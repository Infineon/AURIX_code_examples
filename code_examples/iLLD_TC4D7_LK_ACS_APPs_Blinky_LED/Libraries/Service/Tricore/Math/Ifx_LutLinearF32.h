/**
 * \file Ifx_LutLinearF32.h
 * \brief Look-up functionality
 *
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
 * \defgroup library_srvsw_sysse_math_f32_lut_linear Look-up table (with linear interpolation)
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTLINEARF32_H
#define IFX_LUTLINEARF32_H 1

//________________________________________________________________________________________
// INCLUDES
#include "Ifx_Types.h"

typedef struct
{
    float32 gain;        /**< \brief channel gain */
    float32 offset;      /**< \brief channel offset */
    float32 boundary;    /**< \brief segment input upper limit */
} Ifx_LutLinearF32_Item;

typedef struct
{
    sint8                          segmentCount;
    const Ifx_LutLinearF32_Item *segments;
} Ifx_LutLinearF32;

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup library_srvsw_sysse_math_f32_lut_linear
 * \{ */
IFX_EXTERN float32 Ifx_LutLinearF32_searchBin(const Ifx_LutLinearF32 *ml, float32 index);
IFX_INLINE float32 Ifx_LutLinearF32_searchNegSeq(const Ifx_LutLinearF32 *ml, float32 index);
IFX_INLINE float32 Ifx_LutLinearF32_searchPosSeq(const Ifx_LutLinearF32 *ml, float32 index);
/** \} */

//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATION

/** \brief Look-up table with positive sequential search implementation
 *
 * Value inside table will be linearly interpolated
 * Value outside table will be linearly extrapolated
 *
 * \param ml pointer to the multi-segment object
 * \param index
 * \return interpolated value */
IFX_INLINE float32 Ifx_LutLinearF32_searchPosSeq(const Ifx_LutLinearF32 *ml, float32 index)
{
    sint8 i = 0;

    while ((index > ml->segments[i].boundary) && (i < ml->segmentCount - 1))
    {
        i++;
    }

    return (ml->segments[i].gain * index) + ml->segments[i].offset;
}


/** \brief Look-up table with negative sequential search implementation
 *
 * Value inside table will be linearly interpolated
 * Value outside table will be linearly extrapolated
 *
 * \param ml pointer to the multi-segment object
 * \param index
 * \return interpolated value */
IFX_INLINE float32 Ifx_LutLinearF32_searchNegSeq(const Ifx_LutLinearF32 *ml, float32 index)
{
    sint8 i = ml->segmentCount - 1;

    while ((i - 1 >= 0) && (index > ml->segments[i - 1].boundary))
    {
        i--;
    }

    return (ml->segments[i].gain * index) + ml->segments[i].offset;
}


#endif /* IFX_LUTLINEARF32_H */
