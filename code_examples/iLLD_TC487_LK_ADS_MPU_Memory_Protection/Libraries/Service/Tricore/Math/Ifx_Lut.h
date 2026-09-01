/**
 * \file Ifx_Lut.h
 * \brief Lookup defintion with fixed-point angle data type
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
 * \defgroup library_srvsw_sysse_math_lut Look-ups
 * \ingroup library_srvsw_sysse_math
 *
 * \defgroup library_srvsw_sysse_math_f32_lut Look-ups float32
 * \ingroup library_srvsw_sysse_math_lut
 *
 */
#ifndef IFX_LUT_H
#define IFX_LUT_H 1
//________________________________________________________________________________________
#if defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxPpu_Intrinsics.h"
#else
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
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
