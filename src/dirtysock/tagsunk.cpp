#include "common.h"

extern "C" char* strcpy(char* dst, const char* src);

//100%
INCLUDE_ASM("dirtysock/tagsunk", cDirtysock_tag_TagFieldSetUnk);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldSetString(char* buf, int size, const char* key, const char* value);

// PORT: the unit declares value as int (callers pass a string pointer in it).
extern "C" int cDirtysock_tag_TagFieldSetUnk(char* buf, int size, const char* key, int value)
{
    char temp[256];
    int r;
    if (*(const char*)value == '\'') {
        temp[0] = '`';
        strcpy(temp + 1, (const char*)value);
        r = cDirtysock_tag_TagFieldSetString(buf, size, key, temp);
    } else {
        r = cDirtysock_tag_TagFieldSetString(buf, size, key, (const char*)value);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", cDirtysock_tag_TagFieldGetUnk);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);

// PORT: variable-length array (GNU extension in C++).
extern "C" void cDirtysock_tag_TagFieldGetUnk(const char* tag, char* dst, int size, const char* defval)
{
    char buf[size + 1];
    cDirtysock_tag_TagFieldGetString(tag, buf, size + 1, defval);
    if (buf[0] == '`')
        strcpy(dst, buf + 1);
    else
        strcpy(dst, buf);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259390__FPv);
#ifdef SKIP_ASM
void func_00259390(void* self)
{
}
#endif

extern "C" void* func_0041AA88(void*, void*);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259398__FPviT0T0);
#ifdef SKIP_ASM
void* func_00259398(void* self, int a1, void* a2, void* a3)
{
    return func_0041AA88((char*)a2 + 0x1c, (char*)a3 + 0x1c);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002593B8__FPviT0T0);
#ifdef SKIP_ASM
void* func_002593B8(void* self, int a1, void* a2, void* a3)
{
    return func_0041AA88((char*)a2 + 0x8, (char*)a3 + 0x8);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002593D8);
#ifdef SKIP_ASM
extern "C" int func_002593D8(void* self, void* a1, void* a2)
{
    return (((*(int*)((char*)a2 + 4)) >> 0x15) ^ 1) & 1;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002593F0);
#ifdef SKIP_ASM
extern "C" int func_002593F0(void* self, void* a1, int* a, int* b)
{
    return *b - *a;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259400);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);
extern char D_004A2F30[];

extern "C" int func_00259400(void* self, int a1, char* a2, char* a3)
{
    int s2[2];
    int s3[2];
    cDirtysock_tag_TagFieldGetStructure(a2 + 0x28, s2, 8, D_004A2F30);
    cDirtysock_tag_TagFieldGetStructure(a3 + 0x28, s3, 8, D_004A2F30);
    return s3[0] - s2[0];
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259468);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);
extern char D_004A2F30[];

extern "C" int func_00259468(void* self, int a1, char* a2, char* a3)
{
    int s2[2];
    int s3[2];
    cDirtysock_tag_TagFieldGetStructure(a2 + 0x28, s2, 8, D_004A2F30);
    cDirtysock_tag_TagFieldGetStructure(a3 + 0x28, s3, 8, D_004A2F30);
    return s2[0] - s3[0];
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002594D0);
#ifdef SKIP_ASM
struct cBXString2;
cBXString2* cBXString_cBXString(cBXString2* self);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00260F10(void* self);
// The shared empty-string pointer is read as const so one load serves several string inits.
extern void* const D_004A3E90_94D0 __asm__("D_004A3E90");
extern char D_004807D8[];
extern char D_004804A8[];

struct sBXStr_94D0 {
    void* str;
};

struct sListNode_94D0 {
    sListNode_94D0* next;
    sListNode_94D0* prev;
    void* data;
};

struct sList_94D0 {
    int f0;
    sListNode_94D0* head;           // 0x4
    int f8;
    int fC;
    int f10;
    int f14;
};

extern "C" void* func_002594D0(void* self_)
{
    char* self = (char*)self_;
    // An unused 16-byte local is needed to reproduce the 0x40-byte frame.
    int unused[4];
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x4) = 0;
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0xC) = 0;
    *(int*)(self + 0x10) = 0;
    *(int*)(self + 0x14) = 0;
    *(int*)(self + 0x18) = 0;
    *(int*)(self + 0x44) = 0;
    *(void**)(self + 0x48) = D_004A3E90_94D0;
    *(void**)(self + 0x4C) = D_004A3E90_94D0;
    *(int*)(self + 0x54) = 0;
    *(int*)(self + 0x58) = 0;
    *(int*)(self + 0x5C) = 0;
    *(int*)(self + 0x60) = 0;
    *(int*)(self + 0x64) = 0;
    *(int*)(self + 0x6C) = 0;
    sBXStr_94D0* p = (sBXStr_94D0*)(self + 0x70);
    for (int i = 3; i != -1; i--, p++) {
        p->str = D_004A3E90_94D0;
    }
    *(void**)(self + 0x80) = D_004A3E90_94D0;
    *(void**)(self + 0x84) = D_004A3E90_94D0;
    *(void**)(self + 0x88) = D_004A3E90_94D0;
    *(void**)(self + 0x8C) = D_004A3E90_94D0;
    *(void**)(self + 0x90) = D_004A3E90_94D0;
    *(void**)(self + 0x94) = D_004A3E90_94D0;
    *(void**)(self + 0x98) = D_004A3E90_94D0;
    *(void**)(self + 0x9C) = D_004A3E90_94D0;
    cBXString_cBXString2(self + 0xE8, D_004807D8);
    sList_94D0* lst = (sList_94D0*)(self + 0xEC);
    *(sListNode_94D0**)(self + 0xF0) = (sListNode_94D0*)cMemMan_alloc(0xC, D_004804A8, 0x20000000, 0);
    lst->head->next = *(sListNode_94D0**)(self + 0xF0);
    lst->head->prev = *(sListNode_94D0**)(self + 0xF0);
    *(int*)(self + 0xF4) = 0;
    *(int*)(self + 0xF8) = 0;
    *(int*)(self + 0xFC) = 0;
    *(int*)(self + 0x100) = 0;
    cBXString_cBXString((cBXString2*)(self + 0x260));
    cBXString_cBXString((cBXString2*)(self + 0x2B0));
    for (int i = 0x1C; i >= 0; i--)
        ((int*)(self + 0x1EC))[i] = 0;
    func_00260F10(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259628);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void func_001DB718(void* self);
extern "C" void func_0025B800(void* self);
void operator_delete(int*);

static inline void dtorSub_9628(char* sub)
{
    if (sub + 0x14 != 0) {
        char* p = sub + 0x14 + 0x10;
        while (sub + 0x14 != p) {
            p -= 4;
            cBXString__cBXString(p, 0);
        }
    }
    cBXString__cBXString(sub + 0x10, 2);
    cBXString__cBXString(sub + 0xC, 2);
    cBXString__cBXString(sub + 0x8, 2);
    cBXString__cBXString(sub + 0x4, 2);
    cBXString__cBXString(sub, 2);
}

static inline void dtor4_9628(char* p)
{
    cBXString__cBXString(p + 0xC, 2);
    cBXString__cBXString(p + 0x8, 2);
    cBXString__cBXString(p + 0x4, 2);
    cBXString__cBXString(p, 2);
}

static inline void dtorList_9628(char* lst)
{
    func_001DB718(lst);
    operator_delete(*(int**)(lst + 4));
}

extern "C" void func_00259628(void* self_, int flags)
{
    char* self = (char*)self_;
    func_0025B800(self);
    dtorSub_9628(self + 0x2B0);
    dtorSub_9628(self + 0x260);
    dtorList_9628(self + 0xEC);
    cBXString__cBXString(self + 0xE8, 2);
    cBXString__cBXString(self + 0x9C, 2);
    cBXString__cBXString(self + 0x98, 2);
    dtor4_9628(self + 0x88);
    cBXString__cBXString(self + 0x84, 2);
    cBXString__cBXString(self + 0x80, 2);
    if (self + 0x70 != 0) {
        char* p = self + 0x70 + 0x10;
        while (self + 0x70 != p) {
            p -= 4;
            cBXString__cBXString(p, 0);
        }
    }
    cBXString__cBXString(self + 0x4C, 2);
    cBXString__cBXString(self + 0x48, 2);
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

extern "C" void* func_003E8FD0(int);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002598A8__FPv);
#ifdef SKIP_ASM
void* func_002598A8(void* self)
{
    return func_003E8FD0(*(int*)((char*)self + 0x54));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002598C8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern "C" int* func_002591D0();
extern "C" void func_00263BA8(void* p, int arg);

struct sMsgListNodeK2 {
    sMsgListNodeK2* next;
    sMsgListNodeK2* prev;
    void* data;
};

struct sMsgListIterK2 {
    sMsgListNodeK2* node;
    sMsgListIterK2(sMsgListNodeK2* x) : node(x) {}
    sMsgListIterK2(const sMsgListIterK2& x) : node(x.node) {}
};

static inline sMsgListIterK2 sMsgListK2_insert(sMsgListIterK2 pos, void* const& x)
{
    sMsgListNodeK2* tmp = (sMsgListNodeK2*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_002598C8(char* self, int* msg)
{
    if (msg[1] == 0x64697363) {
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0x115;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgListK2_insert(*(sMsgListNodeK2**)(self + 0xF0), mp);
        *(int*)(self + 0x10) = 1;
        if (*func_002591D0() != 0)
            func_00263BA8(func_002591D0(), 2);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002599B0);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];

struct sMsgListNodeK2b {
    sMsgListNodeK2b* next;
    sMsgListNodeK2b* prev;
    void* data;
};

struct sMsgListIterK2b {
    sMsgListNodeK2b* node;
    sMsgListIterK2b(sMsgListNodeK2b* x) : node(x) {}
    sMsgListIterK2b(const sMsgListIterK2b& x) : node(x.node) {}
};

static inline sMsgListIterK2b sMsgListK2b_insert(sMsgListIterK2b pos, void* const& x)
{
    sMsgListNodeK2b* tmp = (sMsgListNodeK2b*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_002599B0(char* self)
{
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = 0xE0;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListK2b_insert(*(sMsgListNodeK2b**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00259A60);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];

struct sMsgListNodeK2c {
    sMsgListNodeK2c* next;
    sMsgListNodeK2c* prev;
    void* data;
};

struct sMsgListIterK2c {
    sMsgListNodeK2c* node;
    sMsgListIterK2c(sMsgListNodeK2c* x) : node(x) {}
    sMsgListIterK2c(const sMsgListIterK2c& x) : node(x.node) {}
};

static inline sMsgListIterK2c sMsgListK2c_insert(sMsgListIterK2c pos, void* const& x)
{
    sMsgListNodeK2c* tmp = (sMsgListNodeK2c*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00259A60(char* self, int unused)
{
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = 0xE1;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListK2c_insert(*(sMsgListNodeK2c**)(self + 0xF0), mp);
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_00259B10);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A1D0);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" unsigned int cDirtysock_tag_TagFieldGetTime(const char* tag, int defval);
extern "C" unsigned int cDirtysock_tag_TagFieldGetAddr(const char* tag, int defval);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" int func_0025A730(void* self, const char* key, int def);
extern "C" int func_004165A8(void*, void*);
extern "C" int* func_002591D0();
extern "C" void func_00263BA8(void* p, int arg);
extern "C" void func_00259098(void* p, int a, int b);
extern "C" unsigned int strlen(const char*);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int cBENewRaceInterface_setGameMode(void* self, int mode);
extern "C" int cBENewRaceInterface_setGameEvent(void* self, int ev);
extern "C" int cBENewRaceInterface_setNumberAI(void* self, int n);
extern char D_004A2F40[];
extern char D_004A2F58[];
extern char D_004A2F60[];
extern char D_004A2F68[];
extern char D_004A2F70[];
extern char D_004A2F78[];
extern char D_004A2F80[];
extern char D_004A2F88[];
extern char D_004A2F90[];
extern char D_004A2F98[];
extern char D_004A2FA0[];
extern char D_004A2FA8[];
extern int D_00535C08[];
extern int D_004A11B8;
extern void* D_004A28A8;
extern int D_00534B34[];
extern char D_005308B8[];
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];

struct sMsgListNodeA1D0 {
    sMsgListNodeA1D0* next;
    sMsgListNodeA1D0* prev;
    void* data;
};

struct sMsgListIterA1D0 {
    sMsgListNodeA1D0* node;
    sMsgListIterA1D0(sMsgListNodeA1D0* x) : node(x) {}
    sMsgListIterA1D0(const sMsgListIterA1D0& x) : node(x.node) {}
};

static inline sMsgListIterA1D0 sMsgListA1D0_insert(sMsgListIterA1D0 pos, void* const& x)
{
    sMsgListNodeA1D0* tmp = (sMsgListNodeA1D0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_A1D0(char* self, void* msg)
{
    void* mp = msg;
    sMsgListA1D0_insert(*(sMsgListNodeA1D0**)(self + 0xF0), mp);
}

struct sAppA1D0 { char pad[0x78]; void* mBE; };

struct sVEntryA1D0 { short delta; short index; int (*fn)(void*); };

extern "C" void func_0025A1D0(char* self, char* msg)
{
    char name[0x100];
    char b1[0x100];
    char b2[0x100];
    char b3[0x100];
    char b4[0x100];
    char b5[0x100];
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F58), name, 0x100, D_004A2F40);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F60), b1, 0x100, D_004A2F40);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F68), b2, 0x100, D_004A2F40);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F70), b3, 0x100, D_004A2F40);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F78), b4, 0x100, D_004A2F40);
    *(int*)(self + 0xA0) = cDirtysock_tag_TagFieldGetTime(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F80), 0);
    int ev = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F88), -1);
    int kind = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F90), -1);
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F88), b5, 0x100, D_004A2F40);
    *(int*)(self + 0xA8) = func_0025A730(self, b2, cDirtysock_tag_TagFieldGetAddr(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F98), 0));
    *(int*)(self + 0xAC) = func_0025A730(self, b3, cDirtysock_tag_TagFieldGetAddr(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2FA0), 0));
    cBXString_cBXString4(self + 0x88, name);
    cBXString_cBXString4(self + 0x90, b2);
    cBXString_cBXString4(self + 0x94, b3);
    cBXString_cBXString4(self + 0x9C, b4);
    int same = func_004165A8(b1, b2) == 0;
    *(int*)(self + 0xB4) = same;
    cBXString_cBXString4(self + 0x98, same ? b3 : b2);
    *(int*)(self + 0xB0) = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2FA8), 0);
    if (*(int*)self != 0x18 && *(int*)self != 0x14)
    {
        *(int*)self = 0x19;
        func_00263BA8(func_002591D0(), 0);
        return;
    }
    *(int*)self = 0x19;
    if (strlen(b5))
    {
        char* ri = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
        int mode = 0;
        switch (kind)
        {
        case 0:
            if (ev >= 14 && ev <= 16)
            {
                mode = 5;
                kind = 4;
            }
            else
                mode = 0;
            break;
        case 1:
            if (ev >= 14 && ev <= 16)
            {
                mode = 6;
                kind = 5;
            }
            else
                mode = 1;
            break;
        case 2:
            mode = 3;
            break;
        case 3:
            mode = 2;
            break;
        }
        cBENewRaceInterface_setGameMode(ri, mode);
        cBENewRaceInterface_setGameEvent(ri, kind);
        D_00535C08[0] = ev;
        D_004A11B8 = 1;
        cBE_getInterface_Fv(((sAppA1D0*)D_004A28A8)->mBE, 7);
        if (D_00534B34[0] != 0)
        {
            char* cfg = D_005308B8;
            *(int*)(cfg + 0x18) |= 0x1C0;
            cBENewRaceInterface_setNumberAI(ri, 0);
            sVEntryA1D0* vt = *(sVEntryA1D0**)(ri + 0xC);
            vt[1].fn(ri + vt[1].delta);
        }
    }
    int type = 0xEF;
    func_00259098(func_002591D0(), *(int*)(self + 0xA4), 0);
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    post_A1D0(self, m);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A650);
#ifdef SKIP_ASM
extern "C" char* func_003E8A70(void* p, int tag);
extern "C" void* func_003E6E08();
extern "C" void func_003E7120(void* h, char* fmt, char* arg);
extern char D_004813A0[];

extern "C" void func_0025A650(char* self)
{
    if (*(int*)(self + 0xC) == 0)
        return;
    if (*(void**)(self + 0xF4) != 0)
        return;
    if (func_003E8A70(*(void**)(self + 0x54), 0x70657273) == 0)
        return;
    if (*func_003E8A70(*(void**)(self + 0x54), 0x70657273) == 0)
        return;
    *(void**)(self + 0xF4) = func_003E6E08();
    if (*(void**)(self + 0xF4) == 0)
        return;
    func_003E7120(*(void**)(self + 0xF4), D_004813A0, func_003E8A70(*(void**)(self + 0x54), 0x70657273));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A6F8);
#ifdef SKIP_ASM
extern "C" void func_003E6E70(void*);

extern "C" void func_0025A6F8(void* self)
{
    void* p = *(void**)((char*)self + 0xF4);
    if (p != 0) {
        func_003E6E70(p);
        *(void**)((char*)self + 0xF4) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A730);
#ifdef SKIP_ASM
extern char D_004813A0[];
extern "C" int func_003E7218(void* tags, const char* key, const char* def);

extern "C" int func_0025A730(void* self, const char* key, int def)
{
    void* tags = *(void**)((char*)self + 0xF4);
    if (tags != 0) {
        int r = func_003E7218(tags, D_004813A0, key);
        if (r != 0) {
            def = r;
        }
    }
    return def;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A778);
#ifdef SKIP_ASM
extern "C" void* func_003E85B0(void* mgr, int idx, void* cb, void* user);
extern "C" void func_003EE5A0(void* h, int a, int b, void* cb);
extern "C" void func_00268A90(void* self, void* a1, int a2);
extern "C" void func_00268AB8(void* self, void* a1, int a2);
extern "C" void func_00268AE0(void* self, void* a1, int a2);

struct sDsSessK2 {
    char pad_0x00[0x54];
    void* mgr;                   // 0x54
    char pad_0x58[4];
    void* chan[3];               // 0x5C
    char pad_0x68[0x104 - 0x68];
    unsigned int slotA[29];      // 0x104
    unsigned int slotB[29];      // 0x178
};

extern "C" void func_0025A778(sDsSessK2* self)
{
    int i;
    self->chan[0] = func_003E85B0(self->mgr, 0, (void*)func_00268A90, self);
    func_003EE5A0(self->chan[0], 0, 0, (void*)func_00259398);
    self->chan[1] = func_003E85B0(self->mgr, 1, (void*)func_00268AB8, self);
    func_003EE5A0(self->chan[1], 0, 0, (void*)func_002593B8);
    self->chan[2] = func_003E85B0(self->mgr, 2, (void*)func_00268AE0, self);
    for (i = 0; i < 29; i++) {
        self->slotA[i] = 0xFFFFFFFF;
        self->slotB[i] = 0xFFFFFFFF;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A850);
#ifdef SKIP_ASM
extern "C" void func_003E8688(void* ctx, int kind, void* p);

extern "C" void func_0025A850(void* self)
{
    int i;
    void** arr = (void**)((char*)self + 0x1EC);
    for (i = 0; i < 29; i++) {
        if (arr[i] != 0) {
            func_003E8688(*(void**)((char*)self + 0x54), 4, arr[i]);
            arr[i] = 0;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025A8B0);
#ifdef SKIP_ASM
struct sTagsUnkCallbackObj {
    char pad[0xC];
    void (*fn)(sTagsUnkCallbackObj* self);
};

extern "C" void func_0025A8B0(void* self)
{
    if (*(void**)((char*)self + 0x5C) != 0) {
        func_003E8688(*(void**)((char*)self + 0x54), 0, *(void**)((char*)self + 0x5C));
        *(void**)((char*)self + 0x5C) = 0;
    }
    if (*(void**)((char*)self + 0x60) != 0) {
        func_003E8688(*(void**)((char*)self + 0x54), 1, *(void**)((char*)self + 0x60));
        *(void**)((char*)self + 0x60) = 0;
    }
    if (*(void**)((char*)self + 0x64) != 0) {
        func_003E8688(*(void**)((char*)self + 0x54), 2, *(void**)((char*)self + 0x64));
        *(void**)((char*)self + 0x64) = 0;
    }
    func_0025A850(self);
    sTagsUnkCallbackObj* obj = *(sTagsUnkCallbackObj**)((char*)self + 0x58);
    if (obj != 0) {
        obj->fn(obj);
        *(void**)((char*)self + 0x58) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025A948);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* func_003E7FF0(const char* tag, int a, void* cb);
extern "C" void func_003E8248(void* mgr, int idx, void* cb, void* user);
extern "C" const char* func_00259198();
extern "C" void func_00268B08(void* self, void* a1, int a2);
extern "C" void func_00268B30(void* self, void* a1, int a2);
extern "C" void func_00268B58(void* self, void* a1, int a2);
extern "C" void func_00268B80(void* self, void* a1, int a2);
extern char D_004A2FC8[];
extern char D_004A2FD0[];
extern char D_004A2FD8[];
extern char D_004A2FE0[];
extern char D_004A2FE8[];
extern char D_004813A0[];
extern char D_004813B0[];
extern char D_00481390[];
extern char D_00480818[];
extern char D_00480828[];

extern "C" void func_0025A948(void* self_)
{
    char* self = (char*)self_;
    char buf[0x40];
    char tag[0x100];
    tag[0] = 0;
    cDirtysock_tag_TagFieldSetString(tag, 0x100, D_004A2FC8, D_004813A0);
    sprintf(buf, D_00480818, D_004A2FD0, D_004813B0, D_00480828);
    cDirtysock_tag_TagFieldSetString(tag, 0x100, D_004A2FD8, buf);
    const char* key = D_004A2FE0;
    cDirtysock_tag_TagFieldSetString(tag, 0x100, key, func_00259198());
    cDirtysock_tag_TagFieldSetString(tag, 0x100, D_004A2FE8, D_00481390);
    void* mgr = func_003E7FF0(tag, 0, (void*)func_00259390);
    *(void**)(self + 0x54) = mgr;
    func_003E8248(mgr, 0, (void*)func_00268B08, self);
    func_003E8248(*(void**)(self + 0x54), 1, (void*)func_00268B30, self);
    func_003E8248(*(void**)(self + 0x54), 3, (void*)func_00268B58, self);
    func_003E8248(*(void**)(self + 0x54), 4, (void*)func_00268B80, self);
    func_0025A778((sDsSessK2*)self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025AA98);
#ifdef SKIP_ASM
extern "C" void func_0025A8B0(void* self);
extern "C" void func_003E80C0(void* p);
extern "C" void func_003E81C8(void* p);

extern "C" void func_0025AA98(void* self)
{
    func_0025A8B0(self);
    if (*(void**)((char*)self + 0x54) != 0) {
        func_003E80C0(*(void**)((char*)self + 0x54));
        func_003E81C8(*(void**)((char*)self + 0x54));
        *(void**)((char*)self + 0x54) = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025AAE0);
#ifdef SKIP_ASM
extern char D_004A3010[];
extern "C" int cDirtysock_tag_TagFieldSetUnk(char* buf, int size, const char* key, int value);
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);

extern "C" void func_0025AAE0(void* self, int value)
{
    char buf[0x200];
    if (*(int*)self != 0) {
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetUnk(buf, 0x200, D_004A3010, value);
        func_003E8B10(*(void**)((char*)self + 0x54), 0x6D657367, buf, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025AB40);
#ifdef SKIP_ASM
extern char D_00480498[];
extern char D_004804A8[];
extern void* D_00481230[];
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void* cBXString_cBXString2(void* self, const char* s);

struct sMsgListNodeAB40 {
    sMsgListNodeAB40* next;
    sMsgListNodeAB40* prev;
    void* data;
};

struct sMsgListIterAB40 {
    sMsgListNodeAB40* node;
    sMsgListIterAB40(sMsgListNodeAB40* x) : node(x) {}
    sMsgListIterAB40(const sMsgListIterAB40& x) : node(x.node) {}
};

static inline sMsgListIterAB40 sMsgListAB40_insert(sMsgListIterAB40 pos, void* const& x)
{
    sMsgListNodeAB40* tmp = (sMsgListNodeAB40*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

// cBXString temporary (one pointer; non-POD, so it gets its own 16-byte stack slot).
struct cBXStrAB40 {
    char* str;
    cBXStrAB40() {}
    cBXStrAB40(const cBXStrAB40& o) : str(o.str) {}
};

extern "C" void func_0025AB40(char* self, const char* a, const char* b)
{
    int* m = (int*)operator new(0x10, D_00480498, 0x20000000, 0);
    cBXStrAB40 sa;
    cBXString_cBXString2(&sa, a);
    cBXStrAB40 sb;
    cBXString_cBXString2(&sb, b);
    m[0] = 0xDE;
    *(void***)((char*)m + 0x4) = D_00481230;
    cBXString_cBXString1((char*)m + 0x8, &sa);
    cBXString_cBXString1((char*)m + 0xC, &sb);
    cBXString__cBXString(&sa, 2);
    cBXString__cBXString(&sb, 2);
    void* mp = m;
    sMsgListAB40_insert(*(sMsgListNodeAB40**)(self + 0xF0), mp);
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_0025AC50);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025B608);
#ifdef SKIP_ASM
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);

extern "C" void func_0025B608(void* self, int a1, int tag, void* cb, int a4, float f)
{
    *(int*)self = a1;
    *(float*)((char*)self + 0xE0) = f;
    *(int*)((char*)self + 0x40) = func_003E8B10(*(void**)((char*)self + 0x54), tag, cb, a4, self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025B650);
#ifdef SKIP_ASM
extern char D_00480838[];
extern void* D_004A3028;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002594D0(void* self);

extern "C" void func_0025B650(void)
{
    D_004A3028 = func_002594D0(cMemMan_alloc(0x300, D_00480838, 0x20000000, 0));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025B688);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern void* D_004A2EEC;
extern "C" void func_0025B800(void* self);
extern "C" void func_00259628(void* self, int flags);
extern "C" void func_00256C50(void);

extern "C" void func_0025B688(void)
{
    if (D_004A3028 != 0) {
        func_0025B800(D_004A3028);
        if (D_004A3028 != 0) {
            func_00259628(D_004A3028, 3);
        }
        D_004A3028 = 0;
    }
    if (D_004A2EEC != 0) {
        func_00256C50();
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025B6D8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern int D_004A3018;
extern "C" void func_0025A948(void* self);
extern "C" int func_003E8260(void* p, int a, int timeout, void* cb, void* user);
extern "C" int func_003F3A98(void* p, int a);
extern "C" void func_00268BA8(void* self, void* a1, int a2);

struct sMsgListNodeB6D8 {
    sMsgListNodeB6D8* next;
    sMsgListNodeB6D8* prev;
    void* data;
};

struct sMsgListIterB6D8 {
    sMsgListNodeB6D8* node;
    sMsgListIterB6D8(sMsgListNodeB6D8* x) : node(x) {}
    sMsgListIterB6D8(const sMsgListIterB6D8& x) : node(x.node) {}
};

static inline sMsgListIterB6D8 sMsgListB6D8_insert(sMsgListIterB6D8 pos, void* const& x)
{
    sMsgListNodeB6D8* tmp = (sMsgListNodeB6D8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025B6D8(char* self, int conn)
{
    if (*(void**)(self + 0x54) == 0)
        func_0025A948(self);
    *(int*)(self + 0x14) = conn;
    if (conn != 0) {
        int g = D_004A3018;
        *(int*)self = 3;
        *(float*)(self + 0xE0) = 30.0f;
        *(int*)(self + 0x4) = g;
        // PORT: function pointer passed as a callback argument.
        func_003E8260(*(void**)(self + 0x54), g, 0x2AF8, (void*)func_00268BA8, self);
    } else {
        *(int*)self = 2;
        *(int*)(self + 0x58) = func_003F3A98(*(void**)(self + 0xE8), 0);
    }
    int type = 0xC8;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListB6D8_insert(*(sMsgListNodeB6D8**)(self + 0xF0), mp);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025B800);
#ifdef SKIP_ASM
extern "C" void func_0025A6F8(void* self);
extern "C" void func_0025AA98(void* self);

extern "C" void func_0025B800(void* self)
{
    func_0025A6F8(self);
    if (*(void**)((char*)self + 0x54) != 0) {
        func_0025AA98(self);
    }
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025B848);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_00480848[];
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeB848 {
    sMsgListNodeB848* next;
    sMsgListNodeB848* prev;
    void* data;
};

struct sMsgListIterB848 {
    sMsgListNodeB848* node;
    sMsgListIterB848(sMsgListNodeB848* x) : node(x) {}
    sMsgListIterB848(const sMsgListIterB848& x) : node(x.node) {}
};

static inline sMsgListIterB848 sMsgListB848_insert(sMsgListIterB848 pos, void* const& x)
{
    sMsgListNodeB848* tmp = (sMsgListNodeB848*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_B848(char* self, void* msg)
{
    void* mp = msg;
    sMsgListB848_insert(*(sMsgListNodeB848**)(self + 0xF0), mp);
}

extern "C" void func_0025B848(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        func_003E8B10(*(void**)(self + 0x54), 0x73656C65, D_00480848, 0, 0);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xC9;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_B848(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_B848(self, m);
        *(int*)(self + 0x10) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025B9C8);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_00480870[];
extern char D_004A2F58[];
extern char D_004A2FE0[];
extern char D_004A3030[];
extern char D_004A3038[];
extern char D_004A3040[];
extern char D_004A3048[];
extern char D_004A3050[];
extern char D_004A3058[];
extern char D_004A3060[];
extern char D_004A3068[];
extern char D_004A3070[];
extern char D_004A3078[];
extern char D_004A3080[];
extern "C" void func_00268BD0(void* self, void* a1, int a2);
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* buf, int size, const char* key, int value);
extern "C" const char* func_00259198();

struct sMsgListNodeB9C8 {
    sMsgListNodeB9C8* next;
    sMsgListNodeB9C8* prev;
    void* data;
};

struct sMsgListIterB9C8 {
    sMsgListNodeB9C8* node;
    sMsgListIterB9C8(sMsgListNodeB9C8* x) : node(x) {}
    sMsgListIterB9C8(const sMsgListIterB9C8& x) : node(x.node) {}
};

static inline sMsgListIterB9C8 sMsgListB9C8_insert(sMsgListIterB9C8 pos, void* const& x)
{
    sMsgListNodeB9C8* tmp = (sMsgListNodeB9C8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025B9C8(char* self, char* msg)
{
    char buf[0x200];
    char yn[16];
    char mf[16];
    char ver[16];
    sprintf(yn, D_004A3030, *(int*)(msg + 0x38) ? 'Y' : 'N', *(int*)(msg + 0x3C) ? 'Y' : 'N');
    sprintf(mf, D_004A3038, *(int*)(msg + 0x34) ? 'F' : 'M');
    sprintf(ver, D_00480870, *(int*)(msg + 0x30), *(int*)(msg + 0x28), *(int*)(msg + 0x2C));
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A2F58, *(const char**)(msg + 0x0));
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3040, *(const char**)(msg + 0x4));
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3048, yn);
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3050, *(const char**)(msg + 0xC));
    const char* email = *(const char**)(msg + 0x10);
    // PORT: string length read from the header before the characters.
    if (*(int*)((int)email - 8) != 0)
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3058, email);
    int type = 0xCA;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3060, mf);
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3068, ver);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A3070, 0);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A3078, 4);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A3080, 0xD);
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A2FE0, func_00259198());
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 4, 0x61636374, buf, (int)func_00268BD0, 20.0f);
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListB9C8_insert(*(sMsgListNodeB9C8**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025BC48);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern char D_004A3090[];
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" void* cBXString_cBXString4(void* self, const char* str);

struct sDsNameListK2 {
    char pad_0x00[0x274];
    char* names[4];   // 0x274 (cBXString)
    int count;        // 0x284
};

// Splits a comma-separated tag field into up to 4 strings.
extern "C" void func_0025BC48(sDsNameListK2* self, char* msg)
{
    char buf[256];
    char* p;
    char* start;
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3090), buf, 256, D_004A2F40);
    self->count = 0;
    p = buf;
    while ((*p != 0) && (self->count < 4)) {
        start = p;
        while ((*p != 0) && (*p != ','))
            p++;
        if (*p != 0)
            *p++ = 0;
        cBXString_cBXString4(&self->names[self->count++], start);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025BD30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004811F0[];
extern void* D_004812B0[];
extern void* D_00481290[];
extern char D_004A3098[];
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
struct sDsNameListK2;
extern "C" void func_0025BC48(sDsNameListK2* self, char* msg);

struct sMsgListNodeBD30 {
    sMsgListNodeBD30* next;
    sMsgListNodeBD30* prev;
    void* data;
};

struct sMsgListIterBD30 {
    sMsgListNodeBD30* node;
    sMsgListIterBD30(sMsgListNodeBD30* x) : node(x) {}
    sMsgListIterBD30(const sMsgListIterBD30& x) : node(x.node) {}
};

static inline sMsgListIterBD30 sMsgListBD30_insert(sMsgListIterBD30 pos, void* const& x)
{
    sMsgListNodeBD30* tmp = (sMsgListNodeBD30*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_BD30(char* self, void* msg)
{
    void* mp = msg;
    sMsgListBD30_insert(*(sMsgListNodeBD30**)(self + 0xF0), mp);
}

extern "C" void func_0025BD30(char* self, char* msg)
{
    *(int*)self = 1;
    int err = *(int*)(msg + 0x8);
    if (err == 0) {
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xCB;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_BD30(self, m);
    } else if (err == 0x746F6F79) {
        int n = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3098), 0);
        int* m = (int*)operator new(0x10, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        m[2] = err;
        *(void***)((char*)m + 0x4) = D_004811F0;
        m[3] = n;
        post_BD30(self, m);
    } else {
        if (err == 0x6475706C)
            func_0025BC48((sDsNameListK2*)self, msg);
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_BD30(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025BF18);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A2F58[];
extern char D_004A3030[];
extern char D_004A3040[];
extern char D_004A3048[];
extern char D_004A3050[];
extern char D_004A30A0[];
extern "C" void func_00268BF8(void* self, void* a1, int a2);

struct sMsgListNodeBF18 {
    sMsgListNodeBF18* next;
    sMsgListNodeBF18* prev;
    void* data;
};

struct sMsgListIterBF18 {
    sMsgListNodeBF18* node;
    sMsgListIterBF18(sMsgListNodeBF18* x) : node(x) {}
    sMsgListIterBF18(const sMsgListIterBF18& x) : node(x.node) {}
};

static inline sMsgListIterBF18 sMsgListBF18_insert(sMsgListIterBF18 pos, void* const& x)
{
    sMsgListNodeBF18* tmp = (sMsgListNodeBF18*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025BF18(char* self, char* msg)
{
    char buf[0x200];
    char tmp[16];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A2F58, *(const char**)(self + 0x48));
    if (*(int*)(msg + 0x44) != 0) {
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3040, *(const char**)(self + 0x4C));
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A30A0, *(const char**)(msg + 0x4));
    }
    if (*(int*)(msg + 0x48) != 0) {
        sprintf(tmp, D_004A3030, *(int*)(msg + 0x38) ? 'Y' : 'N', *(int*)(msg + 0x3C) ? 'Y' : 'N');
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3048, tmp);
    }
    if (*(int*)(msg + 0x4C) != 0) {
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3050, *(const char**)(msg + 0xC));
    }
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 5, 0x65646974, buf, (int)func_00268BF8, 20.0f);
    int type = 0xCD;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListBF18_insert(*(sMsgListNodeBF18**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C0C0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeC0C0 {
    sMsgListNodeC0C0* next;
    sMsgListNodeC0C0* prev;
    void* data;
};

struct sMsgListIterC0C0 {
    sMsgListNodeC0C0* node;
    sMsgListIterC0C0(sMsgListNodeC0C0* x) : node(x) {}
    sMsgListIterC0C0(const sMsgListIterC0C0& x) : node(x.node) {}
};

static inline sMsgListIterC0C0 sMsgListC0C0_insert(sMsgListIterC0C0 pos, void* const& x)
{
    sMsgListNodeC0C0* tmp = (sMsgListNodeC0C0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_C0C0(char* self, void* msg)
{
    void* mp = msg;
    sMsgListC0C0_insert(*(sMsgListNodeC0C0**)(self + 0xF0), mp);
}

extern "C" void func_0025C0C0(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xCE;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_C0C0(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_C0C0(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C1E0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A3050[];
extern "C" void func_00268C20(void* self, void* a1, int a2);

struct sMsgListNodeC1E0 {
    sMsgListNodeC1E0* next;
    sMsgListNodeC1E0* prev;
    void* data;
};

struct sMsgListIterC1E0 {
    sMsgListNodeC1E0* node;
    sMsgListIterC1E0(sMsgListNodeC1E0* x) : node(x) {}
    sMsgListIterC1E0(const sMsgListIterC1E0& x) : node(x.node) {}
};

static inline sMsgListIterC1E0 sMsgListC1E0_insert(sMsgListIterC1E0 pos, void* const& x)
{
    sMsgListNodeC1E0* tmp = (sMsgListNodeC1E0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025C1E0(char* self, const char* value)
{
    char buf[0x200];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3050, value);
    int type = 0xD1;
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 6, 0x6C6F7374, buf, (int)func_00268C20, 20.0f);
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListC1E0_insert(*(sMsgListNodeC1E0**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C2D8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeC2D8 {
    sMsgListNodeC2D8* next;
    sMsgListNodeC2D8* prev;
    void* data;
};

struct sMsgListIterC2D8 {
    sMsgListNodeC2D8* node;
    sMsgListIterC2D8(sMsgListNodeC2D8* x) : node(x) {}
    sMsgListIterC2D8(const sMsgListIterC2D8& x) : node(x.node) {}
};

static inline sMsgListIterC2D8 sMsgListC2D8_insert(sMsgListIterC2D8 pos, void* const& x)
{
    sMsgListNodeC2D8* tmp = (sMsgListNodeC2D8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_C2D8(char* self, void* msg)
{
    void* mp = msg;
    sMsgListC2D8_insert(*(sMsgListNodeC2D8**)(self + 0xF0), mp);
}

extern "C" void func_0025C2D8(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xCF;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_C2D8(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_C2D8(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C3F8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A2F58[];
extern "C" void func_00268C48(void* self, void* a1, int a2);

struct sMsgListNodeC3F8 {
    sMsgListNodeC3F8* next;
    sMsgListNodeC3F8* prev;
    void* data;
};

struct sMsgListIterC3F8 {
    sMsgListNodeC3F8* node;
    sMsgListIterC3F8(sMsgListNodeC3F8* x) : node(x) {}
    sMsgListIterC3F8(const sMsgListIterC3F8& x) : node(x.node) {}
};

static inline sMsgListIterC3F8 sMsgListC3F8_insert(sMsgListIterC3F8 pos, void* const& x)
{
    sMsgListNodeC3F8* tmp = (sMsgListNodeC3F8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025C3F8(char* self, const char* value)
{
    char buf[0x200];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A2F58, value);
    int type = 0xD0;
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 7, 0x6C6F7374, buf, (int)func_00268C48, 20.0f);
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListC3F8_insert(*(sMsgListNodeC3F8**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C4F0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeC4F0 {
    sMsgListNodeC4F0* next;
    sMsgListNodeC4F0* prev;
    void* data;
};

struct sMsgListIterC4F0 {
    sMsgListNodeC4F0* node;
    sMsgListIterC4F0(sMsgListNodeC4F0* x) : node(x) {}
    sMsgListIterC4F0(const sMsgListIterC4F0& x) : node(x.node) {}
};

static inline sMsgListIterC4F0 sMsgListC4F0_insert(sMsgListIterC4F0 pos, void* const& x)
{
    sMsgListNodeC4F0* tmp = (sMsgListNodeC4F0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_C4F0(char* self, void* msg)
{
    void* mp = msg;
    sMsgListC4F0_insert(*(sMsgListNodeC4F0**)(self + 0xF0), mp);
}

extern "C" void func_0025C4F0(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xD2;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_C4F0(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_C4F0(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C610);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004813A0[];
extern char D_004A2F58[];
extern char D_004A3040[];
extern char D_004A30C0[];
extern char D_004A30C8[];
extern char D_004A30D0[];
extern char D_004A30D8[];
extern char D_004A30E0[];
extern void* D_004A2EB8;
extern void* D_004A33F0;
extern void* D_004A33F4;
extern "C" void func_00268C70(void* self, void* a1, int a2);
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* buf, int size, const char* key, int value);
extern "C" const char* func_003F3F78();
void* func_00266F38(void* self);

struct sMsgListNodeC610 {
    sMsgListNodeC610* next;
    sMsgListNodeC610* prev;
    void* data;
};

struct sMsgListIterC610 {
    sMsgListNodeC610* node;
    sMsgListIterC610(sMsgListNodeC610* x) : node(x) {}
    sMsgListIterC610(const sMsgListIterC610& x) : node(x.node) {}
};

static inline sMsgListIterC610 sMsgListC610_insert(sMsgListIterC610 pos, void* const& x)
{
    sMsgListNodeC610* tmp = (sMsgListNodeC610*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_C610(char* lst, void* msg)
{
    void* mp = msg;
    sMsgListC610_insert(*(sMsgListNodeC610**)(lst + 4), mp);
}

struct sDsSlotC610 {
    char pad[0x88];
    int flags;
};

extern "C" void func_0025C610(char* self)
{
    char buf[0x200];
    int flags = 0;
    int caps = 0;
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A2F58, *(const char**)(self + 0x48));
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3040, *(const char**)(self + 0x4C));
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A30C0, 1);
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A30C8, func_003F3F78());
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A30D0, D_004813A0);
    int v = *(int*)((char*)D_004A2EB8 + 0x30);
    if (v != 1) {
        flags = v & 4;
        caps = 0x10024;
        if (v & 0x10)
            flags |= 0x10000;
        if (v & 8)
            flags |= 0x20;
    }
    caps |= 0x800;
    int i = 0;
    void* conn = D_004A33F4;

    for (; i < 8; i++) {
        if (((sDsSlotC610*)D_004A33F0)[i].flags & 1) {
            flags |= 0x800;
            break;
        }
    }
    caps |= 0x100;
    if ((int)func_00266F38(conn) & 0x10)
        flags |= 0x100;
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A30D8, flags);
    int type = 0xD3;
    cDirtysock_tag_TagFieldSetNumber(buf, 0x200, D_004A30E0, caps);
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 8, 0x61757468, buf, (int)func_00268C70, 20.0f);
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    post_C610(self + 0xEC, m);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025C878);
#ifdef SKIP_ASM
extern "C" int func_003E8D70(void* p, int a);

extern "C" void func_0025C878(void* self)
{
    if (*(int*)((char*)self + 0) == 8) {
        func_003E8D70(*(void**)((char*)self + 0x54), *(int*)((char*)self + 0x40));
    }
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_0025C8A8);

extern "C" void* func_0025CD50(void*, int);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025CD28__FPvi);
#ifdef SKIP_ASM
void func_0025CD28(void* self, int a1)
{
    func_0025CD50(self, *(int*)((char*)((char*)self + a1 * 4) + 0x70));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025CD50);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A3108[];
extern char D_004A30C8[];
extern char D_004A30D0[];
extern char D_004A3110[];
extern char D_004813A0[];
extern "C" const char* func_003F3F78();
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_0025B608(void* self, int a1, int tag, void* cb, int a4, float f);
extern "C" void func_00268C98(void* self, void* a1, int a2);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeCD50 {
    sMsgListNodeCD50* next;
    sMsgListNodeCD50* prev;
    void* data;
};

struct sMsgListIterCD50 {
    sMsgListNodeCD50* node;
    sMsgListIterCD50(sMsgListNodeCD50* x) : node(x) {}
    sMsgListIterCD50(const sMsgListIterCD50& x) : node(x.node) {}
};

static inline sMsgListIterCD50 sMsgListCD50_insert(sMsgListIterCD50 pos, void* const& x)
{
    sMsgListNodeCD50* tmp = (sMsgListNodeCD50*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

// PORT: the unit declares func_0025CD50 as void* (void*, int) (a caller tail-calls it); the body takes (self, name).
extern "C" void func_0025CD50_impl(char* self, const char* name) __asm__("func_0025CD50");

extern "C" void func_0025CD50_impl(char* self, const char* name)
{
    cBXString_cBXString4(self + 0x80, name);
    char buf[0x200];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3108, name);
    const char* key = D_004A30C8;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, key, func_003F3F78());
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A30D0, D_004813A0);
    if (*(int*)(self + 0x18) != 0)
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3110, self + 0x1C);
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 9, 0x70657273, buf, (int)func_00268C98, 20.0f);
    int type = 0xD9;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListCD50_insert(*(sMsgListNodeCD50**)(self + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025CEB0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];
extern "C" void func_0025CFE0(void* self);

struct sMsgListNodeCEB0 {
    sMsgListNodeCEB0* next;
    sMsgListNodeCEB0* prev;
    void* data;
};

struct sMsgListIterCEB0 {
    sMsgListNodeCEB0* node;
    sMsgListIterCEB0(sMsgListNodeCEB0* x) : node(x) {}
    sMsgListIterCEB0(const sMsgListIterCEB0& x) : node(x.node) {}
};

static inline sMsgListIterCEB0 sMsgListCEB0_insert(sMsgListIterCEB0 pos, void* const& x)
{
    sMsgListNodeCEB0* tmp = (sMsgListNodeCEB0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_CEB0(char* self, void* msg)
{
    void* mp = msg;
    sMsgListCEB0_insert(*(sMsgListNodeCEB0**)(self + 0xF0), mp);
}

extern "C" void func_0025CEB0(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        func_0025CFE0(self);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xDA;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_CEB0(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_CEB0(self, m);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025CFE0);
#ifdef SKIP_ASM
extern char D_004A3108[];
extern "C" int cDirtysock_tag_TagFieldSetString(char* buf, int size, const char* key, const char* value);
extern "C" void func_0025B608(void* self, int a1, int tag, void* cb, int a4, float f);
extern "C" void func_00268CC0(void* self, void* a1, int a2);

extern "C" void func_0025CFE0(void* self)
{
    char buf[0x200];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3108, *(const char**)((char*)self + 0x80));
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 0x1B, 0x6F6E6C6E, buf, (int)func_00268CC0, 20.0f);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D048);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A3128[];
extern char D_004A3130[];
extern char D_004A2F40[];
extern char D_004A2F30[];
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" void func_0025E0C8(void* self, int value);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeD048 {
    sMsgListNodeD048* next;
    sMsgListNodeD048* prev;
    void* data;
};

struct sMsgListIterD048 {
    sMsgListNodeD048* node;
    sMsgListIterD048(sMsgListNodeD048* x) : node(x) {}
    sMsgListIterD048(const sMsgListIterD048& x) : node(x.node) {}
};

static inline sMsgListIterD048 sMsgListD048_insert(sMsgListIterD048 pos, void* const& x)
{
    sMsgListNodeD048* tmp = (sMsgListNodeD048*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_D048(char* self, void* msg)
{
    void* mp = msg;
    sMsgListD048_insert(*(sMsgListNodeD048**)(self + 0xF0), mp);
}

extern "C" void func_0025D048(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        char buf[0x100];
        int st[16];
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3128), buf, 0x100, D_004A2F40);
        cDirtysock_tag_TagFieldGetStructure(buf, st, 0x40, D_004A2F30);
        *(int*)(self + 0xBC) = st[2];
        *(int*)(self + 0xC0) = st[2] + st[3] + st[4];
        *(int*)(self + 0xC4) = st[6];
        *(int*)(self + 0xB8) = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3130), 0);
        *(int*)(self + 0xC8) = -1;
        func_0025E0C8(self, 0);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_D048(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D1B8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A3108[];
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_00268CE8(void* self, void* a1, int a2);

struct sMsgListNodeD1B8 {
    sMsgListNodeD1B8* next;
    sMsgListNodeD1B8* prev;
    void* data;
};

struct sMsgListIterD1B8 {
    sMsgListNodeD1B8* node;
    sMsgListIterD1B8(sMsgListNodeD1B8* x) : node(x) {}
    sMsgListIterD1B8(const sMsgListIterD1B8& x) : node(x.node) {}
};

static inline sMsgListIterD1B8 sMsgListD1B8_insert(sMsgListIterD1B8 pos, void* const& x)
{
    sMsgListNodeD1B8* tmp = (sMsgListNodeD1B8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sDsNamesD1B8 {
    char pad_0x00[0x6C];
    int count;          // 0x6C
    char* names[8];     // 0x70 (cBXString)
};

extern "C" void func_0025D1B8(char* self, const char* name)
{
    if (*(int*)self != 0) {
        char buf[0x200];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3108, name);
        int type = 0xD5;
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0xA, 0x63706572, buf, (int)func_00268CE8, 20.0f);
        sDsNamesD1B8* s = (sDsNamesD1B8*)self;
        cBXString_cBXString4(&s->names[s->count], name);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgListD1B8_insert(*(sMsgListNodeD1B8**)(self + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D2D8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];

extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeD2D8 {
    sMsgListNodeD2D8* next;
    sMsgListNodeD2D8* prev;
    void* data;
};

struct sMsgListIterD2D8 {
    sMsgListNodeD2D8* node;
    sMsgListIterD2D8(sMsgListNodeD2D8* x) : node(x) {}
    sMsgListIterD2D8(const sMsgListIterD2D8& x) : node(x.node) {}
};

static inline sMsgListIterD2D8 sMsgListD2D8_insert(sMsgListIterD2D8 pos, void* const& x)
{
    sMsgListNodeD2D8* tmp = (sMsgListNodeD2D8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_D2D8(char* self, void* msg)
{
    void* mp = msg;
    sMsgListD2D8_insert(*(sMsgListNodeD2D8**)(self + 0xF0), mp);
}

extern "C" void func_0025D2D8(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        (*(int*)(self + 0x6C))++;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xD6;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_D2D8(self, m);
    } else {
        if (*(int*)(msg + 0x8) == 0x6475706C)
            func_0025BC48((sDsNameListK2*)self, msg);
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_D2D8(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D428);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A3108[];
extern "C" void func_00268D10(void* self, void* a1, int a2);

struct sMsgListNodeD428 {
    sMsgListNodeD428* next;
    sMsgListNodeD428* prev;
    void* data;
};

struct sMsgListIterD428 {
    sMsgListNodeD428* node;
    sMsgListIterD428(sMsgListNodeD428* x) : node(x) {}
    sMsgListIterD428(const sMsgListIterD428& x) : node(x.node) {}
};

static inline sMsgListIterD428 sMsgListD428_insert(sMsgListIterD428 pos, void* const& x)
{
    sMsgListNodeD428* tmp = (sMsgListNodeD428*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025D428(char* self, int idx)
{
    if (*(int*)self != 0) {
        char buf[0x200];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x200, D_004A3108, *(const char**)(self + 0x70 + (idx << 2)));
        int type = 0xD7;
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0xB, 0x64706572, buf, (int)func_00268D10, 20.0f);
        *(int*)(self + 0x50) = idx;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgListD428_insert(*(sMsgListNodeD428**)(self + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D538);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern "C" void* cBXString_operatorE(void* self, void* other);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeD538 {
    sMsgListNodeD538* next;
    sMsgListNodeD538* prev;
    void* data;
};

struct sMsgListIterD538 {
    sMsgListNodeD538* node;
    sMsgListIterD538(sMsgListNodeD538* x) : node(x) {}
    sMsgListIterD538(const sMsgListIterD538& x) : node(x.node) {}
};

static inline sMsgListIterD538 sMsgListD538_insert(sMsgListIterD538 pos, void* const& x)
{
    sMsgListNodeD538* tmp = (sMsgListNodeD538*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_D538(char* lst, void* msg)
{
    void* mp = msg;
    sMsgListD538_insert(*(sMsgListNodeD538**)(lst + 4), mp);
}

struct sDsNamesD538 {
    char pad_0x00[0x50];
    int index;          // 0x50
    char pad_0x54[0x6C - 0x54];
    int count;          // 0x6C
    char* names[8];     // 0x70 (cBXString)
};

extern "C" void func_0025D538(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        sDsNamesD538* s = (sDsNamesD538*)self;
        char* lst = self + 0xEC;
        s->count--;
        for (int i = s->index; i < s->count; i++)
            cBXString_operatorE(&s->names[i], &s->names[i + 1]);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        *(void***)((char*)m + 0x4) = D_004812B0;
        m[0] = 0xD8;
        post_D538(lst, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_D538(self + 0xEC, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D6C0);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];

struct sMsgListNodeK6c0 {
    sMsgListNodeK6c0* next;
    sMsgListNodeK6c0* prev;
    void* data;
};

struct sMsgListIterK6c0 {
    sMsgListNodeK6c0* node;
    sMsgListIterK6c0(sMsgListNodeK6c0* x) : node(x) {}
    sMsgListIterK6c0(const sMsgListIterK6c0& x) : node(x.node) {}
};

static inline sMsgListIterK6c0 sMsgListK6c0_insert(sMsgListIterK6c0 pos, void* const& x)
{
    sMsgListNodeK6c0* tmp = (sMsgListNodeK6c0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025D6C0(char* self)
{
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    sMsgListNodeK6c0* list = *(sMsgListNodeK6c0**)(self + 0xF0);
    m[0] = 0xDF;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgListK6c0_insert(list, mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D770);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern char D_004A2F58[];
extern "C" void* func_0025F150(void* self, int i);

extern "C" void func_0025D770(void* self, int idx)
{
    char buf[256];
    if (*(int*)self != 0) {
        const char* key = D_004A2F58;
        const char* name;
        buf[0] = 0;
        if (idx != -1) {
            name = (const char*)func_0025F150(self, idx);
        } else {
            name = D_004A2F40;
        }
        cDirtysock_tag_TagFieldSetString(buf, 0x100, key, name);
        func_003E8B10(*(void**)((char*)self + 0x54), 0x7065656B, buf, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D800);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern "C" void* func_0025F150(void* self, int i);
extern "C" void func_0025D860(void* self, void* name, int a2);

extern "C" void func_0025D800(void* self, int idx, int a2)
{
    void* name;
    if (idx != -1) {
        name = func_0025F150(self, idx);
    } else {
        name = D_004A2F40;
    }
    func_0025D860(self, name, a2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025D860);
#ifdef SKIP_ASM
extern char D_004A2F58[];
extern char D_004A3040[];
extern "C" void func_00268D38(void* self, void* a1, int a2);

// PORT: the unit declares a2 as int; it carries an optional string pointer.
extern "C" void func_0025D860(void* self, void* name, int a2)
{
    if (*(int*)self != 0) {
        char buf[0x100];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A2F58, (const char*)name);
        if (a2 != 0) {
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3040, (const char*)a2);
        }
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0xC, 0x6D6F7665, buf, (int)func_00268D38, 20.0f);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025D8F8);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];
extern char D_004A2F40[];
extern char D_004A2F58[];
extern "C" void cBXString_Reset(void* self);
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);

struct sMsgListNodeD8F8 {
    sMsgListNodeD8F8* next;
    sMsgListNodeD8F8* prev;
    void* data;
};

struct sMsgListIterD8F8 {
    sMsgListNodeD8F8* node;
    sMsgListIterD8F8(sMsgListNodeD8F8* x) : node(x) {}
    sMsgListIterD8F8(const sMsgListIterD8F8& x) : node(x.node) {}
};

static inline sMsgListIterD8F8 sMsgListD8F8_insert(sMsgListIterD8F8 pos, void* const& x)
{
    sMsgListNodeD8F8* tmp = (sMsgListNodeD8F8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_D8F8(char* self, void* msg)
{
    void* mp = msg;
    sMsgListD8F8_insert(*(sMsgListNodeD8F8**)(self + 0xF0), mp);
}

extern "C" void func_0025D8F8(char* self, char* msg)
{
    *(int*)self = 1;
    if (*(int*)(msg + 0x8) == 0) {
        char buf[0x100];
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F58), buf, 0x100, D_004A2F40);
        cBXString_cBXString4(self + 0x84, buf);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0xDC;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_D8F8(self, m);
    } else {
        cBXString_Reset(self + 0x84);
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = *(int*)(msg + 0x8);
        post_D8F8(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DA90);
#ifdef SKIP_ASM
extern "C" char* func_0025DA90(void* self)
{
    char* s;
    if (*(int*)((char*)self + 0x54) == 0) {
        return 0;
    }
    s = *(char**)((char*)self + 0x84);
    if (s != 0) {
        if (*s != 0) {
            return s;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025DAC0);
#ifdef SKIP_ASM
extern char D_004A2F58[];
extern char D_004A3040[];
extern char D_004A3150[];
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00268D60(void* self, void* a1, int a2);

extern "C" void func_0025DAC0(void* self, int a1, int a2, const char* a3)
{
    if (*(int*)self != 0) {
        char buf[0x100];
        char name[0x100];
        sprintf(name, D_004A3150, a1, a2);
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A2F58, name);
        if (a3 != 0) {
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3040, a3);
        }
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0x11, 0x726F6F6D, buf, (int)func_00268D60, 20.0f);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DB80);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A2F58[];
extern char D_004A2F40[];
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeDB80 {
    sMsgListNodeDB80* next;
    sMsgListNodeDB80* prev;
    void* data;
};

struct sMsgListIterDB80 {
    sMsgListNodeDB80* node;
    sMsgListIterDB80(sMsgListNodeDB80* x) : node(x) {}
    sMsgListIterDB80(const sMsgListIterDB80& x) : node(x.node) {}
};

static inline sMsgListIterDB80 sMsgListDB80_insert(sMsgListIterDB80 pos, void* const& x)
{
    sMsgListNodeDB80* tmp = (sMsgListNodeDB80*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_DB80(char* self, void* msg)
{
    void* mp = msg;
    sMsgListDB80_insert(*(sMsgListNodeDB80**)(self + 0xF0), mp);
}

extern "C" void func_0025DB80(char* self, char* msg)
{
    *(int*)self = 1;
    int v = *(int*)(msg + 0x8);
    if (v == 0) {
        int type = 0xE4;
        char buf[0x100];
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F58), buf, 0x100, D_004A2F40);
        cBXString_cBXString4(self + 0x84, buf);
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_DB80(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = v;
        post_DB80(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DD08);
#ifdef SKIP_ASM
extern "C" int func_0025A730(void* self, const char* key, int def);
extern "C" void func_00268D88(void* self, void* a1, int a2);
extern "C" int func_003E8DC0(void* p, const char* key, int value, int timeout, void* cb, void* user);

extern "C" void func_0025DD08(void* self, const char* key, int def)
{
    if (*(int*)self != 0) {
        func_003E8DC0(*(void**)((char*)self + 0x54), key, func_0025A730(self, key, def), 0x1388, (void*)func_00268D88, self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DD68);
#ifdef SKIP_ASM
extern "C" int func_0025A730(void* self, const char* key, int def);
extern "C" void func_00268D88(void* self, void* a1, int a2);
extern "C" int func_003E8DC0(void* p, const char* key, int value, int timeout, void* cb, void* user);
extern "C" void* func_003EE560(void*);

extern "C" void func_0025DD68(char* self)
{
    if (*(int*)self != 0) {
        char* e = (char*)func_003EE560(*(void**)(self + 0x60));
        if (e != 0) {
            const char* key = e + 8;
            func_003E8DC0(*(void**)(self + 0x54), key, func_0025A730(self, key, *(int*)(e + 0x30)), 0x1388, (void*)func_00268D88, self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DDE0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481170[];
extern char D_004A2F58[];
extern char D_004A2F40[];
extern char D_004A3168[];
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" void* cBXString_cBXString2(void* self, const char* s);

struct sMsgListNodeDDE0 {
    sMsgListNodeDDE0* next;
    sMsgListNodeDDE0* prev;
    void* data;
};

struct sMsgListIterDDE0 {
    sMsgListNodeDDE0* node;
    sMsgListIterDDE0(sMsgListNodeDDE0* x) : node(x) {}
    sMsgListIterDDE0(const sMsgListIterDDE0& x) : node(x.node) {}
};

static inline sMsgListIterDDE0 sMsgListDDE0_insert(sMsgListIterDDE0 pos, void* const& x)
{
    sMsgListNodeDDE0* tmp = (sMsgListNodeDDE0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025DDE0(char* self, char* msg)
{
    char name[0x20];
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F58), name, 0x20, D_004A2F40);
    int v;
    if (*(int*)(msg + 0x8) != 0)
        v = 0x7F90;
    else
        v = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3168), 0);
    int* m = (int*)operator new(0x10, D_00480488, 0x20000000, 0);
    m[0] = 0xE5;
    *(void***)((char*)m + 0x4) = D_00481170;
    cBXString_cBXString2((char*)m + 0x8, name);
    m[3] = v;
    void* mp = m;
    sMsgListDDE0_insert(*(sMsgListNodeDDE0**)(self + 0xF0), mp);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025DF00);
#ifdef SKIP_ASM
extern char D_004A3108[];
extern char D_004A2FE0[];
extern "C" const char* func_00259198();
extern "C" void func_00268DB0(void* self, void* a1, int a2);

extern "C" void func_0025DF00(void* self, const char* name)
{
    if (*(int*)self != 0) {
        char buf[0x100];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, name);
        const char* key = D_004A2FE0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, key, func_00259198());
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0x10, 0x72657074, buf, (int)func_00268DB0, 20.0f);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025DF98);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeDF98 {
    sMsgListNodeDF98* next;
    sMsgListNodeDF98* prev;
    void* data;
};

struct sMsgListIterDF98 {
    sMsgListNodeDF98* node;
    sMsgListIterDF98(sMsgListNodeDF98* x) : node(x) {}
    sMsgListIterDF98(const sMsgListIterDF98& x) : node(x.node) {}
};

static inline sMsgListIterDF98 sMsgListDF98_insert(sMsgListIterDF98 pos, void* const& x)
{
    sMsgListNodeDF98* tmp = (sMsgListNodeDF98*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_DF98(char* self, void* msg)
{
    void* mp = msg;
    sMsgListDF98_insert(*(sMsgListNodeDF98**)(self + 0xF0), mp);
}

extern "C" void func_0025DF98(char* self, char* msg)
{
    *(int*)self = 1;
    int v = *(int*)(msg + 0x8);
    if (v == 0) {
        int type = 0xE8;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_DF98(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = v;
        post_DF98(self, m);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025E0C8);
#ifdef SKIP_ASM
extern char D_004A2F58[];
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* buf, int size, const char* key, int value);
extern "C" void func_0025B608(void* self, int a1, int tag, void* cb, int a4, float f);
extern "C" void func_00268DD8(void* self, void* a1, int a2);

extern "C" void func_0025E0C8(void* self, int value)
{
    if (*(int*)self != 0) {
        char buf[0x100];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A2F58, value);
        // PORT: function pointer passed through func_0025B608's int parameter.
        func_0025B608(self, 0xE, 0x6E657773, buf, (int)func_00268DD8, 20.0f);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025E138);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_00481210[];
extern void* D_004812B0[];
extern char D_00480890[];
extern char D_004808A0[];
extern char D_004808B0[];
extern char D_004808C0[];
extern char D_004813A0[];
extern char D_004A2F40[];
extern void* D_004A3328;
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" int func_00261460(void* p);
extern "C" void func_00261248(void* self, void* self2, int idx, void* a, void* b, int c);

struct sStateE138 {
    int active;     // 0x0
    int f4;
    int f8;
    int busy;       // 0xC
};

struct sNetMgrE138 {
    char pad[0xA4];
    int timeout;    // 0xA4
};

struct sMsgListNodeE138 {
    sMsgListNodeE138* next;
    sMsgListNodeE138* prev;
    void* data;
};

struct sMsgListIterE138 {
    sMsgListNodeE138* node;
    sMsgListIterE138(sMsgListNodeE138* x) : node(x) {}
    sMsgListIterE138(const sMsgListIterE138& x) : node(x.node) {}
};

static inline sMsgListIterE138 sMsgListE138_insert(sMsgListIterE138 pos, void* const& x)
{
    sMsgListNodeE138* tmp = (sMsgListNodeE138*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_E138(char* self, void* msg)
{
    void* mp = msg;
    sMsgListE138_insert(*(sMsgListNodeE138**)(self + 0xF0), mp);
}

extern "C" void func_0025E138(char* self, char* msg)
{
    sStateE138* st = (sStateE138*)self;
    st->active = 1;
    int type = *(int*)(msg + 0x8);
    if (type == 0x6E657731) {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0xE2;
        *(void***)((char*)m + 0x4) = D_00481210;
        cBXString_cBXString2(m + 2, *(char**)(msg + 0xC));
        post_E138(self, m);
    } else if (type == 0x6E657730) {
        st->busy = 1;
        if (func_00261460(D_004A3328) == 0) {
            char host[0x100];
            char name[0x100];
            cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_00480890), host, 0x100, D_004A2F40);
            int port = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004808A0), 0x34C1);
            cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004808B0), name, 0x100, D_004813A0);
            ((sNetMgrE138*)D_004A3328)->timeout = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004808C0), 0xD2F00);
            // PORT: a pointer passed through func_00261248's int parameter.
            func_00261248(D_004A3328, host, port, *(void**)(self + 0x80), *(void**)(self + 0x4C), (int)name);
        }
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = 0x111;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_E138(self, m);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025E348);
#ifdef SKIP_ASM
extern "C" void* func_003E8F08(void* ctx, int tag);
extern "C" unsigned int func_0025F338(void* self);
extern "C" void func_0025E420(void* self, int a1, int a2, int a3);
extern "C" void func_00259A60(char* self, int unused);

struct sDsSlotSessK2 {
    int active;                  // 0x0
    char pad_0x04[0x50];
    void* ctx;                   // 0x54
    char pad_0x58[0xF8 - 0x58];
    int slot;                    // 0xF8
    int pad_0xFC;
    void* slotTag;               // 0x100
    unsigned int limit[58];      // 0x104
    void* handles[29];           // 0x1EC
};

extern "C" void func_0025E348(sDsSlotSessK2* self, int slot)
{
    if (self->active != 0) {
        int old = self->slot;
        self->slot = slot;
        self->slotTag = func_003E8F08(self->ctx, 0x736C6F74);
        if (func_0025F338(self) < self->limit[slot]) {
            if (self->handles[self->slot] != 0) {
                func_003E8688(self->ctx, 4, self->handles[self->slot]);
                self->handles[self->slot] = 0;
            }
            func_0025E420(self, 0, 100, old);
        } else {
            func_00259A60((char*)self, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025E420);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* buf, int size, const char* key, int value);
extern "C" void func_0025B608(void* self, int a1, int tag, void* cb, int a4, float f);
extern "C" void* func_003E85B0(void* mgr, int idx, void* cb, void* user);
extern "C" int func_003E8D70(void* p, int a);
extern "C" void func_00268AE0(void* self, void* a1, int a2);
extern "C" void func_00268E00(void* self, void* a1, int a2);
extern int D_004A3180;
extern char D_004A3188[];
extern char D_004A3190[];
extern char D_004A3198[];
extern char D_004A31A0[];
extern char D_004A31A8[];

struct sDsSlotSessE420 {
    int active;                  // 0x0
    char pad_0x04[0x3C];
    int f40;                     // 0x40
    char pad_0x44[0x10];
    void* ctx;                   // 0x54
    char pad_0x58[0xF8 - 0x58];
    int slot;                    // 0xF8
    int pad_0xFC;
    void* slotTag;               // 0x100
    unsigned int limitA[29];     // 0x104
    unsigned int limitB[29];     // 0x178
    void* handles[29];           // 0x1EC
};

extern "C" void func_0025E420(void* self_, int a1, int a2, int a3)
{
    sDsSlotSessE420* self = (sDsSlotSessE420*)self_;
    if (self->active == 0)
        return;
    if (self->handles[self->slot] == 0)
        self->handles[self->slot] = func_003E85B0(self->ctx, 4, (void*)func_00268AE0, self);
    char buf[0x100];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A3188, self->slot);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A3190, D_004A3180 + 4);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A3198, a1);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A31A0, a2);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x100, D_004A31A8, self->slot);
    func_003E8D70(self->ctx, self->limitB[a3]);
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, self->active, 0x736E6170, buf, (int)func_00268E00, 20.0f);
    self->limitB[self->slot] = self->f40;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025E590);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];
extern char D_004A3198[];
extern char D_004A31A8[];
extern char D_004A31A0[];
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);

struct sMsgListNodeE590 {
    sMsgListNodeE590* next;
    sMsgListNodeE590* prev;
    void* data;
};

struct sMsgListIterE590 {
    sMsgListNodeE590* node;
    sMsgListIterE590(sMsgListNodeE590* x) : node(x) {}
    sMsgListIterE590(const sMsgListIterE590& x) : node(x.node) {}
};

static inline sMsgListIterE590 sMsgListE590_insert(sMsgListIterE590 pos, void* const& x)
{
    sMsgListNodeE590* tmp = (sMsgListNodeE590*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025E590(char* self, char* msg)
{
    int v = *(int*)(msg + 0x8);
    if (v == 0) {
        int a = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3198), 0);
        int idx = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31A8), 0);
        int b = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31A0), 0);
        *(int*)(self + (idx << 2) + 0x104) = a + b;
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = v;
        void* mp = m;
        sMsgListE590_insert(*(sMsgListNodeE590**)(self + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025E6D0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A3108[];
extern "C" void func_00268E28(void* self, void* a1, int a2);

struct sMsgListNodeE6D0 {
    sMsgListNodeE6D0* next;
    sMsgListNodeE6D0* prev;
    void* data;
};

struct sMsgListIterE6D0 {
    sMsgListNodeE6D0* node;
    sMsgListIterE6D0(sMsgListNodeE6D0* x) : node(x) {}
    sMsgListIterE6D0(const sMsgListIterE6D0& x) : node(x.node) {}
};

static inline sMsgListIterE6D0 sMsgListE6D0_insert(sMsgListIterE6D0 pos, void* const& x)
{
    sMsgListNodeE6D0* tmp = (sMsgListNodeE6D0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025E6D0(char* self, const char* name)
{
    if (*(int*)self != 0) {
        if (func_0041AA88(*(void**)(self + 0x80), (void*)name) == 0) {
            int type = 0x10E;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            m[0] = type;
            *(void***)((char*)m + 0x4) = D_004812B0;
            void* mp = m;
            sMsgListE6D0_insert(*(sMsgListNodeE6D0**)(self + 0xF0), mp);
        } else {
            char buf[0x100];
            buf[0] = 0;
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, name);
            *(int*)(self + 0x44) = 1;
            // PORT: function pointer passed through func_0025B608's int parameter.
            func_0025B608(self, *(int*)self, 0x75736572, buf, (int)func_00268E28, 20.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025E7F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A2F30[];
extern char D_004A2F40[];
extern char D_004A2FA0[];
extern char D_004A3108[];
extern char D_004A3128[];
extern char D_004A31C0[];
extern char D_004A31C8[];
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern void* D_00481190[];
extern void* D_00481290[];

struct sMsgListNodeE7F0 {
    sMsgListNodeE7F0* next;
    sMsgListNodeE7F0* prev;
    void* data;
};

struct sMsgListIterE7F0 {
    sMsgListNodeE7F0* node;
    sMsgListIterE7F0(sMsgListNodeE7F0* x) : node(x) {}
    sMsgListIterE7F0(const sMsgListIterE7F0& x) : node(x.node) {}
};

static inline sMsgListIterE7F0 sMsgListE7F0_insert(sMsgListIterE7F0 pos, void* const& x)
{
    sMsgListNodeE7F0* tmp = (sMsgListNodeE7F0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_E7F0(char* self, void* msg)
{
    void* mp = msg;
    sMsgListE7F0_insert(*(sMsgListNodeE7F0**)(self + 0xF0), mp);
}

struct sRecE7F0 {
    int id;
    int start;
    int end;
    int len;
    int extra;
};

struct sMsgE7F0 {
    int type;
    void** vt;
    char name[4];       // 0x8 cBXString
    char text[4];       // 0xC cBXString
    int on;             // 0x10
    int count;          // 0x14
    sRecE7F0 rec;       // 0x18
};

extern "C" void func_0025E7F0(char* self, char* msg)
{
    *(int*)(self + 0x44) = 0;
    int err = *(int*)(msg + 0x8);
    if (err == 0) {
        char name[0x100];
        char text[0x100];
        sRecE7F0 rec;
        char buf[0x100];
        int st[16];
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3108), name, 0x100, D_004A2F40);
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3128), buf, 0x100, D_004A2F40);
        cDirtysock_tag_TagFieldGetStructure(buf, st, 0x40, D_004A2F30);
        rec.start = st[2];
        rec.end = st[2] + st[3] + st[4];
        rec.len = st[6];
        rec.id = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31C0), -1);
        rec.extra = -1;
        int count = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2FA0), 0);
        int on = count > 0;
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31C8), text, 0x100, D_004A2F40);
        sMsgE7F0* m = (sMsgE7F0*)operator new(0x2C, D_00480488, 0x20000000, 0);
        m->type = 0xE3;
        m->vt = D_00481190;
        cBXString_cBXString2(m->name, name);
        cBXString_cBXString2(m->text, text);
        m->on = on;
        m->count = count;
        m->rec = rec;
        post_E7F0(self, m);
    } else {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = err;
        post_E7F0(self, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025EAA0);
#ifdef SKIP_ASM
extern "C" void func_00268E50(void* self, void* a1, int a2);

extern "C" void func_0025EAA0(char* self, const char* name)
{
    char buf[0x100];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, name);
    // PORT: function pointer passed through func_003E8B10's int parameter.
    func_003E8B10(*(void**)(self + 0x54), 0x6F6E6C6E, buf, (int)func_00268E50, self);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025EB00);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* tag, int defval);
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A2F30[];
extern char D_004A2F38[];
extern char D_004A2F40[];
extern char D_004A3130[];
extern char D_004A31D8[];
extern char D_004A31E0[];
extern char D_004A31E8[];
extern char D_004A31F0[];
extern char D_004A31F8[];
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
extern void* D_00481110[];
extern void* D_00481290[];

struct sMsgListNode25EB00 {
    sMsgListNode25EB00* next;
    sMsgListNode25EB00* prev;
    void* data;
};

struct sMsgListIter25EB00 {
    sMsgListNode25EB00* node;
    sMsgListIter25EB00(sMsgListNode25EB00* x) : node(x) {}
    sMsgListIter25EB00(const sMsgListIter25EB00& x) : node(x.node) {}
};

static inline sMsgListIter25EB00 sMsgList25EB00_insert(sMsgListIter25EB00 pos, void* const& x)
{
    sMsgListNode25EB00* tmp = (sMsgListNode25EB00*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_25EB00(char* self, void* msg)
{
    void* mp = msg;
    sMsgList25EB00_insert(*(sMsgListNode25EB00**)(self + 0xF0), mp);
}

struct sRec25EB00 {
    int id;
    int start;
    int end;
    int len;
    int extra;
};

struct sMsg25EB00 {
    int type;
    void** vt;
    char name[0x20];    // 0x8
    char b1[0x20];      // 0x28
    char b2[0x20];      // 0x48
    char pad68[0xE0];
    int f148;
    int f14C;
    sRec25EB00 rec;     // 0x150
};

extern "C" void func_0025EB00(char* self, char* msg)
{
    int err = *(int*)(msg + 0x8);
    if (err == 0) {
        char name[0x100];
        char b1[0x100];
        char b2[0x100];
        char buf[0x14];
        int st[16];
        sRec25EB00 rec;
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31D8), name, 0x100, D_004A2F40);
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A2F38), b1, 0x100, D_004A2F40);
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31E0), b2, 0x100, D_004A2F40);
        int n1 = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31E8), -1);
        int n2 = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31F0), -1);
        cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A31F8), buf, 0x14, D_004A2F40);
        int n3 = cDirtysock_tag_TagFieldGetNumber(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3130), 0);
        cDirtysock_tag_TagFieldGetStructure(buf, st, 0x40, D_004A2F30);
        rec.start = st[2];
        rec.end = st[2] + st[3] + st[4];
        rec.len = st[6];
        rec.id = n3;
        rec.extra = n1;
        sMsg25EB00* m = (sMsg25EB00*)operator new(0x164, D_00480488, 0x20000000, 0);
        m->type = 0x10D;
        m->vt = D_00481110;
        m->f148 = n2;
        m->f14C = n1;
        strcpy(m->name, name);
        strcpy(m->b1, b1);
        strcpy(m->b2, b2);
        m->rec = rec;
        post_25EB00(self, m);
    } else if (err != 0x75757372) {
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = err;
        post_25EB00(self, m);
    }
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025EE20);
#ifdef SKIP_ASM
extern char D_004A3200[];
extern char D_004A3208[];
extern char D_004808D0[];
extern char D_004A2F30[];
extern "C" int cDirtysock_tag_TagFieldSetStructure(char* buf, int size, const char* key, const void* data, int len, const char* fmt);
extern "C" void func_00268E78(void* self, void* a1, int a2);

extern "C" void func_0025EE20(void* self, const void* data, int a2)
{
    int st = *(int*)self;
    if (st != 0) {
        bool on = (st == 1);
        if (on) {
            char buf[0x100];
            *(int*)((char*)self + 0xA4) = a2;
            buf[0] = 0;
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3200, D_004808D0);
            cDirtysock_tag_TagFieldSetStructure(buf, 0x100, D_004A3208, data, 0x14, D_004A2F30);
            // PORT: function pointer passed through func_0025B608's int parameter.
            func_0025B608(self, 0x12, 0x7175696B, buf, (int)func_00268E78, 20.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025EED8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_004A3200[];
extern char D_004A3218[];
extern "C" int* func_002591D0();
extern "C" void func_00263BA8(void* p, int arg);
extern "C" void func_00268E78(void* self, void* a1, int a2);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNodeEED8 {
    sMsgListNodeEED8* next;
    sMsgListNodeEED8* prev;
    void* data;
};

struct sMsgListIterEED8 {
    sMsgListNodeEED8* node;
    sMsgListIterEED8(sMsgListNodeEED8* x) : node(x) {}
    sMsgListIterEED8(const sMsgListIterEED8& x) : node(x.node) {}
};

static inline sMsgListIterEED8 sMsgListEED8_insert(sMsgListIterEED8 pos, void* const& x)
{
    sMsgListNodeEED8* tmp = (sMsgListNodeEED8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_EED8(char* self, void* msg)
{
    void* mp = msg;
    sMsgListEED8_insert(*(sMsgListNodeEED8**)(self + 0xF0), mp);
}

extern "C" void func_0025EED8(char* self)
{
    int st = *(int*)self;
    if (st == 0)
        return;
    if (st == 0x19) {
        if (*func_002591D0() != 0)
            func_00263BA8(func_002591D0(), 2);
    } else if (st != 1) {
        char buf[0x100];
        buf[0] = 0;
        cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3200, D_004A3218);
        *(float*)(self + 0xE0) = 20.0f;
        // PORT: function pointer passed through func_003E8B10's int parameter.
        *(int*)(self + 0x40) = func_003E8B10(*(void**)(self + 0x54), 0x7175696B, buf, (int)func_00268E78, self);
    }
    *(int*)self = 1;
    int type = 0xE7;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = type;
    *(void***)((char*)m + 0x4) = D_004812B0;
    post_EED8(self, m);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F030);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];

struct sMsgListNodeK2e {
    sMsgListNodeK2e* next;
    sMsgListNodeK2e* prev;
    void* data;
};

struct sMsgListIterK2e {
    sMsgListNodeK2e* node;
    sMsgListIterK2e(sMsgListNodeK2e* x) : node(x) {}
    sMsgListIterK2e(const sMsgListIterK2e& x) : node(x.node) {}
};

static inline sMsgListIterK2e sMsgListK2e_insert(sMsgListIterK2e pos, void* const& x)
{
    sMsgListNodeK2e* tmp = (sMsgListNodeK2e*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern void* D_00481290[];

extern "C" void func_0025F030(char* self, char* msg)
{
    if (*(int*)(msg + 0x8) == 0) {
        if (*(int*)self == 0x12)
            *(int*)self = 0x14;
    } else {
        *(int*)self = 1;
        int v = *(int*)(msg + 0x8);
        int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = v;
        void* mp = m;
        sMsgListK2e_insert(*(sMsgListNodeK2e**)(self + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F120);
#ifdef SKIP_ASM
extern "C" int func_003EE558(void*);

extern "C" int func_0025F120(void* self)
{
    if (*(int*)self == 0) {
        return 0;
    }
    return func_003EE558(*(void**)((char*)self + 0x5C));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F150);
#ifdef SKIP_ASM
extern "C" void* func_003EE560(void*);

extern "C" void* func_0025F150(void* self, int i)
{
    if (*(int*)self == 0) {
        return 0;
    }
    return (char*)func_003EE560(*(void**)((char*)self + 0x5C)) + 0x1C;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F180);
#ifdef SKIP_ASM
extern "C" void* func_003EE560(void*);

static inline short getFlags(void* p)
{
    return *(short*)((char*)p + 0xA);
}

extern "C" int func_0025F180(void* self)
{
    if (*(int*)self == 0) {
        return 0;
    }
    return getFlags(func_003EE560(*(void**)((char*)self + 0x5C))) & 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F1B0);
#ifdef SKIP_ASM
extern "C" int func_003EE558(void*);

extern "C" int func_0025F1B0(void* self)
{
    if (*(int*)self == 0) {
        return 0;
    }
    return func_003EE558(*(void**)((char*)self + 0x60));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F1E0);
#ifdef SKIP_ASM
extern char D_004A2ED0[];
// PORT: the unit declares func_003EE560 with one parameter; this caller passes (list, index).
void* func_003EE560_2(void* list, int idx) __asm__("func_003EE560");

extern "C" char* func_0025F1E0(void* self, int idx, int* outFlag)
{
    if (*(int*)self == 0) {
        return 0;
    }
    char* p = (char*)func_003EE560_2(*(void**)((char*)self + 0x60), idx);
    if (p != 0) {
        if (outFlag != 0) {
            *outFlag = (*(int*)(p + 0x4) >> 21) & 1;
        }
        return p + 8;
    }
    return D_004A2ED0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F248);
#ifdef SKIP_ASM
extern "C" int func_0025F248(void* self)
{
    void* p;
    if (*(int*)self == 0) {
        return 0;
    }
    p = func_003EE560(*(void**)((char*)self + 0x60));
    if (p != 0) {
        return (*(int*)((char*)p + 0x4) >> 21) & 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F288);
#ifdef SKIP_ASM
extern char D_004A2F30[];
extern "C" void* func_003EE560(void*);
extern "C" int func_004187C0(const char* s);
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);

struct sDsPeerK2 {
    char pad_0x00[0x28];
    char name[0xC];      // 0x28
    int addr;            // 0x34
    char record[1];      // 0x38
};

struct sDsPeerInfoK2 {
    int addr;            // 0x0
    int a;               // 0x4
    int total;           // 0x8
    int b;               // 0xC
    int nameLen;         // 0x10
};

extern "C" void func_0025F288(void* self, int a1, sDsPeerInfoK2* out)
{
    if (*(int*)self != 0) {
        int st[16];
        const char* rec;
        sDsPeerK2* e = (sDsPeerK2*)func_003EE560(*(void**)((char*)self + 0x60));
        if (e != 0 && e->record != 0) {
            rec = e->record;
            out->addr = e->addr;
            out->nameLen = func_004187C0(e->name);
        } else {
            out->addr = 0;
            rec = 0;
            out->nameLen = 0;
        }
        cDirtysock_tag_TagFieldGetStructure(rec, st, 0x40, D_004A2F30);
        out->a = st[2];
        out->total = st[2] + st[3] + st[4];
        out->b = st[6];
    }
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_0025F338);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F388);
#ifdef SKIP_ASM
extern char D_004A2F30[];
extern "C" void* func_003EE560(void*);
extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* tag, void* data, int len, const char* fmt);

struct sDsSlotSessK2b {
    int active;                  // 0x0
    char pad_0x04[0xF8 - 0x4];
    int slot;                    // 0xF8
    char pad_0xFC[0x1EC - 0xFC];
    void* handles[29];           // 0x1EC
};

extern "C" void* func_0025F388(sDsSlotSessK2b* self, int a1, int* outA, int* outB)
{
    if (self->active == 0)
        return 0;
    char* e = (char*)func_003EE560(self->handles[self->slot]);
    if (e != 0) {
        int st[2];
        cDirtysock_tag_TagFieldGetStructure(e + 0x28, st, 8, D_004A2F30);
        *outB = st[1];
        if (self->slot != 0)
            *outA = st[0];
        else
            *outA = *(int*)e;
    }
    return e;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F430);
#ifdef SKIP_ASM
extern "C" char* func_003E8A70(void* p, int tag);
extern "C" bool func_0025F430(void* self)
{
    char* s;
    if (*(int*)self == 0) {
        return false;
    }
    s = func_003E8A70(*(void**)((char*)self + 0x54), 0x726F6F6D);
    return s != 0 && *s != 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F478);
#ifdef SKIP_ASM
extern "C" void func_0025F4C0(void*, char*, int);

extern "C" void func_0025F478(void* self, int idx, int a2)
{
    func_0025F4C0(self, func_0025F1E0(self, idx, 0), a2);
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_0025F4C0);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F628);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern "C" int func_003E8D70(void* p, int a);
extern "C" void func_0025F858(void* self);
extern "C" void func_0025F740(void* self, int type);
void* func_0025FC48(void* self);

struct sMsgListNodeF628 {
    sMsgListNodeF628* next;
    sMsgListNodeF628* prev;
    void* data;
};

struct sMsgListIterF628 {
    sMsgListNodeF628* node;
    sMsgListIterF628(sMsgListNodeF628* x) : node(x) {}
    sMsgListIterF628(const sMsgListIterF628& x) : node(x.node) {}
};

static inline sMsgListIterF628 sMsgListF628_insert(sMsgListIterF628 pos, void* const& x)
{
    sMsgListNodeF628* tmp = (sMsgListNodeF628*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025F628(void* selfp, int notify, int flag)
{
    char* self = (char*)selfp;
    int st = *(int*)self;
    if (st != 0) {
        if (st == 0x15 || st == 0x16 || st == 0x18) {
            if (flag)
                func_0025FC48(self);
            func_003E8D70(*(void**)(self + 0x54), *(int*)(self + 0x40));
            func_0025F858(self);
        } else if (st == 0x19) {
            func_0025F740(self, 0);
        }
        if (notify) {
            int type = 0xEE;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            m[0] = type;
            *(void***)((char*)m + 0x4) = D_004812B0;
            void* mp = m;
            sMsgListF628_insert(*(sMsgListNodeF628**)(self + 0xF0), mp);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F740);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_004A3108[];
extern char D_004A3218[];

struct sMsgListNodeF740 {
    sMsgListNodeF740* next;
    sMsgListNodeF740* prev;
    void* data;
};

struct sMsgListIterF740 {
    sMsgListNodeF740* node;
    sMsgListIterF740(sMsgListNodeF740* x) : node(x) {}
    sMsgListIterF740(const sMsgListIterF740& x) : node(x.node) {}
};

static inline sMsgListIterF740 sMsgListF740_insert(sMsgListIterF740 pos, void* const& x)
{
    sMsgListNodeF740* tmp = (sMsgListNodeF740*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025F740(void* selfp, int type)
{
    char* self = (char*)selfp;
    if (*(int*)self != 0) {
        if (*(int*)self == 0x19) {
            char buf[0x100];
            *(float*)(self + 0xE0) = 20.0f;
            buf[0] = 0;
            cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, D_004A3218);
            func_003E8B10(*(void**)(self + 0x54), 0x6368616C, buf, 0, 0);
            *(int*)self = 1;
        }
        if (type != 0) {
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            m[0] = type;
            *(void***)((char*)m + 0x4) = D_004812B0;
            void* mp = m;
            sMsgListF740_insert(*(sMsgListNodeF740**)(self + 0xF0), mp);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F858);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);

extern "C" void func_0025F858(void* self)
{
    func_003E8B10(*(void**)((char*)self + 0x54), 0x6368616C, D_004A2F40, 0, 0);
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025F8A0);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_00481290[];
extern char D_004A2F40[];
extern char D_004A3220[];
extern char D_004A3228[];
extern char D_004A3230[];
extern char D_004A3238[];
extern float D_004A5154;
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);
void* func_0025FC48(void* self);
extern "C" void func_0025FC70(void* self, int a1, int a2);
extern "C" int func_004165A8(void*, void*);

struct sMsgListNodeF8A0 {
    sMsgListNodeF8A0* next;
    sMsgListNodeF8A0* prev;
    void* data;
};

struct sMsgListIterF8A0 {
    sMsgListNodeF8A0* node;
    sMsgListIterF8A0(sMsgListNodeF8A0* x) : node(x) {}
    sMsgListIterF8A0(const sMsgListIterF8A0& x) : node(x.node) {}
};

static inline sMsgListIterF8A0 sMsgListF8A0_insert(sMsgListIterF8A0 pos, void* const& x)
{
    sMsgListNodeF8A0* tmp = (sMsgListNodeF8A0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025F8A0(char* self, char* msg)
{
    char buf[16];
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(*(char**)(msg + 0xC), D_004A3220), buf, 0x10, D_004A2F40);
    if (*(int*)(msg + 0x8) != 0) {
        if (*(int*)self == 0x15) {
            *(int*)self = 1;
            func_0025FC48(self);
            int* m = (int*)operator new(0xC, D_00480488, 0x20000000, 0);
            m[0] = 0x102;
            *(void***)((char*)m + 0x4) = D_00481290;
            m[2] = *(int*)(msg + 0x8);
            void* mp = m;
            sMsgListF8A0_insert(*(sMsgListNodeF8A0**)(self + 0xF0), mp);
        }
    } else if (func_004165A8(buf, D_004A3228) == 0) {
        if (*(int*)self == 0x15)
            func_0025FC70(self, *(int*)(self + 0x98), 0x18);
    } else if (func_004165A8(buf, D_004A3230) == 0) {
    } else if (func_004165A8(buf, D_004A3238) == 0) {
        if (*(int*)self == 0x15) {
            *(int*)self = 0x18;
            *(float*)(self + 0xE0) = 20.0f;
            D_004A5154 = 20.0f;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025FA48);
#ifdef SKIP_ASM
extern char D_004A3108[];
extern char D_004A2F68[];
extern char D_004A3240[];
extern "C" void func_00268EA0(void* self, void* a1, int a2);

extern "C" void func_0025FA48(void* self, const char* name)
{
    char buf[0x100];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, name);
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A2F68, D_004A3240);
    *(int*)self = 1;
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 0x15, 0x6368616C, buf, (int)func_00268EA0, 20.0f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_0025FAD0);
#ifdef SKIP_ASM
extern char D_004A3108[];
extern char D_004A2F68[];
extern char D_004A3250[];
extern "C" void func_00268EA0(void* self, void* a1, int a2);

extern "C" void func_0025FAD0(void* self, const char* name)
{
    char buf[0x100];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3108, name);
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A2F68, D_004A3250);
    *(int*)self = 1;
    // PORT: function pointer passed through func_0025B608's int parameter.
    func_0025B608(self, 0x18, 0x6368616C, buf, (int)func_00268EA0, 20.0f);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FB58);
#ifdef SKIP_ASM
extern "C" void func_0025FC70(void* self, int a1, int a2);

extern "C" void func_0025FB58(void* self, int a1, int a2)
{
    if (*(int*)self != 0) {
        *(int*)((char*)self + 0xA4) = a2;
        func_0025FC70(self, a1, 0x17);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FB80);
#ifdef SKIP_ASM
extern char D_004A3258[];
extern char D_004A3010[];
extern char D_004A3260[];
extern "C" int cDirtysock_tag_TagFieldSetFlags(char* record, int len, const char* name, int value);
extern "C" void func_00268EC8(void* self, void* a1, int a2);

// PORT: a1 carries a string pointer in an int (the unit's declaration).
extern "C" void* func_0025FB80(void* self, int a1, void* a2)
{
    char buf[0x100];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3258, (const char*)a1);
    cDirtysock_tag_TagFieldSetString(buf, 0x100, D_004A3010, (const char*)a2);
    cDirtysock_tag_TagFieldSetFlags(buf, 0x100, D_004A3260, 0x40004000);
    // PORT: function pointer passed through func_003E8B10's int parameter.
    return (void*)func_003E8B10(*(void**)((char*)self + 0x54), 0x6D657367, buf, (int)func_00268EC8, self);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FC20__FPv);
#ifdef SKIP_ASM
void func_0025FC20(void* self)
{
}
#endif

extern void* D_004A3270[];
extern "C" void* func_0025FB80(void*, int, void*);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FC28__FPvi);
#ifdef SKIP_ASM
void* func_0025FC28(void* self, int a1)
{
    return func_0025FB80(self, a1, (void*)D_004A3270);
}
#endif

extern void* D_004807F8[];
extern "C" void* func_0025FB80(void*, int, void*);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FC48__FPv);
#ifdef SKIP_ASM
void* func_0025FC48(void* self)
{
    return func_0025FB80(self, *(int*)((char*)self + 0x98), (void*)D_004807F8);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_0025FC70);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_00480910[];
extern float D_004A5154;

struct sMsgListNode_0025FC70 {
    sMsgListNode_0025FC70* next;
    sMsgListNode_0025FC70* prev;
    void* data;
};

struct sMsgListIter_0025FC70 {
    sMsgListNode_0025FC70* node;
    sMsgListIter_0025FC70(sMsgListNode_0025FC70* x) : node(x) {}
    sMsgListIter_0025FC70(const sMsgListIter_0025FC70& x) : node(x.node) {}
};

static inline sMsgListIter_0025FC70 sMsgList_0025FC70_insert(sMsgListIter_0025FC70 pos, void* const& x)
{
    sMsgListNode_0025FC70* tmp = (sMsgListNode_0025FC70*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_0025FC70(void* self, int a1, int a2)
{
    func_0025FB80(self, a1, D_00480910);
    int kind = 0x110;
    *(int*)self = a2;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_0025FC70_insert(*(sMsgListNode_0025FC70**)((char*)self + 0xF0), mp);
    *(float*)((char*)self + 0xE0) = 20.0f;
    D_004A5154 = 21.0f;
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_0025FD50);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00260C68);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A28A8;
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_00481290[];
extern int D_00534B34[];

struct sMsgListNode0C68 {
    sMsgListNode0C68* next;
    sMsgListNode0C68* prev;
    void* data;
};

struct sMsgListIter0C68 {
    sMsgListNode0C68* node;
    sMsgListIter0C68(sMsgListNode0C68* x) : node(x) {}
    sMsgListIter0C68(const sMsgListIter0C68& x) : node(x.node) {}
};

static inline sMsgListIter0C68 sMsgList0C68_insert(sMsgListIter0C68 pos, void* const& x)
{
    sMsgListNode0C68* tmp = (sMsgListNode0C68*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_0C68(char* lst, void* msg)
{
    void* mp = msg;
    sMsgList0C68_insert(*(sMsgListNode0C68**)(lst + 4), mp);
}

extern "C" void func_00260C68(char* self, char* msg)
{
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (*(int*)(msg + 0x8) == 0 || (*(int*)(msg + 0x8) == 0x72616E6B && D_00534B34[0] == 0)) {
        int type = 0x101;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        post_0C68(self + 0xEC, m);
    } else {
        int err = *(int*)(msg + 0x8);
        char* lst = self + 0xEC;
        int* m = (int*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
        m[0] = 0x102;
        *(void***)((char*)m + 0x4) = D_004812B0;
        *(void***)((char*)m + 0x4) = D_00481290;
        m[2] = err;
        post_0C68(lst, m);
        int type = 0x101;
        int* m2 = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
        *(void***)((char*)m2 + 0x4) = D_004812B0;
        m2[0] = type;
        post_0C68(lst, m2);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00260E50);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" void func_003194A8(void* str, const char* fmt, ...);
extern void* D_004A3E90;
extern char D_00480E10[];
extern char D_004A3320[];
extern char D_00480E20[];

struct sBXStr_00260E50 {
    char* p;
};

// Builds the display name of a 4-character tag.
extern "C" void* func_00260E50(void* ret, void* self, unsigned int tag)
{
    switch (tag)
    {
    case 0x6475706C:
        cBXString_cBXString2(ret, D_00480E10);
        break;
    case 0x74696D65:
        cBXString_cBXString2(ret, D_004A3320);
        break;
    default:
    {
        sBXStr_00260E50 s;
        s.p = (char*)D_004A3E90;
        func_003194A8(&s, D_00480E20, tag, tag >> 24, (tag >> 16) & 0xFF, (tag >> 8) & 0xFF, tag & 0xFF);
        cBXString_cBXString1(ret, &s);
        cBXString__cBXString(&s, 2);
        break;
    }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00260F10);
#ifdef SKIP_ASM
extern "C" void cBXString_Reset(void* self);

extern "C" void func_00260F10(void* self)
{
    cBXString_Reset((char*)self + 0x260);
    cBXString_Reset((char*)self + 0x264);
    cBXString_Reset((char*)self + 0x268);
    cBXString_Reset((char*)self + 0x26C);
    cBXString_Reset((char*)self + 0x270);
    *(int*)((char*)self + 0x298) = 1;
    *(int*)((char*)self + 0x29C) = 1;
    *(int*)((char*)self + 0x288) = 1;
    *(int*)((char*)self + 0x294) = 0;
    *(int*)((char*)self + 0x28C) = 1;
    *(int*)((char*)self + 0x290) = 0x7C1;
    *(int*)((char*)self + 0x2A0) = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00260F80);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480E48[];
extern void* D_004A3E90;
extern void* D_004A3328;

// Creates the memory-card manager singleton (D_004A3328).
extern "C" void func_00260F80(void)
{
    // An unused 32-byte local is needed to reproduce the 0x30-byte frame.
    int unused[8];
    char* m = (char*)operator new(0xF0, D_00480E48, 0x20000000, 0);
    *(int*)(m + 0x40) = -1;
    *(int*)(m + 0xA4) = 0x15180;
    *(void**)(m + 0xEC) = D_004A3E90;
    *(int*)(m + 0xAC) = 0;
    *(int*)(m + 0xB0) = 0;
    *(int*)(m + 0xB4) = 0;
    *(int*)(m + 0xBC) = 0;
    *(int*)(m + 0xC0) = 0;
    *(int*)(m + 0xC4) = 0;
    *(int*)(m + 0xC8) = 0;
    *(int*)(m + 0xCC) = 0;
    *(int*)(m + 0xD0) = 0;
    *(int*)(m + 0xD8) = 0;
    *(int*)(m + 0xDC) = 0;
    *(int*)(m + 0xE0) = 0;
    *(int*)(m + 0xE4) = 0;
    *(int*)(m + 0xE8) = 0;
    D_004A3328 = m;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261008);
#ifdef SKIP_ASM
extern void* D_004A3328;
void func_00261058(void* self);
struct sVec261070;
extern "C" void func_00261070(sVec261070* self);
extern "C" void func_00261408(void* self);
extern "C" void func_002689B8(void* self, int flags);

extern "C" void func_00261008(void)
{
    if (D_004A3328 != 0) {
        func_00261058(D_004A3328);
        func_00261070((sVec261070*)D_004A3328);
        func_00261408(D_004A3328);
        if (D_004A3328 != 0) {
            func_002689B8(D_004A3328, 3);
        }
        D_004A3328 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261058__FPv);
#ifdef SKIP_ASM
void func_00261058(void* self)
{
    *(char*)self = 0;
    *(int*)((char*)self + 0x40) = -1;
    *(char*)((char*)self + 0x44) = 0;
    *(char*)((char*)self + 0x64) = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261070);
#ifdef SKIP_ASM
struct sVE261070 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj261070 {
    char pad[0xC];
    sVE261070* vt;
};

struct sVec261070 {
    char pad[0xAC];
    sObj261070** begin;
    sObj261070** end;
};

extern "C" void func_00261070(sVec261070* self)
{
    while (self->begin != self->end) {
        sObj261070* p = self->end[-1];
        self->end--;
        if (p != 0) {
            p->vt[1].fn((char*)p + p->vt[1].delta, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002610D0);
#ifdef SKIP_ASM
extern void* D_004A3328;
extern void* D_004A3028;
extern "C" void func_00260F80(void);
extern "C" int func_00261460(void* p);
extern "C" void func_002613C8(void* p);
extern "C" void func_0025B800(void* self);
extern "C" int func_00262938(void* self);
extern "C" void* func_00263630(void* self, unsigned int i);
extern "C" int func_00262468(void* self, int a1);
extern "C" void func_00261EF8(void* self, int a1, int a2, void* out);

static inline void* Mgr_2610D0()
{
    if (D_004A3328 == 0)
        func_00260F80();
    if (func_00261460(D_004A3328) == 0)
        func_002613C8(D_004A3328);
    if (D_004A3328 == 0)
        func_0025B800(D_004A3028);
    return D_004A3328;
}

extern "C" void func_002610D0()
{
    for (int i = 0; i < func_00262938(Mgr_2610D0()); i++)
    {
        int* e = (int*)func_00263630(Mgr_2610D0(), i);
        if (func_00262468(Mgr_2610D0(), *e) < 0)
        {
            int out;
            func_00261EF8(Mgr_2610D0(), *e, 2, &out);
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261248);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cBXString_Concat(void* self, const char* str);
extern "C" const char* func_00259198();
extern "C" void func_002614E8(void* self, void* a1);
extern "C" int func_003F0818(void* p, const char* a1, int tag, const char* a3, int a4);
extern "C" int func_003F08E8(void* p, const char* name, int a2, int a3, const char* s1, const char* s2, void* cb, void* user);
extern "C" void func_00268F18(void* self, void* a1, int a2);
extern void* D_004A3E90;
extern char D_004A3330[];
extern char D_004A3338[];

struct sDsGame_261248 {
    char name[0x40];        // 0x0
    int idx;                // 0x40
    char a[0x20];           // 0x44
    char b[0x64];           // 0x64
    void* ctx;              // 0xC8
    int fCC;
    int fD0;                // 0xD0
    float fD4;              // 0xD4
    int fD8;                // 0xD8
    int fDC;                // 0xDC
    int fE0;                // 0xE0
};

struct sBXStr_261248 {
    char* p;
    sBXStr_261248() : p((char*)D_004A3E90) {}
    sBXStr_261248(const sBXStr_261248& o) : p(o.p) {}
};

// PORT: the unit declares (void*, void*, int, void*, void*, int); the last int is really a string pointer.
extern "C" void func_00261248(void* self_, void* name_, int a2, void* a3_, void* a4_, int a5_)
{
    char* self = (char*)self_;
    const char* name = (const char*)name_;
    const char* a3 = (const char*)a3_;
    const char* a4 = (const char*)a4_;
    const char* a5 = (const char*)a5_;
    if (*(void**)(self + 0xC8) == 0)
    {
        func_002614E8(self, (void*)a5);
        func_003F0818(*(void**)(self + 0xC8), a5, 0x73737833, func_00259198(), 0);
    }
    strcpy(self, name);
    *(int*)(self + 0x40) = a2;
    strcpy(self + 0x44, a3);
    strcpy(self + 0x64, a4);
    sDsGame_261248* g = (sDsGame_261248*)self;
    g->fD0 = 0;
    g->fD4 = 30.0f;
    g->fD8 = 1;
    g->fDC = 0;
    g->fE0 = 0;
    sBXStr_261248 s1;
    cBXString_cBXString4(&s1, a3);
    cBXString_Concat(&s1, D_004A3330);
    cBXString_Concat(&s1, a4);
    sBXStr_261248 s2;
    cBXString_cBXString4(&s2, D_004A3338);
    cBXString_Concat(&s2, a5);
    cBXString_cBXString4(self + 0xEC, a5);
    func_003F08E8(*(void**)(self + 0xC8), name, a2, 0x1E, s1.p, s2.p, (void*)func_00268F18, self);
    cBXString__cBXString(&s2, 2);
    cBXString__cBXString(&s1, 2);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002613C8);
#ifdef SKIP_ASM
extern "C" void func_00261248(void* self, void* self2, int idx, void* a, void* b, int c);
extern "C" void func_002613C8(void* self)
{
    int idx = *(int*)((char*)self + 0x40);
    if (idx >= 0) {
        bool ok = !*(bool*)((char*)self + 0xD8);
        if (ok) {
            func_00261248(self, self, idx, (char*)self + 0x44, (char*)self + 0x64, *(int*)((char*)self + 0xEC));
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261408);
#ifdef SKIP_ASM
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern "C" void func_00261530(void* self);

extern "C" void func_00261408(void* self)
{
    func_00262768(self, 0, 1, 0, 0, 0);
    func_00261530(self);
    *(int*)((char*)self + 0xD8) = 0;
    *(int*)((char*)self + 0xD0) = 0;
    *(int*)((char*)self + 0xDC) = 0;
    *(int*)((char*)self + 0xE0) = 0;
    *(int*)((char*)self + 0xE8) = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261460);
#ifdef SKIP_ASM
extern "C" long f_261460(void* p) __asm__("func_00261460");
extern "C" long f_261460(void* p)
{
    char* s = (char*)p;
    return *(int*)(s + 0xC8) != 0 && (*(int*)(s + 0xD8) ^ 1) != 0 && *(int*)(s + 0xE0) != 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261490);
#ifdef SKIP_ASM
extern "C" void func_003F17D8(void* p);
extern "C" void func_00261408(void* self);

extern "C" void func_00261490(void* self)
{
    void* p = *(void**)((char*)self + 0xC8);
    if (p != 0) {
        func_003F17D8(p);
        if (*(int*)((char*)self + 0xDC) != 0) {
            func_00261408(self);
            *(int*)((char*)self + 0xDC) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002614E0);
#ifdef SKIP_ASM
extern "C" void func_002614E0(void) {

}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002614E8);
#ifdef SKIP_ASM
extern char D_00480E58[];
extern "C" void func_00268F40(void* self);
extern "C" void* func_003F0710(void* a, const char* name);
extern "C" void func_003F17C8(void* h, void (*cb)(void*), void* user);

extern "C" void func_002614E8(void* self, void* a1)
{
    void* h = func_003F0710(a1, D_00480E58);
    *(void**)((char*)self + 0xC8) = h;
    func_003F17C8(h, func_00268F40, self);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261530);
#ifdef SKIP_ASM
extern void* D_004A3028;
// PORT: callee defined as returning void* in this unit; called here as void.
void func_0025FC28_v(void* self, int a1) __asm__("func_0025FC28__FPvi");
extern "C" void func_003F0BE0(void* p);
extern "C" void func_003F07A0(void* p);

struct sVE261530 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj261530 {
    int id;
    char pad[0x38];
    sVE261530* vt;
};

struct sMgr261530 {
    char pad[0xBC];
    sObj261530** begin;
    sObj261530** end;
    char pad2[4];
    void* h;
    int cc;
};

extern "C" void func_00261530(void* vself)
{
    sMgr261530* self = (sMgr261530*)vself;
    if (self->h != 0) {
        while (self->begin != self->end) {
            sObj261530* p = self->end[-1];
            func_0025FC28_v(D_004A3028, p->id);
            self->end--;
            if (p != 0) {
                p->vt[1].fn((char*)p + p->vt[1].delta, 3);
            }
        }
        func_003F0BE0(self->h);
        func_003F07A0(self->h);
        self->h = 0;
        self->cc = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002615C8);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;
extern "C" void* func_003F0C90(void* h, void* cb, void* user);
extern "C" void func_003EE5A0(void* h, int a, int b, void* cb);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern "C" void func_00268F68(void* self, void* a1, int a2);
extern "C" int func_002634C0(void* self, int a1, void* a, void* b);

struct sMsgListNode15C8 {
    sMsgListNode15C8* next;
    sMsgListNode15C8* prev;
    void* data;
};

struct sMsgListIter15C8 {
    sMsgListNode15C8* node;
    sMsgListIter15C8(sMsgListNode15C8* x) : node(x) {}
    sMsgListIter15C8(const sMsgListIter15C8& x) : node(x.node) {}
};

static inline sMsgListIter15C8 sMsgList15C8_insert(sMsgListIter15C8 pos, void* const& x)
{
    sMsgListNode15C8* tmp = (sMsgListNode15C8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_15C8(char* owner, void* msg)
{
    void* mp = msg;
    sMsgList15C8_insert(*(sMsgListNode15C8**)(owner + 0xF0), mp);
}

extern "C" void func_002615C8(char* self, int* msg)
{
    switch (msg[0]) {
    case 0x636F6E6E:
        {
            int s = msg[1];
            if (s == 2) {
                *(int*)(self + 0xDC) = 1;
                if (*(int*)(self + 0xD0) == 0)
                    *(int*)(self + 0xD0) = 1;
            } else if (s == 6) {
                *(int*)(self + 0xE8) = 0;
                *(int*)(self + 0xDC) = 1;
                if (*(int*)(self + 0xD0) == 0)
                    *(int*)(self + 0xD0) = 1;
            } else if (s == 4) {
                *(int*)(self + 0xDC) = 1;
                if (*(int*)(self + 0xD0) == 0)
                    *(int*)(self + 0xD0) = 1;
            } else if (s == 3) {
                *(int*)(self + 0xDC) = 1;
                if (*(int*)(self + 0xD0) == 0)
                    *(int*)(self + 0xD0) = 1;
            }
        }
        break;
    case 0x61757468:
        if (msg[2] == 0) {
            // PORT: function pointers passed as callbacks.
            *(void**)(self + 0xCC) = func_003F0C90(*(void**)(self + 0xC8), (void*)func_00268F68, self);
            func_003EE5A0(*(void**)(self + 0xCC), 0, 0, (void*)func_002634C0);
            func_00262768(self, 1, 0, 0, 0, 0);
            *(int*)(self + 0xD8) = 0;
            *(int*)(self + 0xE0) = 1;
        } else {
            char* owner = (char*)D_004A3028;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            *(void***)((char*)m + 0x4) = D_004812B0;
            m[0] = 0x104;
            post_15C8(owner, m);
            int r = msg[2];
            *(int*)(self + 0xDC) = 1;
            *(int*)(self + 0xD0) = r;
        }
        break;
    }
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_00261770);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002618C0);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;

struct sMsgListNode_002618C0 {
    sMsgListNode_002618C0* next;
    sMsgListNode_002618C0* prev;
    void* data;
};

struct sMsgListIter_002618C0 {
    sMsgListNode_002618C0* node;
    sMsgListIter_002618C0(sMsgListNode_002618C0* x) : node(x) {}
    sMsgListIter_002618C0(const sMsgListIter_002618C0& x) : node(x.node) {}
};

static inline sMsgListIter_002618C0 sMsgList_002618C0_insert(sMsgListIter_002618C0 pos, void* const& x)
{
    sMsgListNode_002618C0* tmp = (sMsgListNode_002618C0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_002618C0(int unused)
{
    char* g = (char*)D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    *(void***)((char*)m + 0x4) = D_004812B0;
    m[0] = 0x10A;
    void* mp = m;
    sMsgList_002618C0_insert(*(sMsgListNode_002618C0**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261970);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;

struct sMsgListNode_00261970 {
    sMsgListNode_00261970* next;
    sMsgListNode_00261970* prev;
    void* data;
};

struct sMsgListIter_00261970 {
    sMsgListNode_00261970* node;
    sMsgListIter_00261970(sMsgListNode_00261970* x) : node(x) {}
    sMsgListIter_00261970(const sMsgListIter_00261970& x) : node(x.node) {}
};

static inline sMsgListIter_00261970 sMsgList_00261970_insert(sMsgListIter_00261970 pos, void* const& x)
{
    sMsgListNode_00261970* tmp = (sMsgListNode_00261970*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00261970 {
    int kind;
    void** vt;
};

extern "C" void func_00261970(int unused)
{
    char* g = (char*)D_004A3028;
    sMsg_00261970* m = (sMsg_00261970*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m->vt = D_004812B0;
    m->kind = 0x10B;
    void* mp = m;
    sMsgList_00261970_insert(*(sMsgListNode_00261970**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261A20__FPv);
#ifdef SKIP_ASM
void func_00261A20(void* self)
{
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_00261A28);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261CD0);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern char D_00480E98[];
extern void* D_0046D8C0[];
extern void* D_004A3028;
extern "C" int func_00262360(void* self, int a1);
extern "C" int func_002623B0(void* self, int a1);
extern "C" int func_00262438(void* self, int a1);
extern "C" int func_00262400(void* self, int a1);
extern "C" int func_00262598(void* self);
extern "C" void func_00262EC0(char* self, int idx);
extern "C" int func_002620D8(char* self, char* name, int kind, int* err, char* other);
struct sPtrVec7128;
extern "C" void func_00267128(sPtrVec7128* self, void** pos, void* const& x);

struct sPtrVec1CD0 {
    void* alloc;
    void** start;
    void** finish;
    void** eos;
};

struct sOwner1CD0 {
    char pad[0xA8];
    sPtrVec1CD0 vec;    // 0xA8
};

static inline void sPtrVec1CD0_construct(void** p, void* const& v)
{
    if (p != 0)
        *p = v;
}

static inline void sOwner1CD0_push_back(sOwner1CD0* s, void* const& x)
{
    sPtrVec1CD0* v = &s->vec;
    if (s->vec.finish != s->vec.eos) {
        sPtrVec1CD0_construct(v->finish, x);
        ++s->vec.finish;
    } else {
        func_00267128((sPtrVec7128*)v, s->vec.finish, x);
    }
}

struct sMsgListNode1CD0 {
    sMsgListNode1CD0* next;
    sMsgListNode1CD0* prev;
    void* data;
};

struct sMsgListIter1CD0 {
    sMsgListNode1CD0* node;
    sMsgListIter1CD0(sMsgListNode1CD0* x) : node(x) {}
    sMsgListIter1CD0(const sMsgListIter1CD0& x) : node(x.node) {}
};

static inline sMsgListIter1CD0 sMsgList1CD0_insert(sMsgListIter1CD0 pos, void* const& x)
{
    sMsgListNode1CD0* tmp = (sMsgListNode1CD0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_1CD0(char* owner, void* msg)
{
    void* mp = msg;
    sMsgList1CD0_insert(*(sMsgListNode1CD0**)(owner + 0xF0), mp);
}

// PORT: name pointers passed through int parameters of some callees.
extern "C" void func_00261CD0(char* self, char* name, char* a2, char* a3)
{
    if (func_00262360(self, (int)name) == 0
        && func_002623B0(self, (int)name) == 0
        && func_00262438(self, (int)name) == 0) {
        int err;
        func_002620D8(self, name, 2, &err, 0);
        if (err == 2) {
            for (int i = 0; i < func_00262598(self); i++) {
                if (func_00262400(self, i)) {
                    func_00262EC0(self, i);
                    break;
                }
            }
            func_002620D8(self, name, 2, &err, 0);
            int type = 0x108;
            char* owner = (char*)D_004A3028;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            m[0] = type;
            *(void***)((char*)m + 0x4) = D_004812B0;
            post_1CD0(owner, m);
        }
    }
    char* obj = (char*)cMemMan_alloc(0x10, D_00480E98, 0x20000000, 0);
    *(void***)(obj + 0xC) = D_0046D8C0;
    cBXString_cBXString2(obj, name);
    cBXString_cBXString2(obj + 4, a2);
    cBXString_cBXString2(obj + 8, a3);
    void* o = obj;
    sOwner1CD0_push_back((sOwner1CD0*)self, o);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00261EF8);
#ifdef SKIP_ASM
extern "C" void* func_003F14D8(void* h);
extern "C" int func_002620D8(char* self, char* name, int kind, int* err, char* other);
extern "C" void func_00263018(void* self, void* name);
extern "C" int func_00263128(char* self, char* name);
extern "C" void func_003F11F8(void* h, void* e, void* cb, void* user, int timeout);
extern "C" void func_00268F90(void* self, void* a1, int a2);

// PORT: the unit declares (void*, int, int, void*); a1 carries the name pointer.
extern "C" void func_00261EF8(void* self_, int a1, int kind, void* out)
{
    char* self = (char*)self_;
    char* name = (char*)a1;
    int* err = (int*)out;
    char* e = (char*)func_003F14D8(*(void**)(self + 0xC8));
    if (e == 0) {
        func_002620D8(self, name, kind, err, 0);
        if (*err == 0)
            *err = 0;
        return;
    }
    int flags = *(int*)(e + 0xA8);
    // PORT: function pointer passed as a callback argument.
    func_003F11F8(*(void**)(self + 0xC8), e, (void*)func_00268F90, self, 600);
    int has = func_00263128(self, name);
    switch (kind) {
    case 0:
        if (!(flags & 4)) {
            func_002620D8(self, name, 0, err, e);
            if (*err != 0) {
                if (flags & 0x100000) {
                    int tmp;
                    func_002620D8(self, name, 2, &tmp, e);
                }
                return;
            }
            if (flags & 0x100000)
                has = 0;
        }
        break;
    case 1:
        if (flags & 0x200)
            goto do2;
        func_002620D8(self, name, 1, err, e);
        if (*err != 0) {
            if (has)
                func_00263018(self, name);
            return;
        }
        break;
    case 2:
        if (!(flags & 0x100000)) {
        do2:
            func_002620D8(self, name, 2, err, e);
            if (*err != 0)
                return;
        }
        break;
    }
    if (has)
        func_00263018(self, name);
    *err = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002620D8);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" int func_00262280(void* self);
extern "C" int func_002622F0(void* self);
extern "C" int func_003F0E38(void* h, void* rec, void* cb, void* user, int timeout);
extern "C" void func_00268FB8(void* self, void* a1, int a2);

struct sTagsUnkReq20D8 {
    char name[0x20];   // 0x00
    char x20[0x20];    // 0x20
    char x40[0x68];    // 0x40
    int flags;         // 0xA8
    char pad[0x14];
};

extern "C" int func_002620D8(char* self, char* name, int kind, int* err, char* other)
{
    sTagsUnkReq20D8 rec;
    if (func_0041AA88(*(void**)((char*)D_004A3028 + 0x80), name) == 0) {
        *err = 3;
        return 0;
    }
    int a = 0;
    int b = 0;
    if (other == 0) {
        a = 1;
        b = 1;
    } else if (*(int*)(other + 0xA8) & 0x100000) {
        a = 1;
    } else {
        b = 1;
    }
    strcpy(rec.name, name);
    strcpy(rec.x40, *(char**)(self + 0xEC));
    rec.x20[0] = 0;
    switch (kind) {
    case 0:
        if (func_00262280(self) + a >= 0x29) {
            *err = 1;
            return 0;
        }
        rec.flags |= 4;
        break;
    case 1:
        if (func_00262280(self) + a >= 0x29) {
            *err = 1;
            return 0;
        }
        rec.flags |= 0x200;
        break;
    case 2:
        if (func_002622F0(self) + b >= 0xB) {
            *err = 2;
            return 0;
        }
        rec.flags |= 0x100000;
        rec.flags |= 0x800000;
        break;
    }
    *err = 0;
    // PORT: function pointer passed as a callback argument.
    return func_003F0E38(*(void**)(self + 0xC8), &rec, (void*)func_00268FB8, self, 600);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262280);
#ifdef SKIP_ASM
extern "C" int func_00262400(void* self, int a1);
extern "C" int func_00262598(void* self);

extern "C" int func_00262280(void* self)
{
    int n = 0;
    for (int i = 0; i < func_00262598(self); i++) {
        if (func_00262400(self, i) == 0)
            n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002622F0);
#ifdef SKIP_ASM
extern "C" int func_00262400(void* self, int a1);
extern "C" int func_00262598(void* self);

extern "C" int func_002622F0(void* self)
{
    int n = 0;
    for (int i = 0; i < func_00262598(self); i++) {
        if (func_00262400(self, i) != 0)
            n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262360);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
// PORT: the unit declares func_00262390 as `int (void*)`; this caller passes a
// second argument (it reaches func_00262620's callee in $a1). Bound by asm label.
int func_00262390_2(void* self, int a1) __asm__("func_00262390__FPv");

extern "C" int func_00262360(void* self, int a1)
{
    return func_00262390_2(self, func_00262468(self, a1));
}
#endif

extern "C" void* func_00262620(void* self);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262390__FPv);
#ifdef SKIP_ASM
int func_00262390(void* self)
{
    return (func_00262620(self) != 0);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002623B0);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
// PORT: the unit declares func_002623E0 as `int (void*)`; this caller passes a
// second argument (it reaches func_00262658's callee in $a1). Bound by asm label.
int func_002623E0_2(void* self, int a1) __asm__("func_002623E0__FPv");

extern "C" int func_002623B0(void* self, int a1)
{
    return func_002623E0_2(self, func_00262468(self, a1));
}
#endif

extern "C" void* func_00262658(void* self);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002623E0__FPv);
#ifdef SKIP_ASM
int func_002623E0(void* self)
{
    return (func_00262658(self) != 0);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262400);
#ifdef SKIP_ASM
extern "C" void* func_002625C8(void* self, int idx);

extern "C" int func_00262400(void* self, int a1)
{
    void* p = func_002625C8(self, a1);
    if (p != 0) {
        return (*(int*)((char*)p + 0xA8) >> 20) & 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262438);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
extern "C" int func_00262400(void* self, int a1);

extern "C" int func_00262438(void* self, int a1)
{
    return func_00262400(self, func_00262468(self, a1));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262468);
#ifdef SKIP_ASM
extern "C" int func_004165A8(void*, void*);
extern "C" void* func_002625C8(void* self, int idx);

// PORT: a1 carries a name pointer in an int (the unit's declaration).
extern "C" int func_00262468(void* self, int a1)
{
    int i;
    int n = func_00262598(self);
    for (i = 0; i < n; i++) {
        void* e = func_002625C8(self, i);
        if (e != 0 && func_004165A8(e, (void*)a1) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002624F8);
#ifdef SKIP_ASM
extern "C" void* func_002625C8(void* self, int idx);

extern "C" int func_002624F8(void* self, void** key)
{
    int i;
    int n;
    if (key == 0) {
        return -1;
    }
    n = func_00262598(self);
    for (i = 0; i < n; i++) {
        void* e = func_002625C8(self, i);
        if (e != 0 && func_0041AA88(*key, e) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262598);
#ifdef SKIP_ASM
extern "C" int func_003EE550(void*);

extern "C" int func_00262598(void* self)
{
    void* p = *(void**)((char*)self + 0xCC);
    if (p == 0) {
        return 0;
    }
    return func_003EE550(p);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002625C8);
#ifdef SKIP_ASM
extern "C" int func_00262598(void* self);
// PORT: the unit declares func_003EE560 with one parameter; this caller passes (list, index).
void* func_003EE560_2(void* list, int idx) __asm__("func_003EE560");

extern "C" void* func_002625C8(void* self, int idx)
{
    void* r;
    if (idx < 0 || func_00262598(self) < idx) {
        r = 0;
    } else {
        r = func_003EE560_2(*(void**)((char*)self + 0xCC), idx);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262620);
#ifdef SKIP_ASM
extern "C" void* func_002625C8(void* self, int idx);
// PORT: the unit declares func_00262620 as `void* (void*)`; the body passes a second
// argument through to func_002625C8 in $a1. Bound by asm label.
void* func_00262620_2(void* self, int idx) __asm__("func_00262620");

void* func_00262620_2(void* self, int idx)
{
    void* p = func_002625C8(self, idx);
    if ((p != 0) && (*(int*)((char*)p + 0xA8) & 0x4)) {
        return p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262658);
#ifdef SKIP_ASM
extern "C" void* func_002625C8(void* self, int idx);
// PORT: the unit declares func_00262658 as `void* (void*)`; the body passes a second
// argument through to func_002625C8 in $a1. Bound by asm label.
void* func_00262658_2(void* self, int idx) __asm__("func_00262658");

void* func_00262658_2(void* self, int idx)
{
    void* p = func_002625C8(self, idx);
    if ((p != 0) && (*(int*)((char*)p + 0xA8) & 0x200)) {
        return p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262690);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern char D_004A3358[];
extern char D_004A3360[];
extern char D_004A3368[];
extern char D_004A3370[];
extern char D_004A3390[];
extern char D_004A3398[];
extern "C" void func_00268FE0(void* self, void* a1, int a2);
extern "C" int func_003F16D8(void* ctx, char* buf, void* cb, void* user, int a4);

extern "C" void func_00262690(char* self, const char* name, int a2)
{
    char buf[0x1000];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x1000, D_004A3358, D_004A3390);
    cDirtysock_tag_TagFieldSetString(buf, 0x1000, D_004A3368, D_004A2F40);
    cDirtysock_tag_TagFieldSetString(buf, 0x1000, D_004A3360, name);
    cDirtysock_tag_TagFieldSetUnk(buf, 0x1000, D_004A3370, a2);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x1000, D_004A3398, *(int*)(self + 0xA4));
    func_003F16D8(*(void**)(self + 0xC8), buf, (void*)func_00268FE0, self, *(int*)(self + 0xA4));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262768);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* buf, int size, const char* key, int value);
extern "C" int cDirtysock_tag_TagFieldSetString(char* buf, int size, const char* key, const char* value);
extern "C" int func_002628C0(void* self, int sel);
extern "C" void func_003F1538(void* p);
extern "C" void func_003F1548(void* p, char* buf);
extern "C" void func_003F1578(void* p, const char* a, const char* b);
extern "C" int func_003F15C8(void* p, const char* name, int a2, int a3);
extern char D_004A31F8[];
extern char D_004A33A8[];
extern char D_004A33B0[];
extern char D_004A33B8[];
extern char D_004A33C0[];
extern char D_004A33C8[];
extern char D_00480EA8[];
extern char D_004A2F18[];

// PORT: the unit declares every argument as int; a3..a5 are really string pointers.
extern "C" void func_00262768(void* self_, int a1, int a2, int a3, int a4, int a5)
{
    char* self = (char*)self_;
    if (*(void**)(self + 0xC8) == 0)
        return;
    char buf[0x50];
    buf[0] = 0;
    cDirtysock_tag_TagFieldSetString(buf, 0x50, D_004A31F8, *(const char**)(self + 0xEC));
    cDirtysock_tag_TagFieldSetNumber(buf, 0x50, D_004A33A8, 3);
    cDirtysock_tag_TagFieldSetNumber(buf, 0x50, D_004A33B0, a2);
    if (a3 != 0)
    {
        cDirtysock_tag_TagFieldSetString(buf, 0x50, D_004A33B8, (const char*)a3);
        if (a4 != 0)
        {
            cDirtysock_tag_TagFieldSetString(buf, 0x50, D_004A33C0, (const char*)a4);
            if (a5 != 0)
                cDirtysock_tag_TagFieldSetString(buf, 0x50, D_004A33C8, (const char*)a5);
        }
    }
    func_003F1538(*(void**)(self + 0xC8));
    func_003F1548(*(void**)(self + 0xC8), buf);
    func_003F1578(*(void**)(self + 0xC8), D_00480EA8, D_004A2F18);
    const char* name = *(const char**)(self + 0xEC);
    func_003F15C8(*(void**)(self + 0xC8), name, func_002628C0(self, a1), 0x7D0);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002628C0);
#ifdef SKIP_ASM
extern "C" int func_002628C0(void* self, int sel)
{
    if (*(int*)((char*)self + 0xC8) == 0) {
        return -1;
    }
    switch (sel) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262938);
#ifdef SKIP_ASM
extern "C" int func_00262938(void* self)
{
    return (*(int*)((char*)self + 0xb0) - *(int*)((char*)self + 0xac)) >> 2;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262950);
#ifdef SKIP_ASM
extern "C" void* func_00263630(void* self, unsigned int i);
extern "C" int func_004165A8(void*, void*);

static inline unsigned int sDsListK2_size(void* self)
{
    return *(void***)((char*)self + 0xB0) - *(void***)((char*)self + 0xAC);
}

// Counts the entries whose name matches entry `idx`'s name.
extern "C" int func_00262950(void* self, int idx)
{
    void* key = func_002625C8(self, idx);
    if (key == 0)
        return -1;
    int count = 0;
    unsigned int i;
    for (i = 0; i < sDsListK2_size(self); i++) {
        void** e = (void**)func_00263630(self, i);
        if (e != 0) {
            if (func_004165A8(*e, key) == 0)
                count++;
        }
    }
    return count;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_00262A08);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
extern "C" int func_00262950(void* self, int a1);

extern "C" int func_00262A08(void* self, int a1)
{
    return func_00262950(self, func_00262468(self, a1));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262A38);
#ifdef SKIP_ASM
extern "C" int func_004165A8(void*, void*);

extern "C" int func_00262A38(void* self, void* name)
{
    for (void*** it = *(void****)((char*)self + 0xAC); it != *(void****)((char*)self + 0xB0); it++) {
        if (func_004165A8(**it, name) == 0)
            return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262AB0);
#ifdef SKIP_ASM
extern "C" int func_00262AB0(void* self, void** arg1)
{
    void*** p = *(void****)((char*)self + 0xAC);
    if (p != *(void****)((char*)self + 0xB0)) {
        func_004165A8(**p, *arg1);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262AF0);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" int func_002620D8(char* self, char* name, int kind, int* err, char* other);
int func_002623E0_2(void* self, int a1) __asm__("func_002623E0__FPv");
extern "C" int func_00262400(void* self, int a1);
extern "C" int func_00262468(void* self, int a1);
extern "C" int func_00262598(void* self);
extern "C" void func_00262EC0(char* self, int idx);
extern "C" void func_00263018(void* self, void* name);
extern "C" int func_00263128(char* self, char* name);
extern "C" void* func_0041AA88(void*, void*);
struct sPtrVec72C8;
extern "C" void func_002672C8(sPtrVec72C8* self, void** pos, void* const& x);
extern char D_00480488[];
extern char D_004804A8[];
extern char D_00480EC0[];
extern char D_004810E0[];
extern void* D_004812B0[];
extern void* D_004A3028;

struct sMsgListNode_262AF0 {
    sMsgListNode_262AF0* next;
    sMsgListNode_262AF0* prev;
    void* data;
};

struct sMsgListIter_262AF0 {
    sMsgListNode_262AF0* node;
    sMsgListIter_262AF0(sMsgListNode_262AF0* x) : node(x) {}
    sMsgListIter_262AF0(const sMsgListIter_262AF0& x) : node(x.node) {}
};

static inline sMsgListIter_262AF0 sMsgList_262AF0_insert(sMsgListIter_262AF0 pos, void* const& x)
{
    sMsgListNode_262AF0* tmp = (sMsgListNode_262AF0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_262AF0(char* owner, void* msg)
{
    void* mp = msg;
    sMsgList_262AF0_insert(*(sMsgListNode_262AF0**)(owner + 0xF0), mp);
}

struct sObjVec_262AF0 {
    void* alloc;
    void** start;
    void** finish;
    void** eos;
};

static inline void construct_262AF0(void** p, void* const& x)
{
    if (p != 0)
        *p = x;
}

static inline void push_back_262AF0(char* o, sObjVec_262AF0* v, void* const& x)
{
    if (*(void***)(o + 0xC0) != *(void***)(o + 0xC4))
    {
        construct_262AF0(v->finish, x);
        ++*(void***)(o + 0xC0);
    }
    else
    {
        func_002672C8((sPtrVec72C8*)v, *(void***)(o + 0xC0), x);
    }
}

extern "C" void func_00262AF0(char* self, char* name, int a2, int a3, int a4, int a5, int a6, int a7,
                              int s0, int s1, char* s2, int s3, int s4, int s5, int s6)
{
    if (func_0041AA88(*(void**)((char*)D_004A3028 + 0x80), name) == 0)
        return;
    while (func_00263128(self, name))
        func_00263018(self, name);
    int idx = func_00262468(self, (int)name);
    if (idx < 0)
    {
        int err;
        func_002620D8(self, name, 2, &err, 0);
        if (err == 2)
        {
            int i;
            for (i = 0; i < func_00262598(self); i++)
            {
                if (func_00262400(self, i))
                {
                    func_00262EC0(self, i);
                    break;
                }
            }
            int type = 0x108;
            func_002620D8(self, name, 2, &err, 0);
            char* g = (char*)D_004A3028;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            m[0] = type;
            *(void***)((char*)m + 0x4) = D_004812B0;
            post_262AF0(g, m);
        }
    }
    else if (func_002623E0_2(self, idx))
    {
        return;
    }
    char* obj = (char*)operator new(0x40, D_00480EC0, 0x20000000, 0);
    *(char**)(obj + 0x3C) = D_004810E0;
    cBXString_cBXString2(obj, name);
    cBXString_cBXString2(obj + 4, s2);
    *(int*)(obj + 0x8) = a2;
    *(int*)(obj + 0xC) = a3;
    *(int*)(obj + 0x10) = a4;
    *(int*)(obj + 0x14) = a5;
    *(int*)(obj + 0x18) = a6;
    *(int*)(obj + 0x1C) = a7;
    *(int*)(obj + 0x20) = s0;
    *(int*)(obj + 0x24) = s1;
    *(int*)(obj + 0x2C) = s3;
    *(int*)(obj + 0x30) = s4;
    *(int*)(obj + 0x34) = s5;
    *(int*)(obj + 0x28) = s6;
    void* op = obj;
    push_back_262AF0(self, (sObjVec_262AF0*)(self + 0xB8), op);
    char* g = (char*)D_004A3028;
    int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
    *(void***)((char*)m + 0x4) = D_004812B0;
    m[0] = 0xEC;
    post_262AF0(g, m);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262E20);
#ifdef SKIP_ASM
static inline unsigned int func_00262E20_count(void* self)
{
    return *(void***)((char*)self + 0xC0) - *(void***)((char*)self + 0xBC);
}

static inline void** func_00262E20_at(void* self, unsigned int i)
{
    return *(void***)((char*)*(void***)((char*)self + 0xBC) + (i << 2));
}

extern "C" int func_00262E20(void* self, void* name)
{
    for (unsigned int i = 0; i < func_00262E20_count(self); i++) {
        void** e = func_00262E20_at(self, i);
        if (e != 0 && func_0041AA88(*e, name) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00262EC0);
#ifdef SKIP_ASM
extern void* D_004A3028;
// PORT: callee defined as returning void* in this unit; called here as void.
void func_0025FC28_v(void* self, int a1) __asm__("func_0025FC28__FPvi");
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" int func_00262400(void* self, int a1);
extern "C" void* func_002625C8(void* self, int idx);
extern "C" int func_00262938(void* self);
extern "C" int func_00262A38(void* self, void* name);
extern "C" int func_00262E20(void* self, void* name);
extern "C" int func_00263128(char* self, char* name);
extern "C" void func_002635A8(void* self, int i);
extern "C" void* func_00263630(void* self, unsigned int i);
extern "C" void func_003F11F8(void* h, void* e, void* cb, void* user, int timeout);
extern "C" void* func_0041610C(void* dst, const void* src, unsigned int n);
extern "C" void* func_0041AA88(void*, void*);
extern "C" void func_00268F90(void* self, void* a1, int a2);

struct sBXStr_262EC0 {
    char* p;
};

struct sObjVec_262EC0 {
    void* alloc;
    void** mStart;
    void** mFinish;
};

static inline void** sObjVec_262EC0_copy(void** first, void** last, void** result)
{
    func_0041610C(result, first, (last - first) * sizeof(void*));
    return result + (last - first);
}

extern "C" void func_00262EC0(char* self, int idx)
{
    if (func_00262400(self, idx) == 0)
        return;
    char* name = (char*)func_002625C8(self, idx);
    if (name == 0)
        return;
    sBXStr_262EC0 s;
    cBXString_cBXString2(&s, name);
    func_003F11F8(*(void**)(self + 0xC8), name, (void*)func_00268F90, self, 600);
    if (func_00262A38(self, s.p))
    {
        for (int i = func_00262938(self) - 1; i >= 0; i--)
        {
            void** e = (void**)func_00263630(self, i);
            if (e != 0 && func_0041AA88(*e, s.p) == 0)
                func_002635A8(self, i);
        }
    }
    if (func_00263128(self, s.p))
    {
        // PORT: the name is passed through an int parameter.
        func_0025FC28_v(D_004A3028, (int)s.p);
        int k = func_00262E20(self, s.p);
        sObjVec_262EC0* v = (sObjVec_262EC0*)(self + 0xB8);
        // PORT: pointer arithmetic through int.
        void** pos = (void**)(k * 4 + (int)*(void***)(self + 0xBC));
        if (pos + 1 != *(void***)(self + 0xC0))
            sObjVec_262EC0_copy(pos + 1, v->mFinish, pos);
        --*(void***)(self + 0xC0);
    }
    cBXString__cBXString(&s, 2);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263018);
#ifdef SKIP_ASM
extern void* D_004A3028;
// PORT: callee defined as returning void* in this unit; called here as void.
void func_0025FC28_v(void* self, int a1) __asm__("func_0025FC28__FPvi");
extern "C" void* func_0041610C(void* dst, const void* src, unsigned int n);
extern "C" int func_00262438(void* self, int a1);
extern "C" int func_00262A38(void* self, void* name);
extern "C" int func_00262468(void* self, int a1);
extern "C" void* func_002625C8(void* self, int idx);
extern "C" void func_003F11F8(void* h, void* e, void* cb, void* user, int timeout);
extern "C" void func_00268F90(void* self, void* a1, int a2);

struct sTagsUnkVEntry18 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sTagsUnkObjVec18 {
    void* alloc;
    void** mStart;
    void** mFinish;
};

static inline void** sTagsUnkObjVec18_copy(void** first, void** last, void** result)
{
    func_0041610C(result, first, (last - first) * sizeof(void*));
    return result + (last - first);
}

// PORT: the name is passed through int parameters of some callees.
extern "C" void func_00263018(void* self, void* name)
{
    int idx = func_00262E20(self, name);
    if (idx >= 0) {
        func_0025FC28_v(D_004A3028, (int)name);
        sTagsUnkObjVec18* v = (sTagsUnkObjVec18*)((char*)self + 0xB8);
        void** pos = *(void***)((char*)self + 0xBC) + idx;
        char* obj = (char*)*pos;
        if (pos + 1 != *(void***)((char*)self + 0xC0)) {
            sTagsUnkObjVec18_copy(pos + 1, v->mFinish, pos);
        }
        --*(void***)((char*)self + 0xC0);
        if (obj != 0) {
            sTagsUnkVEntry18* vt = *(sTagsUnkVEntry18**)(obj + 0x3C);
            vt[1].fn(obj + vt[1].delta, 3);
        }
        if (func_00262438(self, (int)name)) {
            if (func_00262A38(self, name) == 0) {
                void* e = func_002625C8(self, func_00262468(self, (int)name));
                if (e != 0) {
                    // PORT: function pointer passed as a callback argument.
                    func_003F11F8(*(void**)((char*)self + 0xC8), e, (void*)func_00268F90, self, 600);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263128);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern "C" int func_004165A8(void*, void*);

// Returns 1 if any entry's name equals `name`.
extern "C" int func_00263128(char* self, char* name)
{
    if ((*(void****)(self + 0xC0) - *(void****)(self + 0xBC)) == 0)
        return 0;
    for (void*** it = *(void****)(self + 0xBC); it != *(void****)(self + 0xC0); it++) {
        void** e = *it;
        char* tmp;
        cBXString_cBXString2(&tmp, name);
        if (func_004165A8(*e, name) == 0) {
            cBXString__cBXString(&tmp, 2);
            return 1;
        }
        cBXString__cBXString(&tmp, 2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002631E0);
#ifdef SKIP_ASM
extern "C" int func_002631E0(void* self, void** name)
{
    if ((unsigned int)(*(void***)((char*)self + 0xC0) - *(void***)((char*)self + 0xBC)) == 0) {
        return 0;
    }
    for (void** it = *(void***)((char*)self + 0xBC); it != *(void***)((char*)self + 0xC0); it++) {
        void* e = *it;
        if (func_004165A8(*(void**)e, *name) == 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263270);
#ifdef SKIP_ASM
extern "C" void* func_00263270(void* self, void* name)
{
    if ((unsigned int)(*(void***)((char*)self + 0xC0) - *(void***)((char*)self + 0xBC)) == 0) {
        return 0;
    }
    for (void** it = *(void***)((char*)self + 0xBC); it != *(void***)((char*)self + 0xC0); it++) {
        void* e = *it;
        if (func_004165A8(*(void**)e, name) == 0) {
            return e;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263308);
#ifdef SKIP_ASM
extern "C" void* func_00263308(void* self, unsigned int i)
{
    void** begin = *(void***)((char*)self + 0xBC);
    void** end = *(void***)((char*)self + 0xC0);
    if (i >= (unsigned int)(end - begin)) {
        return 0;
    }
    return *(void**)((char*)begin + (i << 2));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263338);
#ifdef SKIP_ASM
// PORT: the target calls func_00262598 without setting $4 (self is still there from entry);
// bound here with a no-arg prototype.
extern "C" int func_00262598_noarg() __asm__("func_00262598");

extern "C" int func_00263338(void* self, int idx)
{
    if (idx < 0) {
        return 0;
    }
    if (func_00262598_noarg() < idx) {
        return 0;
    }
    char* e = (char*)func_002625C8(self, idx);
    if (e == 0) {
        return 0;
    }
    int r = 0;
    if ((*(unsigned char*)(e + 0xA7) & 1) || (*(unsigned int*)(e + 0xA8) & 0x100000)) {
        r = 1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_002633C8);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
extern "C" int func_00263338(void* self, int a1);

extern "C" int func_002633C8(void* self, int a1)
{
    return func_00263338(self, func_00262468(self, a1));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002633F8);
#ifdef SKIP_ASM
extern char D_004A2F40[];
extern char D_004A31F8[];
extern "C" const char* cDirtysock_tag_TagFieldFind(const char* record, const char* name);
// PORT: the target calls func_00262598 without setting $4 (self is still there from entry);
// bound here with a no-arg prototype.
extern "C" int func_00262598_noarg() __asm__("func_00262598");
// PORT: TagFieldGetString really takes a 4th (default value) argument; the unit declares 3.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* tag, char* buf, int size, const char* defval);

extern "C" int func_002633F8(void* self, int idx)
{
    if (idx < 0) {
        return 0;
    }
    if (func_00262598_noarg() < idx) {
        return 0;
    }
    char* e = (char*)func_002625C8(self, idx);
    if (e == 0) {
        return 0;
    }
    char buf[16];
    cDirtysock_tag_TagFieldGetString(cDirtysock_tag_TagFieldFind(e + 0x54, D_004A31F8), buf, 0x10, D_004A2F40);
    return func_004165A8(*(void**)((char*)self + 0xEC), buf) == 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_00263490);
#ifdef SKIP_ASM
extern "C" int func_00262468(void* self, int a1);
extern "C" int func_002633F8(void* self, int a1);

extern "C" int func_00263490(void* self, int a1)
{
    return func_002633F8(self, func_00262468(self, a1));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002634C0);
#ifdef SKIP_ASM
extern "C" int func_002634C0(void* self, int a1, void* a, void* b)
{
    if (a == 0) {
        return b != 0;
    }
    if (b == 0) {
        return -1;
    }
    // PORT: func_0041AA88 (strcmp-like) is declared void* in this unit but returns int
    return (int)func_0041AA88(a, b);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263500);
#ifdef SKIP_ASM
extern "C" void func_00263500(char* self, void* obj)
{
    for (void** it = *(void***)(self + 0xB0); it != *(void***)(self + 0xAC); it--) {
        char* o = (char*)*it;
        if (o == obj) {
            sTagsUnkObjVec18* v = (sTagsUnkObjVec18*)(self + 0xA8);
            if (it + 1 != *(void***)(self + 0xB0)) {
                sTagsUnkObjVec18_copy(it + 1, v->mFinish, it);
            }
            --*(void***)(self + 0xB0);
            if (o != 0) {
                sTagsUnkVEntry18* vt = *(sTagsUnkVEntry18**)(o + 0xC);
                vt[1].fn(o + vt[1].delta, 3);
            }
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002635A8);
#ifdef SKIP_ASM
extern "C" void* func_0041610C(void* dst, const void* src, unsigned int n);

struct sTagsUnkVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sTagsUnkObjVec {
    void* alloc;
    void** mStart;
    void** mFinish;
};

static inline void** sTagsUnkObjVec_copy(void** first, void** last, void** result)
{
    func_0041610C(result, first, (last - first) * sizeof(void*));
    return result + (last - first);
}

extern "C" void func_002635A8(void* self, int idx)
{
    sTagsUnkObjVec* v = (sTagsUnkObjVec*)((char*)self + 0xA8);
    void** pos = *(void***)((char*)self + 0xAC) + idx;
    char* obj = (char*)*pos;
    if (pos + 1 != *(void***)((char*)self + 0xB0)) {
        sTagsUnkObjVec_copy(pos + 1, v->mFinish, pos);
    }
    --*(void***)((char*)self + 0xB0);
    if (obj != 0) {
        sTagsUnkVEntry* vt = *(sTagsUnkVEntry**)(obj + 0xC);
        vt[1].fn(obj + vt[1].delta, 3);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263630);
#ifdef SKIP_ASM
extern "C" void* func_00263630(void* self, unsigned int i)
{
    void** begin = *(void***)((char*)self + 0xAC);
    void** end = *(void***)((char*)self + 0xB0);
    if (i >= (unsigned int)(end - begin)) {
        return 0;
    }
    return *(void**)((char*)begin + (i << 2));
}
#endif

extern void* D_004810C8[];

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263660__FPv);
#ifdef SKIP_ASM
void* func_00263660(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0x8) = (int)(void*)D_004810C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263678);
#ifdef SKIP_ASM
extern void* D_004810C8[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00263678(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004810C8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002636A8);
#ifdef SKIP_ASM
extern void* D_004A2EB8;
extern float D_004A2F0C;
extern float D_004A2F10;
extern "C" void func_00255F50(void* p, int arg1);

extern "C" void func_002636A8(void* self, int arg1)
{
    func_00255F50(D_004A2EB8, arg1);
    float v;
    if (*(int*)((char*)D_004A2EB8 + 0x2C) != 0) {
        v = D_004A2F0C;
    } else {
        v = D_004A2F10;
    }
    *(float*)((char*)self + 0x4) = v;
    *(int*)self = 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002636F0);
#ifdef SKIP_ASM
extern char D_004804A8[];
extern char D_00480ED0[];
extern void* D_00481250[];
extern void* D_004A3328;
extern void* D_004A3028;
extern void* D_004A2EB8;
extern "C" void func_00260F80(void);
extern "C" int func_00261460(void* p);
extern "C" void func_002613C8(void* p);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* p);
extern "C" void func_00255FA0(void* p);
struct sMsgListNode36F0 {
    sMsgListNode36F0* next;
    sMsgListNode36F0* prev;
    void* data;
};

struct sMsgListIter36F0 {
    sMsgListNode36F0* node;
    sMsgListIter36F0(sMsgListNode36F0* x) : node(x) {}
    sMsgListIter36F0(const sMsgListIter36F0& x) : node(x.node) {}
};

static inline sMsgListIter36F0 sMsgList36F0_insert(sMsgListIter36F0 pos, void* const& x)
{
    sMsgListNode36F0* tmp = (sMsgListNode36F0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline bool isState_36F0(int st)
{
    return *(int*)((char*)D_004A2EB8 + 0x20) == st;
}

extern "C" void func_002636F0(int* out, int val)
{
    if (D_004A3328 == 0)
        func_00260F80();
    if (func_00261460(D_004A3328) == 0)
        func_002613C8(D_004A3328);
    if (D_004A3328 == 0)
        func_0025B800(D_004A3028);
    func_00261408(D_004A3328);
    func_0025B800(D_004A3028);
    if (!isState_36F0(1)) {
        func_00255FA0(D_004A2EB8);
        if (val != 0) {
            char* g = (char*)D_004A3028;
            int* m = (int*)operator new(0xC, D_00480ED0, 0x20000000, 0);
            m[0] = 0x116;
            *(void***)((char*)m + 0x4) = D_00481250;
            m[2] = val;
            void* mp = m;
            sMsgList36F0_insert(*(sMsgListNode36F0**)(g + 0xF0), mp);
        }
        *out = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263828);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004A3028;
extern void* D_004A2EB8;
extern void* D_004A28A8;
extern "C" void func_002636F0(int* out, int val);

static inline bool isState_3828(int st)
{
    return *(int*)((char*)D_004A2EB8 + 0x20) == st;
}
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNode3828 {
    sMsgListNode3828* next;
    sMsgListNode3828* prev;
    void* data;
};

struct sMsgListIter3828 {
    sMsgListNode3828* node;
    sMsgListIter3828(sMsgListNode3828* x) : node(x) {}
    sMsgListIter3828(const sMsgListIter3828& x) : node(x.node) {}
};

static inline sMsgListIter3828 sMsgList3828_insert(sMsgListIter3828 pos, void* const& x)
{
    sMsgListNode3828* tmp = (sMsgListNode3828*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_3828(char* self, void* msg)
{
    void* mp = msg;
    sMsgList3828_insert(*(sMsgListNode3828**)(self + 0xF0), mp);
}

struct sDsTimer_263828 {
    int state;
    float timer;
};

extern "C" void func_00263828(int* self)
{
    sDsTimer_263828* t = (sDsTimer_263828*)self;
    switch (t->state)
    {
    case 0:
        break;
    case 1:
        if (isState_3828(5)) {
            t->state = 2;
            char* g = (char*)D_004A3028;
            int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
            *(void***)((char*)m + 0x4) = D_004812B0;
            m[0] = 0x105;
            post_3828(g, m);
        } else if (isState_3828(6)) {
            func_002636F0(self, *(int*)((char*)D_004A2EB8 + 0x28));
        } else {
            int expired = t->timer < 0.0f;
            if (expired)
                func_002636F0(self, 0x2D3F3F3F);
            else
                t->timer -= *(float*)((char*)D_004A28A8 + 0x14);
        }
        break;
    case 2:
        if (isState_3828(6))
            func_002636F0(self, *(int*)((char*)D_004A2EB8 + 0x28));
        break;
    }
}
#endif

extern void* D_004810B0[];

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263998__FPv);
#ifdef SKIP_ASM
void* func_00263998(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 0x14) = (int)(void*)D_004810B0;
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002639B0);
#ifdef SKIP_ASM
extern void* D_004810B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_002639B0(void* self, int flags)
{
    *(void***)((char*)self + 0x14) = D_004810B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002639E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
void cBENewRaceInterface_setNumberHumans(void* self, int n);
extern "C" void func_001472C8(void* self, int a1, int a2);
extern "C" int cCommSystem_openDSockChannel(void* comm, const char* addr, unsigned short port, int a3);
extern "C" void func_00266D58(void* self, void* ip);
extern "C" void func_00266E30(void* self);
extern void* D_004A28A8;
extern void* D_004A2EB8;
extern void* D_004A33F4;
extern float D_004A2F14;
extern int D_00535610[];
extern char D_00480EE0[];

struct sVE_002639E0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sIf_002639E0 {
    char pad[0xC];
    sVE_002639E0* vt;
};

struct sNetCfg_002639E0 {
    int active;     // 0x0
    int f4;         // 0x4
    int chan;       // 0x8
    int port;       // 0xC
    float rate;     // 0x10
};

extern sNetCfg_002639E0 D_00534B30_002639E0[] __asm__("D_00534B30");

extern "C" void func_002639E0(int* self, unsigned int ip, int chan, int a3, int a4)
{
    char buf[256];
    int one = 1;
    self[3] = a4;
    sIf_002639E0* p = (sIf_002639E0*)cBE_getInterface_Fv(cBE_getBE(), 1);
    sIf_002639E0* q = (sIf_002639E0*)cBE_getInterface_Fv(cBE_getBE(), 0);
    cBENewRaceInterface_setNumberHumans(q, 2);
    q->vt[1].fn((char*)q + q->vt[1].delta);
    func_001472C8(p, 0, a3);
    func_001472C8(p, 1, 0);
    p->vt[1].fn((char*)p + p->vt[1].delta);
    sIf_002639E0* r = (sIf_002639E0*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    D_00534B30_002639E0[0].active = one;
    D_00534B30_002639E0[0].rate = 0.01666666753590107f;
    D_00534B30_002639E0[0].port = 0xE4A;
    D_00534B30_002639E0[0].chan = chan;
    r->vt[1].fn((char*)r + r->vt[1].delta);
    r->vt[1].fn((char*)r + r->vt[1].delta);
    self[2] = chan;
    sprintf(buf, D_00480EE0, ip >> 24, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    self[1] = cCommSystem_openDSockChannel(D_004A2EB8, buf, D_00534B30_002639E0[0].port, chan);
    cBE_getInterface_Fv(cBE_getBE(), 4);
    if ((D_00535610[0] >> 18) & 1) {
        func_00266D58(D_004A33F4, (void*)ip);
        func_00266E30(D_004A33F4);
    }
    *(float*)&self[4] = D_004A2F14;
    self[0] = one;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263BA8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" int func_003E8B10(void* p, int tag, void* cb, int a3, void* user);
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004A3028;
extern void* D_004A2EB8;
extern void* D_004A33CC;
extern void* D_004A33F4;
extern "C" int func_00255D38(void* comm, int chan);
extern "C" void func_00255CC8(void* comm, int chan);
extern "C" void func_00264098(void);
extern "C" void func_00266DF8(void* self);
extern "C" void func_00266E88(void* self);
extern "C" void func_0025F740(void* self, int type);
extern void* D_004812B0[];
extern void* D_00481290[];

struct sMsgListNode3BA8 {
    sMsgListNode3BA8* next;
    sMsgListNode3BA8* prev;
    void* data;
};

struct sMsgListIter3BA8 {
    sMsgListNode3BA8* node;
    sMsgListIter3BA8(sMsgListNode3BA8* x) : node(x) {}
    sMsgListIter3BA8(const sMsgListIter3BA8& x) : node(x.node) {}
};

static inline sMsgListIter3BA8 sMsgList3BA8_insert(sMsgListIter3BA8 pos, void* const& x)
{
    sMsgListNode3BA8* tmp = (sMsgListNode3BA8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

static inline void post_3BA8(char* self, void* msg)
{
    void* mp = msg;
    sMsgList3BA8_insert(*(sMsgListNode3BA8**)(self + 0xF0), mp);
}

extern "C" void func_00263BA8(void* p, int arg)
{
    int* self = (int*)p;
    if (self[0] != 0 && func_00255D38(D_004A2EB8, self[1]) != 0)
    {
        func_00255CC8(D_004A2EB8, self[1]);
        func_00266E88(D_004A33F4);
        func_00266DF8(D_004A33F4);
    }
    if (D_004A33CC != 0)
        func_00264098();
    func_0025F740(D_004A3028, 0);
    self[0] = 0;
    if (arg == 1) {
        char* g = (char*)D_004A3028;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        *(void***)((char*)m + 0x4) = D_004812B0;
        m[0] = 0x10C;
        post_3BA8(g, m);
    } else if (arg == 0) {
        char* g = (char*)D_004A3028;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        *(void***)((char*)m + 0x4) = D_004812B0;
        m[0] = 0x112;
        post_3BA8(g, m);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00263CF0);
#ifdef SKIP_ASM
struct cAppMan;
void cAppMan_setNextModule(cAppMan* self, unsigned int module);
void* func_00232720(void* self);
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewPlayerInterface_setRiderCharID(void* iface, int rider, int ch);
extern "C" void cGameComm_construct(int a, int b);
extern "C" void func_0014EBF8(void* self, int a);
extern "C" int func_00255D50(void* comm, int chan);
extern "C" int func_00255E40(void* comm, int chan);
extern "C" void func_00256C50(void);
extern "C" void func_0025B800(void* self);
extern "C" void func_00260F80(void);
extern "C" void func_002613C8(void* p);
extern "C" int func_00261460(void* p);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern "C" void func_00263BA8(void* p, int arg);
extern "C" void func_00264030(int a1, int a2, int a3);
extern "C" void func_00264098(void);
extern "C" void func_002642B8(void* self);
// PORT: func_00264CB8 is defined with one parameter; this caller passes a second in $a1.
extern "C" void func_00264CB8(void* self, int a);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern void* D_004A28A8;
extern void* D_004A2EB8;
extern void* D_004A2EEC;
extern void* D_004A3028;
extern void* D_004A3328;
extern void* D_004A33CC;
extern int D_004A19C4;
extern int D_00534B34[];
extern int D_00534E58[];
extern char D_00480EF0[];

struct sVEntry_263CF0 { short delta; short index; void (*fn)(void*); };

static inline bool tsTimedOut_263CF0(int* self)
{
    return *(float*)(self + 4) < 0.0f;
}

static inline bool tsIsState_263CF0(int st)
{
    return *(int*)D_004A33CC == st;
}

static inline void* Mgr_263CF0()
{
    if (D_004A3328 == 0)
        func_00260F80();
    if (func_00261460(D_004A3328) == 0)
        func_002613C8(D_004A3328);
    if (D_004A3328 == 0)
        func_0025B800(D_004A3028);
    return D_004A3328;
}

extern "C" void func_00263CF0(int* self)
{
    switch (self[0])
    {
    case 0:
        break;
    case 1:
        if (func_00255D50(D_004A2EB8, self[1]))
        {
            if (self[3] != 0)
            {
                func_00263BA8(self, 1);
                return;
            }
            cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
            func_00264030(self[1], self[2], D_00534B34[0]);
            func_00264CB8(D_004A33CC, *(int*)((char*)D_004A3028 + 0x8C));
            self[0] = 2;
            return;
        }
        if (func_00255E40(D_004A2EB8, self[1]) || tsTimedOut_263CF0(self))
        {
            func_00263BA8(self, 0);
            return;
        }
        *(float*)(self + 4) = *(float*)(self + 4) - *(float*)((char*)D_004A28A8 + 0x14);
        return;
    case 2:
        if (func_00255E40(D_004A2EB8, self[1]))
        {
            if (!tsIsState_263CF0(0xB))
            {
                char* g = (char*)D_004A3028;
                int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
                *(void***)((char*)m + 0x4) = D_004812B0;
                m[0] = 0x113;
                post_3BA8(g, m);
            }
            func_00263BA8(self, 2);
            return;
        }
        {
            func_002642B8(D_004A33CC);
            int go = 0;
            int st = *(int*)D_004A33CC;
            if (st == 0xD)
                go = 1;
            else if (st == 0xB)
                func_00263BA8(self, 2);
            if (go == 0)
                return;
            func_00264098();
            func_0025B800(D_004A3028);
            D_004A19C4 = 0x34;
            func_00262768(Mgr_263CF0(), 1, 9, *(int*)((char*)D_004A3028 + 0x98), 0, 0);
            void* bi7 = cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
            char* bi1 = (char*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 1);
            cBENewPlayerInterface_setRiderCharID(bi1, 0, D_00534E58[0]);
            sVEntry_263CF0* vt = *(sVEntry_263CF0**)(bi1 + 0xC);
            vt[1].fn(bi1 + vt[1].delta);
            func_0014EBF8(bi7, 0);
            if (D_004A2EEC != 0)
                func_00256C50();
            cGameComm_construct(self[1], self[2]);
            cAppMan_setNextModule((cAppMan*)D_004A28A8, (unsigned int)func_00232720(cMemMan_alloc(8, D_00480EF0, 0x100, 0)));
            self[0] = 0;
        }
        return;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264030);
#ifdef SKIP_ASM
extern char D_00480F08[];
extern void* D_004A33CC;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002640C0(void* self, int a1, int a2, int a3);

extern "C" void func_00264030(int a1, int a2, int a3)
{
    D_004A33CC = func_002640C0(cMemMan_alloc(0x12C, D_00480F08, 0x20000000, 0), a1, a2, a3);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264098);
#ifdef SKIP_ASM
extern void* D_004A33CC;
extern "C" void func_00264138(void* self, int flags);

extern "C" void func_00264098(void)
{
    if (D_004A33CC != 0) {
        func_00264138(D_004A33CC, 3);
        D_004A33CC = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002640C0);
#ifdef SKIP_ASM
extern "C" void* func_003E6448(void* dst, int value, int size);

extern "C" void* func_002640C0(void* self, int a1, int a2, int a3)
{
    *(int*)((char*)self + 0x0) = 1;
    *(int*)((char*)self + 0x120) = a1;
    *(int*)((char*)self + 0x124) = a2;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x118) = 0;
    *(int*)((char*)self + 0x11C) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x128) = a3;
    func_003E6448((char*)self + 0x10, 0, 0x80);
    *(int*)((char*)self + 0x90) = 0;
    *(int*)((char*)self + 0x94) = 0;
    func_003E6448((char*)self + 0x98, 0, 0x80);
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264138);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_00264990(void* self, int* p);

struct sRing_264138
{
    int end;
    int head;
    int* q[32];
};

struct sRingOwner_264138
{
    int f0;
    int* f4;
    sRing_264138 a;     // 0x8
    sRing_264138 b;     // 0x90
};

static inline int* PeekA_264138(sRingOwner_264138* o)
{
    if (o->a.head < o->a.end)
        return o->a.q[o->a.head % 32];
    return 0;
}

static inline int* PopA_264138(sRingOwner_264138* o)
{
    int h = o->a.head++;
    return o->a.q[h % 32];
}

static inline int* PeekB_264138(sRingOwner_264138* o)
{
    if (o->b.head < o->b.end)
        return o->b.q[o->b.head % 32];
    return 0;
}

static inline int* PopB_264138(sRingOwner_264138* o)
{
    int h = o->b.head++;
    return o->b.q[h % 32];
}

extern "C" void func_00264138(void* self_, int flags)
{
    sRingOwner_264138* self = (sRingOwner_264138*)self_;
    if (self->f4 != 0)
        func_00264990(self, self->f4);
    while (PeekA_264138(self) != 0)
        func_00264990(self, PopA_264138(self));
    while (PeekB_264138(self) != 0)
        func_00264990(self, PopB_264138(self));
    self->f0 = 1;
    if (flags & 1)
        operator_delete((int*)self);
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_002642B8);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264960);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_004805A8[];

extern "C" void* func_00264960(void* self)
{
    return cMemMan_alloc(0xF0, D_004805A8, 0x20000000, 0);
}
#endif

void operator_delete(int*);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264990);
#ifdef SKIP_ASM
extern "C" void func_00264990(void* self, int* p)
{
    operator_delete(p);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002649B0);
#ifdef SKIP_ASM
extern "C" void func_00264A58(void* self);
extern "C" void func_003E6574(void* dst, const void* src, int n);

struct sDsPacketK2 {
    unsigned short kind;   // 0x0
    unsigned short size;   // 0x2 (including this 4-byte header)
    char data[1];          // 0x4
};

struct sDsPacketQueueK2 {
    int pad_0x0[2];
    int tail;                    // 0x8
    int head;                    // 0xC
    sDsPacketK2* slots[32];      // 0x10
};

// Pops the oldest queued packet into `dst`; returns its payload size (0 if empty).
extern "C" int func_002649B0(sDsPacketQueueK2* self, void* dst)
{
    func_00264A58(self);
    int head = self->head;
    if (head != self->tail) {
        self->head = head + 1;
        sDsPacketK2* p = self->slots[head % 32];
        int len = p->size - 4;
        func_003E6574(dst, p->data, len);
        func_00264990(self, (int*)p);
        return len;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264A58);
#ifdef SKIP_ASM
extern void* D_004A2EB8;
extern "C" int func_00255DC0(void* mgr, int idx, void* buf, int len);
// PORT: func_00264960 is defined as f(void); this caller passes self in $a0.
void* func_00264960(void* self);

struct sDsRecvQueue_00264A58 {
    int f0;                     // 0x0
    void* cur;                  // 0x4
    int tail;                   // 0x8
    int head;                   // 0xC
    void* slots[32];            // 0x10
    char pad_0x90[0x120 - 0x90];
    int chan;                   // 0x120
};

// Fills the 32-entry receive queue until it is full or no packet is pending.
extern "C" void func_00264A58(void* p)
{
    sDsRecvQueue_00264A58* self = (sDsRecvQueue_00264A58*)p;
    void* buf;
    while (self->cur != 0
           || (buf = func_00264960(self), self->cur = buf,
               func_00255DC0(D_004A2EB8, self->chan, buf, 0xF0) != 0))
    {
        bool full = self->tail - self->head >= 0x1F;
        if (full)
            return;
        self->slots[self->tail++ % 32] = self->cur;
        self->cur = 0;
    }
    operator_delete((int*)self->cur);
    self->cur = 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264B20);
#ifdef SKIP_ASM
extern void* D_004A2EB8;
extern "C" int func_00255E00(void* mgr, int idx, void* buf, int len);

struct sDsPacket_00264B20 {
    unsigned short kind;   // 0x0
    unsigned short size;   // 0x2 (including this 4-byte header)
};

struct sDsSendQueue_00264B20 {
    char pad_0x00[0x90];
    int tail;                          // 0x90
    int head;                          // 0x94
    sDsPacket_00264B20* slots[32];     // 0x98
    char pad_0x118[0x120 - 0x118];
    int chan;                          // 0x120
};

// Sends queued packets until the queue is empty or the channel refuses one.
extern "C" void func_00264B20(void* p)
{
    sDsSendQueue_00264B20* self = (sDsSendQueue_00264B20*)p;
    while (self->head != self->tail)
    {
        sDsPacket_00264B20* pkt;
        int head = self->head;
        if (head < self->tail)
            pkt = self->slots[head % 32];
        else
            pkt = 0;
        if (func_00255E00(D_004A2EB8, self->chan, pkt, pkt->size) == 0)
            return;
        self->head++;
        func_00264990(self, (int*)pkt);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264BE8);
#ifdef SKIP_ASM
extern void* D_004A2EB8;
extern "C" int func_00255E00(void* mgr, int idx, void* buf, int len);
extern "C" void func_00264B20(void* p);
// PORT: func_00264960 is defined as f(void); this caller passes self in $a0.
void* func_00264960(void* self);

struct sDsOutPacket_00264BE8 {
    unsigned char kind;     // 0x0
    unsigned char flags;    // 0x1
    unsigned short size;    // 0x2 (including this 4-byte header)
    char data[0xEC];        // 0x4
};

struct sDsSendQueue_00264BE8 {
    char pad_0x00[0x90];
    int tail;                          // 0x90
    int head;                          // 0x94
    void* slots[32];                   // 0x98
    char pad_0x118[0x120 - 0x118];
    int chan;                          // 0x120
};

// PORT: the unit declares func_00264BE8 as returning void (callers ignore the result); the body
// returns 1, so it is bound by asm label.
int func_00264BE8_impl(void* p, const void* src, int len) __asm__("func_00264BE8");

// Flushes the send queue, then sends `len` bytes now or queues a copy for later.
int func_00264BE8_impl(void* p, const void* src, int len)
{
    sDsSendQueue_00264BE8* self = (sDsSendQueue_00264BE8*)p;
    func_00264B20(self);
    sDsOutPacket_00264BE8 pkt;
    pkt.kind = 0;
    pkt.flags = 0;
    pkt.size = len + 4;
    func_003E6574(pkt.data, src, len);
    if (func_00255E00(D_004A2EB8, self->chan, &pkt, pkt.size) != 0)
        return 1;
    void* buf = func_00264960(self);
    func_003E6574(buf, &pkt, pkt.size);
    self->slots[self->tail++ % 32] = buf;
    return 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264CB8);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" void func_00264BE8(void* self, void* msg, int size);

struct sTagMsg264CB8 {
    int type;          // 0x0
    int state;         // 0x4
    unsigned int id;   // 0x8
    int pad[2];
};

extern "C" void func_00264CB8(void* self, int a)
{
    sTagMsg264CB8 msg;
    msg.state = *(int*)((char*)D_004A3028 + 0xB8);
    msg.type = 16;
    msg.id = 0;
    func_00264BE8(self, &msg, sizeof(msg));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264CF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00147448(void* self, int a1, int charID);
extern void* D_004A28A8;
extern int D_00534E58[];

struct sVE264CF0 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sIf264CF0 {
    char pad[0xC];
    sVE264CF0* vt;
};

extern "C" void func_00264CF0(void* self, int charID)
{
    sIf264CF0* p = (sIf264CF0*)cBE_getInterface_Fv(cBE_getBE(), 1);
    func_00147448(p, 0, charID);
    p->vt[1].fn((char*)p + p->vt[1].delta);
    sIf264CF0* q = (sIf264CF0*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    D_00534E58[0] = charID;
    q->vt[1].fn((char*)q + q->vt[1].delta);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264D80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00147448(void* self, int a1, int charID);
extern void* D_004A28A8;

struct sVE_00264D80 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sIf_00264D80 {
    char pad[0xC];
    sVE_00264D80* vt;
};

struct sName7_00264D80 {
    char c[7];
};

struct sNetState_00264D80 {
    char pad_0x000[0x32C];
    int charID;                     // 0x32C
    char pad_0x330[0x4A8 - 0x330];
    sName7_00264D80 name;           // 0x4A8
};

extern sNetState_00264D80 D_00534B30_00264D80[] __asm__("D_00534B30");

extern "C" void func_00264D80(void* self, int charID, sName7_00264D80* name)
{
    sIf_00264D80* p = (sIf_00264D80*)cBE_getInterface_Fv(cBE_getBE(), 1);
    func_00147448(p, 1, charID);
    p->vt[1].fn((char*)p + p->vt[1].delta);
    sIf_00264D80* q = (sIf_00264D80*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    D_00534B30_00264D80[0].charID = charID;
    if (name != 0)
        D_00534B30_00264D80[0].name = *name;
    q->vt[1].fn((char*)q + q->vt[1].delta);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00264E50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00264BE8(void* self, void* msg, int size);
extern "C" int func_00148BC8(void* iface, int a, int rider);
extern "C" int func_00148C68(void* iface, int a, int rider);
extern "C" int func_00148B78(void* iface, int a, int rider);
extern "C" int func_00148CB8(void* iface, int a, int rider);
extern "C" int func_00148D58(void* iface, int a, int rider);
extern "C" int func_00148D08(void* iface, int a, int rider);
extern "C" int func_00148C18(void* iface, int a, int rider);
extern void* D_004A28A8;

struct sTagMsg264E50 {
    int type;                   // 0x0
    int rider;                  // 0x4
    int state;                  // 0x8
    unsigned char stats[7];     // 0xC
};

extern "C" void func_00264E50(void* self, int type, int rider, int state)
{
    sTagMsg264E50 msg;
    msg.type = type;
    msg.state = state;
    msg.rider = rider;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 3);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (*(int*)((char*)self + 0x128) != 0) {
        int i;
        for (i = 0; i < 7; i++)
            msg.stats[i] = 40;
    } else {
        msg.stats[0] = func_00148BC8(iface, 0, rider);
        msg.stats[1] = func_00148C68(iface, 0, rider);
        msg.stats[2] = func_00148B78(iface, 0, rider);
        msg.stats[3] = func_00148CB8(iface, 0, rider);
        msg.stats[4] = func_00148D58(iface, 0, rider);
        msg.stats[5] = func_00148D08(iface, 0, rider);
        msg.stats[6] = func_00148C18(iface, 0, rider);
    }
    func_00264BE8(self, &msg, sizeof(msg));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_00264F88);
#ifdef SKIP_ASM
extern "C" void func_00264CF0(void* self, int a1);
extern "C" void func_00264E50(void* self, int event, int a2, int state);

extern "C" void func_00264F88(void* self, int a1)
{
    int state = *(int*)self;
    if (state == 0xC) {
        return;
    }
    if (*(int*)((char*)self + 0x124) != 0) {
        if (state == 1) {
            *(int*)self = 2;
        }
        func_00264CF0(self, a1);
        func_00264E50(self, 0, a1, *(int*)self);
    } else {
        func_00264E50(self, 1, a1, 0);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265018);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;
extern "C" void func_00264CF0(void* self, int charID);
extern "C" void func_00264E50(void* self, int type, int rider, int state);

struct sMsgListNode5018 {
    sMsgListNode5018* next;
    sMsgListNode5018* prev;
    void* data;
};

struct sMsgListIter5018 {
    sMsgListNode5018* node;
    sMsgListIter5018(sMsgListNode5018* x) : node(x) {}
    sMsgListIter5018(const sMsgListIter5018& x) : node(x.node) {}
};

static inline sMsgListIter5018 sMsgList5018_insert(sMsgListIter5018 pos, void* const& x)
{
    sMsgListNode5018* tmp = (sMsgListNode5018*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00265018(void* self, int rider)
{
    if (*(int*)((char*)self + 0x124) != 0) {
        int st = *(int*)self;
        if (st > 0) {
            if (st < 3)
                *(int*)self = 4;
            else if (st == 3)
                *(int*)self = 5;
        }
        func_00264CF0(self, rider);
        int type = 0xF4;
        func_00264E50(self, 2, rider, *(int*)self);
        char* g = (char*)D_004A3028;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgList5018_insert(*(sMsgListNode5018**)(g + 0xF0), mp);
    } else {
        func_00264E50(self, 3, rider, *(int*)self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tagsunk", func_00265140);
#ifdef SKIP_ASM
extern "C" void func_00264E50(void* self, int event, int a2, int state);

extern "C" void func_00265140(int* self)
{
    int event;
    if (*self != 0xC) {
        if (*(int*)((char*)self + 0x124) != 0) {
            if (*self == 4) {
                *self = 2;
            }
            event = 4;
        } else {
            event = 5;
        }
        func_00264E50(self, event, -1, *self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265190);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;
struct sName7_00264D80;
extern "C" void func_00264D80(void* self, int charID, sName7_00264D80* name);
extern "C" void func_00264E50(void* self, int type, int rider, int state);

struct sMsgListNode5190 {
    sMsgListNode5190* next;
    sMsgListNode5190* prev;
    void* data;
};

struct sMsgListIter5190 {
    sMsgListNode5190* node;
    sMsgListIter5190(sMsgListNode5190* x) : node(x) {}
    sMsgListIter5190(const sMsgListIter5190& x) : node(x.node) {}
};

static inline sMsgListIter5190 sMsgList5190_insert(sMsgListIter5190 pos, void* const& x)
{
    sMsgListNode5190* tmp = (sMsgListNode5190*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00265190(void* self, int rider, sName7_00264D80* name)
{
    int st = *(int*)self;
    if (st != 2) {
        if (st < 3) {
            if (st == 1)
                *(int*)self = 2;
        }
    }
    func_00264D80(self, rider, name);
    int type = 0xF3;
    func_00264E50(self, 1, rider, *(int*)self);
    {
        char* g = (char*)D_004A3028;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgList5190_insert(*(sMsgListNode5190**)(g + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265290);
#ifdef SKIP_ASM
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;
struct sName7_00264D80;
extern "C" void func_00264D80(void* self, int charID, sName7_00264D80* name);
extern "C" void func_00264E50(void* self, int type, int rider, int state);

struct sMsgListNode5290 {
    sMsgListNode5290* next;
    sMsgListNode5290* prev;
    void* data;
};

struct sMsgListIter5290 {
    sMsgListNode5290* node;
    sMsgListIter5290(sMsgListNode5290* x) : node(x) {}
    sMsgListIter5290(const sMsgListIter5290& x) : node(x.node) {}
};

static inline sMsgListIter5290 sMsgList5290_insert(sMsgListIter5290 pos, void* const& x)
{
    sMsgListNode5290* tmp = (sMsgListNode5290*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00265290(void* self, int rider)
{
    int st = *(int*)self;
    if (st > 0) {
        if (st < 3)
            *(int*)self = 3;
        else if (st == 4)
            *(int*)self = 5;
    }
    int type = 0xF5;
    func_00264D80(self, rider, 0);
    func_00264E50(self, 3, rider, *(int*)self);
    {
        char* g = (char*)D_004A3028;
        int* m = (int*)operator new(8, D_00480488, 0x20000000, 0);
        m[0] = type;
        *(void***)((char*)m + 0x4) = D_004812B0;
        void* mp = m;
        sMsgList5290_insert(*(sMsgListNode5290**)(g + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265398);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_00480488[];
extern char D_004804A8[];
extern void* D_004812B0[];
extern void* D_004A3028;

struct sMsgListNode_00265398 {
    sMsgListNode_00265398* next;
    sMsgListNode_00265398* prev;
    void* data;
};

struct sMsgListIter_00265398 {
    sMsgListNode_00265398* node;
    sMsgListIter_00265398(sMsgListNode_00265398* x) : node(x) {}
    sMsgListIter_00265398(const sMsgListIter_00265398& x) : node(x.node) {}
};

static inline sMsgListIter_00265398 sMsgList_00265398_insert(sMsgListIter_00265398 pos, void* const& x)
{
    sMsgListNode_00265398* tmp = (sMsgListNode_00265398*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00265398 {
    int kind;
    void** vt;
};

extern "C" void func_00265398(int* self)
{
    if (*self == 3)
        *self = 2;
    char* g = (char*)D_004A3028;
    sMsg_00265398* m = (sMsg_00265398*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m->vt = D_004812B0;
    m->kind = 0xF7;
    void* mp = m;
    sMsgList_00265398_insert(*(sMsgListNode_00265398**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265458);
#ifdef SKIP_ASM
extern char D_004804A8[];
extern char D_00480F18[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern void* D_004A3028;
extern "C" void func_00264BE8(void* self, void* msg, int size);
extern void* D_00481150[];

struct sMsgListNode5458 {
    sMsgListNode5458* next;
    sMsgListNode5458* prev;
    void* data;
};

struct sMsgListIter5458 {
    sMsgListNode5458* node;
    sMsgListIter5458(sMsgListNode5458* x) : node(x) {}
    sMsgListIter5458(const sMsgListIter5458& x) : node(x.node) {}
};

static inline sMsgListIter5458 sMsgList5458_insert(sMsgListIter5458 pos, void* const& x)
{
    sMsgListNode5458* tmp = (sMsgListNode5458*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sTagMsg5458 {
    int type;   // 0x0
    int id;     // 0x4
    int state;  // 0x8
    int pad[2];
};

struct sNetMsg5458 {
    int type;       // 0x0
    void** vt;      // 0x4
    int flag;       // 0x8
    int v0;         // 0xC
    int v1;         // 0x10
};

extern "C" void func_00265458(void* self, int id)
{
    int st = *(int*)self;
    if (st != 12) {
        int type;
        if (*(int*)((char*)self + 0x124) != 0) {
            if (st >= 5) {
                if (st < 7)
                    *(int*)self = 7;
            }
            type = 6;
        } else
            type = 7;
        sTagMsg5458 msg;
        msg.type = type;
        msg.state = *(int*)self;
        msg.id = id;
        func_00264BE8(self, &msg, sizeof(msg));
        sNetMsg5458* m = (sNetMsg5458*)cMemMan_alloc(0x10, D_00480F18, 0x20000000, 0);
        m->type = 0xFB;
        m->vt = D_00481150;
        m->v0 = id;
        m->flag = 0;
        void* mp = m;
        sMsgList5458_insert(*(sMsgListNode5458**)((char*)D_004A3028 + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265568);
#ifdef SKIP_ASM
extern char D_004804A8[];
extern char D_00480F18[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern void* D_004A3028;
extern "C" void func_00264BE8(void* self, void* msg, int size);
extern void* D_00481130[];

struct sMsgListNode5568 {
    sMsgListNode5568* next;
    sMsgListNode5568* prev;
    void* data;
};

struct sMsgListIter5568 {
    sMsgListNode5568* node;
    sMsgListIter5568(sMsgListNode5568* x) : node(x) {}
    sMsgListIter5568(const sMsgListIter5568& x) : node(x.node) {}
};

static inline sMsgListIter5568 sMsgList5568_insert(sMsgListIter5568 pos, void* const& x)
{
    sMsgListNode5568* tmp = (sMsgListNode5568*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sTagMsg5568 {
    int type;   // 0x0
    int a;      // 0x4
    int b;      // 0x8
    int pad[2];
};

struct sNetMsg5568 {
    int type;       // 0x0
    void** vt;      // 0x4
    int flag;       // 0x8
    int v0;         // 0xC
    int v1;         // 0x10
};

extern "C" void func_00265568(void* self, int a, int b)
{
    int st = *(int*)self;
    if (st != 12) {
        int type;
        if (*(int*)((char*)self + 0x124) != 0) {
            if (st >= 5) {
                if (st < 7)
                    *(int*)self = 7;
            }
            type = 8;
        } else
            type = 9;
        sTagMsg5568 msg;
        msg.type = type;
        msg.a = a;
        msg.b = b;
        func_00264BE8(self, &msg, sizeof(msg));
        sNetMsg5568* m = (sNetMsg5568*)cMemMan_alloc(0x14, D_00480F18, 0x20000000, 0);
        m->type = 0xFC;
        m->vt = D_00481130;
        m->v0 = a;
        m->v1 = b;
        m->flag = 0;
        void* mp = m;
        sMsgList5568_insert(*(sMsgListNode5568**)((char*)D_004A3028 + 0xF0), mp);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265688);
#ifdef SKIP_ASM
// PORT: really returns int (the unit declares it void); the int return keeps the target's store scheduling.
extern "C" int func_00264BE8_5688(void* self, void* msg, int size) __asm__("func_00264BE8");
struct sMsg_5688 {
    int code;
    int state;
    unsigned int arg;
    int pad[2];
};

// Advances the connection state (5..7 -> 9, 8 -> 10) and posts a status message.
extern "C" void func_00265688(int* self)
{
    sMsg_5688 m;
    int code = 0xB;
    if (self[0x124 / 4] != 0) {
        code = 0xA;
        int st = self[0];
        if (st >= 5) {
            int nst;
            if (st < 8)
                nst = 9;
            else if (st == 8)
                nst = 10;
            else
                goto send;
            self[0] = nst;
            code = 0xA;
        }
    }
send:
    m.code = code;
    m.state = self[0];
    m.arg = 0xFFFFFFFF;
    func_00264BE8_5688(self, &m, 0x14);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265700);
#ifdef SKIP_ASM
struct sTagMsg265700 {
    int type;          // 0x0
    int state;         // 0x4
    unsigned int id;   // 0x8
    int pad[2];
};

extern "C" void func_00264BE8(void* self, void* msg, int size);

extern "C" void func_00265700(void* self)
{
    sTagMsg265700 msg;
    int type;
    int state = *(int*)self;
    if (state == 12)
        return;
    if (*(int*)((char*)self + 0x124) != 0) {
        if (state == 9)
            *(int*)self = 7;
        type = 12;
    } else {
        type = 13;
    }
    msg.type = type;
    msg.state = *(int*)self;
    msg.id = 0xFFFFFFFF;
    func_00264BE8(self, &msg, sizeof(msg));
}
#endif

INCLUDE_ASM("dirtysock/tagsunk", func_00265768);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265880);
#ifdef SKIP_ASM
extern char D_00480F30[];
extern void* D_004A33D0;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002658E0(void* self);

extern "C" void func_00265880(void)
{
    D_004A33D0 = func_002658E0(cMemMan_alloc(8, D_00480F30, 0x20000000, 0));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002658B8);
#ifdef SKIP_ASM
extern void* D_004A33D0;
extern "C" void func_00265908(void* self, int flags);

extern "C" void func_002658B8(void)
{
    if (D_004A33D0 != 0) {
        func_00265908(D_004A33D0, 3);
        D_004A33D0 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002658E0);
#ifdef SKIP_ASM
extern "C" void func_00265950(void* self);

extern "C" void* func_002658E0(void* self)
{
    func_00265950(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265908);
#ifdef SKIP_ASM
extern "C" void func_002659C0(void* self);
void operator_delete(int*);

extern "C" void func_00265908(void* self, int flags)
{
    func_002659C0(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265950);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern int D_004A33DC;
extern int D_004A33E0;
extern int D_004A33E4;
struct sDsInit265950 { void* buf; int len; };
extern sDsInit265950 D_004A5B48_s __asm__("D_004A5B48");
extern char D_00442A18[];
extern char D_00537190[];
extern "C" void* func_003E6448(void* dst, int value, int size);
extern "C" void func_003F7EE0(void* p);
extern "C" void* func_002C22C8();

// Resets the DirtySock session state and creates the session object.
extern "C" void func_00265950(void* vself)
{
    int* self = (int*)vself;
    self[0] = 1;
    D_004A33D4 = 0;
    self[1] = 0;
    D_004A5B48_s.buf = D_00442A18;
    D_004A33E0 = 0;
    D_004A33DC = 0;
    D_004A33E4 = 0;
    D_004A5B48_s.len = 0;
    func_003F7EE0(&D_004A5B48_s);
    func_003E6448(D_00537190, 0, 0x40);
    D_004A33D8 = func_002C22C8();
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002659C0);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern "C" int func_003F7F18();
extern "C" void func_002C2300(void* h);

extern "C" void func_002659C0(void* self)
{
    *(int*)self = 0;
    func_003F7F18();
    func_002C2300(D_004A33D8);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002659E8);
#ifdef SKIP_ASM
struct cDsObj2659E8 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int a);
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int v11();
};

extern void* D_004A33D8;
extern int D_004A33DC;

extern "C" void func_002659E8(void* self)
{
    if (((cDsObj2659E8*)D_004A33D8)->v11() == 0) {
        ((cDsObj2659E8*)D_004A33D8)->v05(D_004A33DC);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265A38);
#ifdef SKIP_ASM
struct cDsObj265A38 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int v20();
};

extern void* D_004A33D8;

extern "C" int func_00265A38(void* self)
{
    return ((cDsObj265A38*)D_004A33D8)->v20();
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265A68);
#ifdef SKIP_ASM
extern int D_004A3940;
extern "C" void func_00265D98(void* state);
extern "C" void func_00265E40(void* state);
extern "C" void func_00265E80(void* state);
extern "C" void func_00265EC8(void* state);
extern "C" void func_00265F00(void* state);
extern "C" int func_003F80E0(int* status);

struct cDsObj265A68 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int a);
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual int v11();
};

// Advances the DirtySock login state machine one step; each "wait" state checks that the socket is idle.
extern "C" void func_00265A68(int* state)
{
    ((cDsObj265A68*)D_004A33D8)->v03();
    int status = 0;
    switch (*state) {
    case 0:
        break;
    case 2:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            func_00265D98(state);
        }
        break;
    case 6:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            func_00265E40(state);
        }
        break;
    case 10:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            func_00265E80(state);
        }
        break;
    case 14:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            func_00265EC8(state);
        }
        break;
    case 18:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            func_00265F00(state);
        }
        break;
    case 3:
    case 7:
    case 11:
    case 15: {
        int r = func_003F80E0(&status);
        state[1] = r;
        if (r == 0) {
            if (status == 2) {
                *state += 1;
            }
        } else {
            *state += 2;
        }
        break;
    }
    case 4:
    case 8:
    case 12:
    case 16:
    case 21:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            ((cDsObj265A68*)D_004A33D8)->v05(0);
        }
        break;
    case 19:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            ((cDsObj265A68*)D_004A33D8)->v08();
            *state = 20;
        }
        break;
    case 20:
        if (!((cDsObj265A68*)D_004A33D8)->v11()) {
            if (D_004A3940 != 0) {
                *state = 0x16;
            } else {
                *state = 0x15;
            }
        }
        break;
    case 22:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265CB0);
#ifdef SKIP_ASM
struct cDsObj265CB0 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual bool v53();
    virtual void v54();
    virtual bool v55();
};

extern void* D_004A33D8;

extern "C" int func_00265CB0(void* self)
{
    if (((cDsObj265CB0*)D_004A33D8)->v53() != 0) {
        return !((cDsObj265CB0*)D_004A33D8)->v55();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265D08);
#ifdef SKIP_ASM
struct cDsObj265D08 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
};

extern void* D_004A33D8;

extern "C" void func_00265D08(void* self)
{
    ((cDsObj265D08*)D_004A33D8)->v47();
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265D38);
#ifdef SKIP_ASM
struct cDsObj265D38 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual int v63();
};

extern void* D_004A33D8;

extern "C" int func_00265D38(void* self)
{
    return ((cDsObj265D38*)D_004A33D8)->v63();
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265D68);
#ifdef SKIP_ASM
struct cDsObj265D68 {
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
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual bool v53();
};

extern void* D_004A33D8;

extern "C" int func_00265D68(void* self)
{
    return !((cDsObj265D68*)D_004A33D8)->v53();
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265D98);
#ifdef SKIP_ASM
extern char D_00536760[0x11];
extern int D_004A33E0;
extern "C" void* func_003E6448(void* dst, int value, int size);
extern "C" int func_003F8000(void* p);

extern "C" void func_00265D98(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    D_004A33E0 = 0;
    func_003E6448(D_00536760, 0, 0x24);
    func_003F8000(D_00536760);
    *(int*)self = 3;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265DF0__FPv);
#ifdef SKIP_ASM
void func_00265DF0(void* self)
{
    *(int*)self = 2;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E00__FPv);
#ifdef SKIP_ASM
void func_00265E00(void* self)
{
    *(int*)self = 6;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E10__FPv);
#ifdef SKIP_ASM
void func_00265E10(void* self)
{
    *(int*)self = 10;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E20__FPv);
#ifdef SKIP_ASM
void func_00265E20(void* self)
{
    *(int*)self = 14;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E30__FPv);
#ifdef SKIP_ASM
void func_00265E30(void* self)
{
    *(int*)self = 18;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E40);
#ifdef SKIP_ASM
extern char D_00536760[0x11];
extern int D_004A33E0;
extern "C" int func_003F8048(void* p);

extern "C" void func_00265E40(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    D_004A33E0 = 0;
    func_003F8048(D_00536760);
    *(int*)self = 7;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265E80);
#ifdef SKIP_ASM
extern char D_00536760[0x11];
extern char D_00442A60[];
extern int D_004A33E0;
extern "C" int func_003F7F48(void* a, void* b);

extern "C" void func_00265E80(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    D_004A33E0 = 0;
    func_003F7F48(D_00442A60, D_00536760);
    *(int*)self = 0xB;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265EC8);
#ifdef SKIP_ASM
extern int D_004A33E0;
extern "C" int func_003F80C0();

extern "C" void func_00265EC8(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    D_004A33E0 = 0;
    func_003F80C0();
    *(int*)self = 0xF;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265F00);
#ifdef SKIP_ASM
extern int D_004A33E0;

extern "C" void func_00265F00(void* self)
{
    *(int*)((char*)self + 0x4) = 0;
    D_004A33E0 = 0;
    *(int*)self = 0x13;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265F18);
#ifdef SKIP_ASM
extern char D_00536760[0x11];
extern "C" void* func_003E6448(void* dst, int value, int size);

extern "C" void func_00265F18(const char* name)
{
    func_003E6448(D_00536760, 0, 0x11);
    strcpy(D_00536760, name);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265F68);
#ifdef SKIP_ASM
extern char D_00536771[0x11];
extern "C" void* func_003E6448(void* dst, int value, int size);

extern "C" void func_00265F68(const char* name)
{
    func_003E6448(D_00536771, 0, 0x11);
    strcpy(D_00536771, name);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00265FB8);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern char D_00537190[];
extern "C" void* func_003E6448(void* dst, int value, int size);
extern "C" int func_003FA1D0(int code, void* out);
extern "C" void func_002C6810(void* obj, void* a1);

struct sDsErr265FB8 {
    char a;
    char b;
};

extern "C" void func_00265FB8(void* arg, int code)
{
    sDsErr265FB8 err;
    func_003FA1D0(code, &err);
    func_003E6448(D_00537190, 0, 0x40);
    func_002C6810(D_004A33D8, arg);
    D_004A33D4 = 2;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266010);
#ifdef SKIP_ASM
extern int D_004A33D4;
extern "C" int func_003FA1D0(int code, void* out);

struct sDsErr266010 {
    char a;
    char b;
};

extern "C" void func_00266010(int code)
{
    sDsErr266010 err;
    func_003FA1D0(code, &err);
    D_004A33D4 = 9;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266038);
#ifdef SKIP_ASM
extern int D_004A33D4;
extern "C" int func_003FA1D0(int code, void* out);

struct sDsErr266038 {
    char a;
    char b;
};

extern "C" void func_00266038(int code)
{
    sDsErr266038 err;
    func_003FA1D0(code, &err);
    D_004A33D4 = 0xA;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266060);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern int D_004A33DC;
extern int D_004A33E4;
extern "C" int func_003FA1D0(int code, void* out);
void func_002C67E8(void* self, int a1);

struct sDsErr266060 {
    unsigned char a;
    unsigned char b;
};

extern "C" void func_00266060(int code)
{
    sDsErr266060 err;
    func_003FA1D0(code, &err);
    D_004A33DC = err.a;
    D_004A33E4 = 9;
    func_002C67E8(D_004A33D8, D_004A33DC);
    D_004A33D4 = 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002660A0);
#ifdef SKIP_ASM
extern int D_004A33D4;
extern "C" int func_003FA1D0(int code, void* out);

struct sDsErr2660A0 {
    char a;
    char b;
};

extern "C" void func_002660A0(int code)
{
    sDsErr2660A0 err;
    func_003FA1D0(code, &err);
    D_004A33D4 = 0x3;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002660C8);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern char D_004A33E8[];
extern "C" int func_003FA1D0(int code, void* out);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_002C6968(void* obj, char* str, int a2);

struct sDsErr2660C8 {
    unsigned char a;
    unsigned char b;
};

extern "C" void func_002660C8(const char* a0, const char* a1, int code, int a3)
{
    sDsErr2660C8 err;
    char buf[80];
    func_003FA1D0(code, &err);
    sprintf(buf, D_004A33E8, a0, a1);
    func_002C6968(D_004A33D8, buf, a3);
    D_004A33D4 = 4;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266148);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
void func_002C6A08(void* obj);

extern "C" void func_00266148(void)
{
    func_002C6A08(D_004A33D8);
    D_004A33D4 = 8;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266170);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern "C" int func_003FA1D0(int code, void* out);
extern "C" void func_002C6C50(void* obj, char* str, int a2);

struct sDsErr266170 {
    unsigned char a;
    unsigned char b;
};

extern "C" void func_00266170(const char* name, int a1, int code)
{
    sDsErr266170 err;
    char buf[80];
    func_003FA1D0(code, &err);
    strcpy(buf, name);
    func_002C6C50(D_004A33D8, buf, a1);
    D_004A33D4 = 0xB;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002661D8);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern char D_004A33E8[];
extern "C" int func_003FA1D0(int code, void* out);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_002C6CE0(void* obj, char* str);

struct sDsErr2661D8 {
    unsigned char a;
    unsigned char b;
};

extern "C" void func_002661D8(const char* a0, const char* a1, int code)
{
    sDsErr2661D8 err;
    char buf[80];
    func_003FA1D0(code, &err);
    sprintf(buf, D_004A33E8, a0, a1);
    func_002C6CE0(D_004A33D8, buf);
    D_004A33D4 = 0xC;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266240);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
extern "C" int func_003FA1D0(int code, void* out);
extern "C" void func_002C6CE0(void* obj, char* str);

struct sDsErr266240 {
    unsigned char a;
    unsigned char b;
};

extern "C" void func_00266240(const char* name, int code)
{
    sDsErr266240 err;
    char buf[80];
    func_003FA1D0(code, &err);
    strcpy(buf, name);
    func_002C6CE0(D_004A33D8, buf);
    D_004A33D4 = 0xD;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266298);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
void func_002C6B50(void* obj, int a1, int a2);

extern "C" void func_00266298(int a0, int a1, int a2)
{
    func_002C6B50(D_004A33D8, a1, a2);
    D_004A33D4 = 6;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002662C0);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
void func_002C6BD0(void* obj, int a1, int a2);

extern "C" void func_002662C0(int a0, int a1, int a2)
{
    func_002C6BD0(D_004A33D8, a1, a2);
    D_004A33D4 = 0xE;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002662E8);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
void func_002C6A60(void* obj, int a1, int a2);

extern "C" void func_002662E8(int a0, int a1, int a2)
{
    int r = 0;
    if (a2 != 0) {
        r = (a2 == 1);
    }
    func_002C6A60(D_004A33D8, a1, r);
    D_004A33D4 = 5;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266320);
#ifdef SKIP_ASM
extern void* D_004A33D8;
extern int D_004A33D4;
void func_002C6AE0(void* obj);

extern "C" void func_00266320(void)
{
    func_002C6AE0(D_004A33D8);
    D_004A33D4 = 7;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266348);
#ifdef SKIP_ASM
extern int D_004A33D4;

extern "C" void func_00266348(void)
{
    D_004A33D4 = 0xF;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266358);
#ifdef SKIP_ASM
extern "C" int func_00266578(int err);
extern int D_004A3940;
extern "C" int func_002C51D0(void* self, int id);
void func_002C67E8(void* self, int a1);
extern "C" void func_002C68C8(void* self, int i, char* out);
extern "C" int func_003FA360(char* name);

struct cDsObj266358 {
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
    virtual int v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int v20();
};

// Polls the current DirtySock operation: *status is 1 while busy, 2 when finished; *out receives the result.
extern "C" int func_00266358(int* status, int* out)
{
    *out = 0;
    switch (D_004A33D4) {
    case 3:
    case 15:
    case 16:
        *status = 2;
        return 0;
    case 10:
        *status = 2;
        *out = 0x800;
        return 0;
    }
    if (((cDsObj266358*)D_004A33D8)->v11()) {
        *status = 1;
        return 0;
    }
    *status = 2;
    if (func_002C51D0(D_004A33D8, *(int*)((char*)D_004A33D8 + 0xC))) {
        return func_00266578(func_002C51D0(D_004A33D8, *(int*)((char*)D_004A33D8 + 0xC)));
    }
    switch (D_004A33D4) {
    case 0:
        break;
    case 1:
        if (D_004A33E4 > 0) {
            *status = 1;
            D_004A33E4--;
            func_002C67E8(D_004A33D8, D_004A33DC);
            return 0;
        }
        D_004A33E0 = 1;
        break;
    case 2:
        if (*(int*)((char*)D_004A33D8 + 0x54) <= 0) {
            *out = 0;
            break;
        }
        for (int i = 0; i < *(int*)((char*)D_004A33D8 + 0x54); i++) {
            func_002C68C8(D_004A33D8, i, D_00537190);
            if (func_003FA360(D_00537190)) {
                *out = 1;
                return 0;
            }
        }
        *out = 0;
        break;
    case 5:
        *out = D_004A3940;
        break;
    case 6:
        *out = D_004A3940;
        break;
    case 14:
        *out = D_004A3940;
        break;
    case 9:
        *out = ((cDsObj266358*)D_004A33D8)->v20() << 10;
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266550);
#ifdef SKIP_ASM
extern int D_004A33D4;
extern char D_00537190[];

extern "C" void func_00266550(char* dst)
{
    strcpy(dst, D_00537190);
    D_004A33D4 = 0x10;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266578);
#ifdef SKIP_ASM
extern int D_004A33D4;

// Maps a network error code to a front-end message id depending on the current connection stage.
extern "C" int func_00266578(int err)
{
    switch (D_004A33D4) {
    case 1:
        break;
    case 2:
        switch (err) {
        case -2: return 9;
        case -4: return 4;
        }
        break;
    case 9:
        switch (err) {
        case -2: return 0x11;
        }
        break;
    case 4:
        switch (err) {
        case -2: return 9;
        case -3: return 0xD;
        case -4: return 4;
        case -5: return 0xD;
        case -7: return 0xD;
        }
        break;
    case 8:
        switch (err) {
        case -2: return 9;
        case -4: return 4;
        }
        return 0x11;
    case 5:
        switch (err) {
        case -2: return 9;
        case -3: return 0xE;
        case -4: return 4;
        case -5: return 0xD;
        case -8: return 0xD;
        }
        break;
    case 7:
        switch (err) {
        case -2: return 9;
        case -4: return 4;
        }
        break;
    case 6:
        switch (err) {
        case -2: return 9;
        case -4: return 4;
        case -5: return 0xD;
        }
        break;
    case 14:
        switch (err) {
        case -2: return 9;
        case -3: return 0xE;
        case -4: return 4;
        case -5: return 0xD;
        case -8: return 0xD;
        }
        break;
    case 11:
        switch (err) {
        case -2: return 9;
        case -3: return 0xE;
        case -4: return 8;
        }
        break;
    case 12:
    case 13:
        switch (err) {
        case -2: return 9;
        case -4: return 4;
        case -5: return 5;
        case -6: return 6;
        }
        break;
    }
    return 3;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266728);
#ifdef SKIP_ASM
extern char D_00481080[];
// PORT: operator_new really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

extern "C" void* func_00266728(void* self, int size, int kind)
{
    int flags = 0x20000000;
    if (kind == 0x20) {
        flags = 0x23000000;
    }
    return operator_new_tag(size + 0x400, D_00481080, flags, 0);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266760);
#ifdef SKIP_ASM
void* cMemMan_free(void* ptr);

extern "C" void func_00266760(void* self, void* ptr, int a2, int a3)
{
    if (ptr != 0) {
        cMemMan_free(ptr);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266788);
#ifdef SKIP_ASM
extern char D_00481090[];
extern void* D_004A33F0;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002667E8(void* self);

extern "C" void func_00266788(void)
{
    D_004A33F0 = func_002667E8(cMemMan_alloc(0x464, D_00481090, 0x20000000, 0));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002667C0);
#ifdef SKIP_ASM
extern "C" void func_00266850(int, int);

extern "C" void func_002667C0(void) {
    if ((*(int*)&D_004A33F0) != 0) {
        func_00266850((*(int*)&D_004A33F0), 3);
        (*(int*)&D_004A33F0) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002667E8);
#ifdef SKIP_ASM
extern char D_005371D0[];
extern "C" void func_002668A8(void* self);
extern "C" int func_003F61D0(int a0, int a1, void* name, void* cb, int a4);
extern "C" void* func_003E6448(void* dst, int value, int size);

extern "C" void* func_002667E8(void* self)
{
    *(int*)((char*)self + 0x460) = 0;
    if (func_003F61D0(0, 0, D_005371D0, (void*)func_002668A8, 0) >= 0) {
        *(int*)((char*)self + 0x460) = 1;
    }
    func_003E6448(self, 0, 0x460);
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266850);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003F62F8();
extern "C" void func_00266850_impl(void* self, int flags) __asm__("func_00266850");

extern "C" void func_00266850_impl(void *self, int flags) {
    if (*(int *)((char*)self + 0x460) != 0) {
        func_003F62F8();
        *(int *)((char*)self + 0x460) = 0;
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002668A8);
#ifdef SKIP_ASM
extern "C" void func_003F6358(void* self);
extern "C" void func_0040C7C0(void* self, int a1);
extern "C" void func_0040D430(void* self, int a1);

extern "C" void func_002668A8(void* self)
{
    func_003F6358(self);
    func_0040C7C0(self, 0);
    func_0040D430(self, 0);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002668E8);
#ifdef SKIP_ASM
extern "C" void func_003F63F0();
extern "C" int func_003F6520(int idx);
extern "C" int func_003F6348();
extern "C" void* func_003F64E0(int idx);
extern "C" unsigned char* func_003F68F0(void* conn, int a1, int idx);
extern "C" int func_003F6838(void* conn, int a1, int a2, int a3);

struct sSlotFlags_668E8 {
    unsigned active : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
};

struct sSlot_668E8 {
    int count;                  // 0x0
    int start;                  // 0x4
    unsigned char buf[64][2];   // 0x8
    sSlotFlags_668E8 flags;     // 0x88
};

struct sSlots_668E8 {
    sSlot_668E8 slot[8];        // 0x0
    int enabled;                // 0x460
};

struct sConn_668E8 {
    unsigned on : 1;            // 0x0
    int f4;
    int count;                  // 0x8
};

static inline int ringIdx_668E8(int w)
{
    return w % 64;
}

extern "C" void func_002668E8(sSlots_668E8* self)
{
    if (self->enabled == 0)
        return;
    func_003F63F0();
    for (int i = 0; i < 8; i++) {
        sSlot_668E8* s = &self->slot[i];
        s->flags.active = func_003F6520(i) == 1;
        if (!s->flags.active)
            *(int*)&s->flags = 0;
    }
    int n = func_003F6348();
    for (int j = 0; j < n; j++) {
        if (self->slot[j].flags.active) {
            sConn_668E8* c = (sConn_668E8*)func_003F64E0(j);
            if (c != 0) {
                for (int k = 0; k < c->count; k++) {
                    unsigned char* e = func_003F68F0(c, 0, k);
                    if (e[0] != 0 || e[1] != 0) {
                        int w = self->slot[j].count;
                        int idx = ringIdx_668E8(w);
                        int r = self->slot[j].start;
                        if (w - r >= 0x40)
                            self->slot[j].start = r + 1;
                        self->slot[j].buf[idx][0] = e[0];
                        self->slot[j].buf[idx][1] = e[1];
                        self->slot[j].count++;
                    }
                }
                if (func_003F6838(c, 0, 0, 0x10))
                    self->slot[j].flags.b4 = 1;
                else
                    self->slot[j].flags.b4 = 0;
                self->slot[j].flags.b2 = c->on;
                self->slot[j].flags.b3 = c->on;
                self->slot[j].flags.b1 = c->on;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266B80);
#ifdef SKIP_ASM
struct sEnt8C {
    int a;
    int b;
    char pad[0x84];
};

struct sEntTable {
    sEnt8C ents[8];
    int active;
};

extern "C" void func_00266B80(sEntTable* self, int idx)
{
    if (self->active != 0) {
        self->ents[idx].b = 0;
        self->ents[idx].a = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266BA8);
#ifdef SKIP_ASM
struct sChan_266BA8 {
    int count;                      // 0x0
    int read;                       // 0x4
    unsigned char buf[64][2];       // 0x8
    int pad;
};

struct sChanSet_266BA8 {
    sChan_266BA8 chan[8];           // 0x0
    char pad[0x460 - 8 * 0x8C];
    int active;                     // 0x460
};

// Pops the next (a, b) pair from channel ch's 64-entry ring; zero entries leave the outputs at -1.
extern "C" int func_00266BA8(sChanSet_266BA8* self, int ch, int* a, int* b)
{
    *a = -1;
    *b = -1;
    if (self->active != 0 && ch < func_003F6348()) {
        if (self->chan[ch].read < self->chan[ch].count) {
            int i = self->chan[ch].read;
            i %= 64;
            if (self->chan[ch].buf[i][0] != 0)
                *a = self->chan[ch].buf[i][0];
            if (self->chan[ch].buf[i][1] != 0)
                *b = self->chan[ch].buf[i][1];
            self->chan[ch].read++;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266CA0);
#ifdef SKIP_ASM
extern char D_004810A0[];
extern void* D_004A33F4;
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* func_00266D00(void* self);

extern "C" void func_00266CA0(void)
{
    D_004A33F4 = func_00266D00(cMemMan_alloc(8, D_004810A0, 0x20000000, 0));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266CD8);
#ifdef SKIP_ASM
extern void* D_004A33F4;
extern "C" void func_00266D10(void* self, int flags);

extern "C" void func_00266CD8(void)
{
    if (D_004A33F4 != 0) {
        func_00266D10(D_004A33F4, 3);
        D_004A33F4 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266D00__FPv);
#ifdef SKIP_ASM
void* func_00266D00(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0x4) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266D10);
#ifdef SKIP_ASM
extern "C" void func_00266DF8(void* self);
void operator_delete(int*);

extern "C" void func_00266D10(void* self, int flags)
{
    func_00266DF8(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266D58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A33F8;
extern int D_00535610[];
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_003F6AB8(void* a0, int a1, int a2);
extern "C" void func_003F6C10(int a0, int a1);
extern "C" void func_00266E88(void* self);
extern "C" void func_00266E30(void* self);

extern "C" void func_00266D58(void* self, void* a1)
{
    if (*(int*)self == 0) {
        func_003F6AB8(a1, 6000, 6000);
        int n = D_004A33F8;
        *(int*)self = 1;
        func_003F6C10(n, 0x55);
        if (D_004A33F8 < 10) {
            func_00266E88(self);
        } else {
            cBE_getInterface_Fv(cBE_getBE(), 4);
            if ((D_00535610[0] >> 18) & 1) {
                func_00266E30(self);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266DF8);
#ifdef SKIP_ASM
extern "C" void func_003F6AF0(void* self);

extern "C" void func_00266DF8(void* self)
{
    if (*(void**)self != 0) {
        func_003F6AF0(self);
        *(void**)self = 0;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266E30);
#ifdef SKIP_ASM
extern int D_004A33F8;
extern "C" void func_003F6B20();

extern "C" void func_00266E30(void* self)
{
    if (*(int*)self != 0 && *(int*)((char*)self + 0x4) == 0 && D_004A33F8 >= 10) {
        func_003F6B20();
        *(int*)((char*)self + 0x4) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266E88);
#ifdef SKIP_ASM
extern "C" void func_003F6B50(void* self);

extern "C" void func_00266E88(void* self)
{
    if (*(int*)self != 0 && *(int*)((char*)self + 0x4) != 0) {
        func_003F6B50(self);
        *(int*)((char*)self + 0x4) = 0;
    }
}
#endif

extern "C" void* func_003F6C40(void* self);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266ED0);
#ifdef SKIP_ASM
extern "C" void func_00266ED0(void* self)
{
    if (*(int*)((char*)self + 4) != 0) {
        func_00266E88(self);
    } else {
        func_00266E30(self);
    }
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266F08);
#ifdef SKIP_ASM
extern "C" int func_003F6B80(void*);

extern "C" int func_00266F08(int* self)
{
    return *self != 0 ? func_003F6B80(self) : 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266F38__FPv);
#ifdef SKIP_ASM
void* func_00266F38(void* self)
{
    return func_003F6C40(self);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266F58);
#ifdef SKIP_ASM
extern int D_004A33F8;
extern "C" void func_003F6C10(int a0, int a1);

extern "C" void func_00266F58(void* self, int a1, int a2)
{
    if (*(int*)self != 0) {
        func_003F6C10(a1, a2);
    }
    D_004A33F8 = a1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266F90);
#ifdef SKIP_ASM
extern "C" void func_003F6BA0(void* a, void* b);

extern "C" void func_00266F90(void* self, void* a, void* b)
{
    if (*(int*)self != 0) {
        func_003F6BA0(a, b);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00266FC0);
#ifdef SKIP_ASM
extern "C" void* func_00266FC0(void* self, ...)
{
    return self;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267000);
#ifdef SKIP_ASM
extern "C" int func_00267000(signed char* first1, signed char* last1, signed char* first2, signed char* last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2)
            return 1;
        if (*first2 < *first1)
            return 0;
        ++first1;
        ++first2;
    }
    return first1 == last1 && first2 != last2;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267068);
#ifdef SKIP_ASM
extern "C" int func_00267068(signed char* first1, signed char* last1, signed char* first2, signed char* last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2)
            return -1;
        if (*first2 < *first1)
            return 1;
        ++first1;
        ++first2;
    }
    if (first2 == last2)
        return !(first1 == last1);
    else
        return -1;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002670C8);
#ifdef SKIP_ASM
struct sListNode_2670C8 {
    sListNode_2670C8* next;
    sListNode_2670C8* prev;
};

extern "C" void func_002670C8(char* self)
{
    sListNode_2670C8* head = *(sListNode_2670C8**)(self + 4);
    sListNode_2670C8* cur = head->next;
    while (cur != *(sListNode_2670C8**)(self + 4)) {
        sListNode_2670C8* tmp = cur;
        cur = cur->next;
        operator_delete((int*)tmp);
    }
    (*(sListNode_2670C8**)(self + 4))->next = *(sListNode_2670C8**)(self + 4);
    (*(sListNode_2670C8**)(self + 4))->prev = *(sListNode_2670C8**)(self + 4);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267128);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0041610C(void* dst, const void* src, unsigned int n);
void* cMemMan_free(void* ptr);
void operator_delete(int*);
extern char D_004804A8[];

struct sPtrVec7128 {
    void* alloc;
    void** start;
    void** finish;
    void** eos;
};

static inline void** sPtrVec7128_allocate(unsigned int n)
{
    if (n == 1)
        return (void**)cMemMan_alloc(4, D_004804A8, 0x20000000, 0);
    return (void**)operator_new_tag(n * 4, D_004804A8, 0x20000000, 0);
}

static inline void sPtrVec7128_deallocate(void** p, unsigned int n)
{
    if (p != 0) {
        if (n == 1)
            operator_delete((int*)p);
        else
            cMemMan_free(p);
    }
}

static inline void** sPtrVec7128_copy(void** first, void** last, void** result)
{
    func_0041610C(result, first, (last - first) * sizeof(void*));
    return result + (last - first);
}

static inline void** sPtrVec7128_ucopy(void** first, void** last, void** result)
{
    return sPtrVec7128_copy(first, last, result);
}

static inline void sPtrVec7128_construct(void** p, void* const& v)
{
    if (p != 0)
        *p = v;
}

static inline void** sPtrVec7128_copy_backward(void** first, void** last, void** result)
{
    int n = last - first;
    func_0041610C(result - n, first, n * sizeof(void*));
    return result - n;
}

extern "C" void func_00267128(sPtrVec7128* self, void** pos, void* const& x)
{
    if (self->finish != self->eos) {
        if (self->finish != 0)
            *self->finish = self->finish[-1];
        ++self->finish;
        void* x_copy = x;
        sPtrVec7128_copy_backward(pos, self->finish - 2, self->finish - 1);
        *pos = x_copy;
    } else {
        unsigned int old_size = self->finish - self->start;
        unsigned int len = old_size != 0 ? 2 * old_size : 1;
        void** new_start = sPtrVec7128_allocate(len);
        void** new_finish = new_start;
        new_finish = sPtrVec7128_ucopy(self->start, pos, new_start);
        sPtrVec7128_construct(new_finish, x);
        ++new_finish;
        new_finish = sPtrVec7128_ucopy(pos, self->finish, new_finish);
        sPtrVec7128_deallocate(self->start, self->eos - self->start);
        self->start = new_start;
        self->finish = new_finish;
        self->eos = new_start + len;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002672C8);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0041610C(void* dst, const void* src, unsigned int n);
void* cMemMan_free(void* ptr);
void operator_delete(int*);
extern char D_004804A8[];

struct sPtrVec72C8 {
    void* alloc;
    void** start;
    void** finish;
    void** eos;
};

static inline void** sPtrVec72C8_allocate(unsigned int n)
{
    if (n == 1)
        return (void**)cMemMan_alloc(4, D_004804A8, 0x20000000, 0);
    return (void**)operator_new_tag(n * 4, D_004804A8, 0x20000000, 0);
}

static inline void sPtrVec72C8_deallocate(void** p, unsigned int n)
{
    if (p != 0) {
        if (n == 1)
            operator_delete((int*)p);
        else
            cMemMan_free(p);
    }
}

static inline void** sPtrVec72C8_copy(void** first, void** last, void** result)
{
    func_0041610C(result, first, (last - first) * sizeof(void*));
    return result + (last - first);
}

static inline void** sPtrVec72C8_ucopy(void** first, void** last, void** result)
{
    return sPtrVec72C8_copy(first, last, result);
}

static inline void sPtrVec72C8_construct(void** p, void* const& v)
{
    if (p != 0)
        *p = v;
}

static inline void** sPtrVec72C8_copy_backward(void** first, void** last, void** result)
{
    int n = last - first;
    func_0041610C(result - n, first, n * sizeof(void*));
    return result - n;
}

extern "C" void func_002672C8(sPtrVec72C8* self, void** pos, void* const& x)
{
    if (self->finish != self->eos) {
        if (self->finish != 0)
            *self->finish = self->finish[-1];
        ++self->finish;
        void* x_copy = x;
        sPtrVec72C8_copy_backward(pos, self->finish - 2, self->finish - 1);
        *pos = x_copy;
    } else {
        unsigned int old_size = self->finish - self->start;
        unsigned int len = old_size != 0 ? 2 * old_size : 1;
        void** new_start = sPtrVec72C8_allocate(len);
        void** new_finish = new_start;
        new_finish = sPtrVec72C8_ucopy(self->start, pos, new_start);
        sPtrVec72C8_construct(new_finish, x);
        ++new_finish;
        new_finish = sPtrVec72C8_ucopy(pos, self->finish, new_finish);
        sPtrVec72C8_deallocate(self->start, self->eos - self->start);
        self->start = new_start;
        self->finish = new_finish;
        self->eos = new_start + len;
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267468);
#ifdef SKIP_ASM
extern float D_004D2C38[4];
extern float D_004D2C48[4];
extern float D_004D2C58[4];
extern float D_004D2C68[4];
extern float D_004D2C78[4];
extern float D_004D2C88[4];
extern float D_004D2C98[4];
extern float D_004D2CA8[4];
extern float D_004D2CB8[4];
extern float D_004D2CC8[4];
extern float D_004D2CD8[4];
extern float D_004D2CE8[4];
extern float D_004D2CF8[4];
extern float D_004D2D08[4];
extern float D_004D2D18[4];
extern float D_004D2D28[4];
extern float D_004D2D38[4];
extern float D_004D2D48[4];
extern float D_004D2D58[4];
extern float D_004D2D68[4];
extern float D_004D2D78[4];
extern float D_004D2D88[4];
extern float D_004D2D98[4];
extern float D_004D2DA8[4];
extern float D_004D2DB8[4];
extern float D_004D2DC8[4];
extern float D_004D2DD8[4];
extern float D_004D2DE8[4];
extern float D_004D2DF8[4];
extern float D_004D2E08[4];
extern float D_004D2E18[4];
extern float D_004D2E28[4];
extern float D_004D2E38[4];
extern float D_004D2E48[4];
extern float D_004D2E58[4];
extern float D_004D2E68[4];
extern float D_004D2E78[4];
extern float D_004D2E88[4];
extern float D_004D2E98[4];
extern float D_004D2EA8[4];
extern float D_004D2EB8[4];
extern float D_004D2EC8[4];
extern float D_004D2ED8[4];
extern float D_004D2EE8[4];
extern float D_004D2EF8[4];
extern float D_004D2F08[4];
extern float D_004D2F18[4];
extern float D_004D2F28[4];
extern float D_004D2F38[4];
extern float D_004D2F48[4];
extern float D_004D2F58[4];
extern float D_004D2F68[4];
extern float D_004D2F78[4];
extern float D_004D2F88[4];
extern float D_004D2F98[4];
extern float D_004D2FA8[4];
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
extern int D_004A50D8;
extern int D_004A50E0;
extern int D_004A50E4;
extern int D_004A50E8[2];
extern int D_004A50F0[2];
extern int D_004A50F8[2];
extern int D_004A5100[2];
extern int D_004A5108[2];
extern int D_004A5110[2];
extern int D_004A5118[2];
extern int D_004A5120[2];
extern int D_004A5128[2];
extern int D_004A5130[2];
extern int D_004A5138[2];
extern int D_004A5140[2];
extern int D_004A5148[2];
extern int D_004A5150[2];
void sti_00267468(int init, int prio) __asm__("func_00267468");
void sti_00267468(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004D2C38[0] = 1.0f;
        D_004D2C38[1] = 1.0f;
        D_004D2C38[2] = 1.0f;
        D_004D2C38[3] = 0.5f;
        D_004D2C48[0] = 0.4998680055141449f;
        D_004D2C48[1] = 1.0f;
        D_004D2C48[2] = 1.0f;
        D_004D2C48[3] = 0.0f;
        D_004D2C58[0] = 0.12951700389385223f;
        D_004D2C58[1] = 1.0f;
        D_004D2C58[2] = 1.0f;
        D_004D2C58[3] = 0.0f;
        D_004D2C68[0] = 0.22426900267601013f;
        D_004D2C68[1] = 0.9402310252189636f;
        D_004D2C68[2] = 0.5425059795379639f;
        D_004D2C68[3] = 0.0004030000127386302f;
        D_004D2C78[0] = 0.4652079939842224f;
        D_004D2C78[1] = 0.32170501351356506f;
        D_004D2C78[2] = 0.9943439960479736f;
        D_004D2C78[3] = 0.0f;
        D_004D2C88[0] = 0.17792600393295288f;
        D_004D2C88[1] = 1.0f;
        D_004D2C88[2] = 1.0f;
        D_004D2C88[3] = 0.0f;
        D_004D2C98[0] = 0.4411740005016327f;
        D_004D2C98[1] = 0.41388601064682007f;
        D_004D2C98[2] = 0.3211260139942169f;
        D_004D2C98[3] = 0.4398239850997925f;
        D_004D2CA8[0] = 0.500997006893158f;
        D_004D2CA8[1] = 0.24849599599838257f;
        D_004D2CA8[2] = 1.0f;
        D_004D2CA8[3] = 1.0f;
        D_004D2CB8[0] = 0.27687299251556396f;
        D_004D2CB8[1] = 0.6395620107650757f;
        D_004D2CB8[2] = 0.13423900306224823f;
        D_004D2CB8[3] = 0.0f;
        D_004D2CC8[0] = 0.8936439752578735f;
        D_004D2CC8[1] = 0.5263469815254211f;
        D_004D2CC8[2] = 0.5051450133323669f;
        D_004D2CC8[3] = 0.8687300086021423f;
        D_004D2CD8[0] = 1.0f;
        D_004D2CD8[1] = 1.0f;
        D_004D2CD8[2] = 1.0f;
        D_004D2CD8[3] = 1.0f;
        D_004D2CE8[0] = 1.0f;
        D_004D2CE8[1] = 0.0f;
        D_004D2CE8[2] = 0.0f;
        D_004D2CE8[3] = 0.0f;
        D_004D2CF8[0] = 1.0f;
        D_004D2CF8[1] = 0.550000011920929f;
        D_004D2CF8[2] = 0.5350000262260437f;
        D_004D2CF8[3] = 0.550000011920929f;
        D_004D2D08[0] = 1.0f;
        D_004D2D08[1] = 1.0f;
        D_004D2D08[2] = 1.0f;
        D_004D2D08[3] = 1.0f;
        D_004D2D18[0] = 1.0f;
        D_004D2D18[1] = 1.0f;
        D_004D2D18[2] = 1.0f;
        D_004D2D18[3] = 1.0f;
        D_004D2D28[0] = 1.0f;
        D_004D2D28[1] = 0.0f;
        D_004D2D28[2] = 0.0f;
        D_004D2D28[3] = 0.0f;
        D_004D2D38[0] = 1.0f;
        D_004D2D38[1] = 0.0f;
        D_004D2D38[2] = 0.0f;
        D_004D2D38[3] = 0.0f;
        D_004D2D48[0] = 1.0f;
        D_004D2D48[1] = 1.0f;
        D_004D2D48[2] = 1.0f;
        D_004D2D48[3] = 1.0f;
        D_004D2D58[0] = 1.0f;
        D_004D2D58[1] = 0.5f;
        D_004D2D58[2] = 1.0f;
        D_004D2D58[3] = 0.5f;
        D_004D2D68[0] = 1.0f;
        D_004D2D68[1] = 0.5f;
        D_004D2D68[2] = 1.0f;
        D_004D2D68[3] = 0.5f;
        D_004D2D78[0] = 1.0f;
        D_004D2D78[1] = 0.5f;
        D_004D2D78[2] = 1.0f;
        D_004D2D78[3] = 0.5f;
        D_004D2D88[0] = 1.0f;
        D_004D2D88[1] = 0.7828119993209839f;
        D_004D2D88[2] = 0.06171900033950806f;
        D_004D2D88[3] = 0.03984399884939194f;
        D_004D2D98[0] = 1.0f;
        D_004D2D98[1] = 1.0f;
        D_004D2D98[2] = 0.7988259792327881f;
        D_004D2D98[3] = 0.0f;
        D_004D2DA8[0] = 0.9886710047721863f;
        D_004D2DA8[1] = 0.9230499863624573f;
        D_004D2DA8[2] = 0.34311699867248535f;
        D_004D2DA8[3] = 0.0f;
        D_004D2DB8[0] = 1.0f;
        D_004D2DB8[1] = 1.0f;
        D_004D2DB8[2] = 1.0f;
        D_004D2DB8[3] = 1.0f;
        D_004D2DC8[0] = 1.0f;
        D_004D2DC8[1] = 1.0f;
        D_004D2DC8[2] = 0.7976430058479309f;
        D_004D2DC8[3] = 0.0f;
        D_004D2DD8[0] = 1.0f;
        D_004D2DD8[1] = 0.9222670197486877f;
        D_004D2DD8[2] = 0.34179699420928955f;
        D_004D2DD8[3] = 0.0f;
        D_004D2DE8[0] = 1.0f;
        D_004D2DE8[1] = 0.7847639918327332f;
        D_004D2DE8[2] = 0.06054700165987015f;
        D_004D2DE8[3] = 0.04062499850988388f;
        D_004D2DF8[0] = 1.0f;
        D_004D2DF8[1] = 0.800000011920929f;
        D_004D2DF8[2] = 0.44999998807907104f;
        D_004D2DF8[3] = 1.0f;
        D_004D2E08[0] = 1.0f;
        D_004D2E08[1] = 0.3281260132789612f;
        D_004D2E08[2] = 1.0f;
        D_004D2E08[3] = 0.3539060056209564f;
        D_004D2E18[0] = 1.0f;
        D_004D2E18[1] = 1.0f;
        D_004D2E18[2] = 1.0f;
        D_004D2E18[3] = 1.0f;
        D_004D2E28[0] = 1.0f;
        D_004D2E28[1] = 1.0f;
        D_004D2E28[2] = 1.0f;
        D_004D2E28[3] = 1.0f;
        D_004D2E38[0] = 1.0f;
        D_004D2E38[1] = 0.8613290190696716f;
        D_004D2E38[2] = 0.38124799728393555f;
        D_004D2E38[3] = 0.0f;
        D_004D2E48[0] = 1.0f;
        D_004D2E48[1] = 1.0f;
        D_004D2E48[2] = 1.0f;
        D_004D2E48[3] = 1.0f;
        D_004D2E58[0] = 1.0f;
        D_004D2E58[1] = 0.3244380056858063f;
        D_004D2E58[2] = 1.0f;
        D_004D2E58[3] = 0.0f;
        D_004D2E68[0] = 1.0f;
        D_004D2E68[1] = 1.0f;
        D_004D2E68[2] = 1.0f;
        D_004D2E68[3] = 1.0f;
        D_004D2E78[0] = 1.0f;
        D_004D2E78[1] = 1.0f;
        D_004D2E78[2] = 0.0f;
        D_004D2E78[3] = 0.0f;
        D_004D2E88[0] = 0.7007060050964355f;
        D_004D2E88[1] = 0.0f;
        D_004D2E88[2] = 0.0f;
        D_004D2E88[3] = 0.0f;
        D_004D2E98[0] = 1.0f;
        D_004D2E98[1] = 0.7828530073165894f;
        D_004D2E98[2] = 0.06140600144863129f;
        D_004D2E98[3] = 0.04146299883723259f;
        D_004D2EA8[0] = 1.0f;
        D_004D2EA8[1] = 0.32487601041793823f;
        D_004D2EA8[2] = 1.0f;
        D_004D2EA8[3] = 0.35280099511146545f;
        D_004D2EB8[0] = 1.0f;
        D_004D2EB8[1] = 1.0f;
        D_004D2EB8[2] = 0.7977359890937805f;
        D_004D2EB8[3] = 0.0f;
        D_004D2EC8[0] = 1.0f;
        D_004D2EC8[1] = 0.4937489926815033f;
        D_004D2EC8[2] = 1.0f;
        D_004D2EC8[3] = 0.49179700016975403f;
        D_004D2ED8[0] = 1.0f;
        D_004D2ED8[1] = 1.0f;
        D_004D2ED8[2] = 1.0f;
        D_004D2ED8[3] = 1.0f;
        D_004D2EE8[0] = 1.0f;
        D_004D2EE8[1] = 0.800000011920929f;
        D_004D2EE8[2] = 1.0f;
        D_004D2EE8[3] = 0.800000011920929f;
        D_004D2EF8[0] = 1.0f;
        D_004D2EF8[1] = 1.0f;
        D_004D2EF8[2] = 0.0f;
        D_004D2EF8[3] = 0.0f;
        D_004D2F08[0] = 1.0f;
        D_004D2F08[1] = 1.0f;
        D_004D2F08[2] = 0.0f;
        D_004D2F08[3] = 0.0f;
        D_004D2F18[0] = 1.0f;
        D_004D2F18[1] = 1.0f;
        D_004D2F18[2] = 0.0f;
        D_004D2F18[3] = 0.0f;
        D_004D2F28[0] = 1.0f;
        D_004D2F28[1] = 0.3273420035839081f;
        D_004D2F28[2] = 1.0f;
        D_004D2F28[3] = 0.35390499234199524f;
        D_004D2F38[0] = 1.0f;
        D_004D2F38[1] = 1.0f;
        D_004D2F38[2] = 0.061000000685453415f;
        D_004D2F38[3] = 0.039000000804662704f;
        D_004D2F48[0] = 1.0f;
        D_004D2F48[1] = 1.0f;
        D_004D2F48[2] = 0.7999979853630066f;
        D_004D2F48[3] = 0.0f;
        D_004D2F58[0] = 1.0f;
        D_004D2F58[1] = 0.9589840173721313f;
        D_004D2F58[2] = 0.6143789887428284f;
        D_004D2F58[3] = 0.0f;
        D_004D2F68[0] = 1.0f;
        D_004D2F68[1] = 0.9285150170326233f;
        D_004D2F68[2] = 0.3399839997291565f;
        D_004D2F68[3] = 0.0f;
        D_004D2F78[0] = 1.0f;
        D_004D2F78[1] = 0.8738250136375427f;
        D_004D2F78[2] = 0.24931700527668f;
        D_004D2F78[3] = 0.017578000202775f;
        D_004D2F88[0] = 1.0f;
        D_004D2F88[1] = 0.7843739986419678f;
        D_004D2F88[2] = 0.06132800132036209f;
        D_004D2F88[3] = 0.03945299983024597f;
        D_004D2F98[0] = 1.0f;
        D_004D2F98[1] = 0.0f;
        D_004D2F98[2] = 1.0f;
        D_004D2F98[3] = 0.0f;
        D_004D2FA8[0] = 1.0f;
        D_004D2FA8[1] = 1.0f;
        D_004D2FA8[2] = 0.0f;
        D_004D2FA8[3] = 0.0f;
        *(char*)&D_004A50D8 = -1;
        D_004A50D8 = (D_004A50D8 & 0xFF) | 0xFFFFFF00u;
        D_004A50E4 = 0;
        D_004A50E0 = 0;
        initE(D_004A50E8, 0);
        initE(D_004A50F0, 1);
        initE(D_004A50F8, 2);
        initE(D_004A5100, 3);
        initE(D_004A5108, 4);
        initE(D_004A5110, 5);
        initE(D_004A5118, 6);
        initE(D_004A5120, 7);
        initE(D_004A5128, 8);
        initE(D_004A5130, 9);
        initE(D_004A5138, 10);
        initE(D_004A5140, 11);
        initE(D_004A5148, 12);
        initE(D_004A5150, 13);
    }
}
#endif

extern "C" void func_00255840(void* self);

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267D88);
#ifdef SKIP_ASM
extern "C" int func_00267D88(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267D90);
#ifdef SKIP_ASM
extern "C" void func_00267D90(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = 1;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DA0);
#ifdef SKIP_ASM
extern "C" int func_00267DA0(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DA8__FPv);
#ifdef SKIP_ASM
void func_00267DA8(void* self)
{
    func_00255840(self);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DC8__FPv);
#ifdef SKIP_ASM
void func_00267DC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DD0__FPv);
#ifdef SKIP_ASM
int func_00267DD0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DD8);
#ifdef SKIP_ASM
extern "C" float func_00267DD8(void)
{
    return 0.01666666753590107f;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DE8__FPv);
#ifdef SKIP_ASM
int func_00267DE8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DF0__FPv);
#ifdef SKIP_ASM
int func_00267DF0(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267DF8__FPv);
#ifdef SKIP_ASM
int func_00267DF8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267E00);
#ifdef SKIP_ASM
extern "C" int func_00267E00(void* self)
{
    return *(int*)((char*)self + 0xc) == 2;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267E10__FPv);
#ifdef SKIP_ASM
int func_00267E10(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267E18);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00267E18(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267E48);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_004812B0[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00267E48(int* self)
{
    int* p = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    int v = *self;
    *(void***)((char*)p + 0x4) = D_004812B0;
    p[0] = v;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267E98);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00267E98(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267EC8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481290[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00267EC8(void* self)
{
    int* p = (int*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    int v = *(int*)((char*)self + 0x8);
    p[0] = 0x102;
    *(void***)((char*)p + 0x4) = D_00481290;
    p[2] = v;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267F28);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00267F28(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267F58);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481290[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00267F58(void* self)
{
    int* p = (int*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    int v = *(int*)((char*)self + 0x8);
    p[0] = 0x102;
    *(void***)((char*)p + 0x4) = D_00481290;
    p[2] = v;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267FB8);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00267FB8(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00267FE8);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481250[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00267FE8(void* self)
{
    int* p = (int*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    int v = *(int*)((char*)self + 0x8);
    p[0] = 0x116;
    *(void***)((char*)p + 0x4) = D_00481250;
    p[2] = v;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268048);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_00268048(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0xC, 2);
    cBXString__cBXString((char*)self + 0x8, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002680A8);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern char D_00480498[];
extern void* D_00481230[];

// Stand-in for cBXString (defined elsewhere): a class with a non-trivial copy constructor,
// which g++ keeps in memory (BLKmode, 16-byte stack slots).
struct sBXStrK2 {
    char* s;
    sBXStrK2() {}
    sBXStrK2(const sBXStrK2& o);
};

// Clone of a two-string message (type 0xDE).
extern "C" void* func_002680A8(char* self)
{
    char* p = (char*)cMemMan_alloc(0x10, D_00480498, 0x20000000, 0);
    sBXStrK2 a;
    sBXStrK2 b;
    cBXString_cBXString1(&a, self + 0x8);
    cBXString_cBXString1(&b, self + 0xC);
    *(void***)(p + 0x4) = D_00481230;
    *(int*)p = 0xDE;
    cBXString_cBXString1(p + 0x8, &a);
    cBXString_cBXString1(p + 0xC, &b);
    cBXString__cBXString(&a, 2);
    cBXString__cBXString(&b, 2);
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268158);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_00268158(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0x8, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002681B0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481210[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString2(void* self, const char* s);

extern "C" void* func_002681B0(void* self)
{
    int* p = (int*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    const char* s = *(const char**)((char*)self + 0x8);
    *(void***)((char*)p + 0x4) = D_00481210;
    p[0] = 0xE2;
    cBXString_cBXString2((char*)p + 0x8, s);
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268210);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00268210(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268240);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_004811F0[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00268240(void* self)
{
    int* p = (int*)cMemMan_alloc(0x10, D_00480488, 0x20000000, 0);
    int b = *(int*)((char*)self + 0xC);
    p[0] = 0x102;
    p[2] = 0x746F6F79;
    *(void***)((char*)p + 0x4) = D_004811F0;
    p[3] = b;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002682A8);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_002682A8(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0x10, 2);
    cBXString__cBXString((char*)self + 0xC, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268308);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern char D_00480488[];
extern char D_004811D0[];

struct sLockMsg268308 {
    int type;       // 0x00
    char* name;     // 0x04
    int tag;        // 0x08
    char a[4];      // 0x0C
    char b[4];      // 0x10
};

static inline void Init268308(sLockMsg268308* m, const char* a, const char* b)
{
    m->type = 0x102;
    m->tag = 0x6C6F636B;
    m->name = D_004811D0;
    cBXString_cBXString2(m->a, a);
    cBXString_cBXString2(m->b, b);
}

// Builds a "lock" message carrying the two name strings of this request.
extern "C" void* func_00268308(char* self)
{
    sLockMsg268308* m = (sLockMsg268308*)operator new(0x14, D_00480488, 0x20000000, 0);
    Init268308(m, *(const char**)(self + 0xC), *(const char**)(self + 0x10));
    return m;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268398);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_00268398(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0xC, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002683F0);
#ifdef SKIP_ASM
extern void* D_004811B0[];

extern "C" void* func_002683F0(void* self)
{
    int* p = (int*)cMemMan_alloc(0x10, D_00480488, 0x20000000, 0);
    const char* s = *(const char**)((char*)self + 0xC);
    p[2] = 0x646F776E;
    *(void***)((char*)p + 0x4) = D_004811B0;
    p[0] = 0x102;
    cBXString_cBXString2((char*)p + 0xC, s);
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268460);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_00268460(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0xC, 2);
    cBXString__cBXString((char*)self + 0x8, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002684C0);
#ifdef SKIP_ASM
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* cBXString_cBXString2(void* self, const char* s);
extern char D_00480488[];
extern void* D_00481190[];

struct sBlk2684C0 {
    int v[5];
};

struct sMsg2684C0 {
    int type;           // 0x00
    void** vt;          // 0x04
    char a[4];          // 0x08
    char b[4];          // 0x0C
    int f10;            // 0x10
    int f14;            // 0x14
    sBlk2684C0 blk;     // 0x18
};

static inline void Init2684C0(sMsg2684C0* m, const char* a, const char* b, int c, int d)
{
    m->type = 0xE3;
    m->vt = D_00481190;
    cBXString_cBXString2(m->a, a);
    cBXString_cBXString2(m->b, b);
    m->f10 = c;
    m->f14 = d;
}

// Clones a 0xE3 message (strings, ids and trailing data block).
extern "C" void* func_002684C0(sMsg2684C0* src)
{
    sMsg2684C0* m = (sMsg2684C0*)operator new(0x2C, D_00480488, 0x20000000, 0);
    Init2684C0(m, *(const char**)src->a, *(const char**)src->b, src->f10, src->f14);
    m->blk = src->blk;
    return m;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268588);
#ifdef SKIP_ASM
extern void* D_004812B0[];
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);

extern "C" void func_00268588(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0x8, 2);
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002685E0);
#ifdef SKIP_ASM
extern void* D_00481170[];

extern "C" void* func_002685E0(void* self)
{
    int* p = (int*)cMemMan_alloc(0x10, D_00480488, 0x20000000, 0);
    int b = *(int*)((char*)self + 0xC);
    const char* s = *(const char**)((char*)self + 0x8);
    *(void***)((char*)p + 0x4) = D_00481170;
    p[0] = 0xE5;
    cBXString_cBXString2((char*)p + 0x8, s);
    p[3] = b;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268658);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00268658(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268688);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481150[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

extern "C" void* func_00268688(void* self)
{
    int* p = (int*)cMemMan_alloc(0x10, D_00480488, 0x20000000, 0);
    int a = *(int*)((char*)self + 0x8);
    int b = *(int*)((char*)self + 0xC);
    p[0] = 0xFB;
    *(void***)((char*)p + 0x4) = D_00481150;
    p[2] = a;
    p[3] = b;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002686F0);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_002686F0(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268720);
#ifdef SKIP_ASM
extern void* D_00481130[];

extern "C" void* func_00268720(void* self)
{
    int* p = (int*)cMemMan_alloc(0x14, D_00480488, 0x20000000, 0);
    int a = *(int*)((char*)self + 0x8);
    int b = *(int*)((char*)self + 0xC);
    int c = *(int*)((char*)self + 0x10);
    p[0] = 0xFC;
    *(void***)((char*)p + 0x4) = D_00481130;
    p[2] = a;
    p[3] = b;
    p[4] = c;
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_00268790);
#ifdef SKIP_ASM
extern void* D_004812B0[];
void operator_delete(int*);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_00268790(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004812B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("dirtysock/tagsunk", func_002687C0);
#ifdef SKIP_ASM
extern char D_00480488[];
extern void* D_00481110[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);

struct sDsBlob14K2b {
    int v[5];
};

// Clone of a message of type 0x10D (three names, two ints, a 20-byte blob).
extern "C" void* func_002687C0(char* self)
{
    char* p = (char*)cMemMan_alloc(0x164, D_00480488, 0x20000000, 0);
    const char* b = self + 0x28;
    int x = *(int*)(self + 0x148);
    int y = *(int*)(self + 0x14C);
    const char* c;
    *(void***)(p + 0x4) = D_00481110;
    *(int*)p = 0x10D;
    c = self + 0x48;
    *(int*)(p + 0x148) = x;
    *(int*)(p + 0x14C) = y;
    strcpy(p + 0x8, self + 0x8);
    strcpy(p + 0x28, b);
    strcpy(p + 0x48, c);
    *(sDsBlob14K2b*)(p + 0x150) = *(sDsBlob14K2b*)(self + 0x150);
    return p;
}
#endif

