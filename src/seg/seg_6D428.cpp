#include "common.h"

//100%
INCLUDE_ASM("seg/seg_6D428", readTrigger);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" void get_uint(int, void*);
extern "C" int readVolume_C428(int, void*, int) __asm__("readVolume");
extern "C" int readAction_C428(int, void*, int) __asm__("readAction");

extern "C" void readTrigger(int arg0, char **arg1, int arg2) {
    get_uint(arg0, *arg1);
    get_uint(arg0, *arg1 + 4);
    if (readVolume_C428(arg0, *arg1 + 8, arg2) == 0) {
        if (readAction_C428(arg0, *arg1 + 0xC, arg2) == 0) {
            readAction_C428(arg0, *arg1 + 0x10, arg2);
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readVolume);
#ifdef SKIP_ASM
extern "C" int get_camvolume();

extern "C" int readVolume(void) {
    return (get_camvolume() != 0) ? 0 : 4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readBoundObj);
#ifdef SKIP_ASM
extern "C" int get_camboundobj();

extern "C" int readBoundObj(void) {
    return (get_camboundobj() != 0) ? 0 : 5;
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readAction);
#ifdef SKIP_ASM
extern "C" int get_camaction(int, char**, int);
extern "C" void get_camspline(int, char*);
extern "C" int readBoundObj_C510(int, char*, int) __asm__("readBoundObj");

extern "C" int readAction(int arg0, char** arg1, int arg2) {
    if (get_camaction(arg0, arg1, arg2) == 0) {
        return 6;
    }
    char* p = *arg1;
    if (*(int*)p == 1) {
        return readBoundObj_C510(arg0, p + 8, arg2);
    }
    if (*(int*)p == 2) {
        get_camspline(arg0, p + 8);
        return 0;
    }
    return 0;
}
#endif
