#include "common.h"

// PORT: PS2 kernel syscall stub: the syscall number goes in $3
#define SYSCALL_STUB(name, n) \
    void name(void) { register int v __asm__("$3") = (n); __asm__ volatile("syscall" : : "r"(v)); }

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239A0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239A0, 0x2)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239B0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239B0, 0x3)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239C0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239C0, 0x4)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239D0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239D0, 0x5)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239E0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239E0, 0x6)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004239F0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004239F0, 0x7)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A00, 0x8)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A10, 0x9)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A20, 0xA)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A30, 0xB)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A40, 0xC)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A50, 0xD)
#endif

INCLUDE_ASM("seg/seg_3249A0", func_00423A60);

INCLUDE_ASM("seg/seg_3249A0", func_00423A70);

INCLUDE_ASM("seg/seg_3249A0", func_00423A80);

INCLUDE_ASM("seg/seg_3249A0", func_00423A90);

INCLUDE_ASM("seg/seg_3249A0", func_00423AA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423AB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423AC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423AD0);

INCLUDE_ASM("seg/seg_3249A0", func_00423AE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423AF0);

INCLUDE_ASM("seg/seg_3249A0", func_00423B00);

INCLUDE_ASM("seg/seg_3249A0", func_00423B10);

INCLUDE_ASM("seg/seg_3249A0", func_00423B20);

INCLUDE_ASM("seg/seg_3249A0", func_00423B30);

INCLUDE_ASM("seg/seg_3249A0", func_00423B40);

INCLUDE_ASM("seg/seg_3249A0", func_00423B50);

INCLUDE_ASM("seg/seg_3249A0", func_00423B60);

INCLUDE_ASM("seg/seg_3249A0", func_00423B70);

INCLUDE_ASM("seg/seg_3249A0", func_00423B80);

INCLUDE_ASM("seg/seg_3249A0", func_00423B90);

INCLUDE_ASM("seg/seg_3249A0", func_00423BA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423BB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423BC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423BD0);

INCLUDE_ASM("seg/seg_3249A0", func_00423BE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423BF0);

INCLUDE_ASM("seg/seg_3249A0", func_00423C00);

INCLUDE_ASM("seg/seg_3249A0", func_00423C10);

INCLUDE_ASM("seg/seg_3249A0", func_00423C20);

INCLUDE_ASM("seg/seg_3249A0", func_00423C30);

INCLUDE_ASM("seg/seg_3249A0", func_00423C40);

INCLUDE_ASM("seg/seg_3249A0", func_00423C50);

INCLUDE_ASM("seg/seg_3249A0", func_00423C60);

INCLUDE_ASM("seg/seg_3249A0", func_00423C70);

INCLUDE_ASM("seg/seg_3249A0", func_00423C80);

INCLUDE_ASM("seg/seg_3249A0", func_00423C90);

INCLUDE_ASM("seg/seg_3249A0", func_00423CA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423CB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423CC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423CD0);

INCLUDE_ASM("seg/seg_3249A0", func_00423CE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423CF0);

INCLUDE_ASM("seg/seg_3249A0", func_00423D00);

INCLUDE_ASM("seg/seg_3249A0", func_00423D10);

INCLUDE_ASM("seg/seg_3249A0", func_00423D20);

INCLUDE_ASM("seg/seg_3249A0", func_00423D30);

INCLUDE_ASM("seg/seg_3249A0", func_00423D40);

INCLUDE_ASM("seg/seg_3249A0", func_00423D50);

INCLUDE_ASM("seg/seg_3249A0", func_00423D60);

INCLUDE_ASM("seg/seg_3249A0", func_00423D70);

INCLUDE_ASM("seg/seg_3249A0", func_00423D80);

INCLUDE_ASM("seg/seg_3249A0", func_00423D90);

INCLUDE_ASM("seg/seg_3249A0", func_00423DA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423DB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423DC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423DD0);

INCLUDE_ASM("seg/seg_3249A0", func_00423DE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423DF0);

INCLUDE_ASM("seg/seg_3249A0", func_00423E00);

INCLUDE_ASM("seg/seg_3249A0", func_00423E10);

INCLUDE_ASM("seg/seg_3249A0", func_00423E20);

INCLUDE_ASM("seg/seg_3249A0", func_00423E30);

INCLUDE_ASM("seg/seg_3249A0", func_00423E40);

INCLUDE_ASM("seg/seg_3249A0", func_00423E50);

INCLUDE_ASM("seg/seg_3249A0", func_00423E60);

INCLUDE_ASM("seg/seg_3249A0", func_00423E70);

INCLUDE_ASM("seg/seg_3249A0", func_00423E80);

INCLUDE_ASM("seg/seg_3249A0", func_00423E90);

INCLUDE_ASM("seg/seg_3249A0", func_00423EA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423EB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423EC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423ED0);

INCLUDE_ASM("seg/seg_3249A0", func_00423EE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423EF0);

INCLUDE_ASM("seg/seg_3249A0", func_00423F00);

INCLUDE_ASM("seg/seg_3249A0", func_00423F10);

INCLUDE_ASM("seg/seg_3249A0", func_00423F20);

INCLUDE_ASM("seg/seg_3249A0", func_00423F30);

INCLUDE_ASM("seg/seg_3249A0", func_00423F40);

INCLUDE_ASM("seg/seg_3249A0", func_00423F50);

INCLUDE_ASM("seg/seg_3249A0", func_00423F60);

INCLUDE_ASM("seg/seg_3249A0", func_00423F70);

INCLUDE_ASM("seg/seg_3249A0", func_00423F80);

INCLUDE_ASM("seg/seg_3249A0", func_00423F90);

INCLUDE_ASM("seg/seg_3249A0", func_00423FA0);

INCLUDE_ASM("seg/seg_3249A0", func_00423FB0);

INCLUDE_ASM("seg/seg_3249A0", func_00423FC0);

INCLUDE_ASM("seg/seg_3249A0", func_00423FD0);

INCLUDE_ASM("seg/seg_3249A0", func_00423FE0);

INCLUDE_ASM("seg/seg_3249A0", func_00423FF0);

INCLUDE_ASM("seg/seg_3249A0", func_00424000);

INCLUDE_ASM("seg/seg_3249A0", func_00424010);

INCLUDE_ASM("seg/seg_3249A0", func_00424020);

INCLUDE_ASM("seg/seg_3249A0", func_00424030);

INCLUDE_ASM("seg/seg_3249A0", func_00424040);

INCLUDE_ASM("seg/seg_3249A0", func_00424050);

INCLUDE_ASM("seg/seg_3249A0", func_00424060);

INCLUDE_ASM("seg/seg_3249A0", func_00424070);

INCLUDE_ASM("seg/seg_3249A0", func_00424080);

INCLUDE_ASM("seg/seg_3249A0", func_00424090);

INCLUDE_ASM("seg/seg_3249A0", func_004240A0);

INCLUDE_ASM("seg/seg_3249A0", func_004240B0);

INCLUDE_ASM("seg/seg_3249A0", func_004240C0);

INCLUDE_ASM("seg/seg_3249A0", func_004240D0);

INCLUDE_ASM("seg/seg_3249A0", func_004240E0);

INCLUDE_ASM("seg/seg_3249A0", func_004240F0);

INCLUDE_ASM("seg/seg_3249A0", func_00424100);

INCLUDE_ASM("seg/seg_3249A0", func_00424110);

INCLUDE_ASM("seg/seg_3249A0", func_00424120);

INCLUDE_ASM("seg/seg_3249A0", func_00424130);

INCLUDE_ASM("seg/seg_3249A0", func_00424140);

INCLUDE_ASM("seg/seg_3249A0", func_00424150);

INCLUDE_ASM("seg/seg_3249A0", func_00424160);

INCLUDE_ASM("seg/seg_3249A0", func_00424170);

INCLUDE_ASM("seg/seg_3249A0", func_00424180);

INCLUDE_ASM("seg/seg_3249A0", func_00424190);

INCLUDE_ASM("seg/seg_3249A0", func_004241A0);

INCLUDE_ASM("seg/seg_3249A0", func_004241B0);

INCLUDE_ASM("seg/seg_3249A0", func_004241C0);

INCLUDE_ASM("seg/seg_3249A0", func_004241D0);

INCLUDE_ASM("seg/seg_3249A0", func_004241E0);

INCLUDE_ASM("seg/seg_3249A0", func_004241F0);

INCLUDE_ASM("seg/seg_3249A0", func_00424200);

INCLUDE_ASM("seg/seg_3249A0", func_00424210);
