#include "common.h"

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCDC8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCE10);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF00);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCF98);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FCFD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD0D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD100);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD128);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD150);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1D8);
#ifdef SKIP_ASM
int func_003FD1D8(int *p) {
    return *p == 0x464C457F;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FD1F0);
#ifdef SKIP_ASM
int func_003FD1F0(int *p, int n) {
    int base = *p;
    return base + *(int *)(base + 0x20) + n * 40;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD210);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD2F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD558);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD660);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD6E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD758);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD810);

void func_003FD908(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_003FD910);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FDAA0);
#ifdef SKIP_ASM
extern char D_00451550[];
void *func_003FDAA0(void) {
    return D_00451550;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDAB0);

INCLUDE_ASM("seg/seg_2FDDC8", sceGsSyncPath);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDE30);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDEA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF28);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF50);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDF88);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FDFB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE090);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE268);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE2A0);
#ifdef SKIP_ASM
int func_003FE2A0(int v) {
    int *r = (int *)0x1000E060;
    int o = *r;
    *r = v;
    return o;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE2B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE320);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE398);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE410);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE458);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE4D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE558);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE590);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE5C8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_003FE660);
#ifdef SKIP_ASM
unsigned func_003FE660(unsigned *p, unsigned v) {
    unsigned o = *p;
    *p = v;
    return (o >> 8) & 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE678);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE690);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE6A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE708);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE758);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE788);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7C8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE7D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE818);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE828);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE838);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FE998);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEB78);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEBC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEBD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEC88);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECE8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FECF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED50);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED60);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FED88);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FEF18);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF060);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF088);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF0F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF130);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF150);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF160);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF1B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF330);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF390);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF4A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF5E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF688);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF708);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF8F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FF9A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFA08);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFA58);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFBC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFC70);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFCD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFD28);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFD60);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFE80);

INCLUDE_ASM("seg/seg_2FDDC8", func_003FFFA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004000D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400190);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400250);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400328);

INCLUDE_ASM("seg/seg_2FDDC8", func_004003E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400490);

INCLUDE_ASM("seg/seg_2FDDC8", func_004004F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400548);

INCLUDE_ASM("seg/seg_2FDDC8", func_004005A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400670);

INCLUDE_ASM("seg/seg_2FDDC8", func_004006D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400740);

INCLUDE_ASM("seg/seg_2FDDC8", func_004007A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400810);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400838);

INCLUDE_ASM("seg/seg_2FDDC8", func_004008A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400908);

INCLUDE_ASM("seg/seg_2FDDC8", func_004009A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400B48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400C00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400CB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400D58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400DD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400E30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00400EA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004011C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004011E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401350);

INCLUDE_ASM("seg/seg_2FDDC8", func_004013E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401488);

INCLUDE_ASM("seg/seg_2FDDC8", func_004014F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401668);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401718);

INCLUDE_ASM("seg/seg_2FDDC8", func_004019F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401BF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401DF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00401FD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402268);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402300);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402398);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402450);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402520);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402618);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402708);

INCLUDE_ASM("seg/seg_2FDDC8", func_004027B8);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_004029C8);
#ifdef SKIP_ASM
int func_004029C8(void) {
    return 1;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_004029D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402A10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402A58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402AA0);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402AF0);
#ifdef SKIP_ASM
void func_00402AF0(int *p) {
    int *q = (int *)p[16];
    q[0x428] = 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B00);
#ifdef SKIP_ASM
void func_00402B00(int *p, int a, int b, int c) {
    int *q = (int *)p[16];
    q[37] = a;
    q[38] = b;
    q[39] = c;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402B18);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B38);
#ifdef SKIP_ASM
int func_00402B38(int *p) {
    int *q = (int *)p[16];
    return q[0];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402B48);
#ifdef SKIP_ASM
int func_00402B48(int *p) {
    int *q = (int *)p[16];
    return q[1] == 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402B58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402BB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402C08);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402C30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402C80);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CA8);
#ifdef SKIP_ASM
int func_00402CA8(int *p, long v) {
    int *q = (int *)p[16];
    q[28] = 1;
    *(long *)&q[30] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CC0);
#ifdef SKIP_ASM
int func_00402CC0(int *p) {
    int *q = (int *)p[16];
    q[28] = 0;
    *(long *)&q[30] = 0;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CD8);
#ifdef SKIP_ASM
int func_00402CD8(int *p, int v) {
    int *q = (int *)p[16];
    q[54] = v;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CE8);
#ifdef SKIP_ASM
int func_00402CE8(int *p) {
    int *q = (int *)p[16];
    return q[51];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402CF8);
#ifdef SKIP_ASM
int func_00402CF8(int *p) {
    int *q = (int *)p[16];
    return q[52];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D08);
#ifdef SKIP_ASM
char *func_00402D08(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D18);
#ifdef SKIP_ASM
char *func_00402D18(int *p) {
    return (char *)p[16] + 0xB4;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D28);
#ifdef SKIP_ASM
int func_00402D28(int *p, int v) {
    int *q = (int *)p[16];
    int old = q[58];
    q[58] = v;
    return old;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D38);
#ifdef SKIP_ASM
int func_00402D38(int *p, long v) {
    int *q = (int *)p[16];
    *(long *)&q[60] = v;
    q[62] = 1;
    return 1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D50);
#ifdef SKIP_ASM
void func_00402D50(int *p, int a, int b) {
    p[0] = a;
    p[1] = b;
    p[2] = a;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D68);
#ifdef SKIP_ASM
int func_00402D68(int *p) {
    return p[3] = p[2];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402D78);
#ifdef SKIP_ASM
int func_00402D78(int *p) {
    return p[2] = p[3];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402D88);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00402DF8);
#ifdef SKIP_ASM
int func_00402DF8(int *p) {
    return p[0] + p[1] - p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00402E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00402F80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403098);

INCLUDE_ASM("seg/seg_2FDDC8", func_004030E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403240);

INCLUDE_ASM("seg/seg_2FDDC8", func_004032A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004032B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403338);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403398);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403460);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403470);

INCLUDE_ASM("seg/seg_2FDDC8", func_004034A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403500);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403600);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403620);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403748);

INCLUDE_ASM("seg/seg_2FDDC8", func_004039F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403AD0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403BB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403CE0);

INCLUDE_ASM("seg/seg_2FDDC8", _sequenceScalableExtension);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403D80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403D90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403DA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403DB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403DD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00403E00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404050);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404758);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404B78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404D98);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404EA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00404F60);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405030);

INCLUDE_ASM("seg/seg_2FDDC8", func_004050E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405198);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405290);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405390);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405430);

INCLUDE_ASM("seg/seg_2FDDC8", func_004054E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004055C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004056A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405780);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405850);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405970);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405A88);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405AE8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405B48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405B70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405E30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00405FB8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004060C8);

INCLUDE_ASM("seg/seg_2FDDC8", _sliceA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406318);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406510);

INCLUDE_ASM("seg/seg_2FDDC8", func_004065D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406B00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406CA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406DF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406E20);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406EC8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00406F78);

INCLUDE_ASM("seg/seg_2FDDC8", func_004070F0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004071F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004072E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407438);

INCLUDE_ASM("seg/seg_2FDDC8", func_004074B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407520);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407630);

INCLUDE_ASM("seg/seg_2FDDC8", func_004076F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407820);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407A10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407A58);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407AD0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407B70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407C38);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407D30);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407DC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407E90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00407F20);

INCLUDE_ASM("seg/seg_2FDDC8", func_004081D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408278);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408508);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408530);

INCLUDE_ASM("seg/seg_2FDDC8", func_004086C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004087D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408988);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408AF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408B80);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408CA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408DF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00408FB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409088);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409310);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409388);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409400);

INCLUDE_ASM("seg/seg_2FDDC8", func_004094E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409638);

INCLUDE_ASM("seg/seg_2FDDC8", func_004096A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409708);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409940);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409B10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409B60);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409B90);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409C48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409D10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409E38);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409E70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00409F28);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A000);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A090);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A1A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A320);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A328);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A360);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A440);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A498);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A618);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A688);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A7D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A858);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040A998);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AA68);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AB80);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AC38);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AE00);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040AF58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B028);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B130);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_0040B1F8);
#ifdef SKIP_ASM
extern int D_004533E0[];
void func_0040B1F8(void) {
    D_004533E0[0] = 0;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B208);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B2B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B2D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B3D8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B400);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B5B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B6D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B938);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B9A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040B9E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BA48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BA68);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BAA8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BAE8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BB38);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BBA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BC08);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BC70);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BCA0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BCC0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BD28);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BD90);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BE48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BEF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BF20);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BF48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BFD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040BFE0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C028);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C220);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbGetInfo);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbRead);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbGetLocation);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbSetLEDStatus);

INCLUDE_ASM("seg/seg_2FDDC8", sceUsbKbSetLEDMode);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C728);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C770);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C7C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C810);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C8B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C8C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C928);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040C980);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CEF8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF48);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF68);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040CF88);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D010);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D040);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D0B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D118);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D268);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D3C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D430);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D4A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D588);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D610);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D758);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040D8D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040DA10);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040DB58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E048);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E300);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E550);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040E878);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040EC58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F5A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F840);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F878);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8C0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F8E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F9D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040F9F8);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FB58);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FB88);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FBE0);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FC90);

INCLUDE_ASM("seg/seg_2FDDC8", func_0040FCB0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004103A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004103B0);

INCLUDE_ASM("seg/seg_2FDDC8", func_004103D8);

void func_00410408(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_00410410);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410468);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410490);

INCLUDE_ASM("seg/seg_2FDDC8", func_004104B8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004104E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410548);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410570);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410848);
#ifdef SKIP_ASM
int func_00410848(short *p) {
    return p[3];
}
#endif

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00410850);
#ifdef SKIP_ASM
int func_00410850(short *p) {
    return p[2];
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00410858);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410930);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410A78);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410B00);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410B80);

void func_00410C10(void) {
}

INCLUDE_ASM("seg/seg_2FDDC8", func_00410C18);

INCLUDE_ASM("seg/seg_2FDDC8", func_00410F48);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411128);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411310);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411340);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411438);

INCLUDE_ASM("seg/seg_2FDDC8", func_004114D0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411530);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411538);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411B08);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411C38);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411CD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411F18);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411F70);

INCLUDE_ASM("seg/seg_2FDDC8", func_00411FD8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412280);

INCLUDE_ASM("seg/seg_2FDDC8", func_004123E8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412500);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412550);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412608);

INCLUDE_ASM("seg/seg_2FDDC8", func_004126A0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412740);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412778);

INCLUDE_ASM("seg/seg_2FDDC8", func_004127A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412800);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412838);
#ifdef SKIP_ASM
extern int D_00453A38[];
int func_00412838(int v) {
    int o = D_00453A38[0];
    D_00453A38[0] = v;
    return o;
}
#endif

INCLUDE_ASM("seg/seg_2FDDC8", func_00412848);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412888);

INCLUDE_ASM("seg/seg_2FDDC8", func_004128A8);

INCLUDE_ASM("seg/seg_2FDDC8", func_004128E0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412908);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412928);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412998);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412A28);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412AF0);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412B20);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412E10);

INCLUDE_ASM("seg/seg_2FDDC8", func_00412E38);

//100%
INCLUDE_ASM("seg/seg_2FDDC8", func_00412E68);
#ifdef SKIP_ASM
extern char D_004998A0[];
void *func_00412E68(void **p) {
    *p = D_004998A0;
    return p;
}
#endif
