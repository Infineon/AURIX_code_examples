/**
 * \file IfxSmm.c
 * \brief SMM  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSmm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSmm_initVoltageDroopLegacyConfig(IfxSmm_VoltageDroopLegacyConfig *voltageDroopConfig)
{
    /*Enabling usage of Voltage Droop Timer*/
    voltageDroopConfig->enableVoltageDroopTimer                  = TRUE;
    /*Enabling update of Voltage Droop Timer Overflow Flag in event of overflow*/
    voltageDroopConfig->enableVoltageDroopTimerOverflowFlag      = TRUE;
    /*Disabling Voltage Droop Timer interrupt*/
    voltageDroopConfig->enableVoltageDroopTimerOverflowInterrupt = FALSE;
    /* Droop timer Compare value */
    voltageDroopConfig->droopTimerCompareValue                   = 0x100;
    /* Requesting for a reduction voltage(negative voltage droop)*/
    voltageDroopConfig->droopRequestType                         = IfxSmm_VoltageDroopRequest_negative;
}


boolean IfxSmm_initAndRequestLegacyVoltageDroop(IfxSmm_VoltageDroopLegacyConfig *voltageDroopConfig)
{
    Ifx_SMM_PMTRCSR0 pmtCsr0;
    boolean          request = 1;

    if (!SMM_PMTRCSR3.B.VDTRUN)
    {
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif

        pmtCsr0.U                = SMM_PMTRCSR0.U;
        pmtCsr0.B.VDTEN          = voltageDroopConfig->enableVoltageDroopTimer;
        pmtCsr0.B.VDTOVEN        = voltageDroopConfig->enableVoltageDroopTimerOverflowFlag;
        pmtCsr0.B.VDTOVIEN       = voltageDroopConfig->enableVoltageDroopTimerOverflowInterrupt;
        pmtCsr0.B.DROOPENAB      = 0u;
        SMM_PMTRCSR0.U           = pmtCsr0.U;
        SMM_PMTRCSR1.B.VDTCV     = voltageDroopConfig->droopTimerCompareValue;
        __dsync();
        SMM_PMTRCSR3.B.VDROOPREQ = voltageDroopConfig->droopRequestType;

#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
        request = 0;
    }

    return request;
}


void IfxSmm_initLoadJumpConfig(IfxSmm_LoadJumpConfig *loadJumpConfig)
{
    loadJumpConfig->enableLoadJumpTimer                  = TRUE;
    loadJumpConfig->enableLoadJumpTimerOverflowFlag      = TRUE;
    loadJumpConfig->enableLoadJumpTimerOverflowInterrupt = FALSE;
    loadJumpConfig->loadjumpTimerCompareValue            = 0x100;
}


boolean IfxSmm_initAndRequestLoadJump(IfxSmm_LoadJumpConfig *loadJumpConfig)
{
    Ifx_SMM_PMTRCSR0 pmtCsr0;
    boolean          request = 1;

    if (!SMM_PMTRCSR2.B.LJTRUN)
    {
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif

        pmtCsr0.U               = SMM_PMTRCSR0.U;
        pmtCsr0.B.LJTEN         = loadJumpConfig->enableLoadJumpTimer;
        pmtCsr0.B.LJTOVEN       = loadJumpConfig->enableLoadJumpTimerOverflowFlag;
        pmtCsr0.B.LJTOVIEN      = loadJumpConfig->enableLoadJumpTimerOverflowInterrupt;
        SMM_PMTRCSR0.U          = pmtCsr0.U;
        SMM_PMTRCSR1.B.LJTCV    = loadJumpConfig->loadjumpTimerCompareValue;
        __dsync();
        SMM_PMTRCSR2.B.LDJMPREQ = 1U;

#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
        request = 0;
    }

    return request;
}


void IfxSmm_initVoltageDroopConfig(IfxSmm_VoltageDroopConfig *voltageDroopConfig)
{
    voltageDroopConfig->droopReq = 1;
    voltageDroopConfig->dir      = FALSE;
    voltageDroopConfig->steps    = IfxSmm_VoltageDroopStep_25mV;
    voltageDroopConfig->dwellCnt = 0x5;
}


boolean IfxSmm_initAndRequestVoltageDroop(IfxSmm_VoltageDroopConfig *voltageDroopConfig)
{
    boolean          request = 1;
    Ifx_SMM_DRPCTRL  drpCtrl;
    Ifx_SMM_PMTRCSR0 pmtCsr0;

    /* Busy bit check */
    if (!SMM_DRPCTRL.B.BUSY)
    {
        /* Check error bit status.IF error bit set clear earlier errors*/
        if (SMM_DRPCTRL.B.ERR)
        {
            SMM_DRPCTRL.B.ERRCLR = 1;
        }

        /*Reading register*/
        drpCtrl.U           = SMM_DRPCTRL.U;
        pmtCsr0.U           = SMM_PMTRCSR0.U;

        drpCtrl.B.REQ       = voltageDroopConfig->droopReq;
        drpCtrl.B.DWELL_CNT = voltageDroopConfig->dwellCnt;
        drpCtrl.B.DIR       = voltageDroopConfig->dir;
        drpCtrl.B.STEPS     = voltageDroopConfig->steps;

        pmtCsr0.B.DROOPENAB = 1u;
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif
        SMM_PMTRCSR0.U = pmtCsr0.U;
        SMM_DRPCTRL.U  = drpCtrl.U;
#if (IFX_PROT_ENABLED == 1U)
        IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
        request = 0;
    }

    return request;
}


void IfxSmm_configureAccessToSmm(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_SMM.ACCEN, apConfig);
}
