/**
 * \file IfxScuRcu.c
 * \brief SCU  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxScuRcu.h"

/******************************************************************************/
/*----------------------------------Macros------------------------------------*/
/******************************************************************************/

#define IFXSCURCU_PERFORM_RESET_DELAY (90000U)

#define IFXSCURCU_COLD_POWERON_MASK                             \
    ((IFX_SCU_RSTSTAT_STBYR_MSK << IFX_SCU_RSTSTAT_STBYR_OFF) | \
     (IFX_SCU_RSTSTAT_SWD_MSK << IFX_SCU_RSTSTAT_SWD_OFF) |     \
     (IFX_SCU_RSTSTAT_EVR33_MSK << IFX_SCU_RSTSTAT_EVR33_OFF) | \
     (IFX_SCU_RSTSTAT_EVRC_MSK << IFX_SCU_RSTSTAT_EVRC_OFF))

#define IFXSCURCU_WARM_POWERON_MASK   (IFX_SCU_RSTSTAT_PORST_MSK << IFX_SCU_RSTSTAT_PORST_OFF)

#define IFXSCURCU_ESR0_MASK           (1u << IFX_SCU_RSTSTAT_ESR0_OFF)

#define IFXSCURCU_ESR1_MASK           (1u << IFX_SCU_RSTSTAT_ESR1_OFF)

#define IFXSCURCU_SMU_MASK            (1u << IFX_SCU_RSTSTAT_SMU_OFF)

#define IFXSCURCU_SW_MASK             (1u << IFX_SCU_RSTSTAT_SW_OFF)

#define IFXSCURCU_STM0_MASK           (1u << IFX_SCU_RSTSTAT_STM0_OFF)

#if (IFXCPU_NUM_MODULES > 1U)
#define IFXSCURCU_STM1_MASK           (1u << IFX_SCU_RSTSTAT_STM1_OFF)
#endif

#if (IFXCPU_NUM_MODULES > 2U)
#define IFXSCURCU_STM2_MASK           (1u << IFX_SCU_RSTSTAT_STM2_OFF)
#endif

#if (IFXCPU_NUM_MODULES > 3U)
#define IFXSCURCU_STM3_MASK           (1u << IFX_SCU_RSTSTAT_STM3_OFF)
#endif

#if (IFXCPU_NUM_MODULES > 4U)
#define IFXSCURCU_STM4_MASK           (1u << IFX_SCU_RSTSTAT_STM4_OFF)
#endif

#if (IFXCPU_NUM_MODULES > 5U)
#define IFXSCURCU_STM5_MASK           (1u << IFX_SCU_RSTSTAT_STM5_OFF)
#endif
#define IFXSCURCU_EVRC_MASK           (1u << IFX_SCU_RSTSTAT_EVRC_OFF)

#define IFXSCURCU_EVR33_MASK          (1u << IFX_SCU_RSTSTAT_EVR33_OFF)

#define IFXSCURCU_SWD_MASK            (1u << IFX_SCU_RSTSTAT_SWD_OFF)

#define IFXSCURCU_STBYR_MASK          (1u << IFX_SCU_RSTSTAT_STBYR_OFF)

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

IfxScuRcu_ResetCode IfxScuRcu_evaluateReset(void)
{
    Ifx_SCU_RSTCON      Rstcon;
    Ifx_SCU_RSTSTAT     RstStat;
    IfxScuRcu_ResetCode resetCode;
    resetCode.cpuSafeState = (((MODULE_SCU.RSTCON2.U >> IFX_SCU_RSTCON2_CSSX_OFF) & IFX_SCU_RSTCON2_CSSX_MSK) == IFX_SCU_RSTCON2_CSSX_MSK);
    resetCode.resetType    = IfxScuRcu_ResetType_undefined;
    resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;
    resetCode.resetReason  = 0;

    /* Read the reset status and configuration registers */
    RstStat.U              = MODULE_SCU.RSTSTAT.U;
    Rstcon.U               = MODULE_SCU.RSTCON.U;

    /* Evaluate the warm reset conditions first */
    if (RstStat.B.ESR0)
    {	
    	/* External Service Request 0 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.ESR0;
        resetCode.resetTrigger = IfxScuRcu_Trigger_esr0;
        resetCode.resetReason  = 0;
    }
    else if (RstStat.B.ESR1)
    {	
    	/* External Service Request 1 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.ESR1;
        resetCode.resetTrigger = IfxScuRcu_Trigger_esr1;
        resetCode.resetReason  = 0;
    }
    else if (RstStat.B.SMU)
    {   
    	/* Safety Management Unit reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.SMU;
        resetCode.resetTrigger = IfxScuRcu_Trigger_smu;
        resetCode.resetReason  = 0;
    }
    else if (RstStat.B.SW)
    {	
    	/* Software reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.SW;
        resetCode.resetTrigger = IfxScuRcu_Trigger_sw;
        resetCode.resetReason  = MODULE_SCU.RSTCON2.B.USRINFO;
    }
    else if (RstStat.B.STM0)
    {	
    	/* System Timer 0 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM0;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm0;
        resetCode.resetReason  = 0;
    }
#if IFXCPU_NUM_MODULES > 1
    else if (RstStat.B.STM1)
    {   
    	/* System Timer 1 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM1;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm1;
        resetCode.resetReason  = 0;
    }
#endif
#if IFXCPU_NUM_MODULES > 2
    else if (RstStat.B.STM2)
    {   
    	/* System Timer 2 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM2;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm2;
        resetCode.resetReason  = 0;
    }
#endif
#if IFXCPU_NUM_MODULES > 3
    else if (RstStat.B.STM3)
    {	
    	/* System Timer 3 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM3;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm3;
        resetCode.resetReason  = 0;
    }
#endif
#if IFXCPU_NUM_MODULES > 4
    else if (RstStat.B.STM4)
    {	
    	/* System Timer 4 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM4;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm4;
        resetCode.resetReason  = 0;
    }
#endif
#if IFXCPU_NUM_MODULES > 5
    else if (RstStat.B.STM5)
    {	
    	/* System Timer 5 reset */
        resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM5;
        resetCode.resetTrigger = IfxScuRcu_Trigger_stm5;
        resetCode.resetReason  = 0;
    }
#endif
    else if (RstStat.B.CB0)
    {	
    	/* System reset */
        resetCode.resetType    = IfxScuRcu_ResetType_system;
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb0;
        resetCode.resetReason  = 0;
    }
    else if (RstStat.B.CB1)
    {	
    	/* Debug reset */
        resetCode.resetType    = IfxScuRcu_ResetType_debug;
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb1;
        resetCode.resetReason  = 0;
    }
    else if (RstStat.B.CB3)
    {	
    	/* Application reset */
        resetCode.resetType    = IfxScuRcu_ResetType_application;
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb3;
        resetCode.resetReason  = 0;
    }
    else
    {
        /* Now evaluate for Cold reset conditions */
        if (RstStat.B.EVRC)
        {   
        	/* Set the reset type to cold power-on and the trigger to EVRC */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;
            resetCode.resetTrigger = IfxScuRcu_Trigger_evrc;
            resetCode.resetReason  = 0;
        }
        else if (RstStat.B.EVR33)
        {   
        	/* Set the reset type to cold power-on and the trigger to EVR33 */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;
            resetCode.resetTrigger = IfxScuRcu_Trigger_evr33;
            resetCode.resetReason  = 0;
        }
        else if (RstStat.B.SWD)
        {   
        	/* Set the reset type to cold power-on and the trigger to SWD */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;
            resetCode.resetTrigger = IfxScuRcu_Trigger_swd;
            resetCode.resetReason  = 0;
        }
        else if (RstStat.B.STBYR)
        {   
        	/* Set the reset type to cold power-on and the trigger to STBYR */
            resetCode.resetType    = IfxScuRcu_ResetType_coldpoweron;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stbyr;
            resetCode.resetReason  = 0;
        }
    }

/* Finally - Evaluate selectively for PORST */
    if (RstStat.B.PORST)
    {   
        if (resetCode.resetType != IfxScuRcu_ResetType_coldpoweron)
        {
            resetCode.resetType    = IfxScuRcu_ResetType_warmpoweron;
            resetCode.resetTrigger = IfxScuRcu_Trigger_portst;
        }

        resetCode.resetReason = 0;
    }

    return resetCode;
}


void IfxScuRcu_performReset(IfxScuRcu_ResetType resetType, uint16 userResetInfo)
{
    uint32 index;
    uint16 password;

    /* Clear endinit protection */
    password = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinitInline(password);

    /* Write the Reset Type - Application or System Reset */
    if (IfxScuRcu_ResetType_system == resetType)
    {
        MODULE_SCU.RSTCON.B.SW = 1; /* System Reset */
    }
    else
    {
        MODULE_SCU.RSTCON.B.SW = 2; /* Application Reset */
    }

    /* SWRSTCON and RSTCON2 are CPU endinit protected - clear end init protection */
    password = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()]);

    /* Clear endinit protection */
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[IfxCpu_getCoreIndex()], password);
    /* Write the user DATA to reset evaluation */
    MODULE_SCU.RSTCON2.B.USRINFO = userResetInfo;

    /* Software Reset can be performed by writing to Reset Request register  SWRSTCON */
    MODULE_SCU.SWRSTCON.B.SWRSTREQ = 1U;

    /* Add some delay for HW to reset */
    for (index = 0U; index < (uint32)IFXSCURCU_PERFORM_RESET_DELAY; index++)
    {}

    /* IfxScu_Wdt_enableSafetyEndinit() is not needed, as the micro would RESET */
    /* IfxScuWdt_setCpuEndinitInline() is not needed, as the micro would RESET */
}


IfxScuRcu_ResetCode IfxScuRcu_getResetReason(void)
{
    Ifx_SCU_RSTCON      Rstcon;
    Ifx_SCU_RSTSTAT     RstStat;
    IfxScuRcu_ResetCode resetCode;

    uint32              cldRbits  = 0u;
    uint32              warmRbits = 0u;
    uint32              asRbits   = 0u;

    resetCode.cpuSafeState = (((MODULE_SCU.RSTCON2.U >> IFX_SCU_RSTCON2_CSSX_OFF) & IFX_SCU_RSTCON2_CSSX_MSK) == IFX_SCU_RSTCON2_CSSX_MSK);
    resetCode.resetType    = IfxScuRcu_ResetType_undefined;
    resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;
    resetCode.resetReason  = 0;

    /* Read the reset status and configuration registers */
    RstStat.U              = MODULE_SCU.RSTSTAT.U;
    Rstcon.U               = MODULE_SCU.RSTCON.U;

    /* Extract cold reset, warm reset & application reset bits for evaluation */
    cldRbits               = RstStat.U & IFXSCURCU_COLD_POWERON_MASK;
    warmRbits              = RstStat.U & IFXSCURCU_WARM_POWERON_MASK;
    asRbits                = RstStat.U & IFXSCURCU_APPLICATIONRESET_MASK;

    /* Evaluate Cold power on reset */
    if ((cldRbits != 0u) && (warmRbits != 0u) && (asRbits == 0u))  /* Cold Power On */
    {
        resetCode.resetType = IfxScuRcu_ResetType_coldpoweron;

        switch (cldRbits)
        {
        case IFXSCURCU_EVRC_MASK:
            resetCode.resetTrigger = IfxScuRcu_Trigger_evrc;
            break;

        case IFXSCURCU_EVR33_MASK:
            resetCode.resetTrigger = IfxScuRcu_Trigger_evr33;
            break;

        case IFXSCURCU_SWD_MASK:
            resetCode.resetTrigger = IfxScuRcu_Trigger_swd;
            break;

        case IFXSCURCU_STBYR_MASK:
            resetCode.resetTrigger = IfxScuRcu_Trigger_stbyr;
            break;

        default:
            resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;
            break;
        }
    }
    else if ((cldRbits == 0u) && (warmRbits != 0u) && (asRbits == 0u)) /* Warm Power On */
    {
        resetCode.resetType    = IfxScuRcu_ResetType_warmpoweron;
        resetCode.resetTrigger = IfxScuRcu_Trigger_portst;
    }
    else if ((cldRbits == 0u) && (warmRbits == 0u) && (asRbits != 0u)) /* App/Sys resets */
    {
        switch (asRbits)
        {
        case IFXSCURCU_ESR0_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.ESR0;
            resetCode.resetTrigger = IfxScuRcu_Trigger_esr0;
            break;

        case IFXSCURCU_ESR1_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.ESR1;
            resetCode.resetTrigger = IfxScuRcu_Trigger_esr1;
            break;

        case IFXSCURCU_SMU_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.SMU;
            resetCode.resetTrigger = IfxScuRcu_Trigger_smu;
            break;

        case IFXSCURCU_SW_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.SW;
            resetCode.resetTrigger = IfxScuRcu_Trigger_sw;
            break;

        case IFXSCURCU_STM0_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM0;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm0;
            break;

#if (IFXCPU_NUM_MODULES > 1U)
        case IFXSCURCU_STM1_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM1;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm1;
            break;
#endif

#if (IFXCPU_NUM_MODULES > 2U)
        case IFXSCURCU_STM2_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM2;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm2;
            break;
#endif

#if (IFXCPU_NUM_MODULES > 3U)
        case IFXSCURCU_STM3_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM3;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm3;
            break;
#endif

#if (IFXCPU_NUM_MODULES > 4U)
        case IFXSCURCU_STM4_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM4;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm4;
            break;
#endif

#if (IFXCPU_NUM_MODULES > 5U)
        case IFXSCURCU_STM5_MASK:
            resetCode.resetType    = (IfxScuRcu_ResetType)Rstcon.B.STM5;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm5;
            break;
#endif
        default:
            resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;
            break;
        }
    }
    else if ((cldRbits != 0u) || ((warmRbits != 0u) && (asRbits != 0u)))
    {
        resetCode.resetType = IfxScuRcu_ResetType_undefined;
    }
    else if ((cldRbits == 0u) && ((warmRbits != 0u) && (asRbits != 0u)))
    {
        resetCode.resetType = IfxScuRcu_ResetType_undefined;
    }
    else if (RstStat.B.CB0)
    {
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb0;
        resetCode.resetType    = IfxScuRcu_ResetType_system;
    }
    else if (RstStat.B.CB1)
    {
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb1;
        resetCode.resetType    = IfxScuRcu_ResetType_debug;
    }
    else if (RstStat.B.CB3)
    {
        resetCode.resetTrigger = IfxScuRcu_Trigger_cb3;
        resetCode.resetType    = IfxScuRcu_ResetType_application;
    }

    return resetCode;
}
