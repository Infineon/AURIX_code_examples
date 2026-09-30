/**
 * \file IfxVmt_cfg_TC48x.c
 * \brief Vmt on-chip implementation data
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC48X)

#include "_Impl/IfxVmt_cfg.h"
#include "Vmt/Std/IfxVmt.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxVmt_SramItem IfxVmt_sramTable[IFXVMT_NUM_MBIST_TABLE_ITEMS] = {
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu0Dspr0 */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu0Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu0Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu0Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu0DlmuStby */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 4, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_dma */
    {1 * 2, 128, 0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds4pTbuf */
    {1 * 4, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds4pLut */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cssKeyattr */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssKeystore */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssFifo0 */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssFifo1 */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssContext */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan0 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan1 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan2 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Dspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Dlmu */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmDspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmDtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmPspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmPtag */
    {1 * 2, 68,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_mod8 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan3 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan4 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_canxl */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_dreRam */
    {1 * 2, 16,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_hsphyPcs0 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_sdmmc */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0RxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1RxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2RxFifo */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0RxParser */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1RxParser */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2RxParser */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0Gcl */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1Gcl */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2Gcl */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 72,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermacDmi */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermacGcl */
    {1 * 4, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_xgmacRxTx */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_psi5 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 2, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0Obf */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0IbfTbf */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0Mbf */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 3, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_cdsp0Data */
    {2 * 3, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cdsp0Prog */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {4 * 1, 8,   0, 0, 1}, /**< \brief IfxVmt_MbistSel_scrXraml */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu1Dspr0 */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu1Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu1Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu1Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu1DlmuStby */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu2Dspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu2Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu2Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu2Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu2DlmuStby */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 1, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_audioTdm */
    {1 * 1, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_audioMixerIn */
    {1 * 1, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_audioMixerOut */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
};

#endif /* #if defined DEVICE_TC48X */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
