/**
 * \file Ifx_DateTime.h
 * \brief Date and time functions.
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:40 GMT$
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
 * \defgroup library_srvsw_sysse_time_datetime DateTime
 * This module implements the Date-Time functions.
 * \ingroup library_srvsw_sysse_time
 */

#ifndef REALTIME_H_
#define REALTIME_H_ 1
#include "Cpu/Std/Ifx_Types.h"
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
