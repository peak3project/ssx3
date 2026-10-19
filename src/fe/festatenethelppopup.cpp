#include "common.h"

//100%
INCLUDE_ASM("fe/festatenethelppopup", cFEStateNetHelpPopup_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004679A0[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void cFEStateNetHelpPopup_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004679A0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001D9E20);
#ifdef SKIP_ASM
struct sVEntry001D9E20 {
    short delta;
    short index;
    int (*fn)(void*, int, int);
};

extern "C" int func_001D9E20(void* self, int a1, int a2)
{
    if (*(int*)((char*)self + 0x50) != 0) {
        void* obj = *(void**)((char*)self + 0x20);
        if (obj != 0) {
            sVEntry001D9E20* vt = *(sVEntry001D9E20**)((char*)obj + 8);
            return vt[24].fn((char*)obj + vt[24].delta, a1, a2);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001D9E68);
#ifdef SKIP_ASM
extern void* D_004A28A8;
extern "C" float func_00320BF0(void* self, int id);
extern "C" void func_0039F190(void*, int);

extern "C" void func_001D9E68(void* self)
{
    int i;
    int found = 0;
    for (i = 0; i < 2; i++) {
        int** p = *(int***)((char*)D_004A28A8 + (i << 2) + 0xB0);
        int ok = *p != 0 && **p != 0;
        if (ok && func_00320BF0(p, 0x99) != 0.0f) {
            found = 1;
        }
    }
    if (found == 0) {
        func_0039F190((char*)*(void**)((char*)self + 0x10) + 0x18, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001D9F30__FPv);
#ifdef SKIP_ASM
int func_001D9F30(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", cFEStateNetHelpPopup_onWidgetCreate);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004679B0[];
extern char D_004A2040[];
extern char D_004679C0[];
extern char D_004A2048[];
extern char D_004679D0[];
extern char D_004679E0[];
extern char D_004679F0[];
extern char D_00467A00[];
extern char D_004A2050[];
extern char D_004A2058[];
extern char D_004A2060[];
extern char D_004A2068[];
extern char D_00467A10[];

struct sWidget_1D9F38 {
    char pad00[0x14];
    unsigned int flags;
    char pad18[0x20];
    int hash;
};

struct sNetHelp_1D9F38 {
    char pad00[0xA8];
    sWidget_1D9F38* wA8;
    sWidget_1D9F38* wAC;
    sWidget_1D9F38* wB0;
    sWidget_1D9F38* rows[7];
    sWidget_1D9F38* wD0;
    sWidget_1D9F38* wD4;
    sWidget_1D9F38* wD8;
    sWidget_1D9F38* wDC;
    sWidget_1D9F38* wE0;
    sWidget_1D9F38* wE4;
    sWidget_1D9F38* wE8;
    sWidget_1D9F38* wEC;
    sWidget_1D9F38* wF0;
};

static inline int IsHash_1D9F38(int id, char* s) { return id == GetHashValue32(s); }

extern "C" void cFEStateNetHelpPopup_onWidgetCreate(sNetHelp_1D9F38* self, sWidget_1D9F38* w)
{
    int h = w->hash;
    if (h == GetHashValue32(D_004679B0)) {
        self->wA8 = w;
        w->flags |= 0x80;
    } else if (h == GetHashValue32(D_004A2040)) {
        self->wAC = w;
        w->flags |= 0x80;
    } else if (h == GetHashValue32(D_004679C0)) {
        self->wB0 = w;
        w->flags |= 0x80;
    } else if (IsHash_1D9F38(w->hash, D_004A2048)) {
        self->wD0 = w;
    } else if (IsHash_1D9F38(w->hash, D_004679D0)) {
        self->wD4 = w;
    } else if (IsHash_1D9F38(w->hash, D_004679E0)) {
        self->wD8 = w;
    } else if (IsHash_1D9F38(w->hash, D_004679F0)) {
        self->wDC = w;
    } else if (IsHash_1D9F38(w->hash, D_00467A00)) {
        self->wE0 = w;
    } else if (IsHash_1D9F38(w->hash, D_004A2050)) {
        self->wE8 = w;
    } else if (IsHash_1D9F38(w->hash, D_004A2058)) {
        self->wE4 = w;
    } else if (IsHash_1D9F38(w->hash, D_004A2060)) {
        self->wF0 = w;
    } else if (IsHash_1D9F38(w->hash, D_004A2068)) {
        self->wEC = w;
    } else {
        char buf[16];
        for (int i = 0; i < 7; i++) {
            sprintf(buf, D_00467A10, i);
            if (h == GetHashValue32(buf)) {
                self->rows[i] = w;
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA110);
#ifdef SKIP_ASM
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void cMemMan_free__FPv(void* p);
extern "C" int USTR_length(unsigned short* s);
extern "C" void func_002C2688(unsigned short* dst, unsigned short* src);
extern "C" void func_003A0D00(void* text, unsigned short* str);
extern char D_00461A70[];

struct sVE_A110 {
    short delta;
    short index;
    unsigned short* (*fn)(void*, int);
};

struct sStrings_A110 {
    int pad0;
    sVE_A110* vt;
};

// Joins up to three localised help strings into one buffer and shows it in the popup text.
extern "C" void func_001DA110(void* p)
{
    char* self = (char*)p;
    unsigned short* strs[3];
    unsigned short* buf = 0;
    int total = 0;
    int count = 0;
    int* ids = (int*)(self + 0x58);
    int i = 0;
    do {
        if (ids[i] == 0) {
            break;
        }
        sStrings_A110* s = *(sStrings_A110**)((char*)D_004A28A8 + 0x8C);
        strs[i] = s->vt[4].fn((char*)s + s->vt[4].delta, ids[i]);
        count++;
        total += USTR_length(strs[i]) + 1;
        i++;
    } while (i < 3);
    if (total > 0) {
        buf = new (D_00461A70, 0x100, 0) unsigned short[total];
        buf[0] = 0;
        for (int i = 0; i < count; i++) {
            func_002C2688(buf, strs[i]);
        }
    }
    func_003A0D00(*(void**)(self + 0xAC), buf);
    if (buf != 0) {
        cMemMan_free__FPv(buf);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatenethelppopup", func_001DA238);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* text, const char* str);
void cUIText_setUnicodeStringByID(cUIText* text, int id);
extern "C" void func_001DA110(void* self);
extern char D_004A1408[];

struct sVEnt_1DA238 { short delta; short index; void (*fn)(void*, int); };
struct sVec3_1DA238 { float x, y, z; };

struct sWidget_1DA238 {
    char pad00[8];
    sVEnt_1DA238* vt;
    char pad0C[0x38];
    sVec3_1DA238 pos;
};

struct sNetHelp_1DA238 {
    char pad00[0x48];
    int state;                  // 0x48
    char pad4C[8];
    int title;                  // 0x54
    int c[3];                   // 0x58
    int f64;                    // 0x64
    int a[7];                   // 0x68
    int b[7];                   // 0x84
    char padA0[8];
    sWidget_1DA238* wA8;        // 0xA8
    sWidget_1DA238* wAC;        // 0xAC
    sWidget_1DA238* wB0;        // 0xB0
    sWidget_1DA238* rows[7];    // 0xB4
    sWidget_1DA238* icons[9];   // 0xD0
};

static inline void show_1DA238(sWidget_1DA238* w, int on)
{
    w->vt[9].fn((char*)w + w->vt[9].delta, on);
}

extern "C" int func_001DA238(sNetHelp_1DA238* self, int a1)
{
    if (a1) {
        if (self->title) {
            cUIText_setUnicodeStringByID((cUIText*)self->wA8, self->title);
        } else {
            cUIText_setAsciiString((cUIText*)self->wA8, D_004A1408);
        }
        if (self->c[0]) {
            func_001DA110(self);
        } else {
            cUIText_setAsciiString((cUIText*)self->wAC, D_004A1408);
        }
        if (self->f64) {
            cUIText_setUnicodeStringByID((cUIText*)self->wB0, self->f64);
        } else {
            cUIText_setAsciiString((cUIText*)self->wB0, D_004A1408);
        }
        for (int j = 0; j < 9; j++) {
            show_1DA238(self->icons[j], 0);
        }
        for (int i = 0; i < 7; i++) {
            if (i < self->state) {
                show_1DA238(self->rows[i], 1);
                show_1DA238(self->icons[self->b[i]], 1);
                sVec3_1DA238 p = self->icons[self->b[i]]->pos;
                p.y += (float)i * 22.0f;
                self->icons[self->b[i]]->pos = p;
                if (self->a[i]) {
                    cUIText_setUnicodeStringByID((cUIText*)self->rows[i], self->a[i]);
                } else {
                    cUIText_setAsciiString((cUIText*)self->rows[i], D_004A1408);
                }
            } else {
                show_1DA238(self->rows[i], 0);
            }
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA478);
#ifdef SKIP_ASM
extern "C" void func_0039F190(void*, int);

extern "C" void func_001DA478(void* self, int a1, int msg)
{
    if (msg == 6) {
        func_0039F190((char*)*(void**)((char*)self + 0x10) + 0x18, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA4A8);
#ifdef SKIP_ASM
struct sNetHelpPopup_DA4A8 {
    char pad_0x0[0x48];
    int state;      // 0x48
    char pad_0x4C[0x8];
    int f54;        // 0x54
    int c[3];       // 0x58
    int f64;        // 0x64
    int a[7];       // 0x68
    int b[7];       // 0x84
};

extern "C" void func_001DA4A8(void* self)
{
    sNetHelpPopup_DA4A8* s = (sNetHelpPopup_DA4A8*)self;
    int i;
    s->state = 0;
    s->f54 = 0;
    for (i = 2; i >= 0; i--) {
        s->c[i] = 0;
    }
    s->f64 = 0;
    for (i = 0; i < 7; i++) {
        s->a[i] = 0;
        s->b[i] = -1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA510__FPviii);
#ifdef SKIP_ASM
struct sNetHelpPopup_DA510 {
    char pad[0x68];
    int a[7];
    int b[7];
};

void func_001DA510(void* self, int i, int a, int b)
{
    sNetHelpPopup_DA510* s = (sNetHelpPopup_DA510*)self;
    s->a[i] = a;
    s->b[i] = b;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA528__FPvi);
#ifdef SKIP_ASM
void func_001DA528(void* self, int val)
{
    *(int*)((char*)self + 0x48) = val;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA530__FPvii);
#ifdef SKIP_ASM
void func_001DA530(void* self, int i, int value)
{
    *(int*)((char*)self + (i << 2) + 0x58) = value;
}
#endif

INCLUDE_ASM("fe/festatenethelppopup", func_001DA540);

INCLUDE_ASM("fe/festatenethelppopup", func_001DA580);

INCLUDE_ASM("fe/festatenethelppopup", func_001DA5E8);

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA648);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CE418(void* self, void* a1, const char* name);
extern "C" void* func_002CCF98(void* self, int a1, void* a2, int a3);
extern "C" void* func_002CCDF0(void* self, void* text);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern "C" char* func_00416958(char* dst, const char* src, int n);
extern void* D_004A28A8;
extern void* D_0046D690[];
extern char D_00467A20[];
extern char D_00467A30[];
extern char D_00467A40[];
extern char D_00467A50[];
extern char D_004A1408[];

static inline void copyName_1DA648(char* dst, const char* src)
{
    dst[0] = 0;
    func_00416958(dst, src, 0xF);
}

extern "C" void* func_001DA648(void* self, void* vinfo, void* a2)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D690;
    *(int*)((char*)self + 0x130) = *(int*)vinfo;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467A20);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xA);
    func_002CE418((char*)self + 0x168, D_00467A30, D_004A1408);
    func_002CE418((char*)self + 0x194, D_00467A40, D_004A1408);
    func_002CCF98((char*)self + 0x1C0, 0, a2, 0);
    func_002CCDF0((char*)self + 0x1E4, D_00467A50);
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    cMenu_addItem(self, (char*)self + 0x168, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C0, -1);
    cMenu_addItem(self, (char*)self + 0x1E4, -1);
    copyName_1DA648((char*)self + 0x180, *(char**)((char*)D_004A28A8 + 0xC4));
    copyName_1DA648((char*)self + 0x1AC, *(char**)((char*)D_004A28A8 + 0xC8));
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DA7E8);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CE418(void* self, void* a1, const char* name);
extern "C" void* func_002CCF98(void* self, int a1, void* a2, int a3);
extern "C" void* func_002CCDF0(void* self, void* text);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern "C" char* func_00416958(char* dst, const char* src, int n);
extern void* D_004A28A8;
extern void* D_0046D6E8[];
extern char D_00467A20[];
extern char D_00467A30[];
extern char D_00467A40[];
extern char D_00467A50[];
extern char D_004A1408[];

static inline void copyName_1DA7E8(char* dst, const char* src)
{
    dst[0] = 0;
    func_00416958(dst, src, 0xF);
}

extern "C" void* func_001DA7E8(void* self, void* vinfo, void* a2)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D6E8;
    *(int*)((char*)self + 0x130) = *(int*)vinfo;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467A20);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xA);
    func_002CE418((char*)self + 0x168, D_00467A30, D_004A1408);
    func_002CE418((char*)self + 0x194, D_00467A40, D_004A1408);
    func_002CCF98((char*)self + 0x1C0, 0, a2, 0);
    func_002CCDF0((char*)self + 0x1E4, D_00467A50);
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    cMenu_addItem(self, (char*)self + 0x168, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    cMenu_addItem(self, (char*)self + 0x1C0, -1);
    cMenu_addItem(self, (char*)self + 0x1E4, -1);
    copyName_1DA7E8((char*)self + 0x180, *(char**)((char*)D_004A28A8 + 0xC4));
    copyName_1DA7E8((char*)self + 0x1AC, *(char**)((char*)D_004A28A8 + 0xC8));
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/festatenethelppopup", func_001DA988);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
extern "C" void* func_001DA648(void* self, void* a1, void* a2);
extern "C" void* func_001DA7E8(void* self, void* a1, void* a2);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D638[];
extern char D_00467A20[];
extern char D_00467A58[];
extern char D_00467A60[];

extern "C" void* func_001DA988(void* self, void* a1, void* a2)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D638;
    func_001DA648((char*)self + 0x130, a1, D_00467A20);
    func_001DA7E8((char*)self + 0x32C, a2, D_00467A58);
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x528), D_00467A60);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x544), (void*)0xA);
    cSubMenuItem_cSubMenuItem((char*)self + 0x55C, (char*)self + 0x130, D_00467A20);
    cSubMenuItem_cSubMenuItem((char*)self + 0x578, (char*)self + 0x32C, D_00467A58);
    cMenu_addItem(self, (char*)self + 0x528, -1);
    cMenu_addItem(self, (char*)self + 0x544, -1);
    cMenu_addItem(self, (char*)self + 0x55C, -1);
    cMenu_addItem(self, (char*)self + 0x578, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DAAC8);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CE418(void* self, void* a1, const char* name);
extern "C" void* func_002CCF98(void* self, int a1, void* a2, int a3);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D588[];
extern char D_00467A70[];
extern char D_00467A80[];
extern char D_004A1408[];
extern char D_00467A90[];

extern "C" void* func_001DAAC8(void* self, int* info)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D588;
    *(int*)((char*)self + 0x130) = *info;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467A70);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xE);
    func_002CE418((char*)self + 0x168, D_00467A80, D_004A1408);
    func_002CCF98((char*)self + 0x194, 0, D_00467A90, 0);
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    cMenu_addItem(self, (char*)self + 0x168, -1);
    cMenu_addItem(self, (char*)self + 0x194, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DABD0);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CCF08(void* self);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D5E0[];
extern char D_00467A98[];

extern "C" void* func_001DABD0(void* self, int* info)
{
    char* p = (char*)self + 0x168;
    int i = 3;
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D5E0;
    *(int*)((char*)self + 0x130) = *info;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467A98);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xE);
    for (; i != -1; i--) {
        func_002CCF08(p);
        p += 0x24;
    }
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    int j;
    for (j = 0; j < 4; j++) {
        cMenu_addItem(self, (char*)self + 0x168 + j * 0x24, -1);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DACB8);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* cSubMenuItem_cSubMenuItem(void* self, void* a1, void* a2);
// PORT: the member ctors return self, but this caller treats them as void
void func_001DAAC8_v(void* self, int* info) __asm__("func_001DAAC8");
void func_001DABD0_v(void* self, int* info) __asm__("func_001DABD0");
extern "C" void* func_002CCF08(void* self);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D530[];
extern char D_00467AA8[];
extern char D_00467A70[];
extern char D_00467A98[];


extern "C" void* func_001DACB8(void* self, int* info, int* a2, int* a3)
{
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D530;
    func_001DAAC8_v((char*)self + 0x130, a2);
    func_001DABD0_v((char*)self + 0x2E8, a3);
    *(int*)((char*)self + 0x4E0) = *info;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x4E4), D_00467AA8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x500), (void*)0xE);
    char* p = (char*)self + 0x518;
    for (int i = 3; i != -1; i--) {
        func_002CCF08(p);
        p += 0x24;
    }
    cSubMenuItem_cSubMenuItem((char*)self + 0x5A8, (char*)self + 0x130, D_00467A70);
    cSubMenuItem_cSubMenuItem((char*)self + 0x5C4, (char*)self + 0x2E8, D_00467A98);
    cMenu_addItem(self, (char*)self + 0x4E4, -1);
    cMenu_addItem(self, (char*)self + 0x500, -1);
    int j;
    for (j = 0; j < 4; j++) {
        cMenu_addItem(self, (char*)self + 0x518 + j * 0x24, -1);
    }
    cMenu_addItem(self, (char*)self + 0x5A8, -1);
    cMenu_addItem(self, (char*)self + 0x5C4, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DAE20);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CCF08(void* self);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D4D8[];
extern char D_00467AB8[];

extern "C" void* func_001DAE20(void* self, int* info)
{
    char* p = (char*)self + 0x168;
    int i = 11;
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D4D8;
    *(int*)((char*)self + 0x130) = *info;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467AB8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xE);
    for (; i != -1; i--) {
        func_002CCF08(p);
        p += 0x24;
    }
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    int j;
    for (j = 0; j < 12; j++) {
        cMenu_addItem(self, (char*)self + 0x168 + j * 0x24, -1);
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DAF08);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CCF08(void* self);
extern "C" void* func_002CCF98(void* self, int a1, void* a2, int a3);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D480[];
extern char D_00467AC8[];
extern char D_00467AD8[];

extern "C" void* func_001DAF08(void* self, int* a, int* b)
{
    char* p = (char*)self + 0x16C;
    int i = 0x17;
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D480;
    *(int*)((char*)self + 0x130) = *a;
    *(int*)((char*)self + 0x134) = *b;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x138), D_00467AC8);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x154), (void*)0xE);
    for (; i != -1; i--) {
        func_002CCF08(p);
        p += 0x24;
    }
    func_002CCF98((char*)self + 0x4CC, -2, D_00467AD8, 0);
    cMenu_addItem(self, (char*)self + 0x138, -1);
    cMenu_addItem(self, (char*)self + 0x154, -1);
    int j;
    for (j = 0; j < 0x18; j++) {
        cMenu_addItem(self, (char*)self + 0x16C + j * 0x24, -1);
    }
    cMenu_addItem(self, (char*)self + 0x4CC, -1);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/festatenethelppopup", func_001DB028);
#ifdef SKIP_ASM
struct cNullMenuItem;
struct cSpaceMenuItem;
void* func_002CAA58(void* self);
cNullMenuItem* cNullMenuItem_cNullMenuItem(cNullMenuItem* self, void* text);
cSpaceMenuItem* cSpaceMenuItem_cSpaceMenuItem(cSpaceMenuItem* self, void* text);
extern "C" void* func_002CCF08(void* self);
extern "C" void* func_002CE418(void* self, void* a1, const char* name);
extern "C" void cMenu_addItem(void* menu, void* item, int index);
extern void* D_0046D428[];
extern char D_00467AE0[];
extern char D_00467AF0[];
extern char D_004A1408[];
extern int D_00467D70[];

extern "C" void* func_001DB028(void* self, int* info)
{
    char* p = (char*)self + 0x194;
    int i = 0xD;
    func_002CAA58(self);
    *(void***)((char*)self + 0x12C) = D_0046D428;
    *(int*)((char*)self + 0x130) = *info;
    cNullMenuItem_cNullMenuItem((cNullMenuItem*)((char*)self + 0x134), D_00467AE0);
    cSpaceMenuItem_cSpaceMenuItem((cSpaceMenuItem*)((char*)self + 0x150), (void*)0xE);
    func_002CE418((char*)self + 0x168, D_00467AF0, D_004A1408);
    for (; i != -1; i--) {
        func_002CCF08(p);
        p += 0x24;
    }
    cMenu_addItem(self, (char*)self + 0x134, -1);
    cMenu_addItem(self, (char*)self + 0x150, -1);
    int j;
    for (j = 0; j < 0xE; j++) {
        char* item = (char*)self + 0x194 + j * 0x24;
        *(int*)(item + 0x8) = j;
        *(int*)(item + 0x14) = D_00467D70[j];
        cMenu_addItem(self, item, -1);
    }
    return self;
}
#endif

