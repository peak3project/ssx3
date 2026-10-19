#include "common.h"

//100%
INCLUDE_ASM("scripter/ssxscriptengine", cSSXScriptEngine_Load);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
// PORT: func_0027B268 is defined with six params; this caller passes a seventh (0) in $t2.
extern "C" void func_0027B268_7(void* self, int i, const char* name, int flags, int key, int* buf, int x)
    __asm__("func_0027B268");
extern "C" void func_00283298(void* rig);
extern const char* D_004A349C;
extern char D_00481BD8[];
extern char D_00481BE8[];
extern char D_00481BF8[];

struct sLink_278358
{
    int a;
    int b;
    int c;
    int d;
    sLink_278358* next;
};

struct sRider_278358
{
    void* owner;
    int f4;
    int f8;
    char pad[0xCC - 0xC];
    sRider_278358() __asm__("func_00275D10");
    // PORT: tagged array new (operator_new__FUi); the sized delete[] makes g++ keep the element-count cookie.
    void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
    void operator delete[](void* p, unsigned int size);
};

struct sSse278358
{
    char pad_0x0[0x544];
    sLink_278358* links;            // 0x544
    sLink_278358* freeLink;         // 0x548
    sRider_278358* objsA;           // 0x54C
    char pad_0x550[0x624 - 0x550];
    sRider_278358* objsB;           // 0x624
    char pad_0x628[0x6D0 - 0x628];
    char rigs[2][0x120];            // 0x6D0
    char pad_0x910[0xC];
    char rigC[0x1C];                // 0x91C
    char rigD[0x1C];                // 0x938
};

extern "C" void cSSXScriptEngine_Load(sSse278358* self)
{
    self->links = (sLink_278358*)operator_new_tag(0xC8, D_00481BD8, 0, 0);
    for (int i = 0; i < 10; i++)
    {
        self->links[i].a = -1;
        self->links[i].b = -1;
        self->links[i].c = -1;
        self->links[i].d = -1;
        self->links[i].next = &self->links[i + 1];
    }
    self->links[9].next = 0;
    self->freeLink = self->links;
    func_0027B268_7(self, 0, D_004A349C, 0, -1, 0, 0);
    for (int i = 0; i < 2; i++)
        func_00283298(self->rigs[i]);
    func_00283298(self->rigC);
    func_00283298(self->rigD);
    sRider_278358** pa = &self->objsA;
    *pa = new (D_00481BE8, 0, 0) sRider_278358[2];
    int i;
    for (i = 0; i < 2; i++)
        self->objsA[i].owner = self;
    sRider_278358** pb = &self->objsB;
    *pb = new (D_00481BF8, 0, 0) sRider_278358[2];
    for (i = 0; i < 2; i++)
    {
        self->objsB[i].owner = self;
        self->objsB[i].f4 = 0;
        self->objsB[i].f8 = i;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278590);
#ifdef SKIP_ASM
void cMemMan_free(void*);
extern "C" void func_00275B08(void* self);
extern "C" void func_00275D90(int* self, int flags);
extern "C" void func_00278A98(void* self);
extern "C" void func_00278CD8(void* self);
extern "C" void func_0027B410(void* self, int idx);
extern "C" void func_0027BF90(void* self);
extern "C" void func_002823F0(void* self);
extern "C" void func_002832D8(void* self);
extern "C" void func_00283818(void* p);
extern "C" void func_002EF368(int);

struct sSseObj8590 {
    char data[0xCC];
};

struct sSseEngine8590 {
    char pad_0x0[0x500];
    char snd[0x1C];                 // 0x500
    char anims[0x544 - 0x51C];      // 0x51C
    void* buf;                      // 0x544
    int field_0x548;                // 0x548
    sSseObj8590* objsA;             // 0x54C
    char pad_0x550[0x624 - 0x550];
    sSseObj8590* objsB;             // 0x624
    char pad_0x628[0x6D0 - 0x628];
    char rigs[2][0x120];            // 0x6D0
    char pad_0x910[0xC];
    char rigC[0x1C];                // 0x91C
    char rigD[0x1C];                // 0x938
};

extern "C" void func_00278590(sSseEngine8590* self)
{
    func_00278A98(self);
    func_002823F0(self);
    for (int i = 0; i < 2; i++) {
        func_002832D8(self->rigs[i]);
    }
    func_002832D8(self->rigC);
    func_002832D8(self->rigD);
    func_00278CD8(self);
    for (int i = 0; i < 10; i++) {
        func_0027B410(self, i);
    }
    func_00275B08(self->anims);
    func_00283818(self->snd);
    if (self->objsA != 0) {
        sSseObj8590* q = self->objsA + ((int*)self->objsA)[-4];
        while (self->objsA != q) {
            q--;
            func_00275D90((int*)q, 0);
        }
        cMemMan_free((char*)self->objsA - 0x10);
    }
    if (self->buf != 0) {
        cMemMan_free(self->buf);
    }
    if (self->objsB != 0) {
        sSseObj8590* q = self->objsB + ((int*)self->objsB)[-4];
        while (self->objsB != q) {
            q--;
            func_00275D90((int*)q, 0);
        }
        cMemMan_free((char*)self->objsB - 0x10);
    }
    func_002EF368(0);
    func_0027BF90(self);
    self->objsA = 0;
    self->buf = 0;
    self->field_0x548 = 0;
    self->objsB = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278710__FPv);
#ifdef SKIP_ASM
void func_00278710(void* self)
{
    *(int*)((char*)self + 0x554) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278718__FPv);
#ifdef SKIP_ASM
void func_00278718(void* self)
{
    *(int*)((char*)self + 0x554) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278720);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char* D_004A28A8;
extern char D_004A34A0[];
struct sSsxScriptRider;
struct sScrObj05B8;
extern "C" void func_00276CC8(void* r);
extern "C" void func_002820B0(void* self);
extern "C" void func_00283AA0(void* snd);
extern "C" void func_00281100(void* slot);
extern "C" void func_00280640(sScrObj05B8* self);
extern "C" int func_00277060(sSsxScriptRider* r);
// The unit declares func_00276B98 as void, but this caller tests its result: bind an int view by asm label.
extern "C" int func_00276B98_i(void* r) __asm__("func_00276B98");
extern "C" void func_00276F48(void* r);
extern "C" int func_00277298(void* r);
extern "C" void func_0027BF90(void* self);
void* func_00320C48(void* self, int a1);
int GetHashValue32(char*);
extern "C" void* func_0039F9D8(void* list, int hash);
extern "C" void func_001F36C0(void*, int);
extern "C" void func_001F36D8(void*, int);

struct sSseObj8720 {
    char data[0xCC];
};

struct sLvl8720 {
    char pad_0x0[0x40];
    char* riders[15];               // 0x40
    int count;                      // 0x7C
};

struct sSse8720 {
    char pad_0x0[0x500];
    char snd[0x4C];                 // 0x500
    sSseObj8720* objsA;             // 0x54C
    int state;                      // 0x550
    int delay;                      // 0x554
    char pad_0x558[0x624 - 0x558];
    sSseObj8720* objsB;             // 0x624
    char pad_0x628[0x6D0 - 0x628];
    char rigs[2][0x120];            // 0x6D0
    char pad_0x910[0x1C];
    char fx[0x10];                  // 0x92C
};

extern "C" void func_00278720(sSse8720* self)
{
    for (int i = 0; i < 2; i++)
        func_00276CC8(&self->objsA[i]);
    for (int i = 0; i < 2; i++)
        func_00276CC8(&self->objsB[i]);
    func_002820B0(self);
    func_00283AA0(self->snd);
    for (int i = 0; i < 2; i++)
        func_00281100(self->rigs[i]);
    func_00280640((sScrObj05B8*)self->fx);
    if (self->state != 2)
    {
        sSseObj8720* r = &self->objsA[self->state];
        if (func_00277060((sSsxScriptRider*)r))
        {
            sLvl8720* lvl = *(sLvl8720**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
            int n = lvl->count;
            for (int j = 0; j < n; j++)
            {
                void* obj = *(void**)(lvl->riders[j] + 0xDF0);
                if (**(int**)obj != 0 && self->delay == 0 && func_00320C48(obj, 0x6F))
                {
                    func_00276F48(r);
                    goto done;
                }
            }
        }
    done:
        if (func_00276B98_i(r) != 3)
            func_0027BF90(self);
        if (func_0039F9D8(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0x48) + 0x18, GetHashValue32(D_004A34A0)))
        {
            if (func_00277298(r))
                func_001F36C0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x94), 1);
            else
                func_001F36D8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x94), 1);
        }
    }
    if (self->delay > 0)
        self->delay--;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278918);
#ifdef SKIP_ASM
struct sScrRelocOwner6B0;
extern "C" int func_003DF980(void*);
extern "C" void func_0027B6B0(sScrRelocOwner6B0* self, void* file);
extern "C" void func_0027B5D8(void* self, void* file);

struct sScrSlot8918 {
    void* file;
    int pad[3];
};

extern "C" void func_00278918(void* self)
{
    if (*(int*)((char*)self + 0x620) == 0) return;
    void* f = *(void**)((char*)self + 0x538);
    if (f != 0 && func_003DF980(f) != 0) {
        func_0027B6B0((sScrRelocOwner6B0*)self, *(void**)((char*)self + 0x538));
    }
    sScrSlot8918* slots = (sScrSlot8918*)((char*)self + 0x630);
    for (int i = 0; i < 10; i++) {
        void* p = slots[i].file;
        if (p != 0 && func_003DF980(p) != 0) {
            func_0027B5D8(self, p);
        }
    }
}
#endif

extern "C" void* func_00283AF8(void*);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002789C0__FPv);
#ifdef SKIP_ASM
void* func_002789C0(void* self)
{
    return func_00283AF8((char*)self + 0x500);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002789E0);
#ifdef SKIP_ASM
extern "C" void func_002790F8(void* self);
extern "C" void func_00279488(void* self);

extern "C" void func_002789E0(void* self)
{
    func_002790F8(self);
    func_00279488(self);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278A10);
#ifdef SKIP_ASM
extern "C" int func_0022E0E0(void* self, int a1);
extern char* D_004A28A8;

extern "C" void func_00278A10(void* self, int key, int val)
{
    *(int*)((char*)self + (func_0022E0E0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x78), key) << 2) + 0x558) = val;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278A58);
#ifdef SKIP_ASM
extern "C" int func_0022E0E0(void* self, int a1);
extern char* D_004A28A8;

extern "C" void func_00278A58(void* self, int key)
{
    *(int*)((char*)self + (func_0022E0E0(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x78), key) << 2) + 0x558) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278A98);
#ifdef SKIP_ASM
extern "C" void func_002790F8(void* self);
extern "C" void func_00279488(void* self);
extern "C" void func_00282390(void* self);

extern "C" void func_00278A98(void* self)
{
    func_002790F8(self);
    func_00279488(self);
    func_00282390(self);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278AD0);
#ifdef SKIP_ASM
extern "C" int func_00282450(void* self, int key);
extern "C" int func_00282BF0(void* self, int a1);
extern "C" void func_00281100(void* slot);

struct sSsxVEntry8AD0 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

struct sScrSlot8AD0 {
    int a;
    int id;
    char pad[0x120 - 8];
};

extern "C" int func_00278AD0(void* self, int key)
{
    int r = func_00282450(self, key);
    if (r != 0) {
        sScrSlot8AD0* p = (sScrSlot8AD0*)((char*)self + 0x6D0);
        for (int i = 0; i < 2; i++, p++) {
            sSsxVEntry8AD0* vt = *(sSsxVEntry8AD0**)((char*)self + 0x2A8);
            int id = p->id;
            void* obj = (char*)self + vt[4].delta;
            // PORT: func_00282BF0 returns a pointer as int
            if (vt[4].fn(obj, id, *(int*)func_00282BF0(self, key))) {
                func_00281100(p);
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278B98);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int* func_00144BC0(void* iface);

// Minimal view of cBXString; the members are bound to the game's (unmangled) symbols.
// PORT: asm labels are not accepted on destructors, so the dtor forwards to the out-of-line one (in-charge flag 2).
struct sBXStr_8B98;
extern "C" void cBXString_dtor_8B98(sBXStr_8B98* self, int flags) __asm__("cBXString__cBXString");

struct sBXStr_8B98 {
    char* p;
    int pad[3];
    sBXStr_8B98(const char* s) __asm__("cBXString_cBXString2");
    ~sBXStr_8B98() { cBXString_dtor_8B98(this, 2); }
    sBXStr_8B98& operator=(const sBXStr_8B98& s) __asm__("cBXString_operatorE");
};
sBXStr_8B98 operator+(const char* a, const sBXStr_8B98& b) __asm__("func_003186D0");
sBXStr_8B98 operator+(const sBXStr_8B98& a, const char* b) __asm__("func_00318630");
extern "C" void* func_003DF690_8B98(const char* name, int flags) __asm__("func_003DF690");
extern "C" void func_0027B370(void* self, int slot, const char* name, int flags, int key, int a, int b);
extern const char D_00481C08[];
extern const char D_004A34B8[];
extern const char D_00481C38[];
extern const char D_004A34C0[];

// Loads the current profile's script file (counting it if found), then queues the profile's second script.
extern "C" void func_00278B98(char* self)
{
    sBXStr_8B98 name((char*)func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0)) + 0x34);
    sBXStr_8B98 path = D_00481C08 + name + D_004A34B8;
    void* h = func_003DF690_8B98(path.p, 0);
    *(void**)(self + 0x538) = h;
    if (h != 0) {
        *(int*)(self + 0x620) += 1;
    }
    path = D_00481C38 + name + D_004A34C0;
    func_0027B370(self, 1, path.p, 0, -1, 0, 0);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278CD8);
#ifdef SKIP_ASM
extern "C" void func_003DFAF0(void* file);
extern "C" int ASYNCFILE_release(void* file, int a, int b);
extern "C" void* func_002523A8(void* self);
extern "C" void func_0027B410(void* self, int idx);

extern "C" void func_00278CD8(void* self)
{
    if (*(void**)((char*)self + 0x538) != 0) {
        func_003DFAF0(*(void**)((char*)self + 0x538));
        ASYNCFILE_release(*(void**)((char*)self + 0x538), 0, 0);
        *(int*)((char*)self + 0x620) -= 1;
    }
    func_0027B410(self, 1);
    if (*(void**)((char*)self + 0x53C) != 0) {
        func_002523A8(*(void**)((char*)self + 0x53C));
    }
    *(void**)((char*)self + 0x538) = 0;
    *(void**)((char*)self + 0x53C) = 0;
    *(int*)((char*)self + 0x540) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_00278D58);
#ifdef SKIP_ASM
extern "C" void func_00278918(void*);
extern "C" int func_0027BF50(void*, int);

extern "C" int func_00278D58(void* self)
{
    int r;
    func_00278918(self);
    r = 0;
    if (*(int*)((char*)self + 0x538) == 0) {
        r = func_0027BF50(self, 1) == 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278DA0);
#ifdef SKIP_ASM
extern "C" int func_002770C0(void*);

extern "C" int func_00278DA0(void* self)
{
    int i = *(int*)((char*)self + 0x550);
    if (i == 2) {
        return 1;
    }
    return func_002770C0(*(char**)((char*)self + 0x54C) + i * 0xCC);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278DE8__FPvi);
#ifdef SKIP_ASM
void func_00278DE8(void* self, int val)
{
    *(int*)((char*)self + 0x554) = val;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278DF0);
#ifdef SKIP_ASM
extern "C" void func_00278DF0(void *arg0, int arg1) {
    int var_3;
    int var_6;

    var_6 = 0;
    var_3 = 1;
    do {
        var_3 -= 1;
        (*(int *)((char*)((var_6 + (*(int *)((char*)(arg0) + (0x54C))))) + (8))) = arg1;
        var_6 += 0xCC;
    } while (var_3 >= 0);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278E20);
#ifdef SKIP_ASM
struct sSsxScriptRider {
    char pad[0xCC];
};

extern "C" void func_00275DD8(sSsxScriptRider* r, int a, int b);

extern "C" void func_00278E20(void* self, int i, int a, int b)
{
    func_00275DD8(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], a, b);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278E50);
#ifdef SKIP_ASM
extern "C" void func_00275ED0(void* e, int a, int b, int c, int d, int f, int g);

extern "C" void func_00278E50(void* self, int i, int a, int b, int c, int d, int f, int g)
{
    func_00275ED0(*(char**)((char*)self + 0x54C) + i * 0xCC, a, b, c, d, f, g);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278E90);
#ifdef SKIP_ASM
extern "C" void func_00276048(void* e, int a, int b, int c, int d, int f);

extern "C" void func_00278E90(void* self, int i, int a, int b, int c, int d, int f)
{
    func_00276048(*(char**)((char*)self + 0x54C) + i * 0xCC, a, b, c, d, f);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_00278ED0);
#ifdef SKIP_ASM
struct sScriptKeyEntry {
    int unk0;
    int key;
    int unk8;
};

extern "C" void func_00278ED0(void* self, int a1, int key, int b, int c, int d, int f)
{
    for (int i = 0; i < **(int**)((char*)self + 0x52C); i++) {
        if ((*(sScriptKeyEntry**)((char*)self + 0x530))[i].key == key) {
            func_00278E90(self, a1, i, b, c, d, f);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278F38);
#ifdef SKIP_ASM
extern "C" void func_00276270(sSsxScriptRider* r, int a);

extern "C" void func_00278F38(void* self, int i)
{
    func_00276270(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], 0);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00278F68);
#ifdef SKIP_ASM
extern "C" void func_002EF368(int);
extern "C" int func_00276388(sSsxScriptRider* r, int a, int b);

extern "C" int func_00278F68(void* self, int i, int a, int b)
{
    *(int*)((char*)self + 0x550) = i;
    func_002EF368(1);
    int r = func_00276388(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], a, b);
    if (r != 3) {
        *(int*)((char*)self + 0x550) = 2;
        func_002EF368(0);
    }
    return r;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_00278FF8);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279040);
#ifdef SKIP_ASM
void func_002766B0(void* r, int a);

extern "C" void func_00279040(void* self, int i, int a)
{
    func_002766B0(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], a);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279070);
#ifdef SKIP_ASM
extern "C" void func_002766D0(sSsxScriptRider* r, int a, int b);

extern "C" void func_00279070(void* self, int i, int a, int b)
{
    func_002766D0(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], a, b);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002790A0);
#ifdef SKIP_ASM
extern "C" void func_00276868(void* self, int a1);
extern "C" void func_0027BF90(void* self);

extern "C" void func_002790A0(void* self, int i)
{
    func_00276868(*(char**)((char*)self + 0x54C) + i * 0xCC, 1);
    if (*(int*)((char*)self + 0x550) == i) {
        func_0027BF90(self);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_002790F8);
#ifdef SKIP_ASM
extern "C" void func_002790A0(void*, int);

extern "C" void func_002790F8(void* self)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_002790A0(self, i);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279148);
#ifdef SKIP_ASM
extern "C" void func_00276998(sSsxScriptRider* r, int a);

extern "C" void func_00279148(void* self, int i, int a)
{
    func_00276998(&(*(sSsxScriptRider**)((char*)self + 0x54C))[i], a);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279178);
#ifdef SKIP_ASM
extern "C" void func_00276A08(int, int);

extern "C" void func_00279178(void *arg0, int arg1, int arg2) {
    func_00276A08((*(int *)((char*)(arg0) + (0x54C))) + (arg1 * 0xCC), arg2);
}
#endif
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002791A8);
#ifdef SKIP_ASM
extern "C" void func_00276A78(int, int);

extern "C" void func_002791A8(void *arg0, int arg1, int arg2) {
    func_00276A78((*(int *)((char*)(arg0) + (0x54C))) + (arg1 * 0xCC), arg2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_002791D8);
#ifdef SKIP_ASM
extern "C" void func_00278918(void*);
extern "C" void func_00276B98(void*);

extern "C" void func_002791D8(void* self, int i)
{
    func_00278918(self);
    func_00276B98(*(char**)((char*)self + 0x54C) + i * 0xCC);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279220);
#ifdef SKIP_ASM
extern "C" void func_00276BD8(void*);

extern "C" void func_00279220(void* self, int i)
{
    func_00276BD8((char*)*(void**)((char*)self + 0x54C) + i * 0xCC);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279248);
#ifdef SKIP_ASM
void func_00276CA8(void*);

extern "C" void func_00279248(void* self, int i)
{
    func_00276CA8((char*)*(void**)((char*)self + 0x54C) + i * 0xCC);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279270);
#ifdef SKIP_ASM
extern "C" void func_00277100(int, int);

extern "C" void func_00279270(void *arg0, int arg1) {
    int temp_5;

    temp_5 = arg1 * 0xCC;
    func_00277100((*(int *)((char*)(arg0) + (0x54C))) + temp_5, temp_5);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279298);
#ifdef SKIP_ASM
int func_002772B8(void*);

extern "C" int func_00279298(void* self)
{
    int i = *(int*)((char*)self + 0x550);
    if (i == 2) {
        return 0;
    }
    return func_002772B8(*(char**)((char*)self + 0x54C) + i * 0xCC);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002792E0);
#ifdef SKIP_ASM
extern "C" int func_00277060(sSsxScriptRider* r);
// PORT: the unit declares func_00276BD8 as returning void, but this caller uses
// its int result; bind an int-returning alias by asm label.
extern "C" int func_00276BD8_i(sSsxScriptRider* r) __asm__("func_00276BD8");

extern "C" int func_002792E0(void* self)
{
    int idx = *(int*)((char*)self + 0x550);
    if (idx == 2) {
        return 1;
    }
    int r = 0;
    if (*(int*)((char*)self + 0x554) == 0) {
        if (func_00277060(&(*(sSsxScriptRider**)((char*)self + 0x54C))[idx]) != 0) {
            r = func_00276BD8_i(&(*(sSsxScriptRider**)((char*)self + 0x54C))[*(int*)((char*)self + 0x550)]) != 3;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279370);
#ifdef SKIP_ASM
extern "C" int func_002771C8(void*, int);

extern "C" int func_00279370(void* self, int a)
{
    int i = *(int*)((char*)self + 0x550);
    if (i == 2) {
        return 0;
    }
    return func_002771C8(*(char**)((char*)self + 0x54C) + i * 0xCC, a);
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_002793B8);

INCLUDE_ASM("scripter/ssxscriptengine", func_002793F8);

INCLUDE_ASM("scripter/ssxscriptengine", func_00279428);

INCLUDE_ASM("scripter/ssxscriptengine", func_00279458);
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279488);
#ifdef SKIP_ASM
extern "C" void func_00276868(void* self, int a1);

extern "C" void func_00279488(void* self)
{
    for (int i = 0; i < 2; i++) {
        func_00276868(&(*(sSsxScriptRider**)((char*)self + 0x624))[i], 1);
    }
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_002794E0);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279528);
#ifdef SKIP_ASM
extern "C" int* cSSXScriptEngine_GetScriptFromCategory(void*, int);
void* func_0027BD78(void* self);
void func_0027BD90(void*, void*);
extern "C" int func_002821A0(void* self, int key, void* node);

extern "C" int func_00279528(void* self, int category, int a, int b, int c)
{
    // PORT: one variable holds the script pointer and then the result
    int r = (int)cSSXScriptEngine_GetScriptFromCategory(self, category);
    if (r == 0) return -1;
    int* node = (int*)func_0027BD78(self);
    node[0] = a;
    node[1] = b;
    node[2] = c;
    r = func_002821A0(self, *(int*)r, node);
    if (r < 0) {
        func_0027BD90(self, node);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002795D0);
#ifdef SKIP_ASM
void* func_0027BD78(void* self);
void func_0027BD90(void*, void*);
extern "C" int func_002821A0(void* self, int key, void* node);
extern char* D_004A28A8;

extern "C" int func_002795D0(void* self, int key, int a, int b, int c)
{
    int n = *(int*)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0x78);
    if (a < 0 || a >= n) {
        a = -1;
    }
    if (b < 0 || b >= n) {
        b = -1;
    }
    if (c < 0 || c >= n) {
        c = -1;
    }
    int* node = (int*)func_0027BD78(self);
    node[0] = a;
    node[1] = b;
    node[2] = c;
    int r = func_002821A0(self, key, node);
    if (r < 0) {
        func_0027BD90(self, node);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002796B8);
#ifdef SKIP_ASM
extern "C" int func_002795D0(void* self, int key, int a, int b, int c);

struct sEnt_002796B8 { int a; int key; int c; };

extern "C" int func_002796B8(char* self, int id, int a, int b, int c)
{
    int i = 0;
    if (**(int**)(self + 0x52C) > 0) {
        do {
            if ((*(sEnt_002796B8**)(self + 0x530))[i].key == id)
                return func_002795D0(self, i, a, b, c);
            i++;
        } while (i < **(int**)(self + 0x52C));
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279720);
#ifdef SKIP_ASM
extern "C" int func_00282BF0(void* self, int a1);
extern "C" void* func_002822A0(void* self, int key, int b, int c);
// PORT: func_0027A668 is defined in this unit as (void*), but this caller passes
// (self, index); bind the 2-arg form to the symbol.
void* func_0027A668_2(void* self, int idx) __asm__("func_0027A668__FPv");

extern "C" void func_00279720(void* self, int val, int key, int b, int c)
{
    *(int*)((char*)func_0027A668_2(self, func_00282BF0(self, key)) + 0xC) = val;
    func_002822A0(self, key, b, c);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002797A0);
#ifdef SKIP_ASM
extern "C" int* cSSXScriptEngine_GetScriptFromCategory(void*, int);

extern "C" int func_002797A0(void* self, int category)
{
    int* script = cSSXScriptEngine_GetScriptFromCategory(self, category);
    if (script == 0)
        return -1;
    return *script;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002797C8);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
struct sScriptEng0628;
extern "C" int func_0027B528(sScriptEng0628* self);
extern "C" void func_0027B370(void* self, int slot, const char* name, int flags, int key, int a, int b);
extern const char D_00481C68[];
extern const char D_00481C78[];

extern "C" int func_002797C8(void* self, int key)
{
    char buf[128];
    sprintf(buf, D_00481C68, D_00481C78, key);
    func_0027B370(self, func_0027B528((sScriptEng0628*)self), buf, 0x100, key, 0, 0);
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279840);
#ifdef SKIP_ASM
extern "C" int func_0027B578(void* self, int a1, int a2);
extern "C" void func_0027B4B8(void* self, int idx, int a);

extern "C" void func_00279840(void* self, int a1)
{
    func_0027B4B8(self, func_0027B578(self, a1, 2), a1);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279888);
#ifdef SKIP_ASM
extern "C" int func_0027B578(void* self, int a1, int a2);
extern "C" void func_0027B410(void* self, int idx);

extern "C" void func_00279888(void* self, int a1)
{
    int idx = func_0027B578(self, a1, 2);
    if (idx >= 0) {
        func_0027B410(self, idx);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002798C0);
#ifdef SKIP_ASM
extern "C" int func_00416B18(const char* a, const char* b, int n);
void* func_0027C078(void* self);
extern "C" void func_00282150(void* self, void* data, int a2);
extern "C" void cScriptAnimBankManager_LinkBank(void* mgr, int bank, void* data);
extern "C" void func_00283580(void* mgr, int bank, void* data, int a3);
extern char D_004A34C8[];
extern char D_004A34D0[];
extern char D_004A34D8[];

extern "C" void func_002798C0(char* self, const char* ext, void* data, int a3, int* kind, int* bank)
{
    if (func_00416B18(D_004A34C8, ext, 3) == 0) {
        char* h = (char*)func_0027C078(data);
        *(int*)(h + 0x1C) = *(int*)(self + 0xA48);
        *kind = 0;
        func_00282150(self, data, *(int*)(h + 0x18));
    } else if (func_00416B18(D_004A34D0, ext, 3) == 0) {
        *kind = 1;
        *bank = *(int*)(self + 0xA48);
        cScriptAnimBankManager_LinkBank(self + 0xA28, *(int*)(self + 0xA48), data);
    } else if (func_00416B18(D_004A34D8, ext, 3) == 0) {
        *kind = 2;
        *bank = *(int*)(self + 0xA48);
        func_00283580(self + 0xA38, *(int*)(self + 0xA48), data, a3);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002799E0);
#ifdef SKIP_ASM
void* func_0027C078(void* self);
extern "C" void func_00282178(void* self, int a1);
extern "C" void func_00275650(void* list, int id);
extern "C" void func_00283610(void* list, int id);

extern "C" void func_002799E0(void* self, void* obj, int a2, int type, int id)
{
    switch (type) {
    case 0:
        func_00282178(self, *(int*)((char*)func_0027C078(obj) + 0x18));
        break;
    case 1:
        func_00275650((char*)self + 0xA28, id);
        break;
    case 2:
        func_00283610((char*)self + 0xA38, id);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279A70);
#ifdef SKIP_ASM
unsigned int BXrand();
unsigned char func_002743C8(void* self);
int func_00274388(void* self);
int func_0027C958(void* self);
// PORT: func_0027C960 forwards (self, index) to func_002742E0; the unit declares it with one arg.
void* func_0027C960_9A70(void* self, int i) __asm__("func_0027C960__FPv");
// PORT: callers elsewhere declare func_0027BDB8 with two args; it takes the three player slots too.
extern "C" void func_0027BDB8_9A70(void* self, int* flags, int p0, int p1, int p2) __asm__("func_0027BDB8");
extern "C" void* func_00274C20(void* self, int i);
extern "C" void func_00273A60(void* self, int idx);
extern int D_00482608[];

struct sScriptHdr_9A70 {
    char pad_0x0;
    unsigned char numEvents;        // 0x1
};

struct sScript_9A70 {
    char pad_0x0[0x10];
    sScriptHdr_9A70* hdr;           // 0x10
};

struct sScriptOpt_9A70 {
    signed char slot;               // 0x0
    char pad_0x1;
    short mask;                     // 0x2
};

struct sScriptCount_9A70 {
    int count;
    int pad[2];
};

// Picks a random option for every choice event of a script, honouring the per-slot team flags.
extern "C" void func_00279A70(void* self, sScript_9A70* script, int idx, int* players)
{
    int flags[21];
    int cands[32];
    unsigned int all = 0;
    int i;
    func_0027BDB8_9A70(self, flags, players[0], players[1], players[2]);
    {
        int j;
        for (j = 0; j < 21; j++)
            all |= flags[j];
    }
    for (i = 0; i < script->hdr->numEvents; i++) {
        void* ev = func_00274C20(script, i);
        if (func_002743C8(ev) == 5) {
            int cnt = func_00274388(ev);
            if (cnt >= 2) {
                int m = 0;
                int k;
                for (k = 0; k < cnt; k++) {
                    sScriptOpt_9A70* opt = (sScriptOpt_9A70*)func_0027C960_9A70(ev, k);
                    int slot = D_00482608[opt->slot];
                    if (slot >= 0) {
                        if (opt->mask == 0 || (opt->mask & flags[slot]) != 0)
                            cands[m++] = k;
                    } else {
                        if (opt->mask == 0 || (opt->mask & all) != 0)
                            cands[m++] = k;
                    }
                }
                if (m > 0) {
                    func_00273A60(ev, cands[BXrand() % m]);
                    sScriptOpt_9A70* opt = (sScriptOpt_9A70*)func_0027C958(ev);
                    int slot = D_00482608[opt->slot];
                    if (slot >= 0) {
                        all &= ~flags[slot];
                        flags[slot] = 0;
                    }
                }
            }
        } else {
            int cnt = func_00274388(ev);
            if (cnt >= 2)
                func_00273A60(ev, BXrand() % cnt);
        }
    }
    (*(sScriptCount_9A70**)((char*)self + 0x530))[idx].count++;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279CE0);
#ifdef SKIP_ASM
void func_0027BD90(void*, void*);

extern "C" void func_00279CE0(void* self, int unused, void* arg)
{
    func_0027BD90(self, arg);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279D00);
#ifdef SKIP_ASM
extern "C" int func_0027CEA8(void* self, void* obj);
extern "C" int func_00281190(void* self, void* obj);
extern "C" int func_002812E0(void* self, void* obj);

class cScriptOwner9D00 {
public:
    int state;      // 0x0
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
    virtual void v08();
    virtual int v09();
};

struct sScrSlot9D00 {
    char pad[0x120];
};

struct sSsxEngine9D00 {
    char pad[0x6D0];
    sScrSlot9D00 slots[2];
};

extern "C" int func_00279D00(sSsxEngine9D00* self, cScriptOwner9D00* obj)
{
    int r = func_0027CEA8(self, obj);
    if (obj->state == 1) {
        func_00281190(&self->slots[*(int*)((char*)obj + 0x7C)], obj);
    } else if (obj->state == 2) {
        func_002812E0(&self->slots[obj->v09()], obj);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279DA8);
#ifdef SKIP_ASM
int func_0027D320(void* self, int i);
extern "C" void func_002811E8(void* slot, void* obj);
extern "C" int func_002812E0(void* self, void* obj);
extern "C" int func_0027CF88(void* self, int idx);

class cScriptOwner9DA8 {
public:
    int state;      // 0x0
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
    virtual void v08();
    virtual int v09();
};

struct sScrSlot9DA8 {
    char pad[0x120];
};

struct sSsxEngine9DA8 {
    char pad[0x6D0];
    sScrSlot9DA8 slots[2];
};

extern "C" void func_00279DA8(sSsxEngine9DA8* self, int idx)
{
    // PORT: func_0027D320 returns a table pointer as int
    cScriptOwner9DA8* obj = (cScriptOwner9DA8*)func_0027D320(self, idx);
    if (obj->state == 1) {
        func_002811E8(&self->slots[*(int*)((char*)obj + 0x7C)], obj);
    } else if (obj->state == 2) {
        func_002812E0(&self->slots[obj->v09()], 0);
    }
    func_0027CF88(self, idx);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279E50);
#ifdef SKIP_ASM
int func_0027D320(void* self, int i);
extern "C" int func_0027D790(void* self, int val);
extern "C" void func_0027D210(void* self, int i, int val);
extern "C" void func_00282EF0(void* obj, int val);

extern "C" void func_00279E50(void* self, int i, int val)
{
    // PORT: func_0027D320 returns a table pointer as int
    int* obj = (int*)func_0027D320(self, i);
    int type = *obj;
    if (type == 1) {
        func_0027D790(obj, val);
    } else if (type != 2) {
        func_0027D210(self, i, val);
    } else {
        func_00282EF0(obj, val);
    }
}
#endif

extern "C" void* func_00275718(void*);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279ED8__FPv);
#ifdef SKIP_ASM
void* func_00279ED8(void* self)
{
    return func_00275718((char*)self + 0xa28);
}
#endif

extern "C" void* func_002836D8(void*);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279EF8__FPv);
#ifdef SKIP_ASM
void* func_00279EF8(void* self)
{
    return func_002836D8((char*)self + 0xa38);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00279F18);
#ifdef SKIP_ASM
struct sLvlObj_279F18 {
    char pad0[0x18];
    void* obj;       // 0x18
};

struct sLvl_279F18 {
    char pad0[0x28];
    void* riders[6];             // 0x28
    sLvlObj_279F18* a40[2];      // 0x40
    sLvlObj_279F18* a48[5];      // 0x48
    sLvlObj_279F18* a5C[5];      // 0x5C
    char pad70[8];
    int n78;                     // 0x78
    int n7C;                     // 0x7C
    int n80;                     // 0x80
    int n84;                     // 0x84
};

static inline sLvl_279F18* Lvl_279F18()
{
    return *(sLvl_279F18**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
}

static inline void* ObjOf_279F18(sLvlObj_279F18* o)
{
    return o ? o->obj : 0;
}

extern "C" void* func_00279F18(void* self, int slot, int arg)
{
    int r;
    switch (slot) {
    case 0: {
        int* p = (int*)func_0027A668_2(self, arg);
        if (p[0] < 0) break;
        return Lvl_279F18()->riders[p[0]];
    }
    case 1:
        r = ((int*)func_0027A668_2(self, arg))[1];
        if (r < 0) break;
        return Lvl_279F18()->riders[r];
    case 2:
        r = ((int*)func_0027A668_2(self, arg))[2];
        if (r < 0) break;
        return Lvl_279F18()->riders[r];
    case 3: case 4: {
        sLvl_279F18* lvl = Lvl_279F18();
        int j = slot - 3;
        if (j >= lvl->n7C) break;
        return ObjOf_279F18(lvl->a40[j]);
    }
    case 5: case 6: case 7: case 8: case 9: {
        sLvl_279F18* lvl = Lvl_279F18();
        int j = slot - 5;
        if (j >= lvl->n80 + lvl->n84) break;
        if (j < lvl->n80) return ObjOf_279F18(lvl->a48[j]);
        return ObjOf_279F18(lvl->a5C[j - lvl->n80]);
    }
    case 10: case 11: case 12: case 13: case 14: {
        sLvl_279F18* lvl = Lvl_279F18();
        int j = slot - 10;
        if (j >= lvl->n84 + lvl->n80) break;
        if (j < lvl->n84) return ObjOf_279F18(lvl->a5C[j]);
        return ObjOf_279F18(lvl->a48[j - lvl->n84]);
    }
    case 15: case 16: case 17: case 18: case 19: case 20: {
        sLvl_279F18* lvl = Lvl_279F18();
        int j = slot - 15;
        if (j >= lvl->n78) break;
        return lvl->riders[j];
    }
    }
    return 0;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_0027A0D8);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A4A0);
#ifdef SKIP_ASM
void* func_002E4D70(void* self);
extern void* D_004880C0[];
// PORT: the wake-fx pool allocator ignores its argument; callers pass the object size.
extern "C" void* func_002E4CE8_sz(unsigned size) __asm__("func_002E4CE8");

struct sColor_27A4A0
{
    float r, g, b, a;
    sColor_27A4A0() {}
    sColor_27A4A0(float ar, float ag, float ab, float aa) { r = ar; g = ag; b = ab; a = aa; }
};

struct sFx_27A4A0
{
    void** vt;
    sColor_27A4A0 c;
};

extern "C" void* func_002EBBA8(void* self, const sColor_27A4A0* col, int dx, int dy);
extern "C" void* func_002EBE20(void* self, const sColor_27A4A0* col);

static inline sFx_27A4A0* initFx_27A4A0(sFx_27A4A0* p, const sColor_27A4A0& col)
{
    func_002E4D70(p);
    p->vt = D_004880C0;
    p->c = col;
    return p;
}

extern "C" void* func_0027A4A0(void* self, int type, int mode)
{
    sColor_27A4A0 c;
    switch (mode) {
    case 0:
        c.r = 1.0f;
        c.g = 0.0f;
        c.b = 0.0f;
        c.a = 0.0f;
        break;
    case 1:
        c.r = 1.0f;
        c.g = 1.0f;
        c.b = 1.0f;
        c.a = 1.0f;
        break;
    }
    switch (type) {
    case 1: {
        sFx_27A4A0* p = (sFx_27A4A0*)func_002E4CE8_sz(0x14);
        sColor_27A4A0 t = c;
        return initFx_27A4A0(p, t);
    }
    case 2:
        return func_002EBBA8(func_002E4CE8_sz(0x1C), &c, -1, 0);
    case 3:
        return func_002EBBA8(func_002E4CE8_sz(0x1C), &c, 1, 0);
    case 4:
        return func_002EBBA8(func_002E4CE8_sz(0x1C), &c, 0, -1);
    case 5:
        return func_002EBBA8(func_002E4CE8_sz(0x1C), &c, 0, 1);
    case 6:
        return func_002EBE20(func_002E4CE8_sz(0x1C), &c);
    case 7: {
        sFx_27A4A0* p = (sFx_27A4A0*)func_002E4CE8_sz(0x14);
        sColor_27A4A0 t;
        t.r = 1.0f;
        t.g = 1.0f;
        t.b = 1.0f;
        t.a = 1.0f;
        return initFx_27A4A0(p, t);
    }
    case 0:
    case 8:
        break;
    }
    return 0;
}
#endif

// PORT: the real function is func_00282BB0__FPvT0 (void*, void*); this caller passes only $a0.
void* func_00282BB0(void* self) __asm__("func_00282BB0__FPvT0");

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A668__FPv);
#ifdef SKIP_ASM
void* func_0027A668(void* self)
{
    return func_00282BB0(self);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A688);
#ifdef SKIP_ASM
extern "C" int func_0022E0C8(void* self, int a1);
extern char* D_004A28A8;

extern "C" int func_0027A688()
{
    return func_0022E0C8(*(void**)(*(char**)(D_004A28A8 + 0x84) + 0x78), 0x2B);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A6B0);
#ifdef SKIP_ASM
extern "C" void func_002829D0(void* self, void* a1);
extern "C" void func_002772C0(void* self, int a1, void* obj);
int func_00282BE0(void* self, void* a1);

extern "C" void func_0027A6B0(void* self, void* a1)
{
    func_002829D0(self, a1);
    int r = *(int*)((char*)self + 0x550);
    if (r != 2) {
        func_002772C0(*(char**)((char*)self + 0x54C) + r * 0xCC, func_00282BE0(self, a1), a1);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A720);
#ifdef SKIP_ASM
extern "C" void func_00277310(void* self, int a1, void* obj, float x, float y);
int func_00282BE0(void* self, void* a1);

extern "C" void func_0027A720(void* self, void* a1, float x, float y)
{
    int r = *(int*)((char*)self + 0x550);
    if (r != 2) {
        func_00277310(*(char**)((char*)self + 0x54C) + r * 0xCC, func_00282BE0(self, a1), a1, x, y);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A798);
#ifdef SKIP_ASM
extern "C" void func_002773A0(void* self, int a1, void* obj);
int func_00282BE0(void* self, void* a1);

extern "C" void func_0027A798(void* self, void* a1)
{
    int r = *(int*)((char*)self + 0x550);
    if (r != 2) {
        func_002773A0(*(char**)((char*)self + 0x54C) + r * 0xCC, func_00282BE0(self, a1), a1);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A7F0);
#ifdef SKIP_ASM
extern "C" void func_00277400(void* self, int a1, void* obj);
extern "C" void func_00282A18(void* self, void* a1);
int func_00282BE0(void* self, void* a1);

extern "C" void func_0027A7F0(void* self, void* a1)
{
    int r = *(int*)((char*)self + 0x550);
    if (r != 2) {
        func_00277400(*(char**)((char*)self + 0x54C) + r * 0xCC, func_00282BE0(self, a1), a1);
    }
    func_00282A18(self, a1);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A860);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00278E50(void* self, int i, int a, int b, int c, int d, int f, int g);
extern "C" void func_00278F38(void* self, int i);
extern "C" int func_00278F68(void* self, int i, int a, int b);
extern "C" void* func_0028B180();
extern "C" void func_0028E8C0(void* self, int id, int a2);
extern char* D_004A28A8;
struct sSseGame_A860 {
    char pad_0x0[0xF44];
    int field_0xF44;        // 0xF44
};
extern sSseGame_A860* D_004A289C_A860 __asm__("D_004A289C");

static inline int sseWorldMode_A860()
{
    return *(int*)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0x7C);
}

extern "C" void func_0027A860(void* self, int online, int intro)
{
    if (online) {
        if (intro) {
            func_00278E50(self, 1, 0x12, 1, 1, -1, -1, -1);
        }
        func_00278E50(self, 1, 0x13, 0, 0, -1, -1, -1);
        if (sseWorldMode_A860() == 1) {
            func_00278E50(self, 1, 0x14, 8, 0, -1, -1, -1);
        } else {
            func_00278E50(self, 1, 0x15, 8, 0, -1, -1, -1);
        }
    } else {
        if (intro) {
            func_00278E50(self, 1, 0xC, 1, 1, -1, -1, -1);
        }
        func_00278E50(self, 1, 0xD, 0, 1, -1, -1, -1);
        D_004A289C_A860->field_0xF44 = 1;
        if (sseWorldMode_A860() == 1) {
            func_00278E50(self, 1, 0xE, 8, 1, -1, -1, -1);
        } else {
            func_00278E50(self, 1, 0xF, 8, 0, -1, -1, -1);
        }
    }
    func_00278F38(self, 1);
    func_00278F68(self, 1, 0, 1);
    func_0028E8C0(func_0028B180(), 0x14, 1);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027A9F0);
#ifdef SKIP_ASM
int func_00279148_r(void* self, int a1, int a2) __asm__("func_00279148");
extern "C" void func_00279070(void* self, int a1, int a2, int a3);

extern "C" bool func_0027A9F0(void* self)
{
    int v = 0;
    switch (func_00279148_r(self, 1, 0)) {
    case 12: case 18:
        v = 3;
        break;
    case 13: case 19:
        v = 2;
        break;
    case 14: case 20:
        v = 1;
        break;
    case 15: case 16: case 17:
        break;
    }
    func_00279070(self, 1, v, 1);
    return v != 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_0027AA80);
#ifdef SKIP_ASM
// PORT: the unit defines func_00279148 as void, but it returns func_00276998's
// int result (a tail call); bind an int-returning form to the symbol.
int func_00279148_int(void* self, int i, int a) __asm__("func_00279148");

extern "C" int func_0027AA80(void* self)
{
    if (*(int*)((char*)self + 0x550) != 1) {
        return 0;
    }
    int s = func_00279148_int(self, 1, 0);
    int r = 0;
    if (s == 0x12 || s == 0xC || s == 0x13 || s == 0xD || s == 0x14 || s == 0xE) {
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027AAF8);
#ifdef SKIP_ASM
extern "C" void func_00278E50(void* self, int i, int a, int b, int c, int d, int f, int g);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A28A4;
extern char* D_004A28A8;
extern signed char D_00535C11[];
extern int* D_00445488[];
extern int D_00534B30[];
extern int D_00481E80[];

extern "C" void func_0027AAF8(void* self, int state)
{
    switch (state) {
    case 0: {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        int* tbl = D_00445488[D_00535C11[0]];
        cBE_getInterface_Fv(*(void**)(D_004A28A8 + 0x78), 7);
        if (D_00534B30[0] != 0) {
            tbl = D_00481E80;
        }
        if (tbl != 0 && tbl[0] >= 0) {
            do {
                func_00278E50(D_004A28A4, 0, tbl[0], tbl[1], 0, -1, -1, -1);
                tbl += 2;
            } while (tbl[0] >= 0);
        }
        break;
    }
    case 1:
    case 2:
        func_00278E50(D_004A28A4, 0, 5, 0, 0, -1, -1, -1);
        break;
    case 3:
        func_00278E50(D_004A28A4, 0, 4, 3, 0, -1, -1, -1);
        func_00278E50(D_004A28A4, 0, 5, 0, 0, -1, -1, -1);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027AC60);
#ifdef SKIP_ASM
extern "C" int* func_00144BC0(void* iface);
extern "C" int func_00146150(void* self, int index, int kind, int flag);
extern "C" void func_00146320(void* self, int index, int kind, int flag, int value);
extern "C" int func_001464D0(void* self, int index, int rc, int kind, int flag);
extern "C" int func_00146E98(void* iface, int idx);
extern "C" signed char func_0014A0B0(int index);
int cBENewPlayerInterface_getRiderCharID(void* self, int index);

struct sScGame_AC60 {
    char pad_0x0[0x48];
    signed char mode;               // 0x48
    signed char lock;               // 0x49
};

struct sScVt_AC60 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sScSub_AC60 {
    sScVt_AC60* vt;
};

struct sScRider_AC60 {
    char pad_0x0[0x6C0];
    sScSub_AC60 sub;                // 0x6C0
};

struct sScSlot_AC60 {
    char pad_0x0[0x18];
    sScRider_AC60* rider;           // 0x18
};

struct sScList_AC60 {
    char pad_0x0[0x28];
    sScRider_AC60* riders[6];       // 0x28
    sScSlot_AC60* slots[2];         // 0x40
    sScSlot_AC60* first;            // 0x48
    char pad_0x4C[0x5C - 0x4C];
    sScSlot_AC60* other;            // 0x5C
    char pad_0x60[0x78 - 0x60];
    int nriders;                    // 0x78
    int nslots;                     // 0x7C
    int nfirst;                     // 0x80
    int nother;                     // 0x84
};

struct sScTbl_AC60 {
    int v[4];
};

struct sScBlk_AC60 {
    int w[0x54 / 4];
    int kind;                       // 0x54
    int w2[(0x64 - 0x58) / 4];
};

extern sScGame_AC60 D_00535BC8;
extern int D_00536730[];
extern int D_00536708[];
extern sScTbl_AC60 D_00481E90;

static inline int Call_AC60(sScRider_AC60* r, int slot)
{
    sScSub_AC60* s = &r->sub;
    return s->vt[slot].fn((char*)s + s->vt[slot].delta);
}

extern "C" void func_0027AC60(void* self)
{
    void* econ = cBE_getInterface_Fv(cBE_getBE(), 0);
    sScGame_AC60* g = &D_00535BC8;
    int mode = g->mode;
    if (mode == 4) {
        return;
    }
    if (*(int*)(*(char**)(D_004A28A8 + 0xC0) + 0x98) == 0) {
        return;
    }
    char* x = *(char**)(D_004A28A8 + 0x84);
    if (*(int*)(*(char**)(x + 0x84) + 0x10) != 1) {
        return;
    }
    int found = 0;
    sScList_AC60* list = *(sScList_AC60**)(x + 0xC);
    if (g->lock == 0) {
        for (int i = 0; i < list->nslots; i++) {
            if (D_00536730[Call_AC60(list->slots[i]->rider, 7)] < 3) {
                found = 1;
                goto done;
            }
        }
    }
done:
    if (found) {
        int ids[3];
        int best = 3;
        for (int j = 0; j < 3; j++) {
            int v = D_00536708[j];
            ids[j] = v;
            if (v >= list->nriders) {
                ids[j] = -1;
            } else if (Call_AC60(list->riders[v], 8)) {
                best = j;
            }
        }
        sScTbl_AC60 tbl = D_00481E90;
        int k = tbl.v[best];
        if (best == 0) {
            k = 9;
            int c = func_0014A0B0(Call_AC60(list->riders[ids[0]], 7));
            if ((unsigned)(c - 10) < 11 || c == 0x1C) {
                k = 10;
            }
        }
        func_00278E50(D_004A28A4, 0, k, 1, 0, ids[0], ids[1], ids[2]);
    }
    if (D_00535BC8.lock != 0) {
        return;
    }
    if ((unsigned)mode >= 4) {
        return;
    }
    void* players = cBE_getInterface_Fv(cBE_getBE(), 1);
    sScBlk_AC60 blk = *(sScBlk_AC60*)func_00144BC0(econ);
    int first = mode == 0;
    int idx = func_00146E98(players, 0);
    int r = func_00146150(players, idx, blk.kind, first);
    if ((unsigned)(func_0014A0B0(idx) - 10) < 11) {
        return;
    }
    int rc = cBENewPlayerInterface_getRiderCharID(players, idx);
    if (func_001464D0(players, idx, rc, blk.kind, first)) {
        return;
    }
    if (r != 0) {
        return;
    }
    int v = -1;
    if (list->nfirst > 0) {
        v = Call_AC60(list->first->rider, 7);
    } else if (list->nother > 0) {
        v = Call_AC60(list->other->rider, 7);
    }
    func_00278E50(D_004A28A4, 0, 0x18, 1, 0, v, -1, -1);
    func_00278E50(D_004A28A4, 0, 0x19, 3, 0, v, -1, -1);
    func_00146320(players, idx, blk.kind, first, 1);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", cSSXScriptEngine_GetScriptFromCategory);
#ifdef SKIP_ASM
void cMemMan_free(void*);
unsigned int BXrand();
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label as the tagged operator new[].
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_0027BDB8(void* self, int* flags);
extern char D_00481EA0[];

struct sScript_27B0C0
{
    int id;
    short mask[21];
};

struct sCategory_27B0C0
{
    int count;
    sScript_27B0C0* scripts;
};

struct sPri_27B0C0
{
    int pri;
    int a;
    int b;
};

struct sEngine_27B0C0
{
    char pad0[0x530];
    sPri_27B0C0* pris;
    char pad534[0x8];
    int numCategories;
    sCategory_27B0C0* categories;
};

extern "C" int* cSSXScriptEngine_GetScriptFromCategory(void* p, int cat)
{
    sEngine_27B0C0* self = (sEngine_27B0C0*)p;
    if (self->numCategories == 0 || self->categories[cat].count == 0)
        return 0;
    int flags[21];
    func_0027BDB8(self, flags);
    int best = 0xFFFF;
    int n = 0;
    sScript_27B0C0** list = new (D_00481EA0, 0x100, 0) sScript_27B0C0*[100];
    int count = self->categories[cat].count;
    sScript_27B0C0* scripts = self->categories[cat].scripts;
    for (int i = 0; i < count; i++)
    {
        sScript_27B0C0* s = &scripts[i];
        int pri = self->pris[s->id].pri;
        if (pri <= best)
        {
            int fail = 0;
            for (int j = 0; j < 21; j++)
            {
                if (s->mask[j] != 0 && (flags[j] & s->mask[j]) == 0)
                {
                    fail = 1;
                    break;
                }
            }
            if (!fail)
            {
                if (pri < best)
                {
                    best = pri;
                    n = 0;
                }
                list[n++] = s;
            }
        }
    }
    sScript_27B0C0* r = n ? list[BXrand() % n] : 0;
    if (list)
        cMemMan_free(list);
    return (int*)r;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B268);
#ifdef SKIP_ASM
void func_00277F08(void* slot);
extern "C" int func_00275920(void* self, const char* name, int* data, int size);
extern "C" int func_00317F98(const char* name);
extern "C" int* func_003E1908(const char* name, int flags);
extern "C" int func_003E1BB8(const char* name, int* buf, int a2);

struct sSeSlotB268 {
    int handle;     // 0x0
    int key;        // 0x4
    int field_0x8;
    int temp;       // 0xC
};

extern "C" void func_0027B268(char* self, int i, const char* name, int flags, int key, int* buf)
{
    sSeSlotB268* s = (sSeSlotB268*)(self + (i * 0x10 + 0x628));
    if (s->handle != 0) {
        return;
    }
    s->key = key;
    int size = 0;
    int* data;
    if (buf != 0) {
        data = 0;
        if (func_003E1BB8(name, buf, 0) != 0) {
            data = buf;
        }
    } else {
        data = func_003E1908(name, flags);
        if (data == 0) {
            func_00277F08(s);
            return;
        }
        size = func_00317F98(name);
    }
    if (data == 0) {
        func_00277F08(s);
        return;
    }
    *(int*)(self + 0xA48) = i;
    s->handle = func_00275920(self + 0x51C, name, data, size);
    *(int*)(self + 0xA48) = 10;
    s->temp = 1;
    if (buf != 0) {
        s->temp = 0;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B370);
#ifdef SKIP_ASM
extern "C" void* func_003DF748(const char* name, int a, int b);
extern "C" void* func_003DF690(const char* name, int flags, int b);
void func_00277F08(void* slot);

extern "C" void func_0027B370(void* self, int i, const char* name, int flags, int key, int a, int b)
{
    char* slot = (char*)self + (i * 16 + 0x628);
    *(int*)(slot + 0x4) = key;
    if (a != 0) {
        *(void**)(slot + 0x8) = func_003DF748(name, a, b);
        *(int*)(slot + 0xC) = 0;
    } else {
        *(void**)(slot + 0x8) = func_003DF690(name, flags, b);
        *(int*)(slot + 0xC) = 1;
    }
    if (*(void**)(slot + 0x8) != 0) {
        *(int*)((char*)self + 0x620) += 1;
    }
    if (*(void**)(slot + 0x8) == 0) {
        func_00277F08(slot);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B410);
#ifdef SKIP_ASM
extern "C" void func_003DFAF0(void* file);
extern "C" int ASYNCFILE_release(void* file, int a, int b);
void func_00277F08(void* slot);
void cMemMan_free(void*);
extern "C" void* func_00275A20(void* self, int key);

extern "C" void func_0027B410(void* self, int i)
{
    char* slot = (char*)self + (i * 16 + 0x628);
    int key = *(int*)slot;
    if (key != 0) {
        void* p = func_00275A20((char*)self + 0x51C, key);
        if (*(int*)(slot + 0xC) != 0 && p != 0) {
            cMemMan_free(p);
        }
    } else if (*(void**)(slot + 0x8) != 0) {
        func_003DFAF0(*(void**)(slot + 0x8));
        ASYNCFILE_release(*(void**)(slot + 0x8), 0, 0);
        *(int*)((char*)self + 0x620) -= 1;
    }
    func_00277F08(slot);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B4B8);
#ifdef SKIP_ASM
extern "C" void func_003DFAF0(void* file);
extern "C" int ASYNCFILE_release(void* file, int a, int b);
void func_00277F08(void* slot);

extern "C" void func_0027B4B8(void* self, int i, int a)
{
    char* slot = (char*)self + (i * 16 + 0x628);
    if (*(void**)(slot + 0x8) != 0) {
        func_003DFAF0(*(void**)(slot + 0x8));
        ASYNCFILE_release(*(void**)(slot + 0x8), 0, 0);
        *(int*)((char*)self + 0x620) -= 1;
        func_00277F08(slot);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B528);
#ifdef SKIP_ASM
struct sSlot0628 {
    int a;
    int b;
    int c;
    int d;
};

struct sScriptEng0628 {
    char pad[0x628];
    sSlot0628 slots[10];
};

static inline int isSlotFree(sSlot0628* s)
{
    if (s->c == 0) {
        if (s->a == 0) return 1;
    }
    return 0;
}

extern "C" int func_0027B528(sScriptEng0628* self)
{
    for (int i = 2; i < 10; i++) {
        if (isSlotFree(&self->slots[i])) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B578);
#ifdef SKIP_ASM
static inline int IsFree27B578(int* key)
{
    return key[1] == 0 && key[-1] == 0;
}

// Finds the next used entry (from `start`) whose key matches; returns its index or -1.
extern "C" int func_0027B578(void* self, int key, int start)
{
    for (int i = start; i < 10; i++) {
        int* k = (int*)((char*)self + (i * 16 + 0x62C));
        if (!IsFree27B578(k) && *k == key) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B5D8);
#ifdef SKIP_ASM
// PORT: the unit declares ASYNCFILE_release(void*, int, int); this caller passes
// out-pointers, so bind a pointer-typed alias by asm label.
extern "C" int ASYNCFILE_release_out(void* file, int** data, int* size) __asm__("ASYNCFILE_release");
extern "C" int sprintf(char* buf, const char* fmt, ...);
void func_00277F08(void* slot);
extern "C" int func_00275920(void* self, const char* name, int* data, int size);
extern const char D_00481EB0[];

extern "C" void func_0027B5D8(void* self, void* file)
{
    char buf[128];
    struct {
        int* data;
        int size;
    } r;
    for (int i = 0; i < 10; i++) {
        sSlot0628* s = &((sScriptEng0628*)self)->slots[i];
        if ((void*)s->c == file) {
            ASYNCFILE_release_out(file, &r.data, &r.size);
            *(int*)((char*)self + 0x620) -= 1;
            if (r.size == 0) {
                func_00277F08(s);
                return;
            }
            sprintf(buf, D_00481EB0, s->b);
            s->c = 0;
            *(int*)((char*)self + 0xA48) = i;
            s->a = func_00275920((char*)self + 0x51C, buf, r.data, r.size);
            *(int*)((char*)self + 0xA48) = 10;
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B6B0);
#ifdef SKIP_ASM
// PORT: the unit declares ASYNCFILE_release(void*, int, int); this caller passes
// out-pointers, so bind a pointer-typed alias by asm label.
extern "C" int ASYNCFILE_release_out(void* file, int** data, int* size) __asm__("ASYNCFILE_release");

struct sScrReloc6B0 {
    int used;
    int offset;
};

struct sScrRelocOwner6B0 {
    char pad_0x000[0x538];
    void* file;                 // 0x538
    int* header;                // 0x53C
    sScrReloc6B0* entries;      // 0x540
    char pad_0x544[0x620 - 0x544];
    int pending;                // 0x620
};

extern "C" void func_0027B6B0(sScrRelocOwner6B0* self, void* file)
{
    struct {
        int* data;
        int size;
    } r;
    self->file = 0;
    ASYNCFILE_release_out(file, &r.data, &r.size);
    self->pending -= 1;
    if (r.size != 0) {
        self->header = r.data;
        self->entries = (sScrReloc6B0*)(r.data + 1);
        for (int i = 0; i < *self->header; i++) {
            if (self->entries[i].used != 0) {
                // PORT: offset relocated to an absolute pointer held in int
                self->entries[i].offset = (int)r.data + self->entries[i].offset;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B750);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);
extern "C" void* func_0026B5E0(void*, int, int);
extern char D_004D33A0[];

struct sVec4_27B750
{
    float x, y, z, w;
    sVec4_27B750(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

struct sVec2_27B750
{
    float x, y;
    sVec2_27B750() {}
};

struct sNode_27B750
{
    char pad0[0x8];
    float px, py, pz;
    float dx, dy, dz;
};

struct sVEntry_27B750 { short delta; short index; int (*fn)(void*); };

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_27B750(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Length_27B750(const sVec2_27B750& v)
{
    return Sqrt_27B750(v.x * v.x + v.y * v.y);
}

static inline float Atan2_27B750(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f)
            a += 3.1415927410125732f;
        else
            a -= 3.1415927410125732f;
    }
    return a;
}

extern "C" void func_0027B750(void* self, char* obj, sVec4_27B750* pos, int* roll, float* pitch, float* yaw)
{
    char* sub = obj + 0x6C0;
    sVEntry_27B750* e = &(*(sVEntry_27B750**)sub)[7];
    sNode_27B750* p = (sNode_27B750*)func_0026B5E0(D_004D33A0, 1, e->fn(sub + e->delta));
    *pos = sVec4_27B750(p->px, p->py, p->pz, 1.0f);
    *yaw = Atan2_27B750(p->dy, p->dx);
    float z = p->dz;
    sVec2_27B750 h;
    h.x = p->dx;
    h.y = p->dy;
    *pitch = Atan2_27B750(z, Length_27B750(h));
    *roll = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027B948);
#ifdef SKIP_ASM
extern "C" float func_0031C228(float x);

struct sVec4_27B948
{
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sVec2_27B948
{
    float x, y;
    sVec2_27B948(float a, float b) : x(a), y(b) {}
};

struct sVEntry_27B948 { short delta; short index; sVec4_27B948* (*fn)(void*); };

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_27B948(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

static inline float Length_27B948(const sVec2_27B948& v)
{
    return Sqrt_27B948(v.x * v.x + v.y * v.y);
}

static inline float Atan2_27B948(float y, float x)
{
    if (x == 0.0f)
    {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float a = func_0031C228(y / x);
    if (x < 0.0f)
    {
        if (y > 0.0f)
            a += 3.1415927410125732f;
        else
            a -= 3.1415927410125732f;
    }
    return a;
}

extern "C" void func_0027B948(void* self, char* obj, sVec4_27B948* pos, int* roll, float* pitch, float* yaw)
{
    char* sub = obj + 0x6C0;
    sVEntry_27B948* e = &(*(sVEntry_27B948**)sub)[5];
    *pos = *e->fn(sub + e->delta);
    sVec4_27B948 dir = *(sVec4_27B948*)(obj + 0x1B0);
    *yaw = Atan2_27B948(dir.y, dir.x);
    sVec2_27B948 h(dir.x, dir.y);
    *pitch = Atan2_27B948(dir.z, Length_27B948(h));
    *roll = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BB08);
#ifdef SKIP_ASM
extern "C" float func_0031C128(float x);
extern "C" int* func_00144BC0(void* iface);
extern int D_00482660[];
extern char** D_004A47B8;

struct sVec_27BB08 {
    float x, y, z, w;
    sVec_27BB08() {}
    sVec_27BB08(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

struct sMat_27BB08 {
    float m[16];
    // PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy); the PC port needs a plain 64-byte copy.
    sMat_27BB08& operator=(const sMat_27BB08& o)
    {
        __asm__ __volatile__(
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            :
            : "r"(this), "r"(&o)
            : "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// PORT: PS2-only VU0 inline asm (4x4 matrix * vector); the PC port needs a C fallback.
static inline sVec_27BB08 MulMat_27BB08(const sMat_27BB08* m, const sVec_27BB08& v)
{
    sVec_27BB08 r;
    __asm__(
        "lqc2      $vf8, %2\n"
        "lqc2      $vf4, 0x0(%1)\n"
        "lqc2      $vf5, 0x10(%1)\n"
        "lqc2      $vf6, 0x20(%1)\n"
        "lqc2      $vf7, 0x30(%1)\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "sqc2      $vf12, %0\n"
        : "=m"(r)
        : "r"(m), "m"(v)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (in-place a += b).
static inline void AddEq_27BB08(sVec_27BB08& a, const sVec_27BB08& b)
{
    __asm__(
        "lqc2      $vf3, %0\n"
        "lqc2      $vf4, %1\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "+m"(a)
        : "m"(b)
        : "memory");
}

static inline float Atan2_27BB08(float y, float x)
{
    if (x == 0.0f) {
        if (y == 0.0f)
            return y;
        if (y >= 0.0f)
            return 1.5707963705062866f;
        return -1.5707963705062866f;
    }
    float r = func_0031C228(y / x);
    if (x < 0.0f) {
        if (y > 0.0f)
            r += 3.1415927410125732f;
        else
            r -= 3.1415927410125732f;
    }
    return r;
}

static inline char* IdxToPtr_27BB08(unsigned int i)
{
    return (char*)(i << 2);
}

static inline char* RefToPtr_27BB08(unsigned int v)
{
    unsigned int i = v >> 8;
    if (i == 0)
        return 0;
    return IdxToPtr_27BB08(i);
}

static inline char* Bone_27BB08(char* model, unsigned int code)
{
    if (model == 0)
        return 0;
    return RefToPtr_27BB08(((unsigned int*)*(char**)(model + 0x1C))[code >> 8]);
}

extern "C" void func_0027BB08(char* self, int slot, sVec_27BB08* pos, int* flag, float* pitch, float* yaw, int cat,
                              const sVec_27BB08* off)
{
    if (cat == 0x32) {
        int k = *func_00144BC0(cBE_getInterface_Fv(cBE_getBE(), 0));
        cat = D_00482660[k];
    }
    int* tbl = *(int**)(self + (cat << 2) + 0x558);
    if (tbl == 0)
        return;
    unsigned int code = tbl[slot];
    if (~code == 0)
        return;
    char* model = ((char**)*(char**)(*D_004A47B8 + 8))[code & 0xFF];
    char* m = Bone_27BB08(model, code);
    *pos = sVec_27BB08(*(float*)(m + 0x40), *(float*)(m + 0x44), *(float*)(m + 0x48), 1.0f);
    *yaw = Atan2_27BB08(*(float*)(m + 0x14), *(float*)(m + 0x10));
    *pitch = func_0031C128(*(float*)(m + 0x18));
    *flag = 0;
    if (off) {
        sMat_27BB08 rot;
        rot = *(sMat_27BB08*)(m + 0x10);
        sVec_27BB08 v = *off;
        v.w = 0.0f;
        v = MulMat_27BB08(&rot, v);
        AddEq_27BB08(*pos, v);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BD78__FPv);
#ifdef SKIP_ASM
void* func_0027BD78(void* self)
{
    void* head = *(void**)((char*)self + 0x548);
    *(void**)((char*)self + 0x548) = *(void**)((char*)head + 0x10);
    *(void**)((char*)head + 0x10) = 0;
    return head;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BD90__FPvT0);
#ifdef SKIP_ASM
void func_0027BD90(void* self, void* a1)
{
    *(void**)((char*)a1 + 0x10) = *(void**)((char*)self + 0x548);
    *(int*)a1 = -1;
    *(int*)((char*)a1 + 0x4) = -1;
    *(int*)((char*)a1 + 0x8) = -1;
    *(int*)((char*)a1 + 0xc) = -1;
    *(void**)((char*)self + 0x548) = a1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BDB8);
#ifdef SKIP_ASM
extern "C" int func_00123128(void* self);
extern char* D_004A28A8;
extern int D_00481BB0[];

struct sRiderObj_BDB8 {
    char pad_0x0[0x18];
    void* rider;                    // 0x18
};

struct sRiderSet_BDB8 {
    char pad_0x0[0x28];
    void* players[6];               // 0x28
    sRiderObj_BDB8* groupA[2];      // 0x40
    sRiderObj_BDB8* groupB[5];      // 0x48
    sRiderObj_BDB8* groupC[5];      // 0x5C
    char pad_0x70[0x8];
    int numPlayers;                 // 0x78
    int numA;                       // 0x7C
    int numB;                       // 0x80
    int numC;                       // 0x84
};

// PORT: callers pass only (self, flags); the three player slots arrive in a2..a4.
extern "C" void func_0027BDB8_def(void* self, int* flags, int p0, int p1, int p2) __asm__("func_0027BDB8");

// Fills the 21 per-slot team flags of the script engine from the current rider set.
extern "C" void func_0027BDB8_def(void* self, int* flags, int p0, int p1, int p2)
{
    sRiderSet_BDB8* set = *(sRiderSet_BDB8**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
    int numA = set->numA;
    int numB = set->numB;
    int i;
    for (i = 0; i < 21; i++) {
        flags[i] = 0;
        switch (i) {
        case 0:
            if (p0 >= 0)
                flags[i] = D_00481BB0[func_00123128(set->players[p0])];
            break;
        case 1:
            if (p1 >= 0)
                flags[i] = D_00481BB0[func_00123128(set->players[p1])];
            break;
        case 2:
            if (p2 >= 0)
                flags[i] = D_00481BB0[func_00123128(set->players[p2])];
            break;
        case 3:
        case 4:
            if (i - 3 < numA)
                flags[i] = D_00481BB0[func_00123128(set->groupA[i - 3]->rider)];
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if (i - 5 < numB)
                flags[i] = D_00481BB0[func_00123128(set->groupB[i - 5]->rider)];
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
            if (i - 10 < set->numC)
                flags[i] = D_00481BB0[func_00123128(set->groupC[i - 10]->rider)];
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            if (i - 15 < set->numPlayers)
                flags[i] = D_00481BB0[func_00123128(set->players[i - 15])];
            break;
        default:
            break;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BF50);
#ifdef SKIP_ASM
extern "C" void func_00278918(void*);

extern "C" int func_0027BF50(void* self, int i)
{
    func_00278918(self);
    return *(int*)((char*)self + (i << 4) + 0x630) != 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BF90);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_0028E888(void*);
extern "C" void func_002EF368(int);

extern "C" void func_0027BF90(void* self)
{
    if (*(int*)((char*)self + 0x550) != 2) {
        *(int*)((char*)self + 0x550) = 2;
        *(int*)((char*)self + 0x554) = 0;
        func_0028E888(func_0028B180());
        func_002EF368(0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027BFD0);
#ifdef SKIP_ASM
void func_00282F60(void*);
void* func_00283200(void*, int);
extern void* D_00482318[];
extern void* D_004822E0[];

extern "C" void* func_0027BFD0(void* self)
{
    func_00282F60(self);
    func_00283200((char*)self + 0xC, 4);
    *(void***)((char*)self + 0x18) = D_00482318;
    *(void***)self = D_004822E0;
    return self;
}
#endif

void func_00283440(void*);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C020);
#ifdef SKIP_ASM
extern "C" void func_0027C020(void* self)
{
    func_00283440((char*)self + 0xc);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C040);
#ifdef SKIP_ASM
extern "C" int func_0027C040(void* self, void* a1, int a2)
{
    return a2 == 6;
}
#endif

extern "C" void func_0027CBB0(void*, void*);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C050);
#ifdef SKIP_ASM
extern "C" void func_0027C050(void* self, void* a1)
{
    char buf[16];
    func_0027CBB0(a1, buf);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C070__FPv);
#ifdef SKIP_ASM
int func_0027C070(void* self)
{
    return *(int*)((char*)self + 0x14);
}
#endif

extern "C" void* func_00274C38(void* self);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C078__FPv);
#ifdef SKIP_ASM
void* func_0027C078(void* self)
{
    return func_00274C38(self);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C098__FPv);
#ifdef SKIP_ASM
int func_0027C098(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C0A0);
#ifdef SKIP_ASM
extern "C" void* func_002742E0(void* self);

extern "C" void* func_0027C0A0(void* self)
{
    return func_002742E0(self);
}
#endif
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C0C0);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C0C0(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C0F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cScriptObjC0F0 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual float* v04();
};

// Same symbol as the unit's func_002742C8 (cScriptObj002742C8*), viewed with a float getter.
cScriptObjC0F0* func_002742C8_C0F0(void* self, int a1) __asm__("func_002742C8__FPvi");

extern "C" void func_0027C0F0(void* self, float* out)
{
    out[0] = *func_002742C8_C0F0(self, 0)->v04();
    out[1] = *func_002742C8_C0F0(self, 1)->v04();
    out[2] = *func_002742C8_C0F0(self, 2)->v04();
    out[3] = *func_002742C8_C0F0(self, 3)->v04();
    out[4] = *func_002742C8_C0F0(self, 4)->v04();
    out[5] = *func_002742C8_C0F0(self, 5)->v04();
    out[6] = *func_002742C8_C0F0(self, 6)->v04();
    out[7] = *func_002742C8_C0F0(self, 7)->v04();
    out[8] = *func_002742C8_C0F0(self, 8)->v04();
    out[9] = *func_002742C8_C0F0(self, 9)->v04();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C2A8__FPv);
#ifdef SKIP_ASM
int func_0027C2A8(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C2B0);
#ifdef SKIP_ASM
extern "C" void* func_002742E0(void* self);

extern "C" void* func_0027C2B0(void* self)
{
    return func_002742E0(self);
}
#endif
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C2D0);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C2D0(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C300);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cScriptObjC300 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual float* v04();
};

// Same symbol as the unit's func_002742C8 (cScriptObj002742C8*), viewed with a float getter.
cScriptObjC300* func_002742C8_C300(void* self, int a1) __asm__("func_002742C8__FPvi");

extern "C" void func_0027C300(void* self, float* out)
{
    out[0] = *func_002742C8_C300(self, 0)->v04();
    out[1] = *func_002742C8_C300(self, 1)->v04();
    out[2] = *func_002742C8_C300(self, 2)->v04();
    out[3] = *func_002742C8_C300(self, 3)->v04();
    out[4] = *func_002742C8_C300(self, 4)->v04();
    out[5] = *func_002742C8_C300(self, 5)->v04();
    out[6] = *func_002742C8_C300(self, 6)->v04();
    out[7] = *func_002742C8_C300(self, 7)->v04();
    out[8] = *func_002742C8_C300(self, 8)->v04();
    out[9] = *func_002742C8_C300(self, 9)->v04();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C4B8__FPv);
#ifdef SKIP_ASM
int func_0027C4B8(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C4C0);
#ifdef SKIP_ASM
extern "C" void* func_002742E0(void* self);

extern "C" void* func_0027C4C0(void* self)
{
    return func_002742E0(self);
}
#endif
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C4E0);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C4E0(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C510);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cScriptObjC510 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual float* v04();
};

// Same symbol as the unit's func_002742C8 (cScriptObj002742C8*), viewed with a float getter.
cScriptObjC510* func_002742C8_C510(void* self, int a1) __asm__("func_002742C8__FPvi");

extern "C" void func_0027C510(void* self, float* out)
{
    out[0] = *func_002742C8_C510(self, 0)->v04();
    out[1] = *func_002742C8_C510(self, 1)->v04();
    out[2] = *func_002742C8_C510(self, 2)->v04();
    out[3] = *func_002742C8_C510(self, 3)->v04();
    out[4] = *func_002742C8_C510(self, 4)->v04();
    out[5] = *func_002742C8_C510(self, 5)->v04();
    out[6] = *func_002742C8_C510(self, 6)->v04();
    out[7] = *func_002742C8_C510(self, 7)->v04();
    out[8] = *func_002742C8_C510(self, 8)->v04();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C6A0__FPv);
#ifdef SKIP_ASM
int func_0027C6A0(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C6A8);
#ifdef SKIP_ASM
extern "C" void* func_002742E0(void* self);

extern "C" void* func_0027C6A8(void* self)
{
    return func_002742E0(self);
}
#endif
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C6C8);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C6C8(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C6F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cScriptObjC6F8 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual float* v04();
};

// Same symbol as the unit's func_002742C8 (cScriptObj002742C8*), viewed with a float getter.
cScriptObjC6F8* func_002742C8_C6F8(void* self, int a1) __asm__("func_002742C8__FPvi");

extern "C" void func_0027C6F8(void* self, float* out)
{
    out[0] = *func_002742C8_C6F8(self, 0)->v04();
    out[1] = *func_002742C8_C6F8(self, 1)->v04();
    out[2] = *func_002742C8_C6F8(self, 2)->v04();
    out[3] = *func_002742C8_C6F8(self, 3)->v04();
    out[4] = *func_002742C8_C6F8(self, 4)->v04();
    out[5] = *func_002742C8_C6F8(self, 5)->v04();
    out[6] = *func_002742C8_C6F8(self, 6)->v04();
    out[7] = *func_002742C8_C6F8(self, 7)->v04();
    out[8] = *func_002742C8_C6F8(self, 8)->v04();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C888__FPv);
#ifdef SKIP_ASM
int func_0027C888(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_0027C890);
//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C8B0);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C8B0(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C8E0);
#ifdef SKIP_ASM
class cScriptObj002742C8 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int* v04();
    virtual int v05();
};

cScriptObj002742C8* func_002742C8(void* self, int a1);

extern "C" void func_0027C8E0(void* self, int* out)
{
    out[0] = *func_002742C8(self, 0)->v04();
    out[1] = func_002742C8(self, 0)->v05();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C958__FPv);
#ifdef SKIP_ASM
int func_0027C958(void* self)
{
    return *(int*)((char*)self + 0x20);
}
#endif

extern "C" void* func_002742E0(void* self);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C960__FPv);
#ifdef SKIP_ASM
void* func_0027C960(void* self)
{
    return func_002742E0(self);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C980);
#ifdef SKIP_ASM
extern "C" void func_00274318(int, int);
extern "C" int func_00274D90();

extern "C" void func_0027C980(void* self, void* arg1, int arg2) {
    func_00274318(func_00274D90(), arg2);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027C9B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cScriptObjC9B0 {
public:
    int unk_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual float* v04();
};

cScriptObj002742C8* func_002742C8(void* self, int a1);
// Same symbol as the unit's func_002742C8 (cScriptObj002742C8*), viewed with a float getter.
cScriptObjC9B0* func_002742C8_C9B0(void* self, int a1) __asm__("func_002742C8__FPvi");

extern "C" void func_0027C9B0(void* self, void* out)
{
    ((int*)out)[0] = *func_002742C8(self, 0)->v04();
    ((int*)out)[1] = func_002742C8(self, 0)->v05();
    ((int*)out)[2] = *func_002742C8(self, 1)->v04();
    ((int*)out)[3] = func_002742C8(self, 1)->v05();
    ((int*)out)[4] = *func_002742C8(self, 2)->v04();
    ((int*)out)[5] = func_002742C8(self, 2)->v05();
    ((float*)out)[6] = *func_002742C8_C9B0(self, 3)->v04();
    ((float*)out)[7] = *func_002742C8_C9B0(self, 4)->v04();
    ((float*)out)[8] = *func_002742C8_C9B0(self, 5)->v04();
    ((float*)out)[9] = *func_002742C8_C9B0(self, 6)->v04();
    ((float*)out)[10] = *func_002742C8_C9B0(self, 7)->v04();
    ((float*)out)[11] = *func_002742C8_C9B0(self, 8)->v04();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CBB0);
#ifdef SKIP_ASM
cScriptObj002742C8* func_002742C8(void* self, int a1);

extern "C" void func_0027CBB0(void* self, void* out)
{
    ((int*)out)[0] = *func_002742C8(self, 0)->v04();
    ((int*)out)[1] = func_002742C8(self, 0)->v05();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CC28);
#ifdef SKIP_ASM
cScriptObj002742C8* func_002742C8(void* self, int a1);

extern "C" void func_0027CC28(void* self, void* out)
{
    ((int*)out)[0] = *func_002742C8(self, 0)->v04();
    ((int*)out)[1] = func_002742C8(self, 0)->v05();
    ((int*)out)[2] = *func_002742C8(self, 1)->v04();
    ((int*)out)[3] = func_002742C8(self, 1)->v05();
    ((int*)out)[4] = *func_002742C8(self, 2)->v04();
    ((int*)out)[5] = func_002742C8(self, 2)->v05();
    ((int*)out)[6] = *func_002742C8(self, 3)->v04();
    ((int*)out)[7] = func_002742C8(self, 3)->v05();
    ((int*)out)[8] = *func_002742C8(self, 4)->v04();
    ((int*)out)[9] = func_002742C8(self, 4)->v05();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CDD0);
#ifdef SKIP_ASM
struct sScrSlot_CDD0 {
    int a;  // 0x0
    int b;  // 0x4
    int c;  // 0x8
    int d;  // 0xC
    int e;  // 0x10
};

struct sScrEngine_CDD0 {
    int vars[20];               // 0x0
    sScrSlot_CDD0 slots[30];    // 0x50
    void* vtbl;                 // 0x2A8
};

extern char D_00482528[];
extern void* D_004A34DC;

extern "C" void* func_0027CDD0(void* self_)
{
    sScrEngine_CDD0* self = (sScrEngine_CDD0*)self_;
    int i;
    self->vtbl = D_00482528;
    D_004A34DC = self;
    for (i = 19; i >= 0; i--) {
        self->vars[i] = 0;
    }
    for (i = 0; i < 30; i++) {
        self->slots[i].a = 0;
        self->slots[i].b = -1;
        self->slots[i].c = -1;
        self->slots[i].d = 0;
        self->slots[i].e = -1;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CE58);
#ifdef SKIP_ASM
extern "C" void func_0027D050(void* self);
void operator_delete(int*);
extern char D_00482528[];
extern void* D_004A34DC;

extern "C" void func_0027CE58(void* self, int flags)
{
    *(void**)((char*)self + 0x2A8) = D_00482528;
    func_0027D050(self);
    D_004A34DC = 0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CEA8);
#ifdef SKIP_ASM
extern "C" int func_0027D330(void* self, int idx, void* item);

class cScriptOwnerCEA8 {
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

struct sScrOwnersCEA8 {
    cScriptOwnerCEA8* owners[20];
};

extern "C" int func_0027CEA8(void* engine, void* o)
{
    sScrOwnersCEA8* self = (sScrOwnersCEA8*)engine;
    cScriptOwnerCEA8* obj = (cScriptOwnerCEA8*)o;
    int i;
    for (i = 0; i < 20; i++) {
        if (self->owners[i] == 0) {
            self->owners[i] = obj;
            break;
        }
    }
    int k = 0;
    int n = obj->v06();
    for (; k < n; k++) {
        func_0027D330(self, i, obj->v07(k));
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027CF88);
#ifdef SKIP_ASM
extern "C" int func_0027D390(void* self, void* msg);

class cScriptOwnerCF88 {
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

extern "C" int func_0027CF88(void* self, int idx)
{
    cScriptOwnerCF88* obj = *(cScriptOwnerCF88**)((char*)self + (idx << 2));
    if (obj == 0) return 0;
    int k = 0;
    int n = obj->v06();
    for (; k < n; k++) {
        func_0027D390(self, obj->v07(k));
    }
    *(cScriptOwnerCF88**)((char*)self + (idx << 2)) = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D050);
#ifdef SKIP_ASM
struct sVEntry0027D050 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_0027D050(void* self)
{
    int i;
    for (i = 0; i < 20; i++) {
        if (((int*)self)[i] != 0) {
            sVEntry0027D050* vt = *(sVEntry0027D050**)((char*)self + 0x2A8);
            vt[3].fn((char*)self + vt[3].delta, i);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D0C0);
#ifdef SKIP_ASM
extern "C" void func_0027D540(void* self, void* a1, int a2);

class cScriptOwnerD0C0 {
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

extern "C" void func_0027D0C0(void* self, int idx, int val)
{
    cScriptOwnerD0C0* obj = *(cScriptOwnerD0C0**)((char*)self + (idx << 2));
    int i = 0;
    int n = obj->v06();
    for (; i < n; i++) {
        func_0027D540(self, obj->v07(i), val);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D170);
#ifdef SKIP_ASM
class cScriptOwnerD170 {
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

extern "C" void func_0027D558(void* self, void* a1);

extern "C" void func_0027D170(void* self, int idx)
{
    cScriptOwnerD170* obj = *(cScriptOwnerD170**)((char*)self + (idx << 2));
    int i = 0;
    int n = obj->v06();
    for (; i < n; i++) {
        func_0027D558(self, obj->v07(i));
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D210);
#ifdef SKIP_ASM
extern "C" int func_0027D2C8(void* self, int i, int val);

class cScriptOwnerD210 {
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
    virtual int* v07(int i);
};

// PORT: func_00279E50 declares func_0027D210 as void; it really returns 0/1.
int func_0027D210_impl(void* self, int idx, int val) __asm__("func_0027D210");

int func_0027D210_impl(void* self, int idx, int val)
{
    cScriptOwnerD210* obj = *(cScriptOwnerD210**)((char*)self + (idx << 2));
    int i = 0;
    int n = obj->v06();
    for (; i < n; i++) {
        if (func_0027D2C8(self, obj->v07(i)[1], val)) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D2C8);
#ifdef SKIP_ASM
extern "C" int func_0027D2C8(void* self, int i, int val)
{
    char* p = (char*)self + i * 0x14;
    return *(int*)(p + 0x58) == val;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D2E8);
#ifdef SKIP_ASM
extern void* D_004A34DC;

extern "C" void* func_0027D2E8()
{
    return D_004A34DC;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D2F0);
#ifdef SKIP_ASM
struct sVar0050 {
    int a;
    int b;
    int value;
    int type;
    int e;
};

struct sScriptEng0050 {
    char pad[0x50];
    sVar0050 vars[1];
};

extern "C" int func_0027D2F0(sScriptEng0050* self, void* a1)
{
    sVar0050* v = &self->vars[*(int*)((char*)a1 + 0x4)];
    if (v->type != 1) {
        return -1;
    }
    return v->value;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D320__FPvi);
#ifdef SKIP_ASM
int func_0027D320(void* self, int i)
{
    return *(int*)((char*)self + (i << 2));
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_0027D330);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D390);
#ifdef SKIP_ASM
extern "C" void func_00282F90(void* self);

struct sScrEnt27D390 {
    int* obj;
    int a;
    int b;
    int state;
    int c;
};

extern "C" int func_0027D390(void* self, void* msg)
{
    sScrEnt27D390* e = (sScrEnt27D390*)((char*)self + (*(int*)((char*)msg + 0x4) * 0x14 + 0x50));
    if (e->state == 1) {
        func_00282F90(msg);
    }
    e->obj[1] = -1;
    e->a = -1;
    e->obj = 0;
    e->b = -1;
    e->state = 0;
    e->c = -1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D400);
#ifdef SKIP_ASM
struct sScrVEntryD400 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

struct sScrVEntryD400b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sScrSlotD400 {
    int field_0x0;
    int id;         // 0x4
    int value;      // 0x8
    int set;        // 0xC
    int field_0x10;
};

struct sScrOwnerD400 {
    void* objs[0x14];           // 0x0
    sScrSlotD400 slots[1];      // 0x50
};

extern "C" void func_0027D400(sScrOwnerD400* self, int* key, int value)
{
    sScrVEntryD400* vt = *(sScrVEntryD400**)((char*)self + 0x2A8);
    sScrSlotD400* s = &self->slots[key[1]];
    if (vt[4].fn((char*)self + vt[4].delta, s->id, value) == 0) {
        char* obj = (char*)self->objs[s->id];
        sScrVEntryD400b* vt2 = *(sScrVEntryD400b**)(obj + 0xC);
        vt2[4].fn(obj + vt2[4].delta, value);
    }
    s->value = value;
    s->set = 1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D4A0);
#ifdef SKIP_ASM
struct sScrVEntryD4A0 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

struct sScrVEntryD4A0b {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sScrSlotD4A0 {
    int field_0x0;
    int id;         // 0x4
    int value;      // 0x8
    int set;        // 0xC
    int field_0x10;
};

struct sScrOwnerD4A0 {
    void* objs[0x14];           // 0x0
    sScrSlotD4A0 slots[1];      // 0x50
};

extern "C" void func_0027D4A0(sScrOwnerD4A0* self, int* key)
{
    sScrSlotD4A0* s = &self->slots[key[1]];
    int old = s->value;
    s->value = -1;
    s->set = 0;
    sScrVEntryD4A0* vt = *(sScrVEntryD4A0**)((char*)self + 0x2A8);
    if (vt[4].fn((char*)self + vt[4].delta, s->id, old) == 0) {
        char* obj = (char*)self->objs[s->id];
        sScrVEntryD4A0b* vt2 = *(sScrVEntryD4A0b**)(obj + 0xC);
        vt2[5].fn(obj + vt2[5].delta, old);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D540);
#ifdef SKIP_ASM
extern "C" void func_0027D540(void* self, void* a1, int a2)
{
    int i = *(int*)((char*)a1 + 0x4);
    char* p = (char*)self + i * 0x14;
    *(int*)(p + 0x60) = a2;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D558);
#ifdef SKIP_ASM
extern "C" void func_0027D558(void* self, void* a1)
{
    int i = *(int*)((char*)a1 + 0x4);
    char* p = (char*)self + i * 0x14;
    *(int*)(p + 0x60) = -1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D578);
#ifdef SKIP_ASM
extern "C" int func_0027D578(sScriptEng0050* self, int key, int* out, int max)
{
    int n = 0;
    int i = 0;
    sVar0050* v = self->vars;
    while (i < 30 && n != max) {
        if (v->a != 0 && v->type != 1 && (v->e < 0 || v->e == key)) {
            *out++ = v->a;
            n++;
        }
        i++;
        if (i < 30) v = &self->vars[i];
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D5E8);
#ifdef SKIP_ASM
void* func_00283200(void*, int);
extern char D_004820B8[];
extern char D_004FF1A0[];

// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy of D_004FF1A0, likely identity);
// the PC port needs a plain 64-byte copy.
extern "C" void* func_0027D5E8(void* self, int a1)
{
    func_00283200(self, 1);
    *(void**)((char*)self + 0xC) = D_004820B8;
    *(int*)((char*)self + 0x20) = -1;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x30), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x7C) = a1;
    *(int*)((char*)self + 0x70) = 0;
    *(int*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x78) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D680__FPvi);
#ifdef SKIP_ASM
void func_0027D680(void* self, int val)
{
    *(int*)((char*)self + 0x10) = val;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D688);
#ifdef SKIP_ASM
extern char D_004FF1A0[];

struct sSeVEntryD688 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy of D_004FF1A0, likely identity);
// the PC port needs a plain 64-byte copy.
extern "C" void func_0027D688(char* self, void* anim)
{
    if (anim != 0) {
        int id = func_0027D2F0((sScriptEng0050*)func_0027D2E8(), anim);
        if (*(void**)(self + 0x14) != 0) {
            sSeVEntryD688* vt = *(sSeVEntryD688**)(self + 0xC);
            vt[5].fn(self + vt[5].delta, *(int*)(self + 0x20));
        }
        *(void**)(self + 0x14) = anim;
        *(int*)(self + 0x20) = id;
        sSeVEntryD688* vt = *(sSeVEntryD688**)(self + 0xC);
        vt[4].fn(self + vt[4].delta, id);
    } else if (*(void**)(self + 0x14) != 0) {
        __asm__ __volatile__(
            ".set noreorder\n"
            "lqc2      $vf1, 0x0(%1)\n"
            "lqc2      $vf2, 0x10(%1)\n"
            "lqc2      $vf3, 0x20(%1)\n"
            "lqc2      $vf4, 0x30(%1)\n"
            "sqc2      $vf1, 0x0(%0)\n"
            "sqc2      $vf2, 0x10(%0)\n"
            "sqc2      $vf3, 0x20(%0)\n"
            "sqc2      $vf4, 0x30(%0)\n"
            ".set reorder\n"
            :
            : "r"(self + 0x30), "r"(D_004FF1A0)
            : "memory");
        *(int*)(self + 0x70) = 0;
        *(int*)(self + 0x74) = 0;
        *(int*)(self + 0x78) = 0;
        sSeVEntryD688* vt = *(sSeVEntryD688**)(self + 0xC);
        vt[5].fn(self + vt[5].delta, *(int*)(self + 0x20));
        *(void**)(self + 0x14) = 0;
        *(int*)(self + 0x20) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D788__FPvf);
#ifdef SKIP_ASM
void func_0027D788(void* self, float val)
{
    *(float*)((char*)self + 0x18) = val;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D790);
#ifdef SKIP_ASM
extern "C" void* func_0027D2E8(void);
extern "C" int func_0027D2C8(void* self, int i, int val);

extern "C" int func_0027D790(void* self, int val)
{
    if (*(void**)((char*)self + 0x14) == 0) {
        return 0;
    }
    return func_0027D2C8(func_0027D2E8(), *(int*)(*(char**)((char*)self + 0x14) + 0x4), val);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D7F0);
#ifdef SKIP_ASM
class cSsxScriptVirt {
public:
    int field_0x0;
    int field_0x4;
    int field_0x8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
};

extern "C" void func_0027D7F0(void* self)
{
    (*(cSsxScriptVirt**)((char*)self + 0x10))->v02();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D820);
#ifdef SKIP_ASM
extern "C" void func_0027D820(void* self)
{
    (*(cSsxScriptVirt**)((char*)self + 0x10))->v03();
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D850);
#ifdef SKIP_ASM
void func_00283430(void* self);
extern "C" void func_0027D970(void* self, int a1);
extern "C" void cScriptCameraController_addCamera(void* ctrl, void* script);
extern "C" void func_0015DFD8(void* self, int mode);
extern char* D_004A28A8;

extern "C" void func_0027D850(void* self)
{
    func_00283430(self);
    if (*(void**)(D_004A28A8 + 0x84) != 0) {
        *(float*)((char*)self + 0x18) = 1.0f;
        func_0027D970(self, *(int*)((char*)self + 0x14));
        char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
        char* rider = *(char**)(riders + (*(int*)((char*)self + 0x7C) << 2) + 4);
        cScriptCameraController_addCamera(*(void**)(rider + 0xAC), self);
        if (*(int*)(*(char**)(rider + 0xAC) + 0x18) != 0) {
            func_0015DFD8(rider, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027D8D8);
#ifdef SKIP_ASM
void func_00283440(void*);
extern "C" void func_001692D8(void* self, void* algo);
extern "C" void func_0015DFD8(void* self, int mode);
extern "C" void* func_00162170(void* self);
extern char* D_004A28A8;

class cScrObj_D8D8 {
public:
    char pad[0x14];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

extern "C" void func_0027D8D8(void* self)
{
    func_00283440(self);
    char* g = D_004A28A8;
    if (*(void**)(g + 0x84) != 0) {
        *(int*)((char*)self + 0x18) = 0;
        char* riders = *(char**)(*(char**)(g + 0x84) + 0x84);
        char* rider = *(char**)(riders + (*(int*)((char*)self + 0x7C) << 2) + 4);
        func_001692D8(*(void**)(rider + 0xAC), self);
        if (*(int*)(*(char**)(rider + 0xAC) + 0x18) == 0) {
            func_0015DFD8(rider, 2);
            func_00162170(*(void**)(rider + 0xA8));
            (*(cScrObj_D8D8**)(rider + 0xA0))->v4();
        }
    }
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_0027D970);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_0027F968);
#ifdef SKIP_ASM
void func_00282F60(void*);
void* func_00283200(void*, int);
extern char D_00481FD8[];
extern char D_00482018[];
extern char D_004FF1A0[];

// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy of D_004FF1A0, likely identity);
// the PC port needs a plain 64-byte copy.
extern "C" void* func_0027F968(void* self)
{
    func_00282F60(self);
    func_00283200((char*)self + 0xC, 3);
    *(void**)((char*)self + 0x18) = D_00482018;
    *(void**)((char*)self + 0x0) = D_00481FD8;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x20) = 0;
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x30), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x70) = 0;
    *(int*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x78) = 0;
    return self;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_0027F9F8);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002803F0);
#ifdef SKIP_ASM
void func_00283440(void*);
extern char D_004FF1A0[];

// PORT: PS2-only VU0 inline asm (lqc2/sqc2 matrix copy of D_004FF1A0, likely identity);
// the PC port needs a plain 64-byte copy.
extern "C" void func_002803F0(void* self)
{
    func_00283440((char*)self + 0xC);
    __asm__ __volatile__(
        ".set noreorder\n"
        "lqc2      $vf1, 0x0(%1)\n"
        "lqc2      $vf2, 0x10(%1)\n"
        "lqc2      $vf3, 0x20(%1)\n"
        "lqc2      $vf4, 0x30(%1)\n"
        "sqc2      $vf1, 0x0(%0)\n"
        "sqc2      $vf2, 0x10(%0)\n"
        "sqc2      $vf3, 0x20(%0)\n"
        "sqc2      $vf4, 0x30(%0)\n"
        ".set reorder\n"
        :
        : "r"((char*)self + 0x30), "r"(D_004FF1A0)
        : "memory");
    *(int*)((char*)self + 0x70) = 0;
    *(int*)((char*)self + 0x74) = 0;
    *(int*)((char*)self + 0x78) = 0;
    *(int*)((char*)self + 0x1C) = 0;
    *(int*)((char*)self + 0x20) = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00280458);
#ifdef SKIP_ASM
extern "C" int func_0011D640(void* self);
extern "C" int func_00123128(void* self);
extern "C" int func_00280560(void* self, void* rider, int id, int a3);
extern int D_00481BB0[];

class cScriptCtx0458 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void* v06();
};

extern "C" int func_00280458(cScriptCtx0458* self, void* msg, int type)
{
    if (type != 5) return 0;
    void* rider = self->v06();
    if (func_0011D640(rider) == 0) return 0;
    int team = func_00123128(rider);
    int mask = D_00481BB0[team];
    // PORT: func_0027C958 returns a record pointer as int
    char* info = (char*)func_0027C958(msg);
    short m = *(short*)(info + 2);
    if (m == 0 || (m & mask) != 0) {
        return func_00280560(self, rider, *(signed char*)info, *(int*)((char*)msg + 0x8));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00280520__FPviT0T0);
#ifdef SKIP_ASM
void func_00280520(void* self, int a1, void* a2, void* a3)
{
    *(int*)a3 = *(int*)((char*)*(void**)((char*)self + 0x1c) + 0x4);
    *(int*)a2 = (*(int**)((char*)*(void**)((char*)self + 0x1c) + 0x10))[a1];
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00280548__FPviT0T0);
#ifdef SKIP_ASM
void func_00280548(void* self, int a1, void* a2, void* a3)
{
    *(int*)a3 = *(int*)((char*)*(void**)((char*)self + 0x20) + 0x4);
    *(int*)a2 = a1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_00280560);
#ifdef SKIP_ASM
extern "C" void* func_00279F18(void* self, int i, int a2);
extern void* D_004A28A4;

extern "C" int func_00280560(void* self, void* rider, int id, int a3)
{
    if (id != 0) {
        if (id >= 0) {
            if (id < 0x16) {
                return func_00279F18(D_004A28A4, id - 1, a3) == rider;
            }
        }
    } else {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002805B8);
#ifdef SKIP_ASM
void func_00282F60(void*);
void* func_00283200(void*, int);
extern void* D_00482298[];
extern void* D_00482260[];

struct sScrTrig05B8 {
    int id;         // 0x0
    int count;      // 0x4
    int target;     // 0x8
};

struct sScrObj05B8 {
    char pad_0x00[0xBC];
    sScrTrig05B8 trig[4];   // 0xBC
    int field_0xEC;
    int field_0xF0;
    int field_0xF4;
    int field_0xF8;
};

extern "C" void* func_002805B8(sScrObj05B8* self)
{
    func_00282F60(self);
    func_00283200((char*)self + 0xC, 5);
    *(void***)((char*)self + 0x18) = D_00482298;
    *(void***)self = D_00482260;
    self->field_0xEC = 0;
    self->field_0xF0 = 0;
    self->field_0xF4 = 0;
    self->field_0xF8 = 0;
    for (int i = 0; i < 4; i++) {
        sScrTrig05B8* t = &self->trig[i];
        t->target = -1;
        t->id = -1;
        t->count = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00280640);
#ifdef SKIP_ASM
extern void* D_004A28A4;
extern "C" void func_002AD5F0(void* bank, int id, int a, float f);
extern "C" int func_002AD550(void* bank, int id, int a);
extern "C" int func_002B0E28(void* p, int i);

extern "C" void func_00280640(sScrObj05B8* self)
{
    char* snd = (char*)func_0028B180();
    for (int i = 0; i < 4; i++) {
        sScrTrig05B8* t = &self->trig[i];
        if (t->id >= 0) {
            if (t->count != 0) {
                func_002AD5F0(**(char***)(snd + 0x118) + 0x1D8, t->id, 1, 0.0f);
                t->target = -1;
                t->id = -1;
                t->count = 0;
            } else if (func_002AD550(**(char***)(snd + 0x118) + 0x1D8, t->id, 1) == 0) {
                t->target = -1;
                t->id = -1;
                t->count = 0;
            }
        }
    }
    if (self->field_0xF4 != 0) {
        self->field_0xF4 = 0;
        if (func_002B0E28(snd + 0x5560, 0) != 0) {
            func_00279070(D_004A28A4, *(int*)((char*)D_004A28A4 + 0x550), 1, 1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00280730);
#ifdef SKIP_ASM
void func_00283430(void* self);
// PORT: func_00279EF8 is declared (void*) but forwards a key in $5.
void* func_00279EF8_2(void* self, int key) __asm__("func_00279EF8__FPv");
extern void* D_004A28A4;

struct sScrTrig_0730 {
    int a;  // 0x0
    int b;  // 0x4
    int c;  // 0x8
};

extern "C" void func_00280730(void* self)
{
    int i;
    func_00283430((char*)self + 0xC);
    *(int*)((char*)self + 0xEC) = 0;
    *(int*)((char*)self + 0xF0) = 0;
    *(int*)((char*)self + 0xF4) = 0;
    // PORT: func_0027C070 returns a pointer as int
    char* info = (char*)func_0027C070(*(void**)(*(char**)((char*)self + 0x8) + 0x8));
    int key = *(int*)(info + 0x1C);
    *(void**)((char*)self + 0xF8) = func_00279EF8_2(D_004A28A4, key);
    sScrTrig_0730* t = (sScrTrig_0730*)((char*)self + 0xBC);
    for (i = 3; i >= 0; i--) {
        t->c = -1;
        t->a = -1;
        t->b = 0;
        t++;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_002807B0);
#ifdef SKIP_ASM
void func_00283440(void*);
extern "C" void* func_0028B180();
void func_002A1BD0(void* p);
extern "C" void func_002AD5F0(void* bank, int id, int a, float f);
extern "C" void func_00309E50(void* mgr, int a, int b);
extern "C" void func_0027CC28(void* self, void* out);
extern void* D_004A3DD8;
extern int D_004A3B60;

struct sSePair07B0 {
    int a;
    int b;
};

struct sSeSound07B0 {
    int id;
    int field_0x4;
    int field_0x8;
};

struct sSeInfo07B0 {
    int v[9];
    int active;     // 0x24
    int pad[2];
};

struct sSeEngine07B0 {
    char pad_0x0[0x8];
    void* owner;                // 0x8
    char pad_0xC[0x10];
    sSePair07B0 pairs[(0xBC - 0x1C) / 8];   // 0x1C
    sSeSound07B0 sounds[4];     // 0xBC
    int pairCount;              // 0xEC
    int field_0xF0;             // 0xF0
    int field_0xF4;             // 0xF4
    int field_0xF8;             // 0xF8
};

extern "C" void func_002807B0(sSeEngine07B0* self)
{
    sSeInfo07B0 info;
    func_00283440((char*)self + 0xC);
    for (int i = 0; i < self->pairCount; i++) {
        func_00309E50(D_004A3DD8, self->pairs[i].b, self->pairs[i].a);
    }
    if (self->field_0xF0 != 0) {
        func_002A1BD0(func_0028B180());
    }
    for (int i = 0; i < 4; i++) {
        int id = self->sounds[i].id;
        if (id >= 0) {
            func_002AD5F0(*(char**)*(char**)((char*)func_0028B180() + 0x118) + 0x1D8, id, 1, 0.0f);
        }
        sSeSound07B0* s = &self->sounds[i];
        s->field_0x8 = -1;
        s->id = -1;
        s->field_0x4 = 0;
    }
    func_0027CC28(self->owner, &info);
    if (info.active != 0) {
        D_004A3B60 = 0;
    }
    self->pairCount = 0;
    self->field_0xF0 = 0;
    self->field_0xF4 = 0;
    self->field_0xF8 = 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002808D8);
#ifdef SKIP_ASM
extern "C" int func_002808D8(void* self, void* a1, int a2)
{
    return a2 == 7;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_002808E8);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281000__FPviT0T0);
#ifdef SKIP_ASM
void func_00281000(void* self, int a1, void* a2, void* a3)
{
    *(int*)a3 = *(int*)((char*)*(void**)((char*)self + 0xf8) + 0x4);
    *(int*)a2 = a1;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_00281018);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281100);
#ifdef SKIP_ASM
extern "C" void func_00281AC8(void* self, int a1, int a2);
extern char* D_004A28A8;

struct sVec4_1100 {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern "C" void func_00281100(void* self)
{
    if (*(int*)((char*)self + 0x8) > 0) {
        char* riders = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x84);
        char* rider = *(char**)(riders + (*(int*)((char*)self + 0xF8) << 2) + 4);
        *(sVec4_1100*)((char*)self + 0x100) = *(sVec4_1100*)(rider + 0x20);
        if (*(int*)((char*)self + 0x18) == 0) {
            func_00281AC8(self, 0, 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281160__FPvi);
#ifdef SKIP_ASM
void func_00281160(void* self, int val)
{
    *(int*)((char*)self + 0xF8) = val;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281168__FPv);
#ifdef SKIP_ASM
int func_00281168(void* self)
{
    return 0xA;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281170);
#ifdef SKIP_ASM
extern "C" void* func_00281170(void* self, int a1)
{
    if (a1 == 0) {
        return (char*)self + 0x10;
    }
    return (char*)self + (a1 * 0x14 + 0x8);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/ssxscriptengine", func_00281190);
#ifdef SKIP_ASM
void func_0027D680(void* self, int val);

extern "C" int func_00281190(void* self, void* obj)
{
    void** slots = (void**)((char*)self + 0xD0);
    for (int i = 0; i < 2; i++) {
        if (slots[i] == 0) {
            slots[i] = obj;
            func_0027D680(obj, (int)self); // PORT: pointer passed as int (callee mangled __FPvi)
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002811E8);
#ifdef SKIP_ASM
void func_0027D680(void* self, int val);
extern "C" void func_0027D688(char* self, void* anim);

struct sSeEng11E8 {
    char pad_0x0[0x8];
    int count;              // 0x8
    char pad_0xC[0xC4];
    char* objs[2];          // 0xD0
    char pad_0xD8[0x4];
    int slots[2];           // 0xDC
};

// PORT: the unit declares func_002811E8(void*, void*) returning void; it returns found/not found.
extern "C" int func_002811E8_impl(sSeEng11E8* self, char* key) __asm__("func_002811E8");
extern "C" int func_002811E8_impl(sSeEng11E8* self, char* key)
{
    int k = *(int*)(key + 4);
    for (int i = 0; i < 2; i++) {
        char* o = self->objs[i];
        if (o != 0 && *(int*)(o + 4) == k) {
            if (self->count > 0 && *(int*)(o + 0x14) != 0) {
                func_0027D688(o, 0);
                for (int j = 0; j < 2; j++) {
                    if (self->slots[j] == i) {
                        self->slots[j] = -1;
                        break;
                    }
                }
            }
            func_0027D680(self->objs[i], 0);
            self->objs[i] = 0;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002812E0);
#ifdef SKIP_ASM
// PORT: func_00282DB0 forwards four float args in $f12..$f15 (declared (void*, int, int)
// in bxscriptengine); func_00282DA8 stores an owner pointer in an int field. Both bound
// by asm label with the real argument types.
void* func_00282DB0_f(void* self, int a1, int a2, float f0, float f1, float f2, float f3)
    __asm__("func_00282DB0__FPvii");
void func_00282DA8_p(void* self, void* owner) __asm__("func_00282DA8__FPvi");

extern "C" int func_002812E0(void* self, void* obj)
{
    if (obj == 0) {
        char* cur = *(char**)((char*)self + 0xD8);
        if (*(int*)(cur + 0x8) > 0) {
            func_00282DB0_f(cur, -1, 9, 0.0f, 0.0f, 0.0f, 0.0f);
            *(int*)((char*)self + 0xE8) = 0;
        }
        func_00282DA8_p(*(void**)((char*)self + 0xD8), 0);
        *(void**)((char*)self + 0xD8) = 0;
        return 1;
    }
    if (*(void**)((char*)self + 0xD8) != 0) {
        return 0;
    }
    *(void**)((char*)self + 0xD8) = obj;
    func_00282DA8_p(obj, self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281370);
#ifdef SKIP_ASM
extern "C" void* func_0027D2E8(void);
extern "C" void func_00281A50(void* self);
extern "C" void func_001033B0(void* self, void* pos);
// PORT: these two are declared (void*) but called with a second argument.
void* func_00282C18_2(void* self, int idx) __asm__("func_00282C18__FPv");
void func_00283430_2(void* self, int val) __asm__("func_00283430__FPv");
extern void* D_004A28A4;
extern char* D_004A28A8;

extern "C" void func_00281370(void* self, int val)
{
    func_0027D0C0(func_0027D2E8(), *(int*)((char*)self + 0x4), val);
    func_00281A50(self);
    // PORT: pointer passed as int
    if (func_00279370(D_004A28A4, (int)func_00282C18_2(D_004A28A4, val)) != 0) {
        func_001033B0(*(void**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + 0xA4), (char*)self + 0x100);
        *(int*)((char*)self + 0x110) = 1;
    }
    func_00283430_2(self, val);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281400);
#ifdef SKIP_ASM
extern char* D_004A28A8;
extern "C" void* func_0027D2E8(void);
extern "C" void func_0027D170(void* mgr, int id);
extern "C" void func_0027D688(char* self, void* anim);
extern "C" void func_00281A50(void* self);
extern "C" void func_001033F8(void* a, void* b, void* c);
// PORT: func_00282DB0's mangled signature is (void*, int, int); it also takes four floats (same alias as func_002812E0).
void* func_00282DB0_f(void* self, int a1, int a2, float f0, float f1, float f2, float f3)
    __asm__("func_00282DB0__FPvii");
// PORT: the unit declares func_00283440(void*); this caller passes a second argument.
void func_00283440_2(void* self, int a1) __asm__("func_00283440__FPv");

struct sSeEng1400 {
    char pad_0x0[0x4];
    int id;                 // 0x4
    char pad_0x8[0xC8];
    char* objs[2];          // 0xD0
    void* fade;             // 0xD8
    int slots[2];           // 0xDC
    char pad_0xE4[0x1C];
    char area[0x10];        // 0x100
    int pending;            // 0x110
};

extern "C" void func_00281400(sSeEng1400* self, int a1)
{
    func_0027D170(func_0027D2E8(), self->id);
    for (int i = 0; i < 2; i++) {
        int s = self->slots[i];
        if (s >= 0) {
            func_0027D688(self->objs[s], 0);
            self->slots[i] = -1;
        }
    }
    if (self->fade != 0) {
        func_00282DB0_f(self->fade, -1, 9, 0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (self->pending != 0) {
        char* lvl = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC);
        func_001033F8(*(void**)(lvl + 0xA4), self->area, lvl);
        self->pending = 0;
    }
    func_00281A50(self);
    func_00283440_2(self, a1);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002814F8);
#ifdef SKIP_ASM
extern "C" void func_0027C8E0(void* self, int* out);
// PORT: func_0027C888 is defined returning int, but it returns a pointer here; bound by asm label.
signed char* func_0027C888_p(void* self) __asm__("func_0027C888__FPv");
extern "C" void func_00281AC8(void* self, int a1, int a2);
extern "C" void func_00281C68(void* self, int* info, float t);
// PORT: func_00282DB0's mangled signature is (void*, int, int); it also takes four floats (same alias as func_002812E0).
void* func_00282DB0_f(void* self, int a1, int a2, float f0, float f1, float f2, float f3)
    __asm__("func_00282DB0__FPvii");

struct sNode_2814F8
{
    char pad0[0x4];
    int bit;
    char pad8[0xC];
    signed char* kind;
    sNode_2814F8* next;
};

extern "C" void func_002814F8(void* self, void* obj, int a2, int flags, float t)
{
    if ((flags & 0xC) == 0)
        return;
    int info[2];
    func_0027C8E0(obj, info);
    if (flags & 4)
    {
        int go = 1;
        if (*func_0027C888_p(obj) != 0)
        {
            sNode_2814F8* head = (sNode_2814F8*)info[1];
            if (info[0] >= 2 && *(int*)((char*)self + 0xF0) == 0 && *head->kind == 8)
            {
                *(int*)((char*)self + 0xEC) = go;
                go = 0;
            }
        }
        if (go)
            func_00281C68(self, info, t);
    }
    if (flags & 8)
    {
        if (info[0] == 0)
        {
            void* fade = *(void**)((char*)self + 0xD8);
            if (fade)
                func_00282DB0_f(fade, -1, 9, 0.0f, 0.0f, 0.0f, 0.0f);
            for (int i = 0; i < 2; i++)
                func_00281AC8(self, i, 9);
            return;
        }
        if (*(int*)((char*)self + 0xEC))
        {
            func_00281C68(self, info, t);
            *(int*)((char*)self + 0xEC) = 0;
        }
        int mask = 0;
        for (sNode_2814F8* n = (sNode_2814F8*)info[1]; n; n = n->next)
            mask |= 1 << n->bit;
        for (int i = 0; i < 2; i++)
        {
            if (((mask >> i) & 1) == 0)
                func_00281AC8(self, i, 9);
        }
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_002816A0);
#ifdef SKIP_ASM
extern "C" void func_0027C8E0(void* self, int* out);
// PORT: func_0027C888 is defined returning int, but it returns a pointer here; bound by asm label.
signed char* func_0027C888_p(void* self) __asm__("func_0027C888__FPv");
void func_0027D788(void* self, float val);
extern "C" int func_00281C40(void* self, int i);
extern "C" void func_00281C68(void* self, int* info, float t);
extern "C" void func_00282D30(void* self, float dt);
extern "C" void* func_0028B180();
extern "C" float func_002B4920(void* p);

struct sNode_2816A0
{
    char pad0[0x4];
    int side;           // 0x4
    int start;          // 0x8
    char padC[0x4];
    unsigned int len;   // 0x10
    signed char* kind;  // 0x14
};

extern "C" void func_002816A0(char* self, void* obj, float t, float dt)
{
    int info[2];
    func_0027C8E0(obj, info);
    if (*func_0027C888_p(obj) != 0) {
        *(int*)(self + 0xF0) = 0;
        char* p = (char*)func_0028B180();
        void* timer = p + 0x118;
        if (*(int*)(p + 0x530) != 0) {
            float now = func_002B4920(timer);
            if (*(float*)(self + 0xF4) < now) {
                *(int*)(self + 0xF0) = 1;
                if (*(int*)(self + 0xEC) != 0) {
                    func_00281C68(self, info, t);
                    *(int*)(self + 0xEC) = 0;
                }
            }
            *(float*)(self + 0xF4) = now;
        } else {
            *(int*)(self + 0xF0) = 1;
        }
    }
    if (info[0] == 0) {
        return;
    }
    if (*(int*)(self + 0xE8) == 0) {
        return;
    }
    // PORT: info[1] holds a node pointer
    sNode_2816A0* n = (sNode_2816A0*)info[1];
    switch (*n->kind) {
    case 0: {
        if ((float)(n->len + n->start) < t) {
            *(int*)(self + 0xE8) = 0;
        }
        int a = func_00281C40(self, n->side);
        int b = func_00281C40(self, 1 - n->side);
        if (b == 0) {
            *(int*)(self + 0xE8) = 0;
            break;
        }
        float w = 1.0f;
        if ((float)(n->len + n->start) < t) {
            *(int*)(self + 0xE8) = 0;
        } else {
            w = (t - (float)n->start) / (float)n->len;
        }
        func_0027D788((void*)a, w);
        func_0027D788((void*)b, 1.0f - w);
        break;
    }
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: {
        int a = func_00281C40(self, n->side);
        int b = func_00281C40(self, 1 - n->side);
        func_00282D30(*(void**)(self + 0xD8), dt);
        if (*(int*)(*(char**)(self + 0xD8) + 8) <= 0) {
            *(int*)(self + 0xE8) = 0;
        }
        if (*(int*)(self + 0xE8) != 0 && b != 0 && t < (float)(n->len + n->start)) {
            func_0027D788((void*)b, 1.0f);
            func_0027D788((void*)a, 0.0f);
        } else {
            if (b != 0) {
                func_0027D788((void*)b, 0.0f);
            }
            func_0027D788((void*)a, 1.0f);
        }
        break;
    }
    case 7:
        func_00282D30(*(void**)(self + 0xD8), dt);
        if (*(int*)(*(char**)(self + 0xD8) + 8) <= 0) {
            *(int*)(self + 0xE8) = 0;
        }
        break;
    case 8:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281A00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* func_0027A668_2(void* self, int idx) __asm__("func_0027A668__FPv");
extern void* D_004A28A4;

extern "C" int func_00281A00(void* self, void* arg, int n)
{
    if (n != 4) {
        return 0;
    }
    return *(int*)((char*)func_0027A668_2(D_004A28A4, *(int*)((char*)arg + 0x8)) + 0xC) ==
           *(int*)((char*)self + 0xF8);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281A50);
#ifdef SKIP_ASM
struct sVec4_1A50 {
    float x, y, z, w;
    sVec4_1A50(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
} __attribute__((aligned(16)));

extern "C" void func_00281A50(void* self)
{
    int i;
    int v = -1;
    int* ids = (int*)((char*)self + 0xDC);
    for (i = 1; i >= 0; i--) {
        ids[i] = v;
    }
    *(int*)((char*)self + 0xF0) = 1;
    *(float*)((char*)self + 0xF4) = 1000000000.0f;
    *(sVec4_1A50*)((char*)self + 0x100) = sVec4_1A50(0.0f, 0.0f, 0.0f, 1.0f);
    *(int*)((char*)self + 0xE4) = 0;
    *(int*)((char*)self + 0xE8) = 0;
    *(int*)((char*)self + 0xEC) = 0;
    *(int*)((char*)self + 0x110) = 0;
}
#endif

INCLUDE_ASM("scripter/ssxscriptengine", func_00281AC8);

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281C40);
#ifdef SKIP_ASM
extern "C" int func_00281C40(void* self, int i)
{
    int j = *(int*)((char*)self + (i << 2) + 0xdc);
    if (j < 0) {
        return 0;
    }
    return *(int*)((char*)self + (j << 2) + 0xd0);
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281C68);
#ifdef SKIP_ASM
extern "C" void* func_0027D2E8(void);
extern "C" int func_0027D2F0(sScriptEng0050* self, void* a1);
void func_0027D788(void* self, float val);
extern "C" void func_00281AC8(void* self, int a1, int a2);
// PORT: func_00281C40 is defined returning int, but it returns a pointer here; bound by asm label.
extern "C" void* func_00281C40_p(void* self, int i) __asm__("func_00281C40");
// PORT: func_00282DB0's mangled signature is (void*, int, int); it also takes four floats (same alias as func_002812E0).
void* func_00282DB0_f(void* self, int a1, int a2, float f0, float f1, float f2, float f3)
    __asm__("func_00282DB0__FPvii");
extern "C" void func_00282DD0(void* self, int id, int a, int b, float f0, float f1, float f2, float f3);

struct sKind_281C68
{
    signed char a;
    signed char b;
    short c;
    short d;
};

struct sNode_281C68
{
    int mode;
    int bit;
    int start;
    char padC[0x4];
    unsigned int len;
    sKind_281C68* kind;
};

extern "C" void func_00281C68(void* self, int* info, float t)
{
    sNode_281C68* node = (sNode_281C68*)info[1];
    int bit = node->bit;
    for (int i = 0; i < 2; i++)
    {
        if (i == bit)
            continue;
        if (node->kind->a >= 7)
        {
            func_00281AC8(self, i, 9);
            continue;
        }
        void* o = func_00281C40_p(self, i);
        if (o)
            func_0027D788(o, 0.0f);
    }
    func_00281AC8(self, bit, node->mode);
    *(int*)((char*)self + 0xE8) = 0;
    if (node->kind->a == 8)
        return;
    if (node->len == 0)
        return;
    *(int*)((char*)self + 0xE8) = 1;
    int k = node->kind->a;
    if (k >= 7)
    {
        void** pf = (void**)((char*)self + 0xD8);
        if (*pf == 0)
        {
            *(int*)((char*)self + 0xE8) = 0;
            return;
        }
        int id = func_0027D2F0((sScriptEng0050*)func_0027D2E8(), (char*)self + 0x10);
        func_00282DB0_f(*pf, id, node->kind->a, t - (float)node->start, (float)node->len, 0.0f, 0.0f);
    }
    else if (k > 0)
    {
        void** pf = (void**)((char*)self + 0xD8);
        if (*pf == 0)
        {
            *(int*)((char*)self + 0xE8) = 0;
            return;
        }
        int id = func_0027D2F0((sScriptEng0050*)func_0027D2E8(), (char*)self + 0x10);
        func_00282DD0(*pf, id, node->kind->a, node->kind->b, t - (float)node->start, (float)node->kind->d, (float)node->len, (float)node->kind->c);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281E80);
#ifdef SKIP_ASM
extern "C" void* func_0027CDD0(void* self);
extern "C" void func_002828B8(void* self);
extern char D_00482450[];
extern char D_004824B8[];
extern void* D_004A34E8;

extern "C" void* func_00281E80(void* self)
{
    func_0027CDD0(self);
    *(void**)((char*)self + 0x2AC) = D_00482450;
    *(void**)((char*)self + 0x2A8) = D_004824B8;
    D_004A34E8 = self;
    *(int*)((char*)self + 0x2B0) = 0;
    *(int*)((char*)self + 0x2B4) = 0;
    func_002828B8(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("scripter/ssxscriptengine", func_00281ED8);
#ifdef SKIP_ASM
extern "C" void func_0027CE58(void* self, int flags);
extern "C" void func_00282020(void* self);
extern char D_00482450[];
extern char D_004824B8[];
extern void* D_004A34E8;

extern "C" void func_00281ED8(void* self, int flags)
{
    *(void**)((char*)self + 0x2AC) = D_00482450;
    *(void**)((char*)self + 0x2A8) = D_004824B8;
    func_00282020(self);
    D_004A34E8 = 0;
    func_0027CE58(self, flags);
}
#endif

