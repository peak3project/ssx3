#include "common.h"

//100%
INCLUDE_ASM("seg/seg_21E5A8", func_0031D5A8);
#ifdef SKIP_ASM
// Evaluates the cubic a*t^3 + b*t^2 + c*t + d at t = x - x0.
struct Cubic_D5A8 {
    float a;
    float b;
    float c;
    float d;
    float x0; // 0x10
};
extern "C" float func_0031D5A8(Cubic_D5A8 *p, float x) {
    float t = x - p->x0;
    float a = p->a;
    float b = p->b;
    float c = p->c;
    float d = p->d;
    float t2 = t * t;
    float r = c * t + d;
    r += b * t2;
    return t * a * t2 + r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_21E5A8", func_0031D5E8);
#ifdef SKIP_ASM
struct Flags_D5E8 {
    unsigned int a : 1;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int pad : 8;
    unsigned int d : 8;
    unsigned int rest : 13;
    int w4;
    int w8;
};
extern "C" Flags_D5E8 *func_0031D5E8(Flags_D5E8 *self) {
    self->w8 = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
    return self;
}
#endif

//100%
INCLUDE_ASM("seg/seg_21E5A8", func_0031D618);
#ifdef SKIP_ASM
void func_0031D790(void *);
void operator_delete(int *);
extern "C" void func_0031D618(int *self, int flags) {
    func_0031D790(self);
    if (flags & 1) operator_delete(self);
}
#endif
