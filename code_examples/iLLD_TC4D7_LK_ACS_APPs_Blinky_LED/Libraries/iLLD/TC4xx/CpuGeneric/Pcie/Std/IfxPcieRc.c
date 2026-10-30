/**
 * \file IfxPcieRc.c
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
#include "IfxPcieRc.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint32 IfxPcieRc_ComposeExternalConfigAddress(uint8 Bus, uint8 Device, uint8 Function, uint16 Offset)
{
    uint32 Location = 0;

    Location |= ((((uint32)Bus) << IFXPCIERC_ECAM_BUS_SHIFT) & IFXPCIERC_ECAM_BUS_MASK);

    Location |= ((((uint32)Device) << IFXPCIERC_ECAM_DEV_SHIFT) & IFXPCIERC_ECAM_DEV_MASK);

    Location |= ((((uint32)Function) << IFXPCIERC_ECAM_FUN_SHIFT) & IFXPCIERC_ECAM_FUN_MASK);

    Location |= ((((uint32)Offset) << IFXPCIERC_ECAM_REG_SHIFT) & IFXPCIERC_ECAM_REG_MASK);

    Location &= IFXPCIERC_ECAM_MASK;

    return Location;
}


void IfxPcieRc_setNumOfLanes(Ifx_PCIE_DSP *PcieDspReg, IfxPcieRc_LaneWidth laneWidth)
{
    uint32 lnkCtrlReg = 0;
    /*Read DBI port link register */
    lnkCtrlReg                                 = PcieDspReg->PORTLOGIC.PORT_LINK_CTRL_OFF.U;

    lnkCtrlReg                                &= ~(IFX_PCIE_DSP_PORTLOGIC_PORT_LINK_CTRL_OFF_LINK_CAPABLE_MSK << IFX_PCIE_DSP_PORTLOGIC_PORT_LINK_CTRL_OFF_LINK_CAPABLE_OFF);

    lnkCtrlReg                                |= (laneWidth << IFX_PCIE_DSP_PORTLOGIC_PORT_LINK_CTRL_OFF_LINK_CAPABLE_OFF);

    PcieDspReg->PORTLOGIC.PORT_LINK_CTRL_OFF.U = lnkCtrlReg;

    uint32 lnkWidthReg = 0;

    /*Read DBI port link register */
    lnkWidthReg                           = PcieDspReg->PORTLOGIC.GEN2_CTRL_OFF.U;

    lnkWidthReg                          &= ~(IFX_PCIE_DSP_PORTLOGIC_GEN2_CTRL_OFF_NUM_OF_LANES_MSK << IFX_PCIE_DSP_PORTLOGIC_GEN2_CTRL_OFF_NUM_OF_LANES_OFF);

    lnkWidthReg                          |= (laneWidth << IFX_PCIE_DSP_PORTLOGIC_GEN2_CTRL_OFF_NUM_OF_LANES_OFF);

    PcieDspReg->PORTLOGIC.GEN2_CTRL_OFF.U = lnkWidthReg;
}

#endif /* defined(DEVICE_TC4DX) || defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
