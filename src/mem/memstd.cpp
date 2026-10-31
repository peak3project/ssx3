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

//100%
INCLUDE_ASM("mem/memstd", func_00251AC0);
#ifdef SKIP_ASM
extern int D_004A2E78_1AC0 __asm__("D_004A2E78");
// Release-build assert (compiled out); EA code asserts its pointers
#define ASSERT_1AC0(cond) do { } while (0)
extern "C" int func_00251AC0(int id)
{
    if (id == 0) {
        id = D_004A2E78_1AC0;
    }
    sMemClass_251718* cls = (sMemClass_251718*)D_004D2438[id & 0x3F];
    sMemNode_251718* n = cls->head.next;
    sMemNode_251718* best = 0;
    int v = 0;
    for (;;) {
        if (v < n->size - 0x10) {
            if (n->tag == 0x4253) {
                break;
            }
            best = n;
            v = best->size - 0x10;
        }
        n = n->next;
    }
    ASSERT_1AC0(best != 0);
    return best != 0 ? best->size : 0;
}
#endif

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

//100%
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

//100%
INCLUDE_ASM("mem/memstd", func_002523D0);
#ifdef SKIP_ASM
struct sMemNode_2523D0 {
    unsigned short tag;
    unsigned short flags;
    int size;
    sMemNode_2523D0* pnext;     // 0x8
    sMemNode_2523D0* pprev;     // 0xC
    sMemNode_2523D0* fnext;     // 0x10
    sMemNode_2523D0* fprev;     // 0x14
};

struct sMemHdr_2523D0 {
    unsigned short tag;
    unsigned short flags;
    int size;
    sMemNode_2523D0* pnext;
    sMemNode_2523D0* pprev;
};

struct sMemClass_2523D0 {
    char pad0[0x10];
    sMemNode_2523D0 head;       // 0x10
    int align;                  // 0x28
    char pad2C[0xC];
    int locked;                 // 0x38
    int sema[5];                // 0x3C
};

extern "C" unsigned short func_00252650(void* arg0);
extern "C" void MUTEX_lock(void* mutex);
extern "C" void MUTEX_unlock(void* mutex);
extern "C" int func_00252960(int unused, int id);
int func_00252658(void* self);

extern "C" int func_002523D0(sMemHdr_2523D0* ptr)
{
    if (ptr != 0) {
        sMemNode_2523D0* blk = (sMemNode_2523D0*)(ptr - 1);
        sMemClass_2523D0* cls = (sMemClass_2523D0*)D_004D2438[*(unsigned short*)((int)ptr - 0xE) & 0x3F];
        if (cls->locked != 0) {
            MUTEX_lock(cls->sema);
        }
        sMemNode_2523D0* prev = *(sMemNode_2523D0**)((int)ptr - 4);
        sMemNode_2523D0* next = *(sMemNode_2523D0**)((int)ptr - 8);
        if (prev->flags & 0x4000) {
            sMemNode_2523D0* b = prev->fprev;
            sMemNode_2523D0* a = prev->fnext;
            b->fnext = a;
            a->fprev = b;
            prev->tag = 0x424F;
            prev->flags &= 0xBFFF;
            blk = prev;
            prev = blk->pprev;
            blk->pnext = next;
            prev->pnext = blk;
            next->pprev = blk;
        }
        if (next->flags & 0x4000) {
            sMemNode_2523D0* b = next->fprev;
            sMemNode_2523D0* a = next->fnext;
            b->fnext = a;
            a->fprev = b;
            next->tag = 0x424F;
            next->flags &= 0xBFFF;
            next = next->pnext;
            blk->pprev = prev;
            blk->pnext = next;
            next->pprev = blk;
        }
        int hdr = func_00252960(func_00252658((char*)prev + 0x10), prev->flags);
        int n = prev->size + hdr;
        if (n < 8) n = 8;
        int al = cls->align;
        sMemNode_2523D0* nb = (sMemNode_2523D0*)((char*)prev + ((n + al + 0xF) & -al));
        if (blk != nb) {
            nb->flags = blk->flags;
            blk = nb;
            blk->pnext = next;
            blk->pprev = prev;
            prev->pnext = blk;
            next->pprev = blk;
        }
        int sz = (char*)blk->pnext - (char*)blk;
        sMemNode_2523D0* q = &cls->head;
        sMemNode_2523D0* p = q;
        if ((char*)cls->head.fnext + ((char*)cls->head.fprev - (char*)cls->head.fnext) / 2 < (char*)blk) {
            do
                p = p->fprev;
            while (blk < p);
            q = p->fnext;
        } else {
            do
                q = q->fnext;
            while (q < blk);
            p = q->fprev;
        }
        blk->size = sz;
        blk->fnext = q;
        blk->fprev = p;
        p->fnext = blk;
        q->fprev = blk;
        blk->tag = 0x4246;
        blk->flags |= 0x4000;
        if (cls->locked != 0) {
            MUTEX_unlock(cls->sema);
        }
    }
    return 1;
}
#endif
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

//100%
INCLUDE_ASM("mem/memstd", func_00252718);
#ifdef SKIP_ASM
extern "C" void func_003E6188(void* dst, void* src, int n);

extern "C" void* func_00252718(sMemHdr_2523D0* ptr, int size)
{
    unsigned short id = *(unsigned short*)((int)ptr - 0xE);
    sMemClass_2523D0* cls = (sMemClass_2523D0*)D_004D2438[id & 0x3F];
    sMemNode_2523D0* blk = (sMemNode_2523D0*)(ptr - 1);
    if (cls->locked != 0) {
        MUTEX_lock(cls->sema);
    }
    sMemNode_2523D0* next = *(sMemNode_2523D0**)((int)ptr - 8);
    if (next->flags & 0x4000) {
        sMemNode_2523D0* b = next->fprev;
        sMemNode_2523D0* a = next->fnext;
        b->fnext = a;
        a->fprev = b;
        next->tag = 0x424F;
        next->flags &= 0xBFFF;
        next = next->pnext;
        *(sMemNode_2523D0**)((int)ptr - 8) = next;
        next->pprev = blk;
    }
    int v = size;
    if (v < 8) {
        if (v == -1) {
            v = 0x40000000;
        } else if (v >= 0) {
            v = 8;
        }
    }
    int hdr = func_00252960(0, id);
    int avail = (char*)next - (char*)blk - 0x10;
    int al = cls->align;
    v = ((v + hdr + 0xF + al) & -al) - 0x10;
    if (avail < v) {
        v = avail;
        size = avail - hdr;
    }
    func_003E6188((char*)ptr + size, (char*)ptr + blk->size, hdr);
    blk->size = size;
    if (avail - v > 0x40) {
        sMemNode_2523D0* nb = (sMemNode_2523D0*)((char*)ptr + (v + 0x10));
        MEM_initblock(nb, 0, 0, 0, 0, blk, next);
        int sz = (char*)nb->pnext - (char*)nb;
        sMemNode_2523D0* q = &cls->head;
        sMemNode_2523D0* p = q;
        if ((char*)cls->head.fnext + ((char*)cls->head.fprev - (char*)cls->head.fnext) / 2 < (char*)nb) {
            do
                p = p->fprev;
            while (nb < p);
            q = p->fnext;
        } else {
            do
                q = q->fnext;
            while (q < nb);
            p = q->fprev;
        }
        nb->size = sz;
        nb->fnext = q;
        nb->fprev = p;
        p->fnext = nb;
        q->fprev = nb;
        nb->tag = 0x4246;
        nb->flags |= 0x4000;
        next->pprev = nb;
        blk->pnext = nb;
    }
    if (cls->locked != 0) {
        MUTEX_unlock(cls->sema);
    }
    return ptr;
}
#endif
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
extern "C" void* operator_new__FUi(unsigned int size, const char* tag, int flags, int d);

// PORT: the unit declares func_00252980 as `void* (void*)`; existing callers bind the
// 6-argument form below by asm label (the 6th argument is unused).
void* func_00252980_6(void*, int, int, int, int, int) __asm__("func_00252980");

void* func_00252980_6(void* tag, int size, int align, int d, int flags, int unused)
{
    int lvl = func_00320B68(align) - 2 < 0 ? 0 : func_00320B68(align) - 2;
    return operator_new__FUi(size, (const char*)tag, flags | (lvl << 24) | 0x10000000, d);
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

//100%
INCLUDE_ASM("mem/memstd", func_00253170);
#ifdef SKIP_ASM
extern "C" sMemNode_251718* func_00253170(sMemClass_251718* cls, int min, int back)
{
    int v = min - 1;
    if (v < 0) {
        v = 0;
    }
    sMemNode_251718* best = 0;
    sMemNode_251718* n;
    if (back == 0) {
        n = cls->head.next;
        for (;;) {
            if (v < n->size - 0x10) {
                if (n->tag == 0x4253) {
                    break;
                }
                best = n;
                v = best->size - 0x10;
            }
            n = n->next;
        }
    } else {
        n = cls->head.prev;
        for (;;) {
            if (v < n->size - 0x10) {
                if (n->tag == 0x4253) {
                    break;
                }
                best = n;
                v = best->size - 0x10;
            }
            n = n->prev;
        }
    }
    return best;
}
#endif
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

extern "C" int func_002534A8(void* self, void* info);

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
extern "C" int SYNCTASK_run(int);
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
void* func_003AE958(void*);

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

//100%
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

//100%
INCLUDE_ASM("mem/memstd", func_00253B58);
#ifdef SKIP_ASM
extern float D_004D2538[4];
extern float D_004D2548[4];
extern float D_004D2558[4];
extern float D_004D2568[4];
extern float D_004D2578[4];
extern float D_004D2588[4];
extern float D_004D2598[4];
extern float D_004D25A8[4];
extern float D_004D25B8[4];
extern float D_004D25C8[4];
extern float D_004D25D8[4];
extern float D_004D25E8[4];
extern float D_004D25F8[4];
extern float D_004D2608[4];
extern float D_004D2618[4];
extern float D_004D2628[4];
extern float D_004D2638[4];
extern float D_004D2648[4];
extern float D_004D2658[4];
extern float D_004D2668[4];
extern float D_004D2678[4];
extern float D_004D2688[4];
extern float D_004D2698[4];
extern float D_004D26A8[4];
extern float D_004D26B8[4];
extern float D_004D26C8[4];
extern float D_004D26D8[4];
extern float D_004D26E8[4];
extern float D_004D26F8[4];
extern float D_004D2708[4];
extern float D_004D2718[4];
extern float D_004D2728[4];
extern float D_004D2738[4];
extern float D_004D2748[4];
extern float D_004D2758[4];
extern float D_004D2768[4];
extern float D_004D2778[4];
extern float D_004D2788[4];
extern float D_004D2798[4];
extern float D_004D27A8[4];
extern float D_004D27B8[4];
extern float D_004D27C8[4];
extern float D_004D27D8[4];
extern float D_004D27E8[4];
extern float D_004D27F8[4];
extern float D_004D2808[4];
extern float D_004D2818[4];
extern float D_004D2828[4];
extern float D_004D2838[4];
extern float D_004D2848[4];
extern float D_004D2858[4];
extern float D_004D2868[4];
extern float D_004D2878[4];
extern float D_004D2888[4];
extern float D_004D2898[4];
extern float D_004D28A8[4];

void sti_00253B58(int init, int prio) __asm__("func_00253B58");
void sti_00253B58(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004D2538[0] = 1.0f;
        D_004D2538[1] = 1.0f;
        D_004D2538[2] = 1.0f;
        D_004D2538[3] = 0.5f;
        D_004D2548[0] = 0.4998680055141449f;
        D_004D2548[1] = 1.0f;
        D_004D2548[2] = 1.0f;
        D_004D2548[3] = 0.0f;
        D_004D2558[0] = 0.12951700389385223f;
        D_004D2558[1] = 1.0f;
        D_004D2558[2] = 1.0f;
        D_004D2558[3] = 0.0f;
        D_004D2568[0] = 0.22426900267601013f;
        D_004D2568[1] = 0.9402310252189636f;
        D_004D2568[2] = 0.5425059795379639f;
        D_004D2568[3] = 0.0004030000127386302f;
        D_004D2578[0] = 0.4652079939842224f;
        D_004D2578[1] = 0.32170501351356506f;
        D_004D2578[2] = 0.9943439960479736f;
        D_004D2578[3] = 0.0f;
        D_004D2588[0] = 0.17792600393295288f;
        D_004D2588[1] = 1.0f;
        D_004D2588[2] = 1.0f;
        D_004D2588[3] = 0.0f;
        D_004D2598[0] = 0.4411740005016327f;
        D_004D2598[1] = 0.41388601064682007f;
        D_004D2598[2] = 0.3211260139942169f;
        D_004D2598[3] = 0.4398239850997925f;
        D_004D25A8[0] = 0.500997006893158f;
        D_004D25A8[1] = 0.24849599599838257f;
        D_004D25A8[2] = 1.0f;
        D_004D25A8[3] = 1.0f;
        D_004D25B8[0] = 0.27687299251556396f;
        D_004D25B8[1] = 0.6395620107650757f;
        D_004D25B8[2] = 0.13423900306224823f;
        D_004D25B8[3] = 0.0f;
        D_004D25C8[0] = 0.8936439752578735f;
        D_004D25C8[1] = 0.5263469815254211f;
        D_004D25C8[2] = 0.5051450133323669f;
        D_004D25C8[3] = 0.8687300086021423f;
        D_004D25D8[0] = 1.0f;
        D_004D25D8[1] = 1.0f;
        D_004D25D8[2] = 1.0f;
        D_004D25D8[3] = 1.0f;
        D_004D25E8[0] = 1.0f;
        D_004D25E8[1] = 0.0f;
        D_004D25E8[2] = 0.0f;
        D_004D25E8[3] = 0.0f;
        D_004D25F8[0] = 1.0f;
        D_004D25F8[1] = 0.550000011920929f;
        D_004D25F8[2] = 0.5350000262260437f;
        D_004D25F8[3] = 0.550000011920929f;
        D_004D2608[0] = 1.0f;
        D_004D2608[1] = 1.0f;
        D_004D2608[2] = 1.0f;
        D_004D2608[3] = 1.0f;
        D_004D2618[0] = 1.0f;
        D_004D2618[1] = 1.0f;
        D_004D2618[2] = 1.0f;
        D_004D2618[3] = 1.0f;
        D_004D2628[0] = 1.0f;
        D_004D2628[1] = 0.0f;
        D_004D2628[2] = 0.0f;
        D_004D2628[3] = 0.0f;
        D_004D2638[0] = 1.0f;
        D_004D2638[1] = 0.0f;
        D_004D2638[2] = 0.0f;
        D_004D2638[3] = 0.0f;
        D_004D2648[0] = 1.0f;
        D_004D2648[1] = 1.0f;
        D_004D2648[2] = 1.0f;
        D_004D2648[3] = 1.0f;
        D_004D2658[0] = 1.0f;
        D_004D2658[1] = 0.5f;
        D_004D2658[2] = 1.0f;
        D_004D2658[3] = 0.5f;
        D_004D2668[0] = 1.0f;
        D_004D2668[1] = 0.5f;
        D_004D2668[2] = 1.0f;
        D_004D2668[3] = 0.5f;
        D_004D2678[0] = 1.0f;
        D_004D2678[1] = 0.5f;
        D_004D2678[2] = 1.0f;
        D_004D2678[3] = 0.5f;
        D_004D2688[0] = 1.0f;
        D_004D2688[1] = 0.7828119993209839f;
        D_004D2688[2] = 0.06171900033950806f;
        D_004D2688[3] = 0.03984399884939194f;
        D_004D2698[0] = 1.0f;
        D_004D2698[1] = 1.0f;
        D_004D2698[2] = 0.7988259792327881f;
        D_004D2698[3] = 0.0f;
        D_004D26A8[0] = 0.9886710047721863f;
        D_004D26A8[1] = 0.9230499863624573f;
        D_004D26A8[2] = 0.34311699867248535f;
        D_004D26A8[3] = 0.0f;
        D_004D26B8[0] = 1.0f;
        D_004D26B8[1] = 1.0f;
        D_004D26B8[2] = 1.0f;
        D_004D26B8[3] = 1.0f;
        D_004D26C8[0] = 1.0f;
        D_004D26C8[1] = 1.0f;
        D_004D26C8[2] = 0.7976430058479309f;
        D_004D26C8[3] = 0.0f;
        D_004D26D8[0] = 1.0f;
        D_004D26D8[1] = 0.9222670197486877f;
        D_004D26D8[2] = 0.34179699420928955f;
        D_004D26D8[3] = 0.0f;
        D_004D26E8[0] = 1.0f;
        D_004D26E8[1] = 0.7847639918327332f;
        D_004D26E8[2] = 0.06054700165987015f;
        D_004D26E8[3] = 0.04062499850988388f;
        D_004D26F8[0] = 1.0f;
        D_004D26F8[1] = 0.800000011920929f;
        D_004D26F8[2] = 0.44999998807907104f;
        D_004D26F8[3] = 1.0f;
        D_004D2708[0] = 1.0f;
        D_004D2708[1] = 0.3281260132789612f;
        D_004D2708[2] = 1.0f;
        D_004D2708[3] = 0.3539060056209564f;
        D_004D2718[0] = 1.0f;
        D_004D2718[1] = 1.0f;
        D_004D2718[2] = 1.0f;
        D_004D2718[3] = 1.0f;
        D_004D2728[0] = 1.0f;
        D_004D2728[1] = 1.0f;
        D_004D2728[2] = 1.0f;
        D_004D2728[3] = 1.0f;
        D_004D2738[0] = 1.0f;
        D_004D2738[1] = 0.8613290190696716f;
        D_004D2738[2] = 0.38124799728393555f;
        D_004D2738[3] = 0.0f;
        D_004D2748[0] = 1.0f;
        D_004D2748[1] = 1.0f;
        D_004D2748[2] = 1.0f;
        D_004D2748[3] = 1.0f;
        D_004D2758[0] = 1.0f;
        D_004D2758[1] = 0.3244380056858063f;
        D_004D2758[2] = 1.0f;
        D_004D2758[3] = 0.0f;
        D_004D2768[0] = 1.0f;
        D_004D2768[1] = 1.0f;
        D_004D2768[2] = 1.0f;
        D_004D2768[3] = 1.0f;
        D_004D2778[0] = 1.0f;
        D_004D2778[1] = 1.0f;
        D_004D2778[2] = 0.0f;
        D_004D2778[3] = 0.0f;
        D_004D2788[0] = 0.7007060050964355f;
        D_004D2788[1] = 0.0f;
        D_004D2788[2] = 0.0f;
        D_004D2788[3] = 0.0f;
        D_004D2798[0] = 1.0f;
        D_004D2798[1] = 0.7828530073165894f;
        D_004D2798[2] = 0.06140600144863129f;
        D_004D2798[3] = 0.04146299883723259f;
        D_004D27A8[0] = 1.0f;
        D_004D27A8[1] = 0.32487601041793823f;
        D_004D27A8[2] = 1.0f;
        D_004D27A8[3] = 0.35280099511146545f;
        D_004D27B8[0] = 1.0f;
        D_004D27B8[1] = 1.0f;
        D_004D27B8[2] = 0.7977359890937805f;
        D_004D27B8[3] = 0.0f;
        D_004D27C8[0] = 1.0f;
        D_004D27C8[1] = 0.4937489926815033f;
        D_004D27C8[2] = 1.0f;
        D_004D27C8[3] = 0.49179700016975403f;
        D_004D27D8[0] = 1.0f;
        D_004D27D8[1] = 1.0f;
        D_004D27D8[2] = 1.0f;
        D_004D27D8[3] = 1.0f;
        D_004D27E8[0] = 1.0f;
        D_004D27E8[1] = 0.800000011920929f;
        D_004D27E8[2] = 1.0f;
        D_004D27E8[3] = 0.800000011920929f;
        D_004D27F8[0] = 1.0f;
        D_004D27F8[1] = 1.0f;
        D_004D27F8[2] = 0.0f;
        D_004D27F8[3] = 0.0f;
        D_004D2808[0] = 1.0f;
        D_004D2808[1] = 1.0f;
        D_004D2808[2] = 0.0f;
        D_004D2808[3] = 0.0f;
        D_004D2818[0] = 1.0f;
        D_004D2818[1] = 1.0f;
        D_004D2818[2] = 0.0f;
        D_004D2818[3] = 0.0f;
        D_004D2828[0] = 1.0f;
        D_004D2828[1] = 0.3273420035839081f;
        D_004D2828[2] = 1.0f;
        D_004D2828[3] = 0.35390499234199524f;
        D_004D2838[0] = 1.0f;
        D_004D2838[1] = 1.0f;
        D_004D2838[2] = 0.061000000685453415f;
        D_004D2838[3] = 0.039000000804662704f;
        D_004D2848[0] = 1.0f;
        D_004D2848[1] = 1.0f;
        D_004D2848[2] = 0.7999979853630066f;
        D_004D2848[3] = 0.0f;
        D_004D2858[0] = 1.0f;
        D_004D2858[1] = 0.9589840173721313f;
        D_004D2858[2] = 0.6143789887428284f;
        D_004D2858[3] = 0.0f;
        D_004D2868[0] = 1.0f;
        D_004D2868[1] = 0.9285150170326233f;
        D_004D2868[2] = 0.3399839997291565f;
        D_004D2868[3] = 0.0f;
        D_004D2878[0] = 1.0f;
        D_004D2878[1] = 0.8738250136375427f;
        D_004D2878[2] = 0.24931700527668f;
        D_004D2878[3] = 0.017578000202775f;
        D_004D2888[0] = 1.0f;
        D_004D2888[1] = 0.7843739986419678f;
        D_004D2888[2] = 0.06132800132036209f;
        D_004D2888[3] = 0.03945299983024597f;
        D_004D2898[0] = 1.0f;
        D_004D2898[1] = 0.0f;
        D_004D2898[2] = 1.0f;
        D_004D2898[3] = 0.0f;
        D_004D28A8[0] = 1.0f;
        D_004D28A8[1] = 1.0f;
        D_004D28A8[2] = 0.0f;
        D_004D28A8[3] = 0.0f;
    }
}
#endif

extern "C" void* func_00253B58(int, int);

//100%
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

//100%
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

//100%
INCLUDE_ASM("mem/memstd", func_00254E60);
#ifdef SKIP_ASM
extern float D_004D28B8[4];
extern float D_004D28C8[4];
extern float D_004D28D8[4];
extern float D_004D28E8[4];
extern float D_004D28F8[4];
extern float D_004D2908[4];
extern float D_004D2918[4];
extern float D_004D2928[4];
extern float D_004D2938[4];
extern float D_004D2948[4];
extern float D_004D2958[4];
extern float D_004D2968[4];
extern float D_004D2978[4];
extern float D_004D2988[4];
extern float D_004D2998[4];
extern float D_004D29A8[4];
extern float D_004D29B8[4];
extern float D_004D29C8[4];
extern float D_004D29D8[4];
extern float D_004D29E8[4];
extern float D_004D29F8[4];
extern float D_004D2A08[4];
extern float D_004D2A18[4];
extern float D_004D2A28[4];
extern float D_004D2A38[4];
extern float D_004D2A48[4];
extern float D_004D2A58[4];
extern float D_004D2A68[4];
extern float D_004D2A78[4];
extern float D_004D2A88[4];
extern float D_004D2A98[4];
extern float D_004D2AA8[4];
extern float D_004D2AB8[4];
extern float D_004D2AC8[4];
extern float D_004D2AD8[4];
extern float D_004D2AE8[4];
extern float D_004D2AF8[4];
extern float D_004D2B08[4];
extern float D_004D2B18[4];
extern float D_004D2B28[4];
extern float D_004D2B38[4];
extern float D_004D2B48[4];
extern float D_004D2B58[4];
extern float D_004D2B68[4];
extern float D_004D2B78[4];
extern float D_004D2B88[4];
extern float D_004D2B98[4];
extern float D_004D2BA8[4];
extern float D_004D2BB8[4];
extern float D_004D2BC8[4];
extern float D_004D2BD8[4];
extern float D_004D2BE8[4];
extern float D_004D2BF8[4];
extern float D_004D2C08[4];
extern float D_004D2C18[4];
extern float D_004D2C28[4];

void sti_00254E60(int init, int prio) __asm__("func_00254E60");
void sti_00254E60(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004D28B8[0] = 1.0f;
        D_004D28B8[1] = 1.0f;
        D_004D28B8[2] = 1.0f;
        D_004D28B8[3] = 0.5f;
        D_004D28C8[0] = 0.4998680055141449f;
        D_004D28C8[1] = 1.0f;
        D_004D28C8[2] = 1.0f;
        D_004D28C8[3] = 0.0f;
        D_004D28D8[0] = 0.12951700389385223f;
        D_004D28D8[1] = 1.0f;
        D_004D28D8[2] = 1.0f;
        D_004D28D8[3] = 0.0f;
        D_004D28E8[0] = 0.22426900267601013f;
        D_004D28E8[1] = 0.9402310252189636f;
        D_004D28E8[2] = 0.5425059795379639f;
        D_004D28E8[3] = 0.0004030000127386302f;
        D_004D28F8[0] = 0.4652079939842224f;
        D_004D28F8[1] = 0.32170501351356506f;
        D_004D28F8[2] = 0.9943439960479736f;
        D_004D28F8[3] = 0.0f;
        D_004D2908[0] = 0.17792600393295288f;
        D_004D2908[1] = 1.0f;
        D_004D2908[2] = 1.0f;
        D_004D2908[3] = 0.0f;
        D_004D2918[0] = 0.4411740005016327f;
        D_004D2918[1] = 0.41388601064682007f;
        D_004D2918[2] = 0.3211260139942169f;
        D_004D2918[3] = 0.4398239850997925f;
        D_004D2928[0] = 0.500997006893158f;
        D_004D2928[1] = 0.24849599599838257f;
        D_004D2928[2] = 1.0f;
        D_004D2928[3] = 1.0f;
        D_004D2938[0] = 0.27687299251556396f;
        D_004D2938[1] = 0.6395620107650757f;
        D_004D2938[2] = 0.13423900306224823f;
        D_004D2938[3] = 0.0f;
        D_004D2948[0] = 0.8936439752578735f;
        D_004D2948[1] = 0.5263469815254211f;
        D_004D2948[2] = 0.5051450133323669f;
        D_004D2948[3] = 0.8687300086021423f;
        D_004D2958[0] = 1.0f;
        D_004D2958[1] = 1.0f;
        D_004D2958[2] = 1.0f;
        D_004D2958[3] = 1.0f;
        D_004D2968[0] = 1.0f;
        D_004D2968[1] = 0.0f;
        D_004D2968[2] = 0.0f;
        D_004D2968[3] = 0.0f;
        D_004D2978[0] = 1.0f;
        D_004D2978[1] = 0.550000011920929f;
        D_004D2978[2] = 0.5350000262260437f;
        D_004D2978[3] = 0.550000011920929f;
        D_004D2988[0] = 1.0f;
        D_004D2988[1] = 1.0f;
        D_004D2988[2] = 1.0f;
        D_004D2988[3] = 1.0f;
        D_004D2998[0] = 1.0f;
        D_004D2998[1] = 1.0f;
        D_004D2998[2] = 1.0f;
        D_004D2998[3] = 1.0f;
        D_004D29A8[0] = 1.0f;
        D_004D29A8[1] = 0.0f;
        D_004D29A8[2] = 0.0f;
        D_004D29A8[3] = 0.0f;
        D_004D29B8[0] = 1.0f;
        D_004D29B8[1] = 0.0f;
        D_004D29B8[2] = 0.0f;
        D_004D29B8[3] = 0.0f;
        D_004D29C8[0] = 1.0f;
        D_004D29C8[1] = 1.0f;
        D_004D29C8[2] = 1.0f;
        D_004D29C8[3] = 1.0f;
        D_004D29D8[0] = 1.0f;
        D_004D29D8[1] = 0.5f;
        D_004D29D8[2] = 1.0f;
        D_004D29D8[3] = 0.5f;
        D_004D29E8[0] = 1.0f;
        D_004D29E8[1] = 0.5f;
        D_004D29E8[2] = 1.0f;
        D_004D29E8[3] = 0.5f;
        D_004D29F8[0] = 1.0f;
        D_004D29F8[1] = 0.5f;
        D_004D29F8[2] = 1.0f;
        D_004D29F8[3] = 0.5f;
        D_004D2A08[0] = 1.0f;
        D_004D2A08[1] = 0.7828119993209839f;
        D_004D2A08[2] = 0.06171900033950806f;
        D_004D2A08[3] = 0.03984399884939194f;
        D_004D2A18[0] = 1.0f;
        D_004D2A18[1] = 1.0f;
        D_004D2A18[2] = 0.7988259792327881f;
        D_004D2A18[3] = 0.0f;
        D_004D2A28[0] = 0.9886710047721863f;
        D_004D2A28[1] = 0.9230499863624573f;
        D_004D2A28[2] = 0.34311699867248535f;
        D_004D2A28[3] = 0.0f;
        D_004D2A38[0] = 1.0f;
        D_004D2A38[1] = 1.0f;
        D_004D2A38[2] = 1.0f;
        D_004D2A38[3] = 1.0f;
        D_004D2A48[0] = 1.0f;
        D_004D2A48[1] = 1.0f;
        D_004D2A48[2] = 0.7976430058479309f;
        D_004D2A48[3] = 0.0f;
        D_004D2A58[0] = 1.0f;
        D_004D2A58[1] = 0.9222670197486877f;
        D_004D2A58[2] = 0.34179699420928955f;
        D_004D2A58[3] = 0.0f;
        D_004D2A68[0] = 1.0f;
        D_004D2A68[1] = 0.7847639918327332f;
        D_004D2A68[2] = 0.06054700165987015f;
        D_004D2A68[3] = 0.04062499850988388f;
        D_004D2A78[0] = 1.0f;
        D_004D2A78[1] = 0.800000011920929f;
        D_004D2A78[2] = 0.44999998807907104f;
        D_004D2A78[3] = 1.0f;
        D_004D2A88[0] = 1.0f;
        D_004D2A88[1] = 0.3281260132789612f;
        D_004D2A88[2] = 1.0f;
        D_004D2A88[3] = 0.3539060056209564f;
        D_004D2A98[0] = 1.0f;
        D_004D2A98[1] = 1.0f;
        D_004D2A98[2] = 1.0f;
        D_004D2A98[3] = 1.0f;
        D_004D2AA8[0] = 1.0f;
        D_004D2AA8[1] = 1.0f;
        D_004D2AA8[2] = 1.0f;
        D_004D2AA8[3] = 1.0f;
        D_004D2AB8[0] = 1.0f;
        D_004D2AB8[1] = 0.8613290190696716f;
        D_004D2AB8[2] = 0.38124799728393555f;
        D_004D2AB8[3] = 0.0f;
        D_004D2AC8[0] = 1.0f;
        D_004D2AC8[1] = 1.0f;
        D_004D2AC8[2] = 1.0f;
        D_004D2AC8[3] = 1.0f;
        D_004D2AD8[0] = 1.0f;
        D_004D2AD8[1] = 0.3244380056858063f;
        D_004D2AD8[2] = 1.0f;
        D_004D2AD8[3] = 0.0f;
        D_004D2AE8[0] = 1.0f;
        D_004D2AE8[1] = 1.0f;
        D_004D2AE8[2] = 1.0f;
        D_004D2AE8[3] = 1.0f;
        D_004D2AF8[0] = 1.0f;
        D_004D2AF8[1] = 1.0f;
        D_004D2AF8[2] = 0.0f;
        D_004D2AF8[3] = 0.0f;
        D_004D2B08[0] = 0.7007060050964355f;
        D_004D2B08[1] = 0.0f;
        D_004D2B08[2] = 0.0f;
        D_004D2B08[3] = 0.0f;
        D_004D2B18[0] = 1.0f;
        D_004D2B18[1] = 0.7828530073165894f;
        D_004D2B18[2] = 0.06140600144863129f;
        D_004D2B18[3] = 0.04146299883723259f;
        D_004D2B28[0] = 1.0f;
        D_004D2B28[1] = 0.32487601041793823f;
        D_004D2B28[2] = 1.0f;
        D_004D2B28[3] = 0.35280099511146545f;
        D_004D2B38[0] = 1.0f;
        D_004D2B38[1] = 1.0f;
        D_004D2B38[2] = 0.7977359890937805f;
        D_004D2B38[3] = 0.0f;
        D_004D2B48[0] = 1.0f;
        D_004D2B48[1] = 0.4937489926815033f;
        D_004D2B48[2] = 1.0f;
        D_004D2B48[3] = 0.49179700016975403f;
        D_004D2B58[0] = 1.0f;
        D_004D2B58[1] = 1.0f;
        D_004D2B58[2] = 1.0f;
        D_004D2B58[3] = 1.0f;
        D_004D2B68[0] = 1.0f;
        D_004D2B68[1] = 0.800000011920929f;
        D_004D2B68[2] = 1.0f;
        D_004D2B68[3] = 0.800000011920929f;
        D_004D2B78[0] = 1.0f;
        D_004D2B78[1] = 1.0f;
        D_004D2B78[2] = 0.0f;
        D_004D2B78[3] = 0.0f;
        D_004D2B88[0] = 1.0f;
        D_004D2B88[1] = 1.0f;
        D_004D2B88[2] = 0.0f;
        D_004D2B88[3] = 0.0f;
        D_004D2B98[0] = 1.0f;
        D_004D2B98[1] = 1.0f;
        D_004D2B98[2] = 0.0f;
        D_004D2B98[3] = 0.0f;
        D_004D2BA8[0] = 1.0f;
        D_004D2BA8[1] = 0.3273420035839081f;
        D_004D2BA8[2] = 1.0f;
        D_004D2BA8[3] = 0.35390499234199524f;
        D_004D2BB8[0] = 1.0f;
        D_004D2BB8[1] = 1.0f;
        D_004D2BB8[2] = 0.061000000685453415f;
        D_004D2BB8[3] = 0.039000000804662704f;
        D_004D2BC8[0] = 1.0f;
        D_004D2BC8[1] = 1.0f;
        D_004D2BC8[2] = 0.7999979853630066f;
        D_004D2BC8[3] = 0.0f;
        D_004D2BD8[0] = 1.0f;
        D_004D2BD8[1] = 0.9589840173721313f;
        D_004D2BD8[2] = 0.6143789887428284f;
        D_004D2BD8[3] = 0.0f;
        D_004D2BE8[0] = 1.0f;
        D_004D2BE8[1] = 0.9285150170326233f;
        D_004D2BE8[2] = 0.3399839997291565f;
        D_004D2BE8[3] = 0.0f;
        D_004D2BF8[0] = 1.0f;
        D_004D2BF8[1] = 0.8738250136375427f;
        D_004D2BF8[2] = 0.24931700527668f;
        D_004D2BF8[3] = 0.017578000202775f;
        D_004D2C08[0] = 1.0f;
        D_004D2C08[1] = 0.7843739986419678f;
        D_004D2C08[2] = 0.06132800132036209f;
        D_004D2C08[3] = 0.03945299983024597f;
        D_004D2C18[0] = 1.0f;
        D_004D2C18[1] = 0.0f;
        D_004D2C18[2] = 1.0f;
        D_004D2C18[3] = 0.0f;
        D_004D2C28[0] = 1.0f;
        D_004D2C28[1] = 1.0f;
        D_004D2C28[2] = 0.0f;
        D_004D2C28[3] = 0.0f;
    }
}
#endif

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

//100%
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

