/**
 * \file IfxDts_Dts.c
 * \brief DTS DTS details
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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

#include "IfxDts_Dts.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint16 IfxDts_Dts_convertFromCelsius(float32 temperatureValue)
{
    sint32 dtsValue = (sint32)(temperatureValue + 285.5) / 0.467;

    if (dtsValue < 0)
    {
        dtsValue = 0;
    }
    else if (dtsValue > 1023)
    {
        dtsValue = 1023;
    }

    return (uint16)dtsValue;
}


float32 IfxDts_Dts_convertToCelsius(uint16 dtsValue)
{
    return ((float32)dtsValue * 0.467) - 285.5;
}


void IfxDts_Dts_initModule(const IfxDts_Dts_Config *config)
{
    IfxDts_enableSensor();

    /* wait for two measurements before enabling the limits */
    {
        int i;

        /* disable limits */
        MODULE_SCU.DTSLIM.B.LOWER = 0;
        MODULE_SCU.DTSLIM.B.UPPER = 1023;

        /* wait until DTS is ready */
        while (!IfxDts_isReady())
        {}

        /* two dummy measurements */
        for (i = 0; i < 2; ++i)
        {
            IfxDts_Dts_startSensor();

            while (IfxDts_Dts_isBusy())
            {}
        }
    }

    /* change to the requested limits */
    MODULE_SCU.DTSLIM.B.LOWER = IfxDts_Dts_convertFromCelsius(config->lowerTemperatureLimit);
    MODULE_SCU.DTSLIM.B.UPPER = IfxDts_Dts_convertFromCelsius(config->upperTemperatureLimit);

    /* lock configuration? */
    if (config->enableSecureLock == TRUE)
    {
        IfxDts_disableSensorControl();
    }
    else
    {
        /* do Nothing */
    }

    /* enable DTS IRQ */
    if (config->isrPriority > 0)
    {
        volatile Ifx_SRC_SRCR *src = IfxDts_getSrcPointer();
        IfxSrc_init(src, config->isrTypeOfService, config->isrPriority);
        IfxSrc_enable(src);
    }
}


void IfxDts_Dts_initModuleConfig(IfxDts_Dts_Config *config)
{
    config->sensorControlDisabled = FALSE;
    config->lowerTemperatureLimit = -40.0; // Celsius
    config->upperTemperatureLimit = 170.0; // Celsius

    config->isrTypeOfService      = IfxSrc_Tos_cpu0;
    config->isrPriority           = 0;

    config->enableSecureLock      = FALSE;
}
