#include "common.h"

//100%
INCLUDE_ASM("util/statemachine", cConsoleConfig_setTimeString);
#ifdef SKIP_ASM
extern "C" int func_002C27C0(char* buf, const char* fmt, ...);
extern "C" void func_002C25B8(char* dst, const char* src, int size);
extern char D_00486500[];
extern char D_00486510[];
extern char D_00486528[];

extern "C" void cConsoleConfig_setTimeString(void* self, char* dst, int size, int hour, int min, int sec, int mode)
{
    char buf[0x40];
    switch (mode) {
    case 0:
        func_002C27C0(buf, D_00486500, hour, min, sec);
        break;
    case 1:
        if (hour < 12) {
            func_002C27C0(buf, D_00486510, hour, min, sec);
        } else {
            func_002C27C0(buf, D_00486528, hour % 13 - 12, min, sec);
        }
        break;
    }
    func_002C25B8(dst, buf, size);
}
#endif

INCLUDE_ASM("util/statemachine", func_002C7038);

INCLUDE_ASM("util/statemachine", func_002C7100);

INCLUDE_ASM("util/statemachine", func_002C7160);

INCLUDE_ASM("util/statemachine", func_002C71C0);

INCLUDE_ASM("util/statemachine", func_002C7208);

INCLUDE_ASM("util/statemachine", func_002C7260);

INCLUDE_ASM("util/statemachine", func_002C7328);

INCLUDE_ASM("util/statemachine", func_002C73C0);

//100%
INCLUDE_ASM("util/statemachine", func_002C7440);
#ifdef SKIP_ASM
extern "C" void* cMemMan_alloc(int size, const char* tag, unsigned int flags, int d);
extern "C" void* func_002C7478(void* self);
extern char D_00486560[];

extern "C" void* func_002C7440(void)
{
    return func_002C7478(cMemMan_alloc(0x38, D_00486560, 0, 0));
}
#endif

INCLUDE_ASM("util/statemachine", func_002C7478);

INCLUDE_ASM("util/statemachine", func_002C76C0);

