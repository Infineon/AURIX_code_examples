/**
 * \file IfxStdIf_Pos.c
 * \brief Standard interface: Position interface
 * \ingroup IfxStdIf
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

#include "IfxStdIf_Pos.h"

void IfxStdIf_Pos_initConfig (IfxStdIf_Pos_Config * config)
{
    config->offset = 0;
    config->reversed = FALSE;
    config->resolution = 0;
    config->periodPerRotation = 1;
    config->resolutionFactor = IfxStdIf_Pos_ResolutionFactor_oneFold;
    config->updatePeriod = 0.001;
    config->speedModeThreshold = 0;
    config->minSpeed = 0;       // 0 rpm
    config->maxSpeed = 20000.0 / 60.0 * (2 * IFX_PI);   // 20000 rpm
    config->speedFilterEnabled = FALSE;
    config->speedFilerCutOffFrequency = 0;

}

void IfxStdIf_Pos_printStatus(IfxStdIf_Pos_Status status, IfxStdIf_DPipe *io)
{
    IfxStdIf_DPipe_print(io, "Position sensor status:"ENDL);
    if (status.status != 0)
    {
        if (status.B.commError)
        {
        	IfxStdIf_DPipe_print(io, "- Communication error"ENDL);
        }
        if (status.B.commErrorThresholdReached)
        {
        	IfxStdIf_DPipe_print(io, "- Communication error threshold reached"ENDL);
        }
        if (status.B.notSynchronised)
        {
        	IfxStdIf_DPipe_print(io, "- Synchronization error"ENDL);
        }
        if (status.B.signalDegradation)
        {
        	IfxStdIf_DPipe_print(io, "- Signal degradation error"ENDL);
        }
        if (status.B.signalLoss)
        {
        	IfxStdIf_DPipe_print(io, "- Signal loss error"ENDL);
        }
        if (status.B.trackingLoss)
        {
        	IfxStdIf_DPipe_print(io, "- Tracking error"ENDL);
        }
    }
    else
    {
    	IfxStdIf_DPipe_print(io, "- Ready"ENDL);
    }
}
