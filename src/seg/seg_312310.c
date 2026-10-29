#include "common.h"

//100%
INCLUDE_ASM("seg/seg_312310", func_00411310);
#ifdef SKIP_ASM
extern void func_0040FB88(int);
extern void func_00416FE0(void);
extern void func_001001C8(int);
void func_00411310(int a) {
    func_0040FB88(a);
    func_00416FE0();
    func_001001C8(a);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411340);
#ifdef SKIP_ASM
extern double a_411340(double) __asm__("func_00413AF8");
extern int cmp_411340(double, double) __asm__("func_00412500");
extern double mul_411340(double, double) __asm__("func_00411FD8");
extern unsigned dtou_411340(double) __asm__("func_004126A0");
extern double ltod_411340(long) __asm__("func_00411438");
extern double add_411340(double, double) __asm__("func_00411F18");
extern double sub_411340(double, double) __asm__("func_00411F70");
unsigned long func_00411340(double a) {
    unsigned long hi;
    double v;
    double d;
    v = a_411340(a);
    if (cmp_411340(v, 0.0) < 0)
        return 0;
    hi = (unsigned long)dtou_411340(mul_411340(v, 2.3283064365386963e-10)) << 32;
    if ((long)hi >= 0) {
        d = ltod_411340(hi);
    } else {
        d = ltod_411340((hi & 1) | (hi >> 1));
        d = add_411340(d, d);
    }
    v = sub_411340(v, d);
    if (cmp_411340(v, 0.0) < 0)
        hi -= (unsigned long)dtou_411340(sub_411340(0.0, v));
    else
        hi += (unsigned long)dtou_411340(v);
    return hi;
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411438);
#ifdef SKIP_ASM
extern double itod_411438(int) __asm__("func_00412550");
extern double dmul_411438(double, double) __asm__("func_00411FD8");
extern double dadd_411438(double, double) __asm__("func_00411F18");
double func_00411438(long a) {
    double hi = itod_411438((int)(a >> 32));
    double lo;
    hi = dmul_411438(hi, 65536.0);
    hi = dmul_411438(hi, 65536.0);
    lo = itod_411438((int)(a & 0xFFFFFFFF));
    if ((int)(a & 0xFFFFFFFF) < 0)
        lo = dadd_411438(lo, 4294967296.0);
    return dadd_411438(hi, lo);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_004114D0);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004114D0\n.type func_004114D0, @function\nfunc_004114D0:\n"
    "dsra32 $6, $4, 0\n"
    "dsra32 $3, $5, 0\n"
    "dsll32 $4, $4, 0\n"
    "dsra32 $4, $4, 0\n"
    "dsll32 $5, $5, 0\n"
    "dsra32 $5, $5, 0\n"
    "mult $3, $4, $3\n"
    "mult1 $6, $6, $5\n"
    "multu $4, $5\n"
    "mflo $4\n"
    "mfhi $2\n"
    "dsll32 $4, $4, 0\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $4, $4, 0\n"
    "addu $3, $3, $6\n"
    "or $4, $4, $2\n"
    "lui $5, (0xFFFF0000 >> 16)\n"
    "dsrl32 $5, $5, 0\n"
    "dsra32 $2, $4, 0\n"
    "addu $2, $2, $3\n"
    "and $4, $4, $5\n"
    "dsll32 $2, $2, 0\n"
    "jr $31\n"
    "or $2, $4, $2\n"
    ".size func_004114D0, . - func_004114D0\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411530);
#ifdef SKIP_ASM
extern void func_004103B0(void);
void func_00411530(void) {
    func_004103B0();
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411538);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00411538\n.type func_00411538, @function\nfunc_00411538:\n"
    "dsra32 $8, $5, 0\n"
    "dsra32 $11, $4, 0\n"
    "dsll32 $9, $5, 0\n"
    "dsra32 $9, $9, 0\n"
    "dsll32 $12, $4, 0\n"
    "dsra32 $12, $12, 0\n"
    "bnez $8, 27f\n"
    "addiu $29, $29, -0x10\n"
    "sltu $2, $11, $9\n"
    "beqz $2, 9f\n"
    "ori $2, $0, 0xFFFF\n"
    "sltu $2, $2, $9\n"
    "bnez $2, 1f\n"
    "lui $2, (0xFFFFFF >> 16)\n"
    "sltiu $2, $9, 0x100\n"
    "addiu $5, $0, 0x8\n"
    "b 2f\n"
    "movn $5, $0, $2\n"
    "1:\n"
    "addiu $5, $0, 0x18\n"
    "ori $2, $2, (0xFFFFFF & 0xFFFF)\n"
    "addiu $3, $0, 0x10\n"
    "sltu $2, $2, $9\n"
    "movz $5, $3, $2\n"
    "nop\n"
    "2:\n"
    "lui $2, %hi(D_004997A0)\n"
    "srlv $4, $9, $5\n"
    "addiu $2, $2, %lo(D_004997A0)\n"
    "addiu $7, $0, 0x20\n"
    "addu $4, $4, $2\n"
    "lbu $3, 0x0($4)\n"
    "addu $3, $3, $5\n"
    "subu $6, $7, $3\n"
    "beqz $6, 3f\n"
    "subu $2, $7, $6\n"
    "sllv $3, $11, $6\n"
    "srlv $2, $12, $2\n"
    "sllv $9, $9, $6\n"
    "or $11, $3, $2\n"
    "sllv $12, $12, $6\n"
    "3:\n"
    "srl $5, $9, 16\n"
    "andi $8, $9, 0xFFFF\n"
    "divu $0, $11, $5\n"
    "srl $4, $12, 16\n"
    "beql $5, $0, 4f\n"
    "break 0, 7\n"
    "4:\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $7, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $7, $8\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 6f\n"
    "subu $3, $3, $6\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 5f\n"
    "addiu $7, $7, -0x1\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 6f\n"
    "subu $3, $3, $6\n"
    "addiu $7, $7, -0x1\n"
    "addu $3, $3, $9\n"
    "nop\n"
    "5:\n"
    "subu $3, $3, $6\n"
    "6:\n"
    "beql $5, $0, 7f\n"
    "break 0, 7\n"
    "7:\n"
    "divu $0, $3, $5\n"
    "andi $4, $12, 0xFFFF\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $5, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $5, $8\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beqz $2, 8f\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 8f\n"
    "addiu $5, $5, -0x1\n"
    "sltu $2, $3, $6\n"
    "bnel $2, $0, 8f\n"
    "addiu $5, $5, -0x1\n"
    "8:\n"
    "dsll32 $2, $7, 0\n"
    "dsll $2, $2, 16\n"
    "dsra32 $2, $2, 0\n"
    "b 38f\n"
    "or $5, $2, $5\n"
    "9:\n"
    "bnez $9, 11f\n"
    "sltu $2, $2, $9\n"
    "addiu $2, $0, 0x1\n"
    "beql $9, $0, 10f\n"
    "break 0, 7\n"
    "10:\n"
    "divu $0, $2, $8\n"
    "mflo $2\n"
    "daddu $9, $2, $0\n"
    "ori $2, $0, 0xFFFF\n"
    "sltu $2, $2, $9\n"
    "nop\n"
    "11:\n"
    "bnez $2, 12f\n"
    "lui $2, (0xFFFFFF >> 16)\n"
    "sltiu $2, $9, 0x100\n"
    "addiu $5, $0, 0x8\n"
    "b 13f\n"
    "movn $5, $0, $2\n"
    "12:\n"
    "addiu $5, $0, 0x18\n"
    "ori $2, $2, (0xFFFFFF & 0xFFFF)\n"
    "addiu $3, $0, 0x10\n"
    "sltu $2, $2, $9\n"
    "movz $5, $3, $2\n"
    "nop\n"
    "13:\n"
    "lui $2, %hi(D_004997A0)\n"
    "srlv $4, $9, $5\n"
    "addiu $2, $2, %lo(D_004997A0)\n"
    "addiu $7, $0, 0x20\n"
    "addu $4, $4, $2\n"
    "lbu $3, 0x0($4)\n"
    "addu $3, $3, $5\n"
    "subu $6, $7, $3\n"
    "bnez $6, 14f\n"
    "subu $7, $7, $6\n"
    "subu $11, $11, $9\n"
    "addiu $13, $0, 0x1\n"
    "srl $8, $9, 16\n"
    "b 21f\n"
    "andi $10, $9, 0xFFFF\n"
    "14:\n"
    "sllv $3, $11, $6\n"
    "srlv $2, $12, $7\n"
    "sllv $9, $9, $6\n"
    "srlv $7, $11, $7\n"
    "sllv $12, $12, $6\n"
    "or $11, $3, $2\n"
    "srl $8, $9, 16\n"
    "divu $0, $7, $8\n"
    "andi $10, $9, 0xFFFF\n"
    "daddu $5, $8, $0\n"
    "srl $4, $11, 16\n"
    "beql $5, $0, 15f\n"
    "break 0, 7\n"
    "15:\n"
    "daddu $13, $10, $0\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $7, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $7, $10\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 17f\n"
    "subu $3, $3, $6\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 16f\n"
    "addiu $7, $7, -0x1\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 17f\n"
    "subu $3, $3, $6\n"
    "addiu $7, $7, -0x1\n"
    "addu $3, $3, $9\n"
    "nop\n"
    "16:\n"
    "subu $3, $3, $6\n"
    "17:\n"
    "beql $5, $0, 18f\n"
    "break 0, 7\n"
    "18:\n"
    "divu $0, $3, $5\n"
    "andi $4, $11, 0xFFFF\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $5, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $5, $13\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beqz $2, 20f\n"
    "dsll32 $2, $7, 0\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 19f\n"
    "addiu $5, $5, -0x1\n"
    "sltu $2, $3, $6\n"
    "beqz $2, 20f\n"
    "dsll32 $2, $7, 0\n"
    "addiu $5, $5, -0x1\n"
    "addu $3, $3, $9\n"
    "19:\n"
    "dsll32 $2, $7, 0\n"
    "20:\n"
    "subu $11, $3, $6\n"
    "dsll $2, $2, 16\n"
    "dsra32 $2, $2, 0\n"
    "or $13, $2, $5\n"
    "21:\n"
    "daddu $5, $8, $0\n"
    "srl $4, $12, 16\n"
    "divu $0, $11, $5\n"
    "daddu $8, $10, $0\n"
    "beql $5, $0, 22f\n"
    "break 0, 7\n"
    "22:\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $7, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $7, $8\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 24f\n"
    "subu $3, $3, $6\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 23f\n"
    "addiu $7, $7, -0x1\n"
    "sltu $2, $3, $6\n"
    "beql $2, $0, 24f\n"
    "subu $3, $3, $6\n"
    "addiu $7, $7, -0x1\n"
    "addu $3, $3, $9\n"
    "23:\n"
    "subu $3, $3, $6\n"
    "24:\n"
    "beql $5, $0, 25f\n"
    "break 0, 7\n"
    "25:\n"
    "divu $0, $3, $5\n"
    "andi $4, $12, 0xFFFF\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $5, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $6, $5, $8\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $6\n"
    "beqz $2, 26f\n"
    "addu $3, $3, $9\n"
    "sltu $2, $3, $9\n"
    "bnez $2, 26f\n"
    "addiu $5, $5, -0x1\n"
    "sltu $2, $3, $6\n"
    "bnel $2, $0, 26f\n"
    "addiu $5, $5, -0x1\n"
    "26:\n"
    "dsll32 $2, $7, 0\n"
    "dsll $2, $2, 16\n"
    "dsra32 $2, $2, 0\n"
    "b 39f\n"
    "or $5, $2, $5\n"
    "27:\n"
    "sltu $2, $11, $8\n"
    "beqz $2, 28f\n"
    "ori $2, $0, 0xFFFF\n"
    "b 38f\n"
    "daddu $5, $0, $0\n"
    "28:\n"
    "sltu $2, $2, $8\n"
    "bnez $2, 29f\n"
    "lui $2, (0xFFFFFF >> 16)\n"
    "sltiu $2, $8, 0x100\n"
    "addiu $5, $0, 0x8\n"
    "b 30f\n"
    "movn $5, $0, $2\n"
    "nop\n"
    "29:\n"
    "addiu $5, $0, 0x18\n"
    "ori $2, $2, (0xFFFFFF & 0xFFFF)\n"
    "addiu $3, $0, 0x10\n"
    "sltu $2, $2, $8\n"
    "movz $5, $3, $2\n"
    "nop\n"
    "30:\n"
    "lui $2, %hi(D_004997A0)\n"
    "srlv $4, $8, $5\n"
    "addiu $2, $2, %lo(D_004997A0)\n"
    "addiu $7, $0, 0x20\n"
    "addu $4, $4, $2\n"
    "lbu $3, 0x0($4)\n"
    "addu $3, $3, $5\n"
    "subu $6, $7, $3\n"
    "bnel $6, $0, 31f\n"
    "subu $7, $7, $6\n"
    "sltu $2, $8, $11\n"
    "bnez $2, 38f\n"
    "addiu $5, $0, 0x1\n"
    "sltu $2, $12, $9\n"
    "bnez $2, 38f\n"
    "daddu $5, $0, $0\n"
    "b 38f\n"
    "addiu $5, $0, 0x1\n"
    "31:\n"
    "sllv $5, $8, $6\n"
    "srlv $4, $12, $7\n"
    "srlv $3, $9, $7\n"
    "srlv $7, $11, $7\n"
    "sllv $2, $11, $6\n"
    "or $11, $2, $4\n"
    "or $8, $5, $3\n"
    "sllv $12, $12, $6\n"
    "sllv $9, $9, $6\n"
    "srl $6, $8, 16\n"
    "divu $0, $7, $6\n"
    "andi $5, $8, 0xFFFF\n"
    "srl $4, $11, 16\n"
    "beql $6, $0, 32f\n"
    "break 0, 7\n"
    "32:\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $10, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $7, $10, $5\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $7\n"
    "beql $2, $0, 34f\n"
    "subu $3, $3, $7\n"
    "addu $3, $3, $8\n"
    "sltu $2, $3, $8\n"
    "bnez $2, 33f\n"
    "addiu $10, $10, -0x1\n"
    "sltu $2, $3, $7\n"
    "beql $2, $0, 34f\n"
    "subu $3, $3, $7\n"
    "addiu $10, $10, -0x1\n"
    "addu $3, $3, $8\n"
    "nop\n"
    "33:\n"
    "subu $3, $3, $7\n"
    "34:\n"
    "beql $6, $0, 35f\n"
    "break 0, 7\n"
    "35:\n"
    "divu $0, $3, $6\n"
    "andi $4, $11, 0xFFFF\n"
    "mflo $2\n"
    "mfhi $3\n"
    "daddu $6, $2, $0\n"
    "dsll32 $3, $3, 0\n"
    "dsll $3, $3, 16\n"
    "dsra32 $3, $3, 0\n"
    "mult $7, $6, $5\n"
    "or $3, $3, $4\n"
    "sltu $2, $3, $7\n"
    "beqz $2, 37f\n"
    "dsll32 $2, $10, 0\n"
    "addu $3, $3, $8\n"
    "sltu $2, $3, $8\n"
    "bnez $2, 36f\n"
    "addiu $6, $6, -0x1\n"
    "sltu $2, $3, $7\n"
    "beqz $2, 37f\n"
    "dsll32 $2, $10, 0\n"
    "addu $3, $3, $8\n"
    "addiu $6, $6, -0x1\n"
    "36:\n"
    "dsll32 $2, $10, 0\n"
    "37:\n"
    "subu $3, $3, $7\n"
    "dsll $2, $2, 16\n"
    "dsra32 $2, $2, 0\n"
    "or $5, $2, $6\n"
    "multu $5, $9\n"
    "mfhi $6\n"
    "mflo $4\n"
    "sltu $2, $3, $6\n"
    "bnel $2, $0, 38f\n"
    "addiu $5, $5, -0x1\n"
    "bne $6, $3, 39f\n"
    "daddu $13, $0, $0\n"
    "sltu $2, $12, $4\n"
    "beqz $2, 40f\n"
    "dsll32 $3, $5, 0\n"
    "addiu $5, $5, -0x1\n"
    "38:\n"
    "daddu $13, $0, $0\n"
    "nop\n"
    "39:\n"
    "dsll32 $3, $5, 0\n"
    "40:\n"
    "dsll32 $2, $13, 0\n"
    "dsrl32 $14, $3, 0\n"
    "or $2, $14, $2\n"
    "jr $31\n"
    "addiu $29, $29, 0x10\n"
    ".size func_00411538, . - func_00411538\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411B08);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00411B08\n.type func_00411B08, @function\nfunc_00411B08:\n"
    "lw $3, 0x0($4)\n"
    "daddu $7, $0, $0\n"
    "lw $8, 0x4($4)\n"
    "sltiu $2, $3, 0x2\n"
    "beqz $2, 1f\n"
    "ld $5, 0x10($4)\n"
    "ori $2, $0, 0x8000\n"
    "dsll32 $2, $2, 4\n"
    "addiu $7, $0, 0x7FF\n"
    "b 8f\n"
    "or $5, $5, $2\n"
    "1:\n"
    "xori $2, $3, 0x4\n"
    "beql $2, $0, 4f\n"
    "addiu $7, $0, 0x7FF\n"
    "xori $2, $3, 0x2\n"
    "bnez $2, 2f\n"
    "nop\n"
    "b 8f\n"
    "daddu $5, $0, $0\n"
    "2:\n"
    "beqz $5, 8f\n"
    "nop\n"
    "lw $3, 0x8($4)\n"
    "slti $2, $3, -0x3FE\n"
    "beqz $2, 3f\n"
    "addiu $2, $0, -0x3FE\n"
    "subu $2, $2, $3\n"
    "slti $3, $2, 0x39\n"
    "bnez $3, 7f\n"
    "dsrlv $5, $5, $2\n"
    "b 7f\n"
    "daddu $5, $0, $0\n"
    "3:\n"
    "slti $2, $3, 0x400\n"
    "bnez $2, 5f\n"
    "addiu $7, $3, 0x3FF\n"
    "addiu $7, $0, 0x7FF\n"
    "4:\n"
    "b 8f\n"
    "daddu $5, $0, $0\n"
    "5:\n"
    "addiu $2, $0, 0x80\n"
    "andi $3, $5, 0xFF\n"
    "bnel $3, $2, 6f\n"
    "daddiu $5, $5, 0x7F\n"
    "andi $3, $5, 0x100\n"
    "daddiu $2, $5, 0x80\n"
    "movn $5, $2, $3\n"
    "6:\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 3\n"
    "sltu $2, $2, $5\n"
    "beql $2, $0, 8f\n"
    "dsrl $5, $5, 8\n"
    "dsrl $5, $5, 1\n"
    "addiu $7, $7, 0x1\n"
    "7:\n"
    "dsrl $5, $5, 8\n"
    "8:\n"
    "ori $3, $0, 0xFFF0\n"
    "dsll32 $3, $3, 16\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $5, $2\n"
    "and $6, $6, $3\n"
    "or $6, $6, $2\n"
    "andi $3, $7, 0x7FF\n"
    "lui $2, (0x800FFFFF >> 16)\n"
    "ori $2, $2, (0x800FFFFF & 0xFFFF)\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll32 $3, $3, 20\n"
    "and $6, $6, $2\n"
    "addiu $4, $0, -0x1\n"
    "dsrl $4, $4, 1\n"
    "or $6, $6, $3\n"
    "dsll32 $2, $8, 31\n"
    "and $6, $6, $4\n"
    "jr $31\n"
    "or $2, $6, $2\n"
    ".size func_00411B08, . - func_00411B08\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411C38);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00411C38\n.type func_00411C38, @function\nfunc_00411C38:\n"
    "ld $2, 0x0($4)\n"
    "addiu $3, $0, -0x1\n"
    "dsrl $3, $3, 12\n"
    "dsrl32 $4, $2, 31\n"
    "and $3, $2, $3\n"
    "dsrl32 $2, $2, 20\n"
    "sw $4, 0x4($5)\n"
    "andi $4, $2, 0x7FF\n"
    "bnez $4, 1f\n"
    "addiu $2, $0, 0x7FF\n"
    "addiu $2, $0, 0x2\n"
    "jr $31\n"
    "sw $2, 0x0($5)\n"
    "nop\n"
    "1:\n"
    "bnel $4, $2, 5f\n"
    "dsll $3, $3, 8\n"
    "bnez $3, 2f\n"
    "addiu $2, $0, 0x4\n"
    "jr $31\n"
    "sw $2, 0x0($5)\n"
    "2:\n"
    "ori $2, $0, 0x8000\n"
    "dsll32 $2, $2, 4\n"
    "and $2, $3, $2\n"
    "beqz $2, 3f\n"
    "addiu $2, $0, 0x1\n"
    "b 4f\n"
    "sw $2, 0x0($5)\n"
    "3:\n"
    "sw $0, 0x0($5)\n"
    "4:\n"
    "jr $31\n"
    "sd $3, 0x10($5)\n"
    "5:\n"
    "ori $2, $0, 0x8000\n"
    "dsll32 $2, $2, 13\n"
    "or $3, $3, $2\n"
    "addiu $4, $4, -0x3FF\n"
    "addiu $2, $0, 0x3\n"
    "sd $3, 0x10($5)\n"
    "sw $4, 0x8($5)\n"
    "jr $31\n"
    "sw $2, 0x0($5)\n"
    ".size func_00411C38, . - func_00411C38\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411CD8);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00411CD8\n.type func_00411CD8, @function\nfunc_00411CD8:\n"
    "daddu $8, $4, $0\n"
    "lw $4, 0x0($8)\n"
    "sltiu $2, $4, 0x2\n"
    "beql $2, $0, 2f\n"
    "lw $3, 0x0($5)\n"
    "1:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    "2:\n"
    "sltiu $2, $3, 0x2\n"
    "beqz $2, 4f\n"
    "xori $2, $4, 0x4\n"
    "3:\n"
    "jr $31\n"
    "daddu $2, $5, $0\n"
    "4:\n"
    "bnez $2, 5f\n"
    "xori $2, $3, 0x4\n"
    "bnez $2, 1b\n"
    "nop\n"
    "lw $3, 0x4($5)\n"
    "lw $2, 0x4($8)\n"
    "beq $2, $3, 1b\n"
    "lui $2, %hi(D_0052ADC0)\n"
    "jr $31\n"
    "addiu $2, $2, %lo(D_0052ADC0)\n"
    "5:\n"
    "beqz $2, 3b\n"
    "xori $2, $3, 0x2\n"
    "bnez $2, 6f\n"
    "xori $2, $4, 0x2\n"
    "bnez $2, 1b\n"
    "daddu $2, $6, $0\n"
    "ld $4, 0x0($8)\n"
    "sd $4, 0x0($6)\n"
    "ld $3, 0x8($8)\n"
    "sd $3, 0x8($6)\n"
    "ld $4, 0x10($8)\n"
    "sd $4, 0x10($6)\n"
    "lw $3, 0x4($8)\n"
    "lw $4, 0x4($5)\n"
    "and $3, $3, $4\n"
    "jr $31\n"
    "sw $3, 0x4($6)\n"
    "6:\n"
    "beqz $2, 3b\n"
    "addiu $2, $0, -0x1\n"
    "lw $7, 0x8($8)\n"
    "lw $9, 0x8($5)\n"
    "ld $11, 0x10($8)\n"
    "subu $3, $7, $9\n"
    "slt $2, $2, $3\n"
    "negu $4, $3\n"
    "movz $3, $4, $2\n"
    "slti $3, $3, 0x40\n"
    "beqz $3, 11f\n"
    "ld $10, 0x10($5)\n"
    "slt $2, $9, $7\n"
    "beqz $2, 8f\n"
    "lw $8, 0x4($8)\n"
    "lw $5, 0x4($5)\n"
    "nop\n"
    "7:\n"
    "dsrl $2, $10, 1\n"
    "addiu $9, $9, 0x1\n"
    "andi $3, $10, 0x1\n"
    "slt $4, $9, $7\n"
    "or $10, $3, $2\n"
    "bnez $4, 7b\n"
    "nop\n"
    "b 9f\n"
    "slt $2, $7, $9\n"
    "8:\n"
    "lw $5, 0x4($5)\n"
    "slt $2, $7, $9\n"
    "9:\n"
    "beqz $2, 13f\n"
    "nop\n"
    "subu $7, $9, $7\n"
    "10:\n"
    "dsrl $3, $11, 1\n"
    "andi $2, $11, 0x1\n"
    "or $11, $2, $3\n"
    "addiu $7, $7, -0x1\n"
    "nop\n"
    "bnez $7, 10b\n"
    "nop\n"
    "b 13f\n"
    "daddu $7, $9, $0\n"
    "11:\n"
    "slt $2, $9, $7\n"
    "beqz $2, 12f\n"
    "lw $8, 0x4($8)\n"
    "daddu $10, $0, $0\n"
    "b 13f\n"
    "lw $5, 0x4($5)\n"
    "12:\n"
    "daddu $7, $9, $0\n"
    "lw $5, 0x4($5)\n"
    "daddu $11, $0, $0\n"
    "13:\n"
    "beq $8, $5, 18f\n"
    "daddu $2, $11, $10\n"
    "bnez $8, 14f\n"
    "dsubu $2, $10, $11\n"
    "dsubu $2, $11, $10\n"
    "14:\n"
    "bltz $2, 15f\n"
    "dsubu $3, $0, $2\n"
    "sw $7, 0x8($6)\n"
    "sd $2, 0x10($6)\n"
    "b 16f\n"
    "sw $0, 0x4($6)\n"
    "15:\n"
    "sw $7, 0x8($6)\n"
    "addiu $2, $0, 0x1\n"
    "sd $3, 0x10($6)\n"
    "sw $2, 0x4($6)\n"
    "16:\n"
    "ld $5, 0x10($6)\n"
    "addiu $2, $0, -0x1\n"
    "dsll $2, $2, 5\n"
    "dsrl $2, $2, 4\n"
    "daddiu $3, $5, -0x1\n"
    "sltu $2, $2, $3\n"
    "bnez $2, 19f\n"
    "daddu $7, $5, $0\n"
    "addiu $5, $0, -0x1\n"
    "dsll $5, $5, 5\n"
    "dsrl $5, $5, 4\n"
    "17:\n"
    "lw $2, 0x8($6)\n"
    "dsll $4, $7, 1\n"
    "daddiu $3, $4, -0x1\n"
    "sd $4, 0x10($6)\n"
    "addiu $2, $2, -0x1\n"
    "sltu $3, $5, $3\n"
    "sw $2, 0x8($6)\n"
    "beqz $3, 17b\n"
    "daddu $7, $4, $0\n"
    "b 19f\n"
    "daddu $5, $4, $0\n"
    "18:\n"
    "sw $8, 0x4($6)\n"
    "sw $7, 0x8($6)\n"
    "daddu $5, $2, $0\n"
    "sd $2, 0x10($6)\n"
    "19:\n"
    "addiu $3, $0, 0x3\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 3\n"
    "sltu $2, $2, $5\n"
    "beqz $2, 20f\n"
    "sw $3, 0x0($6)\n"
    "lw $2, 0x8($6)\n"
    "dsrl $4, $5, 1\n"
    "andi $3, $5, 0x1\n"
    "or $3, $3, $4\n"
    "addiu $2, $2, 0x1\n"
    "sd $3, 0x10($6)\n"
    "sw $2, 0x8($6)\n"
    "20:\n"
    "jr $31\n"
    "daddu $2, $6, $0\n"
    ".size func_00411CD8, . - func_00411CD8\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411F18);
#ifdef SKIP_ASM
struct S412778;
extern void func_00411C38(long *, int *);
extern struct S412778 *func_00411CD8(int *, int *, int *);
extern void func_00411B08(struct S412778 *);
void func_00411F18(long a, long b) {
    int x[8];
    int y[8];
    int z[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    func_00411B08(func_00411CD8(x, y, z));
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00411F70);
#ifdef SKIP_ASM
struct S412778;
extern void func_00411C38(long *, int *);
extern struct S412778 *func_00411CD8(int *, int *, int *);
extern void func_00411B08(struct S412778 *);
void func_00411F70(long a, long b) {
    int x[8];
    int y[8];
    int z[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    y[1] ^= 1;
    func_00411B08(func_00411CD8(x, y, z));
}
#endif

INCLUDE_ASM("seg/seg_312310", func_00411FD8);

//100%
INCLUDE_ASM("seg/seg_312310", func_00412280);
#ifdef SKIP_ASM
struct S412280 { unsigned cls; int sign; int exp; int pad; unsigned long frac; long pad2; };
extern void unp_80(long *, struct S412280 *) __asm__("func_00411C38");
extern void pk_80(struct S412280 *) __asm__("func_00411B08");
extern struct S412280 D_0052ADC0;
void func_00412280(long x, long y) {
    struct S412280 a;
    struct S412280 b;
    struct S412280 *r;
    struct S412280 *p;
    unsigned long n, d, q, bit;
    unp_80(&x, &a);
    unp_80(&y, &b);
    p = &a;
    if (a.cls < 2) {
        r = &a;
    } else if (b.cls < 2) {
        r = &b;
    } else {
        a.sign ^= b.sign;
        if ((a.cls ^ 4) == 0 || (a.cls ^ 2) == 0) {
            r = &a;
            if (a.cls == b.cls)
                r = &D_0052ADC0;
        } else if ((b.cls ^ 4) == 0) {
            a.frac = 0;
            a.exp = 0;
            r = &a;
        } else if ((b.cls ^ 2) == 0) {
            a.cls = 4;
            r = &a;
        } else {
            a.exp = a.exp - b.exp;
            n = a.frac;
            d = b.frac;
            if (n < d) {
                a.exp--;
                n <<= 1;
            }
            q = 0;
            for (bit = 0x1000000000000000UL; bit != 0; bit >>= 1) {
                if (n >= d) {
                    q |= bit;
                    n -= d;
                }
                n <<= 1;
            }
            if ((q & 0xFF) == 0x80) {
                if (q & 0x100)
                    q += 0x80;
                else if (n != 0)
                    q += 0x80;
            }
            p->frac = q;
            r = p;
        }
    }
    pk_80(r);
}
#endif

INCLUDE_ASM("seg/seg_312310", func_004123E8);

//100%
INCLUDE_ASM("seg/seg_312310", func_00412500);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
extern void func_004123E8(int *, int *);
void func_00412500(long a, long b) {
    int x[8];
    int y[8];
    func_00411C38(&a, x);
    func_00411C38(&b, y);
    func_004123E8(x, y);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412550);
#ifdef SKIP_ASM
struct S412550 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
extern void pk_412550(struct S412550 *) __asm__("func_00411B08");
double func_00412550(int x) {
    struct S412550 s;
    s.cls = 3;
    s.sign = (unsigned)x >> 31;
    if (x == 0) {
        s.cls = 2;
    } else {
        s.exp = 60;
        if (s.sign) {
            if (x == (-2147483647 - 1))
                return -2147483648.0;
            s.frac = -x;
        } else {
            s.frac = x;
        }
        while (s.frac <= (~0UL >> 4)) {
            s.frac <<= 1;
            s.exp--;
        }
    }
    pk_412550(&s);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412608);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
struct S412608 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
int func_00412608(long a) {
    struct S412608 s;
    int r;
    func_00411C38(&a, (int *)&s);
    if ((s.cls ^ 2) == 0)
        return 0;
    if (s.cls < 2)
        return 0;
    if ((s.cls ^ 4) == 0)
        goto sat;
    if (s.exp < 0)
        return 0;
    if (s.exp >= 31) {
sat:
        return s.sign ? 0x80000000 : 0x7FFFFFFF;
    }
    r = (int)(s.frac >> (60 - s.exp));
    return s.sign ? -r : r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_004126A0);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
struct S4126A0 { unsigned cls; int sign; int exp; int pad; unsigned long frac; };
unsigned func_004126A0(long a) {
    struct S4126A0 s;
    func_00411C38(&a, (int *)&s);
    if ((s.cls ^ 2) == 0)
        return 0;
    if (s.cls < 2)
        return 0;
    if (s.sign != 0)
        return 0;
    if ((s.cls ^ 4) == 0)
        goto sat;
    if (s.exp < 0)
        return 0;
    if (s.exp >= 32) {
sat:
        return 0xFFFFFFFF;
    }
    if (s.exp >= 61)
        return s.frac << (s.exp - 60);
    else
        return s.frac >> (60 - s.exp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412740);
#ifdef SKIP_ASM
extern void func_00411C38(long *, int *);
void func_00412740(long a) {
    int buf[8];
    func_00411C38(&a, buf);
    buf[1] = buf[1] == 0;
    func_00411B08((struct S412778 *)buf);
}
#endif

//100%
INCLUDE_ASM("seg/seg_312310", func_00412778);
#ifdef SKIP_ASM
struct S412778 { int a, b, c; long d; };
extern void func_00411B08(struct S412778 *);
void func_00412778(int a, int b, int c, long d) {
    struct S412778 s;
    s.a = a;
    s.b = b;
    s.c = c;
    s.d = d;
    func_00411B08(&s);
}
#endif

INCLUDE_ASM("seg/seg_312310", func_004127A8);
