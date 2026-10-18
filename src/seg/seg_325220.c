#include "common.h"

//100%
INCLUDE_ASM("seg/seg_325220", func_00424220);
#ifdef SKIP_ASM
extern int D_00455168;
void func_00424220(void) {
    D_00455168 = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424230);

INCLUDE_ASM("seg/seg_325220", func_004242C0);

INCLUDE_ASM("seg/seg_325220", func_00424368);

INCLUDE_ASM("seg/seg_325220", func_004243E8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424460);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_00424460(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424488);
#ifdef SKIP_ASM
int func_00424488(void) {
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424490);
#ifdef SKIP_ASM
int func_00424490(void) {
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424498);
#ifdef SKIP_ASM
int func_00424498(void) {
    return -1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004244A0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424550);
#ifdef SKIP_ASM
int func_00424550(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424558);
#ifdef SKIP_ASM
long func_00424558(int a0, char *a1) {
    *(int *)(a1 + 4) = 0x2000;
    *(long *)(a1 + 0x48) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424570);
#ifdef SKIP_ASM
int func_00424570(void) {
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00424578);
#ifdef SKIP_ASM
extern void func_0042C6E8(int a0);
int func_00424578(int a0, int a1) {
    if (a0 == 1) {
        func_0042C6E8(a1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004245A0);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_004245A0(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_004245C8);
#ifdef SKIP_ASM
extern int *func_00415FB8(void);
int func_004245C8(void) {
    *func_00415FB8() = 5;
    return -1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004245F0);

INCLUDE_ASM("seg/seg_325220", func_00424698);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424718);
#ifdef SKIP_ASM
extern void func_004245F0(unsigned, unsigned);
void func_00424718(unsigned a, unsigned b) {
    func_004245F0(a & ~63, b & ~63);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424730);

INCLUDE_ASM("seg/seg_325220", func_004247D8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424858);
#ifdef SKIP_ASM
extern void func_00424730(unsigned, unsigned);
void func_00424858(unsigned a, unsigned b) {
    func_00424730(a & ~63, b & ~63);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424870);

INCLUDE_ASM("seg/seg_325220", func_00424880);

INCLUDE_ASM("seg/seg_325220", func_004248E8);

INCLUDE_ASM("seg/seg_325220", func_00424950);

INCLUDE_ASM("seg/seg_325220", func_004249B8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424A20);
#ifdef SKIP_ASM
extern void func_00423B40(void);
void func_00424A20(void) {
    func_00423B40();
    __asm__ volatile("sync");
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424A40);

INCLUDE_ASM("seg/seg_325220", func_00424A60);

INCLUDE_ASM("seg/seg_325220", func_00424A80);

INCLUDE_ASM("seg/seg_325220", func_00424AA0);

INCLUDE_ASM("seg/seg_325220", func_00424B78);

INCLUDE_ASM("seg/seg_325220", func_00424C50);

INCLUDE_ASM("seg/seg_325220", func_00424CE8);

INCLUDE_ASM("seg/seg_325220", func_00424D68);

//100%
INCLUDE_ASM("seg/seg_325220", func_00424E00);
#ifdef SKIP_ASM
extern int D_0052B7C0[];
int *func_00424E00(int a0) {
    D_0052B7C0[0] = a0;
    D_0052B7C0[1] = 0;
    D_0052B7C0[3] = (int)&D_0052B7C0[4];
    D_0052B7C0[2] = (int)&D_0052B7C0[4];
    return D_0052B7C0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00424E28);

INCLUDE_ASM("seg/seg_325220", func_00424E68);

INCLUDE_ASM("seg/seg_325220", func_00424EA8);

INCLUDE_ASM("seg/seg_325220", func_00425040);

INCLUDE_ASM("seg/seg_325220", func_00425190);

INCLUDE_ASM("seg/seg_325220", func_00425260);

INCLUDE_ASM("seg/seg_325220", func_00425320);

INCLUDE_ASM("seg/seg_325220", func_00425358);

INCLUDE_ASM("seg/seg_325220", func_00425408);

INCLUDE_ASM("seg/seg_325220", func_00425440);

INCLUDE_ASM("seg/seg_325220", func_004254D0);

INCLUDE_ASM("seg/seg_325220", func_00425638);

INCLUDE_ASM("seg/seg_325220", func_00425C28);

INCLUDE_ASM("seg/seg_325220", func_00425C60);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CC0);
#ifdef SKIP_ASM
void func_00425CC0(int *a0, int *a1) {
    ((int *)a1[7])[a0[4]] = a0[5];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CE0);
#ifdef SKIP_ASM
void func_00425CE0(int *a0, int *a1) {
    a1[2] = a0[4];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425CF0);
#ifdef SKIP_ASM
extern int D_0052BE00[];
int func_00425CF0(int a0) {
    return D_0052BE00[a0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425D08);
#ifdef SKIP_ASM
extern int D_0052BE00[];
int func_00425D08(int a0, int a1) {
    D_0052BE00[a0] = a1;
    return a1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425D28);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int *func_00425D28(void) {
    return D_0052BCD8;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00425D38);

//100%
INCLUDE_ASM("seg/seg_325220", func_00425FB8);
#ifdef SKIP_ASM
extern int func_00424950(int a0);
extern int func_00423AD0(int a0, int a1);
extern int D_0045517C;
extern int D_0052BCD4;
void func_00425FB8(void) {
    func_00424950(5);
    func_00423AD0(5, D_0052BCD4);
    D_0045517C = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00425FF0);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int func_00425FF0(int a0, int a1) {
    int old = D_0052BCD8[5];
    D_0052BCD8[5] = a0;
    D_0052BCD8[6] = a1;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426008);
#ifdef SKIP_ASM
extern int D_0052BCD8[];
int func_00426008(int a0, int a1) {
    int old = D_0052BCD8[3];
    D_0052BCD8[3] = a0;
    D_0052BCD8[4] = a1;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426020);
#ifdef SKIP_ASM
extern int *D_0052BCE4;
extern int *D_0052BCEC;
void func_00426020(int a0, int a1, int a2) {
    int off = a0 << 3;
    if (a0 < 0) {
        a0 = (int)D_0052BCE4;
    } else {
        a0 = (int)D_0052BCEC;
    }
    off += a0;
    ((int *)off)[0] = a1;
    ((int *)off)[1] = a2;
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_00426050);
#ifdef SKIP_ASM
extern int *D_0052BCE4;
extern int *D_0052BCEC;
void func_00426050(int a0) {
    int off = a0 << 3;
    if (a0 < 0) {
        a0 = (int)D_0052BCE4;
    } else {
        a0 = (int)D_0052BCEC;
    }
    off += a0;
    *(int *)off = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426078);

INCLUDE_ASM("seg/seg_325220", func_004261B0);

INCLUDE_ASM("seg/seg_325220", func_004261F0);

INCLUDE_ASM("seg/seg_325220", func_00426230);

INCLUDE_ASM("seg/seg_325220", func_00426358);

INCLUDE_ASM("seg/seg_325220", func_00426404);

INCLUDE_ASM("seg/seg_325220", func_00426408);

//100%
INCLUDE_ASM("seg/seg_325220", func_004265A8);
#ifdef SKIP_ASM
extern void func_00425FB8(void);
extern int D_00455180;
void func_004265A8(void) {
    func_00425FB8();
    D_00455180 = 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004265D0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426678);
#ifdef SKIP_ASM
void func_00426678(unsigned int *a0) {
    a0[6] = 0;
    a0[4] &= 0xFFFFFFFE;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426698);

//100%
INCLUDE_ASM("seg/seg_325220", func_004266C8);
#ifdef SKIP_ASM
extern int func_00426698(int *a0);
int func_004266C8(int *a0, int a1) {
    if (a1 < 0 || a1 >= a0[8]) {
        return func_00426698(a0);
    }
    return a0[7] + (a1 << 6);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426708);

INCLUDE_ASM("seg/seg_325220", func_004267C0);

INCLUDE_ASM("seg/seg_325220", func_00426820);

INCLUDE_ASM("seg/seg_325220", func_004268F0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426A48);
#ifdef SKIP_ASM
struct N426A48 { int key; char pad[0x34]; struct N426A48 *next; };
struct O426A48 { char pad[8]; struct N426A48 *head; char pad2[8]; struct O426A48 *next; };
struct P426A48 { char pad[0x28]; struct O426A48 *list; };
struct N426A48 *func_00426A48(int a0, struct P426A48 *a1) {
    struct O426A48 *o;
    struct N426A48 *n;
    for (o = a1->list; o != 0; o = o->next) {
        for (n = o->head; n != 0; n = n->next) {
            if (n->key == a0) {
                return n;
            }
        }
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426A98);

INCLUDE_ASM("seg/seg_325220", func_00426B48);

INCLUDE_ASM("seg/seg_325220", func_00426C88);

INCLUDE_ASM("seg/seg_325220", func_00426D18);

//100%
INCLUDE_ASM("seg/seg_325220", func_00426F08);
#ifdef SKIP_ASM
int func_00426F08(int *a0) {
    int *p = (int *)a0[0];
    if (p == 0 || a0[1] != p[6] || !(p[4] & 1)) {
        return 0;
    }
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00426F48);

INCLUDE_ASM("seg/seg_325220", func_00426FE0);

INCLUDE_ASM("seg/seg_325220", func_004270B0);

INCLUDE_ASM("seg/seg_325220", func_00427148);

INCLUDE_ASM("seg/seg_325220", func_004271D8);

INCLUDE_ASM("seg/seg_325220", func_00427230);

INCLUDE_ASM("seg/seg_325220", func_004273F8);

INCLUDE_ASM("seg/seg_325220", func_00427438);

INCLUDE_ASM("seg/seg_325220", func_00427498);

INCLUDE_ASM("seg/seg_325220", func_00427520);

INCLUDE_ASM("seg/seg_325220", func_00427590);

INCLUDE_ASM("seg/seg_325220", func_00427938);

//100%
INCLUDE_ASM("seg/seg_325220", func_00427988);
#ifdef SKIP_ASM
extern void func_00427938(void);
extern void func_00423DE0(int a0);
extern int D_00455214;
int func_00427988(void) {
    func_00427938();
    func_00423DE0(D_00455214);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004279B8);

INCLUDE_ASM("seg/seg_325220", func_004279C8);

INCLUDE_ASM("seg/seg_325220", func_00427A60);

INCLUDE_ASM("seg/seg_325220", func_00427A90);

INCLUDE_ASM("seg/seg_325220", func_00427C98);

//100%
INCLUDE_ASM("seg/seg_325220", func_00427D28);
#ifdef SKIP_ASM
extern void func_00416210(void *a0, int a1, int a2);
extern int D_0045520C;
extern char D_0052EE28[];
int func_00427D28(void) {
    D_0045520C = 0;
    func_00416210(D_0052EE28, 0, 4);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00427D60);

INCLUDE_ASM("seg/seg_325220", func_00427FE8);

INCLUDE_ASM("seg/seg_325220", func_00428168);

INCLUDE_ASM("seg/seg_325220", func_004283A0);

INCLUDE_ASM("seg/seg_325220", func_00428600);

INCLUDE_ASM("seg/seg_325220", func_004288C0);

INCLUDE_ASM("seg/seg_325220", func_00428C38);

INCLUDE_ASM("seg/seg_325220", func_00428E18);

//100%
INCLUDE_ASM("seg/seg_325220", func_00428FC0);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00428FC0(int a0) {
    return func_00428E18(a0, 6);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00428FE0);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429190);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429190(int a0) {
    return func_00428E18(a0, 8);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_004291B0);

INCLUDE_ASM("seg/seg_325220", func_00429420);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429540);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429540(int a0) {
    return func_00428E18(a0, 0x10);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00429560);

INCLUDE_ASM("seg/seg_325220", func_00429628);

INCLUDE_ASM("seg/seg_325220", func_00429790);

INCLUDE_ASM("seg/seg_325220", func_004298E8);

INCLUDE_ASM("seg/seg_325220", func_00429A88);

INCLUDE_ASM("seg/seg_325220", func_00429CC8);

//100%
INCLUDE_ASM("seg/seg_325220", func_00429EB8);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_00429EB8(int a0) {
    return func_00428E18(a0, 0x12);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_00429ED8);

INCLUDE_ASM("seg/seg_325220", func_0042A070);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042A2E0);
#ifdef SKIP_ASM
extern int func_00428E18(int a0, int a1);
int func_0042A2E0(int a0) {
    return func_00428E18(a0, 0x15);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042A300);

INCLUDE_ASM("seg/seg_325220", func_0042A538);

INCLUDE_ASM("seg/seg_325220", func_0042A770);

INCLUDE_ASM("seg/seg_325220", func_0042A950);

INCLUDE_ASM("seg/seg_325220", func_0042AB18);

INCLUDE_ASM("seg/seg_325220", func_0042ABA0);

INCLUDE_ASM("seg/seg_325220", func_0042AC10);

INCLUDE_ASM("seg/seg_325220", func_0042AC90);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042AD08);
#ifdef SKIP_ASM
extern int func_0042AC90(void);
int func_0042AD08(void) {
    return func_0042AC90();
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042AD28);

INCLUDE_ASM("seg/seg_325220", func_0042AE18);

INCLUDE_ASM("seg/seg_325220", func_0042AE88);

INCLUDE_ASM("seg/seg_325220", func_0042AEF8);

INCLUDE_ASM("seg/seg_325220", func_0042AF68);

INCLUDE_ASM("seg/seg_325220", func_0042AFE8);

INCLUDE_ASM("seg/seg_325220", func_0042B068);

INCLUDE_ASM("seg/seg_325220", func_0042B168);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B1F8);
#ifdef SKIP_ASM
extern void func_00416210(void *a0, int a1, int a2);
extern int D_00455228;
extern char D_0052F2A8[];
int func_0042B1F8(void) {
    D_00455228 = -1;
    func_00416210(D_0052F2A8, 0, 4);
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042B230);

INCLUDE_ASM("seg/seg_325220", func_0042B438);

INCLUDE_ASM("seg/seg_325220", func_0042B640);

INCLUDE_ASM("seg/seg_325220", func_0042B6D0);

INCLUDE_ASM("seg/seg_325220", func_0042B770);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B800);
#ifdef SKIP_ASM
extern int func_0042B230(int a0, int a1, int a2, int *a3);
int func_0042B800(int a0, int a1, int a2) {
    int sp;
    return func_0042B230(a0, a1, a2, &sp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042B820);
#ifdef SKIP_ASM
extern int func_0042B230(int a0, int a1, int a2, int *a3);
int func_0042B820(int a0, int a1, int a2, int *a3) {
    return func_0042B230(a0, a1, a2, a3);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042B840);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BA68);
#ifdef SKIP_ASM
extern int func_0042B840(int a0, int a1, int a2, int *a3, int a4);
int func_0042BA68(int a0, int a1, int a2) {
    int sp;
    return func_0042B840(a0, a1, a2, &sp, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BA88);
#ifdef SKIP_ASM
extern int func_0042B840(int a0, int a1, int a2, int *a3, int a4);
int func_0042BA88(int a0, int a1, int a2, int *a3) {
    return func_0042B840(a0, a1, a2, a3, 0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BAA8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BBB0);
#ifdef SKIP_ASM
extern int func_0042BAA8(int a0, char *a1, int a2, int a3);
int func_0042BBB0(int a0, char *a1, int a2) {
    return func_0042BAA8(a0, a1, a2, 1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BBD0);
#ifdef SKIP_ASM
extern char D_0049AD58[];
extern int func_0042BAA8(int a0, char *a1, int a2, int a3);
int func_0042BBD0(int a0, int a1) {
    return func_0042BAA8(a0, D_0049AD58, a1, 1);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BBF8);

INCLUDE_ASM("seg/seg_325220", func_0042BCE8);

INCLUDE_ASM("seg/seg_325220", func_0042BDC8);

INCLUDE_ASM("seg/seg_325220", func_0042BF08);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042BF30);
#ifdef SKIP_ASM
extern int func_004241B0(int a0);
extern void func_00424220(void);
int func_0042BF30(void) {
    if (func_004241B0(4) & 0x40000) {
        func_00424220();
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042BF68);

INCLUDE_ASM("seg/seg_325220", func_0042C078);

INCLUDE_ASM("seg/seg_325220", func_0042C0C0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C0D8);
#ifdef SKIP_ASM
extern int D_00455248;
extern int D_0045524C;
extern int func_00423DA0(int *a0);
void func_0042C0D8(void) {
    int a[8];
    int b[8];
    a[1] = 1;
    a[2] = 1;
    b[1] = 1;
    b[2] = 1;
    D_00455248 = func_00423DA0(a);
    D_0045524C = func_00423DA0(b);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C120);

INCLUDE_ASM("seg/seg_325220", func_0042C130);

INCLUDE_ASM("seg/seg_325220", func_0042C168);

INCLUDE_ASM("seg/seg_325220", func_0042C1A8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C1B8);
#ifdef SKIP_ASM
extern void func_0042C120(void *a0, int a1, int a2);
extern int D_00455230;
int func_0042C1B8(int a0) {
    int v;
    func_0042C120(&v, D_00455230 + a0 * 4, 4);
    return v;
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042C1F0);

INCLUDE_ASM("seg/seg_325220", func_0042C2F0);

INCLUDE_ASM("seg/seg_325220", func_0042C300);

INCLUDE_ASM("seg/seg_325220", func_0042C340);

INCLUDE_ASM("seg/seg_325220", func_0042C350);

INCLUDE_ASM("seg/seg_325220", func_0042C360);

INCLUDE_ASM("seg/seg_325220", func_0042C398);

INCLUDE_ASM("seg/seg_325220", func_0042C3A8);

INCLUDE_ASM("seg/seg_325220", func_0042C410);

INCLUDE_ASM("seg/seg_325220", func_0042C4C0);

INCLUDE_ASM("seg/seg_325220", func_0042C4D0);

INCLUDE_ASM("seg/seg_325220", func_0042C500);

INCLUDE_ASM("seg/seg_325220", func_0042C510);

INCLUDE_ASM("seg/seg_325220", func_0042C628);

INCLUDE_ASM("seg/seg_325220", func_0042C630);

INCLUDE_ASM("seg/seg_325220", func_0042C6A0);

INCLUDE_ASM("seg/seg_325220", func_0042C6E8);

INCLUDE_ASM("seg/seg_325220", func_0042C710);

INCLUDE_ASM("seg/seg_325220", func_0042C760);

INCLUDE_ASM("seg/seg_325220", func_0042C770);

INCLUDE_ASM("seg/seg_325220", func_0042C780);

INCLUDE_ASM("seg/seg_325220", func_0042C7B8);

INCLUDE_ASM("seg/seg_325220", func_0042C7C8);

INCLUDE_ASM("seg/seg_325220", func_0042C8A0);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C8E8);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042C8E8(int a0) {
    return func_004241D0(2, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C910);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C910(int a0, char a1) {
    int buf[2];
    buf[0] = a0;
    buf[1] = a1;
    func_004241D0(3, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C940);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042C940(int a0) {
    return func_004241D0(4, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C968);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C968(int a0, int a1, unsigned short a2) {
    int buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    func_004241D0(-5, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C9A0);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C9A0(int a0, int a1, unsigned short a2) {
    int buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    func_004241D0(-6, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042C9D8);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
void func_0042C9D8(int a0, char a1) {
    int buf[2];
    buf[0] = a0;
    buf[1] = a1;
    func_004241D0(-7, buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA08);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA08(int a0) {
    return func_004241D0(-8, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA30);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA30(int a0) {
    return func_004241D0(-9, &a0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CA58);
#ifdef SKIP_ASM
extern int func_004241D0(int a0, int *a1);
int func_0042CA58(int a0) {
    return func_004241D0(0x10, &a0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CA80);

INCLUDE_ASM("seg/seg_325220", func_0042CAE0);

INCLUDE_ASM("seg/seg_325220", func_0042CB68);

INCLUDE_ASM("seg/seg_325220", func_0042CB78);

INCLUDE_ASM("seg/seg_325220", func_0042CBB0);

INCLUDE_ASM("seg/seg_325220", func_0042CBC0);

INCLUDE_ASM("seg/seg_325220", func_0042CBD0);

INCLUDE_ASM("seg/seg_325220", func_0042CC98);

INCLUDE_ASM("seg/seg_325220", func_0042CCA8);

INCLUDE_ASM("seg/seg_325220", func_0042CCB8);

//100%
INCLUDE_ASM("seg/seg_325220", func_0042CCC8);
#ifdef SKIP_ASM
extern int func_0042CCB8(int a0);
int func_0042CCC8(int a0) {
    if ((unsigned int)(a0 - 13) >= 0x23)
        return -1;
    return func_0042CCB8(a0);
}
#endif

INCLUDE_ASM("seg/seg_325220", func_0042CCF8);

INCLUDE_ASM("seg/seg_325220", func_0042CD08);

INCLUDE_ASM("seg/seg_325220", func_0042CD18);

INCLUDE_ASM("seg/seg_325220", func_0042CD28);

INCLUDE_ASM("seg/seg_325220", func_0042CD38);

INCLUDE_ASM("seg/seg_325220", func_0042CD48);

INCLUDE_ASM("seg/seg_325220", func_0042CD58);

INCLUDE_ASM("seg/seg_325220", func_0042CD98);

INCLUDE_ASM("seg/seg_325220", func_0042CFC0);

INCLUDE_ASM("seg/seg_325220", func_0042D320);

INCLUDE_ASM("seg/seg_325220", func_0042D380);

INCLUDE_ASM("seg/seg_325220", func_0042D470);

INCLUDE_ASM("seg/seg_325220", func_0042DAD8);
