/**
 * \file Cpu5_Main_Vm1.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#include "Ifx_Cfg.h"
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxStm.h"
#include "IfxHv_CpuVmSched.h"
#if (IFX_DEBUG_PRINT == 1U)
#include "printf_to_tspi.h"
#endif

volatile unsigned int tc5_vm1_scheduler_ctr = 0u;
volatile unsigned int tc5_vm1_main_ctr      = 0u;
volatile unsigned int tc5_vm1_isr_ctr       = 0u;
IFX_INTERRUPT_FUNC void Cpu5_Vm1_Isr(void);

/*VM1 main function
 * 1. In case cooperative scheduling mode is selected: relinquish the control after some ticks
 * 2. In case Timer mode is selected : No action needed
 * 3. If VM1 ISR is enabled: initialize STM to trigger event for VM1 */
void core5_vm1_main(void)
{
#if (IFX_CFG_TC5_VM1_INT != 0U)
    /* Enable interrupts by setting the IE bit */
    IfxCpu_enableInterrupts();

    /* STM configuration handler */
    IfxStm_CompareConfig stmCompareConfig;

    /* Call the constructor of configuration
     * Step 1 : Load the default configuration
     * Step 2 : Modify the configuration parameters
     * Step 3 : Initialize the STM with the configuration
     * In the default configuration STM, Comparator0 is used
     */
    IfxStm_initCompareConfig(&stmCompareConfig);
    stmCompareConfig.ticks           = (uint32)(IFX_VM1_INTERRUPT_INTERVAL * IfxHv_getStmFrequency());
    stmCompareConfig.triggerPriority = IFX_VM1_ISR_PRIORITY;
    stmCompareConfig.typeOfService   = IfxSrc_Tos_cpu5;
    stmCompareConfig.vmId            = IfxSrc_VmId_1;

    /* Initialize STM compare functionality */
    IfxStm_initCompare(&MODULE_CPU5, &stmCompareConfig);
#endif

    while (1)
    {
        tc5_vm1_main_ctr++;
        tc5_vm1_scheduler_ctr++;
#if (IFX_DEBUG_PRINT == 1U)

#if (IFX_CFG_TC5_VM1_INT != 0U)
        printf("TC5 VM1 isr Counter is %d\n", tc5_vm1_isr_ctr);
#else
        printf("TC5 VM1 main Counter is %d\n", tc5_vm1_main_ctr);
#endif
#endif

#if (IFX_CFG_HV5_TIME_BASED_SCHD == 0U)

        if (tc5_vm1_scheduler_ctr > 50u)
        {
            tc5_vm1_scheduler_ctr = 0u;
            Ifx__hvcall(1);
        }

#endif
    }
}


/* ISR for STM1 event on VM1
 * 1. Reload the STM1 timer value for next event
 * 2. Increment VM1 ISR counter value */
#if (IFX_CFG_TC5_VM1_INT != 0U)
IFX_INTERRUPT(Cpu5_Vm1_Isr, 5, IFX_VM1_ISR_PRIORITY)
{
    uint32 stmTicks;
    stmTicks = (uint32)(IFX_VM1_INTERRUPT_INTERVAL * IfxHv_getStmFrequency());
    IfxStm_updateCompare(&MODULE_CPU5, IfxStm_Comparator_0, (uint32)IfxStm_get(&MODULE_CPU5) + stmTicks);

    tc5_vm1_isr_ctr += 1u;

    /* This is added as a workaround since TASKING
     *  doesn't support interrupts for virtualization case.
     *  This can re removed in future if TASKING supports the same.
     */
#if defined(__TASKING__)
    __asm("ji a11");
#endif
}
#endif
