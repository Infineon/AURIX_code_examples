/**********************************************************************************************************************
 * \file ADC_Queued_Scan.c
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
#include "IfxVadc_Adc.h"
#include "ADC_Queued_Scan.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define GROUPID_4           IfxVadc_GroupId_4                   /* VADC group 4                                     */
#define CHANNELS_NUM        3                                   /* Number of used channels                          */
#define CHANNELS_PER_GROUP  8                                   /* Maximum number of channels per group             */
#define AN37_CHID           5              /* Channel ID for pin AN37, used also as index in the g_adcChannel array */
#define AN38_CHID           6              /* Channel ID for pin AN38, used also as index in the g_adcChannel array */
#define AN39_CHID           7              /* Channel ID for pin AN39, used also as index in the g_adcChannel array */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* VADC handle */
IfxVadc_Adc g_vadc;                                             /* VADC module handle                               */
IfxVadc_Adc_Group g_adcGroup;                                   /* VADC group handle                                */
IfxVadc_Adc_Channel g_adcChannel[CHANNELS_PER_GROUP];           /* VADC channels handle                             */

uint8 g_grpChannelsId[] = {AN37_CHID, AN38_CHID, AN39_CHID};    /* AN37, AN38, AN39                                 */

Ifx_VADC_RES g_results[CHANNELS_NUM];                           /* Array containing the conversion results          */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initVADCModule(void);                                      /* Function to initialize the VADC module           */
void initVADCGroup(void);                                       /* Function to initialize the VADC group            */
void initVADCChannels(void);                                    /* Function to initialize the VADC channels         */
void fillQueue(void);                                           /* Function to fill the queue                       */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Function to initialize the VADC */
void initVADC()
{
    initVADCModule();                                           /* Initialize the VADC module                       */
    initVADCGroup();                                            /* Initialize the VADC group                        */
    initVADCChannels();                                         /* Initialize the channels                          */
    fillQueue();                                                /* Fill the VADC queue                              */

    IfxVadc_Adc_startQueue(&g_adcGroup);                        /* Start the conversion                             */
}

/* Function to initialize the VADC module with default parameters */
void initVADCModule()
{
    /* Create configuration */
    IfxVadc_Adc_Config adcConfig;
    IfxVadc_Adc_initModuleConfig(&adcConfig, &MODULE_VADC);

    /* Initialize module */
    IfxVadc_Adc_initModule(&g_vadc, &adcConfig);
}

/* Function to initialize the VADC group */
void initVADCGroup()
{
    /* Create and initialize group configuration with default values */
    IfxVadc_Adc_GroupConfig adcGroupConfig;
    IfxVadc_Adc_initGroupConfig(&adcGroupConfig, &g_vadc);

    /* Setting user configuration using group 4 */
    adcGroupConfig.groupId = GROUPID_4;
    adcGroupConfig.master = GROUPID_4;

    /* Enable queued source */
    adcGroupConfig.arbiter.requestSlotQueueEnabled = TRUE;

    /* Enable all gates in "always" mode (no edge detection) */
    adcGroupConfig.queueRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always;

    /* Initialize the group */
    IfxVadc_Adc_initGroup(&g_adcGroup, &adcGroupConfig);
}

/* Function to initialize the VADC channels */
void initVADCChannels()
{
    /* Create channel configuration */
    IfxVadc_Adc_ChannelConfig adcChannelConfig;

    for(uint16 chId = 0; chId < CHANNELS_NUM; ++chId)
    {
        /* Initialize the channel configuration with default values */
        IfxVadc_Adc_initChannelConfig(&adcChannelConfig, &g_adcGroup);

        /* Set the channel ID and the corresponding result register */
        adcChannelConfig.channelId = (IfxVadc_ChannelId)(g_grpChannelsId[chId]);
        adcChannelConfig.resultRegister = (IfxVadc_ChannelResult)(g_grpChannelsId[chId]);

        /* Initialize the channel */
        IfxVadc_Adc_initChannel(&g_adcChannel[g_grpChannelsId[chId]], &adcChannelConfig);
    }
}

/* Function to fill the VADC queue */
void fillQueue()
{
    for(uint16 chId = 0; chId < CHANNELS_NUM; ++chId)
    {
        /* Add channel to queue with refill enabled */
        IfxVadc_Adc_addToQueue(&g_adcChannel[g_grpChannelsId[chId]], IFXVADC_QUEUE_REFILL);
    }
}

/* Function to update the VADC result values */
void readVADC()
{
    for(uint8 chId = 0; chId < CHANNELS_NUM; chId++)
    {
        /* Wait for a valid result */
        Ifx_VADC_RES conversionResult;
        do
        {
            conversionResult = IfxVadc_Adc_getResult(&g_adcChannel[g_grpChannelsId[chId]]);
        } while(!conversionResult.B.VF);

        /* Store the result */
        g_results[chId] = conversionResult;
    }
}
