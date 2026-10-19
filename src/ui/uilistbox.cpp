#include "common.h"

//100%
INCLUDE_ASM("ui/uilistbox", cUIListBox_addEntryByAsciiString);
#ifdef SKIP_ASM
extern "C" int strlen(const char*);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void UIAsciiToUnicode(unsigned short* dst, const char* src);
extern char D_00493DD0[];

extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data)
{
    unsigned short* u = (unsigned short*)operator_new_tag((strlen(text) + 1) * 2, D_00493DD0, 0x100, 0);
    UIAsciiToUnicode(u, text);
    *(const char**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA0) = text;
    *(unsigned short**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0x9C) = u;
    *(int*)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA4) = data;
    return (*(unsigned char*)((char*)self + 0x318))++;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A4B0);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern char D_00493DC0[];

extern "C" unsigned char func_0039A4B0(void* self, unsigned short* str, int data)
{
    unsigned short* u = (unsigned short*)operator_new_tag((USTR_length(str) + 1) * 2, D_00493DC0, 0x100, 0);
    USTR_copy(u, str);
    *(const char**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA0) = 0;
    *(unsigned short**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0x9C) = u;
    *(int*)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA4) = data;
    return (*(unsigned char*)((char*)self + 0x318))++;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", cUIListBox_addEntryByStringID);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int USTR_length(unsigned short* s);
extern "C" void USTR_copy(unsigned short* dst, unsigned short* src);
extern char D_00493DE0[];

struct sUIStrVtA568 { short delta; short index; unsigned short* (*fn)(void*, int); };

extern "C" unsigned char cUIListBox_addEntryByStringID(void* self, int id, int data)
{
    char* tbl = *(char**)(*(char**)(*(char**)(*(char**)((char*)self + 0x5C) + 0xD0) + 0x10) + 0x10);
    if (tbl != 0) {
        sUIStrVtA568* vt = *(sUIStrVtA568**)(tbl + 4);
        unsigned short* str = vt[4].fn(tbl + vt[4].delta, id);
        if (str != 0) {
            unsigned short* u = (unsigned short*)operator_new_tag((USTR_length(str) + 1) * 2, D_00493DE0, 0x100, 0);
            USTR_copy(u, str);
            *(const char**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA0) = 0;
            *(unsigned short**)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0x9C) = u;
            *(int*)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0xA4) = data;
            *(int*)((char*)self + *(unsigned char*)((char*)self + 0x318) * 0x14 + 0x98) = id;
        }
    }
    return (*(unsigned char*)((char*)self + 0x318))++;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A670);
#ifdef SKIP_ASM
void cMemMan_free(void*);

struct func_0039A670_sItem {
    void* data;
    char pad[0x10];
};

extern "C" void func_0039A670(void* self)
{
    if (*(int*)((char*)self + 0x74) & 0x10) {
        if (*(void**)((char*)self + 0x9C) != 0) {
            cMemMan_free(*(void**)((char*)self + 0x9C));
        }
    } else {
        for (int i = 0; i < *(unsigned char*)((char*)self + 0x318); i++) {
            func_0039A670_sItem* it = (func_0039A670_sItem*)((char*)self + 0x9C) + i;
            if (it->data != 0) {
                cMemMan_free(it->data);
            }
        }
    }
    *(unsigned char*)((char*)self + 0x319) = 0;
    *(unsigned char*)((char*)self + 0x318) = 0;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A708);
#ifdef SKIP_ASM
extern "C" int func_0039A708(void* self)
{
    if (*(unsigned char*)((char*)self + 0x319) < *(unsigned char*)((char*)self + 0x318)) {
        return *(int*)((char*)self + *(unsigned char*)((char*)self + 0x319) * 0x14 + 0xA0);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A738);
#ifdef SKIP_ASM
extern "C" int func_0039A738(void* self)
{
    if (*(unsigned char*)((char*)self + 0x319) < *(unsigned char*)((char*)self + 0x318)) {
        return *(int*)((char*)self + *(unsigned char*)((char*)self + 0x319) * 0x14 + 0xA4);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A768);
#ifdef SKIP_ASM
extern "C" int func_0039A768(void* self, int key, unsigned char* out)
{
    int i;
    for (i = 0; i < *(unsigned char*)((char*)self + 0x318); i++) {
        if (*(int*)((char*)self + i * 0x14 + 0xA4) == key) {
            *out = i;
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A7A8);
#ifdef SKIP_ASM
extern "C" void func_0039A7A8(void* self, int a1)
{
    unsigned char v = (unsigned char)a1;
    if (v < *(unsigned char*)((char*)self + 0x318)) {
        *(char*)((char*)self + 0x319) = v;
    }
}
#endif

INCLUDE_ASM("ui/uilistbox", func_0039A7C8);

//100%
INCLUDE_ASM("ui/uilistbox", cUIListBox_setEntryByAsciiString);
#ifdef SKIP_ASM
extern "C" int strlen(const char*);
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
void UIAsciiToUnicode(unsigned short* dst, const char* src);
extern char D_00493DF0[];

struct cUIListBox_sEntry {
    int id;
    unsigned short* str;
    const char* text;
    int data;
    signed char cap;
};

struct cUIListBox_sObj {
    char pad[0x98];
    cUIListBox_sEntry entries[32];
    unsigned char count;
    unsigned char cur;
};

extern "C" void cUIListBox_setEntryByAsciiString(cUIListBox_sObj* self, unsigned char idx, const char* text, int data)
{
    int len = strlen(text) + 1;
    unsigned short* u = self->entries[idx].str;
    if (u != 0) {
        if (len < self->entries[idx].cap) {
            cMemMan_free(u);
            u = 0;
        }
    }
    if (u == 0) {
        u = (unsigned short*)operator_new_tag(len * 2, D_00493DF0, 0x100, 0);
    }
    UIAsciiToUnicode(u, text);
    self->entries[idx].str = u;
    self->entries[idx].text = text;
    self->entries[idx].data = data;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A8D8);
#ifdef SKIP_ASM
struct sVEntry39A8D8 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_0039A8D8(void* self, int count)
{
    *(char*)((char*)self + 0x318) = count;
    *(char*)((char*)self + 0x319) = 0;
    *(int*)((char*)self + 0x74) |= 0x10;
    void* obj = *(void**)(*(char**)((char*)self + 0x5C) + 0xD0);
    sVEntry39A8D8* vt = *(sVEntry39A8D8**)((char*)obj + 8);
    vt[0x13].fn((char*)obj + vt[0x13].delta, self, 9);
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039A928);
#ifdef SKIP_ASM
struct cUIThing;
unsigned short cUIThing_getKeyframerEvent(cUIThing* self, int x);
extern "C" void cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" unsigned char func_0039B7B0(void* self, int a1);

struct sVEntry39A928a {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sVEntry39A928b {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

struct sUIFlags39A928 {
    unsigned int pad0 : 4;
    unsigned int active : 1;
};

extern "C" void func_0039A928(char* self, int on)
{
    ((sUIFlags39A928*)(self + 0x14))->active = on != 0;
    if (on) {
        if (*(unsigned char*)(self + 0xA4) != 0xFF) {
            cUIMenu_setSelectedByIndex(self, *(unsigned char*)(self + 0xA4));
            return;
        }
        char* cur = *(char**)(self + 0xA0);
        if (cur == 0) {
            unsigned char idx = func_0039B7B0(self, 0);
            if (idx == 0xFF)
                idx = 0;
            cUIMenu_setSelectedByIndex(self, idx);
        } else if (((*(int*)(cur + 0x14) >> 4) & 1) == 0) {
            unsigned short ev = cUIThing_getKeyframerEvent((cUIThing*)cur, 0);
            if (ev != 0xFFFF) {
                void* scr = *(void**)(*(char**)(self + 0xA0) + 0x5C);
                if (scr != 0) {
                    cUIScreen_playFrame(scr, ev, 1);
                }
            }
            char* c = *(char**)(self + 0xA0);
            sVEntry39A928a* va = *(sVEntry39A928a**)(c + 8);
            va[7].fn(c + va[7].delta, 1);
            char* o = *(char**)(*(char**)(self + 0x5C) + 0xD0);
            sVEntry39A928b* vb = *(sVEntry39A928b**)(o + 8);
            vb[19].fn(o + vb[19].delta, *(void**)(self + 0xA0), 1);
        }
    } else {
        char* cur = *(char**)(self + 0xA0);
        if (cur != 0) {
            unsigned short ev = cUIThing_getKeyframerEvent((cUIThing*)cur, 1);
            if (ev != 0xFFFF) {
                void* scr = *(void**)(*(char**)(self + 0xA0) + 0x5C);
                if (scr != 0) {
                    cUIScreen_playFrame(scr, ev, 1);
                }
            }
            char* c = *(char**)(self + 0xA0);
            sVEntry39A928a* va = *(sVEntry39A928a**)(c + 8);
            va[7].fn(c + va[7].delta, 0);
            char* o = *(char**)(*(char**)(self + 0x5C) + 0xD0);
            sVEntry39A928b* vb = *(sVEntry39A928b**)(o + 8);
            vb[19].fn(o + vb[19].delta, *(void**)(self + 0xA0), 2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039AAC0);
#ifdef SKIP_ASM
extern "C" void* func_0039FE00(void* self);
extern "C" char func_003979C0(void*);
extern "C" void func_0039AB00(void* self, char a1);

extern "C" void func_0039AAC0(void* self)
{
    func_0039FE00(self);
    char v = func_003979C0((char*)self + 0x74);
    *(char*)((char*)self + 0x97) = v;
    *(char*)((char*)self + 0x96) = v;
    func_0039AB00(self, 0);
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039AB00);
#ifdef SKIP_ASM
extern "C" void func_0039AB00(void* self, char a1)
{
    if (a1 == 0) {
        *(char*)((char*)self + 0x91) = 0;
        *(char*)((char*)self + 0x92) = 1;
        *(char*)((char*)self + 0x93) = 2;
        *(char*)((char*)self + 0x94) = 3;
    } else {
        *(char*)((char*)self + 0x91) = 4;
        *(char*)((char*)self + 0x92) = 5;
        *(char*)((char*)self + 0x93) = 6;
        *(char*)((char*)self + 0x94) = 7;
    }
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039AB50);
#ifdef SKIP_ASM
extern "C" void* func_00397870(void* list, unsigned char i);

struct sUIVtAB50 { short delta; short index; int (*fn)(void*, void*, int, int); };

extern "C" unsigned char func_0039AB50(void* self)
{
    unsigned char i = *(unsigned char*)((char*)self + 0x95) + 1;
    unsigned char n = *(unsigned char*)((char*)self + 0x96);
    do {
        if (i < *(unsigned char*)((char*)self + 0x96)) {
            if (*(int*)((char*)self + 0x90) & 4) {
                char* o = *(char**)(*(char**)((char*)self + 0x5C) + 0xD0);
                sUIVtAB50* vt = *(sUIVtAB50**)(o + 8);
                if (vt[20].fn(o + vt[20].delta, self, 1, i) != 0) return i;
            } else {
                char* e = (char*)func_00397870((char*)self + 0x74, i);
                int f = *(int*)(e + 0x14) >> 5;
                if ((f & 1) == 0) return i;
            }
            i = i + 1;
        } else {
            int f = *(int*)((char*)self + 0x14) >> 7;
            if ((f & 1) == 0) return *(unsigned char*)((char*)self + 0x95);
            i = 0;
        }
    } while (n-- != 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ui/uilistbox", func_0039AC48);
#ifdef SKIP_ASM
extern "C" void* func_00397870(void* list, unsigned char i);

struct func_0039AC48_sVEntry {
    short delta;
    short index;
    int (*fn)(void*, void*, int, unsigned char);
};

extern "C" unsigned char func_0039AC48(void* self)
{
    unsigned char n = *(unsigned char*)((char*)self + 0x96);
    unsigned char i = *(unsigned char*)((char*)self + 0x95) - 1;
    do {
        if (i != 0xFF) {
            if (*(int*)((char*)self + 0x90) & 4) {
                char* mgr = *(char**)(*(char**)((char*)self + 0x5C) + 0xD0);
                func_0039AC48_sVEntry* vt = *(func_0039AC48_sVEntry**)(mgr + 8);
                if (vt[20].fn(mgr + vt[20].delta, self, 1, i)) {
                    return i;
                }
            } else {
                void* item = func_00397870((char*)self + 0x74, i);
                int f = *(int*)((char*)item + 0x14);
                if (((f >> 5) & 1) == 0) {
                    return i;
                }
            }
            i--;
        } else {
            int f = *(int*)((char*)self + 0x14) >> 7;
            if ((f & 1) == 0) {
                return *(unsigned char*)((char*)self + 0x95);
            }
            i = *(unsigned char*)((char*)self + 0x96) - 1;
        }
        n--;
    } while (n != 0xFF);
    return 0;
}
#endif

