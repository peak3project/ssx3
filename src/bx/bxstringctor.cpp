#include "common.h"

extern void* D_004A3E90;

struct cBXString2 {
    void* field_0x0;
    void* field_0x4;
    void* field_0x8;
    void* field_0xC;
    void* field_0x10;
    void* arr[4]; // 0x14-0x23
};

//100%
INCLUDE_ASM("bx/bxstringctor", cBXString_cBXString__FP10cBXString2);
#ifdef SKIP_ASM
struct cBXStrK2 {
    void* str;
};

cBXString2* cBXString_cBXString(cBXString2* self)
{
    self->field_0x0 = D_004A3E90;
    self->field_0x4 = D_004A3E90;
    self->field_0x8 = D_004A3E90;
    self->field_0xC = D_004A3E90;
    self->field_0x10 = D_004A3E90;
    cBXStrK2* p = (cBXStrK2*)self->arr;
    for (int i = 3; i != -1; i--, p++) {
        p->str = D_004A3E90;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_002688E0);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);
extern char D_0046D8C0[];

extern "C" void func_002688E0(void* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0046D8C0;
    cBXString__cBXString((char*)self + 8, 2);
    cBXString__cBXString((char*)self + 4, 2);
    cBXString__cBXString(self, 2);
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268950);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
void operator_delete(int*);
extern char D_004810E0[];

extern "C" void func_00268950(void* self, int flags)
{
    *(void**)((char*)self + 0x3C) = D_004810E0;
    cBXString__cBXString((char*)self + 4, 2);
    cBXString__cBXString(self, 2);
    if (flags & 1)
    {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("bx/bxstringctor", func_002689B8);

// padded past the 8-byte gp-relative threshold so the compiler emits
// absolute lui/lo addressing like the target
struct sShortPad16 { short v; int pad[3]; };
extern sShortPad16 D_004A2FB0;
extern "C" void func_0025D6C0(int);

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268A80);
#ifdef SKIP_ASM
extern "C" int func_00268A80(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("bx/bxstringctor", func_00268A88);
#ifdef SKIP_ASM
extern "C" int func_00268A88(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268A90);
#ifdef SKIP_ASM
extern "C" void func_00268A90(void* self, void* a1, int a2)
{
    func_0025D6C0(a2 + D_004A2FB0.v);
}
#endif

extern sShortPad16 D_004A2FB8;
extern "C" void func_002599B0(int);

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268AB8);
#ifdef SKIP_ASM
extern "C" void func_00268AB8(void* self, void* a1, int a2)
{
    func_002599B0(a2 + D_004A2FB8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268AE0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A2FC0;
extern "C" void func_00259A60(int);

extern "C" void func_00268AE0(void* self, void* a1, int a2)
{
    func_00259A60(a2 + D_004A2FC0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268B08);
#ifdef SKIP_ASM
extern sShortPad16 D_004A2FF0;
void* func_002598A8(void* self);

extern "C" void func_00268B08(void* self, void* a1, char* a2)
{
    func_002598A8(a2 + D_004A2FF0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268B30);
#ifdef SKIP_ASM
extern sShortPad16 D_004A2FF8;
extern "C" void func_00259B10(int);

extern "C" void func_00268B30(void* self, void* a1, int a2)
{
    func_00259B10(a2 + D_004A2FF8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268B58);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3000;
extern "C" void func_002598C8(int);

extern "C" void func_00268B58(void* self, void* a1, int a2)
{
    func_002598C8(a2 + D_004A3000.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268B80);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3008;
extern "C" void func_0025A1D0(int);

extern "C" void func_00268B80(void* self, void* a1, int a2)
{
    func_0025A1D0(a2 + D_004A3008.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268BA8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3020;
extern "C" void func_0025B848(int);

extern "C" void func_00268BA8(void* self, void* a1, int a2)
{
    func_0025B848(a2 + D_004A3020.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268BD0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3088;
extern "C" void func_0025BD30(int);

extern "C" void func_00268BD0(void* self, void* a1, int a2)
{
    func_0025BD30(a2 + D_004A3088.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268BF8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A30A8;
extern "C" void func_0025C0C0(int);

extern "C" void func_00268BF8(void* self, void* a1, int a2)
{
    func_0025C0C0(a2 + D_004A30A8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268C20);
#ifdef SKIP_ASM
extern sShortPad16 D_004A30B0;
extern "C" void func_0025C2D8(int);

extern "C" void func_00268C20(void* self, void* a1, int a2)
{
    func_0025C2D8(a2 + D_004A30B0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268C48);
#ifdef SKIP_ASM
extern sShortPad16 D_004A30B8;
extern "C" void func_0025C4F0(int);

extern "C" void func_00268C48(void* self, void* a1, int a2)
{
    func_0025C4F0(a2 + D_004A30B8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268C70);
#ifdef SKIP_ASM
extern sShortPad16 D_004A30E8;
extern "C" void func_0025C8A8(int);

extern "C" void func_00268C70(void* self, void* a1, int a2)
{
    func_0025C8A8(a2 + D_004A30E8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268C98);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3118;
extern "C" void func_0025CEB0(int);

extern "C" void func_00268C98(void* self, void* a1, int a2)
{
    func_0025CEB0(a2 + D_004A3118.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268CC0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3120;
extern "C" void func_0025D048(int);

extern "C" void func_00268CC0(void* self, void* a1, int a2)
{
    func_0025D048(a2 + D_004A3120.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268CE8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3138;
extern "C" void func_0025D2D8(int);

extern "C" void func_00268CE8(void* self, void* a1, int a2)
{
    func_0025D2D8(a2 + D_004A3138.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268D10);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3140;
extern "C" void func_0025D538(int);

extern "C" void func_00268D10(void* self, void* a1, int a2)
{
    func_0025D538(a2 + D_004A3140.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268D38);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3148;
extern "C" void func_0025D8F8(int);

extern "C" void func_00268D38(void* self, void* a1, int a2)
{
    func_0025D8F8(a2 + D_004A3148.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268D60);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3158;
extern "C" void func_0025DB80(int);

extern "C" void func_00268D60(void* self, void* a1, int a2)
{
    func_0025DB80(a2 + D_004A3158.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268D88);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3160;
extern "C" void func_0025DDE0(int);

extern "C" void func_00268D88(void* self, void* a1, int a2)
{
    func_0025DDE0(a2 + D_004A3160.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268DB0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3170;
extern "C" void func_0025DF98(int);

extern "C" void func_00268DB0(void* self, void* a1, int a2)
{
    func_0025DF98(a2 + D_004A3170.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268DD8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3178;
extern "C" void func_0025E138(int);

extern "C" void func_00268DD8(void* self, void* a1, int a2)
{
    func_0025E138(a2 + D_004A3178.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268E00);
#ifdef SKIP_ASM
extern sShortPad16 D_004A31B0;
extern "C" void func_0025E590(int);

extern "C" void func_00268E00(void* self, void* a1, int a2)
{
    func_0025E590(a2 + D_004A31B0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268E28);
#ifdef SKIP_ASM
extern sShortPad16 D_004A31B8;
extern "C" void func_0025E7F0(int);

extern "C" void func_00268E28(void* self, void* a1, int a2)
{
    func_0025E7F0(a2 + D_004A31B8.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268E50);
#ifdef SKIP_ASM
extern sShortPad16 D_004A31D0;
extern "C" void func_0025EB00(int);

extern "C" void func_00268E50(void* self, void* a1, int a2)
{
    func_0025EB00(a2 + D_004A31D0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268E78);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3210;
extern "C" void func_0025F030(int);

extern "C" void func_00268E78(void* self, void* a1, int a2)
{
    func_0025F030(a2 + D_004A3210.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268EA0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3248;
extern "C" void func_0025F8A0(int);

extern "C" void func_00268EA0(void* self, void* a1, int a2)
{
    func_0025F8A0(a2 + D_004A3248.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268EC8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3268;
void func_0025FC20(void* self);

extern "C" void func_00268EC8(void* self, void* a1, char* a2)
{
    func_0025FC20(a2 + D_004A3268.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268EF0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3318;
extern "C" void func_00260C68(int);

extern "C" void func_00268EF0(void* self, void* a1, int a2)
{
    func_00260C68(a2 + D_004A3318.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268F18);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3340;
extern "C" void func_002615C8(int);

extern "C" void func_00268F18(void* self, void* a1, int a2)
{
    func_002615C8(a2 + D_004A3340.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268F40);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3348;
extern "C" void func_00261A28(int);

extern "C" void func_00268F40(void* self, void* a1, int a2)
{
    func_00261A28(a2 + D_004A3348.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268F68);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3350;
extern "C" void func_00261770(int);

extern "C" void func_00268F68(void* self, void* a1, int a2)
{
    func_00261770(a2 + D_004A3350.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268F90);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3380;
extern "C" void func_00261970(int);

extern "C" void func_00268F90(void* self, void* a1, int a2)
{
    func_00261970(a2 + D_004A3380.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268FB8);
#ifdef SKIP_ASM
extern sShortPad16 D_004A3388;
extern "C" void func_002618C0(int);

extern "C" void func_00268FB8(void* self, void* a1, int a2)
{
    func_002618C0(a2 + D_004A3388.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00268FE0);
#ifdef SKIP_ASM
extern sShortPad16 D_004A33A0;
void func_00261A20(void* self);

extern "C" void func_00268FE0(void* self, void* a1, char* a2)
{
    func_00261A20(a2 + D_004A33A0.v);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269008);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_00264CF0(void* self, int a1);
extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_00269008 {
    sMsgListNode_00269008* next;
    sMsgListNode_00269008* prev;
    void* data;
};

struct sMsgListIter_00269008 {
    sMsgListNode_00269008* node;
    sMsgListIter_00269008(sMsgListNode_00269008* x) : node(x) {}
    sMsgListIter_00269008(const sMsgListIter_00269008& x) : node(x.node) {}
};

static inline sMsgListIter_00269008 sMsgList_00269008_insert(sMsgListIter_00269008 pos, void* const& x)
{
    sMsgListNode_00269008* tmp = (sMsgListNode_00269008*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00269008(void* self, int a1, int a2)
{
    int kind = 0xF3;
    *(int*)self = a2;
    func_00264CF0(self, a1);
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_00269008_insert(*(sMsgListNode_00269008**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_002690C8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_00264CF0(void* self, int a1);
extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_002690C8 {
    sMsgListNode_002690C8* next;
    sMsgListNode_002690C8* prev;
    void* data;
};

struct sMsgListIter_002690C8 {
    sMsgListNode_002690C8* node;
    sMsgListIter_002690C8(sMsgListNode_002690C8* x) : node(x) {}
    sMsgListIter_002690C8(const sMsgListIter_002690C8& x) : node(x.node) {}
};

static inline sMsgListIter_002690C8 sMsgList_002690C8_insert(sMsgListIter_002690C8 pos, void* const& x)
{
    sMsgListNode_002690C8* tmp = (sMsgListNode_002690C8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_002690C8(void* self, int a1, int a2)
{
    int kind = 0xF4;
    *(int*)self = a2;
    func_00264CF0(self, a1);
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_002690C8_insert(*(sMsgListNode_002690C8**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269188);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_00269188 {
    sMsgListNode_00269188* next;
    sMsgListNode_00269188* prev;
    void* data;
};

struct sMsgListIter_00269188 {
    sMsgListNode_00269188* node;
    sMsgListIter_00269188(sMsgListNode_00269188* x) : node(x) {}
    sMsgListIter_00269188(const sMsgListIter_00269188& x) : node(x.node) {}
};

static inline sMsgListIter_00269188 sMsgList_00269188_insert(sMsgListIter_00269188 pos, void* const& x)
{
    sMsgListNode_00269188* tmp = (sMsgListNode_00269188*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsgSelf_00269188 {
    int f0;
};

extern "C" void func_00269188(void* self, int a1)
{
    int kind = 0xF7;
    ((sMsgSelf_00269188*)self)->f0 = a1;
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_00269188_insert(*(sMsgListNode_00269188**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269240);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_00264D80(void* self, int a1, void* a2);
extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_00269240 {
    sMsgListNode_00269240* next;
    sMsgListNode_00269240* prev;
    void* data;
};

struct sMsgListIter_00269240 {
    sMsgListNode_00269240* node;
    sMsgListIter_00269240(sMsgListNode_00269240* x) : node(x) {}
    sMsgListIter_00269240(const sMsgListIter_00269240& x) : node(x.node) {}
};

static inline sMsgListIter_00269240 sMsgList_00269240_insert(sMsgListIter_00269240 pos, void* const& x)
{
    sMsgListNode_00269240* tmp = (sMsgListNode_00269240*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00269240(void* self, int a1, int a2, void* a3)
{
    int kind = 0xF3;
    *(int*)self = a2;
    func_00264D80(self, a1, a3);
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_00269240_insert(*(sMsgListNode_00269240**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269300);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_00264D80(void* self, int a1, void* a2);
extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_00269300 {
    sMsgListNode_00269300* next;
    sMsgListNode_00269300* prev;
    void* data;
};

struct sMsgListIter_00269300 {
    sMsgListNode_00269300* node;
    sMsgListIter_00269300(sMsgListNode_00269300* x) : node(x) {}
    sMsgListIter_00269300(const sMsgListIter_00269300& x) : node(x.node) {}
};

static inline sMsgListIter_00269300 sMsgList_00269300_insert(sMsgListIter_00269300 pos, void* const& x)
{
    sMsgListNode_00269300* tmp = (sMsgListNode_00269300*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

extern "C" void func_00269300(void* self, int a1, int a2)
{
    int kind = 0xF5;
    *(int*)self = a2;
    func_00264D80(self, a1, 0);
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_00269300_insert(*(sMsgListNode_00269300**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_002693C0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");

extern const char D_00480488[];
extern const char D_004804A8[];
extern void* D_004812B0[];
extern char* D_004A3028;

struct sMsgListNode_002693C0 {
    sMsgListNode_002693C0* next;
    sMsgListNode_002693C0* prev;
    void* data;
};

struct sMsgListIter_002693C0 {
    sMsgListNode_002693C0* node;
    sMsgListIter_002693C0(sMsgListNode_002693C0* x) : node(x) {}
    sMsgListIter_002693C0(const sMsgListIter_002693C0& x) : node(x.node) {}
};

static inline sMsgListIter_002693C0 sMsgList_002693C0_insert(sMsgListIter_002693C0 pos, void* const& x)
{
    sMsgListNode_002693C0* tmp = (sMsgListNode_002693C0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsgSelf_002693C0 {
    int f0;
};

extern "C" void func_002693C0(void* self, int a1)
{
    int kind = 0xF7;
    ((sMsgSelf_002693C0*)self)->f0 = a1;
    char* g = D_004A3028;
    int* m = (int*)cMemMan_alloc(8, D_00480488, 0x20000000, 0);
    m[0] = kind;
    *(void***)((char*)m + 0x4) = D_004812B0;
    void* mp = m;
    sMsgList_002693C0_insert(*(sMsgListNode_002693C0**)(g + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269478);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481150[];
extern char* D_004A3028;

struct sMsgListNode_00269478 {
    sMsgListNode_00269478* next;
    sMsgListNode_00269478* prev;
    void* data;
};

struct sMsgListIter_00269478 {
    sMsgListNode_00269478* node;
    sMsgListIter_00269478(sMsgListNode_00269478* x) : node(x) {}
    sMsgListIter_00269478(const sMsgListIter_00269478& x) : node(x.node) {}
};

static inline sMsgListIter_00269478 sMsgList_00269478_insert(sMsgListIter_00269478 pos, void* const& x)
{
    sMsgListNode_00269478* tmp = (sMsgListNode_00269478*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269478 {
    int kind;
    void** vt;
    int f8;
    int fC;
};

extern "C" void func_00269478(void* self, int a1)
{
    sMsg_00269478* m = (sMsg_00269478*)cMemMan_alloc(0x10, D_00480F18, 0x20000000, 0);
    m->kind = 0xFB;
    m->vt = D_00481150;
    m->f8 = 1;
    m->fC = a1;
    void* mp = m;
    sMsgList_00269478_insert(*(sMsgListNode_00269478**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269538);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481130[];
extern char* D_004A3028;

struct sMsgListNode_00269538 {
    sMsgListNode_00269538* next;
    sMsgListNode_00269538* prev;
    void* data;
};

struct sMsgListIter_00269538 {
    sMsgListNode_00269538* node;
    sMsgListIter_00269538(sMsgListNode_00269538* x) : node(x) {}
    sMsgListIter_00269538(const sMsgListIter_00269538& x) : node(x.node) {}
};

static inline sMsgListIter_00269538 sMsgList_00269538_insert(sMsgListIter_00269538 pos, void* const& x)
{
    sMsgListNode_00269538* tmp = (sMsgListNode_00269538*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269538 {
    int kind;
    void** vt;
    int f8;
    int fC;
    int f10;
};

extern "C" void func_00269538(void* self, int a1, int a2)
{
    sMsg_00269538* m = (sMsg_00269538*)cMemMan_alloc(0x14, D_00480F18, 0x20000000, 0);
    m->kind = 0xFC;
    m->vt = D_00481130;
    m->f8 = 1;
    m->fC = a1;
    m->f10 = a2;
    void* mp = m;
    sMsgList_00269538_insert(*(sMsgListNode_00269538**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269608);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern "C" void func_00264E50(void* self, int event, int a2, int state);
extern const char D_004804A8[];
extern char D_004813E0[];
extern char* D_004A3028;

struct sMsgListNode_00269608 {
    sMsgListNode_00269608* next;
    sMsgListNode_00269608* prev;
    void* data;
};

struct sMsgListIter_00269608 {
    sMsgListNode_00269608* node;
    sMsgListIter_00269608(sMsgListNode_00269608* x) : node(x) {}
    sMsgListIter_00269608(const sMsgListIter_00269608& x) : node(x.node) {}
};

static inline sMsgListIter_00269608 sMsgList_00269608_insert(sMsgListIter_00269608 pos, void* const& x)
{
    sMsgListNode_00269608* tmp = (sMsgListNode_00269608*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269608 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_00269608(void* self)
{
    switch (*(int*)self)
    {
    case 6:
    case 7:
        *(int*)self = 8;
        break;
    case 9:
        *(int*)self = 10;
        break;
    }
    func_00264E50(self, 0xB, *(int*)self, 0);
    sMsg_00269608* m = (sMsg_00269608*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFD;
    m->vt = D_004813E0;
    m->f8 = 1;
    void* mp = m;
    sMsgList_00269608_insert(*(sMsgListNode_00269608**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_002696F8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern "C" void func_00264E50(void* self, int event, int a2, int state);
extern const char D_004804A8[];
extern char D_004813C0[];
extern char* D_004A3028;

struct sMsgListNode_002696F8 {
    sMsgListNode_002696F8* next;
    sMsgListNode_002696F8* prev;
    void* data;
};

struct sMsgListIter_002696F8 {
    sMsgListNode_002696F8* node;
    sMsgListIter_002696F8(sMsgListNode_002696F8* x) : node(x) {}
    sMsgListIter_002696F8(const sMsgListIter_002696F8& x) : node(x.node) {}
};

static inline sMsgListIter_002696F8 sMsgList_002696F8_insert(sMsgListIter_002696F8 pos, void* const& x)
{
    sMsgListNode_002696F8* tmp = (sMsgListNode_002696F8*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_002696F8 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_002696F8(void* self)
{
    if (*(int*)self == 8)
        *(int*)self = 7;
    func_00264E50(self, 0xC, *(int*)self, 0);
    sMsg_002696F8* m = (sMsg_002696F8*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFE;
    m->vt = D_004813C0;
    m->f8 = 1;
    void* mp = m;
    sMsgList_002696F8_insert(*(sMsgListNode_002696F8**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_002697D0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481150[];
extern char* D_004A3028;

struct sMsgListNode_002697D0 {
    sMsgListNode_002697D0* next;
    sMsgListNode_002697D0* prev;
    void* data;
};

struct sMsgListIter_002697D0 {
    sMsgListNode_002697D0* node;
    sMsgListIter_002697D0(sMsgListNode_002697D0* x) : node(x) {}
    sMsgListIter_002697D0(const sMsgListIter_002697D0& x) : node(x.node) {}
};

static inline sMsgListIter_002697D0 sMsgList_002697D0_insert(sMsgListIter_002697D0 pos, void* const& x)
{
    sMsgListNode_002697D0* tmp = (sMsgListNode_002697D0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_002697D0 {
    int kind;
    void* vt;
    int f8;
    int fC;
};

extern "C" void func_002697D0(void* self, int a1)
{
    sMsg_002697D0* m = (sMsg_002697D0*)cMemMan_alloc(0x10, D_00480F18, 0x20000000, 0);
    m->kind = 0xFB;
    m->vt = D_00481150;
    m->f8 = 1;
    m->fC = a1;
    void* mp = m;
    sMsgList_002697D0_insert(*(sMsgListNode_002697D0**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269890);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481150[];
extern char* D_004A3028;

struct sMsgListNode_00269890 {
    sMsgListNode_00269890* next;
    sMsgListNode_00269890* prev;
    void* data;
};

struct sMsgListIter_00269890 {
    sMsgListNode_00269890* node;
    sMsgListIter_00269890(sMsgListNode_00269890* x) : node(x) {}
    sMsgListIter_00269890(const sMsgListIter_00269890& x) : node(x.node) {}
};

static inline sMsgListIter_00269890 sMsgList_00269890_insert(sMsgListIter_00269890 pos, void* const& x)
{
    sMsgListNode_00269890* tmp = (sMsgListNode_00269890*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269890 {
    int kind;
    void* vt;
    int f8;
    int fC;
};

extern "C" void func_00269890(void* self, int a1)
{
    sMsg_00269890* m = (sMsg_00269890*)cMemMan_alloc(0x10, D_00480F18, 0x20000000, 0);
    m->kind = 0xFB;
    m->vt = D_00481150;
    m->f8 = 0;
    m->fC = a1;
    void* mp = m;
    sMsgList_00269890_insert(*(sMsgListNode_00269890**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269948);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481130[];
extern char* D_004A3028;

struct sMsgListNode_00269948 {
    sMsgListNode_00269948* next;
    sMsgListNode_00269948* prev;
    void* data;
};

struct sMsgListIter_00269948 {
    sMsgListNode_00269948* node;
    sMsgListIter_00269948(sMsgListNode_00269948* x) : node(x) {}
    sMsgListIter_00269948(const sMsgListIter_00269948& x) : node(x.node) {}
};

static inline sMsgListIter_00269948 sMsgList_00269948_insert(sMsgListIter_00269948 pos, void* const& x)
{
    sMsgListNode_00269948* tmp = (sMsgListNode_00269948*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269948 {
    int kind;
    void* vt;
    int f8;
    int fC;
    int f10;
};

extern "C" void func_00269948(void* self, int a1, int a2)
{
    sMsg_00269948* m = (sMsg_00269948*)cMemMan_alloc(0x14, D_00480F18, 0x20000000, 0);
    m->kind = 0xFC;
    m->vt = D_00481130;
    m->f8 = 1;
    m->fC = a1;
    m->f10 = a2;
    void* mp = m;
    sMsgList_00269948_insert(*(sMsgListNode_00269948**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269A18);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern void* D_00481130[];
extern char* D_004A3028;

struct sMsgListNode_00269A18 {
    sMsgListNode_00269A18* next;
    sMsgListNode_00269A18* prev;
    void* data;
};

struct sMsgListIter_00269A18 {
    sMsgListNode_00269A18* node;
    sMsgListIter_00269A18(sMsgListNode_00269A18* x) : node(x) {}
    sMsgListIter_00269A18(const sMsgListIter_00269A18& x) : node(x.node) {}
};

static inline sMsgListIter_00269A18 sMsgList_00269A18_insert(sMsgListIter_00269A18 pos, void* const& x)
{
    sMsgListNode_00269A18* tmp = (sMsgListNode_00269A18*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269A18 {
    int kind;
    void* vt;
    int f8;
    int fC;
    int f10;
};

extern "C" void func_00269A18(void* self, int a1, int a2)
{
    sMsg_00269A18* m = (sMsg_00269A18*)cMemMan_alloc(0x14, D_00480F18, 0x20000000, 0);
    m->kind = 0xFC;
    m->vt = D_00481130;
    m->f8 = 0;
    m->fC = a1;
    m->f10 = a2;
    void* mp = m;
    sMsgList_00269A18_insert(*(sMsgListNode_00269A18**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269AE0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern char D_004813E0[];
extern char* D_004A3028;

struct sMsgListNode_00269AE0 {
    sMsgListNode_00269AE0* next;
    sMsgListNode_00269AE0* prev;
    void* data;
};

struct sMsgListIter_00269AE0 {
    sMsgListNode_00269AE0* node;
    sMsgListIter_00269AE0(sMsgListNode_00269AE0* x) : node(x) {}
    sMsgListIter_00269AE0(const sMsgListIter_00269AE0& x) : node(x.node) {}
};

static inline sMsgListIter_00269AE0 sMsgList_00269AE0_insert(sMsgListIter_00269AE0 pos, void* const& x)
{
    sMsgListNode_00269AE0* tmp = (sMsgListNode_00269AE0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269AE0 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_00269AE0(void* self, int a1)
{
    *(int*)self = a1;
    sMsg_00269AE0* m = (sMsg_00269AE0*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFD;
    m->vt = D_004813E0;
    m->f8 = 1;
    void* mp = m;
    sMsgList_00269AE0_insert(*(sMsgListNode_00269AE0**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269B90);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern char D_004813E0[];
extern char* D_004A3028;

struct sMsgListNode_00269B90 {
    sMsgListNode_00269B90* next;
    sMsgListNode_00269B90* prev;
    void* data;
};

struct sMsgListIter_00269B90 {
    sMsgListNode_00269B90* node;
    sMsgListIter_00269B90(sMsgListNode_00269B90* x) : node(x) {}
    sMsgListIter_00269B90(const sMsgListIter_00269B90& x) : node(x.node) {}
};

static inline sMsgListIter_00269B90 sMsgList_00269B90_insert(sMsgListIter_00269B90 pos, void* const& x)
{
    sMsgListNode_00269B90* tmp = (sMsgListNode_00269B90*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269B90 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_00269B90(void* self, int a1)
{
    *(int*)self = a1;
    sMsg_00269B90* m = (sMsg_00269B90*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFD;
    m->vt = D_004813E0;
    m->f8 = 0;
    void* mp = m;
    sMsgList_00269B90_insert(*(sMsgListNode_00269B90**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269C40);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern char D_004813C0[];
extern char* D_004A3028;

struct sMsgListNode_00269C40 {
    sMsgListNode_00269C40* next;
    sMsgListNode_00269C40* prev;
    void* data;
};

struct sMsgListIter_00269C40 {
    sMsgListNode_00269C40* node;
    sMsgListIter_00269C40(sMsgListNode_00269C40* x) : node(x) {}
    sMsgListIter_00269C40(const sMsgListIter_00269C40& x) : node(x.node) {}
};

static inline sMsgListIter_00269C40 sMsgList_00269C40_insert(sMsgListIter_00269C40 pos, void* const& x)
{
    sMsgListNode_00269C40* tmp = (sMsgListNode_00269C40*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269C40 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_00269C40(void* self, int a1)
{
    *(int*)self = a1;
    sMsg_00269C40* m = (sMsg_00269C40*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFE;
    m->vt = D_004813C0;
    m->f8 = 1;
    void* mp = m;
    sMsgList_00269C40_insert(*(sMsgListNode_00269C40**)(D_004A3028 + 0xF0), mp);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269CF0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern const char D_00480F18[];
extern const char D_004804A8[];
extern char D_004813C0[];
extern char* D_004A3028;

struct sMsgListNode_00269CF0 {
    sMsgListNode_00269CF0* next;
    sMsgListNode_00269CF0* prev;
    void* data;
};

struct sMsgListIter_00269CF0 {
    sMsgListNode_00269CF0* node;
    sMsgListIter_00269CF0(sMsgListNode_00269CF0* x) : node(x) {}
    sMsgListIter_00269CF0(const sMsgListIter_00269CF0& x) : node(x.node) {}
};

static inline sMsgListIter_00269CF0 sMsgList_00269CF0_insert(sMsgListIter_00269CF0 pos, void* const& x)
{
    sMsgListNode_00269CF0* tmp = (sMsgListNode_00269CF0*)operator new(0xC, D_004804A8, 0x20000000, 0);
    void** data = &tmp->data;
    if (data != 0)
        *data = x;
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;
    return tmp;
}

struct sMsg_00269CF0 {
    int kind;
    void* vt;
    int f8;
};

extern "C" void func_00269CF0(void* self, int a1)
{
    *(int*)self = a1;
    sMsg_00269CF0* m = (sMsg_00269CF0*)cMemMan_alloc(0xC, D_00480F18, 0x20000000, 0);
    m->kind = 0xFE;
    m->vt = D_004813C0;
    m->f8 = 0;
    void* mp = m;
    sMsgList_00269CF0_insert(*(sMsgListNode_00269CF0**)(D_004A3028 + 0xF0), mp);
}
#endif

extern "C" void* func_00267E18(void* self);

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269DA0__FPv);
#ifdef SKIP_ASM
void* func_00269DA0(void* self)
{
    return func_00267E18(self);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269DC0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00480488[];
extern char D_004813E0[];

struct sNode00269DC0 {
    int kind;
    void* vtbl;
    int value;
};

extern "C" sNode00269DC0* func_00269DC0(void* self)
{
    sNode00269DC0* n = (sNode00269DC0*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    int v = *(int*)((char*)self + 8);
    n->kind = 0xFD;
    n->vtbl = D_004813E0;
    n->value = v;
    return n;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269E20__FPv);
#ifdef SKIP_ASM
void* func_00269E20(void* self)
{
    return func_00267E18(self);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269E40);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern const char D_00480488[];
extern char D_004813C0[];

struct sNode00269E40 {
    int kind;
    void* vtbl;
    int value;
};

extern "C" sNode00269E40* func_00269E40(void* self)
{
    sNode00269E40* n = (sNode00269E40*)cMemMan_alloc(0xC, D_00480488, 0x20000000, 0);
    int v = *(int*)((char*)self + 8);
    n->kind = 0xFE;
    n->vtbl = D_004813C0;
    n->value = v;
    return n;
}
#endif

extern "C" void* func_00267468(int, int);

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269EA0__FPv);
#ifdef SKIP_ASM
void* func_00269EA0(void* self)
{
    return func_00267468(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269EC0__FPv);
#ifdef SKIP_ASM
int func_00269EC0(void* self)
{
    int t0 = 0x2e;
    *(int*)((char*)self + 0x38) = t0;
    *(int*)((char*)self + 0x3c) = 1;
    return t0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269ED8);
#ifdef SKIP_ASM
extern "C" void func_0026BA68(void* p);

extern "C" void func_00269ED8(void* self, int a1, int id)
{
    if (id == 0x64) {
        func_0026BA68((char*)self + 0x38);
    } else if (id == 0x65) {
        func_0026BA68((char*)self + 0x3C);
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_00269F18);
#ifdef SKIP_ASM
struct sBXVec4K2 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct sBXPath;
// sBXVec4 (defined later in the unit) has this layout.
sBXVec4K2 func_0026AB20_K2(sBXPath* self, int* inRange, float t) __asm__("func_0026AB20");

struct sBXRangeK2 {
    int type;   // 0x0
    int pad_0x4;
    float lo;   // 0x8
    float hi;   // 0xC
};

struct sBXRangeListK2 {
    int count;            // 0x0
    sBXRangeK2* entries;  // 0x4
};

// PORT: >? and <? (g++ min/max operators).
extern "C" sBXVec4K2 func_00269F18(sBXPath* path, float* t)
{
    sBXRangeListK2* list = (sBXRangeListK2*)path;
    float hi = *t + 50.0f;
    float lo = hi;
    int i;
    for (i = 0; i < list->count; i++) {
        sBXRangeK2* e = &list->entries[i];
        if (*t < e->lo)
            continue;
        if (e->hi < *t)
            continue;
        if (e->type == 16)
            hi = e->hi >? hi;
        else if (e->type == 12)
            lo = e->lo <? lo;
        else if (e->type == 14)
            lo = e->hi >? lo;
    }
    if (lo != *t)
        *t = lo;
    else
        *t = hi;
    return func_0026AB20_K2(path, 0, *t);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A000);
#ifdef SKIP_ASM
struct sEntry_0026A000 {
    int type;
    int pad4;
    float lo;
    float hi;
};
struct sTable_0026A000 {
    int count;
    sEntry_0026A000* entries;
};

extern "C" int func_0026A000(sTable_0026A000* t, float x) {
    int i;
    for (i = 0; i < t->count; i++) {
        sEntry_0026A000* e = &t->entries[i];
        if (!(x < e->lo) && !(e->hi < x) && e->type == 0xD)
            return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A068__FPv);
#ifdef SKIP_ASM
void func_0026A068(void* self)
{
    *(int*)((char*)self + 0x38) = 0;
}
#endif

extern "C" void func_0026BA88(void*);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A070);
#ifdef SKIP_ASM
extern "C" void func_0026A070(void* self, int a1, int a2)
{
    if (a2 == 0) {
        func_0026BA88((char*)self + 0x38);
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A090);
#ifdef SKIP_ASM
struct sBXRange {
    int field_0x0;
    int field_0x4;
    float min; // 0x8
    float max; // 0xC
};

struct sBXRangeList {
    int count;          // 0x0
    sBXRange* items;    // 0x4
    char pad_0x08[0x30];
    float field_0x38;   // 0x38
};

extern "C" int func_0026AA80(sBXRangeList* self, sBXRange* out, int maxOut, float lo, float hi);

extern "C" int func_0026A090(sBXRangeList* self, sBXRange* out, int maxOut, float a, float b)
{
    float base = self->field_0x38;
    return func_0026AA80(self, out, maxOut, base - a, base - b);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A0B8);
#ifdef SKIP_ASM
extern "C" float func_0026AC48(void* self);
extern "C" int func_0026AC88(sBXRangeList* self, float lo, float hi);

extern "C" int func_0026A0B8(sBXRangeList* self, float a, float b)
{
    float lo;
    float hi;
    if (a >= 0.0f)
        lo = self->field_0x38 - a;
    else
        lo = 0.0f;
    if (b < 0.0f)
        hi = func_0026AC48(self);
    else
        hi = self->field_0x38 - b;
    return func_0026AC88(self, lo, hi);
}
#endif

INCLUDE_ASM("bx/bxstringctor", func_0026A138);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A180);
#ifdef SKIP_ASM
// PORT: func_0026BA68 takes (dst, src); the unit declares it with one arg
void func_0026BA68_A180(void* dst, void* src) __asm__("func_0026BA68");
extern "C" void func_0026BA48(void* p, void* q);
extern "C" void func_0026A338(void* self, void* src, void* dst);
extern "C" void func_0026A378(void* self, char* src, int* dst);

struct sVE0_26A180 { short delta; short index; void (*fn)(void*); };
struct sVE1_26A180 { short delta; short index; void (*fn)(void*, char*, int, int); };

struct sBXStr_26A180
{
    int count2;         // 0x0
    char* items2;       // 0x4
    int count1;         // 0x8
    char vecA[0xC];     // 0xC
    char* items1;       // 0x18
    char vecB[0xC];     // 0x1C
    char vecC[0xC];     // 0x28
    void* vt;           // 0x34
};

extern "C" int func_0026A180(sBXStr_26A180* self, char* src)
{
    char* start = src;
    int n;
    int a;
    int b;
    int c;
    sVE0_26A180* vt0 = (sVE0_26A180*)self->vt;
    vt0[3].fn((char*)self + vt0[3].delta);
    func_0026BA68_A180(&n, src);
    src += 4;
    for (int i = 0; i < n; i++)
    {
        func_0026BA68_A180(&a, src);
        src += 4;
        func_0026BA68_A180(&b, src);
        src += 4;
        sVE1_26A180* vt1 = (sVE1_26A180*)self->vt;
        vt1[4].fn((char*)self + vt1[4].delta, src, a, b);
        src += b;
    }
    func_0026BA68_A180(&c, src);
    src += 4;
    self->count1 = c;
    func_0026BA68_A180(&c, src);
    src += 4;
    self->count2 = c;
    func_0026BA48(self->vecA, src);
    src += 0xC;
    func_0026BA48(self->vecB, src);
    src += 0xC;
    func_0026BA48(self->vecC, src);
    src += 0xC;
    self->items1 = src;
    for (int i = 0; i < self->count1; i++)
    {
        func_0026A338(self, src, self->items1 + i * 16);
        src += 16;
    }
    self->items2 = src;
    for (int i = 0; i < self->count2; i++)
    {
        func_0026A378(self, src, (int*)(self->items2 + i * 16));
        src += 16;
    }
    return src - start;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A338);
#ifdef SKIP_ASM
extern "C" void func_0026BA48(void* p, void* q);
// PORT: func_0026BA88 takes (dst, src); the unit declares it with one arg
void func_0026BA88_2(void* dst, void* src) __asm__("func_0026BA88");

extern "C" void func_0026A338(void* self, void* src, void* dst)
{
    func_0026BA48(dst, src);
    func_0026BA88_2((char*)dst + 0xC, (char*)src + 0xC);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A378);
#ifdef SKIP_ASM
// PORT: func_0026BA68 takes (dst, src); the unit declares it with one arg
void func_0026BA68_K2(void* dst, void* src) __asm__("func_0026BA68");
extern int D_004453D0[];

extern "C" void func_0026A378(void* self, char* src, int* dst)
{
    int key;
    int i;
    func_0026BA68_K2(&key, src);
    src += 4;
    *dst = 0;
    for (i = 0; i < 21; i++) {
        if (D_004453D0[i] == key) {
            *dst = i;
            break;
        }
    }
    func_0026BA68_K2(dst + 1, src);
    src += 4;
    func_0026BA88_2(dst + 2, src);
    func_0026BA88_2(dst + 3, src + 4);
}
#endif

INCLUDE_ASM("bx/bxstringctor", func_0026A428);

INCLUDE_ASM("bx/bxstringctor", func_0026A638);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A8B8);
#ifdef SKIP_ASM
struct sBXSeg16 {
    float f0;
    float f4;
    float f8;
    float fC;
};

extern "C" sBXSeg16* func_0026A8B8(sBXSeg16* out, void* self, float t)
{
    int i = 0;
    for (;;) {
        sBXSeg16* e = &(*(sBXSeg16**)((char*)self + 0x18))[i];
        if (i == *(int*)((char*)self + 0x8) - 1 || t <= e->fC) {
            out->f0 = e->f0;
            out->f4 = e->f4;
            out->f8 = e->f8;
            *(int*)&out->fC = 0;
            goto done;
        }
        t -= e->fC;
        i++;
    }
done:
    return out;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A920);
#ifdef SKIP_ASM
struct sBXEnt16_A920 {
    int key;
    int key2;
    int pad[2];
};
struct sBXTab_A920 {
    int count;
    sBXEnt16_A920* items;
};

extern "C" sBXEnt16_A920* func_0026A920(sBXTab_A920* self, int key, int key2)
{
    sBXEnt16_A920* e = self->items;
    for (int i = 0; i < self->count; i++, e++) {
        if (e->key == key && e->key2 == key2) {
            return e;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A970);
#ifdef SKIP_ASM
struct sBXEnt16_A970 {
    int key;
    int pad[3];
};
struct sBXTab_A970 {
    int count;
    sBXEnt16_A970* items;
};

extern "C" sBXEnt16_A970* func_0026A970(sBXTab_A970* self, int key)
{
    sBXEnt16_A970* e = self->items;
    for (int i = 0; i < self->count; i++, e++) {
        if (e->key == key) {
            return e;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026A9B0);
#ifdef SKIP_ASM
struct sBXBox {
    char pad_0x00[0x1C];
    float min[3]; // 0x1C
    float max[3]; // 0x28
};

// Largest per-axis distance from point p to the box.
extern "C" float func_0026A9B0(sBXBox* self, float* p)
{
    float dx = 0.0f;
    float dy = 0.0f;
    float dz = 0.0f;
    if (p[0] < self->min[0]) {
        dx = self->min[0] - p[0];
    } else if (self->max[0] < p[0]) {
        dx = p[0] - self->max[0];
    }
    if (p[1] < self->min[1]) {
        dy = self->min[1] - p[1];
    } else if (self->max[1] < p[1]) {
        dy = p[1] - self->max[1];
    }
    if (p[2] < self->min[2]) {
        dz = self->min[2] - p[2];
    } else if (self->max[2] < p[2]) {
        dz = p[2] - self->max[2];
    }
    if (dy < dx) {
        if (dx < dz) {
            return dz;
        }
        return dx;
    }
    if (dy < dz) {
        return dz;
    }
    return dy;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AA80);
#ifdef SKIP_ASM
extern "C" int func_0026AA80(sBXRangeList* self, sBXRange* out, int maxOut, float lo, float hi)
{
    int n;
    int i;
    if (hi < lo) {
        return 0;
    }
    n = 0;
    for (i = 0; i < self->count; i++) {
        if (!(hi < self->items[i].min) && !(self->items[i].max < lo)) {
            *out++ = self->items[i];
            n++;
            if (n == maxOut) {
                goto done;
            }
        }
    }
done:
    return n;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AB20);
#ifdef SKIP_ASM
struct sBXVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sBXPathSeg {
    float x, y, z;   // direction
    float len;       // 0xC
};

struct sBXPath {
    char pad_0x00[8];
    int count;          // 0x8
    float x, y, z;      // 0xC start
    sBXPathSeg* segs;   // 0x18
};

// PORT: PS2-only VU0 inline asm (direction times scalar).
static inline sBXVec4 bxVu0ScaleDir(const sBXPathSeg& seg, float s)
{
    sBXVec4 v;
    v.x = seg.x;
    v.y = seg.y;
    v.z = seg.z;
    v.w = 0.0f;
    sBXVec4 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add-assign).
static inline void bxVu0AddEq(sBXVec4& dst, sBXVec4 b)
{
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(dst)
        : "m"(dst), "m"(b));
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sBXVec4 bxVu0Add(const sBXVec4& a, sBXVec4 b)
{
    sBXVec4 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b));
    return r;
}

extern "C" sBXVec4 func_0026AB20(sBXPath* self, int* inRange, float t)
{
    sBXVec4 pos;
    pos.x = self->x;
    pos.y = self->y;
    pos.z = self->z;
    pos.w = 1.0f;
    if (inRange) {
        *inRange = 1;
    }
    for (int i = 0;; ) {
        sBXPathSeg* seg = &self->segs[i];
        if (i == self->count) {
            if (inRange) {
                *inRange = 0;
            }
            return pos;
        }
        float len = seg->len;
        if (t < len) {
            return bxVu0Add(pos, bxVu0ScaleDir(*seg, t));
        }
        t -= len;
        i++;
        bxVu0AddEq(pos, bxVu0ScaleDir(*seg, len));
    }
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AC48);
#ifdef SKIP_ASM
struct sBXElem16 {
    float f0;
    float f4;
    float f8;
    float fC;
};

extern "C" float func_0026AC48(void* self)
{
    int n = *(int*)((char*)self + 0x8);
    float sum = 0.0f;
    int i;
    for (i = 0; i < n; i++) {
        sum += (*(sBXElem16**)((char*)self + 0x18))[i].fC;
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AC88);
#ifdef SKIP_ASM
extern "C" int func_0026AC88(sBXRangeList* self, float lo, float hi)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (!(hi < self->items[i].min) && !(self->items[i].max < lo)) {
            if (self->items[i].field_0x0 == 0x14 || self->items[i].field_0x0 == 0x12) {
                return 1;
            }
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("bx/bxstringctor", func_0026AD00);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AD70);
#ifdef SKIP_ASM
extern "C" void func_0026ADF0(void* self);

extern "C" int func_0026AD70(void* self, int v)
{
    *(int*)((char*)self + 0x48) = v;
    *(int*)((char*)self + 0x4C) = 1;
    func_0026ADF0(self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026ADA0__FPv);
#ifdef SKIP_ASM
void func_0026ADA0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026ADA8);
#ifdef SKIP_ASM
extern "C" int func_003E22F0(int, int);

extern "C" void func_0026ADA8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x48))) = func_003E22F0(arg1, 0);
    (*(int *)((char*)(arg0) + (0x4C))) = 1;
    func_0026ADF0(arg0);
}
#endif
//100%
INCLUDE_ASM("bx/bxstringctor", func_0026ADE8);
#ifdef SKIP_ASM
extern "C" int func_0026ADE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x4C)));
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026ADF0);
#ifdef SKIP_ASM
// PORT: func_0026BA68 takes (dst, src); the unit declares it with one arg
void func_0026BA68_2(void* dst, void* src) __asm__("func_0026BA68");
extern "C" int func_0026B410(void* self, char* p);
extern "C" int cPathSys_resolvePaths(void* self, char* p);
extern "C" int func_0026B7D8(void* self, char* p);
extern "C" void func_0026B880(void* self, char* p);

extern "C" void func_0026ADF0(void* self)
{
    int header;
    char* p = *(char**)((char*)self + 0x48);
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x0) = 0;
    func_0026BA68_2(&header, p);
    p += 4;
    p += func_0026B410(self, p);
    p += cPathSys_resolvePaths(self, p);
    p += func_0026B7D8(self, p);
    func_0026B880(self, p);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AE70);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void func_0026ADA8(void* self, int arg1);
extern "C" int func_003E22F0(int, int);
// PORT: func_0026BA68 takes (dst, src); the unit declares it with one arg
void func_0026BA68_3(void* dst, void* src) __asm__("func_0026BA68");
extern "C" int func_0026B410(void* self, char* p);
extern "C" int cPathSys_resolvePaths(void* self, char* p);

extern "C" void func_0026AE70(void* self, int arg1)
{
    int header;
    void* old = *(void**)((char*)self + 0x48);
    if (old != 0) {
        cMemMan_free(old);
    } else {
        func_0026ADA8(self, arg1);
    }
    *(int*)((char*)self + 0x48) = 0;
    char* p = (char*)func_003E22F0(arg1, 0);
    *(char**)((char*)self + 0x48) = p;
    func_0026BA68_3(&header, p);
    p += 4;
    p += func_0026B410(self, p);
    cPathSys_resolvePaths(self, p);
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AF00);
#ifdef SKIP_ASM
void cMemMan_free(void*);

extern "C" void func_0026AF00(void* self)
{
    if (*(void**)((char*)self + 0xC) != 0)
        cMemMan_free(*(void**)((char*)self + 0xC));
    *(void**)((char*)self + 0xC) = 0;
    if (*(void**)((char*)self + 0x14) != 0)
        cMemMan_free(*(void**)((char*)self + 0x14));
    *(void**)((char*)self + 0x14) = 0;
    if (*(void**)((char*)self + 0x48) != 0 && *(int*)((char*)self + 0x4C) != 0)
        cMemMan_free(*(void**)((char*)self + 0x48));
    *(void**)((char*)self + 0x48) = 0;
    *(int*)((char*)self + 0x4C) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AF70);
#ifdef SKIP_ASM
extern "C" int func_0026AF70(void* self, int a1)
{
    return *(int*)((char*)self + 0x14) + a1 * 0x3c;
}
#endif

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AF88);
#ifdef SKIP_ASM
extern "C" int func_0026AF88(void* self, int a1)
{
    return *(int*)((char*)self + 0xc) + (a1 << 6);
}
#endif

extern "C" void* func_0026AFB8(void*);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026AF98__FPv);
#ifdef SKIP_ASM
// PORT: the unit declares func_0026AFB8(void*) and this symbol's mangling says (void*),
// but both really take more arguments (callers pass $5-$7, and this passes a 5th arg in $8).
// Bind the real signatures to the existing symbol names with asm labels.
int func_0026AFB8_impl(void* self, void* a1, void** out, int maxOut, int flag) __asm__("func_0026AFB8");
int func_0026AF98_impl(void* self, void* a1, void** out, int maxOut) __asm__("func_0026AF98__FPv");

int func_0026AF98_impl(void* self, void* a1, void** out, int maxOut)
{
    return func_0026AFB8_impl(self, a1, out, maxOut, 1);
}
#endif

INCLUDE_ASM("bx/bxstringctor", func_0026AFB8);

//100%
INCLUDE_ASM("bx/bxstringctor", func_0026B178);
#ifdef SKIP_ASM
struct sBXBox;
struct sPathItem_B178 {
    char pad[0x3C];
};

struct sPathList_B178 {
    char pad_0x0[0x10];
    int count;                  // 0x10
    sPathItem_B178* items;      // 0x14
};

extern "C" float func_0026A9B0(sBXBox* self, float* p);

static inline int minB178(int a, int b)
{
    return a < b ? a : b;
}

// Collects up to max items nearest to pos (items containing it first), nearest first; returns how many.
extern "C" int func_0026B178(sPathList_B178* self, float* pos, sPathItem_B178** out, int max)
{
    float dist[52];
    int n = 0;
    int want = minB178(self->count, max);
    int i;
    for (i = 0; i < self->count; i++) {
        dist[i] = func_0026A9B0((sBXBox*)&self->items[i], pos);
        if (dist[i] == 0.0f) {
            dist[i] = 1e37f;
            out[n++] = &self->items[i];
            if (n == want) {
                break;
            }
        }
    }
    while (n < want) {
        float best = dist[0];
        int bi = 0;
        for (i = 1; i < self->count; i++) {
            if (dist[i] < best) {
                best = dist[i];
                bi = i;
            }
        }
        dist[bi] = 1e37f;
        out[n] = &self->items[bi];
        n++;
    }
    return n;
}
#endif

