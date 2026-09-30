/**
 * \file IfxPcieEp.c
 * \brief PCIE  basic functionality
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

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC45X)
#include "IfxPcieEp.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPcieEp_initApConfig(IfxPcieEp_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxPcieEp_initAp(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&pcieEpSFR->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&pcieEpSFR->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&pcieEpSFR->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&pcieEpSFR->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&pcieEpSFR->PROTSE, IfxApProt_State_run);
}


IfxPcie_Status IfxPcieEp_setBarMask(Ifx_PCIE_USP *pcieSFR, IfxPcie_BarNum barIndex, uint64 barSize, IfxPcie_AddressWidth addressWidth, boolean enabled)
{
    IfxPcie_Status                                 status          = IfxPcie_Status_success;
    volatile Ifx_PCIE_USP_TYPE0HDRDBI_BARMASK_REG *barMaskPtr      = &(pcieSFR->TYPE0HDRDBI.BARMASK_REG[barIndex]);
    volatile Ifx_PCIE_USP_TYPE0HDRDBI_BARMASK_REG *barMaskUpperPtr = NULL_PTR;
    uint64                                         barMaskVal      = 0x0u;
    boolean                                        doubleWord      = (addressWidth == IfxPcie_AddressWidth_64) ? TRUE : FALSE;

    if (enabled == FALSE)
    {
        barMaskPtr->U = 0x0u;                                           /* Disable BAR */
    }
    else
    {
        if (doubleWord == TRUE)
        {
            if (barIndex < IfxPcie_BarNum_5)
            {
                barMaskUpperPtr = &(pcieSFR->TYPE0HDRDBI.BARMASK_REG[barIndex + 1]);
            }
            else
            {
                status = IfxPcie_Status_failure;
            }
        }

        if (status == IfxPcie_Status_success)
        {
            if (IFXPCIE_GET_NEXT_4KB_BOUNDARY(barSize) == barSize)      /* Bar Size is aligned */
            {
                barMaskVal    = barSize - 1u;                           /* Mask value is 1 less than aligned size */
                barMaskPtr->U = (uint32)barMaskVal;                     /* Write MASK value */

                if (doubleWord == TRUE)
                {
                    barMaskUpperPtr->U = (uint32)(barMaskVal >> 32U);   /* Write upper BAR MASK value */
                }
            }
            else
            {
                status = IfxPcie_Status_failure;                        /* Illegal Bar Size */
            }
        }
    }

    return status;
}


void IfxPcieEp_setBarParameters(Ifx_PCIE_USP *pcieSFR, IfxPcie_BarNum barIndex, IfxPcie_AddressWidth addressWidth, boolean prefetch)
{
    volatile Ifx_PCIE_USP_TYPE0HDR_BAR *barRegPtr = &(pcieSFR->TYPE0HDR.BAR[barIndex]);
    Ifx_PCIE_USP_TYPE0HDR_BAR           barReg;
    barReg.U               = barRegPtr->U; /* Read Word */

    barReg.B.BAR0_MEM_IO   = 0x0u;         /* always Memory */
    barReg.B.BAR0_PREFETCH = (prefetch == TRUE) ? 1u : 0u;
    barReg.B.BAR0_TYPE     = (uint32)addressWidth;

    barRegPtr->U           = barReg.U; /* Write Back */
}


void IfxPcieEp_resetLinkTraining(Ifx_PCIE_USP *pcieEpSFR)
{
    pcieEpSFR->LNK.CORECTRL.B.LTSSMEN = 0;
}


boolean IfxPcieEp_isLinkUp(Ifx_PCIE_USP *pcieEpSFR)
{
    return pcieEpSFR->LNK.STAT.U & (IFX_PCIE_USP_LNK_STAT_LINKUP_MSK << IFX_PCIE_USP_LNK_STAT_LINKUP_OFF);
}


boolean IfxPcieEp_isLinkStateL0(Ifx_PCIE_USP *pcieEpSFR)
{
    return (pcieEpSFR->PORTLOGIC.PL_DEBUG0_OFF.U & 0x1F) == 0x11;
}


void IfxPcieEp_enterLocalLoopback(Ifx_PCIE_USP *pcieEpSFR)
{
    IfxPcie_setDbiRoAccess((IfxPcie *)pcieEpSFR, TRUE);
    /* ASPM must be disabled before moving to loopback mode */
    pcieEpSFR->PCIECAP.LINK_CAPABILITIES_REG.B.PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT = 0;
    /* Disable Equalisation */
    pcieEpSFR->PORTLOGIC.GEN3_RELATED_OFF.B.GEN3_EQUALIZATION_DISABLE                = 1;
    /* Set Pipe Loopback bit */
    pcieEpSFR->PORTLOGIC.PIPE_LOOPBACK_CONTROL_OFF.B.PIPE_LOOPBACK                   = 1;
    pcieEpSFR->PORTLOGIC.PORT_LINK_CTRL_OFF.B.LOOPBACK_ENABLE                        = 1;
    IfxPcie_setDbiRoAccess((IfxPcie *)pcieEpSFR, FALSE);
}


void IfxPcieEp_setSrisOperatingMode(Ifx_PCIE_USP *pcieEpSFR)
{
    IfxPcie_setDbiRoAccess((IfxPcie *)pcieEpSFR, TRUE);

    /* L0s should not be supported if SRIS is enabled and hence check if L0s is supported if yes disable it*/
    if ((pcieEpSFR->PCIECAP.LINK_CAPABILITIES_REG.B.PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT & 0x1) == 0x1)
    {
        pcieEpSFR->PCIECAP.LINK_CAPABILITIES_REG.B.PCIE_CAP_ACTIVE_STATE_LINK_PM_SUPPORT = 0x2;
    }

    pcieEpSFR->LNK.CORECTRL.B.SRISMD = 1;
    IfxPcie_setDbiRoAccess((IfxPcie *)pcieEpSFR, FALSE);
}


void IfxPcieEp_exitLocalLoopback(Ifx_PCIE_USP *pcieEpSFR)
{
    /* reset Pipe Loopback bit */
    pcieEpSFR->PORTLOGIC.PIPE_LOOPBACK_CONTROL_OFF.B.PIPE_LOOPBACK = 0;
    pcieEpSFR->PORTLOGIC.PORT_LINK_CTRL_OFF.B.LOOPBACK_ENABLE      = 0;
}


void IfxPcieEp_setAckNackScheduler(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_ackNackConfig ackNackConfig)
{
    /* Set the ACK frequency of L0-L1 ASPM behaviour */
    /* Number of pending ACKs */
    pcieEpSFR->PORTLOGIC.ACK_F_ASPM_CTRL_OFF.B.ACK_FREQ                        = ackNackConfig.ackFreq;
    pcieEpSFR->PORTLOGIC.ACK_LATENCY_TIMER_OFF.B.ROUND_TRIP_LATENCY_TIME_LIMIT = ackNackConfig.ackLatencyTimerLimit;
    pcieEpSFR->PORTLOGIC.TIMER_CTRL_MAX_FUNC_NUM_OFF.B.TIMER_MOD_ACK_NAK       = ackNackConfig.ackLatencyTimerModifier;
}


void IfxPcieEp_setReplayTimerLimit(Ifx_PCIE_USP *pcieEpSFR, IfxPcieEp_replayTimerConfig replayTimerConfig)
{
    pcieEpSFR->PORTLOGIC.ACK_LATENCY_TIMER_OFF.B.REPLAY_TIME_LIMIT            = replayTimerConfig.replayTimerLimit;
    pcieEpSFR->PORTLOGIC.TIMER_CTRL_MAX_FUNC_NUM_OFF.B.TIMER_MOD_REPLAY_TIMER = replayTimerConfig.replayTimerModifier;
}


void IfxPcieEp_setIntrTriggerMsk(Ifx_PCIE_USP *pcieEpSFR, uint32 value)
{
    pcieEpSFR->INT.TRIGEN.U = value;
}


uint32 IfxPcieEp_getIntrTriggerStatus(Ifx_PCIE_USP *pcieEpSFR)
{
    return pcieEpSFR->INT.TRIGSTAT.U;
}


void IfxPcieEp_clearIntrTriggerStatus(Ifx_PCIE_USP *pcieEpSFR, uint32 value)
{
    pcieEpSFR->INT.TRIGCLR.U = value;
}

#endif /* defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
