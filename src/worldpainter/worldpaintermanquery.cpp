#include "common.h"

extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* cWorldPainterQuery_cWorldPainterQuery(void* self, void* arg);
extern const char D_00483DE8[];

struct cWorldPainterManArg {
    void* field_0x0;
};

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", cWorldPainterMan_getQuery__FPvP19cWorldPainterManArg);
#ifdef SKIP_ASM
void* cWorldPainterMan_getQuery(void* self, cWorldPainterManArg* x)
{
    void* mem = cMemMan_alloc(0x18, D_00483DE8, 0, 0);
    void* arg = x->field_0x0;
    return cWorldPainterQuery_cWorldPainterQuery(mem, arg);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0AA0);
#ifdef SKIP_ASM
extern "C" void func_002C0AA0(void* self, int* dst, int* src, float t)
{
    if (t == 1.0f) {
        *dst = *src;
    } else {
        *dst = (int)((float)*dst * (1.0f - t) + (float)*src * t);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0AF0);
#ifdef SKIP_ASM
extern "C" void func_002C0AF0(void* self, float* dst, float* src, float t)
{
    if (t == 1.0f) {
        *dst = *src;
    } else {
        *dst = *dst * (1.0f - t) + *src * t;
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0B30);
#ifdef SKIP_ASM
extern "C" void* func_002C0B30(void* a, ...)
{
    return a;
}
#endif
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C0B70);

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1458__FPv);
#ifdef SKIP_ASM
void func_002C1458(void* self)
{
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1460);
#ifdef SKIP_ASM
extern void* D_00485D30[];
void operator_delete(int* ptr);

// deleting destructor: reset the vtable, free when bit 0 of flags is set
extern "C" void func_002C1460(void* self, int flags)
{
    *(void***)((char*)self + 0x4) = D_00485D30;
    if (flags & 1) {
        operator_delete((int*)self);
    }
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1490__FPv);
#ifdef SKIP_ASM
void* func_002C1490(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1498__FPv);
#ifdef SKIP_ASM
void* func_002C1498(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14A0__FPv);
#ifdef SKIP_ASM
void* func_002C14A0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14A8__FPv);
#ifdef SKIP_ASM
void* func_002C14A8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14B0__FPv);
#ifdef SKIP_ASM
void* func_002C14B0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14B8__FPv);
#ifdef SKIP_ASM
void* func_002C14B8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14C0__FPv);
#ifdef SKIP_ASM
void* func_002C14C0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14C8__FPv);
#ifdef SKIP_ASM
void* func_002C14C8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14D0__FPv);
#ifdef SKIP_ASM
void* func_002C14D0(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14D8__FPv);
#ifdef SKIP_ASM
void* func_002C14D8(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14E0__FPv);
#ifdef SKIP_ASM
void* func_002C14E0(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14E8__FPv);
#ifdef SKIP_ASM
void* func_002C14E8(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14F0__FPv);
#ifdef SKIP_ASM
void* func_002C14F0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C14F8__FPv);
#ifdef SKIP_ASM
void* func_002C14F8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1500__FPv);
#ifdef SKIP_ASM
void* func_002C1500(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1508__FPv);
#ifdef SKIP_ASM
void* func_002C1508(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1510__FPv);
#ifdef SKIP_ASM
void* func_002C1510(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1518__FPv);
#ifdef SKIP_ASM
void* func_002C1518(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1520__FPv);
#ifdef SKIP_ASM
void* func_002C1520(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1528__FPv);
#ifdef SKIP_ASM
void* func_002C1528(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1530__FPv);
#ifdef SKIP_ASM
void* func_002C1530(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1538__FPv);
#ifdef SKIP_ASM
void* func_002C1538(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1540__FPv);
#ifdef SKIP_ASM
void* func_002C1540(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1548__FPv);
#ifdef SKIP_ASM
void* func_002C1548(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1550__FPv);
#ifdef SKIP_ASM
void* func_002C1550(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1558__FPv);
#ifdef SKIP_ASM
void* func_002C1558(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1560__FPv);
#ifdef SKIP_ASM
void* func_002C1560(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1568__FPv);
#ifdef SKIP_ASM
void* func_002C1568(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1570__FPv);
#ifdef SKIP_ASM
void* func_002C1570(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1578__FPv);
#ifdef SKIP_ASM
void* func_002C1578(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1580__FPv);
#ifdef SKIP_ASM
void* func_002C1580(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1588__FPv);
#ifdef SKIP_ASM
void* func_002C1588(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1590__FPv);
#ifdef SKIP_ASM
void* func_002C1590(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1598__FPv);
#ifdef SKIP_ASM
void* func_002C1598(void* self)
{
    return (char*)self + 0x40;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15A0__FPv);
#ifdef SKIP_ASM
void* func_002C15A0(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15A8__FPv);
#ifdef SKIP_ASM
void* func_002C15A8(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15B0__FPv);
#ifdef SKIP_ASM
void* func_002C15B0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15B8__FPv);
#ifdef SKIP_ASM
void* func_002C15B8(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15C0__FPv);
#ifdef SKIP_ASM
void* func_002C15C0(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15C8__FPv);
#ifdef SKIP_ASM
void* func_002C15C8(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15D0__FPv);
#ifdef SKIP_ASM
void* func_002C15D0(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15D8__FPv);
#ifdef SKIP_ASM
void* func_002C15D8(void* self)
{
    return (char*)self + 0x50;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15E0__FPv);
#ifdef SKIP_ASM
void* func_002C15E0(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15E8__FPv);
#ifdef SKIP_ASM
void* func_002C15E8(void* self)
{
    return (char*)self + 0x10;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15F0__FPv);
#ifdef SKIP_ASM
void* func_002C15F0(void* self)
{
    return (char*)self + 0x18;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C15F8__FPv);
#ifdef SKIP_ASM
void* func_002C15F8(void* self)
{
    return (char*)self + 0x20;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1600__FPv);
#ifdef SKIP_ASM
void* func_002C1600(void* self)
{
    return (char*)self + 0x28;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1608__FPv);
#ifdef SKIP_ASM
void* func_002C1608(void* self)
{
    return (char*)self + 0x30;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1610__FPv);
#ifdef SKIP_ASM
void* func_002C1610(void* self)
{
    return (char*)self + 0x38;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1618__FPv);
#ifdef SKIP_ASM
void* func_002C1618(void* self)
{
    return (char*)self + 0x40;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1620__FPv);
#ifdef SKIP_ASM
void* func_002C1620(void* self)
{
    return (char*)self + 0x48;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1628__FPv);
#ifdef SKIP_ASM
void* func_002C1628(void* self)
{
    return (char*)self + 0x50;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1630__FPv);
#ifdef SKIP_ASM
void* func_002C1630(void* self)
{
    return (char*)self + 0x58;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1638__FPv);
#ifdef SKIP_ASM
void* func_002C1638(void* self)
{
    return (char*)self + 0x60;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1640__FPv);
#ifdef SKIP_ASM
void* func_002C1640(void* self)
{
    return (char*)self + 0x68;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1648__FPv);
#ifdef SKIP_ASM
void* func_002C1648(void* self)
{
    return (char*)self + 0x70;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1650__FPv);
#ifdef SKIP_ASM
void* func_002C1650(void* self)
{
    return (char*)self + 0x78;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1658__FPv);
#ifdef SKIP_ASM
void* func_002C1658(void* self)
{
    return (char*)self + 0x80;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1660__FPv);
#ifdef SKIP_ASM
void* func_002C1660(void* self)
{
    return (char*)self + 0x88;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1668__FPv);
#ifdef SKIP_ASM
void* func_002C1668(void* self)
{
    return (char*)self + 0x90;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1670__FPv);
#ifdef SKIP_ASM
void* func_002C1670(void* self)
{
    return (char*)self + 0x98;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1678__FPv);
#ifdef SKIP_ASM
void* func_002C1678(void* self)
{
    return (char*)self + 0x8;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1680__FPv);
#ifdef SKIP_ASM
void* func_002C1680(void* self)
{
    return (char*)self + 0x10;
}
#endif

extern "C" void* func_002C0B70(int, int);

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1688__FPv);
#ifdef SKIP_ASM
void* func_002C1688(void* self)
{
    return func_002C0B70(1, 0xffff);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C16A8);
#ifdef SKIP_ASM
extern "C" void func_002C16A8(int self, int a, int b)
{
    *(int*)(self + 4) = a;
    *(int*)self = b;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C16B8);
#ifdef SKIP_ASM
extern "C" void func_002C16B8(unsigned short* p, unsigned short a, unsigned short b, unsigned short c, unsigned short d)
{
    p[0] = (a << 1) | 1;
    p[1] = (b << 1) | (p[1] & 1);
    p[2] = (c << 1) | (p[2] & 1);
    p[3] = (d << 1) | (p[3] & 1);
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1718);
#ifdef SKIP_ASM
extern "C" void func_002C1718(void *arg0) {
    (*(int *)((char*)(arg0) + (0))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C1728);
#ifdef SKIP_ASM
extern "C" unsigned short cQuadTree_getFreeNode();
extern "C" void func_002C16A8(int, int, int);

extern "C" void *func_002C1728(void *arg0, int arg1, int arg2, float fparg0, float fparg1, float fparg2) {
    (*(int *)((char*)(arg0) + (0x24))) = 0;
    (*(int *)((char*)(arg0) + (0x20))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(float *)((char*)(arg0) + (4))) = fparg0;
    (*(float *)((char*)(arg0) + (8))) = fparg1;
    (*(float *)((char*)(arg0) + (0))) = (float) (32768.0f / fparg2);
    (*(unsigned short *)((char*)(arg0) + (0x14))) = cQuadTree_getFreeNode();
    (*(short *)((char*)(arg0) + (0x16))) = 0;
    func_002C16A8((*(int *)((char*)(arg0) + (0x20))) + ((*(unsigned short *)((char*)(arg0) + (0x14))) * 8), arg1, arg2);
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
    (*(int *)((char*)(arg0) + (0x18))) = arg2;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("worldpainter/worldpaintermanquery", func_002C17C0__FPv);
#ifdef SKIP_ASM
void func_002C17C0(void* self)
{
    void* t0 = (char*)self + 0x28;
    *(void**)((char*)self + 0x20) = t0;
    *(void**)((char*)self + 0x24) = t0;
}
#endif

