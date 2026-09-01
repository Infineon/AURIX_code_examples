/**
 * \file IfxPpu_Timer.h
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

#ifndef IFXPPU_TIMER_H
#define IFXPPU_TIMER_H 1

#include "Ifx_Types.h"
#include "Compilers.h"
#if defined (__CARC__)
#include <sfr/regppu.sfr>
#endif

IFX_INLINE void IfxPpu_Timer_initTimer0(void)
{
#if defined (__CCAC__)
	_sr(0xFFFFFFFF, 0x23);
	_sr(0x3, 0x22);
	_sr(0x0, 0x21);
#endif
#if defined (__CARC__)
	LIMIT0 = 0xFFFFFFFF;
	CONTROL0.IE = 0x1;
	CONTROL0.NH = 0x1;
	COUNT0 = 0x0;
#endif
}

IFX_INLINE void IfxPpu_Timer_resetTimer0(void)
{
#if defined (__CCAC__)
	_sr(0x0, 0x21);
#endif
#if defined (__CARC__)
	COUNT0 = 0x0;
#endif
}

IFX_INLINE uint32 IfxPpu_Timer_readTimer0(void)
{
#if defined (__CCAC__)
	return _lr(0x21);
#endif
#if defined (__CARC__)
	return (COUNT0);
#endif
}

IFX_INLINE void IfxPpu_Timer_setLimitToTimer0(uint32 limit)
{
#if defined (__CCAC__)
	_sr(limit, 0x23);
#endif
#if defined (__CARC__)
	LIMIT0 = limit;
#endif
}

IFX_INLINE void IfxPpu_Timer_initTimer1(void)
{
#if defined (__CCAC__)
	_sr(0xFFFFFFFF, 0x102);
	_sr(0x3, 0x101);
	_sr(0x0, 0x100);
#endif
#if defined (__CARC__)
	LIMIT1 = 0xFFFFFFFF;
	CONTROL1.IE = 0x1;
	CONTROL1.NH = 0x1;
	COUNT1 = 0x0;
#endif
}

IFX_INLINE void IfxPpu_Timer_resetTimer1(void)
{
#if defined (__CCAC__)
	_sr(0x0, 0x101);
#endif
#if defined (__CARC__)
	COUNT1 = 0x0;
#endif
}

IFX_INLINE uint32 IfxPpu_Timer_readTimer1(void)
{
#if defined (__CCAC__)
	return _lr(0x100);
#endif
#if defined (__CARC__)
	return (COUNT1);
#endif
}

IFX_INLINE void IfxPpu_Timer_setLimitToTimer1(uint32 limit)
{
#if defined (__CCAC__)
	_sr(limit, 0x102);
#endif
#if defined (__CARC__)
	LIMIT1 = limit;
#endif
}


/**** Examples for using the ARC timer ************** ;

#include "ARCtimer.h"

// Declare ARC Timer count value
   unsigned int timer_val=0;
// Initialse ARC Timer0
   _init_timer0 ;

// Reset ARC Timer0
   _reset_timer0 ;


// Read ARC Timer0 and print result
  printf("Number of timer ticks for function xxxxx was: \t%u \n", _read_timer0 );

***** End of examples for using the ARC timer ********/


#endif /* IFXPPU_TIMER_H_ */
