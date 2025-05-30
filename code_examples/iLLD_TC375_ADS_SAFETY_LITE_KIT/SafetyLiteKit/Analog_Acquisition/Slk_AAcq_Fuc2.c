/**********************************************************************************************************************
 * \file Slk_AAcq_Fuc2.c
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


/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyLiteKit/Analog_Acquisition/Slk_AA_Global.h"
#include "SafetyLiteKit/Analog_Acquisition/Slk_AAcq_Fuc2.h"
#include "SafetyLiteKit/Slk_Cfg.h"
#include "SafetyLiteKit/Smu/SMU.h"
#include "IfxCpu_Irq.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* Macros for EVADC group and channel configuration */
#define EVADC_INPUT1_CH_ID_AA_FUC2     0 /* Array Id */
#define EVADC_VAREF_CH_ID_AA_FUC2   1 /* Array Id */

#define EVADC_INPUT1_G_ID_AA_FUC2      0 /* Array Id */
#define EVADC_VAREF_G_ID_AA_FUC2    1 /* Array Id */

/* Macros for EDSADC group and channel configuration */
#define EDSADC_INPUT2_CH_ID_AA_FUC2    0 /* Array Id */
#define EDSADC_VAREF_CH_ID_AA_FUC2  1 /* Array Id */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN AnalogAcquisitionStatusDatatype g_analogAcquisitionStatus;
SlkEvadcCfgType   g_slkEvadcCfgAAcqFuc2;
SlkEdsadcCfgType  g_slkEdsadcCfgAAcqFuc2;

/* EVADC handles */
IfxEvadc_Adc_Group      g_evadcGroupAAcqFuc2[EVADC_GROUPS_NUM_AA_FUC2]; /* Configuring the EVADC groups          */
IfxEvadc_Adc_Channel    g_evadcChannelAAcqFuc2[EVADC_CHANNELS_NUM_AA_FUC2]; /* Configuring the EVADC channels    */

/* EVADC group and channel configuration, align with macros */
SlkEvadcChannelCfgType g_evadcChannelConfigAAcqFuc2[EVADC_CHANNELS_NUM_AA_FUC2] = {
    { &INPUT1_EVADC_PIN, &g_evadcGroupAAcqFuc2[EVADC_INPUT1_G_ID_AA_FUC2], IfxEvadc_ChannelResult_0,
        IfxEvadc_InputClasses_global1, IfxEvadc_RequestSource_queue0, TRUE, IfxEvadc_SrcNr_group2,
        IfxSrc_Tos_cpu1, ISR_PRIORITY_EVADC_INPUT1_AA_FUC2},
    { &VAREF_EVADC_PIN, &g_evadcGroupAAcqFuc2[EVADC_VAREF_G_ID_AA_FUC2], IfxEvadc_ChannelResult_0,
        IfxEvadc_InputClasses_group0, IfxEvadc_RequestSource_queue0, FALSE, 0, 0, 255}
};

/* EDSADC handles */
IfxEdsadc_Edsadc_Channel g_edsadcChannel_AA_FUC2[EDSADC_CHANNELS_NUM_AA_FUC2];

/* EDSADC group and channel configuration, align with macros */
/* Example for using only positive input of CH2: */
SlkEdsadcChannelCfgType g_edsadcChannelConfig_AA_FUC2[EDSADC_CHANNELS_NUM_AA_FUC2] = {
    { &INPUT2_EDSADC_CH5P_PIN,   NULL_PTR },
    { &VAREF_EDSADC_CH1P_PIN,     NULL_PTR }
};

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void runEvadcMeasurementAAcqFuc2(SlkEvadcCfgType *evadcCfg);
void runEdsadcMeasurementAAcqFuc2(SlkEdsadcCfgType *edsadcCfg);
void startupCalibrationAAcqFuc2(SlkEvadcCfgType *evadcCfg, SlkEdsadcCfgType *edsadcCfg);
void plausibilityCheckAAcqFuc2(void);

IFX_INTERRUPT(isrEvadcInput1ChAAcqFuc2, CPU1_RUNNING_TASK, ISR_PRIORITY_EVADC_INPUT1_AA_FUC2);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* ISR for Input1 EVADC */
void isrEvadcInput1ChAAcqFuc2(void)
{
    IfxCpu_enableInterrupts();

    /* Get the EVADC conversion result */
    g_analogAcquisitionStatus.evadcConversionResult[EVADC_INPUT1_CH_ID_AA_FUC2] = getEvadcChannelResult(
            &g_slkEvadcCfgAAcqFuc2.evadcChannel[EVADC_INPUT1_CH_ID_AA_FUC2]);

    /* Calculate the corresponding voltage */
    g_analogAcquisitionStatus.evadcVoltageResults[EVADC_INPUT1_CH_ID_AA_FUC2] = EVADC_RESULT_TO_V(
            g_analogAcquisitionStatus.evadcConversionResult[EVADC_INPUT1_CH_ID_AA_FUC2]);

    /* Deduct calibration offset */
    g_analogAcquisitionStatus.evadcVoltageResults[EVADC_INPUT1_CH_ID_AA_FUC2] -=
            g_analogAcquisitionStatus.evadcInput1Calibration;

    /* Set measurement done flag */
    g_analogAcquisitionStatus.evadcInput1MeasDoneFlag = TRUE;
}

/*
 * Function to add each channel to the queue and start it
 * */
void runEvadcMeasurementAAcqFuc2(SlkEvadcCfgType *evadcCfg)
{
    /* Add channel to queue with refill option DISABLED */
    IfxEvadc_Adc_addToQueue(&evadcCfg->evadcChannel[EVADC_INPUT1_CH_ID_AA_FUC2],
            evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].queueRequestSourceId,
            IFXEVADC_QUEUE_REFILL_DISABLED);

    /* Start the queue */
    IfxEvadc_Adc_startQueue(evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].groupHandle,
            evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].queueRequestSourceId);
}

/*
 * Function to add each channel to the queue and start it
 * */
void runEdsadcMeasurementAAcqFuc2(SlkEdsadcCfgType *edsadcCfg)
{
    /* Get the ESDADC raw value */
    g_analogAcquisitionStatus.edsadcConversionResult[EDSADC_INPUT2_CH_ID_AA_FUC2] = IfxEdsadc_Edsadc_getMainResult(
            &edsadcCfg->edsadcChannel[EDSADC_INPUT2_CH_ID_AA_FUC2]);

    /* Check if only the negative channel is used */
    if((edsadcCfg->edsadcChannelConfig[EDSADC_INPUT2_CH_ID_AA_FUC2].posInput == NULL_PTR)  &&
       (edsadcCfg->edsadcChannelConfig[EDSADC_INPUT2_CH_ID_AA_FUC2].negInput != NULL_PTR))
    {
        /* If yes multiply conversion result by -1 */
        g_analogAcquisitionStatus.edsadcConversionResult[EDSADC_INPUT2_CH_ID_AA_FUC2] *= -1;
    }

    /* Calculate the corresponding voltage */
    g_analogAcquisitionStatus.edsadcVoltageResults[EDSADC_INPUT2_CH_ID_AA_FUC2] = EDSADC_RESULT_TO_V(
            g_analogAcquisitionStatus.edsadcConversionResult[EDSADC_INPUT2_CH_ID_AA_FUC2]);

    /* Deduct calibration offset */
    g_analogAcquisitionStatus.edsadcVoltageResults[EDSADC_INPUT2_CH_ID_AA_FUC2] -=
            g_analogAcquisitionStatus.edsadcInput2Calibration;
}

/*
 * Plausibility check of Analog Acquisition Function use case 2
 * */
void plausibilityCheckAAcqFuc2(void)
{
    /* Ignore first three measurements as measurement might return 0 at the beginning (self-calibration) */
    if (g_analogAcquisitionStatus.initCnt < 3)
    {
        g_analogAcquisitionStatus.initCnt++;
    }
    else
    {
        /* Continue only if EVADC measurements is done */
        static uint8 notDoneCnt;
        if (!g_analogAcquisitionStatus.evadcInput1MeasDoneFlag)
        {
            /* Increase static not done counter */
            notDoneCnt++;
            /* If notDoneCnt is not reset frequently it means that one of the two EVADCs is not successfully
             * measured anymore */
            if (notDoneCnt > 10)
            {
                /* Trigger SMU software alarm */
                softwareCoreAlarmTriggerSMU(SOFT_SMU_ALM_ADC);

                /* Reset static notDoneCnt counter */
                notDoneCnt = 0;
            }
        }
        else
        {
            /* Reset static notDoneCnt counter */
            notDoneCnt = 0;

            /* Comparison of EVADC mission and EDSADC monitor channels values */
            plausibilityCheck(g_analogAcquisitionStatus.evadcVoltageResults[EVADC_INPUT1_CH_ID_AA_FUC2],
                    g_analogAcquisitionStatus.edsadcVoltageResults[EDSADC_INPUT2_CH_ID_AA_FUC2],
                    MAX_DIFF, UPPER_LIMIT, LOWER_LIMIT, SOFT_SMU_ALM_ADC);

            /* Reset measurement done flags */
            g_analogAcquisitionStatus.evadcInput1MeasDoneFlag = FALSE;
        }
    }
}

/*
 * Execute Analog Acquisition Function Use Case 2
 * */
void runAAcqFuc2(void)
{
    runEvadcMeasurementAAcqFuc2(&g_slkEvadcCfgAAcqFuc2);    /* Run EVADC measurement and get results */
    runEdsadcMeasurementAAcqFuc2(&g_slkEdsadcCfgAAcqFuc2);  /* Run EDSADC measurement and get results */

    plausibilityCheckAAcqFuc2();
}

/*
 * As there might be a slight difference between both Input, this function executes
 * CALIBRATION_SAMPLE_AMOUNT measurements at the beginning to determine the offset.
 * */
void startupCalibrationAAcqFuc2(SlkEvadcCfgType *evadcCfg, SlkEdsadcCfgType *edsadcCfg)
{
    /* Disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();
    sint8 multiplerRv2 = 1;
    /* Add channel to queue with refill option enabled */
    IfxEvadc_Adc_addToQueue(&evadcCfg->evadcChannel[EVADC_INPUT1_CH_ID_AA_FUC2],
            evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].queueRequestSourceId, IFXEVADC_QUEUE_REFILL);

    /* Start the queue */
    IfxEvadc_Adc_startQueue(evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].groupHandle,
            evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].queueRequestSourceId);


    /* Check if only the negative channel of EDSADC is used */
    if((edsadcCfg->edsadcChannelConfig[EDSADC_INPUT2_CH_ID_AA_FUC2].posInput == NULL_PTR)  &&
       (edsadcCfg->edsadcChannelConfig[EDSADC_INPUT2_CH_ID_AA_FUC2].negInput != NULL_PTR))
    {
        multiplerRv2 *= -1;
    }

    /* Accumulate CALIBRATION_SAMPLE_AMOUNT adc samples */
    float32 accumulationResult[2] = {0, 0};
    for(uint8 sampleCnt = 0; sampleCnt < CALIBRATION_SAMPLE_AMOUNT; sampleCnt++)
    {
        /* Get the EVADC raw value */
        accumulationResult[0] += EVADC_RESULT_TO_V(
                getEvadcChannelResult(&evadcCfg->evadcChannel[EVADC_INPUT1_CH_ID_AA_FUC2]));
        /* Get the ESDADC raw value i.e Negative channel value multiple by -1 */
        accumulationResult[1] += EDSADC_RESULT_TO_V(multiplerRv2 *
                IfxEdsadc_Edsadc_getMainResult(&edsadcCfg->edsadcChannel[EDSADC_INPUT2_CH_ID_AA_FUC2]));
    }

    /* Stop and flush the queue */
    IfxEvadc_Adc_clearQueue(evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].groupHandle,
            evadcCfg->evadcChannelConfig[EVADC_INPUT1_CH_ID_AA_FUC2].queueRequestSourceId);

    /* Get the calibration offset */
    float32 calibrationOffset[2] = {0};
    getCalibrationOffset(accumulationResult, CALIBRATION_SAMPLE_AMOUNT, calibrationOffset);

    /* Save calibration values to global structure */
    g_analogAcquisitionStatus.evadcInput1Calibration = calibrationOffset[0];
    g_analogAcquisitionStatus.edsadcInput2Calibration = calibrationOffset[1];

    /* Enable interrupts again*/
    IfxCpu_restoreInterrupts(interruptState);
}

/*
 * Initial Analog Acquisition Function Use Case 2
 * */
void initAAcqFuc2(void)
{
    /* Reset status */
    resetAnalogAcqStatus();

    g_slkEvadcCfgAAcqFuc2.amountOfGroups        = EVADC_GROUPS_NUM_AA_FUC2;
    g_slkEvadcCfgAAcqFuc2.amountOfChannels      = EVADC_CHANNELS_NUM_AA_FUC2;
    g_slkEvadcCfgAAcqFuc2.evadcGroup            = g_evadcGroupAAcqFuc2;
    g_slkEvadcCfgAAcqFuc2.evadcChannel          = g_evadcChannelAAcqFuc2;
    g_slkEvadcCfgAAcqFuc2.evadcChannelConfig    = g_evadcChannelConfigAAcqFuc2;

    g_slkEdsadcCfgAAcqFuc2.amountOfChannels     = EDSADC_CHANNELS_NUM_AA_FUC2;
    g_slkEdsadcCfgAAcqFuc2.edsadcChannel        = g_edsadcChannel_AA_FUC2;
    g_slkEdsadcCfgAAcqFuc2.edsadcChannelConfig  = g_edsadcChannelConfig_AA_FUC2;

    initCONVCTRL();                                     /* Initialize and verify the CONVTRL module */
    initEVADCModule(&g_slkEvadcCfgAAcqFuc2);      /* Initialize the EVADC module */
    initEVADCGroups(&g_slkEvadcCfgAAcqFuc2, EVADC_VAREF_G_ID_AA_FUC2);      /* Initialize the EVADC group */
    initEVADCChannels(&g_slkEvadcCfgAAcqFuc2);    /* Initialize the EVADC channels */

    initEDSADCModule(&g_slkEdsadcCfgAAcqFuc2);    /* Initialize the EDSADC module */
    initEDSADCChannels(&g_slkEdsadcCfgAAcqFuc2);  /* Initialize the EDSADC channels */

    /* Run VAREF plausibility check once per driving cycle, better would be cyclically after a predefined time
     * or number of conversions. */
    g_analogAcquisitionStatus.evadcVoltageResults[EVADC_VAREF_CH_ID_AA_FUC2] = evadcVarefPlausibilityCheck(
            &g_slkEvadcCfgAAcqFuc2, EVADC_VAREF_CH_ID_AA_FUC2,
            g_slkEvadcCfgAAcqFuc2.evadcChannelConfig[EVADC_VAREF_CH_ID_AA_FUC2].queueRequestSourceId);

    /* Run VAREF plausibility check once per driving cycle, better would be cyclically after a predefined time
     * or number of conversions. */
    g_analogAcquisitionStatus.edsadcVoltageResults[EDSADC_VAREF_CH_ID_AA_FUC2] = edsadcVarefPlausibilityCheck(
            &g_slkEdsadcCfgAAcqFuc2, EDSADC_VAREF_CH_ID_AA_FUC2, VAREF_EXPECTED_RESULT, VAREF_TOLERANCE);

    startupCalibrationAAcqFuc2(&g_slkEvadcCfgAAcqFuc2, &g_slkEdsadcCfgAAcqFuc2);
}
