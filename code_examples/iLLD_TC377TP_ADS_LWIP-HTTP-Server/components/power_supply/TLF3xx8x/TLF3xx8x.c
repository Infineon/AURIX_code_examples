/**********************************************************************************************************************
 * \file TLF3xx8x.c
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "TLF3XX8X.h"
#include "Ifx_Cfg.h"
#include <Qspi/SpiMaster/IfxQspi_SpiMaster.h>
#include "board.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define TLF_BUFFER_SIZE 1   /**< \brief Tx/Rx Buffer size */

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
    uint32 spiTxBuffer[TLF_BUFFER_SIZE];                               /**< \brief Qspi Transmit buffer */
    uint32 spiRxBuffer[TLF_BUFFER_SIZE];                               /**< \brief Qspi receive buffer */
} AppQspi_TLF_Buffer;

/** \brief QspiCpu global data */
typedef struct
{
    AppQspi_TLF_Buffer qspiBuffer;                       /**< \brief Qspi buffer */
    struct
    {
        IfxQspi_SpiMaster         spiMaster;             /**< \brief Spi Master handle */
        IfxQspi_SpiMaster_Channel spiMasterChannel;      /**< \brief Spi Master Channel handle */
    }drivers;
}  App_Qspi_TLF_Cpu;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
#if CPU_WHICH_SERVICE_TLF == 0
    #if defined(__GNUC__)
    #pragma section ".text_cpu0" ax
    #pragma section ".bss_cpu0" awc0
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu0"
    #pragma section farbss  "bss_cpu0"
    #pragma section fardata "data_cpu0"
    #pragma section farrom  "rodata_cpu0"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu0"
    #pragma section DATA ".data_cpu0" ".bss_cpu0" far-absolute RW
    #pragma section CONST ".rodata_cpu0"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu0"
    #pragma ghs section bss= ".bss_cpu0"
    #pragma ghs section data=".data_cpu0"
    #pragma ghs section rodata=".rodata_cpu0"
    #endif
#elif ((CPU_WHICH_SERVICE_TLF == 1) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu1" ax
    #pragma section ".bss_cpu1" awc1
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu1"
    #pragma section farbss  "bss_cpu1"
    #pragma section fardata "data_cpu1"
    #pragma section farrom  "rodata_cpu1"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu1"
    #pragma section DATA ".data_cpu1" ".bss_cpu1" far-absolute RW
    #pragma section CONST ".rodata_cpu1"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu1"
    #pragma ghs section bss= ".bss_cpu1"
    #pragma ghs section data=".data_cpu1"
    #pragma ghs section rodata=".rodata_cpu1"
    #endif
#elif ((CPU_WHICH_SERVICE_TLF == 2) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu2" ax
    #pragma section ".bss_cpu2" awc2
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu2"
    #pragma section farbss  "bss_cpu2"
    #pragma section fardata "data_cpu2"
    #pragma section farrom  "rodata_cpu2"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu2"
    #pragma section DATA ".data_cpu2" ".bss_cpu2" far-absolute RW
    #pragma section CONST ".rodata_cpu2"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu2"
    #pragma ghs section bss= ".bss_cpu2"
    #pragma ghs section data=".data_cpu2"
    #pragma ghs section rodata=".rodata_cpu2"
    #endif
#elif ((CPU_WHICH_SERVICE_TLF == 3) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu3" ax
    #pragma section ".bss_cpu3" awc3
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu3"
    #pragma section farbss  "bss_cpu3"
    #pragma section fardata "data_cpu3"
    #pragma section farrom  "rodata_cpu3"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu3"
    #pragma section DATA ".data_cpu3" ".bss_cpu3" far-absolute RW
    #pragma section CONST ".rodata_cpu3"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu3"
    #pragma ghs section bss= ".bss_cpu3"
    #pragma ghs section data=".data_cpu3"
    #pragma ghs section rodata=".rodata_cpu3"
    #endif
#elif ((CPU_WHICH_SERVICE_TLF == 4) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu4" ax
    #pragma section ".bss_cpu4" awc4
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu4"
    #pragma section farbss  "bss_cpu4"
    #pragma section fardata "data_cpu4"
    #pragma section farrom  "rodata_cpu4"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu4"
    #pragma section DATA ".data_cpu4" ".bss_cpu4" far-absolute RW
    #pragma section CONST ".rodata_cpu4"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu4"
    #pragma ghs section bss= ".bss_cpu4"
    #pragma ghs section data=".data_cpu4"
    #pragma ghs section rodata=".rodata_cpu4"
    #endif
#elif ((CPU_WHICH_SERVICE_TLF == 5) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #if defined(__GNUC__)
    #pragma section ".text_cpu5" ax
    #pragma section ".bss_cpu5" awc5
    #endif
    #if defined(__TASKING__)
    #pragma section code    "text_cpu5"
    #pragma section farbss  "bss_cpu5"
    #pragma section fardata "data_cpu5"
    #pragma section farrom  "rodata_cpu5"
    #endif
    #if defined(__DCC__)
    #pragma section CODE ".text_cpu5"
    #pragma section DATA ".data_cpu5" ".bss_cpu5" far-absolute RW
    #pragma section CONST ".rodata_cpu5"
    #endif
    #if defined(__ghs__)
    #pragma ghs section text=".text_cpu5"
    #pragma ghs section bss= ".bss_cpu5"
    #pragma ghs section data=".data_cpu5"
    #pragma ghs section rodata=".rodata_cpu5"
    #endif
#else
#error "Set CPU_WHICH_SERVICE_TLF to a valid value!"
#endif

App_Qspi_TLF_Cpu g_Qspi_TLF_Cpu;
boolean TLF_A_Step;   /* this is the value of DEVCTRL Register which should be different between A and other steps */
uint32 TLF_30682;      /* this is the value of DEVID Register which is valid for TLF30682, will be 0 if we have a TLF35584 */

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/
#if defined(__GNUC__)
    #pragma section /* end bss section */
    #if CPU_WHICH_SERVICE_TLF == 0
    #pragma section ".rodata_cpu0" ac0
    #endif
    #if ((CPU_WHICH_SERVICE_TLF == 1) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #pragma section ".rodata_cpu1" ac1
    #endif
    #if ((CPU_WHICH_SERVICE_TLF == 2) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #pragma section ".rodata_cpu2" ac2
    #endif
    #if ((CPU_WHICH_SERVICE_TLF == 3) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #pragma section ".rodata_cpu3" ac3
    #endif
    #if ((CPU_WHICH_SERVICE_TLF == 4) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #pragma section ".rodata_cpu4" ac4
    #endif
    #if ((CPU_WHICH_SERVICE_TLF == 5) && (CPU_WHICH_SERVICE_TLF < IFXCPU_NUM_MODULES))
    #pragma section ".rodata_cpu5" ac5
    #endif
#endif
/* Pins on TriBoards TC3X7 and TC3X5 */
const IfxQspi_SpiMaster_Pins tlf_qspi_pins = {&TLF_SCLK_PIN, IfxPort_OutputMode_pushPull,  /* SCLK */
                                              &TLF_MTSR_PIN,  IfxPort_OutputMode_pushPull, /* MTSR */
                                              &TLF_MRST_PIN,  IfxPort_InputMode_pullDown,  /* MRST */
                                              IfxPort_PadDriver_ttlSpeed1                   /* pad driver mode */
};

const IfxQspi_SpiMaster_Output tlf_slsOutput = {&TLF_CS_PIN,
                                                IfxPort_OutputMode_pushPull,
                                                IfxPort_PadDriver_cmosAutomotiveSpeed1};


#if defined(__GNUC__)
    #pragma section /* end rodata section */
#endif

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
/** \brief Handle tlf_qspi_Tx interrupt.
 *
 * \isrProvider \ref CPU_WHICH_SERVICE_TLF
 * \isrPriority \ref ISR_PRIORITY_TLF_QSPI
 *
 */
IFX_INTERRUPT(ISR_tlf_qspi_Tx, CPU_WHICH_SERVICE_TLF, ISR_PRIORITY_TLF_QSPI_TX)
{
    IfxCpu_enableInterrupts();
#ifdef TLF_USE_DMA
    IfxQspi_SpiMaster_isrDmaTransmit(&(g_Qspi_TLF_Cpu.drivers.spiMaster));
#else
    IfxQspi_SpiMaster_isrTransmit(&(g_Qspi_TLF_Cpu.drivers.spiMaster));
#endif

}


/** \brief Handle tlf_qspi_Rx interrupt.
 *
 * \isrProvider \ref CPU_WHICH_SERVICE_TLF
 * \isrPriority \ref ISR_PRIORITY_TLF_QSPI
 *
 */
IFX_INTERRUPT(ISR_tlf_qspi_Rx, CPU_WHICH_SERVICE_TLF, ISR_PRIORITY_TLF_QSPI_RX)
{
    IfxCpu_enableInterrupts();
#ifdef TLF_USE_DMA
    IfxQspi_SpiMaster_isrDmaReceive(&(g_Qspi_TLF_Cpu.drivers.spiMaster));
#else
    IfxQspi_SpiMaster_isrReceive(&(g_Qspi_TLF_Cpu.drivers.spiMaster));
#endif
}

/** \brief Handle tlf_qspi_Er interrupt.
 *
 * \isrProvider \ref CPU_WHICH_SERVICE_TLF
 * \isrPriority \ref ISR_PRIORITY_TLF_QSPI
 *
 */
IFX_INTERRUPT(ISR_tlf_qspi_Er, CPU_WHICH_SERVICE_TLF, ISR_PRIORITY_TLF_QSPI_ER)
{
    IfxCpu_enableInterrupts();
    IfxQspi_SpiMaster_isrError(&(g_Qspi_TLF_Cpu.drivers.spiMaster));
}

/** \brief TLF (QSPI) initialization
 *
 * This function initializes Qspix in master mode.
 */
void IfxTLF3XX8X_init(void)
{
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxQspi_SpiMaster_Config        spiMasterConfig;

    /* create module config */
/*
 *  if (SCU_CHIPID.B.CHPK == 6)
        IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, TLF_ALT_SCLK_PIN.module);
    else
*/
          IfxQspi_SpiMaster_initModuleConfig(&spiMasterConfig, TLF_SCLK_PIN.module);

    /* set the maximum baudrate */
    spiMasterConfig.base.maximumBaudrate = TLF_QSPI_MAX_BAUDRATE;

    /* ISR priorities and interrupt target */
    spiMasterConfig.base.txPriority  = ISR_PRIORITY_TLF_QSPI_TX;
    spiMasterConfig.base.rxPriority  = ISR_PRIORITY_TLF_QSPI_RX;
    spiMasterConfig.base.erPriority  = ISR_PRIORITY_TLF_QSPI_ER;
    if (CPU_WHICH_SERVICE_TLF)
        spiMasterConfig.base.isrProvider = (IfxSrc_Tos)(CPU_WHICH_SERVICE_TLF+1);
    else
        spiMasterConfig.base.isrProvider = (IfxSrc_Tos)CPU_WHICH_SERVICE_TLF;

#ifdef TLF_QSPI_USE_DMA
        /* DMA configuration */
        spiMasterConfig.dma.txDmaChannelId = DMA_CH_TLF_QSPI_TX;
        spiMasterConfig.dma.rxDmaChannelId = DMA_CH_TLF_QSPI_RX;
        spiMasterConfig.dma.useDma = 1;
#endif

/*        if (SCU_CHIPID.B.CHPK == 6)
                  spiMasterConfig.pins = &tlf_alt_qspi_pins;
        else
*/
            spiMasterConfig.pins = &tlf_qspi_pins;

    /* initialize module */
    IfxQspi_SpiMaster_initModule(&(g_Qspi_TLF_Cpu.drivers.spiMaster), &spiMasterConfig);
    /* set the MRST_input also to the selected pad driver mode if needed */
/*    if (SCU_CHIPID.B.CHPK == 6)
          IfxPort_setPinPadDriver(tlf_alt_qspi_pins.mrst->pin.port, tlf_alt_qspi_pins.mrst->pin.pinIndex, tlf_alt_qspi_pins.pinDriver);
      else
*/
        IfxPort_setPinPadDriver(tlf_qspi_pins.mrst->pin.port, tlf_qspi_pins.mrst->pin.pinIndex, tlf_qspi_pins.pinDriver);

    IfxQspi_SpiMaster_ChannelConfig spiMasterChannelConfig;

    {
        /* create channel config */
        IfxQspi_SpiMaster_initChannelConfig(&spiMasterChannelConfig, &(g_Qspi_TLF_Cpu.drivers.spiMaster));

        /* set the baudrate for this channel */
        spiMasterChannelConfig.base.baudrate = 5000000;

        /* set the transfer data width */
        spiMasterChannelConfig.base.mode.dataWidth = 16;

        spiMasterChannelConfig.base.mode.csTrailDelay = 2;
        spiMasterChannelConfig.base.mode.csInactiveDelay = 2;
        /* we need this to for TLF30682, we need to change this later in case of TLF35584 */
        spiMasterChannelConfig.base.mode.clockPolarity = SpiIf_ClockPolarity_idleHigh;

        spiMasterChannelConfig.base.mode.shiftClock = SpiIf_ShiftClock_shiftTransmitDataOnTrailingEdge;

/*       if (SCU_CHIPID.B.CHPK == 6)
         {
              spiMasterChannelConfig.sls.output.pin    = tlf_alt_slsOutput.pin;
              spiMasterChannelConfig.sls.output.mode   = tlf_alt_slsOutput.mode;
              spiMasterChannelConfig.sls.output.driver = tlf_alt_slsOutput.driver;
          }
          else
          {
*/
            spiMasterChannelConfig.sls.output.pin    = tlf_slsOutput.pin;
            spiMasterChannelConfig.sls.output.mode   = tlf_slsOutput.mode;
            spiMasterChannelConfig.sls.output.driver = tlf_slsOutput.driver;
/*       } */


        /* initialize channel */
        IfxQspi_SpiMaster_initChannel(&g_Qspi_TLF_Cpu.drivers.spiMasterChannel,
            &spiMasterChannelConfig);
    }

    /* init tx buffer area */
    g_Qspi_TLF_Cpu.qspiBuffer.spiTxBuffer[0] = 0;
    g_Qspi_TLF_Cpu.qspiBuffer.spiRxBuffer[0] = 0;

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);
    /* preset the A-Step Flag to FALSE */
    TLF_A_Step = FALSE;
    /* first we check for TLF30682 or TLF35584 */
    TLF_30682 = (IfxTLF3XX8X_read_write(0x7800)>>1) & 0xFF;  /* read address 0x3C */
    if ((TLF_30682 == 0x10) || (TLF_30682 == 0x20))
    {
        /* we have a TLF30682 connected (some older devices haven wrong id 0x20) */
        /* set the core supply to 1,25V in case that we have an TLF30682 */
        /* our board has a 50mR resistor inside of the VDD line to measure the VDD current */
        /* therefore we must set the voltage to 1,3V that the supply on the VDD will be 1,25V */
        /* for normal boards the value 0x00 (0xA000/0xA3FF) must be change to 0x01 (0xA003/0xA3FC) */
        IfxTLF3XX8X_read_write(0xA000);  /* B2VCTRL.B.B2VOUTF = 0x00 */
        IfxTLF3XX8X_read_write(0xA3FF);  /* B2VCTRLN.B.B2VOUTF = ~0x00 */
    }
    else
    {
        /* we expect that we have here a TLF35584 */
        /* switch the Clock polarity to idle low */
/*       if (SCU_CHIPID.B.CHPK == 6)
            g_Qspi_TLF_Cpu.drivers.spiMaster.qspi->ECON[TLF_ALT_CS_PIN.slsoNr].B.CPOL = SpiIf_ClockPolarity_idleLow;
        else
*/
            g_Qspi_TLF_Cpu.drivers.spiMaster.qspi->ECON[TLF_CS_PIN.slsoNr].B.CPOL = SpiIf_ClockPolarity_idleLow;

        TLF_30682 = 0;
        /* we clear all errors in SPISF */
        IfxTLF3XX8X_read_write(0xBE3F);  /* SPISF = 0x1F */
        /* now we check for A-Step or newer */
        /* we read the value from address 0x34 but ignore the returned value */
        IfxTLF3XX8X_read_write(0x6801);  /* read address 0x34 */
        /* no we read the SPI status flags */
        if ((IfxTLF3XX8X_read_write(0x3E01)>>1) & 0x4)
        {
            /* there was an address error, this is not the A-step */
            /* we reset the ADDRE flag */
            IfxTLF3XX8X_read_write(0xBE09);  /* SPISF = 0x04 */
        }
        else
            TLF_A_Step = TRUE;
    }
}

void IfxTLF3XX8X_unprotect_register(void)
{
    IfxTLF3XX8X_read_write(0x8756);  /* PROTCFG = 0xAB */
    IfxTLF3XX8X_read_write(0x87DE);  /* PROTCFG = 0xEF */
    IfxTLF3XX8X_read_write(0x86AD);  /* PROTCFG = 0x56 */
    IfxTLF3XX8X_read_write(0x8625);  /* PROTCFG = 0x12 */
}

void IfxTLF3XX8X_protect_register(void)
{
    IfxTLF3XX8X_read_write(0x87BE);  /* PROTCFG = 0xDF */
    IfxTLF3XX8X_read_write(0x8668);  /* PROTCFG = 0x34 */
    IfxTLF3XX8X_read_write(0x877D);  /* PROTCFG = 0xBE */
    IfxTLF3XX8X_read_write(0x8795);  /* PROTCFG = 0xCA */
}

void IfxTLF3XX8X_disable_window_watchdog(void)
{
    uint32 uiWdcfg0;
    /* first we get the value of WDCFG0 to check the window watchdog */
    if (TLF_30682 != 0)
    {
        uiWdcfg0 = IfxTLF3XX8X_read_write(0x0E00);  /* read RWDCFG0 (0x07) */
    }
    else
    {
        if (TLF_A_Step == TRUE)
            uiWdcfg0 = IfxTLF3XX8X_read_write(0x0C00);  /* read WDCFG0 (0x06) */
        else
            uiWdcfg0 = IfxTLF3XX8X_read_write(0x1A00);  /* read RWDCFG0 (0x0D) */
    }
    /* if the WWDEN is cleared then return because the window watchdog is already disabled */
    if (!(uiWdcfg0 & 0x0010)) return;
    /* clear the WWDEN bit */
    uiWdcfg0 &= ~0x0010;
    /* correct the parity */
    if (uiWdcfg0 & 0x0001)
        uiWdcfg0 &= ~0x0001;
    else
        uiWdcfg0 |= 0x0001;
    /* set the write address to 0x06 */
    uiWdcfg0 |= (0x06<<9);
    /* Write back and disable the Window Watchdog */
    IfxTLF3XX8X_read_write(uiWdcfg0);
}

void IfxTLF3XX8X_enable_window_watchdog(void)
{
    uint32 uiWdcfg0;
    /* first we get the value of WDCFG0 to check the window watchdog */
    if (TLF_30682 != 0)
    {
        uiWdcfg0 = IfxTLF3XX8X_read_write(0x0E00);  /* read RWDCFG0 (0x07) */
    }
    else
    {
        if (TLF_A_Step == TRUE)
            uiWdcfg0 = IfxTLF3XX8X_read_write(0x0C00);  /* read WDCFG0 (0x06) */
        else
            uiWdcfg0 = IfxTLF3XX8X_read_write(0x1A00);  /* read RWDCFG0 (0x0D) */
    }
    /* if the WWDEN is set then return because the window watchdog is already enabled */
    if (uiWdcfg0 & 0x0010) return;
    /* set the WWDEN bit */
    uiWdcfg0 |= 0x0010;
    /* correct the parity */
    if (uiWdcfg0 & 0x0001)
        uiWdcfg0 &= ~0x0001;
    else
        uiWdcfg0 |= 0x0001;
    /* set the write address to 0x06 */
    uiWdcfg0 |= (0x06<<9);
    /* Write back and enable the Window Watchdog */
    IfxTLF3XX8X_read_write(uiWdcfg0);
}

void IfxTLF3XX8X_disable_err_pin_monitor(void)
{
    uint32 uiSyspcfg;
    if (TLF_30682 != 0)
    {
       /* this is a TLF30682 which don't have normal/operational state, we do nothing */
       return;
    }
    else
    {
        if (TLF_A_Step == TRUE)
        {
            /* first we get the value of SYSPCFG0 to check the error pin monitor */
            uiSyspcfg = IfxTLF3XX8X_read_write(0x0801);  /* read SYSPCFG0 (0x04) */
            /* if the ERREN is cleared then return because the error pin monitor is already disabled */
            if (!(uiSyspcfg & 0x0004)) return;
            /* clear the ERREN bit */
            uiSyspcfg &= ~0x0004;
            /* set the write address to 0x04 */
            uiSyspcfg |= (0x04<<9);
            /* parity must not be corrected */
        }
        else
        {
            /* first we get the value of RSYSPCFG1 to check the error pin monitor */
            uiSyspcfg = IfxTLF3XX8X_read_write(0x1800);  /* read RSYSPCFG1 (0x0C) */
            /* if the ERREN is cleared then return because the error pin monitor is already disabled */
            if (!(uiSyspcfg & 0x0010)) return;
            /* clear the ERREN bit */
            uiSyspcfg &= ~0x0010;
            /* set the write address to 0x05 */
            uiSyspcfg |= (0x05<<9);
            /* correct the parity */
            if (uiSyspcfg & 0x0001)
                uiSyspcfg &= ~0x0001;
            else
                uiSyspcfg |= 0x0001;
        }
    }
    /* Write back and disable the error pin monitor */
    IfxTLF3XX8X_read_write(uiSyspcfg);
}

void IfxTLF3XX8X_enable_err_pin_monitor(void)
{
    uint32 uiSyspcfg;
    if (TLF_30682 != 0)
    {
       /* this is a TLF30682 which don't have normal/operational state, we do nothing */
       return;
    }
    else
    {
        if (TLF_A_Step == TRUE)
        {
            /* first we get the value of SYSPCFG0 to check the error pin monitor */
            uiSyspcfg = IfxTLF3XX8X_read_write(0x0801);  /* read SYSPCFG0 (0x04) */
            /* if the ERREN is set then return because the error pin monitor is already enabled */
            if (uiSyspcfg & 0x0004) return;
            /* set the ERREN bit */
            uiSyspcfg |= 0x0004;
            /* set the write address to 0x04 */
            uiSyspcfg |= (0x04<<9);
            /* parity must not be corrected */
        }
        else
        {
            /* first we get the value of SYSPCFG1 to check the error pin monitor */
            uiSyspcfg = IfxTLF3XX8X_read_write(0x1800);  /* read SYSPCFG1 (0x0C) */
            /* if the ERREN is set then return because the error pin monitor is already enabled */
            if (uiSyspcfg & 0x0010) return;
            /* set the ERREN bit */
            uiSyspcfg |= 0x0010;
            /* set the write address to 0x05 */
            uiSyspcfg |= (0x05<<9);
            /* correct the parity */
            if (uiSyspcfg & 0x0001)
                uiSyspcfg &= ~0x0001;
            else
                uiSyspcfg |= 0x0001;
        }
    }
    /* Write back and enable the error pin monitor */
    IfxTLF3XX8X_read_write(uiSyspcfg);
}

void IfxTLF3XX8X_goto_standby_powerdown_state(void)
{
    if (TLF_30682 != 0)
    {
        uint32 uiDevStat, uiDevCtrl;
        /* first we get the value of DEVSTAT to check the state of device */
        uiDevStat = IfxTLF3XX8X_read_write(0x5001);  /* read DEVSTAT (0x28) */
        /* we don't need to check the device state because we are never in this state here */
        uiDevCtrl = uiDevStat & ~0xE;
        // set statereq to disabled state
        uiDevCtrl |= 0x6;
        /* set the write address to DEVCTRL (0x34) */
        uiDevCtrl |= (0x34<<9);
        /* our new state is 3, the address is 0x34 with this we need to change the parity dependent of old state */
        switch (uiDevStat & 0x7)
        {
        case 0:
        case 3:
        case 5:
        case 6:
            /* correct the parity, reset if set and set if reset */
            uiDevCtrl = uiDevCtrl ^ 0x1;
            break;
        default:
            /* no parity change */
            break;
        }

        IfxTLF3XX8X_read_write(uiDevCtrl);  /* DEVCTRL */
        /* we invert the value also the parity */
        uiDevCtrl = uiDevCtrl ^ 0x01FF;
        /* correct the address to DEVCTRLN */
        uiDevCtrl |= 0x200;
        IfxTLF3XX8X_read_write(uiDevCtrl);  /* DEVCTRLN */
    }
    else
    {
        if (TLF_A_Step == TRUE)
            IfxTLF3XX8X_read_write(0x9DD9);  /* DEVCTRL = 0xEC */
        else
        {
            IfxTLF3XX8X_read_write(0xABD9);  /* DEVCTRL = 0xEC */
            IfxTLF3XX8X_read_write(0xAC27);  /* DEVCTRLN = ~0xEC */
        }
    }
}

void IfxTLF3XX8X_goto_normal_state(void)
{
    if (TLF_30682 != 0)
    {
       /* this is a TLF30682 which don't have normal/operational state, we do nothing */
       return;
    }
    else
    {
        /* Switch TLF to normal state */
        if (TLF_A_Step == TRUE)
            IfxTLF3XX8X_read_write(0x9DD5);  /* DEVCTRL = 0xEA */
        else
        {
            IfxTLF3XX8X_read_write(0xABD5);  /* DEVCTRL = 0xEA */
            IfxTLF3XX8X_read_write(0xAC2B);  /* DEVCTRLN = ~0xEA */
        }
    }
}

uint32 IfxTLF3XX8X_read_write(uint32 send_data)
{
    g_Qspi_TLF_Cpu.qspiBuffer.spiTxBuffer[0] = send_data;

    while (IfxQspi_SpiMaster_getStatus(&g_Qspi_TLF_Cpu.drivers.spiMasterChannel) == SpiIf_Status_busy)  {};

    IfxQspi_SpiMaster_exchange(&g_Qspi_TLF_Cpu.drivers.spiMasterChannel, &g_Qspi_TLF_Cpu.qspiBuffer.spiTxBuffer[0],
        &g_Qspi_TLF_Cpu.qspiBuffer.spiRxBuffer[0], TLF_BUFFER_SIZE);

    /* we wait until our values are read from Qspi */
    while (IfxQspi_SpiMaster_getStatus(&g_Qspi_TLF_Cpu.drivers.spiMasterChannel) == SpiIf_Status_busy)  {};

    return (g_Qspi_TLF_Cpu.qspiBuffer.spiRxBuffer[0]);

}

#if defined(__GNUC__)
#pragma section /* end text section */
#endif
#if defined(__TASKING__)
#pragma section code restore
#pragma section fardata restore
#pragma section farbss restore
#pragma section farrom restore
#endif
#if defined(__DCC__)
#pragma section CODE
#pragma section DATA RW
#pragma section CONST
#endif
#if defined(__ghs__)
#pragma ghs section text=default
#pragma ghs section data=default
#pragma ghs section bss=default
#pragma ghs section rodata=default
#endif
