/**
 * \file IfxStm.c
 * \brief STM  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
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
        stm->ISCR.B.CMP0IRR = 1U;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
        stm->ISCR.B.CMP1IRR = 1U;
    }
}


void IfxStm_disableComparatorInterrupt(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
        stm->ICR.B.CMP0EN = 0U;
    }
    else // if (comparator == IfxStm_Comparator_1)
    {
        stm->ICR.B.CMP1EN = 0U;
    }
}


void IfxStm_disableModule(Ifx_STM *stm)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    stm->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxStm_enableComparatorInterrupt(Ifx_STM *stm, IfxStm_Comparator comparator)
{
    if (comparator == IfxStm_Comparator_0)
    {
        stm->ICR.B.CMP0EN = 1U;
    }
    else if (comparator == IfxStm_Comparator_1)
    {
        stm->ICR.B.CMP1EN = 1U;
    }
}


void IfxStm_enableOcdsSuspend(Ifx_STM *stm)
{
    Ifx_STM_OCS ocs = stm->OCS;

    ocs.B.SUS_P      = 1;
    ocs.B.SUS        = 2;
    stm->OCS         = ocs;
    stm->OCS.B.SUS_P = 0;
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
    return comparator == IfxStm_Comparator_0 ? &MODULE_SRC.STM.STM[index].SR0 : &MODULE_SRC.STM.STM[index].SR1;
}


boolean IfxStm_initCompare(Ifx_STM *stm, const IfxStm_CompareConfig *config)
{
    sint32        index;
    boolean       result;
    Ifx_STM_CMCON comcon = stm->CMCON;
    Ifx_STM_ICR   icr    = stm->ICR;

    if (config->comparator == 0)
    {
        comcon.B.MSIZE0  = config->compareSize;
        comcon.B.MSTART0 = config->compareOffset;
        icr.B.CMP0OS     = config->comparatorInterrupt;
        result           = TRUE;
    }
    else if (config->comparator == 1)
    {
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
            srcr = &(MODULE_SRC.STM.STM[index].SR0);
        }
        else
        {
            srcr = &(MODULE_SRC.STM.STM[index].SR1);
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
    /* TODO add interrupt configuration */
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

    IfxScuWdt_clearCpuEndinit(passwd);
    stm->KRST0.B.RST = 1;           /* Only if both Kernel reset bits are set a reset is executed */
    stm->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == stm->KRST0.B.RSTSTAT)   /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    stm->KRSTCLR.B.CLR = 1;         /* Clear Kernel reset status bit */

    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxStm_setCompareControl(Ifx_STM *stm, IfxStm_Comparator comparator, IfxStm_ComparatorOffset offset, IfxStm_ComparatorSize size, IfxStm_ComparatorInterrupt interrupt)
{
    Ifx_STM_CMCON comcon = stm->CMCON;
    Ifx_STM_ICR   icr    = stm->ICR;

    if (comparator == 0)
    {
        comcon.B.MSIZE0  = size;
        comcon.B.MSTART0 = offset;
        icr.B.CMP0OS     = interrupt;
    }
    else // if (comparator == 1)
    {
        comcon.B.MSIZE1  = size;
        comcon.B.MSTART1 = offset;
        icr.B.CMP1OS     = interrupt;
    }

    stm->ICR.U   = icr.U;
    stm->CMCON.U = comcon.U;
}
