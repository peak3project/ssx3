#include "common.h"

INCLUDE_ASM("scripter/all_in_one_scripter", __sti__all_in_one_scripter_cpp);

extern "C" void func_002847A8(void) {
}

extern "C" void func_002847B0(void) {
}

extern "C" void func_002847B8(void) {
}

extern "C" void func_002847C0(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847C8);
#ifdef SKIP_ASM
extern "C" int func_002847C8(int *arg0) {
    return *arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847D0);
#ifdef SKIP_ASM
extern "C" int func_002847D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847D8);
#ifdef SKIP_ASM
extern "C" int func_002847D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (8))) > 0;
}
#endif

extern "C" void func_002847E8(void) {
}

extern "C" void func_002847F0(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002847F8);
#ifdef SKIP_ASM
extern "C" int func_002847F8(void) {
    return 1;
}
#endif

extern "C" void func_00284800(void) {
}

extern "C" void func_00284808(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284810);
#ifdef SKIP_ASM
extern "C" int func_00284810(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284818);
#ifdef SKIP_ASM
extern "C" int func_00284818(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x2B4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284820);
#ifdef SKIP_ASM
extern "C" int func_00284820(void) {
    return 0;
}
#endif

extern "C" void func_00284828(void) {
}

extern "C" void func_00284830(void) {
}

extern "C" void func_00284838(void) {
}

extern "C" void func_00284840(void) {
}

extern "C" void func_00284848(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284850);
#ifdef SKIP_ASM
extern "C" int func_00284850(void *arg0) {
    return (*(int *)((char*)(arg0) + (8)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284858);
#ifdef SKIP_ASM
extern "C" int func_00284858(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284860);
#ifdef SKIP_ASM
extern "C" void func_00284860(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (4))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284868);
#ifdef SKIP_ASM
extern "C" void func_00284868(void *arg0) {
    (*(int *)((char*)(arg0) + (4))) = -1;
}
#endif

extern "C" void func_00284878(void) {
}

extern "C" void func_00284880(void) {
}

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284888);
#ifdef SKIP_ASM
extern "C" int func_00284888(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284890);
#ifdef SKIP_ASM
extern "C" void func_00284890(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x10))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284898);
#ifdef SKIP_ASM
extern "C" int func_00284898(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xC)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00283228_48A0(void *) __asm__("func_00283228");
extern char D_00482360[];
extern char D_00482398[];

extern "C" void func_002848A0(void *arg0) {
    *(char **)((char*)arg0 + 0x10) = D_00482360;
    *(char **)((char*)arg0 + 0xC) = D_00482398;
    func_00283228_48A0(arg0);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848D0);
#ifdef SKIP_ASM
extern "C" int func_002848D0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0xF8)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002848D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00283228_48D8(void *, int) __asm__("func_00283228");
void operator_delete(int *);
extern char D_004822E0[];
extern char D_00482318[];

extern "C" void func_002848D8(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482318;
    *(char **)((char*)arg0 + 0x0) = D_004822E0;
    func_00283228_48D8((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284940);
#ifdef SKIP_ASM
extern "C" int func_00284940(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284948);
#ifdef SKIP_ASM
extern "C" int func_00284948(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284950);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00283228_4950(void *, int) __asm__("func_00283228");
void operator_delete(int *);
extern char D_00482260[];
extern char D_00482298[];

extern "C" void func_00284950(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482298;
    *(char **)((char*)arg0 + 0x0) = D_00482260;
    func_00283228_4950((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849B8);
#ifdef SKIP_ASM
extern "C" int func_002849B8(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849C0);
#ifdef SKIP_ASM
extern "C" int func_002849C0(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849C8);
#ifdef SKIP_ASM
extern "C" int func_002849C8(int *arg0) {
    return *arg0 != 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849D8);
#ifdef SKIP_ASM
extern "C" int func_002849D8(void *arg0) {
    return (*(int *)((char*)(arg0) + (4)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849E0);
#ifdef SKIP_ASM
extern "C" int func_002849E0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x550))) != 2;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849F0);
#ifdef SKIP_ASM
extern "C" int func_002849F0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x550)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_002849F8);
#ifdef SKIP_ASM
struct sSlot_49F8 {
    int f0;     // 0x628
    int f4;
    int f8;     // 0x630
    int fC;
};

struct sEngine_49F8 {
    char pad[0x628];
    sSlot_49F8 slots[1];
};

extern "C" int func_002849F8(sEngine_49F8* self, int idx)
{
    int r = 0;
    if (self->slots[idx].f8 == 0) {
        r = self->slots[idx].f0 == 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A28);
#ifdef SKIP_ASM
extern "C" void func_00283228();

extern "C" void func_00284A28(void) {
    func_00283228();
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A48);
#ifdef SKIP_ASM
extern "C" int func_00284A48(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x14)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A50);
#ifdef SKIP_ASM
extern "C" float func_00284A50(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x18)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A58);
#ifdef SKIP_ASM
extern "C" int func_00284A58(int arg0) {
    return arg0 + 0x30;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A60);
#ifdef SKIP_ASM
extern "C" float func_00284A60(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x70)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A68);
#ifdef SKIP_ASM
extern "C" float func_00284A68(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x74)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A70);
#ifdef SKIP_ASM
extern "C" float func_00284A70(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x78)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A78);
#ifdef SKIP_ASM
extern "C" int func_00284A78(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x7C)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A80);
#ifdef SKIP_ASM
extern "C" int func_00284A80(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A88);
#ifdef SKIP_ASM
extern "C" int func_00284A88(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A90);
#ifdef SKIP_ASM
extern "C" int func_00284A90(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284A98);
#ifdef SKIP_ASM
extern "C" void func_00284A98(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AA0);
#ifdef SKIP_ASM
extern "C" int func_00284AA0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x1C)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AA8);
#ifdef SKIP_ASM
extern "C" void func_00283228();

extern "C" void func_00284AA8(void) {
    func_00283228();
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AC8);
#ifdef SKIP_ASM
extern "C" int func_00284AC8(int arg0) {
    return arg0 + 0x18;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AD0);
#ifdef SKIP_ASM
extern "C" int func_00284AD0(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x10)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AD8);
#ifdef SKIP_ASM
extern "C" int func_00284AD8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AE0);
#ifdef SKIP_ASM
extern "C" int func_00284AE0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284AE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void func_00283228_4AE8(void *, int) __asm__("func_00283228");
void operator_delete(int *);
extern char D_00481FD8[];
extern char D_00482018[];

extern "C" void func_00284AE8(void *arg0, int arg1) {
    *(char **)((char*)arg0 + 0x18) = D_00482018;
    *(char **)((char*)arg0 + 0x0) = D_00481FD8;
    func_00283228_4AE8((char*)arg0 + 0xC, 0);
    if (arg1 & 1) {
        operator_delete((int *)arg0);
    }
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B50);
#ifdef SKIP_ASM
extern "C" int func_00284B50(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B58);
#ifdef SKIP_ASM
extern "C" int func_00284B58(int arg0) {
    return arg0;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B60);
#ifdef SKIP_ASM
extern "C" int func_00284B60(int arg0) {
    return arg0 + 0x30;
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B68);
#ifdef SKIP_ASM
extern "C" float func_00284B68(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x70)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B70);
#ifdef SKIP_ASM
extern "C" float func_00284B70(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x74)));
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B78);
#ifdef SKIP_ASM
extern "C" float func_00284B78(void *arg0) {
    return (*(float *)((char*)(arg0) + (0x78)));
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284B80);
#ifdef SKIP_ASM
extern "C" void __sti__all_in_one_scripter_cpp(int, int);

extern "C" void func_00284B80(void) {
    __sti__all_in_one_scripter_cpp(1, 0xFFFF);
}
#endif

//100%
INCLUDE_ASM("scripter/all_in_one_scripter", func_00284BA0);
#ifdef SKIP_ASM
extern "C" int func_00284BA0(int arg0) {
    return (arg0 != 0) ? 0 : 0x173;
}
#endif
