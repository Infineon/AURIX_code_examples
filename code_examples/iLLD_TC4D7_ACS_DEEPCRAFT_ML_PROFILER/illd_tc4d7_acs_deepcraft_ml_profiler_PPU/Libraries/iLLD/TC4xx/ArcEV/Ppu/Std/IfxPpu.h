/**
 * \file IfxPpu.h
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

#ifndef IFXPPU_H
#define IFXPPU_H 1

#include "Ifx_Types.h"
#include "Compilers.h"
#if defined (__CARC__)
#include <sfr/regppu.sfr>
#endif

IFX_INLINE void IfxPpu_setVccmRegion(uint8 region)
{
#if defined (__CCAC__)
	_sr(((uint32)region << 28), 0x544U);
#endif
#if defined (__CARC__)
	AUX_VECMEM_REGION = ((uint32)region << 28);
#endif
}

IFX_INLINE uint8 IfxPpu_getVccmRegion(uint32 *region)
{
#if defined (__CCAC__)
	return (uint8)(_lr(0x544U) >> 28);
#endif
#if defined (__CARC__)
	return (uint8)(AUX_VECMEM_REGION >> 28);
#endif
}

IFX_INLINE void IfxPpu_requestTricoreToWriteToBits(uint32 *address, uint32 value, uint32 mask)
{

}

/******************************************************************************/
/*--------------------------Mutex and Semaphore-------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Maximum spin iterations waiting for the internal spinlock to be released.
 * The spinlock protects only 3 instructions and should free in nanoseconds.
 * If this timeout expires, the spinlock holder has crashed - catastrophic system error.
 * Override in Ifx_Cfg.h.
 */
#ifndef IFXPPU_SPINLOCK_TIMEOUT
#define IFXPPU_SPINLOCK_TIMEOUT   (10000U)
#endif

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Counting/binary semaphore with integrated companion spinlock.
 *
 *  Initialise with IfxPpu_initSemaphore() before use.
 *
 * Binary semaphore:  initialCount = 1 (one resource, mutually exclusive).
 * Counting semaphore: initialCount = N (N resources available).
 */
typedef struct
{
    volatile uint32 count;      /**< \brief Resource count (0 = none available) */
    volatile uint32 maxCount;   /**< \brief Maximum resource count (upper bound for release) */
    volatile uint32 spinlock;   /**< \brief Internal spinlock - do not access directly */
} IfxPpu_Semaphore;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Atomic exchange intrinsic for ARC core.
 * Atomically swaps the value at *ptr with 'with' and returns the old value.
 * Uses the ARC EX instruction which performs an uninterruptible read-modify-write.
 *
 * \param[in] with  The new value to write into *ptr.
 * \param[in] ptr   Pointer to the memory location to exchange.
 *
 * \return The old value that was at *ptr before the swap.
 */
IFX_INLINE __attribute__ ((always_inline)) unsigned int __ex(unsigned int with, volatile void *ptr)
{
    __asm__ volatile (" ex  %0, [%1]"
            : "=r" (with), "=r" (ptr)
            : "0" (with), "1" (ptr)
            : "memory");
    return (with);
}

/** \brief Initialise a semaphore before first use.
 *
 * \param[out] semaphore    Pointer to the IfxPpu_Semaphore to initialise.
 * \param[in]  initialCount Initial resource count (1 = binary, N = counting).
 *
 * \retval None
 */
IFX_INLINE void IfxPpu_initSemaphore(IfxPpu_Semaphore *semaphore, uint32 initialCount);

/** \brief Initialise a mutex before first use.
 *
 * Sets the mutex to the unlocked state (0). Must be called before the first
 * call to IfxPpu_acquireMutex() or IfxPpu_releaseMutex().
 *
 * \param[out] lock Pointer to the mutex variable (volatile uint32).
 *
 * \retval None
 */
IFX_INLINE void IfxPpu_initMutex(volatile void *lock);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Acquire a mutex.
 * Uses atomic exchange to set the lock. If the lock was previously free (0),
 * acquisition succeeds and returns TRUE. If already held (1), returns FALSE.
 *
 * \param[inout] lock Pointer to the mutex variable.
 *
 * \retval TRUE  If mutex was successfully acquired (lock was free).
 *         FALSE If mutex is already held.
 */
IFX_EXTERN boolean IfxPpu_acquireMutex(volatile void *lock);

/** \brief Release a previously acquired mutex.
 * Writes 0 to the lock variable to release it.
 *
 * \param[inout] lock Pointer to the mutex variable.
 *
 * \retval None
 */
IFX_EXTERN void IfxPpu_releaseMutex(volatile void *lock);

/** \brief Acquire a semaphore.
 *
 * Acquires the internal spinlock (with timeout), then checks the resource count:
 *   - If count > 0: decrements it and returns TRUE.
 *   - If count == 0: no resources available, returns FALSE immediately.
 *
 * The internal spinlock guards only the 3-instruction read-modify-write of count.
 * It exits in nanoseconds under normal operation. If IFXPPU_SPINLOCK_TIMEOUT
 * expires, the spinlock holder has crashed - returns FALSE as a fault indicator.
 *
 * Works for both binary (initialCount=1) and counting (initialCount=N) semaphores.
 *
 * \param[inout] semaphore Pointer to IfxPpu_Semaphore.
 *
 * \retval TRUE  If one resource was acquired (count was > 0, now decremented).
 *         FALSE If no resources are available, or if the spinlock timed out.
 */
IFX_EXTERN boolean IfxPpu_acquireSemaphore(IfxPpu_Semaphore *semaphore);

/** \brief Release a semaphore.
 *
 * Acquires the internal spinlock (with timeout), then checks the resource count:
 *   - If count < maxCount: increments it and returns TRUE.
 *   - If count == maxCount: already at maximum, returns FALSE (overflow protection).
 *
 * If IFXPPU_SPINLOCK_TIMEOUT expires, the spinlock holder has crashed.
 * Returns FALSE as a fault indicator - caller should trigger fault handling.
 *
 * \param[inout] semaphore Pointer to IfxPpu_Semaphore.
 *
 * \retval TRUE  If the semaphore was successfully released (count incremented).
 *         FALSE If count is already at maxCount, or if the spinlock timed out.
 */
IFX_EXTERN boolean IfxPpu_releaseSemaphore(IfxPpu_Semaphore *semaphore);

/******************************************************************************/
/*---------------------Inline Function Implementations-----------------------*/
/******************************************************************************/

IFX_INLINE void IfxPpu_initSemaphore(IfxPpu_Semaphore *semaphore, uint32 initialCount)
{
    semaphore->count    = initialCount;
    semaphore->maxCount = initialCount;
    semaphore->spinlock = 0U;
}


IFX_INLINE void IfxPpu_initMutex(volatile void *lock)
{
    (*(volatile unsigned int *)lock) = 0U;
}


#endif /* IFXPPU_H */
