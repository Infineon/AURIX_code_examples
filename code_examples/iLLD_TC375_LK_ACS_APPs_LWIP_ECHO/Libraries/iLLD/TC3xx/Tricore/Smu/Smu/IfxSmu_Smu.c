/**
 * \file IfxSmu_Smu.c
 * \brief SMU SMU details
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxSmu_Smu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxSmu_Smu_initModuleConfig(IfxSmu_Smu_Config *config)
{
    const IfxSmu_Smu_Config IfxSmu_Smu_defaultConfig = {
        .fsp                            = {
            .prescalar1             = IfxSmu_FspPrescalar1_referenceClockDiv2,
            .prescalar2             = IfxSmu_FspPrescalar2_referenceClockDiv512,
            .mode                   = IfxSmu_FspMode_BiStableProtocol,
            .portEmergencyStop      = 0,
            .faultStateDurationHigh = 0,
            .faultStateDurationLow  = 0
        },
        .alarmGlobalConfig              = {
            .igcs0                      = 0,
            .igcs1                      = 0,
            .igcs2                      = 0,
            .resetConfigSet             = 0,
            .portEmergencyStop          = 0,
            .enableFaultToRunTransition = FALSE
        },
        .recoveryTimerConfig            = {
            .enableRecoveryTimer0  = FALSE,
            .enableRecoveryTimer1  = FALSE,
            .recoveryTimerDuration = 0
        },
        .recoveryTimerAlarmConfig       = {
            {
                .groupIndex0 = 0,
                .alarmId0    = 0,
                .groupIndex1 = 0,
                .alarmId1    = 0,
                .groupIndex2 = 0,
                .alarmId2    = 0,
                .groupIndex3 = 0,
                .alarmId3    = 0
            },
            {
                .groupIndex0 = 0,
                .alarmId0    = 0,
                .groupIndex1 = 0,
                .alarmId1    = 0,
                .groupIndex2 = 0,
                .alarmId2    = 0,
                .groupIndex3 = 0,
                .alarmId3    = 0
            },
        },
        .alarmConfigRegister[0][0]  = 0,
        .alarmConfigRegister[0][1]  = 0,
        .alarmConfigRegister[0][2]  = 0,
        .alarmConfigRegister[1][0]  = 0,
        .alarmConfigRegister[1][1]  = 0,
        .alarmConfigRegister[1][2]  = 0,
        .alarmConfigRegister[2][0]  = 0,
        .alarmConfigRegister[2][1]  = 0,
        .alarmConfigRegister[2][2]  = 0,
        .alarmConfigRegister[3][0]  = 0,
        .alarmConfigRegister[3][1]  = 0,
        .alarmConfigRegister[3][2]  = 0,
        .alarmConfigRegister[4][0]  = 0,
        .alarmConfigRegister[4][1]  = 0,
        .alarmConfigRegister[4][2]  = 0,
        .alarmConfigRegister[5][0]  = 0,
        .alarmConfigRegister[5][1]  = 0,
        .alarmConfigRegister[5][2]  = 0,
        .alarmConfigRegister[6][0]  = 0,
        .alarmConfigRegister[6][1]  = 0,
        .alarmConfigRegister[6][2]  = 0,
        .alarmConfigRegister[7][0]  = 0,
        .alarmConfigRegister[7][1]  = 0,
        .alarmConfigRegister[7][2]  = 0,
        .alarmConfigRegister[8][0]  = 0,
        .alarmConfigRegister[8][1]  = 0,
        .alarmConfigRegister[8][2]  = 0,
        .alarmConfigRegister[9][0]  = 0,
        .alarmConfigRegister[9][1]  = 0,
        .alarmConfigRegister[9][2]  = 0,
        .alarmConfigRegister[10][0] = 0,
        .alarmConfigRegister[10][1] = 0,
        .alarmConfigRegister[10][2] = 0,
        .alarmConfigRegister[11][0] = 0,
        .alarmConfigRegister[11][1] = 0,
        .alarmConfigRegister[11][2] = 0,
        .fspConfigRegister[0]       = 0,
        .fspConfigRegister[1]       = 0,
        .fspConfigRegister[2]       = 0,
        .fspConfigRegister[3]       = 0,
        .fspConfigRegister[4]       = 0,
        .fspConfigRegister[5]       = 0,
        .fspConfigRegister[6]       = 0,
        .fspConfigRegister[7]       = 0,
        .fspConfigRegister[8]       = 0,
        .fspConfigRegister[9]       = 0,
        .fspConfigRegister[10]      = 0,
        .fspConfigRegister[11]      = 0,
    };

    *config = IfxSmu_Smu_defaultConfig;
}


void IfxSmu_Smu_initModule(IfxSmu_Smu_Config *config)
{
    Ifx_SMU_FSP    fspSfr;
    Ifx_SMU_AGC    agcSfr;
    Ifx_SMU_RTC    rtcSfr;

    Ifx_SMU_RTAC00 rtacSfr0;
    Ifx_SMU_RTAC01 rtacSfr1;

    uint16         passwd          = IfxScuWdt_getSafetyWatchdogPassword();
    uint8          alarmGroupIndex = 0;

    /* Disable the write-protection for registers */
    IfxScuWdt_clearSafetyEndinit(passwd);

    /* Write Config key to configure the SMU registers */
    MODULE_SMU.KEYS.U = (uint32)0x000000bc;

    /* Configure SMU module register as per the requested configuration */
    fspSfr.U           = MODULE_SMU.FSP.U;
    fspSfr.B.PRE1      = config->fsp.prescalar1;
    fspSfr.B.PRE2      = config->fsp.prescalar2;
    fspSfr.B.MODE      = config->fsp.mode;
    fspSfr.B.PES       = config->fsp.portEmergencyStop;
    fspSfr.B.TFSP_LOW  = config->fsp.faultStateDurationLow;
    fspSfr.B.TFSP_HIGH = config->fsp.faultStateDurationHigh;
    MODULE_SMU.FSP.U   = fspSfr.U;

    agcSfr.U           = MODULE_SMU.AGC.U;
    agcSfr.B.IGCS0     = config->alarmGlobalConfig.igcs0;
    agcSfr.B.IGCS1     = config->alarmGlobalConfig.igcs1;
    agcSfr.B.IGCS2     = config->alarmGlobalConfig.igcs2;
    agcSfr.B.RCS       = config->alarmGlobalConfig.resetConfigSet;
    agcSfr.B.PES       = config->alarmGlobalConfig.portEmergencyStop;
    agcSfr.B.EFRST     = config->alarmGlobalConfig.enableFaultToRunTransition;
    MODULE_SMU.AGC.U   = agcSfr.U;

    rtcSfr.U           = MODULE_SMU.RTC.U;
    rtcSfr.B.RT0E      = config->recoveryTimerConfig.enableRecoveryTimer0;
    rtcSfr.B.RT1E      = config->recoveryTimerConfig.enableRecoveryTimer1;
    rtcSfr.B.RTD       = config->recoveryTimerConfig.recoveryTimerDuration;
    MODULE_SMU.RTC.U   = rtcSfr.U;

    /* Recovery Timer 0 Alarm Configuration 0 */

    rtacSfr0.U          = MODULE_SMU.RTAC00.U;

    rtacSfr0.B.GID0     = config->recoveryTimerAlarmConfig[0].groupIndex0;
    rtacSfr0.B.ALID0    = config->recoveryTimerAlarmConfig[0].alarmId0;
    rtacSfr0.B.GID1     = config->recoveryTimerAlarmConfig[0].groupIndex1;
    rtacSfr0.B.ALID1    = config->recoveryTimerAlarmConfig[0].alarmId1;

    MODULE_SMU.RTAC00.U = rtacSfr0.U;

    /* Recovery Timer 0 Alarm Configuration 1 */

    rtacSfr1.U          = MODULE_SMU.RTAC01.U;

    rtacSfr1.B.GID2     = config->recoveryTimerAlarmConfig[0].groupIndex2;
    rtacSfr1.B.ALID2    = config->recoveryTimerAlarmConfig[0].alarmId2;
    rtacSfr1.B.GID3     = config->recoveryTimerAlarmConfig[0].groupIndex3;
    rtacSfr1.B.ALID3    = config->recoveryTimerAlarmConfig[0].alarmId3;

    MODULE_SMU.RTAC01.U = rtacSfr1.U;

    /* Recovery Timer 1 Alarm Configuration 0 */

    rtacSfr0.U          = MODULE_SMU.RTAC10.U;

    rtacSfr0.B.GID0     = config->recoveryTimerAlarmConfig[1].groupIndex0;
    rtacSfr0.B.ALID0    = config->recoveryTimerAlarmConfig[1].alarmId0;
    rtacSfr0.B.GID1     = config->recoveryTimerAlarmConfig[1].groupIndex1;
    rtacSfr0.B.ALID1    = config->recoveryTimerAlarmConfig[1].alarmId1;

    MODULE_SMU.RTAC10.U = rtacSfr0.U;

    /* Recovery Timer 1 Alarm Configuration 1 */

    rtacSfr1.U          = MODULE_SMU.RTAC11.U;

    rtacSfr1.B.GID2     = config->recoveryTimerAlarmConfig[1].groupIndex2;
    rtacSfr1.B.ALID2    = config->recoveryTimerAlarmConfig[1].alarmId2;
    rtacSfr1.B.GID3     = config->recoveryTimerAlarmConfig[1].groupIndex3;
    rtacSfr1.B.ALID3    = config->recoveryTimerAlarmConfig[1].alarmId3;

    MODULE_SMU.RTAC11.U = rtacSfr1.U;

    for (alarmGroupIndex = 0U; alarmGroupIndex < IFXSMU_NUM_ALARM_GROUPS; alarmGroupIndex++)
    {
        MODULE_SMU.AGCF[alarmGroupIndex][0].U = config->alarmConfigRegister[alarmGroupIndex][0];
        MODULE_SMU.AGCF[alarmGroupIndex][1].U = config->alarmConfigRegister[alarmGroupIndex][1];
        MODULE_SMU.AGCF[alarmGroupIndex][2].U = config->alarmConfigRegister[alarmGroupIndex][2];
    }

    for (alarmGroupIndex = 0U; alarmGroupIndex < IFXSMU_NUM_ALARM_GROUPS; alarmGroupIndex++)
    {
        MODULE_SMU.AGFSP[alarmGroupIndex].U = config->fspConfigRegister[alarmGroupIndex];
    }

    /* After configuration set temporary lock of SMU configuration */
    MODULE_SMU.KEYS.U = 0;

    /* Restore back the write-protection for registers */
    IfxScuWdt_setSafetyEndinit(passwd);

    /* Clear all SMU Alarms */
    for (alarmGroupIndex = 0U; alarmGroupIndex < IFXSMU_NUM_ALARM_GROUPS; alarmGroupIndex++)
    {
        /* Write SMU_ASCE(0) in CMD register */
        MODULE_SMU.CMD.U = IfxSmu_Command_alarmStatusClear;

        /* Disable the write-protection for registers */
        IfxScuWdt_clearSafetyEndinit(passwd);

        /* Write 1 in AG bit to clear alarm */
        MODULE_SMU.AG[alarmGroupIndex].U = 0xFFFFFFFFU;

        /* Restore back the write-protection for registers */
        IfxScuWdt_setSafetyEndinit(passwd);
    }
}


boolean IfxSmu_Smu_isAlarmTriggered(void)
{
    boolean result = FALSE;
    uint32  groups;

    for (groups = 0; groups < IFXSMU_NUM_ALARM_GROUPS; groups++)
    {
        if ((MODULE_SMU.AG[groups].U != 0))
        {
            result = TRUE;
            break;
        }
        else
        {
            result = FALSE;
        }
    }

    return result;
}
