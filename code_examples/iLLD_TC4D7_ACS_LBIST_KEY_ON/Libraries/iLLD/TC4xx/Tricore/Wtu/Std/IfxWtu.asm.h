/**
 * \file IfxWtu.asm.h
 * \brief WTU  basic functionality
 * \ingroup IfxLld_Wtu
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 * \defgroup IfxLld_Wtu_Std_Wtu_Operative Wdt Operative Functionality
 * \ingroup IfxLld_Wtu_Std
 */
#ifndef IFXWTU_ASM_H
#define IFXWTU_ASM_H 1

#include "Ifx_Types.h"
#include "IfxWtu_reg.h"

/** \addtogroup IfxLld_Scu_Std_Wdt_Operative
 * \{ */
#define IFXWTU_CALCULATELFSR(pwd) ((((((pwd) >> 14) ^ ((pwd) >> 13) ^ ((pwd) >> 12) ^ ((pwd) >> 2) ^ 1) & 1)) | (((pwd) << 1) & 0x7FFF))
/**
 * \brief WTU Inline API utility to Calculte new 14-bit LFSR.
 *
 * This API will Calculte new 15-bit LFSR (Linear Feedback Shift Register) with characteristic polynomial
 * x15+x14+x13+x3+1.
 *
 * \param password Password for which LFSR value to be calculated.
 * \return New LFSR.
 */
IFX_INLINE uint16 IfxWtu_calculateLfsr(uint16 password);
/** \}  */

/**
 * \brief WTU Inline API utility to Calculte new 15-bit LFSR.
 */
#if defined(__TASKING__)
IFX_INLINE uint16 IfxWtu_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,14,%1,13 \n\
           xor.t  %0,%0,0,%1,12  \n\
           xor.t    %0,%0,0,%1,2   \n\
           xor      %0,%0,#1        \n\
           sh.or.t  %1,%0,0,%0,0   \n\
           mov d4,#0 \n\
           mov d5,#15 \n\
           extr.u %0,%1,e4     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}


#elif defined(__GNUC__)
IFX_INLINE uint16 IfxWtu_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t    %0,%1,14,%1,13 \n\
           xor.t    %0,%0,0,%1,12  \n\
           xor.t    %0,%0,0,%1,2   \n\
           xor      %0,%0,1        \n\
           sh.or.t  %1,%0,0,%0,0   \n\
           extr.u %0,%1,0,15     \n" : "=&d" (res), "+d" (temp) : );
    return res;
    /* *INDENT-ON* */
}


#elif defined(__DCC__)
/* *INDENT-OFF* */
asm uint16 IfxWtu_calculateLfsr_asm(uint16 password)
{
%reg password
!"%d2"
    xor.t   %d2, password, 14, password, 13
    xor.t   %d2, %d2, 0, password, 12
	xor.t   %d2,%d2,0,password,2
	xor     %d2,%d2,1
	sh.or.t password,%d2,0,%d2,0
	extr.u %d2,password,0,15
}
/* *INDENT-ON* */
IFX_INLINE uint16 IfxWtu_calculateLfsr(uint16 pwd)
{
    return IfxWtu_calculateLfsr_asm(pwd);
}


#elif defined(__ghs__)
IFX_INLINE uint16 IfxWtu_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t    %0,%1,14,%1,13 \n\
           xor.t    %0,%0,0,%1,12  \n\
           xor.t    %0,%0,0,%1,2   \n\
           xor      %0,%0,1        \n\
           sh.or.t  %1,%0,0,%0,0   \n\
           extr.u %0,%1,0,15     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}


#endif
#endif
