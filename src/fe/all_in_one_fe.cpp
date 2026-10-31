#include "common.h"

INCLUDE_ASM("fe/all_in_one_fe", __sti__all_in_one_fe_cpp);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C640);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_xi(void*, int) __asm__("func_0039E2A0");
extern char D_00474E08[];
extern "C" void* func_0021C640(void *self) {
    func_0039E2A0_xi(self, 0);
    *(char**)((char*)self + 8) = D_00474E08;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C678);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021C678(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C6D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C6D8(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C700);
#ifdef SKIP_ASM
extern "C" int func_0021C700(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x4C)));
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C708);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C708(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C730);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00474D30[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021C730(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474D30;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C798);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C798(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C7C0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00474C58[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021C7C0(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474C58;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C828);
#ifdef SKIP_ASM
extern "C" void func_0020E900();

extern "C" void func_0021C828(void) {
    func_0020E900();
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C848);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C848(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C870);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C870(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C898);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00474AA8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021C898(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474AA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C900(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C928);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C928(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C950);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_C950(void*) __asm__("func_0039E2A0");
extern char D_004748F8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021C950(void *arg0, int arg1, int arg2) {
    func_0039E2A0_C950(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004748F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0x9C))) = 1;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C9C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C9C0(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021C9E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021C9E8(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CA10(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CA38(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CA60(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CA88);
#ifdef SKIP_ASM
extern "C" void func_0039E390(void *, int);

extern "C" void func_0021CA88(void *self, int flags) {
    func_0039E390(self, flags);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CAA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_x(void*) __asm__("func_0039E2A0");
extern char D_004743F0[];
extern "C" void* func_0021CAA8(void *self) {
    func_0039E2A0_x(self);
    *(char**)((char*)self + 8) = D_004743F0;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CAE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CAE0(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_xi(void*, int) __asm__("func_0039E2A0");
extern char D_00474248[];
extern "C" void* func_0021CB08(void *self) {
    func_0039E2A0_xi(self, 0);
    *(char**)((char*)self + 8) = D_00474248;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474248[];

extern "C" void func_0021CB40(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474248;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB68);
#ifdef SKIP_ASM
extern "C" int func_0021CB68(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB70);
#ifdef SKIP_ASM
extern "C" void func_0021CB70(int *p) {
    p[0]=1;
    p[1]=0;
    p[2]=0;
    p[3]=0;
    p[4]=0;
    p[5]=0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB90);
#ifdef SKIP_ASM
extern int D_004A275C;

extern "C" void func_0021CB90(int arg0) {
    D_004A275C = arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CB98);
#ifdef SKIP_ASM
extern int D_004A275C;

extern "C" int func_0021CB98(void) {
    return D_004A275C;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CBA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_CBA0(void*, int) __asm__("func_0039E2A0");
extern "C" void func_0020EAA0(void*);
extern char D_00474160[];
struct sElem_CBA0 {
    void* operator new[](unsigned int, void* p) { return p; }
    char pad[8];
    char sub[0x84];
    sElem_CBA0() { func_0020EAA0(sub); }
};

extern "C" void *func_0021CBA0(void *arg0) {
    char* self = (char*)arg0;
    func_0039E2A0_CBA0(self, 0);
    *(char**)(self + 8) = D_00474160;
    new (self + 0x48) sElem_CBA0[2];
    *(int*)(self + 0x474) = -1;
    *(float*)(self + 0x478) = 1.0f;
    *(float*)(self + 0x47C) = 1.0f;
    *(int*)(self + 0x480) = 0;
    *(int*)(self + 0x484) = 0;
    *(float*)(self + 0x488) = 1.0f;
    *(float*)(self + 0x48C) = 1.0f;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CC40);
#ifdef SKIP_ASM
extern "C" void func_0020EB08(void *, int);
extern char D_00474160[];

extern "C" void func_0021CC40(void *arg0, int arg1) {
    (*(char **)((char*)(arg0) + (8))) = D_00474160;
    if ((char*)arg0 + 0x48 != 0) {
        char *p = (char*)arg0 + 0x48 + 0x118;
        while ((char*)arg0 + 0x48 != p) {
            p -= 0x8C;
            func_0020EB08(p + 8, 2);
        }
    }
    func_0039E390(arg0, arg1);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CCC8);
#ifdef SKIP_ASM
extern "C" unsigned char *func_0021CCC8(unsigned char *arg0) {
    *arg0 &= 0xF0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CCE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CCE0(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD08);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00474088[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021CD08(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00474088;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CD70(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CD98);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473FB0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021CD98(void *arg0, int arg1, int arg2) {
    func_0039E2A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473FB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CE00(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_CE28(void*) __asm__("func_0039E2A0");
extern char D_00473ED8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021CE28(void *arg0, int arg1, int arg2) {
    func_0039E2A0_CE28(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473ED8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CE90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CE90(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CEB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_CEB8(void*) __asm__("func_0039E2A0");
int GetHashValue32(char*);
extern char D_00473E00[];
extern char D_00474E08[];
extern char D_0046E340[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021CEB8(void *arg0, int arg1, int arg2) {
    func_0039E2A0_CEB8(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(char **)((char*)(arg0) + (8))) = D_00473E00;
    (*(int *)((char*)(arg0) + (0xC))) = GetHashValue32(D_0046E340);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CF38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CF38(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CF60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_CF60(void*) __asm__("func_0039E2A0");
int GetHashValue32(char*);
extern char D_00473D28[];
extern char D_00474E08[];
extern char D_0046E340[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021CF60(void *arg0, int arg1, int arg2) {
    func_0039E2A0_CF60(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(char **)((char*)(arg0) + (8))) = D_00473D28;
    (*(int *)((char*)(arg0) + (0xC))) = GetHashValue32(D_0046E340);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021CFE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021CFE0(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D008);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_D008(void*) __asm__("func_0039E2A0");
extern char D_00473C50[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021D008(void *arg0, int arg1, int arg2) {
    func_0039E2A0_D008(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473C50;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D070);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473B78[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021D070(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473B78;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D0D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_D0D0(void*) __asm__("func_0039E2A0");
extern char D_00473B78[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_0021D0D0(void *arg0, int arg1, int arg2) {
    func_0039E2A0_D0D0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473B78;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_0021D138(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021D160);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define func_0021D160_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" void func_00391C48(int, int, char*);

extern "C" void func_0021D160(float x, float y, int c, int d, ...) {
    char* ap;
    func_0021D160_va_start(ap);
    func_00391C48(c, d, ap);
}
#endif

INCLUDE_ASM("fe/all_in_one_fe", func_0021D1A0);

INCLUDE_ASM("fe/all_in_one_fe", func_0021D9A0);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E1B0);
#ifdef SKIP_ASM
struct V2_E1B0 { float x, y; };
struct V4_E1B0 { float x, y, z, w; };
struct Ctx_E1B0 { char pad[0xE84]; char* e84; };
extern Ctx_E1B0* D_004A289C_E1B0 __asm__("D_004A289C");
extern char* D_004A28A8_E1B0 __asm__("D_004A28A8");
extern float D_00504FB8_E1B0[] __asm__("D_00504FB8");
extern char D_00477F30[];
extern int D_00535BF8[];
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv_E1B0(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001E91F8(void*, void*);
extern "C" void func_001E9220(void*, void*, int);
void func_001E9290_E1B0(void*, void*) __asm__("func_001E9290__FPvT0");
void func_001E91A8_E1B0(void*, void*) __asm__("func_001E91A8__FPvT0");
extern "C" void func_001F10F8(void*, void*, void*, void*, void*, int, int, int);
extern "C" void func_001F1190(void*, int, void*, void*, void*, void*);
extern "C" void func_0021E7E0_E1B0(char* self, V4_E1B0* colp, V2_E1B0* pos, V2_E1B0* size,
                                   float t, float sx, float sy, float amin, float amax) __asm__("func_0021E7E0");

extern "C" void func_0021E1B0(char* self, char* obj, int* rider, int x)
{
    V2_E1B0 scale;
    V4_E1B0 col;
    V2_E1B0 sc;
    V4_E1B0 a;
    V2_E1B0 size1;
    V2_E1B0 size2;
    V2_E1B0 dim;
    V2_E1B0 p;
    V4_E1B0 c2;
    V2_E1B0 size3;
    V2_E1B0 tmp;
    V2_E1B0 pa;
    V2_E1B0 sa;
    V2_E1B0 sb;
    scale.x = 1.0f;
    scale.y = 1.0f;
    float k = 1.0f;
    char* r = *(char**)(*(char**)(*(char**)(D_004A28A8_E1B0 + 0x84) + 0xC) + (rider[0] << 2) + 0x28);
    func_001E91A8_E1B0(D_00477F30 + *(int*)(r + 0xEC) * 0x24, &col);
    float t = ((float*)rider)[0x12];
    if (t >= 0.0f) {
        if (*(int*)(r + 0xEC) == 0) {
            k = D_00504FB8_E1B0[(int)(t * 12.566370964050293f * 81.4873275756836f) & 0x1FF] * 0.199636310338974f * (1.0f - t * t) + k;
        } else {
            col.x = col.x * (t * 0.5f + 0.5f);
        }
    }
    func_001E9290_E1B0(obj + 0x360, &sc);
    int* tex = (int*)(self + 0x444);
    func_001E91F8(obj + 0x360, &a);
    func_001E9220(D_00477F30 + 0xD8, &size1, 0);
    size1.x *= sc.x;
    size1.y *= sc.y;
    int off = *(int*)(r + 0xEC) << 2;
    func_001E9220(D_00477F30 + *(int*)(r + 0xEC) * 0x24, &size2, *(int*)((char*)tex + off));
    size2.x *= sc.x;
    size2.y *= sc.y;
    dim.x = size2.x + size1.x;
    dim.y = size2.y;
    func_001F10F8(self, &p, &a, &dim, &scale, obj[0x380], obj[0x381], x);
    p.x += size2.x;
    p.y += size1.y;
    int* w = (int*)(D_004A289C_E1B0->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0x382] << 5) & 0x3E0);
    func_001E91A8_E1B0(D_00477F30 + 0xFC, &c2);
    func_001E9220(D_00477F30 + 0xFC, &size3, 0);
    size3.x *= sc.x;
    size3.y *= sc.y;
    func_001F1190(self, *(int*)(self + 0x46C), &p, &size3, &scale, &c2);
    p.x += size3.x;
    func_001E91A8_E1B0(D_00477F30 + 0x120, &c2);
    func_001E9220(D_00477F30 + 0x120, &size3, 0);
    cBE_getInterface_Fv_E1B0(cBE_getBE(), 0);
    int off3 = (D_00535BF8[0] - 1) << 2;
    func_001F1190(self, *(int*)((char*)tex + off3), &p, &size3, &sc, &c2);
    if (k != 1.0f) {
        size2.x *= k;
        size2.y *= k;
        size1.x *= k;
        size1.y *= k;
        dim.x *= k;
        dim.y *= k;
    }
    func_001F10F8(self, &p, &a, &dim, &scale, obj[0x380], obj[0x381], x);
    w = (int*)(D_004A289C_E1B0->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0x382] << 5) & 0x3E0);
    int off4 = *(int*)(r + 0xEC) << 2;
    func_001F1190(self, *(int*)((char*)tex + off4), &p, &size2, &scale, &col);
    signed char n = *(int*)(r + 0xEC) < 4 ? *(int*)(r + 0xEC) : 3;
    tmp = p;
    int off5 = n * 4;
    int tx = *(int*)(self + off5 + 0x45C);
    tmp.x += size2.x;
    func_001F1190(self, tx, &tmp, &size1, &scale, &col);
    if (((float*)rider)[0x13] >= 0.0f) {
        w = (int*)(D_004A289C_E1B0->e84 + 8);
        *w = (*w & ~0x3E0) | (((obj[0x382] - 1) << 5) & 0x3E0);
        pa = p;
        sa = size2;
        func_0021E7E0_E1B0(self, &col, &pa, &sa, ((float*)rider)[0x13], 1.8101750612258911f, 1.8101750612258911f, 0.5f, 1.0f);
        pa = tmp;
        sb = size1;
        func_0021E7E0_E1B0(self, &col, &pa, &sb, ((float*)rider)[0x13], 1.8101750612258911f, 1.8101750612258911f, 0.5f, 1.0f);
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E750);
#ifdef SKIP_ASM
extern "C" float func_0021E750(int unused, int a, int flags, float x, float y, float z) {
    int v = a;
    if (flags & 1) {
        x = 640.0f - x;
        v = (flags & 2) ? a : -v;
    }
    if (v == 0) {
        x -= z * y * 0.5f;
    } else if (v > 0) {
        x -= z * y;
    }
    return x;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E7A8);
#ifdef SKIP_ASM
extern "C" float func_0021E7A8(int arg0, int mode, float a, float b, float c) {
    if (mode == 0) {
        a -= c * b * 0.5f;
    } else if (mode > 0) {
        a -= c * b;
    }
    return a;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021E7E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Col_E7E0 { float r, g, b, a; };
struct Ctx_E7E0 { char pad[0xE84]; char* e84; };
extern Ctx_E7E0* D_004A289C;
extern "C" void func_0021EA00_E7E0(void* self, Col_E7E0* col, float* pos, float w, float h, float u0, float v0, float u1, float v1) __asm__("func_0021EA00");

extern "C" void func_0021E7E0(char* self, Col_E7E0* colp, float* pos, float* size,
                              float t, float sx, float sy, float amin, float amax) {
    Col_E7E0 col = *colp;
    Col_E7E0* c = &col;
    float dw, dh;
    float range = amax - amin;
    c->r = c->r * (amin + (t > 1.0f ? range * (2.0f - t) : range * t));
    dw = size[0] * (sx - 1.0f);
    dh = size[1] * (sy - 1.0f);
    pos[0] -= dw * 0.5f;
    pos[1] -= dh * 0.5f;
    size[0] += dw;
    size[1] += dh;
    int id = *(int*)(self + 0x474);
    *(short*)(D_004A289C->e84 + 0x10) = id;
    if (size[0] > 72.0f) {
        float mid = (*(float*)(self + 0x484) + *(float*)(self + 0x488)) * 0.5f;
        func_0021EA00_E7E0(self, c, pos, 36.0f, size[1], *(float*)(self + 0x484), *(float*)(self + 0x480), mid, *(float*)(self + 0x48C));
        pos[0] += 36.0f;
        func_0021EA00_E7E0(self, c, pos, size[0] - 72.0f, size[1], mid, *(float*)(self + 0x480), mid, *(float*)(self + 0x48C));
        pos[0] += size[0] - 72.0f;
        func_0021EA00_E7E0(self, c, pos, 36.0f, size[1], mid, *(float*)(self + 0x480), *(float*)(self + 0x488), *(float*)(self + 0x48C));
    } else {
        func_0021EA00_E7E0(self, c, pos, size[0], size[1], *(float*)(self + 0x484), *(float*)(self + 0x480), *(float*)(self + 0x488), *(float*)(self + 0x48C));
    }
}
#endif

INCLUDE_ASM("fe/all_in_one_fe", func_0021EA00);

INCLUDE_ASM("fe/all_in_one_fe", func_0021ED48);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F338);
#ifdef SKIP_ASM
struct V2_F338 { float x, y; };
struct V4_F338 { float x, y, z, w; };
extern V4_F338 D_004C8568;
extern V4_F338 D_004C8588;
extern V4_F338 D_004C85A8;
extern V4_F338 D_004C85C8;
extern V4_F338 D_004C85E8;
extern "C" void func_001E91F8(void*, void*);
extern "C" void func_001E9220(void*, void*, int);
void func_001E9290(void*, void*);
extern "C" void func_001F10F8(void*, void*, void*, void*, void*, int, int, int);
extern "C" void func_001F1190(void*, int, void*, void*, void*, void*);

extern "C" void func_0021F338(char* self, char* obj, int n, int x, V2_F338* pos, V2_F338* scale, float alpha) {
    if (n > 0) {
        V4_F338 cols[5];
        V4_F338 a;
        V2_F338 p;
        V2_F338 size;
        V2_F338 sc;
        V2_F338 dim;
        V4_F338 col;
        float step;
        int i;
        cols[0] = D_004C8568;
        cols[1] = D_004C8588;
        cols[2] = D_004C85A8;
        cols[3] = D_004C85C8;
        cols[4] = D_004C85E8;
        func_001E91F8(obj + 0x240, &a);
        func_001E9220(obj + 0x240, &size, *(int*)(self + 0x4A0));
        func_001E9290(obj + 0x240, &sc);
        if (scale) {
            sc.x *= scale->x;
            sc.y *= scale->y;
        }
        if (pos == 0) {
            dim.x = size.x * n + (n - 1) * 2.0f;
            dim.y = size.y;
            func_001F10F8(self, &p, &a, &dim, &sc, obj[0x260], obj[0x261], x);
        } else {
            p = *pos;
            p.x -= (size.x * n + (n - 1) * 2.0f) * sc.x * 0.5f;
            p.y -= size.y * sc.y * 0.5f;
        }
        int* w = (int*)(D_004A289C->e84 + 8);
        *w = (*w & ~0x3E0) | ((obj[0x262] << 5) & 0x3E0);
        step = (size.x + 2.0f) * sc.x;
        col = cols[n - 1];
        col.x *= alpha;
        for (i = 0; i < n; i++) {
            func_001F1190(self, *(int*)(self + 0x4A0), &p, &size, &sc, &col);
            p.x += step;
        }
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F660);
#ifdef SKIP_ASM
struct V2_F660 { float x, y; };
struct V4_F660 { float x, y, z, w; };
struct Obj_F660 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
extern char* D_004A28A8;
extern signed char D_00535C10[];
extern int D_00536640[];
extern char D_0046ED68[];
extern char D_004A2138[];
extern V4_F660 D_004C8808;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001E91F8(void*, void*);
extern "C" void func_001E9220(void*, void*, int);
void func_001E9290(void*, void*);
void func_001E91A8(void*, void*);
extern "C" void func_001F10F8(void*, void*, void*, void*, void*, int, int, int);
extern "C" void func_001F1190(void*, int, void*, void*, void*, void*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_00392908(void*, float, float, char*);

extern "C" void func_0021F660(char* self, int elems, int* rider, int x, int flag) {
    V2_F660 scale;
    V2_F660 p;
    V4_F660 a;
    V2_F660 size;
    V2_F660 sc;
    V4_F660 c;
    char buf[64];
    V4_F660 col;
    int idx = 0x42;
    char* r = *(char**)(*(char**)(*(char**)(D_004A28A8 + 0x84) + 0xC) + (*rider << 2) + 0x28);
    int sz = *(int*)(self + 0x4B4);
    if (flag) {
        sz = *(int*)(self + 0x49C);
        idx = 0x1B;
    }
    char* e = (char*)(idx * 0x24 + elems); // PORT: pointer passed as int
    scale.x = 1.0f;
    scale.y = 1.0f;
    func_001E91F8(e, &a);
    func_001E9220(e, &size, sz);
    func_001E9290(e, &sc);
    size.x *= sc.x;
    size.y *= sc.y;
    func_001F10F8(self, &p, &a, &size, &scale, e[0x20], e[0x21], x);
    func_001E91A8(e, &c);
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((e[0x22] << 5) & 0x3E0);
    func_001F1190(self, sz, &p, &size, &scale, &c);
    if (flag == 0) {
        cBE_getInterface_Fv(cBE_getBE(), 0);
        signed char mode = D_00535C10[0];
        Obj_F660* o = (Obj_F660*)(r + 0x6C0);
        int k = o->v07();
        int val = D_00536640[k];
        if (mode == 0 || mode == 5) {
            int t = (int)((float)val * 0.01666666753590107f);
            int rem = t % 3600;
            sprintf(buf, D_0046ED68, t / 3600, rem / 60, rem % 60);
        } else {
            sprintf(buf, D_004A2138, val + rider[0x7C / 4]);
        }
        char* t = *(char**)(self + 0x42C);
        p.x += size.x * 0.5f;
        p.y += size.y;
        sc.x *= 1.907578468322754f;
        sc.y *= 1.907578468322754f;
        *(float*)(t + 0x38) = *(float*)(t + 0x30) * sc.x;
        *(float*)(t + 0x3C) = *(float*)(t + 0x34) * sc.y;
        col = D_004C8808;
        *(V4_F660*)(*(char**)(self + 0x42C) + 0x40) = col;
        func_00392908(*(char**)(self + 0x42C), p.x, p.y, buf);
        t = *(char**)(self + 0x42C);
        *(float*)(t + 0x38) = *(float*)(t + 0x30) * scale.x;
        *(float*)(t + 0x3C) = *(float*)(t + 0x34) * scale.y;
    }
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_0021F9B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V2_F9B0 { float x, y; };
struct V4_F9B0 { float x, y, z, w; };
struct Obj_F9B0 {
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int v07();
};
extern char* D_004A28A8;
extern float D_00504FB8[];
extern V4_F9B0 D_004C8648;
extern char D_004A2300[];
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001E91F8(void*, void*);
extern "C" void func_001E9220(void*, void*, int);
void func_001E9290(void*, void*);
void func_001E91A8(void*, void*);
extern "C" void func_001F10F8(void*, void*, void*, void*, void*, int, int, int);
extern "C" void func_001F1190(void*, int, void*, void*, void*, void*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" int func_0022D390(void*, int);
extern "C" int func_00153520(void*, int, int);
extern "C" int func_00153350(void*, int);
extern "C" void func_00391CB0(void*, float, float, char*);

extern "C" void func_0021F9B0(char* self, char* obj, char* rider, int x, float t) {
    V2_F9B0 scale;
    V2_F9B0 p;
    V4_F9B0 a;
    V2_F9B0 size;
    V2_F9B0 sc;
    V4_F9B0 col;
    char buf[64];
    char* m = *(char**)(*(char**)(D_004A28A8 + 0x84) + 0x78);
    int id = *(int*)(m + 0x1BC);
    if (func_0022D390(m, id)) {
        float s = 1.0f;
        scale.x = 1.0f;
        scale.y = 1.0f;
        void* iface = cBE_getInterface_Fv(cBE_getBE(), 10);
        if (t < 0.4399542808532715f) {
            float u = t * 2.272963523864746f;
            s = D_00504FB8[(int)(u * 12.566370964050293f * 81.4873275756836f) & 0x1FF] * 0.19996199011802673f * (1.0f - u * u) + 1.0f;
        }
        func_001E91F8(obj + 0x804, &a);
        func_001E9220(obj + 0x804, &size, *(int*)(self + 0x4A8));
        func_001E9290(obj + 0x804, &sc);
        size.x *= s;
        size.y *= s;
        sc.x *= s;
        sc.y *= s;
        func_001F10F8(self, &p, &a, &size, &scale, obj[0x824], obj[0x825], x);
        int* w = (int*)(D_004A289C->e84 + 8);
        *w = (*w & ~0x3E0) | ((obj[0x826] << 5) & 0x3E0);
        col.x = 1.0f;
        col.y = 1.0f;
        col.z = 1.0f;
        col.w = 1.0f;
        func_001F1190(self, *(int*)(self + 0x4A8), &p, &size, &scale, &col);
        char* tx = *(char**)(self + 0x42C);
        p.x += size.x;
        p.y += (size.y - (float)*(int*)(tx + 0x14) * *(float*)(tx + 0x34) * sc.y) * 0.5f;
        if (t > 0.4399542808532715f) {
            func_001E91A8(obj + 0x804, &col);
        } else {
            col = D_004C8648;
        }
        char* tx2 = *(char**)(self + 0x42C);
        *(float*)(tx2 + 0x38) = *(float*)(tx2 + 0x30) * sc.x;
        *(float*)(tx2 + 0x3C) = *(float*)(tx2 + 0x34) * sc.y;
        *(V4_F9B0*)(*(char**)(self + 0x42C) + 0x40) = col;
        Obj_F9B0* o = (Obj_F9B0*)(rider + 0x6C0);
        sprintf(buf, D_004A2300, func_00153520(iface, o->v07(), id), func_00153350(iface, id));
        func_00391CB0(*(char**)(self + 0x42C), p.x, p.y, buf);
        tx = *(char**)(self + 0x42C);
        *(float*)(tx + 0x38) = *(float*)(tx + 0x30) * scale.x;
        *(float*)(tx + 0x3C) = *(float*)(tx + 0x34) * scale.y;
    }
}
#endif

INCLUDE_ASM("fe/all_in_one_fe", func_0021FD38);

INCLUDE_ASM("fe/all_in_one_fe", func_002200C0);

INCLUDE_ASM("fe/all_in_one_fe", func_002204A0);

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220AD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V2_0AD0 { float x, y; };
struct V4_0AD0 { float x, y, z, w; };
struct Big_0AD0 { unsigned int pad0 : 20; unsigned int mode : 2; unsigned int pad1 : 10; int rest[0xA1]; };
struct Bits_0AD0 { int a, b; unsigned int lo : 5; int v : 5; unsigned int hi : 22; };
struct Glob_0AD0 { char pad[0x504]; int f504; };
extern Big_0AD0 D_00535610;
extern Glob_0AD0* D_004A28A4;
extern "C" void* cBE_getBE();
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_001E91F8(void*, void*);
void func_001E9290(void*, void*);
void func_001E91A8(void*, void*);
extern "C" void func_001E95A0(void*, void*, void*, void*, int, int);

extern "C" void func_00220AD0(char* self, char* obj, float t) {
    V2_0AD0 a;
    V4_0AD0 b;
    Big_0AD0 big;
    V4_0AD0 c;
    V2_0AD0 d;
    V2_0AD0 e;
    void* p = obj + 0xAD4;
    func_001E91F8(p, &a);
    func_001E9290(p, &b);
    cBE_getInterface_Fv(cBE_getBE(), 4);
    big = D_00535610;
    if (D_004A28A4->f504 != 0 && big.mode != 2) {
        b.y *= 0.75f;
        a.y -= 60.0f;
    }
    func_001E91A8(obj + 0xAD4, &c);
    if (t <= 0.5f) {
        c.x *= t * 2.0f;
    } else {
        c.x *= (1.0f - t) * 2.0f;
    }
    d.x = 2.0f;
    d.y = 2.0f;
    *(V2_0AD0*)(*(char**)(self + 0xB50) + 0x28) = d;
    int* w = (int*)(D_004A289C->e84 + 8);
    *w = (*w & ~0x3E0) | ((obj[0xAF6] << 5) & 0x3E0);
    e = a;
    func_001E95A0(self + 0xB48, &e, &b, &c, obj[0xAF4], obj[0xAF5]);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_xi(void*, int) __asm__("func_0039E2A0");
extern char D_00473AA8[];
extern "C" void* func_00220D38(void *self) {
    func_0039E2A0_xi(self, 0);
    *(char**)((char*)self + 8) = D_00473AA8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_0046D0D0[];

extern "C" void func_00220D70(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220D98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_xi(void*, int) __asm__("func_0039E2A0");
extern char D_004739D8[];
extern "C" void* func_00220D98(void *self) {
    func_0039E2A0_xi(self, 0);
    *(char**)((char*)self + 8) = D_004739D8;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220DD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_0046D0D0[];

extern "C" void func_00220DD0(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220DF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E2A0_xi(void*, int) __asm__("func_0039E2A0");
extern char D_00473908[];
extern "C" void* func_00220DF8(void *self) {
    func_0039E2A0_xi(self, 0);
    *(char**)((char*)self + 8) = D_00473908;
    return self;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_0046D0D0[];

extern "C" void func_00220E30(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E58);
#ifdef SKIP_ASM
extern "C" void* func_0039E2A0(void*, ...);
extern char D_00473838[];

extern "C" void *func_00220E58(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00473838;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220E90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_0046D0D0[];

extern "C" void func_00220E90(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_0046D0D0;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220EB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_00220EB8(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220EE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_0EE0(void*) __asm__("func_0039E2A0");
extern char D_00473760[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00220EE0(void *arg0, int arg1, int arg2) {
    func_0039E2A0_0EE0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473760;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220F48);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473688[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00220F48(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473688;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00220FA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001F7548(void*);
extern void *func_0039E2A0_0FA8(void*) __asm__("func_0039E2A0");
extern char D_00473688[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00220FA8(void *arg0, int arg1, int arg2) {
    func_0039E2A0_0FA8(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473688;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_001F7548(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_00221018(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221040);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_004735B0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221040(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004735B0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002210A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_001F7738(void*);
extern void *func_0039E2A0_10A0(void*) __asm__("func_0039E2A0");
extern char D_004735B0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002210A0(void *arg0, int arg1, int arg2) {
    func_0039E2A0_10A0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004735B0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_001F7738(arg0);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221110);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_00221110(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_0039E390_a(void *) __asm__("func_0039E390");
extern char D_00474E08[];

extern "C" void func_00221138(void *arg0) {
    *(char **)((char*)arg0 + 8) = D_00474E08;
    func_0039E390_a(arg0);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221160);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1160(void*) __asm__("func_0039E2A0");
extern char D_004734D0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221160(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1160(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004734D0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002211C8);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_004733F8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002211C8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004733F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221228);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void *func_002006B8(void*);
extern void *func_0039E2A0_1228(void*) __asm__("func_0039E2A0");
extern char D_004733F8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221228(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1228(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004733F8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    func_002006B8((char*)arg0 + 0x9C);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221298);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221298(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

extern "C" void func_002212C0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002212C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_12C8(void*, int) __asm__("func_0039E2A0");
extern char D_00473320[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];
inline void* operator new[](unsigned int, void* p) { return p; }
struct Elem { Elem() {} };

extern "C" void *func_002212C8(void *arg0) {
    func_0039E2A0_12C8(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473320;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    new ((char*)arg0 + 0x9C) Elem[8];
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221350);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1350(void*, int) __asm__("func_0039E2A0");
extern char D_00473320[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221350(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1350(arg0, arg1);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473320;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    new ((char*)arg0 + 0x9C) Elem[8];
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002213D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002213D8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

extern "C" void func_00221400(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221408);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473248[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221408(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473248;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221468);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1468(void*) __asm__("func_0039E2A0");
extern char D_00473248[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221468(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1468(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473248;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002214D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002214D0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002214F8);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473170[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002214F8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473170;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221558);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1558(void*) __asm__("func_0039E2A0");
extern char D_00473170[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221558(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1558(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473170;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002215C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002215C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002215F0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00473098[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002215F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473098;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221658);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1658(void*) __asm__("func_0039E2A0");
extern char D_00473098[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221658(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1658(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00473098;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002216C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002216C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002216F0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472FC0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002216F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472FC0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221758);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1758(void*) __asm__("func_0039E2A0");
extern char D_00472FC0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221758(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1758(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472FC0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002217C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002217C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002217F0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472EE8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002217F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472EE8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221858);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1858(void*) __asm__("func_0039E2A0");
extern char D_00472EE8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221858(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1858(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472EE8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002218C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002218C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002218F0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472E10[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002218F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472E10;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221958);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1958(void*) __asm__("func_0039E2A0");
extern char D_00472E10[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221958(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1958(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472E10;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002219C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002219C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002219F0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472D38[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002219F0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472D38;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221A58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1A58(void*) __asm__("func_0039E2A0");
extern char D_00472D38[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221A58(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1A58(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472D38;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221AC8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221AF0);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472C60[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221AF0(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472C60;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221B58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1B58(void*) __asm__("func_0039E2A0");
extern char D_00472C60[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221B58(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1B58(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472C60;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221BC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221BC8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221BF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221BF0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221C18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1C18(void*) __asm__("func_0039E2A0");
extern char D_00472B88[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221C18(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1C18(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472B88;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221C80);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00472AB0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221C80(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472AB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221CE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1CE0(void*) __asm__("func_0039E2A0");
extern char D_00472AB0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221CE0(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1CE0(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472AB0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    (*(int *)((char*)(arg0) + (0xA0))) = 1;
    (*(int *)((char*)(arg0) + (0x9C))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221D58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221D58(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

extern "C" void func_00221D80(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221D88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_x(void*) __asm__("func_001D5428");
extern char D_00472928[];
extern "C" void* func_00221D88(void *self) {
    *(char**)((char*)self + 8) = D_00472928;
    return func_001D5428_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221DB0);
#ifdef SKIP_ASM
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern char D_00472928[];

extern "C" void *func_00221DB0(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00472928;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221DF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221DF0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221E18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1E18(void*) __asm__("func_0039E2A0");
extern char D_00472850[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221E18(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1E18(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472850;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221E80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221E80(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221EA8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1EA8(void*) __asm__("func_0039E2A0");
extern char D_00472778[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221EA8(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1EA8(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472778;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221F10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221F10(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221F38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1F38(void*) __asm__("func_0039E2A0");
extern char D_004726A0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221F38(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1F38(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004726A0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221FA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_00221FA0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00221FC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_1FC8(void*) __asm__("func_0039E2A0");
extern char D_004725C8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00221FC8(void *arg0, int arg1, int arg2) {
    func_0039E2A0_1FC8(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004725C8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222030);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_x(void*) __asm__("func_001D5428");
extern char D_00472440[];
extern "C" void* func_00222030(void *self) {
    *(char**)((char*)self + 8) = D_00472440;
    return func_001D5428_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222058);
#ifdef SKIP_ASM
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern char D_00472440[];

extern "C" void *func_00222058(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00472440;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222098);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_x(void*) __asm__("func_001D5428");
extern char D_004722B8[];
extern "C" void* func_00222098(void *self) {
    *(char**)((char*)self + 8) = D_004722B8;
    return func_001D5428_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002220C0);
#ifdef SKIP_ASM
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern char D_004722B8[];

extern "C" void *func_002220C0(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_004722B8;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222100);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_004721E0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00222100(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004721E0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222160);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_2160(void*) __asm__("func_0039E2A0");
extern char D_004721E0[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00222160(void *arg0, int arg1, int arg2) {
    func_0039E2A0_2160(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_004721E0;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002221C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002221C8(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002221F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002221F0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222218);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_2218(void*) __asm__("func_0039E2A0");
extern char D_00472108[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00222218(void *arg0, int arg1, int arg2) {
    func_0039E2A0_2218(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00472108;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222280);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_001D5428_x(void*) __asm__("func_001D5428");
extern char D_00471F80[];
extern "C" void* func_00222280(void *self) {
    *(char**)((char*)self + 8) = D_00471F80;
    return func_001D5428_x(self);
}
#endif

extern "C" void func_002222A8(void) {
}

extern "C" void func_002222B0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002222B8);
#ifdef SKIP_ASM
extern "C" void* func_001D53B0(void* self, int a1, int a2);
extern char D_00471F80[];

extern "C" void *func_002222B8(void *arg0) {
    func_001D53B0(arg0, 0, 0);
    (*(char **)((char*)(arg0) + (8))) = D_00471F80;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002222F8);
#ifdef SKIP_ASM
extern "C" void *func_0039E2A0(void*, ...);
extern char D_00471EA8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_002222F8(void *arg0) {
    func_0039E2A0(arg0, 0);
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00471EA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222358);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_0039E2A0_2358(void*) __asm__("func_0039E2A0");
extern char D_00471EA8[];
extern char D_00474E08[];
extern unsigned short D_004A2088[];

extern "C" void *func_00222358(void *arg0, int arg1, int arg2) {
    func_0039E2A0_2358(arg0);
    (*(int *)((char*)(arg0) + (0x98))) = arg2;
    (*(int *)((char*)(arg0) + (0x48))) = 0;
    (*(char **)((char*)(arg0) + (8))) = D_00474E08;
    (*(int *)((char*)(arg0) + (0x4C))) = 0;
    (*(int *)((char*)(arg0) + (0x54))) = 0;
    unsigned short t = D_004A2088[0];
    (*(char **)((char*)(arg0) + (8))) = D_00471EA8;
    (*(unsigned short *)((char*)(arg0) + (0x58))) = t;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002223C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void* func_0039E390_x(void*) __asm__("func_0039E390");
extern char D_00474E08[];
extern "C" void* func_002223C0(void *self) {
    *(char**)((char*)self + 8) = D_00474E08;
    return func_0039E390_x(self);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002223E8);
#ifdef SKIP_ASM
// PORT: hand-rolled EE EABI va_start (gcc 2.95 va-mips.h form); use <stdarg.h> off-PS2.
#define func_002223E8_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern "C" void func_003929F8(int, int, char*);

extern "C" void func_002223E8(float x, float y, int c, int d, ...) {
    char* ap;
    func_002223E8_va_start(ap);
    func_003929F8(c, d, ap);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("fe/all_in_one_fe", func_00222428);
#ifdef SKIP_ASM
extern "C" void __sti__all_in_one_fe_cpp(int, int);

extern "C" void func_00222428(void) {
    __sti__all_in_one_fe_cpp(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222448);
#ifdef SKIP_ASM
extern unsigned short D_00441D38[];

extern "C" unsigned int func_00222448(const unsigned char *p, int n) {
    const unsigned char *end = p + n;
    unsigned int crc = 0xFBEA;
    while (p < end) {
        crc = D_00441D38[(*p++ ^ crc) & 0xFF] ^ (crc >> 8);
    }
    return crc;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224A0);
#ifdef SKIP_ASM
extern "C" int func_002224A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224A8);
#ifdef SKIP_ASM
extern "C" int func_002224A8(int arg0) {
    return arg0;
}
#endif

extern "C" void func_002224B0(void) {
}

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_002224B8);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
struct LV_24B8;
extern "C" void func_00224DF0_24B8(LV_24B8*, int) __asm__("func_00224DF0");
extern "C" void func_00225068_24B8(LV_24B8*, const LV_24B8*) __asm__("func_00225068");
extern "C" void luno_cLunoVM_execute_24B8(LV_24B8**, char**, int) __asm__("luno_cLunoVM_execute");
extern char D_00479780[];

struct LVPair_24B8 { int a, b; };
struct LV_24B8 {
    union { int i; LVPair_24B8 pair; } u;
    int type;
    LV_24B8() { type = 0; u.i = 0; }
    ~LV_24B8() {}
    void Release() { if (type == 4) func_00224DF0_24B8(this, 2); }
    void Clear() { type = 0; u.i = 0; }
    void SetTable(const LV_24B8* src) {
        Release();
        Clear();
        func_00225068_24B8(this, src);
        type = 4;
    }
    void Assign(const LV_24B8* src) {
        Release();
        Clear();
        if (src->type == 4) {
            func_00225068_24B8(this, src);
        } else if (src->type == 5) {
            u.pair = src->u.pair;
        } else {
            u.i = src->u.i;
        }
        type = src->type;
    }
};

extern LV_24B8 D_004C9098;

extern "C" void func_002224B8(LV_24B8** out, char** state, LV_24B8* a, int c) {
    char* s = *state;
    int n = *(int*)(s + *(int*)(s + 4) + 8);
    LV_24B8* arr = new (D_00479780, 0x20000000, 0) LV_24B8[n];
    *out = arr;
    arr[0].SetTable(a);
    LV_24B8* b = &D_004C9098;
    LV_24B8* p = *out;
    LV_24B8* q = &p[1];
    if (p[1].type == 4) func_00224DF0_24B8(q, 2);
    q->type = 0;
    p[1].u.i = 0;
    if (b->type == 4) {
        func_00225068_24B8(q, b);
    } else if (b->type == 5) {
        p[1].u.pair = b->u.pair;
    } else {
        p[1].u.i = b->u.i;
    }
    q->type = b->type;
    luno_cLunoVM_execute_24B8(out, state, c);
}
#endif

//100%
INCLUDE_ASM("fe/all_in_one_fe", func_00222648);
#ifdef SKIP_ASM
// PORT: operator_new__FUi really takes (size, tag, flags, d); bound by asm label
void* operator new[](unsigned int size, const char* tag, int flags, int d) __asm__("operator_new__FUi");
struct LV_2648;
extern "C" void func_00224DF0_2648(LV_2648*, int) __asm__("func_00224DF0");
extern "C" void func_00225068_2648(LV_2648*, const LV_2648*) __asm__("func_00225068");
extern "C" void luno_cLunoVM_execute_2648(LV_2648**, char**, int) __asm__("luno_cLunoVM_execute");
extern char D_00479780[];

struct LVPair_2648 { int a, b; };
struct LV_2648 {
    union { int i; LVPair_2648 pair; } u;
    int type;
    LV_2648() { type = 0; u.i = 0; }
    ~LV_2648() {}
    void Release() { if (type == 4) func_00224DF0_2648(this, 2); }
    void Clear() { type = 0; u.i = 0; }
    void SetTable(const LV_2648* src) {
        Release();
        Clear();
        func_00225068_2648(this, src);
        type = 4;
    }
    void Assign(const LV_2648* src) {
        Release();
        Clear();
        if (src->type == 4) {
            func_00225068_2648(this, src);
        } else if (src->type == 5) {
            u.pair = src->u.pair;
        } else {
            u.i = src->u.i;
        }
        type = src->type;
    }
};

extern "C" void func_00222648(LV_2648** out, char** state, LV_2648* a, LV_2648* b, int c) {
    char* s = *state;
    int n = *(int*)(s + *(int*)(s + 4) + 8);
    LV_2648* arr = new (D_00479780, 0x20000000, 0) LV_2648[n];
    *out = arr;
    arr[0].SetTable(a);
    LV_2648* p = *out;
    LV_2648* q = &p[1];
    if (p[1].type == 4) func_00224DF0_2648(q, 2);
    q->type = 0;
    p[1].u.i = 0;
    if (b->type == 4) {
        func_00225068_2648(q, b);
    } else if (b->type == 5) {
        p[1].u.pair = b->u.pair;
    } else {
        p[1].u.i = b->u.i;
    }
    q->type = b->type;
    luno_cLunoVM_execute_2648(out, state, c);
}
#endif
