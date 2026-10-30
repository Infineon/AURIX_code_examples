/**
 * \file IfxPmsEvr.c
 * \brief PMS  basic functionality
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

#include "IfxPmsEvr.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/
#ifndef DEVICE_TC33X
IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase1Default[] = {
    {&PMS_EVRSDCOEFF6.U, (0x00873802U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF7.U, (0x0000D066U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF8.U, (0x00073802U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF9.U, (0x00009826U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL7.U,  (0x000000C9U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL0.U,  (0x30360001U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL1.U,  (0x0B690708U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL8.U,  (0x0121048EU), (0xFFFFFFFFU)},
};

IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase2Default[] = {
    {&PMS_EVRSDCOEFF0.U, (0x350873B6U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF1.U, (0x02946C46U), (0xFFFFFFFFU)},
}


;

IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase3Default[] = {
    {&PMS_EVRSDCTRL0.U,  (0x30360002U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL2.U,  (0x0036033BU), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL3.U,  (0x0B690810U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF2.U, (0x3408710EU), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF3.U, (0x02946C44U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL4.U,  (0x00360009U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL5.U,  (0x0B690808U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL6.U,  (0x00231C94U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF4.U, (0x1B0822B6U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF5.U, (0x02946C46U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL9.U,  (0x00000434U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL10.U, (0x00005A82U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL11.U, (0x12070909U), (0xFFFFFFFFU)},
};

IFX_CONST IfxPmsEvr_initSequencePhase          IfxPmsEvr_cfgPhasesDefault[] = {
    {
        sizeof(IfxPmsEvr_cfgPhase1Default) / sizeof(IfxPmsEvr_StepDownRegulatorRegConfig),
        IfxPmsEvr_cfgPhase1Default,
        (0.00002F)
    },
    {
        sizeof(IfxPmsEvr_cfgPhase2Default) / sizeof(IfxPmsEvr_StepDownRegulatorRegConfig),
        IfxPmsEvr_cfgPhase2Default,
        (0.00002F)
    },
    {
        sizeof(IfxPmsEvr_cfgPhase3Default) / sizeof(IfxPmsEvr_StepDownRegulatorRegConfig),
        IfxPmsEvr_cfgPhase3Default,
        (0.00002F)
    }
};

IFX_CONST IfxPmsEvr_initSequence               IfxPmsEvr_cfgSequenceDefault = {
    sizeof(IfxPmsEvr_cfgPhasesDefault) / sizeof(IfxPmsEvr_initSequencePhase),
    IfxPmsEvr_cfgPhasesDefault
};


IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_checkRegValuesDefault[] = {
    {&PMS_EVRSDCOEFF6.U, (0x00873802U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF7.U, (0x0000D066U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF8.U, (0x00073802U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF9.U, (0x00009826U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL7.U,  (0x000000C9U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL1.U,  (0x0B690708U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL8.U,  (0x0121048EU), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF0.U, (0x350873B6U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF1.U, (0x02946C46U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL0.U,  (0x30360002U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL2.U,  (0x0036033BU), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL3.U,  (0x0B690810U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF2.U, (0x3408710EU), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF3.U, (0x02946C44U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL4.U,  (0x00360009U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL5.U,  (0x0B690808U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL6.U,  (0x00231C94U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF4.U, (0x1B0822B6U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCOEFF5.U, (0x02946C46U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL9.U,  (0x00000434U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL10.U, (0x00005A82U), (0xFFFFFFFFU)},
    {&PMS_EVRSDCTRL11.U, (0x12070909U), (0xFFFFFFFFU)},
};

IFX_CONST IfxPmsEvr_checkRegConfig             IfxPmsEvr_checkRegCfgDefault = {
    sizeof(IfxPmsEvr_checkRegValuesDefault) / sizeof(IfxPmsEvr_StepDownRegulatorRegConfig),
    IfxPmsEvr_checkRegValuesDefault
};
#endif
/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxPmsEvr_filterSecondaryConversionResult(Ifx_PMS *pms, IfxPmsEvr_SupplyFilter adcFilterValue, IfxPmsEvr_SupplyMode supply)
{
    uint16          passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_MONFILT tempMONFILT;

    /* Clear safety endinit protection */
    IfxScuWdt_clearSafetyEndinit(passwd);
    /* Reads the current filter register value */
    tempMONFILT.U = pms->MONFILT.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempMONFILT.B.EVRCFIL = adcFilterValue;
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempMONFILT.B.EVR33FIL = adcFilterValue;
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempMONFILT.B.SWDFIL = adcFilterValue;
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempMONFILT.B.PREFIL = adcFilterValue;
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempMONFILT.B.VDDMFIL = adcFilterValue;
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempMONFILT.B.SBFIL = adcFilterValue;
        break;
    }

    /* Updates the filter register with the new value */
    pms->MONFILT.U = tempMONFILT.U;

    /* Set safety endinit protection again */
    IfxScuWdt_setSafetyEndinit(passwd);
}


uint8 IfxPmsEvr_getSecondaryAdcResult(Ifx_PMS *pms, IfxPmsEvr_SupplyMode supply)
{
    uint8 adcResult = 0;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc: adcResult  = pms->MONSTAT1.B.ADCCV;
        break;
    case IfxPmsEvr_SupplyMode_evr33: adcResult = pms->MONSTAT1.B.ADC33V;
        break;
    case IfxPmsEvr_SupplyMode_swd: adcResult   = pms->MONSTAT1.B.ADCSWDV;
        break;
    case IfxPmsEvr_SupplyMode_evrpr: adcResult = pms->MONSTAT2.B.ADCPRE;
        break;
    case IfxPmsEvr_SupplyMode_sb: adcResult    = pms->MONSTAT2.B.ADCSB;
        break;
    case IfxPmsEvr_SupplyMode_vddm: adcResult  = pms->MONSTAT2.B.ADCVDDM;
        break;
    }

    return adcResult;
}


void IfxPmsEvr_setSecondaryOverVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply)
{
    uint16         passwd = IfxScuWdt_getSafetyWatchdogPassword();
    Ifx_PMS_OVMON  tempOVMON;
    Ifx_PMS_OVMON2 tempOVMON2;

    /* Clear safety endinit protection */
    IfxScuWdt_clearSafetyEndinit(passwd);

    /* Reads current OVMON register value */
    tempOVMON.U  = pms->OVMON.U;
    /* Reads current OVMON2 register value */
    tempOVMON2.U = pms->OVMON2.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempOVMON.B.EVRCOVVAL = (uint8)((thresholdLevel / 5.7692f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempOVMON.B.EVR33OVVAL = (uint8)((thresholdLevel / 15) + 1);
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempOVMON.B.SWDOVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempOVMON2.B.PREOVVAL = (uint8)((thresholdLevel / 5.7692f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempOVMON2.B.VDDMOVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempOVMON2.B.SBOVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    }

    /* Updates OVMON register with new threshold */
    pms->OVMON.U  = tempOVMON.U;
    /* Updates OVMON2 register with new threshold */
    pms->OVMON2.U = tempOVMON2.U;

    /* Set safety endinit protection again */
    IfxScuWdt_setSafetyEndinit(passwd);
}


void IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply)
{
    uint16         passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_UVMON  tempUVMON;
    Ifx_PMS_UVMON2 tempUVMON2;

    /* Clear safety endinit protection */
    IfxScuWdt_clearSafetyEndinit(passwd);

    /* Reads current UVMON register value */
    tempUVMON.U  = pms->UVMON.U;
    /* Reads current UVMON2 register value */
    tempUVMON2.U = pms->UVMON2.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempUVMON.B.EVRCUVVAL = (uint8)((thresholdLevel / 5.7692f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempUVMON.B.EVR33UVVAL = (uint8)((thresholdLevel / 15) + 1);
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempUVMON.B.SWDUVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempUVMON2.B.PREUVVAL = (uint8)((thresholdLevel / 5.7692f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempUVMON2.B.VDDMUVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempUVMON2.B.SBUVVAL = (uint8)((thresholdLevel / 23.077f) + 1);
        break;
    }

    /* Updates UVMON register with new threshold */
    pms->UVMON.U  = tempUVMON.U;
    /* Updates UVMON2 register with new threshold */
    pms->UVMON2.U = tempUVMON2.U;

    /* Set safety endinit protection again */
    IfxScuWdt_setSafetyEndinit(passwd);
}
