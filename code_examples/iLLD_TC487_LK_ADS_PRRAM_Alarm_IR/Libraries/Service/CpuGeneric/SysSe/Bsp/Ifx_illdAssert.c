/**
 * \file Ifx_illdAssert.c
 * \brief Assert functions.
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 */

#include "Ifx_illdAssert.h"

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
