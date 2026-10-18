#include "common.h"

INCLUDE_ASM("seg/seg_2F0F40", func_003EFF40);

INCLUDE_ASM("seg/seg_2F0F40", func_003F00D8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0150);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0198);

INCLUDE_ASM("seg/seg_2F0F40", func_003F02D0);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0568);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0610);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0658);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0710);

INCLUDE_ASM("seg/seg_2F0F40", func_003F07A0);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0800);
#ifdef SKIP_ASM
int func_003F0800(int* p) {
    return p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0808);
#ifdef SKIP_ASM
void func_003F0808(int* p, int a, int b) {
    p[0x504 / 4] = a;
    p[0x508 / 4] = b;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F0818);

INCLUDE_ASM("seg/seg_2F0F40", func_003F08E8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0B50);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0BE0);

INCLUDE_ASM("seg/seg_2F0F40", func_003F0C90);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F0E30);
#ifdef SKIP_ASM
int func_003F0E30(int* p) {
    return p[0x4A8 / 4];
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F0E38);

INCLUDE_ASM("seg/seg_2F0F40", func_003F11F8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F14D8);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F1538);
#ifdef SKIP_ASM
void func_003F1538(char* p) {
    p[0x40] = 0;
    p[0x140] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F1548);
#ifdef SKIP_ASM
extern int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src);
void func_003F1548(char* p, const char* src) {
    if (p[0x2C8]) {
        cDirtysock_tag_TagFieldDupl(p + 0x40, 0x100, src);
    }
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F1578);

INCLUDE_ASM("seg/seg_2F0F40", func_003F15C8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F16D8);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F17C8);
#ifdef SKIP_ASM
void func_003F17C8(int* p, int a, int b) {
    p[0x4B0 / 4] = a;
    p[0x4AC / 4] = b;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F17D8);

INCLUDE_ASM("seg/seg_2F0F40", func_003F2220);

//100%
INCLUDE_ASM("seg/seg_2F0F40", func_003F30F0);
#ifdef SKIP_ASM
void func_003F30F0(unsigned int* p) {
    p[0] = 0;
    p[1] = 0x67452301;
    p[2] = 0xEFCDAB89;
    p[3] = 0x98BADCFE;
    p[4] = 0x10325476;
}
#endif

INCLUDE_ASM("seg/seg_2F0F40", func_003F3128);
