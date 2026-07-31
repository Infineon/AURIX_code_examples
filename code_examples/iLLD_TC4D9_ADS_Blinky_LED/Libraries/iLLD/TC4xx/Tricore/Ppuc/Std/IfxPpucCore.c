/**
 * \file IfxPpucCore.c
 * \brief PPUC basic functionality
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
#pragma warning 508 	    /* To suppress empty file warning */
#endif    
#if defined (__ghs__)    
#pragma diag_suppress 96	/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) ||defined(DEVICE_TC46X) || defined(DEVICE_TC45X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
#include "IfxPpucCore.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPpucCore_configureCoreAndRun(Ifx_PPU *ppuc, uint32 intVectAddress)
{
    ppuc->CLC.U = 0U;

    IfxPpucCore_configureInterruptVectorBaseAddress(ppuc, intVectAddress);

    /* Trigger a Kernel reset once you configure the ivt base address */
    ppuc->RST.CTRLA.U = 0x1;
    ppuc->RST.CTRLB.U = 0x1;

    /* Wait until the reset status is updated */
    while (ppuc->RST.STAT.B.KRST != 2U)
    {}

    /* Clear the RST STATUS */
    ppuc->RST.CTRLB.B.STATCLR = 1U;

    /* Write into CTRL register to bring PPUC out of halt
     * Enable the PPUC-ICU interface
     * Enable the CBU interface
     * Enable the LBU interface
     * Enable the STU interface
     * Enable the STU-DMI interface
     * Enable the CSM-DMI interface
     * Enable the VM-DMI interface
     * */
    ppuc->CTRL.U = 0x3f09U;
}


void IfxPpucCore_configureAccessToPpuc(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PPU.SFR.ACCEN, apConfig);
}


void IfxPpucCore_configureAccessToPpucCsm(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PPU_CSMAP.CSM.ACCEN, apConfig);
}


void IfxPpucCore_configureAccessToPpucVccm(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_PPU_VMEMAP.VMEM.ACCEN, apConfig);
}

#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC49XN) ||defined(DEVICE_TC46X) || defined(DEVICE_TC45X) || defined(DEVICE_TC4EX)*/

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
