/*****************************************************************************
*
* Copyright (C) 2022 Infineon Technologies AG. All rights reserved.
*
* Infineon Technologies AG (INFINEON) is supplying this file for use
* exclusively with Infineon's microcontroller products. This file can be freely
* distributed within development tools and software supporting such microcontroller
* products.
*
* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
* INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
*
******************************************************************************/
/*! \file Ifx_warnAboutUnimplementedMode.c
 */

#include "dsplib-internal.h"

//mn #define MAX_WARNINGS 10
#define MAX_WARNINGS 1000

static uint32 num_warnings = 0;

static char * 
get_mode_string (enum Ifx_mode mode)
{
    char * result;
    switch (mode) {
    case IFX_MODE_EXTERNAL_LIBRARY:
        result = "EXTERNAL_LIBRARY";
        break;
    case IFX_MODE_REFERENCE_IMPLEMENTATION:
        result="REFERENCE_IMPLEMENTATION";
        break;
    case IFX_MODE_OPTIMIZED_C:
        result="OPTIMIZED_C";
        break;
    case IFX_MODE_OPTIMIZED_ASM:
        result="OPTIMIZED_ASM";
        break;
    case IFX_MODE_HARDWARE_ACCELERATOR:
        result="HARDWARE_ACCELERATOR";
        break;
    case IFX_MODE_LOOKUP_TABLE:
        result="LOOKUP_TABLE";
        break;
    case IFX_MODE_LOOKUP_TABLE_WITH_INTERPOLATION:
        result="LOOKUP_TABLE_WITH_INTERPOLATION";
        break;
    default:
        result = (char*) malloc (50);
        sprintf (result, "unkown mode %d", mode);
    }
    return result;
}

void 
Ifx_warnAboutUnimplementedMode (enum Ifx_mode mode, const char * name)
{
    num_warnings++;
    if (num_warnings > MAX_WARNINGS) 
        return;
    if (num_warnings == MAX_WARNINGS)
        Ifx_error (IFX_ERR_WARN, 
                   "encountered %d warnings, turning off message\n",
                   num_warnings);
    if (num_warnings < MAX_WARNINGS)
    	Ifx_error (IFX_ERR_WARN,
                   "%s mode %s not implemented\n\r", name,
                   get_mode_string (mode));
}
