/**
 * \file Ifx_LowPassPt1F32.c
 * \brief Low pass filter PT1
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

//------------------------------------------------------------------------------
#include "Ifx_LowPassPt1F32.h"
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
