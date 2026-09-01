/**
 * \file IfxScrRtc.c
 * \brief SCR RTC  basic functionality
 * 
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)

#include "IfxScrRtc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxScrRtc_initModule(IfxScrRtc_Config *rtcConfig)
{
	Ifx_SCR_RTCSCR_CON rtc_con;
    SCR_SYSCON0.U = SCR_SYSCON0.U & (uint8)(0xFE);
    /* Stop the RTC */
    SCR_RTCSCR_CON.U = (SCR_RTCSCR_CON.U & ~(1u << IFX_SCR_RTCSCR_CON_RTCC_OFF));

    /* Loading the 32-bit initial count value */
    /* Enable bit protection write access */
    SCR_PASSWD.U   = ((SCR_PASSWD.U & (unsigned char)0x07) | (0x13 << IFX_SCR_PASSWD_PASS_OFF));

    SCR_RTCSCR_CNT0.U = (uint8)rtcConfig->initialCountValue;
    SCR_RTCSCR_CNT1.U = (uint8)((rtcConfig->initialCountValue) >> 8);
    SCR_RTCSCR_CNT2.U = (uint8)((rtcConfig->initialCountValue) >> 16);
    SCR_RTCSCR_CNT3.U = (uint8)((rtcConfig->initialCountValue) >> 24);

    /* Disable bit protection write access */
    SCR_PASSWD.U = ((SCR_PASSWD.U & (unsigned char)0x07) | (0x15 << IFX_SCR_PASSWD_PASS_OFF));

    /* Configure RTC clock, prescalar and interrupt */
    rtc_con.U     = (SCR_RTCSCR_CON.U & ~((IFX_SCR_RTCSCR_CON_RTCCLKSEL_MSK << IFX_SCR_RTCSCR_CON_RTCCLKSEL_OFF) | (1u << IFX_SCR_RTCSCR_CON_RTPBYP_OFF) | (1u << IFX_SCR_RTCSCR_CON_ECRTC_OFF)));
    rtc_con.U    |= (rtcConfig->clockSource << IFX_SCR_RTCSCR_CON_RTCCLKSEL_OFF) | (1u << IFX_SCR_RTCSCR_CON_RTCCLKSEL_P_OFF) | \
    		        (rtcConfig->enableInterruptOnCompare << IFX_SCR_RTCSCR_CON_ECRTC_OFF) | \
    		        (rtcConfig->bypassPrescaler << IFX_SCR_RTCSCR_CON_RTPBYP_OFF);
    SCR_RTCSCR_CON.U = rtc_con.U;

    /* Load RTC Compare Value*/
    SCR_RTCSCR_CR0.U = (uint8)(rtcConfig->compareValue & (uint32)0xFFU);
    SCR_RTCSCR_CR1.U = (uint8)((rtcConfig->compareValue & ((uint32)0xFFU << 8)) >> 8);
    SCR_RTCSCR_CR2.U = (uint8)((rtcConfig->compareValue & ((uint32)0xFF << 16)) >> 16);
    SCR_RTCSCR_CR3.U = (uint8)((rtcConfig->compareValue & ((uint32)0xFF << 24)) >> 24);
}

#endif /* #if !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
