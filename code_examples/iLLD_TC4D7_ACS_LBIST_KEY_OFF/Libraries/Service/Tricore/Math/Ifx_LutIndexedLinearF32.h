/**
 * \file Ifx_LutIndexedLinearF32.h
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
 * \defgroup library_srvsw_sysse_math_f32_lut_indexedLinear Indexes look-up table (with linear interpolation)
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTINDEXEDLINEARF32_H
#define IFX_LUTINDEXEDLINEARF32_H 1

//________________________________________________________________________________________
// INCLUDES
#include "Ifx_Types.h"

typedef struct
{
    float32 gain;        /**< \brief channel gain */
    float32 offset;      /**< \brief channel offset */
} Ifx_LutIndexedLinearF32_Item;

typedef struct
{
    uint16                                segmentCount;
    sint8                                 shift;
    const Ifx_LutIndexedLinearF32_Item *segments;
} Ifx_LutIndexedLinearF32;

//________________________________________________________________________________________
// FUNCTION PROTOTYPES

/** \addtogroup library_srvsw_sysse_math_f32_lut_indexedLinear
 * \{ */
IFX_INLINE float32 Ifx_LutIndexedLinearF32_search(const Ifx_LutIndexedLinearF32 *ml, uint32 index);
/** \} */

//________________________________________________________________________________________
// INLINE FUNCTION IMPLEMENTATION

/** \brief Look-up table search
*
*
* \param ml pointer to the multi-segment object
* \param index
* \return interpolated value */
IFX_INLINE float32 Ifx_LutIndexedLinearF32_search(const Ifx_LutIndexedLinearF32 *ml, uint32 index)
{
    uint32 i;
    i = index >> ml->shift;

    return (ml->segments[i].gain * index) + ml->segments[i].offset;
}


#endif /* IFX_LUTINDEXEDLINEARF32_H */
