#include "visualfx/crowdrender2d.h"
#include <stdint.h>

//100%
//https://decomp.me/scratch/pOTwa

INCLUDE_ASM("visualfx/crowdrender2d", cCrowdRender2D_cCrowdRender2D__Fi);
#ifdef SKIP_ASM
int cCrowdRender2D_cCrowdRender2D(int param_1) {
	cCrowdRender2D_init();
	return param_1;
}
#endif

//100%
//https://decomp.me/scratch/zsTkS
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdRender2D__cCrowdRender2D__FPii);
#ifdef SKIP_ASM
void cCrowdRender2D__cCrowdRender2D(int* param_1, int param_2)
{
	cCrowdRender2D_purge(param_1);

	if ((param_2 & 1) != 0) {
		operator_delete(param_1);
	}

	return;
}
#endif

//100%
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdRender2D_init__Fv);
#ifdef SKIP_ASM
struct sCrowdAnimDef_B6D0 {
    int f0;
    int count;              // 0x04
    char names[16][5];      // 0x08
    char* shapes[16];       // 0x58
    int handles[16];        // 0x98
};
struct sVEnt_B6D0 {
    short delta;
    short index;
    void* fn;
};
typedef int (*tRegister_B6D0)(void*, char*, char*, int, int, int);
typedef void (*tRelease_B6D0)(void*, int);

extern sCrowdAnimDef_B6D0 D_00445D38_B6D0[] __asm__("D_00445D38");
extern char* D_004A5B80;
extern char D_004875C0[];
extern "C" int FILE_load(const char* name, int flags);
extern "C" char* SHAPE_locate(int file, const char* name);
extern "C" int func_002523A8(int file);

// PORT: the unit declares this as void(); defined under an asm label with its real type
extern "C" void cCrowdRender2D_init_impl(int* self) __asm__("cCrowdRender2D_init__Fv");
extern "C" void cCrowdRender2D_init_impl(int* self)
{
    int i;
    self[0] = FILE_load(D_004875C0, 0x5000000);
    for (i = 0; i < 1; i++) {
        int j;
        for (j = 0; j < D_00445D38_B6D0[i].count; j++) {
            char* shape = SHAPE_locate(self[0], D_00445D38_B6D0[i].names[j]);
            D_00445D38_B6D0[i].shapes[j] = shape;
            sVEnt_B6D0* vt = *(sVEnt_B6D0**)(D_004A5B80 + 0x10D8);
            D_00445D38_B6D0[i].handles[j] = ((tRegister_B6D0)vt[46].fn)(D_004A5B80 + vt[46].delta, shape, D_00445D38_B6D0[i].names[j], 0, 0, -1);
        }
    }
    char* first = D_00445D38_B6D0[0].shapes[0];
    self[1] = *(short*)(first + 4);
    self[2] = *(short*)(first + 6);
    self[3] = *(unsigned char*)first;
}
#endif

//100%
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdRender2D_purge__FPi);
#ifdef SKIP_ASM
int cCrowdRender2D_purge(int* self)
{
    int i;
    for (i = 0; i < 1; i++) {
        int j;
        for (j = 0; j < D_00445D38_B6D0[i].count; j++) {
            sVEnt_B6D0* vt = *(sVEnt_B6D0**)(D_004A5B80 + 0x10D8);
            ((tRelease_B6D0)vt[50].fn)(D_004A5B80 + vt[50].delta, D_00445D38_B6D0[i].handles[j]);
        }
    }
    return func_002523A8(self[0]);
}
#endif

//100%
//https://decomp.me/scratch/Rbiv4
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdRender2D_constructCrowdAnim2D__FPv);
#ifdef SKIP_ASM

extern "C" void* cMemMan_alloc(int a, const char* b, uint32_t c, int d);

void* cCrowdRender2D_constructCrowdAnim2D(void* param) {
	void* memory = cMemMan_alloc(0x20, D_004875D8, 0x20000000, 0);
	return cCrowdAnim2D_cCrowdAnim2D(memory, param);
}
#endif

//100%
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdAnim2D_cCrowdAnim2D__FPvT0);
#ifdef SKIP_ASM
struct sCrowdAnim2D {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    void* f1C;
};

extern int D_00445DD0[];
extern char* D_004A5B64;

void* cCrowdAnim2D_cCrowdAnim2D(void* memory, void* param_1)
{
    sCrowdAnim2D* a = (sCrowdAnim2D*)memory;
    a->f1C = param_1;
    a->f8 = 4;
    a->f4 = 0;
    a->fC = 0;
    a->f10 = D_00445DD0[0];
    a->f0 = 0;
    a->f18 = *(int*)(D_004A5B64 + 0x1C);
    a->f14 = 3;
    return a;
}
#endif

//100%
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdAnim2D_advanceFrame);
#ifdef SKIP_ASM
// Steps a crowd animation frame for the current play mode and returns the new frame.
extern "C" int cCrowdAnim2D_advanceFrame(void* self, int frame, int n, int* mode)
{
    switch (*mode) {
    case 0:
        frame++;
        if (frame >= n) {
            frame = n - 1;
        }
        break;
    case 1:
        frame--;
        if (frame < 0) {
            frame = 0;
        }
        break;
    case 2:
        if (n == 1) {
            break;
        }
        frame++;
        if (frame >= n) {
            *mode = 3;
            frame = n - 2;
        }
        break;
    case 3:
        if (n == 1) {
            break;
        }
        frame--;
        if (frame < 0) {
            *mode = 2;
            frame = 1;
        }
        break;
    case 4:
        if (n == 1) {
            break;
        }
        frame++;
        if (frame >= n) {
            frame = 0;
        }
        break;
    }
    return frame;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("visualfx/crowdrender2d", cCrowdAnim2D_update);
#ifdef SKIP_ASM
struct sCrowdAnimDef_BAC0 {
    int f0;
    int count;              // 0x4
    char pad_0x8[0x90];
    int frames[16];         // 0x98
};

struct sCrowdTrans_BAC0 {
    int anim;
    int mode;
    int kind;
};

extern sCrowdAnimDef_BAC0 D_00445D38[];
extern sCrowdTrans_BAC0 D_00445E10[];
extern int D_00445E20[];
extern "C" int cCrowdAnim2D_advanceFrame(void* self, int frame, int count, int* dir);

struct sCrowdAnim2D_BAC0 {
    int type;               // 0x0
    int anim;               // 0x4
    int dir;                // 0x8
    int frame;              // 0xC
    int tex;                // 0x10
    int delay;              // 0x14
    int last;               // 0x18
    void* param;            // 0x1C
};

extern "C" void cCrowdAnim2D_update(sCrowdAnim2D_BAC0* self)
{
    int now = *(int*)(D_004A5B64 + 0x1C);
    if (now - self->last < self->delay) {
        return;
    }
    self->last = now;
    sCrowdTrans_BAC0* base = &D_00445E10[D_00445E20[self->type]];
    // PORT: int arithmetic on the table address (matches the original operand order).
    sCrowdTrans_BAC0* tr = (sCrowdTrans_BAC0*)(self->anim * (int)sizeof(sCrowdTrans_BAC0) + (int)base);
    if (tr->anim == self->anim) {
        self->frame = cCrowdAnim2D_advanceFrame(self, self->frame, D_00445D38[tr->anim].count, &self->dir);
    } else {
        switch (tr->kind) {
        case 0: {
            int* dir = &self->dir;
            if (*dir == 0) {
                *dir = 1;
            }
            if (self->frame == 0) {
                self->anim = tr->anim;
                self->dir = tr->mode;
                if (self->dir == 1) {
                    self->frame = D_00445D38[self->anim].count - 1;
                } else {
                    self->frame = 0;
                }
            } else {
                self->frame = cCrowdAnim2D_advanceFrame(self, self->frame, D_00445D38[self->anim].count, dir);
            }
            break;
        }
        case 1: {
            int* dir = &self->dir;
            if (*dir == 1) {
                *dir = 0;
            }
            int cnt = D_00445D38[self->anim].count;
            if (self->frame == cnt - 1) {
                self->anim = tr->anim;
                self->dir = tr->mode;
                if (self->dir == 1) {
                    self->frame = D_00445D38[self->anim].count - 1;
                } else {
                    self->frame = 0;
                }
            } else {
                self->frame = cCrowdAnim2D_advanceFrame(self, self->frame, cnt, dir);
            }
            break;
        }
        case 2:
            self->anim = tr->anim;
            self->dir = tr->mode;
            self->frame = cCrowdAnim2D_advanceFrame(self, self->frame, D_00445D38[self->anim].count, &self->dir);
            break;
        }
    }
    self->tex = D_00445D38[self->anim].frames[self->frame];
}
#endif

