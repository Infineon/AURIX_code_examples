/**
 * \file Bsp.c
 * \brief Board support package
 * \ingroup library_srvsw_sysse_bsp_bsp
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
#if !defined(IFX_ILLD_PPU_USAGE) 
void initTime(void)
{
    uint64 Fsys = IfxStm_getFrequency();

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
#endif

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

/** \brief PPU get ticks for delay function.
 *
 * \param microsecond argument specifies the time parameter in microseconds.
 *
 * \return Return the ticks of microseconds.
 */
#if defined(IFX_ILLD_PPU_USAGE)
Ifx_TickTime getPpuTicks(uint32 microseconds)
{

	uint64 Fppu = IfxClock_getPpuFrequency();
	return (Fppu / (1000000)) * microseconds;
}
#endif
