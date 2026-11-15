/* .vutext (0x42E590-0x43CE00): the VU microcode DMA chains, assembled from the ee-dvp-as sources in this
 * directory (configure.py, DVP_AS). obj/vutext/vutext.bin is their .vutext sections joined in address order. */
.include "macro.inc"

.section .text, "ax"

glabel D_0042E590
.incbin "obj/vutext/vutext.bin"
/* zero fill up to 0x43CE00, where .data starts */
.space 0x90
endlabel D_0042E590
