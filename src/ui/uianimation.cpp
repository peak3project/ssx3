#include "common.h"

//100%
INCLUDE_ASM("ui/uianimation", cUIAnimationBank_getAnimationByHashName);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cUIAnimation_cUIAnimation(void* self, void* data);
extern const char D_004A4768[];

struct sUIAnimEntry {
    int f0;
    int f4;
    int hash;
    int size;
};

extern "C" void* cUIAnimationBank_getAnimationByHashName(unsigned int** self, int hash)
{
    sUIAnimEntry* e = (sUIAnimEntry*)(*self + 1);
    for (unsigned int i = 0; i < **self; i++) {
        if (e->hash == hash) {
            return cUIAnimation_cUIAnimation(cMemMan_alloc(0x14, D_004A4768, 0x100, 0), e);
        }
        e = (sUIAnimEntry*)((char*)e + e->size);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_003971C8);
#ifdef SKIP_ASM
struct func_003971C8_sKey {
    unsigned short dt;
    short value;
};

struct func_003971C8_sAnim {
    char pad[6];
    unsigned short count;
    func_003971C8_sKey keys[1];
};

extern "C" float func_003971C8(func_003971C8_sAnim** self, int t)
{
    func_003971C8_sAnim* a = *self;
    if (a == 0) {
        return 0.0f;
    }
    unsigned int i;
    int prevT = 0;
    float prevV = a->keys[0].value;
    int accT = 0;
    float v = 0.0f;
    func_003971C8_sKey* k = &a->keys[1];
    for (i = 1; i < a->count; i++, k++) {
        int dt = k->dt;
        accT += dt;
        v = k->value;
        if (accT >= t) {
            return (float)(t - prevT) / (float)dt * (v - prevV) + prevV;
        }
        prevT = accT;
        prevV = v;
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_00397278);
#ifdef SKIP_ASM
extern "C" unsigned short func_00397278(void* self)
{
    void* p = *(void**)self;
    if (p != 0) {
        return *(unsigned short*)((char*)p + 0x2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_00397298__FPvi);
#ifdef SKIP_ASM
void func_00397298(void* self, int val)
{
    *(int*)((char*)self + 0x0) = val;
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", cUIAnimation_cUIAnimation);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void func_00397298(void* self, int val);
extern char D_00493D60[];
extern void* D_00494D08[];

extern "C" void* cUIAnimation_cUIAnimation(void* self, void* data)
{
    *(void***)((char*)self + 0x10) = D_00494D08;
    *(void**)self = data;
    *(int*)((char*)self + 0x4) = 0;
    *(short*)((char*)self + 0x8) = -1;
    *(short*)((char*)self + 0xA) = 0;
    *(unsigned short*)((char*)self + 0xC) = 0xFFFF;
    int** slot = (int**)((char*)self + 0x4);
    unsigned int n = *(unsigned int*)((char*)data + 4);
    if (n != 0) {
        int* p = (int*)operator_new_tag(n * 4 + 0x10, D_00493D60, 0x100, 0);
        p[0] = n;
        int* arr = p + 4;
        int* e = arr;
        for (int i = n - 1; i != -1; i--, e++) {
            *e = 0;
        }
        *slot = arr;
        char* q = *(char**)self + 0x10;
        for (unsigned int i = 0; i < *(unsigned int*)(*(char**)self + 4); i++) {
            // PORT: the entry pointer is passed as int
            func_00397298(*(char**)((char*)self + 0x4) + (i << 2), (int)q);
            q += *(unsigned short*)(q + 4);
        }
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_003973A8);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int* ptr);
extern void* D_00494D08[];

extern "C" void func_003973A8(void* self, int flags)
{
    *(void***)((char*)self + 0x10) = D_00494D08;
    char* base = *(char**)((char*)self + 0x4);
    if (base != 0) {
        char* p = base + *(int*)(base - 0x10) * 4;
        while (*(char**)((char*)self + 0x4) != p) {
            p -= 4;
        }
        cMemMan_free(*(char**)((char*)self + 0x4) - 0x10);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

INCLUDE_ASM("ui/uianimation", func_00397440);

INCLUDE_ASM("ui/uianimation", func_00397458);

//100%
INCLUDE_ASM("ui/uianimation", func_00397468);
#ifdef SKIP_ASM
extern "C" void func_00397468(void* self, int mode, unsigned short v)
{
    mode &= 7;
    if (mode == 0) {
        *(unsigned short*)((char*)self + 0xc) = v;
    }
    if (mode == 2) {
        *(unsigned char*)((char*)self + 0xe) = 1;
        *(unsigned short*)((char*)self + 0xa) = *(unsigned short*)((char*)*(void**)self + 0x2) - 1;
    } else {
        *(unsigned char*)((char*)self + 0xe) = 0;
        *(unsigned short*)((char*)self + 0xa) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_003974B0);
#ifdef SKIP_ASM
struct func_003974B0_sData {
    short pad0;
    unsigned short count;
};

struct func_003974B0_sAnim {
    func_003974B0_sData* data;
    char pad4[6];
    short frame;
    short padc;
    signed char dir;
};

extern "C" void func_003974B0(func_003974B0_sAnim* self, unsigned char flags)
{
    func_003974B0_sData* data = self->data;
    int mode;
    if (data == 0) {
        return;
    }
    mode = flags & 7;
    if (mode == 0) {
        return;
    }
    switch (mode) {
    case 2:
        self->frame--;
        if (self->frame < 0) {
            if (flags & 8) {
                self->frame = data->count - 1;
            } else {
                self->frame = 0;
            }
        }
        break;
    case 1:
        self->frame++;
        if (self->frame >= data->count) {
            if (!(flags & 8)) {
                self->frame = data->count - 1;
            } else {
                self->frame = 0;
            }
        }
        break;
    case 3:
        if (self->dir == 0) {
            self->frame++;
        } else {
            self->frame--;
        }
        if (self->dir == 0) {
            if (self->frame >= self->data->count) {
                self->dir = 1;
                self->frame = self->data->count - 1;
                return;
            }
        }
        if (self->dir == 1 && self->frame < 0) {
            self->dir = 0;
            self->frame = 0;
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uianimation", func_003975E0);
#ifdef SKIP_ASM
struct sUIAnimVt75E0 { short delta; short index; void (*fn)(void*, int, float); };
struct sUIAnimHdr75E0 { short f0; unsigned short nframes; unsigned int ntracks; };
struct sUIAnim75E0 {
    sUIAnimHdr75E0* hdr;        // 0x0
    char* tracks;               // 0x4
    short cur;                  // 0x8
    short frame;                // 0xA
    unsigned short start;       // 0xC
};

extern "C" void func_003975E0(sUIAnim75E0* self, char* obj, int mode, unsigned short t)
{
    unsigned short frame = self->frame;
    if ((mode & 7) == 0 && self->start != 0xFFFF) {
        if (t < self->start) return;
        frame = t - self->start;
        if (self->frame == frame) return;
        self->frame = frame;
    }
    if (self->cur == frame) return;
    if (frame < self->hdr->nframes) {
        for (unsigned int i = 0; i < self->hdr->ntracks; i++) {
            float v = func_003971C8((func_003971C8_sAnim**)(self->tracks + (i << 2)), frame);
            sUIAnimVt75E0* vt = *(sUIAnimVt75E0**)(obj + 8);
            vt[12].fn(obj + vt[12].delta, func_00397278(self->tracks + (i << 2)), v);
        }
    }
    self->cur = frame;
}
#endif

