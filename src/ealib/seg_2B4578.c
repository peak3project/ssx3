#include "common.h"

// PORT: PS2-only COP0 (disable / enable interrupts, pipeline sync, read the Status register).
#define DI_2B45() __asm__ volatile("di")
#define EI_2B45() __asm__ volatile("ei")
#define SYNCP_2B45() __asm__ volatile("sync.p")
#define MFC0_STATUS_2B45(v) __asm__ volatile("mfc0 %0, $12" : "=r"(v))

/* D_0050A8E8: the sound driver's state block (layout worked out from every use in this unit; field names are
   their offsets). Some fields are also reached through their own splat symbols (declared below), which the
   functions that address them directly must keep using. */
struct sA8E8Cfg {                   /* 0xA0: the current setup (+0x20, D_0050A908) and a saved copy (+0xD4) */
    char pad00[0x4];
    int f04;
    unsigned short f08;             /* number of slots (f1F4) */
    unsigned short f0A;
    unsigned short f0C;
    unsigned char f0E;
    unsigned char f0F;
    unsigned char f10;
    char pad11[0x14 - 0x11];
    float f14;
    char pad18[0x1C - 0x18];
    unsigned char f1C;
    char pad1D;
    unsigned char f1E;
    unsigned char f1F;
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    char pad23[0x26 - 0x23];
    unsigned char f26;
    unsigned char f27;
    unsigned char f28;
    unsigned char f29;
    unsigned char f2A;
    char f2B;
    unsigned char f2C;
    char pad2D;
    short f2E[3];
    char pad34[0x44 - 0x34];
    unsigned int f44;
    int f48;
    char *f4C;                      /* also D_0050A954 */
    char pad50[0x58 - 0x50];
    unsigned short f58[5][6];       /* row n: n + 1 angles */
    char pad94[0xA0 - 0x94];
};
struct sA8E8Tail {                  /* +0xC0 (D_0050A9A8) */
    int f00;
    int f04;
    void (*f08)(void);              /* D_0050A9B0 */
    int f0C;
    int f10;
};
struct sA8E8Setup {                 /* 0xD4: what func_003B4DD8 hands out */
    unsigned short f00;
    unsigned short f02;
    unsigned char f04;
    unsigned char f05;
    unsigned char f06;
    unsigned char f07;
    unsigned char f08;
    char pad09[0xC - 0x9];
    unsigned char f0C;
    char pad0D[0x13 - 0xD];
    unsigned char f13;
    short f14[3];
    short f1A[3];
    struct sA8E8Cfg cfg;
    struct sA8E8Tail tail;
};
struct sA8E8Node {                  /* +0x1B4 list */
    struct sA8E8Node *next;
    int f04;
    void (*fn)(int);
    int arg;
};
struct sA8E8HeapEnt { int key; int val; };
struct sA8E8Heap {                  /* +0x234 (also D_0050AB1C): block heap, entry table grows down from f04 */
    int f00;
    struct sA8E8HeapEnt *f04;
    int f08;
    unsigned int f0C;
    int f10;
    int f14;
};
struct sA8E8Bank {                  /* a loaded bank's header */
    int f00;
    short f04;
    unsigned short f06;             /* number of f14 entries */
    int f08;                        /* header size */
    int f0C;                        /* size of the kind-8 data */
    int f10;                        /* size of the kind-0x100 data */
    int f14[1];                     /* self-relative offsets */
};
struct sA8E8Slot {                  /* 0x10, D_0050A8E8.f1F4[f08] (also D_0050AADC) */
    struct sA8E8Bank *f00;
    char *f04;
    char *f08;
    signed char f0C;                /* busy */
};
struct sA8E8Chan {                  /* 0x8C, D_0050A8E8.f1F0[f17E] (also D_0050AAD8) */
    int f00;
    short f04[7];
    short f12;                      /* slot */
    int f14;
    int f18;
    unsigned short f1C;
    unsigned short f1E;
    unsigned short f20;
    char pad22;
    unsigned char f23;              /* number of f04 entries */
    unsigned short f24;
    unsigned char f26;
    unsigned char f27;
    short f28;
    unsigned char f2A;
    char pad2B;
    unsigned int f2C;
    int f30;
    int f34;
    int f38;                        /* 16.16 */
    int f3C;
    int f40;
    int f44;
    float f48;
    unsigned short f4C;
    char pad4E[0x5C - 0x4E];
    signed char f5C;                /* number of f6C steps */
    signed char f5D;
    signed char f5E;
    signed char f5F;
    signed char f60[1];             /* indexed */
    signed char f61[1];             /* indexed */
    short f62[1];                   /* indexed */
    signed char f64;
    unsigned char f65;
    unsigned char f66;
    unsigned char f67;
    unsigned char f68;
    signed char f69;
    unsigned short f6A;
    struct sA8E8Env *f6C;
    char pad70[0x74 - 0x70];
    signed char *f74;
    signed char *f78;
    signed char *f7C;
    short f80;
    short f82;
    short f84;
    unsigned short f86;
    unsigned short f88;
    unsigned short f8A;
};
struct sA8E8Env { int f00; int f04; };
struct sA8E8Pan { float l; float r; };
struct sA8E8Bus {                   /* 0x14, at +0x1F8 / +0x20C / +0x220, indexed by id */
    short f00;
    char f02;
    char pad03;
    int f04;
    int f08;
    struct sA8E8Pan f0C;
};
struct sA8E8 {
    struct sA8E8Setup setup;
    struct sA8E8Cfg saved;
    signed char f174;               /* also D_0050AA5C */
    char f175;
    volatile unsigned char f176;    /* lock depth */
    signed char f177;
    signed char f178;
    signed char f179;
    unsigned char f17A;             /* also D_0050AA62 */
    char pad17B[0x17E - 0x17B];
    short f17E;                     /* number of channels (f1F0) */
    volatile unsigned int f180;     /* tick */
    void (*f184[6])(void);          /* f177 entries */
    void (*f19C[6])(void);          /* f178 entries */
    struct sA8E8Node *f1B4;
    char pad1B8[0x1C0 - 0x1B8];
    int f1C0;
    char pad1C4[0x1C8 - 0x1C4];
    void (*f1C8[4])(void *);        /* f179 entries */
    void (*f1D8)(void);
    void (*f1DC)(void);
    void (*f1E0)(void);
    void (*f1E4)(int);
    void (*f1E8)(void);
    void (*f1EC)(void);
    struct sA8E8Chan *f1F0;
    struct sA8E8Slot *f1F4;
    struct sA8E8Bus f1F8[1];        /* kind 4 */
    struct sA8E8Bus f20C[1];        /* kind 0x100 */
    struct sA8E8Bus f220[1];        /* kind 8 */
    struct sA8E8Heap *f234;
    char pad238[0x2E0 - 0x238];
    unsigned short f2E0[6][6];      /* also D_0050ABC8: row n - 1 = n channel angles */
    void (*f328)(void);             /* sound thread hooks: before / after a tick */
    void (*f32C)(void);
    volatile unsigned int f330;
    volatile unsigned short f334;
};
extern struct sA8E8 D_0050A8E8;
extern struct sA8E8Cfg D_0050A908;      /* D_0050A8E8.setup.cfg */
extern struct sA8E8Tail D_0050A9A8;     /* D_0050A8E8.setup.tail */
extern void (*D_0050A9B0)(void);        /* D_0050A8E8.setup.tail.f08 */
extern unsigned short D_0050A912;       /* D_0050A8E8.setup.cfg.f0A */
extern unsigned char D_0050A918;        /* D_0050A8E8.setup.cfg.f10 */
extern unsigned char D_0050A92E;        /* D_0050A8E8.setup.cfg.f26 */
extern unsigned int D_0050A94C[];       /* &D_0050A8E8.setup.cfg.f44 (an array, so reads are in-struct memory like the member's) */
extern signed char D_0050AA5C;          /* D_0050A8E8.f174 */
extern unsigned char D_0050AA62;        /* D_0050A8E8.f17A */
extern struct sA8E8Chan *D_0050AAD8;    /* D_0050A8E8.f1F0 */

/* PATHI players: D_00517610[4] (0x928 each), D_0044F420 points at the one selected by func_003D5450. Layout
   from every use in this unit; field names are their offsets. */
struct sPathVoice {                 /* 0x110, sPath.f58[] */
    char pad00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    signed char f04;
    char pad05[0x8 - 0x5];
    int f08;
    signed char f0C;
    signed char f0D;
    signed char f0E;
    char pad0F;
    int f10;
    signed char f14;
    signed char f15;
    signed char f16;
    char pad17;
    int f18;
    signed char f1C;
    signed char f1D;
    signed char f1E;
    char pad1F;
    int lo : 4;
    int ch : 5;
    unsigned int hi : 23;
    int f24;
    char pad28[0x2C - 0x28];
    short f2C;
    char pad2E;
    unsigned char f2F;
    unsigned int *f30;
    signed char f34;
    char pad35;
    short f36;
    char pad38[0x48 - 0x38];
    unsigned int f48;
    unsigned int f4C;
    char pad50[0x54 - 0x50];
    int f54;
    char pad58[0x110 - 0x58];
};
struct sPathEvent {                 /* sPath.f0DC[] */
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    union {
        unsigned int w;
        struct {
            unsigned int pad : 16;
            unsigned int end : 6;   /* number of 16-byte items after the header */
            unsigned int start : 6;
            unsigned int rest : 4;
        } b;
    } f0C;
};
struct sPathRamp { int dur; unsigned int mode; };
struct sPath {                      /* 0x928 */
    int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0C;
    unsigned int f10;
    struct sPathRamp f14[3];
    char pad2C[0x30 - 0x2C];
    unsigned int f30;
    unsigned int *f34;              /* the loaded path data (32-bit words) */
    short *f38;                     /* word offsets of its nodes */
    char pad3C[0x40 - 0x3C];
    short *f40;
    char pad44[0x48 - 0x44];
    int *f48;
    int *f4C;
    char *f50;
    unsigned int *f54;
    struct sPathVoice *f58[24];
    char padB8[0xDC - 0xB8];
    struct sPathEvent *f0DC[16];
    char buf[0x91C - 0x11C];
    int f91C;
    char pad920[0x924 - 0x920];
    int *f924;
};
extern struct sPath *D_0044F420;
extern struct sPath D_00517610[4];
extern char D_00517644[];               /* &D_00517610[0].f34: walked with stride 0x928 (f30 at -4) */
extern void (*D_0044F424)(int, int);    /* event callback (func_003D3018) */
extern void (*D_0044F428)(unsigned int, int);
extern unsigned char D_0044F42C;
extern unsigned char D_0044F42D;
extern unsigned char D_0044F42E;
extern unsigned int D_0044F430;
extern unsigned char D_0044F434;
extern unsigned int D_0044F438;         /* tick */
extern int D_0044F43C;                  /* flags */
extern struct sA8E8Bus D_0050AAE0[];    /* D_0050A8E8.f1F8 */
extern struct sA8E8Bus D_0050AAF4[];    /* D_0050A8E8.f20C */
extern struct sA8E8Bus D_0050AB08[];    /* D_0050A8E8.f220 */
extern void (*D_0050AAD0)(void);        /* D_0050A8E8.f1E8 */
extern void (*D_0050AAD4)(void);        /* D_0050A8E8.f1EC */
extern struct sA8E8Slot *D_0050AADC;    /* D_0050A8E8.f1F4 */
extern struct sA8E8Heap *D_0050AB1C;    /* D_0050A8E8.f234 */

/* D_0050A0A0: the streams (one per stream slot, func_003B6A38 looks one up). Layout from every use in this unit;
   field names are their offsets. */
struct sA0A0Node {                  /* 0x28: a queued stream request */
    struct sA0A0Node *f00;          /* next */
    int f04;
    int f08;
    volatile int f0C;               /* handle */
    unsigned int f10;
    volatile unsigned int f14;
    volatile unsigned int f18;
    volatile unsigned int f1C;
    volatile int f20;
    unsigned char f24;
    char pad25[0x28 - 0x25];
};
struct sA0A0List {                  /* 0xC */
    struct sA0A0Node *f00;          /* first */
    struct sA0A0Node *f04;
    int f08;                        /* count */
};
struct sA0A0Fmt {                   /* 4 bytes, copied as a whole: rate (u16), channels, codec (func_003B6948) */
    unsigned char b[4];
};
struct sA0A0Hdr {                   /* 0x68 */
    char pad00[0x18];
    int f18[6];                     /* one per channel */
    char pad30[0x68 - 0x30];
};
struct sA0A0Parm {                  /* 0x18, handed to func_003C6760 */
    signed char f00;
    signed char f01;
    char pad02[0x4 - 0x2];
    char f04;
    char f05;
    char pad06[0x8 - 0x6];
    short f08;
    short f0A;
    short f0C;
    short f0E;
    char pad10[0x14 - 0x10];
    short f14;
    char pad16[0x18 - 0x16];
};
struct sA0A0Trk {                   /* 0x18 */
    char pad00[0x10];
    int f10;
    char pad14[0x18 - 0x14];
};
struct sA0A0Strm {                  /* 0x138 */
    int f00;                        /* handle */
    volatile int f04;               /* voice */
    volatile int f08;               /* queue (D_005157B8.f304) */
    volatile int f0C;
    volatile signed char f10;       /* state */
    volatile unsigned char f11;
    char pad12[0x14 - 0x12];
    struct sA0A0Fmt f14;            /* current */
    struct sA0A0Fmt f18;            /* next */
    struct sA0A0Hdr f1C;            /* current */
    struct sA0A0Hdr f84;            /* next */
    struct sA0A0Parm fEC;
    struct sA0A0Trk f104[1];
    struct sA0A0List f11C;          /* queued requests */
    struct sA0A0List f128;          /* free requests */
    struct sA0A0Node *f134;
};
extern struct sA0A0Strm *D_0050A0A0[32];

/* D_0050A120: the MIDI sequence player (16 songs, then 24 voices, also D_0050A820). Layout from every use in this
   unit; field names are their offsets. */
struct sA120Chan {                  /* 4 bytes, one per MIDI channel (sA120Song.f30[]) */
    unsigned int b00 : 10;
    unsigned int b10 : 7;           /* volume */
    unsigned int b17 : 7;
    int b24 : 8;                    /* program */
};
struct sA120Song {                  /* 0x70, D_0050A120.f000[] */
    int f00;
    unsigned int f04;
    unsigned char *f08;             /* read position */
    unsigned char *f0C;             /* loop start */
    int f10;                        /* handle (sequence number | index) */
    int f14;                        /* volume, 16.16 */
    int f18;                        /* volume step */
    int f1C;                        /* volume target */
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;             /* tempo, percent */
    unsigned char f26;
    unsigned char f27;              /* ticks to the next event */
    signed char f28;                /* state */
    char pad29[0x2C - 0x29];
    short f2C;
    short f2E;
    struct sA120Chan f30[16];
};
struct sA120Voice {                 /* 8 bytes, D_0050A120.f700[] (also D_0050A820) */
    int f00;                        /* voice id */
    signed char f04;                /* owning song */
    signed char f05;                /* channel */
    signed char f06;
    signed char f07;
};
struct sA120 {
    struct sA120Song f000[16];
    struct sA120Voice f700[24];
    int f7C0;                       /* sequence counter */
};
extern struct sA120 D_0050A120;
extern struct sA120Voice D_0050A820[];  /* D_0050A120.f700 */

/* D_005157B8: the stream queues (a pending-callback list, then one queue per stream). Layout from every use in
   this unit; field names are their offsets. */
struct s7B8Rec {                    /* 0x20, s7B8Queue.f7C[] */
    int f00;                        /* sequence number */
    int len : 31;
    int flag : 1;
    unsigned int f08[6];            /* one per reader */
};
struct s7B8Queue {
    volatile int f00;               /* voice */
    volatile int f04;               /* records written */
    volatile unsigned int f08;
    volatile unsigned int f0C;
    volatile unsigned int f10[6];   /* per reader: records read */
    volatile short f28[6];          /* per reader: read index */
    volatile short f34[6];          /* per reader: records pending */
    volatile short f40;             /* number of records */
    volatile unsigned char f42;
    char pad43;
    volatile short f44;
    volatile short f46;             /* write index */
    volatile int f48;
    volatile int f4C;
    int f50;
    void (*f54)(int, int);
    void (*f58)(int, int, int);
    int f5C;
    char pad60[0x62 - 0x60];
    unsigned char f62;              /* number of readers */
    char pad63;
    int f64[6];
    struct s7B8Rec f7C[1];
};
struct s7B8Event {                  /* 8 bytes: a callback to run (f00 == 0: f58, else f54) */
    unsigned short f00;
    unsigned short f02;             /* queue */
    int f04;
};
struct s7B8 {
    int f000;                       /* number of f004 entries */
    struct s7B8Event f004[0x60];
    struct s7B8Queue *f304[32];
};
extern struct s7B8 D_005157B8;

/* D_00515B40: the software mixer (channel buffers, per-voice gain entries with their filter chains, the filter
   factories). Layout from every use in this unit; field names are their offsets. */
struct sB40Node {                   /* a filter in an entry's chain (allocated, size per kind) */
    int (*f00)(struct sB40Node *, int, int, float *, int);     /* process */
    void (*f04)(struct sB40Node *);                             /* release */
    struct sB40Node *f08;           /* next */
    struct sB40Node *f0C;
    struct sB40Node *f10;
    struct sB40Node *f14;
    unsigned short f18;             /* order in the chain */
    signed char f1A;
    unsigned char f1B;
};
struct sB40Init {                   /* what func_003C8158 hands a filter factory */
    int f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int (*f28)(struct sB40Node *);
};
struct sB40Ent {                    /* 0x60, D_00515B40.f1DC[] (one per mixer voice) */
    signed char f00;                /* state */
    signed char f01;                /* gains changed */
    char pad02[0x4 - 0x2];
    float f04[6];                   /* current channel gains */
    float f1C[6];                   /* wanted channel gains */
    float f34[1];                   /* current effect send */
    float f38[1];                   /* wanted effect send */
    float f3C;                      /* last sample */
    struct sB40Node *f40;           /* filter chain */
    int (*f44)(struct sB40Node *);
    struct sB40Node *f48;
    struct sB40Node *f4C;
    struct sB40Node *f50;
    struct sB40Node *f54;
    int f58;
    struct sB40Node *f5C;
};
struct sB40 {
    char pad00[0x4];
    unsigned char f04;              /* number of f1DC entries */
    unsigned char f05;              /* number of channels (also D_00515B45) */
    char pad06[0x8 - 0x6];
    int (*f08)(int);                /* also D_00515B48 */
    unsigned short f0C;
    unsigned char f0E;              /* also D_00515B4E */
    signed char f0F[1];             /* effect send on (also D_00515B4F) */
    void (*f10)(int);               /* output hook (also D_00515B50) */
    int *f14;                       /* output buffer (also D_00515B54) */
    void (*f18[6][3])(struct sB40Node *, struct sB40Init *);   /* filter factories by kind and variant */
    int f60[6][3];                  /* their node sizes */
    int fA8[2];
    int fB0;
    float *fB4;                     /* mix buffer */
    int fB8[6];
    float *fD0[6];                  /* channel buffers */
    float fE8[6];                   /* channel gains */
    float f100[1];                  /* effect send gain */
    struct sB40Node *f104[6];
    struct sB40Node *f11C[6];
    char pad134[0x1DC - 0x134];
    struct sB40Ent *f1DC;           /* also D_00515D1C */
    void (*f1E0)(int, float *, float *, float);                 /* add a voice into a buffer */
};
extern struct sB40 D_00515B40;
extern unsigned char D_00515B45;        /* D_00515B40.f05 */
extern int (*D_00515B48)(int);          /* D_00515B40.f08 */
extern unsigned char D_00515B4E;        /* D_00515B40.f0E */
extern signed char D_00515B4F;          /* D_00515B40.f0F[0] */
extern void (*D_00515B50)(int);         /* D_00515B40.f10 */
extern int *D_00515B54;                 /* D_00515B40.f14 */
extern struct sB40Ent *D_00515D1C;      /* D_00515B40.f1DC */

/* D_0050AD00: the IOP sound side's state (RPC buffers, the shared voice block func_003C1638 lays out, the transfer
   queue, speaker gains, sound-RAM segments, the recursive lock). Layout from every use in this unit; field names are
   their offsets. */
struct sAD00Voice { int key; int val; };
struct sAD00SpuVoice {              /* 8 bytes, sAD00Spu.f20[] */
    int key;
    short pitch;
    signed char l;
    signed char r;
};
struct sAD00SpuChan {               /* 16 bytes, sAD00Spu.f1A0[] */
    int key;
    short pitch;
    signed char vol[6];
    signed char f0C[4];
};
struct sAD00Spu {                   /* 0x2A0, block 3 of the shared buffer (D_0050AD00.fCB0) */
    long f00;                       /* voice on bits */
    unsigned long f08;
    char f10;
    char f11;
    char f12;
    unsigned char f13;
    short f14;
    short f16;
    char pad18[0x20 - 0x18];
    struct sAD00SpuVoice f20[48];
    struct sAD00SpuChan f1A0[16];
};
struct sAD00Xfer {                  /* 16 bytes, D_0050AD00.fCC8[] (also D_0050B9C8) */
    unsigned int key;
    int f04;
    int f08;
    unsigned short f0C;
    unsigned char f0E;
    char pad0F;
};
struct sAD00Spk {                   /* 0x20, D_0050AD00.fE98[] (also D_0050BB98) */
    float f00[6];
    unsigned int f18;
    short f1C;
    short f1E;
};
struct sAD00Seg { unsigned short a; unsigned short b; };
struct sAD00Port { int f00; int f04; int pad08[2]; };   /* 16 bytes, D_0050AD00.fE88[] */
struct sAD00 {
    char f000[0x83C];               /* RPC send buffer */
    struct sAD00Voice f83C[48];
    struct sAD00Voice f9BC[16];
    char padA3C[0xC80 - 0xA3C];
    char fC80[0x30];                /* RPC client data */
    struct sAD00Spu *fCB0;          /* also D_0050B9B0 */
    int *fCB4;
    void *fCB8;
    volatile int fCBC;              /* last transfer id */
    volatile unsigned char fCC0;    /* queued transfers */
    volatile unsigned char fCC1;    /* selected transfer */
    volatile unsigned char fCC2;    /* transfer running */
    char padCC3;
    int fCC4;                       /* tick of the last transfer */
    struct sAD00Xfer fCC8[28];
    struct sAD00Port fE88[1];
    struct sAD00Spk fE98[96];
    unsigned short f1A98;           /* number of f1AA0 segments */
    unsigned short f1A9A;
    unsigned short f1A9C;
    unsigned short f1A9E;
    struct sAD00Seg *f1AA0;
    int f1AA4;
    int f1AA8;
    char f1AAC;
    unsigned char f1AAD;
    unsigned short f1AAE;
    char pad1AB0[0x1AB2 - 0x1AB0];
    unsigned short f1AB2;           /* fill offset while func_003C1638 lays out f1AB4 */
    char *f1AB4;
    int f1AB8;
    void *f1ABC[6];
    int f1AD4;
    int f1AD8;
    char pad1ADC[0x1AF4 - 0x1ADC];
    void *f1AF4;
    int f1AF8;
    char pad1AFC[0x1B00 - 0x1AFC];
    void *f1B00;
    int f1B04;
    int f1B08;
    int f1B0C;
    volatile int f1B10;             /* lock: semaphore, owner thread, depth */
    volatile int f1B14;
    volatile int f1B18;
    int f1B1C[7];                   /* saved SPU2 DMA registers */
    int f1B38;
};
extern struct sAD00 D_0050AD00;
extern struct sAD00Spu *D_0050B9B0;     /* D_0050AD00.fCB0 */
extern struct sAD00Xfer D_0050B9C8[];   /* D_0050AD00.fCC8 */
extern struct sAD00Spk D_0050BB98[];    /* D_0050AD00.fE98 */

INCLUDE_ASM("ealib/seg_2B4578", SHAPE_unpack);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B38B8);
#ifdef SKIP_ASM
int func_003B38B8(int arg0) {
    int var_5;

    var_5 = 0;
    switch (arg0) {
    case 15:
    case 16:
        var_5 = 0x20;
        break;
    case 18:
    case 24:
        var_5 = 0;
        break;
    case 32:
        var_5 = 0x21;
        break;
    }
    return var_5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char *f_3A10_3900(char *) __asm__("func_003B3A10");
extern void f_3D00_3900(char *, int, void *) __asm__("func_003B3D00");
extern int f_65A8_3900(void *, int) __asm__("func_004165A8");
struct B_3900 { int pad; char c; };
struct H_3900 { char pad[8]; int n; char pad2[8]; struct { int off; int x; } t[1]; };

char *func_003B3900_3900(struct H_3900 *, int) __asm__("func_003B3900");
char *func_003B3900_3900(struct H_3900 *arg0, int arg1) {
    int i;
    int n = arg0->n;
    struct B_3900 buf;
    char *p;
    for (i = 0; i < n; i++) {
        p = f_3A10_3900((char *)arg0 + arg0->t[i].off);
        if (p == 0) {
            buf.c = 0;
            f_3D00_3900((char *)arg0, i, &buf);
            p = (char *)&buf;
        }
        if (f_65A8_3900(p, arg1) == 0)
            return (char *)arg0 + arg0->t[i].off;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", SHAPE_locate);
#ifdef SKIP_ASM
extern char* func_003B3900();

char* SHAPE_locate(void) {
    return func_003B3900();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B39D8);
#ifdef SKIP_ASM
extern unsigned char D_0044C3D0[];

unsigned char func_003B39D8(unsigned char *arg0) {
    return D_0044C3D0[*arg0 & 0x7F];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B39F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C3D0_39F8[128] __asm__("D_0044C3D0");

unsigned char func_003B39F8(int arg0) {
    return D_0044C3D0_39F8[arg0 & 0x7F];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3A10);
#ifdef SKIP_ASM
unsigned char *func_003B3A10(unsigned char *p) {
    while (p) {
        int off;
        unsigned char *n;
        if (*p == 0x70) {
            return p + 4;
        }
        off = *(int *)p >> 8;
        n = p + off;
        p = off ? n : 0;
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3A50);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B3BB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B3A50_3BB0(unsigned char, short, short, unsigned int, int) __asm__("func_003B3A50");
extern int func_003B4D00_3BB0(char *, int *) __asm__("func_003B4D00");
extern int strlen_3BB0(char *) __asm__("strlen");

int func_003B3BB0(char *p) {
    int sp0;
    int r = 0;
    int w;
    unsigned int u;
    char *q;
    unsigned int t = *(unsigned char *)p;
    switch (t) {
    case 0x70:
        return strlen_3BB0(p + 4) + 5;
    case 0x6F:
        return *(int *)(p + 4) + 8;
    case 0x7C:
        return (*(int *)(p + 4) << 3) + 8;
    case 0x69:
        if (*(unsigned short *)(p + 6) & 0x10) {
            u = *(unsigned short *)(p + 4);
            if (u == 0) u = 0xF0;
            return u + 0x10;
        }
        return 0x10;
    default:
        if (*(unsigned char *)p & 0x80) {
            sp0 = 0;
            if (*(int *)(p + 0xC) & 0x1000) {
                q = p + *(int *)(p + 0x10);
            } else {
                q = p + 0x10;
            }
            if (func_003B4D00_3BB0(q, &sp0) != 0) {
                r = sp0 + 0x10;
            }
        } else {
            w = *(int *)(p + 0xC);
            r = func_003B3A50_3BB0(*(unsigned char *)p, *(short *)(p + 4), *(short *)(p + 6), (unsigned int)w >> 28, (w >> 13) & 1);
        }
        return r;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3CCC);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written accessor (starts 4 mod 8, so file-scope asm); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl func_003B3CCC\n.type func_003B3CCC, @function\nfunc_003B3CCC:\n"
    "lw $2, 0x8($4)\n"
    "jr $31\n"
    "nop\n"
    ".size func_003B3CCC, . - func_003B3CCC\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3CD8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written bounds-checked table lookup: the assembler bgeu macro (sltu $1 + beqz $1) and li as addiu $0; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003B3CD8\n.type func_003B3CD8, @function\nfunc_003B3CD8:\n"
    "lw $9, 0x8($4)\n"
    "sll $11, $5, 3\n"
    "sltu $1, $5, $9\n"
    "beqz $1, .L003B3CF8\n"
    "addu $11, $4, $11\n"
    "lw $2, 0x14($11)\n"
    "jr $31\n"
    "addu $2, $4, $2\n"
    ".L003B3CF8:\n"
    "jr $31\n"
    "addiu $2, $0, 0x0\n"
    ".size func_003B3CD8, . - func_003B3CD8\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3D00);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written bounds-checked unaligned store: the assembler bgeu macro (sltu $1 + beqz $1), an explicit load-delay nop, swr/swl; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003B3D00\n.type func_003B3D00, @function\nfunc_003B3D00:\n"
    "lw $9, 0x8($4)\n"
    "sll $11, $5, 3\n"
    "sltu $1, $5, $9\n"
    "beqz $1, .L003B3D2C\n"
    "addu $11, $4, $11\n"
    "lw $2, 0x10($11)\n"
    "nop\n"
    "swr $2, 0x0($6)\n"
    "swl $2, 0x3($6)\n"
    "jr $31\n"
    "daddu $2, $6, $0\n"
    ".L003B3D2C:\n"
    "addiu $2, $0, 0x0\n"
    "swr $2, 0x0($6)\n"
    "swl $2, 0x3($6)\n"
    "jr $31\n"
    "daddu $2, $6, $0\n"
    ".size func_003B3D00, . - func_003B3D00\n"
    ".set pop\n");
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3D40);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B3DA8);
#ifdef SKIP_ASM
int func_003B3DA8(int arg0) {
    int r = 0;
    switch (arg0) {
    case 4: r = 1; break;
    case 8: r = 2; break;
    case 0xF: case 0x10: case 0x22B: case 0x613: r = 3; break;
    case 0x20: case 0x22B8: r = 5; break;
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B3E40);

INCLUDE_ASM("ealib/seg_2B4578", func_003B4010);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4218);
#ifdef SKIP_ASM
extern int func_003B42B0(int, int, int);
extern int func_003B4338(int, int, int);
extern int func_003B43C0(int, int, int);
extern int func_003B4448(int, int, int);

int func_003B4218(int a0, int a1, int a2, int a3, int kind) {
    int result = 0;
    switch (kind) {
    case 4:
        result = func_003B42B0(a0, a1, a2);
        break;
    case 8:
        result = func_003B4338(a0, a1, a2);
        break;
    case 15:
        result = func_003B43C0(a0, a1, a2);
        break;
    case 16:
        result = func_003B43C0(a0, a1, a2);
        break;
    case 32:
        result = func_003B4448(a0, a1, a2);
        break;
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B42B0);
#ifdef SKIP_ASM
int func_003B42B0(int x, int y, int w) {
    int c = ((y & 0x70) >> 1) + ((x & 7) ^ ((y & 2) << 1) ^ (y & 4));
    int lo = (x & 0x18) + ((y & 2) << 1);
    y = ((y >> 7) << 5) + (((x & 0x60) >> 2) + ((y & 0xC) >> 1) + (y & 1));
    x = ((x >> 7) << 6) + c;
    return ((y * w / 2 + x) << 5) + lo;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B4338);

INCLUDE_ASM("ealib/seg_2B4578", func_003B43C0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4448);
#ifdef SKIP_ASM
int func_003B4448(int arg0, int arg1, int arg2) {
    return ((arg1 * arg2) + arg0) << 5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4458);
#ifdef SKIP_ASM
extern int D_0044C450;
extern void *(*D_0044C454)(void *, int, int, int, int);
extern void (*D_0044C458)(void *);

void func_003B4458(int arg0, void *(*arg1)(void *, int, int, int, int), void (*arg2)(void *)) {
    D_0044C450 = arg0;
    D_0044C454 = arg1;
    D_0044C458 = arg2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4478);
#ifdef SKIP_ASM
extern int func_003B3BB0(char *);
extern int func_003B4708(int);

int func_003B4478(char *p) {
    int total = 0;
    int base = (((int)p + 0xF) & ~0xF) - (int)p;
    if (p != 0) {
        do {
            int sz = func_003B3BB0(p);
            int off;
            char *n;
            if (total != 0) {
                if (func_003B4708(*(unsigned char *)p) != 0) {
                    int aligned = ((total - base) + 0x1F) & ~0xF;
                    int base16 = base - 0x10;
                    total = aligned + base16;
                } else {
                    int aligned = ((total - base) + 0xF) & ~0xF;
                    total = aligned + base;
                }
            }
            off = *(int *)p >> 8;
            n = p + off;
            p = off ? n : 0;
            total += sz;
        } while (p != 0);
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", SHAPE_cloneat);
#ifdef SKIP_ASM
extern int func_003B3BB0(char *);
extern int func_003B4708(int);
extern void func_003E6188(char *, char *, int);
extern int sprintf(char *, const char *, ...);
extern char D_004957B8_CA[] __asm__("D_004957B8");

void SHAPE_cloneat(char *dst, char *src) {
    int off = 0;
    char *prev;
    char *cur = 0;
    char *nx;
    int n;
    int r;
    int pad = (((int)src + 15) & -16) - (int)src;
    int padm;
    int al;
    if (src) {
        al = -16;
        padm = pad - 16;
        do {
            n = func_003B3BB0(src);
            if (off != 0) {
                r = func_003B4708(*(unsigned char *)src);
                if (r) {
                    off = (((off - pad) + 0x1F) & al) + padm;
                } else {
                    off = (((off - pad) + 0xF) & al) + pad;
                }
            }
            prev = cur;
            cur = dst + off;
            if (prev) {
                *(unsigned int *)prev = *(unsigned char *)prev | ((cur - prev) << 8);
            }
            *(unsigned int *)cur = *(unsigned char *)cur;
            if (n) {
                func_003E6188(cur, src, n);
                if (*(unsigned char *)cur == 0x69 && n > 0x14) {
                    sprintf(cur + 0x10, D_004957B8_CA, *(short *)(cur + 4));
                }
            }
            r = *(int *)src >> 8;
            nx = 0;
            if (r) nx = src + r;
            src = nx;
            off += n;
        } while (src);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4690);
#ifdef SKIP_ASM
extern int func_003B4478_4690(int) __asm__("func_003B4478");
extern void *func_003B3A10_4690(int) __asm__("func_003B3A10");
extern void SHAPE_cloneat_4690(void *, int) __asm__("SHAPE_cloneat");
extern void *(*D_0044C454)(void *, int, int, int, int);

void *func_003B4690(int arg0) {
    int sz = func_003B4478_4690(arg0);
    void *r = D_0044C454(func_003B3A10_4690(arg0), sz, 0, 0x10, 0x400);

    SHAPE_cloneat_4690(r, arg0);
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4708);
#ifdef SKIP_ASM
int func_003B4708(int arg0) {
    int var_5;

    var_5 = 0;
    switch (arg0) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x29:
    case 0x2A:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x38:
        var_5 = 1;
        break;
    }
    return var_5;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B4740);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B47F8);
#ifdef SKIP_ASM
extern void* func_003B4740();

void* func_003B47F8(void* src, void* dst) {
    return func_003B4740();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4818);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int f_4818(unsigned char *p) __asm__("func_003B4818");
static __inline__ int get24_4818(unsigned char *q) { return (q[0] << 16) | (q[1] << 8) | q[2]; }
static __inline__ int get32_4818(unsigned char *q) { return (q[0] << 24) | (q[1] << 16) | (q[2] << 8) | q[3]; }
int f_4818(unsigned char *p) {
    int v = 0;
    if (p[1] == 0xFB) {
        switch (p[0] & 0xFE) {
        case 0x10: case 0x18: case 0x1A: case 0x1E:
        case 0x30: case 0x32: case 0x34: case 0x46:
            v = get24_4818(p + 2);
            break;
        case 0x90: case 0x98: case 0x9A: case 0x9E:
        case 0xB0: case 0xB2: case 0xB4: case 0xC6:
            v = get32_4818(p + 2);
            break;
        case 0xC0:
            break;
        }
    }
    return v;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B49B0);
#ifdef SKIP_ASM
extern void func_003B4818();

void func_003B49B0(void) {
    func_003B4818();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B49D0);
#ifdef SKIP_ASM
int func_003B49D0(unsigned char *dst, unsigned char *src, int *used) {
    unsigned char *s = src;
    unsigned char *ref;
    unsigned int t;
    unsigned char c;
    unsigned int b1;
    unsigned int b2;
    unsigned int b3;
    unsigned int run;
    int len = 0;

    if (src != 0) {
        t = s[0];
        t = (t << 8) + s[1];
        s = src + 2;
        if (t & 0x8000) {
            if (t & 0x100) {
                s = src + 6;
            }
            len = *s++;
            len = (len << 8) + *s++;
            len = (len << 8) + *s++;
            len = (len << 8) + *s++;
        } else {
            if (t & 0x100) {
                s = src + 5;
            }
            len = *s++;
            len = (len << 8) + *s++;
            len = (len << 8) + *s++;
        }
        for (;;) {
            c = *s++;
            if (!(c & 0x80)) {
                b1 = *s++;
                run = c & 3;
                while (run--) *dst++ = *s++;
                ref = dst - 1 - (((c & 0x60) << 3) + b1);
                run = ((c & 0x1C) >> 2) + 3 - 1;
                do *dst++ = *ref++; while (run--);
                continue;
            }
            if (!(c & 0x40)) {
                b1 = *s++;
                b2 = *s++;
                run = b1 >> 6;
                while (run--) *dst++ = *s++;
                ref = dst - 1 - (((b1 & 0x3F) << 8) + b2);
                run = (c & 0x3F) + 4 - 1;
                do *dst++ = *ref++; while (run--);
                continue;
            }
            if (!(c & 0x20)) {
                b1 = *s++;
                b2 = *s++;
                b3 = *s++;
                run = c & 3;
                while (run--) *dst++ = *s++;
                ref = dst - 1 - ((((c & 0x10) >> 4) << 16) + (b1 << 8) + b2);
                run = ((c & 0x0C) << 6) + b3 + 5 - 1;
                do *dst++ = *ref++; while (run--);
                continue;
            }
            run = ((c & 0x1F) << 2) + 4;
            if (run <= 0x70) {
                while (run--) *dst++ = *s++;
                continue;
            }
            run = c & 3;
            while (run--) *dst++ = *s++;
            break;
        }
    }
    if (used != 0) {
        *used = s - src;
    }
    return len;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4D00);
#ifdef SKIP_ASM
int func_003B4D00(unsigned char *p, int *out) {
    int r = 0;
    unsigned char *q;
    unsigned int c;
    unsigned int n;
    if (p) {
        q = (((*p << 8) & 0x100) ? p + 5 : p + 2);
        r = *q++;
        r = (r << 8) + *q++;
        r = (r << 8) + *q++;
        if (out) {
            for (;;) {
                c = *q++;
                if ((c & 0x80) == 0) {
                    q++;
                    q += c & 3;
                } else if ((c & 0x40) == 0) {
                    n = *q >> 6;
                    q += 2;
                    q += n;
                } else if ((c & 0x20) == 0) {
                    q += 3;
                    q += c & 3;
                } else {
                    n = ((c & 0x1F) << 2) + 4;
                    if (n <= 0x70) {
                        q += n;
                    } else {
                        q += c & 3;
                        n = q - p;
                        *out = n;
                        break;
                    }
                }
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4DD8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044C45C;
extern int D_0044C460;
extern int func_003C0C90_4DD8() __asm__("func_003C0C90");

int func_003B4DD8_4DD8(struct sA8E8Setup *out) __asm__("func_003B4DD8");

int func_003B4DD8_4DD8(struct sA8E8Setup *out) {
    if (D_0044C45C == 0) {
        D_0044C460 = func_003C0C90_4DD8();
        D_0044C45C = 1;
        D_0050A8E8.setup.cfg.f08 = 0x10;
        D_0050A8E8.setup.cfg.f2B = 0x5A;
        D_0050A8E8.setup.cfg.f1C = 1;
        D_0050A8E8.setup.cfg.f14 = -1.0f;
        D_0050A8E8.saved = D_0050A8E8.setup.cfg;
    }
    *out = D_0050A8E8.setup;
    return D_0044C460;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B4FC0);
#ifdef SKIP_ASM
extern int func_003C0E28(void);
int func_003B4FC0_impl(struct sA8E8Setup *p) __asm__("func_003B4FC0");
int func_003B4FC0_impl(struct sA8E8Setup *p) {
    __builtin_memcpy(&D_0050A908, &p->cfg, sizeof(struct sA8E8Cfg));
    D_0050A9A8 = p->tail;
    func_003C0E28();
    /* D_0050A8E8.saved = D_0050A8E8.setup.cfg, addressed from D_0050A9A8 as in the target */
    __builtin_memcpy((char *)&D_0050A9A8 + 0x14, (char *)&D_0050A9A8 - 0xA0, sizeof(struct sA8E8Cfg));
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5158);
#ifdef SKIP_ASM
extern char D_0044E180;
extern void func_00416210_5158(void *, int, int) __asm__("func_00416210");
void func_003B5BD0(struct sA8E8Heap *a0, int a1);
int func_003B4DD8_4DD8(struct sA8E8Setup *out) __asm__("func_003B4DD8");
int func_003B4FC0_impl(struct sA8E8Setup *p) __asm__("func_003B4FC0");
void func_003BC588(int arg0);
void func_003C3300(void);
void func_003B58A0(void);
void func_003B58D8(void);
extern void *func_003B5C60_5158(int) __asm__("func_003B5C60");
extern int func_003C1B80(void);
extern void func_003C2268_5320() __asm__("func_003C2268");
extern void func_003C3358();
extern void func_003BC0B0(void);

int func_003B5158_impl(void *buf, int size, int arg2) __asm__("func_003B5158");

/* arg2 is passed by the caller (func_003C5B80 forwards its own argument) but not used here. */
int func_003B5158_impl(void *buf, int size, int arg2) {
    int r;
    D_0044E180 = 'S';
    if (D_0050A8E8.f174 != 0) return 0;
    func_00416210_5158(buf, 0, size);
    func_003B5BD0(buf, size);
    if (D_0050A8E8.f17E == 0) {
        r = func_003B4DD8_4DD8(&D_0050A8E8.setup);
        if (r < 0) return r;
        func_003B4FC0_impl(&D_0050A8E8.setup);
    }
    func_003BC588(D_0050A8E8.setup.cfg.f04);
    func_003C3300();
    D_0050A8E8.f174 = 1;
    func_003B58A0();
    D_0050A8E8.f1F0 = func_003B5C60_5158(D_0050A8E8.f17E * 0x8C);
    D_0050A8E8.f1F4 = func_003B5C60_5158(D_0050A8E8.setup.cfg.f08 << 4);
    func_003B58D8();
    D_0050A8E8.f330 = 0;
    D_0050A8E8.f175 = 0x7F;
    D_0050A8E8.f180 = 0;
    D_0050A8E8.f179 = 0;
    D_0050A8E8.f177 = 0;
    D_0050A8E8.f178 = 0;
    r = func_003C1B80();
    if (r < 0) {
        func_003C2268_5320();
        func_003C3358();
        D_0050A8E8.f174 = 0;
        return r;
    }
    if (D_0050A8E8.setup.cfg.f27 == 2) {
        D_0050A8E8.f2E0[1][0] = 0xC000;
        D_0050A8E8.f2E0[1][1] = 0x4000;
    } else {
        D_0050A8E8.f2E0[1][0] = 0xE000;
        D_0050A8E8.f2E0[1][1] = 0x2000;
    }
    D_0050A8E8.f2E0[2][0] = D_0050A8E8.setup.cfg.f58[2][2];
    D_0050A8E8.f2E0[2][1] = D_0050A8E8.setup.cfg.f58[2][0];
    D_0050A8E8.f2E0[2][2] = D_0050A8E8.setup.cfg.f58[2][1];
    D_0050A8E8.f2E0[3][0] = 0xE000;
    D_0050A8E8.f2E0[3][1] = 0x2000;
    D_0050A8E8.f2E0[3][2] = 0xA000;
    D_0050A8E8.f2E0[3][3] = 0x6000;
    D_0050A8E8.f2E0[4][0] = 0xE000;
    D_0050A8E8.f2E0[4][1] = 0;
    D_0050A8E8.f2E0[4][2] = 0x2000;
    D_0050A8E8.f2E0[4][3] = 0xA000;
    D_0050A8E8.f2E0[4][4] = 0x6000;
    D_0050A8E8.f2E0[5][0] = 0xE000;
    D_0050A8E8.f2E0[5][1] = 0;
    D_0050A8E8.f2E0[5][2] = 0x2000;
    D_0050A8E8.f2E0[5][3] = 0xA000;
    D_0050A8E8.f2E0[5][4] = 0x6000;
    D_0050A8E8.f2E0[5][5] = 0;
    func_003BC0B0();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5320);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B5440_5320() __asm__("func_003B5440");
extern int func_003B82B8(int, int, int, int, int);
extern void func_003BC530();
extern void func_003B8A38();
extern void func_003C2268_5320() __asm__("func_003C2268");
extern int func_003B5C40();
extern void func_003C3358();

int func_003B5320(void) {
    int r;
    if (func_003B5440_5320() == 0) return -14;
    func_003B82B8(0, 0, 0, -1, -1);
    if (D_0050A8E8.f1D8) D_0050A8E8.f1D8();
    if (D_0050A8E8.f1DC) D_0050A8E8.f1DC();
    if (D_0050A8E8.f1E0) D_0050A8E8.f1E0();
    if (D_0050A8E8.f1EC) D_0050A8E8.f1EC();
    if (D_0050A8E8.f1E8) D_0050A8E8.f1E8();
    func_003BC530();
    func_003B8A38();
    if (D_0050A8E8.f1E4) D_0050A8E8.f1E4(-1);
    func_003C2268_5320();
    func_003B58A0();
    func_003B5E98(D_0050A8E8.f1F0);
    func_003B5E98(D_0050A8E8.f1F4);
    func_003B58D8();
    r = func_003B5C40();
    D_0050A8E8.f174 = 0;
    func_003C3358();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5440);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
signed char func_003B5440(void) {
    return D_0050AA5C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5450);
#ifdef SKIP_ASM
extern void func_003C60E0();

int func_003B5450(void) {
    func_003C60E0();
    return 0;
}
#endif

void func_003B5470(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5478);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BC910(void);
extern void SYNCTASK_add_5478(void *, int, int) __asm__("SYNCTASK_add");
extern void func_003E4A30_5478(void *) __asm__("func_003E4A30");
extern int D_0044C464;

int func_003B5478(void) {
    D_0050A9B0 = func_003B5470;
    if (D_0044C464 == 0) {
        SYNCTASK_add_5478(func_003B5450, 0, 1);
        D_0044C464 = 1;
    }
    func_003E4A30_5478(func_003BC910);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B54E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044C468;

void func_003B54E0(void) {
    struct sA8E8Node *n;

    if (D_0050A8E8.f1C0 != D_0044C468) {
        n = D_0050A8E8.f1B4;
        D_0044C468 = D_0050A8E8.f1C0;
        if (n != 0) {
            do {
                n->fn(n->arg);
                n = n->next;
            } while (n != 0);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5540);
#ifdef SKIP_ASM
extern void func_003B55F0_5540(void) __asm__("func_003B55F0");

void func_003B5540(unsigned arg0) {
    unsigned lim;
    if (D_0050A8E8.f174 != 0) {
        if ((int)arg0 != (short)D_0050A8E8.f334) {
            D_0050A8E8.f334 = arg0;
            D_0050A8E8.f180 = 0;
            D_0050A8E8.f330 = 0;
        }
        D_0050A8E8.f330++;
        lim = D_0050A8E8.f330 * 100 / arg0;
        while (lim >= D_0050A8E8.f180) {
            func_003B55F0_5540();
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B55F0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5860);
#ifdef SKIP_ASM
extern void func_003C3380();

void func_003B5860(void) {
    func_003C3380();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5880);
#ifdef SKIP_ASM
extern void func_003C33E0();

void func_003B5880(void) {
    func_003C33E0();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B58A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void (*D_0044C46C)(void);

void func_003B58A0(void) {
    D_0044C46C();

    D_0050A8E8.f176++;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B58D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void (*D_0044C470_58D8[])(void) __asm__("D_0044C470");

void func_003B58D8(void) {
    D_0050A8E8.f176--;
    D_0044C470_58D8[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5910);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003B5910(void (*arg0)(void)) {
    if (D_0050A8E8.f174 != 0) {
        D_0050A8E8.f184[D_0050A8E8.f177] = arg0;
        D_0050A8E8.f177++;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5948);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B58A0();
extern void func_003B58D8();

void func_003B5948(void (*a)(void)) {
    int i;
    if (D_0050A8E8.f174) {
        func_003B58A0();
        for (i = 0; i < D_0050A8E8.f177; i++) {
            if (D_0050A8E8.f184[i] == a) {
                D_0050A8E8.f177--;
                for (; i < D_0050A8E8.f177; i++) D_0050A8E8.f184[i] = D_0050A8E8.f184[i + 1];
                break;
            }
        }
        func_003B58D8();
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5A28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003B5A28(void (*arg0)(void *)) {
    if (D_0050A8E8.f174 != 0) {
        D_0050A8E8.f1C8[D_0050A8E8.f179] = arg0;
        D_0050A8E8.f179++;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5A60);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5A60(void (*arg)(void *)) {
    int i;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8.f179; i++) {
        if (D_0050A8E8.f1C8[i] == arg) {
            D_0050A8E8.f179--;
            for (; i < D_0050A8E8.f179; i++) D_0050A8E8.f1C8[i] = D_0050A8E8.f1C8[i + 1];
            break;
        }
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5B20);
#ifdef SKIP_ASM
extern void func_003B58A0();
extern void func_003B58D8();
extern int func_003C4E50(int, int);

int func_003B5B20(int arg0, int arg1) {
    int temp_16;

    func_003B58A0();
    temp_16 = func_003C4E50(arg0, arg1);
    func_003B58D8();
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5B68);
#ifdef SKIP_ASM
extern void func_003B58A0();
extern void func_003B58D8();
extern int func_003C4EC8(int);

int func_003B5B68(int arg0) {
    int temp_16;

    func_003B58A0();
    temp_16 = func_003C4EC8(arg0);
    func_003B58D8();
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5BA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5BA0(int *a, int *b) {
    int x = *a;
    unsigned int lim = D_0050AB1C->f0C;
    if (lim < (unsigned int)(x + *b))
        *b = lim - x;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5BD0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5BD0(struct sA8E8Heap *a0, int a1) {
    D_0050A8E8.f234 = a0;
    a0->f08 = a1;
    D_0050A8E8.f234->f04 = (struct sA8E8HeapEnt *)((char *)a0 + a1 - 8);
    a1 -= 0xF;
    D_0050A8E8.f234->f00 = (int)a0 + 0x18;
    D_0050A8E8.f234->f00 += 0xF;
    D_0050A8E8.f234->f00 &= 0xFFFFFFF0;
    D_0050A8E8.f234->f0C = a1 - 0x20;
    D_0050A8E8.f234->f10 = a1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5C40);
#ifdef SKIP_ASM
extern int func_003C6240();

int func_003B5C40(void) {
    return func_003C6240();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B5C60);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5E98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B5E98_5E98(int) __asm__("func_003B5E98");
void func_003B5E98_5E98(int a) {
    int i = 0;
    int d = a - D_0050A8E8.f234->f00;
    if (D_0050A8E8.f234->f14 >= 0) return;
    while (1) {
        struct sA8E8Heap *s = D_0050A8E8.f234;
        if (((struct sA8E8HeapEnt *)((char *)s->f04 + (i << 3)))->key == d) {
            s->f14++;
            D_0050A8E8.f234->f0C += 8;
            if (!(D_0050A8E8.f234->f14 < i)) return;
            do {
                D_0050A8E8.f234->f04[i] = D_0050A8E8.f234->f04[i - 1];
                i--;
            } while (D_0050A8E8.f234->f14 < i);
            return;
        }
        i--;
        if (!(s->f14 < i)) return;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5F60);
#ifdef SKIP_ASM
int func_003C51E0(void);

int func_003B5F60(void) {
    int r;
    if (D_0050AA5C != 0) {
        r = func_003C51E0();
    } else {
        r = 0;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B5F98);
#ifdef SKIP_ASM
struct Ev_5F98 { int a; int b; int c; int rest[5]; };
struct Obj_5F98 { char pad[0x17]; signed char cnt; char pad2[0x34 - 0x18]; int a[4]; int b[4]; };

void func_003B5F98(struct Obj_5F98 *o, int arg) {
    struct Ev_5F98 ev;
    int i;
    while (o->cnt > 0) {
        o->cnt--;
        ev.a = arg;
        ev.b = o->a[o->cnt];
        ev.c = o->b[o->cnt];
        for (i = 0; i < D_0050A8E8.f179; i++) {
            D_0050A8E8.f1C8[i](&ev);
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6098);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B6300_6098(int) __asm__("func_003B6300");
extern int func_003C6500(void);
extern char *f_4B70_6098(int, int) __asm__("func_003C4B70");
extern int f_42D8_6098(int, char *, char *, int) __asm__("func_003C42D8");
extern int f_42F8_6098(int) __asm__("func_003C42F8");
extern int f_6788_6098(int, char *, char *, int *) __asm__("func_003B6788");

int func_003B6098(int *out, struct sA8E8Bank *hdr) {
    struct sA8E8Slot *ent;
    int i, n, h;
    int tmp;

    D_0050A8E8.f1E4 = func_003B6300_6098;
    *out = func_003C6500();
    ent = &D_0050A8E8.f1F4[*out];
    ent->f0C = 1;
    ent->f00 = hdr;
    ent->f04 = 0;
    if (hdr->f10 != 0) {
        ent->f04 = f_4B70_6098(0x100, hdr->f10 + 0x40);
        if (ent->f04 == 0) {
            goto fail;
        }
        for (i = 0; i < hdr->f10; i += 0x1000) {
            n = hdr->f10 - i;
            h = f_42D8_6098(0x100, (char *)hdr + hdr->f08 + i, ent->f04 + i, n < 0x1001 ? n : 0x1000);
            while (f_42F8_6098(h) == 0) {
            }
        }
        tmp = 0;
        for (i = 0; i < hdr->f06; i++) {
            if (hdr->f14[i] != 0) {
                f_6788_6098(0x100, (char *)&hdr->f14[i] + hdr->f14[i], ent->f04, &tmp);
            }
        }
    }
    ent->f08 = 0;
    if (hdr->f0C != 0) {
        ent->f08 = f_4B70_6098(8, hdr->f0C + 0x30);
        if (ent->f08 == 0) {
fail:
            ent->f00 = 0;
            ent->f0C = 0;
            return -6;
        }
        for (i = 0; i < hdr->f0C; i += 0x1000) {
            n = hdr->f0C - i;
            h = f_42D8_6098(8, (char *)hdr + hdr->f08 + hdr->f10 + i, ent->f08 + i, n < 0x1001 ? n : 0x1000);
            while (f_42F8_6098(h) == 0) {
            }
        }
        tmp = 0;
        for (i = 0; i < hdr->f06; i++) {
            if (hdr->f14[i] != 0) {
                f_6788_6098(8, (char *)&hdr->f14[i] + hdr->f14[i], ent->f08, &tmp);
            }
        }
    }
    ent->f0C = 0;
    if (hdr->f0C != 0 || hdr->f10 != 0) {
        return 7;
    }
    return 8;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B6300);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5F98_6300(void *buf, int n) __asm__("func_003B5F98");
extern void func_003B89E0_6300(int h) __asm__("func_003B89E0");
extern int func_003BAAC0_6300(char **pp, void *buf) __asm__("func_003BAAC0");
extern void func_003C4D78_6300(int a, void *p) __asm__("func_003C4D78");
extern char *func_003C6540_6300(struct sA8E8Bank *p, int i) __asm__("func_003C6540");

int func_003B6300(int arg0) {
    char buf[0xD0];
    char *q;
    struct sA8E8Bank *obj;
    int i;
    int r;

    if (arg0 == -1) {
        for (i = 0; i < D_0050A8E8.setup.cfg.f08; i++) {
            func_003B6300(i);
        }
        return 0;
    }
    if (func_003B64D8(arg0) != 0) {
        return -8;
    }
    func_003B58A0();
    obj = D_0050A8E8.f1F4[arg0].f00;
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        struct sA8E8Chan *e = &D_0050A8E8.f1F0[i];
        if (e->f12 == arg0) {
            func_003B89E0_6300(e->f00);
        }
    }
    for (i = 0; i < obj->f06; i++) {
        q = func_003C6540_6300(obj, i);
        if (q != 0) {
            q += 4;
            do {
                r = func_003BAAC0_6300(&q, buf);
                func_003B5F98_6300(buf, 2);
            } while (r != 0);
        }
    }
    if (D_0050A8E8.f1F4[arg0].f04 != 0) {
        func_003C4D78_6300(0x100, D_0050A8E8.f1F4[arg0].f04);
    }
    if (D_0050A8E8.f1F4[arg0].f08 != 0) {
        func_003C4D78_6300(8, D_0050A8E8.f1F4[arg0].f08);
    }
    D_0050A8E8.f1F4[arg0].f00 = 0;
    D_0050A8E8.f1F4[arg0].f0C = 0;
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B64D8);
#ifdef SKIP_ASM
int func_003B64D8(int arg0) {
    struct sA8E8Slot *r;
    if (arg0 < 0 || arg0 >= D_0050A8E8.setup.cfg.f08) {
        return -8;
    }
    r = (struct sA8E8Slot *)(arg0 * 16 + (int)D_0050A8E8.f1F4);
    if (r->f00 != 0) {
        return r->f0C ? -0x12 : 0;
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6528);
#ifdef SKIP_ASM
int func_003B6528(int arg0) {
    return D_0050AADC[arg0].f00->f08;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6548);
#ifdef SKIP_ASM
extern void *func_0041610C(void *, void *, int);
int func_003B6548(struct sA8E8Bank *dst, int idx) {
    int ret = 0;
    int n = func_003B6528(idx);
    if (n < 0) {
        ret = n;
    } else {
        func_0041610C(dst, D_0050A8E8.f1F4[idx].f00, n);
        D_0050A8E8.f1F4[idx].f00 = dst;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B65D0);
#ifdef SKIP_ASM
extern int func_003B64D8(int);
extern unsigned int func_003B8AB8(int);

int func_003B65D0(int a) {
    int ok = 0;
    int i;
    if (func_003B64D8(a) != 0) return -8;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        struct sA8E8Chan *e = &D_0050A8E8.f1F0[i];
        if (e->f12 == a && func_003B8AB8(e->f00) == 0) {
            ok = 1;
            break;
        }
    }
    func_003B58D8();
    return ok;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6670);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B64D8_6670() __asm__("func_003B64D8");
extern void func_003BB820_6670(struct sA8E8Bank *, int, char *, int, int, int) __asm__("func_003BB820");
extern int func_003C6540_6670(struct sA8E8Bank *, int) __asm__("func_003C6540");

int func_003B6670(int a0, int a1, char *a2, int a3, int a4) {
    int o, i;
    int *p;
    if (func_003B64D8_6670() < 0) return -8;
    o = func_003C6540_6670(D_0050A8E8.f1F4[a0].f00, a1);
    if (o == 0) return -8;
    i = 0;
    func_003B58A0();
    func_003BB820_6670(D_0050A8E8.f1F4[a0].f00, o, a2, a3, a4, 0);
    if (*(unsigned char *)(a2 + 2) != 0) {
        p = (int *)(a3 + 0x18);
        do {
            if (*p != 0) {
                func_003B5E98(*p);
                *p = 0;
                p[6] = 0;
            }
            i++;
            p++;
        } while (i < *(unsigned char *)(a2 + 2));
    }
    func_003B58D8();
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B6788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5F98_6788(void *, int) __asm__("func_003B5F98");
extern int func_003BAAC0_6788(char **, void *) __asm__("func_003BAAC0");
extern void func_003C3EA8_6788(void *, int, int) __asm__("func_003C3EA8");

int func_003B6788(int arg0, char *arg1, int arg2, int arg3) {
    char sp[0xD0];
    char *spD0;
    int temp_16;

    spD0 = arg1 + 4;
    do {
        temp_16 = func_003BAAC0_6788(&spD0, sp);
        if (*(unsigned short *)(sp + 0x18) & arg0) {
            func_003C3EA8_6788(sp, arg2, arg3);
            func_003B5F98_6788(sp, 0);
        }
    } while (temp_16 != 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6820);
#ifdef SKIP_ASM
extern void *f_6540_6820(void *, int) __asm__("func_003C6540");
extern int f_B588_6820(void *, void *, int, int, int) __asm__("func_003BB588");

int func_003B6820(int a, int b, int c) {
    struct sA8E8Bank *obj;
    if (func_003B64D8(a) < 0) return -8;
    obj = D_0050AADC[a].f00;

    if (b < 0 || b >= obj->f06) return -8;
    return f_B588_6820(obj, f_6540_6820(obj, b), a, b, c);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B68B8);
#ifdef SKIP_ASM
extern int func_003B8CC8(int, int);
extern int func_003C6760(int, int, int, int);

void func_003B68B8(struct sA0A0Strm *p) {
    int i = 0;
    struct sA0A0Trk *q = p->f104;
    int *f = &p->f104[0].f10;
    p->f04 = func_003C6760(p->f08, (int)&p->f14, (int)&p->f1C, (int)&p->fEC);
    do {
        if (*f != 0) {
            func_003B8CC8(p->f04, (int)q);
        }
        q++;
        i++;
        f += 6;
    } while (i == 0);
    p->f10 = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6948);
#ifdef SKIP_ASM
int func_003B6948(unsigned char *p) {
    int v = 0;
    int w = *(unsigned short *)p;
    int h = p[2];
    int t = p[3];
    w = w * h;
    if (t == 5) v = 0x92;
    else if (t == 10) v = 0x88;
    else if (t == 4) v = 0x33;
    else if (t == 22) v = 0x66;
    else if (t == 8) v = 0x200;
    else if (t == 16) return h << 3;
    else if (t == 23) return h << 3;
    return (w * v) >> 8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B69D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B7838(int);

int func_003B69D8(void) {
    int i;

    for (i = 0; i < D_0050A8E8.setup.cfg.f26; i++) {
        func_003B7838(i);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6A38);
#ifdef SKIP_ASM
struct sA0A0Strm *func_003B6A38(int arg0) {
    if (arg0 >= D_0050A92E || arg0 < 0) {
        return 0;
    }
    return D_0050A0A0[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6A70);
#ifdef SKIP_ASM
extern struct sA0A0Node *func_003B7A70(int);
extern void func_003C6320(void *, void *);
extern void func_003C6288(void *, void *);

void func_003B6A70(int arg0) {
    struct sA0A0Strm *s = D_0050A0A0[arg0 & 0xFF];
    struct sA0A0Node *r = func_003B7A70(arg0);
    func_003C6320(&s->f11C, r);
    func_003C6288(&s->f128, r);
    if (s->f134 == r) {
        s->f134 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6AD8);
#ifdef SKIP_ASM
extern void func_003E13E8_6AD8(int, unsigned char *) __asm__("func_003E13E8");

void func_003B6AD8(void *arg0) {
    unsigned char *t = ((unsigned char **)arg0)[-1];
    func_003E13E8_6AD8(D_0050A0A0[*t]->f00, t);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B6B10);
#ifdef SKIP_ASM
void func_003B6B10(struct sA0A0Node *node, unsigned n, struct sA0A0Strm *s) {
    unsigned left = 0;
    int i = 0;
    for (;;) {
        i++;
        node = s->f11C.f00;
        if (i >= 0xC9) {
            func_003B6A70(node->f0C);
            return;
        }
        if (node->f1C < n) {
            left = n - node->f1C;
            n -= left;
        }
        node->f14 += n;
        node->f1C -= n;
        if (node->f14 >= node->f18) {
            func_003B6A70(node->f0C);
        }
        if (left == 0) return;
        n = left;
        left = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B6BD0);

INCLUDE_ASM("ealib/seg_2B4578", func_003B6EA8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7080);
#ifdef SKIP_ASM
extern void func_003B6EA8_7080(struct sA0A0Strm *, int *) __asm__("func_003B6EA8");
extern void func_003B6BD0_7080(int) __asm__("func_003B6BD0");
extern void func_003E13E8_7080(int, int *) __asm__("func_003E13E8");

int func_003B7080(int arg0, int *arg1) {
    struct sA0A0Strm *o = D_0050A0A0[arg0];
    int r;
    if (*arg1 == 0x6C444353) {
        func_003B6EA8_7080(o, arg1);
        r = 1;
    } else if (*arg1 == 0x6C484353) {
        func_003B6BD0_7080(arg0);
        r = 0;
    } else {
        func_003E13E8_7080(o->f00, arg1);
        r = 1;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B70F8);
#ifdef SKIP_ASM
extern unsigned int f_14C8_70F8(int) __asm__("func_003E14C8");
extern int f_14F8_70F8(int) __asm__("func_003E14F8");
int func_003B70F8(struct sA0A0Strm *self) {
    struct sA0A0Node *t = self->f134;
    if (t == 0) {
        return 0;
    }
    if (t->f10 == 0) {
        return 0;
    }
    if (t->f20 < 0) {
        return 1;
    }
    if (t->f20 != 0) {
        unsigned int u = f_14C8_70F8(self->f00);
        if (u > 4000000) u = 4000000;
        if (u * 1000 / t->f10 >= t->f20) {
            t->f20 = 0;
            return 0;
        }
        if (f_14F8_70F8(self->f00) == 2) {
            t->f20 = 0;
            return 0;
        }
        if (self->f128.f08 > 0) return 1;
        if (f_14F8_70F8(self->f00) == 0) {
            t->f20 = 0;
            return 0;
        }
        return 1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B71D8);
#ifdef SKIP_ASM
extern int func_003C6C98(int);
extern int func_003C6CE8(int);
extern int func_003C6C28(int);
extern int *func_003E12E0(int);

void func_003B71D8(void) {
    int i = 0;
    struct sA0A0Strm *p;
    int n;
    int r;
    int *q;
    func_003B58A0();
    for (; i < D_0050A8E8.setup.cfg.f26; i++) {
        p = D_0050A0A0[i];
        if (p == 0 || p->f11C.f08 == 0) continue;
        if (p->f10 == 2) {
            if (func_003C6C98(p->f08) > 0) continue;
            p->f14 = p->f18;
            __builtin_memcpy(&p->f1C, &p->f84, sizeof(p->f1C));
            p->f84.f18[0] = 0;
            func_003C6CE8(p->f08);
            func_003B68B8(p);
        }
        if (func_003B70F8(p) == 0) {
            if (p->f10 == 1) {
                n = func_003C6C28(p->f08);
                if (n <= 0) continue;
            } else {
                n = 8;
            }
            r = 0;
            do {
                n--;
                q = func_003E12E0(p->f00);
                if (q != 0) r = func_003B7080(i, q);
            } while (r != 0 && n > 0);
        }
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7410);
#ifdef SKIP_ASM
int func_003B7410(void) {
    int n = 0;
    int i;

    for (i = 0; i < D_0050A92E; i++) {
        if (D_0050A0A0[i] != 0) {
            n++;
        }
    }
    return n;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B7450);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B76E8);
#ifdef SKIP_ASM
extern int f_0C88_76E8(int, int, int, int) __asm__("func_003E0C88");
extern int f_0D80_76E8(int, int, int, int) __asm__("func_003E0D80");
extern struct sA0A0Node *f_62E8_76E8(struct sA0A0List *) __asm__("func_003C62E8");
extern void f_6210_76E8(void *, int, int) __asm__("func_00416210");
extern void f_62B8_76E8(struct sA0A0List *, struct sA0A0Node *) __asm__("func_003C62B8");

int func_003B76E8(int, int, int, int, int);
int func_003B76E8(int a0, int a1, int a2, int a3, int a4) {
    struct sA0A0Strm *o = func_003B6A38(a0);
    struct sA0A0Node *s;
    int r;
    if (o == 0) return -8;
    if (o->f128.f08 == 0) return -13;
    if (a4 == 0) {
        r = f_0C88_76E8(o->f00, a2, a3, 0x6C454353);
    } else if (a4 == 1) {
        r = f_0D80_76E8(o->f00, a2, 0, 0x6C454353);
    } else {
        r = a3;
    }
    if (r == 0) return -1;
    func_003B58A0();
    a4 = (int)f_62E8_76E8(&o->f128);
    s = (struct sA0A0Node *)a4;
    f_6210_76E8(s, 0, 0x28);
    f_62B8_76E8(&o->f11C, s);
    s->f08 = r;
    o->f0C += 0x100;
    if (o->f0C < 0) o->f0C = 0;
    s->f0C = o->f0C | a0;
    s->f20 = a1;
    o = (struct sA0A0Strm *)s->f0C;
    func_003B58D8();
    return (int)o;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7818);
#ifdef SKIP_ASM
int func_003B7818(int a, int b, int c, int d, int e) {
    return func_003B7450(a, b, c, d, e, 0, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7838);
#ifdef SKIP_ASM
extern int func_003B7410(void);
extern int func_003B78F8(int);
extern void func_003C6040(void (*)(void));
extern int func_003C6DA0(int);
extern void func_003E0A28(int);

int func_003B7838(int);
int func_003B7838(int h) {
    struct sA0A0Strm *o = func_003B6A38(h);
    int w;
    signed char c;
    if (o == 0) return -8;
    func_003B78F8(h);
    if (func_003B7410() == 1) {
        func_003C6040(func_003B71D8);
        D_0050AAD4 = 0;
    }
    func_003C6DA0(o->f08);
    w = o->f00;
    c = o->f11;
    D_0050A0A0[h] = 0;
    if (c == 0)
        func_003E0A28(w);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B78D8);
#ifdef SKIP_ASM
extern int func_003B76E8(int, int, int, int, int);

int func_003B78D8(int a, int b, int c, int d) {
    return func_003B76E8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B78F8);
#ifdef SKIP_ASM
extern int func_003C6CE8(int);
extern void f_1110_78F8(int) __asm__("func_003E1110");
extern void f_5E98_78F8(int) __asm__("func_003B5E98");
extern struct sA0A0Node *f_62E8_78F8(struct sA0A0List *) __asm__("func_003C62E8");
extern void func_003C6288(void *, void *);
extern void f_6210_78F8(void *, int, int) __asm__("func_00416210");

int func_003B78F8(int arg0) {
    struct sA0A0Strm *o;
    struct sA0A0Node *s;
    int i;
    func_003B58A0();
    o = func_003B6A38(arg0);
    if (o == 0) {
        func_003B58D8();
        return -8;
    }
    if (o->f04 >= 0) {
        func_003C6CE8(o->f08);
    }
    o->f04 = -1;
    if (o->f11 == 0) {
        f_1110_78F8(o->f00);
    }
    if (o->f84.f18[0] != 0) {
        i = 0;
        if (o->f18.b[2] != 0) {
            int *p = &o->f84.f18[0];
            do {
                i++;
                f_5E98_78F8(*p++);
            } while (i < o->f18.b[2]);
        }
    }
    do {
        s = f_62E8_78F8(&o->f11C);
        if (s == 0) break;
        func_003C6288(&o->f128, s);
    } while (1);
    o->f134 = 0;
    o->f10 = 0;
    f_6210_78F8(&o->f14, 0, 4);
    f_6210_78F8(&o->f18, 0, 4);
    f_6210_78F8(&o->f1C, 0, 0x68);
    f_6210_78F8(&o->f84, 0, 0x68);
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7A70);
#ifdef SKIP_ASM
struct sA0A0Node *func_003B7A70(int arg0) {
    struct sA0A0Strm *t;
    struct sA0A0Node *v;
    if (arg0 < 0) return 0;
    t = func_003B6A38(arg0 & 0xFF);
    if (t == 0) return 0;
    for (v = t->f11C.f00; v != 0; v = v->f00) {
        if (v->f0C == arg0) break;
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C65F0(int);
int func_003B7AC8_7AC8(int arg0, int arg1) __asm__("func_003B7AC8");

int func_003B7AC8_7AC8(int arg0, int arg1) {
    int t = arg0 * 0x28 + 0x138;
    return t + func_003C65F0(arg1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7B00);
#ifdef SKIP_ASM
extern int func_003B7AC8();
extern int func_003E06B0(int, int, int);

int func_003B7B00(int arg0, int m) {
    int temp_17;

    temp_17 = func_003B7AC8();
    return temp_17 + func_003E06B0(arg0 + 2, 1, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7B48);
#ifdef SKIP_ASM
extern unsigned int f_6C98_7B48(int) __asm__("func_003C6C98");
extern int func_003E14C8(int);

int func_003B7B48_impl(int, int *) __asm__("func_003B7B48");
int func_003B7B48_impl(int arg0, int *out) {
    struct sA0A0Strm *s;
    struct sA0A0Node *n;
    unsigned int t;
    int v;
    
    out[2] = 0;
    out[1] = 0;
    out[0] = 0;
    s = func_003B6A38(arg0);
    if (s == 0) return -8;
    v = s->f11C.f08;
    out[0] = v;
    if (v != 0) {
        n = s->f11C.f00;
        out[1] = n->f0C;
        if (*(unsigned short *)s->f14.b == 0) return 0;
        do {
            out[2] = f_6C98_7B48(s->f08) * 1000 / *(unsigned short *)s->f14.b;
            if (out[2] != 0) return 0;
            n = func_003B7A70(out[1]);
            if (n->f10 == 0) return 0;
        } while (0);
        t = func_003E14C8(s->f00);
        out[2] = (t > 0x3D0900 ? 0x3D0900 : t) * 1000 / n->f10;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7C40);
#ifdef SKIP_ASM
typedef struct { unsigned int lo, hi; } L64_7C40;
extern L64_7C40 f6380_7C40(int, int) __asm__("func_003C6380");
extern int f64A8_7C40(L64_7C40, int) __asm__("func_003C64A8");

int func_003B7C40(int h, int *out) {
    struct sA0A0Strm *a;
    struct sA0A0Node *b;
    unsigned int d;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    if (h < 0 || (a = func_003B6A38(h & 0xFF)) == 0) {
        return -8;
    }
    b = func_003B7A70(h);
    if (b != 0) {
        if (b->f24 == 0) {
            out[0] = 0;
        } else {
            if (a->f11C.f00 == b) {
                out[0] = 2;
                d = *(unsigned short *)a->f14.b;
            } else {
                out[0] = 1;
                d = *(unsigned short *)a->f18.b;
            }
            out[1] = f64A8_7C40(f6380_7C40(b->f14, 1000), d);
            out[2] = f64A8_7C40(f6380_7C40(b->f18 - b->f14, 1000), d);
            out[3] = b->f1C * 1000 / d;
        }
    } else {
        out[0] = 3;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7D80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void *func_003B7A70_7D80(int) __asm__("func_003B7A70");

int func_003B7D80(int arg0, int arg1) {
    int var_18;
    char *temp_2;

    var_18 = -8;
    func_003B58A0();
    temp_2 = func_003B7A70_7D80(arg0);
    if (temp_2 != 0) {
        var_18 = 0;
        *(int *)(temp_2 + 0x20) = (short)arg1;
    }
    func_003B58D8();
    return var_18;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7DE8);
#ifdef SKIP_ASM
extern int func_003B76E8(int, int, int, int, int);

int func_003B7DE8(int a, int b, int c) {
    return func_003B76E8(a, b, 0, c, 2);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E10);
#ifdef SKIP_ASM
extern int func_003B76E8(int, int, int, int, int);

void func_003B7E10(int a, int b, int c, int d) {
    func_003B76E8(a, b, c + d, 0, 1);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E38);
#ifdef SKIP_ASM
extern int func_003B7450(int, int, int, int, int, int, int);

int func_003B7E38(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    return func_003B7450(arg1, arg2, arg3, arg4, arg5, arg0, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7E70);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B7E70(void) __asm__("func_003B6A38");
void func_003B85F0_func_003B7E70(int, int) __asm__("func_003B85F0");

int func_003B7E70(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B7E70();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(char *)((char *)p + 0xEC) = arg1;
    func_003B85F0_func_003B7E70(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7EB0);
#ifdef SKIP_ASM
int *func_003B6A38_7EB0(void) __asm__("func_003B6A38");
int func_003B8530(int, int, int);

int func_003B7EB0(int arg0, int arg1, int arg2) {
    int *p;

    p = func_003B6A38_7EB0();
    if (p == 0) {
        return -8;
    }
    *(char *)((char *)p + 0xEC) = arg2;
    func_003B8530(p[1], arg1 / 10, arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7F18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_7F18(void) __asm__("func_003B6A38");
int func_003B86C0_7F18(int) __asm__("func_003B86C0");

int func_003B7F18(int h) {
    int *p;
    int r;

    p = func_003B6A38_7F18();
    if (p == 0) {
        return -8;
    }
    r = func_003B86C0_7F18(*(volatile int *)(p + 1));
    if (r < 0) {
        r = *(signed char *)((char *)p + 0xEC);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7F60);
#ifdef SKIP_ASM
int *func_003B6A38_7F60(void) __asm__("func_003B6A38");
int func_003B8C00(int, int, int);

int func_003B7F60(int arg0, int arg1, int arg2) {
    int *p;

    p = func_003B6A38_7F60();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0xF4) = arg1;
    *(short *)((char *)p + 0xF6) = arg2;
    func_003B8C00(p[1], arg1, arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B7FB8);
#ifdef SKIP_ASM
int *func_003B6A38_7FB8(void) __asm__("func_003B6A38");
int func_003B8790(int, int);

static inline int body_7FB8(int *p, int arg1) {
    if (arg1 > 0x4000) {
        arg1 = 0x4000;
    }
    *(short *)((char *)p + 0xF8) = arg1;
    func_003B8790(p[1], arg1);
    return 0;
}

int func_003B7FB8(int arg0, int arg1) {
    int *p;
    p = func_003B6A38_7FB8();
    if (p == 0) {
        return -8;
    }
    if (arg1 > 0x4000) {
        arg1 = 0x4000;
    }
    *(short *)((char *)p + 0xF8) = arg1;
    func_003B8790(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8010);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B8010(void) __asm__("func_003B6A38");
int func_003B8700(int, int);

int func_003B8010(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B8010();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(char *)((char *)p + 0xF0) = arg1;
    func_003B8700(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8050);
#ifdef SKIP_ASM
struct sTrk_8050 {
    int f0;
    volatile int handle;    /* 0x04: written by the sound thread */
    char pad8[0xF1 - 0x8];
    char fF1;
};
struct sTrk_8050 *func_003B6A38_8050(void) __asm__("func_003B6A38");

int func_003B8050(int arg0, int arg1, int arg2) {
    struct sTrk_8050 *p;

    p = func_003B6A38_8050();
    if (p == 0) {
        return -8;
    }
    p->fF1 = arg2;
    func_003B88C8(p->handle, arg1, arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B80A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B80A0(void) __asm__("func_003B6A38");
int func_003B8978(int, int);

int func_003B80A0(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B80A0();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0x100) = arg1;
    func_003B8978(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B80E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_func_003B80E0(void) __asm__("func_003B6A38");
int func_003B8838(int, int);

int func_003B80E0(int arg0, int arg1) {
    int *p;

    p = func_003B6A38_func_003B80E0();
    if (p == 0) {
        return -8;
        do { } while (0);
    }
    *(short *)((char *)p + 0xFA) = arg1;
    func_003B8838(p[1], arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8120);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int *func_003B6A38_8120(void) __asm__("func_003B6A38");
void func_003E0B28(int, int);

int func_003B8120(int arg0, int arg1) {
    int *temp_2;

    temp_2 = func_003B6A38_8120();
    if (temp_2 == 0) {
        return -8;
    }
    func_003E0B28(*temp_2, arg1);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8160);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_A7B0_8160(int) __asm__("func_003BA7B0");

int func_003B8160(int arg0) {
    int i;
    struct sA8E8Chan *e;
    func_003B58A0();
    D_0050A8E8.f175 = arg0;
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        e = &D_0050A8E8.f1F0[i];
        if (e->f69 == 1 && e->f00 >= 0) {
            f_A7B0_8160(i);
            func_003C2A50(i);
        }
    }
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8218);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

struct sA8E8Bus *func_003B8218(int arg0, int arg1) {
    switch (arg1 & 0x71C) {
    case 8:
        return &D_0050AB08[arg0];
    case 4:
        return &D_0050AAE0[arg0];
    case 0x100:
        return &D_0050AAF4[arg0];
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8290);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
int func_003B8290(unsigned long a) {
    int t = (a & 0x40) >> 3;
    if (a & 0x10) t |= 4;
    if (a & 0x20) t |= 0x100;
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B82B8);
#ifdef SKIP_ASM
extern int f8290_82B8(int) __asm__("func_003B8290");
extern int func_003C36A8(int, int);
extern int func_003B83A0(int, int);

int func_003B82B8(int a, int b, int c, int d, int e) {
    int m;
    int bit = 4;
    int id;
    if ((a & 0x1F8) == 0) a |= 0x1F8;
    m = f8290_82B8(a);
    id = a & ~0x1F8;
    while (m != 0) {
        if (bit & m) {
            struct sA8E8Bus *q = func_003B8218(id, bit);
            q->f00 = c;
            q->f04 = d;
            q->f08 = e;
            func_003C36A8(id, bit);
            m &= ~bit;
        }
        bit <<= 1;
    }
    func_003B83A0(a, c ? b : 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B83A0);
#ifdef SKIP_ASM
extern void f84E0_83Ab(int, int, int, struct sA8E8Pan *) __asm__("func_003B84E0");
extern int func_003B88C8(int, int, int);

int func_003B83A0(int arg0, int arg1) {
    int id = arg0 & ~0x1F8;
    int i;
    int f40;
    if ((arg0 & 0x1F8) == 0) {
        arg0 |= 0x1F8;
    }
    if (arg0 & 0x10) {
        D_0050A8E8.f1F8[id].f02 = arg1;
    }
    if (arg0 & 0x20) {
        D_0050A8E8.f20C[id].f02 = arg1;
    }
    f40 = arg0 & 0x40;
    if (f40) {
        D_0050A8E8.f220[id].f02 = arg1;
    }
    func_003B58A0();
    if (f40) {
        struct sA8E8Pan v;
        v.r = v.l = (float)arg1 * 0.007874016f;
        f84E0_83Ab(id, 8, 0, &v);
    }
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        struct sA8E8Chan *e = &D_0050A8E8.f1F0[i];
        func_003B88C8(e->f00, id, e->f61[id]);
    }
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B84E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_84E0 { struct sA8E8Pan v; char pad[0xC]; };
extern struct E_84E0 D_0050AB14_84E0[] __asm__("D_0050AB14");  /* &D_0050AB08[0].f0C */
extern void func_003C36C8(int, int);

int func_003B84E0(int arg0, int flags, int arg2, struct sA8E8Pan *v) {
    if (flags & 8) {
        D_0050AB14_84E0[arg0].v = *v;
    }
    func_003C36C8(arg0, flags);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8530);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BA6E8_8530(void) __asm__("func_003BA6E8");

int func_003B8530(int a, int n, int v) {
    int h = func_003BA6E8_8530();
    int sp0;
    if (h >= 0) {
        if (n <= 0) n = 1;
        sp0 = -1;
        v <<= 16;
        while (func_003BAA00(h, &sp0)) {
            struct sA8E8Chan *e = &D_0050A8E8.f1F0[sp0];
            e->f34 = v;
            e->f30 = (v - e->f38) / n;
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B85F0);
#ifdef SKIP_ASM
extern int func_003BA6E8_85F0(void) __asm__("func_003BA6E8");
extern void f_A7B0_85F0(int) __asm__("func_003BA7B0");
extern void f_2A50_85F0(int) __asm__("func_003C2A50");
extern int func_003C27E0(int, int);

int func_003B85F0_impl(int, int) __asm__("func_003B85F0");
int func_003B85F0_impl(int arg0, int arg1) {
    int h = func_003BA6E8_85F0();
    int sp0;
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            struct sA8E8Chan *e = &D_0050A8E8.f1F0[sp0];
            int v = arg1 << 16;
            e->f30 = 0;
            if (e->f38 == v) return 0;
            e->f38 = v;
            f_A7B0_85F0(sp0);
            f_2A50_85F0(sp0);
            if (e->f62[0] > 0) func_003C27E0(e->f04[0], 0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B86C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003BA6E8(int arg0);

short func_003B86C0(int arg0) {
    int i = func_003BA6E8(arg0);
    if (i < 0) {
        return -8;
    }
    return *(short *)((char *)D_0050AAD8 + i * 0x8C + 0x3A);   /* integer part of the 16.16 f38 */
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8700);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003B8700(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8(arg0);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            D_0050A8E8.f1F0[sp0].f5F = arg1;
            func_003C2EC8(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8790);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BA6E8_8790(void) __asm__("func_003BA6E8");
extern void func_003BA938_8790(int, int) __asm__("func_003BA938");
extern int func_003C25E0(int);
int func_003B8790(int a0, int arg1);

int func_003B8790(int a0, int arg1) {
    int sp0;
    int h;
    struct sA8E8Chan *e;
    int i;
    h = func_003BA6E8_8790();
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            i = sp0;
            e = &D_0050A8E8.f1F0[i];
            if (e->f88 == arg1) {
                return 0;
            }
            e->f88 = arg1;
            func_003BA938_8790(i, i);
            func_003C25E0(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8838);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C3010(int, int);

int func_003B8838(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8(arg0);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            int i = sp0;
            D_0050A8E8.f1F0[i].f6A = arg1;
            func_003C3010(i, arg1);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B88C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BA6E8_88C8() __asm__("func_003BA6E8");
extern void func_003BA740_88C8(int, int) __asm__("func_003BA740");
extern int func_003C27E0(int, int);

int func_003B88C8(int arg0, int arg1, int arg2) {
    int sp0;
    int t;
    t = func_003BA6E8_88C8();
    if (t >= 0) {
        sp0 = -1;
        while (func_003BAA00(t, &sp0) != 0) {
            D_0050A8E8.f1F0[sp0].f61[arg1] = arg2;
            func_003BA740_88C8(arg1, sp0);
            func_003C27E0(sp0, arg1);
        }
    }
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8978);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C3178_8978(int, int) __asm__("func_003C3178");

int func_003B8978(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8(arg0);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            func_003C3178_8978(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B89E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003BA6E8_89E0(void) __asm__("func_003BA6E8");
int func_003C2440(int);

int func_003B89E0(void) {
    int sp0;
    int temp_2;

    temp_2 = func_003BA6E8_89E0();
    if (temp_2 >= 0) {
        sp0 = -1;
        while (func_003BAA00(temp_2, &sp0) != 0) {
            func_003C2440(sp0);
        }
    }
    return temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8A38);
#ifdef SKIP_ASM
extern int f_89E0_8A38(int) __asm__("func_003B89E0");

void func_003B8A38(void) {
    int i = 0;
    func_003B58A0();
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        f_89E0_8A38(D_0050A8E8.f1F0[i].f00);
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8AB8);
#ifdef SKIP_ASM
unsigned int func_003B8AB8(int arg0) {
    return (unsigned int)func_003BA6E8(arg0) >> 0x1F;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8AD8);
#ifdef SKIP_ASM
extern int func_003BAA00_8AD8(int, int *) __asm__("func_003BAA00");
extern int func_003BA6E8_8AD8(void) __asm__("func_003BA6E8");
extern int func_003C4318_8AD8(int) __asm__("func_003C4318");
int func_003B8AD8(void) {
    int best = -7;
    int h = func_003BA6E8_8AD8();
    int sp0;
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00_8AD8(h, &sp0) != 0) {
            struct sA8E8Chan *e = &D_0050A8E8.f1F0[sp0];
            int v;
            if (e->f18 > 0) {
                v = -7;
            } else {
                v = func_003C4318_8AD8(sp0);
            }
            if (v >= 0) {
                int t = (e->f14 - v) * 100 / e->f20;
                if (e->f8A > 0x10) {
                    t = ((t << 12) / e->f8A << 12) / e->f6A;
                } else {
                    t = 0x7FFFFFFF;
                }
                if (best < t) {
                    best = t;
                }
            }
        }
    }
    return best;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8C00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003B8C00(int a, int b, int c) {
    int h;
    int sp0;
    if (c >= 0x4000) {
        c = 0x3FFF;
    } else if (c < -0x4000) {
        c = -0x4000;
    }
    h = func_003BA6E8(a);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0)) {
            struct sA8E8Chan *e = &D_0050A8E8.f1F0[sp0];
            e->f1C = e->f4C + b;
            e->f1E = c;
            func_003C38E0(sp0);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8CC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C5068(int, int);

int func_003B8CC8(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8(arg0);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            func_003C5068(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8D30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C5128(int, int);

int func_003B8D30(int arg0, int arg1) {
    int sp0;
    int h;

    h = func_003BA6E8(arg0);
    if (h >= 0) {
        sp0 = -1;
        while (func_003BAA00(h, &sp0) != 0) {
            func_003C5128(sp0, arg1);
        }
    }
    return h;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8D98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003B8D98(int arg0) {
    int idx;
    int v = arg0;
    if (v < 0)
        return -8;
    idx = v & 0x1F;
    if (idx < 0x10)
        return (D_0050A120.f000[idx].f10 ^ v) == 0 ? idx : -8;
    return -8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8DE8);
#ifdef SKIP_ASM
extern int func_003B9920(int);
extern int f_85F0_8DE8(int, int) __asm__("func_003B85F0");

int func_003B8DE8_impl(int) __asm__("func_003B8DE8");
int func_003B8DE8_impl(int id) {
    struct sA120Song *e = &D_0050A120.f000[id];
    struct sA120Voice *v;
    int i;
    e->f14 = e->f14 + e->f18;
    if (e->f18 < 0) {
        if (!(e->f1C < e->f14)) {
            e->f14 = e->f1C;
            e->f18 = 0;
        }
    } else {
        if (!(e->f14 < e->f1C)) {
            e->f14 = e->f1C;
            e->f18 = 0;
        }
    }
    if (e->f14 < 0) {
        func_003B9920(e->f10);
        return 1;
    }
    i = 0x17;
    v = D_0050A820;
    do {
        if (v->f04 == id && v->f00 >= 0) {
            f_85F0_8DE8(v->f00, (unsigned int)(e->f30[v->f05].b10 * (e->f14 >> 16)) >> 7);
        }
        i--;
        v++;
    } while (i >= 0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B8EE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003B8EE8(int arg0) {
    int i;
    int r = 1;
    for (i = 0; i < 0x18; i++) {
        if (D_0050A820[i].f04 == arg0 && D_0050A820[i].f00 >= 0 && func_003BA6E8(D_0050A820[i].f00) >= 0) {
            r = 0;
            break;
        }
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003B8F78);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9140);
#ifdef SKIP_ASM
extern void f7138_9140(int) __asm__("func_003C7138");

void func_003B9140(int arg0, int arg1, int arg2) {
    struct sA120Song *t = D_0050A120.f000;
    struct sA120Voice *p;
    int i = 0;
    t[arg0].f08++;
    p = D_0050A120.f700;
    do {
        if (p->f04 == arg0 && p->f05 == arg1 && p->f06 == arg2 && p->f07 >= 0) {
            f7138_9140(p->f00);
            p->f07 = -1;
            break;
        }
        i++;
        p++;
    } while (i < 0x18);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B91E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Ch_91E0 {
    char pad00[0x8];
    unsigned char *p8;
    unsigned char *pC;
    char pad10[0x16 - 0x10];
    short f16;
    char pad18[0x20 - 0x18];
    unsigned short f20;
    char pad22[0x26 - 0x22];
    unsigned char f26;
    char pad27[0x70 - 0x27];
};
struct V_91E0 {
    int h;
    signed char ch;
    signed char x;
    char pad[2];
};
struct G_91E0 {
    struct Ch_91E0 ch[16];
    struct V_91E0 v[24];
};
struct Bits_91E0 {
    unsigned int a : 10;
    unsigned int b : 7;
};
extern struct G_91E0 D_0050A120_91E0 __asm__("D_0050A120");
extern void func_003B85F0(int, unsigned int);
extern int func_003BC570_91E0(int v) __asm__("func_003BC570");

void func_003B91E0(int h, struct Bits_91E0 *bits, int x, int cmd) {
    struct V_91E0 *p = (struct V_91E0 *)&D_0050A120_91E0;
    struct Ch_91E0 *e = (struct Ch_91E0 *)((char *)p + h * 0x70);
    unsigned char *s;
    int i;

    if (cmd == 20) {
        unsigned char *t = e->p8 + 1;
        e->p8 = t;
        e->pC = t;
        return;
    } else if (cmd == 30) {
        if (e->f26 >= 0x7F) {
            e->f26 = *e->p8;
        }
        if (e->f26 != 0) {
            e->f26--;
            e->p8 = e->pC;
            return;
        }
    } else if (cmd == 7) {
        s = e->p8;
        p = (struct V_91E0 *)((char *)p + 0x700);
        i = 0x17;
        bits->b = *s;
        e->p8 = s + 1;
        do {
            if (p->ch == h && p->x == x) {
                func_003B85F0(p->h, (unsigned int)(bits->b * e->f16) >> 7);
            }
            i--;
            p++;
        } while (i >= 0);
        return;
    } else if (cmd == 10) {
        p = (struct V_91E0 *)((char *)p + 0x700);
        i = 0x17;
        bits->a = func_003BC570_91E0(*e->p8++) >> 6;
        do {
            if (p->ch == h && p->x == x) {
                int v = ((*(unsigned int *)bits & 0x3FF) << 6) + e->f20;
                func_003B8C00(p->h, (unsigned short)v, 0);
            }
            i--;
            p++;
        } while (i >= 0);
        return;
    }
    e->p8++;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B93C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003BC6B8(int, int);

void func_003B93C8(int a0, struct sA120Chan *a1, int a2, int a3) {
    struct sA120Song *r = &D_0050A120.f000[a0];
    int t, i;
    struct sA120Voice *e = &D_0050A120.f700[0];
    i = 0x17;
    t = (*r->f08++ << 7) + a3;
    a1->b17 = t / 128;
    do {
        i -= 1;
        if (e->f04 == a0 && e->f05 == a2) {
            func_003BC6B8(e->f00, a1->b17);
        }
        e += 1;
    } while (i >= 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B94B0);
#ifdef SKIP_ASM
extern int f8EE8_94B0(int) __asm__("func_003B8EE8");
extern void f9920_94B0(int) __asm__("func_003B9920");
extern void f8F78_94B0(int, struct sA120Chan *, int, int) __asm__("func_003B8F78");
extern void f9140_94B0(int, int, int) __asm__("func_003B9140");
extern void f91E0_94B0(int, struct sA120Chan *, int, int) __asm__("func_003B91E0");
extern void f93C8_94B0(int, struct sA120Chan *, int, int) __asm__("func_003B93C8");

void func_003B94B0(int h) {
    struct sA120Song *c = &D_0050A120.f000[h];
    unsigned char ev, a, b;
    unsigned char *s;
    int hi, lo;

    s = c->f08;
    s++;
    c->f08 = s;
    c->f27--;
    hi = *s & 0xF0;
    c->f08 = s + 1;
    b = s[1];
    c->f08 = s - 1;
    if (hi == 0xF0 && b == 0x2F) {
        if (f8EE8_94B0(h) != 0) f9920_94B0(c->f10);
        return;
    }
    if (c->f27 != 0) return;
    for (;;) {
        struct sA120Chan *q;
        ev = *c->f08++;
        a = *c->f08++;
        b = *c->f08++;
        hi = a & 0xF0;
        lo = a & 0xF;
        q = &c->f30[lo];
        switch (hi) {
        case 0x90:
            f8F78_94B0(h, q, lo, b);
            break;
        case 0x80:
            f9140_94B0(h, lo, b);
            break;
        case 0xB0:
            f91E0_94B0(h, q, lo, b);
            break;
        case 0xE0:
            f93C8_94B0(h, q, lo, b);
            break;
        case 0xC0:
            q->b24 = b;
            break;
        case 0xF0:
            if (b == 0x2F) {
                if (f8EE8_94B0(h) != 0) {
                    f9920_94B0(c->f10);
                } else {
                    ev = 1;
                    c->f08 -= 3;
                    c->f27++;
                }
            }
            break;
        }
        if (ev != 0) break;
        if (c->f28 != 3) break;
    }
    c->f27 = ev;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B96B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B8DE8_96B8(int) __asm__("func_003B8DE8");
extern void func_003B94B0_96B8(int) __asm__("func_003B94B0");

void func_003B96B8(void) {
    int i;
    struct sA120Song *e;
    signed char st;
    unsigned int lim;
    int t;
    for (i = 0; i < 16; i++) {
        e = &D_0050A120.f000[i];
        st = e->f28;
        if (st == 3 && (e->f18 == 0 || func_003B8DE8_96B8(i) == 0)) {
            t = e->f00;
            lim = (unsigned int)(t * e->f24) / 100u;
            e->f00 = t + 1;
            if (lim >= e->f04 && e->f28 == st) {
                do {
                    func_003B94B0_96B8(i);
                    e->f04++;
                } while (lim >= e->f04 && e->f28 == 3);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B97D8);
#ifdef SKIP_ASM
extern void func_003B58A0();
extern void func_003B58D8();
extern void f_5910_97D8(void (*)(void)) __asm__("func_003B5910");
extern void func_003B96B8(void);
extern void f_9880_97D8(void) __asm__("func_003B9880");

int func_003B97D8(void) {
    int i;
    struct sA120Song *b;
    int end;
    func_003B58A0();
    for (i = 0; i < 24; i++) {
        D_0050A820[i].f05 = -1;
        D_0050A820[i].f06 = 0;
        D_0050A820[i].f07 = 0;
        D_0050A820[i].f00 = -1;
    }
    b = D_0050A120.f000;
    end = (int)(b + 16);
    do {
        b->f10 = -1;
        b->f28 = 0;
        b++;
    } while ((int)b < end);
    f_5910_97D8(func_003B96B8);
    D_0050A8E8.f1E8 = f_9880_97D8;
    func_003B58D8();
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003B9880);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5948_9880(void (*)(void)) __asm__("func_003B5948");
extern int func_003B98C0(void);

int func_003B9880(void) {
    func_003B58A0();
    func_003B98C0();
    func_003B5948_9880(func_003B96B8);
    D_0050AAD0 = 0;
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B98C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B58A0();
extern void func_003B58D8();
extern int func_003B9920(int);

int func_003B98C0(void) {
    int i;

    func_003B58A0();
    for (i = 0; i < 16; i++) {
        func_003B9920(D_0050A120.f000[i].f10);
    }
    func_003B58D8();
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9920);
#ifdef SKIP_ASM
extern int func_003B8D98(int);
extern void f_89E0_9920(int) __asm__("func_003B89E0");

int func_003B9920(int);
int func_003B9920(int arg0) {
    int idx = func_003B8D98(arg0);
    struct sA120Song *e;
    struct sA120Voice *vt;
    int i;
    if (idx < 0) return idx;
    e = &D_0050A120.f000[idx];
    if (e->f28 != 0) {
        vt = D_0050A120.f700;
        for (i = 0; i < 24; i++) {
            if (vt[i].f04 == idx) {
                if (vt[i].f00 >= 0) f_89E0_9920(vt[i].f00);
                vt[i].f05 = -1;
                vt[i].f06 = 0;
                vt[i].f07 = 0;
                vt[i].f00 = -1;
            }
        }
        e->f10 = -1;
        e->f28 = 2;
        return 0;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9A00);
#ifdef SKIP_ASM
struct H_9A00 { signed char f00; char pad01[7]; unsigned short f08; char pad0A[2]; unsigned short f0C; char pad0E[2]; unsigned short f10; };

int func_003B9A00(struct H_9A00 *hdr, unsigned char *data, int arg2, int arg3) {
    int ret = -9;
    struct sA120Song *e;
    int i;
    int j;
    if (*(short *)data == 0x444D) {
        data += 8;
    } else if (*(int *)data == 0x7844494D) {
        data += 4;
    }
    D_0050A120.f7C0 += 0x20;
    if (D_0050A120.f7C0 < 0) D_0050A120.f7C0 = 0;
    for (i = 0; i < 16; i++) {
        e = &D_0050A120.f000[i];
        if (e->f10 < 0) {
            e->f04 = 0;
            e->f00 = 0;
            e->f24 = (hdr->f10 * 100) >> 12;
            e->f10 = D_0050A120.f7C0 | i;
            e->f08 = data;
            e->f2C = arg2;
            e->f2E = arg3;
            e->f26 = 0xFF;
            e->f27 = 1;
            e->f18 = 0;
            e->f0C = 0;
            e->f14 = hdr->f00 << 16;
            e->f28 = 3;
            e->f20 = hdr->f08;
            e->f22 = hdr->f0C;
            for (j = 0; j < 16; j++) {
                struct sA120Chan *q = &e->f30[j];
                q->b00 = 0;
                q->b10 = 0x7F;
                q->b17 = 0x40;
                q->b24 = -1;
            }
            ret = e->f10;
            break;
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9B68);
#ifdef SKIP_ASM
extern int func_003B8790(int, int);

int func_003B9B68(int, int);
int func_003B9B68(int arg0, int arg1) {
    int r = -1;
    int idx = func_003B8D98(arg0);
    struct sA120Song *e;
    struct sA120Voice *vt;
    int i;
    if (idx < 0) {
        return idx;
    }
    e = &D_0050A120.f000[idx];
    if (arg1 != e->f22) {
        if (e->f28 != 3) {
            goto out;
        }
        e->f22 = arg1;
        vt = D_0050A120.f700;
        i = 0x17;
        do {
            if (vt->f04 == idx) {
                if (vt->f00 >= 0) {
                    func_003B8790(vt->f00, arg1);
                }
            }
            i--;
            vt++;
        } while (i >= 0);
    }
    r = 0;
out:
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9C20);
#ifdef SKIP_ASM
extern int func_003B8C00(int, int, int);

int func_003B9C20(int, int);
int func_003B9C20(int arg0, int arg1) {
    struct sA120Song *e;
    int r = -1;
    int id = func_003B8D98(arg0);
    if (id < 0) {
        return id;
    }
    e = &D_0050A120.f000[id];
    if (arg1 != e->f20) {
        struct sA120Voice *p;
        int i;
        if (e->f28 != 3) {
            goto out;
        }
        e->f20 = arg1;
        p = D_0050A120.f700;
        i = 0x17;
        do {
            if (p->f04 == id && p->f00 >= 0) {
                arg1 = e->f20 + (e->f30[p->f05].b00 << 6);
                func_003B8C00(p->f00, arg1 & 0xFFFF, 0);
            }
            i--;
            p++;
        } while (i >= 0);
    }
    r = 0;
out:
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9D00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B89E0_9D00(int) __asm__("func_003B89E0");
int func_003B9FC8(int arg0);

int func_003B9D00(int arg0) {
    int r, h, i;
    struct sA120Voice *p;
    struct sA120Song *t;

    func_003B58A0();
    h = func_003B8D98(arg0);
    if (h < 0) {
        func_003B58D8();
        return h;
    }
    t = &D_0050A120.f000[h];
    if (t->f28 == 3) {
        p = D_0050A120.f700;
        t->f28 = 5;
        i = 0x17;
        do {
            i--;
            if (p->f04 == h) {
                if (p->f00 >= 0) func_003B89E0_9D00(p->f00);
            }
            p++;
        } while (i >= 0);
    }
    r = func_003B9FC8(arg0);
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9DC8);
#ifdef SKIP_ASM
int func_003B9DC8(int arg0) {
    int r, h;
    struct sA120Song *t;

    func_003B58A0();
    h = func_003B8D98(arg0);
    if (h < 0) {
        func_003B58D8();
        return h;
    }
    t = &D_0050A120.f000[h];
    if (t->f28 == 5)
        t->f28 = 3;
    r = func_003B9FC8(arg0);
    func_003B58D8();
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9E48);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B8D98_9E48() __asm__("func_003B8D98");
extern void func_003B85F0(int, unsigned int);

int func_003B9E48(int a0, int vol) {
    int ret = 0;
    int idx = func_003B8D98_9E48();
    if (idx < 0) {
        return idx;
    }
    {
        int key = vol << 16;
        struct sA120Song *e = &D_0050A120.f000[idx];
        e->f18 = 0;
        if (e->f14 != key) {
            if (e->f28 == 3) {
                struct sA120Voice *p;
                int i;
                e->f14 = key;
                p = D_0050A120.f700;
                i = 0x17;
                do {
                    if (p->f04 == idx) {
                        int v = p->f00;
                        if (v >= 0) {
                            func_003B85F0(v, (unsigned int)(e->f30[p->f05].b10 * vol) >> 7);
                        }
                    }
                    i -= 1;
                    p++;
                } while (i >= 0);
            } else {
                ret = -1;
            }
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9F38);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003B9F38(int arg0, int arg1, int arg2) {
    int r;
    struct sA120Song *e;
    int t;
    r = func_003B8D98(arg0);
    if (r < 0) return r;
    e = &D_0050A120.f000[r];
    if (e->f28 == 3) {
        if (arg1 <= 0) arg1 = 1;
        t = arg2 << 16;
        e->f1C = t;
        e->f18 = (t - e->f14) / arg1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003B9FC8);
#ifdef SKIP_ASM
int func_003B9FC8(int arg0) {
    int var_5;
    struct sA120Song *temp_2;

    var_5 = func_003B8D98(arg0);
    if (var_5 >= 0) {
        temp_2 = &D_0050A120.f000[var_5];
        var_5 = temp_2->f28;
        if (var_5 == 3) {
            var_5 = (temp_2->f18 != 0) ? 6 : var_5;
        }
    }
    return var_5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA020);
#ifdef SKIP_ASM
struct S_A020 {
    unsigned char b0, b1, b2, b3, b4, b5;
    short pad6;
    unsigned short h8, hA, hC, hE, h10, h12, h14, h16;
};

int func_003BA020(struct S_A020 *s) {
    s->hC = 0x1000;
    s->b2 = 0x3C;
    s->hE = 0x1000;
    s->h10 = 0x1000;
    s->h12 = 0;
    s->h14 = 0xFFFF;
    s->h16 = 0;
    s->b1 = 0x40;
    s->b3 = 0x7F;
    s->b0 = 0x7F;
    s->b4 = 0x7F;
    s->b5 = 0x7F;
    s->h8 = 0;
    s->hA = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA078);
#ifdef SKIP_ASM
extern short D_0050AC20[];

int func_003BA078(int arg0, int arg1) {
    int i;
    for (i = 0; i < arg1; i++) {
        if (D_0050AC20[i] == arg0) {
            return 1;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA0B0);
#ifdef SKIP_ASM
extern short D_0050AC20_A0B0[] __asm__("D_0050AC20");
extern int D_0044C478;
extern int f_A078_A0B0(int, int) __asm__("func_003BA078");
extern void f_89E0_A0B0(int) __asm__("func_003B89E0");

short func_003BA0B0(int n, int tag, unsigned int *out, int lo, int hi) {
    int result = -9;
    int sel = 0;
    int i;
    int k;
    int best;
    unsigned int key;
    int lim;
    struct sA8E8Chan *e;

    for (i = 0; i < n; i++) {
        D_0050AC20_A0B0[i] = -1;
    }
    D_0044C478 += 0x100;
    if (D_0044C478 < 0) {
        D_0044C478 = 0;
    }
    for (i = 0; i < n; i++) {
        best = -1;
        key = 0xFFFFFFFF;
        for (k = lo; k < hi; k++) {
            e = &D_0050A8E8.f1F0[k];
            if (e->f69 == 0 && f_A078_A0B0(k, sel) == 0 && e->f2C < key) {
                key = e->f2C;
                best = k;
            }
        }
        if (best >= 0) {
            D_0050AC20_A0B0[sel] = best;
            sel++;
        }
    }
    for (i = sel; i < n; i++) {
        best = -1;
        lim = tag;
        if (D_0050A8E8.setup.cfg.f1C == 0) lim = tag - 1;
        key = 0xFFFFFFFF;
        for (k = lo; k < hi; k++) {
            if (f_A078_A0B0(k, sel) == 0) {
                e = &D_0050A8E8.f1F0[k];
                if (e->f2A < 0x65) {
                    if (e->f2A < lim) {
                        lim = e->f2A;
                        key = e->f2C;
                        best = k;
                    } else if (e->f2A == lim && e->f2C < key) {
                        key = e->f2C;
                        best = k;
                    }
                }
            }
        }
        if (best >= 0) {
            D_0050AC20_A0B0[sel] = best;
            sel++;
            if (sel >= n) break;
        }
    }
    if (sel == n) {
        int sorted;
        do {
            sorted = 1;
            for (i = 0; i < sel - 1; i++) {
                short t = D_0050AC20_A0B0[i];
                if (D_0050AC20_A0B0[i + 1] < t) {
                    D_0050AC20_A0B0[i] = D_0050AC20_A0B0[i + 1];
                    sorted = 0;
                    D_0050AC20_A0B0[i + 1] = t;
                }
            }
        } while (!sorted);
        *out = D_0044C478 | D_0050AC20_A0B0[0];
        result = D_0050AC20_A0B0[0];
        for (i = 0; i < sel; i++) {
            int w;
            e = &D_0050A8E8.f1F0[D_0050AC20_A0B0[i]];
            w = e->f00;
            if (e->f69 != 0) {
                if (w < 0) {
                    w = D_0050A8E8.f1F0[e->f28].f00;
                }
                f_89E0_A0B0(w);
            }
            e->f69 = 1;
            e->f2C = D_0050A8E8.f180;
            e->f2A = tag;
        }
        D_0050A8E8.f1F0[D_0050AC20_A0B0[0]].f00 = *out;
        D_0050A8E8.f1F0[D_0050AC20_A0B0[0]].f04[0] = D_0050AC20_A0B0[0];
        D_0050A8E8.f1F0[D_0050AC20_A0B0[0]].f28 = -1;
        for (i = 1; i < sel; i++) {
            D_0050A8E8.f1F0[D_0050AC20_A0B0[0]].f04[i] = D_0050AC20_A0B0[i];
            D_0050A8E8.f1F0[D_0050AC20_A0B0[i]].f00 = -1;
            D_0050A8E8.f1F0[D_0050AC20_A0B0[i]].f28 = D_0050AC20_A0B0[0];
        }
    }
    return result;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA550);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003BA550(int i, unsigned char u) {
    struct sA8E8Chan *e = &D_0050A8E8.f1F0[i];
    unsigned char k = e->f26;
    int n = 0;
    int sel = -1;
    int j;
    if (k != 0) {
        for (j = 0; j < D_0050A8E8.f17E; j++) {
            struct sA8E8Chan *q = &D_0050A8E8.f1F0[j];
            if (q->f26 == k && q->f00 >= 0 && q->f69 != 0) {
                n++;
                if (q->f27) sel = j;
            }
        }
        e = &D_0050A8E8.f1F0[i];
        if (n == 1) {
            e->f69 = 0;
            e->f26 = 0;
            e->f27 = 0;
            e->f2C = D_0050A8E8.f180;
            return;
        }
        if (D_0050A8E8.f1F0[sel].f69 == 2 && i != sel && n == 2) {
            e->f69 = 0;
            e->f26 = 0;
            e->f27 = 0;
            e->f2C = D_0050A8E8.f180;
            D_0050A8E8.f1F0[sel].f69 = 0;
            D_0050A8E8.f1F0[sel].f26 = 0;
            D_0050A8E8.f1F0[sel].f27 = 0;
            D_0050A8E8.f1F0[sel].f2C = D_0050A8E8.f180;
            return;
        }
        if (D_0050A8E8.f1F0[sel].f69 == 1 && i == sel) {
            D_0050A8E8.f1F0[sel].f69 = 2;
            return;
        }
        e->f69 = 0;
        e->f26 = 0;
        e->f27 = 0;
        e->f2C = D_0050A8E8.f180;
        return;
    }
    e->f69 = 0;
    e->f26 = 0;
    e->f27 = 0;
    e->f2C = D_0050A8E8.f180;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA6E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003BA6E8(int arg0) {
    int var_5;
    struct sA8E8Chan *e;

    if (arg0 < 0) {
        return -8;
    }
    var_5 = arg0 & 0xFF;
    if (var_5 >= D_0050A8E8.f17E) {
        return -8;
    }
    e = &D_0050A8E8.f1F0[var_5];
    if (e->f69 == 0 || e->f00 != arg0) {
        var_5 = -8;
    }
    return var_5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA740);
#ifdef SKIP_ASM
void func_003BA740(int a, int i) {
    struct sA8E8Chan *e = &D_0050AAD8[i];
    struct sA8E8Bus *q = func_003B8218(a, e->f24);
    e->f62[a] = (e->f60[a] * e->f61[a] * q->f02) >> 6;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BA7B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA888);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044C480_A888[] __asm__("D_0044C480");

int func_003BA888(int x) {
    int scale = 0x1000;
    int t;
    while (x >= 0x4B0) {
        x -= 0x4B0;
        scale <<= 1;
    }
    while (x < -0x4AF) {
        x += 0x4B0;
        scale >>= 1;
    }
    t = (x * 0x369D) >> 16;
    if (t <= -0x100)
        t = -0xFF;
    if (t < 0)
        scale = (scale * (D_0044C480_A888[t + 0x100] + 0x100)) >> 9;
    else
        scale = (scale * (D_0044C480_A888[t] + 0x100)) >> 8;
    return scale;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BA938);
#ifdef SKIP_ASM
extern short f_A888_A938(int) __asm__("func_003BA888");

void func_003BA938(int idx) {
    struct sA8E8Chan *e = &D_0050AAD8[idx];
    int v;
    if (e->f86 == 0) {
        int a = e->f84;
        if (e->f82 != 0) {
            int c = e->f74 != 0 ? e->f74[e->f64] : e->f64;
            a += ((c - 0x40) * e->f82) >> 6;
        }
        if (e->f7C != 0) {
            a += ((e->f7C[e->f68] - 0x40) * e->f80) >> 6;
        }
        e->f86 = f_A888_A938(a);
    }
    v = e->f86;
    e->f8A = (v * e->f88) >> 12;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BAA00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003BAA00(int h, int *pos) {
    struct sA8E8Chan *e = &D_0050A8E8.f1F0[h];
    unsigned char t = e->f26;
    if (t != 0) {
        (*pos)++;
        while (*pos < D_0050A8E8.f17E) {
            e = &D_0050A8E8.f1F0[*pos];
            if (e->f26 == t && e->f69 == 1 && e->f00 >= 0) return 1;
            (*pos)++;
        }
    } else if (*pos < 0) {
        *pos = h;
        return 1;
    }
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BAAC0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BB0C8);
#ifdef SKIP_ASM
extern unsigned char D_0044C588;

unsigned char func_003BB0C8(void) {
    int i;
again:
    D_0044C588 = D_0044C588 + 1;
    if (D_0044C588 == 0) {
        D_0044C588 = D_0044C588 + 1;
    }
    for (i = 0; i < D_0050A8E8.f17E; i++) {
        struct sA8E8Chan *e = &D_0050A8E8.f1F0[i];
        if (e->f69 != 0 && e->f26 == D_0044C588) {
            goto again;
        }
    }
    return D_0044C588;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BB140);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003BB588);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Rec_B588 {
    short id;
    char pad2[6];
    unsigned char x0;
    unsigned char x1;
    unsigned char y0;
    unsigned char y1;
    char padC[0xD0 - 0xC];
};
extern unsigned char func_003BB0C8(void);
extern int f_AAC0_B588(int **, struct Rec_B588 *) __asm__("func_003BAAC0");
extern int func_003C72A0(int);
extern int f_B140_B588(int, int, int *, signed char *, struct Rec_B588 *, int, int, int) __asm__("func_003BB140");
extern void f_5F98_B588(struct Rec_B588 *, int) __asm__("func_003B5F98");
extern unsigned int func_003B8AB8(int);
extern void f_89E0_B588(int) __asm__("func_003B89E0");

int func_003BB588_impl(int *self, int *cur, int a2, int a3, signed char *pos) __asm__("func_003BB588");
int func_003BB588_impl(int *self, int *cur, int a2, int a3, signed char *pos) {
    struct Rec_B588 rec;
    int ids[12];
    int n;
    int m;
    int i;
    int k;
    struct sA8E8Chan *e;
    int ret;
    int first;
    int h;
    int x;
    int y;
    int tag;
    int more;

    n = 0;
    e = 0;
    ret = -9;
    first = 0;
    h = 0;
    if (cur == 0) {
        return -8;
    }
    if (self == 0) {
        self = cur;
    }
    cur++;
    y = pos[2];
    x = pos[3];
    tag = func_003BB0C8();
    do {
        more = f_AAC0_B588(&cur, &rec);
        if (!first) {
            if (rec.id) {
                h = func_003C72A0(rec.id);
            }
            first = 1;
        }
        if (x >= (signed char)rec.x0 && x <= (signed char)rec.x1 && y >= (signed char)rec.y0 && y <= (signed char)rec.y1) {
            ret = f_B140_B588(a2, a3, self, pos, &rec, y, x, h);
            if (ret < 0) {
                goto fail;
            }
            ids[n++] = ret;
            f_5F98_B588(&rec, 1);
        }
    } while (more);

    m = n;
    n = 0;
    for (i = 0; i < m; i++) {
        if (func_003B8AB8(ids[i]) == 0) {
            ids[n++] = ids[i];
        }
    }
    if (n == 0) {
        goto fail;
    }
    if (n == 1) {
        k = func_003BA6E8(ids[0]);
        if (k >= 0) {
            e = &D_0050AAD8[k];
            e->f26 = 0;
            e->f27 = 0;
        }
    } else {
        for (i = 0; i < n; i++) {
            k = func_003BA6E8(ids[i]);
            if (k >= 0) {
                e = &D_0050A8E8.f1F0[k];
                e->f26 = tag;
                e->f27 = 0;
            }
        }
        e->f27 = 1;
    }
    return ret;
fail:
    for (i = 0; i < n; i++) {
        f_89E0_B588(ids[i]);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BB820);
#ifdef SKIP_ASM
struct Rec_B820 { int p; int id; int v1; int v2; int v3; };
struct Hdr_B820 { unsigned short rate; unsigned char nch; unsigned char f03; };
struct Ext_B820 { int f00; int pos[6]; };
struct Out_B820 {
    char pad00[2];
    unsigned char f02;
    char pad03[2];
    unsigned char f05;
    unsigned char f06;
    unsigned char f07;
    unsigned short f08;
    char pad0A[2];
    short f0C[6];
    void *data[6];
    int len[6];
    int a[4];
    int b[4];
};
extern void f_6210_B820(void *, int, int) __asm__("func_00416210");
extern int f_7218_B820(struct Out_B820 *) __asm__("func_003C7218");
extern int f_7388_B820(struct Rec_B820 *) __asm__("func_003C7388");
extern void *f_5C60_B820(int) __asm__("func_003B5C60");
extern void func_003C51E8(void *, void *, int);
extern void func_003BBDA0(int, int, unsigned char *, char *, int *);

void func_003BB820(int base, unsigned char *src, struct Hdr_B820 *hdr, struct Out_B820 *out, struct Ext_B820 *extra, char *gstr) {
    struct Rec_B820 rec;
    int d[6];
    int k;
    int bits;
    int *pos;
    int i;

    f_6210_B820(d, 0, sizeof(d));
    k = 0;
    f_6210_B820(hdr, 0, 4);
    bits = 8;
    pos = 0;
    f_6210_B820(out, 0, 0x68);
    f_6210_B820(extra, 0, 0x1C);
    if (!(src[0] == 'P' && src[1] == 'T') && src[0] == 'G' && src[1] == 'S' && src[2] == 'T' && src[3] == 'R') {
        func_003BBDA0(0, (int)src, (unsigned char *)hdr, (char *)out, (int *)extra);
        if (gstr != 0) {
            *gstr = 1;
        }
        return;
    }
    if (gstr != 0) {
        *gstr = 0;
    }
    f_7218_B820(out);
    rec.p = (int)(src + 4);
    hdr->rate = 22050;
    hdr->nch = 1;
    hdr->f03 = 5;
    extra->f00 = 0;
    while (f_7388_B820(&rec) != 0) {
        if (rec.id == 0xA0) {
            hdr->f03 = rec.v1;
        } else if (rec.id == 0x9C) {
            d[0] = rec.v1;
        } else if (rec.id == 0x9D) {
            d[1] = rec.v1;
        } else if (rec.id == 0x9E) {
            d[2] = rec.v1;
        } else if (rec.id == 0x9F) {
            d[3] = rec.v1;
        } else if (rec.id == 0xA6) {
            d[4] = rec.v1;
        } else if (rec.id == 0xA7) {
            d[5] = rec.v1;
        } else if (rec.id == 0x98) {
            out->data[0] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[0], (void *)rec.v2, rec.v3);
            out->len[0] = rec.v3;
        } else if (rec.id == 0x99) {
            out->data[1] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[1], (void *)rec.v2, rec.v3);
            out->len[1] = rec.v3;
        } else if (rec.id == 0x9A) {
            out->data[2] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[2], (void *)rec.v2, rec.v3);
            out->len[2] = rec.v3;
        } else if (rec.id == 0x9B) {
            out->data[3] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[3], (void *)rec.v2, rec.v3);
            out->len[3] = rec.v3;
        } else if (rec.id == 0xA4) {
            out->data[4] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[4], (void *)rec.v2, rec.v3);
            out->len[4] = rec.v3;
        } else if (rec.id == 0xA5) {
            out->data[5] = f_5C60_B820(rec.v3);
            func_003C51E8(out->data[5], (void *)rec.v2, rec.v3);
            out->len[5] = rec.v3;
        } else if (rec.id == 0x80) {
            out->f07 = rec.v1;
        } else if (rec.id == 0x82) {
            hdr->nch = rec.v1;
        } else if (rec.id == 0x84) {
            hdr->rate = rec.v1;
        } else if (rec.id == 0x85) {
            extra->f00 = rec.v1;
        } else if (rec.id == 0x8A) {
            pos = (int *)rec.v2;
        } else if (rec.id == 0x13) {
            out->f05 = rec.v1;
        } else if (rec.id == 0x0A) {
            out->f06 = rec.v1;
        } else if (rec.id == 0x06) {
            out->f02 = rec.v1;
        } else if (rec.id == 0x8C) {
            bits = rec.v1;
        } else if (rec.id == 0x88) {
            extra->pos[0] = rec.v1;
        } else if (rec.id == 0x89) {
            extra->pos[1] = rec.v1;
        } else if (rec.id == 0x94) {
            extra->pos[2] = rec.v1;
        } else if (rec.id == 0x95) {
            extra->pos[3] = rec.v1;
        } else if (rec.id == 0xA2) {
            extra->pos[4] = rec.v1;
        } else if (rec.id == 0xA3) {
            extra->pos[5] = rec.v1;
        } else if (rec.id == 0x14) {
            out->a[k] = rec.v2;
            out->b[k] = rec.v3;
            k++;
        }
    }
    out->f08 = bits;
    for (i = hdr->nch - 1; i >= 0; i--) {
        if (D_0050A8E8.setup.cfg.f27 == 2 && hdr->nch == 2) {
            d[i] = 0;
        }
        out->f0C[i] = D_0050A8E8.f2E0[hdr->nch - 1][i] + d[i];
        if ((out->f08 & 0x14) != 0 || out->f08 == 0) {
            extra->pos[i] = base + extra->pos[i];
        }
        if ((out->f08 & 0x308) != 0 && pos != 0) {
            if (i == 0) {
                extra->pos[0] = *pos;
            } else {
                extra->pos[i] = *pos + (extra->pos[i] - extra->pos[0]);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BBDA0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct O_BDA0 { char pad[0x48]; int a[4]; int b[4]; };
struct Rec_BDA0 { int p; int id; int v1; int v2; int v3; };
extern void f_6210_BDA0(void *, int, int) __asm__("func_00416210");
extern void f_7218_BDA0(char *) __asm__("func_003C7218");
extern int f_7388_BDA0(struct Rec_BDA0 *) __asm__("func_003C7388");
extern unsigned short D_0050ABC8_BDA0[][6] __asm__("D_0050ABC8");

void func_003BBDA0(int unused, int src, unsigned char *hdr, char *out, int *extra) {
    int a[43];
    int c[43];
    int d[46];
    int b[46];
    struct Rec_BDA0 rec;
    int i;
    int k;

    k = 0;
    f_6210_BDA0(hdr, 0, 4);
    f_6210_BDA0(out, 0, 0x68);
    f_6210_BDA0(extra, 0, 0x1C);
    f_7218_BDA0(out);
    rec.p = src + 8;
    for (i = 42; i >= 0; i--) {
        c[i] = 0;
    }
    for (i = 45; i >= 0; i--) {
        b[i] = 0;
    }
    d[2] = 1;
    d[4] = 48000;
    d[0x20] = 10;
    d[5] = 0;
    while (f_7388_BDA0(&rec) != 0) {
        if (rec.id < 0x2B) {
            a[rec.id] = rec.v1;
            c[rec.id] = rec.v2;
            if (rec.id == 0x14) {
                ((struct O_BDA0 *)out)->a[k] = rec.v2;
                ((struct O_BDA0 *)out)->b[k] = rec.v3;
                k++;
            }
        } else if ((unsigned int)(rec.id - 0x80) >= 0x2E) {
            if (rec.id != 0xFE) {
                continue;
            }
            break;
        } else {
            d[rec.id - 0x80] = rec.v1;
            b[rec.id - 0x80] = rec.v2;
        }
    }
    hdr[2] = d[2];
    hdr[3] = d[0x20];
    *(unsigned short *)hdr = d[4];
    *extra = d[5];
    *(short *)(out + 8) = 4;
    out[7] = 3;
    for (i = 0; i < hdr[2]; i++) {
        ((unsigned short *)(out + 0xC))[i] = D_0050ABC8_BDA0[hdr[2] - 1][i];
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC000);
#ifdef SKIP_ASM
extern float func_003BC770(float);
extern float func_003BC840(float);

void func_003BC000(float *out, int arg1, int arg2, int arg3) {
    float a = 2.0f * ((float)arg1 / 65535.0f) * 3.1415927f;
    float b = 2.0f * ((float)arg2 / 65535.0f) * 3.1415927f;
    float c = 2.0f * ((float)arg3 / 65535.0f) * 3.1415927f;
    float t = (c - b) / (a - b) * 1.5707964f;
    out[0] = func_003BC770(t);
    out[1] = func_003BC840(t);
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BC0B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC4C0);
#ifdef SKIP_ASM
extern unsigned char* D_0050AC38[];
void func_003BC4C0(int a, float* out)
{
    int idx = (a & 0xFFFF) >> 8;
    int i;
    for (i = 0; i < D_0050A8E8.setup.cfg.f27; i++) {
        out[i] = (float)D_0050AC38[i][idx] / 255.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC530);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0050AC30;
extern char D_0050AC38_C530[] __asm__("D_0050AC38");

void func_003BC530(void) {
    func_003B58A0();
    if (D_0050AC38_C530 != 0) {
        func_003B5E98(D_0050AC30);
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC570);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned short D_0044C590_C570[128] __asm__("D_0044C590");

unsigned short func_003BC570(int arg0) {
    return D_0044C590_C570[arg0];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC588);
#ifdef SKIP_ASM
extern int D_0044C690[];
extern int D_0050AC50[];

void func_003BC588(int arg0) {
    int i;
    for (i = 0; i < 6; i++) {
        D_0050AC50[i] = D_0044C690[i] + arg0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC5C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned int D_0050AC50_C5C8[6] __asm__("D_0050AC50");

unsigned int func_003BC5C8(void) {
    unsigned int s, c, n;

    s = D_0050AC50_C5C8[5] + D_0050AC50_C5C8[4];
    c = 0;
    if (s < D_0050AC50_C5C8[5] || s < D_0050AC50_C5C8[4]) {
        c = 1;
    }
    D_0050AC50_C5C8[4] = s;
    s = s + D_0050AC50_C5C8[3] + c;
    c = s < D_0050AC50_C5C8[3];
    D_0050AC50_C5C8[3] = s;
    s = s + D_0050AC50_C5C8[2] + c;
    c = s < D_0050AC50_C5C8[2];
    D_0050AC50_C5C8[2] = s;
    n = ++D_0050AC50_C5C8[5];
    s = s + D_0050AC50_C5C8[1] + c;
    c = s < D_0050AC50_C5C8[1];
    D_0050AC50_C5C8[1] = s;
    s = s + D_0050AC50_C5C8[0] + c;
    D_0050AC50_C5C8[0] = s;
    if (n == 0) {
        if (++D_0050AC50_C5C8[4] == 0) {
            if (++D_0050AC50_C5C8[3] == 0) {
                if (++D_0050AC50_C5C8[2] == 0) {
                    if (++D_0050AC50_C5C8[1] == 0) {
                        s = ++D_0050AC50_C5C8[0];
                    }
                }
            }
        }
    }
    return s;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC6B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f_A6E8_C6B8() __asm__("func_003BA6E8");
extern void f_A938_C6B8(int) __asm__("func_003BA938");
extern int func_003C25E0(int);

int func_003BC6B8(int arg0, int arg1) {
    int sp0;
    int r = f_A6E8_C6B8();
    struct sA8E8Chan *e;
    if (r >= 0) {
        sp0 = -1;
        while (func_003BAA00(r, &sp0) != 0) {
            e = &D_0050A8E8.f1F0[sp0];
            if (e->f64 == arg1)
                return 0;
            if (e->f82 != 0) {
                e->f86 = 0;
                e->f64 = arg1;
                f_A938_C6B8(sp0);
                func_003C25E0(sp0);
            } else
                return 0;
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC770);
#ifdef SKIP_ASM
float func_003BC770(float x) {
    float x2, x3, x5, x7, x9, x11, x13;
    while (x > 6.2831855f) {
        x -= 6.2831855f;
    }
    x2 = x * x;
    x3 = x2 * x;
    x5 = x2 * x3;
    x7 = x2 * x5;
    x9 = x2 * x7;
    x11 = x2 * x9;
    x13 = x2 * x11;
    return x - x3 * 0.16666667f + x5 * 0.00833333f - x7 * 0.00019841270f + x9 * 2.7557319e-6f - x11 * 2.5052108e-8f + x13 * 1.6059e-10f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC840);
#ifdef SKIP_ASM
float func_003BC840(float x) {
    float x2, x4, x6, x8, x10, x12;
    while (x > 6.2831855f) {
        x -= 6.2831855f;
    }
    x2 = x * x;
    x4 = x2 * x2;
    x6 = x2 * x4;
    x8 = x4 * x4;
    x10 = x2 * x8;
    x12 = x6 * x6;
    return 1.0f - x2 * 0.5f + x4 * 0.041666668f - x6 * 0.0013888889f + x8 * 2.4801588e-5f - x10 * 2.755732e-7f + x12 * 2.0876758e-9f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC910);
#ifdef SKIP_ASM
extern void func_003C5E08();

void func_003BC910(void) {
    func_003C5E08();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC930);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BECA0_C930(void) __asm__("func_003BECA0");
extern void func_003BED30_C930(void) __asm__("func_003BED30");
extern void func_003BF0F0_C930(void) __asm__("func_003BF0F0");
extern void *D_0050C840;
extern void *D_0050C844;
extern void *D_0050C848;

void func_003BC930(void) {
    D_0050C840 = func_003BECA0_C930;
    D_0050C844 = func_003BED30_C930;
    D_0050C848 = func_003BF0F0_C930;

}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BC968);
#ifdef SKIP_ASM
void func_003BC968(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D400 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
    *(volatile int *)0x1000D410 = arg0;
    *(volatile int *)0x1000D480 = arg1;
    *(volatile int *)0x1000D420 = arg2;
    *(volatile int *)0x1000D400 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D400 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BCA28);
#ifdef SKIP_ASM
void func_003BCA28(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D000 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
    *(volatile int *)0x1000D010 = arg1;
    *(volatile int *)0x1000D080 = arg0;
    *(volatile int *)0x1000D020 = arg2;
    *(volatile int *)0x1000D000 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D000 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BCAE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char p0[6]; unsigned short pos; unsigned char *buf; } BW_CAE8;
extern BW_CAE8 *D_0050AC68_CAE8[] __asm__("D_0050AC68");

void func_003BCAE8(int arg0, int n) {
    unsigned int v = arg0 << (0x20 - n);
    int byte;
    int room;
    int take;
    int rem;
    v = v >> (0x20 - n);
    while (n > 0) {
        byte = D_0050AC68_CAE8[0]->pos >> 3;
        if (byte & 1)
            byte = byte - 1;
        else
            byte = byte + 1;
        room = 8 - (D_0050AC68_CAE8[0]->pos & 7);
        if (room == 8)
            D_0050AC68_CAE8[0]->buf[byte] = 0;
        take = (room >= n) ? n : room;
        rem = n - take;
        D_0050AC68_CAE8[0]->buf[byte] |= (v >> rem) << (room - take);
        n = rem;
        D_0050AC68_CAE8[0]->pos += take;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BCBA0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD078);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C06B0_D078(int a0, float *buf, void *p, signed char *tbl) __asm__("func_003C06B0");
extern signed char D_0044DD00_D078[] __asm__("D_0044DD00");
extern int D_0044C760_D078[] __asm__("D_0044C760");
extern signed char D_0044DD38_D078[] __asm__("D_0044DD38");
extern void *D_0050AC68;

void func_003BD078(int a0, signed char *out, signed char *out8) {
    float buf[8];
    float max;
    float min;
    float scale;
    int i;
    int n;
    int idx;

    max = 0.0f;
    min = 0.0f;
    func_003C06B0_D078(a0, buf, (char *)D_0050AC68 + 0x6C, D_0044DD00_D078);
    for (i = 0; i < 8; i++) {
        if (max < buf[i]) {
            max = buf[i];
        } else if (buf[i] < min) {
            min = buf[i];
        }
    }
    min = -min;
    if (max < min) {
        max = min;
    }
    if (max < 4.0f) {
        idx = D_0044DD38_D078[(int)max];
    } else {
        n = (int)((float)*(int *)&max * 6.524646209982166e-07f) - 0x2B8;
        idx = n + 1;
        if (max < (float)D_0044C760_D078[n]) {
            idx = n;
        }
    }
    *out = idx;
    scale = 1.0f / (float)D_0044C760_D078[idx] * 28.571428298950195f;
    for (i = 0; i < 8; i++) {
        out8[i] = (int)(buf[i] * scale);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD220);
#ifdef SKIP_ASM
struct S_D220 { char pad[4]; unsigned short w4; };
struct C_D220 { char pad0[0x600]; char b600[0x200]; char b800[0x220]; int *pA20; int *pA24; int *pA28; int *pA2C; int *pA30; int *pA34; int *pA38; unsigned char padA3C; };
extern struct S_D220 *D_0050AC68_D220 __asm__("D_0050AC68");
extern struct C_D220 *D_0050AC6C_D220 __asm__("D_0050AC6C");
extern void func_003BC968(int, int, int, int);
extern void func_003BCA28(int, int, int, int);
extern void fF3E0_D220(int, int, int) __asm__("func_003BF3E0");
extern void fF440_D220(int, int, int) __asm__("func_003BF440");
extern void fF4C0_D220(int, int, void *) __asm__("func_003BF4C0");
extern void fF5A0_D220(int, int, void *) __asm__("func_003BF5A0");
extern void fF6B0_D220(int, int, void *) __asm__("func_003BF6B0");
extern void fF800_D220(void *) __asm__("func_003BF800");
extern void fF8D0_D220(void *, void *) __asm__("func_003BF8D0");
extern void fF960_D220(void *, void *) __asm__("func_003BF960");
extern void fFAC0_D220(void *, void *) __asm__("func_003BFAC0");
extern void fFB90_D220(void *, void *) __asm__("func_003BFB90");
extern void fFC50_D220(void *, int) __asm__("func_003BFC50");
extern void fFD60_D220(void *, int, void *) __asm__("func_003BFD60");
extern void fFE80_D220(void *, int, void *) __asm__("func_003BFE80");
extern void fFFA0_D220(void *, int, void *) __asm__("func_003BFFA0");
extern void f01A0_D220(void *, int, int, int) __asm__("func_003C01A0");
void func_003BD220(unsigned int a0, int a1, unsigned int a2) {
    short b;
    int i;
    if (!(D_0050AC6C_D220->padA3C == 0)) {
        b = 0;
        if ((a0 & 0x70000000) != 0x70000000) {
            b = (a2 & 0x70000000) != 0x70000000;
        }
    } else {
        b = 0;
    }
    if (b) {
        func_003BC968(a2, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4 >> 2, 0);
        fF440_D220(a0, (int)D_0050AC6C_D220->pA20 + D_0050AC68_D220->w4 * 4, 0x200);
        if (*(volatile int *)0x1000D400 & 0x100) {
            do {
            } while (*(volatile int *)0x1000D400 & 0x100);
        }
    } else {
        fF3E0_D220(a2, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4);
    }
    i = 0;
    do {
        if (b) {
            if (D_0050AC68_D220->w4 == 0xE0) {
                fF4C0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else if (D_0050AC68_D220->w4 == 0x160) {
                fF5A0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else {
                fF6B0_D220((int)D_0050AC6C_D220->pA20 + i * 0x200, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            }
        } else {
            fF440_D220(a0, (int)D_0050AC6C_D220->pA20 + D_0050AC68_D220->w4 * 4, 0x80);
            if (D_0050AC68_D220->w4 == 0xE0) {
                fF4C0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else if (D_0050AC68_D220->w4 == 0x160) {
                fF5A0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            } else {
                fF6B0_D220((int)D_0050AC6C_D220->pA20, (int)D_0050AC6C_D220->pA24, D_0050AC6C_D220->b600);
            }
            fF3E0_D220((int)D_0050AC6C_D220->pA20 + 0x200, (int)D_0050AC6C_D220->pA20, D_0050AC68_D220->w4);
        }
        i++;
        a0 += 0x100;
        fF800_D220(D_0050AC6C_D220->b600);
        fF8D0_D220(D_0050AC6C_D220->b600, D_0050AC6C_D220->b800);
        fF960_D220(D_0050AC6C_D220->b800, D_0050AC6C_D220->b600);
        fFAC0_D220(D_0050AC6C_D220->b600, D_0050AC6C_D220->b800);
        fFB90_D220(D_0050AC6C_D220->b800, D_0050AC6C_D220->b600);
        fFC50_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA28);
        fFD60_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA2C, D_0050AC6C_D220->b800);
        fFE80_D220(D_0050AC6C_D220->b800, (int)D_0050AC6C_D220->pA30, D_0050AC6C_D220->b600);
        fFFA0_D220(D_0050AC6C_D220->b600, (int)D_0050AC6C_D220->pA34, D_0050AC6C_D220->b800);
        f01A0_D220(D_0050AC6C_D220->b800, (int)D_0050AC6C_D220->pA38, a1, 0x40);
        a1 += 0x10;
    } while (i < 4);
    if (b) {
        func_003BCA28((int)D_0050AC6C_D220->pA20 + 0x800, a2, D_0050AC68_D220->w4 >> 2, 0x10000);
    } else {
        fF3E0_D220((int)D_0050AC6C_D220->pA20, a2, D_0050AC68_D220->w4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD5B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Blk_D5B8 {
    int *data;
    unsigned char sf[24];
};
struct S_D5B8 {
    unsigned char mode;
    unsigned char n;
    char pad2[6];
    unsigned char *out;
    float fC[24];
    int a6C[6];
    struct Blk_D5B8 *ptrs[5];
};
struct C_D5B8 {
    char pad0[0xA00];
    unsigned short q[16];
    char padA20[0xA20 - 0xA20];
    float *pA20;
};
extern struct S_D5B8 *D_0050AC68_D5B8 __asm__("D_0050AC68");
extern struct C_D5B8 *D_0050AC6C_D5B8 __asm__("D_0050AC6C");
extern int D_0044C760_D5B8[] __asm__("D_0044C760");
extern signed char D_0044DD38_D5B8[] __asm__("D_0044DD38");
extern void f03E0_D5B8(struct C_D5B8 *, float *) __asm__("func_003C03E0");
extern void func_003C0564(void *, void *, float);
extern void func_003C05E0(void *, void *, float);

void func_003BD5B8(int ch) {
    struct Blk_D5B8 *blk;
    unsigned char *sf;
    unsigned char *out;
    unsigned short *q;
    unsigned char *b;
    float x;
    int i;
    int n;
    int idx;

    blk = D_0050AC68_D5B8->ptrs[ch];
    f03E0_D5B8(D_0050AC6C_D5B8, D_0050AC6C_D5B8->pA20);
    sf = blk->sf;
    for (i = 0; i < 24; i++) {
        x = D_0050AC6C_D5B8->pA20[i] * D_0050AC68_D5B8->fC[i];
        if (x < 4.0f) {
            idx = D_0044DD38_D5B8[(int)x];
        } else {
            n = (int)((float)*(int *)&x * 6.5246462099821656e-07f) - 0x2B8;
            idx = n + 1;
            if (x < (float)D_0044C760_D5B8[n]) {
                idx = n;
            }
        }
        blk->sf[i] = idx;
    }
    out = D_0050AC68_D5B8->out + (ch * 0xDC + 0xEA);
    q = D_0050AC6C_D5B8->q;
    for (i = 0; i < 14; i++) {
        func_003C0564((char *)D_0050AC6C_D5B8 + i * 0x40, q, 1.0f / (float)D_0044C760_D5B8[sf[i]]);
        out[1] = q[0] >> 2;
        out[0] = (q[0] << 6) | (q[1] >> 4);
        out[3] = (q[1] << 4) | (q[2] >> 6);
        out[2] = (q[2] << 2) | (q[3] >> 8);
        out[5] = q[3];
        out[4] = q[4] >> 2;
        out[7] = (q[4] << 6) | (q[5] >> 4);
        out[6] = (q[5] << 4) | (q[6] >> 6);
        out[9] = (q[6] << 2) | (q[7] >> 8);
        out[8] = q[7];
        out[0x371] = q[8] >> 2;
        out[0x370] = (q[8] << 6) | (q[9] >> 4);
        out[0x373] = (q[9] << 4) | (q[10] >> 6);
        out[0x372] = (q[10] << 2) | (q[11] >> 8);
        out[0x375] = q[11];
        out[0x374] = q[12] >> 2;
        out[0x377] = (q[12] << 6) | (q[13] >> 4);
        out[0x376] = (q[13] << 4) | (q[14] >> 6);
        out[0x379] = (q[14] << 2) | (q[15] >> 8);
        out[0x378] = q[15];
        out += 10;
    }
    for (; i < 24; i++) {
        func_003C05E0((char *)D_0050AC6C_D5B8 + i * 0x40, q, 1.0f / (float)D_0044C760_D5B8[sf[i]]);
        b = (unsigned char *)q;
        out[1] = b[0];
        out[0] = b[1];
        out[3] = b[2];
        out[2] = b[3];
        out[5] = b[4];
        out[4] = b[5];
        out[7] = b[6];
        out[6] = b[7];
        out[0x371] = b[8];
        out[0x370] = b[9];
        out[0x373] = b[10];
        out[0x372] = b[11];
        out[0x375] = b[12];
        out[0x374] = b[13];
        out[0x377] = b[14];
        out[0x376] = b[15];
        out += 8;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BD9C0);
#ifdef SKIP_ASM
extern void *D_0050AC68;

void func_003BD9C0(void) {
    int temp_3;
    int var_7;
    int var_8;
    void *temp_4;
    void *temp_4_2;
    void *temp_5;
    void *temp_5_2;
    void *var_6;

    var_7 = 0;
    var_6 = (*(int *)((char*)(D_0050AC68) + (8))) + 0x8D;
    if ((*(unsigned char *)((char*)(D_0050AC68) + (1))) != 0) {
        var_8 = 4;
        do {
            temp_3 = var_7 * 4;
            var_7 += 2;
            temp_4 = (*(void **)((char*)((D_0050AC68 + temp_3)) + (0x84)));
            temp_5 = temp_4 + 4;
            (*(signed char *)((char*)(var_6) + (-1))) = (signed char) (((*(unsigned char *)((char*)(temp_4) + (4))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (1))) >> 6));
            (*(signed char *)((char*)(var_6) + (2))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (1))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (2))) >> 5));
            (*(signed char *)((char*)(var_6) + (1))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (2))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (3))) >> 4));
            (*(signed char *)((char*)(var_6) + (4))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (3))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (4))) >> 3));
            (*(signed char *)((char*)(var_6) + (3))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (4))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (5))) >> 2));
            (*(signed char *)((char*)(var_6) + (6))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (5))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (6))) >> 1));
            (*(signed char *)((char*)(var_6) + (5))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (7))) | ((*(unsigned char *)((char*)(temp_5) + (6))) << 7));
            (*(signed char *)((char*)(var_6) + (8))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (8))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (9))) >> 6));
            (*(signed char *)((char*)(var_6) + (7))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (9))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xA))) >> 5));
            (*(signed char *)((char*)(var_6) + (0xA))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xA))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xB))) >> 4));
            (*(signed char *)((char*)(var_6) + (9))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xB))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xC))) >> 3));
            (*(signed char *)((char*)(var_6) + (0xC))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xC))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xD))) >> 2));
            (*(signed char *)((char*)(var_6) + (0xB))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0xD))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0xE))) >> 1));
            (*(signed char *)((char*)(var_6) + (0xE))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (0xF))) | ((*(unsigned char *)((char*)(temp_5) + (0xE))) << 7));
            (*(signed char *)((char*)(var_6) + (0xD))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x10))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x11))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x10))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x11))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x12))) >> 5));
            (*(signed char *)((char*)(var_6) + (0xF))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x12))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x13))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x12))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x13))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x14))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x11))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x14))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x15))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x14))) = (signed char) (((*(unsigned char *)((char*)(temp_5) + (0x15))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5) + (0x16))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x13))) = (signed char) ((*(unsigned char *)((char*)(temp_5) + (0x17))) | ((*(unsigned char *)((char*)(temp_5) + (0x16))) << 7));
            temp_4_2 = (*(void **)((char*)((D_0050AC68 + var_8)) + (0x84)));
            var_8 += 8;
            temp_5_2 = temp_4_2 + 4;
            (*(signed char *)((char*)(var_6) + (0x16))) = (signed char) (((*(unsigned char *)((char*)(temp_4_2) + (4))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (1))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x15))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (1))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (2))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x18))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (2))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (3))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x17))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (3))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (4))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x1A))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (4))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (5))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x19))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (5))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (6))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x1C))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (7))) | ((*(unsigned char *)((char*)(temp_5_2) + (6))) << 7));
            (*(signed char *)((char*)(var_6) + (0x1B))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (8))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (9))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x1E))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (9))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xA))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x1D))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xA))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xB))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x20))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xB))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xC))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x1F))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xC))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xD))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x22))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0xD))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0xE))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x21))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (0xF))) | ((*(unsigned char *)((char*)(temp_5_2) + (0xE))) << 7));
            (*(signed char *)((char*)(var_6) + (0x24))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x10))) * 2) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x11))) >> 6));
            (*(signed char *)((char*)(var_6) + (0x23))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x11))) * 4) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x12))) >> 5));
            (*(signed char *)((char*)(var_6) + (0x26))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x12))) * 8) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x13))) >> 4));
            (*(signed char *)((char*)(var_6) + (0x25))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x13))) * 0x10) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x14))) >> 3));
            (*(signed char *)((char*)(var_6) + (0x28))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x14))) << 5) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x15))) >> 2));
            (*(signed char *)((char*)(var_6) + (0x27))) = (signed char) (((*(unsigned char *)((char*)(temp_5_2) + (0x15))) << 6) | ((unsigned char) (*(unsigned char *)((char*)(temp_5_2) + (0x16))) >> 1));
            (*(signed char *)((char*)(var_6) + (0x2A))) = (signed char) ((*(unsigned char *)((char*)(temp_5_2) + (0x17))) | ((*(unsigned char *)((char*)(temp_5_2) + (0x16))) << 7));
            var_6 += 0x2A;
        } while (var_7 < (int) (*(unsigned char *)((char*)(D_0050AC68) + (1))));
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BDE08);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BE6E0);
#ifdef SKIP_ASM
extern struct S_D5B8 *D_0050AC68_E6E0 __asm__("D_0050AC68");
extern void func_003BD078(int a0, signed char *out, signed char *out8);

void func_003BE6E0(char *arg0) {
    signed char q[8];
    signed char idx;
    unsigned char *p;
    unsigned char *s;
    int i;

    p = D_0050AC68_E6E0->out + 0xAA;
    for (i = 0; i < D_0050AC68_E6E0->n; i++) {
        s = D_0050AC68_E6E0->ptrs[i]->sf;
        if (i & 1) {
            p[-1] = p[-1] & 0xf8 | s[0] >> 4;
            p[2] = s[0] << 4 | s[1] >> 3;
            p[1] = s[1] << 5 | s[2] >> 2;
            p[4] = s[2] << 6 | s[3] >> 1;
            p[3] = s[4] | s[3] << 7;
            p[6] = s[5] << 1 | s[6] >> 6;
            p[5] = s[6] << 2 | s[7] >> 5;
            p[8] = s[7] << 3 | s[8] >> 4;
            p[7] = s[8] << 4 | s[9] >> 3;
            p[10] = s[9] << 5 | s[10] >> 2;
            p[9] = s[10] << 6 | s[11] >> 1;
            p[12] = s[12] | s[11] << 7;
            p[11] = s[13] << 1 | s[14] >> 6;
            p[14] = s[14] << 2 | s[15] >> 5;
            p[13] = s[15] << 3 | s[16] >> 4;
            p[16] = s[16] << 4 | s[17] >> 3;
            p[15] = s[17] << 5 | s[18] >> 2;
            p[18] = s[18] << 6 | s[19] >> 1;
            p[17] = s[20] | s[19] << 7;
            p[20] = s[21] << 1 | s[22] >> 6;
            p[19] = s[22] << 2 | s[23] >> 5;
            p[21] = p[21] & 7 | s[23] << 3;
        } else {
            p[1] = p[1] & 0xf8 | s[0] >> 4;
            p[0] = s[0] << 4 | s[1] >> 3;
            p[3] = s[1] << 5 | s[2] >> 2;
            p[2] = s[2] << 6 | s[3] >> 1;
            p[5] = s[4] | s[3] << 7;
            p[4] = s[5] << 1 | s[6] >> 6;
            p[7] = s[6] << 2 | s[7] >> 5;
            p[6] = s[7] << 3 | s[8] >> 4;
            p[9] = s[8] << 4 | s[9] >> 3;
            p[8] = s[9] << 5 | s[10] >> 2;
            p[11] = s[10] << 6 | s[11] >> 1;
            p[10] = s[12] | s[11] << 7;
            p[13] = s[13] << 1 | s[14] >> 6;
            p[12] = s[14] << 2 | s[15] >> 5;
            p[15] = s[15] << 3 | s[16] >> 4;
            p[14] = s[16] << 4 | s[17] >> 3;
            p[17] = s[17] << 5 | s[18] >> 2;
            p[16] = s[18] << 6 | s[19] >> 1;
            p[19] = s[20] | s[19] << 7;
            p[18] = s[21] << 1 | s[22] >> 6;
            p[21] = s[22] << 2 | s[23] >> 5;
            p[20] = p[20] & 7 | s[23] << 3;
        }
        p += 0x15;
    }
    p = D_0050AC68_E6E0->out + 0x113;
    func_003BD078(*(int *)(arg0 + 0x14), &idx, q);
    p[-1] = (p[-1] & 0xF8) | (q[0] >> 5);
    p[2] = (q[0] << 5) | (q[1] >> 5);
    p[1] = (q[1] << 5) | (q[2] >> 5);
    p[4] = (q[2] << 5) | (q[3] >> 5);
    p[3] = (q[3] << 5) | (q[4] >> 5);
    p[6] = (q[4] << 5) | (q[5] >> 5);
    p[5] = (q[5] << 5) | (q[6] >> 5);
    p[8] = (q[6] << 5) | (q[7] >> 5);
    p[7] = (q[7] << 5) | ((unsigned char)idx >> 5);
    p[10] = (p[10] & 7) | (idx << 5);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BECA0);
#ifdef SKIP_ASM
int func_003BECA0(int a, int b, int *o1, int *o2) {
    int w, m;
    if (b < 0) return -2;
    if (b < 0x22) w = 0xE0;
    else if (b < 0x43) w = 0x160;
    else if (b < 0x65) w = 0x1E0;
    else return -2;
    if (a == 1) m = 4;
    else if (a == 2) m = 5;
    else return -1;
    *o1 = (w * 4 + 0x3C) * m + 0xA8;
    *o2 = (w + (w + 0x200)) * 4 + 0xC00;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003BED30);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003BF0F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct C_F0F0 {
    char pad0[0xA20];
    char *pA20;
    char *pA24;
    char *pA28;
    char *pA2C;
    char *pA30;
    char *pA34;
    char *pA38;
    unsigned char flagA3C;
};
struct S_F0F0 {
    unsigned char mode;
    unsigned char n;
    char pad2[2];
    unsigned short n4;
    short h6;
    int key;
    char padC[0x84 - 0xC];
    int *ptrs[1];
};
extern struct S_F0F0 *D_0050AC68_F0F0 __asm__("D_0050AC68");
extern struct C_F0F0 *D_0050AC6C_F0F0 __asm__("D_0050AC6C");
extern char D_0044C980_F0F0[] __asm__("D_0044C980");
extern char D_0044C990_F0F0[] __asm__("D_0044C990");
extern char D_0044C9B0_F0F0[] __asm__("D_0044C9B0");
extern char D_0044C9E0_F0F0[] __asm__("D_0044C9E0");
extern char D_0044CA40_F0F0[] __asm__("D_0044CA40");
extern char D_0044CB00_F0F0[] __asm__("D_0044CB00");
extern char D_0044CF00_F0F0[] __asm__("D_0044CF00");
extern char D_0044D500_F0F0[] __asm__("D_0044D500");
extern void f_C968_F0F0(char *, char *, int, int) __asm__("func_003BC968");
extern void f_CBA0_F0F0(void) __asm__("func_003BCBA0");
extern void f_D220_F0F0(int, struct C_F0F0 *, int) __asm__("func_003BD220");
extern void func_003BD5B8(int);
extern void f_DE08_F0F0(int) __asm__("func_003BDE08");
extern void func_003BD9C0(void);
extern void f_E6E0_F0F0(int *) __asm__("func_003BE6E0");

int func_003BF0F0(int *data, int key, char *buf) {
    int i;

    if (key & 1) {
        return -3;
    }
    buf = (char *)((((int)buf - 1) | 0xF) + 1);
    D_0050AC6C_F0F0 = (struct C_F0F0 *)buf;
    D_0050AC6C_F0F0->flagA3C = ((int)buf & 0x70000000) == 0x70000000;
    if (D_0050AC6C_F0F0->flagA3C) {
        buf += 0xA40;
        D_0050AC6C_F0F0->pA24 = buf;
        if (D_0050AC68_F0F0->n4 == 0xE0) {
            f_C968_F0F0(D_0044CB00_F0F0, buf, 0x40, 0);
            buf += 0x400;
        } else if (D_0050AC68_F0F0->n4 == 0x160) {
            f_C968_F0F0(D_0044CF00_F0F0, buf, 0x60, 0);
            buf += 0x600;
        } else {
            f_C968_F0F0(D_0044D500_F0F0, buf, 0x80, 0);
            buf += 0x800;
        }
        D_0050AC6C_F0F0->pA20 = buf;
        buf += (D_0050AC68_F0F0->n4 + 0x200) * 4;
        D_0050AC6C_F0F0->pA28 = buf;
        D_0050AC6C_F0F0->pA2C = buf + 0x10;
        D_0050AC6C_F0F0->pA30 = buf + 0x30;
        D_0050AC6C_F0F0->pA34 = buf + 0x60;
        D_0050AC6C_F0F0->pA38 = buf + 0xC0;
        f_C968_F0F0(D_0044C980_F0F0, buf, 0x12, 0x10000);
    } else {
        D_0050AC6C_F0F0->pA20 = buf + 0xA40;
        if (D_0050AC68_F0F0->n4 == 0xE0) {
            D_0050AC6C_F0F0->pA24 = D_0044CB00_F0F0;
        } else if (D_0050AC68_F0F0->n4 == 0x160) {
            D_0050AC6C_F0F0->pA24 = D_0044CF00_F0F0;
        } else if (D_0050AC68_F0F0->n4 == 0x1E0) {
            D_0050AC6C_F0F0->pA24 = D_0044D500_F0F0;
        }
        D_0050AC6C_F0F0->pA28 = D_0044C980_F0F0;
        D_0050AC6C_F0F0->pA2C = D_0044C990_F0F0;
        D_0050AC6C_F0F0->pA30 = D_0044C9B0_F0F0;
        D_0050AC6C_F0F0->pA34 = D_0044C9E0_F0F0;
        D_0050AC6C_F0F0->pA38 = D_0044CA40_F0F0;
    }
    if (D_0050AC68_F0F0->key != key) {
        D_0050AC68_F0F0->key = key;
        D_0050AC68_F0F0->h6 = 0;
        f_CBA0_F0F0();
    }
    for (i = 0; i < D_0050AC68_F0F0->n; i++) {
        if (data[i] & 0xF) {
            return -3;
        }
        f_D220_F0F0(data[i], D_0050AC6C_F0F0, *D_0050AC68_F0F0->ptrs[i]);
        if (D_0050AC68_F0F0->mode == 1) {
            func_003BD5B8(i);
        } else {
            f_DE08_F0F0(i);
        }
    }
    if (D_0050AC68_F0F0->mode == 1) {
        func_003BD9C0();
    } else {
        f_E6E0_F0F0(data);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF3E0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF3E0(char *src, char *dst, unsigned bytes) {
    __asm__ volatile(
        ".set noreorder\n"
        "srl $2, $6, 5\n"
        "1:\n"
        "lqc2 $vf1, 0x0($4)\n"
        "lqc2 $vf2, 0x10($4)\n"
        "lqc2 $vf3, 0x20($4)\n"
        "lqc2 $vf4, 0x30($4)\n"
        "lqc2 $vf5, 0x40($4)\n"
        "lqc2 $vf6, 0x50($4)\n"
        "lqc2 $vf7, 0x60($4)\n"
        "lqc2 $vf8, 0x70($4)\n"
        "sqc2 $vf1, 0x0($5)\n"
        "sqc2 $vf2, 0x10($5)\n"
        "sqc2 $vf3, 0x20($5)\n"
        "sqc2 $vf4, 0x30($5)\n"
        "sqc2 $vf5, 0x40($5)\n"
        "sqc2 $vf6, 0x50($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf7, 0x60($5)\n"
        "addiu $4, $4, 0x80\n"
        "sqc2 $vf8, 0x70($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, 0x80\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF440);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF440(char *src, char *dst, unsigned bytes) {
    __asm__ volatile(
        ".set noreorder\n"
        "srl $2, $6, 4\n"
        "1:\n"
        "ld $7, 0x0($4)\n"
        "ld $8, 0x8($4)\n"
        "ld $9, 0x10($4)\n"
        "ld $10, 0x18($4)\n"
        "pextlh $7, $7, $0\n"
        "pextlh $8, $8, $0\n"
        "pextlh $9, $9, $0\n"
        "pextlh $10, $10, $0\n"
        "psraw $7, $7, 8\n"
        "psraw $8, $8, 8\n"
        "psraw $9, $9, 8\n"
        "psraw $10, $10, 8\n"
        "qmtc2.ni $7, $vf1\n"
        "qmtc2.ni $8, $vf2\n"
        "qmtc2.ni $9, $vf3\n"
        "qmtc2.ni $10, $vf4\n"
        "vitof0.xyzw $vf1, $vf1\n"
        "vitof0.xyzw $vf2, $vf2\n"
        "vitof0.xyzw $vf3, $vf3\n"
        "vitof0.xyzw $vf4, $vf4\n"
        "sqc2 $vf1, 0x0($5)\n"
        "sqc2 $vf2, 0x10($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf3, 0x20($5)\n"
        "addiu $4, $4, 0x20\n"
        "sqc2 $vf4, 0x30($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF4C0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF4C0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x0($4)\n"
        "lqc2 $vf6, 0x80($4)\n"
        "lqc2 $vf7, 0x100($4)\n"
        "lqc2 $vf8, 0x180($4)\n"
        "lqc2 $vf9, 0x200($4)\n"
        "lqc2 $vf10, 0x280($4)\n"
        "lqc2 $vf11, 0x300($4)\n"
        "lqc2 $vf12, 0x380($4)\n"
        "lqc2 $vf13, 0x400($4)\n"
        "lqc2 $vf14, 0x480($4)\n"
        "vmula.xyzw ACC, $vf1, $vf5\n"
        "vmadda.xyzw ACC, $vf2, $vf7\n"
        "vmadda.xyzw ACC, $vf3, $vf9\n"
        "vmadd.xyzw $vf5, $vf4, $vf11\n"
        "vmula.xyzw ACC, $vf1, $vf6\n"
        "vmadda.xyzw ACC, $vf2, $vf8\n"
        "vmadda.xyzw ACC, $vf3, $vf10\n"
        "vmadd.xyzw $vf6, $vf4, $vf12\n"
        "vmula.xyzw ACC, $vf1, $vf7\n"
        "vmadda.xyzw ACC, $vf2, $vf9\n"
        "vmadda.xyzw ACC, $vf3, $vf11\n"
        "vmadd.xyzw $vf7, $vf4, $vf13\n"
        "vmula.xyzw ACC, $vf1, $vf8\n"
        "vmadda.xyzw ACC, $vf2, $vf10\n"
        "vmadda.xyzw ACC, $vf3, $vf12\n"
        "vmadd.xyzw $vf8, $vf4, $vf14\n"
        "qmfc2.ni $7, $vf5\n"
        "qmfc2.ni $8, $vf6\n"
        "qmfc2.ni $9, $vf7\n"
        "qmfc2.ni $10, $vf8\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
// the retail object pads this hand-scheduled loop to 16 bytes: two nops after jr/nop
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF5A0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF5A0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x400($5)\n"
        "lqc2 $vf6, 0x500($5)\n"
        "lqc2 $vf7, 0x0($4)\n"
        "lqc2 $vf8, 0x80($4)\n"
        "lqc2 $vf9, 0x100($4)\n"
        "lqc2 $vf10, 0x180($4)\n"
        "lqc2 $vf11, 0x200($4)\n"
        "lqc2 $vf12, 0x280($4)\n"
        "lqc2 $vf13, 0x300($4)\n"
        "lqc2 $vf14, 0x380($4)\n"
        "lqc2 $vf15, 0x400($4)\n"
        "lqc2 $vf16, 0x480($4)\n"
        "lqc2 $vf17, 0x500($4)\n"
        "lqc2 $vf18, 0x580($4)\n"
        "lqc2 $vf19, 0x600($4)\n"
        "lqc2 $vf20, 0x680($4)\n"
        "vmula.xyzw ACC, $vf1, $vf7\n"
        "vmadda.xyzw ACC, $vf2, $vf9\n"
        "vmadda.xyzw ACC, $vf3, $vf11\n"
        "vmadda.xyzw ACC, $vf4, $vf13\n"
        "vmadda.xyzw ACC, $vf5, $vf15\n"
        "vmadd.xyzw $vf7, $vf6, $vf17\n"
        "vmula.xyzw ACC, $vf1, $vf8\n"
        "vmadda.xyzw ACC, $vf2, $vf10\n"
        "vmadda.xyzw ACC, $vf3, $vf12\n"
        "vmadda.xyzw ACC, $vf4, $vf14\n"
        "vmadda.xyzw ACC, $vf5, $vf16\n"
        "vmadd.xyzw $vf8, $vf6, $vf18\n"
        "vmula.xyzw ACC, $vf1, $vf9\n"
        "vmadda.xyzw ACC, $vf2, $vf11\n"
        "vmadda.xyzw ACC, $vf3, $vf13\n"
        "vmadda.xyzw ACC, $vf4, $vf15\n"
        "vmadda.xyzw ACC, $vf5, $vf17\n"
        "vmadd.xyzw $vf9, $vf6, $vf19\n"
        "vmula.xyzw ACC, $vf1, $vf10\n"
        "vmadda.xyzw ACC, $vf2, $vf12\n"
        "vmadda.xyzw ACC, $vf3, $vf14\n"
        "vmadda.xyzw ACC, $vf4, $vf16\n"
        "vmadda.xyzw ACC, $vf5, $vf18\n"
        "vmadd.xyzw $vf10, $vf6, $vf20\n"
        "qmfc2.ni $7, $vf7\n"
        "qmfc2.ni $8, $vf8\n"
        "qmfc2.ni $9, $vf9\n"
        "qmfc2.ni $10, $vf10\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF6B0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF6B0(char *a, char *b, char *out) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x10\n"
        "1:\n"
        "lqc2 $vf1, 0x0($5)\n"
        "lqc2 $vf2, 0x100($5)\n"
        "lqc2 $vf3, 0x200($5)\n"
        "lqc2 $vf4, 0x300($5)\n"
        "lqc2 $vf5, 0x400($5)\n"
        "lqc2 $vf6, 0x500($5)\n"
        "lqc2 $vf7, 0x600($5)\n"
        "lqc2 $vf8, 0x700($5)\n"
        "lqc2 $vf9, 0x0($4)\n"
        "lqc2 $vf10, 0x80($4)\n"
        "lqc2 $vf11, 0x100($4)\n"
        "lqc2 $vf12, 0x180($4)\n"
        "lqc2 $vf13, 0x200($4)\n"
        "lqc2 $vf14, 0x280($4)\n"
        "lqc2 $vf15, 0x300($4)\n"
        "lqc2 $vf16, 0x380($4)\n"
        "lqc2 $vf17, 0x400($4)\n"
        "lqc2 $vf18, 0x480($4)\n"
        "lqc2 $vf19, 0x500($4)\n"
        "lqc2 $vf20, 0x580($4)\n"
        "lqc2 $vf21, 0x600($4)\n"
        "lqc2 $vf22, 0x680($4)\n"
        "lqc2 $vf23, 0x700($4)\n"
        "lqc2 $vf24, 0x780($4)\n"
        "lqc2 $vf25, 0x800($4)\n"
        "lqc2 $vf26, 0x880($4)\n"
        "vmula.xyzw ACC, $vf1, $vf9\n"
        "vmadda.xyzw ACC, $vf2, $vf11\n"
        "vmadda.xyzw ACC, $vf3, $vf13\n"
        "vmadda.xyzw ACC, $vf4, $vf15\n"
        "vmadda.xyzw ACC, $vf5, $vf17\n"
        "vmadda.xyzw ACC, $vf6, $vf19\n"
        "vmadda.xyzw ACC, $vf7, $vf21\n"
        "vmadd.xyzw $vf9, $vf8, $vf23\n"
        "vmula.xyzw ACC, $vf1, $vf10\n"
        "vmadda.xyzw ACC, $vf2, $vf12\n"
        "vmadda.xyzw ACC, $vf3, $vf14\n"
        "vmadda.xyzw ACC, $vf4, $vf16\n"
        "vmadda.xyzw ACC, $vf5, $vf18\n"
        "vmadda.xyzw ACC, $vf6, $vf20\n"
        "vmadda.xyzw ACC, $vf7, $vf22\n"
        "vmadd.xyzw $vf10, $vf8, $vf24\n"
        "vmula.xyzw ACC, $vf1, $vf11\n"
        "vmadda.xyzw ACC, $vf2, $vf13\n"
        "vmadda.xyzw ACC, $vf3, $vf15\n"
        "vmadda.xyzw ACC, $vf4, $vf17\n"
        "vmadda.xyzw ACC, $vf5, $vf19\n"
        "vmadda.xyzw ACC, $vf6, $vf21\n"
        "vmadda.xyzw ACC, $vf7, $vf23\n"
        "vmadd.xyzw $vf11, $vf8, $vf25\n"
        "vmula.xyzw ACC, $vf1, $vf12\n"
        "vmadda.xyzw ACC, $vf2, $vf14\n"
        "vmadda.xyzw ACC, $vf3, $vf16\n"
        "vmadda.xyzw ACC, $vf4, $vf18\n"
        "vmadda.xyzw ACC, $vf5, $vf20\n"
        "vmadda.xyzw ACC, $vf6, $vf22\n"
        "vmadda.xyzw ACC, $vf7, $vf24\n"
        "vmadd.xyzw $vf12, $vf8, $vf26\n"
        "qmfc2.ni $7, $vf9\n"
        "qmfc2.ni $8, $vf10\n"
        "qmfc2.ni $9, $vf11\n"
        "qmfc2.ni $10, $vf12\n"
        "pextlw $11, $8, $7\n"
        "pextuw $8, $8, $7\n"
        "pextlw $12, $10, $9\n"
        "pextuw $10, $10, $9\n"
        "pcpyld $7, $12, $11\n"
        "pcpyud $9, $11, $12\n"
        "pcpyld $11, $10, $8\n"
        "pcpyud $12, $8, $10\n"
        "sq $7, 0x0($6)\n"
        "addiu $2, $2, -0x1\n"
        "sq $9, 0x10($6)\n"
        "addiu $4, $4, 0x10\n"
        "sq $11, 0x20($6)\n"
        "addiu $5, $5, 0x10\n"
        "sq $12, 0x30($6)\n"
        "bnez $2, 1b\n"
        "addiu $6, $6, 0x40\n"
        ".set reorder\n"
        : : : "memory");
}
// the retail object pads this hand-scheduled loop to 16 bytes: two nops after jr/nop
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF800);
#ifdef SKIP_ASM
// PORT: PS2-only VU0/MMI hand-written routine; whole body as one asm block (no C equivalent that keeps the register use).
void func_003BF800(char *p) {
    __asm__ volatile(
        ".set noreorder\n"
        "addiu $2, $0, 0x4\n"
        "addiu $5, $4, 0x1F0\n"
        "1:\n"
        "lqc2 $vf9, 0x200($4)\n"
        "lqc2 $vf10, 0x210($4)\n"
        "lqc2 $vf11, 0x220($4)\n"
        "lqc2 $vf12, 0x230($4)\n"
        "lqc2 $vf13, 0x1D0($5)\n"
        "lqc2 $vf14, 0x1E0($5)\n"
        "lqc2 $vf15, 0x1F0($5)\n"
        "lqc2 $vf16, 0x200($5)\n"
        "lqc2 $vf1, 0x0($4)\n"
        "lqc2 $vf2, 0x10($4)\n"
        "lqc2 $vf3, 0x20($4)\n"
        "lqc2 $vf4, 0x30($4)\n"
        "lqc2 $vf5, -0x30($5)\n"
        "lqc2 $vf6, -0x20($5)\n"
        "lqc2 $vf7, -0x10($5)\n"
        "lqc2 $vf8, 0x0($5)\n"
        "vadd.xyzw $vf16, $vf9, $vf16\n"
        "vadd.xyzw $vf15, $vf10, $vf15\n"
        "vadd.xyzw $vf14, $vf11, $vf14\n"
        "vadd.xyzw $vf13, $vf12, $vf13\n"
        "vsub.xyzw $vf9, $vf1, $vf8\n"
        "vsub.xyzw $vf10, $vf2, $vf7\n"
        "vsub.xyzw $vf11, $vf3, $vf6\n"
        "vsub.xyzw $vf12, $vf4, $vf5\n"
        "vsub.xyzw $vf8, $vf8, $vf1\n"
        "vsub.xyzw $vf7, $vf7, $vf2\n"
        "vsub.xyzw $vf6, $vf6, $vf3\n"
        "vsub.xyzw $vf5, $vf5, $vf4\n"
        "vsub.xyzw $vf1, $vf9, $vf16\n"
        "vsub.xyzw $vf2, $vf10, $vf15\n"
        "vsub.xyzw $vf3, $vf11, $vf14\n"
        "vsub.xyzw $vf4, $vf12, $vf13\n"
        "vsub.xyzw $vf8, $vf8, $vf16\n"
        "vsub.xyzw $vf7, $vf7, $vf15\n"
        "vsub.xyzw $vf6, $vf6, $vf14\n"
        "vsub.xyzw $vf5, $vf5, $vf13\n"
        "sqc2 $vf1, 0x0($4)\n"
        "sqc2 $vf2, 0x10($4)\n"
        "sqc2 $vf3, 0x20($4)\n"
        "sqc2 $vf4, 0x30($4)\n"
        "sqc2 $vf5, -0x30($5)\n"
        "sqc2 $vf6, -0x20($5)\n"
        "addiu $2, $2, -0x1\n"
        "sqc2 $vf7, -0x10($5)\n"
        "addiu $4, $4, 0x40\n"
        "sqc2 $vf8, 0x0($5)\n"
        "bnez $2, 1b\n"
        "addiu $5, $5, -0x40\n"
        ".set reorder\n"
        : : : "memory");
}
#endif

/* Types and VU0 helpers shared by the func_003BF8D0 .. func_003C01A0 family (EA audio engine transform
   routines). Kept in one unguarded block so that no function's block depends on another's (types and unused
   static inline helpers emit no code when the functions are built from asm). */
/* --- used by func_003BF8D0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_F8D0;

// PORT: PS2-only VU0 inline asm (clear running-sum register vf1).
static inline void vu0ClearSum(void) {
    __asm__ volatile("vsub.xyzw  $vf1, $vf0, $vf0\n");
}

// PORT: PS2-only VU0 inline asm (load eight vec4 rows into vf2..vf9).
static inline void vu0LoadRows2to9(const V4_F8D0 *p) {
    __asm__ volatile(
        "lqc2       $vf2, 0x0(%0)\n"
        "lqc2       $vf3, 0x10(%0)\n"
        "lqc2       $vf4, 0x20(%0)\n"
        "lqc2       $vf5, 0x30(%0)\n"
        "lqc2       $vf6, 0x40(%0)\n"
        "lqc2       $vf7, 0x50(%0)\n"
        "lqc2       $vf8, 0x60(%0)\n"
        "lqc2       $vf9, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf8 += vf2..vf9).
static inline void vu0AddNext1to8(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n"
        "vadd.xyzw  $vf8, $vf8, $vf9\n");
}

// PORT: PS2-only VU0 inline asm (store first six sums).
static inline void vu0StoreSums(V4_F8D0 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x0(%0)\n"
        "sqc2       $vf4, 0x10(%0)\n"
        "sqc2       $vf6, 0x20(%0)\n"
        "sqc2       $vf8, 0x30(%0)\n"
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf3, 0x110(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sum vf5).
static inline void vu0StoreSum5(V4_F8D0 *d) {
    __asm__ volatile("sqc2       $vf5, 0x120(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sum vf7, carry last row vf9 into vf1).
static inline void vu0StoreSum7Carry(V4_F8D0 *d) {
    __asm__ volatile("sqc2       $vf7, 0x130(%0)\n" "vmove.xyzw $vf1, $vf9\n" : : "r"(d) : "memory");
}

/* --- used by func_003BF960 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_F960;

// PORT: PS2-only VU0 inline asm (load sixteen consecutive vec4 rows into vf1..vf16).
static inline void vu0LoadRows16(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x40(%0)\n"
        "lqc2       $vf6, 0x50(%0)\n"
        "lqc2       $vf7, 0x60(%0)\n"
        "lqc2       $vf8, 0x70(%0)\n"
        "lqc2       $vf9, 0x80(%0)\n"
        "lqc2       $vf10, 0x90(%0)\n"
        "lqc2       $vf11, 0xA0(%0)\n"
        "lqc2       $vf12, 0xB0(%0)\n"
        "lqc2       $vf13, 0xC0(%0)\n"
        "lqc2       $vf14, 0xD0(%0)\n"
        "lqc2       $vf15, 0xE0(%0)\n"
        "lqc2       $vf16, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the first row unchanged to the middle of the output).
static inline void vu0StoreFirstRow(V4_F960 *d) {
    __asm__ volatile("sqc2       $vf1, 0x80(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf15 += vf2..vf16).
static inline void vu0AddNext1to15(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n"
        "vadd.xyzw  $vf8, $vf8, $vf9\n"
        "vadd.xyzw  $vf9, $vf9, $vf10\n"
        "vadd.xyzw  $vf10, $vf10, $vf11\n"
        "vadd.xyzw  $vf11, $vf11, $vf12\n"
        "vadd.xyzw  $vf12, $vf12, $vf13\n"
        "vadd.xyzw  $vf13, $vf13, $vf14\n"
        "vadd.xyzw  $vf14, $vf14, $vf15\n"
        "vadd.xyzw  $vf15, $vf15, $vf16\n");
}

// PORT: PS2-only VU0 inline asm (store the odd-numbered sums to the low half of the output).
static inline void vu0StoreOddSums(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf11, 0x50(%0)\n"
        "sqc2       $vf13, 0x60(%0)\n"
        "sqc2       $vf15, 0x70(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the even-numbered sums to the upper half of the output).
static inline void vu0StoreEvenSums(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x90(%0)\n"
        "sqc2       $vf4, 0xA0(%0)\n"
        "sqc2       $vf6, 0xB0(%0)\n"
        "sqc2       $vf8, 0xC0(%0)\n"
        "sqc2       $vf10, 0xD0(%0)\n"
        "sqc2       $vf12, 0xE0(%0)\n"
        "sqc2       $vf14, 0xF0(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (load every other row of the second block, vf1..vf8).
static inline void vu0LoadEvenRows(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x100(%0)\n"
        "lqc2       $vf2, 0x120(%0)\n"
        "lqc2       $vf3, 0x140(%0)\n"
        "lqc2       $vf4, 0x160(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf6, 0x1A0(%0)\n"
        "lqc2       $vf7, 0x1C0(%0)\n"
        "lqc2       $vf8, 0x1E0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (copy vf1..vf8 to eight consecutive output rows).
static inline void vu0StoreCopy8(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf2, 0x110(%0)\n"
        "sqc2       $vf3, 0x120(%0)\n"
        "sqc2       $vf4, 0x130(%0)\n"
        "sqc2       $vf5, 0x140(%0)\n"
        "sqc2       $vf6, 0x150(%0)\n"
        "sqc2       $vf7, 0x160(%0)\n"
        "sqc2       $vf8, 0x170(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (load the other interleaved rows of the second block, vf1..vf8).
static inline void vu0LoadOddRows(const V4_F960 *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x110(%0)\n"
        "lqc2       $vf2, 0x130(%0)\n"
        "lqc2       $vf3, 0x150(%0)\n"
        "lqc2       $vf4, 0x170(%0)\n"
        "lqc2       $vf5, 0x190(%0)\n"
        "lqc2       $vf6, 0x1B0(%0)\n"
        "lqc2       $vf7, 0x1D0(%0)\n"
        "lqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store the first row unchanged).
static inline void vu0StoreFirstRow2(V4_F960 *d) {
    __asm__ volatile("sqc2       $vf1, 0x180(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (add each row to its successor: vf1..vf7 += vf2..vf8).
static inline void vu0AddNext1to7(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf1, $vf1, $vf2\n"
        "vadd.xyzw  $vf2, $vf2, $vf3\n"
        "vadd.xyzw  $vf3, $vf3, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf5\n"
        "vadd.xyzw  $vf5, $vf5, $vf6\n"
        "vadd.xyzw  $vf6, $vf6, $vf7\n"
        "vadd.xyzw  $vf7, $vf7, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store sums vf1..vf7; trailing label keeps gas from filling a delay slot).
static inline void vu0StoreSums7(V4_F960 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x190(%0)\n"
        "sqc2       $vf2, 0x1A0(%0)\n"
        "sqc2       $vf3, 0x1B0(%0)\n"
        "sqc2       $vf4, 0x1C0(%0)\n"
        "sqc2       $vf5, 0x1D0(%0)\n"
        "sqc2       $vf6, 0x1E0(%0)\n"
        "sqc2       $vf7, 0x1F0(%0)\n"
        "1:\n"
        : : "r"(d) : "memory");
}

/* --- used by func_003BFAC0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FAC0;

// PORT: PS2-only VU0 inline asm (load eight vec4 rows into vf1..vf8).
static inline void vu0LoadRows1to8(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x40(%0)\n"
        "lqc2       $vf6, 0x50(%0)\n"
        "lqc2       $vf7, 0x60(%0)\n"
        "lqc2       $vf8, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store row vf1 unchanged).
static inline void vu0StoreRow1At40(V4_FAC0 *d) {
    __asm__ volatile("sqc2       $vf1, 0x40(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store sums vf1, vf3, vf5, vf7 and vf2).
static inline void vu0StoreHeadSums(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        "sqc2       $vf2, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf4 to row 6).
static inline void vu0StoreV4At60(void *d) {
    __asm__ volatile("sqc2       $vf4, 0x60(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf6 to row 7).
static inline void vu0StoreV6At70(void *d) {
    __asm__ volatile("sqc2       $vf6, 0x70(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf1, vf3, vf5, vf7 to rows 0..3).
static inline void vu0StoreOddRows(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf5, 0x20(%0)\n"
        "sqc2       $vf7, 0x30(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (pairwise sums of even rows: vf3 = vf2+vf4, vf4 = vf4+vf6, vf5 = vf6+vf8).
static inline void vu0AddEvenPairs(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf3, $vf2, $vf4\n"
        "vadd.xyzw  $vf4, $vf4, $vf6\n"
        "vadd.xyzw  $vf5, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store vf2 and vf3 to rows 4 and 5).
static inline void vu0StoreV2V3(V4_FAC0 *d) {
    __asm__ volatile(
        "sqc2       $vf2, 0x40(%0)\n"
        "sqc2       $vf3, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf5 to row 7).
static inline void vu0StoreV5At70(V4_FAC0 *d) {
    __asm__ volatile("sqc2       $vf5, 0x70(%0)\n" : : "r"(d) : "memory");
}

/* --- used by func_003BFB90 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FB90;

// PORT: PS2-only VU0 inline asm (first-block sums: vf9 = vf1+vf2, vf10 = vf3+vf4, vf11 = vf2+vf3, vf12 = vf6+vf8).
static inline void vu0AddHeadSums(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf2\n"
        "vadd.xyzw  $vf10, $vf3, $vf4\n"
        "vadd.xyzw  $vf11, $vf2, $vf3\n"
        "vadd.xyzw  $vf12, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store first-block results to rows 0..5).
static inline void vu0StoreHeadRows(V4_FB90 *d) {
    __asm__ volatile(
        "sqc2       $vf9, 0x0(%0)\n"
        "sqc2       $vf10, 0x10(%0)\n"
        "sqc2       $vf1, 0x20(%0)\n"
        "sqc2       $vf11, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf7, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf6 to row 6).
static inline void vu0StoreV6At60(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf6, 0x60(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12 to row 7).
static inline void vu0StoreV12At70(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf12, 0x70(%0)\n" : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop sums: vf9 = vf2+vf4, vf10 = vf6+vf8).
static inline void vu0AddLoopSums(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf2, $vf4\n"
        "vadd.xyzw  $vf10, $vf6, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (store loop results to rows 0..5).
static inline void vu0StoreLoopRows(V4_FB90 *d) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf3, 0x10(%0)\n"
        "sqc2       $vf2, 0x20(%0)\n"
        "sqc2       $vf9, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf7, 0x50(%0)\n"
        : : "r"(d) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf10 to row 7).
static inline void vu0StoreV10At70(V4_FB90 *d) {
    __asm__ volatile("sqc2       $vf10, 0x70(%0)\n" : : "r"(d) : "memory");
}

/* --- used by func_003BFC50 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FC50;

// PORT: PS2-only VU0 inline asm (load the twiddle vector into vf16).
static inline void vu0LoadTwiddle(const V4_FC50 *p) {
    __asm__ volatile("lqc2       $vf16, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (head: vf9 = (vf1+vf2)*w.x, vf10/vf11/vf12 = vf4/vf6/vf8 * w.x).
static inline void vu0ScaleHead(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf2\n"
        "vmulx.xyzw $vf10, $vf4, $vf16x\n"
        "vmulx.xyzw $vf11, $vf6, $vf16x\n"
        "vmulx.xyzw $vf12, $vf8, $vf16x\n"
        "vmulx.xyzw $vf9, $vf9, $vf16x\n");
}

// PORT: PS2-only VU0 inline asm (head butterfly: sub/add of rows against the scaled terms).
static inline void vu0ButterflyHead(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf4, $vf3, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf10\n"
        "vsub.xyzw  $vf6, $vf5, $vf11\n"
        "vadd.xyzw  $vf5, $vf5, $vf11\n"
        "vsub.xyzw  $vf2, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vsub.xyzw  $vf8, $vf7, $vf12\n"
        "vadd.xyzw  $vf7, $vf7, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (scale vf2 by w.y and vf1 by w.z).
static inline void vu0ScaleY2Z1(void) {
    __asm__ volatile(
        "vmuly.xyzw $vf2, $vf2, $vf16y\n"
        "vmulz.xyzw $vf1, $vf1, $vf16z\n");
}

// PORT: PS2-only VU0 inline asm (store head results in place, vf3..vf8 then vf1).
static inline void vu0StoreHeadInPlace(void *p) {
    __asm__ volatile(
        "sqc2       $vf3, 0x20(%0)\n"
        "sqc2       $vf4, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf6, 0x50(%0)\n"
        "sqc2       $vf7, 0x60(%0)\n"
        "sqc2       $vf8, 0x70(%0)\n"
        "sqc2       $vf1, 0x0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf2 to row 1).
static inline void vu0StoreV2At10(void *p) {
    __asm__ volatile("sqc2       $vf2, 0x10(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (scale even rows vf2/vf4/vf6/vf8 by w.x).
static inline void vu0ScaleEvenRows(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf2, $vf16x\n"
        "vmulx.xyzw $vf10, $vf4, $vf16x\n"
        "vmulx.xyzw $vf11, $vf6, $vf16x\n"
        "vmulx.xyzw $vf12, $vf8, $vf16x\n");
}

// PORT: PS2-only VU0 inline asm (butterfly of row pairs against the scaled terms).
static inline void vu0ButterflyPairs(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf2, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vsub.xyzw  $vf4, $vf3, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf10\n"
        "vsub.xyzw  $vf6, $vf5, $vf11\n"
        "vadd.xyzw  $vf5, $vf5, $vf11\n"
        "vsub.xyzw  $vf8, $vf7, $vf12\n"
        "vadd.xyzw  $vf7, $vf7, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly rows vf1..vf7 in place).
static inline void vu0StoreRows1to7(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x0(%0)\n"
        "sqc2       $vf2, 0x10(%0)\n"
        "sqc2       $vf3, 0x20(%0)\n"
        "sqc2       $vf4, 0x30(%0)\n"
        "sqc2       $vf5, 0x40(%0)\n"
        "sqc2       $vf6, 0x50(%0)\n"
        "sqc2       $vf7, 0x60(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf8 to row 7).
static inline void vu0StoreV8At70(void *p) {
    __asm__ volatile("sqc2       $vf8, 0x70(%0)\n" : : "r"(p) : "memory");
}

/* --- used by func_003BFD60 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FD60;

// PORT: PS2-only VU0 inline asm (load two twiddle vectors into vf15 and vf16).
static inline void vu0LoadTwiddles15and16(const V4_FD60 *p) {
    __asm__ volatile(
        "lqc2       $vf15, 0x0(%0)\n"
        "lqc2       $vf16, 0x10(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (head sums and differences of rows 1..4).
static inline void vu0AddSubRows1to4Head(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf3\n"
        "vadd.xyzw  $vf10, $vf2, $vf4\n"
        "vsub.xyzw  $vf11, $vf4, $vf2\n"
        "vsub.xyzw  $vf12, $vf3, $vf1\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf15 and vf7/vf8 by vf16.x/y).
static inline void vu0ScaleHeadLanes(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf15x\n"
        "vmuly.xyzw $vf10, $vf10, $vf15y\n"
        "vmulz.xyzw $vf11, $vf11, $vf15z\n"
        "vmulw.xyzw $vf12, $vf12, $vf15w\n"
        "vmulx.xyzw $vf7, $vf7, $vf16x\n"
        "vmuly.xyzw $vf8, $vf8, $vf16y\n");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 0..3).
static inline void vu0StoreResults4(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x0(%0)\n"
        "sqc2       $vf10, 0x10(%0)\n"
        "sqc2       $vf11, 0x20(%0)\n"
        "sqc2       $vf12, 0x30(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (sums and differences of rows 5..8).
static inline void vu0AddSubRows5to8(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf5, $vf7\n"
        "vadd.xyzw  $vf10, $vf6, $vf8\n"
        "vsub.xyzw  $vf11, $vf6, $vf8\n"
        "vsub.xyzw  $vf12, $vf5, $vf7\n");
}

// PORT: PS2-only VU0 inline asm (store vf9 and vf10 to rows 4 and 5).
static inline void vu0StoreResults5and6(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf10, 0x50(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf11 to row 6).
static inline void vu0StoreV11At60(void *p) {
    __asm__ volatile("sqc2       $vf11, 0x60(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12 to row 7).
static inline void vu0StoreV12At70Of(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x70(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop: scale rows 3, 4, 7, 8 by vf16.x/y).
static inline void vu0ScaleLoopRows(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf3, $vf3, $vf16x\n"
        "vmuly.xyzw $vf4, $vf4, $vf16y\n"
        "vmulx.xyzw $vf7, $vf7, $vf16x\n"
        "vmuly.xyzw $vf8, $vf8, $vf16y\n");
}

// PORT: PS2-only VU0 inline asm (loop sums and differences of rows 1..4).
static inline void vu0AddSubRows1to4Loop(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf3\n"
        "vadd.xyzw  $vf10, $vf2, $vf4\n"
        "vsub.xyzw  $vf11, $vf2, $vf4\n"
        "vsub.xyzw  $vf12, $vf1, $vf3\n");
}

/* --- used by func_003BFE80 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_FE80;

// PORT: PS2-only VU0 inline asm (add the upper four rows to the lower four: vf9..vf12 = vf1..vf4 + vf5..vf8).
static inline void vu0AddRowHalves(void) {
    __asm__ volatile(
        "vadd.xyzw  $vf9, $vf1, $vf5\n"
        "vadd.xyzw  $vf10, $vf2, $vf6\n"
        "vadd.xyzw  $vf11, $vf3, $vf7\n"
        "vadd.xyzw  $vf12, $vf4, $vf8\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf15).
static inline void vu0ScaleResultsBy15(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf15x\n"
        "vmuly.xyzw $vf10, $vf10, $vf15y\n"
        "vmulz.xyzw $vf11, $vf11, $vf15z\n"
        "vmulw.xyzw $vf12, $vf12, $vf15w\n");
}

// PORT: PS2-only VU0 inline asm (subtract lower four rows from the upper four, reversed order).
static inline void vu0SubRowHalvesRev(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf9, $vf8, $vf4\n"
        "vsub.xyzw  $vf10, $vf7, $vf3\n"
        "vsub.xyzw  $vf11, $vf6, $vf2\n"
        "vsub.xyzw  $vf12, $vf5, $vf1\n");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf16).
static inline void vu0ScaleResultsBy16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf16x\n"
        "vmuly.xyzw $vf10, $vf10, $vf16y\n"
        "vmulz.xyzw $vf11, $vf11, $vf16z\n"
        "vmulw.xyzw $vf12, $vf12, $vf16w\n");
}

// PORT: PS2-only VU0 inline asm (load the third twiddle vector into vf16).
static inline void vu0LoadTwiddle16At20(const V4_FE80 *p) {
    __asm__ volatile("lqc2       $vf16, 0x20(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (loop: scale rows 5..8 per lane by vf16).
static inline void vu0ScaleRows5to8By16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf5, $vf5, $vf16x\n"
        "vmuly.xyzw $vf6, $vf6, $vf16y\n"
        "vmulz.xyzw $vf7, $vf7, $vf16z\n"
        "vmulw.xyzw $vf8, $vf8, $vf16w\n");
}

// PORT: PS2-only VU0 inline asm (loop: subtract scaled upper rows from lower rows).
static inline void vu0SubRowHalves(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf9, $vf4, $vf8\n"
        "vsub.xyzw  $vf10, $vf3, $vf7\n"
        "vsub.xyzw  $vf11, $vf2, $vf6\n"
        "vsub.xyzw  $vf12, $vf1, $vf5\n");
}

/* --- used by func_003BFFA0 and later family members --- */
// PORT: PS2-only VU0 inline asm (load scale vectors 0 and 3 into vf15 and vf16).
static inline void vu0LoadScale0and3(const void *s) {
    __asm__ volatile(
        "lqc2       $vf15, 0x0(%0)\n"
        "lqc2       $vf16, 0x30(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 0..3 into vf1..vf4 and rows 8..11 into vf5..vf8).
static inline void vu0LoadRowsLo0Hi8(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x80(%0)\n"
        "lqc2       $vf6, 0x90(%0)\n"
        "lqc2       $vf7, 0xA0(%0)\n"
        "lqc2       $vf8, 0xB0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 12..15).
static inline void vu0StoreResultsC0(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0xC0(%0)\n"
        "sqc2       $vf10, 0xD0(%0)\n"
        "sqc2       $vf11, 0xE0(%0)\n"
        "sqc2       $vf12, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load scale vectors 1 and 2 into vf15 and vf16).
static inline void vu0LoadScale1and2(const void *s) {
    __asm__ volatile(
        "lqc2       $vf15, 0x10(%0)\n"
        "lqc2       $vf16, 0x20(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 4..7 into vf1..vf4 and rows 12..15 into vf5..vf8).
static inline void vu0LoadRowsLo4Hi12(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        "lqc2       $vf3, 0x60(%0)\n"
        "lqc2       $vf4, 0x70(%0)\n"
        "lqc2       $vf5, 0xC0(%0)\n"
        "lqc2       $vf6, 0xD0(%0)\n"
        "lqc2       $vf7, 0xE0(%0)\n"
        "lqc2       $vf8, 0xF0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 4..7).
static inline void vu0StoreResults40(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x40(%0)\n"
        "sqc2       $vf10, 0x50(%0)\n"
        "sqc2       $vf11, 0x60(%0)\n"
        "sqc2       $vf12, 0x70(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9..vf12 to rows 8..11).
static inline void vu0StoreResults80(void *p) {
    __asm__ volatile(
        "sqc2       $vf9, 0x80(%0)\n"
        "sqc2       $vf10, 0x90(%0)\n"
        "sqc2       $vf11, 0xA0(%0)\n"
        "sqc2       $vf12, 0xB0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load scale vectors 4 and 5 into vf1 and vf2).
static inline void vu0LoadScale4and5(const void *s) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        : : "r"(s) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 24..31 into vf9..vf16).
static inline void vu0LoadRows24to31(const void *p) {
    __asm__ volatile(
        "lqc2       $vf9, 0x180(%0)\n"
        "lqc2       $vf10, 0x190(%0)\n"
        "lqc2       $vf11, 0x1A0(%0)\n"
        "lqc2       $vf12, 0x1B0(%0)\n"
        "lqc2       $vf13, 0x1C0(%0)\n"
        "lqc2       $vf14, 0x1D0(%0)\n"
        "lqc2       $vf15, 0x1E0(%0)\n"
        "lqc2       $vf16, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (scale vf9..vf12 per lane by vf1, vf13..vf16 per lane by vf2).
static inline void vu0ScaleRows9to16(void) {
    __asm__ volatile(
        "vmulx.xyzw $vf9, $vf9, $vf1x\n"
        "vmuly.xyzw $vf10, $vf10, $vf1y\n"
        "vmulz.xyzw $vf11, $vf11, $vf1z\n"
        "vmulw.xyzw $vf12, $vf12, $vf1w\n"
        "vmulx.xyzw $vf13, $vf13, $vf2x\n"
        "vmuly.xyzw $vf14, $vf14, $vf2y\n"
        "vmulz.xyzw $vf15, $vf15, $vf2z\n"
        "vmulw.xyzw $vf16, $vf16, $vf2w\n");
}

// PORT: PS2-only VU0 inline asm (load rows 19..16 reversed into vf4..vf1).
static inline void vu0LoadRowsRev100(const void *p) {
    __asm__ volatile(
        "lqc2       $vf4, 0x130(%0)\n"
        "lqc2       $vf3, 0x120(%0)\n"
        "lqc2       $vf2, 0x110(%0)\n"
        "lqc2       $vf1, 0x100(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (butterfly of vf1..vf4 against vf9..vf12: vf5..vf8 = diff, vf1..vf4 = sum).
static inline void vu0Butterfly1to4With9to12(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf5, $vf4, $vf12\n"
        "vsub.xyzw  $vf6, $vf3, $vf11\n"
        "vsub.xyzw  $vf7, $vf2, $vf10\n"
        "vsub.xyzw  $vf8, $vf1, $vf9\n"
        "vadd.xyzw  $vf1, $vf1, $vf9\n"
        "vadd.xyzw  $vf2, $vf2, $vf10\n"
        "vadd.xyzw  $vf3, $vf3, $vf11\n"
        "vadd.xyzw  $vf4, $vf4, $vf12\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly sums to rows 16..19 and differences to rows 28..31).
static inline void vu0StoreButterfly100(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x100(%0)\n"
        "sqc2       $vf2, 0x110(%0)\n"
        "sqc2       $vf3, 0x120(%0)\n"
        "sqc2       $vf4, 0x130(%0)\n"
        "sqc2       $vf5, 0x1C0(%0)\n"
        "sqc2       $vf6, 0x1D0(%0)\n"
        "sqc2       $vf7, 0x1E0(%0)\n"
        "sqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 23..20 reversed into vf4..vf1).
static inline void vu0LoadRowsRev140(const void *p) {
    __asm__ volatile(
        "lqc2       $vf4, 0x170(%0)\n"
        "lqc2       $vf3, 0x160(%0)\n"
        "lqc2       $vf2, 0x150(%0)\n"
        "lqc2       $vf1, 0x140(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (butterfly of vf1..vf4 against vf13..vf16: vf5..vf8 = diff, vf1..vf4 = sum).
static inline void vu0Butterfly1to4With13to16(void) {
    __asm__ volatile(
        "vsub.xyzw  $vf5, $vf4, $vf16\n"
        "vsub.xyzw  $vf6, $vf3, $vf15\n"
        "vsub.xyzw  $vf7, $vf2, $vf14\n"
        "vsub.xyzw  $vf8, $vf1, $vf13\n"
        "vadd.xyzw  $vf1, $vf1, $vf13\n"
        "vadd.xyzw  $vf2, $vf2, $vf14\n"
        "vadd.xyzw  $vf3, $vf3, $vf15\n"
        "vadd.xyzw  $vf4, $vf4, $vf16\n");
}

// PORT: PS2-only VU0 inline asm (store butterfly sums to rows 20..23 and differences to rows 24..27; trailing label keeps gas from filling the return delay slot).
static inline void vu0StoreButterfly140(void *p) {
    __asm__ volatile(
        "sqc2       $vf1, 0x140(%0)\n"
        "sqc2       $vf2, 0x150(%0)\n"
        "sqc2       $vf3, 0x160(%0)\n"
        "sqc2       $vf4, 0x170(%0)\n"
        "sqc2       $vf5, 0x180(%0)\n"
        "sqc2       $vf6, 0x190(%0)\n"
        "sqc2       $vf7, 0x1A0(%0)\n"
        "sqc2       $vf8, 0x1B0(%0)\n"
        "1:\n"
        : : "r"(p) : "memory");
}

/* --- used by func_003C01A0 and later family members --- */
typedef struct { int w[4]; } __attribute__((aligned(16))) V4_01A0;

// PORT: PS2-only VU0 inline asm (load one scale vector into vf16).
static inline void vu0LoadScaleVec16(const V4_01A0 *v) {
    __asm__ volatile("lqc2       $vf16, %0\n" : : "m"(*v));
}

// PORT: PS2-only VU0 inline asm (load rows 0..3 into vf1..vf4 and rows 16..19 into vf5..vf8).
static inline void vu0LoadRowsG0(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x0(%0)\n"
        "lqc2       $vf2, 0x10(%0)\n"
        "lqc2       $vf3, 0x20(%0)\n"
        "lqc2       $vf4, 0x30(%0)\n"
        "lqc2       $vf5, 0x100(%0)\n"
        "lqc2       $vf6, 0x110(%0)\n"
        "lqc2       $vf7, 0x120(%0)\n"
        "lqc2       $vf8, 0x130(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 4..7 into vf1..vf4 and rows 20..23 into vf5..vf8).
static inline void vu0LoadRowsG1(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x40(%0)\n"
        "lqc2       $vf2, 0x50(%0)\n"
        "lqc2       $vf3, 0x60(%0)\n"
        "lqc2       $vf4, 0x70(%0)\n"
        "lqc2       $vf5, 0x140(%0)\n"
        "lqc2       $vf6, 0x150(%0)\n"
        "lqc2       $vf7, 0x160(%0)\n"
        "lqc2       $vf8, 0x170(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 8..11 into vf1..vf4 and rows 24..27 into vf5..vf8).
static inline void vu0LoadRowsG2(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0x80(%0)\n"
        "lqc2       $vf2, 0x90(%0)\n"
        "lqc2       $vf3, 0xA0(%0)\n"
        "lqc2       $vf4, 0xB0(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf6, 0x190(%0)\n"
        "lqc2       $vf7, 0x1A0(%0)\n"
        "lqc2       $vf8, 0x1B0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 12..15 into vf1..vf4 and rows 28..31 into vf5..vf8).
static inline void vu0LoadRowsG3(const void *p) {
    __asm__ volatile(
        "lqc2       $vf1, 0xC0(%0)\n"
        "lqc2       $vf2, 0xD0(%0)\n"
        "lqc2       $vf3, 0xE0(%0)\n"
        "lqc2       $vf4, 0xF0(%0)\n"
        "lqc2       $vf5, 0x1C0(%0)\n"
        "lqc2       $vf6, 0x1D0(%0)\n"
        "lqc2       $vf7, 0x1E0(%0)\n"
        "lqc2       $vf8, 0x1F0(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (load rows 27..24 and 11..8 reversed into vf8..vf1).
static inline void vu0LoadRowsRevG2(const void *p) {
    __asm__ volatile(
        "lqc2       $vf8, 0x1B0(%0)\n"
        "lqc2       $vf7, 0x1A0(%0)\n"
        "lqc2       $vf6, 0x190(%0)\n"
        "lqc2       $vf5, 0x180(%0)\n"
        "lqc2       $vf4, 0xB0(%0)\n"
        "lqc2       $vf3, 0xA0(%0)\n"
        "lqc2       $vf2, 0x90(%0)\n"
        "lqc2       $vf1, 0x80(%0)\n"
        : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf9).
static inline void vu0StoreVf9(void *p) {
    __asm__ volatile("sqc2       $vf9, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf10).
static inline void vu0StoreVf10(void *p) {
    __asm__ volatile("sqc2       $vf10, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf11).
static inline void vu0StoreVf11(void *p) {
    __asm__ volatile("sqc2       $vf11, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (store vf12).
static inline void vu0StoreVf12(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x0(%0)\n" : : "r"(p) : "memory");
}

// PORT: PS2-only VU0 inline asm (final store of vf12; trailing label keeps gas from filling the return delay slot).
static inline void vu0StoreVf12Last(void *p) {
    __asm__ volatile("sqc2       $vf12, 0x0(%0)\n" "1:\n" : : "r"(p) : "memory");
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF8D0);
#ifdef SKIP_ASM
void func_003BF8D0(V4_F8D0 *src, V4_F8D0 *dst) {
    int i = 4;
    vu0ClearSum();
    do {
        vu0LoadRows2to9(src);
        vu0AddNext1to8();
        vu0StoreSums(dst);
        i--;
        vu0StoreSum5(dst);
        src += 8;
        vu0StoreSum7Carry(dst);
        dst += 4;
    } while (i != 0);
}
/* retail: two padding nops end this function's slot (the next VU0 routine starts after them) */
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BF960);
#ifdef SKIP_ASM
void func_003BF960(V4_F960 *src, V4_F960 *dst) {
    vu0LoadRows16(src);
    vu0StoreFirstRow(dst);
    vu0AddNext1to15();
    vu0StoreOddSums(dst);
    vu0StoreEvenSums(dst);
    vu0LoadEvenRows(src);
    vu0StoreCopy8(dst);
    vu0LoadOddRows(src);
    vu0StoreFirstRow2(dst);
    vu0AddNext1to7();
    vu0StoreSums7(dst);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFAC0);
#ifdef SKIP_ASM
void func_003BFAC0(V4_FAC0 *src, V4_FAC0 *dst) {
    int i;
    vu0LoadRows1to8(src);
    vu0StoreRow1At40(dst);
    vu0AddNext1to7();
    vu0StoreHeadSums(dst);
    i = 3;
    vu0StoreV4At60(dst);
    src += 8;
    vu0StoreV6At70(dst);
    dst += 8;
    do {
        vu0LoadRows1to8(src);
        vu0StoreOddRows(dst);
        vu0AddEvenPairs();
        vu0StoreV2V3(dst);
        i--;
        vu0StoreV4At60(dst);
        src += 8;
        vu0StoreV5At70(dst);
        dst += 8;
    } while (i != 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFB90);
#ifdef SKIP_ASM
void func_003BFB90(V4_FB90 *src, V4_FB90 *dst) {
    int i;
    vu0LoadRows1to8(src);
    vu0AddHeadSums();
    vu0StoreHeadRows(dst);
    i = 3;
    vu0StoreV6At60(dst);
    src += 8;
    vu0StoreV12At70(dst);
    dst += 8;
top:
    vu0LoadRows1to8(src);
    vu0AddLoopSums();
    vu0StoreLoopRows(dst);
    i--;
    vu0StoreV6At60(dst);
    src += 8;
    vu0StoreV10At70(dst);
    dst += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFC50);
#ifdef SKIP_ASM
void func_003BFC50(V4_FC50 *src, V4_FC50 *dst) {
    int i;
    vu0LoadTwiddle(dst);
    vu0LoadRows1to8(src);
    vu0ScaleHead();
    vu0ButterflyHead();
    vu0ScaleY2Z1();
    vu0StoreHeadInPlace(src);
    i = 3;
    vu0StoreV2At10(src);
    src += 8;
top:
    vu0LoadRows1to8(src);
    vu0ScaleEvenRows();
    vu0ButterflyPairs();
    vu0StoreRows1to7(src);
    i--;
    vu0StoreV8At70(src);
    src += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFD60);
#ifdef SKIP_ASM
void func_003BFD60(V4_FD60 *src, V4_FD60 *dst, V4_FD60 *p6) {
    int i;
    vu0LoadTwiddles15and16(dst);
    vu0LoadRows1to8(src);
    vu0AddSubRows1to4Head();
    vu0ScaleHeadLanes();
    vu0StoreResults4(p6);
    vu0AddSubRows5to8();
    vu0StoreResults5and6(p6);
    i = 3;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
top:
    vu0LoadRows1to8(src);
    vu0ScaleLoopRows();
    vu0AddSubRows1to4Loop();
    vu0StoreResults4(p6);
    vu0AddSubRows5to8();
    vu0StoreResults5and6(p6);
    i--;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    if (i != 0) goto top;
}
/* retail: two padding nops end this function's slot (the next VU0 routine starts after them) */
__asm__("nop\n\tnop");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFE80);
#ifdef SKIP_ASM
void func_003BFE80(V4_FE80 *src, V4_FE80 *dst, V4_FE80 *p6) {
    int i;
    vu0LoadTwiddles15and16(dst);
    vu0LoadRows1to8(src);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults4(p6);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResults5and6(p6);
    i = 3;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    vu0LoadTwiddle16At20(dst);
top:
    vu0LoadRows1to8(src);
    vu0ScaleRows5to8By16();
    vu0AddRowHalves();
    vu0StoreResults4(p6);
    vu0SubRowHalves();
    vu0StoreResults5and6(p6);
    i--;
    vu0StoreV11At60(p6);
    src += 8;
    vu0StoreV12At70Of(p6);
    p6 += 8;
    if (i != 0) goto top;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003BFFA0);
#ifdef SKIP_ASM
void func_003BFFA0(void *in, void *scale, void *out) {
    vu0LoadScale0and3(scale);
    vu0LoadRowsLo0Hi8(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults4(out);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResultsC0(out);
    vu0LoadScale1and2(scale);
    vu0LoadRowsLo4Hi12(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy15();
    vu0StoreResults40(out);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreResults80(out);
    vu0LoadScale4and5(scale);
    vu0LoadRows24to31(in);
    vu0ScaleRows9to16();
    vu0LoadRowsRev100(in);
    vu0Butterfly1to4With9to12();
    vu0StoreButterfly100(out);
    vu0LoadRowsRev140(in);
    vu0Butterfly1to4With13to16();
    vu0StoreButterfly140(out);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C01A0);
#ifdef SKIP_ASM
void func_003C01A0(void *in, void *scale, void *out, int stride) {
    const V4_01A0 *s = (const V4_01A0 *)scale;
    vu0LoadScaleVec16(&s[0]);
    vu0LoadRowsG0(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[1]);
    vu0LoadRowsG1(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[2]);
    vu0LoadRowsG2(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[3]);
    vu0LoadRowsG3(in);
    vu0AddRowHalves();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[4]);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12(out);
    out = (char *)out + stride;
    vu0LoadScaleVec16(&s[5]);
    vu0LoadRowsRevG2(in);
    vu0SubRowHalvesRev();
    vu0ScaleResultsBy16();
    vu0StoreVf9(out);
    out = (char *)out + stride;
    vu0StoreVf10(out);
    out = (char *)out + stride;
    vu0StoreVf11(out);
    out = (char *)out + stride;
    vu0StoreVf12Last(out);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C03E0);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written MMI routine (pnor/psrlw mask, 16 lq per pass, pand/pmaxw/pextlw/pcpyld/pcpyud, no gcc frame): max of masked absolute values over 256-byte blocks; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003C03E0\n.type func_003C03E0, @function\nfunc_003C03E0:\n"
    "pnor $14, $0, $0\n"
    "psrlw $14, $14, 1\n"
    "addiu $2, $0, 0x6\n"
    ".L003C03EC:\n"
    "lq $6, 0x0($4)\n"
    "lq $7, 0x40($4)\n"
    "lq $8, 0x80($4)\n"
    "lq $9, 0xC0($4)\n"
    "pand $6, $6, $14\n"
    "pand $7, $7, $14\n"
    "pand $8, $8, $14\n"
    "pand $9, $9, $14\n"
    "lq $10, 0x10($4)\n"
    "lq $11, 0x50($4)\n"
    "lq $12, 0x90($4)\n"
    "lq $13, 0xD0($4)\n"
    "pand $10, $10, $14\n"
    "pand $11, $11, $14\n"
    "pand $12, $12, $14\n"
    "pand $13, $13, $14\n"
    "pmaxw $6, $6, $10\n"
    "pmaxw $7, $7, $11\n"
    "pmaxw $8, $8, $12\n"
    "pmaxw $9, $9, $13\n"
    "lq $10, 0x20($4)\n"
    "lq $11, 0x60($4)\n"
    "lq $12, 0xA0($4)\n"
    "lq $13, 0xE0($4)\n"
    "pand $10, $10, $14\n"
    "pand $11, $11, $14\n"
    "pand $12, $12, $14\n"
    "pand $13, $13, $14\n"
    "pmaxw $6, $6, $10\n"
    "pmaxw $7, $7, $11\n"
    "pmaxw $8, $8, $12\n"
    "pmaxw $9, $9, $13\n"
    "lq $10, 0x30($4)\n"
    "lq $11, 0x70($4)\n"
    "lq $12, 0xB0($4)\n"
    "lq $13, 0xF0($4)\n"
    "pand $10, $10, $14\n"
    "pand $11, $11, $14\n"
    "pand $12, $12, $14\n"
    "pand $13, $13, $14\n"
    "pmaxw $6, $6, $10\n"
    "pmaxw $7, $7, $11\n"
    "pmaxw $8, $8, $12\n"
    "pmaxw $9, $9, $13\n"
    "pextlw $10, $7, $6\n"
    "pextuw $7, $7, $6\n"
    "pextlw $11, $9, $8\n"
    "pextuw $9, $9, $8\n"
    "pcpyld $6, $11, $10\n"
    "pcpyud $8, $10, $11\n"
    "pcpyld $10, $9, $7\n"
    "pcpyud $11, $7, $9\n"
    "pmaxw $6, $6, $8\n"
    "pmaxw $10, $10, $11\n"
    "addiu $2, $2, -0x1\n"
    "pmaxw $6, $6, $10\n"
    "addiu $4, $4, 0x100\n"
    "sq $6, 0x0($5)\n"
    "bnez $2, .L003C03EC\n"
    "addiu $5, $5, 0x10\n"
    "jr $31\n"
    "nop\n"
    ".size func_003C03E0, . - func_003C03E0\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C04F0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed halfwords).
void func_003C04F0(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0xFFF\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "pand      $6, $6, $10\n"
        "pand      $8, $8, $10\n"
        "sq        $6, 0x0(%1)\n"
        "sq        $8, 0x10(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0564);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed halfwords).
void func_003C0564(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0x3FF\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "pand      $6, $6, $10\n"
        "pand      $8, $8, $10\n"
        "sq        $6, 0x0(%1)\n"
        "sq        $8, 0x10(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C05E0);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed bytes).
void func_003C05E0(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "ppacb     $6, $8, $6\n"
        "sq        $6, 0x0(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0640);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (scale 4x4 float matrix, convert to packed bytes).
void func_003C0640(void *in, void *out, float s) {
    __asm__ volatile(
        "mfc1      $6, %2\n"
        "qmtc2.ni  $6, $vf5\n"
        "lqc2      $vf1, 0x0(%0)\n"
        "addiu     $10, $0, 0x1F1F\n"
        "lqc2      $vf2, 0x10(%0)\n"
        "pcpyh     $10, $10\n"
        "lqc2      $vf3, 0x20(%0)\n"
        "pcpyld    $10, $10, $10\n"
        "lqc2      $vf4, 0x30(%0)\n"
        "vmulx.xyzw $vf1, $vf1, $vf5x\n"
        "vmulx.xyzw $vf2, $vf2, $vf5x\n"
        "vmulx.xyzw $vf3, $vf3, $vf5x\n"
        "vmulx.xyzw $vf4, $vf4, $vf5x\n"
        "vftoi0.xyzw $vf1, $vf1\n"
        "vftoi0.xyzw $vf2, $vf2\n"
        "vftoi0.xyzw $vf3, $vf3\n"
        "vftoi0.xyzw $vf4, $vf4\n"
        "qmfc2.ni  $6, $vf1\n"
        "qmfc2.ni  $7, $vf2\n"
        "qmfc2.ni  $8, $vf3\n"
        "qmfc2.ni  $9, $vf4\n"
        "ppach     $6, $7, $6\n"
        "ppach     $8, $9, $8\n"
        "ppacb     $6, $8, $6\n"
        "pand      $6, $6, $10\n"
        "sq        $6, 0x0(%1)\n"
        :
        : "r"(in), "r"(out), "f"(s)
        : "$6", "$7", "$8", "$9", "$10", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C06B0);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written FPU filter (mula.s/madda.s accumulator ops no compiler emits); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
void func_003C06B0(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "addi $8, $5, 0x20\n"
        "mtc1 $0, $f0\n"
        "lwc1 $f1, 0x0($7)\n"
        "lwc1 $f2, 0x4($7)\n"
        "lwc1 $f3, 0x8($7)\n"
        "lwc1 $f4, 0xC($7)\n"
        "lwc1 $f5, 0x10($7)\n"
        "lwc1 $f6, 0x14($7)\n"
        "lwc1 $f7, 0x18($7)\n"
        "lwc1 $f8, 0x1C($7)\n"
        "lwc1 $f9, 0x20($7)\n"
        "lwc1 $f10, 0x24($7)\n"
        "lwc1 $f11, 0x28($7)\n"
        "lwc1 $f12, 0x2C($7)\n"
        "lwc1 $f13, 0x30($7)\n"
        "lwc1 $f20, 0x0($6)\n"
        "lwc1 $f21, 0x4($6)\n"
        "lwc1 $f22, 0x8($6)\n"
        "lwc1 $f23, 0xC($6)\n"
        "lwc1 $f24, 0x10($6)\n"
        "lwc1 $f25, 0x14($6)\n"
        "1:\n"
        "addi $9, $4, 0x80\n"
        "2:\n"
        "lh $12, 0x0($4)\n"
        "mtc1 $12, $f31\n"
        "cvt.s.w $f31, $f31\n"
        "mula.s $f1, $f31\n"
        "madda.s $f20, $f2\n"
        "madda.s $f21, $f3\n"
        "addi $4, $4, 0x2\n"
        "madd.s $f31, $f0, $f0\n"
        "madda.s $f20, $f4\n"
        "madda.s $f21, $f5\n"
        "mov.s $f20, $f21\n"
        "mov.s $f21, $f31\n"
        "madda.s $f22, $f6\n"
        "madda.s $f23, $f7\n"
        "madd.s $f31, $f0, $f0\n"
        "madda.s $f22, $f8\n"
        "madda.s $f23, $f9\n"
        "mov.s $f22, $f23\n"
        "mov.s $f23, $f31\n"
        "madda.s $f24, $f10\n"
        "madda.s $f25, $f11\n"
        "madd.s $f31, $f0, $f0\n"
        "madda.s $f24, $f12\n"
        "madda.s $f25, $f13\n"
        "mov.s $f24, $f25\n"
        "bne $9, $4, 2b\n"
        "mov.s $f25, $f31\n"
        "addi $5, $5, 0x4\n"
        "madd.s $f31, $f0, $f0\n"
        "bne $8, $5, 1b\n"
        "swc1 $f31, -0x4($5)\n"
        "swc1 $f20, 0x0($6)\n"
        "swc1 $f21, 0x4($6)\n"
        "swc1 $f22, 0x8($6)\n"
        "swc1 $f23, 0xC($6)\n"
        "swc1 $f24, 0x10($6)\n"
        "swc1 $f25, 0x14($6)\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C07A8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 FPU-flag probe: builds two float4s from flag bits and multiplies them on VU0.
void func_003C07A8(int flags)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    int i;
    for (i = 0; i < 4; i++) {
        float f;
        if ((flags & 0x8800) == 0) {
            f = 0.0f;
            if (!(flags & 8))
                f = 1.0f;
        } else {
            f = 1.0000000031710769e-30f;
            if (!(flags & 8))
                f = 1.0000000150474662e+30f;
        }
        a[i] = f;
        if (flags & 0x80)
            f = -f;
        b[i] = f;
        flags <<= 1;
    }
    __asm__ __volatile__(
        "qmfc2.ni   $8, $vf1\n"
        "qmfc2.ni   $9, $vf2\n"
        "lqc2       $vf1, %0\n"
        "lqc2       $vf2, %1\n"
        "vmul.xyzw  $vf1, $vf1, $vf2\n"
        "qmtc2.ni   $8, $vf1\n"
        "qmtc2.ni   $9, $vf2\n"
        "vnop\n"
        :
        : "m"(a[0]), "m"(b[0])
        : "$8", "$9");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0858);
#ifdef SKIP_ASM
/* PORT: PS2-only VU0 state save; func_0031A308 without the $vi22/$vi18
   saves, and with ctc2 (not cfc2) on $vi16 as in the shipped code. */
void func_003C0858(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "cfc2.i     $9, $vi17\n"
        "sqc2       $vf1, 0x0($8)\n"
        "sqc2       $vf2, 0x10($8)\n"
        "sw         $9, 0x200($8)\n"
        "sqc2       $vf3, 0x20($8)\n"
        "sqc2       $vf4, 0x30($8)\n"
        "ctc2.ni    $9, $vi16\n"
        "sqc2       $vf5, 0x40($8)\n"
        "sqc2       $vf6, 0x50($8)\n"
        "sw         $9, 0x204($8)\n"
        "sqc2       $vf7, 0x60($8)\n"
        "sqc2       $vf8, 0x70($8)\n"
        "vmaddx.xyzw $vf1, $vf0, $vf0x\n"
        "sqc2       $vf9, 0x80($8)\n"
        "sqc2       $vf10, 0x90($8)\n"
        "sqc2       $vf11, 0xA0($8)\n"
        "sqc2       $vf12, 0xB0($8)\n"
        "sqc2       $vf13, 0xC0($8)\n"
        "sqc2       $vf14, 0xD0($8)\n"
        "sqc2       $vf15, 0xE0($8)\n"
        "sqc2       $vf16, 0xF0($8)\n"
        "sqc2       $vf17, 0x100($8)\n"
        "sqc2       $vf18, 0x110($8)\n"
        "sqc2       $vf19, 0x120($8)\n"
        "sqc2       $vf20, 0x130($8)\n"
        "sqc2       $vf21, 0x140($8)\n"
        "sqc2       $vf22, 0x150($8)\n"
        "sqc2       $vf23, 0x160($8)\n"
        "sqc2       $vf24, 0x170($8)\n"
        "sqc2       $vf25, 0x180($8)\n"
        "sqc2       $vf26, 0x190($8)\n"
        "sqc2       $vf27, 0x1A0($8)\n"
        "sqc2       $vf28, 0x1B0($8)\n"
        "sqc2       $vf29, 0x1C0($8)\n"
        "sqc2       $vf30, 0x1D0($8)\n"
        "sqc2       $vf31, 0x1E0($8)\n"
        "sqc2       $vf1, 0x1F0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C08F8);
#ifdef SKIP_ASM
void func_003C07A8(int status);

/* PORT: PS2-only VU0 state restore; same as func_0031A3C0 without the
   $vi22/$vi18 restore. */
void func_003C08F8(void* buf)
{
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lqc2       $vf1, 0x1F0($8)\n"
        "vaddax.xyzw ACC, $vf1, $vf0x\n"
        "lqc2       $vf1, 0x0($8)\n"
        "lqc2       $vf2, 0x10($8)\n"
        "lqc2       $vf3, 0x20($8)\n"
        "lqc2       $vf4, 0x30($8)\n"
        "lqc2       $vf5, 0x40($8)\n"
        "lqc2       $vf6, 0x50($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
    func_003C07A8(*(int*)((char*)buf + 0x200));
    __asm__ __volatile__(
        ".set push\n"
        ".set noreorder\n"
        "daddu      $8, %0, $0\n"
        "lqc2       $vf7, 0x60($8)\n"
        "lqc2       $vf8, 0x70($8)\n"
        "lqc2       $vf9, 0x80($8)\n"
        "lqc2       $vf10, 0x90($8)\n"
        "lqc2       $vf11, 0xA0($8)\n"
        "lqc2       $vf12, 0xB0($8)\n"
        "lw         $9, 0x204($8)\n"
        "lqc2       $vf13, 0xC0($8)\n"
        "lqc2       $vf14, 0xD0($8)\n"
        "ctc2.ni    $9, $vi16\n"
        "lqc2       $vf15, 0xE0($8)\n"
        "lqc2       $vf16, 0xF0($8)\n"
        "lqc2       $vf17, 0x100($8)\n"
        "lqc2       $vf18, 0x110($8)\n"
        "lqc2       $vf19, 0x120($8)\n"
        "lqc2       $vf20, 0x130($8)\n"
        "lqc2       $vf21, 0x140($8)\n"
        "lqc2       $vf22, 0x150($8)\n"
        "lqc2       $vf23, 0x160($8)\n"
        "lqc2       $vf24, 0x170($8)\n"
        "lqc2       $vf25, 0x180($8)\n"
        "lqc2       $vf26, 0x190($8)\n"
        "lqc2       $vf27, 0x1A0($8)\n"
        "lqc2       $vf28, 0x1B0($8)\n"
        "lqc2       $vf29, 0x1C0($8)\n"
        "lqc2       $vf30, 0x1D0($8)\n"
        "lqc2       $vf31, 0x1E0($8)\n"
        ".set pop\n"
        :
        : "r"(buf)
        : "$8", "$9", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C09B8);
#ifdef SKIP_ASM
extern void func_003C4A38_09B8(int, int, int, int) __asm__("func_003C4A38");

void func_003C09B8(void) {
    D_0050AD00.f1B1C[0] = *(volatile int *)0x1000D010;
    D_0050AD00.f1B1C[1] = *(volatile int *)0x1000D080;
    D_0050AD00.f1B1C[2] = *(volatile int *)0x1000D020;
    D_0050AD00.f1B1C[3] = *(volatile int *)0x1000D410;
    D_0050AD00.f1B1C[4] = *(volatile int *)0x1000D430;
    D_0050AD00.f1B1C[5] = *(volatile int *)0x1000D480;
    D_0050AD00.f1B1C[6] = *(volatile int *)0x1000D420;
    func_003C4A38_09B8(D_0050A94C[0], D_0050AD00.f1B38, D_0050AD00.f1AAE >> 4, 0x10000);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0A60);
#ifdef SKIP_ASM
extern void func_003C4978(int, int, int, int);

void func_003C0A60(void) {
    func_003C4978(D_0050AD00.f1B38, D_0050A94C[0], D_0050AD00.f1AAE >> 4, 0x10000);
    *(volatile int *)0x1000D010 = D_0050AD00.f1B1C[0];
    *(volatile int *)0x1000D080 = D_0050AD00.f1B1C[1];
    *(volatile int *)0x1000D020 = D_0050AD00.f1B1C[2];
    *(volatile int *)0x1000D410 = D_0050AD00.f1B1C[3];
    *(volatile int *)0x1000D430 = D_0050AD00.f1B1C[4];
    *(volatile int *)0x1000D480 = D_0050AD00.f1B1C[5];
    *(volatile int *)0x1000D420 = D_0050AD00.f1B1C[6];
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0B10);
#ifdef SKIP_ASM
extern void func_003C51E8(void *, void *, int);
extern int func_00426F08(void *);
extern void func_00426D18(void *, int, int, void *, int, int, int, int, int);

void func_003C0B10(int a0, void *a1, int a2) {
    volatile int i;
    int two = a0 == 2;
    if (a2) {
        func_003C51E8(D_0050AD00.f000, a1, a2);
    }
    while (func_00426F08(D_0050AD00.fC80)) {
        for (i = 0; i < 10000; i++) {
        }
    }
    func_00426D18(D_0050AD00.fC80, a0, two, D_0050AD00.f000, a2, 0, 0, 0, 0);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C0BE8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003BA550(int, unsigned char);

void func_003C0BE8(int arg0) {
    func_003BA550(arg0 + D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F, D_0050A8E8.setup.cfg.f0F);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0C18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003C0C18(int arg0, int *arg1, int *arg2) {
    if (arg0 & 8) {
        *arg1 = 0;
        *arg2 = D_0050A918;
        return;
    }
    if (arg0 & 0x100) {
        *arg1 = D_0050A8E8.setup.cfg.f10;
        *arg2 = D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F;
        return;
    }
    if (arg0 & 4) {
        *arg1 = D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F;
        *arg2 = D_0050A8E8.f17E;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C0C90);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C0E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f8148_0E28(int) __asm__("func_003C8148");
extern void f38E0_0E28(int) __asm__("func_003C38E0");

int func_003C0E28(void) {
    struct sA8E8Cfg s;
    int i;

    s = D_0050A908;
    if (D_0050A8E8.f174) {
        D_0050A8E8.setup.cfg = D_0050A8E8.saved;
        if (D_0050A8E8.saved.f29 != s.f29) {
            return 0;
        }
    }
    if (s.f0A <= 24000) {
        s.f0A = 24000;
    } else if (s.f0A <= 36000) {
        s.f0A = 36000;
    } else {
        s.f0A = 48000;
    }
    if (s.f0C <= 24000) {
        s.f0C = 24000;
    } else if (s.f0C <= 36000) {
        s.f0C = 36000;
    } else {
        s.f0C = 48000;
    }
    if (s.f29 & 2) {
        s.f10 = 0x18;
        if (s.f27 < 4) {
            s.f27 = 4;
        }
    }
    if (s.f29 & 1) {
        if (s.f27 > 2) {
            s.f27 = 2;
        }
        s.f28 = 0;
    }
    if (s.f2A > 100) {
        s.f2A = 100;
    }
    if (s.f27 < D_0050A8E8.setup.f04) {
        s.f27 = D_0050A8E8.setup.f04;
    } else if (s.f27 > D_0050A8E8.setup.f05) {
        s.f27 = D_0050A8E8.setup.f05;
    }
    if (s.f27 == 5) {
        s.f28 = 1;
    } else {
        s.f28 = 0;
    }
    if (s.f0E > D_0050A8E8.setup.f06) {
        s.f0E = D_0050A8E8.setup.f06;
    }
    if (s.f0F > D_0050A8E8.setup.f07) {
        s.f0F = D_0050A8E8.setup.f07;
    }
    if (s.f10 > D_0050A8E8.setup.f08) {
        s.f10 = D_0050A8E8.setup.f08;
    }
    if (s.f26 > 0x20) {
        s.f26 = 0x20;
    }
    f8148_0E28(s.f20);
    if (D_0050A8E8.setup.cfg.f44 != 0 && (s.f44 & 0xF)) {
        s.f44 = ((s.f44 + 0xF) >> 4) << 4;
        s.f48 -= 0x10;
    }
    if (D_0050A8E8.f174) {
        D_0050A8E8.setup.cfg.f20 = s.f20;
        D_0050A8E8.setup.cfg.f21 = s.f21;
        D_0050B9B0->f13 = s.f21;
        if (D_0050A8E8.saved.f27 != s.f27) {
            D_0050A8E8.setup.cfg.f27 = s.f27;
            for (i = 0; i < D_0050A8E8.f17E; i++) {
                if (D_0050A8E8.f1F0[i].f69 == 1 && D_0050A8E8.f1F0[i].f28 < 0) {
                    f38E0_0E28(i);
                }
            }
        }
        return 0;
    }
    D_0050A8E8.f17E = s.f0E + s.f0F + s.f10;
    D_0050A8E8.setup.cfg = s;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1298);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_A550_1298(int) __asm__("func_003BA550");

void func_003C1298(void) {
    int i;
    int j;
    int h;

    for (i = 0; i < D_0050A8E8.setup.cfg.f10; i++) {
        if (D_0050AD00.fCB0->f20[i].key != 0 && D_0050A8E8.f1F0[i].f28 == -1) {
            if (D_0050AD00.f83C[i].key != D_0050AD00.fCB0->f20[i].key) {
                D_0050AD00.f83C[i].val = D_0050AD00.fCB0->f20[i].key & 0x7FFFFF;
            }
            if (D_0050AD00.f83C[i].val == 0) {
                for (j = 0; j < D_0050A8E8.f1F0[i].f23; j++) {
                    h = D_0050A8E8.f1F0[i].f04[j];
                    D_0050AD00.fCB0->f20[h].key = 0;
                    f_A550_1298(h);
                    if (D_0050A8E8.setup.cfg.f29 == 2) {
                        D_0050AD00.fCB0->f20[h + 0x18].key = 0;
                    }
                }
            }
        }
    }
    for (i = 0; i < D_0050A8E8.setup.cfg.f0F; i++) {
        if (D_0050AD00.fCB0->f1A0[i].key != 0 && D_0050A8E8.f1F0[i + D_0050A8E8.setup.cfg.f10].f28 == -1) {
            if (D_0050AD00.f9BC[i].key != D_0050AD00.fCB0->f1A0[i].key) {
                D_0050AD00.f9BC[i].val = 0;
            }
            if (D_0050AD00.f9BC[i].val == -1) {
                for (j = 0; j < D_0050A8E8.f1F0[i + D_0050A8E8.setup.cfg.f10].f23; j++) {
                    h = D_0050A8E8.f1F0[i + D_0050A8E8.setup.cfg.f10].f04[j];
                    D_0050AD00.fCB0->f1A0[h - D_0050A8E8.setup.cfg.f10].key = 0;
                    f_A550_1298(h);
                }
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1578);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad[0xC]; int v; int mode; } A_1578;
extern void func_003C4918(int);
extern void func_00423DD0(int);

void func_003C1578(A_1578 *arg0) {
    switch (arg0->mode) {
    case 2:
        func_003C4918(arg0->v);
        return;
    case 3:
        break;
    case 0:
        D_0050AD00.f1B04 = arg0->v;
        func_00423DD0(D_0050AD00.f1AA4);
        break;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C15D8);
#ifdef SKIP_ASM
void func_003C15D8(char *dst, char *src) {
    while (*dst) dst++;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C1638);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C1980);
#ifdef SKIP_ASM
int func_003C1980(void) {
    D_0050A8E8.f1C0 = D_0050A8E8.f1C0 + 1;
    // PORT: MIPS sync + EE ei (no C equivalent)
    __asm__ volatile("sync\n\tei");
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C19A8);

INCLUDE_ASM("ealib/seg_2B4578", func_003C1B80);

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C2268);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00512B20;
extern void func_003C0B10_2268(int, int, int) __asm__("func_003C0B10");
extern void func_003C8018(void);
extern void func_003CBC00(int *);
extern int func_00423AA0_2268(int, int) __asm__("func_00423AA0");
extern void func_00423BB0(int);
extern void func_00423BF0(int);
extern void func_00423CA0(int, void *);
extern void func_00423DB0(int);
extern void func_00424880(int);
extern void func_004248E8_2268(int) __asm__("func_004248E8");
extern void func_0042AD08_2268(int) __asm__("func_0042AD08");

int func_003C2268(void) {
    int st[12];
    unsigned int t;
    int i;

    while (D_0050A8E8.f176 != 0) {
        func_003B58D8();
    }
    t = D_0050A8E8.f180 + 10;
    while (D_0050A8E8.f180 < t) {
        func_003C60E0();
    }
    if (D_0050AD00.f1AA8 >= 0) {
        func_00424880(2);
        if (func_00423AA0_2268(2, D_0050AD00.f1AA8) > 0) {
            func_004248E8_2268(2);
        }
    }
    func_003C0B10_2268(1, 0, 0);
    func_00423CA0(D_00512B20, st);
    if (st[0] == 0x10) {
        func_00423BB0(D_00512B20);
    } else {
        func_00423BF0(D_00512B20);
        func_00423BB0(D_00512B20);
    }
    func_00423DB0(D_0050AD00.f1AA4);
    for (i = 0; i < 1; i++) {
        func_0042AD08_2268(D_0050AD00.fE88[i].f04);
    }
    func_003CBC00(0);
    D_0050AD00.f1AAD = 0;
    func_003B58A0();
    if (D_0050AD00.f1AD4 != 0) {
        func_003B5E98(D_0050AD00.f1AD4);
        D_0050AD00.f1AD4 = 0;
        D_0050AD00.f1AD8 = 0;
    }
    if (D_0050AD00.f1AF8 != 0) {
        func_003B5E98(D_0050AD00.f1AF8);
        D_0050AD00.f1AF8 = 0;
    }
    if (D_0050AD00.f1B38 != 0) {
        func_003B5E98(D_0050AD00.f1B38);
        D_0050AD00.f1B38 = 0;
    }
    func_003C8018();
    func_003B5E98(D_0050AD00.f1AA0);
    func_003B58D8();
    return 0;
}
#endif

void func_003C2438(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C2440);
#ifdef SKIP_ASM
extern void f_A550_2440(int) __asm__("func_003BA550");
extern void f_8468_2440(int) __asm__("func_003C8468");

int func_003C2440(int arg0) {
    struct sA8E8Chan *e = &D_0050A8E8.f1F0[arg0];
    int i, k;
    unsigned fl = e->f24;
    if (fl & 8) {
        for (i = 0; i < e->f23; i++) {
            D_0050AD00.fCB0->f20[e->f04[i]].key = 0;
            f_A550_2440(e->f04[i]);
            if (D_0050A8E8.setup.cfg.f29 == 2) {
                k = e->f04[i] + 0x18;
                D_0050AD00.fCB0->f20[k].key = 0;
            }
        }
    } else if (fl & 0x100) {
        for (i = 0; i < e->f23; i++) {
            D_0050AD00.fCB0->f1A0[e->f04[i] - D_0050A8E8.setup.cfg.f10].key = 0;
            f_A550_2440(e->f04[i]);
        }
    } else {
        for (i = 0; i < e->f23; i++) {
            f_8468_2440(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F));
            f_A550_2440(e->f04[i]);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C25E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8A88_25E0(int a, unsigned int v) __asm__("func_003C8A88");

int func_003C25E0(int idx) {
    struct sA8E8Chan *e = &D_0050A8E8.f1F0[idx];
    unsigned int v;
    int i;

    if (e->f24 & 8) {
        v = (unsigned int)((e->f20 << 12) / 48000 * e->f8A) >> 12;
        if (v >= 0x4000) {
            v = 0x3FFF;
        }
        for (i = 0; i < e->f23; i++) {
            D_0050AD00.fCB0->f20[e->f04[i]].pitch = v;
            if (D_0050A8E8.setup.cfg.f29 == 2) {
                D_0050AD00.fCB0->f20[e->f04[i] + 0x18].pitch = v;
            }
        }
    } else if (e->f24 & 0x100) {
        v = (unsigned int)((e->f20 << 12) / D_0050A8E8.setup.cfg.f0C * e->f8A) >> 12;
        for (i = 0; i < e->f23; i++) {
            D_0050AD00.fCB0->f1A0[e->f04[i] - D_0050A8E8.setup.cfg.f10].pitch = v;
        }
    } else {
        v = (unsigned int)((e->f20 << 12) / D_0050A8E8.setup.cfg.f0A * e->f8A) >> 8;
        for (i = 0; i < e->f23; i++) {
            func_003C8A88_25E0(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), v);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C27E0);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8598(int, int, float);

int func_003C27E0(int id, int k) {
    struct sA8E8Chan *ch;
    int i, v;
    float f;

    ch = &D_0050A8E8.f1F0[id];
    if (ch->f24 & 8) {
        for (i = 0; i < ch->f23; i++) {
            if (ch->f62[0] != 0) {
                D_0050AD00.fCB0->f00 |= 1L << ch->f04[i];
            } else {
                D_0050AD00.fCB0->f00 &= ~(1L << ch->f04[i]);
            }
            if (D_0050A8E8.setup.cfg.f29 == 2) {
                if (ch->f62[0] != 0) {
                    D_0050AD00.fCB0->f00 |= 1L << (ch->f04[i] + 0x18);
                } else {
                    D_0050AD00.fCB0->f00 &= ~(1L << (ch->f04[i] + 0x18));
                }
            }
        }
    } else if (ch->f24 & 0x100) {
        v = ch->f48 * ch->f62[k] * 0.003875850699841976f;
        for (i = 0; i < ch->f23; i++) {
            D_0050AD00.fCB0->f1A0[ch->f04[i] - D_0050A8E8.setup.cfg.f10].f0C[k] = v;
        }
    } else {
        f = ch->f48 * ch->f62[k] / 32767.0f;
        for (i = 0; i < ch->f23; i++) {
            func_003C8598(ch->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), k, f);
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C2A50);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8560(int, int, float);

void func_003C2A50(int id) {
    struct sA8E8Chan *ch;
    float sc;
    int i;
    int j;
    int m;

    ch = &D_0050A8E8.f1F0[id];
    if (ch->f24 & 8) {
        for (i = 0; i < ch->f23; i++) {
            if (D_0050A8E8.setup.cfg.f29 != 2) {
                D_0050AD00.fCB0->f20[ch->f04[i]].l = D_0050AD00.fE98[ch->f04[i]].f00[1] * ch->f48 * 127.0f;
                D_0050AD00.fCB0->f20[ch->f04[i]].r = D_0050AD00.fE98[ch->f04[i]].f00[0] * ch->f48 * 127.0f;
            } else {
                if (D_0050A8E8.setup.cfg.f27 == 4) {
                    D_0050AD00.fCB0->f20[ch->f04[i]].l = D_0050AD00.fE98[ch->f04[i]].f00[3] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i]].r = D_0050AD00.fE98[ch->f04[i]].f00[0] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i] + 0x18].l = D_0050AD00.fE98[ch->f04[i]].f00[2] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i] + 0x18].r = D_0050AD00.fE98[ch->f04[i]].f00[1] * ch->f48 * 127.0f;
                } else {
                    D_0050AD00.fCB0->f20[ch->f04[i]].l = D_0050AD00.fE98[ch->f04[i]].f00[4] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i]].r = D_0050AD00.fE98[ch->f04[i]].f00[1] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i] + 0x18].l = D_0050AD00.fE98[ch->f04[i]].f00[3] * ch->f48 * 127.0f;
                    D_0050AD00.fCB0->f20[ch->f04[i] + 0x18].r = D_0050AD00.fE98[ch->f04[i]].f00[2] * ch->f48 * 127.0f;
                }
            }
        }
    } else if (ch->f24 & 0x100) {
        m = D_0050A8E8.setup.cfg.f27 + D_0050A8E8.setup.cfg.f28;
        sc = ch->f48 * (float)ch->f5F * 0.0078740157186985016f;
        for (i = 0; i < ch->f23; i++) {
            for (j = 0; j < m; j++) {
                D_0050AD00.fCB0->f1A0[ch->f04[i] - D_0050A8E8.setup.cfg.f10].vol[j] = sc * D_0050AD00.fE98[ch->f04[i]].f00[j] * 127.0f;
            }
        }
    } else {
        m = D_0050A8E8.setup.cfg.f27 + D_0050A8E8.setup.cfg.f28;
        sc = ch->f48 * (float)ch->f5F * 0.0078740157186985016f;
        for (i = 0; i < ch->f23; i++) {
            for (j = 0; j < m; j++) {
                func_003C8560(ch->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), j, sc * D_0050BB98[ch->f04[i]].f00[j]);
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C2EC8);
#ifdef SKIP_ASM
extern void func_003C2A50(int);

void func_003C2EC8(int id) {
    struct sA8E8Chan *ch = &D_0050A8E8.f1F0[id];
    int i;
    if (ch->f24 & 8) {
        for (i = 0; i < ch->f23; i++) {
            if (ch->f5F) {
                D_0050AD00.fCB0->f08 = D_0050AD00.fCB0->f08 | (1L << ch->f04[i]);
            } else {
                D_0050AD00.fCB0->f08 = D_0050AD00.fCB0->f08 & ~(1L << ch->f04[i]);
            }
            if (D_0050A8E8.setup.cfg.f29 == 2) {
                if (ch->f5F) {
                    D_0050AD00.fCB0->f08 = D_0050AD00.fCB0->f08 | (1L << (ch->f04[i] + 0x18));
                } else {
                    D_0050AD00.fCB0->f08 = D_0050AD00.fCB0->f08 & ~(1L << (ch->f04[i] + 0x18));
                }
            }
        }
    } else if (ch->f24 & 0x100) {   /* the two arms are identical in the release build (two separate calls in the binary) */
        func_003C2A50(id);
    } else {
        func_003C2A50(id);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3010);
#ifdef SKIP_ASM
extern void func_003C8B40(int, int);

int func_003C3010(int arg0, int arg1) {
    struct sA8E8Chan *e;
    int i;
    e = &D_0050A8E8.f1F0[arg0];
    if (e->f24 & 4) {
        for (i = 0; i < e->f23; i++)
            func_003C8B40(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), arg1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C30C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8B80(int, int);

void func_003C30C8(int arg0, int arg1) {
    struct sA8E8Chan *e;
    int i;
    e = &D_0050A8E8.f1F0[arg0];
    if (e->f24 & 4) {
        for (i = 0; i < e->f23; i++)
            func_003C8B80(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), arg1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3178);
#ifdef SKIP_ASM
extern void func_003C8D00_3178(float, int) __asm__("func_003C8D00");

void func_003C3178(int arg0, int arg1) {
    struct sA8E8Chan *e = &D_0050A8E8.f1F0[arg0];
    int i;

    if (e->f24 & 4) {
        float f = (float)arg1 * (1.0f / ((float)D_0050A8E8.setup.cfg.f0A * 0.5f));
        for (i = 0; i < e->f23; i++) {
            func_003C8D00_3178(f, e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F));
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3250);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8C30(int, int);

void func_003C3250(int arg0, int arg1) {
    struct sA8E8Chan *e;
    int i;
    e = &D_0050A8E8.f1F0[arg0];
    if (e->f24 & 4) {
        for (i = 0; i < e->f23; i++)
            func_003C8C30(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), arg1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3300);
#ifdef SKIP_ASM
extern int D_0050ACE0_3300[] __asm__("D_0050ACE0");
extern int func_00423DA0_3300(int *) __asm__("func_00423DA0");

void func_003C3300(void) {
    D_0050ACE0_3300[1] = 0x14;
    D_0050AD00.f1B14 = -1;
    D_0050ACE0_3300[2] = 1;
    D_0050AD00.f1B18 = 0;
    D_0050AD00.f1B10 = func_00423DA0_3300(D_0050ACE0_3300);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3358);
#ifdef SKIP_ASM
void func_003C3358(void) {
    func_00423DB0(D_0050AD00.f1B10);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3380);
#ifdef SKIP_ASM
extern int func_00423C90(void);
extern void func_00423DE0(int);

/* Recursive lock (pairs with func_003C33E0). The owner's re-entry bumps the count and returns early; jump2
   cross-jumps the two count increments into one copy, and the return label left behind keeps the epilogue
   restores below the final store, as in the target. */
void func_003C3380(void) {
    int r = func_00423C90();
    if (D_0050AD00.f1B14 == r) {
        D_0050AD00.f1B18++;
        return;
    }
    func_00423DE0(D_0050AD00.f1B10);
    D_0050AD00.f1B14 = r;
    D_0050AD00.f1B18++;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C33E0);
#ifdef SKIP_ASM
extern int func_00423C90(void);
extern void func_00423DC0(int);

void func_003C33E0(void) {
    int r = func_00423C90();
    if (D_0050AD00.f1B14 == r) {
        D_0050AD00.f1B18--;
        if (D_0050AD00.f1B18 == 0) {
            D_0050AD00.f1B14 = -1;
        }
    }
    if (D_0050AD00.f1B18 <= 0) {
        func_00423DC0(D_0050AD00.f1B10);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C3450);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C0B10(int, void *, int);
extern int f_72F8_3450(void *, int) __asm__("func_003C72F8");
extern char D_0050AAF4_3450[] __asm__("D_0050AAF4");
extern char D_0044DD70_3450[] __asm__("D_0044DD70");
extern void func_003CC878(int);

void func_003C3450(int arg0) {
    char *b = D_0050AAF4_3450;
    char *t = b - 0x20C;
    char *q;
    if (*(unsigned char *)(t + 0x42) != 0) {
        D_00515B40.f10 = func_003CC878;
        D_00515B40.f0F[0] = 1;
    }
    if (arg0 != 1) {
        func_003C0B10(2, D_0044DD70_3450, 4);
        if (*(unsigned char *)(t + 0x42) != 0)
            D_00515B4F = 0;
    } else {
        q = *(char **)(b + 4);
        if (*(unsigned char *)(t + 0x42) != 0)
            D_00515B4F = arg0;
        func_003C0B10(2, q, f_72F8_3450(q + 4, 4));
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3500);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044DD48_3500[] __asm__("D_0044DD48");

void func_003C3500(unsigned a) {
    unsigned v = a;
    if (a < 2) {
        v = 0;
    } else if (a == 5) {
        v = 1;
    } else if (a == 10) {
        v = 2;
    } else if (a == 20) {
        v = 3;
    } else if (a == 30) {
        v = 4;
    } else if (a == 40) {
        v = 5;
    } else if (a == 50) {
        v = 6;
    } else if (a == 100) {
        v = 9;
    } else if (a == 110) {
        v = 8;
    } else if (a == 120) {
        v = 7;
    }
    D_0050AD00.f1A9E = (0x200000 - D_0044DD48_3500[v]) >> 6;
    D_0050AD00.fCB0->f10 = v;
    D_0050AD00.fCB0->f11 = D_0050A8E8.f220[0].f04;
    D_0050AD00.fCB0->f12 = D_0050A8E8.f220[0].f08;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C35F8);
#ifdef SKIP_ASM
extern void func_003CC848(void);
extern void func_003CC630_35F8(int, int) __asm__("func_003CC630");

void func_003C35F8(int arg0) {
    func_003B58A0();
    if (arg0 == 8) {
        func_003C3500(D_0050AB08[0].f00);
    } else if (arg0 == 0x100) {
        func_003C3450(D_0050AAF4[0].f00);
    } else if (arg0 == 4) {
        if (D_0050A8E8.f1F8[0].f00 != 1 || D_0050A8E8.setup.cfg.f22 != 0) {
            if (D_0050A8E8.setup.cfg.f22 == 0) {
                D_00515B50 = 0;
            }
            func_003CC848();
        } else {
            func_003CC630_35F8(D_0050A8E8.setup.cfg.f0A, D_0050A8E8.f1F8[0].f04);
        }
    }
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C36A8);
#ifdef SKIP_ASM
extern void func_003C35F8(int);

int func_003C36A8(int a, int b) {
    func_003C35F8(b);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C36C8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003C36C8(int arg0, int flags) {
    if (D_0050AD00.fCB0 != 0 && (flags & 8)) {
        D_0050AD00.fCB0->f14 = (int)(D_0050AB08[0].f0C.l * 32767.0f);
        D_0050AD00.fCB0->f16 = (int)(D_0050AB08[0].f0C.r * 32767.0f);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3728);
#ifdef SKIP_ASM
extern short D_0044DD78[];
void func_003C3728(unsigned x, float* out)
{
    short* p = D_0044DD78;
    int i;
    p = (short*)((char*)p + ((x >> 6) & 0x3FC));
    for (i = 0; i < 2; i++)
        out[i] = p[i] / 32767.0f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3780);
#ifdef SKIP_ASM
void func_003C3780(int a, float *x, float *y, int dx, int dy) {
    int oct;
    int k;
    int r;
    if (dx < 0 && dy < 0) {
        oct = dx < dy ? 1 : 2;
    } else if (dx >= 0 && dy >= 0) {
        oct = dx < dy ? 2 : 1;
    } else {
        int ax = dx > -1 ? dx : -dx;
        oct = (dy < 0 ? -dy < ax : dy < ax) ? 4 : 3;
    }
    r = 0;
    if ((unsigned)(a - 0x4000) < 0x8000) {
        k = 4;
        if (*x < *y) k = 3;
        if (oct < 3) {
            r = 2;
            if (k == 3 && oct == 2) r = 1;
        }
    } else {
        k = 1;
        if (*x < *y) k = 2;
        if (oct >= 3) {
            r = 2;
            if (k == 2 && oct == 3) r = 1;
        }
    }
    if (dx < 0) *x = -*x;
    if (dy < 0) *y = -*y;
    if (r == 1) *x = -*x;
    else if (r == 2) *y = -*y;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C38E0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3EA8);
#ifdef SKIP_ASM
int func_003C3EA8(void *arg0, int arg1, int *arg2) {
    if (*arg2 == 0) {
        *arg2 = (*(int *)((char*)(arg0) + (0x68)));
    }
    *(*(int **)((char*)(arg0) + (0x64))) = arg1 + ((*(int *)((char*)(arg0) + (0x68))) - *arg2);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C3EE0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct V_3EE0 {
    char pad0[2];
    signed char b2;
    char pad3[0x13 - 3];
    unsigned char b13;
    char pad14[0x5C - 0x14];
    int x5C;
    int x60;
    int *p64;
    int a68[6];
    int a80[6];
    int a98[6];
};
extern void func_003C2EC8(int);
extern void f38E0_3EE0(int) __asm__("func_003C38E0");
extern void f3178_3EE0(int, int) __asm__("func_003C3178");
extern void func_003C83A0(int);
extern void f8158_3EE0(int, int, int, int, int, int, int, int, int, int, int, int, int, int) __asm__("func_003C8158");

int func_003C3EE0(struct V_3EE0 *v, int base, int id, int p3, int p4, int p5, int p6) {
    struct sA8E8Chan *ch;
    int i;

    ch = &D_0050A8E8.f1F0[id];
    if (ch->f24 & 8) {
        func_003C25E0(id);
        f38E0_3EE0(id);
        func_003C2EC8(id);
        func_003C27E0(id, 0);
        for (i = 0; i < ch->f23; i++) {
            D_0050AD00.fE98[ch->f04[i]].f18 = *v->p64 + (v->a68[i] - v->a68[0]);
            D_0050AD00.f1AB8 += 0x800000;
            D_0050AD00.fCB0->f20[ch->f04[i]].key = D_0050AD00.fE98[ch->f04[i]].f18 | D_0050AD00.f1AB8;
            D_0050AD00.f83C[ch->f04[i]].val = D_0050AD00.fE98[ch->f04[i]].f18;
            if (D_0050A8E8.setup.cfg.f29 == 2) {
                D_0050AD00.fCB0->f20[ch->f04[i] + 0x18].key = D_0050AD00.fE98[ch->f04[i]].f18 | D_0050AD00.f1AB8;
                D_0050AD00.f83C[ch->f04[i] + 0x18].val = D_0050AD00.fE98[ch->f04[i]].f18;
            }
        }
    } else if (ch->f24 & 0x100) {
        func_003C25E0(id);
        f38E0_3EE0(id);
        func_003C27E0(id, 0);
        for (i = 0; i < ch->f23; i++) {
            D_0050AD00.fE98[ch->f04[i]].f18 = *v->p64 + (v->a68[i] - v->a68[0]);
            D_0050AD00.f1AB8 += 0x800000;
            D_0050AD00.fCB0->f1A0[ch->f04[i] - D_0050A8E8.setup.cfg.f10].key = D_0050AD00.fE98[ch->f04[i]].f18 | D_0050AD00.f1AB8;
            D_0050AD00.f9BC[ch->f04[i] - D_0050A8E8.setup.cfg.f10].val = 0;
        }
    } else {
        for (i = 0; i < ch->f23; i++) {
            f8158_3EE0(ch->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), v->b13, 1,
                       base + v->a68[i], base + v->a68[0] + v->a80[i], v->a98[i], ch->f23, *(int *)((char *)ch + 0x14),
                       v->x5C, v->x60, 0, 0, v->b2, i);
        }
        func_003C25E0(ch->f04[0]);
        f38E0_3EE0(ch->f04[0]);
        func_003C27E0(ch->f04[0], 0);
        func_003C3010(ch->f04[0], p3);
        func_003C30C8(ch->f04[0], p4);
        f3178_3EE0(ch->f04[0], p5);
        func_003C3250(ch->f04[0], p6);
        for (i = 0; i < ch->f23; i++) {
            func_003C83A0(ch->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F));
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C42D8);
#ifdef SKIP_ASM
extern int func_003C4788(int, int, int, int, int);

int func_003C42D8(int a, int b, int c, int d) {
    return func_003C4788(a, b, c, d, 10);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C42F8);
#ifdef SKIP_ASM
extern int func_003C4898();

int func_003C42F8(void) {
    return func_003C4898();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4318);
#ifdef SKIP_ASM
extern int func_003C8A40(int);
unsigned int func_003C4318(int id) {
    struct sA8E8Chan *ch = &D_0050A8E8.f1F0[id];
    struct sAD00Spk *s = &D_0050AD00.fE98[id];
    unsigned short f = ch->f24;
    if (f & 8) {
        return ((D_0050AD00.f83C[id].val - s->f18) * 0x1C) >> 4;
    }
    if (f & 0x100) {
        return D_0050AD00.f9BC[id - D_0050A8E8.setup.cfg.f10].val;
    }
    return func_003C8A40(id - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C43C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_43C0 { int a, b, c, d; };
extern void func_00424020(int);
extern void func_00424050(int);
extern int func_00424140(int);
extern int func_00424150(int);
extern int func_00424160(void *, int);
extern int func_00424170(void *, int);
extern int D_0044E178;

void func_003C43C0(int arg0, int arg1, int arg2, int arg3) {
    struct S_43C0 s;
    s.a = arg0;
    s.c = arg2;
    s.b = arg1;
    s.d = 0;
    if (arg3 != 0) {
        func_00424050(0);
        while (func_00424150(D_0044E178) >= 0) {}
        D_0044E178 = func_00424170(&s, 1);
    } else {
        func_00424020(0);
        while (func_00424140(D_0044E178) >= 0) {}
        D_0044E178 = func_00424160(&s, 1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4450);
#ifdef SKIP_ASM
struct Dst_4450 { char b0; char pad1[0xF]; int f10; int f14; int f18; int f1C; unsigned short h20; short h22; };
extern struct Dst_4450 D_00515780_4450 __asm__("D_00515780");
extern void func_003C43C0(int, int, int, int);
extern void func_004261B0(int, void *, int, int, int, int);
extern void f61F0_4450(int, void *, int, int, int, int) __asm__("func_004261F0");

void func_003C4450(int arg0) {
    struct sAD00Xfer *t0 = D_0050B9C8;
    struct sAD00 *h = (struct sAD00 *)((char *)t0 - 0xCC8);
    struct sAD00Xfer *e = t0;
    int cnt = 0;
    unsigned best = 0xFFFFFFFF;
    unsigned char pri = 0;
    int i;
    struct sAD00Xfer *p;
    signed char c;
    i = 0;
    do {
        if (e->key != 0) {
            cnt++;
            if (pri < e->f0E) {
                h->fCC1 = i;
                best = e->key;
                pri = e->f0E;
            } else if (e->f0E == pri && e->key < best) {
                h->fCC1 = i;
                best = e->key;
            }
            c = h->fCC0;
            if (cnt >= c) break;
        }
        i++;
        e++;
    } while (i < 0x1C);
    p = &D_0050AD00.fCC8[(signed char)D_0050AD00.fCC1];
    D_0050AD00.fCC4 = D_0050A8E8.f180;
    func_003C43C0(p->f04, D_0050AD00.fE88[0].f04, p->f0C, arg0);
    D_0050AD00.fCC2 = 1;
    D_00515780_4450.b0 = 0x30;
    D_00515780_4450.f10 = 1;
    D_00515780_4450.f14 = p->key;
    D_00515780_4450.f18 = D_0050AD00.fE88[0].f04;
    D_00515780_4450.f1C = p->f08;
    D_00515780_4450.h20 = p->f0C;
    D_00515780_4450.h22 = p->f0E;
    if (arg0 != 0) {
        f61F0_4450(0, &D_00515780_4450, 0x30, 0, 0, 0);
        return;
    }
    func_004261B0(0, &D_00515780_4450, 0x30, 0, 0, 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C45E8);
#ifdef SKIP_ASM
void func_003C45E8(int arg0) {
    int s;
    if (arg0 == 0) {
        do {
            DI_2B45();
            SYNCP_2B45();
            MFC0_STATUS_2B45(s);
        } while (s & 0x10000);
    }
    if (D_0050AD00.fCC2 == 0 && (signed char)D_0050AD00.fCC0 > 0) {
        func_003C4450(arg0);
    }
    if (arg0 == 0) {
        EI_2B45();
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4668);
#ifdef SKIP_ASM
extern void func_003C45E8_4668(int) __asm__("func_003C45E8");
extern void func_003C43C0_4668(int, int, int, int) __asm__("func_003C43C0");
int func_003C4668(int op, int a, int b, int size, int d) {
    int s, i;
    if (size & 0x3F) {
        size += 0x40;
        size &= 0xFFFFFFC0;
    }
    do {
        DI_2B45();
        SYNCP_2B45();
        MFC0_STATUS_2B45(s);
    } while (s & 0x10000);
    D_0050AD00.fCBC++;
    if (D_0050AD00.fCBC == 0) {
        D_0050AD00.fCBC = 1;
    }
    if (op == 0x100) {
        func_003C43C0_4668(a, b, size, 0);
        EI_2B45();
        return D_0050AD00.fCBC;
    }
    for (i = 0; i < 28; i++) {
        struct sAD00Xfer *e = &D_0050AD00.fCC8[i];
        if (e->key == 0) {
            D_0050AD00.fCC0++;
            e->key = D_0050AD00.fCBC;
            e->f04 = a;
            e->f08 = b;
            e->f0C = size;
            e->f0E = d;
            EI_2B45();
            func_003C45E8_4668(0);
            return D_0050AD00.fCBC;
        }
    }
    EI_2B45();
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C4788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C45E8(int);
extern int func_003C4668_4788(int, int, int, int, int) __asm__("func_003C4668");

int func_003C4788(int a0, int a1, int a2, int a3, int a4) {
    int r = 0;
    int t;
    int c;
    while (a3 > 0) {
        t = 0x1000;
        if (!(a3 > 0xFFF)) t = a3;
        c = D_0050AD00.fCC0;
        while (0x1C - (signed char)c < 5) {
            func_003C45E8(0);
            c = D_0050AD00.fCC0;
        }
        r = func_003C4668_4788(a0, a1, a2, t, a4);
        a1 += t;
        a2 += t;
        a3 -= t;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4898);
#ifdef SKIP_ASM
extern void func_003C4450(int);

int func_003C4898_4898(int) __asm__("func_003C4898");
int func_003C4898_4898(int key) {
    int i;
    if ((signed char)D_0050AD00.fCC0 <= 0) return 1;
    for (i = 0; i < 28; i++) {
        if (D_0050AD00.fCC8[i].key == key) {
            if (D_0050AD00.fCC4 + 500 < D_0050A8E8.f180) {
                func_003C4450(0);
            }
            return 0;
        }
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4918);
#ifdef SKIP_ASM
void func_003C4918(int key) {
    int i;
    for (i = 0; i < 28; i++) {
        if (D_0050AD00.fCC8[i].key == key) {
            D_0050AD00.fCC2 = 0;
            D_0050AD00.fCC0--;
            D_0050AD00.fCC8[i].key = 0;
            func_003C45E8(1);
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4978);
#ifdef SKIP_ASM
void func_003C4978(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D400 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
    *(volatile int *)0x1000D410 = arg0;
    *(volatile int *)0x1000D480 = arg1;
    *(volatile int *)0x1000D420 = arg2;
    *(volatile int *)0x1000D400 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D400 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D400 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4A38);
#ifdef SKIP_ASM
void func_003C4A38(int arg0, int arg1, int arg2, int arg3) {
    if (*(volatile int *)0x1000D000 & 0x100) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
    *(volatile int *)0x1000D010 = arg1;
    *(volatile int *)0x1000D080 = arg0;
    *(volatile int *)0x1000D020 = arg2;
    *(volatile int *)0x1000D000 = 0x100;
    if ((arg3 & 0x10000) && (*(volatile int *)0x1000D000 & 0x100)) {
        do {
        } while (*(volatile int *)0x1000D000 & 0x100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4AF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C4AF8(int *arg0, int *arg1) {
    int temp_4;
    int temp_6;
    int lo = D_0050AD00.f1A9A;

    temp_6 = *arg0;
    if (temp_6 < lo) {
        *arg0 = lo;
        *arg1 -= lo - temp_6;
    }
    if (D_0050AD00.f1A9C < *arg0 + *arg1) {
        *arg1 = D_0050AD00.f1A9C - *arg0;
    }
    temp_4 = *arg0;
    if (D_0050AD00.f1A9E < temp_4 + *arg1) {
        *arg1 = D_0050AD00.f1A9E - temp_4;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C4B70);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4D78);
#ifdef SKIP_ASM
extern int func_0042AD08_4D78(unsigned int) __asm__("func_0042AD08");
int func_003C4D78(int type, unsigned int addr) {
    struct sAD00Seg *s;
    int i;
    if (type == 0x100) {
        return func_0042AD08_4D78(addr);
    }
    addr >>= 6;
    for (i = 0; i < D_0050AD00.f1A98; i++) {
        s = &D_0050AD00.f1AA0[i];
        if (s->a == addr) {
            D_0050AD00.f1A98--;
            for (; i < D_0050AD00.f1A98; i++) {
                D_0050AD00.f1AA0[i] = D_0050AD00.f1AA0[i + 1];
            }
            return 0;
        }
    }
    return -8;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4E50);
#ifdef SKIP_ASM
int func_003C4E50(int a, int b) {
    if (a == -1) {
        D_0050AD00.f1A9A = 0x141;
    } else {
        a = (a + 0x3F) >> 6;
        if (a < 0x141) return -8;
        D_0050AD00.f1A9A = a;
    }
    if (b == -1) {
        D_0050AD00.f1A9C = 0x8000;
    } else {
        b = (b + 0x3F) >> 6;
        if (b > 0x8000) return -8;
        D_0050AD00.f1A9C = b;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C4EC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int f_4EC8(int *out) __asm__("func_003C4EC8");
int f_4EC8(int *out) {
    int start;
    int len;
    int best = 0;
    int i;
    struct sAD00Seg *seg;
    struct sAD00Seg *prev;

    if (D_0050AD00.f1A98 == 0) {
        start = D_0050AD00.f1A9A;
        len = D_0050AD00.f1A9C - D_0050AD00.f1A9A;
        func_003C4AF8(&start, &len);
        best = len;
        *out = start;
    } else {
        for (i = 0; i < D_0050AD00.f1A98; i++) {
            seg = &D_0050AD00.f1AA0[i];
            if (i == 0) {
                start = seg->a;
                len = seg->a - 0x141;
                func_003C4AF8(&start, &len);
                if (best < len) {
                    best = len;
                    *out = start;
                }
            } else {
                prev = &D_0050AD00.f1AA0[i - 1];
                start = prev->a + prev->b;
                len = seg->a - start;
                func_003C4AF8(&start, &len);
                if (best < len) {
                    best = len;
                    *out = start;
                }
            }
        }
        prev = &D_0050AD00.f1AA0[i - 1];
        start = prev->a + prev->b;
        len = D_0050AD00.f1A9E - start;
        func_003C4AF8(&start, &len);
        if (best < len) {
            best = len;
            *out = start;
        }
    }
    *out <<= 6;
    return best << 6;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5068);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8E28_5068(int, int, int) __asm__("func_003C8E28");

int func_003C5068(int arg0, int arg1) {
    struct sA8E8Chan *e;
    int i;
    e = &D_0050A8E8.f1F0[arg0];
    if (e->f24 & 4) {
        for (i = 0; i < e->f23; i++)
            func_003C8E28_5068(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), i, arg1);
        return 0;
    }
    return -7;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8EC0(int, int);

int func_003C5128(int arg0, int arg1) {
    struct sA8E8Chan *e;
    int i;
    e = &D_0050A8E8.f1F0[arg0];
    if (e->f24 & 4) {
        for (i = 0; i < e->f23; i++)
            func_003C8EC0(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), arg1);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C51E0);
#ifdef SKIP_ASM
int func_003C51E0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C51E8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written memcpy (16-byte lq/sq blocks of 0x80, ld/sd and byte tails, unfilled delay slots; it branches into func_003C52C8, which loops back into it); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003C51E8\n.type func_003C51E8, @function\nfunc_003C51E8:\n"
    "slti $8, $6, 0x12\n"
    ".word 0x15000029 /* bnez $8, .L003C5294: raw word */\n"
    "andi $8, $4, 0xF\n"
    "bnez $8, func_003C52C8\n"
    "nop\n"
    ".L003C51FC:\n"
    "andi $8, $5, 0xF\n"
    ".word 0x15000024 /* bnez $8, .L003C5294: raw word */\n"
    "nop\n"
    "addiu $6, $6, -0x80\n"
    ".word 0x04C00015 /* bltz $6, .L003C5264: raw word */\n"
    "nop\n"
    ".L003C5214:\n"
    "lq $9, 0x0($5)\n"
    "lq $10, 0x10($5)\n"
    "lq $11, 0x20($5)\n"
    "lq $12, 0x30($5)\n"
    "sq $9, 0x0($4)\n"
    "sq $10, 0x10($4)\n"
    "sq $11, 0x20($4)\n"
    "sq $12, 0x30($4)\n"
    "lq $9, 0x40($5)\n"
    "lq $10, 0x50($5)\n"
    "lq $11, 0x60($5)\n"
    "lq $12, 0x70($5)\n"
    "sq $9, 0x40($4)\n"
    "sq $10, 0x50($4)\n"
    "sq $11, 0x60($4)\n"
    "sq $12, 0x70($4)\n"
    "addiu $6, $6, -0x80\n"
    "addiu $5, $5, 0x80\n"
    ".word 0x04C1FFED /* bgez $6, .L003C5214: raw word */\n"
    "addiu $4, $4, 0x80\n"
    ".L003C5264:\n"
    "addiu $6, $6, 0x78\n"
    ".word 0x04C00009 /* bltz $6, .L003C5290: raw word */\n"
    "nop\n"
    ".L003C5270:\n"
    "ld $9, 0x0($5)\n"
    "addiu $5, $5, 0x8\n"
    "sd $9, 0x0($4)\n"
    "addiu $6, $6, -0x8\n"
    ".word 0x04C1FFFB\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x04C1FFF9 /* bgez $6, .L003C5270: raw word */\n"
    "nop\n"
    ".L003C5290:\n"
    "addiu $6, $6, 0x8\n"
    ".L003C5294:\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x04C00009 /* bltz $6, .L003C52C0: raw word */\n"
    "nop\n"
    ".L003C52A0:\n"
    "addiu $6, $6, -0x1\n"
    "lbu $9, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $9, 0x0($4)\n"
    ".word 0x04C1FFFB\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x04C1FFF9 /* bgez $6, .L003C52A0: raw word */\n"
    "nop\n"
    ".L003C52C0:\n"
    "jr $31\n"
    "nop\n"
    ".size func_003C51E8, . - func_003C51E8\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C52C8);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written byte-align head of the memcpy above (jumps back into func_003C51E8 once the destination is 16-byte aligned); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003C52C8\n.type func_003C52C8, @function\nfunc_003C52C8:\n"
    "andi $8, $4, 0xF\n"
    "beqz $8, .L003C51FC\n"
    "nop\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x18C00005 /* blez $6, .L003C52F0: raw word */\n"
    "lbu $9, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $9, 0x0($4)\n"
    "j func_003C52C8\n"
    "addiu $4, $4, 0x1\n"
    ".L003C52F0:\n"
    "jr $31\n"
    "nop\n"
    ".size func_003C52C8, . - func_003C52C8\n"
    ".set pop\n");
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C52F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C52F8(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(short *)(sp + 0x28) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5330);
#ifdef SKIP_ASM
extern void func_003B4DD8(void *);

int func_003C5330(int *arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *arg0 = *(unsigned short *)(sp + 0x28);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5368);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5368(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(signed char *)(sp + 0x46) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C53A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C53A0(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(signed char *)(sp + 0x3C) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C53D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C53D8(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(int *)(sp + 0x24) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5410);
#ifdef SKIP_ASM
extern void func_003B4FC0(void *);

int func_003C5410(float f) {
    char buf[0xE0];

    if (f >= 0.0f) {
        f = 1000.0f / f;
    }
    func_003B4DD8(buf);
    *(float *)(buf + 0x34) = f;
    func_003B4FC0(buf);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5468);
#ifdef SKIP_ASM
int func_003C5468(float *a0) {
    char buf[0xE0];
    float f;

    func_003B4DD8(buf);
    f = *(float *)(buf + 0x34);
    *a0 = f;
    if (f >= 0.0f) {
        *a0 = 1000.0f / f;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C54C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003B4DD8_i(void *) __asm__("func_003B4DD8");
int func_003C54C0(unsigned int kind, int *out) {
    unsigned char info[0xE0];
    *out = 0;
    func_003B4DD8_i(info);
    switch (kind) {
    case 1:
        if (info[5] >= 2U) {
            *out = 1;
        }
        break;
    case 0:
    case 4:
    case 5:
    case 8:
        *out = 1;
        break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5538);
#ifdef SKIP_ASM
extern char D_004958C8[];
extern char D_004958D0[];
extern char D_004958D8[];
extern char D_004958E0[];
extern char D_004958E8[];
extern char D_004958F0[];
extern char D_004958F8[];
extern char D_00495910[];
extern char D_00495920[];

int func_003C5538(unsigned int kind, char **out) {
    switch (kind) {
    case 0:
        *out = D_004958C8;
        break;
    case 1:
        *out = D_004958D0;
        break;
    case 2:
        *out = D_004958D8;
        break;
    case 3:
        *out = D_004958E0;
        break;
    case 4:
        *out = D_004958E8;
        break;
    case 5:
        *out = D_004958F0;
        break;
    case 6:
        *out = D_004958F8;
        break;
    case 7:
        *out = D_00495910;
        break;
    case 8:
        *out = D_00495920;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5600);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C4_5600[] __asm__("D_0044E1C4");
int func_003C54C0_5600(int, int *) __asm__("func_003C54C0");

int func_003C5600(int arg0) {
    int buf[4];
    func_003C54C0_5600(arg0, buf);
    if (buf[0] == 0) {
        return -5;
    }
    D_0044E1C4_5600[0] = arg0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5648);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C4_5648[4] __asm__("D_0044E1C4");

int func_003C5648(int *arg0) {
    *arg0 = D_0044E1C4_5648[0];
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5660);
#ifdef SKIP_ASM
extern int func_003B4DD8_5660(void *) __asm__("func_003B4DD8");

int func_003C5660(int mode, int rate, int *out) {
    char sp[0xE0];
    func_003B4DD8_5660(sp);
    switch (mode) {
    case 0:
        if (rate <= 24000) {
            *out = 24000;
        } else if (rate <= 36000) {
            *out = 36000;
        } else {
            *out = 48000;
        }
        break;
    case 1:
        if (rate <= 24000) {
            *out = 24000;
        } else if (rate <= 36000) {
            *out = 36000;
        } else {
            *out = 48000;
        }
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5710);
#ifdef SKIP_ASM
extern int func_003B4DD8_5710(void *) __asm__("func_003B4DD8");


int func_003C5710(int arg0, int arg1) {
    char buf[0xE0];
    func_003B4DD8_5710(buf);
    { int lim = 0xFFFF; arg1 = arg1 > lim ? lim : arg1; }
    *(short *)(buf + 0x2A) = arg1 & 0xFF;
    switch (arg0) {
    case 0:
        *(short *)(buf + 0x2A) = arg1;
        break;
    case 1:
        *(short *)(buf + 0x2C) = arg1;
        break;
    default:
        return -5;
    }
    func_003B4FC0(buf);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5788);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct Buf_5788 { char pad[0x2A]; unsigned short a; unsigned short b; char rest[0xE0 - 0x2E]; } Buf_5788;
extern void func_003B4DD8_5788(Buf_5788 *) __asm__("func_003B4DD8");

int func_003C5788(int arg0, int *arg1) {
    Buf_5788 sp;

    *arg1 = 0;
    func_003B4DD8_5788(&sp);
    switch (arg0) {
    case 0:
        *arg1 = sp.a;
        break;
    case 1:
        *arg1 = sp.b;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C57F0);
#ifdef SKIP_ASM
extern int func_003B4DD8_57F0(void *) __asm__("func_003B4DD8");

int func_003C57F0(int which, int *out) {
    char sp[0xE0];
    *out = 0;
    func_003B4DD8_57F0(sp);
    switch (which) {
    case 0:
        *out = *(unsigned char *)(sp + 6);
        break;
    case 1:
        *out = *(unsigned char *)(sp + 7);
        break;
    case 2:
        *out = *(unsigned char *)(sp + 8);
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5880);
#ifdef SKIP_ASM
extern int func_003B4DD8_5880(void *) __asm__("func_003B4DD8");

int func_003C5880(int which, int val) {
    char sp[0xE0];
    func_003B4DD8_5880(sp);
    switch (which) {
    case 0:
        sp[0x2E] = val;
        break;
    case 1:
        sp[0x2F] = val;
        break;
    case 2:
        sp[0x30] = val;
        break;
    default:
        return -5;
    }
    func_003B4FC0(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5908);
#ifdef SKIP_ASM
extern int func_003B4DD8_5908(void *) __asm__("func_003B4DD8");

int func_003C5908(int which, int *out) {
    char sp[0xE0];
    func_003B4DD8_5908(sp);
    switch (which) {
    case 0:
        *out = *(unsigned char *)(sp + 0x2E);
        break;
    case 1:
        *out = *(unsigned char *)(sp + 0x2F);
        break;
    case 2:
        *out = *(unsigned char *)(sp + 0x30);
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5998);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5998(int arg0, float f) {
    char sp[0xE0];
    func_003B4DD8(sp);
    switch (arg0) {
    case 0:
        *(signed char *)(sp + 0x40) = (int)(f * 100.0f);
        break;
    case 1:
        *(signed char *)(sp + 0x41) = (int)(f * 100.0f);
        break;
    default:
        return -5;
    }
    func_003B4FC0(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5A28);
#ifdef SKIP_ASM

int func_003C5A28(int arg0, float *out) {
    char sp[0xE0];
    func_003B4DD8(sp);
    switch (arg0) {
    case 0:
        *out = *(unsigned char *)(sp + 0x40) * 0.01f;
        break;
    case 1:
        *out = *(unsigned char *)(sp + 0x41) * 0.01f;
        break;
    default:
        return -5;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AA0);
#ifdef SKIP_ASM
int func_003C5AA0(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AA8);
#ifdef SKIP_ASM
int func_003C5AA8(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AB0);
#ifdef SKIP_ASM
int func_003C5AB0(void) {
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AB8);
#ifdef SKIP_ASM
int func_003C5AB8(void) {
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5AC0(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(signed char *)(sp + 0x3F) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5AF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5AF8(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(int *)(sp + 0x6C) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5B30);
#ifdef SKIP_ASM
typedef struct { char pad[0x4A]; signed char v; char pad2[0xE0 - 0x4B]; } S_5B30;
extern void func_003B4FC0(void *);

int func_003C5B30(float f) {
    S_5B30 s;
    func_003B4DD8(&s);
    s.v = (int)(f * 100.0f);
    func_003B4FC0(&s);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5B80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5B80(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(signed char *)(sp + 0x42) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BB8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5BB8(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(signed char *)(sp + 0x43) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BF0);
#ifdef SKIP_ASM
int func_003C5BF0(void) {
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5BF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5BF8(int arg0) {
    char sp[0xE0];
    func_003B4DD8(sp);
    *(int *)(sp + 0xC8) = arg0;
    func_003B4FC0(sp);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5C30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003B4FC0_i(void *) __asm__("func_003B4FC0");
extern int func_003B5158(int, int, int);
extern int D_0044E1C0;
extern unsigned int D_0044E1C4;
extern int D_005157B0;

struct sInfo_5C30 {
    char pad0[0x2A];
    unsigned short w2A;
    unsigned short w2C;
    char pad2E;
    unsigned char b2F;
    char pad30[0x47 - 0x30];
    signed char f47;
    signed char f48;
    signed char f49;
    char pad4A[2];
    unsigned char n;
    char pad4D;
    short list[8];
    char tail[0xE0 - 0x5E];
};

int func_003C5C30(int arg0) {
    struct sInfo_5C30 info;
    int t;
    int ia;

    func_003B4DD8(&info);
    info.n = 0;
    if (D_0044E1C4 == 8) {
        info.list[0] = 0x44;
        info.n = 1;
    }
    info.list[info.n] = 0x24;
    info.n += 1;
    if (info.b2F != 0) {
        if (D_0044E1C4 == 8) {
            info.list[info.n] = 0x140;
            info.n += 1;
        }
        info.list[info.n] = 0x120;
        info.n += 1;
    }
    if (D_0044E1C4 == 8) {
        info.list[info.n] = 0x48;
        info.n += 1;
    }
    info.list[info.n] = 0x28;
    info.f49 = 1;
    info.f48 = 0;
    info.n += 1;
    switch (D_0044E1C4) {
    case 0:
        info.f47 = 1;
        break;
    case 4:
        info.f47 = 4;
        info.f49 = 2;
        break;
    case 5:
        info.f47 = 5;
        info.f49 = 2;
        break;
    case 1:
    case 8:
        info.f47 = 2;
        break;
    }
    ia = info.w2A;
    t = ia & 0xFFFF;
    if (t != info.w2C && (t != 0x8CA0 || info.w2C != 0x5DC0)) {
        info.w2C = ia;
    }
    func_003B4FC0_i(&info);
    func_003B5158(D_0044E1C0, D_005157B0, arg0);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5DF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C5DF0(void) {
    return D_0050AA5C == 1;

}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C0_5E08[] __asm__("D_0044E1C0");
int func_003B5320(void);
int func_003C5E08_5E08(void) __asm__("func_003C5E08");
int func_003C5E08_5E08(void) {
    func_003B5320();
    D_0044E1C0_5E08[0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044E1C0_5E30[] __asm__("D_0044E1C0");
extern int D_005157B0_5E30[] __asm__("D_005157B0");
int func_003C5E30(int a, int b, int c) {
    if (a == 0) {
        D_0044E1C0_5E30[0] = b;
        D_005157B0_5E30[0] = c;
        return 0;
    }
    return -5;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C5E58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C5DF0();
extern int D_0044E1C0_5E58[] __asm__("D_0044E1C0");
extern int D_005157B0_5E58[] __asm__("D_005157B0");

int func_003C5E58(int arg0, int *arg1, int *arg2) {
    *arg1 = 0;
    *arg2 = 0;
    if (arg0 == 0) {
        if (func_003C5DF0() == 0) {
            return -4;
        }
        *arg1 = D_0044E1C0_5E58[0];
        *arg2 = D_005157B0_5E58[0];
    } else {
        return -5;
    }
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5ED0);
#ifdef SKIP_ASM
typedef struct { char pad0[0x64]; int a; int b; char pad1[0xE0 - 0x6C]; } S_5ED0;
extern void func_003B4FC0(void *);

int func_003C5ED0(int arg0, int arg1) {
    S_5ED0 s;
    func_003B4DD8(&s);
    s.a = arg0;
    s.b = arg1;
    func_003B4FC0(&s);
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5F18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003B4FC0_5F18(char *) __asm__("func_003B4FC0");

int func_003C5F18(int arg0, float f) {
    char buf[0xE0];
    if (arg0 == 0) {
        func_003B4DD8(buf);
        buf[0x4B] = (int)(f * 100.0f);
        func_003B4FC0_5F18(buf);
        return 0;
    }
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5F70);
#ifdef SKIP_ASM
extern void func_003B4DD8(void *);

int func_003C5F70(int arg0, float *arg1) {
    unsigned char buf[0xE0];

    *arg1 = 0.0f;
    if (arg0 == 0) {
        func_003B4DD8(buf);
        *arg1 = (float)buf[0x4B] * 0.01f;
        return 0;
    }
    return -5;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C5FD0);
#ifdef SKIP_ASM
typedef struct { char pad0[0xCC]; int a; int b; char pad1[0xE0 - 0xD4]; } S_5FD0;
extern void func_003B4FC0(void *);

int func_003C5FD0(int arg0, int arg1) {
    S_5FD0 s;
    func_003B4DD8(&s);
    s.a = arg0;
    s.b = arg1;
    func_003B4FC0(&s);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C6018(void (*a)(void)) {
    D_0050A8E8.f19C[D_0050A8E8.f178] = a;
    D_0050A8E8.f178 = D_0050A8E8.f178 + 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6040);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003C6040(void (*arg0)(void)) {
    int i;

    for (i = 0; i < D_0050A8E8.f178; i++) {
        if (D_0050A8E8.f19C[i] == arg0) {
            D_0050A8E8.f178--;
            while (i < D_0050A8E8.f178) {
                D_0050A8E8.f19C[i] = D_0050A8E8.f19C[i + 1];
                i++;
            }
            return;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C60E0);
#ifdef SKIP_ASM

void func_003C60E0(void) {
    int i;
    if (D_0050A8E8.f174 != 0) {
        for (i = 0; i < D_0050A8E8.f178; i++) {
            D_0050A8E8.f19C[i]();
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6158);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6240);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C6240(void) {
    int temp_3;

    temp_3 = D_0050AB1C->f08;
    return (temp_3 - D_0050AB1C->f10) * 100 / temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6278);
#ifdef SKIP_ASM
void func_003C6278(void *arg0) {
    *(int *)((char *)arg0 + 0) = 0;
    *(int *)((char *)arg0 + 4) = 0;
    *(int *)((char *)arg0 + 8) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6288);
#ifdef SKIP_ASM
void func_003C6288(void *arg0, void *arg1) {
    void *temp_2;

    (*(void **)((char*)(arg1) + (0))) = (void *) (*(void **)((char*)(arg0) + (0)));
    (*(int *)((char*)(arg1) + (4))) = 0;
    temp_2 = (*(void **)((char*)(arg0) + (0)));
    if (temp_2 != 0) {
        (*(void **)((char*)(temp_2) + (4))) = arg1;
    } else {
        (*(void **)((char*)(arg0) + (4))) = arg1;
    }
    (*(void **)((char*)(arg0) + (0))) = arg1;
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C62B8);
#ifdef SKIP_ASM
void func_003C62B8(void *arg0, int *arg1) {
    int *temp_2;

    (*(int **)((char*)(arg1) + (0))) = 0;
    (*(int **)((char*)(arg1) + (4))) = (int *) (*(int **)((char*)(arg0) + (4)));
    temp_2 = (*(int **)((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        *temp_2 = (int)arg1;
    } else {
        (*(int **)((char*)(arg0) + (0))) = arg1;
    }
    (*(int **)((char*)(arg0) + (4))) = arg1;
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) + 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C62E8);
#ifdef SKIP_ASM
int *func_003C62E8(void *arg0) {
    int *temp_2;
    int *temp_3;

    temp_3 = (*(int **)((char*)(arg0) + (0)));
    if (temp_3 != 0) {
        temp_2 = *temp_3;
        (*(int **)((char*)(arg0) + (0))) = temp_2;
        if (temp_2 == 0) {
            (*(int *)((char*)(arg0) + (4))) = 0;
        } else {
            (*(int *)((char*)(temp_2) + (4))) = 0;
        }
        (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) - 1);
    }
    return temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6320);
#ifdef SKIP_ASM
void func_003C6320(void *arg0, void *arg1) {
    void **temp_3;
    void *temp_3_2;

    if (arg1 == (*(void **)((char*)(arg0) + (0)))) {
        (*(void **)((char*)(arg0) + (0))) = (void *) (*(void **)((char*)(arg1) + (0)));
    }
    if (arg1 == (*(void ***)((char*)(arg0) + (4)))) {
        (*(void ***)((char*)(arg0) + (4))) = (void **) (*(void ***)((char*)(arg1) + (4)));
    }
    temp_3 = (*(void ***)((char*)(arg1) + (4)));
    if (temp_3 != 0) {
        *temp_3 = (*(void **)((char*)(arg1) + (0)));
    }
    temp_3_2 = (*(void **)((char*)(arg1) + (0)));
    if (temp_3_2 != 0) {
        (*(void ***)((char*)(temp_3_2) + (4))) = (void **) (*(void ***)((char*)(arg1) + (4)));
    }
    (*(int *)((char*)(arg0) + (8))) = (int) ((*(int *)((char*)(arg0) + (8))) - 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6380);
#ifdef SKIP_ASM
typedef struct { unsigned int lo, hi; } L64_6380;
extern unsigned long f14D0_6380(unsigned long, unsigned long) __asm__("func_004114D0");

L64_6380 func_003C6380(unsigned int a, unsigned int b) {
    unsigned long al = a & 0xFFFF;
    unsigned long bl = b & 0xFFFF;
    unsigned long ah = (a >> 16) & 0xFFFF;
    unsigned long bh = (b >> 16) & 0xFFFF;
    unsigned long ll, lh, hl, hh, mid;
    L64_6380 t;
    L64_6380 r;
    ll = f14D0_6380(al, bl);
    lh = f14D0_6380(al, bh);
    hl = f14D0_6380(ah, bl);
    hh = f14D0_6380(ah, bh);
    mid = (ll >> 16) + (lh & 0xFFFF) + (hl & 0xFFFF);
    t.lo = ll + (lh << 16) + (hl << 16);
    t.hi = (lh >> 16) + (hl >> 16) + hh + (mid >> 16);
    r = t;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C64A8);
#ifdef SKIP_ASM
struct U64_64A8 { unsigned int lo, hi; };
unsigned int func_003C64A8(struct U64_64A8 n, unsigned int d) {
    unsigned int q = 0;
    unsigned int lo = n.lo;
    unsigned int r = n.hi;
    int i;
    for (i = 31; i >= 0; i--) {
        unsigned int c = lo >> 31;
        r <<= 1;
        r += c;
        q <<= 1;
        lo <<= 1;
        if (r >= d) {
            r -= d;
            q++;
        }
    }
    return q;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6500);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003C6500(void) {
    int i;
    for (i = 0; i < D_0050A8E8.setup.cfg.f08; i++) {
        if (D_0050A8E8.f1F4[i].f00 == 0) {
            return i;
        }
    }
    return -9;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6540);
#ifdef SKIP_ASM
void *func_003C6540(char *arg0, int arg1) {
    int temp_3;

    if (arg1 >= *(unsigned short *)(arg0 + 6)) {
        return 0;
    }
    temp_3 = *(int *)(arg0 + (arg1 << 2) + 0x14);
    if (temp_3 == 0) {
        return 0;
    }
    return arg0 + ((arg1 << 2) + 0x14) + temp_3;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6580);
#ifdef SKIP_ASM
int func_003C6580(int arg0, int arg1) {
    int i;
    int best = -1;
    int bi = -1;
    for (i = 0; i < arg1; i++) {
        if (best < D_0050AAD8[arg0].f04[i]) {
            best = D_0050AAD8[arg0].f04[i];
            bi = i;
        }
    }
    return bi;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C65E0);
#ifdef SKIP_ASM
int func_003C65E0(int arg0) {
    return (arg0 << 5) + 0x9C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C65F0);
#ifdef SKIP_ASM
int func_003CE198(void);
int func_003C65F0(int arg0) {
    int t = func_003C65E0(arg0);
    return t + func_003CE198();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C6620);

INCLUDE_ASM("ealib/seg_2B4578", func_003C6760);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6AB8);
#ifdef SKIP_ASM
/* 97.69: only missing "move $5,$2" copy of lbu result before loop (n vs r pseudo); volatile f48/f46/f4/f40/a[] needed */
struct A_6AB8 { char pad0[4]; unsigned int sz : 31; unsigned int flag : 1; char pad8[4]; int w[6]; };

int func_003C6AB8(int arg0, struct A_6AB8 *arg1)
{
  struct s7B8Queue *s = D_005157B8.f304[arg0];
  struct s7B8Rec *e;
  int i;
  int r;
  for (i = 0; i < s->f62; i++)
  {
    if (s->f34[i] >= s->f40 - 1)
    {
      r = -13;
      goto done;
    }
  }

  e = &s->f7C[s->f46];
  e->len = arg1->sz;
  e->flag = arg1->flag;
  e->f00 = s->f04;
  for (i = 0; i < s->f62; i++)
  {
    e->f08[i] = arg1->w[i];
    s->f34[i] += 1;
  }

  s->f48 += arg1->sz;
  r = s->f04;
  s->f04 = s->f04 + 1;
  s->f46 = s->f46 + 1;
  if (s->f46 >= s->f40)
  {
    s->f46 = 0;
  }
  done:
  return r;

}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6C28);
#ifdef SKIP_ASM
int func_003C6C28(int arg0) {
    struct s7B8Queue *e = D_005157B8.f304[arg0];
    int m = 0;
    int i;
    for (i = 0; i < e->f62; i++) {
        if (!(e->f34[i] < m))
            m = e->f34[i];
    }
    return e->f40 - m - 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6C98);
#ifdef SKIP_ASM
int func_003C6C98(int i) {
    struct s7B8Queue *q = D_005157B8.f304[i];
    return q->f48 + q->f4C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CC0);
#ifdef SKIP_ASM
int func_003C6CC0(int i) {
    return D_005157B8.f304[i]->f4C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CE0);
#ifdef SKIP_ASM
int func_003C6CE0(void) {
    return -0xF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6CE8);
#ifdef SKIP_ASM
extern void f_89E0_6CE8(int) __asm__("func_003B89E0");
extern void func_003C7080(void);
extern int f_6CE0_6CE8(int, int, int) __asm__("func_003C6CE0");

int func_003C6CE8(int arg0) {
    struct s7B8Queue *e = D_005157B8.f304[arg0];
    int i = 0;

    f_89E0_6CE8(e->f00);
    func_003C7080();
    f_6CE0_6CE8(arg0, 0, 0x7FFFFFFF);
    e->f00 = -1;

    for (; i < e->f62; i++) {
        if (e->f64[i]) func_003B5E98(e->f64[i]);

    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6DA0);
#ifdef SKIP_ASM
int func_003CE1A8(void);

int func_003C6DA0(int arg0) {
    func_003CE1A8();
    D_005157B8.f304[arg0] = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C6DE0);
#ifdef SKIP_ASM
unsigned int func_003C6DE0(int id, int r, int *len, int *flag) {
    struct s7B8Queue *q;
    struct s7B8Rec *e;
    struct s7B8Event *ev;
    int ok, ok2, i;
    unsigned int v;

    ok = 1;
    q = D_005157B8.f304[id];
    ok2 = 1;
    for (i = 0; i < q->f62; i++) {
        if (q->f10[i] <= q->f08) {
            ok = 0;
        }
    }
    if (ok) {
        struct s7B8Rec *w = &q->f7C[q->f44];
        if (q->f54) {
            ev = &D_005157B8.f004[D_005157B8.f000];
            ev->f00 = 1;
            ev->f02 = id;
            ev->f04 = w->f08[0];
            D_005157B8.f000++;
        }
        q->f44++;
        q->f08++;
        if (q->f44 >= q->f40) {
            q->f44 = 0;
        }
    }
    if (q->f34[r] == 0) {
        return 0;
    }
    e = &q->f7C[q->f28[r]];
    *len = e->len;
    *flag = e->flag;
    q->f28[r]++;
    q->f10[r]++;
    i = 0;
    do {
        if (q->f10[i] <= q->f0C) {
            ok2 = 0;
        }
        i++;
    } while (ok2 == 1 && i < q->f62);
    if (ok2) {
        q->f0C++;
        q->f48 -= e->len;
        q->f4C += e->len;
    }
    if (q->f28[r] >= q->f40) {
        q->f28[r] = 0;
    }
    q->f34[r]--;
    v = e->f08[r];
    return v ? v : 0xFFFFFFFF;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7010);
#ifdef SKIP_ASM
void func_003C7010(int id, int b, int c)
{
    struct s7B8Queue* o = D_005157B8.f304[id];
    if (b == (signed char)o->f42) {

        o->f4C -= c;
        if (o->f58) {
            struct s7B8Event* e = &D_005157B8.f004[D_005157B8.f000];
            e->f04 = c;
            e->f02 = id;
            e->f00 = 0;
            D_005157B8.f000++;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7080);
#ifdef SKIP_ASM
void func_003C7080(void) {
    int i;
    for (i = 0; i < D_005157B8.f000; i++) {
        struct s7B8Event *n = &D_005157B8.f004[i];
        struct s7B8Queue *o = D_005157B8.f304[n->f02];
        if (n->f00 == 0) {
            o->f58(n->f02, n->f04, o->f5C);
        } else {
            o->f54(n->f04, o->f5C);
        }
    }
    D_005157B8.f000 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int fA6E8_7138(void) __asm__("func_003BA6E8");
extern int func_003BAA00(int, int *);
extern int func_003C2440(int);

int func_003C7138(void) {
    int sp0;
    int r = fA6E8_7138();
    if (r >= 0) {
        sp0 = -1;
        while (func_003BAA00(r, &sp0) != 0) {
            struct sA8E8Chan *e = &D_0050A8E8.f1F0[sp0];
            signed char t = e->f5E;
            if (t < 0) {
                func_003C2440(sp0);
            } else if (e->f5D < t) {
                struct sA8E8Env *q;
                int d;
                e->f5D = e->f5E;
                q = (struct sA8E8Env *)(t * 8 + (int)e->f6C);
                d = q->f00;
                e->f44 = d;
                e->f3C = ((q->f04 << 16) - e->f40) / d;
            }
        }
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7218);
#ifdef SKIP_ASM
struct S7218 { short s0; char b2, b3, b4, b5, b6, b7; short s8; short sA; short sC[6]; int i18[6]; char pad[0x48 - 0x30]; int a48[4]; int a58[4]; };

int func_003C7218(struct S7218 *p) {
    int i;
    p->b3 = 0x7F;
    p->b4 = 0x40;
    p->s8 = 8;
    p->b2 = 0;
    p->s0 = 0;
    p->b5 = 0;
    p->b6 = 0;
    p->b7 = 0;
    for (i = 0; i < 4; i++) {
        p->a48[i] = 0;
        p->a58[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        p->sC[i] = 0;
        p->i18[i] = 0;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C72A0);
#ifdef SKIP_ASM
int func_003C72A0(int arg0) {
    if (arg0 > 0x10000) {
        arg0 = 0x10000;
    } else {
        arg0 = (arg0 <= -1) ? 0 : arg0;
    }
    return (int)(((func_003BC5C8() & 0x7FFF) - 0x4000) * arg0) >> 0xE;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C72F8);
#ifdef SKIP_ASM
int f_72F8_72F8(unsigned char *, int) __asm__("func_003C72F8");
int f_72F8_72F8(unsigned char *p, int n) {
    int v = 0;
    int i = n;
    int ext;
    while (i--) {
        v = (v << 8) + *p++;
    }
    if (n == 1 && v >= 0x80) {
        v -= 0x100;
    } else {
        if (n == 2 && v > 0x7FFF) {
            ext = 0xFFFF0000;
            v += ext;
        } else if (n == 3 && v > 0x7FFFFF) {
            ext = 0xFF000000;
            v += ext;
        }
    }
    return v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7388);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_7388 {
    unsigned char *p;
    unsigned cur;
    int r8;
    unsigned char *c;
    unsigned len;
};
extern unsigned func_003C72F8_7388(unsigned char *, unsigned) __asm__("func_003C72F8");

int func_003C7388(struct S_7388 *s) {
    unsigned char *p = s->p;
    unsigned char *q, *r;
    unsigned cur, len;
    if (*p == 0xFC) {
        do {
            q = p;
            s->p = q + 1;
            p = q + 1;
        } while (q[1] == 0xFC);
    }
    r = s->p;
    cur = *r;
    s->cur = cur;
    if (cur == 0xFF) {
        return 0;
    }
    s->p = r + 1;
    if (cur == 0xFD) {
        return 1;
    }
    if (cur == 0xFE) {
        return 1;
    }
    len = r[1];
    s->len = len;
    if (len == 0xFF) {
        s->len = func_003C72F8_7388(r + 2, 4);
        s->p = s->p + 4;
    }
    s->p = s->p + 1;
    s->c = s->p;
    if (s->len < 5) {
        s->r8 = func_003C72F8_7388(s->p, s->len);
    }
    s->p = s->p + s->len;
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7480);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S24_7480 { int w[6]; };
struct S16_7480 { int w[4]; };
struct T_7480 { struct S24_7480 a, b, c, d, e; struct S16_7480 f; int pad[2]; struct S16_7480 g; };
extern struct T_7480 D_0050AB20_7480 __asm__("D_0050AB20");
extern struct S24_7480 D_0044E1C8_7480 __asm__("D_0044E1C8");
extern struct S24_7480 D_0044E1E0_7480 __asm__("D_0044E1E0");
extern struct S24_7480 D_0044E1F8_7480 __asm__("D_0044E1F8");
extern struct S24_7480 D_0044E210_7480 __asm__("D_0044E210");
extern struct S24_7480 D_0044E228_7480 __asm__("D_0044E228");
extern struct S16_7480 D_0044E240_7480 __asm__("D_0044E240");
extern struct S16_7480 D_0044E250_7480 __asm__("D_0044E250");

void func_003C7480(void) {
    D_0050AB20_7480.a = D_0044E1C8_7480;
    D_0050AB20_7480.b = D_0044E1E0_7480;
    D_0050AB20_7480.c = D_0044E1F8_7480;
    D_0050AB20_7480.d = D_0044E210_7480;
    D_0050AB20_7480.e = D_0044E228_7480;
    D_0050AB20_7480.f = D_0044E240_7480;
    D_0050AB20_7480.g = D_0044E250_7480;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7600);
#ifdef SKIP_ASM
void func_003C7600(float *arg0, void *arg1) {
    (*(float *)((char*)(arg1) + (0))) = (float) ((*(float *)((char*)(arg1) + (0))) + (*arg0 * 0.9411765f));
    (*(float *)((char*)(arg1) + (4))) = (float) ((*(float *)((char*)(arg1) + (4))) + (*arg0 * 0.88235295f));
    (*(float *)((char*)(arg1) + (8))) = (float) ((*(float *)((char*)(arg1) + (8))) + (*arg0 * 0.8235294f));
    (*(float *)((char*)(arg1) + (0xC))) = (float) ((*(float *)((char*)(arg1) + (0xC))) + (*arg0 * 0.7647059f));
    (*(float *)((char*)(arg1) + (0x10))) = (float) ((*(float *)((char*)(arg1) + (0x10))) + (*arg0 * 0.7058824f));
    (*(float *)((char*)(arg1) + (0x14))) = (float) ((*(float *)((char*)(arg1) + (0x14))) + (*arg0 * 0.64705884f));
    (*(float *)((char*)(arg1) + (0x18))) = (float) ((*(float *)((char*)(arg1) + (0x18))) + (*arg0 * 0.5882353f));
    (*(float *)((char*)(arg1) + (0x1C))) = (float) ((*(float *)((char*)(arg1) + (0x1C))) + (*arg0 * 0.5294118f));
    (*(float *)((char*)(arg1) + (0x20))) = (float) ((*(float *)((char*)(arg1) + (0x20))) + (*arg0 * 0.47058824f));
    (*(float *)((char*)(arg1) + (0x24))) = (float) ((*(float *)((char*)(arg1) + (0x24))) + (*arg0 * 0.4117647f));
    (*(float *)((char*)(arg1) + (0x28))) = (float) ((*(float *)((char*)(arg1) + (0x28))) + (*arg0 * 0.3529412f));
    (*(float *)((char*)(arg1) + (0x2C))) = (float) ((*(float *)((char*)(arg1) + (0x2C))) + (*arg0 * 0.29411766f));
    (*(float *)((char*)(arg1) + (0x30))) = (float) ((*(float *)((char*)(arg1) + (0x30))) + (*arg0 * 0.23529412f));
    (*(float *)((char*)(arg1) + (0x34))) = (float) ((*(float *)((char*)(arg1) + (0x34))) + (*arg0 * 0.1764706f));
    (*(float *)((char*)(arg1) + (0x38))) = (float) ((*(float *)((char*)(arg1) + (0x38))) + (*arg0 * 0.11764706f));
    (*(float *)((char*)(arg1) + (0x3C))) = (float) ((*(float *)((char*)(arg1) + (0x3C))) + (*arg0 * 0.05882353f));
    *arg0 = 0.0f;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7828);
#ifdef SKIP_ASM
void func_003C7828(void *arg0, void *arg1, float fparg0, float fparg1) {
    float temp_f13;

    temp_f13 = (fparg1 - fparg0) * 0.05882353f;
    (*(float *)((char*)(arg1) + (0))) = (float) ((*(float *)((char*)(arg1) + (0))) + ((*(float *)((char*)(arg0) + (0))) * (fparg0 + temp_f13)));
    (*(float *)((char*)(arg1) + (4))) = (float) ((*(float *)((char*)(arg1) + (4))) + ((*(float *)((char*)(arg0) + (4))) * (fparg0 + (2.0f * temp_f13))));
    (*(float *)((char*)(arg1) + (8))) = (float) ((*(float *)((char*)(arg1) + (8))) + ((*(float *)((char*)(arg0) + (8))) * (fparg0 + (temp_f13 * 3.0f))));
    (*(float *)((char*)(arg1) + (0xC))) = (float) ((*(float *)((char*)(arg1) + (0xC))) + ((*(float *)((char*)(arg0) + (0xC))) * (fparg0 + (temp_f13 * 4.0f))));
    (*(float *)((char*)(arg1) + (0x10))) = (float) ((*(float *)((char*)(arg1) + (0x10))) + ((*(float *)((char*)(arg0) + (0x10))) * (fparg0 + (temp_f13 * 5.0f))));
    (*(float *)((char*)(arg1) + (0x14))) = (float) ((*(float *)((char*)(arg1) + (0x14))) + ((*(float *)((char*)(arg0) + (0x14))) * (fparg0 + (temp_f13 * 6.0f))));
    (*(float *)((char*)(arg1) + (0x18))) = (float) ((*(float *)((char*)(arg1) + (0x18))) + ((*(float *)((char*)(arg0) + (0x18))) * (fparg0 + (temp_f13 * 7.0f))));
    (*(float *)((char*)(arg1) + (0x1C))) = (float) ((*(float *)((char*)(arg1) + (0x1C))) + ((*(float *)((char*)(arg0) + (0x1C))) * (fparg0 + (temp_f13 * 8.0f))));
    (*(float *)((char*)(arg1) + (0x20))) = (float) ((*(float *)((char*)(arg1) + (0x20))) + ((*(float *)((char*)(arg0) + (0x20))) * (fparg0 + (temp_f13 * 9.0f))));
    (*(float *)((char*)(arg1) + (0x24))) = (float) ((*(float *)((char*)(arg1) + (0x24))) + ((*(float *)((char*)(arg0) + (0x24))) * (fparg0 + (temp_f13 * 10.0f))));
    (*(float *)((char*)(arg1) + (0x28))) = (float) ((*(float *)((char*)(arg1) + (0x28))) + ((*(float *)((char*)(arg0) + (0x28))) * (fparg0 + (temp_f13 * 11.0f))));
    (*(float *)((char*)(arg1) + (0x2C))) = (float) ((*(float *)((char*)(arg1) + (0x2C))) + ((*(float *)((char*)(arg0) + (0x2C))) * (fparg0 + (temp_f13 * 12.0f))));
    (*(float *)((char*)(arg1) + (0x30))) = (float) ((*(float *)((char*)(arg1) + (0x30))) + ((*(float *)((char*)(arg0) + (0x30))) * (fparg0 + (temp_f13 * 13.0f))));
    (*(float *)((char*)(arg1) + (0x34))) = (float) ((*(float *)((char*)(arg1) + (0x34))) + ((*(float *)((char*)(arg0) + (0x34))) * (fparg0 + (temp_f13 * 14.0f))));
    (*(float *)((char*)(arg1) + (0x38))) = (float) ((*(float *)((char*)(arg1) + (0x38))) + ((*(float *)((char*)(arg0) + (0x38))) * (fparg0 + (temp_f13 * 15.0f))));
    (*(float *)((char*)(arg1) + (0x3C))) = (float) ((*(float *)((char*)(arg1) + (0x3C))) + ((*(float *)((char*)(arg0) + (0x3C))) * (fparg0 + (temp_f13 * 16.0f))));
}
#endif

void func_003C7AA8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7AB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern float D_00515D80_7AB0[] __asm__("D_00515D80");
extern void func_003C7828_7AB0(float *snd, float *name, float from, float to) __asm__("func_003C7828");

int func_003C7AB0(struct sB40Ent *s) {
    int i;

    if (s->f40->f00(s->f40, 0x10, D_00515B40.fB0, D_00515B40.fB4, 0) <= 0) {
        for (i = 0; i < 1; i++) {
            s->f34[i] = s->f38[i];
        }
        for (i = 0; i < D_00515B40.f05; i++) {
            s->f04[i] = s->f1C[i];
        }
        return 0;
    }
    s->f3C = D_00515B40.fB4[15];
    for (i = 0; i < 1; i++) {
        if (D_00515B40.f0F[i] != 0) {
            if (s->f34[i] != s->f38[i]) {
                func_003C7828_7AB0(D_00515B40.fB4, D_00515D80_7AB0, s->f34[i], s->f38[i]);
                s->f34[i] = s->f38[i];
            } else if (s->f38[i] != 0.0f) {
                D_00515B40.f1E0(0x10, D_00515B40.fB4, D_00515D80_7AB0, s->f38[i]);
            }
        }
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        if (s->f04[i] != s->f1C[i]) {
            func_003C7828_7AB0(D_00515B40.fB4, D_00515B40.fD0[i], s->f04[i], s->f1C[i]);
            s->f04[i] = s->f1C[i];
        } else if (s->f1C[i] != 0.0f) {
            D_00515B40.f1E0(0x10, D_00515B40.fB4, D_00515B40.fD0[i], s->f1C[i]);
        }
    }
    return 0x10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7CC0);
#ifdef SKIP_ASM
extern void func_003B5C60();

void func_003C7CC0(void) {
    func_003B5C60();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C7CE0);
#ifdef SKIP_ASM
extern void func_003B5E98();

void func_003C7CE0(void) {
    func_003B5E98();
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C7D00);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_7AA8_8018(float) __asm__("func_003C7AA8");
void func_003C8018(void) {
    int i;
    int v;
    func_003B58A0();
    if (D_00515B40.f1DC) {
        func_003B5E98(D_00515B40.f1DC);
        D_00515B40.f1DC = 0;
    }
    for (i = 0; i < 2; i++) {
        v = D_00515B40.fA8[i];
        if ((v & 0x70000000) == 0x70000000) {
            D_00515B40.fA8[i] = 0;
        } else if (v != 0) {
            func_003B5E98(v);
            D_00515B40.fA8[i] = 0;
        }
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        v = D_00515B40.fB8[i];
        if ((v & 0x70000000) == 0x70000000) {
            D_00515B40.fB8[i] = 0;
        } else if (v != 0) {
            func_003B5E98(v);
            D_00515B40.fB8[i] = 0;
        }
    }
    f_7AA8_8018(2.0f);
    func_003B58D8();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8128);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CBB78_set(int, float *, float *, float) __asm__("func_003CBB78");

void func_003C8128(void) {
    D_00515B40.f1E0 = func_003CBB78_set;
    D_00515B40.f0C = 0x400;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8148);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003C8148(signed char arg0) {
    D_00515B4E = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8158);
#ifdef SKIP_ASM
extern struct sB40Node *func_003B5C60_8158(int) __asm__("func_003B5C60");
extern void func_003C8F48_8158(struct sB40Node **, struct sB40Node *) __asm__("func_003C8F48");
extern void func_003CB280_8158(struct sB40Node *, int, int) __asm__("func_003CB280");

void func_003C8158(int idx, int type, int p2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13) {
    struct sB40Ent *e = &D_00515B40.f1DC[idx];
    struct sB40Init r;
    int k;
    short sel;

    e->f40 = 0;
    e->f48 = 0;
    e->f50 = 0;
    e->f58 = 0;
    e->f5C = 0;
    e->f4C = 0;
    r.f18 = 1;
    r.f28 = 0;
    k = -1;
    if (type == 8) k = 0;
    else if (type == 10) k = 1;
    else if (type == 4) k = 2;
    else if (type == 0x16) k = 3;
    else if (type == 0x10) k = 4;
    else if (type == 0x17) k = 5;
    if (p2 == 1) {
        sel = (a9 < 1) ? 0 : p2;
    } else {
        sel = 2;
        if (p2 != 0) sel = 0;
    }
    if (D_00515B40.f18[k][sel] != 0) {
        e->f48 = func_003B5C60_8158(D_00515B40.f60[k][sel]);
        r.f00 = a3;
        r.f04 = a4;
        r.f08 = a6;
        r.f24 = a12;
        r.f0C = a7;
        r.f10 = a8;
        r.f14 = a9;
        r.f20 = D_0050AA62;
        r.f1C = idx;
        e->f48->f04 = 0;
        e->f48->f18 = 0xF0;
        e->f48->f1A = a13;
        D_00515B40.f18[k][sel](e->f48, &r);
        e->f44 = r.f28;
        func_003C8F48_8158(&e->f40, e->f48);
    }
    if (a5 != 0) {
        if (p2 != 0) idx = -1;
        e->f4C = func_003B5C60_8158(0x1828);
        e->f4C->f04 = 0;
        e->f4C->f18 = 200;
        e->f4C->f1A = a13;
        func_003CB280_8158(e->f4C, a5, idx);
        func_003C8F48_8158(&e->f40, e->f4C);
    }
    e->f00 = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C83A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C83A0(int arg0) {
    struct sB40Ent *e = &D_00515B40.f1DC[arg0];
    int i;

    e->f3C = 0.0f;
    e->f01 = 0;
    for (i = 0; i < 1; i++) {
        e->f34[i] = e->f38[i];
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        e->f04[i] = e->f1C[i];
    }
    e->f00 = 2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8430);
#ifdef SKIP_ASM
extern void func_003C8468();

void func_003C8430(int arg0) {
    func_003C8468();
    D_00515B48(arg0);

}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8468);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003B5E98_8468(struct sB40Node *) __asm__("func_003B5E98");

void func_003C8468(int idx) {
    struct sB40Ent *e = &D_00515B40.f1DC[idx];
    int i;
    struct sB40Node *nd;
    struct sB40Node *next;
    for (i = 0; i < 1; i++) {
        D_00515B40.f100[i] += e->f34[i] * e->f3C;
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        D_00515B40.fE8[i] += e->f04[i] * e->f3C;
    }
    do {
        if (e->f40->f04 != 0) {
            e->f40->f04(e->f40);
        }
        nd = e->f40;
        next = nd->f08;
        func_003B5E98_8468(nd);
        e->f40 = next;
    } while (next != 0);
    e->f00 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8560);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C8560(int idx, int k, float f) {
    D_00515B40.f1DC[idx].f1C[k] = f;
    D_00515B40.f1DC[idx].f01 = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8598);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C8598(int idx, int k, float f) {
    D_00515B40.f1DC[idx].f38[k] = f;
    D_00515B40.f1DC[idx].f01 = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C85D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern float D_00515D80_85D0[] __asm__("D_00515D80");
extern void f6210_85D0(void *, int, int) __asm__("func_00416210");
extern void func_003C8430(int);

void func_003C85D0(int *outs, int n) {
    struct sB40Ent *e;
    int i;
    int j;
    int k;
    int m;
    int r;

    for (i = 0; i < 1; i++) {
        if (D_00515B40.f0F[i] != 0 && D_00515B40.f100[i] != 0.0f) {
            func_003C7600(&D_00515B40.f100[i], D_00515D80_85D0);
        }
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        f6210_85D0(D_00515B40.fD0[i], 0, n * 4);
        if (D_00515B40.fE8[i] != 0.0f) {
            func_003C7600(&D_00515B40.fE8[i], D_00515B40.fD0[i]);
        }
    }
    for (j = 0; j < D_00515B40.f04; j++) {
        e = &D_00515B40.f1DC[j];
        if (e->f00 == 2) {
            if (e->f01 != 0) {
                k = func_003C7AB0(e);
                e->f01 = 0;
                m = n - k;
            } else {
                k = 0;
                m = n;
            }
            if (m != 0) {
                r = e->f40->f00(e->f40, m, D_00515B40.fB0, D_00515B40.fB4, 0);
                if (r < 0) {
                    func_003C8430(j);
                } else if (r != 0) {
                    e->f3C = D_00515B40.fB4[r - 1];
                    for (i = 0; i < D_00515B40.f05; i++) {
                        if (e->f1C[i] != 0.0f) {
                            D_00515B40.f1E0(r, D_00515B40.fB4, D_00515B40.fD0[i] + k, e->f1C[i]);
                        }
                    }
                    for (i = 0; i < 1; i++) {
                        if (D_00515B40.f0F[i] != 0 && e->f38[i] != 0.0f) {
                            D_00515B40.f1E0(r, D_00515B40.fB4, D_00515D80_85D0 + k, e->f38[i]);
                            *(int *)((char *)D_00515D80_85D0 + 0x1800) = 0;
                        }
                    }
                }
            }
        }
    }
    if (D_00515B40.f10 != 0) {
        D_00515B40.f10(n);
    }
    for (i = 0; i < D_00515B40.f05; i++) {
        if (D_00515B40.f11C[i] != 0) {
            D_00515B40.f11C[i]->f00(D_00515B40.f11C[i], n, (int)D_00515B40.fD0[i], (float *)D_00515B40.fB0, 0);
            D_00515B40.f104[i]->f00(D_00515B40.f104[i], n, D_00515B40.fB0, (float *)outs[i], 0);
        } else {
            D_00515B40.f104[i]->f00(D_00515B40.f104[i], n, (int)D_00515B40.fD0[i], (float *)outs[i], 0);
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C8968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C85D0(int *, int);

void func_003C8968(int *src, int len) {
    int buf[8];
    int i, n;

    for (i = 0; i < D_00515B45; i++) {
        buf[i] = src[i];
    }
    while (len > 0) {
        func_003C85D0(buf, len < 0x201 ? len : 0x200);
        for (i = 0; i < D_00515B40.f05; i++) {
            buf[i] += D_00515B40.f0C;
        }
        len -= 0x200;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8A40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
int func_003C8A40(int idx) {
    struct sB40Ent *e = &D_00515D1C[idx];
    if (e->f44 != 0) {
        return e->f44(e->f48);
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8A88);
#ifdef SKIP_ASM
extern struct sB40Node *func_003B5C60_8A88(int) __asm__("func_003B5C60");
extern void func_003CBB28_8A88(struct sB40Node *, int, int) __asm__("func_003CBB28");
extern void func_003C8F48_8A88(struct sB40Node **, struct sB40Node *) __asm__("func_003C8F48");
extern void func_003CB538_8A88(struct sB40Node *, int) __asm__("func_003CB538");

void func_003C8A88(int idx, int n) {
    struct sB40Ent *e;
    if (n > 0x20000) n = 0x20000;
    e = &D_00515B40.f1DC[idx];
    if (e->f50 == 0) {
        int big;
        e->f50 = func_003B5C60_8A88(0x38);
        big = D_00515B40.f0E >= 0x32;
        e->f50->f04 = 0;
        e->f50->f18 = 0xA0;
        e->f50->f1A = 0;
        func_003CBB28_8A88(e->f50, D_0050AA62, big);
        func_003C8F48_8A88(&e->f40, e->f50);
    }
    func_003CB538_8A88(e->f50, n);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8B40);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CB110_8B40(struct sB40Node *, int) __asm__("func_003CB110");

void func_003C8B40(int arg0, int arg1) {
    struct sB40Ent *e = &D_00515D1C[arg0];
    struct sB40Node *n;

    n = e->f4C;
    if (n != 0) {
        func_003CB110_8B40(n, arg1);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8B80);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern struct sB40Node *f_5C60_8B80(int) __asm__("func_003B5C60");
extern void f_5E98_8B80(void *) __asm__("func_003B5E98");
extern void f_8F48_8B80(struct sB40Node **, struct sB40Node *) __asm__("func_003C8F48");
extern void f_8FB0_8B80(struct sB40Node **, struct sB40Node *) __asm__("func_003C8FB0");
extern void f_B4A8_8B80(struct sB40Node *, int) __asm__("func_003CB4A8");
extern void f_B528_8B80(struct sB40Node *) __asm__("func_003CB528");

void func_003C8B80(int arg0, int arg1) {
    struct sB40Ent *p = &D_00515D1C[arg0];
    if (arg1 > 0) {
        if (p->f54 == 0) {
            struct sB40Node *n = f_5C60_8B80(0x50);
            p->f54 = n;
            n->f04 = 0;
            p->f54->f18 = 0x78;
            f_B528_8B80(p->f54);
            f_8F48_8B80(&p->f40, p->f54);
        }
        f_B4A8_8B80(p->f54, arg1);
        return;
    }
    if (p->f54 != 0) {
        f_8FB0_8B80(&p->f40, p->f54);
        f_5E98_8B80(p->f54);
        p->f54 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8C30);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern struct sB40Node *func_003B5C60_8C30(int) __asm__("func_003B5C60");
extern void func_003B5E98_8C30(void *) __asm__("func_003B5E98");
extern void func_003CA990_8C30(struct sB40Node *) __asm__("func_003CA990");
extern void func_003C8F48_8C30(struct sB40Node **, struct sB40Node *) __asm__("func_003C8F48");
extern void func_003C8FB0_8C30(struct sB40Node **, struct sB40Node *) __asm__("func_003C8FB0");
extern void func_003CA9D8_8C30(struct sB40Node *, int *) __asm__("func_003CA9D8");

void func_003C8C30(int arg0, int arg1) {
    int sp[2];
    struct sB40Ent *e;
    struct sB40Node *buf;

    e = &D_00515D1C[arg0];
    if (arg1 > 0) {
        if (e->f5C == 0) {
            struct sB40Node *t2 = func_003B5C60_8C30(0x120);
            e->f5C = t2;
            t2->f04 = 0;
            e->f5C->f18 = 0x50;
            e->f5C->f1A = 0;
            func_003CA990_8C30(e->f5C);
            func_003C8F48_8C30(&e->f40, e->f5C);
        }
        sp[0] = arg1 << 8;
        sp[1] = D_0050A912 << 8;
        func_003CA9D8_8C30(e->f5C, sp);
        return;
    }
    buf = e->f5C;
    if (buf != 0) {
        func_003C8FB0_8C30(&e->f40, buf);
        func_003B5E98_8C30(e->f5C);
        e->f5C = 0;
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003C8D00);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8E28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Kind_8E28 {                  /* a filter kind: node size, order, init, process, release */
    int f00;
    int f04;
    unsigned short f08;
    int (*f0C)(struct sB40Node *, int, int);
    int (*f10)(struct sB40Node *, int, int, float *, int);
    void (*f14)(struct sB40Node *);
};
extern struct sB40Node *func_003B5C60_8E28(int) __asm__("func_003B5C60");
extern void func_003C8F48_8E28(struct sB40Node **, struct sB40Node *) __asm__("func_003C8F48");

void func_003C8E28(int arg0, int arg1, struct Kind_8E28 *arg2) {
    struct sB40Ent *e = &D_00515D1C[arg0];
    struct sB40Node *n;

    n = func_003B5C60_8E28(arg2->f04);
    arg2->f0C(n, arg2->f00, arg1);
    n->f18 = arg2->f08;
    n->f00 = arg2->f10;
    n->f04 = arg2->f14;
    n->f1A = 0;
    func_003C8F48_8E28(&e->f40, n);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8EC0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C8FB0_8EC0(struct sB40Node **, struct sB40Node *) __asm__("func_003C8FB0");
extern void func_003B5E98_8EC0(struct sB40Node *) __asm__("func_003B5E98");

void func_003C8EC0(int arg0, int arg1) {
    struct sB40Ent *rec = &D_00515D1C[arg0];
    struct sB40Node *node = rec->f40;
    do {
        if (node->f18 == arg1) {
            if (node->f04 != 0) {
                node->f04(node);
            }
            func_003C8FB0_8EC0(&rec->f40, node);
            func_003B5E98_8EC0(node);
            return;
        }
        node = node->f08;
    } while (node != 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8F48);
#ifdef SKIP_ASM
void func_003C8F48(char **arg0, char *arg1) {
    char *cur;
    char *prev;

    cur = *arg0;
    prev = 0;
    while (cur != 0 && *(unsigned short *)(cur + 0x18) < *(unsigned short *)(arg1 + 0x18)) {
        prev = cur;
        cur = *(char **)(cur + 8);
    }
    *(char **)(arg1 + 8) = cur;
    if (cur != 0) {
        *(char **)(cur + 0x10) = arg1;
    }
    if (prev == 0) {
        *arg0 = arg1;
    } else {
        *(char **)(prev + 8) = arg1;
        *(char **)(arg1 + 0x10) = prev;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C8FB0);
#ifdef SKIP_ASM
typedef struct N_8FB0 { char pad0[8]; struct N_8FB0 *next; int pad1; struct N_8FB0 *prev; } N_8FB0;

void func_003C8FB0(N_8FB0 **arg0, N_8FB0 *arg1) {
    N_8FB0 *temp_5;
    N_8FB0 *var_2;
    N_8FB0 *var_6;

    var_6 = *arg0;
    var_2 = var_6->next;
    if (arg1 == var_6) {
        *arg0 = var_2;
        return;
    }
    while (var_2 != 0 && var_2 != arg1) {
        var_6 = var_2;
        var_2 = var_6->next;
    }
    if ((var_2 != 0) && (var_2 == arg1)) {
        temp_5 = arg1->next;
        if (temp_5 != 0) {
            temp_5->prev = var_6;
        }
        var_6->next = var_6->next->next;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9010);
#ifdef SKIP_ASM
int func_003C9010(void *arg0) {
    int (*temp_2)();

    temp_2 = (*(int (**)())((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        temp_2();
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9040);
#ifdef SKIP_ASM
void func_003C9040(void *arg0) {
    int (*temp_2)(void *);
    void *temp_4;
    void *temp_4_2;

    temp_4 = (*(void **)((char*)(arg0) + (8)));
    if ((temp_4 != 0) && ((*(unsigned char *)((char*)(temp_4) + (0x1B))) == 0)) {
        func_003C9040(temp_4);
    }
    temp_4_2 = (*(void **)((char*)(arg0) + (0xC)));
    if ((temp_4_2 != 0) && ((*(unsigned char *)((char*)(temp_4_2) + (0x1B))) == 0)) {
        func_003C9040(temp_4_2);
    }
    temp_2 = (*(int (**)(void *))((char*)(arg0) + (4)));
    if (temp_2 != 0) {
        temp_2(arg0);
    }
    (*(signed char *)((char*)(arg0) + (0x1B))) = 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C90C0);
#ifdef SKIP_ASM
int func_003C90C0(char *a, char *b, int s, int t) {
    if (s == 1 && t == 1 && *(int*)(b + 8) == 0) {
        *(int*)(a + 0x10) = (int)b;
        *(int*)(b + 8) = (int)a;
        *(char*)(b + 0x1A) = t;
        return 0;
    }
    if (s == 1 && t == 2 && *(int*)(b + 0xC) == 0) {
        *(int*)(a + 0x10) = (int)b;
        *(int*)(b + 0xC) = (int)a;
        *(char*)(b + 0x1A) = s;
        return 0;
    }
    if (s == 2 && t == 1 && *(int*)(b + 8) == 0) {
        *(int*)(a + 0x14) = (int)b;
        *(int*)(b + 8) = (int)a;
        *(char*)(b + 0x1A) = s;
        return 0;
    }
    if (s == 2 && t == 2 && *(int*)(b + 0xC) == 0) {
        *(int*)(a + 0x14) = (int)b;
        *(int*)(b + 0xC) = (int)a;
        *(char*)(b + 0x1A) = t;
        return 0;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9188);
#ifdef SKIP_ASM
int func_003C9188(int *a, int *b, int x, int y) {
    if (x == 1 && y == 1 && a[4] == (int)b && b[2] == (int)a) {
        a[4] = 0;
        b[2] = 0;
        return 0;
    }
    if (x == 1 && y == 2 && a[4] == (int)b && b[3] == (int)a) {
        a[4] = 0;
        b[3] = 0;
        return 0;
    }
    if (x == 2 && y == 1 && a[5] == (int)b && b[2] == (int)a) {
        a[5] = 0;
        b[2] = 0;
        return 0;
    }
    if (x == 2 && y == 2 && a[5] == (int)b && b[3] == (int)a) {
        a[5] = 0;
        b[3] = 0;
        return 0;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9268);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_9268_a(struct sB40Node *, struct sB40Init *) __asm__("func_003C9AC8");
extern void f_9268_b(struct sB40Node *, struct sB40Init *) __asm__("func_003C9BC8");
extern void f_9268_c(struct sB40Node *, struct sB40Init *) __asm__("func_003C9D28");

void func_003C9268(void) {
    D_00515B40.f18[0][0] = f_9268_a;
    D_00515B40.f60[0][0] = 0x2C;
    D_00515B40.f18[0][1] = f_9268_b;
    D_00515B40.f60[0][1] = 0x30;
    D_00515B40.f18[0][2] = f_9268_c;
    D_00515B40.f60[0][2] = 0x34;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C92B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_92B0_a(struct sB40Node *, struct sB40Init *) __asm__("func_003CA028");
extern void f_92B0_b(struct sB40Node *, struct sB40Init *) __asm__("func_003CA388");
extern void f_92B0_c(struct sB40Node *, struct sB40Init *) __asm__("func_003CA610");

void func_003C92B0(void) {
    D_00515B40.f18[1][0] = f_92B0_a;
    D_00515B40.f60[1][0] = 0x2C;
    D_00515B40.f60[1][1] = 0x54;
    D_00515B40.f18[1][1] = f_92B0_b;
    D_00515B40.f18[1][2] = f_92B0_c;
    D_00515B40.f60[1][2] = 0x3C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C92F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C9420_9420(struct sB40Node *, struct sB40Init *) __asm__("func_003C9420");
extern void func_003C9618_9618(struct sB40Node *, struct sB40Init *) __asm__("func_003C9618");
extern void func_003C9960_9960(struct sB40Node *, struct sB40Init *) __asm__("func_003C9960");

void func_003C92F8(void) {
    D_00515B40.f18[2][0] = func_003C9420_9420;
    D_00515B40.f60[2][0] = 0x2C;
    D_00515B40.f18[2][2] = func_003C9960_9960;
    D_00515B40.f60[2][2] = 0x3C;
    D_00515B40.f18[2][1] = func_003C9618_9618;
    D_00515B40.f60[2][1] = 0x30;
    D_00515B40.f18[3][0] = func_003C9420_9420;
    D_00515B40.f60[3][0] = 0x2C;
    D_00515B40.f18[3][2] = func_003C9960_9960;
    D_00515B40.f60[3][2] = 0x3C;
    D_00515B40.f18[3][1] = func_003C9618_9618;
    D_00515B40.f60[3][1] = 0x30;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9358);
#ifdef SKIP_ASM
int func_003C9358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9360);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CDE68_9360(int, int **, int) __asm__("func_003CDE68");
extern void func_00416210_9360(int *, int, int) __asm__("func_00416210");

int func_003C9360(void *arg0, int arg1, int arg2, int *arg3) {
    int *sp0;
    int temp_2;

    sp0 = arg3;
    if ((unsigned int) (*(unsigned int *)((char*)(arg0) + (0x20))) >= (unsigned int) (*(unsigned int *)((char*)(arg0) + (0x1C)))) {
        return -1;
    }
    temp_2 = func_003CDE68_9360((*(int *)((char*)(arg0) + (0x28))), &sp0, arg1);
    (*(unsigned int *)((char*)(arg0) + (0x20))) = (unsigned int) ((*(unsigned int *)((char*)(arg0) + (0x20))) + temp_2);
    sp0 = sp0 + temp_2;
    if (temp_2 < arg1) {
        func_00416210_9360(sp0, 0, (arg1 -= temp_2) * 4);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C93F8);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C93F8(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x28)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9420);
#ifdef SKIP_ASM
typedef struct { int a, b, c; } Q_9420;
extern int f_9360_9420[] __asm__("func_003C9360");
extern int f_93F8_9420[] __asm__("func_003C93F8");
extern int f_9358_9420[] __asm__("func_003C9358");
extern int f_D1A8_9420(int) __asm__("func_003CD1A8");
extern void *f_DDB8_9420(int) __asm__("func_003CDDB8");
extern Q_9420 f_E078_9420(int) __asm__("func_003CE078");
extern void f_E0B8_9420(int, Q_9420 *, int) __asm__("func_003CE0B8");
extern void f_E0D8_9420(int, int) __asm__("func_003CE0D8");
extern void f_DDE8_9420(int, int, int, int) __asm__("func_003CDDE8");

void func_003C9420_impl(char *, char *) __asm__("func_003C9420");
void func_003C9420_impl(char *self, char *src) {
    Q_9420 q;
    Q_9420 t;
    int n;
    *(int **)(self + 0) = f_9360_9420;
    *(int *)(self + 0x1C) = *(int *)(src + 0xC);
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = *(int *)(src + 0x24);
    *(int **)(src + 0x28) = f_9358_9420;
    *(int **)(self + 4) = f_93F8_9420;
    *(void **)(self + 0x28) = f_DDB8_9420(f_D1A8_9420(0xD68));
    t = f_E078_9420(*(int *)(self + 0x28));
    q = t;
    q.c = 1;
    f_E0B8_9420(*(int *)(self + 0x28), &q, 0);
    if (*(int *)(self + 0x24) < 3) {
        f_E0D8_9420(*(int *)(self + 0x28), 0);
    } else {
        f_E0D8_9420(*(int *)(self + 0x28), 1);
    }
    n = *(int *)(self + 0x1C);
    f_DDE8_9420(*(int *)(self + 0x28), *(int *)(src + 0), n * 4, n);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9518);
#ifdef SKIP_ASM
int func_003C9518(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9520);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a, b, c; } Q_9520;
extern int func_003CDE68_9520(int, int *, int) __asm__("func_003CDE68");
extern void func_003CE0B8_9520(int, void *, int) __asm__("func_003CE0B8");
extern void func_003CDDE8_9520(int, int, int, int) __asm__("func_003CDDE8");

int func_003C9520(char *arg0, int arg1, int arg2, int arg3) {
    Q_9520 q;
    int sp10;
    int n, t;

    sp10 = arg3;
    if (arg1 > 0) {
        do {
            n = func_003CDE68_9520(*(int*)(arg0 + 0x1C), &sp10, arg1);
            arg1 -= n;
            sp10 += n * 4;
            *(int*)(arg0 + 0x20) = *(int*)(arg0 + 0x20) + n;
            if (n < arg1) {
                *(int*)(arg0 + 0x20) = *(int*)(arg0 + 0x24);
                q.b = 0;
                q.a = 0;
                q.c = 1;
                func_003CE0B8_9520(*(int*)(arg0 + 0x1C), &q, 0);
                t = (*(int*)(arg0 + 0x28) - *(int*)(arg0 + 0x24)) + 1;
                func_003CDDE8_9520(*(int*)(arg0 + 0x1C), *(int*)(arg0 + 0x2C), t * 4, t);
            }
        } while (arg1 > 0);
    }
    return 1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C95F0);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C95F0(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9618);
#ifdef SKIP_ASM
typedef struct { int a, b, c; } Q_9618;
extern int f_9520_9618[] __asm__("func_003C9520");
extern int f_95F0_9618[] __asm__("func_003C95F0");
extern int f_9518_9618[] __asm__("func_003C9518");
extern int f_D1A8_9618(int) __asm__("func_003CD1A8");
extern void *f_DDB8_9618(int) __asm__("func_003CDDB8");
extern Q_9618 f_E078_9618(int) __asm__("func_003CE078");
extern void f_E0B8_9618(int, Q_9618 *, int) __asm__("func_003CE0B8");
extern int f_DDE8_9618(int, int, int, int) __asm__("func_003CDDE8");

void func_003C9618_impl(char *, char *) __asm__("func_003C9618");
void func_003C9618_impl(char *self, char *src) {
    Q_9618 q;
    Q_9618 t;
    int n;
    *(int **)(self + 0) = f_9520_9618;
    *(int **)(self + 4) = f_95F0_9618;
    *(int *)(self + 0x2C) = *(int *)(src + 4);
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = *(int *)(src + 0x10);
    *(int *)(self + 0x28) = *(int *)(src + 0x14);
    *(void **)(self + 0x1C) = f_DDB8_9618(f_D1A8_9618(0xD68));
    t = f_E078_9618(*(int *)(self + 0x1C));
    q = t;
    q.c = 1;
    f_E0B8_9618(*(int *)(self + 0x1C), &q, 0);
    n = *(int *)(self + 0x24);
    f_DDE8_9618(*(int *)(self + 0x1C), *(int *)(src + 0), n * 4, n);
    *(int **)(src + 0x28) = f_9518_9618;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C96F0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { int a, b, c; } Q_96F0;
extern void func_003C7010(int, int, int);
extern int f_6DE0_96F0(int, int, char *, int *) __asm__("func_003C6DE0");
extern int f_DE68_96F0(int, int *, int) __asm__("func_003CDE68");
extern Q_96F0 f_E078_96F0(int) __asm__("func_003CE078");
extern void f_E0B8_96F0(int, Q_96F0 *, int) __asm__("func_003CE0B8");
extern void f_E0D8_96F0(int, int) __asm__("func_003CE0D8");
extern void f_DDE8_96F0(int, int, int, int) __asm__("func_003CDDE8");
extern void f_6210_96F0(int, int, int) __asm__("func_00416210");

int func_003C96F0(char *self, int n, int unused, int buf) {
    Q_96F0 q;
    Q_96F0 t;
    int last;
    int total;
    int got;

    total = 0;
    if (*(int *)(self + 0x28) != 0) {
        func_003C7010(*(int *)(self + 0x24), *(unsigned char *)(self + 0x38), *(int *)(self + 0x28));
        *(int *)(self + 0x28) = 0;
    }
    while (n > 0) {
        got = f_DE68_96F0(*(int *)(self + 0x34), &buf, n);
        *(unsigned short *)(self + 0x2C) += got;
        total += got;
        buf += got * 4;
        *(int *)(self + 0x28) += got;
        if (got < n) {
            n -= got;
            *(int *)(self + 0x1C) = f_6DE0_96F0(*(int *)(self + 0x24), *(unsigned char *)(self + 0x38), self + 0x20, &last);
            if (*(int *)(self + 0x1C) != 0) {
                *(unsigned short *)(self + 0x2C) = 0;
                if (*(int *)(self + 0x30) < 3) {
                    if (last == 0) {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 1;
                        f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    } else {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 0;
                        f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    }
                    f_E0D8_96F0(*(int *)(self + 0x34), 0);
                } else {
                    if (last == 0) {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.b = 0;
                        q.c = 1;
                    } else {
                        t = f_E078_96F0(*(int *)(self + 0x34));
                        q = t;
                        q.c = 0;
                    }
                    f_E0B8_96F0(*(int *)(self + 0x34), &q, 0);
                    f_E0D8_96F0(*(int *)(self + 0x34), 1);
                }
                f_DDE8_96F0(*(int *)(self + 0x34), *(int *)(self + 0x1C) + 1, *(int *)(self + 0x20) * 4, *(int *)(self + 0x20));
            } else {
                if (n > 0 && *(int *)(self + 0x28) != 0) {
                    f_6210_96F0(buf, 0, n * 4);
                }
                *(int *)(self + 0x20) = 0;
                n = 0;
            }
        } else {
            n -= got;
        }
    }
    return total;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9938);
#ifdef SKIP_ASM
extern void func_003CD1D0(int);

void func_003C9938(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x34)));
    if (temp_4 != 0) {
        func_003CD1D0(temp_4);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9960);
#ifdef SKIP_ASM
extern int func_003CD1A8_9960(int) __asm__("func_003CD1A8");
extern void *func_003CDDB8_9960(int) __asm__("func_003CDDB8");
extern int func_003C96F0_9960[] __asm__("func_003C96F0");
extern int func_003C9938_9960[] __asm__("func_003C9938");

void func_003C9960(void *arg0, void *arg1) {
    (*(int **)((char *)(arg0) + 0)) = func_003C96F0_9960;
    (*(int *)((char *)(arg0) + 0x24)) = func_003CE378(func_003CE0E0((*(int *)((char *)(arg1) + 0x1C))));
    (*(signed char *)((char *)(arg0) + 0x38)) = func_003CE118((*(int *)((char *)(arg1) + 0x1C)));
    (*(int *)((char *)(arg0) + 0x1C)) = 0;
    (*(short *)((char *)(arg0) + 0x2C)) = 0;
    (*(int *)((char *)(arg0) + 0x30)) = (int)(*(int *)((char *)(arg1) + 0x24));
    (*(int *)((char *)(arg0) + 0x20)) = (int)(*(int *)((char *)(arg1) + 0xC));
    (*(int **)((char *)(arg0) + 4)) = func_003C9938_9960;
    (*(void **)((char *)(arg0) + 0x34)) = func_003CDDB8_9960(func_003CD1A8_9960(0xD68));
    (*(int *)((char *)(arg0) + 0x28)) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C99F8);
#ifdef SKIP_ASM
int func_003C99F8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9A00);
#ifdef SKIP_ASM
struct R_9A00 { char pad[0x1C]; short *data; unsigned int pos; unsigned int cap; int flag; };

int func_003C9A00(struct R_9A00 *r, unsigned int n, int arg2, int *buf) {
    unsigned int pos = r->pos;
    unsigned int cap = r->cap;
    if (pos >= cap) return -1;
    r->pos = pos + n;
    if (pos + n < cap) {
        if (r->flag) {
            func_003C9E50(n, r->data + pos, buf);
        }
    } else {
        unsigned int first = cap - pos;
        if (r->flag) {
            func_003C9E50(first, r->data + pos, buf);
        }
        func_00416210(buf + first, 0, (n - first) * 4);
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9AC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C99F8_9AC8(void) __asm__("func_003C99F8");
void func_003C9A00_9AC8(void) __asm__("func_003C9A00");

void func_003C9AC8(char *arg0, char *arg1) {
    int t;
    *(void (**)(void))(arg0 + 0) = func_003C9A00_9AC8;
    t = *(int *)(arg1 + 0);
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x1C) = t;
    *(int *)(arg0 + 0x24) = *(int *)(arg1 + 0xC);
    *(int *)(arg0 + 0x28) = *(int *)(arg1 + 0x18);
    *(void (**)(void))(arg1 + 0x28) = func_003C99F8_9AC8;
    *(int *)(arg0 + 4) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9B08);
#ifdef SKIP_ASM
int func_003C9B08(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9B10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_9E50_9B10(int, void *, void *) __asm__("func_003C9E50");
struct R_9B10 { char pad[0x1C]; short *buf; unsigned cur; unsigned start; unsigned end; int en; };

int func_003C9B10(struct R_9B10 *self, int n, int unused, int *src) {
    int m;
    while (n > 0) {
        m = self->end - self->cur + 1;
        if (n < m)
            m = n;
        if (self->en != 0)
            f_9E50_9B10(m, self->buf + self->cur, src);
        src += m;
        self->cur = self->cur + m;
        n -= m;
        if (self->end < self->cur)
            self->cur = self->start;
    }
    return 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9BC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003C9B10_9BC8(void) __asm__("func_003C9B10");
void func_003C9B08_9BC8(void) __asm__("func_003C9B08");

void func_003C9BC8(int *a, int *b) {
    a[0] = (int)func_003C9B10_9BC8;
    a[7] = b[0];
    a[8] = 0;
    a[9] = b[4];
    a[10] = b[5];
    a[11] = b[6];
    b[10] = (int)func_003C9B08_9BC8;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9C08);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C6DE0_9C08(int, unsigned char, int *, int *) __asm__("func_003C6DE0");
extern void func_003C7010_9C08(int, unsigned char, int) __asm__("func_003C7010");
extern void func_003C9E50_9C08(int, int, int *) __asm__("func_003C9E50");
extern void func_00416210_9C08(int *, int, int) __asm__("func_00416210");

int func_003C9C08(char *o, int n, int unused, int *buf);
int func_003C9C08(char *o, int n, int unused, int *buf) {
    int sp0, sp4;
    int t;
    if (*(int *)(o + 0x2C) != 0) {
        func_003C7010_9C08(*(int *)(o + 0x28), *(unsigned char *)(o + 0x31), *(int *)(o + 0x2C));
        *(int *)(o + 0x2C) = 0;
    }
    while (n > 0) {
        if (*(int *)(o + 0x24) >= *(int *)(o + 0x20)) {
            *(int *)(o + 0x1C) = func_003C6DE0_9C08(*(int *)(o + 0x28), *(unsigned char *)(o + 0x31), &sp0, &sp4);
            if (*(int *)(o + 0x1C) == 0) {
                if (*(int *)(o + 0x2C) != 0) {
                    func_00416210_9C08(buf, 0, n * 4);
                }
                return *(int *)(o + 0x2C);
            }
            *(int *)(o + 0x24) = 0;
            *(int *)(o + 0x20) = sp0;
        }
        t = *(int *)(o + 0x20) - *(int *)(o + 0x24);
        if (n < t) t = n;
        if (*(unsigned char *)(o + 0x30) != 0) {
            func_003C9E50_9C08(t, *(int *)(o + 0x1C) + *(int *)(o + 0x24) * 2, buf);
        }
        buf += t;
        n -= t;
        *(int *)(o + 0x24) += t;
        *(int *)(o + 0x2C) += t;
    }
    return *(int *)(o + 0x2C);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003C9D28);
#ifdef SKIP_ASM
extern int func_003CE0E0(int);
extern signed char func_003CE118(int);
extern int func_003CE378(int);
extern int func_003C9C08(char *o, int n, int unused, int *buf);

void func_003C9D28(void *arg0, void *arg1) {
    (*(int **)((char*)(arg0) + (0))) = (int*)&func_003C9C08;
    (*(int *)((char*)(arg0) + (0x28))) = func_003CE378(func_003CE0E0((*(int *)((char*)(arg1) + (0x1C)))));
    (*(signed char *)((char*)(arg0) + (0x31))) = func_003CE118((*(int *)((char*)(arg1) + (0x1C))));
    (*(int *)((char*)(arg0) + (0x20))) = -1;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x24))) = 0;
    (*(unsigned char *)((char*)(arg0) + (0x30))) = (*(unsigned char *)((char*)(arg1) + (0x18)));
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9DA0);
#ifdef SKIP_ASM
void func_003C9DA0(int n, short *src, float *dst) {
    float *d = dst;
    int r = n & 3;
    float *end = d + n;
    short *s = src;
    if (r != 0) {
        int c = r;
        do {
            *d++ = (float)*s++;
        } while (--c != 0);
    }
    if (n >= 4) {
        // PORT: PS2-only hand-written inner loop (4 int16 -> float per iteration), one inline asm block.
        __asm__ volatile(
            ".set noreorder\n\t"
            "move $4, %0\n\t"
            "move $5, %1\n\t"
            "move $6, %2\n"
            "1:\n\t"
            "lh $8, 0x0($4)\n\t"
            "lh $9, 0x2($4)\n\t"
            "lh $10, 0x4($4)\n\t"
            "lh $11, 0x6($4)\n\t"
            "mtc1 $8, $f0\n\t"
            "mtc1 $9, $f1\n\t"
            "mtc1 $10, $f2\n\t"
            "mtc1 $11, $f3\n\t"
            "addi $5, $5, 0x10\n\t"
            "cvt.s.w $f0, $f0\n\t"
            "cvt.s.w $f1, $f1\n\t"
            "cvt.s.w $f2, $f2\n\t"
            "cvt.s.w $f3, $f3\n\t"
            "swc1 $f0, -0x10($5)\n\t"
            "swc1 $f1, -0xC($5)\n\t"
            "swc1 $f2, -0x8($5)\n\t"
            "swc1 $f3, -0x4($5)\n\t"
            "bne $5, $6, 1b\n\t"
            "addi $4, $4, 0x8\n\t"
            ".set reorder\n"
            : : "r"(s), "r"(d), "r"(end)
            : "$4", "$5", "$6", "$8", "$9", "$10", "$11", "$f0", "$f1", "$f2", "$f3", "memory");
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9E50);
#ifdef SKIP_ASM
extern void func_003C9DA0(int n, short *src, float *dst);

void func_003C9E50(int n, short *src, float *dst) {
    int rem;
    if (((int)src & 7) != 0 || ((int)dst & 0xF) != 0) {
        func_003C9DA0(n, src, dst);
        return;
    }
    rem = n & 0xF;
    if (rem != 0) {
        n &= 0x7FF0;
        func_003C9DA0(rem, src + n, dst + n);
        if (n <= 0) return;
    }
    // PORT: PS2-only MMI/VU0 inline asm loop (16 int16 -> float per iteration).
    __asm__ volatile(
        ".set noreorder\n\t"
        "move $4, %0\n\t"
        "move $5, %1\n\t"
        "move $6, %2\n"
        "1:\n\t"
        "ld $8, 0x0($5)\n\t"
        "ld $9, 0x8($5)\n\t"
        "ld $10, 0x10($5)\n\t"
        "ld $11, 0x18($5)\n\t"
        "pextlh $8, $8, $0\n\t"
        "pextlh $9, $9, $0\n\t"
        "pextlh $10, $10, $0\n\t"
        "pextlh $11, $11, $0\n\t"
        "psraw $8, $8, 16\n\t"
        "psraw $9, $9, 16\n\t"
        "psraw $10, $10, 16\n\t"
        "psraw $11, $11, 16\n\t"
        "qmtc2.ni $8, $vf1\n\t"
        "qmtc2.ni $9, $vf2\n\t"
        "qmtc2.ni $10, $vf3\n\t"
        "qmtc2.ni $11, $vf4\n\t"
        "vitof0.xyzw $vf1, $vf1\n\t"
        "vitof0.xyzw $vf2, $vf2\n\t"
        "vitof0.xyzw $vf3, $vf3\n\t"
        "vitof0.xyzw $vf4, $vf4\n\t"
        "sqc2 $vf1, 0x0($6)\n\t"
        "sqc2 $vf2, 0x10($6)\n\t"
        "addiu $4, $4, -0x10\n\t"
        "sqc2 $vf3, 0x20($6)\n\t"
        "addiu $5, $5, 0x20\n\t"
        "sqc2 $vf4, 0x30($6)\n\t"
        "bgtzl $4, 1b\n\t"
        "addiu $6, $6, 0x40\n\t"
        ".set reorder\n"
        : : "r"(n), "r"(src), "r"(dst)
        : "$4", "$5", "$6", "$8", "$9", "$10", "$11", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9F58);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CCF90_9F58(int, char **, int) __asm__("func_003CCF90");
extern void func_00416210_9F58(char *, int, int) __asm__("func_00416210");

int func_003C9F58(void *arg0, int arg1, int arg2, int arg3) {
    char *p;
    char *q;
    int n;
    p = (char *)arg3;
    if (*(int *)((char *)arg0 + 0x28) >= *(int *)((char *)arg0 + 0x24)) {
        return -1;
    }
    n = func_003CCF90_9F58(*(int *)((char *)arg0 + 0x1C), &p, arg1);
    *(int *)((char *)arg0 + 0x28) += n;
    p += n * 4;
    q = p;
    if (n < arg1) {
        arg1 = arg1 - n;
        n += arg1;
        func_00416210_9F58(q, 0, arg1 * 4);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003C9FF8);
#ifdef SKIP_ASM
int func_003C9FF8(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x28)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA000);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA000(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA028);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char func_003C9F58_A028[] __asm__("func_003C9F58");
extern char func_003C9FF8_A028[] __asm__("func_003C9FF8");
extern char func_003CA000_A028[] __asm__("func_003CA000");
extern int func_003CCEF0_A028(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A028(int) __asm__("func_003CCF40");
extern void func_003CCF60_A028(int, int, int, int) __asm__("func_003CCF60");

void func_003CA028(char *arg0, char *arg1) {
    int n;
    *(char **)(arg0 + 0) = func_003C9F58_A028;
    *(char **)(arg0 + 4) = func_003CA000_A028;
    *(int *)(arg0 + 0x20) = *(int *)(arg1 + 0);
    *(int *)(arg0 + 0x24) = *(int *)(arg1 + 0xC);
    *(int *)(arg0 + 0x28) = 0;
    *(int *)(arg0 + 0x1C) = func_003CCF40_A028(func_003CCEF0_A028(0xA8));
    *(char **)(arg1 + 0x28) = func_003C9FF8_A028;
    n = *(int *)(arg0 + 0x24);
    func_003CCF60_A028(*(int *)(arg0 + 0x1C), *(int *)(arg0 + 0x20), n * 4, n);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA0B8);
#ifdef SKIP_ASM
typedef struct { float x, y; } V2_A0B8;
extern int func_003CCF90_A0B8(int, int **, int) __asm__("func_003CCF90");
extern int func_003CCF60_A0B8(int, int, int, int) __asm__("func_003CCF60");
extern V2_A0B8 func_003CD138_A0B8(int) __asm__("func_003CD138");
extern void func_003CD190_A0B8(int, V2_A0B8 *) __asm__("func_003CD190");

int func_003CA0B8(char *o, int n, int unused, int *buf) {
    int used = 0;
    int got;
    int *dst = buf;
    V2_A0B8 v;
    struct { int hdr[2]; int samples[30]; } tmp;
    int *p2;

    if (*(int *)(o + 0x30) < 3) {
        int k;
        if (*(int *)(o + 0x40) == 0) {
            k = *(int *)(o + 0x44) / 0x1C;
            k = k * 0x1C;
            func_003CCF60_A0B8(*(int *)(o + 0x1C), *(int *)(o + 0x34), k * 4, k);
            *(int *)(o + 0x40) = 1;
        }
        while (n != 0) {
            got = func_003CCF90_A0B8(*(int *)(o + 0x1C), &dst, n);
            dst += got;
            used += got;
            *(int *)(o + 0x20) += got;
            if (got < n) {
                int rem;
                int cnt;
                n -= got;
                rem = *(int *)(o + 0x44) % 0x1C;
                *(int *)(o + 0x20) = *(int *)(o + 0x44) - rem;
                cnt = *(int *)(o + 0x48) - *(int *)(o + 0x20) + 1;
                func_003CCF60_A0B8(*(int *)(o + 0x1C), *(int *)(o + 0x34) + (*(int *)(o + 0x20) / 0x1C) * 15, cnt * 4, cnt);
                if (*(int *)(o + 0x3C) == 0) {
                    v = func_003CD138_A0B8(*(int *)(o + 0x1C));
                    *(float *)(o + 0x4C) = v.x;
                    *(float *)(o + 0x50) = v.y;
                    got = func_003CCF90_A0B8(*(int *)(o + 0x1C), &dst, n);
                    dst += got;
                    *(int *)(o + 0x20) += got;
                    *(int *)(o + 0x3C) = 1;
                    used += got;
                    n -= got;
                } else {
                    v.x = *(float *)(o + 0x4C);
                    v.y = *(float *)(o + 0x50);
                    func_003CD190_A0B8(*(int *)(o + 0x1C), &v);
                    p2 = tmp.samples;
                    got = func_003CCF90_A0B8(*(int *)(o + 0x1C), &p2, rem);
                    *(int *)(o + 0x20) += got;
                }
            } else {
                n -= got;
            }
        }
        return used;
    }
    while (n > 0) {
        got = func_003CCF90_A0B8(*(int *)(o + 0x1C), &dst, n);
        dst += got;
        n -= got;
        *(int *)(o + 0x20) += got;
        used += got;
        if (got < n) {
            int cnt = *(int *)(o + 0x28) - *(int *)(o + 0x24) + 1;
            *(int *)(o + 0x20) = *(int *)(o + 0x24);
            func_003CCF60_A0B8(*(int *)(o + 0x1C), *(int *)(o + 0x2C), cnt * 4, cnt);
        }
    }
    return used;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA358);
#ifdef SKIP_ASM
int func_003CA358(void *arg0) {
    return (*(int *)((char*)(arg0) + (0x20)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA360);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA360(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA388);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char func_003CA0B8_A388[] __asm__("func_003CA0B8");
extern char func_003CA358_A388[] __asm__("func_003CA358");
extern char func_003CA360_A388[] __asm__("func_003CA360");
extern int func_003CCEF0_A388(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A388(int) __asm__("func_003CCF40");
extern void func_003CCF60_A388(int, int, int, int) __asm__("func_003CCF60");

void func_003CA388(int *self, int *arg1) {
    int n;

    self[0] = (int)func_003CA0B8_A388;
    self[1] = (int)func_003CA360_A388;
    self[11] = arg1[1];
    self[8] = 0;
    self[12] = arg1[9];
    self[9] = arg1[4];
    self[10] = arg1[5];
    self[7] = func_003CCF40_A388(func_003CCEF0_A388(0xA8));
    arg1[10] = (int)func_003CA358_A388;
    if (self[12] < 3) {
        self[13] = arg1[0];
        self[14] = arg1[3];
        self[15] = 0;
        self[16] = 0;
        self[17] = arg1[4];
        self[18] = arg1[5];
    } else {
        n = self[9];
        func_003CCF60_A388(self[7], arg1[0], n * 4, n);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA460);
#ifdef SKIP_ASM
extern int func_003CCF90_A460(int, int **, int) __asm__("func_003CCF90");
extern void func_003C7010_A460(int, unsigned char, int) __asm__("func_003C7010");
extern short *func_003C6DE0_A460(int, unsigned char, int *, int *) __asm__("func_003C6DE0");
extern void func_00416210_A460(int *, int, int) __asm__("func_00416210");
extern void func_003CD190_A460(int, float *) __asm__("func_003CD190");
extern void func_003CCF60_A460(int, short *, int, int) __asm__("func_003CCF60");

int func_003CA460(char *o, int n, int unused, int *buf) {
    float f[2];
    int *dst;
    int sp14;
    int used = 0;
    int got;
    int flag = 0;

    dst = buf;

    if (*(int *)(o + 0x34) != 0) {
        func_003C7010_A460(*(int *)(o + 0x30), *(unsigned char *)(o + 0x38), *(int *)(o + 0x34));
        *(int *)(o + 0x34) = 0;
    }
    while (n > 0) {
        got = func_003CCF90_A460(*(int *)(o + 0x1C), &dst, n);
        used += got;
        *(int *)(o + 0x28) += got;
        dst += got;
        *(int *)(o + 0x34) += got;
        if (got < n) {
            short *p;
            n -= got;
            p = func_003C6DE0_A460(*(int *)(o + 0x30), *(unsigned char *)(o + 0x38), (int *)(o + 0x24), &sp14);
            *(short **)(o + 0x20) = p;
            if (p != 0) {
                if (*(int *)(o + 0x2C) < 3) flag = 1;
                if (flag) {
                    f[0] = (float)p[0];
                    f[1] = (float)p[1];
                    func_003CD190_A460(*(int *)(o + 0x1C), f);
                    *(short **)(o + 0x20) += 2;
                }
                *(int *)(o + 0x28) = 0;
                func_003CCF60_A460(*(int *)(o + 0x1C), *(short **)(o + 0x20), *(int *)(o + 0x24) * 4, *(int *)(o + 0x24));
            } else {
                if (n > 0 && *(int *)(o + 0x34) != 0) {
                    func_00416210_A460(dst, 0, n * 4);
                }
                n = 0;
            }
        } else {
            n -= got;
        }
    }
    return used;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA5E8);
#ifdef SKIP_ASM
extern void func_003CCF18(int);

void func_003CA5E8(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003CCF18(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA610);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CCEF0_A610(int) __asm__("func_003CCEF0");
extern int func_003CCF40_A610(int) __asm__("func_003CCF40");
extern int func_003CA460_A610[] __asm__("func_003CA460");
extern int func_003CA5E8_A610[] __asm__("func_003CA5E8");

void func_003CA610(void *arg0, void *arg1) {
    (*(int **)((char*)(arg0) + (0))) = func_003CA460_A610;
    (*(int **)((char*)(arg0) + (4))) = func_003CA5E8_A610;
    (*(int *)((char*)(arg0) + (0x30))) = func_003CE378(func_003CE0E0((*(int *)((char*)(arg1) + (0x1C)))));
    (*(signed char *)((char*)(arg0) + (0x38))) = func_003CE118((*(int *)((char*)(arg1) + (0x1C))));
    (*(int *)((char*)(arg0) + (0x2C))) = (int) (*(int *)((char*)(arg1) + (0x24)));
    (*(int *)((char*)(arg0) + (0x20))) = 0;
    (*(int *)((char*)(arg0) + (0x24))) = (int) (*(int *)((char*)(arg1) + (0xC)));
    (*(int *)((char*)(arg0) + (0x28))) = 0;
    (*(int *)((char*)(arg0) + (0x34))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = func_003CCF40_A610(func_003CCEF0_A610(0xA8));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA6A8);
#ifdef SKIP_ASM
struct S3CA6A8 { char p0[8]; int *obj; char p1[0xE]; unsigned char f1A; };
int func_003CA6A8_C(struct S3CA6A8 *self, int n, float *src, short *dst) __asm__("func_003CA6A8");
int func_003CA6A8_C(struct S3CA6A8 *self, int n, float *src, short *dst) {
    if (self->obj) {
        int r = ((int (*)(int *, int, short *, float *, int))*self->obj)(self->obj, n, dst, src, self->f1A);
        if (r <= 0) return r;
    }
    // PORT: PS2-only VU0 hand-written loop (clamp floats to the 16-bit range and pack); one inline asm block.
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        ".set noat\n\t"
        "move $4, %0\n\t"
        "move $5, %1\n\t"
        "move $6, %2\n\t"
        "addiu $8, $0, -0x8000\n\t"
        "addiu $9, $0, 0x7FFF\n\t"
        "qmtc2.ni $8, $vf1\n\t"
        "qmtc2.ni $9, $vf2\n\t"
        "vitof0.xyzw $vf1, $vf1\n\t"
        "vitof0.xyzw $vf2, $vf2\n"
        "1:\n\t"
        "lqc2 $vf3, 0x0($5)\n\t"
        "lqc2 $vf4, 0x10($5)\n\t"
        "lqc2 $vf5, 0x20($5)\n\t"
        "lqc2 $vf6, 0x30($5)\n\t"
        "vmaxx.xyzw $vf3, $vf3, $vf1x\n\t"
        "vmaxx.xyzw $vf4, $vf4, $vf1x\n\t"
        "vmaxx.xyzw $vf5, $vf5, $vf1x\n\t"
        "vmaxx.xyzw $vf6, $vf6, $vf1x\n\t"
        "vminix.xyzw $vf3, $vf3, $vf2x\n\t"
        "vminix.xyzw $vf4, $vf4, $vf2x\n\t"
        "vminix.xyzw $vf5, $vf5, $vf2x\n\t"
        "vminix.xyzw $vf6, $vf6, $vf2x\n\t"
        "vftoi0.xyzw $vf3, $vf3\n\t"
        "vftoi0.xyzw $vf4, $vf4\n\t"
        "vftoi0.xyzw $vf5, $vf5\n\t"
        "vftoi0.xyzw $vf6, $vf6\n\t"
        "addi $4, $4, -0x10\n\t"
        "addi $5, $5, 0x40\n\t"
        "qmfc2.ni $7, $vf3\n\t"
        "qmfc2.ni $8, $vf4\n\t"
        "qmfc2.ni $9, $vf5\n\t"
        "qmfc2.ni $10, $vf6\n\t"
        "ppach $7, $8, $7\n\t"
        "ppach $9, $10, $9\n\t"
        "sq $7, 0x0($6)\n\t"
        "sq $9, 0x10($6)\n\t"
        "bgtzl $4, 1b\n\t"
        "addi $6, $6, 0x20\n\t"
        ".set pop\n"
        : : "r"(n), "r"(src), "r"(dst)
        : "$4", "$5", "$6", "$7", "$8", "$9", "$10", "memory");
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA7A0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CA6A8_A7A0(void) __asm__("func_003CA6A8");

void func_003CA7A0(void *arg0) {
    *(int *)((char *)arg0 + 4) = 0;
    *(void (**)(void))((char *)arg0 + 0) = func_003CA6A8_A7A0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA7B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef int (*vfn_A7B8)(void *, int, float *, float *, unsigned char);
int func_003CA7B8_A7B8(char *, int, float *, float *) __asm__("func_003CA7B8");
int func_003CA7B8_A7B8(char *self, int n, float *in, float *out) {
    void **o = *(void ***)(self + 8);
    int r;
    float *st;
    int i;
    if (o == 0 || (r = ((vfn_A7B8)(*(void **)o))(o, n, out, in, *(unsigned char *)(self + 0x1A))) > 0) {
        st = (float *)(self + 0x1C);
        for (i = 0; i < n; i++) {
            st[0] = st[0] * st[1] + st[2] * in[i];
            out[i] = st[0];
        }
        r = n;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA870);
#ifdef SKIP_ASM
extern void func_003CA7B8();

int func_003CA870(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(void (**)())((char*)(arg0) + (0))) = func_003CA7B8;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA8A0);
#ifdef SKIP_ASM
void func_003CA8A0(void *arg0, void *arg1) {
    float temp_f1;
    float temp_f2;

    temp_f1 = (2.0f * (float) (*(int *)((char*)(arg1) + (0)))) / (float) (*(int *)((char*)(arg1) + (4)));
    temp_f2 = 1.0f - temp_f1;
    (*(float *)((char*)(arg0) + (0x24))) = temp_f1;
    (*(float *)((char*)(arg0) + (0x20))) = temp_f2;
    (*(float *)((char*)(arg0) + (0x24))) = (float) (temp_f1 * ((float) (*(int *)((char*)(arg1) + (8))) * 0.00390625f));
    (*(float *)((char*)(arg0) + (0x20))) = (float) (temp_f2 * ((float) (*(int *)((char*)(arg1) + (8))) * 0.00390625f));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA900);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CEBE8_A900(void *, int, int, int) __asm__("func_003CEBE8");

int func_003CA900(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CEBE8_A900(p + 0x20, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CA990);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_A990;
extern void func_003CEB90(void *);
extern void func_003CA900_x(void) __asm__("func_003CA900");

int func_003CA990(S_A990 *self) {
    self->vt = func_003CA900_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CA9D8);
#ifdef SKIP_ASM
extern void func_003CE7C0_A9D8(char *, int) __asm__("func_003CE7C0");

void func_003CA9D8(char *arg0, int *arg1) {
    *(float *)(arg0 + 0x114) = (float)(arg1[0] >> 7) / (float)(arg1[1] >> 8);
    func_003CE7C0_A9D8(arg0 + 0x20, 3);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CAA28);
#ifdef SKIP_ASM
void func_003CAA28(float* a, float* b, float* d, int n, int m)
{
    float t, step;
    int i;
    if (m > 0) {
        step = -1.0f / (float)n;
        t = 1.0f;
    } else {
        m = -m;
        step = 1.0f / (float)n;
        t = 0.0f;
    }
    if (m < n) {
        float* pd = d;
        float* pa = a;
        int k = 0;
        i = n - m;
        do {
            *pd = t * a[m + k] + (1.0f - t) * *pa;
            t += step;
            k++;
            pa++;
            pd++;
        } while (--i != 0);
    }
    if (m > 0) {
        int k = 0;
        int j = n - m;
        i = m;
        do {
            d[j + k] = t * b[k] + (1.0f - t) * a[j + k];
            t += step;
            k++;
        } while (--i != 0);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CAB28);
#ifdef SKIP_ASM
#define FABS_AB28(x) ((x) < 0.0f ? -(x) : (x))
int func_003CAB28(int n, unsigned char **pp, float *err, float t) {
    int k = **pp + n / 2;
    float e1, e2;
    if (t < 1.0f) {
        e1 = ((float)n + *err) - t * n;
        e2 = ((float)(n * 2 - k) + *err) - (t + t) * n;
        if (FABS_AB28(e1) < FABS_AB28(e2)) {
            *pp += 1;
            *err = e1;
            return 0;
        }
        *pp += 2;
        *err = e2;
        return -k;
    } else {
        float tn = t * n;
        e1 = ((float)n + *err) - tn;
        e2 = ((float)(n + k) + *err) - tn;
        if (FABS_AB28(e1) < FABS_AB28(e2)) {
            *pp += 1;
            *err = e1;
            return 0;
        }
        *pp += 1;
        *err = e2;
        return k;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CAC88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CAA28_AC88(void *, void *, void *, int, int) __asm__("func_003CAA28");

void func_003CAC88(char *arg0, char **arg1, int arg2) {
    char *v18;
    char *v20;
    if (*(int *)(arg0 + 0x34) > 0) {
        v18 = arg0 + 0x40;
        v20 = *arg1;
    } else {
        v18 = *arg1;
        v20 = v18 + *(int *)(arg0 + 0x2C) * 4;
    }
    if (arg2 == 0) {
        func_003C51E8(arg0 + 0x838, v18, *(int *)(arg0 + 0x2C) * 4);
        *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - *(int *)(arg0 + 0x2C);
        *(int *)(arg0 + 0x38) = *(int *)(arg0 + 0x2C);
        *arg1 = v20;
    } else {
        if (arg2 > 0) {
            int t = arg2 * 4;
            func_003C51E8(arg0 + 0x838, v18, t);
            func_003CAA28_AC88(v18, v20, arg0 + (t + 0x838), *(int *)(arg0 + 0x2C), arg2);
            *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - *(int *)(arg0 + 0x2C);
            *(int *)(arg0 + 0x38) = *(int *)(arg0 + 0x2C) + arg2;
            *arg1 = v20;
        } else {
            int m, d, n;
            func_003CAA28_AC88(v18, v20, arg0 + 0x838, *(int *)(arg0 + 0x2C), arg2);
            m = *(int *)(arg0 + 0x2C);
            func_003C51E8(arg0 + ((m * 4) + 0x838), v20 - arg2 * 4, (m + arg2) * 4);
            n = *(int *)(arg0 + 0x2C);
            d = n * 2;
            *(int *)(arg0 + 0x30) = *(int *)(arg0 + 0x30) - d;
            *(int *)(arg0 + 0x38) = d + arg2;
            *arg1 = v20 + n * 4;
        }
    }
    *(int *)(arg0 + 0x34) = 0;
    *(int *)(arg0 + 0x3C) = 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CADF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003C51E8_ADF0(int, void *, int) __asm__("func_003C51E8");

int func_003CADF0(void *arg0, int *arg1, int *arg2) {
    int temp_16;
    int temp_16_2;
    int temp_20;
    int temp_3;

    temp_16_2 = (*(int *)((char*)(arg0) + (0x38)));
    temp_3 = *arg1;
    temp_16 = temp_16_2;
    if (temp_16_2 >= temp_3) temp_16 = temp_3;
    temp_20 = temp_16 * 4;
    func_003C51E8_ADF0(*arg2, arg0 + (((*(int *)((char*)(arg0) + (0x3C))) * 4) + 0x838), temp_20);
    (*(int *)((char*)(arg0) + (0x3C))) = (int) ((*(int *)((char*)(arg0) + (0x3C))) + temp_16);
    (*(int *)((char*)(arg0) + (0x38))) = (int) ((*(int *)((char*)(arg0) + (0x38))) - temp_16);
    *arg1 -= temp_16;
    *arg2 += temp_20;
    return temp_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CAEA0);
#ifdef SKIP_ASM
struct S_AEA0 { char pad[0x1C]; int w1C; char pad20[4]; float f24; float f28; int w2C; int w30; int w34; int w38; };
extern int func_003CAB28_AEA0(float, int, int *, float *) __asm__("func_003CAB28");
int func_003CAEA0(struct S_AEA0 *p, int n) {
    int pos;
    float err;
    int tot;
    int t;
    int avail;
    int step;
    int used;
    if (p->w38 < n) {
        n -= p->w38;
        pos = p->w1C;
        err = p->f28;
        tot = 0;
        t = 0;
        avail = p->w30;
        while (n > 0) {
            int lo = p->w2C;
            if (avail < lo) break;
            t = 0;
            if (avail >= p->w2C * 2) t = func_003CAB28_AEA0(p->f24, p->w2C, &pos, &err);
            if (t >= 0) { step = p->w2C; used = step + t; } else { step = p->w2C * 2; used = step + t; }
            tot += step;
            avail -= step;
            if (used >= n) n = 0; else n -= used;
        }
        if (t > 0) tot += p->w2C;
        if (n > 0) {
            if (avail < n) tot += avail; else tot += n;
        }
        if (p->w34 < tot) return tot - p->w34;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CAFD0);
#ifdef SKIP_ASM
extern int fADF0_AFD0(void *, int *, int *) __asm__("func_003CADF0");
extern void fAC88_AFD0(void *, char **, long) __asm__("func_003CAC88");
extern long fAB28_AFD0(float, int, void *, void *) __asm__("func_003CAB28");
extern void f51E8_AFD0(void *, void *, int) __asm__("func_003C51E8");

int func_003CAFD0(char *self, int cnt, char *buf, char *dst) {
    int r = fADF0_AFD0(self, &cnt, (int *)&dst);
    long t;
    if (cnt == 0) return r;
    t = 0;
    while (cnt > 0) {
        int hi = *(int *)(self + 0x30);
        int lo = *(int *)(self + 0x2C);
        if (hi < lo)
            break;
        t = 0;
        if (*(int *)(self + 0x30) >= *(int *)(self + 0x2C) * 2)
            t = fAB28_AFD0(*(float *)(self + 0x24), *(int *)(self + 0x2C), self + 0x1C, self + 0x28);
        fAC88_AFD0(self, &buf, t);
        r += fADF0_AFD0(self, &cnt, (int *)&dst);
    }
    if (t > 0) {
        f51E8_AFD0(self + 0x40, buf, *(int *)(self + 0x2C) * 4);
        *(int *)(self + 0x34) = *(int *)(self + 0x2C);
        buf += *(int *)(self + 0x2C) * 4;
    }
    if (cnt > 0) {
        int n = *(int *)(self + 0x30);
        if (n >= cnt)
            n = cnt;
        r += n;
        f51E8_AFD0(dst, buf, n * 4);
        *(int *)(self + 0x30) -= n;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB110);
#ifdef SKIP_ASM
struct S_B110 { char pad[0x24]; float f24; };

void func_003CB110(struct S_B110 *p, int v) {
    p->f24 = (float)v * 0.000244140625f;
    if ((double)p->f24 < 0.5) {
        p->f24 = 0.5f;
    } else if ((double)p->f24 > 2.0) {
        p->f24 = 2.0f;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB1A8);
#ifdef SKIP_ASM
struct O_B1A8 { int (*fn)(struct O_B1A8 *, int, int *, int, int); };
struct S_B1A8 { char pad0[8]; struct O_B1A8 *f8; char padC[0xE]; unsigned char f1A; char pad1B[5]; int f20; };
extern int f_AEA0_B1A8(struct S_B1A8 *, int) __asm__("func_003CAEA0");
extern int f_AFD0_B1A8(struct S_B1A8 *, int, int, int *) __asm__("func_003CAFD0");
extern int func_003C6C98(int);
extern void f_6210_B1A8(int *, int, int) __asm__("func_00416210");

int func_003CB1A8_impl(struct S_B1A8 *, int, int, int *) __asm__("func_003CB1A8");
int func_003CB1A8_impl(struct S_B1A8 *s, int n, int a2, int *buf) {
    int w = f_AEA0_B1A8(s, n);
    int r;
    if (s->f20 >= 0) {
        if (func_003C6C98(s->f20) < w) return 0;
    }
    if (w > 0) {
        r = s->f8->fn(s->f8, w, buf, a2, s->f1A);
        if (r <= 0) return r;
    }
    r = f_AFD0_B1A8(s, n, a2, buf);
    if (r < n) {
        f_6210_B1A8(buf + r, 0, (n - r) * 4);
    }
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CB280);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003C72F8(int, int);
extern int func_003CE0E0(int);
extern int func_003CE378(int);
extern char func_003CB1A8_B280[] __asm__("func_003CB1A8");

int func_003CB280(void *arg0, void *arg1, int arg2) {
    (*(char **)((char*)(arg0) + (0))) = func_003CB1A8_B280;
    (*(int *)((char*)(arg0) + (4))) = 0;
    if (arg2 >= 0) {
        (*(int *)((char*)(arg0) + (0x20))) = func_003CE378(func_003CE0E0(arg2));
    } else {
        (*(int *)((char*)(arg0) + (0x20))) = -1;
    }
    (*(int *)((char*)(arg0) + (0x1C))) = (int) (arg1 + 6);
    (*(float *)((char*)(arg0) + (0x24))) = 1.0f;
    (*(int *)((char*)(arg0) + (0x28))) = 0;
    (*(int *)((char*)(arg0) + (0x2C))) = (int) ((*(unsigned char *)((char*)(arg1) + (1))) * 2);
    (*(int *)((char*)(arg0) + (0x30))) = func_003C72F8(arg1 + 2, 4);
    (*(int *)((char*)(arg0) + (0x34))) = 0;
    (*(int *)((char*)(arg0) + (0x38))) = 0;
    (*(int *)((char*)(arg0) + (0x3C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB328);
#ifdef SKIP_ASM
struct O_B328 {
    char pad0[8]; int (**f8)(); char padC[0x1A - 0xC]; unsigned char b1A; char pad1B[0x20 - 0x1B];
    short s20; char pad22[0x30 - 0x22]; short s30; char pad32[0x40 - 0x32]; short s40;
};

int func_003CB328(struct O_B328 *o, int n, short *src, short *dst) {
    int i;
    short *sp;
    short *dp;
    int r;
    if (o->f8) {
        r = (*o->f8)(o->f8, n, dst, src, o->b1A);
        if (r <= 0) {
            return r;
        }
    }
    sp = src;
    dp = dst;
    for (i = 0; i < n; i += 4) {
        int a, b, c, d; short t0, t1, t2, t3;
        a = sp[0];
        if (a > o->s30) t0 = o->s30; else if (a < o->s20) t0 = o->s20; else t0 = a;
        b = sp[1];
        if (b > o->s30) t1 = o->s30; else if (b < o->s20) t1 = o->s20; else t1 = b;
        c = sp[2];
        if (c > o->s30) t2 = o->s30; else if (c < o->s20) t2 = o->s20; else t2 = c;
        d = sp[3];
        if (d > o->s30) t3 = o->s30; else if (d < o->s20) t3 = o->s20; else t3 = d;
        dp[0] = (t0 * o->s40) >> 7;
        dp[1] = (t1 * o->s40) >> 7;
        dp[2] = (t2 * o->s40) >> 7;
        dp[3] = (t3 * o->s40) >> 7;
        sp += 4;
        dp += 4;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB4A8);
#ifdef SKIP_ASM
struct P { char pad[0x20]; short A[8]; short B[8]; short C[8]; };
void func_003CB4A8(struct P* p, int x)
{
    int t = (x * 0x7D00) >> 15;
    int b = 0x7FFF - t;
    int i;
    p->A[0] = t - 0x8000;
    p->B[0] = b;
    p->C[0] = 0x3FDE00 / (short)b;
    for (i = 1; i < 8; i++) {
        p->A[i] = p->A[0];
        p->B[i] = p->B[0];
        p->C[i] = p->C[0];
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CB528);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CB328_B528(void) __asm__("func_003CB328");

void func_003CB528(void (**arg0)(void)) {
    *arg0 = func_003CB328_B528;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB538);
#ifdef SKIP_ASM
void func_003CB538(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0x1C))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CB540);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written routine (splat-marked; hand-written add/addi in its VU0/MMI loop, all values kept in stack slots around a 156-instruction VU0 block, callback through jalr); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003CB540\n.type func_003CB540, @function\nfunc_003CB540:\n"
    "addiu $29, $29, -0xE0\n"
    "daddu $10, $6, $0\n"
    "sw $4, 0x30($29)\n"
    "daddu $6, $7, $0\n"
    "sw $5, 0x0($29)\n"
    "lui $2, (0x10000 >> 16)\n"
    "sq $16, 0xD0($29)\n"
    "sq $17, 0xC0($29)\n"
    "daddu $8, $5, $0\n"
    "sq $18, 0xB0($29)\n"
    "sq $19, 0xA0($29)\n"
    "sq $20, 0x90($29)\n"
    "sq $21, 0x80($29)\n"
    "sq $22, 0x70($29)\n"
    "sq $23, 0x60($29)\n"
    "sq $30, 0x50($29)\n"
    "sd $31, 0x40($29)\n"
    "sw $4, 0x4($29)\n"
    "lw $3, 0x1C($4)\n"
    "sw $10, 0x20($29)\n"
    ".word 0x14620058 /* bne $3, $2, .L003CB6F4: raw word */\n"
    "sw $6, 0x8($29)\n"
    "lh $2, 0x24($4)\n"
    ".word 0x14400005 /* bnez $2, .L003CB5B4: raw word */\n"
    "lw $2, 0x30($29)\n"
    "lh $3, 0x26($4)\n"
    "addiu $2, $5, 0x4\n"
    ".word 0x1000001D /* b .L003CB624: raw word */\n"
    "subu $5, $2, $3\n"
    ".L003CB5B4:\n"
    "lw $4, 0x30($29)\n"
    "lh $3, 0x26($2)\n"
    "addiu $2, $0, 0x4\n"
    "lhu $7, 0x26($4)\n"
    "subu $2, $2, $3\n"
    ".word 0x18400016 /* blez $2, .L003CB624: raw word */\n"
    "daddu $4, $0, $0\n"
    "lw $6, 0x30($29)\n"
    "addiu $9, $0, 0x4\n"
    "addiu $3, $6, 0x28\n"
    "nop\n"
    ".L003CB5E0:\n"
    "sll $2, $7, 16\n"
    "lw $25, 0x8($29)\n"
    "sra $2, $2, 16\n"
    "addu $2, $4, $2\n"
    "sll $2, $2, 2\n"
    "addiu $4, $4, 0x1\n"
    "addu $2, $3, $2\n"
    "lwc1 $f0, 0x0($2)\n"
    "swc1 $f0, 0x0($25)\n"
    "addiu $25, $25, 0x4\n"
    "sw $25, 0x8($29)\n"
    "lw $30, 0x30($29)\n"
    "lh $2, 0x26($30)\n"
    "subu $2, $9, $2\n"
    "slt $2, $4, $2\n"
    ".word 0x1440FFF0 /* bnez $2, .L003CB5E0: raw word */\n"
    "lhu $7, 0x26($30)\n"
    ".L003CB624:\n"
    "lw $2, 0x30($29)\n"
    "lw $4, 0x8($2)\n"
    ".word 0x10800007 /* beqz $4, .L003CB64C: raw word */\n"
    "lw $3, 0x30($29)\n"
    "daddu $6, $10, $0\n"
    "lw $2, 0x0($4)\n"
    "lbu $8, 0x1A($3)\n"
    "jalr $2\n"
    "lw $7, 0x8($29)\n"
    "daddu $8, $2, $0\n"
    ".L003CB64C:\n"
    ".word 0x1D00000E /* bgtz $8, .L003CB688: raw word */\n"
    "lw $6, 0x30($29)\n"
    "lw $4, 0x30($29)\n"
    "lh $2, 0x24($4)\n"
    ".word 0x14400004 /* bnez $2, .L003CB670: raw word */\n"
    "lw $5, 0x30($29)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0x24($4)\n"
    "lw $5, 0x30($29)\n"
    ".L003CB670:\n"
    "daddu $2, $8, $0\n"
    "sw $0, 0x34($5)\n"
    "sw $0, 0x28($5)\n"
    "sw $0, 0x2C($5)\n"
    ".word 0x1000011C /* b .L003CBAF4: raw word */\n"
    "sw $0, 0x30($5)\n"
    ".L003CB688:\n"
    "lh $2, 0x24($6)\n"
    ".word 0x1440000A /* bnez $2, .L003CB6B8: raw word */\n"
    "lw $3, 0x0($29)\n"
    "addiu $3, $0, 0x1\n"
    "lh $2, 0x26($6)\n"
    "sh $3, 0x24($6)\n"
    "lw $25, 0x0($29)\n"
    "lw $30, 0x8($29)\n"
    "subu $2, $25, $2\n"
    "sll $2, $2, 2\n"
    ".word 0x10000005 /* b .L003CB6C8: raw word */\n"
    "addu $7, $30, $2\n"
    ".L003CB6B8:\n"
    "lw $4, 0x8($29)\n"
    "sll $2, $3, 2\n"
    "addiu $2, $2, -0x10\n"
    "addu $7, $4, $2\n"
    ".L003CB6C8:\n"
    "lwc1 $f1, 0x0($7)\n"
    "lw $5, 0x30($29)\n"
    "lw $2, 0x0($29)\n"
    "swc1 $f1, 0x28($5)\n"
    "lwc1 $f0, 0x4($7)\n"
    "swc1 $f0, 0x2C($5)\n"
    "lwc1 $f1, 0x8($7)\n"
    "swc1 $f1, 0x30($5)\n"
    "lwc1 $f0, 0xC($7)\n"
    ".word 0x10000101 /* b .L003CBAF4: raw word */\n"
    "swc1 $f0, 0x34($5)\n"
    ".L003CB6F4:\n"
    "lw $25, 0x0($29)\n"
    "lw $30, 0x30($29)\n"
    "mult $2, $3, $25\n"
    "lw $3, 0x20($30)\n"
    "lh $4, 0x24($30)\n"
    "addu $2, $2, $3\n"
    ".word 0x14800013 /* bnez $4, .L003CB75C: raw word */\n"
    "srl $5, $2, 16\n"
    "lh $3, 0x26($30)\n"
    "addiu $2, $5, 0x4\n"
    "daddu $4, $0, $0\n"
    ".word 0x1860001A /* blez $3, .L003CB78C: raw word */\n"
    "subu $5, $2, $3\n"
    "lw $2, 0x20($29)\n"
    "nop\n"
    ".L003CB730:\n"
    "addiu $4, $4, 0x1\n"
    "sw $0, 0x0($2)\n"
    "addiu $2, $2, 0x4\n"
    "lw $3, 0x30($29)\n"
    "sw $2, 0x20($29)\n"
    "lh $2, 0x26($3)\n"
    "slt $2, $4, $2\n"
    ".word 0x1440FFF8 /* bnez $2, .L003CB730: raw word */\n"
    "lw $2, 0x20($29)\n"
    ".word 0x1000000D /* b .L003CB78C: raw word */\n"
    "nop\n"
    ".L003CB75C:\n"
    "lw $4, 0x30($29)\n"
    "lw $25, 0x20($29)\n"
    "lwc1 $f0, 0x28($4)\n"
    "swc1 $f0, 0x0($25)\n"
    "lwc1 $f1, 0x2C($4)\n"
    "swc1 $f1, 0x4($25)\n"
    "lwc1 $f0, 0x30($4)\n"
    "swc1 $f0, 0x8($25)\n"
    "lwc1 $f1, 0x34($4)\n"
    "swc1 $f1, 0xC($25)\n"
    "addiu $25, $25, 0x10\n"
    "sw $25, 0x20($29)\n"
    ".L003CB78C:\n"
    ".word 0x18A00018 /* blez $5, .L003CB7F0: raw word */\n"
    "lw $30, 0x30($29)\n"
    "lw $4, 0x8($30)\n"
    ".word 0x50800016 /* beql $4, $0, .L003CB7F4: raw word */\n"
    "lw $4, 0x30($29)\n"
    "lbu $8, 0x1A($30)\n"
    "lw $2, 0x0($4)\n"
    "jalr $2\n"
    "lw $7, 0x20($29)\n"
    "daddu $8, $2, $0\n"
    ".word 0x1D00000F /* bgtz $8, .L003CB7F4: raw word */\n"
    "lw $4, 0x30($29)\n"
    "lh $2, 0x24($30)\n"
    ".word 0x14400004 /* bnez $2, .L003CB7D4: raw word */\n"
    "lw $2, 0x30($29)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0x24($30)\n"
    "lw $2, 0x30($29)\n"
    ".L003CB7D4:\n"
    "sw $0, 0x34($2)\n"
    "daddu $2, $8, $0\n"
    "lw $3, 0x30($29)\n"
    "sw $0, 0x28($3)\n"
    "sw $0, 0x2C($3)\n"
    ".word 0x100000C2 /* b .L003CBAF4: raw word */\n"
    "sw $0, 0x30($3)\n"
    ".L003CB7F0:\n"
    "lw $4, 0x30($29)\n"
    ".L003CB7F4:\n"
    "lh $2, 0x24($4)\n"
    ".word 0x10400008 /* beqz $2, .L003CB81C: raw word */\n"
    "addiu $2, $0, 0x4\n"
    "lh $3, 0x26($4)\n"
    "lw $5, 0x20($29)\n"
    "subu $2, $2, $3\n"
    "sll $2, $2, 2\n"
    "subu $5, $5, $2\n"
    ".word 0x10000004 /* b .L003CB828: raw word */\n"
    "sw $5, 0x20($29)\n"
    ".L003CB81C:\n"
    "lw $6, 0x30($29)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0x24($6)\n"
    ".L003CB828:\n"
    "lw $25, 0x4($29)\n"
    "lw $30, 0x0($29)\n"
    "lw $2, 0x20($29)\n"
    "lw $3, 0x8($29)\n"
    "daddu $4, $25, $0\n"
    "daddu $5, $30, $0\n"
    "daddu $6, $2, $0\n"
    "daddu $7, $3, $0\n"
    "lw $10, 0x1C($4)\n"
    "sll $8, $10, 2\n"
    "pextlw $8, $8, $8\n"
    "pextlw $8, $8, $8\n"
    "sll $11, $10, 1\n"
    "add $12, $11, $10\n"
    "pextlw $9, $11, $0\n"
    "pextlw $14, $12, $10\n"
    "pextlw $9, $14, $9\n"
    "paddw $10, $9, $8\n"
    "paddw $11, $10, $8\n"
    "paddw $12, $11, $8\n"
    "psllw $8, $8, 2\n"
    "lw $13, 0x20($4)\n"
    "pextlw $13, $13, $13\n"
    "pextlw $13, $13, $13\n"
    "lui $14, (0x37800000 >> 16)\n"
    "qmtc2.ni $14, $vf1\n"
    "sll $5, $5, 2\n"
    "add $5, $5, $7\n"
    "mtsab $0, 0x4\n"
    ".L003CB89C:\n"
    "paddw $14, $13, $9\n"
    "paddw $15, $13, $10\n"
    "paddw $16, $13, $11\n"
    "paddw $17, $13, $12\n"
    "paddw $13, $13, $8\n"
    "pinteh $18, $0, $14\n"
    "pinteh $19, $0, $15\n"
    "pinteh $20, $0, $16\n"
    "pinteh $21, $0, $17\n"
    "qmtc2.ni $18, $vf2\n"
    "qmtc2.ni $19, $vf3\n"
    "qmtc2.ni $20, $vf4\n"
    "qmtc2.ni $21, $vf5\n"
    "vitof0.xyzw $vf2, $vf2\n"
    "vitof0.xyzw $vf3, $vf3\n"
    "pextlw $18, $6, $6\n"
    "vitof0.xyzw $vf4, $vf4\n"
    "vitof0.xyzw $vf5, $vf5\n"
    "vmulx.xyzw $vf2, $vf2, $vf1x\n"
    "vmulx.xyzw $vf3, $vf3, $vf1x\n"
    "pextlw $18, $18, $18\n"
    "vmulx.xyzw $vf4, $vf4, $vf1x\n"
    "vmulx.xyzw $vf5, $vf5, $vf1x\n"
    "psrlw $14, $14, 16\n"
    "psrlw $15, $15, 16\n"
    "psrlw $16, $16, 16\n"
    "psrlw $17, $17, 16\n"
    "psllw $14, $14, 2\n"
    "psllw $15, $15, 2\n"
    "psllw $16, $16, 2\n"
    "psllw $17, $17, 2\n"
    "paddw $14, $14, $18\n"
    "paddw $15, $15, $18\n"
    "paddw $16, $16, $18\n"
    "paddw $17, $17, $18\n"
    "qfsrv $18, $0, $14\n"
    "lw $19, 0x0($14)\n"
    "lw $20, 0x4($14)\n"
    "qfsrv $14, $0, $18\n"
    "lw $21, 0x0($18)\n"
    "lw $22, 0x4($18)\n"
    "dsrl32 $18, $14, 0\n"
    "lw $23, 0x0($14)\n"
    "lw $24, 0x4($14)\n"
    "pextlw $19, $23, $19\n"
    "lw $23, 0x0($18)\n"
    "lw $14, 0x4($18)\n"
    "pextlw $20, $24, $20\n"
    "pextlw $21, $23, $21\n"
    "pextlw $22, $14, $22\n"
    "pextlw $19, $21, $19\n"
    "pextlw $20, $22, $20\n"
    "qmtc2.ni $19, $vf6\n"
    "qmtc2.ni $20, $vf10\n"
    "qfsrv $18, $0, $15\n"
    "lw $19, 0x0($15)\n"
    "lw $20, 0x4($15)\n"
    "qfsrv $15, $0, $18\n"
    "lw $21, 0x0($18)\n"
    "lw $22, 0x4($18)\n"
    "dsrl32 $18, $15, 0\n"
    "lw $23, 0x0($15)\n"
    "lw $24, 0x4($15)\n"
    "pextlw $19, $23, $19\n"
    "lw $23, 0x0($18)\n"
    "lw $14, 0x4($18)\n"
    "pextlw $20, $24, $20\n"
    "pextlw $21, $23, $21\n"
    "pextlw $22, $14, $22\n"
    "pextlw $19, $21, $19\n"
    "pextlw $20, $22, $20\n"
    "qmtc2.ni $19, $vf7\n"
    "qmtc2.ni $20, $vf11\n"
    "qfsrv $18, $0, $16\n"
    "lw $19, 0x0($16)\n"
    "lw $20, 0x4($16)\n"
    "qfsrv $16, $0, $18\n"
    "lw $21, 0x0($18)\n"
    "lw $22, 0x4($18)\n"
    "dsrl32 $18, $16, 0\n"
    "lw $23, 0x0($16)\n"
    "lw $24, 0x4($16)\n"
    "pextlw $19, $23, $19\n"
    "lw $23, 0x0($18)\n"
    "lw $14, 0x4($18)\n"
    "pextlw $20, $24, $20\n"
    "pextlw $21, $23, $21\n"
    "pextlw $22, $14, $22\n"
    "pextlw $19, $21, $19\n"
    "pextlw $20, $22, $20\n"
    "qmtc2.ni $19, $vf8\n"
    "qmtc2.ni $20, $vf12\n"
    "qfsrv $18, $0, $17\n"
    "lw $19, 0x0($17)\n"
    "lw $20, 0x4($17)\n"
    "qfsrv $17, $0, $18\n"
    "lw $21, 0x0($18)\n"
    "lw $22, 0x4($18)\n"
    "dsrl32 $18, $17, 0\n"
    "lw $23, 0x0($17)\n"
    "lw $24, 0x4($17)\n"
    "pextlw $19, $23, $19\n"
    "lw $23, 0x0($18)\n"
    "lw $14, 0x4($18)\n"
    "pextlw $20, $24, $20\n"
    "pextlw $21, $23, $21\n"
    "pextlw $22, $14, $22\n"
    "pextlw $19, $21, $19\n"
    "pextlw $20, $22, $20\n"
    "qmtc2.ni $19, $vf9\n"
    "qmtc2.ni $20, $vf13\n"
    "addi $7, $7, 0x40\n"
    "vsub.xyzw $vf10, $vf10, $vf6\n"
    "vsub.xyzw $vf11, $vf11, $vf7\n"
    "vsub.xyzw $vf12, $vf12, $vf8\n"
    "vsub.xyzw $vf13, $vf13, $vf9\n"
    "vmul.xyzw $vf10, $vf10, $vf2\n"
    "vmul.xyzw $vf11, $vf11, $vf3\n"
    "vmul.xyzw $vf12, $vf12, $vf4\n"
    "vmul.xyzw $vf13, $vf13, $vf5\n"
    "vadd.xyzw $vf10, $vf10, $vf6\n"
    "vadd.xyzw $vf11, $vf11, $vf7\n"
    "vadd.xyzw $vf12, $vf12, $vf8\n"
    "vadd.xyzw $vf13, $vf13, $vf9\n"
    "sqc2 $vf10, -0x40($7)\n"
    "sqc2 $vf11, -0x30($7)\n"
    "sqc2 $vf12, -0x20($7)\n"
    ".word 0x14A7FF80 /* bne $5, $7, .L003CB89C: raw word */\n"
    "sqc2 $vf13, -0x10($7)\n"
    "sw $13, 0x20($4)\n"
    "lw $4, 0x30($29)\n"
    "daddu $2, $30, $0\n"
    "lw $6, 0x20($29)\n"
    "lw $5, 0x20($4)\n"
    "lh $4, 0x26($4)\n"
    "srl $3, $5, 16\n"
    "lw $25, 0x30($29)\n"
    "subu $3, $3, $4\n"
    "andi $5, $5, 0xFFFF\n"
    "sll $3, $3, 2\n"
    "addu $7, $6, $3\n"
    "lwc1 $f0, 0x0($7)\n"
    "swc1 $f0, 0x28($25)\n"
    "lwc1 $f1, 0x4($7)\n"
    "swc1 $f1, 0x2C($25)\n"
    "lwc1 $f0, 0x8($7)\n"
    "swc1 $f0, 0x30($25)\n"
    "lwc1 $f1, 0xC($7)\n"
    "sw $5, 0x20($25)\n"
    "swc1 $f1, 0x34($25)\n"
    ".L003CBAF4:\n"
    "lq $16, 0xD0($29)\n"
    "lq $17, 0xC0($29)\n"
    "lq $18, 0xB0($29)\n"
    "lq $19, 0xA0($29)\n"
    "lq $20, 0x90($29)\n"
    "lq $21, 0x80($29)\n"
    "lq $22, 0x70($29)\n"
    "lq $23, 0x60($29)\n"
    "lq $30, 0x50($29)\n"
    "ld $31, 0x40($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xE0\n"
    ".size func_003CB540, . - func_003CB540\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CBB28);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_BB28_vt(void) __asm__("func_003CB540");

void func_003CBB28(int *self) {
    int i;
    self[1] = 0;
    self[8] = 0;
    self[0] = (int)f_BB28_vt;
    ((short *)self)[0x24 / 2] = 0;
    ((short *)self)[0x26 / 2] = 0;
    for (i = 3; i >= 0; i--)
        self[0xA + i] = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBB78);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written VU0 loop (add/addi, no compiler emits them); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
void func_003CBB78(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "daddu $3, $4, $0\n"
        "daddu $2, $6, $0\n"
        "mfc1 $8, $f12\n"
        "daddu $4, $3, $0\n"
        "qmtc2.ni $8, $vf1\n"
        "sll $4, $4, 2\n"
        "daddu $6, $5, $0\n"
        "daddu $7, $2, $0\n"
        "add $4, $4, $6\n"
        "1:\n"
        "lqc2 $vf2, 0x0($6)\n"
        "lqc2 $vf3, 0x10($6)\n"
        "lqc2 $vf4, 0x20($6)\n"
        "lqc2 $vf5, 0x30($6)\n"
        "lqc2 $vf6, 0x0($7)\n"
        "lqc2 $vf7, 0x10($7)\n"
        "lqc2 $vf8, 0x20($7)\n"
        "lqc2 $vf9, 0x30($7)\n"
        "vmulx.xyzw $vf2, $vf2, $vf1x\n"
        "vmulx.xyzw $vf3, $vf3, $vf1x\n"
        "vmulx.xyzw $vf4, $vf4, $vf1x\n"
        "vmulx.xyzw $vf5, $vf5, $vf1x\n"
        "vadd.xyzw $vf6, $vf6, $vf2\n"
        "vadd.xyzw $vf7, $vf7, $vf3\n"
        "addi $6, $6, 0x40\n"
        "vadd.xyzw $vf8, $vf8, $vf4\n"
        "vadd.xyzw $vf9, $vf9, $vf5\n"
        "sqc2 $vf6, 0x0($7)\n"
        "sqc2 $vf7, 0x10($7)\n"
        "sqc2 $vf8, 0x20($7)\n"
        "sqc2 $vf9, 0x30($7)\n"
        "bne $4, $6, 1b\n"
        "addi $7, $7, 0x40\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC00);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003CBC00(int *arg0) {
    D_00515B54 = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00515D80_BC10[4] __asm__("D_00515D80");

int *func_003CBC10(void) {
    return D_00515D80_BC10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CBC20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern unsigned char D_0044E770_BC20[][6][6] __asm__("D_0044E770");

unsigned char func_003CBC20(int arg0, int arg1, int arg2) {
    return D_0044E770_BC20[arg0 - 1][arg1 - 1][arg2 - 1];
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CBC58);

INCLUDE_ASM("ealib/seg_2B4578", func_003CBEC8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC070);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Hdr_C070 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    int f4;
    unsigned char cnt[6][4];
    unsigned char len[6][4];
};
extern struct Hdr_C070 D_005175C0_C070 __asm__("D_005175C0");
extern struct Hdr_C070 *D_00515D40;
extern void **D_00515D44;
extern void **D_00515D48;
extern unsigned char *D_00515D4C;
extern unsigned char *D_00515D50;
extern int D_00515D58;
extern unsigned char *D_005175F8;
extern unsigned char *D_005175FC;
extern int D_00517600;
extern int D_0044E848_C070[] __asm__("D_0044E848");
extern int D_0044E870_C070[] __asm__("D_0044E870");
extern int D_00515D80_C070[] __asm__("D_00515D80");
extern void *f_5C60_C070(int) __asm__("func_003B5C60");
extern void *f_6210_C070(void *, int, unsigned int) __asm__("func_00416210");
extern int f_72F8_C070(unsigned char *, int) __asm__("func_003C72F8");
extern unsigned char f_BC20_C070(int, int, int) __asm__("func_003CBC20");
extern int f_F7B0_C070(void *) __asm__("func_003CF7B0");
extern int f_A870_C070(void *) __asm__("func_003CA870");
extern void f_A8A0_C070(void *, int *) __asm__("func_003CA8A0");
extern int f_EE88_C070(void *) __asm__("func_003CEE88");
extern void f_EED0_C070(void *, int *) __asm__("func_003CEED0");
extern int f_A990_C070(void *) __asm__("func_003CA990");
extern void f_A9D8_C070(void *, int *) __asm__("func_003CA9D8");
extern int f_EFB0_C070(void *) __asm__("func_003CEFB0");
extern void f_EFF8_C070(void *, int *) __asm__("func_003CEFF8");
extern int f_F498_C070(void *) __asm__("func_003CF498");
extern void f_F4D0_C070(void *, int *) __asm__("func_003CF4D0");
extern int f_F128_C070(void *) __asm__("func_003CF128");
extern void f_F158_C070(void *, int *) __asm__("func_003CF158");
extern int f_F998_C070(void *) __asm__("func_003CF998");
extern void f_F9D8_C070(void *, int *) __asm__("func_003CF9D8");
extern int f_F2C0_C070(void *) __asm__("func_003CF2C0");
extern int f_F6F8_C070(void *) __asm__("func_003CF6F8");
extern int f_90C0_C070(void *, void *, int, int) __asm__("func_003C90C0");

void func_003CC070(int a, unsigned char *data) {
    int s[4];
    unsigned char *p;
    unsigned char *q;
    void *o;
    int n;
    int count;
    int i;
    int v;

    D_00515D40 = &D_005175C0_C070;
    D_00515D48 = f_5C60_C070(0x1C);
    f_6210_C070(D_00515D48, 0, 0x1C);
    n = D_00515D58 - 1;
    D_00515D4C = D_005175F8;
    D_00515D50 = D_005175FC;
    count = f_72F8_C070(D_00515D40->cnt[n], 4);
    D_00515D44 = f_5C60_C070(count * 4);
    p = D_00515D4C;
    for (i = 0; i < count; i++) {
        D_00515D44[i] = f_5C60_C070(D_0044E848_C070[*p]);
        f_6210_C070(D_00515D44[i], 0, D_0044E848_C070[*p]);
        f_6210_C070(s, 0, 0x10);
        switch (*p) {
        case 0:
            f_F7B0_C070(D_00515D44[i]);
            break;
        case 1:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 4, 2) << 8;
            s[1] = a << 8;
            s[2] = f_72F8_C070(p + 6, 2);
            f_A870_C070(o);
            f_A8A0_C070(o, s);
            break;
        case 2:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 2, 2) << 8;
            s[1] = a << 8;
            f_EE88_C070(o);
            f_EED0_C070(o, s);
            break;
        case 3:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 2, 2) << 8;
            s[1] = a << 8;
            f_A990_C070(o);
            f_A9D8_C070(o, s);
            break;
        case 4:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 4, 2) << 8;
            s[1] = f_72F8_C070(p + 6, 2) << 8;
            s[2] = a << 8;
            f_EFB0_C070(o);
            f_EFF8_C070(o, s);
            break;
        case 5:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 2, 2) << 8;
            s[1] = a << 8;
            s[2] = f_72F8_C070(p + 4, 2) << 8;
            s[3] = f_72F8_C070(p + 6, 2);
            f_F498_C070(o);
            f_F4D0_C070(o, s);
            break;
        case 6:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 2, 2);
            f_F128_C070(o);
            f_F158_C070(o, s);
            break;
        case 7:
            o = D_00515D44[i];
            s[0] = f_72F8_C070(p + 2, 2);
            s[1] = a << 8;
            s[2] = f_72F8_C070(p + 4, 2) << 8;
            f_F998_C070(o);
            f_F9D8_C070(o, s);
            break;
        case 8:
            f_F2C0_C070(D_00515D44[i]);
            break;
        case 9:
            f_F6F8_C070(D_00515D44[i]);
            break;
        }
        if (p[1] != 0) {
            if (*p == 9 && D_00515D40->f2 > 10) {
                v = p[1];
                D_00515D48[f_BC20_C070(D_00515D58, D_00515B40.f05, v & 0xF)] = D_00515D44[i];
                D_00515D48[f_BC20_C070(D_00515D58, D_00515B40.f05, v >> 4)] = D_00515D44[i];
            } else {
                D_00515D48[f_BC20_C070(D_00515D58, D_00515B45, p[1])] = D_00515D44[i];
            }
        }
        p += D_0044E870_C070[*p];
    }
    q = D_00515D50;
    for (i = 0; i < f_72F8_C070(D_00515D40->len[n], 4); i++) {
        f_90C0_C070(D_00515D44[f_72F8_C070(q, 4)], D_00515D44[f_72F8_C070(q + 4, 4)], q[8], q[9]);
        q += 12;
    }
    D_00515D80_C070[0x600] = 3000;
    f_6210_C070(D_00515D80_C070, 0, 0x800);
    p = D_00515D4C;
    for (D_00517600 = 0; *p != 0; D_00517600++) {
        p += D_0044E870_C070[*p];
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CC630);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Hdr_C630 {
    int f0;
    int f4;
    int cnt[6];
    int len[6];
};
extern struct Hdr_C630 D_005175C0_C630 __asm__("D_005175C0");
extern int D_005175C8_C630[] __asm__("D_005175C8");
extern int D_0044E870_C630[] __asm__("D_0044E870");
extern int D_0044E898;
extern int D_00515D54;
extern int D_00515D58;
extern unsigned char *D_005175F8;
extern unsigned char *D_005175FC;
extern void func_003CBC58();
extern int func_003C72F8_C630(void *p, int size) __asm__("func_003C72F8");
extern void func_003CC070_C630(int a, unsigned char *data) __asm__("func_003CC070");

void func_003CC630(int a0, unsigned char *data) {
    unsigned char *p = data + 0x38;
    int n;
    int i;
    int j;
    int k;

    func_003CC848();
    D_0044E898 = 1;
    func_003C51E8(&D_005175C0_C630, data, 0x38);
    n = D_00515B40.f05 - 1;
    if (func_003C72F8_C630(&D_005175C0_C630.cnt[n], 4) != 0) {
        D_00515D58 = D_00515B40.f05;
    } else {
        while (func_003C72F8_C630(&D_005175C8_C630[n], 4) == 0) {
            n--;
        }
        D_00515D58 = n + 1;
    }
    D_00515D54 = D_00515D58;
    for (i = 0; i < n; i++) {
        k = func_003C72F8_C630(&D_005175C8_C630[i], 4);
        for (j = 0; j < k; j++) {
            p += D_0044E870_C630[*p];
        }
        p += func_003C72F8_C630(&D_005175C8_C630[i + 6], 4) * 12;
    }
    D_005175F8 = p;
    k = func_003C72F8_C630(&D_005175C8_C630[n], 4);
    for (j = 0; j < k; j++) {
        p += D_0044E870_C630[*p];
    }
    D_005175FC = p;
    func_003CC070_C630(a0, data);
    D_00515B40.f10 = func_003CBC58;
    D_00515B40.f0F[0] = 1;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CC848);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003CBEC8();

void func_003CC848(void) {
    D_00515B40.f10 = 0;
    func_003CBEC8();
    D_00515B40.f0F[0] = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC878);
#ifdef SKIP_ASM
extern int D_00515D80_CC78[] __asm__("D_00515D80");
void func_003CC878(int n) {
    int *dst = D_00515B54;
    if (dst != 0) {
        // PORT: PS2-only VU0 hand-written loop (scale by 127, convert, clear source); one inline asm block.
        __asm__ volatile(
            ".set push\n\t"
            ".set noreorder\n\t"
            ".set noat\n\t"
            "move $4, %0\n\t"
            "move $5, %1\n\t"
            "move $6, %2\n\t"
            "addiu $8, $0, 0x7F\n\t"
            "sll $4, $4, 2\n\t"
            "qmtc2.ni $8, $vf1\n\t"
            "add $4, $4, $5\n\t"
            "vitof0.xyzw $vf1, $vf1\n"
            "1:\n\t"
            "lqc2 $vf2, 0x0($5)\n\t"
            "lqc2 $vf3, 0x10($5)\n\t"
            "lqc2 $vf4, 0x20($5)\n\t"
            "lqc2 $vf5, 0x30($5)\n\t"
            "vmulx.xyzw $vf2, $vf2, $vf1x\n\t"
            "sq $0, 0x0($5)\n\t"
            "vmulx.xyzw $vf3, $vf3, $vf1x\n\t"
            "sq $0, 0x10($5)\n\t"
            "vmulx.xyzw $vf4, $vf4, $vf1x\n\t"
            "sq $0, 0x20($5)\n\t"
            "vmulx.xyzw $vf5, $vf5, $vf1x\n\t"
            "sq $0, 0x30($5)\n\t"
            "addi $5, $5, 0x40\n\t"
            "addi $6, $6, 0x40\n\t"
            "vftoi0.xyzw $vf2, $vf2\n\t"
            "vftoi0.xyzw $vf3, $vf3\n\t"
            "vftoi0.xyzw $vf4, $vf4\n\t"
            "vftoi0.xyzw $vf5, $vf5\n\t"
            "sqc2 $vf2, -0x40($6)\n\t"
            "sqc2 $vf3, -0x30($6)\n\t"
            "sqc2 $vf4, -0x20($6)\n\t"
            "bne $4, $5, 1b\n\t"
            "sqc2 $vf5, -0x10($6)\n\t"
            ".set pop\n"
            : : "r"(n), "r"(D_00515D80_CC78), "r"(dst)
            : "$4", "$5", "$6", "$8", "memory");
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC918);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00517604;

void func_003CC918(int arg0) {
    D_00517604 = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC928);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_00517608;

void func_003CC928(int arg0) {
    D_00517608 = arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CC938);
#ifdef SKIP_ASM
typedef struct { int pad0; float x; float y; unsigned char *src; float *dst; } S_C938;
typedef union { short s; unsigned char c[2]; } U_C938;

void func_003CC938(S_C938 *s) {
    unsigned char b[2];
    unsigned int i;

    if (*s->src == 0xEE) {
        s->src++;
        b[0] = s->src[1];
        b[1] = s->src[0];
        s->src += 2;
        s->x = (float)*(short*)b;
        b[0] = s->src[1];
        b[1] = s->src[0];
        s->src += 2;
        s->y = (float)*(short*)b;
        for (i = 0; i < 0x1C; i++) {
            b[0] = s->src[1];
            b[1] = s->src[0];
            *s->dst = (float)*(short*)b;
            s->dst++;
            s->src += 2;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCA08);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written entry stub that falls through into func_003CCA38; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_003CCA08\n.type func_003CCA08, @function\nfunc_003CCA08:\n"
    "lui $2, %hi(D_0044E8A0)\n"
    "daddu $3, $4, $0\n"
    "addiu $2, $2, %lo(D_0044E8A0)\n"
    "daddu $4, $3, $0\n"
    "daddu $5, $2, $0\n"
    "addi $29, $29, -0x10\n"
    "sw $31, 0x0($29)\n"
    "lw $6, 0x0($4)\n"
    "lwc1 $f10, 0x4($4)\n"
    "lwc1 $f11, 0x8($4)\n"
    "lw $7, 0xC($4)\n"
    "lw $8, 0x10($4)\n"
    ".size func_003CCA08, . - func_003CCA08\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCA38);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written FPU routine (mula.s/madda.s accumulator ops, unsaved $f20-$f25); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
void func_003CCA38(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "blez $6, 2f\n"
        "nop\n"
        "lbu $9, 0x0($7)\n"
        "addi $6, $6, -0x1C\n"
        "addiu $13, $0, 0xEE\n"
        "lbu $14, 0x0($7)\n"
        "bne $13, $14, 1f\n"
        "nop\n"
        "addi $29, $29, -0x30\n"
        "sw $4, 0x20($29)\n"
        "sw $5, 0x1C($29)\n"
        "sw $6, 0x18($29)\n"
        "sw $7, 0x14($29)\n"
        "sw $8, 0x10($29)\n"
        "sw $9, 0xC($29)\n"
        "sw $10, 0x8($29)\n"
        "sw $11, 0x4($29)\n"
        "sw $12, 0x0($29)\n"
        "jal func_003CC938\n"
        "nop\n"
        "lw $12, 0x0($29)\n"
        "lw $11, 0x4($29)\n"
        "lw $10, 0x8($29)\n"
        "lw $9, 0xC($29)\n"
        "lw $8, 0x10($29)\n"
        "lw $7, 0x14($29)\n"
        "lw $6, 0x18($29)\n"
        "lw $5, 0x1C($29)\n"
        "lw $4, 0x20($29)\n"
        "addi $29, $29, 0x30\n"
        "lwc1 $f10, 0x4($4)\n"
        "lwc1 $f11, 0x8($4)\n"
        "lw $7, 0xC($4)\n"
        "lw $8, 0x10($4)\n"
        "j func_003CCA38\n"
        "nop\n"
        "1:\n"
        "srl $10, $9, 4\n"
        "andi $9, $9, 0xF\n"
        "sll $10, $10, 2\n"
        "add $10, $10, $5\n"
        "lwc1 $f0, 0x0($10)\n"
        "lwc1 $f1, 0x10($10)\n"
        "addi $10, $0, 0xC\n"
        "sub $10, $10, $9\n"
        "addi $9, $9, 0x10\n"
        "lb $11, 0x1($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "mtc1 $0, $f31\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x2($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x0($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x4($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x3($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x8($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0xC($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x4($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x10($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x14($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x5($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x18($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0x1C($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x6($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x20($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x24($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x7($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x28($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0x2C($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x8($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x30($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x34($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0x9($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x38($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0x3C($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0xA($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x40($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x44($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0xB($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x48($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0x4C($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0xC($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x50($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x54($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0xD($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x58($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f2\n"
        "mtc1 $11, $f3\n"
        "cvt.s.w $f2, $f2\n"
        "cvt.s.w $f3, $f3\n"
        "swc1 $f10, 0x5C($8)\n"
        "adda.s $f2, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "lb $11, 0xE($7)\n"
        "sra $12, $11, 4\n"
        "sll $11, $11, 28\n"
        "sllv $12, $12, $10\n"
        "srav $11, $11, $9\n"
        "swc1 $f11, 0x60($8)\n"
        "adda.s $f3, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "mtc1 $12, $f4\n"
        "mtc1 $11, $f5\n"
        "cvt.s.w $f4, $f4\n"
        "cvt.s.w $f5, $f5\n"
        "swc1 $f10, 0x64($8)\n"
        "adda.s $f4, $f31\n"
        "madda.s $f10, $f0\n"
        "madd.s $f11, $f11, $f1\n"
        "swc1 $f11, 0x68($8)\n"
        "adda.s $f5, $f31\n"
        "madda.s $f11, $f0\n"
        "madd.s $f10, $f10, $f1\n"
        "swc1 $f10, 0x6C($8)\n"
        "addi $7, $7, 0xF\n"
        "addi $8, $8, 0x70\n"
        "swc1 $f10, 0x4($4)\n"
        "swc1 $f11, 0x8($4)\n"
        "sw $7, 0xC($4)\n"
        "sw $8, 0x10($4)\n"
        "j func_003CCA38\n"
        "nop\n"
        "2:\n"
        "sw $6, 0x0($4)\n"
        "swc1 $f10, 0x4($4)\n"
        "swc1 $f11, 0x8($4)\n"
        "sw $7, 0xC($4)\n"
        "sw $8, 0x10($4)\n"
        "lq $31, 0x0($29)\n"
        "addi $29, $29, 0x10\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCEF0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517604_CEF0[])(void) __asm__("D_00517604");
int func_003CCEF0(void) {
    return D_00517604_CEF0[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF18);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517608_CF18[])(void) __asm__("D_00517608");
int func_003CCF18_CF18(int) __asm__("func_003CCF18");
int func_003CCF18_CF18(int a) {
    return D_00517608_CF18[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF40);
#ifdef SKIP_ASM
void *func_003CCF40(void *arg0) {
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x98))) = 0;
    (*(int *)((char*)(arg0) + (0x9C))) = 0;
    return arg0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF60);
#ifdef SKIP_ASM
int func_003CCF60(void *arg0, int arg1, int arg2, int arg3) {
    if (arg1 == 0) {
        return -1;
    }
    if ((*(int *)((char*)(arg0) + (8))) != 0) {
        return -1;
    }
    (*(int *)((char*)(arg0) + (8))) = arg3;
    (*(int *)((char*)(arg0) + (0xC))) = arg2;
    (*(int *)((char*)(arg0) + (0xA0))) = arg1;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CCF90);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct S_CF90 { int f0; int pending; int remaining; int fC; float *rd; char pad[0x10]; float buf[28]; int n; int pad2[3]; float *out; };
extern void func_003CCA08_CF90(int *) __asm__("func_003CCA08");

int func_003CCF90(struct S_CF90 *s, float **pout, int n) {
    int done = 0;
    int m;
    int k;
    int i;
    int rem;
    float *dst;

    s->out = *pout;
    if (s->remaining == 0) {
        return 0;
    }
    m = s->remaining;
    if (n < m) {
        m = n;
    }
    if (s->pending != 0) {
        if (m < s->pending) {
            k = m;
        } else {
            k = s->pending;
        }
        for (i = 0; i < k; i++) {
            *s->out = *s->rd;
            s->out++;
            s->rd++;
        }
        m -= k;
        s->remaining -= k;
        s->pending -= k;
        done = k;
    }
    i = m / 28 * 28;
    rem = m - i;
    s->n = i;
    if (i > 0) {
        done += i;
        func_003CCA08_CF90(&s->n);
        s->remaining -= i;
    }
    if (rem > 0) {
        dst = s->out;
        s->n = rem;
        s->out = s->buf;
        func_003CCA08_CF90(&s->n);
        s->remaining -= rem;
        s->rd = s->out + s->n;
        s->pending = -s->n;
        s->out -= 28;
        for (i = 0; i < rem; i++) {
            dst[i] = s->out[i];
        }
        done += rem;
    }
    if (s->remaining <= 0) {
        s->pending = 0;
    }
    return done;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { float x; float y; } V2_D138;
V2_D138 func_003CD138_D138(char *p) __asm__("func_003CD138");

V2_D138 func_003CD138_D138(char *p) {
    V2_D138 v;
    V2_D138 w;
    v.x = *(float *)(p + 0x98);
    v.y = *(float *)(p + 0x9C);
    w = v;
    return w;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD190);
#ifdef SKIP_ASM
void func_003CD190(void *arg0, void *arg1) {
    (*(float *)((char*)(arg0) + (0x98))) = (float) (*(float *)((char*)(arg1) + (0)));
    (*(float *)((char*)(arg0) + (0x9C))) = (float) (*(float *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517604_D1A8[])(void) __asm__("D_00517604");
int func_003CD1A8_D1A8(int) __asm__("func_003CD1A8");
int func_003CD1A8_D1A8(int a) {
    return D_00517604_D1A8[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int (*D_00517608_D1D0[])(void) __asm__("D_00517608");
int func_003CD1D0_D1D0(int) __asm__("func_003CD1D0");
int func_003CD1D0_D1D0(int a) {
    return D_00517608_D1D0[0]();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD1F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct BS_D1F8 { unsigned char *ptr; unsigned int bits; int cnt; } BS_D1F8;
extern unsigned int D_0044E8C0_E8C0[] __asm__("D_0044E8C0");

int func_003CD1F8(BS_D1F8 *p, int n) {
    unsigned int v = p->bits;
    int ret = v & D_0044E8C0_E8C0[n];
    p->bits >>= n;
    p->cnt -= n;
    if (p->cnt < 8) {
        p->bits |= *p->ptr++ << p->cnt;
        p->cnt += 8;
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD260);
#ifdef SKIP_ASM
typedef struct { unsigned char *p; unsigned int bits; int n; } B_D260;

void func_003CD260(B_D260 *b, int k) {
    unsigned int t = b->bits >> k;
    int n = b->n - k;
    b->bits = t;
    b->n = n;
    if (n < 8) {
        unsigned char *q = b->p;
        unsigned int c = *q;
        b->n = n + 8;
        b->p = q + 1;
        b->bits = t | (c << n);
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CD2B0);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD518);
#ifdef SKIP_ASM
void func_003CD518(void *arg0) {
    int var_2;
    void *var_4;

    var_4 = arg0;
    var_2 = 0x6A;
    do {
        var_2 -= 2;
        (*(float *)((char*)(var_4) + (0))) = (float) ((((*(float *)((char*)(var_4) + (-4))) + (*(float *)((char*)(var_4) + (4)))) * 0.59738594f) + (((*(float *)((char*)(var_4) + (-0xC))) + (*(float *)((char*)(var_4) + (0xC)))) * -0.11459156f) + (((*(float *)((char*)(var_4) + (-0x14))) + (*(float *)((char*)(var_4) + (0x14)))) * 0.01803268f));
        var_4 += 8;
    } while (var_2 >= 0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD590);
#ifdef SKIP_ASM
void func_003CD590(char *a_, void *out_) {
    float *a = (float *)a_;
    float *out = (float *)out_;
    float tmp[12];
    float y[12];
    int i, j;
    float s;
    for (j = 10; j >= 0; j--)
        tmp[j + 1] = a[j];
    tmp[0] = 1.0f;
    for (i = 0; i < 12; i++) {
        s = -a[11] * tmp[11];
        for (j = 10; j >= 0; j--) {
            s -= a[j] * tmp[j];
            tmp[j + 1] = a[j] * s + tmp[j];
        }
        tmp[0] = s;
        y[i] = s;
        { int k; for (k = 0; k < i; k++) s -= out[k] * y[i - k - 1]; }
        out[i] = s;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CD690);
#ifdef SKIP_ASM
extern void func_003CD590(char *, void *);
extern void func_003CE410(int, void *, char *, char *);

void func_003CD690(char *arg0, int arg1, int arg2) {
    char buf[0x30];

    func_003CD590(arg0 + 0x114, buf);
    func_003CE410(arg2, buf, arg0 + 0x144, arg0 + (arg1 * 4 + 0x684));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CD6F0);
#ifdef SKIP_ASM
struct S_D6F0 {
    unsigned char *src; int w4; int w8; int wC; int w10; float tab[64];
    int z1[12]; int z2[12]; int z3[0x144];
};

void func_003CD6F0(char *arg0, unsigned char *arg1, char *arg2, int arg3) {
    struct S_D6F0 *s = (struct S_D6F0 *)arg2;
    int n;
    float m;
    int i;

    s->w8 = 8;
    s->src = arg1 + 1;
    s->w4 = *arg1;
    if (arg3 != 0) {
        s->wC = func_003CD1F8((BS_D1F8 *)s, 1);
        s->w10 = 0x20 - func_003CD1F8((BS_D1F8 *)s, 4);
        n = func_003CD1F8((BS_D1F8 *)s, 4);
        s->tab[0] = (float)(unsigned)(n + 1) * 8.0f;
        i = func_003CD1F8((BS_D1F8 *)s, 6);
        m = (float)(unsigned)i * 0.001f + 1.04f;
        for (i = 1; i < 64; i++) {
            s->tab[i] = s->tab[i - 1] * m;
        }
        for (i = 0; i < 12; i++) {
            s->z1[i] = 0;
            s->z2[i] = 0;
        }
        for (i = 0x143; i >= 0; i--) {
            s->z3[i] = 0;
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CD878);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CDDB8);
#ifdef SKIP_ASM
void *func_003CDDB8(void *arg0) {
    (*(int *)((char*)(arg0) + (0xD44))) = 0;
    (*(int *)((char*)(arg0) + (0xD64))) = 1;
    (*(int *)((char*)(arg0) + (0xD54))) = 0;
    (*(int *)((char*)(arg0) + (0xD58))) = 0;
    (*(short *)((char*)(arg0) + (0xD50))) = 0;
    (*(short *)((char*)(arg0) + (0xD52))) = 0;
    (*(int *)((char*)(arg0) + (0xD5C))) = 0;
    (*(int *)((char*)(arg0) + (0xD60))) = 0;
    return arg0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CDDE8);
#ifdef SKIP_ASM
extern void func_003CD6F0(char *, unsigned char *, char *, int);

int func_003CDDE8(char *arg0, unsigned char *arg1, int arg2, int arg3) {
    int temp_8;

    if (arg1 == 0) return -1;
    if (*(int *)(arg0 + 0xD54) != 0) return -1;
    temp_8 = *(int *)(arg0 + 0xD64);
    *(int *)(arg0 + 0xD54) = arg3;
    *(int *)(arg0 + 0xD58) = arg2;
    *(int *)(arg0 + 0xD44) = 0;
    *(unsigned char **)(arg0 + 0xD48) = arg1;
    if (temp_8 == 1) {
        if (*arg1 == 0xEE) {
            *(int *)(arg0 + 0xD60) = temp_8;
        } else {
            *(int *)(arg0 + 0xD60) = 0;
        }
        func_003CD6F0(arg0, arg1 + 1, arg0, *(int *)(arg0 + 0xD5C));
    } else {
        func_003CD6F0(arg0, arg1, arg0, *(int *)(arg0 + 0xD5C));
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CDE68);
#ifdef SKIP_ASM
struct S_DE68 {
    unsigned char *src; int w4; int w8; char pad[0x684 - 0xC]; float buf[0x1B0];
    int cnt; unsigned char *p48; char *out; short n; short idx; int rem; int w58; int w5C; int flag; int mode;
};
extern int func_0041605C_DE68(void *, void *, int) __asm__("func_0041605C");
extern void func_003CD878_DE68(void *) __asm__("func_003CD878");
int func_003CDE68(struct S_DE68 *s, char **arg1, int max) {
    int chunk = s->cnt;
    int n, rem;
    if (s->rem == 0) {
        return 0;
    }
    n = s->rem;
    if (max < n) n = max;
    s->out = *arg1;
    rem = n;
    while (rem > 0) {
        int bytes;
        if (rem < chunk) chunk = rem;
        bytes = chunk * 4;
        rem -= chunk;
        func_0041605C_DE68(s->out, (char *)((0x1B0 - s->cnt) * 4 + (int)s) + 0x684, bytes);
        s->out += bytes;
        s->cnt -= chunk;
        if (rem > 0) {
            func_003CD878_DE68(s);
            s->cnt = 0x1B0;
            chunk = 0x1B0;
            if (s->mode == 1) {
                unsigned char *src = s->src;
                unsigned char *p;
                p = s->p48 = src - 1;
                if (s->flag != 0) {
                    unsigned char *pi = (unsigned char *)&s->idx;
                    unsigned char *pn = (unsigned char *)&s->n;
                    float *fp;
                    short j;
                    char b[2];
                    pi[0] = p[1];
                    pi[1] = p[0];
                    pn[0] = src[2];
                    pn[1] = src[1];
                    p += 4;
                    s->p48 = s->p48 + s->n * 2 + 4;
                    fp = &s->buf[s->idx];
                    s->src = s->p48 + 1;
                    for (j = 0; j < s->n; j++) {
                        b[0] = p[1];
                        b[1] = p[0];
                        p += 2;
                        *fp++ = (float)*(short *)b;
                    }
                    s->flag = 0;
                }
                if (*s->p48 == 0xEE) s->flag = 1;
                s->w8 = 8;
                s->w4 = *s->src;
                s->src++;
            }
        }
    }
    s->rem -= n;
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE078);
#ifdef SKIP_ASM
struct V3_E078 { int a; int b; int c; };

struct V3_E078 func_003CE078(char *self) {
    struct V3_E078 t;
    t.a = *(int *)(self + 4);
    t.c = *(int *)(self + 0xD5C);
    t.b = *(int *)(self + 0xD44);
    return t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0B8);
#ifdef SKIP_ASM
void func_003CE0B8(void *arg0, void *arg1) {
    (*(int *)((char*)(arg0) + (4))) = (int) (*(int *)((char*)(arg1) + (0)));
    (*(int *)((char*)(arg0) + (0xD5C))) = (int) (*(int *)((char*)(arg1) + (8)));
    (*(int *)((char*)(arg0) + (0xD44))) = (int) (*(int *)((char*)(arg1) + (4)));
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0D8);
#ifdef SKIP_ASM
void func_003CE0D8(void *arg0, int arg1) {
    (*(int *)((char*)(arg0) + (0xD64))) = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE0E0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_E0E0[] __asm__("D_0050A8E8");
typedef struct { char pad[0x28]; short f; char pad2[0x62]; } R_E0E0;
typedef struct { R_E0E0 arr[100]; } W_E0E0;

int func_003CE0E0(int arg0) {
    char *p = D_0050A8E8_E0E0;
    int temp_2;
    int temp_4;

    temp_4 = arg0 + *(unsigned char *)(p + 0x30) + *(unsigned char *)(p + 0x2F);
    temp_2 = (*(W_E0E0 **)(p + 0x1F0))->arr[temp_4].f;
    return (temp_2 == -1) ? temp_4 : temp_2;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE118);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern char D_0050A8E8_E118[] __asm__("D_0050A8E8");

struct E_E118 { char pad[0x28]; short f28; char pad2[0x8C - 0x2A]; };
struct R_E118 { struct E_E118 e[1]; };

int func_003CE118_impl(int arg0) __asm__("func_003CE118");
int func_003CE118_impl(int arg0) {
    short *var_3;
    int temp_2;
    int temp_4;
    int var_5;
    char *b = D_0050A8E8_E118;

    temp_4 = arg0 + *(unsigned char *)(b + 0x30) + *(unsigned char *)(b + 0x2F);
    temp_2 = ((struct R_E118 *)*(char **)(b + 0x1F0))->e[temp_4].f28;
    if (temp_2 == -1) {
        return 0;
    }
    var_3 = (short *)(temp_2 * 0x8C + *(int *)(b + 0x1F0) + 6);
    for (var_5 = 1; var_5 < 6; var_5++, var_3++) {
        if (*var_3 == temp_4) {
            return var_5;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE198);
#ifdef SKIP_ASM
int func_003CE198(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1A0);
#ifdef SKIP_ASM
int func_003CE1A0(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1A8);
#ifdef SKIP_ASM
int func_003CE1A8(void) {
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CE1B0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { char pad0[3]; unsigned char b3; } A6_E1B0;
typedef struct { char pad0[7]; unsigned char b7; char pad8[0x18 - 8]; int arr[8]; } A7_E1B0;
extern void func_003C8158_E1B0(int, int, int, int, unsigned int, int, int, int, int, int, int, int, int, int) __asm__("func_003C8158");
extern int func_003C25E0(int);
extern void func_003C38E0_E1B0(int) __asm__("func_003C38E0");
extern int func_003C27E0(int, int);
extern int func_003C3010(int, int);
extern void func_003C30C8(int, int);
extern void func_003C3178_E1B0(int, int) __asm__("func_003C3178");
extern void func_003C3250(int, int);

int func_003CE1B0(int arg0, int idx, int arg2, int arg3, int arg4, int arg5, A6_E1B0 *arg6, A7_E1B0 *arg7) {
    struct sA8E8Chan *e;
    int i;

    e = &D_0050A8E8.f1F0[idx];
    if (!(e->f24 & 8)) {
    if (e->f24 & 4) {
    for (i = 0; i < e->f23; i++) {
        func_003C8158_E1B0(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F), arg6->b3, 0, 0, 0xFFFFFFFF,
                           arg7->arr[i], e->f23, e->f14, -1, -1, 0, 0, arg7->b7, i);
    }
    func_003C25E0(e->f04[0]);
    func_003C38E0_E1B0(e->f04[0]);
    func_003C27E0(e->f04[0], 0);
    func_003C3010(e->f04[0], arg2);
    func_003C30C8(e->f04[0], arg3);
    func_003C3178_E1B0(e->f04[0], arg4);
    func_003C3250(e->f04[0], arg5);
    for (i = 0; i < e->f23; i++) {
        func_003C83A0(e->f04[i] - (D_0050A8E8.setup.cfg.f10 + D_0050A8E8.setup.cfg.f0F));
    }
    }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE378);
#ifdef SKIP_ASM
int func_003CE378(int key) {
    int i;
    for (i = 0; i < D_0050A8E8.setup.cfg.f26; i++) {
        struct s7B8Queue *q = D_005157B8.f304[i];
        if (q != 0 && func_003BA6E8(q->f00) == key) return i;
    }
    return -1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE410);
#ifdef SKIP_ASM
// PORT: PS2-only hand-written FPU routine (mula.s/madda.s accumulator ops no compiler emits); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
void func_003CE410_asmbody(void) __asm__("func_003CE410");
void func_003CE410_asmbody(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "lwc1 $f0, 0x0($5)\n"
        "lwc1 $f1, 0x4($5)\n"
        "lwc1 $f2, 0x8($5)\n"
        "lwc1 $f3, 0xC($5)\n"
        "lwc1 $f4, 0x10($5)\n"
        "lwc1 $f5, 0x14($5)\n"
        "lwc1 $f6, 0x18($5)\n"
        "lwc1 $f7, 0x1C($5)\n"
        "lwc1 $f8, 0x20($5)\n"
        "lwc1 $f9, 0x24($5)\n"
        "lwc1 $f10, 0x28($5)\n"
        "lwc1 $f11, 0x2C($5)\n"
        "mtc1 $0, $f31\n"
        "lwc1 $f12, 0x0($6)\n"
        "lwc1 $f13, 0x4($6)\n"
        "lwc1 $f14, 0x8($6)\n"
        "lwc1 $f15, 0xC($6)\n"
        "lwc1 $f16, 0x10($6)\n"
        "lwc1 $f17, 0x14($6)\n"
        "lwc1 $f18, 0x18($6)\n"
        "lwc1 $f19, 0x1C($6)\n"
        "lwc1 $f20, 0x20($6)\n"
        "lwc1 $f21, 0x24($6)\n"
        "lwc1 $f22, 0x28($6)\n"
        "lwc1 $f23, 0x2C($6)\n"
        "1:\n"
        "lwc1 $f30, 0x0($7)\n"
        "adda.s $f30, $f31\n"
        "madda.s $f0, $f12\n"
        "madda.s $f1, $f13\n"
        "madda.s $f2, $f14\n"
        "madda.s $f3, $f15\n"
        "addi $4, $4, -0x1\n"
        "madda.s $f4, $f16\n"
        "madda.s $f5, $f17\n"
        "madda.s $f6, $f18\n"
        "madda.s $f7, $f19\n"
        "lwc1 $f30, 0x4($7)\n"
        "madda.s $f8, $f20\n"
        "madda.s $f9, $f21\n"
        "madda.s $f10, $f22\n"
        "madda.s $f11, $f23\n"
        "madd.s $f23, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f12\n"
        "madda.s $f2, $f13\n"
        "madda.s $f3, $f14\n"
        "madda.s $f4, $f15\n"
        "swc1 $f23, 0x0($7)\n"
        "madda.s $f5, $f16\n"
        "madda.s $f6, $f17\n"
        "madda.s $f7, $f18\n"
        "madda.s $f8, $f19\n"
        "lwc1 $f30, 0x8($7)\n"
        "madda.s $f9, $f20\n"
        "madda.s $f10, $f21\n"
        "madda.s $f11, $f22\n"
        "madda.s $f0, $f23\n"
        "madd.s $f22, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f23\n"
        "madda.s $f2, $f12\n"
        "madda.s $f3, $f13\n"
        "madda.s $f4, $f14\n"
        "swc1 $f22, 0x4($7)\n"
        "madda.s $f5, $f15\n"
        "madda.s $f6, $f16\n"
        "madda.s $f7, $f17\n"
        "madda.s $f8, $f18\n"
        "lwc1 $f30, 0xC($7)\n"
        "madda.s $f9, $f19\n"
        "madda.s $f10, $f20\n"
        "madda.s $f11, $f21\n"
        "madda.s $f0, $f22\n"
        "madd.s $f21, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f22\n"
        "madda.s $f2, $f23\n"
        "madda.s $f3, $f12\n"
        "madda.s $f4, $f13\n"
        "swc1 $f21, 0x8($7)\n"
        "madda.s $f5, $f14\n"
        "madda.s $f6, $f15\n"
        "madda.s $f7, $f16\n"
        "madda.s $f8, $f17\n"
        "lwc1 $f30, 0x10($7)\n"
        "madda.s $f9, $f18\n"
        "madda.s $f10, $f19\n"
        "madda.s $f11, $f20\n"
        "madda.s $f0, $f21\n"
        "madd.s $f20, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f21\n"
        "madda.s $f2, $f22\n"
        "madda.s $f3, $f23\n"
        "swc1 $f20, 0xC($7)\n"
        "madda.s $f4, $f12\n"
        "madda.s $f5, $f13\n"
        "madda.s $f6, $f14\n"
        "madda.s $f7, $f15\n"
        "madda.s $f8, $f16\n"
        "lwc1 $f30, 0x14($7)\n"
        "madda.s $f9, $f17\n"
        "madda.s $f10, $f18\n"
        "madda.s $f11, $f19\n"
        "madda.s $f0, $f20\n"
        "madd.s $f19, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f20\n"
        "madda.s $f2, $f21\n"
        "madda.s $f3, $f22\n"
        "madda.s $f4, $f23\n"
        "swc1 $f19, 0x10($7)\n"
        "madda.s $f5, $f12\n"
        "madda.s $f6, $f13\n"
        "madda.s $f7, $f14\n"
        "madda.s $f8, $f15\n"
        "lwc1 $f30, 0x18($7)\n"
        "madda.s $f9, $f16\n"
        "madda.s $f10, $f17\n"
        "madda.s $f11, $f18\n"
        "madda.s $f0, $f19\n"
        "madd.s $f18, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f19\n"
        "madda.s $f2, $f20\n"
        "madda.s $f3, $f21\n"
        "madda.s $f4, $f22\n"
        "swc1 $f18, 0x14($7)\n"
        "madda.s $f5, $f23\n"
        "madda.s $f6, $f12\n"
        "madda.s $f7, $f13\n"
        "madda.s $f8, $f14\n"
        "lwc1 $f30, 0x1C($7)\n"
        "madda.s $f9, $f15\n"
        "madda.s $f10, $f16\n"
        "madda.s $f11, $f17\n"
        "madda.s $f0, $f18\n"
        "madd.s $f17, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f18\n"
        "madda.s $f2, $f19\n"
        "madda.s $f3, $f20\n"
        "madda.s $f4, $f21\n"
        "swc1 $f17, 0x18($7)\n"
        "madda.s $f5, $f22\n"
        "madda.s $f6, $f23\n"
        "madda.s $f7, $f12\n"
        "madda.s $f8, $f13\n"
        "lwc1 $f30, 0x20($7)\n"
        "madda.s $f9, $f14\n"
        "madda.s $f10, $f15\n"
        "madda.s $f11, $f16\n"
        "madda.s $f0, $f17\n"
        "madd.s $f16, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f17\n"
        "madda.s $f2, $f18\n"
        "madda.s $f3, $f19\n"
        "madda.s $f4, $f20\n"
        "swc1 $f16, 0x1C($7)\n"
        "madda.s $f5, $f21\n"
        "madda.s $f6, $f22\n"
        "madda.s $f7, $f23\n"
        "madda.s $f8, $f12\n"
        "lwc1 $f30, 0x24($7)\n"
        "madda.s $f9, $f13\n"
        "madda.s $f10, $f14\n"
        "madda.s $f11, $f15\n"
        "madda.s $f0, $f16\n"
        "madd.s $f15, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f16\n"
        "madda.s $f2, $f17\n"
        "madda.s $f3, $f18\n"
        "madda.s $f4, $f19\n"
        "swc1 $f15, 0x20($7)\n"
        "madda.s $f5, $f20\n"
        "madda.s $f6, $f21\n"
        "madda.s $f7, $f22\n"
        "madda.s $f8, $f23\n"
        "lwc1 $f30, 0x28($7)\n"
        "madda.s $f9, $f12\n"
        "madda.s $f10, $f13\n"
        "madda.s $f11, $f14\n"
        "madda.s $f0, $f15\n"
        "madd.s $f14, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f15\n"
        "madda.s $f2, $f16\n"
        "madda.s $f3, $f17\n"
        "madda.s $f4, $f18\n"
        "swc1 $f14, 0x24($7)\n"
        "madda.s $f5, $f19\n"
        "madda.s $f6, $f20\n"
        "madda.s $f7, $f21\n"
        "madda.s $f8, $f22\n"
        "lwc1 $f30, 0x2C($7)\n"
        "madda.s $f9, $f23\n"
        "madda.s $f10, $f12\n"
        "madda.s $f11, $f13\n"
        "madda.s $f0, $f14\n"
        "madd.s $f13, $f31, $f31\n"
        "adda.s $f30, $f31\n"
        "madda.s $f1, $f14\n"
        "madda.s $f2, $f15\n"
        "madda.s $f3, $f16\n"
        "madda.s $f4, $f17\n"
        "swc1 $f13, 0x28($7)\n"
        "madda.s $f5, $f18\n"
        "madda.s $f6, $f19\n"
        "madda.s $f7, $f20\n"
        "madda.s $f8, $f21\n"
        "addi $7, $7, 0x30\n"
        "madda.s $f9, $f22\n"
        "madda.s $f10, $f23\n"
        "madda.s $f11, $f12\n"
        "madda.s $f0, $f13\n"
        "madd.s $f12, $f31, $f31\n"
        "swc1 $f12, -0x4($7)\n"
        "bgtzl $4, 1b\n"
        "nop\n"
        "swc1 $f12, 0x0($6)\n"
        "swc1 $f13, 0x4($6)\n"
        "swc1 $f14, 0x8($6)\n"
        "swc1 $f15, 0xC($6)\n"
        "swc1 $f16, 0x10($6)\n"
        "swc1 $f17, 0x14($6)\n"
        "swc1 $f18, 0x18($6)\n"
        "swc1 $f19, 0x1C($6)\n"
        "swc1 $f20, 0x20($6)\n"
        "swc1 $f21, 0x24($6)\n"
        "swc1 $f22, 0x28($6)\n"
        "swc1 $f23, 0x2C($6)\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CE7C0);
#ifdef SKIP_ASM
typedef struct {
    float m[0x38];
    float c[5];
    float f1;
    float f2;
    char dirty;
} sFir_E7C0;

void func_003CE7C0(sFir_E7C0 *p, int type) {
    /* order stays in $19: the target tests it with slti/beqz and folds order & 1 only via nonzero_bits */
    int order = 4;
    int i;
    float angle, sum;

    p->dirty = 1;
    if ((unsigned)(type - 3) < 2 && p->f1 > 0.8f) {
        p->f1 = 0.8f;
    }
    switch (type) {
    case 2:
        p->c[order] = p->f2;
        for (i = 1; i <= order; i++) {
            angle = (float)i * 3.1415927f;
            p->c[order - i] = func_003BC770(p->f2 * angle) / angle;
        }
        break;
    case 3:
        p->c[order] = p->f1;
        for (i = 1; i <= order; i++) {
            angle = (float)i * 3.1415927f;
            p->c[order - i] = func_003BC770(p->f1 * angle) / angle;
        }
        break;
    case 4:
        p->c[order] = p->f2 - p->f1;
        for (i = 1; i <= order; i++) {
            float s;
            angle = (float)i * 3.1415927f;
            s = func_003BC770((p->f2 - p->f1) * 0.5f * angle);
            p->c[order - i] = (s + s) * func_003BC840((p->f2 + p->f1) * 0.5f * angle) / angle;
        }
        break;
    }
    /* window step pi/4 is set at the switch join before the order < 0 loop guard (a literal is hoisted after it) */
    angle = 0.7853982f;
    sum = 0.0f;
    for (i = 0; i <= order; i++) {
        if (type == 2 || type == 4) {
            float v = p->c[i] * (0.54f - func_003BC840(angle * (float)i) * 0.46f);
            p->c[i] = v;
            sum += v;
        } else if (type == 3) {
            float v = p->c[i] * -(0.54f - func_003BC840(angle * (float)i) * 0.46f);
            p->c[i] = v;
            if ((i & 1) == 0) {
                sum += v;
            } else {
                sum -= v;
            }
        }
    }
    if (type == 3) {
        sum += 1.0f;
        p->c[order] += 1.0f;
    }
    if (order & 1) {
        sum = sum + sum;
    } else {
        sum = sum + sum - p->c[order];
    }
    if (sum < 0.0f) {
        sum = -sum;
    }
    for (i = 0; i <= order; i++) {
        p->c[i] /= sum;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEB90);
#ifdef SKIP_ASM
void func_003CEB90(void *arg0) {
    (*(int *)((char*)(arg0) + (0xC0))) = 0;
    (*(int *)((char*)(arg0) + (0xC4))) = 0;
    (*(int *)((char*)(arg0) + (0xC8))) = 0;
    (*(int *)((char*)(arg0) + (0xCC))) = 0;
    (*(int *)((char*)(arg0) + (0xD0))) = 0;
    (*(int *)((char*)(arg0) + (0xD4))) = 0;
    (*(int *)((char*)(arg0) + (0xD8))) = 0;
    (*(int *)((char*)(arg0) + (0xDC))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x18))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    (*(int *)((char*)(arg0) + (0x2C))) = 0;
    (*(int *)((char*)(arg0) + (0x90))) = 0;
    (*(int *)((char*)(arg0) + (0xA0))) = 0;
    (*(int *)((char*)(arg0) + (0xA4))) = 0;
    (*(int *)((char*)(arg0) + (0xB0))) = 0;
    (*(int *)((char*)(arg0) + (0xB4))) = 0;
    (*(int *)((char*)(arg0) + (0xB8))) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEBE8);
#ifdef SKIP_ASM
// PORT: PS2-only VU0 inline asm (FIR filter over 4-float blocks: 12x4 banded matrix times sliding window).
void func_003CEBE8(char *p, int n, int src, int dst) {
    if (*(signed char *)(p + 0xFC) != 0) {
        float *m = (float *)p;
        float a = m[0xE0 / 4];
        float b = m[0xE4 / 4];
        float c = m[0xE8 / 4];
        float d = m[0xEC / 4];
        float e = m[0xF0 / 4];
        m[0] = a;
        m[5] = a;
        m[10] = a;
        m[15] = a;
        m[4] = b;
        m[9] = b;
        m[14] = b;
        m[19] = b;
        m[8] = c;
        m[13] = c;
        m[18] = c;
        m[23] = c;
        m[12] = d;
        m[17] = d;
        m[22] = d;
        m[27] = d;
        m[16] = e;
        m[21] = e;
        m[26] = e;
        m[31] = e;
        m[20] = d;
        m[25] = d;
        m[30] = d;
        m[35] = d;
        m[24] = c;
        m[29] = c;
        m[34] = c;
        m[39] = c;
        m[28] = b;
        m[33] = b;
        m[38] = b;
        m[43] = b;
        m[32] = a;
        m[37] = a;
        m[42] = a;
        m[47] = a;
        *(signed char *)(p + 0xFC) = 0;
    }
    __asm__ volatile(
        ".set push\n"
        ".set noreorder\n"
        "move         $6, %1\n"
        "move         $4, %0\n"
        "move         $5, %2\n"
        "sll          $6, $6, 2\n"
        "move         $7, %3\n"
        "move         $8, %4\n"
        "add          $6, $6, $7\n"
        "lqc2         $vf1, 0x0($4)\n"
        "lqc2         $vf2, 0x10($4)\n"
        "lqc2         $vf3, 0x20($4)\n"
        "lqc2         $vf4, 0x30($4)\n"
        "lqc2         $vf5, 0x40($4)\n"
        "lqc2         $vf6, 0x50($4)\n"
        "lqc2         $vf7, 0x60($4)\n"
        "lqc2         $vf8, 0x70($4)\n"
        "lqc2         $vf9, 0x80($4)\n"
        "lqc2         $vf10, 0x90($4)\n"
        "lqc2         $vf11, 0xA0($4)\n"
        "lqc2         $vf12, 0xB0($4)\n"
        "lqc2         $vf20, 0x0($5)\n"
        "lqc2         $vf21, 0x10($5)\n"
        "1:\n"
        "lqc2         $vf22, 0x0($7)\n"
        "lqc2         $vf23, 0x10($7)\n"
        "lqc2         $vf24, 0x20($7)\n"
        "lqc2         $vf25, 0x30($7)\n"
        "vmulax.xyzw  ACC, $vf1, $vf20x\n"
        "vmadday.xyzw ACC, $vf2, $vf20y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf20z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf20w\n"
        "vmaddax.xyzw ACC, $vf5, $vf21x\n"
        "vmadday.xyzw ACC, $vf6, $vf21y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf21z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf21w\n"
        "vmaddax.xyzw ACC, $vf9, $vf22x\n"
        "vmadday.xyzw ACC, $vf10, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf22z\n"
        "vmaddw.xyzw  $vf28, $vf12, $vf22w\n"
        "vmulax.xyzw  ACC, $vf1, $vf21x\n"
        "vmadday.xyzw ACC, $vf2, $vf21y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf21z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf21w\n"
        "vmaddax.xyzw ACC, $vf5, $vf22x\n"
        "vmadday.xyzw ACC, $vf6, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf22z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf22w\n"
        "vmaddax.xyzw ACC, $vf9, $vf23x\n"
        "vmadday.xyzw ACC, $vf10, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf23z\n"
        "vmaddw.xyzw  $vf29, $vf12, $vf23w\n"
        "vmulax.xyzw  ACC, $vf1, $vf22x\n"
        "vmadday.xyzw ACC, $vf2, $vf22y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf22z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf22w\n"
        "vmaddax.xyzw ACC, $vf5, $vf23x\n"
        "vmadday.xyzw ACC, $vf6, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf23z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf23w\n"
        "vmaddax.xyzw ACC, $vf9, $vf24x\n"
        "vmadday.xyzw ACC, $vf10, $vf24y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf24z\n"
        "vmaddw.xyzw  $vf30, $vf12, $vf24w\n"
        "vmulax.xyzw  ACC, $vf1, $vf23x\n"
        "vmadday.xyzw ACC, $vf2, $vf23y\n"
        "vmaddaz.xyzw ACC, $vf3, $vf23z\n"
        "vmaddaw.xyzw ACC, $vf4, $vf23w\n"
        "vmaddax.xyzw ACC, $vf5, $vf24x\n"
        "vmadday.xyzw ACC, $vf6, $vf24y\n"
        "vmaddaz.xyzw ACC, $vf7, $vf24z\n"
        "vmaddaw.xyzw ACC, $vf8, $vf24w\n"
        "vmaddax.xyzw ACC, $vf9, $vf25x\n"
        "vmadday.xyzw ACC, $vf10, $vf25y\n"
        "vmaddaz.xyzw ACC, $vf11, $vf25z\n"
        "vmaddw.xyzw  $vf31, $vf12, $vf25w\n"
        "addi         $7, $7, 0x40\n"
        "sqc2         $vf28, 0x0($8)\n"
        "sqc2         $vf29, 0x10($8)\n"
        "sqc2         $vf30, 0x20($8)\n"
        "sqc2         $vf31, 0x30($8)\n"
        "vmove.xyzw   $vf20, $vf24\n"
        "vmove.xyzw   $vf21, $vf25\n"
        "bne          $6, $7, 1b\n"
        "addi         $8, $8, 0x40\n"
        "sqc2         $vf20, 0x0($5)\n"
        "sqc2         $vf21, 0x10($5)\n"
        ".set pop\n"
        :
        : "r"(p), "r"(n), "r"(p + 0xC0), "r"(src), "r"(dst)
        : "$4", "$5", "$6", "$7", "$8", "memory");
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEE08);
#ifdef SKIP_ASM
extern void func_003CEBE8(char *, int, int, int);
int func_003CEE08(char *arg0, int arg1, int arg2, int arg3) {
    int **obj = *(int ***)(arg0 + 8);
    int r;
    if (obj == 0 || (r = ((int (*)(int **, int, int, int, unsigned char))(*obj))(obj, arg1, arg3, arg2, *(unsigned char *)(arg0 + 0x1A)), r > 0)) {
        func_003CEBE8(arg0 + 0x20, arg1, arg2, arg3);
        r = arg1;
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CEE88);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_EE88;
extern void func_003CEB90(void *);
extern void func_003CEE08_x(void) __asm__("func_003CEE08");

int func_003CEE88(S_EE88 *self) {
    self->vt = func_003CEE08_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEED0);
#ifdef SKIP_ASM
extern void func_003CE7C0_EED0(char *, int) __asm__("func_003CE7C0");

void func_003CEED0(char *arg0, int *arg1) {
    float a = (float)(arg1[0] >> 8);
    *(float *)(arg0 + 0x118) = (a + a) / (float)(arg1[1] >> 8);
    func_003CE7C0_EED0(arg0 + 0x20, 2);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEF20);
#ifdef SKIP_ASM
// Identical copy of func_003CA900.
extern void func_003CEBE8_EF20(void *, int, int, int) __asm__("func_003CEBE8");

int func_003CEF20(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CEBE8_EF20(p + 0x20, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CEFB0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; int f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int pad1c; char sub[1]; } S_EFB0;
extern void func_003CEB90(void *);
extern void func_003CEF20_x(void) __asm__("func_003CEF20");

int func_003CEFB0(S_EFB0 *self) {
    self->vt = func_003CEF20_x;
    self->f8 = 0;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f4 = 0;
    func_003CEB90(&self->sub);
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CEFF8);
#ifdef SKIP_ASM
extern void func_003CE7C0_EFF8(char *, int) __asm__("func_003CE7C0");

void func_003CEFF8(char *arg0, int *arg1) {
    float x = (float)(arg1[0] >> 7);
    float y = (float)(arg1[1] >> 7);
    float d = (float)(arg1[2] >> 8);
    *(float *)(arg0 + 0x114) = x / d;
    *(float *)(arg0 + 0x118) = y / d;
    func_003CE7C0_EFF8(arg0 + 0x20, 4);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF060);
#ifdef SKIP_ASM
struct S3CF060 { char p0[8]; int *obj; char p1[0xE]; unsigned char f1A; char p2[1]; float f1C; };
int func_003CF060_C(struct S3CF060 *self, int n, float *src, float *dst) __asm__("func_003CF060");
int func_003CF060_C(struct S3CF060 *self, int n, float *src, float *dst) {
    if (self->obj) {
        int r = ((int (*)(int *, int, float *, float *, int))*self->obj)(self->obj, n, dst, src, self->f1A);
        if (r <= 0) return r;
    }
    // PORT: PS2-only VU0 hand-written loop (scale 4x4 blocks by a factor); one inline asm block.
    __asm__ volatile(
        ".set push\n\t"
        ".set noreorder\n\t"
        ".set noat\n\t"
        "mfc1 $2, %3\n\t"
        "move $4, %0\n\t"
        "qmtc2.ni $2, $vf1\n\t"
        "sll $4, $4, 2\n\t"
        "move $6, %1\n\t"
        "move $7, %2\n\t"
        "add $4, $4, $6\n"
        "1:\n\t"
        "lqc2 $vf2, 0x0($6)\n\t"
        "lqc2 $vf3, 0x10($6)\n\t"
        "lqc2 $vf4, 0x20($6)\n\t"
        "lqc2 $vf5, 0x30($6)\n\t"
        "addi $6, $6, 0x40\n\t"
        "vmulx.xyzw $vf2, $vf2, $vf1x\n\t"
        "vmulx.xyzw $vf3, $vf3, $vf1x\n\t"
        "vmulx.xyzw $vf4, $vf4, $vf1x\n\t"
        "vmulx.xyzw $vf5, $vf5, $vf1x\n\t"
        "sqc2 $vf2, 0x0($7)\n\t"
        "sqc2 $vf3, 0x10($7)\n\t"
        "sqc2 $vf4, 0x20($7)\n\t"
        "sqc2 $vf5, 0x30($7)\n\t"
        "bne $4, $6, 1b\n\t"
        "addi $7, $7, 0x40\n\t"
        ".set pop\n"
        : : "r"(n), "r"(src), "r"(dst), "f"(self->f1C)
        : "$2", "$4", "$6", "$7", "memory");
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF128);
#ifdef SKIP_ASM
extern void func_003CF060();

int func_003CF128(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(void (**)())((char*)(arg0) + (0))) = func_003CF060;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (4))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF158);
#ifdef SKIP_ASM
void func_003CF158(void *arg0, int *arg1) {
    (*(float *)((char*)(arg0) + (0x1C))) = (float) ((float) *arg1 * 0.00390625f);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF178);
#ifdef SKIP_ASM
struct S3CF178 { char p0[8]; int *f8; int *fC; char p1[0xC]; void *f1C; int f20; };
extern void ff_F178(void *) __asm__("func_003B5E98");
extern void *fa_F178(int) __asm__("func_003B5C60");
int func_003CF178_C(struct S3CF178 *self, int n, int a2, float *a3) __asm__("func_003CF178");
int func_003CF178_C(struct S3CF178 *self, int n, int a2, float *a3) {
    int r;
    if (self->f20 < n) {
        if (self->f1C) ff_F178(self->f1C);
        self->f20 = n;
        self->f1C = fa_F178(n << 2);
    }
    r = ((int (*)(int *, int, int, float *, int))*self->f8)(self->f8, n, a2, a3, 1);
    if (r <= 0) return r;
    r = ((int (*)(int *, int, int, void *, int))*self->fC)(self->fC, n, a2, self->f1C, 2);
    if (r <= 0) return r;
    {
            // PORT: PS2-only VU0 hand-written loop (add a scratch buffer into the destination, 4x4 floats per step).
            __asm__ volatile(
                ".set push\n\t"
                ".set noreorder\n\t"
                ".set noat\n\t"
                "move $4, %0\n\t"
                "sll $4, $4, 2\n\t"
                "move $5, %1\n\t"
                "move $6, %2\n\t"
                "add $4, $4, $5\n"
                "1:\n\t"
                "lqc2 $vf2, 0x0($5)\n\t"
                "lqc2 $vf3, 0x10($5)\n\t"
                "lqc2 $vf4, 0x20($5)\n\t"
                "lqc2 $vf5, 0x30($5)\n\t"
                "lqc2 $vf6, 0x0($6)\n\t"
                "lqc2 $vf7, 0x10($6)\n\t"
                "lqc2 $vf8, 0x20($6)\n\t"
                "lqc2 $vf9, 0x30($6)\n\t"
                "addi $5, $5, 0x40\n\t"
                "vadd.xyzw $vf6, $vf6, $vf2\n\t"
                "vadd.xyzw $vf7, $vf7, $vf3\n\t"
                "vadd.xyzw $vf8, $vf8, $vf4\n\t"
                "vadd.xyzw $vf9, $vf9, $vf5\n\t"
                "sqc2 $vf6, 0x0($6)\n\t"
                "sqc2 $vf7, 0x10($6)\n\t"
                "sqc2 $vf8, 0x20($6)\n\t"
                "sqc2 $vf9, 0x30($6)\n\t"
                "bne $4, $5, 1b\n\t"
                "addi $6, $6, 0x40\n\t"
                ".set pop\n"
                : : "r"(n), "r"(self->f1C), "r"(a3)
                : "$4", "$5", "$6", "memory");
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF298);
#ifdef SKIP_ASM
extern void func_003B5E98(int);

void func_003CF298(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF2C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF178_F2C0(void) __asm__("func_003CF178");
void func_003CF298_F2C0(void) __asm__("func_003CF298");

int func_003CF2C0(char *arg0) {
    *(void (**)(void))(arg0 + 4) = func_003CF298_F2C0;
    *(void (**)(void))(arg0 + 0) = func_003CF178_F2C0;
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 0x1C) = 0;
    *(int *)(arg0 + 0x20) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF300);
#ifdef SKIP_ASM
struct S_F300 { char p0[0x1C]; int f1C; float f20; float f24; float f28; float f2C; float f30; char p34[4]; float f38; float f3C; };
void func_003CF300(void *sv, int n, int in_, int out_) {
    struct S_F300 *s = (struct S_F300 *)sv;
    float *in = (float *)in_;
    float *out = (float *)out_;
    int h = s->f1C;
    float t, a, b, v;
    if (s->f24 < (2.0f * (float)h) / 3.1415927f && (t = s->f20, t > 0.0f) && t < (float)(h >> 1)) {
        if (n > 0) {
            do {
                a = s->f28;
                n -= 1;
                b = s->f30 * (*in + 1e-20f);
                in += 1;
                *out = (b + (2.0f * a * s->f2C * s->f38)) - (a * a * s->f3C);
                s->f3C = s->f38;
                t = *out;
                out += 1;
                s->f38 = t;
            } while (n != 0);
        }
    } else if (n > 0) {
        do {
            v = *in;
            n -= 1;
            in += 1;
            *out = v;
            out += 1;
        } while (n != 0);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF408);
#ifdef SKIP_ASM
extern void func_003CF300(void *, int, int, int);

int func_003CF408(char *p, int arg1, int arg2, int arg3) {
    int (**obj)(void *, int, int, int, int);
    int n;
    obj = *(int (***)(void *, int, int, int, int))(p + 8);
    if (obj != 0) {
        n = (*obj)(obj, arg1, arg3, arg2, *(unsigned char *)(p + 0x1A));
        if (n <= 0) {
            return n;
        }
    } else {
        n = arg1;
    }
    func_003CF300(p, n, arg2, arg3);
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF498);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF408_F498(void) __asm__("func_003CF408");

int func_003CF498(char *arg0) {
    *(int *)(arg0 + 8) = 0;
    *(void (**)(void))(arg0 + 0) = func_003CF408_F498;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 4) = 0;
    *(int *)(arg0 + 0x34) = 0;
    *(int *)(arg0 + 0x38) = 0;
    *(int *)(arg0 + 0x3C) = 0;
    return 0;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF4D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern float func_003CFA98(float);
void func_003CF4D0(void *arg0, void *arg1) {
    float fa, fb, fc, fd, f21, f0, r;
    int ia = (*(int *)((char*)arg1 + 0)) >> 8;
    int ib = (*(int *)((char*)arg1 + 4)) >> 8;
    int ic = (*(int *)((char*)arg1 + 8)) >> 8;
    fa = (float)ia;
    fd = (float)(*(int *)((char*)arg1 + 0xC));
    fc = (float)ic;
    fb = (float)ib;
    *(int *)((char*)arg0 + 0x1C) = ib;
    *(float *)((char*)arg0 + 0x20) = fa;
    fd = fd * 0.00390625f;
    *(float *)((char*)arg0 + 0x24) = fc;
    f0 = 1.0f - (fc * 3.1415927f) / fb;
    *(float *)((char*)arg0 + 0x28) = f0;
    f21 = f0 * f0;
    r = (2.0f * *(float *)((char*)arg0 + 0x28)) / (f21 + 1.0f) * func_003BC840((fa * 6.2831855f) / fb);
    *(float *)((char*)arg0 + 0x2C) = r;
    *(float *)((char*)arg0 + 0x30) = (1.0f - f21) * fd * func_003CFA98(-r * r);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF5D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003B5C60_F5D0(int) __asm__("func_003B5C60");
extern void func_003C51E8_F5D0(char *, char *, int) __asm__("func_003C51E8");

int func_003CF5D0(char *self, int n, char *a2, char *a3) {
    int bytes, p, r;
    int *obj;
    if (*(short *)(self + 0x24) != 0) {
        *(short *)(self + 0x24) = 0;
        *(short *)(self + 0x26) = 1;
    }
    bytes = n * 4;
    if (*(int *)(self + 0x20) < n) {
        p = *(int *)(self + 0x1C);
        if (p != 0) {
            func_003B5E98(p);
        }
        *(int *)(self + 0x1C) = func_003B5C60_F5D0(bytes);
        *(int *)(self + 0x20) = n;
    }
    if (*(short *)(self + 0x26) != 0) {
        int (**vt)(void *, int, char *, char *, int) = *(int (***)(void *, int, char *, char *, int))(self + 8);
        r = (*vt)(vt, n, a3, a2, 1);
        if (r <= 0) {
            return r;
        }
        func_003C51E8_F5D0(a3, a2, bytes);
        func_003C51E8_F5D0(*(char **)(self + 0x1C), a2, bytes);
        *(short *)(self + 0x26) = 0;
    } else {
        func_003C51E8_F5D0(a3, *(char **)(self + 0x1C), bytes);
        *(short *)(self + 0x24) = 1;
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF6D0);
#ifdef SKIP_ASM
extern void func_003B5E98(int);

void func_003CF6D0(void *arg0) {
    int temp_4;

    temp_4 = (*(int *)((char*)(arg0) + (0x1C)));
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF6F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct { void *vt; void *f4; int f8; int fc; int f10; int f14; char pad18[3]; char f1b; int f1c; int f20; short f24; short f26; } S_F6F8;
extern void f_F6F8_a(void) __asm__("func_003CF5D0");
extern void f_F6F8_b(void) __asm__("func_003CF6D0");

int func_003CF6F8(S_F6F8 *self) {
self->f26 = 1;
    self->f4 = f_F6F8_b;
    self->vt = f_F6F8_a;
    self->fc = 0;
    self->f10 = 0;
    self->f14 = 0;
    self->f1b = 0;
    self->f20 = 0;
    self->f1c = 0;
    self->f24 = 0;
    self->f8 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF740);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003CF740(char *self, int n, int arg2, void *dst) {
    func_003C51E8(dst, *(char **)(self + 0x1C), n * 4);
    *(char **)(self + 0x1C) += n * 4;
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF798);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF740_F798(void) __asm__("func_003CF740");

void func_003CF798(void *arg0, int arg1) {
    *(int *)((char *)arg0 + 0x1C) = arg1;
    *(int *)((char *)arg0 + 4) = 0;
    *(void (**)(void))((char *)arg0 + 0) = func_003CF740_F798;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF7B0);
#ifdef SKIP_ASM
int func_003CF7B0(void *arg0) {
    (*(int *)((char*)(arg0) + (8))) = 0;
    (*(int *)((char*)(arg0) + (0xC))) = 0;
    (*(int *)((char*)(arg0) + (0x10))) = 0;
    (*(int *)((char*)(arg0) + (0x14))) = 0;
    (*(signed char *)((char*)(arg0) + (0x1B))) = 0;
    (*(int *)((char*)(arg0) + (0x1C))) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF7D0);
#ifdef SKIP_ASM
struct S3CF7D0 { char p0[8]; int *obj; char p1[0xE]; unsigned char f1A; char p2[1]; float *f1C; int f20; int f24; int f28; int f2C; float f30[4]; };
int func_003CF7D0_C(struct S3CF7D0 *self, int n, float *a2, float *a3) __asm__("func_003CF7D0");
int func_003CF7D0_C(struct S3CF7D0 *self, int n, float *a2, float *a3) {
    float *src;
    float *dst;
    int rem;
    int chunk;
    if (self->obj) {
        chunk = ((int (*)(int *, int, float *, float *, int))*self->obj)(self->obj, n, a3, a2, self->f1A);
        if (chunk <= 0) return chunk;
    }
    src = a2;
    dst = a3;
    rem = n;
    src = a2;
    dst = a3;
    rem = n;
    if (rem > 0) {
        int size = self->f28;
        do {
            int pos;
            if (!(self->f24 < size)) self->f24 = 0;
            pos = self->f24;
            chunk = self->f28 - pos;
            if (rem < chunk) chunk = rem;
            // PORT: PS2-only VU0 hand-written loop (blend two 4x4 float blocks with a 2-term factor); one inline asm block.
            __asm__ volatile(
                ".set push\n\t"
                ".set noreorder\n\t"
                ".set noat\n\t"
                "move $6, %0\n\t"
                "move $4, %1\n\t"
                "move $5, %2\n\t"
                "sll $6, $6, 2\n\t"
                "move $7, %3\n\t"
                "move $8, %4\n\t"
                "add $6, $6, $7\n\t"
                "lqc2 $vf1, 0x0($4)\n"
                "1:\n\t"
                "lqc2 $vf4, 0x0($5)\n\t"
                "lqc2 $vf5, 0x10($5)\n\t"
                "lqc2 $vf6, 0x20($5)\n\t"
                "lqc2 $vf7, 0x30($5)\n\t"
                "lqc2 $vf8, 0x0($7)\n\t"
                "lqc2 $vf9, 0x10($7)\n\t"
                "lqc2 $vf10, 0x20($7)\n\t"
                "lqc2 $vf11, 0x30($7)\n\t"
                "vmulx.xyzw $vf12, $vf4, $vf1x\n\t"
                "vmulx.xyzw $vf13, $vf5, $vf1x\n\t"
                "vmulx.xyzw $vf14, $vf6, $vf1x\n\t"
                "vmulx.xyzw $vf15, $vf7, $vf1x\n\t"
                "vadd.xyzw $vf12, $vf12, $vf8\n\t"
                "vadd.xyzw $vf13, $vf13, $vf9\n\t"
                "vadd.xyzw $vf14, $vf14, $vf10\n\t"
                "vadd.xyzw $vf15, $vf15, $vf11\n\t"
                "vmuly.xyzw $vf8, $vf12, $vf1y\n\t"
                "vmuly.xyzw $vf9, $vf13, $vf1y\n\t"
                "vmuly.xyzw $vf10, $vf14, $vf1y\n\t"
                "vmuly.xyzw $vf11, $vf15, $vf1y\n\t"
                "vadd.xyzw $vf8, $vf8, $vf4\n\t"
                "vadd.xyzw $vf9, $vf9, $vf5\n\t"
                "vadd.xyzw $vf10, $vf10, $vf6\n\t"
                "vadd.xyzw $vf11, $vf11, $vf7\n\t"
                "addi $7, $7, 0x40\n\t"
                "addi $8, $8, 0x40\n\t"
                "sqc2 $vf12, 0x0($5)\n\t"
                "sqc2 $vf13, 0x10($5)\n\t"
                "sqc2 $vf14, 0x20($5)\n\t"
                "sqc2 $vf15, 0x30($5)\n\t"
                "sqc2 $vf8, -0x40($8)\n\t"
                "sqc2 $vf9, -0x30($8)\n\t"
                "sqc2 $vf10, -0x20($8)\n\t"
                "sqc2 $vf11, -0x10($8)\n\t"
                "bne $6, $7, 1b\n\t"
                "addi $5, $5, 0x40\n\t"
                ".set pop\n"
                : : "r"(chunk), "r"(self->f30), "r"(self->f1C + pos), "r"(src), "r"(dst)
                : "$4", "$5", "$6", "$7", "$8", "memory");
            self->f24 = pos + chunk;
            rem -= chunk;
            src += chunk;
            dst += chunk;
        } while (rem > 0);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF958);
#ifdef SKIP_ASM
void func_003B5E98(int);

void func_003CF958(char *arg0) {
    int temp_4;

    temp_4 = *(int *)(arg0 + 0x20);
    if (temp_4 != 0) {
        func_003B5E98(temp_4);
        *(int *)(arg0 + 0x20) = 0;
        *(int *)(arg0 + 0x1C) = 0;
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003CF998);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
void func_003CF7D0_F998(void) __asm__("func_003CF7D0");
void func_003CF958_F998(void) __asm__("func_003CF958");

int func_003CF998(char *arg0) {
    *(void (**)(void))(arg0 + 4) = func_003CF958_F998;
    *(void (**)(void))(arg0 + 0) = func_003CF7D0_F998;
    *(int *)(arg0 + 8) = 0;
    *(int *)(arg0 + 0xC) = 0;
    *(int *)(arg0 + 0x10) = 0;
    *(int *)(arg0 + 0x14) = 0;
    *(signed char *)(arg0 + 0x1B) = 0;
    *(int *)(arg0 + 0x20) = 0;
    *(int *)(arg0 + 0x1C) = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CF9D8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void f_F958_F9D8(void) __asm__("func_003CF958");
extern int func_003CFB38(int, int);
extern char *f_5C60_F9D8(int) __asm__("func_003B5C60");
extern void f_6210_F9D8(char *, int, int) __asm__("func_00416210");
void func_003CF9D8(void *arg0, void *arg1) {
    float temp_f0;
    int temp_16;
    int temp_16_2;
    int temp_17;
    int temp_18;
    int temp_2;
    char *temp_2_2;
    int temp_3;

    temp_16 = (*(int *)((char*)(arg1) + (0))) >> 1;
    temp_17 = (*(int *)((char*)(arg1) + (4))) >> 8;
    temp_18 = (*(int *)((char*)(arg1) + (8))) >> 8;
    f_F958_F9D8();
    temp_f0 = (float) temp_16 * 0.007874016f;
    (*(float *)((char*)(arg0) + (0x30))) = temp_f0;
    (*(float *)((char*)(arg0) + (0x34))) = -temp_f0;
    temp_2 = func_003CFB38(temp_17, temp_18);
    temp_16_2 = temp_2 * 4;
    (*(int *)((char*)(arg0) + (0x28))) = temp_2;
    temp_2_2 = f_5C60_F9D8(temp_16_2 + 0x10);
    (*(char **)((char*)(arg0) + (0x20))) = temp_2_2;
    temp_3 = ((unsigned int) ((int)temp_2_2 + 0xF) >> 4) * 0x10;
    (*(int *)((char*)(arg0) + (0x1C))) = temp_3;
    f_6210_F9D8((char*)temp_3, 0, temp_16_2);
    (*(int *)((char*)(arg0) + (0x24))) = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFA98);
#ifdef SKIP_ASM
float func_003CFA98(float fparg0) {
    float temp_f0;
    float temp_f1;
    float temp_f2;
    float temp_f4;
    float temp_f5;
    float temp_f6;

    temp_f0 = fparg0 * 0.5f;
    temp_f1 = temp_f0 * -0.25f * fparg0;
    temp_f2 = temp_f1 * -0.5f * fparg0;
    temp_f4 = temp_f2 * -0.625f * fparg0;
    temp_f5 = temp_f4 * -0.7f * fparg0;
    temp_f6 = temp_f5 * -0.75f * fparg0;
    return temp_f0 + 1.0f + temp_f1 + temp_f2 + temp_f4 + temp_f5 + temp_f6 + (temp_f6 * -0.7857f * fparg0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB38);
#ifdef SKIP_ASM
extern int func_003CFB98(int, int);

int func_003CFB38(int arg0, int arg1) {
    return func_003CFB98(arg0, arg1 / 16) * 16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB68);
#ifdef SKIP_ASM
int func_003CFB68(int n) {
    int i = 0, sq;
    for (;;) {
        sq = i * i;
        i++;
        if (sq != n) {
            if (n < sq) return i - 2;
        } else
            return i - 1;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003CFB98);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003CFB68(int);

int func_003CFB98(int arg0, int arg1) {
    int lim;
    int t;
    int n;
    int d;

    t = (int) (arg1 * arg0) / 1000;
    n = (t <= 2) ? 3 : t;
    for (;;) {
        lim = func_003CFB68(n) + 1;
        for (d = 2; lim >= d; d++) {
            if ((n % d) == 0) {
                n += 1;
                break;
            }
            if (d == lim) {
                return n;
            }
        }
    }
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003CFC30);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0B18);
#ifdef SKIP_ASM
typedef struct { int a, b, c, d; } E_0B18;
typedef struct { int p0, p1, p2; unsigned lo : 16; unsigned idx : 6; unsigned hi : 10; E_0B18 e[1]; } Q_0B18;

void func_003D0B18(Q_0B18 *q, E_0B18 *src) {
    E_0B18 *arr = q->e;
    unsigned i = q->idx;
    q->idx = i + 1;
    arr[i] = *src;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0B78);
#ifdef SKIP_ASM
void func_003D0B78_impl(char *base, int n, char *lim) __asm__("func_003D0B78");
void func_003D0B78_impl(char *base, int n, char *lim) {
    int depth = 0;
    char *e = base + 0x10;
    while (e <= lim && n >= 0) {
        if (((unsigned char *)e)[9] == 1) {
            unsigned m = *(unsigned *)(e + 8) & 0x300000;
            if (m == 0x100000) {
                depth++;
            } else if (m == 0x300000) {
                if (depth-- < 1) {
                    n--;
                }
            } else if (m == 0x200000) {
                if (depth-- < 1) {
                    n--;
                }
            }
        }
        if (n < 1) {
            *(unsigned *)(e + 8) |= 0x4000000;
        }
        e += 0x10;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0C20);
#ifdef SKIP_ASM
void func_003D0C20(unsigned char *a0, unsigned char *a1) {
    unsigned char *p = a0 + 0x10;

    while (a1 >= p && p[9] != 1) {
        *(unsigned int *)(p + 8) |= 0x04000000;
        p += 0x10;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0C78);
#ifdef SKIP_ASM
void func_003D0C78(int arg0, unsigned int arg1) {
    unsigned int temp_4;

    temp_4 = arg0 + 0x10;
    if (arg1 >= temp_4) {
        (*(int *)((char*)(temp_4) + (8))) = (int) ((*(int *)((char*)(temp_4) + (8))) | 0x04000000);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0CA0);
#ifdef SKIP_ASM
extern void func_003D0CC8(int);
extern int func_003D5290();

void func_003D0CA0(void) {
    func_003D0CC8(func_003D5290());
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0CC8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D32B8_0CC8(char *, int *) __asm__("func_003D32B8");
int func_003D0CC8_0CC8(char *arg0) __asm__("func_003D0CC8");

int func_003D0CC8_0CC8(char *arg0) {
    int buf[8];
    unsigned int t;
    int r;
    if (arg0 == 0) {
        return 1;
    }
    {
        t = *(unsigned int *)(arg0 + 0x4C);
        *(int *)(arg0 + 0x100) = 2;
        if (t != 0) {
            if ((unsigned int)D_0044F438 >= t) {
                *(int *)(arg0 + 0x100) = 4;
            } else {
                *(int *)(arg0 + 0x100) = 3;
            }
            goto done;
        }
        if (*(short *)(arg0 + 0x36) >= 0) {
            *(int *)(arg0 + 0x100) = 7;
            if (func_003D32B8_0CC8(arg0, buf) >= 0
                && (unsigned int)(*(int *)(arg0 + 0x24) + D_0044F420->f0C) >= (unsigned int)buf[6]) {
                *(int *)(arg0 + 0x100) = 5;
            }
        }
done:
        r = *(int *)(arg0 + 0x100);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0D70);
#ifdef SKIP_ASM
extern int func_003D5450_0D70(int) __asm__("func_003D5450");

int func_003D0D70(unsigned int mask, unsigned int val) {
    int i, j;
    unsigned int fl, t, u;
    if (D_0044F42C == 0) {
        return -18;
    }
    if (D_0044F430 != 0) {
        return -18;
    }
    if (func_003D5450_0D70(-1) == 0) {
        return -18;
    }
    if (val < 0x80) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(D_00517644 + i * 0x928) != 0) {
                fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
                t = fl & 0xF0000000;
                if ((t & mask) != 0) {
                    u = fl & 0x0F000000;
                    if ((u & mask) != 0 && func_003D5450_0D70(i & 0xFF) != 0) {
                        for (j = 0; j < 24; j++) {
                            struct sPathVoice *e = D_0044F420->f58[j];
                            if (e != 0) {
                                unsigned char t2 = e->f01;
                                e->f01 = val;
                                e->f02 = t2;
                            }
                        }
                    }
                }
            }
        }
    }
    D_0044F430 = 0;
    D_0044F420 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D0ED0);
#ifdef SKIP_ASM
struct Ev_0ED0 { int w0; char pad4[4]; signed char b8; unsigned char b9; short hA; short hC; signed char bE; char pF; };
struct Q_0ED0 { int p[4]; };
struct P_0ED0 { unsigned int x30; int x34; char pad2[0x928 - 8]; };
extern struct P_0ED0 D_00517610_0ED0[4] __asm__("D_00517610");
extern int f5450_0ED0(int) __asm__("func_003D5450");
extern void f6210_0ED0(void *, int, int) __asm__("func_00416210");
extern void f0B18_0ED0(void *, void *) __asm__("func_003D0B18");
extern char *fcopy_0ED0(void *) __asm__("PATHI_copyevent");
extern int func_003D1F80(unsigned int, char *);

int func_003D0ED0(unsigned int arg0, int arg1) {
    struct Ev_0ED0 ev;
    struct Q_0ED0 q;
    unsigned int i;
    unsigned int fl, t, u;
    char *base;
    struct P_0ED0 *p;
    if (D_0044F42C == 0 || D_0044F430 != 0 || f5450_0ED0(-1) == 0) {
        return -18;
    }
    f6210_0ED0(&q, 0, 0x10);
    i = 0;
    f6210_0ED0(&ev, 0, 0x10);
    ev.w0 = arg0;
    ev.b9 = 4;
    ev.bE = ev.b8 = -1;
    ev.hC = arg1;
    f0B18_0ED0(&q, &ev);
    base = (char *)D_00517610_0ED0;
    p = (struct P_0ED0 *)(base + 0x30);
    do {
        if (p->x34 != 0) {
            fl = p->x30;
            t = fl & 0xF0000000;
            if ((t & arg0) != 0 && (u = fl & 0x0F000000, (u & arg0) != 0)) {
                if (f5450_0ED0(i & 0xFF) != 0) {
                    func_003D1F80(arg0, fcopy_0ED0(&q));
                }
            }
        }
        i++;
        p++;
    } while (i < 4);
    D_0044F430 = 0;
    D_0044F420 = 0;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1038);
#ifdef SKIP_ASM
extern int func_003D5450_1038(int) __asm__("func_003D5450");
extern void func_002AF7A0_1038(int, int) __asm__("func_002AF7A0");

static inline int isOff_1038(unsigned int m, int b) { return ((m >> b) & 1) == 0; }
void func_003D1038(unsigned int mask, unsigned char val) {
    int i;
    int j;
    unsigned int fl, t, u;
    struct sPathVoice *e;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    if (func_003D5450_1038(-1) == 0) return;
    if (mask == 0xFFFFFFFF) {
        D_0044F42D = val;
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(D_00517644 + i * 0x928) != 0) {
            fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
            t = fl & 0xF0000000;
            if ((t & mask) != 0) {
                u = fl & 0x0F000000;
                if ((u & mask) != 0 && func_003D5450_1038(i & 0xFF) != 0) {
                    for (j = 0; j < 24; j++) {
                        e = D_0044F420->f58[j];
                        if (e == 0 || isOff_1038(mask, j)) continue;
                        func_002AF7A0_1038(e->f54, val);
                        e->f03 = val;
                    }
                }
            }
        }
    }
    D_0044F420 = 0;
    D_0044F430 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D11B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct Info_11B8 {
    int a;
    int b;
    int c;
    unsigned int total;
    unsigned int f10;
    unsigned int f14;
    unsigned int len;
    unsigned int f1C;
    unsigned int f20;
    int f24;
    int f28;
};
struct Ent_11B8 { int a; int b; int c; int key; };
struct Fmt_11B8 {
    unsigned int pad0 : 20;
    unsigned int ch : 4;
    unsigned int mul : 4;
    unsigned int pad1 : 4;
};
struct Rec_11B8 { int w0; unsigned int w; };
struct S_11B8 {
    char pad0[0x20];
    unsigned int pad20a : 14;
    unsigned int n : 5;
    unsigned int pad20b : 13;
    char pad24[0x36 - 0x24];
    short f36;
    char pad38[0x54 - 0x38];
    int f54;
    char pad58[0xDC - 0x58];
    char name[0xFC - 0xDC];
    struct Ent_11B8 *tbl;
};
extern char D_00495B10_11B8[] __asm__("D_00495B10");
extern int f_5450_11B8(int) __asm__("func_003D5450");
extern struct S_11B8 *f_5290_11B8(unsigned int) __asm__("func_003D5290");
extern int f_4BB0_11B8(unsigned int) __asm__("func_003D4BB0");
extern int f_F2F0_11B8(int, int *, int *, int) __asm__("func_002AF2F0");
extern void f_1658_11B8(char *, char *, int) __asm__("func_003D1658");

int func_003D11B8_impl(unsigned int id, struct Info_11B8 *info) __asm__("func_003D11B8");
int func_003D11B8_impl(unsigned int id, struct Info_11B8 *info) {
    int ret;
    struct S_11B8 *s;
    struct sPath *g;
    struct Rec_11B8 *r;
    unsigned int i;
    unsigned int total;
    unsigned int q;
    int off;
    int len;

    ret = -8;
    if (D_0044F42C == 0 || D_0044F430 != 0 || f_5450_11B8(-1) == 0) {
        return -18;
    }
    info->a = -1;
    info->b = -1;
    info->c = -1;
    info->total = 0;
    info->f10 = 0;
    info->f14 = 0;
    info->len = 0;
    info->f20 = 0;
    info->f1C = 0;
    info->f24 = -1;
    info->f28 = -1;
    s = f_5290_11B8(id);
    if (s == 0) {
        goto done;
    }
    if (f_4BB0_11B8(id & 0xFF000000) != 0) {
        ret = f_F2F0_11B8(s->f54, &off, &len, 0);
        if (ret >= 0) {
            info->len = len;
            info->total = off + len;
            info->f24 = s->f36;
            for (i = 0; i < s->n; i++) {
                if (s->tbl[i].key == ret) {
                    g = D_0044F420;
                    info->a = s->tbl[i].a;
                    total = info->total;
                    info->c = s->tbl[i].c;
                    r = (struct Rec_11B8 *)(g->f34 + g->f38[info->a]);
                    q = total;
                    if (r->w & 0xF00000) {
                        info->f10 = total / ((r->w >> 20) & 0xF);
                        q = total / ((r->w >> 20) & 0xF);
                        if (r->w & 0xF000000) {
                            info->f14 = total / (((r->w >> 24) & 0xF) * ((r->w >> 20) & 0xF));
                            total = total / (((r->w >> 24) & 0xF) * ((r->w >> 20) & 0xF));
                        }
                    }
                    if (q != 0) {
                        info->f1C = info->len % q;
                    } else {
                        info->f1C = 0;
                    }
                    if (total != 0) {
                        info->f20 = info->len % total;
                    } else {
                        info->f20 = 0;
                    }
                    goto done;
                }
            }
            if (D_0044F43C & 0x100) {
                f_1658_11B8(D_00495B10_11B8, s->name, ret);
            }
        }
    }
done:
    D_0044F430 = 0;
    D_0044F420 = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1470);
#ifdef SKIP_ASM
extern int func_003D5450_1470(int) __asm__("func_003D5450");
extern int func_002AF838(int);

void func_003D1470_impl(unsigned int mask) __asm__("func_003D1470");
void func_003D1470_impl(unsigned int mask) {
    int i;
    int j;
    unsigned int fl, t, u;
    struct sPathVoice *e;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    if (func_003D5450_1470(-1) == 0) return;
    for (i = 0; i < 4; i++) {
        if (*(int *)(D_00517644 + i * 0x928) != 0) {
            fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
            t = fl & 0xF0000000;
            if ((t & mask) != 0) {
                u = fl & 0x0F000000;
                if ((u & mask) != 0 && func_003D5450_1470(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        e = D_0044F420->f58[j];
                        if (e != 0) {
                            func_002AF838(e->f54);
                            e->f36 = -1;
                        }
                    }
                }
            }
        }
    }
    D_0044F420 = 0;
    D_0044F430 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D15C8);
#ifdef SKIP_ASM
int func_003D15C8(int arg0, int arg1) {
    char *t = (char *)func_003D5290();
    if (t == 0) {
        return -8;
    }
    *(int *)(t + 0x24) = arg1 & 0xFFFF;
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1608);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_00411310_1608(int, ...) __asm__("func_00411310") __attribute__((noreturn));

void func_003D1608(int a, ...) {
    D_0044F430 = 0xFFFFFFFF;
    func_00411310_1608(0);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1658);
#ifdef SKIP_ASM
void func_003D1658(int a, ...) {
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1690);
#ifdef SKIP_ASM
void func_003D1690(int a, ...) {
}
#endif

void func_003D16C8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D16D0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

int func_003D16D0_16D0(void) __asm__("func_003D16D0");
int func_003D16D0_16D0(void) {
    return D_0044F43C;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D16E0);
#ifdef SKIP_ASM
int func_003D16E0(int arg0) {
    return arg0;
}
#endif

void func_003D16E8(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D16F0);
#ifdef SKIP_ASM
extern int f5450_16F0(int) __asm__("func_003D5450");
extern struct sPathEvent *fcopy_16F0(struct sPathEvent *) __asm__("PATHI_copyevent");
extern unsigned int f_F370_16F0(void) __asm__("func_002AF370");

int func_003D16F0(unsigned int mask, short id) {
    int ret = 0;
    unsigned int i;
    unsigned int bit;
    if (D_0044F42C == 0) return -18;
    if (D_0044F430 != 0) return -18;
    if (f5450_16F0(-1) == 0) return -18;
    bit = 0x1000000 << ((id & 0xF00) >> 8);
    id &= 0xFF;
    for (i = 0; i < 4; i++) {
        unsigned int fl, t, u;
        if (D_00517610[i].f34 == 0) continue;
        fl = D_00517610[i].f30;
        if ((fl & bit) == 0) continue;
        u = fl & 0x0F000000;
        if ((u & mask) == 0) continue;
        t = fl & 0xF0000000;
        if ((t & mask) == 0) continue;
        if (f5450_16F0(i & 0xFF) != 0) {
            unsigned int *data = D_0044F420->f34;
            struct sPathEvent *ev;
            unsigned int key;
            int r;
            int j;
            if (id >= ((unsigned char *)data)[0xF]) {
                ret = -13;
                break;
            }
            ev = (struct sPathEvent *)(data + D_0044F420->f40[id]);
            if (ev->f0C.w & 0x20000000) continue;
            ev = fcopy_16F0(ev);
            r = -8;
            key = D_00517610[i].f30;
            key &= 0xFF000000;
            for (j = 0; j < 4; j++) {
                if (D_00517610[j].f34 != 0 && (D_00517610[j].f30 & key) == key) {
                    int n = D_00517610[j].f91C;
                    if (n >= 16) {
                        ret = -13;
                        goto next;
                    }
                    r = 0;
                    ev->f00 = ev->f08 = f_F370_16F0();
                    D_00517610[j].f0DC[n] = ev;
                    n++;
                    D_00517610[j].f91C = n;
                }
            }
            ret = r;
        }
    next:;
    }
    D_0044F430 = 0;
    D_0044F420 = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1940);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003D1BA8_1940(int, int) __asm__("func_003D1BA8");
extern int func_003D5450_1940(int) __asm__("func_003D5450");


void func_003D1940(unsigned int mask) {
    int i, j;
    unsigned int fl, t, u;
    if (D_0044F42C != 0) {
        if (D_0044F430 == 0) {
            if (func_003D5450_1940(-1) != 0) {
                for (i = 0; i < 4; i++) {
                    if (*(int *)(D_00517644 + i * 0x928) != 0) {
                        fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
                        t = fl & 0xF0000000;
                        if ((t & mask) != 0 && (u = fl & 0x0F000000, (u & mask) != 0)) {
                            if (func_003D5450_1940(i & 0xFF) != 0) {
                                for (j = 0; j < 0x10; j++) {
                                    if (D_0044F420->f0DC[j] != 0) {
                                        func_003D1BA8_1940(j, 2);
                                    }
                                }
                            }
                        }
                    }
                }
                D_0044F420 = 0;
                D_0044F430 = 0;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1A88);
#ifdef SKIP_ASM
extern int func_003D5450_1A88(int) __asm__("func_003D5450");

int func_003D1A88_impl(unsigned int mask) __asm__("func_003D1A88");
int func_003D1A88_impl(unsigned int mask) {
    int n = 0;
    int i;
    int j;
    if (D_0044F42C == 0 || D_0044F430 != 0 || func_003D5450_1A88(-1) == 0) {
        return -0x12;
    }
    mask &= 0x0F000000;
    for (i = 0; i < 4; i++) {
        if (D_00517610[i].f34 != 0 && (D_00517610[i].f30 & mask) != 0 && func_003D5450_1A88(i & 0xFF) != 0) {
            for (j = 0; j < 16; j++) {
                if (D_0044F420->f0DC[j] != 0) {
                    n++;
                }
            }
            break;
        }
    }
    D_0044F430 = 0;
    D_0044F420 = 0;
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1BA8);
#ifdef SKIP_ASM
struct B16_1BA8 { char b[16]; };
struct G_1BA8 { char pad[0xDC]; unsigned a[17]; char pad120[0x91C - 0x120]; int n; };
extern struct G_1BA8 *D_0044F420_1BA8 __asm__("D_0044F420");
extern void func_0041605C_1BA8(unsigned, unsigned, unsigned) __asm__("func_0041605C");


void func_003D1BA8(int idx, int status) {
    struct B16_1BA8 hdr; /* copied but unused: its reader is compiled out in the release build */
    unsigned e = D_0044F420_1BA8->a[idx];
    unsigned end = (unsigned)D_0044F420_1BA8 + 0x91C;
    int sz = (*(unsigned short *)(e + 0xE) & 0x3F) * 16 + 16;
    unsigned i;
    int k;
    hdr = *(struct B16_1BA8 *)e;
    if (e >= (unsigned)D_0044F420_1BA8 + 0x11C && e < end) {
        func_0041605C_1BA8(e, e + sz, end - e);
        for (i = 0; i < 17; i++) {
            unsigned p = D_0044F420_1BA8->a[i];
            if (e < p && p < end) {
                D_0044F420_1BA8->a[i] = p - sz;
            }
        }
    } else {
        if (D_0044F428 != 0) {
            D_0044F428(e, status);
        }
    }
    D_0044F420_1BA8->a[idx] = 0;
    for (idx++; idx < 16; idx++) {
        D_0044F420_1BA8->a[idx - 1] = D_0044F420_1BA8->a[idx];
    }
    D_0044F420_1BA8->n--;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1D28);
#ifdef SKIP_ASM
struct E_1D28 {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
};
extern int func_003CFC30_1D28(struct sPathEvent *, struct E_1D28 *) __asm__("func_003CFC30");

int func_003D1D28_impl(int idx) __asm__("func_003D1D28");
int func_003D1D28_impl(int idx) {
    struct sPathEvent *h = D_0044F420->f0DC[idx];
    unsigned int i = h->f0C.b.start;
    int n = 0;
    if (i < h->f0C.b.end) {
        struct E_1D28 *e = (struct E_1D28 *)(i * 16 + ((int)h + 16));
        do {
            if (e->f4 != 0) {
                if (e->f4 < h->f00) {
                    e->f4 += D_0044F438;
                }
                if (e->f4 < D_0044F438) {
                    e->f8 |= 0x04000000;
                }
            }
            if (!(e->f8 & 0x04000000) && func_003CFC30_1D28(h, e) == 0) {
                break;
            }
            i++;
            n++;
            e++;
            h->f08 = D_0044F438;
            h->f0C.b.start++;
        } while (i < h->f0C.b.end);
    }
    return n;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1E80);
#ifdef SKIP_ASM
extern void f_1BA8_1E80(int, int) __asm__("func_003D1BA8");
extern int f_1D28_1E80(int) __asm__("func_003D1D28");

int func_003D1E80_impl(void) __asm__("func_003D1E80");
int func_003D1E80_impl(void) {
    int i;
    int sum = 0;
    struct sPathEvent *o;
    int st;
    unsigned int v;
    for (i = 0; i < 16; i++) {
        if (i >= D_0044F420->f91C) {
            D_0044F420->f0DC[i] = 0;
            continue;
        }
        o = D_0044F420->f0DC[i];
        if (o == 0) break;
        v = o->f0C.w;
        st = ((v >> 22) & 0x3F) < ((v >> 16) & 0x3F) ? 0 : 3;
        if (o->f04 != 0) {
            if (o->f00 + o->f04 < D_0044F438) st = 1;
        }
        if (st != 0) {
            f_1BA8_1E80(i, st);
            i--;
        } else {
            sum += f_1D28_1E80(i);
        }
    }
    return sum;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D1F80);
#ifdef SKIP_ASM
extern int func_002AF370(void);

int func_003D1F80(unsigned int a0, char *a1) {
    unsigned int m = a0 & 0xFF000000;
    int i, ret = -8;
    for (i = 0; i < 4; i++) {
        if (D_00517610[i].f34 != 0 && (D_00517610[i].f30 & m) == m) {
            int c = D_00517610[i].f91C;
            if (c >= 0x10) return -0xD;
            ret = 0;
            {
                int t = func_002AF370();
                *(int *)(a1 + 8) = t;
                *(int *)a1 = t;
            }
            D_00517610[i].f0DC[c] = (struct sPathEvent *)a1;
            c++;
            D_00517610[i].f91C = c;
        }
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", PATHI_copyevent);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044F420_2068[] __asm__("D_0044F420");
extern char D_00495B48_2068[] __asm__("D_00495B48");
extern void func_0041605C_2068(unsigned int, void *, int) __asm__("func_0041605C");

unsigned int PATHI_copyevent(void *arg0) {
    int temp_9;
    unsigned int *p;
    unsigned int temp_3;
    unsigned int temp_6;
    unsigned int cur;
    unsigned int i;

    temp_6 = D_0044F420_2068[0] + 0x91C;
    cur = D_0044F420_2068[0] + 0x11C;
    p = (unsigned int*)(D_0044F420_2068[0] + 0xDC);
    temp_9 = (((*(unsigned short*)((char*)arg0 + 0xE)) & 0x3F) * 0x10) + 0x10;
    for (i = 0; i < 0x10; i++, p++) {
        temp_3 = *p;
        if (temp_3 >= cur) {
            if (temp_3 < temp_6) {
                int sz = (((*(unsigned short*)((char*)temp_3 + 0xE)) & 0x3F) * 0x10) + 0x10;
                cur += sz;
            }
        }
    }
    if (cur + temp_9 < temp_6) {
        func_0041605C_2068(cur, arg0, temp_9);
        return cur;
    }
    if (D_0044F43C & 0x120) {
        func_003D1658(D_00495B48_2068, temp_9, temp_6 - cur);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2138);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct I2138 { int w0; int w4; unsigned int w8; int wC; };
struct E2138 { char pad[0xC]; unsigned char b; char padd; unsigned short h; struct I2138 items[1]; };
extern struct E2138 **D_0044F420_2138[] __asm__("D_0044F420");

int func_003D2138(char *arg0, int arg1) {
    int i;
    unsigned int j;
    struct E2138 *e;
    struct I2138 *it;
    for (i = 0; i < 16; i++) {
        e = *(struct E2138 **)((char *)D_0044F420_2138[0] + 0xDC + i * 4);
        if (e != 0 && e->b == *(unsigned char *)(arg0 + 0xC)) {
            for (j = 0; j < (e->h & 0x3F); j++) {
                it = &e->items[j];
                if (((unsigned char *)it)[9] == arg1) {
                    return (it->w8 >> 26) & 1;
                }
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D21C0);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003D21C0(char *arg0, int arg1) {
    unsigned int *p = D_0044F420->f34 + D_0044F420->f40[*(unsigned char *)(arg0 + 0xC)];
    if (p != 0) {
        p[3] = (p[3] & 0xDFFFFFFF) | ((arg1 & 1) << 29);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2218);
#ifdef SKIP_ASM
struct E_2218 { int w0; int w4; int w8; unsigned int wC; };

void func_003D2218(void) {
    int i;
    for (i = 0; i < ((unsigned char *)D_0044F420->f34)[0xF]; i++) {
        struct E_2218 *p = (struct E_2218 *)(D_0044F420->f34 + D_0044F420->f40[i]);
        if (p != 0) {
            p->wC &= 0xDFFFFFFF;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2290);
#ifdef SKIP_ASM

int func_003D2290(void) {
    int i, j;
    if (D_0044F430 != 0) return -0x12;
    for (i = 0; i < 4; i++) {
        D_00517610[i].f34 = 0;
        D_00517610[i].f924 = 0;
        for (j = 0; j < 24; j++) {
            D_00517610[i].f58[j] = 0;
        }
    }
    D_0044F42C = 1;
    D_0044F43C = 0x100;
    D_0044F420 = 0;
    D_0044F42D = 0;
    return 0;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D2350);

INCLUDE_ASM("ealib/seg_2B4578", func_003D25F0);

INCLUDE_ASM("ealib/seg_2B4578", func_003D2A68);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2C20);
#ifdef SKIP_ASM
// PORT: 64-bit `long` (8 bytes on EE, 4 on Windows); use int64_t/uint64_t off-PS2.
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D5450_2C20(int) __asm__("func_003D5450");
extern int func_003D4BB0(int);
extern double func_00413AF8(float);
extern double func_00411F18_2C20(double, double) __asm__("func_00411F18");
extern int func_004126A0_2C20(double) __asm__("func_004126A0");
extern char *D_0044F420_2C20[] __asm__("D_0044F420");

static inline int bitclear_2C20(int x) {
    return !(x & 1);
}

int func_003D2C20(int m, int arg1) {
    float ratio, max;
    unsigned int i;
    char *g;
    int *base;
    int *tab;
    int *e;
    int r;

    ratio = 0.0f;
    max = 0.0f;
    if (D_0044F42C == 0 || D_0044F430 != 0 || func_003D5450_2C20(-1) == 0) {
        return -0x12;
    }
    if (func_003D4BB0(m & 0xFF000000) == 0) {
        return 0;
    }
    i = 0;
    while (i < 24 && bitclear_2C20((long)m >> i)) {
        i++;
    }
    g = D_0044F420_2C20[0];
    base = *(int **)(g + 0x34);
    if (*((unsigned char *)base + 0xD) < i) {
        return 0;
    }
    tab = *(int **)(g + 0x4C);
    for (e = base + tab[i]; e < base + tab[i + 1] - 2; e += 2) {
        ratio = (float)((unsigned int)(e[2] - e[0]) << 7) / (float)(unsigned int)e[1];
        if (max < ratio) {
            max = ratio;
        }
    }
    r = func_004126A0_2C20(func_00411F18_2C20(func_00413AF8(ratio * arg1), 0.5));
    D_0044F430 = 0;
    D_0044F420_2C20[0] = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2DF8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_2DF8 { unsigned int f0; unsigned int f4; unsigned int f8; };
struct R_2DF8 { unsigned short n; unsigned short type; unsigned int f4; unsigned int f8; };
struct T_2DF8 { char pad[0x54]; int f54; char pad2[4]; char f5C[0x104 - 0x5C]; unsigned int f104; unsigned int f108; };
extern struct T_2DF8 *func_003D5290_2DF8(int) __asm__("func_003D5290");
extern int func_003D5450_2DF8(int) __asm__("func_003D5450");
extern struct R_2DF8 *func_003D4A50_2DF8(int) __asm__("func_003D4A50");
extern int func_003D3140_2DF8(int, int) __asm__("func_003D3140");
extern int func_002AE3A8(int);
extern int func_002AE298_2DF8(int, char *, int, int) __asm__("func_002AE298");

int func_003D2DF8(int h, int idx, int arg2) {
    int ret = 0;
    struct T_2DF8 *t;
    struct R_2DF8 *r;
    struct E_2DF8 *e;

    if (D_0044F42C != 0) {
        if (D_0044F430 != 0) {
            return -0x12;
        }
        if (func_003D5450_2DF8(-1) != 0) {
            goto ok;
        }
    }
    return -0x12;
ok:
    t = func_003D5290_2DF8(h);
    if (t != 0) {
        r = func_003D4A50_2DF8(h);
        e = (struct E_2DF8 *)(r + 1);
        e += idx;
        if (r != 0 && r->type != 2) {
            if (r->f4 < t->f104 + e->f4 || r->f8 < t->f108 + e->f8) {
                if (r->type == 1) {
                    unsigned int min = 0x7FFFFFFF;
                    int sel = -1;
                    int i;
                    e = (struct E_2DF8 *)(r + 1);
                    for (i = 0; i < r->n; i++, e++) {
                        if (e->f0 <= min) {
                            min = e->f0;
                            sel = i;
                        }
                    }
                    if (sel == idx) {
                        return 0;
                    }
                    func_003D3140_2DF8(h, sel);
                } else if (r->type == 0) {
                    func_002AE3A8(h);
                }
            }
        }
        ret = func_002AE298_2DF8(t->f54, t->f5C, idx, arg2);
    }
    D_0044F430 = 0;
    D_0044F420 = 0;
    return ret;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FA0);
#ifdef SKIP_ASM
void func_003D2FA0(void) {
    func_003D16C8();
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FC0);
#ifdef SKIP_ASM
extern void func_003D16D0();

void func_003D2FC0(void) {
    func_003D16D0();
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D2FE0);
#ifdef SKIP_ASM
int func_003D2A68(int);
int func_003D2FE0(void) {
    func_003D2A68(-1);
    D_0044F42C = 0;
    D_0044F430 = 0;
    return 0;
}
#endif

void func_003D3010(void) {
}

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3018);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003D3018(void (*arg0)(int, int), void (*arg1)(unsigned int, int)) {
    D_0044F424 = arg0;
    D_0044F428 = arg1;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3030);
#ifdef SKIP_ASM
int func_003D3030(int id) {
    char *temp_2;

    temp_2 = (char *)func_003D5290();
    if (temp_2 == 0) {
        return -8;
    }
    return *(int *)(temp_2 + 0x54);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3058);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AE478_3058() __asm__("func_002AE478");

int func_003D3058(int n, int b) {
    int t = func_002AE478_3058() + 0x110;
    t += n * 0x10;
    return (t / 16) * 16 + 0x10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D30A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002AE768_30A8(int, int, int) __asm__("func_002AE768");
extern void *func_003D5290_30A8(int) __asm__("func_003D5290");
extern int func_003D5450_30A8(int) __asm__("func_003D5450");

void func_003D30A8(int arg0, int arg1, int arg2) {
    int var_4;
    void *temp_2;

    if ((D_0044F42C != 0) && (D_0044F430 == 0) && (func_003D5450_30A8(-1) != 0)) {
        temp_2 = func_003D5290_30A8(arg0);
        var_4 = -8;
        if (temp_2 != 0) {
            var_4 = (*(int *)((char*)(temp_2) + (0x54)));
        }
        func_002AE768_30A8(var_4, arg1, arg2);
        D_0044F430 = 0;
        D_0044F420 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3140);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AE328(int, int);
extern char *func_003D5290_3140(int) __asm__("func_003D5290");
extern int func_003D5450_3140(int) __asm__("func_003D5450");
int func_003D3140_3140(int arg0, int arg1) __asm__("func_003D3140");

int func_003D3140_3140(int arg0, int arg1) {
    int r;
    char *t;
    r = 0;
    if (D_0044F42C != 0) {
        if (D_0044F430 != 0) {
            return -0x12;
        }
        if (func_003D5450_3140(-1) != 0) {
            goto ok;
        }
    }
    return -0x12;
ok:
    t = func_003D5290_3140(arg0);
    if (t != 0) {
        r = func_002AE328(*(int *)(t + 0x54), arg1);
    }
    D_0044F430 = 0;
    D_0044F420 = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D31E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.

void func_003D31E8(unsigned int a, int b, int c) {
    int i;
    if (D_0044F42C != 0 && D_0044F430 == 0) {
        if (func_003D5450(-1)) {
            a &= 0x0F000000;
            for (i = 0; i < 4; i++) {
                if (D_00517610[i].f34 != 0 && (D_00517610[i].f30 & a) != 0) {
                    D_00517610[i].f0C = b;
                    D_00517610[i].f10 = c;
                }
            }
            D_0044F430 = 0;
            D_0044F420 = 0;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D32A8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int D_0044ED48_32A8[4] __asm__("D_0044ED48");

int *func_003D32A8(void) {
    return D_0044ED48_32A8;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D32B8);

INCLUDE_ASM("ealib/seg_2B4578", func_003D3658);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D37A0);
#ifdef SKIP_ASM
struct R_37A0 { signed char lo; signed char hi; short v; };
int func_003D37A0(int arg0, int arg1) {
    struct sPath *g = D_0044F420;
    int r = -1;
    unsigned int *e = g->f34 + g->f38[arg0];
    unsigned int w0 = e[0];
    struct sPathVoice *s = g->f58[(w0 >> 16) & 0x1F];
    struct R_37A0 *p = (struct R_37A0 *)(e + 4);
    unsigned int i;
    if (s->f2C == arg0) {
        arg1 = s->lo & 0x7F;
        if ((int)w0 >> 28 > 0) {
            if (--s->lo == -1) {
                s->f2C = -1;
            }
        }
    }
    for (i = 0; i < ((e[1] >> 12) & 0x1F); i++) {
        if (arg1 >= p[i].lo && p[i].hi >= arg1) {
            r = p[i].v;
            break;
        }
    }
    if (r < 0) {
        int n = (e[1] >> 12) & 0x1F;
        if (n <= 0) {
            r = -1;
        } else {
            struct R_37A0 *best = p;
            int bd = 0x7F;
            int k;
            for (k = 0; k < n; k++) {
                int a = p[k].lo - arg1;
                int b = p[k].hi - arg1;
                int m;
                if (a < 0) a = -a;
                if (b < 0) b = -b;
                m = a < b ? a : b;
                if (m < bd) {
                    bd = m;
                    best = &p[k];
                }
            }
            r = (unsigned short)best->v;
        }
    }
    return r;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D3900);
#ifdef SKIP_ASM
// PORT: 64-bit `long` bitfields (8 bytes on EE); use uint64_t off-PS2.
struct E_3900 {
    short type;
    unsigned short h2;
    unsigned int w4;
    unsigned int w8;
    unsigned int wC;
};
struct Ev_3900 {
    int w0;
    int w4;
    signed char b8;
    unsigned char b9;
    short pad;
    unsigned char bC;
    unsigned long f7 : 7;
    unsigned long f1 : 1;
    unsigned short hE;
};
struct Q_3900 {
    int p0;
    int p1;
    int p2;
    unsigned long lo : 12;
    unsigned long b : 4;
    unsigned long idx : 6;
    unsigned long hi : 10;
};
extern int func_003D3C90(int, int);
extern int f37A0_3900(int, int) __asm__("func_003D37A0");
extern void f6210_3900(void *, int, int) __asm__("func_00416210");
extern void f0B18_3900(void *, void *) __asm__("func_003D0B18");
extern char *fcopy_3900(void *) __asm__("PATHI_copyevent");

int func_003D3900(int id, int start, int vel) {
    struct Ev_3900 ev;
    struct Q_3900 q;
    struct E_3900 *e;
    struct sPathVoice *v;
    unsigned int t;
    unsigned int w;
    short k;
    short type;
    int save;

    save = vel;
    k = func_003D3C90(id, start);
    e = (struct E_3900 *)(D_0044F420->f34 + D_0044F420->f38[k]);
    v = D_0044F420->f58[e->h2 & 0x1F];
    while (e->type <= 0) {
        type = e->type;
        if (type == 0) {
            v->f30 = (unsigned int *)e;
            if (e->w8 & 0x7C00) {
                f6210_3900(&q, 0, 0x10);
                f6210_3900(&ev, 0, 0x10);
                t = D_0044F420->f54[((e->w8 >> 10) & 0x1F) - 1];
                if (t & 0x80) {
                    ev.bC = 100;
                } else {
                    ev.bC = 0;
                }
                ev.f1 = (t >> 7) & 1;
                ev.b9 = 6;
                ev.hE = 0x25A0;
                ev.f7 = ((e->w8 >> 10) & 0x1F) - 1;
                ev.b8 = -1;
                q.p1 = ev.hE;
                ev.w4 = D_0044F438 + ev.hE;
                ev.w0 = 0x1F000001;
                q.b = 0;
                f0B18_3900(&q, &ev);
                func_003D1F80(D_00517610[0].f30, fcopy_3900(&q));
            }
            if ((e->w4 & 0xE0000) == 0x20000) {
                vel = (D_0044F438 / 23) & 0x7F;
            }
            if (D_0044F424 != 0) {
                D_0044F424(D_0044F430, k);
            }
        } else if (type == -1) {
            w = *(unsigned int *)e;
            if (w & 0xF0000000) {
                if (k != v->f2C) {
                    v->f2C = k;
                    v->lo = w >> 28;
                }
            }
        } else if (type == -2) {
            vel = (D_0044F438 / 23) & 0x7F;
        } else if (type == -3) {
            func_003D1F80(D_0044F420->f30, (char *)(D_0044F420->f34 + D_0044F420->f40[(e->wC >> 2) & 0xFFF]));
        }
        t = f37A0_3900(k, vel);
        vel = save;
        k = func_003D3C90(id, t);
        e = (struct E_3900 *)(D_0044F420->f34 + D_0044F420->f38[k]);
    }
    return (short)func_003D3C90(id, k);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D3C90);
#ifdef SKIP_ASM

int func_003D3C90(int idx, int def) {
    int ret = def;
    struct sPath *g;
    unsigned int *base;
    int k;
    if (idx < 0) return ret;
    g = D_0044F420;
    base = g->f34;
    k = ((unsigned char *)base)[g->f38[idx] * 4 + 4];
    if (k == 0) return ret;
    {
        int lo = g->f48[k - 1];
        int n = g->f48[k] - lo;
        unsigned int *start = base + lo;
        int i;
        for (i = 0; i < n; i++) {
            unsigned int w = start[i];
            if (ret == (int)w >> 16) ret = w & 0xFFFF;
        }
    }
    return ret;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D3D20);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
struct E_3D20 { unsigned short h0; unsigned short h2; unsigned int w4; int w8; int wC; };
extern int f_37A0_3D20(int, int) __asm__("func_003D37A0");
extern int func_003D3900(int, int, int);
extern int func_003D4050(int);
extern int f_41A8_3D20(struct sPathVoice *) __asm__("func_003D41A8");

void func_003D3D20(int idx) {
    struct sPathVoice save;
    struct sPathVoice *v;
    struct sPathVoice *w;
    struct E_3D20 *e;
    int old;
    int ch;
    int sel;
    int n;
    int k;
    int r;

    sel = -1;
    old = D_0044F420->f91C;
    v = D_0044F420->f58[idx];
    save = *v;
    ch = -1;
    k = v->f36;
    e = (struct E_3D20 *)(D_0044F420->f34 + D_0044F420->f38[k]);
    n = v->ch;
    if (v->f2F) {
        ch = 1;
    }
    if (n > 0 && (e->wC & 2) && (int)(((e->w4 >> 24) & 0xF) * ((e->w4 >> 20) & 0xF)) >= n) {
        sel = k;
        ch = n;
    } else if (v->f36 >= 0) {
        sel = f_37A0_3D20(v->f36, v->f01);
    }
    if (sel >= 0) {
        sel = func_003D3900(v->f36, sel, v->f01);
    }
    e = (struct E_3D20 *)(D_0044F420->f34 + D_0044F420->f38[sel]);
    w = D_0044F420->f58[e->h2 & 0x1F];
    if (w != 0 && w != v) {
        v->f36 = -1;
        v->ch = ch;
        func_003D4050(sel);
        return;
    }
    v->f36 = sel;
    v->ch = ch;
    r = f_41A8_3D20(v);
    if (r >= 0 || r == -9999) {
        return;
    }
    D_0044F420->f91C = old;
    *v = save;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4050);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_003D0B18_4050(void *, void *) __asm__("func_003D0B18");
extern void func_003D1F80_4050(int, int) __asm__("func_003D1F80");
extern int PATHI_copyevent_4050(void *) __asm__("PATHI_copyevent");
extern void func_003D32B8_4050(struct sPathVoice *, void *) __asm__("func_003D32B8");
extern void *func_00416210(void *, int, int);
struct M_4050 {
    int w0;
    int w4;
    unsigned char b8;
    unsigned char b9;
    unsigned char ba, bb;
    short sc;
    char be;
    char bf;
};
struct B_4050 { char pad[0x18]; int w18; char rest[4]; };

int func_003D4050(int idx) {
    struct M_4050 m;
    struct M_4050 a;
    struct B_4050 buf;
    char *e = (char *)(D_0044F420->f34 + D_0044F420->f38[idx]);
    int r = 0;
    int k, h;
    if (e != 0) {
        k = *(unsigned short *)(e + 2) & 0x1F;
        if (D_0044F420->f58[k] != 0) {
            h = (int)((1L << k) | 0x11000000);
            func_00416210(&a, 0, 0x10);
            func_00416210(&m, 0, 0x10);
            if (D_0044F420->f00 >= 0) {
                func_003D32B8_4050(D_0044F420->f58[D_0044F420->f00], &buf);
                m.b9 = 2;
                m.w0 = h;
                *(int *)&m.sc = buf.w18 - 0xA;
                func_003D0B18_4050(&a, &m);
            }
            m.b9 = 4;
            m.w0 = h;
            m.b8 = (*(unsigned int *)e >> 21) & 0x3F;
            m.sc = idx;
            m.be = -1;
            func_003D0B18_4050(&a, &m);
            r = PATHI_copyevent_4050(&a);
            func_003D1F80_4050(h, r);
        }
    }
    return r;
}
#endif

INCLUDE_ASM("ealib/seg_2B4578", func_003D41A8);

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4898);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
typedef struct E_4898 { short v; short w; } E_4898;
typedef struct B_4898 { E_4898 ent[0x40]; } B_4898;
typedef struct A_4898 { char pad0[0x34]; B_4898 *b; short *idx; char pad1[0x50 - 0x3C]; char *arr; } A_4898;
extern A_4898 *D_0044F420_F420[] __asm__("D_0044F420");

static inline int get_4898(char *arr, int i) {
    return *(int *)(arr + i * 8);
}

int func_003D4898(int arg0) {
    int var_7;
    A_4898 *a;
    B_4898 *b;
    short t;

    var_7 = 0;
    if (arg0 < 0) return 0;
    a = D_0044F420_F420[0];
    b = a->b;
    if (arg0 >= *(unsigned short *)((char *)b + 0x12)) return 0;
    t = b->ent[a->idx[arg0]].v;
    if (t > 0) {
        var_7 = get_4898(a->arr, t - 1);
    }
    return var_7;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4900);
#ifdef SKIP_ASM
struct S_4900 {
    int a0;
    int a4;
    int a8;
    int ac;
    unsigned int a10;
    int a14;
    int a18;
    int a1c;
};
extern int func_003D32B8(int, struct S_4900 *);

int func_003D4900(int a0, int *a1) {
    struct S_4900 s;

    if (func_003D32B8(a0, &s) < 0) {
        s.a4 = 0;
        s.a10 = 0xFFFFFFFF;
    }
    if (a1 != 0) {
        *a1 = s.a4;
    }
    return s.a10;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4950);
#ifdef SKIP_ASM
extern int func_002AEAA8(int, unsigned int);

int func_003D4950(char *arg0) {
    int temp_2;
    int var_16 = 0;
    unsigned int i;

    for (i = 0; i < ((*(unsigned int *)(arg0 + 0x20) >> 0xE) & 0x1F); i++) {
        temp_2 = func_002AEAA8(*(int *)(arg0 + 0x54), i);
        if (temp_2 >= 0) {
            var_16 += temp_2;
        }
    }
    return var_16;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D49D0);
#ifdef SKIP_ASM
struct C_49D0 { signed char a; signed char b; unsigned short v; };

int func_003D49D0(int n, int key, struct C_49D0 *tbl) {
    struct C_49D0 *best = tbl;
    int bd;
    int i;
    if (n <= 0) return -1;
    bd = 0x7F;
    for (i = 0; i < n; i++) {
        int da = tbl[i].a - key;
        int db = tbl[i].b - key;
        int d;
        if (da < 0) da = -da;
        if (db < 0) db = -db;
        d = da < db ? da : db;
        if (d < bd) {
            bd = d;
            best = &tbl[i];
        }
    }
    return best->v;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4A50);
#ifdef SKIP_ASM
int func_003D4A50(unsigned arg0) {
    unsigned i, b;
    unsigned hi = arg0 & 0xF0000000;
    unsigned mid = arg0 & 0x0F000000;
    unsigned m = arg0 & 0xFFFFFF;
    for (i = 0; i < 4; i++) {
        unsigned mk = D_00517610[i].f30;
        if (D_00517610[i].f924 != 0 && D_00517610[i].f34 != 0 &&
            (mk & hi) && (mk & mid)) {
            for (b = 0; b < 0x18; b++) {
                if ((m >> b) & 1)
                    return D_00517610[i].f924[b];
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4B00);
#ifdef SKIP_ASM

static inline int valid_4B00(struct sPathVoice *e) { return e->f36 >= 0 && e->f30 != 0; }

void func_003D4B00(void) {
    int i;
    D_0044F420->f00 = -1;
    D_0044F420->f04 = 0;
    D_0044F420->f08 = 0;
    for (i = 0; i < 24; i++) {
        struct sPathVoice *e = D_0044F420->f58[i];
        if (e != 0 && e->f03 == 0 && valid_4B00(e) && D_0044F420->f04 < e->f24) {
            D_0044F420->f04 = e->f24;
            D_0044F420->f00 = i;
            D_0044F420->f08 = (*e->f30 >> 21) & 0x3F;
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4BB0);
#ifdef SKIP_ASM

static inline int sel_4BB0(unsigned int idx) {
    if (D_0044F430 == 0)
        D_0044F430 = 0xFFFFFFFF;
    if (idx < 4 && D_00517610[idx].f34 != 0) {
        int v = D_00517610[idx].f30;
        D_0044F420 = &D_00517610[idx];
        D_0044F430 = v;
        return v;
    }
    if ((int)idx != -1)
        D_0044F430 = 0;
    return D_0044F430;
}

int func_003D4BB0(int key) {
    int i;
    for (i = 0; i < 4; i++) {
        if (D_00517610[i].f34 != 0 && D_00517610[i].f30 == key)
            return sel_4BB0(i);
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D4C40);
#ifdef SKIP_ASM
void func_003D4C40(void) {
    struct sPath tmp;
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        if (*(void **)(D_00517644 + i * 0x928) != 0) {
            for (j = i + 1; j < 4; j++) {
                if (D_00517610[j].f34 != 0 && D_00517610[j].f30 < D_00517610[i].f30) {
                    tmp = D_00517610[i];
                    D_00517610[i] = D_00517610[j];
                    D_00517610[j] = tmp;
                }
            }
        }
    }
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D4F10);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern void func_002AE9F8(int h, int a);
extern int func_002AEBD0(int h);
extern int func_003D1E80_4F10(void) __asm__("func_003D1E80");
extern void func_003D3D20_4F10(unsigned int i) __asm__("func_003D3D20");
extern int func_003D4950_4F10(struct sPathVoice *s) __asm__("func_003D4950");
extern void func_003D5A98_4F10(struct sPathVoice *s) __asm__("func_003D5A98");
extern void func_003D5CC0_4F10(struct sPathVoice *s) __asm__("func_003D5CC0");
extern void func_003D5EE8_4F10(struct sPathVoice *s) __asm__("func_003D5EE8");

void func_003D4F10(void) {
    int isB = D_0044F434 == 'B';
    unsigned int step;
    unsigned int i;
    struct sPathVoice *s;
    unsigned int end;
    int ok;
    int r;
    int skip;

    if (isB) {
        step = D_0044F420->f10;
    } else {
        step = D_0044F420->f0C;
    }
    if (!isB) {
        func_003D1E80_4F10();
    }
    for (i = 0; i < 24; i++) {
        s = D_0044F420->f58[i];
        if (s == 0 || s->f03 != 0) {
            continue;
        }
        ok = 0;
        end = D_0044F438 + s->f24;
        if (s->f36 >= 0) {
            ok = s->f30 != 0;
        }
        if (ok) {
            if (s->f0D >= 0) {
                func_003D5A98_4F10(s);
            }
            if (s->f15 >= 0) {
                func_003D5CC0_4F10(s);
            }
            if (s->f1D >= 0) {
                func_003D5EE8_4F10(s);
            }
        }
        if ((s->f2F != 0) != isB || !ok) {
            continue;
        }
        if (s->f4C != 0) {
            if (D_0044F438 + (step >> 1) >= s->f4C) {
                func_002AE9F8(s->f54, 0);
                s->f4C = 0;
            }
        } else if (func_002AEBD0(s->f54) != 0) {
            r = func_003D4950_4F10(s);
            if (s->f48 != 0) {
                end += step;
                skip = end < s->f48;
            } else {
                skip = s->f24 < r;
            }
            if (!skip) {
                if (s->f0E == 0 && func_002AF428(s->f54) == 0) {
                    s->f0E = -1;
                }
                func_003D3D20_4F10(i);
            }
        }
    }
    while (!isB && func_003D1E80_4F10() != 0) {
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5128);
#ifdef SKIP_ASM
extern unsigned int func_002AF370_5128(void) __asm__("func_002AF370");
extern void func_002AEFA8_5128(int) __asm__("func_002AEFA8");
extern void func_003D4B00_5128(void) __asm__("func_003D4B00");
extern void func_003D4F10_5128(void) __asm__("func_003D4F10");

/* same body as func_003D5450 (also inlined in func_003D4BB0) */
static inline int sel_5128(unsigned int idx) {
    if (D_0044F430 == 0)
        D_0044F430 = 0xFFFFFFFF;
    if (idx < 4 && D_00517610[idx].f34 != 0) {
        int v = D_00517610[idx].f30;
        D_0044F420 = &D_00517610[idx];
        D_0044F430 = v;
        return v;
    }
    if ((int)idx != -1)
        D_0044F430 = 0;
    return D_0044F430;
}

void func_003D5128_impl(unsigned char arg) __asm__("func_003D5128");
void func_003D5128_impl(unsigned char arg) {
    unsigned char i;
    if (D_0044F42D != 0) return;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    D_0044F430 = 0xFFFFFFFF;
    D_0044F434 = arg;
    D_0044F438 = func_002AF370_5128();
    func_002AEFA8_5128(0);
    i = 0;
    do {
        if (D_00517610[i].f34 != 0) {
            if (sel_5128(i) != 0) {
                func_003D4B00_5128();
                func_003D4F10_5128();
            }
        }
        i++;
    } while (i < 4);
    func_002AEFA8_5128(1);
    D_0044F430 = 0;
    D_0044F420 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5290);
#ifdef SKIP_ASM
struct E_5290 { char pad[0x30]; unsigned mask; int w34; char pad2[0x20]; int tab[24]; char pad3[0x928 - 0xB8]; };
extern struct E_5290 D_00517610_5290[] __asm__("D_00517610");

int func_003D5290(unsigned arg0) {
    unsigned i, b;
    unsigned hi = arg0 & 0xF0000000;
    unsigned mid = arg0 & 0x0F000000;
    unsigned m = arg0 & 0xFFFFFF;
    for (i = 0; i < 4; i++) {
        unsigned mk = D_00517610_5290[i].mask;
        if (D_00517610_5290[i].w34 != 0 &&
            (mk & hi) && (mk & mid)) {
            for (b = 0; b < 0x18; b++) {
                if ((m >> b) & 1)
                    return D_00517610_5290[i].tab[b];
            }
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5330);
#ifdef SKIP_ASM
struct E_5330 { unsigned int f0; int f4; char pad[0x20]; int w[24]; char pad2[0x928 - 0x28 - 24 * 4]; };
extern struct E_5330 D_00517640_5330[] __asm__("D_00517640");

int func_003D5330(unsigned int mask) {
    int n = 0;
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        if (mask & (0x1000000 << i)) {
            if (D_00517640_5330[i].f4 != 0) {
                for (j = 0; j < 24; j++) {
                    if (D_00517640_5330[i].w[j] != 0) {
                        n++;
                    }
                }
            }
        }
    }
    return n;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D53B8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_003D11B8_53B8(int, int *) __asm__("func_003D11B8");
extern int func_003D3030(int);

int func_003D53B8(int arg0, int arg1) {
    int sp0[12];
    int i;
    int t;

    for (i = 1; i >= 0; i--) {
        t = ((0x10000000 << i) | (0x01000000 << arg0)) + (1 << arg1);
        if (func_003D3030(t) >= 0) {
            func_003D11B8_53B8(t, sp0);
            if (sp0[0] >= 0) return t;
        }
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5450);
#ifdef SKIP_ASM

int func_003D5450(unsigned int idx) {
    if (D_0044F430 == 0)
        D_0044F430 = 0xFFFFFFFF;
    if (idx < 4 && D_00517610[idx].f34 != 0) {
        int v = D_00517610[idx].f30;
        D_0044F420 = &D_00517610[idx];
        D_0044F430 = v;
        return v;
    }
    if ((int)idx != -1)
        D_0044F430 = 0;
    return D_0044F430;
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D54C8);
#ifdef SKIP_ASM
extern void func_003D5128(int);

void func_003D54C8(void) {
    func_003D5128(0x20);
}
#endif

//100% - objdiff report; single-function view differs only in a relocation name
INCLUDE_ASM("ealib/seg_2B4578", func_003D54E8);
#ifdef SKIP_ASM
extern void func_003D5128(int);

void func_003D54E8(void) {
    func_003D5128(0x42);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5508);
#ifdef SKIP_ASM
extern int func_003D5450_5508(int) __asm__("func_003D5450");
extern void func_003D62C8_5508(struct sPathVoice *, int) __asm__("func_003D62C8");

static inline int isOff(unsigned int m, int b) { return ((m >> b) & 1) == 0; }
void func_003D5508(unsigned int mask, signed char val) {
    int i;
    int j;
    unsigned int fl, t, u;
    struct sPathVoice *e;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    if (func_003D5450_5508(-1) == 0) return;
    if (val > 100) val = 100;
    if (val < 0) val = 0;
    if (mask == 0xFFFFFFFF) {
        D_0044F42E = val;
    }
    for (i = 0; i < 4; i++) {
        if (*(int *)(D_00517644 + i * 0x928) != 0) {
            fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
            t = fl & 0xF0000000;
            if ((t & mask) != 0) {
                u = fl & 0x0F000000;
                if ((u & mask) != 0 && func_003D5450_5508(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        e = D_0044F420->f58[j];
                        if (e == 0 || isOff(mask, j)) continue;
                        func_003D62C8_5508(e, val);
                    }
                }
            }
        }
    }
    D_0044F420 = 0;
    D_0044F430 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5698);
#ifdef SKIP_ASM
extern int func_003D5450_5698(int) __asm__("func_003D5450");
extern void func_003D6318_5698(struct sPathVoice *, int, int, int) __asm__("func_003D6318");

static inline int isOff_5698(unsigned int m, int b) { return ((m >> b) & 1) == 0; }
void func_003D5698(unsigned int mask, int a1, int a2) {
    int i;
    int j;
    unsigned int fl, t, u;
    struct sPath *g;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    if (func_003D5450_5698(-1) == 0) return;
    for (i = 0; i < 4; i++) {
        if (*(int *)(D_00517644 + i * 0x928) != 0) {
            fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
            t = fl & 0xF0000000;
            if ((t & mask) != 0) {
                u = fl & 0x0F000000;
                if ((u & mask) != 0 && func_003D5450_5698(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        g = D_0044F420;
                        if (g->f58[j] == 0 || isOff_5698(mask, j)) continue;
                        func_003D6318_5698(g->f58[j], a1, a2, g->f14[0].mode);
                    }
                }
            }
        }
    }
    D_0044F420 = 0;
    D_0044F430 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5800);
#ifdef SKIP_ASM
extern int func_003D5450_5800(int) __asm__("func_003D5450");
extern void func_003D6360_5800(struct sPathVoice *, int, int, int) __asm__("func_003D6360");

static inline int isOff_5800(unsigned int m, int b) { return ((m >> b) & 1) == 0; }
void func_003D5800(unsigned int mask, int a1, int a2) {
    int i;
    int j;
    unsigned int fl, t, u;
    struct sPath *g;
    if (D_0044F42C == 0) return;
    if (D_0044F430 != 0) return;
    if (func_003D5450_5800(-1) == 0) return;
    for (i = 0; i < 4; i++) {
        if (*(int *)(D_00517644 + i * 0x928) != 0) {
            fl = *(unsigned int *)(D_00517644 + i * 0x928 - 4);
            t = fl & 0xF0000000;
            if ((t & mask) != 0) {
                u = fl & 0x0F000000;
                if ((u & mask) != 0 && func_003D5450_5800(i) != 0) {
                    for (j = 0; j < 24; j++) {
                        g = D_0044F420;
                        if (g->f58[j] == 0 || isOff_5800(mask, j)) continue;
                        func_003D6360_5800(g->f58[j], a1, a2, g->f14[0].mode);
                    }
                }
            }
        }
    }
    D_0044F420 = 0;
    D_0044F430 = 0;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5968);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AF6C0(int, int);
extern int func_002AF838(int);

void func_003D5968(unsigned int mask) {
    int i;
    for (i = 0; i < 0x18; i++) {
        struct sPathVoice *o = D_0044F420->f58[i];
        if (o != 0 && !(((mask >> i) ^ 1) & 1) && o->f36 >= 0) {
            int t18 = o->f34 * o->f04 / 100;
            signed char b = o->f0E;
            if (b >= 0) {
                int t16 = b * o->f04 / 100;
                if (t16 == func_002AF428(o->f54)) {
                    if (o->f0E == 0) {
                        func_002AF838(o->f54);
                        o->f36 = -1;
                    } else {
                        goto b8;
                    }
                    goto b10;
                }
            } else {
b8:
                if (t18 >= 0) {
                    func_002AF6C0(o->f54, t18);
                }
b10:
                o->f0E = -1;
            }
        }
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5A98);
#ifdef SKIP_ASM
extern int func_002AF6C0(int, int);

void func_003D5A98_impl(struct sPathVoice *v) __asm__("func_003D5A98");
void func_003D5A98_impl(struct sPathVoice *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->f0E - (float)v->f0C;
    l.dur = D_0044F420->f14[0].dur;
    l.mode = D_0044F420->f14[0].mode;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438 - v->f08) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF6C0(v->f54, v->f34);
        none = -1;
        v->f0C = none;
        sel = none;
        v->f0D = v->f0E = sel;
        v->f08 = 0;
        v->f34 = sel;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->f0C;
    if (v->f0E < v->f0C) {
        m = v->f0E;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF6C0(v->f54, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5CC0);
#ifdef SKIP_ASM
extern int func_002AF4E0(int, int, int);

void func_003D5CC0_impl(struct sPathVoice *v) __asm__("func_003D5CC0");
void func_003D5CC0_impl(struct sPathVoice *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->f16 - (float)v->f14;
    l.dur = D_0044F420->f14[1].dur;
    l.mode = D_0044F420->f14[1].mode;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438 - v->f10) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF4E0(v->f54, 0, v->f16);
        none = -1;
        v->f14 = none;
        v->f15 = v->f16 = none;
        v->f10 = 0;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->f14;
    if (v->f16 < v->f14) {
        m = v->f16;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF4E0(v->f54, 0, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D5EE8);
#ifdef SKIP_ASM
extern int func_002AF580(int, int);

void func_003D5EE8_impl(struct sPathVoice *v) __asm__("func_003D5EE8");
void func_003D5EE8_impl(struct sPathVoice *v) {
    struct {
        unsigned mode : 7;
        int neg : 1;
        unsigned mid : 8;
        unsigned dur : 16;
    } l;
    float r = -1.0f;
    float diff;
    float t;
    float m;
    int pos;
    int none;
    unsigned sel;
    diff = (float)v->f1E - (float)v->f1C;
    l.dur = D_0044F420->f14[2].dur;
    l.mode = D_0044F420->f14[2].mode;
    pos = 1;
    if (diff < 0.0f) {
        pos = 0;
    }
    l.neg = pos;
    t = (float)(unsigned)(D_0044F438 - v->f18) / (float)l.dur;
    if (t >= 1.0f) {
        func_002AF580(v->f54, v->f1E);
        none = -1;
        v->f1C = none;
        v->f1D = v->f1E = none;
        v->f18 = 0;
        return;
    }
    if (l.neg) {
        t = 1.0f - t;
    }
    sel = l.mode;
    switch (sel) {
    case 1:
        r = 1.0f - t;
        break;
    case 2:
        r = 1.0f - t * t;
        break;
    case 3:
        r = 1.0f / t / 25.0f;
        break;
    }
    m = v->f1C;
    if (v->f1E < v->f1C) {
        m = v->f1E;
    }
    if (diff < 0.0f) {
        diff = -diff;
    }
    if (r >= 0.0f && r <= 1.0f) {
        r = m + diff * r;
        func_002AF580(v->f54, (int)r);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6108);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f5450_6108(int) __asm__("func_003D5450");

void func_003D6108(int a0, int a1) {
    int i;
    if (D_0044F42C != 0 && D_0044F430 == 0 && f5450_6108(-1) != 0) {
        a0 &= 0x0F000000;
        for (i = 0; i < 4; i++) {
            if (D_00517610[i].f34 != 0 && (D_00517610[i].f30 & a0) && f5450_6108(i & 0xFF) != 0) {
                D_0044F420->f14[0].dur = a1;
            }
        }
        D_0044F430 = 0;
        D_0044F420 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D61E8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int f5450_61E8(int) __asm__("func_003D5450");

void func_003D61E8(int a0, int a1) {
    int i;
    if (D_0044F42C != 0 && D_0044F430 == 0 && f5450_61E8(-1) != 0) {
        a0 &= 0x0F000000;
        for (i = 0; i < 4; i++) {
            if (D_00517610[i].f34 != 0 && (D_00517610[i].f30 & a0) && f5450_61E8(i & 0xFF) != 0) {
                D_0044F420->f14[0].mode = a1;
            }
        }
        D_0044F430 = 0;
        D_0044F420 = 0;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D62C8);
#ifdef SKIP_ASM
extern int func_002AF6C0(int, int);

void func_003D62C8(void *arg0, signed char arg1) {
    (*(signed char *)((char*)(arg0) + (4))) = arg1;
    if ((*(signed char *)((char*)(arg0) + (0xE))) < 0) {
        func_002AF6C0((*(int *)((char*)(arg0) + (0x54))), (int) ((*(signed char *)((char*)(arg0) + (0x34))) * arg1) / 100);
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6318);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern int func_002AF608(int, int, int, char);

void func_003D6318(char *self, int v, int w) {
    int x;
    self[0xE] = v;
    x = (v * self[4]) / 100;
    self[0xD] = 0;
    func_002AF608(*(int *)(self + 0x54), x, w, 1);
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6360);
#ifdef SKIP_ASM
void func_003D6360(void *arg0, int arg1, int arg2, int arg3) {
    *(signed char *)((char *)arg0 + 0x16) = arg1;
    if (arg3 >= 0) {
        *(signed char *)((char *)arg0 + 0x15) = arg3;
    }
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6378);
#ifdef SKIP_ASM
extern int func_002AF428(int);

void func_003D6378(char *self, int a, int b) {
    int t;
    int q, d;
    *(int *)(self + 8) = D_0044F438;
    self[0xD] = b;
    t = func_002AF428(*(int *)(self + 0x54));
    self[0xC] = (int)(float)t;
    self[0xE] = a;
    self[0x34] = (int)(float)a;
    d = 0x7F;
    q = a / d;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D63F8);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern signed char f_63F8_cb(int) __asm__("func_002AF4B0");

void func_003D63F8(char *self, int a, int b) {
    signed char t;
    *(int *)(self + 0x10) = D_0044F438;
    self[0x15] = b;
    t = f_63F8_cb(*(int *)(self + 0x54));
    self[0x16] = a;
    self[0x14] = t;
}
#endif

//100%
INCLUDE_ASM("ealib/seg_2B4578", func_003D6448);
#ifdef SKIP_ASM
// PORT: PS2-only inline asm; needs a C fallback off-PS2.
extern signed char f_6448_cb(int) __asm__("func_002AF480");

void func_003D6448(char *self, int a, int b) {
    signed char t;
    *(int *)(self + 0x18) = D_0044F438;
    self[0x1D] = b;
    t = f_6448_cb(*(int *)(self + 0x54));
    self[0x1E] = a;
    self[0x1C] = t;
}
#endif
