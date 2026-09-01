/**
 * \file Ifx_LutSincosF32.c
 * \brief Sin/Cos lookup functions with fixed-point angle data type
 *
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
