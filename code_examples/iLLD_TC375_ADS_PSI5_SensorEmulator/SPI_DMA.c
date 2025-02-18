/**********************************************************************************************************************
 * \file SPI_DMA.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include <stdio.h>
#include "_Utilities/Ifx_Assert.h"
#include "SPI_DMA.h"
#include "IfxPort.h"
#include "IfxPsi5_Psi5.h"    
#include "IfxSrc_regdef.h"
#include "Psi5Demo.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define QSPI1_MASTER                &MODULE_QSPI1          /* SPI Master Hardware module                             */
#define ISR_PRIORITY_QSPI1_ER       10u                    /* Define the QSPI1 error interrupt priority              */
#define ISR_PRIORITY_DMA_CH1        50u                    /* Define the DMA channel1 interrupt priority             */
#define ISR_PROVIDER_QSPI1          IfxSrc_Tos_cpu0        /* Define the QSPI1 interrupt provider                    */
#define MASTER_CHANNEL_BAUDRATE     1000000u               /* Master channel baud rate                               */
#define MANCHESTER_BIT_1            0xF0u                  /* Manchester encoded value for bit 0                     */
#define MANCHESTER_BIT_0            0x0Fu                  /* Manchester encoded value for bit 1                     */
#define DATA_E_OK                   0u                     /* SPI data successfully transmitted                      */
#define DATA_E_NOK                 -1                      /* SPI data not transmitted                               */
#define DATA_TO_TRANSFER            20u                    /* SPI Buffer size equal to PSI frame with 10bits payload */

/* In this code example,
 * PSI5 - 28 data bits , 2 Start bits and 1 parity bit and first 7 bits
 * are dummy 0s as SPI MOSI pin idle state is high and can't detect
 * the PSI5 start bits. Total 38 bits. */
#define PSI_DATA_SIZE               38u

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
static qspiDma g_qspiDma;                                        /* Global handle for QSPI communication             */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void initQSPI1Master(void);
static void initQSPI1MasterChannel(void);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(QSPI1ErrorISR, 0, ISR_PRIORITY_QSPI1_ER);         /* SPI Master Error Interrupt definition            */
IFX_INTERRUPT(DMAChn1ISR, 0, ISR_PRIORITY_DMA_CH1);             /* DMA Channel 1 Interrupt definition               */

/* Handle QSPI1 Error interrupt */
void QSPI1ErrorISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_qspiDma.spiMaster);
}

/* Handle DMA Channel 1 interrupt */
void DMAChn1ISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrDmaTransmit(&g_qspiDma.spiMaster);
}

/* This function initializes QSPI1 in master mode */
static void initQSPI1Master(void)
{
    IfxQspi_SpiMaster_Config spiMasterConfig;                           /* Define the Master Configuration          */

    IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, QSPI1_MASTER); /* Initialize it with default values        */

    const IfxQspi_SpiMaster_Pins QSPI1Masterpins = {
            &IfxQspi1_SCLK_P10_2_OUT, IfxPort_OutputMode_pushPull,          /* SCLK Pin                          (CLK)  */
            &IfxQspi1_MTSR_P10_3_OUT, IfxPort_OutputMode_pushPull,          /* Master Transmit Slave Receive Pin (MOSI) */
            &IfxQspi1_MRSTA_P10_1_IN, IfxPort_InputMode_pullDown,           /* Master Receive Slave Transmit Pin (MISO) */
            IfxPort_PadDriver_cmosAutomotiveSpeed3                          /* Pad driver mode                          */
    };
    spiMasterConfig.pins = &QSPI1Masterpins;                            /* Assign Master Pins                       */
    
    spiMasterConfig.dma.useDma = TRUE;
    spiMasterConfig.dma.txDmaChannelId = IfxDma_ChannelId_1;
    spiMasterConfig.dma.rxDmaChannelId = IfxDma_ChannelId_2;
    
    spiMasterConfig.base.txPriority = ISR_PRIORITY_DMA_CH1;
    spiMasterConfig.base.erPriority = ISR_PRIORITY_QSPI1_ER;
    spiMasterConfig.base.isrProvider = ISR_PROVIDER_QSPI1;

    /* Initialize the QSPI Master module using the user configuration */
    IfxQspi_SpiMaster_initModule(&g_qspiDma.spiMaster, &spiMasterConfig);
}

/*  This function initializes QSPI1 channel. */
static void initQSPI1MasterChannel(void)
{
    IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;             /* Define the Master Channel Configuration  */

    IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig, &g_qspiDma.spiMaster); /* Initialize it with default values */

    spiMasterChannelConfig.base.baudrate = MASTER_CHANNEL_BAUDRATE;                     /* Set SCLK frequency to 1 MHz      */

    const IfxQspi_SpiMaster_Output QSPI1SlaveSelect = {
            &IfxQspi1_SLSO9_P10_5_OUT, IfxPort_OutputMode_pushPull,         /* Slave Select Pin (CS)                    */
            IfxPort_PadDriver_cmosAutomotiveSpeed1                          /* Pad driver mode                          */
    };
    spiMasterChannelConfig.sls.output = QSPI1SlaveSelect;

    /* Initialize the QSPI Master channel using the user configuration */
    IfxQspi_SpiMaster_initChannel(&g_qspiDma.spiMasterChannel, &spiMasterChannelConfig);

}

/* This function initializes the LED */
void initLED(void)
{
    /* Set the port pin 00.5 (to which the LED1 is connected) to output push-pull mode */
    IfxPort_setPinModeOutput(LED1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    /* Set the port pin 00.6 (to which the LED1 is connected) to output push-pull mode */
    IfxPort_setPinModeOutput(LED2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    /* Turn off the LED (LED is low-level active) */
    IfxPort_setPinHigh(LED1);
    IfxPort_setPinHigh(LED2);
}

/* This function initializes the QSPI modules */
void initQSPI(void)
{
    /* initialize the Master */
    initQSPI1Master();
    initQSPI1MasterChannel();
}

/* This function ensures the QSPI communication between Master and Slave and checks whether
 * the data transfer was correct or not
 */
uint8 transferData(const uint32 data,  uint8 len)
{
    SpiIf_Status ret_status = SpiIf_Status_unknown;
    uint8 manschterbuffer[PSI_DATA_SIZE];     /* Manchester encoded data Buffer */
    uint16 mask = 0u;
    uint8 i = 0u;
    /* used ManchesterBuffer initialized to 3 in order to skip the start bits and */
    uint8 j = 3u;
    uint8 Cnt_parity= 0u;
    uint16 firstXbits = 0u;
    boolean binarynum[len];

    /*extract desired bits from the data */
    mask = (1 << len) - 1;
    firstXbits = ((uint16)data & mask);

    /*convert decimal to binary */
    while (firstXbits > 0)
    {
        binarynum[i] = firstXbits % 2;
        firstXbits = firstXbits / 2;
        i++;
    }

    /*send first byte as '0' for PSI5 to detect the rising edge of the Start bits and to avoid CRCI error  */
    manschterbuffer[0] = 0;
    /*Update Start bits S0 and S1  */
    manschterbuffer[1] = MANCHESTER_BIT_0;
    manschterbuffer[2] = MANCHESTER_BIT_0;

    /*Manchester Encoding */
    for(uint8 i = 0; i < len; i++)
    {
        manschterbuffer[j] = (binarynum[i]==1)?  MANCHESTER_BIT_1:MANCHESTER_BIT_0;
        j++;
    }
    /*Calculate Parity */
    for(uint8 i = 0; i < j; i++)
    {
        if(manschterbuffer[i] == MANCHESTER_BIT_1 )
        {
            Cnt_parity++;
        }
    }
    /*Parity bit update */
    manschterbuffer [j] = (Cnt_parity%2 == 0)? MANCHESTER_BIT_0: MANCHESTER_BIT_1;

    /* Start SPI Master communication with manchester encoded data */
    ret_status = IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &manschterbuffer[0], NULL_PTR, DATA_TO_TRANSFER);

    /* Switch on the LED1 in case master exchange is successful (LED is low-level active) */
    if(ret_status == SpiIf_Status_ok)
    {
        return DATA_E_OK;
    }
    else
    {
        return DATA_E_NOK;
    }
}
