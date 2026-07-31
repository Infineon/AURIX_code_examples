/**
 * \file Icu.h
 * \brief ICU interface
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
 * \defgroup library_srvsw_if_icu ICU interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef ICU_H
#define ICU_H 1

#include "Ifx_Types.h"

typedef struct Icu_s Icu;
typedef void       (*Icu_StartCapture)(Icu *handle);
typedef void       (*Icu_StopCapture)(Icu *handle);
typedef void       (*Icu_GetTimeStamp)(Icu *handle);

typedef struct
{
    Icu_StartCapture startCapture;
    Icu_StopCapture  stopCapture;
    Icu_GetTimeStamp getTimeStamp;
} Icu_Functions;

/** \brief Structure of the Icu interface */
struct Icu_s
{
    float32       frequency;      /**< \brief dummy member to avoid error */
#if IFX_CFG_USE_STANDARD_INTERFACE
    Icu_Functions functions;      /**< \brief Actual timer period */
#endif
};

/** \brief Configuration structure of the Icu interface */
typedef struct
{
    float32 frequency;             /**< \brief dummy member to avoid error */
//	  IfxCcu6_Timer	*timer;
} Icu_Config;

#if IFX_CFG_USE_STANDARD_INTERFACE
IFX_INLINE void Icu_startCapture(Icu *handle) {handle->functions.startCapture(handle); }
IFX_INLINE void Icu_stopCapture(Icu *handle)  {handle->functions.stopCapture(handle); }
IFX_INLINE void Icu_getTimeStamp(Icu *handle) {handle->functions.getTimeStamp(handle); }
#endif

#endif /* ICU_H_ */
