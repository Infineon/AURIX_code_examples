/**
 * \file IfxCpu.c
 * \brief CPU  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxCpu.h"
#include "Pms/Std/IfxPmsPm.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxCpu_acquireMutex(IfxCpu_mutexLock *lock)
{
    boolean         retVal;
    volatile uint32 spinLockVal;

    retVal      = FALSE;

    spinLockVal = 1UL;
    spinLockVal =
        (uint32)__cmpAndSwap(((unsigned int *)lock), spinLockVal, 0);

    /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
    if (spinLockVal == 0)
    {
        retVal = TRUE;
    }

    return retVal;
}


void IfxCpu_disableOverlayBlock(IfxCpu_ResourceCpu cpu, uint16 overlayBlock)
{
    Ifx_CPU          *ovcSfrBase = NULL_PTR;

    Ifx_SCU_OVCCON    ovccon;
    Ifx_SCU_OVCENABLE ovcenable;
    uint16            safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();

    /* Clear endinit protection */
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    ovccon.U    = MODULE_SCU.OVCCON.U;
    ovcenable.U = MODULE_SCU.OVCENABLE.U;
#if IFXCPU_NUM_MODULES > 1
    /* Disable Overlay in SCU */
    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        ovcSfrBase        = &MODULE_CPU1;
        ovcenable.B.OVEN1 = 0;
        ovccon.B.CSEL1    = 0;
        break;

#if IFXCPU_NUM_MODULES > 2
    case IfxCpu_ResourceCpu_2:
        ovcSfrBase        = &MODULE_CPU2;
        ovcenable.B.OVEN2 = 0;
        ovccon.B.CSEL2    = 0;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
    case IfxCpu_ResourceCpu_3:
        ovcSfrBase        = &MODULE_CPU3;
        ovcenable.B.OVEN3 = 0;
        ovccon.B.CSEL3    = 0;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
    case IfxCpu_ResourceCpu_4:
        ovcSfrBase        = &MODULE_CPU4;
        ovcenable.B.OVEN4 = 0;
        ovccon.B.CSEL4    = 0;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
    case IfxCpu_ResourceCpu_5:
        ovcSfrBase        = &MODULE_CPU5;
        ovcenable.B.OVEN5 = 0;
        ovccon.B.CSEL5    = 0;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    default:
        ovcSfrBase        = &MODULE_CPU0;
        ovcenable.B.OVEN0 = 0;
        ovccon.B.CSEL0    = 0;
        break;
    }
#else /* for IFXCPU_NUM_MODULES = 1*/
    ovcSfrBase        = &MODULE_CPU0;
    ovcenable.B.OVEN0 = 0;
    ovccon.B.CSEL0    = 0;
#endif /*#if IFXCPU_NUM_MODULES > 1*/
    ovccon.B.OVSTP         = 1;
    ovccon.B.DCINVAL       = 1;
    MODULE_SCU.OVCCON.U    = ovccon.U;
    MODULE_SCU.OVCENABLE.U = ovcenable.U;

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);

    ovcSfrBase->BLK[overlayBlock].RABR.U  = 0;
    ovcSfrBase->BLK[overlayBlock].OTAR.U  = 0;
    ovcSfrBase->BLK[overlayBlock].OMASK.U = 0;
}


void IfxCpu_enableOverlayBlock(IfxCpu_ResourceCpu cpu, uint16 overlayBlock, IfxCpu_OverlayMemorySelect overlayMemorySelect, IfxCpu_OverlayAddressMask overlayAddressMask, uint32 targetBaseAddress, uint32 overlayBaseAddress)
{
    Ifx_CPU *ovcSfrBase = NULL_PTR;
#if IFXCPU_NUM_MODULES > 1
    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        ovcSfrBase = &MODULE_CPU1;
        break;

#if IFXCPU_NUM_MODULES > 2
    case IfxCpu_ResourceCpu_2:
        ovcSfrBase = &MODULE_CPU2;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
    case IfxCpu_ResourceCpu_3:
        ovcSfrBase = &MODULE_CPU3;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
    case IfxCpu_ResourceCpu_4:
        ovcSfrBase = &MODULE_CPU4;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
    case IfxCpu_ResourceCpu_5:
        ovcSfrBase = &MODULE_CPU5;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    default:
        ovcSfrBase = &MODULE_CPU0;
        break;
    }
#else /* for IFXCPU_NUM_MODULES = 1*/
    ovcSfrBase = &MODULE_CPU0;
#endif /*#if IFXCPU_NUM_MODULES > 1*/
    /* Select overlay Block */
    ovcSfrBase->OSEL.U |= 1 << overlayBlock;

    /* Configure ovcBlock */
    Ifx_CPU_BLK_RABR rabr;
    Ifx_CPU_BLK_OTAR otar;
    rabr.U                                = 0;
    rabr.B.OMEM                           = overlayMemorySelect;
    rabr.B.OBASE                          = overlayBaseAddress >> 5;

    otar.U                                = 0;
    otar.B.TBASE                          = targetBaseAddress >> 5;

    ovcSfrBase->BLK[overlayBlock].RABR.U  = rabr.U;
    ovcSfrBase->BLK[overlayBlock].OTAR.U  = otar.U;
    ovcSfrBase->BLK[overlayBlock].OMASK.U = ((overlayAddressMask << 5) & 0x0001FFE0);

    /* Enable Overlay in SCU */
    uint16         safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();

    /* Clear endinit protection */
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    Ifx_SCU_OVCCON ovccon;
    ovccon.U = MODULE_SCU.OVCCON.U;
#if IFXCPU_NUM_MODULES > 1
    switch (cpu)
    {
    case IfxCpu_ResourceCpu_1:
        MODULE_SCU.OVCENABLE.B.OVEN1 = 1;
        ovccon.B.CSEL1               = 1;
        break;

#if IFXCPU_NUM_MODULES > 2
    case IfxCpu_ResourceCpu_2:
        MODULE_SCU.OVCENABLE.B.OVEN2 = 1;
        ovccon.B.CSEL2               = 1;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
    case IfxCpu_ResourceCpu_3:
        MODULE_SCU.OVCENABLE.B.OVEN3 = 1;
        ovccon.B.CSEL3               = 1;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
    case IfxCpu_ResourceCpu_4:
        MODULE_SCU.OVCENABLE.B.OVEN4 = 1;
        ovccon.B.CSEL4               = 1;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
    case IfxCpu_ResourceCpu_5:
        MODULE_SCU.OVCENABLE.B.OVEN5 = 1;
        ovccon.B.CSEL5               = 1;
        break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    default:
        MODULE_SCU.OVCENABLE.B.OVEN0 = 1;
        ovccon.B.CSEL0               = 1;
        break;
    }
#else    
    MODULE_SCU.OVCENABLE.B.OVEN0 = 1;
    ovccon.B.CSEL0               = 1;
#endif /*#if IFXCPU_NUM_MODULES > 1*/
    ovccon.B.OVSTRT     = 1;
    MODULE_SCU.OVCCON.U = ovccon.U;

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}


IfxCpu_CoreMode IfxCpu_getCoreMode(Ifx_CPU *cpu)
{
    IfxCpu_CoreMode          cpuMode;
    Ifx_CPU_DBGSR            dbgsr;
    IfxCpu_ResourceCpu       index = IfxCpu_getIndex(cpu);

    volatile Ifx_SCU_PMCSR0 *pmcsr_val0;
#if IFXCPU_NUM_MODULES > 1
    volatile Ifx_SCU_PMCSR1 *pmcsr_val1;
#endif /*#if IFXCPU_NUM_MODULES > 1*/
#if IFXCPU_NUM_MODULES > 2
    volatile Ifx_SCU_PMCSR2 *pmcsr_val2;
#endif /*#if IFXCPU_NUM_MODULES > 2*/
#if IFXCPU_NUM_MODULES > 3
    volatile Ifx_SCU_PMCSR3 *pmcsr_val3;
#endif /*#if IFXCPU_NUM_MODULES > 3*/
#if IFXCPU_NUM_MODULES > 4
    volatile Ifx_SCU_PMCSR4 *pmcsr_val4;
#endif /*#if IFXCPU_NUM_MODULES > 4*/
#if IFXCPU_NUM_MODULES > 5
    volatile Ifx_SCU_PMCSR5 *pmcsr_val5;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    cpuMode = IfxCpu_CoreMode_unknown;

    /*get the DBGSR.HALT status */
    /*Check if the request is done for same cpu as the host for this call */
    if (IfxCpu_getCoreIndex() != index)
    {                           /*status request is for other cpu than the host */
        dbgsr = cpu->DBGSR;
    }
    else
    {                           /*status request is for same cpu as the host */
        dbgsr.U = __mfcr(CPU_DBGSR);
    }

    /*Check if the requested CPU is in DBG HALT mode */
    if (dbgsr.B.HALT == (uint32)IfxCpu_DBGST_HALT_halt)
    {                           /*CPU is in DBG HALT mode */
        cpuMode = IfxCpu_CoreMode_halt;
    }
    else
    {
        /*Check if the requested CPU is in DBG HALT run mode */
        if (dbgsr.B.HALT == (uint32)IfxCpu_DBGST_HALT_run)
        {                       /*CPU is in DBG RUNNING mode now check PMCSR status */
            switch (index)
            {
            case IfxCpu_ResourceCpu_0:

                pmcsr_val0 = &MODULE_SCU.PMCSR0;

                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val0->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val0->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;

#if IFXCPU_NUM_MODULES > 1
            case IfxCpu_ResourceCpu_1:

                pmcsr_val1 = &MODULE_SCU.PMCSR1;

                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val1->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val1->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
#endif /*#if IFXCPU_NUM_MODULES > 1*/

#if IFXCPU_NUM_MODULES > 2
            case IfxCpu_ResourceCpu_2:

                pmcsr_val2 = &MODULE_SCU.PMCSR2;

                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val2->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val2->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
            case IfxCpu_ResourceCpu_3:

                pmcsr_val3 = &MODULE_SCU.PMCSR3;

                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val3->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val3->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
            case IfxCpu_ResourceCpu_4:

                pmcsr_val4 = &MODULE_SCU.PMCSR4;

                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val4->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val4->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
            case IfxCpu_ResourceCpu_5:

                pmcsr_val5 = &MODULE_SCU.PMCSR5;
                
                /*Check if the requested CPU is in normal run mode */
                if (pmcsr_val5->B.PMST == (uint32)IfxCpu_PMCSR_PMST_normalMode)
                {                   /*Cpu is in normal run mode */
                    cpuMode = IfxCpu_CoreMode_run;
                }
                else
                {                   /*Cpu is not in run mode */
                    if (pmcsr_val5->B.PMST == (uint32)IfxCpu_PMCSR_PMST_idleMode)
                    {               /*Cpu is in idle mode */
                        cpuMode = IfxCpu_CoreMode_idle;
                    }
                }

                break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
            default:
                /* Invalid core selected */
                break;
            }
        }
    }

    return cpuMode;
}


IfxCpu_ResourceCpu IfxCpu_getIndex(Ifx_CPU *cpu)
{
    IfxCpu_ResourceCpu result;
    uint32             index;
    result = IfxCpu_ResourceCpu_none;

    for (index = 0; index < IFXCPU_NUM_MODULES; index++)
    {
        if (IfxCpu_cfg_indexMap[index].module == cpu)
        {
            result = (IfxCpu_ResourceCpu)IfxCpu_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


uint32 IfxCpu_getRandomValue(uint32 *seed)
{
    /*************************************************************************
     * the choice of a and m is important for a long period of the LCG
     * with a =  279470273 and
     *       m = 4294967291
     * a maximum period of 2^32-5 is given
     * values for a:
     * 0x5EB0A82F = 1588635695
     * 0x48E7211F = 1223106847
     * 0x10a860c1 =  279470273
     ***************************************************************************/
    uint32 x = *seed;

    /* a seed of 0 is not allowed, and therefore will be changed to a valid value */
    if (x == 0)
    {
        x = 42;
    }

    uint32 a = 0x10a860c1;  // 279470273
    uint32 m = 0xfffffffb;  // 4294967291
    uint32 result;

    //__asm(a,m,x,tmp1,tmp2              );
    //EhEl = a * x;
    //result = e14 %  m;
    // %0 result
    // %1 a
    // %2 x
    // %3 m
    result = IfxCpu_getRandomVal(a, x, m);

    *seed  = result; // to simplify seed passing

    return result;
}


uint32 IfxCpu_getRandomValueWithinRange(uint32 *seed, uint32 min, uint32 max)
{
    uint32 new_value = IfxCpu_getRandomValue(seed);

    /* swap min/max if required */
    if (min > max)
    {
        unsigned swap = max;
        max = min;
        min = swap;
    }

    /* special case */
    if ((min == 0) && (max == 0xffffffff))
    {
        return new_value;
    }

    /* return value within range */
    return (new_value % (max - min + 1)) + min;
}


void IfxCpu_releaseMutex(IfxCpu_mutexLock *lock)
{
    /*Reset the SpinLock*/
    *lock = 0;
}


void IfxCpu_resetSpinLock(IfxCpu_spinLock *lock)
{
    /*Reset the SpinLock*/
    *lock = 0;
}


boolean IfxCpu_setCoreMode(Ifx_CPU *cpu, IfxCpu_CoreMode mode)
{
    IfxCpu_ResourceCpu cpuIndex;
    cpuIndex = IfxCpu_getIndex(cpu);
    return IfxPmsPm_setCoreMode(cpuIndex, mode);
}


boolean IfxCpu_setProgramCounter(Ifx_CPU *cpu, uint32 programCounter)
{
    boolean retVal = TRUE;

    if (cpu == IfxCpu_getAddress(IfxCpu_getCoreIndex()))
    {
        retVal = FALSE;
    }
    else
    {
        cpu->PC.B.PC = programCounter >> 1;
    }

    return retVal;
}


boolean IfxCpu_setSpinLock(IfxCpu_spinLock *lock, uint32 timeoutCount)
{
    boolean         retVal;
    volatile uint32 spinLockVal;

    retVal = FALSE;

    do
    {
        spinLockVal = 1UL;
        spinLockVal =
            (uint32)__cmpAndSwap(((unsigned int *)lock), spinLockVal, 0);

        /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
        if (spinLockVal == 0)
        {
            retVal = TRUE;
        }
        else
        {
            timeoutCount--;
        }
    } while ((retVal == FALSE) && (timeoutCount > 0));

    return retVal;
}


boolean IfxCpu_startCore(Ifx_CPU *cpu, uint32 programCounter)
{
    boolean retVal = TRUE;

    /* Set the PC */
    retVal &= IfxCpu_setProgramCounter(cpu, programCounter);

    /* release boot halt mode if required */
    {
        Ifx_CPU_SYSCON syscon;
        syscon = cpu->SYSCON;

        if (syscon.B.BHALT)
        {
            syscon.B.BHALT = 0; cpu->SYSCON = syscon;
        }
    }

    return retVal;
}


boolean IfxCpu_waitEvent(IfxCpu_syncEvent *event, uint32 timeoutMilliSec)
{
    volatile uint32 *sync          = (volatile uint32 *)IFXCPU_GLB_ADDR_DSPR(__mfcr(CPU_CORE_ID), event);

    boolean          errorcnt      = 0U;
    /* Divide with 1000, gives the count value equivalent to milliseconds */
    uint32           stmCount      = (uint32)((IfxScuCcu_getStmFrequency() / 1000) * timeoutMilliSec);
    uint32           stmCountBegin = STM0_TIM0.U;

    while ((*sync & IFXCPU_CFG_ALLCORE_DONE) != IFXCPU_CFG_ALLCORE_DONE)
    {
        __nop();

        if ((uint32)(STM0_TIM0.U - stmCountBegin) >= stmCount)
        {
            errorcnt = 1;
            break;
        }

        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }

    return errorcnt;
}


void IfxCpu_emitEvent(IfxCpu_syncEvent *event)
{
    Ifx__imaskldmst(event, 1, __mfcr(CPU_CORE_ID), 1);
}


void IfxCpu_triggerCpuReset(IfxCpu_ResourceCpu coreIndex)
{
    if (coreIndex != IfxCpu_getCoreIndex())
    {
        uint16   password = IfxScuWdt_getGlobalEndinitPassword();
        Ifx_CPU *cpu      = IfxCpu_getAddress(coreIndex);

        /* Clear endinit protection */
        IfxScuWdt_clearGlobalEndinit(password);
        cpu->KRST0.B.RST = 1;
        cpu->KRST1.B.RST = 1;
        /* Set the endinit protection again */
        IfxScuWdt_setGlobalEndinit(password);
    }

    else

    {
//Do nothing because one cannot set the endinit back from the same CPU which is reset
    }
}


IfxCpu_ResetStatus IfxCpu_getCpuResetStatus(IfxCpu_ResourceCpu coreIndex)
{
    Ifx_CPU           *cpu    = IfxCpu_getAddress(coreIndex);
    IfxCpu_ResetStatus status = (IfxCpu_ResetStatus)cpu->KRST0.B.RSTSTAT;
    cpu->KRSTCLR.B.CLR = 1;
    return status;
}

#if IFXCPU_NUM_MODULES > 1
void IfxCpu_setAllIdleExceptMasterCpu(IfxCpu_ResourceCpu masterCpu)
{
    uint16 endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPasswordInline();

    /* Clear endinit protection */
    IfxScuWdt_clearSafetyEndinitInline(endinitSfty_pw);

    switch (masterCpu)
    {
    case IfxCpu_ResourceCpu_0:
    	/* Request CPU1 Idle mode */
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

#if IFXCPU_NUM_MODULES > 2
        /* Request CPU2 Idle mode */
        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
        /* Request CPU3 Idle mode */
        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        /* Request CPU4 Idle mode */
        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        /* Request CPU5 Idle mode */
        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;

    case IfxCpu_ResourceCpu_1:
    	/* Request CPU0 Idle mode */
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

#if IFXCPU_NUM_MODULES > 2
        /* Request CPU2 Idle mode */
        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
        /* Request CPU3 Idle mode */
        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        /* Request CPU4 Idle mode */
        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        /* Request CPU5 Idle mode */
        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;

#if IFXCPU_NUM_MODULES > 2
    case IfxCpu_ResourceCpu_2:
    	/* Request CPU0 Idle mode */
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        /* Request CPU1 Idle mode */
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

#if IFXCPU_NUM_MODULES > 3
        /* Request CPU3 Idle mode */
        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        /* Request CPU4 Idle mode */
        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        /* Request CPU5 Idle mode */
        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
    case IfxCpu_ResourceCpu_3:
    	/* Request CPU0 Idle mode */
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        /* Request CPU1 Idle mode */
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        /* Request CPU2 Idle mode */
        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

#if IFXCPU_NUM_MODULES > 4
        /* Request CPU4 Idle mode */
        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        /* Request CPU5 Idle mode */
        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
    case IfxCpu_ResourceCpu_4:
    	/* Request CPU0 Idle mode */
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        /* Request CPU1 Idle mode */
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        /* Request CPU2 Idle mode */
        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        /* Request CPU3 Idle mode */
        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

#if IFXCPU_NUM_MODULES > 5
        /* Request CPU5 Idle mode */
        SCU_PMCSR5.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU5)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
    case IfxCpu_ResourceCpu_5:
    	/* Request CPU0 Idle mode */
        SCU_PMCSR0.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU0)
        {}

        /* Request CPU1 Idle mode */
        SCU_PMCSR1.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU1)
        {}

        /* Request CPU2 Idle mode */
        SCU_PMCSR2.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU2)
        {}

        /* Request CPU3 Idle mode */
        SCU_PMCSR3.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU3)
        {}

        /* Request CPU4 Idle mode */
        SCU_PMCSR4.B.REQSLP = 0x1;

        while (SCU_PMSTAT0.B.CPU4)
        {}

        break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    default:
        /* Invalid core selected */
        break;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setSafetyEndinitInline(endinitSfty_pw);
}
#endif /*#if IFXCPU_NUM_MODULES > 1*/

#if IFXCPU_NUM_MODULES > 1
void IfxCpu_disableInterruptsAllExceptMaster(IfxCpu_ResourceCpu masterCpu)
{
    uint16 password = IfxScuWdt_getGlobalEndinitPassword();

    /* Clear endinit protection */
    IfxScuWdt_clearGlobalEndinit(password);

    switch (masterCpu)
    {
    case IfxCpu_ResourceCpu_0:
        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

#if IFXCPU_NUM_MODULES > 2
        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;

    case IfxCpu_ResourceCpu_1:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

#if IFXCPU_NUM_MODULES > 2
        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;

#if IFXCPU_NUM_MODULES > 2
    case IfxCpu_ResourceCpu_2:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

#if IFXCPU_NUM_MODULES > 3
        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 2*/

#if IFXCPU_NUM_MODULES > 3
    case IfxCpu_ResourceCpu_3:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

#if IFXCPU_NUM_MODULES > 4
        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 3*/

#if IFXCPU_NUM_MODULES > 4
    case IfxCpu_ResourceCpu_4:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

#if IFXCPU_NUM_MODULES > 5
        CPU5_ICR.B.IE = 0;

        while (CPU5_ICR.B.IE)
        {}
#endif /*#if IFXCPU_NUM_MODULES > 5*/
        break;
#endif /*#if IFXCPU_NUM_MODULES > 4*/

#if IFXCPU_NUM_MODULES > 5
    case IfxCpu_ResourceCpu_5:
        CPU0_ICR.B.IE = 0;

        while (CPU0_ICR.B.IE)
        {}

        CPU1_ICR.B.IE = 0;

        while (CPU1_ICR.B.IE)
        {}

        CPU2_ICR.B.IE = 0;

        while (CPU2_ICR.B.IE)
        {}

        CPU3_ICR.B.IE = 0;

        while (CPU3_ICR.B.IE)
        {}

        CPU4_ICR.B.IE = 0;

        while (CPU4_ICR.B.IE)
        {}

        break;
#endif /*#if IFXCPU_NUM_MODULES > 5*/
    default:
        /* Invalid core selected */
        break;
    }

    /* Set the endinit protection again */
    IfxScuWdt_setGlobalEndinit(password);
}

void IfxCpu_enableMemoryProtection(void)
{
    Ifx_CPU_SYSCON sysconValue;
    sysconValue.U = __mfcr(CPU_SYSCON);                 /* Get the System Configuration Register (SYSCON) value     */
    sysconValue.B.PROTEN = 1;                           /* Set the PROTEN bitfield to enable the Memory Protection  */
    __mtcr(CPU_SYSCON, sysconValue.U);                  /* Set the System Configuration Register (SYSCON)           */

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_disableMemoryProtection(void)
{
    Ifx_CPU_SYSCON sysconValue;
    sysconValue.U = __mfcr(CPU_SYSCON);                 /* Get the System Configuration Register (SYSCON) value     */
    sysconValue.B.PROTEN = 0;                           /* Set the PROTEN bitfield to disable the Memory Protection  */
    __mtcr(CPU_SYSCON, sysconValue.U);                  /* Set the System Configuration Register (SYSCON)           */

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_defineDataProtectionRange(uint32 lowerBoundAddress, uint32 upperBoundAddress, IfxCpu_DataProtectionRange range)
{
    /* Set the lower and upper bound of CPU Data Protection Range */
    switch(range)
    {
        case IfxCpu_DataProtectionRange_0:
            __mtcr(CPU_DPR0_L,  lowerBoundAddress);
            __mtcr(CPU_DPR0_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_1:
            __mtcr(CPU_DPR1_L,  lowerBoundAddress);
            __mtcr(CPU_DPR1_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_2:
            __mtcr(CPU_DPR2_L,  lowerBoundAddress);
            __mtcr(CPU_DPR2_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_3:
            __mtcr(CPU_DPR3_L,  lowerBoundAddress);
            __mtcr(CPU_DPR3_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_4:
            __mtcr(CPU_DPR4_L,  lowerBoundAddress);
            __mtcr(CPU_DPR4_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_5:
            __mtcr(CPU_DPR5_L,  lowerBoundAddress);
            __mtcr(CPU_DPR5_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_6:
            __mtcr(CPU_DPR6_L,  lowerBoundAddress);
            __mtcr(CPU_DPR6_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_7:
            __mtcr(CPU_DPR7_L,  lowerBoundAddress);
            __mtcr(CPU_DPR7_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_8:
            __mtcr(CPU_DPR8_L,  lowerBoundAddress);
            __mtcr(CPU_DPR8_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_9:
            __mtcr(CPU_DPR9_L,  lowerBoundAddress);
            __mtcr(CPU_DPR9_U,  upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_10:
            __mtcr(CPU_DPR10_L, lowerBoundAddress);
            __mtcr(CPU_DPR10_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_11:
            __mtcr(CPU_DPR11_L, lowerBoundAddress);
            __mtcr(CPU_DPR11_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_12:
            __mtcr(CPU_DPR12_L, lowerBoundAddress);
            __mtcr(CPU_DPR12_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_13:
            __mtcr(CPU_DPR13_L, lowerBoundAddress);
            __mtcr(CPU_DPR13_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_14:
            __mtcr(CPU_DPR14_L, lowerBoundAddress);
            __mtcr(CPU_DPR14_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_15:
            __mtcr(CPU_DPR15_L, lowerBoundAddress);
            __mtcr(CPU_DPR15_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_16:
            __mtcr(CPU_DPR16_L, lowerBoundAddress);
            __mtcr(CPU_DPR16_U, upperBoundAddress);
            break;
        case IfxCpu_DataProtectionRange_17:
            __mtcr(CPU_DPR17_L, lowerBoundAddress);
            __mtcr(CPU_DPR17_U, upperBoundAddress);
            break;
        default:
            break; /* Invalid range */
    }

#if !defined(__TASKING__)
    __isync();
#endif
}


void IfxCpu_defineCodeProtectionRange(uint32 lowerBoundAddress, uint32 upperBoundAddress, IfxCpu_CodeProtectionRange range)
{
    /* Set the lower and upper bound of CPU Code Protection Range */
    switch(range)
    {
        case IfxCpu_CodeProtectionRange_0:
            __mtcr(CPU_CPR0_L, lowerBoundAddress);
            __mtcr(CPU_CPR0_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_1:
            __mtcr(CPU_CPR1_L, lowerBoundAddress);
            __mtcr(CPU_CPR1_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_2:
            __mtcr(CPU_CPR2_L, lowerBoundAddress);
            __mtcr(CPU_CPR2_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_3:
            __mtcr(CPU_CPR3_L, lowerBoundAddress);
            __mtcr(CPU_CPR3_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_4:
            __mtcr(CPU_CPR4_L, lowerBoundAddress);
            __mtcr(CPU_CPR4_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_5:
            __mtcr(CPU_CPR5_L, lowerBoundAddress);
            __mtcr(CPU_CPR5_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_6:
            __mtcr(CPU_CPR6_L, lowerBoundAddress);
            __mtcr(CPU_CPR6_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_7:
            __mtcr(CPU_CPR7_L, lowerBoundAddress);
            __mtcr(CPU_CPR7_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_8:
            __mtcr(CPU_CPR8_L, lowerBoundAddress);
            __mtcr(CPU_CPR8_U, upperBoundAddress);
            break;
        case IfxCpu_CodeProtectionRange_9:
            __mtcr(CPU_CPR9_L, lowerBoundAddress);
            __mtcr(CPU_CPR9_U, upperBoundAddress);
            break;
        default:
            break; /* Invalid range */
    }

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_enableDataRead(IfxCpu_ProtectionSet protectionSet, IfxCpu_DataProtectionRange range)
{
    Ifx_CPU_DPRE dpreRegisterValue;

    /* Get the CPU Data Protection Read Enable Register value
     * Set the bit corresponding to the given Data Protection Range
     * Set the CPU Data Protection Read Enable Register value to enable data read access */
    switch(protectionSet)
    {
        case IfxCpu_ProtectionSet_0:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_0);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_0, dpreRegisterValue.U);
        break;
    case IfxCpu_ProtectionSet_1:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_1);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_1, dpreRegisterValue.U);
        break;
    case IfxCpu_ProtectionSet_2:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_2);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_2, dpreRegisterValue.U);
        break;
    case IfxCpu_ProtectionSet_3:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_3);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_3, dpreRegisterValue.U);
        break;
    case IfxCpu_ProtectionSet_4:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_4);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_4, dpreRegisterValue.U);
        break;
    case IfxCpu_ProtectionSet_5:
        dpreRegisterValue.U = __mfcr(CPU_DPRE_5);
        dpreRegisterValue.B.RE_N |= (1 << range);
        __mtcr(CPU_DPRE_5, dpreRegisterValue.U);
        break;
    default:
        break; /* Invalid protection set */
    }

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_enableDataWrite(IfxCpu_ProtectionSet protectionSet, IfxCpu_DataProtectionRange range)
{
    Ifx_CPU_DPWE dpweRegisterValue;

    /* Get the CPU Data Protection Write Enable Register value
     * Set the bit corresponding to the given Data Protection Range
     * Set the CPU Data Protection Write Enable Register value to enable data write access */
    switch(protectionSet)
    {
        case IfxCpu_ProtectionSet_0:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_0);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_0, dpweRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_1:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_1);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_1, dpweRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_2:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_2);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_2, dpweRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_3:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_3);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_3, dpweRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_4:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_4);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_4, dpweRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_5:
            dpweRegisterValue.U = __mfcr(CPU_DPWE_5);
            dpweRegisterValue.B.WE_N |= (0x1 << range);
            __mtcr(CPU_DPWE_5, dpweRegisterValue.U);
            break;
        default:
            break; /* Invalid protection set */
    }

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_enableCodeExecution(IfxCpu_ProtectionSet protectionSet, IfxCpu_CodeProtectionRange range)
{
    Ifx_CPU_CPXE cpxeRegisterValue;

    /* Get the CPU Code Protection Execute Enable Register value
     * Set the bit corresponding to the given Code Protection Range
     * Set the CPU Code Protection Execute Enable Register value to enable code execution */
    switch(protectionSet)
    {
        case IfxCpu_ProtectionSet_0:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_0);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_0, cpxeRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_1:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_1);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_1, cpxeRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_2:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_2);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_2, cpxeRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_3:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_3);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_3, cpxeRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_4:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_4);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_4, cpxeRegisterValue.U);
            break;
        case IfxCpu_ProtectionSet_5:
            cpxeRegisterValue.U = __mfcr(CPU_CPXE_5);
            cpxeRegisterValue.B.XE_N |= (0x1 << range);
            __mtcr(CPU_CPXE_5, cpxeRegisterValue.U);
            break;
        default:
            break; /* Invalid protection set */
    }

#if !defined(__TASKING__)
    __isync();
#endif
}

void IfxCpu_loadMpuConfig(const IfxCpu_MpuConfig *mpuConfig)
{
    /* Configure Data Protection Ranges */
    for (int i = 0; i < DATA_PROT_RANGE_COUNT; ++i)
    {
        IfxCpu_defineDataProtectionRange(mpuConfig->dataProtectionRange[i].L.U, mpuConfig->dataProtectionRange[i].U.U, (IfxCpu_DataProtectionRange)i);
    }

    /* Configure Code Protection Ranges */
    for (int i = 0; i < CODE_PROT_RANGE_COUNT; ++i)
    {
        IfxCpu_defineCodeProtectionRange(mpuConfig->codeProtectionRange[i].L.U, mpuConfig->codeProtectionRange[i].U.U, (IfxCpu_CodeProtectionRange)i);
    }

    /* Set Access Permissions */
    for (int i = 0; i < PROTECTION_SET_COUNT; ++i)
    {
        IfxCpu_enableCodeExecution((IfxCpu_ProtectionSet)i, (IfxCpu_CodeProtectionRange)mpuConfig->accessPermissions[i].executionEnable.B.XE_N);
        IfxCpu_enableDataRead((IfxCpu_ProtectionSet)i, (IfxCpu_DataProtectionRange)mpuConfig->accessPermissions[i].readEnable.B.RE_N);
        IfxCpu_enableDataWrite((IfxCpu_ProtectionSet)i, (IfxCpu_DataProtectionRange)mpuConfig->accessPermissions[i].writeEnable.B.WE_N);
    }
}

#endif /*#if IFXCPU_NUM_MODULES > 1*/

