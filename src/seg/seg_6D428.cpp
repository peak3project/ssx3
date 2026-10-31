#include "common.h"

//100%
INCLUDE_ASM("seg/seg_6D428", readTrigger);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern "C" int get_uint(void*, void*);
extern "C" int readVolume_C428(void*, void*, int) __asm__("readVolume");
extern "C" int readAction_C428(void*, void*, int) __asm__("readAction");

extern "C" int readTrigger(void* arg0, char **arg1, int arg2) {
    int r;
    get_uint(arg0, *arg1);
    get_uint(arg0, *arg1 + 4);
    r = readVolume_C428(arg0, *arg1 + 8, arg2);
    if (r == 0) {
        r = readAction_C428(arg0, *arg1 + 0xC, arg2);
        if (r == 0) {
            r = readAction_C428(arg0, *arg1 + 0x10, arg2);
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readVolume);
#ifdef SKIP_ASM
extern "C" int get_camvolume(void* reader, void** out);

extern "C" int readVolume(void* reader, void** out) {
    return (get_camvolume(reader, out) != 0) ? 0 : 4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readBoundObj);
#ifdef SKIP_ASM
extern "C" int get_camboundobj(void* reader, void** out);

extern "C" int readBoundObj(void* reader, void** out) {
    return (get_camboundobj(reader, out) != 0) ? 0 : 5;
}
#endif

//100%
INCLUDE_ASM("seg/seg_6D428", readAction);
#ifdef SKIP_ASM
extern "C" int get_camaction(void*, char**);
extern "C" int get_camspline(void*, char*);
extern "C" int readBoundObj_C510(void*, char*, int) __asm__("readBoundObj");

extern "C" int readAction(void* arg0, char** arg1, int arg2) {
    if (get_camaction(arg0, arg1) == 0) {
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
