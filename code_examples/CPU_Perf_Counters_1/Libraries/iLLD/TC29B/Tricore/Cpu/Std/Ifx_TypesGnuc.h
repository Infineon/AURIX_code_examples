/**
 * \file Ifx_TypesGnuc.h
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
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
#ifndef IFX_TYPESGNUC_H_
#define IFX_TYPESGNUC_H_
/******************************************************************************/
#define FRACT_MAX 0x7fffffff

#include <machine/cint.h>
#define __interrupt(intno)

typedef long          fract;
typedef short         sfract;
typedef long long     laccum;
typedef long          __packb;   //MSMRK should be struct of four chars
typedef unsigned long __upackb;  //MSMRK should be struct of four unsigned chars
typedef long          __packhw;  //MSMRK should be struct of two shorts
typedef unsigned long __upackhw; //MSMRK should be struct of two unsigned shorts
/******************************************************************************/

#endif /* IFX_TYPESGNUC_H_ */
