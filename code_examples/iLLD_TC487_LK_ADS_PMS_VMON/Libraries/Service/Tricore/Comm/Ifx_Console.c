/**
 * \file Ifx_Console.c
 * \brief Main Ifx_Console module implementation file
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

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "Ifx_Console.h"
#include "_Utilities/Ifx_Assert.h"
#if defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxPpu_Intrinsics.h"
#else
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif

Ifx_Console Ifx_g_console;

/**
 * \brief Initialize the \ref Ifx_g_console object.
 * \param standardIo Pointer to the IfxStdIf_DPipe object used by the \ref Ifx_g_console.
 */
void Ifx_Console_init(IfxStdIf_DPipe *standardIo)
{
    Ifx_g_console.standardIo = standardIo;
    Ifx_g_console.align      = 0;
}


/**
 * \brief Print formatted string into \ref Ifx_g_console.
 * \param format printf-compatible formatted string.
 * \retval TRUE if the string is printed successfully
 * \retval FALSE if the function failed.
 */
boolean Ifx_Console_print(pchar format, ...)
{
    if (!Ifx_g_console.standardIo->txDisabled)
    {
        char      message[STDIF_DPIPE_MAX_PRINT_SIZE + 1];
        Ifx_SizeT count;
        va_list   args;
        va_start(args, format);
        vsprintf((char *)message, format, args);
        va_end(args);
        count = (Ifx_SizeT)strlen(message);
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, count < STDIF_DPIPE_MAX_PRINT_SIZE);

        return IfxStdIf_DPipe_write(Ifx_g_console.standardIo, (void *)message, &count, TIME_INFINITE);
    }
    else
    {
        return TRUE;
    }
}


/**
 * \brief Print formatted string into \ref Ifx_g_console.
 * Indented with a number of spaces.
 * \param format printf-compatible formatted string.
 * \retval TRUE if the string is printed successfully
 * \retval FALSE if the function failed.
 */
boolean Ifx_Console_printAlign(pchar format, ...)
{
    if (!Ifx_g_console.standardIo->txDisabled)
    {
        char      message[STDIF_DPIPE_MAX_PRINT_SIZE + 1];
        Ifx_SizeT align, count;
        char      spaces[17] = "                ";
        va_list   args;
        va_start(args, format);
        vsprintf((char *)message, format, args);
        va_end(args);
        count = (Ifx_SizeT)strlen(message);
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, count < STDIF_DPIPE_MAX_PRINT_SIZE);
        align = Ifx_g_console.align;

        while (align > 0)
        {
            Ifx_SizeT scount;
            scount = __min(align, 10);
            IfxStdIf_DPipe_write(Ifx_g_console.standardIo, (void *)spaces, &scount, TIME_INFINITE);
            align  = align - scount;
        }

        return IfxStdIf_DPipe_write(Ifx_g_console.standardIo, (void *)message, &count, TIME_INFINITE);
    }
    else
    {
        return TRUE;
    }
}
