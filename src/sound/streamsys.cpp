#include "common.h"

extern "C" char* strcpy(char* dst, const char* src);

//100%
INCLUDE_ASM("sound/streamsys", cStreamInstance_cStreamInstance);
#ifdef SKIP_ASM
struct sSsEnt_99D8 { char vol; char pad[0x17]; };
struct sSsPlayer_99D8 {
    char pad0[0x1C];
    volatile int cur;           // 0x1C
    sSsEnt_99D8* ents;          // 0x20
    char pad24[0x38 - 0x24];
    int* vols;                  // 0x38
    float** scales;             // 0x3C
};
struct sStreamInst_99D8 {
    char* mem;          // 0x0
    int f4;             // 0x4
    int handle;         // 0x8
    char vol;           // 0xC
    float* scale;       // 0x10
    char pad14[0x74 - 0x14];
    int f74;            // 0x74
    int f78;            // 0x78
    int heap;           // 0x7C
    int f80;            // 0x80
};
extern "C" int func_003B7818(void* desc, int n, int m, void* mem, int size);
extern "C" int func_003B7B00(int n, int m);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_004A3770[];

static inline int curVol_99D8(sSsPlayer_99D8* p) { return p->vols[p->cur]; }

#define MIN_99D8(a, b) ((a) < (b) ? (a) : (b))
#define MAX_99D8(a, b) ((a) >= (b) ? (a) : (b))

extern "C" sStreamInst_99D8* cStreamInstance_cStreamInstance(sStreamInst_99D8* self, sSsPlayer_99D8* p, int heap, int extra)
{
    self->f74 = 0;
    self->handle = -1;
    self->f78 = 0;
    self->heap = heap;
    self->f80 = 0;
    self->scale = p->scales[p->cur];
    self->vol = curVol_99D8(p);
    if (self->scale) {
        p->vols[p->cur] = (int)MAX_99D8(MIN_99D8((float)p->vols[p->cur] * *self->scale, 127.0f), 0.0f);
        p->ents[p->cur].vol = MAX_99D8(MIN_99D8(p->vols[p->cur], 127), 0);
    }
    int n = func_003B7B00(8, 300) + extra;
    self->mem = new (D_004A3770, heap, 0) char[n];
    self->f4 = 0;
    self->handle = func_003B7818(&p->ents[p->cur], 8, 300, self->mem, n);
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9C00);
#ifdef SKIP_ASM
extern "C" sStreamInst_99D8* func_002A9C00(sStreamInst_99D8* self, sSsPlayer_99D8* p, char* mem, int size, int n, int m)
{
    self->scale = p->scales[p->cur];
    self->vol = curVol_99D8(p);
    if (self->scale) {
        p->vols[p->cur] = (int)MAX_99D8(MIN_99D8((float)p->vols[p->cur] * *self->scale, 127.0f), 0.0f);
        p->ents[p->cur].vol = MAX_99D8(MIN_99D8(p->vols[p->cur], 127), 0);
    }
    self->mem = mem;
    self->f4 = 1;
    self->handle = func_003B7818(&p->ents[p->cur], n, m, mem, size);
    return self;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002A9DD8);
#ifdef SKIP_ASM
extern "C" void *func_002A9DD8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (0x74))) = 0;
    (*(int *)((char*)(arg0) + (0x78))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9DF0);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" int func_003B7838(int h);
extern "C" void* func_002523A8(void* self);

extern "C" void func_002A9DF0(void* self, int flags)
{
    if (*(void**)self != 0) {
        func_003B7838(*(int*)((char*)self + 0x8));
        if (*(int*)((char*)self + 0x4) == 0 && *(void**)self != 0) {
            cMemMan_free(*(void**)self);
        }
    }
    if (*(void**)((char*)self + 0x74) != 0) {
        func_002523A8(*(void**)((char*)self + 0x74));
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9E78);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(const char* name);
extern "C" int func_003E1EC8(const char* name, int a1);

// PORT: second parameter is a const char* passed as int (unit declares func_002A9E78(void*, int)).
extern "C" void func_002A9E78(void* self, int name)
{
    if (BXFILE_exists((const char*)name) != 0) {
        strcpy((char*)self + 0x14, (const char*)name);
        *(int*)((char*)self + 0x74) = func_003E1EC8((char*)self + 0x14, *(int*)((char*)self + 0x7C));
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9ED8);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7F60(int h, int a, int b);

extern "C" void func_002A9ED8(void* self, int a, int b)
{
    func_003B58A0();
    func_003B7F60(*(int*)((char*)self + 0x8), a, b);
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9F30__FPvi);
#ifdef SKIP_ASM
void func_002A9F30(void* self, int val)
{
    *(char*)((char*)self + 0xC) = (char)val;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9F38);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7FB8(int h, int v);

extern "C" void func_002A9F38(void* self, int v)
{
    func_003B58A0();
    func_003B7FB8(*(int*)((char*)self + 0x8), v);
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002A9F80);
#ifdef SKIP_ASM
int func_0028B240(void* self);
void* func_002AA408(void* self);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7E70(int h, int vol);

extern "C" void func_002A9F80(void* self)
{
    if (func_0028B240(self) * 2 < *(int*)((char*)self + 0x80)) {
        func_002AA408(self);
        *(int*)((char*)self + 0x80) = 0;
        return;
    }
    float* p = *(float**)((char*)self + 0x10);
    if (p != 0) {
        int v = (int)((float)*(signed char*)((char*)self + 0xC) * *p);
        if (v > 0x7F) {
            v = 0x7F;
        }
        if (v < 0) {
            v = 0;
        }
        func_003B58A0();
        func_003B7E70(*(int*)((char*)self + 0x8), v);
        func_003B58D8();
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA020);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7B48(int h, void* out);

// PORT: returns int; the unit declares it void(void*, void*) further down
int func_002AA020_impl(void* self, void* out) __asm__("func_002AA020");

int func_002AA020_impl(void* self, void* out)
{
    int r;
    func_003B58A0();
    r = func_003B7B48(*(int*)((char*)self + 0x8), out);
    func_003B58D8();
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AA068);
#ifdef SKIP_ASM
extern "C" int func_002AA020(void*, void*);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B7C40(int h, int a1);

// PORT: returns int and takes (self, int, out); later callers in this unit declare it void(void*, sStatus*, int)
int func_002AA068_impl(void* self, int a1, int* out) __asm__("func_002AA068");

int func_002AA068_impl(void* self, int a1, int* out)
{
    int buf[4];
    int* p = out ? out : buf;
    int r;
    func_002AA020(self, p);
    func_003B58A0();
    r = func_003B7C40(p[1], a1);
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA0C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct func_002AA0C0_sStatus {
    int state;
    int a;
    int b;
    int c;
};

// the unit declares func_002AA068 later with a different pointer type; alias it
int func_002AA068_status(void* self, func_002AA0C0_sStatus* out, int flags) __asm__("func_002AA068");

extern "C" float func_002AA0C0(void* self)
{
    func_002AA0C0_sStatus st;
    func_002AA068_status(self, &st, 0);
    if (st.state == 2) {
        return (float)st.a;
    }
    return 0.0f;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AA108);
#ifdef SKIP_ASM
struct func_002AA1B8_sStatus;
extern "C" int func_002AA068(void* self, func_002AA1B8_sStatus* out, int flags);

struct func_002AA108_sStatus {
    int state;
    int a;
    int b;
    int c;
};

extern "C" float func_002AA108(void* self)
{
    func_002AA108_sStatus st;
    func_002AA068(self, (func_002AA1B8_sStatus*)&st, 0);
    if (st.state == 2) {
        return (float)st.b;
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA150);
#ifdef SKIP_ASM
struct func_002AA150_sStatus {
    int state;
    int a;
    int b;
    int c;
};

extern "C" int func_002AA150(void* self, int minVal)
{
    func_002AA150_sStatus st;
    func_002AA020(self, &st);
    return st.b >= minVal;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AA188);
#ifdef SKIP_ASM
struct func_002AA188_sStatus {
    int state;
    int a;
    int b;
    int c;
};

extern "C" int func_002AA188(void* self)
{
    func_002AA188_sStatus st;
    func_002AA068(self, (func_002AA1B8_sStatus*)&st, 0);
    return st.state == 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AA1B8);
#ifdef SKIP_ASM
struct func_002AA1B8_sStatus {
    int state;
    int a;
    int b;
    int c;
};

extern "C" int func_002AA068(void* self, func_002AA1B8_sStatus* out, int flags);

extern "C" int func_002AA1B8(void* self)
{
    func_002AA1B8_sStatus st;
    func_002AA068(self, &st, 0);
    return st.state == 2;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA1E8);
#ifdef SKIP_ASM
extern "C" int func_003B7D80(int, int);

extern "C" void func_002AA1E8(void* self)
{
    int buf[2];
    func_002AA020(self, buf);
    func_003B7D80(buf[1], 0);
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA210);
#ifdef SKIP_ASM
// func_002AA020 returns the status (the unit declares it void); the int return keeps $2 free as the target has it.
int func_002AA020_st(void* self, int* out) __asm__("func_002AA020");

// Returns the stream's second status word, or -1 when the stream is not active.
extern "C" int func_002AA210(void* self)
{
    int st[2];
    func_002AA020_st(self, st);
    if (st[0] == 0) {
        return -1;
    }
    return st[1];
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA240);
#ifdef SKIP_ASM
extern "C" int func_003B7D80(int, int);

extern "C" void func_002AA240(void* self, int arg1)
{
    func_003B7D80(arg1, 0);
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AA260);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct func_002AA260_sStatus {
    int state;
    int a;
    int b;
    int c;
};

int func_002AA068_status(void* self, func_002AA260_sStatus* out, int flags) __asm__("func_002AA068");

extern "C" float func_002AA260(void* self)
{
    func_002AA260_sStatus st;
    func_002AA068_status(self, &st, 0);
    if (st.state == 2) {
        return (float)(st.a + st.b);
    }
    return 0.0f;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AA2B0);
#ifdef SKIP_ASM
extern "C" void func_002AA2B0(void *arg0) {
    func_003B58A0();
    func_003B7FB8((*(int *)((char*)(arg0) + (8))), 0);
    func_003B58D8();
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AA2E8);
#ifdef SKIP_ASM
extern "C" void func_002AA2E8(void *arg0) {
    func_003B58A0();
    func_003B7FB8((*(int *)((char*)(arg0) + (8))), 0x1000);
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA320);
#ifdef SKIP_ASM
extern "C" int func_003B78D8(int h, int a, int buf, int off);
extern "C" int func_003E2CE0(void* dec, int src, int a, int* out, int b);

// PORT: buf is a pointer carried in an int (the unit's caller declares this function with int params).
extern "C" int func_002AA320(void* self, int a, int buf, int off)
{
    if (*(void**)((char*)self + 0x74) != 0) {
        int n;
        func_003E2CE0(*(void**)((char*)self + 0x74), buf, 0, &n, 0);
        return func_003B78D8(*(int*)((char*)self + 0x8), a, (int)((char*)self + 0x14), off + n);
    }
    return func_003B78D8(*(int*)((char*)self + 0x8), a, buf, off);
}
#endif

extern "C" void* func_003B78F8(int);

//100%
INCLUDE_ASM("sound/streamsys", func_002AA398);
#ifdef SKIP_ASM
extern "C" int func_002AA398(void* self, int a, int b, int off)
{
    void* dec = *(void**)((char*)self + 0x74);
    if (dec != 0) {
        int n;
        func_003E2CE0(dec, 0, b, &n, 0);
        return func_003B78D8(*(int*)((char*)self + 0x8), a, (int)((char*)self + 0x14), off + n);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA408__FPv);
#ifdef SKIP_ASM
void* func_002AA408(void* self)
{
    return func_003B78F8(*(int*)((char*)self + 0x8));
}
#endif

extern "C" int func_002AA020(void*, void*);

//100%
INCLUDE_ASM("sound/streamsys", func_002AA428);
#ifdef SKIP_ASM
extern "C" int func_002AA428(void* self)
{
    int buf[4];
    func_002AA020(self, buf);
    return buf[0];
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA448);
#ifdef SKIP_ASM
extern "C" int func_003B80E0(int, int);

extern "C" int func_002AA448(void *arg0, int arg1) {
    int temp_16;

    func_003B58A0();
    temp_16 = func_003B80E0((*(int *)((char*)(arg0) + (8))), arg1);
    func_003B58D8();
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", cStreamSys_cStreamSys);
#ifdef SKIP_ASM
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
extern "C" void* func_002ADE88(void* self, int heap);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern const char D_00483218[];
extern void* D_00483B48[];

struct sSsVEntryA490 {
    short delta;
    short index;
    void* fn;
};
struct sSsVtblAA490 {
    sSsVEntryA490 e[4];
} __attribute__((aligned(8)));
struct sSsVtblBA490 {
    sSsVEntryA490 e[7];
} __attribute__((aligned(8)));
extern const sSsVtblAA490 D_00483998;
extern const sSsVtblBA490 D_004839B8;

struct sStreamSysA490 {
    char* vbase;        // 0x0
    int count;          // 0x4
    void** items;       // 0x8
    char vb2[0x8];      // 0xC
    char vb[0x4];       // 0x14
};

extern "C" sStreamSysA490* cStreamSys_cStreamSys(sStreamSysA490* self, int inchrg, int banks, int count, int heap)
{
    if (inchrg) {
        self->vbase = self->vb;
        *(char**)(self->vb + 0x1D8) = self->vb2;
        func_002ADE88(self->vb2, heap);
        cBankManager_cBankManager(self->vbase, 0, banks, heap);
    }
    *(const sSsVtblAA490**)(*(char**)(self->vbase + 0x1D8) + 4) = &D_00483998;
    *(void***)(self->vbase + 0xAB0) = D_00483B48;
    *(const sSsVtblBA490**)(self->vbase + 0x1D4) = &D_004839B8;
    if (!inchrg) {
        // PORT: g++ 2.95 virtual-base this-adjust fix-ups (copied vtables on the stack), written out by hand.
        sSsVtblAA490 t1 = D_00483998;
        *(sSsVtblAA490**)(*(char**)(self->vbase + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(self->vbase + 0x1D8) - 0xC;
        int d1 = (char*)self - base1;
        t1.e[1].delta = D_00483998.e[1].delta + d1;
        sSsVtblBA490 t2 = D_004839B8;
        *(sSsVtblBA490**)(self->vbase + 0x1D4) = &t2;
        char* base2 = self->vbase - 0x14;
        int d2 = (char*)self - base2;
        t2.e[1].delta = D_004839B8.e[1].delta + d2;
    }
    self->count = count;
    self->items = new (D_00483218, 0, 0) void*[count];
    for (int i = 0; i < self->count; i++)
        self->items[i] = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA648);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002A9DF0(void* e, int a1);
extern "C" void func_002ADEE8(void* self, int flags);
extern void* D_00483B48[];

struct sSsVEntryA648 {
    short delta;
    short index;
    void* fn;
};
struct sSsVtblAA648 {
    sSsVEntryA648 e[4];
} __attribute__((aligned(8)));
struct sSsVtblBA648 {
    sSsVEntryA648 e[7];
} __attribute__((aligned(8)));
// Views of the vtables cStreamSys_cStreamSys (earlier in this unit) declares with its own types.
extern const sSsVtblAA648 D_00483998_A648 __asm__("D_00483998");
extern const sSsVtblBA648 D_004839B8_A648 __asm__("D_004839B8");

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002AA648(void* p, int flags)
{
    char* self = (char*)p;
    *(const sSsVtblAA648**)(*(char**)(*(char**)self + 0x1D8) + 4) = &D_00483998_A648;
    *(void***)(*(char**)self + 0xAB0) = D_00483B48;
    *(const sSsVtblBA648**)(*(char**)self + 0x1D4) = &D_004839B8_A648;
    if (flags == 0) {
        sSsVtblAA648 t1 = D_00483998_A648;
        *(sSsVtblAA648**)(*(char**)(*(char**)self + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(*(char**)self + 0x1D8) - 0xC;
        int d1 = self - base1;
        t1.e[1].delta = D_00483998_A648.e[1].delta + d1;
        sSsVtblBA648 t2 = D_004839B8_A648;
        *(sSsVtblBA648**)(*(char**)self + 0x1D4) = &t2;
        char* base2 = *(char**)self - 0x14;
        int d2 = self - base2;
        t2.e[1].delta = D_004839B8_A648.e[1].delta + d2;
    }
    for (int i = 0; i < *(int*)(self + 4); i++) {
        void* e = (*(void***)(self + 8))[i];
        if (e != 0) {
            func_002A9DF0(e, 3);
        }
    }
    if (*(void**)(self + 8) != 0) {
        cMemMan_free(*(void**)(self + 8));
    }
    if (flags & 2) {
        func_0028BB10(*(void**)self, 0);
        func_002ADEE8(*(void**)(*(char**)self + 0x1D8), 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA7F0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_00483228[];

extern "C" void func_002AA7F0(void* self, int idx, int heap, int extra)
{
    sStreamInst_99D8** slot = (sStreamInst_99D8**)((idx << 2) + *(int*)((char*)self + 0x8));
    void* mem = cMemMan_alloc(0x84, D_00483228, heap, 0);
    *slot = cStreamInstance_cStreamInstance((sStreamInst_99D8*)mem, (sSsPlayer_99D8*)(*(char**)self + 0x1D8), heap, extra);
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AA870);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern char D_00483228[];
extern "C" sStreamInst_99D8* func_002A9C00(sStreamInst_99D8* self, sSsPlayer_99D8* p, char* mem, int size, int n, int m);

extern "C" void func_002AA870(void* self, int idx, int heap, char* mem, int size, int n, int m)
{
    sStreamInst_99D8** slot = (sStreamInst_99D8**)((idx << 2) + *(int*)((char*)self + 0x8));
    void* obj = cMemMan_alloc(0x84, D_00483228, heap, 0);
    *slot = func_002A9C00((sStreamInst_99D8*)obj, (sSsPlayer_99D8*)(*(char**)self + 0x1D8), mem, size, n, m);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AA910);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);
extern "C" void func_002AA7F0(void* self, int a1, int a2, int a3);

struct sEntry_A910 {
    signed char kind;
    char pad[0x17];
};
struct sQuad_A910 {
    int a;
    int b;
    int c;
    int d;
};
struct sStack_A910 {
    int field_0x0;                  // 0x1D8
    sEntry_A910 cur;                // 0x1DC
    volatile int depth;             // 0x1F4
    sEntry_A910* entries;           // 0x1F8
    int flags[4];                   // 0x1FC
    int* a34;
    int* a38;
    int* a3C;
    char a40[4][8];
    int* a60;
    int* a64;
    int* a68;
    int* a6C;
    sQuad_A910* a70;
    int* a74;
    int* a78;
    int* a7C;
    int* a80;
    int* a84;
};
struct sMgr_A910 {
    char pad_0x0[0x1D8];
    sStack_A910 st;                 // 0x1D8
};

extern "C" void func_002AA910(sMgr_A910** self, int a1, int a2, int a3, int a4)
{
    sMgr_A910* m = *self;
    sStack_A910* st = &m->st;
    m->st.depth++;
    st->entries[m->st.depth] = m->st.cur;
    m->st.flags[m->st.depth] = 0;
    st->a34[m->st.depth] = 0;
    st->a38[m->st.depth] = st->entries[m->st.depth].kind;
    st->a3C[m->st.depth] = 0;
    func_00416210((char*)st + m->st.depth * 8 + 0x40, 0, 8);
    st->a60[m->st.depth] = 0;
    st->a64[m->st.depth] = 0;
    st->a68[m->st.depth] = 0;
    st->a6C[m->st.depth] = 0;
    st->a70[m->st.depth].b = 0;
    st->a70[m->st.depth].a = 100;
    st->a70[m->st.depth].c = 90;
    st->a70[m->st.depth].d = 50;
    st->a74[m->st.depth] = 0;
    st->a80[m->st.depth] = 0;
    st->a84[m->st.depth] = 0;
    st->a78[m->st.depth] = 127;
    st->a7C[m->st.depth] = 1;
    (*self)->st.a3C[(*self)->st.depth] = a2;
    func_002AA7F0(self, a1, a3, a4);
    (*self)->st.depth--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAB98);
#ifdef SKIP_ASM
extern "C" void func_002A9E78(void*, int);

extern "C" void func_002AAB98(void* self, int i, int val)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        func_002A9E78(e, val);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AABD0);
#ifdef SKIP_ASM
extern "C" void func_002A9DF0(void* e, int a1);

extern "C" void func_002AABD0(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        func_002A9DF0(e, 3);
    }
    (*(void***)((char*)self + 0x8))[i] = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAC28);
#ifdef SKIP_ASM
extern "C" void func_002A9F80(void* e);

extern "C" void func_002AAC28(void* self)
{
    for (int i = 0; i < *(int*)((char*)self + 0x4); i++) {
        void* e = (*(void***)((char*)self + 0x8))[i];
        if (e != 0) {
            func_002A9F80(e);
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AAC98);
#ifdef SKIP_ASM
extern "C" void func_002AA2B0(void* p);

extern "C" void func_002AAC98(void* self)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x4); i++) {
        void* p = *(void**)((char*)*(void**)((char*)self + 0x8) + i * 4);
        if (p != 0) {
            func_002AA2B0(p);
        }
    }
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AAD08);
#ifdef SKIP_ASM
extern "C" void func_002AA2E8(void* p);

extern "C" void func_002AAD08(void* self)
{
    int i;
    for (i = 0; i < *(int*)((char*)self + 0x4); i++) {
        void* p = *(void**)((char*)*(void**)((char*)self + 0x8) + i * 4);
        if (p != 0) {
            func_002AA2E8(p);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAD78);
#ifdef SKIP_ASM
extern "C" int func_002AA320(void* e, int a, int b, int c);

extern "C" int func_002AAD78(void* self, int i, int a, int b, int c)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        return func_002AA320(e, a, b, c);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AADC0);
#ifdef SKIP_ASM
extern "C" int func_002AA398(void*, int, int, int);

extern "C" int func_002AADC0(void* self, int idx, int arg2, int arg3, int arg4)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    if (stream != 0) {
        return func_002AA398(stream, arg2, arg3, arg4);
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAE08);
#ifdef SKIP_ASM
extern "C" int func_002AA428(void*);

extern "C" int func_002AAE08(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        return func_002AA428(e);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AAE40);
#ifdef SKIP_ASM
extern "C" void func_002AAE40(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        func_002AA408(e);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAE78);
#ifdef SKIP_ASM
extern "C" float func_002AA108(void* self);

extern "C" float func_002AAE78(void* self, int i)
{
    void* e;
    if (i < 0 || (e = (*(void***)((char*)self + 0x8))[i]) == 0) {
        return 0.0f;
    }
    return func_002AA108(e);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AAEC0);
#ifdef SKIP_ASM
extern "C" float func_002AA260(void*);

extern "C" float func_002AAEC0(void* self, int idx)
{
    void* stream;
    if (idx < 0 || (stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4)) == 0) {
        return 0.0f;
    }
    return func_002AA260(stream);
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AAF08);
#ifdef SKIP_ASM
extern "C" int func_002AA150(void*, int);

extern "C" int func_002AAF08(void* self, int idx, int arg2)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    return stream != 0 ? func_002AA150(stream, arg2) : 0;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AAF40);
#ifdef SKIP_ASM
extern "C" int func_002AA188(void*);

extern "C" int func_002AAF40(void* self, int idx)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    return stream != 0 ? func_002AA188(stream) : 0;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AAF78);
#ifdef SKIP_ASM
// PORT: the unit declares func_003B7C40(int, int); this call passes an out buffer
int func_003B7C40_pbuf(int h, int* out) __asm__("func_003B7C40");

extern "C" int func_002AAF78(void* self, int h)
{
    int st[4];
    int r;
    func_003B58A0();
    r = func_003B7C40_pbuf(h, st);
    func_003B58D8();
    return st[0] == 3 || r < 0;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AAFD0);
#ifdef SKIP_ASM
// PORT: the unit declares func_003B7C40(int, int); this call passes an out buffer
int func_003B7C40_pbuf(int h, int* out) __asm__("func_003B7C40");

extern "C" int func_002AAFD0(void* self, int h)
{
    int st[4];
    int r;
    func_003B58A0();
    r = func_003B7C40_pbuf(h, st);
    func_003B58D8();
    return st[0] == 2 && !(r < 0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AB028);
#ifdef SKIP_ASM
extern "C" int func_002AA1B8(void*);

extern "C" int func_002AB028(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        return func_002AA1B8(e);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB060);
#ifdef SKIP_ASM
extern "C" void func_002AA1E8(void*);

extern "C" void func_002AB060(void* self, int idx)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    if (stream != 0) {
        func_002AA1E8(stream);
    }
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AB098);
#ifdef SKIP_ASM
extern "C" void func_002AA240(void*, int);

extern "C" void func_002AB098(void* self, int idx, int arg2)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    if (stream != 0) {
        func_002AA240(stream, arg2);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB0D0);
#ifdef SKIP_ASM
extern "C" void func_002AB0D0(void* self, int i, int val)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        *(int*)((char*)e + 0x10) = val;
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB0F0);
#ifdef SKIP_ASM
extern "C" void func_002AB0F0(void* self, int idx, int val)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    if (stream != 0) {
        func_002A9F30(stream, val);
    }
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AB128);
#ifdef SKIP_ASM
extern "C" int func_002AB128(void* self, int idx)
{
    void* p = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    if (p != 0) {
        return *(int*)((char*)p + 0x8);
    }
    return -1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AB150);
#ifdef SKIP_ASM
extern "C" int func_002AA210(void*);

extern "C" int func_002AB150(void* self, int i)
{
    void* e = (*(void***)((char*)self + 0x8))[i];
    if (e != 0) {
        return func_002AA210(e);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB188__FPvi);
#ifdef SKIP_ASM
int func_002AB188(void* self, int a1)
{
    return *(int*)((char*)*(void**)((char*)self + 0x8) + a1 * 4);
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB1A0);
#ifdef SKIP_ASM
extern "C" int func_003B7D80(int, int);

extern "C" int func_002AB1A0(void* self, void* arg1)
{
    func_003B7D80(*(int*)((char*)arg1 + 0x1C), 0);
    return 1;
}
#endif
//100%
INCLUDE_ASM("sound/streamsys", func_002AB1C8);
#ifdef SKIP_ASM
extern "C" int func_002AA448(void*, int);

extern "C" int func_002AB1C8(void* self, int idx, int arg2)
{
    void* stream = *(void**)(*(char**)((char*)self + 0x8) + idx * 4);
    return stream != 0 ? func_002AA448(stream, arg2) : -1;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB200);
#ifdef SKIP_ASM
extern "C" void* func_002ADE88(void* self, int heap);
extern "C" void* cBankManager_cBankManager(void* self, int embedded, int count, int heap);
extern "C" void* func_002A69A0(void* self, int embedded, int a2, int a3, int heap);
extern "C" void* func_002B28C0(void* self, int embedded, int a2, int a3, int heap);
extern "C" void* func_002B07F8(void* self, int embedded, int a2, int a3, int heap);
extern void* D_004838F8[];
extern void* D_004837F8[];
extern void* D_00483870[];

struct sSsVEntryB200 {
    short delta;
    short index;
    void* fn;
};
struct sSsVtblAB200 {
    sSsVEntryB200 e[4];
} __attribute__((aligned(8)));
struct sSsVtblBB200 {
    sSsVEntryB200 e[8];
} __attribute__((aligned(8)));
struct sSsVtblCB200 {
    sSsVEntryB200 e[7];
} __attribute__((aligned(8)));
extern const sSsVtblAB200 D_004837D8_B200 __asm__("D_004837D8");
extern const sSsVtblBB200 D_00483760_B200 __asm__("D_00483760");
extern const sSsVtblCB200 D_004837A0_B200 __asm__("D_004837A0");

// PORT: g++ 2.95 virtual-base construction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" char* func_002AB200(char* self, int embedded, int a2, int a3, int heap)
{
    if (embedded != 0) {
        *(char**)(self + 0x5560) = self + 0x6200;
        *(char**)(self + 0x6200) = self + 0x5730;
        *(char**)(self + 0x0) = self + 0x5730;
        *(char**)(self + 0x5908) = self + 0x5728;
        *(char**)(self + 0x118) = self + 0x6200;
        func_002ADE88(self + 0x5728, heap);
        cBankManager_cBankManager(*(void**)(self + 0x6200), 0, a2, heap);
        cStreamSys_cStreamSys(*(sStreamSysA490**)(self + 0x5560), 0, a2, a3, heap);
    }
    func_002A69A0(self, 0, a2, a3, heap);
    func_002B28C0(self + 0x118, 0, a2, a3, heap);
    func_002B07F8(self + 0x5560, 0, a2, a3, heap);
    *(const sSsVtblAB200**)(*(char**)(**(char***)(self + 0x118) + 0x1D8) + 4) = &D_004837D8_B200;
    *(const sSsVtblBB200**)(**(char***)(self + 0x118) + 0xAB0) = &D_00483760_B200;
    *(const sSsVtblCB200**)(**(char***)(self + 0x118) + 0x1D4) = &D_004837A0_B200;
    if (embedded == 0) {
        sSsVtblAB200 t1 = D_004837D8_B200;
        *(sSsVtblAB200**)(*(char**)(**(char***)(self + 0x118) + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)(self + 0x118) + 0x1D8) - 0x5728;
        int d1 = self - base1;
        t1.e[1].delta = D_004837D8_B200.e[1].delta + d1;
        sSsVtblBB200 t2 = D_00483760_B200;
        *(sSsVtblBB200**)(**(char***)(self + 0x118) + 0xAB0) = &t2;
        char* base2 = **(char***)(self + 0x118) - 0x5730;
        int d2 = self - base2;
        t2.e[1].delta = D_00483760_B200.e[1].delta + d2;
        t2.e[5].delta = D_00483760_B200.e[5].delta + d2;
        sSsVtblCB200 t3 = D_004837A0_B200;
        *(sSsVtblCB200**)(**(char***)(self + 0x118) + 0x1D4) = &t3;
        t3.e[1].delta = D_004837A0_B200.e[1].delta + d2;
    }
    *(void***)(self + 0x5558) = D_004838F8;
    *(void***)(self + 0x571C) = D_00483870;
    *(void***)(self + 0xC) = D_004837F8;
    *(int*)(self + 0x5720) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB478);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern "C" void func_0028BB10(void* self, int flags);
extern "C" void func_002A6B50(void* self, int flags);
extern "C" void func_002AA648(void* self, int flags);
extern "C" void func_002ADEE8(void* self, int flags);
extern "C" void func_002B0AE8(char* self, int flags);
extern "C" void func_002B3398(char* self, int flags);
extern void* D_004838F8[];
extern void* D_004837F8[];
extern void* D_00483870[];

struct sSsVEntryB478 {
    short delta;
    short index;
    void* fn;
};
struct sSsVtblAB478 {
    sSsVEntryB478 e[4];
} __attribute__((aligned(8)));
struct sSsVtblBB478 {
    sSsVEntryB478 e[8];
} __attribute__((aligned(8)));
struct sSsVtblCB478 {
    sSsVEntryB478 e[7];
} __attribute__((aligned(8)));
extern const sSsVtblAB478 D_004837D8;
extern const sSsVtblBB478 D_00483760;
extern const sSsVtblCB478 D_004837A0;

// PORT: g++ 2.95 virtual-base destruction with stack vtable this-adjust fix-ups, written out by hand.
extern "C" void func_002AB478(char* self, int flags)
{
    char* mon = self + 0x118;
    char* bank = self + 0x5560;
    *(void***)(self + 0x5558) = D_004838F8;
    *(void***)(self + 0x571C) = D_00483870;
    *(void***)(self + 0xC) = D_004837F8;
    *(const sSsVtblAB478**)(*(char**)(**(char***)(self + 0x118) + 0x1D8) + 4) = &D_004837D8;
    *(const sSsVtblBB478**)(**(char***)(self + 0x118) + 0xAB0) = &D_00483760;
    *(const sSsVtblCB478**)(**(char***)(self + 0x118) + 0x1D4) = &D_004837A0;
    if (flags == 0) {
        sSsVtblAB478 t1 = D_004837D8;
        *(sSsVtblAB478**)(*(char**)(**(char***)(self + 0x118) + 0x1D8) + 4) = &t1;
        char* base1 = *(char**)(**(char***)(self + 0x118) + 0x1D8) - 0x5728;
        int d1 = self - base1;
        t1.e[1].delta = D_004837D8.e[1].delta + d1;
        sSsVtblBB478 t2 = D_00483760;
        *(sSsVtblBB478**)(**(char***)(self + 0x118) + 0xAB0) = &t2;
        char* base2 = **(char***)(self + 0x118) - 0x5730;
        int d2 = self - base2;
        t2.e[1].delta = D_00483760.e[1].delta + d2;
        t2.e[5].delta = D_00483760.e[5].delta + d2;
        sSsVtblCB478 t3 = D_004837A0;
        *(sSsVtblCB478**)(**(char***)(self + 0x118) + 0x1D4) = &t3;
        t3.e[1].delta = D_004837A0.e[1].delta + d2;
    }
    func_002B0AE8(bank, 0);
    func_002B3398(mon, 0);
    func_002A6B50(self, 0);
    if (flags & 2) {
        func_002AA648(*(void**)(self + 0x118), 0);
        func_0028BB10(**(void***)(self + 0x118), 0);
        func_002ADEE8(*(void**)(**(char***)(self + 0x118) + 0x1D8), 0);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB6B0);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void* self);
extern "C" void func_002AC868(void* voice, void* bm, float v);

class cStrmCbOwner {
public:
    virtual void dummy();
};

struct sStrmVoiceCb {
    char pad[0xA8];
    void (cStrmCbOwner::*cb)(void* voice, float v);
};

extern "C" void func_002AB6B0(void* voice, void* self, float v)
{
    if (func_002ABB80(voice) == 0 && v > 0.0f) {
        sStrmVoiceCb* sv = (sStrmVoiceCb*)voice;
        if (sv->cb) {
            (((cStrmCbOwner*)self)->*(sv->cb))(voice, v);
        }
        char* bm = 0;
        if (self) {
            char* snd = **(char***)((char*)self + 0x118);
            if (snd) {
                bm = snd;
                bm += 0x1D8;
            }
        }
        func_002AC868(voice, bm, v);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AB7A0);
#ifdef SKIP_ASM
extern "C" void func_002AB6B0(void* voice, void* self, float v);

extern "C" void func_002AB7A0(void* self, float v)
{
    if (*(int*)(**(char***)((char*)self + 0x118) + 0xAC0) != 0) {
        v = 0.0f;
    }
    for (int i = 0; i < 64; i++) {
        func_002AB6B0(*(char**)(**(char***)((char*)self + 0x118) + 0xAC4) + i * 0xC0, self, v);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB828);
#ifdef SKIP_ASM
extern "C" void func_002AD940(void* e);

class cStrmTickOwner {
public:
    virtual void dummy();
};

struct sStrmTick {
    int active;
    int period;
    int count;
    int (cStrmTickOwner::*cb)(sStrmTick* e);
};

extern "C" void func_002AB828(void* e, void* self)
{
    sStrmTick* t = (sStrmTick*)e;
    if (t->active) {
        if ((t->count -= 10) < 5) {
            if ((((cStrmTickOwner*)self)->*(t->cb))(t)) {
                func_002AD940(t);
            } else {
                t->count += t->period;
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AB8E8);
#ifdef SKIP_ASM
extern "C" void func_002ADC10(void* bm);
extern "C" void func_002AB828(void* e, void* self);

extern "C" void func_002AB8E8(void* self)
{
    char* snd = **(char***)((char*)self + 0x118);
    char* bm = snd + 0x1D8;
    if (*(int*)(snd + 0x26C) == 0) {
        func_002ADC10(bm);
        for (int i = 0; i < 48; i++) {
            func_002AB828(**(char***)((char*)self + 0x118) + 0x270 + i * 0x2C, self);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AB958);
#ifdef SKIP_ASM
extern "C" void func_0028AAF8(void* snd);
extern "C" void func_002A6D18(void* self);
extern "C" void func_002AAC28(void* self);
extern "C" void func_002B0C78(void* self);
extern "C" void func_002B4388(void* self);

struct sStrmVtEntF { short delta; short index; void (*fn)(void*, float); };

extern "C" void func_002AB958(void* self, float v)
{
    char** sys = (char**)((char*)self + 0x118);
    func_0028AAF8(*(void**)*sys);
    func_002A6D18(self);
    char* b = *(char**)*sys;
    char* o = b + 0x1D8;
    sStrmVtEntF* e = &(*(sStrmVtEntF**)(b + 0xAB0))[5];
    e->fn(o + e->delta, v);
    func_002B4388(sys);
    func_002B0C78((char*)self + 0x5560);
    func_002AAC28(*sys);
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AB9E0);
#ifdef SKIP_ASM
extern "C" void* func_002AB9E0(void* self)
{
    *(int*)((char*)self + 0xB0) = 0x8000;
    *(float*)((char*)self + 0x90) = -1.0f;
    *(int*)((char*)self + 0xB4) = -1;
    *(int*)((char*)self + 0xB8) = -30000;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABA18);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern "C" void func_002ABA18(int* self, int flags)
{
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABA40);
#ifdef SKIP_ASM
extern "C" unsigned int func_003B8AB8(int h);
extern "C" int func_003B9FC8(int h);
// PORT: the unit declares func_003B7C40(int, int); its second argument is a status buffer here.
int func_003B7C40_st(int h, int* st) __asm__("func_003B7C40");

extern "C" int func_002ABA40(void* self)
{
    int type = *(int*)self;
    switch (type) {
    case 1: {
        func_003B58A0();
        int r = func_003B8AB8(*(int*)((char*)self + 4)) != 0;
        func_003B58D8();
        return r;
    }
    case 2: {
        func_003B58A0();
        int r = func_003B9FC8(*(int*)((char*)self + 4));
        func_003B58D8();
        return r == 2 || r < 0;
    }
    case 3: {
        int st[4];
        func_003B58A0();
        if (func_003B7C40_st(*(int*)((char*)self + 4), st) >= 0) {
            func_003B58D8();
            return st[0] == 3;
        }
        func_003B58D8();
        return 1;
    }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABB38);
#ifdef SKIP_ASM
extern "C" void func_002AC180(void*);

extern "C" void func_002ABB38(void* self)
{
    func_002AC180(self);
    *(int*)((char*)self + 0xB0) = 0x8000;
    *(int*)((char*)self + 0xB4) = -1;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x54) = 0;
    *(int*)((char*)self + 0x58) = 0;
    *(int*)((char*)self + 0xB8) = 0xFFFF;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002ABB80);
#ifdef SKIP_ASM
extern "C" int func_002ABA40(void* self);
extern "C" void func_002ABB38(void* self);

extern "C" int func_002ABB80(void* self)
{
    if (*(int*)self == 0) {
        return 1;
    }
    if (*(int*)((char*)self + 0x9C) == 0) {
        return 0;
    }
    if (func_002ABA40(self) == 0) {
        return 0;
    }
    func_002ABB38(self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABBD8);
#ifdef SKIP_ASM
extern "C" float func_002ABBD8(void* self, float* a, float* b)
{
    float dx = a[0] - b[0];
    float dy = a[1] - b[1];
    float dz = a[2] - b[2];
    return dx * dx + dy * dy + dz * dz;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABC18);
#ifdef SKIP_ASM
// PORT: the unit declares func_002ABC18 as void*(int); the body takes (int, float, float).
int func_002ABC18_impl(int vol, float dist, float range) __asm__("func_002ABC18");

int func_002ABC18_impl(int vol, float dist, float range)
{
    dist = dist - 0.5f;
    if (dist < 0.0f) {
        dist = 0.0f;
    }
    int result = 0;
    if (dist < range && 0.0f < range) {
        float t = (range - dist) / range;
        result = (int)(t * t * (float)vol);
    }
    return result;
}
#endif

extern "C" void* func_002ABC18(int);

//100%
INCLUDE_ASM("sound/streamsys", func_002ABC80__FPvi);
#ifdef SKIP_ASM
void* func_002ABC80(void* self, int a1)
{
    return func_002ABC18(a1);
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABCA0);
#ifdef SKIP_ASM
extern "C" float func_002ABCA0(float a, float b)
{
    float f = a / b;
    if (f < -894.0799560546875f) {
        f = -894.0799560546875f;
    } else if (894.0799560546875f < f) {
        f = 894.0799560546875f;
    }
    return (f + 8000.0f) * 0.0001250000059371814f;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABCE8__FPvii);
#ifdef SKIP_ASM
void func_002ABCE8(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0xc) = a1;
    *(int*)((char*)self + 0x10) = a2;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABCF8);
#ifdef SKIP_ASM

extern "C" void func_002ABCF8(void* self, int a, const char* name, int b)
{
    *(int*)((char*)self + 0xC) = a;
    strcpy((char*)self + 0x10, name);
    *(int*)((char*)self + 0x50) = b;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABD38__FPvii);
#ifdef SKIP_ASM
void func_002ABD38(void* self, int a1, int a2)
{
    *(int*)((char*)self + 0xc) = a1;
    *(int*)((char*)self + 0x10) = a2;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABD48);
#ifdef SKIP_ASM
class func_002ABD48_cObj {
public:
    char pad[0x8D8];
    // vptr at 0x8D8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual float v06(void* a, void* out);
};

extern "C" void func_002ABD48(void* self, func_002ABD48_cObj* obj)
{
    char buf[0x20];
    float d;
    float d2 = obj->v06(self, buf);
    // PORT: sqrt.s (sqrtf without errno check)
    __asm__("sqrt.s %0, %1" : "=f"(d) : "f"(d2));
    *(float*)((char*)self + 0x5C) = d;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002ABD90);
#ifdef SKIP_ASM
extern "C" void func_002A9ED8(void* s, int pos, int a2);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B8C00(int h, int pos, int a2);
extern "C" int func_003B9C20(int h, int pos);

extern "C" void func_002ABD90(void* self, int pos, int a2)
{
    int d = pos - *(int*)((char*)self + 0xB8);
    if (d >= -0x1FF && d <= 0x1FF) {
        return;
    }
    *(int*)((char*)self + 0xB8) = pos;
    switch (*(int*)self) {
    case 1:
        func_003B58A0();
        func_003B8C00(*(int*)((char*)self + 0x4), pos, a2);
        func_003B58D8();
        break;
    case 2:
        func_003B58A0();
        func_003B9C20(*(int*)((char*)self + 0x4), pos);
        func_003B58D8();
        break;
    case 3:
        func_002A9ED8(*(void**)((char*)self + 0xC), pos, a2);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002ABE78);
#ifdef SKIP_ASM
extern "C" void func_002A9F38(void* s, int vol);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B8790(int h, int vol);
extern "C" int func_003B9B68(int h, int vol);

extern "C" void func_002ABE78(void* self, int vol)
{
    if (vol > 0x3FFF) {
        vol = 0x3FFF;
    }
    if (vol < 0) {
        vol = 0;
    }
    int d = vol - *(int*)((char*)self + 0xB0);
    if (d >= -0xFF && d <= 0xFF) {
        return;
    }
    *(int*)((char*)self + 0xB0) = vol;
    switch (*(int*)self) {
    case 1:
        func_003B58A0();
        func_003B8790(*(int*)((char*)self + 0x4), vol);
        func_003B58D8();
        break;
    case 2:
        func_003B58A0();
        func_003B9B68(*(int*)((char*)self + 0x4), vol);
        func_003B58D8();
        break;
    case 3:
        func_002A9F38(*(void**)((char*)self + 0xC), vol);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ABF60);
#ifdef SKIP_ASM
void func_002A9F30(void* self, int val);
void* func_002AA408(void* self);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B85F0(int h, int a);
extern "C" void func_003B89E0(int h);
extern "C" int func_003B9920(int h);
extern "C" int func_003B9E48(int h, int a);

extern "C" void func_002ABF60(void* self, int vol)
{
    int orig = vol;
    switch (*(int*)self) {
    case 1: {
        if (*(float*)((char*)self + 0x90) >= 0.0f)
            vol = (int)(*(float*)((char*)self + 0x90) * (float)vol);
        if (vol > 127)
            vol = 127;
        int none = -1;
        if (vol <= none)
            vol = 0;
        if (*(int*)((char*)self + 0xB4) >= 0) {
            int d = vol - *(int*)((char*)self + 0xB4);
            if (d >= -4 && d <= 4)
                return;
        }
        *(int*)((char*)self + 0xB4) = vol;
        func_003B58A0();
        if (orig == none)
            func_003B89E0(*(int*)((char*)self + 0x4));
        else
            func_003B85F0(*(int*)((char*)self + 0x4), vol);
        func_003B58D8();
        break;
    }
    case 2: {
        if (*(float*)((char*)self + 0x90) >= 0.0f)
            vol = (int)(*(float*)((char*)self + 0x90) * (float)vol);
        if (vol > 127)
            vol = 127;
        int none = -1;
        if (vol <= none)
            vol = 0;
        if (*(int*)((char*)self + 0xB4) >= 0) {
            int d = vol - *(int*)((char*)self + 0xB4);
            if (d >= -4 && d <= 4)
                return;
        }
        *(int*)((char*)self + 0xB4) = vol;
        func_003B58A0();
        if (orig == none)
            func_003B9920(*(int*)((char*)self + 0x4));
        else
            func_003B9E48(*(int*)((char*)self + 0x4), vol);
        func_003B58D8();
        break;
    }
    case 3: {
        if (*(float*)((char*)self + 0x90) >= 0.0f)
            vol = (int)(*(float*)((char*)self + 0x90) * (float)vol);
        if (vol > 127)
            vol = 127;
        int none = -1;
        if (vol <= none)
            vol = 0;
        if (*(int*)((char*)self + 0xB4) >= 0) {
            int d = vol - *(int*)((char*)self + 0xB4);
            if (d >= -4 && d <= 4)
                return;
        }
        *(int*)((char*)self + 0xB4) = vol;
        if (orig == none)
            func_002AA408(*(void**)((char*)self + 0xC));
        else
            func_002A9F30(*(void**)((char*)self + 0xC), vol);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AC180);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B8530(int h, int a, int b);
extern "C" int func_003B9F38(int h, int a, int b);

extern "C" void func_002AC180(void* self)
{
    if (*(int*)((char*)self + 0x54) != 0) {
        return;
    }
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x54) = 1;
    switch (*(int*)self) {
    case 1:
        func_003B58A0();
        func_003B8530(*(int*)((char*)self + 0x4), 0x19, -1);
        func_003B58D8();
        break;
    case 2:
        func_003B58A0();
        func_003B9F38(*(int*)((char*)self + 0x4), 0x19, -1);
        func_003B58D8();
        break;
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AC220);
#ifdef SKIP_ASM
struct sSsEntry {
    signed char first;          // 0x0
    char rest[0x17];
};
struct sSs4 {
    int a, b, c, d;
};
struct sSsMgr {
    int pad0;
    sSsEntry proto;             // 0x4
    volatile int idx;           // 0x1C
    sSsEntry* entries;          // 0x20
    int a24[4];                 // 0x24
    int* p34;                   // 0x34
    int* p38;                   // 0x38
    int* p3C;                   // 0x3C
    char a40[4][8];             // 0x40
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    sSs4* p70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
struct sSsPlay {
    int kind;                   // 0x0
    int result;                 // 0x4
    int f8;                     // 0x8
    int f0C;
    int f10;
    char pad14[0x54 - 0x14];
    int f54;
    char pad58[0x60 - 0x58];
    int f60;
};
extern "C" void* func_00416210(void* p, int v, int n);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B6820(int a, int b, void* e);
extern "C" int func_003B9A00(void* e, int a, int b, int c);

static inline void ssAlloc_C220(sSsPlay* p, sSsMgr* m)
{
    m->idx++;
    m->entries[m->idx] = m->proto;
    m->a24[m->idx] = 0;
    m->p34[m->idx] = 0;
    m->p38[m->idx] = m->entries[m->idx].first;
    m->p3C[m->idx] = 0;
    func_00416210((char*)m + m->idx * 8 + 0x40, 0, 8);
    m->p60[m->idx] = 0;
    m->p64[m->idx] = 0;
    m->p68[m->idx] = 0;
    m->p6C[m->idx] = 0;
    m->p70[m->idx].b = 0;
    m->p70[m->idx].a = 100;
    m->p70[m->idx].c = 90;
    m->p70[m->idx].d = 50;
    m->p74[m->idx] = 0;
    m->p80[m->idx] = 0;
    m->p84[m->idx] = 0;
    m->p78[m->idx] = 0x7F;
    m->p7C[m->idx] = 1;
    m->p3C[m->idx] = p->f60;
    m->p38[m->idx] = 0;
    sSsEntry* e = (sSsEntry*)(m->idx * 0x18 + (int)m->entries);
    unsigned char c;
    if (m->p38[m->idx] >= 0x7F || m->p38[m->idx] >= 0) {
        if (m->p38[m->idx] < 0x7F)
            c = m->p38[m->idx];
        else
            c = 0x7F;
    } else {
        c = 0;
    }
    e->first = c;
}

extern "C" void func_002AC220_impl(sSsPlay* p, sSsMgr* m) __asm__("func_002AC220");

void func_002AC220_impl(sSsPlay* p, sSsMgr* m)
{
    int r;
    p->f8 = 1;
    p->f54 = 0;
    switch (p->kind) {
    case 1: {
        ssAlloc_C220(p, m);
        func_003B58A0();
        r = func_003B6820(p->f0C, p->f10, &m->entries[m->idx]);
        break;
    }
    case 2: {
        ssAlloc_C220(p, m);
        func_003B58A0();
        r = func_003B9A00(&m->entries[m->idx], p->f0C, p->f10, -1);
        break;
    }
    case 3:
    default:
        return;
    }
    p->result = r;
    func_003B58D8();
    m->idx--;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002AC7F0);
#ifdef SKIP_ASM
extern "C" void func_002AC180(void*);
extern "C" void func_002AC220(void*);

extern "C" int func_002AC7F0(void* self, float t)
{
    float th = *(float*)((char*)self + 0x8C);
    if (th == 0.0f) {
        return 1;
    }
    if (*(int*)((char*)self + 0x8) != 0) {
        if (th < t) {
            func_002AC180(self);
            return 0;
        }
        return 1;
    }
    if (t < th) {
        func_002AC220(self);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002AC868);
#ifdef SKIP_ASM
class cStreamBM_C868 {
public:
    char pad[0x8D8];
    // vptr at 0x8D8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual float v06(void* a, void* out);
};
struct sPos_C868 {
    int a;
    int b;
    unsigned short pos;     // 0x8
    short pos2;             // 0xA
    int c[5];
};
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
// PORT: the unit declares func_003B7C40(int, int); its second argument is a status buffer here.
int func_003B7C40_st(int h, int* st) __asm__("func_003B7C40");
extern "C" int func_002ABA40(void* self);
extern "C" void func_002ABD90(void* self, int pos, int a2);
extern "C" void func_002ABE78(void* self, int a1);
extern "C" void func_002ABF60(void* self, int a1);
// PORT: these callees are declared with fewer parameters elsewhere in the unit; the caller passes the extra registers.
int func_002ABC80_4(void* self, int vol, float dist, float range) __asm__("func_002ABC80__FPvi");
float func_002ABCA0_3(void* self, float a, float b) __asm__("func_002ABCA0");
int func_002AC7F0_3(void* self, void* bm, float t) __asm__("func_002AC7F0");

// PORT: PS2 sqrt.s asm helper; use sqrtf on PC.
static inline float Sqrt_C868(float x)
{
    float r;
    __asm__("sqrt.s %0,%1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_002AC868(void* voice, void* bm, float v)
{
    char* s = (char*)voice;
    char* b = (char*)bm;
    if (*(int*)s == 0) {
        return;
    }
    int st[4];
    sPos_C868 pos;
    int vol = 0;
    if (*(int*)s == 3) {
        func_003B58A0();
        int r = func_003B7C40_st(*(int*)(s + 0x4), st);
        func_003B58D8();
        if (r <= 0 && st[0] != 2) {
            return;
        }
    }
    if (*(int*)(b + 0x8E4) != 0 && *(int*)(s + 0x68) != 0) {
        float d = Sqrt_C868(((cStreamBM_C868*)bm)->v06(voice, &pos));
        if (*(int*)(s + 0x94) != 0 || func_002AC7F0_3(voice, bm, d) != 0) {
            float f = *(float*)(s + 0x5C);
            if (f != -1.0f && *(int*)(b + 0x8E0) != 0) {
                v = func_002ABCA0_3(voice, f - d, v);
            } else {
                v = 1.0f;
            }
            func_002ABD90(voice, pos.pos, pos.pos2);
            func_002ABE78(voice, (int)(v * 4096.0f));
            if (*(int*)(s + 0x94) != 0) {
                vol = *(int*)(s + 0x64);
            } else {
                float range = *(float*)(s + 0x88);
                if (range == 0.0f) {
                    vol = func_002ABC80_4(voice, *(int*)(s + 0x64), d, 30.0f);
                } else {
                    vol = func_002ABC80_4(voice, *(int*)(s + 0x64), d, range);
                }
                int m = *(int*)(s + 0x98);
                if (m != 0x7F) {
                    vol = vol * 0x7F / m;
                    if (vol > 0x7F) {
                        vol = 0x7F;
                    }
                    if (vol < 0) {
                        vol = 0;
                    }
                }
            }
        }
        if (vol > 0x7F) {
            vol = 0x7F;
        }
        if (vol < 0) {
            vol = 0;
        }
        *(float*)(s + 0x5C) = d;
    } else {
        vol = *(int*)(s + 0x64);
    }
    if (*(int*)(s + 0x54) == 0) {
        float* p = *(float**)(s + 0x60);
        if (p != 0) {
            vol = (int)((float)vol * *p);
        }
        func_002ABF60(voice, vol);
        return;
    }
    if (func_002ABA40(voice) != 0) {
        *(int*)(s + 0x8) = 0;
        *(int*)(s + 0x54) = 0;
        *(int*)(s + 0x4) = -1;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002ACAC8);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void* self);
extern "C" void func_002ABE78(void* self, int a1);
extern "C" void func_002ABF60(void* self, int a1);
extern "C" int func_003B9D00(int h);

extern "C" void func_002ACAC8(void* self)
{
    if (func_002ABB80(self) == 0 && *(int*)((char*)self + 0x54) == 0) {
        func_002ABE78(self, 0);
        func_002ABF60(self, 0);
        if (*(int*)((char*)self + 0x0) == 2) {
            func_003B9D00(*(int*)((char*)self + 0x4));
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("sound/streamsys", func_002ACB30);
#ifdef SKIP_ASM
extern "C" int func_002ABB80(void* self);
extern "C" void func_002ABE78(void* self, int a1);
extern "C" int func_003B9DC8(int h);

extern "C" void func_002ACB30(void* self)
{
    if (func_002ABB80(self) == 0) {
        func_002ABE78(self, 0x1000);
        if (*(int*)self == 2) {
            func_003B9DC8(*(int*)((char*)self + 0x4));
        }
    }
}
#endif

//100%
INCLUDE_ASM("sound/streamsys", func_002ACB80);
#ifdef SKIP_ASM
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B8530(int h, int a, int b);
extern "C" int func_003B85F0(int h, int a);
extern "C" int func_003B9E48(int h, int a);
extern "C" int func_003B9F38(int h, int a, int b);
void* func_002AA408(void* self);
void func_002A9F30(void* self, int val);

extern "C" void func_002ACB80(void* self, int n, int a2, float t)
{
    if (a2) {
        *(int*)((char*)self + 0x58) = 1;
        *(int*)((char*)self + 0x9C) = 1;
    }
    if (*(int*)((char*)self + 0x54) != 0) {
        return;
    }
    if (n == -1) {
        *(int*)((char*)self + 0x54) = 1;
    } else {
        if (n > 127) {
            n = 127;
        }
        if (n < 0) {
            n = 0;
        }
    }
    switch (*(int*)self) {
    case 1:
        func_003B58A0();
        if (t != 0.0f) {
            func_003B8530(*(int*)((char*)self + 0x4), (int)(t * 100.0f), n);
        } else {
            func_003B85F0(*(int*)((char*)self + 0x4), n);
        }
        func_003B58D8();
        break;
    case 2:
        func_003B58A0();
        if (t != 0.0f) {
            func_003B9F38(*(int*)((char*)self + 0x4), (int)(t * 100.0f), n);
        } else {
            func_003B9E48(*(int*)((char*)self + 0x4), n);
        }
        func_003B58D8();
        break;
    case 3:
        if (*(int*)((char*)self + 0x54) != 0) {
            func_002AA408(*(void**)((char*)self + 0xC));
        } else {
            func_002A9F30(*(void**)((char*)self + 0xC), n);
        }
        break;
    }
}
#endif

