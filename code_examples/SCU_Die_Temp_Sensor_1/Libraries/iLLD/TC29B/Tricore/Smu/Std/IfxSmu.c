/**
 * \file IfxSmu.c
 * \brief SMU  basic functionality
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

#include "IfxSmu.h"
#include "Port/Std/IfxPort.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxSmu_initFsp(Ifx_SMU *smu, IfxSmu_configFsp *config)
{
    /* FIXME IfxSmu_Fsp is not required, only need Ifx_SMU */
    boolean result = TRUE;

    float32 fBack  = 100e6;
    uint16  endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

    IfxSmu_unlock(smu);

    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->AGC.B.EFRST = config->enableFaultToRunStateTransition ? 1 : 0;
    smu->FSP.B.PES   = config->emergencyStopEnabled ? 1 : 0;
    smu->FSP.B.MODE  = config->mode == IfxSmu_Fsp_Mode_bistable ? 0 : 2;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

    {
        uint32  tFspHigh;
        boolean ok = FALSE;

        float32 tSmuFs;
        uint32  i;

        for (i = 0; i < 8; i++)
        {
            IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
            smu->FSP.B.PRE1 = i; /* Write PRE1 to get TFSP_LOW value */
            IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

            tSmuFs = (1 << (smu->FSP.B.PRE1 + 1)) / fBack;

            /*
             *	tFSP_FS = tSMU_FS *(SMU_FSP.TFSP_HIGH[] & SMU_FSP.TFSP_LOW[] + 1)
             *
             *	tFSP_FS = tSMU_FS *(SMU_FSP.TFSP + 1)
             *	(SMU_FSP.TFSP + 1) = tFSP_FS / tSMU_FS
             *
             *
             */

            tFspHigh = ((uint32)(config->faultStateTime / tSmuFs) - 1) >> IFX_SMU_FSP_TFSP_LOW_LEN;

            /* FIXME check why condition is always true */

            if (
                (config->faultStateTime <= tSmuFs * (((tFspHigh << IFX_SMU_FSP_TFSP_LOW_LEN) | (smu->FSP.B.TFSP_LOW)) + 1)) /* Check minimal fault time  */
                && (tFspHigh <= IFX_SMU_FSP_TFSP_HIGH_MSK)                                                                  /* Check for overflow */
                )
            {
                ok                   = TRUE;
                IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
                smu->FSP.B.TFSP_HIGH = tFspHigh;
                IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
                break;
            }
        }

        result &= ok;
    }

    if (config->mode == IfxSmu_Fsp_Mode_timeSwitching)
    {
        uint32  dividers[4] = {512, 1024, 2048, 4096};
        uint32  i;
        float32 fSmuFfs;
        boolean ok = FALSE;

        for (i = 0; i < 4; i++)
        {
            fSmuFfs = fBack / dividers[i];

            if ((config->faultFreeStateFrequencyMin < fSmuFfs) && (fSmuFfs < config->faultFreeStateFrequencyMax))
            {
                ok              = TRUE;
                IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
                smu->FSP.B.PRE2 = i;
                IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
                break;
            }
        }

        result &= ok;
    }

    {
        IfxSmu_Fsp_Out *out = IfxSmu_Fsp_Out_pinTable[0][0];
        IfxPort_setPinModeOutput(out->pin.port, out->pin.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
        IfxPort_setPinPadDriver(out->pin.port, out->pin.pinIndex, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    }

    {
        /* Configure the FSP port to output */
        Ifx_SMU_PCTL regPctrl;
        regPctrl.U       = smu->PCTL.U;

        regPctrl.B.HWDIR = 1; /* Set to output */
        regPctrl.B.HWEN  = 1; /* Port is driven by FSP */
        regPctrl.B.PCS   = 1; /* PAD is controlled by the SMU */

        IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
        smu->PCTL.U = regPctrl.U;
        IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
    }

    IfxSmu_lock(smu);

    return result;
}


boolean IfxSmu_cmd(Ifx_SMU *smu, uint8 cmd, uint8 arg)
{
    Ifx_SMU_CMD reg;
    Ifx_SMU_STS status;
    uint16      endinitSfty_pw;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

    reg.U          = 0;
    reg.B.CMD      = cmd;
    reg.B.ARG      = arg;

    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->CMD.U = reg.U;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

    status.U = smu->STS.U;
    return (status.B.CMD == cmd) && (status.B.ARG == arg) && (status.B.RES == 0);
}


float32 IfxSmu_getFspFaultFreeFrequency(Ifx_SMU *smu)
{
    float32 fBack       = 100e6;
    uint32  dividers[4] = {512, 1024, 2048, 4096};

    return fBack / dividers[smu->FSP.B.PRE2];
}


float32 IfxSmu_getFspFaultStateTime(Ifx_SMU *smu)
{
    float32 fBack = 100e6;
    float32 tSmuFs;

    tSmuFs = (1 << (smu->FSP.B.PRE1 + 1)) / fBack;

    return tSmuFs * (((smu->FSP.B.TFSP_HIGH << IFX_SMU_FSP_TFSP_LOW_LEN) | (smu->FSP.B.TFSP_LOW)) + 1);
}


boolean IfxSmu_unlock(Ifx_SMU *smu)
{
    boolean result;

    if (smu->KEYS.B.PERLCK != 0xFF)
    {
        uint16 endinitSfty_pw;
        endinitSfty_pw     = IfxScuWdt_getSafetyWatchdogPassword();
        IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
        smu->KEYS.B.CFGLCK = 0xBC;
        IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
        result             = TRUE;
    }
    else
    {
        result = FALSE;
    }

    return result;
}


void IfxSmu_lock(Ifx_SMU *smu)
{
    uint16 endinitSfty_pw;
    endinitSfty_pw     = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->KEYS.B.CFGLCK = 0x00;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
}


void IfxSmu_lockForever(Ifx_SMU *smu)
{
    uint16 endinitSfty_pw;
    endinitSfty_pw     = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->KEYS.B.PERLCK = 0xFF;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
}


void IfxSmu_setAlarmConfig(Ifx_SMU *smu, IfxSmu_Alarm alarm, IfxSmu_AlarmConfig config)
{
    uint16            endinitSfty_pw;
    IfxSmu_AlarmGroup group = (alarm >> 8) & 0xFF;
    uint32            index = alarm & 0xFF;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);

    smu->AGCF[group][0].U &= ~(1 << index);
    smu->AGCF[group][1].U &= ~(1 << index);
    smu->AGCF[group][2].U &= ~(1 << index);

    smu->AGCF[group][0].U |= ((config >> 0) & 1) << index;
    smu->AGCF[group][1].U |= ((config >> 1) & 1) << index;
    smu->AGCF[group][2].U |= ((config >> 2) & 1) << index;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
}


void IfxSmu_enableAlarmFsp(Ifx_SMU *smu, IfxSmu_Alarm alarm, boolean enabled)
{
    uint16            endinitSfty_pw;
    IfxSmu_AlarmGroup group = (alarm >> 8) & 0xFF;
    uint32            index = alarm & 0xFF;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->AGFSP[group].U &= (~1) << index;

    smu->AGFSP[group].U |= (enabled ? 1 : 0) << index;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
}


boolean IfxSmu_isAlarmSet(Ifx_SMU *smu, IfxSmu_Alarm alarm)
{
    IfxSmu_AlarmGroup group = (alarm >> 8) & 0xFF;
    uint32            index = alarm & 0xFF;

    return ((smu->AG[group].U >> index) & 1) != 0;
}


IfxSmu_Alarm IfxSmu_getAlarm(Ifx_SMU *smu)
{
    IfxSmu_AlarmGroup group;
    uint32            index;

    for (group = IfxSmu_AlarmGroup_0; group <= IfxSmu_AlarmGroup_6; group++)
    {
        index = __clz(smu->AG[group].U);

        if (index != 32)
        {
            return (group << 8) | (31 - index);
        }
    }

    return IfxSmu_Alarm_noAlarm;
}


void IfxSmu_clearAlarm(Ifx_SMU *smu, IfxSmu_Alarm alarm)
{
    uint16            endinitSfty_pw;
    IfxSmu_AlarmGroup group = (alarm >> 8) & 0xFF;
    uint32            index = alarm & 0xFF;
    endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);
    smu->AG[group].U = 1 << index;
    IfxScuWdt_setSafetyEndinit(endinitSfty_pw);
}
