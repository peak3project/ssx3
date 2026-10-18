#include "common.h"

INCLUDE_ASM("seg/seg_2EEF50", func_003EDF50);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE028);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE1B0);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE1E8);
#ifdef SKIP_ASM
extern int* func_002591E8(int);
extern void func_00416210(void*, int, int);
extern int func_003EE028(int*);
int* func_003EE1E8(int a, int b, int c) {
    int* p = func_002591E8(0x44);
    func_00416210(p, 0, 0x44);
    p[0] = a;
    func_003EE028(p);
    p[0] = b;
    p[1] = c;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE260);
#ifdef SKIP_ASM
extern void func_00259210(void*);
void func_003EE260(int* p) {
    if (p[15]) {
        do {
            int* q = (int*)p[15];
            p[15] = *q;
            func_00259210(q);
        } while (p[15]);
    }
    func_00259210((void*)p[16]);
    func_00259210(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE2B8);
#ifdef SKIP_ASM
void func_003EE2B8(int* p) {
    int i;
    for (i = 0; i < p[6]; i++) {
        int* item = ((int**)p[16])[i];
        item[0] = p[14];
        p[14] = (int)item;
    }
    p[2] = 1;
    p[4] += p[6];
    p[6] = 0;
    p[5] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE320);
#ifdef SKIP_ASM
typedef int (*func_003EE320_cb)(int, int, int);
int* func_003EE320(int* p, int a) {
    int* n;
    if (!p[14] && func_003EE028(p) <= 0) {
        return 0;
    }
    n = (int*)p[14];
    p[14] = *n;
    *n = a;
    ((int*)p[16])[p[6]] = (int)n;
    p[6]++;
    p[4]--;
    if (!p[9] || ((func_003EE320_cb)p[9])(p[8], p[7], *n) > 0) {
        p[2]++;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE3E0);
#ifdef SKIP_ASM
typedef int (*func_003EE3E0_cb)(int, int, int);
void func_003EE3E0(int* p, int* a, int b) {
    if (!p[9] || ((func_003EE3E0_cb)p[9])(p[8], p[7], *a) > 0 || ((func_003EE3E0_cb)p[9])(p[8], p[7], b) > 0) {
        p[2]++;
    }
    *a = b;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EE468);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE480);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE550);
#ifdef SKIP_ASM
int func_003EE550(int* p) {
    return p[6];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE558);
#ifdef SKIP_ASM
int func_003EE558(int* p) {
    return p[5];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE560);
#ifdef SKIP_ASM
int func_003EE560(int* p, int i) {
    if (!p || i < 0 || i >= p[6]) {
        return 0;
    }
    return **(int**)(p[16] + i * 4);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE5A0);
#ifdef SKIP_ASM
void func_003EE5A0(int* p, int a, int b, int c) {
    if (p[6] > 0) {
        p[2] = 1;
    }
    p[11] = a;
    p[10] = b;
    p[12] = c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE5C0);
#ifdef SKIP_ASM
void func_003EE5C0(int* p, int a, int b, int c) {
    if (p[6] > 0) {
        p[2] = 1;
    }
    p[8] = a;
    p[7] = b;
    p[9] = c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE5E0);
#ifdef SKIP_ASM
int func_003EE5E0(int* p, int inc) {
    if (inc) {
        p[2]++;
    }
    return p[2] > 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE600);
#ifdef SKIP_ASM
int func_003EE600(int* p, int inc) {
    if (inc) {
        p[3]++;
    }
    return p[3] > 0;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EE620);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE768);
#ifdef SKIP_ASM
void func_003EE768(int* p, int v) {
    p[13] = v;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE770);
#ifdef SKIP_ASM
int func_003EE770(int* p) {
    return p[13];
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EE778);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE820);
#ifdef SKIP_ASM
extern void func_00259210(void*);
void func_003EE820(int* p) {
    if (p[6]) {
        do {
            int* q = (int*)p[6];
            p[6] = *q;
            func_00259210(q);
        } while (p[6]);
    }
    func_00259210((void*)p[5]);
    func_00259210(p);
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE878);
#ifdef SKIP_ASM
void func_003EE878(int* p, int v) {
    p[8] = v;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EE880);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EE900);
#ifdef SKIP_ASM
extern int* func_002591E8(int);
int func_003EE900(int* p, int n) {
    int g = n > 0;
    int cnt = 1;
    int size;
    int* mem;
    int* item;
    int* end;
    if (g) {
        cnt = n;
    }
    cnt++;
    size = cnt * 12;
    mem = func_002591E8(size);
    if (!mem) {
        return -1;
    }
    mem[0] = p[6];
    p[6] = (int)mem;
    item = mem + 3;
    end = (int*)((char*)mem + size);
    while (item != end) {
        item[0] = p[7];
        p[7] = (int)item;
        item += 3;
    }
    return cnt - 1;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EE9A0);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEA48);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEAB8);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEB30);
#ifdef SKIP_ASM
extern int func_003EEA48(int*, int);
extern int func_003EE900(int*, int);
int func_003EEB30(int* p, int a, int b) {
    int h = func_003EEA48(p, a);
    int* n;
    if (!p[7] && func_003EE900(p, (p[0] * 3 + 10) / 2) <= 0) {
        return -1;
    }
    n = (int*)p[7];
    p[7] = *n;
    n[2] = a;
    n[1] = b;
    n[0] = ((int*)p[5])[h];
    ((int*)p[5])[h] = (int)n;
    p[0]++;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEBF8);
#ifdef SKIP_ASM
extern int func_003EEA48(int*, int);
int func_003EEBF8(int* p, int key, int val) {
    int* n = ((int**)p[5])[func_003EEA48(p, key)];
    while (n) {
        if (!((int (*)(int, int))p[8])(n[2], key)) {
            int old = n[1];
            n[1] = val;
            return old;
        }
        n = (int*)n[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEC88);
#ifdef SKIP_ASM
extern int func_003EEA48(int*, int);
int func_003EEC88(int* p, int key) {
    int* n = ((int**)p[5])[func_003EEA48(p, key)];
    while (n) {
        if (!((int (*)(int, int))p[8])(n[2], key)) {
            return n[1];
        }
        n = (int*)n[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EED08);
#ifdef SKIP_ASM
extern int func_003EEA48(int*, int);
int func_003EED08(int* p, int key) {
    int* n;
    int* prev = &((int*)p[5])[func_003EEA48(p, key)];
    for (;;) {
        n = (int*)*prev;
        if (!n) {
            return 0;
        }
        if (!((int (*)(int, int))p[8])(n[2], key)) {
            break;
        }
        prev = (int*)*prev;
    }
    *prev = n[0];
    n[0] = p[7];
    p[7] = (int)n;
    p[0]--;
    return n[1];
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EEDA0);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEE80);
#ifdef SKIP_ASM
int func_003EEE80(int* p, int key, int val) {
    int k = key >= 0 ? key : -key;
    int* n = ((int**)p[5])[k % p[4]];
    while (n) {
        if (n[2] == key) {
            int old = n[1];
            n[1] = val;
            return old;
        }
        n = (int*)n[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEEE8);
#ifdef SKIP_ASM
int func_003EEEE8(int* p, int key) {
    int k = key >= 0 ? key : -key;
    int* n = ((int**)p[5])[k % p[4]];
    while (n) {
        if (n[2] == key) {
            return n[1];
        }
        n = (int*)n[0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEF40);
#ifdef SKIP_ASM
int func_003EEF40(int* p, int key) {
    int k = key >= 0 ? key : -key;
    int* prev = &((int*)p[5])[k % p[4]];
    int* n;
    for (;;) {
        n = (int*)*prev;
        if (!n) {
            return 0;
        }
        if (n[2] == key) {
            break;
        }
        prev = n;
    }
    *prev = n[0];
    n[0] = p[7];
    p[7] = (int)n;
    p[0]--;
    return n[1];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EEFB8);
#ifdef SKIP_ASM
void func_003EEFB8(int* p) {
    p[2] = 0;
    p[3] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EEFC8);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF088);
#ifdef SKIP_ASM
int func_003EF088(void) {
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EF090);

INCLUDE_ASM("seg/seg_2EEF50", func_003EF210);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF600);
#ifdef SKIP_ASM
int func_003EF600(unsigned char x) {
    int n;
    for (n = 1; n < 7 && (x & 0x80); n++) {
        x <<= 1;
    }
    return n;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EF640);

INCLUDE_ASM("seg/seg_2EEF50", func_003EF6F8);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF770);
#ifdef SKIP_ASM
int func_003EF770(unsigned char* dst, unsigned int* e, unsigned short c, signed char ch) {
    int found = 0;
    unsigned char* d0 = dst;
    for (; e[1]; e += 3) {
        if (c < e[0]) {
            continue;
        }
        if (e[1] < c) {
            continue;
        }
        {
            unsigned char b;
            c = c - *(unsigned short*)e;
            b = ((unsigned char*)e[2])[c];
            if (b != 0xFF) {
                *dst = b;
            } else if (ch) {
                *dst = ch;
            } else {
                *dst = b;
            }
            dst++;
            found = 1;
            break;
        }
    }
    if (!found && ch) {
        *dst++ = ch;
    }
    return dst - d0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF808);
#ifdef SKIP_ASM
extern void func_003EF828(int, int, int, int);
void func_003EF808(int a, int b, int c) {
    func_003EF828(a, b, c, 0);
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EF828);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF940);
#ifdef SKIP_ASM
extern int func_003EF600(unsigned char);
int func_003EF940(char* s) {
    int i = 0;
    int count = 0;
    if (s[0]) {
        do {
            if (s[i] & 0x80) {
                i += func_003EF600(s[i]);
            } else {
                i++;
            }
            count++;
        } while (s[i]);
    }
    return count;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF9B8);
#ifdef SKIP_ASM
extern int func_003EF6F8(char*, int);
int func_003EF9B8(char* dst, int size, unsigned short* src) {
    int i = 0;
    int lim = size - 2;
    if (*src && lim > 0) {
        do {
            i += func_003EF6F8(dst + i, *src++);
        } while (*src && i < lim);
    }
    dst[i] = 0;
    return i + 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EFA48);
#ifdef SKIP_ASM
extern int func_003EF640(unsigned short*, char*);
int func_003EFA48(unsigned short* dst, int size, char* src) {
    int di = 0;
    int si = 0;
    int lim = size - 1;
    if (*src && lim > 0) {
        do {
            int r = func_003EF640(dst + di, src + si);
            si += r;
            if (r <= 3) {
                di++;
            }
        } while (src[si] && di < lim);
    }
    dst[di] = 0;
    return di + 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EFAF8);
#ifdef SKIP_ASM
extern int func_003EF6F8(char*, int);
int func_003EFAF8(char* dst, int size, char* src, unsigned short* tbl) {
    int i = 0;
    int lim = size - 2;
    if (*src && lim > 0) {
        do {
            unsigned short* e = &tbl[(unsigned char)*src++];
            i += func_003EF6F8(dst + i, *e);
        } while (*src && i < lim);
    }
    dst[i] = 0;
    return i + 1;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EFBA0);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EFC68);
#ifdef SKIP_ASM
char* func_003EFC68(char* s, int* out) {
    int v = 0;
    int c;
    for (;; s++) {
        if ((unsigned char)(*(unsigned char*)s - '0') < 10 || (unsigned char)(*(unsigned char*)s - 'a') < 6 || (unsigned char)(*(unsigned char*)s - 'A') < 6) {
            c = *s;
            if (c >= ':') {
                c = (char)(c + 9);
            }
            v = (v << 4) | (c & 0xF);
            continue;
        }
        break;
    }
    *out = v;
    return s;
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EFCD8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFD30);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFE20);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EFED0);
#ifdef SKIP_ASM
extern int func_004186C8(char* dst, const char* fmt, char* ap);
void func_003EFED0(int* p, const char* fmt, ...) {
    char buf[0x1000];
    char* ap;
    ap = (char*)__builtin_next_arg()
         - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0);
    func_004186C8(buf, fmt, ap);
    if (p[322]) {
        ((void (*)(int, char*))p[322])(p[321], buf);
    }
}
#endif
