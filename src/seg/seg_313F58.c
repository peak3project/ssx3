#include "common.h"

//100%
INCLUDE_ASM("seg/seg_313F58", func_00412F58);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00412F58\n.type func_00412F58, @function\nfunc_00412F58:\n"
    "lw $3, 0x0($4)\n"
    "daddu $7, $0, $0\n"
    "lw $8, 0x4($4)\n"
    "sltiu $2, $3, 0x2\n"
    "beqz $2, 1f\n"
    "lw $5, 0xC($4)\n"
    "lui $2, (0x100000 >> 16)\n"
    "addiu $7, $0, 0xFF\n"
    "b 8f\n"
    "or $5, $5, $2\n"
    "1:\n"
    "xori $2, $3, 0x4\n"
    "beqz $2, 4f\n"
    "xori $2, $3, 0x2\n"
    "bnez $2, 2f\n"
    "nop\n"
    "b 8f\n"
    "daddu $5, $0, $0\n"
    "2:\n"
    "beqz $5, 9f\n"
    "lui $3, (0xFF800000 >> 16)\n"
    "lw $3, 0x8($4)\n"
    "slti $2, $3, -0x7E\n"
    "beqz $2, 3f\n"
    "addiu $2, $0, -0x7E\n"
    "subu $2, $2, $3\n"
    "slti $3, $2, 0x1A\n"
    "bnez $3, 7f\n"
    "srlv $5, $5, $2\n"
    "b 7f\n"
    "daddu $5, $0, $0\n"
    "3:\n"
    "slti $2, $3, 0x80\n"
    "bnez $2, 5f\n"
    "addiu $7, $3, 0x7F\n"
    "4:\n"
    "addiu $7, $0, 0xFF\n"
    "b 8f\n"
    "daddu $5, $0, $0\n"
    "5:\n"
    "addiu $2, $0, 0x40\n"
    "andi $3, $5, 0x7F\n"
    "bnel $3, $2, 6f\n"
    "addiu $5, $5, 0x3F\n"
    "andi $3, $5, 0x80\n"
    "addiu $2, $5, 0x40\n"
    "movn $5, $2, $3\n"
    "6:\n"
    "bgezl $5, 8f\n"
    "srl $5, $5, 7\n"
    "srl $5, $5, 1\n"
    "addiu $7, $7, 0x1\n"
    "7:\n"
    "srl $5, $5, 7\n"
    "8:\n"
    "lui $3, (0xFF800000 >> 16)\n"
    "9:\n"
    "lui $2, (0x7FFFFF >> 16)\n"
    "and $6, $6, $3\n"
    "ori $2, $2, (0x7FFFFF & 0xFFFF)\n"
    "and $2, $5, $2\n"
    "lui $3, (0x807FFFFF >> 16)\n"
    "or $6, $6, $2\n"
    "ori $3, $3, (0x807FFFFF & 0xFFFF)\n"
    "andi $4, $7, 0xFF\n"
    "and $6, $6, $3\n"
    "sll $4, $4, 23\n"
    "lui $2, (0x7FFFFFFF >> 16)\n"
    "or $6, $6, $4\n"
    "ori $2, $2, (0x7FFFFFFF & 0xFFFF)\n"
    "sll $3, $8, 31\n"
    "and $6, $6, $2\n"
    "or $6, $6, $3\n"
    "mtc1 $6, $f0\n"
    "jr $31\n"
    "nop\n"
    ".size func_00412F58, . - func_00412F58\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413068);
#ifdef SKIP_ASM
struct FB {
    unsigned m : 23;
    unsigned e : 8;
    unsigned s : 1;
};
void func_00413068(float *f, int *o) {
    struct FB *b = (struct FB *)f;
    unsigned m = b->m;
    int e = b->e;
    o[1] = b->s;
    if (e == 0) {
        o[0] = 2;
        return;
    }
    if (e == 0xFF) {
        if (m == 0) {
            o[0] = 4;
            return;
        }
        if (m & 0x100000)
            o[0] = 1;
        else
            o[0] = 0;
        o[3] = m;
        return;
    }
    o[2] = e - 0x7F;
    o[0] = 3;
    o[3] = (m << 7) | 0x40000000;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004130F8);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004130F8\n.type func_004130F8, @function\nfunc_004130F8:\n"
    "daddu $9, $4, $0\n"
    "lw $4, 0x0($9)\n"
    "sltiu $2, $4, 0x2\n"
    "beql $2, $0, 2f\n"
    "lw $3, 0x0($5)\n"
    "1:\n"
    "jr $31\n"
    "daddu $2, $9, $0\n"
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
    "lw $2, 0x4($9)\n"
    "beq $2, $3, 1b\n"
    "lui $2, %hi(D_0052ADD8)\n"
    "jr $31\n"
    "addiu $2, $2, %lo(D_0052ADD8)\n"
    "5:\n"
    "beqz $2, 3b\n"
    "xori $2, $3, 0x2\n"
    "bnez $2, 6f\n"
    "xori $2, $4, 0x2\n"
    "bnez $2, 1b\n"
    "nop\n"
    "ldl $2, 0x7($9)\n"
    "ldr $2, 0x0($9)\n"
    "ldl $3, 0xF($9)\n"
    "ldr $3, 0x8($9)\n"
    "sdl $2, 0x7($6)\n"
    "sdr $2, 0x0($6)\n"
    "sdl $3, 0xF($6)\n"
    "sdr $3, 0x8($6)\n"
    "lw $3, 0x4($9)\n"
    "daddu $2, $6, $0\n"
    "lw $4, 0x4($5)\n"
    "and $3, $3, $4\n"
    "jr $31\n"
    "sw $3, 0x4($6)\n"
    "6:\n"
    "beqz $2, 3b\n"
    "addiu $2, $0, -0x1\n"
    "lw $7, 0x8($9)\n"
    "lw $8, 0x8($5)\n"
    "lw $11, 0xC($9)\n"
    "subu $3, $7, $8\n"
    "slt $2, $2, $3\n"
    "negu $4, $3\n"
    "movz $3, $4, $2\n"
    "slti $3, $3, 0x20\n"
    "beqz $3, 11f\n"
    "lw $10, 0xC($5)\n"
    "slt $2, $8, $7\n"
    "beqz $2, 8f\n"
    "lw $9, 0x4($9)\n"
    "lw $5, 0x4($5)\n"
    "7:\n"
    "srl $2, $10, 1\n"
    "addiu $8, $8, 0x1\n"
    "andi $3, $10, 0x1\n"
    "slt $4, $8, $7\n"
    "or $10, $3, $2\n"
    "bnez $4, 7b\n"
    "nop\n"
    "b 9f\n"
    "slt $2, $7, $8\n"
    "8:\n"
    "lw $5, 0x4($5)\n"
    "slt $2, $7, $8\n"
    "9:\n"
    "beqz $2, 13f\n"
    "nop\n"
    "subu $7, $8, $7\n"
    "10:\n"
    "srl $3, $11, 1\n"
    "andi $2, $11, 0x1\n"
    "or $11, $2, $3\n"
    "addiu $7, $7, -0x1\n"
    "nop\n"
    "bnez $7, 10b\n"
    "nop\n"
    "b 13f\n"
    "daddu $7, $8, $0\n"
    "11:\n"
    "slt $2, $8, $7\n"
    "beqz $2, 12f\n"
    "lw $9, 0x4($9)\n"
    "daddu $10, $0, $0\n"
    "b 13f\n"
    "lw $5, 0x4($5)\n"
    "12:\n"
    "daddu $7, $8, $0\n"
    "lw $5, 0x4($5)\n"
    "daddu $11, $0, $0\n"
    "13:\n"
    "beq $9, $5, 18f\n"
    "addu $2, $11, $10\n"
    "bnez $9, 14f\n"
    "subu $2, $10, $11\n"
    "subu $2, $11, $10\n"
    "14:\n"
    "bltz $2, 15f\n"
    "negu $3, $2\n"
    "sw $7, 0x8($6)\n"
    "sw $2, 0xC($6)\n"
    "b 16f\n"
    "sw $0, 0x4($6)\n"
    "15:\n"
    "sw $7, 0x8($6)\n"
    "addiu $2, $0, 0x1\n"
    "sw $3, 0xC($6)\n"
    "sw $2, 0x4($6)\n"
    "16:\n"
    "lw $5, 0xC($6)\n"
    "lui $2, (0x3FFFFFFE >> 16)\n"
    "ori $2, $2, (0x3FFFFFFE & 0xFFFF)\n"
    "addiu $3, $5, -0x1\n"
    "sltu $2, $2, $3\n"
    "bnez $2, 19f\n"
    "daddu $7, $5, $0\n"
    "lui $5, (0x3FFFFFFE >> 16)\n"
    "ori $5, $5, (0x3FFFFFFE & 0xFFFF)\n"
    "17:\n"
    "lw $2, 0x8($6)\n"
    "sll $4, $7, 1\n"
    "addiu $3, $4, -0x1\n"
    "sw $4, 0xC($6)\n"
    "addiu $2, $2, -0x1\n"
    "sltu $3, $5, $3\n"
    "sw $2, 0x8($6)\n"
    "beqz $3, 17b\n"
    "daddu $7, $4, $0\n"
    "b 19f\n"
    "daddu $5, $4, $0\n"
    "18:\n"
    "sw $9, 0x4($6)\n"
    "sw $7, 0x8($6)\n"
    "daddu $5, $2, $0\n"
    "sw $2, 0xC($6)\n"
    "19:\n"
    "addiu $2, $0, 0x3\n"
    "bgez $5, 20f\n"
    "sw $2, 0x0($6)\n"
    "lw $2, 0x8($6)\n"
    "srl $4, $5, 1\n"
    "andi $3, $5, 0x1\n"
    "or $3, $3, $4\n"
    "addiu $2, $2, 0x1\n"
    "sw $3, 0xC($6)\n"
    "sw $2, 0x8($6)\n"
    "20:\n"
    "jr $31\n"
    "daddu $2, $6, $0\n"
    ".size func_004130F8, . - func_004130F8\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413330);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int *func_004130F8(int *, int *, int *);
extern int func_00412F58(int *);

int func_00413330(float x, float y) {
    int a[4];
    int b[4];
    int c[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    return func_00412F58(func_004130F8(a, b, c));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413388);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int *func_004130F8(int *, int *, int *);
extern int func_00412F58(int *);

int func_00413388(float x, float y) {
    int a[4];
    int b[4];
    int c[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    b[1] ^= 1;
    return func_00412F58(func_004130F8(a, b, c));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004133F0);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_004133F0\n.type func_004133F0, @function\nfunc_004133F0:\n"
    "addiu $29, $29, -0x60\n"
    "sd $16, 0x40($29)\n"
    "addiu $4, $29, 0x30\n"
    "sd $31, 0x50($29)\n"
    "daddu $5, $29, $0\n"
    "swc1 $f12, 0x30($29)\n"
    "jal func_00413068\n"
    "swc1 $f13, 0x34($29)\n"
    "addiu $16, $29, 0x10\n"
    "addiu $4, $29, 0x34\n"
    "jal func_00413068\n"
    "daddu $5, $16, $0\n"
    "lw $4, 0x0($29)\n"
    "sltiu $2, $4, 0x2\n"
    "bnez $2, 4f\n"
    "addiu $9, $29, 0x20\n"
    "lw $3, 0x10($29)\n"
    "sltiu $2, $3, 0x2\n"
    "bnel $2, $0, 7f\n"
    "lw $3, 0x14($29)\n"
    "xori $2, $4, 0x4\n"
    "bnez $2, 1f\n"
    "xori $2, $3, 0x4\n"
    "xori $2, $3, 0x2\n"
    "beqz $2, 2f\n"
    "lw $2, 0x4($29)\n"
    "b 5f\n"
    "daddu $4, $29, $0\n"
    "1:\n"
    "bnez $2, 3f\n"
    "xori $2, $4, 0x2\n"
    "bnez $2, 7f\n"
    "lw $3, 0x14($29)\n"
    "2:\n"
    "lui $2, %hi(D_0052ADD8)\n"
    "b 17f\n"
    "addiu $4, $2, %lo(D_0052ADD8)\n"
    "3:\n"
    "bnez $2, 6f\n"
    "xori $2, $3, 0x2\n"
    "4:\n"
    "lw $2, 0x4($29)\n"
    "daddu $4, $29, $0\n"
    "5:\n"
    "lw $3, 0x14($29)\n"
    "xor $2, $2, $3\n"
    "sltu $2, $0, $2\n"
    "b 17f\n"
    "sw $2, 0x4($29)\n"
    "6:\n"
    "bnez $2, 8f\n"
    "lw $4, 0xC($29)\n"
    "lw $3, 0x14($29)\n"
    "7:\n"
    "daddu $4, $16, $0\n"
    "lw $2, 0x4($29)\n"
    "xor $2, $2, $3\n"
    "sltu $2, $0, $2\n"
    "b 17f\n"
    "sw $2, 0x14($29)\n"
    "8:\n"
    "lw $2, 0x1C($29)\n"
    "lw $3, 0x8($29)\n"
    "multu $4, $2\n"
    "lw $6, 0x14($29)\n"
    "lw $2, 0x4($29)\n"
    "xor $2, $2, $6\n"
    "mflo $5\n"
    "mfhi $4\n"
    "dsll32 $5, $5, 0\n"
    "dsll32 $4, $4, 0\n"
    "dsrl32 $5, $5, 0\n"
    "sltu $2, $0, $2\n"
    "or $4, $4, $5\n"
    "sw $2, 0x24($29)\n"
    "lw $5, 0x18($29)\n"
    "addu $3, $3, $5\n"
    "addiu $3, $3, 0x2\n"
    "dsll32 $5, $4, 0\n"
    "dsra32 $5, $5, 0\n"
    "dsra32 $4, $4, 0\n"
    "bgez $4, 11f\n"
    "sw $3, 0x28($29)\n"
    "lui $6, (0x80000000 >> 16)\n"
    "andi $2, $4, 0x1\n"
    "nop\n"
    "9:\n"
    "beqz $2, 10f\n"
    "addiu $3, $3, 0x1\n"
    "srl $5, $5, 1\n"
    "or $5, $5, $6\n"
    "10:\n"
    "srl $4, $4, 1\n"
    "bltz $4, 9b\n"
    "andi $2, $4, 0x1\n"
    "sw $3, 0x28($29)\n"
    "11:\n"
    "lui $2, (0x3FFFFFFF >> 16)\n"
    "ori $2, $2, (0x3FFFFFFF & 0xFFFF)\n"
    "sltu $2, $2, $4\n"
    "bnez $2, 13f\n"
    "andi $3, $4, 0x7F\n"
    "lui $7, (0x3FFFFFFF >> 16)\n"
    "lw $6, 0x28($29)\n"
    "lui $8, (0x80000000 >> 16)\n"
    "ori $7, $7, (0x3FFFFFFF & 0xFFFF)\n"
    "nop\n"
    "12:\n"
    "sll $4, $4, 1\n"
    "and $3, $5, $8\n"
    "ori $2, $4, 0x1\n"
    "addiu $6, $6, -0x1\n"
    "movn $4, $2, $3\n"
    "sltu $2, $7, $4\n"
    "beqz $2, 12b\n"
    "sll $5, $5, 1\n"
    "sw $6, 0x28($29)\n"
    "andi $3, $4, 0x7F\n"
    "13:\n"
    "addiu $2, $0, 0x40\n"
    "bnel $3, $2, 16f\n"
    "sw $4, 0x2C($29)\n"
    "andi $2, $4, 0x80\n"
    "beqz $2, 14f\n"
    "addiu $2, $4, 0x40\n"
    "b 15f\n"
    "addiu $4, $4, 0x40\n"
    "14:\n"
    "movn $4, $2, $5\n"
    "15:\n"
    "sw $4, 0x2C($29)\n"
    "16:\n"
    "addiu $2, $0, 0x3\n"
    "sw $2, 0x0($9)\n"
    "daddu $4, $9, $0\n"
    "17:\n"
    "jal func_00412F58\n"
    "nop\n"
    "ld $31, 0x50($29)\n"
    "ld $16, 0x40($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x60\n"
    ".size func_004133F0, . - func_004133F0\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004135E8);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern float func_00412F58_f(int *) __asm__("func_00412F58");
extern int D_0052ADD8[];

float func_004135E8(float x, float y) {
    int a[4];
    int b[4];
    float fx = x;
    float fy = y;
    int *r;
    unsigned n, d, q, bit;
    int *p;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    p = a;
    if ((unsigned)a[0] < 2) {
        r = a;
    } else if ((unsigned)b[0] < 2) {
        r = b;
    } else {
        a[1] ^= b[1];
        if ((a[0] ^ 4) == 0 || (a[0] ^ 2) == 0) {
            r = a;
            if (a[0] == b[0])
                r = D_0052ADD8;
        } else if ((b[0] ^ 4) == 0) {
            a[3] = 0;
            a[2] = 0;
            r = a;
        } else if ((b[0] ^ 2) == 0) {
            a[0] = 4;
            r = a;
        } else {
            a[2] = a[2] - b[2];
            n = a[3];
            d = b[3];
            if (n < d) {
                a[2]--;
                n <<= 1;
            }
            bit = 0x40000000;
            q = 0;
            for (; bit != 0; bit >>= 1) {
                if (n >= d) {
                    q |= bit;
                    n -= d;
                }
                n <<= 1;
            }
            if ((q & 0x7F) == 0x40) {
                if (q & 0x80)
                    q += 0x40;
                else if (n != 0)
                    q += 0x40;
            }
            p[3] = q;
            r = p;
        }
    }
    return func_00412F58_f(r);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413748);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00413748\n.type func_00413748, @function\nfunc_00413748:\n"
    "lw $6, 0x0($4)\n"
    "sltiu $2, $6, 0x2\n"
    "bnez $2, 1f\n"
    "nop\n"
    "lw $3, 0x0($5)\n"
    "sltiu $2, $3, 0x2\n"
    "beqz $2, 2f\n"
    "xori $2, $6, 0x4\n"
    "1:\n"
    "jr $31\n"
    "addiu $2, $0, 0x1\n"
    "2:\n"
    "bnez $2, 4f\n"
    "xori $2, $3, 0x4\n"
    "bnel $2, $0, 3f\n"
    "lw $4, 0x4($4)\n"
    "lw $3, 0x4($5)\n"
    "lw $2, 0x4($4)\n"
    "jr $31\n"
    "subu $2, $3, $2\n"
    "3:\n"
    "addiu $3, $0, 0x1\n"
    "addiu $2, $0, -0x1\n"
    "jr $31\n"
    "movz $2, $3, $4\n"
    "4:\n"
    "bnel $2, $0, 5f\n"
    "xori $2, $6, 0x2\n"
    "lw $4, 0x4($5)\n"
    "addiu $3, $0, -0x1\n"
    "addiu $2, $0, 0x1\n"
    "jr $31\n"
    "movz $2, $3, $4\n"
    "5:\n"
    "bnez $2, 7f\n"
    "xori $2, $3, 0x2\n"
    "bnel $2, $0, 6f\n"
    "lw $4, 0x4($5)\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    "6:\n"
    "addiu $3, $0, 0x1\n"
    "addiu $2, $0, -0x1\n"
    "jr $31\n"
    "movn $2, $3, $4\n"
    "7:\n"
    "beql $2, $0, 3b\n"
    "lw $4, 0x4($4)\n"
    "lw $7, 0x4($4)\n"
    "lw $2, 0x4($5)\n"
    "beql $7, $2, 9f\n"
    "lw $6, 0x8($4)\n"
    "addiu $3, $0, 0x1\n"
    "8:\n"
    "addiu $2, $0, -0x1\n"
    "jr $31\n"
    "movz $2, $3, $7\n"
    "9:\n"
    "lw $3, 0x8($5)\n"
    "slt $2, $3, $6\n"
    "bnel $2, $0, 8b\n"
    "addiu $3, $0, 0x1\n"
    "slt $2, $6, $3\n"
    "beql $2, $0, 11f\n"
    "lw $3, 0xC($4)\n"
    "addiu $3, $0, -0x1\n"
    "10:\n"
    "addiu $2, $0, 0x1\n"
    "jr $31\n"
    "movz $2, $3, $7\n"
    "11:\n"
    "lw $4, 0xC($5)\n"
    "sltu $2, $4, $3\n"
    "bnel $2, $0, 8b\n"
    "addiu $3, $0, 0x1\n"
    "sltu $2, $3, $4\n"
    "bnez $2, 10b\n"
    "addiu $3, $0, -0x1\n"
    "jr $31\n"
    "daddu $2, $0, $0\n"
    ".size func_00413748, . - func_00413748\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413860);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00413748(int *, int *);

int func_00413860(float x, float y) {
    int a[4];
    int b[4];
    float fx = x;
    float fy = y;
    func_00413068(&fx, a);
    func_00413068(&fy, b);
    return func_00413748(a, b);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004138B0);
#ifdef SKIP_ASM
extern float func_00412F58_f(int *) __asm__("func_00412F58");

float func_004138B0(int x) {
    int o[4];
    unsigned m, t;
    int e;
    o[0] = 3;
    o[1] = (unsigned)x >> 31;
    if (x == 0) {
        o[0] = 2;
    } else {
        o[2] = 0x1E;
        if (o[1]) {
            if (x == 0x80000000)
                return -2147483648.0f;
            o[3] = -x;
        } else {
            o[3] = x;
        }
        m = o[3];
        if (m <= 0x3FFFFFFF) {
            e = o[2];
            do {
                t = m << 1;
                e--;
                m = t;
            } while (t <= 0x3FFFFFFF);
            o[2] = e;
            o[3] = t;
        }
    }
    return func_00412F58_f(o);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413968);
#ifdef SKIP_ASM
int func_00413968(float x) {
    int o[4];
    float f = x;
    unsigned c;
    unsigned r;
    func_00413068(&f, o);
    c = o[0];
    if ((c ^ 2) == 0)
        return 0;
    if (c < 2)
        return 0;
    if ((c ^ 4) == 0)
        goto sat;
    if (o[2] < 0)
        return 0;
    if (o[2] >= 0x1F) {
sat:
        return o[1] ? 0x80000000 : 0x7FFFFFFF;
    }
    r = (unsigned)o[3] >> (0x1E - o[2]);
    return o[1] ? -r : r;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004139F8);
#ifdef SKIP_ASM
unsigned func_004139F8(float x) {
    int o[4];
    float f = x;
    unsigned c;
    func_00413068(&f, o);
    c = o[0];
    if ((c ^ 2) == 0)
        return 0;
    if (c < 2)
        return 0;
    if (o[1])
        return 0;
    if ((c ^ 4) == 0)
        goto sat;
    if (o[2] < 0)
        return 0;
    if (o[2] >= 0x20) {
sat:
        return 0xFFFFFFFF;
    }
    if (o[2] >= 0x1F)
        return (unsigned)o[3] << (o[2] - 0x1E);
    return (unsigned)o[3] >> (0x1E - o[2]);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413A90);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00412F58(int *);
int func_00413A90(float x) {
    int obj[2];
    float f = x;
    func_00413068(&f, obj);
    obj[1] = obj[1] == 0;
    return func_00412F58(obj);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413AC8);
#ifdef SKIP_ASM
void func_00413AC8(int a, int b, int c, int d) {
    int v[4];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
    func_00412F58(v);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413AF8);
#ifdef SKIP_ASM
extern void func_00413068(float *, int *);
extern int func_00412778(int, int, int, unsigned long long);
int func_00413AF8(float x) {
    int o[4];
    float f = x;
    func_00413068(&f, o);
    return func_00412778(o[0], o[1], o[2], ((unsigned long long)(long long)o[3] << 32) >> 2);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413B38);
#ifdef SKIP_ASM
unsigned char *func_00413B38(unsigned char *p, unsigned *out) {
    unsigned b = *p++;
    unsigned r = b & 0x7F;
    int shift = 0;
    if (b & 0x80) {
        do {
            b = *p++;
            shift += 7;
            r |= (b & 0x7F) << shift;
        } while (b & 0x80);
    }
    *out = r;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413B80);
#ifdef SKIP_ASM
unsigned char *func_00413B80(unsigned char *p, int *out) {
    unsigned shift = 0;
    int r = 0;
    unsigned b;
    do {
        b = *p++;
        r |= (b & 0x7F) << shift;
        shift += 7;
    } while (b & 0x80);
    if (shift < 32 && (b & 0x40))
        r |= -1 << shift;
    *out = r;
    return p;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413BD0);
#ifdef SKIP_ASM
struct K13BD0 { int f0; int f4; int key; };
struct L13BD0 { struct K13BD0 **items; unsigned n; };
void func_00413BD0(struct L13BD0 *a, struct L13BD0 *b) {
    unsigned m = b->n;
    unsigned n;
    unsigned j;
    j = m;
    if (m != 0) {
        n = a->n;
        do {
            struct K13BD0 *x;
            j--;
            x = b->items[j];
            if (n != 0 && a->items[n - 1]->key - x->key > 0) {
                do {
                    a->items[n + j] = a->items[n - 1];
                    n--;
                } while (n != 0 && a->items[n - 1]->key - x->key > 0);
            }
            a->items[n + j] = x;
        } while (j != 0);
        a->n = a->n + m;
    }
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413CD0);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00413CD0\n.type func_00413CD0, @function\nfunc_00413CD0:\n"
    "addiu $29, $29, -0x40\n"
    "sd $17, 0x10($29)\n"
    "sd $31, 0x30($29)\n"
    "daddu $17, $4, $0\n"
    "sd $18, 0x20($29)\n"
    "sd $16, 0x0($29)\n"
    "lw $16, 0x4($17)\n"
    "beq $16, $5, 1f\n"
    "addiu $18, $17, 0x8\n"
    "jal func_00418790\n"
    "nop\n"
    "1:\n"
    "daddu $4, $17, $0\n"
    "jal func_004149F0\n"
    "daddu $5, $18, $0\n"
    "lw $2, 0x4($17)\n"
    "lw $3, 0xC($17)\n"
    "addu $2, $2, $3\n"
    "beql $2, $16, 2f\n"
    "lw $13, 0x4($18)\n"
    "jal func_00418790\n"
    "nop\n"
    "2:\n"
    "lw $11, 0x8($17)\n"
    "beqz $13, 11f\n"
    "daddu $14, $13, $0\n"
    "sltiu $15, $13, 0x2\n"
    "addiu $4, $14, -0x1\n"
    "3:\n"
    "sll $10, $4, 1\n"
    "b 9f\n"
    "daddu $14, $4, $0\n"
    "nop\n"
    "4:\n"
    "addiu $12, $3, 0x2\n"
    "sltu $2, $12, $13\n"
    "beqz $2, 5f\n"
    "sll $7, $4, 3\n"
    "addu $8, $7, $11\n"
    "lw $9, 0x8($8)\n"
    "lw $3, 0x4($8)\n"
    "lw $6, 0x8($9)\n"
    "lw $2, 0x8($3)\n"
    "subu $2, $6, $2\n"
    "blez $2, 6f\n"
    "sll $5, $4, 2\n"
    "addu $3, $5, $11\n"
    "lw $4, 0x0($3)\n"
    "lw $2, 0x8($4)\n"
    "subu $2, $6, $2\n"
    "blez $2, 7f\n"
    "addu $7, $7, $11\n"
    "sw $9, 0x0($3)\n"
    "sw $4, 0x8($8)\n"
    "b 8f\n"
    "daddu $4, $12, $0\n"
    "5:\n"
    "sll $5, $4, 2\n"
    "6:\n"
    "addu $7, $7, $11\n"
    "7:\n"
    "addu $6, $5, $11\n"
    "lw $4, 0x4($7)\n"
    "lw $5, 0x0($6)\n"
    "lw $2, 0x8($4)\n"
    "lw $3, 0x8($5)\n"
    "subu $2, $2, $3\n"
    "blez $2, 10f\n"
    "nop\n"
    "sw $4, 0x0($6)\n"
    "sw $5, 0x4($7)\n"
    "addiu $4, $10, 0x1\n"
    "nop\n"
    "8:\n"
    "sll $10, $4, 1\n"
    "9:\n"
    "addiu $2, $10, 0x1\n"
    "sltu $2, $2, $13\n"
    "bnez $2, 4b\n"
    "daddu $3, $10, $0\n"
    "10:\n"
    "bnez $14, 3b\n"
    "addiu $4, $14, -0x1\n"
    "b 12f\n"
    "nop\n"
    "11:\n"
    "addiu $15, $0, 0x1\n"
    "12:\n"
    "bnez $15, 21f\n"
    "daddu $5, $18, $0\n"
    "sll $2, $13, 2\n"
    "addiu $16, $0, 0x1\n"
    "addu $14, $2, $11\n"
    "addiu $14, $14, -0x4\n"
    "13:\n"
    "addiu $13, $13, -0x1\n"
    "lw $2, 0x0($11)\n"
    "lw $3, 0x0($14)\n"
    "sw $3, 0x0($11)\n"
    "sw $2, 0x0($14)\n"
    "sltu $2, $16, $13\n"
    "beqz $2, 19f\n"
    "daddu $4, $0, $0\n"
    "daddu $10, $0, $0\n"
    "sltiu $15, $13, 0x2\n"
    "addiu $12, $10, 0x2\n"
    "nop\n"
    "14:\n"
    "sltu $2, $12, $13\n"
    "beqz $2, 15f\n"
    "sll $7, $4, 3\n"
    "addu $8, $7, $11\n"
    "lw $9, 0x8($8)\n"
    "lw $3, 0x4($8)\n"
    "lw $6, 0x8($9)\n"
    "lw $2, 0x8($3)\n"
    "subu $2, $6, $2\n"
    "blez $2, 16f\n"
    "sll $5, $4, 2\n"
    "addu $3, $5, $11\n"
    "lw $4, 0x0($3)\n"
    "lw $2, 0x8($4)\n"
    "subu $2, $6, $2\n"
    "blez $2, 17f\n"
    "addu $7, $7, $11\n"
    "sw $9, 0x0($3)\n"
    "sw $4, 0x8($8)\n"
    "b 18f\n"
    "daddu $4, $12, $0\n"
    "nop\n"
    "15:\n"
    "sll $5, $4, 2\n"
    "16:\n"
    "addu $7, $7, $11\n"
    "17:\n"
    "addu $6, $5, $11\n"
    "lw $4, 0x4($7)\n"
    "lw $5, 0x0($6)\n"
    "lw $2, 0x8($4)\n"
    "lw $3, 0x8($5)\n"
    "subu $2, $2, $3\n"
    "blez $2, 20f\n"
    "nop\n"
    "sw $4, 0x0($6)\n"
    "sw $5, 0x4($7)\n"
    "addiu $4, $10, 0x1\n"
    "nop\n"
    "18:\n"
    "sll $3, $4, 1\n"
    "daddu $10, $3, $0\n"
    "addiu $2, $10, 0x1\n"
    "sltu $2, $2, $13\n"
    "bnez $2, 14b\n"
    "addiu $12, $10, 0x2\n"
    "b 20f\n"
    "nop\n"
    "19:\n"
    "sltiu $15, $13, 0x2\n"
    "20:\n"
    "beqz $15, 13b\n"
    "addiu $14, $14, -0x4\n"
    "daddu $5, $18, $0\n"
    "21:\n"
    "jal func_00413BD0\n"
    "daddu $4, $17, $0\n"
    "jal func_00418910\n"
    "lw $4, 0x8($17)\n"
    "lw $2, 0x0($17)\n"
    "ld $31, 0x30($29)\n"
    "ld $18, 0x20($29)\n"
    "ld $17, 0x10($29)\n"
    "ld $16, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x40\n"
    ".size func_00413CD0, . - func_00413CD0\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413F38);
#ifdef SKIP_ASM
struct N13F38 {
    int off;
    int a;
    int b;
};
int func_00413F38(struct N13F38 *n) {
    int cnt = 0;
    if (n->off != 0) {
        do {
            if (n->a != 0 && n->b != 0)
                cnt++;
            n = (struct N13F38 *)((char *)n + n->off + 4);
        } while (n->off);
    }
    return cnt;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00413F80);
#ifdef SKIP_ASM
struct N13F80 {
    int off;
    int a;
    unsigned addr;
    int size;
};
struct L13F80 {
    struct N13F80 **arr;
    int cnt;
};
void func_00413F80(struct N13F80 *n, struct L13F80 *l, unsigned *lo, unsigned *hi) {
    unsigned mn = *lo;
    unsigned mx = *hi;
    if (n->off != 0) {
        do {
            if (n->a != 0 && n->addr != 0) {
                l->arr[l->cnt++] = n;
                if (n->addr < mn)
                    mn = n->addr;
                if (mx < n->addr + n->size)
                    mx = n->addr + n->size;
            }
            n = (struct N13F80 *)((char *)n + n->off + 4);
        } while (n->off);
    }
    *lo = mn;
    *hi = mx;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414008);
#ifdef SKIP_ASM
struct N14008 {
    unsigned lo;
    unsigned hi;
    struct N13F80 *root;
    struct N13F80 **roots;
    int cnt;
};
struct LL14008 {
    int *a;
    int na;
    int *b;
    int nb;
};
extern int *func_004188C0(int);
extern struct N13F80 **func_00413CD0(struct LL14008 *, int);
void func_00414008(struct N14008 *n) {
    struct N13F80 **pp;
    int cnt, bytes;
    struct LL14008 l;
    unsigned lo, hi;
    if (n->roots != 0) {
        pp = n->roots;
        cnt = 0;
        while (*pp != 0) {
            cnt += func_00413F38((struct N13F38 *)*pp);
            pp++;
        }
    } else {
        cnt = func_00413F38((struct N13F38 *)n->root);
    }
    bytes = cnt * 4;
    n->cnt = cnt;
    l.a = func_004188C0(bytes);
    l.b = func_004188C0(bytes);
    l.na = 0;
    l.nb = 0;
    lo = 0xFFFFFFFF;
    hi = 0;
    if (n->roots != 0) {
        pp = n->roots;
        while (*pp != 0) {
            func_00413F80(*pp, (struct L13F80 *)&l, &lo, &hi);
            pp++;
        }
    } else {
        func_00413F80(n->root, (struct L13F80 *)&l, &lo, &hi);
    }
    n->roots = func_00413CD0(&l, cnt);
    n->lo = lo;
    n->hi = hi;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414148);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00414148\n.type func_00414148, @function\nfunc_00414148:\n"
    "addiu $29, $29, -0x30\n"
    "lui $2, %hi(D_0052ADE8)\n"
    "sd $16, 0x0($29)\n"
    "sd $17, 0x10($29)\n"
    "lw $16, %lo(D_0052ADE8)($2)\n"
    "daddu $17, $4, $0\n"
    "sd $31, 0x20($29)\n"
    "nop\n"
    "1:\n"
    "beqz $16, 9f\n"
    "daddu $2, $0, $0\n"
    "lw $2, 0x0($16)\n"
    "bnez $2, 2f\n"
    "sltu $2, $17, $2\n"
    "jal func_00414008\n"
    "daddu $4, $16, $0\n"
    "lw $2, 0x0($16)\n"
    "sltu $2, $17, $2\n"
    "2:\n"
    "bnel $2, $0, 1b\n"
    "lw $16, 0x14($16)\n"
    "lw $2, 0x4($16)\n"
    "sltu $2, $17, $2\n"
    "beql $2, $0, 1b\n"
    "lw $16, 0x14($16)\n"
    "bnel $16, $0, 4f\n"
    "lw $7, 0x10($16)\n"
    "b 9f\n"
    "daddu $2, $0, $0\n"
    "3:\n"
    "b 9f\n"
    "daddu $2, $3, $0\n"
    "4:\n"
    "beqz $7, 8f\n"
    "daddu $8, $0, $0\n"
    "lw $4, 0xC($16)\n"
    "addu $2, $8, $7\n"
    "nop\n"
    "5:\n"
    "srl $6, $2, 1\n"
    "sll $3, $6, 2\n"
    "addu $3, $3, $4\n"
    "lw $3, 0x0($3)\n"
    "lw $5, 0x8($3)\n"
    "sltu $2, $17, $5\n"
    "beql $2, $0, 6f\n"
    "lw $2, 0xC($3)\n"
    "b 7f\n"
    "daddu $7, $6, $0\n"
    "6:\n"
    "addu $2, $5, $2\n"
    "sltu $2, $17, $2\n"
    "bnez $2, 3b\n"
    "addiu $8, $6, 0x1\n"
    "7:\n"
    "sltu $2, $8, $7\n"
    "bnez $2, 5b\n"
    "addu $2, $8, $7\n"
    "8:\n"
    "daddu $2, $0, $0\n"
    "9:\n"
    "ld $31, 0x20($29)\n"
    "ld $17, 0x10($29)\n"
    "ld $16, 0x0($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x30\n"
    ".size func_00414148, . - func_00414148\n"
    ".word 0x00000000\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414230);
#ifdef SKIP_ASM
extern int D_004998F0[];
extern int D_004998F8[];
extern int func_004165A8(int, int);
struct C14230 {
    char *aug;
    int f4;
    unsigned f8;
    int fC;
    int f10;
};
struct U14230 {
    int v;
} __attribute__((packed));
extern int strlen(char *);
unsigned char *func_00414230(int *cie, struct C14230 *o) {
    char *s;
    unsigned char *p;
    unsigned tmp;
    o->aug = (char *)cie - cie[1] + 13;
    if (func_004165A8((int)o->aug, (int)D_004998F0) == 0 || func_004165A8((int)o->aug, (int)D_004998F8) == 0 || *o->aug == 'z') {
        s = o->aug + strlen(o->aug);
        p = (unsigned char *)s + 1;
        if (func_004165A8((int)o->aug, (int)D_004998F8) == 0) {
            o->f4 = ((struct U14230 *)p)->v;
            p += 4;
        } else {
            o->f4 = 0;
        }
        p = func_00413B38(p, &o->f8);
        p = func_00413B80(p, &o->fC);
        o->f10 = *p++;
        if (*o->aug == 'z')
            p = func_00413B38(p, &tmp) + tmp;
        return p;
    }
    return 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414338);
#ifdef SKIP_ASM
// PORT: PS2-only libgcc soft-float library routine; kept as the binary's own instructions (library source is never reconstructed); the whole
// body is one asm block so the PS2 build stays byte-exact. A port replaces this function.
__asm__(
    ".set push\n.set noreorder\n.set noat\n"
    ".text\n.align 3\n.globl func_00414338\n.type func_00414338, @function\nfunc_00414338:\n"
    "addiu $29, $29, -0x50\n"
    "sd $18, 0x30($29)\n"
    "sd $17, 0x20($29)\n"
    "daddu $18, $6, $0\n"
    "sd $16, 0x10($29)\n"
    "daddu $17, $5, $0\n"
    "sd $31, 0x40($29)\n"
    "daddu $16, $4, $0\n"
    "lbu $3, 0x0($16)\n"
    "andi $2, $3, 0x40\n"
    ".word 0x10400006 /* beqz $2, .L0041437C: raw word */\n"
    "addiu $16, $16, 0x1\n"
    "lw $4, 0x8($18)\n"
    "andi $2, $3, 0x3F\n"
    "lw $3, 0x0($7)\n"
    ".word 0x10000027 /* b .L00414414: raw word */\n"
    "mult $2, $2, $4\n"
    ".L0041437C:\n"
    "andi $2, $3, 0x80\n"
    ".word 0x10400004 /* beqz $2, .L00414394: raw word */\n"
    "andi $2, $3, 0x3F\n"
    "daddu $4, $16, $0\n"
    ".word 0x1000002F /* b .L0041444C: raw word */\n"
    "sw $2, 0x4($29)\n"
    ".L00414394:\n"
    "andi $2, $3, 0xC0\n"
    ".word 0x10400005 /* beqz $2, .L004143B0: raw word */\n"
    "andi $2, $3, 0x3F\n"
    "addu $3, $17, $2\n"
    "sw $2, 0x4($29)\n"
    ".word 0x100000C2 /* b lbl_004146B4: raw word */\n"
    "sb $0, 0x29C($3)\n"
    ".L004143B0:\n"
    "sltiu $2, $3, 0x2F\n"
    ".word 0x104000BD /* beqz $2, lbl_004146AC: raw word */\n"
    "lui $2, %hi(jtbl_00499900)\n"
    "sll $3, $3, 2\n"
    "addiu $2, $2, %lo(jtbl_00499900)\n"
    "addu $3, $3, $2\n"
    "lw $4, 0x0($3)\n"
    "jr $4\n"
    "nop\n"
    "lbl_004143D4:\n"
    ".Llbl_004143D4:\n"
    "lwl $2, 0x3($16)\n"
    "lwr $2, 0x0($16)\n"
    "addiu $16, $16, 0x4\n"
    ".word 0x100000B4 /* b lbl_004146B4: raw word */\n"
    "sw $2, 0x0($7)\n"
    "lbl_004143E8:\n"
    ".Llbl_004143E8:\n"
    "lbu $3, 0x0($16)\n"
    "lw $2, 0x0($7)\n"
    ".word 0x1000000F /* b .L00414430: raw word */\n"
    "addiu $16, $16, 0x1\n"
    "lbl_004143F8:\n"
    ".Llbl_004143F8:\n"
    "lbu $2, 0x1($16)\n"
    "lbu $4, 0x0($16)\n"
    "dsll $2, $2, 8\n"
    "lw $3, 0x0($7)\n"
    "or $2, $2, $4\n"
    "addiu $16, $16, 0x2\n"
    "andi $2, $2, 0xFFFF\n"
    ".L00414414:\n"
    "addu $3, $3, $2\n"
    ".word 0x100000A6 /* b lbl_004146B4: raw word */\n"
    "sw $3, 0x0($7)\n"
    "lbl_00414420:\n"
    ".Llbl_00414420:\n"
    "lwl $3, 0x3($16)\n"
    "lwr $3, 0x0($16)\n"
    "lw $2, 0x0($7)\n"
    "addiu $16, $16, 0x4\n"
    ".L00414430:\n"
    "addu $2, $2, $3\n"
    ".word 0x1000009F /* b lbl_004146B4: raw word */\n"
    "sw $2, 0x0($7)\n"
    "lbl_0041443C:\n"
    ".Llbl_0041443C:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x4\n"
    "daddu $4, $2, $0\n"
    ".L0041444C:\n"
    "jal func_00413B38\n"
    "daddu $5, $29, $0\n"
    "lw $4, 0x0($29)\n"
    "daddu $16, $2, $0\n"
    "lw $5, 0xC($18)\n"
    "addiu $6, $0, 0x1\n"
    "lw $2, 0x4($29)\n"
    "mult $4, $4, $5\n"
    "sll $3, $2, 3\n"
    "addu $2, $17, $2\n"
    "addu $3, $17, $3\n"
    "sb $6, 0x29C($2)\n"
    "sw $4, 0x0($29)\n"
    "daddu $2, $4, $0\n"
    ".word 0x1000008B /* b lbl_004146B4: raw word */\n"
    "sd $2, 0x18($3)\n"
    "lbl_0041448C:\n"
    ".Llbl_0041448C:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x4\n"
    "lw $3, 0x4($29)\n"
    "daddu $16, $2, $0\n"
    "addu $3, $17, $3\n"
    ".word 0x10000083 /* b lbl_004146B4: raw word */\n"
    "sb $0, 0x29C($3)\n"
    "lbl_004144AC:\n"
    ".Llbl_004144AC:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x4\n"
    "daddu $4, $2, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x8\n"
    "lw $4, 0x4($29)\n"
    "daddu $16, $2, $0\n"
    "lw $3, 0x8($29)\n"
    "addiu $5, $0, 0x2\n"
    "sll $2, $4, 3\n"
    "addu $4, $17, $4\n"
    "dsll32 $3, $3, 0\n"
    "sb $5, 0x29C($4)\n"
    "addu $2, $17, $2\n"
    "dsrl32 $3, $3, 0\n"
    ".word 0x10000071 /* b lbl_004146B4: raw word */\n"
    "sd $3, 0x18($2)\n"
    "lbl_004144F4:\n"
    ".Llbl_004144F4:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x4\n"
    "daddu $4, $2, $0\n"
    "jal func_00413B38\n"
    "daddu $5, $29, $0\n"
    "daddu $16, $2, $0\n"
    "lhu $3, 0x4($29)\n"
    "lw $2, 0x0($29)\n"
    "sh $3, 0x298($17)\n"
    ".word 0x10000065 /* b lbl_004146B4: raw word */\n"
    "sd $2, 0x8($17)\n"
    "lbl_00414524:\n"
    ".Llbl_00414524:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "ori $5, $29, 0x4\n"
    "lhu $3, 0x4($29)\n"
    "daddu $16, $2, $0\n"
    ".word 0x1000005E /* b lbl_004146B4: raw word */\n"
    "sh $3, 0x298($17)\n"
    "lbl_00414540:\n"
    ".Llbl_00414540:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "daddu $5, $29, $0\n"
    "lw $3, 0x0($29)\n"
    "daddu $16, $2, $0\n"
    ".word 0x10000057 /* b lbl_004146B4: raw word */\n"
    "sd $3, 0x8($17)\n"
    "lbl_0041455C:\n"
    ".Llbl_0041455C:\n"
    "jal func_004188C0\n"
    "addiu $4, $0, 0x2F8\n"
    "addiu $5, $17, 0x2E0\n"
    "daddu $4, $2, $0\n"
    "daddu $3, $17, $0\n"
    ".L00414570:\n"
    "ld $6, 0x0($3)\n"
    "ld $7, 0x8($3)\n"
    "ld $8, 0x10($3)\n"
    "ld $9, 0x18($3)\n"
    "sd $6, 0x0($4)\n"
    "sd $7, 0x8($4)\n"
    "sd $8, 0x10($4)\n"
    "sd $9, 0x18($4)\n"
    "addiu $3, $3, 0x20\n"
    "addiu $4, $4, 0x20\n"
    "nop\n"
    ".word 0x1465FFF4 /* bne $3, $5, .L00414570: raw word */\n"
    "nop\n"
    "ld $5, 0x0($3)\n"
    "ld $6, 0x8($3)\n"
    "ld $7, 0x10($3)\n"
    "sd $5, 0x0($4)\n"
    "sd $6, 0x8($4)\n"
    "sd $7, 0x10($4)\n"
    ".word 0x1000003D /* b lbl_004146B4: raw word */\n"
    "sw $2, 0x2F0($17)\n"
    "lbl_004145C4:\n"
    ".Llbl_004145C4:\n"
    "lw $4, 0x2F0($17)\n"
    "daddu $5, $17, $0\n"
    "addiu $2, $4, 0x2E0\n"
    "daddu $6, $4, $0\n"
    ".L004145D4:\n"
    "ld $9, 0x0($6)\n"
    "ld $3, 0x8($6)\n"
    "ld $7, 0x10($6)\n"
    "ld $8, 0x18($6)\n"
    "sd $9, 0x0($5)\n"
    "sd $3, 0x8($5)\n"
    "sd $7, 0x10($5)\n"
    "sd $8, 0x18($5)\n"
    "addiu $6, $6, 0x20\n"
    "addiu $5, $5, 0x20\n"
    "nop\n"
    ".word 0x14C2FFF4 /* bne $6, $2, .L004145D4: raw word */\n"
    "nop\n"
    "ld $9, 0x0($6)\n"
    "ld $2, 0x8($6)\n"
    "ld $3, 0x10($6)\n"
    "sd $9, 0x0($5)\n"
    "sd $2, 0x8($5)\n"
    "jal func_00418910\n"
    "sd $3, 0x10($5)\n"
    ".word 0x10000024 /* b .L004146B8: raw word */\n"
    "daddu $2, $16, $0\n"
    "lbl_0041462C:\n"
    ".Llbl_0041462C:\n"
    "addiu $2, $0, 0x10\n"
    "addiu $4, $0, 0x10\n"
    "sw $2, 0x4($29)\n"
    "addiu $7, $0, 0x10\n"
    "addiu $9, $17, 0x29C\n"
    "addiu $8, $17, 0x18\n"
    "nop\n"
    ".L00414648:\n"
    "addiu $2, $4, -0x10\n"
    "addiu $6, $4, 0x1\n"
    "addu $5, $9, $7\n"
    "sll $2, $2, 2\n"
    "addiu $3, $0, 0x1\n"
    "sll $4, $4, 3\n"
    "sb $3, 0x0($5)\n"
    "dsll32 $2, $2, 0\n"
    "addu $4, $8, $4\n"
    "dsrl32 $2, $2, 0\n"
    "sw $6, 0x4($29)\n"
    "daddu $7, $6, $0\n"
    "sd $2, 0x0($4)\n"
    "sltiu $2, $7, 0x20\n"
    ".word 0x1440FFF1 /* bnez $2, .L00414648: raw word */\n"
    "daddu $4, $7, $0\n"
    ".word 0x1000000B /* b .L004146B8: raw word */\n"
    "daddu $2, $16, $0\n"
    "lbl_00414690:\n"
    ".Llbl_00414690:\n"
    "daddu $4, $16, $0\n"
    "jal func_00413B38\n"
    "daddu $5, $29, $0\n"
    "lw $3, 0x0($29)\n"
    "daddu $16, $2, $0\n"
    ".word 0x10000003 /* b lbl_004146B4: raw word */\n"
    "sd $3, 0x10($17)\n"
    "lbl_004146AC:\n"
    ".Llbl_004146AC:\n"
    "jal func_00418790\n"
    "nop\n"
    "lbl_004146B4:\n"
    ".Llbl_004146B4:\n"
    "daddu $2, $16, $0\n"
    ".L004146B8:\n"
    "ld $31, 0x40($29)\n"
    "ld $18, 0x30($29)\n"
    "ld $17, 0x20($29)\n"
    "ld $16, 0x10($29)\n"
    "jr $31\n"
    "addiu $29, $29, 0x50\n"
    ".size func_00414338, . - func_00414338\n"
    ".set pop\n");
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004146D0);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
void func_004146D0(int a, int *p) {
    p[2] = a;
    p[5] = (int)D_0052ADE8;
    D_0052ADE8 = p;
    p[0] = 0;
    p[3] = 0;
    p[4] = 0;
    p[1] = 0;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004146F8);
#ifdef SKIP_ASM
extern void func_004146D0(int, int *);
extern int *func_004188C0(int);
void func_004146F8(int a) {
    func_004146D0(a, func_004188C0(0x18));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414728);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
void func_00414728(int a, int *p) {
    p[2] = a;
    p[5] = (int)D_0052ADE8;
    D_0052ADE8 = p;
    p[1] = 0;
    p[0] = 0;
    p[4] = 0;
    p[3] = a;
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414750);
#ifdef SKIP_ASM
extern void func_00414728(int, int *);
extern int *func_004188C0(int);
void func_00414750(int a) {
    func_00414728(a, func_004188C0(0x18));
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414780);
#ifdef SKIP_ASM
extern int *D_0052ADE8;
extern void func_00418910(int);
extern void func_00418790();
int func_00414780(key)
    int key;
{
    int **pp = &D_0052ADE8;
    int *n;
    if (D_0052ADE8 != 0) {
        do {
            n = *pp;
            if (n[2] == key) {
                *pp = (int *)n[5];
                if (n[0] != 0)
                    func_00418910(n[3]);
                return (int)n;
            }
            pp = (int **)&n[5];
        } while (n[5] != 0);
    }
    func_00418790(key, pp);
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004147F8);
#ifdef SKIP_ASM
extern int func_00414780();
extern void func_00418910(int);
void func_004147F8(void) {
    func_00418910(func_00414780());
}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_00414818);
#ifdef SKIP_ASM
// 96.79 (reg numbering: target &st=$20,start=$19,copyend=$21,pc=$22; ours &st=19,start=20,pc=21,copyend=22) - struct copy needs aligned(8)
struct Ctx14818 {
    char *aug;
    int f4;
    int f8;
    int fC;
    unsigned short f10;
};
struct St14818 {
    char pad0[4];
    unsigned f4;
    char pad8[0x29A - 8];
    unsigned short ra;
    char rest[0x2F0 - 0x29C];
} __attribute__((aligned(8)));
struct SI14818 {
    struct St14818 s;
    int extra[2];
};
extern int *f14818_find(unsigned) __asm__("func_00414148");
extern unsigned char *f14818_cie(int *, struct Ctx14818 *) __asm__("func_00414230");
extern unsigned char *f14818_exec(unsigned char *, struct SI14818 *, struct Ctx14818 *, unsigned *) __asm__("func_00414338");
extern unsigned char *f14818_leb(unsigned char *, int *) __asm__("func_00413B38");
extern void f14818_memset(void *, int, int) __asm__("func_00416210");
struct St14818 *func_00414818(unsigned pc, struct St14818 *out) {
    struct Ctx14818 ctx;
    struct SI14818 st;
    int *fde;
    int *cie;
    unsigned char *insn;
    unsigned char *end;
    unsigned char *start;
    int len;
    unsigned fpc;
    fde = f14818_find(pc);
    if (fde == 0) return 0;
    insn = f14818_cie(fde, &ctx);
    if (insn == 0) return 0;
    f14818_memset(&st, 0, sizeof(st));
    st.s.ra = ctx.f10;
    cie = (int *)((char *)fde - (fde[1] - 4));
    end = (unsigned char *)cie + *cie + 4;
    st.s.f4 = ctx.f4;
    do {
    if (insn < end) {
        start = (unsigned char *)(fde + 4);
        do {
            insn = f14818_exec(insn, &st, &ctx, 0);
        } while (insn < end);
    } else {
        start = (unsigned char *)(fde + 4);
    }
    } while (0);
    insn = start;
    if (*ctx.aug == 'z') {
        insn = f14818_leb(insn, &len) + len;
    }
    end = (unsigned char *)fde + *fde + 4;
    fpc = fde[2];
    if (insn < end && pc >= fpc) {
        do {
            insn = f14818_exec(insn, &st, &ctx, &fpc);
        } while (insn < end && pc >= fpc);
    }
    *out = st.s;
    return out;}
#endif

//100%
INCLUDE_ASM("seg/seg_313F58", func_004149F0);
#ifdef SKIP_ASM
struct K { int f0; int f4; int key; };
struct L { struct K **items; unsigned n; };
struct M { struct K **arr; int n; };
void func_004149F0(struct L *a, struct M *out) {
    unsigned n = a->n;
    unsigned link[n];
    unsigned top = -1;
    unsigned i;
    unsigned p;
    for (i = 0; i < n; i++) {
        p = top;
        if (p != -1 && a->items[i]->key - a->items[p]->key < 0) {
            do {
                out->arr[out->n++] = a->items[p];
                a->items[p] = 0;
                p = link[p];
                if (p == -1) break;
            } while (a->items[i]->key - a->items[p]->key < 0);
        }
        top = i;
        link[i] = p;
    }
    p = 0;
    for (i = 0; i < n; i++) {
        struct K *k = a->items[i];
        if (k) a->items[p++] = k;
    }
    a->n = p;
}
#endif
