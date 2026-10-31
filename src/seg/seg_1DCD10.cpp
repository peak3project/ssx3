#include "common.h"

INCLUDE_ASM("seg/seg_1DCD10", func_002DBD10);

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBEE0);
#ifdef SKIP_ASM
struct Pre_BEE0 { char pad[0x10D8]; };
class Mgr_BEE0 : Pre_BEE0 {
public:
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
  virtual void v48();
  virtual void v48b();
  virtual void v50(int);
};
extern Mgr_BEE0 *D_004A5B80;
void operator_delete(int *);
extern "C" void func_002DBEE0(int *self, int flags) {
    Mgr_BEE0 *m = D_004A5B80;
    int i;
    for (i = 0; i < 0x51; i++) {
        int *slot = (int*)((char*)m + 0xF50) + i;
        if (*slot != -1) {
            m->v50(*slot);
            *slot = -1;
        }
    }
    if (flags & 1) operator_delete(self);
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBF80);
#ifdef SKIP_ASM
extern char D_00488308[];
extern "C" void *func_002DBF80(int *self) {
    self[0] = 0;
    *(char**)((char*)self + 4) = D_00488308;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DBF98);
#ifdef SKIP_ASM
extern "C" int func_00418EF8(void* base, int n, int size, int (*cmp)(void*, void*));
extern "C" int func_002DC168(void* arg0, void* arg1);
struct RS_BF98 {
    unsigned int w0_lo : 2;
    unsigned int a : 2;
    unsigned int w0_hi : 28;
    unsigned int b : 2;
    unsigned int c : 5;
    unsigned int w1_p7 : 5;
    unsigned int d : 8;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 2;
    unsigned int w1_hi : 7;
    unsigned int w2_lo : 5;
    unsigned int h : 5;
    unsigned int i : 19;
    unsigned int w2_hi : 3;
    int w3;
    int w4;
};
struct Ctx_BF98 { char pad[0xE84]; RS_BF98* top; char pad2[0xF60 - 0xE88]; int f60; };
extern Ctx_BF98* D_004A289C;
extern char D_00537AC0[];
struct VEnt_BF98 { short delta; short idx; void (*fn)(void*); };
struct Obj_BF98 { int n; char* vt; };

static inline void Push_BF98() {
    Ctx_BF98* ctx = D_004A289C;
    ctx->top[1] = ctx->top[0];
    ctx->top++;
}
static inline void Pop_BF98() {
    D_004A289C->top--;
}
static inline void G3_BF98(int c, int f, int g, int e, int d) {
    Ctx_BF98* ctx = D_004A289C;
    ctx->top->c = c;
    ctx->top->f = f;
    ctx->top->g = g;
    ctx->top->e = e;
    ctx->top->d = d;
}

extern "C" void func_002DBF98(Obj_BF98* self) {
    if (self->n) {
        func_00418EF8(D_00537AC0, self->n, 8, func_002DC168);
        Push_BF98();
        {
            Ctx_BF98* ctx = D_004A289C;
            int v = ctx->f60;
            ctx->top->h = 7;
            ctx->top->b = 2;
            ctx->top->i = 0x3FF;
            *(short*)((char*)ctx->top + 0x10) = v;
        }
        {
            Ctx_BF98* ctx = D_004A289C;
            ctx->top->a = 3;
            *(short*)((char*)ctx->top + 0x12) = -1;
        }
        G3_BF98(5, 1, 0, 3, 0);
        {
            VEnt_BF98* e = (VEnt_BF98*)(self->vt + 0x18);
            e->fn((char*)self + e->delta);
        }
        Pop_BF98();
        self->n = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_1DCD10", func_002DC168);
#ifdef SKIP_ASM
extern "C" int func_002DC168(void *arg0, void *arg1) {
    int temp_3;
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (4)));
    temp_3 = (*(int *)((char*)(arg1) + (4)));
    if (temp_4 >= temp_3) {
        return (temp_3 >= temp_4) ? 0 : -1;
    }
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_1DCD10", func_002DC190);

INCLUDE_ASM("seg/seg_1DCD10", func_002DC7B0);
