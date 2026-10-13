#include "common.h"

//100%
INCLUDE_ASM("ui/uiengine", UIAsciiToUnicode__FPUsPCc);
#ifdef SKIP_ASM
void UIAsciiToUnicode(unsigned short* dst, const char* src)
{
    for (; *src != 0; src++, dst++) {
        *dst = (char)*(unsigned char*)src;
    }
    *dst = 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00397B08);
#ifdef SKIP_ASM
extern "C" void* func_003977E8(void* self);

extern "C" void* func_00397B08(void* self)
{
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    func_003977E8((char*)self + 0x18);
    func_003977E8((char*)self + 0x34);
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0x5C) = 0;
    *(int*)((char*)self + 0x60) = 0;
    *(int*)((char*)self + 0x64) = 0;
    *(int*)((char*)self + 0x68) = 0;
    *(void**)((char*)self + 0x54) = self;
    *(void**)((char*)self + 0x6C) = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00397B70);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_00398078(void* self, int flags);
extern "C" void func_0039E9D8(void* self, int flags);

class cUIEngOwnA {
public:
    int f0;
    virtual ~cUIEngOwnA();
};

class cUIEngOwnB {
public:
    int f0;
    int f4;
    virtual ~cUIEngOwnB();
};

class cUIEngOwnC {
public:
    virtual ~cUIEngOwnC();
};

struct func_00397B70_sSelf {
    cUIEngOwnA* a;
    void* buf;
    int f8;
    cUIEngOwnB* b;
    int f10;
    cUIEngOwnC* c;
};

extern "C" void func_00397B70(void* self, int flags)
{
    func_00397B70_sSelf* s = (func_00397B70_sSelf*)self;
    delete s->a;
    if (s->buf) {
        cMemMan_free(s->buf);
    }
    delete s->b;
    delete s->c;
    func_00398078((char*)self + 0x58, 2);
    func_0039E9D8((char*)self + 0x18, 2);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", cUIEngine_loadFile);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* FILE_load(const char* name, int flags);
void func_00397138(void* self, int val);
extern "C" void cUITextureBank_setData(void* bank, int id, void* data);
extern const char D_004A4770[];

extern "C" int cUIEngine_loadFile(void* self, int id)
{
    char name[100];
    sprintf(name, D_004A4770, id);
    char* file = (char*)FILE_load(name, 0);
    *(char**)((char*)self + 0x4) = file;
    // PORT: the font setter stores the data pointer in an int.
    func_00397138((char*)self + 0x50, (int)(file + *(int*)(file + 0x8)));
    file = *(char**)((char*)self + 0x4);
    cUITextureBank_setData((char*)self + 0x58, id, file + *(int*)(file + 0x10));
    return 1;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", cUIEngine_addScreenByHashName);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is the game's tagged operator new(size, tag, flags, d); bound by asm label.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void* func_003977E8(void* self);
extern "C" void func_001DD580(void* self);
extern "C" void cUIScreen_setData(void* self, char* data);
extern "C" void func_0039E758(void* self, void* node);
extern "C" void cUIScreen_createAllObjects(void* self);
// PORT: func_0039FB30 really takes (self, a, b); the unit's other caller uses a 1-arg declaration.
void* func_0039FB30_3(void* self, int a, int b) __asm__("func_0039FB30");
extern char D_00493D80[];
extern void* D_00494670[];
extern void* D_004949E8[];

struct sUIScreenD4 {
    sUIScreenD4* next;          // 0x0
    sUIScreenD4* prev;          // 0x4
    void** vt;                  // 0x8
    int fC;
    int f10;
    char o14[4];                // 0x14
    char o18[0x1C];             // 0x18
    int f34;
    int f38;
    int f3C;
    char o40[8];                // 0x40
    void** vt48;                // 0x48
    char pad4C[0xB4 - 0x4C];
    char oB4[0x1C];             // 0xB4
    void* owner;                // 0xD0
};
struct sUIScrEnt { unsigned int hash; int offset; };
struct sUIScrTbl { unsigned int count; sUIScrEnt ents[1]; };

extern "C" void* cUIEngine_addScreenByHashName(void* self, void* owner, unsigned int hash, void* screen)
{
    char* bank = *(char**)((char*)self + 4);
    sUIScrTbl* tbl = (sUIScrTbl*)(bank + *(int*)(bank + 0xC));
    sUIScrEnt* found = 0;
    sUIScrEnt* e = tbl->ents;
    for (unsigned int i = 0; i < tbl->count; i++, e++) {
        if (e->hash == hash) {
            found = e;
            break;
        }
    }
    char* data = (char*)tbl + found->offset;
    if (screen == 0) {
        sUIScreenD4* s = new (D_00493D80, 0x100, 0) sUIScreenD4;
        s->prev = s;
        s->next = s;
        s->vt = D_00494670;
        s->fC = 0;
        s->f10 = 0;
        func_001DD580(s->o14);
        func_003977E8(s->o18);
        s->f34 = 0;
        s->f38 = 0;
        s->f3C = 0;
        func_0039FB30_3(s->o40, 0, 0);
        s->vt48 = D_004949E8;
        func_003977E8(s->oB4);
        s->owner = owner;
        screen = s;
    }
    cUIScreen_setData(screen, data);
    func_0039E758(owner, screen);
    cUIScreen_createAllObjects(screen);
    return screen;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00397DF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sUIRS_7DF8 {
    unsigned int f0_0 : 2;
    unsigned int f0_2 : 2;
    unsigned int f0_4 : 28;
    unsigned int f4_0 : 2;
    unsigned int f4_2 : 5;
    unsigned int f4_7 : 5;
    unsigned int f4_12 : 8;
    unsigned int f4_20 : 2;
    unsigned int f4_22 : 1;
    unsigned int f4_23 : 2;
    unsigned int f4_25 : 7;
    int f8;
    int fC;
    int f10;
};

class cUICtx_7DF8 {
public:
    char pad0[0xE84];
    sUIRS_7DF8* top;
    char pad1[0x10D8 - 0xE88];
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
    virtual void v26(int a, int b, float x, float y, float w, float h, float zn, float zf);
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(void* p);
};

// Typed view of the render context (the unit declares D_004A289C as void* later).
extern cUICtx_7DF8* D_004A289C_7df8 __asm__("D_004A289C");
extern char D_004FF1A0[];
extern sUIRS_7DF8 D_00501420_7df8 __asm__("D_00501420");
extern "C" void func_0039EBE0(void* p);

static inline void setF4_22_7DF8(sUIRS_7DF8* rs, int v) { rs->f4_22 = v; }
static inline void setF4_23_7DF8(sUIRS_7DF8* rs, int v) { rs->f4_23 = v; }
static inline void setF4_20_7DF8(sUIRS_7DF8* rs, int v) { rs->f4_20 = v; }
static inline void setF4_12_7DF8(sUIRS_7DF8* rs, int v) { rs->f4_12 = v; }
static inline void setF4_2_7DF8(sUIRS_7DF8* rs, int v) { rs->f4_2 = v; }

extern "C" void func_00397DF8(void* self)
{
    cUICtx_7DF8* ctx = D_004A289C_7df8;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
    *D_004A289C_7df8->top = D_00501420_7df8;
    D_004A289C_7df8->v31();
    D_004A289C_7df8->v21();
    D_004A289C_7df8->v26(0, 1, 0.0f, 0.0f, 640.0f, 480.0f, -1.0f, 1.0f);
    D_004A289C_7df8->v34(D_004FF1A0);
    setF4_22_7DF8(D_004A289C_7df8->top, 1);
    setF4_23_7DF8(D_004A289C_7df8->top, 2);
    setF4_20_7DF8(D_004A289C_7df8->top, 0);
    setF4_12_7DF8(D_004A289C_7df8->top, 0x14);
    setF4_2_7DF8(D_004A289C_7df8->top, 5);
    D_004A289C_7df8->top->f0_2 = 3;
    func_0039EBE0((char*)self + 0x18);
    D_004A289C_7df8->v22();
    D_004A289C_7df8->v32();
    D_004A289C_7df8->top--;
}
#endif

void func_0039ECA8(void*);

//100%
INCLUDE_ASM("ui/uiengine", func_00398018);
#ifdef SKIP_ASM
extern "C" void func_00398018(void* self)
{
    func_0039ECA8((char*)self + 0x18);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398038);
#ifdef SKIP_ASM
struct sVEntry398038 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0039F100(void*);

extern "C" void func_00398038(void* self)
{
    void* obj = *(void**)((char*)self + 0xC);
    sVEntry398038* vt = *(sVEntry398038**)((char*)obj + 8);
    vt[0x2E].fn((char*)obj + vt[0x2E].delta);
    func_0039F100((char*)self + 0x18);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398078);
#ifdef SKIP_ASM
struct sVEntry398078 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
extern void* D_004A289C;

extern "C" void func_00398078(void* self, int flags)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x8); i++) {
        char* obj = (char*)D_004A289C;
        sVEntry398078* vt = *(sVEntry398078**)(obj + 0x10D8);
        vt[0x32].fn(obj + vt[0x32].delta, (*(int**)((char*)self + 0x4))[i]);
    }
    if (*(void**)((char*)self + 0x4) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x4));
    }
    if (*(void**)((char*)self + 0xC) != 0) {
        cMemMan_free(*(void**)((char*)self + 0xC));
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", cUITextureBank_setData);
#ifdef SKIP_ASM
struct sUITexElem8138 {
    int tex;                // 0x00
    float f4;               // 0x04
    float f8;               // 0x08
    float fC;               // 0x0C
    float f10;              // 0x10
    float f14;              // 0x14
    float f18;              // 0x18
    int id;                 // 0x1C
    sUITexElem8138()
    {
        tex = -1;
        f4 = 1.0f;
        f8 = 1.0f;
        fC = 0.0f;
        f10 = 0.0f;
        f14 = 1.0f;
        f18 = 1.0f;
    }
};

struct sUITexSrc8138 {
    int id;                 // 0x00
    char b4;                // 0x04
    unsigned char tex;      // 0x05
    char pad6[2];
    float f8;               // 0x08
    float fC;               // 0x0C
    float f10;              // 0x10
    float f14;              // 0x14
};

struct sUITexData8138 {
    int count;              // 0x00
    sUITexSrc8138 e[1];     // 0x04
};

struct sUITexBank8138 {
    sUITexData8138* data;   // 0x00
    int* texIds;            // 0x04
    int texCount;           // 0x08
    sUITexElem8138* elems;  // 0x0C
    int elemCount;          // 0x10
};

struct sUIFshDir8138 {
    int offset;
    int pad;
};

struct sUIFsh8138 {
    char pad_0x0[0x8];
    int count;              // 0x08
    char pad_0xC[0x8];
    sUIFshDir8138 dir[1];   // 0x14
};

struct sUIVE_8138 {
    short delta;
    short index;
    int (*fn)(void*, void*, void*, int, int, int);
};

extern char D_00493D90[];
extern char D_00493DA0[];
extern char D_00493DB0[];
extern char D_004A4778[];
extern char* D_004A289C_8138 __asm__("D_004A289C");
extern "C" sUIFsh8138* func_003E22F0(char* name, int flags);
extern "C" void func_002523A8(void* p);
extern "C" void* func_00416210(void* dst, int c, int n);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");

extern "C" void cUITextureBank_setData(void* vbank, int id, void* vdata)
{
    sUITexBank8138* self = (sUITexBank8138*)vbank;
    sUITexData8138* data = (sUITexData8138*)vdata;
    char name[0x70];
    int i = 0;
    sprintf(name, D_00493D90, id);
    sUIFsh8138* fsh = func_003E22F0(name, 0x3000100);
    self->texCount = fsh->count;
    self->texIds = (int*)operator_new_tag(self->texCount * 4, D_00493DA0, 0, 0);
    func_00416210(self->texIds, 0xFF, self->texCount * 4);
    for (; i < self->texCount; i++) {
        char* shape = (char*)fsh + fsh->dir[i].offset;
        if (shape != 0) {
            sUIVE_8138* vt = *(sUIVE_8138**)(D_004A289C_8138 + 0x10D8);
            self->texIds[i] = vt[46].fn(D_004A289C_8138 + vt[46].delta, shape, D_004A4778, 0, 1, -1);
        }
    }
    func_002523A8(fsh);
    sUITexSrc8138* src = data->e;
    self->data = data;
    int n = data->count;
    self->elemCount = n;
    sUITexElem8138*& slot = self->elems;
    slot = new (D_00493DB0, 0, 0) sUITexElem8138[n];
    func_00416210(self->elems, 0xFF, self->elemCount * 4);
    int j;
    for (j = 0; j < self->elemCount; j++, src++) {
        self->elems[j].fC = src->fC;
        self->elems[j].f10 = src->f8;
        self->elems[j].f18 = src->f14;
        self->elems[j].f14 = src->f10;
        self->elems[j].id = src->id;
        self->elems[j].tex = self->texIds[src->tex];
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398380);
#ifdef SKIP_ASM
struct s398380Item {
    char pad[0x1C];
    int id;
};

extern "C" s398380Item* func_00398380(void* self, int id)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x10); i++) {
        s398380Item* item = &(*(s398380Item**)((char*)self + 0xC))[i];
        if (item->id == id) {
            return item;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_003983F0);
#ifdef SKIP_ASM
struct s3983F0Entry {
    int key;
    int unk4;
    int value;
};

struct s3983F0 {
    int unk0;
    s3983F0Entry entries[4];
    signed char count;
};

extern "C" int func_003983F0(s3983F0* self, int key)
{
    signed char i;
    for (i = 0; i < self->count; i++) {
        s3983F0Entry* e = &self->entries[i];
        if (e->key == key) {
            return e->value;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398438);
#ifdef SKIP_ASM
extern "C" void func_003916C0(int h, int a);

extern "C" void func_00398438(s3983F0* self)
{
    for (int i = 0; i < self->count; i++) {
        s3983F0Entry* e = &self->entries[i];
        if (e->value != 0) {
            func_003916C0(e->value, 3);
        }
        e->unk4 = 0;
        e->key = 0;
    }
    self->count = 0;
}
#endif

INCLUDE_ASM("ui/uiengine", func_003984B0);

//100%
INCLUDE_ASM("ui/uiengine", cUIFontInterface_loadFonts);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" int func_003915E8(void* mem, int name, int a2);
extern char D_004A4780[];

static inline int uiFontNameOf(s3983F0Entry* e)
{
    return e->unk4;
}

extern "C" void cUIFontInterface_loadFonts(s3983F0* self)
{
    for (int i = 0; i < self->count; i++) {
        signed char j = i;
        *(int*)((char*)self + j * 12 + 0xC) = func_003915E8(cMemMan_alloc(0x84, D_004A4780, 0, 0), uiFontNameOf(&self->entries[i]), 0);
    }
}
#endif

extern "C" void* func_0039FE00(void* self);

//100%
INCLUDE_ASM("ui/uiengine", func_00398618__FPv);
#ifdef SKIP_ASM
void* func_00398618(void* self)
{
    return func_0039FE00(self);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398638);
#ifdef SKIP_ASM
extern void* D_00494B98[];
extern void* D_00494CE8[];

struct func_00398638_sFunctor {
    void** vt;
    int arg;
};

struct func_00398638_sFlags {
    unsigned int pad0 : 4;
    unsigned int on : 1;
};

// PORT: functor object passed to func_003979F8 (declared later in the unit with its own functor struct).
int func_003979F8_f(void* list, func_00398638_sFunctor* fn) __asm__("func_003979F8");

extern "C" void func_00398638(void* self, int on)
{
    func_00398638_sFunctor f;
    f.vt = D_00494CE8;
    f.vt = D_00494B98;
    f.arg = on;
    func_003979F8_f((char*)self + 0x74, &f);
    f.vt = D_00494CE8;
    ((func_00398638_sFlags*)((char*)self + 0x14))->on = (on != 0);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_003986B0);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);
extern "C" void* func_0039FF60(void* self, int a1);

struct func_003986B0_sVEntry {
    short delta;
    short index;
    void* (*fn)(void*, int);
};

extern "C" void* func_003986B0(void* self, int id)
{
    if (func_0039FF60(self, id) != 0) {
        return self;
    }
    void* n = cList_first((cList*)((char*)self + 0x74));
    if (n != 0) {
        do {
            func_003986B0_sVEntry* e = &(*(func_003986B0_sVEntry**)((char*)n + 8))[14];
            void* r = e->fn((char*)n + e->delta, id);
            if (r != 0) {
                return r;
            }
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398738);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);

struct func_00398738_sVEntry {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00398738(void* self)
{
    void* n = cList_first((cList*)((char*)self + 0x74));
    if (n != 0) {
        do {
            func_00398738_sVEntry* vt = *(func_00398738_sVEntry**)((char*)n + 8);
            vt[0x10].fn((char*)n + vt[0x10].delta);
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398798);
#ifdef SKIP_ASM
extern void* D_00494BB8[];
extern void* D_00494CE8[];

struct func_00398798_sFunctor {
    void** vt;
    int arg;
};

extern "C" int func_003979F8(void* list, func_00398798_sFunctor* fn);

extern "C" int func_00398798(void* self, int a1)
{
    if ((*(int*)((char*)self + 0x14) >> 5) & 1) {
        return 0;
    }
    func_00398798_sFunctor f;
    f.vt = D_00494CE8;
    f.vt = D_00494BB8;
    f.arg = a1;
    int r = func_003979F8((char*)self + 0x74, &f);
    f.vt = D_00494CE8;
    return r != 0;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_003987F8);
#ifdef SKIP_ASM
struct func_003987F8_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_003987F8(void* self, int a1)
{
    void* n = cList_first((cList*)((char*)self + 0x74));
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            func_003987F8_sVEntry* vt = *(func_003987F8_sVEntry**)((char*)n + 8);
            vt[0x12].fn((char*)n + vt[0x12].delta, a1);
            n = *(void**)((char*)n + 4);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398868);
#ifdef SKIP_ASM
struct func_00398868_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, float, float);
};

extern "C" void func_00398868(void* self, float x, float y)
{
    void* n = cList_first((cList*)((char*)self + 0x74));
    if (n != 0) {
        do {
            if ((*(int*)((char*)n + 0x14) >> 6) & 1) {
                func_00398868_sVEntry* vt = *(func_00398868_sVEntry**)((char*)n + 8);
                vt[0x11].fn((char*)n + vt[0x11].delta, *(float*)((char*)self + 0x44) + x, *(float*)((char*)self + 0x48) + y);
            }
            n = *(void**)((char*)n + 4);
        } while (!cListNode_isSentinel((cListNode*)n));
    }
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398910);
#ifdef SKIP_ASM
struct cList;
struct cListNode;
void* cList_first(cList*);
int cListNode_isSentinel(cListNode*);
extern "C" void func_003A0000(void* self, unsigned short ev);

struct func_00398910_sVEntry {
    short delta;
    short index;
    void (*fn)(void*, unsigned short);
};

extern "C" void func_00398910(void* self, unsigned short ev)
{
    void* n = cList_first((cList*)((char*)self + 0x74));
    if (n != 0) {
        while (!cListNode_isSentinel((cListNode*)n)) {
            func_00398910_sVEntry* vt = *(func_00398910_sVEntry**)((char*)n + 8);
            vt[19].fn((char*)n + vt[19].delta, ev);
            n = *(void**)((char*)n + 4);
        }
    }
    func_003A0000(self, ev);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398998);
#ifdef SKIP_ASM
// PORT: func_0039FE00 really takes (self, data) and its result is unused here; the unit declares it with one argument.
void func_0039FE00_8998(void* self, void* data) __asm__("func_0039FE00");

struct sUISize8998 {
    float w, h;
    sUISize8998() {}
    sUISize8998(float aw, float ah) : w(aw), h(ah) {}
};
struct sUIObj8998 {
    char pad0[0x5C];
    char* scene;                // 0x5C
    char pad60[0x74 - 0x60];
    unsigned int b0 : 1;        // 0x74
    unsigned int clip : 1;
    unsigned int align : 2;
    unsigned int rest : 28;
    char pad78[0x7C - 0x78];
    s398380Item* item;          // 0x7C
    sUISize8998 size;           // 0x80
};
struct sUIData8998 {
    char pad0[0x20];
    unsigned char align : 2;    // 0x20
    unsigned int clip : 1;
    unsigned int rest : 29;
    int id;                     // 0x24
    unsigned short w;           // 0x28
    unsigned short h;           // 0x2A
};

// Copies the widget's clip/alignment bits, looks up its item and sets its size (stored in 1/100 units).
extern "C" void func_00398998(sUIObj8998* self, sUIData8998* data)
{
    func_0039FE00_8998(self, data);
    self->clip = data->clip;
    self->align = data->align;
    self->item = func_00398380(*(char**)(*(char**)(self->scene + 0xD0) + 0x10) + 0x58, data->id);
    self->size = sUISize8998(data->w * 0.01f, data->h * 0.01f);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00398A60__FPvT0);
#ifdef SKIP_ASM
void func_00398A60(void* a, void* b)
{
    float t = *(float*)a;
    *(float*)a = *(float*)b;
    *(float*)b = t;
}
#endif

INCLUDE_ASM("ui/uiengine", func_00398A78);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uiengine", func_00399730);
#ifdef SKIP_ASM
extern "C" void func_00399730(void* self, int id)
{
    void* a = *(void**)((char*)self + 0x5C);
    void* b = *(void**)((char*)a + 0xD0);
    void* c = *(void**)((char*)b + 0x10);
    *(s398380Item**)((char*)self + 0x7C) = func_00398380((char*)c + 0x58, id);
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00399768);
#ifdef SKIP_ASM
extern "C" void* func_0039FB30(void* self);
extern "C" void* func_00416210(void* dst, int c, int n);
extern void* D_00494798[];

struct func_00399768_sQuad {
    int a, b, c, d;
};
extern func_00399768_sQuad D_004C66C8;

struct func_00399768_sEntry {
    int a;
    int b;
    int c;
    int d;
    char e;
};

struct func_00399768_sObj {
    char base[0x74];
    unsigned char flags;
    char pad75[0x88 - 0x75];
    func_00399768_sQuad quad;
    func_00399768_sEntry entries[32];
    char c318;
    char c319;
};

extern "C" func_00399768_sObj* func_00399768(func_00399768_sObj* self)
{
    func_0039FB30(self);
    *(void***)((char*)self + 8) = D_00494798;
    self->flags = (self->flags | 4) & 0xC4;
    func_00399768_sEntry* p = self->entries;
    for (int i = 31; i != -1; i--, p++) {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
    }
    self->c318 = 0;
    self->c319 = 0;
    func_00416210(self->entries, 0, 0x280);
    self->quad = D_004C66C8;
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00399820);
#ifdef SKIP_ASM
// PORT: func_0039FE00 really takes (self, data); the unit declares it with one argument.
void* func_0039FE00_2(void* self, void* data) __asm__("func_0039FE00");

struct sUIColor9820 {
    float r, g, b, a;
    sUIColor9820() {}
    sUIColor9820(float ar, float ag, float ab, float aa) : r(ar), g(ag), b(ab), a(aa) {}
};
struct sUIVt9820 { short delta; short index; void (*fn)(void*, int); };
struct sUIObj9820 {
    char pad0[0x8];
    sUIVt9820* vt;              // 0x8
    char padC[0x14 - 0xC];
    int flags14;                // 0x14
    char pad18[0x74 - 0x18];
    unsigned int mode : 2;      // 0x74
    unsigned int tinted : 1;
    unsigned int rest : 29;
    sUIColor9820 color;         // 0x78
};
struct sUIData9820 {
    char pad0[0x20];
    unsigned char mode;         // 0x20
    char pad21;
    unsigned short vis;         // 0x22
    unsigned char r, g, b, a;   // 0x24
};

extern "C" void func_00399820(sUIObj9820* self, sUIData9820* data)
{
    func_0039FE00_2(self, data);
    self->mode = data->mode & 3;
    self->vt[23].fn((char*)self + self->vt[23].delta, data->vis & 1);
    int f = *(int*)((char*)self + 0x74) >> 2;
    if (f & 1) {
        self->color = sUIColor9820(data->r * 0.003921568859368563f, data->g * 0.003921568859368563f,
                                   data->b * 0.003921568859368563f, data->a * 0.003921568859368563f);
    }
    self->flags14 |= 0x80;
}
#endif

//100%
INCLUDE_ASM("ui/uiengine", func_00399920);
#ifdef SKIP_ASM
void* func_0039FF50(void*);

struct func_00399920_sEntry {
    int a;
    int b;
    int c;
};

extern "C" int func_00399920(void* self)
{
    void* o = func_0039FF50(self);
    if (o != 0) {
        func_00399920_sEntry* t = *(func_00399920_sEntry**)((char*)o + 0x8);
        return t[(*(unsigned char*)((char*)self + 0x74) & 3) + 1].a;
    }
    return 0;
}
#endif

INCLUDE_ASM("ui/uiengine", func_00399970);

//100%
INCLUDE_ASM("ui/uiengine", func_00399D80);
#ifdef SKIP_ASM
void cMemMan_free(void*);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern char D_00493DC0[];

struct func_00399D80_sEntry {
    unsigned short* str;
    int pad[4];
};

extern "C" void func_00399D80(void* self, unsigned char idx, unsigned short* str)
{
    void* a = *(void**)((char*)self + 0x5C);
    void* b = *(void**)((char*)a + 0xD0);
    void* c = *(void**)((char*)b + 0x10);
    if (*(void**)((char*)c + 0x10) != 0) {
        func_00399D80_sEntry* tbl = (func_00399D80_sEntry*)((char*)self + 0x9C);
        func_00399D80_sEntry* e = &tbl[idx];
        if (e->str) {
            cMemMan_free(e->str);
        }
        unsigned short* s = (unsigned short*)operator_new_tag((USTR_length(str) + 1) * 2, D_00493DC0, 0x100, 0);
        USTR_copy(s, str);
        e->str = s;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ui/uiengine", func_00399E28);
#ifdef SKIP_ASM
extern "C" void func_00399D80(void* self, unsigned char idx, unsigned short* str);

struct func_00399E28_sEntry {
    int id;
    unsigned short* str;
    int pad[3];
};

struct func_00399E28_sObj {
    char pad[0x98];
    func_00399E28_sEntry entries[32];
    unsigned char count;
};

struct func_00399E28_sVEntry {
    short delta;
    short index;
    void* fn;
};

extern "C" void func_00399E28(func_00399E28_sObj* self)
{
    void* a = *(void**)((char*)self + 0x5C);
    void* b = *(void**)((char*)a + 0xD0);
    void* c = *(void**)((char*)b + 0x10);
    char* loc = *(char**)((char*)c + 0x10);
    if (loc != 0) {
        for (unsigned char i = 0; i < self->count; i++) {
            int id = self->entries[i].id;
            if (id != 0) {
                func_00399E28_sVEntry* vt = *(func_00399E28_sVEntry**)(loc + 4);
                unsigned short* s = ((unsigned short* (*)(void*, int))vt[4].fn)(loc + vt[4].delta, id);
                if (s != 0) {
                    func_00399D80(self, i, s);
                }
            }
        }
        func_00399E28_sVEntry* vt2 = *(func_00399E28_sVEntry**)((char*)self + 8);
        ((void (*)(void*, int))vt2[5].fn)((char*)self + vt2[5].delta, 1);
    }
}
#endif

INCLUDE_ASM("ui/uiengine", func_00399F00);

