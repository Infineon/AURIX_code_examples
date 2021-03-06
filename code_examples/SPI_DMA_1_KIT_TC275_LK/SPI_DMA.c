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
#include "SPI_DMA.h"
#include "IfxPort.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define QSPI1_MASTER                &MODULE_QSPI1               /* SPI Master Hardware module                       */
#define QSPI3_SLAVE                 &MODULE_QSPI3               /* SPI Slave Hardware module                        */

#define LED1                        &MODULE_P00,5               /* LED1 Port, Pin definition                        */

#define ISR_PRIORITY_QSPI1_TX       1                           /* Define the QSPI1 transmit interrupt priority     */
#define ISR_PRIORITY_QSPI1_RX       2                           /* Define the QSPI1 receive interrupt priority      */
#define ISR_PRIORITY_QSPI1_ER       10                          /* Define the QSPI1 error interrupt priority        */

#define ISR_PRIORITY_QSPI3_TX       3                           /* Define the QSPI3 transmit interrupt priority     */
#define ISR_PRIORITY_QSPI3_RX       4                           /* Define the QSPI3 receive interrupt priority      */
#define ISR_PRIORITY_QSPI3_ER       11                          /* Define the QSPI3 error interrupt priority        */

#define ISR_PRIORITY_DMA_CH1        50                          /* Define the DMA channel1 interrupt priority       */
#define ISR_PRIORITY_DMA_CH2        51                          /* Define the DMA channel2 interrupt priority       */
#define ISR_PRIORITY_DMA_CH3        52                          /* Define the DMA channel3 interrupt priority       */
#define ISR_PRIORITY_DMA_CH4        53                          /* Define the DMA channel4 interrupt priority       */

#define ISR_PROVIDER_QSPI1          IfxSrc_Tos_cpu0             /* Define the QSPI1 interrupt provider              */
#define ISR_PROVIDER_QSPI3          IfxSrc_Tos_cpu0             /* Define the QSPI3 interrupt provider              */

#define ISR_PROVIDER_DMA_CH1        IfxSrc_Tos_cpu0             /* Define the DMA Channel1 interrupt provider       */
#define ISR_PROVIDER_DMA_CH2        IfxSrc_Tos_cpu0             /* Define the DMA Channel2 interrupt provider       */
#define ISR_PROVIDER_DMA_CH3        IfxSrc_Tos_cpu0             /* Define the DMA Channel3 interrupt provider       */
#define ISR_PROVIDER_DMA_CH4        IfxSrc_Tos_cpu0             /* Define the DMA Channel4 interrupt provider       */

#define MASTER_CHANNEL_BAUDRATE     1000000                     /* Master channel baud rate                         */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
qspiDma g_qspiDma;                                              /* Global handle for QSPI communication             */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void initQSPI1Master(void);
static void initQSPI1MasterChannel(void);
static void initQSPI1MasterBuffers(void);
static void initQSPI3Slave(void);
static void initQSPI3SlaveBuffers(void);
static void initQSPI(void);
static void initLED(void);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(QSPI1ErrorISR, 0, ISR_PRIORITY_QSPI1_ER);         /* SPI Master Error Interrupt definition            */
IFX_INTERRUPT(QSPI3ErrorISR, 0, ISR_PRIORITY_QSPI3_ER);         /* SPI Slave Error Interrupt definition             */
IFX_INTERRUPT(DMAChn1ISR, 0, ISR_PRIORITY_DMA_CH1);             /* DMA Channel 1 Interrupt definition               */
IFX_INTERRUPT(DMAChn2ISR, 0, ISR_PRIORITY_DMA_CH2);             /* DMA Channel 2 Interrupt definition               */
IFX_INTERRUPT(DMAChn3ISR, 0, ISR_PRIORITY_DMA_CH3);             /* DMA Channel 3 Interrupt definition               */
IFX_INTERRUPT(DMAChn4ISR, 0, ISR_PRIORITY_DMA_CH4);             /* DMA Channel 4 Interrupt definition               */

/* Handle QSPI1 Error interrupt */
void QSPI1ErrorISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_qspiDma.spiMaster);
}

/* Handle QSPI3 Error interrupt */
void QSPI3ErrorISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrError(&g_qspiDma.spiSlave);
}


/* Handle DMA Channel 1 interrupt */
void DMAChn1ISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrDmaTransmit(&g_qspiDma.spiMaster);
}


/* Handle DMA Channel 2 interrupt */
void DMAChn2ISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrDmaReceive(&g_qspiDma.spiMaster);
}


/* Handle DMA Channel 3 interrupt */
void DMAChn3ISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrDmaTransmit(&g_qspiDma.spiSlave);
}


/* Handle DMA Channel 4 interrupt */
void DMAChn4ISR(void)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiSlave_isrDmaReceive(&g_qspiDma.spiSlave);
}

/* This function initializes QSPI1 in master mode */
static void initQSPI1Master(void)
{
    IfxQspi_SpiMaster_Config spiMasterConfig;                           /* Define the Master Configuration          */

    IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, QSPI1_MASTER); /* Initialize it with default values        */

    const IfxQspi_SpiMaster_Pins qspi1Masterpins = {
        &IfxQspi1_SCLK_P10_2_OUT, IfxPort_OutputMode_pushPull,          /* SCLK Pin                          (CLK)  */
        &IfxQspi1_MTSR_P10_3_OUT, IfxPort_OutputMode_pushPull,          /* Master Transmit Slave Receive Pin (MOSI) */
        &IfxQspi1_MRSTA_P10_1_IN, IfxPort_InputMode_pullDown,           /* Master Receive Slave Transmit Pin (MISO) */
        IfxPort_PadDriver_cmosAutomotiveSpeed3                          /* Pad driver mode                          */
    };
    spiMasterConfig.pins = &qspi1Masterpins;                            /* Assign Master Pins                       */
    
    spiMasterConfig.dma.useDma = TRUE;
    spiMasterConfig.dma.txDmaChannelId = IfxDma_ChannelId_1;
    spiMasterConfig.dma.rxDmaChannelId = IfxDma_ChannelId_2;
    
    spiMasterConfig.base.txPriority = ISR_PRIORITY_DMA_CH1;
    spiMasterConfig.base.rxPriority = ISR_PRIORITY_DMA_CH2;
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

    spiMasterChannelConfig.base.baudrate = MASTER_CHANNEL_BAUDRATE;     /* Set SCLK frequency to 1 MHz              */

    const IfxQspi_SpiMaster_Output qspi1SlaveSelectQspi3 = {
        &IfxQspi1_SLSO9_P10_5_OUT, IfxPort_OutputMode_pushPull,         /* Slave Select Pin (CS)                    */
        IfxPort_PadDriver_cmosAutomotiveSpeed1                          /* Pad driver mode                          */
    };
    spiMasterChannelConfig.sls.output = qspi1SlaveSelectQspi3;

    /* Initialize the QSPI Master channel using the user configuration */
    IfxQspi_SpiMaster_initChannel(&g_qspiDma.spiMasterChannel, &spiMasterChannelConfig);

}

/* This function initializes Master SW buffers */
static void initQSPI1MasterBuffers(void)
{
    for (uint32 i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        /* Fill the SPI Master TX Buffer  */
        g_qspiDma.qspiBuffer.spiMasterTxBuffer[i] = (uint8)(i + 1);
        /* Clear the SPI Master RX Buffer */
        g_qspiDma.qspiBuffer.spiMasterRxBuffer[i] = 0;
    }
}

/* This function initializes QSPI3 in Slave mode */
static void initQSPI3Slave(void)
{
    IfxQspi_SpiSlave_Config spiSlaveConfig;                             /* Define the Slave Configuration           */

    IfxQspi_SpiSlave_initModuleConfig(&spiSlaveConfig, QSPI3_SLAVE);    /* Initialize it with default values        */
    
    /* Enable DMA mode*/
    spiSlaveConfig.dma.useDma = TRUE;
    /* Set SPI slave DMA channels */
    spiSlaveConfig.dma.txDmaChannelId = IfxDma_ChannelId_3;
    spiSlaveConfig.dma.rxDmaChannelId = IfxDma_ChannelId_4;
    
    /* Configure SPI slave interrupts */
    spiSlaveConfig.base.txPriority = ISR_PRIORITY_DMA_CH3;
    spiSlaveConfig.base.rxPriority = ISR_PRIORITY_DMA_CH4;
    spiSlaveConfig.base.erPriority = ISR_PRIORITY_QSPI1_ER;
    spiSlaveConfig.base.isrProvider = ISR_PROVIDER_QSPI1;

    const IfxQspi_SpiSlave_Pins qspi3Slavepins = {
        &IfxQspi3_SCLKA_P02_7_IN, IfxPort_InputMode_pullDown,           /* SCLK Pin                          (CLK)  */
        &IfxQspi3_MTSRA_P02_6_IN, IfxPort_InputMode_pullDown,           /* Master Transmit Slave Receive Pin (MOSI) */
        &IfxQspi3_MRST_P02_5_OUT, IfxPort_OutputMode_pushPull,          /* Master Receive Slave Transmit Pin (MISO) */
        &IfxQspi3_SLSIA_P02_4_IN, IfxPort_InputMode_pullDown,           /* Slave Select Pin                  (CS)   */
        IfxPort_PadDriver_cmosAutomotiveSpeed3                          /* Pad driver mode                          */
    };

    /* Assign Slave Pins */
    spiSlaveConfig.pins = &qspi3Slavepins;

    /* Initialize QSPI Slave module */
    IfxQspi_SpiSlave_initModule(&g_qspiDma.spiSlave, &spiSlaveConfig);
}

/* Initialize Slave SW buffers */
static void initQSPI3SlaveBuffers(void)
{
    for (uint32 i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        /* Fill the SPI Slave TX Buffer  */
        g_qspiDma.qspiBuffer.spiSlaveTxBuffer[i] = (uint8)(i + 0x64);
        /* Clear the SPI Slave RX Buffer */
        g_qspiDma.qspiBuffer.spiSlaveRxBuffer[i] = 0;
    }
}

/* This function initializes the LED */
static void initLED(void)
{
    /* Set the port pin 00.5 (to which the LED1 is connected) to output push-pull mode */
    IfxPort_setPinModeOutput(LED1, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    /* Turn off the LED (LED is low-level active) */
    IfxPort_setPinHigh(LED1);
}

/* This function initializes the QSPI modules */
static void initQSPI(void)
{
    /* Firstly initialize the Slave */
    initQSPI3Slave();
    initQSPI3SlaveBuffers();

    /* Secondly initialize the Master */
    initQSPI1Master();
    initQSPI1MasterChannel();
    initQSPI1MasterBuffers();
}

/* This function initializes the SPI and the LED called from Cpu0_Main */
void initPeripherals(void)
{
    initLED();
    initQSPI();
}


/* This function ensures the QSPI communication between Master and Slave and checks whether
 * the data transfer was correct or not
 */
void transferData(void)
{
    uint32 i;
    uint32 error = 0;
    
    /* Enable SPI Slave for communication */
    IfxQspi_SpiSlave_exchange(&g_qspiDma.spiSlave, &g_qspiDma.qspiBuffer.spiSlaveTxBuffer[0],
                              &g_qspiDma.qspiBuffer.spiSlaveRxBuffer[0], SPI_BUFFER_SIZE);
    
    /* Start SPI Master communication */
    IfxQspi_SpiMaster_exchange(&g_qspiDma.spiMasterChannel, &g_qspiDma.qspiBuffer.spiMasterTxBuffer[0],
                               &g_qspiDma.qspiBuffer.spiMasterRxBuffer[0], SPI_BUFFER_SIZE);
                
    /* Wait until the slave received all data */
    while (IfxQspi_SpiSlave_getStatus(&g_qspiDma.spiSlave) == SpiIf_Status_busy)
    {
    }

    /* Compare exchanged data */
    for(i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        if(g_qspiDma.qspiBuffer.spiSlaveRxBuffer[i] != g_qspiDma.qspiBuffer.spiMasterTxBuffer[i])
        {
            error++;
        }

        if(g_qspiDma.qspiBuffer.spiMasterRxBuffer[i] != g_qspiDma.qspiBuffer.spiSlaveTxBuffer[i])
        {
            error++;
        }
    }

    /* Switch on the LED1 in case of no errors (LED is low-level active) */
    if(error == 0)
    {
        IfxPort_setPinLow(LED1);
    }
}
