#include "common.h"

//100%
INCLUDE_ASM("scripter/bxscriptengine", cBXScriptEngine_SetupBXEngine);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00272788(void* obj, void* buf, int size, int a3, void* out);
extern char D_00481F48[];
extern char D_00481F58[];
extern char D_004A34F0[];

struct sBXSlot {
    int a;
    short b;
};

extern "C" void cBXScriptEngine_SetupBXEngine(void* self, int count, int a2, int size)
{
    *(void**)((char*)self + 0x2BC) = operator_new_tag(size, D_00481F48, 0, 0);
    *(void**)((char*)self + 0x2B8) = func_00272788(cMemMan_alloc(0x20, D_004A34F0, 0, 0),
        *(void**)((char*)self + 0x2BC), size, a2, (char*)self + 0x2AC);
    *(int*)((char*)self + 0x2B4) = count;
    *(sBXSlot**)((char*)self + 0x2B0) = (sBXSlot*)operator_new_tag(count * 8, D_00481F58, 0, 0);
    for (int i = 0; i < *(int*)((char*)self + 0x2B4); i++) {
        (*(sBXSlot**)((char*)self + 0x2B0))[i].a = 0;
        (*(sBXSlot**)((char*)self + 0x2B0))[i].b = 0;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282020);
#ifdef SKIP_ASM
struct sScriptEngine282390;
struct sScriptEngine2823F0;
struct sScriptEngine2B8;
extern "C" void func_00282390(sScriptEngine282390* self);
extern "C" void func_002823F0(sScriptEngine2823F0* self);
extern "C" void func_002828B8(sScriptEngine2B8* self);
extern "C" void func_0027D050(void* self);
extern "C" void func_002728D0(void* obj, int flags);
void cMemMan_free(void*);

extern "C" void func_00282020(void* self)
{
    if (*(void**)((char*)self + 0x2B0) != 0) {
        func_00282390((sScriptEngine282390*)self);
        func_002823F0((sScriptEngine2823F0*)self);
        func_0027D050(self);
        if (*(void**)((char*)self + 0x2B0) != 0) {
            cMemMan_free(*(void**)((char*)self + 0x2B0));
        }
        *(void**)((char*)self + 0x2B0) = 0;
        *(int*)((char*)self + 0x2B4) = 0;
        if (*(void**)((char*)self + 0x2B8) != 0) {
            func_002728D0(*(void**)((char*)self + 0x2B8), 3);
        }
        *(void**)((char*)self + 0x2B8) = 0;
        if (*(void**)((char*)self + 0x2BC) != 0) {
            cMemMan_free(*(void**)((char*)self + 0x2BC));
        }
        *(void**)((char*)self + 0x2BC) = 0;
        func_002828B8((sScriptEngine2B8*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002820B0);
#ifdef SKIP_ASM
extern "C" void func_002728F8(void* obj);
extern "C" void func_00282908(void* self, void* script);

struct sScriptSlot_2820B0 {
    int f0;
    int type;           // 0x04
    char pad8[0x18];
    int state;          // 0x20
};

struct sScriptEngine_2820B0 {
    char pad0[0x2B8];
    void* obj2B8;                       // 0x2B8
    char pad2BC[4];
    sScriptSlot_2820B0 slots[16];       // 0x2C0
};

// Retail builds compile the per-state debug hooks to nothing.
static inline void slotNop_2820B0(void* self, void* slot) {}
extern "C" void func_002820B0(sScriptEngine_2820B0* self)
{
    int i;
    func_002728F8(self->obj2B8);
    for (i = 0; i < 16; i++) {
        sScriptSlot_2820B0* s = &self->slots[i];
        if (s->state == 0) {
            continue;
        }
        if (s->state == 1) {
            switch (s->type) {
            case 0: slotNop_2820B0(self, s); break;
            case 1: func_00282908(self, s); break;
            case 2: slotNop_2820B0(self, s); break;
            case 3: slotNop_2820B0(self, s); break;
            case 4: slotNop_2820B0(self, s); break;
            case 5: slotNop_2820B0(self, s); break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282150);
#ifdef SKIP_ASM
struct sSlot282150 { int value; int pad; };
extern "C" int func_00282150(void* self, int value, int index)
{
    sSlot282150* slots = *(sSlot282150**)((char*)self + 0x2b0);
    if (slots[index].value != 0) {
        return 0;
    }
    slots[index].value = value;
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282178);
#ifdef SKIP_ASM
extern "C" int func_00282178(void* self, int index)
{
    sSlot282150* slots = *(sSlot282150**)((char*)self + 0x2b0);
    int old = slots[index].value;
    if (old == 0) {
        return 0;
    }
    slots[index].value = 0;
    return old;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002821A0);
#ifdef SKIP_ASM
struct sBxsThreadHdr;
extern "C" sBxsThreadHdr* func_00282C38(void* self, int a1);
extern "C" int func_00272938(void* self, void* src);
// PORT: the unit declares func_00272CC0(int), but it really takes (self, id).
void* func_00272CC0_2(void* self, int id) __asm__("func_00272CC0");
// PORT: the setter's mangled signature is (void*, int); a pointer is passed as int.
int func_00274C10(void* self, int a1);
void func_00282C88(void* self, void* v);

struct sBxsVEntry21A0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

struct sBXSlot21A0 {
    void* data;
    unsigned short uses;
};

struct sBXThread21A0 {
    void* owner;    // 0x0
    int state;      // 0x4
    int slot;       // 0x8
    int arg;        // 0xC
    short pad_10;   // 0x10
    short f12;      // 0x12
    int pending;    // 0x14
    float time;     // 0x18
    int result;     // 0x1C
};

extern "C" int func_002821A0(void* self, int idx, int arg)
{
    sBXSlot21A0* s = &(*(sBXSlot21A0**)((char*)self + 0x2B0))[idx];
    sBXThread21A0* t = (sBXThread21A0*)func_00282C38(self, 1);
    if (s->data == 0) {
        int one = 1;
        t->pending = idx;
        t->state = one;
        t->f12 = one;
        sBxsVEntry21A0* e = &(*(sBxsVEntry21A0**)((char*)self + 0x2A8))[7];
        if (e->fn((char*)self + e->delta, idx) == 0) {
            t->state = 7;
            func_00282C88(self, t);
            return -1;
        }
    } else {
        t->slot = idx;
        t->state = 2;
        int id = func_00272938(*(void**)((char*)self + 0x2B8), s->data);
        void* obj = func_00272CC0_2(*(void**)((char*)self + 0x2B8), id);
        t->owner = obj;
        func_00274C10(obj, (int)t);
        s->uses++;
    }
    t->arg = arg;
    return t->result;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002822A0);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);
extern "C" void func_00272AD0(void* cache, void* data, int a2);

extern "C" int func_002822A0(void* self, int id, int value, int arg)
{
    char* e = (char*)func_00282CB0(self, id);
    if (e == 0) {
        return 0;
    }
    int state = *(int*)(e + 0x4);
    if (state != 2) {
        return state;
    }
    *(short*)(e + 0x10) = value;
    if (*(int*)(e + 0x20) == 1) {
        *(int*)(e + 0x4) = 3;
        func_00272AD0(*(void**)((char*)self + 0x2B8), **(void***)e, arg);
    }
    return *(int*)(e + 0x4);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282338);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);
extern "C" void func_00272B58(void* cache, void* data);

extern "C" void func_00282338(void* self, int a1)
{
    char* e = (char*)func_00282CB0(self, a1);
    char* obj = *(char**)e;
    if (obj != 0 && *(int*)(obj + 0x20) != 0 && *(int*)(e + 0x20) == 1) {
        func_00272B58(*(void**)((char*)self + 0x2B8), *(void**)obj);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_00282390);
#ifdef SKIP_ASM
extern "C" void func_00282338(void* self, int id);

struct sScriptSlot282390 {
    int active;
    char pad_0x04[0x18];
    int id;
    int pad_0x20;
};

struct sScriptEngine282390 {
    char pad_0x000[0x2C0];
    sScriptSlot282390 slots[16];
};

extern "C" void func_00282390(sScriptEngine282390* self)
{
    for (int i = 0; i < 16; i++) {
        sScriptSlot282390* s = &self->slots[i];
        if (s->active != 0) {
            func_00282338(self, s->id);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002823F0);
#ifdef SKIP_ASM
extern "C" void func_00282540(void* self, int id);

struct sScriptSlot2823F0 {
    int active;
    char pad_0x04[0x18];
    int id;
    int state;
};

struct sScriptEngine2823F0 {
    char pad_0x000[0x2C0];
    sScriptSlot2823F0 slots[16];
};

extern "C" void func_002823F0(sScriptEngine2823F0* self)
{
    for (int i = 0; i < 16; i++) {
        sScriptSlot2823F0* s = &self->slots[i];
        if (s->state != 0) {
            func_00282540(self, s->id);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282450);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);
extern "C" void func_00274A30(void* p);

extern "C" int func_00282450(void* self, int a1)
{
    void* t = func_00282CB0(self, a1);
    if (t == 0) {
        return 0;
    }
    int type = *(int*)((char*)t + 0x4);
    if (type == 3 || type == 4) {
        func_00274A30(*(void**)t);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_00282CB0_v(void) __asm__("func_00282CB0");
void func_00274808(void* self, float t);

extern "C" int func_00282498(float t)
{
    if (t < 0.01f) return 0;
    char* c = (char*)func_00282CB0_v();
    if (c == 0) return 0;
    if (*(int*)(c + 4) == 1) {
        *(float*)(c + 0x18) = t;
        return 1;
    }
    func_00274808(*(void**)c, t);
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282500);
#ifdef SKIP_ASM
extern "C" int func_00282500(void* self, char* o, int v)
{
    char* p = *(char**)(o + 0xC);
    int old = *(int*)(p + 0xC);
    *(int*)(p + 0xC) = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282510);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0_v(void) __asm__("func_00282CB0");

extern "C" int func_00282510(void* self, int a, int v)
{
    char* e = (char*)func_00282CB0_v();
    int old = *(int*)(e + 0xC);
    *(int*)(e + 0xC) = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282540);
#ifdef SKIP_ASM
extern "C" void func_00282338(void* self, int id);
int func_00274C10(void* obj, int a);
extern "C" void func_002729A8(void* mgr, int handle);
void func_00282C88(void* self, void* slot);

struct sVEnt_282540 {
    short delta;
    short index;
    void* fn;
};
typedef void (*tVFn1_282540)(void*, int);
typedef void (*tVFn2_282540)(void*, int, int);

struct sTblEnt_282540 {
    int f0;                 // 0x0
    unsigned short refs;    // 0x4
    short pad6;
};

struct sScriptSlot_282540 {
    int* obj;               // 0x00
    int type;               // 0x04
    int tblIdx;             // 0x08
    int fC;                 // 0x0C
    short f10;              // 0x10
    short pad12;
    int f14;                // 0x14
    char pad18[8];
    int state;              // 0x20
};

struct sScriptEngine_282540 {
    char pad0[0x2A8];
    sVEnt_282540* vt;       // 0x2A8
    char pad2AC[4];
    sTblEnt_282540* tbl;    // 0x2B0
    char pad2B4[4];
    void* mgr;              // 0x2B8
};

sScriptSlot_282540* func_00282CB0_282540(sScriptEngine_282540* self, int id) __asm__("func_00282CB0");

#define VCALL1(SELF, SLOT, A) ((tVFn1_282540)(SELF)->vt[SLOT].fn)((char*)(SELF) + (SELF)->vt[SLOT].delta, A)
#define VCALL2(SELF, SLOT, A, B) ((tVFn2_282540)(SELF)->vt[SLOT].fn)((char*)(SELF) + (SELF)->vt[SLOT].delta, A, B)

// Finishes a script slot: per-type cleanup, release of its object and
// table reference, then returns the slot to the free list.
// PORT: the unit declares this as void(void*, int); defined under an asm label with its real type
extern "C" int func_00282540_impl(sScriptEngine_282540* self, int id) __asm__("func_00282540");
extern "C" int func_00282540_impl(sScriptEngine_282540* self, int id)
{
    sScriptSlot_282540* s = func_00282CB0_282540(self, id);
    if (s == 0 || s->state == 0) {
        return 6;
    }
    s->f10 = 0;
    switch (s->type) {
    case 1:
        {
            sTblEnt_282540* t = self->tbl + s->f14;
            if (t->f0 == 0) {
                VCALL1(self, 8, s->f14);
            }
        }
        break;
    case 3:
    case 4:
    case 5:
        func_00282338(self, id);
        break;
    case 0:
    case 2:
    case 6:
        break;
    }
    VCALL2(self, 12, id, s->fC);
    if (s->obj != 0) {
        func_00274C10(s->obj, 0);
        func_002729A8(self->mgr, *s->obj);
    }
    if (s->tblIdx >= 0) {
        sTblEnt_282540* e = self->tbl + s->tblIdx;
        if (--e->refs == 0) {
            VCALL1(self, 9, s->tblIdx);
        }
    }
    s->type = 7;
    func_00282C88(self, s);
    return 6;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282698);
#ifdef SKIP_ASM
extern "C" void func_00272BF8(int);

extern "C" void func_00282698(void *arg0) {
    func_00272BF8((*(int *)((char*)(arg0) + (0x2B8))));
}
#endif
//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002826B8);
#ifdef SKIP_ASM
extern "C" void func_00272C70(int);

extern "C" void func_002826B8(void *arg0) {
    func_00272C70((*(int *)((char*)(arg0) + (0x2B8))));
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002826D8);
#ifdef SKIP_ASM
extern "C" void func_002749E8(void* self);

extern "C" void func_002826D8(void* self, int a1)
{
    char* p = (char*)self + (a1 * 0x24 + 0x2c0);
    func_002749E8(*(void**)p);
    if (*(int*)(*(char**)p + 0x2C) > 0) {
        *(int*)(p + 0x4) = 5;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282720);
#ifdef SKIP_ASM
extern "C" void func_00274A08(void* self);

extern "C" void func_00282720(void* self, int a1)
{
    char* p = (char*)self + (a1 * 0x24 + 0x2c0);
    func_00274A08(*(void**)p);
    if (*(int*)(p + 0x4) == 5) {
        char* s = *(char**)p;
        if (*(int*)(s + 0x2C) <= 0) {
            int t = *(int*)(s + 0x20);
            if (t == 3 || t == 4) {
                *(int*)(p + 0x4) = 4;
            } else {
                *(int*)(p + 0x4) = 3;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282790);
#ifdef SKIP_ASM
extern int D_004A34E8;

extern "C" int func_00282790(void) {
    return D_004A34E8;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282798);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);
extern "C" void func_00282908(void* self, void* script);

extern "C" int func_00282798(void* self, int a1)
{
    char* s = (char*)func_00282CB0(self, a1);
    if (s == 0) {
        return 0;
    }
    if (*(int*)(s + 0x4) == 1) {
        func_00282908(self, s);
    }
    return *(int*)(s + 0x4);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002827F8);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0_v(void) __asm__("func_00282CB0");

extern "C" int func_002827F8(void)
{
    char* e = (char*)func_00282CB0_v();
    if (e == 0)
        return -1;
    if (*(int*)(e + 4) == 1)
        return *(int*)(e + 0x14);
    return *(int*)(e + 8);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282838);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);
extern "C" void func_00282908(void* self, void* script);

extern "C" int func_00282838(void* self, int a1)
{
    char* s = (char*)func_00282CB0(self, a1);
    if (s == 0) {
        return 0;
    }
    if (*(int*)(s + 0x4) == 1) {
        func_00282908(self, s);
    }
    if (*(int*)(s + 0x4) != 4 && *(int*)(s + 0x4) != 5) {
        return 0;
    }
    return *(int*)(*(char**)s + 0x20) == 4;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002828B8);
#ifdef SKIP_ASM
struct sScriptThread2C0 {
    int a;          // 0x00
    int b;          // 0x04
    int c;          // 0x08
    int d;          // 0x0C
    short e;        // 0x10
    short f;        // 0x12
    int g;          // 0x14
    int h;          // 0x18
    int id;         // 0x1C
    int k;          // 0x20
};
struct sScriptEngine2B8 {
    char pad[0x2b8];
    int count;                      // 0x2B8
    int unk2BC;                     // 0x2BC
    sScriptThread2C0 threads[16];   // 0x2C0
};
extern "C" void func_002828B8(sScriptEngine2B8* self)
{
    int i;
    self->count = 0;
    self->unk2BC = 0;
    for (i = 0; i < 16; i++) {
        self->threads[i].id = i;
        self->threads[i].k = 0;
        self->threads[i].a = 0;
        self->threads[i].b = 0;
        self->threads[i].e = 0;
        self->threads[i].f = 0;
        self->threads[i].h = 0;
        self->threads[i].g = -1;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282908);
#ifdef SKIP_ASM
extern "C" int func_00272938(void* self, void* src);
// PORT: the unit declares func_00272CC0(int), but it really takes (self, id).
void* func_00272CC0_2(void* self, int id) __asm__("func_00272CC0");
// PORT: the setter's mangled signature is (void*, int); a pointer is passed as int.
int func_00274C10(void* self, int a1);
void func_00274808(void* self, float t);

struct sBXSlot282908 {
    void* data;
    unsigned short uses;
};

struct sBXThread282908 {
    void* owner;    // 0x0
    int state;      // 0x4
    int slot;       // 0x8
    int pad_c;      // 0xC
    short pad_10;   // 0x10
    short f12;      // 0x12
    int pending;    // 0x14
    float time;     // 0x18
};

extern "C" void func_00282908(void* self, void* script)
{
    sBXThread282908* t = (sBXThread282908*)script;
    int idx = t->pending;
    sBXSlot282908* s = &(*(sBXSlot282908**)((char*)self + 0x2B0))[idx];
    if (s->data == 0) return;
    t->slot = idx;
    t->pending = -1;
    t->state = 2;
    t->f12 = 0;
    int id = func_00272938(*(void**)((char*)self + 0x2B8), s->data);
    void* obj = func_00272CC0_2(*(void**)((char*)self + 0x2B8), id);
    t->owner = obj;
    func_00274C10(obj, (int)t);
    if (t->time > 0.0f) {
        func_00274808(t->owner, t->time);
        t->time = 0.0f;
    }
    s->uses++;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002829D0);
#ifdef SKIP_ASM
struct sBxsVEntry10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int, int);
};

extern "C" void func_002829D0(void* self, void* a1)
{
    char* t = *(char**)((char*)a1 + 0xC);
    sBxsVEntry10* vt = *(sBxsVEntry10**)((char*)self + 0x2A8);
    vt[10].fn((char*)self + vt[10].delta, a1, *(int*)(t + 0x8), *(int*)(t + 0xC));
    *(int*)(t + 0x4) = 4;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282A18);
#ifdef SKIP_ASM
struct sVEntry282A18 {
    short delta;
    short index;
    void (*fn)(void*, void*, int, int);
};

extern "C" void func_00282540(void* self, int id);

extern "C" void func_00282A18(void* self, void* msg)
{
    char* s = *(char**)((char*)msg + 0xC);
    sVEntry282A18* vt = *(sVEntry282A18**)((char*)self + 0x2A8);
    vt[11].fn((char*)self + vt[11].delta, msg, *(int*)(s + 0x8), *(int*)(s + 0xC));
    *(int*)(s + 0x4) = 2;
    if (*(short*)(s + 0x10) != 0) {
        func_00282540(self, *(int*)(s + 0x1C));
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282A80);
#ifdef SKIP_ASM
extern "C" int func_0027D578(void* self, int key, void** out, int max);

class cBxsHandler2A80 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05(void* ctx, int arg);
};

extern "C" cBxsHandler2A80* func_00282A80(void* self, void* ctx, int arg)
{
    cBxsHandler2A80* buf[30];
    cBxsHandler2A80* found = 0;
    int n = func_0027D578(self, **(int**)((char*)ctx + 0x8), (void**)buf, 30);
    for (int i = 0; i < n; i++) {
        cBxsHandler2A80* h = buf[i];
        if (h->v05(ctx, arg)) {
            found = h;
            break;
        }
    }
    return found;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282B40);
#ifdef SKIP_ASM
struct sBxsThreadHdr {
    void* owner;    // 0x0
    int state;      // 0x4
    int handle;     // 0x8
};

extern "C" sBxsThreadHdr* func_00282C38(void* self, int a1);
// PORT: the setter's mangled signature is (void*, int); a pointer is passed as int.
int func_00274C10(void* self, int a1);

extern "C" void func_00282B40(void* self, void* obj)
{
    sBxsThreadHdr* t = func_00282C38(self, 1);
    t->state = 2;
    t->handle = -1;
    t->owner = obj;
    func_00274C10(obj, (int)t);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282B88);
#ifdef SKIP_ASM
void func_00282C88(void* self, void* v);

extern "C" void func_00282B88(void* self, void* ctx)
{
    void* v = *(void**)((char*)ctx + 0xC);
    *(int*)((char*)v + 0x4) = 7;
    func_00282C88(self, v);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282BB0__FPvT0);
#ifdef SKIP_ASM
int func_00282BB0(void* self, void* a1)
{
    return *(int*)((char*)*(void**)((char*)a1 + 0xc) + 0xc);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282BC0);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0_v(void) __asm__("func_00282CB0");

extern "C" int func_00282BC0(void)
{
    char* e = (char*)func_00282CB0_v();
    return *(int*)(e + 0xC);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282BE0__FPvT0);
#ifdef SKIP_ASM
int func_00282BE0(void* self, void* a1)
{
    return *(int*)((char*)*(void**)((char*)a1 + 0xc) + 0x1c);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282BF0);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1);

extern "C" int func_00282BF0(void* self, int a1)
{
    int* p = (int*)func_00282CB0(self, a1);
    if (p == 0) {
        return 0;
    }
    return *p;
}
#endif

extern "C" void* func_00272CC0(int);

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282C18__FPv);
#ifdef SKIP_ASM
void* func_00282C18(void* self)
{
    return func_00272CC0(*(int*)((char*)self + 0x2b8));
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282C38);
#ifdef SKIP_ASM
struct sBxsThreadSlot2C0 {
    sBxsThreadHdr hdr; // 0x00
    int unk0C;         // 0x0C
    short unk10;       // 0x10
    short unk12;       // 0x12
    int unk14;         // 0x14
    int unk18;         // 0x18
    int id;            // 0x1C
    int type;          // 0x20
};

struct sBxsEngineThreads {
    char pad[0x2C0];
    sBxsThreadSlot2C0 threads[16]; // 0x2C0
};

extern "C" sBxsThreadHdr* func_00282C38(void* self, int a1)
{
    sBxsEngineThreads* e = (sBxsEngineThreads*)self;
    int i = 0;
    do {
        if (e->threads[i].type == 0) {
            e->threads[i].type = a1;
            switch (a1) {
            case 1:
                e->threads[i].hdr.handle = -1;
                break;
            }
            return &e->threads[i].hdr;
        }
        i++;
    } while (i < 16);
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282C88__FPvT0);
#ifdef SKIP_ASM
void func_00282C88(void* self, void* a1)
{
    *(int*)((char*)a1 + 0x0) = 0;
    *(int*)((char*)a1 + 0x4) = 0;
    *(int*)((char*)a1 + 0x20) = 0;
    *(short*)((char*)a1 + 0x10) = 0;
    *(short*)((char*)a1 + 0x12) = 0;
    *(int*)((char*)a1 + 0x14) = -1;
    *(int*)((char*)a1 + 0x18) = 0;
    *(int*)((char*)a1 + 0xc) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282CB0);
#ifdef SKIP_ASM
extern "C" void* func_00282CB0(void* self, int a1)
{
    char* p = (char*)self + (a1 * 0x24 + 0x2c0);
    return *(int*)(p + 0x20) != 0 ? p : 0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282CD0);
#ifdef SKIP_ASM
void* func_00283200(void* self, int type);
extern void* D_00482060[];

extern "C" void* func_00282CD0(void* self)
{
    func_00283200(self, 2);
    *(void***)((char*)self + 0xC) = D_00482060;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0x14) = -1;
    *(int*)((char*)self + 0x18) = 9;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x20) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282D30);
#ifdef SKIP_ASM
// PORT: the callee also forwards four float args ($f12-$f15); bound to its (void*, int, int) symbol.
void* func_00282DB0_f4(void* self, int a1, int a2, float f0, float f1, float f2, float f3) __asm__("func_00282DB0__FPvii");

extern "C" void func_00282D30(void* self, float dt)
{
    int id = *(int*)((char*)self + 0x14);
    if (id >= 0) {
        float t = *(float*)((char*)self + 0x2C) + dt * 0.01666666753590107f;
        *(float*)((char*)self + 0x2C) = t;
        if (*(float*)((char*)self + 0x1C) + *(float*)((char*)self + 0x20) + *(float*)((char*)self + 0x24) - 0.009999999776482582f <= t) {
            func_00282DB0_f4(self, id, 9, 0.0f, 0.0f, 0.0f, 0.0f);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282DA8__FPvi);
#ifdef SKIP_ASM
void func_00282DA8(void* self, int val)
{
    *(int*)((char*)self + 0x10) = val;
}
#endif

extern "C" void* func_00282DD0(void*, int, int, int);

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282DB0__FPvii);
#ifdef SKIP_ASM
void* func_00282DB0(void* self, int a1, int a2)
{
    return func_00282DD0(self, a1, a2, *(int*)((char*)self + 0x28));
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282DD0);
#ifdef SKIP_ASM
struct sBxsVEntry2DD0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sBxsFade2DD0 {
    char pad_0x0[0xC];
    sBxsVEntry2DD0* vtable;     // 0xC
    char pad_0x10[0x4];
    int id;                     // 0x14
    int kind;                   // 0x18
    float rateA;                // 0x1C
    float rateB;                // 0x20
    float rateC;                // 0x24
    int arg;                    // 0x28
    int time;                   // 0x2C
};

// PORT: the unit declares func_00282DD0(void*, int, int, int) returning void*; the body also takes four floats and returns nothing.
extern "C" void func_00282DD0_impl(sBxsFade2DD0* self, int id, int kind, int arg, float t, float c, float a, float b) __asm__("func_00282DD0");
extern "C" void func_00282DD0_impl(sBxsFade2DD0* self, int id, int kind, int arg, float t, float c, float a, float b)
{
    if (self->kind != 9) {
        sBxsVEntry2DD0* vt = self->vtable;
        vt[5].fn((char*)self + vt[5].delta, self->id);
    }
    if (kind == 9 || a + b + c <= t) {
        self->kind = 9;
        self->rateA = 0.0f;
        self->rateB = 0.0f;
        self->id = -1;
        self->rateC = 0.0f;
        self->time = 0;
    } else {
        self->kind = kind;
        self->arg = arg;
        self->time = 0;
        self->id = id;
        self->rateA = a * 0.01666666753590107f;
        self->rateB = b * 0.01666666753590107f;
        self->rateC = c * 0.01666666753590107f;
        sBxsVEntry2DD0* vt = self->vtable;
        vt[4].fn((char*)self + vt[4].delta, self->id);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282EF0);
#ifdef SKIP_ASM
extern "C" int func_00282EF0(void* self, int a1)
{
    return *(int*)((char*)self + 0x14) == a1;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282F00);
#ifdef SKIP_ASM
class cBxScriptVirt {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
};

extern "C" void func_00282F00(void* self)
{
    (*(cBxScriptVirt**)((char*)self + 0x10))->v02();
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282F30);
#ifdef SKIP_ASM
extern "C" void func_00282F30(void* self)
{
    (*(cBxScriptVirt**)((char*)self + 0x10))->v03();
}
#endif

extern void* D_00482418[];

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282F60__FPv);
#ifdef SKIP_ASM
void* func_00282F60(void* self)
{
    *(void***)self = D_00482418;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282F80__FPv);
#ifdef SKIP_ASM
int func_00282F80(void* self)
{
    return (*(int*)((char*)self + 0x8) != 0);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282F90);
#ifdef SKIP_ASM
extern "C" void func_00274240(void* p, int a1);

extern "C" void func_00282F90(void* self)
{
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        func_00274240(p, 0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00282FB8);
#ifdef SKIP_ASM
extern "C" void* func_0027D2E8(void);
extern "C" void func_0027D400(void* mgr, void* self, int a2);

extern "C" void func_00282FB8(void* self, void* a1)
{
    *(void**)((char*)self + 0x8) = a1;
    func_0027D400(func_0027D2E8(), self, **(int**)((char*)a1 + 0x8));
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283000);
#ifdef SKIP_ASM
extern "C" void* func_0027D2E8(void);
extern "C" void func_0027D4A0(void* mgr, void* obj);

extern "C" void func_00283000(void* self)
{
    func_0027D4A0(func_0027D2E8(), self);
    *(int*)((char*)self + 0x8) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283038);
#ifdef SKIP_ASM
extern "C" void func_002749E8(void* self);

extern "C" void func_00283038(void* self)
{
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        func_002749E8(*(void**)((char*)p + 0x8));
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283060);
#ifdef SKIP_ASM
extern "C" void func_00274A08(void* self);

extern "C" void func_00283060(void* self)
{
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        func_00274A08(*(void**)((char*)p + 0x8));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_00283088);
#ifdef SKIP_ASM
extern void* D_004823E0[];
void* func_00282F60(void* self);

extern "C" void* func_00283088(void* self)
{
    func_00282F60(self);
    *(void***)self = D_004823E0;
    *(int*)((char*)self + 0xC) = 9;
    *(int*)((char*)self + 0x10) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_002830C8);
#ifdef SKIP_ASM
extern "C" void func_00282FB8(void* self, void* a1);
int func_002743C8(void* self);
char* func_0027C098(void* self);
char* func_0027C2A8(void* self);
char* func_0027C4B8(void* self);
char* func_0027C6A0(void* self);

extern "C" void func_002830C8(void* self, void* obj)
{
    func_00282FB8(self, obj);
    switch (func_002743C8(obj)) {
    case 0:
        *(int*)((char*)self + 0xC) = *(signed char*)(func_0027C098(obj) + 0x21);
        break;
    case 1:
        *(int*)((char*)self + 0xC) = *(signed char*)(func_0027C2A8(obj) + 0x21);
        break;
    case 2:
        *(int*)((char*)self + 0xC) = *(signed char*)(func_0027C4B8(obj) + 0x21);
        break;
    case 3:
        *(int*)((char*)self + 0xC) = *(signed char*)(func_0027C6A0(obj) + 0x1C);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_00283180);
#ifdef SKIP_ASM
extern "C" void func_00283000(void* self);

extern "C" void func_00283180(void* self)
{
    func_00283000(self);
    *(int*)((char*)self + 0xC) = 9;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002831B0);
#ifdef SKIP_ASM
// PORT: func_0027A668 is declared (void*) but takes (self, idx).
void* func_0027A668_2(void* self, int idx) __asm__("func_0027A668__FPv");
extern void* D_004A28A4;

extern "C" int func_002831B0(void* self, void* arg, int n)
{
    if (n >= 4) {
        return 0;
    }
    return *(int*)((char*)func_0027A668_2(D_004A28A4, *(int*)((char*)arg + 0x8)) + 0xC) ==
           *(int*)(*(char**)((char*)self + 0x10) + 0xF8);
}
#endif

extern void* D_00482558[];

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283200__FPvi);
#ifdef SKIP_ASM
void* func_00283200(void* self, int a1)
{
    *(void***)((char*)self + 0xc) = D_00482558;
    *(int*)self = a1;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283228);
#ifdef SKIP_ASM
extern "C" void func_002832D8(void* self);
void operator_delete(int* ptr);

extern "C" void func_00283228(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_00482558;
    if (*(int*)((char*)self + 0x4) != -1 && *(int*)((char*)self + 0x4) != 0) {
        func_002832D8(self);
        *(int*)((char*)self + 0x4) = -1;
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283298);
#ifdef SKIP_ASM
struct sBxsVEntryA {
    short delta;
    short index;
    int (*fn)(void*, void*);
};

extern "C" void func_00283298(void* self)
{
    char* mgr = (char*)func_0027D2E8();
    sBxsVEntryA* vt = *(sBxsVEntryA**)(mgr + 0x2A8);
    *(int*)((char*)self + 0x4) = vt[2].fn(mgr + vt[2].delta, self);
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_002832D8);
#ifdef SKIP_ASM
struct sBxsVEntryB {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_002832D8(void* self)
{
    char* mgr = (char*)func_0027D2E8();
    sBxsVEntryB* vt = *(sBxsVEntryB**)(mgr + 0x2A8);
    vt[3].fn(mgr + vt[3].delta, *(int*)((char*)self + 0x4));
    *(int*)((char*)self + 0x4) = -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_00283320);
#ifdef SKIP_ASM
class cScriptOwner3320 {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    // vptr at 0xC; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual int v06();
    virtual void* v07(int i);
};

extern "C" void func_00283320(cScriptOwner3320* self)
{
    int i = 0;
    int n = self->v06();
    for (; i < n; i++) {
        func_00283038(self->v07(i));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/bxscriptengine", func_002833A8);
#ifdef SKIP_ASM
class cScriptOwner33A8 {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    // vptr at 0xC; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual int v06();
    virtual void* v07(int i);
};

extern "C" void func_002833A8(cScriptOwner33A8* self)
{
    int i = 0;
    int n = self->v06();
    for (; i < n; i++) {
        func_00283060(self->v07(i));
    }
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283430__FPv);
#ifdef SKIP_ASM
void* func_00283430(void* self)
{
    void* t0 = (char*)*(void**)((char*)self + 0x8) + 0x1;
    *(int*)((char*)self + 0x8) = (int)t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("scripter/bxscriptengine", func_00283440__FPv);
#ifdef SKIP_ASM
void* func_00283440(void* self)
{
    void* t0 = (char*)*(void**)((char*)self + 0x8) - 0x1;
    *(int*)((char*)self + 0x8) = (int)t0;
    return t0;
}
#endif

