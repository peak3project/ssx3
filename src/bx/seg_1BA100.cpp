#include "common.h"

//100%
INCLUDE_ASM("bx/seg_1BA100", bxLogPrint);
#ifdef SKIP_ASM
extern "C" void bxLogPrint(const char *fmt, ...) {
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9138);
#ifdef SKIP_ASM
extern "C" int func_002B9138(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9140);
#ifdef SKIP_ASM
extern "C" int func_002B9140(void *arg0) {
    return *(volatile int *)((char*)arg0 + 0x1C);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9150);
#ifdef SKIP_ASM
extern "C" int func_002B9150(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20))) + ((*(int *)((char*)(arg0) + (0x1C))) * 0x18);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9168);
#ifdef SKIP_ASM
extern "C" int func_002B9168(void *p) {
    return *(int*)((char*)p + (*(int*)((char*)p + 0x1C) << 2) + 0x24);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9180);
#ifdef SKIP_ASM
extern "C" int func_002B9180(void *p) {
    return (*(int**)((char*)p + 0x34))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9198);
#ifdef SKIP_ASM
extern "C" int func_002B9198(void *p) {
    return (*(int**)((char*)p + 0x38))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B91B0);
#ifdef SKIP_ASM
extern "C" int func_002B91B0(void *p) {
    return (*(int**)((char*)p + 0x3C))[*(int*)((char*)p + 0x1C)];
}
#endif

INCLUDE_ASM("bx/seg_1BA100", func_002B91C8);

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9208);
#ifdef SKIP_ASM
extern "C" unsigned short func_002B9208(void *arg0) {
    return (*(unsigned short *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9228);
#ifdef SKIP_ASM
extern "C" short func_002B9228(void *arg0) {
    return (*(short *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (0xA)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9248);
#ifdef SKIP_ASM
extern "C" int func_002B9248(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x70))) + ((*(int *)((char*)(arg0) + (0x1C))) * 0x10);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9260);
#ifdef SKIP_ASM
extern "C" int func_002B9260(void *p) {
    return (*(int**)((char*)p + 0x60))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9278);
#ifdef SKIP_ASM
extern "C" int func_002B9278(void *p) {
    return (*(int**)((char*)p + 0x64))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9290);
#ifdef SKIP_ASM
extern "C" float func_002B9290(void *p) {
    return (*(float**)((char*)p + 0x68))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B92A8);
#ifdef SKIP_ASM
extern "C" float func_002B92A8(void *p) {
    return (*(float**)((char*)p + 0x6C))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B92C0);
#ifdef SKIP_ASM
extern "C" int func_002B92C0(void *p) {
    return (*(int**)((char*)p + 0x74))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B92D8);
#ifdef SKIP_ASM
extern "C" int func_002B92D8(void *p) {
    return (*(int**)((char*)p + 0x78))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B92F0);
#ifdef SKIP_ASM
extern "C" int func_002B92F0(void *p) {
    return (*(int**)((char*)p + 0x7C))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9308);
#ifdef SKIP_ASM
extern "C" int func_002B9308(void *p) {
    return (*(int**)((char*)p + 0x80))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9320);
#ifdef SKIP_ASM
extern "C" int func_002B9320(void *p) {
    return (*(int**)((char*)p + 0x84))[*(int*)((char*)p + 0x1C)];
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9338);
#ifdef SKIP_ASM
extern "C" void func_003BA020(int);

extern "C" void func_002B9338(void *arg0) {
    func_003BA020((*(int *)((char*)(arg0) + (0x20))) + ((*(int *)((char*)(arg0) + (0x1C))) * 0x18));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9368);
#ifdef SKIP_ASM
struct S9368 { int a[6]; };
extern "C" void func_002B9368(void *self) {
    *(S9368*)((char*)self + 4) = *(S9368*)((char*)(*(int*)((char*)self + 0x20)) + *(int*)((char*)self + 0x1C) * 0x18);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B93B8);
#ifdef SKIP_ASM
struct Rec_93B8 { signed char v; char pad[0x17]; };
struct Q_93B8 { int a, b, c, d; };
struct Obj_93B8 {
    int pad0;
    Rec_93B8 cur;
    volatile int idx;
    Rec_93B8* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_93B8* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);

extern "C" void func_002B93B8(Obj_93B8* p) {
    p->recs[p->idx] = p->cur;
    p->arr24[p->idx] = 0;
    p->p34[p->idx] = 0;
    p->vals[p->idx] = p->recs[p->idx].v;
    p->p3C[p->idx] = 0;
    func_00416210((char*)p + p->idx * 8 + 0x40, 0, 8);
    p->p60[p->idx] = 0;
    p->p64[p->idx] = 0;
    p->p68[p->idx] = 0;
    p->p6C[p->idx] = 0;
    p->q70[p->idx].b = 0;
    p->q70[p->idx].a = 100;
    p->q70[p->idx].c = 90;
    p->q70[p->idx].d = 50;
    p->p74[p->idx] = 0;
    p->p80[p->idx] = 0;
    p->p84[p->idx] = 0;
    p->p78[p->idx] = 127;
    p->p7C[p->idx] = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B95B0);
#ifdef SKIP_ASM
struct Rec_95B0 { signed char v; char pad[0x17]; };
struct Q_95B0 { int a, b, c, d; };
struct Obj_95B0 {
    int pad0;
    Rec_95B0 cur;
    volatile int idx;
    Rec_95B0* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_95B0* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);

extern "C" void func_002B95B0(Obj_95B0* p) {
    p->idx++;
    p->recs[p->idx] = p->cur;
    p->arr24[p->idx] = 0;
    p->p34[p->idx] = 0;
    p->vals[p->idx] = p->recs[p->idx].v;
    p->p3C[p->idx] = 0;
    func_00416210((char*)p + p->idx * 8 + 0x40, 0, 8);
    p->p60[p->idx] = 0;
    p->p64[p->idx] = 0;
    p->p68[p->idx] = 0;
    p->p6C[p->idx] = 0;
    p->q70[p->idx].b = 0;
    p->q70[p->idx].a = 100;
    p->q70[p->idx].c = 90;
    p->q70[p->idx].d = 50;
    p->p74[p->idx] = 0;
    p->p80[p->idx] = 0;
    p->p84[p->idx] = 0;
    p->p78[p->idx] = 127;
    p->p7C[p->idx] = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B97B8);
#ifdef SKIP_ASM
extern "C" void func_002B97B8(void *arg0) {
    *(volatile int *)((char*)arg0 + 0x1C) = *(volatile int *)((char*)arg0 + 0x1C) - 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B97D0);
#ifdef SKIP_ASM
extern "C" void func_002B97D0(void *arg0, signed char arg1) {
    (*(signed char *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (2))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B97F0);
#ifdef SKIP_ASM
extern "C" void func_002B97F0(void *arg0, signed char arg1) {
    (*(signed char *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (3))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9810);
#ifdef SKIP_ASM
struct Rec_9810 { signed char v; char pad[0x17]; };
struct Q_9810 { int a, b, c, d; };
struct Obj_9810 {
    int pad0;
    Rec_9810 cur;
    volatile int idx;
    Rec_9810* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_9810* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};

#define MIN_9810(a,b) ((a) < (b) ? (a) : (b))
#define MAX_9810(a,b) ((a) < (b) ? (b) : (a))
extern "C" void func_002B9810(Obj_9810 *p, int v) {
    p->vals[p->idx] = v;
    p->recs[p->idx].v = MAX_9810(MIN_9810(p->vals[p->idx], 127), 0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B98A8);
#ifdef SKIP_ASM
#define MIN_98A8(a, b) ((a) < (b) ? (a) : (b))
#define MAX_98A8(a, b) ((a) >= (b) ? (a) : (b))
struct Rec_98A8 { unsigned char v; char pad[0x17]; };
struct Obj_98A8 {
    char pad0[0x1C];
    volatile int idx;
    Rec_98A8* recs;
    char pad24[0x14];
    int* vals;
};

extern "C" void func_002B98A8(Obj_98A8* p, float f) {
    p->vals[p->idx] = (int)MAX_98A8(MIN_98A8(p->vals[p->idx] * f, 127.0f), 0.0f);
    p->recs[p->idx].v = MAX_98A8(MIN_98A8(p->vals[p->idx], 127), 0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B99E8);
#ifdef SKIP_ASM
#define MIN_99E8(a, b) ((a) < (b) ? (a) : (b))
#define MAX_99E8(a, b) ((a) >= (b) ? (a) : (b))
struct Rec_99E8 { unsigned char v; char pad[0x17]; };
struct Obj_99E8 {
    char pad0[0x1C];
    volatile int idx;
    Rec_99E8* recs;
    char pad24[0x14];
    int* vals;
};

extern "C" void func_002B99E8(Obj_99E8* p, int n) {
    p->vals[p->idx] = MAX_99E8(MIN_99E8(p->vals[p->idx] * n / 127, 127), 0);
    p->recs[p->idx].v = MAX_99E8(MIN_99E8(p->vals[p->idx], 127), 0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9B48);
#ifdef SKIP_ASM
extern "C" void func_002B9B48(void *arg0, signed char arg1) {
    (*(signed char *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (1))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9B68);
#ifdef SKIP_ASM
extern "C" void func_002B9B68(void *arg0, short arg1) {
    (*(short *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (0xC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9B88);
#ifdef SKIP_ASM
extern "C" void func_002B9B88(void *arg0, int arg1) {
    (*(int *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x10) + (*(int *)((char*)(arg0) + (0x70))))) + (4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9BA0);
#ifdef SKIP_ASM
struct E_9BA0 { int v[4]; };
extern "C" void func_002B9BA0(void *p, int v) {
    (*(E_9BA0**)((char*)p + 0x70))[*(int*)((char*)p + 0x1C)].v[0] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9BB8);
#ifdef SKIP_ASM
extern "C" void func_002B9BB8(void *arg0, int arg1) {
    (*(int *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x10) + (*(int *)((char*)(arg0) + (0x70))))) + (8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9BD0);
#ifdef SKIP_ASM
extern "C" void func_002B9BD0(void *arg0, int arg1) {
    (*(int *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x10) + (*(int *)((char*)(arg0) + (0x70))))) + (0xC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9BE8);
#ifdef SKIP_ASM
extern "C" void func_002B9BE8(void *arg0, short arg1) {
    (*(short *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9C08);
#ifdef SKIP_ASM
extern "C" void func_002B9C08(void *arg0, short arg1) {
    (*(short *)((char*)((((*(int *)((char*)(arg0) + (0x1C))) * 0x18) + (*(int *)((char*)(arg0) + (0x20))))) + (0xA))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9C28);
#ifdef SKIP_ASM
extern "C" void func_002B9C28(void *p, int v) {
    *(int*)((char*)p + (*(int*)((char*)p + 0x1C) << 2) + 0x24) = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9C40);
#ifdef SKIP_ASM
extern "C" void func_002B9C40(void *arg0) {
    int *base = *(int **)((char *)arg0 + 0x34);
    base[*(int *)((char *)arg0 + 0x1C)] = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9C60);
#ifdef SKIP_ASM
extern "C" void func_002B9C60(void *p, int v) {
    (*(int**)((char*)p + 0x64))[*(int*)((char*)p + 0x1C)] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9C78);
#ifdef SKIP_ASM
extern "C" void func_002B9C78(void *self, int v) {
    int t = (v <= 0xFFFF) ? v : 0xFFFF;
    *(short*)((char*)(*(int*)((char*)self + 0x1C) * 0x18 + *(int*)((char*)self + 0x20)) + 0x14) = (t <= -1) ? 0 : t;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9CB0);
#ifdef SKIP_ASM
extern "C" void func_002B9CB0(void *p, int v) {
    (*(int**)((char*)p + 0x60))[*(int*)((char*)p + 0x1C)] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9CC8);
#ifdef SKIP_ASM
extern "C" void func_002B9CC8(void *p, int v) {
    (*(int**)((char*)p + 0x3C))[*(int*)((char*)p + 0x1C)] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9CE0);
#ifdef SKIP_ASM
struct V8_9CE0 { int a, b; };
extern "C" void func_002B9CE0(char *arg0, V8_9CE0 arg1) {
    V8_9CE0 *d = (V8_9CE0 *)(arg0 + *(int *)(arg0 + 0x1C) * 8);
    d[8] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D10);
#ifdef SKIP_ASM
extern "C" void func_002B9D10(void *p, int v) {
    (*(int**)((char*)p + 0x74))[*(int*)((char*)p + 0x1C)] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D28);
#ifdef SKIP_ASM
extern "C" void func_002B9D28(void *p, int v) {
    (*(int**)((char*)p + 0x78))[*(int*)((char*)p + 0x1C)] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D40);
#ifdef SKIP_ASM
extern "C" void func_002B9D40(void *arg0, int arg1) {
    int *base = *(int **)((char *)arg0 + 0x7C);
    base[*(int *)((char *)arg0 + 0x1C)] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D58);
#ifdef SKIP_ASM
extern "C" void func_002B9D58(void *arg0, int arg1) {
    int *base = *(int **)((char *)arg0 + 0x80);
    base[*(int *)((char *)arg0 + 0x1C)] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D70);
#ifdef SKIP_ASM
extern "C" void func_002B9D70(void *arg0, int arg1) {
    int *base = *(int **)((char *)arg0 + 0x84);
    base[*(int *)((char *)arg0 + 0x1C)] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D88);
#ifdef SKIP_ASM
extern "C" void func_002B9D88(void *arg0) {
    (*(int *)((char*)(arg0) + (0x94))) = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9D98);
#ifdef SKIP_ASM
extern "C" void func_002B9D98(void *arg0) {
    (*(int *)((char*)(arg0) + (0x94))) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9DA0);
#ifdef SKIP_ASM
extern "C" int func_002B9DA0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x94)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9DA8);
#ifdef SKIP_ASM
// volatile keeps the load out of the jr delay slot, as in the target.
extern "C" int func_002B9DA8(void *arg0) {
    return (*(volatile int *)((char*)(arg0) + (0x88)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9DB8);
#ifdef SKIP_ASM
extern "C" float func_002B9DB8(void *arg0) {
    int temp_2;
    int temp_3;

    temp_2 = (*(int *)((char*)(arg0) + (0x88)));
    temp_3 = (*(int *)((char*)(arg0) + (0x8C)));
    (*(int *)((char*)(arg0) + (0x8C))) = temp_2;
    return (float) (temp_2 - temp_3) * 0.01f;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9DE0);
#ifdef SKIP_ASM
extern "C" int func_002B9DE0(void *arg0, int arg1) {
    return (*(int *)((char*)(arg0) + (0x8EC))) + (arg1 * 0xC0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9DF8);
#ifdef SKIP_ASM
extern "C" int func_002B9DF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8E8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E00);
#ifdef SKIP_ASM
extern "C" void func_002B9E00(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8E0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E08);
#ifdef SKIP_ASM
extern "C" void func_002B9E08(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x8E4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E10);
#ifdef SKIP_ASM
extern "C" int func_002B9E10(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8E0)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E18);
#ifdef SKIP_ASM
extern "C" int func_002B9E18(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8E4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E20);
#ifdef SKIP_ASM
extern "C" int func_002B9E20(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E28);
#ifdef SKIP_ASM
struct Q_9E28 { int a; int *data; int tail; int head; };
extern "C" int func_002B9E28(char *self) {
    int r;
    if (*(int *)(self + 4) != 0) {
        Q_9E28 *q = (Q_9E28 *)(self + 0x18C);
        if (*(int *)(self + 0x194) == *(int *)(self + 0x198)) r = -1;
        else r = q->data[q->head];
    } else r = -1;
    return r;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E70);
#ifdef SKIP_ASM
extern "C" void func_00289DF0(void*, int);
extern "C" void func_002B9E70(void *a) {
    func_00289DF0(a, 0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9E90);
#ifdef SKIP_ASM
extern "C" void func_00289DF0(void*, int);
extern "C" void func_002B9E90(void *a) {
    func_00289DF0(a, 1);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9EB0);
#ifdef SKIP_ASM
struct S9EB0 { int a; char pad[0x5C]; };
extern "C" int func_002B9EB0(void *arg0, int arg1) {
    S9EB0 *base = *(S9EB0 **)((char *)arg0 + 0xACC);
    return base[arg1].a;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9EC8);
#ifdef SKIP_ASM
struct S9EC8 { int a; char pad[0x5C]; };
extern "C" int func_002B9EC8(void *arg0, int arg1) {
    S9EC8 *base = *(S9EC8 **)((char *)arg0 + 0xACC);
    return base[arg1].a == 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9EE8);
#ifdef SKIP_ASM
struct S9EE8 { int a; char pad[0x5C]; };
extern "C" int func_002B9EE8(void *arg0, int arg1) {
    S9EE8 *base = *(S9EE8 **)((char *)arg0 + 0xACC);
    return base[arg1].a == 2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9F08);
#ifdef SKIP_ASM
extern "C" int func_002B9F88(void *, int);
extern "C" void func_003B58A0();
extern "C" void func_003B58D8();
extern "C" int func_003B65D0(int);

extern "C" int func_002B9F08(void *self, int idx) {
    int r = 0;
    func_003B58A0();
    bool ok = *(int *)((char*)(*(int *)((char*)self + 0xACC)) + idx * 0x60) != 1;
    if (!ok) {
        r = func_003B65D0(func_002B9F88(self, idx)) == 1;
    }
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9F88);
#ifdef SKIP_ASM
struct S9F88 { int a; int b; char pad[0x58]; };
extern "C" int func_002B9F88(void *arg0, int arg1) {
    S9F88 *base = *(S9F88 **)((char *)arg0 + 0xACC);
    bool ne = base[arg1].a != 1;
    if (!ne) {
        return base[arg1].b;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9FB8);
#ifdef SKIP_ASM
extern "C" void func_002B9FB8(void *arg0, int arg1) {
    int *base = *(int **)((char *)arg0 + 4);
    base[*(int *)(*(char **)arg0 + 0x1F4)] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9FD8);
#ifdef SKIP_ASM
extern "C" void func_002B9FD8(void *arg0, int arg1) {
    int *base = *(int **)((char *)arg0 + 8);
    base[*(int *)(*(char **)arg0 + 0x1F4)] = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002B9FF8);
#ifdef SKIP_ASM
struct Rec_9FF8 { signed char v; char pad[0x17]; };
struct Q_9FF8 { int a, b, c, d; };
struct Obj_9FF8 {
    int pad0;
    Rec_9FF8 cur;
    volatile int idx;
    Rec_9FF8* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_9FF8* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);


struct Outer_9FF8 { char pad[0x1D8]; Obj_9FF8 sub; };
extern "C" void func_002B9FF8(Outer_9FF8** arg) {
    Outer_9FF8* o = *arg;
    Obj_9FF8* p = &o->sub;
    o->sub.idx++;
    p->recs[o->sub.idx] = o->sub.cur;
    o->sub.arr24[o->sub.idx] = 0;
    p->p34[o->sub.idx] = 0;
    p->vals[o->sub.idx] = p->recs[o->sub.idx].v;
    p->p3C[o->sub.idx] = 0;
    func_00416210((char*)p + o->sub.idx * 8 + 0x40, 0, 8);
    p->p60[o->sub.idx] = 0;
    p->p64[o->sub.idx] = 0;
    p->p68[o->sub.idx] = 0;
    p->p6C[o->sub.idx] = 0;
    p->q70[o->sub.idx].b = 0;
    p->q70[o->sub.idx].a = 100;
    p->q70[o->sub.idx].c = 90;
    p->q70[o->sub.idx].d = 50;
    p->p74[o->sub.idx] = 0;
    p->p80[o->sub.idx] = 0;
    p->p84[o->sub.idx] = 0;
    p->p78[o->sub.idx] = 127;
    p->p7C[o->sub.idx] = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BA208);
#ifdef SKIP_ASM
struct Rec_A208 { signed char v; char pad[0x17]; };
struct Q_A208 { int a, b, c, d; };
struct Obj_A208 {
    int pad0;
    Rec_A208 cur;
    volatile int idx;
    Rec_A208* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_A208* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);


struct Outer_A208 { char pad[0x1D8]; Obj_A208 sub; };
struct Arg_A208 { Outer_A208* o; int* vals; };
extern "C" void func_002BA208(Arg_A208* arg, int v) {
    Outer_A208* o = arg->o;
    Obj_A208* p = &o->sub;
    o->sub.idx++;
    p->recs[o->sub.idx] = o->sub.cur;
    o->sub.arr24[o->sub.idx] = 0;
    p->p34[o->sub.idx] = 0;
    p->vals[o->sub.idx] = p->recs[o->sub.idx].v;
    p->p3C[o->sub.idx] = 0;
    func_00416210((char*)p + o->sub.idx * 8 + 0x40, 0, 8);
    p->p60[o->sub.idx] = 0;
    p->p64[o->sub.idx] = 0;
    p->p68[o->sub.idx] = 0;
    p->p6C[o->sub.idx] = 0;
    p->q70[o->sub.idx].b = 0;
    p->q70[o->sub.idx].a = 100;
    p->q70[o->sub.idx].c = 90;
    p->q70[o->sub.idx].d = 50;
    p->p74[o->sub.idx] = 0;
    p->p80[o->sub.idx] = 0;
    p->p84[o->sub.idx] = 0;
    p->p78[o->sub.idx] = 127;
    p->p7C[o->sub.idx] = 1;
    arg->vals[arg->o->sub.idx] = v;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BA448);
#ifdef SKIP_ASM
struct Rec_A448 { signed char v; char pad[0x17]; };
struct Q_A448 { int a, b, c, d; };
struct Obj_A448 {
    int pad0;
    Rec_A448 cur;
    volatile int idx;
    Rec_A448* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_A448* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);


struct Outer_A448 { char pad[0x1D8]; Obj_A448 sub; };
struct Arg_A448 { Outer_A448* o; int* vals; int* vals2; };
extern "C" void func_002BA448(Arg_A448* arg, int v, int v2) {
    Outer_A448* o = arg->o;
    Obj_A448* p = &o->sub;
    o->sub.idx++;
    p->recs[o->sub.idx] = o->sub.cur;
    o->sub.arr24[o->sub.idx] = 0;
    p->p34[o->sub.idx] = 0;
    p->vals[o->sub.idx] = p->recs[o->sub.idx].v;
    p->p3C[o->sub.idx] = 0;
    func_00416210((char*)p + o->sub.idx * 8 + 0x40, 0, 8);
    p->p60[o->sub.idx] = 0;
    p->p64[o->sub.idx] = 0;
    p->p68[o->sub.idx] = 0;
    p->p6C[o->sub.idx] = 0;
    p->q70[o->sub.idx].b = 0;
    p->q70[o->sub.idx].a = 100;
    p->q70[o->sub.idx].c = 90;
    p->q70[o->sub.idx].d = 50;
    p->p74[o->sub.idx] = 0;
    p->p80[o->sub.idx] = 0;
    p->p84[o->sub.idx] = 0;
    p->p78[o->sub.idx] = 127;
    p->p7C[o->sub.idx] = 1;
    arg->vals[arg->o->sub.idx] = v;
    arg->vals2[arg->o->sub.idx] = v2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BA6B0);
#ifdef SKIP_ASM
struct Rec_A6B0 { signed char v; char pad[0x17]; };
struct Q_A6B0 { int a, b, c, d; };
struct Obj_A6B0 {
    int pad0;
    Rec_A6B0 cur;
    volatile int idx;
    Rec_A6B0* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_A6B0* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);


extern "C" void func_002906B8(void*);
struct Outer_A6B0 { char pad[0x1D8]; Obj_A6B0 sub; };
struct Arg_A6B0 { Outer_A6B0* o; int* vals; int* vals2; };
extern "C" void func_002BA6B0(Arg_A6B0* arg, int v, int v2) {
    Outer_A6B0* o = arg->o;
    Obj_A6B0* p = &o->sub;
    o->sub.idx++;
    p->recs[o->sub.idx] = o->sub.cur;
    o->sub.arr24[o->sub.idx] = 0;
    p->p34[o->sub.idx] = 0;
    p->vals[o->sub.idx] = p->recs[o->sub.idx].v;
    p->p3C[o->sub.idx] = 0;
    func_00416210((char*)p + o->sub.idx * 8 + 0x40, 0, 8);
    p->p60[o->sub.idx] = 0;
    p->p64[o->sub.idx] = 0;
    p->p68[o->sub.idx] = 0;
    p->p6C[o->sub.idx] = 0;
    p->q70[o->sub.idx].b = 0;
    p->q70[o->sub.idx].a = 100;
    p->q70[o->sub.idx].c = 90;
    p->q70[o->sub.idx].d = 50;
    p->p74[o->sub.idx] = 0;
    p->p80[o->sub.idx] = 0;
    p->p84[o->sub.idx] = 0;
    p->p78[o->sub.idx] = 127;
    p->p7C[o->sub.idx] = 1;
    arg->vals[arg->o->sub.idx] = v;
    arg->vals2[arg->o->sub.idx] = v2;
    func_002906B8(arg);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BA920);
#ifdef SKIP_ASM
struct Rec_A920 { signed char v; char pad[0x17]; };
struct Q_A920 { int a, b, c, d; };
struct Obj_A920 {
    int pad0;
    Rec_A920 cur;
    volatile int idx;
    Rec_A920* recs;
    int arr24[4];
    int* p34;
    int* vals;
    int* p3C;
    int arr40[4][2];
    int* p60;
    int* p64;
    int* p68;
    int* p6C;
    Q_A920* q70;
    int* p74;
    int* p78;
    int* p7C;
    int* p80;
    int* p84;
};
extern "C" void* func_00416210(void*, int, unsigned int);


struct Outer_A920 { char pad[0x1D8]; Obj_A920 sub; };
struct Arg_A920 { Outer_A920* o; int* vals; int* vals2; };
#define MIN_A920(a,b) ((a) < (b) ? (a) : (b))
#define MAX_A920(a,b) ((a) < (b) ? (b) : (a))
extern "C" void func_002906B8(void*);
extern "C" void func_002BA920(Arg_A920* arg, int v, int v2, int v3) {
    Outer_A920* o = arg->o;
    Obj_A920* p = &o->sub;
    o->sub.idx++;
    p->recs[o->sub.idx] = o->sub.cur;
    o->sub.arr24[o->sub.idx] = 0;
    p->p34[o->sub.idx] = 0;
    p->vals[o->sub.idx] = p->recs[o->sub.idx].v;
    p->p3C[o->sub.idx] = 0;
    func_00416210((char*)p + o->sub.idx * 8 + 0x40, 0, 8);
    p->p60[o->sub.idx] = 0;
    p->p64[o->sub.idx] = 0;
    p->p68[o->sub.idx] = 0;
    p->p6C[o->sub.idx] = 0;
    p->q70[o->sub.idx].b = 0;
    p->q70[o->sub.idx].a = 100;
    p->q70[o->sub.idx].c = 90;
    p->q70[o->sub.idx].d = 50;
    p->p74[o->sub.idx] = 0;
    p->p80[o->sub.idx] = 0;
    p->p84[o->sub.idx] = 0;
    p->p78[o->sub.idx] = 127;
    p->p7C[o->sub.idx] = 1;
    arg->vals[arg->o->sub.idx] = v;
    arg->vals2[arg->o->sub.idx] = v2;
    {
        Outer_A920* o2 = arg->o;
        Obj_A920* p2 = &o2->sub;
        p2->vals[o2->sub.idx] = v3;
        p2->recs[o2->sub.idx].v = MAX_A920(MIN_A920(p2->vals[p2->idx], 127), 0);
    }
    func_002906B8(arg);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC30);
#ifdef SKIP_ASM
extern "C" int func_002BAC30(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x408)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC38);
#ifdef SKIP_ASM
extern "C" int func_002B2488(int);

extern "C" int func_002BAC38(void *arg0) {
    int temp_4;
    int var_2;

    temp_4 = (*(int *)((char*)(arg0) + (0x408)));
    var_2 = -1;
    if (temp_4 != 0) {
        var_2 = func_002B2488(temp_4);
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC60);
#ifdef SKIP_ASM
extern "C" int func_002BAC60(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3E4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC68);
#ifdef SKIP_ASM
extern "C" int func_002BAC68(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3E8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC70);
#ifdef SKIP_ASM
extern "C" int func_002BAC70(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3EC)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC78);
#ifdef SKIP_ASM
struct S78 { char x[0xB]; };
extern "C" void *func_002BAC78(void *arg0) {
    return (S78 *)((char *)arg0 + 0x124) + *(int *)((char *)arg0 + 0x3F0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC90);
#ifdef SKIP_ASM
extern "C" int func_002BAC90(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3F0)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAC98);
#ifdef SKIP_ASM
extern "C" void func_002B2850(int, void *);

extern "C" void func_002BAC98(void *arg0) {
    func_002B2850((*(int *)((char*)(arg0) + (0x408))), arg0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACB8);
#ifdef SKIP_ASM
extern "C" int func_002BACB8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x418)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACC0);
#ifdef SKIP_ASM
extern "C" void func_002BACC0(void *arg0) {
    (*(int *)((char*)(arg0) + (0x418))) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACC8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" void func_002BACC8(void *arg0) {
    (*(long *)((char*)(arg0) + (0x400))) = (long) (*(long *)((char*)(arg0) + (0x3F8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACD8);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_002BACD8(void *arg0) {
    return (*(long *)((char*)(arg0) + (0x400)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACE0);
#ifdef SKIP_ASM
extern "C" void func_002BACE0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x3F0))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACE8);
#ifdef SKIP_ASM
extern "C" int func_002BACE8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x41C)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACF0);
#ifdef SKIP_ASM
extern "C" int func_002BACF0(void) {
    return -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BACF8);
#ifdef SKIP_ASM
extern "C" int func_002BACF8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD00);
#ifdef SKIP_ASM
extern "C" char* func_002BAD00(char *p, int i) {
    int off = i * 0x14 + 0x158;
    return p + off;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD18);
#ifdef SKIP_ASM
extern "C" char* func_002BAD18(char *p, int i) {
    int off = i * 0x54 + 0x1C;
    return p + off;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD30);
#ifdef SKIP_ASM
extern "C" void func_002BAD30(void *p) {
    *(int*)((char*)p + 0x5790) = 0;
    *(int*)((char*)p + 0x578C) = 1;
    *(int*)((char*)p + 0x6254) = 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD48);
#ifdef SKIP_ASM
extern "C" int func_002BAD48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x578C)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD50);
#ifdef SKIP_ASM
extern "C" int func_002BAD50(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5790)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD58);
#ifdef SKIP_ASM
extern "C" void func_002BAD58(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x598C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD60);
#ifdef SKIP_ASM
extern "C" int func_002BAD60(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x5FB0)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD68);
#ifdef SKIP_ASM
extern "C" int func_002BAD68(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x608C)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD70);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
extern "C" long func_002BAD70(void *arg0) {
    return (*(long *)((char*)(arg0) + (0x6098)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD78);
#ifdef SKIP_ASM
extern "C" int func_002BAD78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6234)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD80);
#ifdef SKIP_ASM
extern "C" char* func_002BAD80(char *p, int i) {
    int off = i * 0x14 + 0x60A4;
    return p + off;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAD98);
#ifdef SKIP_ASM
extern "C" int func_002BAD98(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6238)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADA0);
#ifdef SKIP_ASM
extern "C" int func_002BADA0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6280)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADA8);
#ifdef SKIP_ASM
extern "C" int func_002BADA8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x62B0)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADB0);
#ifdef SKIP_ASM
extern "C" int func_002BADB0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x62B8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADB8);
#ifdef SKIP_ASM
extern "C" int func_002BADB8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x62B4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADC0);
#ifdef SKIP_ASM
extern "C" int func_002BADC0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6470)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADC8);
#ifdef SKIP_ASM
extern "C" int func_002BADC8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x6474)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BADD0);
#ifdef SKIP_ASM
struct Item_ADD0 { Item_ADD0* next; int pad; int type; };
struct List_ADD0 { int count; Item_ADD0* items[1]; };
struct Node_ADD0 { Node_ADD0* child[8]; int pad[2]; Item_ADD0* items; };

extern "C" void func_002BADD0(Node_ADD0* node, List_ADD0** out) {
    Item_ADD0* it;
    for (it = node->items; it != 0; it = it->next) {
        if (it->type == 5) {
            List_ADD0* l = *out;
            l->items[l->count++] = it;
        }
    }
    if (node->child[0]) func_002BADD0(node->child[0], out);
    if (node->child[1]) func_002BADD0(node->child[1], out);
    if (node->child[2]) func_002BADD0(node->child[2], out);
    if (node->child[3]) func_002BADD0(node->child[3], out);
    if (node->child[4]) func_002BADD0(node->child[4], out);
    if (node->child[5]) func_002BADD0(node->child[5], out);
    if (node->child[6]) func_002BADD0(node->child[6], out);
    if (node->child[7]) func_002BADD0(node->child[7], out);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAEE8);
#ifdef SKIP_ASM
extern "C" void func_002B8818(int, int);

extern "C" void func_002BAEE8(void) {
    func_002B8818(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAF08);
#ifdef SKIP_ASM
void func_002C17C0(void *);
struct E_AF08 { int a; int off; };
extern "C" void func_002BAF08(void *self) {
    char *base = (char*)self;
    *(char**)base = base + *(int*)base;
    func_002C17C0(*(char**)base);
    *(char**)(base + 8) = base + *(int*)(base + 8);
    E_AF08 *e = *(E_AF08**)(base + 8);
    int i;
    for (i = 0; i < *(int*)(base + 4); i++, e++) {
        int off = e->off;
        if (off != -1) {
            e->off = (int)(base + off);
        } else {
            e->off = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAF90);
#ifdef SKIP_ASM
extern "C" void *func_002C1CD8(int);

extern "C" int func_002BAF90(int *arg0) {
    return (*(int *)((char*)(func_002C1CD8(*arg0)) + (4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BAFB0);
#ifdef SKIP_ASM
// Placement new for constructing the key table in place.
inline void* operator new(unsigned int, void* p) { return p; }

// 8-byte key: a byte id at offset 0, overlaid by the packed word id | (index << 8).
struct sKey_AFB0 {
    union {
        unsigned char id;
        int packed;
    };
    int pad;

    sKey_AFB0(int n)
    {
        id = n;
        packed = (packed & 0xFF) | (n << 8);
    }
};

// Two zeroed words placed before the key table.
extern int D_004A52E0;
extern int D_004A52E4;
extern sKey_AFB0 D_004A52E8;
extern sKey_AFB0 D_004A52F0;
extern sKey_AFB0 D_004A52F8;
extern sKey_AFB0 D_004A5300;
extern sKey_AFB0 D_004A5308;
extern sKey_AFB0 D_004A5310;
extern sKey_AFB0 D_004A5318;
extern sKey_AFB0 D_004A5320;
extern sKey_AFB0 D_004A5328;
extern sKey_AFB0 D_004A5330;
extern sKey_AFB0 D_004A5338;
extern sKey_AFB0 D_004A5340;
extern sKey_AFB0 D_004A5348;
extern sKey_AFB0 D_004A5350;

// Static initializer (initialize, priority) for the key table.
extern "C" void func_002BAFB0(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0) {
        D_004A52E4 = 0;
        D_004A52E0 = 0;
        new (&D_004A52E8) sKey_AFB0(0);
        new (&D_004A52F0) sKey_AFB0(1);
        new (&D_004A52F8) sKey_AFB0(2);
        new (&D_004A5300) sKey_AFB0(3);
        new (&D_004A5308) sKey_AFB0(4);
        new (&D_004A5310) sKey_AFB0(5);
        new (&D_004A5318) sKey_AFB0(6);
        new (&D_004A5320) sKey_AFB0(7);
        new (&D_004A5328) sKey_AFB0(8);
        new (&D_004A5330) sKey_AFB0(9);
        new (&D_004A5338) sKey_AFB0(10);
        new (&D_004A5340) sKey_AFB0(11);
        new (&D_004A5348) sKey_AFB0(12);
        new (&D_004A5350) sKey_AFB0(13);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/seg_1BA100", func_002BB0E0);
#ifdef SKIP_ASM
extern "C" void func_002BAFB0(int, int);

extern "C" void func_002BB0E0(void) {
    func_002BAFB0(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB100);
#ifdef SKIP_ASM
extern "C" int func_002BB100(void *arg0, void *arg1) {
    int var_6;

    var_6 = 0;
    if (((*(int *)((char*)(arg0) + (0))) != (*(int *)((char*)(arg1) + (0)))) || ((*(int *)((char*)(arg0) + (4))) != (*(int *)((char*)(arg1) + (4))))) {
        var_6 = 1;
    }
    return var_6;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB130);
#ifdef SKIP_ASM
extern "C" void *func_002BB130(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB140);
#ifdef SKIP_ASM
void cMemMan_free(void *);
void operator_delete(int *);
extern "C" void func_002BB390(void *, int);
struct S12_B140 { int a, b, c; };
extern "C" void func_002BB140(void *self, int flags) {
    S12_B140 *arr = *(S12_B140**)((char*)self + 4);
    if (arr != 0) {
        S12_B140 *p = arr + *(int*)((char*)arr - 0x10);
        if (arr != p) {
            do {
                p--;
                func_002BB390(p, 0);
            } while (*(S12_B140**)((char*)self + 4) != p);
        }
        cMemMan_free((char*)*(S12_B140**)((char*)self + 4) - 0x10);
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB1D0);
#ifdef SKIP_ASM
extern "C" void *func_002BB370(void *arg0);
int operator_new_B1D0(unsigned int, void*, int, int) __asm__("operator_new__FUi");
extern char D_00483C68[];
struct sArr_B1D0 { int n; S12_B140 *arr; };

// Reallocates the 12-byte element array (delete[] then new[] with a count cookie).
extern "C" void func_002BB1D0(sArr_B1D0 *self, int n) {
    if (self->arr != 0) {
        S12_B140 *p = self->arr + *(int*)((char*)self->arr - 0x10);
        if (self->arr != p) {
            do {
                p--;
                func_002BB390(p, 0);
            } while (self->arr != p);
        }
        cMemMan_free((char*)self->arr - 0x10);
    }
    self->n = n;
    S12_B140 **dst = &self->arr;
    int *blk = (int*)operator_new_B1D0(n * 12 + 0x10, D_00483C68, 0x20000000, 0);
    blk[0] = n;
    S12_B140 *a = (S12_B140*)(blk + 4);
    S12_B140 *q = a;
    int i;
    for (i = n - 1; i != -1; i--) {
        func_002BB370(q);
        q++;
    }
    *dst = a;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB2B8);
#ifdef SKIP_ASM
extern "C" void func_002BB3F0(void *);
extern "C" void func_002BB2B8(void *self) {
    unsigned i;
    for (i = 0; i < *(unsigned*)self; i++) {
        func_002BB3F0((char*)(*(void**)((char*)self + 4)) + i * 12);
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB318);
#ifdef SKIP_ASM
extern "C" void func_002BB4D8(int, int);

extern "C" void func_002BB318(void *arg0, int arg1, int arg2) {
    func_002BB4D8((*(int *)((char*)(arg0) + (4))) + (arg1 * 0xC), arg2);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB348);
#ifdef SKIP_ASM
extern "C" void func_002BB570(void*, int, int);
extern "C" void func_002BB348(void *arg0, int arg1, int arg2) {
    func_002BB570((char*)*(void **)((char *)arg0 + 4) + arg1 * 12, arg1, arg2);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB370);
#ifdef SKIP_ASM
extern "C" void *func_002BB370(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (4))) = -1;
    (*(short *)((char*)(arg0) + (0))) = 0;
    (*(short *)((char*)(arg0) + (2))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB390);
#ifdef SKIP_ASM
void cMemMan_free(void*);
void operator_delete(int*);
extern "C" void func_002BB390(void *self, int flags) {
    void *p = *(void**)((char*)self + 8);
    if (p != 0) {
        if (*(short*)((char*)self + 2) == 0) {
            cMemMan_free(p);
        }
    }
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB3F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void ASYNCFILE_release_B3F0(int, int *, int *) __asm__("ASYNCFILE_release");
extern "C" void func_002523A8_B3F0(int) __asm__("func_002523A8");
extern "C" void func_003B47F8_B3F0(int, int) __asm__("func_003B47F8");
extern "C" int func_003B4818_B3F0(int) __asm__("func_003B4818");
extern "C" int func_003DF980_B3F0(int) __asm__("func_003DF980");
extern "C" void func_003E6574_B3F0(int, int, int) __asm__("func_003E6574");
int operator_new_B3F0(unsigned int, void*, int, int) __asm__("operator_new__FUi");
extern char D_004A3868[];
extern "C" void func_002BB3F0(void *self_) {
    char *self = (char*)self_;
    short st = *(short*)self;
    if (st == 1 && func_003DF980_B3F0(*(int*)(self + 4)) == st) {
        int sp0 = 0;
        int sp4 = 0;
        ASYNCFILE_release_B3F0(*(int*)(self + 4), &sp0, &sp4);
        if (sp0 != 0) {
            if (sp4 > 0) {
                int t = func_003B4818_B3F0(sp0);
                if (t > 0) {
                    int r = operator_new_B3F0(t, D_004A3868, 0x20000000, 0);
                    *(int*)(self + 8) = r;
                    func_003B47F8_B3F0(sp0, r);
                } else {
                    int r = operator_new_B3F0(sp4, D_004A3868, 0x20000000, 0);
                    *(int*)(self + 8) = r;
                    func_003E6574_B3F0(r, sp0, sp4);
                }
                func_002523A8_B3F0(sp0);
            }
        }
        *(short*)self = 2;
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB4D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct sBXStr_B4D8 { char *p; int pad[3]; sBXStr_B4D8() {} };
extern "C" void func_003186D0_B4D8(sBXStr_B4D8*, const char*, int) __asm__("func_003186D0");
extern "C" void func_00318630_B4D8(sBXStr_B4D8*, sBXStr_B4D8*, const char*) __asm__("func_00318630");
extern "C" int func_003DF690_B4D8(const char*, int) __asm__("func_003DF690");
extern "C" void cBXString_dt_B4D8(sBXStr_B4D8*, int) __asm__("cBXString__cBXString");
extern char D_004A3870[];
extern char D_004A3878[];
extern "C" void func_002BB4D8_B4D8(void *self, int arg) __asm__("func_002BB4D8");
extern "C" void func_002BB4D8_B4D8(void *self, int arg) {
    sBXStr_B4D8 a;
    sBXStr_B4D8 b;
    *(short*)((char*)self + 2) = 0;
    func_003186D0_B4D8(&b, D_004A3870, arg);
    func_00318630_B4D8(&a, &b, D_004A3878);
    *(int*)((char*)self + 4) = func_003DF690_B4D8(a.p, 0);
    cBXString_dt_B4D8(&a, 2);
    cBXString_dt_B4D8(&b, 2);
    int n = *(int*)((char*)self + 4);
    *(short*)((char*)self + 0) = n <= 0 ? 2 : 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB570);
#ifdef SKIP_ASM
extern "C" void func_002BB5F0(void *);

extern "C" void func_002BB570(void *arg0, int arg1, int arg2) {
    (*(short *)((char*)(arg0) + (2))) = 1;
    (*(short *)((char*)(arg0) + (0))) = 2;
    (*(int *)((char*)(arg0) + (8))) = arg2;
    func_002BB5F0(arg0);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB5A8);
#ifdef SKIP_ASM
extern "C" void cMemMan_free__FPv(int);

extern "C" void func_002BB5A8(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (8)));
    if (temp_4 != 0) {
        if ((*(short *)((char*)(arg0) + (2))) == 0) {
            cMemMan_free__FPv(temp_4);
        }
        (*(int *)((char*)(arg0) + (8))) = 0;
    }
    (*(short *)((char*)(arg0) + (0))) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB5F0);
#ifdef SKIP_ASM
extern "C" void func_002BAF08_B5F0(int p) __asm__("func_002BAF08");

struct sReloc_B5F0 {
    int magic;          // 0x0 (0x10 once relocated)
    int count;          // 0x4
    int offs[1];        // 0x8
};

struct sRes_B5F0 {
    short state;        // 0x0
    short keep;         // 0x2
    int pad4;
    sReloc_B5F0* data;  // 0x8
};

// Relocates the loaded block's offset table (dropping it if it has the wrong magic) and marks it ready.
extern "C" void func_002BB5F0(void* vself)
{
    sRes_B5F0* self = (sRes_B5F0*)vself;
    if (self->data == 0) {
        self->state = 3;
        return;
    }
    {
        if (self->data->magic != 0x10) {
            if (self->keep == 0) {
                cMemMan_free(self->data);
            }
            self->data = 0;
        }
        if (self->data != 0) {
            int* p = self->data->offs;
            for (int i = 0; i < self->data->count; i++, p++) {
                if (*p == -1) {
                    *p = 0;
                } else {
                    *p = (int)self->data + *p;
                    func_002BAF08_B5F0(*p);
                }
            }
        }
    }
    self->state = 3;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB6B8);
#ifdef SKIP_ASM
extern "C" void func_002BB6E0(int, void *);
extern void *D_004A28A8;

extern "C" void func_002BB6B8(void) {
    void *temp_5;

    temp_5 = (*(void **)((char*)((*(void **)((char*)(D_004A28A8) + (0x84)))) + (0x10)));
    func_002BB6E0((*(int *)((char*)(temp_5) + (8))), temp_5);
}
#endif

INCLUDE_ASM("bx/seg_1BA100", func_002BB6E0);

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BB928);
#ifdef SKIP_ASM
// PORT: PS2-only vector layout (16-byte aligned quads, copied with lq/sq).
struct sQtVec4_B928 {
    float x, y, z, w;
    sQtVec4_B928() {}
    sQtVec4_B928(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct sQtVtx_B928 {
    char pad_0x0[0x20];
    sQtVec4_B928 pos;   // 0x20
};

struct sQtNode_B928 {
    unsigned short child[4];
};

struct sQtTree_B928 {
    char pad_0x0[0x20];
    sQtNode_B928* nodes;    // 0x20
};

struct sQtVEntry_B928 {
    short delta;
    short index;
    void (*fn)(void*, int, sQtVtx_B928*, int);
};

struct sQtCtx_B928 {
    char pad_0x0[0x10D8];
    sQtVEntry_B928* vtable;      // 0x10D8
};

class cQtCam_B928 {
public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual sQtVec4_B928* v05();
};

extern sQtCtx_B928* D_004A5B80_B928 __asm__("D_004A5B80");

// PORT: PS2-only VU0 inline asm (a + b).
static inline sQtVec4_B928 qtAdd_B928(const sQtVec4_B928& a, const sQtVec4_B928& b)
{
    sQtVec4_B928 r;
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

// PORT: PS2-only VU0 inline asm (v / s).
static inline sQtVec4_B928 qtDiv_B928(const sQtVec4_B928& v, float s)
{
    sQtVec4_B928 r;
    int t;
    __asm__(
        "mfc1      %1, %3\n"
        "qmtc2.ni  %1, $vf3\n"
        "vdiv      Q, $vf0w, $vf3x\n"
        "lqc2      $vf4, %2\n"
        "vwaitq\n"
        "vmulq.xyzw $vf4, $vf4, Q\n"
        "sqc2      $vf4, %0\n"
        : "=m"(r), "=&r"(t)
        : "m"(v), "f"(s)
        : "memory");
    return r;
}

// Walks a quadtree: inner nodes split the rect (lo, hi) at its midpoint into four children;
// leaves submit the rect's outline as a 5-vertex strip at the camera's height.
extern "C" void func_002BB928(void* ctx, sQtTree_B928* tree, sQtNode_B928* node, sQtVtx_B928* v,
                              sQtVec4_B928* lo, sQtVec4_B928* hi)
{
    if (node->child[0] & 1) {
        sQtVec4_B928 mid = qtDiv_B928(qtAdd_B928(*lo, *hi), 2.0f);
        sQtVec4_B928 a;
        a.x = lo->x;
        a.y = mid.y;
        a.z = 0.0f;
        a.w = 1.0f;
        sQtVec4_B928 b;
        b.x = hi->x;
        b.y = mid.y;
        b.z = 0.0f;
        b.w = 1.0f;
        sQtVec4_B928 c;
        c.x = mid.x;
        c.y = lo->y;
        c.z = 0.0f;
        c.w = 1.0f;
        sQtVec4_B928 d;
        d.x = mid.x;
        d.y = hi->y;
        d.z = 0.0f;
        d.w = 1.0f;
        func_002BB928(ctx, tree, tree->nodes + (node->child[0] >> 1), v, lo, &mid);
        func_002BB928(ctx, tree, tree->nodes + (node->child[1] >> 1), v, &a, &d);
        func_002BB928(ctx, tree, tree->nodes + (node->child[2] >> 1), v, &c, &b);
        func_002BB928(ctx, tree, tree->nodes + (node->child[3] >> 1), v, &mid, hi);
    } else {
        sQtCtx_B928* g = D_004A5B80_B928;
        char* rider = *(char**)(*(char**)(*(char**)(*(char**)((char*)D_004A28A8 + 0x84) + 0xC) + 0x40) + 0x18);
        sQtVec4_B928 cam = *((cQtCam_B928*)(rider + 0x6C0))->v05();
        sQtVec4_B928 t;
        t.x = lo->x;
        t.y = lo->y;
        t.z = cam.z;
        t.w = 1.0f;
        v[0].pos = t;
        t.x = hi->x;
        t.y = lo->y;
        t.z = cam.z;
        t.w = 1.0f;
        v[1].pos = t;
        t.x = hi->x;
        t.y = hi->y;
        t.z = cam.z;
        t.w = 1.0f;
        v[2].pos = t;
        t.x = lo->x;
        t.y = hi->y;
        t.z = cam.z;
        t.w = 1.0f;
        v[3].pos = t;
        t.x = lo->x;
        t.y = lo->y;
        t.z = cam.z;
        t.w = 1.0f;
        v[4].pos = t;
        sQtVEntry_B928* vt = g->vtable;
        vt[73].fn((char*)g + vt[73].delta, 5, v, 0);
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BBBF8);
#ifdef SKIP_ASM
extern "C" int func_002BBBF8(int a, ...) {
    return a;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BBC38);
#ifdef SKIP_ASM
extern float D_004D42B8[4];
extern float D_004D42C8[4];
extern float D_004D42D8[4];
extern float D_004D42E8[4];
extern float D_004D42F8[4];
extern float D_004D4308[4];
extern float D_004D4318[4];
extern float D_004D4328[4];
extern float D_004D4338[4];
extern float D_004D4348[4];
extern float D_004D4358[4];
extern float D_004D4368[4];
extern float D_004D4378[4];
extern float D_004D4388[4];
extern float D_004D4398[4];
extern float D_004D43A8[4];
extern float D_004D43B8[4];
extern float D_004D43C8[4];
extern float D_004D43D8[4];
extern float D_004D43E8[4];
extern float D_004D43F8[4];
extern float D_004D4408[4];
extern float D_004D4418[4];
extern float D_004D4428[4];
extern float D_004D4438[4];
extern float D_004D4448[4];
extern float D_004D4458[4];
extern float D_004D4468[4];
extern float D_004D4478[4];
extern float D_004D4488[4];
extern float D_004D4498[4];
extern float D_004D44A8[4];
extern float D_004D44B8[4];
extern float D_004D44C8[4];
extern float D_004D44D8[4];
extern float D_004D44E8[4];
extern float D_004D44F8[4];
extern float D_004D4508[4];
extern float D_004D4518[4];
extern float D_004D4528[4];
extern float D_004D4538[4];
extern float D_004D4548[4];
extern float D_004D4558[4];
extern float D_004D4568[4];
extern float D_004D4578[4];
extern float D_004D4588[4];
extern float D_004D4598[4];
extern float D_004D45A8[4];
extern float D_004D45B8[4];
extern float D_004D45C8[4];
extern float D_004D45D8[4];
extern float D_004D45E8[4];
extern float D_004D45F8[4];
extern float D_004D4608[4];
extern float D_004D4618[4];
extern float D_004D4628[4];
extern int D_004A535C;
extern int D_004A5358;
extern int D_004A5360[2];
extern int D_004A5368[2];
extern int D_004A5370[2];
extern int D_004A5378[2];
extern int D_004A5380[2];
extern int D_004A5388[2];
extern int D_004A5390[2];
extern int D_004A5398[2];
extern int D_004A53A0[2];
extern int D_004A53A8[2];
extern int D_004A53B0[2];
extern int D_004A53B8[2];
extern int D_004A53C0[2];
extern int D_004A53C8[2];
static inline void initE(int* p, int n)
{
    *(char*)p = n;
    *p = (*p & 0xFF) | (n << 8);
}
void sti_002BBC38(int init, int prio) __asm__("func_002BBC38");
void sti_002BBC38(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004A535C = 0;
        D_004A5358 = 0;
        initE(D_004A5360, 0);
        initE(D_004A5368, 1);
        initE(D_004A5370, 2);
        initE(D_004A5378, 3);
        initE(D_004A5380, 4);
        initE(D_004A5388, 5);
        initE(D_004A5390, 6);
        initE(D_004A5398, 7);
        initE(D_004A53A0, 8);
        initE(D_004A53A8, 9);
        initE(D_004A53B0, 10);
        initE(D_004A53B8, 11);
        initE(D_004A53C0, 12);
        initE(D_004A53C8, 13);
        D_004D42B8[0] = 1.0f;
        D_004D42B8[1] = 1.0f;
        D_004D42B8[2] = 1.0f;
        D_004D42B8[3] = 0.5f;
        D_004D42C8[0] = 0.4998680055141449f;
        D_004D42C8[1] = 1.0f;
        D_004D42C8[2] = 1.0f;
        D_004D42C8[3] = 0.0f;
        D_004D42D8[0] = 0.12951700389385223f;
        D_004D42D8[1] = 1.0f;
        D_004D42D8[2] = 1.0f;
        D_004D42D8[3] = 0.0f;
        D_004D42E8[0] = 0.22426900267601013f;
        D_004D42E8[1] = 0.9402310252189636f;
        D_004D42E8[2] = 0.5425059795379639f;
        D_004D42E8[3] = 0.0004030000127386302f;
        D_004D42F8[0] = 0.4652079939842224f;
        D_004D42F8[1] = 0.32170501351356506f;
        D_004D42F8[2] = 0.9943439960479736f;
        D_004D42F8[3] = 0.0f;
        D_004D4308[0] = 0.17792600393295288f;
        D_004D4308[1] = 1.0f;
        D_004D4308[2] = 1.0f;
        D_004D4308[3] = 0.0f;
        D_004D4318[0] = 0.4411740005016327f;
        D_004D4318[1] = 0.41388601064682007f;
        D_004D4318[2] = 0.3211260139942169f;
        D_004D4318[3] = 0.4398239850997925f;
        D_004D4328[0] = 0.500997006893158f;
        D_004D4328[1] = 0.24849599599838257f;
        D_004D4328[2] = 1.0f;
        D_004D4328[3] = 1.0f;
        D_004D4338[0] = 0.27687299251556396f;
        D_004D4338[1] = 0.6395620107650757f;
        D_004D4338[2] = 0.13423900306224823f;
        D_004D4338[3] = 0.0f;
        D_004D4348[0] = 0.8936439752578735f;
        D_004D4348[1] = 0.5263469815254211f;
        D_004D4348[2] = 0.5051450133323669f;
        D_004D4348[3] = 0.8687300086021423f;
        D_004D4358[0] = 1.0f;
        D_004D4358[1] = 1.0f;
        D_004D4358[2] = 1.0f;
        D_004D4358[3] = 1.0f;
        D_004D4368[0] = 1.0f;
        D_004D4368[1] = 0.0f;
        D_004D4368[2] = 0.0f;
        D_004D4368[3] = 0.0f;
        D_004D4378[0] = 1.0f;
        D_004D4378[1] = 0.550000011920929f;
        D_004D4378[2] = 0.5350000262260437f;
        D_004D4378[3] = 0.550000011920929f;
        D_004D4388[0] = 1.0f;
        D_004D4388[1] = 1.0f;
        D_004D4388[2] = 1.0f;
        D_004D4388[3] = 1.0f;
        D_004D4398[0] = 1.0f;
        D_004D4398[1] = 1.0f;
        D_004D4398[2] = 1.0f;
        D_004D4398[3] = 1.0f;
        D_004D43A8[0] = 1.0f;
        D_004D43A8[1] = 0.0f;
        D_004D43A8[2] = 0.0f;
        D_004D43A8[3] = 0.0f;
        D_004D43B8[0] = 1.0f;
        D_004D43B8[1] = 0.0f;
        D_004D43B8[2] = 0.0f;
        D_004D43B8[3] = 0.0f;
        D_004D43C8[0] = 1.0f;
        D_004D43C8[1] = 1.0f;
        D_004D43C8[2] = 1.0f;
        D_004D43C8[3] = 1.0f;
        D_004D43D8[0] = 1.0f;
        D_004D43D8[1] = 0.5f;
        D_004D43D8[2] = 1.0f;
        D_004D43D8[3] = 0.5f;
        D_004D43E8[0] = 1.0f;
        D_004D43E8[1] = 0.5f;
        D_004D43E8[2] = 1.0f;
        D_004D43E8[3] = 0.5f;
        D_004D43F8[0] = 1.0f;
        D_004D43F8[1] = 0.5f;
        D_004D43F8[2] = 1.0f;
        D_004D43F8[3] = 0.5f;
        D_004D4408[0] = 1.0f;
        D_004D4408[1] = 0.7828119993209839f;
        D_004D4408[2] = 0.06171900033950806f;
        D_004D4408[3] = 0.03984399884939194f;
        D_004D4418[0] = 1.0f;
        D_004D4418[1] = 1.0f;
        D_004D4418[2] = 0.7988259792327881f;
        D_004D4418[3] = 0.0f;
        D_004D4428[0] = 0.9886710047721863f;
        D_004D4428[1] = 0.9230499863624573f;
        D_004D4428[2] = 0.34311699867248535f;
        D_004D4428[3] = 0.0f;
        D_004D4438[0] = 1.0f;
        D_004D4438[1] = 1.0f;
        D_004D4438[2] = 1.0f;
        D_004D4438[3] = 1.0f;
        D_004D4448[0] = 1.0f;
        D_004D4448[1] = 1.0f;
        D_004D4448[2] = 0.7976430058479309f;
        D_004D4448[3] = 0.0f;
        D_004D4458[0] = 1.0f;
        D_004D4458[1] = 0.9222670197486877f;
        D_004D4458[2] = 0.34179699420928955f;
        D_004D4458[3] = 0.0f;
        D_004D4468[0] = 1.0f;
        D_004D4468[1] = 0.7847639918327332f;
        D_004D4468[2] = 0.06054700165987015f;
        D_004D4468[3] = 0.04062499850988388f;
        D_004D4478[0] = 1.0f;
        D_004D4478[1] = 0.800000011920929f;
        D_004D4478[2] = 0.44999998807907104f;
        D_004D4478[3] = 1.0f;
        D_004D4488[0] = 1.0f;
        D_004D4488[1] = 0.3281260132789612f;
        D_004D4488[2] = 1.0f;
        D_004D4488[3] = 0.3539060056209564f;
        D_004D4498[0] = 1.0f;
        D_004D4498[1] = 1.0f;
        D_004D4498[2] = 1.0f;
        D_004D4498[3] = 1.0f;
        D_004D44A8[0] = 1.0f;
        D_004D44A8[1] = 1.0f;
        D_004D44A8[2] = 1.0f;
        D_004D44A8[3] = 1.0f;
        D_004D44B8[0] = 1.0f;
        D_004D44B8[1] = 0.8613290190696716f;
        D_004D44B8[2] = 0.38124799728393555f;
        D_004D44B8[3] = 0.0f;
        D_004D44C8[0] = 1.0f;
        D_004D44C8[1] = 1.0f;
        D_004D44C8[2] = 1.0f;
        D_004D44C8[3] = 1.0f;
        D_004D44D8[0] = 1.0f;
        D_004D44D8[1] = 0.3244380056858063f;
        D_004D44D8[2] = 1.0f;
        D_004D44D8[3] = 0.0f;
        D_004D44E8[0] = 1.0f;
        D_004D44E8[1] = 1.0f;
        D_004D44E8[2] = 1.0f;
        D_004D44E8[3] = 1.0f;
        D_004D44F8[0] = 1.0f;
        D_004D44F8[1] = 1.0f;
        D_004D44F8[2] = 0.0f;
        D_004D44F8[3] = 0.0f;
        D_004D4508[0] = 0.7007060050964355f;
        D_004D4508[1] = 0.0f;
        D_004D4508[2] = 0.0f;
        D_004D4508[3] = 0.0f;
        D_004D4518[0] = 1.0f;
        D_004D4518[1] = 0.7828530073165894f;
        D_004D4518[2] = 0.06140600144863129f;
        D_004D4518[3] = 0.04146299883723259f;
        D_004D4528[0] = 1.0f;
        D_004D4528[1] = 0.32487601041793823f;
        D_004D4528[2] = 1.0f;
        D_004D4528[3] = 0.35280099511146545f;
        D_004D4538[0] = 1.0f;
        D_004D4538[1] = 1.0f;
        D_004D4538[2] = 0.7977359890937805f;
        D_004D4538[3] = 0.0f;
        D_004D4548[0] = 1.0f;
        D_004D4548[1] = 0.4937489926815033f;
        D_004D4548[2] = 1.0f;
        D_004D4548[3] = 0.49179700016975403f;
        D_004D4558[0] = 1.0f;
        D_004D4558[1] = 1.0f;
        D_004D4558[2] = 1.0f;
        D_004D4558[3] = 1.0f;
        D_004D4568[0] = 1.0f;
        D_004D4568[1] = 0.800000011920929f;
        D_004D4568[2] = 1.0f;
        D_004D4568[3] = 0.800000011920929f;
        D_004D4578[0] = 1.0f;
        D_004D4578[1] = 1.0f;
        D_004D4578[2] = 0.0f;
        D_004D4578[3] = 0.0f;
        D_004D4588[0] = 1.0f;
        D_004D4588[1] = 1.0f;
        D_004D4588[2] = 0.0f;
        D_004D4588[3] = 0.0f;
        D_004D4598[0] = 1.0f;
        D_004D4598[1] = 1.0f;
        D_004D4598[2] = 0.0f;
        D_004D4598[3] = 0.0f;
        D_004D45A8[0] = 1.0f;
        D_004D45A8[1] = 0.3273420035839081f;
        D_004D45A8[2] = 1.0f;
        D_004D45A8[3] = 0.35390499234199524f;
        D_004D45B8[0] = 1.0f;
        D_004D45B8[1] = 1.0f;
        D_004D45B8[2] = 0.061000000685453415f;
        D_004D45B8[3] = 0.039000000804662704f;
        D_004D45C8[0] = 1.0f;
        D_004D45C8[1] = 1.0f;
        D_004D45C8[2] = 0.7999979853630066f;
        D_004D45C8[3] = 0.0f;
        D_004D45D8[0] = 1.0f;
        D_004D45D8[1] = 0.9589840173721313f;
        D_004D45D8[2] = 0.6143789887428284f;
        D_004D45D8[3] = 0.0f;
        D_004D45E8[0] = 1.0f;
        D_004D45E8[1] = 0.9285150170326233f;
        D_004D45E8[2] = 0.3399839997291565f;
        D_004D45E8[3] = 0.0f;
        D_004D45F8[0] = 1.0f;
        D_004D45F8[1] = 0.8738250136375427f;
        D_004D45F8[2] = 0.24931700527668f;
        D_004D45F8[3] = 0.017578000202775f;
        D_004D4608[0] = 1.0f;
        D_004D4608[1] = 0.7843739986419678f;
        D_004D4608[2] = 0.06132800132036209f;
        D_004D4608[3] = 0.03945299983024597f;
        D_004D4618[0] = 1.0f;
        D_004D4618[1] = 0.0f;
        D_004D4618[2] = 1.0f;
        D_004D4618[3] = 0.0f;
        D_004D4628[0] = 1.0f;
        D_004D4628[1] = 1.0f;
        D_004D4628[2] = 0.0f;
        D_004D4628[3] = 0.0f;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("bx/seg_1BA100", func_002BC4E0);
#ifdef SKIP_ASM
extern "C" void func_002BBC38(int, int);

extern "C" void func_002BC4E0(void) {
    func_002BBC38(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC500);
#ifdef SKIP_ASM
extern "C" int func_002BC500(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC508);
#ifdef SKIP_ASM
extern "C" int func_002BC508(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC510);
#ifdef SKIP_ASM
extern "C" int func_002BC510(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC518);
#ifdef SKIP_ASM
extern "C" int func_002BC518(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC520);
#ifdef SKIP_ASM
extern "C" int func_002BC520(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC528);
#ifdef SKIP_ASM
extern "C" int func_002BC528(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC530);
#ifdef SKIP_ASM
extern "C" int func_002BC530(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC538);
#ifdef SKIP_ASM
extern "C" int func_002BC538(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC540);
#ifdef SKIP_ASM
extern "C" int func_002BC540(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC548);
#ifdef SKIP_ASM
extern "C" int func_002BC548(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC550);
#ifdef SKIP_ASM
extern "C" int func_002BC550(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC558);
#ifdef SKIP_ASM
extern "C" int func_002BC558(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC560);
#ifdef SKIP_ASM
extern "C" int func_002BC560(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC568);
#ifdef SKIP_ASM
extern "C" int func_002BC568(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC570);
#ifdef SKIP_ASM
extern "C" int func_002BC570(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC578);
#ifdef SKIP_ASM
extern "C" int func_002BC578(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC580);
#ifdef SKIP_ASM
extern "C" int func_002BC580(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC588);
#ifdef SKIP_ASM
extern "C" int func_002BC588(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC590);
#ifdef SKIP_ASM
extern "C" int func_002BC590(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC598);
#ifdef SKIP_ASM
extern "C" int func_002BC598(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5A0);
#ifdef SKIP_ASM
extern "C" int func_002BC5A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5A8);
#ifdef SKIP_ASM
extern "C" int func_002BC5A8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5B0);
#ifdef SKIP_ASM
extern "C" int func_002BC5B0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5B8);
#ifdef SKIP_ASM
extern "C" int func_002BC5B8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5C0);
#ifdef SKIP_ASM
extern "C" int func_002BC5C0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5C8);
#ifdef SKIP_ASM
extern "C" int func_002BC5C8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5D0);
#ifdef SKIP_ASM
extern "C" int func_002BC5D0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5D8);
#ifdef SKIP_ASM
extern "C" int func_002BC5D8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5E0);
#ifdef SKIP_ASM
extern "C" int func_002BC5E0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5E8);
#ifdef SKIP_ASM
extern "C" int func_002BC5E8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5F0);
#ifdef SKIP_ASM
extern "C" int func_002BC5F0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC5F8);
#ifdef SKIP_ASM
extern "C" int func_002BC5F8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC600);
#ifdef SKIP_ASM
extern "C" int func_002BC600(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC608);
#ifdef SKIP_ASM
extern "C" int func_002BC608(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC610);
#ifdef SKIP_ASM
extern "C" int func_002BC610(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC618);
#ifdef SKIP_ASM
extern "C" int func_002BC618(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC620);
#ifdef SKIP_ASM
extern "C" int func_002BC620(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC628);
#ifdef SKIP_ASM
extern "C" int func_002BC628(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC630);
#ifdef SKIP_ASM
extern "C" int func_002BC630(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC638);
#ifdef SKIP_ASM
extern "C" int func_002BC638(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC640);
#ifdef SKIP_ASM
extern "C" int func_002BC640(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC648);
#ifdef SKIP_ASM
extern "C" int func_002BC648(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC650);
#ifdef SKIP_ASM
extern "C" int func_002BC650(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC658);
#ifdef SKIP_ASM
extern "C" int func_002BC658(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC660);
#ifdef SKIP_ASM
extern "C" int func_002BC660(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC668);
#ifdef SKIP_ASM
extern "C" int func_002BC668(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC670);
#ifdef SKIP_ASM
extern "C" int func_002BC670(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC678);
#ifdef SKIP_ASM
extern "C" int func_002BC678(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC680);
#ifdef SKIP_ASM
extern "C" int func_002BC680(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC688);
#ifdef SKIP_ASM
extern "C" int func_002BC688(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC690);
#ifdef SKIP_ASM
extern "C" int func_002BC690(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC698);
#ifdef SKIP_ASM
extern "C" int func_002BC698(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6A0);
#ifdef SKIP_ASM
extern "C" int func_002BC6A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6A8);
#ifdef SKIP_ASM
extern "C" int func_002BC6A8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6B0);
#ifdef SKIP_ASM
extern "C" int func_002BC6B0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6B8);
#ifdef SKIP_ASM
extern "C" int func_002BC6B8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6C0);
#ifdef SKIP_ASM
extern "C" int func_002BC6C0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6C8);
#ifdef SKIP_ASM
extern "C" int func_002BC6C8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6D0);
#ifdef SKIP_ASM
extern "C" int func_002BC6D0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6D8);
#ifdef SKIP_ASM
extern "C" int func_002BC6D8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6E0);
#ifdef SKIP_ASM
extern "C" int func_002BC6E0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6E8);
#ifdef SKIP_ASM
extern "C" int func_002BC6E8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6F0);
#ifdef SKIP_ASM
extern "C" int func_002BC6F0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC6F8);
#ifdef SKIP_ASM
extern char D_00485AF8[];
extern "C" void *func_002BC6F8(void *arg0) {
    *(char **)((char *)arg0 + 4) = D_00485AF8;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(int *)((char *)arg0 + 0xC) = -1;
    *(int *)((char *)arg0 + 8) = -1;
    *(int *)((char *)arg0 + 0x14) = -1;
    *(int *)((char *)arg0 + 0x10) = -1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC728);
#ifdef SKIP_ASM
extern char D_004858C0[];
extern "C" void *func_002BC728(void *arg0) {
    *(char **)((char *)arg0 + 4) = D_004858C0;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(int *)((char *)arg0 + 0xC) = -1;
    *(int *)((char *)arg0 + 8) = -1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC750);
#ifdef SKIP_ASM
extern char D_00485688[];
extern "C" void *func_002BC750(void *arg0) {
    *(char **)((char *)arg0 + 4) = D_00485688;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(int *)((char *)arg0 + 0xC) = -1;
    *(int *)((char *)arg0 + 8) = -1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC778);
#ifdef SKIP_ASM
extern char D_00485450[];
extern "C" void *func_002BC778(void *arg0) {
    *(char **)((char *)arg0 + 4) = D_00485450;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(int *)((char *)arg0 + 0xC) = -1;
    *(int *)((char *)arg0 + 8) = -1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC7A0);
#ifdef SKIP_ASM
extern char D_00485218[];
extern "C" void *func_002BC7A0(void *arg0) {
    *(char **)((char *)arg0 + 4) = D_00485218;
    *(float *)((char *)arg0 + 0xC) = 30000.0f;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(float *)((char *)arg0 + 8) = 30000.0f;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC7C8);
#ifdef SKIP_ASM
extern char D_00484FE0[];
extern "C" void *func_002BC7C8(void *arg0) {
    float zero = 0.0f;
    float a = 3000.0f, b = 30000.0f, c = 0.43f, d = 0.55f, e = 0.71f;
    *(int **)((char*)arg0 + 4) = (int*)D_00484FE0;
    *(float *)((char*)arg0 + 0) = -99999.0f;
    *(float *)((char*)arg0 + 0xC) = zero;
    *(float *)((char*)arg0 + 0x14) = a;
    *(float *)((char*)arg0 + 0x1C) = b;
    *(float *)((char*)arg0 + 0x24) = c;
    *(float *)((char*)arg0 + 0x2C) = d;
    *(float *)((char*)arg0 + 0x34) = e;
    *(float *)((char*)arg0 + 0x8) = zero;
    *(float *)((char*)arg0 + 0x10) = a;
    *(float *)((char*)arg0 + 0x18) = b;
    *(float *)((char*)arg0 + 0x20) = c;
    *(float *)((char*)arg0 + 0x28) = d;
    *(float *)((char*)arg0 + 0x30) = e;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC830);
#ifdef SKIP_ASM
extern char D_00484DA8[];
extern "C" void *func_002BC830(void *self) {
    float one = 1.0f, zero = 0.0f;
    float *p = (float*)self;
    p[0] = -99999.0f;
    *(void**)((char*)self + 4) = D_00484DA8;
    p[3] = one;
    p[2] = one;
    p[5] = one;
    p[4] = one;
    p[7] = one;
    p[6] = one;
    p[9] = one;
    p[8] = one;
    p[11] = one;
    p[10] = one;
    p[13] = zero;
    p[12] = zero;
    p[15] = zero;
    p[14] = zero;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC890);
#ifdef SKIP_ASM
extern char D_00484B70[];
extern "C" void *func_002BC890(void *self) {
    float one = 1.0f, zero = 0.0f;
    float *p = (float*)self;
    p[0] = -99999.0f;
    *(void**)((char*)self + 4) = D_00484B70;
    p[3] = one;
    p[2] = one;
    p[5] = one;
    p[4] = one;
    p[7] = one;
    p[6] = one;
    p[9] = zero;
    p[8] = zero;
    p[11] = zero;
    p[10] = zero;
    p[13] = zero;
    p[12] = zero;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC8E8);
#ifdef SKIP_ASM
extern char D_00484938[];
extern "C" void *func_002BC8E8(void *arg0) {
    float zero = 0.0f;
    *(char **)((char *)arg0 + 4) = D_00484938;
    *(float *)((char *)arg0 + 0xC) = zero;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(float *)((char *)arg0 + 8) = zero;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC910);
#ifdef SKIP_ASM
extern char D_00484700[];
extern "C" void *func_002BC910(void *self) {
    float one = 1.0f, zero = 0.0f;
    float *p = (float*)self;
    p[0] = -99999.0f;
    *(void**)((char*)self + 4) = D_00484700;
    p[3] = zero;
    p[2] = zero;
    p[5] = zero;
    p[4] = zero;
    p[7] = one;
    p[6] = one;
    p[9] = one;
    p[8] = one;
    p[11] = one;
    p[10] = one;
    p[13] = one;
    p[12] = one;
    ((int*)p)[15] = 0;
    ((int*)p)[14] = 0;
    p[17] = one;
    p[16] = one;
    p[19] = one;
    p[18] = one;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC980);
#ifdef SKIP_ASM
extern char D_004844C8[];
extern "C" void *func_002BC980(void *arg0) {
    float one = 1.0f;
    *(char **)((char *)arg0 + 4) = D_004844C8;
    *(float *)((char *)arg0 + 0xC) = one;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(float *)((char *)arg0 + 8) = one;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BC9B0);
#ifdef SKIP_ASM
// Lighting painter (tWPIGD_Lighting) constructor: four current/target
// irradiance bank references, all starting at the empty reference, plus
// current/target gain (1.0) and rim (0.75).
struct sRef_C9B0 { int a; int b; };
struct sSlot_C9B0 { sRef_C9B0 cur; sRef_C9B0 tgt; };
struct sLight_C9B0 {
    float f0;
    void *vt;
    sSlot_C9B0 slot[4];
    float gain, gainTgt, rim, rimTgt;
};
extern sRef_C9B0 D_004A53D0_C9B0 __asm__("D_004A53D0");
extern char D_00484290[];

static inline void refInit_C9B0(sRef_C9B0 *r) {
    r->b = 0;
    r->a = 0;
}

extern "C" sLight_C9B0 *func_002BC9B0(sLight_C9B0 *self) {
    self->vt = D_00484290;
    self->f0 = -99999.0f;
    refInit_C9B0(&self->slot[0].cur); refInit_C9B0(&self->slot[0].tgt);
    refInit_C9B0(&self->slot[1].cur); refInit_C9B0(&self->slot[1].tgt);
    refInit_C9B0(&self->slot[2].cur); refInit_C9B0(&self->slot[2].tgt);
    refInit_C9B0(&self->slot[3].cur); refInit_C9B0(&self->slot[3].tgt);
    { sRef_C9B0 t = D_004A53D0_C9B0; self->slot[0].tgt = t; self->slot[0].cur = self->slot[0].tgt; }
    { sRef_C9B0 t = D_004A53D0_C9B0; self->slot[1].tgt = t; self->slot[1].cur = self->slot[1].tgt; }
    { sRef_C9B0 t = D_004A53D0_C9B0; self->slot[2].tgt = t; self->slot[2].cur = self->slot[2].tgt; }
    { sRef_C9B0 t = D_004A53D0_C9B0; self->slot[3].tgt = t; self->slot[3].cur = self->slot[3].tgt; }
    self->gainTgt = 1.0f;
    self->rimTgt = 0.75f;
    self->gain = 1.0f;
    self->rim = 0.75f;
    return self;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCAF8);
#ifdef SKIP_ASM
extern char D_00484058[];
#define F_CAF8(o) (*(float*)(self + (o)))
extern "C" void* func_002BCAF8(char *self) {
    *(char**)(self + 4) = D_00484058;
    F_CAF8(0) = -99999.0f;
    F_CAF8(0x8) = F_CAF8(0xC) = 0.0f;
    F_CAF8(0x10) = F_CAF8(0x14) = 6.0f;
    F_CAF8(0x18) = F_CAF8(0x1C) = 0.0f;
    F_CAF8(0x20) = F_CAF8(0x24) = 0.0f;
    F_CAF8(0x28) = F_CAF8(0x2C) = 0.0f;
    F_CAF8(0x30) = F_CAF8(0x34) = 10.0f;
    F_CAF8(0x38) = F_CAF8(0x3C) = 1.0f;
    F_CAF8(0x40) = F_CAF8(0x44) = 1.0f;
    F_CAF8(0x48) = F_CAF8(0x4C) = 0.0f;
    F_CAF8(0x50) = F_CAF8(0x54) = 0.0f;
    F_CAF8(0x58) = F_CAF8(0x5C) = 0.0f;
    F_CAF8(0x60) = F_CAF8(0x64) = 1.0f;
    F_CAF8(0x68) = F_CAF8(0x6C) = 1.0f;
    F_CAF8(0x70) = F_CAF8(0x74) = 1.0f;
    F_CAF8(0x78) = F_CAF8(0x7C) = 1.0f;
    F_CAF8(0x80) = F_CAF8(0x84) = 0.05999999865889549f;
    F_CAF8(0x88) = F_CAF8(0x8C) = 1.0f;
    F_CAF8(0x90) = F_CAF8(0x94) = 1.0f;
    F_CAF8(0x98) = F_CAF8(0x9C) = 1.0f;
    return self;
}
#undef F_CAF8
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCBD0);
#ifdef SKIP_ASM
extern char D_00483E20[];
extern "C" void *func_002BCBD0(void *arg0) {
    float zero = 0.0f;
    *(char **)((char *)arg0 + 4) = D_00483E20;
    *(int *)((char *)arg0 + 0xC) = 0;
    *(int *)((char *)arg0 + 0x8) = 0;
    *(float *)((char *)arg0 + 0) = -99999.0f;
    *(float *)((char *)arg0 + 0x14) = zero;
    *(float *)((char *)arg0 + 0x10) = zero;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCC00);
#ifdef SKIP_ASM
class cCC00 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BCC00(void *self, void *p, float f) {
    cCC00 *o = (cCC00*)self;
    o->vt();
    f = f * f;
    *(int*)((char*)self + 8) = (int)(f * (float)*(int*)((char*)p + 4) + (1.0f - f) * (float)*(int*)((char*)self + 8));
    *(int*)((char*)self + 0xC) = *(int*)((char*)p + 4);
    *(int*)((char*)self + 0x10) = (int)(f * (float)*(int*)((char*)p + 8) + (1.0f - f) * (float)*(int*)((char*)self + 0x10));
    *(int*)((char*)self + 0x14) = *(int*)((char*)p + 8);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCCC8);
#ifdef SKIP_ASM
class cCCC8 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BCCC8(void *self, void *p, float f) {
    cCCC8 *o = (cCCC8*)self;
    o->vt();
    f = f * f;
    *(int*)((char*)self + 8) = (int)(f * (float)*(int*)((char*)p + 4) + (1.0f - f) * (float)*(int*)((char*)self + 8));
    *(int*)((char*)self + 0xC) = *(int*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCD68);
#ifdef SKIP_ASM
class cCD68 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BCD68(void *self, void *p, float f) {
    cCD68 *o = (cCD68*)self;
    o->vt();
    f = f * f;
    *(int*)((char*)self + 8) = (int)(f * (float)*(int*)((char*)p + 4) + (1.0f - f) * (float)*(int*)((char*)self + 8));
    *(int*)((char*)self + 0xC) = *(int*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCE08);
#ifdef SKIP_ASM
class cCE08 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BCE08(void *self, void *p, float f) {
    cCE08 *o = (cCE08*)self;
    o->vt();
    f = f * f;
    *(int*)((char*)self + 8) = (int)(f * (float)*(int*)((char*)p + 4) + (1.0f - f) * (float)*(int*)((char*)self + 8));
    *(int*)((char*)self + 0xC) = *(int*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCEA8);
#ifdef SKIP_ASM
class cCEA8 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BCEA8(void *self, void *p, float f) {
    cCEA8 *o = (cCEA8*)self;
    o->vt();
    f = f * f;
    *(float*)((char*)self + 8) = f * *(float*)((char*)p + 4) + (1.0f - f) * *(float*)((char*)self + 8);
    *(float*)((char*)self + 0xC) = *(float*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BCF38);
#ifdef SKIP_ASM
struct VEnt_CF38 { short delta; short idx; int (*fn)(void*); };
struct Pair_CF38 { float cur; float tgt; };
struct Obj_CF38 { int pad0; char* vt; Pair_CF38 p[6]; };
struct Src_CF38 { int pad0; float v[6]; };

extern "C" void func_002BCF38(Obj_CF38* self, Src_CF38* src, float t) {
    VEnt_CF38* e;
    float inv;
    e = (VEnt_CF38*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
    t = t * t;
    inv = 1.0f - t;
    self->p[0].cur = t * src->v[0] + inv * self->p[0].cur;
    self->p[0].tgt = src->v[0];
    self->p[1].cur = t * src->v[1] + inv * self->p[1].cur;
    self->p[1].tgt = src->v[1];
    self->p[2].cur = t * src->v[2] + inv * self->p[2].cur;
    self->p[2].tgt = src->v[2];
    self->p[3].cur = t * src->v[3] + inv * self->p[3].cur;
    self->p[3].tgt = src->v[3];
    self->p[4].cur = t * src->v[4] + inv * self->p[4].cur;
    self->p[4].tgt = src->v[4];
    self->p[5].cur = t * src->v[5] + inv * self->p[5].cur;
    self->p[5].tgt = src->v[5];
    e = (VEnt_CF38*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD068);
#ifdef SKIP_ASM
struct VEnt_D068 { short delta; short idx; int (*fn)(void*); };
struct VEntV_D068 { short delta; short idx; void (*fn)(void*); };
struct Pair_D068 { float cur; float tgt; };
struct Obj_D068 { int pad0; char* vt; Pair_D068 p[7]; };
struct Src_D068 { int pad0; float v[7]; };

extern "C" void func_002BD068(Obj_D068* self, Src_D068* src, float t) {
    VEnt_D068* e;
    float inv;
    e = (VEnt_D068*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
    t = t * t;
    inv = 1.0f - t;
    self->p[0].cur = t * src->v[0] + inv * self->p[0].cur;
    self->p[0].tgt = src->v[0];
    self->p[1].cur = t * src->v[1] + inv * self->p[1].cur;
    self->p[1].tgt = src->v[1];
    self->p[2].cur = t * src->v[2] + inv * self->p[2].cur;
    self->p[2].tgt = src->v[2];
    self->p[3].cur = t * src->v[3] + inv * self->p[3].cur;
    self->p[3].tgt = src->v[3];
    self->p[4].cur = t * src->v[4] + inv * self->p[4].cur;
    self->p[4].tgt = src->v[4];
    self->p[5].cur = t * src->v[5] + inv * self->p[5].cur;
    self->p[5].tgt = src->v[5];
    self->p[6].cur = t * src->v[6] + inv * self->p[6].cur;
    self->p[6].tgt = src->v[6];
    {
        VEntV_D068* e2 = (VEntV_D068*)(self->vt + 0x218);
        e2->fn((char*)self + e2->delta);
    }
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD1B8);
#ifdef SKIP_ASM
struct VEnt_D1B8 { short delta; short idx; int (*fn)(void*); };
struct Pair_D1B8 { float cur; float tgt; };
struct Obj_D1B8 { int pad0; char* vt; Pair_D1B8 p[6]; };
struct Src_D1B8 { int pad0; float v[6]; };

extern "C" void func_002BD1B8(Obj_D1B8* self, Src_D1B8* src, float t) {
    VEnt_D1B8* e;
    float inv;
    e = (VEnt_D1B8*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
    t = t * t;
    inv = 1.0f - t;
    self->p[0].cur = t * src->v[0] + inv * self->p[0].cur;
    self->p[0].tgt = src->v[0];
    self->p[1].cur = t * src->v[1] + inv * self->p[1].cur;
    self->p[1].tgt = src->v[1];
    self->p[2].cur = t * src->v[2] + inv * self->p[2].cur;
    self->p[2].tgt = src->v[2];
    self->p[3].cur = t * src->v[3] + inv * self->p[3].cur;
    self->p[3].tgt = src->v[3];
    self->p[4].cur = t * src->v[4] + inv * self->p[4].cur;
    self->p[4].tgt = src->v[4];
    self->p[5].cur = t * src->v[5] + inv * self->p[5].cur;
    self->p[5].tgt = src->v[5];
    e = (VEnt_D1B8*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD2E8);
#ifdef SKIP_ASM
class cD2E8 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BD2E8(void *self, void *p, float f) {
    cD2E8 *o = (cD2E8*)self;
    o->vt();
    f = f * f;
    *(float*)((char*)self + 8) = f * *(float*)((char*)p + 4) + (1.0f - f) * *(float*)((char*)self + 8);
    *(float*)((char*)self + 0xC) = *(float*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD378);
#ifdef SKIP_ASM
struct VEnt_D378 { short delta; short idx; int (*fn)(void*); };
struct Pair_D378 { float cur; float tgt; };
struct IPair_D378 { int cur; int tgt; };
struct Obj_D378 { int pad0; char* vt; Pair_D378 p[6]; IPair_D378 i6; Pair_D378 q[2]; };
struct Src_D378 { int pad0; float v[6]; int i6; float w[2]; };

extern "C" void func_002BD378(Obj_D378* self, Src_D378* src, float t) {
    VEnt_D378* e;
    float inv;
    e = (VEnt_D378*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
    t = t * t;
    inv = 1.0f - t;
    self->p[0].cur = t * src->v[0] + inv * self->p[0].cur;
    self->p[0].tgt = src->v[0];
    self->p[1].cur = t * src->v[1] + inv * self->p[1].cur;
    self->p[1].tgt = src->v[1];
    self->p[2].cur = t * src->v[2] + inv * self->p[2].cur;
    self->p[2].tgt = src->v[2];
    self->p[3].cur = t * src->v[3] + inv * self->p[3].cur;
    self->p[3].tgt = src->v[3];
    self->p[4].cur = t * src->v[4] + inv * self->p[4].cur;
    self->p[4].tgt = src->v[4];
    self->p[5].cur = t * src->v[5] + inv * self->p[5].cur;
    self->p[5].tgt = src->v[5];
    self->i6.cur = (int)(t * src->i6 + inv * self->i6.cur);
    self->i6.tgt = src->i6;
    self->q[0].cur = t * src->w[0] + inv * self->q[0].cur;
    self->q[0].tgt = src->w[0];
    self->q[1].cur = t * src->w[1] + inv * self->q[1].cur;
    self->q[1].tgt = src->w[1];
    e = (VEnt_D378*)(self->vt + 0x218);
    e->fn((char*)self + e->delta);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD518);
#ifdef SKIP_ASM
class cD518 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BD518(void *self, void *p, float f) {
    cD518 *o = (cD518*)self;
    o->vt();
    f = f * f;
    *(float*)((char*)self + 8) = f * *(float*)((char*)p + 4) + (1.0f - f) * *(float*)((char*)self + 8);
    *(float*)((char*)self + 0xC) = *(float*)((char*)p + 4);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD5A8);
#ifdef SKIP_ASM
struct sP_D5A8 { float x, y; };
class cD5A8 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BD5A8(void *self, void *p, float f) {
    cD5A8 *o = (cD5A8*)self;
    o->vt();
    f = f * f;
    *(sP_D5A8*)((char*)self + 8) = *(sP_D5A8*)((char*)p + 4);
    *(sP_D5A8*)((char*)self + 0x18) = *(sP_D5A8*)((char*)p + 0xC);
    *(sP_D5A8*)((char*)self + 0x28) = *(sP_D5A8*)((char*)p + 0x14);
    *(sP_D5A8*)((char*)self + 0x38) = *(sP_D5A8*)((char*)p + 0x1C);
    *(float*)((char*)self + 0x48) = f * *(float*)((char*)p + 0x24) + (1.0f - f) * *(float*)((char*)self + 0x48);
    *(float*)((char*)self + 0x4C) = *(float*)((char*)p + 0x24);
    *(float*)((char*)self + 0x50) = f * *(float*)((char*)p + 0x28) + (1.0f - f) * *(float*)((char*)self + 0x50);
    *(float*)((char*)self + 0x54) = *(float*)((char*)p + 0x28);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD698);
#ifdef SKIP_ASM
// Environment property blend: w^2 blend of all 19 current values toward the
// incoming set, which is then stored as the target.
class cD698 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BD698(void *self, void *p, float f) {
    cD698 *o = (cD698*)self;
    o->vt();
    f = f * f;
    *(float*)((char*)self + 0x8) = f * *(float*)((char*)p + 0x4) + (1.0f - f) * *(float*)((char*)self + 0x8);
    *(float*)((char*)self + 0xC) = *(float*)((char*)p + 0x4);
    *(float*)((char*)self + 0x10) = f * *(float*)((char*)p + 0x8) + (1.0f - f) * *(float*)((char*)self + 0x10);
    *(float*)((char*)self + 0x14) = *(float*)((char*)p + 0x8);
    *(float*)((char*)self + 0x18) = f * *(float*)((char*)p + 0xC) + (1.0f - f) * *(float*)((char*)self + 0x18);
    *(float*)((char*)self + 0x1C) = *(float*)((char*)p + 0xC);
    *(float*)((char*)self + 0x20) = f * *(float*)((char*)p + 0x10) + (1.0f - f) * *(float*)((char*)self + 0x20);
    *(float*)((char*)self + 0x24) = *(float*)((char*)p + 0x10);
    *(float*)((char*)self + 0x28) = f * *(float*)((char*)p + 0x14) + (1.0f - f) * *(float*)((char*)self + 0x28);
    *(float*)((char*)self + 0x2C) = *(float*)((char*)p + 0x14);
    *(float*)((char*)self + 0x30) = f * *(float*)((char*)p + 0x18) + (1.0f - f) * *(float*)((char*)self + 0x30);
    *(float*)((char*)self + 0x34) = *(float*)((char*)p + 0x18);
    *(float*)((char*)self + 0x38) = f * *(float*)((char*)p + 0x1C) + (1.0f - f) * *(float*)((char*)self + 0x38);
    *(float*)((char*)self + 0x3C) = *(float*)((char*)p + 0x1C);
    *(float*)((char*)self + 0x40) = f * *(float*)((char*)p + 0x20) + (1.0f - f) * *(float*)((char*)self + 0x40);
    *(float*)((char*)self + 0x44) = *(float*)((char*)p + 0x20);
    *(float*)((char*)self + 0x48) = f * *(float*)((char*)p + 0x24) + (1.0f - f) * *(float*)((char*)self + 0x48);
    *(float*)((char*)self + 0x4C) = *(float*)((char*)p + 0x24);
    *(float*)((char*)self + 0x50) = f * *(float*)((char*)p + 0x28) + (1.0f - f) * *(float*)((char*)self + 0x50);
    *(float*)((char*)self + 0x54) = *(float*)((char*)p + 0x28);
    *(float*)((char*)self + 0x58) = f * *(float*)((char*)p + 0x2C) + (1.0f - f) * *(float*)((char*)self + 0x58);
    *(float*)((char*)self + 0x5C) = *(float*)((char*)p + 0x2C);
    *(float*)((char*)self + 0x60) = f * *(float*)((char*)p + 0x30) + (1.0f - f) * *(float*)((char*)self + 0x60);
    *(float*)((char*)self + 0x64) = *(float*)((char*)p + 0x30);
    *(float*)((char*)self + 0x68) = f * *(float*)((char*)p + 0x34) + (1.0f - f) * *(float*)((char*)self + 0x68);
    *(float*)((char*)self + 0x6C) = *(float*)((char*)p + 0x34);
    *(float*)((char*)self + 0x70) = f * *(float*)((char*)p + 0x38) + (1.0f - f) * *(float*)((char*)self + 0x70);
    *(float*)((char*)self + 0x74) = *(float*)((char*)p + 0x38);
    *(float*)((char*)self + 0x78) = f * *(float*)((char*)p + 0x3C) + (1.0f - f) * *(float*)((char*)self + 0x78);
    *(float*)((char*)self + 0x7C) = *(float*)((char*)p + 0x3C);
    *(float*)((char*)self + 0x80) = f * *(float*)((char*)p + 0x40) + (1.0f - f) * *(float*)((char*)self + 0x80);
    *(float*)((char*)self + 0x84) = *(float*)((char*)p + 0x40);
    *(float*)((char*)self + 0x88) = f * *(float*)((char*)p + 0x44) + (1.0f - f) * *(float*)((char*)self + 0x88);
    *(float*)((char*)self + 0x8C) = *(float*)((char*)p + 0x44);
    *(float*)((char*)self + 0x90) = f * *(float*)((char*)p + 0x48) + (1.0f - f) * *(float*)((char*)self + 0x90);
    *(float*)((char*)self + 0x94) = *(float*)((char*)p + 0x48);
    *(float*)((char*)self + 0x98) = f * *(float*)((char*)p + 0x4C) + (1.0f - f) * *(float*)((char*)self + 0x98);
    *(float*)((char*)self + 0x9C) = *(float*)((char*)p + 0x4C);
    o->vt();
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BD968);
#ifdef SKIP_ASM
class cD968 { public: int f0; virtual void v0();virtual void v1();virtual void v2();virtual void v3();virtual void v4();virtual void v5();virtual void v6();virtual void v7();virtual void v8();virtual void v9();virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();virtual void v19();virtual void v20();virtual void v21();virtual void v22();virtual void v23();virtual void v24();virtual void v25();virtual void v26();virtual void v27();virtual void v28();virtual void v29();virtual void v30();virtual void v31();virtual void v32();virtual void v33();virtual void v34();virtual void v35();virtual void v36();virtual void v37();virtual void v38();virtual void v39();virtual void v40();virtual void v41();virtual void v42();virtual void v43();virtual void v44();virtual void v45();virtual void v46();virtual void v47();virtual void v48();virtual void v49();virtual void v50();virtual void v51();virtual void v52();virtual void v53();virtual void v54();virtual void v55();virtual void v56();virtual void v57();virtual void v58();virtual void v59();virtual void v60();virtual void v61();virtual void v62();virtual void v63();virtual void v64();virtual void v65(); virtual int vt(); };
extern "C" void func_002BD968(void *self, void *p, float f) {
    cD968 *o = (cD968*)self;
    o->vt();
    f = f * f;
    *(int*)((char*)self + 8) = (int)(f * (float)*(int*)((char*)p + 4) + (1.0f - f) * (float)*(int*)((char*)self + 8));
    *(int*)((char*)self + 0xC) = *(int*)((char*)p + 4);
    *(float*)((char*)self + 0x10) = f * *(float*)((char*)p + 8) + (1.0f - f) * *(float*)((char*)self + 0x10);
    *(float*)((char*)self + 0x14) = *(float*)((char*)p + 8);
    o->vt();
}
#endif

extern "C" void func_002BDA28(void) {
}

extern "C" void func_002BDA30(void) {
}

extern "C" void func_002BDA38(void) {
}

extern "C" void func_002BDA40(void) {
}

extern "C" void func_002BDA48(void) {
}

extern "C" void func_002BDA50(void) {
}

extern "C" void func_002BDA58(void) {
}

extern "C" void func_002BDA60(void) {
}

extern "C" void func_002BDA68(void) {
}

extern "C" void func_002BDA70(void) {
}

extern "C" void func_002BDA78(void) {
}

extern "C" void func_002BDA80(void) {
}

extern "C" void func_002BDA88(void) {
}

extern "C" void func_002BDA90(void) {
}

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDA98);
#ifdef SKIP_ASM
extern "C" int func_002BDA98(void *arg0, void *arg1) {
    if ((*(int *)((char*)(arg0) + (8))) != (*(int *)((char*)(arg1) + (4)))) {
        return 0;
    }
    return (*(int *)((char*)(arg0) + (0x10))) == (*(int *)((char*)(arg1) + (8)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDAC8);
#ifdef SKIP_ASM
extern "C" int func_002BDAC8(void *arg0, void *arg1) {
    return (*(int *)((char*)(arg0) + (8))) == (*(int *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDAE0);
#ifdef SKIP_ASM
extern "C" int func_002BDAE0(void *arg0, void *arg1) {
    return (*(int *)((char*)(arg0) + (8))) == (*(int *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDAF8);
#ifdef SKIP_ASM
extern "C" int func_002BDAF8(void *arg0, void *arg1) {
    return (*(int *)((char*)(arg0) + (8))) == (*(int *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDB10);
#ifdef SKIP_ASM
extern "C" int func_002BDB10(void *arg0, void *arg1) {
    int var_2;

    var_2 = 0;
    if ((*(float *)((char*)(arg0) + (8))) == (*(float *)((char*)(arg1) + (4)))) {
        var_2 = 1;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDB38);
#ifdef SKIP_ASM
extern "C" int func_002BDB38(void *a, void *b) {
    if (*(float*)((char*)a + 8) != *(float*)((char*)b + 4)) return 0;
    if (*(float*)((char*)a + 0x10) != *(float*)((char*)b + 8)) return 0;
    if (*(float*)((char*)a + 0x18) != *(float*)((char*)b + 0xC)) return 0;
    if (*(float*)((char*)a + 0x20) != *(float*)((char*)b + 0x10)) return 0;
    if (*(float*)((char*)a + 0x28) != *(float*)((char*)b + 0x14)) return 0;
    if (*(float*)((char*)a + 0x30) != *(float*)((char*)b + 0x18)) return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDBD0);
#ifdef SKIP_ASM
extern "C" int func_002BDBD0(void *a, void *b) {
    if (*(float*)((char*)a + 0x8) != *(float*)((char*)b + 0x4)) return 0;
    if (*(float*)((char*)a + 0x10) != *(float*)((char*)b + 0x8)) return 0;
    if (*(float*)((char*)a + 0x18) != *(float*)((char*)b + 0xC)) return 0;
    if (*(float*)((char*)a + 0x20) != *(float*)((char*)b + 0x10)) return 0;
    if (*(float*)((char*)a + 0x28) != *(float*)((char*)b + 0x14)) return 0;
    if (*(float*)((char*)a + 0x30) != *(float*)((char*)b + 0x18)) return 0;
    if (*(float*)((char*)a + 0x38) != *(float*)((char*)b + 0x1C)) return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDC78);
#ifdef SKIP_ASM
extern "C" int func_002BDC78(void *a, void *b) {
    if (*(float*)((char*)a + 8) != *(float*)((char*)b + 4)) return 0;
    if (*(float*)((char*)a + 0x10) != *(float*)((char*)b + 8)) return 0;
    if (*(float*)((char*)a + 0x18) != *(float*)((char*)b + 0xC)) return 0;
    if (*(float*)((char*)a + 0x20) != *(float*)((char*)b + 0x10)) return 0;
    if (*(float*)((char*)a + 0x28) != *(float*)((char*)b + 0x14)) return 0;
    if (*(float*)((char*)a + 0x30) != *(float*)((char*)b + 0x18)) return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDD10);
#ifdef SKIP_ASM
extern "C" int func_002BDD10(void *arg0, void *arg1) {
    int var_2;

    var_2 = 0;
    if ((*(float *)((char*)(arg0) + (8))) == (*(float *)((char*)(arg1) + (4)))) {
        var_2 = 1;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDD38);
#ifdef SKIP_ASM
extern "C" int func_002BDD38(void *a, void *b) {
    if (*(float*)((char*)a + 0x8) != *(float*)((char*)b + 0x4)) return 0;
    if (*(float*)((char*)a + 0x10) != *(float*)((char*)b + 0x8)) return 0;
    if (*(float*)((char*)a + 0x18) != *(float*)((char*)b + 0xC)) return 0;
    if (*(float*)((char*)a + 0x20) != *(float*)((char*)b + 0x10)) return 0;
    if (*(float*)((char*)a + 0x28) != *(float*)((char*)b + 0x14)) return 0;
    if (*(float*)((char*)a + 0x30) != *(float*)((char*)b + 0x18)) return 0;
    if (*(int*)((char*)a + 0x38) != *(int*)((char*)b + 0x1C)) return 0;
    if (*(float*)((char*)a + 0x40) != *(float*)((char*)b + 0x20)) return 0;
    if (*(float*)((char*)a + 0x48) != *(float*)((char*)b + 0x24)) return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDE08);
#ifdef SKIP_ASM
extern "C" int func_002BDE08(void *arg0, void *arg1) {
    int var_2;

    var_2 = 0;
    if ((*(float *)((char*)(arg0) + (8))) == (*(float *)((char*)(arg1) + (4)))) {
        var_2 = 1;
    }
    return var_2;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDE30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_002BB100_DE30(char *, char *) __asm__("func_002BB100");
extern "C" int func_002BDE30(char *a, char *b) {
    if (func_002BB100_DE30(a + 8, b + 4)) return 0;
    if (func_002BB100_DE30(a + 0x18, b + 0xC)) return 0;
    if (func_002BB100_DE30(a + 0x28, b + 0x14)) return 0;
    if (func_002BB100_DE30(a + 0x38, b + 0x1C)) return 0;
    if (*(float*)(a + 0x48) != *(float*)(b + 0x24)) return 0;
    if (*(float*)(a + 0x50) != *(float*)(b + 0x28)) return 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BDEE0);
#ifdef SKIP_ASM
// Environment property compare: all 19 current values against the incoming set.
extern "C" int func_002BDEE0(void *arg0, void *arg1) {
    if ((*(float *)((char*)(arg0) + (0x8))) != (*(float *)((char*)(arg1) + (0x4)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x10))) != (*(float *)((char*)(arg1) + (0x8)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x18))) != (*(float *)((char*)(arg1) + (0xC)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x20))) != (*(float *)((char*)(arg1) + (0x10)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x28))) != (*(float *)((char*)(arg1) + (0x14)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x30))) != (*(float *)((char*)(arg1) + (0x18)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x38))) != (*(float *)((char*)(arg1) + (0x1C)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x40))) != (*(float *)((char*)(arg1) + (0x20)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x48))) != (*(float *)((char*)(arg1) + (0x24)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x50))) != (*(float *)((char*)(arg1) + (0x28)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x58))) != (*(float *)((char*)(arg1) + (0x2C)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x60))) != (*(float *)((char*)(arg1) + (0x30)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x68))) != (*(float *)((char*)(arg1) + (0x34)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x70))) != (*(float *)((char*)(arg1) + (0x38)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x78))) != (*(float *)((char*)(arg1) + (0x3C)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x80))) != (*(float *)((char*)(arg1) + (0x40)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x88))) != (*(float *)((char*)(arg1) + (0x44)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x90))) != (*(float *)((char*)(arg1) + (0x48)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x98))) != (*(float *)((char*)(arg1) + (0x4C)))) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE078);
#ifdef SKIP_ASM
extern "C" int func_002BE078(void *arg0, void *arg1) {
    if ((*(int *)((char*)(arg0) + (8))) != (*(int *)((char*)(arg1) + (4)))) {
        return 0;
    }
    if ((*(float *)((char*)(arg0) + (0x10))) != (*(float *)((char*)(arg1) + (8)))) {
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE0B0);
#ifdef SKIP_ASM
extern "C" void func_002BE0B0(void *p) {
    *(int*)((char*)p + 0) = 0;
    *(int*)((char*)p + 8) = -1;
    *(int*)((char*)p + 0x10) = -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE0C8);
#ifdef SKIP_ASM
extern "C" void func_002BE0C8(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (8))) = -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE0D8);
#ifdef SKIP_ASM
extern "C" void func_002BE0D8(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (8))) = -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE0E8);
#ifdef SKIP_ASM
extern "C" void func_002BE0E8(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (8))) = -1;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE0F8);
#ifdef SKIP_ASM
extern "C" void func_002BE0F8(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(float *)((char*)(arg0) + (8))) = 30000.0f;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE108);
#ifdef SKIP_ASM
extern "C" void func_002BE108(void *arg0) {
    (*(float *)((char*)(arg0) + (0x10))) = 3000.0f;
    (*(float *)((char*)(arg0) + (0x18))) = 30000.0f;
    (*(float *)((char*)(arg0) + (0x20))) = 0.43f;
    (*(float *)((char*)(arg0) + (0x28))) = 0.55f;
    (*(float *)((char*)(arg0) + (0x30))) = 0.71f;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0))) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE140);
#ifdef SKIP_ASM
extern "C" void func_002BE140(void *arg0) {
    *(float *)((char *)arg0 + 0x8) = 1.0f;
    *(float *)((char *)arg0 + 0x10) = 1.0f;
    *(float *)((char *)arg0 + 0x18) = 1.0f;
    *(float *)((char *)arg0 + 0x20) = 1.0f;
    *(float *)((char *)arg0 + 0x28) = 1.0f;
    *(int *)((char *)arg0 + 0x30) = 0;
    *(int *)((char *)arg0 + 0x38) = 0;
    *(int *)((char *)arg0 + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE170);
#ifdef SKIP_ASM
extern "C" void func_002BE170(void *arg0) {
    *(float *)((char *)arg0 + 0x8) = 1.0f;
    *(float *)((char *)arg0 + 0x10) = 1.0f;
    *(float *)((char *)arg0 + 0x18) = 1.0f;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x28) = 0;
    *(int *)((char *)arg0 + 0x30) = 0;
    *(int *)((char *)arg0 + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE198);
#ifdef SKIP_ASM
extern "C" void func_002BE198(void *p) {
    *(int*)((char*)p + 8) = 0;
    *(int*)((char*)p + 0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE1A8);
#ifdef SKIP_ASM
extern "C" void func_002BE1A8(void *arg0) {
    *(int *)((char *)arg0 + 0x8) = 0;
    *(int *)((char *)arg0 + 0x10) = 0;
    *(float *)((char *)arg0 + 0x18) = 1.0f;
    *(float *)((char *)arg0 + 0x20) = 1.0f;
    *(float *)((char *)arg0 + 0x28) = 1.0f;
    *(float *)((char *)arg0 + 0x30) = 1.0f;
    *(int *)((char *)arg0 + 0x38) = 0;
    *(float *)((char *)arg0 + 0x40) = 1.0f;
    *(float *)((char *)arg0 + 0x48) = 1.0f;
    *(int *)((char *)arg0 + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE1E0);
#ifdef SKIP_ASM
extern "C" void func_002BE1E0(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(float *)((char*)(arg0) + (8))) = 1.0f;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE1F8);
#ifdef SKIP_ASM
// Lighting painter reset: all four bank slots get the empty reference.
struct sLightRef_BE1F8 {
    int a;
    int b;
};
extern sLightRef_BE1F8 D_004A53D0;

extern "C" void func_002BE1F8(void *arg0) {
    *(sLightRef_BE1F8 *)((char *)arg0 + 0x8) = D_004A53D0;
    *(sLightRef_BE1F8 *)((char *)arg0 + 0x18) = D_004A53D0;
    *(sLightRef_BE1F8 *)((char *)arg0 + 0x28) = D_004A53D0;
    *(sLightRef_BE1F8 *)((char *)arg0 + 0x38) = D_004A53D0;
    *(float *)((char *)arg0 + 0x48) = 1.0f;
    *(float *)((char *)arg0 + 0x50) = 0.75f;
    *(int *)((char *)arg0 + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE258);
#ifdef SKIP_ASM
extern "C" void func_002BE258(void *arg0) {
    *(int *)((char *)arg0 + 0x8) = 0;
    *(float *)((char *)arg0 + 0x10) = 6.0f;
    *(int *)((char *)arg0 + 0x18) = 0;
    *(int *)((char *)arg0 + 0x20) = 0;
    *(int *)((char *)arg0 + 0x28) = 0;
    *(float *)((char *)arg0 + 0x30) = 10.0f;
    *(float *)((char *)arg0 + 0x38) = 1.0f;
    *(float *)((char *)arg0 + 0x40) = 1.0f;
    *(int *)((char *)arg0 + 0x48) = 0;
    *(int *)((char *)arg0 + 0x50) = 0;
    *(int *)((char *)arg0 + 0x58) = 0;
    *(float *)((char *)arg0 + 0x60) = 1.0f;
    *(float *)((char *)arg0 + 0x68) = 1.0f;
    *(float *)((char *)arg0 + 0x70) = 1.0f;
    *(float *)((char *)arg0 + 0x78) = 1.0f;
    *(float *)((char *)arg0 + 0x80) = 0.06f;
    *(float *)((char *)arg0 + 0x88) = 1.0f;
    *(float *)((char *)arg0 + 0x90) = 1.0f;
    *(float *)((char *)arg0 + 0x98) = 1.0f;
    *(int *)((char *)arg0 + 0x0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE2C8);
#ifdef SKIP_ASM
extern "C" void func_002BE2C8(void *p) {
    *(int*)((char*)p + 8) = 0;
    *(int*)((char*)p + 0x10) = 0;
    *(int*)((char*)p + 0) = 0;
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE2D8);
#ifdef SKIP_ASM
struct VE_E2D8 { short delta; short idx; int (*fn)(void *, void *, int); };
extern "C" void func_002BE2D8(char *self, char *s) {
    VE_E2D8 *e = &(*(VE_E2D8 **)s)[2];
    e->fn(s + e->delta, self + 8, 4);
    e = &(*(VE_E2D8 **)s)[2];
    e->fn(s + e->delta, self, 4);
    e = &(*(VE_E2D8 **)s)[2];
    e->fn(s + e->delta, self + 0x10, 4);
    e = &(*(VE_E2D8 **)s)[2];
    e->fn(s + e->delta, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE378);
#ifdef SKIP_ASM
extern "C" void func_002BE378(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE3E0);
#ifdef SKIP_ASM
extern "C" void func_002BE3E0(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE448);
#ifdef SKIP_ASM
extern "C" void func_002BE448(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE4B0);
#ifdef SKIP_ASM
extern "C" void func_002BE4B0(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE518);
#ifdef SKIP_ASM
struct VEnt_E518 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_E518 { char* vt; };

static inline void Wr_E518(Stream_E518* s, void* p, int n) {
    VEnt_E518* e = (VEnt_E518*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BE518(char* self, Stream_E518* s) {
    Wr_E518(s, self + 0x8, 4);
    Wr_E518(s, self, 4);
    Wr_E518(s, self + 0x10, 4);
    Wr_E518(s, self, 4);
    Wr_E518(s, self + 0x18, 4);
    Wr_E518(s, self, 4);
    Wr_E518(s, self + 0x20, 4);
    Wr_E518(s, self, 4);
    Wr_E518(s, self + 0x28, 4);
    Wr_E518(s, self, 4);
    Wr_E518(s, self + 0x30, 4);
    Wr_E518(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE698);
#ifdef SKIP_ASM
struct VEnt_E698 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_E698 { char* vt; };

static inline void Wr_E698(Stream_E698* s, void* p, int n) {
    VEnt_E698* e = (VEnt_E698*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BE698(char* self, Stream_E698* s) {
    Wr_E698(s, self + 0x8, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x10, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x18, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x20, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x28, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x30, 4);
    Wr_E698(s, self, 4);
    Wr_E698(s, self + 0x38, 4);
    Wr_E698(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE850);
#ifdef SKIP_ASM
struct VEnt_E850 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_E850 { char* vt; };

static inline void Wr_E850(Stream_E850* s, void* p, int n) {
    VEnt_E850* e = (VEnt_E850*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BE850(char* self, Stream_E850* s) {
    Wr_E850(s, self + 0x8, 4);
    Wr_E850(s, self, 4);
    Wr_E850(s, self + 0x10, 4);
    Wr_E850(s, self, 4);
    Wr_E850(s, self + 0x18, 4);
    Wr_E850(s, self, 4);
    Wr_E850(s, self + 0x20, 4);
    Wr_E850(s, self, 4);
    Wr_E850(s, self + 0x28, 4);
    Wr_E850(s, self, 4);
    Wr_E850(s, self + 0x30, 4);
    Wr_E850(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BE9D0);
#ifdef SKIP_ASM
extern "C" void func_002BE9D0(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BEA38);
#ifdef SKIP_ASM
struct VEnt_EA38 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_EA38 { char* vt; };

static inline void Wr_EA38(Stream_EA38* s, void* p, int n) {
    VEnt_EA38* e = (VEnt_EA38*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BEA38(char* self, Stream_EA38* s) {
    Wr_EA38(s, self + 0x8, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x10, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x18, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x20, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x28, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x30, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x38, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x40, 4);
    Wr_EA38(s, self, 4);
    Wr_EA38(s, self + 0x48, 4);
    Wr_EA38(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BEC60);
#ifdef SKIP_ASM
extern "C" void func_002BEC60(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x10))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0x14)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x10))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BECC8);
#ifdef SKIP_ASM
struct VEnt_ECC8 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_ECC8 { char* vt; };

static inline void Wr_ECC8(Stream_ECC8* s, void* p, int n) {
    VEnt_ECC8* e = (VEnt_ECC8*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BECC8(char* self, Stream_ECC8* s) {
    Wr_ECC8(s, self + 0x8, 8);
    Wr_ECC8(s, self, 4);
    Wr_ECC8(s, self + 0x18, 8);
    Wr_ECC8(s, self, 4);
    Wr_ECC8(s, self + 0x28, 8);
    Wr_ECC8(s, self, 4);
    Wr_ECC8(s, self + 0x38, 8);
    Wr_ECC8(s, self, 4);
    Wr_ECC8(s, self + 0x48, 4);
    Wr_ECC8(s, self, 4);
    Wr_ECC8(s, self + 0x50, 4);
    Wr_ECC8(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BEE48);
#ifdef SKIP_ASM
struct VEnt_EE48 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_EE48 { char* vt; };

static inline void Wr_EE48(Stream_EE48* s, void* p, int n) {
    VEnt_EE48* e = (VEnt_EE48*)(s->vt + 0x10);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BEE48(char* self, Stream_EE48* s) {
    Wr_EE48(s, self + 0x8, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x10, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x18, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x20, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x28, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x30, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x38, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x40, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x48, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x50, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x58, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x60, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x68, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x70, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x78, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x80, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x88, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x90, 4);
    Wr_EE48(s, self, 4);
    Wr_EE48(s, self + 0x98, 4);
    Wr_EE48(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF2A0);
#ifdef SKIP_ASM
struct VE_F2A0 { short delta; short idx; int (*fn)(void *, void *, int); };
extern "C" void func_002BF2A0(char *self, char *s) {
    VE_F2A0 *e = &(*(VE_F2A0 **)s)[2];
    e->fn(s + e->delta, self + 8, 4);
    e = &(*(VE_F2A0 **)s)[2];
    e->fn(s + e->delta, self, 4);
    e = &(*(VE_F2A0 **)s)[2];
    e->fn(s + e->delta, self + 0x10, 4);
    e = &(*(VE_F2A0 **)s)[2];
    e->fn(s + e->delta, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF340);
#ifdef SKIP_ASM
struct VE_F340 { short delta; short idx; int (*fn)(void *, void *, int); };
extern "C" void func_002BF340(char *self, char *s) {
    VE_F340 *e = &(*(VE_F340 **)s)[1];
    e->fn(s + e->delta, self + 8, 4);
    e = &(*(VE_F340 **)s)[1];
    e->fn(s + e->delta, self, 4);
    e = &(*(VE_F340 **)s)[1];
    e->fn(s + e->delta, self + 0x10, 4);
    e = &(*(VE_F340 **)s)[1];
    e->fn(s + e->delta, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF3E0);
#ifdef SKIP_ASM
extern "C" void func_002BF3E0(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF448);
#ifdef SKIP_ASM
extern "C" void func_002BF448(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF4B0);
#ifdef SKIP_ASM
extern "C" void func_002BF4B0(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF518);
#ifdef SKIP_ASM
extern "C" void func_002BF518(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF580);
#ifdef SKIP_ASM
struct VEnt_F580 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_F580 { char* vt; };

static inline void Wr_F580(Stream_F580* s, void* p, int n) {
    VEnt_F580* e = (VEnt_F580*)(s->vt + 0x8);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BF580(char* self, Stream_F580* s) {
    Wr_F580(s, self + 0x8, 4);
    Wr_F580(s, self, 4);
    Wr_F580(s, self + 0x10, 4);
    Wr_F580(s, self, 4);
    Wr_F580(s, self + 0x18, 4);
    Wr_F580(s, self, 4);
    Wr_F580(s, self + 0x20, 4);
    Wr_F580(s, self, 4);
    Wr_F580(s, self + 0x28, 4);
    Wr_F580(s, self, 4);
    Wr_F580(s, self + 0x30, 4);
    Wr_F580(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF700);
#ifdef SKIP_ASM
struct VEnt_F700 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_F700 { char* vt; };

static inline void Wr_F700(Stream_F700* s, void* p, int n) {
    VEnt_F700* e = (VEnt_F700*)(s->vt + 0x8);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BF700(char* self, Stream_F700* s) {
    Wr_F700(s, self + 0x8, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x10, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x18, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x20, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x28, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x30, 4);
    Wr_F700(s, self, 4);
    Wr_F700(s, self + 0x38, 4);
    Wr_F700(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BF8B8);
#ifdef SKIP_ASM
struct VEnt_F8B8 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_F8B8 { char* vt; };

static inline void Wr_F8B8(Stream_F8B8* s, void* p, int n) {
    VEnt_F8B8* e = (VEnt_F8B8*)(s->vt + 0x8);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BF8B8(char* self, Stream_F8B8* s) {
    Wr_F8B8(s, self + 0x8, 4);
    Wr_F8B8(s, self, 4);
    Wr_F8B8(s, self + 0x10, 4);
    Wr_F8B8(s, self, 4);
    Wr_F8B8(s, self + 0x18, 4);
    Wr_F8B8(s, self, 4);
    Wr_F8B8(s, self + 0x20, 4);
    Wr_F8B8(s, self, 4);
    Wr_F8B8(s, self + 0x28, 4);
    Wr_F8B8(s, self, 4);
    Wr_F8B8(s, self + 0x30, 4);
    Wr_F8B8(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BFA38);
#ifdef SKIP_ASM
extern "C" void func_002BFA38(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BFAA0);
#ifdef SKIP_ASM
struct VEnt_FAA0 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_FAA0 { char* vt; };

static inline void Wr_FAA0(Stream_FAA0* s, void* p, int n) {
    VEnt_FAA0* e = (VEnt_FAA0*)(s->vt + 0x8);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BFAA0(char* self, Stream_FAA0* s) {
    Wr_FAA0(s, self + 0x8, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x10, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x18, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x20, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x28, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x30, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x38, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x40, 4);
    Wr_FAA0(s, self, 4);
    Wr_FAA0(s, self + 0x48, 4);
    Wr_FAA0(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BFCC8);
#ifdef SKIP_ASM
extern "C" void func_002BFCC8(int arg0, void **arg1) {
    void *temp_3;
    void *temp_3_2;

    temp_3 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3) + (0x8))), arg0 + 8, 4);
    temp_3_2 = *arg1;
    (*(int (**)(void *, int, int))((char*)(temp_3_2) + (0xC)))((char*)arg1 + (*(short *)((char*)(temp_3_2) + (0x8))), arg0, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BFD30);
#ifdef SKIP_ASM
struct VEnt_FD30 { short delta; short idx; void (*fn)(void*, void*, int); };
struct Stream_FD30 { char* vt; };

static inline void Wr_FD30(Stream_FD30* s, void* p, int n) {
    VEnt_FD30* e = (VEnt_FD30*)(s->vt + 0x8);
    e->fn((char*)s + e->delta, p, n);
}

extern "C" void func_002BFD30(char* self, Stream_FD30* s) {
    Wr_FD30(s, self + 0x8, 8);
    Wr_FD30(s, self, 4);
    Wr_FD30(s, self + 0x18, 8);
    Wr_FD30(s, self, 4);
    Wr_FD30(s, self + 0x28, 8);
    Wr_FD30(s, self, 4);
    Wr_FD30(s, self + 0x38, 8);
    Wr_FD30(s, self, 4);
    Wr_FD30(s, self + 0x48, 4);
    Wr_FD30(s, self, 4);
    Wr_FD30(s, self + 0x50, 4);
    Wr_FD30(s, self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002BFEB0);
#ifdef SKIP_ASM
class cStream_FEB0 {
public:
    virtual int read(void* p, int n);
    virtual int write(void* p, int n);
};

// Reads 19 words into self (at +0x8 .. +0x98), each followed by one into +0x0
// (the read-side twin of func_002BEE48).
extern "C" void func_002BFEB0(char* self, cStream_FEB0* s)
{
    s->read(self + 0x8, 4);
    s->read(self, 4);
    s->read(self + 0x10, 4);
    s->read(self, 4);
    s->read(self + 0x18, 4);
    s->read(self, 4);
    s->read(self + 0x20, 4);
    s->read(self, 4);
    s->read(self + 0x28, 4);
    s->read(self, 4);
    s->read(self + 0x30, 4);
    s->read(self, 4);
    s->read(self + 0x38, 4);
    s->read(self, 4);
    s->read(self + 0x40, 4);
    s->read(self, 4);
    s->read(self + 0x48, 4);
    s->read(self, 4);
    s->read(self + 0x50, 4);
    s->read(self, 4);
    s->read(self + 0x58, 4);
    s->read(self, 4);
    s->read(self + 0x60, 4);
    s->read(self, 4);
    s->read(self + 0x68, 4);
    s->read(self, 4);
    s->read(self + 0x70, 4);
    s->read(self, 4);
    s->read(self + 0x78, 4);
    s->read(self, 4);
    s->read(self + 0x80, 4);
    s->read(self, 4);
    s->read(self + 0x88, 4);
    s->read(self, 4);
    s->read(self + 0x90, 4);
    s->read(self, 4);
    s->read(self + 0x98, 4);
    s->read(self, 4);
}
#endif

//100%
INCLUDE_ASM("bx/seg_1BA100", func_002C0308);
#ifdef SKIP_ASM
struct VE_0308 { short delta; short idx; int (*fn)(void *, void *, int); };
extern "C" void func_002C0308(char *self, char *s) {
    VE_0308 *e = &(*(VE_0308 **)s)[1];
    e->fn(s + e->delta, self + 8, 4);
    e = &(*(VE_0308 **)s)[1];
    e->fn(s + e->delta, self, 4);
    e = &(*(VE_0308 **)s)[1];
    e->fn(s + e->delta, self + 0x10, 4);
    e = &(*(VE_0308 **)s)[1];
    e->fn(s + e->delta, self, 4);
}
#endif
