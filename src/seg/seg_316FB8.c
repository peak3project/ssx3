#include "common.h"

// PORT: PS2 kernel syscall stub: the syscall number goes in $3. Defined under a second C name with an
// asm label because this file declares these symbols with their argument lists elsewhere.
#define SYSCALL_STUB(name, n) \
    void name##_syscall(void) __asm__(#name); \
    void name##_syscall(void) { register int v __asm__("$3") = (n); __asm__ volatile("syscall" : : "r"(v)); }

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00415FB8);
#ifdef SKIP_ASM
extern int D_00454944;
int func_00415FB8(void) {
    return D_00454944;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00415FC8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00415FC8\n.ent func_00415FC8\nfunc_00415FC8:\n"
    "sltiu $2, $6, 0x10\n"
    ".word 0x14400011 /* bnez $2, .L00416014: raw word */\n"
    "or $2, $4, $5\n"
    "andi $2, $2, 0xF\n"
    ".word 0x1440000E /* bnez $2, .L00416014: raw word */\n"
    "nop\n"
    ".L00415FE0:\n"
    "lq $3, 0x0($4)\n"
    "sltiu $7, $6, 0x20\n"
    "lq $2, 0x0($5)\n"
    "addiu $4, $4, 0x10\n"
    "pxor $8, $2, $3\n"
    "addiu $2, $5, 0x10\n"
    "pcpyud $10, $8, $7\n"
    "or $9, $10, $8\n"
    "movz $5, $2, $9\n"
    ".word 0x55200003 /* bnel $9, $0, .L00416014: raw word */\n"
    "addiu $4, $4, -0x10\n"
    ".word 0x10E0FFF4 /* beqz $7, .L00415FE0: raw word */\n"
    "addiu $6, $6, -0x10\n"
    ".L00416014:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "addiu $6, $6, -0x1\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x10C2000C /* beq $6, $2, .L00416054: raw word */\n"
    "nop\n"
    "lui $7, (0xFFFFFFFF >> 16)\n"
    "ori $7, $7, (0xFFFFFFFF & 0xFFFF)\n"
    ".L00416030:\n"
    "lbu $3, 0x0($4)\n"
    "lbu $2, 0x0($5)\n"
    ".word 0x10620003 /* beq $3, $2, .L00416048: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    ".L00416048:\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x14C7FFF8 /* bne $6, $7, .L00416030: raw word */\n"
    "addiu $5, $5, 0x1\n"
    ".L00416054:\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".end func_00415FC8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041605C);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl func_0041605C\n.ent func_0041605C\nfunc_0041605C:\n"
    "daddu $8, $4, $0\n"
    "sltiu $2, $6, 0x20\n"
    ".word 0x1440001C /* bnez $2, .L004160D8: raw word */\n"
    "daddu $3, $8, $0\n"
    "or $2, $5, $8\n"
    "andi $2, $2, 0xF\n"
    ".word 0x54400019 /* bnel $2, $0, .L004160DC: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "daddu $7, $8, $0\n"
    ".L00416080:\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $4, $6, 0x20\n"
    "sq $3, 0x0($7)\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "addiu $5, $5, 0x10\n"
    "sq $2, 0x0($7)\n"
    ".word 0x1080FFF6 /* beqz $4, .L00416080: raw word */\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x8\n"
    ".word 0x14400009 /* bnez $2, .L004160D8: raw word */\n"
    "daddu $3, $7, $0\n"
    ".L004160B8:\n"
    "ld $3, 0x0($5)\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    ".word 0x1040FFFA /* beqz $2, .L004160B8: raw word */\n"
    "addiu $7, $7, 0x8\n"
    "daddu $3, $7, $0\n"
    ".L004160D8:\n"
    "addiu $6, $6, -0x1\n"
    ".L004160DC:\n"
    "addiu $2, $0, -0x1\n"
    ".word 0x10C20008 /* beq $6, $2, .L00416104: raw word */\n"
    "daddu $4, $2, $0\n"
    ".L004160E8:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "nop\n"
    ".word 0x14C4FFFA /* bne $6, $4, .L004160E8: raw word */\n"
    "addiu $3, $3, 0x1\n"
    ".L00416104:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end func_0041605C\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041610C);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl func_0041610C\n.ent func_0041610C\nfunc_0041610C:\n"
    "daddu $8, $4, $0\n"
    "sltu $2, $5, $8\n"
    ".word 0x10400013 /* beqz $2, .L00416164: raw word */\n"
    "daddu $3, $8, $0\n"
    "addu $7, $5, $6\n"
    "sltu $2, $8, $7\n"
    ".word 0x1040000F /* beqz $2, .L00416164: raw word */\n"
    "addiu $2, $0, -0x1\n"
    "addu $3, $8, $6\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x10C20034 /* beq $6, $2, .L00416208: raw word */\n"
    "daddu $5, $7, $0\n"
    "daddu $4, $2, $0\n"
    ".L00416140:\n"
    "addiu $5, $5, -0x1\n"
    "addiu $3, $3, -0x1\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "nop\n"
    ".word 0x14C4FFFA /* bne $6, $4, .L00416140: raw word */\n"
    "sb $2, 0x0($3)\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".L00416164:\n"
    "sltiu $2, $6, 0x20\n"
    ".word 0x5440001D /* bnel $2, $0, .L004161E0: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "or $2, $5, $3\n"
    "andi $2, $2, 0xF\n"
    ".word 0x54400019 /* bnel $2, $0, .L004161E0: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "daddu $7, $3, $0\n"
    ".L00416184:\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $4, $6, 0x20\n"
    "sq $3, 0x0($7)\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "addiu $5, $5, 0x10\n"
    "sq $2, 0x0($7)\n"
    ".word 0x1080FFF6 /* beqz $4, .L00416184: raw word */\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x8\n"
    ".word 0x14400009 /* bnez $2, .L004161DC: raw word */\n"
    "daddu $3, $7, $0\n"
    ".L004161BC:\n"
    "ld $3, 0x0($5)\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    ".word 0x1040FFFA /* beqz $2, .L004161BC: raw word */\n"
    "addiu $7, $7, 0x8\n"
    "daddu $3, $7, $0\n"
    ".L004161DC:\n"
    "addiu $6, $6, -0x1\n"
    ".L004161E0:\n"
    "addiu $2, $0, -0x1\n"
    ".word 0x10C20008 /* beq $6, $2, .L00416208: raw word */\n"
    "daddu $4, $2, $0\n"
    ".L004161EC:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "nop\n"
    ".word 0x14C4FFFA /* bne $6, $4, .L004161EC: raw word */\n"
    "addiu $3, $3, 0x1\n"
    ".L00416208:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end func_0041610C\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416210);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00416210\n.ent func_00416210\nfunc_00416210:\n"
    "sltiu $2, $6, 0x8\n"
    ".word 0x1440001E /* bnez $2, .L00416290: raw word */\n"
    "daddu $3, $4, $0\n"
    "andi $2, $4, 0xF\n"
    ".word 0x1440001B /* bnez $2, .L00416290: raw word */\n"
    "daddu $7, $4, $0\n"
    "andi $9, $5, 0xFF\n"
    "sltiu $10, $6, 0x20\n"
    "daddu $8, $9, $0\n"
    "dsll $3, $8, 8\n"
    "or $8, $3, $9\n"
    "pcpyh $3, $8\n"
    ".word 0x1540000E /* bnez $10, .L0041627C: raw word */\n"
    "sltiu $2, $6, 0x8\n"
    "pcpyld $8, $3, $3\n"
    ".L0041624C:\n"
    "sq $8, 0x0($7)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x20\n"
    "sq $8, 0x0($7)\n"
    ".word 0x1040FFFA /* beqz $2, .L0041624C: raw word */\n"
    "addiu $7, $7, 0x10\n"
    ".word 0x10000004 /* b .L0041627C: raw word */\n"
    "sltiu $2, $6, 0x8\n"
    ".L00416270:\n"
    "addiu $6, $6, -0x8\n"
    "addiu $7, $7, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    ".L0041627C:\n"
    "nop\n"
    "nop\n"
    ".word 0x5040FFFA /* beql $2, $0, .L00416270: raw word */\n"
    "sd $3, 0x0($7)\n"
    "daddu $3, $7, $0\n"
    ".L00416290:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "addiu $6, $6, -0x1\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x10C2000A /* beq $6, $2, .L004162C8: raw word */\n"
    "nop\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".L004162AC:\n"
    "sb $5, 0x0($3)\n"
    "addiu $6, $6, -0x1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x14C2FFFA /* bne $6, $2, .L004162AC: raw word */\n"
    "addiu $3, $3, 0x1\n"
    ".L004162C8:\n"
    "jr $31\n"
    "daddu $2, $4, $0\n"
    ".end func_00416210\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004162D0);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004162D0\n.ent func_004162D0\nfunc_004162D0:\n"
    "addiu $29, $29, -0x20\n"
    "sq $16, 0x0($29)\n"
    "daddu $16, $4, $0\n"
    "andi $2, $16, 0x7\n"
    ".word 0x1440003A /* bnez $2, .L004163CC: raw word */\n"
    "sq $31, 0x10($29)\n"
    "andi $2, $16, 0xF\n"
    "ori $3, $0, 0x8080\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0x8080\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0x8080\n"
    "dsll $3, $3, 9\n"
    "ori $3, $3, 0x101\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    ".word 0x14400018 /* bnez $2, .L00416388: raw word */\n"
    "ld $6, 0x0($16)\n"
    "lq $2, 0x0($16)\n"
    "pcpyld $7, $3, $3\n"
    "pcpyld $8, $4, $4\n"
    "psubb $3, $2, $7\n"
    "pnor $2, $0, $2\n"
    "pand $3, $3, $2\n"
    "pand $3, $3, $8\n"
    "pcpyud $2, $3, $3\n"
    "or $3, $2, $3\n"
    ".word 0x1460001E /* bnez $3, .L004163CC: raw word */\n"
    "daddu $4, $16, $0\n"
    "addiu $6, $4, 0x10\n"
    ".L0041635C:\n"
    "lq $2, 0x0($6)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $7\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $3, $2, $2\n"
    "or $2, $2, $3\n"
    ".word 0x5040FFF8 /* beql $2, $0, .L0041635C: raw word */\n"
    "addiu $6, $6, 0x10\n"
    ".word 0x10000012 /* b .L004163CC: raw word */\n"
    "daddu $4, $6, $0\n"
    ".L00416388:\n"
    "daddu $7, $3, $0\n"
    "daddu $8, $4, $0\n"
    "dsubu $3, $6, $3\n"
    "nor $2, $0, $6\n"
    "and $3, $3, $2\n"
    "and $3, $3, $4\n"
    ".word 0x1460000A /* bnez $3, .L004163CC: raw word */\n"
    "daddu $4, $16, $0\n"
    "addiu $6, $16, 0x8\n"
    ".L004163AC:\n"
    "ld $2, 0x0($6)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $7\n"
    "and $2, $2, $3\n"
    "and $2, $2, $8\n"
    ".word 0x5040FFFA /* beql $2, $0, .L004163AC: raw word */\n"
    "addiu $6, $6, 0x8\n"
    "daddu $4, $6, $0\n"
    ".L004163CC:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5440FFFA /* bnel $2, $0, .L004163CC: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "jal strcpy\n"
    "nop\n"
    "daddu $2, $16, $0\n"
    "lq $31, 0x10($29)\n"
    "lq $16, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x20\n"
    ".end func_004162D0\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strchr);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl strchr\n.ent strchr\nstrchr:\n"
    "andi $2, $4, 0x7\n"
    ".word 0x1440005E /* bnez $2, .L00416584: raw word */\n"
    "andi $5, $5, 0xFF\n"
    "dsll $3, $5, 8\n"
    "ori $6, $0, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 9\n"
    "ori $6, $6, 0x101\n"
    "daddu $10, $3, $5\n"
    "andi $3, $4, 0xF\n"
    "dsll $2, $10, 16\n"
    "ori $8, $0, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "daddu $2, $2, $10\n"
    "dsll32 $10, $2, 0\n"
    ".word 0x14600026 /* bnez $3, .L004164FC: raw word */\n"
    "daddu $7, $2, $10\n"
    ".L00416468:\n"
    "lq $9, 0x0($4)\n"
    "pcpyld $10, $6, $6\n"
    "pnor $3, $0, $9\n"
    "psubb $2, $9, $10\n"
    "pcpyld $6, $8, $8\n"
    "pand $2, $2, $3\n"
    "pcpyld $8, $7, $7\n"
    "pand $2, $2, $6\n"
    "pcpyud $3, $2, $7\n"
    "or $3, $2, $3\n"
    ".word 0x5460003D /* bnel $3, $0, .L00416588: raw word */\n"
    "lbu $2, 0x0($4)\n"
    "pxor $2, $9, $8\n"
    "psubb $3, $2, $10\n"
    "pnor $2, $0, $2\n"
    "ori $8, $0, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "pand $3, $3, $2\n"
    "pand $3, $3, $6\n"
    "ori $6, $0, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 9\n"
    "ori $6, $6, 0x101\n"
    "pcpyud $2, $3, $5\n"
    "or $3, $2, $3\n"
    ".word 0x5060FFDE /* beql $3, $0, .L00416468: raw word */\n"
    "addiu $4, $4, 0x10\n"
    ".word 0x10000024 /* b .L00416588: raw word */\n"
    "lbu $2, 0x0($4)\n"
    ".L004164FC:\n"
    "ld $9, 0x0($4)\n"
    "nor $3, $0, $9\n"
    "dsubu $2, $9, $6\n"
    "and $2, $2, $3\n"
    "and $2, $2, $8\n"
    ".word 0x5440001D /* bnel $2, $0, .L00416588: raw word */\n"
    "lbu $2, 0x0($4)\n"
    "xor $2, $9, $7\n"
    "dsubu $3, $2, $6\n"
    "nor $2, $0, $2\n"
    "and $3, $3, $2\n"
    "and $3, $3, $8\n"
    ".word 0x54600016 /* bnel $3, $0, .L00416588: raw word */\n"
    "lbu $2, 0x0($4)\n"
    "daddu $9, $6, $0\n"
    "addiu $4, $4, 0x8\n"
    ".L0041653C:\n"
    "ld $6, 0x0($4)\n"
    "dsubu $2, $6, $9\n"
    "nor $3, $0, $6\n"
    "and $2, $2, $3\n"
    "and $2, $2, $8\n"
    ".word 0x1440000C /* bnez $2, .L00416584: raw word */\n"
    "xor $2, $6, $7\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $8\n"
    ".word 0x5040FFF4 /* beql $2, $0, .L0041653C: raw word */\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x10000005 /* b .L00416588: raw word */\n"
    "lbu $2, 0x0($4)\n"
    ".L00416578:\n"
    ".word 0x50450007 /* beql $2, $5, .L00416598: raw word */\n"
    "lbu $3, 0x0($4)\n"
    "addiu $4, $4, 0x1\n"
    ".L00416584:\n"
    "lbu $2, 0x0($4)\n"
    ".L00416588:\n"
    "nop\n"
    ".word 0x1440FFFA /* bnez $2, .L00416578: raw word */\n"
    "nop\n"
    "lbu $3, 0x0($4)\n"
    ".L00416598:\n"
    "daddu $2, $0, $0\n"
    "xor $3, $3, $5\n"
    "jr $31\n"
    "movz $2, $4, $3\n"
    ".end strchr\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004165A8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004165A8\n.ent func_004165A8\nfunc_004165A8:\n"
    "or $8, $4, $5\n"
    "andi $2, $8, 0x7\n"
    ".word 0x5440004B /* bnel $2, $0, .L004166E0: raw word */\n"
    "lb $2, 0x0($4)\n"
    "andi $9, $8, 0xF\n"
    "ori $7, $0, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 9\n"
    "ori $7, $7, 0x101\n"
    "ori $6, $0, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    ".word 0x1520001F /* bnez $9, .L00416674: raw word */\n"
    "ld $2, 0x0($5)\n"
    "lq $3, 0x0($4)\n"
    "pcpyld $8, $7, $7\n"
    "lq $2, 0x0($5)\n"
    "pcpyld $10, $6, $6\n"
    "psubw $7, $2, $3\n"
    "pcpyud $6, $7, $4\n"
    "or $3, $6, $7\n"
    ".word 0x54600031 /* bnel $3, $0, .L004166E0: raw word */\n"
    "lb $2, 0x0($4)\n"
    "lq $2, 0x0($4)\n"
    "pnor $3, $0, $2\n"
    ".L00416628:\n"
    "psubb $2, $2, $8\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $6, $3, $2\n"
    ".word 0x10C00003 /* beqz $6, .L0041664C: raw word */\n"
    "addiu $4, $4, 0x10\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".L0041664C:\n"
    "addiu $5, $5, 0x10\n"
    "lq $2, 0x0($4)\n"
    "lq $3, 0x0($5)\n"
    "psubw $7, $2, $3\n"
    "pcpyud $6, $7, $4\n"
    "or $9, $6, $7\n"
    ".word 0x5120FFF0 /* beql $9, $0, .L00416628: raw word */\n"
    "pnor $3, $0, $2\n"
    ".word 0x1000001C /* b .L004166E0: raw word */\n"
    "lb $2, 0x0($4)\n"
    ".L00416674:\n"
    "ld $3, 0x0($4)\n"
    ".word 0x54620019 /* bnel $3, $2, .L004166E0: raw word */\n"
    "lb $2, 0x0($4)\n"
    "ld $2, 0x0($4)\n"
    "nor $8, $0, $2\n"
    ".L00416688:\n"
    "dsubu $2, $2, $7\n"
    "and $2, $2, $8\n"
    "and $2, $2, $6\n"
    ".word 0x10400003 /* beqz $2, .L004166A4: raw word */\n"
    "addiu $4, $4, 0x8\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".L004166A4:\n"
    "addiu $5, $5, 0x8\n"
    "ld $2, 0x0($4)\n"
    "ld $3, 0x0($5)\n"
    ".word 0x5062FFF5 /* beql $3, $2, .L00416688: raw word */\n"
    "nor $8, $0, $2\n"
    ".word 0x10000009 /* b .L004166E0: raw word */\n"
    "lb $2, 0x0($4)\n"
    ".L004166C0:\n"
    "sll $2, $3, 24\n"
    "lb $3, 0x0($5)\n"
    "sra $2, $2, 24\n"
    ".word 0x54430006 /* bnel $2, $3, .L004166E8: raw word */\n"
    "lbu $3, 0x0($4)\n"
    "addiu $4, $4, 0x1\n"
    "addiu $5, $5, 0x1\n"
    "lb $2, 0x0($4)\n"
    ".L004166E0:\n"
    ".word 0x1440FFF7 /* bnez $2, .L004166C0: raw word */\n"
    "lbu $3, 0x0($4)\n"
    ".L004166E8:\n"
    "lbu $2, 0x0($5)\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    ".end func_004165A8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strcpy);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl strcpy\n.ent strcpy\nstrcpy:\n"
    "daddu $7, $4, $0\n"
    "or $8, $5, $7\n"
    "andi $2, $8, 0x7\n"
    ".word 0x1440003A /* bnez $2, .L004167EC: raw word */\n"
    "daddu $3, $7, $0\n"
    "andi $2, $8, 0xF\n"
    "ori $9, $0, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 9\n"
    "ori $9, $9, 0x101\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    ".word 0x54400019 /* bnel $2, $0, .L004167AC: raw word */\n"
    "ld $10, 0x0($5)\n"
    "pcpyld $10, $9, $9\n"
    "lq $9, 0x0($5)\n"
    "pcpyld $8, $4, $4\n"
    "psubb $2, $9, $10\n"
    "pnor $3, $0, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $4, $2, $9\n"
    "or $3, $2, $4\n"
    ".word 0x1460001D /* bnez $3, .L004167E8: raw word */\n"
    "daddu $6, $7, $0\n"
    ".L00416778:\n"
    "sq $9, 0x0($6)\n"
    "addiu $5, $5, 0x10\n"
    "lq $9, 0x0($5)\n"
    "psubb $2, $9, $10\n"
    "pnor $3, $0, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $4, $2, $9\n"
    "or $3, $2, $4\n"
    ".word 0x1060FFF6 /* beqz $3, .L00416778: raw word */\n"
    "addiu $6, $6, 0x10\n"
    ".word 0x10000011 /* b .L004167EC: raw word */\n"
    "daddu $3, $6, $0\n"
    ".L004167AC:\n"
    "dsubu $2, $10, $9\n"
    "nor $3, $0, $10\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    ".word 0x1440000A /* bnez $2, .L004167E8: raw word */\n"
    "daddu $6, $7, $0\n"
    ".L004167C4:\n"
    "sd $10, 0x0($6)\n"
    "addiu $5, $5, 0x8\n"
    "ld $10, 0x0($5)\n"
    "nor $2, $0, $10\n"
    "dsubu $3, $10, $9\n"
    "and $3, $3, $2\n"
    "and $3, $3, $4\n"
    ".word 0x1060FFF8 /* beqz $3, .L004167C4: raw word */\n"
    "addiu $6, $6, 0x8\n"
    ".L004167E8:\n"
    "daddu $3, $6, $0\n"
    ".L004167EC:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "sll $2, $2, 24\n"
    "nop\n"
    ".word 0x1440FFFA /* bnez $2, .L004167EC: raw word */\n"
    "addiu $3, $3, 0x1\n"
    "jr $31\n"
    "daddu $2, $7, $0\n"
    ".end strcpy\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strlen);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl strlen\n.ent strlen\nstrlen:\n"
    "andi $2, $4, 0x7\n"
    ".word 0x14400047 /* bnez $2, .L00416934: raw word */\n"
    "daddu $7, $4, $0\n"
    "andi $3, $4, 0xF\n"
    "ori $2, $0, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 9\n"
    "ori $2, $2, 0x101\n"
    ".word 0x1460001F /* bnez $3, .L004168BC: raw word */\n"
    "daddu $5, $4, $0\n"
    "lq $3, 0x0($5)\n"
    "pcpyld $8, $2, $2\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "psubb $2, $3, $8\n"
    "pnor $3, $0, $3\n"
    "pcpyld $9, $4, $4\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $9\n"
    "pcpyud $3, $2, $8\n"
    "or $6, $3, $2\n"
    ".word 0x54C0002B /* bnel $6, $0, .L00416934: raw word */\n"
    "daddu $4, $5, $0\n"
    "addiu $5, $5, 0x10\n"
    ".L00416890:\n"
    "lq $2, 0x0($5)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $8\n"
    "pand $2, $2, $3\n"
    "pand $4, $2, $9\n"
    "pcpyud $3, $4, $6\n"
    "or $3, $3, $4\n"
    ".word 0x5060FFF8 /* beql $3, $0, .L00416890: raw word */\n"
    "addiu $5, $5, 0x10\n"
    ".word 0x1000001F /* b .L00416934: raw word */\n"
    "daddu $4, $5, $0\n"
    ".L004168BC:\n"
    "ld $3, 0x0($5)\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsubu $2, $3, $2\n"
    "nor $3, $0, $3\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    ".word 0x54400011 /* bnel $2, $0, .L00416934: raw word */\n"
    "daddu $4, $5, $0\n"
    "ori $6, $0, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 9\n"
    "ori $6, $6, 0x101\n"
    "addiu $5, $5, 0x8\n"
    ".L00416914:\n"
    "ld $2, 0x0($5)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $6\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    ".word 0x5040FFFA /* beql $2, $0, .L00416914: raw word */\n"
    "addiu $5, $5, 0x8\n"
    "daddu $4, $5, $0\n"
    ".L00416934:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5440FFFA /* bnel $2, $0, .L00416934: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "jr $31\n"
    "subu $2, $4, $7\n"
    ".end strlen\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416958);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00416958\n.ent func_00416958\nfunc_00416958:\n"
    "daddu $8, $4, $0\n"
    "andi $2, $8, 0x7\n"
    ".word 0x54400048 /* bnel $2, $0, .L00416A84: raw word */\n"
    "lb $2, 0x0($4)\n"
    "andi $3, $8, 0xF\n"
    ".word 0x54600027 /* bnel $3, $0, .L00416A0C: raw word */\n"
    "ld $2, 0x0($8)\n"
    "ori $7, $0, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 9\n"
    "ori $7, $7, 0x101\n"
    "lq $2, 0x0($8)\n"
    "pcpyld $9, $7, $7\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "psubb $3, $2, $9\n"
    "pnor $2, $0, $2\n"
    "pcpyld $10, $4, $4\n"
    "pand $3, $3, $2\n"
    "pand $3, $3, $10\n"
    "pcpyud $2, $3, $4\n"
    "or $3, $3, $2\n"
    ".word 0x1460002A /* bnez $3, .L00416A7C: raw word */\n"
    "daddu $7, $8, $0\n"
    "addiu $7, $7, 0x10\n"
    "nop\n"
    ".L004169E0:\n"
    "lq $2, 0x0($7)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $2, $2, $3\n"
    ".word 0x1040FFF8 /* beqz $2, .L004169E0: raw word */\n"
    "addiu $7, $7, 0x10\n"
    ".word 0x1000001D /* b .L00416A7C: raw word */\n"
    "addiu $7, $7, -0x10\n"
    ".L00416A0C:\n"
    "ori $9, $0, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 9\n"
    "ori $9, $9, 0x101\n"
    "ori $4, $0, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsll $4, $4, 16\n"
    "ori $4, $4, 0x8080\n"
    "dsubu $3, $2, $9\n"
    "nor $2, $0, $2\n"
    "and $3, $3, $2\n"
    "and $3, $3, $4\n"
    ".word 0x14600009 /* bnez $3, .L00416A7C: raw word */\n"
    "daddu $7, $8, $0\n"
    "addiu $7, $7, 0x8\n"
    ".L00416A60:\n"
    "ld $2, 0x0($7)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    ".word 0x5040FFFA /* beql $2, $0, .L00416A60: raw word */\n"
    "addiu $7, $7, 0x8\n"
    ".L00416A7C:\n"
    "daddu $4, $7, $0\n"
    "lb $2, 0x0($4)\n"
    ".L00416A84:\n"
    ".word 0x10400009 /* beqz $2, .L00416AAC: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "addiu $4, $4, 0x1\n"
    ".L00416A90:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5440FFFA /* bnel $2, $0, .L00416A90: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L00416AAC:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x10C20015 /* beq $6, $2, .L00416B0C: raw word */\n"
    "nop\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    ".word 0x1040000F /* beqz $2, .L00416B0C: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "lui $3, (0xFFFFFFFF >> 16)\n"
    "ori $3, $3, (0xFFFFFFFF & 0xFFFF)\n"
    "nop\n"
    ".L00416AE0:\n"
    ".word 0x50C00001 /* beql $6, $0, .L00416AE8: raw word */\n"
    "sb $0, 0x0($4)\n"
    ".L00416AE8:\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x10C30007 /* beq $6, $3, .L00416B0C: raw word */\n"
    "nop\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    ".word 0x1440FFF6 /* bnez $2, .L00416AE0: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L00416B0C:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end func_00416958\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416B18);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00416B18\n.ent func_00416B18\nfunc_00416B18:\n"
    ".word 0x14C00003 /* bnez $6, .L00416B28: raw word */\n"
    "or $3, $4, $5\n"
    ".L00416B20:\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".L00416B28:\n"
    "andi $2, $3, 0x7\n"
    ".word 0x14400059 /* bnez $2, .L00416C94: raw word */\n"
    "daddu $2, $6, $0\n"
    "andi $2, $3, 0xF\n"
    "sltiu $7, $6, 0x10\n"
    "ori $9, $0, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 9\n"
    "ori $9, $9, 0x101\n"
    "or $2, $2, $7\n"
    ".word 0x1440002A /* bnez $2, .L00416C08: raw word */\n"
    "daddu $7, $4, $0\n"
    "lq $3, 0x0($4)\n"
    "pcpyld $10, $9, $9\n"
    "lq $2, 0x0($5)\n"
    "ori $8, $0, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "dsll $8, $8, 16\n"
    "ori $8, $8, 0x8080\n"
    "psubw $3, $3, $2\n"
    "pcpyld $9, $8, $8\n"
    "pcpyud $2, $3, $4\n"
    "daddu $8, $5, $0\n"
    "or $3, $2, $3\n"
    ".word 0x1460003C /* bnez $3, .L00416C94: raw word */\n"
    "daddu $2, $6, $0\n"
    "addiu $6, $6, -0x10\n"
    ".L00416BAC:\n"
    ".word 0x10C0FFDC /* beqz $6, .L00416B20: raw word */\n"
    "nop\n"
    "lq $2, 0x0($7)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $10\n"
    "pand $2, $2, $3\n"
    "pand $3, $2, $9\n"
    "pcpyud $2, $3, $4\n"
    "or $2, $2, $3\n"
    ".word 0x1440FFD3 /* bnez $2, .L00416B20: raw word */\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x10\n"
    "lq $3, 0x0($7)\n"
    ".word 0x14400029 /* bnez $2, .L00416C88: raw word */\n"
    "addiu $8, $8, 0x10\n"
    "lq $2, 0x0($8)\n"
    "psubw $3, $3, $2\n"
    "pcpyud $2, $3, $4\n"
    "or $2, $2, $3\n"
    ".word 0x5040FFEC /* beql $2, $0, .L00416BAC: raw word */\n"
    "addiu $6, $6, -0x10\n"
    ".word 0x10000022 /* b .L00416C8C: raw word */\n"
    "daddu $4, $7, $0\n"
    ".L00416C08:\n"
    "sltiu $2, $6, 0x8\n"
    ".word 0x1440001E /* bnez $2, .L00416C88: raw word */\n"
    "daddu $8, $5, $0\n"
    "ld $3, 0x0($4)\n"
    "ld $2, 0x0($5)\n"
    ".word 0x1462001D /* bne $3, $2, .L00416C94: raw word */\n"
    "daddu $2, $6, $0\n"
    "addiu $6, $6, -0x8\n"
    "ori $10, $0, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "nop\n"
    ".L00416C48:\n"
    ".word 0x10C0FFB5 /* beqz $6, .L00416B20: raw word */\n"
    "nop\n"
    "ld $2, 0x0($7)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $10\n"
    ".word 0x1440FFAE /* bnez $2, .L00416B20: raw word */\n"
    "addiu $7, $7, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    ".word 0x14400005 /* bnez $2, .L00416C88: raw word */\n"
    "addiu $8, $8, 0x8\n"
    "ld $3, 0x0($7)\n"
    "ld $2, 0x0($8)\n"
    ".word 0x5062FFF1 /* beql $3, $2, .L00416C48: raw word */\n"
    "addiu $6, $6, -0x8\n"
    ".L00416C88:\n"
    "daddu $4, $7, $0\n"
    ".L00416C8C:\n"
    "daddu $5, $8, $0\n"
    "daddu $2, $6, $0\n"
    ".L00416C94:\n"
    ".word 0x1040000E /* beqz $2, .L00416CD0: raw word */\n"
    "addiu $6, $6, -0x1\n"
    ".word 0x10000009 /* b .L00416CC4: raw word */\n"
    "lb $3, 0x0($4)\n"
    "nop\n"
    ".L00416CA8:\n"
    ".word 0x10C0FF9D /* beqz $6, .L00416B20: raw word */\n"
    "nop\n"
    ".word 0x10E0FF9B /* beqz $7, .L00416B20: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "addiu $5, $5, 0x1\n"
    "lb $3, 0x0($4)\n"
    "addiu $6, $6, -0x1\n"
    ".L00416CC4:\n"
    "lb $2, 0x0($5)\n"
    ".word 0x1062FFF7 /* beq $3, $2, .L00416CA8: raw word */\n"
    "lbu $7, 0x0($4)\n"
    ".L00416CD0:\n"
    "lbu $2, 0x0($5)\n"
    "lbu $3, 0x0($4)\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    ".end func_00416B18\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strncpy);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl strncpy\n.ent strncpy\nstrncpy:\n"
    "daddu $8, $4, $0\n"
    "or $7, $5, $4\n"
    "addiu $10, $0, 0x10\n"
    "andi $2, $7, 0x7\n"
    "addiu $9, $0, 0x8\n"
    ".word 0x14400058 /* bnez $2, .L00416E58: raw word */\n"
    "andi $2, $7, 0xF\n"
    "movz $9, $10, $2\n"
    ".word 0x1440002E /* bnez $2, .L00416DBC: raw word */\n"
    "sltu $2, $6, $9\n"
    ".word 0x14400053 /* bnez $2, .L00416E58: raw word */\n"
    "nop\n"
    "ori $7, $0, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 9\n"
    "ori $7, $7, 0x101\n"
    "lq $3, 0x0($5)\n"
    "pcpyld $9, $7, $7\n"
    "pnor $3, $0, $3\n"
    "ori $7, $0, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "dsll $7, $7, 16\n"
    "ori $7, $7, 0x8080\n"
    "psubb $2, $3, $9\n"
    "pcpyld $10, $7, $7\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $3, $2, $3\n"
    ".word 0x14600039 /* bnez $3, .L00416E54: raw word */\n"
    "daddu $7, $8, $0\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x10\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $2, $6, 0x10\n"
    "sq $3, 0x0($7)\n"
    ".word 0x14400032 /* bnez $2, .L00416E54: raw word */\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $2, $2, $3\n"
    ".word 0x5040001C /* beql $2, $0, .L00416E20: raw word */\n"
    "lq $3, 0x0($5)\n"
    ".word 0x10000028 /* b .L00416E58: raw word */\n"
    "daddu $4, $7, $0\n"
    ".L00416DBC:\n"
    ".word 0x14400026 /* bnez $2, .L00416E58: raw word */\n"
    "nop\n"
    "ld $3, 0x0($5)\n"
    "ori $9, $0, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 16\n"
    "ori $9, $9, 0x8080\n"
    "dsll $9, $9, 9\n"
    "ori $9, $9, 0x101\n"
    "ori $10, $0, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "dsll $10, $10, 16\n"
    "ori $10, $10, 0x8080\n"
    "dsubu $2, $3, $9\n"
    "nor $3, $0, $3\n"
    "and $2, $2, $3\n"
    "and $2, $2, $10\n"
    ".word 0x14400010 /* bnez $2, .L00416E54: raw word */\n"
    "daddu $7, $8, $0\n"
    "ld $3, 0x0($5)\n"
    "nop\n"
    ".L00416E20:\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    ".word 0x14400008 /* bnez $2, .L00416E54: raw word */\n"
    "addiu $7, $7, 0x8\n"
    "ld $2, 0x0($5)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $10\n"
    ".word 0x5040FFF4 /* beql $2, $0, .L00416E20: raw word */\n"
    "ld $3, 0x0($5)\n"
    ".L00416E54:\n"
    "daddu $4, $7, $0\n"
    ".L00416E58:\n"
    ".word 0x10C00012 /* beqz $6, .L00416EA4: raw word */\n"
    "daddu $2, $6, $0\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    ".word 0x1440FFF8 /* bnez $2, .L00416E58: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "daddu $2, $6, $0\n"
    ".word 0x10400008 /* beqz $2, .L00416EA4: raw word */\n"
    "addiu $6, $6, -0x1\n"
    ".L00416E88:\n"
    "sb $0, 0x0($4)\n"
    "daddu $2, $6, $0\n"
    "addiu $4, $4, 0x1\n"
    "nop\n"
    "nop\n"
    ".word 0x1440FFFA /* bnez $2, .L00416E88: raw word */\n"
    "addiu $6, $6, -0x1\n"
    ".L00416EA4:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end strncpy\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416EB0);
#ifdef SKIP_ASM
extern int func_00420180(int, char *, int *);
extern char *func_00420010(int);
extern int func_0041FCB0(int *, int, int, int);
extern long func_00417948(), func_004179B0(), func_00417A30();
extern void func_00417A98();
extern long func_00417008(char *, int, int);
char *func_00416EB0_(int ptr, char *file, char *mode) __asm__("func_00416EB0");
char *func_00416EB0_(int ptr, char *file, char *mode) {
    char *fp;
    int f, flags, oflags;
    if ((flags = func_00420180(ptr, mode, &oflags)) == 0)
        return 0;
    if ((fp = func_00420010(ptr)) == 0)
        return 0;
    if ((f = func_0041FCB0(*(int **)(fp + 0x54), (int)file, oflags, 0x1B6)) < 0) {
        *(short *)(fp + 0xC) = 0;
        return 0;
    }
    *(short *)(fp + 0xE) = f;
    *(short *)(fp + 0xC) = flags;
    *(char **)(fp + 0x1C) = fp;
    *(void **)(fp + 0x20) = func_00417948;
    *(void **)(fp + 0x24) = func_004179B0;
    *(void **)(fp + 0x28) = func_00417A30;
    *(void **)(fp + 0x2C) = func_00417A98;
    if (flags & 0x100)
        func_00417008(fp, 0, 2);
    return fp;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416F90);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416EB0(int, int, int);
void func_00416F90(int a, int b) {
    func_00416EB0(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416FC0);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
extern int func_00417418(int, void (*)(void));
void func_00416FC0(int a) {
    func_00417418(a, func_0041FE30);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416FE0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00416FC0(int);
void func_00416FE0(void) {
    func_00416FC0(D_00454944);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417008);
#ifdef SKIP_ASM
struct R17008 {
    int err;
    char pad[0x38 - 4];
    int didinit;
};
struct F17008 {
    unsigned char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    unsigned char *base;
    int size;
    int lbfsize;
    int cookie;
    int pad20[2];
    long (*seek)(int, long, int);
    int pad2C;
    unsigned char *ubbase;
    int ubsize;
    unsigned char *up;
    int ur;
    char pad40[0x4C - 0x40];
    int blksize;
    int offset;
    struct R17008 *data;
};
extern struct R17008 *g17008_impure __asm__("D_00454944");
extern void g17008_init(struct R17008 *) __asm__("func_004200F0");
extern int g17008_fflush(struct F17008 *) __asm__("func_0041FE30");
extern int g17008_fstat(struct R17008 *, int, int *) __asm__("func_0041FBF0");
extern long g17008_sseek(int, long, int) __asm__("func_00417A30");
extern void g17008_smakebuf(struct F17008 *) __asm__("func_004174B0");
extern int g17008_srefill(struct F17008 *) __asm__("func_00417648");
int func_00417008_(struct F17008 *fp, long offset, int whence) __asm__("func_00417008");
int func_00417008_(struct F17008 *fp, long offset, int whence) {
    long (*seekfn)(int, long, int);
    long target, curoff;
    unsigned n;
    int st[0x68 / 4];
    int havepos;
    struct R17008 *ptr;
    if (fp->data == 0)
        fp->data = g17008_impure;
    if (fp->data->didinit == 0)
        g17008_init(fp->data);
    ptr = fp->data;
    if ((*(int *)&fp->flags & 0x108) == 0x108)
        g17008_fflush(fp);
    if ((seekfn = fp->seek) == 0) {
        ptr->err = 0x1D;
        return -1;
    }
    switch (whence) {
    case 1:
        g17008_fflush(fp);
        if (fp->flags & 0x1000)
            curoff = fp->offset;
        else {
            curoff = (*seekfn)(fp->cookie, 0, 1);
            if (curoff == -1)
                return -1;
        }
        if (fp->flags & 4) {
            curoff -= fp->r;
            if (fp->ubbase)
                curoff -= fp->ur;
        } else if (fp->flags & 8 && fp->p != 0)
            curoff += fp->p - fp->base;
        offset += curoff;
        whence = 0;
        havepos = 1;
        break;
    case 0:
    case 2:
        havepos = 0;
        break;
    default:
        ptr->err = 0x16;
        return -1;
    }
    if (fp->base == 0)
        g17008_smakebuf(fp);
    if (fp->flags & 0x81A)
        goto dumb;
    if ((fp->flags & 0x400) == 0) {
        if (seekfn != g17008_sseek || fp->file < 0 || g17008_fstat(ptr, fp->file, st) ||
            (st[1] & 0xF000) != 0x8000) {
            fp->flags |= 0x800;
            goto dumb;
        }
        fp->blksize = 0x400;
        fp->flags |= 0x400;
    }
    if (whence == 0)
        target = offset;
    else {
        if (g17008_fstat(ptr, fp->file, st))
            goto dumb;
        target = *(long *)&st[4] + offset;
    }
    if (!havepos) {
        if (fp->flags & 0x1000)
            curoff = fp->offset;
        else {
            curoff = (*seekfn)(fp->cookie, 0, 1);
            if (curoff == -1)
                goto dumb;
        }
        curoff -= fp->r;
        if (fp->ubbase)
            curoff -= fp->ur;
    }
    if (fp->ubbase) {
        curoff += fp->r;
        n = fp->up - fp->base;
        curoff -= n;
        n += fp->ur;
    } else {
        n = fp->p - fp->base;
        curoff -= n;
        n += fp->r;
    }
    if ((fp->flags & 0x2000) == 0 && target >= curoff && target < curoff + n) {
        int o = target - curoff;
        fp->p = fp->base + o;
        fp->r = n - o;
        fp->flags &= ~0x20;
        return 0;
    }
    curoff = target & -fp->blksize;
    if ((*seekfn)(fp->cookie, curoff, 0) == -1)
        goto dumb;
    fp->r = 0;
    fp->flags &= ~0x20;
    n = target - curoff;
    if (n) {
        if (g17008_srefill(fp) || fp->r < n)
            goto dumb;
        fp->p += n;
        fp->r -= n;
    }
    return 0;
dumb:
    if (g17008_fflush(fp) || (*seekfn)(fp->cookie, offset, whence) == -1)
        return -1;
    fp->p = fp->base;
    fp->r = 0;
    fp->flags &= ~0x20;
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417418);
#ifdef SKIP_ASM
struct G17418 {
    struct G17418 *next;
    int n;
    char *files;
};
int func_00417418(int r_, void (*fn_)(void)) {
    char *r = (char *)r_;
    int (*fn)(char *) = (int (*)(char *))fn_;
    struct G17418 *g;
    char *fp;
    int n;
    int ret = 0;
    for (g = (struct G17418 *)(r + 0x1D8); g; g = g->next) {
        fp = g->files;
        for (n = g->n; --n >= 0; fp += 0x58)
            if (*(short *)(fp + 0xC))
                ret |= fn(fp);
    }
    return ret;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004174B0);
#ifdef SKIP_ASM
struct F174B0 {
    char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    char *base;
    int size;
    char pad1[0x28 - 0x18];
    void *seek;
    char pad2[0x43 - 0x2C];
    char nbuf[9];
    int blksize;
    int offset;
    int data;
};
extern long func_00417A30();
extern int func_0041FBF0(int *, int, int);
void func_004174B0(struct F174B0 *f) {
    int st[0x68 / 4];
    if (f->flags & 2) {
        f->p = f->nbuf;
        f->base = f->nbuf;
        f->size = 1;
        return;
    }
    if (f->file < 0 || func_0041FBF0((int *)f->data, f->file, (int)st) < 0) {
        f->flags |= 0x800;
    } else if ((st[1] & 0xF000) == 0x8000 && f->seek == (void *)func_00417A30) {
        f->blksize = 0x400;
        f->flags |= 0x400;
    } else {
        f->flags |= 0x800;
    }
    f->flags |= 2;
    f->size = 1;
    f->p = f->nbuf;
    f->base = f->nbuf;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417578);
#ifdef SKIP_ASM
#define func_00417578_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern void func_0041B728(int *, int, int, char *);
void func_00417578(int *p, int fmt, ...) {
    char *ap;
    func_00417578_va_start(ap);
    func_0041B728(p, p[2], fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004175C8);
#ifdef SKIP_ASM
#define func_004175C8_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
extern int D_00454944;
extern int func_0041B658(int, int, char *);
void func_004175C8(int fmt, ...) {
    char *ap;
    int *g;
    func_004175C8_va_start(ap);
    g = (int *)D_00454944;
    ((int *)g[2])[0x54 / 4] = (int)g;
    func_0041B658(g[2], fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417628);
#ifdef SKIP_ASM
extern void func_0041FE30(void);
void func_00417628(void) {
    func_0041FE30();
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417648);
#ifdef SKIP_ASM
struct R7648 {
    int err;
    char pad[0x38 - 4];
    int didinit;
};
struct F7648 {
    unsigned char *p;
    int r;
    int w;
    unsigned short flags;
    short file;
    unsigned char *base;
    int size;
    int lbfsize;
    int cookie;
    int (*rd)(int, unsigned char *, int);
    int pad24;
    int pad28;
    int pad2C;
    unsigned char *ubbase;
    int ubsize;
    unsigned char *up;
    int ur;
    char pad40[0x54 - 0x40];
    struct R7648 *data;
};
extern struct R7648 *g7648_impure __asm__("D_00454944");
extern void g7648_init(struct R7648 *) __asm__("func_004200F0");
extern int g7648_fflush(struct F7648 *) __asm__("func_0041FE30");
extern void g7648_smakebuf(struct F7648 *) __asm__("func_004174B0");
extern int g7648_fwalk(struct R7648 *, void *) __asm__("func_00417418");
extern void g7648_lflush(void) __asm__("func_00417628");
int func_00417648_impl(struct F7648 *fp) __asm__("func_00417648");
int func_00417648_impl(struct F7648 *fp) {
    int n;
    do {
        if (fp->data == 0)
            fp->data = g7648_impure;
        if (fp->data->didinit == 0)
            g7648_init(fp->data);
    } while (0);
    fp->r = 0;
    if (fp->flags & 0x20)
        return -1;
    if ((fp->flags & 4) == 0) {
        if ((fp->flags & 0x10) == 0)
            return -1;
        if (fp->flags & 8) {
            if (g7648_fflush(fp))
                return -1;
            fp->flags &= ~8;
            fp->w = 0;
            fp->lbfsize = 0;
        }
        fp->flags |= 4;
    } else if (fp->ubbase != 0) {
        if ((fp->r = fp->ur) != 0) {
            fp->p = fp->up;
            return 0;
        }
    }
    if (fp->base == 0)
        g7648_smakebuf(fp);
    if (fp->flags & 3)
        g7648_fwalk(fp->data, g7648_lflush);
    fp->p = fp->base;
    n = fp->rd(fp->cookie, fp->base, fp->size);
    fp->r = n;
    fp->flags &= ~0x2000;
    if (n <= 0) {
        if (n == 0) {
            fp->flags |= 0x20;
        } else {
            fp->r = 0;
            fp->flags |= 0x40;
        }
        return -1;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004177B0);
#ifdef SKIP_ASM
#define func_004177B0_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct F177B0 {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
void func_004177B0(int reent, char *buf, int fmt, ...) {
    char *ap;
    struct F177B0 f;
    func_004177B0_va_start(ap);
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = reent;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", sprintf);
#ifdef SKIP_ASM
#define sprintf_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct Fsprintf {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
void sprintf(char *buf, int fmt, ...) {
    char *ap;
    struct Fsprintf f;
    sprintf_va_start(ap);
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = D_00454944;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004178A8);
#ifdef SKIP_ASM
int func_004178A8(void) {
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004178B0);
#ifdef SKIP_ASM
#define func_004178B0_va_start(ap) \
    (ap = (char*)__builtin_next_arg() \
          - (__builtin_args_info(2) < 8 ? (8 - __builtin_args_info(2)) * 8 : 0))
struct F178B0 {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int lbfsize;
    int cookie;
    int (*read)(void);
    int pad1[3];
    int ubbase;
    int pad2[0x44 / 4 - 0x34 / 4];
    int lbbase;
    int pad3[0x54 / 4 - 0x48 / 4];
    int ent;
};
extern int strlen(char *);
extern int D_00454944;
extern int func_00417AB8(struct F178B0 *, int, char *);
int func_004178B0(char *str, int fmt, ...) {
    char *ap;
    struct F178B0 f;
    f.flags = 4;
    f.p = str;
    f.base = str;
    f.size = f.r = strlen(str);
    f.read = func_004178A8;
    f.ubbase = 0;
    f.lbbase = 0;
    f.ent = D_00454944;
    func_004178B0_va_start(ap);
    return func_00417AB8(&f, fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417948);
#ifdef SKIP_ASM
extern long func_0041FD10(int *, int, int, int);
long func_00417948(int *f, int a, int b) {
    int r = func_0041FD10((int *)f[0x54 / 4], ((short *)f)[7], a, b);
    if (r >= 0) {
        f[0x50 / 4] += r;
    } else {
        ((unsigned short *)f)[6] &= 0xEFFF;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004179B0);
#ifdef SKIP_ASM
extern long func_0041FDD0(int *, int, int, int);
int func_004179B0_(int *f, int a, int b) __asm__("func_004179B0");
int func_004179B0_(int *f, int a, int b) {
    if (((unsigned short *)f)[6] & 0x100)
        func_0041FC50((int *)f[0x54 / 4], ((short *)f)[7], 0, 2);
    ((unsigned short *)f)[6] &= 0xEFFF;
    return func_0041FDD0((int *)f[0x54 / 4], ((short *)f)[7], a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417A30);
#ifdef SKIP_ASM
extern long func_0041FC50(int *, int, int, int);
long func_00417A30(int *f, int a, int b) {
    long r = func_0041FC50((int *)f[0x54 / 4], ((short *)f)[7], a, b);
    unsigned short *p = (unsigned short *)f + 6;
    if (r == -1) {
        *p &= 0xEFFF;
    } else {
        f[0x50 / 4] = r;
        *p |= 0x1000;
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417A98);
#ifdef SKIP_ASM
extern int func_0041FB98(int, int);
void func_00417A98(int *p) {
    func_0041FB98(p[0x54 / 4], ((short *)p)[7]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00417AB8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00417AB8\n.ent func_00417AB8\nfunc_00417AB8:\n"
    "addiu $29, $29, -0x320\n"
    "addiu $2, $29, 0x260\n"
    "addiu $3, $29, 0x264\n"
    "sq $18, 0x2F0($29)\n"
    "sq $21, 0x2C0($29)\n"
    "daddu $18, $4, $0\n"
    "sq $23, 0x2A0($29)\n"
    "daddu $21, $6, $0\n"
    "sq $30, 0x290($29)\n"
    "daddu $23, $0, $0\n"
    "sq $16, 0x310($29)\n"
    "daddu $30, $0, $0\n"
    "sq $17, 0x300($29)\n"
    "sq $19, 0x2E0($29)\n"
    "sq $20, 0x2D0($29)\n"
    "sq $22, 0x2B0($29)\n"
    "sd $31, 0x280($29)\n"
    "sw $0, 0x264($29)\n"
    "sw $5, 0x268($29)\n"
    "sw $0, 0x270($29)\n"
    "sw $0, 0x26C($29)\n"
    "sw $2, 0x274($29)\n"
    "sw $3, 0x278($29)\n"
    "nop\n"
    ".L00417B18:\n"
    "lui $2, %hi(D_00454944)\n"
    ".L00417B1C:\n"
    "lui $3, %hi(D_00455140)\n"
    "lw $4, %lo(D_00454944)($2)\n"
    "lw $6, 0x268($29)\n"
    "lw $7, %lo(D_00455140)($3)\n"
    "lw $5, 0x274($29)\n"
    "jal func_00418958\n"
    "lw $8, 0x278($29)\n"
    "lw $4, 0x268($29)\n"
    "daddu $22, $2, $0\n"
    "lhu $2, 0x260($29)\n"
    "addu $4, $4, $22\n"
    ".word 0x10400293 /* beqz $2, .L00418598: raw word */\n"
    "sw $4, 0x268($29)\n"
    "addiu $2, $0, 0x1\n"
    ".word 0x16C20020 /* bne $22, $2, .L00417BD8: raw word */\n"
    "lhu $3, 0x260($29)\n"
    "lui $2, %hi(D_00499C81)\n"
    "addiu $4, $2, %lo(D_00499C81)\n"
    "addu $3, $3, $4\n"
    "lbu $2, 0x0($3)\n"
    "andi $2, $2, 0x8\n"
    ".word 0x10400018 /* beqz $2, .L00417BD4: raw word */\n"
    "daddu $16, $4, $0\n"
    ".word 0x10000007 /* b .L00417B98: raw word */\n"
    "lw $2, 0x4($18)\n"
    ".L00417B80:\n"
    "addiu $2, $4, 0x1\n"
    "sw $2, 0x0($18)\n"
    "addiu $23, $23, 0x1\n"
    "addiu $3, $3, -0x1\n"
    "sw $3, 0x4($18)\n"
    "lw $2, 0x4($18)\n"
    ".L00417B98:\n"
    ".word 0x5C400006 /* bgtzl $2, .L00417BB4: raw word */\n"
    "lw $4, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x1440027C /* bnez $2, .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    "lw $4, 0x0($18)\n"
    ".L00417BB4:\n"
    "lbu $2, 0x0($4)\n"
    "addu $2, $2, $16\n"
    "lbu $3, 0x0($2)\n"
    "andi $3, $3, 0x8\n"
    ".word 0x5460FFEE /* bnel $3, $0, .L00417B80: raw word */\n"
    "lw $3, 0x4($18)\n"
    ".word 0x1000FFD3 /* b .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    ".L00417BD4:\n"
    "lhu $3, 0x260($29)\n"
    ".L00417BD8:\n"
    "addiu $2, $0, 0x25\n"
    ".word 0x14620011 /* bne $3, $2, .L00417C24: raw word */\n"
    "lw $3, 0x268($29)\n"
    "daddu $20, $0, $0\n"
    "daddu $19, $0, $0\n"
    ".L00417BEC:\n"
    "lw $2, 0x268($29)\n"
    "lb $16, 0x0($2)\n"
    "addiu $2, $2, 0x1\n"
    "sw $2, 0x268($29)\n"
    "sltiu $2, $16, 0x79\n"
    ".word 0x10400073 /* beqz $2, lbl_00417DD0: raw word */\n"
    "lui $2, %hi(jtbl_00499DC0)\n"
    "sll $3, $16, 2\n"
    "addiu $2, $2, %lo(jtbl_00499DC0)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_00417C20\n"
    "lbl_00417C20:\n"
    ".Llbl_00417C20:\n"
    "lw $3, 0x268($29)\n"
    ".L00417C24:\n"
    "daddu $16, $0, $0\n"
    ".word 0x1AC0FFBB /* blez $22, .L00417B18: raw word */\n"
    "subu $17, $3, $22\n"
    ".L00417C30:\n"
    "lw $2, 0x4($18)\n"
    ".word 0x5C400006 /* bgtzl $2, .L00417C50: raw word */\n"
    "lw $4, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x14400251 /* bnez $2, .L0041858C: raw word */\n"
    "lw $3, 0x26C($29)\n"
    "lw $4, 0x0($18)\n"
    ".L00417C50:\n"
    "lb $3, 0x0($17)\n"
    "lbu $2, 0x0($4)\n"
    ".word 0x1443024F /* bne $2, $3, .L00418598: raw word */\n"
    "addiu $3, $4, 0x1\n"
    "lw $2, 0x4($18)\n"
    "addiu $16, $16, 0x1\n"
    "sw $3, 0x0($18)\n"
    "addiu $2, $2, -0x1\n"
    "addiu $23, $23, 0x1\n"
    "sw $2, 0x4($18)\n"
    "slt $2, $16, $22\n"
    ".word 0x1440FFEC /* bnez $2, .L00417C30: raw word */\n"
    "addiu $17, $17, 0x1\n"
    ".word 0x1000FFA5 /* b .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    ".globl lbl_00417C8C\n"
    "lbl_00417C8C:\n"
    ".Llbl_00417C8C:\n"
    ".word 0x1000FFD7 /* b .L00417BEC: raw word */\n"
    "ori $19, $19, 0x8\n"
    ".globl lbl_00417C94\n"
    "lbl_00417C94:\n"
    ".Llbl_00417C94:\n"
    ".word 0x1000FFD5 /* b .L00417BEC: raw word */\n"
    "ori $19, $19, 0x1\n"
    ".globl lbl_00417C9C\n"
    "lbl_00417C9C:\n"
    ".Llbl_00417C9C:\n"
    ".word 0x1000FFD3 /* b .L00417BEC: raw word */\n"
    "ori $19, $19, 0x2\n"
    ".globl lbl_00417CA4\n"
    "lbl_00417CA4:\n"
    ".Llbl_00417CA4:\n"
    ".word 0x1000FFD1 /* b .L00417BEC: raw word */\n"
    "ori $19, $19, 0x4\n"
    ".globl lbl_00417CAC\n"
    "lbl_00417CAC:\n"
    ".Llbl_00417CAC:\n"
    "addiu $2, $0, 0xA\n"
    "mult $3, $20, $2\n"
    "addu $2, $3, $16\n"
    ".word 0x1000FFCC /* b .L00417BEC: raw word */\n"
    "addiu $20, $2, -0x30\n"
    ".globl lbl_00417CC0\n"
    "lbl_00417CC0:\n"
    ".Llbl_00417CC0:\n"
    "ori $19, $19, 0x1\n"
    ".globl lbl_00417CC4\n"
    "lbl_00417CC4:\n"
    ".Llbl_00417CC4:\n"
    "lui $2, %hi(func_0041E9E0)\n"
    "addiu $16, $0, 0x3\n"
    ".word 0x10000011 /* b .L00417D14: raw word */\n"
    "addiu $2, $2, %lo(func_0041E9E0)\n"
    ".globl lbl_00417CD4\n"
    "lbl_00417CD4:\n"
    ".Llbl_00417CD4:\n"
    "lui $2, %hi(func_0041E9E0)\n"
    "addiu $16, $0, 0x3\n"
    "addiu $2, $2, %lo(func_0041E9E0)\n"
    "daddu $30, $0, $0\n"
    ".word 0x10000045 /* b .L00417DFC: raw word */\n"
    "sw $2, 0x270($29)\n"
    ".globl lbl_00417CEC\n"
    "lbl_00417CEC:\n"
    ".Llbl_00417CEC:\n"
    "ori $19, $19, 0x1\n"
    ".globl lbl_00417CF0\n"
    "lbl_00417CF0:\n"
    ".Llbl_00417CF0:\n"
    "lui $2, %hi(func_0041AA50)\n"
    "addiu $16, $0, 0x3\n"
    "addiu $2, $2, %lo(func_0041AA50)\n"
    "addiu $30, $0, 0x8\n"
    ".word 0x1000003E /* b .L00417DFC: raw word */\n"
    "sw $2, 0x270($29)\n"
    ".globl lbl_00417D08\n"
    "lbl_00417D08:\n"
    ".Llbl_00417D08:\n"
    "lui $2, %hi(func_0041AA50)\n"
    "addiu $16, $0, 0x3\n"
    "addiu $2, $2, %lo(func_0041AA50)\n"
    ".L00417D14:\n"
    "addiu $30, $0, 0xA\n"
    ".word 0x10000038 /* b .L00417DFC: raw word */\n"
    "sw $2, 0x270($29)\n"
    ".globl lbl_00417D20\n"
    "lbl_00417D20:\n"
    ".Llbl_00417D20:\n"
    "lui $2, %hi(func_0041AA50)\n"
    ".word 0x10000011 /* b .L00417D6C: raw word */\n"
    "ori $19, $19, 0x100\n"
    ".globl lbl_00417D2C\n"
    "lbl_00417D2C:\n"
    ".Llbl_00417D2C:\n"
    ".word 0x10000033 /* b .L00417DFC: raw word */\n"
    "addiu $16, $0, 0x4\n"
    ".globl lbl_00417D34\n"
    "lbl_00417D34:\n"
    ".Llbl_00417D34:\n"
    ".word 0x10000031 /* b .L00417DFC: raw word */\n"
    "addiu $16, $0, 0x2\n"
    ".globl lbl_00417D3C\n"
    "lbl_00417D3C:\n"
    ".Llbl_00417D3C:\n"
    "lw $5, 0x268($29)\n"
    "daddu $4, $29, $0\n"
    "ori $19, $19, 0x20\n"
    "jal func_004185D0\n"
    "addiu $16, $0, 0x1\n"
    ".word 0x1000002A /* b .L00417DFC: raw word */\n"
    "sw $2, 0x268($29)\n"
    ".globl lbl_00417D58\n"
    "lbl_00417D58:\n"
    ".Llbl_00417D58:\n"
    "ori $19, $19, 0x20\n"
    ".word 0x10000027 /* b .L00417DFC: raw word */\n"
    "daddu $16, $0, $0\n"
    ".globl lbl_00417D64\n"
    "lbl_00417D64:\n"
    ".Llbl_00417D64:\n"
    "lui $2, %hi(func_0041AA50)\n"
    "ori $19, $19, 0x110\n"
    ".L00417D6C:\n"
    "addiu $2, $2, %lo(func_0041AA50)\n"
    "addiu $16, $0, 0x3\n"
    "sw $2, 0x270($29)\n"
    ".word 0x10000020 /* b .L00417DFC: raw word */\n"
    "addiu $30, $0, 0x10\n"
    ".globl lbl_00417D80\n"
    "lbl_00417D80:\n"
    ".Llbl_00417D80:\n"
    "andi $2, $19, 0x8\n"
    ".word 0x1440FF65 /* bnez $2, .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    "andi $2, $19, 0x4\n"
    ".word 0x10400005 /* beqz $2, .L00417DA8: raw word */\n"
    "andi $2, $19, 0x1\n"
    "addiu $21, $21, 0x8\n"
    "lw $4, -0x8($21)\n"
    ".word 0x1000FF5D /* b .L00417B18: raw word */\n"
    "sh $23, 0x0($4)\n"
    ".L00417DA8:\n"
    ".word 0x10400004 /* beqz $2, .L00417DBC: raw word */\n"
    "addiu $21, $21, 0x8\n"
    "lw $2, -0x8($21)\n"
    ".word 0x1000FF58 /* b .L00417B18: raw word */\n"
    "sd $23, 0x0($2)\n"
    ".L00417DBC:\n"
    "lw $4, -0x8($21)\n"
    ".word 0x1000FF55 /* b .L00417B18: raw word */\n"
    "sw $23, 0x0($4)\n"
    ".globl lbl_00417DC8\n"
    "lbl_00417DC8:\n"
    ".Llbl_00417DC8:\n"
    ".word 0x100001F4 /* b .L0041859C: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".globl lbl_00417DD0\n"
    "lbl_00417DD0:\n"
    ".Llbl_00417DD0:\n"
    "lui $2, %hi(D_00499C81)\n"
    "lui $3, %hi(func_0041E9E0)\n"
    "addiu $3, $3, %lo(func_0041E9E0)\n"
    "addiu $2, $2, %lo(D_00499C81)\n"
    "addu $2, $16, $2\n"
    "sw $3, 0x270($29)\n"
    "lbu $3, 0x0($2)\n"
    "addiu $30, $0, 0xA\n"
    "addiu $16, $0, 0x3\n"
    "andi $3, $3, 0x1\n"
    "or $19, $19, $3\n"
    ".L00417DFC:\n"
    "lw $2, 0x4($18)\n"
    ".word 0x1C400006 /* bgtz $2, .L00417E1C: raw word */\n"
    "andi $2, $19, 0x20\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x144001DE /* bnez $2, .L0041858C: raw word */\n"
    "lw $3, 0x26C($29)\n"
    "andi $2, $19, 0x20\n"
    ".L00417E1C:\n"
    ".word 0x1440001F /* bnez $2, .L00417E9C: raw word */\n"
    "sltiu $2, $16, 0x5\n"
    "lw $4, 0x0($18)\n"
    "lui $2, %hi(D_00499C81)\n"
    "addiu $5, $2, %lo(D_00499C81)\n"
    "lbu $3, 0x0($4)\n"
    "addu $3, $3, $5\n"
    "lbu $2, 0x0($3)\n"
    "andi $2, $2, 0x8\n"
    ".word 0x10400016 /* beqz $2, .L00417E9C: raw word */\n"
    "sltiu $2, $16, 0x5\n"
    "daddu $17, $5, $0\n"
    "lw $2, 0x4($18)\n"
    ".L00417E50:\n"
    "addiu $23, $23, 0x1\n"
    "addiu $2, $2, -0x1\n"
    ".word 0x18400004 /* blez $2, .L00417E6C: raw word */\n"
    "sw $2, 0x4($18)\n"
    "addiu $2, $4, 0x1\n"
    ".word 0x10000005 /* b .L00417E7C: raw word */\n"
    "sw $2, 0x0($18)\n"
    ".L00417E6C:\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x144001C5 /* bnez $2, .L0041858C: raw word */\n"
    "lw $3, 0x26C($29)\n"
    ".L00417E7C:\n"
    "lw $4, 0x0($18)\n"
    "lbu $2, 0x0($4)\n"
    "addu $2, $2, $17\n"
    "lbu $3, 0x0($2)\n"
    "andi $3, $3, 0x8\n"
    ".word 0x5460FFEF /* bnel $3, $0, .L00417E50: raw word */\n"
    "lw $2, 0x4($18)\n"
    "sltiu $2, $16, 0x5\n"
    ".L00417E9C:\n"
    ".word 0x1040FF1F /* beqz $2, .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    "lui $2, %hi(jtbl_00499FB0)\n"
    "sll $3, $16, 2\n"
    "addiu $2, $2, %lo(jtbl_00499FB0)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_00417EC0\n"
    "lbl_00417EC0:\n"
    ".Llbl_00417EC0:\n"
    "addiu $2, $0, 0x1\n"
    "andi $3, $19, 0x8\n"
    ".word 0x1060001A /* beqz $3, .L00417F34: raw word */\n"
    "movz $20, $2, $20\n"
    "daddu $17, $0, $0\n"
    "lw $16, 0x4($18)\n"
    ".L00417ED8:\n"
    "sltu $2, $16, $20\n"
    ".word 0x1040000D /* beqz $2, .L00417F14: raw word */\n"
    "daddu $4, $18, $0\n"
    "lw $2, 0x0($18)\n"
    "addu $17, $17, $16\n"
    "subu $20, $20, $16\n"
    "addu $2, $2, $16\n"
    "jal func_00417648\n"
    "sw $2, 0x0($18)\n"
    ".word 0x5040FFF6 /* beql $2, $0, .L00417ED8: raw word */\n"
    "lw $16, 0x4($18)\n"
    ".word 0x122001A0 /* beqz $17, .L00418588: raw word */\n"
    "addu $23, $23, $17\n"
    ".word 0x1000FF03 /* b .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    ".L00417F14:\n"
    "lw $3, 0x0($18)\n"
    "subu $2, $16, $20\n"
    "sw $2, 0x4($18)\n"
    "addu $17, $17, $20\n"
    "addu $3, $3, $20\n"
    "sw $3, 0x0($18)\n"
    ".word 0x1000FEFA /* b .L00417B18: raw word */\n"
    "addu $23, $23, $17\n"
    ".L00417F34:\n"
    "addiu $21, $21, 0x8\n"
    "daddu $6, $20, $0\n"
    "lw $4, -0x8($21)\n"
    "addiu $5, $0, 0x1\n"
    "jal func_00420260\n"
    "daddu $7, $18, $0\n"
    ".word 0x1040018E /* beqz $2, .L00418588: raw word */\n"
    "lw $4, 0x26C($29)\n"
    "addu $23, $23, $2\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1000FEEE /* b .L00417B18: raw word */\n"
    "sw $4, 0x26C($29)\n"
    ".globl lbl_00417F64\n"
    "lbl_00417F64:\n"
    ".Llbl_00417F64:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "andi $3, $19, 0x8\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x1060001B /* beqz $3, .L00417FE0: raw word */\n"
    "movz $20, $2, $20\n"
    "daddu $16, $0, $0\n"
    "lw $5, 0x0($18)\n"
    ".L00417F80:\n"
    "lbu $2, 0x0($5)\n"
    "addu $3, $29, $2\n"
    "lb $4, 0x0($3)\n"
    ".word 0x10800010 /* beqz $4, .L00417FD0: raw word */\n"
    "addiu $2, $5, 0x1\n"
    "lw $3, 0x4($18)\n"
    "sw $2, 0x0($18)\n"
    "addiu $16, $16, 0x1\n"
    "addiu $3, $3, -0x1\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x12800009 /* beqz $20, .L00417FD0: raw word */\n"
    "sw $3, 0x4($18)\n"
    ".word 0x5C60FFF3 /* bgtzl $3, .L00417F80: raw word */\n"
    "lw $5, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x5040FFEF /* beql $2, $0, .L00417F80: raw word */\n"
    "lw $5, 0x0($18)\n"
    ".word 0x12000170 /* beqz $16, .L0041858C: raw word */\n"
    "lw $3, 0x26C($29)\n"
    ".L00417FD0:\n"
    ".word 0x12000171 /* beqz $16, .L00418598: raw word */\n"
    "addu $23, $23, $16\n"
    ".word 0x1000FED0 /* b .L00417B1C: raw word */\n"
    "lui $2, %hi(D_00454944)\n"
    ".L00417FE0:\n"
    "addiu $21, $21, 0x8\n"
    "lw $17, -0x8($21)\n"
    "daddu $16, $17, $0\n"
    "lw $5, 0x0($18)\n"
    ".L00417FF0:\n"
    "lbu $2, 0x0($5)\n"
    "addu $3, $29, $2\n"
    "lb $4, 0x0($3)\n"
    ".word 0x50800015 /* beql $4, $0, .L00418054: raw word */\n"
    "subu $16, $17, $16\n"
    "lw $2, 0x4($18)\n"
    "addiu $4, $5, 0x1\n"
    "addiu $20, $20, -0x1\n"
    "addiu $2, $2, -0x1\n"
    "sw $2, 0x4($18)\n"
    "lbu $3, 0x0($5)\n"
    "sb $3, 0x0($17)\n"
    "sw $4, 0x0($18)\n"
    ".word 0x1280000A /* beqz $20, .L00418050: raw word */\n"
    "addiu $17, $17, 0x1\n"
    "lw $2, 0x4($18)\n"
    ".word 0x5C40FFEF /* bgtzl $2, .L00417FF0: raw word */\n"
    "lw $5, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x5040FFEB /* beql $2, $0, .L00417FF0: raw word */\n"
    "lw $5, 0x0($18)\n"
    ".word 0x12300150 /* beq $17, $16, .L0041858C: raw word */\n"
    "lw $3, 0x26C($29)\n"
    ".L00418050:\n"
    "subu $16, $17, $16\n"
    ".L00418054:\n"
    ".word 0x12000151 /* beqz $16, .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    "sb $0, 0x0($17)\n"
    "lw $2, 0x26C($29)\n"
    "addiu $2, $2, 0x1\n"
    ".word 0x1000001E /* b .L004180E4: raw word */\n"
    "sw $2, 0x26C($29)\n"
    ".globl lbl_00418070\n"
    "lbl_00418070:\n"
    ".Llbl_00418070:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "andi $3, $19, 0x8\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x1060001B /* beqz $3, .L004180EC: raw word */\n"
    "movz $20, $2, $20\n"
    "lui $2, %hi(D_00499C81)\n"
    "daddu $16, $0, $0\n"
    "addiu $17, $2, %lo(D_00499C81)\n"
    "lw $4, 0x0($18)\n"
    "nop\n"
    ".L00418098:\n"
    "lbu $2, 0x0($4)\n"
    "addu $2, $2, $17\n"
    "lbu $3, 0x0($2)\n"
    "andi $3, $3, 0x8\n"
    ".word 0x1460000E /* bnez $3, .L004180E4: raw word */\n"
    "addiu $2, $4, 0x1\n"
    "lw $3, 0x4($18)\n"
    "sw $2, 0x0($18)\n"
    "addiu $16, $16, 0x1\n"
    "addiu $3, $3, -0x1\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x12800007 /* beqz $20, .L004180E4: raw word */\n"
    "sw $3, 0x4($18)\n"
    ".word 0x5C60FFF2 /* bgtzl $3, .L00418098: raw word */\n"
    "lw $4, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x5040FFEE /* beql $2, $0, .L00418098: raw word */\n"
    "lw $4, 0x0($18)\n"
    ".L004180E4:\n"
    ".word 0x1000FE8C /* b .L00417B18: raw word */\n"
    "addu $23, $23, $16\n"
    ".L004180EC:\n"
    "addiu $21, $21, 0x8\n"
    "lw $3, 0x26C($29)\n"
    "lw $17, -0x8($21)\n"
    "lui $2, %hi(D_00499C81)\n"
    "addiu $22, $2, %lo(D_00499C81)\n"
    "addiu $19, $3, 0x1\n"
    "daddu $16, $17, $0\n"
    "lw $5, 0x0($18)\n"
    "nop\n"
    ".L00418110:\n"
    "lbu $2, 0x0($5)\n"
    "addu $2, $2, $22\n"
    "lbu $3, 0x0($2)\n"
    "andi $3, $3, 0x8\n"
    ".word 0x14600011 /* bnez $3, .L00418168: raw word */\n"
    "addiu $4, $5, 0x1\n"
    "lw $2, 0x4($18)\n"
    "addiu $20, $20, -0x1\n"
    "addiu $2, $2, -0x1\n"
    "sw $2, 0x4($18)\n"
    "lbu $3, 0x0($5)\n"
    "sb $3, 0x0($17)\n"
    "sw $4, 0x0($18)\n"
    ".word 0x12800008 /* beqz $20, .L00418168: raw word */\n"
    "addiu $17, $17, 0x1\n"
    "lw $2, 0x4($18)\n"
    ".word 0x5C40FFEF /* bgtzl $2, .L00418110: raw word */\n"
    "lw $5, 0x0($18)\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x5040FFEB /* beql $2, $0, .L00418110: raw word */\n"
    "lw $5, 0x0($18)\n"
    ".L00418168:\n"
    "subu $2, $17, $16\n"
    "sw $19, 0x26C($29)\n"
    "addu $23, $23, $2\n"
    ".word 0x1000FE68 /* b .L00417B18: raw word */\n"
    "sb $0, 0x0($17)\n"
    ".globl lbl_0041817C\n"
    "lbl_0041817C:\n"
    ".Llbl_0041817C:\n"
    "addiu $20, $20, -0x1\n"
    "addiu $3, $0, 0x15C\n"
    "sltiu $2, $20, 0x15D\n"
    "addiu $17, $29, 0x100\n"
    "movz $20, $3, $2\n"
    "ori $19, $19, 0x2C0\n"
    "addiu $20, $20, 0x1\n"
    ".word 0x1280004B /* beqz $20, lbl_004182C8: raw word */\n"
    "daddu $22, $17, $0\n"
    "lw $2, 0x0($18)\n"
    "nop\n"
    ".L004181A8:\n"
    "lbu $16, 0x0($2)\n"
    "addiu $3, $16, -0x2B\n"
    "sltiu $2, $3, 0x4E\n"
    ".word 0x10400044 /* beqz $2, lbl_004182C8: raw word */\n"
    "lui $2, %hi(jtbl_00499FD0)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_00499FD0)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_004181D4\n"
    "lbl_004181D4:\n"
    ".Llbl_004181D4:\n"
    ".word 0x17C00004 /* bnez $30, .L004181E8: raw word */\n"
    "andi $2, $19, 0x200\n"
    "addiu $30, $0, 0x8\n"
    "ori $19, $19, 0x100\n"
    "andi $2, $19, 0x200\n"
    ".L004181E8:\n"
    ".word 0x14400025 /* bnez $2, .L00418280: raw word */\n"
    "addiu $2, $0, -0x2C1\n"
    ".word 0x10000023 /* b .L00418280: raw word */\n"
    "addiu $2, $0, -0x1C1\n"
    ".globl lbl_004181F8\n"
    "lbl_004181F8:\n"
    ".Llbl_004181F8:\n"
    "lui $2, %hi(D_00499D90)\n"
    "sll $3, $30, 1\n"
    "addiu $2, $2, %lo(D_00499D90)\n"
    "addiu $4, $0, -0x1C1\n"
    "addu $3, $3, $2\n"
    "and $19, $19, $4\n"
    ".word 0x1000001C /* b .L00418284: raw word */\n"
    "lh $30, 0x0($3)\n"
    ".globl lbl_00418218\n"
    "lbl_00418218:\n"
    ".Llbl_00418218:\n"
    "lui $2, %hi(D_00499D90)\n"
    "sll $3, $30, 1\n"
    "addiu $2, $2, %lo(D_00499D90)\n"
    "addu $3, $3, $2\n"
    "lh $30, 0x0($3)\n"
    "slti $2, $30, 0x9\n"
    ".word 0x14400025 /* bnez $2, lbl_004182C8: raw word */\n"
    "addiu $2, $0, -0x1C1\n"
    ".word 0x10000012 /* b .L00418284: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_00418240\n"
    "lbl_00418240:\n"
    ".Llbl_00418240:\n"
    "slti $2, $30, 0xB\n"
    ".word 0x14400020 /* bnez $2, lbl_004182C8: raw word */\n"
    "addiu $2, $0, -0x1C1\n"
    ".word 0x1000000D /* b .L00418284: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_00418254\n"
    "lbl_00418254:\n"
    ".Llbl_00418254:\n"
    "andi $2, $19, 0x40\n"
    ".word 0x1040001B /* beqz $2, lbl_004182C8: raw word */\n"
    "addiu $2, $0, -0x41\n"
    ".word 0x10000008 /* b .L00418284: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_00418268\n"
    "lbl_00418268:\n"
    ".Llbl_00418268:\n"
    "andi $2, $19, 0x100\n"
    ".word 0x10400016 /* beqz $2, lbl_004182C8: raw word */\n"
    "addiu $2, $29, 0x101\n"
    ".word 0x16220014 /* bne $17, $2, lbl_004182C8: raw word */\n"
    "addiu $2, $0, -0x101\n"
    "addiu $30, $0, 0x10\n"
    ".L00418280:\n"
    "and $19, $19, $2\n"
    ".L00418284:\n"
    "sb $16, 0x0($17)\n"
    "addiu $17, $17, 0x1\n"
    "lw $2, 0x4($18)\n"
    "addiu $2, $2, -0x1\n"
    ".word 0x18400005 /* blez $2, .L004182AC: raw word */\n"
    "sw $2, 0x4($18)\n"
    "lw $2, 0x0($18)\n"
    "addiu $2, $2, 0x1\n"
    ".word 0x10000005 /* b .L004182BC: raw word */\n"
    "sw $2, 0x0($18)\n"
    ".L004182AC:\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x14400005 /* bnez $2, .L004182CC: raw word */\n"
    "andi $2, $19, 0x80\n"
    ".L004182BC:\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x5680FFB9 /* bnel $20, $0, .L004181A8: raw word */\n"
    "lw $2, 0x0($18)\n"
    ".globl lbl_004182C8\n"
    "lbl_004182C8:\n"
    ".Llbl_004182C8:\n"
    "andi $2, $19, 0x80\n"
    ".L004182CC:\n"
    ".word 0x10400008 /* beqz $2, .L004182F0: raw word */\n"
    "sltu $2, $22, $17\n"
    ".word 0x104000B1 /* beqz $2, .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    "lb $4, -0x1($17)\n"
    "jal ungetc\n"
    "daddu $5, $18, $0\n"
    ".word 0x100000AC /* b .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    ".L004182F0:\n"
    "lb $16, -0x1($17)\n"
    "addiu $2, $0, 0x78\n"
    ".word 0x12020003 /* beq $16, $2, .L00418308: raw word */\n"
    "addiu $2, $0, 0x58\n"
    ".word 0x16020006 /* bne $16, $2, .L0041831C: raw word */\n"
    "andi $2, $19, 0x8\n"
    ".L00418308:\n"
    "daddu $4, $16, $0\n"
    "addiu $17, $17, -0x1\n"
    "jal ungetc\n"
    "daddu $5, $18, $0\n"
    "andi $2, $19, 0x8\n"
    ".L0041831C:\n"
    ".word 0x14400098 /* bnez $2, .L00418580: raw word */\n"
    "subu $2, $17, $22\n"
    "sb $0, 0x0($17)\n"
    "daddu $4, $22, $0\n"
    "daddu $5, $0, $0\n"
    "lw $3, 0x270($29)\n"
    "jalr $3\n"
    "daddu $6, $30, $0\n"
    "daddu $3, $2, $0\n"
    "andi $2, $19, 0x10\n"
    ".word 0x10400007 /* beqz $2, .L00418364: raw word */\n"
    "andi $2, $19, 0x4\n"
    "addiu $21, $21, 0x8\n"
    "dsll32 $3, $3, 0\n"
    "dsra32 $3, $3, 0\n"
    "lw $2, -0x8($21)\n"
    ".word 0x10000011 /* b .L004183A4: raw word */\n"
    "sw $3, 0x0($2)\n"
    ".L00418364:\n"
    ".word 0x10400005 /* beqz $2, .L0041837C: raw word */\n"
    "andi $2, $3, 0xFFFF\n"
    "addiu $21, $21, 0x8\n"
    "lw $4, -0x8($21)\n"
    ".word 0x1000000B /* b .L004183A4: raw word */\n"
    "sh $2, 0x0($4)\n"
    ".L0041837C:\n"
    "andi $2, $19, 0x1\n"
    ".word 0x10400004 /* beqz $2, .L00418394: raw word */\n"
    "addiu $21, $21, 0x8\n"
    "lw $2, -0x8($21)\n"
    ".word 0x10000005 /* b .L004183A4: raw word */\n"
    "sd $3, 0x0($2)\n"
    ".L00418394:\n"
    "dsll32 $2, $3, 0\n"
    "dsra32 $2, $2, 0\n"
    "lw $4, -0x8($21)\n"
    "sw $2, 0x0($4)\n"
    ".L004183A4:\n"
    "lw $4, 0x26C($29)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x10000073 /* b .L0041857C: raw word */\n"
    "sw $4, 0x26C($29)\n"
    ".globl lbl_004183B4\n"
    "lbl_004183B4:\n"
    ".Llbl_004183B4:\n"
    "addiu $20, $20, -0x1\n"
    "addiu $3, $0, 0x15C\n"
    "sltiu $2, $20, 0x15D\n"
    "addiu $17, $29, 0x100\n"
    "movz $20, $3, $2\n"
    "ori $19, $19, 0x3C0\n"
    "addiu $20, $20, 0x1\n"
    ".word 0x12800032 /* beqz $20, lbl_0041849C: raw word */\n"
    "daddu $22, $17, $0\n"
    "lw $2, 0x0($18)\n"
    "nop\n"
    ".L004183E0:\n"
    "lbu $16, 0x0($2)\n"
    "addiu $3, $16, -0x2B\n"
    "sltiu $2, $3, 0x3B\n"
    ".word 0x1040002B /* beqz $2, lbl_0041849C: raw word */\n"
    "lui $2, %hi(jtbl_0049A110)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A110)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_0041840C\n"
    "lbl_0041840C:\n"
    ".Llbl_0041840C:\n"
    "addiu $2, $0, -0xC1\n"
    ".word 0x10000011 /* b .L00418458: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_00418418\n"
    "lbl_00418418:\n"
    ".Llbl_00418418:\n"
    "andi $2, $19, 0x40\n"
    ".word 0x1040001F /* beqz $2, lbl_0041849C: raw word */\n"
    "addiu $2, $0, -0x41\n"
    ".word 0x1000000C /* b .L00418458: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_0041842C\n"
    "lbl_0041842C:\n"
    ".Llbl_0041842C:\n"
    "andi $2, $19, 0x100\n"
    ".word 0x1040001A /* beqz $2, lbl_0041849C: raw word */\n"
    "addiu $2, $0, -0x141\n"
    ".word 0x10000007 /* b .L00418458: raw word */\n"
    "and $19, $19, $2\n"
    ".globl lbl_00418440\n"
    "lbl_00418440:\n"
    ".Llbl_00418440:\n"
    "andi $3, $19, 0x280\n"
    "addiu $2, $0, 0x200\n"
    ".word 0x14620014 /* bne $3, $2, lbl_0041849C: raw word */\n"
    "addiu $2, $0, -0x301\n"
    "and $2, $19, $2\n"
    "ori $19, $2, 0xC0\n"
    ".L00418458:\n"
    "sb $16, 0x0($17)\n"
    "addiu $17, $17, 0x1\n"
    "lw $2, 0x4($18)\n"
    "addiu $2, $2, -0x1\n"
    ".word 0x18400005 /* blez $2, .L00418480: raw word */\n"
    "sw $2, 0x4($18)\n"
    "lw $2, 0x0($18)\n"
    "addiu $2, $2, 0x1\n"
    ".word 0x10000005 /* b .L00418490: raw word */\n"
    "sw $2, 0x0($18)\n"
    ".L00418480:\n"
    "jal func_00417648\n"
    "daddu $4, $18, $0\n"
    ".word 0x14400005 /* bnez $2, .L004184A0: raw word */\n"
    "andi $2, $19, 0x80\n"
    ".L00418490:\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x5680FFD2 /* bnel $20, $0, .L004183E0: raw word */\n"
    "lw $2, 0x0($18)\n"
    ".globl lbl_0041849C\n"
    "lbl_0041849C:\n"
    ".Llbl_0041849C:\n"
    "andi $2, $19, 0x80\n"
    ".L004184A0:\n"
    ".word 0x1040001E /* beqz $2, .L0041851C: raw word */\n"
    "andi $2, $19, 0x200\n"
    ".word 0x1040000E /* beqz $2, .L004184E4: raw word */\n"
    "sltu $2, $22, $17\n"
    ".word 0x1040003A /* beqz $2, .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    "addiu $17, $17, -0x1\n"
    "nop\n"
    ".L004184C0:\n"
    "daddu $5, $18, $0\n"
    "jal ungetc\n"
    "lb $4, 0x0($17)\n"
    "sltu $3, $22, $17\n"
    "nop\n"
    ".word 0x1460FFFA /* bnez $3, .L004184C0: raw word */\n"
    "addiu $17, $17, -0x1\n"
    ".word 0x1000002F /* b .L0041859C: raw word */\n"
    "lw $2, 0x26C($29)\n"
    ".L004184E4:\n"
    "addiu $17, $17, -0x1\n"
    "addiu $2, $0, 0x65\n"
    "lb $16, 0x0($17)\n"
    ".word 0x12020007 /* beq $16, $2, .L00418510: raw word */\n"
    "addiu $2, $0, 0x45\n"
    ".word 0x12020005 /* beq $16, $2, .L00418510: raw word */\n"
    "daddu $4, $16, $0\n"
    "jal ungetc\n"
    "daddu $5, $18, $0\n"
    "addiu $17, $17, -0x1\n"
    "lb $16, 0x0($17)\n"
    ".L00418510:\n"
    "daddu $4, $16, $0\n"
    "jal ungetc\n"
    "daddu $5, $18, $0\n"
    ".L0041851C:\n"
    "andi $2, $19, 0x8\n"
    ".word 0x14400017 /* bnez $2, .L00418580: raw word */\n"
    "subu $2, $17, $22\n"
    "sb $0, 0x0($17)\n"
    "jal func_004187A0\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $2, $0\n"
    "andi $2, $19, 0x1\n"
    ".word 0x54400005 /* bnel $2, $0, .L00418554: raw word */\n"
    "addiu $21, $21, 0x8\n"
    "andi $2, $19, 0x2\n"
    ".word 0x10400005 /* beqz $2, .L00418560: raw word */\n"
    "nop\n"
    "addiu $21, $21, 0x8\n"
    ".L00418554:\n"
    "lw $2, -0x8($21)\n"
    ".word 0x10000005 /* b .L00418570: raw word */\n"
    "sd $4, 0x0($2)\n"
    ".L00418560:\n"
    "jal func_004127A8\n"
    "addiu $21, $21, 0x8\n"
    "lw $16, -0x8($21)\n"
    "swc1 $f0, 0x0($16)\n"
    ".L00418570:\n"
    "lw $2, 0x26C($29)\n"
    "addiu $2, $2, 0x1\n"
    "sw $2, 0x26C($29)\n"
    ".L0041857C:\n"
    "subu $2, $17, $22\n"
    ".L00418580:\n"
    ".word 0x1000FD65 /* b .L00417B18: raw word */\n"
    "addu $23, $23, $2\n"
    ".L00418588:\n"
    "lw $3, 0x26C($29)\n"
    ".L0041858C:\n"
    "addiu $2, $0, -0x1\n"
    ".word 0x10000002 /* b .L0041859C: raw word */\n"
    "movn $2, $3, $3\n"
    ".L00418598:\n"
    "lw $2, 0x26C($29)\n"
    ".L0041859C:\n"
    "lq $16, 0x310($29)\n"
    "lq $17, 0x300($29)\n"
    "lq $18, 0x2F0($29)\n"
    "lq $19, 0x2E0($29)\n"
    "lq $20, 0x2D0($29)\n"
    "lq $21, 0x2C0($29)\n"
    "lq $22, 0x2B0($29)\n"
    "lq $23, 0x2A0($29)\n"
    "lq $30, 0x290($29)\n"
    "ld $31, 0x280($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x320\n"
    ".end func_00417AB8\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004185D0);
#ifdef SKIP_ASM
char *func_004185D0(char *tab, char *fmt) {
    int c, n, v;
    c = *fmt++;
    if (c == '^') {
        v = 1;
        c = *fmt++;
    } else
        v = 0;
    for (n = 0; n < 256; n++)
        tab[n] = v;
    if (c == 0)
        return fmt - 1;
    v = 1 - v;
    for (;;) {
        tab[c] = v;
    doswitch:
        n = *fmt++;
        switch (n) {
        case 0:
            return fmt - 1;
        case '-':
            n = *fmt;
            if (n == ']' || n < c) {
                c = '-';
                break;
            }
            fmt++;
            do {
                tab[++c] = v;
            } while (c < n);
            goto doswitch;
            break;
        case ']':
            return fmt;
        default:
            c = n;
            break;
        }
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004186C8);
#ifdef SKIP_ASM
struct Fvsprintf {
    char *p;
    int r;
    int w;
    short flags, file;
    char *base;
    int size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
extern int func_0041B658(int, int, char *);
void func_004186C8(char *buf, int fmt, char *ap) {
    struct Fvsprintf f;
    f.p = buf;
    f.w = 0x7FFFFFFF;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7FFFFFFF;
    f.ent = D_00454944;
    func_0041B658((int)&f, fmt, ap);
    *f.p = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418720);
#ifdef SKIP_ASM
struct F18720 {
    char *p;
    int r;
    unsigned w;
    short flags, file;
    char *base;
    unsigned size;
    int pad[0x54 / 4 - 6];
    int ent;
};
extern int D_00454944;
int func_00418720(char *buf, unsigned n, int fmt, char *ap) {
    struct F18720 f;
    int r;
    f.p = buf;
    f.w = n;
    f.flags = 0x208;
    f.base = buf;
    f.size = n;
    f.ent = D_00454944;
    r = func_0041B658((int)&f, fmt, ap);
    if (n < (unsigned)r) r = -1;
    *f.p = 0;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418790);
#ifdef SKIP_ASM
void func_001001C8(int) __attribute__((noreturn));
void func_00418790(void) {
    func_001001C8(1);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187A0);
#ifdef SKIP_ASM
extern void func_0041A7E8(int, int);
void func_004187A0(int a) {
    func_0041A7E8(a, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187C0);
#ifdef SKIP_ASM
extern long func_0041E9E0(int, int, int);
int func_004187C0(int a) {
    return func_0041E9E0(a, 0, 10);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004187E8);
#ifdef SKIP_ASM
void *func_004187E8(void *key, char *base, unsigned nmemb, unsigned size, int (*compar)(void *, void *)) {
    unsigned lo = 0, hi = nmemb, mid;
    char *p;
    int c;
    if (nmemb == 0 || size == 0)
        return 0;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        p = base + mid * size;
        c = compar(key, p);
        if (c < 0)
            hi = mid;
        else if (c > 0)
            lo = mid + 1;
        else
            return p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004188C0);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern int func_0041DBF8(int, int);
int func_004188C0(int a) {
    int r;
    func_00418CA8(D_00454944);
    r = func_0041DBF8(D_00454944, a);
    func_00418D08(D_00454944);
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418910);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_00418CA8(int);
extern void func_00418D08(int);
extern void func_0041E340(int, int);
void func_00418910(int a) {
    func_00418CA8(D_00454944);
    func_0041E340(D_00454944, a);
    func_00418D08(D_00454944);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418958);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00418958\n.ent func_00418958\nfunc_00418958:\n"
    "addiu $29, $29, -0x70\n"
    "sq $19, 0x30($29)\n"
    "sq $16, 0x60($29)\n"
    "daddu $19, $29, $0\n"
    "sq $17, 0x50($29)\n"
    "daddu $16, $6, $0\n"
    "sq $18, 0x40($29)\n"
    "daddu $17, $4, $0\n"
    "sq $20, 0x20($29)\n"
    "daddu $18, $8, $0\n"
    "sd $31, 0x10($29)\n"
    "daddu $20, $7, $0\n"
    ".word 0x12000003 /* beqz $16, .L00418998: raw word */\n"
    "movn $19, $5, $5\n"
    ".word 0x128000BC /* beqz $20, .L00418C84: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".L00418998:\n"
    "lw $4, 0x34($17)\n"
    ".word 0x108000B1 /* beqz $4, .L00418C64: raw word */\n"
    "nop\n"
    "jal strlen\n"
    "nop\n"
    "sltiu $2, $2, 0x2\n"
    ".word 0x144000AC /* bnez $2, .L00418C64: raw word */\n"
    "lui $5, %hi(D_0049A200)\n"
    "lw $4, 0x34($17)\n"
    "jal func_004165A8\n"
    "addiu $5, $5, %lo(D_0049A200)\n"
    ".word 0x5440001A /* bnel $2, $0, .L00418A30: raw word */\n"
    "lui $5, %hi(D_0049A208)\n"
    "lbu $3, 0x0($16)\n"
    ".word 0x120000AC /* beqz $16, .L00418C84: raw word */\n"
    "daddu $2, $0, $0\n"
    "addiu $2, $3, -0x81\n"
    "sltiu $2, $2, 0x1F\n"
    ".word 0x14400005 /* bnez $2, .L004189F8: raw word */\n"
    "sltiu $2, $20, 0x2\n"
    "addiu $2, $3, -0xE0\n"
    "sltiu $2, $2, 0x10\n"
    ".word 0x1040009C /* beqz $2, .L00418C64: raw word */\n"
    "sltiu $2, $20, 0x2\n"
    ".L004189F8:\n"
    ".word 0x10400003 /* beqz $2, .L00418A08: raw word */\n"
    "lbu $3, 0x1($16)\n"
    ".globl lbl_00418A00\n"
    "lbl_00418A00:\n"
    ".Llbl_00418A00:\n"
    ".word 0x100000A0 /* b .L00418C84: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".L00418A08:\n"
    "addiu $2, $3, -0x40\n"
    "sltiu $2, $2, 0x3F\n"
    ".word 0x54400019 /* bnel $2, $0, .L00418A78: raw word */\n"
    "lbu $4, 0x0($16)\n"
    "addiu $2, $3, -0x80\n"
    "sltiu $2, $2, 0x7D\n"
    ".word 0x54400015 /* bnel $2, $0, .L00418A78: raw word */\n"
    "lbu $4, 0x0($16)\n"
    ".word 0x10000096 /* b .L00418C84: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".L00418A30:\n"
    "lw $4, 0x34($17)\n"
    "jal func_004165A8\n"
    "addiu $5, $5, %lo(D_0049A208)\n"
    ".word 0x54400014 /* bnel $2, $0, .L00418A90: raw word */\n"
    "lui $5, %hi(D_0049A210)\n"
    ".word 0x1200008E /* beqz $16, .L00418C80: raw word */\n"
    "lbu $2, 0x0($16)\n"
    "addiu $2, $2, -0xA1\n"
    "sltiu $2, $2, 0x5E\n"
    ".word 0x10400083 /* beqz $2, .L00418C64: raw word */\n"
    "sltiu $2, $20, 0x2\n"
    ".word 0x1440FFE8 /* bnez $2, lbl_00418A00: raw word */\n"
    "lbu $3, 0x1($16)\n"
    "addiu $2, $3, -0xA1\n"
    "sltiu $2, $2, 0x5E\n"
    ".word 0x10400085 /* beqz $2, .L00418C84: raw word */\n"
    "addiu $2, $0, -0x1\n"
    "lbu $4, 0x0($16)\n"
    ".L00418A78:\n"
    "addiu $2, $0, 0x2\n"
    "lbu $3, 0x1($16)\n"
    "sll $4, $4, 8\n"
    "addu $3, $3, $4\n"
    ".word 0x1000007E /* b .L00418C84: raw word */\n"
    "sh $3, 0x0($19)\n"
    ".L00418A90:\n"
    "lw $4, 0x34($17)\n"
    "jal func_004165A8\n"
    "addiu $5, $5, %lo(D_0049A210)\n"
    ".word 0x14400071 /* bnez $2, .L00418C64: raw word */\n"
    "nop\n"
    ".word 0x56000004 /* bnel $16, $0, .L00418AB8: raw word */\n"
    "lw $2, 0x0($18)\n"
    "sw $0, 0x0($18)\n"
    ".word 0x10000074 /* b .L00418C84: raw word */\n"
    "addiu $2, $0, 0x1\n"
    ".L00418AB8:\n"
    "addiu $9, $0, 0x3\n"
    "daddu $7, $16, $0\n"
    "daddu $6, $0, $0\n"
    ".word 0x1280FFCE /* beqz $20, lbl_00418A00: raw word */\n"
    "movz $9, $0, $2\n"
    "addu $2, $16, $6\n"
    ".L00418AD0:\n"
    "addiu $3, $0, 0x28\n"
    "lbu $4, 0x0($2)\n"
    ".word 0x10830024 /* beq $4, $3, .L00418B6C: raw word */\n"
    "daddu $8, $2, $0\n"
    "slti $2, $4, 0x29\n"
    ".word 0x1040000D /* beqz $2, .L00418B1C: raw word */\n"
    "addiu $2, $0, 0x1B\n"
    ".word 0x10820019 /* beq $4, $2, .L00418B54: raw word */\n"
    "slti $2, $4, 0x1C\n"
    ".word 0x10400005 /* beqz $2, .L00418B0C: raw word */\n"
    "addiu $2, $0, 0x24\n"
    ".word 0x10800021 /* beqz $4, .L00418B84: raw word */\n"
    "addiu $2, $4, -0x21\n"
    ".word 0x10000021 /* b .L00418B8C: raw word */\n"
    "addiu $3, $0, 0x5D\n"
    ".L00418B0C:\n"
    ".word 0x10820013 /* beq $4, $2, .L00418B5C: raw word */\n"
    "addiu $2, $4, -0x21\n"
    ".word 0x1000001D /* b .L00418B8C: raw word */\n"
    "addiu $3, $0, 0x5D\n"
    ".L00418B1C:\n"
    "addiu $2, $0, 0x42\n"
    ".word 0x10820014 /* beq $4, $2, .L00418B74: raw word */\n"
    "slti $2, $4, 0x43\n"
    ".word 0x10400005 /* beqz $2, .L00418B40: raw word */\n"
    "addiu $2, $0, 0x40\n"
    ".word 0x1082000C /* beq $4, $2, .L00418B64: raw word */\n"
    "addiu $2, $4, -0x21\n"
    ".word 0x10000014 /* b .L00418B8C: raw word */\n"
    "addiu $3, $0, 0x5D\n"
    ".L00418B40:\n"
    "addiu $2, $0, 0x4A\n"
    ".word 0x1082000D /* beq $4, $2, .L00418B7C: raw word */\n"
    "addiu $2, $4, -0x21\n"
    ".word 0x1000000F /* b .L00418B8C: raw word */\n"
    "addiu $3, $0, 0x5D\n"
    ".L00418B54:\n"
    ".word 0x10000011 /* b .L00418B9C: raw word */\n"
    "daddu $4, $0, $0\n"
    ".L00418B5C:\n"
    ".word 0x1000000F /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x1\n"
    ".L00418B64:\n"
    ".word 0x1000000D /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x3\n"
    ".L00418B6C:\n"
    ".word 0x1000000B /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x2\n"
    ".L00418B74:\n"
    ".word 0x10000009 /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x4\n"
    ".L00418B7C:\n"
    ".word 0x10000007 /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x5\n"
    ".L00418B84:\n"
    ".word 0x10000005 /* b .L00418B9C: raw word */\n"
    "addiu $4, $0, 0x6\n"
    ".L00418B8C:\n"
    "sltu $3, $3, $2\n"
    "addiu $4, $0, 0x8\n"
    "addiu $2, $0, 0x7\n"
    "movz $4, $2, $3\n"
    ".L00418B9C:\n"
    "addiu $5, $0, 0x24\n"
    "sll $4, $4, 2\n"
    "mult $5, $9, $5\n"
    "lui $3, %hi(D_00454AF8)\n"
    "addiu $3, $3, %lo(D_00454AF8)\n"
    "lui $2, %hi(D_00454948)\n"
    "addiu $2, $2, %lo(D_00454948)\n"
    "addu $4, $4, $5\n"
    "addu $3, $4, $3\n"
    "lw $3, 0x0($3)\n"
    "addu $4, $4, $2\n"
    "sltiu $2, $3, 0x8\n"
    ".word 0x1040FF8C /* beqz $2, lbl_00418A00: raw word */\n"
    "lw $9, 0x0($4)\n"
    "lui $2, %hi(jtbl_0049A220)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A220)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_00418BF0\n"
    "lbl_00418BF0:\n"
    ".Llbl_00418BF0:\n"
    "sw $0, 0x0($18)\n"
    "daddu $2, $6, $0\n"
    ".word 0x10000022 /* b .L00418C84: raw word */\n"
    "sh $0, 0x0($19)\n"
    ".globl lbl_00418C00\n"
    "lbl_00418C00:\n"
    ".Llbl_00418C00:\n"
    "sw $0, 0x0($18)\n"
    "addiu $2, $6, 0x1\n"
    "lbu $3, 0x0($7)\n"
    ".word 0x1000001D /* b .L00418C84: raw word */\n"
    "sh $3, 0x0($19)\n"
    ".globl lbl_00418C14\n"
    "lbl_00418C14:\n"
    ".Llbl_00418C14:\n"
    "sw $0, 0x0($18)\n"
    ".word 0x10000005 /* b .L00418C30: raw word */\n"
    "addiu $2, $6, 0x1\n"
    ".globl lbl_00418C20\n"
    "lbl_00418C20:\n"
    ".Llbl_00418C20:\n"
    "addiu $3, $0, 0x1\n"
    "subu $2, $7, $16\n"
    "sw $3, 0x0($18)\n"
    "addiu $2, $2, 0x2\n"
    ".L00418C30:\n"
    "lbu $3, 0x0($7)\n"
    "lbu $4, 0x1($7)\n"
    "sll $3, $3, 8\n"
    "addu $4, $4, $3\n"
    ".word 0x10000010 /* b .L00418C84: raw word */\n"
    "sh $4, 0x0($19)\n"
    ".globl lbl_00418C48\n"
    "lbl_00418C48:\n"
    ".Llbl_00418C48:\n"
    "addiu $7, $8, 0x1\n"
    ".globl lbl_00418C4C\n"
    "lbl_00418C4C:\n"
    ".Llbl_00418C4C:\n"
    "addiu $6, $6, 0x1\n"
    "sltu $2, $6, $20\n"
    ".word 0x1440FF9E /* bnez $2, .L00418AD0: raw word */\n"
    "addu $2, $16, $6\n"
    ".word 0x10000009 /* b .L00418C84: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".L00418C64:\n"
    ".word 0x52000007 /* beql $16, $0, .L00418C84: raw word */\n"
    "daddu $2, $0, $0\n"
    "lbu $2, 0x0($16)\n"
    "sh $2, 0x0($19)\n"
    "lbu $2, 0x0($16)\n"
    ".word 0x10000002 /* b .L00418C84: raw word */\n"
    "sltu $2, $0, $2\n"
    ".L00418C80:\n"
    "daddu $2, $0, $0\n"
    ".L00418C84:\n"
    "lq $16, 0x60($29)\n"
    "lq $17, 0x50($29)\n"
    "lq $18, 0x40($29)\n"
    "lq $19, 0x30($29)\n"
    "lq $20, 0x20($29)\n"
    "ld $31, 0x10($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x70\n"
    ".end func_00418958\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418CA8);
#ifdef SKIP_ASM
extern int func_00423C90(void);
extern void func_00423DE0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418CA8(int unused) {
    int id = func_00423C90();
    if (D_00454CA8 == id) {
        D_00454CAC++;
    } else {
        func_00423DE0(D_00455248);
        D_00454CA8 = id;
        D_00454CAC++;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418D08);
#ifdef SKIP_ASM
extern void func_00423DC0(int);
extern int D_00454CA8;
extern int D_00454CAC;
extern int D_00455248;
void func_00418D08(int unused) {
    if (--D_00454CAC == 0) {
        D_00454CA8 = -1;
        func_00423DC0(D_00455248);
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418D48);
#ifdef SKIP_ASM
extern void func_004218D8(int, int, int, int, int);
void func_00418D48(int a, int b, int c, int d) {
    func_004218D8(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418D68);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418D48(int, int, int, int);
void func_00418D68(int a, int b, int c) {
    func_00418D48(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418DB8);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern int func_00418E68(int, int, int);
void func_00418DB8(int a, int b) {
    func_00418E68(func_00413AF8(), a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418DF8);
#ifdef SKIP_ASM
extern void func_00421A50(int, int, int, int, int);
void func_00418DF8(int a, int b, int c, int d) {
    func_00421A50(a, b, c, d, 0);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418E18);
#ifdef SKIP_ASM
extern int func_00413AF8(void);
extern void func_00418DF8(int, int, int, int);
void func_00418E18(int a, int b, int c) {
    func_00418DF8(func_00413AF8(), a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418E68);
#ifdef SKIP_ASM
extern int D_00454944;
extern int func_00412500(int, int);
extern int func_00421B98(int, int, int, char *, int, int);
int func_00418E68(int a, int prec, int buf_) {
    char *buf = (char *)buf_;
    char *p = buf;
    if (func_00412500(a, 0) < 0) {
        *p++ = '-';
        prec--;
    }
    return func_00421B98(D_00454944, a, prec, p, 'g', 0) ? (int)buf : 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00418EF8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00418EF8\n.ent func_00418EF8\nfunc_00418EF8:\n"
    "addiu $29, $29, -0xF0\n"
    "sq $18, 0xC0($29)\n"
    "sq $22, 0x80($29)\n"
    "daddu $18, $6, $0\n"
    "sq $23, 0x70($29)\n"
    "daddu $22, $4, $0\n"
    "sq $16, 0xE0($29)\n"
    "daddu $23, $7, $0\n"
    "sq $17, 0xD0($29)\n"
    "sq $19, 0xB0($29)\n"
    "sq $20, 0xA0($29)\n"
    "sq $21, 0x90($29)\n"
    "sq $30, 0x60($29)\n"
    "sd $31, 0x50($29)\n"
    "sw $5, 0x0($29)\n"
    ".L00418F34:\n"
    "andi $2, $22, 0x7\n"
    ".word 0x14400006 /* bnez $2, .L00418F54: raw word */\n"
    "addiu $2, $0, 0x2\n"
    "andi $2, $18, 0x7\n"
    ".word 0x54400003 /* bnel $2, $0, .L00418F54: raw word */\n"
    "addiu $2, $0, 0x2\n"
    "xori $2, $18, 0x8\n"
    "sltu $2, $0, $2\n"
    ".L00418F54:\n"
    "sw $2, 0x4($29)\n"
    "lw $3, 0x0($29)\n"
    "sltiu $2, $3, 0x7\n"
    ".word 0x1040003F /* beqz $2, .L00419060: raw word */\n"
    "sw $0, 0x8($29)\n"
    "mult $2, $3, $18\n"
    "addu $16, $22, $18\n"
    "addu $3, $2, $22\n"
    "sltu $2, $16, $3\n"
    ".word 0x1040024A /* beqz $2, .L004198A4: raw word */\n"
    "srl $2, $18, 3\n"
    "sw $3, 0xC($29)\n"
    "lw $3, 0x4($29)\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $20, $18, 0\n"
    "slti $21, $3, 0x2\n"
    "daddu $17, $16, $0\n"
    ".L00418F98:\n"
    ".word 0x10000022 /* b .L00419024: raw word */\n"
    "addu $19, $16, $18\n"
    ".L00418FA0:\n"
    ".word 0x14800006 /* bnez $4, .L00418FBC: raw word */\n"
    "nop\n"
    "ld $2, 0x0($16)\n"
    "ld $3, 0x0($17)\n"
    "sd $2, 0x0($17)\n"
    ".word 0x1000001A /* b .L00419020: raw word */\n"
    "sd $3, 0x0($16)\n"
    ".L00418FBC:\n"
    ".word 0x12A0000E /* beqz $21, .L00418FF8: raw word */\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $30, 0\n"
    "daddu $6, $16, $0\n"
    "nop\n"
    ".L00418FD0:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00418FD0: raw word */\n"
    "addiu $6, $6, 0x8\n"
    ".word 0x1000000C /* b .L00419024: raw word */\n"
    "daddu $17, $16, $0\n"
    ".L00418FF8:\n"
    "dsrl32 $5, $20, 0\n"
    "daddu $6, $16, $0\n"
    ".L00419000:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419000: raw word */\n"
    "addiu $6, $6, 0x1\n"
    ".L00419020:\n"
    "daddu $17, $16, $0\n"
    ".L00419024:\n"
    "sltu $2, $22, $17\n"
    ".word 0x10400006 /* beqz $2, .L00419044: raw word */\n"
    "subu $16, $17, $18\n"
    "daddu $5, $17, $0\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    ".word 0x5C40FFD8 /* bgtzl $2, .L00418FA0: raw word */\n"
    "lw $4, 0x4($29)\n"
    ".L00419044:\n"
    "lw $3, 0xC($29)\n"
    "daddu $16, $19, $0\n"
    "sltu $2, $16, $3\n"
    ".word 0x1440FFD1 /* bnez $2, .L00418F98: raw word */\n"
    "daddu $17, $16, $0\n"
    ".word 0x10000213 /* b .L004198A8: raw word */\n"
    "lq $16, 0xE0($29)\n"
    ".L00419060:\n"
    "lw $4, 0x0($29)\n"
    "srl $2, $4, 1\n"
    "sltiu $3, $4, 0x8\n"
    "addiu $4, $4, -0x1\n"
    "sw $4, 0x30($29)\n"
    "mult $4, $2, $18\n"
    ".word 0x1460008B /* bnez $3, .L004192A8: raw word */\n"
    "addu $16, $4, $22\n"
    "lw $3, 0x0($29)\n"
    "daddu $17, $22, $0\n"
    "sltiu $2, $3, 0x29\n"
    "lw $3, 0x30($29)\n"
    "mult $3, $3, $18\n"
    ".word 0x14400066 /* bnez $2, .L00419230: raw word */\n"
    "addu $21, $3, $22\n"
    "lw $4, 0x0($29)\n"
    "srl $2, $4, 3\n"
    "mult $30, $2, $18\n"
    "daddu $4, $22, $0\n"
    "addu $17, $22, $30\n"
    "sll $2, $30, 1\n"
    "addu $19, $2, $22\n"
    "jalr $23\n"
    "daddu $5, $17, $0\n"
    ".word 0x0441000C /* bgez $2, .L004190F4: raw word */\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    ".word 0x04400014 /* bltz $2, .L00419124: raw word */\n"
    "daddu $4, $22, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $19, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x1000000E /* b .L00419128: raw word */\n"
    "movn $4, $22, $3\n"
    ".L004190F4:\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    ".word 0x5C40000A /* bgtzl $2, .L00419128: raw word */\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $22, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $22, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x10000002 /* b .L00419128: raw word */\n"
    "movn $4, $19, $3\n"
    ".L00419124:\n"
    "daddu $4, $17, $0\n"
    ".L00419128:\n"
    "subu $20, $16, $30\n"
    "daddu $17, $4, $0\n"
    "addu $19, $16, $30\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $16, $0\n"
    ".word 0x0441000C /* bgez $2, .L00419174: raw word */\n"
    "daddu $4, $16, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    ".word 0x04400014 /* bltz $2, .L004191A4: raw word */\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $19, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x1000000E /* b .L004191A8: raw word */\n"
    "movn $4, $20, $3\n"
    ".L00419174:\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    ".word 0x5C40000A /* bgtzl $2, .L004191A8: raw word */\n"
    "daddu $4, $16, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $20, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x10000002 /* b .L004191A8: raw word */\n"
    "movn $4, $19, $3\n"
    ".L004191A4:\n"
    "daddu $4, $16, $0\n"
    ".L004191A8:\n"
    "sll $2, $30, 1\n"
    "subu $19, $21, $30\n"
    "subu $20, $21, $2\n"
    "daddu $16, $4, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    ".word 0x0441000C /* bgez $2, .L004191F8: raw word */\n"
    "daddu $4, $19, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    ".word 0x04400014 /* bltz $2, .L00419228: raw word */\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $21, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x1000000E /* b .L0041922C: raw word */\n"
    "movn $4, $20, $3\n"
    ".L004191F8:\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    ".word 0x5C40000A /* bgtzl $2, .L0041922C: raw word */\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $20, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x10000002 /* b .L0041922C: raw word */\n"
    "movn $4, $21, $3\n"
    ".L00419228:\n"
    "daddu $4, $19, $0\n"
    ".L0041922C:\n"
    "daddu $21, $4, $0\n"
    ".L00419230:\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $16, $0\n"
    ".word 0x0441000C /* bgez $2, .L00419270: raw word */\n"
    "daddu $4, $16, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    ".word 0x04400014 /* bltz $2, .L004192A0: raw word */\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $21, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x1000000E /* b .L004192A4: raw word */\n"
    "movn $4, $17, $3\n"
    ".L00419270:\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    ".word 0x5C40000A /* bgtzl $2, .L004192A4: raw word */\n"
    "daddu $4, $16, $0\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $17, $0\n"
    "slt $3, $3, $2\n"
    ".word 0x10000002 /* b .L004192A4: raw word */\n"
    "movn $4, $21, $3\n"
    ".L004192A0:\n"
    "daddu $4, $16, $0\n"
    ".L004192A4:\n"
    "daddu $16, $4, $0\n"
    ".L004192A8:\n"
    "lw $2, 0x4($29)\n"
    ".word 0x14400008 /* bnez $2, .L004192D0: raw word */\n"
    "lw $3, 0x4($29)\n"
    "ld $3, 0x0($16)\n"
    "addu $4, $22, $18\n"
    "sw $4, 0x2C($29)\n"
    "ld $2, 0x0($22)\n"
    "sd $3, 0x0($22)\n"
    ".word 0x10000023 /* b .L00419358: raw word */\n"
    "sd $2, 0x0($16)\n"
    ".L004192D0:\n"
    "slti $2, $3, 0x2\n"
    ".word 0x10400012 /* beqz $2, .L00419320: raw word */\n"
    "srl $2, $18, 3\n"
    "daddu $4, $16, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $6, $22, $0\n"
    "dsrl32 $5, $2, 0\n"
    "addu $2, $22, $18\n"
    "sw $2, 0x2C($29)\n"
    "nop\n"
    ".L004192F8:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($6)\n"
    "sd $3, 0x0($6)\n"
    "sd $2, 0x0($4)\n"
    "addiu $6, $6, 0x8\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L004192F8: raw word */\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x10000010 /* b .L0041935C: raw word */\n"
    "lw $2, 0x30($29)\n"
    ".L00419320:\n"
    "addu $3, $22, $18\n"
    "dsll32 $2, $18, 0\n"
    "sw $3, 0x2C($29)\n"
    "daddu $4, $16, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $6, $22, $0\n"
    ".L00419338:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($6)\n"
    "sb $3, 0x0($6)\n"
    "sb $2, 0x0($4)\n"
    "addiu $6, $6, 0x1\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419338: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L00419358:\n"
    "lw $2, 0x30($29)\n"
    ".L0041935C:\n"
    "dsll32 $4, $18, 0\n"
    "lw $3, 0x4($29)\n"
    "mult $2, $2, $18\n"
    "lw $17, 0x2C($29)\n"
    "slti $3, $3, 0x2\n"
    "sd $4, 0x20($29)\n"
    "sw $3, 0x10($29)\n"
    "daddu $19, $17, $0\n"
    "addu $20, $2, $22\n"
    "srl $2, $18, 3\n"
    "daddu $16, $20, $0\n"
    "dsll32 $2, $2, 0\n"
    ".word 0x10000030 /* b .L00419450: raw word */\n"
    "sd $2, 0x18($29)\n"
    "nop\n"
    ".L00419398:\n"
    ".word 0x14A0002C /* bnez $5, .L0041944C: raw word */\n"
    "addu $9, $17, $18\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x4($29)\n"
    ".word 0x14600007 /* bnez $3, .L004193C8: raw word */\n"
    "sw $2, 0x8($29)\n"
    "ld $3, 0x0($17)\n"
    "addu $7, $19, $18\n"
    "ld $2, 0x0($19)\n"
    "sd $3, 0x0($19)\n"
    ".word 0x10000021 /* b .L00419448: raw word */\n"
    "sd $2, 0x0($17)\n"
    ".L004193C8:\n"
    "lw $4, 0x10($29)\n"
    ".word 0x10800010 /* beqz $4, .L00419410: raw word */\n"
    "ld $2, 0x18($29)\n"
    "daddu $5, $19, $0\n"
    "daddu $4, $17, $0\n"
    "addu $7, $5, $18\n"
    "dsrl32 $6, $2, 0\n"
    "nop\n"
    ".L004193E8:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($5)\n"
    "sd $3, 0x0($5)\n"
    "sd $2, 0x0($4)\n"
    "addiu $5, $5, 0x8\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L004193E8: raw word */\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x10000010 /* b .L0041944C: raw word */\n"
    "daddu $19, $7, $0\n"
    ".L00419410:\n"
    "ld $3, 0x20($29)\n"
    "daddu $5, $19, $0\n"
    "daddu $4, $17, $0\n"
    "addu $7, $5, $18\n"
    "dsrl32 $6, $3, 0\n"
    "nop\n"
    ".L00419428:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($5)\n"
    "sb $3, 0x0($5)\n"
    "sb $2, 0x0($4)\n"
    "addiu $5, $5, 0x1\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L00419428: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L00419448:\n"
    "daddu $19, $7, $0\n"
    ".L0041944C:\n"
    "daddu $17, $9, $0\n"
    ".L00419450:\n"
    "sltu $2, $16, $17\n"
    ".word 0x14400007 /* bnez $2, .L00419474: raw word */\n"
    "lw $4, 0x4($29)\n"
    "daddu $5, $22, $0\n"
    "jalr $23\n"
    "daddu $4, $17, $0\n"
    "daddu $5, $2, $0\n"
    ".word 0x18A0FFCA /* blez $5, .L00419398: raw word */\n"
    "lw $4, 0x4($29)\n"
    ".L00419474:\n"
    "srl $2, $18, 3\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $21, $18, 0\n"
    ".word 0x1000002B /* b .L00419530: raw word */\n"
    "slti $9, $4, 0x2\n"
    ".L00419488:\n"
    ".word 0x14A00028 /* bnez $5, .L0041952C: raw word */\n"
    "subu $8, $16, $18\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x4($29)\n"
    ".word 0x14600007 /* bnez $3, .L004194B8: raw word */\n"
    "sw $2, 0x8($29)\n"
    "ld $3, 0x0($20)\n"
    "subu $7, $20, $18\n"
    "ld $2, 0x0($16)\n"
    "sd $3, 0x0($16)\n"
    ".word 0x1000001D /* b .L00419528: raw word */\n"
    "sd $2, 0x0($20)\n"
    ".L004194B8:\n"
    ".word 0x1120000F /* beqz $9, .L004194F8: raw word */\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $20, $0\n"
    "dsrl32 $6, $30, 0\n"
    "subu $7, $5, $18\n"
    "nop\n"
    ".L004194D0:\n"
    "ld $3, 0x0($5)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($5)\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L004194D0: raw word */\n"
    "addiu $5, $5, 0x8\n"
    ".word 0x1000000E /* b .L0041952C: raw word */\n"
    "daddu $20, $7, $0\n"
    ".L004194F8:\n"
    "daddu $5, $20, $0\n"
    "dsrl32 $6, $21, 0\n"
    "subu $7, $5, $18\n"
    "nop\n"
    ".L00419508:\n"
    "lbu $3, 0x0($5)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($5)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L00419508: raw word */\n"
    "addiu $5, $5, 0x1\n"
    ".L00419528:\n"
    "daddu $20, $7, $0\n"
    ".L0041952C:\n"
    "daddu $16, $8, $0\n"
    ".L00419530:\n"
    "sltu $2, $16, $17\n"
    ".word 0x14400035 /* bnez $2, .L0041960C: raw word */\n"
    "daddu $5, $22, $0\n"
    "sq $9, 0x40($29)\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $2, $0\n"
    ".word 0x04A1FFCE /* bgez $5, .L00419488: raw word */\n"
    "lq $9, 0x40($29)\n"
    "lw $4, 0x4($29)\n"
    ".word 0x14800008 /* bnez $4, .L0041957C: raw word */\n"
    "lw $2, 0x10($29)\n"
    "ld $3, 0x0($16)\n"
    "addu $9, $17, $18\n"
    "ld $2, 0x0($17)\n"
    "subu $8, $16, $18\n"
    "sd $3, 0x0($17)\n"
    ".word 0x10000020 /* b .L004195F8: raw word */\n"
    "sd $2, 0x0($16)\n"
    ".L0041957C:\n"
    ".word 0x10400010 /* beqz $2, .L004195C0: raw word */\n"
    "ld $3, 0x18($29)\n"
    "daddu $5, $17, $0\n"
    "daddu $4, $16, $0\n"
    "addu $9, $5, $18\n"
    "dsrl32 $6, $3, 0\n"
    "subu $8, $4, $18\n"
    ".L00419598:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($5)\n"
    "sd $3, 0x0($5)\n"
    "sd $2, 0x0($4)\n"
    "addiu $5, $5, 0x8\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L00419598: raw word */\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x10000010 /* b .L004195FC: raw word */\n"
    "addiu $3, $0, 0x1\n"
    ".L004195C0:\n"
    "ld $2, 0x20($29)\n"
    "daddu $5, $17, $0\n"
    "daddu $4, $16, $0\n"
    "addu $9, $5, $18\n"
    "dsrl32 $6, $2, 0\n"
    "subu $8, $4, $18\n"
    ".L004195D8:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($5)\n"
    "sb $3, 0x0($5)\n"
    "sb $2, 0x0($4)\n"
    "addiu $5, $5, 0x1\n"
    ".word 0x1CC0FFF9 /* bgtz $6, .L004195D8: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L004195F8:\n"
    "addiu $3, $0, 0x1\n"
    ".L004195FC:\n"
    "daddu $17, $9, $0\n"
    "daddu $16, $8, $0\n"
    ".word 0x1000FF92 /* b .L00419450: raw word */\n"
    "sw $3, 0x8($29)\n"
    ".L0041960C:\n"
    "lw $4, 0x8($29)\n"
    ".word 0x14800041 /* bnez $4, .L00419718: raw word */\n"
    "subu $5, $17, $19\n"
    "lw $2, 0x0($29)\n"
    "lw $16, 0x2C($29)\n"
    "mult $2, $2, $18\n"
    "addu $3, $2, $22\n"
    "sltu $2, $16, $3\n"
    ".word 0x1040009D /* beqz $2, .L004198A4: raw word */\n"
    "srl $2, $18, 3\n"
    "sw $3, 0x28($29)\n"
    "lw $3, 0x4($29)\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $20, $18, 0\n"
    "slti $21, $3, 0x2\n"
    "daddu $17, $16, $0\n"
    "nop\n"
    ".L00419650:\n"
    ".word 0x10000022 /* b .L004196DC: raw word */\n"
    "addu $19, $16, $18\n"
    ".L00419658:\n"
    ".word 0x14800006 /* bnez $4, .L00419674: raw word */\n"
    "nop\n"
    "ld $2, 0x0($16)\n"
    "ld $3, 0x0($17)\n"
    "sd $2, 0x0($17)\n"
    ".word 0x1000001A /* b .L004196D8: raw word */\n"
    "sd $3, 0x0($16)\n"
    ".L00419674:\n"
    ".word 0x12A0000E /* beqz $21, .L004196B0: raw word */\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $30, 0\n"
    "daddu $6, $16, $0\n"
    "nop\n"
    ".L00419688:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419688: raw word */\n"
    "addiu $6, $6, 0x8\n"
    ".word 0x1000000C /* b .L004196DC: raw word */\n"
    "daddu $17, $16, $0\n"
    ".L004196B0:\n"
    "dsrl32 $5, $20, 0\n"
    "daddu $6, $16, $0\n"
    ".L004196B8:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L004196B8: raw word */\n"
    "addiu $6, $6, 0x1\n"
    ".L004196D8:\n"
    "daddu $17, $16, $0\n"
    ".L004196DC:\n"
    "sltu $2, $22, $17\n"
    ".word 0x10400006 /* beqz $2, .L004196FC: raw word */\n"
    "subu $16, $17, $18\n"
    "daddu $5, $17, $0\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    ".word 0x5C40FFD8 /* bgtzl $2, .L00419658: raw word */\n"
    "lw $4, 0x4($29)\n"
    ".L004196FC:\n"
    "lw $3, 0x28($29)\n"
    "daddu $16, $19, $0\n"
    "sltu $2, $16, $3\n"
    ".word 0x1440FFD1 /* bnez $2, .L00419650: raw word */\n"
    "daddu $17, $16, $0\n"
    ".word 0x10000065 /* b .L004198A8: raw word */\n"
    "lq $16, 0xE0($29)\n"
    ".L00419718:\n"
    "subu $3, $19, $22\n"
    "slt $2, $3, $5\n"
    "daddu $7, $5, $0\n"
    "movn $5, $3, $2\n"
    "subu $16, $20, $16\n"
    "lw $2, 0x0($29)\n"
    "mult $2, $2, $18\n"
    ".word 0x18A00020 /* blez $5, .L004197B8: raw word */\n"
    "addu $21, $2, $22\n"
    "lw $4, 0x4($29)\n"
    "slti $2, $4, 0x2\n"
    ".word 0x10400010 /* beqz $2, .L00419788: raw word */\n"
    "subu $3, $17, $5\n"
    "srl $2, $5, 3\n"
    "daddu $6, $3, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $4, $22, $0\n"
    "dsrl32 $5, $2, 0\n"
    ".L00419760:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419760: raw word */\n"
    "addiu $6, $6, 0x8\n"
    ".word 0x1000000E /* b .L004197BC: raw word */\n"
    "subu $2, $21, $20\n"
    ".L00419788:\n"
    "dsll32 $2, $5, 0\n"
    "daddu $6, $3, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $4, $22, $0\n"
    ".L00419798:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419798: raw word */\n"
    "addiu $6, $6, 0x1\n"
    ".L004197B8:\n"
    "subu $2, $21, $20\n"
    ".L004197BC:\n"
    "subu $5, $2, $18\n"
    "sltu $3, $16, $5\n"
    "movn $5, $16, $3\n"
    ".word 0x18A0001F /* blez $5, .L00419848: raw word */\n"
    "lw $3, 0x4($29)\n"
    "slti $2, $3, 0x2\n"
    ".word 0x10400010 /* beqz $2, .L00419818: raw word */\n"
    "subu $3, $21, $5\n"
    "srl $2, $5, 3\n"
    "daddu $4, $17, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $6, $3, $0\n"
    "dsrl32 $5, $2, 0\n"
    ".L004197F0:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L004197F0: raw word */\n"
    "addiu $6, $6, 0x8\n"
    ".word 0x1000000E /* b .L0041984C: raw word */\n"
    "daddu $5, $7, $0\n"
    ".L00419818:\n"
    "dsll32 $2, $5, 0\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $6, $3, $0\n"
    ".L00419828:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x1CA0FFF9 /* bgtz $5, .L00419828: raw word */\n"
    "addiu $6, $6, 0x1\n"
    ".L00419848:\n"
    "daddu $5, $7, $0\n"
    ".L0041984C:\n"
    "sltu $2, $18, $5\n"
    ".word 0x5040000A /* beql $2, $0, .L0041987C: raw word */\n"
    "daddu $5, $16, $0\n"
    "divu $0, $5, $18\n"
    ".word 0x52400001 /* beql $18, $0, .L00419864: raw word */\n"
    "break 0, 7\n"
    ".L00419864:\n"
    "daddu $4, $22, $0\n"
    "daddu $6, $18, $0\n"
    "mflo $5\n"
    "jal func_00418EF8\n"
    "daddu $7, $23, $0\n"
    "daddu $5, $16, $0\n"
    ".L0041987C:\n"
    "sltu $2, $18, $5\n"
    ".word 0x10400009 /* beqz $2, .L004198A8: raw word */\n"
    "lq $16, 0xE0($29)\n"
    "divu $0, $5, $18\n"
    ".word 0x52400001 /* beql $18, $0, .L00419894: raw word */\n"
    "break 0, 7\n"
    ".L00419894:\n"
    "subu $22, $21, $5\n"
    "mflo $2\n"
    ".word 0x1000FDA5 /* b .L00418F34: raw word */\n"
    "sw $2, 0x0($29)\n"
    ".L004198A4:\n"
    "lq $16, 0xE0($29)\n"
    ".L004198A8:\n"
    "lq $17, 0xD0($29)\n"
    "lq $18, 0xC0($29)\n"
    "lq $19, 0xB0($29)\n"
    "lq $20, 0xA0($29)\n"
    "lq $21, 0x90($29)\n"
    "lq $22, 0x80($29)\n"
    "lq $23, 0x70($29)\n"
    "lq $30, 0x60($29)\n"
    "ld $31, 0x50($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xF0\n"
    ".end func_00418EF8\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004198D8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004198D8\n.ent func_004198D8\nfunc_004198D8:\n"
    "addiu $29, $29, -0xF0\n"
    "daddu $10, $0, $0\n"
    "sq $17, 0xD0($29)\n"
    "sq $21, 0x90($29)\n"
    "daddu $17, $0, $0\n"
    "sq $23, 0x70($29)\n"
    "daddu $21, $5, $0\n"
    "sw $6, 0x8($29)\n"
    "daddu $23, $4, $0\n"
    "sq $16, 0xE0($29)\n"
    "daddu $6, $0, $0\n"
    "sq $18, 0xC0($29)\n"
    "sq $19, 0xB0($29)\n"
    "sq $20, 0xA0($29)\n"
    "sq $22, 0x80($29)\n"
    "sq $30, 0x60($29)\n"
    "sd $31, 0x50($29)\n"
    "sw $0, 0xC($29)\n"
    ".L00419920:\n"
    "lb $3, 0x0($21)\n"
    "sltiu $2, $3, 0x2E\n"
    ".word 0x10400012 /* beqz $2, .L00419974: raw word */\n"
    "lui $2, %hi(jtbl_0049A240)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A240)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_00419948\n"
    "lbl_00419948:\n"
    ".Llbl_00419948:\n"
    "addiu $2, $0, 0x1\n"
    "sw $2, 0xC($29)\n"
    ".globl lbl_00419950\n"
    "lbl_00419950:\n"
    ".Llbl_00419950:\n"
    "addiu $21, $21, 0x1\n"
    "lb $2, 0x0($21)\n"
    ".word 0x54400006 /* bnel $2, $0, .L00419974: raw word */\n"
    "lb $3, 0x0($21)\n"
    ".word 0x1000038C /* b .L0041A794: raw word */\n"
    "daddu $21, $5, $0\n"
    ".globl lbl_00419968\n"
    "lbl_00419968:\n"
    ".Llbl_00419968:\n"
    ".word 0x1000FFED /* b .L00419920: raw word */\n"
    "addiu $21, $21, 0x1\n"
    ".globl lbl_00419970\n"
    "lbl_00419970:\n"
    ".Llbl_00419970:\n"
    "lb $3, 0x0($21)\n"
    ".L00419974:\n"
    "addiu $2, $0, 0x30\n"
    ".word 0x1462000C /* bne $3, $2, .L004199AC: raw word */\n"
    "lbu $4, 0x0($21)\n"
    "addiu $10, $0, 0x1\n"
    "addiu $4, $0, 0x30\n"
    ".L00419988:\n"
    "addiu $21, $21, 0x1\n"
    "lb $3, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1064FFFA /* beq $3, $4, .L00419988: raw word */\n"
    "lbu $2, 0x0($21)\n"
    ".word 0x1060037B /* beqz $3, .L0041A794: raw word */\n"
    "daddu $4, $2, $0\n"
    ".L004199AC:\n"
    "sll $2, $4, 24\n"
    "sw $21, 0x18($29)\n"
    "sra $4, $2, 24\n"
    "daddu $18, $0, $0\n"
    "sw $0, 0x20($29)\n"
    "daddu $9, $0, $0\n"
    "slti $2, $4, 0x30\n"
    ".word 0x1440001D /* bnez $2, .L00419A40: raw word */\n"
    "daddu $20, $0, $0\n"
    "slti $2, $4, 0x3A\n"
    ".word 0x1040001B /* beqz $2, .L00419A44: raw word */\n"
    "addiu $2, $0, 0x2E\n"
    "addiu $3, $0, 0xA\n"
    "slti $2, $20, 0x9\n"
    "nop\n"
    ".L004199E8:\n"
    ".word 0x10400006 /* beqz $2, .L00419A04: raw word */\n"
    "lw $7, 0x20($29)\n"
    "mult $7, $7, $3\n"
    "addu $2, $7, $4\n"
    "addiu $2, $2, -0x30\n"
    ".word 0x10000008 /* b .L00419A20: raw word */\n"
    "sw $2, 0x20($29)\n"
    ".L00419A04:\n"
    "slti $2, $20, 0x10\n"
    ".word 0x10400005 /* beqz $2, .L00419A20: raw word */\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $2, $2, 1\n"
    "daddu $2, $4, $2\n"
    "daddiu $18, $2, -0x30\n"
    ".L00419A20:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "slti $2, $4, 0x30\n"
    ".word 0x14400004 /* bnez $2, .L00419A40: raw word */\n"
    "addiu $20, $20, 0x1\n"
    "slti $2, $4, 0x3A\n"
    ".word 0x1440FFEB /* bnez $2, .L004199E8: raw word */\n"
    "slti $2, $20, 0x9\n"
    ".L00419A40:\n"
    "addiu $2, $0, 0x2E\n"
    ".L00419A44:\n"
    ".word 0x14820049 /* bne $4, $2, .L00419B6C: raw word */\n"
    "daddu $30, $20, $0\n"
    "addiu $21, $21, 0x1\n"
    ".word 0x16800042 /* bnez $20, .L00419B5C: raw word */\n"
    "lb $4, 0x0($21)\n"
    "addiu $2, $0, 0x30\n"
    ".word 0x5482000A /* bnel $4, $2, .L00419A88: raw word */\n"
    "addiu $2, $4, -0x31\n"
    "nop\n"
    ".L00419A68:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1082FFFA /* beq $4, $2, .L00419A68: raw word */\n"
    "addiu $6, $6, 0x1\n"
    "addiu $2, $4, -0x31\n"
    ".L00419A88:\n"
    "sltiu $2, $2, 0x9\n"
    ".word 0x10400038 /* beqz $2, .L00419B70: raw word */\n"
    "addiu $2, $0, 0x65\n"
    "daddu $9, $6, $0\n"
    "sw $21, 0x18($29)\n"
    "daddu $6, $0, $0\n"
    "addiu $8, $21, 0x1\n"
    "nop\n"
    ".L00419AA8:\n"
    "addiu $4, $4, -0x30\n"
    ".word 0x10800029 /* beqz $4, .L00419B54: raw word */\n"
    "addiu $6, $6, 0x1\n"
    "addiu $7, $0, 0x1\n"
    "slt $2, $7, $6\n"
    ".word 0x10400013 /* beqz $2, .L00419B0C: raw word */\n"
    "addu $9, $9, $6\n"
    "addiu $7, $6, -0x1\n"
    "addiu $3, $0, 0xA\n"
    "daddu $2, $20, $0\n"
    ".L00419AD0:\n"
    "slti $2, $2, 0x9\n"
    ".word 0x10400005 /* beqz $2, .L00419AEC: raw word */\n"
    "addiu $20, $20, 0x1\n"
    "lw $2, 0x20($29)\n"
    "mult $2, $2, $3\n"
    ".word 0x10000006 /* b .L00419B00: raw word */\n"
    "sw $2, 0x20($29)\n"
    ".L00419AEC:\n"
    "slti $2, $20, 0x11\n"
    ".word 0x10400003 /* beqz $2, .L00419B00: raw word */\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $18, $2, 1\n"
    ".L00419B00:\n"
    "addiu $7, $7, -0x1\n"
    ".word 0x14E0FFF2 /* bnez $7, .L00419AD0: raw word */\n"
    "daddu $2, $20, $0\n"
    ".L00419B0C:\n"
    "daddu $2, $20, $0\n"
    "slti $2, $2, 0x9\n"
    ".word 0x10400008 /* beqz $2, .L00419B38: raw word */\n"
    "addiu $20, $20, 0x1\n"
    "lw $3, 0x20($29)\n"
    "addiu $2, $0, 0xA\n"
    "mtlo $4\n"
    "madd $0, $3, $2\n"
    "mflo $3\n"
    ".word 0x10000007 /* b .L00419B50: raw word */\n"
    "sw $3, 0x20($29)\n"
    ".L00419B38:\n"
    "slti $2, $20, 0x11\n"
    ".word 0x10400004 /* beqz $2, .L00419B50: raw word */\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $2, $2, 1\n"
    "daddu $18, $4, $2\n"
    ".L00419B50:\n"
    "daddu $6, $0, $0\n"
    ".L00419B54:\n"
    "daddu $21, $8, $0\n"
    "lb $4, 0x0($21)\n"
    ".L00419B5C:\n"
    "addiu $2, $4, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1440FFD0 /* bnez $2, .L00419AA8: raw word */\n"
    "addiu $8, $21, 0x1\n"
    ".L00419B6C:\n"
    "addiu $2, $0, 0x65\n"
    ".L00419B70:\n"
    ".word 0x10820004 /* beq $4, $2, .L00419B84: raw word */\n"
    "sd $0, 0x10($29)\n"
    "addiu $2, $0, 0x45\n"
    ".word 0x14820049 /* bne $4, $2, .L00419CA4: raw word */\n"
    "nop\n"
    ".L00419B84:\n"
    ".word 0x56800007 /* bnel $20, $0, .L00419BA4: raw word */\n"
    "daddu $5, $21, $0\n"
    ".word 0x54C00005 /* bnel $6, $0, .L00419BA4: raw word */\n"
    "daddu $5, $21, $0\n"
    ".word 0x55400003 /* bnel $10, $0, .L00419BA4: raw word */\n"
    "daddu $5, $21, $0\n"
    ".globl lbl_00419B9C\n"
    "lbl_00419B9C:\n"
    ".Llbl_00419B9C:\n"
    ".word 0x100002FD /* b .L0041A794: raw word */\n"
    "daddu $21, $5, $0\n"
    ".L00419BA4:\n"
    "addiu $21, $21, 0x1\n"
    "addiu $2, $0, 0x2B\n"
    "lb $4, 0x0($21)\n"
    ".word 0x10820005 /* beq $4, $2, .L00419BC8: raw word */\n"
    "daddu $8, $0, $0\n"
    "addiu $2, $0, 0x2D\n"
    ".word 0x14820005 /* bne $4, $2, .L00419BD4: raw word */\n"
    "addiu $2, $4, -0x30\n"
    "addiu $8, $0, 0x1\n"
    ".L00419BC8:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "addiu $2, $4, -0x30\n"
    ".L00419BD4:\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x10400031 /* beqz $2, .L00419CA0: raw word */\n"
    "addiu $2, $0, 0x30\n"
    ".word 0x5482000B /* bnel $4, $2, .L00419C10: raw word */\n"
    "addiu $2, $4, -0x31\n"
    "addiu $21, $21, 0x1\n"
    "nop\n"
    ".L00419BF0:\n"
    "lb $4, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5082FFFA /* beql $4, $2, .L00419BF0: raw word */\n"
    "addiu $21, $21, 0x1\n"
    "addiu $2, $4, -0x31\n"
    ".L00419C10:\n"
    "sltiu $2, $2, 0x9\n"
    ".word 0x10400020 /* beqz $2, .L00419C98: raw word */\n"
    "addiu $4, $4, -0x30\n"
    "daddu $7, $21, $0\n"
    "sd $4, 0x10($29)\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "slti $2, $4, 0x30\n"
    ".word 0x14400010 /* bnez $2, .L00419C74: raw word */\n"
    "subu $2, $21, $7\n"
    ".L00419C38:\n"
    "slti $2, $4, 0x3A\n"
    ".word 0x1040000C /* beqz $2, .L00419C70: raw word */\n"
    "ld $3, 0x10($29)\n"
    "addiu $21, $21, 0x1\n"
    "dsll $2, $3, 2\n"
    "daddu $2, $2, $3\n"
    "dsll $2, $2, 1\n"
    "daddu $2, $4, $2\n"
    "lb $4, 0x0($21)\n"
    "daddiu $2, $2, -0x30\n"
    "slti $3, $4, 0x30\n"
    ".word 0x1060FFF4 /* beqz $3, .L00419C38: raw word */\n"
    "sd $2, 0x10($29)\n"
    "nop\n"
    ".L00419C70:\n"
    "subu $2, $21, $7\n"
    ".L00419C74:\n"
    "lui $4, (0x98967F >> 16)\n"
    "ori $4, $4, (0x98967F & 0xFFFF)\n"
    "ld $7, 0x10($29)\n"
    "slti $2, $2, 0x9\n"
    "movz $7, $4, $2\n"
    "dsubu $3, $0, $7\n"
    "movn $7, $3, $8\n"
    ".word 0x10000004 /* b .L00419CA4: raw word */\n"
    "sd $7, 0x10($29)\n"
    ".L00419C98:\n"
    ".word 0x10000002 /* b .L00419CA4: raw word */\n"
    "sd $0, 0x10($29)\n"
    ".L00419CA0:\n"
    "daddu $21, $5, $0\n"
    ".L00419CA4:\n"
    ".word 0x16800004 /* bnez $20, .L00419CB8: raw word */\n"
    "ld $3, 0x10($29)\n"
    "movn $5, $21, $10\n"
    ".word 0x100002B8 /* b .L0041A794: raw word */\n"
    "movz $21, $5, $6\n"
    ".L00419CB8:\n"
    "slti $2, $20, 0x11\n"
    "lw $4, 0x20($29)\n"
    "addiu $19, $0, 0x10\n"
    "dsubu $3, $3, $9\n"
    "movn $19, $20, $2\n"
    "dsll32 $16, $3, 0\n"
    "dsra32 $16, $16, 0\n"
    "jal func_00412550\n"
    "sd $3, 0x10($29)\n"
    "movz $30, $20, $30\n"
    "lw $7, 0x20($29)\n"
    ".word 0x04E10006 /* bgez $7, .L00419D00: raw word */\n"
    "daddu $4, $2, $0\n"
    "ori $5, $0, 0x83E0\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411F18\n"
    "nop\n"
    "daddu $4, $2, $0\n"
    ".L00419D00:\n"
    "slti $2, $19, 0xA\n"
    ".word 0x1440001A /* bnez $2, .L00419D70: raw word */\n"
    "daddu $17, $4, $0\n"
    "lui $3, %hi(D_0049A8F8)\n"
    "addiu $2, $19, -0x9\n"
    "addiu $3, $3, %lo(D_0049A8F8)\n"
    "sll $2, $2, 3\n"
    "addu $2, $2, $3\n"
    "daddu $5, $4, $0\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($2)\n"
    ".word 0x06400005 /* bltz $18, .L00419D44: raw word */\n"
    "daddu $17, $2, $0\n"
    "jal func_00411438\n"
    "daddu $4, $18, $0\n"
    ".word 0x10000009 /* b .L00419D64: raw word */\n"
    "daddu $4, $17, $0\n"
    ".L00419D44:\n"
    "dsrl $2, $18, 1\n"
    "andi $4, $18, 0x1\n"
    "jal func_00411438\n"
    "or $4, $4, $2\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $17, $0\n"
    ".L00419D64:\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "daddu $17, $2, $0\n"
    ".L00419D70:\n"
    "slti $2, $20, 0x10\n"
    ".word 0x10400039 /* beqz $2, .L00419E5C: raw word */\n"
    "sw $0, 0x38($29)\n"
    "ld $2, 0x10($29)\n"
    ".word 0x10400285 /* beqz $2, .L0041A798: raw word */\n"
    "lw $4, 0x8($29)\n"
    ".word 0x18400025 /* blez $2, .L00419E20: raw word */\n"
    "slti $2, $2, 0x17\n"
    ".word 0x10400009 /* beqz $2, .L00419DB8: raw word */\n"
    "ld $4, 0x10($29)\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $5, $17, $0\n"
    "dsll32 $3, $4, 0\n"
    "dsra32 $3, $3, 0\n"
    "sll $3, $3, 3\n"
    ".word 0x10000017 /* b .L00419E10: raw word */\n"
    "addu $3, $3, $2\n"
    ".L00419DB8:\n"
    "addiu $3, $0, 0xF\n"
    "subu $7, $3, $20\n"
    "ld $3, 0x10($29)\n"
    "addiu $2, $7, 0x16\n"
    "slt $2, $2, $3\n"
    ".word 0x14400024 /* bnez $2, .L00419E60: raw word */\n"
    "subu $2, $20, $19\n"
    "lui $16, %hi(D_0049A8F8)\n"
    "sll $2, $7, 3\n"
    "addiu $16, $16, %lo(D_0049A8F8)\n"
    "dsubu $3, $3, $7\n"
    "addu $2, $2, $16\n"
    "daddu $5, $17, $0\n"
    "ld $4, 0x0($2)\n"
    "jal func_00411FD8\n"
    "sd $3, 0x10($29)\n"
    "ld $4, 0x10($29)\n"
    "daddu $5, $2, $0\n"
    "dsll32 $3, $4, 0\n"
    "dsra32 $3, $3, 0\n"
    "sll $3, $3, 3\n"
    "addu $3, $3, $16\n"
    ".L00419E10:\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($3)\n"
    ".word 0x1000025E /* b .L0041A794: raw word */\n"
    "daddu $17, $2, $0\n"
    ".L00419E20:\n"
    "ld $7, 0x10($29)\n"
    "slti $2, $7, -0x16\n"
    ".word 0x1440000D /* bnez $2, .L00419E60: raw word */\n"
    "subu $2, $20, $19\n"
    "dsll32 $3, $7, 0\n"
    "dsra32 $3, $3, 0\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "sll $3, $3, 3\n"
    "subu $2, $2, $3\n"
    "daddu $4, $17, $0\n"
    "jal func_00412280\n"
    "ld $5, 0x0($2)\n"
    ".word 0x1000024F /* b .L0041A794: raw word */\n"
    "daddu $17, $2, $0\n"
    ".L00419E5C:\n"
    "subu $2, $20, $19\n"
    ".L00419E60:\n"
    "addu $16, $16, $2\n"
    ".word 0x1A000050 /* blez $16, .L00419FA8: raw word */\n"
    "andi $7, $16, 0xF\n"
    ".word 0x10E00008 /* beqz $7, .L00419E90: raw word */\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $7, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $5, $17, $0\n"
    "addu $3, $3, $2\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($3)\n"
    "daddu $17, $2, $0\n"
    ".L00419E90:\n"
    "addiu $2, $0, -0x10\n"
    "and $16, $16, $2\n"
    ".word 0x12000090 /* beqz $16, .L0041A0DC: raw word */\n"
    "slti $2, $16, 0x135\n"
    ".word 0x54400009 /* bnel $2, $0, .L00419EC8: raw word */\n"
    "sra $16, $16, 4\n"
    ".L00419EA8:\n"
    "addiu $2, $0, 0x22\n"
    ".L00419EAC:\n"
    "lui $3, %hi(D_0049A898)\n"
    "sw $2, 0x0($23)\n"
    "lw $2, 0x38($29)\n"
    ".word 0x14400227 /* bnez $2, .L0041A758: raw word */\n"
    "ld $17, %lo(D_0049A898)($3)\n"
    ".word 0x10000235 /* b .L0041A798: raw word */\n"
    "lw $4, 0x8($29)\n"
    ".L00419EC8:\n"
    ".word 0x12000084 /* beqz $16, .L0041A0DC: raw word */\n"
    "daddu $19, $0, $0\n"
    "slti $2, $16, 0x2\n"
    ".word 0x1440000E /* bnez $2, .L00419F10: raw word */\n"
    "lui $22, %hi(D_0049A9C0)\n"
    "addiu $18, $22, %lo(D_0049A9C0)\n"
    ".L00419EE0:\n"
    "andi $2, $16, 0x1\n"
    ".word 0x50400006 /* beql $2, $0, .L00419F00: raw word */\n"
    "sra $16, $16, 1\n"
    "ld $4, 0x0($18)\n"
    "jal func_00411FD8\n"
    "daddu $5, $17, $0\n"
    "daddu $17, $2, $0\n"
    "sra $16, $16, 1\n"
    ".L00419F00:\n"
    "addiu $18, $18, 0x8\n"
    "slti $2, $16, 0x2\n"
    ".word 0x1040FFF5 /* beqz $2, .L00419EE0: raw word */\n"
    "addiu $19, $19, 0x1\n"
    ".L00419F10:\n"
    "addiu $4, $22, %lo(D_0049A9C0)\n"
    "dsra32 $5, $17, 0\n"
    "lui $2, (0xFCB00000 >> 16)\n"
    "sll $3, $19, 3\n"
    "addu $3, $3, $4\n"
    "addu $5, $5, $2\n"
    "addiu $16, $0, -0x1\n"
    "dsrl32 $16, $16, 0\n"
    "ld $4, 0x0($3)\n"
    "dsll32 $5, $5, 0\n"
    "and $17, $17, $16\n"
    "jal func_00411FD8\n"
    "or $5, $17, $5\n"
    "daddu $17, $2, $0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "dsra32 $4, $17, 0\n"
    "lui $2, (0x7CA00000 >> 16)\n"
    "and $18, $4, $3\n"
    "sltu $2, $2, $18\n"
    ".word 0x1440FFD3 /* bnez $2, .L00419EAC: raw word */\n"
    "addiu $2, $0, 0x22\n"
    "lui $2, (0x7C900000 >> 16)\n"
    "sltu $2, $2, $18\n"
    ".word 0x10400009 /* beqz $2, .L00419F94: raw word */\n"
    "lui $2, (0x3500000 >> 16)\n"
    "and $17, $17, $16\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFE\n"
    "dsll $2, $2, 31\n"
    "or $17, $17, $2\n"
    ".word 0x10000053 /* b .L0041A0DC: raw word */\n"
    "or $17, $17, $16\n"
    ".L00419F94:\n"
    "and $17, $17, $16\n"
    "addu $2, $4, $2\n"
    "dsll32 $2, $2, 0\n"
    ".word 0x1000004E /* b .L0041A0DC: raw word */\n"
    "or $17, $17, $2\n"
    ".L00419FA8:\n"
    ".word 0x0601004D /* bgez $16, .L0041A0E0: raw word */\n"
    "lw $5, 0x18($29)\n"
    "negu $16, $16\n"
    "andi $7, $16, 0xF\n"
    ".word 0x10E00008 /* beqz $7, .L00419FDC: raw word */\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $7, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $4, $17, $0\n"
    "addu $3, $3, $2\n"
    "jal func_00412280\n"
    "ld $5, 0x0($3)\n"
    "daddu $17, $2, $0\n"
    ".L00419FDC:\n"
    "addiu $2, $0, -0x10\n"
    "and $16, $16, $2\n"
    ".word 0x1200003D /* beqz $16, .L0041A0DC: raw word */\n"
    "sra $16, $16, 4\n"
    "slti $2, $16, 0x20\n"
    ".word 0x1040002C /* beqz $2, .L0041A0A4: raw word */\n"
    "daddu $19, $0, $0\n"
    "slti $2, $16, 0x2\n"
    ".word 0x1440000E /* bnez $2, .L0041A038: raw word */\n"
    "lui $22, %hi(D_0049A9E8)\n"
    "addiu $18, $22, %lo(D_0049A9E8)\n"
    ".L0041A008:\n"
    "andi $2, $16, 0x1\n"
    ".word 0x50400006 /* beql $2, $0, .L0041A028: raw word */\n"
    "sra $16, $16, 1\n"
    "ld $4, 0x0($18)\n"
    "jal func_00411FD8\n"
    "daddu $5, $17, $0\n"
    "daddu $17, $2, $0\n"
    "sra $16, $16, 1\n"
    ".L0041A028:\n"
    "addiu $18, $18, 0x8\n"
    "slti $2, $16, 0x2\n"
    ".word 0x1040FFF5 /* beqz $2, .L0041A008: raw word */\n"
    "addiu $19, $19, 0x1\n"
    ".L0041A038:\n"
    "addiu $2, $22, %lo(D_0049A9E8)\n"
    "sll $3, $19, 3\n"
    "addu $3, $3, $2\n"
    "daddu $5, $17, $0\n"
    "ld $16, 0x0($3)\n"
    "daddu $22, $17, $0\n"
    "daddu $18, $0, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $18, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $17, $2, $0\n"
    ".word 0x1440001C /* bnez $2, .L0041A0E0: raw word */\n"
    "lw $5, 0x18($29)\n"
    "daddu $4, $22, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $5, $18, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $17, $2, $0\n"
    ".word 0x1440000F /* bnez $2, .L0041A0DC: raw word */\n"
    "addiu $17, $0, 0x1\n"
    ".L0041A0A4:\n"
    "addiu $2, $0, 0x22\n"
    ".L0041A0A8:\n"
    "sw $2, 0x0($23)\n"
    "lw $3, 0x38($29)\n"
    ".word 0x146001A9 /* bnez $3, .L0041A758: raw word */\n"
    "daddu $17, $0, $0\n"
    ".word 0x100001B7 /* b .L0041A798: raw word */\n"
    "lw $4, 0x8($29)\n"
    ".L0041A0C0:\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    ".word 0x100001A0 /* b .L0041A758: raw word */\n"
    "daddu $17, $2, $0\n"
    ".L0041A0DC:\n"
    "lw $5, 0x18($29)\n"
    ".L0041A0E0:\n"
    "daddu $6, $30, $0\n"
    "lw $8, 0x20($29)\n"
    "daddu $7, $20, $0\n"
    "jal func_004206F8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x38($29)\n"
    "ld $4, 0x10($29)\n"
    "dsll32 $4, $4, 0\n"
    "dsra32 $4, $4, 0\n"
    "addiu $7, $29, 0x4\n"
    "sw $4, 0x44($29)\n"
    ".word 0x1000011D /* b .L0041A584: raw word */\n"
    "sw $7, 0x48($29)\n"
    "nop\n"
    ".L0041A118:\n"
    "daddu $4, $23, $0\n"
    "jal func_00420CC8\n"
    "addiu $6, $0, 0x1\n"
    "sw $2, 0x40($29)\n"
    "lw $5, 0x3C($29)\n"
    "jal func_00420E28\n"
    "daddu $4, $2, $0\n"
    ".word 0x1C40001E /* bgtz $2, .L0041A1B0: raw word */\n"
    "lw $5, 0x30($29)\n"
    ".word 0x10000187 /* b .L0041A75C: raw word */\n"
    "nop\n"
    ".L0041A144:\n"
    ".word 0x14E0003F /* bnez $7, .L0041A244: raw word */\n"
    "lw $4, 0x40($29)\n"
    ".word 0x12800013 /* beqz $20, .L0041A19C: raw word */\n"
    "nop\n"
    "addiu $3, $0, -0x1\n"
    "dsrl $3, $3, 12\n"
    "and $2, $17, $3\n"
    ".word 0x14430024 /* bne $2, $3, .L0041A1F4: raw word */\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "dsra32 $2, $17, 0\n"
    "and $2, $2, $3\n"
    "lui $4, (0x100000 >> 16)\n"
    "addiu $3, $0, -0x1\n"
    "dsrl32 $3, $3, 0\n"
    "daddu $2, $2, $4\n"
    "and $17, $17, $3\n"
    "dsll32 $2, $2, 0\n"
    "or $17, $17, $2\n"
    "addiu $3, $0, -0x1\n"
    "dsll32 $3, $3, 0\n"
    ".word 0x10000170 /* b .L0041A758: raw word */\n"
    "and $17, $17, $3\n"
    ".L0041A19C:\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    ".word 0x14400012 /* bnez $2, .L0041A1F4: raw word */\n"
    "nop\n"
    ".L0041A1B0:\n"
    "dsra32 $2, $17, 0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "and $2, $2, $3\n"
    "lui $4, (0xFFF00000 >> 16)\n"
    "addu $2, $2, $4\n"
    "addiu $5, $0, -0x1\n"
    "dsrl32 $5, $5, 0\n"
    "dsll32 $2, $2, 0\n"
    "ori $3, $0, 0xFFFF\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0xF000\n"
    "dsll $3, $3, 20\n"
    "or $3, $3, $2\n"
    "and $17, $17, $5\n"
    "or $17, $17, $3\n"
    ".word 0x1000015A /* b .L0041A758: raw word */\n"
    "or $17, $17, $5\n"
    ".L0041A1F4:\n"
    "dsll32 $2, $17, 0\n"
    "dsra32 $2, $2, 0\n"
    "andi $2, $2, 0x1\n"
    ".word 0x10400156 /* beqz $2, .L0041A75C: raw word */\n"
    "lw $5, 0x30($29)\n"
    ".word 0x1680FFAD /* bnez $20, .L0041A0C0: raw word */\n"
    "nop\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $17, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $5, $0, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $17, $2, $0\n"
    ".word 0x1040FF9B /* beqz $2, .L0041A0A4: raw word */\n"
    "lw $5, 0x30($29)\n"
    ".word 0x10000147 /* b .L0041A75C: raw word */\n"
    "nop\n"
    ".L0041A244:\n"
    "jal func_00421400\n"
    "lw $5, 0x3C($29)\n"
    "daddu $16, $2, $0\n"
    "ori $5, $0, 0x8000\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x1C400024 /* bgtz $2, .L0041A2F4: raw word */\n"
    "nop\n"
    ".word 0x12800005 /* beqz $20, .L0041A280: raw word */\n"
    "nop\n"
    "ori $16, $0, 0xFFC0\n"
    "dsll32 $16, $16, 14\n"
    ".word 0x10000029 /* b .L0041A320: raw word */\n"
    "daddu $18, $16, $0\n"
    ".L0041A280:\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    ".word 0x10400009 /* beqz $2, .L0041A2B4: raw word */\n"
    "addiu $2, $0, 0x1\n"
    ".word 0x1222FF84 /* beq $17, $2, .L0041A0A8: raw word */\n"
    "addiu $2, $0, 0x22\n"
    "ori $16, $0, 0xFFC0\n"
    "dsll32 $16, $16, 14\n"
    "ori $18, $0, 0xBFF0\n"
    "dsll32 $18, $18, 16\n"
    ".word 0x1000001C /* b .L0041A320: raw word */\n"
    "nop\n"
    ".L0041A2B4:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x04410005 /* bgez $2, .L0041A2DC: raw word */\n"
    "daddu $4, $0, $0\n"
    "ori $16, $0, 0xFF80\n"
    "dsll32 $16, $16, 14\n"
    ".word 0x1000000F /* b .L0041A314: raw word */\n"
    "nop\n"
    ".L0041A2DC:\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $16, $0\n"
    ".word 0x10000008 /* b .L0041A310: raw word */\n"
    "daddu $16, $2, $0\n"
    ".L0041A2F4:\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $16, $0\n"
    "daddu $16, $2, $0\n"
    ".word 0x16800005 /* bnez $20, .L0041A320: raw word */\n"
    "daddu $18, $16, $0\n"
    ".L0041A310:\n"
    "daddu $4, $0, $0\n"
    ".L0041A314:\n"
    "jal func_00411F70\n"
    "daddu $5, $16, $0\n"
    "daddu $18, $2, $0\n"
    ".L0041A320:\n"
    "dsra32 $3, $17, 0\n"
    "lui $30, (0x7FF00000 >> 16)\n"
    "and $2, $3, $30\n"
    "sw $2, 0x20($29)\n"
    "lui $2, (0x7FE00000 >> 16)\n"
    "lw $4, 0x20($29)\n"
    ".word 0x1482002E /* bne $4, $2, .L0041A3F4: raw word */\n"
    "lw $7, 0x20($29)\n"
    "lui $2, (0xFCB00000 >> 16)\n"
    "daddu $22, $17, $0\n"
    "addu $2, $3, $2\n"
    "addiu $19, $0, -0x1\n"
    "dsrl32 $19, $19, 0\n"
    "dsll32 $2, $2, 0\n"
    "and $17, $17, $19\n"
    "or $17, $17, $2\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $17, $2, $0\n"
    "lui $3, (0x7C9FFFFF >> 16)\n"
    "dsra32 $4, $17, 0\n"
    "ori $3, $3, (0x7C9FFFFF & 0xFFFF)\n"
    "and $2, $4, $30\n"
    "sltu $3, $3, $2\n"
    ".word 0x10600011 /* beqz $3, .L0041A3E0: raw word */\n"
    "lui $2, (0x3500000 >> 16)\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll $2, $2, 15\n"
    "ori $2, $2, 0x7FFF\n"
    ".word 0x12C2FEBA /* beq $22, $2, .L00419EA8: raw word */\n"
    "and $17, $17, $19\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFE\n"
    "dsll $2, $2, 31\n"
    "or $17, $17, $2\n"
    ".word 0x1000005E /* b .L0041A554: raw word */\n"
    "or $17, $17, $19\n"
    ".L0041A3E0:\n"
    "and $17, $17, $19\n"
    "addu $2, $4, $2\n"
    "dsll32 $2, $2, 0\n"
    ".word 0x10000022 /* b .L0041A478: raw word */\n"
    "or $17, $17, $2\n"
    ".L0041A3F4:\n"
    "lui $2, (0x3400000 >> 16)\n"
    "sltu $2, $2, $7\n"
    ".word 0x14400015 /* bnez $2, .L0041A454: raw word */\n"
    "nop\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x0440000F /* bltz $2, .L0041A454: raw word */\n"
    "nop\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411F18\n"
    "daddu $4, $16, $0\n"
    "jal func_00412608\n"
    "daddu $4, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $2, $0\n"
    ".word 0x16800005 /* bnez $20, .L0041A454: raw word */\n"
    "daddu $18, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    "daddu $18, $2, $0\n"
    ".L0041A454:\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $17, $2, $0\n"
    ".L0041A478:\n"
    "lw $3, 0x20($29)\n"
    "dsra32 $4, $17, 0\n"
    "dsll32 $2, $3, 0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "dsrl32 $2, $2, 0\n"
    "and $18, $4, $3\n"
    ".word 0x14520031 /* bne $2, $18, .L0041A558: raw word */\n"
    "lw $5, 0x30($29)\n"
    "jal func_0042D320\n"
    "daddu $4, $16, $0\n"
    "jal func_00411438\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    ".word 0x16800006 /* bnez $20, .L0041A4D0: raw word */\n"
    "daddu $16, $2, $0\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    ".word 0x10400017 /* beqz $2, .L0041A528: raw word */\n"
    "nop\n"
    ".L0041A4D0:\n"
    "ori $5, $0, 0xFF7F\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFFFE\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xA501\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1595\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x04400099 /* bltz $2, .L0041A75C: raw word */\n"
    "lw $5, 0x30($29)\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 0\n"
    "ori $5, $5, 0xD6BF\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x2535\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x1C40008F /* bgtz $2, .L0041A758: raw word */\n"
    "lw $5, 0x30($29)\n"
    ".word 0x1000000D /* b .L0041A558: raw word */\n"
    "nop\n"
    ".L0041A528:\n"
    "ori $5, $0, 0xFF3F\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFFFE\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xA501\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1595\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x04420083 /* bltzl $2, .L0041A75C: raw word */\n"
    "lw $5, 0x30($29)\n"
    ".L0041A554:\n"
    "lw $5, 0x30($29)\n"
    ".L0041A558:\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x34($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x3C($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x40($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    ".L0041A584:\n"
    "lw $4, 0x38($29)\n"
    "lw $5, 0x4($4)\n"
    "jal func_00420510\n"
    "daddu $4, $23, $0\n"
    "lw $7, 0x38($29)\n"
    "lw $6, 0x10($7)\n"
    "addiu $5, $7, 0xC\n"
    "sw $2, 0x34($29)\n"
    "sll $6, $6, 2\n"
    "addiu $4, $2, 0xC\n"
    "jal func_0041605C\n"
    "addiu $6, $6, 0x8\n"
    "lw $7, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00421280\n"
    "daddu $6, $29, $0\n"
    "sw $2, 0x30($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420978\n"
    "addiu $5, $0, 0x1\n"
    "sw $2, 0x3C($29)\n"
    "ld $2, 0x10($29)\n"
    ".word 0x04400005 /* bltz $2, .L0041A5F8: raw word */\n"
    "lw $16, 0x44($29)\n"
    "daddu $6, $0, $0\n"
    "daddu $18, $0, $0\n"
    ".word 0x10000006 /* b .L0041A60C: raw word */\n"
    "daddu $22, $16, $0\n"
    ".L0041A5F8:\n"
    "lw $3, 0x44($29)\n"
    "daddu $22, $0, $0\n"
    "daddu $16, $0, $0\n"
    "negu $18, $3\n"
    "daddu $6, $18, $0\n"
    ".L0041A60C:\n"
    "lw $4, 0x0($29)\n"
    ".word 0x04820002 /* bltzl $4, .L0041A61C: raw word */\n"
    "subu $16, $16, $4\n"
    "addu $18, $18, $4\n"
    ".L0041A61C:\n"
    "lw $5, 0x4($29)\n"
    "addu $2, $4, $5\n"
    "addiu $7, $2, -0x1\n"
    "slti $3, $7, -0x3FE\n"
    ".word 0x10600003 /* beqz $3, .L0041A63C: raw word */\n"
    "daddu $20, $18, $0\n"
    ".word 0x10000003 /* b .L0041A644: raw word */\n"
    "addiu $19, $4, 0x433\n"
    ".L0041A63C:\n"
    "addiu $2, $0, 0x36\n"
    "subu $19, $2, $5\n"
    ".L0041A644:\n"
    "addu $7, $16, $19\n"
    "addu $18, $18, $19\n"
    "daddu $16, $7, $0\n"
    "slt $2, $18, $7\n"
    "movn $7, $18, $2\n"
    "slt $3, $20, $7\n"
    "movn $7, $20, $3\n"
    ".word 0x18E00004 /* blez $7, .L0041A674: raw word */\n"
    "nop\n"
    "subu $20, $20, $7\n"
    "subu $18, $18, $7\n"
    "subu $16, $16, $7\n"
    ".L0041A674:\n"
    ".word 0x18C0000C /* blez $6, .L0041A6A8: raw word */\n"
    "lw $5, 0x3C($29)\n"
    "jal func_00420BC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x3C($29)\n"
    "daddu $4, $23, $0\n"
    "lw $6, 0x30($29)\n"
    "jal func_004209B0\n"
    "daddu $5, $2, $0\n"
    "lw $5, 0x30($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_004205B8\n"
    "sw $2, 0x30($29)\n"
    ".L0041A6A8:\n"
    ".word 0x1A400005 /* blez $18, .L0041A6C0: raw word */\n"
    "lw $5, 0x30($29)\n"
    "daddu $6, $18, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x30($29)\n"
    ".L0041A6C0:\n"
    ".word 0x1AC00005 /* blez $22, .L0041A6D8: raw word */\n"
    "lw $5, 0x34($29)\n"
    "daddu $6, $22, $0\n"
    "jal func_00420BC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x34($29)\n"
    ".L0041A6D8:\n"
    ".word 0x1A000005 /* blez $16, .L0041A6F0: raw word */\n"
    "lw $5, 0x34($29)\n"
    "daddu $6, $16, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x34($29)\n"
    ".L0041A6F0:\n"
    ".word 0x1A800005 /* blez $20, .L0041A708: raw word */\n"
    "lw $5, 0x3C($29)\n"
    "daddu $6, $20, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x3C($29)\n"
    ".L0041A708:\n"
    "lw $5, 0x30($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420E90\n"
    "lw $6, 0x34($29)\n"
    "sw $2, 0x40($29)\n"
    "lw $5, 0x3C($29)\n"
    "lw $20, 0xC($2)\n"
    "daddu $4, $2, $0\n"
    "jal func_00420E28\n"
    "sw $0, 0xC($4)\n"
    "daddu $7, $2, $0\n"
    ".word 0x04E1FE83 /* bgez $7, .L0041A144: raw word */\n"
    "nop\n"
    ".word 0x16800007 /* bnez $20, .L0041A75C: raw word */\n"
    "lw $5, 0x30($29)\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    ".word 0x1040FE71 /* beqz $2, .L0041A118: raw word */\n"
    "lw $5, 0x40($29)\n"
    ".L0041A758:\n"
    "lw $5, 0x30($29)\n"
    ".L0041A75C:\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x34($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x3C($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x38($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $5, 0x40($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    ".L0041A794:\n"
    "lw $4, 0x8($29)\n"
    ".L0041A798:\n"
    ".word 0x54800001 /* bnel $4, $0, .L0041A7A0: raw word */\n"
    "sw $21, 0x0($4)\n"
    ".L0041A7A0:\n"
    "lw $7, 0xC($29)\n"
    ".word 0x10E00004 /* beqz $7, .L0041A7B8: raw word */\n"
    "daddu $2, $17, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    ".L0041A7B8:\n"
    "lq $16, 0xE0($29)\n"
    "lq $17, 0xD0($29)\n"
    "lq $18, 0xC0($29)\n"
    "lq $19, 0xB0($29)\n"
    "lq $20, 0xA0($29)\n"
    "lq $21, 0x90($29)\n"
    "lq $22, 0x80($29)\n"
    "lq $23, 0x70($29)\n"
    "lq $30, 0x60($29)\n"
    "ld $31, 0x50($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xF0\n"
    ".end func_004198D8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A7E8);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_004198D8(int, int, int);
void func_0041A7E8(int a, int b) {
    func_004198D8(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A818);
#ifdef SKIP_ASM
extern void func_004127A8(int);
void func_0041A818(void) {
    func_004127A8(((int (*)(void))func_0041A7E8)());
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041A840);
#ifdef SKIP_ASM
extern char D_00499C81[];
extern long func_00411538_div(long, long) __asm__("func_00411538");
extern long func_004114D0_mul(long, long) __asm__("func_004114D0");
extern long func_0042DAD8_mod(long, long) __asm__("func_0042DAD8");
#define XCT(c) (D_00499C81[(int)(c)])
unsigned long func_0041A840_(int *ptr, char *nptr, char **endptr, int base) __asm__("func_0041A840");
unsigned long func_0041A840_(int *ptr, char *nptr, char **endptr, int base) {
    char *s = nptr;
    unsigned long acc, cutoff;
    int c, neg = 0, any, cutlim;
    do {
        c = *s++;
    } while (XCT(c) & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = func_00411538_div(-1, base);
    cutlim = func_0042DAD8_mod(-1, base);
    for (acc = 0, any = 0;; c = *s++) {
        if (XCT(c) & 4)
            c -= '0';
        else if (XCT(c) & 3)
            c -= (XCT(c) & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc = func_004114D0_mul(acc, base);
            acc += c;
        }
    }
    if (any < 0) {
        acc = -1;
        *ptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? s - 1 : nptr;
    return acc;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AA50);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041A840(int, int, int, int);
void func_0041AA50(int a, int b, int c) {
    func_0041A840(D_00454944, a, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AA88);
#ifdef SKIP_ASM
int func_0041AA88(char *a, char *b) {
    while (*a && func_0041EA18(*a) == func_0041EA18(*b)) {
        a++;
        b++;
    }
    return func_0041EA18((unsigned char)*a) - func_0041EA18((unsigned char)*b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AB08);
#ifdef SKIP_ASM
int func_0041AB08(char *s1, char *s2) {
    char *s = s1;
    char *c;
    while (*s1) {
        for (c = s2; *c; c++)
            if (*s1 == *c)
                break;
        if (*c)
            break;
        s1++;
    }
    return s1 - s;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AB78);
#ifdef SKIP_ASM
extern int func_0041EA18(int);
int func_0041AB78(char *s1, char *s2, unsigned n) {
    if (n == 0)
        return 0;
    while (n-- != 0 && func_0041EA18(*s1) == func_0041EA18(*s2)) {
        if (n == 0 || *s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return func_0041EA18(*(unsigned char *)s1) - func_0041EA18(*(unsigned char *)s2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AC40);
#ifdef SKIP_ASM
char *func_0041AC40(char *s, char *accept) {
    char *p;
    if (*s == 0)
        return 0;
    for (; *s; s++) {
        for (p = accept; *p && *s != *p; p++)
            ;
        if (*p)
            break;
    }
    return *p ? s : 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041ACC0);
#ifdef SKIP_ASM
char *func_0041ACC0(char *s, char c) {
    char *r = 0;
    while (*s) {
        if (*s == c) r = s;
        s++;
    }
    return *s == c ? s : r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AD10);
#ifdef SKIP_ASM
int func_0041AD10(char *s1, char *s2) {
    char *s = s1;
    char *c;
    while (*s1) {
        for (c = s2; *c; c++)
            if (*s1 == *c)
                break;
        if (*c == 0)
            break;
        s1++;
    }
    return s1 - s;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AD80);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041AD80\n.ent func_0041AD80\nfunc_0041AD80:\n"
    "lb $2, 0x0($4)\n"
    ".word 0x14400006 /* bnez $2, .L0041ADA0: raw word */\n"
    "lb $3, 0x0($5)\n"
    "daddu $2, $0, $0\n"
    "jr $31\n"
    "movz $2, $4, $3\n"
    ".L0041AD98:\n"
    "jr $31\n"
    "daddu $2, $4, $0\n"
    ".L0041ADA0:\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1060FFFA /* beqz $3, .L0041AD98: raw word */\n"
    "daddu $7, $0, $0\n"
    "lb $2, 0x0($4)\n"
    ".word 0x5462000B /* bnel $3, $2, .L0041ADE8: raw word */\n"
    "addiu $4, $4, 0x1\n"
    "addiu $7, $7, 0x1\n"
    "nop\n"
    ".L0041ADC8:\n"
    "addu $2, $5, $7\n"
    "lb $6, 0x0($2)\n"
    ".word 0x10C0FFF1 /* beqz $6, .L0041AD98: raw word */\n"
    "addu $2, $4, $7\n"
    "lb $3, 0x0($2)\n"
    ".word 0x50C3FFFA /* beql $6, $3, .L0041ADC8: raw word */\n"
    "addiu $7, $7, 0x1\n"
    "addiu $4, $4, 0x1\n"
    ".L0041ADE8:\n"
    "lb $2, 0x0($4)\n"
    ".word 0x5440FFEC /* bnel $2, $0, .L0041ADA0: raw word */\n"
    "lb $3, 0x0($5)\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".end func_0041AD80\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AE00);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041AE00\n.ent func_0041AE00\nfunc_0041AE00:\n"
    ".word 0x18A00019 /* blez $5, .L0041AE68: raw word */\n"
    "addiu $5, $5, -0x1\n"
    "addu $3, $4, $5\n"
    "lb $2, 0x0($3)\n"
    "slti $2, $2, 0x35\n"
    ".word 0x14400014 /* bnez $2, .L0041AE68: raw word */\n"
    "addiu $7, $0, 0x30\n"
    "addiu $6, $0, 0x39\n"
    "sb $7, 0x0($3)\n"
    "nop\n"
    ".L0041AE28:\n"
    "addiu $5, $5, -0x1\n"
    ".word 0x18A00005 /* blez $5, .L0041AE44: raw word */\n"
    "addiu $3, $3, -0x1\n"
    "lb $2, 0x0($3)\n"
    "nop\n"
    ".word 0x5046FFFA /* beql $2, $6, .L0041AE28: raw word */\n"
    "sb $7, 0x0($3)\n"
    ".L0041AE44:\n"
    "addu $4, $4, $5\n"
    "addiu $3, $0, 0x39\n"
    "lb $2, 0x0($4)\n"
    ".word 0x14430003 /* bne $2, $3, .L0041AE60: raw word */\n"
    "lbu $5, 0x0($4)\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".L0041AE60:\n"
    "addiu $2, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    ".L0041AE68:\n"
    "jr $31\n"
    "addiu $2, $0, 0x1\n"
    ".end func_0041AE00\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AE70);
#ifdef SKIP_ASM
char *func_0041AE70(char *s) {
    int i, j;
    char t;
    j = 0;
    while (s[j])
        j++;
    j--;
    for (i = 0; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
    return s;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AEE8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041AEE8\n.ent func_0041AEE8\nfunc_0041AEE8:\n"
    "addiu $29, $29, -0x10\n"
    "daddu $9, $5, $0\n"
    "srl $10, $4, 31\n"
    ".word 0x11400004 /* beqz $10, .L0041AF08: raw word */\n"
    "sd $31, 0x0($29)\n"
    "negu $3, $4\n"
    "xori $2, $6, 0xA\n"
    "movz $4, $3, $2\n"
    ".L0041AF08:\n"
    "lui $2, %hi(D_00454CB0)\n"
    "daddu $7, $0, $0\n"
    "addiu $11, $2, %lo(D_00454CB0)\n"
    "daddu $8, $0, $0\n"
    "divu $0, $4, $6\n"
    "nop\n"
    ".L0041AF20:\n"
    ".word 0x50C80001 /* beql $6, $8, .L0041AF28: raw word */\n"
    "break 0, 7\n"
    ".L0041AF28:\n"
    "addu $5, $9, $7\n"
    "addiu $7, $7, 0x1\n"
    "mfhi $3\n"
    "mflo $4\n"
    "addu $3, $3, $11\n"
    "lbu $2, 0x0($3)\n"
    "sb $2, 0x0($5)\n"
    ".word 0x50C80001 /* beql $6, $8, .L0041AF4C: raw word */\n"
    "break 0, 7\n"
    ".L0041AF4C:\n"
    ".word 0x5480FFF4 /* bnel $4, $0, .L0041AF20: raw word */\n"
    "divu $0, $4, $6\n"
    ".word 0x11400004 /* beqz $10, .L0041AF68: raw word */\n"
    "addu $3, $9, $7\n"
    "addiu $2, $0, 0x2D\n"
    "sb $2, 0x0($3)\n"
    "addiu $7, $7, 0x1\n"
    ".L0041AF68:\n"
    "addu $2, $9, $7\n"
    "daddu $4, $9, $0\n"
    "jal func_0041AE70\n"
    "sb $0, 0x0($2)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x10\n"
    ".end func_0041AEE8\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041AF88);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041AF88\n.ent func_0041AF88\nfunc_0041AF88:\n"
    "addiu $29, $29, -0xB0\n"
    "sll $6, $6, 24\n"
    "sq $16, 0xA0($29)\n"
    "sra $6, $6, 24\n"
    "sq $18, 0x80($29)\n"
    "sw $5, 0x0($29)\n"
    "daddu $18, $4, $0\n"
    "sw $7, 0x8($29)\n"
    "sq $17, 0x90($29)\n"
    "sq $19, 0x70($29)\n"
    "sq $20, 0x60($29)\n"
    "sq $21, 0x50($29)\n"
    "sq $22, 0x40($29)\n"
    "sq $23, 0x30($29)\n"
    "sq $30, 0x20($29)\n"
    "sd $31, 0x10($29)\n"
    "sw $6, 0x4($29)\n"
    "daddu $2, $18, $0\n"
    "dsll32 $6, $2, 0\n"
    "dsra32 $6, $6, 0\n"
    "dsra32 $2, $2, 0\n"
    "lui $3, (0xFFFFF >> 16)\n"
    "srl $4, $2, 20\n"
    "ori $3, $3, (0xFFFFF & 0xFFFF)\n"
    "andi $5, $4, 0x800\n"
    "and $3, $2, $3\n"
    "andi $4, $4, 0x7FF\n"
    "addiu $2, $0, 0x7FF\n"
    ".word 0x14820017 /* bne $4, $2, .L0041B058: raw word */\n"
    "daddu $16, $8, $0\n"
    ".word 0x14600011 /* bnez $3, .L0041B048: raw word */\n"
    "lui $2, %hi(D_0049A310)\n"
    ".word 0x14C00010 /* bnez $6, .L0041B04C: raw word */\n"
    "lui $3, %hi(D_0052ADF0)\n"
    ".word 0x10A00009 /* beqz $5, .L0041B038: raw word */\n"
    "lui $3, %hi(D_0049A300)\n"
    "lui $2, %hi(D_0052ADF0)\n"
    "lw $5, %lo(D_0049A300)($3)\n"
    "addiu $4, $3, %lo(D_0049A300)\n"
    "lbu $6, 0x4($4)\n"
    "addiu $3, $2, %lo(D_0052ADF0)\n"
    "sw $5, %lo(D_0052ADF0)($2)\n"
    ".word 0x1000012F /* b .L0041B4F0: raw word */\n"
    "sb $6, 0x4($3)\n"
    ".L0041B038:\n"
    "lui $2, %hi(D_0049A308)\n"
    "lui $3, %hi(D_0052ADF0)\n"
    ".word 0x10000003 /* b .L0041B050: raw word */\n"
    "lw $4, %lo(D_0049A308)($2)\n"
    ".L0041B048:\n"
    "lui $3, %hi(D_0052ADF0)\n"
    ".L0041B04C:\n"
    "lw $4, %lo(D_0049A310)($2)\n"
    ".L0041B050:\n"
    ".word 0x10000127 /* b .L0041B4F0: raw word */\n"
    "sw $4, %lo(D_0052ADF0)($3)\n"
    ".L0041B058:\n"
    "lw $21, 0x0($29)\n"
    "daddu $20, $0, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x04410010 /* bgez $2, .L0041B0B0: raw word */\n"
    "lui $2, %hi(D_0052ADF0)\n"
    ".word 0x12000005 /* beqz $16, .L0041B08C: raw word */\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "addiu $2, $0, 0x2D\n"
    "sb $2, 0x0($16)\n"
    ".word 0x10000005 /* b .L0041B09C: raw word */\n"
    "addiu $22, $3, %lo(D_0052ADF0)\n"
    ".L0041B08C:\n"
    "addiu $3, $0, 0x2D\n"
    "addiu $4, $2, %lo(D_0052ADF0)\n"
    "sb $3, %lo(D_0052ADF0)($2)\n"
    "addiu $22, $4, 0x1\n"
    ".L0041B09C:\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    ".word 0x10000002 /* b .L0041B0B4: raw word */\n"
    "daddu $18, $2, $0\n"
    ".L0041B0B0:\n"
    "addiu $22, $2, %lo(D_0052ADF0)\n"
    ".L0041B0B4:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x04400037 /* bltz $2, .L0041B1A4: raw word */\n"
    "daddu $19, $20, $0\n"
    "ori $19, $0, 0x8048\n"
    "dsll32 $19, $19, 15\n"
    "jal func_0041ED60\n"
    "daddu $4, $18, $0\n"
    "daddu $17, $2, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $17, $0\n"
    "daddu $18, $2, $0\n"
    "slti $2, $20, 0xA3\n"
    "nop\n"
    ".L0041B0F8:\n"
    ".word 0x10400019 /* beqz $2, .L0041B160: raw word */\n"
    "daddu $5, $19, $0\n"
    "jal func_0041EF50\n"
    "daddu $4, $17, $0\n"
    "jal func_00412608\n"
    "daddu $4, $2, $0\n"
    "daddu $16, $2, $0\n"
    "addiu $3, $16, 0x30\n"
    "addu $2, $22, $20\n"
    "sb $3, 0x0($2)\n"
    "jal func_00412550\n"
    "daddu $4, $16, $0\n"
    "addiu $20, $20, 0x1\n"
    "daddu $4, $17, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412280\n"
    "daddu $5, $19, $0\n"
    "daddu $17, $2, $0\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $17, $0\n"
    ".word 0x0441FFE7 /* bgez $2, .L0041B0F8: raw word */\n"
    "slti $2, $20, 0xA3\n"
    ".L0041B160:\n"
    "addiu $7, $20, -0x1\n"
    ".word 0x18E0000E /* blez $7, .L0041B1A0: raw word */\n"
    "daddu $16, $0, $0\n"
    "addu $6, $7, $22\n"
    "daddu $5, $22, $0\n"
    "nop\n"
    ".L0041B178:\n"
    "lbu $2, 0x0($6)\n"
    "addiu $16, $16, 0x1\n"
    "lb $3, 0x0($5)\n"
    "addiu $7, $7, -0x1\n"
    "sb $2, 0x0($5)\n"
    "slt $4, $16, $7\n"
    "sb $3, 0x0($6)\n"
    "addiu $5, $5, 0x1\n"
    ".word 0x1480FFF7 /* bnez $4, .L0041B178: raw word */\n"
    "addiu $6, $6, -0x1\n"
    ".L0041B1A0:\n"
    "daddu $19, $20, $0\n"
    ".L0041B1A4:\n"
    ".word 0x16600026 /* bnez $19, .L0041B240: raw word */\n"
    "lw $3, 0x4($29)\n"
    "addiu $2, $0, 0x66\n"
    ".word 0x10620020 /* beq $3, $2, .L0041B234: raw word */\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x1040000F /* beqz $2, .L0041B200: raw word */\n"
    "nop\n"
    ".L0041B1C8:\n"
    "ori $5, $0, 0x8048\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "daddu $18, $2, $0\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x04410003 /* bgez $2, .L0041B1FC: raw word */\n"
    "slti $2, $19, -0x3FC\n"
    ".word 0x5040FFF4 /* beql $2, $0, .L0041B1C8: raw word */\n"
    "addiu $19, $19, -0x1\n"
    ".L0041B1FC:\n"
    "addiu $19, $19, -0x1\n"
    ".L0041B200:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x0440000B /* bltz $2, .L0041B240: raw word */\n"
    "lw $2, 0x0($29)\n"
    "daddu $4, $18, $0\n"
    "ori $5, $0, 0x8048\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00412280\n"
    "addiu $21, $2, 0x1\n"
    ".word 0x10000004 /* b .L0041B240: raw word */\n"
    "daddu $18, $2, $0\n"
    ".L0041B234:\n"
    "addiu $2, $0, 0x30\n"
    "addiu $20, $0, 0x1\n"
    "sb $2, 0x0($22)\n"
    ".L0041B240:\n"
    ".word 0x06610003 /* bgez $19, .L0041B250: raw word */\n"
    "lw $3, 0x4($29)\n"
    ".word 0x10000008 /* b .L0041B26C: raw word */\n"
    "daddu $17, $21, $0\n"
    ".L0041B250:\n"
    "addiu $2, $0, 0x66\n"
    ".word 0x14620005 /* bne $3, $2, .L0041B26C: raw word */\n"
    "addiu $17, $21, 0x1\n"
    "addiu $2, $0, 0x1\n"
    "slt $3, $0, $19\n"
    "movn $2, $19, $3\n"
    "addu $17, $21, $2\n"
    ".L0041B26C:\n"
    "ori $21, $0, 0xF240\n"
    "dsll32 $21, $21, 14\n"
    "addiu $30, $17, 0x1\n"
    "ori $23, $0, 0x8048\n"
    "dsll32 $23, $23, 15\n"
    ".L0041B280:\n"
    "daddu $5, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "daddu $18, $2, $0\n"
    "jal func_00412608\n"
    "daddu $4, $18, $0\n"
    "daddu $16, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $16, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $21, $0\n"
    "daddu $18, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $23, $0\n"
    "daddu $21, $2, $0\n"
    "slt $2, $20, $17\n"
    ".word 0x10400012 /* beqz $2, .L0041B314: raw word */\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $21, $0\n"
    ".word 0x0440000E /* bltz $2, .L0041B314: raw word */\n"
    "nop\n"
    "ori $4, $0, 0xFFC0\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x1C400005 /* bgtz $2, .L0041B314: raw word */\n"
    "addu $2, $22, $20\n"
    "addiu $3, $16, 0x30\n"
    "sb $3, 0x0($2)\n"
    ".word 0x1000FFDC /* b .L0041B280: raw word */\n"
    "addiu $20, $20, 0x1\n"
    ".L0041B314:\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    "slti $2, $2, 0x0\n"
    "addiu $3, $16, 0x1\n"
    "movz $16, $3, $2\n"
    "addu $4, $22, $20\n"
    "addiu $3, $16, 0x30\n"
    "addiu $20, $20, 0x1\n"
    "slt $2, $17, $20\n"
    ".word 0x1440000A /* bnez $2, .L0041B36C: raw word */\n"
    "sb $3, 0x0($4)\n"
    "addiu $4, $0, 0x30\n"
    "nop\n"
    ".L0041B350:\n"
    "addu $3, $22, $20\n"
    "addiu $20, $20, 0x1\n"
    "slt $2, $17, $20\n"
    "nop\n"
    "nop\n"
    ".word 0x1040FFFA /* beqz $2, .L0041B350: raw word */\n"
    "sb $4, 0x0($3)\n"
    ".L0041B36C:\n"
    "daddu $4, $22, $0\n"
    "jal func_0041AE00\n"
    "daddu $5, $30, $0\n"
    ".word 0x14400006 /* bnez $2, .L0041B394: raw word */\n"
    "lw $2, 0x0($29)\n"
    "addiu $2, $0, 0x31\n"
    "daddu $17, $30, $0\n"
    "sb $2, 0x0($22)\n"
    "addiu $19, $19, 0x1\n"
    "lw $2, 0x0($29)\n"
    ".L0041B394:\n"
    ".word 0x10400016 /* beqz $2, .L0041B3F0: raw word */\n"
    "lw $3, 0x4($29)\n"
    "addiu $2, $0, 0x66\n"
    ".word 0x14620003 /* bne $3, $2, .L0041B3B0: raw word */\n"
    "addiu $5, $0, 0x1\n"
    "slti $2, $19, 0x1\n"
    "movz $5, $19, $2\n"
    ".L0041B3B0:\n"
    "daddu $20, $17, $0\n"
    "slt $2, $5, $17\n"
    ".word 0x1040000A /* beqz $2, .L0041B3E4: raw word */\n"
    "addu $6, $22, $5\n"
    "addu $4, $17, $22\n"
    "nop\n"
    ".L0041B3C8:\n"
    "lbu $2, -0x1($4)\n"
    "addiu $20, $20, -0x1\n"
    "slt $3, $5, $20\n"
    "sb $2, 0x0($4)\n"
    "nop\n"
    ".word 0x1460FFFA /* bnez $3, .L0041B3C8: raw word */\n"
    "addiu $4, $4, -0x1\n"
    ".L0041B3E4:\n"
    "addiu $2, $0, 0x2E\n"
    ".word 0x10000002 /* b .L0041B3F4: raw word */\n"
    "sb $2, 0x0($6)\n"
    ".L0041B3F0:\n"
    "addiu $17, $17, -0x1\n"
    ".L0041B3F4:\n"
    "lw $2, 0x8($29)\n"
    ".word 0x10400016 /* beqz $2, .L0041B454: raw word */\n"
    "lw $3, 0x4($29)\n"
    ".word 0x1220000E /* beqz $17, .L0041B43C: raw word */\n"
    "addu $2, $22, $17\n"
    "addiu $4, $0, 0x30\n"
    "lb $3, 0x0($2)\n"
    ".word 0x5464000D /* bnel $3, $4, .L0041B448: raw word */\n"
    "addiu $4, $17, -0x1\n"
    "addiu $17, $17, -0x1\n"
    "nop\n"
    ".L0041B420:\n"
    ".word 0x12200006 /* beqz $17, .L0041B43C: raw word */\n"
    "addu $2, $22, $17\n"
    "lb $3, 0x0($2)\n"
    "nop\n"
    "nop\n"
    ".word 0x5064FFFA /* beql $3, $4, .L0041B420: raw word */\n"
    "addiu $17, $17, -0x1\n"
    ".L0041B43C:\n"
    "addu $2, $22, $17\n"
    "addiu $4, $17, -0x1\n"
    "lb $3, 0x0($2)\n"
    ".L0041B448:\n"
    "xori $3, $3, 0x2E\n"
    "movz $17, $4, $3\n"
    "lw $3, 0x4($29)\n"
    ".L0041B454:\n"
    "addiu $2, $0, 0x66\n"
    ".word 0x10620024 /* beq $3, $2, .L0041B4EC: raw word */\n"
    "addu $2, $17, $22\n"
    "addiu $17, $17, 0x1\n"
    "addu $2, $22, $17\n"
    ".word 0x0660000E /* bltz $19, .L0041B4A4: raw word */\n"
    "sb $3, 0x0($2)\n"
    "addiu $2, $19, -0x1\n"
    "addiu $17, $17, 0x1\n"
    "movn $19, $2, $19\n"
    "addu $4, $22, $17\n"
    "addiu $2, $0, 0x2B\n"
    "slti $3, $19, 0xA\n"
    ".word 0x10600011 /* beqz $3, .L0041B4D0: raw word */\n"
    "sb $2, 0x0($4)\n"
    "addiu $17, $17, 0x1\n"
    "addiu $3, $0, 0x30\n"
    "addu $2, $22, $17\n"
    ".word 0x1000000C /* b .L0041B4D0: raw word */\n"
    "sb $3, 0x0($2)\n"
    ".L0041B4A4:\n"
    "addiu $17, $17, 0x1\n"
    "addiu $2, $0, 0x2D\n"
    "addu $3, $22, $17\n"
    "slti $4, $19, -0x9\n"
    ".word 0x14800005 /* bnez $4, .L0041B4CC: raw word */\n"
    "sb $2, 0x0($3)\n"
    "addiu $17, $17, 0x1\n"
    "addiu $3, $0, 0x30\n"
    "addu $2, $22, $17\n"
    "sb $3, 0x0($2)\n"
    ".L0041B4CC:\n"
    "negu $19, $19\n"
    ".L0041B4D0:\n"
    "addiu $17, $17, 0x1\n"
    "daddu $4, $19, $0\n"
    "addu $5, $22, $17\n"
    "jal func_0041AEE8\n"
    "addiu $6, $0, 0xA\n"
    ".word 0x10000003 /* b .L0041B4F4: raw word */\n"
    "lui $3, %hi(D_0052ADF0)\n"
    ".L0041B4EC:\n"
    "sb $0, 0x1($2)\n"
    ".L0041B4F0:\n"
    "lui $3, %hi(D_0052ADF0)\n"
    ".L0041B4F4:\n"
    "addiu $2, $3, %lo(D_0052ADF0)\n"
    "lq $16, 0xA0($29)\n"
    "lq $17, 0x90($29)\n"
    "lq $18, 0x80($29)\n"
    "lq $19, 0x70($29)\n"
    "lq $20, 0x60($29)\n"
    "lq $21, 0x50($29)\n"
    "lq $22, 0x40($29)\n"
    "lq $23, 0x30($29)\n"
    "lq $30, 0x20($29)\n"
    "ld $31, 0x10($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xB0\n"
    ".end func_0041AF88\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B528);
#ifdef SKIP_ASM
extern void func_0041B550(int, int, int, int);
void func_0041B528(short *p) {
    func_0041B550(p[7], 0, 0, 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B550);
#ifdef SKIP_ASM
extern char *D_00454CDC;
extern int D_00454CD8;
extern char D_0052AE98[];
extern int func_00424368(int, int, int);
int func_0041B550_(int fd, char *buf, unsigned n, int mode) __asm__("func_0041B550");
int func_0041B550_(int fd, char *buf, unsigned n, int mode) {
    unsigned i;
    int r;
    if (mode == 1) {
        r = func_00424368(fd, (int)D_0052AE98, D_00454CD8);
        D_00454CD8 = 0;
        D_00454CDC = D_0052AE98;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_00454CDC = buf[i];
        D_00454CDC++;
        D_00454CD8++;
        if (D_00454CD8 >= 128) {
            r = func_00424368(fd, (int)D_0052AE98, D_00454CD8);
            D_00454CDC = D_0052AE98;
            D_00454CD8 = 0;
            if (r == 0)
                return 0;
        }
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B658);
#ifdef SKIP_ASM
extern int func_0041B728_f(int, int, char *, char *) __asm__("func_0041B728");
extern int func_0041CA70_i(int, int, char *, char *) __asm__("func_0041CA70");
int func_0041B658(int fp, int fmt, char *ap) {
    char *p = (char *)fmt;
    while (*p) {
        if (*p == '%' && p[1]) {
            p++;
            while (*p < 'A' && p[1])
                p++;
            switch (*p) {
            case 'E':
            case 'G':
            case 'L':
            case 'e':
            case 'f':
            case 'g':
                return func_0041B728_f(*(int *)(fp + 0x54), fp, (char *)fmt, ap);
            }
        }
        p++;
    }
    return func_0041CA70_i(*(int *)(fp + 0x54), fp, (char *)fmt, ap);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041B728);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041B728\n.ent func_0041B728\nfunc_0041B728:\n"
    "addiu $29, $29, -0x250\n"
    "sq $17, 0x230($29)\n"
    "sq $19, 0x210($29)\n"
    "daddu $17, $5, $0\n"
    "sq $30, 0x1C0($29)\n"
    "daddu $19, $7, $0\n"
    "sq $16, 0x240($29)\n"
    "sq $18, 0x220($29)\n"
    "sq $20, 0x200($29)\n"
    "sq $21, 0x1F0($29)\n"
    "sq $22, 0x1E0($29)\n"
    "sq $23, 0x1D0($29)\n"
    "sd $31, 0x1B0($29)\n"
    "jal func_0041EC48\n"
    "daddu $30, $6, $0\n"
    "addiu $2, $29, 0x180\n"
    "addiu $3, $29, 0x184\n"
    "sw $0, 0x18C($29)\n"
    "sw $2, 0x1A4($29)\n"
    "sw $3, 0x1A8($29)\n"
    "sw $0, 0x184($29)\n"
    "nop\n"
    ".L0041B780:\n"
    "daddu $20, $30, $0\n"
    "addiu $18, $0, 0x25\n"
    ".L0041B788:\n"
    "lui $5, %hi(D_00454944)\n"
    "lui $6, %hi(D_00455140)\n"
    "lw $4, %lo(D_00454944)($5)\n"
    "lw $7, %lo(D_00455140)($6)\n"
    "lw $5, 0x1A4($29)\n"
    "daddu $6, $30, $0\n"
    "jal func_00418958\n"
    "lw $8, 0x1A8($29)\n"
    "daddu $16, $2, $0\n"
    ".word 0x1A000004 /* blez $16, .L0041B7C0: raw word */\n"
    "lhu $2, 0x180($29)\n"
    ".word 0x1452FFF4 /* bne $2, $18, .L0041B788: raw word */\n"
    "addu $30, $30, $16\n"
    "addiu $30, $30, -0x1\n"
    ".L0041B7C0:\n"
    "subu $18, $30, $20\n"
    ".word 0x12400028 /* beqz $18, .L0041B868: raw word */\n"
    "nop\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041B838: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $18, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041B814: raw word */\n"
    "daddu $5, $20, $0\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $18, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $18\n"
    "subu $2, $2, $18\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041B85C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041B814:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041B85C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041B838:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041B84C: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041B84C:\n"
    "daddu $5, $20, $0\n"
    "daddu $6, $18, $0\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041B85C:\n"
    "lw $2, 0x18C($29)\n"
    "addu $2, $2, $18\n"
    "sw $2, 0x18C($29)\n"
    ".L0041B868:\n"
    ".word 0x5A0003B2 /* blezl $16, .L0041C734: raw word */\n"
    "lhu $2, 0xC($17)\n"
    "lw $2, 0x8($17)\n"
    ".word 0x5C400006 /* bgtzl $2, .L0041B890: raw word */\n"
    "sb $0, 0x182($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x144003B4 /* bnez $2, .L0041C758: raw word */\n"
    "lw $2, 0x18C($29)\n"
    "sb $0, 0x182($29)\n"
    ".L0041B890:\n"
    "addiu $30, $30, 0x1\n"
    "sw $0, 0x194($29)\n"
    "daddu $21, $0, $0\n"
    "sw $0, 0x190($29)\n"
    "addiu $23, $0, -0x1\n"
    ".L0041B8A4:\n"
    "lb $22, 0x0($30)\n"
    ".L0041B8A8:\n"
    "addiu $30, $30, 0x1\n"
    ".L0041B8AC:\n"
    "addiu $3, $22, -0x20\n"
    "sltiu $2, $3, 0x59\n"
    ".word 0x1040019C /* beqz $2, lbl_0041BF28: raw word */\n"
    "lui $2, %hi(jtbl_0049A430)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A430)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_0041B8D4\n"
    "lbl_0041B8D4:\n"
    ".Llbl_0041B8D4:\n"
    "lb $2, 0x182($29)\n"
    ".word 0x5440FFF3 /* bnel $2, $0, .L0041B8A8: raw word */\n"
    "lb $22, 0x0($30)\n"
    "addiu $2, $0, 0x20\n"
    ".word 0x1000FFEF /* b .L0041B8A4: raw word */\n"
    "sb $2, 0x182($29)\n"
    ".globl lbl_0041B8EC\n"
    "lbl_0041B8EC:\n"
    ".Llbl_0041B8EC:\n"
    ".word 0x1000FFED /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x1\n"
    ".globl lbl_0041B8F4\n"
    "lbl_0041B8F4:\n"
    ".Llbl_0041B8F4:\n"
    ".word 0x1000FFEB /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x200\n"
    ".globl lbl_0041B8FC\n"
    "lbl_0041B8FC:\n"
    ".Llbl_0041B8FC:\n"
    "addiu $19, $19, 0x8\n"
    "lw $3, -0x8($19)\n"
    ".word 0x0461FFE7 /* bgez $3, .L0041B8A4: raw word */\n"
    "sw $3, 0x190($29)\n"
    "negu $3, $3\n"
    "sw $3, 0x190($29)\n"
    ".globl lbl_0041B914\n"
    "lbl_0041B914:\n"
    ".Llbl_0041B914:\n"
    ".word 0x1000FFE3 /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x4\n"
    ".globl lbl_0041B91C\n"
    "lbl_0041B91C:\n"
    ".Llbl_0041B91C:\n"
    "addiu $2, $0, 0x2B\n"
    ".word 0x1000FFE0 /* b .L0041B8A4: raw word */\n"
    "sb $2, 0x182($29)\n"
    ".globl lbl_0041B928\n"
    "lbl_0041B928:\n"
    ".Llbl_0041B928:\n"
    "lb $22, 0x0($30)\n"
    "addiu $2, $0, 0x2A\n"
    ".word 0x16C20008 /* bne $22, $2, .L0041B954: raw word */\n"
    "addiu $30, $30, 0x1\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $0, -0x2\n"
    "lw $16, -0x8($19)\n"
    "addiu $23, $0, -0x1\n"
    "slt $2, $2, $16\n"
    ".word 0x1000FFD5 /* b .L0041B8A4: raw word */\n"
    "movn $23, $16, $2\n"
    ".L0041B954:\n"
    "addiu $2, $22, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1040000A /* beqz $2, .L0041B988: raw word */\n"
    "daddu $16, $0, $0\n"
    "addiu $3, $0, 0xA\n"
    ".L0041B968:\n"
    "mult $2, $16, $3\n"
    "addiu $2, $2, -0x30\n"
    "addu $16, $2, $22\n"
    "lb $22, 0x0($30)\n"
    "addiu $2, $22, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1440FFF9 /* bnez $2, .L0041B968: raw word */\n"
    "addiu $30, $30, 0x1\n"
    ".L0041B988:\n"
    "addiu $2, $0, -0x2\n"
    "addiu $23, $0, -0x1\n"
    "slt $2, $2, $16\n"
    ".word 0x1000FFC5 /* b .L0041B8AC: raw word */\n"
    "movn $23, $16, $2\n"
    ".globl lbl_0041B99C\n"
    "lbl_0041B99C:\n"
    ".Llbl_0041B99C:\n"
    ".word 0x1000FFC1 /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x80\n"
    ".globl lbl_0041B9A4\n"
    "lbl_0041B9A4:\n"
    ".Llbl_0041B9A4:\n"
    "daddu $16, $0, $0\n"
    "addiu $3, $0, 0xA\n"
    "nop\n"
    ".L0041B9B0:\n"
    "mult $2, $16, $3\n"
    "addiu $2, $2, -0x30\n"
    "addu $16, $2, $22\n"
    "lb $22, 0x0($30)\n"
    "addiu $2, $22, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1440FFF9 /* bnez $2, .L0041B9B0: raw word */\n"
    "addiu $30, $30, 0x1\n"
    ".word 0x1000FFB6 /* b .L0041B8AC: raw word */\n"
    "sw $16, 0x190($29)\n"
    ".globl lbl_0041B9D8\n"
    "lbl_0041B9D8:\n"
    ".Llbl_0041B9D8:\n"
    ".word 0x1000FFB2 /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x8\n"
    ".globl lbl_0041B9E0\n"
    "lbl_0041B9E0:\n"
    ".Llbl_0041B9E0:\n"
    ".word 0x1000FFB0 /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x40\n"
    ".globl lbl_0041B9E8\n"
    "lbl_0041B9E8:\n"
    ".Llbl_0041B9E8:\n"
    "lb $3, 0x0($30)\n"
    "addiu $2, $0, 0x6C\n"
    ".word 0x5462FFAC /* bnel $3, $2, .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x10\n"
    "addiu $30, $30, 0x1\n"
    ".globl lbl_0041B9FC\n"
    "lbl_0041B9FC:\n"
    ".Llbl_0041B9FC:\n"
    ".word 0x1000FFA9 /* b .L0041B8A4: raw word */\n"
    "ori $21, $21, 0x20\n"
    ".globl lbl_0041BA04\n"
    "lbl_0041BA04:\n"
    ".Llbl_0041BA04:\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $0, 0x1\n"
    "lbu $3, -0x8($19)\n"
    "andi $4, $21, 0x4\n"
    "addiu $20, $29, 0x10\n"
    "sw $2, 0x188($29)\n"
    "andi $23, $21, 0x84\n"
    "sb $3, 0x10($29)\n"
    "sw $4, 0x1A0($29)\n"
    ".word 0x10000148 /* b .L0041BF4C: raw word */\n"
    "sb $0, 0x182($29)\n"
    ".globl lbl_0041BA30\n"
    "lbl_0041BA30:\n"
    ".Llbl_0041BA30:\n"
    "ori $21, $21, 0x10\n"
    ".globl lbl_0041BA34\n"
    "lbl_0041BA34:\n"
    ".Llbl_0041BA34:\n"
    "andi $2, $21, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041BA50: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $21, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041BA58: raw word */\n"
    "andi $2, $21, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041BA50:\n"
    ".word 0x10000006 /* b .L0041BA6C: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041BA58:\n"
    ".word 0x10400003 /* beqz $2, .L0041BA68: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041BA6C: raw word */\n"
    "lh $16, -0x8($19)\n"
    ".L0041BA68:\n"
    "lw $16, -0x8($19)\n"
    ".L0041BA6C:\n"
    ".word 0x060100C8 /* bgez $16, .L0041BD90: raw word */\n"
    "addiu $18, $0, 0x1\n"
    "addiu $2, $0, 0x2D\n"
    "dsubu $16, $0, $16\n"
    ".word 0x100000C4 /* b .L0041BD90: raw word */\n"
    "sb $2, 0x182($29)\n"
    ".globl lbl_0041BA84\n"
    "lbl_0041BA84:\n"
    ".Llbl_0041BA84:\n"
    "nor $2, $0, $23\n"
    "addiu $3, $0, 0x6\n"
    "addiu $19, $19, 0x8\n"
    "movz $23, $3, $2\n"
    "ld $20, -0x8($19)\n"
    "addiu $2, $0, 0x67\n"
    ".word 0x12C20004 /* beq $22, $2, .L0041BAB0: raw word */\n"
    "daddu $7, $0, $0\n"
    "addiu $2, $0, 0x47\n"
    ".word 0x16C2002A /* bne $22, $2, .L0041BB54: raw word */\n"
    "andi $2, $21, 0x1\n"
    ".L0041BAB0:\n"
    "daddu $18, $0, $0\n"
    "daddu $4, $20, $0\n"
    "jal func_00412500\n"
    "daddu $5, $18, $0\n"
    ".word 0x1040000D /* beqz $2, .L0041BAF8: raw word */\n"
    "daddu $16, $20, $0\n"
    "daddu $4, $20, $0\n"
    "jal func_00412500\n"
    "daddu $5, $18, $0\n"
    ".word 0x04410004 /* bgez $2, .L0041BAE8: raw word */\n"
    "daddu $4, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $20, $0\n"
    "daddu $16, $2, $0\n"
    ".L0041BAE8:\n"
    "jal func_0041F9D8\n"
    "daddu $4, $16, $0\n"
    ".word 0x10000003 /* b .L0041BB00: raw word */\n"
    "daddu $16, $2, $0\n"
    ".L0041BAF8:\n"
    "ori $16, $0, 0xFFC0\n"
    "dsll32 $16, $16, 14\n"
    ".L0041BB00:\n"
    "ori $5, $0, 0xC010\n"
    "dsll32 $5, $5, 16\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x04400008 /* bltz $2, .L0041BB34: raw word */\n"
    "xori $4, $22, 0x67\n"
    "jal func_00412550\n"
    "daddu $4, $23, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00412500\n"
    "daddu $5, $2, $0\n"
    ".word 0x04400006 /* bltz $2, .L0041BB48: raw word */\n"
    "xori $4, $22, 0x67\n"
    ".L0041BB34:\n"
    "addiu $2, $0, 0x65\n"
    "addiu $3, $0, 0x45\n"
    "daddu $22, $2, $0\n"
    ".word 0x10000002 /* b .L0041BB4C: raw word */\n"
    "movn $22, $3, $4\n"
    ".L0041BB48:\n"
    "addiu $22, $0, 0x66\n"
    ".L0041BB4C:\n"
    "addiu $7, $0, 0x1\n"
    "andi $2, $21, 0x1\n"
    ".L0041BB54:\n"
    ".word 0x10400003 /* beqz $2, .L0041BB64: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "daddu $7, $0, $0\n"
    "movz $23, $2, $23\n"
    ".L0041BB64:\n"
    "daddu $5, $23, $0\n"
    "daddu $4, $20, $0\n"
    "daddu $6, $22, $0\n"
    "jal func_0041AF88\n"
    "addiu $8, $29, 0x182\n"
    "andi $23, $21, 0x84\n"
    "andi $5, $21, 0x4\n"
    "daddu $20, $2, $0\n"
    "sw $5, 0x1A0($29)\n"
    "jal strlen\n"
    "daddu $4, $20, $0\n"
    "andi $3, $21, 0x200\n"
    ".word 0x106000ED /* beqz $3, .L0041BF4C: raw word */\n"
    "sw $2, 0x188($29)\n"
    "daddu $4, $20, $0\n"
    "addiu $7, $29, 0x188\n"
    "addu $6, $4, $2\n"
    ".word 0x100000D7 /* b .L0041BF08: raw word */\n"
    "daddu $5, $4, $0\n"
    ".globl lbl_0041BBB0\n"
    "lbl_0041BBB0:\n"
    ".Llbl_0041BBB0:\n"
    "andi $2, $21, 0x20\n"
    ".word 0x10400005 /* beqz $2, .L0041BBCC: raw word */\n"
    "lw $6, 0x18C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FEEE /* b .L0041B780: raw word */\n"
    "sd $6, 0x0($2)\n"
    ".L0041BBCC:\n"
    "andi $2, $21, 0x10\n"
    ".word 0x10400005 /* beqz $2, .L0041BBE8: raw word */\n"
    "lw $3, 0x18C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FEE7 /* b .L0041B780: raw word */\n"
    "sd $3, 0x0($2)\n"
    ".L0041BBE8:\n"
    "andi $2, $21, 0x40\n"
    ".word 0x10400005 /* beqz $2, .L0041BC04: raw word */\n"
    "lw $4, 0x18C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FEE0 /* b .L0041B780: raw word */\n"
    "sh $4, 0x0($2)\n"
    ".L0041BC04:\n"
    "addiu $19, $19, 0x8\n"
    "lw $5, 0x18C($29)\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FEDB /* b .L0041B780: raw word */\n"
    "sw $5, 0x0($2)\n"
    ".globl lbl_0041BC18\n"
    "lbl_0041BC18:\n"
    ".Llbl_0041BC18:\n"
    "ori $21, $21, 0x10\n"
    ".globl lbl_0041BC1C\n"
    "lbl_0041BC1C:\n"
    ".Llbl_0041BC1C:\n"
    "andi $2, $21, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041BC38: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $21, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041BC40: raw word */\n"
    "andi $2, $21, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041BC38:\n"
    ".word 0x10000006 /* b .L0041BC54: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041BC40:\n"
    ".word 0x10400003 /* beqz $2, .L0041BC50: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041BC54: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041BC50:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041BC54:\n"
    ".word 0x1000004D /* b .L0041BD8C: raw word */\n"
    "daddu $18, $0, $0\n"
    ".globl lbl_0041BC5C\n"
    "lbl_0041BC5C:\n"
    ".Llbl_0041BC5C:\n"
    "lui $2, %hi(D_0049A3D0)\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $2, %lo(D_0049A3D0)\n"
    "addiu $18, $0, 0x2\n"
    "sw $2, 0x19C($29)\n"
    "ori $21, $21, 0x2\n"
    "addiu $22, $0, 0x78\n"
    ".word 0x10000044 /* b .L0041BD8C: raw word */\n"
    "lw $16, -0x8($19)\n"
    ".globl lbl_0041BC80\n"
    "lbl_0041BC80:\n"
    ".Llbl_0041BC80:\n"
    "addiu $19, $19, 0x8\n"
    "lw $20, -0x8($19)\n"
    ".word 0x16800002 /* bnez $20, .L0041BC94: raw word */\n"
    "lui $2, %hi(D_0049A3E8)\n"
    "addiu $20, $2, %lo(D_0049A3E8)\n"
    ".L0041BC94:\n"
    ".word 0x06E0000B /* bltz $23, .L0041BCC4: raw word */\n"
    "daddu $4, $20, $0\n"
    "daddu $5, $0, $0\n"
    "jal func_0041EC70\n"
    "daddu $6, $23, $0\n"
    ".word 0x10400004 /* beqz $2, .L0041BCBC: raw word */\n"
    "subu $2, $2, $20\n"
    "slt $3, $23, $2\n"
    ".word 0x10600006 /* beqz $3, .L0041BCD0: raw word */\n"
    "sw $2, 0x188($29)\n"
    ".L0041BCBC:\n"
    ".word 0x10000004 /* b .L0041BCD0: raw word */\n"
    "sw $23, 0x188($29)\n"
    ".L0041BCC4:\n"
    "jal strlen\n"
    "daddu $4, $20, $0\n"
    "sw $2, 0x188($29)\n"
    ".L0041BCD0:\n"
    "andi $6, $21, 0x4\n"
    "sb $0, 0x182($29)\n"
    "andi $23, $21, 0x84\n"
    ".word 0x1000009B /* b .L0041BF4C: raw word */\n"
    "sw $6, 0x1A0($29)\n"
    ".globl lbl_0041BCE4\n"
    "lbl_0041BCE4:\n"
    ".Llbl_0041BCE4:\n"
    "ori $21, $21, 0x10\n"
    ".globl lbl_0041BCE8\n"
    "lbl_0041BCE8:\n"
    ".Llbl_0041BCE8:\n"
    "andi $2, $21, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041BD04: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $21, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041BD0C: raw word */\n"
    "andi $2, $21, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041BD04:\n"
    ".word 0x10000006 /* b .L0041BD20: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041BD0C:\n"
    ".word 0x10400003 /* beqz $2, .L0041BD1C: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041BD20: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041BD1C:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041BD20:\n"
    ".word 0x1000001A /* b .L0041BD8C: raw word */\n"
    "addiu $18, $0, 0x1\n"
    ".globl lbl_0041BD28\n"
    "lbl_0041BD28:\n"
    ".Llbl_0041BD28:\n"
    "lui $2, %hi(D_0049A3F0)\n"
    ".word 0x10000003 /* b .L0041BD3C: raw word */\n"
    "addiu $2, $2, %lo(D_0049A3F0)\n"
    ".globl lbl_0041BD34\n"
    "lbl_0041BD34:\n"
    ".Llbl_0041BD34:\n"
    "lui $2, %hi(D_0049A3D0)\n"
    "addiu $2, $2, %lo(D_0049A3D0)\n"
    ".L0041BD3C:\n"
    "sw $2, 0x19C($29)\n"
    "andi $2, $21, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041BD5C: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $21, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041BD64: raw word */\n"
    "andi $2, $21, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041BD5C:\n"
    ".word 0x10000006 /* b .L0041BD78: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041BD64:\n"
    ".word 0x10400003 /* beqz $2, .L0041BD74: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041BD78: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041BD74:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041BD78:\n"
    "andi $3, $21, 0x1\n"
    ".word 0x10600003 /* beqz $3, .L0041BD8C: raw word */\n"
    "addiu $18, $0, 0x2\n"
    "ori $2, $21, 0x2\n"
    "movn $21, $2, $16\n"
    ".L0041BD8C:\n"
    "sb $0, 0x182($29)\n"
    ".L0041BD90:\n"
    ".word 0x06E00003 /* bltz $23, .L0041BDA0: raw word */\n"
    "sw $23, 0x194($29)\n"
    "addiu $2, $0, -0x81\n"
    "and $21, $21, $2\n"
    ".L0041BDA0:\n"
    ".word 0x16000006 /* bnez $16, .L0041BDBC: raw word */\n"
    "addiu $20, $29, 0x16C\n"
    "andi $2, $21, 0x4\n"
    "lw $3, 0x194($29)\n"
    "andi $23, $21, 0x84\n"
    ".word 0x1060004B /* beqz $3, .L0041BEE4: raw word */\n"
    "sw $2, 0x1A0($29)\n"
    ".L0041BDBC:\n"
    "addiu $2, $0, 0x1\n"
    ".word 0x12420019 /* beq $18, $2, .L0041BE28: raw word */\n"
    "andi $5, $21, 0x4\n"
    ".word 0x12400005 /* beqz $18, .L0041BDE0: raw word */\n"
    "addiu $2, $0, 0x2\n"
    ".word 0x1242002D /* beq $18, $2, .L0041BE88: raw word */\n"
    "lui $2, %hi(D_0049A408)\n"
    ".word 0x1000003B /* b .L0041BEC8: raw word */\n"
    "andi $4, $21, 0x4\n"
    ".L0041BDE0:\n"
    "andi $4, $21, 0x4\n"
    "andi $3, $21, 0x1\n"
    "sw $4, 0x1A0($29)\n"
    "andi $23, $21, 0x84\n"
    ".L0041BDF0:\n"
    "andi $2, $16, 0x7\n"
    "addiu $20, $20, -0x1\n"
    "daddiu $2, $2, 0x30\n"
    "dsrl $16, $16, 3\n"
    "andi $2, $2, 0xFF\n"
    ".word 0x1600FFFA /* bnez $16, .L0041BDF0: raw word */\n"
    "sb $2, 0x0($20)\n"
    ".word 0x10600035 /* beqz $3, .L0041BEE4: raw word */\n"
    "addiu $3, $0, 0x30\n"
    ".word 0x10430034 /* beq $2, $3, .L0041BEE8: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x10000031 /* b .L0041BEE8: raw word */\n"
    "sb $3, 0x0($20)\n"
    ".L0041BE28:\n"
    "sltiu $2, $16, 0xA\n"
    "andi $23, $21, 0x84\n"
    ".word 0x14400010 /* bnez $2, .L0041BE74: raw word */\n"
    "sw $5, 0x1A0($29)\n"
    "daddu $4, $16, $0\n"
    "nop\n"
    ".L0041BE40:\n"
    "jal func_0042DAD8\n"
    "addiu $5, $0, 0xA\n"
    "addiu $20, $20, -0x1\n"
    "daddiu $2, $2, 0x30\n"
    "daddu $4, $16, $0\n"
    "andi $2, $2, 0xFF\n"
    "addiu $5, $0, 0xA\n"
    "jal func_00411538\n"
    "sb $2, 0x0($20)\n"
    "daddu $16, $2, $0\n"
    "sltiu $2, $16, 0xA\n"
    ".word 0x1040FFF4 /* beqz $2, .L0041BE40: raw word */\n"
    "daddu $4, $16, $0\n"
    ".L0041BE74:\n"
    "daddiu $2, $16, 0x30\n"
    "addiu $20, $20, -0x1\n"
    "andi $2, $2, 0xFF\n"
    ".word 0x10000018 /* b .L0041BEE4: raw word */\n"
    "sb $2, 0x0($20)\n"
    ".L0041BE88:\n"
    "andi $6, $21, 0x4\n"
    "andi $23, $21, 0x84\n"
    "sw $6, 0x1A0($29)\n"
    "nop\n"
    ".L0041BE98:\n"
    "lw $3, 0x19C($29)\n"
    "andi $2, $16, 0xF\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "addiu $20, $20, -0x1\n"
    "addu $2, $3, $2\n"
    "dsrl $16, $16, 4\n"
    "lbu $3, 0x0($2)\n"
    ".word 0x1600FFF7 /* bnez $16, .L0041BE98: raw word */\n"
    "sb $3, 0x0($20)\n"
    ".word 0x10000009 /* b .L0041BEE8: raw word */\n"
    "addiu $2, $0, 0x1\n"
    ".L0041BEC8:\n"
    "addiu $20, $2, %lo(D_0049A408)\n"
    "sw $4, 0x1A0($29)\n"
    "daddu $4, $20, $0\n"
    "jal strlen\n"
    "andi $23, $21, 0x84\n"
    ".word 0x1000001B /* b .L0041BF4C: raw word */\n"
    "sw $2, 0x188($29)\n"
    ".L0041BEE4:\n"
    "addiu $2, $0, 0x1\n"
    ".L0041BEE8:\n"
    ".word 0x1642000C /* bne $18, $2, .L0041BF1C: raw word */\n"
    "subu $2, $29, $20\n"
    "andi $2, $21, 0x200\n"
    ".word 0x10400008 /* beqz $2, .L0041BF18: raw word */\n"
    "daddu $5, $20, $0\n"
    "addiu $6, $29, 0x16C\n"
    "addiu $4, $29, 0x10\n"
    "addiu $7, $29, 0x188\n"
    ".L0041BF08:\n"
    "jal func_0041C788\n"
    "nop\n"
    ".word 0x1000000E /* b .L0041BF4C: raw word */\n"
    "daddu $20, $2, $0\n"
    ".L0041BF18:\n"
    "subu $2, $29, $20\n"
    ".L0041BF1C:\n"
    "addiu $2, $2, 0x16C\n"
    ".word 0x1000000A /* b .L0041BF4C: raw word */\n"
    "sw $2, 0x188($29)\n"
    ".globl lbl_0041BF28\n"
    "lbl_0041BF28:\n"
    ".Llbl_0041BF28:\n"
    ".word 0x12C00201 /* beqz $22, .L0041C730: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "andi $5, $21, 0x4\n"
    "sb $22, 0x10($29)\n"
    "addiu $20, $29, 0x10\n"
    "sw $2, 0x188($29)\n"
    "andi $23, $21, 0x84\n"
    "sb $0, 0x182($29)\n"
    "sw $5, 0x1A0($29)\n"
    ".L0041BF4C:\n"
    "lw $6, 0x188($29)\n"
    "lw $4, 0x194($29)\n"
    "lb $3, 0x182($29)\n"
    "slt $2, $6, $4\n"
    "movz $4, $6, $2\n"
    ".word 0x10600004 /* beqz $3, .L0041BF74: raw word */\n"
    "sw $4, 0x198($29)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x10000005 /* b .L0041BF84: raw word */\n"
    "sw $4, 0x198($29)\n"
    ".L0041BF74:\n"
    "lw $5, 0x198($29)\n"
    "andi $2, $21, 0x2\n"
    "addu $5, $2, $5\n"
    "sw $5, 0x198($29)\n"
    ".L0041BF84:\n"
    ".word 0x16E0005C /* bnez $23, .L0041C0F8: raw word */\n"
    "lb $2, 0x182($29)\n"
    "lw $6, 0x190($29)\n"
    "lw $2, 0x198($29)\n"
    "subu $16, $6, $2\n"
    ".word 0x1A000056 /* blez $16, .L0041C0F4: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x14400030 /* bnez $2, .L0041C064: raw word */\n"
    "lui $18, %hi(D_0049A3B0)\n"
    "lhu $2, 0xC($17)\n"
    "nop\n"
    ".L0041BFB0:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041C030: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041C010: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $6, $18, %lo(D_0049A3B0)\n"
    "ldl $3, 0x7($6)\n"
    "ldr $3, 0x0($6)\n"
    "ldl $4, 0xF($6)\n"
    "ldr $4, 0x8($6)\n"
    "sdl $3, 0x7($2)\n"
    "sdr $3, 0x0($2)\n"
    "sdl $4, 0xF($2)\n"
    "sdr $4, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000012 /* b .L0041C054: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C010:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041C054: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C030:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C044: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C044:\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C054:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD4 /* beql $2, $0, .L0041BFB0: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C064:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041C0D0: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041C0AC: raw word */\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041C0F4: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C0AC:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041C0F4: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C0D0:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C0E4: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C0E4:\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C0F4:\n"
    "lb $2, 0x182($29)\n"
    ".L0041C0F8:\n"
    ".word 0x1040001D /* beqz $2, .L0041C170: raw word */\n"
    "lbu $3, 0x182($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040000E /* beql $2, $0, .L0041C144: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x2\n"
    ".word 0x54400008 /* bnel $2, $0, .L0041C13C: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "sb $3, 0x0($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x1\n"
    ".word 0x10000023 /* b .L0041C1C4: raw word */\n"
    "addiu $2, $2, -0x1\n"
    ".L0041C13C:\n"
    ".word 0x10000025 /* b .L0041C1D4: raw word */\n"
    "addiu $5, $29, 0x182\n"
    ".L0041C144:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C158: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C158:\n"
    "addiu $5, $29, 0x182\n"
    "addiu $6, $0, 0x1\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".word 0x1000002D /* b .L0041C220: raw word */\n"
    "addiu $2, $0, 0x80\n"
    ".L0041C170:\n"
    "andi $2, $21, 0x2\n"
    ".word 0x10400029 /* beqz $2, .L0041C21C: raw word */\n"
    "addiu $2, $0, 0x30\n"
    "lhu $3, 0xC($17)\n"
    "sb $2, 0x170($29)\n"
    "andi $3, $3, 0x200\n"
    ".word 0x1060001A /* beqz $3, .L0041C1F4: raw word */\n"
    "sb $22, 0x171($29)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x3\n"
    ".word 0x5440000D /* bnel $2, $0, .L0041C1D0: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "lb $3, 0x170($29)\n"
    "lb $4, 0x171($29)\n"
    "sb $3, 0x0($2)\n"
    "sb $4, 0x1($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x2\n"
    "addiu $2, $2, -0x2\n"
    ".L0041C1C4:\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000014 /* b .L0041C21C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C1D0:\n"
    "addiu $5, $29, 0x170\n"
    ".L0041C1D4:\n"
    "jal func_0041605C\n"
    "nop\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000B /* b .L0041C21C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C1F4:\n"
    "lw $2, 0xC($17)\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C20C: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C20C:\n"
    "addiu $5, $29, 0x170\n"
    "addiu $6, $0, 0x2\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C21C:\n"
    "addiu $2, $0, 0x80\n"
    ".L0041C220:\n"
    ".word 0x16E2005B /* bne $23, $2, .L0041C390: raw word */\n"
    "lw $2, 0x188($29)\n"
    "lw $2, 0x190($29)\n"
    "lw $3, 0x198($29)\n"
    "subu $16, $2, $3\n"
    ".word 0x1A000055 /* blez $16, .L0041C38C: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002F /* bnez $2, .L0041C2FC: raw word */\n"
    "lui $18, %hi(D_0049A3C0)\n"
    "addiu $21, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    "nop\n"
    ".L0041C250:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041C2D0: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041C2B0: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $3, $18, %lo(D_0049A3C0)\n"
    "ldl $4, 0x7($3)\n"
    "ldr $4, 0x0($3)\n"
    "ldl $5, 0xF($3)\n"
    "ldr $5, 0x8($3)\n"
    "sdl $4, 0x7($2)\n"
    "sdr $4, 0x0($2)\n"
    "sdl $5, 0xF($2)\n"
    "sdr $5, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041C2EC: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C2B0:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041C2EC: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C2D0:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041C2D8: raw word */\n"
    "sh $21, 0xE($17)\n"
    ".L0041C2D8:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C2EC:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041C250: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C2FC:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041C368: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041C344: raw word */\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041C38C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C344:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041C38C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C368:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C37C: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C37C:\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C38C:\n"
    "lw $2, 0x188($29)\n"
    ".L0041C390:\n"
    "lw $4, 0x194($29)\n"
    "subu $16, $4, $2\n"
    ".word 0x1A000054 /* blez $16, .L0041C4EC: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002E /* bnez $2, .L0041C45C: raw word */\n"
    "lui $18, %hi(D_0049A3C0)\n"
    "addiu $21, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C3B0:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041C430: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041C410: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $4, $18, %lo(D_0049A3C0)\n"
    "ldl $5, 0x7($4)\n"
    "ldr $5, 0x0($4)\n"
    "ldl $6, 0xF($4)\n"
    "ldr $6, 0x8($4)\n"
    "sdl $5, 0x7($2)\n"
    "sdr $5, 0x0($2)\n"
    "sdl $6, 0xF($2)\n"
    "sdr $6, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041C44C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C410:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041C44C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C430:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041C438: raw word */\n"
    "sh $21, 0xE($17)\n"
    ".L0041C438:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C44C:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041C3B0: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C45C:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041C4C8: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041C4A4: raw word */\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041C4EC: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C4A4:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041C4EC: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C4C8:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C4DC: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C4DC:\n"
    "addiu $5, $18, %lo(D_0049A3C0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C4EC:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x10400018 /* beqz $2, .L0041C558: raw word */\n"
    "lw $6, 0x188($29)\n"
    "lw $3, 0x8($17)\n"
    "slt $2, $6, $3\n"
    ".word 0x1040000B /* beqz $2, .L0041C534: raw word */\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $4, 0x188($29)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $4\n"
    "subu $2, $2, $4\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000014 /* b .L0041C580: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C534:\n"
    "daddu $6, $3, $0\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000B /* b .L0041C580: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C558:\n"
    "lw $2, 0xC($17)\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C570: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C570:\n"
    "daddu $5, $20, $0\n"
    "lw $6, 0x188($29)\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C580:\n"
    "lw $5, 0x1A0($29)\n"
    ".word 0x10A00059 /* beqz $5, .L0041C6EC: raw word */\n"
    "lw $6, 0x190($29)\n"
    "lw $2, 0x198($29)\n"
    "subu $16, $6, $2\n"
    ".word 0x1A000055 /* blez $16, .L0041C6EC: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002F /* bnez $2, .L0041C65C: raw word */\n"
    "lui $18, %hi(D_0049A3B0)\n"
    "addiu $20, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    "nop\n"
    ".L0041C5B0:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041C630: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041C610: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $6, $18, %lo(D_0049A3B0)\n"
    "ldl $3, 0x7($6)\n"
    "ldr $3, 0x0($6)\n"
    "ldl $4, 0xF($6)\n"
    "ldr $4, 0x8($6)\n"
    "sdl $3, 0x7($2)\n"
    "sdr $3, 0x0($2)\n"
    "sdl $4, 0xF($2)\n"
    "sdr $4, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041C64C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C610:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041C64C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C630:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041C638: raw word */\n"
    "sh $20, 0xE($17)\n"
    ".L0041C638:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C64C:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041C5B0: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C65C:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041C6C8: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041C6A4: raw word */\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041C6EC: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041C6A4:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041C6EC: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041C6C8:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041C6DC: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041C6DC:\n"
    "addiu $5, $18, %lo(D_0049A3B0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041B550\n"
    "daddu $7, $0, $0\n"
    ".L0041C6EC:\n"
    "lw $2, 0x8($17)\n"
    ".word 0x1C400008 /* bgtz $2, .L0041C714: raw word */\n"
    "lw $3, 0x198($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x10400005 /* beqz $2, .L0041C718: raw word */\n"
    "lw $4, 0x190($29)\n"
    "lw $2, 0x14($17)\n"
    ".word 0x1000FC1C /* b .L0041B780: raw word */\n"
    "sw $2, 0x18C($29)\n"
    ".L0041C714:\n"
    "lw $4, 0x190($29)\n"
    ".L0041C718:\n"
    "lw $5, 0x18C($29)\n"
    "slt $2, $3, $4\n"
    "movz $4, $3, $2\n"
    "addu $5, $5, $4\n"
    ".word 0x1000FC15 /* b .L0041B780: raw word */\n"
    "sw $5, 0x18C($29)\n"
    ".L0041C730:\n"
    "lhu $2, 0xC($17)\n"
    ".L0041C734:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x14400007 /* bnez $2, .L0041C758: raw word */\n"
    "lw $2, 0x18C($29)\n"
    "lh $4, 0xE($17)\n"
    "daddu $5, $0, $0\n"
    "daddu $6, $0, $0\n"
    "jal func_0041B550\n"
    "addiu $7, $0, 0x1\n"
    "lw $2, 0x18C($29)\n"
    ".L0041C758:\n"
    "lq $16, 0x240($29)\n"
    "lq $17, 0x230($29)\n"
    "lq $18, 0x220($29)\n"
    "lq $19, 0x210($29)\n"
    "lq $20, 0x200($29)\n"
    "lq $21, 0x1F0($29)\n"
    "lq $22, 0x1E0($29)\n"
    "lq $23, 0x1D0($29)\n"
    "lq $30, 0x1C0($29)\n"
    "ld $31, 0x1B0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x250\n"
    ".end func_0041B728\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041C788);
#ifdef SKIP_ASM
extern void *g_c788_memcpy(void *, const void *, unsigned) __asm__("func_0041605C");
char *func_0041C788_impl(char *dest, char *start, char *end, int *outlen) __asm__("func_0041C788");
char *func_0041C788_impl(char *dest, char *start, char *end, int *outlen) {
    int len = end - start + 10;
    char *buf = __builtin_alloca(len);
    char *w = buf + len - 1;
    int cnt = 0;
    int st[2];
    char *p;
    if (dest == 0 || start == 0 || end == 0) return 0;
    st[0] = 0;
    st[1] = (int)end;
    p = start;
    if (!(end < p)) {
        do {
            switch (*p) {
            case '.':
                st[1] = (int)p;
                if (st[0] == 0) st[0] = 1;
                break;
            case 'E':
            case 'e':
                st[0] = 2;
                break;
            }
            p++;
        } while (!(end < p) && st[0] != 2);
    }
    if (st[0] == 2) return start;
    p = end;
    if (start < p) {
        do {
            *w = *p;
            w--;
            if (!((char *)st[1] < p)) {
                if (cnt % 3 == 0 && cnt != 0) {
                    *w = ',';
                    len++;
                    w--;
                }
                cnt++;
            }
            p--;
        } while (start < p);
    }
    *w = *p;
    len -= 10;
    g_c788_memcpy(dest, w, len);
    *outlen = len;
    return dest;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041C938);
#ifdef SKIP_ASM
extern char *D_00454CE4;
extern int D_00454CE0;
extern char D_0052AF18[];
int func_0041C938_(int fd, char *buf, unsigned n, int mode) __asm__("func_0041C938");
int func_0041C938_(int fd, char *buf, unsigned n, int mode) {
    unsigned i;
    int r;
    if (mode == 1) {
        r = func_00424368(fd, (int)D_0052AF18, D_00454CE0);
        D_00454CE0 = 0;
        D_00454CE4 = D_0052AF18;
        return r;
    }
    for (i = 0; i < n; i++) {
        *D_00454CE4 = buf[i];
        D_00454CE4++;
        D_00454CE0++;
        if (D_00454CE0 >= 128) {
            r = func_00424368(fd, (int)D_0052AF18, D_00454CE0);
            D_00454CE4 = D_0052AF18;
            D_00454CE0 = 0;
            if (r == 0)
                return 0;
        }
    }
    return i;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041CA40);
#ifdef SKIP_ASM
extern void func_0041CA70(int, int *, int, int);
void func_0041CA40(int *p, int b, int c) {
    func_0041CA70(p[21], p, b, c);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041CA70);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041CA70\n.ent func_0041CA70\nfunc_0041CA70:\n"
    "addiu $29, $29, -0x110\n"
    "addiu $2, $29, 0x40\n"
    "addiu $3, $29, 0x44\n"
    "sq $17, 0xF0($29)\n"
    "sq $19, 0xD0($29)\n"
    "daddu $17, $5, $0\n"
    "sq $23, 0x90($29)\n"
    "daddu $19, $7, $0\n"
    "sq $16, 0x100($29)\n"
    "daddu $23, $6, $0\n"
    "sq $18, 0xE0($29)\n"
    "sq $20, 0xC0($29)\n"
    "sq $21, 0xB0($29)\n"
    "sq $22, 0xA0($29)\n"
    "sq $30, 0x80($29)\n"
    "sd $31, 0x70($29)\n"
    "sw $0, 0x44($29)\n"
    "sw $0, 0x4C($29)\n"
    "sw $2, 0x60($29)\n"
    "sw $3, 0x64($29)\n"
    ".L0041CAC0:\n"
    "daddu $20, $23, $0\n"
    "addiu $18, $0, 0x25\n"
    ".L0041CAC8:\n"
    "lui $5, %hi(D_00454944)\n"
    "lui $6, %hi(D_00455140)\n"
    "lw $4, %lo(D_00454944)($5)\n"
    "lw $7, %lo(D_00455140)($6)\n"
    "lw $5, 0x60($29)\n"
    "daddu $6, $23, $0\n"
    "jal func_00418958\n"
    "lw $8, 0x64($29)\n"
    "daddu $16, $2, $0\n"
    ".word 0x1A000004 /* blez $16, .L0041CB00: raw word */\n"
    "lhu $2, 0x40($29)\n"
    ".word 0x1452FFF4 /* bne $2, $18, .L0041CAC8: raw word */\n"
    "addu $23, $23, $16\n"
    "addiu $23, $23, -0x1\n"
    ".L0041CB00:\n"
    "subu $18, $23, $20\n"
    ".word 0x12400028 /* beqz $18, .L0041CBA8: raw word */\n"
    "nop\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041CB78: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $18, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041CB54: raw word */\n"
    "daddu $5, $20, $0\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $18, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $18\n"
    "subu $2, $2, $18\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041CB9C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041CB54:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041CB9C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041CB78:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041CB8C: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041CB8C:\n"
    "daddu $5, $20, $0\n"
    "daddu $6, $18, $0\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041CB9C:\n"
    "lw $2, 0x4C($29)\n"
    "addu $2, $2, $18\n"
    "sw $2, 0x4C($29)\n"
    ".L0041CBA8:\n"
    ".word 0x5A000364 /* blezl $16, .L0041D93C: raw word */\n"
    "lhu $2, 0xC($17)\n"
    "lw $2, 0x8($17)\n"
    ".word 0x5C400006 /* bgtzl $2, .L0041CBD0: raw word */\n"
    "sb $0, 0x42($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x14400366 /* bnez $2, .L0041D960: raw word */\n"
    "lw $2, 0x4C($29)\n"
    "sb $0, 0x42($29)\n"
    ".L0041CBD0:\n"
    "addiu $23, $23, 0x1\n"
    "sw $0, 0x54($29)\n"
    "daddu $18, $0, $0\n"
    "sw $0, 0x50($29)\n"
    "addiu $30, $0, -0x1\n"
    ".L0041CBE4:\n"
    "lb $21, 0x0($23)\n"
    ".L0041CBE8:\n"
    "addiu $23, $23, 0x1\n"
    ".L0041CBEC:\n"
    "addiu $3, $21, -0x20\n"
    "sltiu $2, $3, 0x59\n"
    ".word 0x1040014F /* beqz $2, lbl_0041D134: raw word */\n"
    "lui $2, %hi(jtbl_0049A620)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A620)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_0041CC14\n"
    "lbl_0041CC14:\n"
    ".Llbl_0041CC14:\n"
    "lb $2, 0x42($29)\n"
    ".word 0x5440FFF3 /* bnel $2, $0, .L0041CBE8: raw word */\n"
    "lb $21, 0x0($23)\n"
    "addiu $2, $0, 0x20\n"
    ".word 0x1000FFEF /* b .L0041CBE4: raw word */\n"
    "sb $2, 0x42($29)\n"
    ".globl lbl_0041CC2C\n"
    "lbl_0041CC2C:\n"
    ".Llbl_0041CC2C:\n"
    ".word 0x1000FFED /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x1\n"
    ".globl lbl_0041CC34\n"
    "lbl_0041CC34:\n"
    ".Llbl_0041CC34:\n"
    ".word 0x1000FFEB /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x200\n"
    ".globl lbl_0041CC3C\n"
    "lbl_0041CC3C:\n"
    ".Llbl_0041CC3C:\n"
    "addiu $19, $19, 0x8\n"
    "lw $3, -0x8($19)\n"
    ".word 0x0461FFE7 /* bgez $3, .L0041CBE4: raw word */\n"
    "sw $3, 0x50($29)\n"
    "negu $3, $3\n"
    "sw $3, 0x50($29)\n"
    ".globl lbl_0041CC54\n"
    "lbl_0041CC54:\n"
    ".Llbl_0041CC54:\n"
    ".word 0x1000FFE3 /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x4\n"
    ".globl lbl_0041CC5C\n"
    "lbl_0041CC5C:\n"
    ".Llbl_0041CC5C:\n"
    "addiu $2, $0, 0x2B\n"
    ".word 0x1000FFE0 /* b .L0041CBE4: raw word */\n"
    "sb $2, 0x42($29)\n"
    ".globl lbl_0041CC68\n"
    "lbl_0041CC68:\n"
    ".Llbl_0041CC68:\n"
    "lb $21, 0x0($23)\n"
    "addiu $2, $0, 0x2A\n"
    ".word 0x16A20008 /* bne $21, $2, .L0041CC94: raw word */\n"
    "addiu $23, $23, 0x1\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $0, -0x2\n"
    "lw $16, -0x8($19)\n"
    "addiu $30, $0, -0x1\n"
    "slt $2, $2, $16\n"
    ".word 0x1000FFD5 /* b .L0041CBE4: raw word */\n"
    "movn $30, $16, $2\n"
    ".L0041CC94:\n"
    "addiu $2, $21, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1040000A /* beqz $2, .L0041CCC8: raw word */\n"
    "daddu $16, $0, $0\n"
    "addiu $3, $0, 0xA\n"
    ".L0041CCA8:\n"
    "mult $2, $16, $3\n"
    "addiu $2, $2, -0x30\n"
    "addu $16, $2, $21\n"
    "lb $21, 0x0($23)\n"
    "addiu $2, $21, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1440FFF9 /* bnez $2, .L0041CCA8: raw word */\n"
    "addiu $23, $23, 0x1\n"
    ".L0041CCC8:\n"
    "addiu $2, $0, -0x2\n"
    "addiu $30, $0, -0x1\n"
    "slt $2, $2, $16\n"
    ".word 0x1000FFC5 /* b .L0041CBEC: raw word */\n"
    "movn $30, $16, $2\n"
    ".globl lbl_0041CCDC\n"
    "lbl_0041CCDC:\n"
    ".Llbl_0041CCDC:\n"
    ".word 0x1000FFC1 /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x80\n"
    ".globl lbl_0041CCE4\n"
    "lbl_0041CCE4:\n"
    ".Llbl_0041CCE4:\n"
    "daddu $16, $0, $0\n"
    "addiu $3, $0, 0xA\n"
    "nop\n"
    ".L0041CCF0:\n"
    "mult $2, $16, $3\n"
    "addiu $2, $2, -0x30\n"
    "addu $16, $2, $21\n"
    "lb $21, 0x0($23)\n"
    "addiu $2, $21, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    ".word 0x1440FFF9 /* bnez $2, .L0041CCF0: raw word */\n"
    "addiu $23, $23, 0x1\n"
    ".word 0x1000FFB6 /* b .L0041CBEC: raw word */\n"
    "sw $16, 0x50($29)\n"
    ".globl lbl_0041CD18\n"
    "lbl_0041CD18:\n"
    ".Llbl_0041CD18:\n"
    ".word 0x1000FFB2 /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x40\n"
    ".globl lbl_0041CD20\n"
    "lbl_0041CD20:\n"
    ".Llbl_0041CD20:\n"
    "lb $3, 0x0($23)\n"
    "addiu $2, $0, 0x6C\n"
    ".word 0x5462FFAE /* bnel $3, $2, .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x10\n"
    "addiu $23, $23, 0x1\n"
    ".globl lbl_0041CD34\n"
    "lbl_0041CD34:\n"
    ".Llbl_0041CD34:\n"
    ".word 0x1000FFAB /* b .L0041CBE4: raw word */\n"
    "ori $18, $18, 0x20\n"
    ".globl lbl_0041CD3C\n"
    "lbl_0041CD3C:\n"
    ".Llbl_0041CD3C:\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $0, 0x1\n"
    "lbu $3, -0x8($19)\n"
    "andi $4, $18, 0x4\n"
    "daddu $20, $29, $0\n"
    "sw $2, 0x48($29)\n"
    "andi $30, $18, 0x84\n"
    "sb $3, 0x0($29)\n"
    "sw $4, 0x68($29)\n"
    ".word 0x100000FD /* b .L0041D158: raw word */\n"
    "sb $0, 0x42($29)\n"
    ".globl lbl_0041CD68\n"
    "lbl_0041CD68:\n"
    ".Llbl_0041CD68:\n"
    "ori $18, $18, 0x10\n"
    ".globl lbl_0041CD6C\n"
    "lbl_0041CD6C:\n"
    ".Llbl_0041CD6C:\n"
    "andi $2, $18, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041CD88: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $18, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041CD90: raw word */\n"
    "andi $2, $18, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041CD88:\n"
    ".word 0x10000006 /* b .L0041CDA4: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041CD90:\n"
    ".word 0x10400003 /* beqz $2, .L0041CDA0: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041CDA4: raw word */\n"
    "lh $16, -0x8($19)\n"
    ".L0041CDA0:\n"
    "lw $16, -0x8($19)\n"
    ".L0041CDA4:\n"
    ".word 0x0601007C /* bgez $16, .L0041CF98: raw word */\n"
    "addiu $22, $0, 0x1\n"
    "addiu $2, $0, 0x2D\n"
    "dsubu $16, $0, $16\n"
    ".word 0x10000078 /* b .L0041CF98: raw word */\n"
    "sb $2, 0x42($29)\n"
    ".globl lbl_0041CDBC\n"
    "lbl_0041CDBC:\n"
    ".Llbl_0041CDBC:\n"
    "andi $2, $18, 0x20\n"
    ".word 0x10400005 /* beqz $2, .L0041CDD8: raw word */\n"
    "lw $5, 0x4C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FF3B /* b .L0041CAC0: raw word */\n"
    "sd $5, 0x0($2)\n"
    ".L0041CDD8:\n"
    "andi $2, $18, 0x10\n"
    ".word 0x10400005 /* beqz $2, .L0041CDF4: raw word */\n"
    "lw $6, 0x4C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FF34 /* b .L0041CAC0: raw word */\n"
    "sd $6, 0x0($2)\n"
    ".L0041CDF4:\n"
    "andi $2, $18, 0x40\n"
    ".word 0x10400005 /* beqz $2, .L0041CE10: raw word */\n"
    "lw $3, 0x4C($29)\n"
    "addiu $19, $19, 0x8\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FF2D /* b .L0041CAC0: raw word */\n"
    "sh $3, 0x0($2)\n"
    ".L0041CE10:\n"
    "addiu $19, $19, 0x8\n"
    "lw $4, 0x4C($29)\n"
    "lw $2, -0x8($19)\n"
    ".word 0x1000FF28 /* b .L0041CAC0: raw word */\n"
    "sw $4, 0x0($2)\n"
    ".globl lbl_0041CE24\n"
    "lbl_0041CE24:\n"
    ".Llbl_0041CE24:\n"
    "ori $18, $18, 0x10\n"
    ".globl lbl_0041CE28\n"
    "lbl_0041CE28:\n"
    ".Llbl_0041CE28:\n"
    "andi $2, $18, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041CE44: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $18, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041CE4C: raw word */\n"
    "andi $2, $18, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041CE44:\n"
    ".word 0x10000006 /* b .L0041CE60: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041CE4C:\n"
    ".word 0x10400003 /* beqz $2, .L0041CE5C: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041CE60: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041CE5C:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041CE60:\n"
    ".word 0x1000004C /* b .L0041CF94: raw word */\n"
    "daddu $22, $0, $0\n"
    ".globl lbl_0041CE68\n"
    "lbl_0041CE68:\n"
    ".Llbl_0041CE68:\n"
    "lui $2, %hi(D_0049A5C0)\n"
    "addiu $19, $19, 0x8\n"
    "addiu $2, $2, %lo(D_0049A5C0)\n"
    "addiu $22, $0, 0x2\n"
    "sw $2, 0x5C($29)\n"
    "ori $18, $18, 0x2\n"
    "addiu $21, $0, 0x78\n"
    ".word 0x10000043 /* b .L0041CF94: raw word */\n"
    "lw $16, -0x8($19)\n"
    ".globl lbl_0041CE8C\n"
    "lbl_0041CE8C:\n"
    ".Llbl_0041CE8C:\n"
    "addiu $19, $19, 0x8\n"
    "lw $20, -0x8($19)\n"
    ".word 0x16800002 /* bnez $20, .L0041CEA0: raw word */\n"
    "lui $2, %hi(D_0049A5D8)\n"
    "addiu $20, $2, %lo(D_0049A5D8)\n"
    ".L0041CEA0:\n"
    ".word 0x07C0000B /* bltz $30, .L0041CED0: raw word */\n"
    "daddu $4, $20, $0\n"
    "daddu $5, $0, $0\n"
    "jal func_0041EC70\n"
    "daddu $6, $30, $0\n"
    ".word 0x10400004 /* beqz $2, .L0041CEC8: raw word */\n"
    "subu $2, $2, $20\n"
    "slt $3, $30, $2\n"
    ".word 0x10600006 /* beqz $3, .L0041CEDC: raw word */\n"
    "sw $2, 0x48($29)\n"
    ".L0041CEC8:\n"
    ".word 0x10000004 /* b .L0041CEDC: raw word */\n"
    "sw $30, 0x48($29)\n"
    ".L0041CED0:\n"
    "jal strlen\n"
    "daddu $4, $20, $0\n"
    "sw $2, 0x48($29)\n"
    ".L0041CEDC:\n"
    "andi $5, $18, 0x4\n"
    "sb $0, 0x42($29)\n"
    ".word 0x1000009B /* b .L0041D154: raw word */\n"
    "andi $30, $18, 0x84\n"
    ".globl lbl_0041CEEC\n"
    "lbl_0041CEEC:\n"
    ".Llbl_0041CEEC:\n"
    "ori $18, $18, 0x10\n"
    ".globl lbl_0041CEF0\n"
    "lbl_0041CEF0:\n"
    ".Llbl_0041CEF0:\n"
    "andi $2, $18, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041CF0C: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $18, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041CF14: raw word */\n"
    "andi $2, $18, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041CF0C:\n"
    ".word 0x10000006 /* b .L0041CF28: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041CF14:\n"
    ".word 0x10400003 /* beqz $2, .L0041CF24: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041CF28: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041CF24:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041CF28:\n"
    ".word 0x1000001A /* b .L0041CF94: raw word */\n"
    "addiu $22, $0, 0x1\n"
    ".globl lbl_0041CF30\n"
    "lbl_0041CF30:\n"
    ".Llbl_0041CF30:\n"
    "lui $2, %hi(D_0049A5E0)\n"
    ".word 0x10000003 /* b .L0041CF44: raw word */\n"
    "addiu $2, $2, %lo(D_0049A5E0)\n"
    ".globl lbl_0041CF3C\n"
    "lbl_0041CF3C:\n"
    ".Llbl_0041CF3C:\n"
    "lui $2, %hi(D_0049A5C0)\n"
    "addiu $2, $2, %lo(D_0049A5C0)\n"
    ".L0041CF44:\n"
    "sw $2, 0x5C($29)\n"
    "andi $2, $18, 0x20\n"
    ".word 0x54400005 /* bnel $2, $0, .L0041CF64: raw word */\n"
    "addiu $19, $19, 0x8\n"
    "andi $2, $18, 0x10\n"
    ".word 0x10400004 /* beqz $2, .L0041CF6C: raw word */\n"
    "andi $2, $18, 0x40\n"
    "addiu $19, $19, 0x8\n"
    ".L0041CF64:\n"
    ".word 0x10000006 /* b .L0041CF80: raw word */\n"
    "ld $16, -0x8($19)\n"
    ".L0041CF6C:\n"
    ".word 0x10400003 /* beqz $2, .L0041CF7C: raw word */\n"
    "addiu $19, $19, 0x8\n"
    ".word 0x10000002 /* b .L0041CF80: raw word */\n"
    "lhu $16, -0x8($19)\n"
    ".L0041CF7C:\n"
    "lwu $16, -0x8($19)\n"
    ".L0041CF80:\n"
    "andi $3, $18, 0x1\n"
    ".word 0x10600003 /* beqz $3, .L0041CF94: raw word */\n"
    "addiu $22, $0, 0x2\n"
    "ori $2, $18, 0x2\n"
    "movn $18, $2, $16\n"
    ".L0041CF94:\n"
    "sb $0, 0x42($29)\n"
    ".L0041CF98:\n"
    "daddu $6, $30, $0\n"
    ".word 0x04C00003 /* bltz $6, .L0041CFAC: raw word */\n"
    "sw $30, 0x54($29)\n"
    "addiu $2, $0, -0x81\n"
    "and $18, $18, $2\n"
    ".L0041CFAC:\n"
    ".word 0x16000006 /* bnez $16, .L0041CFC8: raw word */\n"
    "addiu $20, $29, 0x28\n"
    "andi $2, $18, 0x4\n"
    "lw $3, 0x54($29)\n"
    "andi $30, $18, 0x84\n"
    ".word 0x1060004C /* beqz $3, .L0041D0F4: raw word */\n"
    "sw $2, 0x68($29)\n"
    ".L0041CFC8:\n"
    "addiu $2, $0, 0x1\n"
    ".word 0x12C2001A /* beq $22, $2, .L0041D038: raw word */\n"
    "andi $5, $18, 0x4\n"
    ".word 0x12C00005 /* beqz $22, .L0041CFEC: raw word */\n"
    "addiu $2, $0, 0x2\n"
    ".word 0x12C2002E /* beq $22, $2, .L0041D098: raw word */\n"
    "lui $2, %hi(D_0049A5F8)\n"
    ".word 0x1000003C /* b .L0041D0D8: raw word */\n"
    "andi $4, $18, 0x4\n"
    ".L0041CFEC:\n"
    "andi $4, $18, 0x4\n"
    "andi $3, $18, 0x1\n"
    "sw $4, 0x68($29)\n"
    "andi $30, $18, 0x84\n"
    "nop\n"
    ".L0041D000:\n"
    "andi $2, $16, 0x7\n"
    "addiu $20, $20, -0x1\n"
    "daddiu $2, $2, 0x30\n"
    "dsrl $16, $16, 3\n"
    "andi $2, $2, 0xFF\n"
    ".word 0x1600FFFA /* bnez $16, .L0041D000: raw word */\n"
    "sb $2, 0x0($20)\n"
    ".word 0x10600035 /* beqz $3, .L0041D0F4: raw word */\n"
    "addiu $3, $0, 0x30\n"
    ".word 0x10430034 /* beq $2, $3, .L0041D0F8: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "addiu $20, $20, -0x1\n"
    ".word 0x10000031 /* b .L0041D0F8: raw word */\n"
    "sb $3, 0x0($20)\n"
    ".L0041D038:\n"
    "sltiu $2, $16, 0xA\n"
    "andi $30, $18, 0x84\n"
    ".word 0x14400010 /* bnez $2, .L0041D084: raw word */\n"
    "sw $5, 0x68($29)\n"
    "daddu $4, $16, $0\n"
    "nop\n"
    ".L0041D050:\n"
    "jal func_0042DAD8\n"
    "addiu $5, $0, 0xA\n"
    "addiu $20, $20, -0x1\n"
    "daddiu $2, $2, 0x30\n"
    "daddu $4, $16, $0\n"
    "andi $2, $2, 0xFF\n"
    "addiu $5, $0, 0xA\n"
    "jal func_00411538\n"
    "sb $2, 0x0($20)\n"
    "daddu $16, $2, $0\n"
    "sltiu $2, $16, 0xA\n"
    ".word 0x1040FFF4 /* beqz $2, .L0041D050: raw word */\n"
    "daddu $4, $16, $0\n"
    ".L0041D084:\n"
    "daddiu $2, $16, 0x30\n"
    "addiu $20, $20, -0x1\n"
    "andi $2, $2, 0xFF\n"
    ".word 0x10000018 /* b .L0041D0F4: raw word */\n"
    "sb $2, 0x0($20)\n"
    ".L0041D098:\n"
    "andi $6, $18, 0x4\n"
    "andi $30, $18, 0x84\n"
    "sw $6, 0x68($29)\n"
    "nop\n"
    ".L0041D0A8:\n"
    "lw $3, 0x5C($29)\n"
    "andi $2, $16, 0xF\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "addiu $20, $20, -0x1\n"
    "addu $2, $3, $2\n"
    "dsrl $16, $16, 4\n"
    "lbu $3, 0x0($2)\n"
    ".word 0x1600FFF7 /* bnez $16, .L0041D0A8: raw word */\n"
    "sb $3, 0x0($20)\n"
    ".word 0x10000009 /* b .L0041D0F8: raw word */\n"
    "addiu $2, $0, 0x1\n"
    ".L0041D0D8:\n"
    "addiu $20, $2, %lo(D_0049A5F8)\n"
    "sw $4, 0x68($29)\n"
    "daddu $4, $20, $0\n"
    "jal strlen\n"
    "andi $30, $18, 0x84\n"
    ".word 0x1000001A /* b .L0041D158: raw word */\n"
    "sw $2, 0x48($29)\n"
    ".L0041D0F4:\n"
    "addiu $2, $0, 0x1\n"
    ".L0041D0F8:\n"
    ".word 0x16C2000B /* bne $22, $2, .L0041D128: raw word */\n"
    "addiu $2, $20, -0x28\n"
    "andi $2, $18, 0x200\n"
    ".word 0x10400007 /* beqz $2, .L0041D124: raw word */\n"
    "daddu $5, $20, $0\n"
    "addiu $6, $29, 0x28\n"
    "daddu $4, $29, $0\n"
    "jal func_0041C788\n"
    "addiu $7, $29, 0x48\n"
    ".word 0x1000000E /* b .L0041D158: raw word */\n"
    "daddu $20, $2, $0\n"
    ".L0041D124:\n"
    "addiu $2, $20, -0x28\n"
    ".L0041D128:\n"
    "subu $3, $29, $2\n"
    ".word 0x1000000A /* b .L0041D158: raw word */\n"
    "sw $3, 0x48($29)\n"
    ".globl lbl_0041D134\n"
    "lbl_0041D134:\n"
    ".Llbl_0041D134:\n"
    ".word 0x12A00200 /* beqz $21, .L0041D938: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "andi $5, $18, 0x4\n"
    "sb $21, 0x0($29)\n"
    "daddu $20, $29, $0\n"
    "sw $2, 0x48($29)\n"
    "andi $30, $18, 0x84\n"
    "sb $0, 0x42($29)\n"
    ".L0041D154:\n"
    "sw $5, 0x68($29)\n"
    ".L0041D158:\n"
    "lw $6, 0x48($29)\n"
    "lw $4, 0x54($29)\n"
    "lb $3, 0x42($29)\n"
    "slt $2, $6, $4\n"
    "movz $4, $6, $2\n"
    ".word 0x10600004 /* beqz $3, .L0041D180: raw word */\n"
    "sw $4, 0x58($29)\n"
    "addiu $4, $4, 0x1\n"
    ".word 0x10000005 /* b .L0041D190: raw word */\n"
    "sw $4, 0x58($29)\n"
    ".L0041D180:\n"
    "lw $5, 0x58($29)\n"
    "andi $2, $18, 0x2\n"
    "addu $5, $2, $5\n"
    "sw $5, 0x58($29)\n"
    ".L0041D190:\n"
    ".word 0x17C0005B /* bnez $30, .L0041D300: raw word */\n"
    "lb $2, 0x42($29)\n"
    "lw $6, 0x50($29)\n"
    "lw $2, 0x58($29)\n"
    "subu $16, $6, $2\n"
    ".word 0x1A000055 /* blez $16, .L0041D2FC: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002F /* bnez $2, .L0041D26C: raw word */\n"
    "lui $22, %hi(D_0049A5A0)\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D1B8:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041D238: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041D218: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $6, $22, %lo(D_0049A5A0)\n"
    "ldl $3, 0x7($6)\n"
    "ldr $3, 0x0($6)\n"
    "ldl $4, 0xF($6)\n"
    "ldr $4, 0x8($6)\n"
    "sdl $3, 0x7($2)\n"
    "sdr $3, 0x0($2)\n"
    "sdl $4, 0xF($2)\n"
    "sdr $4, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000012 /* b .L0041D25C: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D218:\n"
    "jal func_0041605C\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041D25C: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D238:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D24C: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D24C:\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D25C:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD4 /* beql $2, $0, .L0041D1B8: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D26C:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041D2D8: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041D2B4: raw word */\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041D2FC: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D2B4:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041D2FC: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D2D8:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D2EC: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D2EC:\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D2FC:\n"
    "lb $2, 0x42($29)\n"
    ".L0041D300:\n"
    ".word 0x1040001D /* beqz $2, .L0041D378: raw word */\n"
    "lbu $3, 0x42($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040000E /* beql $2, $0, .L0041D34C: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x2\n"
    ".word 0x54400008 /* bnel $2, $0, .L0041D344: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "sb $3, 0x0($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x1\n"
    ".word 0x10000023 /* b .L0041D3CC: raw word */\n"
    "addiu $2, $2, -0x1\n"
    ".L0041D344:\n"
    ".word 0x10000025 /* b .L0041D3DC: raw word */\n"
    "addiu $5, $29, 0x42\n"
    ".L0041D34C:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D360: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D360:\n"
    "addiu $5, $29, 0x42\n"
    "addiu $6, $0, 0x1\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".word 0x1000002D /* b .L0041D428: raw word */\n"
    "addiu $2, $0, 0x80\n"
    ".L0041D378:\n"
    "andi $2, $18, 0x2\n"
    ".word 0x10400029 /* beqz $2, .L0041D424: raw word */\n"
    "addiu $2, $0, 0x30\n"
    "lhu $3, 0xC($17)\n"
    "sb $2, 0x30($29)\n"
    "andi $3, $3, 0x200\n"
    ".word 0x1060001A /* beqz $3, .L0041D3FC: raw word */\n"
    "sb $21, 0x31($29)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x3\n"
    ".word 0x5440000D /* bnel $2, $0, .L0041D3D8: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "lb $3, 0x30($29)\n"
    "lb $4, 0x31($29)\n"
    "sb $3, 0x0($2)\n"
    "sb $4, 0x1($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x2\n"
    "addiu $2, $2, -0x2\n"
    ".L0041D3CC:\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000014 /* b .L0041D424: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D3D8:\n"
    "addiu $5, $29, 0x30\n"
    ".L0041D3DC:\n"
    "jal func_0041605C\n"
    "nop\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000B /* b .L0041D424: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D3FC:\n"
    "lw $2, 0xC($17)\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D414: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D414:\n"
    "addiu $5, $29, 0x30\n"
    "addiu $6, $0, 0x2\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D424:\n"
    "addiu $2, $0, 0x80\n"
    ".L0041D428:\n"
    ".word 0x17C2005B /* bne $30, $2, .L0041D598: raw word */\n"
    "lw $2, 0x48($29)\n"
    "lw $2, 0x50($29)\n"
    "lw $3, 0x58($29)\n"
    "subu $16, $2, $3\n"
    ".word 0x1A000055 /* blez $16, .L0041D594: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002F /* bnez $2, .L0041D504: raw word */\n"
    "lui $18, %hi(D_0049A5B0)\n"
    "addiu $21, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    "nop\n"
    ".L0041D458:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041D4D8: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041D4B8: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $3, $18, %lo(D_0049A5B0)\n"
    "ldl $4, 0x7($3)\n"
    "ldr $4, 0x0($3)\n"
    "ldl $5, 0xF($3)\n"
    "ldr $5, 0x8($3)\n"
    "sdl $4, 0x7($2)\n"
    "sdr $4, 0x0($2)\n"
    "sdl $5, 0xF($2)\n"
    "sdr $5, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041D4F4: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D4B8:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041D4F4: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D4D8:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041D4E0: raw word */\n"
    "sh $21, 0xE($17)\n"
    ".L0041D4E0:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D4F4:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041D458: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D504:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041D570: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041D54C: raw word */\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041D594: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D54C:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041D594: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D570:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D584: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D584:\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D594:\n"
    "lw $2, 0x48($29)\n"
    ".L0041D598:\n"
    "lw $4, 0x54($29)\n"
    "subu $16, $4, $2\n"
    ".word 0x1A000054 /* blez $16, .L0041D6F4: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002E /* bnez $2, .L0041D664: raw word */\n"
    "lui $18, %hi(D_0049A5B0)\n"
    "addiu $21, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D5B8:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041D638: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041D618: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $4, $18, %lo(D_0049A5B0)\n"
    "ldl $5, 0x7($4)\n"
    "ldr $5, 0x0($4)\n"
    "ldl $6, 0xF($4)\n"
    "ldr $6, 0x8($4)\n"
    "sdl $5, 0x7($2)\n"
    "sdr $5, 0x0($2)\n"
    "sdl $6, 0xF($2)\n"
    "sdr $6, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041D654: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D618:\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041D654: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D638:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041D640: raw word */\n"
    "sh $21, 0xE($17)\n"
    ".L0041D640:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D654:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041D5B8: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D664:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041D6D0: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041D6AC: raw word */\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041D6F4: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D6AC:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041D6F4: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D6D0:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D6E4: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D6E4:\n"
    "addiu $5, $18, %lo(D_0049A5B0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D6F4:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x10400018 /* beqz $2, .L0041D760: raw word */\n"
    "lw $6, 0x48($29)\n"
    "lw $3, 0x8($17)\n"
    "slt $2, $6, $3\n"
    ".word 0x1040000B /* beqz $2, .L0041D73C: raw word */\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $4, 0x48($29)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $4\n"
    "subu $2, $2, $4\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000014 /* b .L0041D788: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D73C:\n"
    "daddu $6, $3, $0\n"
    "jal func_0041605C\n"
    "daddu $5, $20, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000B /* b .L0041D788: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D760:\n"
    "lw $2, 0xC($17)\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D778: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D778:\n"
    "daddu $5, $20, $0\n"
    "lw $6, 0x48($29)\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D788:\n"
    "lw $5, 0x68($29)\n"
    ".word 0x10A00059 /* beqz $5, .L0041D8F4: raw word */\n"
    "lw $6, 0x50($29)\n"
    "lw $2, 0x58($29)\n"
    "subu $16, $6, $2\n"
    ".word 0x1A000055 /* blez $16, .L0041D8F4: raw word */\n"
    "slti $2, $16, 0x11\n"
    ".word 0x1440002F /* bnez $2, .L0041D864: raw word */\n"
    "lui $22, %hi(D_0049A5A0)\n"
    "addiu $18, $0, 0x1\n"
    "lhu $2, 0xC($17)\n"
    "nop\n"
    ".L0041D7B8:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x5040001E /* beql $2, $0, .L0041D838: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slti $2, $6, 0x11\n"
    ".word 0x54400012 /* bnel $2, $0, .L0041D818: raw word */\n"
    "lw $4, 0x0($17)\n"
    "lw $2, 0x0($17)\n"
    "addiu $6, $22, %lo(D_0049A5A0)\n"
    "ldl $3, 0x7($6)\n"
    "ldr $3, 0x0($6)\n"
    "ldl $4, 0xF($6)\n"
    "ldr $4, 0x8($6)\n"
    "sdl $3, 0x7($2)\n"
    "sdr $3, 0x0($2)\n"
    "sdl $4, 0xF($2)\n"
    "sdr $4, 0x8($2)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addiu $3, $3, 0x10\n"
    "addiu $2, $2, -0x10\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000010 /* b .L0041D854: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D818:\n"
    "jal func_0041605C\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x10000008 /* b .L0041D854: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D838:\n"
    ".word 0x50400001 /* beql $2, $0, .L0041D840: raw word */\n"
    "sh $18, 0xE($17)\n"
    ".L0041D840:\n"
    "lh $4, 0xE($17)\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "addiu $6, $0, 0x10\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D854:\n"
    "addiu $16, $16, -0x10\n"
    "slti $2, $16, 0x11\n"
    ".word 0x5040FFD6 /* beql $2, $0, .L0041D7B8: raw word */\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D864:\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x50400018 /* beql $2, $0, .L0041D8D0: raw word */\n"
    "lw $2, 0xC($17)\n"
    "lw $6, 0x8($17)\n"
    "slt $2, $16, $6\n"
    ".word 0x1040000B /* beqz $2, .L0041D8AC: raw word */\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "daddu $6, $16, $0\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "addu $3, $3, $16\n"
    "subu $2, $2, $16\n"
    "sw $3, 0x0($17)\n"
    ".word 0x10000013 /* b .L0041D8F4: raw word */\n"
    "sw $2, 0x8($17)\n"
    ".L0041D8AC:\n"
    "lw $4, 0x0($17)\n"
    "jal func_0041605C\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "lw $3, 0x0($17)\n"
    "lw $2, 0x8($17)\n"
    "sw $0, 0x8($17)\n"
    "addu $3, $3, $2\n"
    ".word 0x1000000A /* b .L0041D8F4: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0041D8D0:\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041D8E4: raw word */\n"
    "lh $4, 0xE($17)\n"
    "addiu $2, $0, 0x1\n"
    "sh $2, 0xE($17)\n"
    "lh $4, 0xE($17)\n"
    ".L0041D8E4:\n"
    "addiu $5, $22, %lo(D_0049A5A0)\n"
    "daddu $6, $16, $0\n"
    "jal func_0041C938\n"
    "daddu $7, $0, $0\n"
    ".L0041D8F4:\n"
    "lw $2, 0x8($17)\n"
    ".word 0x1C400008 /* bgtz $2, .L0041D91C: raw word */\n"
    "lw $3, 0x58($29)\n"
    "lhu $2, 0xC($17)\n"
    "andi $2, $2, 0x200\n"
    ".word 0x10400005 /* beqz $2, .L0041D920: raw word */\n"
    "lw $4, 0x50($29)\n"
    "lw $2, 0x14($17)\n"
    ".word 0x1000FC6A /* b .L0041CAC0: raw word */\n"
    "sw $2, 0x4C($29)\n"
    ".L0041D91C:\n"
    "lw $4, 0x50($29)\n"
    ".L0041D920:\n"
    "lw $5, 0x4C($29)\n"
    "slt $2, $3, $4\n"
    "movz $4, $3, $2\n"
    "addu $5, $5, $4\n"
    ".word 0x1000FC63 /* b .L0041CAC0: raw word */\n"
    "sw $5, 0x4C($29)\n"
    ".L0041D938:\n"
    "lhu $2, 0xC($17)\n"
    ".L0041D93C:\n"
    "andi $2, $2, 0x200\n"
    ".word 0x14400007 /* bnez $2, .L0041D960: raw word */\n"
    "lw $2, 0x4C($29)\n"
    "lh $4, 0xE($17)\n"
    "daddu $5, $0, $0\n"
    "daddu $6, $0, $0\n"
    "jal func_0041C938\n"
    "addiu $7, $0, 0x1\n"
    "lw $2, 0x4C($29)\n"
    ".L0041D960:\n"
    "lq $16, 0x100($29)\n"
    "lq $17, 0xF0($29)\n"
    "lq $18, 0xE0($29)\n"
    "lq $19, 0xD0($29)\n"
    "lq $20, 0xC0($29)\n"
    "lq $21, 0xB0($29)\n"
    "lq $22, 0xA0($29)\n"
    "lq $23, 0x90($29)\n"
    "lq $30, 0x80($29)\n"
    "ld $31, 0x70($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x110\n"
    ".end func_0041CA70\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041D990);
#ifdef SKIP_ASM
struct mchunk {
    unsigned prev_size, size;
    struct mchunk *fd, *bk;
};
typedef struct mchunk *mchunkptr;
extern unsigned D_00454CE8[];
extern unsigned long D_004550F0;
extern unsigned long D_004550F8;
extern unsigned D_00454CF0[];
#define bin_at(i) ((mchunkptr)((char *)&D_00454CE8[2 * (i) + 2] - 8))
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define lr2 ((mchunkptr)D_00454CF0)
#define binblocks (bin_at(0)->size)
#define chunk_at_offset(p, s) ((mchunkptr)((char *)(p) + (s)))
#define chunksize(p) ((p)->size & ~3u)
#define inuse_bit_at_offset(p, s) (chunk_at_offset(p, s)->size & 1)
#define unlink(P, BK, FD) \
    { \
        BK = (P)->bk; \
        FD = (P)->fd; \
        FD->bk = BK; \
        BK->fd = FD; \
    }
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (chunk_at_offset(p, s)->prev_size = (s))
#define idx2binblock(ix) ((unsigned long)1 << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define smallbin_index(sz) (((unsigned)(sz)) >> 3)
#define bin_index(sz) \
    ((((unsigned)(sz)) >> 9 == 0) ? (((unsigned)(sz)) >> 3) \
    : (((unsigned)(sz)) >> 9 <= 4) ? 56 + (((unsigned)(sz)) >> 6) \
    : (((unsigned)(sz)) >> 9 <= 20) ? 91 + (((unsigned)(sz)) >> 9) \
    : (((unsigned)(sz)) >> 9 <= 84) ? 110 + (((unsigned)(sz)) >> 12) \
    : (((unsigned)(sz)) >> 9 <= 340) ? 119 + (((unsigned)(sz)) >> 15) \
    : (((unsigned)(sz)) >> 9 <= 1364) ? 124 + (((unsigned)(sz)) >> 18) \
    : 126)
#define frontlink(P, S, IDX, BK, FD) \
    { \
        if (S < 512) { \
            IDX = smallbin_index(S); \
            mark_binblock(IDX); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } else { \
            IDX = bin_index(S); \
            BK = bin_at(IDX); \
            FD = BK->fd; \
            if (FD == BK) { \
                mark_binblock(IDX); \
            } else { \
                while (FD != BK && S < chunksize(FD)) \
                    FD = FD->fd; \
                BK = FD->bk; \
            } \
            P->bk = BK; \
            P->fd = FD; \
            FD->bk = BK->fd = P; \
        } \
    }
#define link_last_remainder(P) \
    { \
        lr->fd = lr->bk = P; \
        P->fd = P->bk = lr; \
    }

#define set_head_size(p, s) ((p)->size = (((p)->size & 1) | (s)))
extern char *D_00455100;
extern int D_00455118;
extern unsigned long D_00455108;
extern unsigned long D_00455110;
extern char *func_0041FD70_sbrk(int, int) __asm__("func_0041FD70");
extern void func_0041E340_free(int, void *) __asm__("func_0041E340");
void func_0041D990_(int ptr, unsigned nb) __asm__("func_0041D990");
void func_0041D990_(int ptr, unsigned nb) {
    char *brk;
    unsigned front_misalign;
    unsigned correction;
    char *new_brk;
    unsigned top_size;
    mchunkptr old_top = top;
    unsigned old_top_size = chunksize(old_top);
    char *old_end = (char *)chunk_at_offset(old_top, old_top_size);
    unsigned sbrk_size = nb + D_004550F8 + 16;
    unsigned long pagesz = 0x1000;
    if (D_00455100 != (char *)-1)
        sbrk_size = (sbrk_size + (pagesz - 1)) & ~(pagesz - 1);
    brk = func_0041FD70_sbrk(ptr, sbrk_size);
    if (brk == (char *)-1 || (brk < old_end && old_top != (mchunkptr)D_00454CE8))
        return;
    D_00455118 += sbrk_size;
    if (brk == old_end) {
        top_size = sbrk_size + old_top_size;
        set_head(top, top_size | 1);
    } else {
        if (D_00455100 == (char *)-1)
            D_00455100 = brk;
        else
            D_00455118 += brk - old_end;
        front_misalign = (unsigned long)(brk + 8) & 15;
        if (front_misalign > 0) {
            correction = 16 - front_misalign;
            brk += correction;
        } else
            correction = 0;
        correction += pagesz - ((unsigned long)(brk + sbrk_size) & (pagesz - 1));
        new_brk = func_0041FD70_sbrk(ptr, correction);
        if (new_brk == (char *)-1)
            return;
        D_00455118 += correction;
        top = (mchunkptr)brk;
        top_size = new_brk - brk + correction;
        set_head(top, top_size | 1);
        if (old_top != (mchunkptr)D_00454CE8) {
            if (old_top_size < 16) {
                set_head(top, 1);
                return;
            }
            old_top_size = (old_top_size - 12) & ~15u;
            set_head_size(old_top, old_top_size);
            chunk_at_offset(old_top, old_top_size)->size = 5;
            chunk_at_offset(old_top, old_top_size + 4)->size = 5;
            if (old_top_size >= 16)
                func_0041E340_free(ptr, (char *)old_top + 8);
        }
    }
    if ((unsigned long)D_00455118 > D_00455108)
        D_00455108 = D_00455118;
    if ((unsigned long)D_00455118 > D_00455110)
        D_00455110 = D_00455118;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041DBF8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041DBF8\n.ent func_0041DBF8\nfunc_0041DBF8:\n"
    "addiu $29, $29, -0x60\n"
    "addiu $5, $5, 0x13\n"
    "sq $19, 0x20($29)\n"
    "sltiu $2, $5, 0x1F\n"
    "sq $16, 0x50($29)\n"
    "daddu $19, $4, $0\n"
    "sq $17, 0x40($29)\n"
    "sq $18, 0x30($29)\n"
    "sq $20, 0x10($29)\n"
    ".word 0x14400005 /* bnez $2, .L0041DC34: raw word */\n"
    "sd $31, 0x0($29)\n"
    "lui $2, (0xFFFFFFF0 >> 16)\n"
    "ori $2, $2, (0xFFFFFFF0 & 0xFFFF)\n"
    ".word 0x10000002 /* b .L0041DC38: raw word */\n"
    "and $17, $5, $2\n"
    ".L0041DC34:\n"
    "addiu $17, $0, 0x10\n"
    ".L0041DC38:\n"
    "jal func_00418CA8\n"
    "daddu $4, $19, $0\n"
    "sltiu $2, $17, 0x1F8\n"
    ".word 0x10400016 /* beqz $2, .L0041DCA0: raw word */\n"
    "lui $2, %hi(D_00454CE8)\n"
    "srl $10, $17, 3\n"
    "addiu $3, $2, %lo(D_00454CE8)\n"
    "addu $9, $17, $3\n"
    "lw $16, 0xC($9)\n"
    ".word 0x1209000E /* beq $16, $9, .L0041DC98: raw word */\n"
    "daddu $20, $2, $0\n"
    "lw $8, 0xC($16)\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "lw $6, 0x8($16)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $5, 0x4($16)\n"
    "daddu $4, $19, $0\n"
    "sw $8, 0xC($6)\n"
    "sw $6, 0x8($8)\n"
    "and $5, $5, $2\n"
    "addu $3, $16, $5\n"
    "lw $2, 0x4($3)\n"
    ".word 0x1000019E /* b .L0041E30C: raw word */\n"
    "ori $2, $2, 0x1\n"
    ".L0041DC98:\n"
    ".word 0x1000003D /* b .L0041DD90: raw word */\n"
    "addiu $10, $10, 0x2\n"
    ".L0041DCA0:\n"
    "srl $4, $17, 9\n"
    ".word 0x14800003 /* bnez $4, .L0041DCB4: raw word */\n"
    "sltiu $2, $4, 0x5\n"
    ".word 0x10000018 /* b .L0041DD10: raw word */\n"
    "srl $10, $17, 3\n"
    ".L0041DCB4:\n"
    ".word 0x10400003 /* beqz $2, .L0041DCC4: raw word */\n"
    "srl $2, $17, 6\n"
    ".word 0x10000014 /* b .L0041DD10: raw word */\n"
    "addiu $10, $2, 0x38\n"
    ".L0041DCC4:\n"
    "sltiu $2, $4, 0x15\n"
    ".word 0x14400011 /* bnez $2, .L0041DD10: raw word */\n"
    "addiu $10, $4, 0x5B\n"
    "sltiu $2, $4, 0x55\n"
    ".word 0x10400003 /* beqz $2, .L0041DCE4: raw word */\n"
    "srl $2, $17, 12\n"
    ".word 0x1000000C /* b .L0041DD10: raw word */\n"
    "addiu $10, $2, 0x6E\n"
    ".L0041DCE4:\n"
    "sltiu $2, $4, 0x155\n"
    ".word 0x10400003 /* beqz $2, .L0041DCF8: raw word */\n"
    "srl $2, $17, 15\n"
    ".word 0x10000007 /* b .L0041DD10: raw word */\n"
    "addiu $10, $2, 0x77\n"
    ".L0041DCF8:\n"
    "sltiu $2, $4, 0x555\n"
    ".word 0x10400003 /* beqz $2, .L0041DD0C: raw word */\n"
    "srl $2, $17, 18\n"
    ".word 0x10000002 /* b .L0041DD10: raw word */\n"
    "addiu $10, $2, 0x7C\n"
    ".L0041DD0C:\n"
    "addiu $10, $0, 0x7E\n"
    ".L0041DD10:\n"
    "lui $2, %hi(D_00454CE8)\n"
    "sll $4, $10, 3\n"
    "addiu $3, $2, %lo(D_00454CE8)\n"
    "addu $8, $4, $3\n"
    "lw $16, 0xC($8)\n"
    ".word 0x10000005 /* b .L0041DD3C: raw word */\n"
    "daddu $20, $2, $0\n"
    "nop\n"
    ".L0041DD30:\n"
    ".word 0x04E30145 /* bgezl $7, .L0041E248: raw word */\n"
    "lw $8, 0xC($16)\n"
    "lw $16, 0xC($16)\n"
    ".L0041DD3C:\n"
    ".word 0x52080014 /* beql $16, $8, .L0041DD90: raw word */\n"
    "addiu $10, $10, 0x1\n"
    "lw $2, 0x4($16)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "and $5, $2, $3\n"
    "sltu $4, $5, $17\n"
    ".word 0x10800005 /* beqz $4, .L0041DD70: raw word */\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    ".word 0x10000004 /* b .L0041DD7C: raw word */\n"
    "dsubu $7, $0, $2\n"
    ".L0041DD70:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    ".L0041DD7C:\n"
    "slti $2, $7, 0x10\n"
    ".word 0x1440FFEB /* bnez $2, .L0041DD30: raw word */\n"
    "nop\n"
    "addiu $10, $10, -0x1\n"
    "addiu $10, $10, 0x1\n"
    ".L0041DD90:\n"
    "lui $2, %hi(D_00454CF0)\n"
    "daddu $14, $2, $0\n"
    "addiu $2, $2, %lo(D_00454CF0)\n"
    "lw $16, 0x8($2)\n"
    ".word 0x12020086 /* beq $16, $2, .L0041DFBC: raw word */\n"
    "addiu $2, $0, -0x1\n"
    "lw $2, 0x4($16)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "and $5, $2, $3\n"
    "sltu $4, $5, $17\n"
    ".word 0x10800005 /* beqz $4, .L0041DDD4: raw word */\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    ".word 0x10000004 /* b .L0041DDE0: raw word */\n"
    "dsubu $7, $0, $2\n"
    ".L0041DDD4:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    ".L0041DDE0:\n"
    "slti $2, $7, 0x10\n"
    ".word 0x14400014 /* bnez $2, .L0041DE38: raw word */\n"
    "addiu $4, $14, %lo(D_00454CF0)\n"
    "ori $2, $17, 0x1\n"
    "addiu $3, $0, 0x1\n"
    "sw $2, 0x4($16)\n"
    "addu $8, $16, $17\n"
    "addiu $5, $14, %lo(D_00454CF0)\n"
    "or $3, $7, $3\n"
    "sw $8, 0xC($5)\n"
    "dsll32 $2, $7, 0\n"
    "dsra32 $2, $2, 0\n"
    "sw $8, 0x8($5)\n"
    "dsll32 $3, $3, 0\n"
    "dsra32 $3, $3, 0\n"
    "addu $6, $8, $2\n"
    "sw $5, 0x8($8)\n"
    "sw $3, 0x4($8)\n"
    "daddu $4, $19, $0\n"
    "sw $5, 0xC($8)\n"
    ".word 0x10000137 /* b .L0041E310: raw word */\n"
    "sw $2, 0x0($6)\n"
    ".L0041DE38:\n"
    "sw $4, 0xC($4)\n"
    ".word 0x04E00006 /* bltz $7, .L0041DE58: raw word */\n"
    "sw $4, 0x8($4)\n"
    "addu $3, $16, $5\n"
    "daddu $4, $19, $0\n"
    "lw $2, 0x4($3)\n"
    ".word 0x1000012E /* b .L0041E30C: raw word */\n"
    "ori $2, $2, 0x1\n"
    ".L0041DE58:\n"
    "sltiu $2, $5, 0x200\n"
    ".word 0x10400012 /* beqz $2, .L0041DEA8: raw word */\n"
    "srl $7, $5, 3\n"
    "addiu $2, $0, -0x1\n"
    "slt $2, $2, $7\n"
    "addiu $3, $7, 0x3\n"
    "movn $3, $7, $2\n"
    "addiu $5, $4, -0x8\n"
    "sra $3, $3, 2\n"
    "addiu $2, $0, 0x1\n"
    "lw $4, 0x4($5)\n"
    "dsllv $2, $2, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "sll $3, $7, 3\n"
    "or $4, $4, $2\n"
    "addu $8, $3, $5\n"
    "sw $4, 0x4($5)\n"
    ".word 0x10000041 /* b .L0041DFA8: raw word */\n"
    "lw $6, 0x8($8)\n"
    ".L0041DEA8:\n"
    "srl $3, $5, 9\n"
    ".word 0x14600003 /* bnez $3, .L0041DEBC: raw word */\n"
    "sltiu $2, $3, 0x5\n"
    ".word 0x10000018 /* b .L0041DF18: raw word */\n"
    "srl $7, $5, 3\n"
    ".L0041DEBC:\n"
    ".word 0x10400003 /* beqz $2, .L0041DECC: raw word */\n"
    "srl $2, $5, 6\n"
    ".word 0x10000014 /* b .L0041DF18: raw word */\n"
    "addiu $7, $2, 0x38\n"
    ".L0041DECC:\n"
    "sltiu $2, $3, 0x15\n"
    ".word 0x14400011 /* bnez $2, .L0041DF18: raw word */\n"
    "addiu $7, $3, 0x5B\n"
    "sltiu $2, $3, 0x55\n"
    ".word 0x10400003 /* beqz $2, .L0041DEEC: raw word */\n"
    "srl $2, $5, 12\n"
    ".word 0x1000000C /* b .L0041DF18: raw word */\n"
    "addiu $7, $2, 0x6E\n"
    ".L0041DEEC:\n"
    "sltiu $2, $3, 0x155\n"
    ".word 0x10400003 /* beqz $2, .L0041DF00: raw word */\n"
    "srl $2, $5, 15\n"
    ".word 0x10000007 /* b .L0041DF18: raw word */\n"
    "addiu $7, $2, 0x77\n"
    ".L0041DF00:\n"
    "sltiu $2, $3, 0x555\n"
    ".word 0x10400003 /* beqz $2, .L0041DF14: raw word */\n"
    "srl $2, $5, 18\n"
    ".word 0x10000002 /* b .L0041DF18: raw word */\n"
    "addiu $7, $2, 0x7C\n"
    ".L0041DF14:\n"
    "addiu $7, $0, 0x7E\n"
    ".L0041DF18:\n"
    "sll $2, $7, 3\n"
    "addiu $9, $20, %lo(D_00454CE8)\n"
    "addu $8, $2, $9\n"
    "lw $6, 0x8($8)\n"
    ".word 0x54C8000E /* bnel $6, $8, .L0041DF64: raw word */\n"
    "lw $3, 0x4($6)\n"
    "addiu $2, $0, -0x1\n"
    "addiu $3, $7, 0x3\n"
    "slt $2, $2, $7\n"
    "addiu $4, $0, 0x1\n"
    "movn $3, $7, $2\n"
    "lw $5, 0x4($9)\n"
    "sra $3, $3, 2\n"
    "dsllv $4, $4, $3\n"
    "dsll32 $4, $4, 0\n"
    "dsra32 $4, $4, 0\n"
    "or $5, $5, $4\n"
    ".word 0x10000012 /* b .L0041DFA8: raw word */\n"
    "sw $5, 0x4($9)\n"
    ".L0041DF64:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "and $3, $3, $2\n"
    "sltu $3, $5, $3\n"
    ".word 0x5060000C /* beql $3, $0, .L0041DFA8: raw word */\n"
    "lw $8, 0xC($6)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $6, 0x8($6)\n"
    ".L0041DF88:\n"
    ".word 0x50C80007 /* beql $6, $8, .L0041DFA8: raw word */\n"
    "lw $8, 0xC($6)\n"
    "lw $2, 0x4($6)\n"
    "and $2, $2, $3\n"
    "sltu $2, $5, $2\n"
    ".word 0x5440FFFA /* bnel $2, $0, .L0041DF88: raw word */\n"
    "lw $6, 0x8($6)\n"
    "lw $8, 0xC($6)\n"
    ".L0041DFA8:\n"
    "sw $8, 0xC($16)\n"
    "sw $6, 0x8($16)\n"
    "sw $16, 0x8($8)\n"
    "sw $16, 0xC($6)\n"
    "addiu $2, $0, -0x1\n"
    ".L0041DFBC:\n"
    "addiu $4, $10, 0x3\n"
    "slt $2, $2, $10\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "movn $4, $10, $2\n"
    "lwu $5, 0x4($3)\n"
    "sra $4, $4, 2\n"
    "addiu $2, $0, 0x1\n"
    "dsllv $6, $2, $4\n"
    "sltu $3, $5, $6\n"
    ".word 0x14600060 /* bnez $3, .L0041E164: raw word */\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "and $2, $6, $5\n"
    ".word 0x14400010 /* bnez $2, .L0041E030: raw word */\n"
    "lui $2, %hi(D_00454CE8)\n"
    "addiu $2, $0, -0x4\n"
    "dsll $6, $6, 1\n"
    "and $2, $10, $2\n"
    "and $3, $6, $5\n"
    ".word 0x14600009 /* bnez $3, .L0041E02C: raw word */\n"
    "addiu $10, $2, 0x4\n"
    "daddu $3, $5, $0\n"
    ".L0041E010:\n"
    "dsll $6, $6, 1\n"
    "and $2, $6, $3\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1040FFFA /* beqz $2, .L0041E010: raw word */\n"
    "addiu $10, $10, 0x4\n"
    ".L0041E02C:\n"
    "lui $2, %hi(D_00454CE8)\n"
    ".L0041E030:\n"
    "addiu $12, $2, %lo(D_00454CE8)\n"
    "daddu $13, $12, $0\n"
    "sll $2, $10, 3\n"
    "nop\n"
    ".L0041E040:\n"
    "daddu $11, $10, $0\n"
    "addu $9, $2, $12\n"
    "daddu $8, $9, $0\n"
    "lw $16, 0xC($8)\n"
    ".L0041E050:\n"
    ".word 0x12080019 /* beq $16, $8, .L0041E0B8: raw word */\n"
    "slti $2, $10, 0x3F\n"
    "lui $4, (0xFFFFFFFC >> 16)\n"
    "ori $4, $4, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($16)\n"
    "nop\n"
    ".L0041E068:\n"
    "and $5, $2, $4\n"
    "sltu $3, $5, $17\n"
    ".word 0x10600005 /* beqz $3, .L0041E088: raw word */\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    ".word 0x10000004 /* b .L0041E094: raw word */\n"
    "dsubu $7, $0, $2\n"
    ".L0041E088:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    ".L0041E094:\n"
    "slti $2, $7, 0x10\n"
    ".word 0x50400073 /* beql $2, $0, .L0041E268: raw word */\n"
    "lw $8, 0xC($16)\n"
    ".word 0x04E10087 /* bgez $7, .L0041E2C0: raw word */\n"
    "addu $3, $16, $5\n"
    "lw $16, 0xC($16)\n"
    ".word 0x5608FFEE /* bnel $16, $8, .L0041E068: raw word */\n"
    "lw $2, 0x4($16)\n"
    "slti $2, $10, 0x3F\n"
    ".L0041E0B8:\n"
    ".word 0x10400003 /* beqz $2, .L0041E0C8: raw word */\n"
    "addiu $8, $8, 0x8\n"
    "addiu $8, $8, 0x8\n"
    "addiu $10, $10, 0x1\n"
    ".L0041E0C8:\n"
    "addiu $10, $10, 0x1\n"
    "andi $2, $10, 0x3\n"
    ".word 0x5440FFDF /* bnel $2, $0, .L0041E050: raw word */\n"
    "lw $16, 0xC($8)\n"
    ".L0041E0D8:\n"
    "andi $2, $11, 0x3\n"
    ".word 0x10400019 /* beqz $2, .L0041E144: raw word */\n"
    "addiu $9, $9, -0x8\n"
    "lw $2, 0x8($9)\n"
    "nop\n"
    ".word 0x1049FFFA /* beq $2, $9, .L0041E0D8: raw word */\n"
    "addiu $11, $11, -0x1\n"
    ".L0041E0F4:\n"
    "lwu $3, 0x4($12)\n"
    "dsll $6, $6, 1\n"
    "sltu $2, $3, $6\n"
    ".word 0x54400018 /* bnel $2, $0, .L0041E164: raw word */\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    ".word 0x10C00015 /* beqz $6, .L0041E160: raw word */\n"
    "and $2, $6, $3\n"
    ".word 0x1440FFCB /* bnez $2, .L0041E040: raw word */\n"
    "sll $2, $10, 3\n"
    "lwu $3, 0x4($13)\n"
    "nop\n"
    ".L0041E120:\n"
    "dsll $6, $6, 1\n"
    "and $2, $6, $3\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1040FFFA /* beqz $2, .L0041E120: raw word */\n"
    "addiu $10, $10, 0x4\n"
    ".word 0x1000FFC0 /* b .L0041E040: raw word */\n"
    "sll $2, $10, 3\n"
    ".L0041E144:\n"
    "lw $3, 0x4($12)\n"
    "dsll32 $2, $6, 0\n"
    "dsra32 $2, $2, 0\n"
    "nor $2, $0, $2\n"
    "and $3, $3, $2\n"
    ".word 0x1000FFE6 /* b .L0041E0F4: raw word */\n"
    "sw $3, 0x4($12)\n"
    ".L0041E160:\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    ".L0041E164:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "lw $4, 0x8($3)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $3, 0x4($4)\n"
    "and $2, $3, $2\n"
    "sltu $4, $2, $17\n"
    ".word 0x50800006 /* beql $4, $0, .L0041E198: raw word */\n"
    "subu $2, $2, $17\n"
    "subu $2, $17, $2\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    ".word 0x10000003 /* b .L0041E1A0: raw word */\n"
    "dsubu $7, $0, $2\n"
    ".L0041E198:\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    ".L0041E1A0:\n"
    "addiu $18, $20, %lo(D_00454CE8)\n"
    "lui $16, (0xFFFFFFFC >> 16)\n"
    "lw $3, 0x8($18)\n"
    "ori $16, $16, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($3)\n"
    "and $2, $2, $16\n"
    "sltu $2, $2, $17\n"
    ".word 0x14400004 /* bnez $2, .L0041E1D0: raw word */\n"
    "daddu $4, $19, $0\n"
    "slti $2, $7, 0x10\n"
    ".word 0x10400046 /* beqz $2, .L0041E2E4: raw word */\n"
    "addiu $6, $20, %lo(D_00454CE8)\n"
    ".L0041E1D0:\n"
    "jal func_0041D990\n"
    "daddu $5, $17, $0\n"
    "lw $2, 0x8($18)\n"
    "lw $3, 0x4($2)\n"
    "and $3, $3, $16\n"
    "sltu $2, $3, $17\n"
    ".word 0x10400005 /* beqz $2, .L0041E200: raw word */\n"
    "subu $2, $17, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    ".word 0x10000004 /* b .L0041E20C: raw word */\n"
    "dsubu $7, $0, $2\n"
    ".L0041E200:\n"
    "subu $2, $3, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    ".L0041E20C:\n"
    "addiu $2, $20, %lo(D_00454CE8)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "lw $4, 0x8($2)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($4)\n"
    "and $2, $2, $3\n"
    "sltu $2, $2, $17\n"
    ".word 0x14400003 /* bnez $2, .L0041E238: raw word */\n"
    "slti $2, $7, 0x10\n"
    ".word 0x1040002C /* beqz $2, .L0041E2E4: raw word */\n"
    "addiu $6, $20, %lo(D_00454CE8)\n"
    ".L0041E238:\n"
    "jal func_00418D08\n"
    "daddu $4, $19, $0\n"
    ".word 0x10000036 /* b .L0041E31C: raw word */\n"
    "daddu $2, $0, $0\n"
    ".L0041E248:\n"
    "addu $3, $16, $5\n"
    "lw $6, 0x8($16)\n"
    "daddu $4, $19, $0\n"
    "sw $8, 0xC($6)\n"
    "sw $6, 0x8($8)\n"
    "lw $2, 0x4($3)\n"
    ".word 0x1000002A /* b .L0041E30C: raw word */\n"
    "ori $2, $2, 0x1\n"
    ".L0041E268:\n"
    "ori $4, $17, 0x1\n"
    "lw $6, 0x8($16)\n"
    "addiu $2, $0, 0x1\n"
    "sw $4, 0x4($16)\n"
    "addiu $3, $14, %lo(D_00454CF0)\n"
    "sw $8, 0xC($6)\n"
    "or $2, $7, $2\n"
    "sw $6, 0x8($8)\n"
    "dsll32 $5, $7, 0\n"
    "dsra32 $5, $5, 0\n"
    "addu $8, $16, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "sw $8, 0xC($3)\n"
    "addu $6, $8, $5\n"
    "sw $8, 0x8($3)\n"
    "daddu $4, $19, $0\n"
    "sw $2, 0x4($8)\n"
    "sw $3, 0x8($8)\n"
    "sw $3, 0xC($8)\n"
    ".word 0x10000015 /* b .L0041E310: raw word */\n"
    "sw $5, 0x0($6)\n"
    ".L0041E2C0:\n"
    "daddu $4, $19, $0\n"
    "lw $2, 0x4($3)\n"
    "ori $2, $2, 0x1\n"
    "sw $2, 0x4($3)\n"
    "lw $8, 0xC($16)\n"
    "lw $6, 0x8($16)\n"
    "sw $8, 0xC($6)\n"
    ".word 0x1000000C /* b .L0041E310: raw word */\n"
    "sw $6, 0x8($8)\n"
    ".L0041E2E4:\n"
    "ori $5, $17, 0x1\n"
    "lw $16, 0x8($6)\n"
    "addiu $2, $0, 0x1\n"
    "or $2, $7, $2\n"
    "daddu $4, $19, $0\n"
    "sw $5, 0x4($16)\n"
    "addu $3, $16, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "sw $3, 0x8($6)\n"
    ".L0041E30C:\n"
    "sw $2, 0x4($3)\n"
    ".L0041E310:\n"
    "jal func_00418D08\n"
    "nop\n"
    "addiu $2, $16, 0x8\n"
    ".L0041E31C:\n"
    "lq $16, 0x50($29)\n"
    "lq $17, 0x40($29)\n"
    "lq $18, 0x30($29)\n"
    "lq $19, 0x20($29)\n"
    "lq $20, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x60\n"
    ".end func_0041DBF8\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E340);
#ifdef SKIP_ASM
extern void func_00418CA8_lock(int) __asm__("func_00418CA8");
extern void func_00418D08_unlock(int) __asm__("func_00418D08");
extern int func_0041E638_trim(int, unsigned) __asm__("func_0041E638");
void func_0041E340_(int ptr, void *mem) __asm__("func_0041E340");
void func_0041E340_(int ptr, void *mem) {
    mchunkptr p;
    unsigned hd, sz;
    int idx;
    mchunkptr next;
    unsigned nextsz, prevsz;
    mchunkptr bck, fwd;
    int islr;
    mchunkptr lr;
    if (mem == 0)
        return;
    func_00418CA8_lock(ptr);
    p = (mchunkptr)((char *)mem - 8);
    hd = p->size;
    sz = hd & ~1u;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);
    if (next == top) {
        sz += nextsz;
        if (!(hd & 1)) {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -(int)prevsz);
            sz += prevsz;
            unlink(p, bck, fwd);
        }
        set_head(p, sz | 1);
        top = p;
        if ((unsigned long)sz >= D_004550F0)
            func_0041E638_trim(ptr, D_004550F8);
        func_00418D08_unlock(ptr);
        return;
    }
    set_head(next, nextsz);
    islr = 0;
    if (!(hd & 1)) {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -(int)prevsz);
        sz += prevsz;
        if (p->fd == last_remainder)
            islr = 1;
        else
            unlink(p, bck, fwd);
    }
    if (!inuse_bit_at_offset(next, nextsz)) {
        sz += nextsz;
        if (!islr && next->fd == (lr = lr2)) {
            islr = 1;
            link_last_remainder(p);
        } else
            unlink(next, bck, fwd);
    }
    set_head(p, sz | 1);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);
    func_00418D08_unlock(ptr);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E638);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041E638\n.ent func_0041E638\nfunc_0041E638:\n"
    "addiu $29, $29, -0x60\n"
    "sq $18, 0x30($29)\n"
    "sq $16, 0x50($29)\n"
    "daddu $18, $4, $0\n"
    "sq $17, 0x40($29)\n"
    "sq $20, 0x10($29)\n"
    "sq $19, 0x20($29)\n"
    "sd $31, 0x0($29)\n"
    "jal func_00418CA8\n"
    "daddu $16, $5, $0\n"
    "lui $2, %hi(D_00454CE8)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "addiu $20, $2, %lo(D_00454CE8)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $4, 0x8($20)\n"
    "dsll32 $16, $16, 0\n"
    "dsrl32 $16, $16, 0\n"
    "addiu $5, $0, 0x1000\n"
    "lw $2, 0x4($4)\n"
    "and $2, $2, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $17, $2, 0\n"
    "dsubu $16, $17, $16\n"
    "jal func_00411538\n"
    "daddiu $4, $16, 0xFEF\n"
    "daddiu $4, $2, -0x1\n"
    "jal func_004114D0\n"
    "addiu $5, $0, 0x1000\n"
    "daddu $16, $2, $0\n"
    "slti $2, $16, 0x1000\n"
    ".word 0x14400023 /* bnez $2, .L0041E740: raw word */\n"
    "daddu $4, $18, $0\n"
    "jal func_0041FD70\n"
    "daddu $5, $0, $0\n"
    "lw $3, 0x8($20)\n"
    "dsll32 $4, $17, 0\n"
    "dsra32 $4, $4, 0\n"
    "addu $3, $3, $4\n"
    ".word 0x1443001B /* bne $2, $3, .L0041E740: raw word */\n"
    "daddu $4, $18, $0\n"
    "dsll32 $19, $16, 0\n"
    "dsra32 $19, $19, 0\n"
    "jal func_0041FD70\n"
    "negu $5, $19\n"
    "lui $3, (0xFFFFFFFF >> 16)\n"
    "ori $3, $3, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x14430017 /* bne $2, $3, .L0041E750: raw word */\n"
    "addiu $3, $0, 0x1\n"
    "daddu $5, $0, $0\n"
    "jal func_0041FD70\n"
    "daddu $4, $18, $0\n"
    "lw $6, 0x8($20)\n"
    "daddu $5, $2, $0\n"
    "subu $17, $5, $6\n"
    "slti $2, $17, 0x10\n"
    ".word 0x1440000A /* bnez $2, .L0041E740: raw word */\n"
    "lui $4, %hi(D_00455100)\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, %lo(D_00455100)($4)\n"
    "or $2, $17, $2\n"
    "lui $4, %hi(D_00455118)\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "subu $3, $5, $3\n"
    "sw $3, %lo(D_00455118)($4)\n"
    "sw $2, 0x4($6)\n"
    ".L0041E740:\n"
    "jal func_00418D08\n"
    "daddu $4, $18, $0\n"
    ".word 0x1000000E /* b .L0041E784: raw word */\n"
    "daddu $2, $0, $0\n"
    ".L0041E750:\n"
    "dsubu $2, $17, $16\n"
    "lw $4, 0x8($20)\n"
    "or $2, $2, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsra32 $2, $2, 0\n"
    "lui $3, %hi(D_00455118)\n"
    "sw $2, 0x4($4)\n"
    "daddu $4, $18, $0\n"
    "lw $2, %lo(D_00455118)($3)\n"
    "subu $2, $2, $19\n"
    "jal func_00418D08\n"
    "sw $2, %lo(D_00455118)($3)\n"
    "addiu $2, $0, 0x1\n"
    ".L0041E784:\n"
    "lq $16, 0x50($29)\n"
    "lq $17, 0x40($29)\n"
    "lq $18, 0x30($29)\n"
    "lq $19, 0x20($29)\n"
    "lq $20, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x60\n"
    ".end func_0041E638\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E7A8);
#ifdef SKIP_ASM
long func_0041E7A8_(int *ptr, char *nptr, char **endptr, int base) __asm__("func_0041E7A8");
long func_0041E7A8_(int *ptr, char *nptr, char **endptr, int base) {
    char *s = nptr;
    unsigned long acc, cutoff;
    int c, neg = 0, any, cutlim;
    do {
        c = *s++;
    } while (XCT(c) & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = neg ? -(unsigned long)0x8000000000000000L : 0x7FFFFFFFFFFFFFFFL;
    cutlim = func_0042DAD8_mod(cutoff, base);
    cutoff = func_00411538_div(cutoff, base);
    for (acc = 0, any = 0;; c = *s++) {
        if (XCT(c) & 4)
            c -= '0';
        else if (XCT(c) & 3)
            c -= (XCT(c) & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc = func_004114D0_mul(acc, base);
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? 0x8000000000000000L : 0x7FFFFFFFFFFFFFFFL;
        *ptr = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = any ? s - 1 : nptr;
    return acc;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041E9E0);
#ifdef SKIP_ASM
extern int D_00454944;
extern long func_0041E7A8(int, int, int, int);
long func_0041E9E0(int s, int end, int base) {
    return func_0041E7A8(D_00454944, s, end, base);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EA18);
#ifdef SKIP_ASM
extern char D_00499C81[];
int func_0041EA18(int a) {
    return (D_00499C81[a] & 1) ? a + 0x20 : a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EA38);
#ifdef SKIP_ASM
extern char D_0049A7D0b[] __asm__("D_0049A7D0");
extern char D_0049A7C0[], D_0049A7D0[], D_0049A7D8[], D_0049A7E0[], D_0049A7E8[];
extern char D_00455140[], D_00455148[], D_00455150[];
extern int func_004165A8_cmp(char *, char *) __asm__("func_004165A8");
extern char *strcpy_(char *, char *) __asm__("strcpy");
extern unsigned strlen_(char *) __asm__("strlen");
char *func_0041EA38_(int *p, int category, char *locale) __asm__("func_0041EA38");
char *func_0041EA38_(int *p, int category, char *locale) {
    if (locale) {
        if (category != 2) {
            if (func_004165A8_cmp(locale, D_0049A7D0) && func_004165A8_cmp(locale, D_0049A7C0))
                return 0;
            if (category == 0) {
                strcpy_(D_00455150, D_00455148);
                strcpy_(D_00455148, locale);
                *(int *)D_00455140 = 1;
            }
        } else {
            if (func_004165A8_cmp(locale, D_0049A7D0) && func_004165A8_cmp(locale, D_0049A7C0) && func_004165A8_cmp(locale, D_0049A7D0) &&
                func_004165A8_cmp(locale, D_0049A7D8) && func_004165A8_cmp(locale, D_0049A7E0) &&
                func_004165A8_cmp(locale, D_0049A7E8))
                return 0;
            strcpy_(D_00455150, D_00455148);
            strcpy_(D_00455148, locale);
            if (func_004165A8_cmp(locale, D_0049A7D8) == 0)
                *(int *)D_00455140 = 8;
            else if (strlen_(locale) >= 2)
                *(int *)D_00455140 = 2;
            else
                *(int *)D_00455140 = 1;
        }
        p[0xD] = (int)locale;
        p[0xC] = category;
        return category == 2 ? D_00455150 : D_0049A7D0b;
    }
    return category == 2 ? D_00455148 : D_0049A7D0b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC08);
#ifdef SKIP_ASM
extern char D_0049A790[];
char *func_0041EC08(void) {
    return D_0049A790;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC18);
#ifdef SKIP_ASM
extern int D_00454944;
extern void func_0041EA38(int, int, int);
void func_0041EC18(int a, int b) {
    func_0041EA38(D_00454944, a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC48);
#ifdef SKIP_ASM
extern int D_00454944;
void func_0041EC48(void) {
    ((char *(*)(int))func_0041EC08)(D_00454944);
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EC70);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041EC70\n.ent func_0041EC70\nfunc_0041EC70:\n"
    "sltiu $2, $6, 0x10\n"
    ".word 0x14400028 /* bnez $2, .L0041ED18: raw word */\n"
    "andi $5, $5, 0xFF\n"
    "andi $2, $4, 0xF\n"
    ".word 0x14400025 /* bnez $2, .L0041ED18: raw word */\n"
    "daddu $7, $4, $0\n"
    "dsll $3, $5, 8\n"
    "ori $2, $0, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 9\n"
    "ori $2, $2, 0x101\n"
    "daddu $10, $3, $5\n"
    "ori $3, $0, 0x8080\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0x8080\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0x8080\n"
    "dsll $3, $3, 16\n"
    "ori $3, $3, 0x8080\n"
    "pcpyh $8, $10\n"
    "pcpyld $9, $8, $8\n"
    "daddu $4, $2, $0\n"
    "pcpyld $8, $3, $3\n"
    ".L0041ECD8:\n"
    "lq $2, 0x0($7)\n"
    "pxor $2, $2, $9\n"
    "pcpyld $10, $4, $4\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $10\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $3, $2, $9\n"
    "or $2, $2, $3\n"
    ".word 0x54400006 /* bnel $2, $0, .L0041ED18: raw word */\n"
    "daddu $4, $7, $0\n"
    "addiu $6, $6, -0x10\n"
    "sltiu $2, $6, 0x10\n"
    ".word 0x1040FFF2 /* beqz $2, .L0041ECD8: raw word */\n"
    "addiu $7, $7, 0x10\n"
    "daddu $4, $7, $0\n"
    ".L0041ED18:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "addiu $6, $6, -0x1\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    ".word 0x10C2000A /* beq $6, $2, .L0041ED50: raw word */\n"
    "nop\n"
    "lui $3, (0xFFFFFFFF >> 16)\n"
    "ori $3, $3, (0xFFFFFFFF & 0xFFFF)\n"
    ".L0041ED34:\n"
    "lbu $2, 0x0($4)\n"
    ".word 0x10450007 /* beq $2, $5, .L0041ED58: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "nop\n"
    "nop\n"
    ".word 0x14C3FFFA /* bne $6, $3, .L0041ED34: raw word */\n"
    "addiu $4, $4, 0x1\n"
    ".L0041ED50:\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".L0041ED58:\n"
    "jr $31\n"
    "daddu $2, $4, $0\n"
    ".end func_0041EC70\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041ED60);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041ED60\n.ent func_0041ED60\nfunc_0041ED60:\n"
    "addiu $29, $29, -0x60\n"
    "daddu $5, $4, $0\n"
    "sq $16, 0x50($29)\n"
    "sq $17, 0x40($29)\n"
    "sq $18, 0x30($29)\n"
    "sq $19, 0x20($29)\n"
    "sq $20, 0x10($29)\n"
    "daddu $2, $5, $0\n"
    "dsll32 $18, $2, 0\n"
    "dsra32 $18, $18, 0\n"
    "dsra32 $16, $2, 0\n"
    "sra $3, $16, 20\n"
    "andi $3, $3, 0x7FF\n"
    "addiu $17, $3, -0x3FF\n"
    "slti $2, $17, 0x14\n"
    ".word 0x1040002F /* beqz $2, .L0041EE5C: raw word */\n"
    "sd $31, 0x0($29)\n"
    ".word 0x06210016 /* bgez $17, .L0041EE00: raw word */\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "lui $2, %hi(D_0049A7F8)\n"
    "jal func_00411F18\n"
    "ld $5, %lo(D_0049A7F8)($2)\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x1840004D /* blez $2, .L0041EEFC: raw word */\n"
    "nop\n"
    ".word 0x06000004 /* bltz $16, .L0041EDE0: raw word */\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "daddu $18, $0, $0\n"
    ".word 0x10000048 /* b .L0041EEFC: raw word */\n"
    "daddu $16, $0, $0\n"
    ".L0041EDE0:\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $2, $16, $2\n"
    "or $2, $2, $18\n"
    ".word 0x10400043 /* beqz $2, .L0041EEFC: raw word */\n"
    "nop\n"
    "lui $16, (0xBFF00000 >> 16)\n"
    ".word 0x10000040 /* b .L0041EEFC: raw word */\n"
    "daddu $18, $0, $0\n"
    ".L0041EE00:\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "srav $20, $2, $17\n"
    "and $3, $16, $20\n"
    "or $3, $3, $18\n"
    ".word 0x10600045 /* beqz $3, .L0041EF28: raw word */\n"
    "daddu $4, $5, $0\n"
    "lui $2, %hi(D_0049A7F8)\n"
    "jal func_00411F18\n"
    "ld $5, %lo(D_0049A7F8)($2)\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x18400032 /* blez $2, .L0041EEFC: raw word */\n"
    "nop\n"
    ".word 0x06010005 /* bgez $16, .L0041EE50: raw word */\n"
    "nor $2, $0, $20\n"
    "lui $2, (0x100000 >> 16)\n"
    "srav $2, $2, $17\n"
    "addu $16, $16, $2\n"
    "nor $2, $0, $20\n"
    ".L0041EE50:\n"
    "daddu $18, $0, $0\n"
    ".word 0x10000029 /* b .L0041EEFC: raw word */\n"
    "and $16, $16, $2\n"
    ".L0041EE5C:\n"
    "slti $2, $17, 0x34\n"
    ".word 0x14400008 /* bnez $2, .L0041EE84: raw word */\n"
    "addiu $4, $3, -0x413\n"
    "addiu $2, $0, 0x400\n"
    ".word 0x1622002F /* bne $17, $2, .L0041EF2C: raw word */\n"
    "daddu $2, $5, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $5, $0\n"
    ".word 0x1000002C /* b .L0041EF30: raw word */\n"
    "lq $16, 0x50($29)\n"
    ".L0041EE84:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    "srlv $20, $2, $4\n"
    "and $3, $18, $20\n"
    ".word 0x10600024 /* beqz $3, .L0041EF28: raw word */\n"
    "daddu $4, $5, $0\n"
    "lui $2, %hi(D_0049A7F8)\n"
    "jal func_00411F18\n"
    "ld $5, %lo(D_0049A7F8)($2)\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x18400011 /* blez $2, .L0041EEFC: raw word */\n"
    "nop\n"
    ".word 0x0601000E /* bgez $16, .L0041EEF8: raw word */\n"
    "nor $2, $0, $20\n"
    "addiu $2, $0, 0x14\n"
    ".word 0x16220003 /* bne $17, $2, .L0041EED8: raw word */\n"
    "addiu $2, $0, 0x34\n"
    ".word 0x10000008 /* b .L0041EEF4: raw word */\n"
    "addiu $16, $16, 0x1\n"
    ".L0041EED8:\n"
    "addiu $3, $0, 0x1\n"
    "subu $2, $2, $17\n"
    "sllv $3, $3, $2\n"
    "addu $3, $18, $3\n"
    "sltu $2, $3, $18\n"
    "addu $16, $16, $2\n"
    "daddu $18, $3, $0\n"
    ".L0041EEF4:\n"
    "nor $2, $0, $20\n"
    ".L0041EEF8:\n"
    "and $18, $18, $2\n"
    ".L0041EEFC:\n"
    "addiu $3, $0, -0x1\n"
    "dsrl32 $3, $3, 0\n"
    "dsll32 $4, $16, 0\n"
    "and $19, $19, $3\n"
    "dsll32 $2, $18, 0\n"
    "or $19, $19, $4\n"
    "addiu $3, $0, -0x1\n"
    "dsll32 $3, $3, 0\n"
    "dsrl32 $2, $2, 0\n"
    "and $19, $19, $3\n"
    "or $5, $19, $2\n"
    ".L0041EF28:\n"
    "daddu $2, $5, $0\n"
    ".L0041EF2C:\n"
    "lq $16, 0x50($29)\n"
    ".L0041EF30:\n"
    "lq $17, 0x40($29)\n"
    "lq $18, 0x30($29)\n"
    "lq $19, 0x20($29)\n"
    "lq $20, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x60\n"
    ".end func_0041ED60\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041EF50);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041EF50\n.ent func_0041EF50\nfunc_0041EF50:\n"
    "addiu $29, $29, -0x40\n"
    "sq $17, 0x20($29)\n"
    "sq $18, 0x10($29)\n"
    "daddu $17, $4, $0\n"
    "daddu $18, $5, $0\n"
    "sq $16, 0x30($29)\n"
    "sd $31, 0x0($29)\n"
    "daddu $2, $17, $0\n"
    "dsll32 $8, $2, 0\n"
    "dsra32 $8, $8, 0\n"
    "dsra32 $7, $2, 0\n"
    "daddu $14, $8, $0\n"
    "daddu $2, $18, $0\n"
    "dsll32 $10, $2, 0\n"
    "dsra32 $10, $10, 0\n"
    "dsra32 $9, $2, 0\n"
    "daddu $15, $10, $0\n"
    "lui $3, (0x80000000 >> 16)\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "and $13, $7, $3\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $9, $9, $2\n"
    "or $3, $9, $10\n"
    ".word 0x1060000E /* beqz $3, .L0041EFE8: raw word */\n"
    "xor $7, $7, $13\n"
    "lui $2, (0x7FEFFFFF >> 16)\n"
    "ori $2, $2, (0x7FEFFFFF & 0xFFFF)\n"
    "slt $2, $2, $7\n"
    ".word 0x1440000A /* bnez $2, .L0041EFEC: raw word */\n"
    "daddu $4, $17, $0\n"
    "negu $2, $10\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "or $2, $10, $2\n"
    "srl $2, $2, 31\n"
    "or $2, $9, $2\n"
    "sltu $3, $3, $2\n"
    ".word 0x1060000D /* beqz $3, .L0041F018: raw word */\n"
    "slt $2, $9, $7\n"
    ".L0041EFE8:\n"
    "daddu $4, $17, $0\n"
    ".L0041EFEC:\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "daddu $16, $2, $0\n"
    "daddu $4, $17, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00412280\n"
    "daddu $5, $2, $0\n"
    ".word 0x100000DF /* b .L0041F390: raw word */\n"
    "lq $16, 0x30($29)\n"
    ".L0041F018:\n"
    ".word 0x1440000A /* bnez $2, .L0041F044: raw word */\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "slt $2, $7, $9\n"
    ".word 0x144000D9 /* bnez $2, .L0041F38C: raw word */\n"
    "daddu $2, $17, $0\n"
    "sltu $2, $8, $10\n"
    ".word 0x544000D6 /* bnel $2, $0, .L0041F38C: raw word */\n"
    "daddu $2, $17, $0\n"
    ".word 0x110A00BE /* beq $8, $10, .L0041F334: raw word */\n"
    "srl $3, $13, 31\n"
    "lui $2, (0xFFFFF >> 16)\n"
    ".L0041F044:\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $7\n"
    ".word 0x5440001B /* bnel $2, $0, .L0041F0BC: raw word */\n"
    "sra $2, $7, 20\n"
    ".word 0x14E0000D /* bnez $7, .L0041F08C: raw word */\n"
    "sll $2, $7, 11\n"
    "addiu $5, $0, -0x413\n"
    ".word 0x19C00017 /* blez $14, .L0041F0C0: raw word */\n"
    "daddu $2, $14, $0\n"
    ".L0041F068:\n"
    "sll $2, $2, 1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1C40FFFA /* bgtz $2, .L0041F068: raw word */\n"
    "addiu $5, $5, -0x1\n"
    ".word 0x1000000F /* b .L0041F0C4: raw word */\n"
    "lui $2, (0xFFFFF >> 16)\n"
    ".L0041F08C:\n"
    ".word 0x1840000C /* blez $2, .L0041F0C0: raw word */\n"
    "addiu $5, $0, -0x3FE\n"
    "nop\n"
    ".L0041F098:\n"
    "sll $2, $2, 1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1C40FFFA /* bgtz $2, .L0041F098: raw word */\n"
    "addiu $5, $5, -0x1\n"
    ".word 0x10000003 /* b .L0041F0C4: raw word */\n"
    "lui $2, (0xFFFFF >> 16)\n"
    ".L0041F0BC:\n"
    "addiu $5, $2, -0x3FF\n"
    ".L0041F0C0:\n"
    "lui $2, (0xFFFFF >> 16)\n"
    ".L0041F0C4:\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $9\n"
    ".word 0x1440001D /* bnez $2, .L0041F144: raw word */\n"
    "sra $2, $9, 20\n"
    ".word 0x1520000F /* bnez $9, .L0041F114: raw word */\n"
    "addiu $4, $0, -0x3FE\n"
    "addiu $4, $0, -0x413\n"
    "daddu $2, $15, $0\n"
    ".word 0x19E00019 /* blez $15, .L0041F14C: raw word */\n"
    "slti $3, $5, -0x3FE\n"
    "nop\n"
    ".L0041F0F0:\n"
    "sll $2, $2, 1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1C40FFFA /* bgtz $2, .L0041F0F0: raw word */\n"
    "addiu $4, $4, -0x1\n"
    ".word 0x1000000F /* b .L0041F14C: raw word */\n"
    "nop\n"
    ".L0041F114:\n"
    "sll $2, $9, 11\n"
    ".word 0x1840000C /* blez $2, .L0041F14C: raw word */\n"
    "slti $3, $5, -0x3FE\n"
    ".L0041F120:\n"
    "sll $2, $2, 1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1C40FFFA /* bgtz $2, .L0041F120: raw word */\n"
    "addiu $4, $4, -0x1\n"
    ".word 0x10000003 /* b .L0041F14C: raw word */\n"
    "nop\n"
    ".L0041F144:\n"
    "slti $3, $5, -0x3FE\n"
    "addiu $4, $2, -0x3FF\n"
    ".L0041F14C:\n"
    ".word 0x14600007 /* bnez $3, .L0041F16C: raw word */\n"
    "addiu $2, $0, -0x3FE\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "lui $3, (0x100000 >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "and $2, $7, $2\n"
    ".word 0x1000000C /* b .L0041F198: raw word */\n"
    "or $7, $2, $3\n"
    ".L0041F16C:\n"
    "subu $6, $2, $5\n"
    "slti $3, $6, 0x20\n"
    ".word 0x10600006 /* beqz $3, .L0041F190: raw word */\n"
    "negu $2, $6\n"
    "sllv $3, $7, $6\n"
    "srlv $2, $14, $2\n"
    "sllv $8, $14, $6\n"
    ".word 0x10000003 /* b .L0041F198: raw word */\n"
    "or $7, $3, $2\n"
    ".L0041F190:\n"
    "sllv $7, $14, $6\n"
    "daddu $8, $0, $0\n"
    ".L0041F198:\n"
    "slti $2, $4, -0x3FE\n"
    ".word 0x14400007 /* bnez $2, .L0041F1BC: raw word */\n"
    "addiu $2, $0, -0x3FE\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "lui $3, (0x100000 >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "and $2, $9, $2\n"
    ".word 0x1000000C /* b .L0041F1E8: raw word */\n"
    "or $9, $2, $3\n"
    ".L0041F1BC:\n"
    "subu $6, $2, $4\n"
    "slti $3, $6, 0x20\n"
    ".word 0x10600006 /* beqz $3, .L0041F1E0: raw word */\n"
    "negu $2, $6\n"
    "sllv $3, $9, $6\n"
    "srlv $2, $15, $2\n"
    "sllv $10, $15, $6\n"
    ".word 0x10000003 /* b .L0041F1E8: raw word */\n"
    "or $9, $3, $2\n"
    ".L0041F1E0:\n"
    "sllv $9, $15, $6\n"
    "daddu $10, $0, $0\n"
    ".L0041F1E8:\n"
    ".word 0x10000011 /* b .L0041F230: raw word */\n"
    "subu $6, $5, $4\n"
    ".L0041F1F0:\n"
    "subu $3, $7, $9\n"
    "sltu $2, $8, $10\n"
    "subu $3, $3, $2\n"
    ".word 0x04610006 /* bgez $3, .L0041F218: raw word */\n"
    "subu $5, $8, $10\n"
    "srl $2, $8, 31\n"
    "sll $3, $7, 1\n"
    "addu $7, $3, $2\n"
    ".word 0x10000007 /* b .L0041F230: raw word */\n"
    "sll $8, $8, 1\n"
    ".L0041F218:\n"
    "or $2, $3, $5\n"
    ".word 0x10400044 /* beqz $2, .L0041F330: raw word */\n"
    "sll $3, $3, 1\n"
    "srl $2, $5, 31\n"
    "addu $7, $3, $2\n"
    "sll $8, $5, 1\n"
    ".L0041F230:\n"
    "daddu $2, $6, $0\n"
    ".word 0x1440FFEE /* bnez $2, .L0041F1F0: raw word */\n"
    "addiu $6, $6, -0x1\n"
    "subu $3, $7, $9\n"
    "sltu $2, $8, $10\n"
    "subu $3, $3, $2\n"
    ".word 0x04600003 /* bltz $3, .L0041F258: raw word */\n"
    "subu $5, $8, $10\n"
    "daddu $7, $3, $0\n"
    "daddu $8, $5, $0\n"
    ".L0041F258:\n"
    "or $2, $7, $8\n"
    ".word 0x10400035 /* beqz $2, .L0041F334: raw word */\n"
    "srl $3, $13, 31\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $7\n"
    ".word 0x1440000B /* bnez $2, .L0041F2A0: raw word */\n"
    "slti $2, $4, -0x3FE\n"
    "lui $5, (0xFFFFF >> 16)\n"
    "ori $5, $5, (0xFFFFF & 0xFFFF)\n"
    ".L0041F280:\n"
    "sll $2, $7, 1\n"
    "srl $3, $8, 31\n"
    "addu $7, $2, $3\n"
    "sll $8, $8, 1\n"
    "slt $2, $5, $7\n"
    ".word 0x1040FFFA /* beqz $2, .L0041F280: raw word */\n"
    "addiu $4, $4, -0x1\n"
    "slti $2, $4, -0x3FE\n"
    ".L0041F2A0:\n"
    ".word 0x14400013 /* bnez $2, .L0041F2F0: raw word */\n"
    "addiu $2, $0, -0x3FE\n"
    "addiu $4, $4, 0x3FF\n"
    "lui $3, (0xFFF00000 >> 16)\n"
    "addu $3, $7, $3\n"
    "sll $4, $4, 20\n"
    "or $7, $3, $4\n"
    "or $2, $7, $13\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "dsll32 $2, $2, 0\n"
    "and $11, $11, $4\n"
    "dsll32 $3, $8, 0\n"
    "or $11, $11, $2\n"
    "addiu $4, $0, -0x1\n"
    "dsll32 $4, $4, 0\n"
    "dsrl32 $3, $3, 0\n"
    "and $11, $11, $4\n"
    ".word 0x10000027 /* b .L0041F388: raw word */\n"
    "or $17, $11, $3\n"
    ".L0041F2F0:\n"
    "subu $6, $2, $4\n"
    "slti $3, $6, 0x15\n"
    ".word 0x10600006 /* beqz $3, .L0041F314: raw word */\n"
    "negu $2, $6\n"
    "srlv $3, $8, $6\n"
    "sllv $2, $7, $2\n"
    "or $8, $3, $2\n"
    ".word 0x10000011 /* b .L0041F354: raw word */\n"
    "srav $7, $7, $6\n"
    ".L0041F314:\n"
    "slti $2, $6, 0x20\n"
    ".word 0x1040000C /* beqz $2, .L0041F34C: raw word */\n"
    "negu $2, $6\n"
    "srlv $3, $8, $6\n"
    "sllv $2, $7, $2\n"
    ".word 0x10000009 /* b .L0041F350: raw word */\n"
    "or $8, $2, $3\n"
    ".L0041F330:\n"
    "srl $3, $13, 31\n"
    ".L0041F334:\n"
    "lui $2, %hi(D_0049A808)\n"
    "addiu $2, $2, %lo(D_0049A808)\n"
    "sll $3, $3, 3\n"
    "addu $3, $3, $2\n"
    ".word 0x10000011 /* b .L0041F38C: raw word */\n"
    "ld $2, 0x0($3)\n"
    ".L0041F34C:\n"
    "srav $8, $7, $6\n"
    ".L0041F350:\n"
    "daddu $7, $13, $0\n"
    ".L0041F354:\n"
    "addiu $3, $0, -0x1\n"
    "dsrl32 $3, $3, 0\n"
    "or $2, $7, $13\n"
    "dsll32 $2, $2, 0\n"
    "and $12, $12, $3\n"
    "or $12, $12, $2\n"
    "dsll32 $3, $8, 0\n"
    "addiu $2, $0, -0x1\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $3, $3, 0\n"
    "and $12, $12, $2\n"
    "or $17, $12, $3\n"
    "nop\n"
    ".L0041F388:\n"
    "daddu $2, $17, $0\n"
    ".L0041F38C:\n"
    "lq $16, 0x30($29)\n"
    ".L0041F390:\n"
    "lq $17, 0x20($29)\n"
    "lq $18, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x40\n"
    ".end func_0041EF50\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041F3A8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041F3A8\n.ent func_0041F3A8\nfunc_0041F3A8:\n"
    "addiu $29, $29, -0xA0\n"
    "daddu $6, $4, $0\n"
    "sq $16, 0x90($29)\n"
    "sq $17, 0x80($29)\n"
    "sq $18, 0x70($29)\n"
    "sq $19, 0x60($29)\n"
    "sq $20, 0x50($29)\n"
    "sq $21, 0x40($29)\n"
    "sq $22, 0x30($29)\n"
    "sq $23, 0x20($29)\n"
    "sq $30, 0x10($29)\n"
    "sd $31, 0x0($29)\n"
    "daddu $2, $6, $0\n"
    "dsra32 $19, $2, 0\n"
    "dsll32 $3, $2, 0\n"
    "dsra32 $3, $3, 0\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $19\n"
    ".word 0x1440001A /* bnez $2, .L0041F460: raw word */\n"
    "daddu $30, $0, $0\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $2, $19, $2\n"
    "or $2, $2, $3\n"
    ".word 0x14400004 /* bnez $2, .L0041F420: raw word */\n"
    "lui $3, %hi(D_0049A870)\n"
    ".word 0x10000163 /* b .L0041F9A4: raw word */\n"
    "ld $2, %lo(D_0049A870)($3)\n"
    "nop\n"
    ".L0041F420:\n"
    ".word 0x06610008 /* bgez $19, .L0041F444: raw word */\n"
    "daddu $4, $6, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412280\n"
    "daddu $5, $0, $0\n"
    ".word 0x1000015A /* b .L0041F9A8: raw word */\n"
    "lq $16, 0x90($29)\n"
    ".L0041F444:\n"
    "ori $5, $0, 0x86A0\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "addiu $30, $0, -0x36\n"
    "daddu $6, $2, $0\n"
    "dsra32 $19, $2, 0\n"
    "nop\n"
    ".L0041F460:\n"
    "lui $2, (0x7FEFFFFF >> 16)\n"
    "ori $2, $2, (0x7FEFFFFF & 0xFFFF)\n"
    "slt $2, $2, $19\n"
    ".word 0x10400006 /* beqz $2, .L0041F488: raw word */\n"
    "lui $16, (0xFFFFF >> 16)\n"
    "daddu $4, $6, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    ".word 0x10000149 /* b .L0041F9A8: raw word */\n"
    "lq $16, 0x90($29)\n"
    ".L0041F488:\n"
    "sra $4, $19, 20\n"
    "ori $16, $16, (0xFFFFF & 0xFFFF)\n"
    "lui $2, (0x95F64 >> 16)\n"
    "ori $2, $2, (0x95F64 & 0xFFFF)\n"
    "and $19, $19, $16\n"
    "addu $2, $19, $2\n"
    "addiu $3, $30, -0x3FF\n"
    "lui $5, (0x100000 >> 16)\n"
    "addu $30, $3, $4\n"
    "and $20, $2, $5\n"
    "daddu $4, $6, $0\n"
    "lui $2, (0x3FF00000 >> 16)\n"
    "addiu $3, $0, -0x1\n"
    "dsrl32 $3, $3, 0\n"
    "xor $2, $20, $2\n"
    "and $4, $4, $3\n"
    "or $2, $2, $19\n"
    "dsll32 $2, $2, 0\n"
    "or $6, $4, $2\n"
    "sra $3, $20, 20\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "addu $30, $30, $3\n"
    "jal func_00411F70\n"
    "daddu $4, $6, $0\n"
    "daddu $21, $2, $0\n"
    "addiu $2, $19, 0x2\n"
    "and $2, $2, $16\n"
    "slti $2, $2, 0x3\n"
    ".word 0x10400057 /* beqz $2, .L0041F65C: raw word */\n"
    "daddu $16, $0, $0\n"
    "daddu $4, $21, $0\n"
    "jal func_00412500\n"
    "daddu $5, $16, $0\n"
    ".word 0x1440001D /* bnez $2, .L0041F588: raw word */\n"
    "daddu $4, $21, $0\n"
    ".word 0x13C00122 /* beqz $30, .L0041F9A4: raw word */\n"
    "daddu $2, $16, $0\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $22, $2, $0\n"
    "ori $5, $0, 0xFF98\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xB90B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFB80\n"
    "dsll $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "ori $5, $0, 0xF7A8\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xE7BC\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xD5E4\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x3C76\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    ".word 0x10000109 /* b .L0041F9A8: raw word */\n"
    "lq $16, 0x90($29)\n"
    ".L0041F588:\n"
    "jal func_00411FD8\n"
    "daddu $5, $21, $0\n"
    "ori $5, $0, 0xFF55\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xAAAA\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xAAAA\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1555\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $21, $0\n"
    "ori $4, $0, 0xFF80\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    ".word 0x17C00004 /* bnez $30, .L0041F5E8: raw word */\n"
    "daddu $18, $2, $0\n"
    "daddu $4, $21, $0\n"
    ".word 0x100000EE /* b .L0041F99C: raw word */\n"
    "daddu $5, $18, $0\n"
    ".L0041F5E8:\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $22, $2, $0\n"
    "ori $5, $0, 0xFF98\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xB90B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFB80\n"
    "dsll $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "ori $5, $0, 0xF7A8\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xE7BC\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xD5E4\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x3C76\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    ".word 0x100000D0 /* b .L0041F998: raw word */\n"
    "daddu $4, $16, $0\n"
    ".L0041F65C:\n"
    "ori $5, $0, 0x8000\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411F18\n"
    "daddu $4, $21, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412280\n"
    "daddu $4, $21, $0\n"
    "daddu $23, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $4, $23, $0\n"
    "daddu $5, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $22, $2, $0\n"
    "lui $3, (0xFFF9EB86 >> 16)\n"
    "daddu $18, $2, $0\n"
    "ori $3, $3, (0xFFF9EB86 & 0xFFFF)\n"
    "daddu $4, $18, $0\n"
    "addu $20, $19, $3\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "lui $16, (0x6B851 >> 16)\n"
    "daddu $17, $2, $0\n"
    "ori $16, $16, (0x6B851 & 0xFFFF)\n"
    "ori $5, $0, 0xFF0E\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xD04E\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0x83C6\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x69F\n"
    "subu $16, $16, $19\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "or $20, $20, $16\n"
    "ori $5, $0, 0xFF31\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xC714\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xEC73\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x18AF\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "ori $5, $0, 0xFF66\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xCCCC\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xCCBF\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1A04\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "ori $5, $0, 0xFF0B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xC44B\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xF9F2\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1244\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "ori $5, $0, 0xFF1D\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0xCC92\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xD960\n"
    "dsll $5, $5, 11\n"
    "ori $5, $5, 0x3DE\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "ori $5, $0, 0xFF49\n"
    "dsll $5, $5, 18\n"
    "ori $5, $5, 0x9249\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0x8452\n"
    "dsll $5, $5, 11\n"
    "ori $5, $5, 0x359\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $17, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "ori $5, $0, 0xFF95\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xAAAA\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xAAAA\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1593\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $16, $0\n"
    ".word 0x1A800039 /* blez $20, .L0041F8F4: raw word */\n"
    "daddu $18, $2, $0\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $21, $0\n"
    ".word 0x17C0000C /* bnez $30, .L0041F864: raw word */\n"
    "daddu $19, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    ".word 0x1000004E /* b .L0041F998: raw word */\n"
    "daddu $4, $21, $0\n"
    ".L0041F864:\n"
    "ori $5, $0, 0xFF98\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xB90B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFB80\n"
    "dsll $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $17, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "ori $5, $0, 0xF7A8\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xE7BC\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xD5E4\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x3C76\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    ".word 0x1000002A /* b .L0041F998: raw word */\n"
    "daddu $4, $17, $0\n"
    ".L0041F8F4:\n"
    ".word 0x13C00022 /* beqz $30, .L0041F980: raw word */\n"
    "daddu $5, $18, $0\n"
    "ori $5, $0, 0xFF98\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xB90B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFB80\n"
    "dsll $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $17, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "ori $5, $0, 0xF7A8\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xE7BC\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xD5E4\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x3C76\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $22, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    ".word 0x10000007 /* b .L0041F998: raw word */\n"
    "daddu $4, $17, $0\n"
    ".L0041F980:\n"
    "jal func_00411F70\n"
    "daddu $4, $21, $0\n"
    "daddu $4, $23, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $4, $21, $0\n"
    ".L0041F998:\n"
    "daddu $5, $2, $0\n"
    ".L0041F99C:\n"
    "jal func_00411F70\n"
    "nop\n"
    ".L0041F9A4:\n"
    "lq $16, 0x90($29)\n"
    ".L0041F9A8:\n"
    "lq $17, 0x80($29)\n"
    "lq $18, 0x70($29)\n"
    "lq $19, 0x60($29)\n"
    "lq $20, 0x50($29)\n"
    "lq $21, 0x40($29)\n"
    "lq $22, 0x30($29)\n"
    "lq $23, 0x20($29)\n"
    "lq $30, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xA0\n"
    ".end func_0041F3A8\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041F9D8);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041F9D8\n.ent func_0041F9D8\nfunc_0041F9D8:\n"
    "addiu $29, $29, -0x40\n"
    "sq $17, 0x20($29)\n"
    "sq $16, 0x30($29)\n"
    "daddu $17, $4, $0\n"
    "sq $18, 0x10($29)\n"
    "sd $31, 0x0($29)\n"
    "daddu $2, $17, $0\n"
    "dsra32 $16, $2, 0\n"
    "dsll32 $3, $2, 0\n"
    "dsra32 $3, $3, 0\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "slt $2, $2, $16\n"
    ".word 0x1440001A /* bnez $2, .L0041FA78: raw word */\n"
    "daddu $18, $0, $0\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $2, $16, $2\n"
    "or $2, $2, $3\n"
    ".word 0x14400004 /* bnez $2, .L0041FA38: raw word */\n"
    "lui $3, %hi(D_0049A890)\n"
    ".word 0x10000054 /* b .L0041FB80: raw word */\n"
    "ld $2, %lo(D_0049A890)($3)\n"
    "nop\n"
    ".L0041FA38:\n"
    ".word 0x06010008 /* bgez $16, .L0041FA5C: raw word */\n"
    "daddu $4, $17, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412280\n"
    "daddu $5, $0, $0\n"
    ".word 0x1000004B /* b .L0041FB84: raw word */\n"
    "lq $16, 0x30($29)\n"
    ".L0041FA5C:\n"
    "ori $5, $0, 0x86A0\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "addiu $18, $0, -0x36\n"
    "daddu $17, $2, $0\n"
    "dsra32 $16, $2, 0\n"
    "nop\n"
    ".L0041FA78:\n"
    "lui $2, (0x7FEFFFFF >> 16)\n"
    "ori $2, $2, (0x7FEFFFFF & 0xFFFF)\n"
    "slt $2, $2, $16\n"
    ".word 0x5440003A /* bnel $2, $0, .L0041FB70: raw word */\n"
    "daddu $4, $17, $0\n"
    "sra $2, $16, 20\n"
    "addiu $4, $18, -0x3FF\n"
    "addu $18, $4, $2\n"
    "lui $3, (0xFFFFF >> 16)\n"
    "srl $4, $18, 31\n"
    "addiu $2, $0, 0x3FF\n"
    "subu $2, $2, $4\n"
    "ori $3, $3, (0xFFFFF & 0xFFFF)\n"
    "and $3, $16, $3\n"
    "sll $2, $2, 20\n"
    "or $16, $3, $2\n"
    "jal func_00412550\n"
    "addu $4, $18, $4\n"
    "daddu $3, $17, $0\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "and $3, $3, $4\n"
    "dsll32 $5, $16, 0\n"
    "or $17, $3, $5\n"
    "daddu $18, $2, $0\n"
    "jal func_0041F3A8\n"
    "daddu $4, $17, $0\n"
    "ori $5, $0, 0xF567\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFBCC\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0x8F89\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0xB36\n"
    "daddu $17, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "ori $5, $0, 0xFF6F\n"
    "dsll $5, $5, 18\n"
    "ori $5, $5, 0xB7B1\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xA4DC\n"
    "dsll $5, $5, 11\n"
    "ori $5, $5, 0x50E\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "ori $5, $0, 0xFF4D\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0x826A\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0x9F60\n"
    "dsll $5, $5, 8\n"
    "daddu $16, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "daddu $4, $16, $0\n"
    ".word 0x10000003 /* b .L0041FB78: raw word */\n"
    "daddu $5, $2, $0\n"
    ".L0041FB70:\n"
    "daddu $5, $4, $0\n"
    "nop\n"
    ".L0041FB78:\n"
    "jal func_00411F18\n"
    "nop\n"
    ".L0041FB80:\n"
    "lq $16, 0x30($29)\n"
    ".L0041FB84:\n"
    "lq $17, 0x20($29)\n"
    "lq $18, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x40\n"
    ".end func_0041F9D8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FB98);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424488(int);
int func_0041FB98(int err, int a) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424488(a);
    if (r == -1 && D_004A5BB8)
        *(int *)err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FBF0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424558(int, int);
int func_0041FBF0(int *err, int a, int b) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424558(a, b);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FC50);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424498(int, int, int);
long func_0041FC50(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424498(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FCB0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424460(int, int, int);
int func_0041FCB0(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424460(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FD10);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_004243E8(int, int, int);
long func_0041FD10(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_004243E8(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FD70);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern unsigned func_004244A0(int);
unsigned func_0041FD70(int *err, int a) {
    unsigned r;
    D_004A5BB8 = 0;
    r = func_004244A0(a);
    if (r == 0xFFFFFFFF && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FDD0);
#ifdef SKIP_ASM
extern int D_004A5BB8;
extern int func_00424368(int, int, int);
long func_0041FDD0(int *err, int a, int b, int c) {
    int r;
    D_004A5BB8 = 0;
    r = func_00424368(a, b, c);
    if (r == -1 && D_004A5BB8)
        *err = D_004A5BB8;
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FE30);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_0041FE30\n.ent func_0041FE30\nfunc_0041FE30:\n"
    "addiu $29, $29, -0x40\n"
    "sq $17, 0x20($29)\n"
    "sq $16, 0x30($29)\n"
    "daddu $17, $4, $0\n"
    "sq $18, 0x10($29)\n"
    ".word 0x16200008 /* bnez $17, .L0041FE68: raw word */\n"
    "sd $31, 0x0($29)\n"
    "lui $2, %hi(D_00454944)\n"
    "lui $5, %hi(func_0041FE30)\n"
    "lw $4, %lo(D_00454944)($2)\n"
    "jal func_00417418\n"
    "addiu $5, $5, %lo(func_0041FE30)\n"
    ".word 0x10000031 /* b .L0041FF28: raw word */\n"
    "lq $16, 0x30($29)\n"
    ".L0041FE68:\n"
    "lw $2, 0x54($17)\n"
    ".word 0x54400006 /* bnel $2, $0, .L0041FE88: raw word */\n"
    "lw $4, 0x54($17)\n"
    "lui $2, %hi(D_00454944)\n"
    "lw $3, %lo(D_00454944)($2)\n"
    "sw $3, 0x54($17)\n"
    "lw $4, 0x54($17)\n"
    "nop\n"
    ".L0041FE88:\n"
    "lw $2, 0x38($4)\n"
    ".word 0x54400004 /* bnel $2, $0, .L0041FEA0: raw word */\n"
    "lh $3, 0xC($17)\n"
    "jal func_004200F0\n"
    "nop\n"
    "lh $3, 0xC($17)\n"
    ".L0041FEA0:\n"
    "andi $2, $3, 0x8\n"
    ".word 0x1040001F /* beqz $2, .L0041FF24: raw word */\n"
    "daddu $2, $0, $0\n"
    "lw $18, 0x10($17)\n"
    ".word 0x56400008 /* bnel $18, $0, .L0041FED4: raw word */\n"
    "lw $2, 0x0($17)\n"
    ".word 0x1000001B /* b .L0041FF28: raw word */\n"
    "lq $16, 0x30($29)\n"
    ".L0041FEC0:\n"
    "lhu $3, 0xC($17)\n"
    "addiu $2, $0, -0x1\n"
    "ori $3, $3, 0x40\n"
    ".word 0x10000015 /* b .L0041FF24: raw word */\n"
    "sh $3, 0xC($17)\n"
    ".L0041FED4:\n"
    "andi $3, $3, 0x3\n"
    "sw $18, 0x0($17)\n"
    "daddu $4, $0, $0\n"
    ".word 0x14600002 /* bnez $3, .L0041FEEC: raw word */\n"
    "subu $16, $2, $18\n"
    "lw $4, 0x14($17)\n"
    ".L0041FEEC:\n"
    ".word 0x1A00000C /* blez $16, .L0041FF20: raw word */\n"
    "sw $4, 0x8($17)\n"
    "nop\n"
    ".L0041FEF8:\n"
    "lw $2, 0x24($17)\n"
    "daddu $5, $18, $0\n"
    "lw $4, 0x1C($17)\n"
    "jalr $2\n"
    "daddu $6, $16, $0\n"
    "daddu $3, $2, $0\n"
    ".word 0x1860FFEB /* blez $3, .L0041FEC0: raw word */\n"
    "subu $16, $16, $3\n"
    ".word 0x1E00FFF7 /* bgtz $16, .L0041FEF8: raw word */\n"
    "addu $18, $18, $3\n"
    ".L0041FF20:\n"
    "daddu $2, $0, $0\n"
    ".L0041FF24:\n"
    "lq $16, 0x30($29)\n"
    ".L0041FF28:\n"
    "lq $17, 0x20($29)\n"
    "lq $18, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x40\n"
    ".end func_0041FE30\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FF40);
#ifdef SKIP_ASM
struct F41FF40 {
    int p, r, w;
    short flags, file;
    int base, size_, lbf;
    int cookie;
    void *rd, *wr, *sk, *cl;
    int pad[0x54 / 4 - 12];
    int ent;
};
extern long func_00417948(), func_004179B0(), func_00417A30();
void func_0041FF40(struct F41FF40 *f, short flags, short file, int ent) {
    f->p = 0;
    f->r = 0;
    f->w = 0;
    f->flags = flags;
    f->file = file;
    f->base = 0;
    f->lbf = 0;
    f->cookie = (int)f;
    f->rd = func_00417948;
    f->wr = func_004179B0;
    f->sk = func_00417A30;
    f->cl = (void *)func_00417A98;
    f->ent = ent;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041FF98);
#ifdef SKIP_ASM
extern void *func_00416210(void *, int, int);
int *func_0041FF98(int a, int cnt) {
    int sz = cnt * 0x58;
    int *p = (int *)func_0041DBF8(a, sz + 0xC);
    if (!p)
        return 0;
    p[1] = cnt;
    p[0] = 0;
    p[2] = (int)(p + 3);
    func_00416210(p + 3, 0, sz);
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420010);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00420010\n.ent func_00420010\nfunc_00420010:\n"
    "addiu $29, $29, -0x30\n"
    "sq $17, 0x10($29)\n"
    "sq $16, 0x20($29)\n"
    "daddu $17, $4, $0\n"
    "sd $31, 0x0($29)\n"
    "lw $2, 0x38($17)\n"
    ".word 0x14400003 /* bnez $2, .L00420038: raw word */\n"
    "addiu $16, $17, 0x1D8\n"
    "jal func_004200F0\n"
    "nop\n"
    ".L00420038:\n"
    "lw $3, 0x4($16)\n"
    "addiu $3, $3, -0x1\n"
    ".word 0x04600008 /* bltz $3, .L00420064: raw word */\n"
    "lw $4, 0x8($16)\n"
    ".L00420048:\n"
    "lh $2, 0xC($4)\n"
    ".word 0x10400013 /* beqz $2, .L0042009C: raw word */\n"
    "addiu $3, $3, -0x1\n"
    "nop\n"
    "nop\n"
    ".word 0x0461FFFA /* bgez $3, .L00420048: raw word */\n"
    "addiu $4, $4, 0x58\n"
    ".L00420064:\n"
    "lw $2, 0x0($16)\n"
    ".word 0x5440FFF3 /* bnel $2, $0, .L00420038: raw word */\n"
    "lw $16, 0x0($16)\n"
    "daddu $4, $17, $0\n"
    "jal func_0041FF98\n"
    "addiu $5, $0, 0x4\n"
    ".word 0x10400003 /* beqz $2, .L0042008C: raw word */\n"
    "sw $2, 0x0($16)\n"
    ".word 0x1000FFEC /* b .L00420038: raw word */\n"
    "lw $16, 0x0($16)\n"
    ".L0042008C:\n"
    "addiu $3, $0, 0xC\n"
    "daddu $2, $0, $0\n"
    ".word 0x10000011 /* b .L004200DC: raw word */\n"
    "sw $3, 0x0($17)\n"
    ".L0042009C:\n"
    "addiu $2, $0, 0x1\n"
    "addiu $3, $0, -0x1\n"
    "sh $2, 0xC($4)\n"
    "sh $3, 0xE($4)\n"
    "daddu $2, $4, $0\n"
    "sw $17, 0x54($4)\n"
    "sw $0, 0x0($4)\n"
    "sw $0, 0x8($4)\n"
    "sw $0, 0x4($4)\n"
    "sw $0, 0x10($4)\n"
    "sw $0, 0x14($4)\n"
    "sw $0, 0x18($4)\n"
    "sw $0, 0x30($4)\n"
    "sw $0, 0x34($4)\n"
    "sw $0, 0x44($4)\n"
    "sw $0, 0x48($4)\n"
    ".L004200DC:\n"
    "lq $16, 0x20($29)\n"
    "lq $17, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x30\n"
    ".end func_00420010\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004200F0);
#ifdef SKIP_ASM
void func_004200F0(char *r) {
    char *f0 = r + 0x1E4;
    *(void **)(r + 0x3C) = (void *)func_00416FC0;
    *(int *)(r + 0x38) = 1;
    func_0041FF40((void *)f0, 4, 0, (int)r);
    func_0041FF40((void *)(r + 0x23C), 9, 1, (int)r);
    func_0041FF40((void *)(r + 0x294), 0xA, 2, (int)r);
    *(char **)(r + 0x1E0) = f0;
    *(int *)(r + 0x1DC) = 3;
    *(int *)(r + 0x1D8) = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420180);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00420180\n.ent func_00420180\nfunc_00420180:\n"
    "lb $3, 0x0($5)\n"
    "addiu $2, $0, 0x72\n"
    ".word 0x1062000C /* beq $3, $2, .L004201BC: raw word */\n"
    "slti $2, $3, 0x73\n"
    ".word 0x10400005 /* beqz $2, .L004201A8: raw word */\n"
    "addiu $2, $0, 0x61\n"
    ".word 0x10620010 /* beq $3, $2, .L004201DC: raw word */\n"
    "addiu $3, $0, 0x16\n"
    ".word 0x10000012 /* b .L004201EC: raw word */\n"
    "daddu $2, $0, $0\n"
    ".L004201A8:\n"
    "addiu $2, $0, 0x77\n"
    ".word 0x10620007 /* beq $3, $2, .L004201CC: raw word */\n"
    "addiu $3, $0, 0x16\n"
    ".word 0x1000000D /* b .L004201EC: raw word */\n"
    "daddu $2, $0, $0\n"
    ".L004201BC:\n"
    "addiu $9, $0, 0x4\n"
    "daddu $7, $0, $0\n"
    ".word 0x1000000B /* b .L004201F4: raw word */\n"
    "daddu $8, $0, $0\n"
    ".L004201CC:\n"
    "addiu $9, $0, 0x8\n"
    "addiu $7, $0, 0x1\n"
    ".word 0x10000007 /* b .L004201F4: raw word */\n"
    "addiu $8, $0, 0x600\n"
    ".L004201DC:\n"
    "addiu $9, $0, 0x108\n"
    "addiu $7, $0, 0x1\n"
    ".word 0x10000003 /* b .L004201F4: raw word */\n"
    "addiu $8, $0, 0x208\n"
    ".L004201EC:\n"
    "jr $31\n"
    "sw $3, 0x0($4)\n"
    ".L004201F4:\n"
    "lb $2, 0x1($5)\n"
    "addiu $3, $0, 0x2B\n"
    ".word 0x50430005 /* beql $2, $3, .L00420214: raw word */\n"
    "addiu $9, $0, 0x10\n"
    "lb $2, 0x2($5)\n"
    ".word 0x14430004 /* bne $2, $3, .L0042021C: raw word */\n"
    "or $3, $7, $8\n"
    "addiu $9, $0, 0x10\n"
    ".L00420214:\n"
    "addiu $7, $0, 0x2\n"
    "or $3, $7, $8\n"
    ".L0042021C:\n"
    "daddu $2, $9, $0\n"
    "jr $31\n"
    "sw $3, 0x0($6)\n"
    ".end func_00420180\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420228);
#ifdef SKIP_ASM
void func_00420228(char *d, char *s, unsigned n) {
    while (n--)
        *d++ = *s++;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420260);
#ifdef SKIP_ASM
extern void func_00420228(char *, char *, unsigned);
extern int func_00417648(int *);
unsigned func_00420260(char *buf, unsigned size, unsigned count, int *fp) {
    unsigned resid, total, r;
    char *p;
    if ((resid = count * size) == 0)
        return 0;
    if (fp[1] < 0)
        fp[1] = 0;
    total = resid;
    p = buf;
    while (resid > (r = fp[1])) {
        func_00420228(p, (char *)fp[0], r);
        p += r;
        fp[0] = fp[0] + r;
        resid -= r;
        if (func_00417648(fp))
            return (total - resid) / size;
    }
    func_00420228(p, (char *)fp[0], resid);
    fp[1] -= resid;
    fp[0] += resid;
    return count;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", ungetc);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl ungetc\n.ent ungetc\nungetc:\n"
    "addiu $29, $29, -0x30\n"
    "addiu $2, $0, -0x1\n"
    "sq $16, 0x20($29)\n"
    "sq $17, 0x10($29)\n"
    "daddu $16, $5, $0\n"
    "daddu $17, $4, $0\n"
    ".word 0x12220059 /* beq $17, $2, .L004204F8: raw word */\n"
    "sd $31, 0x0($29)\n"
    "lw $2, 0x54($16)\n"
    ".word 0x54400006 /* bnel $2, $0, .L004203B8: raw word */\n"
    "lw $4, 0x54($16)\n"
    "lui $2, %hi(D_00454944)\n"
    "lw $3, %lo(D_00454944)($2)\n"
    "sw $3, 0x54($16)\n"
    "lw $4, 0x54($16)\n"
    "nop\n"
    ".L004203B8:\n"
    "lw $2, 0x38($4)\n"
    ".word 0x54400004 /* bnel $2, $0, .L004203D0: raw word */\n"
    "lhu $2, 0xC($16)\n"
    "jal func_004200F0\n"
    "nop\n"
    "lhu $2, 0xC($16)\n"
    ".L004203D0:\n"
    "andi $3, $2, 0xFFDF\n"
    "andi $2, $3, 0x4\n"
    ".word 0x14400012 /* bnez $2, .L00420424: raw word */\n"
    "sh $3, 0xC($16)\n"
    "andi $2, $3, 0x10\n"
    ".word 0x1040001C /* beqz $2, .L00420458: raw word */\n"
    "andi $2, $3, 0x8\n"
    ".word 0x5040000B /* beql $2, $0, .L0042041C: raw word */\n"
    "lhu $2, 0xC($16)\n"
    "jal func_0041FE30\n"
    "daddu $4, $16, $0\n"
    ".word 0x1440003E /* bnez $2, .L004204F8: raw word */\n"
    "addiu $2, $0, -0x1\n"
    "lhu $2, 0xC($16)\n"
    "sw $0, 0x8($16)\n"
    "andi $2, $2, 0xFFF7\n"
    "sw $0, 0x18($16)\n"
    "sh $2, 0xC($16)\n"
    "lhu $2, 0xC($16)\n"
    ".L0042041C:\n"
    "ori $2, $2, 0x4\n"
    "sh $2, 0xC($16)\n"
    ".L00420424:\n"
    "lw $2, 0x30($16)\n"
    ".word 0x10400015 /* beqz $2, .L00420480: raw word */\n"
    "andi $17, $17, 0xFF\n"
    "lw $2, 0x4($16)\n"
    "lw $3, 0x34($16)\n"
    "slt $2, $2, $3\n"
    ".word 0x54400008 /* bnel $2, $0, .L00420460: raw word */\n"
    "lw $4, 0x0($16)\n"
    "lui $5, %hi(D_0049A8A0)\n"
    "addiu $4, $0, 0x1\n"
    "addiu $5, $5, %lo(D_0049A8A0)\n"
    "jal func_00424368\n"
    "addiu $6, $0, 0x44\n"
    ".L00420458:\n"
    ".word 0x10000027 /* b .L004204F8: raw word */\n"
    "addiu $2, $0, -0x1\n"
    ".L00420460:\n"
    "daddu $2, $17, $0\n"
    "addiu $3, $4, -0x1\n"
    "sw $3, 0x0($16)\n"
    "sb $17, -0x1($4)\n"
    "lw $3, 0x4($16)\n"
    "addiu $3, $3, 0x1\n"
    ".word 0x1000001F /* b .L004204F8: raw word */\n"
    "sw $3, 0x4($16)\n"
    ".L00420480:\n"
    "lw $2, 0x10($16)\n"
    ".word 0x5040000F /* beql $2, $0, .L004204C4: raw word */\n"
    "lw $4, 0x4($16)\n"
    "lw $4, 0x0($16)\n"
    "sltu $2, $2, $4\n"
    ".word 0x5040000B /* beql $2, $0, .L004204C4: raw word */\n"
    "lw $4, 0x4($16)\n"
    "lbu $2, -0x1($4)\n"
    ".word 0x54510008 /* bnel $2, $17, .L004204C4: raw word */\n"
    "lw $4, 0x4($16)\n"
    "lw $3, 0x4($16)\n"
    "addiu $2, $4, -0x1\n"
    "sw $2, 0x0($16)\n"
    "addiu $3, $3, 0x1\n"
    "daddu $2, $17, $0\n"
    ".word 0x1000000E /* b .L004204F8: raw word */\n"
    "sw $3, 0x4($16)\n"
    ".L004204C4:\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x0($16)\n"
    "addiu $7, $16, 0x40\n"
    "addiu $5, $0, 0x3\n"
    "addiu $6, $16, 0x42\n"
    "sw $2, 0x4($16)\n"
    "sw $4, 0x3C($16)\n"
    "daddu $2, $17, $0\n"
    "sw $3, 0x38($16)\n"
    "sw $7, 0x30($16)\n"
    "sw $5, 0x34($16)\n"
    "sw $6, 0x0($16)\n"
    "sb $17, 0x42($16)\n"
    ".L004204F8:\n"
    "lq $16, 0x20($29)\n"
    "lq $17, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x30\n"
    ".end ungetc\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420510);
#ifdef SKIP_ASM
extern int *func_004224A0(int *, int, int);
int *func_00420510(int ep_, int k) {
    int *ep = (int *)ep_;
    int x;
    int *rv;
    if (ep[0x4C / 4] == 0) {
        ep[0x4C / 4] = (int)func_004224A0(ep, 4, 16);
        if (ep[0x4C / 4] == 0)
            return 0;
    }
    rv = ((int **)ep[0x4C / 4])[k];
    if (rv) {
        ((int **)ep[0x4C / 4])[k] = (int *)*rv;
    } else {
        x = 1 << k;
        rv = func_004224A0(ep, 1, 0x18 + (x - 1) * 4);
        if (rv == 0)
            return 0;
        rv[1] = k;
        rv[2] = x;
    }
    rv[3] = rv[4] = 0;
    return rv;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004205B8);
#ifdef SKIP_ASM
void func_004205B8(int *self, int *p) {
    if (p) {
        int i = p[1];
        p[0] = ((int *)self[0x4C / 4])[i];
        ((int **)self[0x4C / 4])[i] = p;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004205F0);
#ifdef SKIP_ASM
struct Bigint {
    struct Bigint *next;
    int k, maxwds, sign, wds;
    unsigned x[1];
};
extern int *func_00420510(int, int);
extern void func_004205B8(int *, int *);
extern void *func_0041605C(void *, void *, int);
struct Bigint *func_004205F0(int ptr, struct Bigint *b, int m, int a) {
    int i, wds;
    unsigned *x, y, xi, z, carry;
    struct Bigint *b1;
    wds = b->wds;
    x = b->x;
    i = 0;
    carry = a;
    do {
        xi = *x;
        y = (xi & 0xffff) * m + carry;
        z = (xi >> 16) * m + (y >> 16);
        carry = z >> 16;
        *x++ = (z << 16) + (y & 0xffff);
    } while (++i < wds);
    if (carry) {
        if (wds >= b->maxwds) {
            b1 = (struct Bigint *)func_00420510(ptr, b->k + 1);
            func_0041605C(&b1->sign, &b->sign, b->wds * 4 + 8);
            func_004205B8((int *)ptr, (int *)b);
            b = b1;
        }
        b->x[wds++] = carry;
        b->wds = wds;
    }
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004206F8);
#ifdef SKIP_ASM
extern struct Bigint *func_004205F0(int, struct Bigint *, int, int);
struct Bigint *func_004206F8(int ptr, char *s, int nd0, int nd, int y9) {
    struct Bigint *b;
    int i, k;
    int x, y;
    x = (nd + 8) / 9;
    for (k = 0, y = 1; x > y; y <<= 1, k++)
        ;
    b = (struct Bigint *)func_00420510(ptr, k);
    b->x[0] = y9;
    b->wds = 1;
    i = 9;
    if (9 < nd0) {
        s += 9;
        do
            b = func_004205F0(ptr, b, 10, *s++ - '0');
        while (++i < nd0);
        s++;
    } else
        s += 10;
    for (; i < nd; i++)
        b = func_004205F0(ptr, b, 10, *s++ - '0');
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420830);
#ifdef SKIP_ASM
int func_00420830(unsigned x) {
    int k = 0;
    if (!(x & 0xffff0000)) {
        k = 16;
        x <<= 16;
    }
    if (!(x & 0xff000000)) {
        k += 8;
        x <<= 8;
    }
    if (!(x & 0xf0000000)) {
        k += 4;
        x <<= 4;
    }
    if (!(x & 0xc0000000)) {
        k += 2;
        x <<= 2;
    }
    if (!(x & 0x80000000)) {
        k++;
        if (!(x & 0x40000000))
            return 32;
    }
    return k;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004208B8);
#ifdef SKIP_ASM
int func_004208B8(unsigned *y) {
    int k;
    unsigned x = *y;
    if (x & 7) {
        if (x & 1)
            return 0;
        if (x & 2) {
            *y = x >> 1;
            return 1;
        }
        *y = x >> 2;
        return 2;
    }
    k = 0;
    if (!(x & 0xffff)) {
        k = 16;
        x >>= 16;
    }
    if (!(x & 0xff)) {
        k += 8;
        x >>= 8;
    }
    if (!(x & 0xf)) {
        k += 4;
        x >>= 4;
    }
    if (!(x & 3)) {
        k += 2;
        x >>= 2;
    }
    if (!(x & 1)) {
        k++;
        x >>= 1;
        if (!x)
            return 32;
    }
    *y = x;
    return k;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420978);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
int *func_00420978(int a, int b) {
    int *p = func_00420510(a, 1);
    p[5] = b;
    p[4] = 1;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004209B0);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
struct Bigint *func_004209B0(int ptr, struct Bigint *a, struct Bigint *b) {
    struct Bigint *c;
    int i, k, wa, wb, wc;
    unsigned *x, *xa, *xae, *xb, *xbe, *xc, *xc0;
    unsigned y, carry, z, z2;
    if (a->wds < b->wds) {
        c = a;
        a = b;
        b = c;
    }
    k = a->k;
    wa = a->wds;
    wb = b->wds;
    wc = wa + wb;
    if (wc > a->maxwds)
        k++;
    c = (struct Bigint *)func_00420510(ptr, k);
    for (x = c->x, xa = x + wc; x < xa; x++)
        *x = 0;
    xa = a->x;
    xae = xa + wa;
    xb = b->x;
    xbe = xb + wb;
    xc0 = c->x;
    for (; xb < xbe; xb++, xc0++) {
        if ((y = *xb & 0xffff)) {
            x = xa;
            xc = xc0;
            carry = 0;
            do {
                z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
                carry = z >> 16;
                z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
                carry = z2 >> 16;
                ((unsigned short *)xc)[1] = z2;
                ((unsigned short *)xc)[0] = z;
                xc++;
            } while (x < xae);
            *xc = carry;
        }
        if ((y = *xb >> 16)) {
            x = xa;
            xc = xc0;
            carry = 0;
            z2 = *xc;
            do {
                z = (*x & 0xffff) * y + (*xc >> 16) + carry;
                carry = z >> 16;
                ((unsigned short *)xc)[1] = z;
                ((unsigned short *)xc)[0] = z2;
                xc++;
                z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
                carry = z2 >> 16;
            } while (x < xae);
            *xc = z2;
        }
    }
    for (xc0 = c->x, xc = xc0 + wc; wc > 0 && !*--xc; --wc)
        ;
    c->wds = wc;
    return c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420BC8);
#ifdef SKIP_ASM
extern struct Bigint *func_004205F0(int, struct Bigint *, int, int);
extern struct Bigint *func_004209B0(int, struct Bigint *, struct Bigint *);
extern int *func_00420978(int, int);
extern void func_004205B8(int *, int *);
extern int D_0049A8E8[];
struct Bigint *func_00420BC8(int ptr, struct Bigint *b, int k) {
    struct Bigint *b1, *p5, *p51;
    int i;
    if ((i = k & 3))
        b = func_004205F0(ptr, b, D_0049A8E8[i - 1], 0);
    if (!(k >>= 2))
        return b;
    if (!(p5 = ((struct Bigint **)ptr)[0x48 / 4])) {
        p5 = ((struct Bigint **)ptr)[0x48 / 4] = (struct Bigint *)func_00420978(ptr, 625);
        p5->next = 0;
    }
    for (;;) {
        if (k & 1) {
            b1 = func_004209B0(ptr, b, p5);
            func_004205B8((int *)ptr, (int *)b);
            b = b1;
        }
        if (!(k >>= 1))
            break;
        if (!(p51 = p5->next)) {
            p51 = p5->next = func_004209B0(ptr, p5, p5);
            p51->next = 0;
        }
        p5 = p51;
    }
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420CC8);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
extern void func_004205B8(int *, int *);
struct Bigint *func_00420CC8(int ptr, struct Bigint *b, int k) {
    int i, k1, n, n1;
    struct Bigint *b1;
    unsigned *x, *x1, *xe, z;
    n = k >> 5;
    k1 = b->k;
    n1 = n + b->wds + 1;
    for (i = b->maxwds; n1 > i; i <<= 1)
        k1++;
    b1 = (struct Bigint *)func_00420510(ptr, k1);
    x1 = b1->x;
    for (i = 0; i < n; i++)
        *x1++ = 0;
    x = b->x;
    xe = x + b->wds;
    if (k &= 0x1f) {
        k1 = 32 - k;
        z = 0;
        do {
            *x1++ = *x << k | z;
            z = *x++ >> k1;
        } while (x < xe);
        if ((*x1 = z))
            ++n1;
    } else
        do
            *x1++ = *x++;
        while (x < xe);
    b1->wds = n1 - 1;
    func_004205B8((int *)ptr, (int *)b);
    return b1;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420E28);
#ifdef SKIP_ASM
struct Bigint28 {
    struct Bigint28 *next;
    int k, maxwds, sign, wds;
    unsigned x[1];
};
int func_00420E28(struct Bigint28 *a, struct Bigint28 *b) {
    unsigned *xa, *xa0, *xb, *xb0;
    int i, j;
    i = a->wds;
    j = b->wds;
    if (i -= j)
        return i;
    xa0 = a->x;
    xa = xa0 + j;
    xb0 = b->x;
    xb = xb0 + j;
    for (;;) {
        if (*--xa != *--xb)
            return *xa < *xb ? -1 : 1;
        if (xa <= xa0)
            break;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00420E90);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
struct Bigint *func_00420E90(int ptr, struct Bigint *a, struct Bigint *b) {
    struct Bigint *c;
    int i, wa, wb;
    int borrow, y, z;
    unsigned *xa, *xae, *xb, *xbe, *xc;
    i = func_00420E28((struct Bigint28 *)a, (struct Bigint28 *)b);
    if (!i) {
        c = (struct Bigint *)func_00420510(ptr, 0);
        c->wds = 1;
        c->x[0] = 0;
        return c;
    }
    if (i < 0) {
        c = a;
        a = b;
        b = c;
        i = 1;
    } else
        i = 0;
    c = (struct Bigint *)func_00420510(ptr, a->k);
    c->sign = i;
    wa = a->wds;
    xa = a->x;
    xae = xa + wa;
    wb = b->wds;
    xb = b->x;
    xbe = xb + wb;
    xc = c->x;
    borrow = 0;
    do {
        y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
        borrow = z >> 16;
        ((unsigned short *)xc)[1] = z;
        ((unsigned short *)xc)[0] = y;
        xc++;
    } while (xb < xbe);
    while (xa < xae) {
        y = (*xa & 0xffff) + borrow;
        borrow = y >> 16;
        z = (*xa++ >> 16) + borrow;
        borrow = z >> 16;
        ((unsigned short *)xc)[1] = z;
        ((unsigned short *)xc)[0] = y;
        xc++;
    }
    while (!*--xc)
        wa--;
    c->wds = wa;
    return c;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421020);
#ifdef SKIP_ASM
union double_union {
    double d;
    struct {
        unsigned long lo : 32;
        unsigned long hi : 32;
    } w;
    long l;
};
#define word0(x) x.w.hi
#define word1(x) x.w.lo
double func_00421020(double _x) {
    union double_union x, a;
    int L;
    x.d = _x;
    L = (word0(x) & 0x7ff00000) - 52 * 0x100000;
    if (L > 0) {
        word0(a) = L;
        word1(a) = 0;
    } else {
        L = -L >> 20;
        if (L < 20) {
            word0(a) = 0x80000 >> L;
            word1(a) = 0;
        } else {
            word0(a) = 0;
            L -= 20;
            word1(a) = L >= 31 ? 1 : 1 << (31 - L);
        }
    }
    return a.d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004210E8);
#ifdef SKIP_ASM
extern int func_00420830(unsigned);
double func_004210E8(struct Bigint *a, int *e) {
    unsigned *xa, *xa0, w, y, z;
    int k;
    union double_union d;
    xa0 = a->x;
    xa = xa0 + a->wds;
    y = *--xa;
    k = func_00420830(y);
    *e = 32 - k;
    if (k < 11) {
        d.w.hi = 0x3ff00000 | y >> (11 - k);
        w = xa > xa0 ? *--xa : 0;
        d.w.lo = y << (21 + k) | w >> (11 - k);
        goto ret_d;
    }
    z = xa > xa0 ? *--xa : 0;
    if (k -= 11) {
        d.w.hi = 0x3ff00000 | y << k | z >> (32 - k);
        y = xa > xa0 ? *--xa : 0;
        d.w.lo = z << k | y >> (32 - k);
    } else {
        d.w.hi = 0x3ff00000 | y;
        d.w.lo = z;
    }
ret_d:
    return d.d;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421280);
#ifdef SKIP_ASM
extern int *func_00420510(int, int);
extern int func_004208B8(unsigned *);
extern int func_00420830(unsigned);
struct Bigint *func_00421280(int ptr, double _d, int *e, int *bits) {
    struct Bigint *b;
    int de, i, k;
    unsigned *x, y, z;
    union double_union d;
    d.d = _d;
    b = (struct Bigint *)func_00420510(ptr, 1);
    x = b->x;
    z = d.w.hi & 0xfffff;
    d.w.hi &= 0x7fffffff;
    if ((de = (int)(d.w.hi >> 20)))
        z |= 0x100000;
    if ((y = d.w.lo)) {
        if ((k = func_004208B8(&y))) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else
            x[0] = y;
        i = b->wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_004208B8(&z);
        x[0] = z;
        i = b->wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1023 - 52 + k;
        *bits = 53 - k;
    } else {
        *e = de - 1023 - 52 + 1 + k;
        *bits = 32 * i - func_00420830(x[i - 1]);
    }
    return b;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421400);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00421400\n.ent func_00421400\nfunc_00421400:\n"
    "addiu $29, $29, -0x50\n"
    "sq $16, 0x40($29)\n"
    "sq $17, 0x30($29)\n"
    "daddu $16, $4, $0\n"
    "daddu $17, $5, $0\n"
    "sq $18, 0x20($29)\n"
    "sd $31, 0x10($29)\n"
    "jal func_004210E8\n"
    "daddu $5, $29, $0\n"
    "daddu $4, $17, $0\n"
    "ori $5, $29, 0x4\n"
    "jal func_004210E8\n"
    "daddu $18, $2, $0\n"
    "lw $3, 0x10($16)\n"
    "daddu $6, $2, $0\n"
    "lw $4, 0x10($17)\n"
    "lw $2, 0x0($29)\n"
    "lw $5, 0x4($29)\n"
    "subu $3, $3, $4\n"
    "sll $3, $3, 5\n"
    "subu $2, $2, $5\n"
    "addu $2, $2, $3\n"
    ".word 0x18400009 /* blez $2, .L00421480: raw word */\n"
    "sll $2, $2, 20\n"
    "dsra32 $3, $18, 0\n"
    "addu $3, $3, $2\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "dsll32 $3, $3, 0\n"
    "and $18, $18, $4\n"
    ".word 0x10000008 /* b .L0042149C: raw word */\n"
    "or $18, $18, $3\n"
    ".L00421480:\n"
    "dsra32 $3, $6, 0\n"
    "subu $3, $3, $2\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "dsll32 $3, $3, 0\n"
    "and $6, $6, $4\n"
    "or $6, $6, $3\n"
    ".L0042149C:\n"
    "daddu $4, $18, $0\n"
    "jal func_00412280\n"
    "daddu $5, $6, $0\n"
    "lq $16, 0x40($29)\n"
    "lq $17, 0x30($29)\n"
    "lq $18, 0x20($29)\n"
    "ld $31, 0x10($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x50\n"
    ".end func_00421400\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004214C0);
#ifdef SKIP_ASM
extern double D_0049A8F8[];
extern double func_00411FD8(double, double);
double func_004214C0(int n) {
    double r = 1.0;
    if (n < 24)
        return D_0049A8F8[n];
    if (n > 0) {
        do {
            r = func_00411FD8(r, 10.0);
        } while (--n > 0);
    }
    return r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421530);
#ifdef SKIP_ASM
struct R21530;
extern char *g21530_dtoa(struct R21530 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
extern char *g21530_strcpy(char *, char *) __asm__("strcpy");
void func_00421530_(struct R21530 *ptr, char *buf, double invalue, int ndigit, int type, int dot, int mode) __asm__("func_00421530");
void func_00421530_(struct R21530 *ptr, char *buf, double invalue, int ndigit, int type, int dot, int mode) {
    int decpt;
    int sign;
    char *p, *start, *end;
    start = p = g21530_dtoa(ptr, invalue, mode, ndigit, &decpt, &sign, &end);
    if (decpt == 9999) {
        g21530_strcpy(buf, p);
        return;
    }
    while (*p != '\0' && decpt > 0) {
        *buf++ = *p++;
        decpt--;
    }
    while (decpt > 0) {
        *buf++ = '0';
        decpt--;
    }
    if (dot == 0 && *p == '\0') {
        *buf = '\0';
        return;
    }
    if (p == start)
        *buf++ = '0';
    *buf++ = '.';
    while (decpt < 0 && ndigit > 0) {
        *buf++ = '0';
        decpt++;
        ndigit--;
    }
    while (*p && ndigit > 0) {
        *buf++ = *p++;
        ndigit--;
    }
    while (ndigit > 0) {
        *buf++ = '0';
        ndigit--;
    }
    *buf = '\0';
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004216E8);
#ifdef SKIP_ASM
struct R216E8;
extern char *g216E8_dtoa(struct R216E8 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
extern char *g216E8_strcpy(char *, char *) __asm__("strcpy");
void func_004216E8_(struct R216E8 *ptr, char *buf, double invalue, int ndigit, char type, int dot) __asm__("func_004216E8");
void func_004216E8_(struct R216E8 *ptr, char *buf, double invalue, int ndigit, char type, int dot) {
    int decpt;
    int i = ndigit;
    int sign;
    char *p, *end;
    p = g216E8_dtoa(ptr, invalue, 2, i + 1, &decpt, &sign, &end);
    if (decpt == 9999) {
        g216E8_strcpy(buf, p);
        return;
    }
    *buf++ = *p++;
    if (dot || i != 0)
        *buf++ = '.';
    while (*p && i > 0) {
        *buf++ = *p++;
        i--;
    }
    if (type == 'g')
        type = 'e';
    else if (type == 'G')
        type = 'E';
    else {
        while (i > 0) {
            *buf++ = '0';
            i--;
        }
    }
    *buf++ = type;
    decpt--;
    if (decpt < 0) {
        *buf++ = '-';
        decpt = -decpt;
    } else
        *buf++ = '+';
    if (decpt >= 100) {
        int dig = decpt / 100;
        *buf++ = dig + '0';
        decpt -= dig * 100;
    }
    {
        int dig = decpt / 10;
        *buf++ = dig + '0';
        decpt -= dig * 10;
    }
    *buf++ = decpt + '0';
    *buf = '\0';
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004218D8);
#ifdef SKIP_ASM
struct R218D8 {
    int pad0[0x50 / 4];
    int cvtlen;
    char *cvtbuf;
};
extern struct R218D8 *g218D8_impure __asm__("D_00454944");
#define REENT218D8 g218D8_impure
extern char *g218D8_realloc(struct R218D8 *, char *, int) __asm__("func_00421F20");
extern char *g218D8_dtoa(struct R218D8 *, double, int, int, int *, int *, char **) __asm__("func_00422780");
char *func_004218D8_(double invalue, int ndigit, int *decpt, int *sign, char *buf) __asm__("func_004218D8");
char *func_004218D8_(double invalue, int ndigit, int *decpt, int *sign, char *buf) {
    char *save, *p, *end;
    int done = 0;
    int newlen;
    if (buf == 0) {
        if (ndigit >= REENT218D8->cvtlen) {
            newlen = ndigit + 1;
            buf = g218D8_realloc(REENT218D8, REENT218D8->cvtbuf, newlen);
            if (buf == 0)
                return 0;
            REENT218D8->cvtlen = newlen;
            REENT218D8->cvtbuf = buf;
        }
        buf = REENT218D8->cvtbuf;
    }
    save = buf;
    if (invalue < 1.0 && invalue > -1.0)
        p = g218D8_dtoa(REENT218D8, invalue, 2, ndigit, decpt, sign, &end);
    else
        p = g218D8_dtoa(REENT218D8, invalue, 3, ndigit, decpt, sign, &end);
    while (p < end) {
        *buf++ = *p++;
        done++;
    }
    if (done < ndigit) {
        done = ndigit - done;
        do {
            *buf++ = '0';
        } while (--done);
    }
    *buf = 0;
    return save;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421A50);
#ifdef SKIP_ASM
struct Reent51 {
    int pad0[0x50 / 4];
    int cvtlen;
    char *cvtbuf;
};
extern int D_00454944;
#define REENT ((struct Reent51 *)D_00454944)
extern char *func_00421F20(struct Reent51 *, char *, int);
extern char *func_00422780(struct Reent51 *, double, int, int, int *, int *, char **);
char *func_00421A50_(double value, int ndigit, int *decpt, int *sign, char *buf) __asm__("func_00421A50");
char *func_00421A50_(double value, int ndigit, int *decpt, int *sign, char *buf) {
    char *save, *p, *end;
    int i = 0;
    int newlen;
    if (buf == 0) {
        if (ndigit >= REENT->cvtlen) {
            newlen = ndigit + 1;
            buf = func_00421F20(REENT, REENT->cvtbuf, newlen);
            if (buf == 0)
                return 0;
            REENT->cvtlen = newlen;
            REENT->cvtbuf = buf;
        }
        buf = REENT->cvtbuf;
    }
    save = buf;
    p = func_00422780(REENT, value, 2, ndigit, decpt, sign, &end);
    while (p < end) {
        *buf++ = *p++;
        i++;
    }
    if (i < ndigit) {
        i = ndigit - i;
        do {
            *buf++ = '0';
        } while (--i);
    }
    *buf = 0;
    return save;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421B98);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00421B98\n.ent func_00421B98\nfunc_00421B98:\n"
    "addiu $29, $29, -0xA0\n"
    "sll $8, $8, 24\n"
    "sq $16, 0x90($29)\n"
    "sq $18, 0x70($29)\n"
    "daddu $16, $7, $0\n"
    "sq $19, 0x60($29)\n"
    "daddu $18, $5, $0\n"
    "sq $20, 0x50($29)\n"
    "daddu $19, $0, $0\n"
    "sq $17, 0x80($29)\n"
    "daddu $20, $4, $0\n"
    "sq $21, 0x40($29)\n"
    "daddu $17, $6, $0\n"
    "sq $22, 0x30($29)\n"
    "daddu $21, $16, $0\n"
    "sq $23, 0x20($29)\n"
    "daddu $22, $9, $0\n"
    "sd $31, 0x10($29)\n"
    "sra $23, $8, 24\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $19, $0\n"
    ".word 0x04410006 /* bgez $2, .L00421C0C: raw word */\n"
    "daddu $5, $19, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $19, $0\n"
    "daddu $18, $2, $0\n"
    "daddu $5, $19, $0\n"
    ".L00421C0C:\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x14400004 /* bnez $2, .L00421C28: raw word */\n"
    "addiu $2, $0, 0x30\n"
    "sb $0, 0x1($21)\n"
    ".word 0x10000083 /* b .L00421E30: raw word */\n"
    "sb $2, 0x0($21)\n"
    ".L00421C28:\n"
    "ori $5, $0, 0xFC68\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xDB8B\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xAC71\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x32D\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x18400008 /* blez $2, .L00421C70: raw word */\n"
    "daddu $4, $20, $0\n"
    "jal func_004214C0\n"
    "daddu $4, $17, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x04400009 /* bltz $2, .L00421C90: raw word */\n"
    "daddu $4, $20, $0\n"
    ".L00421C70:\n"
    "daddu $6, $18, $0\n"
    "addiu $7, $17, -0x1\n"
    "daddu $8, $23, $0\n"
    "daddu $9, $22, $0\n"
    "jal func_004216E8\n"
    "daddu $5, $21, $0\n"
    ".word 0x1000006A /* b .L00421E34: raw word */\n"
    "daddu $2, $21, $0\n"
    ".L00421C90:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    ".word 0x04410004 /* bgez $2, .L00421CB4: raw word */\n"
    "daddu $5, $18, $0\n"
    "daddu $4, $20, $0\n"
    ".word 0x10000003 /* b .L00421CBC: raw word */\n"
    "addiu $6, $0, 0x3\n"
    ".L00421CB4:\n"
    "daddu $4, $20, $0\n"
    "addiu $6, $0, 0x2\n"
    ".L00421CBC:\n"
    "daddu $7, $17, $0\n"
    "daddu $8, $29, $0\n"
    "ori $9, $29, 0x4\n"
    "jal func_00422780\n"
    "ori $10, $29, 0x8\n"
    "daddu $5, $2, $0\n"
    "lw $3, 0x0($29)\n"
    "addiu $2, $0, 0x270F\n"
    ".word 0x54620005 /* bnel $3, $2, .L00421CF4: raw word */\n"
    "lb $2, 0x0($5)\n"
    "jal strcpy\n"
    "daddu $4, $16, $0\n"
    ".word 0x10000051 /* b .L00421E34: raw word */\n"
    "daddu $2, $16, $0\n"
    ".L00421CF4:\n"
    ".word 0x1040000F /* beqz $2, .L00421D34: raw word */\n"
    "lbu $4, 0x0($5)\n"
    ".word 0x1860001C /* blez $3, .L00421D70: raw word */\n"
    "nop\n"
    "sb $4, 0x0($16)\n"
    ".L00421D08:\n"
    "addiu $5, $5, 0x1\n"
    "addiu $16, $16, 0x1\n"
    "addiu $17, $17, -0x1\n"
    "lw $2, 0x0($29)\n"
    "addiu $3, $2, -0x1\n"
    "sw $3, 0x0($29)\n"
    "lb $2, 0x0($5)\n"
    ".word 0x10400003 /* beqz $2, .L00421D34: raw word */\n"
    "lbu $4, 0x0($5)\n"
    ".word 0x5C60FFF6 /* bgtzl $3, .L00421D08: raw word */\n"
    "sb $4, 0x0($16)\n"
    ".L00421D34:\n"
    "lw $2, 0x0($29)\n"
    ".word 0x1840000D /* blez $2, .L00421D70: raw word */\n"
    "nop\n"
    ".word 0x1A20000B /* blez $17, .L00421D70: raw word */\n"
    "nop\n"
    "addiu $3, $0, 0x30\n"
    "sb $3, 0x0($16)\n"
    ".L00421D50:\n"
    "addiu $17, $17, -0x1\n"
    "addiu $16, $16, 0x1\n"
    "lw $2, 0x0($29)\n"
    "addiu $2, $2, -0x1\n"
    ".word 0x18400003 /* blez $2, .L00421D70: raw word */\n"
    "sw $2, 0x0($29)\n"
    ".word 0x5E20FFF9 /* bgtzl $17, .L00421D50: raw word */\n"
    "sb $3, 0x0($16)\n"
    ".L00421D70:\n"
    ".word 0x16C00004 /* bnez $22, .L00421D84: raw word */\n"
    "nop\n"
    "lb $2, 0x0($5)\n"
    ".word 0x5040002C /* beql $2, $0, .L00421E30: raw word */\n"
    "sb $0, 0x0($16)\n"
    ".L00421D84:\n"
    ".word 0x16150005 /* bne $16, $21, .L00421D9C: raw word */\n"
    "addiu $2, $0, 0x2E\n"
    "addiu $2, $0, 0x30\n"
    "addiu $16, $21, 0x1\n"
    "sb $2, 0x0($21)\n"
    "addiu $2, $0, 0x2E\n"
    ".L00421D9C:\n"
    "sb $2, 0x0($16)\n"
    "lw $2, 0x0($29)\n"
    ".word 0x04410011 /* bgez $2, .L00421DEC: raw word */\n"
    "addiu $16, $16, 0x1\n"
    ".word 0x1A20000F /* blez $17, .L00421DEC: raw word */\n"
    "addiu $3, $0, 0x30\n"
    "sb $3, 0x0($16)\n"
    ".L00421DB8:\n"
    "addiu $17, $17, -0x1\n"
    "addiu $16, $16, 0x1\n"
    "lw $2, 0x0($29)\n"
    "addiu $2, $2, 0x1\n"
    ".word 0x04410008 /* bgez $2, .L00421DEC: raw word */\n"
    "sw $2, 0x0($29)\n"
    ".word 0x5E20FFF9 /* bgtzl $17, .L00421DB8: raw word */\n"
    "sb $3, 0x0($16)\n"
    ".word 0x10000005 /* b .L00421DF0: raw word */\n"
    "lb $2, 0x0($5)\n"
    ".L00421DE0:\n"
    "addiu $5, $5, 0x1\n"
    "addiu $16, $16, 0x1\n"
    "addiu $17, $17, -0x1\n"
    ".L00421DEC:\n"
    "lb $2, 0x0($5)\n"
    ".L00421DF0:\n"
    ".word 0x10400003 /* beqz $2, .L00421E00: raw word */\n"
    "lbu $3, 0x0($5)\n"
    ".word 0x5E20FFF9 /* bgtzl $17, .L00421DE0: raw word */\n"
    "sb $3, 0x0($16)\n"
    ".L00421E00:\n"
    ".word 0x52C0000B /* beql $22, $0, .L00421E30: raw word */\n"
    "sb $0, 0x0($16)\n"
    ".word 0x1A200008 /* blez $17, .L00421E2C: raw word */\n"
    "addiu $2, $0, 0x30\n"
    ".L00421E10:\n"
    "sb $2, 0x0($16)\n"
    "addiu $17, $17, -0x1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x1E20FFFA /* bgtz $17, .L00421E10: raw word */\n"
    "addiu $16, $16, 0x1\n"
    ".L00421E2C:\n"
    "sb $0, 0x0($16)\n"
    ".L00421E30:\n"
    "daddu $2, $21, $0\n"
    ".L00421E34:\n"
    "lq $16, 0x90($29)\n"
    "lq $17, 0x80($29)\n"
    "lq $18, 0x70($29)\n"
    "lq $19, 0x60($29)\n"
    "lq $20, 0x50($29)\n"
    "lq $21, 0x40($29)\n"
    "lq $22, 0x30($29)\n"
    "lq $23, 0x20($29)\n"
    "ld $31, 0x10($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0xA0\n"
    ".end func_00421B98\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421E60);
#ifdef SKIP_ASM
extern void func_00421530_f(int, char *, long, int, int, int, int) __asm__("func_00421530");
extern void func_00421B98_g(int, long, int, char *, int, int) __asm__("func_00421B98");
extern void func_004216E8_e(int, char *, long, int, int, int) __asm__("func_004216E8");
char *func_00421E60(int ep, char *buf, long val, int nd, int unused, char fmt, int pad) {
    switch (fmt) {
    case 'f':
    case 'F':
        func_00421530_f(ep, buf, val, nd, fmt, nd ? 1 : pad, 3);
        break;
    case 'g':
    case 'G':
        func_00421B98_g(ep, val, nd ? nd : 1, buf, fmt, pad);
        break;
    case 'e':
    case 'E':
        func_004216E8_e(ep, buf, val, nd, fmt, pad);
        break;
    }
    return buf;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00421F20);
#ifdef SKIP_ASM
extern void func_00418CA8_lock(int) __asm__("func_00418CA8");
extern void func_00418D08_unlock(int) __asm__("func_00418D08");
extern void *func_0041DBF8_malloc(int, int) __asm__("func_0041DBF8");
extern void func_0041E340_free(int, void *) __asm__("func_0041E340");
extern void *func_0041605C_memcpy(void *, void *, unsigned) __asm__("func_0041605C");
#define MALLOC_COPY(dest, src, nbytes)     do {         unsigned mcn = (nbytes);         if (mcn < 37) {             unsigned *mcsrc = (unsigned *)(src);             unsigned *mcdst = (unsigned *)(dest);             if (mcn >= 20) {                 *mcdst++ = *mcsrc++;                 *mcdst++ = *mcsrc++;                 if (mcn >= 28) {                     *mcdst++ = *mcsrc++;                     *mcdst++ = *mcsrc++;                     if (mcn >= 36) {                         *mcdst++ = *mcsrc++;                         *mcdst++ = *mcsrc++;                     }                 }             }             *mcdst++ = *mcsrc++;             *mcdst++ = *mcsrc++;             *mcdst = *mcsrc;         } else             func_0041605C_memcpy(dest, src, mcn);     } while (0)
#define inuse(p) (chunk_at_offset(p, (p)->size & ~1u)->size & 1)
void *func_00421F20_(int ptr, void *oldmem, unsigned bytes) __asm__("func_00421F20");
void *func_00421F20_(int ptr, void *oldmem, unsigned bytes) {
    unsigned nb, oldsize, newsize, nextsize, prevsize, remainder_size;
    mchunkptr oldp, newp, next, prev, remainder, bck, fwd;
    void *newmem;
    if (oldmem == 0)
        return func_0041DBF8_malloc(ptr, bytes);
    func_00418CA8_lock(ptr);
    newp = oldp = (mchunkptr)((char *)oldmem - 8);
    newsize = oldsize = chunksize(oldp);
    nb = (bytes + 19 < 31) ? 16 : ((bytes + 19) & ~15u);
    if (oldsize < nb) {
        next = chunk_at_offset(oldp, oldsize);
        if (next == top || !inuse(next)) {
            nextsize = chunksize(next);
            if (next == top) {
                if (nextsize + newsize >= nb + 16) {
                    newsize += nextsize;
                    top = chunk_at_offset(oldp, nb);
                    set_head(top, (newsize - nb) | 1);
                    set_head_size(oldp, nb);
                    func_00418D08_unlock(ptr);
                    return (char *)oldp + 8;
                }
            } else if (nextsize + newsize >= nb) {
                unlink(next, bck, fwd);
                newsize += nextsize;
                goto split;
            }
        } else {
            next = 0;
            nextsize = 0;
        }
        if (!(oldp->size & 1)) {
            prev = chunk_at_offset(oldp, -(int)oldp->prev_size);
            prevsize = chunksize(prev);
            if (next != 0) {
                if (next == top) {
                    if (nextsize + prevsize + newsize >= nb + 16) {
                        unlink(prev, bck, fwd);
                        newp = prev;
                        newsize += prevsize + nextsize;
                        newmem = (char *)newp + 8;
                        MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                        top = chunk_at_offset(newp, nb);
                        set_head(top, (newsize - nb) | 1);
                        set_head_size(newp, nb);
                        func_00418D08_unlock(ptr);
                        return newmem;
                    }
                } else if (nextsize + prevsize + newsize >= nb) {
                    unlink(next, bck, fwd);
                    unlink(prev, bck, fwd);
                    newp = prev;
                    newsize += nextsize + prevsize;
                    newmem = (char *)newp + 8;
                    MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                    goto split;
                }
            }
            if (prev != 0 && prevsize + newsize >= nb) {
                unlink(prev, bck, fwd);
                newp = prev;
                newsize += prevsize;
                newmem = (char *)newp + 8;
                MALLOC_COPY((char *)newp + 8, oldmem, oldsize - 4);
                goto split;
            }
        }
        newmem = func_0041DBF8_malloc(ptr, bytes);
        if (newmem == 0) {
            func_00418D08_unlock(ptr);
            return 0;
        }
        if ((newp = (mchunkptr)((char *)newmem - 8)) == chunk_at_offset(oldp, oldp->size & ~1u)) {
            newsize += chunksize(newp);
            newp = oldp;
            goto split;
        }
        MALLOC_COPY(newmem, oldmem, oldsize - 4);
        func_0041E340_free(ptr, oldmem);
        func_00418D08_unlock(ptr);
        return newmem;
    }
split:
    if (newsize - nb >= 16) {
        remainder = chunk_at_offset(newp, nb);
        remainder_size = newsize - nb;
        set_head_size(newp, nb);
        set_head(remainder, remainder_size | 1);
        chunk_at_offset(remainder, remainder_size)->size |= 1;
        func_0041E340_free(ptr, (char *)remainder + 8);
    } else {
        set_head_size(newp, newsize);
        chunk_at_offset(newp, newsize)->size |= 1;
    }
    func_00418D08_unlock(ptr);
    return (char *)newp + 8;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004224A0);
#ifdef SKIP_ASM
extern void *func_0041DBF8_malloc(int, int) __asm__("func_0041DBF8");
extern void *func_00416210_memset(void *, int, unsigned) __asm__("func_00416210");
#define MALLOC_ZERO(charp, nbytes)     do {         unsigned mctmp = (nbytes);         if (mctmp < 37) {             unsigned *mzp = (unsigned *)(charp);             if (mctmp >= 20) {                 *mzp++ = 0;                 *mzp++ = 0;                 if (mctmp >= 28) {                     *mzp++ = 0;                     *mzp++ = 0;                     if (mctmp >= 36) {                         *mzp++ = 0;                         *mzp++ = 0;                     }                 }             }             *mzp++ = 0;             *mzp++ = 0;             *mzp = 0;         } else             func_00416210_memset(charp, 0, mctmp);     } while (0)
void *func_004224A0_(int ptr, int n, int elem_size) __asm__("func_004224A0");
void *func_004224A0_(int ptr, int n, int elem_size) {
    mchunkptr p;
    unsigned csz;
    unsigned sz = n * elem_size;
    void *mem;
    mem = func_0041DBF8_malloc(ptr, sz);
    if (mem == 0)
        return 0;
    p = (mchunkptr)((char *)mem - 8);
    csz = chunksize(p);
    MALLOC_ZERO(mem, csz - 4);
    return mem;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00422560);
#ifdef SKIP_ASM
extern int func_00420E28_cmp(struct Bigint *, struct Bigint *) __asm__("func_00420E28");
int func_00422560(struct Bigint *b, struct Bigint *S) {
    int n;
    int borrow, y;
    unsigned carry, q, ys;
    unsigned *bx, *bxe, *sx, *sxe;
    int z;
    unsigned si, zs;
    n = S->wds;
    if (b->wds < n)
        return 0;
    sx = S->x;
    sxe = sx + --n;
    bx = b->x;
    bxe = bx + n;
    q = *bxe / (*sxe + 1);
    if (q) {
        borrow = 0;
        carry = 0;
        do {
            si = *sx++;
            ys = (si & 0xffff) * q + carry;
            zs = (si >> 16) * q + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((unsigned short *)bx)[1] = (unsigned short)z;
            ((unsigned short *)bx)[0] = (unsigned short)y;
            bx++;
        } while (sx <= sxe);
        if (!*bxe) {
            bx = b->x;
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    if (func_00420E28_cmp(b, S) >= 0) {
        q++;
        borrow = 0;
        carry = 0;
        bx = b->x;
        sx = S->x;
        do {
            si = *sx++;
            ys = (si & 0xffff) + carry;
            zs = (si >> 16) + (ys >> 16);
            carry = zs >> 16;
            y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
            borrow = y >> 16;
            z = (*bx >> 16) - (zs & 0xffff) + borrow;
            borrow = z >> 16;
            ((unsigned short *)bx)[1] = (unsigned short)z;
            ((unsigned short *)bx)[0] = (unsigned short)y;
            bx++;
        } while (sx <= sxe);
        bx = b->x;
        bxe = bx + n;
        if (!*bxe) {
            while (--bxe > bx && !*bxe)
                --n;
            b->wds = n;
        }
    }
    return q;
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00422780);
#ifdef SKIP_ASM
// PORT: PS2-only newlib C library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00422780\n.ent func_00422780\nfunc_00422780:\n"
    "addiu $29, $29, -0x100\n"
    "sq $16, 0xF0($29)\n"
    "sq $19, 0xC0($29)\n"
    "daddu $16, $9, $0\n"
    "sq $23, 0x80($29)\n"
    "daddu $19, $5, $0\n"
    "sq $17, 0xE0($29)\n"
    "daddu $23, $4, $0\n"
    "sq $18, 0xD0($29)\n"
    "sq $20, 0xB0($29)\n"
    "sq $21, 0xA0($29)\n"
    "sq $22, 0x90($29)\n"
    "sq $30, 0x70($29)\n"
    "sd $31, 0x60($29)\n"
    "sw $6, 0x8($29)\n"
    "lw $3, 0x40($23)\n"
    "sw $7, 0xC($29)\n"
    "sw $8, 0x10($29)\n"
    ".word 0x1060000B /* beqz $3, .L004227F8: raw word */\n"
    "sw $10, 0x14($29)\n"
    "lw $5, 0x44($23)\n"
    "addiu $2, $0, 0x1\n"
    "sw $5, 0x4($3)\n"
    "lw $3, 0x44($23)\n"
    "lw $5, 0x40($23)\n"
    "sllv $2, $2, $3\n"
    "sw $2, 0x8($5)\n"
    "jal func_004205B8\n"
    "lw $5, 0x40($23)\n"
    "sw $0, 0x40($23)\n"
    ".L004227F8:\n"
    "dsra32 $4, $19, 0\n"
    ".word 0x0483000B /* bgezl $4, .L0042282C: raw word */\n"
    "sw $0, 0x0($16)\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "addiu $3, $0, -0x1\n"
    "dsrl32 $3, $3, 0\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "and $19, $19, $3\n"
    "and $2, $4, $2\n"
    "addiu $3, $0, 0x1\n"
    "dsll32 $2, $2, 0\n"
    "sw $3, 0x0($16)\n"
    "or $19, $19, $2\n"
    ".L0042282C:\n"
    "dsra32 $16, $19, 0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "and $2, $16, $3\n"
    ".word 0x14430016 /* bne $2, $3, .L00422894: raw word */\n"
    "daddu $4, $19, $0\n"
    "lw $4, 0x10($29)\n"
    "addiu $3, $0, 0x270F\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $19, $2\n"
    ".word 0x14400004 /* bnez $2, .L00422868: raw word */\n"
    "sw $3, 0x0($4)\n"
    "lui $2, %hi(D_0049AAA0)\n"
    ".word 0x10000003 /* b .L00422870: raw word */\n"
    "addiu $21, $2, %lo(D_0049AAA0)\n"
    ".L00422868:\n"
    "lui $2, %hi(D_0049AAB0)\n"
    "addiu $21, $2, %lo(D_0049AAB0)\n"
    ".L00422870:\n"
    "lw $2, 0x14($29)\n"
    ".word 0x10400015 /* beqz $2, .L004228CC: raw word */\n"
    "addiu $4, $21, 0x8\n"
    "lb $2, 0x3($21)\n"
    "addiu $3, $21, 0x3\n"
    "movn $3, $4, $2\n"
    "lw $4, 0x14($29)\n"
    ".word 0x1000000F /* b .L004228CC: raw word */\n"
    "sw $3, 0x0($4)\n"
    ".L00422894:\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x1440000D /* bnez $2, .L004228D4: raw word */\n"
    "daddu $4, $23, $0\n"
    "lw $4, 0x10($29)\n"
    "addiu $2, $0, 0x1\n"
    "lui $3, %hi(D_0049AAB8)\n"
    "sw $2, 0x0($4)\n"
    "lw $2, 0x14($29)\n"
    ".word 0x10400004 /* beqz $2, .L004228CC: raw word */\n"
    "addiu $21, $3, %lo(D_0049AAB8)\n"
    "lw $3, 0x14($29)\n"
    "addiu $2, $21, 0x1\n"
    "sw $2, 0x0($3)\n"
    ".L004228CC:\n"
    ".word 0x10000419 /* b .L00423934: raw word */\n"
    "daddu $2, $21, $0\n"
    ".L004228D4:\n"
    "daddu $5, $19, $0\n"
    "daddu $6, $29, $0\n"
    "jal func_00421280\n"
    "ori $7, $29, 0x4\n"
    "srl $3, $16, 20\n"
    "andi $20, $3, 0x7FF\n"
    ".word 0x12800015 /* beqz $20, .L00422944: raw word */\n"
    "sw $2, 0x48($29)\n"
    "daddu $22, $19, $0\n"
    "lui $2, (0xFFFFF >> 16)\n"
    "dsra32 $3, $22, 0\n"
    "ori $2, $2, (0xFFFFF & 0xFFFF)\n"
    "and $3, $3, $2\n"
    "addiu $5, $0, -0x1\n"
    "dsrl32 $5, $5, 0\n"
    "dsll32 $3, $3, 0\n"
    "and $22, $22, $5\n"
    "or $22, $22, $3\n"
    "lui $4, (0x3FF00000 >> 16)\n"
    "dsra32 $2, $22, 0\n"
    "addiu $20, $20, -0x3FF\n"
    "or $2, $2, $4\n"
    "and $22, $22, $5\n"
    "dsll32 $2, $2, 0\n"
    "sw $0, 0x44($29)\n"
    "or $22, $22, $2\n"
    ".word 0x10000030 /* b .L00422A00: raw word */\n"
    "lw $17, 0x4($29)\n"
    ".L00422944:\n"
    "lw $2, 0x4($29)\n"
    "lw $3, 0x0($29)\n"
    "daddu $17, $2, $0\n"
    "addu $3, $2, $3\n"
    "addiu $20, $3, 0x432\n"
    "slti $2, $20, 0x21\n"
    ".word 0x5440000B /* bnel $2, $0, .L0042298C: raw word */\n"
    "negu $3, $20\n"
    "addiu $2, $3, 0x412\n"
    "dsll32 $4, $19, 0\n"
    "dsra32 $4, $4, 0\n"
    "negu $3, $20\n"
    "srlv $4, $4, $2\n"
    "sllv $3, $16, $3\n"
    "or $3, $3, $4\n"
    "dsll32 $3, $3, 0\n"
    ".word 0x10000006 /* b .L004229A0: raw word */\n"
    "dsrl32 $4, $3, 0\n"
    ".L0042298C:\n"
    "dsll32 $2, $19, 0\n"
    "dsra32 $2, $2, 0\n"
    "sllv $2, $2, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $4, $2, 0\n"
    ".L004229A0:\n"
    ".word 0x04800005 /* bltz $4, .L004229B8: raw word */\n"
    "dsrl $2, $4, 1\n"
    "jal func_00411438\n"
    "nop\n"
    ".word 0x10000008 /* b .L004229D4: raw word */\n"
    "daddu $22, $2, $0\n"
    ".L004229B8:\n"
    "andi $4, $4, 0x1\n"
    "jal func_00411438\n"
    "or $4, $4, $2\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    "daddu $22, $2, $0\n"
    ".L004229D4:\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "dsra32 $3, $22, 0\n"
    "lui $2, (0xFE100000 >> 16)\n"
    "and $22, $22, $4\n"
    "addu $3, $3, $2\n"
    "addiu $4, $0, 0x1\n"
    "dsll32 $3, $3, 0\n"
    "sw $4, 0x44($29)\n"
    "addiu $20, $20, -0x433\n"
    "or $22, $22, $3\n"
    ".L00422A00:\n"
    "ori $5, $0, 0xFFE0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411F70\n"
    "daddu $4, $22, $0\n"
    "ori $5, $0, 0xFF4A\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0xF4EC\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xDBD0\n"
    "dsll $5, $5, 10\n"
    "ori $5, $5, 0x361\n"
    "jal func_00411FD8\n"
    "daddu $4, $2, $0\n"
    "ori $5, $0, 0xFF1A\n"
    "dsll $5, $5, 18\n"
    "ori $5, $5, 0xA288\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xB60C\n"
    "dsll $5, $5, 12\n"
    "ori $5, $5, 0x8B3\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $16, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $20, $0\n"
    "ori $5, $0, 0xFF4D\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0x826A\n"
    "dsll $5, $5, 19\n"
    "ori $5, $5, 0x9F79\n"
    "dsll $5, $5, 8\n"
    "ori $5, $5, 0xFB\n"
    "jal func_00411FD8\n"
    "daddu $4, $2, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $16, $0\n"
    "daddu $18, $2, $0\n"
    "jal func_00412608\n"
    "daddu $4, $18, $0\n"
    "daddu $30, $2, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    ".word 0x04410009 /* bgez $2, .L00422AD8: raw word */\n"
    "addiu $2, $0, 0x1\n"
    "jal func_00412550\n"
    "daddu $4, $30, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $2, $0\n"
    "addiu $3, $30, -0x1\n"
    "movn $30, $3, $2\n"
    "addiu $2, $0, 0x1\n"
    ".L00422AD8:\n"
    "sw $2, 0x30($29)\n"
    "sltiu $2, $30, 0x17\n"
    ".word 0x1040000C /* beqz $2, .L00422B14: raw word */\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $30, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $4, $19, $0\n"
    "addu $3, $3, $2\n"
    "sw $0, 0x30($29)\n"
    "jal func_00412500\n"
    "ld $5, 0x0($3)\n"
    "addiu $3, $0, -0x1\n"
    "addiu $4, $30, -0x1\n"
    "slt $3, $3, $2\n"
    "movz $30, $4, $3\n"
    ".L00422B14:\n"
    "subu $2, $17, $20\n"
    "addiu $16, $2, -0x1\n"
    ".word 0x06020004 /* bltzl $16, .L00422B30: raw word */\n"
    "negu $16, $16\n"
    "sw $16, 0x38($29)\n"
    ".word 0x10000003 /* b .L00422B38: raw word */\n"
    "sw $0, 0x18($29)\n"
    ".L00422B30:\n"
    "sw $0, 0x38($29)\n"
    "sw $16, 0x18($29)\n"
    ".L00422B38:\n"
    ".word 0x07C00006 /* bltz $30, .L00422B54: raw word */\n"
    "lw $3, 0x38($29)\n"
    "sw $0, 0x1C($29)\n"
    "addu $3, $3, $30\n"
    "sw $30, 0x3C($29)\n"
    ".word 0x10000007 /* b .L00422B6C: raw word */\n"
    "sw $3, 0x38($29)\n"
    ".L00422B54:\n"
    "lw $4, 0x18($29)\n"
    "negu $2, $30\n"
    "sw $2, 0x1C($29)\n"
    "subu $4, $4, $30\n"
    "sw $0, 0x3C($29)\n"
    "sw $4, 0x18($29)\n"
    ".L00422B6C:\n"
    "lw $4, 0x8($29)\n"
    "addiu $18, $0, 0x1\n"
    "sltiu $3, $4, 0xA\n"
    "movz $4, $0, $3\n"
    "slti $2, $4, 0x6\n"
    ".word 0x14400004 /* bnez $2, .L00422B94: raw word */\n"
    "sw $4, 0x8($29)\n"
    "addiu $4, $4, -0x4\n"
    "daddu $18, $0, $0\n"
    "sw $4, 0x8($29)\n"
    ".L00422B94:\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x8($29)\n"
    "sw $2, 0x34($29)\n"
    "sltiu $2, $3, 0x6\n"
    ".word 0x1040001F /* beqz $2, .L00422C24: raw word */\n"
    "lui $2, %hi(jtbl_0049AAC0)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049AAC0)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    ".globl lbl_00422BC4\n"
    "lbl_00422BC4:\n"
    ".Llbl_00422BC4:\n"
    "addiu $4, $0, -0x1\n"
    "addiu $20, $0, 0x12\n"
    "sw $4, 0x28($29)\n"
    "sw $4, 0x20($29)\n"
    ".word 0x10000013 /* b .L00422C24: raw word */\n"
    "sw $0, 0xC($29)\n"
    ".globl lbl_00422BDC\n"
    "lbl_00422BDC:\n"
    ".Llbl_00422BDC:\n"
    "sw $0, 0x34($29)\n"
    ".globl lbl_00422BE0\n"
    "lbl_00422BE0:\n"
    ".Llbl_00422BE0:\n"
    "lw $3, 0xC($29)\n"
    "addiu $20, $0, 0x1\n"
    "slt $2, $0, $3\n"
    "movn $20, $3, $2\n"
    "sw $20, 0xC($29)\n"
    "sw $20, 0x28($29)\n"
    ".word 0x1000000A /* b .L00422C24: raw word */\n"
    "sw $20, 0x20($29)\n"
    ".globl lbl_00422C00\n"
    "lbl_00422C00:\n"
    ".Llbl_00422C00:\n"
    "sw $0, 0x34($29)\n"
    ".globl lbl_00422C04\n"
    "lbl_00422C04:\n"
    ".Llbl_00422C04:\n"
    "lw $4, 0xC($29)\n"
    "addiu $3, $0, 0x1\n"
    "addu $2, $4, $30\n"
    "addiu $20, $2, 0x1\n"
    "sw $2, 0x28($29)\n"
    "sw $20, 0x20($29)\n"
    "slt $2, $0, $20\n"
    "movz $20, $3, $2\n"
    ".L00422C24:\n"
    "sw $0, 0x44($23)\n"
    "addiu $16, $0, 0x4\n"
    "sltiu $2, $20, 0x18\n"
    "lw $3, 0x20($29)\n"
    ".word 0x1440000A /* bnez $2, .L00422C60: raw word */\n"
    "sltiu $17, $3, 0xF\n"
    "daddu $3, $0, $0\n"
    ".L00422C40:\n"
    "sll $16, $16, 1\n"
    "addiu $2, $16, 0x14\n"
    "sltu $2, $20, $2\n"
    "nop\n"
    "nop\n"
    ".word 0x1040FFFA /* beqz $2, .L00422C40: raw word */\n"
    "addiu $3, $3, 0x1\n"
    "sw $3, 0x44($23)\n"
    ".L00422C60:\n"
    "lw $5, 0x44($23)\n"
    "jal func_00420510\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x58($29)\n"
    "sw $2, 0x40($23)\n"
    ".word 0x12200101 /* beqz $17, .L0042307C: raw word */\n"
    "lw $21, 0x58($29)\n"
    ".word 0x124000FF /* beqz $18, .L0042307C: raw word */\n"
    "lw $4, 0x20($29)\n"
    "daddu $22, $19, $0\n"
    "sw $30, 0x2C($29)\n"
    "addiu $20, $0, 0x2\n"
    ".word 0x1BC00024 /* blez $30, .L00422D24: raw word */\n"
    "sw $4, 0x24($29)\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "andi $3, $30, 0xF\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "sll $3, $3, 3\n"
    "addu $3, $3, $2\n"
    "sra $16, $30, 4\n"
    "andi $2, $16, 0x10\n"
    ".word 0x10400008 /* beqz $2, .L00422CD8: raw word */\n"
    "ld $18, 0x0($3)\n"
    "lui $2, %hi(D_0049A9E0)\n"
    "daddu $4, $19, $0\n"
    "ld $5, %lo(D_0049A9E0)($2)\n"
    "andi $16, $16, 0xF\n"
    "jal func_00412280\n"
    "addiu $20, $0, 0x3\n"
    "daddu $19, $2, $0\n"
    ".L00422CD8:\n"
    ".word 0x1200000D /* beqz $16, .L00422D10: raw word */\n"
    "lui $2, %hi(D_0049A9C0)\n"
    "addiu $17, $2, %lo(D_0049A9C0)\n"
    "nop\n"
    ".L00422CE8:\n"
    "andi $2, $16, 0x1\n"
    ".word 0x10400005 /* beqz $2, .L00422D04: raw word */\n"
    "daddu $4, $18, $0\n"
    "ld $5, 0x0($17)\n"
    "jal func_00411FD8\n"
    "addiu $20, $20, 0x1\n"
    "daddu $18, $2, $0\n"
    ".L00422D04:\n"
    "sra $16, $16, 1\n"
    ".word 0x1600FFF7 /* bnez $16, .L00422CE8: raw word */\n"
    "addiu $17, $17, 0x8\n"
    ".L00422D10:\n"
    "daddu $4, $19, $0\n"
    "jal func_00412280\n"
    "daddu $5, $18, $0\n"
    ".word 0x1000001A /* b .L00422D88: raw word */\n"
    "daddu $19, $2, $0\n"
    ".L00422D24:\n"
    "negu $17, $30\n"
    ".word 0x12200017 /* beqz $17, .L00422D88: raw word */\n"
    "lui $3, %hi(D_0049A8F8)\n"
    "andi $2, $17, 0xF\n"
    "addiu $3, $3, %lo(D_0049A8F8)\n"
    "sll $2, $2, 3\n"
    "addu $2, $2, $3\n"
    "daddu $5, $19, $0\n"
    "ld $4, 0x0($2)\n"
    "jal func_00411FD8\n"
    "sra $16, $17, 4\n"
    ".word 0x1200000D /* beqz $16, .L00422D88: raw word */\n"
    "daddu $19, $2, $0\n"
    "lui $2, %hi(D_0049A9C0)\n"
    "addiu $17, $2, %lo(D_0049A9C0)\n"
    ".L00422D60:\n"
    "andi $2, $16, 0x1\n"
    ".word 0x10400005 /* beqz $2, .L00422D7C: raw word */\n"
    "daddu $5, $19, $0\n"
    "ld $4, 0x0($17)\n"
    "jal func_00411FD8\n"
    "addiu $20, $20, 0x1\n"
    "daddu $19, $2, $0\n"
    ".L00422D7C:\n"
    "sra $16, $16, 1\n"
    ".word 0x1600FFF7 /* bnez $16, .L00422D60: raw word */\n"
    "addiu $17, $17, 0x8\n"
    ".L00422D88:\n"
    "lw $2, 0x30($29)\n"
    ".word 0x10400014 /* beqz $2, .L00422DE0: raw word */\n"
    "nop\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $19, $0\n"
    ".word 0x0441000E /* bgez $2, .L00422DE0: raw word */\n"
    "lw $3, 0x20($29)\n"
    ".word 0x1860000C /* blez $3, .L00422DE0: raw word */\n"
    "nop\n"
    "lw $4, 0x28($29)\n"
    ".word 0x188000AB /* blez $4, .L00423068: raw word */\n"
    "lw $2, 0x28($29)\n"
    "daddu $5, $19, $0\n"
    "ori $4, $0, 0x8048\n"
    "dsll32 $4, $4, 15\n"
    "addiu $30, $30, -0x1\n"
    "sw $2, 0x20($29)\n"
    "jal func_00411FD8\n"
    "addiu $20, $20, 0x1\n"
    "daddu $19, $2, $0\n"
    ".L00422DE0:\n"
    "jal func_00412550\n"
    "daddu $4, $20, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $19, $0\n"
    "ori $5, $0, 0x8038\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $18, $2, $0\n"
    "addiu $4, $0, -0x1\n"
    "dsrl32 $4, $4, 0\n"
    "dsra32 $3, $18, 0\n"
    "lui $2, (0xFCC00000 >> 16)\n"
    "addu $3, $3, $2\n"
    "and $18, $18, $4\n"
    "dsll32 $3, $3, 0\n"
    "or $18, $18, $3\n"
    "lw $3, 0x20($29)\n"
    ".word 0x54600017 /* bnel $3, $0, .L00422E8C: raw word */\n"
    "lw $4, 0x34($29)\n"
    "ori $5, $0, 0x8028\n"
    "dsll32 $5, $5, 15\n"
    "daddu $4, $19, $0\n"
    "sw $0, 0x50($29)\n"
    "jal func_00411F70\n"
    "sw $0, 0x54($29)\n"
    "daddu $16, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x1C4001C2 /* bgtz $2, .L00423568: raw word */\n"
    "lw $3, 0x58($29)\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00412500\n"
    "daddu $5, $2, $0\n"
    ".word 0x044001B7 /* bltz $2, .L0042355C: raw word */\n"
    "lw $3, 0x24($29)\n"
    ".word 0x1000007A /* b .L00423070: raw word */\n"
    "daddu $19, $22, $0\n"
    ".L00422E8C:\n"
    ".word 0x1080003A /* beqz $4, .L00422F78: raw word */\n"
    "lui $3, %hi(D_0049A8F8)\n"
    "lw $4, 0x20($29)\n"
    "addiu $3, $3, %lo(D_0049A8F8)\n"
    "daddu $20, $0, $0\n"
    "addiu $2, $4, -0x1\n"
    "sll $2, $2, 3\n"
    "ori $4, $0, 0xFF80\n"
    "dsll32 $4, $4, 14\n"
    "addu $2, $2, $3\n"
    "jal func_00412280\n"
    "ld $5, 0x0($2)\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $2, $0\n"
    ".word 0x1000000B /* b .L00422EF8: raw word */\n"
    "daddu $18, $2, $0\n"
    ".L00422ED0:\n"
    "ori $4, $0, 0x8048\n"
    "dsll32 $4, $4, 15\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "ori $4, $0, 0x8048\n"
    "dsll32 $4, $4, 15\n"
    "daddu $18, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $16, $0\n"
    "daddu $19, $2, $0\n"
    ".L00422EF8:\n"
    "jal func_00412608\n"
    "daddu $4, $19, $0\n"
    "daddu $17, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $16, $2, $0\n"
    "daddu $5, $18, $0\n"
    "addiu $2, $17, 0x30\n"
    "daddu $4, $16, $0\n"
    "sb $2, 0x0($21)\n"
    "jal func_00412500\n"
    "addiu $21, $21, 0x1\n"
    ".word 0x04400275 /* bltz $2, .L0042390C: raw word */\n"
    "lw $5, 0x48($29)\n"
    "ori $4, $0, 0xFFC0\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $16, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $5, $18, $0\n"
    ".word 0x04400088 /* bltz $2, .L0042317C: raw word */\n"
    "lw $3, 0x20($29)\n"
    "addiu $20, $20, 0x1\n"
    "slt $2, $20, $3\n"
    ".word 0x1440FFD9 /* bnez $2, .L00422ED0: raw word */\n"
    "lw $3, 0x24($29)\n"
    ".word 0x1000003F /* b .L00423070: raw word */\n"
    "daddu $19, $22, $0\n"
    ".L00422F78:\n"
    "lw $4, 0x20($29)\n"
    "addiu $3, $3, %lo(D_0049A8F8)\n"
    "daddu $5, $18, $0\n"
    "addiu $2, $4, -0x1\n"
    "addiu $20, $0, 0x1\n"
    "sll $2, $2, 3\n"
    "addu $2, $2, $3\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($2)\n"
    "daddu $18, $2, $0\n"
    ".L00422FA0:\n"
    "jal func_00412608\n"
    "daddu $4, $19, $0\n"
    "daddu $17, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "daddu $16, $2, $0\n"
    "addiu $2, $17, 0x30\n"
    "sb $2, 0x0($21)\n"
    "lw $2, 0x20($29)\n"
    ".word 0x1682001E /* bne $20, $2, .L0042304C: raw word */\n"
    "addiu $21, $21, 0x1\n"
    "ori $4, $0, 0xFF80\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F18\n"
    "daddu $5, $18, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x1C400062 /* bgtz $2, .L00423180: raw word */\n"
    "addiu $3, $0, 0x39\n"
    "ori $4, $0, 0xFF80\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $18, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00412500\n"
    "daddu $5, $2, $0\n"
    ".word 0x04410013 /* bgez $2, .L00423068: raw word */\n"
    "addiu $3, $0, 0x30\n"
    "addiu $21, $21, -0x1\n"
    "nop\n"
    ".L00423028:\n"
    "lb $2, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5043FFFA /* beql $2, $3, .L00423028: raw word */\n"
    "addiu $21, $21, -0x1\n"
    ".word 0x10000230 /* b .L00423908: raw word */\n"
    "addiu $21, $21, 0x1\n"
    ".L0042304C:\n"
    "ori $4, $0, 0x8048\n"
    "dsll32 $4, $4, 15\n"
    "daddu $5, $16, $0\n"
    "jal func_00411FD8\n"
    "addiu $20, $20, 0x1\n"
    ".word 0x1000FFCF /* b .L00422FA0: raw word */\n"
    "daddu $19, $2, $0\n"
    ".L00423068:\n"
    "lw $3, 0x24($29)\n"
    "daddu $19, $22, $0\n"
    ".L00423070:\n"
    "lw $30, 0x2C($29)\n"
    "sw $3, 0x20($29)\n"
    "lw $21, 0x58($29)\n"
    ".L0042307C:\n"
    "lw $3, 0x0($29)\n"
    ".word 0x0460005B /* bltz $3, .L004231F0: raw word */\n"
    "slti $2, $30, 0xF\n"
    ".word 0x10400059 /* beqz $2, .L004231F0: raw word */\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $30, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "lw $4, 0xC($29)\n"
    "addu $3, $3, $2\n"
    ".word 0x04810012 /* bgez $4, .L004230EC: raw word */\n"
    "ld $18, 0x0($3)\n"
    "lw $2, 0x20($29)\n"
    ".word 0x1C400010 /* bgtz $2, .L004230F0: raw word */\n"
    "addiu $20, $0, 0x1\n"
    "sw $0, 0x50($29)\n"
    ".word 0x04400128 /* bltz $2, .L0042355C: raw word */\n"
    "sw $0, 0x54($29)\n"
    "ori $5, $0, 0x8028\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "daddu $4, $19, $0\n"
    "jal func_00412500\n"
    "daddu $5, $2, $0\n"
    ".word 0x1840011F /* blez $2, .L0042355C: raw word */\n"
    "lw $3, 0x58($29)\n"
    ".word 0x10000121 /* b .L0042356C: raw word */\n"
    "addiu $2, $0, 0x31\n"
    ".L004230EC:\n"
    "addiu $20, $0, 0x1\n"
    ".L004230F0:\n"
    "daddu $5, $18, $0\n"
    ".L004230F4:\n"
    "jal func_00412280\n"
    "daddu $4, $19, $0\n"
    "jal func_00412608\n"
    "daddu $4, $2, $0\n"
    "daddu $17, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $18, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $19, $0\n"
    "daddu $5, $2, $0\n"
    "addiu $2, $17, 0x30\n"
    "sb $2, 0x0($21)\n"
    "lw $3, 0x20($29)\n"
    ".word 0x16830021 /* bne $20, $3, .L004231C0: raw word */\n"
    "addiu $21, $21, 0x1\n"
    "jal func_00411F18\n"
    "daddu $4, $5, $0\n"
    "daddu $16, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    ".word 0x1C400009 /* bgtz $2, .L00423180: raw word */\n"
    "addiu $3, $0, 0x39\n"
    "daddu $4, $16, $0\n"
    "jal func_00412500\n"
    "daddu $5, $18, $0\n"
    ".word 0x144001E6 /* bnez $2, .L00423908: raw word */\n"
    "andi $2, $17, 0x1\n"
    ".word 0x504001E5 /* beql $2, $0, .L0042390C: raw word */\n"
    "lw $5, 0x48($29)\n"
    ".L0042317C:\n"
    "addiu $3, $0, 0x39\n"
    ".L00423180:\n"
    "addiu $4, $0, 0x30\n"
    "addiu $21, $21, -0x1\n"
    ".L00423188:\n"
    "lb $2, 0x0($21)\n"
    ".word 0x14430007 /* bne $2, $3, .L004231AC: raw word */\n"
    "lw $2, 0x58($29)\n"
    "nop\n"
    "nop\n"
    ".word 0x56A2FFFA /* bnel $21, $2, .L00423188: raw word */\n"
    "addiu $21, $21, -0x1\n"
    "sb $4, 0x0($2)\n"
    "addiu $30, $30, 0x1\n"
    ".L004231AC:\n"
    "lbu $2, 0x0($21)\n"
    "addiu $2, $2, 0x1\n"
    "sb $2, 0x0($21)\n"
    ".word 0x100001D3 /* b .L00423908: raw word */\n"
    "addiu $21, $21, 0x1\n"
    ".L004231C0:\n"
    "ori $4, $0, 0x8048\n"
    "dsll32 $4, $4, 15\n"
    "jal func_00411FD8\n"
    "nop\n"
    "daddu $5, $0, $0\n"
    "daddu $4, $2, $0\n"
    "jal func_00412500\n"
    "daddu $19, $2, $0\n"
    ".word 0x104001C9 /* beqz $2, .L00423908: raw word */\n"
    "addiu $20, $20, 0x1\n"
    ".word 0x1000FFC2 /* b .L004230F4: raw word */\n"
    "daddu $5, $18, $0\n"
    ".L004231F0:\n"
    "lw $4, 0x8($29)\n"
    "lw $2, 0x34($29)\n"
    "lw $17, 0x18($29)\n"
    "slti $22, $4, 0x2\n"
    "lw $18, 0x1C($29)\n"
    "sw $0, 0x4C($29)\n"
    ".word 0x10400028 /* beqz $2, .L004232AC: raw word */\n"
    "sw $0, 0x50($29)\n"
    ".word 0x12C00007 /* beqz $22, .L00423230: raw word */\n"
    "lw $4, 0x44($29)\n"
    ".word 0x1480001A /* bnez $4, .L00423284: raw word */\n"
    "addiu $20, $3, 0x433\n"
    "lw $3, 0x4($29)\n"
    "addiu $2, $0, 0x36\n"
    ".word 0x10000016 /* b .L00423284: raw word */\n"
    "subu $20, $2, $3\n"
    ".L00423230:\n"
    "lw $2, 0x20($29)\n"
    "lw $3, 0x1C($29)\n"
    "addiu $16, $2, -0x1\n"
    "slt $2, $3, $16\n"
    ".word 0x14400003 /* bnez $2, .L00423250: raw word */\n"
    "lw $4, 0x1C($29)\n"
    ".word 0x10000008 /* b .L0042326C: raw word */\n"
    "subu $18, $3, $16\n"
    ".L00423250:\n"
    "daddu $18, $0, $0\n"
    "lw $2, 0x3C($29)\n"
    "subu $16, $16, $4\n"
    "addu $4, $4, $16\n"
    "addu $2, $2, $16\n"
    "sw $4, 0x1C($29)\n"
    "sw $2, 0x3C($29)\n"
    ".L0042326C:\n"
    "lw $20, 0x20($29)\n"
    ".word 0x06810005 /* bgez $20, .L00423288: raw word */\n"
    "daddu $4, $23, $0\n"
    "lw $3, 0x18($29)\n"
    "subu $17, $3, $20\n"
    "daddu $20, $0, $0\n"
    ".L00423284:\n"
    "daddu $4, $23, $0\n"
    ".L00423288:\n"
    "jal func_00420978\n"
    "addiu $5, $0, 0x1\n"
    "sw $2, 0x50($29)\n"
    "lw $4, 0x38($29)\n"
    "lw $2, 0x18($29)\n"
    "addu $4, $4, $20\n"
    "addu $2, $2, $20\n"
    "sw $4, 0x38($29)\n"
    "sw $2, 0x18($29)\n"
    ".L004232AC:\n"
    ".word 0x1A20000B /* blez $17, .L004232DC: raw word */\n"
    "lw $3, 0x38($29)\n"
    ".word 0x18600009 /* blez $3, .L004232DC: raw word */\n"
    "daddu $20, $3, $0\n"
    "lw $4, 0x18($29)\n"
    "slt $2, $17, $20\n"
    "movn $20, $17, $2\n"
    "subu $3, $3, $20\n"
    "subu $4, $4, $20\n"
    "sw $3, 0x38($29)\n"
    "subu $17, $17, $20\n"
    "sw $4, 0x18($29)\n"
    ".L004232DC:\n"
    "lw $2, 0x1C($29)\n"
    ".word 0x1840001D /* blez $2, .L00423358: raw word */\n"
    "lw $3, 0x34($29)\n"
    ".word 0x50600016 /* beql $3, $0, .L00423344: raw word */\n"
    "lw $5, 0x48($29)\n"
    ".word 0x1A40000D /* blez $18, .L00423328: raw word */\n"
    "lw $5, 0x50($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420BC8\n"
    "daddu $6, $18, $0\n"
    "sw $2, 0x50($29)\n"
    "daddu $4, $23, $0\n"
    "lw $6, 0x48($29)\n"
    "jal func_004209B0\n"
    "daddu $5, $2, $0\n"
    "lw $5, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_004205B8\n"
    "sw $2, 0x48($29)\n"
    ".L00423328:\n"
    "lw $4, 0x1C($29)\n"
    "subu $16, $4, $18\n"
    ".word 0x12000009 /* beqz $16, .L00423358: raw word */\n"
    "lw $5, 0x48($29)\n"
    "daddu $6, $16, $0\n"
    ".word 0x10000003 /* b .L0042334C: raw word */\n"
    "daddu $4, $23, $0\n"
    ".L00423344:\n"
    "daddu $4, $23, $0\n"
    "lw $6, 0x1C($29)\n"
    ".L0042334C:\n"
    "jal func_00420BC8\n"
    "nop\n"
    "sw $2, 0x48($29)\n"
    ".L00423358:\n"
    "daddu $4, $23, $0\n"
    "jal func_00420978\n"
    "addiu $5, $0, 0x1\n"
    "sw $2, 0x54($29)\n"
    "lw $2, 0x3C($29)\n"
    ".word 0x18400005 /* blez $2, .L00423384: raw word */\n"
    "lw $5, 0x54($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420BC8\n"
    "daddu $6, $2, $0\n"
    "sw $2, 0x54($29)\n"
    ".L00423384:\n"
    ".word 0x12C00015 /* beqz $22, .L004233DC: raw word */\n"
    "lw $3, 0x3C($29)\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $19, $2\n"
    ".word 0x5440000F /* bnel $2, $0, .L004233D8: raw word */\n"
    "sw $0, 0x40($29)\n"
    "dsra32 $2, $19, 0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "and $2, $2, $3\n"
    ".word 0x10400009 /* beqz $2, .L004233D4: raw word */\n"
    "lw $3, 0x18($29)\n"
    "addiu $2, $0, 0x1\n"
    "lw $4, 0x38($29)\n"
    "addiu $3, $3, 0x1\n"
    "sw $2, 0x40($29)\n"
    "addiu $4, $4, 0x1\n"
    "sw $3, 0x18($29)\n"
    ".word 0x10000002 /* b .L004233D8: raw word */\n"
    "sw $4, 0x38($29)\n"
    ".L004233D4:\n"
    "sw $0, 0x40($29)\n"
    ".L004233D8:\n"
    "lw $3, 0x3C($29)\n"
    ".L004233DC:\n"
    ".word 0x1060000A /* beqz $3, .L00423408: raw word */\n"
    "lw $4, 0x54($29)\n"
    "lw $2, 0x10($4)\n"
    "addiu $2, $2, -0x1\n"
    "sll $2, $2, 2\n"
    "addu $2, $4, $2\n"
    "jal func_00420830\n"
    "lw $4, 0x14($2)\n"
    "lw $3, 0x38($29)\n"
    ".word 0x10000003 /* b .L00423410: raw word */\n"
    "subu $2, $3, $2\n"
    ".L00423408:\n"
    "lw $4, 0x38($29)\n"
    "addiu $2, $4, 0x1\n"
    ".L00423410:\n"
    "andi $20, $2, 0x1F\n"
    ".word 0x12800002 /* beqz $20, .L00423420: raw word */\n"
    "addiu $2, $0, 0x20\n"
    "subu $20, $2, $20\n"
    ".L00423420:\n"
    "slti $2, $20, 0x5\n"
    ".word 0x1440000A /* bnez $2, .L00423450: raw word */\n"
    "slti $2, $20, 0x4\n"
    "lw $2, 0x38($29)\n"
    "addiu $20, $20, -0x4\n"
    "lw $3, 0x18($29)\n"
    "addu $17, $17, $20\n"
    "addu $2, $2, $20\n"
    "addu $3, $3, $20\n"
    "sw $2, 0x38($29)\n"
    ".word 0x1000000A /* b .L00423474: raw word */\n"
    "sw $3, 0x18($29)\n"
    ".L00423450:\n"
    ".word 0x10400008 /* beqz $2, .L00423474: raw word */\n"
    "lw $4, 0x38($29)\n"
    "addiu $20, $20, 0x1C\n"
    "lw $2, 0x18($29)\n"
    "addu $17, $17, $20\n"
    "addu $4, $4, $20\n"
    "addu $2, $2, $20\n"
    "sw $4, 0x38($29)\n"
    "sw $2, 0x18($29)\n"
    ".L00423474:\n"
    "lw $3, 0x18($29)\n"
    ".word 0x18600005 /* blez $3, .L00423490: raw word */\n"
    "lw $5, 0x48($29)\n"
    "daddu $6, $3, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x48($29)\n"
    ".L00423490:\n"
    "lw $4, 0x38($29)\n"
    ".word 0x18800005 /* blez $4, .L004234AC: raw word */\n"
    "lw $5, 0x54($29)\n"
    "daddu $6, $4, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x54($29)\n"
    ".L004234AC:\n"
    "lw $2, 0x30($29)\n"
    ".word 0x10400016 /* beqz $2, .L0042350C: raw word */\n"
    "lw $4, 0x48($29)\n"
    "jal func_00420E28\n"
    "lw $5, 0x54($29)\n"
    ".word 0x04410013 /* bgez $2, .L00423510: raw word */\n"
    "lw $2, 0x20($29)\n"
    "lw $5, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "addiu $30, $30, -0x1\n"
    "lw $3, 0x34($29)\n"
    ".word 0x10600007 /* beqz $3, .L00423504: raw word */\n"
    "sw $2, 0x48($29)\n"
    "lw $5, 0x50($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "sw $2, 0x50($29)\n"
    ".L00423504:\n"
    "lw $4, 0x28($29)\n"
    "sw $4, 0x20($29)\n"
    ".L0042350C:\n"
    "lw $2, 0x20($29)\n"
    ".L00423510:\n"
    ".word 0x1C40001A /* bgtz $2, .L0042357C: raw word */\n"
    "lw $4, 0x34($29)\n"
    "lw $3, 0x8($29)\n"
    "slti $2, $3, 0x3\n"
    ".word 0x14400016 /* bnez $2, .L0042357C: raw word */\n"
    "nop\n"
    "lw $4, 0x20($29)\n"
    ".word 0x0480000B /* bltz $4, .L0042355C: raw word */\n"
    "lw $5, 0x54($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0x5\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "sw $2, 0x54($29)\n"
    "lw $4, 0x48($29)\n"
    "jal func_00420E28\n"
    "daddu $5, $2, $0\n"
    ".word 0x1C400004 /* bgtz $2, .L00423568: raw word */\n"
    "lw $3, 0x58($29)\n"
    ".L0042355C:\n"
    "lw $2, 0xC($29)\n"
    ".word 0x100000DA /* b .L004238CC: raw word */\n"
    "nor $30, $0, $2\n"
    ".L00423568:\n"
    "addiu $2, $0, 0x31\n"
    ".L0042356C:\n"
    "addiu $30, $30, 0x1\n"
    "addiu $21, $3, 0x1\n"
    ".word 0x100000D5 /* b .L004238CC: raw word */\n"
    "sb $2, 0x0($3)\n"
    ".L0042357C:\n"
    ".word 0x10800099 /* beqz $4, .L004237E4: raw word */\n"
    "addiu $20, $0, 0x1\n"
    ".word 0x1A200005 /* blez $17, .L0042359C: raw word */\n"
    "lw $5, 0x50($29)\n"
    "daddu $6, $17, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x50($29)\n"
    ".L0042359C:\n"
    "lw $2, 0x50($29)\n"
    "lw $3, 0x40($29)\n"
    ".word 0x10600012 /* beqz $3, .L004235F0: raw word */\n"
    "sw $2, 0x4C($29)\n"
    "lw $5, 0x4($2)\n"
    "jal func_00420510\n"
    "daddu $4, $23, $0\n"
    "lw $4, 0x4C($29)\n"
    "lw $6, 0x10($4)\n"
    "sw $2, 0x50($29)\n"
    "sll $6, $6, 2\n"
    "addiu $4, $2, 0xC\n"
    "addiu $6, $6, 0x8\n"
    "lw $2, 0x4C($29)\n"
    "jal func_0041605C\n"
    "addiu $5, $2, 0xC\n"
    "lw $5, 0x50($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420CC8\n"
    "addiu $6, $0, 0x1\n"
    "sw $2, 0x50($29)\n"
    ".L004235F0:\n"
    "dsll32 $2, $19, 0\n"
    "dsra32 $2, $2, 0\n"
    "addiu $20, $0, 0x1\n"
    ".word 0x10000020 /* b .L00423680: raw word */\n"
    "andi $22, $2, 0x1\n"
    "nop\n"
    ".L00423608:\n"
    "lw $5, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "lw $3, 0x4C($29)\n"
    "lw $4, 0x50($29)\n"
    ".word 0x14640009 /* bne $3, $4, .L0042364C: raw word */\n"
    "sw $2, 0x48($29)\n"
    "daddu $5, $4, $0\n"
    "addiu $6, $0, 0xA\n"
    "daddu $4, $23, $0\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "sw $2, 0x50($29)\n"
    ".word 0x1000000D /* b .L0042367C: raw word */\n"
    "sw $2, 0x4C($29)\n"
    ".L0042364C:\n"
    "lw $5, 0x4C($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "lw $5, 0x50($29)\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x4C($29)\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "sw $2, 0x50($29)\n"
    ".L0042367C:\n"
    "addiu $20, $20, 0x1\n"
    ".L00423680:\n"
    "lw $4, 0x48($29)\n"
    "jal func_00422560\n"
    "lw $5, 0x54($29)\n"
    "lw $4, 0x48($29)\n"
    "addiu $19, $2, 0x30\n"
    "jal func_00420E28\n"
    "lw $5, 0x4C($29)\n"
    "lw $5, 0x54($29)\n"
    "daddu $16, $2, $0\n"
    "lw $6, 0x50($29)\n"
    "jal func_00420E90\n"
    "daddu $4, $23, $0\n"
    "daddu $18, $2, $0\n"
    "lw $2, 0xC($18)\n"
    ".word 0x14400005 /* bnez $2, .L004236D0: raw word */\n"
    "addiu $17, $0, 0x1\n"
    "lw $4, 0x48($29)\n"
    "jal func_00420E28\n"
    "daddu $5, $18, $0\n"
    "daddu $17, $2, $0\n"
    ".L004236D0:\n"
    "daddu $5, $18, $0\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    ".word 0x1620000A /* bnez $17, .L00423708: raw word */\n"
    "lw $2, 0x8($29)\n"
    ".word 0x14400008 /* bnez $2, .L00423708: raw word */\n"
    "nop\n"
    ".word 0x16C00006 /* bnez $22, .L00423708: raw word */\n"
    "addiu $3, $0, 0x39\n"
    ".word 0x12630027 /* beq $19, $3, .L00423794: raw word */\n"
    "slt $2, $0, $16\n"
    "addu $19, $2, $19\n"
    ".word 0x10000071 /* b .L004238C8: raw word */\n"
    "sb $19, 0x0($21)\n"
    ".L00423708:\n"
    ".word 0x06000007 /* bltz $16, .L00423728: raw word */\n"
    "nop\n"
    ".word 0x1600001C /* bnez $16, .L00423784: raw word */\n"
    "lw $4, 0x8($29)\n"
    ".word 0x1480001A /* bnez $4, .L00423784: raw word */\n"
    "nop\n"
    ".word 0x16C00018 /* bnez $22, .L00423784: raw word */\n"
    "nop\n"
    ".L00423728:\n"
    ".word 0x1A200014 /* blez $17, .L0042377C: raw word */\n"
    "lw $5, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "jal func_00420CC8\n"
    "addiu $6, $0, 0x1\n"
    "sw $2, 0x48($29)\n"
    "lw $5, 0x54($29)\n"
    "jal func_00420E28\n"
    "daddu $4, $2, $0\n"
    "daddu $17, $2, $0\n"
    ".word 0x5E200007 /* bgtzl $17, .L00423770: raw word */\n"
    "addiu $19, $19, 0x1\n"
    ".word 0x5620005B /* bnel $17, $0, .L004238C8: raw word */\n"
    "sb $19, 0x0($21)\n"
    "andi $2, $19, 0x1\n"
    ".word 0x50400058 /* beql $2, $0, .L004238C8: raw word */\n"
    "sb $19, 0x0($21)\n"
    "addiu $19, $19, 0x1\n"
    ".L00423770:\n"
    "addiu $2, $0, 0x3A\n"
    ".word 0x12620008 /* beq $19, $2, .L00423798: raw word */\n"
    "addiu $3, $0, 0x39\n"
    ".L0042377C:\n"
    ".word 0x10000052 /* b .L004238C8: raw word */\n"
    "sb $19, 0x0($21)\n"
    ".L00423784:\n"
    ".word 0x1A200009 /* blez $17, .L004237AC: raw word */\n"
    "addiu $2, $0, 0x39\n"
    ".word 0x16620005 /* bne $19, $2, .L004237A4: raw word */\n"
    "addiu $2, $19, 0x1\n"
    ".L00423794:\n"
    "addiu $3, $0, 0x39\n"
    ".L00423798:\n"
    "sb $3, 0x0($21)\n"
    ".word 0x1000002A /* b .L00423848: raw word */\n"
    "addiu $21, $21, 0x1\n"
    ".L004237A4:\n"
    ".word 0x10000048 /* b .L004238C8: raw word */\n"
    "sb $2, 0x0($21)\n"
    ".L004237AC:\n"
    "sb $19, 0x0($21)\n"
    "lw $4, 0x20($29)\n"
    ".word 0x1684FF94 /* bne $20, $4, .L00423608: raw word */\n"
    "addiu $21, $21, 0x1\n"
    ".word 0x10000013 /* b .L0042380C: raw word */\n"
    "lw $5, 0x48($29)\n"
    "nop\n"
    ".L004237C8:\n"
    "lw $5, 0x48($29)\n"
    "daddu $4, $23, $0\n"
    "addiu $6, $0, 0xA\n"
    "jal func_004205F0\n"
    "daddu $7, $0, $0\n"
    "addiu $20, $20, 0x1\n"
    "sw $2, 0x48($29)\n"
    ".L004237E4:\n"
    "lw $4, 0x48($29)\n"
    "jal func_00422560\n"
    "lw $5, 0x54($29)\n"
    "addiu $19, $2, 0x30\n"
    "lw $3, 0x20($29)\n"
    "sb $19, 0x0($21)\n"
    "slt $2, $20, $3\n"
    ".word 0x1440FFF1 /* bnez $2, .L004237C8: raw word */\n"
    "addiu $21, $21, 0x1\n"
    "lw $5, 0x48($29)\n"
    ".L0042380C:\n"
    "daddu $4, $23, $0\n"
    "jal func_00420CC8\n"
    "addiu $6, $0, 0x1\n"
    "sw $2, 0x48($29)\n"
    "lw $5, 0x54($29)\n"
    "jal func_00420E28\n"
    "daddu $4, $2, $0\n"
    "daddu $16, $2, $0\n"
    ".word 0x5E000007 /* bgtzl $16, .L0042384C: raw word */\n"
    "addiu $21, $21, -0x1\n"
    ".word 0x1600001C /* bnez $16, .L004238A8: raw word */\n"
    "addiu $3, $0, 0x30\n"
    "andi $2, $19, 0x1\n"
    ".word 0x5040001A /* beql $2, $0, .L004238AC: raw word */\n"
    "addiu $21, $21, -0x1\n"
    ".L00423848:\n"
    "addiu $21, $21, -0x1\n"
    ".L0042384C:\n"
    "addiu $3, $0, 0x39\n"
    "lb $2, 0x0($21)\n"
    ".word 0x5443000A /* bnel $2, $3, .L00423880: raw word */\n"
    "lbu $2, 0x0($21)\n"
    "nop\n"
    ".L00423860:\n"
    "lw $4, 0x58($29)\n"
    ".word 0x12A40009 /* beq $21, $4, .L0042388C: raw word */\n"
    "addiu $21, $21, -0x1\n"
    "lb $2, 0x0($21)\n"
    "nop\n"
    ".word 0x1043FFFA /* beq $2, $3, .L00423860: raw word */\n"
    "nop\n"
    "lbu $2, 0x0($21)\n"
    ".L00423880:\n"
    "addiu $2, $2, 0x1\n"
    ".word 0x10000010 /* b .L004238C8: raw word */\n"
    "sb $2, 0x0($21)\n"
    ".L0042388C:\n"
    "lw $3, 0x58($29)\n"
    "addiu $2, $0, 0x31\n"
    "addiu $30, $30, 0x1\n"
    "sb $2, 0x0($3)\n"
    ".word 0x1000000B /* b .L004238CC: raw word */\n"
    "addiu $21, $3, 0x1\n"
    "nop\n"
    ".L004238A8:\n"
    "addiu $21, $21, -0x1\n"
    ".L004238AC:\n"
    "lb $2, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    ".word 0x5043FFFA /* beql $2, $3, .L004238AC: raw word */\n"
    "addiu $21, $21, -0x1\n"
    ".L004238C8:\n"
    "addiu $21, $21, 0x1\n"
    ".L004238CC:\n"
    "lw $5, 0x54($29)\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "lw $4, 0x50($29)\n"
    ".word 0x1080000A /* beqz $4, .L00423908: raw word */\n"
    "lw $2, 0x4C($29)\n"
    ".word 0x10400006 /* beqz $2, .L00423900: raw word */\n"
    "lw $5, 0x50($29)\n"
    ".word 0x10440003 /* beq $2, $4, .L004238FC: raw word */\n"
    "daddu $5, $2, $0\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    ".L004238FC:\n"
    "lw $5, 0x50($29)\n"
    ".L00423900:\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    ".L00423908:\n"
    "lw $5, 0x48($29)\n"
    ".L0042390C:\n"
    "jal func_004205B8\n"
    "daddu $4, $23, $0\n"
    "sb $0, 0x0($21)\n"
    "addiu $2, $30, 0x1\n"
    "lw $3, 0x10($29)\n"
    "sw $2, 0x0($3)\n"
    "lw $4, 0x14($29)\n"
    ".word 0x54800001 /* bnel $4, $0, .L00423930: raw word */\n"
    "sw $21, 0x0($4)\n"
    ".L00423930:\n"
    "lw $2, 0x58($29)\n"
    ".L00423934:\n"
    "lq $16, 0xF0($29)\n"
    "lq $17, 0xE0($29)\n"
    "lq $18, 0xD0($29)\n"
    "lq $19, 0xC0($29)\n"
    "lq $20, 0xB0($29)\n"
    "lq $21, 0xA0($29)\n"
    "lq $22, 0x90($29)\n"
    "lq $23, 0x80($29)\n"
    "lq $30, 0x70($29)\n"
    "ld $31, 0x60($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x100\n"
    ".end func_00422780\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".word 0x00000000\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00423980);
#ifdef SKIP_ASM
// PORT: PS2-only kernel syscall 0 stub (gcc writes the zero as move $3,$0, the stub has li $3,0); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
void func_00423980(void) {
    __asm__ volatile(
        ".set push\n.set noreorder\n.set noat\n"
        "addiu $3, $0, 0x0\n"
        "syscall 0\n"
        ".set pop\n"
        : : : "memory");
}
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00423990);
#ifdef SKIP_ASM
SYSCALL_STUB(func_00423990, 0x1)
#endif
