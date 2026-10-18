#include "common.h"

INCLUDE_ASM("seg/seg_2EEF50", func_003EDF50);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE028);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE1B0);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE1E8);

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

INCLUDE_ASM("seg/seg_2EEF50", func_003EE320);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE3E0);

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

INCLUDE_ASM("seg/seg_2EEF50", func_003EE900);

INCLUDE_ASM("seg/seg_2EEF50", func_003EE9A0);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEA48);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEAB8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEB30);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEBF8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EEC88);

INCLUDE_ASM("seg/seg_2EEF50", func_003EED08);

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

INCLUDE_ASM("seg/seg_2EEF50", func_003EEF40);

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

INCLUDE_ASM("seg/seg_2EEF50", func_003EF770);

//100%
INCLUDE_ASM("seg/seg_2EEF50", func_003EF808);
#ifdef SKIP_ASM
extern void func_003EF828(int, int, int, int);
void func_003EF808(int a, int b, int c) {
    func_003EF828(a, b, c, 0);
}
#endif

INCLUDE_ASM("seg/seg_2EEF50", func_003EF828);

INCLUDE_ASM("seg/seg_2EEF50", func_003EF940);

INCLUDE_ASM("seg/seg_2EEF50", func_003EF9B8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFA48);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFAF8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFBA0);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFC68);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFCD8);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFD30);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFE20);

INCLUDE_ASM("seg/seg_2EEF50", func_003EFED0);
