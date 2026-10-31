#include "common.h"

//100%
INCLUDE_ASM("fe/festatecredits", cFEStateCredits_onCreateScreen);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void* cUIScreen_playFrame(void* self, unsigned short frame, int flag);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern char D_0045DB80[];
extern char D_0045DB90[];
extern char D_0045DBA0[];
extern char D_0045DBB0[];

struct sVEntryK185A98 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void cFEStateCredits_onCreateScreen(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0045DB80), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    char* o = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DB90));
    if (o != 0)
        *(int*)(o + 0x90) |= 8;
    char* t = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DBA0));
    *(void**)((char*)self + 0x58) = t;
    if (t != 0) {
        sVEntryK185A98* vt = *(sVEntryK185A98**)(t + 8);
        vt[9].fn(t + vt[9].delta, 0);
    }
    t = (char*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DBB0));
    *(void**)((char*)self + 0x58) = t;
    if (t != 0) {
        sVEntryK185A98* vt = *(sVEntryK185A98**)(t + 8);
        vt[9].fn(t + vt[9].delta, 0);
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", cFEStateCredits_onGainFocus);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_003A1F18(void* self, int id);
extern "C" void func_00186518(void* self, void* a1);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0045DBC0[];
extern char D_0045DBD0[];
extern char D_0045DBE0[];
extern char D_0045DBF0[];
extern char D_0045DC00[];
extern char D_0045DC10[];
extern char D_0045DC20[];
extern char D_0045DC30[];
extern char D_0045DC40[];

class cUIObjK185BA0 {
public:
    int pad[2];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(int a);
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
    virtual int v20(float* pos);
    virtual void v21(float* pos);
};

extern "C" void cFEStateCredits_onGainFocus(void* self, void* a1)
{
    cUIObjK185BA0* t = (cUIObjK185BA0*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0045DBC0));
    *(cUIObjK185BA0**)((char*)self + 0x5C) = t;
    if (t != 0)
    {
        float pos[4];
        char buf[0x20];
        int i;
        t->v20(pos);
        pos[0] = 600.0f;
        (*(cUIObjK185BA0**)((char*)self + 0x5C))->v21(pos);
        (*(cUIObjK185BA0**)((char*)self + 0x5C))->v09(0);
        for (i = 0; i < 7; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DBE0));
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DBF0));
        for (i = 7; i < 0x2F; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
        for (i = 0x31; i < 0x4B; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DC00));
        for (i = 0x4B; i < 0x51; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DC10));
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DC20));
        for (i = 0x5A; i < 0x92; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DC30));
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(D_0045DC40));
        sprintf(buf, D_0045DBD0, 0x96);
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        sprintf(buf, D_0045DBD0, 0x97);
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        sprintf(buf, D_0045DBD0, 0x98);
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        sprintf(buf, D_0045DBD0, 0x99);
        func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        for (i = 0x9A; i < 0xA8; i++)
        {
            sprintf(buf, D_0045DBD0, i);
            func_003A1F18(*(void**)((char*)self + 0x5C), GetHashValue32(buf));
        }
    }
    func_00186518(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_00185F40);
#ifdef SKIP_ASM
extern "C" void func_00391E30(void* self, float x, float y, void* m);
extern "C" float func_003921F0(void* f_, const unsigned short* s, void* r_, int mono, float sx, float sy);
extern "C" void func_0039E6B8(void* self);
extern "C" char* func_003A12D0(void* self);
extern "C" unsigned short* func_003A2068(void* self, int idx);
extern void* D_004A289C;

struct sV3_185F40 {
    float x, y, z;
};

struct sV4_185F40 {
    float x, y, z, w;
};

struct sV2_185F40 {
    float x, y;
};

struct sRect_185F40 {
    float x0, y0, x1, y1;
};

class cUIObj185F40 {
public:
    int pad[2];
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
    virtual void v20(sV4_185F40* out);
};

struct sRS_185F40 {
    int f0;
    int f4;
    int pad : 5;
    int mode : 5;
};

static inline void DrawText_185F40(char* font, unsigned short* s, float x, float y, const sV2_185F40& sc)
{
    *(float*)(font + 0x38) = *(float*)(font + 0x30) * sc.x;
    *(float*)(font + 0x3C) = *(float*)(font + 0x34) * sc.y;
    func_00391E30(font, x, y, s);
    *(sV2_185F40*)(font + 0x38) = *(sV2_185F40*)(font + 0x30);
}

extern "C" void func_00185F40(char* self)
{
    char* o = *(char**)(self + 0x5C);
    if (o != 0)
    {
        sV3_185F40 pos = *(sV3_185F40*)(o + 0x44);
        sV3_185F40 size = *(sV3_185F40*)(o + 0x50);
        sV4_185F40 box;
        ((cUIObj185F40*)o)->v20(&box);
        char* font = func_003A12D0(*(void**)(self + 0x5C));
        if (font != 0)
        {
            float lineH = (float)*(int*)(font + 0x14) * *(float*)(font + 0x34);
            int any = 0;
            sV4_185F40 white;
            white.x = 1.0f;
            white.y = 1.0f;
            white.z = 1.0f;
            white.w = 1.0f;
            float h = size.y * lineH;
            float bh = box.y;
            sV4_185F40 save = *(sV4_185F40*)(*(char**)(self + 0x5C) + 0x1C);
            (*(sRS_185F40**)((char*)D_004A289C + 0xE84))->mode = 21;
            signed char rows = (int)h + 3;
            int scroll = *(int*)(self + 0x60);
            int first = scroll / rows;
            int rem = scroll % rows;
            signed char count = (int)(bh / (float)rows);
            if (rem < 0)
                rem = -scroll % rows;
            for (int i = 0; i < count; i++)
            {
                unsigned short* line = func_003A2068(*(void**)(self + 0x5C), i + first);
                float frows = (float)rows;
                if (line != 0)
                {
                    float frem = (float)rem;
                    while (*line == ' ')
                        line++;
                    sV3_185F40 p = pos;
                    if (*(int*)(self + 0x60) > 0)
                        p.y -= frem;
                    else
                        p.y += frem;
                    if (*line == '~' && *(void**)(self + 0x58) != 0)
                    {
                        sV4_185F40 b;
                        any = 1;
                        (*(cUIObj185F40**)(self + 0x58))->v20(&b);
                        p.x = (640.0f - b.x) * 0.5f;
                        *(sV3_185F40*)(*(char**)(self + 0x58) + 0x44) = p;
                        (*(cUIObj185F40**)(self + 0x58))->v09(1);
                    }
                    else
                    {
                        sV2_185F40 sz;
                        sz.x = size.x;
                        sz.y = size.y;
                        if (*line == '^')
                        {
                            *(sV4_185F40*)(font + 0x40) = white;
                            line++;
                        }
                        else
                        {
                            *(sV4_185F40*)(font + 0x40) = save;
                            sz.x -= 0.10000000149011612f;
                            sz.y -= 0.10000000149011612f;
                        }
                        sRect_185F40 r;
                        func_003921F0(font, line, &r, 0, sz.x, sz.y);
                        p.x = (640.0f - r.x1) * 0.5f;
                        DrawText_185F40(font, line, p.x, p.y, sz);
                    }
                }
                pos.y += frows;
            }
            if (!any)
            {
                if (*(void**)(self + 0x58) != 0)
                    (*(cUIObj185F40**)(self + 0x58))->v09(0);
            }
            int total = count * rows;
            int lim = *(unsigned short*)(*(char**)(self + 0x5C) + 0xC8) * rows + total;
            if (*(int*)(self + 0x60) < -total && *(int*)(self + 0x64) < 0)
                *(int*)(self + 0x60) = lim;
            if (lim < *(int*)(self + 0x60) && *(int*)(self + 0x64) > 0)
                *(int*)(self + 0x60) = -total;
        }
    }
    func_0039E6B8(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_001863B8);
#ifdef SKIP_ASM
extern "C" void func_0039E510(void* self);

extern "C" void func_001863B8(void* self)
{
    *(int*)((char*)self + 0x60) += *(int*)((char*)self + 0x64);
    func_0039E510(self);
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_001863E8);
#ifdef SKIP_ASM
struct sVEntry001863E8 {
    short delta;
    short index;
    int (*fn)(void*);
};

extern "C" int func_001863E8(void* self, void* pad)
{
    sVEntry001863E8* e = &(*(sVEntry001863E8**)((char*)pad + 8))[17];
    if (e->fn((char*)pad + e->delta)) {
        if (*(int*)((char*)self + 0x64) >= -7) {
            *(int*)((char*)self + 0x64) -= 1;
        }
        return 1;
    }
    e = &(*(sVEntry001863E8**)((char*)pad + 8))[18];
    if (e->fn((char*)pad + e->delta)) {
        if (*(int*)((char*)self + 0x64) < 8) {
            *(int*)((char*)self + 0x64) += 1;
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_00186478);
#ifdef SKIP_ASM
extern "C" int func_00186478(void* self, int a1, unsigned int a2)
{
    switch (a2) {
    case 6:
    case 8:
    case 9:
        return 0x100;
    }
    return 0x101;
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_001864B0);
#ifdef SKIP_ASM
struct sVEntry001864B0 {
    short delta;
    short index;
    void* (*fn)(void*, void*, int);
};
extern "C" void func_0039F400(void* list, void* item);

extern "C" void func_001864B0(void* self, void* item, int msg)
{
    if (item != 0 && msg == 6) {
        void* obj = **(void***)((char*)self + 0x10);
        sVEntry001864B0* vt = *(sVEntry001864B0**)((char*)obj + 4);
        void* r = vt[5].fn((char*)obj + vt[5].delta, self, 0x24);
        if (r != 0) {
            func_0039F400((char*)*(void**)((char*)self + 0x10) + 0x18, r);
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_00186518);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList* list);
int GetHashValue32(char* str);
extern char D_004A1398[];
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void cUIMenu_setSelectedByIndex(void* menu, unsigned char idx);
extern "C" signed char func_001A06F0(void* self, int a1);
extern "C" void func_0039E4C0(void* self, void* a1);
// NOTE: placeholder for the object at $gp+0x1D90 (no symbol in the target)
struct sFlowState_865A8 {
    signed char count;
    char* states;
};
extern sFlowState_865A8 D_004A4E80;

extern "C" void func_00186518(void* self, void* a1)
{
    void* screen = cList_first((cList*)((char*)self + 0x24));
    if (screen != 0) {
        void* menu = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004A1398));
        if (menu != 0) {
            cUIMenu_setSelectedByIndex(menu, func_001A06F0(&D_004A4E80, *(signed char*)((char*)self + 0xC)));
        }
    }
    func_0039E4C0(self, a1);
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_001865A8);
#ifdef SKIP_ASM
struct cList;
void* cList_first(cList* list);
int GetHashValue32(char* str);
extern char D_004A1398[];
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
extern "C" void func_001A0708(void* self, int a1, int a2);
// NOTE: placeholder for the object at $gp+0x1D90 (no symbol in the target)
extern sFlowState_865A8 D_004A4E80;

extern "C" void func_001865A8(void* self)
{
    void* screen = cList_first((cList*)((char*)self + 0x24));
    if (screen != 0) {
        void* obj = cUIScreen_getObjectByHashName(screen, GetHashValue32(D_004A1398));
        if (obj != 0) {
            func_001A0708(&D_004A4E80, *(signed char*)((char*)self + 0xC), *(signed char*)((char*)obj + 0x95));
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/festatecredits", func_00186610);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void *, int);
extern "C" void func_002006B8(void* self);
extern void* D_0046BD28[];

extern "C" void* func_00186610(void* self, int a1, int a2)
{
    func_0039E2A0(self, a1);
    *(int*)((char*)self + 0xC) = 0x13;
    *(void***)((char*)self + 0x8) = D_0046BD28;
    func_002006B8((char*)self + 0x48);
    return self;
}
#endif

