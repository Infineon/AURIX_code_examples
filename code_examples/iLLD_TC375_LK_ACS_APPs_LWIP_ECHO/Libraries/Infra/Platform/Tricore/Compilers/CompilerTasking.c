/**
 * \file CompilerTasking.c
 *
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:41 GMT$
 *
 *                                 IMPORTANT NOTICE
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

#include "Cpu/Std/Ifx_Types.h"
#include "Compilers.h"

#if defined(__TASKING__)
/*!
 * \brief   Initializes C variables
 *
 * This function is called in the startup. This function initialize the all variables in .data section
 * and clears the .bss section
 *
 * Parameters: Nil
 * Return: Nil
 */
void Ifx_C_Init(void)
{
    extern void _c_init(void);

    _c_init();                  /* initialize data */
}


#endif
