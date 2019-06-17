/**
 * \file CompilerDcc.c
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:39 GMT$
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

#include "Cpu/Std/Ifx_Types.h"
#include "Compilers.h"

#if defined(__DCC__)
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
    extern void __init_main(void);

    __init_main();              /* initialize data */
}


#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER
/*Dummy main function
 * This function is required only for the Windriver, which looks for main while linking
 * ! DO NOT USE THIS FUNCTION !*/
int main(void)
{
    return 0;
}


#endif /*IFX_CFG_USE_COMPILER_DEFAULT_LINKER */
#endif
