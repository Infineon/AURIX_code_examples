/**
 * \file Ifx_LutIndexedLinearF32.h
 * \brief Look-up functionality
 *
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
 * \defgroup library_srvsw_sysse_math_f32_lut_indexedLinear Indexes look-up table (with linear interpolation)
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTINDEXEDLINEARF32_H
#define IFX_LUTINDEXEDLINEARF32_H

//________________________________________________________________________________________
// INCLUDES
#include "Cpu/Std/Ifx_Types.h"

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
