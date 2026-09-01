/**
 * \file IfxPort_Io.c
 * \brief PORT IO details
 *
 * \version iLLD-TC4-v2.6.0
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
