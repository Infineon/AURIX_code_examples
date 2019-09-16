/**
 * \file Ifx_Console.c
 * \brief Main Ifx_Console module implementation file
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-03-13 15:49:47 GMT$
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

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "Ifx_Console.h"
#include "_Utilities/Ifx_Assert.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

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
