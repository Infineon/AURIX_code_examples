/**
 * \file IfxPmsEvr.h
 * \brief PMS  basic functionality
 * \ingroup IfxLld_Pms
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
 * \defgroup IfxLld_Pms_Std_Evr How to use the PMS EVR driver?
 * \ingroup IfxLld_Pms_Std
 *
 * The PMS EVR driver provides APIs to monitor, configure, and control the on-chip voltage regulators and supply domains.
 * It enables detection and handling of over-voltage and under-voltage conditions, adjustment of regulator output levels, and configuration of supply monitoring and trimming.
 * The driver supports initialization sequences, interrupt configuration, and voltage measurement for safe and reliable power management.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Pms_Std_Evr_Preparation Preparation
 * \subsection IfxLld_Pms_Std_Include      Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Pms/Std/IfxPmsEvr.h>
 * \endcode
 *
 * \subsection IfxLld_Pms_Std_Evr_Variables Variables
 *
 * \code
 * // used globally
 * Ifx_PMS modulePms;  //PMS Module instance
 * \encode
 *
 * \subsection IfxLld_Pms_Std_Evr_PmsSecondaryVoltageConfig Pms Secondary voltage configuration
 *
 * \code
 * IfxPmsEvr_SupplyMode supply = IfxPmsEvr_SupplyMode_evrc;
 *
 * IfxPmsEvr_filterSecondaryConversionResult(&modulePms, IfxPmsEvr_SupplyFilter_avgAdcConversionResult0, supply);
 *
 * IfxPmsEvr_setSecondaryOverVoltageThresholdMv(&modulePms, overVoltageThreshold, supply);
 *
 * IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(&modulePms, underVoltageThreshold, supply);
 *
 * IfxPmsEvr_getSecondaryAdcResult(&modulePms, supply);
 * \encode
 *
 * \defgroup IfxLld_Pms_Std_Evr EVR
 * \ingroup IfxLld_Pms_Std
 * \defgroup IfxLld_Pms_Std_Evr_Enum Enumerations
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Over-Voltage Over Voltage Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Module Module Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_Under-Voltage Under Voltage Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_EVRC EVRC Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_EVR33 EVR33 Functions
 * \ingroup IfxLld_Pms_Std_Evr
 * \defgroup IfxLld_Pms_Std_Evr_SWD SWD Functions
 * \ingroup IfxLld_Pms_Std_Evr
 */

#ifndef IFXPMSEVR_H
#define IFXPMSEVR_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxPms_cfg.h"
#include "Cpu/Std/IfxCpu.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPms_bf.h"
#include "IfxPms_reg.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define IFXPMSEVR_ADC_VDD_LSB               (0.005f)

#define IFXPMSEVR_ADC_VDDP3_LSB             (0.015f)

#define IFXPMSEVR_ADC_VEXT_LSB              (0.02f)

#define IFXPMSEVR_CTRL_UP_WAIT_TIMEOUTCOUNT (0x100)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Pms_Std_Evr_Enum
 * \{ */
/** \brief Configure respective interrupts defined in register Ifx_PMS.PMSIEN
 */
typedef enum
{
    IfxPmsEvr_EnableInterrupt_ovswd   = 0,   /**< \brief OVSWD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvswd   = 1,   /**< \brief UVSWD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ov33    = 2,   /**< \brief OV33Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uv33    = 3,   /**< \brief UV33 Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovc     = 4,   /**< \brief OVC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvc     = 5,   /**< \brief UVC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovpre   = 6,   /**< \brief OVPRE Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvpre   = 7,   /**< \brief UVPRE Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovddm   = 8,   /**< \brief OVDDM Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvddm   = 9,   /**< \brief UVDDM Interrupt enable */
    IfxPmsEvr_EnableInterrupt_ovsb    = 10,  /**< \brief OVSB Interrupt enable */
    IfxPmsEvr_EnableInterrupt_uvsb    = 11,  /**< \brief UVSB Interrupt enable */
    IfxPmsEvr_EnableInterrupt_evrcmod = 16,  /**< \brief EVRCMOD Interrupt enable */
    IfxPmsEvr_EnableInterrupt_sdvok   = 17,  /**< \brief SDVOK Interrupt enable */
    IfxPmsEvr_EnableInterrupt_synclck = 18,  /**< \brief SD SYNCLCK Interrupt enable */
    IfxPmsEvr_EnableInterrupt_swdlvl  = 19,  /**< \brief SWDLVL Interrupt enable */
    IfxPmsEvr_EnableInterrupt_wutwkp  = 21,  /**< \brief WUT WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_esr0wkp = 22,  /**< \brief ESR0 WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_esr1wkp = 23,  /**< \brief ESR1 WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_pinawkp = 24,  /**< \brief PINA WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_pinbwkp = 25,  /**< \brief PINB WKP Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrint  = 26,  /**< \brief SCR INT Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrrst  = 27,  /**< \brief SCR RST Interrupt enable */
    IfxPmsEvr_EnableInterrupt_screcc  = 28,  /**< \brief SCR ECC Interrupt enable */
    IfxPmsEvr_EnableInterrupt_scrwdt  = 29   /**< \brief SCR WDT Interrupt enable */
} IfxPmsEvr_EnableInterrupt;

/** \brief Current operation mode of EVRC Regulator defined in Ifx_PMS.EVR.STAT.B.EVRCMOD
 */
typedef enum
{
    IfxPmsEvr_EvrcMode_pwmMode      = 0,  /**< \brief The step-down converter is in
                                          * normal operational closed loop state */
    IfxPmsEvr_EvrcMode_lowPowerMode = 1,  /**< \brief The step-down converter is in low
                                           * power state */
    IfxPmsEvr_EvrcMode_startupMode  = 2,  /**< \brief The step-down converter is in start-up
                                           * phase */
    IfxPmsEvr_EvrcMode_disableMode  = 3   /**< \brief EVRC is Disable */
} IfxPmsEvr_EvrcMode;

/** \brief Switching frequency division factor for external synchronisation defined in Ifx_PMS.EVRSDCTRL7.B.SYNCDIVFAC
 */
typedef enum
{
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_1  = 0,  /**< \brief fDCDCSYNC = fDCDC. The actual duty cycle is routed. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_2  = 1,  /**< \brief fDCDCSYNC = fDCDC/2. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_4  = 2,  /**< \brief fDCDCSYNC = fDCDC/4. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_8  = 3,  /**< \brief fDCDCSYNC = fDCDC/8. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_16 = 4,  /**< \brief fDCDCSYNC = fDCDC/16. Duty cycle is constant at 50%. */
    IfxPmsEvr_ExtSyncSwitchingFreqDivFactor_32 = 5   /**< \brief fDCDCSYNC = fDCDC/32. Duty cycle is constant at 50%. */
} IfxPmsEvr_ExtSyncSwitchingFreqDivFactor;

/** \brief Monitoring OverVoltage for all bitfields defined
 * in .Ifx_PMS.EVR.MONCTRL register for overvoltage monitoring
 */
typedef enum
{
    IfxPmsEvr_OverVoltageMonitoring_inactive                         = 0, /**< \brief Over-Voltage Monitoring inactive */
    IfxPmsEvr_OverVoltageMonitoring_lowToHighVoltageTransition       = 1, /**< \brief Over-Voltage event is generated when threshold is crossed in lower to higher voltage transition */
    IfxPmsEvr_OverVoltageMonitoring_highToLowVoltageTransition       = 2, /**< \brief Over-Voltage event is generated when threshold is crossed in higher to lower voltage transition */
    IfxPmsEvr_OverVoltageMonitoring_eitherDirectionVoltageTransition = 3  /**< \brief Over-Voltage event is generated when threshold is crossed in either direction */
} IfxPmsEvr_OverVoltageMonitoring;

/** \brief set TRIM Value For respective Voltages.
 * Defined in Ifx_PMS.EVR.TRIM and Ifx_PMS.EVR.TRIM2
 */
typedef enum
{
    IfxPmsEvr_PrimaryAdcTrimValue_0 = 0,      /**< \brief Primary Adc Trim Value 0  */
    IfxPmsEvr_PrimaryAdcTrimValue_1,          /**< \brief Primary Adc Trim Value 1  */
    IfxPmsEvr_PrimaryAdcTrimValue_2,          /**< \brief Primary Adc Trim Value 2  */
    IfxPmsEvr_PrimaryAdcTrimValue_3,          /**< \brief Primary Adc Trim Value 3  */
    IfxPmsEvr_PrimaryAdcTrimValue_4,          /**< \brief Primary Adc Trim Value 4  */
    IfxPmsEvr_PrimaryAdcTrimValue_5,          /**< \brief Primary Adc Trim Value 5  */
    IfxPmsEvr_PrimaryAdcTrimValue_6,          /**< \brief Primary Adc Trim Value 6  */
    IfxPmsEvr_PrimaryAdcTrimValue_7,          /**< \brief Primary Adc Trim Value 7  */
    IfxPmsEvr_PrimaryAdcTrimValue_8,          /**< \brief Primary Adc Trim Value 8  */
    IfxPmsEvr_PrimaryAdcTrimValue_9,          /**< \brief Primary Adc Trim Value 9  */
    IfxPmsEvr_PrimaryAdcTrimValue_10,         /**< \brief Primary Adc Trim Value 10  */
    IfxPmsEvr_PrimaryAdcTrimValue_11,         /**< \brief Primary Adc Trim Value 11  */
    IfxPmsEvr_PrimaryAdcTrimValue_12,         /**< \brief Primary Adc Trim Value 12  */
    IfxPmsEvr_PrimaryAdcTrimValue_13,         /**< \brief Primary Adc Trim Value 13  */
    IfxPmsEvr_PrimaryAdcTrimValue_14,         /**< \brief Primary Adc Trim Value 14  */
    IfxPmsEvr_PrimaryAdcTrimValue_15,         /**< \brief Primary Adc Trim Value 15  */
    IfxPmsEvr_PrimaryAdcTrimValue_16,         /**< \brief Primary Adc Trim Value 16  */
    IfxPmsEvr_PrimaryAdcTrimValue_17,         /**< \brief Primary Adc Trim Value 17  */
    IfxPmsEvr_PrimaryAdcTrimValue_18,         /**< \brief Primary Adc Trim Value 18  */
    IfxPmsEvr_PrimaryAdcTrimValue_19,         /**< \brief Primary Adc Trim Value 19  */
    IfxPmsEvr_PrimaryAdcTrimValue_20,         /**< \brief Primary Adc Trim Value 20  */
    IfxPmsEvr_PrimaryAdcTrimValue_21,         /**< \brief Primary Adc Trim Value 21  */
    IfxPmsEvr_PrimaryAdcTrimValue_22,         /**< \brief Primary Adc Trim Value 22  */
    IfxPmsEvr_PrimaryAdcTrimValue_23,         /**< \brief Primary Adc Trim Value 23  */
    IfxPmsEvr_PrimaryAdcTrimValue_24,         /**< \brief Primary Adc Trim Value 24  */
    IfxPmsEvr_PrimaryAdcTrimValue_25,         /**< \brief Primary Adc Trim Value 25  */
    IfxPmsEvr_PrimaryAdcTrimValue_26,         /**< \brief Primary Adc Trim Value 26  */
    IfxPmsEvr_PrimaryAdcTrimValue_27,         /**< \brief Primary Adc Trim Value 27  */
    IfxPmsEvr_PrimaryAdcTrimValue_28,         /**< \brief Primary Adc Trim Value 28  */
    IfxPmsEvr_PrimaryAdcTrimValue_29,         /**< \brief Primary Adc Trim Value 29  */
    IfxPmsEvr_PrimaryAdcTrimValue_30,         /**< \brief Primary Adc Trim Value 30  */
    IfxPmsEvr_PrimaryAdcTrimValue_31,         /**< \brief Primary Adc Trim Value 31  */
    IfxPmsEvr_PrimaryAdcTrimValue_32,         /**< \brief Primary Adc Trim Value 32  */
    IfxPmsEvr_PrimaryAdcTrimValue_33,         /**< \brief Primary Adc Trim Value 33  */
    IfxPmsEvr_PrimaryAdcTrimValue_34,         /**< \brief Primary Adc Trim Value 34  */
    IfxPmsEvr_PrimaryAdcTrimValue_35,         /**< \brief Primary Adc Trim Value 35  */
    IfxPmsEvr_PrimaryAdcTrimValue_36,         /**< \brief Primary Adc Trim Value 36  */
    IfxPmsEvr_PrimaryAdcTrimValue_37,         /**< \brief Primary Adc Trim Value 37  */
    IfxPmsEvr_PrimaryAdcTrimValue_38,         /**< \brief Primary Adc Trim Value 38  */
    IfxPmsEvr_PrimaryAdcTrimValue_39,         /**< \brief Primary Adc Trim Value 39  */
    IfxPmsEvr_PrimaryAdcTrimValue_40,         /**< \brief Primary Adc Trim Value 40  */
    IfxPmsEvr_PrimaryAdcTrimValue_41,         /**< \brief Primary Adc Trim Value 41  */
    IfxPmsEvr_PrimaryAdcTrimValue_42,         /**< \brief Primary Adc Trim Value 42  */
    IfxPmsEvr_PrimaryAdcTrimValue_43,         /**< \brief Primary Adc Trim Value 43  */
    IfxPmsEvr_PrimaryAdcTrimValue_44,         /**< \brief Primary Adc Trim Value 44  */
    IfxPmsEvr_PrimaryAdcTrimValue_45,         /**< \brief Primary Adc Trim Value 45  */
    IfxPmsEvr_PrimaryAdcTrimValue_46,         /**< \brief Primary Adc Trim Value 46  */
    IfxPmsEvr_PrimaryAdcTrimValue_47,         /**< \brief Primary Adc Trim Value 47  */
    IfxPmsEvr_PrimaryAdcTrimValue_48,         /**< \brief Primary Adc Trim Value 48  */
    IfxPmsEvr_PrimaryAdcTrimValue_49,         /**< \brief Primary Adc Trim Value 49  */
    IfxPmsEvr_PrimaryAdcTrimValue_50,         /**< \brief Primary Adc Trim Value 50  */
    IfxPmsEvr_PrimaryAdcTrimValue_51,         /**< \brief Primary Adc Trim Value 51  */
    IfxPmsEvr_PrimaryAdcTrimValue_52,         /**< \brief Primary Adc Trim Value 52  */
    IfxPmsEvr_PrimaryAdcTrimValue_53,         /**< \brief Primary Adc Trim Value 53  */
    IfxPmsEvr_PrimaryAdcTrimValue_54,         /**< \brief Primary Adc Trim Value 54  */
    IfxPmsEvr_PrimaryAdcTrimValue_55,         /**< \brief Primary Adc Trim Value 55  */
    IfxPmsEvr_PrimaryAdcTrimValue_56,         /**< \brief Primary Adc Trim Value 56  */
    IfxPmsEvr_PrimaryAdcTrimValue_57,         /**< \brief Primary Adc Trim Value 57  */
    IfxPmsEvr_PrimaryAdcTrimValue_58,         /**< \brief Primary Adc Trim Value 58  */
    IfxPmsEvr_PrimaryAdcTrimValue_59,         /**< \brief Primary Adc Trim Value 59  */
    IfxPmsEvr_PrimaryAdcTrimValue_60,         /**< \brief Primary Adc Trim Value 60  */
    IfxPmsEvr_PrimaryAdcTrimValue_61,         /**< \brief Primary Adc Trim Value 61  */
    IfxPmsEvr_PrimaryAdcTrimValue_62,         /**< \brief Primary Adc Trim Value 62  */
    IfxPmsEvr_PrimaryAdcTrimValue_63          /**< \brief Primary Adc Trim Value 63  */
} IfxPmsEvr_PrimaryAdcTrimValue;

/** \brief This Declare the Under and over voltage counter defined in Ifx_PMS.EVR.MONFILT.B.ERRCNTLIMT
 */
typedef enum
{
    IfxPmsEvr_SecondaryVoltageErrorCounter_level0 = 0,      /**< \brief Error Counter Limit 0  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level1,          /**< \brief Error Counter Limit 1  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level2,          /**< \brief Error Counter Limit 2  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level3,          /**< \brief Error Counter Limit 3  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level4,          /**< \brief Error Counter Limit 4  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level5,          /**< \brief Error Counter Limit 5  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level6,          /**< \brief Error Counter Limit 6  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level7,          /**< \brief Error Counter Limit 7  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level8,          /**< \brief Error Counter Limit 8  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level9,          /**< \brief Error Counter Limit 9  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level10,         /**< \brief Error Counter Limit 10  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level11,         /**< \brief Error Counter Limit 11  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level12,         /**< \brief Error Counter Limit 12  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level13,         /**< \brief Error Counter Limit 13  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level14,         /**< \brief Error Counter Limit 14  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level15,         /**< \brief Error Counter Limit 15  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level16,         /**< \brief Error Counter Limit 16  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level17,         /**< \brief Error Counter Limit 17  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level18,         /**< \brief Error Counter Limit 18  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level19,         /**< \brief Error Counter Limit 19  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level20,         /**< \brief Error Counter Limit 20  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level21,         /**< \brief Error Counter Limit 21  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level22,         /**< \brief Error Counter Limit 22  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level23,         /**< \brief Error Counter Limit 23  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level24,         /**< \brief Error Counter Limit 24  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level25,         /**< \brief Error Counter Limit 25  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level26,         /**< \brief Error Counter Limit 26  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level27,         /**< \brief Error Counter Limit 27  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level28,         /**< \brief Error Counter Limit 28  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level29,         /**< \brief Error Counter Limit 29  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level30,         /**< \brief Error Counter Limit 30  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level31,         /**< \brief Error Counter Limit 31  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level32,         /**< \brief Error Counter Limit 32  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level33,         /**< \brief Error Counter Limit 33  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level34,         /**< \brief Error Counter Limit 34  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level35,         /**< \brief Error Counter Limit 35  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level36,         /**< \brief Error Counter Limit 36  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level37,         /**< \brief Error Counter Limit 37  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level38,         /**< \brief Error Counter Limit 38  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level39,         /**< \brief Error Counter Limit 39  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level40,         /**< \brief Error Counter Limit 40  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level41,         /**< \brief Error Counter Limit 41  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level42,         /**< \brief Error Counter Limit 42  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level43,         /**< \brief Error Counter Limit 43  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level44,         /**< \brief Error Counter Limit 44  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level45,         /**< \brief Error Counter Limit 45  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level46,         /**< \brief Error Counter Limit 46  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level47,         /**< \brief Error Counter Limit 47  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level48,         /**< \brief Error Counter Limit 48  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level49,         /**< \brief Error Counter Limit 49  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level50,         /**< \brief Error Counter Limit 50  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level51,         /**< \brief Error Counter Limit 51  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level52,         /**< \brief Error Counter Limit 52  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level53,         /**< \brief Error Counter Limit 53  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level54,         /**< \brief Error Counter Limit 54  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level55,         /**< \brief Error Counter Limit 55  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level56,         /**< \brief Error Counter Limit 56  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level57,         /**< \brief Error Counter Limit 57  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level58,         /**< \brief Error Counter Limit 58  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level59,         /**< \brief Error Counter Limit 59  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level60,         /**< \brief Error Counter Limit 60  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level61,         /**< \brief Error Counter Limit 61  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level62,         /**< \brief Error Counter Limit 62  */
    IfxPmsEvr_SecondaryVoltageErrorCounter_level63          /**< \brief Error Counter Limit 63  */
} IfxPmsEvr_SecondaryVoltageErrorCounter;

/** \brief ADC result for the generating Alarm declared in Ifx_PMS.EVR.MONFILT
 */
typedef enum
{
    IfxPmsEvr_SupplyFilter_eachConversionResult    = 0,    /**< \brief Each conversion result is compared with threshold to generate alarm */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult0 = 1,    /**< \brief A moving mean average of consecutive 0 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult1,        /**< \brief A moving mean average of consecutive 1 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult2,        /**< \brief A moving mean average of consecutive 2 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult3,        /**< \brief A moving mean average of consecutive 3 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult4,        /**< \brief A moving mean average of consecutive 4 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult5,        /**< \brief A moving mean average of consecutive 5 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult6,        /**< \brief A moving mean average of consecutive 6 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult7,        /**< \brief A moving mean average of consecutive 7 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult8,        /**< \brief A moving mean average of consecutive 8 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult9,        /**< \brief A moving mean average of consecutive 9 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult10,       /**< \brief A moving mean average of consecutive 10 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult11,       /**< \brief A moving mean average of consecutive 11 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult12,       /**< \brief A moving mean average of consecutive 12 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult13,       /**< \brief A moving mean average of consecutive 13 ADC results  */
    IfxPmsEvr_SupplyFilter_avgAdcConversionResult14        /**< \brief A moving mean average of consecutive 14 ADC results  */
} IfxPmsEvr_SupplyFilter;

/** \brief Controls the voltage supply Type
 */
typedef enum
{
    IfxPmsEvr_SupplyMode_evrc  = 0,  /**< \brief select EVRC regulator or VDD Supply */
    IfxPmsEvr_SupplyMode_evr33 = 1,  /**< \brief select EVR33 regulator or VDDP3 Supply */
    IfxPmsEvr_SupplyMode_swd   = 2,  /**< \brief select  external VEXT suppy watchdog */
    IfxPmsEvr_SupplyMode_evrpr = 3,  /**< \brief select EVRPR or VDDPD supply */
    IfxPmsEvr_SupplyMode_vddm  = 4,  /**< \brief VDDM ADC Supply */
    IfxPmsEvr_SupplyMode_sb    = 5   /**< \brief EVR Standby Supply or VEVRSB supply */
} IfxPmsEvr_SupplyMode;

/** \brief Monitoring underVoltage for all bitfields defined
 * in Ifx_PMS.EVR.MONCTRL register for undervoltage monitoring
 */
typedef enum
{
    IfxPmsEvr_UnderVoltageMonitoring_inactive                         = 0, /**< \brief Under-Voltage Monitoring inactive */
    IfxPmsEvr_UnderVoltageMonitoring_lowToHighVoltageTransition       = 1, /**< \brief under-Voltage event is generated when threshold is crossed in lower to higher voltage transition */
    IfxPmsEvr_UnderVoltageMonitoring_highToLowVoltageTransition       = 2, /**< \brief Under-Voltage event is generated when threshold is crossed in higher to lower voltage transition */
    IfxPmsEvr_UnderVoltageMonitoring_eitherDirectionVoltageTransition = 3  /**< \brief Under-Voltage event is generated when threshold is crossed in either direction */
} IfxPmsEvr_UnderVoltageMonitoring;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief Step down regulator register configuration.
 */
typedef struct
{
    volatile void *regAddr;       /**< \brief Register Address to be updated. */
    uint32         value;         /**< \brief Register value to be updated. Range: 0 to 0xFFFFFFFF */
    uint32         mask;          /**< \brief Mask to select the bit fields to be updated. Range: 0 to 0xFFFFFFFF */
} IfxPmsEvr_StepDownRegulatorRegConfig;

/** \brief Initialization sequence phase configuration.
 */
typedef struct
{
    uint8                                           numOfRegisters;    /**< \brief Number of registers to process in this phase. Range: 0 to 0xFF */
    IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;		   /**< \brief Pointer to an array of register configurations for this phase. */
    float32                                         waitInSecs;		   /**< \brief Waiting time in seconds for this phase to complete. */
} IfxPmsEvr_initSequencePhase;

/** \brief Register validation configuration.
 */
typedef struct
{
    uint8                                           numOfRegisters;    /**< \brief Number of registers to be validated. Range: 0 to 0xFF */
    IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;		   /**< \brief Pointer to an step down regulator register configuration for validation. */
} IfxPmsEvr_checkRegConfig;

/** \brief Initialization sequence configuration.
 */
typedef struct
{
    uint8                                  numOfPhases;				 	/**< \brief Number of initialization phases in the sequence. Range: 0 to 0xFF */
    IFX_CONST IfxPmsEvr_initSequencePhase *phaseConfig;					/**< \brief Pointer to an array of phase configurations for the initialization sequence. */
} IfxPmsEvr_initSequence;

/** \addtogroup IfxLld_Pms_Std_Evr_Over-Voltage
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the over-voltage monitoring mode for a specified supply.
 *
 * \param[inout] pms    Pointer to the base address of PMS registers.
 * \param[in]    mode   Specifies the over-voltage monitoring mode.
 * 					    Range: \ref IfxPmsEvr_OverVoltageMonitoring
 * \param[in]    supply Specifies the supply mode to configure.
 * 					    Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setOverVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_OverVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the secondary over-voltage threshold level for a specified supply mode.
 *
 * \param[inout] pms            Pointer to the base address of PMS registers.
 * \param[in]    thresholdLevel Over-voltage monitoring threshold level of the respective regulator output or supply, in millivolts.
 * \param[in]    supply         Specifies the supply mode to configure.
 * 							    Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsEvr_setSecondaryOverVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the blanking filter delay for the PMS EVR module.
 *
 * \param[inout] pms   Pointer to the base address of PMS registers.
 * \param[in]    delay Blanking filter delay value in milliseconds.
 *                     Range: 0 to 0xD
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_configureBlankingFilterDelay(Ifx_PMS *pms, uint8 delay);

/**
 * \brief Enables the synchronization output to synchronize the external SMPS regulator with the internal EVRC regulator.
 *
 * \param[inout] pms     Pointer to the base address of PMS registers.
 * \param[in]    enabled Boolean flag to enable or disable DC-DC synchronization.
 * 					     Range: TRUE  DC-DC Synchronisation signal available.
 * 					  	        FALSE DC-DC Synchronisation signal not available.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_enableDcdcSynchronisation(Ifx_PMS *pms, boolean enabled);

/**
 * \brief Enables specified interrupts for the PMS module.
 *
 * \param[inout] pms           Pointer to the base address of PMS registers.
 * \param[in]    interruptType The type of interrupt to be enabled.
 * 							   Range: \ref IfxPmsEvr_EnableInterrupt
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_enableInterrupts(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType);

/**
 * \brief Enables or disables the wakeup functionality on VEXT supply ramp-up after the blanking filter time has expired.
 *
 * \param[inout] pms     Pointer to the base address of PMS registers.
 * \param[in]    enabled Boolean flag to enable or disable the wakeup on VEXT supply ramp-up.
 * 					     Range: TRUE  Wake-up on VEXT supply ramp-down disabled. Blanking filter configuration has no effect.
 *						        FALSE Standby Wake-up on VEXT supply ramp-up is enabled after blanking filter expiry.
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_enableWakeupOnVextSupplyRampUp(Ifx_PMS *pms, boolean enabled);

/**
 * \brief Fine trims the EVR clock frequency to 100MHz using the provided trim value.
 *
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    trimValue The fine trim value to be applied to the EVR clock oscillator.
 *                         Range: Supported bits combination.
 *                         		  0x0  0    MHz
 *                         		  0x1F 3.65 MHz
 *                         		  0x3F 7.3  MHz
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_fineTrimEvrClock(Ifx_PMS *pms, uint8 trimValue);

/**
 * \brief Sets the maximum frequency spreading threshold for the PMS module.
 *
 * \param[inout] pms            Pointer to the base address of PMS registers.
 * \param[in]    thresholdLevel Maximum frequency spreading value.
 * 							    Range: 0x0 no frequency spreading activated
 * 							           0x1 SDSWPRDNOM - (SDSWPRDNOM+2) switching period spread
 * 							           0x2 (SDSWPRDNOM-2) - (SDSWPRDNOM+2) switching period spread
 * 							           0x3 (SDSWPRDNOM-2) - (SDSWPRDNOM+4) switching period spread
 * 							           0x4 (SDSWPRDNOM-4) - (SDSWPRDNOM+4) switching period spread
 * 							           0x5 (SDSWPRDNOM-4) - (SDSWPRDNOM+6) switching period spread
 * 							           0x6 (SDSWPRDNOM-6) - (SDSWPRDNOM+6) switching period spread
 * 							           0x7 (SDSWPRDNOM-6) - (SDSWPRDNOM+8) switching period spread
 * 							           0x8 (SDSWPRDNOM-8) - (SDSWPRDNOM+8) switching period spread
 * 							           0x9 (SDSWPRDNOM-8) - (SDSWPRDNOM+10) switching period spread
 * 							           0xA (SDSWPRDNOM-10) - (SDSWPRDNOM+10) switching period
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setFrequencySpreadThreshold(Ifx_PMS *pms, uint16 thresholdLevel);

/**
 * \brief Sets the NMOS level for the PMS EVR module.
 *
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    nmosLevel Boolean value indicating the NMOS level to be set.
 *						   Range: TRUE  Set MOSFET in LOW state.
 *						          FALSE Set MOSFET in TRISTATE.
 * \retval None
 */
#ifndef DEVICE_TC33X
IFX_INLINE void IfxPmsEvr_setNmosLevel(Ifx_PMS *pms, boolean nmosLevel);

/**
 * \brief Configures the state of P channel MOSFET driver during power-up and power-down phases.
 *
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    pmosLevel The desired state of the P channel MOSFET driver.
 *                         Range: TRUE  Set MOSFET in TRISTATE.
 *                                FALSE Set MOSFET in LOW state.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setPmosLevel(Ifx_PMS *pms, boolean pmosLevel);

/**
 * \brief Sets the regulator switching frequency in Hz (100MHz/samplingFactor).
 *
 * \param[inout] pms            Pointer to the base address of PMS registers.
 * \param[in]    samplingFactor Over-sampling factor used to calculate the switching frequency.
 *								Range: 0x37 - 1.82 MHz (100 MHz/(54+1)) SMPS switching frequency.
 *									   0x7D - 0.8 MHz (100 MHz/(124+1)) SMPS switching frequency.
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setRegulatorSwitchingFrequency(Ifx_PMS *pms, uint16 samplingFactor);
#endif

/**
 * \brief Sets the reset trim value for the specified supply mode.
 * 
 * \param[inout] pms 			Pointer to the base address of PMS registers.
 * \param[in]    resetTrimValue The reset trim value to be set (in millivolts).
 * \param[in]    supply 		The supply mode to configure.
 * 								Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setResetTrimValueMv(Ifx_PMS *pms, float32 resetTrimValue, IfxPmsEvr_SupplyMode supply);

/**
 * \brief Sets the output voltage level of the step-down regulator.
 *
 * \param[inout] pms         Pointer to the base address of PMS registers.
 * \param[in]    outputLevel The desired output voltage level of the step-down regulator.
 *                           Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setSdRegulatorOutputLevel(Ifx_PMS *pms, uint8 outputLevel);

/**
 * \brief Sets the primary ADC trim value for the SD regulator voltage.
 * 
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    trimValue The trim value to be applied.
 * 						   Range: \ref IfxPmsEvr_PrimaryAdcTrimValue
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setSdRegulatorPrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue);

/**
 * \brief Configures the specified DLMU RAM block to enter Standby Mode.
 *
 * \param[inout] pms      Pointer to the base address of PMS registers.
 * \param[in]    ramBlock DLMU RAM block to be set in Standby Mode.
 * 						  Range: Supported bits combination.
 * 						  		 0x0 Standby RAM is not supplied.
 * 						  		 0x1 Standby RAM (CPU0 dLMU RAM Lower Half) is supplied.
 * 						 		 0x2 Standby RAM (CPU0 dLMU RAM) is supplied.
 * 						  		 0x4 Reserved.
 * 						         0x7 Reserved.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setStandbyRamSupply(Ifx_PMS *pms, uint8 ramBlock);

/**
 * \brief Sets the switching frequency division factor for external synchronization.
 *
 * \param[inout] pms     Pointer to the base address of PMS registers.
 * \param[in]    divider Division factor for the switching frequency.
 * 						 Range: \ref IfxPmsEvr_ExtSyncSwitchingFreqDivFactor
 *
 * \retval None
 */
#ifndef DEVICE_TC33X
IFX_INLINE void IfxPmsEvr_setSwitchingFreqDivFactorForExternalsync(Ifx_PMS *pms, IfxPmsEvr_ExtSyncSwitchingFreqDivFactor divider);
#endif

/**
 * \brief Adjusts the fine trim value of the EVR clock oscillator.
 *
 * \param[inout] pms  Pointer to the base address of PMS registers.
 * \param[in]    trim Signed fine trim value for the EVR clock oscillator.
 *             		  Range: Supported bits combination.
 *                           0x0 -  0    MHz
 *                           0x1F - 3.65 MHz
 *                           0x3F - 7.3  MHz
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_signedFineTrimEvrClock(Ifx_PMS *pms, sint8 trimValue);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Filters each conversion result or calculates the average of consecutive ADC results for comparison with a threshold.
 *
 * \param[inout] pms            Pointer to the base address of PMS registers.
 * \param[in]    adcFilterValue Specifies whether to use individual conversion results or an average of consecutive results.
 * 								Range: \ref IfxPmsEvr_SupplyFilter
 * \param[in]    supply         Selects the supply mode to be used for filtering.
 * 								Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsEvr_filterSecondaryConversionResult(Ifx_PMS *pms, IfxPmsEvr_SupplyFilter adcFilterValue, IfxPmsEvr_SupplyMode supply);

/**
 * \brief Get secondray ADC result for respective Voltage supply.
 *
 * \param[in] pms    Pointer to the base address of PMS registers.
 * \param[in] supply Selects the supply mode to be configured for getting secondary Adc result.
 * 					 Range: \ref IfxPmsEvr_SupplyMode
 *
 * \return uint8 last conversion result of the ADC measurement of respective voltage by secondary monitor
 * 				 Range: 0 to 0xFF
 */
IFX_EXTERN uint8 IfxPmsEvr_getSecondaryAdcResult(Ifx_PMS *pms, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_Under-Voltage
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the under-voltage monitoring mode for a specified supply.
 *
 * \param[inout] pms    Pointer to the base address of PMS registers.
 * \param[in]    mode   Mode to be configured
 * 						Range: \ref IfxPmsEvr_UnderVoltageMonitoring
 * \param[in]    supply Specifies the supply type to configure to set under-voltage monitoring mode.
 * 						Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setUnderVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_UnderVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the secondary under-voltage threshold level for a specified supply mode.
 *
 * \param[inout] pms            Pointer to the base address of PMS registers.
 * \param[in]    thresholdLevel Under-voltage threshold level in millivolts (mV).
 *                              Range: \ref IfxPmsEvr_SupplyMode
 * \param[in]    supply         Supply mode selector
 * 							    Range: \ref IfxPmsEvr_SupplyMode
 *
 * \retval None
 */
IFX_EXTERN void IfxPmsEvr_setSecondaryUnderVoltageThresholdMv(Ifx_PMS *pms, float32 thresholdLevel, IfxPmsEvr_SupplyMode supply);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_EVRC
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the Reset Trigger signal for the EVRC.
 *
 * \param[inout] pms         Pointer to the base address of PMS registers.
 * \param[in]    enableReset Boolean flag to enable or disable the reset trigger signal.
 *                           Range: TRUE  No reset trigger signal is generated and forwarded to the SCU,
 *                           			  by primary monitor depending on the selected reset trim value.
 *                        		    FALSE A reset trigger signal is generated and forwarded to the SCU,
 *                        		    	  by primary monitor depending on the selected reset trim value.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_evrcResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/**
 * \brief Converts the average ADCC value to the ADC VDD core voltage.
 *
 * \param[in] averageADCC The average value of PMS_EVRADCSTAT.ADCCV.
 *
 * \retval float32 The computed ADC VDD core voltage.
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVddResult(float32 averageADCC);

/**
 * \brief Gets the current operating mode of the EVRC.
 *
 * \param[in] pms Pointer to the base address of PMS registers.
 *
 * \retval IfxPmsEvr_EvrcMode The current mode of the EVRC.
 *             				  Range: \ref IfxPmsEvr_EvrcMode
 */
IFX_INLINE IfxPmsEvr_EvrcMode IfxPmsEvr_getEvrcMode(Ifx_PMS *pms);

/**
 * \brief Gets the EVRC Regulator Voltage status
 *
 * \param[in] pms Pointer to the base address of PMS registers.
 *
 * \retval boolean Status of the Evr Regulator Volatge
 * 				   TRUE  EVRC regulator setpoint voltage is reached and VDD voltage is ok.
 * 				   FALSE EVRC regulator setpoint voltage has not been reached.
 */
IFX_INLINE boolean IfxPmsEvr_getEvrcVoltageRegulator(Ifx_PMS *pms);

/**
 * \brief Retrieves the last conversion result of the ADC measurement of the VDD/EVRC supply by the Primary Monitor.
 *
 * \param[in] pms Pointer to the base address of PMS registers.
 *
 * \retval uint8 The last conversion result of the ADC measurement.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvrcResult(Ifx_PMS *pms);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_EVR33
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Configures the reset trigger signal for EVR33.
 *
 * \param[inout] pms         Pointer to the base address of PMS registers.
 * \param[in]    enableReset Boolean flag to enable or disable the reset trigger signal.
 * 							 Range: TRUE  A reset trigger signal is generated and forwarded to the SCU by primary monitor
 * 							              depending on the selected reset trim value.
 * 							        FALSE No reset trigger signal is generated and forwarded to the SCU by primary monitor
 * 							              depending on the selected reset trim value.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_evr33ResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/**
 * \brief Retrieves the last conversion result of the ADC measurement of the VDDP3 / EVR33 supply by the Primary Monitor.
 *
 * \param[in] pms Pointer to the base address of PMS registers.
 *
 * \retval uint8 The last conversion result of the ADC measurement the VDDP3 / EVR33 supply by the Primary Monitor.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvr33Result(Ifx_PMS *pms);

/**
 * \brief Sets the 3.3 V Regulator Voltage Primary ADC Trim Value.
 *
 * \param[inout] pms       Pointer to the base address of PMS registers.
 * \param[in]    trimValue The trim value to be set. The value is an offset added to the output level.
 *                         Range: \ref IfxPmsEvr_PrimaryAdcTrimValue
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setEvr33PrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue);

/**
 * \brief Sets the VDDP3 output level of the EVR33 LDO regulator.
 *
 * \param[inout] pms         Pointer to the base address of PMS registers.
 * \param[in]    outputLevel Defines the VDDP3 output level of the EVR33 LDO regulator.
 * 					         Range: 0 to 0xFF
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_setEvr33VoltageOutputlevel(Ifx_PMS *pms, uint8 outputLevel);

/** \} */

/** \addtogroup IfxLld_Pms_Std_Evr_SWD
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the last conversion result of the ADC measurement for the external VEXT supply (3.3V / 5V) by the Primary Monitor.
 *
 * \param[in] pms Pointer to the base address of PMS registers.
 *
 * \retval uint8 The last conversion result of the ADC measurement.
 * 				 Range: 0 to 0xFF
 */
IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcSwdResult(Ifx_PMS *pms);

/**
 * \brief Enables or disables the reset trigger signal for SWD.
 *
 * \param[inout] pms         Pointer to the base address of PMS registers.
 * \param[in]    enableReset Boolean flag to enable or disable the reset trigger signal.
 *                           Range: TRUE  No reset trigger signal is generated and forwarded to the SCU,
 *                           			  by primary monitor depending on the selected reset trim value.
 *                                  FALSE A reset trigger signal is generated and forwarded to the SCU,
 *                                  	  by primary monitor depending on the selected reset trim value.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_swdResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Checks if the initialization values of the EVR configuration are correct.
 *
 * \param[in] checkConfig Pointer to the configuration structure containing the initialization values to be checked.
 *
 * \retval boolean TRUE  If the initialization values are correct.
 * 		           FALSE If the initialization values are incorrect.
 */
IFX_INLINE boolean IfxPmsEvr_areInitValuesRight(const IfxPmsEvr_checkRegConfig *const checkConfig);

/**
 * \brief Disables a specified interrupt for the PMS module.
 *
 * \param[inout] pms           Pointer to the base address of PMS registers.
 * \param[in]    interruptType Type of interrupt to disable.
 * 							   Range: \ref IfxPmsEvr_EnableInterrupt
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_disableInterrupt(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType);

/**
 * \brief Converts the average ADC value to the corresponding VDDP3 voltage.
 *
 * \param[in] averageADC33V The average of PMS_EVRSTAT.ADC33V values used for conversion.
 *
 * \retval float32 The calculated VDDP3 voltage.
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVddp3Result(float32 averageADC33V);

/**
 * \brief Computes the VEXT supply voltage based on the average ADC value.
 *
 * \param[in] averageADCSWDV The average of PMS_EVRADCSTAT.ADCSWDV values.
 *
 * \retval float32 The computed VEXT supply voltage in volts.
 */
IFX_INLINE float32 IfxPmsEvr_getAdcVextResult(float32 averageADCSWDV);

/**
 * \brief Runs the initialization sequence for the PMS EVR module using the provided configuration.
 *
 * \param[in] sequence A pointer to the IfxPmsEvr_initSequence instance containing the initialization
 *                     parameters for the PMS EVR module.
 *
 * \retval boolean TRUE	 If the initialization sequence was successfully executed.
  		   	   	   FALSE If an error occurred during the initialization sequence.
 */
IFX_INLINE boolean IfxPmsEvr_runInitSequence(const IfxPmsEvr_initSequence *const sequence);

/**
 * \brief Introduces a delay in seconds for the IfxPmsEvr module.
 *
 * \param[in] waitInSec The duration to wait, specified in seconds.
 *
 * \retval None
 */
IFX_INLINE void IfxPmsEvr_wait(float32 waitInSec);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/
#ifndef DEVICE_TC33X
IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase1Default[];

IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase2Default[];

/** \brief
 */
IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_cfgPhase3Default[];

IFX_EXTERN IFX_CONST IfxPmsEvr_initSequencePhase          IfxPmsEvr_cfgPhasesDefault[];

IFX_EXTERN IFX_CONST IfxPmsEvr_initSequence               IfxPmsEvr_cfgSequenceDefault;

IFX_EXTERN IFX_CONST IfxPmsEvr_checkRegConfig             IfxPmsEvr_checkRegCfgDefault;

IFX_EXTERN IFX_CONST IfxPmsEvr_StepDownRegulatorRegConfig IfxPmsEvr_checkRegValuesDefault[];
#endif
/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE boolean IfxPmsEvr_areInitValuesRight(const IfxPmsEvr_checkRegConfig *const checkConfig)
{
    boolean allRight = TRUE;
    sint32  regCfgCount;

    if (PMS_EVRSTAT.B.EVRC == 1U)
    {
        for (regCfgCount = 0; regCfgCount < checkConfig->numOfRegisters; regCfgCount++)
        {
            uint32                                      regVal;
            const IfxPmsEvr_StepDownRegulatorRegConfig *regConfig = &checkConfig->regConfig[regCfgCount];
            regVal  = (*((volatile uint32 *)regConfig->regAddr));
            regVal &= regConfig->mask;

            if (regVal != regConfig->value)
            {
                allRight = FALSE;
            }
        }

        /*Check if EVRSTAT.SDVOK is set*/
        if (allRight == TRUE)
        {
            if (PMS_EVRSTAT.B.SDVOK != 1)
            {
                allRight = FALSE;
            }
        }
    }

    return allRight;
}


IFX_INLINE void IfxPmsEvr_configureBlankingFilterDelay(Ifx_PMS *pms, uint8 delay)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.BLNKFIL = delay;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_disableInterrupt(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    uint32 mask = (1U << interruptType);
    pms->PMSIEN.U &= (~mask);

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableDcdcSynchronisation(Ifx_PMS *pms, boolean enabled)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR5.B.DCDCSYNCO = enabled;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableInterrupts(Ifx_PMS *pms, IfxPmsEvr_EnableInterrupt interruptType)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSIEN.U |= (1U << interruptType);

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_enableWakeupOnVextSupplyRampUp(Ifx_PMS *pms, boolean enabled)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.PWRWKEN = enabled;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_evr33ResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRRSTCON.B.BPRST33OFF = 1;
    pms->EVRRSTCON.B.RST33OFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_evrcResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRRSTCON.B.BPRSTCOFF = 1;
    pms->EVRRSTCON.B.RSTCOFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_fineTrimEvrClock(Ifx_PMS *pms, uint8 trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVROSCCTRL.B.OSCFTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE float32 IfxPmsEvr_getAdcVddResult(float32 averageADCC)
{
    float32 vddVoltage = 0;
    vddVoltage = (IFXPMSEVR_ADC_VDD_LSB * averageADCC + 0.7125f);
    return vddVoltage;
}


IFX_INLINE float32 IfxPmsEvr_getAdcVddp3Result(float32 averageADC33V)
{
    float32 vddp3Voltage = 0;
    vddp3Voltage = (IFXPMSEVR_ADC_VDDP3_LSB * averageADC33V + 0.9375f);
    return vddp3Voltage;
}


IFX_INLINE float32 IfxPmsEvr_getAdcVextResult(float32 averageADCSWDV)
{
    float32 vextVoltage = 0;
    vextVoltage = (IFXPMSEVR_ADC_VEXT_LSB * averageADCSWDV + 1.050f);
    return vextVoltage;
}


IFX_INLINE IfxPmsEvr_EvrcMode IfxPmsEvr_getEvrcMode(Ifx_PMS *pms)
{
    return (IfxPmsEvr_EvrcMode)pms->EVRSTAT.B.EVRCMOD;
}


IFX_INLINE boolean IfxPmsEvr_getEvrcVoltageRegulator(Ifx_PMS *pms)
{
    return (boolean)pms->EVRSTAT.B.SDVOK;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvr33Result(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADC33V;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcEvrcResult(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADCCV;
}


IFX_INLINE uint8 IfxPmsEvr_getPrimaryAdcSwdResult(Ifx_PMS *pms)
{
    return pms->EVRADCSTAT.B.ADCSWDV;
}


#if defined(__TASKING__)
#pragma optimize L
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC optimize ("-O2")
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC optimize ("-O2")
#endif
IFX_INLINE boolean IfxPmsEvr_runInitSequence(const IfxPmsEvr_initSequence *const sequence)
{
    boolean                                     pmsInitDone    = TRUE;
    uint32                                      regVal;
    uint16                                      endinitSfty_pw = IfxScuWdt_getGlobalSafetyEndinitPasswordInline();
    const IfxPmsEvr_initSequencePhase          *phaseConfig;
    const IfxPmsEvr_StepDownRegulatorRegConfig *regConfig;

    if (PMS_EVRSTAT.B.EVRC == 1U)
    {
        /*Loop through each configured phase*/
        for (phaseConfig = &sequence->phaseConfig[0];
             phaseConfig < &sequence->phaseConfig[sequence->numOfPhases];
             phaseConfig++)
        {
            IfxScuWdt_clearGlobalSafetyEndinitInline(endinitSfty_pw);

            /*Loop through each register which is configured in the phase configuration*/
            for (regConfig = &phaseConfig->regConfig[0];
                 regConfig < &phaseConfig->regConfig[phaseConfig->numOfRegisters];
                 regConfig++)
            {
                regVal  = (*((volatile uint32 *)regConfig->regAddr));
                regVal &= ~regConfig->mask;
                regVal |= regConfig->value;

                /** During normal running one must wait for the LCK bit.
                 * However, for this function, as this is used only with CPU0 startup no wait required
                 */
                (*((volatile uint32 *)regConfig->regAddr)) = regVal; /*Write to the physical register*/
            }

            PMS_EVRSDCTRL0.B.UP = 1;
            IfxScuWdt_setGlobalSafetyEndinitInline(endinitSfty_pw);
            IfxPmsEvr_wait(phaseConfig->waitInSecs);        // wait for configured time
            /* wait for the UP bit*/
            sint32 timeoutCount = IFXPMSEVR_CTRL_UP_WAIT_TIMEOUTCOUNT;

            /*Now, wait for the UP bit at EVRSDCTRL0 is reset, which is to indicate the configurations are done*/
            do
            {
                if (--timeoutCount <= 0)
                {
                    pmsInitDone = FALSE;
                    break;
                }
            } while (PMS_EVRSDCTRL0.B.UP == 1);   
        }
    }

    /*return the status*/
    return pmsInitDone;
}
#if defined(__TASKING__)
#pragma endoptimize
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC reset_options
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC reset_options
#endif


IFX_INLINE void IfxPmsEvr_setEvr33PrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRTRIM.B.EVR33VOUTTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setEvr33VoltageOutputlevel(Ifx_PMS *pms, uint8 outputLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRTRIM.B.EVR33VOUTSEL = outputLevel;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setFrequencySpreadThreshold(Ifx_PMS *pms, uint16 thresholdLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRSDCTRL0.B.SDFREQSPRD = thresholdLevel;
    pms->EVRSDCTRL0.B.UP         = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}

#ifndef DEVICE_TC33X
IFX_INLINE void IfxPmsEvr_setNmosLevel(Ifx_PMS *pms, boolean nmosLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.NGOFF = nmosLevel;
    pms->EVRSDCTRL0.B.UP    = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}
#endif

IFX_INLINE void IfxPmsEvr_setOverVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_OverVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply)
{
    uint16          passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_MONCTRL tempMONCTRL;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempMONCTRL.U = pms->MONCTRL.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempMONCTRL.B.EVRCOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempMONCTRL.B.EVR33OVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempMONCTRL.B.SWDOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempMONCTRL.B.PREOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempMONCTRL.B.VDDMOVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempMONCTRL.B.SBOVMOD = mode;
        break;
    }

    pms->MONCTRL.U = tempMONCTRL.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}

#ifndef DEVICE_TC33X
IFX_INLINE void IfxPmsEvr_setPmosLevel(Ifx_PMS *pms, boolean pmosLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.PGOFF = pmosLevel;
    pms->EVRSDCTRL0.B.UP    = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setRegulatorSwitchingFrequency(Ifx_PMS *pms, uint16 samplingFactor)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRSDCTRL0.B.SDFREQ = samplingFactor;
    pms->EVRSDCTRL0.B.UP     = 1;

    IfxScuWdt_setSafetyEndinit(passwd);
}
#endif

IFX_INLINE void IfxPmsEvr_setResetTrimValueMv(Ifx_PMS *pms, float32 resetTrimValue, IfxPmsEvr_SupplyMode supply)
{
    uint16            passwd = IfxScuWdt_getSafetyWatchdogPassword();

    Ifx_PMS_EVRRSTCON tempRSTCON;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempRSTCON.U = pms->EVRRSTCON.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempRSTCON.B.RSTCTRIM = ((resetTrimValue - 712.5f) / 5);
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempRSTCON.B.RST33TRIM = ((resetTrimValue - 937.5f) / 15);
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempRSTCON.B.RSTSWDTRIM = ((resetTrimValue - 1050) / 20);
        break;
    default:
        break;
    }

    pms->EVRRSTCON.U = tempRSTCON.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setSdRegulatorOutputLevel(Ifx_PMS *pms, uint8 outputLevel)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->EVRTRIM.B.SDVOUTSEL = outputLevel;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setSdRegulatorPrimaryAdcTrimValue(Ifx_PMS *pms, IfxPmsEvr_PrimaryAdcTrimValue trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRTRIM.B.SDVOUTTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_setStandbyRamSupply(Ifx_PMS *pms, uint8 ramBlock)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);

    pms->PMSWCR0.B.STBYRAMSEL = ramBlock;

    IfxScuWdt_setSafetyEndinit(passwd);
}

#ifndef DEVICE_TC33X
IFX_INLINE void IfxPmsEvr_setSwitchingFreqDivFactorForExternalsync(Ifx_PMS *pms, IfxPmsEvr_ExtSyncSwitchingFreqDivFactor divider)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRSDCTRL7.B.SYNCDIVFAC = divider;
    IfxScuWdt_setSafetyEndinit(passwd);
}
#endif

IFX_INLINE void IfxPmsEvr_setUnderVoltageMonitoringMode(Ifx_PMS *pms, IfxPmsEvr_UnderVoltageMonitoring mode, IfxPmsEvr_SupplyMode supply)
{
    uint16          passwd = IfxScuWdt_getSafetyWatchdogPassword();
    Ifx_PMS_MONCTRL tempMONCTRL;
    IfxScuWdt_clearSafetyEndinit(passwd);
    tempMONCTRL.U = pms->MONCTRL.U;

    switch (supply)
    {
    case IfxPmsEvr_SupplyMode_evrc:
        tempMONCTRL.B.EVRCUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evr33:
        tempMONCTRL.B.EVR33UVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_swd:
        tempMONCTRL.B.SWDUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_evrpr:
        tempMONCTRL.B.PREUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_vddm:
        tempMONCTRL.B.VDDMUVMOD = mode;
        break;
    case IfxPmsEvr_SupplyMode_sb:
        tempMONCTRL.B.SBUVMOD = mode;
        break;
    }

    pms->MONCTRL.U = tempMONCTRL.U;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_signedFineTrimEvrClock(Ifx_PMS *pms, sint8 trimValue)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVROSCCTRL.B.OSCFPTRIM = trimValue;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_swdResetTriggerSignalConfig(Ifx_PMS *pms, boolean enableReset)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();

    IfxScuWdt_clearSafetyEndinit(passwd);
    pms->EVRRSTCON.B.BPRSTSWDOFF = 1;
    pms->EVRRSTCON.B.RSTSWDOFF   = enableReset;

    IfxScuWdt_setSafetyEndinit(passwd);
}


IFX_INLINE void IfxPmsEvr_wait(float32 waitInSec)
{
    uint32 stmCount      = (uint32)((float32)33000000UL * waitInSec);
    uint32 stmCountBegin = STM0_TIM0.U;     /* it is necessary to get this value to have minimum 100uS delay in subsequent CPU start */

    while ((uint32)(STM0_TIM0.U - stmCountBegin) < stmCount)
    {
        /* There is no need to check overflow of the STM timer.
         * When counter after overflow subtracted with counter before overflow,
         * the subtraction result will be as expected, as long as both are unsigned 32 bits
         * eg: stmCountBegin= 0xFFFFFFFE (before overflow)
         *     stmCountNow = 0x00000002 (before overflow)
         *     diff= stmCountNow - stmCountBegin = 4 as expected.*/
    }
}


#endif /* IFXPMSEVR_H */
