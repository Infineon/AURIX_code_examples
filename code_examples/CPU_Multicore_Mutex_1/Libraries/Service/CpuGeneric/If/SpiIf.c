/**
 * \file SpiIf.c
 * \brief SPI interface
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:21 GMT$
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

#include "SpiIf.h"

void SpiIf_initConfig(SpiIf_Config *config)
{
    config->mode            = SpiIf_Mode_master;
    config->rxPriority      = 0;
    config->txPriority      = 0;
    config->erPriority      = 0;
    config->isrProvider     = IfxSrc_Tos_cpu0;
    config->bufferSize      = 0;
    config->buffer          = NULL_PTR;
    config->maximumBaudrate = 0;
}


void SpiIf_initChannelConfig(SpiIf_ChConfig *config, SpiIf *driver)
{
    config->driver               = driver;
    config->baudrate             = 0;
    config->mode.enabled         = 1;
    config->mode.autoCS          = 1;
    config->mode.loopback        = 0;
    config->mode.clockPolarity   = SpiIf_ClockPolarity_idleLow;
    config->mode.shiftClock      = SpiIf_ShiftClock_shiftTransmitDataOnLeadingEdge;
    config->mode.dataHeading     = SpiIf_DataHeading_msbFirst;
    config->mode.dataWidth       = 8;
    config->mode.csActiveLevel   = Ifx_ActiveState_low;
    config->mode.csLeadDelay     = SpiIf_SlsoTiming_0;
    config->mode.csTrailDelay    = SpiIf_SlsoTiming_0;
    config->mode.csInactiveDelay = SpiIf_SlsoTiming_0;
    config->mode.parityCheck     = 0;
    config->mode.parityMode      = Ifx_ParityMode_even;
    config->errorChecks.baudrate = 0;
    config->errorChecks.phase    = 0;
    config->errorChecks.receive  = 0;
    config->errorChecks.transmit = 0;
}
