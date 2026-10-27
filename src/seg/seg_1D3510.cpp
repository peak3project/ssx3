#include "common.h"

//100%
INCLUDE_ASM("seg/seg_1D3510", get_float);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int get_float_2510(unsigned char **pp, float *out) __asm__("get_float");
extern "C" int get_float_2510(unsigned char **pp, float *out) {
    unsigned char *p = *pp;
    union { unsigned int u; float f; } x;
    x.u = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
    *out = x.f;
    *pp += 4;
    return 4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", get_uint);
#ifdef SKIP_ASM
extern "C" int get_uint(unsigned char **pp, unsigned int *out) {
    unsigned char *p = *pp;
    *out = (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
    *pp += 4;
    return 4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", get_t3Vector);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct t3Vector_25A0 { float x, y, z; };
extern "C" int get_float_25A0(void*, void*) __asm__("get_float");
extern "C" int get_t3Vector(void *src, t3Vector_25A0 *out) {
    t3Vector_25A0 v;
    int total = 0;
    int i;
    float *p = &v.x;
    for (i = 0; i < 3; i++) {
        total += get_float_25A0(src, p);
        p++;
    }
    *out = v;
    return total;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1D3510", func_002D2628);
#ifdef SKIP_ASM
extern "C" int get_float(int, int);

extern "C" int func_002D2628(int arg0, int arg1) {
    int temp_2;
    int var_16;
    int var_17;
    int var_18;

    var_16 = arg1;
    var_17 = 3;
    var_18 = 0;
    do {
        temp_2 = get_float(arg0, var_16);
        var_16 += 4;
        var_17 -= 1;
        var_18 += temp_2;
    } while (var_17 >= 0);
    return var_18;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1D3510", func_002D2690);
#ifdef SKIP_ASM
extern "C" int get_float(int, int);

extern "C" int func_002D2690(int arg0, int arg1) {
    int temp_2;
    int var_16;
    int var_17;
    int var_18;

    var_16 = arg1;
    var_17 = 0xF;
    var_18 = 0;
    do {
        temp_2 = get_float(arg0, var_16);
        var_16 += 4;
        var_17 -= 1;
        var_18 += temp_2;
    } while (var_17 >= 0);
    return var_18;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D26F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V4_26F8 { float x, y, z, w; } __attribute__((aligned(16)));
extern "C" int get_float_26F8(void*, void*) __asm__("get_float");
extern "C" int func_002D26F8(void *src, V4_26F8 *out) {
    float a, b, c, d;
    V4_26F8 v;
    int total;
    total = get_float_26F8(src, &a);
    total += get_float_26F8(src, &b);
    total += get_float_26F8(src, &c);
    total += get_float_26F8(src, &d);
    v.w = a;
    v.x = b;
    v.y = c;
    v.z = d;
    *out = v;
    return total;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D2790);
#ifdef SKIP_ASM
extern "C" int func_002D2790(unsigned char **arg0, unsigned char *arg1) {
    *arg1 = **arg0;
    *arg0 += 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", get_string);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag_27B0(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" int func_002D2790_27B0(unsigned char **, unsigned char *) __asm__("func_002D2790");
extern "C" char *strcpy(char *, const char *);
extern char D_004D49B8[];
extern char D_00486768[];
extern "C" int get_string(unsigned char **src, char **out) {
    int n = 0;
    char c = 1;
    do {
        n += func_002D2790_27B0(src, (unsigned char*)&c);
        D_004D49B8[n - 1] = c;
    } while (c != 0 && n < 1000);
    if (n == 1000) D_004D49B8[999] = 0;
    char *p = (char*)operator_new_tag_27B0(n, D_00486768, 0x100, 0);
    *out = p;
    strcpy(p, D_004D49B8);
    return n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", get_data);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator_new_tag_2868(unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
extern "C" void* cMemMan_alloc_2868(int, const char*, int, int) __asm__("cMemMan_alloc");
extern "C" int func_002D2790_2868(unsigned char **, unsigned char *) __asm__("func_002D2790");
extern "C" int get_uint_2868(unsigned char **, void *) __asm__("get_uint");
extern char D_00486778[];
extern char D_00486788[];
struct Data_2868 { unsigned int n; unsigned char *data; };
extern "C" int get_data(unsigned char **src, Data_2868 **out) {
    unsigned int i = 0;
    Data_2868 *d = (Data_2868*)cMemMan_alloc_2868(8, D_00486778, 0x100, 0);
    d->n = 0;
    d->data = 0;
    *out = d;
    int total = get_uint_2868(src, d);
    Data_2868 *e = *out;
    e->data = (unsigned char*)operator_new_tag_2868(e->n, D_00486788, 0x100, 0);
    Data_2868 *t = *out;
    for (i = 0; i < t->n; i++) {
        total += func_002D2790_2868(src, t->data + i);
        t = *out;
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D2948);
#ifdef SKIP_ASM
extern "C" int func_002D2948(int self, ...) {
    return self;
}
#endif

INCLUDE_ASM("seg/seg_1D3510", func_002D2988);

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3788);
#ifdef SKIP_ASM
void operator_delete(int *);
extern void* D_004871E8[];
extern "C" void func_002D3788(void ***self, int flags) {
    *self = D_004871E8;
    if (flags & 1) operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D37B8);
#ifdef SKIP_ASM
extern "C" int func_002D37B8(void) {
    return 1;
}
#endif

extern "C" void func_002D37C0(void) {
}

extern "C" void func_002D37C8(void) {
}

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D37D0);
#ifdef SKIP_ASM
extern "C" int func_002D37D0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D37D8);
#ifdef SKIP_ASM
extern "C" int func_002D37D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D37E0);
#ifdef SKIP_ASM
struct VEnt_37E0 { short delta; short idx; int (*fn)(void*, int); };
extern "C" void func_002D37E0(void *arg0) {
    VEnt_37E0 *e = (VEnt_37E0*)(*(char **)arg0 + 0x180);
    e->fn((char*)arg0 + e->delta, *(int *)((char*)arg0 + 0xC));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3810);
#ifdef SKIP_ASM
struct VEnt_3810 { short delta; short idx; int (*fn)(void*, int); };
extern "C" void func_002D3810(void *arg0) {
    VEnt_3810 *e = (VEnt_3810*)(*(char **)arg0 + 0x1A0);
    e->fn((char*)arg0 + e->delta, *(int *)((char*)arg0 + 0xC));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3840);
#ifdef SKIP_ASM
struct Obj_3840 {
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
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
  virtual int v48();
  virtual void v49();
  virtual int v50(int);
  virtual void v51();
  virtual int v52(int);
  virtual void v53();
  virtual void v54();
  virtual void v55();
  virtual int v56(int);
};
extern "C" int func_002D3840(Obj_3840 *o, int x) {
    int ok = 0;
    if (!o->v48() && !o->v50(x) && o->v56(x)) {
        ok = o->v52(x) != 0;
    }
    return ok;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D38F0);
#ifdef SKIP_ASM
struct VEnt_38F0 { short delta; short idx; int (*fn)(void*, int); };
extern "C" void func_002D38F0(void *arg0) {
    VEnt_38F0 *e = (VEnt_38F0*)(*(char **)arg0 + 0x1C0);
    e->fn((char*)arg0 + e->delta, *(int *)((char*)arg0 + 0xC));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3920);
#ifdef SKIP_ASM
extern "C" int func_002D3920(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3928);
#ifdef SKIP_ASM
extern "C" int func_002D3928(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3930);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002C53C8_3930(void*, int) __asm__("func_002C53C8");
extern "C" void func_002D3930(void *arg0) {
    func_002C53C8_3930(arg0, (*(int *)((char*)(arg0) + (0xC))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3950);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002C53E0_3950(void*, int, int) __asm__("func_002C53E0");
extern "C" void func_002D3950(void *arg0, int arg1) {
    func_002C53E0_3950(arg0, (*(int *)((char*)(arg0) + (0xC))), arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3970);
#ifdef SKIP_ASM
extern "C" int func_002D3970(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3978);
#ifdef SKIP_ASM
extern "C" int func_002D3978(void) {
    return 2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3980);
#ifdef SKIP_ASM
struct VEnt_3980 { short delta; short idx; void (*fn)(void*, int, int, int); };
extern "C" void func_002D3980(void *arg0, int a1, int a2, int a3) {
    VEnt_3980 *e = (VEnt_3980*)(*(char **)arg0 + 0x230);
    e->fn((char*)arg0 + e->delta, a1, a2, a3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39A8);
#ifdef SKIP_ASM
extern "C" int func_002D39A8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39B0);
#ifdef SKIP_ASM
extern "C" int func_002D39B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3C)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002C51D0_39B8(void*, int) __asm__("func_002C51D0");
extern "C" void func_002D39B8(void *arg0) {
    func_002C51D0_39B8(arg0, (*(int *)((char*)(arg0) + (0xC))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39D8);
#ifdef SKIP_ASM
extern "C" int func_002D39D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

extern "C" void func_002D39E0(void) {
}

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39E8);
#ifdef SKIP_ASM
extern "C" int func_002D39E8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x54)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D39F0);
#ifdef SKIP_ASM
extern int D_004A3940;

extern "C" int func_002D39F0(void) {
    return D_004A3940;
}
#endif

extern "C" void func_002D39F8(void) {
}

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A00);
#ifdef SKIP_ASM
extern "C" void func_002D3A00(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (8))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A08);
#ifdef SKIP_ASM
extern "C" int func_002D3A08(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A10);
#ifdef SKIP_ASM
extern "C" void func_002D3A10(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xC))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A18);
#ifdef SKIP_ASM
extern "C" int func_002D3A18(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A20);
#ifdef SKIP_ASM
extern "C" int func_002D3A20(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A28);
#ifdef SKIP_ASM
extern "C" int func_002D3A28(char *arg0, int arg1) {
    return *(int *)(arg0 + (arg1 << 2) + 0xC);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A38);
#ifdef SKIP_ASM
extern "C" int func_002D3A38(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A40);
#ifdef SKIP_ASM
extern "C" int func_002D3A40(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x124)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A48);
#ifdef SKIP_ASM
extern "C" int func_002D3A48(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0x124)))) + (0x58)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A58);
#ifdef SKIP_ASM
extern "C" int func_002D3A58(void **arg0) {
    return (*(int *)((char*)((*(void **)((char*)(*arg0) + (0x124)))) + (0x58)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A68);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3A68(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A88);
#ifdef SKIP_ASM
extern "C" void func_002D3A88(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A90);
#ifdef SKIP_ASM
extern "C" void func_002D3A90(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3A98);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3A98(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3AB8);
#ifdef SKIP_ASM
extern "C" void func_002D3AB8(void *arg0, int arg1, int arg2) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
    (*(int *)((char*)(arg0) + (0x1C))) = arg2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3AC8);
#ifdef SKIP_ASM
extern "C" void func_002D3AC8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3AD0);
#ifdef SKIP_ASM
extern "C" void func_002D3AD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3AD8);
#ifdef SKIP_ASM
extern "C" int func_002D3AD8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3AE0);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3AE0(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B00);
#ifdef SKIP_ASM
extern "C" void func_002D3B00(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B08);
#ifdef SKIP_ASM
extern "C" int func_002D3B08(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B10);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3B10(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B30);
#ifdef SKIP_ASM
extern "C" void func_002D3B30(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B38);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3B38(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B58);
#ifdef SKIP_ASM
extern "C" void func_002D3B58(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B60);
#ifdef SKIP_ASM
extern "C" void func_002D3B60(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B68);
#ifdef SKIP_ASM
extern "C" int func_002D3B68(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B70);
#ifdef SKIP_ASM
extern "C" void func_002D3B70(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x20))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B78);
#ifdef SKIP_ASM
extern "C" int func_002D3B78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3B80);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3B80(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BA0);
#ifdef SKIP_ASM
extern "C" void func_002D3BA0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BA8);
#ifdef SKIP_ASM
extern "C" int func_002D3BA8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BB0);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3BB0(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BD0);
#ifdef SKIP_ASM
extern "C" void func_002D3BD0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BD8);
#ifdef SKIP_ASM
extern "C" void func_002D3BD8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3BE0);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3BE0(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C00);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3C00(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C20);
#ifdef SKIP_ASM
extern "C" void func_002D3C20(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C28);
#ifdef SKIP_ASM
extern "C" void func_002D3C28(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C30);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3C30(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C50);
#ifdef SKIP_ASM
extern "C" void func_002D3C50(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C58);
#ifdef SKIP_ASM
extern "C" void func_002D3C58(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C60);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3C60(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C80);
#ifdef SKIP_ASM
extern "C" void func_002D3C80(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C88);
#ifdef SKIP_ASM
extern "C" void func_002D3C88(void *arg0, float fparg0, float fparg1) {
    (*(float *)((char*)(arg0) + (0x1C))) = fparg0;
    (*(float *)((char*)(arg0) + (0x20))) = fparg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3C98);
#ifdef SKIP_ASM
extern "C" void func_002D3C98(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3CA0);
#ifdef SKIP_ASM
extern "C" void func_002D3CA0(void *arg0, float fparg0, float fparg1) {
    (*(float *)((char*)(arg0) + (0x24))) = fparg0;
    (*(float *)((char*)(arg0) + (0x28))) = fparg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3CB0);
#ifdef SKIP_ASM
extern "C" void func_002D3CB0(void *arg0, float fparg0) {
    *(*(float **)((char*)(arg0) + (0x18))) = fparg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3CC0);
#ifdef SKIP_ASM
extern "C" float func_002D3CC0(void *arg0) {
    return ((*(float *)((char*)(arg0) + (0x24))) * *(*(float **)((char*)(arg0) + (0x18)))) + (*(float *)((char*)(arg0) + (0x28)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3CE0);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3CE0(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D00);
#ifdef SKIP_ASM
extern "C" void func_002D3D00(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D08);
#ifdef SKIP_ASM
extern "C" void func_002D3D08(void *arg0, float fparg0, float fparg1) {
    (*(float *)((char*)(arg0) + (0x1C))) = fparg0;
    (*(float *)((char*)(arg0) + (0x20))) = fparg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D18);
#ifdef SKIP_ASM
extern "C" void func_002D3D18(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D20);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3D20(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D40);
#ifdef SKIP_ASM
extern "C" int func_002D3D40(int arg0) {
    return arg0 + 0x18;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00416958_3D48(char*, int, int) __asm__("func_00416958");
extern "C" int func_002D3D48(char *arg0, int arg1) {
    char *p = arg0 + 0x18;
    *p = 0;
    return func_00416958_3D48(p, arg1, 0xF);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D70);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3D70(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3D90);
#ifdef SKIP_ASM
extern "C" void func_002CAA80();

extern "C" void func_002D3D90(void) {
    func_002CAA80();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3DB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002CA280_3DB0(int, int) __asm__("func_002CA280");
extern "C" void func_002CAA80(int, int);

extern "C" void func_002D3DB0(int arg0, int arg1) {
    func_002CAA80(arg0 + 0x18, 2);
    func_002CA280_3DB0(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3DF8);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3DF8(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3E18);
#ifdef SKIP_ASM
extern "C" void func_002D3E18(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3E20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002CA280_3E20(int, int) __asm__("func_002CA280");
extern "C" void func_002CAA80(int, int);

extern "C" void func_002D3E20(int arg0, int arg1) {
    func_002CA280_3E20(arg0 + 0x640, 2);
    func_002CA280_3E20(arg0 + 0x61C, 2);
    func_002CA280_3E20(arg0 + 0x5F8, 2);
    func_002CA280_3E20(arg0 + 0x5D4, 2);
    func_002CA280_3E20(arg0 + 0x5B0, 2);
    func_002CAA80(arg0 + 0x18, 2);
    func_002CA280_3E20(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3EA0);
#ifdef SKIP_ASM
extern "C" void func_002D3EA0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x658))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3EA8);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3EA8(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3EC8);
#ifdef SKIP_ASM
extern "C" void func_002D3EC8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3ED0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002CA280_3ED0(int, int) __asm__("func_002CA280");
extern "C" void func_002CAA80(int, int);

extern "C" void func_002D3ED0(int arg0, int arg1) {
    func_002CA280_3ED0(arg0 + 0x654, 2);
    func_002CA280_3ED0(arg0 + 0x620, 2);
    func_002CA280_3ED0(arg0 + 0x5EC, 2);
    func_002CA280_3ED0(arg0 + 0x5B8, 2);
    func_002CAA80(arg0 + 0x18, 2);
    func_002CA280_3ED0(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3F48);
#ifdef SKIP_ASM
extern "C" void func_002D3F48(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x66C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3F50);
#ifdef SKIP_ASM
extern "C" void func_002CA280();

extern "C" void func_002D3F50(void) {
    func_002CA280();
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3F70);
#ifdef SKIP_ASM
extern "C" void func_002D3F70(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x14))) = arg1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3F78);
#ifdef SKIP_ASM
extern "C" void func_002CA280(int, int);
extern "C" void func_002CAA80(int, int);

extern "C" void func_002D3F78(int arg0, int arg1) {
    func_002CA280(arg0 + 0x164, 2);
    func_002CA280(arg0 + 0x14C, 2);
    func_002CA280(arg0 + 0x130, 2);
    func_002CAA80(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D3FD8);
#ifdef SKIP_ASM
void operator_delete(int *);
extern void* D_00487480[];
extern "C" void func_002D3FD8(char *self, int flags) {
    *(void***)(self + 0x34) = D_00487480;
    if (flags & 1) operator_delete((int*)self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D4008);
#ifdef SKIP_ASM
extern int (*D_004A54BC)(int, int);

extern "C" void func_002D4008(int *arg0, int *arg1) {
    D_004A54BC(*arg0, *arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D4030);
#ifdef SKIP_ASM
void operator_delete(int *);
extern void* D_00487480[];
extern "C" void func_002D4030(char *self, int flags) {
    *(void***)(self + 0x34) = D_00487480;
    if (flags & 1) operator_delete((int*)self);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1D3510", func_002D4060);
#ifdef SKIP_ASM
extern "C" void func_002D2988(int, int);

extern "C" void func_002D4060(void) {
    func_002D2988(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D4080);
#ifdef SKIP_ASM
extern "C" int func_002D4080(int self, ...) {
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1D3510", func_002D40C0);
#ifdef SKIP_ASM
extern float D_004D53F0[4];
extern float D_004D5400[4];
extern float D_004D5410[4];
extern float D_004D5420[4];
extern float D_004D5430[4];
extern float D_004D5440[4];
extern float D_004D5450[4];
extern float D_004D5460[4];
extern float D_004D5470[4];
extern float D_004D5480[4];
extern float D_004D5490[4];
extern float D_004D54A0[4];
extern float D_004D54B0[4];
extern float D_004D54C0[4];
extern float D_004D54D0[4];
extern float D_004D54E0[4];
extern float D_004D54F0[4];
extern float D_004D5500[4];
extern float D_004D5510[4];
extern float D_004D5520[4];
extern float D_004D5530[4];
extern float D_004D5540[4];
extern float D_004D5550[4];
extern float D_004D5560[4];
extern float D_004D5570[4];
extern float D_004D5580[4];
extern float D_004D5590[4];
extern float D_004D55A0[4];
extern float D_004D55B0[4];
extern float D_004D55C0[4];
extern float D_004D55D0[4];
extern float D_004D55E0[4];
extern float D_004D55F0[4];
extern float D_004D5600[4];
extern float D_004D5610[4];
extern float D_004D5620[4];
extern float D_004D5630[4];
extern float D_004D5640[4];
extern float D_004D5650[4];
extern float D_004D5660[4];
extern float D_004D5670[4];
extern float D_004D5680[4];
extern float D_004D5690[4];
extern float D_004D56A0[4];
extern float D_004D56B0[4];
extern float D_004D56C0[4];
extern float D_004D56D0[4];
extern float D_004D56E0[4];
extern float D_004D56F0[4];
extern float D_004D5700[4];
extern float D_004D5710[4];
extern float D_004D5720[4];
extern float D_004D5730[4];
extern float D_004D5740[4];
extern float D_004D5750[4];
extern float D_004D5760[4];
extern int D_004A54C0;
void sti_002D40C0(int init, int prio) __asm__("func_002D40C0");
void sti_002D40C0(int init, int prio)
{
    if (prio == 0xFFFF && init) {
        D_004D53F0[0] = 1.0f;
        D_004D53F0[1] = 1.0f;
        D_004D53F0[2] = 1.0f;
        D_004D53F0[3] = 0.5f;
        D_004D5400[0] = 0.4998680055141449f;
        D_004D5400[1] = 1.0f;
        D_004D5400[2] = 1.0f;
        D_004D5400[3] = 0.0f;
        D_004D5410[0] = 0.12951700389385223f;
        D_004D5410[1] = 1.0f;
        D_004D5410[2] = 1.0f;
        D_004D5410[3] = 0.0f;
        D_004D5420[0] = 0.22426900267601013f;
        D_004D5420[1] = 0.9402310252189636f;
        D_004D5420[2] = 0.5425059795379639f;
        D_004D5420[3] = 0.0004030000127386302f;
        D_004D5430[0] = 0.4652079939842224f;
        D_004D5430[1] = 0.32170501351356506f;
        D_004D5430[2] = 0.9943439960479736f;
        D_004D5430[3] = 0.0f;
        D_004D5440[0] = 0.17792600393295288f;
        D_004D5440[1] = 1.0f;
        D_004D5440[2] = 1.0f;
        D_004D5440[3] = 0.0f;
        D_004D5450[0] = 0.4411740005016327f;
        D_004D5450[1] = 0.41388601064682007f;
        D_004D5450[2] = 0.3211260139942169f;
        D_004D5450[3] = 0.4398239850997925f;
        D_004D5460[0] = 0.500997006893158f;
        D_004D5460[1] = 0.24849599599838257f;
        D_004D5460[2] = 1.0f;
        D_004D5460[3] = 1.0f;
        D_004D5470[0] = 0.27687299251556396f;
        D_004D5470[1] = 0.6395620107650757f;
        D_004D5470[2] = 0.13423900306224823f;
        D_004D5470[3] = 0.0f;
        D_004D5480[0] = 0.8936439752578735f;
        D_004D5480[1] = 0.5263469815254211f;
        D_004D5480[2] = 0.5051450133323669f;
        D_004D5480[3] = 0.8687300086021423f;
        D_004D5490[0] = 1.0f;
        D_004D5490[1] = 1.0f;
        D_004D5490[2] = 1.0f;
        D_004D5490[3] = 1.0f;
        D_004D54A0[0] = 1.0f;
        D_004D54A0[1] = 0.0f;
        D_004D54A0[2] = 0.0f;
        D_004D54A0[3] = 0.0f;
        D_004D54B0[0] = 1.0f;
        D_004D54B0[1] = 0.550000011920929f;
        D_004D54B0[2] = 0.5350000262260437f;
        D_004D54B0[3] = 0.550000011920929f;
        D_004D54C0[0] = 1.0f;
        D_004D54C0[1] = 1.0f;
        D_004D54C0[2] = 1.0f;
        D_004D54C0[3] = 1.0f;
        D_004D54D0[0] = 1.0f;
        D_004D54D0[1] = 1.0f;
        D_004D54D0[2] = 1.0f;
        D_004D54D0[3] = 1.0f;
        D_004D54E0[0] = 1.0f;
        D_004D54E0[1] = 0.0f;
        D_004D54E0[2] = 0.0f;
        D_004D54E0[3] = 0.0f;
        D_004D54F0[0] = 1.0f;
        D_004D54F0[1] = 0.0f;
        D_004D54F0[2] = 0.0f;
        D_004D54F0[3] = 0.0f;
        D_004D5500[0] = 1.0f;
        D_004D5500[1] = 1.0f;
        D_004D5500[2] = 1.0f;
        D_004D5500[3] = 1.0f;
        D_004D5510[0] = 1.0f;
        D_004D5510[1] = 0.5f;
        D_004D5510[2] = 1.0f;
        D_004D5510[3] = 0.5f;
        D_004D5520[0] = 1.0f;
        D_004D5520[1] = 0.5f;
        D_004D5520[2] = 1.0f;
        D_004D5520[3] = 0.5f;
        D_004D5530[0] = 1.0f;
        D_004D5530[1] = 0.5f;
        D_004D5530[2] = 1.0f;
        D_004D5530[3] = 0.5f;
        D_004D5540[0] = 1.0f;
        D_004D5540[1] = 0.7828119993209839f;
        D_004D5540[2] = 0.06171900033950806f;
        D_004D5540[3] = 0.03984399884939194f;
        D_004D5550[0] = 1.0f;
        D_004D5550[1] = 1.0f;
        D_004D5550[2] = 0.7988259792327881f;
        D_004D5550[3] = 0.0f;
        D_004D5560[0] = 0.9886710047721863f;
        D_004D5560[1] = 0.9230499863624573f;
        D_004D5560[2] = 0.34311699867248535f;
        D_004D5560[3] = 0.0f;
        D_004D5570[0] = 1.0f;
        D_004D5570[1] = 1.0f;
        D_004D5570[2] = 1.0f;
        D_004D5570[3] = 1.0f;
        D_004D5580[0] = 1.0f;
        D_004D5580[1] = 1.0f;
        D_004D5580[2] = 0.7976430058479309f;
        D_004D5580[3] = 0.0f;
        D_004D5590[0] = 1.0f;
        D_004D5590[1] = 0.9222670197486877f;
        D_004D5590[2] = 0.34179699420928955f;
        D_004D5590[3] = 0.0f;
        D_004D55A0[0] = 1.0f;
        D_004D55A0[1] = 0.7847639918327332f;
        D_004D55A0[2] = 0.06054700165987015f;
        D_004D55A0[3] = 0.04062499850988388f;
        D_004D55B0[0] = 1.0f;
        D_004D55B0[1] = 0.800000011920929f;
        D_004D55B0[2] = 0.44999998807907104f;
        D_004D55B0[3] = 1.0f;
        D_004D55C0[0] = 1.0f;
        D_004D55C0[1] = 0.3281260132789612f;
        D_004D55C0[2] = 1.0f;
        D_004D55C0[3] = 0.3539060056209564f;
        D_004D55D0[0] = 1.0f;
        D_004D55D0[1] = 1.0f;
        D_004D55D0[2] = 1.0f;
        D_004D55D0[3] = 1.0f;
        D_004D55E0[0] = 1.0f;
        D_004D55E0[1] = 1.0f;
        D_004D55E0[2] = 1.0f;
        D_004D55E0[3] = 1.0f;
        D_004D55F0[0] = 1.0f;
        D_004D55F0[1] = 0.8613290190696716f;
        D_004D55F0[2] = 0.38124799728393555f;
        D_004D55F0[3] = 0.0f;
        D_004D5600[0] = 1.0f;
        D_004D5600[1] = 1.0f;
        D_004D5600[2] = 1.0f;
        D_004D5600[3] = 1.0f;
        D_004D5610[0] = 1.0f;
        D_004D5610[1] = 0.3244380056858063f;
        D_004D5610[2] = 1.0f;
        D_004D5610[3] = 0.0f;
        D_004D5620[0] = 1.0f;
        D_004D5620[1] = 1.0f;
        D_004D5620[2] = 1.0f;
        D_004D5620[3] = 1.0f;
        D_004D5630[0] = 1.0f;
        D_004D5630[1] = 1.0f;
        D_004D5630[2] = 0.0f;
        D_004D5630[3] = 0.0f;
        D_004D5640[0] = 0.7007060050964355f;
        D_004D5640[1] = 0.0f;
        D_004D5640[2] = 0.0f;
        D_004D5640[3] = 0.0f;
        D_004D5650[0] = 1.0f;
        D_004D5650[1] = 0.7828530073165894f;
        D_004D5650[2] = 0.06140600144863129f;
        D_004D5650[3] = 0.04146299883723259f;
        D_004D5660[0] = 1.0f;
        D_004D5660[1] = 0.32487601041793823f;
        D_004D5660[2] = 1.0f;
        D_004D5660[3] = 0.35280099511146545f;
        D_004D5670[0] = 1.0f;
        D_004D5670[1] = 1.0f;
        D_004D5670[2] = 0.7977359890937805f;
        D_004D5670[3] = 0.0f;
        D_004D5680[0] = 1.0f;
        D_004D5680[1] = 0.4937489926815033f;
        D_004D5680[2] = 1.0f;
        D_004D5680[3] = 0.49179700016975403f;
        D_004D5690[0] = 1.0f;
        D_004D5690[1] = 1.0f;
        D_004D5690[2] = 1.0f;
        D_004D5690[3] = 1.0f;
        D_004D56A0[0] = 1.0f;
        D_004D56A0[1] = 0.800000011920929f;
        D_004D56A0[2] = 1.0f;
        D_004D56A0[3] = 0.800000011920929f;
        D_004D56B0[0] = 1.0f;
        D_004D56B0[1] = 1.0f;
        D_004D56B0[2] = 0.0f;
        D_004D56B0[3] = 0.0f;
        D_004D56C0[0] = 1.0f;
        D_004D56C0[1] = 1.0f;
        D_004D56C0[2] = 0.0f;
        D_004D56C0[3] = 0.0f;
        D_004D56D0[0] = 1.0f;
        D_004D56D0[1] = 1.0f;
        D_004D56D0[2] = 0.0f;
        D_004D56D0[3] = 0.0f;
        D_004D56E0[0] = 1.0f;
        D_004D56E0[1] = 0.3273420035839081f;
        D_004D56E0[2] = 1.0f;
        D_004D56E0[3] = 0.35390499234199524f;
        D_004D56F0[0] = 1.0f;
        D_004D56F0[1] = 1.0f;
        D_004D56F0[2] = 0.061000000685453415f;
        D_004D56F0[3] = 0.039000000804662704f;
        D_004D5700[0] = 1.0f;
        D_004D5700[1] = 1.0f;
        D_004D5700[2] = 0.7999979853630066f;
        D_004D5700[3] = 0.0f;
        D_004D5710[0] = 1.0f;
        D_004D5710[1] = 0.9589840173721313f;
        D_004D5710[2] = 0.6143789887428284f;
        D_004D5710[3] = 0.0f;
        D_004D5720[0] = 1.0f;
        D_004D5720[1] = 0.9285150170326233f;
        D_004D5720[2] = 0.3399839997291565f;
        D_004D5720[3] = 0.0f;
        D_004D5730[0] = 1.0f;
        D_004D5730[1] = 0.8738250136375427f;
        D_004D5730[2] = 0.24931700527668f;
        D_004D5730[3] = 0.017578000202775f;
        D_004D5740[0] = 1.0f;
        D_004D5740[1] = 0.7843739986419678f;
        D_004D5740[2] = 0.06132800132036209f;
        D_004D5740[3] = 0.03945299983024597f;
        D_004D5750[0] = 1.0f;
        D_004D5750[1] = 0.0f;
        D_004D5750[2] = 1.0f;
        D_004D5750[3] = 0.0f;
        D_004D5760[0] = 1.0f;
        D_004D5760[1] = 1.0f;
        D_004D5760[2] = 0.0f;
        D_004D5760[3] = 0.0f;
        *(char*)&D_004A54C0 = -1;
        D_004A54C0 = (D_004A54C0 & 0xFF) | 0xFFFFFF00u;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_1D3510", func_002D48D0);
#ifdef SKIP_ASM
extern "C" void func_002D40C0(int, int);

extern "C" void func_002D48D0(void) {
    func_002D40C0(1, 0xFFFF);
}
#endif
