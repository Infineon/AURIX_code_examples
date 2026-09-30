/**
 * \file Ifx_DateTime.h
 * \brief Date and time functions.
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
 * \defgroup library_srvsw_sysse_time_datetime DateTime
 * This module implements the Date-Time functions.
 * \ingroup library_srvsw_sysse_time
 */

#ifndef IFX_DATETIME_H
#define IFX_DATETIME_H 1
#include "Ifx_Types.h"
typedef struct
{
    sint32 hours;
    sint32 minutes;
    sint32 seconds;
} Ifx_DateTime;
/** \addtogroup library_srvsw_sysse_time_datetime
 * \{ */
IFX_EXTERN void DateTime_set(Ifx_DateTime *time);
IFX_EXTERN void DateTime_get(Ifx_DateTime *time);
/** \} */

#endif /* REALTIME_H_ */
