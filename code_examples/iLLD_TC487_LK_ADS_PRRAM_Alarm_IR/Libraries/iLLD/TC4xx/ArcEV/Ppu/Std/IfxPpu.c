/**
 * \file IfxPpu.c
 * \brief PPU mutex and semaphore implementations using ARC atomic exchange.
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxPpu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxPpu_acquireMutex(volatile void *lock)
{
    boolean retVal      = FALSE;
    uint32  spinLockVal = 1U;

    /* Atomically swap 1 into lock, get previous value back */
    spinLockVal = (uint32)__ex(spinLockVal, ((volatile unsigned int *)lock));

    /* If previous value was 0 (unlocked), we successfully acquired the mutex */
    if (spinLockVal == 0U)
    {
        retVal = TRUE;
    }

    return retVal;
}


void IfxPpu_releaseMutex(volatile void *lock)
{
    /* Release the mutex by writing 0 (unlocked) */
    (*(volatile unsigned int *)lock) = 0U;
}


boolean IfxPpu_acquireSemaphore(IfxPpu_Semaphore *semaphore)
{
    boolean retVal      = FALSE;
    uint32  spinTimeout = IFXPPU_SPINLOCK_TIMEOUT;
    uint32  count;

    /* Acquire the internal spinlock with timeout.
     * Timeout fires only if the holder has crashed (catastrophic system error). */
    while (__ex(1U, (volatile unsigned int *)&semaphore->spinlock) != 0U)
    {
        spinTimeout--;
        if (spinTimeout == 0U)
        {
            break;   /* Spinlock holder crashed - exit loop */
        }
    }

    if (spinTimeout > 0U)
    {
        /* Spinlock held - safe to read-modify-write the count */
        count = semaphore->count;
        if (count > 0U)
        {
            semaphore->count = count - 1U;
            retVal = TRUE;
        }

        /* Release the spinlock */
        semaphore->spinlock = 0U;
    }

    return retVal;
}


boolean IfxPpu_releaseSemaphore(IfxPpu_Semaphore *semaphore)
{
    boolean retVal      = FALSE;
    uint32  spinTimeout = IFXPPU_SPINLOCK_TIMEOUT;

    /* Acquire the internal spinlock with timeout */
    while (__ex(1U, (volatile unsigned int *)&semaphore->spinlock) != 0U)
    {
        spinTimeout--;
        if (spinTimeout == 0U)
        {
            break;   /* Spinlock holder crashed - exit loop */
        }
    }

    if (spinTimeout > 0U)
    {
        /* Spinlock held - safe to increment the count if below max */
        if (semaphore->count < semaphore->maxCount)
        {
            semaphore->count = semaphore->count + 1U;
            retVal = TRUE;
        }

        /* Release the spinlock */
        semaphore->spinlock = 0U;
    }

    return retVal;
}
