/**
 * \file Ifx_Console.h
 * \brief Main Console module header file
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:36 GMT$
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
 * \defgroup library_srvsw_sysse_comm_console Console
 * This module implements "Main Console" functions
 * \ingroup library_srvsw_sysse_comm
 *
 */
#ifndef IFX_CONSOLE_H
#define IFX_CONSOLE_H               1

#include "StdIf/IfxStdIf_DPipe.h"

//----------------------------------------------------------------------------------------
#if !defined(IFX_CFG_CONSOLE_INDENT_SIZE)
#define IFX_CFG_CONSOLE_INDENT_SIZE (4) /**<\brief Default indentation/alignment size */
#endif

typedef struct
{
    IfxStdIf_DPipe *standardIo;       /**<\brief Pointer to the \ref IfxStdIf_DPipe object used as general console */
    sint16          align;            /**<\brief Variable for storing the actual (left)indentation level of the \ref Ifx_g_console */
} Ifx_Console;

IFX_EXTERN Ifx_Console Ifx_g_console; /**< \brief Default main console global variable */

//----------------------------------------------------------------------------------------
/** \addtogroup library_srvsw_sysse_comm_console
 * \{ */

#ifndef CONSOLE

/* FIXME (Alann to discuss with Dian) there is no requirement to define multiple console, CONSOLE should be removed, and APIs used instead */
/** \brief Alias \ref Ifx_g_console object (by value) */
#define CONSOLE Ifx_g_console

/** \brief Return pointer to the default console object
 *
 * User can override this function by defining new \ref CONSOLE macro and this function
 * externally, e.g. inside Ifx_Cfg.h file.*/
IFX_INLINE IfxStdIf_DPipe *Ifx_Console_getIo(void)
{
    return Ifx_g_console.standardIo;
}


#endif

IFX_EXTERN void    Ifx_Console_init(IfxStdIf_DPipe *standardIo);
IFX_EXTERN boolean Ifx_Console_print(pchar format, ...);
IFX_EXTERN boolean Ifx_Console_printAlign(pchar format, ...);

/**
 * \brief Decrement the alignment/indentation using the given value
 * \param value the increment. If value == 0, \ref IFX_CFG_CONSOLE_INDENT_SIZE will be used.
 */
IFX_INLINE void Ifx_Console_decrAlign(sint16 value)
{
    value               = (sint16)(Ifx_g_console.align - ((value == 0U) ? IFX_CFG_CONSOLE_INDENT_SIZE : value));
    Ifx_g_console.align = (value > 0) ? value : 0;
}


/**
 * \brief Increment the alignment/indentation using the given value
 * \param value the increment. If value == 0, \ref IFX_CFG_CONSOLE_INDENT_SIZE will be used.
 */
IFX_INLINE void Ifx_Console_incrAlign(sint16 value)
{
    Ifx_g_console.align += ((value == 0) ? (sint16)IFX_CFG_CONSOLE_INDENT_SIZE : value);
}


/** \} */
//----------------------------------------------------------------------------------------
#endif
