/**
 * \file SpiIf.c
 * \brief SPI interface
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
    config->vmId            = IfxSrc_VmId_0;
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
