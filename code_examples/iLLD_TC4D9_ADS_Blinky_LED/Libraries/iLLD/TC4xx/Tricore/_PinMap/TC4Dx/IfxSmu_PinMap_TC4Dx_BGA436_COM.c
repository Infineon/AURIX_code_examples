/**
 * \file IfxSmu_PinMap_TC4Dx_BGA436_COM.c
 * \brief SMU  details
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
#include "IfxSmu_PinMap_TC4Dx_BGA436_COM.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IfxSmu_Ext_emergencystop_req_In IfxSmu_EXT_EMERGENCYSTOP_REQ_P21_2_IN = {&MODULE_SMU, {&MODULE_P21, 2}, Ifx_RxSel_a};

IfxSmu_Fsp_Out                  IfxSmu_FSP0_P33_8_OUT = {&MODULE_SMU, {&MODULE_P33, 8}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP1_P33_12_OUT = {&MODULE_SMU, {&MODULE_P33, 12}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP2_P32_2_OUT = {&MODULE_SMU, {&MODULE_P32, 2}, IfxPort_OutputIdx_general};

IfxSmu_Fsp_Out                  IfxSmu_FSP3_P32_5_OUT = {&MODULE_SMU, {&MODULE_P32, 5}, IfxPort_OutputIdx_general};

IfxSmu_Fspin_In                 IfxSmu_FSPIN0_P33_8_IN = {&MODULE_SMU, {&MODULE_P33, 8}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN1_P33_12_IN = {&MODULE_SMU, {&MODULE_P33, 12}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN2_P32_2_IN = {&MODULE_SMU, {&MODULE_P32, 2}, Ifx_RxSel_a};

IfxSmu_Fspin_In                 IfxSmu_FSPIN3_P32_5_IN = {&MODULE_SMU, {&MODULE_P32, 5}, Ifx_RxSel_a};

/** \addtogroup IfxLld_Smu__PinTables
 * \{ */

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxSmu_Ext_emergencystop_req_In *IfxSmu_Ext_emergencystop_req_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_EXT_EMERGENCYSTOP_REQ_IN_NUM_ITEMS] = {
    {
        &IfxSmu_EXT_EMERGENCYSTOP_REQ_P21_2_IN,
    },
};

IFX_CONST IfxSmu_Fsp_Out                  *IfxSmu_Fsp_Out_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSP_OUT_NUM_ITEMS] = {
    {
        &IfxSmu_FSP2_P32_2_OUT,
        &IfxSmu_FSP3_P32_5_OUT,
        &IfxSmu_FSP0_P33_8_OUT,
        &IfxSmu_FSP1_P33_12_OUT,
    },
};

IFX_CONST IfxSmu_Fspin_In                 *IfxSmu_Fspin_In_pinTable[IFXSMU_PINMAP_NUM_MODULES][IFXSMU_PINMAP_FSPIN_IN_NUM_ITEMS] = {
    {
        &IfxSmu_FSPIN2_P32_2_IN,
        &IfxSmu_FSPIN3_P32_5_IN,
        &IfxSmu_FSPIN0_P33_8_IN,
        &IfxSmu_FSPIN1_P33_12_IN,
    },
};

/** \} */

#endif
