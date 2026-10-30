/**
 * \file IfxScuWdt.asm.h
 * \brief SCU  basic functionality
 * \ingroup IfxLld_Scu
 *
 * \version iLLD_1_22_0
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
 * \defgroup IfxLld_Scu_Std_Wdt_Operative Wdt Operative Functionality
 * \ingroup IfxLld_Scu_Std_Wdt
 */
#ifndef IFXSCUWDT_ASM_H
#define IFXSCUWDT_ASM_H 1

#include "Cpu/Std/Ifx_Types.h"
#include "IfxScu_reg.h"

/** \addtogroup IfxLld_Scu_Std_Wdt_Operative
 * \{ */
#define IFXSCUWDT_CALCULATELFSR(pwd) ((((((pwd) >> 13) ^ ((pwd) >> 12) ^ ((pwd) >> 11) ^ ((pwd) >> 1 )) & 1)) | (((pwd)<<1) & 0x3FFF))
/**
 * \brief SCUWDT Inline API utility to calculate a new 14-bit LFSR.
 *
 * This function calculates a new 14-bit LFSR (Linear Feedback Shift Register) value using the characteristic polynomial \(x^{14} + x^{13} + x^{12} + x^2 + 1\).
 *
 * \param[in] password The input password for which the LFSR value is to be calculated.
 * 				       Range: 0x0000 to 0xFFFF
 *
 * \retval uint16 The newly calculated 14-bit LFSR value. Range: 0 to 16383.
 */
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 password);
/** \}  */

/**
 * \brief SCUWDT Inline API utility to Calculte new 14-bit LFSR.
 */
#if defined(__TASKING__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           mov d4,#0 \n\
           mov d5,#14 \n\
           extr.u %0,%1,e4     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#elif defined(__HIGHTEC__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           extr.u %0,%1,0,14     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           extr.u %0,%1,0,14     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#elif defined(__DCC__)
/* *INDENT-OFF* */
asm uint16 IfxScuWdt_calculateLfsr_asm(uint16 password)
{
%reg password
!"%d2"
    xor.t %d2, password, 13, password, 12
    xor.t %d2, %d2, 0, password, 11
	sh.xor.t password,%d2,0,password,1
	extr.u %d2,password,0,14
}
/* *INDENT-ON* */
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    return IfxScuWdt_calculateLfsr_asm(pwd);
}
#elif defined(__ghs__)
IFX_INLINE uint16 IfxScuWdt_calculateLfsr(uint16 pwd)
{
    /* *INDENT-OFF* */
    uint32 temp = pwd;
    uint16 res;

    __asm("xor.t  %0,%1,13,%1,12 \n\
           xor.t  %0,%0,0,%1,11  \n\
           sh.xor.t %1,%0,0,%1,1  \n\
           extr.u %0,%1,0,14     \n" : "=&d" (res) : "d" (temp));
    return res;
    /* *INDENT-ON* */
}
#endif
#endif /* #ifndef IFXSCUWDT_ASM_H */
