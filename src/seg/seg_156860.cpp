#include "common.h"

//100%
INCLUDE_ASM("seg/seg_156860", cCommSystem_construct);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_004A2EB8;
extern "C" int cCommSystem_cCommSystem_5860(int) __asm__("cCommSystem_cCommSystem");
extern "C" int cMemMan_alloc_5860(unsigned int, void *, unsigned int, int) __asm__("cMemMan_alloc");
extern char D_00480300[];

extern "C" void cCommSystem_construct(void) {
    D_004A2EB8 = cCommSystem_cCommSystem_5860(cMemMan_alloc_5860(0x34, D_00480300, 0x20000000, 0));
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255898);
#ifdef SKIP_ASM
extern "C" void cCommSystem__cCommSystem(int, int);
extern int D_004A2EB8;

extern "C" void func_00255898(void) {
    if (D_004A2EB8 != 0) {
        cCommSystem__cCommSystem(D_004A2EB8, 3);
        D_004A2EB8 = 0;
    }
}
#endif

INCLUDE_ASM("seg/seg_156860", cCommSystem_cCommSystem);

//100%
INCLUDE_ASM("seg/seg_156860", cCommSystem__cCommSystem);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E56E0(void *);
extern "C" void cMemMan_free__FPv_59B0(void *) __asm__("cMemMan_free__FPv");
extern "C" void operator_delete__FPi_59B0(void *) __asm__("operator_delete__FPi");

extern "C" void cCommSystem__cCommSystem_59B0(void *self, int flags) __asm__("cCommSystem__cCommSystem");
extern "C" void cCommSystem__cCommSystem_59B0(void *self, int flags) {
    func_003E56E0((char*)self + 4);
    void *p = *(void **)((char*)self + 0x14);
    if (p != 0) {
        cMemMan_free__FPv_59B0(p);
    }
    *(int *)((char*)self + 0x14) = 0;
    *(int *)((char*)self + 0x18) = 0;
    if (flags & 1) {
        operator_delete__FPi_59B0(self);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", cCommSystem_getSignature);
#ifdef SKIP_ASM
extern char D_00481370[];

extern "C" char *cCommSystem_getSignature(void) {
    return D_00481370;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255A20);
#ifdef SKIP_ASM
extern "C" void func_003F42A0(void);
extern "C" int func_003F3CC0_5A20(int sel, int a, int b) __asm__("func_003F3CC0");
extern "C" int func_003F3C50(void* params, int a);
extern "C" void func_00255FE8(void* self, int reason);
extern "C" void func_00256038(void* self, int* out);
extern char D_00536810[];

struct sCommVE_5A20 {
    short delta;
    short index;
    void (*fn)(void*);
};

struct sCommObj_5A20 {
    char pad0[8];
    sCommVE_5A20* vt;   // 0x8
};

struct sComm_5A20 {
    sCommObj_5A20* objs[1];   // 0x0
    char pad4[0x1C - 4];
    int index;                // 0x1C
    int state;                // 0x20
    int timer;                // 0x24
    char pad28[4];
    int bband;                // 0x2C
    int type;                 // 0x30
};

extern "C" void func_00255A20(sComm_5A20* self)
{
    int i;
    func_003F42A0();
    switch (self->state) {
    case 0:
    case 1:
    case 6:
        break;
    case 2:
        if (func_003F3CC0_5A20(0x6F6E6C6E, 0, 0) == 0) {
            func_003F3C50(D_00536810 + (self->index << 8), 0);
            self->state = 3;
        }
        break;
    case 3: {
        if (func_003F3CC0_5A20(0x6F6E6C6E, 0, 0) != 0 && func_003F3CC0_5A20(0x686F7374, 0, 0) != 0) {
            self->state = 4;
            self->timer = 0x708;
            self->type = func_003F3CC0_5A20(0x74797065, 0, 0);
            int bb = func_003F3CC0_5A20(0x62626E64, 0, 0);
            if (bb == 1) {
                self->bband = bb;
            }
        }
        int conn = func_003F3CC0_5A20(0x636F6E6E, 0, 0);
        if ((conn >> 24) == '-') {
            func_00255FE8(self, conn);
            self->timer = 0;
        }
        break;
    }
    case 4: {
        int addr;
        func_00256038(self, &addr);
        if (addr != 0) {
            self->timer = 0;
            self->state = 5;
        }
        break;
    }
    case 5:
        for (i = 0; i < 1; i++) {
            sCommObj_5A20* o = self->objs[i];
            if (o != 0) {
                o->vt[3].fn((char*)o + o->vt[3].delta);
            }
        }
        break;
    }
    if (self->timer > 0) {
        self->timer--;
        if (self->timer <= 0) {
            func_00255FE8(self, 0x74696D65);
            self->timer = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", cCommSystem_openDSockChannel);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *cMemMan_alloc_5BF8(int, char *, int, int) __asm__("cMemMan_alloc");
extern "C" void *func_00256698_5BF8(void *) __asm__("func_00256698");
extern "C" void func_00256860_5BF8(void *, int, int) __asm__("func_00256860");
extern "C" void func_002568F8_5BF8(void *, int, int) __asm__("func_002568F8");
extern char D_00480350[];

extern "C" int cCommSystem_openDSockChannel(void **slots, int a1, int a2, int a3) {
    int i;
    int n = a2 & 0xFFFF;
    for (i = 0; i < 1; i++) {
        if (slots[i] == 0) {
            void *obj = func_00256698_5BF8(cMemMan_alloc_5BF8(0x20, D_00480350, 0x20000000, 0));
            if (a3 != 0) {
                func_002568F8_5BF8(obj, a1, n);
            } else {
                func_00256860_5BF8(obj, a1, n);
            }
            slots[i] = obj;
            return i;
        }
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255CC8);
#ifdef SKIP_ASM
extern "C" void func_00255CC8(char *arg0, int arg1) {
    void **slot = (void **)(arg0 + arg1 * 4);
    char *a = (char *)*slot;
    if (*(int *)a != 0) {
        char *vt = *(char **)(a + 8);
        void (*fn)(void *) = *(void (**)(void *))(vt + 0x14);
        fn(a + *(short *)(vt + 0x10));
    }
    char *b = (char *)*slot;
    if (b != 0) {
        char *vt = *(char **)(b + 8);
        void (*fn)(void *, int) = *(void (**)(void *, int))(vt + 0xC);
        fn(b + *(short *)(vt + 8), 3);
    }
    *slot = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255D38);
#ifdef SKIP_ASM
extern "C" int func_00255D38(void *arg0, int arg1) {
    return *(int *)((char*)arg0 + (arg1 << 2)) != 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255D50);
#ifdef SKIP_ASM
extern "C" int func_00255D50(void *arg0, int arg1) {
    char *obj = *(char **)((char*)arg0 + (arg1 << 2));
    char *vt = *(char **)(obj + 8);
    return (*(int (**)(void *))(vt + 0x24))(obj + *(short *)(vt + 0x20));
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255D88);
#ifdef SKIP_ASM
extern "C" float func_00255D88(int arg0, int arg1) {
    char *obj = *(char **)(arg0 + (arg1 << 2));
    char *vt = *(char **)(obj + 8);
    return (*(float (**)(void *))(vt + 0x2C))(obj + *(short *)(vt + 0x28));
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255DC0);
#ifdef SKIP_ASM
extern "C" int func_00255DC0(void *arg0, int arg1, int arg2, int arg3) {
    char *obj = *(char **)((char*)arg0 + (arg1 << 2));
    char *vt = *(char **)(obj + 8);
    return (*(int (**)(void *, int, int))(vt + 0x3C))(obj + *(short *)(vt + 0x38), arg2, arg3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255E00);
#ifdef SKIP_ASM
extern "C" int func_00255E00(void *arg0, int arg1, int arg2, int arg3) {
    char *obj = *(char **)((char*)arg0 + (arg1 << 2));
    char *vt = *(char **)(obj + 8);
    return (*(int (**)(void *, int, int))(vt + 0x44))(obj + *(short *)(vt + 0x40), arg2, arg3);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255E40);
#ifdef SKIP_ASM
extern "C" int func_00255E40(void *arg0, int arg1) {
    if ((*(int *)((char*)(arg0) + (0x28))) != 0) {
        return 1;
    }
    return *(int *)((char*)(*(void **)((char*)arg0 + (arg1 << 2))) + 4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255E68);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void *);
extern "C" void MUTEX_unlock(void *);

extern "C" int *func_00255E68(void *arg0) {
    void *m = (char*)arg0 + 4;
    MUTEX_lock(m);
    int *r = *(int **)((char*)arg0 + 0x18);
    *(int **)((char*)arg0 + 0x18) = (int *)*r;
    MUTEX_unlock(m);
    *r = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255EC0);
#ifdef SKIP_ASM
extern "C" void MUTEX_lock(void *);
extern "C" void MUTEX_unlock(void *);

extern "C" void func_00255EC0(void *arg0, void *arg1) {
    void *m = (char*)arg0 + 4;
    MUTEX_lock(m);
    void *head = *(void **)((char*)arg0 + 0x18);
    *(int *)((char*)arg1 + 4) = 0;
    *(void **)((char*)arg1 + 0) = head;
    *(int *)((char*)arg1 + 8) = 0;
    *(void **)((char*)arg0 + 0x18) = arg1;
    MUTEX_unlock(m);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255F20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003F3BC8_5F20(int, void *, int) __asm__("func_003F3BC8");
extern char D_00536790[];
extern int D_004A2EBC;

extern "C" int func_00255F20(void *arg0, int arg1) {
    D_004A2EBC = func_003F3BC8_5F20(arg1, D_00536790, 0xA);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255F50);
#ifdef SKIP_ASM
extern "C" void func_00255FA0(void *);

extern "C" void func_00255F50(void *arg0, int arg1) {
    func_00255FA0(arg0);
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
    (*(int *)((char*)(arg0) + (0x30))) = 1;
    (*(int *)((char*)(arg0) + (0x24))) = 0x2328;
    (*(int *)((char*)(arg0) + (0x20))) = 2;
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255FA0);
#ifdef SKIP_ASM
extern "C" int func_003F40B8();

extern "C" void func_00255FA0(void *arg0) {
    if ((*(int *)((char*)(arg0) + (0x1C))) >= 0) {
        (*(int *)((char*)(arg0) + (0x1C))) = -1;
        func_003F40B8();
    }
    (*(int *)((char*)(arg0) + (0x24))) = 0;
    (*(int *)((char*)(arg0) + (0x20))) = 1;
    (*(int *)((char*)(arg0) + (0x28))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00255FE8);
#ifdef SKIP_ASM
extern "C" int func_003F40B8();

extern "C" void func_00255FE8(void *arg0, int arg1) {
    if ((*(int *)((char*)(arg0) + (0x1C))) >= 0) {
        (*(int *)((char*)(arg0) + (0x1C))) = -1;
        func_003F40B8();
    }
    (*(int *)((char*)(arg0) + (0x28))) = arg1;
    (*(int *)((char*)(arg0) + (0x20))) = 6;
    (*(int *)((char*)(arg0) + (0x24))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256038);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003F3CC0_6038(int, int, int) __asm__("func_003F3CC0");

extern "C" void func_00256038(void *arg0, int *arg1) {
    int temp_2;

    *arg1 = 0;
    temp_2 = func_003F3CC0_6038(0x61646472, 0, 0);
    if (temp_2 & 0xFFFFFF00) {
        *arg1 = temp_2;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256088);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0031B008_6088(void *, int, void *) __asm__("func_0031B008");
extern char D_00480378[];
extern int D_004A2EC0;

extern "C" void func_00256088(void) {
    func_0031B008_6088(D_00480378, 1, &D_004A2EC0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002560B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *cMemMan_alloc_60B0(int, char *, int, int) __asm__("cMemMan_alloc");
extern "C" int *func_002561B8_60B0(void *) __asm__("func_002561B8");
extern "C" void func_002561E0_60B0(int *, int) __asm__("func_002561E0");
extern "C" void func_00256258_60B0(int *, int) __asm__("func_00256258");
extern "C" void func_002562D0_60B0(int *) __asm__("func_002562D0");
extern "C" void func_002563A8_60B0(int *) __asm__("func_002563A8");
extern "C" void func_002563F8_60B0(int *) __asm__("func_002563F8");
extern "C" int SYNCTASK_run(int);
extern "C" void THREAD_yieldticks_60B0(int) __asm__("THREAD_yieldticks");
extern char D_004A2EC8[];

static inline int ge3_60B0(int *o) { return *o >= 3; }

extern "C" void func_002560B0(void) {
    int *o = func_002561B8_60B0(cMemMan_alloc_60B0(0xA50, D_004A2EC8, 0x20000000, 0));
    func_00256258_60B0(o, 0);
    while (!ge3_60B0(o)) {
        func_002563F8_60B0(o);
        SYNCTASK_run(0);
        THREAD_yieldticks_60B0(1);
    }
    func_002562D0_60B0(o);
    while ((*o ^ 5) != 0) {
        func_002563F8_60B0(o);
        SYNCTASK_run(0);
        THREAD_yieldticks_60B0(1);
    }
    func_002563A8_60B0(o);
    if (o != 0) {
        func_002561E0_60B0(o, 3);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256188);
#ifdef SKIP_ASM
extern "C" int func_003DED50(void *, int, int, void *);
extern char D_004803D0[];
extern int D_004A2ED4;

extern "C" void func_00256188(void) {
    func_003DED50(D_004803D0, 0, 0x64, &D_004A2ED4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002561B8);
#ifdef SKIP_ASM
extern "C" void func_00256228(void *arg0);

extern "C" void *func_002561B8(void *arg0) {
    func_00256228(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002561E0);
#ifdef SKIP_ASM
extern "C" void func_00256250(int *);
extern "C" void operator_delete__FPi(int *);

extern "C" void func_002561E0(int *arg0, int arg1) {
    func_00256250(arg0);
    if (arg1 & 1) {
        operator_delete__FPi(arg0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256228);
#ifdef SKIP_ASM
extern "C" void func_00256228(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(int *)((char*)(arg0) + (0x18))) = -1;
    (*(int *)((char*)(arg0) + (0))) = 0;
}
#endif

extern "C" void func_00256250(int * a0) {
}

//100%
INCLUDE_ASM("seg/seg_156860", func_00256258);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003DF748(int *, int, int);
extern int D_004803E8[];
extern int D_004A2EE0[];
extern "C" void *operator_new__FUi_6258(unsigned int, int *, int, int) __asm__("operator_new__FUi");

extern "C" void func_00256258(char *self, int arg1) {
    *(int *)(self + 0x20) = arg1;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0x1C) = 0;
    *(int *)(self + 0) = 1;
    void *mem = operator_new__FUi_6258(0x195000, D_004A2EE0, 0x04000100, 0);
    *(void **)(self + 4) = mem;
    *(int *)(self + 0x18) = func_003DF748(D_004803E8, (int)mem, 0x195000);
}
#endif

INCLUDE_ASM("seg/seg_156860", func_002562D0);

//100%
INCLUDE_ASM("seg/seg_156860", func_002563A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void cMemMan_free__FPv_63A8(int) __asm__("cMemMan_free__FPv");

extern "C" void func_002563A8(void *arg0) {
    int temp_4;
    int temp_4_2;

    temp_4 = (*(int *)((char*)(arg0) + (0xC)));
    if (temp_4 != 0) {
        cMemMan_free__FPv_63A8(temp_4);
        (*(int *)((char*)(arg0) + (0xC))) = 0;
    }
    temp_4_2 = (*(int *)((char*)(arg0) + (4)));
    if (temp_4_2 != 0) {
        cMemMan_free__FPv_63A8(temp_4_2);
        (*(int *)((char*)(arg0) + (4))) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002563F8);
#ifdef SKIP_ASM
extern "C" void func_00256460(char* self);
extern "C" void func_00256510(char* self);
extern "C" void func_002565E0(char* self);

extern "C" void func_002563F8(char* self)
{
    switch (*(int*)self) {
    case 1:
        func_00256460(self);
        break;
    case 2:
        func_00256510(self);
        break;
    case 4:
        func_002565E0(self);
        break;
    case 0:
    case 3:
    case 5:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256460);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003DF980_6460(int) __asm__("func_003DF980");
extern "C" int ASYNCFILE_release(int, int, void *);
extern "C" int func_003FCFD8_6460(int, int) __asm__("func_003FCFD8");
extern "C" void *operator_new__FUi_6460(unsigned int, char *, int, int) __asm__("operator_new__FUi");
extern "C" int func_003DF748_6460(char *, void *, int) __asm__("func_003DF748");
extern char D_00480428[];
extern char D_00480438[];

extern "C" void func_00256460(char *self) {
    if (func_003DF980_6460(*(int *)(self + 0x18)) == 1) {
        *(int *)(self + 8) = 0;
        ASYNCFILE_release(*(int *)(self + 0x18), 0, self + 8);
        int a = *(int *)(self + 4);
        if (a != 0) {
            int b = *(int *)(self + 8);
            if (b > 0 && func_003FCFD8_6460(a, b) >= 0) {
                void *m = operator_new__FUi_6460(0x10000, D_00480428, 0x04000100, 0);
                *(void **)(self + 0xC) = m;
                *(int *)(self + 0x18) = func_003DF748_6460(D_00480438, m, 0x10000);
                *(int *)(self + 0) = 2;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256510);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003DF980_6510(int) __asm__("func_003DF980");
extern "C" int ASYNCFILE_release(int, int, void *);
struct K6510 { unsigned char b[4]; };
extern K6510 D_004A2EE8[];

extern "C" void func_00256510(char *self) {
    if (func_003DF980_6510(*(int *)(self + 0x18)) == 1) {
        *(int *)(self + 0x10) = 0;
        ASYNCFILE_release(*(int *)(self + 0x18), 0, self + 0x10);
        unsigned char *d = *(unsigned char **)(self + 0xC);
        if (d != 0) {
            int n = *(int *)(self + 0x10);
            if (n > 0) {
                *(int *)(self + 0) = 3;
                K6510 key = D_004A2EE8[0];
                int i;
                unsigned char *p;
                for (i = 0, p = d; i < *(int *)(self + 0x10); i++, p++) {
                    *p ^= key.b[i % 4];
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002565E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003FD100_65E0(int) __asm__("func_003FD100");
extern "C" void func_003E6448_65E0(char *, int, int) __asm__("func_003E6448");
extern "C" int func_003FD128_65E0(char *) __asm__("func_003FD128");
extern "C" void USTR_copy_65E0(char *, char *) __asm__("USTR_copy");

extern "C" void func_002565E0(char *self) {
    if (func_003FD100_65E0(*(int *)(self + 0x14)) == 0) {
        char *p = self + 0xC4;
        func_003E6448_65E0(p, 0, 0x38C);
        char *b = self + 0x650;
        char *c = self + 0x850;
        int r = func_003FD128_65E0(p);
        *(short *)(self + 0x450) = 0;
        *(short *)b = 0;
        *(short *)c = 0;
        USTR_copy_65E0(self + 0x450, self + 0xCC);
        USTR_copy_65E0(b, self + 0x10C);
        USTR_copy_65E0(c, self + 0x20C);
        if (r == 0) {
            *(int *)(self + 0x1C) = 1;
        } else {
            *(int *)(self + 0x1C) = 0;
        }
        *(int *)(self + 0) = 5;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256698);
#ifdef SKIP_ASM
void* func_002557E0(void *);
extern char D_004812D0[];

extern "C" void *func_00256698(void *arg0) {
    func_002557E0(arg0);
    (*(char **)((char*)(arg0) + (8))) = D_004812D0;
    (*(float *)((char*)(arg0) + (0x10))) = 0.10000000149011612f;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x18))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002566E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00255800_66E8(void *, int) __asm__("func_00255800");
extern "C" void func_00256998(void *);
extern char D_004812D0[];

extern "C" void func_002566E8(void *arg0, int arg1) {
    (*(char **)((char*)(arg0) + (8))) = D_004812D0;
    func_00256998(arg0);
    func_00255800_66E8(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256730);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_003E6574_6730(char *, char *, int) __asm__("func_003E6574");
extern "C" int func_003E6B10_6730(int, char *, int) __asm__("func_003E6B10");

extern "C" unsigned char func_00256730(char *self, char *dst, int maxlen) {
    unsigned char buf[0x108];
    if (*(int *)(self + 0xC) == 2) {
        while (func_003E6B10_6730(*(int *)(self + 0x1C), (char *)buf, 1) > 0) {
            if (buf[2] == 5) {
                if (buf[3] != 0 && maxlen >= (int)buf[3]) {
                    unsigned char n = buf[3];
                    func_003E6574_6730(dst, (char *)buf + 4, n);
                    return buf[3];
                }
            } else {
                *(int *)(self + 0x14) = 1;
                return 0;
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002567E0);
#ifdef SKIP_ASM
extern "C" void func_003E6574(char *, int, int);
extern "C" int func_003E6C80(int, void *, int);

extern "C" int func_002567E0(char *self, int a1, int len) {
    char buf[0x108];
    if (*(int *)(self + 0xC) != 2) return 0;
    int t = *(int *)(self + 4);
    if (t != 0) return 0;
    if (len > 0) {
        buf[2] = 5;
        buf[3] = len;
        func_003E6574(buf + 4, a1, len);
        return t < func_003E6C80(*(int *)(self + 0x1C), buf, 1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256860);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00255830__FPv_6860(void *) __asm__("func_00255830__FPv");
extern "C" int func_003E6E08();
extern "C" int func_003E6F40_6860(int, int, void *) __asm__("func_003E6F40");
extern "C" int sprintf_6860(char *, const char *, ...) __asm__("sprintf");
extern char D_00480448[];

extern "C" void func_00256860(char *self, int a1, int a2) {
    int n = a2 & 0xFFFF;
    char buf[0x100];
    char *vt = *(char **)(self + 8);
    (*(void (**)(void *))(vt + 0x14))(self + *(short *)(vt + 0x10));
    func_00255830__FPv_6860(self);
    int h = func_003E6E08();
    *(int *)(self + 0x18) = h;
    if (h != 0) {
        sprintf_6860(buf, D_00480448, a1, n, n);
        func_003E6F40_6860(*(int *)(self + 0x18), 0x101, buf);
        *(int *)(self + 0xC) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002568F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00255830__FPv_68F8(void *) __asm__("func_00255830__FPv");
extern "C" int func_003E6E08();
extern "C" int func_003E6F40_68F8(int, int, void *) __asm__("func_003E6F40");
extern "C" int sprintf_68F8(char *, const char *, ...) __asm__("sprintf");
extern char D_00480448[];

extern "C" void func_002568F8(char *self, int a1, int a2) {
    int n = a2 & 0xFFFF;
    char buf[0x100];
    *(int *)(self + 4) = 0;
    char *vt = *(char **)(self + 8);
    (*(void (**)(void *))(vt + 0x14))(self + *(short *)(vt + 0x10));
    func_00255830__FPv_68F8(self);
    int h = func_003E6E08();
    *(int *)(self + 0x18) = h;
    if (h != 0) {
        sprintf_68F8(buf, D_00480448, a1, n, n);
        func_003E6F40_68F8(*(int *)(self + 0x18), 0x102, buf);
        *(int *)(self + 0xC) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256998);
#ifdef SKIP_ASM
extern "C" void func_00255840(void* self);
extern "C" void func_003E67F8(int);
extern "C" void func_003E6E70(int);

extern "C" void func_00256998(void *arg0) {
    int temp_4;
    int temp_4_2;

    if ((*(int *)((char*)(arg0) + (0xC))) != 0) {
        func_00255840(arg0);
        temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
        if (temp_4 != 0) {
            func_003E67F8(temp_4);
            (*(int *)((char*)(arg0) + (0x1C))) = 0;
        }
        temp_4_2 = (*(int *)((char*)(arg0) + (0x18)));
        if (temp_4_2 != 0) {
            func_003E6E70(temp_4_2);
            (*(int *)((char*)(arg0) + (0x18))) = 0;
        }
        (*(int *)((char*)(arg0) + (0xC))) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256A00);
#ifdef SKIP_ASM
extern "C" void func_00256A58(void* self);
extern "C" void func_00256AA8(char* self);

extern "C" void func_00256A00(char* self)
{
    switch (*(int*)((char*)self + 0xC)) {
    case 1:
        func_00256A58(self);
        break;
    case 2:
        func_00256AA8(self);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256A58);
#ifdef SKIP_ASM
extern "C" int func_003E66F0(int, int, int);
extern "C" int func_003E6FC8(int);

extern "C" void func_00256A58(void *arg0) {
    int temp_2;
    int temp_2_2;

    temp_2 = func_003E6FC8((*(int *)((char*)(arg0) + (0x18))));
    if (temp_2 != 0) {
        temp_2_2 = func_003E66F0(temp_2, 0, 0x237C);
        (*(int *)((char*)(arg0) + (0x1C))) = temp_2_2;
        if (temp_2_2 != 0) {
            (*(int *)((char*)(arg0) + (0xC))) = 2;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256AA8);
#ifdef SKIP_ASM
struct VEnt_6AA8 {
    short delta;
    short index;
    void (*fn)(char*);
};

extern "C" char* func_003E6958(int id);

extern "C" void func_00256AA8(char* s)
{
    char* st = func_003E6958(*(int*)(s + 0x1C));
    if (st) {
        if (*(int*)(st + 0x0) - *(int*)(st + 0x20) > 30000) {
            *(int*)(s + 0xC) = 3;
            *(int*)(s + 0x4) = 1;
            return;
        }
        if (*(unsigned char*)(st + 0x45) == 0) {
            VEnt_6AA8* vt = *(VEnt_6AA8**)(s + 0x8);
            vt[2].fn(s + vt[2].delta);
            *(int*)(s + 0x4) = 1;
            return;
        }
        float f = (float)*(unsigned int*)(st + 0xC) * 0.0010000000474974513f;
        if (f > 1.0f) f = 1.0f;
        *(float*)(s + 0x10) = (*(float*)(s + 0x10) * 4.0f + f) * 0.20000000298023224f;
    }
    if (*(int*)(s + 0x14)) {
        *(int*)(s + 0xC) = 4;
        *(int*)(s + 0x4) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256BA8);
#ifdef SKIP_ASM
extern "C" float func_00256BA8(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", RpcAlloc);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *operator_new_6BB0(unsigned int, void *, unsigned int, int) __asm__("operator_new__FUi");
extern char D_00480478[];

extern "C" void *RpcAlloc(unsigned int size) {
    return operator_new_6BB0(size, D_00480478, 0x20000000, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256BD8);
#ifdef SKIP_ASM
extern "C" void cMemMan_free__FPv();

extern "C" void func_00256BD8(int arg0) {
    if (arg0 != 0) {
        cMemMan_free__FPv();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", cGameComm_construct);
#ifdef SKIP_ASM
extern "C" int cMemMan_alloc(int, int *, int, int);
extern "C" int func_00256C78(int, int, int);
extern int D_004804B8[];
extern int D_004A2EEC;

extern "C" void cGameComm_construct(int arg0, int arg1) {
    D_004A2EEC = func_00256C78(cMemMan_alloc(0x5F0, D_004804B8, 0x20000000, 0), arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256C50);
#ifdef SKIP_ASM
extern "C" void func_00256EE0(int, int);
extern int D_004A2EEC;

extern "C" void func_00256C50(void) {
    if (D_004A2EEC != 0) {
        func_00256EE0(D_004A2EEC, 3);
        D_004A2EEC = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256C78);
#ifdef SKIP_ASM
void* cBE_getInterface_6C78(void* be, int kind) __asm__("cBE_getInterface__Fv");
int func_0014E2C0(void* iface);
extern "C" void func_00257038_6C78(void* self, int mode) __asm__("func_00257038");
extern "C" void func_003E6448_6C78(void* p, int c, int n) __asm__("func_003E6448");
extern "C" int func_003E7340();

struct sGcQueue_6C78 {
    int wr;                 // 0x0
    int rd;                 // 0x4
    int* slots[32];         // 0x8
};

// cGameComm (0x5F0 bytes, allocated by cGameComm_construct).
struct sGameComm_6C78 {
    int unk_0;          // 0x0
    int unk_4;          // 0x4
    int unk_8;          // 0x8
    int unk_C;          // 0xC
    int unk_10;         // 0x10
    int unk_14;         // 0x14
    int unk_18;         // 0x18
    int unk_1C;         // 0x1C
    int unk_20;         // 0x20
    int unk_24;         // 0x24
    int unk_28;         // 0x28
    int unk_2C;         // 0x2C
    int unk_30;         // 0x30
    int unk_34;         // 0x34
    int unk_38;         // 0x38
    int unk_3C;         // 0x3C
    int unk_40;         // 0x40
    int unk_44;         // 0x44
    int unk_48;         // 0x48
    int unk_4C;         // 0x4C
    int unk_50;         // 0x50
    int unk_54;         // 0x54
    int unk_58;         // 0x58
    int unk_5C;         // 0x5C
    int unk_60;         // 0x60
    int unk_64;         // 0x64
    int unk_68;         // 0x68
    int unk_6C;         // 0x6C
    int unk_70;         // 0x70
    int unk_74;         // 0x74
    int unk_78;         // 0x78
    int unk_7C;         // 0x7C
    int unk_80;         // 0x80
    int unk_84;         // 0x84
    int unk_88;         // 0x88
    int unk_8C;         // 0x8C
    int unk_90;         // 0x90
    int unk_94;         // 0x94
    int unk_98;         // 0x98
    int unk_9C;         // 0x9C
    int unk_A0;         // 0xA0
    int unk_A4;         // 0xA4
    int unk_A8;         // 0xA8
    int unk_AC;         // 0xAC
    int unk_B0;         // 0xB0
    int unk_B4;         // 0xB4
    int unk_B8;         // 0xB8
    int unk_BC;         // 0xBC
    int unk_C0;         // 0xC0
    int unk_C4[4];          // 0xC4 (cleared high to low)
    char unk_D4[0x18];      // 0xD4 (random state; func_003178E0 / func_00317908)
    int unk_EC;         // 0xEC
    char unk_F0[0x10];      // 0xF0 (name, host side)
    int unk_100;        // 0x100
    char unk_104[0x10];     // 0x104 (name, client side)
    float unk_114;      // 0x114
    float unk_118;      // 0x118
    float unk_11C;      // 0x11C
    int unk_120;        // 0x120
    int unk_124;        // 0x124
    int unk_128;        // 0x128
    int unk_12C;        // 0x12C
    int unk_130;        // 0x130
    int unk_134;        // 0x134
    int unk_138;        // 0x138
    int unk_13C;        // 0x13C
    int unk_140;        // 0x140
    sGcQueue_6C78 q[5];     // 0x144
    void* buf;              // 0x3EC
    int bufSize;            // 0x3F0
    int unk_3F4;            // 0x3F4
    int unk_3F8;            // 0x3F8
    int unk_3FC;            // 0x3FC
    int unk_400;            // 0x400
    int unk_404;            // 0x404
    int unk_408;            // 0x408
    int unk_40C;            // 0x40C
    char unk_410[0xF0];     // 0x410
    char unk_500[0xF0];     // 0x500
};

struct sGcGlobals_6C78 {
    char pad0[0x10];
    int unk_10;             // 0x10
    float unk_14;           // 0x14
    int unk_18;             // 0x18
    char pad1C[0x5C];
    void* be;               // 0x78
};
extern sGcGlobals_6C78* D_004A28A8_6C78 __asm__("D_004A28A8");

// cGameComm setup (called by cGameComm_construct on a fresh 0x5F0-byte block): clears the session state,
// the five packet queues and the two message buffers, and returns self.
// PORT: the unit declares this as (int, int, int) returning int.
extern "C" int func_00256C78(int vself, int port, int b)
{
    sGameComm_6C78* self = (sGameComm_6C78*)vself;
    self->unk_6C = port;
    self->unk_44 = b;
    func_00257038_6C78(self, 0);
    self->bufSize = func_0014E2C0(cBE_getInterface_6C78(D_004A28A8_6C78->be, 7));
    self->unk_60 = 30;
    self->unk_0 = 1;
    self->buf = 0;
    self->unk_40 = 1;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_5C = 0;
    self->unk_2C = 0;
    self->unk_64 = -1;
    self->unk_48 = 0;
    self->unk_7C = 0;
    self->unk_80 = 0;
    self->unk_84 = 0;
    self->unk_30 = 0;
    self->unk_18 = 0;
    self->unk_94 = 0;
    self->unk_88 = 0;
    self->unk_8C = 0;
    self->unk_90 = 0;
    self->unk_9C = 1;
    self->unk_68 = -1;
    self->unk_AC = 1;
    self->unk_A0 = 0;
    self->unk_A4 = 0;
    self->unk_B0 = 0;
    self->unk_A8 = 0;
    self->unk_98 = 0;
    self->unk_4C = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_124 = 0;
    self->unk_12C = 0;
    self->unk_128 = 0;
    self->unk_114 = D_004A28A8_6C78->unk_14;
    self->unk_118 = D_004A28A8_6C78->unk_14;
    self->unk_11C = D_004A28A8_6C78->unk_14;
    self->unk_120 = 3;
    self->unk_4 = 0;
    self->unk_8 = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_134 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_3F4 = 0;
    self->unk_C = 0;
    self->unk_3F8 = 0;
    self->unk_3FC = 0;
    self->unk_B4 = 0;
    self->unk_B8 = 0;
    self->unk_BC = 0;
    self->unk_C0 = 0;
    for (int j = 3; j >= 0; j--) {
        self->unk_C4[j] = 0;
    }
    self->unk_34 = D_004A28A8_6C78->unk_18 / D_004A28A8_6C78->unk_10;
    self->unk_38 = 0;
    self->unk_3C = 0;
    self->unk_138 = 0;
    self->unk_140 = 0;
    self->unk_13C = 0;
    for (int i = 0; i < 4; i++) {
        sGcQueue_6C78* q = &self->q[i];
        q->wr = 0;
        q->rd = 0;
        func_003E6448_6C78(q->slots, 0, sizeof(q->slots));
    }
    self->q[4].wr = 0;
    self->q[4].rd = 0;
    func_003E6448_6C78(self->q[4].slots, 0, sizeof(self->q[4].slots));
    self->unk_400 = 0;
    self->unk_404 = 0;
    self->unk_408 = -1;
    self->unk_40C = -1;
    func_003E6448_6C78(self->unk_410, 0, sizeof(self->unk_410));
    func_003E6448_6C78(self->unk_500, 0, sizeof(self->unk_500));
    self->unk_140 = func_003E7340();
    return (int)self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00256EE0);
#ifdef SKIP_ASM
extern "C" void cMemMan_free_6EE0(void *) __asm__("cMemMan_free__FPv");
extern "C" void operator_delete__FPi(int *);
extern "C" void func_002581B8(void *arg0, int *arg1);
extern "C" void func_003E73E0(void* p);

struct PacketQueue_6EE0 {
    int wr;                 // 0x0
    int rd;                 // 0x4
    int* slots[32];         // 0x8
};

static inline int* Peek_6EE0(PacketQueue_6EE0* q)
{
    return q->rd < q->wr ? q->slots[q->rd % 32] : 0;
}

static inline int* Pop_6EE0(PacketQueue_6EE0* q)
{
    return q->slots[q->rd++ % 32];
}

// PORT: the unit declares this as (int, int)
extern "C" void func_00256EE0(int self, int flags)
{
    char* s = (char*)self;
    int i;
    if (*(void**)(s + 0x3EC)) cMemMan_free_6EE0(*(void**)(s + 0x3EC));
    if (*(int**)(s + 0x134)) func_002581B8(s, *(int**)(s + 0x134));
    for (i = 0; i < 4; i++) {
        while (Peek_6EE0((PacketQueue_6EE0*)(s + 0x144) + i)) {
            func_002581B8(s, Pop_6EE0((PacketQueue_6EE0*)(s + 0x144) + i));
        }
    }
    if (*(void**)(s + 0x140)) {
        func_003E73E0(*(void**)(s + 0x140));
        *(void**)(s + 0x140) = 0;
    }
    if (flags & 1) operator_delete__FPi((int*)s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257038);
#ifdef SKIP_ASM
extern "C" void func_00258330(void *arg0);
extern "C" void func_00258870(void *, int, int);
extern "C" void func_0031AD18(void);
// Switches the controller to a new mode, running per-mode setup first.
extern "C" void func_00257038(void *self, int mode)
{
    switch (mode) {
    case 14:
        func_00258330(self);
        func_00258870(self, 0xE10, 0);
        func_0031AD18();
        *(int *)((char *)self + 0x70) = mode;
        return;
    case 15:
        *(int *)((char *)self + 0x84) = 0;
        *(int *)((char *)self + 0x78) = 0;
        break;
    case 1: case 3: case 5: case 7: case 9: case 11: case 13:
        func_00258870(self, 0x708, 0);
        break;
    case 2: case 4: case 6: case 8: case 10: case 12:
        break;
    }
    *(int *)((char *)self + 0x70) = mode;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002570D8);
#ifdef SKIP_ASM
// PORT: several callees are defined later in the unit with their own parameter types; bind local views by asm label
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_0014E2C8_70D8(void* iface, int a1, int a2) __asm__("func_0014E2C8");
extern "C" void func_0014E5C8_70D8(void* iface, int a1, int a2) __asm__("func_0014E5C8");
extern "C" float func_00255D88_70D8(int arg0, int arg1) __asm__("func_00255D88");
extern "C" void func_00257038_70D8(void* self, int mode) __asm__("func_00257038");
extern "C" void func_00257750_70D8(char* p) __asm__("func_00257750");
extern "C" int func_002577C8_70D8(char* s) __asm__("func_002577C8");
extern "C" void func_00257A80_70D8(char* s) __asm__("func_00257A80");
extern "C" void func_00257CD8_70D8(char* s) __asm__("func_00257CD8");
extern "C" void func_00257DC0_70D8(char* s) __asm__("func_00257DC0");
extern "C" void func_00257F98_70D8(char* s) __asm__("func_00257F98");
extern "C" int func_002581D8_70D8(char* s) __asm__("func_002581D8");
extern "C" void func_002581E8_70D8(char* s, int a1, int a2) __asm__("func_002581E8");
extern "C" void func_002581F8_70D8(char* s) __asm__("func_002581F8");
extern "C" int func_00258280_70D8(char* s) __asm__("func_00258280");
extern "C" void func_00258290_70D8(char* s, int a1, int a2) __asm__("func_00258290");
extern "C" void func_002582A0_70D8(char* s) __asm__("func_002582A0");
extern "C" void func_00258CB0_70D8(void* s) __asm__("func_00258CB0");
extern "C" int func_003E7450_70D8(int sock, int a1, char* tag, int n) __asm__("func_003E7450");
extern "C" int func_003E7500_70D8(int sock, char* buf, int* len, int* info) __asm__("func_003E7500");
extern "C" int func_00416B18_70D8(const char* a, const char* b, int n) __asm__("func_00416B18");
extern void* D_004A28A8;
extern int D_004A2EB8;
extern char D_00481380[];

// PORT: the unit declares func_002570D8 as (void*)
extern "C" void func_002570D8(void* vs)
{
    char* s = (char*)vs;
    if (*(int*)(s + 0x138) > 0) {
        char msg[0x100];
        int info[4];
        int len;
        *(int*)(s + 0x138) = *(int*)(s + 0x138) - 1;
        for (;;) {
            len = 0x100;
            if (func_003E7500_70D8(*(int*)(s + 0x140), msg, &len, info) == 0) {
                break;
            }
            if (func_00416B18_70D8(msg, D_00481380, 0xD) != 0) {
                continue;
            }
            for (int i = 0; i < *(int*)(s + 0xB8); i++) {
                if (*(int*)(s + (i << 2) + 0xC4) == info[2]) {
                    *(int*)(s + 0x138) = 0;
                    *(int*)(s + 0x13C) = 1;
                    break;
                }
            }
            if (*(int*)(s + 0x138) <= 0) {
                break;
            }
        }
        if (*(int*)(s + 0x138) > 0 && *(int*)(s + 0xB8) < 4) {
            if (*(int*)(s + 0xBC) > 0) {
                *(int*)(s + 0xBC) = *(int*)(s + 0xBC) - 1;
            } else {
                int sock = func_003E7450_70D8(*(int*)(s + 0x140), *(int*)(s + 0xC0), D_00481380, 0xE);
                int k = *(int*)(s + 0xB8);
                *(int*)(s + (k << 2) + 0xC4) = sock;
                *(int*)(s + 0xB8) = k + 1;
                *(int*)(s + 0xBC) = 4;
            }
        }
    }
    *(float*)(s + 0xB0) = *(float*)(s + 0xB0) - 0.15000000596046448f;
    if (*(float*)(s + 0xB0) < 0.0f) {
        *(float*)(s + 0xB0) = 0.0f;
    }
    if (*(int*)(s + 0x3FC) > 0) {
        *(int*)(s + 0x3FC) = *(int*)(s + 0x3FC) - 1;
    }
    func_00258CB0_70D8(s);
    func_00257750_70D8(s);
    if (func_002577C8_70D8(s) != 0) {
        return;
    }
    func_00257CD8_70D8(s);
    func_00257DC0_70D8(s);
    func_002581F8_70D8(s);
    func_002582A0_70D8(s);
    func_00257F98_70D8(s);
    if (func_002577C8_70D8(s) != 0) {
        return;
    }
    void* iface = cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    if (*(int*)(s + 0x44) != 0) {
        switch (*(unsigned int*)(s + 0x70)) {
        case 0:
            func_00257038_70D8(s, 1);
            break;
        case 1:
            func_00258290_70D8(s, (int)(s + 0xD4), 0x2C);
            func_00257038_70D8(s, 2);
            break;
        case 2:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 3);
            }
            break;
        case 3:
            func_002581E8_70D8(s, (int)(s + 0x100), 0x14);
            func_00257038_70D8(s, 4);
            break;
        case 4:
            if (func_002581D8_70D8(s) != 0) {
                func_00257038_70D8(s, 5);
            }
            break;
        case 5:
            func_0014E2C8_70D8(iface, 0, *(int*)(s + 0x3EC));
            func_00258290_70D8(s, *(int*)(s + 0x3EC), *(int*)(s + 0x3F0));
            func_00257038_70D8(s, 6);
            break;
        case 6:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 7);
            }
            break;
        case 7:
            func_002581E8_70D8(s, *(int*)(s + 0x3EC), *(int*)(s + 0x3F0));
            func_00257038_70D8(s, 8);
            break;
        case 8:
            if (func_002581D8_70D8(s) != 0) {
                func_0014E5C8_70D8(iface, 1, *(int*)(s + 0x3EC));
                func_00257038_70D8(s, 9);
            }
            break;
        case 9:
            *(float*)(s + 0x114) = func_00255D88_70D8(D_004A2EB8, *(int*)(s + 0x6C));
            func_00258290_70D8(s, (int)(s + 0x114), 4);
            func_00257038_70D8(s, 10);
            break;
        case 10:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 11);
            }
            break;
        case 11:
            func_002581E8_70D8(s, (int)(s + 0x118), 4);
            func_00257038_70D8(s, 12);
            break;
        case 12:
            if (func_002581D8_70D8(s) != 0) {
                func_00257038_70D8(s, 13);
            }
            break;
        case 13:
            func_00257038_70D8(s, 14);
            break;
        case 14:
            func_00257A80_70D8(s);
            break;
        case 15:
            break;
        }
    } else {
        switch (*(unsigned int*)(s + 0x70)) {
        case 0:
            func_00257038_70D8(s, 3);
            break;
        case 3:
            func_002581E8_70D8(s, (int)(s + 0xD4), 0x2C);
            func_00257038_70D8(s, 4);
            break;
        case 4:
            if (func_002581D8_70D8(s) != 0) {
                func_00257038_70D8(s, 1);
            }
            break;
        case 1:
            func_00258290_70D8(s, (int)(s + 0x100), 0x14);
            func_00257038_70D8(s, 2);
            break;
        case 2:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 7);
            }
            break;
        case 7:
            func_002581E8_70D8(s, *(int*)(s + 0x3EC), *(int*)(s + 0x3F0));
            func_00257038_70D8(s, 8);
            break;
        case 8:
            if (func_002581D8_70D8(s) != 0) {
                func_0014E5C8_70D8(iface, 0, *(int*)(s + 0x3EC));
                func_00257038_70D8(s, 5);
            }
            break;
        case 5:
            func_0014E2C8_70D8(iface, 1, *(int*)(s + 0x3EC));
            func_00258290_70D8(s, *(int*)(s + 0x3EC), *(int*)(s + 0x3F0));
            func_00257038_70D8(s, 6);
            break;
        case 6:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 11);
            }
            break;
        case 11:
            func_002581E8_70D8(s, (int)(s + 0x114), 4);
            func_00257038_70D8(s, 12);
            break;
        case 12:
            if (func_002581D8_70D8(s) != 0) {
                func_00257038_70D8(s, 9);
            }
            break;
        case 9:
            *(float*)(s + 0x118) = func_00255D88_70D8(D_004A2EB8, *(int*)(s + 0x6C));
            func_00258290_70D8(s, (int)(s + 0x118), 4);
            func_00257038_70D8(s, 10);
            break;
        case 10:
            if (func_00258280_70D8(s) != 0) {
                func_00257038_70D8(s, 13);
            }
            break;
        case 13:
            func_00257038_70D8(s, 14);
            break;
        case 14:
            func_00257A80_70D8(s);
            break;
        case 15:
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257610);
#ifdef SKIP_ASM
extern void *D_004A28A8;

extern "C" void func_00257610(void *arg0, int arg1) {
    if (((arg1 != 0) || (((*(int *)((char*)(arg0) + (4))) == 0) && ((*(int *)((char*)(arg0) + (0x70))) < 0xF))) && ((*(int *)((char*)(arg0) + (0x38))) == 0)) {
        (*(int *)((char*)(arg0) + (0x38))) = (int) ((int) (*(int *)((char*)(D_004A28A8) + (0x18))) / (int) (*(int *)((char*)(D_004A28A8) + (0x10))));
    }
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (0x80))) = 0;
    (*(int *)((char*)(arg0) + (0x78))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257678);
#ifdef SKIP_ASM
extern "C" void func_00257678(char *self) {
    if (*(int *)(self + 0x30) == 0) {
        *(int *)(self + 0x30) = 1;
        int *p = (int *)(self + 0x18);
        int v = 0;
        if (*(int *)(self + 0xA0) == 0 || *(int *)(self + 0xA4) == 0) {
            int c = *(int *)(self + 0x70) >= 0xF;
            if (!c) v = 1;
        }
        *p = v;
        *(int *)(self + 0x20) = *(int *)(self + 0xA0) | (*(int *)(self + 0xA4) << 1) | (*(int *)(self + 0x10) << 2) | (*(int *)(self + 0x14) << 3)
            | (*(int *)(self + 0x7C) << 4) | (*(int *)(self + 0x80) << 5) | (*(int *)(self + 0x48) << 6) | (*(int *)(self + 0x88) << 7)
            | (*(int *)(self + 0x8C) << 8) | (*(int *)(self + 0x90) << 9) | (*(int *)(self + 0xAC) << 10);
        *(int *)(self + 0x1C) = *(int *)(self + 0x70);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257750);
#ifdef SKIP_ASM
extern "C" void func_00257750(char *p) {
    if (*(int *)(p + 8) == 0 && *(int *)(p + 0x48) == 0 && (*(int *)(p + 4) == 0 || *(int *)(p + 0x80) == 0)) {
        int a = *(int *)(p + 0x64);
        if (a > 0) {
            if (*(int *)(p + 0x74) == 0 || *(int *)(p + 0x78) == 0) {
                *(int *)(p + 0x64) = a - 1;
            }
        }
        int b = *(int *)(p + 0x68);
        if (b > 0) {
            *(int *)(p + 0x68) = b - 1;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002577C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00255E40_77C8(int sys, int port) __asm__("func_00255E40");
extern "C" void func_00257678(char *self);
extern "C" void func_002578F8(char *self);
extern "C" void func_002579C8(char *self);
extern int D_004A2EB8;

extern "C" int func_002577C8(char* s)
{
    if (*(int*)(s + 0x8) > 0) {
        func_002579C8(s);
        return 1;
    }
    if (*(int*)(s + 0x4) != 0) return 1;
    if (*(int*)(s + 0x8C) != 0) {
        func_002578F8(s);
        return 1;
    }
    if (func_00255E40_77C8(D_004A2EB8, *(int*)(s + 0x6C)) != 0) {
        func_00257678(s);
        func_002578F8(s);
        return 1;
    }
    if (*(int*)(s + 0x54) >= 3) {
        *(int*)(s + 0x24) = 3;
        func_002578F8(s);
        return 1;
    }
    if (*(int*)(s + 0x4C) >= 6) {
        *(int*)(s + 0x24) = 2;
        func_002578F8(s);
        return 1;
    }
    if (*(int*)(s + 0x58) >= 3) {
        *(int*)(s + 0x28) = 3;
        func_002578F8(s);
        return 1;
    }
    if (*(int*)(s + 0x50) >= 6) {
        *(int*)(s + 0x28) = 2;
        func_002578F8(s);
        return 1;
    }
    if (*(float*)(s + 0xB0) >= 3600.0f) {
        func_00257678(s);
        func_002578F8(s);
        return 1;
    }
    if (*(int*)(s + 0x94) <= 0) return 0;
    if (--*(int*)(s + 0x94) > 0) return 0;
    *(int*)(s + 0x2C) = 1;
    func_00257678(s);
    func_002578F8(s);
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002578F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_002579C8_78F8(void *) __asm__("func_002579C8");
extern "C" void func_00258CB0_78F8(void *) __asm__("func_00258CB0");
extern "C" void func_00266DF8_78F8(int) __asm__("func_00266DF8");
extern void *D_004A28A8;
extern int D_004A33F4;

extern "C" void func_002578F8(char *self) {
    *(int *)(self + 0x84) = 0;
    *(int *)(self + 0x78) = 0;
    *(int *)(self + 0x3F8) = 0;
    *(int *)(self + 0x3FC) = 0;
    if (*(int *)(self + 4) == 0) {
        if (*(int *)(self + 0xC) == 0 && *(int *)(self + 0x24) == 0) {
            if ((*(int *)(self + 0x30) == 0 || *(int *)(self + 0x88) != 0) && *(int *)(self + 0xA0) == 0 && *(int *)(self + 0x80) != 0) {
                if (*(int *)(*(char **)((char*)D_004A28A8 + 0x84) + 0x224) != 0) {
                    *(int *)(self + 0x24) = 4;
                }
            }
        }
        if (D_004A33F4 != 0) {
            func_00266DF8_78F8(D_004A33F4);
        }
        func_00258CB0_78F8(self);
        *(int *)(self + 0x40) = 0;
        *(int *)(self + 0) = 0;
        *(int *)(self + 4) = 1;
        *(int *)(self + 8) = 1;
        func_002579C8_78F8(self);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002579C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" char *cUIStateStack_getCurrentState_79C8(char *) __asm__("cUIStateStack_getCurrentState");
extern "C" void func_0020AB50_79C8(int) __asm__("func_0020AB50");
extern void *D_004A28A8;
extern int D_004A2A50;
extern int D_004A2A54;
extern int D_00442924[];
extern int D_005366E8[];

extern "C" void func_002579C8(char *self) {
    if (*(int *)(self + 0xAC) == 0 && *(int *)(self + 8) > 0) {
        char *p = *(char **)(*(char **)((char*)D_004A28A8 + 0x84) + 0x48);
        char *st;
        if (p != 0 && (p += 0x18) != 0 && ((st = cUIStateStack_getCurrentState_79C8(p), st == 0) || (st[0x1D] & 0x3F) == 5)) {
            int n = *(int *)(self + 8) - 1;
            *(int *)(self + 8) = n;
            if (n <= 0) {
                func_0020AB50_79C8(0x27);
                int idx = D_004A2A54 + 1;
                D_005366E8[idx] = 0xD;
                D_004A2A50 = D_00442924[0];
                D_004A2A54 = idx;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257A80);
#ifdef SKIP_ASM
extern "C" void func_00257678(char *self);
extern "C" void func_002578F8(char *self);
extern void *D_004A28A8;
extern int D_004A3ED0;

extern "C" void func_00257A80(char* s)
{
    if (*(int*)(s + 0x24) != 0) return;
    if (*(int*)(s + 0x74) == 0) {
        if (*(int*)(s + 0x7C) != 0) {
            if (*(int*)(s + 0x78) == 0 && *(int*)(s + 0x3FC) <= 0) {
                char* g = (char*)D_004A28A8;
                int n = ++*(int*)(s + 0xA8);
                ++*(int*)(s + 0x60);
                unsigned int st = *(int*)(*(char**)(*(char**)(g + 0x84) + 0xC)) - 4;
                if (st < 2) {
                    if (n >= 10) *(float*)(s + 0xB0) += 1.0f;
                    if (*(int*)(s + 0xA8) == 10) ++*(int*)(s + 0xB4);
                }
            }
            if (*(int*)(s + 0x60) == 60) *(int*)(s + 0x84) = 1;
        }
        if (*(int*)(s + 0x80) != 0) {
            if (*(int*)(s + 0xC) != 0) {
                func_00257678(s);
                func_002578F8(s);
                return;
            }
            if (*(int*)(s + 0x78) == 0) ++*(int*)(s + 0x5C);
            if (*(int*)(s + 0x5C) >= 1800) {
                *(int*)(s + 0x2C) = 1;
                func_00257678(s);
                func_002578F8(s);
                return;
            }
        }
    }
    if (D_004A3ED0 != 0) {
        *(int*)(s + 0x24) = 1;
        func_002578F8(s);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257BD8);
#ifdef SKIP_ASM
struct Packet_7BD8 {
    unsigned char type;
    unsigned char flags;
    unsigned short size;    // 0x2, includes the 4-byte header
    char data[1];           // 0x4
};

struct PacketQueue_7BD8 {
    int wr;                         // 0x0
    int rd;                         // 0x4
    Packet_7BD8* slots[32];         // 0x8
};

struct Conn_7BD8 {
    char pad0[4];
    int busy;                       // 0x4
    char pad8[0x5C - 0x8];
    int unk5C;                      // 0x5C
    int unk60;                      // 0x60
    char pad64[0x84 - 0x64];
    int unk84;                      // 0x84
    char pad88[0x94 - 0x88];
    int unk94;                      // 0x94
    char pad98[0xA8 - 0x98];
    int unkA8;                      // 0xA8
    char padAC[0x144 - 0xAC];
    PacketQueue_7BD8 queues[2];     // 0x144
};

extern "C" void func_00257CD8(Conn_7BD8* c);
extern "C" void func_002581B8(void *arg0, int *arg1);
extern "C" void func_00258870(void *, int, int);
extern "C" void func_003E6574_7BD8(void* dst, const void* src, int n) __asm__("func_003E6574");

// PORT: the unit declares this as (void*, int, int, int); dst is a pointer passed as int
extern "C" int func_00257BD8(void* self, int ch, int dst, int unused)
{
    Conn_7BD8* c = (Conn_7BD8*)self;
    if (c->busy != 0) return 0;
    func_00257CD8(c);
    PacketQueue_7BD8* q = &c->queues[ch];
    if (q->rd != q->wr) {
        Packet_7BD8* p = q->slots[q->rd++ % 32];
        int len = p->size - 4;
        func_003E6574_7BD8((void*)dst, p->data, len);
        func_002581B8(c, (int*)p);
        if (ch == 0) {
            c->unk5C = 0;
            c->unk60 = 0;
            c->unkA8 = 0;
            c->unk84 = 0;
        }
        if (c->unk94 > 0) func_00258870(c, 0x708, 0);
        return len;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_156860", func_00257CD8);

//100%
INCLUDE_ASM("seg/seg_156860", func_00257DC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00255E00_7DC0(int, int, char *, unsigned short) __asm__("func_00255E00");
extern "C" void func_002581B8_7DC0(char *, char *) __asm__("func_002581B8");
extern int D_004A2EB8;
struct S7DC0 { char pad[0x36C]; char *arr[32]; };

extern "C" void func_00257DC0(char *self) {
    if (*(int *)(self + 0x368) != *(int *)(self + 0x364)) {
        do {
            if (*(int *)(self + 4) != 0) return;
            int idx = *(int *)(self + 0x368);
            char *item;
            if (idx < *(int *)(self + 0x364)) {
                item = ((S7DC0 *)self)->arr[idx % 32];
            } else {
                item = 0;
            }
            if (func_00255E00_7DC0(D_004A2EB8, *(int *)(self + 0x6C), item, *(unsigned short *)(item + 2)) == 0) return;
            *(int *)(self + 0x368) = *(int *)(self + 0x368) + 1;
            func_002581B8_7DC0(self, item);
        } while (*(int *)(self + 0x368) != *(int *)(self + 0x364));
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257E98);
#ifdef SKIP_ASM
struct Packet_7E98 {
    unsigned char type;     // 0x0
    unsigned char flags;    // 0x1
    unsigned short size;    // 0x2, includes this 4-byte header
    char data[0xEC];        // 0x4
};

extern "C" int func_00255E00_7E98(int sys, int port, Packet_7E98* p, int size) __asm__("func_00255E00");
extern "C" Packet_7E98* func_00258188_7E98(char* self) __asm__("func_00258188");
extern "C" void func_003E6574_7E98(void* dst, const void* src, int n) __asm__("func_003E6574");
extern "C" void func_00257DC0(char *self);
extern int D_004A2EB8;

struct Conn_7E98 {
    char pad0[0x36C];
    Packet_7E98* slots[32];     // 0x36C
};

// PORT: the unit declares this void(void*, int, int, int); the target returns a status
extern "C" int func_00257E98_impl(char* self, int type, const void* data, int len) __asm__("func_00257E98");
extern "C" int func_00257E98_impl(char* self, int type, const void* data, int len)
{
    Packet_7E98 pkt;
    if (*(int*)(self + 4) != 0) return 0;
    func_00257DC0(self);
    pkt.type = type;
    pkt.size = len + 4;
    pkt.flags = 0;
    func_003E6574_7E98(pkt.data, data, len);
    if (*(int*)(self + 0x368) == *(int*)(self + 0x364)) {
        if (func_00255E00_7E98(D_004A2EB8, *(int*)(self + 0x6C), &pkt, pkt.size)) return 1;
    }
    {
        Packet_7E98* p = func_00258188_7E98(self);
        func_003E6574_7E98(p, &pkt, pkt.size);
        ((Conn_7E98*)self)->slots[(*(int*)(self + 0x364))++ % 32] = p;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00257F98);
#ifdef SKIP_ASM
// PORT: the unit declares this as (void*, int, int, int); dst is the packet buffer
extern "C" int func_00257BD8_7F98(void* self, int ch, void* dst, int size) __asm__("func_00257BD8");
// PORT: defined later in the unit with a struct param; bind a void* view by asm label
extern "C" void func_002588A8_7F98(void* self) __asm__("func_002588A8");

struct sGamePacket_7F98 {
    unsigned char type;
    int a;      // 0x4
    int b;      // 0x8
};

struct sGameComm_7F98 {
    int f0;
    int f4;
    char pad8[4];
    int fC;
    int f10;
    int f14;
    char pad18[0x3C - 0x18];
    int f3C;
    char pad40[0x50 - 0x40];
    int f50;
    char pad54[4];
    int f58;
    int f5C;
    int f60;
    int f64;
    char pad68[0x70 - 0x68];
    int f70;
    int f74;
    int f78;
    int f7C;
    char pad80[4];
    int f84;
    int f88;
    int f8C;
    char pad90[0x3F4 - 0x90];
    int f3F4;
    int f3F8;
    int f3FC;
    char pad400[4];
    int f404;
    char pad408[4];
    int f40C;
    char pad410[0x500 - 0x410];
    int f500[60];
};

extern "C" void func_00257F98(sGameComm_7F98* self)
{
    sGamePacket_7F98 msg;
    while (func_00257BD8_7F98(self, 3, &msg, 0xC)) {
        switch (msg.type) {
        case 0:
            if (self->f7C == 0) {
                func_00258870(self, 0xE4C, 1);
            } else {
                self->f3F8 = 1;
            }
            self->f78 = 1;
            self->f5C = 0;
            self->f50++;
            self->f3FC = 0;
            break;
        case 1:
            self->f5C = 0;
            self->f78 = 0;
            if (self->f74 != 0 && self->f64 > 0) {
                self->f64 = 0x4B0;
            }
            self->f3F8 = 0;
            self->f60 = 0;
            self->f84 = 0;
            if (self->f7C == 0) {
                func_00258870(self, 0x708, 0);
            } else {
                func_002588A8_7F98(self);
            }
            break;
        case 3:
            self->f3F4 = 1;
            break;
        case 5:
            self->f88 = 1;
            if (self->f3C == 0) {
                self->f3C = *(int*)((char*)D_004A28A8 + 0x18) / *(int*)((char*)D_004A28A8 + 0x10);
            }
            self->f78 = 0;
            self->f0 = 0;
            self->f14 = 1;
            if (self->f4 == 0 && self->f70 < 15) {
                self->f8C = 1;
            }
            break;
        case 2:
            self->f58++;
            break;
        case 4:
            self->f404 = 1;
            self->f40C = msg.a;
            self->f500[msg.a / 60 % 60] = msg.b;
            break;
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258160);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00257BD8_8160(int, int, int, int) __asm__("func_00257BD8");

extern "C" int func_00258160(int arg0, int arg1, int arg2) {
    return func_00257BD8_8160(arg0, 1, arg1, arg2) > 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258188);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *cMemMan_alloc_8188(unsigned int, void *, unsigned int, int) __asm__("cMemMan_alloc");
extern char D_004805A8[];

extern "C" void *func_00258188(void) {
    return cMemMan_alloc_8188(0xF0, D_004805A8, 0x20000000, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002581B8);
#ifdef SKIP_ASM
extern "C" void operator_delete__FPi(int *);

extern "C" void func_002581B8(void *arg0, int *arg1) {
    operator_delete__FPi(arg1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002581D8);
#ifdef SKIP_ASM
extern "C" int func_002581D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x124))) == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002581E8);
#ifdef SKIP_ASM
extern "C" void func_002581E8(void *arg0, int arg1, int arg2) {
    (*(int *)((char*)(arg0) + (0x124))) = arg1;
    (*(int *)((char*)(arg0) + (0x128))) = arg2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_002581F8);
#ifdef SKIP_ASM
extern "C" int func_00257BD8(void *, int, int, int);

extern "C" void func_002581F8(char *p) {
    int a;
    while ((a = *(int *)(p + 0x124)) != 0) {
        int n = *(int *)(p + 0x128);
        if (n >= 0xED) n = 0xEC;
        if (func_00257BD8(p, 2, a, n) == 0) break;
        *(int *)(p + 0x124) = *(int *)(p + 0x124) + n;
        int rem = *(int *)(p + 0x128) - n;
        *(int *)(p + 0x128) = rem;
        if (rem <= 0) {
            *(int *)(p + 0x124) = 0;
            *(int *)(p + 0x128) = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258280);
#ifdef SKIP_ASM
extern "C" int func_00258280(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x12C))) == 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258290);
#ifdef SKIP_ASM
extern "C" void func_00258290(void *arg0, int arg1, int arg2) {
    (*(int *)((char*)(arg0) + (0x12C))) = arg1;
    (*(int *)((char*)(arg0) + (0x130))) = arg2;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_002582A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00257E98_82A0(void *, int, int, int) __asm__("func_00257E98");

extern "C" void func_002582A0(char *p) {
    int a = *(int *)(p + 0x12C);
    if (a != 0 && *(int *)(p + 0x368) == *(int *)(p + 0x364)) {
        int n = *(int *)(p + 0x130);
        if (n >= 0xED) n = 0xEC;
        if (func_00257E98_82A0(p, 2, a, n) != 0) {
            *(int *)(p + 0x12C) = *(int *)(p + 0x12C) + n;
            int rem = *(int *)(p + 0x130) - n;
            *(int *)(p + 0x130) = rem;
            if (rem <= 0) {
                *(int *)(p + 0x12C) = 0;
                *(int *)(p + 0x130) = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258330);
#ifdef SKIP_ASM
// PORT: g++ >?/<? (min/max) operator, removed in GCC 4.3.
extern void *D_004A28A8;

extern "C" void func_00258330(void *arg0) {
    char *p = (char*)D_004A28A8;
    float b = *(float *)((char*)arg0 + 0x118);
    float a = *(float *)((char*)arg0 + 0x114);
    float r = b >? a;
    *(float *)((char*)arg0 + 0x11C) = r;
    float c = *(float *)(p + 0x14);
    if (r < c) {
        *(float *)((char*)arg0 + 0x11C) = c;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258360);
#ifdef SKIP_ASM
extern "C" float func_00255D88(int, int);
extern void *D_004A28A8;
extern int D_004A2EB8;

extern "C" float func_00258360(void *arg0) {
    return func_00255D88(D_004A2EB8, (*(int *)((char*)(arg0) + (0x6C)))) + ((float) (*(int *)((char*)(arg0) + (0x120))) * (*(float *)((char*)(D_004A28A8) + (0x14))));
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002583A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_003E7450_83A8(int, int, char *, int) __asm__("func_003E7450");
extern char D_00481380[];
extern int D_004A2EB8;

struct S83A8 {
    char pad0[0xB8];
    int count;
    int bc;
    int c0;
    int arr[0x1D];
    int t138;
    int t13c;
    int h140;
};

extern "C" void func_002583A8(S83A8 *self, int arg1, int arg2) {
    if (self->t138 <= 0) {
        self->count = 0;
        self->c0 = arg1;
        self->arr[self->count++] = func_003E7450_83A8(self->h140, arg1, D_00481380, 0xE);
        self->bc = 4;
        self->t138 = arg2 * 0x3C;
        self->t13c = 0;
    }
    if (*(int *)((char*)D_004A2EB8 + 0x2C) == 0) {
        self->t13c = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", cGameComm_syncGame);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* operator_new_8448(unsigned int size, const char* tag, int flags, int align) __asm__("operator_new__FUi");
void cMemMan_free_8448(void* p) __asm__("cMemMan_free__FPv");
extern "C" void func_0014E9F8(void* iface);
extern "C" void func_0014EA90(void* iface);
extern "C" void func_0014F898();
extern "C" void func_0014E2C8_8448(void* iface, int which, void* buf) __asm__("func_0014E2C8");
extern "C" void func_0014E5C8_8448(void* iface, int which, void* buf) __asm__("func_0014E5C8");
extern "C" void func_003E6448_8448(char* p, int c, int n) __asm__("func_003E6448");
extern "C" char* strncpy(char* dst, const char* src, unsigned int n);
extern "C" void* cBE_getBE();
extern "C" int func_00147318(void* iface, int a1);
extern "C" void func_001472C8(void* iface, int a1, int a2);
extern "C" void func_00237CB0(unsigned int seed);
extern "C" void THREAD_yieldticks(int);
unsigned int AIrand();
void func_003178E0_8448(void* self) __asm__("func_003178E0__FPv");
void func_00317908(void* self);

struct sVEnt_8448 {
    short delta;
    short index;
    void (*fn)(void*);
};

extern char D_004805B8[];
extern char D_004805C8[];
extern char D_00534B30[];

static inline int ggHost_8448(char* g) { return *(int*)(g + 8); }
static inline void ggSetTime_8448(char* g, float t) { *(float*)(g + 0x10) = t; }
static inline int ggSynced_8448(char* s) { return *(int*)(s + 0x70) == 0xE; }
static inline int ggDropped_8448(char* s) { return *(int*)(s + 4); }

// Joins the game session: sets up the sync buffer and this side's name slot, then pumps
// messages until the sync state (0xE) is reached or the link drops.
extern "C" void cGameComm_syncGame(char* self)
{
    void* iface = cBE_getInterface_Fv(*(void**)((char*)D_004A28A8 + 0x78), 7);
    *(void**)(self + 0x3EC) = operator_new_8448(*(unsigned int*)(self + 0x3F0), D_004805B8, 0x100, 0);
    func_0014E9F8(iface);
    if (ggHost_8448(D_00534B30) != 0) {
        func_003E6448_8448(self + 0xF0, 0, 0x10);
        strncpy(self + 0xF0, D_004805C8, 0xF);
        *(int*)(self + 0xEC) = *(int*)((char*)D_004A2EB8 + 0x2C);
        func_0014E2C8_8448(iface, 0, *(void**)(self + 0x3EC));
        func_0014E5C8_8448(iface, 0, *(void**)(self + 0x3EC));
    } else {
        func_0014F898();
        func_003E6448_8448(self + 0x104, 0, 0x10);
        strncpy(self + 0x104, D_004805C8, 0xF);
        *(int*)(self + 0x100) = *(int*)((char*)D_004A2EB8 + 0x2C);
        func_0014E2C8_8448(iface, 1, *(void**)(self + 0x3EC));
        func_0014E5C8_8448(iface, 1, *(void**)(self + 0x3EC));
        void* ui = cBE_getInterface_Fv(cBE_getBE(), 1);
        func_001472C8(ui, 1, func_00147318(ui, 0));
        sVEnt_8448* vt = *(sVEnt_8448**)((char*)ui + 0xC);
        vt[1].fn((char*)ui + vt[1].delta);
    }
    func_003178E0_8448(self + 0xD4);
    while (!ggSynced_8448(self) && ggDropped_8448(self) == 0) {
        func_002570D8(self);
        THREAD_yieldticks(1);
    }
    if (*(void**)(self + 0x3EC)) {
        cMemMan_free_8448(*(void**)(self + 0x3EC));
    }
    *(int*)(self + 0x120) = 3;
    *(void**)(self + 0x3EC) = 0;
    if (*(int*)(self + 4) == 0) {
        func_0014EA90(iface);
        func_00317908(self + 0xD4);
        func_00237CB0(AIrand());
        ggSetTime_8448(D_00534B30, *(float*)(self + 0x11C));
        if (*(int*)(self + 0xEC) != 0 && *(int*)(self + 0x100) != 0) {
            *(int*)(self + 0x120) = 2;
        }
        if (*(int*)(self + 4) == 0 && func_00416B18_70D8(self + 0xF0, self + 0x104, 9) != 0) {
            func_00257678(self);
            func_002578F8(self);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_002586B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void* cBE_getInterface_86B0(int, int) __asm__("cBE_getInterface__Fv");
extern "C" void func_00257E98(void *, int, int, int);
extern "C" void func_00258870(void *, int, int);
extern "C" void func_002570D8(void *);
extern "C" void THREAD_yieldticks(int);
extern void *D_004A28A8;
extern char D_00534B30[];
static inline int rd8(char *p) { return *(int*)(p + 8); }
extern "C" void func_002586B0(void *self) {
    char buf[12];
    cBE_getInterface_86B0(*(int*)((char*)D_004A28A8 + 0x78), 7);
    if (rd8(D_00534B30) != 0) {
        buf[0] = 3;
        func_00257E98(self, 3, (int)buf, 0xC);
    }
    func_00258870(self, 0xE10, 0);
    while (*(int*)((char*)self + 0x3F4) == 0 && *(int*)((char*)self + 4) == 0) {
        func_002570D8(self);
        THREAD_yieldticks(1);
    }
    *(int*)((char*)self + 0x94) = 0;
    if (*(int*)((char*)self + 4) == 0 && rd8(D_00534B30) == 0) {
        buf[0] = 3;
        func_00257E98(self, 3, (int)buf, 0xC);
    }
    *(int*)((char*)self + 0xAC) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258790);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00257E98(void *, int, int, int);
extern "C" void func_00258870(void *, int, int);
extern void func_002588A8_8790(void *) __asm__("func_002588A8");
extern "C" void func_00258790(void *self, int arg1) {
    char buf[12];
    if (*(int*)((char*)self + 4) == 0 && *(int*)self != 0) {
        if (arg1 != 0) {
            if (*(int*)((char*)self + 0x7C) == 0) {
                func_00258870(self, 0xE4C, 1);
            } else {
                *(int*)((char*)self + 0x3F8) = 1;
            }
            buf[0] = 0;
            *(int*)((char*)self + 0x74) = 1;
            *(int*)((char*)self + 0x4C) = *(int*)((char*)self + 0x4C) + 1;
            *(int*)((char*)self + 0x3FC) = 0;
            *(int*)((char*)self + 0x5C) = 0;
        } else {
            buf[0] = 1;
            *(int*)((char*)self + 0x74) = 0;
            *(int*)((char*)self + 0x3F8) = 0;
            *(int*)((char*)self + 0x60) = 0;
            *(int*)((char*)self + 0x84) = 0;
            *(int*)((char*)self + 0x5C) = 0;
            if (*(int*)((char*)self + 0x7C) == 0) {
                func_00258870(self, 0x708, 0);
            } else {
                func_002588A8_8790(self);
            }
        }
        func_00257E98(self, 3, (int)buf, 0xC);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258870);
#ifdef SKIP_ASM
extern "C" void func_00258870(void *arg0, int arg1, int arg2) {
    if ((arg2 != 0) || (((*(int *)((char*)(arg0) + (0x78))) == 0) && ((*(int *)((char*)(arg0) + (0x74))) == 0)) || ((*(int *)((char*)(arg0) + (0x7C))) != 0)) {
        (*(int *)((char*)(arg0) + (0x94))) = arg1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002588A8);
#ifdef SKIP_ASM
extern void *D_004A28A8;

struct S88A8_4 { int k0; char p[0x14]; int k18; int k1c; };
struct S88A8_6 { char p0[0xC]; S88A8_4 *c; char p1[0x204]; int k214; };
struct S88A8_G { char p[0x84]; S88A8_6 *g84; };
struct S88A8_S { int k0; int k4; char p0[0x40]; int k48; char p1[0x24]; int k70; int k74; int k78; char p2[0x380]; int k3fc; };

extern "C" void func_002588A8(S88A8_S *self) {
    S88A8_6 *t6;
    S88A8_4 *t4;
    self->k3fc = 0;
    t6 = ((S88A8_G *)D_004A28A8)->g84;
    if (t6->k214 != 2 && self->k4 == 0 && self->k48 == 0 && self->k0 != 0
        && self->k70 < 0xF
        && ((t4 = t6->c, t4->k0 != 4) || t4->k1c < 0x97)
        && t4->k18 <= 0 && self->k74 == 0 && self->k78 == 0) {
        self->k3fc = 0xB4;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258950);
#ifdef SKIP_ASM
extern "C" void func_00258950(void *arg0) {
    (*(int *)((char*)(arg0) + (0x84))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 1;
    (*(int *)((char*)(arg0) + (0x78))) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258968);
#ifdef SKIP_ASM
extern "C" void func_00258968(void *arg0) {
    if ((*(int *)((char*)(arg0) + (0x70))) < 0xF) {
        (*(int *)((char*)(arg0) + (0x94))) = 0;
        (*(int *)((char*)(arg0) + (0x7C))) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258988);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00260F80_8988(void) __asm__("func_00260F80");
extern "C" int func_00261460_8988(int) __asm__("func_00261460");
extern "C" void func_002613C8_8988(int) __asm__("func_002613C8");
extern "C" void func_0025B800_8988(void *) __asm__("func_0025B800");
extern "C" void func_00262768_8988(int, int, int, int, int, int) __asm__("func_00262768");
extern void *D_004A28A8;
extern char *D_004A3028;
extern int D_004A3328;

extern "C" void func_00258988(char *self) {
    if (*(int *)(self + 0x70) < 0xF) {
        if (D_004A3328 == 0) {
            func_00260F80_8988();
        }
        if (func_00261460_8988(D_004A3328) == 0) {
            func_002613C8_8988(D_004A3328);
        }
        if (D_004A3328 == 0) {
            func_0025B800_8988(D_004A3028);
        }
        int t4 = D_004A3328;
        if (t4 != 0) {
            func_00262768_8988(t4, 1, 9, *(int *)(D_004A3028 + 0x98), 0, 0);
        }
        *(int *)(self + 0x34) = *(int *)((char*)D_004A28A8 + 0x18) / *(int *)((char*)D_004A28A8 + 0x10);
        *(int *)(self + 0x80) = 1;
        *(int *)(self + 0x94) = 0;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258A48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00257038_8A48(void *, int) __asm__("func_00257038");
extern void *D_004A28A8;

extern "C" void func_00258A48(void *arg0) {
    (*(int *)((char*)(arg0) + (0x80))) = 0;
    (*(int *)((char*)(arg0) + (0x40))) = 0;
    if ((*(int *)((char*)(arg0) + (0x70))) < 0xF) {
        func_00257038_8A48(arg0, 0xF);
    }
    if ((*(int *)((char*)(arg0) + (0x38))) == 0) {
        (*(int *)((char*)(arg0) + (0x38))) = (int) ((int) (*(int *)((char*)(D_004A28A8) + (0x18))) / (int) (*(int *)((char*)(D_004A28A8) + (0x10))));
    }
    if ((*(int *)((char*)(arg0) + (0x3C))) == 0) {
        (*(int *)((char*)(arg0) + (0x3C))) = (int) ((int) (*(int *)((char*)(D_004A28A8) + (0x18))) / (int) (*(int *)((char*)(D_004A28A8) + (0x10))));
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00258AE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
class cIface_AE0 { public: int f0, f4, f8; virtual void v0(); virtual void v1(); };
void* cBE_getInterface_8AE0(int, int) __asm__("cBE_getInterface__Fv");
extern "C" void func_00260F80();
extern "C" int func_00261460(int);
extern "C" void func_002613C8(int);
extern "C" void func_0025B800(int);
extern "C" void func_00262768(int, int, int, int, int, int);
extern "C" void func_00258BC8(void *);
extern "C" void func_00258A48(void *);
extern "C" void func_0014E9C0(void *, int, int);
extern "C" void* cBE_getBE();
extern int D_004A3328;
extern int D_004A3028_8AE0 __asm__("D_004A3028");
extern void *D_004A28A8;
extern int D_00534B38[];
extern "C" void func_00258AE0(void *self) {
    if (D_004A3328 == 0) {
        func_00260F80();
    }
    if (func_00261460(D_004A3328) == 0) {
        func_002613C8(D_004A3328);
    }
    if (D_004A3328 == 0) {
        func_0025B800(D_004A3028_8AE0);
    }
    int t = D_004A3328;
    if (t != 0) {
        func_00262768(t, 1, 0, 0, 0, 0);
    }
    func_00258BC8(self);
    func_00258A48(self);
    void *i = cBE_getInterface_8AE0(*(int*)((char*)D_004A28A8 + 0x78), 7);
    if (D_00534B38[0] == 0) {
        func_0014E9C0(i, 1, 0);
        cIface_AE0 *o = (cIface_AE0*)cBE_getInterface_8AE0((int)cBE_getBE(), 3);
        o->v1();
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258BC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00257E98_8BC8(void *, int, void *, int) __asm__("func_00257E98");

extern "C" void func_00258BC8(void *arg0) {
    if ((*(int *)((char*)(arg0) + (4))) == 0) {
        char buf[12];
        buf[0] = 5;
        func_00257E98_8BC8(arg0, 3, buf, 0xC);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258C00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00257E98_8C00(void *, int, void *, int) __asm__("func_00257E98");

extern "C" void func_00258C00(void *arg0) {
    if (*(int *)((char*)arg0 + 4) == 0 && *(int *)((char*)arg0 + 0) != 0) {
        char buf[12];
        buf[0] = 2;
        *(int *)((char*)arg0 + 0x54) = *(int *)((char*)arg0 + 0x54) + 1;
        func_00257E98_8C00(arg0, 3, buf, 0xC);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("seg/seg_156860", func_00258C50);
#ifdef SKIP_ASM
extern "C" void func_00257E98(void *, int, int, int);
extern "C" int strlen(int);

extern "C" void func_00258C50(void *arg0, int arg1) {
    if (((*(int *)((char*)(arg0) + (4))) == 0) && ((*(int *)((char*)(arg0) + (0))) != 0)) {
        func_00257E98(arg0, 1, arg1, strlen(arg1) + 1);
    }
}
#endif

INCLUDE_ASM("seg/seg_156860", func_00258CB0);

//100%
INCLUDE_ASM("seg/seg_156860", func_00258F20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int func_00257E98_8F20(void* self, int type, const void* data, int len) __asm__("func_00257E98");
extern void *D_004A28A8;

struct SyncMsg_8F20 {
    unsigned char type;     // 0x0
    int frame;              // 0x4
    int value;              // 0x8
};

struct Ring_8F20 {
    int v[60];
};

static inline int& RingAt_8F20(Ring_8F20* r, int frame)
{
    return r->v[(frame / 60) % 60];
}

extern "C" void func_00258F20(char* s, int frame, int value)
{
    char* gs = *(char**)((char*)D_004A28A8 + 0x84);
    int st = **(int**)(gs + 0xC);
    if (st != 5) {
        if (st != 3) return;
        if (*(int*)(gs + 0x214) != st) return;
    }
    if (*(int*)(s + 0x40) == 0) return;
    if (*(int*)(s + 0x4) != 0) return;
    if (*(int*)(s + 0x0) == 0) return;
    if (*(int*)(s + 0xC) != 0) return;
    RingAt_8F20((Ring_8F20*)(s + 0x410), frame) = value;
    *(int*)(s + 0x408) = frame;
    if (*(int*)(s + 0x400) != 0) {
        if (*(int*)(s + 0x404) != 0) {
            *(int*)(s + 0x404) = 0;
            *(int*)(s + 0x400) = 0;
        }
    } else {
        SyncMsg_8F20 msg;
        msg.frame = frame;
        msg.value = value;
        msg.type = 4;
        func_00257E98_8F20(s, 3, &msg, 12);
        *(int*)(s + 0x400) = 1;
    }
    {
        int f = *(int*)(s + 0x408);
        if (f < 0) return;
        int g = *(int*)(s + 0x40C);
        if (g < 0) return;
        int m = g < f ? g : f;
        if (RingAt_8F20((Ring_8F20*)(s + 0x410), m) != RingAt_8F20((Ring_8F20*)(s + 0x500), m)) *(int*)(s + 0xC) = 1;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00259098);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_9098(void* be, int kind) __asm__("cBE_getInterface__Fv");
int cBENewPlayerInterface_getPlayerCharID(void*, int);
extern "C" void func_0014EBB8(void* iface, int v);
extern "C" void func_0014EBD8(void* iface, int v);
extern "C" void func_002639E0(int a, int b, int c, int d, int e);
extern void *D_004A28A8;
extern char* D_004A3028;
extern int D_00534E58[];

struct VEnt_9098 {
    short delta;
    short index;
    void (*fn)(char*);
};

extern "C" void func_00259098(int a0, int a1, int a2)
{
    char* g = D_004A3028;
    int v;
    if (*(int*)(g + 0xB4)) v = *(int*)(g + 0xAC);
    else v = *(int*)(g + 0xA8);
    void* pi = cBE_getInterface_9098(cBE_getBE(), 1);
    char* ri = (char*)cBE_getInterface_9098(*(void**)((char*)D_004A28A8 + 0x78), 7);
    D_00534E58[0] = cBENewPlayerInterface_getPlayerCharID(pi, 0);
    func_0014EBB8(ri, *(int*)(D_004A3028 + 0x98));
    func_0014EBD8(ri, *(int*)(D_004A3028 + 0x80));
    {
        VEnt_9098* vt = *(VEnt_9098**)(ri + 0xC);
        vt[1].fn(ri + vt[1].delta);
    }
    func_002639E0(a0, v, *(int*)(g + 0xB4), a1, a2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00259198);
#ifdef SKIP_ASM
extern char D_004A2F18[];

extern "C" char *func_00259198(void) {
    return D_004A2F18;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002591A8);
#ifdef SKIP_ASM
extern char D_004A2F20[];

extern "C" char *func_002591A8(void) {
    return D_004A2F20;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002591B8);
#ifdef SKIP_ASM
extern void *D_004A28A8;

extern "C" int func_002591B8(void) {
    return (*(int *)((char*)(D_004A28A8) + (0x7C))) + 0xB5AB0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002591D0);
#ifdef SKIP_ASM
extern void *D_004A28A8;

extern "C" int func_002591D0(void) {
    return (*(int *)((char*)(D_004A28A8) + (0x7C))) + 0xB5ABC;
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_002591E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *operator_new_91E8(unsigned int, void *, unsigned int, int) __asm__("operator_new__FUi");
extern char D_004A2F28[];

extern "C" void *func_002591E8(unsigned int size) {
    return operator_new_91E8(size, D_004A2F28, 0x20000000, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00259210);
#ifdef SKIP_ASM
extern "C" void cMemMan_free__FPv();

extern "C" void func_00259210(int arg0) {
    if (arg0 != 0) {
        cMemMan_free__FPv();
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_156860", func_00259230);
#ifdef SKIP_ASM
extern "C" void *func_0039FAE8(int);
extern void *D_004A28A8;

extern "C" void func_00259230(int *arg0) {
    void *obj = *(void **)((char*)D_004A28A8 + 0x7C);
    if (obj != 0) {
        char *o = (char *)func_0039FAE8(*(int *)((char*)obj + 0xC) + 0x18);
        char *vt = *(char **)(o + 8);
        void (*fn)(void *, int, int *) = *(void (**)(void *, int, int *))(vt + 0xC4);
        fn(o + *(short *)(vt + 0xC0), *arg0, arg0);
    }
}
#endif
