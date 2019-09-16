/**
 * \file IfxMtu_cfg.c
 * \brief Mtu on-chip implementation data
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2016 Infineon Technologies AG. All rights reserved.
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

#include "IfxMtu_cfg.h"
#include "Mtu/Std/IfxMtu.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

const IfxMtu_SramItem IfxMtu_sramTable[IFXMTU_NUM_MBIST_TABLE_ITEMS] = {
    {2 * 4, 16,  6,  0, 1, 7936}, /**< \brief IfxMtu_MbistSel_cpu2Dspr0 */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {2 * 1, 20,  10, 0, 4, 128 }, /**< \brief IfxMtu_MbistSel_cpu2Dtag */
    {1 * 2, 64,  8,  0, 1, 4096}, /**< \brief IfxMtu_MbistSel_cpu2Pspr */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {2 * 1, 19,  10, 0, 4, 512 }, /**< \brief IfxMtu_MbistSel_cpu2Ptag */
    {2 * 4, 16,  6,  0, 1, 7936}, /**< \brief IfxMtu_MbistSel_cpu1Dspr0 */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {2 * 1, 20,  10, 0, 4, 128 }, /**< \brief IfxMtu_MbistSel_cpu1Dtag */
    {1 * 2, 64,  8,  0, 1, 4096}, /**< \brief IfxMtu_MbistSel_cpu1Pspr */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {2 * 1, 19,  10, 0, 4, 512 }, /**< \brief IfxMtu_MbistSel_cpu1Ptag */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 128, 9,  0, 1, 256 }, /**< \brief IfxMtu_MbistSel_miniMcds */
    {2 * 4, 16,  6,  0, 1, 8192}, /**< \brief IfxMtu_MbistSel_cpu0Dspr */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 64,  8,  0, 1, 3072}, /**< \brief IfxMtu_MbistSel_cpu0Pspr */
    {2 * 1, 20,  10, 0, 4, 256 }, /**< \brief IfxMtu_MbistSel_cpu0Ptag */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {2 * 1, 20,  10, 0, 4, 128 }, /**< \brief IfxMtu_MbistSel_cpu0Dtag */
    {2 * 4, 16,  6,  0, 1, 7936}, /**< \brief IfxMtu_MbistSel_cpu1Dspr1 */
    {2 * 4, 16,  6,  0, 1, 7936}, /**< \brief IfxMtu_MbistSel_cpu2Dspr1 */
    {1 * 2, 35,  7,  0, 1, 1024}, /**< \brief IfxMtu_MbistSel_ethermac */
    {1 * 4, 32,  7,  5, 6, 256 }, /**< \brief IfxMtu_MbistSel_mod1 */
    {1 * 4, 24,  6,  0, 1, 64  }, /**< \brief IfxMtu_MbistSel_mod2 */
    {1 * 2, 32,  7,  5, 6, 5120}, /**< \brief IfxMtu_MbistSel_mod3 */
    {1 * 1, 64,  8,  0, 1, 4096}, /**< \brief IfxMtu_MbistSel_mod4 */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 2, 29,  7,  0, 1, 1024}, /**< \brief IfxMtu_MbistSel_gtmFifo */
    {1 * 6, 32,  7,  5, 6, 1024}, /**< \brief IfxMtu_MbistSel_gtmMcs0 */
    {1 * 6, 32,  7,  5, 6, 512 }, /**< \brief IfxMtu_MbistSel_gtmMcs1 */
    {1 * 1, 24,  6,  1, 2, 128 }, /**< \brief IfxMtu_MbistSel_gtmDpll1a */
    {1 * 1, 24,  6,  1, 2, 384 }, /**< \brief IfxMtu_MbistSel_gtmDpll1b */
    {1 * 1, 24,  6,  1, 2, 4096}, /**< \brief IfxMtu_MbistSel_gtmDpll2 */
    {1 * 1, 32,  7,  5, 6, 320 }, /**< \brief IfxMtu_MbistSel_psi5 */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 1, 32,  7,  5, 6, 2368}, /**< \brief IfxMtu_MbistSel_mcan */
    {1 * 1, 32,  7,  5, 6, 1152}, /**< \brief IfxMtu_MbistSel_mcan1 */
    {1 * 2, 32,  7,  5, 6, 64  }, /**< \brief IfxMtu_MbistSel_erayObf */
    {1 * 4, 32,  7,  5, 6, 128 }, /**< \brief IfxMtu_MbistSel_erayIbfTbf */
    {1 * 1, 32,  7,  5, 6, 4096}, /**< \brief IfxMtu_MbistSel_erayMbf */
    {1 * 2, 32,  7,  5, 6, 64  }, /**< \brief IfxMtu_MbistSel_eray1Obf */
    {1 * 4, 32,  7,  5, 6, 128 }, /**< \brief IfxMtu_MbistSel_eray1IbfTbf */
    {1 * 1, 32,  7,  5, 6, 4096}, /**< \brief IfxMtu_MbistSel_eray1Mbf */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 4, 32,  7,  5, 6, 1024}, /**< \brief IfxMtu_MbistSel_mcds */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem0 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem1 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem2 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem3 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem4 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem5 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem6 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem7 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem8 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem9 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem10 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem11 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem12 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem13 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem14 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_emem15 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper0 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper1 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper2 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper3 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper4 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper5 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper6 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper7 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper8 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper9 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper10 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper11 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper12 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper13 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper14 */
    {1 * 2, 128, 9,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_ememUpper15 */
    {1 * 4, 8,   5,  0, 2, 5120}, /**< \brief IfxMtu_MbistSel_cifJpeg1_4 */
    {1 * 1, 64,  8,  0, 1, 4096}, /**< \brief IfxMtu_MbistSel_lmu */
    {1 * 2, 8,   5,  0, 2, 384 }, /**< \brief IfxMtu_MbistSel_cifJpeg3 */
    {1 * 1, 36,  8,  0, 1, 512 }, /**< \brief IfxMtu_MbistSel_cifCif */
    {0 * 0, 0,   0,  0, 0, 0   }, /**< \brief IfxMtu_MbistSel_none */
    {1 * 4, 64,  8,  0, 1, 256 }, /**< \brief IfxMtu_MbistSel_dma */
    {1 * 2, 128, 9,  0, 1, 256 }, /**< \brief IfxMtu_MbistSel_ememXtm0 */
    {1 * 2, 128, 9,  0, 1, 256 }, /**< \brief IfxMtu_MbistSel_ememXtm1 */
    {1 * 4, 64,  8,  0, 1, 2048}, /**< \brief IfxMtu_MbistSel_fft0 */
    {1 * 1, 16,  6,  0, 1, 1024}, /**< \brief IfxMtu_MbistSel_fft1 */
};
