/**
 * \file IfxDts_Dts.c
 * \brief DTS DTS details
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

#include "IfxDts_Dts.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

uint16 IfxDts_Dts_convertFromCelsius(float32 temperatureValue)
{
    sint32 dtsValue = (sint32)(7.505f * (temperatureValue + 273.15f));

    if (dtsValue < 0)
    {
        dtsValue = 0;
    }
    else if (dtsValue > 4095)
    {
        dtsValue = 4095;
    }

    return (uint16)dtsValue;
}


float32 IfxDts_Dts_convertToCelsius(uint16 dtsValue)
{
    return (float32)((dtsValue / 7.505f) - 273.15f);
}


void IfxDts_Dts_initModule(const IfxDts_Dts_Config *config)
{
	/* Wait for two measurements before enabling the limits */
    MODULE_PMS.DTSLIM.B.LOWER = 0;
    MODULE_PMS.DTSLIM.B.UPPER = 4095;

    /* change to the requested limits */
    MODULE_PMS.DTSLIM.B.LOWER = IfxDts_Dts_convertFromCelsius(config->lowerTemperatureLimit);
    MODULE_PMS.DTSLIM.B.UPPER = IfxDts_Dts_convertFromCelsius(config->upperTemperatureLimit);

    /* Enable DTS IRQ */
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
    config->lowerTemperatureLimit = IFXDTS_DEFAULT_TEMPERATURELIMIT_LOW;   /* Celsius */
    config->upperTemperatureLimit = IFXDTS_DEFAULT_TEMPERATURELIMIT_UPPER; /* Celsius */

    config->isrTypeOfService      = IfxSrc_Tos_cpu0;
    config->isrPriority           = 0;
}
