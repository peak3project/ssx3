#include "common.h"

extern "C" void cWorldPainterQuery_reset();

//100%
INCLUDE_ASM("worldpainter/worldpainterman", cWorldPainterMan_reset__FPv);
#ifdef SKIP_ASM
void cWorldPainterMan_reset(void* self)
{
    cWorldPainterQuery_reset();
}
#endif

