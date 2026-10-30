/**
 * \file IfxMsc_PinMap_TC4Dx_BGA436_COM.c
 * \brief MSC  details
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

#if defined(__TASKING__)
#pragma warning 508
#endif

#if defined(__ghs__)
#pragma ghs nowarning 96
#endif
#include "Ifx_PinMap.h"
#if defined(DEVICE_TC4DX) && defined(IFX_PIN_PACKAGE_BGA436_COM)
#include "IfxMsc_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxMsc_En_Out   IfxMsc0_EN0_P10_10_OUT = {&MODULE_MSC0, 0, {&MODULE_P10, 10}, IfxPort_OutputIdx_alt3};

IfxMsc_En_Out   IfxMsc0_EN0_P10_2_OUT = {&MODULE_MSC0, 0, {&MODULE_P10, 2}, IfxPort_OutputIdx_alt4};

IfxMsc_En_Out   IfxMsc0_EN0_P10_3_OUT = {&MODULE_MSC0, 0, {&MODULE_P10, 3}, IfxPort_OutputIdx_alt4};

IfxMsc_En_Out   IfxMsc0_EN0_P10_4_OUT = {&MODULE_MSC0, 0, {&MODULE_P10, 4}, IfxPort_OutputIdx_alt5};

IfxMsc_En_Out   IfxMsc0_EN0_P14_10_OUT = {&MODULE_MSC0, 0, {&MODULE_P14, 10}, IfxPort_OutputIdx_alt3};

IfxMsc_En_Out   IfxMsc0_EN0_P14_14_OUT = {&MODULE_MSC0, 0, {&MODULE_P14, 14}, IfxPort_OutputIdx_alt14};

IfxMsc_En_Out   IfxMsc0_EN0_P15_5_OUT = {&MODULE_MSC0, 0, {&MODULE_P15, 5}, IfxPort_OutputIdx_alt5};

IfxMsc_En_Out   IfxMsc0_EN1_P10_1_OUT = {&MODULE_MSC0, 1, {&MODULE_P10, 1}, IfxPort_OutputIdx_alt4};

IfxMsc_En_Out   IfxMsc0_EN1_P10_9_OUT = {&MODULE_MSC0, 1, {&MODULE_P10, 9}, IfxPort_OutputIdx_alt3};

IfxMsc_En_Out   IfxMsc0_EN1_P13_0_OUT = {&MODULE_MSC0, 1, {&MODULE_P13, 0}, IfxPort_OutputIdx_alt4};

IfxMsc_En_Out   IfxMsc0_EN1_P14_13_OUT = {&MODULE_MSC0, 1, {&MODULE_P14, 13}, IfxPort_OutputIdx_alt14};

IfxMsc_En_Out   IfxMsc0_EN1_P14_9_OUT = {&MODULE_MSC0, 1, {&MODULE_P14, 9}, IfxPort_OutputIdx_alt3};

IfxMsc_En_Out   IfxMsc0_EN1_P15_3_OUT = {&MODULE_MSC0, 1, {&MODULE_P15, 3}, IfxPort_OutputIdx_alt5};

IfxMsc_Fcln_Out IfxMsc0_FCLN_P13_0_OUT = {&MODULE_MSC0, {&MODULE_P13, 0}, IfxPort_OutputIdx_alt5};

IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_1_OUT = {&MODULE_MSC0, {&MODULE_P13, 1}, IfxPort_OutputIdx_alt5};

IfxMsc_Fclp_Out IfxMsc0_FCLP_P13_2_OUT = {&MODULE_MSC0, {&MODULE_P13, 2}, IfxPort_OutputIdx_alt4};

IfxMsc_Inj_In   IfxMsc0_INJ0_P00_0_IN = {&MODULE_MSC0, {&MODULE_P00, 0}, Ifx_RxSel_a};

IfxMsc_Inj_In   IfxMsc0_INJ1_P10_5_IN = {&MODULE_MSC0, {&MODULE_P10, 5}, Ifx_RxSel_b};

IfxMsc_Sdi_In   IfxMsc0_SDI1_P10_2_IN = {&MODULE_MSC0, {&MODULE_P10, 2}, Ifx_RxSel_b};

IfxMsc_Sdi_In   IfxMsc0_SDI2_P14_3_IN = {&MODULE_MSC0, {&MODULE_P14, 3}, Ifx_RxSel_c};

IfxMsc_Sdi_In   IfxMsc0_SDI4_P14_11_IN = {&MODULE_MSC0, {&MODULE_P14, 11}, Ifx_RxSel_e};

IfxMsc_Sdi_In   IfxMsc0_SDI5_P10_3_IN = {&MODULE_MSC0, {&MODULE_P10, 3}, Ifx_RxSel_f};

IfxMsc_Sdi_In   IfxMsc0_SDI6_P10_14_IN = {&MODULE_MSC0, {&MODULE_P10, 14}, Ifx_RxSel_g};

IfxMsc_Son_Out  IfxMsc0_SON_P13_2_OUT = {&MODULE_MSC0, {&MODULE_P13, 2}, IfxPort_OutputIdx_alt5};

IfxMsc_Sop_Out  IfxMsc0_SOP_P13_3_OUT = {&MODULE_MSC0, {&MODULE_P13, 3}, IfxPort_OutputIdx_alt5};

/** \addtogroup IfxLld_Msc__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxMsc_En_Out   *IfxMsc_En_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_NUM_TARGETS][IFXMSC_PINMAP_EN_OUT_NUM_ITEMS] = {
    {
        {
            &IfxMsc0_EN0_P10_2_OUT,
            &IfxMsc0_EN0_P10_3_OUT,
            &IfxMsc0_EN0_P10_4_OUT,
            &IfxMsc0_EN0_P10_10_OUT,
            &IfxMsc0_EN0_P14_10_OUT,
            &IfxMsc0_EN0_P14_14_OUT,
            &IfxMsc0_EN0_P15_5_OUT,
        },
        {
            &IfxMsc0_EN1_P10_1_OUT,
            &IfxMsc0_EN1_P10_9_OUT,
            &IfxMsc0_EN1_P13_0_OUT,
            &IfxMsc0_EN1_P14_9_OUT,
            &IfxMsc0_EN1_P14_13_OUT,
            &IfxMsc0_EN1_P15_3_OUT,
            NULL_PTR,
        },
    },
};

IFX_CONST IfxMsc_Fcln_Out *IfxMsc_Fcln_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLN_OUT_NUM_ITEMS] = {
    {
        &IfxMsc0_FCLN_P13_0_OUT,
    },
};

IFX_CONST IfxMsc_Fclp_Out *IfxMsc_Fclp_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_FCLP_OUT_NUM_ITEMS] = {
    {
        &IfxMsc0_FCLP_P13_1_OUT,
        &IfxMsc0_FCLP_P13_2_OUT,
    },
};

IFX_CONST IfxMsc_Inj_In   *IfxMsc_Inj_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_INJ_IN_NUM_ITEMS] = {
    {
        &IfxMsc0_INJ0_P00_0_IN,
        &IfxMsc0_INJ1_P10_5_IN,
    },
};

IFX_CONST IfxMsc_Sdi_In   *IfxMsc_Sdi_In_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SDI_IN_NUM_ITEMS] = {
    {
        NULL_PTR,
        &IfxMsc0_SDI1_P10_2_IN,
        &IfxMsc0_SDI2_P14_3_IN,
        NULL_PTR,
        &IfxMsc0_SDI4_P14_11_IN,
        &IfxMsc0_SDI5_P10_3_IN,
        &IfxMsc0_SDI6_P10_14_IN,
    },
};

IFX_CONST IfxMsc_Son_Out  *IfxMsc_Son_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SON_OUT_NUM_ITEMS] = {
    {
        &IfxMsc0_SON_P13_2_OUT,
    },
};

IFX_CONST IfxMsc_Sop_Out  *IfxMsc_Sop_Out_pinTable[IFXMSC_PINMAP_NUM_MODULES][IFXMSC_PINMAP_SOP_OUT_NUM_ITEMS] = {
    {
        &IfxMsc0_SOP_P13_3_OUT,
    },
};

/** \} */

#endif
