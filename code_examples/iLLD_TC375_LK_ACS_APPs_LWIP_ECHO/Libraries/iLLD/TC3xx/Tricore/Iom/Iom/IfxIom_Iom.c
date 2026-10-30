/**
 * \file IfxIom_Iom.c
 * \brief IOM IOM details
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

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508				/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif
#ifndef DEVICE_TC33XED
#include "IfxIom_Iom.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxIom_Iom_clearFpcEdges(IfxIom_Iom_FpcConfig *fpcConfig, IfxIom_Iom *iom)
{
    Ifx_IOM *iomSFR    = iom->iom;
    uint8    channelId = (IfxIom_FpcChannelId)fpcConfig->channelId;

    /* To clear rising edge */
    if (fpcConfig->edgeType == IfxIom_EdgeClearType_rising)
    {
        Ifx_IOM_FPCESR tempFPCESR;
        /* Set the bit corresponding to the rising edge for the channel */
        tempFPCESR.U     = (1 << (channelId + 16U));
        iomSFR->FPCESR.U = tempFPCESR.U;
    }
    /* To clear falling edge */
    else if (fpcConfig->edgeType == IfxIom_EdgeClearType_falling)
    {
        Ifx_IOM_FPCESR tempFPCESR;
        /* Set the bit corresponding to the falling edge for the channel */
        tempFPCESR.U     = (1 << channelId);
        iomSFR->FPCESR.U = tempFPCESR.U;
    }
    /* To clear both edges */
    else if (fpcConfig->edgeType == IfxIom_EdgeClearType_risingFalling)
    {
        Ifx_IOM_FPCESR tempFPCESR;
        /* Set the bits for both rising and falling edges for the channel */
        tempFPCESR.U     = (1 << channelId);
        tempFPCESR.U    |= (1 << (channelId + 16U));
        iomSFR->FPCESR.U = tempFPCESR.U;
    }
    else
    {
        /* Do nothing */
    }
}


void IfxIom_Iom_deInitModule(IfxIom_Iom *iom)
{
	/* Resets the IOM module */
    IfxIom_resetModule(iom->iom);
}


boolean IfxIom_Iom_initAnalyser(IfxIom_Iom *iom, const IfxIom_Iom_LamConfig *lamConfig)
{
	/* Initializes the Logic Analyser Module (LAM) for internal event generation */

    boolean  status = TRUE;

    Ifx_IOM *iomSFR = iom->iom;
    uint8    lamId  = (IfxIom_LamId)lamConfig->lamId;
    {
        Ifx_IOM_LAMCFG tempLAMCFG;
        tempLAMCFG.U            = 0;
        tempLAMCFG.B.IVR        = lamConfig->referenceSignalInverted;
        tempLAMCFG.B.IVM        = lamConfig->monitorSignalInverted;
        tempLAMCFG.B.MOS        = lamConfig->lamMonitorSource;
        tempLAMCFG.B.RMS        = lamConfig->lamMode;
        tempLAMCFG.B.EWS        = lamConfig->eventSource;
        tempLAMCFG.B.EDS        = lamConfig->eventActiveEdgeSelection;
        tempLAMCFG.B.IVW        = lamConfig->eventWindowInverted;
        tempLAMCFG.B.MCS        = lamConfig->lamMonitorInputChannel;
        tempLAMCFG.B.RCS        = lamConfig->lamReferenceInputChannel;
        iomSFR->LAMCFG[lamId].U = tempLAMCFG.U;
    }

    {
        Ifx_IOM_LAMEWS tempLAMEWS;
        tempLAMEWS.U            = 0;
        tempLAMEWS.B.THR        = lamConfig->eventWindowThreshold;
        iomSFR->LAMEWS[lamId].U = tempLAMEWS.U;
    }
    return status;
}


void IfxIom_Iom_initAnalyserConfig(IfxIom_Iom_LamConfig *lamConfig)
{
	/* Initialize Lam with default values */
    lamConfig->lamId                    = IfxIom_LamId_0;
    lamConfig->lamMode                  = IfxIom_LamRunMode_freeRunning;
    lamConfig->lamMonitorInputChannel   = IfxIom_LamMonitorInputChannel_0;
    lamConfig->lamReferenceInputChannel = IfxIom_LamReferenceInputChannel_0;
    lamConfig->eventWindowThreshold     = 15;
    lamConfig->monitorSignalInverted    = TRUE;
    lamConfig->referenceSignalInverted  = TRUE;
    lamConfig->eventSource              = IfxIom_EventSource_reference;
    lamConfig->lamMonitorSource         = IfxIom_LamMonitorSource_directFpcMonitor;
    lamConfig->eventWindowInverted      = TRUE;
    lamConfig->eventActiveEdgeSelection = IfxIom_EventActiveEdgeSelection_positiveGateEitherClear;
}


boolean IfxIom_Iom_initCombiner(IfxIom_Iom *iom, const IfxIom_Iom_EcmConfig *ecmConfig)
{
	/* Initializes the Event Combiner Module (ECM) configuration */

    boolean  status = TRUE;
    Ifx_IOM *iomSFR = iom->iom;
    {
        Ifx_IOM_ECMCCFG tempECMCCFG;
        tempECMCCFG.U       = 0;
        tempECMCCFG.B.SELC0 = ecmConfig->eventCounter[0].input;
        tempECMCCFG.B.THRC0 = ecmConfig->eventCounter[0].threshold;
        tempECMCCFG.B.SELC1 = ecmConfig->eventCounter[1].input;
        tempECMCCFG.B.THRC1 = ecmConfig->eventCounter[1].threshold;
        tempECMCCFG.B.SELC2 = ecmConfig->eventCounter[2].input;
        tempECMCCFG.B.THRC2 = ecmConfig->eventCounter[2].threshold;
        tempECMCCFG.B.SELC3 = ecmConfig->eventCounter[3].input;
        tempECMCCFG.B.THRC3 = ecmConfig->eventCounter[3].threshold;
        iomSFR->ECMCCFG.U   = tempECMCCFG.U;
    }

    {
        iomSFR->ECMSELR.U = ecmConfig->globalEventSelection.U;
    }
    return status;
}


void IfxIom_Iom_initCombinerConfig(IfxIom_Iom_EcmConfig *ecmConfig)
{
	/* Initializes Event Combiner Module with default values */

    uint8 counterId;

    ecmConfig->globalEventSelection.U = 0;

    for (counterId = 0; counterId <= 3; counterId++)
    {
        ecmConfig->eventCounter[counterId].input     = IfxIom_EventCounterChannel_0;
        ecmConfig->eventCounter[counterId].threshold = IfxIom_EventCounterThreshold_disable;
    }
}


boolean IfxIom_Iom_initFpcChannel(IfxIom_Iom *iom, const IfxIom_Iom_FpcConfig *fpcConfig)
{
    boolean  status = TRUE;

    Ifx_IOM *iomSFR = iom->iom;
    uint8    exorInput;

    {
    	/* Get the FPC channel ID from the configuration */
        uint8          channelId = (IfxIom_FpcChannelId)fpcConfig->channelId;

        Ifx_IOM_FPCCTR tempFPCCTR;
        tempFPCCTR.U                = 0;
        tempFPCCTR.B.CMP            = fpcConfig->comparatorThreshold;
        tempFPCCTR.B.MOD            = fpcConfig->filterMode;
        tempFPCCTR.B.ISM            = fpcConfig->monitorSignal;
        tempFPCCTR.B.RTG            = fpcConfig->timerReset;
        tempFPCCTR.B.ISR            = fpcConfig->referenceSignal;

        iomSFR->FPCCTR[channelId].U = tempFPCCTR.U;
    }

    {
        Ifx_IOM_GTMEXR tempGTMEXR;
        tempGTMEXR.U = 0;

        for (exorInput = 0; exorInput <= 7; exorInput++)
        {
            if (fpcConfig->exorInputEnable[exorInput])
            {
                tempGTMEXR.U |= (1 << exorInput);
            }
            else
            {
                tempGTMEXR.U &= ~(1 << exorInput);
            }
        }

        iomSFR->GTMEXR.U = tempGTMEXR.U;
    }
    return status;
}


void IfxIom_Iom_initFpcChannelConfig(IfxIom_Iom_FpcConfig *fpcConfig)
{
    uint8 exorInput;
    /* Initialize the default value of Filter & Prescaler Cell channel */
    fpcConfig->channelId           = IfxIom_FpcChannelId_0;
    /* Initialize the default value of Filter & Prescaler Cell mode */
    fpcConfig->filterMode          = IfxIom_FilterMode_delayedDebounce;
    /* Initialize the default value of reference signal input for Filter & Prescaler cell */
    fpcConfig->referenceSignal     = IfxIom_ReferenceSignal_portLogic;
    /* Initialize the default value of monitor signal input for Filter & Prescaler cell */
    fpcConfig->monitorSignal       = IfxIom_MonitorSignal_portLogic;
    /* Initialize the default threshold value */
    fpcConfig->comparatorThreshold = 15;
    /* Initialize the default value for timer reset bit */
    fpcConfig->timerReset          = TRUE;
    /* Initialize the default edge type */
    fpcConfig->edgeType            = IfxIom_EdgeClearType_risingFalling;

    for (exorInput = 0; exorInput <= 7; exorInput++)
    {
        fpcConfig->exorInputEnable[exorInput] = FALSE;
    }
}


boolean IfxIom_Iom_initModule(IfxIom_Iom *iom)
{
    boolean  status = TRUE;

    Ifx_IOM *iomSFR = iom->iom;
    {
        Ifx_IOM_CLC tempCLC;
        tempCLC.U      = 0;
        tempCLC.B.EDIS = 0;
        tempCLC.B.RMC  = 1;
        uint16      passwd = IfxScuWdt_getCpuWatchdogPassword();
        /* Clearing the endinit protection */
        IfxScuWdt_clearCpuEndinit(passwd);
        /* Enable the IOM module */
        iomSFR->CLC.U = tempCLC.U;
        IfxIom_enableModule(iomSFR, 1);
        /* Setting the endinit protection back on */
        IfxScuWdt_setCpuEndinit(passwd);
    }

    return status;
}


void IfxIom_Iom_initModuleConfig(IfxIom_Iom *iom, Ifx_IOM *module)
{
    iom->iom = module;
}
#endif

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
