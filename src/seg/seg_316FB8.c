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
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00415FC8\n.ent func_00415FC8\nfunc_00415FC8:\n"
    "sltiu $2, $6, 0x10\n"
    "bnez $2, 2f\n"
    "or $2, $4, $5\n"
    "andi $2, $2, 0xF\n"
    "bnez $2, 2f\n"
    "nop\n"
    "1:\n"
    "lq $3, 0x0($4)\n"
    "sltiu $7, $6, 0x20\n"
    "lq $2, 0x0($5)\n"
    "addiu $4, $4, 0x10\n"
    "pxor $8, $2, $3\n"
    "addiu $2, $5, 0x10\n"
    "pcpyud $10, $8, $7\n"
    "or $9, $10, $8\n"
    "movz $5, $2, $9\n"
    "bnel $9, $0, 2f\n"
    "addiu $4, $4, -0x10\n"
    "beqz $7, 1b\n"
    "addiu $6, $6, -0x10\n"
    "2:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "addiu $6, $6, -0x1\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    "beq $6, $2, 5f\n"
    "nop\n"
    "lui $7, (0xFFFFFFFF >> 16)\n"
    "ori $7, $7, (0xFFFFFFFF & 0xFFFF)\n"
    "3:\n"
    "lbu $3, 0x0($4)\n"
    "lbu $2, 0x0($5)\n"
    "beq $3, $2, 4f\n"
    "addiu $4, $4, 0x1\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    "4:\n"
    "addiu $6, $6, -0x1\n"
    "bne $6, $7, 3b\n"
    "addiu $5, $5, 0x1\n"
    "5:\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".end func_00415FC8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_0041605C);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl func_0041605C\n.ent func_0041605C\nfunc_0041605C:\n"
    "daddu $8, $4, $0\n"
    "sltiu $2, $6, 0x20\n"
    "bnez $2, 3f\n"
    "daddu $3, $8, $0\n"
    "or $2, $5, $8\n"
    "andi $2, $2, 0xF\n"
    "bnel $2, $0, 4f\n"
    "addiu $6, $6, -0x1\n"
    "daddu $7, $8, $0\n"
    "1:\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $4, $6, 0x20\n"
    "sq $3, 0x0($7)\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "addiu $5, $5, 0x10\n"
    "sq $2, 0x0($7)\n"
    "beqz $4, 1b\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x8\n"
    "bnez $2, 3f\n"
    "daddu $3, $7, $0\n"
    "2:\n"
    "ld $3, 0x0($5)\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    "beqz $2, 2b\n"
    "addiu $7, $7, 0x8\n"
    "daddu $3, $7, $0\n"
    "3:\n"
    "addiu $6, $6, -0x1\n"
    "4:\n"
    "addiu $2, $0, -0x1\n"
    "beq $6, $2, 6f\n"
    "daddu $4, $2, $0\n"
    "5:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "nop\n"
    "bne $6, $4, 5b\n"
    "addiu $3, $3, 0x1\n"
    "6:\n"
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
    "beqz $2, 2f\n"
    "daddu $3, $8, $0\n"
    "addu $7, $5, $6\n"
    "sltu $2, $8, $7\n"
    "beqz $2, 2f\n"
    "addiu $2, $0, -0x1\n"
    "addu $3, $8, $6\n"
    "addiu $6, $6, -0x1\n"
    "beq $6, $2, 8f\n"
    "daddu $5, $7, $0\n"
    "daddu $4, $2, $0\n"
    "1:\n"
    "addiu $5, $5, -0x1\n"
    "addiu $3, $3, -0x1\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "nop\n"
    "bne $6, $4, 1b\n"
    "sb $2, 0x0($3)\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    "2:\n"
    "sltiu $2, $6, 0x20\n"
    "bnel $2, $0, 6f\n"
    "addiu $6, $6, -0x1\n"
    "or $2, $5, $3\n"
    "andi $2, $2, 0xF\n"
    "bnel $2, $0, 6f\n"
    "addiu $6, $6, -0x1\n"
    "daddu $7, $3, $0\n"
    "3:\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $4, $6, 0x20\n"
    "sq $3, 0x0($7)\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "addiu $5, $5, 0x10\n"
    "sq $2, 0x0($7)\n"
    "beqz $4, 3b\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x8\n"
    "bnez $2, 5f\n"
    "daddu $3, $7, $0\n"
    "4:\n"
    "ld $3, 0x0($5)\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    "beqz $2, 4b\n"
    "addiu $7, $7, 0x8\n"
    "daddu $3, $7, $0\n"
    "5:\n"
    "addiu $6, $6, -0x1\n"
    "6:\n"
    "addiu $2, $0, -0x1\n"
    "beq $6, $2, 8f\n"
    "daddu $4, $2, $0\n"
    "7:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "nop\n"
    "bne $6, $4, 7b\n"
    "addiu $3, $3, 0x1\n"
    "8:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end func_0041610C\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_00416210);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00416210\n.ent func_00416210\nfunc_00416210:\n"
    "sltiu $2, $6, 0x8\n"
    "bnez $2, 4f\n"
    "daddu $3, $4, $0\n"
    "andi $2, $4, 0xF\n"
    "bnez $2, 4f\n"
    "daddu $7, $4, $0\n"
    "andi $9, $5, 0xFF\n"
    "sltiu $10, $6, 0x20\n"
    "daddu $8, $9, $0\n"
    "dsll $3, $8, 8\n"
    "or $8, $3, $9\n"
    "pcpyh $3, $8\n"
    "bnez $10, 3f\n"
    "sltiu $2, $6, 0x8\n"
    "pcpyld $8, $3, $3\n"
    "1:\n"
    "sq $8, 0x0($7)\n"
    "addiu $6, $6, -0x20\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x20\n"
    "sq $8, 0x0($7)\n"
    "beqz $2, 1b\n"
    "addiu $7, $7, 0x10\n"
    "b 3f\n"
    "sltiu $2, $6, 0x8\n"
    "2:\n"
    "addiu $6, $6, -0x8\n"
    "addiu $7, $7, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "3:\n"
    "nop\n"
    "nop\n"
    "beql $2, $0, 2b\n"
    "sd $3, 0x0($7)\n"
    "daddu $3, $7, $0\n"
    "4:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "addiu $6, $6, -0x1\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    "beq $6, $2, 6f\n"
    "nop\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    "5:\n"
    "sb $5, 0x0($3)\n"
    "addiu $6, $6, -0x1\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "bne $6, $2, 5b\n"
    "addiu $3, $3, 0x1\n"
    "6:\n"
    "jr $31\n"
    "daddu $2, $4, $0\n"
    ".end func_00416210\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004162D0);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004162D0\n.ent func_004162D0\nfunc_004162D0:\n"
    "addiu $29, $29, -0x20\n"
    "sq $16, 0x0($29)\n"
    "daddu $16, $4, $0\n"
    "andi $2, $16, 0x7\n"
    "bnez $2, 4f\n"
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
    "bnez $2, 2f\n"
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
    "bnez $3, 4f\n"
    "daddu $4, $16, $0\n"
    "addiu $6, $4, 0x10\n"
    "1:\n"
    "lq $2, 0x0($6)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $7\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $3, $2, $2\n"
    "or $2, $2, $3\n"
    "beql $2, $0, 1b\n"
    "addiu $6, $6, 0x10\n"
    "b 4f\n"
    "daddu $4, $6, $0\n"
    "2:\n"
    "daddu $7, $3, $0\n"
    "daddu $8, $4, $0\n"
    "dsubu $3, $6, $3\n"
    "nor $2, $0, $6\n"
    "and $3, $3, $2\n"
    "and $3, $3, $4\n"
    "bnez $3, 4f\n"
    "daddu $4, $16, $0\n"
    "addiu $6, $16, 0x8\n"
    "3:\n"
    "ld $2, 0x0($6)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $7\n"
    "and $2, $2, $3\n"
    "and $2, $2, $8\n"
    "beql $2, $0, 3b\n"
    "addiu $6, $6, 0x8\n"
    "daddu $4, $6, $0\n"
    "4:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "bnel $2, $0, 4b\n"
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

INCLUDE_ASM("seg/seg_316FB8", strchr);

//100%
INCLUDE_ASM("seg/seg_316FB8", func_004165A8);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004165A8\n.ent func_004165A8\nfunc_004165A8:\n"
    "or $8, $4, $5\n"
    "andi $2, $8, 0x7\n"
    "bnel $2, $0, 7f\n"
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
    "bnez $9, 3f\n"
    "ld $2, 0x0($5)\n"
    "lq $3, 0x0($4)\n"
    "pcpyld $8, $7, $7\n"
    "lq $2, 0x0($5)\n"
    "pcpyld $10, $6, $6\n"
    "psubw $7, $2, $3\n"
    "pcpyud $6, $7, $4\n"
    "or $3, $6, $7\n"
    "bnel $3, $0, 7f\n"
    "lb $2, 0x0($4)\n"
    "lq $2, 0x0($4)\n"
    "pnor $3, $0, $2\n"
    "1:\n"
    "psubb $2, $2, $8\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $6, $3, $2\n"
    "beqz $6, 2f\n"
    "addiu $4, $4, 0x10\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    "2:\n"
    "addiu $5, $5, 0x10\n"
    "lq $2, 0x0($4)\n"
    "lq $3, 0x0($5)\n"
    "psubw $7, $2, $3\n"
    "pcpyud $6, $7, $4\n"
    "or $9, $6, $7\n"
    "beql $9, $0, 1b\n"
    "pnor $3, $0, $2\n"
    "b 7f\n"
    "lb $2, 0x0($4)\n"
    "3:\n"
    "ld $3, 0x0($4)\n"
    "bnel $3, $2, 7f\n"
    "lb $2, 0x0($4)\n"
    "ld $2, 0x0($4)\n"
    "nor $8, $0, $2\n"
    "4:\n"
    "dsubu $2, $2, $7\n"
    "and $2, $2, $8\n"
    "and $2, $2, $6\n"
    "beqz $2, 5f\n"
    "addiu $4, $4, 0x8\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    "5:\n"
    "addiu $5, $5, 0x8\n"
    "ld $2, 0x0($4)\n"
    "ld $3, 0x0($5)\n"
    "beql $3, $2, 4b\n"
    "nor $8, $0, $2\n"
    "b 7f\n"
    "lb $2, 0x0($4)\n"
    "6:\n"
    "sll $2, $3, 24\n"
    "lb $3, 0x0($5)\n"
    "sra $2, $2, 24\n"
    "bnel $2, $3, 8f\n"
    "lbu $3, 0x0($4)\n"
    "addiu $4, $4, 0x1\n"
    "addiu $5, $5, 0x1\n"
    "lb $2, 0x0($4)\n"
    "7:\n"
    "bnez $2, 6b\n"
    "lbu $3, 0x0($4)\n"
    "8:\n"
    "lbu $2, 0x0($5)\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    ".end func_004165A8\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strcpy);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 2\n.globl strcpy\n.ent strcpy\nstrcpy:\n"
    "daddu $7, $4, $0\n"
    "or $8, $5, $7\n"
    "andi $2, $8, 0x7\n"
    "bnez $2, 5f\n"
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
    "bnel $2, $0, 2f\n"
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
    "bnez $3, 4f\n"
    "daddu $6, $7, $0\n"
    "1:\n"
    "sq $9, 0x0($6)\n"
    "addiu $5, $5, 0x10\n"
    "lq $9, 0x0($5)\n"
    "psubb $2, $9, $10\n"
    "pnor $3, $0, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $8\n"
    "pcpyud $4, $2, $9\n"
    "or $3, $2, $4\n"
    "beqz $3, 1b\n"
    "addiu $6, $6, 0x10\n"
    "b 5f\n"
    "daddu $3, $6, $0\n"
    "2:\n"
    "dsubu $2, $10, $9\n"
    "nor $3, $0, $10\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    "bnez $2, 4f\n"
    "daddu $6, $7, $0\n"
    "3:\n"
    "sd $10, 0x0($6)\n"
    "addiu $5, $5, 0x8\n"
    "ld $10, 0x0($5)\n"
    "nor $2, $0, $10\n"
    "dsubu $3, $10, $9\n"
    "and $3, $3, $2\n"
    "and $3, $3, $4\n"
    "beqz $3, 3b\n"
    "addiu $6, $6, 0x8\n"
    "4:\n"
    "daddu $3, $6, $0\n"
    "5:\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($3)\n"
    "sll $2, $2, 24\n"
    "nop\n"
    "bnez $2, 5b\n"
    "addiu $3, $3, 0x1\n"
    "jr $31\n"
    "daddu $2, $7, $0\n"
    ".end strcpy\n"
    ".set at\n.set reorder\n");
#endif

//100%
INCLUDE_ASM("seg/seg_316FB8", strlen);
#ifdef SKIP_ASM
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl strlen\n.ent strlen\nstrlen:\n"
    "andi $2, $4, 0x7\n"
    "bnez $2, 4f\n"
    "daddu $7, $4, $0\n"
    "andi $3, $4, 0xF\n"
    "ori $2, $0, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0x8080\n"
    "dsll $2, $2, 9\n"
    "ori $2, $2, 0x101\n"
    "bnez $3, 2f\n"
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
    "bnel $6, $0, 4f\n"
    "daddu $4, $5, $0\n"
    "addiu $5, $5, 0x10\n"
    "1:\n"
    "lq $2, 0x0($5)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $8\n"
    "pand $2, $2, $3\n"
    "pand $4, $2, $9\n"
    "pcpyud $3, $4, $6\n"
    "or $3, $3, $4\n"
    "beql $3, $0, 1b\n"
    "addiu $5, $5, 0x10\n"
    "b 4f\n"
    "daddu $4, $5, $0\n"
    "2:\n"
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
    "bnel $2, $0, 4f\n"
    "daddu $4, $5, $0\n"
    "ori $6, $0, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 16\n"
    "ori $6, $6, 0x8080\n"
    "dsll $6, $6, 9\n"
    "ori $6, $6, 0x101\n"
    "addiu $5, $5, 0x8\n"
    "3:\n"
    "ld $2, 0x0($5)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $6\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    "beql $2, $0, 3b\n"
    "addiu $5, $5, 0x8\n"
    "daddu $4, $5, $0\n"
    "4:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "bnel $2, $0, 4b\n"
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
    "bnel $2, $0, 5f\n"
    "lb $2, 0x0($4)\n"
    "andi $3, $8, 0xF\n"
    "bnel $3, $0, 2f\n"
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
    "bnez $3, 4f\n"
    "daddu $7, $8, $0\n"
    "addiu $7, $7, 0x10\n"
    "nop\n"
    "1:\n"
    "lq $2, 0x0($7)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $2, $2, $3\n"
    "beqz $2, 1b\n"
    "addiu $7, $7, 0x10\n"
    "b 4f\n"
    "addiu $7, $7, -0x10\n"
    "2:\n"
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
    "bnez $3, 4f\n"
    "daddu $7, $8, $0\n"
    "addiu $7, $7, 0x8\n"
    "3:\n"
    "ld $2, 0x0($7)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $4\n"
    "beql $2, $0, 3b\n"
    "addiu $7, $7, 0x8\n"
    "4:\n"
    "daddu $4, $7, $0\n"
    "lb $2, 0x0($4)\n"
    "5:\n"
    "beqz $2, 7f\n"
    "addiu $6, $6, -0x1\n"
    "addiu $4, $4, 0x1\n"
    "6:\n"
    "lb $2, 0x0($4)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "bnel $2, $0, 6b\n"
    "addiu $4, $4, 0x1\n"
    "7:\n"
    "lui $2, (0xFFFFFFFF >> 16)\n"
    "ori $2, $2, (0xFFFFFFFF & 0xFFFF)\n"
    "beq $6, $2, 10f\n"
    "nop\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    "beqz $2, 10f\n"
    "addiu $4, $4, 0x1\n"
    "lui $3, (0xFFFFFFFF >> 16)\n"
    "ori $3, $3, (0xFFFFFFFF & 0xFFFF)\n"
    "nop\n"
    "8:\n"
    "beql $6, $0, 9f\n"
    "sb $0, 0x0($4)\n"
    "9:\n"
    "addiu $6, $6, -0x1\n"
    "beq $6, $3, 10f\n"
    "nop\n"
    "lbu $2, 0x0($5)\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    "bnez $2, 8b\n"
    "addiu $4, $4, 0x1\n"
    "10:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end func_00416958\n"
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
    "bnez $6, 2f\n"
    "or $3, $4, $5\n"
    "1:\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    "2:\n"
    "andi $2, $3, 0x7\n"
    "bnez $2, 8f\n"
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
    "bnez $2, 4f\n"
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
    "bnez $3, 8f\n"
    "daddu $2, $6, $0\n"
    "addiu $6, $6, -0x10\n"
    "3:\n"
    "beqz $6, 1b\n"
    "nop\n"
    "lq $2, 0x0($7)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $10\n"
    "pand $2, $2, $3\n"
    "pand $3, $2, $9\n"
    "pcpyud $2, $3, $4\n"
    "or $2, $2, $3\n"
    "bnez $2, 1b\n"
    "addiu $7, $7, 0x10\n"
    "sltiu $2, $6, 0x10\n"
    "lq $3, 0x0($7)\n"
    "bnez $2, 6f\n"
    "addiu $8, $8, 0x10\n"
    "lq $2, 0x0($8)\n"
    "psubw $3, $3, $2\n"
    "pcpyud $2, $3, $4\n"
    "or $2, $2, $3\n"
    "beql $2, $0, 3b\n"
    "addiu $6, $6, -0x10\n"
    "b 7f\n"
    "daddu $4, $7, $0\n"
    "4:\n"
    "sltiu $2, $6, 0x8\n"
    "bnez $2, 6f\n"
    "daddu $8, $5, $0\n"
    "ld $3, 0x0($4)\n"
    "ld $2, 0x0($5)\n"
    "bne $3, $2, 8f\n"
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
    "5:\n"
    "beqz $6, 1b\n"
    "nop\n"
    "ld $2, 0x0($7)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $10\n"
    "bnez $2, 1b\n"
    "addiu $7, $7, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "bnez $2, 6f\n"
    "addiu $8, $8, 0x8\n"
    "ld $3, 0x0($7)\n"
    "ld $2, 0x0($8)\n"
    "beql $3, $2, 5b\n"
    "addiu $6, $6, -0x8\n"
    "6:\n"
    "daddu $4, $7, $0\n"
    "7:\n"
    "daddu $5, $8, $0\n"
    "daddu $2, $6, $0\n"
    "8:\n"
    "beqz $2, 11f\n"
    "addiu $6, $6, -0x1\n"
    "b 10f\n"
    "lb $3, 0x0($4)\n"
    "nop\n"
    "9:\n"
    "beqz $6, 1b\n"
    "nop\n"
    "beqz $7, 1b\n"
    "addiu $4, $4, 0x1\n"
    "addiu $5, $5, 0x1\n"
    "lb $3, 0x0($4)\n"
    "addiu $6, $6, -0x1\n"
    "10:\n"
    "lb $2, 0x0($5)\n"
    "beq $3, $2, 9b\n"
    "lbu $7, 0x0($4)\n"
    "11:\n"
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
// PORT: PS2-only library string/memory routine (MMI); kept as the binary's own instructions rather than rewriting library source; the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl strncpy\n.ent strncpy\nstrncpy:\n"
    "daddu $8, $4, $0\n"
    "or $7, $5, $4\n"
    "addiu $10, $0, 0x10\n"
    "andi $2, $7, 0x7\n"
    "addiu $9, $0, 0x8\n"
    "bnez $2, 4f\n"
    "andi $2, $7, 0xF\n"
    "movz $9, $10, $2\n"
    "bnez $2, 1f\n"
    "sltu $2, $6, $9\n"
    "bnez $2, 4f\n"
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
    "bnez $3, 3f\n"
    "daddu $7, $8, $0\n"
    "lq $3, 0x0($5)\n"
    "addiu $6, $6, -0x10\n"
    "addiu $5, $5, 0x10\n"
    "sltiu $2, $6, 0x10\n"
    "sq $3, 0x0($7)\n"
    "bnez $2, 3f\n"
    "addiu $7, $7, 0x10\n"
    "lq $2, 0x0($5)\n"
    "pnor $3, $0, $2\n"
    "psubb $2, $2, $9\n"
    "pand $2, $2, $3\n"
    "pand $2, $2, $10\n"
    "pcpyud $3, $2, $4\n"
    "or $2, $2, $3\n"
    "beql $2, $0, 2f\n"
    "lq $3, 0x0($5)\n"
    "b 4f\n"
    "daddu $4, $7, $0\n"
    "1:\n"
    "bnez $2, 4f\n"
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
    "bnez $2, 3f\n"
    "daddu $7, $8, $0\n"
    "ld $3, 0x0($5)\n"
    "nop\n"
    "2:\n"
    "addiu $6, $6, -0x8\n"
    "addiu $5, $5, 0x8\n"
    "sltiu $2, $6, 0x8\n"
    "sd $3, 0x0($7)\n"
    "bnez $2, 3f\n"
    "addiu $7, $7, 0x8\n"
    "ld $2, 0x0($5)\n"
    "nor $3, $0, $2\n"
    "dsubu $2, $2, $9\n"
    "and $2, $2, $3\n"
    "and $2, $2, $10\n"
    "beql $2, $0, 2b\n"
    "ld $3, 0x0($5)\n"
    "3:\n"
    "daddu $4, $7, $0\n"
    "4:\n"
    "beqz $6, 6f\n"
    "daddu $2, $6, $0\n"
    "lbu $2, 0x0($5)\n"
    "addiu $6, $6, -0x1\n"
    "addiu $5, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "sll $2, $2, 24\n"
    "bnez $2, 4b\n"
    "addiu $4, $4, 0x1\n"
    "daddu $2, $6, $0\n"
    "beqz $2, 6f\n"
    "addiu $6, $6, -0x1\n"
    "5:\n"
    "sb $0, 0x0($4)\n"
    "daddu $2, $6, $0\n"
    "addiu $4, $4, 0x1\n"
    "nop\n"
    "nop\n"
    "bnez $2, 5b\n"
    "addiu $6, $6, -0x1\n"
    "6:\n"
    "jr $31\n"
    "daddu $2, $8, $0\n"
    ".end strncpy\n"
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

INCLUDE_ASM("seg/seg_316FB8", func_00417AB8);

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

INCLUDE_ASM("seg/seg_316FB8", func_00418958);

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
    "1:\n"
    "andi $2, $22, 0x7\n"
    "bnez $2, 2f\n"
    "addiu $2, $0, 0x2\n"
    "andi $2, $18, 0x7\n"
    "bnel $2, $0, 2f\n"
    "addiu $2, $0, 0x2\n"
    "xori $2, $18, 0x8\n"
    "sltu $2, $0, $2\n"
    "2:\n"
    "sw $2, 0x4($29)\n"
    "lw $3, 0x0($29)\n"
    "sltiu $2, $3, 0x7\n"
    "beqz $2, 12f\n"
    "sw $0, 0x8($29)\n"
    "mult $2, $3, $18\n"
    "addu $16, $22, $18\n"
    "addu $3, $2, $22\n"
    "sltu $2, $16, $3\n"
    "beqz $2, 80f\n"
    "srl $2, $18, 3\n"
    "sw $3, 0xC($29)\n"
    "lw $3, 0x4($29)\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $20, $18, 0\n"
    "slti $21, $3, 0x2\n"
    "daddu $17, $16, $0\n"
    "3:\n"
    "b 10f\n"
    "addu $19, $16, $18\n"
    "4:\n"
    "bnez $4, 5f\n"
    "nop\n"
    "ld $2, 0x0($16)\n"
    "ld $3, 0x0($17)\n"
    "sd $2, 0x0($17)\n"
    "b 9f\n"
    "sd $3, 0x0($16)\n"
    "5:\n"
    "beqz $21, 7f\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $30, 0\n"
    "daddu $6, $16, $0\n"
    "nop\n"
    "6:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    "bgtz $5, 6b\n"
    "addiu $6, $6, 0x8\n"
    "b 10f\n"
    "daddu $17, $16, $0\n"
    "7:\n"
    "dsrl32 $5, $20, 0\n"
    "daddu $6, $16, $0\n"
    "8:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    "bgtz $5, 8b\n"
    "addiu $6, $6, 0x1\n"
    "9:\n"
    "daddu $17, $16, $0\n"
    "10:\n"
    "sltu $2, $22, $17\n"
    "beqz $2, 11f\n"
    "subu $16, $17, $18\n"
    "daddu $5, $17, $0\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    "bgtzl $2, 4b\n"
    "lw $4, 0x4($29)\n"
    "11:\n"
    "lw $3, 0xC($29)\n"
    "daddu $16, $19, $0\n"
    "sltu $2, $16, $3\n"
    "bnez $2, 3b\n"
    "daddu $17, $16, $0\n"
    "b 81f\n"
    "lq $16, 0xE0($29)\n"
    "12:\n"
    "lw $4, 0x0($29)\n"
    "srl $2, $4, 1\n"
    "sltiu $3, $4, 0x8\n"
    "addiu $4, $4, -0x1\n"
    "sw $4, 0x30($29)\n"
    "mult $4, $2, $18\n"
    "bnez $3, 26f\n"
    "addu $16, $4, $22\n"
    "lw $3, 0x0($29)\n"
    "daddu $17, $22, $0\n"
    "sltiu $2, $3, 0x29\n"
    "lw $3, 0x30($29)\n"
    "mult $3, $3, $18\n"
    "bnez $2, 22f\n"
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
    "bgez $2, 13f\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "bltz $2, 14f\n"
    "daddu $4, $22, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $19, $0\n"
    "slt $3, $3, $2\n"
    "b 15f\n"
    "movn $4, $22, $3\n"
    "13:\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "bgtzl $2, 15f\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $22, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $22, $0\n"
    "slt $3, $3, $2\n"
    "b 15f\n"
    "movn $4, $19, $3\n"
    "14:\n"
    "daddu $4, $17, $0\n"
    "15:\n"
    "subu $20, $16, $30\n"
    "daddu $17, $4, $0\n"
    "addu $19, $16, $30\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $16, $0\n"
    "bgez $2, 16f\n"
    "daddu $4, $16, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "bltz $2, 17f\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $19, $0\n"
    "slt $3, $3, $2\n"
    "b 18f\n"
    "movn $4, $20, $3\n"
    "16:\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "bgtzl $2, 18f\n"
    "daddu $4, $16, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $20, $0\n"
    "slt $3, $3, $2\n"
    "b 18f\n"
    "movn $4, $19, $3\n"
    "17:\n"
    "daddu $4, $16, $0\n"
    "18:\n"
    "sll $2, $30, 1\n"
    "subu $19, $21, $30\n"
    "subu $20, $21, $2\n"
    "daddu $16, $4, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $19, $0\n"
    "bgez $2, 19f\n"
    "daddu $4, $19, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "bltz $2, 20f\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $21, $0\n"
    "slt $3, $3, $2\n"
    "b 21f\n"
    "movn $4, $20, $3\n"
    "19:\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "bgtzl $2, 21f\n"
    "daddu $4, $19, $0\n"
    "daddu $4, $20, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $20, $0\n"
    "slt $3, $3, $2\n"
    "b 21f\n"
    "movn $4, $21, $3\n"
    "20:\n"
    "daddu $4, $19, $0\n"
    "21:\n"
    "daddu $21, $4, $0\n"
    "22:\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $16, $0\n"
    "bgez $2, 23f\n"
    "daddu $4, $16, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "bltz $2, 24f\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $21, $0\n"
    "slt $3, $3, $2\n"
    "b 25f\n"
    "movn $4, $17, $3\n"
    "23:\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "bgtzl $2, 25f\n"
    "daddu $4, $16, $0\n"
    "daddu $4, $17, $0\n"
    "jalr $23\n"
    "daddu $5, $21, $0\n"
    "addiu $3, $0, -0x1\n"
    "daddu $4, $17, $0\n"
    "slt $3, $3, $2\n"
    "b 25f\n"
    "movn $4, $21, $3\n"
    "24:\n"
    "daddu $4, $16, $0\n"
    "25:\n"
    "daddu $16, $4, $0\n"
    "26:\n"
    "lw $2, 0x4($29)\n"
    "bnez $2, 27f\n"
    "lw $3, 0x4($29)\n"
    "ld $3, 0x0($16)\n"
    "addu $4, $22, $18\n"
    "sw $4, 0x2C($29)\n"
    "ld $2, 0x0($22)\n"
    "sd $3, 0x0($22)\n"
    "b 31f\n"
    "sd $2, 0x0($16)\n"
    "27:\n"
    "slti $2, $3, 0x2\n"
    "beqz $2, 29f\n"
    "srl $2, $18, 3\n"
    "daddu $4, $16, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $6, $22, $0\n"
    "dsrl32 $5, $2, 0\n"
    "addu $2, $22, $18\n"
    "sw $2, 0x2C($29)\n"
    "nop\n"
    "28:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($6)\n"
    "sd $3, 0x0($6)\n"
    "sd $2, 0x0($4)\n"
    "addiu $6, $6, 0x8\n"
    "bgtz $5, 28b\n"
    "addiu $4, $4, 0x8\n"
    "b 32f\n"
    "lw $2, 0x30($29)\n"
    "29:\n"
    "addu $3, $22, $18\n"
    "dsll32 $2, $18, 0\n"
    "sw $3, 0x2C($29)\n"
    "daddu $4, $16, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $6, $22, $0\n"
    "30:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($6)\n"
    "sb $3, 0x0($6)\n"
    "sb $2, 0x0($4)\n"
    "addiu $6, $6, 0x1\n"
    "bgtz $5, 30b\n"
    "addiu $4, $4, 0x1\n"
    "31:\n"
    "lw $2, 0x30($29)\n"
    "32:\n"
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
    "b 40f\n"
    "sd $2, 0x18($29)\n"
    "nop\n"
    "33:\n"
    "bnez $5, 39f\n"
    "addu $9, $17, $18\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x4($29)\n"
    "bnez $3, 34f\n"
    "sw $2, 0x8($29)\n"
    "ld $3, 0x0($17)\n"
    "addu $7, $19, $18\n"
    "ld $2, 0x0($19)\n"
    "sd $3, 0x0($19)\n"
    "b 38f\n"
    "sd $2, 0x0($17)\n"
    "34:\n"
    "lw $4, 0x10($29)\n"
    "beqz $4, 36f\n"
    "ld $2, 0x18($29)\n"
    "daddu $5, $19, $0\n"
    "daddu $4, $17, $0\n"
    "addu $7, $5, $18\n"
    "dsrl32 $6, $2, 0\n"
    "nop\n"
    "35:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($5)\n"
    "sd $3, 0x0($5)\n"
    "sd $2, 0x0($4)\n"
    "addiu $5, $5, 0x8\n"
    "bgtz $6, 35b\n"
    "addiu $4, $4, 0x8\n"
    "b 39f\n"
    "daddu $19, $7, $0\n"
    "36:\n"
    "ld $3, 0x20($29)\n"
    "daddu $5, $19, $0\n"
    "daddu $4, $17, $0\n"
    "addu $7, $5, $18\n"
    "dsrl32 $6, $3, 0\n"
    "nop\n"
    "37:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($5)\n"
    "sb $3, 0x0($5)\n"
    "sb $2, 0x0($4)\n"
    "addiu $5, $5, 0x1\n"
    "bgtz $6, 37b\n"
    "addiu $4, $4, 0x1\n"
    "38:\n"
    "daddu $19, $7, $0\n"
    "39:\n"
    "daddu $17, $9, $0\n"
    "40:\n"
    "sltu $2, $16, $17\n"
    "bnez $2, 41f\n"
    "lw $4, 0x4($29)\n"
    "daddu $5, $22, $0\n"
    "jalr $23\n"
    "daddu $4, $17, $0\n"
    "daddu $5, $2, $0\n"
    "blez $5, 33b\n"
    "lw $4, 0x4($29)\n"
    "41:\n"
    "srl $2, $18, 3\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $21, $18, 0\n"
    "b 49f\n"
    "slti $9, $4, 0x2\n"
    "42:\n"
    "bnez $5, 48f\n"
    "subu $8, $16, $18\n"
    "addiu $2, $0, 0x1\n"
    "lw $3, 0x4($29)\n"
    "bnez $3, 43f\n"
    "sw $2, 0x8($29)\n"
    "ld $3, 0x0($20)\n"
    "subu $7, $20, $18\n"
    "ld $2, 0x0($16)\n"
    "sd $3, 0x0($16)\n"
    "b 47f\n"
    "sd $2, 0x0($20)\n"
    "43:\n"
    "beqz $9, 45f\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $20, $0\n"
    "dsrl32 $6, $30, 0\n"
    "subu $7, $5, $18\n"
    "nop\n"
    "44:\n"
    "ld $3, 0x0($5)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($5)\n"
    "addiu $4, $4, 0x8\n"
    "bgtz $6, 44b\n"
    "addiu $5, $5, 0x8\n"
    "b 48f\n"
    "daddu $20, $7, $0\n"
    "45:\n"
    "daddu $5, $20, $0\n"
    "dsrl32 $6, $21, 0\n"
    "subu $7, $5, $18\n"
    "nop\n"
    "46:\n"
    "lbu $3, 0x0($5)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($5)\n"
    "addiu $4, $4, 0x1\n"
    "bgtz $6, 46b\n"
    "addiu $5, $5, 0x1\n"
    "47:\n"
    "daddu $20, $7, $0\n"
    "48:\n"
    "daddu $16, $8, $0\n"
    "49:\n"
    "sltu $2, $16, $17\n"
    "bnez $2, 56f\n"
    "daddu $5, $22, $0\n"
    "sq $9, 0x40($29)\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    "daddu $5, $2, $0\n"
    "bgez $5, 42b\n"
    "lq $9, 0x40($29)\n"
    "lw $4, 0x4($29)\n"
    "bnez $4, 50f\n"
    "lw $2, 0x10($29)\n"
    "ld $3, 0x0($16)\n"
    "addu $9, $17, $18\n"
    "ld $2, 0x0($17)\n"
    "subu $8, $16, $18\n"
    "sd $3, 0x0($17)\n"
    "b 54f\n"
    "sd $2, 0x0($16)\n"
    "50:\n"
    "beqz $2, 52f\n"
    "ld $3, 0x18($29)\n"
    "daddu $5, $17, $0\n"
    "daddu $4, $16, $0\n"
    "addu $9, $5, $18\n"
    "dsrl32 $6, $3, 0\n"
    "subu $8, $4, $18\n"
    "51:\n"
    "ld $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "ld $2, 0x0($5)\n"
    "sd $3, 0x0($5)\n"
    "sd $2, 0x0($4)\n"
    "addiu $5, $5, 0x8\n"
    "bgtz $6, 51b\n"
    "addiu $4, $4, 0x8\n"
    "b 55f\n"
    "addiu $3, $0, 0x1\n"
    "52:\n"
    "ld $2, 0x20($29)\n"
    "daddu $5, $17, $0\n"
    "daddu $4, $16, $0\n"
    "addu $9, $5, $18\n"
    "dsrl32 $6, $2, 0\n"
    "subu $8, $4, $18\n"
    "53:\n"
    "lbu $3, 0x0($4)\n"
    "daddiu $6, $6, -0x1\n"
    "lb $2, 0x0($5)\n"
    "sb $3, 0x0($5)\n"
    "sb $2, 0x0($4)\n"
    "addiu $5, $5, 0x1\n"
    "bgtz $6, 53b\n"
    "addiu $4, $4, 0x1\n"
    "54:\n"
    "addiu $3, $0, 0x1\n"
    "55:\n"
    "daddu $17, $9, $0\n"
    "daddu $16, $8, $0\n"
    "b 40b\n"
    "sw $3, 0x8($29)\n"
    "56:\n"
    "lw $4, 0x8($29)\n"
    "bnez $4, 66f\n"
    "subu $5, $17, $19\n"
    "lw $2, 0x0($29)\n"
    "lw $16, 0x2C($29)\n"
    "mult $2, $2, $18\n"
    "addu $3, $2, $22\n"
    "sltu $2, $16, $3\n"
    "beqz $2, 80f\n"
    "srl $2, $18, 3\n"
    "sw $3, 0x28($29)\n"
    "lw $3, 0x4($29)\n"
    "dsll32 $30, $2, 0\n"
    "dsll32 $20, $18, 0\n"
    "slti $21, $3, 0x2\n"
    "daddu $17, $16, $0\n"
    "nop\n"
    "57:\n"
    "b 64f\n"
    "addu $19, $16, $18\n"
    "58:\n"
    "bnez $4, 59f\n"
    "nop\n"
    "ld $2, 0x0($16)\n"
    "ld $3, 0x0($17)\n"
    "sd $2, 0x0($17)\n"
    "b 63f\n"
    "sd $3, 0x0($16)\n"
    "59:\n"
    "beqz $21, 61f\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $30, 0\n"
    "daddu $6, $16, $0\n"
    "nop\n"
    "60:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    "bgtz $5, 60b\n"
    "addiu $6, $6, 0x8\n"
    "b 64f\n"
    "daddu $17, $16, $0\n"
    "61:\n"
    "dsrl32 $5, $20, 0\n"
    "daddu $6, $16, $0\n"
    "62:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    "bgtz $5, 62b\n"
    "addiu $6, $6, 0x1\n"
    "63:\n"
    "daddu $17, $16, $0\n"
    "64:\n"
    "sltu $2, $22, $17\n"
    "beqz $2, 65f\n"
    "subu $16, $17, $18\n"
    "daddu $5, $17, $0\n"
    "jalr $23\n"
    "daddu $4, $16, $0\n"
    "bgtzl $2, 58b\n"
    "lw $4, 0x4($29)\n"
    "65:\n"
    "lw $3, 0x28($29)\n"
    "daddu $16, $19, $0\n"
    "sltu $2, $16, $3\n"
    "bnez $2, 57b\n"
    "daddu $17, $16, $0\n"
    "b 81f\n"
    "lq $16, 0xE0($29)\n"
    "66:\n"
    "subu $3, $19, $22\n"
    "slt $2, $3, $5\n"
    "daddu $7, $5, $0\n"
    "movn $5, $3, $2\n"
    "subu $16, $20, $16\n"
    "lw $2, 0x0($29)\n"
    "mult $2, $2, $18\n"
    "blez $5, 70f\n"
    "addu $21, $2, $22\n"
    "lw $4, 0x4($29)\n"
    "slti $2, $4, 0x2\n"
    "beqz $2, 68f\n"
    "subu $3, $17, $5\n"
    "srl $2, $5, 3\n"
    "daddu $6, $3, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $4, $22, $0\n"
    "dsrl32 $5, $2, 0\n"
    "67:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    "bgtz $5, 67b\n"
    "addiu $6, $6, 0x8\n"
    "b 71f\n"
    "subu $2, $21, $20\n"
    "68:\n"
    "dsll32 $2, $5, 0\n"
    "daddu $6, $3, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $4, $22, $0\n"
    "69:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    "bgtz $5, 69b\n"
    "addiu $6, $6, 0x1\n"
    "70:\n"
    "subu $2, $21, $20\n"
    "71:\n"
    "subu $5, $2, $18\n"
    "sltu $3, $16, $5\n"
    "movn $5, $16, $3\n"
    "blez $5, 75f\n"
    "lw $3, 0x4($29)\n"
    "slti $2, $3, 0x2\n"
    "beqz $2, 73f\n"
    "subu $3, $21, $5\n"
    "srl $2, $5, 3\n"
    "daddu $4, $17, $0\n"
    "dsll32 $2, $2, 0\n"
    "daddu $6, $3, $0\n"
    "dsrl32 $5, $2, 0\n"
    "72:\n"
    "ld $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "ld $2, 0x0($4)\n"
    "sd $3, 0x0($4)\n"
    "sd $2, 0x0($6)\n"
    "addiu $4, $4, 0x8\n"
    "bgtz $5, 72b\n"
    "addiu $6, $6, 0x8\n"
    "b 76f\n"
    "daddu $5, $7, $0\n"
    "73:\n"
    "dsll32 $2, $5, 0\n"
    "daddu $4, $17, $0\n"
    "dsrl32 $5, $2, 0\n"
    "daddu $6, $3, $0\n"
    "74:\n"
    "lbu $3, 0x0($6)\n"
    "daddiu $5, $5, -0x1\n"
    "lb $2, 0x0($4)\n"
    "sb $3, 0x0($4)\n"
    "sb $2, 0x0($6)\n"
    "addiu $4, $4, 0x1\n"
    "bgtz $5, 74b\n"
    "addiu $6, $6, 0x1\n"
    "75:\n"
    "daddu $5, $7, $0\n"
    "76:\n"
    "sltu $2, $18, $5\n"
    "beql $2, $0, 78f\n"
    "daddu $5, $16, $0\n"
    "divu $0, $5, $18\n"
    "beql $18, $0, 77f\n"
    "break 0, 7\n"
    "77:\n"
    "daddu $4, $22, $0\n"
    "daddu $6, $18, $0\n"
    "mflo $5\n"
    "jal func_00418EF8\n"
    "daddu $7, $23, $0\n"
    "daddu $5, $16, $0\n"
    "78:\n"
    "sltu $2, $18, $5\n"
    "beqz $2, 81f\n"
    "lq $16, 0xE0($29)\n"
    "divu $0, $5, $18\n"
    "beql $18, $0, 79f\n"
    "break 0, 7\n"
    "79:\n"
    "subu $22, $21, $5\n"
    "mflo $2\n"
    "b 1b\n"
    "sw $2, 0x0($29)\n"
    "80:\n"
    "lq $16, 0xE0($29)\n"
    "81:\n"
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
    "1:\n"
    "lb $3, 0x0($21)\n"
    "sltiu $2, $3, 0x2E\n"
    "beqz $2, 2f\n"
    "lui $2, %hi(jtbl_0049A240)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_0049A240)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    "addiu $2, $0, 0x1\n"
    "sw $2, 0xC($29)\n"
    "addiu $21, $21, 0x1\n"
    "lb $2, 0x0($21)\n"
    "bnel $2, $0, 2f\n"
    "lb $3, 0x0($21)\n"
    "b 98f\n"
    "daddu $21, $5, $0\n"
    "b 1b\n"
    "addiu $21, $21, 0x1\n"
    "lb $3, 0x0($21)\n"
    "2:\n"
    "addiu $2, $0, 0x30\n"
    "bne $3, $2, 4f\n"
    "lbu $4, 0x0($21)\n"
    "addiu $10, $0, 0x1\n"
    "addiu $4, $0, 0x30\n"
    "3:\n"
    "addiu $21, $21, 0x1\n"
    "lb $3, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beq $3, $4, 3b\n"
    "lbu $2, 0x0($21)\n"
    "beqz $3, 98f\n"
    "daddu $4, $2, $0\n"
    "4:\n"
    "sll $2, $4, 24\n"
    "sw $21, 0x18($29)\n"
    "sra $4, $2, 24\n"
    "daddu $18, $0, $0\n"
    "sw $0, 0x20($29)\n"
    "daddu $9, $0, $0\n"
    "slti $2, $4, 0x30\n"
    "bnez $2, 8f\n"
    "daddu $20, $0, $0\n"
    "slti $2, $4, 0x3A\n"
    "beqz $2, 9f\n"
    "addiu $2, $0, 0x2E\n"
    "addiu $3, $0, 0xA\n"
    "slti $2, $20, 0x9\n"
    "nop\n"
    "5:\n"
    "beqz $2, 6f\n"
    "lw $7, 0x20($29)\n"
    "mult $7, $7, $3\n"
    "addu $2, $7, $4\n"
    "addiu $2, $2, -0x30\n"
    "b 7f\n"
    "sw $2, 0x20($29)\n"
    "6:\n"
    "slti $2, $20, 0x10\n"
    "beqz $2, 7f\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $2, $2, 1\n"
    "daddu $2, $4, $2\n"
    "daddiu $18, $2, -0x30\n"
    "7:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "slti $2, $4, 0x30\n"
    "bnez $2, 8f\n"
    "addiu $20, $20, 0x1\n"
    "slti $2, $4, 0x3A\n"
    "bnez $2, 5b\n"
    "slti $2, $20, 0x9\n"
    "8:\n"
    "addiu $2, $0, 0x2E\n"
    "9:\n"
    "bne $4, $2, 21f\n"
    "daddu $30, $20, $0\n"
    "addiu $21, $21, 0x1\n"
    "bnez $20, 20f\n"
    "lb $4, 0x0($21)\n"
    "addiu $2, $0, 0x30\n"
    "bnel $4, $2, 11f\n"
    "addiu $2, $4, -0x31\n"
    "nop\n"
    "10:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beq $4, $2, 10b\n"
    "addiu $6, $6, 0x1\n"
    "addiu $2, $4, -0x31\n"
    "11:\n"
    "sltiu $2, $2, 0x9\n"
    "beqz $2, 22f\n"
    "addiu $2, $0, 0x65\n"
    "daddu $9, $6, $0\n"
    "sw $21, 0x18($29)\n"
    "daddu $6, $0, $0\n"
    "addiu $8, $21, 0x1\n"
    "nop\n"
    "12:\n"
    "addiu $4, $4, -0x30\n"
    "beqz $4, 19f\n"
    "addiu $6, $6, 0x1\n"
    "addiu $7, $0, 0x1\n"
    "slt $2, $7, $6\n"
    "beqz $2, 16f\n"
    "addu $9, $9, $6\n"
    "addiu $7, $6, -0x1\n"
    "addiu $3, $0, 0xA\n"
    "daddu $2, $20, $0\n"
    "13:\n"
    "slti $2, $2, 0x9\n"
    "beqz $2, 14f\n"
    "addiu $20, $20, 0x1\n"
    "lw $2, 0x20($29)\n"
    "mult $2, $2, $3\n"
    "b 15f\n"
    "sw $2, 0x20($29)\n"
    "14:\n"
    "slti $2, $20, 0x11\n"
    "beqz $2, 15f\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $18, $2, 1\n"
    "15:\n"
    "addiu $7, $7, -0x1\n"
    "bnez $7, 13b\n"
    "daddu $2, $20, $0\n"
    "16:\n"
    "daddu $2, $20, $0\n"
    "slti $2, $2, 0x9\n"
    "beqz $2, 17f\n"
    "addiu $20, $20, 0x1\n"
    "lw $3, 0x20($29)\n"
    "addiu $2, $0, 0xA\n"
    "mtlo $4\n"
    "madd $0, $3, $2\n"
    "mflo $3\n"
    "b 18f\n"
    "sw $3, 0x20($29)\n"
    "17:\n"
    "slti $2, $20, 0x11\n"
    "beqz $2, 18f\n"
    "dsll $2, $18, 2\n"
    "daddu $2, $2, $18\n"
    "dsll $2, $2, 1\n"
    "daddu $18, $4, $2\n"
    "18:\n"
    "daddu $6, $0, $0\n"
    "19:\n"
    "daddu $21, $8, $0\n"
    "lb $4, 0x0($21)\n"
    "20:\n"
    "addiu $2, $4, -0x30\n"
    "sltiu $2, $2, 0xA\n"
    "bnez $2, 12b\n"
    "addiu $8, $21, 0x1\n"
    "21:\n"
    "addiu $2, $0, 0x65\n"
    "22:\n"
    "beq $4, $2, 23f\n"
    "sd $0, 0x10($29)\n"
    "addiu $2, $0, 0x45\n"
    "bne $4, $2, 34f\n"
    "nop\n"
    "23:\n"
    "bnel $20, $0, 24f\n"
    "daddu $5, $21, $0\n"
    "bnel $6, $0, 24f\n"
    "daddu $5, $21, $0\n"
    "bnel $10, $0, 24f\n"
    "daddu $5, $21, $0\n"
    "b 98f\n"
    "daddu $21, $5, $0\n"
    "24:\n"
    "addiu $21, $21, 0x1\n"
    "addiu $2, $0, 0x2B\n"
    "lb $4, 0x0($21)\n"
    "beq $4, $2, 25f\n"
    "daddu $8, $0, $0\n"
    "addiu $2, $0, 0x2D\n"
    "bne $4, $2, 26f\n"
    "addiu $2, $4, -0x30\n"
    "addiu $8, $0, 0x1\n"
    "25:\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "addiu $2, $4, -0x30\n"
    "26:\n"
    "sltiu $2, $2, 0xA\n"
    "beqz $2, 33f\n"
    "addiu $2, $0, 0x30\n"
    "bnel $4, $2, 28f\n"
    "addiu $2, $4, -0x31\n"
    "addiu $21, $21, 0x1\n"
    "nop\n"
    "27:\n"
    "lb $4, 0x0($21)\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beql $4, $2, 27b\n"
    "addiu $21, $21, 0x1\n"
    "addiu $2, $4, -0x31\n"
    "28:\n"
    "sltiu $2, $2, 0x9\n"
    "beqz $2, 32f\n"
    "addiu $4, $4, -0x30\n"
    "daddu $7, $21, $0\n"
    "sd $4, 0x10($29)\n"
    "addiu $21, $21, 0x1\n"
    "lb $4, 0x0($21)\n"
    "slti $2, $4, 0x30\n"
    "bnez $2, 31f\n"
    "subu $2, $21, $7\n"
    "29:\n"
    "slti $2, $4, 0x3A\n"
    "beqz $2, 30f\n"
    "ld $3, 0x10($29)\n"
    "addiu $21, $21, 0x1\n"
    "dsll $2, $3, 2\n"
    "daddu $2, $2, $3\n"
    "dsll $2, $2, 1\n"
    "daddu $2, $4, $2\n"
    "lb $4, 0x0($21)\n"
    "daddiu $2, $2, -0x30\n"
    "slti $3, $4, 0x30\n"
    "beqz $3, 29b\n"
    "sd $2, 0x10($29)\n"
    "nop\n"
    "30:\n"
    "subu $2, $21, $7\n"
    "31:\n"
    "lui $4, (0x98967F >> 16)\n"
    "ori $4, $4, (0x98967F & 0xFFFF)\n"
    "ld $7, 0x10($29)\n"
    "slti $2, $2, 0x9\n"
    "movz $7, $4, $2\n"
    "dsubu $3, $0, $7\n"
    "movn $7, $3, $8\n"
    "b 34f\n"
    "sd $7, 0x10($29)\n"
    "32:\n"
    "b 34f\n"
    "sd $0, 0x10($29)\n"
    "33:\n"
    "daddu $21, $5, $0\n"
    "34:\n"
    "bnez $20, 35f\n"
    "ld $3, 0x10($29)\n"
    "movn $5, $21, $10\n"
    "b 98f\n"
    "movz $21, $5, $6\n"
    "35:\n"
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
    "bgez $7, 36f\n"
    "daddu $4, $2, $0\n"
    "ori $5, $0, 0x83E0\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411F18\n"
    "nop\n"
    "daddu $4, $2, $0\n"
    "36:\n"
    "slti $2, $19, 0xA\n"
    "bnez $2, 39f\n"
    "daddu $17, $4, $0\n"
    "lui $3, %hi(D_0049A8F8)\n"
    "addiu $2, $19, -0x9\n"
    "addiu $3, $3, %lo(D_0049A8F8)\n"
    "sll $2, $2, 3\n"
    "addu $2, $2, $3\n"
    "daddu $5, $4, $0\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($2)\n"
    "bltz $18, 37f\n"
    "daddu $17, $2, $0\n"
    "jal func_00411438\n"
    "daddu $4, $18, $0\n"
    "b 38f\n"
    "daddu $4, $17, $0\n"
    "37:\n"
    "dsrl $2, $18, 1\n"
    "andi $4, $18, 0x1\n"
    "jal func_00411438\n"
    "or $4, $4, $2\n"
    "daddu $4, $2, $0\n"
    "jal func_00411F18\n"
    "daddu $5, $4, $0\n"
    "daddu $4, $17, $0\n"
    "38:\n"
    "jal func_00411F18\n"
    "daddu $5, $2, $0\n"
    "daddu $17, $2, $0\n"
    "39:\n"
    "slti $2, $20, 0x10\n"
    "beqz $2, 43f\n"
    "sw $0, 0x38($29)\n"
    "ld $2, 0x10($29)\n"
    "beqz $2, 99f\n"
    "lw $4, 0x8($29)\n"
    "blez $2, 42f\n"
    "slti $2, $2, 0x17\n"
    "beqz $2, 40f\n"
    "ld $4, 0x10($29)\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $5, $17, $0\n"
    "dsll32 $3, $4, 0\n"
    "dsra32 $3, $3, 0\n"
    "sll $3, $3, 3\n"
    "b 41f\n"
    "addu $3, $3, $2\n"
    "40:\n"
    "addiu $3, $0, 0xF\n"
    "subu $7, $3, $20\n"
    "ld $3, 0x10($29)\n"
    "addiu $2, $7, 0x16\n"
    "slt $2, $2, $3\n"
    "bnez $2, 44f\n"
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
    "41:\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($3)\n"
    "b 98f\n"
    "daddu $17, $2, $0\n"
    "42:\n"
    "ld $7, 0x10($29)\n"
    "slti $2, $7, -0x16\n"
    "bnez $2, 44f\n"
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
    "b 98f\n"
    "daddu $17, $2, $0\n"
    "43:\n"
    "subu $2, $20, $19\n"
    "44:\n"
    "addu $16, $16, $2\n"
    "blez $16, 53f\n"
    "andi $7, $16, 0xF\n"
    "beqz $7, 45f\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $7, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $5, $17, $0\n"
    "addu $3, $3, $2\n"
    "jal func_00411FD8\n"
    "ld $4, 0x0($3)\n"
    "daddu $17, $2, $0\n"
    "45:\n"
    "addiu $2, $0, -0x10\n"
    "and $16, $16, $2\n"
    "beqz $16, 61f\n"
    "slti $2, $16, 0x135\n"
    "bnel $2, $0, 48f\n"
    "sra $16, $16, 4\n"
    "46:\n"
    "addiu $2, $0, 0x22\n"
    "47:\n"
    "lui $3, %hi(D_0049A898)\n"
    "sw $2, 0x0($23)\n"
    "lw $2, 0x38($29)\n"
    "bnez $2, 96f\n"
    "ld $17, %lo(D_0049A898)($3)\n"
    "b 99f\n"
    "lw $4, 0x8($29)\n"
    "48:\n"
    "beqz $16, 61f\n"
    "daddu $19, $0, $0\n"
    "slti $2, $16, 0x2\n"
    "bnez $2, 51f\n"
    "lui $22, %hi(D_0049A9C0)\n"
    "addiu $18, $22, %lo(D_0049A9C0)\n"
    "49:\n"
    "andi $2, $16, 0x1\n"
    "beql $2, $0, 50f\n"
    "sra $16, $16, 1\n"
    "ld $4, 0x0($18)\n"
    "jal func_00411FD8\n"
    "daddu $5, $17, $0\n"
    "daddu $17, $2, $0\n"
    "sra $16, $16, 1\n"
    "50:\n"
    "addiu $18, $18, 0x8\n"
    "slti $2, $16, 0x2\n"
    "beqz $2, 49b\n"
    "addiu $19, $19, 0x1\n"
    "51:\n"
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
    "bnez $2, 47b\n"
    "addiu $2, $0, 0x22\n"
    "lui $2, (0x7C900000 >> 16)\n"
    "sltu $2, $2, $18\n"
    "beqz $2, 52f\n"
    "lui $2, (0x3500000 >> 16)\n"
    "and $17, $17, $16\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFE\n"
    "dsll $2, $2, 31\n"
    "or $17, $17, $2\n"
    "b 61f\n"
    "or $17, $17, $16\n"
    "52:\n"
    "and $17, $17, $16\n"
    "addu $2, $4, $2\n"
    "dsll32 $2, $2, 0\n"
    "b 61f\n"
    "or $17, $17, $2\n"
    "53:\n"
    "bgez $16, 62f\n"
    "lw $5, 0x18($29)\n"
    "negu $16, $16\n"
    "andi $7, $16, 0xF\n"
    "beqz $7, 54f\n"
    "lui $2, %hi(D_0049A8F8)\n"
    "sll $3, $7, 3\n"
    "addiu $2, $2, %lo(D_0049A8F8)\n"
    "daddu $4, $17, $0\n"
    "addu $3, $3, $2\n"
    "jal func_00412280\n"
    "ld $5, 0x0($3)\n"
    "daddu $17, $2, $0\n"
    "54:\n"
    "addiu $2, $0, -0x10\n"
    "and $16, $16, $2\n"
    "beqz $16, 61f\n"
    "sra $16, $16, 4\n"
    "slti $2, $16, 0x20\n"
    "beqz $2, 58f\n"
    "daddu $19, $0, $0\n"
    "slti $2, $16, 0x2\n"
    "bnez $2, 57f\n"
    "lui $22, %hi(D_0049A9E8)\n"
    "addiu $18, $22, %lo(D_0049A9E8)\n"
    "55:\n"
    "andi $2, $16, 0x1\n"
    "beql $2, $0, 56f\n"
    "sra $16, $16, 1\n"
    "ld $4, 0x0($18)\n"
    "jal func_00411FD8\n"
    "daddu $5, $17, $0\n"
    "daddu $17, $2, $0\n"
    "sra $16, $16, 1\n"
    "56:\n"
    "addiu $18, $18, 0x8\n"
    "slti $2, $16, 0x2\n"
    "beqz $2, 55b\n"
    "addiu $19, $19, 0x1\n"
    "57:\n"
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
    "bnez $2, 62f\n"
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
    "bnez $2, 61f\n"
    "addiu $17, $0, 0x1\n"
    "58:\n"
    "addiu $2, $0, 0x22\n"
    "59:\n"
    "sw $2, 0x0($23)\n"
    "lw $3, 0x38($29)\n"
    "bnez $3, 96f\n"
    "daddu $17, $0, $0\n"
    "b 99f\n"
    "lw $4, 0x8($29)\n"
    "60:\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "b 96f\n"
    "daddu $17, $2, $0\n"
    "61:\n"
    "lw $5, 0x18($29)\n"
    "62:\n"
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
    "b 84f\n"
    "sw $7, 0x48($29)\n"
    "nop\n"
    "63:\n"
    "daddu $4, $23, $0\n"
    "jal func_00420CC8\n"
    "addiu $6, $0, 0x1\n"
    "sw $2, 0x40($29)\n"
    "lw $5, 0x3C($29)\n"
    "jal func_00420E28\n"
    "daddu $4, $2, $0\n"
    "bgtz $2, 66f\n"
    "lw $5, 0x30($29)\n"
    "b 97f\n"
    "nop\n"
    "64:\n"
    "bnez $7, 68f\n"
    "lw $4, 0x40($29)\n"
    "beqz $20, 65f\n"
    "nop\n"
    "addiu $3, $0, -0x1\n"
    "dsrl $3, $3, 12\n"
    "and $2, $17, $3\n"
    "bne $2, $3, 67f\n"
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
    "b 96f\n"
    "and $17, $17, $3\n"
    "65:\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    "bnez $2, 67f\n"
    "nop\n"
    "66:\n"
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
    "b 96f\n"
    "or $17, $17, $5\n"
    "67:\n"
    "dsll32 $2, $17, 0\n"
    "dsra32 $2, $2, 0\n"
    "andi $2, $2, 0x1\n"
    "beqz $2, 97f\n"
    "lw $5, 0x30($29)\n"
    "bnez $20, 60b\n"
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
    "beqz $2, 58b\n"
    "lw $5, 0x30($29)\n"
    "b 97f\n"
    "nop\n"
    "68:\n"
    "jal func_00421400\n"
    "lw $5, 0x3C($29)\n"
    "daddu $16, $2, $0\n"
    "ori $5, $0, 0x8000\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bgtz $2, 72f\n"
    "nop\n"
    "beqz $20, 69f\n"
    "nop\n"
    "ori $16, $0, 0xFFC0\n"
    "dsll32 $16, $16, 14\n"
    "b 75f\n"
    "daddu $18, $16, $0\n"
    "69:\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    "beqz $2, 70f\n"
    "addiu $2, $0, 0x1\n"
    "beq $17, $2, 59b\n"
    "addiu $2, $0, 0x22\n"
    "ori $16, $0, 0xFFC0\n"
    "dsll32 $16, $16, 14\n"
    "ori $18, $0, 0xBFF0\n"
    "dsll32 $18, $18, 16\n"
    "b 75f\n"
    "nop\n"
    "70:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bgez $2, 71f\n"
    "daddu $4, $0, $0\n"
    "ori $16, $0, 0xFF80\n"
    "dsll32 $16, $16, 14\n"
    "b 74f\n"
    "nop\n"
    "71:\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $16, $0\n"
    "b 73f\n"
    "daddu $16, $2, $0\n"
    "72:\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411FD8\n"
    "daddu $4, $16, $0\n"
    "daddu $16, $2, $0\n"
    "bnez $20, 75f\n"
    "daddu $18, $16, $0\n"
    "73:\n"
    "daddu $4, $0, $0\n"
    "74:\n"
    "jal func_00411F70\n"
    "daddu $5, $16, $0\n"
    "daddu $18, $2, $0\n"
    "75:\n"
    "dsra32 $3, $17, 0\n"
    "lui $30, (0x7FF00000 >> 16)\n"
    "and $2, $3, $30\n"
    "sw $2, 0x20($29)\n"
    "lui $2, (0x7FE00000 >> 16)\n"
    "lw $4, 0x20($29)\n"
    "bne $4, $2, 77f\n"
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
    "beqz $3, 76f\n"
    "lui $2, (0x3500000 >> 16)\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFF\n"
    "dsll $2, $2, 15\n"
    "ori $2, $2, 0x7FFF\n"
    "beq $22, $2, 46b\n"
    "and $17, $17, $19\n"
    "ori $2, $0, 0xFFDF\n"
    "dsll $2, $2, 16\n"
    "ori $2, $2, 0xFFFE\n"
    "dsll $2, $2, 31\n"
    "or $17, $17, $2\n"
    "b 82f\n"
    "or $17, $17, $19\n"
    "76:\n"
    "and $17, $17, $19\n"
    "addu $2, $4, $2\n"
    "dsll32 $2, $2, 0\n"
    "b 79f\n"
    "or $17, $17, $2\n"
    "77:\n"
    "lui $2, (0x3400000 >> 16)\n"
    "sltu $2, $2, $7\n"
    "bnez $2, 78f\n"
    "nop\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bltz $2, 78f\n"
    "nop\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00411F18\n"
    "daddu $4, $16, $0\n"
    "jal func_00412608\n"
    "daddu $4, $2, $0\n"
    "jal func_00412550\n"
    "daddu $4, $2, $0\n"
    "bnez $20, 78f\n"
    "daddu $18, $2, $0\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    "daddu $18, $2, $0\n"
    "78:\n"
    "jal func_00421020\n"
    "daddu $4, $17, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00411FD8\n"
    "daddu $5, $2, $0\n"
    "daddu $5, $17, $0\n"
    "jal func_00411F18\n"
    "daddu $4, $2, $0\n"
    "daddu $17, $2, $0\n"
    "79:\n"
    "lw $3, 0x20($29)\n"
    "dsra32 $4, $17, 0\n"
    "dsll32 $2, $3, 0\n"
    "lui $3, (0x7FF00000 >> 16)\n"
    "dsrl32 $2, $2, 0\n"
    "and $18, $4, $3\n"
    "bne $2, $18, 83f\n"
    "lw $5, 0x30($29)\n"
    "jal func_0042D320\n"
    "daddu $4, $16, $0\n"
    "jal func_00411438\n"
    "daddu $4, $2, $0\n"
    "daddu $4, $16, $0\n"
    "jal func_00411F70\n"
    "daddu $5, $2, $0\n"
    "bnez $20, 80f\n"
    "daddu $16, $2, $0\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    "beqz $2, 81f\n"
    "nop\n"
    "80:\n"
    "ori $5, $0, 0xFF7F\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFFFE\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xA501\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1595\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bltz $2, 97f\n"
    "lw $5, 0x30($29)\n"
    "ori $5, $0, 0xFF80\n"
    "dsll32 $5, $5, 0\n"
    "ori $5, $5, 0xD6BF\n"
    "dsll $5, $5, 14\n"
    "ori $5, $5, 0x2535\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bgtz $2, 96f\n"
    "lw $5, 0x30($29)\n"
    "b 83f\n"
    "nop\n"
    "81:\n"
    "ori $5, $0, 0xFF3F\n"
    "dsll $5, $5, 16\n"
    "ori $5, $5, 0xFFFE\n"
    "dsll $5, $5, 17\n"
    "ori $5, $5, 0xA501\n"
    "dsll $5, $5, 13\n"
    "ori $5, $5, 0x1595\n"
    "jal func_00412500\n"
    "daddu $4, $16, $0\n"
    "bltzl $2, 97f\n"
    "lw $5, 0x30($29)\n"
    "82:\n"
    "lw $5, 0x30($29)\n"
    "83:\n"
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
    "84:\n"
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
    "bltz $2, 85f\n"
    "lw $16, 0x44($29)\n"
    "daddu $6, $0, $0\n"
    "daddu $18, $0, $0\n"
    "b 86f\n"
    "daddu $22, $16, $0\n"
    "85:\n"
    "lw $3, 0x44($29)\n"
    "daddu $22, $0, $0\n"
    "daddu $16, $0, $0\n"
    "negu $18, $3\n"
    "daddu $6, $18, $0\n"
    "86:\n"
    "lw $4, 0x0($29)\n"
    "bltzl $4, 87f\n"
    "subu $16, $16, $4\n"
    "addu $18, $18, $4\n"
    "87:\n"
    "lw $5, 0x4($29)\n"
    "addu $2, $4, $5\n"
    "addiu $7, $2, -0x1\n"
    "slti $3, $7, -0x3FE\n"
    "beqz $3, 88f\n"
    "daddu $20, $18, $0\n"
    "b 89f\n"
    "addiu $19, $4, 0x433\n"
    "88:\n"
    "addiu $2, $0, 0x36\n"
    "subu $19, $2, $5\n"
    "89:\n"
    "addu $7, $16, $19\n"
    "addu $18, $18, $19\n"
    "daddu $16, $7, $0\n"
    "slt $2, $18, $7\n"
    "movn $7, $18, $2\n"
    "slt $3, $20, $7\n"
    "movn $7, $20, $3\n"
    "blez $7, 90f\n"
    "nop\n"
    "subu $20, $20, $7\n"
    "subu $18, $18, $7\n"
    "subu $16, $16, $7\n"
    "90:\n"
    "blez $6, 91f\n"
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
    "91:\n"
    "blez $18, 92f\n"
    "lw $5, 0x30($29)\n"
    "daddu $6, $18, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x30($29)\n"
    "92:\n"
    "blez $22, 93f\n"
    "lw $5, 0x34($29)\n"
    "daddu $6, $22, $0\n"
    "jal func_00420BC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x34($29)\n"
    "93:\n"
    "blez $16, 94f\n"
    "lw $5, 0x34($29)\n"
    "daddu $6, $16, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x34($29)\n"
    "94:\n"
    "blez $20, 95f\n"
    "lw $5, 0x3C($29)\n"
    "daddu $6, $20, $0\n"
    "jal func_00420CC8\n"
    "daddu $4, $23, $0\n"
    "sw $2, 0x3C($29)\n"
    "95:\n"
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
    "bgez $7, 64b\n"
    "nop\n"
    "bnez $20, 97f\n"
    "lw $5, 0x30($29)\n"
    "addiu $2, $0, -0x1\n"
    "dsrl $2, $2, 12\n"
    "and $2, $17, $2\n"
    "beqz $2, 63b\n"
    "lw $5, 0x40($29)\n"
    "96:\n"
    "lw $5, 0x30($29)\n"
    "97:\n"
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
    "98:\n"
    "lw $4, 0x8($29)\n"
    "99:\n"
    "bnel $4, $0, 100f\n"
    "sw $21, 0x0($4)\n"
    "100:\n"
    "lw $7, 0xC($29)\n"
    "beqz $7, 101f\n"
    "daddu $2, $17, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    "101:\n"
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
    "bnez $2, 2f\n"
    "lb $3, 0x0($5)\n"
    "daddu $2, $0, $0\n"
    "jr $31\n"
    "movz $2, $4, $3\n"
    "1:\n"
    "jr $31\n"
    "daddu $2, $4, $0\n"
    "2:\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beqz $3, 1b\n"
    "daddu $7, $0, $0\n"
    "lb $2, 0x0($4)\n"
    "bnel $3, $2, 4f\n"
    "addiu $4, $4, 0x1\n"
    "addiu $7, $7, 0x1\n"
    "nop\n"
    "3:\n"
    "addu $2, $5, $7\n"
    "lb $6, 0x0($2)\n"
    "beqz $6, 1b\n"
    "addu $2, $4, $7\n"
    "lb $3, 0x0($2)\n"
    "beql $6, $3, 3b\n"
    "addiu $7, $7, 0x1\n"
    "addiu $4, $4, 0x1\n"
    "4:\n"
    "lb $2, 0x0($4)\n"
    "bnel $2, $0, 2b\n"
    "lb $3, 0x0($5)\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".end func_0041AD80\n"
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
    "blez $5, 4f\n"
    "addiu $5, $5, -0x1\n"
    "addu $3, $4, $5\n"
    "lb $2, 0x0($3)\n"
    "slti $2, $2, 0x35\n"
    "bnez $2, 4f\n"
    "addiu $7, $0, 0x30\n"
    "addiu $6, $0, 0x39\n"
    "sb $7, 0x0($3)\n"
    "nop\n"
    "1:\n"
    "addiu $5, $5, -0x1\n"
    "blez $5, 2f\n"
    "addiu $3, $3, -0x1\n"
    "lb $2, 0x0($3)\n"
    "nop\n"
    "beql $2, $6, 1b\n"
    "sb $7, 0x0($3)\n"
    "2:\n"
    "addu $4, $4, $5\n"
    "addiu $3, $0, 0x39\n"
    "lb $2, 0x0($4)\n"
    "bne $2, $3, 3f\n"
    "lbu $5, 0x0($4)\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    "3:\n"
    "addiu $2, $5, 0x1\n"
    "sb $2, 0x0($4)\n"
    "4:\n"
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
    "beqz $10, 1f\n"
    "sd $31, 0x0($29)\n"
    "negu $3, $4\n"
    "xori $2, $6, 0xA\n"
    "movz $4, $3, $2\n"
    "1:\n"
    "lui $2, %hi(D_00454CB0)\n"
    "daddu $7, $0, $0\n"
    "addiu $11, $2, %lo(D_00454CB0)\n"
    "daddu $8, $0, $0\n"
    "divu $0, $4, $6\n"
    "nop\n"
    "2:\n"
    "beql $6, $8, 3f\n"
    "break 0, 7\n"
    "3:\n"
    "addu $5, $9, $7\n"
    "addiu $7, $7, 0x1\n"
    "mfhi $3\n"
    "mflo $4\n"
    "addu $3, $3, $11\n"
    "lbu $2, 0x0($3)\n"
    "sb $2, 0x0($5)\n"
    "beql $6, $8, 4f\n"
    "break 0, 7\n"
    "4:\n"
    "bnel $4, $0, 2b\n"
    "divu $0, $4, $6\n"
    "beqz $10, 5f\n"
    "addu $3, $9, $7\n"
    "addiu $2, $0, 0x2D\n"
    "sb $2, 0x0($3)\n"
    "addiu $7, $7, 0x1\n"
    "5:\n"
    "addu $2, $9, $7\n"
    "daddu $4, $9, $0\n"
    "jal func_0041AE70\n"
    "sb $0, 0x0($2)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x10\n"
    ".end func_0041AEE8\n"
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
    "bne $4, $2, 5f\n"
    "daddu $16, $8, $0\n"
    "bnez $3, 2f\n"
    "lui $2, %hi(D_0049A310)\n"
    "bnez $6, 3f\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "beqz $5, 1f\n"
    "lui $3, %hi(D_0049A300)\n"
    "lui $2, %hi(D_0052ADF0)\n"
    "lw $5, %lo(D_0049A300)($3)\n"
    "addiu $4, $3, %lo(D_0049A300)\n"
    "lbu $6, 0x4($4)\n"
    "addiu $3, $2, %lo(D_0052ADF0)\n"
    "sw $5, %lo(D_0052ADF0)($2)\n"
    "b 40f\n"
    "sb $6, 0x4($3)\n"
    "1:\n"
    "lui $2, %hi(D_0049A308)\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "b 4f\n"
    "lw $4, %lo(D_0049A308)($2)\n"
    "2:\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "3:\n"
    "lw $4, %lo(D_0049A310)($2)\n"
    "4:\n"
    "b 40f\n"
    "sw $4, %lo(D_0052ADF0)($3)\n"
    "5:\n"
    "lw $21, 0x0($29)\n"
    "daddu $20, $0, $0\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    "bgez $2, 8f\n"
    "lui $2, %hi(D_0052ADF0)\n"
    "beqz $16, 6f\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "addiu $2, $0, 0x2D\n"
    "sb $2, 0x0($16)\n"
    "b 7f\n"
    "addiu $22, $3, %lo(D_0052ADF0)\n"
    "6:\n"
    "addiu $3, $0, 0x2D\n"
    "addiu $4, $2, %lo(D_0052ADF0)\n"
    "sb $3, %lo(D_0052ADF0)($2)\n"
    "addiu $22, $4, 0x1\n"
    "7:\n"
    "daddu $5, $18, $0\n"
    "jal func_00411F70\n"
    "daddu $4, $0, $0\n"
    "b 9f\n"
    "daddu $18, $2, $0\n"
    "8:\n"
    "addiu $22, $2, %lo(D_0052ADF0)\n"
    "9:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    "bltz $2, 14f\n"
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
    "10:\n"
    "beqz $2, 11f\n"
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
    "bgez $2, 10b\n"
    "slti $2, $20, 0xA3\n"
    "11:\n"
    "addiu $7, $20, -0x1\n"
    "blez $7, 13f\n"
    "daddu $16, $0, $0\n"
    "addu $6, $7, $22\n"
    "daddu $5, $22, $0\n"
    "nop\n"
    "12:\n"
    "lbu $2, 0x0($6)\n"
    "addiu $16, $16, 0x1\n"
    "lb $3, 0x0($5)\n"
    "addiu $7, $7, -0x1\n"
    "sb $2, 0x0($5)\n"
    "slt $4, $16, $7\n"
    "sb $3, 0x0($6)\n"
    "addiu $5, $5, 0x1\n"
    "bnez $4, 12b\n"
    "addiu $6, $6, -0x1\n"
    "13:\n"
    "daddu $19, $20, $0\n"
    "14:\n"
    "bnez $19, 19f\n"
    "lw $3, 0x4($29)\n"
    "addiu $2, $0, 0x66\n"
    "beq $3, $2, 18f\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $0, $0\n"
    "beqz $2, 17f\n"
    "nop\n"
    "15:\n"
    "ori $5, $0, 0x8048\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00411FD8\n"
    "daddu $4, $18, $0\n"
    "daddu $18, $2, $0\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    "bgez $2, 16f\n"
    "slti $2, $19, -0x3FC\n"
    "beql $2, $0, 15b\n"
    "addiu $19, $19, -0x1\n"
    "16:\n"
    "addiu $19, $19, -0x1\n"
    "17:\n"
    "ori $5, $0, 0xFFC0\n"
    "dsll32 $5, $5, 14\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    "bltz $2, 19f\n"
    "lw $2, 0x0($29)\n"
    "daddu $4, $18, $0\n"
    "ori $5, $0, 0x8048\n"
    "dsll32 $5, $5, 15\n"
    "jal func_00412280\n"
    "addiu $21, $2, 0x1\n"
    "b 19f\n"
    "daddu $18, $2, $0\n"
    "18:\n"
    "addiu $2, $0, 0x30\n"
    "addiu $20, $0, 0x1\n"
    "sb $2, 0x0($22)\n"
    "19:\n"
    "bgez $19, 20f\n"
    "lw $3, 0x4($29)\n"
    "b 21f\n"
    "daddu $17, $21, $0\n"
    "20:\n"
    "addiu $2, $0, 0x66\n"
    "bne $3, $2, 21f\n"
    "addiu $17, $21, 0x1\n"
    "addiu $2, $0, 0x1\n"
    "slt $3, $0, $19\n"
    "movn $2, $19, $3\n"
    "addu $17, $21, $2\n"
    "21:\n"
    "ori $21, $0, 0xF240\n"
    "dsll32 $21, $21, 14\n"
    "addiu $30, $17, 0x1\n"
    "ori $23, $0, 0x8048\n"
    "dsll32 $23, $23, 15\n"
    "22:\n"
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
    "beqz $2, 23f\n"
    "daddu $4, $18, $0\n"
    "jal func_00412500\n"
    "daddu $5, $21, $0\n"
    "bltz $2, 23f\n"
    "nop\n"
    "ori $4, $0, 0xFFC0\n"
    "dsll32 $4, $4, 14\n"
    "jal func_00411F70\n"
    "daddu $5, $21, $0\n"
    "daddu $5, $2, $0\n"
    "jal func_00412500\n"
    "daddu $4, $18, $0\n"
    "bgtz $2, 23f\n"
    "addu $2, $22, $20\n"
    "addiu $3, $16, 0x30\n"
    "sb $3, 0x0($2)\n"
    "b 22b\n"
    "addiu $20, $20, 0x1\n"
    "23:\n"
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
    "bnez $2, 25f\n"
    "sb $3, 0x0($4)\n"
    "addiu $4, $0, 0x30\n"
    "nop\n"
    "24:\n"
    "addu $3, $22, $20\n"
    "addiu $20, $20, 0x1\n"
    "slt $2, $17, $20\n"
    "nop\n"
    "nop\n"
    "beqz $2, 24b\n"
    "sb $4, 0x0($3)\n"
    "25:\n"
    "daddu $4, $22, $0\n"
    "jal func_0041AE00\n"
    "daddu $5, $30, $0\n"
    "bnez $2, 26f\n"
    "lw $2, 0x0($29)\n"
    "addiu $2, $0, 0x31\n"
    "daddu $17, $30, $0\n"
    "sb $2, 0x0($22)\n"
    "addiu $19, $19, 0x1\n"
    "lw $2, 0x0($29)\n"
    "26:\n"
    "beqz $2, 30f\n"
    "lw $3, 0x4($29)\n"
    "addiu $2, $0, 0x66\n"
    "bne $3, $2, 27f\n"
    "addiu $5, $0, 0x1\n"
    "slti $2, $19, 0x1\n"
    "movz $5, $19, $2\n"
    "27:\n"
    "daddu $20, $17, $0\n"
    "slt $2, $5, $17\n"
    "beqz $2, 29f\n"
    "addu $6, $22, $5\n"
    "addu $4, $17, $22\n"
    "nop\n"
    "28:\n"
    "lbu $2, -0x1($4)\n"
    "addiu $20, $20, -0x1\n"
    "slt $3, $5, $20\n"
    "sb $2, 0x0($4)\n"
    "nop\n"
    "bnez $3, 28b\n"
    "addiu $4, $4, -0x1\n"
    "29:\n"
    "addiu $2, $0, 0x2E\n"
    "b 31f\n"
    "sb $2, 0x0($6)\n"
    "30:\n"
    "addiu $17, $17, -0x1\n"
    "31:\n"
    "lw $2, 0x8($29)\n"
    "beqz $2, 35f\n"
    "lw $3, 0x4($29)\n"
    "beqz $17, 33f\n"
    "addu $2, $22, $17\n"
    "addiu $4, $0, 0x30\n"
    "lb $3, 0x0($2)\n"
    "bnel $3, $4, 34f\n"
    "addiu $4, $17, -0x1\n"
    "addiu $17, $17, -0x1\n"
    "nop\n"
    "32:\n"
    "beqz $17, 33f\n"
    "addu $2, $22, $17\n"
    "lb $3, 0x0($2)\n"
    "nop\n"
    "nop\n"
    "beql $3, $4, 32b\n"
    "addiu $17, $17, -0x1\n"
    "33:\n"
    "addu $2, $22, $17\n"
    "addiu $4, $17, -0x1\n"
    "lb $3, 0x0($2)\n"
    "34:\n"
    "xori $3, $3, 0x2E\n"
    "movz $17, $4, $3\n"
    "lw $3, 0x4($29)\n"
    "35:\n"
    "addiu $2, $0, 0x66\n"
    "beq $3, $2, 39f\n"
    "addu $2, $17, $22\n"
    "addiu $17, $17, 0x1\n"
    "addu $2, $22, $17\n"
    "bltz $19, 36f\n"
    "sb $3, 0x0($2)\n"
    "addiu $2, $19, -0x1\n"
    "addiu $17, $17, 0x1\n"
    "movn $19, $2, $19\n"
    "addu $4, $22, $17\n"
    "addiu $2, $0, 0x2B\n"
    "slti $3, $19, 0xA\n"
    "beqz $3, 38f\n"
    "sb $2, 0x0($4)\n"
    "addiu $17, $17, 0x1\n"
    "addiu $3, $0, 0x30\n"
    "addu $2, $22, $17\n"
    "b 38f\n"
    "sb $3, 0x0($2)\n"
    "36:\n"
    "addiu $17, $17, 0x1\n"
    "addiu $2, $0, 0x2D\n"
    "addu $3, $22, $17\n"
    "slti $4, $19, -0x9\n"
    "bnez $4, 37f\n"
    "sb $2, 0x0($3)\n"
    "addiu $17, $17, 0x1\n"
    "addiu $3, $0, 0x30\n"
    "addu $2, $22, $17\n"
    "sb $3, 0x0($2)\n"
    "37:\n"
    "negu $19, $19\n"
    "38:\n"
    "addiu $17, $17, 0x1\n"
    "daddu $4, $19, $0\n"
    "addu $5, $22, $17\n"
    "jal func_0041AEE8\n"
    "addiu $6, $0, 0xA\n"
    "b 41f\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "39:\n"
    "sb $0, 0x1($2)\n"
    "40:\n"
    "lui $3, %hi(D_0052ADF0)\n"
    "41:\n"
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

INCLUDE_ASM("seg/seg_316FB8", func_0041B728);

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

INCLUDE_ASM("seg/seg_316FB8", func_0041CA70);

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
    "bnez $2, 1f\n"
    "sd $31, 0x0($29)\n"
    "lui $2, (0xFFFFFFF0 >> 16)\n"
    "ori $2, $2, (0xFFFFFFF0 & 0xFFFF)\n"
    "b 2f\n"
    "and $17, $5, $2\n"
    "1:\n"
    "addiu $17, $0, 0x10\n"
    "2:\n"
    "jal func_00418CA8\n"
    "daddu $4, $19, $0\n"
    "sltiu $2, $17, 0x1F8\n"
    "beqz $2, 4f\n"
    "lui $2, %hi(D_00454CE8)\n"
    "srl $10, $17, 3\n"
    "addiu $3, $2, %lo(D_00454CE8)\n"
    "addu $9, $17, $3\n"
    "lw $16, 0xC($9)\n"
    "beq $16, $9, 3f\n"
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
    "b 57f\n"
    "ori $2, $2, 0x1\n"
    "3:\n"
    "b 15f\n"
    "addiu $10, $10, 0x2\n"
    "4:\n"
    "srl $4, $17, 9\n"
    "bnez $4, 5f\n"
    "sltiu $2, $4, 0x5\n"
    "b 10f\n"
    "srl $10, $17, 3\n"
    "5:\n"
    "beqz $2, 6f\n"
    "srl $2, $17, 6\n"
    "b 10f\n"
    "addiu $10, $2, 0x38\n"
    "6:\n"
    "sltiu $2, $4, 0x15\n"
    "bnez $2, 10f\n"
    "addiu $10, $4, 0x5B\n"
    "sltiu $2, $4, 0x55\n"
    "beqz $2, 7f\n"
    "srl $2, $17, 12\n"
    "b 10f\n"
    "addiu $10, $2, 0x6E\n"
    "7:\n"
    "sltiu $2, $4, 0x155\n"
    "beqz $2, 8f\n"
    "srl $2, $17, 15\n"
    "b 10f\n"
    "addiu $10, $2, 0x77\n"
    "8:\n"
    "sltiu $2, $4, 0x555\n"
    "beqz $2, 9f\n"
    "srl $2, $17, 18\n"
    "b 10f\n"
    "addiu $10, $2, 0x7C\n"
    "9:\n"
    "addiu $10, $0, 0x7E\n"
    "10:\n"
    "lui $2, %hi(D_00454CE8)\n"
    "sll $4, $10, 3\n"
    "addiu $3, $2, %lo(D_00454CE8)\n"
    "addu $8, $4, $3\n"
    "lw $16, 0xC($8)\n"
    "b 12f\n"
    "daddu $20, $2, $0\n"
    "nop\n"
    "11:\n"
    "bgezl $7, 53f\n"
    "lw $8, 0xC($16)\n"
    "lw $16, 0xC($16)\n"
    "12:\n"
    "beql $16, $8, 15f\n"
    "addiu $10, $10, 0x1\n"
    "lw $2, 0x4($16)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "and $5, $2, $3\n"
    "sltu $4, $5, $17\n"
    "beqz $4, 13f\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    "b 14f\n"
    "dsubu $7, $0, $2\n"
    "13:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    "14:\n"
    "slti $2, $7, 0x10\n"
    "bnez $2, 11b\n"
    "nop\n"
    "addiu $10, $10, -0x1\n"
    "addiu $10, $10, 0x1\n"
    "15:\n"
    "lui $2, %hi(D_00454CF0)\n"
    "daddu $14, $2, $0\n"
    "addiu $2, $2, %lo(D_00454CF0)\n"
    "lw $16, 0x8($2)\n"
    "beq $16, $2, 30f\n"
    "addiu $2, $0, -0x1\n"
    "lw $2, 0x4($16)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "and $5, $2, $3\n"
    "sltu $4, $5, $17\n"
    "beqz $4, 16f\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    "b 17f\n"
    "dsubu $7, $0, $2\n"
    "16:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    "17:\n"
    "slti $2, $7, 0x10\n"
    "bnez $2, 18f\n"
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
    "b 58f\n"
    "sw $2, 0x0($6)\n"
    "18:\n"
    "sw $4, 0xC($4)\n"
    "bltz $7, 19f\n"
    "sw $4, 0x8($4)\n"
    "addu $3, $16, $5\n"
    "daddu $4, $19, $0\n"
    "lw $2, 0x4($3)\n"
    "b 57f\n"
    "ori $2, $2, 0x1\n"
    "19:\n"
    "sltiu $2, $5, 0x200\n"
    "beqz $2, 20f\n"
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
    "b 29f\n"
    "lw $6, 0x8($8)\n"
    "20:\n"
    "srl $3, $5, 9\n"
    "bnez $3, 21f\n"
    "sltiu $2, $3, 0x5\n"
    "b 26f\n"
    "srl $7, $5, 3\n"
    "21:\n"
    "beqz $2, 22f\n"
    "srl $2, $5, 6\n"
    "b 26f\n"
    "addiu $7, $2, 0x38\n"
    "22:\n"
    "sltiu $2, $3, 0x15\n"
    "bnez $2, 26f\n"
    "addiu $7, $3, 0x5B\n"
    "sltiu $2, $3, 0x55\n"
    "beqz $2, 23f\n"
    "srl $2, $5, 12\n"
    "b 26f\n"
    "addiu $7, $2, 0x6E\n"
    "23:\n"
    "sltiu $2, $3, 0x155\n"
    "beqz $2, 24f\n"
    "srl $2, $5, 15\n"
    "b 26f\n"
    "addiu $7, $2, 0x77\n"
    "24:\n"
    "sltiu $2, $3, 0x555\n"
    "beqz $2, 25f\n"
    "srl $2, $5, 18\n"
    "b 26f\n"
    "addiu $7, $2, 0x7C\n"
    "25:\n"
    "addiu $7, $0, 0x7E\n"
    "26:\n"
    "sll $2, $7, 3\n"
    "addiu $9, $20, %lo(D_00454CE8)\n"
    "addu $8, $2, $9\n"
    "lw $6, 0x8($8)\n"
    "bnel $6, $8, 27f\n"
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
    "b 29f\n"
    "sw $5, 0x4($9)\n"
    "27:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "and $3, $3, $2\n"
    "sltu $3, $5, $3\n"
    "beql $3, $0, 29f\n"
    "lw $8, 0xC($6)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $6, 0x8($6)\n"
    "28:\n"
    "beql $6, $8, 29f\n"
    "lw $8, 0xC($6)\n"
    "lw $2, 0x4($6)\n"
    "and $2, $2, $3\n"
    "sltu $2, $5, $2\n"
    "bnel $2, $0, 28b\n"
    "lw $6, 0x8($6)\n"
    "lw $8, 0xC($6)\n"
    "29:\n"
    "sw $8, 0xC($16)\n"
    "sw $6, 0x8($16)\n"
    "sw $16, 0x8($8)\n"
    "sw $16, 0xC($6)\n"
    "addiu $2, $0, -0x1\n"
    "30:\n"
    "addiu $4, $10, 0x3\n"
    "slt $2, $2, $10\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "movn $4, $10, $2\n"
    "lwu $5, 0x4($3)\n"
    "sra $4, $4, 2\n"
    "addiu $2, $0, 0x1\n"
    "dsllv $6, $2, $4\n"
    "sltu $3, $5, $6\n"
    "bnez $3, 46f\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "and $2, $6, $5\n"
    "bnez $2, 33f\n"
    "lui $2, %hi(D_00454CE8)\n"
    "addiu $2, $0, -0x4\n"
    "dsll $6, $6, 1\n"
    "and $2, $10, $2\n"
    "and $3, $6, $5\n"
    "bnez $3, 32f\n"
    "addiu $10, $2, 0x4\n"
    "daddu $3, $5, $0\n"
    "31:\n"
    "dsll $6, $6, 1\n"
    "and $2, $6, $3\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beqz $2, 31b\n"
    "addiu $10, $10, 0x4\n"
    "32:\n"
    "lui $2, %hi(D_00454CE8)\n"
    "33:\n"
    "addiu $12, $2, %lo(D_00454CE8)\n"
    "daddu $13, $12, $0\n"
    "sll $2, $10, 3\n"
    "nop\n"
    "34:\n"
    "daddu $11, $10, $0\n"
    "addu $9, $2, $12\n"
    "daddu $8, $9, $0\n"
    "lw $16, 0xC($8)\n"
    "35:\n"
    "beq $16, $8, 39f\n"
    "slti $2, $10, 0x3F\n"
    "lui $4, (0xFFFFFFFC >> 16)\n"
    "ori $4, $4, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($16)\n"
    "nop\n"
    "36:\n"
    "and $5, $2, $4\n"
    "sltu $3, $5, $17\n"
    "beqz $3, 37f\n"
    "subu $2, $17, $5\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    "b 38f\n"
    "dsubu $7, $0, $2\n"
    "37:\n"
    "subu $2, $5, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    "38:\n"
    "slti $2, $7, 0x10\n"
    "beql $2, $0, 54f\n"
    "lw $8, 0xC($16)\n"
    "bgez $7, 55f\n"
    "addu $3, $16, $5\n"
    "lw $16, 0xC($16)\n"
    "bnel $16, $8, 36b\n"
    "lw $2, 0x4($16)\n"
    "slti $2, $10, 0x3F\n"
    "39:\n"
    "beqz $2, 40f\n"
    "addiu $8, $8, 0x8\n"
    "addiu $8, $8, 0x8\n"
    "addiu $10, $10, 0x1\n"
    "40:\n"
    "addiu $10, $10, 0x1\n"
    "andi $2, $10, 0x3\n"
    "bnel $2, $0, 35b\n"
    "lw $16, 0xC($8)\n"
    "41:\n"
    "andi $2, $11, 0x3\n"
    "beqz $2, 44f\n"
    "addiu $9, $9, -0x8\n"
    "lw $2, 0x8($9)\n"
    "nop\n"
    "beq $2, $9, 41b\n"
    "addiu $11, $11, -0x1\n"
    "42:\n"
    "lwu $3, 0x4($12)\n"
    "dsll $6, $6, 1\n"
    "sltu $2, $3, $6\n"
    "bnel $2, $0, 46f\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "beqz $6, 45f\n"
    "and $2, $6, $3\n"
    "bnez $2, 34b\n"
    "sll $2, $10, 3\n"
    "lwu $3, 0x4($13)\n"
    "nop\n"
    "43:\n"
    "dsll $6, $6, 1\n"
    "and $2, $6, $3\n"
    "nop\n"
    "nop\n"
    "nop\n"
    "beqz $2, 43b\n"
    "addiu $10, $10, 0x4\n"
    "b 34b\n"
    "sll $2, $10, 3\n"
    "44:\n"
    "lw $3, 0x4($12)\n"
    "dsll32 $2, $6, 0\n"
    "dsra32 $2, $2, 0\n"
    "nor $2, $0, $2\n"
    "and $3, $3, $2\n"
    "b 42b\n"
    "sw $3, 0x4($12)\n"
    "45:\n"
    "addiu $3, $20, %lo(D_00454CE8)\n"
    "46:\n"
    "lui $2, (0xFFFFFFFC >> 16)\n"
    "lw $4, 0x8($3)\n"
    "ori $2, $2, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $3, 0x4($4)\n"
    "and $2, $3, $2\n"
    "sltu $4, $2, $17\n"
    "beql $4, $0, 47f\n"
    "subu $2, $2, $17\n"
    "subu $2, $17, $2\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    "b 48f\n"
    "dsubu $7, $0, $2\n"
    "47:\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    "48:\n"
    "addiu $18, $20, %lo(D_00454CE8)\n"
    "lui $16, (0xFFFFFFFC >> 16)\n"
    "lw $3, 0x8($18)\n"
    "ori $16, $16, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($3)\n"
    "and $2, $2, $16\n"
    "sltu $2, $2, $17\n"
    "bnez $2, 49f\n"
    "daddu $4, $19, $0\n"
    "slti $2, $7, 0x10\n"
    "beqz $2, 56f\n"
    "addiu $6, $20, %lo(D_00454CE8)\n"
    "49:\n"
    "jal func_0041D990\n"
    "daddu $5, $17, $0\n"
    "lw $2, 0x8($18)\n"
    "lw $3, 0x4($2)\n"
    "and $3, $3, $16\n"
    "sltu $2, $3, $17\n"
    "beqz $2, 50f\n"
    "subu $2, $17, $3\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $2, $2, 0\n"
    "b 51f\n"
    "dsubu $7, $0, $2\n"
    "50:\n"
    "subu $2, $3, $17\n"
    "dsll32 $2, $2, 0\n"
    "dsrl32 $7, $2, 0\n"
    "51:\n"
    "addiu $2, $20, %lo(D_00454CE8)\n"
    "lui $3, (0xFFFFFFFC >> 16)\n"
    "lw $4, 0x8($2)\n"
    "ori $3, $3, (0xFFFFFFFC & 0xFFFF)\n"
    "lw $2, 0x4($4)\n"
    "and $2, $2, $3\n"
    "sltu $2, $2, $17\n"
    "bnez $2, 52f\n"
    "slti $2, $7, 0x10\n"
    "beqz $2, 56f\n"
    "addiu $6, $20, %lo(D_00454CE8)\n"
    "52:\n"
    "jal func_00418D08\n"
    "daddu $4, $19, $0\n"
    "b 59f\n"
    "daddu $2, $0, $0\n"
    "53:\n"
    "addu $3, $16, $5\n"
    "lw $6, 0x8($16)\n"
    "daddu $4, $19, $0\n"
    "sw $8, 0xC($6)\n"
    "sw $6, 0x8($8)\n"
    "lw $2, 0x4($3)\n"
    "b 57f\n"
    "ori $2, $2, 0x1\n"
    "54:\n"
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
    "b 58f\n"
    "sw $5, 0x0($6)\n"
    "55:\n"
    "daddu $4, $19, $0\n"
    "lw $2, 0x4($3)\n"
    "ori $2, $2, 0x1\n"
    "sw $2, 0x4($3)\n"
    "lw $8, 0xC($16)\n"
    "lw $6, 0x8($16)\n"
    "sw $8, 0xC($6)\n"
    "b 58f\n"
    "sw $6, 0x8($8)\n"
    "56:\n"
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
    "57:\n"
    "sw $2, 0x4($3)\n"
    "58:\n"
    "jal func_00418D08\n"
    "nop\n"
    "addiu $2, $16, 0x8\n"
    "59:\n"
    "lq $16, 0x50($29)\n"
    "lq $17, 0x40($29)\n"
    "lq $18, 0x30($29)\n"
    "lq $19, 0x20($29)\n"
    "lq $20, 0x10($29)\n"
    "ld $31, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x60\n"
    ".end func_0041DBF8\n"
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

INCLUDE_ASM("seg/seg_316FB8", func_0041E638);

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

INCLUDE_ASM("seg/seg_316FB8", func_0041EC70);

INCLUDE_ASM("seg/seg_316FB8", func_0041ED60);

INCLUDE_ASM("seg/seg_316FB8", func_0041EF50);

INCLUDE_ASM("seg/seg_316FB8", func_0041F3A8);

INCLUDE_ASM("seg/seg_316FB8", func_0041F9D8);

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

INCLUDE_ASM("seg/seg_316FB8", func_0041FE30);

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

INCLUDE_ASM("seg/seg_316FB8", func_00420010);

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

INCLUDE_ASM("seg/seg_316FB8", func_00420180);

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

INCLUDE_ASM("seg/seg_316FB8", ungetc);

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

INCLUDE_ASM("seg/seg_316FB8", func_00421400);

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

INCLUDE_ASM("seg/seg_316FB8", func_00421B98);

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

INCLUDE_ASM("seg/seg_316FB8", func_00422780);

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
