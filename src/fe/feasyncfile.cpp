#include "common.h"

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_Load3PeakPic);
#ifdef SKIP_ASM
struct cFEAsyncManager;
void cFEAsyncManager_SetFileStatus(cFEAsyncManager* self, int index, int status);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char* D_004A19F0;
extern char D_004A19F8[];
extern char D_004A1A00[];

struct sFE3PeakPicEntry {
    char mName[0x108];
    int mParam; // 0x108
    char pad[0x11C - 0x10C];
};

struct sFE3PeakPicFiles {
    sFE3PeakPicEntry mFiles[1];
};

extern "C" void cFEAsyncManager_Load3PeakPic(cFEAsyncManager* self, int slot, int param)
{
    sFE3PeakPicFiles* files = (sFE3PeakPicFiles*)self;
    sprintf(files->mFiles[slot].mName, D_004A19F8, D_004A19F0, D_004A1A00);
    files->mFiles[slot].mParam = param;
    cFEAsyncManager_SetFileStatus(self, slot, 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_Load1PeakPic);
#ifdef SKIP_ASM
struct cFEAsyncManager;
void cFEAsyncManager_SetFileStatus(cFEAsyncManager* self, int index, int status);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char* D_00441258[];
extern char D_004A19F8[];
extern char D_004A1A00[];

struct sFEPeakPicEntry {
    char mName[0x108];
    int mParam; // 0x108
    char pad[0x11C - 0x10C];
};

struct sFEPeakPicFiles {
    sFEPeakPicEntry mFiles[1];
};

extern "C" void cFEAsyncManager_Load1PeakPic(cFEAsyncManager* self, int pic, int slot, int param)
{
    sFEPeakPicFiles* files = (sFEPeakPicFiles*)self;
    sprintf(files->mFiles[slot].mName, D_004A19F8, D_00441258[pic], D_004A1A00);
    files->mFiles[slot].mParam = param;
    cFEAsyncManager_SetFileStatus(self, slot, 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A37F8);
#ifdef SKIP_ASM
extern char D_004A1A08[];
extern char D_004A1A10[];
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_00154760(void* self, int id);

extern "C" void func_001A37F8(cFEAsyncManager* self, int id, int slot, int param)
{
    if (id >= 0) {
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 10);
        sFEPeakPicFiles* files = (sFEPeakPicFiles*)self;
        sprintf(files->mFiles[slot].mName, D_004A1A08, D_004A1A10, func_00154760(iface, id), D_004A1A00);
        files->mFiles[slot].mParam = param;
        cFEAsyncManager_SetFileStatus(self, slot, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_UnloadFEAsyncFile);
#ifdef SKIP_ASM
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);
void cFEAsyncManager_SetFileStatus(cFEAsyncManager* self, int index, int status);
void cMemMan_free(void* p);
extern "C" int ASYNCFILE_release(int handle, void** data, int* size);
extern char* D_004A289C;

struct sFEUnloadFile {
    char name[0x100];
    void* data;    // 0x100
    int handle;    // 0x104
    int async;     // 0x108
    int size;      // 0x10C
    int id;        // 0x110
    int status;    // 0x114
    int f118;      // 0x118
};

struct sFEUnloadFiles {
    sFEUnloadFile files[5];
};

struct sVEUnload {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void cFEAsyncManager_UnloadFEAsyncFile(cFEAsyncManager* self, int idx)
{
    sFEUnloadFiles* m = (sFEUnloadFiles*)self;
    if (cFEAsyncManager_GetFileStatus(self, idx) == 1) {
        cFEAsyncManager_SetFileStatus(self, idx, 0);
    } else if (cFEAsyncManager_GetFileStatus(self, idx) == 2) {
        ASYNCFILE_release(m->files[idx].handle, 0, 0);
        if (m->files[idx].data != 0) {
            cMemMan_free(m->files[idx].data);
        }
        m->files[idx].data = 0;
        cFEAsyncManager_SetFileStatus(self, idx, 0);
    } else if (cFEAsyncManager_GetFileStatus(self, idx) == 3) {
        char* obj = D_004A289C;
        sVEUnload* vt = *(sVEUnload**)(obj + 0x10D8);
        m->files[idx].f118 = vt[114].fn(obj + vt[114].delta) + 0xE;
        cFEAsyncManager_SetFileStatus(self, idx, 0);
    }
}
#endif

struct cFEAsyncFileEntry {
    char pad_0x00[0x114];
    int mStatus; // 0x114
    char pad_0x118[0x11C - 0x114 - 4];
};

struct cFEAsyncManager {
    cFEAsyncFileEntry mFiles[1];
};

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_GetFileStatus__FP15cFEAsyncManageri);
#ifdef SKIP_ASM
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index)
{
    return self->mFiles[index].mStatus;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_SetFileStatus__FP15cFEAsyncManagerii);
#ifdef SKIP_ASM
void cFEAsyncManager_SetFileStatus(cFEAsyncManager* self, int index, int status)
{
    self->mFiles[index].mStatus = status;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A39F0);
#ifdef SKIP_ASM
struct sFE39F0File {
    char name[0x100];
    char* data;    // 0x100
    int handle;    // 0x104
    int async;     // 0x108
    int size;      // 0x10C
    int id;        // 0x110
    int status;    // 0x114
    int f118;      // 0x118
};

struct sFE39F0Files {
    sFE39F0File files[5];
};

struct sVE39F0 {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sVE39F0L {
    short delta;
    short index;
    int (*fn)(void*, char*, const char*, int, int, int);
};

struct sVE39F0V {
    short delta;
    short index;
    void (*fn)(void*, int);
};

int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);
void cFEAsyncManager_SetFileStatus(cFEAsyncManager* self, int index, int status);
extern "C" void cFEAsyncManager_LoadDataFile(cFEAsyncManager* self, int idx);
extern "C" int ASYNCFILE_release(int handle, void** data, int* size);
extern "C" int func_003DF980(int handle);
void cMemMan_free(void* p);
extern char* D_004A289C;
extern char D_004A1A18[];

extern "C" void func_001A39F0(cFEAsyncManager* self)
{
    sFE39F0Files* m = (sFE39F0Files*)self;
    int i;
    for (i = 0; i < 5; i++) {
        if (cFEAsyncManager_GetFileStatus(self, i) == 0 || cFEAsyncManager_GetFileStatus(self, i) == 1) {
            char* obj = D_004A289C;
            sVE39F0* vt = *(sVE39F0**)(obj + 0x10D8);
            if (m->files[i].f118 < vt[114].fn(obj + vt[114].delta)) {
                if (m->files[i].data != 0) {
                    char* obj2 = D_004A289C;
                    sVE39F0V* vt2 = *(sVE39F0V**)(obj2 + 0x10D8);
                    vt2[50].fn(obj2 + vt2[50].delta, m->files[i].id);
                    if (m->files[i].data != 0) {
                        cMemMan_free(m->files[i].data);
                    }
                    m->files[i].data = 0;
                    m->files[i].f118 = 0;
                    m->files[i].id = -1;
                }
            }
        }
        if (cFEAsyncManager_GetFileStatus(self, i) == 1) {
            char* obj = D_004A289C;
            sVE39F0* vt = *(sVE39F0**)(obj + 0x10D8);
            if (m->files[i].f118 < vt[114].fn(obj + vt[114].delta)) {
                cFEAsyncManager_LoadDataFile(self, i);
            }
        }
        if (cFEAsyncManager_GetFileStatus(self, i) == 2) {
            if (func_003DF980(m->files[i].handle) == 1) {
                cFEAsyncManager_SetFileStatus(self, i, 3);
                ASYNCFILE_release(m->files[i].handle, 0, 0);
                char* obj = D_004A289C;
                sVE39F0L* vt = *(sVE39F0L**)(obj + 0x10D8);
                char* data = m->files[i].data;
                m->files[i].id = vt[46].fn(obj + vt[46].delta, data + *(int*)(data + 0x14), D_004A1A18, 0, 0, -1);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A3BF0);
#ifdef SKIP_ASM
int cFEAsyncManager_GetFileStatus(cFEAsyncManager* self, int index);

extern "C" int func_001A3BF0(cFEAsyncManager* self)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (cFEAsyncManager_GetFileStatus(self, i) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A3C50);
#ifdef SKIP_ASM
struct sFE3C50File {
    char name[0x100];
    void* data;    // 0x100
    int handle;    // 0x104
    int async;     // 0x108
    int size;      // 0x10C
    int id;        // 0x110
    int status;    // 0x114
    int f118;      // 0x118
};

struct sFE3C50Files {
    sFE3C50File files[5];
};

struct sVE3C50 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern char* D_004A289C;
void cMemMan_free(void* p);

extern "C" void func_001A3C50(cFEAsyncManager* self)
{
    sFE3C50Files* m = (sFE3C50Files*)self;
    int i;
    for (i = 0; i < 5; i++) {
        if (m->files[i].data != 0) {
            char* obj = D_004A289C;
            sVE3C50* vt = *(sVE3C50**)(obj + 0x10D8);
            vt[50].fn(obj + vt[50].delta, m->files[i].id);
            if (m->files[i].data != 0) {
                cMemMan_free(m->files[i].data);
            }
            m->files[i].data = 0;
            m->files[i].f118 = 0;
            m->files[i].id = -1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", cFEAsyncManager_LoadDataFile);
#ifdef SKIP_ASM
struct sFEAsyncFile {
    char name[0x100];
    void* data;    // 0x100
    int handle;    // 0x104
    int async;     // 0x108
    int size;      // 0x10C
    int pad110;
    int status;    // 0x114
    int pad118;
};

struct sFEAsyncFiles {
    sFEAsyncFile files[5];
};

extern char D_00461430[];
// PORT: operator_new__FUi really takes (size, tag, flags, d)
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int func_003DF748(void* file, void* data, int size);
extern "C" void func_003E1BB8(void* file, void* data, int size);

extern "C" void cFEAsyncManager_LoadDataFile(cFEAsyncManager* self, int idx)
{
    sFEAsyncFiles* m = (sFEAsyncFiles*)self;
    void** pData;
    char* base;
    m->files[idx].size = 0x109A0;
    base = (char*)self + 0x100;
    pData = (void**)(base + idx * 0x11C);
    *pData = operator_new_tag(0x109A0, D_00461430, 0x25000000, 0);
    cFEAsyncManager_SetFileStatus(self, idx, 2);
    if (m->files[idx].async != 0) {
        cFEAsyncManager_SetFileStatus(self, idx, 2);
        m->files[idx].handle = func_003DF748(&m->files[idx], *pData, m->files[idx].size);
    } else {
        func_003E1BB8(&m->files[idx], *pData, m->files[idx].size);
        cFEAsyncManager_SetFileStatus(self, idx, 3);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A3DC8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A3E30);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001A3E30()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 10, 0, 0, 0);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A3EA0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A3F68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001A5898(void* self);
extern "C" void func_001A6978(void* self);
extern char D_00461448[];

extern "C" void func_001A3F68(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00461448), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        func_001A5898(self);
        func_001A6978(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A3FE0);
#ifdef SKIP_ASM
extern void* D_004A5B64;
extern "C" void func_001A6978(void* self);
extern "C" void* func_001A8770(void* self);

extern "C" void func_001A3FE0(void* self)
{
    int now = *(int*)((char*)D_004A5B64 + 0x18);
    int d = now - *(int*)((char*)self + 0x6DC);
    if (d >= 1 && d <= 59) {
        func_001A8770(self);
    } else {
        *(int*)((char*)self + 0x6DC) = now;
        func_001A6978(self);
        func_001A8770(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4040);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00461458[];
extern char D_00461470[];
extern char D_00461488[];
extern char D_004614A0[];
extern char D_0045FE60[];
extern char D_004614B8[];
extern char D_004614D0[];
extern char D_004614E8[];
extern char D_00461500[];

extern "C" void func_001A4040(void* self, void* menu)
{
    func_001DA528(menu, 5);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00461458);
    func_001DA530(menu, 0, GetHashValue32(D_00461470));
    func_001DA530(menu, 1, GetHashValue32(D_00461488));
    func_001DA530(menu, 2, GetHashValue32(D_004614A0));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_004614B8), 0);
    func_001DA510(menu, 2, GetHashValue32(D_004614D0), 2);
    func_001DA510(menu, 3, GetHashValue32(D_004614E8), 1);
    func_001DA510(menu, 4, GetHashValue32(D_00461500), 6);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4170);
#ifdef SKIP_ASM
struct sVE1A4170 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_001A6C40(void* self, int a1);

extern "C" int func_001A4170(void* self, void* obj)
{
    int r;
    sVE1A4170* vt = *(sVE1A4170**)((char*)obj + 0x8);
    if (vt[27].fn((char*)obj + vt[27].delta) == 0) {
        r = 0;
    } else {
        func_001A6C40(self, *(int*)((char*)self + 0x6F8));
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A41C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00461458[];
extern char D_00461520[];
extern char D_00461530[];
extern char D_00461540[];
extern char D_00461558[];
extern char D_00461570[];
extern char D_00461580[];
extern char D_00461590[];

class cFEVObj_001A41C0 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline int IsHash1A41C0(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001A41C0(void* self, cUIText* text)
{
    cFEVObj_001A41C0* obj = (cFEVObj_001A41C0*)text;
    if (IsHash1A41C0(*(int*)((char*)text + 0x38), D_00461520)) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00461458));
        obj->v09(1);
    } else if (IsHash1A41C0(*(int*)((char*)text + 0x38), D_00461530)) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00461540));
        obj->v09(1);
    } else if (IsHash1A41C0(*(int*)((char*)text + 0x38), D_00461558)) {
        obj->v09(1);
        *(int*)((char*)text + 0x14) |= 0x80;
    } else if (IsHash1A41C0(*(int*)((char*)text + 0x38), D_00461570)) {
        obj->v09(0);
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00461580));
    } else if (IsHash1A41C0(*(int*)((char*)text + 0x38), D_00461590)) {
        *(int*)((char*)text + 0x14) |= 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4300);
#ifdef SKIP_ASM
extern "C" void func_001A6978(void* self);

extern "C" int func_001A4300(void* self, int a1, int a2, int a3)
{
    if (a2 == 4) {
        *(int*)((char*)self + 0x6F4) = a3;
        func_001A6978(self);
        return 0;
    }
    return 0x101;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A4330);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4670);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_00262400(void* self, int a1);
extern "C" int func_00263338(void* self, int a1);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001A4670()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" int func_001A4670(void* self, int idx)
{
    if (func_00262400(GetSession_001A4670(), idx) != 0) {
        return 0;
    }
    if (func_00263338(GetSession_001A4670(), idx) != 0) {
        return 2;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4740);
#ifdef SKIP_ASM
extern "C" int func_001A4740(void* self, int a1)
{
    return *(int*)((char*)self + 0x6f4) + a1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4750);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_001A4810(void* self, void* a1);
extern "C" void func_00262690(void* self, int a1, void* a2);
int func_001A98B0(void* self);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001A4750()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001A4750(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    switch (*(int*)(p + 0x18)) {
    case 1:
        func_001A4810(self, p + 0x74);
        break;
    case 2:
        func_00262690(GetSession_001A4750(), func_001A98B0(self), *(char**)((char*)self + 0x69C) + 0x74);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4810);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025E6D0(void* self, const char* str);
extern void* D_004A3028;
extern char D_004615F8[];
extern char D_00461618[];
extern char D_00461628[];

extern "C" void func_001A4810(void* self, void* a1)
{
    const char* name = (const char*)a1;
    if (strlen(name) < 3) {
        void* p = func_001A9C50(self);
        int three = 3;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004615F8);
        *(int*)((char*)p + 0xC0) = three;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x14C) = three;
        *(int*)((char*)p + 0x150) = 0x806;
        func_001A9BC0(self, p);
    } else {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00461628);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x807;
        *(int*)((char*)p + 0x14C) = 3;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        cBXString_cBXString4((char*)self + 0x6D4, name);
        func_0025E6D0(D_004A3028, name);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4928);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" int func_0041AA88(const char* a, const char* b);
extern "C" void func_001A9890(void* self, const char* str);
int func_001A98B0(void* self);
extern "C" void func_001AB370(void* self, int a1, int a2);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001A4928(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        if (func_0041AA88(*(const char**)((char*)D_004A3028 + 0x80), *(const char**)((char*)self + 0x6D0)) != 0) {
            func_001A9890(self, *(const char**)((char*)self + 0x6D0));
            func_001AB370(self, func_001A98B0(self), 0);
        }
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A49A0);
#ifdef SKIP_ASM
extern "C" void func_001A5898(void* self);
extern "C" void func_001A6978(void* self);
extern "C" void func_001ABB30(void* self, int a1, void* a2, int a3);
// PORT: the unit types the last parameter `int`; it is an out pointer passed through.
extern "C" void func_001A4B20_ABC50(void* self, int a1, int* out) __asm__("func_001ABC50");
extern "C" void func_001A4B20_ABE58(void* self, int a1, int* out) __asm__("func_001ABE58");
extern "C" void func_001ABED8(void* self);
extern "C" void func_001ABCD0(void* self, int a1, void* a2, int a3, int a4);

extern "C" void func_001A49A0(void* self, void* a1, unsigned int kind)
{
    int r17;
    int r18;
    switch (kind) {
    case 15:
        func_001ABCD0(self, func_001A98B0(self), a1, 15, 1);
        break;
    case 16:
        func_001A97B8(self, a1, 16);
        func_001ABB30(self, func_001A98B0(self), a1, 16);
        break;
    case 17:
        func_001A4B20_ABE58(self, func_001A98B0(self), &r17);
        if (r17 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, 17);
        }
        func_001A5898(self);
        func_001A6978(self);
        break;
    case 18:
        func_001A4B20_ABC50(self, func_001A98B0(self), &r18);
        if (r18 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, 18);
        }
        func_001A5898(self);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4B20);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
int func_001A98B0(void* self);
extern "C" void func_001A5898(void* self);
extern "C" void func_001A6978(void* self);
extern "C" void func_001ABB30(void* self, int a1, void* a2, int a3);
// PORT: the unit types the last parameter `int`; it is an out pointer passed through.
extern "C" void func_001A4B20_ABC50(void* self, int a1, int* out) __asm__("func_001ABC50");
extern "C" void func_001A4B20_ABE58(void* self, int a1, int* out) __asm__("func_001ABE58");
extern "C" void func_001ABED8(void* self);

extern "C" void func_001A4B20(void* self, void* a1, unsigned int kind)
{
    int r16;
    int r17;
    switch (kind) {
    case 15:
        func_001A97B8(self, a1, 15);
        func_001ABB30(self, func_001A98B0(self), a1, 15);
        break;
    case 16:
        func_001A4B20_ABE58(self, func_001A98B0(self), &r16);
        if (r16 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, 16);
        }
        func_001A5898(self);
        func_001A6978(self);
        break;
    case 17:
        func_001A4B20_ABC50(self, func_001A98B0(self), &r17);
        if (r17 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, 17);
        }
        func_001A5898(self);
        func_001A6978(self);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4C58);
#ifdef SKIP_ASM
class cFEVObj_001A4C58 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v33(void* a1, int a2);
    virtual void v34(void* a1, int a2);
    virtual void v35(void* a1, int a2);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001A4C58(cFEVObj_001A4C58* self, void* a1, int a2)
{
    switch (*(unsigned int*)((char*)a1 + 0x18)) {
    case 0x809:
        self->v33(a1, a2);
        break;
    case 0x80B:
        self->v34(a1, a2);
        break;
    case 0x80C:
        self->v35(a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4CE8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBXString_operatorE(void* self, void* other);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C5780(void* self, int a1, int a2);
extern char D_00461648[];

extern "C" void func_001A4CE8(void* self, void* src)
{
    cBXString_operatorE((char*)self + 0x6D0, (char*)src + 0x8);
    *(int*)((char*)self + 0x6D8) = *(int*)((char*)src + 0x10);
    void* p = func_001A9C50(self);
    int three = 3;
    char* sub = (char*)p + 0xBC;
    *(int*)((char*)p + 0xBC) = 1;
    *(int*)((char*)p + 0xCC) = GetHashValue32(D_00461648);
    *(int*)((char*)p + 0xC8) = three;
    func_001C5780(sub, 0, *(int*)((char*)self + 0x6D0));
    *(int*)((char*)p + 0x14C) = three;
    *(int*)((char*)p + 0x150) = 0x809;
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4D90);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern char D_00461660[];
extern char D_00461618[];

extern "C" void func_001A4D90(void* self)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 1;
    *(int*)((char*)p + 0xCC) = GetHashValue32(D_00461660);
    *(int*)((char*)p + 0xC8) = 3;
    func_001C57C0((char*)p + 0xBC, 0, GetHashValue32(D_00461618));
    *(int*)((char*)p + 0x14C) = 3;
    *(int*)((char*)p + 0x150) = 0x808;
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A4E28);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_002C26D0(void* str, int a1, char* buf);
// PORT: unit declares func_001A8E40 with one arg; the real handler takes (self, id, msg)
extern "C" void* func_001A8E40_msg(void* self, int id, void* msg) __asm__("func_001A8E40");
extern void* D_004A28A8;
extern char D_004615F8[];
extern char D_00461618[];
extern char D_00461678[];
extern char D_00461690[];

struct sVEntry_001A4E28 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

extern "C" void func_001A4E28(void* self, void* msg)
{
    switch (*(int*)((char*)msg + 8)) {
    case 0x69706572: {
        char* buf = (char*)self + 0x9C;
        int one = 1;
        int three = 3;
        char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
        sVEntry_001A4E28* vt = *(sVEntry_001A4E28**)(obj + 4);
        func_002C26D0(buf, vt[4].fn(obj + vt[4].delta, GetHashValue32(D_00461678)), *(char**)((char*)self + 0x6D4));
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = one;
        char* sub = (char*)p + 0xBC;
        int h = GetHashValue32(D_00461690);
        *(char**)((char*)p + 0xC4) = buf;
        *(int*)((char*)p + 0xC0) = one;
        *(int*)((char*)p + 0xC8) = three;
        *(int*)((char*)p + 0xCC) = h;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x14C) = three;
        *(int*)((char*)p + 0x150) = 0x80A;
        func_001A9BC0(self, p);
        break;
    }
    case 0x696E616D: {
        void* p = func_001A9C50(self);
        int three = 3;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004615F8);
        *(int*)((char*)p + 0xC0) = three;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x14C) = three;
        *(int*)((char*)p + 0x150) = 0x806;
        func_001A9BC0(self, p);
        break;
    }
    default:
        func_001A8E40_msg(self, *(int*)msg, msg);
        break;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A4FB0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A5010);
#ifdef SKIP_ASM
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void func_001A5898(void* self);
extern "C" void func_001A54D8(void* self);
extern "C" void func_001A52B0(void* self);
extern "C" void func_001A6978(void* self);
int func_001A98B0(void* self);
extern "C" void func_001AB3D0(void* self, int a1, int a2);
extern "C" void func_001A4D90(void* self);
extern "C" void func_001A4CE8(void* self, void* src);
extern "C" void func_001A4FB0(void* self, int a1, int a2);

// Message handler: refreshes the file list on most results, otherwise forwards to the base handler.
extern "C" void* func_001A5010(void* self, int a1, int a2)
{
    switch (a1) {
    case 0x107:
        func_001A5898(self);
    case 0xEA: case 0xEC: case 0xED: case 0xEF: case 0xF1: case 0x106:
    case 0x109: case 0x10A: case 0x10B: case 0x112: case 0x113:
        if (*(int*)((char*)self + 0x6AC) != 0) {
            break;
        }
        func_001A54D8(self);
        func_001A52B0(self);
        func_001A6978(self);
        func_001AB3D0(self, func_001A98B0(self), 0);
        break;
    case 0x10E:
        func_001A4D90(self);
        break;
    case 0xE3:
        func_001A4CE8(self, (void*)a2);
        break;
    case 0x102:
        func_001A4FB0(self, a1, a2);
        break;
    default:
        func_001AB3D0(self, func_001A98B0(self), 0);
        return func_001A8E40_3(self, a1, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A5128);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern char D_00461778[];
extern char D_00461788[];

struct sVec3_001A5128 {
    float x;
    float y;
    float z;
};

struct cUIObj_001A5128 {
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
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
    virtual void v20(void* out);
};

static inline sVec3_001A5128 GetPos_001A5128(cUIObj_001A5128* o)
{
    return *(sVec3_001A5128*)((char*)o + 0x44);
}

extern "C" void func_001A5128(void* self, int pos, int count)
{
    if (*(void**)((char*)self + 0x40) == 0) return;
    if (pos < 0) return;
    if (count < pos) return;
    if (count <= 0) return;
    cUIObj_001A5128* track = (cUIObj_001A5128*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461778));
    cUIObj_001A5128* thumb = (cUIObj_001A5128*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461788));
    if (thumb == 0) return;
    if (track == 0) return;
    sVec3_001A5128 size;
    track->v20(&size);
    sVec3_001A5128 p = *(sVec3_001A5128*)((char*)track + 0x44);
    float fpos = (float)pos;
    if (count >= 2) count--;
    float step = (size.y + -15.0f) / (float)count;
    sVec3_001A5128 np = p;
    np.y += fpos * step;
    np.x += -2.0f;
    *(sVec3_001A5128*)((char*)thumb + 0x44) = np;
    thumb->v09(1);
    track->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A52B0);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void* func_00263308(void* self, int a1);
extern "C" int func_00262938(void* self);
extern "C" void* func_00263630(void* self, int a1);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void cBXString__cBXString(void* self, int flags);
struct sOwner1A5800;
extern "C" int func_001A5800(sOwner1A5800* self, char** name);
extern void* D_004A3328;
extern void* D_004A3028;

struct sSession1A52B0 {
    char pad[0xBC];
    void** mBegin;
    void** mEnd;
};

static inline int Count1A52B0(sSession1A52B0* s) { return s->mEnd - s->mBegin; }

static inline void* GetSession_001A52B0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sBXString1A52B0 {
    char* str;
    sBXString1A52B0() {}
    sBXString1A52B0(const sBXString1A52B0& o);
};

extern "C" void func_001A52B0(void* self)
{
    void* name;
    if ((Count1A52B0((sSession1A52B0*)GetSession_001A52B0()) != 0 && (name = func_00263308(GetSession_001A52B0(), 0)) != 0)
        || (func_00262938(GetSession_001A52B0()) > 0 && (name = func_00263630(GetSession_001A52B0(), 0)) != 0)) {
        sBXString1A52B0 s;
        cBXString_cBXString1(&s, name);
        *(int*)((char*)self + 0x6F8) = func_001A5800((sOwner1A5800*)self, &s.str);
        cBXString__cBXString(&s, 2);
    } else {
        *(int*)((char*)self + 0x6F8) = -1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A5450);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* func_0041610C(void* dst, void* src, int n);

struct sPtrVec1A5450 {
    void** mBegin;
    void** mEnd;
};

struct sOwner1A5450 {
    char pad[0x6E8];
    sPtrVec1A5450 mVec;
};

extern "C" void func_001A5450(sOwner1A5450* self)
{
    for (;;) {
        if (self->mVec.mBegin == self->mVec.mEnd) break;
        void* p = self->mVec.mEnd[-1];
        self->mVec.mEnd--;
        if (p) {
            cBXString__cBXString(p, 3);
        }
    }
    void** first = self->mVec.mBegin;
    void** last = self->mVec.mEnd;
    void** finish = last;
    func_0041610C(first, last, (char*)finish - (char*)last);
    self->mVec.mEnd -= last - first;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A54D8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_00262598(void* self);
extern "C" const char* func_002625C8(void* self, int idx);
extern "C" int func_00262438(void* self, const char* name);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString2(void* self, const char* str);
struct sOwner1A56D0;
extern "C" int func_001A56D0(sOwner1A56D0* self, const char* name);
extern "C" void func_001DB778(void* vec, void** pos, void* const* val);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_00461798[];

static inline void* GetSession_001A54D8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sElem1A54D8 {
    void* v;
    sElem1A54D8(void* const& x) : v(x) {}
    void* operator new(unsigned int, void* p) throw() { return p; }
};

static inline void Construct1A54D8(sElem1A54D8* p, void* const& x) { new (p) sElem1A54D8(x); }

struct sPtrVec1A54D8 {
    int f0;
    sElem1A54D8* mBegin;
    sElem1A54D8* mEnd;
    sElem1A54D8* mCap;
};

struct sOwner1A54D8 {
    char pad[0x6E4];
    sPtrVec1A54D8 mNames;
};

static inline void PushBack1A54D8(sOwner1A54D8* o, void* x)
{
    sPtrVec1A54D8* v = &o->mNames;
    if (o->mNames.mEnd != o->mNames.mCap) {
        Construct1A54D8(v->mEnd, x);
        ++o->mNames.mEnd;
    } else {
        func_001DB778(v, (void**)o->mNames.mEnd, &x);
    }
}

extern "C" void func_001A54D8(void* self)
{
    if (*(int*)((char*)GetSession_001A54D8() + 0xE8) != 0) {
        int i;
        for (i = 0; i < func_00262598(GetSession_001A54D8()); i++) {
            const char* name = func_002625C8(GetSession_001A54D8(), i);
            if (name != 0 && func_00262438(GetSession_001A54D8(), name) != 0 && func_001A56D0((sOwner1A56D0*)self, name) == 0) {
                void* s = cBXString_cBXString2(cMemMan_alloc(4, D_00461798, 0x20000000, 0), name);
                PushBack1A54D8((sOwner1A54D8*)self, s);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A56D0);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);

struct sOwner1A56D0 {
    char pad[0x6E8];
    char*** mBegin;
    char*** mEnd;
};

static inline unsigned int Count1A56D0(sOwner1A56D0* s) { return s->mEnd - s->mBegin; }

extern "C" int func_001A56D0(sOwner1A56D0* self, const char* name)
{
    unsigned int i;
    for (i = 0; i < Count1A56D0(self); i++) {
        if (func_0041AA88(**(char***)((char*)self->mBegin + (i << 2)), name) == 0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A5800);
#ifdef SKIP_ASM
extern "C" int func_0041AA88(const char* a, const char* b);

struct sOwner1A5800 {
    char pad[0x6E8];
    char*** mBegin;
    char*** mEnd;
};

static inline unsigned int Count1A5800(sOwner1A5800* s) { return s->mEnd - s->mBegin; }

extern "C" int func_001A5800(sOwner1A5800* self, char** name)
{
    unsigned int i;
    for (i = 0; i < Count1A5800(self); i++) {
        if (func_0041AA88(**(char***)((char*)self->mBegin + (i << 2)), *name) == 0) {
            return i;
        }
    }
    return -1;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A5898);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A5FB8);
#ifdef SKIP_ASM
struct sVE1A5FB8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern char D_004615B0[];
extern "C" int sprintf(char* buf, const char* fmt, ...);
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001A66A8(void* self, unsigned int index, int flag);

extern "C" void func_001A5FB8(void* self, int sel)
{
    char buf[32];
    int i;
    for (i = 0; i < 15; i++) {
        sprintf(buf, D_004615B0, i);
        void* obj = (void*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (obj != 0) {
            sVE1A5FB8* vt = *(sVE1A5FB8**)((char*)obj + 0x8);
            vt[9].fn((char*)obj + vt[9].delta, i == sel);
        }
        func_001A66A8(self, sel, i == sel);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6070);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_002624F8(void* self, int id);
extern "C" const char* func_002625C8(void* self, int idx);
extern "C" int func_00263338(void* self, int a1);
extern "C" int func_002633F8(void* self, int a1);
extern "C" void func_001A7390(void* self, const char* str, int a2);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004A1390[];
extern char D_00461558[];
extern char D_004617A8[];
extern char D_004617B8[];
extern char D_004617C8[];
extern char D_004617E0[];

static inline void* GetSession_001A6070()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

class cFEVObj_001A6070 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" int func_001A6070(void* self, int idx)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        return 0;
    }
    cFEVObj_001A6070* name = (cFEVObj_001A6070*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004617A8));
    cFEVObj_001A6070* status = (cFEVObj_001A6070*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461558));
    if (status == 0 || name == 0) {
        return 0;
    }
    int n = *(int**)((char*)self + 0x6EC) - *(int**)((char*)self + 0x6E8);
    if (n == 0) {
        cUIText_setAsciiString((cUIText*)name, D_004A1390);
        if (*(int*)((char*)GetSession_001A6070() + 0xE8) != 0) {
            cUIText_setUnicodeStringByID((cUIText*)status, GetHashValue32(D_004617B8));
        } else {
            cUIText_setUnicodeStringByID((cUIText*)status, GetHashValue32(D_004617C8));
            GetSession_001A6070();
        }
        return 0;
    }
    if (idx >= n) {
        return 0;
    }
    int e = *(int*)(*(char**)((char*)self + 0x6E8) + (idx << 2));
    int id = func_002624F8(GetSession_001A6070(), e);
    const char* str = func_002625C8(GetSession_001A6070(), id);
    if (str == 0) {
        return 0;
    }
    cBXString_cBXString4((char*)self + 0x6E0, str);
    cUIText_setAsciiString((cUIText*)name, str);
    name->v09(1);
    status->v09(1);
    if (func_00263338(GetSession_001A6070(), id) != 0) {
        func_001A7390(self, str, func_002633F8(GetSession_001A6070(), id));
    } else {
        cUIText_setUnicodeStringByID((cUIText*)status, GetHashValue32(D_004617E0));
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A63C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_004617F8[];
extern char D_00461808[];
extern char D_00461818[];

class cFEVObj_001A63C8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001A63C8(void* self, unsigned int index, int state)
{
    char name[32];
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    if (index >= 15) {
        return;
    }
    sprintf(name, D_004617F8, index);
    cFEVObj_001A63C8* a = (cFEVObj_001A63C8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    sprintf(name, D_00461808, index);
    cFEVObj_001A63C8* b = (cFEVObj_001A63C8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    sprintf(name, D_00461818, index);
    cFEVObj_001A63C8* c = (cFEVObj_001A63C8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    switch (state) {
    case 0:
        if (a) a->v09(0);
        if (b) b->v09(1);
        if (c) c->v09(0);
        break;
    case 1:
        if (a) a->v09(1);
        if (b) b->v09(0);
        if (c) c->v09(0);
        break;
    case 2:
        if (a) a->v09(0);
        if (b) b->v09(0);
        if (c) c->v09(1);
        break;
    default:
        if (a) a->v09(0);
        if (b) b->v09(0);
        if (c) c->v09(0);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6618);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_004615A0[];

extern "C" void func_001A6618(void* self, unsigned int index, const char* str, int a3)
{
    char buf[32];
    if (*(void**)((char*)self + 0x40) != 0 && index < 0xF) {
        sprintf(buf, D_004615A0, index);
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (text != 0) {
            cUIText_setAsciiString(text, str);
            *(int*)((char*)text + 0x18) = a3;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A66A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_001A4670(void* self, int idx);
extern "C" int func_001A4740(void* self, int a1);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_002624F8(void* self, int id);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004615A0[];
extern char D_00461830[];

static inline void* GetSession_001A66A8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sCol_001A66A8 {
    float r, g, b, a;
    sCol_001A66A8() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
    sCol_001A66A8(const float& r_) : r(r_), g(0.0f), b(0.0f), a(0.0f) {}
    sCol_001A66A8(const float& r_, const float& g_, const float& b_, const float& a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cFEVObj_001A66A8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol_001A66A8& c);
};

extern "C" void func_001A66A8(void* self, unsigned int index, int flag)
{
    char name[32];
    if (*(void**)((char*)self + 0x40) == 0 || index >= 15) {
        return;
    }
    sprintf(name, D_004615A0, index);
    cFEVObj_001A66A8* persona = (cFEVObj_001A66A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    sprintf(name, D_00461830, index);
    cFEVObj_001A66A8* overlay = (cFEVObj_001A66A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    if (flag != 0) {
        overlay->v11(sCol_001A66A8(1.0f, 0.6078431606292725f, 0.24313727021217346f, 0.0f));
        persona->v11(sCol_001A66A8(1.0f, 1.0f, 1.0f, 1.0f));
        return;
    }
    unsigned int idx = func_001A4740(self, index);
    if (idx >= (unsigned int)(*(int**)((char*)self + 0x6EC) - *(int**)((char*)self + 0x6E8))) {
        overlay->v11(sCol_001A66A8());
        return;
    }
    persona->v11(sCol_001A66A8(1.0f));
    switch (func_001A4670(self, func_002624F8(GetSession_001A66A8(), *(int*)(*(char**)((char*)self + 0x6E8) + (idx << 2))))) {
    case 2:
        overlay->v11(sCol_001A66A8(1.0f, 0.5372549295425415f, 0.7411764860153198f, 0.874509871006012f));
        break;
    case 0:
        overlay->v11(sCol_001A66A8(1.0f, 0.501960813999176f, 0.501960813999176f, 0.501960813999176f));
        break;
    case 1:
    default:
        overlay->v11(sCol_001A66A8(1.0f, 0.30588236451148987f, 0.545098066329956f, 0.7019608020782471f));
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6978);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001A5FB8(void* self, int sel);
extern "C" int func_001A6070(void* self, int sel);
extern "C" void func_001A66A8(void* self, unsigned int index, int flag);
extern "C" void func_001A6CA0(void* self);
struct sOwner1A6E70;
extern "C" void func_001A6E70(sOwner1A6E70* self);
extern "C" void func_001A71B0(void* self, unsigned int index, const char* name, int a3);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_002624F8(void* self, int id);
extern "C" const char* func_002625C8(void* self, int idx);
extern "C" void func_0039B760(void* self, unsigned char a1);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_00461590[];

static inline void* GetSession_001A6978()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sIntVec_001A6978 {
    int f0;
    int* mBegin;
    int* mEnd;
};

struct sOwner_001A6978 {
    char pad[0x40];
    void* screen;
    char pad44[0x6E4 - 0x44];
    sIntVec_001A6978 mVec;
    char pad6F0[0x6F4 - 0x6F0];
    unsigned int mTop;
};

static inline unsigned int Size_001A6978(sOwner_001A6978* o) { return o->mVec.mEnd - o->mVec.mBegin; }

extern "C" void func_001A6978(void* vself)
{
    sOwner_001A6978* self = (sOwner_001A6978*)vself;
    if (self->screen == 0) {
        return;
    }
    func_001A6E70((sOwner1A6E70*)self);
    func_001A6CA0(self);
    unsigned int n = Size_001A6978(self);
    unsigned int first = self->mTop;
    if (n >= 16) {
        if (n - first < 15) {
            int top = n - 15;
            first = top;
        }
    }
    int count = 0;
    int row = 0;
    while (row < 15 && first < Size_001A6978(self)) {
        int id = *(int*)((char*)self->mVec.mBegin + (first << 2));
        int idx = func_002624F8(GetSession_001A6978(), id);
        if (idx < 0) {
            func_001A71B0(self, row, 0, -1);
        } else {
            count++;
            func_001A71B0(self, row, func_002625C8(GetSession_001A6978(), idx), idx);
            func_001A66A8(self, row, 0);
        }
        row++;
        first++;
    }
    cUIText* menu = cUIScreen_getObjectByHashName(self->screen, GetHashValue32(D_00461590));
    if (menu != 0) {
        if (*(unsigned char*)((char*)menu + 0x96) != Size_001A6978(self)) {
            func_0039B760(menu, Size_001A6978(self));
            if (Size_001A6978(self) == 0) {
                func_0039B760(menu, 1);
            }
        }
        if (func_001A6070(self, *(unsigned char*)((char*)menu + 0x95)) != 0 && Size_001A6978(self) != 0) {
            func_001A5FB8(self, *(unsigned char*)((char*)menu + 0x95) - *(unsigned char*)((char*)menu + 0x98));
            func_001A66A8(self, *(unsigned char*)((char*)menu + 0x95) - *(unsigned char*)((char*)menu + 0x98), 1);
        } else {
            func_001A5FB8(self, -1);
        }
    }
    for (row = count; row < 15; row++) {
        func_001A71B0(self, row, 0, -1);
        func_001A66A8(self, row, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6C40);
#ifdef SKIP_ASM
extern char D_00461590[];
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);

extern "C" void func_001A6C40(void* self, int idx)
{
    if (*(void**)((char*)self + 0x40) != 0 && idx >= 0) {
        void* menu = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461590));
        if (menu != 0) {
            cUIMenu_setSelectedByIndex(menu, idx);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6CA0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001A52B0(void* self);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004A1A20[];
extern char D_00461570[];
extern char D_00461840[];
extern char D_00461858[];

struct sSession1A6CA0 {
    char pad[0xBC];
    void** mBegin;
    void** mEnd;
};

static inline int Count1A6CA0(sSession1A6CA0* s) { return s->mEnd - s->mBegin; }

static inline void* GetSession_001A6CA0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

class cFEVObj_001A6CA0 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001A6CA0(void* self)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    func_001A52B0(self);
    int has = *(int*)((char*)self + 0x6F8) >= 0;
    cFEVObj_001A6CA0* o = (cFEVObj_001A6CA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1A20));
    if (o != 0) {
        o->v09(has);
    }
    o = (cFEVObj_001A6CA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461570));
    if (o != 0) {
        o->v09(has);
    }
    cFEVObj_001A6CA0* a = (cFEVObj_001A6CA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461840));
    cFEVObj_001A6CA0* b = (cFEVObj_001A6CA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461858));
    if (a != 0 && b != 0) {
        if (!has) {
            a->v09(0);
            b->v09(0);
        } else if (Count1A6CA0((sSession1A6CA0*)GetSession_001A6CA0()) != 0) {
            a->v09(has);
            b->v09(0);
        } else {
            b->v09(has);
            a->v09(0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A6E70);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_002624F8(void* self, int id);
extern "C" void* func_0041610C(void* dst, void* src, int n);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001A6E70()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sIntVec1A6E70 {
    int f0;
    int* mBegin;
    int* mEnd;
};

static inline int* Copy1A6E70(int* first, int* last, int* result)
{
    func_0041610C(result, first, (last - first) * sizeof(int));
    return result + (last - first);
}

struct sOwner1A6E70 {
    char pad[0x6E4];
    sIntVec1A6E70 mVec;
};

extern "C" void func_001A6E70(sOwner1A6E70* self)
{
    int i;
    for (i = (self->mVec.mEnd - self->mVec.mBegin) - 1; i >= 0; i--) {
        sIntVec1A6E70* v = &self->mVec;
        int id = *(int*)((char*)self->mVec.mBegin + (i << 2));
        if (func_002624F8(GetSession_001A6E70(), id) < 0) {
            // PORT: pointer arithmetic through int
            int* pos = (int*)(i * 4 + (int)self->mVec.mBegin);
            if (pos + 1 != self->mVec.mEnd) {
                Copy1A6E70(pos + 1, v->mEnd, pos);
            }
            self->mVec.mEnd--;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A71B0);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_00263128(void* self, const char* name);
extern "C" int func_002623B0(void* self, const char* name);
// PORT: the unit declares func_00262A38 with an int name parameter; this caller passes a string
extern "C" int func_00262A38(void* self, int a1);
extern "C" void func_001A63C8(void* self, unsigned int index, int state);
extern "C" void func_001A6618(void* self, unsigned int index, const char* str, int a3);
extern "C" void func_001A66A8(void* self, unsigned int index, int flag);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004A1390[];

static inline void* GetSession_001A71B0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001A71B0(void* self, unsigned int index, const char* name, int a3)
{
    if (index >= 15) {
        return;
    }
    if (name == 0) {
        func_001A63C8(self, index, 3);
        func_001A6618(self, index, D_004A1390, a3);
        func_001A66A8(self, index, 1);
        return;
    }
    if (func_00263128(GetSession_001A71B0(), name)) {
        func_001A63C8(self, index, 2);
    } else if (func_002623B0(GetSession_001A71B0(), name)) {
        func_001A63C8(self, index, 0);
    } else if (func_00262A38(GetSession_001A71B0(), (int)name)) {
        func_001A63C8(self, index, 1);
    } else {
        func_001A63C8(self, index, 3);
    }
    func_001A6618(self, index, name, a3);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A7390);

INCLUDE_ASM("fe/feasyncfile", func_001A77A0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7848);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* func_0041610C(void* dst, void* src, int n);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");
void cMemMan_free(void* p);
void operator_delete(int* ptr);
extern char D_00467E18[];

struct sVE1A7848 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj1A7848 {
    char pad[0xC];
    sVE1A7848* vt;
};

struct sObjVec1A7848 {
    int f0;
    sObj1A7848** mBegin;
    sObj1A7848** mEnd;
    sObj1A7848** mCap;
};

static inline void Dealloc1A7848(sObj1A7848** p, int n)
{
    if (p != 0) {
        if (n == 1) {
            operator_delete((int*)p);
        } else {
            cMemMan_free(p);
        }
    }
}

struct sOwner1A7848 {
    char pad0[0x8];
    void* vt;
    char padC[0x6C4];
    char str[8];
    sObjVec1A7848 mVec;
};

extern "C" void func_001A7848(sOwner1A7848* self, int flags)
{
    self->vt = D_00467E18;
    for (;;) {
        if (self->mVec.mBegin == self->mVec.mEnd) break;
        sObj1A7848* p = self->mVec.mEnd[-1];
        self->mVec.mEnd--;
        if (p) {
            p->vt[1].fn((char*)p + p->vt[1].delta, 3);
        }
    }
    sObjVec1A7848* v = &self->mVec;
    sObj1A7848** first = self->mVec.mBegin;
    sObj1A7848** last = self->mVec.mEnd;
    func_0041610C(first, last, (v->mEnd - last) * sizeof(sObj1A7848*));
    self->mVec.mEnd -= last - first;
    Dealloc1A7848(v->mBegin, self->mVec.mCap - self->mVec.mBegin);
    cBXString__cBXString(self->str, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7970);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_003A1310(void* self, int a1);
extern char D_004619A0[];
extern char D_004619B8[];
extern char D_004619C8[];
extern char D_004619D8[];
extern char D_004619E8[];
extern char D_004619F8[];

struct sCol1A7970 {
    float r, g, b, a;
    sCol1A7970(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

struct sBlk1A7970 {
    int v[4];
};

class cFEVObj_001A7970 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol1A7970& c);
};

extern "C" void func_001A7970(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004619A0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    char* a = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619B8));
    *(int*)(a + 0x14) |= 1;
    void* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619C8));
    void* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619D8));
    void* d = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619E8));
    *(void**)(a + 0x7C) = b;
    *(void**)(a + 0x80) = c;
    *(void**)(a + 0x84) = d;
    *(int*)(a + 0x88) = 2;
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619F8));
    if (o != 0) {
        cFEVObj_001A7970* obj = (cFEVObj_001A7970*)o;
        *(int*)(o + 0x74) |= 1;
        func_003A1310(o, 1);
        obj->v09(1);
        *(int*)(o + 0x14) |= 0x80;
        obj->v11(sCol1A7970(1.0f, 0.0f, 0.0f, 0.0f));
        *(sBlk1A7970*)(o + 0xA8) = *(sBlk1A7970*)((char*)self + 0x6EC);
        *(char**)(o + 0xB8) = a;
    }
}
#endif

extern "C" void* func_001A8770(void* self);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7B20__FPv);
#ifdef SKIP_ASM
void* func_001A7B20(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7B40);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001A7B40()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 10, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7BB0__FPv);
#ifdef SKIP_ASM
void func_001A7BB0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7BB8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262690(void* self, int a1, void* a2);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE468(void* self, int v);
extern "C" void func_001A81F0(void* self);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A7ED8(void* self, const char* name);
extern "C" void func_001A9090(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004A1408[];

struct cFEObj_001A7BB8 {
    int f0;
    int f4;
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
    virtual void v17(void* a1, int a2);
};

extern "C" void func_001A7BB8(void* self, int a1, unsigned int msg)
{
    switch (msg) {
    case 6:
        (*(cFEObj_001A7BB8**)((char*)self + 0x20))->v17(self, 0x14);
        break;
    case 5:
        func_001A9090(self, 0, *(int*)((char*)self + 0x6D0), (int)D_004A1408, 0, 0, 0x3F);
        *(int*)(*(char**)((char*)self + 0x69C) + 0x43C) = 0;
        func_001CE3C8(*(void**)((char*)self + 0x69C), 0x4B, 1, 2);
        func_001CE468(*(void**)((char*)self + 0x69C), 1);
        *(int*)(*(char**)((char*)self + 0x69C) + 0x438) = 1;
        break;
    case 7:
        break;
    case 13:
        func_001A7ED8(self, *(char**)((char*)self + 0x69C) + 0x74);
        if (D_004A3328 == 0) {
            func_00260F80();
        }
        if (func_00261460(D_004A3328) == 0) {
            func_002613C8(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800(D_004A3028);
        }
        func_00262690(D_004A3328, *(int*)((char*)self + 0x6D0), *(char**)((char*)self + 0x69C) + 0x74);
        func_001A81F0(self);
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7D10);
#ifdef SKIP_ASM
extern "C" void func_001A81F0(void* self);

extern "C" int func_001A7D10(void* self, int a1, int a2, int a3)
{
    if (a2 == 4) {
        *(int*)((char*)self + 0x6D4) = a3;
        func_001A81F0(self);
        return 0;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7D40);
#ifdef SKIP_ASM
extern "C" void func_001A7F78(void* self);
extern "C" void func_001A81F0(void* self);
extern "C" void* func_001A8E40(void* self);
extern "C" void* func_001A7D40(void* self, int msg)
{
    if (msg == 0x109) {
        func_001A7F78(self);
        func_001A81F0(self);
        return 0;
    }
    return func_001A8E40(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7D90);
#ifdef SKIP_ASM
class cFEVObj_001A7D90 {
public:
    int field_0x0;
    int field_0x4;
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
};

extern "C" void func_001A7F78(void* self);
extern "C" void func_001A81F0(void* self);

extern "C" int func_001A7D90(cFEVObj_001A7D90* self)
{
    self->v32();
    func_001A7F78(self);
    func_001A81F0(self);
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7DD8);
#ifdef SKIP_ASM
extern "C" void* func_0041610C(void* dst, void* src, int n);

struct sVE1A7DD8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

struct sObj1A7DD8 {
    char pad[0xC];
    sVE1A7DD8* vt;
};

struct sObjVec1A7DD8 {
    int f0;
    sObj1A7DD8** mBegin;
    sObj1A7DD8** mEnd;
    sObj1A7DD8** mCap;
};

extern "C" void func_001DB918(sObjVec1A7DD8* vec, sObj1A7DD8** pos, sObj1A7DD8* const* x);

static inline sObj1A7DD8** Copy1A7DD8(sObj1A7DD8** first, sObj1A7DD8** last, sObj1A7DD8** result)
{
    func_0041610C(result, first, (last - first) * sizeof(sObj1A7DD8*));
    return result + (last - first);
}

struct sOwner1A7DD8 {
    char pad0[0x6D8];
    sObjVec1A7DD8 mVec;
};

extern "C" void func_001A7DD8(void* selfp, void* item)
{
    sOwner1A7DD8* self = (sOwner1A7DD8*)selfp;
    sObj1A7DD8* x = (sObj1A7DD8*)item;
    for (;;) {
        if ((unsigned int)(self->mVec.mEnd - self->mVec.mBegin) < 31) break;
        sObjVec1A7DD8* v = &self->mVec;
        sObj1A7DD8** pos = self->mVec.mBegin;
        sObj1A7DD8* p = *pos;
        if (p) {
            if (pos + 1 != self->mVec.mEnd) {
                Copy1A7DD8(pos + 1, v->mEnd, pos);
            }
            self->mVec.mEnd--;
            p->vt[1].fn((char*)p + p->vt[1].delta, 3);
        }
    }
    sObjVec1A7DD8* v2 = &self->mVec;
    if (self->mVec.mEnd != self->mVec.mCap) {
        sObj1A7DD8** e = v2->mEnd;
        if (e) *e = x;
        self->mVec.mEnd++;
    } else {
        func_001DB918(v2, self->mVec.mEnd, &x);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A7ED8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString2(void* self, const char* str);
extern "C" void func_001A7DD8(void* self, void* item);
extern char D_00461A08[];
extern void* D_0046D8C0[];
extern char D_004A1408[];
extern void* D_004A3028;

static inline void* Init_001A7ED8(char* p, const char* a, const char* b, const char* c)
{
    *(void***)(p + 0xC) = D_0046D8C0;
    cBXString_cBXString2(p, a);
    cBXString_cBXString2(p + 4, b);
    cBXString_cBXString2(p + 8, c);
    return p;
}

extern "C" void func_001A7ED8(void* self, const char* name)
{
    func_001A7DD8(self, Init_001A7ED8((char*)cMemMan_alloc(0x10, D_00461A08, 0x20000000, 0),
                                      *(const char**)((char*)D_004A3028 + 0x80), name, D_004A1408));
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A7F78);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void func_001A7DD8(void* self, void* item);
extern "C" void func_0025B800(void* self);
extern "C" void func_00260F80();
extern "C" void func_002613C8(void* self);
extern "C" int func_00261460(void* self);
extern "C" int func_00262938(void* self);
extern "C" void func_002635A8(void* self, int idx);
extern "C" void* func_00263630(void* self, int a1);
extern "C" int func_0041AA88(const char* a, const char* b);
extern char D_00461A08[];
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern void* D_0046D8C0[];
extern void* D_004A3028;
extern void* D_004A3328;

static inline void* GetSession_001A7F78()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

static inline void* Init_001A7F78(char* p, char* src)
{
    *(void***)(p + 0xC) = D_0046D8C0;
    cBXString_cBXString1(p, src);
    cBXString_cBXString1(p + 4, src + 4);
    cBXString_cBXString1(p + 8, src + 8);
    return p;
}

extern "C" void func_001A7F78(void* self)
{
    for (int i = 0; i < func_00262938(GetSession_001A7F78()); i++) {
        char* item = (char*)func_00263630(GetSession_001A7F78(), i);
        if (item != 0 && func_0041AA88(*(const char**)item, *(const char**)((char*)self + 0x6D0)) == 0) {
            func_001A7DD8(self, Init_001A7F78((char*)operator new(0x10, D_00461A08, 0x20000000, 0), item));
        }
    }
    for (int i = func_00262938(GetSession_001A7F78()) - 1; i >= 0; i--) {
        char* item = (char*)func_00263630(GetSession_001A7F78(), i);
        if (item != 0 && func_0041AA88(*(const char**)item, *(const char**)((char*)self + 0x6D0)) == 0) {
            func_002635A8(GetSession_001A7F78(), i);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A81F0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
struct sList1A83D8;
extern "C" void func_001A83D8(sList1A83D8* list, int keep, unsigned int sel, int a3, int pos, int a5, int a6, int trim);
// PORT: func_002C26D0 is a varargs formatter (dst, fmt, ...); the unit declares a 3-arg view
extern "C" void func_002C26D0_1A81F0(void* str, int fmt, ...) __asm__("func_002C26D0");
extern "C" void func_003A0E90(cUIText* text, char* str);
extern "C" void func_003A18C0(void* list);
extern "C" void func_003A19F8(cUIText* text, char* str);
extern "C" char* func_004162D0(char*, const char*);
extern "C" char* strcpy(char* dst, const char* src);
extern void* D_004A28A8;
extern char D_00461A18[];
extern char D_00461A28[];
extern char D_004619F8[];
extern char D_004A1408[];
extern char D_004A1A50[];

struct sVEntry_001A81F0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1A81F0(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001A81F0* vt = *(sVEntry_001A81F0**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

struct sEntry1A81F0 {
    char* name;
    char* ext;
    char* desc;
};

struct sOwner1A81F0 {
    char pad[0x6DC];
    sEntry1A81F0** mBegin;
    sEntry1A81F0** mEnd;
};

static inline unsigned int Count1A81F0(sOwner1A81F0* s) { return s->mEnd - s->mBegin; }

class cFEVObj_001A81F0 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001A81F0(void* self)
{
    char buf[0x100];
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00461A18));
    if (text != 0 && Count1A81F0((sOwner1A81F0*)self) != 0) {
        sEntry1A81F0* e = ((sOwner1A81F0*)self)->mBegin[0];
        char* who = *(char**)((char*)self + 0x6D0);
        func_002C26D0_1A81F0(buf, Loc1A81F0(D_00461A28), who, e->desc, D_004A1408);
        func_003A0E90(text, buf);
        ((cFEVObj_001A81F0*)text)->v09(1);
    }
    cUIText* list = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619F8));
    if (list == 0) {
        return;
    }
    unsigned short count = *(unsigned short*)((char*)list + 0xC8);
    unsigned short top = *(unsigned short*)((char*)list + 0xC4);
    unsigned short sel = *(unsigned short*)((char*)list + 0xC6);
    func_003A18C0(list);
    unsigned int i;
    for (i = 0; i < Count1A81F0((sOwner1A81F0*)self); i++) {
        sEntry1A81F0* e = *(sEntry1A81F0**)((char*)((sOwner1A81F0*)self)->mBegin + (i << 2));
        strcpy(buf, e->name);
        func_004162D0(buf, D_004A1A50);
        func_004162D0(buf, e->ext);
        func_003A19F8(list, buf);
    }
    func_001A83D8((sList1A83D8*)list, 0x28, 8, count, top, sel, *(int*)((char*)self + 0x6E8), 0);
    *(int*)((char*)self + 0x6E8) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A83D8);
#ifdef SKIP_ASM
extern "C" void func_003A1F90(void* list, int a1);

struct sList1A83D8 {
    char pad[0xC4];
    short top;
    short sel;
    unsigned short count;
};

extern "C" void func_001A83D8(sList1A83D8* list, int keep, unsigned int sel, int a3, int pos, int a5, int a6, int trim)
{
    if (list == 0) return;
    int toEnd = 0;
    if (a3 == pos + 1 || a6 != 0) toEnd = 1;
    int n = list->count - keep;
    int atStart = pos == 0;
    int removed = 0;
    if (n > 0 && trim != 0) {
        for (removed = 0; removed < n; removed++) {
            func_003A1F90(list, 0);
        }
    }
    if (toEnd) {
        unsigned short c = list->count;
        if (sel >= c) {
            list->sel = 0;
        } else {
            list->sel = c - sel;
        }
        list->top = list->count - 1;
    } else if (atStart) {
        list->sel = 0;
        list->top = 0;
    } else {
        int d = pos - removed;
        if (d <= 0) {
            list->top = 0;
            list->sel = 0;
        } else {
            int e = a5 - removed;
            if (e <= 0) {
                list->sel = 0;
            } else {
                list->sel = e;
            }
            list->top = d;
        }
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A8500);

INCLUDE_ASM("fe/feasyncfile", func_001A85D0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A86E8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern void* D_004A3328;
extern void* D_004A3028;
extern int D_004A1A70;

extern "C" void func_001A86E8(int on)
{
    D_004A1A70 = on;
    if (on == 0 && D_004A3328 != 0 && func_00261460(D_004A3328) != 0) {
        if (D_004A3328 == 0) {
            func_00260F80();
        }
        if (func_00261460(D_004A3328) == 0) {
            func_002613C8(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800(D_004A3028);
        }
        func_00261408(D_004A3328);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8768__FPv);
#ifdef SKIP_ASM
void func_001A8768(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8770);
#ifdef SKIP_ASM
class cFEAsync1A8770 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
};

extern "C" void func_0039E510(void*);
extern "C" void* func_001A8B88(void* self, int size, int a2);

extern "C" void* func_001A8770(void* self)
{
    ((cFEAsync1A8770*)self)->v27();
    ((cFEAsync1A8770*)self)->v28();
    func_0039E510(self);
    return func_001A8B88(self, 0x114, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A87D0);
#ifdef SKIP_ASM
struct sVE1A87D0 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" void func_0039E4C0(void* self, int a1);

extern "C" void func_001A87D0(void* self, int a1)
{
    sVE1A87D0* vt = *(sVE1A87D0**)((char*)self + 0x8);
    vt[32].fn((char*)self + vt[32].delta);
    func_0039E4C0(self, a1);
    *(int*)((char*)self + 0x48) = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8828__FPv);
#ifdef SKIP_ASM
int func_001A8828(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8830);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

class cFEVObj_001A8830 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual int v29();
};

static inline void* GetSession_001A8830()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001A8830(cFEVObj_001A8830* self)
{
    if (self->v29() != 0) {
        func_00262768(GetSession_001A8830(), 1, 0, 0, 0, 0);
    } else {
        func_00262768(GetSession_001A8830(), 0, 1, 0, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8918);
#ifdef SKIP_ASM
class cFEVObj_001A8918 {
public:
    char pad[0x8];
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
    virtual void v25(void* popup);
};

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001D9D48(void* mem, void* a1, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00461A70[];

extern "C" void func_001A8918(void* self, int a1, int msg)
{
    if (a1 != 0 && msg == 7) {
        void* p = func_001D9D48(cMemMan_alloc(0x140, D_00461A70, 0x100, 0), *(void**)((char*)self + 0x10), self);
        *(int*)((char*)p + 0x50) = 1;
        ((cFEVObj_001A8918*)self)->v25(p);
        func_0039F290(*(char**)((char*)self + 0x10) + 0x18, p);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A89B0);
#ifdef SKIP_ASM
class cFEMsg_001A89B0 {
public:
    int field_0x0;
    int field_0x4;
    virtual ~cFEMsg_001A89B0();
};

extern void* D_004A3028;
extern "C" void func_001A9930(void* self);

extern "C" void* func_001A89B0(void* self, cFEMsg_001A89B0* msg)
{
    int kind = *(int*)((char*)msg + 0xC);
    if (*(int*)((char*)self + 0x6A8) != 0 && kind != 0x31 && kind != 0x33 && kind != 0x4D && kind != 0x4E
        && *(int*)D_004A3028 == 0) {
        delete msg;
        func_001A9930(self);
        return 0;
    }
    return msg;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8A40);
#ifdef SKIP_ASM
class cFEVObj_001A8A40 {
public:
    char pad[0x8];
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
    virtual void* v26(void* obj);
};

int GetHashValue32(char* str);
extern char D_0045DC60[];
struct cUIScreen;
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0039F4C0(void* list, void* item);
// PORT: the unit declares func_001A8A40 as returning void; the body returns 0/1
extern "C" int func_001A8A40_r(void* self, void* obj) __asm__("func_001A8A40");

extern "C" int func_001A8A40_r(void* self, void* obj)
{
    void* child = *(void**)((char*)self + 0x20);
    if (child != 0) {
        return func_001A8A40_r(child, obj);
    }
    void* item = ((cFEVObj_001A8A40*)self)->v26(obj);
    if (item != 0) {
        int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(D_0045DC60));
        if (frame != 0xFFFF) {
            cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
        }
        func_0039F4C0(*(char**)((char*)self + 0x10) + 0x18, item);
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8AE8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc is probably the game's overloaded operator new(size, tag, flags, align). Calling it as
// operator new gives gcc's malloc-like (REG_NOALIAS) aliasing that the target shows. On PC use a real operator new.
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern char D_0045CDE8[];

class cFEVObj_001A8AE8 {
public:
    int field_0x0;
    virtual void* v01();
    virtual void* v02();
};

struct sListNode1A8AE8 {
    void* mNext;
    void* mPrev;
    void* mData;
};

struct sListIter1A8AE8 {
    sListNode1A8AE8* mNode;
    sListIter1A8AE8(sListNode1A8AE8* x) : mNode(x) {}
    sListIter1A8AE8(const sListIter1A8AE8& x) : mNode(x.mNode) {}
};

static inline sListIter1A8AE8 ListInsert1A8AE8(sListIter1A8AE8 pos, void* const& x)
{
    sListNode1A8AE8* tmp = (sListNode1A8AE8*)operator new(0xC, D_0045CDE8, 0x20000000, 0);
    void** data = &tmp->mData;
    if (data != 0) {
        *data = x;
    }
    tmp->mNext = pos.mNode;
    tmp->mPrev = pos.mNode->mPrev;
    ((sListNode1A8AE8*)(pos.mNode->mPrev))->mNext = tmp;
    pos.mNode->mPrev = tmp;
    return tmp;
}

extern "C" void func_001A8AE8(void* self, cFEVObj_001A8AE8* obj)
{
    if (obj != 0) {
        void* item = obj->v02();
        if (item != 0) {
            ListInsert1A8AE8(*(sListNode1A8AE8**)((char*)self + 0x6CC), item);
        }
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A8B88);

INCLUDE_ASM("fe/feasyncfile", func_001A8E40);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A8F98);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_00461618[];
extern char D_00461C40[];

static inline void* GetSession_001A8F98()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001A8F98(void* self)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 1;
    func_001C57C0((char*)p + 0xBC, 0, GetHashValue32(D_00461618));
    int h = GetHashValue32(D_00461C40);
    *(int*)((char*)p + 0xC4) = h;
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x150) = 0x83E;
    *(int*)((char*)p + 0x14C) = 6;
    func_001A9BC0(self, p);
    func_00261408(GetSession_001A8F98());
    func_0025B800(D_004A3028);
    func_002636F0(func_002591B8(), 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9090);
#ifdef SKIP_ASM
extern "C" void func_001A91B0(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_001CCF00(void* p, int a);
extern "C" void func_001CB418(void* p, int a);

extern "C" void func_001A9090(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    func_001A91B0(self, a1, a4, a5, a6);
    func_001CCF00(*(void**)((char*)self + 0x69C), a2);
    func_001CB418(*(void**)((char*)self + 0x69C), a3);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9150);
#ifdef SKIP_ASM
extern "C" void func_001A91B0(void* self, int a1, int a2, int a3, int a4);
extern "C" void func_001CD020(void* p, int a);
extern "C" void func_001CB418(void* p, int a);

extern "C" void func_001A9150(void* self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    func_001A91B0(self, a1, a4, a5, a6);
    func_001CD020(*(void**)((char*)self + 0x69C), a2);
    func_001CB418(*(void**)((char*)self + 0x69C), a3);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A91B0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001CB030(void* mem, void* engine, void* owner, int a3, unsigned char a4);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_001CD088(void* self, int v);
extern char D_0045D8D8[];

extern "C" void func_001A91B0(void* self, int a1, int a2, int a3, int a4)
{
    void* p = func_001CB030(cMemMan_alloc(0x444, D_0045D8D8, 0x100, 0), *(void**)((char*)self + 0x10), self, a2, 0xF);
    *(void**)((char*)self + 0x69C) = p;
    func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
    *(int*)((char*)*(void**)((char*)self + 0x69C) + 0x18) = a3;
    func_001CD088(*(void**)((char*)self + 0x69C), a4);
    *(int*)((char*)self + 0x6A4) = a1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A9268);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern const char D_00461C60[];

extern "C" void func_001A9268(void* self, int a1, int a2)
{
    if (a2 == 0xF) {
        func_001A93D0_3(self, a1, 0xF);
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
    } else {
        func_001A93D0_3(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A92D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");

struct sVE1A92D8 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE1A92D8b {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001A92D8(void* self, int a1, unsigned int kind)
{
    switch (kind) {
    case 21:
        *(int*)((char*)self + 0x6BC) = 2;
        func_001A93D0_3(self, a1, 0x15);
        break;
    case 15:
        *(int*)((char*)self + 0x6BC) = 0;
        func_001A93D0_3(self, a1, 0xF);
        break;
    case 22: {
        sVE1A92D8* vt = *(sVE1A92D8**)((char*)self + 0x8);
        vt[32].fn((char*)self + vt[32].delta);
        if (*(int*)((char*)self + 0x6BC) == 0) {
            char* obj = *(char**)((char*)self + 0x20);
            sVE1A92D8b* vt2 = *(sVE1A92D8b**)(obj + 0x8);
            vt2[17].fn(obj + vt2[17].delta, self, 0xF);
        }
        func_001A93D0_3(self, a1, 0x16);
        break;
    }
    default:
        func_001A93D0_3(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A93D0);
#ifdef SKIP_ASM
extern "C" void func_0039F190(void* self, int a1);

// PORT: the unit declares this with a 4th arg; defined under an asm label with its real type
extern "C" void func_001A93D0_impl(void* self, int id, int event) __asm__("func_001A93D0");
extern "C" void func_001A93D0_impl(void* self, int id, int event)
{
    switch (event) {
    case 15: case 16: case 17: case 18: case 20:
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        break;
    case 22:
        if (id == *(int*)((char*)self + 0x6A0)) {
            *(int*)((char*)self + 0x6A0) = 0;
        }
        break;
    case 19:
    case 21:
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A9438);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cFEVObj_001A9438 {
public:
    char pad[0x8];
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
};

// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001BEE30(void* mem, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern const char D_00461CA0[];

extern "C" void func_001A9438(void* self, int a1, int a2)
{
    if (a2 == 0x16) {
        ((cFEVObj_001A9438*)self)->v32();
        func_001A8A40(self, func_001BEE30(cMemMan_alloc(0x6D4, D_00461CA0, 0, 0), *(int*)((char*)self + 0x10)));
        func_001A93D0_3(self, a1, 0x16);
    } else {
        func_001A93D0_3(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A94D8__FPv);
#ifdef SKIP_ASM
void func_001A94D8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A94E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cFEVObj_001A94E0 {
public:
    char pad[0x8];
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
};
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");

extern "C" void func_001A94E0(void* self, int a1, int a2)
{
    switch (a2) {
    case 0x15:
        func_001A93D0_3(self, a1, 0x15);
        break;
    case 0x16:
        ((cFEVObj_001A94E0*)self)->v32();
        *(int*)((char*)self + 0x69C) = 0;
        func_001A93D0_3(self, a1, 0x16);
        break;
    default:
        func_001A93D0_3(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9578);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
struct sFEObj_001B1F88; // defined with func_001B1F88 (its ctor)
extern "C" sFEObj_001B1F88* func_001B1F88(sFEObj_001B1F88* mem, int a1);
extern "C" void* func_001BFBB8(void* mem, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_0025DA90(void* self);
extern void* D_004A3028;
extern int D_004A4E88;
extern const char D_0045FF10[];
extern const char D_0045FF28[];

extern "C" void func_001A9578(void* self, int a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_001A93D0_3(self, a1, a2);
        void* obj;
        if (func_0025DA90(D_004A3028) != 0 && D_004A4E88 == 0) {
            obj = func_001B1F88((sFEObj_001B1F88*)cMemMan_alloc(0x73C, D_0045FF10, 0, 0), *(int*)((char*)self + 0x10));
        } else {
            obj = func_001BFBB8(cMemMan_alloc(0x6D0, D_0045FF28, 0, 0), *(int*)((char*)self + 0x10));
        }
        func_001A8A40(self, obj);
    } else {
        func_001A93D0_3(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9638);
#ifdef SKIP_ASM
extern "C" void func_001A93D0(void* self, int a1, int a2, int a3);

extern "C" void func_001A9638(void* self, int a1, int a2, int a3)
{
    switch (a2) {
    case 0xF:
        break;
    case 0x14:
        break;
    default:
        func_001A93D0(self, a1, a2, a3);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A9668);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001BEE30(void* mem, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_0039F698(void* p);
extern "C" void* cUIStateStack_getCurrentState(void* stack);
extern const char D_00461CD8[];

extern "C" void func_001A9668(void* self, int a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_001A93D0_3(self, a1, a2);
        func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
        *(int*)((char*)self + 0x58) = 1;
        void* st = cUIStateStack_getCurrentState(*(char**)((char*)self + 0x10) + 0x18);
        *(int*)((char*)st + 0x1C) |= 0x80;
        func_001A8A40(self, func_001BEE30(cMemMan_alloc(0x6D4, D_00461CD8, 0, 0), *(int*)((char*)self + 0x10)));
        *(int*)((char*)self + 0x6AC) = 0;
    } else {
        func_001A93D0_3(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A9710);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
// func_001A93D0 really takes (self, a1, a2); the unit declares it with a 4th arg
void func_001A93D0_3(void* self, int a1, int a2) __asm__("func_001A93D0");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B3F78(void* mem, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_0039F698(void* p);
extern "C" void* cUIStateStack_getCurrentState(void* stack);
extern const char D_00460BF0[];

extern "C" void func_001A9710(void* self, int a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_001A93D0_3(self, a1, a2);
        func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
        *(int*)((char*)self + 0x58) = 1;
        void* st = cUIStateStack_getCurrentState(*(char**)((char*)self + 0x10) + 0x18);
        *(int*)((char*)st + 0x1C) |= 0x80;
        func_001A8A40(self, func_001B3F78(cMemMan_alloc(0x91C, D_00460BF0, 0, 0), *(int*)((char*)self + 0x10)));
        *(int*)((char*)self + 0x6AC) = 0;
    } else {
        func_001A93D0_3(self, a1, a2);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A97B8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9890);
#ifdef SKIP_ASM
extern "C" void* cBXString_cBXString4(void* self, const char* str);

extern "C" void func_001A9890(void* self, const char* str)
{
    cBXString_cBXString4((char*)self + 0x6C0, str);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A98B0__FPv);
#ifdef SKIP_ASM
int func_001A98B0(void* self)
{
    return *(int*)((char*)self + 0x6C0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A98B8);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

struct sFEPassword1A98B8 {
    char pad[0x5C];
    char text[0x40];    // 0x5C
};

extern "C" void func_001A98B8(void* self, const char* str)
{
    sFEPassword1A98B8* s = (sFEPassword1A98B8*)self;
    int len = strlen(str);
    int i;
    for (i = 0; i < len && i < 0x3F; i++) {
        s->text[i] = '*';
    }
    if (len == 0) {
        s->text[0] = ' ';
        len = 1;
    }
    s->text[len] = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9930);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" int* func_002591B8();
extern "C" int func_0039F698(void* p);
extern char D_00461618[];
extern char D_00461C40[];
extern char D_00461D28[];

extern "C" void func_001A9930(void* self)
{
    if (*(int*)((char*)self + 0x6AC) == 0) {
        int one = 1;
        *(int*)((char*)self + 0x6AC) = one;
        func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = one;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x170) = one;
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x14C) = 6;
        if (*func_002591B8() == 0) {
            *(int*)((char*)p + 0x150) = 0x83E;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00461C40);
            *(int*)((char*)p + 0xC0) = 3;
        } else {
            *(int*)((char*)p + 0x150) = 0x83D;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00461D28);
            *(int*)((char*)p + 0xC0) = 3;
        }
        func_001A9BC0(self, p);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9A18);
#ifdef SKIP_ASM
class cUIListBox_001A9A18 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_0045DCC8[];
extern char D_0045FCD8[];

extern "C" void func_001A9A18(void* self, cUIListBox_001A9A18* box, int value)
{
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045DCC8), 1);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045FCD8), 0);
    func_0039A7A8(box, value == 0);
    box->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9AB8);
#ifdef SKIP_ASM
class cUIListBox_001A9AB8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_0045E028[];
extern char D_0045DF40[];

extern "C" void func_001A9AB8(void* self, cUIListBox_001A9AB8* box, int value)
{
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045E028), 1);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_0045DF40), 0);
    func_0039A7A8(box, value == 0);
    box->v09(1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001A9B58);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001A3DC8(void* mem, void* engine, void* owner);
extern "C" void func_0039F290(void* list, void* item);
extern const char D_00461D40[];

extern "C" void func_001A9B58(void* self)
{
    void* p = func_001A3DC8(cMemMan_alloc(0x6FC, D_00461D40, 0x100, 0), *(void**)((char*)self + 0x10), self);
    *(int*)((char*)p + 0x18) = 0x833;
    func_0039F290((char*)*(void**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9BC0);
#ifdef SKIP_ASM
extern "C" void* func_0039FAE8(void* list);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_001C5DD8(void* self);

extern "C" void func_001A9BC0(void* self, void* popup)
{
    void* top = func_0039FAE8(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18);
    if (*(int*)((char*)popup + 0x2B8) == 0) {
        if (popup != top) {
            func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, popup);
        }
    } else {
        *(int*)((char*)popup + 0x1C) = (*(int*)((char*)popup + 0x1C) & ~0x3F00) | 0x500;
        func_001C5DD8(*(void**)((char*)self + 0x6A0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001A9C50);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cScreenPopup_cScreenPopup(void* mem, void* engine, void* owner);
extern "C" void func_001C5630(void* self);
extern const char D_00461D58[];

extern "C" void* func_001A9C50(void* self)
{
    void* popup;
    void* cur = *(void**)((char*)self + 0x6A0);
    if (cur == 0) {
        popup = cScreenPopup_cScreenPopup(cMemMan_alloc(0x360, D_00461D58, 0x100, 0), *(void**)((char*)self + 0x10), self);
        *(void**)((char*)self + 0x6A0) = popup;
        *(int*)((char*)popup + 0x178) = 0;
    } else {
        func_001C5630((char*)cur + 0xBC);
        *(int*)((char*)*(void**)((char*)self + 0x6A0) + 0x178) = 0;
    }
    return *(void**)((char*)self + 0x6A0);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001A9CC0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AA9B0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern void* D_004A5B64;
extern char D_00462638[];
extern char D_00462650[];
extern char D_00462668[];

class cFEVObj_001AA9B0 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001AA9B0(void* self)
{
    unsigned int now = *(unsigned int*)((char*)D_004A5B64 + 0x18);
    cFEVObj_001AA9B0* a = (cFEVObj_001AA9B0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462638));
    if (a != 0) {
        if (*(unsigned int*)((char*)self + 0x54) != 0) {
            a->v09((now - *(unsigned int*)((char*)self + 0x54)) % 60 > 30);
        } else {
            a->v09(0);
        }
    }
    cFEVObj_001AA9B0* b = (cFEVObj_001AA9B0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462650));
    a = (cFEVObj_001AA9B0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462668));
    if (a != 0) {
        if (*(unsigned int*)((char*)self + 0x50) != 0) {
            a->v09((now - *(unsigned int*)((char*)self + 0x50)) % 60 > 30);
            if (b != 0) {
                b->v09((now - *(unsigned int*)((char*)self + 0x50)) % 60 > 30);
            }
        } else {
            a->v09(0);
            if (b != 0) {
                b->v09(0);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AAB68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_00262938(void* self);
extern void* D_004A3328;
extern void* D_004A3028;
extern void* D_004A5B64;
extern char D_00462650[];
extern char D_004A12C0[];
extern char D_004A1390[];

struct sSession1AAB68 {
    char pad[0xBC];
    void** mBegin;
    void** mEnd;
};

static inline int Count1AAB68(sSession1AAB68* s) { return s->mEnd - s->mBegin; }

static inline void* GetSession_001AAB68()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

class cFEVObj_001AAB68 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
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
    virtual int v29();
};

struct sSelf1AAB68 {
    char pad[0x4C];
    unsigned int last;
    unsigned int t50;
    unsigned int t54;
};

extern "C" void func_001AAB68(void* self)
{
    char buf[16];
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    if (((cFEVObj_001AAB68*)self)->v29() == 0) {
        return;
    }
    unsigned int now = *(unsigned int*)((char*)D_004A5B64 + 0x18);
    unsigned int d = now - ((sSelf1AAB68*)self)->last;
    if (d > 0 && d < 60) {
        return;
    }
    ((sSelf1AAB68*)self)->last = now;
    int n = func_00262938(GetSession_001AAB68());
    if (((sSelf1AAB68*)self)->t50 != 0) {
        if (n <= 0) {
            ((sSelf1AAB68*)self)->t50 = 0;
        }
    } else {
        if (n > 0) {
            ((sSelf1AAB68*)self)->t50 = now;
        }
    }
    int has = Count1AAB68((sSession1AAB68*)GetSession_001AAB68()) != 0;
    if (((sSelf1AAB68*)self)->t54 != 0) {
        if (!has) {
            ((sSelf1AAB68*)self)->t54 = 0;
        }
    } else {
        if (has) {
            ((sSelf1AAB68*)self)->t54 = now;
        }
    }
    cFEVObj_001AAB68* text = (cFEVObj_001AAB68*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462650));
    if (text == 0) {
        return;
    }
    if (n > 0) {
        text->v09(1);
        sprintf(buf, D_004A12C0, n);
        cUIText_setAsciiString((cUIText*)text, buf);
    } else {
        text->v09(0);
        cUIText_setAsciiString((cUIText*)text, D_004A1390);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AAD50);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_00462678[];

struct sCol1AAD50 {
    float r, g, b, a;
    sCol1AAD50(const float& r_, const float& g_, const float& b_, const float& a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cFEVObj_001AAD50 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol1AAD50& c);
};

extern "C" void func_001AAD50(void* screen, int slot, int ping)
{
    if (screen == 0) {
        return;
    }
    sCol1AAD50 col(1.0f, 0.2199999988079071f, 0.5400000214576721f, 0.10000000149011612f);
    int bars = 5;
    char name[32];
    cFEVObj_001AAD50* objs[5];
    unsigned char i;
    for (i = 0; i < 5; i++) {
        sprintf(name, D_00462678, slot + 1, i + 'a');
        cFEVObj_001AAD50* o = (cFEVObj_001AAD50*)cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
        if (o != 0) {
            objs[i] = o;
        }
    }
    if (ping > 200 && ping < 300) {
        col = sCol1AAD50(1.0f, 0.2199999988079071f, 0.5400000214576721f, 0.10000000149011612f);
        bars = 4;
    } else if (ping > 300 && ping < 400) {
        col = sCol1AAD50(1.0f, 0.949999988079071f, 0.8199999928474426f, 0.20000000298023224f);
        bars = 3;
    } else if (ping > 400 && ping < 500) {
        col = sCol1AAD50(1.0f, 0.949999988079071f, 0.8199999928474426f, 0.20000000298023224f);
        bars = 2;
    } else if (ping > 500) {
        col = sCol1AAD50(1.0f, 0.800000011920929f, 0.1599999964237213f, 0.019999999552965164f);
        bars = 1;
    }
    int j;
    for (j = 0; j < 5; j++) {
        cFEVObj_001AAD50* o = objs[j];
        if (j < bars) {
            o->v09(1);
            o->v11(col);
        } else {
            o->v09(0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AAF90);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern void* D_004A28A8;
extern char D_00462688[];
extern char D_004626A0[];
extern char D_004626B8[];
extern char D_004626D0[];
extern char D_004626E8[];
extern char D_00462700[];
extern char D_00462710[];
extern char D_00462728[];
extern char D_00462740[];

struct cLocStr_001AAF90 {
    int f0;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int v04(int hash);
};

extern "C" int func_001AAF90(void* self, void* msg)
{
    int h;
    switch (*(unsigned int*)((char*)msg + 8)) {
    case 0x2D646966:
        h = GetHashValue32(D_00462688);
        break;
    case 0x2D646576:
        h = GetHashValue32(D_004626A0);
        break;
    case 0x2D636667:
        h = GetHashValue32(D_004626B8);
        break;
    case 0x2D696E69:
        h = GetHashValue32(D_004626D0);
        break;
    case 0x2D746F6E:
        h = GetHashValue32(D_004626E8);
        break;
    case 0x2D627379:
        h = GetHashValue32(D_00462700);
        break;
    case 0x2D636F6E:
        h = GetHashValue32(D_00462710);
        break;
    case 0x2D3F3F3F:
        h = GetHashValue32(D_00462728);
        break;
    case 0x2D617468:
        h = GetHashValue32(D_00462740);
        break;
    case 0x2D646E73:
        h = GetHashValue32(D_00462728);
        break;
    case 0x74696D65:
        h = GetHashValue32(D_00462728);
        break;
    default:
        return 0;
    }
    return (*(cLocStr_001AAF90**)((char*)D_004A28A8 + 0x8C))->v04(h);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AB108);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern char D_00462750[];

extern "C" void func_001AB108(void* self)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 0;
    *(int*)((char*)p + 0x170) = 0;
    *(int*)((char*)p + 0x150) = 0x836;
    *(int*)((char*)p + 0x14C) = 6;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462750);
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x164) = 0;
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AB178);
#ifdef SKIP_ASM
extern char D_00462768[];
extern char D_00462780[];
extern char D_004627A0[];
extern char D_00462158[];
extern char D_004627B8[];
extern char D_004627D8[];
// Shows an error popup with the message matching the error code.
extern "C" void func_001AB178(void* self, int err)
{
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    *(int*)((char*)p + 0xBC) = 1;
    func_001C57C0(sub, 0, GetHashValue32(D_00461618));
    *(int*)((char*)p + 0x150) = 0x835;
    *(int*)((char*)p + 0x14C) = 6;
    *(int*)((char*)p + 0x170) = 0;
    switch (err) {
    case 0xF2:
        *(int*)(sub + 0x8) = GetHashValue32(D_00462768);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0xF1: case 0x10C: case 0x113:
        *(int*)(sub + 0x8) = GetHashValue32(D_00462780);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0x112:
        *(int*)(sub + 0x8) = GetHashValue32(D_004627A0);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0xF0:
        *(int*)(sub + 0x8) = GetHashValue32(D_00462158);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0xED:
        *(int*)(sub + 0x8) = GetHashValue32(D_004627B8);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0xEE:
        *(int*)(sub + 0x8) = GetHashValue32(D_004627D8);
        *(int*)(sub + 0x4) = 3;
        break;
    }
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AB288);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern char D_00461618[];
extern char D_00462780[];
extern char D_004627A0[];
extern char D_004627D8[];
// Shows an error popup with the message matching the error code.
extern "C" void func_001AB288(void* self, int err)
{
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    *(int*)((char*)p + 0xBC) = 1;
    func_001C57C0(sub, 0, GetHashValue32(D_00461618));
    *(int*)((char*)p + 0x150) = 0x837;
    *(int*)((char*)p + 0x14C) = 6;
    *(int*)((char*)p + 0x170) = 0;
    switch (err) {
    case 0xF1: case 0xFA: case 0x10C: case 0x113:
        *(int*)(sub + 0x8) = GetHashValue32(D_00462780);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0x112:
        *(int*)(sub + 0x8) = GetHashValue32(D_004627A0);
        *(int*)(sub + 0x4) = 3;
        break;
    case 0xEE: case 0xF8:
        *(int*)(sub + 0x8) = GetHashValue32(D_004627D8);
        *(int*)(sub + 0x4) = 3;
        break;
    }
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AB370);
#ifdef SKIP_ASM
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001AB478(void* self, void* popup, int a1, int a2, int a3);

extern "C" void func_001AB370(void* self, int a1, int a2)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)self + 0x6C4) = 1;
    func_001AB478(self, p, a1, a2, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AB3D0);
#ifdef SKIP_ASM
extern "C" void func_001AB478(void* self, void* popup, int a1, int a2, int a3);
extern "C" int func_001CA150(void* popup);

extern "C" void func_001AB3D0(void* self, int a1, int a2)
{
    if ((*(int*)((char*)self + 0x1C) & 6) != 0) {
        void* popup = *(void**)((char*)self + 0x6A0);
        if (popup != 0 && *(int*)((char*)self + 0x6C4) != 0) {
            int id = *(int*)((char*)popup + 0x18);
            if (id != 0x80B) {
                if (id != 0x80C) {
                    return;
                }
            }
            if ((*(unsigned char*)((char*)popup + 0x1D) & 0x3F) < 6) {
                func_001AB478(self, *(void**)((char*)self + 0x6A0), a1, a2, func_001CA150(popup));
            }
        }
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AB478);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001ABB30);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_00262A38(void* self, int a1);
extern "C" void* func_001A77A0(void* mem, int a1, void* owner, int a3);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE468(void* self, int v);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_004A1408[];
extern char D_00462AA8[];

struct sFEObj_001ABB30 {
    char pad0[0x10];
    int f10;
    char pad14[0x2C];
    char* f40;
    char pad44[0x658];
    char* f69C;
    char pad6A0[0x24];
    int f6C4;
};

// PORT: passes D_004A1408 through an int parameter.
extern "C" void func_001ABB30(void* p, int a1, void* a2, int a3)
{
    sFEObj_001ABB30* self = (sFEObj_001ABB30*)p;
    self->f6C4 = 0;
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    if (func_00262A38(D_004A3328, a1) != 0) {
        void* obj = func_001A77A0(cMemMan_alloc(0x6FC, D_00462AA8, 0x100, 0), self->f10, self, a1);
        func_0039F290(*(char**)(*(char**)(self->f40 + 0xD0) + 0x10) + 0x18, obj);
    } else {
        func_001A9090(self, 0, a1, (int)D_004A1408, 0, 2, 0x3F);
        *(int*)(self->f69C + 0x43C) = 0;
        func_001CE3C8(self->f69C, 0x4B, 1, 2);
        func_001CE468(self->f69C, 1);
        *(int*)(self->f69C + 0x438) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ABC50);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261EF8(void* self, int a1, int a2, int a3);
extern void* D_004A3328;
extern void* D_004A3028;

struct sFEObj_001ABC50 {
    char pad[0x6C4];
    int f6C4;
};

extern "C" void func_001ABC50(sFEObj_001ABC50* self, int a1, int a2)
{
    self->f6C4 = 0;
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00261EF8(D_004A3328, a1, 1, a2);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001ABCD0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ABE58);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261EF8(void* self, int a1, int a2, int a3);
extern void* D_004A3328;
extern void* D_004A3028;

struct sFEObj_001ABE58 {
    char pad[0x6C4];
    int f6C4;
};

extern "C" void func_001ABE58(sFEObj_001ABE58* self, int a1, int a2)
{
    self->f6C4 = 0;
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00261EF8(D_004A3328, a1, 0, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ABED8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern char D_00461618[];
extern char D_00462B00[];

extern "C" void func_001ABED8(void* self)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 1;
    func_001C57C0((char*)p + 0xBC, 0, GetHashValue32(D_00461618));
    int h = GetHashValue32(D_00462B00);
    //S
    *(int*)((char*)p + 0xC4) = h;
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x150) = 0x845;
    *(int*)((char*)p + 0x14C) = 6;
    //E
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ABF70);
#ifdef SKIP_ASM
extern "C" void* func_001A8500(void* self);
extern void* D_0046B6F8[];

extern "C" void* func_001ABF70(void* self)
{
    func_001A8500(self);
    *(void***)((char*)self + 0x8) = D_0046B6F8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ABFA8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A1A78[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void* func_001ABFA8(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A1A78), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        screen = cUIScreen_playFrame(screen, 0, 0);
    }
    return screen;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC010);
#ifdef SKIP_ASM
extern void* D_00469068[];
extern int D_004A3E90;
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001AC010(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    int d = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_00469068;
    *(int*)((char*)self + 0x6DC) = d;
    *(int*)((char*)self + 0xC) = 0x35;
    *(int*)((char*)self + 0x6D0) = 0;
    *(int*)((char*)self + 0x6E0) = 0;
    *(int*)((char*)self + 0x6A8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC068);
#ifdef SKIP_ASM
extern void* D_00469068[];
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001AC068(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00469068;
    cBXString__cBXString((char*)self + 0x6DC, 2);
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC0B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
void func_001A8768(void* self);
extern char D_00462B20[];
extern char D_004A1408[];
extern void* D_004A3028;

extern "C" void func_001AC0B8(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00462B20), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cBXString_cBXString4((char*)D_004A3028 + 0x48, D_004A1408);
    cBXString_cBXString4((char*)D_004A3028 + 0x4C, D_004A1408);
    func_001A8768(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC150__FPv);
#ifdef SKIP_ASM
void* func_001AC150(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC170);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_00462B38[];
extern char D_00462B48[];
extern char D_00462B58[];
extern char D_00462B70[];
extern char D_00462B88[];
extern char D_00462BA0[];
extern char D_004A1A80[];
extern char D_004A1408[];

struct cFEVObj_001AC170 {
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
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
    virtual void v25(int on);
};

static inline int IsHash_001AC170(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001AC170(void* self, cUIText* text)
{
    if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462B38)) {
        *(int*)((char*)text + 0x18) = 0;
    } else if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462B48)) {
        *(int*)((char*)text + 0x18) = 1;
    } else if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462B58)) {
        *(cUIText**)((char*)self + 0x6E0) = text;
        *(int*)((char*)text + 0x18) = 2;
        (*(cFEVObj_001AC170**)((char*)self + 0x6E0))->v25(1);
        (*(cFEVObj_001AC170**)((char*)self + 0x6E0))->v08(1);
    } else if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462B70)) {
        *(int*)((char*)text + 0x18) = 3;
    } else if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462B88) || IsHash_001AC170(*(int*)((char*)text + 0x38), D_00462BA0)) {
        cUIText_setAsciiString(text, D_004A1408);
    } else if (IsHash_001AC170(*(int*)((char*)text + 0x38), D_004A1A80)) {
        *(int*)((char*)text + 0x18) = 4;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC2B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern void* D_004A3028;
extern char D_00462BB0[];
extern char D_00461618[];

extern "C" int func_001AC2B8(void* self)
{
    if (strlen(*(const char**)((char*)D_004A3028 + 0x4C)) == 0) {
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    *(int*)((char*)p + 0xBC) = 1;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BB0);
    *(int*)((char*)p + 0xC0) = 3;
    func_001C57C0(sub, 0, GetHashValue32(D_00461618));
    *(int*)((char*)p + 0x150) = 0x80D;
    func_001A9BC0(self, p);
    return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC360);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern void* D_004A3028;
extern char D_00462BD0[];
extern char D_00461618[];

extern "C" int func_001AC360(void* self)
{
    if (strlen(*(const char**)((char*)D_004A3028 + 0x48)) == 0) {
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    *(int*)((char*)p + 0xBC) = 1;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BD0);
    *(int*)((char*)p + 0xC0) = 3;
    func_001C57C0(sub, 0, GetHashValue32(D_00461618));
    *(int*)((char*)p + 0x150) = 0x80D;
    func_001A9BC0(self, p);
    return 0;
    }
    return 1;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AC408);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC448);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern char D_00462BF0[];
extern char D_00461618[];

extern "C" int func_001AC448(void* self)
{
    // PORT: string header read through a pointer held in an int
    if (*(int*)(*(int*)((char*)self + 0x6DC) - 8) == 0) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BF0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC4F0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00462C08[];
extern char D_00462C28[];
extern char D_0045FE60[];
extern char D_00462C50[];
extern char D_004614E8[];

extern "C" void func_001AC4F0(void* self, void* popup)
{
    func_001DA528(popup, 3);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00462C08);
    func_001DA530(popup, 0, GetHashValue32(D_00462C28));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 2, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC5A8);
#ifdef SKIP_ASM
extern "C" int func_001AC5A8(void* self, int a1, int a2)
{
    return a2 != 9 ? 0x101 : 0x100;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AC5C0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC920);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001AC9C0(void* self, void* a1, int a2);
extern "C" void func_001ACA88(void* self, void* a1, int a2);
extern "C" void func_001ACB48(void* self, void* a1, int a2);
extern "C" void func_001ACCD0(void* self, void* a1, int a2);

extern "C" void func_001AC920(void* self, void* a1, int a2)
{
    switch (*(unsigned int*)((char*)a1 + 0x18)) {
    case 0x80E:
        func_001ACA88(self, a1, a2);
        break;
    case 0x80F:
        func_001AC9C0(self, a1, a2);
        break;
    case 0x82C:
        func_001ACB48(self, a1, a2);
        break;
    case 0x81E:
        func_001ACCD0(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AC9C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" int func_001AC448(void* self);
extern "C" void func_0025B6D8(void* self, int a1);
extern void* D_004A3028;
extern char D_00462D48[];

extern "C" void func_001AC9C0(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        int three = 3;
        func_001A97B8(self, a1, 0xF);
        cBXString_cBXString4((char*)self + 0x6DC, *(const char**)((char*)a1 + 0x2B0));
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D48);
        *(int*)((char*)p + 0xC0) = three;
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x810;
        func_001A9BC0(self, p);
        if (func_001AC448(self) != 0) {
            *(int*)((char*)self + 0x6D8) = three;
            func_0025B6D8(D_004A3028, 0);
        }
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ACA88);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001ACA88()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001ACA88(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_00261408(GetSession_001ACA88());
        func_0025B800(D_004A3028);
        func_001A97B8(self, a1, a2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ACB48);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001AD130(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern const char D_00462D68[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_00462D80[];

extern "C" void func_001ACB48(void* self, void* a1, int kind)
{
    switch ((unsigned int)kind) {
    case 15:
    case 16:
        *(int*)((char*)self + 0x6D4) = 0;
        func_001A97B8(self, a1, kind);
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    case 17:
        *(int*)((char*)self + 0x6D4) = 1;
        func_001A97B8(self, a1, 17);
        break;
    case 22:
        if (*(int*)((char*)self + 0x6D4) != 0) {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 2;
            char* sub = (char*)p + 0xBC;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0x150) = 0x81E;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
            *(int*)((char*)p + 0xC0) = 3;
            *(int*)((char*)p + 0x168) = 0;
            *(int*)((char*)p + 0x164) = 0;
            func_001A9BC0(self, p);
        }
        *(int*)((char*)self + 0x6D4) = 0;
        func_001A97B8(self, a1, 22);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ACCD0);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void* func_001AD130(void* self, int a1);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern void* D_004A3028;
extern char D_00462D10[];
extern const char D_00462D68[];

extern "C" void func_001ACCD0(void* self, void* a1, int kind)
{
    switch ((unsigned int)kind) {
    case 15: {
        func_001A97B8(self, a1, 15);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 1,
                                *(int*)((char*)D_004A3028 + 0x48), *(int*)((char*)D_004A3028 + 0x4C));
        *(int*)((char*)p + 0x18) = 0x82C;
        func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        break;
    }
    case 16:
    case 20:
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ACDD0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" int strlen(const char* s);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void func_001A98B8(void* self, const char* str);
extern void* D_004A3028;
extern char D_00462B88[];
extern char D_00462BA0[];

struct sVE1ACDD0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void Show1ACDD0(char* o, int on)
{
    sVE1ACDD0* vt = *(sVE1ACDD0**)(o + 0x8);
    vt[8].fn(o + vt[8].delta, on);
}

extern "C" void func_001ACDD0(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    switch (*(int*)(p + 0x18)) {
    case 6: {
        const char* name = p + 0x74;
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462B88));
        if (text != 0) {
            cUIText_setAsciiString(text, name);
        }
        if (strlen(name) != 0) {
            Show1ACDD0(*(char**)((char*)self + 0x6E0), 0);
        } else {
            Show1ACDD0(*(char**)((char*)self + 0x6E0), 1);
        }
        cBXString_cBXString4((char*)D_004A3028 + 0x48, name);
        break;
    }
    case 7: {
        const char* name = p + 0x74;
        if (cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462BA0)) != 0) {
            func_001A98B8(self, name);
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6A4), (char*)self + 0x5C);
        }
        cBXString_cBXString4((char*)D_004A3028 + 0x4C, name);
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ACEF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025C1E0(void* self, int a1);
extern "C" void func_0025C3F8(void* self, int a1);
extern "C" void func_0025C610(void* self);
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
extern void* D_004A3028;
extern char D_00462D98[];
extern char D_00462DB0[];
extern char D_00462D80[];
extern char D_00461618[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

extern "C" int func_001ACEF8(void* self, int id, int a2)
{
    switch (id) {
    case 0xC9:
        switch (*(int*)((char*)self + 0x6D8)) {
        case 2:
            func_0025C3F8(D_004A3028, *(int*)((char*)D_004A3028 + 0x48));
            break;
        case 3:
            func_0025C1E0(D_004A3028, *(int*)((char*)self + 0x6DC));
            break;
        case 4:
            func_0025C610(D_004A3028);
            break;
        }
        break;
    case 0xCF: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D98);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x811;
        func_001A9BC0(self, p);
        break;
    }
    case 0xD2: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462DB0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x813;
        func_001A9BC0(self, p);
        break;
    }
    case 0xD4: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 2;
        char* sub = (char*)p + 0xBC;
        func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
        func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
        *(int*)((char*)p + 0x150) = 0x81E;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x168) = 0;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        break;
    }
    default:
        return func_001A8E40_3i(self, id, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD130);
#ifdef SKIP_ASM
extern void* D_00468F50[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001AD130(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x38;
    *(void***)((char*)self + 0x8) = D_00468F50;
    *(int*)((char*)self + 0x6D0) = 0;
    return self;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001AD178);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void func_001A8768(void* self);
extern char D_00462DC8[];

extern "C" void func_001AD178(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00462DC8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001A8768(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD1E8__FPv);
#ifdef SKIP_ASM
void* func_001AD1E8(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD208);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025D1B8(void* self, const char* str);
extern void* D_004A3028;
extern char D_004615F8[];
extern char D_00461618[];
extern char D_00462DE0[];

extern "C" void func_001AD208(void* self, const char* name)
{
    if (strlen(name) < 3) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004615F8);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x814;
        func_001A9BC0(self, p);
    } else {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462DE0);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x815;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        func_0025D1B8(D_004A3028, name);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD308);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void func_001AD3E8(void* self, cUIText* text);
extern void* D_004A3028;
extern char D_00462E00[];
extern char D_00462E10[];
extern char D_00462E20[];
extern char D_00462E30[];
extern char D_00462E40[];

static inline int IsHash1AD308(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001AD308(void* self, cUIText* text)
{
    void* g = D_004A3028;
    if (IsHash1AD308(*(int*)((char*)text + 0x38), D_00462E00)) {
        func_001AD3E8(self, text);
    } else if (IsHash1AD308(*(int*)((char*)text + 0x38), D_00462E10)) {
        *(int*)((char*)text + 0x18) = -1;
    } else if (IsHash1AD308(*(int*)((char*)text + 0x38), D_00462E20)) {
        cUIText_setAsciiString(text, *(const char**)((char*)g + 0x48));
    } else if (IsHash1AD308(*(int*)((char*)text + 0x38), D_00462E30)) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00462E40));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD3E8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" cUIText* func_00397870(void* list, int i);
extern void* D_004A3028;
extern char D_00462E58[];

class cFEVObj_001AD3E8 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

struct sFEGlobals1AD3E8 {
    char pad[0x6C];
    int count;
    const char* names[4];
};

extern "C" void func_001AD3E8(void* self, cUIText* text)
{
    sFEGlobals1AD3E8* g = (sFEGlobals1AD3E8*)D_004A3028;
    int i = 0;
    for (; i < g->count; i++) {
        cUIText* item = func_00397870((char*)text + 0x74, i);
        *(int*)((char*)item + 0x18) = i;
        cUIText_setAsciiString(item, g->names[i]);
        ((cFEVObj_001AD3E8*)item)->v09(1);
    }
    for (; i < 4; i++) {
        cUIText* item = func_00397870((char*)text + 0x74, i);
        *(int*)((char*)item + 0x18) = i;
        cUIText_setUnicodeStringByID(item, GetHashValue32(D_00462E58));
        ((cFEVObj_001AD3E8*)item)->v09(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD4F0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00462E70[];
extern char D_00462E88[];
extern char D_00462EA0[];
extern char D_0045FE60[];
extern char D_00462EB8[];
extern char D_00462C50[];
extern char D_004614E8[];

extern "C" void func_001AD4F0(void* self, void* menu)
{
    func_001DA528(menu, 4);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00462E70);
    func_001DA530(menu, 0, GetHashValue32(D_00462E88));
    func_001DA530(menu, 1, GetHashValue32(D_00462EA0));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_00462EB8), 2);
    func_001DA510(menu, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(menu, 3, GetHashValue32(D_004614E8), 1);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AD5E8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD8C0);
#ifdef SKIP_ASM
class cFEVObj_001AD8C0 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v33(void* a1, int a2);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001AD930(void* self, void* a1, int a2);

extern "C" void func_001AD8C0(cFEVObj_001AD8C0* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x816:
        self->v33(a1, a2);
        break;
    case 0x819:
        func_001AD930(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD930);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00462D10[];

extern "C" void func_001AD930(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8(self, a1, 0xF);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
        *(int*)((char*)p + 0x18) = 0x832;
        func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AD9C8);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" void func_0025D428(void* self, void* a1);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001AD9C8(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_0025D428(D_004A3028, *(void**)((char*)self + 0x6D4));
        func_001A97B8(self, a1, 0xF);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ADA30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void* func_001BFBB8(void* mem, int a1);
extern "C" void func_0039F190(void* self, int a1);
extern "C" void func_001ADC30(void* self, int a2);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern void* D_004A3328;
extern void* D_004A3028;
extern const char D_0045FF28[];
extern char D_00461618[];
extern char D_00462E00[];
extern char D_00462F58[];
extern char D_00462F78[];

struct sVE1ADA30 {
    short delta;
    short index;
    void (*fn)(void*, cUIText*);
};

// Message handler for the network-settings screen; returns -1 when handled.
extern "C" int func_001ADA30(void* self, int a1, int a2)
{
    switch (a1) {
    case 0xD9: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462F58);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x817;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        break;
    }
    case 0x104: {
        if (D_004A3328 == 0) {
            func_00260F80();
        }
        if (func_00261460(D_004A3328) == 0) {
            func_002613C8(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800(D_004A3028);
        }
        func_00261408(D_004A3328);
        func_0025B800(D_004A3028);
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462F78);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x819;
        func_001A9BC0(self, p);
    }
    case 0xD6:
        func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
    case 0xD8:
        {
            sVE1ADA30* vt = *(sVE1ADA30**)((char*)self + 8);
            vt[18].fn((char*)self + vt[18].delta, cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462E00)));
        }
        break;
    case 0x102:
        func_001ADC30(self, a2);
        break;
    case 0x111:
        func_001A8A40(self, func_001BFBB8(cMemMan_alloc(0x6D0, D_0045FF28, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        return (int)func_001A8E40_3(self, a1, a2);
    case 0xE1:
        break;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ADC30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001BBD08(void* self, int a1, int a2);
void func_001C57C0(void* self, int a1, int a2);
// PORT: unit declares func_001A8E40 with one arg; the real handler takes (self, id, msg)
extern "C" void* func_001A8E40_1ADC30(void* self, int id, void* msg) __asm__("func_001A8E40");
extern char D_004615F8[];
extern char D_00461618[];
extern char D_004620C8[];
extern char D_00463090[];
extern char D_004630A8[];

// PORT: the message pointer arrives as int
extern "C" void func_001ADC30(void* self, int a2)
{
    void* msg = (void*)a2;
    switch (*(unsigned int*)((char*)msg + 8)) {
    case 0x6475706C:
        func_001A8A40(self, func_001BBD08(cMemMan_alloc(0x6E0, D_00463090, 0, 0), *(int*)((char*)self + 0x10), 0));
        break;
    case 0x696E616D:
        {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_004615F8);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0x150) = 0x818;
            func_001A9BC0(self, p);
        }
        break;
    case 0x66696C74:
        {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            if (*(int*)((char*)self + 0x6D0) == 0) {
                *(int*)((char*)p + 0xC4) = GetHashValue32(D_004630A8);
                *(int*)((char*)p + 0xC0) = 3;
                *(int*)((char*)p + 0x150) = 0x818;
            } else {
                *(int*)((char*)p + 0xC4) = GetHashValue32(D_004620C8);
                *(int*)((char*)p + 0xC0) = 3;
                *(int*)((char*)p + 0x150) = 0x83D;
            }
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            func_001A9BC0(self, p);
        }
        break;
    default:
        func_001A8E40_1ADC30(self, *(int*)msg, msg);
        break;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001ADDD0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ADE88);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewRaceInterface_setNumberAI(void* iface, int n);
extern "C" void func_001AF728(void* self, void* iface, void* screen);
extern "C" void func_001AF688(void* self);
extern "C" void func_001AF930(void* screen);
extern "C" void func_0025E6D0(void* self, const char* str);
extern "C" void func_001A9930(void* self);
extern void* D_004A3028;
extern int D_004A4E8C;
extern char D_004630C8[];
extern char D_004630E0[];

struct sVE1ADE88 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE1ADE88i {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_001ADE88(void* self)
{
    sVE1ADE88* vt = *(sVE1ADE88**)((char*)self + 0x8);
    vt[32].fn((char*)self + vt[32].delta);
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004630C8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
        cBENewRaceInterface_setNumberAI(iface, D_004A4E8C);
        sVE1ADE88i* ivt = *(sVE1ADE88i**)(iface + 0xC);
        ivt[1].fn(iface + ivt[1].delta);
        func_001AF728(self, iface, *(void**)((char*)self + 0x40));
        func_001AF688(self);
        func_0025E6D0(D_004A3028, *(const char**)((char*)D_004A3028 + 0x98));
        func_001AF930(*(void**)((char*)self + 0x40));
        if (*(int*)((char*)self + 0x6D4) == 0) {
            cUIMenu_setSelectedByIndex(cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004630E0)), 6);
        } else {
            *(int*)((char*)self + 0x6D4) = 0;
        }
    }
    if (*(int*)D_004A3028 == 0) {
        func_001A9930(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ADFB8);
#ifdef SKIP_ASM
class func_001ADFB8_cObj {
public:
    char pad[0x8];
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
};

extern "C" int func_001ADFB8(func_001ADFB8_cObj* self)
{
    self->v32();
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001ADFE8);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001A87D0(void* self, int a1);
extern "C" void func_0039A7A8(void* self, int a1);
extern "C" void func_001AF098(void* self, int a1);
extern "C" void func_001AEC60(void* self, int a1);
extern void* D_004A28A8;
extern int D_00534B30_1ADFE8[] __asm__("D_00534B30");
extern signed char D_00535C12[];
extern char D_00441268[];
extern char D_00441278[];
extern char D_00441288[];
extern char D_00441298[];
extern char D_004412A8[];
extern char D_004412B8[];

// Refreshes the race-options screen and picks the mode title for the current game mode.
extern "C" void func_001ADFE8(void* self, int a1)
{
    func_001A87D0(self, a1);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    func_0039A7A8(*(void**)((char*)self + 0x6DC), D_00534B30_1ADFE8[1] ^ 1);
    cBE_getInterface_Fv(cBE_getBE(), 0);
    switch (D_00535C12[0]) {
    case 3:
        *(char**)((char*)self + 0x6D8) = D_00441288;
        break;
    case 1:
        *(char**)((char*)self + 0x6D8) = D_00441278;
        break;
    case 2:
        *(char**)((char*)self + 0x6D8) = D_00441298;
        break;
    case 5:
        *(char**)((char*)self + 0x6D8) = D_004412A8;
        break;
    case 4:
        *(char**)((char*)self + 0x6D8) = D_004412B8;
        break;
    case 0:
    default:
        *(char**)((char*)self + 0x6D8) = D_00441268;
        break;
    }
    func_001AF098(self, D_00534B30_1ADFE8[1]);
    func_001AEC60(self, *(int*)((char*)self + 0x6D0));
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AE0E0__FPv);
#ifdef SKIP_ASM
void* func_001AE0E0(void* self)
{
    return func_001A8770(self);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AE100);

INCLUDE_ASM("fe/feasyncfile", func_001AE128);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AE680);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewRaceInterface_setNumberAI(void* iface, int n);
extern "C" int func_0039A738(void* a);
extern void* D_004A28A8;
// D_00534B34 is a splat label inside D_00534B30
extern int D_00534B34[];
extern char D_005308B8[];

struct sVE1AE680 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sVE1AE680i {
    short delta;
    short index;
    int (*fn)(void*);
};

struct sOpts1AE680 {
    char pad[0x18];
    unsigned int f0 : 6;
    unsigned int b6 : 1;
    unsigned int b7 : 1;
    unsigned int b8 : 1;
};

extern "C" void func_001AE680(void* self)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        char* iface = (char*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        D_00534B34[0] = func_0039A738(*(void**)((char*)self + 0x6DC)) != 0;
        sVE1AE680* vt = *(sVE1AE680**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        int v = func_0039A738(*(void**)((char*)self + 0x6E8));
        sOpts1AE680* o = (sOpts1AE680*)D_005308B8;
        o->b6 = v;
        o->b8 = func_0039A738(*(void**)((char*)self + 0x6E4));
        o->b7 = func_0039A738(*(void**)((char*)self + 0x6EC));
        char* nr = (char*)cBE_getInterface_Fv(cBE_getBE(), 0);
        cBENewRaceInterface_setNumberAI(nr, func_0039A738(*(void**)((char*)self + 0x6E0)));
        sVE1AE680i* nvt = *(sVE1AE680i**)(nr + 0xC);
        nvt[1].fn(nr + nvt[1].delta);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AE7A0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AEBF0);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001AEBF0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 7, *(int*)((char*)D_004A3028 + 0x98), 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AEC60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A28A8;
extern int D_00534B34[];
extern char D_004632A8[];
extern char D_004632B8[];
extern char D_004632D0[];
extern char D_004632E0[];
extern char D_004632F0[];
extern char D_00463130[];

class cFEVObj_001AEC60 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

struct sVE_001AEC60 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_001AEC60(void* self, int on)
{
    char* s = (char*)self;
    if (*(void**)(s + 0x40) == 0) {
        return;
    }
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    int locked = D_00534B34[0];
    cFEVObj_001AEC60* o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004632A8));
    if (o != 0) {
        o->v08(on);
    }
    o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004632B8));
    if (o != 0) {
        (*(cFEVObj_001AEC60**)(s + 0x6E0))->v08(on);
        o->v08(on);
        if (on == 0) {
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)o + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)o + vt[8].delta, (*(int**)(s + 0x6D8))[0] == 0 || locked != 0);
        }
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E0)) + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E0)) + vt[8].delta, (*(int**)(s + 0x6D8))[0] == 0 || locked != 0);
        }
        }
    }
    o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004632D0));
    if (o != 0) {
        o->v08(on);
        (*(cFEVObj_001AEC60**)(s + 0x6E4))->v08(on);
        if (on == 0) {
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E4)) + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E4)) + vt[8].delta, (*(int**)(s + 0x6D8))[1] == 0 || locked != 0);
        }
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)o + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)o + vt[8].delta, (*(int**)(s + 0x6D8))[1] == 0 || locked != 0);
        }
        }
    }
    o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004632E0));
    if (o != 0) {
        o->v08(on);
        (*(cFEVObj_001AEC60**)(s + 0x6E8))->v08(on);
        if (on == 0) {
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E8)) + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)(*(cFEVObj_001AEC60**)(s + 0x6E8)) + vt[8].delta, (*(int**)(s + 0x6D8))[3] == 0 || locked != 0);
        }
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)o + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)o + vt[8].delta, (*(int**)(s + 0x6D8))[3] == 0 || locked != 0);
        }
        }
    }
    o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004632F0));
    if (o != 0) {
        o->v08(on);
        (*(cFEVObj_001AEC60**)(s + 0x6EC))->v08(on);
        if (on == 0) {
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)(*(cFEVObj_001AEC60**)(s + 0x6EC)) + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)(*(cFEVObj_001AEC60**)(s + 0x6EC)) + vt[8].delta, (*(int**)(s + 0x6D8))[2] == 0 || locked != 0);
        }
            {
            sVE_001AEC60* vt = *(sVE_001AEC60**)((char*)o + 8);
            void (**pf)(void*, int) = &vt[8].fn;
            (*pf)((char*)o + vt[8].delta, (*(int**)(s + 0x6D8))[2] == 0 || locked != 0);
        }
        }
    }
    o = (cFEVObj_001AEC60*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00463130));
    if (o != 0) {
        o->v08(on);
    }
    (*(cFEVObj_001AEC60**)(s + 0x6DC))->v08(on);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AF098);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF208);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern char D_004631F8[];
extern char D_00463210[];
extern char D_00463238[];
extern char D_00463248[];
extern char D_00463260[];
extern char D_00463300[];
extern char D_00463310[];
extern char D_00463320[];
extern char D_00463330[];
extern char D_00463340[];
extern char D_00463350[];
extern char D_00463360[];
extern char D_00463370[];
extern char D_00463380[];
extern char D_00463390[];

class cFEVObj_001AF208 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline int IsHash1AF208(int id, char* name) { return id == GetHashValue32(name); }

static inline cFEVObj_001AF208* Get1AF208(void* self, char* name)
{
    return (cFEVObj_001AF208*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_001AF208(void* self, cUIText* item, int on)
{
    if (item == 0) {
        return;
    }
    cFEVObj_001AF208* a = 0;
    cFEVObj_001AF208* b = 0;
    if (IsHash1AF208(*(int*)((char*)item + 0x38), D_004631F8)) {
        a = Get1AF208(self, D_00463300);
        b = Get1AF208(self, D_00463310);
    } else if (IsHash1AF208(*(int*)((char*)item + 0x38), D_00463210)) {
        a = Get1AF208(self, D_00463320);
        b = Get1AF208(self, D_00463330);
    } else if (IsHash1AF208(*(int*)((char*)item + 0x38), D_00463238)) {
        a = Get1AF208(self, D_00463340);
        b = Get1AF208(self, D_00463350);
    } else if (IsHash1AF208(*(int*)((char*)item + 0x38), D_00463248)) {
        a = Get1AF208(self, D_00463360);
        b = Get1AF208(self, D_00463370);
    } else if (IsHash1AF208(*(int*)((char*)item + 0x38), D_00463260)) {
        a = Get1AF208(self, D_00463380);
        b = Get1AF208(self, D_00463390);
    }
    if (a != 0) {
        a->v09(on);
    }
    if (b != 0) {
        b->v09(on);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF3E0);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int func_0039F698(void* p);

extern "C" int func_001AF3E0(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        return func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
    }
    return func_001A97B8(self, a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF428);
#ifdef SKIP_ASM
class cFEVObj_001AF428 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v33(void* a1, int a2);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001AF428(cFEVObj_001AF428* self, void* a1, int a2)
{
    if (*(int*)((char*)a1 + 0x18) == 0x835) {
        self->v33(a1, a2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF470);
#ifdef SKIP_ASM
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001AF688(void* self);
extern "C" void func_001AB178(void* self, int err);
extern "C" void func_001AB108(void* self);
extern "C" void func_001AFA60(void* screen, char* msg);
extern "C" void func_001AFD88(void* self, void* a1);
extern const char D_00461C60[];

// Message handler: opens the next screen, shows error popups, or forwards to the base handler.
extern "C" void* func_001AF470(void* self, int a1, int a2)
{
    switch (a1) {
    case 0xF3:
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0xED: case 0xEE: case 0xF0: case 0xF1: case 0xF2: case 0x10C: case 0x112: case 0x113:
        func_001AF688(self);
        func_001AB178(self, a1);
        break;
    case 0x110:
        func_001AB108(self);
        break;
    case 0xE3:
        func_001AFA60(*(void**)((char*)self + 0x40), (char*)a2);
        break;
    case 0xE5:
        func_001AFD88(*(void**)((char*)self + 0x40), (void*)a2);
        break;
    default:
        return func_001A8E40_3(self, a1, a2);
    case 0xEF:
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF568);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void func_001AEC60(void* self, int a1);
extern "C" void func_002C26D0(void* str, int a1, char* buf);
extern "C" void func_003A0E90(cUIText* text, char* str);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_00463468[];
extern char D_00463480[];
extern char D_004631C8[];
extern char D_004630E0[];

struct sVE_001AF568 {
    short delta;
    short index;
    int (*fn)(void* self, int hash);
};

struct sVE_001AF568b {
    short delta;
    short index;
    void (*fn)(void* self, int on);
};

extern "C" void func_001AF568(void* self)
{
    char buf[0x400];
    *(int*)((char*)self + 0x6D0) = 1;
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463468));
    if (text != 0) {
        char* name = *(char**)((char*)D_004A3028 + 0x98);
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_001AF568* vt = *(sVE_001AF568**)(o + 4);
        char* obj = o + vt[4].delta;
        func_002C26D0(buf, vt[4].fn(obj, GetHashValue32(D_00463480)), name);
        func_003A0E90(text, buf);
        char* o2 = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004631C8));
        sVE_001AF568b* vt2 = *(sVE_001AF568b**)(o2 + 8);
        vt2[8].fn(o2 + vt2[8].delta, 1);
        cUIMenu_setSelectedByIndex(cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004630E0)), 7);
        func_001AEC60(self, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF688);
#ifdef SKIP_ASM
class cUIObj_001AF688 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int a1);
};

int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void func_001AEC60(void* self, int a1);
extern char D_00463468[];
extern char D_00463498[];
extern char D_004631C8[];

extern "C" void func_001AF688(void* self)
{
    *(int*)((char*)self + 0x6D0) = 0;
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463468));
    if (text != 0) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00463498));
        ((cUIObj_001AF688*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004631C8)))->v08(0);
        func_001AEC60(self, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF728);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewRaceInterface_setNumberAI(void* iface, int n);
extern "C" int func_00144C98(void* track);
extern "C" const char* func_00145340(void* track);
extern "C" const char* func_00144BF0(void* track);
extern "C" void func_0039A7A8(void* self, int a1);
extern signed char D_00535C12[];
extern char D_004634B8[];
extern char D_004634C8[];
extern char D_004634D8[];
extern char D_004A1390[];
extern char D_004A14F8[];
extern char D_004A1500[];
extern char D_004A1508[];

class cRaceIface_001AF728 {
public:
    int f0;
    int f4;
    int f8;
    // vptr at 0xC
    virtual int v01();
};

class cFEVObj_001AF728 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

extern "C" void func_001AF728(void* self, void* track, void* screen)
{
    if (screen == 0) {
        return;
    }
    cUIText* t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004634B8));
    if (track == 0) {
        cUIText_setAsciiString(t, D_004A1390);
    } else {
        switch (func_00144C98(track)) {
        case 0:
            cUIText_setAsciiString(t, D_004A14F8);
            break;
        case 1:
            cUIText_setAsciiString(t, D_004A1500);
            break;
        case 2:
            cUIText_setAsciiString(t, D_004A1508);
            break;
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004634C8));
    if (track == 0) {
        cUIText_setAsciiString(t, D_004A1390);
    } else {
        if (D_00535C12[0] != 0) {
            cRaceIface_001AF728* iface = (cRaceIface_001AF728*)cBE_getInterface_Fv(cBE_getBE(), 0);
            cBENewRaceInterface_setNumberAI(iface, 0);
            iface->v01();
            func_0039A7A8(*(void**)((char*)self + 0x6E0), 0);
            (*(cFEVObj_001AF728**)((char*)self + 0x6E0))->v08(1);
        }
        cUIText_setAsciiString(t, func_00145340(track));
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004634D8));
    if (track == 0) {
        cUIText_setAsciiString(t, D_004A1390);
    } else {
        cUIText_setAsciiString(t, func_00144BF0(track));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AF930);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_004A1390[];
extern char D_00463108[];
extern char D_004634E8[];
extern char D_004634F8[];
extern char D_00463508[];
extern char D_00463520[];
extern char D_00463538[];

static inline void Clear1AF930(void* screen, char* name)
{
    cUIText* t = cUIScreen_getObjectByHashName(screen, GetHashValue32(name));
    if (t != 0) {
        cUIText_setAsciiString(t, D_004A1390);
    }
}

extern "C" void func_001AF930(void* screen)
{
    if (screen != 0) {
        Clear1AF930(screen, D_00463108);
        Clear1AF930(screen, D_004634E8);
        Clear1AF930(screen, D_004634F8);
        Clear1AF930(screen, D_00463508);
        Clear1AF930(screen, D_00463520);
        Clear1AF930(screen, D_00463538);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AFA60);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void cBXString__cBXString(void* self, int flags);
// PORT: func_002C2718 is a varargs formatter (buf, fmt, ...); the unit declares a 3-arg view
extern "C" void func_002C2718_1AFA60(char* buf, const char* fmt, ...) __asm__("func_002C2718");
extern "C" void func_003A0E90(cUIText* text, char* str);
// PORT: SN soft-float float->double helper called by name
extern "C" double func_00413AF8(float f);
extern "C" void func_0025DD08(void* self, const char* str, int a2);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_00463108[];
extern char D_004634E8[];
extern char D_004634F8[];
extern char D_00463508[];
extern char D_00463520[];
extern char D_00463550[];
extern char D_00463568[];
extern char D_00463580[];
extern char D_00463590[];
extern char D_004635A8[];
extern char D_004A1A88[];

struct sVEntry_001AFA60 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1AFA60(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001AFA60* vt = *(sVEntry_001AFA60**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

struct sBXString1AFA60 {
    char* str;
    sBXString1AFA60() {}
    sBXString1AFA60(const sBXString1AFA60& o);
};

struct sStats1AFA60 {
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" void func_001AFA60(void* screen, char* msg)
{
    sBXString1AFA60 s;
    char buf[0x100];
    sStats1AFA60* st = (sStats1AFA60*)(msg + 0x18);
    cBXString_cBXString1(&s, (char*)D_004A3028 + 0x98);
    *(sStats1AFA60*)((char*)D_004A3028 + 0xCC) = *(sStats1AFA60*)(msg + 0x18);
    func_0025DD08(D_004A3028, s.str, *(int*)(msg + 0x14));
    cUIText* t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463108));
    if (t != 0) {
        cUIText_setAsciiString(t, s.str);
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004634E8));
    if (t != 0) {
        int name = Loc1AFA60(D_00463550);
        func_002C2718_1AFA60(buf, D_004A1A88, name, *(int*)(msg + 0x18));
        func_003A0E90(t, buf);
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004634F8));
    if (t != 0) {
        int name = Loc1AFA60(D_00463568);
        func_002C2718_1AFA60(buf, D_004A1A88, name, *(int*)(msg + 0x20));
        func_003A0E90(t, buf);
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463508));
    if (t != 0) {
        int b = *(int*)(msg + 0x20);
        int a = *(int*)(msg + 0x1C);
        float pct = 0.0f;
        if (a < b) {
            pct = (float)a / (float)b * 100.0f;
        } else if (a != 0) {
            pct = 100.0f;
        }
        int name = Loc1AFA60(D_00463580);
        func_002C2718_1AFA60(buf, D_00463590, name, st->b, st->c, func_00413AF8(pct));
        func_003A0E90(t, buf);
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463520));
    if (t != 0) {
        int name = Loc1AFA60(D_004635A8);
        func_002C2718_1AFA60(buf, D_004A1A88, name, st->d);
        func_003A0E90(t, buf);
    }
    cBXString__cBXString(&s, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001AFD88);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void func_001AAD50(void* self, int a1, int a2);
extern char D_00463538[];
extern char D_004635C0[];

extern "C" void func_001AFD88(void* self, void* a1)
{
    cUIText* text = cUIScreen_getObjectByHashName(self, GetHashValue32(D_00463538));
    if (text != 0) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_004635C0));
        func_001AAD50(self, 0, *(int*)((char*)a1 + 0xC));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001AFE08);
#ifdef SKIP_ASM
extern void* D_00468D20[];
extern int D_004A4E88;
extern "C" void* cBXString_cBXString2(void* self, const char* str);
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001AFE08(void* self, int a1, int a2, const char* name)
{
    func_001A8500_3(self, a1, a2);
    *(void***)((char*)self + 0x8) = D_00468D20;
    cBXString_cBXString2((char*)self + 0x6D0, name);
    *(int*)((char*)self + 0x6D4) = 0;
    *(int*)((char*)self + 0xC) = 0x40;
    D_004A4E88 = 0;
    return self;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001AFE68);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B00B8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001B00B8(void* self)
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 8, *(int*)((char*)self + 0x6D0), 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0130__FPv);
#ifdef SKIP_ASM
void* func_001B0130(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0150);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern void* D_004A3028;
extern int D_00535C04[];
extern int D_005308D0[];
extern char D_004A12C0[];
extern char D_004A1A90[];
extern char D_00461520[];
extern char D_004635F8[];
extern char D_00463608[];
extern char D_00463618[];
extern char D_00463108[];
extern char D_00463118[];
extern char D_00463140[];
extern char D_00463150[];
extern char D_00463168[];
extern char D_00463178[];
extern char D_00463190[];
extern char D_004631A0[];
extern char D_004631B8[];
extern char D_00463628[];
extern char D_00463640[];
extern char D_00463228[];
extern char D_00463658[];
extern char D_00463670[];
extern char D_00463688[];
extern char D_004636A0[];
extern char D_004636B0[];
extern char D_004630E0[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

class cFEVObj_001B0150 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline int IsHash_001B0150(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B0150(void* self, cFEVObj_001B0150* obj)
{
    char buf[16];
    char* o = (char*)obj;
    cUIText* t = (cUIText*)obj;
    if (IsHash_001B0150(*(int*)(o + 0x38), D_00461520)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_004635F8)) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00463608));
        *(int*)(o + 0x18) = 0xB;
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463618)) {
        *(int*)(o + 0x18) = 0xC;
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463108)) {
        cUIText_setAsciiString(t, *(const char**)((char*)D_004A3028 + 0x98));
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463118)) {
        *(int*)(o + 0x18) = 7;
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463140)) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00463150));
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463168)) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_00463178));
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463190)) {
        cUIText_setUnicodeStringByID(t, GetHashValue32(D_004631A0));
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_004631B8)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463628)) {
        cUIText_setAsciiString(t, D_004A1A90);
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463640)) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        int n = D_00535C04[0];
        if (n == 0) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_00463228));
        } else {
            sprintf(buf, D_004A12C0, n);
            cUIText_setAsciiString(t, buf);
        }
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463658)) {
        if ((D_005308D0[0] >> 8) & 1) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
        } else {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
        }
        cUIText_setAsciiString(t, D_004A1A90);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463670)) {
        if ((D_005308D0[0] >> 6) & 1) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
        } else {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
        }
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463688)) {
        int f = D_005308D0[0] >> 7;
        if (f & 1) {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
        } else {
            cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
        }
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_004636A0)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_004636B0)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463628)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_00463640)) {
        obj->v09(1);
    } else if (IsHash_001B0150(*(int*)(o + 0x38), D_004630E0)) {
        *(int*)(o + 0x14) |= 0x80;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0538);
#ifdef SKIP_ASM
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001B0C08(void* self);
extern "C" void func_001B0E10(void* self);
extern "C" void func_0025FB58(void* self, int a1, int a2);
extern void* D_004A3028;

extern "C" void func_001B0538(void* self, void* obj, int msg)
{
    if (obj == 0) {
        return;
    }
    switch (msg) {
    case 5:
        switch (*(int*)((char*)obj + 0x18)) {
        case 0xB:
            if (*(int*)((char*)self + 0x6D4) == 0) {
                func_001B0C08(self);
                func_0025FB58(D_004A3028, *(int*)((char*)D_004A3028 + 0x98), *(signed char*)((char*)self + 0x14));
            }
            break;
        case 0xC:
            func_001B0E10(self);
            break;
        }
        break;
    case 7:
        break;
    default:
        // PORT: the unit declares func_001A8918 with an int a1; obj is passed through as int
        func_001A8918(self, (int)obj, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B05E0);
#ifdef SKIP_ASM
class cFEVObj_001B05E0 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v33(void* a1, int a2);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001B05E0(cFEVObj_001B05E0* self, void* a1, int a2)
{
    if (*(int*)((char*)a1 + 0x18) == 0x835) {
        self->v33(a1, a2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0628);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int func_0039F698(void* p);

extern "C" int func_001B0628(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        return func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
    }
    return func_001A97B8(self, a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0670);
#ifdef SKIP_ASM
class cFEVObj_001B0670 {
public:
    int field_0x0;
    int field_0x4;
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
};

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001B0850(void* self, void* iface, void* screen);

extern "C" int func_001B0670(cFEVObj_001B0670* self, int a1)
{
    self->v32();
    if (a1 != 0) {
        func_001B0850(self, cBE_getInterface_Fv(cBE_getBE(), 0), *(void**)((char*)self + 0x40));
    }
    return 1;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B06E0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0708);
#ifdef SKIP_ASM
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001B0C08(void* self);
extern "C" void func_001AB178(void* self, int err);
extern "C" void func_001AB108(void* self);
extern "C" void func_001AFA60(void* screen, char* msg);
extern "C" void func_001AFD88(void* self, void* a1);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00263018(void* self, void* a1);
extern void* D_004A3328;
extern void* D_004A3028;
extern const char D_00461C60[];

// Message handler: starts the memory-card task, shows error popups, or forwards to the base handler.
extern "C" void* func_001B0708(void* self, int a1, int a2)
{
    switch (a1) {
    case 0xEF:
        if (D_004A3328 == 0) {
            func_00260F80();
        }
        if (func_00261460(D_004A3328) == 0) {
            func_002613C8(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800(D_004A3028);
        }
        func_00263018(D_004A3328, *(void**)((char*)self + 0x6D0));
        break;
    case 0x110:
        func_001AB108(self);
        break;
    case 0xED: case 0xEE: case 0xF0: case 0xF1: case 0x10C: case 0x112: case 0x113:
        func_001B0C08(self);
        func_001AB178(self, a1);
        break;
    case 0xF3:
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0xE3:
        func_001AFA60(*(void**)((char*)self + 0x40), (char*)a2);
        break;
    case 0xE5:
        func_001AFD88(*(void**)((char*)self + 0x40), (void*)a2);
        break;
    default:
        return func_001A8E40_3(self, a1, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0850);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" const char* func_00145340(void* track);
extern "C" const char* func_00144BF0(void* track);
extern void* D_004A28A8;
extern int D_00534B34[];
extern int D_005308D0[];
extern int D_00535C04[];
extern char D_004A1390[];
extern char D_004A12C0[];
extern char D_004636A0[];
extern char D_004636B0[];
extern char D_00463628[];
extern char D_00463798[];
extern char D_00463670[];
extern char D_00463688[];
extern char D_00463640[];
extern char D_00463228[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

extern "C" void func_001B0850(void* self, void* iface, void* screen)
{
    char buf[16];
    if (screen == 0) {
        return;
    }
    cUIText* t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004636A0));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            cUIText_setAsciiString(t, func_00145340(iface));
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004636B0));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            cUIText_setAsciiString(t, func_00144BF0(iface));
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463628));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
            if (D_00534B34[0] != 0) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
            } else {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
            }
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463798));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            if ((D_005308D0[0] >> 8) & 1) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
            } else {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
            }
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463670));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            if ((D_005308D0[0] >> 6) & 1) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
            } else {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
            }
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463688));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            int f = D_005308D0[0] >> 7;
            if (f & 1) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045FCD8));
            } else {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_0045DCC8));
            }
        }
    }
    t = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_00463640));
    if (t != 0) {
        if (iface == 0) {
            cUIText_setAsciiString(t, D_004A1390);
        } else {
            cBE_getInterface_Fv(cBE_getBE(), 0);
            int n = D_00535C04[0];
            if (n <= 0) {
                cUIText_setUnicodeStringByID(t, GetHashValue32(D_00463228));
            } else {
                sprintf(buf, D_004A12C0, n);
                cUIText_setAsciiString(t, buf);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0C08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00463618[];
extern char D_004630E0[];
extern char D_00463468[];
extern char D_00462750[];
extern char D_004635F8[];

class cFEVObj_001B0C08 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08(int on);
    virtual void v09(int on);
};

extern "C" void func_001B0C08(void* self)
{
    *(int*)((char*)self + 0x6D4) = 1;
    if (*(void**)((char*)self + 0x40) != 0) {
        cFEVObj_001B0C08* o = (cFEVObj_001B0C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463618));
        if (o != 0) {
            o->v07(1);
        }
        cUIText* menu = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004630E0));
        if (menu != 0) {
            cUIMenu_setSelectedByIndex(menu, 1);
        }
        o = (cFEVObj_001B0C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463468));
        if (o != 0) {
            o->v09(1);
            cUIText_setUnicodeStringByID((cUIText*)o, GetHashValue32(D_00462750));
        }
        o = (cFEVObj_001B0C08*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004635F8));
        if (o != 0) {
            o->v08(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0E10);
#ifdef SKIP_ASM
extern "C" void func_001B0C08(void* self);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_0025F740(void* self, int a1);
extern "C" void func_00263018(void* self, void* a1);
extern "C" void* func_002591D0();
extern "C" void func_00263BA8(void* p, int a1);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001B0E10()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

struct sVE1B0E10 {
    short delta;
    short index;
    void (*fn)(void*, void*, int);
};

extern "C" void func_001B0E10(void* self)
{
    func_001B0C08(self);
    if (*(int*)((char*)self + 0x6D4) != 0) {
        func_0025F740(D_004A3028, 0);
        func_00263018(GetSession_001B0E10(), *(void**)((char*)D_004A3028 + 0x98));
        func_00263BA8(func_002591D0(), 2);
    } else {
        func_00263018(GetSession_001B0E10(), *(void**)((char*)D_004A3028 + 0x98));
    }
    char* obj = *(char**)((char*)self + 0x20);
    sVE1B0E10* vt = *(sVE1B0E10**)(obj + 0x8);
    vt[17].fn(obj + vt[17].delta, self, 0x14);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0F28);
#ifdef SKIP_ASM
extern signed char D_00440F68[];

extern "C" int func_001B0F28(int c)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (c == D_00440F68[i]) {
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0F60);
#ifdef SKIP_ASM
extern void* D_00468C10[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001B0F60(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(void***)((char*)self + 0x8) = D_00468C10;
    *(int*)((char*)self + 0x6DC) = 1;
    *(int*)((char*)self + 0xC) = 0x41;
    *(int*)((char*)self + 0x6D8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B0FB0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001B1B98(void* self, int index, int a2, int a3);
extern char D_00463800[];

extern "C" void func_001B0FB0(void* self)
{
    int i;
    *(int*)((char*)self + 0x6E0) = 0;
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00463800), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    for (i = 0; i < 30; i++) {
        func_001B1B98(self, i, 1, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1048__FPv);
#ifdef SKIP_ASM
void* func_001B1048(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1068);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_0039A738(void* a);
extern "C" void func_001B1B10(void* self, int sel, int flag);
extern "C" void func_001B1760(void* self, int index);
extern "C" void func_001B1808(void* self);
extern void* D_004A28A8;
extern char D_00534B30[];

extern "C" int func_001B1068(void* self, int a1)
{
    if (a1 != 0) {
        func_001B1B10(self, func_0039A738(*(void**)((char*)self + 0x6D0)), 0);
        cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        char* net = D_00534B30;
        if (*(int*)(net + 0x32C) >= 0) {
            func_001B1760(self, *(int*)(net + 0x32C));
            func_001B1B10(self, *(int*)(net + 0x32C), 1);
        }
        func_001B1808(self);
        *(int*)((char*)self + 0x6DC) = 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B10F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* cBE_getBE();
int cBENewPlayerInterface_getPlayerCharID(void* self, int index);
extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data);
extern "C" void* func_0014EEC8(void* self, int player, int index);
extern "C" int func_001B0F28(int c);
extern "C" void func_0039A7A8(void* self, int a1);
extern void* D_004A28A8;
extern signed char D_00440F68[];
extern char D_00463818[];
extern char D_00463830[];
extern char D_004A1390[];

struct sVec4_001B10F8 {
    float x, y, z, w;
    sVec4_001B10F8(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

class cFEVObj_001B10F8 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sVec4_001B10F8& c);
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
    virtual void v24(int on);
};

static inline int IsHash_001B10F8(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B10F8(void* self, cUIText* text)
{
    cFEVObj_001B10F8* box = (cFEVObj_001B10F8*)text;
    if (IsHash_001B10F8(*(int*)((char*)text + 0x38), D_00463818)) {
        *(int*)((char*)text + 0x14) &= ~1;
        int i;
        for (i = 0; i < 10; i++) {
            cUIListBox_addEntryByAsciiString(text, (const char*)func_0014EEC8(cBE_getInterface_Fv(cBE_getBE(), 2), D_00440F68[i], 0), D_00440F68[i]);
        }
        *(int*)((char*)text + 0x14) &= ~1;
        box->v09(1);
        int id = cBENewPlayerInterface_getPlayerCharID(cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 1), 0);
        *(int*)((char*)self + 0x6E0) = id;
        func_0039A7A8(text, (unsigned char)func_001B0F28(id));
        *(cUIText**)((char*)self + 0x6D0) = text;
        box->v24(1);
    } else if (IsHash_001B10F8(*(int*)((char*)text + 0x38), D_00463830)) {
        cUIText_setAsciiString(text, D_004A1390);
        box->v11(sVec4_001B10F8(1.0f, 0.0f, 0.0f, 0.0f));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1280);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001474A8(void* iface, int a1, int a2);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001B1A08(void* self, int on, int a2);
extern "C" void func_001B1B10(void* self, int sel, int flag);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_00264F88(void* self, int a1);
extern "C" void func_00265018(void* self, int a1);
extern "C" void func_00265140(void* self);
extern "C" int func_0039A738(void* a);
extern void* D_004A33CC;
extern void* D_004A28A8;
extern char D_00463818[];
extern char D_0045FD98[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

struct sVE1B1280 {
    short delta;
    short index;
    void (*fn)(void*);
};

class cFEVObj_001B1280 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

static inline int IsHash1B1280(int id, char* name) { return id == GetHashValue32(name); }

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001B1280(void* self, int a1, unsigned int msg)
{
    char* obj = (char*)a1;
    if (obj == 0) {
        return;
    }
    switch (msg) {
    case 5:
        if (*(int*)((char*)self + 0x6DC) != 0) {
            return;
        }
        if (D_004A33CC == 0) {
            return;
        }
        if (*(int*)((char*)self + 0x6E0) != func_0039A738(*(void**)((char*)self + 0x6D0))) {
            char* iface = (char*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 1);
            func_001474A8(iface, 0, 0);
            sVE1B1280* vt = *(sVE1B1280**)(iface + 0xC);
            vt[1].fn(iface + vt[1].delta);
        }
        {
            void* mgr = D_004A33CC;
            func_00265018(mgr, func_0039A738(*(void**)((char*)self + 0x6D0)));
        }
        *(int*)((char*)self + 0x6D8) = *(signed char*)((char*)self + 0x14);
        ((cFEVObj_001B1280*)obj)->v08(1);
        func_001B1A08(self, 1, 0);
        *(int*)((char*)self + 0x6DC) = 1;
        break;
    case 6:
        if (*(int*)((char*)self + 0x6DC) == 0) {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 2;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_0045FD98);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0x150) = 0x838;
            *(int*)((char*)p + 0x168) = 1;
            func_001A9BC0(self, p);
        } else {
            func_00265140(D_004A33CC);
            ((cFEVObj_001B1280*)obj)->v08(0);
            func_001B1A08(self, 0, 0);
            *(int*)((char*)self + 0x6DC) = 0;
        }
        break;
    case 9:
        if (IsHash1B1280(*(int*)(obj + 0x38), D_00463818)) {
            void* mgr = D_004A33CC;
            func_00264F88(mgr, func_0039A738(*(void**)((char*)self + 0x6D0)));
            func_001B1B10(self, func_0039A738(*(void**)((char*)self + 0x6D0)), 0);
        }
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B14D8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00463848[];
extern char D_00463868[];
extern char D_00463890[];
extern char D_004638B0[];
extern char D_004614E8[];

extern "C" void func_001B14D8(void* self, void* popup)
{
    func_001DA528(popup, 3);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00463848);
    func_001DA530(popup, 0, GetHashValue32(D_00463868));
    func_001DA510(popup, 0, GetHashValue32(D_00463890), 4);
    func_001DA510(popup, 1, GetHashValue32(D_004638B0), 0);
    func_001DA510(popup, 2, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1590);
#ifdef SKIP_ASM
class cFEVObj_001B1590 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual bool v06();
};

extern void* D_004A33CC;

extern "C" bool func_001B1590(void* self, cFEVObj_001B1590* obj)
{
    if (*(int*)((char*)self + 0x6DC) != 0 || D_004A33CC == 0) {
        return !obj->v06();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B15D8);
#ifdef SKIP_ASM
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
struct sFEObj_001B1F88;
extern "C" sFEObj_001B1F88* func_001B1F88(sFEObj_001B1F88* mem, int a1);
extern "C" void* func_001BFBB8(void* mem, int a1);
extern "C" void* func_00192D00(void* mem, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_0025DA90(void* self);
extern "C" void func_001B1760(void* self, int index);
extern "C" void func_001B1B10(void* self, int sel, int flag);
extern "C" void func_001B1A08(void* self, int on, int a2);
extern "C" void func_001AB288(void* self, int err);
extern void* D_004A28A8;
extern void* D_004A3028;
extern int D_004A4E88;
extern int D_00534B30_1B15D8[] __asm__("D_00534B30");
extern const char D_0045FF10[];
extern const char D_0045FF28[];
extern const char D_00460CC8[];

// Message handler for the profile list: select/scroll, error popups, and opening the follow-up screens.
extern "C" void* func_001B15D8(void* self, int a1, int a2)
{
    void* obj;
    switch (a1) {
    case 0xF3:
        cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
        if (D_00534B30_1B15D8[0xCB] >= 0) {
            func_001B1760(self, D_00534B30_1B15D8[0xCB]);
            func_001B1B10(self, D_00534B30_1B15D8[0xCB], 1);
        }
        break;
    case 0xF5:
        func_001B1A08(self, 1, 1);
        break;
    case 0xF7:
        func_001B1A08(self, 0, 1);
        break;
    case 0xEE: case 0xF1: case 0xF8: case 0xFA: case 0x112: case 0x113:
        func_001AB288(self, a1);
        break;
    case 0xF6:
        func_001A8A40(self, func_00192D00(cMemMan_alloc(0x73C, D_00460CC8, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0x10C:
        if (func_0025DA90(D_004A3028) != 0 && D_004A4E88 == 0) {
            obj = func_001B1F88((sFEObj_001B1F88*)cMemMan_alloc(0x73C, D_0045FF10, 0, 0), *(int*)((char*)self + 0x10));
        } else {
            obj = func_001BFBB8(cMemMan_alloc(0x6D0, D_0045FF28, 0, 0), *(int*)((char*)self + 0x10));
        }
        func_001A8A40(self, obj);
        break;
    default:
        return func_001A8E40_3(self, a1, a2);
    case 0xE0:
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1760);
#ifdef SKIP_ASM
class cFEVText_001B1760 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_0014EEC8(void* self, int player, int index);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_00463830[];

extern "C" void func_001B1760(void* self, int player)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        const char* str = (const char*)func_0014EEC8(cBE_getInterface_Fv(cBE_getBE(), 2), player, 0);
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463830));
        ((cFEVText_001B1760*)text)->v09(1);
        cUIText_setAsciiString(text, str);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1808);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
// PORT: func_002C2718 is a varargs formatter (buf, fmt, ...); the unit declares a 3-arg view
extern "C" void func_002C2718_1B1808(char* buf, const char* fmt, ...) __asm__("func_002C2718");
extern "C" void func_003A0E90(cUIText* text, char* str);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_00463108[];
extern char D_004639A0[];
extern char D_004634E8[];
extern char D_004639B8[];
extern char D_00463550[];
extern char D_004A1A88[];

struct sVEntry_001B1808 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1B1808(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001B1808* vt = *(sVEntry_001B1808**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

class cFEVObj_001B1808 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001B1808(void* self)
{
    char buf[0x100];
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    cFEVObj_001B1808* o = (cFEVObj_001B1808*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463108));
    if (o != 0) {
        cUIText_setAsciiString((cUIText*)o, *(const char**)((char*)D_004A3028 + 0x80));
        o->v09(1);
    }
    o = (cFEVObj_001B1808*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004639A0));
    if (o != 0) {
        cUIText_setAsciiString((cUIText*)o, *(const char**)((char*)D_004A3028 + 0x98));
        o->v09(1);
    }
    o = (cFEVObj_001B1808*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004634E8));
    if (o != 0) {
        void* mgr = D_004A3028;
        int name = Loc1B1808(D_00463550);
        func_002C2718_1B1808(buf, D_004A1A88, name, *(int*)((char*)mgr + 0xB8));
        func_003A0E90((cUIText*)o, buf);
        o->v09(1);
    }
    o = (cFEVObj_001B1808*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004639B8));
    if (o != 0) {
        void* mgr = D_004A3028;
        int name = Loc1B1808(D_00463550);
        func_002C2718_1B1808(buf, D_004A1A88, name, *(int*)((char*)mgr + 0xCC));
        func_003A0E90((cUIText*)o, buf);
        o->v09(1);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B1A08);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1B10);
#ifdef SKIP_ASM
extern "C" void func_001B1760(void* self, int index);
extern "C" void func_001B1B98(void* self, int index, int a2, int a3);

extern "C" void func_001B1B10(void* self, int sel, int flag)
{
    int i;
    for (i = 0; i < 30; i++) {
        if (i == sel && flag) {
            func_001B1760(self, i);
        }
        func_001B1B98(self, i, flag, i == sel);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1B98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" int func_00148BC8(void* iface, int a1, int idx);
extern "C" int func_00148C68(void* iface, int a1, int idx);
extern "C" int func_00148B78(void* iface, int a1, int idx);
extern "C" int func_00148CB8(void* iface, int a1, int idx);
extern "C" int func_00148D58(void* iface, int a1, int idx);
extern "C" int func_00148D08(void* iface, int a1, int idx);
extern "C" int func_00148C18(void* iface, int a1, int idx);
extern "C" void func_0039C428(void* self, int v);
extern void* D_004A28A8;
extern char* D_004412C8[];
extern char D_004A19F8[];
extern char D_004A1B18[];
extern char D_004A1B20[];
extern char D_004A12C0[];
extern char D_00441340[];
extern char D_00441350[];
extern char D_00441360[];
extern char D_00441378[];
extern unsigned char D_00534FD8[];
extern int D_00534B34[];

class cFEVObj_001B1B98 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001B1B98(void* self, int index, int a2, int a3)
{
    char buf[0x30];
    int stats[7];
    char num[0x10];
    char* name1;
    char* name2;
    if ((unsigned int)index >= 31) {
        return;
    }
    if (a2 != 0) {
        sprintf(buf, D_004A19F8, D_004412C8[index], D_004A1B18);
    } else {
        sprintf(buf, D_004A19F8, D_004412C8[index], D_004A1B20);
    }
    cFEVObj_001B1B98* o = (cFEVObj_001B1B98*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
    if (o != 0) {
        o->v09(a3);
    }
    if (a3 == 0) {
        return;
    }
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 3);
    cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (a2 != 0) {
        name1 = D_00441350;
        name2 = D_00441378;
        unsigned char* src = D_00534FD8;
        for (int j = 0; j < 7; j++) {
            stats[j] = src[j];
        }
    } else {
        name1 = D_00441340;
        name2 = D_00441360;
        if (D_00534B34[0] != 0) {
            int v = 0x28;
            for (int j = 6; j >= 0; j--) {
                stats[j] = v;
            }
        } else {
            stats[0] = func_00148BC8(iface, 0, index);
            stats[1] = func_00148C68(iface, 0, index);
            stats[2] = func_00148B78(iface, 0, index);
            stats[3] = func_00148CB8(iface, 0, index);
            stats[4] = func_00148D58(iface, 0, index);
            stats[5] = func_00148D08(iface, 0, index);
            stats[6] = func_00148C18(iface, 0, index);
        }
    }
    for (int i = 0; i < 7; i++) {
        name1[0] = '0' + i;
        cFEVObj_001B1B98* a = (cFEVObj_001B1B98*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name1));
        name2[0] = '0' + i;
        void* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name2));
        if (a != 0 && b != 0) {
            int v = stats[i];
            int q = v / 5;
            sprintf(num, D_004A12C0, q);
            a->v09(1);
            cUIText_setAsciiString((cUIText*)a, num);
            *(int*)((char*)b + 0x80) = 0x37;
            func_0039C428(b, v);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B1EC0);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001B1F18(void* self, void* a1, int a2);

extern "C" void func_001B1EC0(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x838:
        func_001B1F18(self, a1, a2);
        break;
    case 0x835:
        func_001A94D8(self);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1F18);
#ifdef SKIP_ASM
extern void* D_004A33CC;
extern "C" void func_00265768(void* self, int a1);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001B1F18(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        if (D_004A33CC != 0) {
            func_00265768(D_004A33CC, 0xF9);
        }
        func_001A97B8(self, a1, 0xF);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B1F88);
#ifdef SKIP_ASM
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");
extern "C" char* strcpy(char* dst, const char* src);
extern void* D_0046AE58[];
extern void* D_004A3028;

struct sCol_001B1F88 {
    float r, g, b, a;
};

struct sFEObj_001B1F88 {
    char pad0[0x8];
    void** vt;                     // 0x8
    int fC;                        // 0xC
    char pad10[0x6EC - 0x10];
    int f6EC;                      // 0x6EC
    int f6F0;                      // 0x6F0
    int f6F4;                      // 0x6F4
    int f6F8;                      // 0x6F8
    int items[2];                  // 0x6FC
    int items2[2];                 // 0x704
    char name[0x20];               // 0x70C
    sCol_001B1F88 color;           // 0x72C
};

extern "C" sFEObj_001B1F88* func_001B1F88(sFEObj_001B1F88* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    self->vt = D_0046AE58;
    self->fC = 0x3D;
    self->f6F8 = 0;
    for (int i = 0; i < 2; i++) {
        self->items[i] = 0;
        self->items2[i] = 0;
    }
    self->f6EC = 0;
    self->f6F0 = 0;
    self->f6F4 = 0;
    sCol_001B1F88 c;
    c.r = 1.0f;
    c.g = 1.0f;
    c.b = 1.0f;
    c.a = 1.0f;
    self->color = c;
    strcpy(self->name, *(const char**)((char*)D_004A3028 + 0x80));
    return self;
}
#endif

extern void* D_0046AE58[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2048__FPv);
#ifdef SKIP_ASM
void* func_001B2048(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_0046AE58;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2070);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001B2378(void* self, int a1);
extern "C" void func_001B3978(void* self, void* a1);
extern "C" void func_003A1310(void* self, int a1);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern void* D_004A3028;
extern char D_00463A08[];
extern char D_004619C8[];
extern char D_004619D8[];
extern char D_004619E8[];
extern char D_004A1B48[];
extern char D_004A1B50[];
extern char D_004A1B58[];
extern char D_00463A18[];
extern char D_00463A28[];

struct sBlk1B2070 {
    int v[4];
};

extern "C" void func_001B2070(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00463A08), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen == 0) {
        return;
    }
    cUIScreen_playFrame(screen, 0, 0);
    func_001B2378(self, 1);
    func_001B3978(self, *(void**)((char*)D_004A3028 + 0x80));
    *(int*)(*(char**)((char*)self + 0x6F0) + 0x74) |= 1;
    func_003A1310(*(void**)((char*)self + 0x6F0), 1);
    *(sBlk1B2070*)(*(char**)((char*)self + 0x6F0) + 0xA8) = *(sBlk1B2070*)((char*)self + 0x72C);
    *(void**)(*(char**)((char*)self + 0x6F0) + 0xB8) = *(void**)((char*)self + 0x6F4);
    cUIText* a = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619C8));
    cUIText* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619D8));
    cUIText* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619E8));
    *(cUIText**)(*(char**)((char*)self + 0x6F4) + 0x7C) = a;
    *(cUIText**)(*(char**)((char*)self + 0x6F4) + 0x80) = b;
    {
        char* o = *(char**)((char*)self + 0x6F4);
        if ((unsigned int)strlen(D_004A1B48) > 24) {
            o[0x8C] = 0;
        } else {
            strcpy(o + 0x8C, D_004A1B48);
        }
    }
    {
        char* o = *(char**)((char*)self + 0x6F4);
        if ((unsigned int)strlen(D_004A1B50) > 24) {
            o[0xA5] = 0;
        } else {
            strcpy(o + 0xA5, D_004A1B50);
        }
    }
    int two = 2;
    *(cUIText**)(*(char**)((char*)self + 0x6F4) + 0x84) = c;
    *(int*)(*(char**)((char*)self + 0x6F4) + 0x88) = two;
    cUIText* d = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1B58));
    cUIText* e = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463A18));
    cUIText* f = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463A28));
    *(cUIText**)(*(char**)((char*)self + 0x6EC) + 0x7C) = d;
    *(cUIText**)(*(char**)((char*)self + 0x6EC) + 0x80) = e;
    *(cUIText**)(*(char**)((char*)self + 0x6EC) + 0x84) = f;
    *(int*)(*(char**)((char*)self + 0x6EC) + 0x88) = two;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B22A0);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" int func_0025DA90(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001B22A0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001B22A0()
{
    func_00262768(GetSession_001B22A0(), 1, 3, func_0025DA90(D_004A3028), 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2320);
#ifdef SKIP_ASM
extern void* D_004A5B64;
extern "C" void func_001B3BF0(void* self);
extern "C" void* func_001A8770(void* self);

extern "C" void func_001B2320(void* self)
{
    if (*(int*)((char*)D_004A5B64 + 0x18) % 10000 == 0) {
        func_001B3BF0(self);
    }
    func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2378);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001B3978(void* self, void* a1);
extern "C" void func_001B3BF0(void* self);
extern "C" void func_001B3D20(void* self, int idx, int on);
extern "C" void func_001B25E0(const char* src, void* out);
extern "C" int func_0025F1B0(void* self);
extern "C" const char* func_0025DA90_s(void* self) __asm__("func_0025DA90");
extern "C" int func_0025DA90(void* self);
extern "C" const char* func_0025F1E0_p(void* self, int idx, int* flag) __asm__("func_0025F1E0");
extern "C" void func_0039B760(void* self, unsigned char a1);
extern "C" void func_003A0E90(cUIText* text, char* str);
struct sFEObj_001BCB58;
extern "C" sFEObj_001BCB58* func_001BCB58(sFEObj_001BCB58* self, int a1);
extern void* D_004A3028;
extern char* D_004A3E90_p __asm__("D_004A3E90");
extern char D_00463A38[];
extern char D_00463A60[];
extern char D_00461B30[];
extern char D_004A1390[];
struct sName_001B2378 { char c[17]; };
extern sName_001B2378 D_00463A48;

struct sBXString_001B2378 {
    char* p;
    sBXString_001B2378() { p = D_004A3E90_p; }
    sBXString_001B2378(const sBXString_001B2378& o);
};

struct sCol_001B2378 {
    float r, g, b, a;
    sCol_001B2378() {}
    sCol_001B2378(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cFEVObj_001B2378 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol_001B2378& c);
};

extern "C" void func_001B2378(void* vself, int a1)
{
    char* self = (char*)vself;
    if (*(void**)(self + 0x40) == 0) {
        return;
    }
    int n = func_0025F1B0(D_004A3028);
    func_001B3D20(self, -1, 0);
    cUIText* menu = cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(D_00463A38));
    if (*(unsigned char*)((char*)menu + 0x96) != n) {
        func_0039B760(menu, n);
    }
    if (n < 7) {
        *(int*)(self + 0x704) = 0;
    }
    sName_001B2378 name = D_00463A48;
    sBXString_001B2378 s;
    int flag = 0;
    for (int i = 5; i >= 0; i--) {
        int idx = *(int*)(self + 0x704) + i;
        sprintf(name.c, D_00463A60, i);
        cFEVObj_001B2378* t = (cFEVObj_001B2378*)cUIScreen_getObjectByHashName(*(void**)(self + 0x40), GetHashValue32(name.c));
        t->v11(sCol_001B2378(1.0f, 0.0f, 0.0f, 0.0f));
        if (idx < n) {
            cBXString_cBXString4(&s, func_0025F1E0_p(D_004A3028, idx, &flag));
            if (flag != 0) {
                char buf[256];
                func_001B25E0(func_0025DA90_s(D_004A3028), buf);
                if (func_0025DA90(D_004A3028) == 0) {
                    func_001A8A40(self, func_001BCB58((sFEObj_001BCB58*)cMemMan_alloc(0xB84, D_00461B30, 0, 0), *(int*)(self + 0x10)));
                }
                func_003A0E90(*(cUIText**)(self + 0x6E8), buf);
            }
        } else {
            cBXString_cBXString4(&s, D_004A1390);
        }
        cUIText_setAsciiString((cUIText*)t, s.p);
        *(int*)((char*)t + 0x18) = idx;
    }
    if (a1 != 0) {
        func_001B3978(self, self + 0x70C);
    }
    func_001B3BF0(self);
    cBXString__cBXString(&s, 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B25E0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void UIAsciiToUnicode(unsigned short* dst, const char* src);
extern "C" void func_002C2508(void* str, int a1);
extern "C" void func_002C2540(void* str, const char* s);
extern "C" void func_002C2688(void* str, unsigned short* s);
extern "C" int func_004165A8(const char* a, const char* b);
extern void* D_004A28A8;
extern const char* D_004A1A60;
extern const char* D_004A1A64;
extern const char* D_004A1A68;
extern const char* D_004A1A6C;
extern char D_00463A78[];
extern char D_00463A90[];
extern char D_00463AA8[];
extern char D_00463AC0[];

struct sVEntry_001B25E0 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1B25E0(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001B25E0* vt = *(sVEntry_001B25E0**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

extern "C" void func_001B25E0(const char* src, void* out)
{
    char name[128];
    char ext[128];
    unsigned short wext[128];
    if (src == 0) {
        return;
    }
    int i;
    for (i = 0; src[i] != '.' && i < 127; i++) {
        name[i] = src[i];
    }
    name[i] = 0;
    i++;
    ext[0] = ' ';
    int j;
    for (j = 1; src[i] != 0 && j < 128; i++, j++) {
        ext[j] = src[i];
    }
    ext[j] = 0;
    if (func_004165A8(name, D_004A1A60) == 0) {
        func_002C2508(out, Loc1B25E0(D_00463A78));
    } else if (func_004165A8(name, D_004A1A64) == 0) {
        func_002C2508(out, Loc1B25E0(D_00463A90));
    } else if (func_004165A8(name, D_004A1A68) == 0) {
        func_002C2508(out, Loc1B25E0(D_00463AA8));
    } else if (func_004165A8(name, D_004A1A6C) == 0) {
        func_002C2508(out, Loc1B25E0(D_00463AC0));
    } else {
        func_002C2540(out, name);
    }
    UIAsciiToUnicode(wext, ext);
    func_002C2688(out, wext);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B27B0);

INCLUDE_ASM("fe/feasyncfile", func_001B2CD0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2DA0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00463B70[];
extern char D_00463B88[];
extern char D_00463BA8[];
extern char D_00463BC0[];
extern char D_00463BD8[];
extern char D_00461458[];
extern char D_004614E8[];
extern char D_00463BF0[];

extern "C" void func_001B2DA0(void* self, void* menu)
{
    func_001DA528(menu, 6);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00463B70);
    func_001DA530(menu, 0, GetHashValue32(D_00463B88));
    func_001DA510(menu, 0, GetHashValue32(D_00463BA8), 3);
    func_001DA510(menu, 1, GetHashValue32(D_00463BC0), 0);
    func_001DA510(menu, 2, GetHashValue32(D_00463BD8), 6);
    func_001DA510(menu, 3, GetHashValue32(D_00461458), 2);
    func_001DA510(menu, 4, GetHashValue32(D_004614E8), 1);
    func_001DA510(menu, 5, GetHashValue32(D_00463BF0), 8);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B2EB8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_0025F1B0(void* self);
extern "C" void func_0039B760(void* self, unsigned char a1);
extern void* D_004A3028;
extern char D_004A1408[];
extern char D_00463108[];
extern char D_00463A38[];
extern char D_00463AD8[];
extern char D_00463C08[];
extern char D_00463C18[];
extern char D_00463C30[];
extern char D_00463C48[];
extern char D_00463C68[];
extern char D_00463C80[];
extern char D_00463C90[];
extern char D_00463CA0[];
extern char D_00463CB0[];
extern char D_00463CC0[];
extern char D_00463CD0[];
extern char D_00463CE0[];
extern char D_00463CF0[];
extern char D_00463D00[];
extern char D_00463D10[];
extern char D_004A1B68[];
extern char D_004A1B70[];

class cFEVObj_001B2EB8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08(int on);
    virtual void v09(int on);
};

extern "C" void func_001B2EB8(void* self, cFEVObj_001B2EB8* obj)
{
    char buf[32];
    char* s = (char*)self;
    char* o = (char*)obj;
    int id = *(int*)(o + 0x38);
    if (id == GetHashValue32(D_00463C08)) {
        *(void**)(s + 0x6E8) = obj;
        obj->v09(1);
    } else if (id == GetHashValue32(D_00463C18)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463C30));
        obj->v09(1);
    } else if (id == GetHashValue32(D_00463108)) {
        obj->v09(1);
        cUIText_setAsciiString((cUIText*)obj, D_004A1408);
    } else if (id == GetHashValue32(D_00463C48)) {
        obj->v09(1);
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463C68));
    } else if (id == GetHashValue32(D_00463A38)) {
        *(int*)(o + 0x14) |= 0x80;
        obj->v07(1);
        int n = func_0025F1B0(D_004A3028);
        if (n <= 0) {
            func_0039B760(obj, 6);
        } else {
            func_0039B760(obj, n);
        }
        *(void**)(s + 0x6FC) = obj;
    } else if (id == GetHashValue32(D_00463C80)) {
        obj->v07(1);
        *(void**)(s + 0x700) = obj;
    } else if (id == GetHashValue32(D_00463AD8)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463C90));
    } else if (id == GetHashValue32(D_00463CA0)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463CB0));
    } else if (id == GetHashValue32(D_00463CC0)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463CD0));
    } else if (id == GetHashValue32(D_00463CE0)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00463CF0));
    } else if (id == GetHashValue32(D_004A1B68)) {
        *(void**)(s + 0x6EC) = obj;
        *(int*)(o + 0x14) |= 1;
    } else if (id == GetHashValue32(D_00463D00)) {
        *(void**)(s + 0x6F0) = obj;
    } else if (id == GetHashValue32(D_004A1B70)) {
        *(void**)(s + 0x6F4) = obj;
        *(int*)(o + 0x14) |= 1;
    }
    void** slots = (void**)(s + 0x6D0);
    for (int i = 0; i < 6; i++) {
        sprintf(buf, D_00463D10, i + 1);
        if (id == GetHashValue32(buf)) {
            *(void**)((char*)slots + (i << 2)) = obj;
            break;
        }
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B31A0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B33D8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_0025AAE0(void* self, void* a1);
extern "C" void func_00262690(void* self, int a1, void* a2);
int func_001A98B0(void* self);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001B33D8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001B33D8(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    switch (*(int*)(p + 0x18)) {
    case 4:
        func_0025AAE0(D_004A3028, p + 0x74);
        break;
    case 2:
        func_00262690(GetSession_001B33D8(), func_001A98B0(self), *(char**)((char*)self + 0x69C) + 0x74);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B3490);
#ifdef SKIP_ASM
class cFEVObj_001B3490 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int a1);
};

struct sFEObj_001B3490 {
    char pad[0x6EC];
    void* f6EC;                    // 0x6EC
    int pad6F0;
    void* f6F4;                    // 0x6F4
    int pad6F8;
    cFEVObj_001B3490* items[2];    // 0x6FC
};

extern void* D_004A3028;
extern "C" void func_0039DE68(void* a, int b);
extern "C" void func_001B3978(void* self, void* a1);

extern "C" int func_001B3490(sFEObj_001B3490* self, int a1)
{
    if (a1 != 0) {
        int i;
        func_0039DE68(self->f6EC, 0);
        func_0039DE68(self->f6F4, 0);
        for (i = 0; i < 2; i++) {
            if (self->items[i] != 0) {
                self->items[i]->v07(1);
            }
        }
        func_001B3978(self, *(void**)((char*)D_004A3028 + 0x80));
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B3528);
#ifdef SKIP_ASM
extern "C" void func_001B3BF0(void* self);
extern "C" void func_001A87D0(void* self, int a1);

extern "C" void func_001B3528(void* self, int a1)
{
    func_001B3BF0(self);
    func_001A87D0(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B3568);
#ifdef SKIP_ASM
extern "C" void func_001B2378(void* self, int a1);

extern "C" int func_001B3568(void* self, void* sender, int event, int value)
{
    if (event == 4) {
        if (sender == *(void**)((char*)self + 0x6FC)) {
            *(int*)((char*)self + 0x704) = value;
            func_001B2378(self, 0);
            return 0x101;
        }
        if (sender == *(void**)((char*)self + 0x700)) {
            *(int*)((char*)self + 0x708) = value;
        }
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B35B0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
int func_001A98B0(void* self);
extern "C" void func_001ABB30(void* self, int a1, void* a2, int a3);
extern "C" void func_001A4B20_ABC50(void* self, int a1, int* out) __asm__("func_001ABC50");
extern "C" void func_001A4B20_ABE58(void* self, int a1, int* out) __asm__("func_001ABE58");
extern "C" void func_001ABED8(void* self);
extern "C" void func_001ABCD0(void* self, int a1, void* a2, int a3, int a4);
extern "C" void func_0025DF00(void* self, int a1);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern void* D_004A3028;
extern char D_00463D78[];

// Memory-card result handler: runs the follow-up for each result; on 19 shows the failure popup.
extern "C" void func_001B35B0(void* self, void* a1, int kind)
{
    int r17;
    int r18;
    switch (kind) {
    case 15:
        func_001ABCD0(self, func_001A98B0(self), a1, kind, 0);
        break;
    case 16:
        func_001A97B8(self, a1, kind);
        func_001ABB30(self, func_001A98B0(self), a1, kind);
        break;
    case 17:
        func_001A4B20_ABE58(self, func_001A98B0(self), &r17);
        if (r17 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, kind);
        }
        break;
    case 18:
        func_001A4B20_ABC50(self, func_001A98B0(self), &r18);
        if (r18 == 1) {
            func_001ABED8(self);
        } else {
            func_001A97B8(self, a1, kind);
        }
        break;
    case 19: {
        *(int*)((char*)self + 0x6C4) = 0;
        void* mc = D_004A3028;
        func_0025DF00(mc, func_001A98B0(self));
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00463D78);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x805;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
    }
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B3760);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_0039F600(void* p);
extern const char D_00461C60[];

extern "C" void func_001B3760(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_0039F600(*(char**)((char*)self + 0x10) + 0x18);
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B37D8);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_0039F600(void* p);
extern const char D_00461C60[];

extern "C" void func_001B37D8(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_0039F600(*(char**)((char*)self + 0x10) + 0x18);
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B3850);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001B35B0(void* self, void* a1, int a2);
extern "C" void func_001B3760(void* self, void* a1, int a2);
extern "C" void func_001B37D8(void* self, void* a1, int a2);

extern "C" void func_001B3850(void* self, void* a1, int a2)
{
    switch (*(unsigned int*)((char*)a1 + 0x18)) {
    case 0x80B:
        func_001B35B0(self, a1, a2);
        break;
    case 0x800:
        func_001B3760(self, a1, a2);
        break;
    case 0x801:
        func_001B37D8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B38D0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9150(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_001CE468(void* self, int v);
extern char D_00463DB8[];
extern char D_004A1408[];

extern "C" int func_001B38D0(void* self, void* obj)
{
    sVE1A4170* vt = *(sVE1A4170**)((char*)obj + 0x8);
    if (vt[27].fn((char*)obj + vt[27].delta) != 0) {
        // PORT: string pointer passed through an int parameter (func_001A9150's a3)
        func_001A9150(self, 0, GetHashValue32(D_00463DB8), (int)D_004A1408, 0, 4, 0x3F);
        *(int*)((char*)*(void**)((char*)self + 0x69C) + 0x43C) = 0;
        func_001CE468(*(void**)((char*)self + 0x69C), 1);
        func_001CE3C8(*(void**)((char*)self + 0x69C), 0x4B, 1, 2);
        *(int*)((char*)*(void**)((char*)self + 0x69C) + 0x438) = 1;
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B3978);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" int func_0025F1B0(void* self);
extern "C" const char* func_0025F1E0(void* self, int idx, int a2);
extern "C" int func_004165A8(const char* a, const char* b);
extern void* D_004A3028;
extern char D_00463A38[];

extern "C" void func_001B3978(void* self, void* name)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        int sel = -1;
        int i = 0;
        int n = func_0025F1B0(D_004A3028);
        for (; i < n; i++) {
            if (func_004165A8(func_0025F1E0(D_004A3028, i, 0), (const char*)name) == 0) {
                sel = i;
                break;
            }
        }
        if (sel >= 0) {
            cUIMenu_setSelectedByIndex(cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463A38)), sel);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B3A30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_001B2378(void* self, int a1);
extern "C" void func_001B3978(void* self, void* a1);
struct sFEObj_001BCB58;
extern "C" sFEObj_001BCB58* func_001BCB58(sFEObj_001BCB58* self, int a1);
extern "C" void func_001B2CD0(void* self, int a1);
extern "C" int func_0025DA90(void* self);
int func_001A98B0(void* self);
extern "C" void func_001AB3D0(void* self, int a1, int a2);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern void* D_004A3028;
extern char D_00461B30[];
extern char D_00463DC8[];
extern char D_00461618[];

// Message handler for the save/load screen; unknown ids refresh the list and go to the base handler.
extern "C" void* func_001B3A30(void* self, int a1, int a2)
{
    switch (a1) {
    case 0xE0: {
        char buf[32];
        strcpy(buf, (char*)self + 0x70C);
        func_001B2378(self, 1);
        func_001B3978(self, buf);
        break;
    }
    case 0xDC:
        if (func_0025DA90(D_004A3028) == 0) {
            func_001A8A40(self, func_001BCB58((sFEObj_001BCB58*)cMemMan_alloc(0xB84, D_00461B30, 0, 0), *(int*)((char*)self + 0x10)));
            break;
        }
        func_001B2378(self, 1);
        break;
    case 0xE8: {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00463DC8);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x804;
        func_001A9BC0(self, p);
        break;
    }
    case 0xDE:
        if (*(int*)((char*)self + 0x6F8) == 0) {
            func_001B2CD0(self, a2);
        }
        break;
    case 0xE1:
        func_001B2378(self, 1);
        break;
    case 0xEA: case 0xEB: case 0xEC: case 0xED: case 0xEE: case 0xEF: case 0xF0:
    case 0x106: case 0x10A: case 0x10B:
        func_001AB3D0(self, func_001A98B0(self), 1);
        break;
    default:
        func_001AB3D0(self, func_001A98B0(self), 1);
        return func_001A8E40_3(self, a1, a2);
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B3BF0);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_001AAD50(void* self, int a1, int a2);
extern "C" int func_0025F1B0(void* self);
extern "C" int func_0025F248(void* self, int idx);
extern "C" void func_0025F288(void* self, int idx, void* info);
extern void* D_004A3028;
extern char D_00463A60[];

class cFEVObj_001B3BF0 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

struct sInfo1B3BF0 {
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int pad[3];
};

struct sOwner1B3BF0 {
    char pad0[0x40];
    void* screen;
    char pad44[0x68C];
    cFEVObj_001B3BF0* items[6];
    char pad6E8[0x1C];
    int first;
};

extern "C" void func_001B3BF0(void* p)
{
    sOwner1B3BF0* self = (sOwner1B3BF0*)p;
    char buf[32];
    sInfo1B3BF0 info;
    int n = func_0025F1B0(D_004A3028);
    int i;
    for (i = 0; i < 6; i++) {
        int idx = self->first + i;
        sprintf(buf, D_00463A60, i);
        if (idx < n) {
            int r = func_0025F248(D_004A3028, idx);
            self->items[i]->v09(1);
            if (r != 0) {
                self->items[i]->v09(0);
            } else {
                func_0025F288(D_004A3028, idx, &info);
                func_001AAD50(self->screen, i, info.f10);
            }
        } else {
            self->items[i]->v09(0);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B3D20);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_001B27B0(void* self, int a1);
extern "C" int func_0025F1B0(void* self);
extern "C" void func_0039DA20(void* a0, void* a1, int a2, int a3);
extern "C" void func_003A0290(void* text, void* out);
extern void* D_004A3028;
extern char D_00463A60[];
extern char D_00463EA0[];
extern char D_004A17E0[];

struct sCol1B3D20 {
    float r, g, b, a;
    sCol1B3D20() {}
    sCol1B3D20(const float& r_, const float& g_, const float& b_, const float& a_) : r(r_), g(g_), b(b_), a(a_) {}
};

struct sVec3_1B3D20 {
    float x, y, z;
};

class cFEVObj_001B3D20 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol1B3D20& c);
};

static inline cFEVObj_001B3D20* Get1B3D20(void* self, char* name)
{
    return (cFEVObj_001B3D20*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
}

extern "C" void func_001B3D20(void* self, int idx, int on)
{
    char name[32];
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    sprintf(name, D_00463A60, idx);
    cFEVObj_001B3D20* sel = Get1B3D20(self, name);
    func_0039DA20(*(void**)((char*)self + 0x6EC), *(void**)((char*)self + 0x704), 6, func_0025F1B0(D_004A3028));
    if (sel == 0) {
        if (idx >= 0) {
            if (idx < 6) {
                return;
            }
        }
    }
    int i;
    for (i = 0; i < 6; i++) {
        sprintf(name, D_00463A60, i);
        Get1B3D20(self, name)->v11(sCol1B3D20(1.0f, 0.0f, 0.0f, 0.0f));
    }
    cFEVObj_001B3D20* hl = Get1B3D20(self, D_004A17E0);
    if (hl == 0) {
        return;
    }
    if (on == 0) {
        hl->v09(0);
        return;
    }
    sprintf(name, D_00463EA0, idx);
    cFEVObj_001B3D20* t = Get1B3D20(self, name);
    if (t == 0) {
        return;
    }
    sCol1B3D20 pos;
    func_003A0290(t, &pos);
    pos.r += 2.0f;
    pos.g += 3.0f;
    *(sVec3_1B3D20*)((char*)hl + 0x44) = *(sVec3_1B3D20*)&pos;
    hl->v09(1);
    func_001B27B0(self, *(int*)((char*)sel + 0x18));
    sel->v11(sCol1B3D20(1.0f, 1.0f, 1.0f, 1.0f));
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B3F78);
#ifdef SKIP_ASM
class cFEVObj_001B3F78 {
public:
    virtual void v01();
    virtual void v02();
};

extern void* D_00468B00[];
extern cFEVObj_001B3F78* D_004A1B78;
extern "C" cFEVObj_001B3F78* func_002C22C8();
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001B3F78(void* mem, int a1)
{
    func_001A8500_3(mem, a1, 0);
    *(int*)((char*)mem + 0x6D0) = 0;
    *(int*)((char*)mem + 0x6D4) = 0;
    *(int*)((char*)mem + 0x6D8) = 0;
    *(int*)((char*)mem + 0x6E4) = 0;
    *(int*)((char*)mem + 0x6E8) = 0;
    *(int*)((char*)mem + 0x6F4) = 0;
    *(int*)((char*)mem + 0x6F8) = 0;
    *(int*)((char*)mem + 0x6FC) = 0;
    *(int*)((char*)mem + 0x700) = 0;
    *(int*)((char*)mem + 0x704) = 0;
    *(int*)((char*)mem + 0x708) = 0;
    *(int*)((char*)mem + 0x710) = 0;
    *(int*)((char*)mem + 0x714) = 0;
    *(int*)((char*)mem + 0x718) = 0;
    *(int*)((char*)mem + 0x6A8) = 0;
    *(void***)((char*)mem + 0x8) = D_00468B00;
    *(int*)((char*)mem + 0xC) = 0x31;
    cFEVObj_001B3F78* o = func_002C22C8();
    D_004A1B78 = o;
    o->v02();
    *(int*)((char*)mem + 0x6E0) = -1;
    return mem;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4018);
#ifdef SKIP_ASM
extern void* D_00468B00[];
void cMemMan_free(void* p);
extern "C" void func_002C2300(void* p);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");
// D_004A1B78 is declared earlier in the unit (cFEVObj_001B3F78*, see func_001B3F78)

extern "C" void func_001B4018(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00468B00;
    if (*(void**)((char*)self + 0x710) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x710));
        *(void**)((char*)self + 0x710) = 0;
    }
    if (*(void**)((char*)self + 0x714) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x714));
        *(void**)((char*)self + 0x714) = 0;
    }
    if (*(void**)((char*)self + 0x718) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x718));
        *(void**)((char*)self + 0x718) = 0;
    }
    if (*(void**)((char*)self + 0x704) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x704));
        *(void**)((char*)self + 0x704) = 0;
    }
    if (D_004A1B78 != 0) {
        func_002C2300(D_004A1B78);
        D_004A1B78 = 0;
    }
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B40D0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_00256C50();
extern "C" void func_001B5268(void* self, int a1);
extern "C" void* func_0028B180();
void func_0028FC38(void* self);
extern char D_00463ED0[];
extern int D_004A2EEC;

extern "C" void func_001B40D0(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00463ED0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    if (D_004A2EEC != 0) {
        func_00256C50();
    }
    func_001B5268(self, 0);
    func_0028FC38(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4168);
#ifdef SKIP_ASM
void* func_0039E4A0(void* self);
extern "C" void* func_0028B180();
extern "C" void func_0028FC58(void*);

extern "C" void func_001B4168(void* self)
{
    func_0039E4A0(self);
    func_0028FC58(func_0028B180());
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4198__FPv);
#ifdef SKIP_ASM
void func_001B4198(void* self)
{
    *(int*)((char*)self + 0x708) = 6;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B41A8);
#ifdef SKIP_ASM
extern "C" void* func_001A8770(void* self);
extern "C" void func_001B4888(void* self, int a1, int a2, int a3);
extern "C" void func_001B5068(void* self, int a1);
extern "C" void func_001B43A8(void* self);
extern "C" void func_001B4470(void* self);
extern "C" void func_001B45E8(void* self);
extern "C" int func_0039F698(void* p);
void func_002C67E8(void* self, int a1);
extern char* D_004A1B78_p __asm__("D_004A1B78");
extern int D_004A1B80;

struct sVEv1B41A8 {
    short delta;
    short index;
    void (*fn)(void*, ...);
};

struct sVE1B41A8 {
    short delta;
    short index;
    int (*fn)(void*, ...);
};

static inline int VCall1B41A8(int slot)
{
    char* obj = D_004A1B78_p;
    sVE1B41A8* vt = *(sVE1B41A8**)obj;
    return vt[slot].fn(obj + vt[slot].delta);
}

// Per-frame update for the online-login screen: steps the login state machine on the network object.
extern "C" void func_001B41A8(void* self)
{
    if (D_004A1B78_p != 0) {
        char* obj = D_004A1B78_p;
        sVEv1B41A8* vt = *(sVEv1B41A8**)obj;
        vt[3].fn(obj + vt[3].delta);
    }
    switch (*(int*)((char*)self + 0x708)) {
    case 1:
        *(int*)((char*)self + 0x708) = 2;
        break;
    case 2:
        if (VCall1B41A8(11) == 0) {
            func_002C67E8(D_004A1B78_p, D_004A1B80);
            *(int*)((char*)self + 0x708) = 3;
        }
        break;
    case 3:
        if (VCall1B41A8(11) == 0) {
            func_001B4470(self);
        }
        break;
    case 4:
        func_001B43A8(self);
        break;
    case 5:
        if ((*(int*)((char*)self + 0x6E0))-- < 0) {
            if (VCall1B41A8(53) == 0) {
                func_001B5068(self, -1);
                func_001B4888(self, 0x842, 0x18, D_004A1B80);
            } else {
                func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
            }
            *(int*)((char*)self + 0x708) = 0;
            break;
        }
    case 0:
        if (VCall1B41A8(11) == 0) {
            char* obj = D_004A1B78_p;
            sVEv1B41A8* vt = *(sVEv1B41A8**)obj;
            vt[5].fn(obj + vt[5].delta, D_004A1B80);
        }
        break;
    case 6:
        *(int*)((char*)self + 0x708) = 7;
        break;
    case 7:
        if (VCall1B41A8(11) == 0) {
            func_002C67E8(D_004A1B78_p, D_004A1B80);
            *(int*)((char*)self + 0x708) = 8;
        }
        break;
    case 8:
        if (VCall1B41A8(11) == 0) {
            func_001B45E8(self);
        }
        break;
    }
    func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B43A8);
#ifdef SKIP_ASM
// D_004A1B78 is declared earlier in the unit (cFEVObj_001B3F78*, see func_001B3F78)
extern "C" void func_001B4888(void* self, int a1, int a2, int a3);
extern "C" void func_001B4CD8(void* self);
extern "C" void func_001B5068(void* self, int a1);

class cFEVObj_001B43A8 {
public:
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual int v53();
    virtual void v54();
    virtual int v55();
};

extern "C" void func_001B43A8(void* self)
{
    int a = ((cFEVObj_001B43A8*)D_004A1B78)->v53();
    if (((cFEVObj_001B43A8*)D_004A1B78)->v55() == 0) {
        *(int*)((char*)self + 0x708) = 0;
        func_001B5068(self, -1);
        func_001B4888(self, 0x840, 0x14, -1);
    } else if (a != 0) {
        func_001B4CD8(self);
    } else {
        *(int*)((char*)self + 0x708) = 0;
        func_001B5068(self, -1);
        func_001B4888(self, 0x840, 2, -1);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B4470);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B45E8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001B5068(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern "C" int* func_002591B8();
extern "C" void func_002636A8(void* self, void* a1);
// PORT: func_002C26D0 is a varargs formatter (dst, fmt, ...); the unit declares a 3-arg view
extern "C" void func_002C26D0_1B45E8(void* str, int fmt, ...) __asm__("func_002C26D0");
class cFEVObj_001B3F78;
extern cFEVObj_001B3F78* D_004A1B78;
extern void* D_004A28A8;
extern int D_004A1B80;
extern char D_00463F08[];
extern char D_00463F20[];
extern char D_00463F38[];
extern char D_0045F7E0[];
extern char D_00462C88[];

struct sVEntry_001B45E8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1B45E8(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001B45E8* vt = *(sVEntry_001B45E8**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

class cFEVObj_001B45E8 {
public:
    // vptr at 0x0; slot N at vtable offset N*8
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
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual int v53();
};

extern "C" void func_001B45E8(void* self)
{
    if (((cFEVObj_001B45E8*)D_004A1B78)->v53() == 0) {
        *(int*)((char*)self + 0x708) = 0;
        func_001B5068(self, -1);
        char* buf = (char*)self + 0x71C;
        void* p = func_001A9C50(self);
        int name = Loc1B45E8(D_00463F08);
        func_002C26D0_1B45E8(buf, Loc1B45E8(D_00463F20), D_004A1B80 + 1, name);
        *(char**)((char*)p + 0xC4) = buf;
        *(int*)((char*)p + 0xC0) = 1;
        *(int*)((char*)p + 0xBC) = 1;
        func_001C57C0((char*)p + 0xBC, 0, GetHashValue32(D_0045F7E0));
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x843;
        func_001A9BC0(self, p);
    } else {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00463F38);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x80E;
        func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
        func_001A9BC0(self, p);
        func_002636A8(func_002591B8(), *(void**)((char*)self + 0x6D0));
        *(int*)((char*)self + 0x708) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B47C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void func_002C2718(char* buf, const char* fmt, int a2);
extern "C" void func_002C26D0(void* str, int a1, char* buf);
extern void* D_004A28A8;
extern char D_004A12C0[];
extern char D_00463F58[];

struct sVE_001B47C0 {
    short delta;
    short index;
    int (*fn)(void* self, int hash);
};

extern "C" void func_001B47C0(void* self, int a1)
{
    char buf[32];
    char* str = (char*)self + 0x71C;
    func_002C2718(buf, D_004A12C0, a1);
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVE_001B47C0* vt = *(sVE_001B47C0**)(o + 4);
    char* obj = o + vt[4].delta;
    func_002C26D0(str, vt[4].fn(obj, GetHashValue32(D_00463F58)), buf);
    void* p = func_001A9C50(self);
    // stores
    *(int*)((char*)p + 0xBC) = 0;
    *(char**)((char*)p + 0xC4) = str;
    *(int*)((char*)p + 0xC0) = 1;
    *(int*)((char*)p + 0x154) = 1;
    *(int*)((char*)p + 0x150) = 0x83F;
    *(int*)((char*)p + 0x164) = 0;
    *(int*)((char*)p + 0x168) = 0;
    // end
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4888);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
// PORT: func_002C26D0 / func_002C2718 are varargs formatters (dst, fmt, ...); the unit declares 3-arg views
extern "C" void func_002C26D0_1B4888(void* str, int fmt, ...) __asm__("func_002C26D0");
extern "C" void func_002C2718_1B4888(char* buf, const char* fmt, ...) __asm__("func_002C2718");
extern void* D_004A28A8;
extern char D_004A12C0[];
extern char D_0045DC90[];
extern char D_0045DCD8[];
extern char D_00463F08[];
extern char D_00463F20[];
extern char D_00463F70[];
extern char D_00462688[];
extern char D_0045F7E0[];
extern char D_00462C88[];

struct sVEntry_001B4888 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1B4888(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001B4888* vt = *(sVEntry_001B4888**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

extern "C" void func_001B4888(void* self, int a1, int a2, int a3)
{
    char buf[0x20];
    int flag = 0;
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    switch (a2) {
    case 2:
        if (a3 == -1) {
            char* dst = (char*)self + 0x71C;
            a3 = 1;
            int name = Loc1B4888(D_00463F08);
            func_002C26D0_1B4888(dst, Loc1B4888(D_00463F20), a3, name);
            *(char**)((char*)p + 0xC4) = dst;
            *(int*)((char*)p + 0xC0) = a3;
        } else {
            char* dst = (char*)self + 0x71C;
            int name = Loc1B4888(D_00463F08);
            func_002C26D0_1B4888(dst, Loc1B4888(D_00463F20), a3 + 1, name);
            *(char**)((char*)p + 0xC4) = dst;
            *(int*)((char*)p + 0xC0) = 1;
            flag = 1;
        }
        break;
    case 0x14: {
        func_002C2718_1B4888(buf, D_004A12C0, a3 + 1);
        char* dst = (char*)self + 0x71C;
        func_002C26D0_1B4888(dst, Loc1B4888(D_0045DC90), buf);
        *(char**)((char*)p + 0xC4) = dst;
        *(int*)((char*)p + 0xC0) = 1;
        break;
    }
    case 0x18: {
        func_002C2718_1B4888(buf, D_004A12C0, a3 + 1);
        char* dst = (char*)self + 0x71C;
        int name = Loc1B4888(D_00463F08);
        func_002C26D0_1B4888(dst, Loc1B4888(D_00463F70), name, buf);
        *(char**)((char*)p + 0xC4) = dst;
        *(int*)((char*)p + 0xC0) = 1;
        break;
    }
    case 6:
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462688);
        *(int*)((char*)p + 0xC0) = 3;
        break;
    }
    *(int*)sub = 2;
    func_001C57C0(sub, 0, GetHashValue32(D_0045DCD8));
    if (flag == 0) {
        func_001C57C0(sub, 1, GetHashValue32(D_0045F7E0));
    } else {
        func_001C57C0(sub, 1, GetHashValue32(D_00462C88));
    }
    *(int*)(sub + 0x94) = a1;
    *(int*)(sub + 0xA8) = 0;
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4C00);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int func_001B4C00(void* self, void* a1, int a2)
{
    int r;
    if (a2 == 0xF || a2 == 0x14) {
        r = func_001A97B8(self, a1, a2);
    } else {
        r = func_001A97B8(self, a1, a2);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4C40);
#ifdef SKIP_ASM
extern int D_004A1B80;
extern "C" void func_001B47C0(void* self, int a1);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001B4C40(void* self, void* a1, unsigned int a2)
{
    switch (a2) {
    case 15:
        D_004A1B80 = 0;
        *(int*)((char*)self + 0x70C) = 1;
        func_001B47C0(self, 1);
        *(int*)((char*)self + 0x708) = 1;
        break;
    case 16:
    case 20:
        func_001A97B8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B4CD8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B4FA0);
#ifdef SKIP_ASM
extern "C" void func_001B4888(void* self, int a1, int a2, int a3);
extern "C" void func_001B5068(void* self, int a1);
extern "C" int func_0039F698(void* p);
extern int D_004A1B80;

extern "C" void func_001B4FA0(void* self, int err)
{
    switch (err) {
    case 0:
        func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
        break;
    // PORT: GNU case ranges
    case -21 ... -16:
    case -14 ... -1:
        func_001B4888(self, 0x842, 0x18, D_004A1B80);
        break;
    case -15:
        func_001B4888(self, 0x841, 6, -1);
        break;
    case -200:
        func_001B4888(self, 0x841, 0x14, 0);
        break;
    }
    func_001B5068(self, -1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5068);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void func_0039A670(void* self);

struct sCol1B5068 {
    float r, g, b, a;
};
extern sCol1B5068 D_004C66C8;

class cFEVObj_001B5068 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol1B5068& c);
};

extern "C" void func_001B5068(void* self, int a1)
{
    if (a1 <= 0) {
        func_0039A670((*(cFEVObj_001B5068**)((char*)self + 0x6E4)));
        func_0039A670((*(cFEVObj_001B5068**)((char*)self + 0x6E8)));
        (*(cFEVObj_001B5068**)((char*)self + 0x6E8))->v08(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E4))->v08(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6EC))->v08(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E8))->v09(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E4))->v09(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6F8))->v09(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6FC))->v09(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6FC))->v11(D_004C66C8);
        cUIMenu_setSelectedByIndex(*(void**)((char*)self + 0x6F4), 0);
    } else {
        (*(cFEVObj_001B5068**)((char*)self + 0x6EC))->v08(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E8))->v08(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E4))->v08(0);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E8))->v09(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6E4))->v09(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6F8))->v09(1);
        (*(cFEVObj_001B5068**)((char*)self + 0x6FC))->v09(0);
        cUIMenu_setSelectedByIndex(*(void**)((char*)self + 0x6F4), 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5268);
#ifdef SKIP_ASM
extern int D_004A1B80;
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" void func_0039A670(void* self);
extern "C" void func_001B47C0(void* self, int a1);

struct sFEObj_001B5268 {
    char pad[0x6E4];
    void* f6E4;    // 0x6E4
    void* f6E8;    // 0x6E8
    char pad6EC[0x6F4 - 0x6EC];
    void* f6F4;    // 0x6F4
    char pad6F8[0x708 - 0x6F8];
    int f708;      // 0x708
    int f70C;      // 0x70C
};

extern "C" void func_001B5268(void* obj, int a1)
{
    sFEObj_001B5268* self = (sFEObj_001B5268*)obj;
    cUIMenu_setSelectedByIndex(self->f6F4, 0);
    D_004A1B80 = 0;
    self->f70C = 1;
    func_0039A670(self->f6E4);
    func_0039A670(self->f6E8);
    func_001B47C0(obj, 1);
    self->f708 = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B52C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern char D_00463F98[];
extern char D_00461520[];
extern char D_00463FB0[];
extern char D_00463FC0[];
extern char D_00463F88[];
extern char D_00463FD8[];
extern char D_00463FF0[];
extern char D_00464000[];
extern char D_00464010[];
extern char D_00464020[];

class cFEVObj_001B52C8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int on);
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
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
    virtual void v24(int on);
};

static inline int IsHash1B52C8(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B52C8(void* self, cUIText* item)
{
    cFEVObj_001B52C8* obj = (cFEVObj_001B52C8*)item;
    if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463F98)) {
        *(int*)((char*)item + 0x18) = 1;
        obj->v09(1);
        obj->v06(1);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00461520)) {
        *(int*)((char*)item + 0x18) = -1;
        obj->v09(1);
        obj->v06(0);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463FB0)) {
        *(int*)((char*)item + 0x18) = -1;
        obj->v09(0);
        obj->v06(0);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463FC0)) {
        *(int*)((char*)item + 0x18) = -1;
        obj->v09(1);
        obj->v06(0);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463F88)) {
        *(int*)((char*)item + 0x18) = 100;
        *(cUIText**)((char*)self + 0x6E8) = item;
        obj->v24(1);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463FD8)) {
        *(cUIText**)((char*)self + 0x6F8) = item;
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00463FF0)) {
        *(cUIText**)((char*)self + 0x6FC) = item;
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00464000)) {
        *(int*)((char*)item + 0x18) = 101;
        *(cUIText**)((char*)self + 0x6E4) = item;
        obj->v24(1);
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00464010)) {
        *(cUIText**)((char*)self + 0x6F4) = item;
        *(int*)((char*)item + 0x18) = -1;
        *(int*)((char*)item + 0x14) |= 0x80;
    } else if (IsHash1B52C8(*(int*)((char*)item + 0x38), D_00464020)) {
        *(cUIText**)((char*)self + 0x6EC) = item;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B54B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00464030[];
extern char D_00464048[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00462C50[];
extern char D_00464068[];
extern char D_004614E8[];

extern "C" void func_001B54B8(void* self, void* menu)
{
    func_001DA528(menu, 5);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00464030);
    func_001DA530(menu, 0, GetHashValue32(D_00464048));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(menu, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(menu, 3, GetHashValue32(D_00464068), 2);
    func_001DA510(menu, 4, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B55B0);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern "C" void func_0039F290(void* list, void* item);
struct sFEObj_001B6288;
extern "C" sFEObj_001B6288* func_001B6288(sFEObj_001B6288* self, int a1, int a2);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_00464080[];

class cFEVObj_001B55B0 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

static inline void* GetSession_001B55B0()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001B55B0(void* self, void* a1, unsigned int kind)
{
    switch (kind) {
    case 15:
    case 20: {
        cFEVObj_001B55B0* o = *(cFEVObj_001B55B0**)((char*)self + 0x6EC);
        *(int*)((char*)self + 0x6D8) = 1;
        o->v08(0);
        func_00261408(GetSession_001B55B0());
        func_0025B800(D_004A3028);
        func_002636F0(func_002591B8(), 0);
        func_001A97B8(self, a1, kind);
        break;
    }
    case 22:
        if (*(int*)((char*)self + 0x6D8) == 0) {
            char* p = (char*)func_001B6288((sFEObj_001B6288*)cMemMan_alloc(0x700, D_00464080, 0, 0), *(int*)((char*)self + 0x10), (int)self);
            *(int*)(p + 0x18) = 0x81A;
            func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        }
        *(int*)((char*)self + 0x6D8) = 0;
        func_001A97B8(self, a1, 22);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5740);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern void* D_004A3328;
extern void* D_004A3028;

class cFEVObj_001B5740 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int a1);
};

static inline void* GetSession_001B5740()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001B5740(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_00261408(GetSession_001B5740());
        func_0025B800(D_004A3028);
        func_002636F0(func_002591B8(), 0);
        (*(cFEVObj_001B5740**)((char*)self + 0x6EC))->v08(0);
        func_001A97B8(self, a1, a2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5830);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
// func_001A97B8 returns void (its asm never sets $2); the unit declares it int
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
// PORT: func_001B6AB8 is declared later in the unit with an int owner parameter
extern "C" void* func_001B6AB8(void* mem, int a1, int a2, int a3, int a4, int a5);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern "C" void func_0039F290(void* list, void* item);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern void* D_004A3328;
extern void* D_004A3028;
extern char D_00464098[];
extern char D_00462D10[];

static inline void* GetSession_001B5830()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

class cFEVObj_001B5830 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

extern "C" void func_001B5830(void* self, void* a1, unsigned int kind)
{
    switch (kind) {
    case 15:
        func_001A97B8_v(self, a1, 15);
        *(int*)((char*)self + 0x700) = 0;
        break;
    case 16:
        *(int*)((char*)self + 0x700) = 1;
        func_001A97B8_v(self, a1, 16);
        break;
    case 20:
        func_00261408(GetSession_001B5830());
        func_0025B800(D_004A3028);
        func_002636F0(func_002591B8(), 0);
        *(int*)((char*)self + 0x6D8) = 1;
        (*(cFEVObj_001B5830**)((char*)self + 0x6EC))->v08(0);
        func_001A97B8_v(self, a1, 20);
        break;
    case 22:
        func_001A97B8_v(self, a1, 22);
        if (*(int*)((char*)self + 0x700) != 0) {
            void* p = func_001B6AB8(cMemMan_alloc(0x6E8, D_00464098, 0, 0), *(int*)((char*)self + 0x10), (int)self,
                                    *(int*)((char*)self + 0x714), *(int*)((char*)self + 0x718), *(int*)((char*)self + 0x710));
            *(int*)((char*)p + 0x18) = 0x81B;
            func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        } else if (*(int*)((char*)self + 0x6D8) == 0) {
            void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
            *(int*)((char*)p + 0x18) = 0x82C;
            func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        }
        *(int*)((char*)self + 0x700) = 0;
        *(int*)((char*)self + 0x6D8) = 0;
        break;
    default:
        func_001A97B8_v(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5A58);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
// PORT: the unit declares func_001A97B8 as returning int; this caller ignores the result.
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* func_001BEE30(void* mem, int a1);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern void* D_004A3328;
extern void* D_004A3028;
extern const char D_00461CD8[];

struct sVE1B5A58 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

// Tracks a pending flag; on 0x10/0x14 restarts the memory-card task and resets the list.
extern "C" void func_001B5A58(void* self, void* a1, int a2)
{
    switch (a2) {
    case 0x15:
        *(int*)((char*)self + 0x6DC) = 0;
        func_001A97B8_v(self, a1, a2);
        break;
    case 0xF:
        func_001A97B8_v(self, a1, a2);
        *(int*)((char*)self + 0x6DC) = 1;
        break;
    case 0x10: case 0x14: {
        func_001A97B8_v(self, a1, a2);
        if (D_004A3328 == 0) {
            func_00260F80();
        }
        if (func_00261460(D_004A3328) == 0) {
            func_002613C8(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800(D_004A3028);
        }
        func_00261408(D_004A3328);
        func_0025B800(D_004A3028);
        func_002636F0(func_002591B8(), 0);
        char* obj = *(char**)((char*)self + 0x6EC);
        sVE1B5A58* vt = *(sVE1B5A58**)(obj + 8);
        vt[8].fn(obj + vt[8].delta, 0);
        break;
    }
    case 0x16:
        if (*(int*)((char*)self + 0x6DC) != 0) {
            func_001A8A40(self, func_001BEE30(cMemMan_alloc(0x6D4, D_00461CD8, 0, 0), *(int*)((char*)self + 0x10)));
        }
        func_001A97B8_v(self, a1, a2);
        break;
    default:
        func_001A97B8_v(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5BD8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* func_0028B180();
extern "C" void func_00286200(void* p);
extern "C" void func_00256088();
extern char D_00463F98[];

struct sColor1B5BD8 {
    float r, g, b, a;
    sColor1B5BD8(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};

class cFEVObj_001B5BD8 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06(int on);
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11(const sColor1B5BD8& c);
};

struct sFlags1B5BD8 {
    unsigned int f0 : 8;
    unsigned int mode : 6;
};

extern "C" void func_001B5BD8(void* self, void* a1, unsigned int kind)
{
    switch (kind) {
    case 15: {
        func_001A97B8(self, a1, 15);
        func_00286200(func_0028B180());
        func_00256088();
        cFEVObj_001B5BD8* o = (cFEVObj_001B5BD8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463F98));
        if (o != 0) {
            o->v06(0);
            o->v11(sColor1B5BD8(1.0f, 0.5f, 0.5f, 0.5f));
        }
        ((sFlags1B5BD8*)((char*)self + 0x1C))->mode = 7;
        break;
    }
    case 16:
    case 20:
        func_001A97B8(self, a1, kind);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5CF8);
#ifdef SKIP_ASM
class cFEVObj_001B5CF8 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int a1);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" void func_001B5CF8(void* self, void* a1, int a2)
{
    if (a2 == 0x16) {
        func_001A97B8(self, a1, a2);
        (*(cFEVObj_001B5CF8**)((char*)self + 0x6EC))->v08(0);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5D58);
#ifdef SKIP_ASM
extern "C" void func_001B5A58(void* self, void* a1, int a2);
// Dispatches a message to the matching handler, falling back to the base handler.
extern "C" void func_001B5D58(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x81C:
        func_001B5CF8(self, a1, a2);
        break;
    case 0x80E:
        func_001B55B0(self, a1, a2);
        break;
    case 0x81B:
        func_001B5740(self, a1, a2);
        break;
    case 0x81A:
        func_001B5830(self, a1, a2);
        break;
    case 0x82C:
        func_001B5A58(self, a1, a2);
        break;
    case 0x840: case 0x841: case 0x842:
        func_001B4C40(self, a1, a2);
        break;
    case 0x843:
        func_001B4C00(self, a1, a2);
        break;
    case 0x844:
        func_001B5BD8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B5E28);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void USTR_copy(void* dst, void* src);
extern "C" int USTR_length(void* s);
void cMemMan_free(void* p);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" int func_001AAF90(void* self, void* msg);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_002C2508(void* dst, int src);
extern "C" void func_0039F190(void* self, int a1);
// PORT: operator_new__FUi really takes (size, tag, flags, d)
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
extern void* D_004A28A8;
extern char D_004641B0[];
extern char D_004641D0[];
extern char D_00460688[];
extern char D_00461618[];

struct sVEntry_001B5E28 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1B5E28(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001B5E28* vt = *(sVEntry_001B5E28**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

// PORT: a2 is a message pointer passed as int
extern "C" int func_001B5E28(void* self, int id, int a2)
{
    char* msg = (char*)a2;
    if (id == 0x105) {
        if (*(int*)((char*)self + 0x1C) & 6) {
            func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
        }
    } else {
        if (id >= 0x105) {
            if (id < 0x117) {
                if (id >= 0x115) {
                    int type = *(int*)(msg + 8);
                    if (type != 0) {
                        int str;
                        switch (type) {
                        case 0x2D646576:
                        case 0x2D617468:
                        case 0x2D636667:
                        case 0x2D696E69:
                        case 0x2D646966:
                        case 0x2D746F6E:
                            str = Loc1B5E28(D_004641B0);
                            break;
                        default:
                            str = Loc1B5E28(D_004641D0);
                            break;
                        }
                        if (*(void**)((char*)self + 0x704) != 0) {
                            cMemMan_free(*(void**)((char*)self + 0x704));
                            *(void**)((char*)self + 0x704) = 0;
                        }
                        void* u = (void*)func_001AAF90(self, msg);
                        if (u != 0) {
                            *(void**)((char*)self + 0x704) = operator_new_tag((USTR_length(u) + 1) * 2, D_00460688, 0x100, 0);
                            USTR_copy(*(void**)((char*)self + 0x704), u);
                        } else {
                            *(void**)((char*)self + 0x704) = operator_new_tag((USTR_length((void*)str) + 1) * 2, D_00460688, 0x100, 0);
                            func_002C2508(*(void**)((char*)self + 0x704), str);
                        }
                        int one = 1;
                        void* p = func_001A9C50(self);
                        *(int*)((char*)p + 0xBC) = one;
                        char* sub = (char*)p + 0xBC;
                        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
                        *(void**)((char*)p + 0xC4) = *(void**)((char*)self + 0x704);
                        *(int*)((char*)p + 0x150) = 0x81C;
                        *(int*)((char*)p + 0xC0) = one;
                        func_001A9BC0(self, p);
                    }
                    return 0;
                }
            }
        }
        return func_001A8E40_3i(self, id, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6078__FPv);
#ifdef SKIP_ASM
int func_001B6078(void* self)
{
    return 0x101;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B6080);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B60A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00194A60(void* mem, int a1);
extern "C" void func_001A86E8(int on);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001B4198(void* self);
extern "C" void func_001B5268(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_004641F0[];
extern char D_00463F88[];
extern const char D_00460BA8[];

class cFEVObj_001B60A8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

static inline int IsHash1B60A8(int id, char* name) { return id == GetHashValue32(name); }

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001B60A8(void* self, int a1, unsigned int msg)
{
    char* obj = (char*)a1;
    if (obj == 0) {
        return;
    }
    switch (msg) {
    case 5: {
        int t = *(int*)(obj + 0x18);
        switch (t) {
        case 0:
            (*(cFEVObj_001B60A8**)((char*)self + 0x6EC))->v08(1);
            func_001B4198(self);
            break;
        case 1: {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 2;
            char* sub = (char*)p + 0xBC;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_004641F0);
            *(int*)((char*)p + 0xC0) = 3;
            *(int*)((char*)p + 0x150) = 0x844;
            *(int*)((char*)p + 0x168) = 1;
            func_001A9BC0(self, p);
            break;
        }
        }
        break;
    }
    case 9:
        if (IsHash1B60A8(*(int*)(obj + 0x38), D_00463F88)) {
            *(int*)((char*)self + 0x6D0) = *(unsigned char*)(obj + 0x319);
            func_0039A7A8(*(void**)((char*)self + 0x6E4), (unsigned char)*(int*)((char*)self + 0x6D0));
        }
        break;
    case 8:
        func_001B5268(self, 0);
        break;
    case 6:
        func_001A86E8(0);
        func_001A8A40(self, func_00194A60(cMemMan_alloc(0x58, D_00460BA8, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6288);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void cMemMan_free(void* p);
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int USTR_length(void* s);
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");
extern void* D_004689F0[];
extern void* D_004A28A8;
extern char D_00464208[];
extern char D_00464220[];

struct sVE_001B6288 {
    short delta;
    short index;
    void* (*fn)(void* self, int hash);
};

struct sFEObj_001B6288 {
    char pad0[0x8];
    void** vt;          // 0x8
    int fC;             // 0xC
    char pad10[0x6A8 - 0x10];
    int f6A8;           // 0x6A8
    char pad6AC[0x6D0 - 0x6AC];
    int f6D0;           // 0x6D0
    int f6D4;           // 0x6D4
    char pad6D8[0x6E4 - 0x6D8];
    int f6E4;           // 0x6E4
    char pad6E8[0x6F4 - 0x6E8];
    int f6F4;           // 0x6F4
    int f6F8;           // 0x6F8
    void* f6FC;         // 0x6FC
};

extern "C" sFEObj_001B6288* func_001B6288(sFEObj_001B6288* self, int a1, int a2)
{
    func_001A8500_3(self, a1, a2);
    self->f6F4 = 2;
    self->vt = D_004689F0;
    self->f6F8 = 0x1E;
    self->fC = 0x44;
    self->f6D0 = 0;
    self->f6D4 = 0;
    self->f6E4 = 0;
    self->f6FC = 0;
    char* o = *(char**)((char*)D_004A28A8 + 0x8C);
    sVE_001B6288* vt = *(sVE_001B6288**)(o + 4);
    int n = USTR_length(vt[4].fn(o + vt[4].delta, GetHashValue32(D_00464208)));
    if (self->f6FC != 0) {
        cMemMan_free(self->f6FC);
        self->f6FC = 0;
    }
    self->f6FC = operator_new_tag((n + 5) * 2, D_00464220, 0x100, 0);
    self->f6A8 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6368);
#ifdef SKIP_ASM
extern void* D_004689F0[];
void cMemMan_free(void* p);
extern "C" void func_002563A8(void* p);
extern "C" void func_002561E0(void* p, int flags);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001B6368(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004689F0;
    if (*(void**)((char*)self + 0x6D0) != 0) {
        func_002563A8(*(void**)((char*)self + 0x6D0));
        if (*(void**)((char*)self + 0x6D0) != 0) {
            func_002561E0(*(void**)((char*)self + 0x6D0), 3);
        }
    }
    if (*(void**)((char*)self + 0x6FC) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x6FC));
        *(void**)((char*)self + 0x6FC) = 0;
    }
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B63E8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* func_002561B8(void* mem);
extern "C" void func_00256258(void* self, int mode);
extern char D_00464238[];
extern char D_00464250[];
extern char D_00464260[];

struct sProfile1B63E8 {
    unsigned int flags;
    char rest[0x284];
};
extern sProfile1B63E8 D_00535610;

class cFEVObj_001B63E8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001B63E8(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00464238), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        cFEVObj_001B63E8* o = (cFEVObj_001B63E8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464250));
        if (o != 0) {
            o->v09(0);
        }
    }
    *(void**)((char*)self + 0x6D0) = func_002561B8(cMemMan_alloc(0xA50, D_00464260, 0x100, 0));
    *(int*)((char*)self + 0x6E4) = 1;
    cBE_getInterface_Fv(cBE_getBE(), 4);
    int mode = 0;
    sProfile1B63E8 prof = D_00535610;
    switch ((prof.flags >> 22) & 7) {
    case 0:
        mode = 0;
        break;
    case 1:
        mode = 1;
        break;
    case 2:
        mode = 2;
        break;
    case 3:
        mode = 3;
        break;
    }
    func_00256258(*(void**)((char*)self + 0x6D0), mode);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B65C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_004631E8[];
extern char D_00464278[];
extern char D_00464288[];
extern char D_004A1BA0[];
extern char D_004642A0[];

class cFEVObj_001B65C0 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline int IsHash1B65C0(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B65C0(void* self, cUIText* text)
{
    cFEVObj_001B65C0* obj = (cFEVObj_001B65C0*)text;
    if (IsHash1B65C0(*(int*)((char*)text + 0x38), D_004631E8)) {
        *(cUIText**)((char*)self + 0x6D8) = text;
        obj->v09(0);
    } else if (IsHash1B65C0(*(int*)((char*)text + 0x38), D_00464278)) {
        *(cUIText**)((char*)self + 0x6D4) = text;
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x6D4), GetHashValue32(D_00464288));
    } else if (IsHash1B65C0(*(int*)((char*)text + 0x38), D_004A1BA0)) {
        *(cUIText**)((char*)self + 0x6DC) = text;
        obj->v09(0);
    } else if (IsHash1B65C0(*(int*)((char*)text + 0x38), D_004642A0)) {
        *(cUIText**)((char*)self + 0x6E0) = text;
        obj->v09(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B66B8);
#ifdef SKIP_ASM
class cFEVObj_001B66B8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual int v05();
    virtual int v06();
};

extern "C" int func_001B66B8(void* self, cFEVObj_001B66B8* obj)
{
    if (*(int*)((char*)self + 0x6E4) == 2) {
        if (obj->v05() || obj->v06()) {
            *(int*)(*(char**)((char*)self + 0x6D0) + 0x14) = 1;
            *(int*)((char*)self + 0x6E4) = 4;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6740);
#ifdef SKIP_ASM
class func_001B6740_cObj {
public:
    char pad[0x8];
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
    virtual int v06(int, int);
    virtual int v07(int, int);
    virtual int v08(int, int);
    virtual int v09(int, int);
    virtual int v10(int, int);
    virtual int v11(int, int);
    virtual int v12(int, int);
    virtual int v13(int, int);
    virtual int v14(int, int);
    virtual int v15(int, int);
    virtual int v16(int, int);
    virtual int v17(int, int);
    virtual int v18(int, int);
    virtual int v19(int, int);
    virtual int v20(int, int);
    virtual int v21(int, int);
    virtual int v22(int, int);
    virtual int v23(int, int);
    virtual int v24(int, int);
};

extern "C" int func_001B6740(void* self, int a1, int a2)
{
    return (*(func_001B6740_cObj**)((char*)self + 0x20))->v24(a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6770);
#ifdef SKIP_ASM
extern "C" void func_001A8918(void* self, int a1, int msg);

extern "C" void func_001B6770(void* self, int a1, int msg)
{
    if (msg != 0xD) {
        func_001A8918(self, a1, msg);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6798);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" void USTR_copy(void* dst, void* src);
extern "C" int USTR_length(void* s);
void cMemMan_free(void* p);
extern "C" void* func_001A8770(void* self);
extern "C" void func_002562D0(void* self);
extern "C" void func_002563F8(void* self);
// PORT: operator_new__FUi really takes (size, tag, flags, d)
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern char D_00464208[];
extern char D_00464220[];
extern char D_00464250[];

class cFEVObj_001B6798 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(void* owner, int msg);
};

static inline int IsReady_001B6798(int* d) { return *d >= 3; }
static inline int IsDone_001B6798(int* d) { return *d == 5; }

extern "C" void func_001B6798(void* self)
{
    char* s = (char*)self;
    switch (*(int*)(s + 0x6E4)) {
    case 1:
        if (IsReady_001B6798(*(int**)(s + 0x6D0))) {
            (*(cFEVObj_001B6798**)(s + 0x6D8))->v09(1);
            (*(cFEVObj_001B6798**)(s + 0x6DC))->v09(1);
            (*(cFEVObj_001B6798**)(s + 0x6E0))->v09(1);
            (*(cFEVObj_001B6798**)(s + 0x6D4))->v09(1);
            cUIText_setUnicodeStringByID(*(cUIText**)(s + 0x6D4), GetHashValue32(D_00464208));
            cFEVObj_001B6798* g = (cFEVObj_001B6798*)cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_00464250));
            if (g != 0) {
                g->v09(1);
            }
            *(int*)(s + 0x6E4) = 2;
            func_002562D0(*(void**)(s + 0x6D0));
        }
        break;
    case 2:
        if (IsDone_001B6798(*(int**)(s + 0x6D0))) {
            *(int*)(s + 0x6E4) = 3;
        }
        break;
    case 3: {
        char* d = *(char**)(s + 0x6D0);
        if (*(int*)(d + 0x1C) != 0) {
            char* o = *(char**)(s + 0x20);
            char* a = d + 0x450;
            char* b = d + 0x650;
            char* c = d + 0x850;
            if (*(void**)(o + 0x710) != 0) {
                cMemMan_free(*(void**)(o + 0x710));
                *(void**)(o + 0x710) = 0;
            }
            *(void**)(o + 0x710) = operator_new_tag((USTR_length(a) + 1) * 2, D_00464220, 0x100, 0);
            if (*(void**)(o + 0x714) != 0) {
                cMemMan_free(*(void**)(o + 0x714));
                *(void**)(o + 0x714) = 0;
            }
            *(void**)(o + 0x714) = operator_new_tag((USTR_length(b) + 1) * 2, D_00464220, 0x100, 0);
            if (*(void**)(o + 0x718) != 0) {
                cMemMan_free(*(void**)(o + 0x718));
                *(void**)(o + 0x718) = 0;
            }
            *(void**)(o + 0x718) = operator_new_tag((USTR_length(c) + 1) * 2, D_00464220, 0x100, 0);
            USTR_copy(*(void**)(o + 0x710), a);
            USTR_copy(*(void**)(o + 0x714), b);
            USTR_copy(*(void**)(o + 0x718), c);
            (*(cFEVObj_001B6798**)(s + 0x20))->v17(self, 0x10);
        } else {
            (*(cFEVObj_001B6798**)(s + 0x20))->v17(self, 0xF);
        }
        break;
    }
    case 4:
        if (IsDone_001B6798(*(int**)(s + 0x6D0))) {
            (*(cFEVObj_001B6798**)(s + 0x20))->v17(self, 0x14);
        }
        break;
    }
    func_002563F8(*(void**)(s + 0x6D0));
    func_001A8770(self);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B6A90);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6AB8);
#ifdef SKIP_ASM
extern void* D_004688E0[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001B6AB8(void* self, int a1, int a2, int a3, int a4, int a5)
{
    func_001A8500_3(self, a1, a2);
    *(int*)((char*)self + 0x6D0) = a3;
    *(int*)((char*)self + 0x6D4) = a4;
    *(int*)((char*)self + 0x6D8) = a5;
    *(void***)((char*)self + 0x8) = D_004688E0;
    *(int*)((char*)self + 0xC) = 0x45;
    return self;
}
#endif

extern void* D_004688E0[];
extern "C" void* func_001A85D0(void*);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6B28__FPv);
#ifdef SKIP_ASM
void* func_001B6B28(void* self)
{
    *(int*)((char*)self + 0x8) = (int)(void*)D_004688E0;
    return func_001A85D0(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6B50);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004642B0[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void* func_001B6B50(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004642B0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        screen = cUIScreen_playFrame(screen, 0, 0);
    }
    return screen;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6BB8);
#ifdef SKIP_ASM
class cFEVText_001B6BB8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
extern char D_004A1BA8[];
extern char D_004A1BB0[];
extern char D_004A1BB8[];
extern char D_00464250[];
extern char D_004642C0[];

static inline int IsHash1B6BB8(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B6BB8(void* self, void* obj)
{
    if (IsHash1B6BB8(*(int*)((char*)obj + 0x38), D_004A1BA8)) {
        *(void**)((char*)self + 0x6DC) = obj;
    } else if (IsHash1B6BB8(*(int*)((char*)obj + 0x38), D_004A1BB0)) {
        *(void**)((char*)self + 0x6E0) = obj;
    } else if (IsHash1B6BB8(*(int*)((char*)obj + 0x38), D_004A1BB8)) {
        *(void**)((char*)self + 0x6E4) = obj;
    } else if (IsHash1B6BB8(*(int*)((char*)obj + 0x38), D_00464250)) {
        ((cFEVText_001B6BB8*)obj)->v09(1);
    } else if (IsHash1B6BB8(*(int*)((char*)obj + 0x38), D_004642C0)) {
        *(int*)((char*)obj + 0x90) |= 8;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6C98);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIScreen;
unsigned short cUIScreen_getFrameByLabel(cUIScreen* self, int label);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" int func_002C24D0(void* p);
extern "C" void func_003A0D00(void* text, void* str);
extern char D_004A1BC0[];
extern char D_004A1BC8[];
extern char D_004642D0[];

class cFEVObj_001B6C98 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline void PlayLabel_001B6C98(void* self, char* label)
{
    int frame = cUIScreen_getFrameByLabel(*(cUIScreen**)((char*)self + 0x40), GetHashValue32(label));
    if (frame != 0xFFFF) {
        cUIScreen_playFrame(*(void**)((char*)self + 0x40), frame, 1);
    }
}

extern "C" int func_001B6C98(void* self, int on)
{
    if (on) {
        if (func_002C24D0(*(void**)((char*)self + 0x6D4)) == 0) {
            PlayLabel_001B6C98(self, D_004A1BC0);
            (*(cFEVObj_001B6C98**)((char*)self + 0x6DC))->v09(0);
        } else {
            PlayLabel_001B6C98(self, D_004A1BC8);
            func_003A0D00(*(void**)((char*)self + 0x6DC), *(void**)((char*)self + 0x6D4));
        }
        if (func_002C24D0(*(void**)((char*)self + 0x6D0)) == 0) {
            (*(cFEVObj_001B6C98**)((char*)self + 0x6E0))->v09(0);
        } else {
            func_003A0D00(*(void**)((char*)self + 0x6E0), *(void**)((char*)self + 0x6D0));
        }
        if (func_002C24D0(*(void**)((char*)self + 0x6D8)) == 0) {
            (*(cFEVObj_001B6C98**)((char*)self + 0x6E4))->v09(0);
        } else {
            func_003A0D00(*(void**)((char*)self + 0x6E4), *(void**)((char*)self + 0x6D8));
        }
        PlayLabel_001B6C98(self, D_004642D0);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6E10);
#ifdef SKIP_ASM
class func_001B6E10_cObj {
public:
    char pad[0x8];
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
    virtual int v06(int, int);
    virtual int v07(int, int);
    virtual int v08(int, int);
    virtual int v09(int, int);
    virtual int v10(int, int);
    virtual int v11(int, int);
    virtual int v12(int, int);
    virtual int v13(int, int);
    virtual int v14(int, int);
    virtual int v15(int, int);
    virtual int v16(int, int);
    virtual int v17(int, int);
    virtual int v18(int, int);
    virtual int v19(int, int);
    virtual int v20(int, int);
    virtual int v21(int, int);
    virtual int v22(int, int);
    virtual int v23(int, int);
    virtual int v24(int, int);
};

extern "C" int func_001B6E10(void* self, int a1, int a2)
{
    return (*(func_001B6E10_cObj**)((char*)self + 0x20))->v24(a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6E40);
#ifdef SKIP_ASM
class cFEVObj_001B6E40 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v17(void* sender, int msg);
};

extern "C" void func_001A8918(void* self, int a1, int msg);

extern "C" void func_001B6E40(void* self, int a1, unsigned int msg)
{
    switch (msg) {
    case 5:
    case 6:
        (*(cFEVObj_001B6E40**)((char*)self + 0x20))->v17(self, 0xF);
        break;
    case 7:
    case 8:
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B6EA8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B6ED0);
#ifdef SKIP_ASM
extern "C" void* func_001ABF70(void* self);
extern "C" void* func_001B70D0(void*, int);
// PORT: the unit declares func_001B70D0 as returning void*; it returns nothing useful
extern "C" void func_001B70D0_v(void* self, int state) __asm__("func_001B70D0");
extern "C" void func_00265880();
extern "C" char* strcpy(char* dst, const char* src);
extern void* D_004687D0[];
extern char D_00536760[];

static inline void SetNames_001B6ED0(char* buf1, char* buf2, const char* a, const char* b)
{
    if (a) {
        strcpy(buf1, a);
    }
    if (b) {
        strcpy(buf2, b);
    }
}

// PORT: the unit declares the two name pointers as int
extern "C" void* func_001B6ED0(void* self, int a1, void* owner, int mode, int name, int name2)
{
    char* buf1 = (char*)self + 0x6E0;
    func_001ABF70(self);
    char* buf2 = (char*)self + 0x6F1;
    *(void***)((char*)self + 0x8) = D_004687D0;
    *((char*)self + 0x6E0) = 0;
    *((char*)self + 0x6F1) = 0;
    *(int*)((char*)self + 0x6D4) = 0;
    *(int*)((char*)self + 0x6D8) = 0;
    *(int*)((char*)self + 0xB04) = 0;
    *(int*)((char*)self + 0xB08) = 0;
    SetNames_001B6ED0(buf1, buf2, (const char*)name, (const char*)name2);
    switch (mode) {
    case 0:
        func_001B70D0_v(self, 0);
        *(int*)((char*)self + 0xB0C) = 0;
        break;
    case 1:
        func_001B70D0_v(self, 5);
        *(int*)((char*)self + 0xB0C) = 5;
        break;
    case 2:
        func_001B70D0_v(self, 0xB);
        *(int*)((char*)self + 0xB0C) = 0xB;
        break;
    case 3:
        SetNames_001B6ED0(buf1, buf2, D_00536760, D_00536760 + 0x11);
        func_001B70D0_v(self, 0x13);
        *(int*)((char*)self + 0xB0C) = 0x13;
        break;
    }
    func_00265880();
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7030);
#ifdef SKIP_ASM
extern void* D_004687D0[];
extern void* D_0046B6F8[];
extern "C" void func_002658B8();
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001B7030(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_004687D0;
    func_002658B8();
    *(void***)((char*)self + 0x8) = D_0046B6F8;
    func_001A85D0_dtor(self, flags);
}
#endif

extern "C" void* func_001ABFA8(void* self);

//99.29%
INCLUDE_ASM("fe/feasyncfile", func_001B7088__FPv);
#ifdef SKIP_ASM
void* func_001B7088(void* self)
{
    return func_001ABFA8(self);
}
#endif

extern "C" void* func_001B7778(void*);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B70A8__FPv);
#ifdef SKIP_ASM
void* func_001B70A8(void* self)
{
    int t0 = 0;
    *(signed char*)((char*)self + 0x6e0) = (signed char)t0;
    *(signed char*)((char*)self + 0x6f1) = (signed char)t0;
    return func_001B7778(self);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B70D0);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7650);
#ifdef SKIP_ASM
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);

extern "C" void func_001B7650(void* self, int a1, int a2, int b0, int b1, int a5, int a6)
{
    void* p = func_001A9C50(self);
    char* sub = (char*)p + 0xBC;
    if (b0 != 0) {
        if (b1 != 0) {
            *(int*)((char*)p + 0xBC) = 2;
            func_001C57C0(sub, 0, b0);
            func_001C57C0(sub, 1, b1);
            *(int*)((char*)p + 0x168) = a2;
        } else {
            *(int*)((char*)p + 0xBC) = 1;
            func_001C57C0(sub, 0, b0);
            *(int*)((char*)p + 0x168) = 0;
        }
    } else {
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x168) = 0;
    }
    if (a5 != 0) {
        *(int*)(sub + 0x10) = a5;
        *(int*)(sub + 0xC) = 1;
    }
    if (a6 != 0) {
        *(int*)(sub + 0x8) = a6;
        *(int*)(sub + 0x4) = 1;
    }
    *(int*)(sub + 0x94) = a1;
    *(int*)(sub + 0xA8) = 0;
    *(int*)(sub + 0x98) = 1;
    func_001A9BC0(self, p);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7778);
#ifdef SKIP_ASM
extern "C" void func_00265F18(void*);
extern "C" void* func_00265F68(void*);

extern "C" void* func_001B7778(void* self)
{
    func_00265F18((char*)self + 0x6E0);
    return func_00265F68((char*)self + 0x6F1);
}
#endif

extern "C" void* func_001B70D0(void*, int);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B77A8__FPv);
#ifdef SKIP_ASM
void* func_001B77A8(void* self)
{
    return func_001B70D0(self, 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B77C8);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B77C8(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B77C8(void* self)
{
    if (IsMode_001B77C8(4)) {
        func_001B70D0(self, 4);
    } else if (IsMode_001B77C8(5)) {
        if (*(int*)((char*)self + 0x6D4) == 1) {
            func_001B70D0(self, 4);
        } else {
            func_001B70D0(self, 3);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7820);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);
extern "C" int func_00265CB0(void* p);

static inline bool IsMode_001B7820(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7820(void* self)
{
    if (IsMode_001B7820(4)) {
        func_001B70D0(self, 7);
    } else if (IsMode_001B7820(5)) {
        if (*(int*)((char*)self + 0x6D4) == 2 && func_00265CB0(D_004A33D0) != 0) {
            func_001B70D0(self, 0xD);
        } else if (*(int*)((char*)self + 0x6D4) == 1) {
            func_001B70D0(self, 0x10);
        } else if (*(int*)((char*)self + 0x6D4) == 5) {
            func_001B70D0(self, 0x19);
        } else if (*(int*)((char*)self + 0x6D4) == 6) {
            func_001B70D0(self, 0x19);
        } else {
            func_001B70D0(self, 9);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B78F0);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B78F0(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B78F0(void* self)
{
    if (IsMode_001B78F0(8)) {
        func_001B70D0(self, 10);
    } else if (IsMode_001B78F0(9)) {
        func_001B70D0(self, 9);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7938);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);
extern "C" int func_00265CB0(void* p);

static inline bool IsMode_001B7938(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7938(void* self)
{
    if (IsMode_001B7938(4)) {
        func_001B70D0(self, 7);
    } else if (IsMode_001B7938(5)) {
        if (*(int*)((char*)self + 0x6D4) == 2 && func_00265CB0(D_004A33D0) != 0) {
            func_001B70D0(self, 0xD);
        } else if (*(int*)((char*)self + 0x6D4) == 1) {
            func_001B70D0(self, 0x10);
        } else if (*(int*)((char*)self + 0x6D4) == 5) {
            func_001B70D0(self, 0x19);
        } else if (*(int*)((char*)self + 0x6D4) == 6) {
            func_001B70D0(self, 0x19);
        } else {
            func_001B70D0(self, 0x11);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7A08);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B7A08(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7A08(void* self)
{
    if (IsMode_001B7A08(0x15)) {
        func_001B70D0(self, 0x10);
    } else if (IsMode_001B7A08(0x16)) {
        func_001B70D0(self, 0xF);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7A50);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B7A50(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7A50(void* self)
{
    if (IsMode_001B7A50(0xC)) {
        func_001B70D0(self, 0x12);
    } else if (IsMode_001B7A50(0xD)) {
        func_001B70D0(self, 0x11);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7A98);
#ifdef SKIP_ASM
extern "C" void* func_001B70D0(void*, int);
extern "C" int func_00265CB0(void* p);
extern "C" int func_004165A8(const char* a, const char* b);
extern int* D_004A33D0;
extern char D_00536760[];

static inline bool IsMode_001B7A98(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7A98(void* self)
{
    if (IsMode_001B7A98(4)) {
        if (func_004165A8(D_00536760, (char*)self + 0x6E0) != 0 || func_004165A8(D_00536760 + 0x11, (char*)self + 0x6F1) != 0) {
            *(int*)((char*)self + 0x6D4) = 0x18;
            *(int*)((char*)self + 0xB08) = 1;
            *(int*)((char*)self + 0x6D8) = 1;
            func_001B70D0(self, 0x17);
        } else {
            func_001B70D0(self, 0x15);
        }
    } else if (IsMode_001B7A98(5)) {
        int s = *(int*)((char*)self + 0x6D4);
        if (s == 1) {
            *(int*)((char*)self + 0xB08) = 1;
            *(int*)((char*)self + 0x6D8) = 1;
            *(int*)((char*)self + 0x6D4) = 0x18;
            func_001B70D0(self, 0x17);
        } else if (s == 5) {
            func_001B70D0(self, 0x15);
        } else if (s == 6) {
            func_001B70D0(self, 0x15);
        } else if (s == 2) {
            if (func_00265CB0(D_004A33D0) != 0) {
                *(int*)((char*)self + 0xB08) = 1;
                *(int*)((char*)self + 0x6D4) = 0x18;
            }
            func_001B70D0(self, 0x17);
            goto dflt;
        } else {
        dflt:
            func_001B70D0(self, 0x17);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7BC0);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);
void* func_001B70A8(void* self);

static inline bool IsMode_001B7BC0(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7BC0(void* self)
{
    if (IsMode_001B7BC0(0x10)) {
        func_001B70A8(self);
        func_001B70D0(self, 0x18);
    } else if (IsMode_001B7BC0(0x11)) {
        func_001B70D0(self, 0x17);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7C28);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B7C28(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7C28(void* self)
{
    if (IsMode_001B7C28(0x10)) {
        func_001B70D0(self, 0x1B);
    } else if (IsMode_001B7C28(0x11)) {
        func_001B70D0(self, 0x1C);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7C70);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void* func_001B70D0(void*, int);

static inline bool IsMode_001B7C70(int m)
{
    return *D_004A33D0 == m;
}

extern "C" void func_001B7C70(void* self)
{
    if (IsMode_001B7C70(0xC)) {
        func_001B70D0(self, 0x1D);
    } else if (IsMode_001B7C70(0xD)) {
        func_001B70D0(self, 0x1C);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B7CB8);
#ifdef SKIP_ASM
extern int* D_004A33D0;
extern "C" void func_00265A68(void* self);
extern "C" int func_00265D38(void* self);
extern "C" void func_002659E8(void* self);
extern "C" void* func_001B70D0(void*, int);
void* func_001B77A8(void* self);
extern "C" void func_001B77C8(void* self);
extern "C" void func_001B7820(void* self);
extern "C" void func_001B78F0(void* self);
extern "C" void func_001B7938(void* self);
extern "C" void func_001B7A08(void* self);
extern "C" void func_001B7A50(void* self);
extern "C" void func_001B7A98(void* self);
extern "C" void func_001B7BC0(void* self);
extern "C" void func_001B7C28(void* self);
extern "C" void func_001B7C70(void* self);

// Polls the memory card, then runs the step handler for the current memory-card state.
extern "C" void func_001B7CB8(void* self)
{
    func_00265A68(D_004A33D0);
    int* mc = D_004A33D0;
    *(int*)((char*)self + 0x6D4) = mc[1];
    if (func_00265D38(mc) != 0) {
        *(int*)((char*)self + 0x6D8) = 1;
        if (*(int*)((char*)self + 0x6D4) == 0) {
            *(int*)((char*)self + 0x6D4) = 2;
        }
    }
    switch (*(int*)((char*)self + 0x6DC)) {
    case 0: func_001B70D0(self, 1); break;
    case 1: func_001B77A8(self); break;
    case 2: func_001B77C8(self); break;
    case 5: func_001B70D0(self, 6); break;
    case 6: func_001B7820(self); break;
    case 8: func_001B78F0(self); break;
    case 11: func_001B70D0(self, 0xC); break;
    case 12: func_001B7938(self); break;
    case 14: func_001B7A08(self); break;
    case 16: func_001B7A50(self); break;
    case 19: func_001B70D0(self, 0x14); break;
    case 20: func_001B7A98(self); break;
    case 22: func_001B7BC0(self); break;
    case 7: case 13: case 21: case 25: func_002659E8(D_004A33D0); break;
    case 26: func_001B7C28(self); break;
    case 27: func_001B7C70(self); break;
    case 28: case 29: break;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B7E40);

INCLUDE_ASM("fe/feasyncfile", func_001B8238);

INCLUDE_ASM("fe/feasyncfile", func_001B83C0);

INCLUDE_ASM("fe/feasyncfile", func_001B84D8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B8860);
#ifdef SKIP_ASM
class func_001B8860_cObj {
public:
    char pad[0x8];
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
    virtual int v06(int, int);
    virtual int v07(int, int);
    virtual int v08(int, int);
    virtual int v09(int, int);
    virtual int v10(int, int);
    virtual int v11(int, int);
    virtual int v12(int, int);
    virtual int v13(int, int);
    virtual int v14(int, int);
    virtual int v15(int, int);
    virtual int v16(int, int);
    virtual int v17(int, int);
    virtual int v18(int, int);
    virtual int v19(int, int);
    virtual int v20(int, int);
    virtual int v21(int, int);
    virtual int v22(int, int);
    virtual int v23(int, int);
    virtual int v24(int, int);
};

extern "C" int func_001B8860(void* self, int a1, int a2)
{
    return (*(func_001B8860_cObj**)((char*)self + 0x20))->v24(a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B8890);
#ifdef SKIP_ASM
extern "C" int func_001B8890(void* self, int id)
{
    switch (id) {
    case 25:
        return 28;
    case 13:
        return 15;
    case 21:
        return 23;
    case 7:
        return 9;
    }
    return 28;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B88F0);
#ifdef SKIP_ASM
extern void* D_004686C0[];
extern int D_004A3E90;
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001B88F0(void* self, int a1, int a2)
{
    func_001A8500_3(self, a1, 0);
    int d = D_004A3E90;
    *(int*)((char*)self + 0x6F0) = 0;
    *(void***)((char*)self + 0x8) = D_004686C0;
    *(int*)((char*)self + 0x6D4) = d;
    *(int*)((char*)self + 0x6D8) = d;
    *(int*)((char*)self + 0x6DC) = d;
    if (a2 != 0) {
        *(int*)((char*)self + 0xC) = 0x4D;
    } else {
        *(int*)((char*)self + 0xC) = 0x50;
    }
    *(int*)((char*)self + 0x6EC) = a2;
    *(int*)((char*)self + 0x6A8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B8960);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void func_001A8768(void* self);
extern char D_00464740[];
extern void* D_004A3028;

extern "C" void func_001B8960(void* self)
{
    if (*(int*)((char*)self + 0x6EC) != 0) {
        *(char**)((char*)self + 0x6D0) = (char*)D_004A3028 + 0x260;
    } else {
        *(char**)((char*)self + 0x6D0) = (char*)D_004A3028 + 0x2B0;
    }
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00464740), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001A8768(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B89E8__FPv);
#ifdef SKIP_ASM
void* func_001B89E8(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B8A08);
#ifdef SKIP_ASM
struct sVE1B8A08 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" bool func_001B9558(void* self);
extern "C" void func_001B95C0(void* self);
extern "C" void func_001B9610(void* self);
extern "C" void func_001B9678(void* self);
extern "C" void func_001B96E0(void* self);
extern "C" void func_001B9740(void* self);
extern "C" void func_001B97B0(void* self);
extern "C" void func_001BA178(void* self);

extern "C" int func_001B8A08(void* self, int a1)
{
    if (a1 != 0) {
        func_001B95C0(self);
        func_001B9610(self);
        func_001B9678(self);
        func_001B96E0(self);
        func_001B97B0(self);
        func_001B9740(self);
        func_001BA178(self);
        void* obj = *(void**)((char*)self + 0x6F0);
        if (obj != 0) {
            sVE1B8A08* vt = *(sVE1B8A08**)((char*)obj + 0x8);
            void* o = (char*)obj + vt[8].delta;
            vt[8].fn(o, !func_001B9558(self));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B8AA0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00461520[];
extern char D_00462B88[];
extern char D_004631D8[];
extern char D_00464750[];
extern char D_00464768[];
extern char D_00464780[];
extern char D_00464790[];
extern char D_004647A8[];

class cFEVObj_001B8AA0 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
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
    virtual void v25(int on);
};

static inline int IsHash1B8AA0(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001B8AA0(void* self, cUIText* text)
{
    cFEVObj_001B8AA0* obj = (cFEVObj_001B8AA0*)text;
    if (IsHash1B8AA0(*(int*)((char*)text + 0x38), D_00461520)) {
        if (*(int*)((char*)self + 0x6EC) == 0) {
            cUIText_setUnicodeStringByID(text, GetHashValue32(D_00464750));
        }
    } else if (IsHash1B8AA0(*(int*)((char*)text + 0x38), D_00464768) || IsHash1B8AA0(*(int*)((char*)text + 0x38), D_00462B88)) {
        if (*(int*)((char*)self + 0x6EC) == 0) {
            obj->v25(1);
            obj->v08(1);
        }
    } else if (IsHash1B8AA0(*(int*)((char*)text + 0x38), D_00464780) || IsHash1B8AA0(*(int*)((char*)text + 0x38), D_00464790)) {
        func_001A9A18(self, (cUIListBox_001A9A18*)text, 1);
    } else if (IsHash1B8AA0(*(int*)((char*)text + 0x38), D_004647A8)) {
        if (*(int*)((char*)self + 0x6EC) != 0) {
            obj->v25(1);
            obj->v08(1);
        } else {
            cUIText_setUnicodeStringByID(text, GetHashValue32(D_004631D8));
        }
        *(cUIText**)((char*)self + 0x6F0) = text;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B8C38);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9088);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_004648A8[];
extern char D_004648C8[];
extern char D_004648E0[];
extern char D_004648F8[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00462C50[];
extern char D_004614E8[];
extern char D_00464910[];
extern char D_00464930[];

extern "C" void func_001B9088(void* self, void* menu)
{
    func_001DA528(menu, 5);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_004648A8);
    func_001DA530(menu, 0, GetHashValue32(D_004648C8));
    func_001DA530(menu, 1, GetHashValue32(D_004648E0));
    func_001DA530(menu, 2, GetHashValue32(D_004648F8));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(menu, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(menu, 3, GetHashValue32(D_004614E8), 1);
    func_001DA510(menu, 4, GetHashValue32(D_00464910), 2);
    *(int*)((char*)menu + 0x64) = GetHashValue32(D_00464930);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B91C8);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void* func_001AD130(void* self, int a1);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00462D10[];
extern const char D_00462D68[];

extern "C" void func_001B91C8(void* self, void* a1, int kind)
{
    switch ((unsigned int)kind) {
    case 15: {
        func_001A97B8(self, a1, 15);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 1,
                                (*(int**)((char*)self + 0x6D0))[0], (*(int**)((char*)self + 0x6D0))[1]);
        *(int*)((char*)p + 0x18) = 0x82C;
        func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        break;
    }
    case 16:
    case 20:
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B92C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* func_001AD130(void* mem, int a1);
extern const char D_00462D68[];
extern char D_00462D80[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

// Tracks a pending flag across messages; on 0x16 either asks for confirmation or opens the next screen.
extern "C" void func_001B92C8(void* self, void* a1, int a2)
{
    switch (a2) {
    case 0xF: case 0x10: case 0x14:
        *(int*)((char*)self + 0x6E8) = 0;
        func_001A97B8(self, a1, a2);
        break;
    case 0x11:
        *(int*)((char*)self + 0x6E8) = 1;
        func_001A97B8(self, a1, a2);
        break;
    case 0x16:
        if (*(int*)((char*)self + 0x6E8) != 0) {
            func_001A97B8(self, a1, a2);
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 2;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0x150) = 0x81E;
            *(int*)((char*)p + 0x168) = 0;
            *(int*)((char*)p + 0x164) = 0;
            func_001A9BC0(self, p);
        } else {
            func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        }
        *(int*)((char*)self + 0x6E8) = 0;
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B9428);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001B91C8(void* self, void* a1, int a2);
extern "C" void func_001B92C8(void* self, void* a1, int a2);

extern "C" void func_001B9428(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x81E:
        func_001B91C8(self, a1, a2);
        break;
    case 0x82C:
        func_001B92C8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9488);
#ifdef SKIP_ASM
// PORT: unit declares func_001A8E40 with one arg; the handler passes (self, a1, a2) through
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern char D_00462D80[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

extern "C" int func_001B9488(void* self, int a1, int a2)
{
    if (a1 == 0xCE) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 2;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
        func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
        *(int*)((char*)p + 0x168) = 0;
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x81E;
        func_001A9BC0(self, p);
        return -1;
    }
    return func_001A8E40_3i(self, a1, a2);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001B9558);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B95C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00462B88[];
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);

extern "C" void func_001B95C0(void* self)
{
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462B88));
    if (text != 0) {
        cUIText_setAsciiString(text, **(const char***)((char*)self + 0x6D0));
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B9610);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00462BA0[];
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001A98B8(void* self, const char* str);

extern "C" void func_001B9610(void* self)
{
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00462BA0));
    if (text != 0) {
        func_001A98B8(self, (*(const char***)((char*)self + 0x6D0))[1]);
        cUIText_setAsciiString(text, (char*)self + 0x5C);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001B9678);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004647F8[];
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001A98B8(void* self, const char* str);

extern "C" void func_001B9678(void* self)
{
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004647F8));
    if (text != 0) {
        func_001A98B8(self, (*(const char***)((char*)self + 0x6D0))[2]);
        cUIText_setAsciiString(text, (char*)self + 0x5C);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B96E0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00464838[];
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001B9950(void* self, cUIText* text, char* str);

extern "C" void func_001B96E0(void* self)
{
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464838));
    if (text != 0) {
        char* s = (*(char***)((char*)self + 0x6D0))[3];
        if (*(int*)(s - 8) != 0) {
            func_001B9950(self, text, s);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9740);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464780[];

extern "C" void func_001B9740(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464780));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x38) != 0, &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B97B0);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464790[];

extern "C" void func_001B97B0(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464790));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x3C) != 0, &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9820);
#ifdef SKIP_ASM
struct cUIText;
extern "C" void* cBXString_cBXString4(void* self, const char* str);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void func_001A98B8(void* self, const char* str);
extern "C" void func_001B9950(void* self, cUIText* text, char* str);

extern "C" void func_001B9820(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    switch (*(unsigned int*)(p + 0x18)) {
    case 11:
        if (*(cUIText**)((char*)self + 0x6A4) != 0) {
            func_001A98B8(self, p + 0x74);
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6A4), (char*)self + 0x5C);
        }
        cBXString_cBXString4(*(char**)((char*)self + 0x6D0) + 0x4, *(char**)((char*)self + 0x69C) + 0x74);
        break;
    case 12:
        if (*(cUIText**)((char*)self + 0x6A4) != 0) {
            func_001A98B8(self, p + 0x74);
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6A4), (char*)self + 0x5C);
        }
        cBXString_cBXString4(*(char**)((char*)self + 0x6D0) + 0x8, *(char**)((char*)self + 0x69C) + 0x74);
        break;
    case 10:
        if (*(cUIText**)((char*)self + 0x6A4) != 0) {
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6A4), p + 0x74);
        }
        cBXString_cBXString4(*(char**)((char*)self + 0x6D0), *(char**)((char*)self + 0x69C) + 0x74);
        break;
    case 13: {
        cBXString_cBXString4(*(char**)((char*)self + 0x6D0) + 0xC, p + 0x74);
        char* s = *(char**)(*(char**)((char*)self + 0x6D0) + 0xC);
        if (((int*)s)[-2] != 0) {
            func_001B9950(self, *(cUIText**)((char*)self + 0x6A4), s);
        }
        break;
    }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9950);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" char* func_003A04F0(void* text);
extern "C" char* func_004162D0(char*, const char*);
extern char D_004A1BD0[];

struct sVec3_1B9950 {
    float x, y, z;
};

struct sVec2_1B9950 {
    float x, y;
    sVec2_1B9950(float x_, float y_) : x(x_), y(y_) {}
};

struct sRect1B9950 {
    float x, y, w, h;
};

class cFEVObj_001B9950 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual void v20(sRect1B9950* out);
};

static inline void Measure1B9950(cUIText* text, const char* s, sRect1B9950* out)
{
    char* f = func_003A04F0(text);
    func_00391FB0(f, s, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
}

extern "C" void func_001B9950(void* self, cUIText* text, char* str)
{
    int cut = 0;
    sVec3_1B9950 scale = *(sVec3_1B9950*)((char*)text + 0x50);
    sRect1B9950 box;
    ((cFEVObj_001B9950*)text)->v20(&box);
    char* f = func_003A04F0(text);
    float sx = scale.x;
    float sy = scale.y;
    *(float*)(f + 0x38) = *(float*)(f + 0x30) * sx;
    *(float*)(f + 0x3C) = *(float*)(f + 0x34) * sy;
    int i = strlen(str) - 1;
    char buf[0x50];
    strcpy(buf, str);
    const char* ell = D_004A1BD0;
    sRect1B9950 sz;
    sRect1B9950 dots;
    Measure1B9950(text, ell, &dots);
    Measure1B9950(text, buf, &sz);
    while (box.x - dots.w < sz.w) {
        cut = 1;
        buf[i--] = 0;
        Measure1B9950(text, buf, &sz);
    }
    if (cut) {
        func_004162D0(buf, ell);
        cUIText_setAsciiString(text, buf);
    } else {
        cUIText_setAsciiString(text, str);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9B18);
#ifdef SKIP_ASM
struct sObj1B9B18 {
    char data[0xD0];
};

int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* func_001C55F8(void* self);
extern "C" void func_001C5750(void* self, int flags);
extern "C" int func_001B9CD8(void* self, const char* str);
extern "C" int strlen(const char* s);
extern char D_00462BF0[];
extern char D_004624D0[];
extern char D_00464960[];
extern char D_00461618[];

extern "C" int func_001B9B18(void* self)
{
    int ok = 1;
    sObj1B9B18 o;
    func_001C55F8(&o);
    int len = strlen(*(const char**)(*(char**)((char*)self + 0x6D0) + 0xC));
    if (len == 0) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BF0);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    }
    if (len < 7) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004624D0);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    } else if (!func_001B9CD8(self, *(const char**)(*(char**)((char*)self + 0x6D0) + 0xC))) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464960);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    }
    func_001C5750(&o, 2);
    return ok;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9CD8);
#ifdef SKIP_ASM
extern "C" int strlen(const char* s);

extern "C" int func_001B9CD8(void* self, const char* str)
{
    int hasAt = 0;
    int hasDot = 0;
    int len = strlen(str);
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] == '@') {
            hasAt = 1;
        } else if (str[i] == '.') {
            hasDot = 1;
        }
    }
    return hasAt && hasDot;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9D68);
#ifdef SKIP_ASM
struct sObj1B9D68 {
    char data[0xD0];
};

int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* func_001C55F8(void* self);
extern "C" void func_001C5750(void* self, int flags);
extern "C" int func_001B9F68(void* self, signed char val, signed char lo, signed char hi);
extern "C" int strlen(const char* s);
extern char D_00462BD0[];
extern char D_004624B0[];
extern char D_00464978[];
extern char D_00461618[];

extern "C" int func_001B9D68(void* self)
{
    int ok = 1;
    sObj1B9D68 o;
    func_001C55F8(&o);
    int len = strlen(**(const char***)((char*)self + 0x6D0));
    if (len == 0) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BD0);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    } else if (len < 4 || len > 16) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004624B0);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    } else {
        signed char c0 = (**(signed char***)((char*)self + 0x6D0))[0];
        if (c0 > '0') {
            if (c0 < '9') {
                void* p = func_001A9C50(self);
                *(int*)((char*)p + 0xBC) = 1;
                char* sub = (char*)p + 0xBC;
                *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464978);
                ok = 0;
                *(int*)((char*)p + 0xC0) = 3;
                func_001C57C0(sub, 0, GetHashValue32(D_00461618));
                *(int*)((char*)p + 0x150) = 0x80D;
                func_001A9BC0(self, p);
                goto done;
            }
        }
        int i;
        for (i = 0; i < len; i++) {
            signed char c = (**(signed char***)((char*)self + 0x6D0))[i];
            if (c != ' ' && !func_001B9F68(self, c, '0', '9') && !func_001B9F68(self, c, 'a', 'z') && !func_001B9F68(self, c, 'A', 'Z')) {
                ok = 0;
                void* p = func_001A9C50(self);
                *(int*)((char*)p + 0xBC) = 1;
                char* sub = (char*)p + 0xBC;
                *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464978);
                *(int*)((char*)p + 0xC0) = 3;
                func_001C57C0(sub, 0, GetHashValue32(D_00461618));
                *(int*)((char*)p + 0x150) = 0x80D;
                func_001A9BC0(self, p);
                break;
            }
        }
    }
done:
    func_001C5750(&o, 2);
    return ok;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9F68);
#ifdef SKIP_ASM
extern "C" int func_001B9F68(void* self, signed char val, signed char lo, signed char hi)
{
    if (val <= hi && val >= lo) {
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001B9FA0);
#ifdef SKIP_ASM
struct sObj1B9FA0 {
    char data[0xD0];
};

int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* func_001C55F8(void* self);
extern "C" void func_001C5750(void* self, int flags);
extern "C" int func_004165A8(const char* a, const char* b);
extern "C" int strlen(const char* s);
extern char D_00462BB0[];
extern char D_00464998[];
extern char D_004649B8[];
extern char D_00461618[];

extern "C" int func_001B9FA0(void* self)
{
    int ok = 1;
    sObj1B9FA0 o;
    func_001C55F8(&o);
    unsigned int len = strlen(*(const char**)(*(char**)((char*)self + 0x6D0) + 4));
    if (len == 0) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462BB0);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    } else if (len - 4 > 12) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464998);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    } else if (func_004165A8(*(const char**)(*(char**)((char*)self + 0x6D0) + 4), *(const char**)(*(char**)((char*)self + 0x6D0) + 8))) {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004649B8);
        ok = 0;
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
    }
    func_001C5750(&o, 2);
    return ok;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BA110);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA178);
#ifdef SKIP_ASM
extern "C" void* cBXString_operatorE(void* self, void* other);
extern "C" void cBXString_Reset(void* self);

extern "C" void func_001BA178(void* self)
{
    if (*(int*)((char*)self + 0x6EC) == 0) {
        cBXString_operatorE((char*)self + 0x6D4, *(char**)((char*)self + 0x6D0) + 0x4);
        cBXString_operatorE((char*)self + 0x6D8, *(char**)((char*)self + 0x6D0) + 0x8);
        cBXString_operatorE((char*)self + 0x6DC, *(char**)((char*)self + 0x6D0) + 0xC);
        char* d = *(char**)((char*)self + 0x6D0);
        *(int*)((char*)self + 0x6E0) = *(int*)(d + 0x38);
        *(int*)((char*)self + 0x6E4) = *(int*)(d + 0x3C);
    } else {
        cBXString_Reset((char*)self + 0x6D4);
        cBXString_Reset((char*)self + 0x6D8);
        cBXString_Reset((char*)self + 0x6DC);
    }
    *(int*)(*(char**)((char*)self + 0x6D0) + 0x4C) = 0;
    *(int*)(*(char**)((char*)self + 0x6D0) + 0x44) = 0;
    *(int*)(*(char**)((char*)self + 0x6D0) + 0x48) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA218);
#ifdef SKIP_ASM
extern "C" void* cBXString_operatorE(void* self, void* other);

extern "C" void func_001BA218(void* self)
{
    cBXString_operatorE(*(char**)((char*)self + 0x6D0) + 0x4, (char*)self + 0x6D4);
    cBXString_operatorE(*(char**)((char*)self + 0x6D0) + 0x8, (char*)self + 0x6D8);
    cBXString_operatorE(*(char**)((char*)self + 0x6D0) + 0xC, (char*)self + 0x6DC);
    *(int*)(*(char**)((char*)self + 0x6D0) + 0x38) = *(int*)((char*)self + 0x6E0);
    *(int*)(*(char**)((char*)self + 0x6D0) + 0x3C) = *(int*)((char*)self + 0x6E4);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA280);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001AD130(void* self, int a1);
extern "C" void func_001BA358(void* self);
extern "C" void func_0025BF18(void* self, void* a1);
extern void* D_004A3028;
extern const char D_00462D68[];
extern char D_004649D8[];

extern "C" void func_001BA280(void* self)
{
    func_001BA358(self);
    char* p = *(char**)((char*)self + 0x6D0);
    if (*(int*)(p + 0x4C) == 0 && *(int*)(p + 0x44) == 0 && *(int*)(p + 0x48) == 0) {
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
    } else {
        void* pp = func_001A9C50(self);
        *(int*)((char*)pp + 0xBC) = 0;
        *(int*)((char*)pp + 0xC4) = GetHashValue32(D_004649D8);
        *(int*)((char*)pp + 0xC0) = 3;
        *(int*)((char*)pp + 0x150) = 0x81D;
        *(int*)((char*)pp + 0x164) = 0;
        func_001A9BC0(self, pp);
        func_0025BF18(D_004A3028, *(void**)((char*)self + 0x6D0));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA358);
#ifdef SKIP_ASM
extern "C" int func_004165A8(const char* a, const char* b);

extern "C" void func_001BA358(void* self)
{
    if (func_004165A8(*(char**)(*(char**)((char*)self + 0x6D0) + 0x4), *(char**)((char*)self + 0x6D4)) != 0) {
        *(int*)(*(char**)((char*)self + 0x6D0) + 0x44) = 1;
    }
    if (func_004165A8(*(char**)(*(char**)((char*)self + 0x6D0) + 0xC), *(char**)((char*)self + 0x6DC)) != 0) {
        *(int*)(*(char**)((char*)self + 0x6D0) + 0x4C) = 1;
    }
    char* d = *(char**)((char*)self + 0x6D0);
    if (*(int*)(d + 0x38) != *(int*)((char*)self + 0x6E0) || *(int*)(d + 0x3C) != *(int*)((char*)self + 0x6E4)) {
        *(int*)(d + 0x48) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA3E0);
#ifdef SKIP_ASM
extern void* D_004685B0[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001BA3E0(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x4E;
    *(void***)((char*)self + 0x8) = D_004685B0;
    *(int*)((char*)self + 0x6A8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA428);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void func_001A8768(void* self);
extern "C" void func_001BB2D0(void* self);
extern "C" void func_001BB340(void* self);
extern "C" void func_001BB3B0(void* self);
extern "C" void func_001BB440(void* self);
extern "C" void func_001BB4B0(void* self);
extern void* D_004A3028;
extern char D_004649F8[];

struct sFEObj_001BA428 {
    char pad0[0x10];
    void* engine;       // 0x10
    char pad14[0x40 - 0x14];
    void* screen;       // 0x40
    char pad44[0x6D0 - 0x44];
    char* f6D0;         // 0x6D0
    int f6D4;           // 0x6D4
    int pad6D8;
    int f6DC;           // 0x6DC
};

extern "C" void func_001BA428(sFEObj_001BA428* self)
{
    self->f6D4 = 0;
    self->f6D0 = (char*)D_004A3028 + 0x260;
    void* engine = self->engine;
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004649F8), 0);
    self->screen = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)(self->f6D0 + 0x40) = 0;
    self->f6DC = 0;
    func_001BB2D0(self);
    func_001BB340(self);
    func_001BB3B0(self);
    func_001BB440(self);
    func_001BB4B0(self);
    func_001A8768(self);
    self->f6D4 = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA4E0__FPv);
#ifdef SKIP_ASM
void* func_001BA4E0(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA500);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001BB520(void* self, void* box, int flag);
extern "C" void func_001BB5D0(void* self, void* box, int a2);
extern "C" void func_001BB798(void* self, void* box, int value);
extern "C" void func_001BB840(void* self, void* box, int a2, int a3, int a4);
extern char D_00464A08[];
extern char D_004A1BD8[];
extern char D_004A1BE0[];
extern char D_004A1BE8[];
extern char D_00464A18[];

static inline int IsHash1BA500(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001BA500(void* self, void* box)
{
    if (IsHash1BA500(*(int*)((char*)box + 0x38), D_00464A08)) {
        func_001A9A18(self, (cUIListBox_001A9A18*)box, 0);
    } else if (IsHash1BA500(*(int*)((char*)box + 0x38), D_004A1BD8)) {
        func_001BB5D0(self, box, 1);
    } else if (IsHash1BA500(*(int*)((char*)box + 0x38), D_004A1BE0)) {
        func_001BB840(self, box, 1, 0x7C1, 1);
    } else if (IsHash1BA500(*(int*)((char*)box + 0x38), D_004A1BE8)) {
        func_001BB798(self, box, 0x7C1);
    } else if (IsHash1BA500(*(int*)((char*)box + 0x38), D_00464A18)) {
        func_001BB520(self, box, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA618);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void cBXString_Reset(void* self);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void cUIListBox_setEntryByAsciiString(void* box, int index, const char* str, int a3);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void* func_001B88F0(void* self, int a1, int a2);
extern "C" void func_001BA9F8(void* self, int a1);
extern "C" void func_001BB840(void* self, void* box, int a2, int a3, int a4);
int func_001BBAA8(void* self);
extern "C" void* func_001C0418(void* self, int a1);
extern "C" int func_0039A738(void* a);
extern char D_004A1BD8[];
extern char D_004A1BE0[];
extern char D_004A1BE8[];
extern char D_004A12C0[];
extern char D_00464A08[];
extern char D_00464A18[];
extern char D_00464A28[];
extern char D_00462ED0[];
extern char D_00464860[];

static inline int IsHash_001BA618(int id, char* name) { return id == GetHashValue32(name); }

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001BA618(void* self, int a1, unsigned int msg)
{
    char* s = (char*)self;
    char* obj = (char*)a1;
    switch (msg) {
    case 9:
        if (*(int*)(s + 0x6D4) != 0) {
            if (IsHash_001BA618(*(int*)(obj + 0x38), D_004A1BD8)) {
                *(int*)(*(char**)(s + 0x6D0) + 0x28) = func_0039A738(obj);
                cUIText* box = cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004A1BE0));
                if (box != 0) {
                    char* d = *(char**)(s + 0x6D0);
                    func_001BB840(self, box, *(int*)(d + 0x28), *(int*)(d + 0x30), *(int*)(d + 0x2C));
                }
            }
            if (IsHash_001BA618(*(int*)(obj + 0x38), D_004A1BE8)) {
                char buf[16];
                *(int*)(*(char**)(s + 0x6D0) + 0x30) = *(unsigned char*)(obj + 0x319) + 0x76C;
                sprintf(buf, D_004A12C0, *(int*)(*(char**)(s + 0x6D0) + 0x30));
                cUIListBox_setEntryByAsciiString(obj, 0, buf, 0);
                cBXString_Reset(*(char**)(s + 0x6D0) + 0x10);
                cUIText* box = cUIScreen_getObjectByHashName(*(void**)(s + 0x40), GetHashValue32(D_004A1BE0));
                if (box != 0) {
                    char* d = *(char**)(s + 0x6D0);
                    func_001BB840(self, box, *(int*)(d + 0x28), *(int*)(d + 0x30), *(int*)(d + 0x2C));
                }
            }
            if (IsHash_001BA618(*(int*)(obj + 0x38), D_004A1BE0)) {
                *(int*)(*(char**)(s + 0x6D0) + 0x2C) = func_0039A738(obj);
            }
            if (IsHash_001BA618(*(int*)(obj + 0x38), D_00464A18)) {
                *(int*)(*(char**)(s + 0x6D0) + 0x34) = func_0039A738(obj);
            }
            if (IsHash_001BA618(*(int*)(obj + 0x38), D_00464A08)) {
                *(int*)(*(char**)(s + 0x6D0) + 0x40) = func_0039A738(obj) == 1;
            }
        }
        break;
    case 5:
        if (IsHash_001BA618(*(int*)(obj + 0x38), D_00464A28)) {
            if (func_001BBAA8(self) != 0) {
                func_001BA9F8(self, 1);
            }
        }
        break;
    case 6:
        func_001A8A40(self, func_001B88F0(cMemMan_alloc(0x6F4, D_00462ED0, 0, 0), *(int*)(s + 0x10), 1));
        break;
    case 8: {
        char* p = (char*)func_001C0418(cMemMan_alloc(0x6DC, D_00464860, 0x100, 0), *(int*)(s + 0x10));
        *(int*)(p + 0x18) = 0x16;
        func_001A8A40(self, p);
        break;
    }
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA8B8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_004648A8[];
extern char D_004648C8[];
extern char D_004648E0[];
extern char D_004648F8[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00462C50[];
extern char D_004614E8[];
extern char D_00464910[];
extern char D_00464930[];

extern "C" void func_001BA8B8(void* self, void* menu)
{
    func_001DA528(menu, 5);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_004648A8);
    func_001DA530(menu, 0, GetHashValue32(D_004648C8));
    func_001DA530(menu, 1, GetHashValue32(D_004648E0));
    func_001DA530(menu, 2, GetHashValue32(D_004648F8));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(menu, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(menu, 3, GetHashValue32(D_004614E8), 1);
    func_001DA510(menu, 4, GetHashValue32(D_00464910), 2);
    *(int*)((char*)menu + 0x64) = GetHashValue32(D_00464930);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BA9F8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void func_0025B6D8(void* self, int a1);
extern "C" void func_0025B9C8(void* self, void* a1);
extern char D_00464A38[];
extern void* D_004A3028;

extern "C" void func_001BA9F8(void* self, int a1)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 0;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464A38);
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x164) = 0;
    *(int*)((char*)p + 0x150) = 0x820;
    func_001A9BC0(self, p);
    if (a1 != 0) {
        func_0025B6D8(D_004A3028, 0);
    } else {
        func_0025B9C8(D_004A3028, (char*)D_004A3028 + 0x260);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BAA88);
#ifdef SKIP_ASM
extern "C" void func_001BB158(void* self, void* a1, unsigned int a2);
extern "C" void func_001BB0E8(void* self, void* a1, int a2);
extern "C" void func_001BB098(void* self, void* a1, int a2);
extern "C" void func_001BADE8(void* self, void* a1, int a2);
extern "C" void func_001BAED8(void* self, void* a1, int a2);
// Dispatches a message to the matching handler, falling back to the base handler.
extern "C" void func_001BAA88(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x81F:
        func_001BB158(self, a1, a2);
        break;
    case 0x821:
        func_001BB0E8(self, a1, a2);
        break;
    case 0x822:
        func_001BB098(self, a1, a2);
        break;
    case 0x80E:
        func_001BADE8(self, a1, a2);
        break;
    case 0x82C:
        func_001BAED8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BAB28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001AD130(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025B9C8(void* self, void* a1);
extern "C" void func_00260F10(void* self);
extern "C" void func_001BAC90(void* self, void* msg);
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
extern void* D_004A3028;
extern const char D_00462D68[];
extern char D_00464AD0[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

extern "C" int func_001BAB28(void* self, int id, int a2)
{
    switch (id) {
    case 0xC9:
        func_0025B9C8(D_004A3028, (char*)D_004A3028 + 0x260);
        break;
    case 0xCB: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 2;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464AD0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
        func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x81F;
        func_001A9BC0(self, p);
        break;
    }
    case 0xD4:
        func_00260F10(D_004A3028);
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0x102:
        func_001BAC90(self, (void*)a2);
        break;
    default:
        return func_001A8E40_3i(self, id, a2);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BAC90);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_001BBAC8(void* self, int state);
extern "C" void* func_001BBD08(void* self, int a1, int a2);
// PORT: unit declares func_001A8E40 with one arg; the real handler takes (self, id, msg)
extern "C" void* func_001A8E40_msg(void* self, int id, void* msg) __asm__("func_001A8E40");
extern char D_00463090[];
extern char D_00462338[];
extern char D_00461618[];

extern "C" void func_001BAC90(void* self, void* msg)
{
    switch (*(unsigned int*)((char*)msg + 8)) {
    case 0x6475706C:
        func_001A8A40(self, func_001BBD08(cMemMan_alloc(0x6E0, D_00463090, 0, 0), *(int*)((char*)self + 0x10), 1));
        break;
    case 0x746F6F79:
        func_001BBAC8(self, *(int*)((char*)msg + 0xC));
        break;
    case 0x706D616C:
        // PORT: string length lives in a header before the character data
        if (*(int*)(*(int*)(*(char**)((char*)self + 0x6D0) + 0x10) - 8) != 0) {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462338);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0x150) = 0x822;
            func_001A9BC0(self, p);
        } else {
            func_001BBAC8(self, 0x11);
        }
        break;
    default:
        func_001A8E40_msg(self, *(int*)msg, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BADE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
// func_001A97B8 returns void (its asm never sets $2); the unit declares it int
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00462D10[];
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001BADE8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001BADE8(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_001A97B8_v(self, a1, a2);
        func_00261408(GetSession_001BADE8());
        func_0025B800(D_004A3028);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
        *(int*)((char*)p + 0x18) = 0x832;
        func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
    } else {
        func_001A97B8_v(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BAED8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
// PORT: the unit declares func_001A97B8 as returning int; this caller ignores the result.
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_0025C610(void* net);
extern void* D_004A3028;
extern char D_00462D80[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_00462C70[];
extern char D_00462C88[];

// Tracks a pending flag; on 0x16 shows either the confirm popup or the network-connect popup.
extern "C" void func_001BAED8(void* self, void* a1, int a2)
{
    switch (a2) {
    case 0xF: case 0x10: case 0x14:
        *(int*)((char*)self + 0x6D8) = 0;
        func_001A97B8_v(self, a1, a2);
        break;
    case 0x11:
        *(int*)((char*)self + 0x6D8) = 1;
        func_001A97B8_v(self, a1, a2);
        break;
    case 0x16:
        func_001A97B8_v(self, a1, a2);
        if (*(int*)((char*)self + 0x6D8) != 0) {
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 2;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0x164) = 0;
            *(int*)((char*)p + 0x150) = 0x81F;
            func_001A9BC0(self, p);
        } else {
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 1;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462C70);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
            *(int*)((char*)p + 0x150) = 0x80E;
            func_001A9BC0(self, p);
            cBXString_cBXString4((char*)D_004A3028 + 0x48, **(char***)((char*)self + 0x6D0));
            cBXString_cBXString4((char*)D_004A3028 + 0x4C, (*(char***)((char*)self + 0x6D0))[1]);
            func_0025C610(D_004A3028);
        }
        *(int*)((char*)self + 0x6D8) = 0;
        break;
    default:
        func_001A97B8_v(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB098);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BBAC8(void* self, int state);

extern "C" void func_001BB098(void* self, void* a1, int a2)
{
    if (a2 == 0x16) {
        func_001A97B8(self, a1, a2);
        func_001BBAC8(self, 0x11);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB0E8);
#ifdef SKIP_ASM
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BA9F8(void* self, int a1);

extern "C" void func_001BB0E8(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8(self, a1, 0xF);
        cBXString_cBXString4(*(char**)((char*)self + 0x6D0) + 0x10, *(const char**)((char*)a1 + 0x2B0));
        func_001BA9F8(self, 0);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB158);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025C610(void* self);
extern "C" void func_0039F290(void* list, void* item);
extern void* D_004A3028;
extern char D_00462D10[];
extern char D_00462C70[];
extern char D_00462C88[];

extern "C" void func_001BB158(void* self, void* a1, unsigned int kind)
{
    switch (kind) {
    case 15: {
        func_001A97B8(self, a1, 15);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 1,
                                **(int**)((char*)self + 0x6D0), *(int*)(*(char**)((char*)self + 0x6D0) + 4));
        *(int*)((char*)p + 0x18) = 0x82C;
        func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        break;
    }
    case 16:
    case 20: {
        func_001A97B8(self, a1, kind);
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462C70);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
        *(int*)((char*)p + 0x150) = 0x80E;
        func_001A9BC0(self, p);
        cBXString_cBXString4((char*)D_004A3028 + 0x48, **(const char***)((char*)self + 0x6D0));
        cBXString_cBXString4((char*)D_004A3028 + 0x4C, *(const char**)(*(char**)((char*)self + 0x6D0) + 4));
        func_0025C610(D_004A3028);
        break;
    }
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB2D0);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_004A1BD8[];

extern "C" void func_001BB2D0(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1BD8));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x28), &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB340);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_004A1BE0[];

extern "C" void func_001BB340(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1BE0));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x2C), &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB3B0);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIListBox_setEntryByAsciiString(void* box, int index, const char* str, int a3);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_004A1BE8[];
extern char D_004A12C0[];

extern "C" void func_001BB3B0(void* self)
{
    char buf[16];
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1BE8));
    if (box != 0) {
        sprintf(buf, D_004A12C0, *(int*)(*(char**)((char*)self + 0x6D0) + 0x30));
        cUIListBox_setEntryByAsciiString(box, 0, buf, 0);
        func_0039A7A8(box, (unsigned char)(*(int*)(*(char**)((char*)self + 0x6D0) + 0x30) - 0x6C));
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB440);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464A18[];

extern "C" void func_001BB440(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464A18));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x34), &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB4B0);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464A08[];

extern "C" void func_001BB4B0(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00464A08));
    if (box != 0) {
        unsigned char out = 0;
        func_0039A768(box, *(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x40) != 0, &out);
        func_0039A7A8(box, out);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB520);
#ifdef SKIP_ASM
class cFEVBox_001BB520 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464B10[];
extern char D_00464B20[];

extern "C" void func_001BB520(void* self, void* box, int flag)
{
    unsigned char out = 0;
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B10), 0);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B20), 1);
    func_0039A768(box, flag == 0, &out);
    func_0039A7A8(box, out);
    ((cFEVBox_001BB520*)box)->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB5D0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00464B30[];
extern char D_00464B40[];
extern char D_00464B50[];
extern char D_00464B60[];
extern char D_00464B70[];
extern char D_00464B80[];
extern char D_00464B90[];
extern char D_00464BA0[];
extern char D_00464BB0[];
extern char D_00464BC0[];
extern char D_00464BD0[];
extern char D_00464BE0[];

class cFEVObj_001BB5D0 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001BB5D0(void* self, void* box, int a2)
{
    unsigned char out = 0;
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B30), 1);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B40), 2);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B50), 3);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B60), 4);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B70), 5);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B80), 6);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464B90), 7);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464BA0), 8);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464BB0), 9);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464BC0), 10);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464BD0), 11);
    cUIListBox_addEntryByStringID(box, GetHashValue32(D_00464BE0), 12);
    func_0039A768(box, 1, &out);
    func_0039A7A8(box, out);
    func_0039A7A8(box, 1);
    ((cFEVObj_001BB5D0*)box)->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB798);
#ifdef SKIP_ASM
class cFEVBox_001BB798 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void cUIListBox_setEntryByAsciiString(void* box, int index, const char* str, int a3);
extern "C" void func_0039A670(void* self);
extern "C" void func_0039A8D8(void* self, int count);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_004A12C0[];

extern "C" void func_001BB798(void* self, void* box, int value)
{
    char buf[16];
    func_0039A670(box);
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    func_0039A8D8(box, 0x67);
    sprintf(buf, D_004A12C0, value);
    cUIListBox_setEntryByAsciiString(box, 0, buf, 0);
    func_0039A7A8(box, (unsigned char)(value - 0x6C));
    ((cFEVBox_001BB798*)box)->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB840);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" int func_001BB9B0(void* self, int month, int year);
extern "C" void func_0039A670(void* self);
extern "C" int func_0039A768(void* self, int key, unsigned char* out);
extern "C" void func_0039A7A8(void* self, int a1);
extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data);
extern char D_004A12C0[];

class cFEVObj_001BB840 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001BB840(void* self, void* box, int month, int year, int sel)
{
    char buf[16];
    unsigned char idx;
    int n = func_001BB9B0(self, month, year);
    func_0039A670(box);
    *(int*)((char*)box + 0x14) = (*(int*)((char*)box + 0x14) & ~1) | 0x80;
    int i;
    for (i = 1; i < n + 1; i++) {
        sprintf(buf, D_004A12C0, i);
        cUIListBox_addEntryByAsciiString(box, buf, i);
    }
    if (n < sel) {
        sel = n;
        *(int*)(*(char**)((char*)self + 0x6D0) + 0x2C) = sel;
    }
    idx = 0;
    func_0039A768(box, sel, &idx);
    func_0039A7A8(box, idx);
    ((cFEVObj_001BB840*)box)->v09(1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BB968);
#ifdef SKIP_ASM
extern "C" int func_001BB968(void* self, int year)
{
    int leap = 0;
    if ((year & 3) == 0) {
        leap = 1;
        if (year % 100 == 0) {
            leap = (year % 400 == 0);
        }
    }
    return leap;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BB9B0);

extern "C" void* func_001BBC40(void* self);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBAA8__FPv);
#ifdef SKIP_ASM
int func_001BBAA8(void* self)
{
    return (func_001BBC40(self) != 0);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BBAC8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBC40);
#ifdef SKIP_ASM
struct sObj1BBC40 {
    char data[0xD0];
};

int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* func_001C55F8(void* self);
extern "C" void func_001C5750(void* self, int flags);
extern char D_00464C38[];
extern char D_00461618[];
// PORT: the unit declares func_001BBC40 as returning void*; the body returns 0/1
extern "C" int func_001BBC40_r(void* self) __asm__("func_001BBC40");

extern "C" int func_001BBC40_r(void* self)
{
    sObj1BBC40 o;
    func_001C55F8(&o);
    if (*(int*)((char*)*(void**)((char*)self + 0x6D0) + 0x40) == 0) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464C38);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x80D;
        func_001A9BC0(self, p);
        func_001C5750(&o, 2);
        return 0;
    }
    func_001C5750(&o, 2);
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBD08);
#ifdef SKIP_ASM
extern void* D_004684A0[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001BBD08(void* self, int a1, int a2)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0x6D0) = a2;
    *(void***)((char*)self + 0x8) = D_004684A0;
    *(int*)((char*)self + 0xC) = 0x4F;
    *(int*)((char*)self + 0x6A8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBD60);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void func_001A8768(void* self);
extern "C" void func_001BC400(void* self);
extern char D_00464C50[];
extern void* D_004A3028;

extern "C" void func_001BBD60(void* self)
{
    *(char**)((char*)self + 0x6D8) = (char*)D_004A3028 + 0x260;
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00464C50), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001BC400(self);
    func_001A8768(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBDE0__FPv);
#ifdef SKIP_ASM
void* func_001BBDE0(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBE00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" int sprintf(char* buf, const char* fmt, ...);
void cUIText_setAsciiString(cUIText* self, const char* str);
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern char D_00464C68[];
extern char D_00461520[];
extern char D_00464C78[];
extern char D_00464C90[];
extern char D_00464CA0[];
extern char D_00464CB8[];

static inline int IsHash1BBE00(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001BBE00(void* self, cUIText* text)
{
    char buf[0x40];
    if (IsHash1BBE00(*(int*)((char*)text + 0x38), D_00464C68)) {
        *(int*)((char*)text + 0x18) = 4;
    } else if (*(int*)((char*)self + 0x6D0) == 0 && IsHash1BBE00(*(int*)((char*)text + 0x38), D_00461520)) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00464C78));
    } else if (*(int*)((char*)self + 0x6D0) == 0 && IsHash1BBE00(*(int*)((char*)text + 0x38), D_00464C90)) {
        cUIText_setUnicodeStringByID(text, GetHashValue32(D_00464CA0));
    } else {
        int i;
        for (i = 0; i < 4; i++) {
            sprintf(buf, D_00464CB8, i);
            if (IsHash1BBE00(*(int*)((char*)text + 0x38), buf)) {
                cUIText_setAsciiString(text, buf);
                *(int*)((char*)text + 0x18) = i;
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BBF18);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cBXString_operatorE(void* self, void* other);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9150(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" void* func_001AD130(void* self, int a1);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_001BC290(void* self);
extern "C" void func_001BC300(void* self, const char* name);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" void func_0025B800(void* self);
extern "C" void func_00260F80();
extern "C" void func_002613C8(void* self);
extern "C" void func_00261408(void* self);
extern "C" int func_00261460(void* self);
extern "C" void func_0039F290(void* list, void* item);
extern void* D_004A3028;
extern void* D_004A3328;
extern char D_004A1408[];
extern char D_00462D10[];
extern const char D_00462D68[];
extern char D_00464C78[];
extern char D_00464CC8[];

struct sStrs_001BBF18 {
    char pad[0x14];
    char* strs[1];
};

static inline void* GetSession_001BBF18()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001BBF18(void* self, int a1, unsigned int msg)
{
    switch (msg) {
    case 5: {
        a1 = *(int*)((char*)a1 + 0x18);
        if (a1 == 4) {
            if (*(int*)((char*)self + 0x6D0) != 0) {
                // PORT: string pointer passed through an int parameter (func_001A9150's a3)
                func_001A9150(self, 0, GetHashValue32(D_00464CC8), (int)D_004A1408, 0, -1, 0x10);
                *(int*)((char*)*(void**)((char*)self + 0x69C) + 0x58) = 1;
                func_001CE3C8(*(void**)((char*)self + 0x69C), 0x4B, 1, 2);
                func_001CE3C8(*(void**)((char*)self + 0x69C), 0x35, 0, 2);
            } else {
                func_001A9150(self, 0, GetHashValue32(D_00464C78), (int)D_004A1408, 0, -1, 0xC);
                *(int*)((char*)*(void**)((char*)self + 0x69C) + 0x58) = 1;
                func_001CE3C8(*(void**)((char*)self + 0x69C), 0x4B, 1, 2);
                func_001CE3C8(*(void**)((char*)self + 0x69C), 0x35, 0, 2);
            }
        } else if (*(int*)((char*)self + 0x6D0) != 0) {
            sStrs_001BBF18* s = *(sStrs_001BBF18**)((char*)self + 0x6D8);
            cBXString_operatorE(s, &s->strs[a1]);
            func_001BC290(self);
        } else {
            func_001BC300(self, ((char**)(*(char**)((char*)self + 0x6D8) + 0x14))[a1]);
        }
        break;
    }
    case 6:
        if (*(int*)((char*)self + 0x6D0) != 0) {
            func_00261408(GetSession_001BBF18());
            func_0025B800(D_004A3028);
            void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
            *(int*)((char*)p + 0x18) = 0x832;
            func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        } else {
            func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        }
        break;
    case 13:
        if (*(int*)((char*)self + 0x6D0) != 0) {
            cBXString_cBXString4(*(void**)((char*)self + 0x6D8), (char*)*(void**)((char*)self + 0x69C) + 0x74);
            func_001BC290(self);
        } else {
            func_001BC300(self, (char*)*(void**)((char*)self + 0x69C) + 0x74);
        }
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC190);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00464CE8[];
extern char D_00464D08[];
extern char D_00464D30[];
extern char D_00464D50[];
extern char D_0045FE60[];
extern char D_00462C50[];
extern char D_004614E8[];

extern "C" void func_001BC190(void* self, void* menu)
{
    func_001DA528(menu, 3);
    if (*(int*)((char*)self + 0x6D0) != 0) {
        *(int*)((char*)menu + 0x54) = GetHashValue32(D_00464CE8);
        func_001DA530(menu, 0, GetHashValue32(D_00464D08));
    } else {
        *(int*)((char*)menu + 0x54) = GetHashValue32(D_00464D30);
        func_001DA530(menu, 0, GetHashValue32(D_00464D50));
    }
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_00462C50), 0);
    func_001DA510(menu, 2, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC290);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void func_0025B9C8(void* self, void* a1);
extern char D_00464A38[];
extern void* D_004A3028;

extern "C" void func_001BC290(void* self)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 0;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464A38);
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x150) = 0x820;
    *(int*)((char*)p + 0x164) = 0;
    func_001A9BC0(self, p);
    func_0025B9C8(D_004A3028, (char*)D_004A3028 + 0x260);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC300);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025D1B8(void* self, const char* str);
extern void* D_004A3028;
extern char D_004615F8[];
extern char D_00461618[];
extern char D_00462DE0[];

extern "C" void func_001BC300(void* self, const char* name)
{
    if (strlen(name) < 3) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004615F8);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x814;
        func_001A9BC0(self, p);
    } else {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462DE0);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x815;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        func_0025D1B8(D_004A3028, name);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC400);
#ifdef SKIP_ASM
class cFEVText_001BC400 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int a1);
};

struct sNames1BC400 {
    char pad[0x14];
    char* mNames[4];
    int mCount;
};

extern "C" int sprintf(char* buf, const char* fmt, ...);
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_00464CB8[];
extern char D_004A1408[];

extern "C" void func_001BC400(void* self)
{
    char buf[64];
    int i;
    for (i = 0; i < 4; i++) {
        sprintf(buf, D_00464CB8, i);
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(buf));
        if (text != 0) {
            sNames1BC400* names = *(sNames1BC400**)((char*)self + 0x6D8);
            if (i < names->mCount) {
                cUIText_setAsciiString(text, ((char**)((char*)names + 0x14))[i]);
                ((cFEVText_001BC400*)text)->v08(0);
            } else {
                cUIText_setAsciiString(text, D_004A1408);
                ((cFEVText_001BC400*)text)->v08(1);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC4F0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001AD130(void* self, int a1);
extern "C" void func_001BC400(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_00260F10(void* self);
extern "C" void func_0039F190(void* self, int a1);
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
extern void* D_004A3028;
extern const char D_00462D68[];
extern char D_00464AD0[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

// PORT: a2 is a message pointer passed as int
extern "C" int func_001BC4F0(void* self, int id, int a2)
{
    switch (id) {
    case 0xCB: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 2;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464AD0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
        func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
        *(int*)((char*)p + 0x164) = 0;
        *(int*)((char*)p + 0x150) = 0x81F;
        func_001A9BC0(self, p);
        break;
    }
    case 0xD4:
        func_00260F10(D_004A3028);
    case 0xD6:
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0x102:
        if (*(unsigned int*)((char*)a2 + 8) == 0x6475706C) {
            char* q = *(char**)((char*)self + 0x6A0);
            if (q != 0) {
                int t = *(int*)(q + 0x18);
                if (t == 0x820 || t == 0x815) {
                    func_0039F190(*(char**)((char*)self + 0x10) + 0x18, 1);
                }
            }
            func_001BC400(self);
        } else {
            func_001A8E40_3i(self, id, a2);
        }
        break;
    default:
        return func_001A8E40_3i(self, id, a2);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC6A0);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BC728(void* self, void* a1, int a2);
extern "C" void func_001BC818(void* self, void* a1, int a2);
extern "C" void func_001BC990(void* self, void* a1, int a2);

extern "C" void func_001BC6A0(void* self, void* a1, int a2)
{
    switch (*(unsigned int*)((char*)a1 + 0x18)) {
    case 0x81F:
        func_001BC818(self, a1, a2);
        break;
    case 0x80E:
        func_001BC728(self, a1, a2);
        break;
    case 0x82C:
        func_001BC990(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC728);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
// func_001A97B8 returns void (its asm never sets $2); the unit declares it int
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00462D10[];
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001BC728()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001BC728(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_001A97B8_v(self, a1, a2);
        func_00261408(GetSession_001BC728());
        func_0025B800(D_004A3028);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
        *(int*)((char*)p + 0x18) = 0x832;
        func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
    } else {
        func_001A97B8_v(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC818);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025C610(void* self);
extern "C" void func_0039F290(void* list, void* item);
extern void* D_004A3028;
extern char D_00462D10[];
extern char D_00462C70[];
extern char D_00462C88[];

extern "C" void func_001BC818(void* self, void* a1, int kind)
{
    switch ((unsigned int)kind) {
    case 15: {
        func_001A97B8(self, a1, 15);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 1,
                                **(int**)((char*)self + 0x6D8), *(int*)(*(char**)((char*)self + 0x6D8) + 4));
        *(int*)((char*)p + 0x18) = 0x82C;
        func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
        break;
    }
    case 16:
    case 20: {
        func_001A97B8(self, a1, kind);
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462C70);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
        *(int*)((char*)p + 0x150) = 0x80E;
        func_001A9BC0(self, p);
        cBXString_cBXString4((char*)D_004A3028 + 0x48, **(const char***)((char*)self + 0x6D8));
        cBXString_cBXString4((char*)D_004A3028 + 0x4C, *(const char**)(*(char**)((char*)self + 0x6D8) + 4));
        func_0025C610(D_004A3028);
        break;
    }
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BC990);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
// PORT: the unit declares func_001A97B8 as returning int; this caller ignores the result.
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_0025C610(void* net);
extern void* D_004A3028;
extern char D_00462D80[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];
extern char D_00462C70[];
extern char D_00462C88[];

// Tracks a pending flag; on 0x16 shows either the confirm popup or the network-connect popup.
extern "C" void func_001BC990(void* self, void* a1, int a2)
{
    switch (a2) {
    case 0xF: case 0x10: case 0x14:
        *(int*)((char*)self + 0x6D4) = 0;
        func_001A97B8_v(self, a1, a2);
        break;
    case 0x11:
        *(int*)((char*)self + 0x6D4) = 1;
        func_001A97B8_v(self, a1, a2);
        break;
    case 0x16:
        func_001A97B8_v(self, a1, a2);
        if (*(int*)((char*)self + 0x6D4) != 0) {
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 2;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462D80);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
            func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
            *(int*)((char*)p + 0x168) = 0;
            *(int*)((char*)p + 0x164) = 0;
            *(int*)((char*)p + 0x150) = 0x81F;
            func_001A9BC0(self, p);
        } else {
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 1;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462C70);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
            *(int*)((char*)p + 0x150) = 0x80E;
            func_001A9BC0(self, p);
            cBXString_cBXString4((char*)D_004A3028 + 0x48, **(char***)((char*)self + 0x6D8));
            cBXString_cBXString4((char*)D_004A3028 + 0x4C, (*(char***)((char*)self + 0x6D8))[1]);
            func_0025C610(D_004A3028);
        }
        *(int*)((char*)self + 0x6D4) = 0;
        break;
    default:
        func_001A97B8_v(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCB58);
#ifdef SKIP_ASM
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");
extern void* D_0046A7F8[];
extern int D_004A3E90;

struct sFEObj_001BCB58 {
    char pad0[0x8];
    void** vt;          // 0x8
    int fC;             // 0xC
    char pad10[0x6D0 - 0x10];
    int f6D0;           // 0x6D0
    int f6D4;           // 0x6D4
    int f6D8[10];       // 0x6D8
    int f700;           // 0x700
    int f704;           // 0x704
    int f708[4];        // 0x708
    int f718[4];        // 0x718
    int f728;           // 0x728
    int f72C;           // 0x72C
    int f730[4];        // 0x730
    int f740[4];        // 0x740
    int f750[4];        // 0x750
    char pad760[0x76C - 0x760];
    int f76C;           // 0x76C
    char pad770[0x778 - 0x770];
    int f778;           // 0x778
    char pad77C[0xB80 - 0x77C];
    int fB80;           // 0xB80
};

extern "C" sFEObj_001BCB58* func_001BCB58(sFEObj_001BCB58* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    self->vt = D_0046A7F8;
    self->fB80 = self->f76C = D_004A3E90;
    self->fC = 0x3C;
    self->f778 = 0;
    self->f6D0 = 0;
    self->f6D4 = 0;
    for (int i = 9; i >= 0; i--) {
        self->f6D8[i] = 0;
    }
    self->f704 = 0;
    for (int j = 0; j < 4; j++) {
        self->f708[j] = 0;
        self->f718[j] = 0;
        self->f730[j] = 0;
        self->f740[j] = 0;
        self->f750[j] = 0;
    }
    self->f728 = 0;
    self->f72C = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCC30);
#ifdef SKIP_ASM
class cFEVObj_001BCC30 {
public:
    int field_0x0;
    int field_0x4;
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
};

int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern char D_00464DA0[];

extern "C" void func_001BCC30(cFEVObj_001BCC30* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00464DA0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        self->v28();
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCCA8);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001BCCA8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 2, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCD18);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
// PORT: func_001BDF60's own definition takes an sFESlots1BDF60* (defined later); bound by asm label.
void func_001BDF60_1BDC18(void* self, int id) __asm__("func_001BDF60");
extern "C" void func_001BE0A8(void* self);
extern "C" void func_001BE3A8(void* self, int id);
extern "C" void func_001BE720(void*);
extern "C" void func_0039A7A8(void* self, int a1);

struct sVE1BCD18 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern "C" int func_001BCD18(void* self, int reset)
{
    if (reset != 0) {
        sVE1BCD18* vt = *(sVE1BCD18**)((char*)self + 0x8);
        vt[32].fn((char*)self + vt[32].delta);
        *(int*)((char*)self + 0x760) = 0;
        func_001BE0A8(self);
        func_001BE720(self);
        func_001BE3A8(self, *(int*)((char*)self + 0x718));
    } else if (*(int*)((char*)self + 0x760) != 0) {
        func_001BE0A8(self);
        int cur = *(int*)((char*)self + 0x764);
        if (cur < 4) {
            char* list = *(char**)((char*)self + (cur << 2) + 0x708);
            int n = *(unsigned char*)(list + 0x318);
            if (*(int*)((char*)self + 0x768) >= n) {
                *(int*)((char*)self + 0x768) = n - 1;
            }
            func_0039A7A8(list, *(unsigned char*)((char*)self + 0x768));
        }
        char* ids = (char*)self + 0x718;
        cUIMenu_setSelectedByIndex(*(void**)((char*)self + 0x6D4), *(int*)((char*)self + 0x764));
        func_001BE3A8(self, *(int*)(ids + (*(int*)((char*)self + 0x764) << 2)));
        func_001BE720(self);
        func_001BDF60_1BDC18(self, *(int*)(ids + (*(int*)((char*)self + 0x764) << 2)));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCE18__FPv);
#ifdef SKIP_ASM
void* func_001BCE18(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BCE38);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_0039AB00(void* self, int a1);
extern "C" void func_0039B760(void* self, unsigned char a1);
extern char D_00464DB0[];
extern char D_00464DC0[];
extern char D_00464DD0[];
extern char D_00464DE8[];
extern char D_004A1BF0[];
extern char D_00464E00[];
extern char D_00464E10[];
extern char D_00464E20[];
extern char D_00464E30[];
extern char D_00464E40[];
extern char D_00464E50[];
extern char D_00464E60[];
extern char D_00464E70[];
extern char D_00464E80[];
extern char D_00464E90[];
extern char D_00464EA0[];
extern char D_00464EB0[];
extern char D_00464EC8[];
extern char D_00464EE0[];
extern char D_00464EF8[];
extern char D_00464F10[];
extern char D_00464F20[];
extern char D_00464F30[];
extern char D_00464F40[];
extern char D_00464F50[];

class cFEVObj_001BCE38 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08();
    virtual void v09(int on);
};

extern "C" void func_001BCE38(void* self, cFEVObj_001BCE38* obj)
{
    char buf[16];
    char* s = (char*)self;
    char* o = (char*)obj;
    int id = *(int*)(o + 0x38);
    if (id == GetHashValue32(D_00464DB0)) {
        *(void**)(s + 0x6D4) = obj;
    } else if (id == GetHashValue32(D_00464DC0)) {
        *(void**)(s + 0x6D0) = obj;
        func_0039AB00(obj, 1);
        (*(cFEVObj_001BCE38**)(s + 0x6D0))->v07(1);
        func_0039B760(*(void**)(s + 0x6D0), 1);
        *(int*)(*(char**)(s + 0x6D0) + 0x14) &= ~0x80;
        *(int*)(*(char**)(s + 0x6D0) + 0x14) |= 1;
    } else if (id == GetHashValue32(D_00464DD0)) {
        cUIText_setUnicodeStringByID((cUIText*)obj, GetHashValue32(D_00464DE8));
    } else if (id == GetHashValue32(D_004A1BF0)) {
        *(void**)(s + 0x704) = obj;
    } else if (id == GetHashValue32(D_00464E00)) {
        *(void**)(s + 0x700) = obj;
        *(int*)(o + 0x18) = 4;
    } else if (id == GetHashValue32(D_00464E10)) {
        *(void**)(s + 0x718) = obj;
        *(int*)(o + 0x18) = 0;
    } else if (id == GetHashValue32(D_00464E20)) {
        *(void**)(s + 0x71C) = obj;
        *(int*)(o + 0x18) = 1;
    } else if (id == GetHashValue32(D_00464E30)) {
        *(void**)(s + 0x720) = obj;
        *(int*)(o + 0x18) = 2;
    } else if (id == GetHashValue32(D_00464E40)) {
        *(void**)(s + 0x724) = obj;
        *(int*)(o + 0x18) = 3;
    } else if (id == GetHashValue32(D_00464E50)) {
        *(void**)(s + 0x730) = obj;
        obj->v09(1);
    } else if (id == GetHashValue32(D_00464E60)) {
        *(void**)(s + 0x734) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464E70)) {
        *(void**)(s + 0x738) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464E80)) {
        *(void**)(s + 0x73C) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464E90)) {
        *(void**)(s + 0x728) = obj;
    } else if (id == GetHashValue32(D_00464EA0)) {
        *(void**)(s + 0x72C) = obj;
    } else if (id == GetHashValue32(D_00464EB0)) {
        *(void**)(s + 0x708) = obj;
        *(int*)(o + 0x14) &= ~1;
    } else if (id == GetHashValue32(D_00464EC8)) {
        *(void**)(s + 0x70C) = obj;
        *(int*)(o + 0x14) &= ~1;
    } else if (id == GetHashValue32(D_00464EE0)) {
        *(void**)(s + 0x710) = obj;
        *(int*)(o + 0x14) &= ~1;
    } else if (id == GetHashValue32(D_00464EF8)) {
        *(void**)(s + 0x714) = obj;
        *(int*)(o + 0x14) &= ~1;
    } else if (id == GetHashValue32(D_00464F10)) {
        *(void**)(s + 0x740) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464F20)) {
        *(void**)(s + 0x744) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464F30)) {
        *(void**)(s + 0x748) = obj;
        obj->v09(0);
    } else if (id == GetHashValue32(D_00464F40)) {
        *(void**)(s + 0x74C) = obj;
        obj->v09(0);
    } else {
        void** p = (void**)(s + 0x6D8);
        int i;
        for (i = 0; ; p++, i++) {
            if (i >= 10) {
                return;
            }
            sprintf(buf, D_00464F50, i);
            if (id == GetHashValue32(buf)) {
                break;
            }
        }
        *p = obj;
        *(int*)(o + 0x18) = i;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BD1B8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD428);
#ifdef SKIP_ASM
extern "C" void func_001BD540(void* self, int a1, void* a2);

extern "C" void func_001BD428(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    if (*(int*)(p + 0x18) == 8) {
        func_001BD540(self, *(int*)((char*)self + 0xB80), p + 0x74);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD460);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void func_0025D800(void* self, int a1, const char* a2);
extern "C" const char* func_0025F150(void* self, int a1);
extern void* D_004A3028;
extern char D_00464FA8[];

struct sFEObj_001BD460 {
    char pad0[0x770];
    int f770;           // 0x770
    char pad774[0xB80 - 0x774];
    char fB80[4];       // 0xB80 (string object)
};

extern "C" void func_001BD460(sFEObj_001BD460* self, int a1, const char* str)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 0;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464FA8);
    *(int*)((char*)p + 0x164) = 0;
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x150) = 0x829;
    func_001A9BC0(self, p);
    if (str == 0 || strlen(str) == 0) {
        self->f770 = 0;
        func_0025D800(D_004A3028, a1, 0);
    } else {
        self->f770 = 1;
        func_0025D800(D_004A3028, a1, str);
    }
    char* s = self->fB80;
    cBXString_cBXString4(s, func_0025F150(D_004A3028, a1));
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD540);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void func_0025D860(void* self, const char* name, const char* str);
extern void* D_004A3028;
extern char D_00464FA8[];

struct sFEObj_001BD540 {
    char pad0[0x770];
    int f770;           // 0x770
    char pad774[0xB80 - 0x774];
    char fB80[4];       // 0xB80 (string object)
};

extern "C" void func_001BD540(void* self, int a1, void* a2)
{
    void* p = func_001A9C50(self);
    *(int*)((char*)p + 0xBC) = 0;
    *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464FA8);
    *(int*)((char*)p + 0x164) = 0;
    *(int*)((char*)p + 0xC0) = 3;
    *(int*)((char*)p + 0x150) = 0x829;
    func_001A9BC0(self, p);
    if (a2 == 0 || strlen((const char*)a2) == 0) {
        ((sFEObj_001BD540*)self)->f770 = 0;
        func_0025D860(D_004A3028, (const char*)a1, 0);
    } else {
        ((sFEObj_001BD540*)self)->f770 = 1;
        func_0025D860(D_004A3028, (const char*)a1, (const char*)a2);
    }
    // PORT: the unit declares a1 as int; it is the name string
    cBXString_cBXString4(((sFEObj_001BD540*)self)->fB80, (const char*)a1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD610);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025DAC0(void* self, int a1, const char* a2, const char* a3);
extern void* D_004A3028;
extern char D_00464FC0[];
extern char D_00461618[];
extern char D_00464FD8[];

// PORT: the unit declares this (void*, int, int, int); a1/a3 are string pointers passed as int.
extern "C" void func_001BD610(void* self, int a1, int a2, int a3)
{
    const char* name = (const char*)a1;
    const char* extra = (const char*)a3;
    if (strlen(name) == 0) {
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464FC0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x824;
        func_001A9BC0(self, p);
    } else {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 0;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464FD8);
        *(int*)((char*)p + 0xC0) = 3;
        *(int*)((char*)p + 0x150) = 0x828;
        *(int*)((char*)p + 0x164) = 0;
        func_001A9BC0(self, p);
        void* g = D_004A3028;
        func_0025DAC0(g, a2, name, strlen(extra) != 0 ? extra : 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD738);
#ifdef SKIP_ASM
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void func_001A8A40(void* self, void* obj);
// PORT: func_001BE510 is defined as (self) in this unit, but this caller passes a second arg.
void func_001BE510_BD738(void* self, int a1) __asm__("func_001BE510");
extern "C" const char* func_0039A708(void* a);
extern "C" void func_001BE0A8(void* self);
// PORT: func_001BE038 is defined later with its own list type; bound by asm label.
void func_001BE038_BD738(void* self) __asm__("func_001BE038");
struct sFEObj_001B1F88;
extern "C" sFEObj_001B1F88* func_001B1F88(sFEObj_001B1F88* mem, int a1);
extern "C" void func_001BD848(void* self, int a1, int a2);
extern const char D_0045FF10[];

struct sFE1BD738 {
    char pad0[0x708];
    void* boxes[4];     // 0x708
};

// Message handler for the slot-select screen; unknown messages go to the base handler.
extern "C" void* func_001BD738(char* self, int a1, int a2)
{
    switch (a1) {
    case 0xE0:
        func_001BE510_BD738(self, *(int*)(self + 0x774));
        break;
    case 0xDF: {
        int n = *(int*)(*(char**)(*(char**)(self + 0x6D4) + 0xA0) + 0x18);
        *(int*)(self + 0x764) = n;
        if (n < 4) {
            cBXString_cBXString4(self + 0x76C, func_0039A708(((sFE1BD738*)self)->boxes[n]));
        }
        func_001BE0A8(self);
        func_001BE038_BD738(self);
        break;
    }
    case 0xDC: case 0xE4:
        func_001A8A40(self, func_001B1F88((sFEObj_001B1F88*)cMemMan_alloc(0x73C, D_0045FF10, 0, 0), *(int*)(self + 0x10)));
        break;
    case 0x102:
        func_001BD848(self, a1, a2);
        break;
    default:
        return func_001A8E40_3(self, a1, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD848);
#ifdef SKIP_ASM
// PORT: unit declares func_001A8E40 with one arg; the handler passes (self, a1, a2) through
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void func_001BDA88(void* self, int a2);
extern "C" void func_001BD8C8(void* self, int a2);

extern "C" void func_001BD848(void* self, int a1, int a2)
{
    if (*(int*)((char*)self + 0x1C) & 6) {
        switch (*(int*)((char*)*(void**)((char*)self + 0x6A0) + 0x18)) {
        case 0x828:
            func_001BDA88(self, a2);
            break;
        case 0x829:
            func_001BD8C8(self, a2);
            break;
        default:
            func_001A8E40_3(self, a1, a2);
            break;
        }
    } else {
        func_001A8E40_3(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BD8C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_002C26D0(void* str, int a1, char* buf);
// PORT: unit declares func_001A8E40 with one arg; the real handler takes (self, id, msg)
extern "C" void* func_001A8E40_msg(void* self, int id, void* msg) __asm__("func_001A8E40");
extern void* D_004A28A8;
extern char D_00461618[];
extern char D_004650A0[];
extern char D_004650B8[];
extern char D_004650D0[];
extern char D_00462C88[];

struct sVEntry_001BD8C8 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

// PORT: the unit declares the message pointer as int
extern "C" void func_001BD8C8(void* self, int a2)
{
    void* msg = (void*)a2;
    switch (*(unsigned int*)((char*)msg + 8)) {
    case 0x66756C6C:
    case 0x75726F6D: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_004650A0);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x150) = 0x82B;
        func_001A9BC0(self, p);
        break;
    }
    case 0x70617373:
        if (*(int*)((char*)self + 0x770) == 0) {
            char* buf = (char*)self + 0x780;
            char* name = *(char**)((char*)self + 0xB80);
            char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
            sVEntry_001BD8C8* vt = *(sVEntry_001BD8C8**)(obj + 4);
            func_002C26D0(buf, vt[4].fn(obj + vt[4].delta, GetHashValue32(D_004650B8)), name);
            void* p = func_001A9C50(self);
            *(char**)((char*)p + 0xC4) = buf;
            *(int*)((char*)p + 0xBC) = 2;
            *(int*)((char*)p + 0xC0) = 1;
            char* sub = (char*)p + 0xBC;
            func_001C57C0(sub, 0, GetHashValue32(D_004650D0));
            func_001C57C0(sub, 1, GetHashValue32(D_00462C88));
            *(int*)((char*)p + 0x150) = 0x82A;
            func_001A9BC0(self, p);
        } else {
            func_001A8E40_msg(self, *(int*)msg, msg);
        }
        break;
    default:
        func_001A8E40_msg(self, *(int*)msg, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDA88);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
// PORT: unit declares func_001A8E40 with one arg; the real handler takes (self, id, msg)
extern "C" void* func_001A8E40_msg(void* self, int id, void* msg) __asm__("func_001A8E40");
extern char D_004650F0[];
extern char D_00465108[];
extern char D_00465128[];
extern char D_00461618[];

// PORT: the unit declares the message pointer as int
extern "C" void func_001BDA88(void* self, int a2)
{
    void* msg = (void*)a2;
    switch (*(unsigned int*)((char*)msg + 8)) {
    case 0x66756C6C:
        {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_004650F0);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0x150) = 0x825;
            func_001A9BC0(self, p);
        }
        break;
    case 0x6475706C:
        {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00465108);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0x150) = 0x826;
            func_001A9BC0(self, p);
        }
        break;
    case 0x66696C74:
        {
            void* p = func_001A9C50(self);
            *(int*)((char*)p + 0xBC) = 1;
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00465128);
            *(int*)((char*)p + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0x150) = 0x827;
            func_001A9BC0(self, p);
        }
        break;
    default:
        func_001A8E40_msg(self, *(int*)msg, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDC18);
#ifdef SKIP_ASM
// PORT: func_001BDF60's own definition takes an sFESlots1BDF60* (defined later); bound by asm label.
void func_001BDF60_1BDC18(void* self, int id) __asm__("func_001BDF60");
extern "C" void func_001BE3A8(void* self, int id);
// PORT: func_001BE510 is defined as (self) in this unit, but this caller passes a second arg.
void func_001BE510_2(void* self, int a1) __asm__("func_001BE510");

extern "C" int func_001BDC18(void* self, void* obj, int msg, int a3)
{
    if (obj == *(void**)((char*)self + 0x6D4)) {
        if (msg == 5) {
            func_001BDF60_1BDC18(self, *(int*)((char*)obj + 0xA0));
            func_001BE3A8(self, *(int*)((char*)obj + 0xA0));
            return 0x101;
        }
        return 0x101;
    }
    if (obj == *(void**)((char*)self + 0x6D0)) {
        if (msg == 4) {
            *(int*)((char*)self + 0x778) = a3;
            func_001BE510_2(self, *(int*)((char*)self + 0x774));
            return 0x101;
        }
    }
    return 0x101;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BDCA0);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001BDCF8);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BD610(void* self, int a1, int a2, int a3);

extern "C" void func_001BDCF8(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8(self, a1, a2);
        func_001BD610(self, *(int*)((char*)a1 + 0x6DC), *(int*)((char*)a1 + 0x6E0), *(int*)((char*)a1 + 0x6E4));
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDD60);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001A9150(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern char D_004650D0[];
extern char D_004A1408[];

extern "C" void func_001BDD60(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8(self, a1, 0xF);
        // PORT: string pointer passed through an int parameter (func_001A9150's a3)
        func_001A9150(self, 0, GetHashValue32(D_004650D0), (int)D_004A1408, 0, 8, 0x3F);
        func_001CE3C8(*(void**)((char*)self + 0x69C), 0x35, 0, 2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001BDDE8);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BDCF8(void* self, void* a1, int a2);
extern "C" void func_001BDD60(void* self, void* a1, int a2);

extern "C" void func_001BDDE8(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x823:
        func_001BDCF8(self, a1, a2);
        break;
    case 0x82A:
        func_001BDD60(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDE48);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465148[];
extern char D_00465160[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00465178[];
extern char D_00465198[];
extern char D_00461458[];
extern char D_004614E8[];

extern "C" void func_001BDE48(void* self, void* menu)
{
    func_001DA528(menu, 6);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00465148);
    func_001DA530(menu, 0, GetHashValue32(D_00465160));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(menu, 2, GetHashValue32(D_00465178), 8);
    func_001DA510(menu, 3, GetHashValue32(D_00465198), 0);
    func_001DA510(menu, 4, GetHashValue32(D_00461458), 2);
    func_001DA510(menu, 5, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDF60);
#ifdef SKIP_ASM
class cFEVObj_001BDF60 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

struct sFESlots1BDF60 {
    char pad[0x718];
    int ids[4];                     // 0x718
    char pad728[0x730 - 0x728];
    cFEVObj_001BDF60* objs[4];      // 0x730
};

extern "C" void func_001BDFD8(void* self);

extern "C" void func_001BDF60(sFESlots1BDF60* self, int id)
{
    func_001BDFD8(self);
    for (int i = 0; i < 4; i++) {
        if (id == self->ids[i]) {
            self->objs[i]->v09(1);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BDFD8);
#ifdef SKIP_ASM
class cFEVObj_001BDFD8 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

extern "C" void func_001BDFD8(void* self)
{
    int i;
    for (i = 0; i < 4; i++) {
        ((cFEVObj_001BDFD8**)((char*)self + 0x730))[i]->v09(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE038);
#ifdef SKIP_ASM
struct sListBox1BE038 {
    char pad[0x318];
    unsigned char count;    // 0x318
};

struct sFELists1BE038 {
    char pad[0x708];
    sListBox1BE038* boxes[4];       // 0x708
    char pad718[0x750 - 0x718];
    unsigned int sel[4];            // 0x750
};

extern "C" void func_0039A7A8(void* self, int a1);

extern "C" void func_001BE038(sFELists1BE038* self)
{
    for (unsigned int i = 0; i < 4; i++) {
        if (self->sel[i] >= self->boxes[i]->count) {
            self->sel[i] = self->boxes[i]->count - 1;
        }
        if (self->boxes[i]->count != 0) {
            func_0039A7A8(self->boxes[i], (unsigned char)self->sel[i]);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE0A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cBXString;
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cBXString_cBXString5(void* self, void* src, int len);
extern "C" void* cBXString_operatorE(void* self, void* other);
extern "C" void cBXString__cBXString(void* self, int flags);
int cBXString_FindLastOf(cBXString* self, char ch, int len);
extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data);
// PORT: the data argument is an unsigned/handle value here (-1 as 0xFFFFFFFF)
extern "C" int cUIListBox_addEntryByStringID_u(void* box, int id, unsigned int a2) __asm__("cUIListBox_addEntryByStringID");
struct sFELists1BE038;
extern "C" int func_0025F120(void* self);
extern "C" const char* func_0025F150(void* self, int a1);
extern "C" int func_0025F180(void* self, int idx);
extern "C" void func_00319028(void* ret, void* src, int n);
extern "C" void func_0039A670(void* self);
extern "C" int func_004165A8(const char* a, const char* b);
extern void* D_004A3028;
extern char* D_004A3E90_p __asm__("D_004A3E90");
extern const char* D_004A1A60;
extern const char* D_004A1A64;
extern const char* D_004A1A68;
extern const char* D_004A1A6C;
extern char D_004651B0[];

struct sBXStr_001BE0A8 {
    char* p;
    sBXStr_001BE0A8() { p = D_004A3E90_p; }
    sBXStr_001BE0A8(const sBXStr_001BE0A8& o);
};

struct sBXTmp_001BE0A8 {
    char* p;
    sBXTmp_001BE0A8(const sBXTmp_001BE0A8& o);
    sBXTmp_001BE0A8(int) {}
};

class cFEVObj_001BE0A8 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
};

extern "C" void func_001BE0A8(void* self)
{
    char* s = (char*)self;
    void* mgr = D_004A3028;
    cFEVObj_001BE0A8** lists = (cFEVObj_001BE0A8**)(s + 0x708);
    int n = func_0025F120(mgr);
    sBXStr_001BE0A8 name;
    sBXStr_001BE0A8 base;
    sBXStr_001BE0A8 ext;
    int counts[4];
    for (int k = 0; k < 4; k++) {
        func_0039A670(lists[k]);
    }
    for (int i = 0; i < n; i++) {
        cBXString_cBXString4(&name, func_0025F150(mgr, i));
        int dot = cBXString_FindLastOf((cBXString*)&name, '.', 0);
        {
            sBXTmp_001BE0A8 t(0);
            cBXString_cBXString5(&t, &name, dot);
            cBXString_operatorE(&base, &t);
            cBXString__cBXString(&t, 2);
        }
        {
            sBXTmp_001BE0A8 t(0);
            int len = *(int*)(name.p - 8) - 1;
            func_00319028(&t, &name, len - dot);
            cBXString_operatorE(&ext, &t);
            cBXString__cBXString(&t, 2);
        }
        cFEVObj_001BE0A8* list;
        int type;
        if (func_004165A8(base.p, D_004A1A6C) == 0) {
            type = 0;
            list = *(cFEVObj_001BE0A8**)(s + 0x708);
            counts[0]++;
        } else if (func_004165A8(base.p, D_004A1A68) == 0) {
            type = 1;
            list = *(cFEVObj_001BE0A8**)(s + 0x70C);
            counts[1]++;
        } else if (func_004165A8(base.p, D_004A1A64) == 0) {
            type = 2;
            list = *(cFEVObj_001BE0A8**)(s + 0x710);
            counts[2]++;
        } else if (func_004165A8(base.p, D_004A1A60) == 0) {
            type = 3;
            list = *(cFEVObj_001BE0A8**)(s + 0x714);
            counts[3]++;
        } else {
            continue;
        }
        if (counts[type] == 0) {
            int on = func_0025F180(D_004A3028, i);
            (*(cFEVObj_001BE0A8**)(s + (type << 2) + 0x740))->v09(on);
        }
        cUIListBox_addEntryByAsciiString(list, ext.p, i);
        list->v08(0);
    }
    for (int k = 0; k < 4; k++) {
        if (counts[k] == 0) {
            cUIListBox_addEntryByStringID_u(lists[k], GetHashValue32(D_004651B0), 0xFFFFFFFF);
            lists[k]->v08(1);
        }
    }
    func_001BE038((sFELists1BE038*)self);
    cBXString__cBXString(&ext, 2);
    cBXString__cBXString(&base, 2);
    cBXString__cBXString(&name, 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE3A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" int func_0039A738(void* a);
extern "C" int func_0025F180(void* self, int idx);
extern "C" void func_0025D770(void* self, int idx);
// PORT: func_001BE510 is defined as (self) in this unit, but this caller passes a second arg.
void func_001BE510_2(void* self, int a1) __asm__("func_001BE510");
extern "C" void func_002C26D0(void* str, int a1, char* buf);
extern "C" void func_003A0E90(cUIText* text, char* str);
extern void* D_004A3028;
extern void* D_004A28A8;
extern char D_004651C8[];

class cFEVObj_001BE3A8 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

struct sVE_001BE3A8 {
    short delta;
    short index;
    int (*fn)(void* self, int hash);
};

struct sFE_001BE3A8 {
    char pad0[0x704];
    cUIText* text;
    void* boxes[4];
    int ids[4];
    char pad728[0x740 - 0x728];
    cFEVObj_001BE3A8* objs[4];
    char pad750[0x774 - 0x750];
    int sel;
    int f778;
};

extern "C" void func_001BE3A8(void* p, int id)
{
    sFE_001BE3A8* self = (sFE_001BE3A8*)p;
    int sel = -1;
    int i;
    for (i = 0; i < 4; i++) {
        if (id == self->ids[i]) {
            void* box = self->boxes[i];
            if (*((unsigned char*)box + 0x318) != 0) {
                sel = func_0039A738(box);
                int on = func_0025F180(D_004A3028, sel);
                self->objs[i]->v09(on);
            }
        } else {
            self->objs[i]->v09(0);
        }
    }
    if (sel != -1) {
        self->sel = sel;
        self->f778 = 0;
        func_001BE510_2(self, sel);
        func_0025D770(D_004A3028, sel);
    } else {
        char buf[0x50];
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_001BE3A8* vt = *(sVE_001BE3A8**)(o + 4);
        char* obj = o + vt[4].delta;
        func_002C26D0(buf, vt[4].fn(obj, GetHashValue32(D_004651C8)), 0);
        func_003A0E90(self->text, buf);
        func_001BE510_2(self, -1);
        func_0025D770(D_004A3028, -1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE510);
#ifdef SKIP_ASM
extern "C" void func_001BE540(void*);
extern "C" void func_001BE720(void*);

extern "C" void func_001BE510(void* self)
{
    func_001BE540(self);
    func_001BE720(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE540);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" int func_0025F1B0(void* self);
extern "C" const char* func_0025F1E0(void* self, int idx, int a2);
extern "C" void func_002C26D0(void* str, int a1, char* buf);
extern "C" void func_003A0E90(cUIText* text, char* str);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_004651C8[];

struct sVEntry_001BE540 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1BE540(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001BE540* vt = *(sVEntry_001BE540**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

class cFEVObj_001BE540 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
};

struct sSelf1BE540 {
    char pad[0x6D0];
    char* info;
    char pad6D4[0x6D8 - 0x6D4];
    cFEVObj_001BE540* items[10];
    char pad700[0x704 - 0x700];
    cUIText* text;
    char pad708[0x778 - 0x708];
    int first;
    int count;
};

// PORT: the unit declares func_001BE540(void*); the body takes (self, page) (func_001BE510 passes its a1 through)
extern "C" void func_001BE540_2(void* self, int page) __asm__("func_001BE540");

extern "C" void func_001BE540_2(void* self, int page)
{
    int i;
    if (page != -1) {
        void* mgr = D_004A3028;
        ((sSelf1BE540*)self)->count = func_0025F1B0(mgr);
        char buf[0x50];
        func_002C26D0(buf, Loc1BE540(D_004651C8), (char*)((sSelf1BE540*)self)->count);
        func_003A0E90(((sSelf1BE540*)self)->text, buf);
        unsigned char n = ((sSelf1BE540*)self)->count;
        *(char*)(((sSelf1BE540*)self)->info + 0x96) = n;
        for (i = 0; i < 10; i++) {
            int idx = ((sSelf1BE540*)self)->first + i;
            if (idx < ((sSelf1BE540*)self)->count) {
                cUIText_setAsciiString((cUIText*)((sSelf1BE540*)self)->items[i], func_0025F1E0(mgr, idx, 0));
                *(int*)((char*)((sSelf1BE540*)self)->items[i] + 0x18) = idx;
                ((sSelf1BE540*)self)->items[i]->v09(1);
                ((sSelf1BE540*)self)->items[i]->v08(0);
            } else {
                ((sSelf1BE540*)self)->items[i]->v09(0);
                ((sSelf1BE540*)self)->items[i]->v08(1);
            }
        }
    } else {
        ((sSelf1BE540*)self)->count = 0;
        for (int j = 0; j < 10; j++) {
            ((sSelf1BE540*)self)->items[j]->v09(0);
            ((sSelf1BE540*)self)->items[j]->v08(1);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE720);
#ifdef SKIP_ASM
class cFEVObj_001BE720 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

extern "C" void func_001BE720(void* self)
{
    if (*(int*)((char*)self + 0x778) == 0) {
        (*(cFEVObj_001BE720**)((char*)self + 0x728))->v09(0);
    } else {
        (*(cFEVObj_001BE720**)((char*)self + 0x728))->v09(1);
    }
    if (*(int*)((char*)self + 0x778) + 10 >= *(int*)((char*)self + 0x77C)) {
        (*(cFEVObj_001BE720**)((char*)self + 0x72C))->v09(0);
    } else {
        (*(cFEVObj_001BE720**)((char*)self + 0x72C))->v09(1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE7D8);
#ifdef SKIP_ASM
extern void* D_0046A6E8[];
extern int D_004A3E90;
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001BE7D8(void* self, int a1, int a2)
{
    func_001A8500_3(self, a1, a2);
    int d = D_004A3E90;
    *(void***)((char*)self + 0x8) = D_0046A6E8;
    *(int*)((char*)self + 0x6DC) = d;
    *(int*)((char*)self + 0x6E0) = d;
    *(int*)((char*)self + 0x6E4) = d;
    *(int*)((char*)self + 0xC) = 0x47;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE828);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004651E0[];
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);

extern "C" void* func_001BE828(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004651E0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        screen = cUIScreen_playFrame(screen, 0, 0);
    }
    return screen;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE890__FPv);
#ifdef SKIP_ASM
void* func_001BE890(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BE8B0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern const char* D_004A1A6C;
extern char D_004651F8[];
extern char D_00465208[];
extern char D_00462BA0[];
extern char D_00465218[];
extern char D_00465228[];
extern char D_00462B48[];
extern char D_00465238[];
extern char D_00463AC0[];
extern char D_00463A90[];
extern char D_00463A78[];
extern char D_00463AA8[];
extern char D_004A1408[];

extern "C" void func_001BE8B0(void* self, cUIText* text)
{
    int id = *(int*)((char*)text + 0x38);
    if (id == GetHashValue32(D_004651F8)) {
        cUIListBox_addEntryByStringID(text, GetHashValue32(D_00463AC0), 2);
        cUIListBox_addEntryByStringID(text, GetHashValue32(D_00463A90), 1);
        cUIListBox_addEntryByStringID(text, GetHashValue32(D_00463A78), 0);
        cUIListBox_addEntryByStringID(text, GetHashValue32(D_00463AA8), 3);
        cBXString_cBXString4((char*)self + 0x6E0, D_004A1A6C);
        *(cUIText**)((char*)self + 0x6D8) = text;
    } else if (id == GetHashValue32(D_00465208)) {
        cUIText_setAsciiString(text, D_004A1408);
        *(cUIText**)((char*)self + 0x6D0) = text;
    } else if (id == GetHashValue32(D_00462BA0)) {
        cUIText_setAsciiString(text, D_004A1408);
        *(cUIText**)((char*)self + 0x6D4) = text;
    } else if (id == GetHashValue32(D_00465218)) {
        *(int*)((char*)text + 0x18) = 0;
    } else if (id == GetHashValue32(D_00465228)) {
        *(int*)((char*)text + 0x18) = 1;
    } else if (id == GetHashValue32(D_00462B48)) {
        *(int*)((char*)text + 0x18) = 2;
    } else if (id == GetHashValue32(D_00465238)) {
        *(int*)((char*)text + 0x18) = 3;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEA30__FPv);
#ifdef SKIP_ASM
int func_001BEA30(void* self)
{
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEA38);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cBXString_cBXString4(void* self, const char* str);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A9150(void* self, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" int func_001BEC78(void* self);
extern "C" void func_001CE3C8(void* self, int i, int v, int mode);
extern "C" int func_0039A738(void* a);
extern const char* D_004A1A60;
extern const char* D_004A1A64;
extern const char* D_004A1A68;
extern const char* D_004A1A6C;
extern char D_00465248[];
extern char D_00465260[];

class cFEVObj_001BEA38 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual void v17(void* owner, int msg);
};

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001BEA38(void* self, int a1, unsigned int msg)
{
    char* obj = (char*)a1;
    switch (msg) {
    case 5:
        switch (*(int*)(obj + 0x18)) {
        case 1:
            func_001A9150(self, *(int*)((char*)self + 0x6D0), GetHashValue32(D_00465248), *(int*)((char*)self + 0x6DC), 0, 1, 8);
            func_001CE3C8(*(void**)((char*)self + 0x69C), 0x35, 0, 2);
            break;
        case 2:
            func_001A9150(self, *(int*)((char*)self + 0x6D4), GetHashValue32(D_00465260), *(int*)((char*)self + 0x6E4), 0, 2, 8);
            func_001CE3C8(*(void**)((char*)self + 0x69C), 0x35, 0, 2);
            break;
        case 3:
            if (func_001BEC78(self)) {
                (*(cFEVObj_001BEA38**)((char*)self + 0x20))->v17(self, 0xF);
            }
            break;
        }
        break;
    case 6:
        (*(cFEVObj_001BEA38**)((char*)self + 0x20))->v17(self, 0x14);
        break;
    case 9:
        if (obj == *(char**)((char*)self + 0x6D8)) {
            switch (func_0039A738(obj)) {
            case 0:
                cBXString_cBXString4((char*)self + 0x6E0, D_004A1A60);
                break;
            case 1:
                cBXString_cBXString4((char*)self + 0x6E0, D_004A1A64);
                break;
            case 2:
                cBXString_cBXString4((char*)self + 0x6E0, D_004A1A6C);
                break;
            case 3:
                cBXString_cBXString4((char*)self + 0x6E0, D_004A1A68);
                break;
            }
        }
        break;
    case 13: {
        char* p = *(char**)((char*)self + 0x69C);
        switch (*(int*)(p + 0x18)) {
        case 1:
            cBXString_cBXString4((char*)self + 0x6DC, p + 0x74);
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6D0), *(const char**)((char*)self + 0x6DC));
            break;
        case 2:
            cBXString_cBXString4((char*)self + 0x6E4, p + 0x74);
            cUIText_setAsciiString(*(cUIText**)((char*)self + 0x6D4), *(const char**)((char*)self + 0x6E4));
            break;
        }
    }
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEC78);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
void func_001C57C0(void* self, int a1, int a2);
extern "C" int strlen(const char* s);
extern char D_00464FC0[];
extern char D_00461618[];

extern "C" int func_001BEC78(void* self)
{
    if (strlen(*(const char**)((char*)self + 0x6DC)) == 0) {
        int three = 3;
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xBC) = 1;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00464FC0);
        *(int*)((char*)p + 0xC0) = three;
        func_001C57C0(sub, 0, GetHashValue32(D_00461618));
        *(int*)((char*)p + 0x14C) = three;
        *(int*)((char*)p + 0x150) = 0x847;
        func_001A9BC0(self, p);
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BED28);
#ifdef SKIP_ASM
class func_001BED28_cObj {
public:
    char pad[0x8];
    virtual int v01(int, int);
    virtual int v02(int, int);
    virtual int v03(int, int);
    virtual int v04(int, int);
    virtual int v05(int, int);
    virtual int v06(int, int);
    virtual int v07(int, int);
    virtual int v08(int, int);
    virtual int v09(int, int);
    virtual int v10(int, int);
    virtual int v11(int, int);
    virtual int v12(int, int);
    virtual int v13(int, int);
    virtual int v14(int, int);
    virtual int v15(int, int);
    virtual int v16(int, int);
    virtual int v17(int, int);
    virtual int v18(int, int);
    virtual int v19(int, int);
    virtual int v20(int, int);
    virtual int v21(int, int);
    virtual int v22(int, int);
    virtual int v23(int, int);
    virtual int v24(int, int);
};

extern "C" int func_001BED28(void* self, int a1, int a2)
{
    return (*(func_001BED28_cObj**)((char*)self + 0x20))->v24(a1, a2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BED58);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465278[];
extern char D_00465290[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00462C50[];
extern char D_004614E8[];

extern "C" void func_001BED58(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465278);
    func_001DA530(popup, 0, GetHashValue32(D_00465290));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(popup, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 3, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEE30);
#ifdef SKIP_ASM
extern void* D_00468388[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001BEE30(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x33;
    *(void***)((char*)self + 0x8) = D_00468388;
    *(int*)((char*)self + 0x6D0) = 0;
    *(int*)((char*)self + 0x6A8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEE78);
#ifdef SKIP_ASM
extern void* D_00468388[];
void cMemMan_free(void* p);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001BEE78(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_00468388;
    if (*(void**)((char*)self + 0x6D0) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x6D0));
        *(void**)((char*)self + 0x6D0) = 0;
    }
    func_001A85D0_dtor(self, flags);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001BEED0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
void func_001A8768(void* self);
extern char D_004652B0[];

extern "C" void func_001BEED0(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004652B0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    func_001A8768(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEF40__FPv);
#ifdef SKIP_ASM
void* func_001BEF40(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BEF60);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void func_003A0E90(cUIText* text, char* str);
extern "C" int strlen(const char* s);
// PORT: func_002C2718 is a varargs formatter (buf, fmt, ...); the unit declares a 3-arg view
extern "C" void func_002C2718_1BEF60(unsigned short* buf, const char* fmt, ...) __asm__("func_002C2718");
extern void* D_004A28A8;
extern char D_004A1BF8[];
extern char D_004652C0[];
extern char D_004652D0[];
extern char D_004652E0[];
extern char D_004652F0[];
extern char D_00465300[];
extern char D_00465318[];
extern char D_00465330[];
extern char D_00462F08[];
extern char D_00536760[];

struct sVEntry_001BEF60 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc_001BEF60(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001BEF60* vt = *(sVEntry_001BEF60**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

static inline int IsHash_001BEF60(int id, char* name) { return id == GetHashValue32(name); }

struct sItem_001BEF60 {
    char pad[0x18];
    int mState;
    char pad1C[0x38 - 0x1C];
    int mId;
};

class cFEVObj_001BEF60 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
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
    virtual void v25(int on);
};

extern "C" void func_001BEF60(void* self, cFEVObj_001BEF60* t)
{
    unsigned short buf[64];
    sItem_001BEF60* o = (sItem_001BEF60*)t;
    if (IsHash_001BEF60(o->mId, D_004652C0)) {
        o->mState = 0;
        int s = Loc_001BEF60(D_004652D0);
        func_002C2718_1BEF60(buf, D_004A1BF8, s, D_00536760);
        func_003A0E90((cUIText*)t, (char*)buf);
        t->v09(1);
        if (strlen(D_00536760) == 0) {
            t->v25(1);
            t->v08(1);
            t->v09(0);
        }
    } else if (IsHash_001BEF60(o->mId, D_004652E0)) {
        if (strlen(D_00536760) == 0) {
            t->v09(0);
        } else {
            t->v09(1);
        }
    } else if (IsHash_001BEF60(o->mId, D_004652F0)) {
        if (strlen(D_00536760) == 0) {
            t->v09(0);
        } else {
            t->v09(1);
        }
    } else if (IsHash_001BEF60(o->mId, D_00465300)) {
        o->mState = 2;
        t->v09(1);
    } else if (IsHash_001BEF60(o->mId, D_00465318)) {
        o->mState = 1;
        t->v09(1);
    } else if (IsHash_001BEF60(o->mId, D_00465330)) {
        o->mState = 3;
        int s = Loc_001BEF60(D_00462F08);
        func_002C2718_1BEF60(buf, D_004A1BF8, s, D_00536760);
        func_003A0E90((cUIText*)t, (char*)buf);
        t->v09(1);
        if (strlen(D_00536760) == 0) {
            t->v25(1);
            t->v08(1);
            t->v09(0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BF228);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int GetHashValue32(char* str);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001AD130(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025C610(void* self);
extern "C" int func_001A8E40_3i(void* self, int a1, int a2) __asm__("func_001A8E40");
extern void* D_004A3028;
extern const char D_00462D68[];
extern char D_00462C70[];
extern char D_00462C88[];
extern char D_00536760[];

extern "C" int func_001BF228(void* self, int id, int a2)
{
    switch (id) {
    case 0xC8: {
        void* p = func_001A9C50(self);
        *(int*)((char*)p + 0xBC) = 1;
        char* sub = (char*)p + 0xBC;
        *(int*)((char*)p + 0xC4) = GetHashValue32(D_00462C70);
        *(int*)((char*)p + 0xC0) = 3;
        func_001C57C0(sub, 0, GetHashValue32(D_00462C88));
        *(int*)((char*)p + 0x150) = 0x80E;
        func_001A9BC0(self, p);
        break;
    }
    case 0xC9: {
        char* names = D_00536760;
        cBXString_cBXString4((char*)D_004A3028 + 0x48, names);
        cBXString_cBXString4((char*)D_004A3028 + 0x4C, names + 0x11);
        func_0025C610(D_004A3028);
        break;
    }
    case 0xD4:
        func_001A8A40(self, func_001AD130(cMemMan_alloc(0x6D8, D_00462D68, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        return func_001A8E40_3i(self, id, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BF378);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001BF378()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001BF378(void* self, void* a1, int a2)
{
    if (a2 == 0xF || a2 == 0x14) {
        func_00261408(GetSession_001BF378());
        func_0025B800(D_004A3028);
        func_001A97B8(self, a1, a2);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BF438);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern char D_004652C0[];
extern char D_00465330[];
extern char D_004652E0[];
extern char D_004652F0[];
extern char D_0045DB90[];

class cFEVObj_001BF438 {
public:
    int f0;
    int f4;
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
    virtual void v18(void* obj);
};

extern "C" void func_001BF438(void* self, void* a1, int kind)
{
    if (kind == 15) {
        func_001A97B8(self, a1, 15);
        {
            void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004652C0));
            if (o) {
                ((cFEVObj_001BF438*)self)->v18(o);
            }
        }
        {
            void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465330));
            if (o) {
                ((cFEVObj_001BF438*)self)->v18(o);
            }
        }
        {
            void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004652E0));
            if (o) {
                ((cFEVObj_001BF438*)self)->v18(o);
            }
        }
        {
            void* o = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004652F0));
            if (o) {
                ((cFEVObj_001BF438*)self)->v18(o);
            }
        }
        void* menu = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DB90));
        if (menu) {
            char* item = *(char**)((char*)menu + 0xA0);
            if (item && ((*(int*)(item + 0x14) >> 5) & 1)) {
                cUIMenu_setSelectedByIndex(menu, 1);
            }
        }
    } else {
        func_001A97B8(self, a1, kind);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BF5A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" int func_001A8A40_r(void* self, void* obj) __asm__("func_001A8A40");
extern "C" void* func_001B3F78(void* mem, int a1);
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern void* D_004A3328;
extern void* D_004A3028;
extern const char D_00460BF0[];

static inline void* GetSession_001BF5A8()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001BF5A8(void* self, void* a1, int kind)
{
    switch ((unsigned int)kind) {
    case 15:
        *(int*)((char*)self + 0x6B0) = 1;
        if (func_001A8A40_r(self, func_001B3F78(cMemMan_alloc(0x91C, D_00460BF0, 0, 0), *(int*)((char*)self + 0x10))) != 0) {
            func_00261408(GetSession_001BF5A8());
            func_0025B800(D_004A3028);
            func_002636F0(func_002591B8(), 0);
        }
        break;
    case 16:
    case 20:
        func_001A97B8(self, a1, kind);
        break;
    default:
        func_001A97B8(self, a1, kind);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001BF6C0);
#ifdef SKIP_ASM
class cFEVObj_001BF6C0 {
public:
    int field_0x0;
    int field_0x4;
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
    virtual void v33(void* a1, int a2);
};

extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001BF438(void* self, void* a1, int a2);
extern "C" void func_001BF5A8(void* self, void* a1, int a2);

extern "C" void func_001BF6C0(cFEVObj_001BF6C0* self, void* a1, int a2)
{
    switch (*(unsigned int*)((char*)a1 + 0x18)) {
    case 0x80E:
        self->v33(a1, a2);
        break;
    case 0x82C:
        func_001BF438(self, a1, a2);
        break;
    case 0x848:
        func_001BF5A8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BF758);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int USTR_length(void* s);
extern "C" int strlen(const char* s);
extern "C" void* cBXString_cBXString4(void* self, const char* str);
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
void cMemMan_free(void* p);
// PORT: operator_new__FUi really takes (size, tag, flags, d)
void* operator_new_tag(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9BC0(void* self, void* popup);
extern "C" void* func_001A9C50(void* self);
extern "C" void* func_001AC010(void* self, int a1);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void* func_001B88F0(void* self, int a1, int a2);
extern "C" void* func_001C0418(void* self, int a1);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0025B6D8(void* self, int a1);
extern "C" void func_002C27C0(void* dst, const char* fmt, int a, int b);
extern "C" void func_0039F290(void* list, void* item);
extern void* D_004A28A8;
extern void* D_004A3028;
extern char D_00465348[];
extern char D_00462ED0[];
extern char D_00462D10[];
extern char D_00464860[];
extern char D_00465360[];
extern char D_00465380[];
extern char D_00465398[];
extern const char D_00461CD8[];
extern char D_0045DCC8[];
extern char D_0045FCD8[];

struct sVEntry_001BF758 {
    short delta;
    short index;
    int (*fn)(void*, int);
};

static inline int Loc1BF758(char* name)
{
    char* obj = *(char**)((char*)D_004A28A8 + 0x8C);
    sVEntry_001BF758* vt = *(sVEntry_001BF758**)(obj + 4);
    return vt[4].fn(obj + vt[4].delta, GetHashValue32(name));
}

extern "C" void func_001BF758(void* self, void* a1, unsigned int kind)
{
    if (a1 == 0) {
        return;
    }
    switch (kind) {
    case 5:
        switch (*(int*)((char*)a1 + 0x18)) {
        case 0:
            cBXString_cBXString4((char*)D_004A3028 + 0x48, *(const char**)((char*)D_004A28A8 + 0xC4));
            cBXString_cBXString4((char*)D_004A3028 + 0x4C, *(const char**)((char*)D_004A28A8 + 0xC8));
            func_0025B6D8(D_004A3028, 0);
            break;
        case 2:
            func_001A8A40(self, func_001B88F0(cMemMan_alloc(0x6F4, D_00462ED0, 0, 0), *(int*)((char*)self + 0x10), 1));
            break;
        case 1:
            func_001A8A40(self, func_001AC010(cMemMan_alloc(0x6E4, D_00465348, 0, 0), *(int*)((char*)self + 0x10)));
            break;
        case 3: {
            void* o = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 3, 0, 0);
            *(int*)((char*)o + 0x18) = 0x82C;
            func_0039F290(*(char**)(*(char**)(*(char**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, o);
            break;
        }
        }
        break;
    case 6: {
        if (*(void**)((char*)self + 0x6D0) != 0) {
            cMemMan_free(*(void**)((char*)self + 0x6D0));
            *(void**)((char*)self + 0x6D0) = 0;
        }
        int a = Loc1BF758(D_00465360);
        char* title = D_00465380;
        int b = Loc1BF758(title);
        char* sep = D_00465398;
        int len = USTR_length((void*)a) + USTR_length((void*)b) + strlen(sep) + 1;
        *(void**)((char*)self + 0x6D0) = operator_new_tag(len * 2, D_00461CD8, 0x100, 0);
        void* p = func_001A9C50(self);
        char* sub = (char*)p + 0xBC;
        if (*(void**)((char*)self + 0x6D0) != 0) {
            func_002C27C0(*(void**)((char*)self + 0x6D0), sep, a, b);
            *(void**)((char*)p + 0xC4) = *(void**)((char*)self + 0x6D0);
            *(int*)((char*)p + 0xC0) = 1;
        } else {
            *(int*)((char*)p + 0xC4) = GetHashValue32(title);
            *(int*)((char*)p + 0xC0) = 3;
        }
        *(int*)sub = 2;
        func_001C57C0(sub, 0, GetHashValue32(D_0045DCC8));
        func_001C57C0(sub, 1, GetHashValue32(D_0045FCD8));
        *(int*)(sub + 0xAC) = 1;
        *(int*)(sub + 0x94) = 0x848;
        func_001A9BC0(self, p);
        break;
    }
    case 8: {
        void* o = func_001C0418(cMemMan_alloc(0x6DC, D_00464860, 0x100, 0), *(int*)((char*)self + 0x10));
        *(int*)((char*)o + 0x18) = 0x12;
        func_001A8A40(self, o);
        break;
    }
    default:
        func_001A8918(self, (int)a1, kind);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFAE0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_004653A8[];
extern char D_004653C8[];
extern char D_0045FE60[];
extern char D_00462C50[];
extern char D_004614E8[];
extern char D_00464910[];

extern "C" void func_001BFAE0(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_004653A8);
    func_001DA530(popup, 0, GetHashValue32(D_004653C8));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 2, GetHashValue32(D_004614E8), 1);
    func_001DA510(popup, 3, GetHashValue32(D_00464910), 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFBB8);
#ifdef SKIP_ASM
extern void* D_0046AD48[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001BFBB8(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x3B;
    *(void***)((char*)self + 0x8) = D_0046AD48;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFBF8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001A9930(void* self);
extern "C" void func_00256C50();
extern "C" void* func_0028B180();
extern "C" void func_0028F140(void* p, int a1);
extern int D_004A2EEC;
extern void* D_004A3028;
extern char D_004653F0[];

extern "C" void func_001BFBF8(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004653F0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    if (*(int*)D_004A3028 == 0) {
        func_001A9930(self);
    }
    if (D_004A2EEC != 0) {
        func_00256C50();
    }
    func_0028F140(func_0028B180(), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFCA0__FPv);
#ifdef SKIP_ASM
void* func_001BFCA0(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFCC0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00465408[];
extern char D_00465420[];
extern char D_00465430[];
extern char D_00465440[];
extern char D_00465458[];
extern char D_00465470[];

static inline int IsHash1BFCC0(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001BFCC0(void* self, void* obj)
{
    if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465408)) {
        *(int*)((char*)obj + 0x18) = 1;
    } else if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465420)) {
        *(int*)((char*)obj + 0x18) = 2;
    } else if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465430)) {
        *(int*)((char*)obj + 0x18) = 3;
    } else if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465440)) {
        *(int*)((char*)obj + 0x18) = 0;
    } else if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465458)) {
        *(int*)((char*)obj + 0x18) = 4;
    } else if (IsHash1BFCC0(*(int*)((char*)obj + 0x38), D_00465470)) {
        *(int*)((char*)obj + 0x18) = 5;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001BFD98);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465480[];
extern char D_004654A0[];
extern char D_0045FE60[];
extern char D_00462C50[];
extern char D_00461458[];
extern char D_004654C0[];

extern "C" void func_001BFD98(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465480);
    func_001DA530(popup, 0, GetHashValue32(D_004654A0));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 2, GetHashValue32(D_00461458), 2);
    func_001DA510(popup, 3, GetHashValue32(D_004654C0), 1);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001BFE70);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0138);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
// func_001A97B8 returns void (its asm never sets $2); the unit declares it int
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
// PORT: the unit declares func_001A8A40 as returning void; the body returns 0/1
extern "C" int func_001A8A40_r(void* self, void* obj) __asm__("func_001A8A40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_00194A60(void* mem, int a1);
extern "C" int* func_002591B8();
extern "C" void func_002636F0(void* p, int a1);
extern const char D_00460BA8[];
extern void* D_004A3328;
extern void* D_004A3028;

static inline void* GetSession_001C0138()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    return D_004A3328;
}

extern "C" void func_001C0138(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8_v(self, a1, 0xF);
        *(int*)((char*)self + 0x6B0) = 1;
        if (func_001A8A40_r(self, func_00194A60(cMemMan_alloc(0x58, D_00460BA8, 0, 0), *(int*)((char*)self + 0x10))) != 0) {
            func_00261408(GetSession_001C0138());
            func_0025B800(D_004A3028);
            func_002636F0(func_002591B8(), 0);
        }
    } else {
        func_001A97B8_v(self, a1, a2);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0025B800(void* self);
extern "C" void func_00261408(void* self);
extern "C" void func_00261070(void* self);
void func_00261058(void* self);
// func_001A97B8 returns void (its asm never sets $2); the unit declares it int
extern "C" void func_001A97B8_v(void* self, void* a1, int a2) __asm__("func_001A97B8");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B6ED0(void* mem, int a1, void* owner, int a3, int a4, int a5);
extern "C" void func_0039F290(void* list, void* item);
extern char D_00462D10[];
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001C0240(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        func_001A97B8_v(self, a1, 0xF);
        func_00261408(D_004A3328);
        func_00261070(D_004A3328);
        func_00261058(D_004A3328);
        func_0025B800(D_004A3028);
        void* p = func_001B6ED0(cMemMan_alloc(0xB10, D_00462D10, 0, 0), *(int*)((char*)self + 0x10), self, 0, 0, 0);
        *(int*)((char*)p + 0x18) = 0x832;
        func_0039F290(*(char**)((char*)*(void**)((char*)*(void**)((char*)self + 0x40) + 0xD0) + 0x10) + 0x18, p);
    } else {
        func_001A97B8_v(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001C02F8);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001C0138(void* self, void* a1, int a2);
extern "C" void func_001C0240(void* self, void* a1, int a2);

extern "C" void func_001C02F8(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x82D:
        func_001C0138(self, a1, a2);
        break;
    case 0x846:
        func_001C0240(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001C0358);
#ifdef SKIP_ASM
// PORT: unit declares func_001A8E40 with one arg; the handler passes (self, a1, a2) through
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern const char D_00461C60[];

extern "C" void* func_001C0358(void* self, int a1, int a2)
{
    switch (a1) {
    default:
        return func_001A8E40_3(self, a1, a2);
    case 0xF3:
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
        break;
    case 0xEF:
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0418);
#ifdef SKIP_ASM
extern void* D_0046AC38[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001C0418(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x43;
    *(void***)((char*)self + 0x8) = D_0046AC38;
    *(int*)((char*)self + 0x6D0) = 0;
    *(int*)((char*)self + 0x6D8) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C04A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void func_001C0540(void* self);
extern char D_00465568[];
extern char D_00465580[];

extern "C" void func_001C04A8(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00465568), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        func_001C0540(self);
    }
    cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465580));
    if (text != 0) {
        *(int*)((char*)text + 0x90) |= 8;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C0540);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0A28);
#ifdef SKIP_ASM
extern void* D_0046AC38[];
void cMemMan_free(void* p);
// PORT: unit declares func_001A85D0 with one arg; the body takes (self, flags)
extern "C" void func_001A85D0_dtor(void* self, int flags) __asm__("func_001A85D0");

extern "C" void func_001C0A28(void* self, int flags)
{
    *(void***)((char*)self + 0x8) = D_0046AC38;
    if (*(void**)((char*)self + 0x6D0) != 0) {
        cMemMan_free(*(void**)((char*)self + 0x6D0));
        *(void**)((char*)self + 0x6D0) = 0;
    }
    func_001A85D0_dtor(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0A80);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* func_001A8770(void* self);
extern "C" void func_003A1F18(cUIText* text, int a1);
extern char D_00465710[];

extern "C" void func_001C0A80(void* self)
{
    if (*(unsigned int*)((char*)self + 0x6D8) < *(unsigned int*)((char*)self + 0x6D4) && *(int**)((char*)self + 0x6D0) != 0) {
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465710));
        if (text != 0) {
            func_003A1F18(text, (*(int**)((char*)self + 0x6D0))[(*(unsigned int*)((char*)self + 0x6D8))++]);
        }
    }
    func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0B08);
#ifdef SKIP_ASM
extern "C" int func_001C0B08(void* self, int a1, int a2)
{
    return a2 != 9 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0B20);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" void func_003A1310(void* self, int a1);
extern char D_004619B8[];
extern char D_004619C8[];
extern char D_004619D8[];
extern char D_004619E8[];
extern char D_00465710[];
extern char D_00465720[];
extern char D_00465730[];

class cFEVObj_001C0B20 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08();
    virtual void v09(int on);
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
};

extern "C" int func_001C0B20(void* self)
{
    ((cFEVObj_001C0B20*)self)->v32();
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619B8));
    cUIText* a = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619C8));
    cUIText* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619D8));
    cUIText* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619E8));
    *(cUIText**)(o + 0x7C) = a;
    *(cUIText**)(o + 0x80) = b;
    if ((unsigned int)strlen(D_00465720) > 24) {
        o[0x8C] = 0;
    } else {
        strcpy(o + 0x8C, D_00465720);
    }
    if ((unsigned int)strlen(D_00465730) > 24) {
        o[0xA5] = 0;
    } else {
        strcpy(o + 0xA5, D_00465730);
    }
    if ((unsigned int)strlen(D_00465730) > 24) {
        o[0xA5] = 0;
    } else {
        strcpy(o + 0xA5, D_00465730);
    }
    *(cUIText**)(o + 0x84) = c;
    char* x = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465710));
    *(char**)(x + 0xB8) = o;
    func_003A1310(x, 1);
    ((cFEVObj_001C0B20*)x)->v07(1);
    if (o) {
        ((cFEVObj_001C0B20*)o)->v09(1);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0CE0);
#ifdef SKIP_ASM
extern char D_004619B8[];
int GetHashValue32(char* str);

extern "C" void func_001C0CE0(void* self, void* item)
{
    int hash = *(int*)((char*)item + 0x38);
    if (hash == GetHashValue32(D_004619B8)) {
        *(int*)((char*)item + 0x14) |= 1;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0D28);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void* func_001BEE30(void* mem, int a1);
extern "C" void* func_001B88F0(void* self, int a1, int a2);
extern "C" void* func_001BA3E0(void* self, int a1);
extern "C" void* func_001C1C50(void* self, int a1);
extern char D_00465740[];
extern char D_00462ED0[];
extern char D_00464848[];
extern const char D_004611A8[];

// On confirm (msg 5/6), opens the screen that matches this menu's id; other messages go to the base handler.
extern "C" void func_001C0D28(void* self, int a1, unsigned int msg)
{
    void* obj;
    if (a1 == 0) {
        return;
    }
    switch (msg) {
    case 5:
    case 6:
        switch (*(int*)((char*)self + 0x18)) {
        case 0x12:
            obj = func_001BEE30(cMemMan_alloc(0x6D4, D_00465740, 0, 0), *(int*)((char*)self + 0x10));
            break;
        case 0x14:
            obj = func_001B88F0(cMemMan_alloc(0x6F4, D_00462ED0, 0, 0), *(int*)((char*)self + 0x10), 1);
            break;
        case 0x15:
            obj = func_001B88F0(cMemMan_alloc(0x6F4, D_00462ED0, 0, 0), *(int*)((char*)self + 0x10), 0);
            break;
        case 0x16:
            obj = func_001BA3E0(cMemMan_alloc(0x6E0, D_00464848, 0, 0), *(int*)((char*)self + 0x10));
            break;
        case 0x13:
        default:
            obj = func_001C1C50(cMemMan_alloc(0x6D0, D_004611A8, 0, 0), *(int*)((char*)self + 0x10));
            break;
        }
        func_001A8A40(self, obj);
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

extern "C" void* func_001A8E40(void* self);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0E88__FPv);
#ifdef SKIP_ASM
void* func_001C0E88(void* self)
{
    return func_001A8E40(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0EA8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465778[];
extern char D_00465798[];
extern char D_004657C0[];
extern char D_004614E8[];

extern "C" void func_001C0EA8(void* self, void* popup)
{
    func_001DA528(popup, 2);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465778);
    func_001DA530(popup, 0, GetHashValue32(D_00465798));
    func_001DA510(popup, 0, GetHashValue32(D_004657C0), 8);
    func_001DA510(popup, 1, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0F40);
#ifdef SKIP_ASM
extern void* D_0046AB28[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001C0F40(void* self, int a1, int a2)
{
    func_001A8500_3(self, a1, a2);
    *(void***)((char*)self + 0x8) = D_0046AB28;
    *(int*)((char*)self + 0xC) = 0x48;
    *(int*)((char*)self + 0x6EC) = 0;
    *(int*)((char*)self + 0x720) = 0;
    *(int*)((char*)self + 0x724) = 0;
    *(int*)((char*)self + 0x728) = 0;
    *(int*)((char*)self + 0x72C) = 0;
    *(int*)((char*)self + 0x730) = 0;
    *(int*)((char*)self + 0x6F8) = 0;
    *(int*)((char*)self + 0x6FC) = 0;
    *(int*)((char*)self + 0x700) = 0;
    *(int*)((char*)self + 0x704) = 0;
    *(int*)((char*)self + 0x708) = 0;
    *(int*)((char*)self + 0x70C) = 0;
    *(int*)((char*)self + 0x710) = 0;
    *(int*)((char*)self + 0x714) = 0;
    *(int*)((char*)self + 0x718) = 0;
    *(int*)((char*)self + 0x71C) = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C0FC0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_003E6448(void* dst, int c, int n);
extern char D_004657E0[];
extern char D_005308B8[];

extern "C" void func_001C0FC0(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004657E0), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        func_003E6448(D_005308B8, 0, 0x20);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1038);
#ifdef SKIP_ASM
extern "C" void* func_001A8770(void* self);
extern "C" void* func_001C1038(void* self)
{
    if (*(int*)((char*)self + 0x6EC) != 0) {
        int t = (*(int*)((char*)self + 0x6E8))--;
        if (t == 0) {
            *(int*)((char*)self + 0x6E8) = 30;
        }
    }
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1080);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_004A1A80[];
extern char D_004657F8[];
extern char D_004A1C00[];
extern char D_00465808[];
extern char D_00465818[];
extern char D_00465828[];
extern char D_00465838[];
extern char D_00465848[];
extern char D_00465858[];
extern char D_00465868[];
extern char D_00465878[];
extern char D_00465890[];
extern char D_004658A0[];
extern char D_004658B0[];
extern char D_004658C0[];
extern char D_004658D0[];
extern char D_004658E0[];

class cFEVObj_001C1080 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
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
    virtual void v24(int on);
    virtual void v25(int on);
};

extern "C" void func_001C1080(void* self, cFEVObj_001C1080* obj)
{
    char* s = (char*)self;
    int id = *(int*)((char*)obj + 0x38);
    obj->v09(1);
    if (id == GetHashValue32(D_004A1A80)) {
        *(void**)(s + 0x6F4) = obj;
        obj->v25(1);
    } else if (id == GetHashValue32(D_004657F8)) {
        func_001A9AB8(self, (cUIListBox_001A9AB8*)obj, 1);
        obj->v24(1);
        *(void**)(s + 0x70C) = obj;
    } else if (id == GetHashValue32(D_004A1C00)) {
        func_001A9AB8(self, (cUIListBox_001A9AB8*)obj, 1);
        obj->v24(1);
        *(void**)(s + 0x710) = obj;
    } else if (id == GetHashValue32(D_00465808)) {
        func_001A9AB8(self, (cUIListBox_001A9AB8*)obj, 1);
        obj->v24(1);
        *(void**)(s + 0x714) = obj;
    } else if (id == GetHashValue32(D_00465818)) {
        func_001A9AB8(self, (cUIListBox_001A9AB8*)obj, 1);
        obj->v24(1);
        *(void**)(s + 0x718) = obj;
    } else if (id == GetHashValue32(D_00465828)) {
        func_001A9AB8(self, (cUIListBox_001A9AB8*)obj, 1);
        obj->v24(1);
        *(void**)(s + 0x71C) = obj;
    } else if (id == GetHashValue32(D_00465838)) {
        obj->v25(1);
        *(void**)(s + 0x6F8) = obj;
    } else if (id == GetHashValue32(D_00465848)) {
        obj->v25(1);
        *(void**)(s + 0x6FC) = obj;
    } else if (id == GetHashValue32(D_00465858)) {
        obj->v25(1);
        *(void**)(s + 0x700) = obj;
    } else if (id == GetHashValue32(D_00465868)) {
        obj->v25(1);
        *(void**)(s + 0x704) = obj;
    } else if (id == GetHashValue32(D_00465878)) {
        obj->v25(1);
        *(void**)(s + 0x708) = obj;
    } else if (id == GetHashValue32(D_00465890)) {
        *(void**)(s + 0x720) = obj;
    } else if (id == GetHashValue32(D_004658A0)) {
        *(void**)(s + 0x724) = obj;
    } else if (id == GetHashValue32(D_004658B0)) {
        *(void**)(s + 0x728) = obj;
    } else if (id == GetHashValue32(D_004658C0)) {
        *(void**)(s + 0x72C) = obj;
    } else if (id == GetHashValue32(D_004658D0)) {
        *(void**)(s + 0x730) = obj;
    } else if (id == GetHashValue32(D_004658E0)) {
        *(void**)(s + 0x6E4) = obj;
        obj->v09(0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C13E0);
#ifdef SKIP_ASM
class cFEVText_001C13E0 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern char D_00463CA0[];
extern char D_004658F0[];

extern "C" void func_001C13E0(void* self, int show)
{
    if (*(void**)((char*)self + 0x40) != 0) {
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00463CA0));
        if (text != 0) {
            ((cFEVText_001C13E0*)text)->v09(show);
        }
        text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004658F0));
        if (text != 0) {
            ((cFEVText_001C13E0*)text)->v09(show);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1488);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465900[];
extern char D_00465918[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00462C50[];
extern char D_004614E8[];

extern "C" void func_001C1488(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465900);
    func_001DA530(popup, 0, GetHashValue32(D_00465918));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(popup, 2, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 3, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1560);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void cBENewRaceInterface_setNumberAI(void* iface, int n);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001C13E0(void* self, int show);
extern "C" void func_001C17F8(void* self, int a1);
extern "C" void func_0025EE20(void* self, void* ids, int a2);
extern "C" void func_0025EED8(void* self);
extern "C" int func_0039A738(void* a);
extern void* D_004A28A8;
extern void* D_004A3028;
// D_00534B34 is a splat label inside D_00534B30
extern int D_00534B34[];
extern char D_00465938[];
extern char D_00462C88[];

struct sSelf_001C1560 {
    char pad[0x6D0];
    int ids[5];
};

struct sVE_001C1560 {
    short delta;
    short index;
    void (*fn)(void*);
};

class cFEVObj_001C1560 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
    virtual void v09(int on);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(void* owner, int msg);
};

// PORT: obj is a pointer passed as int (the unit's handler signature)
extern "C" void func_001C1560(void* self, int a1, unsigned int msg)
{
    char* s = (char*)self;
    switch (msg) {
    case 7:
        if (*(int*)(s + 0x6EC) == 0) {
            func_001A8918(self, a1, 7);
        }
        break;
    case 5:
        if (*(int*)(s + 0x6F4) == a1) {
            if (*(int*)(s + 0x6EC) != 0) {
                cUIText_setUnicodeStringByID(*(cUIText**)(s + 0x6E4), GetHashValue32(D_00465938));
                (*(cFEVObj_001C1560**)(s + 0x6F4))->v08(1);
                func_001C13E0(self, *(int*)(s + 0x6EC) ^ 1);
                func_0025EED8(D_004A3028);
            } else {
                *(int*)(s + 0x6F0) = 0;
                *(int*)(s + 0x6EC) = 1;
                sSelf_001C1560* o = (sSelf_001C1560*)s;
                int* ids = o->ids;
                func_001C13E0(self, 0);
                char* iface = (char*)cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
                D_00534B34[0] = func_0039A738(*(void**)(s + 0x70C)) != 0;
                sVE_001C1560* vt = *(sVE_001C1560**)(iface + 0xC);
                vt[1].fn(iface + vt[1].delta);
                cBENewRaceInterface_setNumberAI(cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 0), 0);
                o->ids[0] = func_0039A738(*(void**)(s + 0x70C));
                o->ids[1] = func_0039A738(*(void**)(s + 0x710));
                o->ids[2] = func_0039A738(*(void**)(s + 0x714));
                o->ids[3] = func_0039A738(*(void**)(s + 0x718));
                o->ids[4] = func_0039A738(*(void**)(s + 0x71C));
                func_0025EE20(D_004A3028, ids, *(signed char*)(s + 0x14));
                (*(cFEVObj_001C1560**)(s + 0x6E4))->v09(1);
                cUIText_setUnicodeStringByID(*(cUIText**)(s + 0x6F4), GetHashValue32(D_00462C88));
                *(int*)(s + 0x6E8) = 0x1E;
                func_001C17F8(self, 1);
            }
        }
        break;
    case 6:
        func_001C13E0(self, *(int*)(s + 0x6EC) ^ 1);
        if (*(int*)(s + 0x6EC) != 0) {
            cUIText_setUnicodeStringByID(*(cUIText**)(s + 0x6E4), GetHashValue32(D_00465938));
            (*(cFEVObj_001C1560**)(s + 0x6F4))->v08(1);
            func_0025EED8(D_004A3028);
        } else {
            (*(cFEVObj_001C1560**)(s + 0x20))->v17(self, 0x14);
        }
        break;
    default:
        func_001A8918(self, a1, msg);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C17D8__FPv);
#ifdef SKIP_ASM
int func_001C17D8(void* self)
{
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C17E0);
#ifdef SKIP_ASM
extern "C" int func_001C17E0(void* self, int a1, int a2)
{
    return a2 != 9 ? 0x101 : 0x100;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C17F8);
#ifdef SKIP_ASM
class cFEVObj_001C17F8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

extern "C" void func_001C17F8(void* self, int on)
{
    (*(cFEVObj_001C17F8**)((char*)self + 0x6F8))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x6FC))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x700))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x704))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x708))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x70C))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x710))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x714))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x718))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x71C))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x720))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x724))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x728))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x72C))->v08(on);
    (*(cFEVObj_001C17F8**)((char*)self + 0x730))->v08(on);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C19C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_001B0F60(void* self, int a1);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001AB178(void* self, int err);
extern "C" int func_0039F698(void* p);
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern const char D_00461C60[];
extern char D_00461618[];
extern char D_00465958[];

struct cFEObj_001C19C8 {
    int f0;
    int f4;
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
    virtual void v17(void* a1, int a2);
};

// Message handler: on 0xE7 confirms (if armed) or closes the screen; other ids as in the sibling handlers.
extern "C" void* func_001C19C8(void* self, int a1, int a2)
{
    switch (a1) {
    case 0xE6:
        *(int*)((char*)self + 0x6F0) = 1;
        break;
    case 0x10C: case 0x112:
        func_0039F698(*(char**)((char*)self + 0x10) + 0x18);
        func_001AB178(self, a1);
        break;
    case 0xE7:
        if (*(int*)((char*)self + 0x6F0) != 0) {
            void* p = func_001A9C50(self);
            char* sub = (char*)p + 0xBC;
            *(int*)((char*)p + 0xBC) = 1;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)p + 0xC4) = GetHashValue32(D_00465958);
            *(int*)((char*)p + 0xC0) = 3;
            *(int*)((char*)p + 0x150) = 0x82F;
            *(int*)((char*)p + 0x14C) = 6;
            func_001A9BC0(self, p);
        } else {
            *(int*)((char*)self + 0x6EC) = 0;
            (*(cFEObj_001C19C8**)((char*)self + 0x20))->v17(self, 0x14);
        }
        break;
    case 0xF3:
        func_001A8A40(self, func_001B0F60(cMemMan_alloc(0x6E4, D_00461C60, 0x100, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        return func_001A8E40_3(self, a1, a2);
    case 0xEF:
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1B48);
#ifdef SKIP_ASM
extern "C" int func_001C1B88(void* self, void* a1, int a2);
extern "C" int func_001A97B8(void* self, void* a1, int a2);

extern "C" int func_001C1B48(void* self, void* a1, int a2)
{
    int r;
    if (*(int*)((char*)a1 + 0x18) == 0x82F) {
        r = func_001C1B88(self, a1, a2);
    } else {
        r = func_001A97B8(self, a1, a2);
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001C1B88);
#ifdef SKIP_ASM
class cFEVText_001C1B88 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
};

int GetHashValue32(char* str);
struct cUIText;
void cUIText_setUnicodeStringByID(cUIText* self, int id);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001C13E0(void* self, int show);
extern "C" void func_001C17F8(void* self, int a1);
extern char D_00461618[];

extern "C" int func_001C1B88(void* self, void* a1, int a2)
{
    int r;
    if (a2 == 0xF || a2 == 0x14) {
        *(int*)((char*)self + 0x6EC) = 0;
        (*(cFEVText_001C1B88**)((char*)self + 0x6E4))->v09(0);
        func_001C13E0(self, *(int*)((char*)self + 0x6EC) ^ 1);
        cUIText_setUnicodeStringByID(*(cUIText**)((char*)self + 0x6F4), GetHashValue32(D_00461618));
        func_001C17F8(self, 0);
        r = func_001A97B8(self, a1, a2);
    } else {
        r = func_001A97B8(self, a1, a2);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1C50);
#ifdef SKIP_ASM
extern void* D_0046AA18[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001C1C50(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x4A;
    *(void***)((char*)self + 0x8) = D_0046AA18;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1C90);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001A9930(void* self);
extern char D_00465A38[];
extern void* D_004A3028;

extern "C" void func_001C1C90(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00465A38), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    if (*(int*)D_004A3028 == 0) {
        func_001A9930(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1D10__FPv);
#ifdef SKIP_ASM
void* func_001C1D10(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1D30);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465A48[];
extern char D_00465A60[];
extern char D_0045FE60[];
extern char D_00462C50[];
extern char D_00461458[];
extern char D_004614E8[];

extern "C" void func_001C1D30(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465A48);
    func_001DA530(popup, 0, GetHashValue32(D_00465A60));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_00462C50), 0);
    func_001DA510(popup, 2, GetHashValue32(D_00461458), 2);
    func_001DA510(popup, 3, GetHashValue32(D_004614E8), 1);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C1E08);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern char D_00465A80[];
extern char D_00465A90[];
extern char D_00465AA8[];
extern char D_00465AC0[];

static inline int IsHash1C1E08(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001C1E08(void* self, void* obj)
{
    if (IsHash1C1E08(*(int*)((char*)obj + 0x38), D_00465A80)) {
        *(int*)((char*)obj + 0x18) = 0;
    } else if (IsHash1C1E08(*(int*)((char*)obj + 0x38), D_00465A90)) {
        *(int*)((char*)obj + 0x18) = 1;
    } else if (IsHash1C1E08(*(int*)((char*)obj + 0x38), D_00465AA8)) {
        *(int*)((char*)obj + 0x18) = 2;
    } else if (IsHash1C1E08(*(int*)((char*)obj + 0x38), D_00465AC0)) {
        *(int*)((char*)obj + 0x18) = 3;
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C1EA8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C20F8);
#ifdef SKIP_ASM
extern void* D_0046A908[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001C20F8(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x4B;
    *(void***)((char*)self + 0x8) = D_0046A908;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2138);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern char D_00465B20[];

extern "C" void func_001C2138(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00465B20), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    *(int*)((char*)self + 0x6D0) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C21A0__FPv);
#ifdef SKIP_ASM
void* func_001C21A0(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C21C0);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465B38[];
extern char D_00465B50[];
extern char D_0045FE60[];
extern char D_00465B70[];
extern char D_004614E8[];
extern char D_00465B88[];

extern "C" void func_001C21C0(void* self, void* popup)
{
    func_001DA528(popup, 4);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465B38);
    func_001DA530(popup, 0, GetHashValue32(D_00465B50));
    func_001DA510(popup, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(popup, 1, GetHashValue32(D_00465B70), 0);
    func_001DA510(popup, 2, GetHashValue32(D_004614E8), 1);
    func_001DA510(popup, 3, GetHashValue32(D_00465B88), 7);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2298);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" int sprintf(char* buf, const char* fmt, ...);
void cUIText_setAsciiString(cUIText* self, const char* str);
extern char D_00465BA0[];
extern char D_004A1398[];
extern char D_00465BB0[];
extern char D_004A1390[];

class cFEVObj_001C2298 {
public:
    int field_0x0;
    int field_0x4;
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline int IsHash1C2298(int id, char* name) { return id == GetHashValue32(name); }

struct sOwner1C2298 {
    char pad[0x6D4];
    cUIText* slots[10];
};

extern "C" void func_001C2298(sOwner1C2298* self, cUIText* text)
{
    char buf[32];
    if (IsHash1C2298(*(int*)((char*)text + 0x38), D_00465BA0)) {
        cUIText_setAsciiString(text, D_004A1390);
        ((cFEVObj_001C2298*)text)->v09(1);
    } else if (IsHash1C2298(*(int*)((char*)text + 0x38), D_004A1398)) {
        *(int*)((char*)text + 0x14) |= 1;
    } else {
        int i;
        for (i = 0; i < 10; i++) {
            sprintf(buf, D_00465BB0, i);
            if (IsHash1C2298(*(int*)((char*)text + 0x38), buf)) {
                cUIText_setAsciiString(text, D_004A1390);
                ((cFEVObj_001C2298*)text)->v09(1);
                *(int*)((char*)text + 0x18) = i;
                self->slots[i] = text;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C23C0);
#ifdef SKIP_ASM
class cFEVObj_001C23C0 {
public:
    int field_0x0;
    int field_0x4;
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
};

extern "C" void func_001C2418(void* self);

extern "C" int func_001C23C0(cFEVObj_001C23C0* self, int a1)
{
    self->v32();
    if (a1 != 0) {
        func_001C2418(self);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2418);
#ifdef SKIP_ASM
extern "C" void func_001C2468(void* self, int i);

extern "C" void func_001C2418(void* self)
{
    int i;
    for (i = 0; i < 10; i++) {
        func_001C2468(self, i);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2468);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBEOptionInterface_getDefaultQuickKeyMessageHashValue(void* self, int i);
extern "C" void* cBXString_cBXString2(void* self, const char* str);
extern "C" void cBXString__cBXString(void* self, int flags);
extern "C" void* cBXString_Concat(void* self, const char* str);
extern "C" char* func_0014F6A8(void* self, int i);
extern "C" void func_003DCB20(char* dst, void* src);
extern "C" void func_001C2578(void* self, void* text, char* str);
extern void* D_004A28A8;
extern char D_004A1C08[];

struct sBXString1C2468 {
    char* str;
    sBXString1C2468() {}
    sBXString1C2468(const sBXString1C2468& o);
};

struct sVE_001C2468 {
    short delta;
    short index;
    void* (*fn)(void* self, int hash);
};

extern "C" void func_001C2468(void* self, int idx)
{
    char buf[16];
    sBXString1C2468 s;
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 4);
    sprintf(buf, D_004A1C08, idx + 1);
    cBXString_cBXString2(&s, buf);
    char* msg = func_0014F6A8(iface, idx);
    if (msg == 0) {
        char tmp[0x40];
        char* o = *(char**)((char*)D_004A28A8 + 0x8C);
        sVE_001C2468* vt = *(sVE_001C2468**)(o + 4);
        char* obj = o + vt[4].delta;
        void* str = vt[4].fn(obj, cBEOptionInterface_getDefaultQuickKeyMessageHashValue(iface, idx));
        func_003DCB20(tmp, str);
        cBXString_Concat(&s, tmp);
    } else {
        cBXString_Concat(&s, msg);
    }
    func_001C2578(self, *(void**)((char*)self + (idx << 2) + 0x6D4), s.str);
    cBXString__cBXString(&s, 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2578);
#ifdef SKIP_ASM
struct cUIText;
void cUIText_setAsciiString(cUIText* self, const char* str);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern "C" float func_00391FB0(void* self, const char* str, void* out, int n, float sx, float sy);
extern "C" char* func_003A04F0(void* text);
extern "C" char* func_004162D0(char*, const char*);
extern char D_004A1BD0[];

struct sVec3_1C2578 {
    float x, y, z;
};

struct sVec2_1C2578 {
    float x, y;
    sVec2_1C2578(float x_, float y_) : x(x_), y(y_) {}
};

struct sRect1C2578 {
    float x, y, w, h;
};

class cFEVObj_001C2578 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
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
    virtual void v20(sRect1C2578* out);
};

static inline void Measure1C2578(cUIText* text, const char* s, sRect1C2578* out)
{
    char* f = func_003A04F0(text);
    func_00391FB0(f, s, out, 0, *(float*)(f + 0x38), *(float*)(f + 0x3C));
}

extern "C" void func_001C2578(void* self, void* vtext, char* str)
{
    cUIText* text = (cUIText*)vtext;
    int cut = 0;
    sVec3_1C2578 scale = *(sVec3_1C2578*)((char*)text + 0x50);
    sRect1C2578 box;
    ((cFEVObj_001C2578*)text)->v20(&box);
    char* f = func_003A04F0(text);
    float sx = scale.x;
    float sy = scale.y;
    *(float*)(f + 0x38) = *(float*)(f + 0x30) * sx;
    *(float*)(f + 0x3C) = *(float*)(f + 0x34) * sy;
    int i = strlen(str) - 1;
    char buf[0x50];
    strcpy(buf, str);
    const char* ell = D_004A1BD0;
    sRect1C2578 sz;
    sRect1C2578 dots;
    Measure1C2578(text, ell, &dots);
    Measure1C2578(text, buf, &sz);
    while (box.x - dots.w < sz.w) {
        cut = 1;
        buf[i--] = 0;
        Measure1C2578(text, buf, &sz);
    }
    if (cut) {
        func_004162D0(buf, ell);
        cUIText_setAsciiString(text, buf);
    } else {
        cUIText_setAsciiString(text, str);
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C2740);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2A18);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int strlen(const char* s);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* func_001A9C50(void* self);
extern "C" void func_001A9BC0(void* self, void* popup);
void func_001C57C0(void* self, int a1, int a2);
extern "C" void func_0014F6E8(void* iface, int i);
extern "C" void func_001C2468(void* self, int i);
extern char D_00465C48[];
extern char D_00461618[];
extern char D_00535617[];

struct sVE1C2A18 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" void func_001C2A18(void* self)
{
    char* p = *(char**)((char*)self + 0x69C);
    unsigned int idx = *(unsigned int*)(p + 0x18);
    char* name = p + 0x74;
    if (idx < 10) {
        char* iface = (char*)cBE_getInterface_Fv(cBE_getBE(), 4);
        if (strlen(name) == 0) {
            void* pop = func_001A9C50(self);
            char* sub = (char*)pop + 0xBC;
            *(int*)((char*)pop + 0xBC) = 1;
            *(int*)((char*)pop + 0xC4) = GetHashValue32(D_00465C48);
            *(int*)((char*)pop + 0xC0) = 3;
            func_001C57C0(sub, 0, GetHashValue32(D_00461618));
            *(int*)((char*)pop + 0x150) = 0x83C;
            func_001A9BC0(self, pop);
            func_0014F6E8(iface, idx);
        } else {
            char* src = *(char**)((char*)self + 0x69C) + 0x74;
            strcpy(D_00535617 + (idx << 6), src);
        }
        *(int*)((char*)self + 0x6D0) = 1;
        sVE1C2A18* vt = *(sVE1C2A18**)(iface + 0xC);
        vt[1].fn(iface + vt[1].delta);
        func_001C2468(self, idx);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2B48);
#ifdef SKIP_ASM
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001C2C50(void* self, void* a1, int a2);
extern "C" void func_001C2BA8(void* self, void* a1, int a2);

extern "C" void func_001C2B48(void* self, void* a1, int a2)
{
    switch (*(int*)((char*)a1 + 0x18)) {
    case 0x83A:
        func_001C2C50(self, a1, a2);
        break;
    case 0x83B:
        func_001C2BA8(self, a1, a2);
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2BA8);
#ifdef SKIP_ASM
class cBEVIface_001C2BA8 {
public:
    int f0;
    int f4;
    int f8;
    virtual void v01();
};

extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0014F758(void* self);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void func_001C2418(void* self);

extern "C" void func_001C2BA8(void* self, void* a1, int a2)
{
    if (a2 == 0xF) {
        cBEVIface_001C2BA8* iface = (cBEVIface_001C2BA8*)cBE_getInterface_Fv(cBE_getBE(), 4);
        func_0014F758(iface);
        *(int*)((char*)self + 0x6D0) = 1;
        iface->v01();
        func_001C2418(self);
        func_001A97B8(self, a1, 0xF);
    } else {
        func_001A97B8(self, a1, a2);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001C2C50);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_0018D7F0(void* mem, int engine, int a2, int a3, int a4);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" int func_001A97B8(void* self, void* a1, int a2);
extern "C" void* func_001C1C50(void* self, int a1);
extern const char D_00460D90[];
extern const char D_004611A8[];

extern "C" void func_001C2C50(void* self, void* a1, int a2)
{
    switch (a2) {
    case 0xF:
        func_001A97B8(self, a1, 0xF);
        func_001A8A40(self, func_0018D7F0(cMemMan_alloc(0x23C, D_00460D90, 0, 0), *(int*)((char*)self + 0x10), 2, 1, 1));
        break;
    case 0x10:
        func_001A97B8(self, a1, 0x10);
        func_001A8A40(self, func_001C1C50(cMemMan_alloc(0x6D0, D_004611A8, 0, 0), *(int*)((char*)self + 0x10)));
        break;
    default:
        func_001A97B8(self, a1, a2);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2D18);
#ifdef SKIP_ASM
extern void* D_00468278[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

struct sFEState1C2D18 {
    char pad[0x6D0];
    int slots[4];       // 0x6D0
    int a;              // 0x6E0
    int b;              // 0x6E4
    int c;              // 0x6E8
};

extern "C" void* func_001C2D18(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(void***)((char*)self + 0x8) = D_00468278;
    *(int*)((char*)self + 0x6EC) = 1;
    *(int*)((char*)self + 0xC) = 0x42;
    sFEState1C2D18* s = (sFEState1C2D18*)self;
    s->a = 0;
    s->b = 0;
    s->c = 0;
    for (int i = 3; i >= 0; i--) {
        s->slots[i] = 0;
    }
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2E00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_001C3310(void* self);
extern char D_00465C68[];

extern "C" void func_001C2E00(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_00465C68), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        func_001C3310(self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2E70);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001C2E70()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 5, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2EE0__FPv);
#ifdef SKIP_ASM
void* func_001C2EE0(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C2F00);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void func_0039AB00(void* self, int a1);
extern "C" void func_0039B760(void* self, unsigned char a1);
extern char D_00465C78[];
extern char D_00465C88[];
extern char D_00465C98[];
extern char D_004A1C10[];
extern char D_00465CA8[];
extern char D_00465CB8[];
extern char D_00465CC8[];
extern char D_00465CE0[];
extern char D_004A1C18[];
extern char D_00465CF0[];
extern char D_00465D00[];
extern char D_00465D10[];
extern char D_004A1BB8[];
extern char D_00465D20[];
extern char D_00465D30[];
extern char D_00465D40[];
extern char D_00465D50[];
extern char D_00465D60[];
extern char D_00465D70[];
extern char D_00465D80[];

struct sCol_001C2F00 {
    float r, g, b, a;
    sCol_001C2F00(const float& r_) : r(r_), g(0.0f), b(0.0f), a(0.0f) {}
};

class cFEVObj_001C2F00 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08();
    virtual void v09(int on);
    virtual void v10();
    virtual void v11(const sCol_001C2F00& c);
};

static inline int IsHash_001C2F00(int id, char* name) { return id == GetHashValue32(name); }

extern "C" void func_001C2F00(void* self, cFEVObj_001C2F00* obj)
{
    char* s = (char*)self;
    char* o = (char*)obj;
    if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465C78) || IsHash_001C2F00(*(int*)(o + 0x38), D_00465C88)) {
        *(int*)(o + 0x14) &= ~1;
        obj->v11(sCol_001C2F00(1.0f));
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465C98)) {
        obj->v09(0);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_004A1C10)) {
        obj->v09(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465CA8)) {
        obj->v09(0);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465CB8)) {
        obj->v09(0);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465CC8)) {
        obj->v09(0);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465CE0)) {
        obj->v09(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_004A1C18)) {
        obj->v09(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465CF0)) {
        obj->v07(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D00)) {
        obj->v07(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D10)) {
        obj->v07(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_004A1BB8)) {
        obj->v09(1);
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D20)) {
        *(int*)(o + 0x14) &= ~1;
        obj->v07(1);
        *(void**)(s + 0x6D0) = obj;
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D30)) {
        *(void**)(s + 0x6D4) = obj;
        *(int*)(o + 0x90) |= 8;
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D40)) {
        *(void**)(s + 0x6D8) = obj;
        *(int*)(o + 0x90) |= 8;
    } else if (IsHash_001C2F00(*(int*)(o + 0x38), D_00465D50)) {
        func_0039B760(obj, 10);
        *(void**)(s + 0x6DC) = obj;
        func_0039AB00(obj, 1);
        (*(cFEVObj_001C2F00**)(s + 0x6DC))->v07(1);
    } else {
        char buf[32];
        for (int i = 0; i < 10; i++) {
            sprintf(buf, D_00465D60, i);
            if (IsHash_001C2F00(*(int*)(o + 0x38), buf)) {
                obj->v09(1);
                break;
            }
            sprintf(buf, D_00465D70, i);
            if (IsHash_001C2F00(*(int*)(o + 0x38), buf)) {
                obj->v09(1);
                break;
            }
            sprintf(buf, D_00465D80, i);
            if (IsHash_001C2F00(*(int*)(o + 0x38), buf)) {
                obj->v09(1);
                break;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C32B8);
#ifdef SKIP_ASM
class cFEVObj_001C32B8 {
public:
    int field_0x0;
    int field_0x4;
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
};

extern "C" void func_001C3EE8(void* self, int a1);

extern "C" int func_001C32B8(cFEVObj_001C32B8* self, int a1)
{
    self->v32();
    if (a1 != 0) {
        func_001C3EE8(self, 0);
    }
    return 1;
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C3310);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C3570);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465DC0[];
extern char D_00465DD8[];
extern char D_0045FE60[];
extern char D_0045FE40[];
extern char D_00461458[];
extern char D_00465DF8[];
extern char D_004614E8[];

extern "C" void func_001C3570(void* self, void* menu)
{
    func_001DA528(menu, 5);
    *(int*)((char*)menu + 0x54) = GetHashValue32(D_00465DC0);
    func_001DA530(menu, 0, GetHashValue32(D_00465DD8));
    func_001DA510(menu, 0, GetHashValue32(D_0045FE60), 3);
    func_001DA510(menu, 1, GetHashValue32(D_0045FE40), 4);
    func_001DA510(menu, 2, GetHashValue32(D_00461458), 2);
    func_001DA510(menu, 3, GetHashValue32(D_00465DF8), 8);
    func_001DA510(menu, 4, GetHashValue32(D_004614E8), 1);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C3668);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C3D68);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern char D_00465CE0[];
extern char D_004A1C18[];

struct sVec3_001C3D68 {
    float x;
    float y;
    float z;
};

struct cUIObj_001C3D68 {
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a1);
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
    virtual void v20(void* out);
};

static inline sVec3_001C3D68 GetPos_001C3D68(cUIObj_001C3D68* o)
{
    return *(sVec3_001C3D68*)((char*)o + 0x44);
}

extern "C" void func_001C3D68(void* self, int pos, int count)
{
    if (*(void**)((char*)self + 0x40) == 0) return;
    if (pos < 0) return;
    if (count < pos) return;
    if (count <= 0) return;
    cUIObj_001C3D68* track = (cUIObj_001C3D68*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465CE0));
    cUIObj_001C3D68* thumb = (cUIObj_001C3D68*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A1C18));
    if (thumb == 0) return;
    if (track == 0) return;
    sVec3_001C3D68 size;
    track->v20(&size);
    sVec3_001C3D68 p = *(sVec3_001C3D68*)((char*)track + 0x44);
    float fpos = (float)pos;
    if (count >= 2) count--;
    float step = (size.y + -17.0f) / (float)count;
    sVec3_001C3D68 np = *(sVec3_001C3D68*)((char*)thumb + 0x44);
    np.y = p.y + fpos * step + 20.0f;
    *(sVec3_001C3D68*)((char*)thumb + 0x44) = np;
    thumb->v09(1);
    track->v09(1);
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C3EE8);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4538);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern char D_00465EA8[];
extern char D_00465D30[];
extern char D_00465C78[];
extern char D_00465EB8[];
extern char D_00465D40[];
extern char D_00465C88[];
extern char D_00465EC8[];
extern char D_00465ED8[];
extern char D_00465E10[];
extern char D_00465E20[];

class cFEVObj_001C4538 {
public:
    char pad[0x8];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int on);
};

static inline void Show_001C4538(void* self, char* name, int on)
{
    cFEVObj_001C4538* o = (cFEVObj_001C4538*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(name));
    if (o != 0) {
        o->v09(on);
    }
}

extern "C" void func_001C4538(void* self, int on)
{
    if (*(void**)((char*)self + 0x40) == 0) {
        return;
    }
    Show_001C4538(self, D_00465EA8, on);
    Show_001C4538(self, D_00465D30, on);
    Show_001C4538(self, D_00465C78, on);
    Show_001C4538(self, D_00465EB8, on);
    Show_001C4538(self, D_00465D40, on);
    Show_001C4538(self, D_00465C88, on);
    Show_001C4538(self, D_00465EC8, on);
    Show_001C4538(self, D_00465ED8, on);
    if (on == 0) {
        Show_001C4538(self, D_00465E10, 0);
        Show_001C4538(self, D_00465E20, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C47A8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data);
extern "C" int cUIListBox_addEntryByStringID(void* box, int id, int a2);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" const char* func_001453B8(void* iface, int id);
extern "C" void func_001C49C8(void* self);
extern "C" void func_0039A670(void* self);
extern char D_00465C78[];
extern char D_00465EE8[];
extern int D_0046DB98[];
extern int D_0046DB88[];

class cFEVObj_001C47A8 {
public:
    char pad[0x8];
    // vptr at 0x8; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08(int on);
};

extern "C" void func_001C47A8(void* self)
{
    cFEVObj_001C47A8* box = (cFEVObj_001C47A8*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465C78));
    if (box == 0) {
        return;
    }
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    switch (*(int*)((char*)self + 0x6E0)) {
    case 0:
        func_0039A670(box);
        box->v08(1);
        break;
    case 1:
        func_0039A670(box);
        box->v08(0);
        for (int i = 0; i < 2; i++) {
            int id = D_0046DB98[i];
            if (id == 4) {
                cUIListBox_addEntryByStringID(box, GetHashValue32(D_00465EE8), 4);
            } else {
                cUIListBox_addEntryByAsciiString(box, func_001453B8(iface, id), id);
            }
        }
        func_001C49C8(self);
        break;
    case 2:
        func_0039A670(box);
        box->v08(0);
        for (int j = 0; j < 4; j++) {
            int id = D_0046DB88[j];
            if (id == 4) {
                cUIListBox_addEntryByStringID(box, GetHashValue32(D_00465EE8), 4);
            } else {
                cUIListBox_addEntryByAsciiString(box, func_001453B8(iface, id), id);
            }
        }
        func_001C49C8(self);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C49C8);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" unsigned char cUIListBox_addEntryByAsciiString(void* self, const char* text, int data);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" const char* func_00144C60(void* iface, int id);
extern "C" void func_001C3310(void* self);
extern "C" void func_001C4B78(void* self, int idx);
extern "C" void func_0039A670(void* self);
extern "C" int func_0039A738(void* a);
extern "C" void func_0039A7A8(void* self, int a1);
extern char D_00465C78[];
extern char D_00465C88[];
extern char D_00465D50[];

struct sEntry1C49C8 {
    int data;
    int name;
    int key;
    int mode;
};
extern sEntry1C49C8 D_0046D9B8[];

extern "C" void func_001C49C8(void* self)
{
    cUIText* box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465C78));
    if (box == 0) {
        return;
    }
    int key = func_0039A738(box);
    void* iface = cBE_getInterface_Fv(cBE_getBE(), 0);
    box = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465C88));
    if (box == 0) {
        return;
    }
    func_0039A670(box);
    int found = 0;
    sEntry1C49C8 first;
    int i;
    for (i = 0; i < 29; i++) {
        sEntry1C49C8 e = D_0046D9B8[i];
        if (e.key == key && e.mode == *(int*)((char*)self + 0x6E0)) {
            cUIListBox_addEntryByAsciiString(box, func_00144C60(iface, e.name), e.data);
            if (!found) {
                first = e;
                found = 1;
            }
        }
    }
    if (first.data >= 0) {
        if (first.data < 29) {
            func_001C4B78(self, first.data);
            func_0039A7A8(box, 0);
            cUIMenu_setSelectedByIndex(cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465D50)), 0);
        }
    }
    func_001C3310(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4B78);
#ifdef SKIP_ASM
extern void* D_004A3028;
extern "C" void func_0025E348(void* self, int slot);

extern "C" void func_001C4B78(void* self, int slot)
{
    *(int*)((char*)self + 0x6E8) = 0;
    func_0025E348(D_004A3028, slot);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4B98);
#ifdef SKIP_ASM
extern "C" void func_001C3310(void* self);

extern "C" int func_001C4B98(void* self, void* a1, int a2, int a3)
{
    switch (a2) {
    case 6:
        return 0x100;
    case 4:
        *(int*)((char*)self + 0x6E8) = a3;
        func_001C3310(self);
        break;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4BD8);
#ifdef SKIP_ASM
// PORT: func_0039E508__FPv is called with (self, pad) here; bind the 2-arg form to that symbol.
void func_0039E508_2(void* self, void* pad) __asm__("func_0039E508__FPv");
extern "C" void func_001C4D28(void* self);
extern "C" void func_001C4E40(void* self);

struct sVE1C4BD8 {
    short delta;
    short index;
    int (*fn)(void*);
};

static inline int Pad1C4BD8(char* pad, int slot)
{
    sVE1C4BD8* vt = *(sVE1C4BD8**)(pad + 0x8);
    return vt[slot].fn(pad + vt[slot].delta);
}

extern "C" void func_001C4BD8(void* self, char* pad)
{
    func_0039E508_2(self, pad);
    if ((Pad1C4BD8(pad, 17) || Pad1C4BD8(pad, 18) || Pad1C4BD8(pad, 20) || Pad1C4BD8(pad, 19)) &&
        *(unsigned int*)((char*)self + 0x6E4) < 3) {
        if (Pad1C4BD8(pad, 17)) {
            func_001C4E40(self);
        } else if (Pad1C4BD8(pad, 18)) {
            func_001C4D28(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4CD8);
#ifdef SKIP_ASM
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);

extern "C" void* func_001C4CD8(void* self, int msg)
{
    if (msg == 0xE1) {
        func_001C3310(self);
        cUIMenu_setSelectedByIndex(*(void**)((char*)self + 0x6DC), 0);
        return 0;
    }
    return func_001A8E40(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4D28);
#ifdef SKIP_ASM
extern char D_004A5A58;

struct sVE1C4D28 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void Show1C4D28(char* o, int on)
{
    sVE1C4D28* vt = *(sVE1C4D28**)(o + 0x8);
    vt[7].fn(o + vt[7].delta, on);
}

extern "C" void func_001C4D28(void* self)
{
    char* snd = *(char**)(*(char**)((char*)self + 0x10) + 0x14);
    if (snd == 0) snd = &D_004A5A58;
    if (snd != 0) {
        sVE1C4D28* vt = *(sVE1C4D28**)snd;
        vt[2].fn(snd + vt[2].delta, 1);
    }
    if (*(unsigned int*)((char*)self + 0x6E4) != 3) {
        Show1C4D28(*(char**)((char*)self + (*(unsigned int*)((char*)self + 0x6E4) << 2) + 0x6D0), 0);
    }
    *(unsigned int*)((char*)self + 0x6E4) += 1;
    if (*(unsigned int*)((char*)self + 0x6E4) >= 4) {
        *(unsigned int*)((char*)self + 0x6E4) = 0;
    }
    if (*(unsigned int*)((char*)self + 0x6E4) == 3) {
        Show1C4D28(*(char**)((char*)self + 0x6DC), 1);
        func_001C4D28(self);
    } else {
        char* item = *(char**)((char*)self + (*(unsigned int*)((char*)self + 0x6E4) << 2) + 0x6D0);
        if ((*(int*)(item + 0x14) >> 6) & 1) {
            Show1C4D28(item, 1);
        } else {
            func_001C4D28(self);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C4E40);
#ifdef SKIP_ASM
extern char D_004A5A58;

struct sVE1C4E40 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

static inline void Show1C4E40(char* o, int on)
{
    sVE1C4E40* vt = *(sVE1C4E40**)(o + 0x8);
    vt[7].fn(o + vt[7].delta, on);
}

extern "C" void func_001C4E40(void* self)
{
    char* snd = *(char**)(*(char**)((char*)self + 0x10) + 0x14);
    if (snd == 0) snd = &D_004A5A58;
    if (snd != 0) {
        sVE1C4E40* vt = *(sVE1C4E40**)snd;
        vt[2].fn(snd + vt[2].delta, 1);
    }
    if (*(unsigned int*)((char*)self + 0x6E4) != 3) {
        Show1C4E40(*(char**)((char*)self + (*(unsigned int*)((char*)self + 0x6E4) << 2) + 0x6D0), 0);
    }
    *(unsigned int*)((char*)self + 0x6E4) -= 1;
    if (*(unsigned int*)((char*)self + 0x6E4) >= 4) {
        *(unsigned int*)((char*)self + 0x6E4) = 3;
    }
    if (*(unsigned int*)((char*)self + 0x6E4) == 3) {
        Show1C4E40(*(char**)((char*)self + 0x6DC), 1);
        func_001C4E40(self);
    } else {
        char* item = *(char**)((char*)self + (*(unsigned int*)((char*)self + 0x6E4) << 2) + 0x6D0);
        if ((*(int*)(item + 0x14) >> 6) & 1) {
            Show1C4E40(item, 1);
        } else {
            func_001C4E40(self);
        }
    }
}
#endif

INCLUDE_ASM("fe/feasyncfile", func_001C4F58);

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5018);
#ifdef SKIP_ASM
extern void* D_00468168[];
// PORT: func_001A8500 takes (self, a1, a2); the unit declares it with one arg
void* func_001A8500_3(void* self, int a1, int a2) __asm__("func_001A8500");

extern "C" void* func_001C5018(void* self, int a1)
{
    func_001A8500_3(self, a1, 0);
    *(int*)((char*)self + 0xC) = 0x43;
    *(void***)((char*)self + 0x8) = D_00468168;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5098);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void func_0025E0C8(void* self, int a1);
extern char D_004A1C30[];
extern void* D_004A3028;

extern "C" void func_001C5098(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A1C30), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
        func_0025E0C8(D_004A3028, 1);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5108);
#ifdef SKIP_ASM
extern "C" void func_00260F80();
extern "C" int func_00261460(void* self);
extern "C" void func_002613C8(void* self);
extern "C" void func_0025B800(void* self);
extern "C" void func_00262768(void* self, int a1, int a2, int a3, int a4, int a5);
extern void* D_004A3328;
extern void* D_004A3028;

extern "C" void func_001C5108()
{
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028);
    }
    func_00262768(D_004A3328, 1, 4, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5178__FPv);
#ifdef SKIP_ASM
void* func_001C5178(void* self)
{
    return func_001A8770(self);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5198);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strlen(const char* s);
extern char D_00465F28[];
extern char D_004619C8[];
extern char D_004619D8[];
extern char D_004619E8[];
extern char D_00465F38[];
extern char D_00465720[];
extern char D_00465730[];

class cFEVObj_001C5198 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int on);
    virtual void v08();
    virtual void v09(int on);
};

extern "C" int func_001C5198(void* self, int on)
{
    if (on) {
        char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465F28));
        cUIText* a = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619C8));
        cUIText* b = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619D8));
        cUIText* c = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004619E8));
        *(cUIText**)(o + 0x7C) = a;
        *(cUIText**)(o + 0x80) = b;
        if ((unsigned int)strlen(D_00465720) > 24) {
            o[0x8C] = 0;
        } else {
            strcpy(o + 0x8C, D_00465720);
        }
        if ((unsigned int)strlen(D_00465730) > 24) {
            o[0xA5] = 0;
        } else {
            strcpy(o + 0xA5, D_00465730);
        }
        *(cUIText**)(o + 0x84) = c;
        char* x = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465F38));
        *(char**)(x + 0xB8) = o;
        ((cFEVObj_001C5198*)x)->v07(1);
        if (o) {
            ((cFEVObj_001C5198*)o)->v09(1);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5310);
#ifdef SKIP_ASM
extern char D_00465F48[];
int GetHashValue32(char* str);

class cFEVObj_001C5310 {
public:
    int field_0x0;
    int field_0x4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07(int a1);
};

extern "C" void func_001C5310(void* self, cFEVObj_001C5310* item)
{
    int hash = *(int*)((char*)item + 0x38);
    if (hash == GetHashValue32(D_00465F48)) {
        item->v07(1);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/feasyncfile", func_001C5368);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void func_001A8918(void* self, int a1, int msg);
extern "C" void func_001A8A40(void* self, void* obj);
extern "C" void func_001A9B58(void* self);
extern "C" void* func_001C1C50(void* self, int a1);
extern const char D_004611A8[];

extern "C" void func_001C5368(void* self, int a1, unsigned int msg)
{
    if (a1 != 0) {
        switch (msg) {
        case 8:
            if ((*(int*)((char*)self + 0x1C) & 6) == 0) {
                func_001A9B58(self);
            }
            break;
        case 6:
            func_001A8A40(self, func_001C1C50(cMemMan_alloc(0x6D0, D_004611A8, 0, 0), *(int*)((char*)self + 0x10)));
            break;
        case 5:
            break;
        default:
            func_001A8918(self, a1, msg);
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5420);
#ifdef SKIP_ASM
extern "C" int func_001C5420(void* self, void* a1, int a2)
{
    return a2 == 4 ? 0 : 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5430);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
struct cUIText;
struct cBXString;
extern "C" cUIText* cUIScreen_getObjectByHashName(void* screen, int hash);
extern "C" void* cBXString_cBXString1(void* self, void* other);
extern "C" void cBXString__cBXString(void* self, int flags);
int cBXString_FindLastOf(cBXString* self, char ch, int len);
extern "C" void func_00318E68(cBXString* self, int idx, char ch);
extern "C" void func_003A19F8(cUIText* text, char* str);
// PORT: unit declares func_001A8E40 with one arg; the handler passes (self, a1, a2) through
extern "C" void* func_001A8E40_3(void* self, int a1, int a2) __asm__("func_001A8E40");
extern char D_00465F38[];

struct sBXString1C5430 {
    char* str;
    sBXString1C5430() {}
    sBXString1C5430(const sBXString1C5430& o);
};

// PORT: a2 is a message-data pointer passed as int
extern "C" void* func_001C5430(void* self, int msg, int a2)
{
    if (msg == 0xE2) {
        cUIText* text = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_00465F38));
        if (text != 0) {
            sBXString1C5430 s;
            cBXString_cBXString1(&s, (char*)a2 + 8);
            int pos;
            while ((pos = cBXString_FindLastOf((cBXString*)&s, '\n', 0)) != -1) {
                int next = pos + 1;
                if (s.str[next] == '\n') {
                    func_00318E68((cBXString*)&s, pos, '\r');
                    func_00318E68((cBXString*)&s, next, '\r');
                } else {
                    func_00318E68((cBXString*)&s, pos, ' ');
                }
            }
            func_003A19F8(text, s.str);
            cBXString__cBXString(&s, 2);
            return 0;
        }
    } else {
        return func_001A8E40_3(self, msg, a2);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5540);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
void func_001DA510(void* self, int i, int a, int b);
void func_001DA528(void* self, int val);
void func_001DA530(void* self, int i, int value);
extern char D_00465F58[];
extern char D_00465F70[];
extern char D_00465F90[];
extern char D_004614E8[];
extern char D_00461458[];

extern "C" void func_001C5540(void* self, void* popup)
{
    func_001DA528(popup, 3);
    *(int*)((char*)popup + 0x54) = GetHashValue32(D_00465F58);
    func_001DA530(popup, 0, GetHashValue32(D_00465F70));
    func_001DA510(popup, 0, GetHashValue32(D_00465F90), 3);
    func_001DA510(popup, 1, GetHashValue32(D_004614E8), 1);
    func_001DA510(popup, 2, GetHashValue32(D_00461458), 2);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C55F8);
#ifdef SKIP_ASM
extern "C" void func_001C5630(void* self);
extern void* D_0046CCA8[];

extern "C" void* func_001C55F8(void* self)
{
    *(void***)((char*)self + 0xC8) = D_0046CCA8;
    func_001C5630(self);
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5630);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int c, int n);

struct sVec3_1C5630 {
    int x, y, z;
};

extern sVec3_1C5630 D_004FF0D8;

extern "C" void func_001C5630(void* self)
{
    char* b = (char*)self + 0x54;
    char* a = (char*)self + 0x24;
    func_00416210((char*)self + 0x4, 0, 8);
    func_00416210((char*)self + 0xC, 0, 8);
    func_00416210((char*)self + 0x14, 0, 8);
    func_00416210((char*)self + 0x1C, 0, 8);
    int i;
    for (i = 4; i >= 0; i--) {
        func_00416210(a, 0, 8);
        a += 8;
        func_00416210(b, 0, 0xC);
        b += 0xC;
    }
    func_00416210((char*)self + 0x4C, 0, 8);
    *(int*)((char*)self + 0x98) = 0;
    *(int*)((char*)self + 0xA8) = 1;
    *(int*)((char*)self + 0xBC) = 1;
    *(int*)((char*)self + 0x94) = 0;
    *(int*)((char*)self + 0xB8) = 0;
    *(int*)((char*)self + 0xB0) = 0;
    *(int*)((char*)self + 0x0) = 0;
    *(int*)((char*)self + 0x90) = 0;
    *(sVec3_1C5630*)((char*)self + 0x9C) = D_004FF0D8;
    *(int*)((char*)self + 0xAC) = -1;
    *(int*)((char*)self + 0xC0) = 0;
    *(int*)((char*)self + 0xB4) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5750);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_0046CCA8[];

extern "C" void func_001C5750(void* self, int flags)
{
    *(void***)((char*)self + 0xC8) = D_0046CCA8;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5780__FPvii);
#ifdef SKIP_ASM
struct cFEAsyncSlot {
    int mState; // 0x0
    int mValue; // 0x4
};

struct cFEAsyncSlots {
    char pad_0x00[0x24];
    cFEAsyncSlot mSlots[1]; // 0x24
};

void func_001C5780(void* self, int a1, int a2)
{
    cFEAsyncSlots* s = (cFEAsyncSlots*)self;
    s->mSlots[a1].mValue = a2;
    s->mSlots[a1].mState = 2;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C57A0__FPvii);
#ifdef SKIP_ASM
void func_001C57A0(void* self, int a1, int a2)
{
    cFEAsyncSlots* s = (cFEAsyncSlots*)self;
    s->mSlots[a1].mValue = a2;
    s->mSlots[a1].mState = 1;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C57C0__FPvii);
#ifdef SKIP_ASM
void func_001C57C0(void* self, int a1, int a2)
{
    cFEAsyncSlots* s = (cFEAsyncSlots*)self;
    s->mSlots[a1].mValue = a2;
    s->mSlots[a1].mState = 3;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5800);
#ifdef SKIP_ASM
extern "C" void* func_001C5800(void* self, int a1)
{
    return (char*)self + ((a1 << 3) + 0x24);
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5838);
#ifdef SKIP_ASM
struct cFEAsyncReq {
    int mState; // 0x0
    int mValue; // 0x4
    int mExtra; // 0x8
};

struct cFEAsyncReqs {
    char pad_0x00[0x54];
    cFEAsyncReq mReqs[1]; // 0x54
};

extern "C" void func_001C5838(void* self, int a1, int a2, int a3)
{
    cFEAsyncReqs* s = (cFEAsyncReqs*)self;
    s->mReqs[a1].mValue = a2;
    s->mReqs[a1].mState = 1;
    s->mReqs[a1].mExtra = a3;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5860);
#ifdef SKIP_ASM
extern "C" void func_001C5860(void* self, int a1)
{
    char* p = (char*)self + a1 * 0xc;
    *(int*)(p + 0x54) = 0;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C5878);
#ifdef SKIP_ASM
extern "C" void func_001C5878(void* self, int a1, int a2, int a3)
{
    cFEAsyncReqs* s = (cFEAsyncReqs*)self;
    s->mReqs[a1].mValue = a2;
    s->mReqs[a1].mState = 3;
    s->mReqs[a1].mExtra = a3;
}
#endif

//100%
INCLUDE_ASM("fe/feasyncfile", func_001C58D0);
#ifdef SKIP_ASM
extern "C" void* func_001C58D0(void* self, int a1)
{
    return (char*)self + (a1 * 0xc + 0x54);
}
#endif

