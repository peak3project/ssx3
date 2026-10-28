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

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E80, 0x4E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423E90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423E90, 0x4F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423EA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423EA0, 0x50)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423EB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423EB0, 0x51)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423EC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423EC0, 0x52)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423ED0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423ED0, -0x53)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423EE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423EE0, 0x54)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423EF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423EF0, -0x55)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F00);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F00, 0x56)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F10);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F10, 0x57)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F20);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F20, -0x58)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F30);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F30, 0x59)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F40);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F40, -0x5A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F50);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F50, 0x5B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F60);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F60, 0x5C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F70);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F70, -0x5C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F80);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F80, 0x5D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423F90);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423F90, -0x5D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FA0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FA0, 0x5E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FB0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FB0, -0x5E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FC0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FC0, 0x5F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FD0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FD0, -0x5F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FE0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FE0, 0x60)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00423FF0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423FF0, 0x61)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424000);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424000, 0x62)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424010);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424010, 0x63)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424020);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424020, 0x64)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424030);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424030, 0x66)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424040);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424040, -0x67)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424050);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424050, -0x68)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424060);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424060, -0x6A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424070);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424070, 0x6B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424080);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424080, 0x6C)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424090);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424090, 0x6D)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240A0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240A0, 0x6E)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240B0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240B0, 0x6F)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240C0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240C0, 0x70)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240D0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240D0, -0x70)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240E0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240E0, 0x71)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004240F0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004240F0, -0x71)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424100);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424100, 0x72)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424110);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424110, 0x73)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424120);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424120, 0x74)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424130);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424130, 0x75)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424140);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424140, 0x76)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424150);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424150, -0x76)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424160);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424160, 0x77)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424170);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424170, -0x77)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424180);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424180, 0x78)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_00424190);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00424190, -0x78)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004241A0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004241A0, 0x79)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004241B0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004241B0, 0x7A)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004241C0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004241C0, 0x7B)
#endif

//100%
INCLUDE_ASM("seg/seg_3249A0", func_004241D0);
#ifdef SKIP_ASM
SYSCALL_STUB(func_004241D0, 0x7C)
#endif

INCLUDE_ASM("seg/seg_3249A0", func_004241E0);

INCLUDE_ASM("seg/seg_3249A0", func_004241F0);

INCLUDE_ASM("seg/seg_3249A0", func_00424200);

INCLUDE_ASM("seg/seg_3249A0", func_00424210);
