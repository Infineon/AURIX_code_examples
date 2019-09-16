/**
 * \file Ifx_LutAtan2F32.c
 * \brief ATAN2 lookup functions with fixed-point angle data type
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
#include "Ifx_LutAtan2F32.h"

#include <math.h>

void Ifx_LutAtan2F32_init(void)
{
#if IFX_LUT_TABLE_CONST == 0
    {   /* generate arctan table */
        sint32  k;
        float32 Step, value;
        Step = (double)IFX_LUT_ATAN_LIMIT_LOW / IFX_LUT_ATAN_SIZE_LOW;

        for (k = 0; k < IFX_LUTATAN2F32_SIZE; k++)
        {
            Ifx_g_LutAtan2F32_FxpAngle_table[k] = IFX_LUT_F32_TO_FXPANGLE(atanf(k / Step));
        }
    }
#endif
}


IFX_INLINE Ifx_Lut_FxpAngle Ifx_LutAtan2F32_fxpAnglePrivate(float32 valf)
{
    uint32 vali;
    valf = IFX_LUTATAN2F32_SIZE * valf;
    vali = (uint32)valf;

    if ((valf - (float32)vali) > 0.5)
    {   /* Round to nearest */
        vali++;
    }

    return Ifx_g_LutAtan2F32_FxpAngle_table[vali];
}


IFX_INLINE float32 Ifx_LutAtan2F32_float32Private(float32 val)
{   /* FIXME round to nearest ?? */
    return Ifx_g_LutAtan2F32_table[(int)(val * IFX_LUTATAN2F32_SIZE)];
}


Ifx_Lut_FxpAngle Ifx_LutAtan2F32_fxpAngle(float32 x, float32 y)
{
    Ifx_Lut_FxpAngle angle;
    float32          fx = (float32)x;
    float32          fy = (float32)y;

    if (y < 0)
    {
        if (x < 0)
        {
            if (-y < -x)
            {   // 180 .. 225 deg
                angle = -IFX_LUT_ANGLE_PI + Ifx_LutAtan2F32_fxpAnglePrivate(-fy / -fx);
            }
            else
            {   // 225 .. 270 deg
                angle = -(IFX_LUT_ANGLE_PI / 2) - Ifx_LutAtan2F32_fxpAnglePrivate(-fx / -fy);
            }
        }
        else // x >= 0
        {
            if (-y < x)
            { // 315 .. 360 deg
                angle = -Ifx_LutAtan2F32_fxpAnglePrivate(-fy / fx); // ok
            }
            else
            {                                                         // 225 .. 270 deg
                angle = -(IFX_LUT_ANGLE_PI / 2) + Ifx_LutAtan2F32_fxpAnglePrivate(fx / -fy);
            }
        }
    }
    else // y >= 0
    {
        if (x < 0)
        {
            if (y < -x)
            {                                                                                 // 135 .. 180 deg
                angle = IFX_LUT_ANGLE_PI - Ifx_LutAtan2F32_fxpAnglePrivate(fy / -fx);       // ok
            }
            else
            {                                                                                 // 90 .. 135 deg
                angle = (IFX_LUT_ANGLE_PI / 2) + Ifx_LutAtan2F32_fxpAnglePrivate(-fx / fy); // ok
            }
        }
        else // x >= 0
        {
            if (y < x)
            {                                                                                // 0 .. 45 deg
                angle = Ifx_LutAtan2F32_fxpAnglePrivate(fy / fx);                          // ok
            }
            else
            {                                                                                // 45 .. 90 deg
                angle = (IFX_LUT_ANGLE_PI / 2) - Ifx_LutAtan2F32_fxpAnglePrivate(fx / fy); // ok
            }
        }
    }

    return angle & (IFX_LUT_ANGLE_RESOLUTION - 1);
}


float32 Ifx_LutAtan2F32_float32(float32 y, float32 x)
{
    float32 angle;

    if (y < 0)
    {
        if (x < 0)
        {
            if (-y < -x)
            {   // 180 .. 225 deg
                angle = -IFX_PI + Ifx_LutAtan2F32_float32Private(-y / -x);
            }
            else
            {   // 225 .. 270 deg
                angle = -(IFX_PI / 2) - Ifx_LutAtan2F32_float32Private(-x / -y);
            }
        }
        else // x >= 0
        {
            if (-y < x)
            { // 315 .. 360 deg
                angle = -Ifx_LutAtan2F32_float32Private(-y / x); // ok
            }
            else
            {                                                      // 225 .. 270 deg
                angle = -(IFX_PI / 2) + Ifx_LutAtan2F32_float32Private(x / -y);
            }
        }
    }
    else // y >= 0
    {
        if (x < 0)
        {
            if (y < -x)
            {                                                                    // 135 .. 180 deg
                angle = IFX_PI - Ifx_LutAtan2F32_float32Private(y / -x);       // ok
            }
            else
            {                                                                    // 90 .. 135 deg
                angle = (IFX_PI / 2) + Ifx_LutAtan2F32_float32Private(-x / y); // ok
            }
        }
        else // x >= 0
        {
            if (y < x)
            {                                                                   // 0 .. 45 deg
                angle = Ifx_LutAtan2F32_float32Private(y / x);                // ok
            }
            else
            {                                                                   // 45 .. 90 deg
                angle = (IFX_PI / 2) - Ifx_LutAtan2F32_float32Private(x / y); // ok
            }
        }
    }

    return angle;
}
