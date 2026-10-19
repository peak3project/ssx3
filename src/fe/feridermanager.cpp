#include "common.h"

//100%
INCLUDE_ASM("fe/feridermanager", cFERider_initBoneMap);
#ifdef SKIP_ASM
extern "C" int func_00310C48(void* self, int idx, const char* name);
extern char D_004A1970[];
extern char D_004A1978[];
extern char D_00460A00[];
extern char D_00460A10[];
extern char D_00460A20[];
extern char D_00460A30[];
extern char D_00460A40[];
extern char D_00460A50[];
extern char D_00460A60[];
extern char D_00460A70[];
extern char D_00460A80[];
extern char D_00460A90[];
extern char D_00460AA0[];
extern char D_00460AB0[];

extern "C" void cFERider_initBoneMap(void* self)
{
    *(int*)((char*)self + 0xC7C) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_004A1970);
    *(int*)((char*)self + 0xC80) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_004A1978);
    *(int*)((char*)self + 0xC84) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A00);
    *(int*)((char*)self + 0xC88) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A10);
    *(int*)((char*)self + 0xC8C) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A20);
    *(int*)((char*)self + 0xC90) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A30);
    *(int*)((char*)self + 0xC94) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A40);
    *(int*)((char*)self + 0xC98) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A50);
    *(int*)((char*)self + 0xC9C) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A60);
    *(int*)((char*)self + 0xCA0) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A70);
    *(int*)((char*)self + 0xCA4) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A80);
    *(int*)((char*)self + 0xCA8) = func_00310C48(*(void**)((char*)self + 0x8), 0, D_00460A90);
    *(int*)((char*)self + 0xCAC) = func_00310C48(*(void**)((char*)self + 0x8), 1, D_00460AA0);
    *(int*)((char*)self + 0xCB0) = func_00310C48(*(void**)((char*)self + 0x8), 1, D_00460AB0);
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019E7F0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void* func_0014D998(void* db, int g);
int func_0014D988(void* db, int g);
extern "C" int func_0014B988(void* iface, int a1, int a2, void* ent, char* buf);
extern "C" int func_0019DA10(void* mgr, int bank, char* buf, int a3, int a4, int a5);
extern "C" int func_0019CCE8(void* self, int a1, int a2);
extern "C" void func_0019CD38(void* self, int bit, int a2, int val);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemE7F0 {
    short id;
    unsigned short flags;
};
struct sItemListE7F0 {
    char pad_0x0[0x288];
    short* map;             // 0x288
    int count;              // 0x28C
    sItemE7F0 items[1];     // 0x290
};
struct sBoneEntE7F0 {
    char f0;
    char f1;
    char f2;
    signed char type;       // 0x3
    short slot;             // 0x4
    char pad_0x6[0x38 - 0x6];
};

static inline sItemE7F0* getItemK19E7F0(sItemListE7F0* list, int i)
{
    if (i >= 0)
        return &list->items[i];
    return 0;
}

extern "C" void func_0019E7F0(int* self)
{
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    void* db = func_0014BDB8_noarg();
    sItemListE7F0* list = (sItemListE7F0*)func_0014AD28(iface, self[1], self[0]);
    sBoneEntE7F0* e = (sBoneEntE7F0*)func_0014D998(db, self[0]);
    int n = func_0014D988(db, self[0]);
    *(int*)((char*)self + 0xCB8) = 0;
    int i;
    for (i = 0; i < n; i++, e++) {
        if (e->type == 6) {
            sItemE7F0* it = getItemK19E7F0(list, list->map[e->slot]);
            if (func_0019CCE8(D_004A1968, self[1], it->id) < 0) {
                char buf[0x100];
                if (func_0014B988(iface, self[1], self[0], e, buf)) {
                    int r = func_0019DA10(mgr, self[0], buf, 0xB, 1, 1);
                    func_0019CD38(D_004A1968, self[1], it->id, r);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", cFERider_init);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void func_0019EBA0(void* self);
extern "C" void func_0019E7F0(int* self);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002F1890(void* mem, void* owner);
extern "C" void* func_002ECA68(void* mem, void* owner, void* a2);
extern "C" void* func_0030D4B8(void* mem);
extern "C" void func_0030D840(void* pool, int a1, int a2);
extern "C" void func_002F19F0(void* a, void* b);
// PORT: these are defined later in the unit with struct-typed params; bind void* views by asm label
extern "C" void func_0019FF00_E980(int* self, void* list, void* prev, int force, int a4) __asm__("func_0019FF00");
extern "C" void func_0019FBE0_E980(int* self, void* list, int a2, int a3) __asm__("func_0019FBE0");
extern "C" void func_0019F138_E980(void* self) __asm__("func_0019F138");
extern char D_00460AC0[];
extern char D_00460AD8[];
extern char D_00460AF0[];

// PORT: callers declare cFERider_init as returning void; the body returns 1
extern "C" int cFERider_init_impl(int* self, int profile, int character, int slot) __asm__("cFERider_init");
extern "C" int cFERider_init_impl(int* self, int profile, int character, int slot)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    if (self[0] == character && self[4] == slot) {
        return 1;
    }
    if (self[0] >= 0) {
        func_0019EBA0(self);
    }
    int dirty = (self[0xCC4 / 4] != 0) | (self[0xCC8 / 4] != 0);
    self[4] = slot;
    self[1] = profile;
    self[0] = character;
    self[0xC28 / 4] = 0;
    self[0x14 / 4] = 0;
    self[0xCC8 / 4] = 0;
    self[0xCB4 / 4] = 0;
    self[0xCB8 / 4] = 0;
    self[0xCBC / 4] = 0;
    self[0xCC0 / 4] = 0;
    self[0xC24 / 4] = -1;
    self[0xCC4 / 4] = dirty;
    *(void**)&self[0xC70 / 4] = func_002F1890(cMemMan_alloc(0xA8, D_00460AC0, 0, 0), self);
    *(void**)&self[0xC74 / 4] = func_002ECA68(cMemMan_alloc(0xC8, D_00460AD8, 0, 0), self, *(void**)&self[0xC70 / 4]);
    *(void**)&self[2] = func_0030D4B8(cMemMan_alloc(0x160, D_00460AF0, 0, 0));
    func_0030D840(*(void**)&self[2], 100, 15);
    func_002F19F0(*(void**)&self[0xC70 / 4], *(void**)&self[2]);
    void* list = func_0014AD28(iface, profile, character);
    func_0019FF00_E980(self, list, 0, self[4], 1);
    if (self[4] != 0) {
        func_0019E7F0(self);
    }
    func_0019FBE0_E980(self, list, 0, 1);
    func_0019F138_E980(self);
    switch (self[0]) {
    case 0: self[0xCD8 / 4] = 1; break;
    case 1: self[0xCD8 / 4] = 4; break;
    case 2: self[0xCD8 / 4] = 0x20; break;
    case 3: self[0xCD8 / 4] = 2; break;
    case 4: self[0xCD8 / 4] = 8; break;
    case 5: self[0xCD8 / 4] = 0x100; break;
    case 6: self[0xCD8 / 4] = 0x200; break;
    case 7: self[0xCD8 / 4] = 0x80; break;
    case 8: self[0xCD8 / 4] = 0x10; break;
    case 9: self[0xCD8 / 4] = 0x40; break;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019EBA0);
#ifdef SKIP_ASM
struct sVE_EBA0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
extern "C" void func_0030D540(void* p, int flags);
extern "C" void func_0019EC68(void* self);

extern "C" void func_0019EBA0(void* self)
{
    void* p = *(void**)((char*)self + 0x8);
    if (p != 0) {
        func_0030D540(p, 3);
    }
    char* o = *(char**)((char*)self + 0xC);
    if (o != 0) {
        sVE_EBA0* vt = *(sVE_EBA0**)(o + 0x58);
        vt[1].fn(o + vt[1].delta, 3);
    }
    o = *(char**)((char*)self + 0xC74);
    if (o != 0) {
        sVE_EBA0* vt = *(sVE_EBA0**)(o + 0xC4);
        vt[1].fn(o + vt[1].delta, 3);
    }
    o = *(char**)((char*)self + 0xC70);
    if (o != 0) {
        sVE_EBA0* vt = *(sVE_EBA0**)(o + 0xA4);
        vt[1].fn(o + vt[1].delta, 3);
    }
    *(void**)((char*)self + 0x8) = 0;
    *(void**)((char*)self + 0xC) = 0;
    *(void**)((char*)self + 0xC70) = 0;
    *(void**)((char*)self + 0xC74) = 0;
    func_0019EC68(self);
    *(int*)((char*)self + 0x0) = -1;
    *(int*)((char*)self + 0x4) = -1;
    *(int*)((char*)self + 0xCC8) = 0;
    *(int*)((char*)self + 0xC78) = 0;
    *(int*)((char*)self + 0xCD4) = -1;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019EC68);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" int func_0019CBE0(void* self, int a1, int a2);
extern "C" int func_0019CCE8(void* self, int a1, int a2);
extern "C" void func_0019CC30(void* self, int bit, int a2, int val);
extern "C" void func_0019CD38(void* self, int bit, int a2, int val);
extern "C" void func_0019DC20(void* self, int bank, int i);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemEC68 {
    short id;
    short pad;
};
struct sItemListEC68 {
    char pad_0x0[0x28C];
    int count;              // 0x28C
    sItemEC68 items[1];     // 0x290
};

extern "C" void func_0019EC68(void* p)
{
    int* self = (int*)p;
    if (self[1] < 0)
        return;
    if (self[0] < 0)
        return;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    sItemListEC68* list = (sItemListEC68*)func_0014AD28(iface, self[1], self[0]);
    int n = list->count;
    int i;
    for (i = 0; i < n; i++) {
        int r = func_0019CCE8(D_004A1968, self[1], list->items[i].id);
        if (r >= 0) {
            func_0019DC20(mgr, self[0], r);
            func_0019CD38(D_004A1968, self[1], list->items[i].id, -1);
        }
        r = func_0019CBE0(D_004A1968, self[1], list->items[i].id);
        if (r >= 0) {
            func_0019DC20(mgr, self[0], r);
            func_0019CC30(D_004A1968, self[1], list->items[i].id, -1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019ED80);
#ifdef SKIP_ASM
extern void* D_004A289C;
void func_00369890(void* self, int a1, int a2);
extern "C" void func_00369690(void* self, int count, void* src);
extern "C" void cAnimModel_compile(void* self, int a1);
// PORT: cMemMan_alloc bound as a placement operator new (gcc treats operator new as malloc-like)
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
struct sAnimMemED80 { char d[0x70]; };
extern "C" void* cRiderAnimBase_cRiderAnimBase(void* self);
extern "C" void func_00104D50(void* anim, void* rider);
extern "C" void cRiderAnimBase_play(void* self, int anim, int flags, float blend);
extern "C" void func_00312598(void* self, int a1);
extern "C" void cFERider_initBoneMap(void* self);
extern char D_00460B28[];
extern void* D_00458458[];

struct sQuadED80 { int x[4]; } __attribute__((aligned(16)));
struct sHalfED80 {
    sQuadED80 a, b;
    sHalfED80() {}
};
extern sHalfED80 D_004FF230;
extern "C" void func_00310200(void* model, void* pose);

struct sFERiderED80 {
    char pad_0x0[0x8];
    void* model;        // 0x8
    void* anim;         // 0xC
    char pad_0x10[0x8];
    int count;          // 0x18
    char bones[0xCB4 - 0x1C];  // 0x1C
    int fCB4;           // 0xCB4
};

extern "C" void func_0019ED80(sFERiderED80* self)
{
    self->fCB4 = 1;
    func_00369890(D_004A289C, 0, 0);
    func_00369690(D_004A289C, self->count, self->bones);
    cAnimModel_compile(self->model, 1);
    char* anim = (char*)new (D_00460B28, 0, 0) sAnimMemED80;
    cRiderAnimBase_cRiderAnimBase(anim);
    *(void***)(anim + 0x58) = D_00458458;
    *(int*)(anim + 0x60) = 0;
    self->anim = anim;
    *(int*)(anim + 0x64) = 0;
    func_00104D50(anim, self);
    cRiderAnimBase_play(self->anim, 0x1B2, 0, -1.0f);
    func_00312598(self->anim, 0);
    sHalfED80 p[2];
    p[1] = D_004FF230;
    p[0] = D_004FF230;
    func_00310200(self->model, p);
    cFERider_initBoneMap(self);
}
#endif

INCLUDE_ASM("fe/feridermanager", func_0019EE88);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feridermanager", func_0019F138);
#ifdef SKIP_ASM
extern void* D_004A289C;
extern "C" void cFERider_init(void* self, int a1, int a2, int a3);
extern "C" int func_001A0100(int* self);
extern "C" int func_0019FD58(int* self);
extern "C" void func_0019F780(int* self);
extern "C" void func_0019F2D0(void* self);
extern "C" void func_003123C0(void* anim, int a1, float blend);
extern "C" void func_00312490(void* anim);
extern "C" void func_002F1A08(void* p);
extern "C" void func_002ECF78(void* p);

struct sFERiderF138 {
    unsigned int state;     // 0x0
    int f4;                 // 0x4
    char pad_0x8[0x4];
    void* anim;             // 0xC
    char pad_0x10[0xC24 - 0x10];
    int fC24;               // 0xC24
    int fC28;               // 0xC28
    char pad_0xC2C[0xC70 - 0xC2C];
    void* fC70;             // 0xC70
    void* fC74;             // 0xC74
    char pad_0xC78[0xCB4 - 0xC78];
    int fCB4;               // 0xCB4
    int fCB8;               // 0xCB8
    int fCBC;               // 0xCBC
    int fCC0;               // 0xCC0
    int fCC4;               // 0xCC4
    int fCC8;               // 0xCC8
    char pad_0xCCC[0xCD4 - 0xCCC];
    int pending;            // 0xCD4
};

struct sVEF138 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_0019F138(void* selfp)
{
    sFERiderF138* self = (sFERiderF138*)selfp;
    if (self->pending >= 0) {
        char* g = (char*)D_004A289C;
        sVEF138* vt = *(sVEF138**)(g + 0x10D8);
        if (self->pending < vt[114].fn(g + vt[114].delta)) {
            self->pending = -1;
            cFERider_init(self, self->f4, self->fC24, self->fC28);
        }
    } else {
        if (self->state >= 10) {
            return;
        }
        if (self->fCBC == 0 && func_001A0100((int*)self)) {
            self->fCBC = 1;
        } else if (self->fCBC != 0) {
            if (self->fCB8 == 0 && func_0019FD58((int*)self)) {
                self->fCB8 = 1;
                if (self->fCB4 == 0) {
                    func_0019ED80((sFERiderED80*)self);
                }
            } else if (self->fCBC != 0 && self->fCB8 != 0 && self->fCB4 != 0 && self->fCC0 == 0) {
                func_0019F780((int*)self);
                self->fCC0 = 1;
                int* pv = &self->fCC8;
                *pv = self->fCC4 != 0 || *pv != 0;
                self->fCC4 = 0;
            }
        }
    }
    if (self->fCC8 != 0) {
        if (self->anim != 0) {
            func_003123C0(self->anim, 0, 1.0f);
            func_00312490(self->anim);
        }
        func_0019F2D0(self);
        func_002F1A08(self->fC70);
        func_002ECF78(self->fC74);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F2D0);
#ifdef SKIP_ASM
struct sQuadF2D0 { int x[4]; } __attribute__((aligned(16)));
struct sHalfF2D0 { sQuadF2D0 a, b; };
extern sQuadF2D0 D_004FF130;
extern sQuadF2D0 D_004FF220;
extern "C" void func_00310200(void* model, void* pose);
extern "C" void func_003103F0(void* model);

extern "C" void func_0019F2D0(void* self)
{
    sHalfF2D0 p[2];
    if (*(int*)((char*)self + 0xCCC) != 0) {
        p[0] = *(sHalfF2D0*)((char*)self + 0xC30);
        p[1] = *(sHalfF2D0*)((char*)self + 0xC30);
        func_00310200(*(void**)((char*)self + 0x8), p);
        func_003103F0(*(void**)((char*)self + 0x8));
    } else {
        p[0] = *(sHalfF2D0*)((char*)self + 0xC30);
        p[1] = *(sHalfF2D0*)((char*)self + 0xC50);
        (*(sQuadF2D0**)(*(char**)((char*)self + 0x8) + 0x24))[*(int*)((char*)self + 0xCAC)] = D_004FF130;
        (*(sQuadF2D0**)(*(char**)((char*)self + 0x8) + 0x28))[*(int*)((char*)self + 0xCAC)] = D_004FF220;
        (*(sQuadF2D0**)(*(char**)((char*)self + 0x8) + 0x24))[*(int*)((char*)self + 0xCB0)] = D_004FF130;
        (*(sQuadF2D0**)(*(char**)((char*)self + 0x8) + 0x28))[*(int*)((char*)self + 0xCB0)] = D_004FF220;
        func_00310200(*(void**)((char*)self + 0x8), p);
        func_003103F0(*(void**)((char*)self + 0x8));
    }
    *(int*)((char*)self + 0x14) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F3E8);
#ifdef SKIP_ASM
struct sQuadRM { int x[4]; } __attribute__((aligned(16)));
extern "C" void func_0019F2D0(void* self);

extern "C" void func_0019F3E8(void* self, sQuadRM* src)
{
    *(sQuadRM*)((char*)self + 0xC30) = src[0];
    *(sQuadRM*)((char*)self + 0xC40) = src[1];
    func_0019F2D0(self);
}
#endif

INCLUDE_ASM("fe/feridermanager", func_0019F418);

INCLUDE_ASM("fe/feridermanager", func_0019F488);

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F548);
#ifdef SKIP_ASM
extern "C" void func_0019F2D0(void* self);

extern "C" void func_0019F548(void* self, sQuadRM* src)
{
    *(sQuadRM*)((char*)self + 0xC50) = src[0];
    *(sQuadRM*)((char*)self + 0xC60) = src[1];
    func_0019F2D0(self);
}
#endif

INCLUDE_ASM("fe/feridermanager", func_0019F578);

INCLUDE_ASM("fe/feridermanager", func_0019F5E8);

INCLUDE_ASM("fe/feridermanager", func_0019F6A8);

INCLUDE_ASM("fe/feridermanager", func_0019F6C8);

INCLUDE_ASM("fe/feridermanager", func_0019F6F0);

INCLUDE_ASM("fe/feridermanager", func_0019F718);

INCLUDE_ASM("fe/feridermanager", func_0019F740);

INCLUDE_ASM("fe/feridermanager", func_0019F760);

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F780);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" int func_0014D448(void* self, int g, int key);
extern "C" void func_0030EB60(void* model);
extern "C" void func_0030EC18(void* model, int i, int param);

struct sItemF780 {
    short id;
    unsigned short flags;
};
struct sItemListF780 {
    char pad_0x0[0x28C];
    int count;              // 0x28C
    sItemF780 items[1];     // 0x290
};
struct sBoneEntF780 {
    char f0;
    char f1;
    char pad_0x2[0xE];
    char f10;
    char pad_0x11[0x38 - 0x11];
};
struct sBoneDbF780 {
    int f0;
    sBoneEntF780* entries;  // 0x4
};

static inline sBoneEntF780* getEntK19F780(sBoneDbF780* db, int i)
{
    if (i < 0)
        return 0;
    return &db->entries[i];
}

extern "C" void func_0019F780(int* self)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    sBoneDbF780* db = (sBoneDbF780*)func_0014BDB8_noarg();
    sItemListF780* list = (sItemListF780*)func_0014AD28(iface, self[1], self[0]);
    int n = list->count;
    sItemF780* it = list->items;
    func_0030EB60(*(void**)((char*)self + 0x8));
    int i;
    for (i = 0; i < n; i++) {
        if (it[i].flags & 0x10) {
            sBoneEntF780* e = getEntK19F780(db, func_0014D448(db, self[0], it[i].id));
            if (e->f10 >= 0)
                func_0030EC18(*(void**)((char*)self + 0x8), e->f10, e->f1);
        }
    }
    **(int**)((char*)self + 0xC74) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F878);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const void* a, const void* b);

struct sRiderName_F878 {
    int id;
    char name[8];
};

struct sRiderTable_F878 {
    char pad_0x0[0x18];
    int count;
    sRiderName_F878 entries[1];
};

extern "C" int func_0019F878(sRiderTable_F878* self, const char* name)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (func_004165A8(name, self->entries[i].name) == 0) {
            return self->entries[i].id;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019F908);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void func_003B3D00(void* pkg, int i, char* name);
extern "C" char* strcpy(char* dst, const char* src);
extern void* D_004A289C;
extern char D_004A19A8[];
extern char D_004A19B0[];

struct sPkgEnt_F908 {
    int off;
    int f4;
};
struct sPkg_F908 {
    int f0;
    int f4;
    int count;      // 0x8
    int fC;
    int f10;
    sPkgEnt_F908 ents[1];   // 0x14
};
struct sName2_F908 { char c[2]; };
struct sVE_F908a {
    short delta;
    short index;
    int (*fn)(void*, char*, char*, int, int, int);
};
struct sVE_F908b {
    short delta;
    short index;
    void (*fn)(void*, int, char*, int);
};

extern "C" void func_0019F908(sRiderTable_F878* self, sPkg_F908* pkg, int replace)
{
    int n = pkg->count;
    int i;
    for (i = 0; i < n; i++) {
        sPkgEnt_F908* e = &pkg->ents[i];
        char* data = (char*)pkg + e->off;
        char name[8];
        *(sName2_F908*)name = *(sName2_F908*)D_004A19A8;
        func_00416210(name + 2, 0, 6);
        func_003B3D00(pkg, i, name);
        int id = func_0019F878(self, name);
        if (id >= 0) {
            if (replace) {
                char* o = (char*)D_004A289C;
                sVE_F908b* vt = *(sVE_F908b**)(o + 0x10D8);
                vt[48].fn(o + vt[48].delta, id, data, 1);
            }
        } else {
            strcpy(self->entries[self->count].name, name);
            char* o = (char*)D_004A289C;
            sVE_F908a* vt = *(sVE_F908a**)(o + 0x10D8);
            self->entries[self->count].id = vt[46].fn(o + vt[46].delta, data, D_004A19B0, 0, 1, -1);
            self->count++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019FA78);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" void* func_0014D998(void* db, int g);
int func_0014D988(void* db, int g);
extern "C" int func_0019CCE8(void* self, int a1, int a2);
extern "C" void func_0019CD38(void* self, int bit, int a2, int val);
extern "C" void func_0019DC20(void* self, int bank, int i);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemFA78 {
    short id;
    unsigned short flags;
};
struct sItemListFA78 {
    char pad_0x0[0x288];
    short* map;             // 0x288
    int count;              // 0x28C
    sItemFA78 items[1];     // 0x290
};
struct sBoneEntFA78 {
    char f0;
    char f1;
    char f2;
    signed char type;       // 0x3
    short slot;             // 0x4
    char pad_0x6[0x38 - 0x6];
};

static inline sItemFA78* getItemK19FA78(sItemListFA78* list, int i)
{
    if (i >= 0)
        return &list->items[i];
    return 0;
}

extern "C" void func_0019FA78(int* self, sItemListFA78* list)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    void* db = func_0014BDB8_noarg();
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    if (self[1] < 0)
        return;
    if (self[0] < 0)
        return;
    if (list == 0)
        list = (sItemListFA78*)func_0014AD28(iface, self[1], self[0]);
    int flag = 1;
    int n = func_0014D988(db, self[0]);
    sBoneEntFA78* e = (sBoneEntFA78*)func_0014D998(db, self[0]);
    int i;
    for (i = 0; i < n; i++, e++) {
        sItemFA78* it = getItemK19FA78(list, list->map[e->slot]);
        int r = func_0019CCE8(D_004A1968, self[1], it->id);
        if (r >= 0) {
            if (e->type != 6) {
                func_0019DC20(mgr, self[0], r);
                func_0019CD38(D_004A1968, self[1], it->id, -1);
            } else {
                flag = 0;
            }
        }
    }
    *(int*)((char*)self + 0xCB8) = flag;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019FBE0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" void* func_0014D998(void* db, int g);
int func_0014D988(void* db, int g);
extern "C" int func_0014B988(void* iface, int a1, int a2, void* ent, char* buf);
extern "C" int func_0019DA10(void* mgr, int bank, char* buf, int a3, int a4, int a5);
extern "C" int func_0019CCE8(void* self, int a1, int a2);
extern "C" void func_0019CD38(void* self, int bit, int a2, int val);
extern "C" void func_0019E070(void* mgr, int bank);
struct sItemListFA78;
extern "C" void func_0019FA78(int* self, sItemListFA78* list);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemFBE0 {
    short id;
    unsigned short flags;
};
struct sItemListFBE0 {
    char pad_0x0[0x288];
    short* map;             // 0x288
    int count;              // 0x28C
    sItemFBE0 items[1];     // 0x290
};
struct sBoneEntFBE0 {
    char f0;
    char f1;
    char f2;
    signed char type;       // 0x3
    short slot;             // 0x4
    char pad_0x6[0x38 - 0x6];
};

static inline sItemFBE0* getItemK19FBE0(sItemListFBE0* list, int i)
{
    if (i >= 0)
        return &list->items[i];
    return 0;
}

extern "C" void func_0019FBE0(int* self, sItemListFBE0* list, int a2, int a3)
{
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    void* db = func_0014BDB8_noarg();
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    func_0019FA78(self, (sItemListFA78*)list);
    *(int*)((char*)self + 0xCB8) = 0;
    *(int*)((char*)self + 0xCC0) = 0;
    int n = func_0014D988(db, self[0]);
    sBoneEntFBE0* e = (sBoneEntFBE0*)func_0014D998(db, self[0]);
    int i;
    for (i = 0; i < n; i++, e++) {
        sItemFBE0* it = getItemK19FBE0(list, list->map[e->slot]);
        if (func_0019CCE8(D_004A1968, self[1], it->id) < 0) {
            if (it->flags & 0x10) {
                char buf[0x100];
                if (func_0014B988(iface, self[1], self[0], e, buf)) {
                    int r = func_0019DA10(mgr, self[0], buf, 0xB, a3, 1);
                    func_0019CD38(D_004A1968, self[1], it->id, r);
                }
            }
        }
    }
    func_0019E070(mgr, self[0]);
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019FD58);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind); bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014AD28(void* self, int a1, int a2);
extern "C" int func_0019CCE8(void* self, int a1, int a2);
extern "C" void func_0019CD38(void* self, int bit, int a2, int val);
extern "C" void func_0019DC20(void* self, int bank, int i);
extern "C" int func_0019E238(void* mgr, int bank, int i);
extern "C" void* func_0019E2B0(void* mgr, int bank, int i);
extern "C" void func_003E6448(void* dst, int c, int n);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemFD58 {
    short id;
    unsigned short flags;
};
struct sItemListFD58 {
    char pad_0x0[0x288];
    short* map;             // 0x288
    int count;              // 0x28C
    sItemFD58 items[1];     // 0x290
};

extern "C" int func_0019FD58(int* self)
{
    if (*(int*)((char*)self + 0xCB8) != 0) {
        return 1;
    }
    int ok = 1;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 9);
    sItemListFD58* list = (sItemListFD58*)func_0014AD28(iface, self[1], self[0]);
    int n = list->count;
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    for (int i = 0; i < n; i++) {
        sItemFD58* it = &list->items[i];
        int r = func_0019CCE8(D_004A1968, self[1], it->id);
        if (r >= 0) {
            if (func_0019E238(mgr, self[0], r) == 0) {
                ok = 0;
            }
        }
    }
    if (ok) {
        int used[256];
        func_003E6448(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) {
            sItemFD58* it = &list->items[i];
            int r = func_0019CCE8(D_004A1968, self[1], it->id);
            if (r >= 0) {
                if (func_0019E2B0(mgr, self[0], r) && used[r] == 0) {
                    sPkg_F908* pkg = (sPkg_F908*)func_0019E2B0(mgr, self[0], r);
                    int fl = it->flags & 0x10;
                    func_0019F908((sRiderTable_F878*)self, pkg, fl != 0);
                }
                used[r] = 1;
                func_0019DC20(mgr, self[0], r);
                func_0019CD38(D_004A1968, self[1], it->id, -1);
            }
        }
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_0019FF00);
#ifdef SKIP_ASM
// PORT: func_0014BDB8 is declared (void*) but never reads its argument; called here with none
void* func_0014BDB8_noarg() __asm__("func_0014BDB8__FPv");
extern "C" int func_0014D448(void* self, int g, int key);
extern "C" int func_0019CBE0(void* self, int a1, int a2);
extern "C" void func_0019CC30(void* self, int bit, int a2, int val);
extern "C" int func_0019DA10(void* mgr, int bank, char* buf, int a3, int a4, int a5);
extern "C" void func_0019DC20(void* self, int bank, int i);
extern "C" void func_0019DF20(void* mgr, int bank);
extern void* D_004A28A8;
extern void* D_004A1968;

struct sItemFF00 {
    short id;
    unsigned short flags;
};
struct sItemListFF00 {
    char pad_0x0[0x28C];
    int count;              // 0x28C
    sItemFF00 items[1];     // 0x290
};
struct sBoneEntFF00 {
    char pad_0x0[0x28];
    char* file;             // 0x28
    char pad_0x2C[0x38 - 0x2C];
};
struct sBoneDbFF00 {
    int f0;
    sBoneEntFF00* entries;  // 0x4
};

static inline sBoneEntFF00* getEntK19FF00(sBoneDbFF00* db, int i)
{
    if (i < 0)
        return 0;
    return &db->entries[i];
}

extern "C" void func_0019FF00(int* self, sItemListFF00* list, sItemFF00* prev, int force, int a4)
{
    int n = list->count;
    sBoneDbFF00* db = (sBoneDbFF00*)func_0014BDB8_noarg();
    char* mgr = *(char**)((char*)D_004A28A8 + 0x7C) + 0x1A70;
    for (int i = 0; i < n; i++) {
        sItemFF00* it = &list->items[i];
        if (force == 0 && (it->flags & 0x10) == 0) {
            if (func_0019CBE0(D_004A1968, self[1], it->id) >= 0) {
                func_0019DC20(mgr, self[0], func_0019CBE0(D_004A1968, self[1], it->id));
                func_0019CC30(D_004A1968, self[1], it->id, -1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sItemFF00* it = &list->items[i];
        if (func_0019CBE0(D_004A1968, self[1], it->id) < 0) {
            if (force || ((it->flags & 0x10) && (prev == 0 || (prev->flags & 0x10) == 0))) {
                sBoneEntFF00* e = getEntK19FF00(db, func_0014D448(db, self[0], it->id));
                if (e->file) {
                    int r = func_0019DA10(mgr, self[0], e->file, 8, a4, 1);
                    func_0019CC30(D_004A1968, self[1], it->id, r);
                    *(int*)((char*)self + 0xCBC) = 0;
                    *(int*)((char*)self + 0xCB4) = 0;
                } else {
                    func_0019CC30(D_004A1968, self[1], it->id, -1);
                }
            }
            if (prev) {
                prev++;
            }
        }
    }
    func_0019DF20(mgr, self[0]);
}
#endif

INCLUDE_ASM("fe/feridermanager", func_001A0100);

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0358);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void func_002A16B0(void* mgr, int id);
extern "C" void func_002A1778(void* mgr, int id);

extern "C" void func_001A0358(void* self)
{
    if (*(int*)((char*)self + 0xC1C) != 0) {
        func_002A1778(func_0028B180(), *(int*)self);
        *(int*)((char*)self + 0xC1C) = 0;
    } else if (*(int*)((char*)self + 0xC20) != 0) {
        func_002A16B0(func_0028B180(), *(int*)self);
        *(int*)((char*)self + 0xC20) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A03C0);
#ifdef SKIP_ASM
extern "C" void* func_0019E3D0(void* self);

extern "C" void* func_001A03C0(void* self)
{
    char* p = (char*)self;
    int i;
    for (i = 1; i != -1; i--, p += 0xCE0) {
        func_0019E3D0(p);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0420);
#ifdef SKIP_ASM
extern "C" void func_001A04C8(void* self);
extern "C" void func_0019E498(void* self, int flags);
void operator_delete(int* p);

extern "C" void func_001A0420(void* self, int flags)
{
    func_001A04C8(self);
    char* base = (char*)self;
    if (base != 0) {
        char* p = base + 0x19C0;
        while (base != p) {
            p -= 0xCE0;
            func_0019E498(p, 0);
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0498);
#ifdef SKIP_ASM
struct sRiderSlot_001A0498 {
    int field_0x0;
    int index;
    char pad[0xce0 - 8];
};

extern "C" void func_001A0498(sRiderSlot_001A0498* self)
{
    int i;
    sRiderSlot_001A0498* p = self;
    for (i = 0; i < 2; i++) {
        p->index = i;
        p++;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A04C8);
#ifdef SKIP_ASM
extern "C" void func_0019EBA0(void* slot);

extern "C" void func_001A04C8(void* self)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_0019EBA0((char*)self + i * 0xce0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0508);
#ifdef SKIP_ASM
extern "C" void func_0019E588(void* slot, int a1, int a2);

extern "C" void func_001A0508(void* self, int idx, int a2, int a3)
{
    func_0019E588((char*)self + idx * 0xce0, a2, a3);
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0538);
#ifdef SKIP_ASM
extern "C" void* func_001A0538(void* self, int a1)
{
    return (char*)self + a1 * 0xce0;
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0548);
#ifdef SKIP_ASM
extern "C" void* func_001A0548(void* self, int a1)
{
    return (char*)self + a1 * 0xce0;
}
#endif

INCLUDE_ASM("fe/feridermanager", func_001A0558);

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0570);
#ifdef SKIP_ASM
extern "C" void func_0019E538(void* slot, int v);

extern "C" void func_001A0570(void* self, int i, int v)
{
    func_0019E538((char*)self + i * 0xce0, v);
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0598);
#ifdef SKIP_ASM
extern "C" void func_0019EE88(void* rider);

// Resets the world's rider camera indices and updates both active riders.
extern "C" void func_001A0598(char* self)
{
    char* p = (char*)D_004A289C;
    *(int*)(p + 0x24) = 0x2E;
    *(int*)(p + 0x84) = 0x2F;
    *(int*)(p + 0x10A8) = *(int*)(p + 0x1008);
    for (int i = 0; i < 2; i++) {
        p = self + i * 0xCE0;
        if (*(int*)(p + 0xCC8) != 0)
            func_0019EE88(p);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feridermanager", func_001A0608);
#ifdef SKIP_ASM
extern "C" void func_0019F138(void* slot);

extern "C" void func_001A0608(void* self)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_0019F138((char*)self + i * 0xce0);
    }
}
#endif

