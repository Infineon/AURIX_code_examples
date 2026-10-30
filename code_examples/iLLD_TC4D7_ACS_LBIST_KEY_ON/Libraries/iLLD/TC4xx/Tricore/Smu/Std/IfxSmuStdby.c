/**
 * \file IfxSmuStdby.c
 * \brief SMU  basic functionality
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

#include "IfxSmuStdby.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSmuStdby_setFaultSignalAlarmConfigEventFlag(void *address, IfxSmu_Alarm alarm, IfxSmuStdby_FaultSignalAlarmConfigFlagEvent enable)
{
    uint8                       alarmPos = (int)alarm & 0x1F;
    Ifx_SMU_STDBY_AGSTDBY_FSP0 *fsp0     = (Ifx_SMU_STDBY_AGSTDBY_FSP0 *)address;
    Ifx_SMU_STDBY_AGSTDBY_FSP0  fsp0Temp;
    fsp0Temp.U = fsp0->U;

    if (enable)
    {
        fsp0Temp.U |= (1U << alarmPos);
    }
    else
    {
        fsp0Temp.U &= ~(1U << alarmPos);
    }

    /* AG2iFSP_STDBY register bits protection setting this bit enables the other bits in the registers (FEz) to be
       changed in the same write operation */
    fsp0Temp.B.BITPROT = 1U;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMUSTDBY.PROTSTDBYE, IfxApProt_State_config);
#endif

    fsp0->U = fsp0Temp.U;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMUSTDBY.PROTSTDBYE, IfxApProt_State_run);
#endif
}


void IfxSmuStdby_setSmuStdbyAlarmStatusFlag(IfxSmu_Alarm alarm, IfxSmuStdby_AlarmStatusFlag status)
{
    Ifx_SMU_STDBY_AGSTDBY_STS sts;
    Ifx_SMU_STDBY_CMDSTDBY    cmdStdby;
    uint16                    alarmGroup = (int)alarm >> 5;
    uint8                     alarmPos   = (int)alarm & 0x1F;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMUSTDBY.PROTSTDBYE, IfxApProt_State_config);
#endif

    cmdStdby.U          = SMUSTDBY_CMDSTDBY.U;
    /* SMU_stdby alarm status bits in AGSTDBYi_STS can be cleared */
    cmdStdby.B.ASCE     = 1;
    /* CMDSTDBY register bits protection setting this bit enables the other bits in the registers  to
       be changed in the same write operation*/
    cmdStdby.B.BITPROT  = 1;
    SMUSTDBY_CMDSTDBY.U = cmdStdby.U;

    sts.U               = MODULE_SMUSTDBY.AGSTDBY[alarmGroup].STS.U;

    if (status == IfxSmuStdby_AlarmStatusFlag_faultExist)
    {
        sts.U |= 1U << alarmPos;
    }
    else
    {
        sts.U &= ~(1U << alarmPos);
    }

    MODULE_SMUSTDBY.AGSTDBY[alarmGroup].STS.U = sts.U;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&MODULE_SMUSTDBY.PROTSTDBYE, IfxApProt_State_run);
#endif
}


#if IFXSMU_CONFIG_STDBY_SMU
void IfxSmuStdby_configureAccessToStandbySmu(IfxApApu_ApuConfig *apConfig)
{
	/* Initializes and Configures the APU with the config value passed */
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_SMUSTDBY.ACCENSTDBY, apConfig);
}
#endif /* #if IFXSMU_CONFIG_STDBY_SMU */
