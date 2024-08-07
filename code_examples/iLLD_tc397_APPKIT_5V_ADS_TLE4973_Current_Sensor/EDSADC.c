/**********************************************************************************************************************
 * \file EDSADC.c
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
#include "Ifx_Types.h"
#include "IfxEdsadc_Edsadc.h"
#include "UART_Config.h"
#include "Main_Config.h"
#include "EDSADC.h"
#include <math.h>

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define DECIMATION_FACTOR   256                     /* Configure the CIC decimation factor (N)                      */
#define START_VALUE         0                       /* Configure start value of the decimation counter              */
#define CIC_SHIFT           24                      /* CIC shift calculated using the selected decimation factor    */
#define GAIN_FACTOR         5399                    /* Gain factor calculated using the CIC shift                   */

#define ANALOG_FULL_SCALE   5.00                    /* Analog full-scale voltage                                    */
#define RAW_FULL_SCALE      30000.0                 /* EDSADC full-scale value (AFS), representing the analog
                                                     * full-scale (V_IN = V_AREF = 5V)                              */

#define MODULATOR_FREQ      40.0e6                  /* Modulator frequency in Hz                                    */
#define MODULATOR_MASK      0xF                     /* Configuration mask to enable modulator 0 only                */
#define CHANNEL_MASK        0xF                     /* Configuration mask to enable channel 0 only                  */

#define CAL_DECIMATION_FACTOR   6                   /* Configure the CIC decimation factor (N) for calibration      */
#define CAL_CIC_SHIFT           27                  /* CIC shift for the selected calibration decimation factor     */
#define CAL_GAIN_FACTOR         5399                /* Gain factor calculated using the CIC shift                   */

#define AN2_CH0             0                       /* Conversion channel                                           */
#define AN20_CH2            2
#define AN0_CH3             3

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* EDSADC handler data structure and channel handler structure */
IfxEdsadc_Edsadc g_edsadc;
IfxEdsadc_Edsadc_Channel g_edsadcChannel[CHANNELS_NUM];

/* Variables to store the result */
sint16 g_resultEDSADC = 0;                                                    /* Variable to store the EDSADC raw value                       */
float32 g_resultVoltage[CHANNELS_NUM] = {0.0, 0.0, 0.0};                      /* Variable to store the calculated voltage value               */
uint8 g_channel[CHANNELS_NUM] = {AN2_CH0, AN20_CH2, AN0_CH3};
uint8 g_voltageAddr[CHANNELS_NUM];
uint8 g_seedAdd = 8;
uint8 g_autoAddState = 0;
float g_res[CHANNELS_NUM];

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

/* This function performs calibration of the EDSADC channels*/
static boolean calib_EDSADC_chan(uint8 chan_num)
{
    /* Set Target Value for Calibrated Fullscale */
    MODULE_EDSADC.CH[chan_num].GAINCAL.B.CALTARGET = RAW_FULL_SCALE;
    /* Reset  Multiplication Factor for Gain Calibration */
    MODULE_EDSADC.CH[chan_num].GAINCAL.B.CALFACTOR = 0;


    /* Reset Offset compensation value */
    MODULE_EDSADC.CH[chan_num].OFFCOMP.B.OFFSET = 0;


    /* Set Decimation Rate of the CIC Filter During, Factor = 2 ^ (CICDEC + 3) */
    MODULE_EDSADC.CH[chan_num].GAINCTR.B.CICDEC        = CAL_DECIMATION_FACTOR;
    /* Set Position of the CIC Filter Output Shifter During Calibration */
    MODULE_EDSADC.CH[chan_num].GAINCTR.B.CICSHIFT      = CAL_CIC_SHIFT;
    /* Set Multiplication Factor for Gain Correction During Calibration */
    MODULE_EDSADC.CH[chan_num].GAINCTR.B.GAINFACTOR    = CAL_GAIN_FACTOR;

    MODULE_EDSADC.CH[chan_num].FCFGM.U |= ( 0x1 << 28 ) | ( 1 << 31 );
    return TRUE;
}

/* In this function, the EDSADC module is initialized */
void initEDSADC(OPMode OPM)
{
    /* ============================================================================================================
     *                                          EDSADC module configuration
     * ============================================================================================================
     */
    IfxEdsadc_Edsadc_Config edsadcConfig;                                   /* Module configuration structure       */
    /* Initialize the configuration with default values */
    IfxEdsadc_Edsadc_initModuleConfig(&edsadcConfig, &MODULE_EDSADC);

    /* Generate the modulator clock independently of the phase synchronizer signal */
    edsadcConfig.modulatorClockMode = IfxEdsadc_ModulatorClockGeneration_unsyncMode;

    /* Initialize the EDSADC module */
    IfxEdsadc_Edsadc_initModule(&g_edsadc, &edsadcConfig);


    /* ============================================================================================================
     *                                             Channel configuration
     * ============================================================================================================
     */
    for(int i = 0; i<CHANNELS_NUM; i++)
    {
        IfxEdsadc_Edsadc_ChannelConfig edsadcChannelConfig;                     /* Channel configuration structure      */
        /* Initialize the configuration with default values */
        IfxEdsadc_Edsadc_initChannelConfig(&edsadcChannelConfig, &g_edsadc);

        /* Configure the comb filter */
        edsadcChannelConfig.combFilter.decimationFactor = DECIMATION_FACTOR;    /* Set the decimation factor            */
        edsadcChannelConfig.combFilter.startValue = START_VALUE;    /* Set the starting value of the decimation counter */


        /* Configure the FIR filters in the filter chain */
        edsadcChannelConfig.firFilter.prefilterEnabled = TRUE;      /* Enable the Pre-Filter in the filter chain        */
        edsadcChannelConfig.firFilter.fir0Enabled = TRUE;           /* Enable the FIR0 Filter in the filter chain       */
        edsadcChannelConfig.firFilter.fir1Enabled = TRUE;           /* Enable the FIR1 Filter in the filter chain       */
        edsadcChannelConfig.firFilter.calibrationTrigger = FALSE;    /* Start the calibration initializing the channel   */

        /* Configure the modulator */
        edsadcChannelConfig.modulator.modulatorClockFreq = MODULATOR_FREQ;      /* Set the modulator frequency          */
        /* Set input mode   */
        if(OPM <= FullyDifferential)
        {
            edsadcChannelConfig.modulator.negativeInput = IfxEdsadc_InputConfig_inputPin;
        }
        else
        {
            edsadcChannelConfig.modulator.negativeInput = IfxEdsadc_InputConfig_referenceGround;
        }
        edsadcChannelConfig.modulator.inputGain = IfxEdsadc_InputGain_factor1;

        edsadcChannelConfig.channelId = (IfxEdsadc_ChannelId)g_channel[i];          /* Select the channel to configure      */
        edsadcChannelConfig.cicShift = CIC_SHIFT;                                   /* Set the CIC shift                    */
        edsadcChannelConfig.gainFactor = GAIN_FACTOR;                               /* Set the gain factor                  */

        /* Set the intended full-scale value */
        edsadcChannelConfig.gainCalibrationConfig.calTarget = RAW_FULL_SCALE;

        IfxEdsadc_Edsadc_initChannel(&g_edsadcChannel[i], &edsadcChannelConfig);    /* Initialize the channel               */
        IfxEdsadc_Edsadc_startScan(&g_edsadc, MODULATOR_MASK, CHANNEL_MASK);        /* Start scan with modulator 0, channel 0   */

        calib_EDSADC_chan(g_channel[i]);
    }
}

/* This function gets the result of the most recent conversion */
void runEDSADC(void)
{
    for(int i = 0; i < CHANNELS_NUM; i++)
    {
        g_resultEDSADC = IfxEdsadc_Edsadc_getMainResult(&g_edsadcChannel[i]);       /* Get the ESDADC raw value             */
        g_resultVoltage[i] = (g_resultEDSADC * ANALOG_FULL_SCALE) / RAW_FULL_SCALE; /* Calculate the corresponding voltage  */
    }
    g_res[0] = (g_resultVoltage[0]*1000);
    g_res[1] = (g_resultVoltage[1]*1000);
    g_res[2] = (g_resultVoltage[2]*1000);
}

/* This function returns the conversion result of a specific channel */
float readEDSACVoltage(uint16 indice)
{
   float res = g_res[indice];       /* the board offset and gain can be manually changed or can be change with calibADCOffSet function */
   return res;
}
