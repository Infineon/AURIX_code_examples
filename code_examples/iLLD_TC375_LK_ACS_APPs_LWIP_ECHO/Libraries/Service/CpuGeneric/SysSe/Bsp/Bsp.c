/**
 * \file Bsp.c
 * \brief Board support package
 * \ingroup library_srvsw_sysse_bsp_bsp
 *
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:34 GMT$
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

#include "Bsp.h"


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
