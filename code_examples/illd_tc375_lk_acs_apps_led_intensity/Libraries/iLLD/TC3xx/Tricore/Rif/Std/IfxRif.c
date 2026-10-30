/**
 * \file IfxRif.c
 * \brief RIF  basic functionality
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
#if defined(DEVICE_TC33XED) || defined(DEVICE_TC39XB) || defined(DEVICE_TC35X)
#include "IfxRif.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxRif_disableModule(Ifx_RIF *rif)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(password);
    /* Set the enable request */
    rif->CLC.B.DISR = 1U;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(password);
}


void IfxRif_enableFifos(Ifx_RIF *rif, uint8 count)
{
    IfxRif_disableAllFifos(rif);

    switch (count)
    {
    case 0:     /*All FIFOs disabled*/
        break;
    case 1:
        IfxRif_enableFifo(rif, IfxRif_FifoId_0);
        break;
    case 2:
        IfxRif_enableFifo(rif, IfxRif_FifoId_0);
        IfxRif_enableFifo(rif, IfxRif_FifoId_1);
        break;
    case 3:
    case 4:
        IfxRif_enableFifo(rif, IfxRif_FifoId_0);
        IfxRif_enableFifo(rif, IfxRif_FifoId_1);
        IfxRif_enableFifo(rif, IfxRif_FifoId_2);
        IfxRif_enableFifo(rif, IfxRif_FifoId_3);
        break;
    default:
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, FALSE); /* Wrong selection  */
        break;
    }
}


void IfxRif_enableModule(Ifx_RIF *rif)
{
    uint16 password = IfxScuWdt_getCpuWatchdogPassword();
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(password);
    /* Set the disable request */
    rif->CLC.B.DISR = 0U;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(password);

    /* Wait until module is enabled */
    while (IfxRif_isModuleEnabled(rif) == FALSE)
    {}
}


Ifx_RIF *IfxRif_getAddress(IfxRif_Index rif)
{
    Ifx_RIF *module;

    if (rif < IFXRIF_NUM_MODULES)
    {
        module = (Ifx_RIF *)IfxRif_cfg_indexMap[rif].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


IfxRif_Index IfxRif_getIndex(Ifx_RIF *rif)
{
    uint32       index;
    IfxRif_Index result;

    result = IfxRif_Index_none;

    for (index = 0; index < IFXRIF_NUM_MODULES; index++)
    {
        if (IfxRif_cfg_indexMap[index].module == rif)
        {
            result = (IfxRif_Index)IfxRif_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


volatile Ifx_SRC_SRCR *IfxRif_getSrcPointerErr(Ifx_RIF *rif)
{
    return &MODULE_SRC.RIF.RIF[IfxRif_getIndex(rif)].ERR;
}


volatile Ifx_SRC_SRCR *IfxRif_getSrcPointerInt(Ifx_RIF *rif)
{
    return &MODULE_SRC.RIF.RIF[IfxRif_getIndex(rif)].INT;
}


void IfxRif_disableFifo(Ifx_RIF *rif, IfxRif_FifoId fifoId)
{
    uint32 setValue = ~(1U << fifoId);
    rif->DMI.U = (rif->DMI.U & setValue);
}


void IfxRif_disableAllFifos(Ifx_RIF *rif)
{
    rif->DMI.U = 0U;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
