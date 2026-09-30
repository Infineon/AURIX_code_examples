/**
 * \file IfxScrPort.c
 * \brief SCR PORT  basic functionality
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

#include "IfxScrPort.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxScrPort_configurePin(IfxScrPort_PinConfig *pinConfig)
{
    if (pinConfig->port == IfxScrPort_Index_00)
    {
        switch ((pinConfig->pin))
        {
        case IfxScrPort_PinIndex_0:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR0.U = (unsigned char)(SCR_P0_IOCR0.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR0.U  = ((SCR_P0_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_1:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR1.U = (unsigned char)(SCR_P0_IOCR1.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR0.U  = ((SCR_P0_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_2:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR2.U = (unsigned char)(SCR_P0_IOCR2.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR2.U  = ((SCR_P0_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_3:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR3.U = (unsigned char)(SCR_P0_IOCR3.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR2.U  = ((SCR_P0_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_4:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR4.U = (unsigned char)(SCR_P0_IOCR4.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR4.U  = ((SCR_P0_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_5:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR5.U = (unsigned char)(SCR_P0_IOCR5.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR4.U  = ((SCR_P0_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_6:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR6.U = (unsigned char)(SCR_P0_IOCR6.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR6.U  = ((SCR_P0_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_7:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P0_IOCR7.U = (unsigned char)(SCR_P0_IOCR7.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P0_PDR6.U  = ((SCR_P0_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
        default:
            break;
        }
    }

    else if (pinConfig->port == IfxScrPort_Index_01)
    {
        switch ((pinConfig->pin))
        {
        case IfxScrPort_PinIndex_0:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR0.U = (unsigned char)(SCR_P1_IOCR0.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR0.U  = ((SCR_P1_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_1:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR1.U = (unsigned char)(SCR_P1_IOCR1.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR0.U  = ((SCR_P1_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_2:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR2.U = (unsigned char)(SCR_P1_IOCR2.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR2.U  = ((SCR_P1_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_3:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR3.U = (unsigned char)(SCR_P1_IOCR3.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR2.U  = ((SCR_P1_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_4:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR4.U = (unsigned char)(SCR_P1_IOCR4.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR4.U  = ((SCR_P1_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_5:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR5.U = (unsigned char)(SCR_P1_IOCR5.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR4.U  = ((SCR_P1_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_6:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR6.U = (unsigned char)(SCR_P1_IOCR6.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR6.U  = ((SCR_P1_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_7:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P1_IOCR7.U = (unsigned char)(SCR_P1_IOCR7.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P1_PDR6.U  = ((SCR_P1_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
        default:
            break;
        }
    }
    else if (pinConfig->port == IfxScrPort_Index_02)
    {
        switch ((pinConfig->pin))
        {
        case IfxScrPort_PinIndex_0:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR0.U = (unsigned char)(SCR_P2_IOCR0.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR0.U  = ((SCR_P2_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_1:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR1.U = (unsigned char)(SCR_P2_IOCR1.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR0.U  = ((SCR_P2_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_2:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR2.U = (unsigned char)(SCR_P2_IOCR2.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR2.U  = ((SCR_P2_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_3:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR3.U = (unsigned char)(SCR_P2_IOCR3.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR2.U  = ((SCR_P2_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_4:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR4.U = (unsigned char)(SCR_P2_IOCR4.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR4.U  = ((SCR_P2_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

#if !defined(DEVICE_TC49XN)			
        case IfxScrPort_PinIndex_5:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR5.U = (unsigned char)(SCR_P2_IOCR5.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR4.U  = ((SCR_P2_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
			
        case IfxScrPort_PinIndex_6:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR6.U = (unsigned char)(SCR_P2_IOCR6.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR6.U  = ((SCR_P2_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
			
        case IfxScrPort_PinIndex_7:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P2_IOCR7.U = (unsigned char)(SCR_P2_IOCR7.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P2_PDR6.U  = ((SCR_P2_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
#endif /* #if !defined(DEVICE_TC49XN) */			
        default:
            break;
        }
    }
    else
    {
        switch ((pinConfig->pin))
        {
        case IfxScrPort_PinIndex_0:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR0.U = (unsigned char)(SCR_P3_IOCR0.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR0.U  = ((SCR_P3_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_1:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR1.U = (unsigned char)(SCR_P3_IOCR1.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR0.U  = ((SCR_P3_PDR0.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_2:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR2.U = (unsigned char)(SCR_P3_IOCR2.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR2.U  = ((SCR_P3_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_3:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR3.U = (unsigned char)(SCR_P3_IOCR3.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR2.U  = ((SCR_P3_PDR2.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

        case IfxScrPort_PinIndex_4:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR4.U = (unsigned char)(SCR_P3_IOCR4.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR4.U  = ((SCR_P3_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;

#if !defined(DEVICE_TC49XN)				
        case IfxScrPort_PinIndex_5:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR5.U = (unsigned char)(SCR_P3_IOCR5.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR4.U  = ((SCR_P3_PDR4.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
			
        case IfxScrPort_PinIndex_6:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR6.U = (unsigned char)(SCR_P3_IOCR6.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR6.U  = ((SCR_P3_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
			
        case IfxScrPort_PinIndex_7:
            IfxScrPort_setIoPage(IfxScrPort_Page_1);
            SCR_P3_IOCR7.U = (unsigned char)(SCR_P3_IOCR7.U & ~(IFX_SCR_P_IOCR_PC_MSK << IFX_SCR_P_IOCR_PC_OFF)) | (pinConfig->pinMode << IFX_SCR_P_IOCR_PC_OFF);
            IfxScrPort_setIoPage(IfxScrPort_Page_2);
            SCR_P3_PDR6.U  = ((SCR_P3_PDR6.U & ~(0xF << (((pinConfig->pin) & 1) << 2))) | (unsigned char)((pinConfig->driverMode) << (((pinConfig->pin) & 1) << 2)));
            break;
#endif /* #if !defined(DEVICE_TC49XN) */			
        default:
            break;
        }
    }
}

#endif /* #if !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif

