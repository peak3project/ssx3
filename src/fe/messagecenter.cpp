#include "common.h"

INCLUDE_ASM("fe/messagecenter", cFEStateRequestLine_onWidgetCreate);

//100%
INCLUDE_ASM("fe/messagecenter", func_00197500);
#ifdef SKIP_ASM
extern "C" void func_00197CA0(void* self);
extern "C" void func_00198118(void* self);
extern "C" void func_00198988_7500(void* self, int idx) __asm__("func_00198988");
extern "C" void cFEStateRequestLine_updateHilightedSongInfo(void* self, int idx);
extern "C" void cFEStateRequestLine_updateHelpText(void* self, int idx);
extern "C" void cFEStateRequestLine_updateButtonsText(void* self, int idx);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_00158848(void* iface, int a, int b, unsigned long m);
extern "C" void func_00158820(void* iface, int a, int b, unsigned long m);
extern "C" void* func_0028B180();
extern "C" void func_0028C2D0(void* p, unsigned long m);
extern "C" void func_0039F190(void* list, int a);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00195FF0(void* mem, void* engine, int a, int b);
extern "C" void func_0039F400(void* list, void* item);
int func_00198AE8(void* self, int idx) __asm__("func_00198AE8__FPv");
extern char* D_004A28A8;
extern const char D_00460650[];

struct sReqLine_7500 {
    char pad_0x0[0x10];
    char* engine;           // 0x10
    char pad_0x14[0x30];
    signed char player;     // 0x44
    char pad_0x45[3];
    int f48;                // 0x48
    int list[64];           // 0x4C
    int count;              // 0x14C
    int top;                // 0x150
    char pad_0x154[0x4];
    unsigned long done;     // 0x158
    unsigned long sel;      // 0x160
    int limit;              // 0x168
    int f16C;               // 0x16C
};

struct sVE_7500 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline int isSet_7500(unsigned long m, int i)
{
    return (m >> i) & 1;
}

static inline int onlyBit_7500(unsigned long m, int i)
{
    unsigned long rest = m & ~((unsigned long)1 << i);
    return rest == 0;
}

static inline int countSel_7500(sReqLine_7500* self)
{
    int n = 0;
    for (int i = 0; i < 64; i++) {
        n += (self->sel >> i) & 1;
    }
    return n;
}

// Request-line widget events: 1 hilights a song, 5 toggles it (done/selected masks), 6 saves the masks and leaves.
extern "C" void func_00197500(void* p, void* item, unsigned int msg)
{
    sReqLine_7500* self = (sReqLine_7500*)p;
    if (item == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        int k = self->top + *(int*)((char*)item + 0x18);
        if (k >= self->count) {
            return;
        }
        int idx = self->list[k];
        if (!isSet_7500(self->sel, idx)) {
            if (self->f16C != 0) {
                if (self->limit >= func_00198AE8(self, idx) || countSel_7500(self) < 6) {
                    func_00198988_7500(self, idx);
                }
            }
        } else {
            unsigned long done = self->done;
            int empty = done == 0;
            if (empty || !onlyBit_7500(done, idx)) {
                if (isSet_7500(done, idx)) {
                    self->done = done & ~((unsigned long)1 << idx);
                } else {
                    self->done = done | ((unsigned long)1 << idx);
                }
                func_00197CA0(self);
                func_00198118(self);
            }
        }
        cFEStateRequestLine_updateButtonsText(self, idx);
        break;
    }
    case 6: {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 0xD);
        func_00158848(iface, self->player, self->f48, self->done);
        func_00158820(iface, self->player, self->f48, self->sel);
        func_0028C2D0(func_0028B180(), self->done);
        if (self->f16C != 0) {
            char* pl = (char*)func_0028B180();
            sVE_7500* vt = *(sVE_7500**)(pl + 0x5558);
            char* obj = pl + 0x118;
            vt[3].fn(obj + vt[3].delta, 0xA);
        }
        if (*(int*)(D_004A28A8 + 0x84) != 0) {
            func_0039F190(self->engine + 0x18, 1);
        } else {
            void* r = func_00195FF0(cMemMan_alloc(0x80, D_00460650, 0, 0), self->engine, self->player, self->f16C);
            if (r != 0) {
                func_0039F400(self->engine + 0x18, r);
            }
        }
        break;
    }
    case 1: {
        int idx = self->list[self->top + *(int*)((char*)item + 0x18)];
        cFEStateRequestLine_updateHilightedSongInfo(self, idx);
        cFEStateRequestLine_updateHelpText(self, idx);
        cFEStateRequestLine_updateButtonsText(self, idx);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_001977D0);
#ifdef SKIP_ASM
extern "C" void func_00197E70(void* self);
extern "C" void func_00197B88(void* self);
extern "C" void func_0028CF98(void* p, int a, int b, long c, int d);
extern "C" void func_002B4978(void* list, int idx);

extern "C" int func_001977D0(void* p, void* item, unsigned int msg, int k)
{
    sReqLine_7500* self = (sReqLine_7500*)p;
    switch (msg) {
    case 6: {
        int idx = self->list[self->top + k];
        if (onlyBit_7500(self->done, idx)) {
            if (self->f16C != 0) {
                if (!isSet_7500(self->sel, idx))
                    return 0x101;
            }
            return 0x10;
        }
        if (self->f16C == 0) {
            if (isSet_7500(self->sel, idx))
                return 0x101;
        } else {
            if (self->limit < func_00198AE8(self, idx)) {
                if (countSel_7500(self) >= 6)
                    goto ret10;
            }
            break;
        }
        goto ret10;
    }
    case 9:
        return 0;
    case 8: {
        int n;
        int idx;
        n = self->top + k;
        if (n < self->count) {
            idx = self->list[n];
            if (*(int*)(D_004A28A8 + 0x84) != 0) {
                if (!isSet_7500(self->sel, idx)) {
                ret10:
                    return 0x10;
                }
                *(int*)((char*)func_0028B180() + 0x508) = idx;
                func_0028CF98(func_0028B180(), 0, 0, -1, 1);
                func_00197E70(self);
            } else {
                func_002B4978((char*)func_0028B180() + 0x118, idx);
            }
        }
        break;
    }
    case 4:
        self->top = k;
        func_00197B88(self);
        break;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_001979D8);
#ifdef SKIP_ASM
extern "C" void func_001988D8(void* self, int idx);
extern "C" void func_00197B88(void* self);
extern "C" void cFEStateRequestLine_updateHilightedSongInfo(void* self, int a1);
extern "C" void func_001985B0(void* self);
extern "C" void func_001985F0(void* self);
extern "C" void cFEStateRequestLine_updateButtonsText(void* self, int a1);
extern "C" void cFEStateRequestLine_updateHelpText(void* self, int a1);

struct sMsgCenter_979D8 {
    char pad_0x0[0x1C];
    int flags;        // 0x1C
    char pad_0x20[0x2C];
    int list[64];     // 0x4C
    int count;        // 0x14C
    int top;          // 0x150
    char pad_0x154[0x1C];
    char* menu;       // 0x170
};

extern "C" void func_001979D8(sMsgCenter_979D8* self, void* item, int msg)
{
    switch (msg) {
    case 0x15:
        if (*(int*)((char*)item + 0xC) != 7) {
            self->flags &= ~8;
        }
        break;
    case 0x16:
        if (((self->flags >> 3) & 1) == 0) {
            self->flags |= 8;
        }
        if (*(int*)((char*)item + 0xC) == 7 && *(int*)((char*)item + 0x6C) != 0) {
            int song = self->list[self->top + *(int*)(*(char**)(self->menu + 0xA0) + 0x18)];
            func_001988D8(self, song);
            func_00197B88(self);
            cFEStateRequestLine_updateHilightedSongInfo(self, song);
            func_001985B0(self);
            func_001985F0(self);
            cFEStateRequestLine_updateButtonsText(self, song);
            cFEStateRequestLine_updateHelpText(self, song);
        }
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197AD8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sMsgCenter_97AD8 {
    char pad_0x0[0x4C];
    int list[64];   // 0x4C
    int count;      // 0x14C
    char pad_0x150[0x10];
    ulong mask;     // 0x160
};

extern "C" void func_00197AD8(void* self)
{
    sMsgCenter_97AD8* s = (sMsgCenter_97AD8*)self;
    int i;
    int j;
    int n = 0;
    for (i = 0; i < s->count; i++) {
        if ((int)((s->mask >> i) & 1)) {
            s->list[n++] = i;
        }
    }
    for (j = 0; j < s->count; j++) {
        if (!(int)((s->mask >> j) & 1)) {
            s->list[n++] = j;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197B88);
#ifdef SKIP_ASM
extern "C" void func_00197BC8(void* self);
extern "C" void func_00197CA0(void* self);
extern "C" void func_00197DB8(void* self);
extern "C" void func_00198118(void* self);

extern "C" void func_00197B88(void* self)
{
    func_00197BC8(self);
    func_00197CA0(self);
    func_00197DB8(self);
    func_00198118(self);
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197BC8);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* func_00198A88(void* self, int i);

class cMsgWidget_97BC8 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

struct sMsgCenter_97BC8 {
    char pad_0x0[0x4C];
    int list[64];   // 0x4C
    int count;      // 0x14C
    int top;        // 0x150
    char pad_0x154[0x20];
    cMsgWidget_97BC8* texts[8]; // 0x174
};

extern "C" void func_00197BC8(void* self)
{
    sMsgCenter_97BC8* s = (sMsgCenter_97BC8*)self;
    int i;
    for (i = 0; i < 8; i++) {
        int idx = s->top + i;
        if (idx < s->count) {
            int id = s->list[idx];
            s->texts[i]->show(1);
            cUIText_setAsciiString((cUIText*)s->texts[i], (const char*)func_00198A88(self, id));
        } else {
            s->texts[i]->show(0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197CA0);
#ifdef SKIP_ASM
class cMsgWidget_97CA0 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};
// PORT: 64-bit `long` masks (8 bytes on EE, 4 on Windows); use uint64_t off-PS2.
struct sMsgCenter_97CA0 {
    char pad_0x0[0x4C];
    int list[64];   // 0x4C
    int count;      // 0x14C
    int top;        // 0x150
    char pad_0x154[0x4];
    ulong newMask;  // 0x158
    ulong readMask; // 0x160
    char pad_0x168[0x2C];
    cMsgWidget_97CA0* icons[8]; // 0x194
    char pad_0x1B4[0x50];
    int colNew;     // 0x204
    int colRead;    // 0x208
    int colOther;   // 0x20C
};

static inline void setColors_97CA0(cMsgWidget_97CA0* w, int a, int b)
{
    *(int*)((char*)w + 0x78) = a;
    *(int*)((char*)w + 0x7C) = b;
}

static inline int isNew_97CA0(sMsgCenter_97CA0* s, int id)
{
    return (int)((s->newMask >> id) & 1);
}

static inline int isRead_97CA0(sMsgCenter_97CA0* s, int id)
{
    return (int)((s->readMask >> id) & 1);
}

static inline void setVisible_97CA0(cMsgWidget_97CA0* w, int v)
{
    w->show(v);
}

extern "C" void func_00197CA0(void* self)
{
    sMsgCenter_97CA0* s = (sMsgCenter_97CA0*)self;
    int i;
    for (i = 0; i < 8; i++) {
        setVisible_97CA0(s->icons[i], 0);
        int idx = s->top + i;
        if (idx < s->count) {
            int id = s->list[idx];
            setVisible_97CA0(s->icons[i], 1);
            if (isNew_97CA0(s, id)) {
                setColors_97CA0(s->icons[i], -1, s->colNew);
            } else if (isRead_97CA0(s, id)) {
                setColors_97CA0(s->icons[i], -1, s->colRead);
            } else {
                setColors_97CA0(s->icons[i], -1, s->colOther);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197DB8);
#ifdef SKIP_ASM
class cMsgWidget_97DB8 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

extern "C" void func_00197DB8(void* self)
{
    if (*(int*)((char*)self + 0x150) == 0) {
        (*(cMsgWidget_97DB8**)((char*)self + 0x1EC))->show(0);
    } else {
        (*(cMsgWidget_97DB8**)((char*)self + 0x1EC))->show(1);
    }
    if (*(int*)((char*)self + 0x150) + 8 >= *(int*)((char*)self + 0x14C)) {
        (*(cMsgWidget_97DB8**)((char*)self + 0x1F0))->show(0);
    } else {
        (*(cMsgWidget_97DB8**)((char*)self + 0x1F0))->show(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00197E70);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int USTR_length(unsigned short* s);
extern "C" int strlen(const char* s);
void cMemMan_free(void* p);
extern "C" void func_002C26D0(unsigned short* dst, unsigned short* fmt, int n);
extern "C" void func_003A0E90(void* text, void* p);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_0028B180();
extern "C" void* func_002B40F0(void* self, int i);
extern "C" void* func_002B4120(void* self, int i);
extern char D_00460470[];
extern char D_00460668[];
extern char D_00460678[];
extern char* D_004A28A8;

struct sVtEntry_197E70 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

class cMsgWidget_197E70 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

struct sReqLine_197E70 {
    char pad_0x0[0x1B4];
    cMsgWidget_197E70* title;   // 0x1B4
    cMsgWidget_197E70* artist;  // 0x1B8
};

extern "C" void func_00197E70(void* vself)
{
    sReqLine_197E70* self = (sReqLine_197E70*)vself;
    if (self->title == 0 || self->artist == 0) {
        return;
    }
    int cur = *(int*)((char*)func_0028B180() + 0x508);
    if (cur < *(int*)((char*)func_0028B180() + 0x504)) {
        char* name = (char*)func_002B40F0((char*)func_0028B180() + 0x118, cur);
        char* artist = (char*)func_002B4120((char*)func_0028B180() + 0x118, cur);
        if (strlen(name) != 0) {
            self->title->show(1);
            char* db = *(char**)(D_004A28A8 + 0x8C);
            sVtEntry_197E70* vt = *(sVtEntry_197E70**)(db + 4);
            unsigned short* fmt = vt[4].fn(db + vt[4].delta, GetHashValue32(D_00460668));
            int len = USTR_length(fmt) + strlen(name) + 1;
            unsigned short* buf = (unsigned short*)operator_new_tag(len * 2, D_00460470, 0x100, 0);
            // PORT: the format argument is a string pointer passed through an int parameter
            func_002C26D0(buf, fmt, (int)name);
            func_003A0E90(self->title, buf);
            if (buf != 0) {
                cMemMan_free(buf);
            }
        } else {
            self->title->show(0);
        }
        if (strlen(artist) != 0) {
            self->artist->show(1);
            char* db = *(char**)(D_004A28A8 + 0x8C);
            sVtEntry_197E70* vt = *(sVtEntry_197E70**)(db + 4);
            unsigned short* fmt = vt[4].fn(db + vt[4].delta, GetHashValue32(D_00460678));
            int len = USTR_length(fmt) + strlen(artist) + 1;
            unsigned short* buf = (unsigned short*)operator_new_tag(len * 2, D_00460470, 0x100, 0);
            // PORT: the format argument is a string pointer passed through an int parameter
            func_002C26D0(buf, fmt, (int)artist);
            func_003A0E90(self->artist, buf);
            if (buf != 0) {
                cMemMan_free(buf);
            }
        } else {
            self->artist->show(0);
        }
    } else {
        self->title->show(0);
        self->artist->show(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198118);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int USTR_length(unsigned short* s);
void cMemMan_free(void* p);
extern "C" void func_002C26D0(unsigned short* dst, unsigned short* fmt, int n);
extern "C" void func_003A0E90(void* text, void* p);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_004605D8[];
extern char D_00460688[];
extern char* D_004A28A8;

struct sVtEntry_00198118 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sMsgCenter_00198118 {
    char pad_0x0[0x158];
    ulong mask;     // 0x158
    char pad_0x160[0x84];
    void* text;     // 0x1E4
};

extern "C" void func_00198118(void* p)
{
    sMsgCenter_00198118* self = (sMsgCenter_00198118*)p;
    char* db = *(char**)(D_004A28A8 + 0x8C);
    sVtEntry_00198118* vt = *(sVtEntry_00198118**)(db + 4);
    unsigned short* fmt = vt[4].fn(db + vt[4].delta, GetHashValue32(D_004605D8));
    unsigned short* buf = (unsigned short*)operator_new_tag((USTR_length(fmt) + 5) * 2, D_00460688, 0x100, 0);
    int n = 0;
    int j;
    for (j = 0; j < 64; j++) {
        n += (int)((self->mask >> j) & 1);
    }
    func_002C26D0(buf, fmt, n);
    func_003A0E90(self->text, buf);
    if (buf != 0) {
        cMemMan_free(buf);
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", cFEStateRequestLine_updateHelpText);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* text, int id);
int func_00198AE8(void* self);
extern char D_004606B0[];
extern char D_004606C8[];
extern char D_004606E0[];
extern char D_004606F8[];
extern char D_00460710[];
extern char D_00460720[];
extern signed char D_00535C11[];

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sReqLine_001981F8 {
    char pad_0x0[0x158];
    ulong done;     // 0x158
    ulong sel;      // 0x160
    int count;      // 0x168
    int f16C;       // 0x16C
    char pad_0x170[0x78];
    cUIText* text;  // 0x1E8
};

static inline int countSel_001981F8(sReqLine_001981F8* self)
{
    int n = 0;
    for (int i = 0; i < 64; i++) {
        n += (self->sel >> i) & 1;
    }
    return n;
}

extern "C" void cFEStateRequestLine_updateHelpText(void* p, int idx)
{
    sReqLine_001981F8* self = (sReqLine_001981F8*)p;
    if (self->text == 0) {
        return;
    }
    int on = (self->sel >> idx) & 1;
    if (on) {
        ulong bit = (ulong)1 << idx;
        int only = (self->done & ~bit) == 0;
        if (only) {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_004606B0));
        } else {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_004606C8));
        }
    } else if (self->f16C != 0) {
        if (self->count >= func_00198AE8(self) || countSel_001981F8(self) < 6) {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_004606E0));
        } else {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_004606F8));
        }
    } else {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        if (D_00535C11[0] == 0) {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_00460710));
        } else {
            cUIText_setUnicodeStringByID(self->text, GetHashValue32(D_00460720));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", cFEStateRequestLine_updateButtonsText);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
int func_00198AE8_UBT(void* self, int idx) __asm__("func_00198AE8__FPv");
extern char D_004A1390[];
extern char D_00460738[];
extern char D_00460748[];
extern char D_00460758[];
extern char* D_004A28A8;

class cUIObj_UBT {
public:
    int pad[2];
    virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void setVisible(int on);
};

struct sReqLine_UBT {
    char pad_0x0[0x158];
    unsigned long done;     // 0x158
    unsigned long sel;      // 0x160
    int count;              // 0x168
    int f16C;               // 0x16C
    char pad_0x170[0x1F4 - 0x170];
    cUIObj_UBT* text;       // 0x1F4
    cUIObj_UBT* back;       // 0x1F8
    cUIObj_UBT* btnA;       // 0x1FC
    cUIObj_UBT* btnB;       // 0x200
};

// Release-build assert: expands to an empty do { } while (0). The empty loop still leaves loop notes in the
// RTL, which is what keeps the done-mask copy scheduled where the target has it.
#define ASSERT_UBT(cond) do { } while (0)

static inline int isSet_UBT(unsigned long m, int i)
{
    return (m >> i) & 1;
}

static inline int countSel_UBT(sReqLine_UBT* self)
{
    int n = 0;
    for (int i = 0; i < 64; i++) {
        n += (self->sel >> i) & 1;
    }
    return n;
}

// Updates the action button label of the selected request line and shows or hides the buttons.
extern "C" void cFEStateRequestLine_updateButtonsText(void* p, int idx)
{
    sReqLine_UBT* self = (sReqLine_UBT*)p;
    if (self->text != 0) {
        int shown = 0;
        cUIText_setAsciiString((cUIText*)self->text, D_004A1390);
        self->text->setVisible(0);
        self->back->setVisible(0);
        int on = (self->sel >> idx) & 1;
        if (on) {
            unsigned long rest = self->done;
            ASSERT_UBT(idx < 64);
            rest &= ~((unsigned long)1 << idx);
            int only = rest == 0;
            if (!only) {
                if (isSet_UBT(self->done, idx)) {
                    shown = 1;
                    cUIText_setUnicodeStringByID((cUIText*)self->text, GetHashValue32(D_00460738));
                } else {
                    shown = 1;
                    cUIText_setUnicodeStringByID((cUIText*)self->text, GetHashValue32(D_00460748));
                }
            } else if (!isSet_UBT(self->done, idx)) {
                shown = 1;
                cUIText_setUnicodeStringByID((cUIText*)self->text, GetHashValue32(D_00460748));
            }
        } else if (self->f16C != 0) {
            if (self->count >= func_00198AE8_UBT(self, idx) || countSel_UBT(self) < 6) {
                shown = 1;
                cUIText_setUnicodeStringByID((cUIText*)self->text, GetHashValue32(D_00460758));
            }
        }
        if (shown) {
            self->text->setVisible(1);
            self->back->setVisible(1);
        }
    }
    if (*(int*)(D_004A28A8 + 0x84) != 0 && !isSet_UBT(self->sel, idx)) {
        self->btnA->setVisible(0);
        self->btnB->setVisible(0);
    } else {
        self->btnA->setVisible(1);
        self->btnB->setVisible(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_001985B0);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" const char* func_00198AF0(void* a0);

extern "C" void func_001985B0(void* self)
{
    if (*(cUIText**)((char*)self + 0x1E0) != 0) {
        cUIText_setAsciiString(*(cUIText**)((char*)self + 0x1E0), func_00198AF0(*(void**)((char*)self + 0x168)));
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_001985F0);
#ifdef SKIP_ASM
class cMsgWidget_985F0 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sMsgCenter_985F0 {
    char pad_0x0[0x160];
    ulong mask;     // 0x160
    char pad_0x168[0x4];
    int enabled;    // 0x16C
    char pad_0x170[0x4C];
    cMsgWidget_985F0* icons[6]; // 0x1BC
};

extern "C" void func_001985F0(void* self)
{
    sMsgCenter_985F0* s = (sMsgCenter_985F0*)self;
    int n = 0;
    int i;
    int j;
    for (j = 0; j < 64; j++) {
        n += (int)((s->mask >> j) & 1);
    }
    for (i = 0; i < 6; i++) {
        if (s->icons[i] != 0) {
            if (s->enabled != 0 && n < 6 - i) {
                s->icons[i]->show(1);
            } else {
                s->icons[i]->show(0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", cFEStateRequestLine_updateHilightedSongInfo);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int USTR_length(unsigned short* s);
extern "C" int strlen(const char* s);
void cMemMan_free(void* p);
extern "C" void func_002C26D0(unsigned short* dst, unsigned short* fmt, int n);
extern "C" void func_003A0E90(void* text, void* p);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* func_00198AB8(void* self, int i);
// PORT: func_00198AE8__FPv is called with (self, idx) here; bind the 2-arg form to that symbol.
int func_00198AE8_2(void* self, int idx) __asm__("func_00198AE8__FPv");
extern "C" const char* func_00198AF0(void* a0);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern char D_00460770[];
extern char D_00460780[];
extern char D_00460688[];
extern char D_004A1408[];
extern char* D_004A28A8;

struct sVtEntry_001986D0 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

class cMsgWidget_1986D0 {
public:
    int pad0, pad4;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void show(int on);
};

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sReqLine_1986D0 {
    char pad_0x0[0x160];
    ulong mask;                 // 0x160
    char pad_0x168[0x4];
    int enabled;                // 0x16C
    char pad_0x170[0x64];
    cMsgWidget_1986D0* title;   // 0x1D4
    cUIText* info;              // 0x1D8
    cMsgWidget_1986D0* icon;    // 0x1DC
};

extern "C" void cFEStateRequestLine_updateHilightedSongInfo(void* vself, int idx)
{
    sReqLine_1986D0* self = (sReqLine_1986D0*)vself;
    if (self->title != 0) {
        char* db = *(char**)(D_004A28A8 + 0x8C);
        sVtEntry_001986D0* vt = *(sVtEntry_001986D0**)(db + 4);
        unsigned short* fmt = vt[4].fn(db + vt[4].delta, GetHashValue32(D_00460770));
        char* name = (char*)func_00198AB8(self, idx);
        int len = USTR_length(fmt) + strlen(name) + 1;
        unsigned short* buf = (unsigned short*)operator_new_tag(len * 2, D_00460688, 0x100, 0);
        // PORT: the format argument is a string pointer passed through an int parameter
        func_002C26D0(buf, fmt, (int)name);
        self->title->show(1);
        func_003A0E90(self->title, buf);
        if (buf != 0) {
            cMemMan_free(buf);
        }
    }
    if (self->info == 0) {
        return;
    }
    ulong mask = self->mask;
    if ((int)((mask >> idx) & 1)) {
        cUIText_setAsciiString(self->info, D_004A1408);
        self->icon->show(0);
        return;
    }
    int n = 0;
    for (int j = 0; j < 64; j++) {
        n += (int)((mask >> j) & 1);
    }
    if (n < 6) {
        cUIText_setUnicodeStringByID(self->info, GetHashValue32(D_00460780));
        if (self->enabled) {
            self->icon->show(1);
        }
    } else {
        cUIText_setAsciiString(self->info, func_00198AF0((void*)func_00198AE8_2(self, idx)));
        if (self->enabled) {
            self->icon->show(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_001988D8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00158558(void* iface, int rider, int a, int idx, int full);

// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
struct sMsgCenter_988D8 {
    char pad_0x0[0x44];
    signed char rider; // 0x44
    char pad_0x45[0x3];
    int a48;        // 0x48
    char pad_0x4C[0x10C];
    ulong seen;     // 0x158
    ulong mask;     // 0x160
    int result;     // 0x168
};

extern "C" void func_001988D8(void* self, int idx)
{
    sMsgCenter_988D8* s = (sMsgCenter_988D8*)self;
    int n = 0;
    int j;
    for (j = 0; j < 64; j++) {
        n += (int)((s->mask >> j) & 1);
    }
    int full = n >= 6;
    s->result = func_00158558(cBE_getInterface_Fv(cBE_getBE(), 0xD), s->rider, s->a48, idx, full);
    ulong bit = (ulong)1 << idx;
    s->mask |= bit;
    s->seen |= bit;
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198988);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CABA8(void* self, void* engine, void* owner, signed char idx);
extern "C" void* func_00198A88(void* self, int i);
// PORT: func_00198AE8__FPv is called with (self, idx) here; bind the 2-arg form to that symbol.
int func_00198AE8_2(void* self, int idx) __asm__("func_00198AE8__FPv");
extern "C" void cBuyPopupInfo_initBuySong(int* self, int a1, int a2, int a3);
extern "C" void cBuyPopupInfo_initBuySongByCredit(void* self, int song, int credit);
extern "C" void func_0039F290(void* stack, void* state);
extern char D_00460790[];

// PORT: 64-bit `long` mask (8 bytes on EE, 4 on Windows); use uint64_t off-PS2.
struct sMsgCenter_98988 {
    char pad_0x0[0x10];
    char* engine;       // 0x10
    char pad_0x14[0x30];
    signed char rider;  // 0x44
    char pad_0x45[0x11B];
    ulong mask;         // 0x160
    int price;          // 0x168
};

extern "C" void func_00198988(sMsgCenter_98988* self, int idx)
{
    char* popup = (char*)func_001CABA8(cMemMan_alloc(0x70, D_00460790, 0, 0), self->engine, self, self->rider);
    int n = 0;
    for (int i = 0; i < 64; i++) {
        n += (int)((self->mask >> i) & 1);
    }
    int song = (int)func_00198A88(self, idx);
    if (n >= 6) {
        int cost = func_00198AE8_2(self, idx);
        cBuyPopupInfo_initBuySong((int*)(popup + 0x48), song, cost, self->price);
    } else {
        cBuyPopupInfo_initBuySongByCredit(popup + 0x48, song, 6 - n);
    }
    func_0039F290(self->engine + 0x18, popup);
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198A88);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void* func_002B40F0(void* self, int i);

extern "C" void* func_00198A88(void* self, int i)
{
    return func_002B40F0((char*)func_0028B180() + 0x118, i);
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198AB8);
#ifdef SKIP_ASM
extern "C" void* func_0028B180();
extern "C" void* func_002B4120(void* self, int i);

extern "C" void* func_00198AB8(void* self, int i)
{
    return func_002B4120((char*)func_0028B180() + 0x118, i);
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198AE8__FPv);
#ifdef SKIP_ASM
int func_00198AE8(void* self)
{
    return 0x1388;
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198AF0);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int strlen(const char* s);
extern char D_004C6310[];
extern char D_004A12C0[];

struct sOptions_8AF0 {
    unsigned int pad0 : 22;
    unsigned int moneyFormat : 3;   // 0 = "$ 1,000", 2 = "$ 1.000", 1/3 = "1 000 $"
    unsigned int pad1 : 7;
    int data[0x288 / 4 - 1];
};
extern sOptions_8AF0 D_00535610_8AF0 __asm__("D_00535610");

struct cBEOptionInterface_8AF0 {
    sOptions_8AF0 getOptions() { return D_00535610_8AF0; }
};

// Formats a money amount with the currency sign and thousands separator chosen in the options.
extern "C" const char* func_00198AF0(void* amount_)
{
    // PORT: callers in this unit declare the amount parameter as void*.
    int amount = (int)amount_;
    int prefix = 1;
    char sep = ' ';
    char n;
    switch (((cBEOptionInterface_8AF0*)cBE_getInterface_Fv(cBE_getBE(), 4))->getOptions().moneyFormat) {
    case 0:
        sep = ',';
        break;
    case 1:
        prefix = 0;
        break;
    case 2:
        sep = '.';
        break;
    case 3:
        prefix = 0;
        break;
    }
    n = 0;
    if (prefix) {
        D_004C6310[0] = '$';
        D_004C6310[1] = ' ';
        n = 2;
    }
    if (amount < 0) {
        D_004C6310[n++] = '-';
        amount = -amount;
    }
    char tmp[32];
    sprintf(tmp, D_004A12C0, amount);
    char len = strlen(tmp);
    char i;
    for (i = 0; i != len; i++) {
        D_004C6310[n++] = tmp[i];
        char left = len - i - 1;
        if (left != 0 && left % 3 == 0)
            D_004C6310[n++] = sep;
    }
    if (!prefix) {
        D_004C6310[n++] = ' ';
        D_004C6310[n++] = '$';
    }
    D_004C6310[n] = 0;
    return D_004C6310;
}
#endif

//100%
INCLUDE_ASM("fe/messagecenter", func_00198DA0);
#ifdef SKIP_ASM
extern "C" int func_00198DA0(void* self, void* a1)
{
    void* p = *(void**)self;
    void* p2 = *(void**)a1;
    return *(short*)((char*)p + 0xa) - *(short*)((char*)p2 + 0xa);
}
#endif

