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

INCLUDE_ASM("dirtysock/tags", func_003EB578);

INCLUDE_ASM("dirtysock/tags", func_003EB588);

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldFind);

INCLUDE_ASM("dirtysock/tags", func_003EB840);

INCLUDE_ASM("dirtysock/tags", func_003EB8B8);

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldDelete);

INCLUDE_ASM("dirtysock/tags", func_003EB9E8);

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

INCLUDE_ASM("dirtysock/tags", func_003EBBA8);

INCLUDE_ASM("dirtysock/tags", func_003EBCB0);

INCLUDE_ASM("dirtysock/tags", func_003EBD70);

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

INCLUDE_ASM("dirtysock/tags", cDirtysock_tag_TagFieldSetStructure);

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

INCLUDE_ASM("dirtysock/tags", func_003EC8B8);

INCLUDE_ASM("dirtysock/tags", func_003EC9A0);

INCLUDE_ASM("dirtysock/tags", func_003ECA88);

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

INCLUDE_ASM("dirtysock/tags", func_003ECBD8);

INCLUDE_ASM("dirtysock/tags", func_003ECE38);

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
extern "C" int strlen(const char* s);
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
            return strlen(defval);
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

INCLUDE_ASM("dirtysock/tags", func_003EDE80);

