#include "common.h"

//100%
INCLUDE_ASM("main/ssxappdtor", cSSXApp__cSSXApp);
#ifdef SKIP_ASM
extern "C" void cBXString__cBXString(void* self, int flags);
void cAppMan__cAppMan(void* self, int flags);

extern "C" void cSSXApp__cSSXApp(void* self, int flags)
{
    cBXString__cBXString((char*)self + 0xCC, 2);
    cBXString__cBXString((char*)self + 0xC8, 2);
    cBXString__cBXString((char*)self + 0xC4, 2);
    cAppMan__cAppMan(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243950);
#ifdef SKIP_ASM
extern "C" int func_00243950(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243958);
#ifdef SKIP_ASM
extern "C" int func_00243958(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243960);
#ifdef SKIP_ASM
extern "C" int func_00243960(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x80)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243968);
#ifdef SKIP_ASM
extern "C" int func_00243968(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x84)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243970);
#ifdef SKIP_ASM
extern "C" int func_00243970(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x88)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243978);
#ifdef SKIP_ASM
extern "C" int func_00243978(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243980);
#ifdef SKIP_ASM
extern "C" int func_00243980(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0xB0);
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243990);
#ifdef SKIP_ASM
extern "C" int func_00243990(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0xB8);
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439A0);
#ifdef SKIP_ASM
extern "C" int func_002439A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC0)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439A8);
#ifdef SKIP_ASM
extern "C" int func_002439A8(int arg0) {
    return arg0 + 0xC4;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439B0);
#ifdef SKIP_ASM
extern "C" int func_002439B0(int arg0) {
    return arg0 + 0xC8;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439B8);
#ifdef SKIP_ASM
extern "C" int func_002439B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xD0)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439C0);
#ifdef SKIP_ASM
extern "C" int func_002439C0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x9C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439C8);
#ifdef SKIP_ASM
extern "C" int func_002439C8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA4)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439D0);
#ifdef SKIP_ASM
extern "C" int func_002439D0(void) {
    return 2;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439D8);
#ifdef SKIP_ASM
extern "C" int func_002439D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA0)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439E0);
#ifdef SKIP_ASM
extern "C" void func_002439E0(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xA0))) = arg1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439E8);
#ifdef SKIP_ASM
extern "C" void func_002439E8(void *self) {
    *(int *)((char *)self + 0x7C) = 0;
    *(int *)((char *)self + 0x80) = 0;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002439F8);
#ifdef SKIP_ASM
extern "C" void func_002439F8(void *arg0) {
    (*(int *)((char*)(arg0) + (0x84))) = 0;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A00);
#ifdef SKIP_ASM
extern "C" int func_00243A00(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x84))) != 0;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A10);
#ifdef SKIP_ASM
extern "C" int func_00243A10(void *arg0) {
    int var_3;

    var_3 = 0;
    if (((*(int *)((char*)(arg0) + (0x7C))) != 0) || ((*(int *)((char*)(arg0) + (0x80))) != 0)) {
        var_3 = 1;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A38);
#ifdef SKIP_ASM
extern "C" int func_00243A38(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x11C)));
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A40);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_00243A40(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A70);
#ifdef SKIP_ASM
extern "C" void func_00243A70(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243A80);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_00243A80(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243AB0__FPv);
#ifdef SKIP_ASM
void func_00243AB0(void* self)
{
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243AB8);
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243AD8);
#ifdef SKIP_ASM
extern "C" void func_00243AD8(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = 1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243AE8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_00243AE8(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243B18);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243B50);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_00243B50(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243B80);
#ifdef SKIP_ASM
void operator_delete(int* ptr);
extern char D_0046D970[];

extern "C" void func_00243B80(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243BB0);
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243BF0);
#ifdef SKIP_ASM
extern "C" int func_00243BF0(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x10);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243C00);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0046D970[];

extern "C" void func_00243C00(int* self, int flags)
{
    *(void**)self = D_0046D970;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243C30);
//100%
INCLUDE_ASM("main/ssxappdtor", func_00243C70);
#ifdef SKIP_ASM
extern "C" int func_00243C70(void *self, int index) {
    return *(int *)((char *)self + (index << 2) + 0x10);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243C80);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243C80(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CB0__FPv);
#ifdef SKIP_ASM
void func_00243CB0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CB8__FPv);
#ifdef SKIP_ASM
void func_00243CB8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CC0__FPv);
#ifdef SKIP_ASM
void func_00243CC0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CC8__FPv);
#ifdef SKIP_ASM
void func_00243CC8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CD0__FPv);
#ifdef SKIP_ASM
void func_00243CD0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CD8__FPv);
#ifdef SKIP_ASM
void func_00243CD8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CE0__FPv);
#ifdef SKIP_ASM
int func_00243CE0(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CE8__FPv);
#ifdef SKIP_ASM
void func_00243CE8(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243CF0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243CF0(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243D20);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243D58);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243D58(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243D88);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243D88(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243DB8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243DB8(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243DE8);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243E20);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243E20(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243E50);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243E50(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243E80);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243EB8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243EB8(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243EE8);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243F20);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243F20(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243F50);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243F50(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243F80);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00243FC0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00243FC0(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00243FF0);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244028);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00244028(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244058);
#ifdef SKIP_ASM
extern "C" void func_00244058(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x18))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244060);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00244060(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244090);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00244090(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_002440C0);

//100%
INCLUDE_ASM("main/ssxappdtor", func_002440F8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_002440F8(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00244128);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244160);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_00244160(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00244190);

//100%
INCLUDE_ASM("main/ssxappdtor", func_002441C8);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D6E8[];

extern "C" void func_002441C8(int* self, int flags)
{
    *(void**)((char*)self + 0xC) = D_0047D6E8;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_002441F8);
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244230);
#ifdef SKIP_ASM
extern "C" void func_00244230(void) {

}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244238);
#ifdef SKIP_ASM
extern "C" void func_00244238(void) {

}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244240);
#ifdef SKIP_ASM
extern int D_004428F0[];
extern int D_005366E8[];
extern int D_004A2A50;
extern int D_004A2A54;

extern "C" void func_00244240(int id)
{
    D_004A2A50 = D_004428F0[id];
    D_005366E8[D_004A2A54] = id;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244278);
#ifdef SKIP_ASM
extern "C" int func_00244278(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x214)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244280);
#ifdef SKIP_ASM
extern "C" int func_00244280(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x218)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244288);
#ifdef SKIP_ASM
extern "C" int func_00244288(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x200)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244290);
#ifdef SKIP_ASM
extern "C" int func_00244290(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244298);
#ifdef SKIP_ASM
extern "C" int func_00244298(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442A0);
#ifdef SKIP_ASM
extern "C" int func_002442A0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x24)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442A8);
#ifdef SKIP_ASM
extern "C" int func_002442A8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xA4)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442B0);
#ifdef SKIP_ASM
extern "C" int func_002442B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442B8);
#ifdef SKIP_ASM
extern "C" int func_002442B8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x48)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442C0);
#ifdef SKIP_ASM
extern "C" int func_002442C0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x28)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442C8);
#ifdef SKIP_ASM
extern "C" int func_002442C8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442D0);
#ifdef SKIP_ASM
extern "C" int func_002442D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x44)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442D8);
#ifdef SKIP_ASM
extern "C" int func_002442D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x4C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442E0);
#ifdef SKIP_ASM
extern "C" int func_002442E0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x50)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442E8);
#ifdef SKIP_ASM
extern "C" int func_002442E8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x54)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442F0);
#ifdef SKIP_ASM
extern "C" int func_002442F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x64)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002442F8);
#ifdef SKIP_ASM
extern "C" int func_002442F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x70)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244300);
#ifdef SKIP_ASM
extern "C" int func_00244300(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x74)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244308);
#ifdef SKIP_ASM
extern "C" int func_00244308(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x34)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244310);
#ifdef SKIP_ASM
extern "C" int func_00244310(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x78)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244318);
#ifdef SKIP_ASM
extern "C" int func_00244318(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244320);
#ifdef SKIP_ASM
extern "C" int func_00244320(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244328);
#ifdef SKIP_ASM
extern "C" int func_00244328(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x38)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244330);
#ifdef SKIP_ASM
extern "C" int func_00244330(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x3C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244338);
#ifdef SKIP_ASM
extern "C" int func_00244338(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x40)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244340);
#ifdef SKIP_ASM
extern "C" int func_00244340(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x88)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244348);
#ifdef SKIP_ASM
extern "C" int func_00244348(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x8C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244350);
#ifdef SKIP_ASM
extern "C" int func_00244350(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x90)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244358);
#ifdef SKIP_ASM
extern "C" int func_00244358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x94)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244360);
#ifdef SKIP_ASM
extern "C" int func_00244360(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x224)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244368);
#ifdef SKIP_ASM
extern "C" int func_00244368(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x84)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244370);
#ifdef SKIP_ASM
extern "C" int func_00244370(void *self, int index) {
    return *(int *)((char *)(*(int *)((char *)self + 0x84)) + (index << 2) + 4);
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244388);
#ifdef SKIP_ASM
extern "C" int func_00244388(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0x84)))) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244398);
#ifdef SKIP_ASM
struct sL244398 { int pad; int items[4]; int cur; };
struct sO244398 { char pad[0x84]; sL244398* list; };
extern "C" int func_00244398(sO244398* self) {
    return self->list->items[self->list->cur];
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002443B0);
#ifdef SKIP_ASM
extern "C" int func_002443B0(void *arg0) {
    return (*(int *)((char*)((*(void **)((char*)(arg0) + (0x84)))) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002443C0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047DB28[];

extern "C" void func_002443C0(int* self, int flags)
{
    *(void**)self = D_0047DB28;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002443F0);
#ifdef SKIP_ASM
extern "C" void* func_002443F0(void* self, void* a1)
{
    return a1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002443F8__FPv);
#ifdef SKIP_ASM
int func_002443F8(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244400__FPvi);
#ifdef SKIP_ASM
void func_00244400(void* self, int val)
{
    *(int*)((char*)self + 0x0) = val;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244408__FPvi);
#ifdef SKIP_ASM
void func_00244408(void* self, int val)
{
    *(int*)((char*)self + 0x4) = val;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244410);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void* self, int flags);
extern void* D_0047D070[];
struct sVEntry_func_00244410 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_00244410(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_0047D070;
    void* obj = *(void**)((char*)self + 0x10);
    if (obj != 0) {
        sVEntry_func_00244410* vt = *(sVEntry_func_00244410**)((char*)obj + 0x44);
        vt[1].fn((char*)obj + vt[1].delta, 3);
    }
    func_003546C8(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244478);
#ifdef SKIP_ASM
class cAppDtorVirt44 {
public:
    char pad[0x44];
    // vptr lands at 0x44 (g++ 2.95 places it after the class's own data);
    // slot N lives at vtable offset N*8 (delta at +0, function at +4)
    virtual void v01();
    virtual void v02();
    virtual void v03();
};

extern "C" void func_00244478(void* self)
{
    (*(cAppDtorVirt44**)((char*)self + 0x10))->v02();
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002444A8);
#ifdef SKIP_ASM
extern "C" void func_002444A8(void* self)
{
    (*(cAppDtorVirt44**)((char*)self + 0x10))->v03();
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002444D8);
#ifdef SKIP_ASM
extern char D_0047D008[];

extern "C" int **func_002444D8(int **arg0) {
    *arg0 = &(*(int*)&D_0047D008);
    return arg0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002444F0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_002444F0(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244520);
#ifdef SKIP_ASM
extern int D_004A2C70;

extern "C" void func_00244520(int arg0) {
    D_004A2C70 = arg0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244528__FPv);
#ifdef SKIP_ASM
void func_00244528(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244530__FPv);
#ifdef SKIP_ASM
int func_00244530(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244538__FPv);
#ifdef SKIP_ASM
void func_00244538(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244540__FPv);
#ifdef SKIP_ASM
void func_00244540(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244548__FPv);
#ifdef SKIP_ASM
int func_00244548(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244550__FPv);
#ifdef SKIP_ASM
void func_00244550(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244558__FPv);
#ifdef SKIP_ASM
void func_00244558(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244560);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244560(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244590);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244590(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002445C0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_002445C0(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002445F0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_002445F0(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244620__FPv);
#ifdef SKIP_ASM
void func_00244620(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244628__FPv);
#ifdef SKIP_ASM
void func_00244628(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244630);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244630(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244660);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244660(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244690);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244690(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002446C0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_002446C0(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002446F0);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_002446F0(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244720);
#ifdef SKIP_ASM
void operator_delete(int* ptr);

extern char D_0047D008[];

extern "C" void func_00244720(int* self, int flags)
{
    *(void**)self = D_0047D008;
    if (flags & 1) {
        operator_delete(self);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244750);
#ifdef SKIP_ASM
extern "C" int func_00244750(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x434)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244758);
#ifdef SKIP_ASM
extern "C" int func_00244758(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x130)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244760);
#ifdef SKIP_ASM
extern "C" int func_00244760(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xBC)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244768);
#ifdef SKIP_ASM
extern "C" int func_00244768(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC0)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244770);
#ifdef SKIP_ASM
extern "C" void func_00244770(void *arg0) {
    (*(int (**)())((char*)(arg0) + (0x78)))();
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244790);
#ifdef SKIP_ASM
extern "C" int func_00244790(void *arg0) {
    int var_3;

    var_3 = 0;
    if ((*(int *)((char*)(arg0) + (0x440))) == 0) {
        var_3 = (*(int *)((char*)(arg0) + (0x43C))) != 0;
    }
    return var_3;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002447B0);
#ifdef SKIP_ASM
extern "C" int func_002447B0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x43C))) != 0;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002447C0);
#ifdef SKIP_ASM
extern "C" int func_002447C0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x43C)));
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002447C8);
#ifdef SKIP_ASM
extern "C" void func_002447C8(void *arg0) {
    (*(int *)((char*)(arg0) + (0x440))) = 1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002447D8);
#ifdef SKIP_ASM
extern "C" int func_002447D8(void *arg0) {
    return (((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x43C))) >> 5) & 0xF) - 1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_002447F0);
#ifdef SKIP_ASM
extern "C" void func_002C2508(int);

extern "C" void func_002447F0(int arg0) {
    func_002C2508(arg0 + 0x276);
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244810);
#ifdef SKIP_ASM
extern "C" void func_002C2540(int);

extern "C" void func_00244810(int arg0) {
    func_002C2540(arg0 + 0x276);
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244830);
#ifdef SKIP_ASM
extern "C" int func_00244830(int arg0) {
    return arg0 + 0x276;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244838);
#ifdef SKIP_ASM
extern "C" void func_00244838(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x11C))) = arg1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244840);
#ifdef SKIP_ASM
extern "C" void func_00244840(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x120))) = arg1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244848);
#ifdef SKIP_ASM
extern "C" void func_00244848(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x124))) = arg1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244850);
#ifdef SKIP_ASM
extern "C" void func_00244850(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x128))) = arg1;
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244858);
#ifdef SKIP_ASM
extern "C" void func_00244858(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x12C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244860__FPv);
#ifdef SKIP_ASM
void func_00244860(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244868__FPv);
#ifdef SKIP_ASM
int func_00244868(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244870__FPv);
#ifdef SKIP_ASM
int func_00244870(void* self)
{
    return 0x1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244878__FPv);
#ifdef SKIP_ASM
int func_00244878(void* self)
{
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244880__FPv);
#ifdef SKIP_ASM
void func_00244880(void* self)
{
    *(int*)((char*)self + 0x40) = 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244888);
#ifdef SKIP_ASM
extern "C" void func_0022E8B8(int);
extern "C" int func_0022E920(int);

extern "C" int func_00244888(void *self) {
    func_0022E8B8(*(int *)((char*)self + 0x84));
    if (*(int *)((char*)self + 0x9C) != 0) {
        return 0;
    }
    if (func_0022E920(*(int *)((char*)self + 0x84)) == 0) {
        *(int *)((char*)self + 0x9C) = 1;
        *(int *)((char*)self + 0xA0) = 1;
        return 0;
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002448E0);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void* self, int flags);
extern void* D_0047CB60[];
struct sVEntry_func_002448E0 {
    short delta;
    short index;
    void (*fn)(void*, int);
};

extern "C" void func_002448E0(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_0047CB60;
    void* obj = *(void**)((char*)self + 0x10);
    if (obj != 0) {
        sVEntry_func_002448E0* vt = *(sVEntry_func_002448E0**)((char*)obj + 0x4);
        vt[1].fn((char*)obj + vt[1].delta, 3);
    }
    func_003546C8(self, flags);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244948);
#ifdef SKIP_ASM
class cAppDtorVirt04 {
public:
    int field_0x0;
    // vptr lands at 0x4 (g++ 2.95 places it after the class's own data);
    // slot N lives at vtable offset N*8 (delta at +0, function at +4)
    virtual void v01();
    virtual void v02();
    virtual void v03();
};

extern "C" void func_00244948(void* self)
{
    (*(cAppDtorVirt04**)((char*)self + 0x10))->v02();
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244978);
#ifdef SKIP_ASM
extern "C" void func_00244978(void* self)
{
    (*(cAppDtorVirt04**)((char*)self + 0x10))->v03();
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002449A8);
#ifdef SKIP_ASM
extern "C" void func_003546C8(void* self, int flags);
extern void* D_0047CAE8[];

extern "C" void func_002449A8(void* self, int flags)
{
    *(void***)((char*)self + 0xC) = D_0047CAE8;
    operator_delete(*(int**)((char*)self + 0x10));
    func_003546C8(self, flags);
}
#endif

void func_002D21B0(void*);

//100%
INCLUDE_ASM("main/ssxappdtor", func_002449F8);
#ifdef SKIP_ASM
extern "C" void func_002449F8(void* self)
{
    func_002D21B0(*(void**)((char*)self + 0x10));
}
#endif

void func_002D21B8(void*);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244A18);
#ifdef SKIP_ASM
extern "C" void func_00244A18(void* self)
{
    func_002D21B8(*(void**)((char*)self + 0x10));
}
#endif

extern "C" void* func_0039E390(void* self);

//100%
INCLUDE_ASM("main/ssxappdtor", func_00244A38);
#ifdef SKIP_ASM
extern "C" void func_00244A38(void) {

}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00244A40);
#ifdef SKIP_ASM
extern "C" void cGameViewMan_updateAll(int);
extern "C" void func_0022D8D8(void *);
extern "C" void func_0022E8B8(int);
extern "C" int func_0022E920(int);
extern "C" void func_00230F40(void *);
void func_003A6928(void *);
extern "C" void func_003A88A8(void *);
extern void *D_004A289C;

extern "C" int func_00244A40(void *self) {
    void *vtbl;

    if ((func_0022E920(*(int *)((char*)self + 0x84)) == 0) || (*(int *)(*(char **)((char*)self + 0x78) + 0x1D0) == 0)) {
        *(int *)(**(char ***)((char*)self + 0x10) + 0x3D4) = 0;
        func_003A6928(*(void **)((char*)self + 0x10));
        cGameViewMan_updateAll(*(int *)((char*)self + 0x84));
        if (*(int *)(*(char **)((char*)self + 0x78) + 0x1D0) == 0) {
            func_00230F40(self);
            func_0022D8D8(*(void **)((char*)self + 0x78));
        }
        if ((*(int *)((char*)self + 0x9C) == 0) && (func_0022E920(*(int *)((char*)self + 0x84)) == 0)) {
            *(int *)((char*)self + 0xA0) = 1;
        }
        *(int *)((char*)self + 0x9C) = 1;
        if (*(int *)((char*)self + 0xA0) != 0) {
            vtbl = *(void **)((char*)D_004A289C + 0x10D8);
            (*(void (**)(void *))((char*)vtbl + 0x9C))((char*)D_004A289C + *(short *)((char*)vtbl + 0x98));
            func_0022E8B8(*(int *)((char*)self + 0x84));
            func_003A88A8(**(void ***)((char*)self + 0x10));
            *(int *)((char*)self + 0xA0) = 0;
        }
        return 0;
    }
    *(int *)(**(char ***)((char*)self + 0x10) + 0x3D4) = 1;
    *(int *)((char*)self + 0x9C) = 0;
    *(int *)((char*)self + 0xA0) = 0;
    func_003A6928(*(void **)((char*)self + 0x10));
    func_0022D8D8(*(void **)((char*)self + 0x78));
    return 1;
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00244B48);

INCLUDE_ASM("main/ssxappdtor", func_00244E60);
//100%
INCLUDE_ASM("main/ssxappdtor", func_00245118);
#ifdef SKIP_ASM
extern "C" void func_002570D8(int);
extern int D_004A2EEC;

extern "C" void func_00245118(void) {
    if (D_004A2EEC != 0) {
        func_002570D8(D_004A2EEC);
    }
}
#endif
//100%
INCLUDE_ASM("main/ssxappdtor", func_00245140);
#ifdef SKIP_ASM
extern "C" void func_003F42A0();
extern int D_004A2EB8;

extern "C" void func_00245140(void) {
    if (D_004A2EB8 != 0) {
        func_003F42A0();
    }
}
#endif

INCLUDE_ASM("main/ssxappdtor", func_00245168);
//100%
INCLUDE_ASM("main/ssxappdtor", func_002451B0);
#ifdef SKIP_ASM
extern "C" void func_002451B0(void *self) {
    int i;
    char *obj;
    char *vtbl;

    i = 0;
    if (*(int *)(*(char **)((char*)self + 0xC) + 0x78) > 0) {
        do {
            obj = *(char **)(*(char **)((char*)self + 0xC) + (i << 2) + 0x28);
            i++;
            vtbl = *(char **)(obj + 0x6C0);
            (*(void (**)(void *))(vtbl + 0x9C))(obj + *(short *)(vtbl + 0x98));
        } while (i < *(int *)(*(char **)((char*)self + 0xC) + 0x78));
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245228__FPv);
#ifdef SKIP_ASM
void* func_00245228(void* self)
{
    return func_0039E390(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245248);
#ifdef SKIP_ASM
struct cUIText;
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void* cUIScreen_getObjectByHashName(void* self, int hash);
void cUIText_setAsciiString(cUIText* text, const char* str);
extern char D_004A2AD8[];
extern char D_004A2AC0[];
extern char D_0047B988[];

extern "C" void func_00245248(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_004A2AD8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
    cUIText* text = (cUIText*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2AC0));
    if (text != 0) {
        cUIText_setAsciiString(text, D_0047B988);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002452D8);
#ifdef SKIP_ASM
// PORT: cMemMan_alloc bound as a placement operator new (gcc then treats the result as unaliased)
void* operator new(unsigned int size, const char* tag, unsigned int flags, int d) __asm__("cMemMan_alloc");
extern "C" void func_0039E2A0(void* self, void* owner);
extern "C" void func_0039F400(void* list, void* item);
extern char D_0047B9C0[];
extern char D_004A2AC8[];
extern void* D_0047DA58[];

struct sUIObj_2452D8 {
    int f0;
    int f4;
    void** vt;
    char pad[0x3C];
    char flag48;
    char pad49[7];
};

struct sRVEntry_2452D8 {
    short delta;
    short index;
    void (*fn)(void*, int);
};
struct sRCtx_2452D8 {
    char pad[0x10D8];
    sRVEntry_2452D8* vt;
};
extern sRCtx_2452D8* D_004A5B80;

static inline int isHash_2452D8(int id, char* s)
{
    return id == GetHashValue32(s);
}

static inline sUIObj_2452D8* newUIObj_2452D8(void* owner, char flag)
{
    sUIObj_2452D8* o = new (D_0047B9C0, 0, 0) sUIObj_2452D8;
    func_0039E2A0(o, *(void**)((char*)owner + 0x10));
    o->vt = D_0047DA58;
    o->flag48 = flag;
    return o;
}

extern "C" void func_002452D8(void* self, char* msg, int type)
{
    if (msg == 0) {
        return;
    }
    if (type != 5) {
        return;
    }
    if (isHash_2452D8(*(int*)(msg + 0x38), D_004A2AC8)) {
        sUIObj_2452D8* o = newUIObj_2452D8(self, 0);
        func_0039F400(*(char**)((char*)self + 0x10) + 0x18, o);
        D_004A5B80->vt[8].fn((char*)D_004A5B80 + D_004A5B80->vt[8].delta, 1);
    } else {
        sUIObj_2452D8* o = newUIObj_2452D8(self, 1);
        func_0039F400(*(char**)((char*)self + 0x10) + 0x18, o);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002453E0);
#ifdef SKIP_ASM
extern "C" int func_002453E0(void* self, int a1, int a2)
{
    return a2 == 6 ? 0x101 : 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002453F0);
#ifdef SKIP_ASM
extern void* D_0047C948[];
extern "C" void* func_0039E390(void* self);

extern "C" void* func_002453F0(void* self)
{
    *(void**)((char*)self + 0x8) = D_0047C948;
    return func_0039E390(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245418);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern "C" void func_00246CF8(void* self, int a1);
extern signed char D_00535C11[];
extern char D_0047BA28[];
extern char D_0047BA38[];

extern "C" void func_00245418(void* self)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    if (D_00535C11[0] == 2) {
        void* engine = *(void**)((char*)self + 0x10);
        void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BA28), 0);
        *(void**)((char*)self + 0x40) = screen;
        if (screen != 0) {
            cUIScreen_playFrame(screen, 0, 0);
        }
    } else {
        void* engine = *(void**)((char*)self + 0x10);
        void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BA38), 0);
        *(void**)((char*)self + 0x40) = screen;
        if (screen != 0) {
            cUIScreen_playFrame(screen, 0, 0);
        }
    }
    func_00246CF8(self, 0);
    func_00246CF8(self, 1);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002454F8);
#ifdef SKIP_ASM
extern char D_004A2BC8[];
extern char D_004A2BD0[];
extern char* D_004A5B64;
extern "C" void func_002C27C0(char* dst, const char* fmt, ...);
extern "C" void func_003A0E90(void* text, void* p);

extern "C" int func_002454F8(void* self, int refresh)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        char buf[0xD0];
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)(D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    if (refresh != 0) {
        func_00246CF8(self, 0);
        func_00246CF8(self, 1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245598);
#ifdef SKIP_ASM
extern "C" void* cBE_getBE();
// PORT: cBE_getInterface__Fv is called with (be, kind) here; bind the 2-arg form to that symbol.
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void func_002464E8(void* self, int a1);
extern "C" void func_00246278(void* self, int a1);
extern signed char D_00535C11[];

extern "C" void func_00245598(void* self, int a1)
{
    cBE_getInterface_Fv(cBE_getBE(), 0);
    bool ok = D_00535C11[0] != 2;
    if (ok) {
        func_002464E8(self, a1);
    } else {
        func_00246278(self, a1);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245600);
#ifdef SKIP_ASM
extern void* D_0047C878[];
extern "C" void* func_0039E390(void* self);

extern "C" void* func_00245600(void* self)
{
    *(void**)((char*)self + 0x8) = D_0047C878;
    return func_0039E390(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245628);
#ifdef SKIP_ASM
int GetHashValue32(char* str);
extern "C" void* cUIEngine_addScreenByHashName(void* engine, void* owner, int hash, int a3);
extern "C" void cUIScreen_playFrame(void* screen, int a1, int a2);
extern char D_0047BCC8[];

extern "C" void func_00245628(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* screen = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BCC8), 0);
    *(void**)((char*)self + 0x40) = screen;
    if (screen != 0) {
        cUIScreen_playFrame(screen, 0, 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245690__FPv);
#ifdef SKIP_ASM
void func_00245690(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245698);
#ifdef SKIP_ASM
extern char D_004A2BC8[];
extern char D_004A2BD0[];
extern char* D_004A5B64;
extern "C" void func_002C27C0(char* dst, const char* fmt, ...);
extern "C" void func_003A0E90(void* text, void* p);

extern "C" int func_00245698(void* self)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        char buf[0xD0];
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)(D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245708);
#ifdef SKIP_ASM
extern void* D_0047C7A8[];
extern "C" void* func_0039E390(void* self);

extern "C" void* func_00245708(void* self)
{
    *(void**)((char*)self + 0x8) = D_0047C7A8;
    return func_0039E390(self);
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245730);
#ifdef SKIP_ASM
// PORT: cBE_getInterface__Fv really takes (be, kind); bound by asm label
void* cBE_getInterface_Fv(void* be, int kind) __asm__("cBE_getInterface__Fv");
extern "C" void* cBE_getBE();
extern "C" int func_00147618(void* iface, int a1);
extern char D_0047BCD8[];
extern char D_0047BCE8[];
extern char D_0047BCF8[];
extern char D_0047BD08[];
extern char D_0047BD18[];

class cUIObj_245730 {
public:
    int f0;
    int f4;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void setVisible(int on);
};

extern "C" void func_00245730(void* self)
{
    void* engine = *(void**)((char*)self + 0x10);
    void* scr = cUIEngine_addScreenByHashName(engine, self, GetHashValue32(D_0047BCD8), 0);
    *(void**)((char*)self + 0x40) = scr;
    if (scr != 0) {
        cUIScreen_playFrame(scr, 0, 0);
    }
    char* ctrlDefault = D_0047BCE8;
    char* ctrlPro = D_0047BCF8;
    int r = func_00147618(cBE_getInterface_Fv(cBE_getBE(), 1), 0);
    cUIObj_245730* o;
    o = (cUIObj_245730*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(ctrlDefault));
    if (o != 0) {
        o->setVisible(r == 0);
    }
    o = (cUIObj_245730*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BD08));
    if (o != 0) {
        o->setVisible(r == 0);
    }
    o = (cUIObj_245730*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(ctrlPro));
    if (o != 0) {
        o->setVisible(r != 0);
    }
    o = (cUIObj_245730*)cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_0047BD18));
    if (o != 0) {
        o->setVisible(r != 0);
    }
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002458B0__FPv);
#ifdef SKIP_ASM
void func_002458B0(void* self)
{
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_002458B8);
#ifdef SKIP_ASM
extern char D_004A2BC8[];
extern char D_004A2BD0[];
extern char* D_004A5B64;
extern "C" void func_002C27C0(char* dst, const char* fmt, ...);
extern "C" void func_003A0E90(void* text, void* p);

extern "C" int func_002458B8(void* self)
{
    void* obj = cUIScreen_getObjectByHashName(*(void**)((char*)self + 0x40), GetHashValue32(D_004A2BC8));
    if (obj != 0) {
        char buf[0xD0];
        func_002C27C0(buf, D_004A2BD0, (int)*(float*)(D_004A5B64 + 0x38));
        func_003A0E90(obj, buf);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("main/ssxappdtor", func_00245928);
#ifdef SKIP_ASM
extern void* D_0047C6D8[];
extern "C" void* func_0039E390(void* self);

extern "C" void* func_00245928(void* self)
{
    *(void**)((char*)self + 0x8) = D_0047C6D8;
    return func_0039E390(self);
}
#endif

