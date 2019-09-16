/**
 * \file Icu.h
 * \brief ICU interface
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:18 GMT$
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
 * \defgroup library_srvsw_if_icu ICU interface
 * \ingroup library_srvsw_if
 *
 */

#ifndef ICU_H_
#define ICU_H_ 1

#include "Cpu/Std/Ifx_Types.h"

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
