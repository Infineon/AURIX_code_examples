/**********************************************************************************************************************
 * \file SPI_TLF.c
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
#include "SPI_TLF.h"
#include "TLF35584.h"

/* Additional includes for SafetyKit */
#include "SafetyKit_Cfg.h"

#if CPU_WHICH_RUN_TLF == 0
    #if defined(__TASKING__)
    #pragma section code    "text_cpu0"
    #pragma section farbss  "bss_cpu0"
    #pragma section fardata "data_cpu0"
    #pragma section farrom  "rodata_cpu0"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#elif ((CPU_WHICH_RUN_TLF == 1) && (CPU_WHICH_RUN_TLF < IFXCPU_NUM_MODULES))
    #if defined(__TASKING__)
    #pragma section code    "text_cpu1"
    #pragma section farbss  "bss_cpu1"
    #pragma section fardata "data_cpu1"
    #pragma section farrom  "rodata_cpu1"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#elif ((CPU_WHICH_RUN_TLF == 2) && (CPU_WHICH_RUN_TLF < IFXCPU_NUM_MODULES))
    #if defined(__TASKING__)
    #pragma section code    "text_cpu2"
    #pragma section farbss  "bss_cpu2"
    #pragma section fardata "data_cpu2"
    #pragma section farrom  "rodata_cpu2"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#elif ((CPU_WHICH_RUN_TLF == 3) && (CPU_WHICH_RUN_TLF < IFXCPU_NUM_MODULES))
    #if defined(__TASKING__)
    #pragma section code    "text_cpu3"
    #pragma section farbss  "bss_cpu3"
    #pragma section fardata "data_cpu3"
    #pragma section farrom  "rodata_cpu3"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#elif ((CPU_WHICH_RUN_TLF == 4) && (CPU_WHICH_RUN_TLF < IFXCPU_NUM_MODULES))
    #if defined(__TASKING__)
    #pragma section code    "text_cpu4"
    #pragma section farbss  "bss_cpu4"
    #pragma section fardata "data_cpu4"
    #pragma section farrom  "rodata_cpu4"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#elif ((CPU_WHICH_RUN_TLF == 5) && (CPU_WHICH_RUN_TLF < IFXCPU_NUM_MODULES))
    #if defined(__TASKING__)
    #pragma section code    "text_cpu5"
    #pragma section farbss  "bss_cpu5"
    #pragma section fardata "data_cpu5"
    #pragma section farrom  "rodata_cpu5"
    #else
        #error "Only TASKING is supported, add pragmas for your compiler"
    #endif
#else
#error "Set CPU_WHICH_RUN_TLF to a valid value!"
#endif
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define QSPI2_MASTER                &MODULE_QSPI2   /* SPI Master module                                             */
#define MASTER_CHANNEL_BAUDRATE     5000000         /* Master channel baud rate                                      */
#define SPI_DATA_WIDTH              15              /* Transfer data width                                           */
#define SPI_CS_TRAIL_DELAY          2               /* CS Trail Delay in Tsclk/2 units                               */
#define SPI_CS_INACTIVE_DELAY       2               /* CS Inactive Delay in Tsclk/2 units                            */

#define ISR_PRIORITY_MASTER_TX      ISR_PRIORITY_TLF_QSPI_TX
#define ISR_PRIORITY_MASTER_RX      ISR_PRIORITY_TLF_QSPI_RX
#define ISR_PRIORITY_MASTER_ER      ISR_PRIORITY_TLF_QSPI_ER

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
qspiComm g_qspi;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void initQSPI2Master(void);
void initQSPI2MasterChannel(void);
void initQSPI2MasterBuffers(void);
void initQSPI(void);
uint16 transferDataTLF35584(spiCommandType cmd, Tlf35584RegAddr addr, uint8 data);

/*********************************************************************************************************************/
/*----------------------------------------------Function Implementations---------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(masterTxISR, CPU_WHICH_RUN_TLF, ISR_PRIORITY_MASTER_TX);                  /* SPI Master ISR for transmit data          */
IFX_INTERRUPT(masterRxISR, CPU_WHICH_RUN_TLF, ISR_PRIORITY_MASTER_RX);                  /* SPI Master ISR for receive data           */
IFX_INTERRUPT(masterErISR, CPU_WHICH_RUN_TLF, ISR_PRIORITY_MASTER_ER);                  /* SPI Master ISR for error                  */

void masterTxISR()
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrTransmit(&g_qspi.spiMaster);
}

void masterRxISR()
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrReceive(&g_qspi.spiMaster);
}

void masterErISR()
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&g_qspi.spiMaster);
}

/*
 * QSPI Master initialization
 * This function initializes the QSPI2 module in Master mode.
 */
void initQSPI2Master(void)
{
    IfxQspi_SpiMaster_Config spiMasterConfig;                           /* Define a Master configuration             */

    IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, QSPI2_MASTER); /* Initialize it with default values         */

    spiMasterConfig.base.mode = SpiIf_Mode_master;                      /* Configure the mode                        */

    /* Select the port pins for communication */
    const IfxQspi_SpiMaster_Pins qspi2MasterPins = {
        &IfxQspi2_SCLK_P15_8_OUT, IfxPort_OutputMode_pushPull,          /* SCLK Pin                       (CLK)      */
        &IfxQspi2_MTSR_P15_6_OUT, IfxPort_OutputMode_pushPull,          /* MasterTransmitSlaveReceive pin (MOSI)     */
        &IfxQspi2_MRSTB_P15_7_IN, IfxPort_InputMode_pullDown,           /* MasterReceiveSlaveTransmit pin (MISO)     */
        IfxPort_PadDriver_cmosAutomotiveSpeed3                          /* Pad driver mode                           */
    };
    spiMasterConfig.pins = &qspi2MasterPins;                            /* Assign the Master's port pins             */

    /* Set the ISR priorities and the service provider */
    spiMasterConfig.base.txPriority = ISR_PRIORITY_MASTER_TX;
    spiMasterConfig.base.rxPriority = ISR_PRIORITY_MASTER_RX;
    spiMasterConfig.base.erPriority = ISR_PRIORITY_MASTER_ER;
    if (CPU_WHICH_RUN_TLF)
    {
        spiMasterConfig.base.isrProvider = (IfxSrc_Tos)(CPU_WHICH_RUN_TLF+1);
    }
    else
    {
        spiMasterConfig.base.isrProvider = (IfxSrc_Tos)CPU_WHICH_RUN_TLF;
    }

    /* Initialize the QSPI Master module */
    IfxQspi_SpiMaster_initModule(&g_qspi.spiMaster, &spiMasterConfig);
}

/*
 * QSPI Master channel initialization
 * This function initializes the QSPI2 Master channel.
 */
void initQSPI2MasterChannel(void)
{
    IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;             /* Define a Master Channel configuration     */

    /* Initialize the configuration with default values */
    IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig, &g_qspi.spiMaster);

    /* The following parameters reflect the SPI related parameters provided
     * in the SPI-Serial Peripheral Interface chapter of the TLF35584's Data Sheet
     */
    spiMasterChannelConfig.base.baudrate = MASTER_CHANNEL_BAUDRATE;     /* Set SCLK frequency to 5 MHz               */
    spiMasterChannelConfig.base.mode.dataWidth = SPI_DATA_WIDTH;        /* Set the transfer data width to 15 bits    */
    spiMasterChannelConfig.base.mode.csTrailDelay = SPI_CS_TRAIL_DELAY; /* Set the CS trailing delay to 2            */
    spiMasterChannelConfig.base.mode.csInactiveDelay = SPI_CS_INACTIVE_DELAY; /* Set the CS inactive delay to 2      */
    spiMasterChannelConfig.base.mode.shiftClock = SpiIf_ShiftClock_shiftTransmitDataOnTrailingEdge;
    spiMasterChannelConfig.base.mode.parityCheck = TRUE;                /* Enable automatic HW parity generation     */
    spiMasterChannelConfig.base.mode.parityMode = Ifx_ParityMode_even;  /* Use even parity mode                      */

    /* Select the port pin for the Chip Select signal */
    const IfxQspi_SpiMaster_Output qspi2SlaveSelect = {                 /* QSPI2 Master selects the TLF device       */
        &IfxQspi2_SLSO1_P14_2_OUT, IfxPort_OutputMode_pushPull,         /* Slave Select port pin (CS)                */
        IfxPort_PadDriver_cmosAutomotiveSpeed1                          /* Pad driver mode                           */
    };
    spiMasterChannelConfig.sls.output = qspi2SlaveSelect;

    /* Initialize the QSPI Master channel */
    IfxQspi_SpiMaster_initChannel(&g_qspi.spiMasterChannel, &spiMasterChannelConfig);
}

/* QSPI Master SW buffer initialization
 * This function initializes SW buffers the Master uses.
 */
void initQSPI2MasterBuffers(void)
{
    for (uint8 i = 0; i < SPI_BUFFER_SIZE; i++)
    {
        g_qspi.spiBuffers.spiMasterTxBuffer[i] = (uint16)0;             /* Clear TX Buffer */
        g_qspi.spiBuffers.spiMasterRxBuffer[i] = (uint16)0;             /* Clear RX Buffer */
    }
}


/*
 * This function initializes the QSPI module
 * */
void initQSPI(void)
{
    /* Initialize the Master */
    initQSPI2Master();
    initQSPI2MasterChannel();
    initQSPI2MasterBuffers();
}

/*
 * This function starts the data transfer to the TLF35584 device
 * */
uint16 transferDataTLF35584(spiCommandType cmd, Tlf35584RegAddr addr, uint8 data)
{
    Tlf35584SpiFrameType spiFrame = {0};

    /* Prepare the SPI frame that should be transfered to the TLF35584 device */
    spiFrame.B.cmd = cmd;
    spiFrame.B.addr = addr;
    spiFrame.B.data = data;

    /* Store the prepared SPI frame to Master Tx Buffer */
    g_qspi.spiBuffers.spiMasterTxBuffer[0] = spiFrame.U;

    /* Wait until the previous communication has finished, if any */
    while(IfxQspi_SpiMaster_getStatus(&g_qspi.spiMasterChannel) == SpiIf_Status_busy)
    {
    }

    /* Send a data stream through the SPI Master */
    IfxQspi_SpiMaster_exchange(&g_qspi.spiMasterChannel, &g_qspi.spiBuffers.spiMasterTxBuffer[0],
                               &g_qspi.spiBuffers.spiMasterRxBuffer[0], SPI_BUFFER_SIZE);

    /* Wait until the values are read from the TLF device */
    while(IfxQspi_SpiMaster_getStatus(&g_qspi.spiMasterChannel) == SpiIf_Status_busy)
    {
    }

    return (g_qspi.spiBuffers.spiMasterRxBuffer[0]);
}

#if defined(__TASKING__)
#pragma section code restore
#pragma section fardata restore
#pragma section farbss restore
#pragma section farrom restore
#else
    #error "Only TASKING is supported, add pragmas for your compiler"
#endif
