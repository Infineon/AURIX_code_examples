/**
 * \file IfxEmem.c
 * \brief EMEM  basic functionality
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
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC35X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC39XB)
#include "IfxEmem.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxEmem_LockedState IfxEmem_getLockedState(void)
{
    return (IfxEmem_LockedState)MODULE_EMEM.SBRCTR.B.STBLOCK;
}


void IfxEmem_setClockEnableState(const IfxEmem_State state)
{
    /* Bit is inverted */
    if (IfxEmem_State_enabled == state)
    {
        MODULE_EMEM.CLC.B.DISR = 0;
    }
    else
    {
        MODULE_EMEM.CLC.B.DISR = 1;
    }

    /* Wait one cycle for module to be enabled */
    __nop();
}


void IfxEmem_setUnlockMode(Ifx_EMEM *ememCore)
{
    ememCore->SBRCTR.U = 0x2;
    ememCore->SBRCTR.U = 0x6;
    ememCore->SBRCTR.U = 0xE;
}


void IfxEmem_enableModule(Ifx_EMEM *ememCore)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enables the module */
    ememCore->CLC.B.DISR = 0;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxEmem_disableModule(Ifx_EMEM *ememCore)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disables the module */
    ememCore->CLC.B.DISR = 1;
    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxEmem_disableEccErrorReporting(IfxEmem_MpuIndex mpuIndex)
{
    uint16        psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);

    Ifx_EMEM_MPU *ememMpu = IfxEmem_getAddress(mpuIndex);

    ememMpu->MEMCON.U = ((ememMpu->MEMCON.U & ~(3 << 8)) | ((1 << 8) | (1 << 9)));

    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


void IfxEmem_enableEccErrorReporting(IfxEmem_MpuIndex mpuIndex)
{
    uint16        psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection */
    IfxScuWdt_clearCpuEndinit(psw);

    Ifx_EMEM_MPU *ememMpu = IfxEmem_getAddress(mpuIndex);

    ememMpu->MEMCON.U = ((ememMpu->MEMCON.U & ~(3 << 8)) | (1 << 8));

    /* Sets the endinit protection back on */
    IfxScuWdt_setCpuEndinit(psw);
}


IfxEmem_MpuIndex IfxEmem_getIndex(Ifx_EMEM_MPU *ememMpu)
{
    uint32           index = 0;
    IfxEmem_MpuIndex result;

    result = IfxEmem_MpuIndex_none;

    for (index = 0; index < IFXEMEM_NUM_MPU_MODULES; index++)
    {
        if (IfxEmem_cfg_indexMap[index].module == ememMpu)
        {
            result = (IfxEmem_MpuIndex)IfxEmem_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


Ifx_EMEM_MPU *IfxEmem_getAddress(IfxEmem_MpuIndex ememMpu)
{
    Ifx_EMEM_MPU *module = NULL_PTR;

    if (ememMpu < IFXEMEM_NUM_MPU_MODULES)
    {
        module = (Ifx_EMEM_MPU *)IfxEmem_cfg_indexMap[ememMpu].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}

#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
