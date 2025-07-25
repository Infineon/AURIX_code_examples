/**
 * \file IfxVmt_cfg.c
 * \brief Vmt on-chip implementation data
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxVmt_cfg.h"
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
    {1 * 1, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cssKeyattr */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssKeystore */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssFifo0 */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssFifo1 */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cssContext */
    {1 * 4, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_dma0 */
    {1 * 2, 128, 0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds4pTbuf */
    {1 * 4, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds4pLut */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu0 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu1 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu4 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu5 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu6 */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu2 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu3 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu7 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu8 */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_lmu9 */
    {1 * 4, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_dma1 */
    {1 * 2, 128, 0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds2pTbuf */
    {1 * 2, 32,  0, 0, 1}, /**< \brief IfxVmt_MbistSel_mcds2pLut */
    {1 * 2, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0Obf */
    {1 * 2, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray1Obf */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0IbfTbf */
    {1 * 4, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray1IbfTbf */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray0Mbf */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_eray1Mbf */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_psi5 */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Dspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu3DlmuStby */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu4Dspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu4Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu4Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu4Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu4DlmuStby */
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu5Dspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu5Dtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu5Pspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu5Ptag */
    {2 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_cpu5DlmuStby */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {2 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mod9 */
    {2 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mod10 */
    {1 * 2, 16,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_hsphyPcs0 */
    {1 * 2, 16,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_hsphyPcs1 */
    {1 * 2, 16,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_hsphyPcs2 */
    {1 * 1, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie0DmaRbuf */
    {1 * 1, 46,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie0RxDq */
    {1 * 2, 85,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie0RxHq */
    {1 * 1, 47,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie0RetryBuf */
    {1 * 1, 87,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie0CmplBuf */
    {1 * 4, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_ethermacAxi */
    {1 * 1, 72,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermacDmi */
    {1 * 1, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac0Gcl */
    {1 * 1, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac1Gcl */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac0RxEven */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac0RxOdd */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac1RxEven */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac1RxOdd */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac0TxEven */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac0TxOdd */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac1TxEven */
    {1 * 1, 76,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ethermac1TxOdd */
    {1 * 1, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie1DmaRbuf */
    {1 * 1, 46,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie1RxDq */
    {1 * 2, 85,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie1RxHq */
    {1 * 1, 47,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie1RetryBuf */
    {1 * 1, 87,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_pcie1CmplBuf */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 4, 30,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuIctag */
    {1 * 4, 80,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuIcdata */
    {1 * 4, 28,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuDctag */
    {1 * 4, 80,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuDcdata */
    {1 * 2, 68,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuBc */
    {1 * 2, 16,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuPt */
    {1 * 1, 64,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuRttint */
    {1 * 8, 24,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuVecmem0 */
    {1 * 8, 24,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuVecmem1 */
    {1 * 8, 73,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_ppuLlmramXl */
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
    {2 * 4, 16,  6, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmDspr */
    {2 * 1, 25,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmDtag */
    {1 * 2, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmPspr */
    {2 * 1, 22,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_csrmPtag */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {1 * 2, 68,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_mod8 */
    {1 * 2, 39,  0, 0, 0}, /**< \brief IfxVmt_MbistSel_cdsp0Data */
    {2 * 2, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_cdsp0Prog */
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
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_canxl */
    {1 * 1, 64,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_dreRam */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan0 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan1 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan2 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan3 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_mcan4 */
    {1 * 1, 32,  7, 1, 4}, /**< \brief IfxVmt_MbistSel_sdmmc */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port3TxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0RxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1RxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2RxFifo */
    {1 * 2, 35,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port3RxFifo */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0RxParser */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1RxParser */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2RxParser */
    {1 * 2, 48,  8, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port3RxParser */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port0Gcl */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port1Gcl */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port2Gcl */
    {1 * 1, 29,  7, 0, 1}, /**< \brief IfxVmt_MbistSel_leth0Port3Gcl */
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
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
    {0 * 0, 0,   0, 0, 0}, /**< \brief IfxVmt_MbistSel_none */
};
const IfxVmt_SshSelectionConfig IfxVmt_sramListG1[] = {
		{0, IfxVmt_MbistSel_cpu0Dspr},
		{0, IfxVmt_MbistSel_cpu0Dtag},
		{0, IfxVmt_MbistSel_cpu0Ptag},
		{0, IfxVmt_MbistSel_dma0}

};

const IfxVmt_NumberOfSsh IfxVmt_G1Size = {

		sizeof(IfxVmt_sramListG1) / sizeof(IfxVmt_SshSelectionConfig)
};

const IfxVmt_SshSelectionConfig IfxVmt_sramListG2_1[] = {
		{0, IfxVmt_MbistSel_cpu0Pspr},
		{0, IfxVmt_MbistSel_cpu0DlmuStby},
		{0, IfxVmt_MbistSel_cpu1Dspr},
		{0, IfxVmt_MbistSel_cpu1Dtag},
		{0, IfxVmt_MbistSel_cpu1Pspr},
		{0, IfxVmt_MbistSel_cpu1Ptag},
		{0, IfxVmt_MbistSel_cpu1DlmuStby},
		{0, IfxVmt_MbistSel_cpu2Dspr},
		{0, IfxVmt_MbistSel_cpu2Dtag},
		{0, IfxVmt_MbistSel_cpu2Pspr},
		{0, IfxVmt_MbistSel_cpu2Ptag},
		{0, IfxVmt_MbistSel_cpu2DlmuStby},
		{0, IfxVmt_MbistSel_mcds4pTbuf},
		{0, IfxVmt_MbistSel_mcds4pLut},
		{1, IfxVmt_MbistSel_eray0IbfTbf},
		{1, IfxVmt_MbistSel_eray1IbfTbf},
		{1, IfxVmt_MbistSel_eray0Obf},
		{1, IfxVmt_MbistSel_cpu4Dspr},
		{1, IfxVmt_MbistSel_cpu4Dtag},
		{1, IfxVmt_MbistSel_cpu4Pspr},
		{1, IfxVmt_MbistSel_cpu4Ptag},
		{1, IfxVmt_MbistSel_cpu4DlmuStby},
		{1, IfxVmt_MbistSel_cpu5Dspr},
		{1, IfxVmt_MbistSel_cpu5Dtag},
		{1, IfxVmt_MbistSel_cpu5Pspr},
		{1, IfxVmt_MbistSel_cpu5Ptag},
		{1, IfxVmt_MbistSel_cpu5DlmuStby},
		{5, IfxVmt_MbistSel_canxl},
		{5, IfxVmt_MbistSel_dreRam},
		{5, IfxVmt_MbistSel_mcan0},
		{5, IfxVmt_MbistSel_mcan1},
		{5, IfxVmt_MbistSel_mcan2},
		{5, IfxVmt_MbistSel_mcan3},
		{5, IfxVmt_MbistSel_leth0Port0TxFifo},
		{5, IfxVmt_MbistSel_leth0Port1TxFifo},
		{5, IfxVmt_MbistSel_leth0Port2TxFifo},
		{5, IfxVmt_MbistSel_leth0Port3TxFifo},
		{5, IfxVmt_MbistSel_leth0Port0RxFifo},
		{5, IfxVmt_MbistSel_leth0Port1RxFifo},
		{5, IfxVmt_MbistSel_leth0Port2RxFifo},
		{5, IfxVmt_MbistSel_leth0Port3RxFifo},
		{5, IfxVmt_MbistSel_leth0Port0RxParser},
		{5, IfxVmt_MbistSel_leth0Port1RxParser},
		{5, IfxVmt_MbistSel_leth0Port2RxParser},
		{5, IfxVmt_MbistSel_leth0Port3RxParser},
		{5, IfxVmt_MbistSel_leth0Port0Gcl},
		{5, IfxVmt_MbistSel_leth0Port1Gcl},
		{5, IfxVmt_MbistSel_leth0Port2Gcl},
		{5, IfxVmt_MbistSel_leth0Port3Gcl}



};

const IfxVmt_NumberOfSsh IfxVmt_G2_1Size = {

		sizeof(IfxVmt_sramListG2_1) / sizeof(IfxVmt_SshSelectionConfig)
};

IFX_CONST IfxVmt_SshSelectionConfig IfxVmt_sramListG2_2[] = {
		{2, IfxVmt_MbistSel_pcie0DmaRbuf},
		{2, IfxVmt_MbistSel_pcie0RxDq},
		{2, IfxVmt_MbistSel_pcie0RxHq},
		{2, IfxVmt_MbistSel_pcie0RetryBuf},
		{2, IfxVmt_MbistSel_pcie0CmplBuf},
		{2, IfxVmt_MbistSel_ethermacAxi},
		{2, IfxVmt_MbistSel_ethermacDmi},
		{2, IfxVmt_MbistSel_ethermac0Gcl},
		{2, IfxVmt_MbistSel_ethermac1Gcl},
		{2, IfxVmt_MbistSel_ethermac0RxEven},
		{2, IfxVmt_MbistSel_ethermac0RxOdd},
		{2, IfxVmt_MbistSel_ethermac1RxEven},
		{2, IfxVmt_MbistSel_ethermac1RxOdd},
		{2, IfxVmt_MbistSel_ethermac0TxEven},
		{2, IfxVmt_MbistSel_ethermac0TxOdd},
		{2, IfxVmt_MbistSel_ethermac1TxEven},
		{2, IfxVmt_MbistSel_ethermac1TxOdd},
		{2, IfxVmt_MbistSel_pcie1DmaRbuf},
		{2, IfxVmt_MbistSel_pcie1RxDq},
		{2, IfxVmt_MbistSel_pcie1RxHq},
		{2, IfxVmt_MbistSel_pcie1RetryBuf},
		{2, IfxVmt_MbistSel_pcie1CmplBuf},
		{3, IfxVmt_MbistSel_ppuIctag},
		{3, IfxVmt_MbistSel_ppuIcdata},
		{3, IfxVmt_MbistSel_ppuDctag},
		{3, IfxVmt_MbistSel_ppuDcdata},
		{3, IfxVmt_MbistSel_ppuBc},
		{3, IfxVmt_MbistSel_ppuPt},
		{3, IfxVmt_MbistSel_ppuRttint},
		{3, IfxVmt_MbistSel_ppuVecmem0},
		{3, IfxVmt_MbistSel_ppuVecmem1},
		{3, IfxVmt_MbistSel_ppuLlmramXl},
		{6, IfxVmt_MbistSel_scrXraml}
};

const IfxVmt_NumberOfSsh IfxVmt_G2_2Size = {

		sizeof(IfxVmt_sramListG2_2) / sizeof(IfxVmt_SshSelectionConfig)
};
