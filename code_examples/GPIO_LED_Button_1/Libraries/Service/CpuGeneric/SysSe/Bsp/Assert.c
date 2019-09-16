/**
 * \file Assert.c
 * \brief Assert functions.
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:29 GMT$
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include "Assert.h"

#if IFX_CFG_ASSERT_STDIO == 1
/** Current standard IO used for the IFX_ASSERT and IFX_VALIDATE */
IfxStdIf_DPipe *Assert_io = NULL_PTR;
#endif

#if IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT > IFX_VERBOSE_LEVEL_OFF
uint32          Assert_verboseLevel = IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT;
#endif

#if IFX_CFG_ASSERT_STDIO == 1
void Ifx_Assert_setStandardIo(IfxStdIf_DPipe *standardIo)
{
    Assert_io = standardIo;
}


#endif

/** \internal
 * Text used to display the king of assertion
 */
const pchar Assert_level[6] = {
    "OFF",
    "FAILURE",
    "ERROR",
    "WARNING",
    "INFO",
    "DEBUG"
};

void Ifx_Assert_doLevel(uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function)
{
#if IFX_CFG_ASSERT_USE_BREAKPOINT == 1

    if (level <= IFX_VERBOSE_LEVEL_ERROR)
    {
        __debug();
    }

#endif

#if IFX_CFG_ASSERT_STDIO == 1

    if (Assert_io != NULL_PTR)
    {
        IfxStdIf_DPipe_print(Assert_io, "ASSERTION %s '%s' in %s:%u (function '%s()')" ENDL, Assert_level[level],
            __assertion, __file, __line, __function);
    }

#endif
}


boolean Ifx_Assert_doValidate(boolean expr, uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function)
{
    if (!((expr) || (level > Assert_verboseLevel)))
    {
#if IFX_CFG_ASSERT_USE_BREAKPOINT == 1

        if (level <= IFX_VERBOSE_LEVEL_ERROR)
        {
            __debug();
        }

#endif

#if IFX_CFG_ASSERT_STDIO == 1

        if (Assert_io != NULL_PTR)
        {
            IfxStdIf_DPipe_print(Assert_io, "VALIDATION %s '%s' in %s:%u (function '%s()')" ENDL, Assert_level[level],
                __assertion, __file, __line, __function);
        }

#endif
    }
    else
    {}

    return expr;
}
