/**
 * \file Bsp.c
 * \brief Board support package
 * \ingroup library_srvsw_sysse_bsp_bsp
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:34 GMT$
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
 */

#include "Bsp.h"

Ifx_TickTime TimeConst[TIMER_COUNT];

/** \brief Initialize the time constants.
 *
 * Initialize the time constants TimeConst_0s, TimeConst_100ns, TimeConst_1us,
 * TimeConst_10us, TimeConst_100us, TimeConst_1ms, TimeConst_10ms, TimeConst_100ms,
 * TimeConst_1s, TimeConst_10s
 * \return None.
 */
void initTime(void)
{
    sint32 Fsys = IfxStm_getFrequency(BSP_DEFAULT_TIMER);

    TimeConst[TIMER_INDEX_10NS]  = Fsys / (1000000000 / 10);
    TimeConst[TIMER_INDEX_100NS] = Fsys / (1000000000 / 100);
    TimeConst[TIMER_INDEX_1US]   = Fsys / (1000000 / 1);
    TimeConst[TIMER_INDEX_10US]  = Fsys / (1000000 / 10);
    TimeConst[TIMER_INDEX_100US] = Fsys / (1000000 / 100);
    TimeConst[TIMER_INDEX_1MS]   = Fsys / (1000 / 1);
    TimeConst[TIMER_INDEX_10MS]  = Fsys / (1000 / 10);
    TimeConst[TIMER_INDEX_100MS] = Fsys / (1000 / 100);
    TimeConst[TIMER_INDEX_1S]    = Fsys * (1);
    TimeConst[TIMER_INDEX_10S]   = Fsys * (10);
    TimeConst[TIMER_INDEX_100S]  = Fsys * (100);
}


/** \brief Wait function.
 *
 * This is an empty function that just spend some time waiting.
 *
 * \return None.
 */
void waitPoll(void)
{}

/** \brief Wait time function.
 *
 * This is an empty function that that returns after the timeout elapsed. The
 * minimal time spend in the function is guaranteed, but not the max time.
 *
 * \param timeout Specifies the time the function waits for before returning
 *
 * \return None.
 */
void waitTime(Ifx_TickTime timeout)
{
    wait(timeout);
}
