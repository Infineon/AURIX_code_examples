/**
 * \file ConfigurationIsr.h
 * \brief Interrupts configuration.
 *
 *
 * \version iLLD_Demos_0_1_0_11
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Demo_QspiDmaDemo_SrcDoc_InterruptConfig Interrupt configuration
 * \ingroup IfxLld_Demo_QspiDmaDemo_SrcDoc
 */

#ifndef CONFIGURATIONISR_H
#define CONFIGURATIONISR_H

#include <_Impl/IfxSrc_cfg.h>
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Build the ISR configuration object
 * \param no interrupt priority
 * \param cpu assign CPU number
 */
#define ISR_ASSIGN(no, cpu)  ((no << 8) + cpu)

/** \brief extract the priority out of the ISR object */
#define ISR_PRIORITY(no_cpu) (no_cpu >> 8)

/** \brief extract the service provider  out of the ISR object */
#define ISR_PROVIDER(no_cpu) (no_cpu % 8)
/**
 * \addtogroup IfxLld_Demo_QspiDmaDemo_SrcDoc_InterruptConfig
 * \{ */

/**
 * \name Interrupt priority configuration for CPU.
 * The interrupt priority range is [1,255]
 * \{
 */

#define ISR_PRIORITY_MEASUREMENT    1  /**< \brief Define the GPT compare match interrupt priority.  */

#define ISR_PRIORITY_CPUSRV0        2  /**< \brief Define the conio periodic interrupt priority must be lower than QSPIx priorities.  */

#define ISR_PRIORITY_RTC_CAL_F      5  /**< \brief Define the RTC Calibration Measurement Finished interrupt priority must be lower than QSPI.  */

#define ISR_PRIORITY_QSPI1_ER       10  /**< \brief Define the Qspi1 error interrupt priority.  */

#define ISR_PRIORITY_QSPI2_ER       11  /**< \brief Define the Qspi2 error interrupt priority.  */

#define ISR_PRIORITY_QSPI0_ER       12  /**< \brief Define the Qspi0 error interrupt priority.  */

#define ISR_PRIORITY_QSPI3_ER       13  /**< \brief Define the Qspi3 error interrupt priority.  */

#define ISR_PRIORITY_QSPI4_ER       14  /**< \brief Define the Qspi4 error interrupt priority.  */

#define ISR_PRIORITY_BACKLIGHT      15  /**< \brief Define the TOMx_x compare match interrupt priority.  */

#define ISR_PRIORITY_QSPI3_TX       30  /**< \brief Define the Qspi3 transmit interrupt priority.  */

#define ISR_PRIORITY_QSPI0_TX       31  /**< \brief Define the Qspi0 transmit interrupt priority.  */

#define ISR_PRIORITY_QSPI1_TX       32  /**< \brief Define the Qspi1 transmit interrupt priority.  */

#define ISR_PRIORITY_QSPI2_TX       33  /**< \brief Define the Qspi2 transmit interrupt priority.  */

#define ISR_PRIORITY_QSPI4_TX       34  /**< \brief Define the Qspi4 transmit interrupt priority.  */

#define ISR_PRIORITY_QSPI3_RX       50  /**< \brief Define the Qspi3 receive interrupt priority.  */

#define ISR_PRIORITY_QSPI0_RX       51  /**< \brief Define the Qspi0 receive interrupt priority.  */

#define ISR_PRIORITY_QSPI1_RX       52  /**< \brief Define the Qspi1 receive interrupt priority.  */

#define ISR_PRIORITY_QSPI2_RX       53  /**< \brief Define the Qspi2 receive interrupt priority.  */

#define ISR_PRIORITY_QSPI4_RX       54  /**< \brief Define the Qspi4 receive interrupt priority.  */

#define ISR_PRIORITY_OS_TICK        64  /**< \brief Define the TFT refresh interrupt priority.  */

#define ISR_PRIORITY_ETHERNET       70  /**< \brief Define the Ethernet interrupt priority.  */

#define ISR_PRIORITY_RTC_ALARM      128 /**< \brief Define the RTC alarm interrupt priority.  */

#define ISR_PRIORITY_PERF_MEAS      255 /**< \brief Define the TOMx_x interrupt priority.  */

/** \} */

/**
 * \name DMA channel configuration.
 * The DMA channel range is [0,15] for TC22X/TC23X
 * \{
 */

#define TFT_DMA_CH_TXBUFF_TO_TXFIFO        0 /**< \brief Dma channel used for TFT Master Qspi Transmit  */
#define TFT_DMA_CH_RXBUFF_FROM_RXFIFO      1 /**< \brief Dma channel used for TFT Master Qspi Receive  */
#define SDCARD_DMA_CH_TXBUFF_TO_TXFIFO     2 /**< \brief Dma channel used for SDCARD Master Qspi Transmit  */
#define SDCARD_DMA_CH_RXBUFF_FROM_RXFIFO   3 /**< \brief Dma channel used for SDCARD Master Qspi Receive  */

/** \} */

/**
 * \name Interrupt service provider configuration (use only number for variable section definition).
 * \{ */
#define ISR_PROVIDER_QSPI0          2     /**< \brief Define the Qspi0 interrupt provider.  */

#define ISR_PROVIDER_QSPI1          0     /**< \brief Define the Qspi1 interrupt provider.  */

#define ISR_PROVIDER_QSPI2          0     /**< \brief Define the Qspi2 interrupt provider.  */

#define ISR_PROVIDER_QSPI3          0     /**< \brief Define the Qspi3 interrupt provider.  */

#define ISR_PROVIDER_QSPI4          0     /**< \brief Define the Qspi4 interrupt provider.  */

#define ISR_PROVIDER_MEASUREMENT    0     /**< \brief Define the GPT compare match interrupt provider. */

#define ISR_PROVIDER_PERF_MEAS      1     /**< \brief Define the TOMx_x compare match interrupt provider. */

#define ISR_PROVIDER_BACKLIGHT      0     /**< \brief Define the TOMx_x compare match interrupt provider. */

#define ISR_PROVIDER_CPUSRV0        2     /**< \brief Define the touch data receive interrupt provider.  */

#define ISR_PROVIDER_RTC_ALARM      1     /**< \brief Define the RTC alarm interrupt provider.  */

#define ISR_PROVIDER_OS_TICK        0     /**< \brief Define the tft refresh interrupt provider.  */

#define ISR_PROVIDER_I2C            1     /**< \brief Define the I2c interrupt provider.  */

#define ISR_PROVIDER_ETHERNET       0     /**< \brief Define the Ethernet interrupt provider.  */

/** \} */

//------------------------------------------------------------------------------

#endif
