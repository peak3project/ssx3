#include "common.h"

//100%
INCLUDE_ASM("wscript/wscriptman", cWScriptMan_addProcess);
#ifdef SKIP_ASM
extern char D_00489908[];
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cWScriptProcess_cWScriptProcess(void* self, void* man, int a1, int a2);
int func_0030B260(void* self, void* a1);

extern "C" void* cWScriptMan_addProcess(void* self, int a1, int a2, int front)
{
    void* p = cWScriptProcess_cWScriptProcess(cMemMan_alloc(0x60, D_00489908, 0x20000000, 0), self, a1, a2);
    if (front != 0) {
        func_0030B260((char*)self + 0x2BC, p);
    } else {
        func_0030B260((char*)self + 0x2B4, p);
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", cWScriptMan_addProcess1);
#ifdef SKIP_ASM
extern char D_00489918[];
extern "C" void* func_00307128(void* self, void* man, int a1, int a2, int a3);
int func_0030B2C0(void* self, void* a1);

extern "C" void* cWScriptMan_addProcess1(void* self, int a1, int a2, int a3, int front)
{
    void* p = func_00307128(cMemMan_alloc(0x78, D_00489918, 0x20000000, 0), self, a1, a2, a3);
    if (front != 0) {
        func_0030B2C0((char*)self + 0x2BC, p);
    } else {
        func_0030B2C0((char*)self + 0x2B4, p);
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309618);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cWSObj_309618 {
public:
    char pad_0x00[0x5C];
    virtual void v00(int);
    virtual void v01();
};

extern "C" void* func_0030B320_a(void* self, int id) __asm__("func_0030B320");
extern "C" int func_0030B2D0_a(void* self, void* node) __asm__("func_0030B2D0");

extern "C" void func_00309618(char* self, int id) {
    cWSObj_309618* obj = (cWSObj_309618*)func_0030B320_a(self + 0x2B8, id);
    if (obj != 0) {
        func_0030B2D0_a(self + 0x2B8, obj);
        obj->v00(3);
        return;
    }
    obj = (cWSObj_309618*)func_0030B320_a(self + 0x2BC, id);
    if (obj != 0) {
        func_0030B2D0_a(self + 0x2BC, obj);
        obj->v00(3);
        return;
    }
    obj = (cWSObj_309618*)func_0030B320_a(self + 0x2B4, id);
    if (obj != 0) {
        func_0030B2D0_a(self + 0x2B4, obj);
        obj->v00(3);
    }
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_003096F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0030B2D0_vv(void* self, void* node) __asm__("func_0030B2D0");
extern "C" void func_003096F0(char* self, void* node) {
    if (func_0030B2D0_vv(self + 0x2B8, node) == 0 &&
        func_0030B2D0_vv(self + 0x2B4, node) == 0) {
        func_0030B2D0_vv(self + 0x2BC, node);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309750);
#ifdef SKIP_ASM
struct sVEntry00309750 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00309750(void* self, void* obj)
{
    void* saved = *(void**)((char*)self + 0x2A4);
    *(void**)((char*)self + 0x2A4) = obj;
    sVEntry00309750* vt = *(sVEntry00309750**)((char*)obj + 0x5C);
    vt[4].fn((char*)obj + vt[4].delta);
    *(void**)((char*)self + 0x2A4) = saved;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309798);
#ifdef SKIP_ASM
struct sVEntry00309798 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_00309798(void* self, void* obj)
{
    void* saved = *(void**)((char*)self + 0x2A4);
    *(void**)((char*)self + 0x2A4) = obj;
    sVEntry00309798* vt = *(sVEntry00309798**)((char*)obj + 0x5C);
    vt[6].fn((char*)obj + vt[6].delta);
    *(void**)((char*)self + 0x2A4) = saved;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_003097E0);
#ifdef SKIP_ASM
struct sWSOpData {
    int a;
    int b;
};

struct sWSOp {
    int op;
    sWSOpData data;
};

struct sWSOpList {
    int count;
    sWSOp ops[1];
};

static inline void sWSOpList_push(sWSOpList* l, sWSOp o)
{
    l->ops[l->count++] = o;
}

extern "C" void func_003097E0(void* self, int v)
{
    sWSOp o;
    o.op = 0x70000;
    o.data.a = v;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309848);
#ifdef SKIP_ASM
extern "C" void func_00309848(void* self)
{
    sWSOp o;
    o.op = 0x70001;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_003098B0);
#ifdef SKIP_ASM
extern "C" void func_003098B0(void* self)
{
    sWSOp o;
    o.op = 0x70002;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309918);
#ifdef SKIP_ASM
extern "C" void func_00309918(void* self, sWSOpData* d)
{
    sWSOp o;
    o.op = 0x70003;
    o.data = *d;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309990);
#ifdef SKIP_ASM
extern "C" void func_00309990(void* self)
{
    sWSOp o;
    o.op = 0x70004;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_003099F8);
#ifdef SKIP_ASM
extern "C" void func_003099F8(void* self)
{
    sWSOp o;
    o.op = 0x70005;
    sWSOpList_push((sWSOpList*)((char*)self + 0x40), o);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309A60);
#ifdef SKIP_ASM
struct cWScriptListHead;
struct cWScriptListNode;
extern "C" int func_0030B2D0(cWScriptListHead* self, cWScriptListNode* node);
int func_0030B260(void* self, void* a1);

extern "C" void func_00309A60(void* self, cWScriptListNode* node)
{
    func_0030B2D0((cWScriptListHead*)((char*)self + 0x2B4), node);
    func_0030B260((char*)self + 0x2B8, node);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309AA0);
#ifdef SKIP_ASM
struct cWScriptListHead;
struct cWScriptListNode;
extern "C" int func_0030B2D0(cWScriptListHead* self, cWScriptListNode* node);
extern "C" int func_0030B428(cWScriptListHead* self, cWScriptListNode* node);
int func_0030B260(void* self, void* a1);

extern "C" void func_00309AA0(void* self, cWScriptListNode* node)
{
    cWScriptListHead* list = (cWScriptListHead*)((char*)self + 0x2B8);
    if (func_0030B428(list, node) != 0) {
        func_0030B2D0(list, node);
        func_0030B260((char*)self + 0x2B4, node);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309B00);
#ifdef SKIP_ASM
int func_0030B260(void* self, void* a1);
extern "C" int func_0030B2D0(cWScriptListHead* self, cWScriptListNode* node);
extern "C" int func_0030B428(cWScriptListHead* self, cWScriptListNode* node);

extern "C" void func_00309B00(void* self, cWScriptListNode* node)
{
    cWScriptListHead* list = (cWScriptListHead*)((char*)self + 0x2B8);
    if (func_0030B428(list, node) != 0) {
        func_0030B2D0(list, node);
        func_0030B260((char*)self + 0x2B4, node);
    }
    *(unsigned int*)((char*)self + 0x2A0) = 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309B70);
#ifdef SKIP_ASM
extern "C" int func_003A6D18(void*, int*);

static inline bool func_00309B70_valid(int id) { return id != -1; }

extern "C" int func_00309B70(void* self, int id)
{
    if (func_00309B70_valid(id)) {
        return func_003A6D18(*(void**)((char*)self + 0x28C), &id);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309BA8);
#ifdef SKIP_ASM
struct func_00309BA8_sVec {
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));

struct func_00309BA8_sPos {
    char pad[8];
    float z;
};

struct func_00309BA8_sVEntry {
    short delta;
    short index;
    func_00309BA8_sPos* (*fn)(void*);
};

extern char* D_004A28A8;

static inline char* func_00309BA8_toPtr(unsigned int i)
{
    return (char*)(i << 2);
}

static inline char* func_00309BA8_get(char* e, unsigned int h)
{
    unsigned int i = ((unsigned int*)*(char**)(e + 0x1C))[h >> 8] >> 8;
    if (i == 0) {
        return 0;
    }
    return func_00309BA8_toPtr(i);
}

static inline char* func_00309BA8_resolve(char* tbl, unsigned int h)
{
    char* e = ((char**)*(char**)(tbl + 0x8))[h & 0xFF];
    if (e == 0) {
        return 0;
    }
    return func_00309BA8_get(e, h);
}

extern "C" float func_00309BA8(void* self)
{
    if (*(int*)((char*)self + 0x28) == 0) {
        return 0.0f;
    }
    char* node = func_00309BA8_resolve(**(char***)((char*)self + 0x28C), *(unsigned int*)((char*)self + 0x2C));
    char* list = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
    char* obj = *(char**)(list + (*(int*)((char*)self + 0x30) << 2) + 0x28);
    char* sub = obj + 0x6C0;
    func_00309BA8_sVEntry* vt = *(func_00309BA8_sVEntry**)sub;
    func_00309BA8_sPos* r = vt[5].fn(sub + vt[5].delta);
    float z = r->z;
    func_00309BA8_sVec pos = *(func_00309BA8_sVec*)(node + 0x40);
    float d = z - pos.z;
    if (d >= 0.0f) {
        return d;
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309C88);
#ifdef SKIP_ASM
extern "C" int func_003A6D18(void*, int*);
struct func_00309DD0_sValue;
struct sLunoValue_9C88 {
    int word0;
    int word1;
    int type;
};
struct sLunoCall_9C88 {
    int pad[4];
};
void func_00226600(void* self, int a1, int a2);
extern "C" void* func_002224A8(void* self);
extern "C" void func_002224B8(void* self, void* args, void* table, void* ret);
extern "C" void func_00225B90(func_00309DD0_sValue* self, int flags);
extern "C" void func_00309C88(void* self, int* handle)
{
    sLunoValue_9C88 arg;
    sLunoValue_9C88 ret;
    sLunoCall_9C88 call;
    func_00226600(&arg, func_003A6D18(*(void**)((char*)self + 0x28C), handle), 0);
    ret.type = 0;
    ret.word0 = 0;
    void* table = *(void**)((char*)self + (*(unsigned char*)handle << 2) + 0x3CC);
    func_002224A8(&call);
    func_002224B8(&call, &arg, table, &ret);
    func_00225B90((func_00309DD0_sValue*)&ret, 2);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309D20);
#ifdef SKIP_ASM
struct func_00309DD0_sValue;
// cLunoValue: { word0, word1, type } (same layout as func_00309DD0_sValue)
struct func_00309D20_sValue {
    int word0;
    int word1;
    int type;
};
struct func_00309D20_sCall {
    int pad[4];
};

void func_00226600(void* self, int a1, int a2);
extern "C" void* func_002224A8(void* self);
extern "C" void func_002224B8(void* self, void* args, void* table, void* ret);
extern "C" void func_00225B90(func_00309DD0_sValue* self, int flags);

extern "C" void func_00309D20(void* self, int* handle, int id)
{
    func_00309D20_sValue arg;
    func_00309D20_sValue ret;
    func_00309D20_sCall call;
    int saved = *(int*)((char*)self + 0x290);
    *(int*)((char*)self + 0x290) = id;
    func_00226600(&arg, func_003A6D18(*(void**)((char*)self + 0x28C), handle), 0);
    ret.type = 0;
    ret.word0 = 0;
    void* table = *(void**)((char*)self + (*(unsigned char*)handle << 2) + 0x3CC);
    func_002224A8(&call);
    func_002224B8(&call, &arg, table, &ret);
    *(int*)((char*)self + 0x290) = saved;
    func_00225B90((func_00309DD0_sValue*)&ret, 2);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309DD0);
#ifdef SKIP_ASM
// cLunoValue (luno/lunovm): { word0, word1, type }
struct func_00309DD0_sValue {
    int word0;
    int word1;
    int type;
};

void* func_00226620(void* self);
extern "C" func_00309DD0_sValue* func_00225248(void* table, func_00309DD0_sValue* key);
extern "C" void func_00225B90(func_00309DD0_sValue* self, int flags);

extern "C" int func_00309DD0(void* self, int idx, int value)
{
    int off = idx << 2;
    char* base = (char*)self + 0x3CC;
    void** slot = (void**)(base + off);
    if (*slot != 0) {
        func_00309DD0_sValue key;
        key.type = 3;
        *(int*)func_00226620(&key) = value;
        int r = func_00225248(*slot, &key)->type == 5;
        func_00225B90(&key, 2);
        return r;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_00309E50);
#ifdef SKIP_ASM
struct func_00309E50_sArg {
    int word0;
    int word1;
};
struct func_00309E50_sCall {
    int pad[4];
};

extern "C" void* func_002224A8(void* self);
extern "C" void func_002224B8(void* self, void* args, void* table, void* ret);

extern "C" void func_00309E50(void* self, int idx, int value)
{
    func_00309DD0_sValue key;
    key.type = 3;
    *(int*)func_00226620(&key) = value;
    int off = idx << 2;
    char* base = (char*)self + 0x3CC;
    void** slot = (void**)(base + off);
    func_00309E50_sArg arg = *(func_00309E50_sArg*)func_00225248(*slot, &key);
    func_00309DD0_sValue ret;
    ret.type = 0;
    ret.word0 = 0;
    func_00309E50_sCall call;
    func_002224A8(&call);
    func_002224B8(&call, &arg, *slot, &ret);
    func_00225B90(&ret, 2);
    func_00225B90(&key, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_00309F18);
#ifdef SKIP_ASM
struct cWorldView;
int cWorldView_getNumSections(cWorldView* view);

struct sWSSection9F18 {
    short type;                 // 0x0
    short pad2;
    int f4;
    int f8;
};

struct sWSWorld9F18 {
    char* view;                 // 0x0 (cWorldView at +0x10)
    struct {
        int f0;
        sWSSection9F18* sections;   // 0x4
    }* info;                    // 0x4
};

struct sWSMan9F18 {
    int f0;                     // 0x000
    char pad4[0x288];
    sWSWorld9F18* world;        // 0x28C
    int f290;                   // 0x290
    int f294;                   // 0x294
    int f298;                   // 0x298
    char pad29C[0x8];
    int f2A4;                   // 0x2A4
    int f2A8;                   // 0x2A8
    char pad2AC[0x14];
    char tables[1][0x10C];      // 0x2C0
};

struct cWScriptIdTable;
extern "C" void func_0030C390(cWScriptIdTable* self);
extern "C" void func_00309C88(void* self, int* idx);
extern "C" void func_002D9B40(void);
extern "C" int func_003A6BA8(void* world, int i);
extern "C" int* func_003A6BD8(void* world, int i);

static inline bool wsIsType3_9F18(sWSSection9F18* s)
{
    return s->type == 3;
}

extern "C" void func_00309F18(sWSMan9F18* self)
{
    int i;
    int saved;
    int n;
    func_002D9B40();
    {
        int k;
        for (k = 0; k < 1; k++) {
            func_0030C390((cWScriptIdTable*)self->tables[k]);
        }
    }
    saved = self->f0;
    self->f0 = -1;
    self->f290 = 0;
    self->f294 = 0;
    self->f298 = 0;
    self->f2A4 = 0;
    self->f2A8 = 0;
    n = cWorldView_getNumSections((cWorldView*)(self->world->view + 0x10));
    for (i = 0; i < n; i++) {
        if (wsIsType3_9F18(&self->world->info->sections[i])) {
            int* p = func_003A6BD8(self->world, i);
            if (p != 0) {
                int cnt = func_003A6BA8(self->world, i);
                int j;
                for (j = 0; j < cnt; j++, p++) {
                    func_00309C88(self, p);
                }
            }
        }
    }
    self->f290 = 0;
    self->f294 = 0;
    self->f298 = 0;
    self->f2A4 = 0;
    self->f2A8 = 0;
    self->f0 = saved;
}
#endif

INCLUDE_ASM("wscript/wscriptman", func_0030A060);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A270);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);

extern "C" int func_0030A270(void* self, int id)
{
    return func_003A6B78(*(void**)((char*)self + 0x28C), id, 1) != -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A298);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);
extern "C" void func_00309C88(void* self, int* idx);

extern "C" void func_0030A298(void* self, int id)
{
    int idx;
    *(int*)((char*)self + 0x290) = id;
    idx = func_003A6B78(*(void**)((char*)self + 0x28C), id, 1);
    int ok = idx != -1;
    if (ok) {
        func_00309C88(self, &idx);
    }
    *(int*)((char*)self + 0x290) = 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A2E8);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);

extern "C" int func_0030A2E8(void* self, int id)
{
    return func_003A6B78(*(void**)((char*)self + 0x28C), id, 3) != -1;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A310);
#ifdef SKIP_ASM
struct sEntry_A310 {
    short type;
    char pad[10];
};
// PORT: the helpers take the object as int in this unit.
extern "C" int func_0030A310(void* self, void* obj)
{
    char* o = (char*)obj;
    if (*(int*)(o + 0xC) != 0) {
        return 1;
    }
    sEntry_A310* tab = *(sEntry_A310**)(*(char**)(*(char**)((char*)self + 0x28C) + 0x4) + 0x4);
    bool isType3 = tab[*(unsigned char*)(o + 0x78)].type == 3;
    if (isType3) {
        if (func_0030A270(self, (int)obj) || func_0030A2E8(self, (int)obj)) {
            return 1;
        }
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A3A0);
#ifdef SKIP_ASM
// script object controller: 0xC bytes of data, then the vptr
class cWScriptCtl {
public:
    int f0;
    int f4;
    int f8;
    // vptr at 0xC; slot N at vtable offset N*8
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
    virtual int v21(void* obj);
    virtual int v22(void* obj);
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
};

struct func_0030A3A0_sType {
    short type;
    short pad;
    int f4;
    int f8;
};

// PORT: func_0030A270/func_0030A298 take the object pointer as an int id
extern "C" void func_0030A3A0(void* self, void* obj)
{
    cWScriptCtl* ctl = *(cWScriptCtl**)((char*)obj + 0xC);
    if (ctl != 0) {
        if (ctl->v20() != 0) {
            (*(cWScriptCtl**)((char*)obj + 0xC))->v21(obj);
        }
    } else {
        func_0030A3A0_sType* t = *(func_0030A3A0_sType**)(*(char**)(*(char**)((char*)self + 0x28C) + 0x4) + 0x4);
        bool isScript = t[*(unsigned char*)((char*)obj + 0x78)].type == 3;
        if (isScript) {
            if (func_0030A270(self, (int)obj) != 0) {
                func_0030A298(self, (int)obj);
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A460);
#ifdef SKIP_ASM
// script object controller: 0xC bytes of data, then the vptr
extern "C" void func_0030A548(void* self, int id);

// PORT: func_0030A2E8/func_0030A548 take the object pointer as an int id
extern "C" void func_0030A460(void* self, void* obj)
{
    cWScriptCtl* ctl = *(cWScriptCtl**)((char*)obj + 0xC);
    if (ctl != 0) {
        if (ctl->v20() != 0) {
            (*(cWScriptCtl**)((char*)obj + 0xC))->v22(obj);
            return;
        }
        ctl = *(cWScriptCtl**)((char*)obj + 0xC);
        if (*(short*)((char*)ctl + 0x10) == 6) {
            return;
        }
        obj = *(void**)((char*)ctl + 0x18);
        if (func_0030A2E8(self, (int)obj) != 0) {
            func_0030A548(self, (int)obj);
            return;
        }
        (*(cWScriptCtl**)((char*)obj + 0xC))->v35();
        return;
    }
    if (func_0030A2E8(self, (int)obj) != 0) {
        func_0030A548(self, (int)obj);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A548);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);
extern "C" void func_00309C88(void* self, int* idx);

extern "C" void func_0030A548(void* self, int id)
{
    int idx;
    *(int*)((char*)self + 0x290) = id;
    idx = func_003A6B78(*(void**)((char*)self + 0x28C), id, 3);
    int ok = idx != -1;
    if (ok) {
        func_00309C88(self, &idx);
    }
    *(int*)((char*)self + 0x290) = 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A598);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);

extern "C" int func_0030A598(void* self, int id)
{
    return func_003A6B78(*(void**)((char*)self + 0x28C), id, 4) != -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A5C0);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);
extern "C" void func_00309C88(void* self, int* idx);

extern "C" void func_0030A5C0(void* self, int id)
{
    int idx;
    *(int*)((char*)self + 0x290) = id;
    idx = func_003A6B78(*(void**)((char*)self + 0x28C), id, 4);
    int ok = idx != -1;
    if (ok) {
        func_00309C88(self, &idx);
    }
    *(int*)((char*)self + 0x290) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A610);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);
extern "C" void func_00309C88(void* self, int* idx);

extern "C" void func_0030A610(void* self, int id)
{
    int idx;
    *(int*)((char*)self + 0x290) = id;
    idx = func_003A6B78(*(void**)((char*)self + 0x28C), id, 0);
    int ok = idx != -1;
    if (ok) {
        func_00309C88(self, &idx);
    }
    *(int*)((char*)self + 0x290) = 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A660);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);

extern "C" int func_0030A660(void* self, int id)
{
    return func_003A6B78(*(void**)((char*)self + 0x28C), id, 5) != -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030A688);
#ifdef SKIP_ASM
extern "C" int func_003A6B78(void* world, int id, int flag);
extern "C" void func_00309C88(void* self, int* idx);

extern "C" void func_0030A688(void* self, int id)
{
    int idx;
    *(int*)((char*)self + 0x290) = id;
    idx = func_003A6B78(*(void**)((char*)self + 0x28C), id, 5);
    int ok = idx != -1;
    if (ok) {
        func_00309C88(self, &idx);
    }
    *(int*)((char*)self + 0x290) = 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A6D8);
#ifdef SKIP_ASM
extern "C" void func_00307EC0(void* p);

extern "C" void func_0030A6D8(void* self)
{
    void* p = *(void**)((char*)self + 0x2A4);
    if (p != 0) {
        func_00307EC0(p);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A700);
#ifdef SKIP_ASM
extern "C" void func_00307F58(void* p);

extern "C" void func_0030A700(void* self)
{
    void* p = *(void**)((char*)self + 0x2A4);
    if (p != 0) {
        func_00307F58(p);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A728);
#ifdef SKIP_ASM
extern "C" void* func_0030B320(void* self, int id);
extern "C" void func_00307D78(void* obj);
extern "C" void func_00307E10(void* obj);

extern "C" void func_0030A728(void* self, unsigned int id, int kind)
{
    void* obj = *(void**)((char*)self + 0x2A4);
    switch (kind) {
    case 1:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B320((char*)self + 0x2B4, id);
        }
        if (obj != 0) {
            func_00309750(self, obj);
        }
        break;
    case 0:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B320((char*)self + 0x2B8, id);
        }
        if (obj != 0) {
            func_00309798(self, obj);
        }
        break;
    case 2:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B320((char*)self + 0x2B8, id);
        }
        if (obj != 0) {
            func_00307E10(obj);
        }
        break;
    case 18:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B320((char*)self + 0x2B8, id);
        }
        if (obj != 0) {
            func_00307D78(obj);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030A868);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0030A728(void* self, unsigned int id, int kind);
// PORT: the unit defines func_0030C7C0 later as (cWSQueue*, int, int, int)
extern "C" void func_0030C7C0_a(void* queue, unsigned int id, int kind, int ctx) __asm__("func_0030C7C0");
extern "C" void* func_0030AEB8(void* self);
extern "C" int func_0030B8C0(void* self);
extern "C" int func_00153D78(void* iface, unsigned int id);
extern "C" int func_00153DD0(void* iface, unsigned int id);
extern "C" int func_00153E28(void* iface, unsigned int id);
extern "C" int func_00153E80(void* iface, unsigned int id);
extern "C" int func_00153ED8(void* iface, unsigned int id);
extern "C" int func_00153FD8(void* iface, unsigned int id);
extern "C" void* func_0028B180();
extern "C" void func_0029D6E0(void* p, unsigned int id);
extern "C" void func_0029DBB0(void* p, int a1);
extern char* D_004A28A8;
extern signed char D_00535C10[];

class cWSObj_30A868 {
public:
    char pad_0x00[0x20];
    unsigned int id;        // 0x20
    char pad_0x24[0x5C - 0x24];
    // vptr at 0x5C
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
};

// PORT: the unit defines func_0030B388 later with its own class type
extern "C" cWSObj_30A868* func_0030B388_a(void* self, unsigned int id) __asm__("func_0030B388");

extern "C" int func_0030A868(char* self, unsigned int id, unsigned int cmd, int ctx)
{
    int force = 0;
    if (cmd == 15 || cmd == 19) {
        force = 1;
    }
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (force == 0) {
        if (D_00535C10[0] != 4) {
            return 0;
        }
        if (*(int*)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x7C) != 1) {
            return 0;
        }
    }
    int saved = *(int*)self;
    if (ctx != -1) {
        *(int*)self = ctx;
    }
    switch (cmd) {
    case 0:
    case 1:
    case 2:
    case 18:
        func_0030A728(self, id, cmd);
        break;
    case 8:
    case 9:
    case 11: {
        int v = **(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        int busy = v != 0 && v < 10;
        if (!busy) {
            func_0030C7C0_a(self + 0x1C4, id, cmd, *(int*)self);
        }
        break;
    }
    }
    int result = 0;
    cWSObj_30A868* obj = (cWSObj_30A868*)func_0030AEB8(self);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 10);
    switch (cmd) {
    case 0:
        break;
    case 3:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B388_a(self + 0x2B8, id);
            if (obj == 0) {
                obj = func_0030B388_a(self + 0x2B4, id);
            }
        }
        if (obj != 0) {
            obj->v17();
            func_0029D6E0(func_0028B180(), id);
        }
        break;
    case 4:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B388_a(self + 0x2B8, id);
        }
        if (obj != 0) {
            obj->v02();
        }
        break;
    case 5:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B388_a(self + 0x2B8, id);
        }
        if (obj != 0) {
            obj->v19();
            func_0029DBB0(func_0028B180(), 0);
        }
        break;
    case 17:
        if (id != 0xFFFFFFFF) {
            obj = func_0030B388_a(self + 0x2B8, id);
            if (obj == 0) {
                obj = func_0030B388_a(self + 0x2B4, id);
            }
        }
        if (obj != 0) {
            obj->v20();
        }
        break;
    case 13:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        result = func_00153E28(iface, id) != 0;
        break;
    case 12:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        result = func_00153DD0(iface, id) != 0;
        break;
    case 16:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        if (*(int*)(self + 0x2AC) == 1) {
            break;
        }
        if (func_0030B8C0(self) != 0) {
            break;
        }
        if (func_00153ED8(iface, id) != 0) {
            result = 1;
        } else {
            result = 0;
        }
        break;
    case 19:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        result = func_00153FD8(iface, id) == -1;
        break;
    case 14:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        result = func_00153E80(iface, id) != 0;
        break;
    case 15:
        if (id == 0xFFFFFFFF) {
            if (obj != 0) {
                id = obj->id;
            }
            if (id == 0xFFFFFFFF) {
                break;
            }
        }
        result = func_00153D78(iface, id) != 0;
        break;
    }
    *(int*)self = saved;
    return result;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030AC98);
#ifdef SKIP_ASM
struct func_00309DD0_sValue;
void func_00226600(void* self, int a1, int a2);
extern "C" void* func_002224A8(void* self);
extern "C" void func_002224B8(void* self, void* args, void* table, void* ret);
extern "C" void func_00225B90(func_00309DD0_sValue* self, int flags);
extern "C" void* func_00224DA0(void* mem, int a1);
extern "C" void func_00224DF0(void* obj, int flags);
extern char D_004898D8[];

// cLunoValue: { word0, word1, type }
struct func_0030AC98_sValue {
    int word0;
    int word1;
    int type;
};
struct func_0030AC98_sCall {
    int pad[4];
};

extern "C" void func_0030AC98(void* self, void* obj, int a2)
{
    func_0030AC98_sValue arg;
    func_0030AC98_sValue ret;
    func_0030AC98_sCall call;
    int savedId;
    void* savedObj = *(void**)((char*)self + 0x2A4);
    *(void**)((char*)self + 0x2A4) = obj;
    savedId = *(int*)((char*)self + 0x290);
    func_00226600(&arg, a2, 0);
    ret.type = 0;
    ret.word0 = 0;
    func_002224A8(&call);
    void* table = *(void**)(*(char**)((char*)self + 0x2A4) + 0x1C);
    if (table != 0) {
        func_002224B8(&call, &arg, table, &ret);
    } else {
        table = func_00224DA0(cMemMan_alloc(4, D_004898D8, 0x20000000, 0), 8);
        func_002224B8(&call, &arg, table, &ret);
        if (table != 0) {
            func_00224DF0(table, 3);
        }
    }
    *(void**)((char*)self + 0x2A4) = savedObj;
    *(int*)((char*)self + 0x290) = savedId;
    func_00225B90((func_00309DD0_sValue*)&ret, 2);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030ADA8);
#ifdef SKIP_ASM
struct func_00309DD0_sValue;
void func_00226600(void* self, int a1, int a2);
extern "C" void* func_002224A8(void* self);
extern "C" void func_002224B8(void* self, void* args, void* table, void* ret);
extern "C" void func_00225B90(func_00309DD0_sValue* self, int flags);
extern "C" void* func_00224DA0(void* mem, int a1);
extern "C" void func_00224DF0(void* obj, int flags);
extern char D_004898D8[];

// cLunoValue: { word0, word1, type }
struct func_0030ADA8_sValue {
    int word0;
    int word1;
    int type;
};
struct func_0030ADA8_sCall {
    int pad[4];
};

extern "C" void func_0030ADA8(void* self, void* obj, int a2)
{
    func_0030ADA8_sValue arg;
    func_0030ADA8_sValue ret;
    func_0030ADA8_sCall call;
    int savedId;
    void* savedObj = *(void**)((char*)self + 0x2A8);
    *(void**)((char*)self + 0x2A8) = obj;
    savedId = *(int*)((char*)self + 0x290);
    func_00226600(&arg, a2, 0);
    ret.type = 0;
    ret.word0 = 0;
    func_002224A8(&call);
    void* table = *(void**)(*(char**)(*(char**)((char*)self + 0x2A8) + 0x3C) + 0x1C);
    if (table != 0) {
        func_002224B8(&call, &arg, table, &ret);
    } else {
        table = func_00224DA0(cMemMan_alloc(4, D_004898D8, 0x20000000, 0), 8);
        func_002224B8(&call, &arg, table, &ret);
        if (table != 0) {
            func_00224DF0(table, 3);
        }
    }
    *(void**)((char*)self + 0x2A8) = savedObj;
    *(int*)((char*)self + 0x290) = savedId;
    func_00225B90((func_00309DD0_sValue*)&ret, 2);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030AEB8);
#ifdef SKIP_ASM
struct sVEntry0030AEB8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void* func_0030AEB8(void* self)
{
    void* obj = *(void**)((char*)self + 0x2A4);
    if (obj != 0) {
        sVEntry0030AEB8* vt = *(sVEntry0030AEB8**)((char*)obj + 0x5C);
        if (vt[3].fn((char*)obj + vt[3].delta) != 0) {
            return *(void**)((char*)self + 0x2A4);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030AF08);
#ifdef SKIP_ASM
struct sScriptFlags_AF08 {
    unsigned int f0 : 3;
    unsigned int f1 : 4;
    unsigned int f2 : 3;
    unsigned int f3 : 2;
    unsigned int f4 : 4;
    unsigned short f5 : 3;
    unsigned int f6 : 3;
    unsigned int f7 : 6;
    unsigned int f8 : 4;
    unsigned int f9 : 3;
    unsigned int f10 : 7;
    unsigned int f11 : 1;
    unsigned int pad : 7;
    unsigned int f13 : 2;
    unsigned int f15 : 4;
    unsigned char f14 : 3;
};

// Reads one packed script setting; 0 when no settings block is loaded.
extern "C" int func_0030AF08(void* self, int a1, int which)
{
    sScriptFlags_AF08* fl = *(sScriptFlags_AF08**)((char*)self + 0x29C);
    if (fl != 0) {
        switch (which) {
        case 0: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f0;
        case 1: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f1;
        case 2: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f2;
        case 3: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f3;
        case 4: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f4;
        case 5: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f5;
        case 6: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f6;
        case 7: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f7;
        case 8: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f8;
        case 9: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f9;
        case 10: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f10;
        case 11: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f11;
        case 13: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f13;
        case 14: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f14;
        case 15: return (*(sScriptFlags_AF08**)((char*)self + 0x29C))->f15;
        }
    }
    return 0;
}
#endif

struct cWScriptListNode {
    char pad_0x00[0x18];
    void* next;
};

struct cWScriptListHead {
    void* head;
};

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B058__FPv);
#ifdef SKIP_ASM
void* func_0030B058(void* self)
{
    ((cWScriptListHead*)self)->head = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B068);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

class func_0030B068_cNode {
public:
    char pad_0x00[0x18];
    func_0030B068_cNode* next;   // 0x18
    char pad_0x1C[0x5C - 0x1C];
    // vptr at 0x5C; slot N at vtable offset N*8
    virtual void v01(int);
};

extern "C" void func_0030B068(func_0030B068_cNode** self, int flags)
{
    func_0030B068_cNode* n = *self;
    while (n != 0) {
        func_0030B068_cNode* cur = n;
        n = n->next;
        if (cur != 0) {
            cur->v01(3);
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B0E8);
#ifdef SKIP_ASM
struct sVE_B0E8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sNode_B0E8 {
    char pad0[0x18];
    sNode_B0E8* next;   // 0x18
    char pad1C[0x24 - 0x1C];
    int key;            // 0x24
    char pad28[0x5C - 0x28];
    sVE_B0E8* vt;       // 0x5C
};

static inline void destroy_B0E8(sNode_B0E8* n)
{
    if (n != 0) {
        n->vt[1].fn((char*)n + n->vt[1].delta, 3);
    }
}

// Deletes the leading run of nodes with the given key, then the run after the new head.
extern "C" void func_0030B0E8(sNode_B0E8** head, int key)
{
    if (*head == 0) {
        return;
    }
    sNode_B0E8* next = (*head)->next;
    if ((*head)->key == key) {
        for (;;) {
            destroy_B0E8(*head);
            *head = next;
            sNode_B0E8* cur = next;
            if (cur == 0) {
                return;
            }
            next = cur->next;
            if (cur->key != key) {
                break;
            }
        }
    }
    if (*head == 0) {
        return;
    }
    sNode_B0E8* n = (*head)->next;
    while (n != 0) {
        sNode_B0E8* cur = n;
        n = cur->next;
        if (cur->key != key) {
            break;
        }
        destroy_B0E8(cur);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B1B8);
#ifdef SKIP_ASM
class func_0030B1B8_cObj {
public:
    char pad_0x00[0x5C];
    virtual ~func_0030B1B8_cObj(); // vptr at 0x5C
};

extern "C" void* func_0030B208(void* self);

extern "C" void func_0030B1B8(void* self)
{
    func_0030B1B8_cObj* p;
    while ((p = (func_0030B1B8_cObj*)func_0030B208(self)) != 0) {
        delete p;
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B208);
#ifdef SKIP_ASM
extern "C" void* func_0030B208(void* self)
{
    cWScriptListNode* p = (cWScriptListNode*)((cWScriptListHead*)self)->head;
    if (p != 0) {
        ((cWScriptListHead*)self)->head = p->next;
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B228);
#ifdef SKIP_ASM
extern "C" int func_0030B228(cWScriptListHead* self)
{
    int n = 0;
    cWScriptListNode* p = (cWScriptListNode*)self->head;
    while (p != 0) {
        p = (cWScriptListNode*)p->next;
        n++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B260__FPvT0);
#ifdef SKIP_ASM
int func_0030B260(void* self, void* a1)
{
    int t0 = (int)((cWScriptListHead*)self)->head;
    ((cWScriptListNode*)a1)->next = (void*)t0;
    ((cWScriptListHead*)self)->head = a1;
    return t0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B270);
#ifdef SKIP_ASM
extern "C" void func_0030B270(cWScriptListHead* self, cWScriptListNode* node)
{
    node->next = 0;
    cWScriptListNode* p = (cWScriptListNode*)self->head;
    if (p != 0) {
        while (p->next != 0) {
            p = (cWScriptListNode*)p->next;
        }
        p->next = node;
    } else {
        self->head = node;
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B2C0__FPvT0);
#ifdef SKIP_ASM
int func_0030B2C0(void* self, void* a1)
{
    int t0 = (int)((cWScriptListHead*)self)->head;
    ((cWScriptListNode*)a1)->next = (void*)t0;
    ((cWScriptListHead*)self)->head = a1;
    return t0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B2D0);
#ifdef SKIP_ASM
extern "C" int func_0030B2D0(cWScriptListHead* self, cWScriptListNode* node)
{
    if (node == self->head) {
        self->head = node->next;
        return 1;
    }
    cWScriptListNode* p = (cWScriptListNode*)self->head;
    if (p != 0) {
        cWScriptListNode* prev = p;
        do {
            p = (cWScriptListNode*)p->next;
            if (p == node) {
                prev->next = p->next;
                return 1;
            }
            prev = p;
        } while (p != 0);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B320);
#ifdef SKIP_ASM
extern "C" void* func_0030B320(void* self, int id)
{
    void* p = *(void**)self;
    while (p != 0) {
        if (*(int*)((char*)p + 0x20) == id) {
            return p;
        }
        p = *(void**)((char*)p + 0x18);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B350);
#ifdef SKIP_ASM
extern "C" int GetHashValue32__FPc(int);

extern "C" void func_0030B350(void *arg0, int arg1) {
    func_0030B320(arg0, GetHashValue32__FPc(arg1));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B388);
#ifdef SKIP_ASM
class func_0030B388_cObj {
public:
    char pad_0x00[0x5C];
    // vptr at 0x5C
    virtual void v01();
    virtual void v02();
    virtual int v03(); // 0x18
};

extern "C" void* func_0030B320(void*, int);

extern "C" func_0030B388_cObj* func_0030B388(void* self, unsigned int id)
{
    func_0030B388_cObj* result = 0;
    if (id != 0xFFFFFFFF) {
        func_0030B388_cObj* p = (func_0030B388_cObj*)func_0030B320(self, id);
        if (p != 0) {
            if (p->v03()) {
                result = p;
            }
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B3F0);
#ifdef SKIP_ASM
extern "C" void* func_0030B388_h(void* self, int hash) __asm__("func_0030B388");

extern "C" void func_0030B3F0(void* self, int name) {
    func_0030B388_h(self, GetHashValue32__FPc(name));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B428);
#ifdef SKIP_ASM
extern "C" int func_0030B428(cWScriptListHead* self, cWScriptListNode* node)
{
    cWScriptListNode* p;
    for (p = (cWScriptListNode*)self->head; p != 0; p = (cWScriptListNode*)p->next) {
        if (p == node) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B458);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_0030B388_vv(void* self, void* node) __asm__("func_0030B388");
extern "C" void func_0030B458(char* self, void* node) {
    if (func_0030B388_vv(self + 0x2B8, node) == 0 &&
        func_0030B388_vv(self + 0x2B4, node) == 0) {
        func_0030B388_vv(self + 0x2BC, node);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B4B8__FPv);
#ifdef SKIP_ASM
void func_0030B4B8(void* self)
{
}
#endif

// self+0x4, +0x10, +0x1c, +0x28 are 0xc-byte slots of shape
// { int enabled; int valueB; int valueC; } (see cWScriptSlot below);
// kept as raw offsets here since struct-pointer codegen regresses
// these below their current objdiff match on this compiler.
struct cWScriptSlot {
    int enabled;
    int valueB;
    int valueC;
};

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B4C0__FPvii);
#ifdef SKIP_ASM
void func_0030B4C0(void* self, int b, int c)
{
    *(int*)((char*)self + 0x4) = 1;
    *(int*)((char*)self + 0x8) = b;
    *(int*)((char*)self + 0xc) = c;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B4D8__FPvii);
#ifdef SKIP_ASM
void func_0030B4D8(void* self, int b, int c)
{
    *(int*)((char*)self + 0x10) = 1;
    *(int*)((char*)self + 0x14) = b;
    *(int*)((char*)self + 0x18) = c;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B4F0__FPvii);
#ifdef SKIP_ASM
void func_0030B4F0(void* self, int b, int c)
{
    *(int*)((char*)self + 0x1c) = 1;
    *(int*)((char*)self + 0x20) = b;
    *(int*)((char*)self + 0x24) = c;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B508__FPviT0);
#ifdef SKIP_ASM
void func_0030B508(void* self, int c, void* src)
{
    *(int*)((char*)self + 0x28) = 1;
    *(int*)((char*)self + 0x30) = c;
    *(int*)((char*)self + 0x2c) = *(int*)((char*)src + 0x78);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B520);
#ifdef SKIP_ASM
struct cWScriptPair {
    int valueB;
    int valueC;
};

extern "C" void func_0030B520(void* self, cWScriptPair* src)
{
    *(int*)((char*)self + 0x34) = 1;
    *(cWScriptPair*)((char*)self + 0x38) = *src;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B540);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void func_0026CDF8(void* p);
extern "C" void func_0026F228(void* p);

extern "C" void func_0030B540(void* self)
{
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026F228(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    *(int*)((char*)self + 0x2AC) = 1;
    *(int*)((char*)self + 0x2B0) = *(int*)((char*)self + 0x2A0);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B590);
#ifdef SKIP_ASM
extern "C" int func_0026CAF8(void*, int);
extern "C" int func_0030B590(char* self) {
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026F228(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    if (func_0026CAF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34), *(int*)(self + 0x2A0)) != 0) {
        *(int*)(self + 0x2AC) = 5;
        *(int*)(self + 0x2B0) = *(int*)(self + 0x2A0);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B608);
#ifdef SKIP_ASM
void func_0026CBB0(void* self);

extern "C" void func_0030B608(void* self)
{
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026CBB0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    *(int*)((char*)self + 0x2AC) = 6;
    *(int*)((char*)self + 0x2B0) = *(int*)((char*)self + 0x2A0);
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B658);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void func_0026CDF8(void* p);
void func_0026CBB0(void* self);
extern "C" void func_0026F228(void* p);
extern "C" void func_0026F7B8(int* self);
extern "C" void func_001235F8(void* self);

extern "C" void func_0030B658(void* self)
{
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026CBB0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026F228(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    func_0026F7B8(*(int**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
    func_001235F8(*(void**)(riders + (*(int*)self << 2) + 0x28));
    *(int*)((char*)self + 0x2AC) = 3;
    *(int*)((char*)self + 0x2B0) = *(int*)((char*)self + 0x2A0);
    *(unsigned int*)((char*)self + 0x2A0) = 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B6F8);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void func_0026CDF8(void* p);
extern "C" void func_0026F228(void* p);
extern "C" void func_0026F7B8(int* self);

extern "C" void func_0030B6F8(void* self)
{
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026F228(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    func_0026F7B8(*(int**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    *(int*)((char*)self + 0x2AC) = 2;
    *(int*)((char*)self + 0x2B0) = *(int*)((char*)self + 0x2A0);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B758);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void func_0026CDF8(void* p);
void func_0026CBB0(void* self);
extern "C" void func_0026F228(void* p);
extern "C" void func_0026F7B8(int* self);
extern "C" void func_001235F8(void* self);

extern "C" void func_0030B758(void* self)
{
    func_0026CDF8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026CBB0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x34));
    func_0026F228(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    func_0026F7B8(*(int**)(*(char**)(D_004A28A8 + 0x84) + 0x28));
    char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
    func_001235F8(*(void**)(riders + (*(int*)self << 2) + 0x28));
    *(int*)((char*)self + 0x2AC) = 4;
    *(int*)((char*)self + 0x2B0) = *(int*)((char*)self + 0x2A0);
    *(unsigned int*)((char*)self + 0x2A0) = 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B7F8);
#ifdef SKIP_ASM
extern "C" void func_00307D78(void* obj);
extern "C" void func_0030C790(void* self);

extern "C" void func_0030B7F8(void* self)
{
    unsigned int id = *(unsigned int*)((char*)self + 0x2A0);
    if (id != 0xFFFFFFFF) {
        func_0030B388_cObj* obj = func_0030B388((char*)self + 0x2B8, id);
        if (obj != 0) {
            func_00307D78(obj);
        }
        *(int*)((char*)self + 0x2AC) = 0;
        *(unsigned int*)((char*)self + 0x2B0) = 0xFFFFFFFF;
        *(unsigned int*)((char*)self + 0x2A0) = 0xFFFFFFFF;
    }
    void* p;
    while ((p = func_0030B208((char*)self + 0x2B8)) != 0) {
        *(int*)p = 0;
        func_0030B260((char*)self + 0x2B4, p);
    }
    func_0030C790((char*)self + 0x1C4);
}
#endif

extern "C" void* func_0030B320(void*, int);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B898__FPvT0);
#ifdef SKIP_ASM
int func_0030B898(void* self, void* a1)
{
    return (func_0030B320((char*)self + 0x2b8, *(int*)((char*)a1 + 0x20)) != 0);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B8C0);
#ifdef SKIP_ASM
class func_0030B8C0_cNode {
public:
    char pad_0x00[0x18];
    func_0030B8C0_cNode* next;   // 0x18
    char pad_0x1C[0x5C - 0x1C];
    // vptr at 0x5C; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual int v03();
};

extern "C" int func_0030B8C0(void* self)
{
    int n = 0;
    func_0030B8C0_cNode* node;
    for (node = *(func_0030B8C0_cNode**)((char*)self + 0x2B8); node != 0; node = node->next) {
        if (node->v03() != 0 && *(int*)((char*)node + 0x60) == 2) {
            n++;
        }
    }
    return n != 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B928);
#ifdef SKIP_ASM
struct cWScriptIdTable;
extern "C" void func_0030C390(cWScriptIdTable* self);

// same layout as cWScriptIdTable (defined later in the unit)
struct func_0030B928_sSlot {
    unsigned int id;     // 0x0
    int arg;             // 0x4
    int b;               // 0x8
    unsigned int entries[64];
};

extern "C" void func_0030B928(void* self, unsigned int id, int arg)
{
    func_0030B928_sSlot* s = (func_0030B928_sSlot*)((char*)self + 0x2C0);
    int i;
    for (i = 0; i < 1; i++, s++) {
        if (s->id == id) {
            return;
        }
        if (s->id == 0xFFFFFFFF) {
            func_0030C390((cWScriptIdTable*)s);
            s->id = id;
            s->arg = arg;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030B9A0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct func_0030C3E0_sTable;
extern "C" void func_0030C3E0(func_0030C3E0_sTable* self, int id);
extern "C" void* func_0028B180();
extern "C" void func_0029CED8(void*, int, void*, float);
extern "C" int func_00144C98(void* iface);
extern "C" int func_00151178(void* self, int level);
extern "C" void func_0010F338(void* rider, int level, int a2);
extern char* D_004A28A8;

struct sWSSlot_B9A0 {
    int id;
    char pad[0x10C - 4];
};

extern "C" void func_0030B9A0(void* self, int rider, int id, int a3)
{
    sWSSlot_B9A0* slots = (sWSSlot_B9A0*)((char*)self + 0x2C0);
    int i;
    for (i = 0; i < 1; i++) {
        if (slots[i].id == id) {
            func_0030C3E0((func_0030C3E0_sTable*)&slots[i], a3);
            func_0029CED8(func_0028B180(), 5, 0, 1.0f);
            void* i0 = cBE_getInterface_Fv(cBE_getBE(), 0);
            void* i11 = cBE_getInterface_Fv(cBE_getBE(), 0xB);
            int lvl = func_00144C98(i0);
            int v = func_00151178(i11, lvl);
            func_0010F338(*(void**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + (rider << 2) + 0x28), lvl, v);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030BA80);
#ifdef SKIP_ASM
struct func_0030BA80_sEntry {
    int id;
    char pad04[0x10C - 4];
};

struct func_0030BA80_sMan {
    char pad000[0x2C0];
    func_0030BA80_sEntry entries[1];
};

extern "C" int func_0030C468(void* entry);

extern "C" int func_0030BA80(func_0030BA80_sMan* self, int id)
{
    func_0030BA80_sEntry* e = self->entries;
    int i;
    for (i = 0; i < 1; i++, e++) {
        if (e->id == id) {
            return func_0030C468(e);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030BAC8);
#ifdef SKIP_ASM
struct func_0030BAC8_sEntry {
    int id;
    char pad04[0x10C - 4];
};

struct func_0030BAC8_sMan {
    char pad000[0x2C0];
    func_0030BAC8_sEntry entries[1];
};

extern "C" void func_0030C4A8(void* e, int a1, int a2);

extern "C" void func_0030BAC8(func_0030BAC8_sMan* self, int id, int a1, int a2)
{
    func_0030BAC8_sEntry* e = self->entries;
    int i;
    for (i = 0; i < 1; i++, e++) {
        if (e->id == id) {
            func_0030C4A8(e, a1, a2);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030BB10);
#ifdef SKIP_ASM
struct sWSVtVBB10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sWSManBB10 {
    char pad0[0x28C];
    char* world;                // 0x28C
    char pad290[0x28];
    void* list2B8;              // 0x2B8
    void* list2BC;              // 0x2BC
    char tables[1][0x10C];      // 0x2C0
    void* objs[50];             // 0x3CC
};

class func_0030C6C8_cObj;
extern "C" int func_0030C6C8(void* a, func_0030C6C8_cObj* obj);
extern "C" void func_0030BC80(void* self, void** list, void* stream);
extern "C" int func_003ACA38(void* a, int id);
extern "C" void func_002257E0(void* obj, void* stream, int a2);

extern "C" void func_0030BB10(sWSManBB10* self, void* stream)
{
    int count;
    int j;
    {
        sWSVtVBB10* e = &(*(sWSVtVBB10**)stream)[1];
        e->fn((char*)stream + e->delta, self, 0x28C);
    }
    {
        int k;
        for (k = 0; k < 1; k++) {
            func_0030C6C8(self->tables[k], (func_0030C6C8_cObj*)stream);
        }
    }
    func_0030BC80(self, &self->list2B8, stream);
    func_0030BC80(self, &self->list2BC, stream);
    count = 0;
    {
        int i;
        for (i = 0; i < 50; i++) {
            if (self->objs[i] != 0) {
                count++;
            }
        }
    }
    {
        sWSVtVBB10* e = &(*(sWSVtVBB10**)stream)[1];
        e->fn((char*)stream + e->delta, &count, 4);
    }
    for (j = 0; j < 50; j++) {
        if (self->objs[j] != 0) {
            sWSVtVBB10* e = &(*(sWSVtVBB10**)stream)[1];
            int r;
            e->fn((char*)stream + e->delta, &j, 4);
            r = func_003ACA38(*(void**)(self->world + 4), j);
            func_002257E0(self->objs[j], stream, r);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030BC80);
#ifdef SKIP_ASM
extern "C" int func_0030B228(cWScriptListHead* self);
extern "C" void func_00308038(void* node, void* stream);

struct sVEntry30BC80 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0030BC80(void* self, void** list, void* stream)
{
    int n = func_0030B228((cWScriptListHead*)list);
    sVEntry30BC80* e = &(*(sVEntry30BC80**)stream)[1];
    e->fn((char*)stream + e->delta, &n, 4);
    char* node = (char*)*list;
    while (node != 0) {
        int id = *(int*)(node + 0x20);
        e = &(*(sVEntry30BC80**)stream)[1];
        e->fn((char*)stream + e->delta, &id, 4);
        func_00308038(node, stream);
        node = *(char**)(node + 0x18);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030BD20);
#ifdef SKIP_ASM
class cStream_30BD20 {
public:
    virtual void v01();
    virtual void Read(void* dst, int size);
};

struct sWSMan_30BD20 {
    char pad0[0x28C];
    char* world;                // 0x28C
    char pad290[0x28];
    void* list2B8;              // 0x2B8
    void* list2BC;              // 0x2BC
    char tables[1][0x10C];      // 0x2C0
    void* objs[50];             // 0x3CC
};

struct cWScriptListHead;
extern "C" void* func_0030B208(void* self);
int func_0030B260(void* self, void* a1);
extern "C" int func_003ACA38(void* a, int id);
class func_0030C700_cObj;
extern "C" int func_0030C700(void* a, func_0030C700_cObj* obj);
class func_0030BEE8_cStream;
extern "C" void func_0030BEE8(void* self, cWScriptListHead* list, func_0030BEE8_cStream* stream);
extern "C" void func_00224F68(void* obj);
extern "C" void func_002259A8(void* obj, cStream_30BD20* stream, int a2);

extern "C" void func_0030BD20(sWSMan_30BD20* self, cStream_30BD20* stream)
{
    stream->Read(self, 0x28C);
    {
        int k;
        for (k = 0; k < 1; k++) {
            func_0030C700(self->tables[k], (func_0030C700_cObj*)stream);
        }
    }
    void* p;
    while ((p = func_0030B208(&self->list2B8)) != 0) {
        *(int*)p = 0;
        func_0030B260((char*)self + 0x2B4, p);
    }
    while ((p = func_0030B208(&self->list2BC)) != 0) {
        *(int*)p = 0;
        func_0030B260((char*)self + 0x2B4, p);
    }
    func_0030BEE8(self, (cWScriptListHead*)&self->list2B8, (func_0030BEE8_cStream*)stream);
    func_0030BEE8(self, (cWScriptListHead*)&self->list2BC, (func_0030BEE8_cStream*)stream);
    {
        int i;
        for (i = 0; i < 50; i++) {
            if (self->objs[i] != 0) {
                func_00224F68(self->objs[i]);
            }
        }
    }
    int count;
    stream->Read(&count, 4);
    for (int j = 0; j < count; j++) {
        int id;
        stream->Read(&id, 4);
        int r = func_003ACA38(*(void**)(self->world + 4), id);
        func_002259A8(self->objs[id], stream, r);
    }
    *(int*)((char*)self + 0x290) = 0;
    *(int*)((char*)self + 0x294) = 0;
    *(int*)((char*)self + 0x298) = 0;
    *(int*)((char*)self + 0x2A4) = 0;
    *(int*)((char*)self + 0x2A8) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("wscript/wscriptman", func_0030BEE8);
#ifdef SKIP_ASM
class func_0030BEE8_cStream {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void Read(void* dst, int size);
};

extern "C" void func_00308118(void* proc, func_0030BEE8_cStream* stream);
extern "C" void func_0030B270(cWScriptListHead* self, cWScriptListNode* node);
extern "C" int func_0030B2D0(cWScriptListHead* self, cWScriptListNode* node);

extern "C" void func_0030BEE8(void* self, cWScriptListHead* list, func_0030BEE8_cStream* stream)
{
    int n;
    int id;
    int i = 0;
    stream->Read(&n, 4);
    for (; i < n; i++) {
        stream->Read(&id, 4);
        cWScriptListNode* node = (cWScriptListNode*)func_0030B320((char*)self + 0x2B4, id);
        func_0030B2D0((cWScriptListHead*)((char*)self + 0x2B4), node);
        func_00308118(node, stream);
        func_0030B270(list, node);
    }
}
#endif

INCLUDE_ASM("wscript/wscriptman", func_0030BFC0);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C390);
#ifdef SKIP_ASM
struct cWScriptIdTable {
    unsigned int id;
    int a;
    int b;
    unsigned int entries[64];
};

extern "C" void func_0030C390(cWScriptIdTable* self)
{
    int i;
    self->id = 0xFFFFFFFF;
    self->a = 0;
    self->b = 0;
    for (i = 0; i < 64; i++) {
        self->entries[i] = 0xFFFFFFFF;
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C3E0);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void func_00153B00(void* iface, int a1, int index, int value);

struct func_0030C3E0_sTable {
    int value;      // 0x0
    int pad4;       // 0x4
    int count;      // 0x8
    int ids[1];     // 0xC
};

extern "C" void func_0030C3E0(func_0030C3E0_sTable* self, int id)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (self->ids[i] == id) {
            func_00153B00(cBE_getInterface_Fv(cBE_getBE(), 10), 0, i, self->value);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C468);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_00153498(void* iface, int a1, int id);

extern "C" int func_0030C468(void* entry)
{
    return func_00153498(cBE_getInterface_Fv(cBE_getBE(), 10), 0, *(int*)entry);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C4A8);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_C4A8(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" int func_001538E8(void* iface, int a, int b, int c);
extern "C" void* func_003506D8(void* mem, void* obj);
extern char D_004896B8[];

struct sRefSet_C4A8 {
    char pad_0x0[0x1C];
    unsigned int* refs;     // 0x1C
};
struct sRefWorld_C4A8 {
    char pad_0x0[0x8];
    sRefSet_C4A8** sets;    // 0x8
};
extern sRefWorld_C4A8** D_004A47B8_C4A8 __asm__("D_004A47B8");

struct sRace_C4A8 {
    char pad0[0x48];
    signed char mode48;
    signed char flag49;
};
extern sRace_C4A8 D_00535BC8_rC4A8 __asm__("D_00535BC8");

struct sVE_C4A8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sEntry_C4A8 {
    int id;
    int f4;
    int count;
    unsigned int ids[1];
};

static inline void* refToPtr_C4A8(unsigned int p)
{
    return (void*)(p << 2);
}

static inline void* toObj_C4A8(unsigned int p)
{
    if (p == 0)
        return 0;
    return refToPtr_C4A8(p);
}

static inline void* lookup_C4A8(unsigned int id)
{
    sRefSet_C4A8* set = (*D_004A47B8_C4A8)->sets[id & 0xFF];
    if (set == 0) {
        return 0;
    }
    return toObj_C4A8(set->refs[id >> 8] >> 8);
}

static inline void respawn_C4A8(unsigned int id)
{
    char* obj = (char*)lookup_C4A8(id);
    char* o = *(char**)(obj + 0xC);
    if (o != 0) {
        sVE_C4A8* vt = *(sVE_C4A8**)(o + 0xC);
        vt[1].fn(o + vt[1].delta, 3);
    }
    func_003506D8(cMemMan_alloc(0x1C, D_004896B8, 0x20000000, 0), obj);
}

// PORT: a1 is really an unsigned int* id list and a2 its count (the unit declares both int).
extern "C" void func_0030C4A8(void* ep, int a1, int a2)
{
    sEntry_C4A8* e = (sEntry_C4A8*)ep;
    unsigned int* ids = (unsigned int*)a1;
    void* iface = cBE_getInterface_C4A8(cBE_getBE(), 10);
    if (a2 <= 0)
        return;
    sRace_C4A8* r = &D_00535BC8_rC4A8;
    for (int n = a2; n != 0; n--, ids++) {
        unsigned int id = *ids;
        if (~id == 0)
            continue;
        ((unsigned int*)((char*)e + 0xC))[e->count] = id;
        cBE_getInterface_C4A8(cBE_getBE(), 0);
        if (r->flag49 == 0) {
            if (func_001538E8(iface, 0, e->count, e->id))
                respawn_C4A8(*ids);
        } else {
            respawn_C4A8(*ids);
        }
        e->count++;
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C6C8);
#ifdef SKIP_ASM
class func_0030C6C8_cObj {
public:
    // slot N at vtable offset N*8
    virtual int v01(void* a, int b);
};

extern "C" int func_0030C6C8(void* a, func_0030C6C8_cObj* obj)
{
    return obj->v01(a, 0x10C);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C700);
#ifdef SKIP_ASM
class func_0030C700_cObj {
public:
    // slot N at vtable offset N*8
    virtual int v01(void* a, int b);
    virtual int v02(void* a, int b);
};

extern "C" int func_0030C700(void* a, func_0030C700_cObj* obj)
{
    return obj->v02(a, 0x10C);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C738);
#ifdef SKIP_ASM
extern "C" void func_0030C760(void* self);

extern "C" void* func_0030C738(void* self)
{
    func_0030C760(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C760);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

extern "C" void func_0030C760(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 4) = 0;
    func_003E6448((char*)self + 8, 0, 0xC0);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C790);
#ifdef SKIP_ASM
extern "C" void func_003E6448(void* dst, int value, int size);

extern "C" void func_0030C790(void* self)
{
    *(int*)self = 0;
    *(int*)((char*)self + 4) = 0;
    func_003E6448((char*)self + 8, 0, 0xC0);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C7C0);
#ifdef SKIP_ASM
// Same layout as cWScriptQueue / cWScriptQueueEntry, which the unit defines
// further down (above func_0030C820). Renamed here only to avoid a redefinition.
struct cWSQEntry {
    int a;
    int b;
    int c;
};

struct cWSQueue {
    int head;
    int tail;
    cWSQEntry entries[16];
};

extern "C" void func_0030C7C0(cWSQueue* self, int a, int b, int c)
{
    self->entries[self->tail].a = a;
    self->entries[self->tail].b = b;
    self->entries[self->tail].c = c;
    self->tail = (self->tail + 1) % 16;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C820);
#ifdef SKIP_ASM
struct cWScriptQueueEntry {
    int a;
    int b;
    int c;
};

struct cWScriptQueue {
    int head;
    int tail;
    cWScriptQueueEntry entries[16];
};

extern "C" cWScriptQueueEntry* func_0030C820(cWScriptQueue* self)
{
    int head = self->head;
    if (head == self->tail) {
        return 0;
    }
    self->head = (head + 1) % 16;
    return &self->entries[head];
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C870);
#ifdef SKIP_ASM
extern "C" cWScriptQueueEntry* func_0030C870(cWScriptQueue* self)
{
    if (self->head == self->tail) {
        return 0;
    }
    return &self->entries[self->head];
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030C898);
#ifdef SKIP_ASM
extern "C" void* func_0030C898(void* self, ...) {
    return self;
}
#endif

INCLUDE_ASM("wscript/wscriptman", func_0030C8D8);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D238);
#ifdef SKIP_ASM
extern "C" void func_0030D238(void *arg0, int arg1, int arg2) {
    (*(int *)((char*)(arg0) + (0))) = arg1;
    (*(int *)((char*)(arg0) + (4))) = arg2;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D248);
#ifdef SKIP_ASM
extern "C" int func_0030D248(int arg0) {
    return arg0;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D250);
#ifdef SKIP_ASM
extern "C" int func_0030D250(int arg0) {
    return arg0;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D258);
#ifdef SKIP_ASM
extern "C" int func_0030D258(int arg0) {
    return arg0;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D260);
#ifdef SKIP_ASM
extern "C" void func_0030D260(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x29C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D268);
#ifdef SKIP_ASM
extern "C" int func_0030D268(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D270);
#ifdef SKIP_ASM
extern "C" int func_0030D270(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D278);
#ifdef SKIP_ASM
extern "C" int func_0030D278(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D280);
#ifdef SKIP_ASM
extern "C" int func_0030D280(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D288);
#ifdef SKIP_ASM
extern "C" int func_0030D288(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D290);
#ifdef SKIP_ASM
extern "C" int func_0030D290(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D298);
#ifdef SKIP_ASM
extern "C" int func_0030D298(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2A0);
#ifdef SKIP_ASM
extern "C" int func_0030D2A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2A8);
#ifdef SKIP_ASM
extern "C" int func_0030D2A8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x24)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2B0);
#ifdef SKIP_ASM
extern "C" int func_0030D2B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x28)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2B8);
#ifdef SKIP_ASM
extern "C" int func_0030D2B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x34)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2C0);
#ifdef SKIP_ASM
extern "C" int func_0030D2C0(int arg0) {
    return arg0 + 0x38;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2C8);
#ifdef SKIP_ASM
extern "C" void func_0030D2C8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x2A0))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2D0);
#ifdef SKIP_ASM
extern "C" int func_0030D2D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2A0)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2D8);
#ifdef SKIP_ASM
extern int D_004A3DD8;

extern "C" int func_0030D2D8(void) {
    return D_004A3DD8;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2E0);
#ifdef SKIP_ASM
extern "C" int func_0030D2E0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x290)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2E8);
#ifdef SKIP_ASM
extern "C" int func_0030D2E8(int *arg0) {
    return *arg0;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2F0);
#ifdef SKIP_ASM
extern "C" int func_0030D2F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x294)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D2F8);
#ifdef SKIP_ASM
extern "C" int func_0030D2F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x298)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D300);
#ifdef SKIP_ASM
extern "C" void func_0030D300(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x290))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D308);
#ifdef SKIP_ASM
extern "C" int func_0030D308(int arg0, int arg1) {
    return (*(int *)(((char*)(arg0) + (arg1 << 2)) + (0x3CC)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D318);
#ifdef SKIP_ASM
extern "C" int func_0030D318(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2A8)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D320);
#ifdef SKIP_ASM
extern "C" void func_0030D320(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x2A8))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D328);
#ifdef SKIP_ASM
extern "C" int func_0030D328(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2A4)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D330);
#ifdef SKIP_ASM
extern "C" int func_0030D330(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C4))) != (*(int *)((char*)(arg0) + (0x1C8)));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D348);
#ifdef SKIP_ASM
extern "C" cWScriptQueueEntry* func_0030D348(char* self) {
    return func_0030C820((cWScriptQueue*)(self + 0x1C4));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D368);
#ifdef SKIP_ASM
extern "C" cWScriptQueueEntry* func_0030D368(char* self) {
    return func_0030C870((cWScriptQueue*)(self + 0x1C4));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D388);
#ifdef SKIP_ASM
extern "C" void func_0030D388(int *arg0, int arg1) {
    *arg0 = arg1;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D390);
#ifdef SKIP_ASM
extern "C" int func_0030D390(int arg0, unsigned int arg1) {
    return arg1 < 10;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D398);
#ifdef SKIP_ASM
extern "C" void func_0030D398(int *arg0) {
    *arg0 = 0;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3A0);
#ifdef SKIP_ASM
extern "C" int func_0030D3A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3A8);
#ifdef SKIP_ASM
extern "C" void func_0030D3A8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3B0);
#ifdef SKIP_ASM
extern "C" int func_0030D3B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x24)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3B8);
#ifdef SKIP_ASM
extern "C" void func_0030D3B8(void *arg0, int arg1) {
    (*(int *)((char*)((*(void **)((char*)(arg0) + (0x10)))) + (0x29C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3C8);
#ifdef SKIP_ASM
extern "C" int func_0030D3C8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3D0);
#ifdef SKIP_ASM
extern "C" int func_0030D3D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3D8__FPv);
#ifdef SKIP_ASM
int func_0030D3D8(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D3E0);
#ifdef SKIP_ASM
extern "C" void func_0030AC98_1(void* arg0) __asm__("func_0030AC98");
extern "C" void func_0030D3E0(char* self) {
    func_0030AC98_1(*(void**)(self + 0x10));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D400);
#ifdef SKIP_ASM
extern "C" void func_0030ADA8_1(void* arg0) __asm__("func_0030ADA8");
extern "C" void func_0030D400(char* self) {
    func_0030ADA8_1(*(void**)(self + 0x10));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D420);
#ifdef SKIP_ASM
extern void* D_00489AE0[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_0030D420(void* self, int flags)
{
    *(void***)((char*)self + 0x40) = D_00489AE0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D450);
#ifdef SKIP_ASM
extern "C" int func_0030D450(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0x3C)))) + (0x1C)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D460);
#ifdef SKIP_ASM
extern "C" int func_0030D460(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D468);
#ifdef SKIP_ASM
extern "C" void func_0030D468(int *arg0) {
    *arg0 = 3;
}
#endif
//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D478);
#ifdef SKIP_ASM
extern "C" int func_0030D478(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x64)));
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D480__FPv);
#ifdef SKIP_ASM
int func_0030D480(void* self)
{
    return 0x1;
}
#endif

extern "C" void* func_0030C8D8(int, int);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D488);
#ifdef SKIP_ASM
extern "C" int func_0030D488(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x60))) == 2;
}
#endif

//99.38%
INCLUDE_ASM("wscript/wscriptman", func_0030D498__FPv);
#ifdef SKIP_ASM
void* func_0030D498(void* self)
{
    return func_0030C8D8(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D4B8);
#ifdef SKIP_ASM
struct sWSVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sWSSlot8 {
    int a;
    int b;
};

extern "C" void* func_0030D4B8(void* self)
{
    sWSVec4 v;
    *(int*)((char*)self + 0x38) = 0;
    *(int*)((char*)self + 0x30) = 0;
    *(int*)((char*)self + 0x34) = 0;
    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    v.w = 1.0f;
    *(sWSVec4*)((char*)self + 0x140) = v;
    *(int*)((char*)self + 0x2C) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x3C) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x12C) = 0;
    *(int*)((char*)self + 0x130) = 0;
    *(int*)((char*)self + 0x24) = 0;
    *(int*)((char*)self + 0x28) = 0;
    *(int*)((char*)self + 0x20) = 0;
    for (int i = 3; i >= 0; i--) {
        ((sWSSlot8*)((char*)self + 0x44))[i].a = 0;
    }
    return self;
}
#endif

INCLUDE_ASM("wscript/wscriptman", func_0030D540);

//100%
INCLUDE_ASM("wscript/wscriptman", func_0030D840);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d), like cMemMan_alloc.
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_003E6448(void* dst, int value, int size);
extern char D_00489C70[];

struct func_0030D840_sPool {
    int count;      // 0x0
    int field_0x4;  // 0x4
    int field_0x8;  // 0x8
    void* items;    // 0xC
    char pad_0x10[0x60 - 0x10];
    int field_0x60; // 0x60
};

extern "C" void func_0030D840(func_0030D840_sPool* self, int count, int a2)
{
    self->field_0x4 = a2;
    self->count = count;
    self->items = operator_new_tag(count * 0x58, D_00489C70, 0, 0);
    func_003E6448(self->items, 0, self->count * 0x58);
    self->field_0x8 = 0;
    self->field_0x60 = 0;
}
#endif

