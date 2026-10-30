/**
 * \file IfxMsc.h
 * \brief MSC  basic functionality
 * \ingroup IfxLld_Msc
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
 * \defgroup IfxLld_Msc_Std_Enum Enumerations
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Config_Flags Configure Flags
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Set_Command_Target Set Command Target
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Set_Data Set Data
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Get_Data Get Data
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Enable_Module Enable Module
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Reset_Module Reset Module
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Baud_Calculator Baud Calculator
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Msc_Std
 * \defgroup IfxLld_Msc_Std_Module Module Functions
 * \ingroup IfxLld_Msc_Std
 */

#ifndef IFXMSC_H
#define IFXMSC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxMsc_cfg.h"
#include "Scu/Std/IfxScuCcu.h"
#include "Scu/Std/IfxScuWdt.h"
#include "_PinMap/IfxMsc_PinMap.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Msc_Std_Enum
 * \{ */
/** \brief Enable SRL/SRH Active Phase Selection Bit\n
 * Definition in Ifx_MSC.DSC.B.ENSELH and Ifx_MSC.DSC.B.ENSELL
 */
typedef enum
{
    IfxMsc_ActivePhaseSelection_none     = 0, /**< \brief No selection bit inserted */
    IfxMsc_ActivePhaseSelection_lowLevel = 1  /**< \brief Low level selection bit inserted */
} IfxMsc_ActivePhaseSelection;

/** \brief Asynchronous Block Configuration Register - Asynchronous Block Bypass\n
 * Definition in Ifx_MSC.ABC.B.ABB
 */
typedef enum
{
    IfxMsc_AsynchronousBlock_bypassed   = 0, /**< \brief Asynchronous block and the n-divider of the MSC downstream path are bypassed and are disabled */
    IfxMsc_AsynchronousBlock_noBypassed = 1  /**< \brief Asynchronous block and the n-divider of the MSC downstream path are active */
} IfxMsc_AsynchronousBlock;

/** \brief Output Control Register - Chip Selection Line Polarity\n
 * Definition in Ifx_MSC.OCR.B.CSLP
 */
typedef enum
{
    IfxMsc_ChipSelectActiveState_high = 0,  /**< \brief EN[3:0] and ENL,ENH,ENC polarities are identical */
    IfxMsc_ChipSelectActiveState_low  = 1   /**< \brief EN[3:0] and ENL,ENH,ENC polarities are inverted */
} IfxMsc_ChipSelectActiveState;

/** \brief Asynchronous Block Configuration Register - Clock Select\n
 * Definition in Ifx_MSC.ABC.B.CLKSEL
 */
typedef enum
{
    IfxMsc_ClockSelect_noClock = 0,  /**< \brief no clock source for the ABRA block */
    IfxMsc_ClockSelect_fper    = 1   /**< \brief f_PER is the  clock source for the ABRA block */
} IfxMsc_ClockSelect;

/** \brief Downstream Control Enhanced Register - Command-Data-Command in Data Repetition Mode\n
 * Definition in Ifx_MSC.DSCE.B.CDCM
 */
typedef enum
{
    IfxMsc_CommandDataCommandRepetitionMode_disabled = 0,  /**< \brief Disables the automatic insertion of data */
    IfxMsc_CommandDataCommandRepetitionMode_enabled  = 1   /**< \brief Enables the automatic insertion of data */
} IfxMsc_CommandDataCommandRepetitionMode;

/** \brief Interrupt Control Register - Command Frame Interrupt Enable\n
 * Definition in Ifx_MSC.ICR.B.ECIE
 */
typedef enum
{
    IfxMsc_CommandFrameInterrupt_disabled = 0,  /**< \brief Interrupt generation disabled */
    IfxMsc_CommandFrameInterrupt_enabled  = 1   /**< \brief Interrupt generation enabled */
} IfxMsc_CommandFrameInterrupt;

/** \brief Interrupt Control Register - Command Frame Interrupt Node Pointer\n
 * Definition in Ifx_MSC.ICR.B.ECIP
 */
typedef enum
{
    IfxMsc_CommandFrameInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_CommandFrameInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_CommandFrameInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_CommandFrameInterruptNode_SR3           /**< \brief Service request output SR3 selected  */
} IfxMsc_CommandFrameInterruptNode;

/** \brief Number of Bits shifted at command frames\n
 * Definition in Ifx_MSC.DSC.B.NBC
 */
typedef enum
{
    IfxMsc_CommandFrameLength_0 = 0,      /**< \brief No bit shifted */
    IfxMsc_CommandFrameLength_1 = 1,      /**< \brief SRL[0] Shifted */
    IfxMsc_CommandFrameLength_2 = 2,      /**< \brief SRL[1:0] Shifted  */
    IfxMsc_CommandFrameLength_3,          /**< \brief SRL[2:0] Shifted  */
    IfxMsc_CommandFrameLength_4,          /**< \brief SRL[3:0] Shifted  */
    IfxMsc_CommandFrameLength_5,          /**< \brief SRL[4:0] Shifted  */
    IfxMsc_CommandFrameLength_6,          /**< \brief SRL[5:0] Shifted  */
    IfxMsc_CommandFrameLength_7,          /**< \brief SRL[6:0] Shifted  */
    IfxMsc_CommandFrameLength_8,          /**< \brief SRL[7:0] Shifted  */
    IfxMsc_CommandFrameLength_9,          /**< \brief SRL[8:0] Shifted  */
    IfxMsc_CommandFrameLength_10,         /**< \brief SRL[9:0] Shifted  */
    IfxMsc_CommandFrameLength_11,         /**< \brief SRL[10:0] Shifted  */
    IfxMsc_CommandFrameLength_12,         /**< \brief SRL[11:0] Shifted  */
    IfxMsc_CommandFrameLength_13,         /**< \brief SRL[12:0] Shifted  */
    IfxMsc_CommandFrameLength_14,         /**< \brief SRL[13:0] Shifted  */
    IfxMsc_CommandFrameLength_15,         /**< \brief SRL[14:0] Shifted  */
    IfxMsc_CommandFrameLength_16,         /**< \brief SRL[15:0] Shifted  */
    IfxMsc_CommandFrameLength_17 = 17,    /**< \brief SRL[15:0] and SRH[0] Shifted */
    IfxMsc_CommandFrameLength_18 = 18,    /**< \brief SRL[15:0] and SRH[1:0] Shifted  */
    IfxMsc_CommandFrameLength_19,         /**< \brief SRL[15:0] and SRH[2:0] Shifted  */
    IfxMsc_CommandFrameLength_20,         /**< \brief SRL[15:0] and SRH[3:0] Shifted  */
    IfxMsc_CommandFrameLength_21,         /**< \brief SRL[15:0] and SRH[4:0] Shifted  */
    IfxMsc_CommandFrameLength_22,         /**< \brief SRL[15:0] and SRH[5:0] Shifted  */
    IfxMsc_CommandFrameLength_23,         /**< \brief SRL[15:0] and SRH[6:0] Shifted  */
    IfxMsc_CommandFrameLength_24,         /**< \brief SRL[15:0] and SRH[7:0] Shifted  */
    IfxMsc_CommandFrameLength_25,         /**< \brief SRL[15:0] and SRH[8:0] Shifted  */
    IfxMsc_CommandFrameLength_26,         /**< \brief SRL[15:0] and SRH[9:0] Shifted  */
    IfxMsc_CommandFrameLength_27,         /**< \brief SRL[15:0] and SRH[10:0] Shifted  */
    IfxMsc_CommandFrameLength_28,         /**< \brief SRL[15:0] and SRH[11:0] Shifted  */
    IfxMsc_CommandFrameLength_29,         /**< \brief SRL[15:0] and SRH[12:0] Shifted  */
    IfxMsc_CommandFrameLength_30,         /**< \brief SRL[15:0] and SRH[13:0] Shifted  */
    IfxMsc_CommandFrameLength_31,         /**< \brief SRL[15:0] and SRH[14:0] Shifted  */
    IfxMsc_CommandFrameLength_32          /**< \brief SRL[15:0] and SRH[15:0] Shifted  */
} IfxMsc_CommandFrameLength;

/** \brief Downstream Timing Extension Register - Passive Phase Length at Control Frames Extension\n
 * Definition in Ifx_MSC.DSTE.B.PPCE
 */
typedef enum
{
    IfxMsc_ControlFrameExtensionPassivePhaseLength_0 = 0,      /**< \brief Length of Command frames passive phase is  2  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_1,          /**< \brief Length of Command frames passive phase is  3  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_2,          /**< \brief Length of Command frames passive phase is  4  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_3,          /**< \brief Length of Command frames passive phase is  5  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_4,          /**< \brief Length of Command frames passive phase is  6  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_5,          /**< \brief Length of Command frames passive phase is  7  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_6,          /**< \brief Length of Command frames passive phase is  8  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_7,          /**< \brief Length of Command frames passive phase is  9  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_8,          /**< \brief Length of Command frames passive phase is  10  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_9,          /**< \brief Length of Command frames passive phase is  11  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_10,         /**< \brief Length of Command frames passive phase is  12  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_11,         /**< \brief Length of Command frames passive phase is  13  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_12,         /**< \brief Length of Command frames passive phase is  14  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_13,         /**< \brief Length of Command frames passive phase is  15  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_14,         /**< \brief Length of Command frames passive phase is  16  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_15,         /**< \brief Length of Command frames passive phase is  17  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_16,         /**< \brief Length of Command frames passive phase is  18  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_17,         /**< \brief Length of Command frames passive phase is  19  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_18,         /**< \brief Length of Command frames passive phase is  20  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_19,         /**< \brief Length of Command frames passive phase is  21  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_20,         /**< \brief Length of Command frames passive phase is  22  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_21,         /**< \brief Length of Command frames passive phase is  23  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_22,         /**< \brief Length of Command frames passive phase is  24  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_23,         /**< \brief Length of Command frames passive phase is  25  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_24,         /**< \brief Length of Command frames passive phase is  26  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_25,         /**< \brief Length of Command frames passive phase is  27  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_26,         /**< \brief Length of Command frames passive phase is  28  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_27,         /**< \brief Length of Command frames passive phase is  29  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_28,         /**< \brief Length of Command frames passive phase is  30  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_29,         /**< \brief Length of Command frames passive phase is  31  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_30,         /**< \brief Length of Command frames passive phase is  32  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_31,         /**< \brief Length of Command frames passive phase is  33  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_32,         /**< \brief Length of Command frames passive phase is  34  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_33,         /**< \brief Length of Command frames passive phase is  35  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_34,         /**< \brief Length of Command frames passive phase is  36  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_35,         /**< \brief Length of Command frames passive phase is  37  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_36,         /**< \brief Length of Command frames passive phase is  38  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_37,         /**< \brief Length of Command frames passive phase is  39  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_38,         /**< \brief Length of Command frames passive phase is  40  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_39,         /**< \brief Length of Command frames passive phase is  41  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_40,         /**< \brief Length of Command frames passive phase is  42  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_41,         /**< \brief Length of Command frames passive phase is  43  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_42,         /**< \brief Length of Command frames passive phase is  44  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_43,         /**< \brief Length of Command frames passive phase is  45  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_44,         /**< \brief Length of Command frames passive phase is  46  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_45,         /**< \brief Length of Command frames passive phase is  47  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_46,         /**< \brief Length of Command frames passive phase is  48  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_47,         /**< \brief Length of Command frames passive phase is  49  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_48,         /**< \brief Length of Command frames passive phase is  50  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_49,         /**< \brief Length of Command frames passive phase is  51  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_50,         /**< \brief Length of Command frames passive phase is  52  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_51,         /**< \brief Length of Command frames passive phase is  53  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_52,         /**< \brief Length of Command frames passive phase is  54  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_53,         /**< \brief Length of Command frames passive phase is  55  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_54,         /**< \brief Length of Command frames passive phase is  56  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_55,         /**< \brief Length of Command frames passive phase is  57  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_56,         /**< \brief Length of Command frames passive phase is  58  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_57,         /**< \brief Length of Command frames passive phase is  59  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_58,         /**< \brief Length of Command frames passive phase is  60  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_59,         /**< \brief Length of Command frames passive phase is  61  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_60,         /**< \brief Length of Command frames passive phase is  62  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_61,         /**< \brief Length of Command frames passive phase is  63  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_62,         /**< \brief Length of Command frames passive phase is  64  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_63,         /**< \brief Length of Command frames passive phase is  65  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_64,         /**< \brief Length of Command frames passive phase is  66  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_65,         /**< \brief Length of Command frames passive phase is  67  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_66,         /**< \brief Length of Command frames passive phase is  68  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_67,         /**< \brief Length of Command frames passive phase is  69  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_68,         /**< \brief Length of Command frames passive phase is  70  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_69,         /**< \brief Length of Command frames passive phase is  71  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_70,         /**< \brief Length of Command frames passive phase is  72  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_71,         /**< \brief Length of Command frames passive phase is  73  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_72,         /**< \brief Length of Command frames passive phase is  74  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_73,         /**< \brief Length of Command frames passive phase is  75  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_74,         /**< \brief Length of Command frames passive phase is  76  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_75,         /**< \brief Length of Command frames passive phase is  77  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_76,         /**< \brief Length of Command frames passive phase is  78  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_77,         /**< \brief Length of Command frames passive phase is  79  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_78,         /**< \brief Length of Command frames passive phase is  80  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_79,         /**< \brief Length of Command frames passive phase is  81  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_80,         /**< \brief Length of Command frames passive phase is  82  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_81,         /**< \brief Length of Command frames passive phase is  83  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_82,         /**< \brief Length of Command frames passive phase is  84  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_83,         /**< \brief Length of Command frames passive phase is  85  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_84,         /**< \brief Length of Command frames passive phase is  86  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_85,         /**< \brief Length of Command frames passive phase is  87  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_86,         /**< \brief Length of Command frames passive phase is  88  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_87,         /**< \brief Length of Command frames passive phase is  89  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_88,         /**< \brief Length of Command frames passive phase is  90  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_89,         /**< \brief Length of Command frames passive phase is  91  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_90,         /**< \brief Length of Command frames passive phase is  92  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_91,         /**< \brief Length of Command frames passive phase is  93  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_92,         /**< \brief Length of Command frames passive phase is  94  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_93,         /**< \brief Length of Command frames passive phase is  95  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_94,         /**< \brief Length of Command frames passive phase is  96  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_95,         /**< \brief Length of Command frames passive phase is  97  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_96,         /**< \brief Length of Command frames passive phase is  98  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_97,         /**< \brief Length of Command frames passive phase is  99  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_98,         /**< \brief Length of Command frames passive phase is  100  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_99,         /**< \brief Length of Command frames passive phase is  101  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_100,        /**< \brief Length of Command frames passive phase is  102  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_101,        /**< \brief Length of Command frames passive phase is  103  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_102,        /**< \brief Length of Command frames passive phase is  104  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_103,        /**< \brief Length of Command frames passive phase is  105  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_104,        /**< \brief Length of Command frames passive phase is  106  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_105,        /**< \brief Length of Command frames passive phase is  107  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_106,        /**< \brief Length of Command frames passive phase is  108  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_107,        /**< \brief Length of Command frames passive phase is  109  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_108,        /**< \brief Length of Command frames passive phase is  110  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_109,        /**< \brief Length of Command frames passive phase is  111  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_110,        /**< \brief Length of Command frames passive phase is  112  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_111,        /**< \brief Length of Command frames passive phase is  113  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_112,        /**< \brief Length of Command frames passive phase is  114  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_113,        /**< \brief Length of Command frames passive phase is  115  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_114,        /**< \brief Length of Command frames passive phase is  116  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_115,        /**< \brief Length of Command frames passive phase is  117  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_116,        /**< \brief Length of Command frames passive phase is  118  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_117,        /**< \brief Length of Command frames passive phase is  119  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_118,        /**< \brief Length of Command frames passive phase is  120  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_119,        /**< \brief Length of Command frames passive phase is  121  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_120,        /**< \brief Length of Command frames passive phase is  122  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_121,        /**< \brief Length of Command frames passive phase is  123  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_122,        /**< \brief Length of Command frames passive phase is  124  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_123,        /**< \brief Length of Command frames passive phase is  125  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_124,        /**< \brief Length of Command frames passive phase is  126  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_125,        /**< \brief Length of Command frames passive phase is  127  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_126,        /**< \brief Length of Command frames passive phase is  128  */
    IfxMsc_ControlFrameExtensionPassivePhaseLength_127         /**< \brief Length of Command frames passive phase is  129  */
} IfxMsc_ControlFrameExtensionPassivePhaseLength;

/** \brief Downstream Timing Extension Register - Passive Phase Length at Data Frames Extension\n
 * Definition in Ifx_MSC.DSTE.B.PPDE
 */
typedef enum
{
    IfxMsc_DataFrameExtensionPassivePhaseLength_0 = 0,      /**< \brief 0 Additional MSB bits extension of the PPD bit field  */
    IfxMsc_DataFrameExtensionPassivePhaseLength_1,          /**< \brief 1 Additional MSB bits extension of the PPD bit field  */
    IfxMsc_DataFrameExtensionPassivePhaseLength_2,          /**< \brief 2 Additional MSB bits extension of the PPD bit field  */
    IfxMsc_DataFrameExtensionPassivePhaseLength_3           /**< \brief 3 Additional MSB bits extension of the PPD bit field  */
} IfxMsc_DataFrameExtensionPassivePhaseLength;

/** \brief Interrupt Control Register - Data Frame Interrupt Enable\n
 * Definition in Ifx_MSC.ICR.B.EDIE
 */
typedef enum
{
    IfxMsc_DataFrameInterrupt_disabled       = 0, /**< \brief Interrupt generation Disable */
    IfxMsc_DataFrameInterrupt_atLastDataBit  = 1, /**< \brief An interrupt is generated when the last data bit has been shifted out */
    IfxMsc_DataFrameInterrupt_atFirstDataBit = 2  /**< \brief An interrupt is generated when the First data bit has been shifted out */
} IfxMsc_DataFrameInterrupt;

/** \brief Interrupt Control Register - Data Frame Interrupt Node Pointer\n
 * Definition in Ifx_MSC.ICR.B.EDIP
 */
typedef enum
{
    IfxMsc_DataFrameInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_DataFrameInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_DataFrameInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_DataFrameInterruptNode_SR3           /**< \brief Service request output SR3 selected  */
} IfxMsc_DataFrameInterruptNode;

/** \brief Number of SRx[] (x->SRL/SRH) Bits Shifted at Data Frames\n
 * Definition in Ifx_MSC.DSC.B.NDBH and Ifx_MSC.DSC.B.NDBL
 */
typedef enum
{
    IfxMsc_DataFrameLength_0 = 0,    /**< \brief No SRx bit shifted */
    IfxMsc_DataFrameLength_1 = 1,    /**< \brief SRx[0] Shifted */
    IfxMsc_DataFrameLength_2 = 2,    /**< \brief SRx[1:0] Shifted  */
    IfxMsc_DataFrameLength_3,        /**< \brief SRx[2:0] Shifted  */
    IfxMsc_DataFrameLength_4,        /**< \brief SRx[3:0] Shifted  */
    IfxMsc_DataFrameLength_5,        /**< \brief SRx[4:0] Shifted  */
    IfxMsc_DataFrameLength_6,        /**< \brief SRx[5:0] Shifted  */
    IfxMsc_DataFrameLength_7,        /**< \brief SRx[6:0] Shifted  */
    IfxMsc_DataFrameLength_8,        /**< \brief SRx[7:0] Shifted  */
    IfxMsc_DataFrameLength_9,        /**< \brief SRx[8:0] Shifted  */
    IfxMsc_DataFrameLength_10,       /**< \brief SRx[9:0] Shifted  */
    IfxMsc_DataFrameLength_11,       /**< \brief SRx[10:0] Shifted  */
    IfxMsc_DataFrameLength_12,       /**< \brief SRx[11:0] Shifted  */
    IfxMsc_DataFrameLength_13,       /**< \brief SRx[12:0] Shifted  */
    IfxMsc_DataFrameLength_14,       /**< \brief SRx[13:0] Shifted  */
    IfxMsc_DataFrameLength_15,       /**< \brief SRx[14:0] Shifted  */
    IfxMsc_DataFrameLength_16        /**< \brief SRx[15:0] Shifted  */
} IfxMsc_DataFrameLength;

/** \brief Passive Phase Length at Data Frames\n
 * Definition in Ifx_MSC.DSC.B.PPD
 */
typedef enum
{
    IfxMsc_DataFramePassivePhaseLength_2 = 2,      /**< \brief Passive phase length is 2 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_3,          /**< \brief Passive phase length is 3 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_4,          /**< \brief Passive phase length is 4 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_5,          /**< \brief Passive phase length is 5 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_6,          /**< \brief Passive phase length is 6 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_7,          /**< \brief Passive phase length is 7 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_8,          /**< \brief Passive phase length is 8 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_9,          /**< \brief Passive phase length is 9 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_10,         /**< \brief Passive phase length is 10 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_11,         /**< \brief Passive phase length is 11 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_12,         /**< \brief Passive phase length is 12 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_13,         /**< \brief Passive phase length is 13 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_14,         /**< \brief Passive phase length is 14 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_15,         /**< \brief Passive phase length is 15 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_16,         /**< \brief Passive phase length is 16 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_17,         /**< \brief Passive phase length is 17 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_18,         /**< \brief Passive phase length is 18 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_19,         /**< \brief Passive phase length is 19 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_20,         /**< \brief Passive phase length is 20 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_21,         /**< \brief Passive phase length is 21 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_22,         /**< \brief Passive phase length is 22 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_23,         /**< \brief Passive phase length is 23 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_24,         /**< \brief Passive phase length is 24 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_25,         /**< \brief Passive phase length is 25 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_26,         /**< \brief Passive phase length is 26 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_27,         /**< \brief Passive phase length is 27 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_28,         /**< \brief Passive phase length is 28 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_29,         /**< \brief Passive phase length is 29 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_30,         /**< \brief Passive phase length is 30 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_31,         /**< \brief Passive phase length is 31 tFCL  */
    IfxMsc_DataFramePassivePhaseLength_32          /**< \brief Passive phase length is 32 tFCL  */
} IfxMsc_DataFramePassivePhaseLength;

/** \brief Divider mode
 */
typedef enum
{
    IfxMsc_DividerMode_normal     = 1, /**< \brief divider mode is normal */
    IfxMsc_DividerMode_fractional = 2  /**< \brief divider mode is fractional */
} IfxMsc_DividerMode;

/** \brief Emergency Stop Register - Emergency stop feature Enable or Disable - SRL and SRH\n
 * Definition in Ifx_MSC.ESR
 */
typedef enum
{
    IfxMsc_EmergencyStop_disabled = 0,  /**< \brief Emergency stop feature for SRx bit is Disabled */
    IfxMsc_EmergencyStop_enabled  = 1   /**< \brief Emergency stop feature for SRx bit is Enabled */
} IfxMsc_EmergencyStop;

/** \brief Downstream Control Enhanced Register - Extension Enable\n
 * Definition in Ifx_MSC.DSCE.B.NDBLE
 */
typedef enum
{
    IfxMsc_Extension_disabled = 0,  /**< \brief Disables the extension bit fields */
    IfxMsc_Extension_enabled  = 1   /**< \brief Enables the extension bit fields */
} IfxMsc_Extension;

/** \brief Downstream Control Enhanced Register - Injection Position of the Pin 0 and 1 Signal\n
 * Definition in Ifx_MSC.DSCE.B.INJPOSP0 and Ifx_MSC.DSCE.B.INJPOSP1
 */
typedef enum
{
    IfxMsc_ExternalBitInjectionPosition_0 = 0,      /**< \brief Injected external bit is at Position 0 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_1,          /**< \brief Injected external bit is at Position 1 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_2,          /**< \brief Injected external bit is at Position 2 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_3,          /**< \brief Injected external bit is at Position 3 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_4,          /**< \brief Injected external bit is at Position 4 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_5,          /**< \brief Injected external bit is at Position 5 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_6,          /**< \brief Injected external bit is at Position 6 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_7,          /**< \brief Injected external bit is at Position 7 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_8,          /**< \brief Injected external bit is at Position 8 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_9,          /**< \brief Injected external bit is at Position 9 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_10,         /**< \brief Injected external bit is at Position 10 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_11,         /**< \brief Injected external bit is at Position 11 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_12,         /**< \brief Injected external bit is at Position 12 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_13,         /**< \brief Injected external bit is at Position 13 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_14,         /**< \brief Injected external bit is at Position 14 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_15,         /**< \brief Injected external bit is at Position 15 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_16,         /**< \brief Injected external bit is at Position 16 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_17,         /**< \brief Injected external bit is at Position 17 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_18,         /**< \brief Injected external bit is at Position 18 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_19,         /**< \brief Injected external bit is at Position 19 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_20,         /**< \brief Injected external bit is at Position 20 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_21,         /**< \brief Injected external bit is at Position 21 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_22,         /**< \brief Injected external bit is at Position 22 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_23,         /**< \brief Injected external bit is at Position 23 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_24,         /**< \brief Injected external bit is at Position 24 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_25,         /**< \brief Injected external bit is at Position 25 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_26,         /**< \brief Injected external bit is at Position 26 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_27,         /**< \brief Injected external bit is at Position 27 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_28,         /**< \brief Injected external bit is at Position 28 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_29,         /**< \brief Injected external bit is at Position 29 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_30,         /**< \brief Injected external bit is at Position 30 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_31,         /**< \brief Injected external bit is at Position 31 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_32,         /**< \brief Injected external bit is at Position 32 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_33,         /**< \brief Injected external bit is at Position 33 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_34,         /**< \brief Injected external bit is at Position 34 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_35,         /**< \brief Injected external bit is at Position 35 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_36,         /**< \brief Injected external bit is at Position 36 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_37,         /**< \brief Injected external bit is at Position 37 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_38,         /**< \brief Injected external bit is at Position 38 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_39,         /**< \brief Injected external bit is at Position 39 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_40,         /**< \brief Injected external bit is at Position 40 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_41,         /**< \brief Injected external bit is at Position 41 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_42,         /**< \brief Injected external bit is at Position 42 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_43,         /**< \brief Injected external bit is at Position 43 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_44,         /**< \brief Injected external bit is at Position 44 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_45,         /**< \brief Injected external bit is at Position 45 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_46,         /**< \brief Injected external bit is at Position 46 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_47,         /**< \brief Injected external bit is at Position 47 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_48,         /**< \brief Injected external bit is at Position 48 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_49,         /**< \brief Injected external bit is at Position 49 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_50,         /**< \brief Injected external bit is at Position 50 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_51,         /**< \brief Injected external bit is at Position 51 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_52,         /**< \brief Injected external bit is at Position 52 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_53,         /**< \brief Injected external bit is at Position 53 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_54,         /**< \brief Injected external bit is at Position 54 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_55,         /**< \brief Injected external bit is at Position 55 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_56,         /**< \brief Injected external bit is at Position 56 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_57,         /**< \brief Injected external bit is at Position 57 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_58,         /**< \brief Injected external bit is at Position 58 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_59,         /**< \brief Injected external bit is at Position 59 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_60,         /**< \brief Injected external bit is at Position 60 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_61,         /**< \brief Injected external bit is at Position 61 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_62,         /**< \brief Injected external bit is at Position 62 of the data frame  */
    IfxMsc_ExternalBitInjectionPosition_63          /**< \brief Injected external bit is at Position 63 of the data frame  */
} IfxMsc_ExternalBitInjectionPosition;

/** \brief Downstream Control Enhanced Register - Injection Enable of the Pin 0 and 1 Signal\n
 * Definition in Ifx_MSC.DSCE.B.INJENP0 and Ifx_MSC.DSCE.B.INJENP1
 */
typedef enum
{
    IfxMsc_ExternalSignalInjection_disabled = 0,  /**< \brief Disables the external signal injection in a data frame */
    IfxMsc_ExternalSignalInjection_enabled  = 1   /**< \brief Enables the external signal injection in a data frame */
} IfxMsc_ExternalSignalInjection;

/** \brief Enum for enable and disable Fast Mode
 * Definition in Ifx_MSC.DSTE.B.FM
 */
typedef enum
{
    IfxMsc_FastMode_disabled = 0,  /**< \brief Disable Fast Mode(DSTE.FM=0).Needs to be cleared with DSTE.UL1=1 in the same cycle */
    IfxMsc_FastMode_enabled  = 1   /**< \brief Enable Fast Mode(DSTE.FM=1).Needs to be cleared with DSTE.UL1=1 in the same cycle */
} IfxMsc_FastMode;

/** \brief Output Control Register - Clock Control\n
 * Definition in Ifx_MSC.OCR.B.CLKCTRL
 */
typedef enum
{
    IfxMsc_FclClockControlEnabled_activePhaseOnly = 0,  /**< \brief FCL is active during active phases of data or command frames */
    IfxMsc_FclClockControlEnabled_always          = 1   /**< \brief FCL is always active */
} IfxMsc_FclClockControlEnabled;

/** \brief Output Control Register - FCLP Line Polarity\n
 * Definition in Ifx_MSC.OCR.B.CLP
 */
typedef enum
{
    IfxMsc_FclLinePolarity_nonInverted = 0,  /**< \brief FCLP and FCL signal polarity is identical */
    IfxMsc_FclLinePolarity_inverted    = 1   /**< \brief FCLP signal has inverted FCL signal polarity */
} IfxMsc_FclLinePolarity;

/** \brief Enable hardware clock control
 * Definition in Ifx_MSC_FDR.B.B.ENHW
 */
typedef enum
{
    IfxMsc_HardwareClock_disabled = 0,  /**< \brief Hardware clock disable */
    IfxMsc_HardwareClock_enabled  = 1   /**< \brief Hardware clock enable */
} IfxMsc_HardwareClock;

/** \brief Interrupt Service Request
 */
typedef enum
{
    IfxMsc_InterruptServiceRequest_0 = 0,      /**< \brief Interrupt Service Request number0  */
    IfxMsc_InterruptServiceRequest_1,          /**< \brief Interrupt Service Request number1  */
    IfxMsc_InterruptServiceRequest_2,          /**< \brief Interrupt Service Request number2  */
    IfxMsc_InterruptServiceRequest_3,          /**< \brief Interrupt Service Request number3  */
    IfxMsc_InterruptServiceRequest_4           /**< \brief Interrupt Service Request number4  */
} IfxMsc_InterruptServiceRequest;

/** \brief OCDS Control and Status - OCDS Suspend Control
 * Definition in Ifx_MSC.OCS.B.SUS
 */
typedef enum
{
    IfxMsc_ModuleSuspendRequestBit_noSuspend   = 0,  /**< \brief OCDS is not suspended */
    IfxMsc_ModuleSuspendRequestBit_hardSuspend = 1,  /**< \brief OCDS is Hard suspended. Clock is switched off immediately */
    IfxMsc_ModuleSuspendRequestBit_softSuspend = 2   /**< \brief OCDS is Soft suspended */
} IfxMsc_ModuleSuspendRequestBit;

/** \brief Downstream Control Enhanced Register - Number of SRL/SRH Bits Shifted at Data Frames Extension (NDBL/NDBH)\n
 * Definition in Ifx_MSC.DSCE.B.NDBLE and Ifx_MSC.DSCE.B.NDBHE
 */
typedef enum
{
    IfxMsc_MsbBitDataExtension_notPresent = 0,  /**< \brief Additional MSB bit is not present in the extension of the NDBL/NDBH bit field */
    IfxMsc_MsbBitDataExtension_present    = 1   /**< \brief Additional MSB bit is present in the extension of the NDBL/NDBH bit field */
} IfxMsc_MsbBitDataExtension;

/** \brief Asynchronous Block Configuration Register - N Divider ABRA\n
 * Definition in Ifx_MSC.ABC.B.NDA
 */
typedef enum
{
    IfxMsc_NDividerAbra_1 = 0,      /**< \brief Division ratio is 1  */
    IfxMsc_NDividerAbra_2,          /**< \brief Division ratio is 2  */
    IfxMsc_NDividerAbra_3,          /**< \brief Division ratio is 3  */
    IfxMsc_NDividerAbra_4,          /**< \brief Division ratio is 4  */
    IfxMsc_NDividerAbra_5,          /**< \brief Division ratio is 5  */
    IfxMsc_NDividerAbra_6,          /**< \brief Division ratio is 6  */
    IfxMsc_NDividerAbra_7,          /**< \brief Division ratio is 7  */
    IfxMsc_NDividerAbra_8           /**< \brief Division ratio is 8  */
} IfxMsc_NDividerAbra;

/** \brief Downstream Timing Extension Register - N Divider Downstream\n
 * Definition in Ifx_MSC.DSTE.B.NDD
 */
typedef enum
{
    IfxMsc_NDividerDownstream_1 = 0,      /**< \brief division ratio is 1  */
    IfxMsc_NDividerDownstream_2,          /**< \brief division ratio is 2  */
    IfxMsc_NDividerDownstream_3,          /**< \brief division ratio is 3  */
    IfxMsc_NDividerDownstream_4,          /**< \brief division ratio is 4  */
    IfxMsc_NDividerDownstream_5,          /**< \brief division ratio is 5  */
    IfxMsc_NDividerDownstream_6,          /**< \brief division ratio is 6  */
    IfxMsc_NDividerDownstream_7,          /**< \brief division ratio is 7  */
    IfxMsc_NDividerDownstream_8,          /**< \brief division ratio is 8  */
    IfxMsc_NDividerDownstream_9,          /**< \brief division ratio is 9  */
    IfxMsc_NDividerDownstream_10,         /**< \brief division ratio is 10  */
    IfxMsc_NDividerDownstream_11,         /**< \brief division ratio is 11  */
    IfxMsc_NDividerDownstream_12,         /**< \brief division ratio is 12  */
    IfxMsc_NDividerDownstream_13,         /**< \brief division ratio is 13  */
    IfxMsc_NDividerDownstream_14,         /**< \brief division ratio is 14  */
    IfxMsc_NDividerDownstream_15,         /**< \brief division ratio is 15  */
    IfxMsc_NDividerDownstream_16          /**< \brief division ratio is 16  */
} IfxMsc_NDividerDownstream;

/** \brief Asynchronous Block Configuration Register - Overflow Interrupt Enable\n
 * Definition in Ifx_MSC.ABC.B.OIE
 */
typedef enum
{
    IfxMsc_OverflowInterrupt_disabled = 0,  /**< \brief Disables the path of the overflow interrupt towards the interrupt node */
    IfxMsc_OverflowInterrupt_enabled  = 1   /**< \brief Enables the path of the overflow interrupt towards the interrupt node */
} IfxMsc_OverflowInterrupt;

/** \brief Asynchronous Block Configuration Register - Overflow Interrupt Node Pointer\n
 * Definition in Ifx_MSC.ABC.B.OIP
 */
typedef enum
{
    IfxMsc_OverflowInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_OverflowInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_OverflowInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_OverflowInterruptNode_SR3,          /**< \brief Service request output SR3 selected  */
    IfxMsc_OverflowInterruptNode_SR4           /**< \brief Service request output SR4 selected  */
} IfxMsc_OverflowInterruptNode;

/** \brief Parity Mode\n
 * Definition in Ifx_MSC.USR.B.PCT
 */
typedef enum
{
    IfxMsc_Parity_even = 0,  /**< \brief Even Parity */
    IfxMsc_Parity_odd  = 1   /**< \brief Odd Parity */
} IfxMsc_Parity;

/** \brief Downstream Status Register - Number Of Passive Time Frames\n
 * Definition in Ifx_MSC.DSS.B.NPTF
 */
typedef enum
{
    IfxMsc_PassiveTimeFrameCount_0 = 0,    /**< \brief No Passive time frames inserted */
    IfxMsc_PassiveTimeFrameCount_1 = 1,    /**< \brief 1 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_2,        /**< \brief 2 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_3,        /**< \brief 3 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_4,        /**< \brief 4 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_5,        /**< \brief 5 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_6,        /**< \brief 6 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_7,        /**< \brief 7 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_8,        /**< \brief 8 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_9,        /**< \brief 9 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_10,       /**< \brief 10 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_11,       /**< \brief 11 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_12,       /**< \brief 12 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_13,       /**< \brief 13 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_14,       /**< \brief 14 Passive time frames inserted  */
    IfxMsc_PassiveTimeFrameCount_15        /**< \brief 15 Passive time frames inserted  */
} IfxMsc_PassiveTimeFrameCount;

/** \brief Interrupt Control Register - Receive Data Interrupt Enable\n
 * Definition in Ifx_MSC.ICR.B.RDIE
 */
typedef enum
{
    IfxMsc_ReceiveDataInterrupt_disabled           = 0, /**< \brief Interrupt generation disabled */
    IfxMsc_ReceiveDataInterrupt_onDataReceive      = 1, /**< \brief An interrupt is generated when data is received and written into the upstream data registers */
    IfxMsc_ReceiveDataInterrupt_onRdieSet          = 2, /**< \brief An interrupt is generated as with RDIE = 01B but only if the received data is not equal to 00H */
    IfxMsc_ReceiveDataInterrupt_onDataReceiveInUd3 = 3  /**< \brief An interrupt is generated as with RDIE = 01B but only if the received data is not equal to 00H */
} IfxMsc_ReceiveDataInterrupt;

/** \brief Interrupt Control Register - Receive Data Interrupt Pointer\n
 * Definition in Ifx_MSC.ICR.B.RDIP
 */
typedef enum
{
    IfxMsc_ReceiveDataInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_ReceiveDataInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_ReceiveDataInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_ReceiveDataInterruptNode_SR3           /**< \brief Service request output SR3 selected  */
} IfxMsc_ReceiveDataInterruptNode;

/** \brief Output Control Register - SDI Line Polarity\n
 * Definition in Ifx_MSC.OCR.B.ILP
 */
typedef enum
{
    IfxMsc_SdiLinePolarity_likeSi     = 0, /**< \brief SDI and SI signal polarities are identical */
    IfxMsc_SdiLinePolarity_invertedSi = 1  /**< \brief SDI and SI signal polarities are inverted */
} IfxMsc_SdiLinePolarity;

/** \brief Output Control Register - Serial Data Input Selection\n
 * Definition in Ifx_MSC.OCR.B.SDISEL
 */
typedef enum
{
    IfxMsc_SerialDataInput_0 = 0,      /**< \brief SDI0 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_1,          /**< \brief SDI1 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_2,          /**< \brief SDI2 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_3,          /**< \brief SDI3 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_4,          /**< \brief SDI4 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_5,          /**< \brief SDI5 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_6,          /**< \brief SDI6 is selected for the SDI of the upstream channel  */
    IfxMsc_SerialDataInput_7           /**< \brief SDI7 is selected for the SDI of the upstream channel  */
} IfxMsc_SerialDataInput;

/** \brief Service Request Delay\n
 * Definition in Ifx_MSC.USR.B.SRDC
 */
typedef enum
{
    IfxMsc_ServiceRequestDelay_noDelay = 0,  /**< \brief No Delay */
    IfxMsc_ServiceRequestDelay_1bit    = 1   /**< \brief Delay of 1 bit time */
} IfxMsc_ServiceRequestDelay;

/** \brief Asynchronous Block Configuration Register - Duration of the Low/High Phase of the Shift Clock\n
 * Definition in Ifx_MSC.ABC.B.LOW and Ifx_MSC.ABC.B.HIGH
 */
typedef enum
{
    IfxMsc_ShiftClockPhaseDuration_1 = 0,      /**< \brief Duration in periods of f_A is 1  */
    IfxMsc_ShiftClockPhaseDuration_2,          /**< \brief Duration in periods of f_A is 2  */
    IfxMsc_ShiftClockPhaseDuration_3,          /**< \brief Duration in periods of f_A is 3  */
    IfxMsc_ShiftClockPhaseDuration_4,          /**< \brief Duration in periods of f_A is 4  */
    IfxMsc_ShiftClockPhaseDuration_5,          /**< \brief Duration in periods of f_A is 5  */
    IfxMsc_ShiftClockPhaseDuration_6,          /**< \brief Duration in periods of f_A is 6  */
    IfxMsc_ShiftClockPhaseDuration_7,          /**< \brief Duration in periods of f_A is 7  */
    IfxMsc_ShiftClockPhaseDuration_8,          /**< \brief Duration in periods of f_A is 8  */
    IfxMsc_ShiftClockPhaseDuration_9,          /**< \brief Duration in periods of f_A is 9  */
    IfxMsc_ShiftClockPhaseDuration_10,         /**< \brief Duration in periods of f_A is 10  */
    IfxMsc_ShiftClockPhaseDuration_11,         /**< \brief Duration in periods of f_A is 11  */
    IfxMsc_ShiftClockPhaseDuration_12,         /**< \brief Duration in periods of f_A is 12  */
    IfxMsc_ShiftClockPhaseDuration_13,         /**< \brief Duration in periods of f_A is 13  */
    IfxMsc_ShiftClockPhaseDuration_14,         /**< \brief Duration in periods of f_A is 14  */
    IfxMsc_ShiftClockPhaseDuration_15,         /**< \brief Duration in periods of f_A is 15  */
    IfxMsc_ShiftClockPhaseDuration_16          /**< \brief Duration in periods of f_A is 16  */
} IfxMsc_ShiftClockPhaseDuration;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_MSC.CLC.B.EDIS
 */
typedef enum
{
    IfxMsc_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxMsc_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxMsc_SleepMode;

/** \brief Output Control Register - SOP Line Polarity\n
 * Definition in Ifx_MSC.OCR.B.SLP
 */
typedef enum
{
    IfxMsc_SoLinePolarity_nonInverted = 0,  /**< \brief SOP and SO polarity is identical */
    IfxMsc_SoLinePolarity_inverted    = 1   /**< \brief SOP and SO polarity is inverted */
} IfxMsc_SoLinePolarity;

/** \brief Downstream Select Data Source Low Register - Select Source for - SRL and SRHNumber Of Passive Time Frames\n
 * Definition in Ifx_MSC.DSDSL and Ifx_MSC.DSDSH
 */
typedef enum
{
    IfxMsc_Source_downstreamDataRegister     = 0, /**< \brief SRx[16] is taken from data Register DD.DDL[xx] */
    IfxMsc_Source_alternateInputLine         = 2, /**< \brief SRx[16] is taken from ALTINL input line */
    IfxMsc_Source_alternateInputLineInverted = 3  /**< \brief SRx[16] is taken from ALTINL input line in inverted state */
} IfxMsc_Source;

/** \brief MSC Stream mode.
 * Used for correct baudrate calculation
 */
typedef enum
{
    IfxMsc_StreamMode_up   = 0, /**< \brief MSC is used in upStream mode */
    IfxMsc_StreamMode_down = 1  /**< \brief MSC is used in downStream mode */
} IfxMsc_StreamMode;

/** \brief OCDS Suspend Control (OCDS.SUS)
 * Definition in Ifx_MSC_OCS.B.SUS
 */
typedef enum
{
    IfxMsc_SuspendMode_none = 0,  /**< \brief No suspend */
    IfxMsc_SuspendMode_hard = 1,  /**< \brief Hard Suspend */
    IfxMsc_SuspendMode_soft = 2   /**< \brief Soft Suspend */
} IfxMsc_SuspendMode;

/** \brief Msc Targets - use as chip enable selection for ENH, ENL and ENC
 * Definition in Ifx_MSC.OCR.B.CSC
 */
typedef enum
{
    IfxMsc_Target_en0 = 0,      /**< \brief Target EN0  */
    IfxMsc_Target_en1,          /**< \brief Target EN1  */
    IfxMsc_Target_en2,          /**< \brief Target EN2  */
    IfxMsc_Target_en3           /**< \brief Target EN3  */
} IfxMsc_Target;

/** \brief Interrupt Control Register - Time Frame Interrupt Enable\n
 * Definition in Ifx_MSC.ICR.B.TFIE
 */
typedef enum
{
    IfxMsc_TimeFrameInterrupt_disabled = 0,  /**< \brief Interrupt generation disabled */
    IfxMsc_TimeFrameInterrupt_enabled  = 1   /**< \brief Interrupt generation enabled */
} IfxMsc_TimeFrameInterrupt;

/** \brief Interrupt Control Register - Time Frame Interrupt Pointer\n
 * Definition in Ifx_MSC.ICR.B.TFIP
 */
typedef enum
{
    IfxMsc_TimeFrameInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_TimeFrameInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_TimeFrameInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_TimeFrameInterruptNode_SR3           /**< \brief Service request output SR3 selected  */
} IfxMsc_TimeFrameInterruptNode;

/** \brief Downstream Channel Transmission Mode\n
 * Definition in Ifx_MSC.DSC.B.TM
 */
typedef enum
{
    IfxMsc_TransmissionMode_triggered      = 0, /**< \brief Triggered Mode */
    IfxMsc_TransmissionMode_dataRepetition = 1  /**< \brief Data Repetition Mode */
} IfxMsc_TransmissionMode;

/** \brief Asynchronous Block Configuration Register - Underflow Interrupt Enable\n
 * Definition in Ifx_MSC.ABC.B.UIE
 */
typedef enum
{
    IfxMsc_UnderflowInterrupt_disabled = 0,  /**< \brief Disables the path of the Underflow interrupt towards the interrupt node */
    IfxMsc_UnderflowInterrupt_enabled  = 1   /**< \brief Enables the path of the Underflow interrupt towards the interrupt node */
} IfxMsc_UnderflowInterrupt;

/** \brief Asynchronous Block Configuration Register - Underflow Interrupt Node Pointer\n
 * Definition in Ifx_MSC.ABC.B.UIP
 */
typedef enum
{
    IfxMsc_UnderflowInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_UnderflowInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_UnderflowInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_UnderflowInterruptNode_SR3,          /**< \brief Service request output SR3 selected  */
    IfxMsc_UnderflowInterruptNode_SR4           /**< \brief Service request output SR4 selected  */
} IfxMsc_UnderflowInterruptNode;

/** \brief Channel Frame Type\n
 * Definition in Ifx_MSC.USR.B.UFT
 */
typedef enum
{
    IfxMsc_UpstreamChannelFrameType_12bit = 0,  /**< \brief 12-bit Upstream frame selected */
    IfxMsc_UpstreamChannelFrameType_16bit = 1   /**< \brief 16-bit Upstream frame selected */
} IfxMsc_UpstreamChannelFrameType;

/** \brief Upstream Receiving Rate\n
 * Definition in Ifx_MSC.USR.B.URR
 */
typedef enum
{
    IfxMsc_UpstreamChannelReceivingRate_disabled = 0,  /**< \brief Disabled */
    IfxMsc_UpstreamChannelReceivingRate_4        = 1,  /**< \brief Baud rate = f_MSC / 4 */
    IfxMsc_UpstreamChannelReceivingRate_8        = 2,  /**< \brief Baud rate = f_MSC / 8 */
    IfxMsc_UpstreamChannelReceivingRate_16       = 3,  /**< \brief Baud rate = f_MSC / 16 */
    IfxMsc_UpstreamChannelReceivingRate_32       = 4,  /**< \brief Baud rate = f_MSC / 32 */
    IfxMsc_UpstreamChannelReceivingRate_64       = 5,  /**< \brief Baud rate = f_MSC / 64 */
    IfxMsc_UpstreamChannelReceivingRate_128      = 6,  /**< \brief Baud rate = f_MSC / 128 */
    IfxMsc_UpstreamChannelReceivingRate_256      = 7   /**< \brief Baud rate = f_MSC / 256 */
} IfxMsc_UpstreamChannelReceivingRate;

/** \brief Upstream Control Enhanced Register 1 - Upstream Timeout Interrupt Enable\n
 * Definition in Ifx_MSC.USCE.B.USTOEN
 */
typedef enum
{
    IfxMsc_UpstreamTimeoutInterrupt_disabled = 0,  /**< \brief Upstream Timeout Interrupt Disabled */
    IfxMsc_UpstreamTimeoutInterrupt_enabled  = 1   /**< \brief Upstream Timeout Interrupt Enabled */
} IfxMsc_UpstreamTimeoutInterrupt;

/** \brief Upstream Control Enhanced Register 1 - Upstream Timeout Interrupt Node Pointer\n
 * Definition in Ifx_MSC.USCE.B.USTOIP
 */
typedef enum
{
    IfxMsc_UpstreamTimeoutInterruptNode_SR0 = 0,      /**< \brief Service request output SR0 selected  */
    IfxMsc_UpstreamTimeoutInterruptNode_SR1,          /**< \brief Service request output SR1 selected  */
    IfxMsc_UpstreamTimeoutInterruptNode_SR2,          /**< \brief Service request output SR2 selected  */
    IfxMsc_UpstreamTimeoutInterruptNode_SR3,          /**< \brief Service request output SR3 selected  */
    IfxMsc_UpstreamTimeoutInterruptNode_SR4           /**< \brief Service request output SR4 selected  */
} IfxMsc_UpstreamTimeoutInterruptNode;

/** \brief Upstream Control Enhanced Register 1 - Upstream Timeout Prescaler\n
 * Definition in Ifx_MSC.USCE.B.USTOPRE
 */
typedef enum
{
    IfxMsc_UpstreamTimeoutPrescaler_1     = 0,   /**< \brief Prescale value 1 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_2     = 1,   /**< \brief Prescale value 2 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_4     = 2,   /**< \brief Prescale value 4 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_8     = 3,   /**< \brief Prescale value 8 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_16    = 4,   /**< \brief Prescale value 16 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_32    = 5,   /**< \brief Prescale value 32 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_64    = 6,   /**< \brief Prescale value 64 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_128   = 7,   /**< \brief Prescale value 128 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_256   = 8,   /**< \brief Prescale value 256 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_512   = 9,   /**< \brief Prescale value 512 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_1024  = 10,  /**< \brief Prescale value 1024 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_2048  = 11,  /**< \brief Prescale value 2048 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_4096  = 12,  /**< \brief Prescale value 4096 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_8192  = 13,  /**< \brief Prescale value 8192 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_16384 = 14,  /**< \brief Prescale value 16384 for the upstream time-out limit */
    IfxMsc_UpstreamTimeoutPrescaler_32768 = 15   /**< \brief Prescale value 32768 for the upstream time-out limit */
} IfxMsc_UpstreamTimeoutPrescaler;

/** \brief Upstream Control Enhanced Register 1 - Upstream Timeout Value\n
 * Definition in Ifx_MSC.USCE.B.USTOVAL
 */
typedef enum
{
    IfxMsc_UpstreamTimeoutValue_1 = 0,      /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_2,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_3,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_4,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_5,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_6,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_7,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_8,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_9,          /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_10,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_11,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_12,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_13,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_14,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_15,         /**< \brief Upstream timeout value for the N-Divider  */
    IfxMsc_UpstreamTimeoutValue_16          /**< \brief Upstream timeout value for the N-Divider  */
} IfxMsc_UpstreamTimeoutValue;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief 64 bit commnd to be loaded first to DCE & then to DC for transmission.
 */
typedef struct
{
    uint32 dce;       /**< \brief Command to be wrtten to DCE register. Range: 0 to 0xFFFFFFFF */
    uint32 dc;        /**< \brief Command to be wrtten to DC register. Range: 0 to 0xFFFFFFFF */
} IfxMsc_CxModeCommand;

/** \addtogroup IfxLld_Msc_Std_Config_Flags
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the ABRA overflow flag in the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearAbraOverflowFlag(Ifx_MSC *msc);

/**
 * \brief Clears the ABRA underflow flag in the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearAbraUnderflowFlag(Ifx_MSC *msc);

/**
 * \brief Clears the upstream timeout for the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearUpstreamTimeout(Ifx_MSC *msc);

/**
 * \brief Clears the valid flag for a specified upstream data register.
 *
 * \param[inout] msc         Pointer to the base address of MSC registers.
 * \param[in]    upstreamIdx The index of the upstream data register for which the
 *                           valid flag should be cleared.
 *                           Range: 0 to 0x3
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearUpstreamValidFlag(Ifx_MSC *msc, uint8 upstreamIdx);

/**
 * \brief Retrieves the status of the valid flag for a specified upstream data register.
 *
 * \param[in] msc         Pointer to the base address of MSC registers.
 * \param[in] upstreamIdx The index of the upstream data register ID for which the valid
 * 						  flag status is to be retrieved.
 * 						  Range: 0 to 0x3
 *
 * \retval boolean TRUE  If the valid flag is set for the specified upstream data register.
 *         		   FALSE If the valid flag is not set for the specified upstream data register.
 */
IFX_INLINE boolean IfxMsc_getUpstreamValidFlag(Ifx_MSC *msc, uint8 upstreamIdx);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Set_Command_Target
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Selects the target for the command phase.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * \param[in]    enX Target to be selected for the command phase.
 * 				     Range: \ref IfxMsc_Target
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setCommandTarget(Ifx_MSC *msc, IfxMsc_Target enX);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Set_Data
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Selects the target for the data high phase.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * \param[in]    enX The target to be selected.
 * 				     Range: \ref IfxMsc_Target
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setDataHighTarget(Ifx_MSC *msc, IfxMsc_Target enX);

/**
 * \brief Selects the target for the data low phase of the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * \param[in]    enX The target to be selected for the data low phase.
 * 					 Rang: \ref IfxMsc_Target
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setDataLowTarget(Ifx_MSC *msc, IfxMsc_Target enX);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Get_Data
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the upstream data from the specified upstream data register.
 *
 * \param[in] msc         Pointer to the base address of MSC registers.
 * \param[in] upstreamIdx The index of the upstream data register ID for which the
 * 						  data is to be retrieved.
 * 						  Range: 0 to 0x3
 *
 * \retval uint16 Received data from the upstream data register.
 * 				  Range: 0 to 0xFF
 */
IFX_INLINE uint16 IfxMsc_getData(Ifx_MSC *msc, uint8 upstreamIdx);

/**
 * \brief Retrieves the target selected during the high phase of the MSC operation.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 * 
 * \retval IfxMsc_Target The selected target during the high phase.
 * 						 Range: \ref IfxMsc_Target
 */
IFX_INLINE IfxMsc_Target IfxMsc_getDataHighTarget(Ifx_MSC *msc);

/**
 * \brief Retrieves the target selected during the low phase of the MSC module operation.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 * 
 * \retval IfxMsc_Target The currently selected target for the low phase.
 * 						 Range: \ref IfxMsc_Target
 */
IFX_INLINE IfxMsc_Target IfxMsc_getDataLowTarget(Ifx_MSC *msc);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Enable_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the MSC kernel, stopping its operation and preparing it for a low-power state.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_disableModule(Ifx_MSC *msc);

/**
 * \brief Enables the MSC kernel.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_enableModule(Ifx_MSC *msc);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Reset_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the reset bit of the MSC kernel.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * 
 * \retval None
 */
IFX_EXTERN void IfxMsc_clearReset(Ifx_MSC *msc);

/**
 * \brief Resets the MSC kernel to its initial state.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * 
 * \retval None
 */
IFX_EXTERN void IfxMsc_resetModule(Ifx_MSC *msc);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Baud_Calculator
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Calculates the NDD (N Divider Downstream) value for the given baud rate when the ABRA block is enabled.
 *
 * \param[in] baud The desired baud rate for which the NDD value is to be calculated.
 * 				   Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud)
 * 
 * \retval uint32 The calculated NDD value for the specified baud rate.
 * 				  Range: 0x1 (for 0.39 Mbaud) to 0x7F (for 25 Mbaud)
 */
IFX_EXTERN uint32 IfxMsc_downstreamAbraBaudCalculator(uint32 baud);

/**
 * \brief Calculates the step value for the supplied baud rate when using fractional divider mode.
 *
 * \param[in] msc  Pointer to the base address of MSC registers.
 * \param[in] baud Required baud rate.
 * 				   Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud)
 *
 * \retval uint64 The calculated step value for the fractional baud rate configuration.
 * 				  Range: 0 to 0x400   (for 25 Mbaud, URR 0 to 7)
 * 				  		 0 to 0x10000 (for 0.39 Mbaud, URR 0 to 7)
 */
IFX_EXTERN uint64 IfxMsc_upstreamFractionalBaudCalculator(Ifx_MSC *msc, uint32 baud);

/**
 * \brief Calculates the step value for the specified baud rate in normal divider mode.
 *
 * \param[in] msc  Pointer to the base address of MSC registers.
 * \param[in] baud Required baud rate.
 * 				   Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud)
 *
 * \retval uint32 Step value for the specified baud rate.
 * 				  Range: 0x3C0 to 0x3FF (for 0.39 Mbaud, URR 1 to 7)
 * 				  		 0x3FF to 0x400 (for 25	Mbaud, URR 1 to 7)
 */
IFX_EXTERN uint32 IfxMsc_upstreamNormalBaudCalculator(Ifx_MSC *msc, uint32 baud);

/** \} */

/** \addtogroup IfxLld_Msc_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Initializes a EN output pin with the specified mode and pad driver settings.
 *
 * \param[in] en        Pointer to the EN pin configuration structure to be initialized.
 * \param[in] pinMode   The output mode to be configured for the pin.
 * 						Range: \ref IfxPort_OutputMode
 * \param[in] padDriver The pad driver mode to be configured.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initEnPin(const IfxMsc_En_Out *en, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a FCLN output pin with the specified mode and driver settings.
 *
 * \param[in] fcln      Pointer to the FCLN pin configuration structure to be initialized.
 * \param[in] pinMode   The output mode to be configured for the pin.
 * 						Range: \ref IfxPort_OutputMode
 * \param[in] padDriver The pad driver mode to be configured.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initFclnPin(const IfxMsc_Fcln_Out *fcln, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a FCLP output pin with the specified mode and driver configuration.
 *
 * \param[in] fclp      Pointer to the FCLP pin configuration structure to be initialized.
 * \param[in] pinMode   The output mode to be configured for the pin.
 * 						Range: \ref IfxPort_OutputMode
 * \param[in] padDriver The pad driver mode to be configured.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initFclpPin(const IfxMsc_Fclp_Out *fclp, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a INJ input pin with the specified input mode and pad driver settings.
 *
 * \param[in] inj       Pointer to the INJ pin configuration structure that should be initialized.
 *                      This structure contains the necessary information for the INJ pin setup.
 * \param[in] pinMode   The input mode to be configured for the INJ pin.
 * 						Range: \ref IfxPort_InputMode
 * \param[in] padDriver The pad driver mode to be configured for the INJ pin.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initInjPin(const IfxMsc_Inj_In *inj, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a SDI input pin with the specified configuration.
 *
 * \param[in] sdi       Pointer to the SDI pin configuration structure to be initialized.
 * \param[in] pinMode   The input mode to be configured for the SDI pin.
 * 						Range: \ref IfxPort_InputMode
 * \param[in] padDriver The pad driver mode to be configured for the SDI pin.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initSdiPin(const IfxMsc_Sdi_In *sdi, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a SON output pin with the specified mode and pad driver configuration.
 *
 * \param[in] son       The SON pin to be configured. This is a pointer to the SON pin structure.
 * \param[in] pinMode   The output mode to be set for the pin.
 * 						Range: \ref IfxPort_OutputMode
 * \param[in] padDriver The pad driver mode to be configured.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initSonPin(const IfxMsc_Son_Out *son, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes a SOP output pin with the specified output mode and pad driver settings.
 *
 * \param[in] sop       Pointer to the SOP pin configuration structure that should be used for initialization.
 * \param[in] pinMode   The output mode to be configured for the SOP pin.
 * 						Range: \ref IfxPort_OutputMode
 * \param[in] padDriver The pad driver mode to be configured for the SOP pin.
 * 						Range: \ref IfxPort_PadDriver
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_initSopPin(const IfxMsc_Sop_Out *sop, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/** \} */

/** \addtogroup IfxLld_Msc_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Retrieves the register address of the MSC module corresponding to the given index.
 *
 * \param[in] msc Resource index of the MSC module.
 * 				  Range: \ref IfxMsc_Index
 *
 * \retval Ifx_MSC* Base address of the MSC module's registers.
 */
IFX_EXTERN Ifx_MSC *IfxMsc_getAddress(IfxMsc_Index msc);

/**
 * \brief Retrieves the resource index of the specified MSC module.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval IfxMsc_Index The resource index of the MSC module.
 * 						Range: \ref IfxMsc_Index
 */
IFX_EXTERN IfxMsc_Index IfxMsc_getIndex(Ifx_MSC *msc);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the receive data interrupt flag of the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearRecieveDataInterruptFlag(Ifx_MSC *msc);

/**
 * \brief Clears the Valid bit of the specified upstream channel, indicating that the channel is not currently valid.
 *
 * \param[inout] msc         Pointer to the base address of MSC registers.
 * \param[in]    upstreamIdx Index of the upstream channel to clear the Valid bit for.
 * 						     Range: 0 to 0x3
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_clearValidbit(Ifx_MSC *msc, uint8 upstreamIdx);

/**
 * \brief Disables the Upstream Timeout Interrupt.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_disableUpstreamTimeoutInterrupt(Ifx_MSC *msc);

/**
 * \brief Enables the Upstream Timeout Interrupt for the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_enableUpstreamTimeoutInterrupt(Ifx_MSC *msc);

/**
 * \brief Checks if the asynchronous clock bypass is enabled.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the Asynchronous Block is not Bypassed and active.
 * 				   FALSE If the Asynchronous Block is Bypassed and disabled.
 */
IFX_INLINE boolean IfxMsc_getAsyncClockBypass(Ifx_MSC *msc);

/**
 * \brief Returns the value of the downstream extension enable bit.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the Downstream extension is enabled.
 *        		   FALSE If the Downstream extension is disabled.
 */
IFX_INLINE boolean IfxMsc_getDownStreamExtension(Ifx_MSC *msc);

/**
 * \brief Returns the status of the Receive Data Interrupt Flag.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the Receive Data Interrupt Flag is set.
 *                 FALSE If the Receive Data Interrupt Flag is not set.
 */
IFX_INLINE boolean IfxMsc_getRecieveDataInterruptFlag(Ifx_MSC *msc);

/**
 * \brief Returns the SRC pointer for the selected MSC interrupt node, providing low-level access to the SRCR register.
 *
 * \param[in] msc        Pointer to the base address of MSC registers.
 * \param[in] intRequest Interrupt Service Request to select the appropriate SRCR register.
 * 						 Range: \ref IfxMsc_InterruptServiceRequest
 *
 * \retval Ifx_SRC_SRCR Pointer to the SRCR register of the selected interrupt service request.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxMsc_getSrcPointer(Ifx_MSC *msc, IfxMsc_InterruptServiceRequest intRequest);

/**
 * \brief Retrieves the upstream data for a specified index.
 *
 * \param[in] msc         Pointer to the base address of MSC registers.
 * \param[in] upstreamIdx The index of the upstream data register to retrieve the data.
 * 						  Range: 0 to 0x3
 *
 * \retval uint32 The upstream data value.
 * 				  Range: 0 to 0xFF00FE00
 */
IFX_INLINE uint32 IfxMsc_getUpstreamData(Ifx_MSC *msc, uint8 upstreamIdx);

/**
 * \brief Returns the status of the Upstream Parity Error Flag for the specified upstream channel.
 *
 * \param[in] msc         Pointer to the base address of MSC registers.
 * \param[in] upstreamIdx The Index of the upstream data register to check parity error flag.
 * 						  Range: 0 to 0x3
 *
 * \retval boolean TRUE  If the Upstream Parity Error is detected.
 * 				   FALSE If no Upstream Parity Error is detected.
 */
IFX_INLINE boolean IfxMsc_getUpstreamParityErrorFlag(Ifx_MSC *msc, uint8 upstreamIdx);

/**
 * \brief Returns the status of the upstream timeout flag.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 * 
 * \retval boolean TRUE  If the Upstream Time-out Flag is Enabled.
 * 		           FALSE If the Upstream Time-out Flag is Disabled.
 */
IFX_INLINE boolean IfxMsc_getUpstreamTimeoutFlag(Ifx_MSC *msc);

/**
 * \brief Checks if the MSC module is in a suspended state.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the Module is suspended
 * 		   		   FALSE If the Module is not (yet) suspended.
 */
IFX_INLINE boolean IfxMsc_isModuleSuspended(Ifx_MSC *msc);

/**
 * \brief Sets or resets the Asynchronous clock bypass bit.
 * 
 * \param[inout] msc   Pointer to the base address of MSC registers.
 * \param[in] 	 value Boolean value to set or reset the bypass bit.
 * 					   Range: TRUE  Disables the bypass, and the asynchronous clock will become active.
 * 						      FALSE Enables the bypass, and the asynchronous clock will be disabled.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setAsyncClockBypass(Ifx_MSC *msc, boolean value);

/**
 * \brief Configures the downstream data for the MSC module.
 *
 * \param[inout] msc  Pointer to the base address of MSC registers.
 * \param[in]    data The 32-bit data value to be set for downstream transmission.
 * 					  Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setDownStreamData(Ifx_MSC *msc, uint32 data);

/**
 * \brief Enables or disables the Downstream extension feature.
 * 
 * \param[inout] msc   Pointer to the base address of MSC registers.
 * \param[in]    value Boolean value to set or reset the downstream extension.
 * 					   Range: TRUE  Enables the downstream extension.
 * 					   		  FALSE Disables the downstream extension.
 * 
 * \retval None
 */
IFX_INLINE void IfxMsc_setDownStreamExtension(Ifx_MSC *msc, boolean value);

/**
 * \brief Configures the downstream extension data for the MSC module.
 *
 * \param[inout] msc  Pointer to the base address of MSC registers.
 * \param[in] 	 data The 32-bit data value to be set as the downstream extension data.
 * 					  Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setDownStreamExtensionData(Ifx_MSC *msc, uint32 data);

/**
 * \brief Enables or disables the Fast Mode for the MSC module.
 *        When Fast Mode is enabled, the module operates at higher speeds,
 *        and the correct NDD (Number of Data Delay) value must be selected.
 *
 * \param[inout] msc   Pointer to the base address of MSC registers.
 * \param[in]    value Boolean value indicating whether to enable or disable Fast Mode.
 * 					   Range: TRUE  Enables the Fast Mode.
 * 					   		  FALSE Disables the Fast Mode.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setFastMode(Ifx_MSC *msc, boolean value);

/**
 * \brief Configures the fractional divider step for the MSC module's clock generator.
 *
 * \param[inout] msc   Pointer to the base address of MSC registers.
 * \param[in] 	 value The fractional divider step value to be set.
 * 					   Range: 0 to 0x3FF
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setFractionalDividerStep(Ifx_MSC *msc, uint16 value);

/**
 * \brief Configures the N divider downstream value for the MSC module.
 *
 * \param[inout] msc           Pointer to the base address of MSC registers.
 * \param[in]    divisionRatio The desired division ratio.
 * 							   Range: \ref IfxMsc_NDividerDownstream
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setNdividerDownstream(Ifx_MSC *msc, IfxMsc_NDividerDownstream divisionRatio);

/**
 * \brief Enables or disables the Reset Command Extension (CX) mode.
 *
 * \param[inout] msc   Pointer to the base address of MSC registers.
 * \param[in]    value Enable or disable CX mode.
 * 					   Range: TRUE  Activates the CX mode.
 * 					   		  FALSE Deactivates the CX mode.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setResetCommandExtensionMode(Ifx_MSC *msc, boolean value);

/**
 * \brief Configures the serial data input selection for the MSC module.
 *
 * \param[inout] msc    Pointer to the base address of MSC registers.
 * \param[in]    select Serial data input selection.
 * 						Range: \ref IfxMsc_SerialDataInput
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setSerialDataInputSelect(Ifx_MSC *msc, IfxMsc_SerialDataInput select);

/**
 * \brief Sets the sensitivity of the module to the sleep signal.
 *
 * \param[inout] msc  Pointer to the base address of MSC registers.
 * \param[in]    mode Mode selection for sleep sensitivity.
 * 				      Range: \ref IfxMsc_SleepMode
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setSleepMode(Ifx_MSC *msc, IfxMsc_SleepMode mode);

/**
 * \brief Configures the MSC module to the specified suspend mode.
 *
 * \param[inout] msc  Pointer to the base address of MSC registers.
 * \param[in]    mode The suspend mode to configure.
 * 					  Range: \ref IfxMsc_SuspendMode
 *
 * \retval None
 *
 * \note The API works only when the OCDS is enabled and in Supervisor Mode. When OCDS is disabled, the OCS suspend control is ineffective.
 */
IFX_INLINE void IfxMsc_setSuspendMode(Ifx_MSC *msc, IfxMsc_SuspendMode mode);

/**
 * \brief Configures the transmission mode for the MSC module.
 *
 * \param[inout] msc  Pointer to the base address of MSC registers.
 * \param[in]    mode The transmission mode to be set.
 *                	  Range: \ref IfxMsc_TransmissionMode
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setTransmissionMode(Ifx_MSC *msc, IfxMsc_TransmissionMode mode);

/**
 * \brief Sets the upstream channel receive rate for the MSC module.
 *
 * \param[inout] msc         Pointer to the base address of MSC registers.
 * \param[in]    recieveRate The desired receive rate.
 * 							 Range: \ref IfxMsc_UpstreamChannelReceivingRate
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setUpstreamChannelRecieveRate(Ifx_MSC *msc, IfxMsc_UpstreamChannelReceivingRate recieveRate);

/**
 * \brief Sets the upstream timeout value for the MSC module.
 *
 * \param[inout] msc        Pointer to the base address of MSC registers.
 * \param[in]    timeoutVal The upstream timeout value to be set.
 * 					        Range: \ref IfxMsc_UpstreamTimeoutValue
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setUpstreamTimeout(Ifx_MSC *msc, IfxMsc_UpstreamTimeoutValue timeoutVal);

/**
 * \brief Configures the upstream timeout prescaler value for the MSC module.
 *
 * \param[inout] msc       Pointer to the base address of MSC registers.
 * \param[in]    prescalar The prescaler value to be set.
 * 						   Range: \ref IfxMsc_UpstreamTimeoutPrescaler
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setUpstreamTimeoutPrescalar(Ifx_MSC *msc, IfxMsc_UpstreamTimeoutPrescaler prescalar);

/**
 * \brief Checks if an ABRA (Asynchronous Baud Rate Adjustment Block) overflow error has occurred in the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the Overflow error has occurred in the ABRA mechanism.
 * 				   FALSE If no Overflow error has occurred in the ABRA mechanism.
 */
IFX_INLINE boolean IfxMsc_hasAbraOverflowErrorOccured(Ifx_MSC *msc);

/**
 * \brief Checks if an ABRA (Asynchronous Baud Rate Adjustment Block) underflow error has occurred in the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean TRUE  If the underflow error has occurred in the ABRA mechanism.
 * 				   FALSE If no underflow error has occurred in the ABRA mechanism.
 */
IFX_INLINE boolean IfxMsc_hasAbraUnderflowErrorOccured(Ifx_MSC *msc);

/**
 * \brief Sets the Overflow Flag and triggers the overflow interrupt if enabled.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_INLINE void IfxMsc_setAbraOverflowFlag(Ifx_MSC *msc);

/**
 * \brief Sets the Underflow Flag and triggers the underflow interrupt if enabled.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 * 
 * \retval None
 */
IFX_INLINE void IfxMsc_setAbraUnderflowFlag(Ifx_MSC *msc);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Clears the data frame interrupt flag for the MSC module.
 *
 * \param[inout] msc Pointer to the base address of MSC registers.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_clearDataFrameInterruptFlag(Ifx_MSC *msc);

/**
 * \brief Calculates the step value for the specified baud rate when using fractional divider mode for downstream communication.
 *
 * \param[in] msc  Pointer to the base address of MSC registers.
 * \param[in] baud Required baud rate to be configured.
 * 				   Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud)
 *
 * \retval uint64 The calculated step value for the fractional divider mode.
 * 				  Range: 0x8 (for 0.39 Mbaud) to 0x200 (for 25 Mbaud)
 */
IFX_EXTERN uint64 IfxMsc_downstreamFractionalBaudCalculator(Ifx_MSC *msc, uint32 baud);

/**
 * \brief Calculates the step value for the specified baud rate in normal divider mode for downstream communication.
 *
 * \param[in] msc  Pointer to the base address of MSC registers.
 * \param[in] baud The desired baud rate for downstream communication.
 * 				   Range: 0x5F5E1 (0.39 Mbaud) to 0x17D7840 (25 Mbaud)
 *
 * \retval uint32 The calculated step value for the specified baud rate.
 * 				  Range: 0x380 (for 0.39 Mbaud) to 0x3FE (for 25 Mbaud)
 */
IFX_EXTERN uint32 IfxMsc_downstreamNormalBaudCalculator(Ifx_MSC *msc, uint32 baud);

/**
 * \brief Checks if there is an active data frame being processed by the MSC module.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean Status of the active data frame.
 *				   TRUE  If the data frame is currently sent out.
 *				   FALSE If no data frame is currently sent out.
 */
IFX_EXTERN boolean IfxMsc_getActiveDataFrameStatus(Ifx_MSC *msc);

/**
 * \brief Gets the status of the data frame interrupt flag.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval boolean Status of the data frame interrupt flag.
 * 				   TRUE  If the Data frame interrupt is generated.
 * 				   FALSE If the Data frame interrupt is cleared.
 */
IFX_EXTERN boolean IfxMsc_getDataFrameInterruptFlag(Ifx_MSC *msc);

/**
 * \brief Manually loads a 64-bit command to the DCE and DC registers for transmission.
 *
 * \param[inout] msc 	   Pointer to the base address of MSC registers.
 * \param[in]    command64 Pointer to the command structure containing the 64-bit command.
 *                         This structure includes the commands to be written to the DCE
 *                         and DC registers. The DCE command is loaded first, followed by
 *                         the DC command.
 *
 * \retval None
 */
IFX_EXTERN void IfxMsc_manualLoadCxModeCommand(Ifx_MSC *msc, IfxMsc_CxModeCommand *command64);

/**
 * \brief Returns the downstream ABRA baudrate.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval float32 The downstream ABRA baudrate in bits per second (bps).
 */
IFX_EXTERN float32 IfxMsc_getDownstreamAbraBaudrate(Ifx_MSC *msc);

/**
 * \brief Returns the downstream baudrate with ABRA disabled.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval float32 The downstream baudrate value when ABRA is disabled in bits per second (bps).
 */
IFX_EXTERN float32 IfxMsc_getDownstreamAbraDisabledBaudrate(Ifx_MSC *msc);

/**
 * \brief Gets the downstream baudrate for the MSC module.
 *
 * \param[in] msc Pointer to the base address of MSC registers.
 *
 * \retval float32 The current downstream baudrate in bits per second (bps).
 */
IFX_EXTERN float32 IfxMsc_getDownstreamBaudrate(Ifx_MSC *msc);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxMsc_clearAbraOverflowFlag(Ifx_MSC *msc)
{
    /* Overflow Flag Clear */
    msc->ABC.B.OFM = 2;
}


IFX_INLINE void IfxMsc_clearAbraUnderflowFlag(Ifx_MSC *msc)
{
    /* Underflow Flag Clear */
    msc->ABC.B.UFM = 2;
}


IFX_INLINE void IfxMsc_clearRecieveDataInterruptFlag(Ifx_MSC *msc)
{
    msc->ISC.B.CURDI = 0x01U;
}


IFX_INLINE void IfxMsc_clearUpstreamTimeout(Ifx_MSC *msc)
{
    /* Upstream Timeout Clear */
    msc->USCE.B.USTC = 1;
}


IFX_INLINE void IfxMsc_clearUpstreamValidFlag(Ifx_MSC *msc, uint8 upstreamIdx)
{
    msc->UD[upstreamIdx].B.C = 1;
}


IFX_INLINE void IfxMsc_clearValidbit(Ifx_MSC *msc, uint8 upstreamIdx)
{
    msc->UD[upstreamIdx].B.C = 0x01U;
}


IFX_INLINE void IfxMsc_disableUpstreamTimeoutInterrupt(Ifx_MSC *msc)
{
    msc->USCE.B.USTOEN = 0x0U;
}


IFX_INLINE void IfxMsc_enableUpstreamTimeoutInterrupt(Ifx_MSC *msc)
{
    msc->USCE.B.USTOEN = 0x1U;
}


IFX_INLINE boolean IfxMsc_getAsyncClockBypass(Ifx_MSC *msc)
{
    return msc->ABC.B.ABB;
}


IFX_INLINE uint16 IfxMsc_getData(Ifx_MSC *msc, uint8 upstreamIdx)
{
    uint16 data = 0;

    data = msc->UD[upstreamIdx].B.DATA;

    return data;
}


IFX_INLINE IfxMsc_Target IfxMsc_getDataHighTarget(Ifx_MSC *msc)
{
    /* get data high target - en0, en1, en2 or en3 */
    return (IfxMsc_Target)msc->OCR.B.CSH;
}


IFX_INLINE IfxMsc_Target IfxMsc_getDataLowTarget(Ifx_MSC *msc)
{
    /* get data low target - en0, en1, en2 or en3 */
    return (IfxMsc_Target)msc->OCR.B.CSL;
}


IFX_INLINE boolean IfxMsc_getDownStreamExtension(Ifx_MSC *msc)
{
    return msc->DSCE.B.EXEN;
}


IFX_INLINE boolean IfxMsc_getRecieveDataInterruptFlag(Ifx_MSC *msc)
{
    return msc->ISR.B.URDI;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxMsc_getSrcPointer(Ifx_MSC *msc, IfxMsc_InterruptServiceRequest intRequest)
{
    IfxMsc_Index           mscIndex;
    volatile Ifx_SRC_SRCR *src;
    mscIndex = IfxMsc_getIndex(msc);
    src      = &MODULE_SRC.MSC.MSC[mscIndex].SR[intRequest];
    return src;
}


IFX_INLINE uint32 IfxMsc_getUpstreamData(Ifx_MSC *msc, uint8 upstreamIdx)
{
    return msc->UD[upstreamIdx].U;
}


IFX_INLINE boolean IfxMsc_getUpstreamParityErrorFlag(Ifx_MSC *msc, uint8 upstreamIdx)
{
    return msc->UD[upstreamIdx].B.PERR;
}


IFX_INLINE boolean IfxMsc_getUpstreamTimeoutFlag(Ifx_MSC *msc)
{
    return msc->USCE.B.USTF;
}


IFX_INLINE boolean IfxMsc_getUpstreamValidFlag(Ifx_MSC *msc, uint8 upstreamIdx)
{
    boolean flag = 0;

    flag = msc->UD[upstreamIdx].B.V;

    return flag;
}


IFX_INLINE void IfxMsc_initEnPin(const IfxMsc_En_Out *en, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (en->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(en->pin.port, en->pin.pinIndex, pinMode, en->select);
        IfxPort_setPinPadDriver(en->pin.port, en->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxMsc_initFclnPin(const IfxMsc_Fcln_Out *fcln, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (fcln->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(fcln->pin.port, fcln->pin.pinIndex, pinMode, fcln->select);
        IfxPort_setPinPadDriver(fcln->pin.port, fcln->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxMsc_initFclpPin(const IfxMsc_Fclp_Out *fclp, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (fclp->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(fclp->pin.port, fclp->pin.pinIndex, pinMode, fclp->select);
        IfxPort_setPinPadDriver(fclp->pin.port, fclp->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxMsc_initInjPin(const IfxMsc_Inj_In *inj, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (inj->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(inj->pin.port, inj->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(inj->pin.port, inj->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxMsc_initSdiPin(const IfxMsc_Sdi_In *sdi, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (sdi->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeInput(sdi->pin.port, sdi->pin.pinIndex, pinMode);
        IfxPort_setPinPadDriver(sdi->pin.port, sdi->pin.pinIndex, padDriver);
        sdi->module->OCR.B.SDISEL = sdi->select;
    }
}


IFX_INLINE void IfxMsc_initSonPin(const IfxMsc_Son_Out *son, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (son->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(son->pin.port, son->pin.pinIndex, pinMode, son->select);
        IfxPort_setPinPadDriver(son->pin.port, son->pin.pinIndex, padDriver);
    }
}


IFX_INLINE void IfxMsc_initSopPin(const IfxMsc_Sop_Out *sop, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver)
{
    if (sop->pin.port != NULL_PTR)
    {
        IfxPort_setPinModeOutput(sop->pin.port, sop->pin.pinIndex, pinMode, sop->select);
        IfxPort_setPinPadDriver(sop->pin.port, sop->pin.pinIndex, padDriver);
    }
}


IFX_INLINE boolean IfxMsc_isModuleSuspended(Ifx_MSC *msc)
{
    Ifx_MSC_OCS ocs;

    // read the status
    ocs.U = msc->OCS.U;

    // return the status
    return ocs.B.SUSSTA;
}


IFX_INLINE void IfxMsc_setAsyncClockBypass(Ifx_MSC *msc, boolean value)
{
    msc->ABC.B.ABB = value;
}


IFX_INLINE void IfxMsc_setCommandTarget(Ifx_MSC *msc, IfxMsc_Target enX)
{
    /* Set command target - en0, en1, en2 or en3 */
    msc->OCR.B.CSC = enX;
}


IFX_INLINE void IfxMsc_setDataHighTarget(Ifx_MSC *msc, IfxMsc_Target enX)
{
    /* Set data high target - en0, en1, en2 or en3 */
    msc->OCR.B.CSH = enX;
}


IFX_INLINE void IfxMsc_setDataLowTarget(Ifx_MSC *msc, IfxMsc_Target enX)
{
    /* Set data low target - en0, en1, en2 or en3 */
    msc->OCR.B.CSL = enX;
}


IFX_INLINE void IfxMsc_setDownStreamData(Ifx_MSC *msc, uint32 data)
{
    msc->DD.U = data;
}


IFX_INLINE void IfxMsc_setDownStreamExtension(Ifx_MSC *msc, boolean value)
{
    msc->DSCE.B.EXEN = value;
}


IFX_INLINE void IfxMsc_setDownStreamExtensionData(Ifx_MSC *msc, uint32 data)
{
    msc->DDE.U = data;
}


IFX_INLINE void IfxMsc_setFastMode(Ifx_MSC *msc, boolean value)
{
    uint32 bit_pattern;
    uint32 mask = 0x80010000; // Mask to clear the bits(FM & UL1)

    if (value == 1)
    {
        /*set the fast mode bit */
        bit_pattern = 0x80010000; // bit pattern(UL1=1 and FM=1) for activating Fast Mode.It's written with DTSE.U access instead of DTSE.B.<individual_bit_fields> as both UL1 & FM bit fields have to be written at once.
    }
    else
    {
        /*reset the fast mode bit */
        bit_pattern = 0x80000000; // bit pattern(UL1=1 and FM=0) bit pattern for deactivating Fast Mode.It's written with DTSE.U access instead of DTSE.B.<individual_bit_fields> as both UL1 & FM bit fields have to be written at once.
    }

    msc->DSTE.U = (msc->DSTE.U & ~mask) | bit_pattern;
}


IFX_INLINE void IfxMsc_setFractionalDividerStep(Ifx_MSC *msc, uint16 value)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);

    msc->FDR.B.DISCLK = 1;      /* Disable MSC clock*/

    while (msc->FDR.B.DISCLK != 1)
    {}

    /* Configure the DIVIDER STEP */
    msc->FDR.B.STEP   = value;
    msc->FDR.B.DISCLK = 0;      /* Enable MSC clock */

    while (msc->FDR.B.DISCLK != 0)
    {}

    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxMsc_setNdividerDownstream(Ifx_MSC *msc, IfxMsc_NDividerDownstream divisionRatio)
{
    msc->DSTE.B.NDD = divisionRatio;
}


IFX_INLINE void IfxMsc_setResetCommandExtensionMode(Ifx_MSC *msc, boolean value)
{
    uint32 bit_pattern;
    uint32 mask = 0x90000000; // Mask to clear the bits(CX & UL1)

    if (value == 1)
    {
        bit_pattern = 0x90000000; // bit pattern(UL1=1 and CX=1) for activating Command Extension Mode.It's written with DTSE.U access instead of DTSE.B.<individual_bit_fields> as both UL1 & CX bit fields have to be written at once( in a single cycle).
    }
    else
    {
        bit_pattern = 0x80000000; // bit pattern(UL1=1 and CX=0) bit pattern for deactivating Command Extension Mode.It's written with DTSE.U access instead of DTSE.B.<individual_bit_fields> as both UL1 & CX bit fields have to be written at once.
    }

    msc->DSTE.U = (msc->DSTE.U & ~mask) | bit_pattern;
}


IFX_INLINE void IfxMsc_setSerialDataInputSelect(Ifx_MSC *msc, IfxMsc_SerialDataInput select)
{
    msc->OCR.B.SDISEL = select;
}


IFX_INLINE void IfxMsc_setSleepMode(Ifx_MSC *msc, IfxMsc_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    msc->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxMsc_setSuspendMode(Ifx_MSC *msc, IfxMsc_SuspendMode mode)
{
    Ifx_MSC_OCS ocs;

    // remove protection and configure the suspend mode.
    ocs.B.SUS_P = 1;
    ocs.B.SUS   = mode;
    msc->OCS.U  = ocs.U;
}


IFX_INLINE void IfxMsc_setTransmissionMode(Ifx_MSC *msc, IfxMsc_TransmissionMode mode)
{
    msc->DSC.B.TM = mode;
}


IFX_INLINE void IfxMsc_setUpstreamChannelRecieveRate(Ifx_MSC *msc, IfxMsc_UpstreamChannelReceivingRate recieveRate)
{
    msc->USR.B.URR = recieveRate;
}


IFX_INLINE void IfxMsc_setUpstreamTimeout(Ifx_MSC *msc, IfxMsc_UpstreamTimeoutValue timeoutVal)
{
    msc->USCE.B.USTOVAL = timeoutVal;
}


IFX_INLINE void IfxMsc_setUpstreamTimeoutPrescalar(Ifx_MSC *msc, IfxMsc_UpstreamTimeoutPrescaler prescalar)
{
    msc->USCE.B.USTOPRE = prescalar;
}


IFX_INLINE boolean IfxMsc_hasAbraOverflowErrorOccured(Ifx_MSC *msc)
{
    return msc->ABC.B.OVF == 1U;
}


IFX_INLINE boolean IfxMsc_hasAbraUnderflowErrorOccured(Ifx_MSC *msc)
{
    return msc->ABC.B.UNF == 1U;
}


IFX_INLINE void IfxMsc_setAbraOverflowFlag(Ifx_MSC *msc)
{
    /* Set Overflow Flag */
    msc->ABC.B.OFM = 1U;
}


IFX_INLINE void IfxMsc_setAbraUnderflowFlag(Ifx_MSC *msc)
{
    /* Set Underflow Flag */
    msc->ABC.B.UFM = 1U;
}


#endif /* IFXMSC_H */
