/**
 * \file Ifx_DateTime.c
 * \brief Date and time functions.
 *
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:37 GMT$
 *
 *                                 IMPORTANT NOTICE
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
 */

#include "Ifx_DateTime.h"
#include "SysSe/Bsp/Bsp.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/
#define TIMER_COUNT       (11)                                      /**< \internal \brief number of timer values defined */
#define TIMER_INDEX_10NS  (0)                                       /**< \internal \brief Index of the time value 10ns*/
#define TIMER_INDEX_100NS (1)                                       /**< \internal \brief Index of the time value 100ns*/
#define TIMER_INDEX_1US   (2)                                       /**< \internal \brief Index of the time value 1us*/
#define TIMER_INDEX_10US  (3)                                       /**< \internal \brief Index of the time value 10us*/
#define TIMER_INDEX_100US (4)                                       /**< \internal \brief Index of the time value 100us*/
#define TIMER_INDEX_1MS   (5)                                       /**< \internal \brief Index of the time value 1ms*/
#define TIMER_INDEX_10MS  (6)                                       /**< \internal \brief Index of the time value 10ms*/
#define TIMER_INDEX_100MS (7)                                       /**< \internal \brief Index of the time value 100ms*/
#define TIMER_INDEX_1S    (8)                                       /**< \internal \brief Index of the time value 1s*/
#define TIMER_INDEX_10S   (9)                                       /**< \internal \brief Index of the time value 10s*/
#define TIMER_INDEX_100S  (10)                                      /**< \internal \brief Index of the time value 100s*/


#define TimeConst_0s    ((Ifx_TickTime)0)                           /**< \brief time constant equal to 1s */
#define TimeConst_10ns  (TimeConst[TIMER_INDEX_10NS])               /**< \brief time constant equal to 10ns */
#define TimeConst_100ns (TimeConst[TIMER_INDEX_100NS])              /**< \brief time constant equal to 100ns */
#define TimeConst_1us   (TimeConst[TIMER_INDEX_1US])                /**< \brief time constant equal to 1us */
#define TimeConst_10us  (TimeConst[TIMER_INDEX_10US])               /**< \brief time constant equal to 10us */
#define TimeConst_100us (TimeConst[TIMER_INDEX_100US])              /**< \brief time constant equal to 100us */
#define TimeConst_1ms   (TimeConst[TIMER_INDEX_1MS])                /**< \brief time constant equal to 1ms */
#define TimeConst_10ms  (TimeConst[TIMER_INDEX_10MS])               /**< \brief time constant equal to 10ms */
#define TimeConst_100ms (TimeConst[TIMER_INDEX_100MS])              /**< \brief time constant equal to 100ms */
#define TimeConst_1s    (TimeConst[TIMER_INDEX_1S])                 /**< \brief time constant equal to 1s */
#define TimeConst_10s   (TimeConst[TIMER_INDEX_10S])                /**< \brief time constant equal to 10s */
#define TimeConst_100s  (TimeConst[TIMER_INDEX_100S])               /**< \brief time constant equal to 100s */

IFX_STATIC Ifx_TickTime TimeConst[TIMER_COUNT];

/* FIXME make compatible to unix time */
sint32 g_DateTimeOffset;

/** \brief Get the real time
 * Note that this function is valid only if DateTime_set() has been called */
void DateTime_get(Ifx_DateTime *dt)
{
    sint32 seconds = (sint32)(now() / TimeConst_1s);

    seconds     = seconds + g_DateTimeOffset;
    dt->hours   = seconds / 3600;
    dt->minutes = seconds / 60;
    dt->minutes = dt->minutes % 60;
    dt->seconds = seconds % 60;
}


/** \brief Set the real time */
void DateTime_set(Ifx_DateTime *dt)
{
    sint32 seconds = dt->seconds - ((sint32)(now() / TimeConst_1s));

    seconds          = seconds + (3600 * dt->hours);
    seconds          = seconds + (60 * dt->minutes);
    g_DateTimeOffset = seconds;
}
