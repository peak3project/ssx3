#include "common.h"

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag__TagFieldSetupAppend__FPcN20);
#ifdef SKIP_ASM
char* cDirtysock_tag__TagFieldSetupAppend(char* buf, char* dst, char* name)
{
    if (name == 0) {
        *buf = 0;
    } else {
        while (*name != 0) {
            *dst++ = *name++;
        }
        *dst++ = '=';
    }
    return dst;
}
#endif

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag__TagFieldSetupTerm);

//100%
INCLUDE_ASM("dirtysock/tags", func_003EB578);
#ifdef SKIP_ASM
extern signed char D_004A4A70;

extern "C" signed char func_003EB578(signed char arg0) {
    signed char temp_2;

    temp_2 = D_004A4A70;
    D_004A4A70 = arg0;
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", func_003EB588);
#ifdef SKIP_ASM
extern "C" void func_003EB588(unsigned char* out, unsigned char sep)
{
    unsigned char* start = out;
    unsigned char* s = out;
    unsigned int c;
    unsigned int d;

    while (*s != 0) {
        c = *s;
        if (c < 0x20) {
            *out++ = sep;
            while ((unsigned int)(*s - 1) < 0x1F) {
                s++;
            }
            if (*s == '=' || *s == ':') {
                if (s[1] < 0x20) {
                    break;
                }
            }
        } else {
            *out++ = c;
            s++;
        }
    }
    if (out != start && out[-1] == sep) {
        out[-1] = (sep == 10 || *s != 0) ? 10 : 0;
    }
    c = *s;
    while (c != 0) {
        if (c < 0x20) {
            *out = 10;
            d = *s++;
            c = *s;
            out++;
            while ((unsigned int)(c - 1) < 0x1F && c != d) {
                s++;
                c = *s;
            }
        } else {
            *out++ = c;
            s++;
        }
        c = *s;
    }
    *out = 0;
}
#endif
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldFind);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003EB840);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char* cDirtysock_tag_TagFieldFind_B840(char* record, char* name) __asm__("cDirtysock_tag_TagFieldFind");
extern "C" char* strcpy(char* dst, const char* src);
extern "C" void func_004162D0_EB840(char* dst, const char* src) __asm__("func_004162D0");

extern "C" char* func_003EB840(char* record, char* prefix, char* name)
{
    char buf[256];
    char* r;
    if (prefix == 0) {
        r = cDirtysock_tag_TagFieldFind_B840(record, name);
    } else if (name == 0) {
        r = cDirtysock_tag_TagFieldFind_B840(record, prefix);
    } else {
        strcpy(buf, prefix);
        func_004162D0_EB840(buf, name);
        r = cDirtysock_tag_TagFieldFind_B840(record, buf);
    }
    return r;
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003EB8B8);
#ifdef SKIP_ASM
extern "C" unsigned char* cDirtysock_tag_TagFieldFind(char* record, char* name);
extern char D_004A4A78[];

extern "C" unsigned char* func_003EB8B8(char* record)
{
    unsigned char* p = cDirtysock_tag_TagFieldFind(record, D_004A4A78);
    if (p != 0) {
        while ((unsigned int)(*p - 1) < 0x20U) {
            p++;
        }
        if (*p == 0) {
            p = 0;
        }
    }
    return p;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldDelete);
#ifdef SKIP_ASM
extern "C" unsigned char* cDirtysock_tag_TagFieldFind(char* record, char* name);

extern "C" int cDirtysock_tag_TagFieldDelete(unsigned char* record, char* name)
{
    unsigned char* p = cDirtysock_tag_TagFieldFind((char*)record, name);
    unsigned char* dst;
    unsigned char* src;
    if (p == 0) {
        return -1;
    }
    dst = p;
    while (dst != record && dst[-1] > ' ') {
        dst--;
    }
    src = p;
    while (*src >= ' ') {
        src++;
    }
    while ((unsigned int)(*src - 1) < 0x1FU) {
        src++;
    }
    int c = *src;
    if (c != 0) {
        do {
            *dst = c;
            src++;
            c = *src;
            dst++;
        } while (c != 0);
    }
    *dst = 0;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003EB9E8);
#ifdef SKIP_ASM
extern "C" unsigned char* cDirtysock_tag_TagFieldFind(char* record, char* name);
extern "C" unsigned int strlen(const char* s);

extern "C" int func_003EB9E8(unsigned char* record, int len, char* name, const signed char* value)
{
    unsigned char* p = cDirtysock_tag_TagFieldFind((char*)record, name);
    unsigned char* start;
    unsigned char* q;
    int delta;

    if (p == 0) {
        return -1;
    }
    if (p[-1] == ' ') {
        p--;
    }
    start = p - 1;
    p = start;
    while (start != record && start[-1] >= 0x21) {
        start--;
    }
    delta = strlen((const char*)value) - (p - start);
    if (delta < 0) {
        unsigned char c = *p;
        if (c != 0) {
            unsigned char* dst = p + delta;
            *dst = c;
            while ((c = *p) != 0) {
                *dst = c;
            }
        }
        *p = 0;
    }
    if (delta > 0) {
        q = p;
        if (*q != 0) {
            do {
                q++;
            } while (*q != 0);
        }
        if (q - record < len - delta) {
            return -1;
        }
        if (q != p) {
            do {
                unsigned char t = *q;
                unsigned char* d = q + delta;
                q--;
                *d = t;
            } while (q != p);
        }
    }
    while (*value != 0) {
        *start = (unsigned char)*value;
        value++;
        start++;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldDupl);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldDupl(char* dst, int len, const char* src)
{
    int left = len;
    while (left > 1 && *src != 0) {
        *dst++ = *src++;
        left--;
    }
    if (left > 0) {
        *dst = 0;
    }
    return len - left;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", func_003EBBA8);
#ifdef SKIP_ASM
extern "C" int func_003EBBA8(unsigned char* rec, char* out, int size)
{
    unsigned char* p;
    unsigned char* s;
    unsigned int c;
    unsigned int next;
    int n;

    n = 0;
    if (size > 0) {
        *out = 0;
    }
    if (rec == 0 || *rec == 0) {
        return 0;
    }
    for (p = rec; ; p++) {
        c = *p;
        if (c == 0) {
            break;
        }
        if (c == '=' || c == ':') {
            next = p[1];
            if (next < 0x20 && p[-1] < 0x21) {
                break;
            }
            for (s = p; s != rec && s[-1] > 0x20; s--) {
            }
            while (s != p && n + 1 < size) {
                out[n++] = *s++;
            }
            out[n] = 0;
            break;
        }
    }
    return n;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tags", func_003EBCB0);
#ifdef SKIP_ASM
extern "C" int func_003EBCB0(char* record, int len, const char* value)
{
    char* p = record;
    char* end;
    for (;;) {
        unsigned char c = *p;
        if (c == 0) {
            break;
        }
        if (c == '=' || c == ':') {
            if ((unsigned char)p[1] < 0x20) {
                break;
            }
        }
        p++;
    }
    *p = 0;
    if (value == 0) {
        return 0;
    }
    end = record + len - 1;
    if (end - p < 5) {
        return -1;
    }
    *p++ = '=';
    *p++ = '\n';
    while (*value != 0 && p != end) {
        *p++ = *value++;
    }
    *p = 0;
    return 0;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tags", func_003EBD70);
#ifdef SKIP_ASM
extern signed char D_004A4A70;
extern signed char D_004A4A80[];

extern "C" int func_003EBD70(unsigned char* buf, int len)
{
    const signed char* s = D_004A4A80;
    int ret = -1;
    int n = 0;
    if (*buf != 0) {
        do {
            n++;
        } while (buf[n] != 0);
    }
    if (n > 0) {
        if (buf[n - 1] >= 0x20) {
            if (buf[n - 1] != D_004A4A70) {
                if (n < len - 1) {
                    buf[n] = (unsigned char)D_004A4A70;
                    n++;
                    buf[n] = 0;
                }
            }
        }
    }
    if (n + 4 < len) {
        while (*s != 0) {
            buf[n++] = (unsigned char)*s;
            s++;
        }
        ret = 0;
        buf[n] = 0;
    }
    return ret;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetNumber);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);

extern "C" int cDirtysock_tag_TagFieldSetNumber(char* record, int len, char* name, int value)
{
    char temp[256 + 32];
    unsigned char* num;
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);

    if (value < 0) {
        *data++ = '-';
        value = -value;
    }
    num = (unsigned char*)data + 31;
    *num = 0;
    while (value > 0) {
        *--num = '0' + (value % 10);
        value /= 10;
    }
    if (*num == 0)
        *--num = '0';
    do {
        *data++ = *num++;
    } while (*num != 0);
    *data = 0;
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetFlags);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);
extern char D_004965C0[];

extern "C" int cDirtysock_tag_TagFieldSetFlags(char* record, int len, char* name, int value)
{
    char temp[256 + 32];
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);
    const char* flags = D_004965C0;
    for (; (value != 0) && (*flags != 0); value >>= 1, flags++) {
        if (value & 1) {
            *data++ = *flags;
        }
    }
    *data = 0;
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetAddress);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);

extern "C" int cDirtysock_tag_TagFieldSetAddress(char* record, int len, char* name, unsigned int addr)
{
    int i;
    unsigned char bytes[4];
    char temp[256 + 32];
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);

    bytes[3] = (unsigned char)addr;
    addr >>= 8;
    bytes[2] = (unsigned char)addr;
    addr >>= 8;
    bytes[1] = (unsigned char)addr;
    addr >>= 8;
    bytes[0] = (unsigned char)addr;
    for (i = 0; i < 4; i++) {
        unsigned char c = bytes[i];
        if (i > 0)
            *data++ = '.';
        if (c >= 10) {
            if (c >= 100) {
                *data++ = '0' + c / 100;
                c %= 100;
            }
            *data++ = '0' + c / 10;
            c %= 10;
        }
        *data++ = '0' + c;
    }
    *data = 0;
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetFourCC);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);

extern "C" int cDirtysock_tag_TagFieldSetFourCC(char* record, int len, char* name, int value)
{
    char temp[256 + 32];
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);
    for (; value != 0; value <<= 8) {
        if (value > 0x20FFFFFF) {
            *data++ = (char)(value >> 24);
        }
    }
    *data = 0;
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetString);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetBinary);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);
extern unsigned char D_00495FC0[];
extern unsigned char D_004960C0[];

extern "C" int cDirtysock_tag_TagFieldSetBinary(char* record, int len, char* name, const void* value, int size)
{
    const unsigned char* src = (const unsigned char*)value;
    char temp[4096 + 256];
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);
    *data++ = '$';
    for (; size > 0; --size) {
        *data++ = D_00495FC0[*src];
        *data++ = D_004960C0[*src++];
    }
    *data = 0;
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetStructure);
#ifdef SKIP_ASM
// Tables are const (read-only): lets the scheduler hoist the table loads above the byte stores.
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);
extern const unsigned char kHexHi[] __asm__("D_00495FC0");
extern const unsigned char kHexLo[] __asm__("D_004960C0");
extern const unsigned char kSafe[] __asm__("D_004964C0");

// Release-build assert: compiles to an empty do { } while (0) (its loop notes still shape the code)
#define ASSERT_ture(cond) do { } while (0)
extern "C" int cDirtysock_tag_TagFieldSetStructure(char* record, int len, char* name, const char* buffer, int size, const char* tmpl)
{
    char temp[2560];
    const char* buf = buffer;
    const char* limit;
    char* out;
    int count;
    unsigned int val;
    int c;
    const unsigned char* str;

    val = 0;
    if (size < 0) {
        limit = buf + 65536;
    } else {
        limit = buf + size;
    }
    out = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);
    while (*tmpl != 0) {
        char t;
        if (*tmpl == '#') {
            for (++tmpl; (*tmpl != 0) && (*tmpl++ != '='); ) {
            }
        }
        c = (unsigned char)*tmpl;
        for (count = 0; (unsigned int)(c - 48) < 10; c = (unsigned char)*tmpl) {
            tmpl++;
            count = count * 10 + (c & 15);
        }
        c = 0;
        str = 0;
        if (*tmpl == 'a') {
            if (count != 0) {
                buf += count;
            } else {
                buf += 1;
            }
        }
        t = (char)*(unsigned char*)tmpl;
        if (t == 'b') {
            val = *(const unsigned char*)buf;
            c = 2;
            buf += 1;
        }
        if (t == 'w') {
            val = *(const unsigned short*)buf;
            c = 4;
            buf += 2;
        }
        if (t == 'l') {
            val = *(const unsigned int*)buf;
            c = 8;
            buf += 4;
        }
        if (t == 's') {
            str = (const unsigned char*)buf;
            buf += count;
        }
        if (limit < buf) {
            break;
        }
        if (c > 0) {
            char* p;
            char* q;
            if (val > 0xFFFF0000U) {
                val = -val;
                *out++ = '-';
            }
            p = out + c;
            q = p;
            *p = 0;
            for (; val != 0; val >>= 4) {
                *--q = kHexLo[val & 15];
            }
            if (!(out != q)) {
                out = p;
            } else {
                while (*q != 0) {
                    *out++ = *q++;
                }
                *out++ = ',';
            }
        }
        if (str != 0) {
            while (*str != 0) {
                val = *str++;
                if (!(kSafe[val] == 0)) {
                    *out++ = val;
                } else {
                    *out++ = '%';
                    *out++ = kHexHi[val];
                    *out++ = kHexLo[val];
                }
            }
            *out++ = ',';
        }
        ++tmpl;
        if (*tmpl == '*') {
            --tmpl;
        }
    }
    if (out[-1] == ',') {
        do {
            out--;
        } while (out[-1] == ',');
        *out = 0;
    } else {
        *out = 0;
    }
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetCrypt);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetEpoch);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern char D_00496A40[];

struct sDsTmK2 {
    int tm_sec;   // 0x0
    int tm_min;   // 0x4
    int tm_hour;  // 0x8
    int tm_mday;  // 0xC
    int tm_mon;   // 0x10
    int tm_year;  // 0x14
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

// ds_timeinsecs / ds_secstotime
extern "C" unsigned int func_003EF088();
extern "C" sDsTmK2* func_003EAEB8(sDsTmK2* tm, unsigned long secs);

// PORT: epoch is widened to 64-bit `unsigned long` (zero-extended) for ds_secstotime.
extern "C" int cDirtysock_tag_TagFieldSetEpoch(char* record, int len, char* name, unsigned int epoch)
{
    sDsTmK2 tm;
    char temp[256 + 32];
    sDsTmK2* t;
    unsigned long secs = epoch;

    if (secs == 0)
        secs = func_003EF088();
    t = func_003EAEB8(&tm, secs);
    if (t == 0)
        return -1;
    char* data = cDirtysock_tag__TagFieldSetupAppend(record, temp, name);
    sprintf(data, D_00496A40, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return cDirtysock_tag__TagFieldSetupTerm(record, len, temp);
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", func_003EC8B8);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int value, int size);
// PORT: ds_tmtosecs returns a 64-bit `unsigned long`.
extern "C" unsigned long func_003EB090(sDsTmK2* tm);

extern "C" int func_003EC8B8(char* record, int len, char* name, int year, int mon, int day, int hour, int min, int sec, int adj)
{
    sDsTmK2 tm;
    int secs;

    func_00416210(&tm, 0, sizeof(tm));
    tm.tm_isdst = -1;
    tm.tm_year = year - 1900;
    tm.tm_mon = mon - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = min;
    tm.tm_sec = sec;
    secs = (int)func_003EB090(&tm);
    return cDirtysock_tag_TagFieldSetEpoch(record, len, name, secs != 0 ? secs - adj : 0);
}
#endif
//100%
INCLUDE_ASM("dirtysock/tags", func_003EC9A0);
#ifdef SKIP_ASM
extern "C" void* func_00416210(void* dst, int value, int size);
// PORT: ds_tmtosecs returns a 64-bit `unsigned long`.
extern "C" unsigned long func_003EB090(sDsTmK2* tm);

extern "C" int func_003EC9A0(char* record, int len, char* name, int date, int time, int adj)
{
    sDsTmK2 tm;
    int secs;

    func_00416210(&tm, 0, sizeof(tm));
    tm.tm_isdst = -1;
    tm.tm_year = ((date >> 16) & 0xFFFF) - 1900;
    tm.tm_mon = ((date >> 8) & 0xFF) - 1;
    tm.tm_mday = date & 0xFF;
    tm.tm_hour = (time >> 16) & 0xFF;
    tm.tm_min = (time >> 8) & 0xFF;
    tm.tm_sec = time & 0xFF;
    secs = (int)func_003EB090(&tm);
    return cDirtysock_tag_TagFieldSetEpoch(record, len, name, secs != 0 ? secs - adj : 0);
}
#endif
//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003ECA88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char* cDirtysock_tag_TagFieldFind_CA88(char* record, char* name) __asm__("cDirtysock_tag_TagFieldFind");
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);

extern "C" int func_003ECA88(char* record, int len, char* name, char* data)
{
    char* p = cDirtysock_tag_TagFieldFind_CA88(data, name);
    int r = 0;
    if (p != 0) {
        while (p != data) {
            if ((unsigned char)p[-1] < 0x20U) {
                break;
            }
            p--;
        }
        r = cDirtysock_tag__TagFieldSetupTerm(record, len, p);
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003ECB00);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag__TagFieldSetupTerm(char* record, int len, char* temp);

// TagFieldMerge: apply every field of `data` to the record; returns how many were set.
extern "C" int func_003ECB00(char* record, int len, unsigned char* data)
{
    int count = 0;
    for (;;) {
        unsigned char c = *data;
        if (c == 0)
            break;
        // skip whitespace
        if (c <= ' ') {
            ++data;
            continue;
        }
        // stop at a separator
        if ((c == '=') || (c == ':'))
            break;
        // add the field
        if (cDirtysock_tag__TagFieldSetupTerm(record, len, (char*)data) > 0)
            ++count;
        // skip to the next field
        while (*data >= ' ')
            ++data;
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", func_003ECBD8);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldSetString(char* record, int len, char* name, const char* value);
extern "C" int cDirtysock_tag_TagFieldSetNumber(char* record, int len, char* name, int value);
extern "C" int cDirtysock_tag_TagFieldSetAddress(char* record, int len, char* name, unsigned int addr);
extern "C" int cDirtysock_tag_TagFieldSetFlags(char* record, int len, char* name, int value);
extern "C" int cDirtysock_tag_TagFieldSetEpoch(char* record, int len, char* name, unsigned int epoch);
extern signed char D_004A4A70;
extern char D_004A4A90[];

// Formats a tag record: %s %d %a %f %e %r each append one field.
// PORT: SN-specific va_start (gcc 2.95 EE EABI form); use <stdarg.h> off-PS2.
extern "C" int func_003ECBD8(char* buf, int len, const char* fmt, ...)
{
    char* ap;
    int orig = len;
    unsigned int c;
    ap = (char*)__builtin_next_arg() - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    while ((c = *(const unsigned char*)fmt++) != 0 && len >= 2) {
        if (c <= ' ') {
            len--;
            *buf++ = D_004A4A70;
            if (*fmt != 0) {
                while (*fmt != 0 && *fmt <= ' ')
                    fmt++;
            }
        } else if (c != '%') {
            *buf++ = c;
            len--;
        } else if (*fmt != 0) {
            int n = 0;
            c = *(const unsigned char*)fmt++;
            if (buf[-1] == '=') {
                buf--;
                len++;
            }
            *buf = 0;
            if (c == 's') {
                n = cDirtysock_tag_TagFieldSetString(buf, len, D_004A4A90, (ap += 8, *(const char**)(ap - 8)));
            } else if (c == 'd') {
                n = cDirtysock_tag_TagFieldSetNumber(buf, len, D_004A4A90, (ap += 8, *(int*)(ap - 8)));
            } else if (c == 'a') {
                n = cDirtysock_tag_TagFieldSetAddress(buf, len, D_004A4A90, (ap += 8, *(unsigned int*)(ap - 8)));
            } else if (c == 'f') {
                n = cDirtysock_tag_TagFieldSetFlags(buf, len, D_004A4A90, (ap += 8, *(int*)(ap - 8)));
            } else if (c == 'e') {
                n = cDirtysock_tag_TagFieldSetEpoch(buf, len, D_004A4A90, (ap += 8, *(unsigned int*)(ap - 8)));
            } else if (c == 'r') {
                ap += 8;
                const char* s = *(const char**)(ap - 8);
                for (; *s != 0 && len > 0; len--)
                    *buf++ = *s++;
            }
            if (n > 0) {
                buf += n;
                len -= n;
            }
        }
    }
    if (len > 0)
        *buf = 0;
    return orig - len;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", func_003ECE38);
#ifdef SKIP_ASM
extern "C" char* func_003ECE38(unsigned char* rec, int unused, char* out, int size, char* def)
{
    unsigned char* p;
    unsigned char* s;
    int c;
    unsigned int next;
    int i;
    int n;

    for (p = rec; ; p++) {
        c = *p;
        if (c == 0) {
            break;
        }
        if (c == '=' || c == ':') {
            next = p[1];
            if (next < 0x20) {
                if (next == 0) {
                    break;
                }
                p += 2;
                if (out != 0) {
                    n = size - 1;
                    i = 0;
                    if (n > 0 && *p != 0) {
                        s = p;
                        do {
                            out[i++] = *s++;
                        } while (i < n && *s != 0);
                    }
                    out[i] = 0;
                }
                return (char*)p;
            }
        }
    }
    if (out != 0 && def != 0) {
        n = size - 1;
        i = 0;
        for (; i < n && def[i] != 0; i++) {
            out[i] = def[i];
        }
        out[i] = 0;
    }
    return 0;
}
#endif
//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetNumber);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetNumber(const char* data, int defval)
{
    int sign;
    int value;
    if (data == 0) {
        return defval;
    }
    sign = 1;
    if (*data == '+') {
        ++data;
    } else if (*data == '-') {
        ++data;
        sign = -1;
    }
    for (value = 0; (*data >= '0') && (*data <= '9'); ) {
        value = (value * 10) + (*data++ & 15);
    }
    return sign * value;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetFlags);
#ifdef SKIP_ASM
extern int D_004965E0[];

extern "C" int cDirtysock_tag_TagFieldGetFlags(const char* data, int defval)
{
    if (data != 0) {
        int flags = 0;
        int f;
        while ((f = D_004965E0[*data]) != 0) {
            flags |= f;
            data++;
        }
        defval = flags;
    }
    return defval;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetAddr);
#ifdef SKIP_ASM
extern "C" unsigned int cDirtysock_tag_TagFieldGetAddr(const char* data, unsigned int defval)
{
    unsigned int addr = 0;
    if (data != 0) {
        for (;; data++) {
            if ((*data >= '0') && (*data <= '9')) {
                addr = (addr & 0xFFFFFF00) | (((addr & 0xFF) * 10) + (*data & 15));
            } else if (*data == '.') {
                addr <<= 8;
            } else {
                break;
            }
        }
        defval = addr;
    }
    return defval;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetFourCC);
#ifdef SKIP_ASM
extern "C" int cDirtysock_tag_TagFieldGetFourCC(const char* data, int defval)
{
    int token;
    if ((data == 0) || (*data <= ' ') || (*data >= 127)) {
        return defval;
    }
    for (token = 0x20202020; (token < 0x20FFFFFF) && (*data > ' ') && (*data < 127); data++) {
        token = (token << 8) | *data;
    }
    return token;
}
#endif

INCLUDE_ASM("dirtysock/tags", func_003ED0F8);

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetString);
#ifdef SKIP_ASM
extern "C" int strlen_m616(const char* s) __asm__("strlen");
extern unsigned char D_004961C0[];
extern unsigned char D_004962C0[];

// TagFieldGetString: copy a (optionally quoted) string field, decoding %xx escapes; returns its length.
extern "C" int cDirtysock_tag_TagFieldGetString(const char* data, char* buf, int len, const char* defval)
{
    int count;
    unsigned char term;
    const unsigned char* src;

    // handle default
    if (data == 0) {
        if (defval == 0) {
            return -1;
        }
        if (buf == 0) {
            return strlen_m616(defval);
        }
        for (count = 1; (count < len) && (*defval != 0); count++) {
            *buf++ = *defval++;
        }
        *buf = 0;
        return count - 1;
    }

    // check for quote
    if ((*data == '"') || (*data == '\'')) {
        term = *data++;
    } else {
        term = 0;
    }

    // calc length
    if (buf == 0) {
        for (count = 0, src = (const unsigned char*)data; (*src != term) && (*src >= ' '); count++) {
            if ((src[0] == '%') && (src[1] >= ' ') && (src[2] >= ' ')) {
                src += 2;
            }
            src++;
        }
        return count;
    }

    if (len <= 0) {
        return -1;
    }

    for (count = 1, src = (const unsigned char*)data; (count < len) && (*src != term) && (*src >= ' '); ) {
        if ((src[0] == '%') && (src[1] == '%')) {
            *buf++ = '%';
            src += 2;
            count++;
        } else if ((src[0] == '%') && (src[1] >= ' ') && (src[2] >= ' ')) {
            *buf++ = D_004961C0[src[1]] | D_004962C0[src[2]];
            src += 3;
            count++;
        } else {
            *buf++ = *src++;
            count++;
        }
    }
    *buf = 0;
    return count - 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetBinary);
#ifdef SKIP_ASM
extern unsigned char D_004961C0[];
extern unsigned char D_004962C0[];

extern "C" int cDirtysock_tag_TagFieldGetBinary(const char* data, void* buffer, int len)
{
    int count;
    const char* p;
    char* buf = (char*)buffer;

    if ((data == 0) || (*data != '$')) {
        return -1;
    }
    if (buf == 0) {
        for (count = 0, p = data + 1; ((unsigned char)p[0] >= '0') && ((unsigned char)p[1] >= '0'); count++) {
            p += 2;
        }
        return count;
    }
    p = data + 1;
    if (len <= 0) {
        return -1;
    }
    for (count = 0; (count < len) && ((unsigned char)p[0] >= '0') && ((unsigned char)p[1] >= '0'); count++) {
        *buf++ = D_004961C0[(unsigned char)p[0]] | D_004962C0[(unsigned char)p[1]];
        p += 2;
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetStructure);
#ifdef SKIP_ASM
extern char D_004A4A90[];

extern "C" int cDirtysock_tag_TagFieldGetStructure(const char* data, void* buffer, int len, const char* tmpl)
{
    int count;
    int size;
    int sign;
    unsigned int value;
    char* buf = (char*)buffer;
    char* limit;
    char temp[1024];

    if (len < 0) {
        limit = buf + 65535;
    } else {
        limit = buf + len;
    }
    if (data == 0) {
        data = D_004A4A90;
    }
    if (buf == 0) {
        buf = (char*)(buffer = temp);
    }
    while (*tmpl != 0) {
        if (*tmpl == '#') {
            for (++tmpl; (*tmpl != 0) && (*tmpl++ != '='); ) {
            }
        }
        for (count = 0; (*tmpl >= '0') && (*tmpl <= '9'); ++tmpl) {
            count = (count * 10) + (*tmpl & 15);
        }
        if (*tmpl == 'a') {
            if (count != 0) {
                buf += count;
            } else {
                buf += 1;
            }
        }
        size = 0;
        if (*tmpl == 'b') {
            size = 2;
        }
        if (*tmpl == 'w') {
            size = 4;
        }
        if (*tmpl == 'l') {
            size = 8;
        }
        if (size > 0) {
            sign = *data;
            if (sign == '-') {
                ++data;
            }
            for (value = 0; (size > 0) && (*data >= '0'); --size) {
                value = (value << 4) | D_004962C0[*data++];
            }
            if ((size > 0) && (*data == ',')) {
                ++data;
            }
            if (sign == '-') {
                value = -value;
            }
            if (*tmpl == 'b') {
                *buf++ = value;
            }
            if (*tmpl == 'w') {
                *(short*)buf = value;
                buf += 2;
            }
            if (*tmpl == 'l') {
                *(int*)buf = value;
                buf += 4;
            }
        }
        if ((*tmpl == 's') && (count > 0)) {
            for (size = 0; ((*data >= '0') || (*data == '%')) && (size + 1 < count); ++size) {
                if (*data == '%') {
                    buf[size] = D_004961C0[data[1]] | D_004962C0[data[2]];
                    data += 3;
                } else {
                    buf[size] = *data++;
                }
            }
            for (; size < count; ++size) {
                buf[size] = 0;
            }
            if (*data == ',') {
                ++data;
            }
            buf += size;
        }
        if (buf >= limit) {
            break;
        }
        ++tmpl;
        if (*tmpl == '*') {
            --tmpl;
        }
    }
    return buf - (char*)buffer;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetCrypt);
#ifdef SKIP_ASM
extern unsigned char D_004961C0[];
extern unsigned char D_004962C0[];
extern char D_004A4A88[];
extern "C" int cDirtysock_tag_TagFieldGetString(const char* data, char* buf, int len, const char* defval);

extern "C" int cDirtysock_tag_TagFieldGetCrypt(const char* data, char* buf, int len, const unsigned char* key, const char* defval)
{
    int count;
    const char* p;
    const unsigned char* kbase = key;
    const unsigned char* k;
    int prev;
    if (data == 0) {
        return -1;
    }
    if (*data != '$') {
        return cDirtysock_tag_TagFieldGetString(data, buf, len, defval);
    }
    if (kbase == 0 || *kbase == 0) {
        kbase = (const unsigned char*)D_004A4A88;
    }
    if (buf == 0) {
        for (count = 0, p = data + 1; (unsigned char)p[0] >= '0' && (unsigned char)p[1] >= '0'; count++) {
            p += 2;
        }
        return count;
    }
    count = 1;
    if (len <= 0) {
        return -1;
    }
    p = data + 1;
    k = kbase;
    prev = 0;
    for (; count < len && (unsigned char)p[0] >= '0' && (unsigned char)p[1] >= '0'; count++) {
        unsigned int c = *k ^ (D_004961C0[(unsigned char)p[0]] | D_004962C0[(unsigned char)p[1]]);
        if (*++k == 0) {
            k = kbase;
        }
        *buf++ = ((c << 5) | (c >> 3)) ^ prev;
        int hi = D_004961C0[(unsigned char)p[0]];
        int lo = D_004962C0[(unsigned char)p[1]];
        prev = lo | hi;
        p += 2;
    }
    *buf = 0;
    return count - 1;
}
#endif

//100%
INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldGetTime);
#ifdef SKIP_ASM
// _TagFieldParseNumber / memset / ds_tmtosecs
extern "C" char* func_003EAE68(const char* data, int* value);
extern "C" void* func_00416210(void* dst, int value, int size);
// PORT: ds_tmtosecs returns a 64-bit `unsigned long`.
extern "C" unsigned long func_003EB090(sDsTmK2* tm);

extern "C" unsigned int cDirtysock_tag_TagFieldGetTime(char* data, unsigned int defval)
{
    sDsTmK2 tm;
    int value;
    unsigned int result = 0;

    if (data != 0) {
        if (*data == '$') {
            for (++data; *data >= '0'; ++data) {
                result = (result << 4) | D_004962C0[*data];
            }
        } else if ((*data >= '0') && (*data <= '9')) {
            const char* p = func_003EAE68(data, &value);
            if (*p <= ' ') {
                result = value;
            } else if ((*data >= '0') && (*data <= '9')) {
                func_00416210(&tm, 0, sizeof(tm));
                tm.tm_isdst = -1;
                data = func_003EAE68(data, &tm.tm_year);
                if ((unsigned char)(*data - '-') <= 1) {
                    data++;
                }
                data = func_003EAE68(data, &tm.tm_mon);
                if ((unsigned char)(*data - '-') <= 1) {
                    data++;
                }
                data = func_003EAE68(data, &tm.tm_mday);
                if (*data == ' ') {
                    data++;
                }
                data = func_003EAE68(data, &tm.tm_hour);
                if (*data == ':') {
                    data++;
                }
                data = func_003EAE68(data, &tm.tm_min);
                if (*data == ':') {
                    data++;
                }
                data = func_003EAE68(data, &tm.tm_sec);
                if ((tm.tm_year < 1970) || (tm.tm_year > 2099) || (tm.tm_mon < 1) || (tm.tm_mon > 12) || (tm.tm_mday < 1) || (tm.tm_mday > 31)) {
                    tm.tm_year = 0;
                }
                if ((tm.tm_hour < 0) || (tm.tm_hour > 23) || (tm.tm_min < 0) || (tm.tm_min > 59) || (tm.tm_sec < 0) || (tm.tm_sec > 61)) {
                    tm.tm_year = 0;
                }
                if (tm.tm_year != 0) {
                    tm.tm_year -= 1900;
                    tm.tm_mon -= 1;
                    result = func_003EB090(&tm);
                }
            }
        }
    }
    if (result == 0) {
        result = defval;
        if (result == 0) {
            result = func_003EF088();
        }
    }
    return result;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("dirtysock/tags", func_003EDD70);
#ifdef SKIP_ASM
extern "C" unsigned int cDirtysock_tag_TagFieldGetTime(char* data, unsigned int dflt);

// TagFieldGetDate-style accessor: split a time tag into calendar fields.
extern "C" int func_003EDD70(char* data, int* year, int* month, int* day, int* hour, int* min, int* sec, int offset)
{
    sDsTmK2 tm;
    sDsTmK2* t;
    unsigned int secs = cDirtysock_tag_TagFieldGetTime(data, 1);
    if (secs < 2)
        return -1;
    t = func_003EAEB8(&tm, secs + offset);
    if (t == 0)
        return -1;
    if (year)
        *year = t->tm_year + 1900;
    if (month)
        *month = t->tm_mon + 1;
    if (day)
        *day = t->tm_mday;
    if (hour)
        *hour = t->tm_hour;
    if (min)
        *min = t->tm_min;
    if (sec)
        *sec = t->tm_sec;
    return 0;
}
#endif


//100%
INCLUDE_ASM("dirtysock/tags", func_003EDE80);
#ifdef SKIP_ASM
extern "C" int func_003EDE80(char* data, unsigned int* date, unsigned int* time, int offset)
{
    sDsTmK2 tm;
    sDsTmK2* t;
    unsigned int secs = cDirtysock_tag_TagFieldGetTime(data, 1);
    if (secs < 2)
        return -1;
    t = func_003EAEB8(&tm, secs + offset);
    if (t == 0)
        return -1;
    if (date)
        *date = ((t->tm_year + 1900) << 16) | ((t->tm_mon + 1) << 8) | t->tm_mday;
    if (time)
        *time = (t->tm_hour << 16) | (t->tm_min << 8) | t->tm_sec;
    return 0;
}
#endif
