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

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A60, 0xE)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A70, 0xF)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A80, 0x10)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423A90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423A90, 0x10)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AA0, 0x11)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AB0, 0x12)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AC0, 0x12)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AD0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AD0, 0x13)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AE0, 0x14)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423AF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423AF0, 0x15)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B00, 0x16)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B10, 0x17)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B20, 0xFC)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B30, 0xFD)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B40, -0x1A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B50, -0x1B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B60, -0x1C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B70, -0x1D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B80, -0xFE)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423B90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423B90, -0xFF)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BA0, 0x20)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BB0, 0x21)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BC0, 0x22)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BD0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BD0, 0x23)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BE0, 0x24)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423BF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423BF0, 0x25)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C00, -0x26)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C10, 0x27)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C20, 0x28)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C30, 0x29)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C40, -0x2A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C50, 0x2B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C60, -0x2C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C70, 0x2D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C80, -0x2E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423C90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423C90, 0x2F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CA0, 0x30)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CB0, -0x31)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CC0, 0x32)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CD0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CD0, 0x33)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CE0, -0x34)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423CF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423CF0, 0x35)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D00, -0x36)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D10, 0x37)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D20, -0x38)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D30, 0x39)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D40, -0x3A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D50, 0x3B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D60, 0x3C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D70, 0x3D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D80, 0x3E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423D90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423D90, 0x3F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DA0, 0x40)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DB0, 0x41)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DC0, 0x42)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DD0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DD0, -0x43)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DE0, 0x44)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423DF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423DF0, 0x45)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E00, -0x46)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E10, 0x47)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E20, -0x48)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E30, 0x49)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E40, 0x4A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E50, 0x4B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E60, 0x4C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E70, 0x4D)
#endif

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
