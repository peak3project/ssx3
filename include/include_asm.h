#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H

#if !defined(M2CTX) && !defined(PERMUTER) && !defined(SKIP_ASM)

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        "    .set noat\n" \
        "    .set noreorder\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        "    .set reorder\n" \
        "    .set at\n" \
    )
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__( \
        ".section .rodata\n" \
        "    .include \"" FOLDER "/" #NAME ".s\"\n" \
        ".section .text" \
    )
#endif

#if INCLUDE_ASM_USE_MACRO_INC
__asm__(".include \"include/macro.inc\"\n");
#else
__asm__(".include \"include/labels.inc\"\n");
#endif

#else

#if defined(SKIP_ASM) && defined(ASM_OFFSETS) && !defined(M2CTX) && !defined(PERMUTER)
/* Position-faithful obj/current: place each function at its obj/target offset (tools/asm_offsets.py),
   because SN's assembler pads short loops depending on where they sit. */
__asm__(".include \"asm_offsets.inc\"\n");
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) \
    __asm__( \
        ".section .text\n" \
        ".ifdef __off_" #NAME "\n" \
        ".org __off_" #NAME "\n" \
        ".endif\n" \
        ".ifdef __size_" #NAME "\n" \
        "__fill_" #NAME "\n" \
        ".endif\n" \
        ".previous\n" \
    )
#endif
#endif

#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)
#endif
#ifndef INCLUDE_RODATA
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#endif /* !defined(M2CTX) && !defined(PERMUTER) && !defined(SKIP_ASM) */

#endif /* INCLUDE_ASM_H */
