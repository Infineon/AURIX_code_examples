/**
 * \file IfxStm.c
 * \brief STM  basic functionality
 *
 * \version iLLD_1_22_0
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

#include "IfxStm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxStm_clearCompareFlag(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
    	/* Clear the Reset Compare Register CMP0 Interrupt Flag */
        stm->ISCR.B.CMP0IRR = 1U;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
    	/* Clear the Reset Compare Register CMP1 Interrupt Flag */
        stm->ISCR.B.CMP1IRR = 1U;
    }
}


void IfxStm_disableComparatorInterrupt(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
    	/* Disable the Compare Register CMP0 Interrupt Enable Control */
        stm->ICR.B.CMP0EN = 0U;
    }
    else // if (comparator == IfxStm_Comparator_1)
    {
    	/* Disable the Compare Register CMP1 Interrupt Enable Control */
        stm->ICR.B.CMP1EN = 0U;
    }
}


void IfxStm_disableModule(Ifx_STM *stm)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Disable the STM module by setting the disable request bit */
    stm->CLC.B.DISR = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxStm_enableComparatorInterrupt(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
    	/* Enable the Compare Register CMP0 Interrupt Enable Control */
        stm->ICR.B.CMP0EN = 1U;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
    	/* Enable the Compare Register CMP1 Interrupt Enable Control */
        stm->ICR.B.CMP1EN = 1U;
    }
}


void IfxStm_enableOcdsSuspend(Ifx_STM *stm)
{
    Ifx_STM_OCS ocs = stm->OCS;

    /* Only if OCDS is enabled write into the OCS register */
    if (MODULE_CBS.OSTATE.B.OEN == 1U)
    {
        ocs.B.SUS_P      = 1;
        ocs.B.SUS        = 2;
        stm->OCS         = ocs;
        stm->OCS.B.SUS_P = 0;
    }
}


Ifx_STM *IfxStm_getAddress(IfxStm_Index stm)
{
    Ifx_STM *module;

    if (stm < IFXSTM_NUM_MODULES)
    {
        module = (Ifx_STM *)IfxStm_cfg_indexMap[stm].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


IfxStm_Index IfxStm_getIndex(Ifx_STM *stm)
{
    uint32       index;
    IfxStm_Index result;

    result = IfxStm_Index_none;

    for (index = 0; index < IFXSTM_NUM_MODULES; index++)
    {
        if (IfxStm_cfg_indexMap[index].module == stm)
        {
            result = (IfxStm_Index)IfxStm_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


volatile Ifx_SRC_SRCR *IfxStm_getSrcPointer(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    IfxStm_Index index;
    index = IfxStm_getIndex(stm);
    return comparator == IfxStm_Comparator_0 ? &MODULE_SRC.STM.STM[index].SR[0] : &MODULE_SRC.STM.STM[index].SR[1];
}


boolean IfxStm_initCompare(Ifx_STM *stm, const IfxStm_CompareConfig *config)
{
    sint32        index;
    boolean       result;
    Ifx_STM_CMCON comcon = stm->CMCON;
    Ifx_STM_ICR   icr    = stm->ICR;

    if (config->comparator == 0)
    {
    	/* Configure the size, offset, and interrupt for Comparator 0 */
        comcon.B.MSIZE0  = config->compareSize;
        comcon.B.MSTART0 = config->compareOffset;
        icr.B.CMP0OS     = config->comparatorInterrupt;
        result           = TRUE;
    }
    else if (config->comparator == 1)
    {
    	/* Configure the size, offset, and interrupt for Comparator 1 */
        comcon.B.MSIZE1  = config->compareSize;
        comcon.B.MSTART1 = config->compareOffset;
        icr.B.CMP1OS     = config->comparatorInterrupt;
        result           = TRUE;
    }
    else
    {
        /*Invalid value */
        result = FALSE;
    }

    stm->ICR.U   = icr.U;
    stm->CMCON.U = comcon.U;

    /* configure interrupt */
    index = IfxStm_getIndex(stm);

    if (config->triggerPriority > 0)
    {
        volatile Ifx_SRC_SRCR *srcr;

        if (config->comparatorInterrupt == IfxStm_ComparatorInterrupt_ir0)
        {
            srcr = &(MODULE_SRC.STM.STM[index].SR[0]);
        }
        else
        {
            srcr = &(MODULE_SRC.STM.STM[index].SR[1]);
        }

        IfxSrc_init(srcr, config->typeOfService, config->triggerPriority);
        IfxSrc_enable(srcr);
    }

    /*Configure the comparator ticks to current value to avoid any wrong triggering*/
    stm->CMP[config->comparator].U = IfxStm_getOffsetTimer(stm, (uint8)config->compareOffset);

    /* clear the interrupt flag of the selected comparator before enabling the interrupt */
    /* this is to avaoid the unneccesary interrupt for the compare match of reset values of the registers */
    IfxStm_clearCompareFlag(stm, config->comparator);
    /* enable the interrupt for the selected comparator */
    IfxStm_enableComparatorInterrupt(stm, config->comparator);

    /*Configure the comparator ticks */
    stm->CMP[config->comparator].U = IfxStm_getOffsetTimer(stm, (uint8)config->compareOffset) + config->ticks;

    return result;
}


void IfxStm_initCompareConfig(IfxStm_CompareConfig *config)
{
    config->comparator          = IfxStm_Comparator_0;
    config->compareOffset       = IfxStm_ComparatorOffset_0;
    config->compareSize         = IfxStm_ComparatorSize_32Bits;
    config->comparatorInterrupt = IfxStm_ComparatorInterrupt_ir0;     /*User must select the interrupt output */
    config->ticks               = 0xFFFFFFFF;
    config->triggerPriority     = 0;
    config->typeOfService       = IfxSrc_Tos_cpu0;
}


boolean IfxStm_isCompareFlagSet(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
        return stm->ICR.B.CMP0IR;
    }
    else // if (comparator == IfxStm_Comparator_1)
    {
        return stm->ICR.B.CMP1IR;
    }
}


void IfxStm_resetModule(Ifx_STM *stm)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    stm->KRST0.B.RST = 1;           /* Only if both Kernel reset bits are set a reset is executed */
    stm->KRST1.B.RST = 1;
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
    /* Wait until reset is executed */
    while (0 == stm->KRST0.B.RSTSTAT)   

    {}
    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    stm->KRSTCLR.B.CLR = 1;         
    /* setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxStm_setCompareControl(Ifx_STM *stm, IfxStm_Comparator comparator, IfxStm_ComparatorOffset offset, IfxStm_ComparatorSize size, IfxStm_ComparatorInterrupt interrupt)
{
    Ifx_STM_CMCON comcon = stm->CMCON;
    Ifx_STM_ICR   icr    = stm->ICR;

    if (comparator == 0)
    {
	/* Configure the size, offset, and interrupt for Comparator 0 */
        comcon.B.MSIZE0  = size;
        comcon.B.MSTART0 = offset;
        icr.B.CMP0OS     = interrupt;
    }
    else // if (comparator == 1)
    {
	/* Configure the size, offset, and interrupt for Comparator 1 */
        comcon.B.MSIZE1  = size;
        comcon.B.MSTART1 = offset;
        icr.B.CMP1OS     = interrupt;
    }

    stm->ICR.U   = icr.U;
    stm->CMCON.U = comcon.U;
}
