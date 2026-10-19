#include "common.h"

struct cCameraTriggerList {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xC;
    int field_0x10;
};

void cCameraTriggerList_initHeader(cCameraTriggerList* self);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_init__FP18cCameraTriggerList);
#ifdef SKIP_ASM
void cCameraTriggerList_init(cCameraTriggerList* self)
{
    self->field_0x0 = 0;
    cCameraTriggerList_initHeader(self);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", func_0016BF40);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
void tCameraTrigger__tCameraTrigger(void* self, int flags);

struct sVEntry_16BF40 { short delta; short index; void (*fn)(void*); };

struct sTrigPart_16BF40
{
    int f0;
    sVEntry_16BF40* vt;     // 0x4
};

struct sTrig_16BF40
{
    int f0;
    int f4;
    int* f8;
    sTrigPart_16BF40* fC;
    sTrigPart_16BF40* f10;
};

struct sTrigList_16BF40
{
    sTrig_16BF40** arr;
    int count;
};

extern "C" void func_0016BF40(void* self_)
{
    sTrigList_16BF40* self = (sTrigList_16BF40*)self_;
    for (int i = 0; i < self->count; i++)
    {
        if (self->arr[i]->f8)
        {
            operator_delete(self->arr[i]->f8);
            self->arr[i]->f8 = 0;
        }
        if (self->arr[i]->fC)
        {
            sTrigPart_16BF40* p = self->arr[i]->fC;
            p->vt[1].fn((char*)p + p->vt[1].delta);
            operator_delete((int*)self->arr[i]->fC);
            self->arr[i]->fC = 0;
        }
        if (self->arr[i]->f10)
        {
            sTrigPart_16BF40* p = self->arr[i]->f10;
            p->vt[1].fn((char*)p + p->vt[1].delta);
            operator_delete((int*)self->arr[i]->f10);
            self->arr[i]->f10 = 0;
        }
        if (self->arr[i])
            tCameraTrigger__tCameraTrigger(self->arr[i], 3);
        self->arr[i] = 0;
    }
    cCameraTriggerList_initHeader((cCameraTriggerList*)self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerlist", func_0016C098);
#ifdef SKIP_ASM
extern "C" void func_0016BF40(void*);
void cMemMan_free(void*);

extern "C" void func_0016C098(void** self)
{
    func_0016BF40(self);
    if (*self != 0) {
        cMemMan_free(*self);
        *self = 0;
    }
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerlist", func_0016C0D8);

struct cCameraTriggerList2 {
    void** arr; // 0x0
    int count; // 0x4
};

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_insert__FP19cCameraTriggerList2Pvi);
#ifdef SKIP_ASM
int cCameraTriggerList_insert(cCameraTriggerList2* list, void* item, int idx)
{
    if (idx < 0) {
        if (list->count >= 0x78) {
            return 0;
        }
        list->arr[list->count] = item;
        list->count++;
    } else {
        list->arr[idx] = item;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_loadFromFile);
#ifdef SKIP_ASM
extern "C" int BXFILE_exists(const char* name);
extern "C" int func_00317F98(const char* name);
extern "C" void FILE_loadpackat(const char* name, void* buf, int size);
extern "C" int cCameraTriggerList_loadFromBuffer(void* self, void* buf);
// PORT: operator_new__FUi takes (size, tag, flags, align) here.
void* operator_new_K2(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_0045BF30[];

extern "C" int cCameraTriggerList_loadFromFile(void* self, const char* name)
{
    if (!BXFILE_exists(name))
        return 1;
    func_0016BF40(self);
    int size = func_00317F98(name);
    void* buf = operator_new_K2(size, D_0045BF30, 0x100, 0);
    FILE_loadpackat(name, buf, size);
    if (buf != 0) {
        int r = cCameraTriggerList_loadFromBuffer(self, buf);
        cMemMan_free(buf);
        return r;
    }
    return 2;
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_loadFromBuffer);
#ifdef SKIP_ASM
void cCameraTriggerList_readCookie(cCameraTriggerList* self, void* buffer);
// readHeader is called with the expected version as a third argument here.
extern "C" int cCameraTriggerList_readHeader_K3(cCameraTriggerList* self, void* buffer, int version) __asm__("cCameraTriggerList_readHeader");
extern "C" int readTrigger(void* buffer, void* trigger, int version);
// PORT: cMemMan_alloc called as the game's operator new(size, tag, flags, align): gcc then treats the
// result as malloc-like (no aliasing), as the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, int flags, int d) __asm__("cMemMan_alloc");
// PORT: operator_new__FUi takes (size, tag, flags, align) here.
void* operator_new_K3(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_0045BF40[];
extern char D_0045BF58[];

struct tCameraTrigger_K3 {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int pad[2];
    int f1C;
    int f20;
    tCameraTrigger_K3() { f1C = 4; f8 = 0; fC = 0; f10 = 0; f0 = 0; f4 = 3; }
};

extern "C" int cCameraTriggerList_loadFromBuffer(void* self_, void* buf)
{
    cCameraTriggerList* self = (cCameraTriggerList*)self_;
    void* cur = buf;
    cCameraTriggerList_initHeader(self);
    cCameraTriggerList_readCookie(self, &cur);
    if (self->field_0xC != 7) {
        self->field_0xC = 7;
        return 3;
    }
    int r = cCameraTriggerList_readHeader_K3(self, &cur, 7);
    if (r != 0)
        return r;
    self->field_0x0 = (int)operator_new_K3(self->field_0x4 * 4, D_0045BF40, 0, 0);
    for (int i = 0; i < self->field_0x4; i++) {
        tCameraTrigger_K3* t = new (D_0045BF58, 0, 0) tCameraTrigger_K3;
        r = readTrigger(&cur, &t, self->field_0xC);
        if (r != 0) {
            if (t != 0)
                tCameraTrigger__tCameraTrigger(t, 3);
            return r;
        }
        cCameraTriggerList_insert((cCameraTriggerList2*)self, t, i);
    }
    self->field_0xC = 7;
    return 0;
}
#endif

INCLUDE_ASM("camera/trigger/cameratriggerlist", func_0016C388);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_initHeader__FP18cCameraTriggerList);
#ifdef SKIP_ASM
void cCameraTriggerList_initHeader(cCameraTriggerList* self)
{
    self->field_0x4 = 0;
    self->field_0xC = 7;
    self->field_0x8 = 0;
    self->field_0x10 = 0;
}
#endif

extern "C" int get_uint(void* buffer, void* dest);

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_readCookie__FP18cCameraTriggerListPv);
#ifdef SKIP_ASM
void cCameraTriggerList_readCookie(cCameraTriggerList* self, void* buffer)
{
    get_uint(buffer, (char*)self + 0xC);
}
#endif

//100%
INCLUDE_ASM("camera/trigger/cameratriggerlist", cCameraTriggerList_readHeader);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// The unit declares get_uint with C++ linkage; the target calls the unmangled symbol.
int get_uint_c(void* buffer, void* dest) __asm__("get_uint");

extern "C" int cCameraTriggerList_readHeader(cCameraTriggerList* self, void* buffer)
{
    get_uint_c(buffer, &self->field_0x10);
    get_uint_c(buffer, &self->field_0x4);
    get_uint_c(buffer, &self->field_0x8);
    return 0;
}
#endif

