#include "common.h"

//100%
INCLUDE_ASM("mem/memstd", MEMCLASS_create);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
// PORT: debugmenu defines MEM_initblock with a short flags parameter; this caller passes the int unconverted.
extern "C" void* MEM_initblock(void* self, const char* name, int size, int hdr, int flags, void* prev, void* next);
extern "C" void* func_003E6448(void* dst, int value, int size);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int func_003E5698(void* sema);
extern char D_004A2E38[];
extern char D_004A2E40[];
extern void* D_004D2438[];

struct sMemNode_251718 {
    unsigned short tag;
    unsigned short flags;
    int size;
    char* end;
    void* fC;
    sMemNode_251718* next;
    sMemNode_251718* prev;
};

struct sMemClass_251718 {
    char name[8];
    sMemNode_251718* first;     // 0x8
    sMemNode_251718* last;      // 0xC
    sMemNode_251718 head;       // 0x10
    int f28;                    // 0x28
    int align;                  // 0x2C
    int hdr;                    // 0x30
    int flags;                  // 0x34
    int locked;                 // 0x38
    int sema[5];                // 0x3C
};

extern "C" int MEMCLASS_create(int id, char* name, char* mem, int size, int f28, int align, int hdr, int a7, int a8, int lock)
{
    char buf[0x100];
    int flags = id;
    if (a7) {
        flags |= 0x2000;
    }
    if (a8) {
        flags |= 0x1000;
    }
    char* data = mem;
    data += hdr + 0x60;
    data += align + 0x2F;
    data = (char*)((int)data & -align);
    char* end = mem + size;
    end -= hdr + 0x30;
    sprintf(buf, D_004A2E38, name);
    sMemNode_251718* blk = (sMemNode_251718*)(data - 0x10);
    sMemClass_251718* cls = (sMemClass_251718*)(mem + 0x10);
    MEM_initblock(mem, buf, 0x50, hdr, flags | 0x8000, 0, blk);
    MEM_initblock(blk, 0, end - (char*)blk - 0x10, hdr, flags, mem, end);
    sprintf(buf, D_004A2E40, name);
    MEM_initblock(end, buf, 0, hdr, flags | 0x8100, blk, 0);
    D_004D2438[id & 0x3F] = cls;
    func_003E6448(cls, 0, 0x50);
    strcpy(cls->name, name);
    *(char**)(mem + 0x1C) = end;
    *(char**)(mem + 0x18) = mem;
    cls->first->tag = 0x4253;
    cls->last->tag = 0x4253;
    *(unsigned short*)(mem + 0x20) = 0x4253;
    *(int*)(mem + 0x24) = 0x7FFFFFFF;
    *(int*)(mem + 0x38) = f28;
    *(int*)(mem + 0x3C) = align;
    *(int*)(mem + 0x40) = hdr;
    *(int*)(mem + 0x44) = flags;
    sMemNode_251718* h = (sMemNode_251718*)(mem + 0x20);
    *(sMemNode_251718**)(mem + 0x30) = h;
    *(sMemNode_251718**)(mem + 0x34) = h;
    *(int*)(mem + 0x48) = 0;
    sMemNode_251718* q = h;
    sMemNode_251718* p = q;
    int sz = *(char**)(data - 8) - (char*)blk;
    if (*(char**)(mem + 0x30) + (*(char**)(mem + 0x34) - *(char**)(mem + 0x30)) / 2 < (char*)blk) {
        do
            p = p->prev;
        while (blk < p);
        q = p->next;
    } else {
        do
            q = q->next;
        while (q < blk);
        p = q->prev;
    }
    blk->size = sz;
    blk->next = q;
    blk->prev = p;
    p->next = blk;
    q->prev = blk;
    blk->tag = 0x4246;
    blk->flags |= 0x4000;
    if (lock) {
        func_003E5698(cls->sema);
        cls->locked = 1;
    }
    return blk->size;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00251998);
#ifdef SKIP_ASM
extern "C" void func_003E56E0(void*);

extern "C" int func_00251998(int id)
{
    void** slot = &D_004D2438[id & 0x3F];
    sMemClass_251718* cls = (sMemClass_251718*)*slot;
    int r = 0;
    if (cls != 0) {
        if (cls->locked != 0) {
            func_003E56E0(cls->sema);
        }
        func_003E6448(cls, 0, 0x50);
        *slot = 0;
        r = 1;
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251A08);
#ifdef SKIP_ASM
extern "C" void* func_002523A8(void* self);
struct sMemNode_251A08 {
    unsigned short tag;
    unsigned short flags;
    int size;
    sMemNode_251A08* next;
};

struct sMemClass_251A08 {
    char pad0[0x8];
    sMemNode_251A08* first;     // 0x8
};

extern "C" void* func_00251A08(int id)
{
    sMemClass_251A08* cls = (sMemClass_251A08*)D_004D2438[id & 0x3F];
    void* r = (void*)1;
    for (sMemNode_251A08* n = cls->first; n != 0 && r != 0; n = n->next) {
        if (!(n->flags & 0xC000)) {
            r = func_002523A8((char*)n + 0x10);
        }
    }
    return r;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251A80);
#ifdef SKIP_ASM
extern "C" int func_00251A80(void)
{
    int i = 2;
    while (i < 0x40 && D_004D2438[i] != 0) {
        i++;
    }
    return i;
}
#endif

INCLUDE_ASM("mem/memstd", func_00251AC0);

INCLUDE_ASM("mem/memstd", func_00251B50);

INCLUDE_ASM("mem/memstd", func_00251BB0);
//100%
INCLUDE_ASM("mem/memstd", func_00251C38);
#ifdef SKIP_ASM
struct sMemNode_251C38 {
    unsigned short tag;
    unsigned short flags;
    int size;
    sMemNode_251C38* next;
};

struct sMemClass_251C38 {
    char pad0[0x8];
    sMemNode_251C38* first;     // 0x8
};

int func_00252658(void* self);
extern "C" int func_0041AA88(int, int);

extern "C" void* func_00251C38(int name)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        sMemClass_251C38* cls = (sMemClass_251C38*)D_004D2438[i & 0x3F];
        if (cls != 0) {
            sMemNode_251C38* n = cls->first;
            void* data = (char*)n + 0x10;
            do {
                int s = func_00252658(data);
                if (s != 0 && func_0041AA88(s, name) == 0) {
                    return data;
                }
                n = n->next;
                data = (char*)n + 0x10;
            } while (n != 0);
        }
    }
    return 0;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251CF0);
#ifdef SKIP_ASM
extern "C" int func_00251CF0(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251CF8);
#ifdef SKIP_ASM
extern "C" int func_00251CF8(void) {
    return 0;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251D00);
#ifdef SKIP_ASM
extern "C" void func_00251D00(void) {

}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00251D08);
#ifdef SKIP_ASM
extern char D_004A2E48[];

extern "C" int func_00251D08(char* mem, int size)
{
    return MEMCLASS_create(0, D_004A2E48, mem, size, 0x40, 0x80, 0, 0, 0, 1);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", MEMCLASS_link);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
// PORT: debugmenu defines MEM_initblock with a short flags parameter; this caller passes the int unconverted.
extern "C" void* MEM_initblock(void* self, const char* name, int size, int hdr, int flags, void* prev, void* next);
extern char D_004A2E50[];
extern char D_004A2E40[];

struct sMemNode_251D50 {
    unsigned short tag;
    unsigned short flags;
    int size;
    char* end;
    void* fC;
    sMemNode_251D50* next;
    sMemNode_251D50* prev;
};

struct sMemClass_251D50 {
    char pad0[0xC];
    char* last;                 // 0xC
    sMemNode_251D50 head;       // 0x10
    int f28;
    int align;                  // 0x2C
    int hdr;                    // 0x30
    int flags;                  // 0x34
};

extern void* D_004D2438[];

extern "C" int MEMCLASS_link(int id, char* mem, int size)
{
    sMemClass_251D50* cls = (sMemClass_251D50*)D_004D2438[id & 0x3F];
    char buf[0x100];
    int hdr = cls->hdr;
    int align = cls->align;
    char* end = mem + size;
    char* data = mem;
    data += hdr + 0x10;
    data += align + 0x2F;
    data = (char*)((int)data & -align);
    end -= hdr + 0x30;
    int flags = cls->flags;
    sMemNode_251D50* blk = (sMemNode_251D50*)(data - 0x10);
    char* last = cls->last;
    sprintf(buf, D_004A2E50, cls);
    MEM_initblock(last, buf, 0, hdr, flags | 0x8000, *(void**)(last + 0xC), mem);
    MEM_initblock(mem, buf, 0, hdr, flags | 0x8000, last, blk);
    MEM_initblock(blk, 0, end - (char*)blk - 0x10, hdr, flags, mem, end);
    sprintf(buf, D_004A2E40, cls);
    MEM_initblock(end, buf, 0, hdr, flags | 0x8100, blk, 0);
    cls->last = end;
    sMemNode_251D50* q = &cls->head;
    sMemNode_251D50* p = q;
    int sz = *(char**)(data - 8) - (char*)blk;
    if ((char*)cls->head.next + ((char*)cls->head.prev - (char*)cls->head.next) / 2 < (char*)blk) {
        do
            p = p->prev;
        while (blk < p);
        q = p->next;
    } else {
        do
            q = q->next;
        while (q < blk);
        p = q->prev;
    }
    blk->size = sz;
    blk->next = q;
    blk->prev = p;
    p->next = blk;
    q->prev = blk;
    blk->tag = 0x4246;
    blk->flags |= 0x4000;
    return 1;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00251F68);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
typedef char* func_00251F68_va_list;
#define func_00251F68_va_start(ap)                                       \
    (ap = (char*)__builtin_next_arg()                                    \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))

extern "C" int func_004186C8(char* dst, const char* fmt, char* ap);
extern "C" void func_003E5D30(int, char*);

extern "C" void func_00251F68(const char* fmt, ...)
{
    char buf[0x200];
    func_00251F68_va_list ap;
    func_00251F68_va_start(ap);
    func_004186C8(buf, fmt, ap);
    func_003E5D30(2, buf);
}
#endif

extern const char D_004800A8[];
extern "C" void MEM_printclassf(void* thing, const char* fmt, void (*cb)(const char*, ...));

//100%
INCLUDE_ASM("mem/memstd", MEM_printclass__FPv);
#ifdef SKIP_ASM
void MEM_printclass(void* thing)
{
    MEM_printclassf(thing, D_004800A8, func_00251F68);
}
#endif

extern void* D_004A2E78;

//99.25%
INCLUDE_ASM("mem/memstd", MEM_print__Fv);
#ifdef SKIP_ASM
void MEM_print()
{
    MEM_printclass(D_004A2E78);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", MEM_printclassf);
#ifdef SKIP_ASM
int func_00252658(void* self);
extern "C" int func_00252660(void* p);
struct sMemBlock002522B0;
extern "C" int func_002522B0(sMemBlock002522B0* blk);
extern "C" int func_003E62D0(void* p, int size, int seed);
extern char D_004800E0[];
extern char D_00480140[];
extern char D_00480198[];
extern char D_004801B0[];
extern char D_004801C0[];
extern char* D_004801E8[];
extern char D_004A2E58[];
extern char D_004A2E60[];
extern char D_004A2E68[];
extern char D_004A2E70[];

struct sMemNode_252010 {
    unsigned short tag;
    unsigned short flags;
    int size;
    char* next;
    void* fC;
};

struct sMemClass_252010 {
    char pad0[0x8];
    sMemNode_252010* first;     // 0x8
};

extern void* D_004D2438[];

// PORT: thing is a memory class id (masked with 0x3F) passed through a void* parameter.
extern "C" void MEM_printclassf(void* thing, const char* fmt, void (*cb)(const char*, ...))
{
    int total = 0;
    int crc = 0;
    cb(D_004800E0);
    cb(D_00480140);
    sMemClass_252010* cls = (sMemClass_252010*)D_004D2438[(int)thing & 0x3F];
    if (cls == 0) {
        cb(D_00480198);
        return;
    }
    for (sMemNode_252010* blk = cls->first; blk != 0; blk = (sMemNode_252010*)blk->next) {
        char* data = (char*)blk + 0x10;
        char* n1 = (char*)func_00252658(data);
        if (n1 == 0)
            n1 = D_004A2E58;
        char* n2 = (char*)func_00252660(data);
        if (n2 == 0)
            n2 = D_004A2E58;
        if (blk->flags & 0x4000) {
            int sz = blk->size;
            if (sz > 0x10 && !(blk->flags & 0x8000))
                crc = func_003E62D0((char*)blk + 0x18, sz - 0x18, 0xFBEA);
            total += sz;
            int st = func_002522B0((sMemBlock002522B0*)blk);
            cb(fmt, D_004A2E60, D_004801B0, data, sz, blk->next - (char*)blk, blk->flags, crc, D_004801E8[st], D_004A2E58);
        } else {
            int sz = blk->size;
            crc = 0;
            if (sz != 0 && !(blk->flags & 0x8000))
                crc = func_003E62D0(data, sz, 0xFBEA);
            int st = func_002522B0((sMemBlock002522B0*)blk);
            cb(fmt, D_004A2E68, n1, data, blk->size, blk->next - (char*)blk, blk->flags, crc, D_004801E8[st], n2);
        }
        cb(D_004A2E70);
    }
    cb(D_004801C0, total, total);
    cb(D_00480140);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00252248);
#ifdef SKIP_ASM
extern int D_004A2E74;
extern "C" int func_003E6240(void* p, int size, int flags);

extern "C" int func_00252248(void* self)
{
    int ok = 0;
    if (func_003E6240(self, 0x18, 0) != 0) {
        unsigned short m = *(unsigned short*)self;
        if (m == 0x4246 || m == 0x4253) {
            ok = 1;
        } else {
            D_004A2E74 = 1;
        }
    } else {
        D_004A2E74 = 1;
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002522B0);
#ifdef SKIP_ASM
struct sMemBlock002522B0 {
    unsigned short tag;
    unsigned short flags;
    int size;
    int f8;
    int fC;
    void* a;
    void* b;
};

static inline unsigned int readBE32_002522B0(unsigned char* p)
{
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

// PORT: the block-end address is computed as size + (int)blk (pointer held in int) to get the target's addu operand order.
extern "C" int func_002522B0(sMemBlock002522B0* blk)
{
    int ok = 0;
    unsigned short tag = blk->tag;
    if (tag == 0x4253) {
        if (blk->flags & 0x8000) {
            ok = 1;
        } else {
            D_004A2E74 = 2;
        }
    } else if (tag == 0x4246) {
        if (blk->flags & 0x4000) {
            ok = func_00252248(blk->a);
            if (ok) {
                ok = func_00252248(blk->b);
            }
        }
    } else if (tag == 0x424D) {
        if (!(blk->flags & 0x2000) || readBE32_002522B0((unsigned char*)(blk->size + (int)blk) + 0x10) == 0x42454E44) {
            ok = 1;
        } else {
            D_004A2E74 = 3;
        }
    } else {
        D_004A2E74 = 4;
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002523A0);
#ifdef SKIP_ASM
extern "C" int func_002523A0(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002523A8);
#ifdef SKIP_ASM
void cMemMan_free(void*);

extern "C" void* func_002523A8(void* self)
{
    if (self != 0) {
        cMemMan_free(self);
    }
    return (void*)1;
}
#endif

INCLUDE_ASM("mem/memstd", func_002523D0);
//100%
INCLUDE_ASM("mem/memstd", func_002525F8);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" int func_00319B98(int);
extern void* D_00538B00[16];

extern "C" int func_002525F8(int arg0) {
    int temp_17;

    MUTEX_lock(&D_00538B00);
    temp_17 = func_00319B98(arg0);
    MUTEX_unlock(&D_00538B00);
    return temp_17;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00252648);
#ifdef SKIP_ASM
extern "C" int func_00252648(void *arg0) {
    return (*(int *)((char*)(arg0) + (-0xC)));
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00252650);
#ifdef SKIP_ASM
extern "C" unsigned short func_00252650(void *arg0) {
    return (*(unsigned short *)((char*)(arg0) + (-0xE)));
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00252658__FPv);
#ifdef SKIP_ASM
int func_00252658(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00252660);
#ifdef SKIP_ASM
struct sMemUnalignedInt {
    int value;
} __attribute__((packed));

// PORT: pointer arithmetic done in int; a plain `(char*)p - 0xE` makes gcc 2.95
// emit the offset as unsigned 0xFFFFFFF2 (addiu -0x8000 / 0x7ff2 split).
extern "C" int func_00252660(void* p)
{
    int r = 0;
    if (*(unsigned short*)((int)p - 0xE) & 0x800) {
        r = ((sMemUnalignedInt*)((char*)p + *(int*)((int)p - 0xC) + 4))->value;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00252688);
#ifdef SKIP_ASM
// PORT: pointer arithmetic done in int (see func_00252660).
extern "C" int func_00252688(void* p, int v)
{
    int r = 0;
    if (*(unsigned short*)((int)p - 0xE) & 0x800) {
        r = 1;
        ((sMemUnalignedInt*)((char*)p + *(int*)((int)p - 0xC) + 4))->value = v;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002526B8);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" void* cMemMan_internalResizeBlock(void* block, int size);
extern void* D_00538B00[16];

extern "C" void* func_002526B8(void* block, int size)
{
    void* r;
    MUTEX_lock(D_00538B00);
    r = cMemMan_internalResizeBlock(block, size);
    MUTEX_unlock(D_00538B00);
    return r;
}
#endif

INCLUDE_ASM("mem/memstd", func_00252718);
//100%
INCLUDE_ASM("mem/memstd", func_00252960);
#ifdef SKIP_ASM
extern "C" int func_00252960(int unused, int id)
{
    return *(int*)((char*)D_004D2438[id & 0x3F] + 0x30);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00252980);
#ifdef SKIP_ASM
extern "C" int func_00320B68(int);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");

// PORT: the unit declares func_00252980 as `void* (void*)`; existing callers bind the
// 6-argument form below by asm label (the 6th argument is unused).
void* func_00252980_6(void*, int, int, int, int, int) __asm__("func_00252980");

void* func_00252980_6(void* tag, int size, int align, int d, int flags, int unused)
{
    int lvl = func_00320B68(align) - 2 < 0 ? 0 : func_00320B68(align) - 2;
    return operator_new_tag(size, (const char*)tag, flags | (lvl << 24) | 0x10000000, d);
}
#endif

INCLUDE_ASM("mem/memstd", func_00252A10);

extern "C" void* func_00252980(void*);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00252F60__FPv);
#ifdef SKIP_ASM
void* func_00252980_6(void*, int, int, int, int, int) __asm__("func_00252980");

// PORT: the project's symbol name says (void*), but callers pass and this
// forwards 5 args (see func_00253AD0); the real body is bound by asm label.
void* func_00252F60_impl(void* a0, int a1, int a2, int a3, int a4) __asm__("func_00252F60__FPv");

void* func_00252F60_impl(void* a0, int a1, int a2, int a3, int a4)
{
    return func_00252980_6(a0, a1, a2, a3, a4, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00252F80);
#ifdef SKIP_ASM
extern "C" void func_00252A10(int, int, int, int, int, int);

extern "C" void func_00252F80(int a0, int a1, int a2, int a3, int a4) {
    func_00252A10(a0, a1, a2, a3, a4, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00252FA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* func_00252980_6(void*, int, int, int, int, int) __asm__("func_00252980");

extern "C" void* func_00252FA0(void* a0, int a1, int a2)
{
    return func_00252980_6(a0, a1, 0x80, 0, a2, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00252FC8);
#ifdef SKIP_ASM
extern "C" void func_00252FC8(int a0, int a1, int a2)
{
    func_00252A10(a0, a1, 0x80, 0, a2, 1);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00252FF0);
#ifdef SKIP_ASM
extern "C" void func_00252FF0(void* a0, int a1, int a2)
{
    func_00252980_6(a0, a1, 0, 0, a2, 0);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00253018);
#ifdef SKIP_ASM
extern "C" void func_00252A10(int, int, int, int, int, int);

extern "C" void func_00253018(int a0, int a1, int a2) {
    func_00252A10(a0, a1, 0, 0, a2, 0);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00253040);
#ifdef SKIP_ASM
extern "C" void func_00253040(int a0)
{
    func_00252980_6(0, a0, 0, 0, 0, 1);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00253070);
#ifdef SKIP_ASM
extern "C" void func_00252A10(int, int, int, int, int, int);

extern "C" void func_00253070(int arg0) {
    func_00252A10(0, arg0, 0, 0, 0, 1);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002530A0);
#ifdef SKIP_ASM
extern "C" void func_002530A0(int a0)
{
    func_00252980_6(0, a0, 0, 0, 0, 0);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_002530D0);
#ifdef SKIP_ASM
extern "C" void func_00252A10(int, int, int, int, int, int);

extern "C" void func_002530D0(int arg0) {
    func_00252A10(0, arg0, 0, 0, 0, 0);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00253100);
#ifdef SKIP_ASM
extern "C" sMemNode_251718* func_00253100(sMemClass_251718* cls, int size, int back)
{
    sMemNode_251718* n = &cls->head;
    if (back == 0) {
        do {
            n = n->next;
        } while (n->size < size);
    } else {
        do {
            n = n->prev;
        } while (n->size < size);
    }
    return n->tag != 0x4253 ? n : 0;
}
#endif

INCLUDE_ASM("mem/memstd", func_00253170);
//100%
INCLUDE_ASM("mem/memstd", func_00253230);
#ifdef SKIP_ASM
extern "C" int func_00253230(sMemClass_251718* cls, int back)
{
    int total = 0;
    if (back == 0) {
        sMemNode_251718* n = cls->head.next;
        while (n->tag != 0x4253) {
            int size = n->size;
            int rest = total - 0x10;
            n = n->next;
            total = rest + size;
        }
    } else {
        sMemNode_251718* n = cls->head.prev;
        while (n->tag != 0x4253) {
            int size = n->size;
            int rest = total - 0x10;
            n = n->prev;
            total = rest + size;
        }
    }
    return total;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002532B0);
#ifdef SKIP_ASM
extern "C" void func_002532B0(sMemClass_251D50* cls, sMemNode_251D50* blk)
{
    sMemNode_251D50* q = &cls->head;
    sMemNode_251D50* p = q;
    int sz = blk->end - (char*)blk;
    if ((char*)cls->head.next + ((char*)cls->head.prev - (char*)cls->head.next) / 2 < (char*)blk) {
        do
            p = p->prev;
        while (blk < p);
        q = p->next;
    } else {
        do
            q = q->next;
        while (q < blk);
        p = q->prev;
    }
    blk->size = sz;
    blk->next = q;
    blk->prev = p;
    p->next = blk;
    q->prev = blk;
    blk->tag = 0x4246;
    blk->flags |= 0x4000;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00253368);
#ifdef SKIP_ASM
struct sMemBlock {
    unsigned short magic;
    unsigned short flags;
    int size;
    char pad[8];
    sMemBlock* next;
    sMemBlock* prev;
};

extern "C" void func_00253368(sMemBlock* blk) {
    sMemBlock* prev = blk->prev;
    sMemBlock* next = blk->next;
    prev->next = next;
    next->prev = prev;
    blk->magic = 0x424F;
    blk->flags &= 0xBFFF;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253390);
#ifdef SKIP_ASM
extern "C" void func_00253390(void* self)
{
    *(float*)((char*)self + 0x20) = 1.0f;
    *(int*)((char*)self + 0x1c) = 31;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)((char*)self + 0xc) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x14) = 0;
    *(int*)((char*)self + 0x18) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_002533C8);
#ifdef SKIP_ASM
extern "C" void func_00253AA0();

extern "C" void* func_002533C8(void* self)
{
    func_00253AA0();
    func_00253390((char*)self + 0x14);
    *(float*)((char*)self + 0x10) = *(float*)((char*)self + 0x34);
    *(int*)((char*)self + 0x38) = 0;
    *(int*)((char*)self + 0x3C) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253418);
#ifdef SKIP_ASM
void operator_delete(int*);
extern "C" void func_002535F8(void* self);

extern "C" void func_00253418(void* self, int flags)
{
    func_002535F8(self);
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253460);
#ifdef SKIP_ASM
struct func_00253460_sInfo {
    int f0;
    char pad[0x20];
};

extern "C" void func_002534A8(void* self, void* info);

extern "C" void func_00253460(void* self, int v)
{
    func_00253460_sInfo info;
    func_002535F8(self);
    func_00253390(&info);
    info.f0 = v;
    func_002534A8(self, &info);
}
#endif

INCLUDE_ASM("mem/memstd", func_002534A8);

//100%
INCLUDE_ASM("mem/memstd", func_002535F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003B0680(void*, void*);
extern "C" void func_003AE300(void* p, int flags);
extern int D_004A2E9C;

class cWorld002535F8 {
public:
    char pad[0x10D8];
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
};
extern cWorld002535F8* D_004A5B80_w __asm__("D_004A5B80");

struct sVEntry002535F8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sStream002535F8 {
    int f0;
    int f4;
    int f8;
    void* fC;
    char pad10[0x28];
    char* f38;
    void* f3C;
    int f40;
};

extern "C" void func_002535F8(void* self)
{
    sStream002535F8* s = (sStream002535F8*)self;
    if (s->f38 != 0 && s->f3C != 0) {
        D_004A5B80_w->v19();
    }
    if (s->f40 != 0 && s->fC != 0) {
        func_003B0680(*(void**)(s->f38 + 0x64), s->fC);
    }
    void* o = s->f3C;
    if (o != 0) {
        sVEntry002535F8* e = &(*(sVEntry002535F8**)((char*)o + 4))[1];
        e->fn((char*)o + e->delta, 3);
        s->f3C = 0;
        D_004A2E9C--;
    }
    char* m = s->f38;
    if (m != 0) {
        func_003AE300(m, 3);
        s->f38 = 0;
    }
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = 0;
    s->fC = 0;
    s->f40 = 0;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002536C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2E9C;
extern int D_004A5B80;
extern "C" int func_003AE450(void* p, int a, int b);
extern "C" void* func_00254368(void* a0, int a1, int a2, int a3);
int func_003AE938(void*);
int func_003AE958_i(void*) __asm__("func_003AE958__FPv");

extern "C" void func_002536C8(void* self)
{
    char* s = (char*)self;
    *(int*)(s + 0x0) = 0;
    *(int*)(s + 0x4) = 0;
    *(int*)(s + 0xC) = 0;
    *(int*)(s + 0xC) = func_003AE450(*(void**)(s + 0x38), 1, 0x21);
    *(int*)(s + 0x40) = 1;
    func_003AE938(*(void**)(s + 0x38));
    *(void**)(s + 0x3C) = func_00254368(*(void**)(*(char**)(s + 0x38) + 0x64), *(int*)(s + 0xC), D_004A5B80, *(int*)(s + 0x30));
    func_003AE958_i(*(void**)(s + 0x38));
    D_004A2E9C++;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253748);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003AE6C8(void* p, float f);
extern "C" int func_003AE780(void* p);
extern "C" int func_003AE860(void* p);
extern "C" void SYNCTASK_run(int);
extern "C" void func_003E5398(int);

struct sVE0_253748 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE1_253748 {
    short delta;
    short index;
    void (*fn)(void*, void*);
};

struct sWorld_253748 {
    char pad[0x10D8];
    sVE0_253748* vt;            // 0x10D8
};
extern sWorld_253748* D_004A5B80_253748 __asm__("D_004A5B80");

extern "C" void func_00253748(void* self)
{
    sStream002535F8* s = (sStream002535F8*)self;
    if (s->f38 != 0) {
        func_002536C8(s);
        do {
            if (s->f4 != 0) {
                char* o = (char*)s->f3C;
                sVE0_253748* e = &(*(sVE0_253748**)(o + 4))[5];
                e->fn(o + e->delta);
            } else {
                char* o = (char*)s->f3C;
                sVE1_253748* e = &(*(sVE1_253748**)(o + 4))[4];
                e->fn(o + e->delta, s->fC);
            }
            sVE0_253748* w = &D_004A5B80_253748->vt[20];
            w->fn((char*)D_004A5B80_253748 + w->delta);
            SYNCTASK_run(0);
            func_003E5398(0);
            if (func_003AE780(s->f38) != 0) {
                char* o = (char*)s->f3C;
                sVE0_253748* e = &(*(sVE0_253748**)(o + 4))[6];
                e->fn(o + e->delta);
                s->fC = (void*)func_003AE6C8(s->f38, *(float*)(s->f38 + 0x48));
                s->f4 = 0;
            } else {
                s->f4 = 1;
            }
            if (s->fC == 0) {
                s->f4 = 1;
                s->f0 = func_003AE860(s->f38);
            }
        } while (s->f0 == 0);
        s->f40 = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00253860);
#ifdef SKIP_ASM
extern "C" void func_002536C8(void* self);

extern "C" int func_00253860(void* self)
{
    if (*(void**)((char*)self + 0x38) == 0) {
        return 0;
    }
    func_002536C8(self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253890);
#ifdef SKIP_ASM
class cMemObj_253890 {
public:
    int field_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int a);
    virtual void v05();
};

extern "C" void func_00253890(void* self, int force)
{
    if (*(void**)((char*)self + 0x38) == 0) {
        return;
    }
    cMemObj_253890* obj = *(cMemObj_253890**)((char*)self + 0x3C);
    if (obj == 0) {
        return;
    }
    if (force != 0 || *(int*)((char*)self + 0x8) != 0
        || (*(int*)((char*)self + 0x40) == 0 && *(int*)((char*)self + 0x4) != 0)
        || *(int*)((char*)self + 0x0) != 0) {
        (*(cMemObj_253890**)((char*)self + 0x3C))->v05();
    } else {
        obj->v04(*(int*)((char*)self + 0xC));
        *(int*)((char*)self + 0x40) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253938);
#ifdef SKIP_ASM
extern "C" int func_003AE780(void* p);
extern "C" int func_003AE6C8(void* p, float f);
extern "C" int func_003AE860(void* p);

class cMemObj_253938 {
public:
    int field_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04(int a);
    virtual void v05();
    virtual void v06();
};

extern "C" void func_00253938(void* self)
{
    if (*(int*)((char*)self + 0x40) == 0 && func_003AE780(*(void**)((char*)self + 0x38)) != 0) {
        (*(cMemObj_253938**)((char*)self + 0x3C))->v06();
        void* p = *(void**)((char*)self + 0x38);
        *(int*)((char*)self + 0xC) = func_003AE6C8(p, *(float*)((char*)p + 0x48));
        *(int*)((char*)self + 0x40) = 1;
        *(int*)((char*)self + 0x4) = 0;
    } else {
        *(int*)((char*)self + 0x4) = 1;
    }
    if (*(int*)((char*)self + 0xC) == 0 && *(int*)((char*)self + 0x0) == 0) {
        *(int*)((char*)self + 0x40) = 0;
        *(int*)((char*)self + 0x4) = 1;
        *(int*)((char*)self + 0x0) = func_003AE860(*(void**)((char*)self + 0x38));
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002539E0);
#ifdef SKIP_ASM
int func_003AE938(void*);

extern "C" void func_002539E0(void* self)
{
    void* p = *(void**)((char*)self + 0x38);
    if (p != 0 && *(int*)((char*)self + 0x3C) != 0 && *(int*)((char*)self + 0x0) == 0
        && *(int*)((char*)self + 0x8) == 0) {
        func_003AE938(p);
        *(int*)((char*)self + 0x8) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253A40);
#ifdef SKIP_ASM
void func_003AE958(void*);

extern "C" void func_00253A40(void* self)
{
    void* p = *(void**)((char*)self + 0x38);
    if (p != 0 && *(int*)((char*)self + 0x3C) != 0 && *(int*)((char*)self + 0x0) == 0
        && *(int*)((char*)self + 0x8) != 0) {
        func_003AE958(p);
        *(int*)((char*)self + 0x8) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253AA0);
#ifdef SKIP_ASM
extern "C" void* func_00253AD0(int size);
void* func_00253AF8(void* self);

struct sMemAllocFuncs {
    void* (*alloc)(int);    // 0x0
    void* (*free)(void*);   // 0x4
    int field_0x8;          // 0x8
};
extern sMemAllocFuncs D_00509430;

extern "C" void func_00253AA0()
{
    D_00509430.alloc = func_00253AD0;
    D_00509430.free = func_00253AF8;
    D_00509430.field_0x8 = 0x400;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00253AD0);
#ifdef SKIP_ASM
void* func_00252F60_5(void* a0, int a1, int a2, int a3, int a4) __asm__("func_00252F60__FPv");

// PORT: the unit declares this as (int size); the body uses 5 args (prototype mismatch).
void* func_00253AD0_impl(void* a0, int a1, int align, int a3, int a4) __asm__("func_00253AD0");

void* func_00253AD0_impl(void* a0, int a1, int align, int a3, int a4)
{
    if (align < 64) {
        align = 64;
    }
    return func_00252F60_5(a0, a1, align, a3, a4);
}
#endif

extern "C" void* func_002523A8(void* self);

//99.29%
INCLUDE_ASM("mem/memstd", func_00253AF8__FPv);
#ifdef SKIP_ASM
void* func_00253AF8(void* self)
{
    return func_002523A8(self);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00253B18);
#ifdef SKIP_ASM
extern "C" int func_00253B18(int a, ...)
{
    return a;
}
#endif

INCLUDE_ASM("mem/memstd", func_00253B58);

extern "C" void* func_00253B58(int, int);

//99.38%
INCLUDE_ASM("mem/memstd", func_00254330__FPv);
#ifdef SKIP_ASM
void* func_00254330(void* self)
{
    return func_00253B58(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00254350);
#ifdef SKIP_ASM
extern "C" int func_00254350(int x)
{
    float fv = (float)x;
    int bits = *(int*)&fv;
    return (bits >> 23) - 0x7f;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00254368);
#ifdef SKIP_ASM
extern char D_004A2EA0[];
extern "C" void* func_00254410(void* self, void* a0, int a1, int a2, int a3);

// PORT: the unit's sMemAllocFuncs declares alloc as `void* (*)(int)`; it really
// takes (tag, size, align, d, flags) (see func_00252F60 / func_00253AD0).
typedef void* (*tMemAlloc5_00254368)(void*, int, int, int, int);

extern "C" void* func_00254368(void* a0, int a1, int a2, int a3)
{
    void* p = ((tMemAlloc5_00254368)D_00509430.alloc)(D_004A2EA0, 0x54, 0, 0, D_00509430.field_0x8);
    return func_00254410(p, a0, a1, a2, a3);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002543F0);
#ifdef SKIP_ASM
extern "C" void func_002543F0(void* self, float a, float b, float c)
{
    *(float*)((char*)self + 0x40) = a;
    *(float*)((char*)self + 0x44) = b;
    *(float*)((char*)self + 0x48) = c;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00254400__FPvff);
#ifdef SKIP_ASM
void func_00254400(void* self, float f0, float f1)
{
    *(float*)((char*)self + 0x4c) = f0;
    *(float*)((char*)self + 0x50) = f1;
}
#endif

INCLUDE_ASM("mem/memstd", func_00254410);

//100%
INCLUDE_ASM("mem/memstd", func_002547B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void* D_00480270[];
extern void* D_004802B0[];
extern void* (*D_00509434[])(void*);

struct sRVEntry_2547B8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sRCtx_2547B8 {
    char pad[0x10D8];
    sRVEntry_2547B8* vt;
};
extern sRCtx_2547B8* D_004A5B80_2547B8 __asm__("D_004A5B80");

struct sTexCache_2547B8 {
    void* owner;
    void** vt;
    int f8;
    void* fC;
    int f10;
    int** texs;
    int count;
};

extern "C" void func_002547B8(sTexCache_2547B8* self, int flags)
{
    self->vt = D_00480270;
    for (int i = 0; i < self->count; i++) {
        int* t = self->texs[i];
        if (t != 0) {
            D_004A5B80_2547B8->vt[50].fn((char*)D_004A5B80_2547B8 + D_004A5B80_2547B8->vt[50].delta, *t);
            *t = -1;
            D_00509430.free(t);
        }
    }
    if (self->texs != 0) {
        cMemMan_free(self->texs);
    }
    self->texs = 0;
    if (self->fC != 0) {
        func_003B0680(self->owner, self->fC);
        self->fC = 0;
    }
    self->vt = D_004802B0;
    if (flags & 1) {
        D_00509434[0](self);
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_002548D0);
#ifdef SKIP_ASM
struct sVec4_2548D0 {
    float v[4];
    sVec4_2548D0() {}
} __attribute__((aligned(16)));

struct sVtx_2548D0 {
    float u, v, q;
    int pad;
    int r, g, b, a;
    sVec4_2548D0 pos;
    sVtx_2548D0() {}
};

struct sRS_2548D0 {
    int f0;
    int f4;
    int f8;
    int fC;
    short f10;
};

class cWorld_2548D0 {
public:
    char pad0[0xE84];
    sRS_2548D0* top;
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
    virtual unsigned int v10();
    virtual unsigned int v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17();
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
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71(int n, void* verts, int flags);
};

extern cWorld_2548D0* D_004A5B80_2548D0 __asm__("D_004A5B80");
extern char D_004FF1A0[];

struct sMesh_2548D0 {
    int f0;
    int f4;
    cWorld_2548D0* world;   // 0x8
    void* res;              // 0xC
    char* hdr;              // 0x10
    int** items;            // 0x14
    int f18;
    int rows;               // 0x1C
    int cols;               // 0x20
    int widths[6];          // 0x24
    int f3C;                // 0x3C
    float x;                // 0x40
    float y;                // 0x44
    float z;                // 0x48
    float cw;               // 0x4C
    float ch;               // 0x50
};

// PORT: the unit declares func_002548D0 as returning void*, but it returns nothing (v0 is left as is); bind the real signature.
extern "C" void func_002548D0_impl(void* p) __asm__("func_002548D0");
extern "C" void func_002548D0_impl(void* p)
{
    sMesh_2548D0* self = (sMesh_2548D0*)p;
    while (self->world->v17() == 0) {
    }
    float w = (float)self->world->v10();
    float h = (float)self->world->v11();
    self->world->v26(0, 0, 0.0f, 0.0f, w, h, 0.0f, 1.0f);
    self->world->v34(D_004FF1A0);
    sRS_2548D0* rs = self->world->top;
    rs->f8 = (rs->f8 & ~0x3E0) | ((self->f3C << 5) & 0x3E0);
    sVtx_2548D0 v[4];
    int i;
    for (i = 0; i < 4; i++) {
        v[i].a = 0x80;
        v[i].r = 0x80;
        v[i].g = 0x80;
        v[i].b = 0x80;
        v[i].q = 1.0f;
    }
    float cw = self->cw * 16.0f;
    float x0 = self->x + 0.5f;
    v[0].u = 0.0f;
    v[0].v = 0.0f;
    float x1 = x0 + cw;
    v[1].u = 1.0f;
    v[1].v = 0.0f;
    v[2].u = 0.0f;
    v[2].v = 1.0f;
    v[3].u = 1.0f;
    v[3].v = 1.0f;
    int cell = 0;
    int row;
    for (row = 0; row < self->rows; row++) {
        float yoff = 0.0f;
        int col = 0;
        if (col < self->cols) {
            int* wp = self->widths;
            do {
                float y = self->y + 0.5f + yoff;
                float ch = (float)*wp * self->ch;
                int id = *self->items[cell];
                D_004A5B80_2548D0->top->f10 = id;
                { sVec4_2548D0 q; q.v[0] = x0; q.v[1] = y; q.v[2] = self->z; q.v[3] = 1.0f; v[0].pos = q; }
                { sVec4_2548D0 q; q.v[0] = x1; q.v[1] = y; q.v[2] = self->z; q.v[3] = 1.0f; v[1].pos = q; }
                { sVec4_2548D0 q; q.v[0] = x0; q.v[1] = y + ch; q.v[2] = self->z; q.v[3] = 1.0f; v[2].pos = q; }
                { sVec4_2548D0 q; q.v[0] = x1; q.v[1] = y + ch; q.v[2] = self->z; q.v[3] = 1.0f; v[3].pos = q; }
                yoff += ch;
                cell++;
                wp++;
                col++;
                self->world->v71(4, v, 0);
            } while (col < self->cols);
        }
        x0 += cw;
        x1 += cw;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("mem/memstd", func_00254C48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cWorld_254C48 {
public:
    char pad[0x10D8];
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
    virtual void v49(int a, char* p, int b, int c, int d, int e, int f, int g, int h);
};
extern "C" void* func_002548D0(void* self);
extern cWorld_254C48* D_004A5B80_254C48 __asm__("D_004A5B80");

struct sMesh_254C48 {
    int f0;
    int f4;
    int f8;
    void* res;
    char* hdr;
    char** items;
    int f18;
    int rows;
    int cols;
    int widths[1];
};

extern "C" void func_00254C48(sMesh_254C48* self, void* res)
{
    if (res != 0) {
        self->res = res;
    }
    char* hdr = *(char**)((char*)res + 4);
    self->hdr = hdr;
    char* data;
    if (*(int*)(hdr + 0xC) & 0x1000) {
        data = hdr + *(int*)(hdr + 0x10);
    } else {
        data = hdr + 0x10;
    }
    int k = 0;
    short stride = *(short*)(self->hdr + 6);
    for (int i = 0; i < self->rows; i++) {
        int off = 0;
        for (int j = 0; j < self->cols; j++) {
            int* e = ((int**)self->items)[k];
            D_004A5B80_254C48->v49(e[0], data + ((off << 6) + stride * (i << 6)), e[1], e[2], 0, 0, 0, 0, 0);
            k++;
            off += self->widths[j];
        }
    }
    func_002548D0(self);
}
#endif

extern "C" void* func_002548D0(void* self);

//99.29%
INCLUDE_ASM("mem/memstd", func_00254DA0__FPv);
#ifdef SKIP_ASM
void* func_00254DA0(void* self)
{
    return func_002548D0(self);
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00254DC0);
#ifdef SKIP_ASM
struct sMemStdVEntry {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_003B0680(void*, void*);

extern "C" void func_00254DC0(void* self)
{
    void* o;
    sMemStdVEntry* vt;
    do {
        o = *(void**)((char*)self + 0x8);
        vt = *(sMemStdVEntry**)((char*)o + 0x10D8);
    } while (vt[18].fn((char*)o + vt[18].delta) == 0);
    void* p = *(void**)((char*)self + 0xC);
    if (p != 0) {
        func_003B0680(*(void**)((char*)self + 0x0), p);
        *(void**)((char*)self + 0xC) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00254E20);
#ifdef SKIP_ASM
extern "C" int func_00254E20(int a, ...)
{
    return a;
}
#endif

INCLUDE_ASM("mem/memstd", func_00254E60);

//100%
INCLUDE_ASM("mem/memstd", func_00255638);
#ifdef SKIP_ASM
extern void* D_004802B0[];
void operator_delete(int*);

extern "C" void func_00255638(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_004802B0;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00255668__FPv);
#ifdef SKIP_ASM
void func_00255668(void* self)
{
}
#endif

extern "C" void* func_00254E60(int, int);

//100%
INCLUDE_ASM("mem/memstd", func_00255670);
#ifdef SKIP_ASM
extern "C" void func_00255670(int arg0) {
    (*(int (**)(int *, int, int, int, int))((char*)(&(*(int*)&D_00509430)) + (0)))(&(*(int*)&D_004A2EA0), arg0, 0, 0, (*(int *)((char*)(&(*(int*)&D_00509430)) + (8))));
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002556B0);
#ifdef SKIP_ASM
extern "C" void func_002556B0(int arg0) {
    (*(int (**)(int *, int, int, int, int))((char*)(&(*(int*)&D_00509430)) + (0)))(&(*(int*)&D_004A2EA0), arg0, 0, 0, (*(int *)((char*)(&(*(int*)&D_00509430)) + (8))));
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002556F0);
#ifdef SKIP_ASM
extern "C" void func_002556F0(int size, void* tag, int align, int d, int flags)
{
    ((tMemAlloc5_00254368)D_00509430.alloc)(tag, size, align, d, flags);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00255720);
#ifdef SKIP_ASM
extern "C" void func_00255720(int size, void* tag, int align, int d, int flags)
{
    ((tMemAlloc5_00254368)D_00509430.alloc)(tag, size, align, d, flags);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00255750);
#ifdef SKIP_ASM
extern "C" void func_00255750(void* self)
{
    D_00509434[0](self);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_00255778);
#ifdef SKIP_ASM
extern "C" void func_00255778(void* self)
{
    D_00509434[0](self);
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002557A0);
#ifdef SKIP_ASM
extern "C" int func_002557A0(void* self, int value) {
    return value;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002557A8);
#ifdef SKIP_ASM
extern "C" void func_002557A8(void) {

}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002557B0);
#ifdef SKIP_ASM
extern "C" int func_002557B0(void* self, int value) {
    return value;
}
#endif
//100%
INCLUDE_ASM("mem/memstd", func_002557B8);
#ifdef SKIP_ASM
extern "C" void func_002557B8(void) {

}
#endif

//99.38%
INCLUDE_ASM("mem/memstd", func_002557C0__FPv);
#ifdef SKIP_ASM
void* func_002557C0(void* self)
{
    return func_00254E60(1, 0xffff);
}
#endif

extern void* D_00481320[];

//100%
INCLUDE_ASM("mem/memstd", func_002557E0__FPv);
#ifdef SKIP_ASM
void* func_002557E0(void* self)
{
    int t0 = 0;
    *(int*)self = t0;
    *(int*)((char*)self + 0x8) = (int)(void*)D_00481320;
    *(int*)((char*)self + 0x4) = t0;
    return self;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00255800);
#ifdef SKIP_ASM
void operator_delete(int*);

extern "C" void func_00255800(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00481320;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00255830__FPv);
#ifdef SKIP_ASM
int func_00255830(void* self)
{
    int t0 = 1;
    *(int*)((char*)self + 0x4) = 0;
    *(int*)self = t0;
    return t0;
}
#endif

//100%
INCLUDE_ASM("mem/memstd", func_00255840);
#ifdef SKIP_ASM
extern "C" void func_00255840(void* self)
{
    if (*(int*)self != 0) {
        *(int*)self = 0;
        *(int*)((char*)self + 0x4) = 0;
    }
}
#endif

