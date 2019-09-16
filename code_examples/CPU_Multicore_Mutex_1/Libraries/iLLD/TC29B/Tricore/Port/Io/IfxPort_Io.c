/**
 * \file IfxPort_Io.c
 * \brief PORT IO details
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

#include "IfxPort_Io.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPort_Io_initModule(const IfxPort_Io_Config *config)
{
    IfxPort_Io_ConfigPin *pinTable = (IfxPort_Io_ConfigPin *)&config->pinTable[0];

    uint32                i;

    for (i = 0; i < config->size; i++, ++pinTable)
    {
        IfxPort_Pin *pin = (IfxPort_Pin *)pinTable->pin;
        IfxPort_setPinMode(pin->port, pin->pinIndex, pinTable->mode);
        IfxPort_setPinPadDriver(pin->port, pin->pinIndex, pinTable->padDriver);
    }
}
