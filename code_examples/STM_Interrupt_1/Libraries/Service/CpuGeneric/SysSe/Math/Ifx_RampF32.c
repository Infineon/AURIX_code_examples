/**
 * \file Ifx_RampF32.c
 * \brief Ramp function
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

#include "SysSe/Math/Ifx_RampF32.h"

/**
 * \brief Execute the Ramp function
 *
 * NOTE: shall be called every 'period'.
 * The period was defined by Ifx_RampF32_init() or Ifx_RampF32_setSlewRate()
 *
 * \param ramp Pointer to the Ifx_RampF32 object
 * \return Actual value
 */
float32 Ifx_RampF32_step(Ifx_RampF32 *ramp)
{
    if (ramp->uk < ramp->ik)
    {
        ramp->uk = __minf(ramp->ik, ramp->uk + ramp->delta);
    }
    else if (ramp->uk > ramp->ik)
    {
        ramp->uk = __maxf(ramp->ik, ramp->uk - ramp->delta);
    }
    else
    {}

    return ramp->uk;
}
