/**
 * \file Ifx_Lut.h
 * \brief Lookup defintion with fixed-point angle data type
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
 * \defgroup library_srvsw_sysse_math_lut Look-ups
 * \ingroup library_srvsw_sysse_math
 *
 * \defgroup library_srvsw_sysse_math_f32_lut Look-ups float32
 * \ingroup library_srvsw_sysse_math_lut
 *
 */
#ifndef IFX_LUT_H
#define IFX_LUT_H
//________________________________________________________________________________________
#include "Cpu/Std/IfxCpu_Intrinsics.h"
//________________________________________________________________________________________
#ifndef IFX_LUT_TABLE_CONST
/** \brief 0 = Lookup tables are generated and stored in RAM,
 * 1 = Lookup tables are precompiled and stored in FLASH */
#define IFX_LUT_TABLE_CONST (1)
#endif

#if (IFX_LUT_TABLE_CONST != 0)
/** \brief Lookup table type modifier (stored in ROM) */
#   define IFX_LUT_TABLE    const
#else
/** \brief Lookup table type modifier (stored in RAM) */
#   define IFX_LUT_TABLE
#endif

/** \brief Define the resolution (in bits) of cosinus and sinus table \ingroup library_srvsw_sysse_math_lut */
#define IFX_LUT_ANGLE_BITS       (12)

/** \brief Define the cosinus and sinus table size \ingroup library_srvsw_sysse_math_lut */
#define IFX_LUT_ANGLE_RESOLUTION (1 << IFX_LUT_ANGLE_BITS)

/** \brief Value used as 180 degree angle */
#define IFX_LUT_ANGLE_PI         (IFX_LUT_ANGLE_RESOLUTION / 2)

//________________________________________________________________________________________
/** \brief Fixed-point angle type.
 *
 * Resolution is defined by \ref IFX_LUT_ANGLE_RESOLUTION */
typedef sint32 Ifx_Lut_FxpAngle;

/** \brief Convert from float32 angle in radian into fixed-point angle type */
#define IFX_LUT_F32_TO_FXPANGLE(f)  ((Ifx_Lut_FxpAngle)(f / IFX_PI * IFX_LUT_ANGLE_PI))

/** \brief Convert from fixed-point angle type to float32 angle in radian */
#define IFX_LUT_FXPANGLE_TO_F32(fx) ((float32)fx * IFX_PI / IFX_LUT_ANGLE_PI)

//________________________________________________________________________________________
#if (1U << IFX_LUT_ANGLE_BITS) != IFX_LUT_ANGLE_RESOLUTION
#error (1U << IFX_LUT_ANGLE_BITS) != IFX_LUT_ANGLE_RESOLUTION
#endif
//________________________________________________________________________________________
#endif /* IFX_LUT_H */
