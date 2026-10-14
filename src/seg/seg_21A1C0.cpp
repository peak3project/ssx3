#include "common.h"

INCLUDE_ASM("seg/seg_21A1C0", func_003191C0);

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_003194A8);
#ifdef SKIP_ASM
extern "C" void func_003191C0(void* str, const char* fmt, char* ap);

// sprintf into a cBXString.
// PORT: SN-specific va_start (gcc 2.95 EE EABI form); use <stdarg.h> off-PS2.
extern "C" void func_003194A8(void* str, const char* fmt, ...)
{
    char* ap;
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_003191C0(str, fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_003194F0);
#ifdef SKIP_ASM
struct cBXString_94F0 {
    char* str;
};
extern "C" void func_00318120(void* self);
extern unsigned char D_00499C81[];

// Strips trailing white space (D_00499C81 is the ctype table + 1, bit 8 = space).
extern "C" void func_003194F0(cBXString_94F0* self)
{
    func_00318120(self);
    char* end = 0;
    char* p;
    for (p = self->str; *p != 0; p++) {
        if (end == 0)
            end = p;
        if (!(D_00499C81[(int)*p] & 8))
            end = 0;
    }
    if (end != 0) {
        *end = 0;
        *(int*)(self->str - 8) = end - self->str;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319578);
#ifdef SKIP_ASM
struct cBXString_9578 {
    char* str;
};
extern "C" void func_00318120(void* self);
extern "C" void* func_0041610C(void* dst, const void* src, int n);
extern unsigned char D_00499C81[];

// Strips leading white space.
extern "C" void func_00319578(cBXString_9578* self)
{
    func_00318120(self);
    char* p = self->str;
    while (D_00499C81[(int)*p] & 8)
        p++;
    int len = *(int*)(self->str - 8) - (p - self->str);
    func_0041610C(self->str, p, len + 1);
    *(int*)(self->str - 8) = len;
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319610);
#ifdef SKIP_ASM
extern "C" void func_00426408(int a);
extern "C" void func_0042AB18(void);
extern "C" void func_00319820(void* self);
extern "C" void func_00401718(int a);
extern "C" void func_00402450(int a);
extern "C" void func_00427D28(void);

extern "C" void func_00319610(void* self)
{
    func_00426408(0);
    func_0042AB18();
    func_00319820(self);
    func_00401718(0);
    func_00402450(2);
    func_00427D28();
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319660);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_0048D9D8[];
extern char D_0048D9C8[];

// Builds the IOP module directory ("cdrom0:\DATA\MODULES\").
extern "C" void func_00319660(void* self, char* out)
{
    sprintf(out, D_0048D9D8, D_0048D9C8);
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319690);
#ifdef SKIP_ASM
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" char* strchr(const char* s, int c);
extern "C" char* strcpy(char* d, const char* s);
extern "C" void func_00319660(void* self, char* out);
extern char D_004A3E98[];
extern char D_004A3EA0[];

// Full path of an IOP module: names with a device prefix are used as is, others get
// the module directory and the ";1" ISO version suffix.
extern "C" void func_00319690(void* self, char* out, const char* name)
{
    if (strchr(name, ':') != 0) {
        strcpy(out, name);
    } else {
        char dir[256];
        func_00319660(self, dir);
        sprintf(out, D_004A3E98, dir, name, D_004A3EA0);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319718);
#ifdef SKIP_ASM
extern "C" void func_00319690(void* self, char* out, const char* name);
extern "C" int func_0042BA68(const char* path, int argLen, const char* args);

// Loads an IOP module, retrying while the IOP is busy (-204) or always when 'retry' is set.
extern "C" int func_00319718(void* self, const char* name, int retry, int argLen, const char* args)
{
    char path[256];
    int r;
    func_00319690(self, path, name);
    do {
        r = func_0042BA68(path, argLen, args);
    } while (r < 0 && (retry != 0 || r == -204));
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319790);
#ifdef SKIP_ASM
extern "C" void func_0042B438(int fd, int a, int b, void* out);
extern "C" void func_0042B640(int fd);

extern "C" void func_00319790(void* self, int fd)
{
    char tmp[16];
    func_0042B438(fd, 0, 0, tmp);
    func_0042B640(fd);
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_003197D0);
#ifdef SKIP_ASM
extern "C" int func_00319718(void* self, const char* name, int retry, int argLen, const char* args);
extern void* D_004A3E94;
extern char D_0048D9E8[];

// Loads MSIFRPC.IRX.
extern "C" void func_003197D0(void* self)
{
    func_00319718(D_004A3E94, D_0048D9E8, 1, 0, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319800);
#ifdef SKIP_ASM
extern "C" void func_0040B1F8(void);

extern "C" void func_00319800(void* self)
{
    func_0040B1F8();
}
#endif

//100%
INCLUDE_ASM("seg/seg_21A1C0", func_00319820);
#ifdef SKIP_ASM
extern "C" void func_00426408(int a);
extern "C" void func_00401718(int a);
extern "C" void func_00402450(int a);
extern "C" void func_00319690(void* self, char* out, const char* name);
extern "C" int func_0042BF68(const char* path);
extern "C" int func_0042BF30(void);
extern "C" void func_0042AB18(void);
extern char D_0048D9F8[];

// Loads the DNAS image (DNAS271.IMG) and waits for it to finish.
extern "C" void func_00319820(void* self)
{
    char path[256];
    func_00426408(0);
    func_00401718(0);
    func_00402450(2);
    func_00319690(self, path, D_0048D9F8);
    while (func_0042BF68(path) == 0)
        ;
    while (func_0042BF30() == 0)
        ;
    func_00426408(0);
    func_0042AB18();
}
#endif

INCLUDE_ASM("seg/seg_21A1C0", func_003198A0);

INCLUDE_ASM("seg/seg_21A1C0", func_00319910);

INCLUDE_ASM("seg/seg_21A1C0", func_00319930);

INCLUDE_ASM("seg/seg_21A1C0", func_003199D0);
