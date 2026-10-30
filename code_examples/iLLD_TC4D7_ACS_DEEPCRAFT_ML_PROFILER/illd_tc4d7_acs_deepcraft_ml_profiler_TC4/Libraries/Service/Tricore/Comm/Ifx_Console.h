/**
 * \file Ifx_Console.h
 * \brief Main Console module header file
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
 * \defgroup library_srvsw_sysse_comm_console Console
 * This module implements "Main Console" functions
 * \ingroup library_srvsw_sysse_comm
 *
 */
#ifndef IFX_CONSOLE_H
#define IFX_CONSOLE_H 1

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

/* FIXME there is no requirement to define multiple console, CONSOLE should be removed, and APIs used instead */
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
