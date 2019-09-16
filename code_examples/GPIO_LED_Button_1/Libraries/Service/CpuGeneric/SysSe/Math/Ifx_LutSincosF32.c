/**
 * \file Ifx_LutSincosF32.c
 * \brief Sin/Cos lookup functions with fixed-point angle data type
 *
 *
 * \version disabled
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
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
#include "Ifx_LutSincosF32.h"

#include <math.h>

void Ifx_LutSincosF32_init(void)
{
#if IFX_LUT_TABLE_CONST == 0
    {   /* generate sin and cos table */
        sint32 k;

        for (k = 0; k <= (IFX_LUT_ANGLE_PI / 2); k++)
        {
            Ifx_g_LutSincosF32_table[k] = sinf((IFX_PI * 2 * k) / IFX_LUT_ANGLE_RESOLUTION);
        }
    }
#endif
}


float32 Ifx_LutSincosF32_sin(Ifx_Lut_FxpAngle fxpAngle)
{
    float32 result;
    fxpAngle = fxpAngle & (IFX_LUT_ANGLE_RESOLUTION - 1);

    if (fxpAngle < (IFX_LUT_ANGLE_PI / 2))
    {
        result = Ifx_g_LutSincosF32_table[fxpAngle];
    }
    else if (fxpAngle < IFX_LUT_ANGLE_PI)
    {
        fxpAngle = IFX_LUT_ANGLE_PI - fxpAngle;
        result   = Ifx_g_LutSincosF32_table[fxpAngle];
    }
    else if (fxpAngle < (IFX_LUT_ANGLE_PI / 2 * 3))
    {
        fxpAngle = fxpAngle - IFX_LUT_ANGLE_PI;
        result   = -Ifx_g_LutSincosF32_table[fxpAngle];
    }
    else
    {
        fxpAngle = IFX_LUT_ANGLE_RESOLUTION - fxpAngle;
        result   = -Ifx_g_LutSincosF32_table[fxpAngle];
    }

    return result;
}
