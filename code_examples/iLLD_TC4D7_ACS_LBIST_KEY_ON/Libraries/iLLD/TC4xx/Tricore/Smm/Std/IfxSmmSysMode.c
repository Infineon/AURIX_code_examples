/**
 * \file IfxSmmSysMode.c
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

#include "IfxSmmSysMode.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSmmSysMode_startSleepSequenceinFlash(void)
{
    uint16 wdgPwd;

    /*Set current CPU as the Master CPU*/
    IfxSmmSysMode_setMasterCpu(IfxCpu_getCoreIndex());

    /* EDIS bit to be cleared for peripherals intended to be inactive in sleep mode. Application hook to disable module not required to be active in sleep mode */
    IFXSMM_DISABLE_MODULES_DURING_SLEEP;

    /* Disabling CPU watchdog */
    wdgPwd = IfxWtu_getCpuWatchdogPassword();
    IfxWtu_disableCpuWatchdog(wdgPwd);

    /* Other CPU watchdog disabling should be taken care by the user. Place other CPU to idle state */
    IFXSMM_IDLE_CPU_DISABLE_WATCHDOG;

    /* Application hook to disable(or not) SYSPLL and PERPLL depending on which modules are required to be kept active*/
    /*Clock dividers for SPB, SRI, BBB, FSI, GETH, GTM, ADAS programmed to operate at lowest frequency*/
    IFXSMM_CLOCK_REDUCTION;

    IfxSmmSysMode_continueSleepSequenceInRAM();
}


void IfxSmmSysMode_continueSleepSequenceInRAM(void)
{
    IfxCpu_ResourceCpu masterCpu;
    /* Setting PF0 - PF5 and Host DFLASH to sleep mode*/
    /* Application hook for disabling HOST/CSRM flash for other CPU*/
    IFXSMM_DISABLE_FLASH;

    masterCpu = IfxSmmSysMode_getMasterCpu();

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif

    MODULE_SMM.PMCSR[masterCpu].B.REQSLP = IfxSmmSysMode_RqPwMd_sleep;

    /* Wait while system is in sleep mode requested*/
    while (MODULE_SMM.PMCSR[masterCpu].B.PMST == IfxSmmSysMode_Pmst_sleepModeRequest)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


void IfxSmmSysMode_setAllIdleExceptMasterCpu(const IfxCpu_ResourceCpu masterCpu)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_config);
#endif

    /* Enable global system mode entry if not enabled*/
    if (!SMM_PMSWCR1.B.PROCMODEEN)
    {
        SMM_PMSWCR1.B.PROCMODEEN = 1u;
    }

    switch (masterCpu)
    {
    case IfxCpu_ResourceCpu_0:
#if IFXCPU_NUM_SAFE_MODULES >= 2
        SMM_PMCSR1.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU1)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 3
        SMM_PMCSR2.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU2)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
        SMM_PMCSR3.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU3)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
        SMM_PMCSR4.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU4)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
        SMM_PMCSR5.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU5)
        {}

#endif
        break;
#if IFXCPU_NUM_SAFE_MODULES >= 2
    case IfxCpu_ResourceCpu_1:
        SMM_PMCSR0.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU0)
        {}

#if IFXCPU_NUM_SAFE_MODULES >= 3
        SMM_PMCSR2.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU2)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
        SMM_PMCSR3.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU3)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
        SMM_PMCSR4.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU4)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
        SMM_PMCSR5.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU5)
        {}

#endif
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 3
    case IfxCpu_ResourceCpu_2:
        SMM_PMCSR0.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU0)
        {}

        SMM_PMCSR1.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU1)
        {}

#if IFXCPU_NUM_SAFE_MODULES >= 4
        SMM_PMCSR3.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU3)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
        SMM_PMCSR4.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU4)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
        SMM_PMCSR5.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU5)
        {}

#endif
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 4
    case IfxCpu_ResourceCpu_3:
        SMM_PMCSR0.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU0)
        {}

        SMM_PMCSR1.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU1)
        {}

        SMM_PMCSR2.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU2)
        {}

#if IFXCPU_NUM_SAFE_MODULES >= 5
        SMM_PMCSR4.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU4)
        {}

#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
        SMM_PMCSR5.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU5)
        {}

#endif
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 5
    case IfxCpu_ResourceCpu_4:
        SMM_PMCSR0.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU0)
        {}

        SMM_PMCSR1.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU1)
        {}

        SMM_PMCSR2.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU2)
        {}

        SMM_PMCSR3.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU3)
        {}

#if IFXCPU_NUM_SAFE_MODULES >= 6
        SMM_PMCSR5.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU5)
        {}

#endif
        break;
#endif
#if IFXCPU_NUM_SAFE_MODULES >= 6
    case IfxCpu_ResourceCpu_5:
        SMM_PMCSR0.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU0)
        {}

        SMM_PMCSR1.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU1)
        {}

        SMM_PMCSR2.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU2)
        {}

        SMM_PMCSR3.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU3)
        {}

        SMM_PMCSR4.B.REQSLP = 0x1;

        while (SMM_PMSTAT0.B.CPU4)
        {}

        break;
#endif
    default:
        /* Invalid core selected */
        break;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMM.PROTE, IfxApProt_State_run);
#endif
}


IfxSmmSysMode_Pmst IfxSmmSysMode_getCoreStatus(IfxSmmSysMode_Resource cpuIndex)
{
    IfxSmmSysMode_Pmst cpuStatus = IfxSmmSysMode_Pmst_undefined;
#if (IFXCPU_NUM_SAFE_MODULES == 2)
    if (cpuIndex <= IfxSmmSysMode_Resource_Cpu_1)
#elif (IFXCPU_NUM_SAFE_MODULES == 3)
    if (cpuIndex <= IfxSmmSysMode_Resource_Cpu_2)
#elif (IFXCPU_NUM_SAFE_MODULES == 4)
    if (cpuIndex <= IfxSmmSysMode_Resource_Cpu_3)
#elif (IFXCPU_NUM_SAFE_MODULES == 5)
    if (cpuIndex <= IfxSmmSysMode_Resource_Cpu_4)
#else	/* IFXCPU_NUM_SAFE_MODULES > 5 */
    if (cpuIndex <= IfxSmmSysMode_Resource_Cpu_5)
#endif /* #if (IFXCPU_NUM_SAFE_MODULES == 2) */	
    {
        cpuStatus = (IfxSmmSysMode_Pmst)(MODULE_SMM.PMCSR[cpuIndex].U >> IFX_SMM_PMCSR_PMST_OFF);
    }
    else if (cpuIndex == IfxSmmSysMode_Resource_Cpu_cs)
    {
        cpuStatus = (IfxSmmSysMode_Pmst)(MODULE_SMM.PMCSRCS.U >> IFX_SMM_PMCSRCS_PMST_OFF);
    }
    else
    {}

    return cpuStatus;
}
