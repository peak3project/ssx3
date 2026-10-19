#include "common.h"

//100%
INCLUDE_ASM("visualfx/renderstateman", cRenderStateMan_SnowFlakeColourR);
#ifdef SKIP_ASM
struct sRSMVEntry {
    short delta;
    short index;
    float* (*fn)(void*);
};

struct sRSMObj {
    int field_0x0;
    sRSMVEntry* vt;
};

struct sRSMEntry {
    char pad0[0x4];
    sRSMObj** p04;
    sRSMObj** p08;
    char pad0C[0x1C - 0xC];
    sRSMObj** p1C;
    sRSMObj** p20;
    char pad24[0xF0 - 0x24];
};

extern sRSMEntry D_004FA370[];

extern "C" float cRenderStateMan_SnowFlakeColourR(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[55].fn((char*)o + vt[55].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", cRenderStateMan_SnowFlakeColourG);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float cRenderStateMan_SnowFlakeColourG(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[56].fn((char*)o + vt[56].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", cRenderStateMan_SnowFlakeColourB);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float cRenderStateMan_SnowFlakeColourB(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[57].fn((char*)o + vt[57].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EE8A0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EE8A0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[58].fn((char*)o + vt[58].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EE8E8);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EE8E8(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[59].fn((char*)o + vt[59].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EE930);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EE930(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[60].fn((char*)o + vt[60].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EE978);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EE978(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[61].fn((char*)o + vt[61].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EE9C0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EE9C0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[7].fn((char*)o + vt[7].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEA08);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEA08(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[8].fn((char*)o + vt[8].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEA50);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEA50(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[9].fn((char*)o + vt[9].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEA98);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEA98(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[10].fn((char*)o + vt[10].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEAE0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEAE0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[11].fn((char*)o + vt[11].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEB28);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEB28(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p04;
    sRSMVEntry* vt = o->vt;
    return *vt[12].fn((char*)o + vt[12].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEB70);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EEB70(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[20].fn((char*)o + vt[20].delta);
    }
    return 1.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEBD0);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EEBD0(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[21].fn((char*)o + vt[21].delta);
    }
    return 1.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEC30);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EEC30(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[22].fn((char*)o + vt[22].delta);
    }
    return 1.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEC90);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EEC90(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[23].fn((char*)o + vt[23].delta);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EECF0);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EECF0(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[24].fn((char*)o + vt[24].delta);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EED50);
#ifdef SKIP_ASM
extern int D_004A3B60;

extern "C" float func_002EED50(int i)
{
    if (D_004A3B60 == 0) {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = **(sRSMObj***)((char*)e + 0xC);
        sRSMVEntry* vt = o->vt;
        return *vt[25].fn((char*)o + vt[25].delta);
    }
    return 0.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEDB0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEDB0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[13].fn((char*)o + vt[13].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEDF8);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEDF8(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[14].fn((char*)o + vt[14].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEE40);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEE40(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[15].fn((char*)o + vt[15].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEE88);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEE88(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[16].fn((char*)o + vt[16].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEED0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEED0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[17].fn((char*)o + vt[17].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEF18);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEF18(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[18].fn((char*)o + vt[18].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEF60);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEF60(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p08;
    sRSMVEntry* vt = o->vt;
    return *vt[19].fn((char*)o + vt[19].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEFA8);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEFA8(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p1C;
    sRSMVEntry* vt = o->vt;
    return *vt[42].fn((char*)o + vt[42].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EEFF0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EEFF0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p1C;
    sRSMVEntry* vt = o->vt;
    return *vt[41].fn((char*)o + vt[41].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF038);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EF038(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = **(sRSMObj***)((char*)e + 0x18);
    sRSMVEntry* vt = o->vt;
    return *vt[36].fn((char*)o + vt[36].delta) * (1.0f - *(float*)((char*)e + 0x24));
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF0A0);
#ifdef SKIP_ASM
extern sRSMEntry D_004FA370[];

extern "C" float func_002EF0A0(int i)
{
    sRSMEntry* e = &D_004FA370[i];
    sRSMObj* o = *e->p20;
    sRSMVEntry* vt = o->vt;
    return *vt[47].fn((char*)o + vt[47].delta);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF0E8);
#ifdef SKIP_ASM
extern int D_004A3B64;
extern int D_004A55B0;

extern "C" void* func_002EF0E8(int i)
{
    if (D_004A3B64 != 0) {
        return &D_004A55B0;
    }
    {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = *e->p1C;
        sRSMVEntry* vt = o->vt;
        return vt[37].fn((char*)o + vt[37].delta);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF140);
#ifdef SKIP_ASM
extern int D_004A3B64;
extern int D_004A55B0;

extern "C" void* func_002EF140(int i)
{
    if (D_004A3B64 != 0) {
        return &D_004A55B0;
    }
    {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = *e->p1C;
        sRSMVEntry* vt = o->vt;
        return vt[38].fn((char*)o + vt[38].delta);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF198);
#ifdef SKIP_ASM
extern int D_004A3B64;
extern int D_004A55B0;

extern "C" void* func_002EF198(int i)
{
    if (D_004A3B64 != 0) {
        return &D_004A55B0;
    }
    {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = *e->p1C;
        sRSMVEntry* vt = o->vt;
        return vt[39].fn((char*)o + vt[39].delta);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF1F0);
#ifdef SKIP_ASM
extern int D_004A3B64;
extern int D_004A55B0;

extern "C" void* func_002EF1F0(int i)
{
    if (D_004A3B64 != 0) {
        return &D_004A55B0;
    }
    {
        sRSMEntry* e = &D_004FA370[i];
        sRSMObj* o = *e->p1C;
        sRSMVEntry* vt = o->vt;
        return vt[40].fn((char*)o + vt[40].delta);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF248);
#ifdef SKIP_ASM
class cRSMObjWF {
public:
    int field_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
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
    virtual void v64(void* frame);
};

extern "C" void func_002EF248(void* frame)
{
    int i;
    for (i = 0; i < 6; i++) {
        sRSMEntry* e = &D_004FA370[i];
        ((cRSMObjWF*)*e->p20)->v64(frame);
        ((cRSMObjWF*)*e->p20)->v64(frame);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", cRenderStateMan_readFromReplayFrame);
#ifdef SKIP_ASM
class cRSMObjRF {
public:
    int field_0x0;
    // vptr at 0x4; slot N at vtable offset N*8
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
    virtual void v65(void* frame);
};

extern "C" void cRenderStateMan_readFromReplayFrame(void* frame)
{
    int i;
    for (i = 0; i < 6; i++) {
        sRSMEntry* e = &D_004FA370[i];
        ((cRSMObjRF*)*e->p20)->v65(frame);
        ((cRSMObjRF*)*e->p20)->v65(frame);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF368);
#ifdef SKIP_ASM
extern void* D_004A3B5C;
extern int D_004A4444;

extern "C" void func_002EF368(void* p)
{
    D_004A3B5C = p;
    D_004A4444 = p != 0;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF378);
#ifdef SKIP_ASM
extern "C" char* strcpy(char* dst, const char* src);
extern int D_004A3B64;
extern int D_004A55B0;

extern "C" void func_002EF378(const char* name)
{
    if (name == 0) {
        D_004A3B64 = 0;
    } else {
        strcpy((char*)&D_004A55B0, name);
        D_004A3B64 = 1;
    }
}
#endif

#ifdef SKIP_ASM
// Classes here derive virtually from cRider. g++ 2.95 then emits, in their destructors, the vtable fix-ups
// for the virtual base (stack copies of the cRider-in-D vtables with the dtor's this-delta adjusted when
// not most-derived). Only the cRider layout that code depends on is modelled (see
// ai/control/handplantcontrol.cpp).
class cRiderVbA0_rsm {
public:
    virtual ~cRiderVbA0_rsm();
    virtual void a01(); virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05();
    virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09(); virtual void a10();
    virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
};
class cRiderVbA_rsm : public cRiderVbA0_rsm { public: char padA[0xC]; };
class cRiderVbB0_rsm { public: virtual void b01(); };
class cRiderVbB_rsm : public cRiderVbB0_rsm { public: char padB[0x14]; };
class cRiderVbC0_rsm {
public:
    virtual ~cRiderVbC0_rsm();
    virtual void c01(); virtual void c02(); virtual void c03(); virtual void c04(); virtual void c05();
    virtual void c06();
};
class cRiderVbC_rsm : public cRiderVbC0_rsm { public: char padC[0x10]; };
class cRiderVbBC_rsm : public cRiderVbB_rsm, public cRiderVbC_rsm { public: };
class cRiderVbPad_rsm { public: char pad[0x6C0]; } __attribute__((aligned(16)));
class cRiderVb_rsm : public cRiderVbPad_rsm, public cRiderVbA_rsm, public cRiderVbBC_rsm {
public:
    cRiderVb_rsm();
    virtual ~cRiderVb_rsm();
};
void operator_delete(int* p);
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF3B0);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, unsigned int flags, int d) __asm__("operator_new__FUi");
extern char D_00487B78[];
extern "C" void func_002EF6A0(void* self);

struct cRsmItem_2EF3B0 {
    char data[0x20];
    cRsmItem_2EF3B0() {}
};

class cRsm_2EF3B0 : virtual public cRiderVb_rsm {
public:
    cRsmItem_2EF3B0* items;     // 0x4
    char pad08[0x18];
    cRsm_2EF3B0();
    virtual ~cRsm_2EF3B0();
};

cRsm_2EF3B0::cRsm_2EF3B0()
{
    cRsmItem_2EF3B0** slot = &items;
    *slot = new (D_00487B78, 0, 0) cRsmItem_2EF3B0[25];
    func_002EF6A0(this);
}
// PORT: the compiler names this ctor __11cRsm_2EF3B0i; expose it under the address-derived name.
__asm__(".globl func_002EF3B0\n.type func_002EF3B0,@function\nfunc_002EF3B0 = __11cRsm_2EF3B0i\n.size func_002EF3B0,0x180\n");
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF530);
#ifdef SKIP_ASM
void cMemMan_free(void* p);

class cVbDtor002EF530 : virtual public cRiderVb_rsm {
public:
    void* m04;
    char pad08[0x18];
    virtual ~cVbDtor002EF530();
    static void operator delete(void* p) { operator_delete((int*)p); }
};

cVbDtor002EF530::~cVbDtor002EF530()
{
    if (m04 != 0) cMemMan_free(m04);
}
// PORT: the compiler names this dtor _$_15cVbDtor002EF530; expose it under the address-derived name.
__asm__(".globl func_002EF530\n.type func_002EF530,@function\nfunc_002EF530 = _$_15cVbDtor002EF530\n.size func_002EF530,0x170\n");
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF6A0);
#ifdef SKIP_ASM
extern "C" void func_002EF6A0(void* self)
{
    int mode = (*(int*)(*(char**)self + 0x870) >= 0) ? 0x19 : 0x12;
    *(int*)((char*)self + 0x10) = 0;
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(int*)((char*)self + 0x14) = mode;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF6D0);
#ifdef SKIP_ASM
int func_0011FE98(void*);
extern "C" int func_001298C8();

struct sRsVec4_EF6D0 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRsSeg_EF6D0 {
    sRsVec4_EF6D0 p0;
    sRsVec4_EF6D0 p1;
};

struct sTrail_EF6D0 {
    char* rider;                // 0x0
    sRsSeg_EF6D0* ring;         // 0x4
    int head;                   // 0x8
    int count;                  // 0xC
    float start;                // 0x10
    int len;                    // 0x14
};

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sRsVec4_EF6D0 Scale_EF6D0(const sRsVec4_EF6D0& v, float s)
{
    sRsVec4_EF6D0 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sRsVec4_EF6D0 Add_EF6D0(const sRsVec4_EF6D0& a, const sRsVec4_EF6D0& b)
{
    sRsVec4_EF6D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sRsVec4_EF6D0 Sub_EF6D0(const sRsVec4_EF6D0& a, const sRsVec4_EF6D0& b)
{
    sRsVec4_EF6D0 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (4-component vector length).
static inline float Length_EF6D0(const sRsVec4_EF6D0& v)
{
    float r;
    int t;
    __asm__(
        "lqc2      $vf3, %2\n"
        "vaddw.x   $vf6, $vf0, $vf0w\n"
        "vmul.xyzw $vf4, $vf3, $vf3\n"
        "vadday.x  ACC, $vf4, $vf4y\n"
        "vmaddaz.x ACC, $vf6, $vf4z\n"
        "vmaddw.x  $vf4, $vf6, $vf4w\n"
        "vsqrt     Q, $vf4x\n"
        "vwaitq\n"
        "cfc2.ni   %1, $vi22\n"
        "mtc1      %1, %0\n"
        : "=f"(r), "=&r"(t)
        : "m"(v));
    return r;
}

static inline int Approach_EF6D0(int n, int step)
{
    return n > step ? n - step : (n > -step - 1 ? 0 : n + step);
}

extern "C" void func_002EF6D0(sTrail_EF6D0* self)
{
    if (func_0011FE98(self->rider) == 1) {
        char* r = self->rider;
        sRsVec4_EF6D0 a = *(sRsVec4_EF6D0*)(*(char**)(*(char**)(r + 0x780) + 0x30) + (*(int*)(r + 0x89C) << 6) + 0x30);
        sRsVec4_EF6D0 b = *(sRsVec4_EF6D0*)(*(char**)(*(char**)(r + 0x780) + 0x30) + (*(int*)(r + 0x8A4) << 6) + 0x30);
        sRsVec4_EF6D0 c = *(sRsVec4_EF6D0*)(*(char**)(*(char**)(r + 0x780) + 0x34) + (*(int*)(r + 0x8A4) << 6));
        sRsVec4_EF6D0 d = Sub_EF6D0(b, Scale_EF6D0(a, 0.699999988079071f));
        self->ring[self->head].p0 = Add_EF6D0(d, Scale_EF6D0(c, 90.0f));
        self->ring[self->head].p1 = Sub_EF6D0(d, Scale_EF6D0(c, 90.0f));
        if ((func_001298C8() & 1) == 0) {
            int old = self->head;
            self->head = old + 1;
            self->head %= 25;
            if (self->count < self->len)
                self->count++;
            self->ring[self->head] = self->ring[old];
        }
    } else {
        int n = self->count;
        self->count = Approach_EF6D0(n, 2);
    }
    self->start -= Length_EF6D0(*(sRsVec4_EF6D0*)(self->rider + 0x1E0)) * 0.00016666666488163173f;
    if (self->start < 0.0f)
        self->start += 1.0f;
    if (self->start > 1.0f)
        self->start -= 1.0f;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EF950);
#ifdef SKIP_ASM
struct sRsVec4_EF950 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct sRsColor_EF950 {
    float x, y, z, w;
    sRsColor_EF950() {}
    sRsColor_EF950(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct sRsVertUV_EF950 {
    float x, y, z, w;
    sRsVertUV_EF950() {}
} __attribute__((aligned(16)));

struct sRsVert_EF950 {
    sRsVertUV_EF950 uv;     // 0x00
    int r, g, b, a;         // 0x10
    sRsVec4_EF950 pos;      // 0x20
};

struct sRsState_EF950 {
    int f0;                 // 0x0
    int flagsA;             // 0x4
    int flagsB;             // 0x8
    int fC;                 // 0xC
    short tex;              // 0x10
    short pad;
};

struct sRsVEnt_EF950 {
    short delta;
    short index;
    void (*fn)(void*, int, sRsVert_EF950*, int);
};

struct sRsCtx_EF950 {
    char pad0[0xE84];
    sRsState_EF950* top;        // 0xE84
    char pad1[0x1044 - 0xE88];
    int tex1044;                // 0x1044
    int pad1048;
    int tex104C;                // 0x104C
    char pad2[0x10D8 - 0x1050];
    sRsVEnt_EF950* vtable;      // 0x10D8
};

struct sRsSeg_EF950 {
    sRsVec4_EF950 p0;
    sRsVec4_EF950 p1;
};

struct sTrail_EF950 {
    char* rider;                // 0x0
    sRsSeg_EF950* ring;         // 0x4
    int head;                   // 0x8
    int count;                  // 0xC
    float start;                // 0x10
    int len;                    // 0x14
};

extern sRsCtx_EF950* D_004A289C;
extern sRsState_EF950 D_00501420[];
extern int D_004A4720;
extern float D_004A3B74;

// PORT: PS2-only VU0 inline asm (vector times scalar).
static inline sRsVec4_EF950 rsScale_EF950(const sRsVec4_EF950& v, float s)
{
    sRsVec4_EF950 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "lqc2      $vf4, %2\n"
        "qmtc2.ni  %1, $vf3\n"
        "vmulx.xyzw $vf5, $vf4, $vf3x\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector add).
static inline sRsVec4_EF950 rsAdd_EF950(const sRsVec4_EF950& a, const sRsVec4_EF950& b)
{
    sRsVec4_EF950 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vadd.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

// PORT: PS2-only VU0 inline asm (vector subtract).
static inline sRsVec4_EF950 rsSub_EF950(const sRsVec4_EF950& a, const sRsVec4_EF950& b)
{
    sRsVec4_EF950 r;
    __asm__(
        "lqc2      $vf3, %1\n"
        "lqc2      $vf4, %2\n"
        "vsub.xyzw $vf5, $vf3, $vf4\n"
        "sqc2      $vf5, %0\n"
        : "=m"(r)
        : "m"(a), "m"(b)
        : "memory");
    return r;
}

static inline int rsTex1044_EF950(sRsCtx_EF950* ctx)
{
    return ctx->tex1044;
}

static inline int rsTex104C_EF950(sRsCtx_EF950* ctx)
{
    return ctx->tex104C;
}

static inline void rsPush_EF950(sRsCtx_EF950* ctx)
{
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}

static inline void rsPop_EF950(sRsCtx_EF950* ctx)
{
    ctx->top--;
}

static inline void rsSetA_EF950(sRsCtx_EF950* ctx, int mask, int shift, int v)
{
    ctx->top->flagsA = (ctx->top->flagsA & ~mask) | ((v << shift) & mask);
}

static inline void rsSetB_EF950(sRsCtx_EF950* ctx, int mask, int shift, int v)
{
    ctx->top->flagsB = (ctx->top->flagsB & ~mask) | ((v << shift) & mask);
}

static inline sRsVec4_EF950 rsRow_EF950(char* base, int idx, int off)
{
    return *(sRsVec4_EF950*)(base + (idx << 6) + off);
}

static inline void rsVert_EF950(sRsVert_EF950* v, float u, float w, const sRsColor_EF950& c, const sRsVec4_EF950& p)
{
    v->r = (int)(c.y * 255.0f);
    v->g = (int)(c.z * 255.0f);
    v->b = (int)(c.w * 255.0f);
    v->a = (int)(c.x * 128.0f);
    v->uv.z = 1.0f;
    v->pos = p;
    v->uv.x = u;
    v->uv.y = w;
}

extern "C" void func_002EF950(sTrail_EF950* self)
{
    if (self->count < 2) {
        return;
    }
    rsPush_EF950(D_004A289C);
    *D_004A289C->top = D_00501420[0];
    int glow = 0;
    float alpha = 0.3f;
    float start = 0.0f;
    if (D_004A4720 != 0 || 0.0f < *(float*)(self->rider + 0x2EC)) {
        glow = 1;
        alpha = 1.0f;
        *(short*)((char*)D_004A289C->top + 0x10) = rsTex1044_EF950(D_004A289C);
        D_004A289C->top->f0 &= ~0xC;
        start = self->start;
    } else {
        sRsCtx_EF950* c = D_004A289C;
        c->top->f0 |= 0xC;
        *(short*)((char*)c->top + 0x10) = rsTex104C_EF950(c);
    }
    sRsCtx_EF950* ctx = D_004A289C;
    rsSetA_EF950(ctx, 0x400000, 22, 1);
    rsSetA_EF950(ctx, 0x1800000, 23, 0);
    rsSetA_EF950(ctx, 0x300000, 20, 0);
    rsSetA_EF950(ctx, 0xFF000, 12, 0x14);
    rsSetA_EF950(ctx, 0x3, 0, 0);
    rsSetB_EF950(ctx, 0x1FFFFC00, 10, 0);
    rsSetB_EF950(ctx, 0x3E0, 5, 8);
    rsSetA_EF950(ctx, 0x7C, 2, 7);
    sRsVert_EF950 v1[52];
    sRsVert_EF950 v2[52];
    char* rider = self->rider;
    float uvy = start;
    float invSq = 1.0f / (float)((self->len - 1) * (self->len - 1));
    sRsVec4_EF950 off = rsScale_EF950(rsRow_EF950(*(char**)(*(char**)(rider + 0x780) + 0x30), *(int*)(rider + 0x89C), 0x30), 0.7f);
    float dv = 1.0f / (float)self->count;
    float t = 0.0f;
    int nverts = 0;
    sRsColor_EF950 color;
    color.x = 1.0f;
    color.y = 1.0f;
    color.z = 1.0f;
    color.w = 1.0f;
    sRsVec4_EF950 A;
    sRsVec4_EF950 B;
    rider = self->rider;
    sRsVec4_EF950 col = rsRow_EF950(*(char**)(*(char**)(rider + 0x780) + 0x34), *(int*)(rider + 0x8A4), 0x20);
    float size = 15.0f;
    if (glow) {
        float k = D_004A3B74;
        color = sRsColor_EF950(1.0f, k, k, k);
        size = 37.5f;
    }
    sRsVec4_EF950 half = rsScale_EF950(col, size * 0.5f);
    int j = self->head;
    int k = 0;
    for (int i = 0; i < self->count; i++) {
        if (j < 0) {
            j = 24;
        }
        color.x = alpha * (1.0f - t * t * invSq);
        if (color.x < 0.0f) {
            color.x = 0.0f;
        }
        A = rsAdd_EF950(self->ring[j].p0, off);
        B = rsAdd_EF950(self->ring[j].p1, off);
        rsVert_EF950(&v1[k], 0.0f, uvy, color, rsSub_EF950(A, half));
        rsVert_EF950(&v2[k], 0.0f, uvy, color, rsSub_EF950(B, half));
        k++;
        rsVert_EF950(&v1[k], 1.0f, uvy, color, rsAdd_EF950(A, half));
        rsVert_EF950(&v2[k], 1.0f, uvy, color, rsAdd_EF950(B, half));
        k++;
        uvy += dv;
        nverts += 2;
        j--;
        t += 1.0f;
    }
    sRsCtx_EF950* o = D_004A289C;
    o->vtable[71].fn((char*)o + o->vtable[71].delta, nverts, v1, 0);
    o = D_004A289C;
    o->vtable[71].fn((char*)o + o->vtable[71].delta, nverts, v2, 0);
    rsPop_EF950(D_004A289C);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EFF90);
#ifdef SKIP_ASM
extern void* D_004A3B78;

extern "C" int func_002EFF90(void) {
    return (*(int*)&D_004A3B78);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002EFF98);
#ifdef SKIP_ASM
struct sRSEntry_002EFF98 {
    int f0;
    int f4;
    int f8;
    int pad[5];
};
struct sRSMan_002EFF98 {
    int f[17];
    void* vt;
};
extern char D_00487DA0[];
extern sRSEntry_002EFF98* D_004A5B80;
extern int D_004A45D4;
extern int D_004A443C;
extern void* D_004A3B78;

extern "C" void* func_002EFF98(sRSMan_002EFF98* self)
{
    self->vt = D_00487DA0;
    self->f[0] = 0;
    self->f[1] = 0;
    self->f[2] = 0;
    self->f[3] = 0;
    self->f[4] = 0;
    self->f[5] = 0;
    self->f[6] = 0;
    self->f[7] = 0;
    self->f[8] = 0;
    self->f[9] = 0;
    self->f[10] = 0;
    self->f[11] = 0;
    self->f[12] = 0;
    self->f[13] = 0;
    self->f[14] = 0;
    self->f[15] = 0;
    self->f[16] = 0;
    D_004A45D4 = 0x37;
    D_004A443C = 0x30;
    D_004A3B78 = self;
    sRSEntry_002EFF98* e = D_004A5B80;
    e[1].f4 = 0x2E;
    e[2].f4 = 0x31;
    e[4].f4 = 0x2F;
    e[3].f4 = 0x44;
    e[5].f4 = 0; e[5].f8 = 0;
    e[6].f4 = 0; e[6].f8 = 0;
    e[7].f4 = 0; e[7].f8 = 0;
    e[8].f4 = 0; e[8].f8 = 0;
    e[9].f4 = 0; e[9].f8 = 0;
    e[10].f4 = 0; e[10].f8 = 0;
    e[11].f4 = 0; e[11].f8 = 0;
    e[12].f4 = 0; e[12].f8 = 0;
    e[13].f4 = 0; e[13].f8 = 0;
    e[14].f4 = 0; e[14].f8 = 0;
    e[15].f4 = 0; e[15].f8 = 0;
    e[16].f4 = 0; e[16].f8 = 0;
    e[17].f4 = 0; e[17].f8 = 0;
    e[18].f4 = 0; e[18].f8 = 0;
    e[19].f4 = 0; e[19].f8 = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F00A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" float func_002EE3B8(int i);
extern "C" float func_002EE738(int i);
extern "C" float func_002EE9C0(int i);
extern "C" float func_002EEA08(int i);
extern "C" float func_002EEA50(int i);
extern "C" float func_002EEA98(int i);
extern "C" float func_002EEAE0(int i);
extern "C" float func_002EEB28(int i);
extern "C" float func_002EEB70(int i);
extern "C" float func_002EEBD0(int i);
extern "C" float func_002EEC30(int i);
extern "C" float func_002EEC90(int i);
extern "C" float func_002EECF0(int i);
extern "C" float func_002EED50(int i);
extern "C" float func_002EEDB0(int i);
extern "C" float func_002EEDF8(int i);
extern "C" float func_002EEE40(int i);
extern "C" float func_002EEE88(int i);
extern "C" float func_002EEED0(int i);
extern "C" float func_002EEF18(int i);
extern "C" float func_002EEF60(int i);
extern "C" float func_002EF038(int i);
extern "C" int func_002F7BE0(void* p);
extern void* D_004A28A8;
extern void* D_004A3B5C;
extern int D_004A4328;
extern int D_004A4334;
extern float D_004A4338;
extern float D_004A432C;
extern float D_004A4330;
extern int D_004A45DC;
extern float D_004A45E4;
extern float D_004A45E8;
extern float D_004A45EC;
extern float D_004A45F0;
extern float D_004A45F4;
extern float D_004A45F8;
extern float D_004A4614;
extern int D_004A460C;
extern int D_004A43CC;
extern float D_004A43D4;
extern float D_004A43D8;
extern float D_004A43DC;
extern float D_004A43E0;
extern float D_004A43E4;
extern float D_004A43F0;
extern float D_004A43F4;

struct sRsCol_F00A0 {
    float r, g, b, a;
    sRsCol_F00A0(const float& x, const float& y, const float& z, const float& w) : r(x), g(y), b(z), a(w) {}
};
extern sRsCol_F00A0 D_00504720;

struct sRsCtx_F00A0 {
    char pad0[0x8C];
    void* a8C[8];       // 0x8C
    float aAC[8];       // 0xAC
    float aCC[8];       // 0xCC
    float aEC[8];       // 0xEC
    float a10C[8];      // 0x10C
    float a12C[8];      // 0x12C
    float a14C[8];      // 0x14C
    float a16C[8];      // 0x16C
    float a18C[8];      // 0x18C
    float a1AC[8];      // 0x1AC
    float a1CC[8];      // 0x1CC
    float a1EC[8];      // 0x1EC
    float a20C[8];      // 0x20C
    float a22C[8];      // 0x22C
    float a24C[8];      // 0x24C
};
extern sRsCtx_F00A0* D_ctx_F00A0 __asm__("D_004A5B80");

extern "C" void func_002F00A0(void* self, int i)
{
    sRsCtx_F00A0* ctx = D_ctx_F00A0;
    if (D_004A4328 == 0) {
        sRsCol_F00A0* dst = &D_00504720;
        D_004A4338 = func_002EE9C0(i);
        D_004A4334 = 1;
        D_004A432C = func_002EEA08(i);
        D_004A4330 = func_002EEA50(i);
        float g = func_002EEA98(i);
        float b = func_002EEAE0(i);
        float a = func_002EEB28(i);
        *dst = sRsCol_F00A0(1.0f, g, b, a);
    }
    if (D_004A45DC == 0) {
        D_004A45E4 = func_002EEB70(i);
        D_004A45E8 = func_002EEBD0(i);
        D_004A45EC = func_002EEC30(i);
        D_004A45F0 = func_002EEC90(i);
        D_004A45F4 = func_002EECF0(i);
        D_004A45F8 = func_002EED50(i);
        D_004A4614 = func_002EE738(i);
        int on = 0;
        int* st = *(int**)(*(char**)((char*)D_004A28A8 + 0x84) + 0x28);
        if (*st == 1 || func_002F7BE0(st))
            on = 1;
        D_004A460C = on;
    }
    if (D_004A43CC == 0) {
        D_004A43D4 = func_002EEDB0(i);
        D_004A43D8 = func_002EEDF8(i);
        D_004A43DC = func_002EEE40(i);
        D_004A43E0 = func_002EEE88(i);
        D_004A43E4 = func_002EEED0(i);
        D_004A43F0 = func_002EEF18(i);
        D_004A43F4 = func_002EEF60(i);
    }
    ctx->a8C[i] = D_004A3B5C;
    ctx->aAC[i] = func_002EF038(i);
    ctx->aCC[i] = func_002EE3B8(i);
    ctx->aEC[i] = func_002EE9C0(i);
    ctx->a10C[i] = func_002EEA98(i);
    ctx->a12C[i] = func_002EEAE0(i);
    ctx->a14C[i] = func_002EEB28(i);
    ctx->a16C[i] = func_002EEA08(i);
    ctx->a18C[i] = func_002EEA50(i);
    ctx->a1AC[i] = func_002EEB70(i);
    ctx->a1CC[i] = func_002EEBD0(i);
    ctx->a1EC[i] = func_002EEC30(i);
    ctx->a20C[i] = func_002EEC90(i);
    ctx->a22C[i] = func_002EECF0(i);
    ctx->a24C[i] = func_002EED50(i);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0360);
#ifdef SKIP_ASM
extern void* D_004A3B80;

extern "C" int func_002F0360(void) {
    return (*(int*)&D_004A3B80);
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0368);
#ifdef SKIP_ASM
extern void* D_00487D78[];
extern void* D_004A3B80;

extern "C" void* func_002F0368(void* self)
{
    *(int*)self = 0;
    *(void***)((char*)self + 0x4) = D_00487D78;
    D_004A3B80 = self;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0388);
#ifdef SKIP_ASM
extern "C" void func_002F0388(void) {

}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0390);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002F03C8(void* self);
extern char D_00487B88[];

extern "C" void* func_002F0390(void)
{
    return func_002F03C8(cMemMan_alloc(8, D_00487B88, 0, 0));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/renderstateman", func_002F03C8);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002F0368(void* self);
extern "C" void func_002D6410(void* self);
extern char D_00487568[];
extern void* D_00487D50[];
extern void* D_00488648[];

extern "C" void* func_002F03C8(void* self)
{
    func_002F0368(self);
    *(void***)((char*)self + 0x4) = D_00487D50;
    void** p = (void**)cMemMan_alloc(4, D_00487568, 0, 0);
    *p = D_00488648;
    func_002D6410(p);
    *(void***)self = p;
    return self;
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0438);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern void* D_00487D50[];
extern void* D_00487D78[];

class func_002F0438_cVirt {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01(int);
};

extern "C" void func_002F0438(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00487D50;
    func_002F0438_cVirt* o = *(func_002F0438_cVirt**)self;
    if (o != 0) {
        o->v01(3);
    }
    *(void***)((char*)self + 0x4) = D_00487D78;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F04B0);
#ifdef SKIP_ASM
class func_002F04B0_cObj {
public:
    // vptr at 0x0; slot N at vtable offset N*8
    virtual void v01();
    virtual void v02();
    virtual void v03();
};

extern "C" void func_002F04B0(func_002F04B0_cObj** self)
{
    (*self)->v02();
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F04E0);
#ifdef SKIP_ASM
extern "C" void func_002F04E0(func_002F04B0_cObj** self)
{
    (*self)->v03();
}
#endif

//100%
INCLUDE_ASM("visualfx/renderstateman", func_002F0510);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cPSPVisualEffectsMan_cPSPVisualEffectsMan(void* self);
extern char D_00487BA0[];

extern "C" void* func_002F0510(void)
{
    return cPSPVisualEffectsMan_cPSPVisualEffectsMan(cMemMan_alloc(0x48, D_00487BA0, 0, 0));
}
#endif

