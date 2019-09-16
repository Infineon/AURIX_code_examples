/**
 * \file Ifx_LutLinearF32.h
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
 * \defgroup library_srvsw_sysse_math_f32_lut_linear Look-up table (with linear interpolation)
 * \ingroup library_srvsw_sysse_math_f32_lut
 *
 */

#ifndef IFX_LUTLINEARF32_H
#define IFX_LUTLINEARF32_H

//________________________________________________________________________________________
// INCLUDES
#include "Cpu/Std/Ifx_Types.h"

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
