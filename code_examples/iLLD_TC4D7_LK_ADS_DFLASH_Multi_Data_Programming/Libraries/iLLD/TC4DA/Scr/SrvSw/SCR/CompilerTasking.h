/**
 * \file CompilerTasking.h
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
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

#ifndef COMPILERTASKING_H
#define COMPILERTASKING_H 1

/******************************************************************************/
//#define IFX_INLINE static	//Added for debug purpose

#ifndef IFX_INLINE
//#define IFX_INLINE _inline //for AgenTiX Tasking
#define IFX_INLINE    static inline
#endif

#ifndef IFX_REENTRANT
#define IFX_REENTRANT __reentrant
#endif

/******************************************************************************/
//for v6.2r1 it's the vectorAddress that has to be put instead of vectorNumber
#ifndef IFX_INTERRUPT
#define IFX_INTERRUPT(isr, vectorNumber) _interrupt(vectorNumber) void isr()
#endif

/******************************************************************************/

#endif /* COMPILERTASKING_H */
