/**
 * \file IfxFft_cfg.h
 * \brief FFT on-chip implementation data
 * \ingroup IfxLld_Fft
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Fft FFT
 * \ingroup IfxLld
 * \defgroup IfxLld_Fft_Impl Implementation
 * \ingroup IfxLld_Fft
 * \defgroup IfxLld_Fft_Std Standard Driver
 * \ingroup IfxLld_Fft
 */

#ifndef IFXFFT_CFG_H
#define IFXFFT_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Data space starting address
 */
#define IFXFFT_DATA_SPACE           0xBE000000U

/** \brief Window coefficient space starting address
 */
#define IFXFFT_WINDOW_SPACE         0xBE100000U

/** \brief Maximim possible length of the transform
 */
#define IFXFFT_MAX_LENGTH           2048

#define IFXFFT_MAX_WINDOW_LENGTH    (IFXFFT_MAX_LENGTH / 2)

#define IFXFFT_FFT_DMA_SUPPORT      (1)

#define IFXFFT_FFT_OPTIMIZED        (0)

#define IFXFFT_FFT_DMA_CHANNEL_BASE 4

#define IFXFFT_FFT_PIPELINED        (1)

#define IFXFFT_FFT_NUM_JOBS         (8)

#define IFXFFT_NUM_MODULES          (1)

#endif /* IFXFFT_CFG_H */
