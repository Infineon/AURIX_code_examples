/**********************************************************************************************************************
 * \file Cpu0_Main.c
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
 /*\title iLLD_TC4D7_LITE_KIT_ADS_ETH_DEMO
 * \abstract This code example implements an ethernet echo server (raw Ethernet) using GETH port 0.
 * \description This code example implements an ethernet echo server replying to Layer 2 packets. The demo configures GETH module using DMA Channel 0 and Tx/Rx Queues 0.
 * \name iLLD_TC4D7_lite_kit_ADS_ETH_Demo
 * \version V1.0.0
 * \board AURIX TC4D7 lite Kit, KIT_A3G_TC4D7_LITE, TC4D7XP_A-Step_CC_COM
 * \keywords GETH
 * \documents README.md
 * \documents changelog.md
 * \lastUpdated 2025-04-23
 *********************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#include "kit_tc4d7_lite.h"

#include "Cpu/Std/IfxCpu.h"
#include "Wtu/Std/IfxWtu.h"
#include "Stm/Std/IfxStm.h"
#include "Clock/Std/IfxClock.h"
#include "Vmt/Std/IfxVmt.h"
#include "Pms/Std/IfxPmsEvr.h"

#include "Geth/Eth/IfxGeth_Eth.h"

#include "pdl/ifx_hsphy.h"
#include "pdl/ifx_geth.h"

#include "retarget_io/retarget_io.h"
#include "phy/dp83825i.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* Interrupt priorities */
#define IFX_INTPRIO_CPU0_STM        1
#define INTPRIO_CPU0_GETH0_DMA_CH_0 64

#define TIMER_TICK_MS           10
#define TIMER_LED_TOOGLE_MS     500
#define TIMER_PHY_MONITOR_MS    200

/* buffer size multiple of 8 to achieve data buffers aligned to 64-bit addresses**/
#define IFXGETH_MAX_TX_BUFFER_SIZE  1528
#define IFXGETH_MAX_RX_BUFFER_SIZE  1528

/*********************************************************************************************************************/
/*-------------------------------------------------Type definitions--------------------------------------------------*/
/*********************************************************************************************************************/

typedef struct timer_s
{
    uint32 last_event_ms;
    uint32 period_ms;
    void (*timer_cb)(void *arg);
    void *arg;
} timer_t;

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
static void geth0_init(void);

static uint16 geth0_p0_mdio_read(uint8 phy_addr, uint8 dev_addr, uint16 reg_addr);
static void geth0_p0_mdio_write(uint8 phy_addr, uint8 dev_addr, uint16 reg_addr, uint16 reg_val);

static void timer_toogle_led_cb(void *arg);
static void timer_phy_monitor(void *arg);

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxGeth_Eth geth0;
phy_t phy_0;

static boolean geth0_rxdma0_interrupt = FALSE;
static boolean geth0_txdma0_interrupt = FALSE;

static const Ifx_GETH_MDIO_Pins geth0_p0_mdio_pins =
{
    .mdc = &BOARD_GETH0_P0_MDC,
    .mdio = &BOARD_GETH0_P0_MDIO,
};

static const IfxHsphy_Geth_RmiiPins geth0_p0_pins =
{
    .rxd0 = &BOARD_GETH0_P0_RXD0,
    .rxd1 = &BOARD_GETH0_P0_RXD1,
    .crsDiv = &BOARD_GETH0_P0_CSRDV,
    .refClk = &BOARD_GETH0_P0_REFCLK,
    .txd0 = &BOARD_GETH0_P0_TXD0,
    .txd1 = &BOARD_GETH0_P0_TXD1,
    .txEn = &BOARD_GETH0_P0_TXEN
};

/* the data buffers and the descriptors need to be aligned to 64-bit addresses, 8bytes */
IFX_ALIGN(8) IfxGeth_TxDescr geth_tx_desc0[IFXGETH_MAX_TX_DESCRIPTORS];
IFX_ALIGN(8) IfxGeth_RxDescr geth_rx_desc0[IFXGETH_MAX_RX_DESCRIPTORS];

IFX_ALIGN(8) uint8 geth_tx_buffer0[IFXGETH_MAX_TX_DESCRIPTORS][IFXGETH_MAX_TX_BUFFER_SIZE];
IFX_ALIGN(8) uint8 geth_rx_buffer0[IFXGETH_MAX_RX_DESCRIPTORS][IFXGETH_MAX_RX_BUFFER_SIZE];

static const uint8 geth0_p0_mac_address[] = {0x00, 0x03, 0x19, 0x00, 0x00, 0x00};

static volatile uint32 timer_ms;

static timer_t timers[] =
{
    [0] = {
        .period_ms = TIMER_LED_TOOGLE_MS,
        .timer_cb = timer_toogle_led_cb,
        .arg = NULL
    },
    [1] = {
        .period_ms = TIMER_PHY_MONITOR_MS,
        .timer_cb = timer_phy_monitor,
        .arg = (void *)IfxGeth_PortIndex_0
    },
};

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/

void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxWtu_disableCpuWatchdog(IfxWtu_getCpuWatchdogPassword());
    IfxWtu_disableSystemWatchdog(IfxWtu_getSystemWatchdogPassword());
    
    IfxPort_setPinHigh(BOARD_USER_LED_1.port, BOARD_USER_LED_1.pinIndex);
    IfxPort_setPinModeOutput(BOARD_USER_LED_1.port, BOARD_USER_LED_1.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    if (retarget_io_init(&BOARD_DEBUG_UART_TX, &BOARD_DEBUG_UART_RX, 115200) != 0)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
    }

    /* switch on VDDPHPHY0, VDDPHY0, VDDPHPHY1, VDDPHY1 */
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphphy0);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphy0);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphphy1);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphy1);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphphy2);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddphy2);
    IfxPmsEvr_enableVoltageRail(&MODULE_PMS, IfxPmsEvr_PrimaryMonitorVoltageSource_vddhsif);

    HSPHY_Init();

    const Ifx_HSPHY_ETH_Bits hsphy_geth0_p0_config =
    {
        .EPR = HSPHY_ETH_EPR_RMII,
        .MDIOEN = TRUE,
        .MDIO = BOARD_GETH0_P0_MDIO.inSelect
    };

    HSPHY_ETH_Init(0, hsphy_geth0_p0_config);

    IfxGeth_enableModule(&MODULE_GETH0);

    uint32 geth_clk_rate = IfxClock_getXGeth0Frequency();

    if (IfxGeth_Mdio_init(&MODULE_GETH0, IfxGeth_PortIndex_0, &geth0_p0_mdio_pins, geth_clk_rate) != 0)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
    }

    if (dp83825i_init(&phy_0, BOARD_GETH0_P0_PHYADR,
                      geth0_p0_mdio_read, geth0_p0_mdio_write, 0) != 0)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
    }
    dp83825i_cfg_link(&phy_0, LINK_FULL_100BASE_T);

    geth0_init();

    /* Demo execution */
    printf("****************** "
           " TC4D7 Lite Kit: GETH Demo  "
           "****************** \r\n\n");

    /* Initialize scheduler timer */
    IfxStm_CompareConfig cpu0_stm_config;
    IfxStm_initCompareConfig(&cpu0_stm_config);
    cpu0_stm_config.triggerPriority = IFX_INTPRIO_CPU0_STM;
    cpu0_stm_config.typeOfService = IfxSrc_Tos_cpu0;
    cpu0_stm_config.ticks = IfxStm_getTicksFromMilliseconds(TIMER_TICK_MS);
    IfxStm_initCompare(&MODULE_CPU0, &cpu0_stm_config);

    while (1)
    {
        for (sint32 i = 0; i < sizeof(timers) / sizeof(timer_t); ++i)
        {
            if ((timer_ms - timers[i].last_event_ms) >= timers[i].period_ms)
            {
                timers[i].last_event_ms = timer_ms;
                if (timers[i].timer_cb != NULL)
                {
                    timers[i].timer_cb(timers[i].arg);
                }
            }
        }

        if (geth0_rxdma0_interrupt)
        {
            geth0_rxdma0_interrupt = FALSE;

            /* get size of received frame */
            volatile IfxGeth_RxDescr *rx_desc = IfxGeth_Eth_getActualRxDescriptor(&geth0, IfxGeth_RxDmaChannel_0);
            while (rx_desc->RDES3.W.OWN == 0)
            {
                if (rx_desc->RDES3.W.CTXT == 0)
                {
                    if ((rx_desc->RDES3.W.FD == 1) && (rx_desc->RDES3.W.LD == 1) && (rx_desc->RDES3.W.ES == 0))
                    {
                        size_t len = rx_desc->RDES3.W.PL - 4;

                        uint8 *pRxBuf = (uint8*)IfxGeth_Eth_getReceiveBuffer(&geth0, IfxGeth_RxDmaChannel_0);
                        uint8 *pTxBuf = IfxGeth_Eth_getTransmitBuffer(&geth0, IfxGeth_TxDmaChannel_0);
                        if (pTxBuf != NULL)
                        {
                            /* prepare echo message */
                            /* destination address of transmitted frame is the source address of the received frame */
                            memcpy(&pTxBuf[0], &pRxBuf[6], 6);
                            /* update source address */
                            memcpy(&pTxBuf[6], &geth0_p0_mac_address[0], 6);
                            memcpy(&pTxBuf[12], &pRxBuf[12], len - 12);
                            IfxGeth_Eth_sendTransmitBuffer(&geth0, 0, len, IfxGeth_TxDmaChannel_0);
                        }
                    }
                }
                else
                {
                    /* we do not process the timestamp */
                }
                IfxGeth_Eth_shuffleRxDescriptor(&geth0, IfxGeth_RxDmaChannel_0);
                rx_desc = IfxGeth_Eth_getActualRxDescriptor(&geth0, IfxGeth_RxDmaChannel_0);
            }
        }
    }
}

static uint16 geth0_p0_mdio_read(uint8 phy_addr, uint8 dev_addr, uint16 reg_addr)
{
    return IfxGeth_Mdio_read(&MODULE_GETH0, 0, phy_addr, dev_addr, reg_addr);
}

static void geth0_p0_mdio_write(uint8 phy_addr, uint8 dev_addr, uint16 reg_addr, uint16 reg_val)
{
    IfxGeth_Mdio_write(&MODULE_GETH0, 0, phy_addr, dev_addr, reg_addr, reg_val);
}

static void timer_toogle_led_cb(void *arg)
{
    IfxPort_togglePin(BOARD_USER_LED_1.port, BOARD_USER_LED_1.pinIndex);
}

static void timer_phy_monitor(void *arg)
{
    IfxGeth_PortIndex port_index = (IfxGeth_PortIndex)arg;
    phy_t *phy = &phy_0;

    if (dp83825i_update_link(phy))
    {
        if (phy->link_status.is_up == false)
        {
            IfxGeth_stopRx(&MODULE_GETH0, port_index);
            IfxGeth_stopTx(&MODULE_GETH0, port_index);

            printf("GETH0_P%d link is down\r\n", port_index);
        }
        else
        {
            switch (phy->link_status.speed)
            {
                    case LINK_FULL_100BASE_T:
                        IfxGeth_setSpeed(&MODULE_GETH0, port_index, IfxGeth_Speed_100M_MII);
                        IfxGeth_setDuplexMode(&MODULE_GETH0, port_index, IfxGeth_DuplexMode_fullDuplex);
                        break;

                    default:
                        break;
            }

            IfxGeth_startRx(&MODULE_GETH0, port_index);
            IfxGeth_startTx(&MODULE_GETH0, port_index);

            printf("GETH0_P%d link is up\r\n", port_index);
            printf("Link speed %s Mb, %s duplex\n", PHY_LINK_IS_SPEED_100M(phy->link_status.speed) ? "100" : "10",
                                                     PHY_LINK_IS_FULL_DUPLEX(phy->link_status.speed) ? "full" : "half");
        }
    }
}

static void geth0_init(void)
{
    IfxGeth_enableModule(&MODULE_GETH0);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermacAxi);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermacDmi);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac0Gcl);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac1Gcl);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac0RxEven);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac0RxOdd);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac1RxEven);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac1RxOdd);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac0TxEven);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac0TxOdd);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac1TxEven);
    IfxVmt_clearSram(IfxVmt_MbistSel_ethermac1TxOdd);

    IfxHsphy_Geth_setupRmiiInputPins(&MODULE_HSPHY, IfxHsphy_EthIndex_0, &geth0_p0_pins);

    IfxGeth_Eth_Config config;
    IfxGeth_Eth_initModuleConfig(&config, &MODULE_GETH0);

    config.port[0].mac.disableCrcCheck = FALSE;
    config.port[0].mtl.rxQueue[0].enable = TRUE;
    config.port[0].mtl.rxQueue[0].enableDynamicDmaChannelMap = TRUE;
    config.port[0].mtl.rxQueue[0].rxQueueSize = (4096 >> 8) - 1;
    config.port[0].mtl.txQueue[0].enable = TRUE;
    config.port[0].mtl.txQueue[0].txQueueSize = (4096 >> 8) - 1;
    memcpy(config.port[0].mac.macAddress, geth0_p0_mac_address, 6);

    config.dma.addressAlignedBeatsEnabled = TRUE;
    config.dma.burstLength = IfxGeth_DmaBurstLength_16;
    config.dma.undefinedBurstLength = FALSE;
    memset(config.dma.burstLengthMultiplierEnable, FALSE, sizeof(boolean));
    config.dma.txChannel[0].channelEnable = TRUE;
    config.dma.txChannel[0].maxBurstLength = IfxGeth_TxBurstLength_16;
    config.dma.txChannel[0].txDescrList = (IfxGeth_TxDescrList *)geth_tx_desc0;
    config.dma.txChannel[0].txBuffer1Size  = IFXGETH_MAX_TX_BUFFER_SIZE;
    config.dma.txChannel[0].txBuffer1StartAddress = (uint32 *)geth_tx_buffer0;
    config.dma.rxChannel[0].channelEnable = TRUE;
    config.dma.rxChannel[0].maxBurstLength = IfxGeth_RxBurstLength_16;
    config.dma.rxChannel[0].rxDescrList = (IfxGeth_RxDescrList *)geth_rx_desc0;
    config.dma.rxChannel[0].rxBuffer1Size  = IFXGETH_MAX_RX_BUFFER_SIZE;
    config.dma.rxChannel[0].rxBuffer1StartAddress = (uint32 *)geth_rx_buffer0;

    config.dma.rxInterrupt[IfxGeth_DmaChannel_0].priority = INTPRIO_CPU0_GETH0_DMA_CH_0;
    config.dma.txInterrupt[IfxGeth_DmaChannel_0].priority = INTPRIO_CPU0_GETH0_DMA_CH_0;

    config.bridge.mode = IfxGeth_BridgePortMode_singlePort0;

    IfxGeth_Eth_initModule(&geth0, &config);

    uint32 geth_clk_rate = IfxClock_getXGeth0Frequency();
    if (IfxGeth_Mdio_init(&MODULE_GETH0, IfxGeth_PortIndex_0, NULL, geth_clk_rate) != 0)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, 0);
    }

    /* reset filter settings */
    MODULE_GETH0.PORT[0].CORE.MAC_PACKET_FILTER.U = 0;

    IfxGeth_startRxDma(&MODULE_GETH0, IfxGeth_RxDmaChannel_0);
    IfxGeth_startTxDma(&MODULE_GETH0, IfxGeth_TxDmaChannel_0);

    /* MAC Output pins (MAC to PHY) */
    IfxHsphy_Geth_setupRmiiOutputPins(&MODULE_HSPHY, &geth0_p0_pins);
}

IFX_INTERRUPT(cpu0_stm_isr, 0, IFX_INTPRIO_CPU0_STM)
{
    IfxStm_clearCompareFlag(&MODULE_CPU0, IfxStm_Comparator_0);
    IfxStm_increaseCompare(&MODULE_CPU0, IfxStm_Comparator_0, IfxStm_getTicksFromMilliseconds(TIMER_TICK_MS));

    timer_ms += TIMER_TICK_MS;
}

/*
 * No need to clear status of interrupts since
 * DMA_Mode.INTM = 00: sbd_perch_* are pulse signals for each completion
 * events. sbd_intr_o is also asserted and cleared only when
 * software clears the corresponding RI/TI status bits
 */
IFX_INTERRUPT(GETH0_DMA_CH_0, 0, INTPRIO_CPU0_GETH0_DMA_CH_0)
{
    uint32 status = IfxGeth_getDmaStatus(&MODULE_GETH0, IfxGeth_RxDmaChannel_0);
    IfxGeth_clearDmaStatus(&MODULE_GETH0, IfxGeth_RxDmaChannel_0, status);
    if (status & IfxGeth_DmaStatus_RI)
    {
        geth0_rxdma0_interrupt = TRUE;
    }
    if (status & IfxGeth_DmaStatus_TI)
    {
        geth0_txdma0_interrupt = TRUE;
    }
}
