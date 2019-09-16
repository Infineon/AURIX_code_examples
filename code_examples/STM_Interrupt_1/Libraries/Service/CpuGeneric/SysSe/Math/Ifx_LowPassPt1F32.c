/**
 * \file Ifx_LowPassPt1F32.c
 * \brief Low pass filter PT1
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

//------------------------------------------------------------------------------
#include "SysSe/Math/Ifx_LowPassPt1F32.h"
//------------------------------------------------------------------------------

/** \brief Set the low pass filter configuration
 *
 * This function sets the low pass filter  configuration and reset the filter output.
 *
 * \param filter Specifies PT1 filter.
 * \param config Specifies the PT1 filter configuration.
 *
 * \return None
 */
void Ifx_LowPassPt1F32_init(Ifx_LowPassPt1F32 *filter, const Ifx_LowPassPt1F32_Config *config)
{
    float32 tStar;
    float32 T = 1 / config->cutOffFrequency;
    tStar       = 1 / (T / config->samplingTime + 1);

    filter->a   = config->gain * tStar;
    filter->b   = tStar;
    filter->out = 0;
}


/** \brief Execute the low pass filter
 * \param filter Specifies PT1 filter.
 * \param input Specifies the filter input.
 *
 * \return Returns the filter output
 */
float32 Ifx_LowPassPt1F32_do(Ifx_LowPassPt1F32 *filter, float32 input)
{
    filter->out = filter->out + filter->a * input - filter->b * filter->out;
    return filter->out;
}
