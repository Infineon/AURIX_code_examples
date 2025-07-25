/**
 * \file IfxLeth.c
 * \brief LETH  basic functionality
 *
 * \version iLLD-TC4-v2.1.1
 * \copyright Copyright (c) 2024 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
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
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxLeth.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxLeth_disableModule(Ifx_LETH *lethSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_config);
#endif

    lethSFR->CLC.B.DISR = 1;        /* set the disable request */

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_run);
#endif
}


void IfxLeth_enableModule(Ifx_LETH *lethSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_config);
#endif

    if (IfxLeth_isModuleEnabled(lethSFR) != 1) /* if module is not enabled already */
    {
        lethSFR->CLC.B.DISR = 0;               /* set the enable request */
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_run);
#endif

    while (IfxLeth_isModuleEnabled(lethSFR) == FALSE) /* wait till enabled */
    {}
}


void IfxLeth_resetModule(Ifx_LETH *lethSFR)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_config);
#endif

    lethSFR->RST.CTRLA.B.KRST = 1;          /* Only if both Kernel reset bits are set a reset is executed */
    lethSFR->RST.CTRLB.B.KRST = 1;

    while (lethSFR->RST.STAT.B.KRST == 0)   /* Wait until reset is executed */
    {}

    lethSFR->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (lethSFR->RST.STAT.B.KRST == 1)   /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_run);
#endif
}


void IfxLeth_initApConfig(IfxLeth_ApConfig *config)
{
    IfxLeth_PortIndex  portIndex;
    IfxLeth_DmaChannel channelIndex;

    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuGlobalConfig);

    for (portIndex = IfxLeth_PortIndex_0; portIndex < IFXLETH_NUM_PORTS; portIndex++)
    {
        IfxApApu_initConfig(&config->apuMacConfig[portIndex]);
    }

    for (channelIndex = IfxLeth_DmaChannel_0; channelIndex < IFXLETH_NUM_DMA_CHANNELS; channelIndex++)
    {
        IfxApApu_initConfig(&config->apuChConfig[channelIndex]);
    }
}


void IfxLeth_initAp(Ifx_LETH *lethSFR, IfxLeth_ApConfig *config)
{
    IfxLeth_PortIndex  portIndex;
    IfxLeth_DmaChannel channelIndex;

    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&lethSFR->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&lethSFR->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&lethSFR->PROTSE, IfxApProt_State_config);

    IfxApApu_init((Ifx_ACCEN_ACCEN *)&lethSFR->ACCENGLOBAL, &config->apuGlobalConfig);

    for (portIndex = IfxLeth_PortIndex_0; portIndex < IFXLETH_NUM_PORTS; portIndex++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&lethSFR->ACCENMAC[portIndex], &config->apuMacConfig[portIndex]);
    }

    for (channelIndex = IfxLeth_DmaChannel_0; channelIndex < IFXLETH_NUM_DMA_CHANNELS; channelIndex++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&lethSFR->ACCENCH[channelIndex], &config->apuChConfig[channelIndex]);
    }

    IfxApProt_setState((Ifx_PROT_PROT *)&lethSFR->PROTSE, IfxApProt_State_run);
}


void IfxLeth_configureAccessToLeth(IfxApApu_ApuConfig *apConfig)
{
    uint8 index;

    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_LETH0.ACCENGLOBAL, apConfig);

    for (index = 0; index < IFXLETH_NUM_PORTS; index++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_LETH0.ACCENMAC[index], apConfig);
    }

    for (index = 0; index < IFXLETH_NUM_DMA_CHANNELS; index++)
    {
        IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_LETH0.ACCENCH[index], apConfig);
    }
}


void IfxLeth_dmaChannelBusIdConfig(Ifx_LETH *lethSFR, IfxLeth_DmaChannel dmaChannelIndex, IfxLeth_DmaApuConfig *dmaApuConfig)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_config);
#endif

    lethSFR->DMACH[dmaChannelIndex].TAGVMPRS.B.PRS    = dmaApuConfig->prsId;
    lethSFR->DMACH[dmaChannelIndex].TAGVMPRS.B.PRSEN  = dmaApuConfig->prsEnable;
    lethSFR->DMACH[dmaChannelIndex].TAGVMPRS.B.TAGOFF = dmaApuConfig->tagOff;
    lethSFR->DMACH[dmaChannelIndex].TAGVMPRS.B.VM     = dmaApuConfig->vmId;
    lethSFR->DMACH[dmaChannelIndex].TAGVMPRS.B.VMEN   = dmaApuConfig->vmEnable;

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(lethSFR->PROTE), IfxApProt_State_run);
#endif
}


void IfxLeth_setupRmiiOutputPins(Ifx_LETH *lethSFR, const IfxLeth_RmiiPins *rmiiPins)
{
    IFX_UNUSED_PARAMETER(lethSFR);
    IfxPort_OutputMode mode       = IfxPort_OutputMode_pushPull;
    IfxPort_PadDriver  speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    //if (rmiiPins != NULL_PTR)
    {
        if (rmiiPins->txEn != NULL_PTR)
        {
            IfxLeth_P_Out *txen = rmiiPins->txEn;
            IfxPort_setPinControllerSelection(txen->pin.port, txen->pin.pinIndex);
            IfxPort_setPinModeOutput(txen->pin.port, txen->pin.pinIndex, mode, txen->select);
            IfxPort_setPinPadDriver(txen->pin.port, txen->pin.pinIndex, speedGrade);
        }

        if (rmiiPins->txd0 != NULL_PTR)
        {
            IfxLeth_P_Out *txd0 = rmiiPins->txd0;
            IfxPort_setPinControllerSelection(txd0->pin.port, txd0->pin.pinIndex);
            IfxPort_setPinModeOutput(txd0->pin.port, txd0->pin.pinIndex, mode, txd0->select);
            IfxPort_setPinPadDriver(txd0->pin.port, txd0->pin.pinIndex, speedGrade);
        }

        if (rmiiPins->txd1 != NULL_PTR)
        {
            IfxLeth_P_Out *txd1 = rmiiPins->txd1;
            IfxPort_setPinControllerSelection(txd1->pin.port, txd1->pin.pinIndex);
            IfxPort_setPinModeOutput(txd1->pin.port, txd1->pin.pinIndex, mode, txd1->select);
            IfxPort_setPinPadDriver(txd1->pin.port, txd1->pin.pinIndex, speedGrade);
        }
    }
}


void IfxLeth_setupRmiiInputPins(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, const IfxLeth_RmiiPins *rmiiPins)
{
    IfxPort_InputMode mode       = IfxPort_InputMode_noPullDevice;
    IfxPort_PadDriver speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed1;
    IfxLeth_P_In     *crsDiv     = rmiiPins->crsDv;
    IfxLeth_P_In     *refClk     = rmiiPins->refClk;
    IfxLeth_P_In     *rxd0       = rmiiPins->rxd0;
    IfxLeth_P_In     *rxd1       = rmiiPins->rxd1;

    //if (rmiiPins != NULL_PTR)
    {
        if (rmiiPins->crsDv != NULL_PTR)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.RXDV = crsDiv->select; /* RMII CRSDV uses the same mux as MII RXDV */
            IfxPort_setPinControllerSelection(crsDiv->pin.port, crsDiv->pin.pinIndex);
            IfxPort_setPinModeInput(crsDiv->pin.port, crsDiv->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(crsDiv->pin.port, crsDiv->pin.pinIndex, speedGrade);
        }

        if (rmiiPins->refClk != NULL_PTR)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.REFCLK = refClk->select;
            IfxPort_setPinControllerSelection(refClk->pin.port, refClk->pin.pinIndex);
            IfxPort_setPinModeInput(refClk->pin.port, refClk->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(refClk->pin.port, refClk->pin.pinIndex, speedGrade);
        }

        if (rmiiPins->rxd0 != NULL_PTR)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.RXD0 = rxd0->select;
            IfxPort_setPinControllerSelection(rxd0->pin.port, rxd0->pin.pinIndex);
            IfxPort_setPinModeInput(rxd0->pin.port, rxd0->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd0->pin.port, rxd0->pin.pinIndex, speedGrade);
        }

        if (rmiiPins->rxd1 != NULL_PTR)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.RXD1 = rxd1->select;
            IfxPort_setPinControllerSelection(rxd1->pin.port, rxd1->pin.pinIndex);
            IfxPort_setPinModeInput(rxd1->pin.port, rxd1->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd1->pin.port, rxd1->pin.pinIndex, speedGrade);
        }
    }
}


void IfxLeth_setRmiiPins(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, const IfxLeth_RmiiPins *rmiiPins)
{
    IfxLeth_setupRmiiInputPins(lethSFR, portIndex, rmiiPins);
    IfxLeth_setupRmiiOutputPins(lethSFR, rmiiPins);
}


void IfxLeth_setupMiiInputPins(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, const IfxLeth_MiiPins *miiPins)
{
    IfxPort_InputMode mode       = IfxPort_InputMode_noPullDevice;
    IfxPort_PadDriver speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    //if (miiPins != NULL_PTR)
    {
        if (miiPins->crs != NULL_PTR)
        {
            IfxLeth_P_In *crs = miiPins->crs;
            lethSFR->P[portIndex].PORTCTRL0.B.CRS = crs->select;
            IfxPort_resetPinControllerSelection(crs->pin.port, crs->pin.pinIndex);
            IfxPort_setPinModeInput(crs->pin.port, crs->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(crs->pin.port, crs->pin.pinIndex, speedGrade);
        }

        if (miiPins->col != NULL_PTR)
        {
            IfxLeth_P_In *col = miiPins->col;
            lethSFR->P[portIndex].PORTCTRL0.B.COL = col->select;
            IfxPort_resetPinControllerSelection(col->pin.port, col->pin.pinIndex);
            IfxPort_setPinModeInput(col->pin.port, col->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(col->pin.port, col->pin.pinIndex, speedGrade);
        }

        if (miiPins->txClk != NULL_PTR)
        {
            IfxLeth_P_In *txClk = miiPins->txClk;
            lethSFR->P[portIndex].PORTCTRL0.B.TXCLK = txClk->select;
            IfxPort_resetPinControllerSelection(txClk->pin.port, txClk->pin.pinIndex);
            IfxPort_setPinModeInput(txClk->pin.port, txClk->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(txClk->pin.port, txClk->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxClk != NULL_PTR)
        {
            IfxLeth_P_In *rxClk = miiPins->rxClk;
            lethSFR->P[portIndex].PORTCTRL0.B.RXCLK = rxClk->select;
            IfxPort_resetPinControllerSelection(rxClk->pin.port, rxClk->pin.pinIndex);
            IfxPort_setPinModeInput(rxClk->pin.port, rxClk->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxClk->pin.port, rxClk->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxDv != NULL_PTR)
        {
            IfxLeth_P_In *rxDv = miiPins->rxDv;
            lethSFR->P[portIndex].PORTCTRL0.B.RXDV = rxDv->select;
            IfxPort_resetPinControllerSelection(rxDv->pin.port, rxDv->pin.pinIndex);
            IfxPort_setPinModeInput(rxDv->pin.port, rxDv->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxDv->pin.port, rxDv->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxEr != NULL_PTR)
        {
            IfxLeth_P_In *rxEr = miiPins->rxEr;
            lethSFR->P[portIndex].PORTCTRL0.B.RXER = rxEr->select;
            IfxPort_resetPinControllerSelection(rxEr->pin.port, rxEr->pin.pinIndex);
            IfxPort_setPinModeInput(rxEr->pin.port, rxEr->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxEr->pin.port, rxEr->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxd0 != NULL_PTR)
        {
            IfxLeth_P_In *rxd0 = miiPins->rxd0;
            lethSFR->P[portIndex].PORTCTRL0.B.RXD0 = rxd0->select;
            IfxPort_resetPinControllerSelection(rxd0->pin.port, rxd0->pin.pinIndex);
            IfxPort_setPinModeInput(rxd0->pin.port, rxd0->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd0->pin.port, rxd0->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxd1 != NULL_PTR)
        {
            IfxLeth_P_In *rxd1 = miiPins->rxd1;
            lethSFR->P[portIndex].PORTCTRL0.B.RXD1 = rxd1->select;
            IfxPort_resetPinControllerSelection(rxd1->pin.port, rxd1->pin.pinIndex);
            IfxPort_setPinModeInput(rxd1->pin.port, rxd1->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd1->pin.port, rxd1->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxd2 != NULL_PTR)
        {
            IfxLeth_P_In *rxd2 = miiPins->rxd2;
            lethSFR->P[portIndex].PORTCTRL0.B.RXD2 = rxd2->select;
            IfxPort_resetPinControllerSelection(rxd2->pin.port, rxd2->pin.pinIndex);
            IfxPort_setPinModeInput(rxd2->pin.port, rxd2->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd2->pin.port, rxd2->pin.pinIndex, speedGrade);
        }

        if (miiPins->rxd3 != NULL_PTR)
        {
            IfxLeth_P_In *rxd3 = miiPins->rxd3;
            lethSFR->P[portIndex].PORTCTRL0.B.RXD3 = rxd3->select;
            IfxPort_resetPinControllerSelection(rxd3->pin.port, rxd3->pin.pinIndex);
            IfxPort_setPinModeInput(rxd3->pin.port, rxd3->pin.pinIndex, mode);
            IfxPort_setPinPadDriver(rxd3->pin.port, rxd3->pin.pinIndex, speedGrade);
        }
    }
}


void IfxLeth_setupMiiOutputPins(Ifx_LETH *lethSFR, const IfxLeth_MiiPins *miiPins)
{
    IFX_UNUSED_PARAMETER(lethSFR);
    IfxPort_OutputMode mode       = IfxPort_OutputMode_pushPull;
    IfxPort_PadDriver  speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    if (miiPins != NULL_PTR)
    {
        if (miiPins->txEn != NULL_PTR)
        {
            IfxLeth_P_Out *txEn = miiPins->txEn;
            IfxPort_resetPinControllerSelection(txEn->pin.port, txEn->pin.pinIndex);
            IfxPort_setPinModeOutput(txEn->pin.port, txEn->pin.pinIndex, mode, txEn->select);
            IfxPort_setPinPadDriver(txEn->pin.port, txEn->pin.pinIndex, speedGrade);
        }

        if (miiPins->txEr != NULL_PTR)
        {
            IfxLeth_P_Out *txEr = miiPins->txEr;
            IfxPort_resetPinControllerSelection(txEr->pin.port, txEr->pin.pinIndex);
            IfxPort_setPinModeOutput(txEr->pin.port, txEr->pin.pinIndex, mode, txEr->select);
            IfxPort_setPinPadDriver(txEr->pin.port, txEr->pin.pinIndex, speedGrade);
        }

        if (miiPins->txd0 != NULL_PTR)
        {
            IfxLeth_P_Out *txd0 = miiPins->txd0;
            IfxPort_resetPinControllerSelection(txd0->pin.port, txd0->pin.pinIndex);
            IfxPort_setPinModeOutput(txd0->pin.port, txd0->pin.pinIndex, mode, txd0->select);
            IfxPort_setPinPadDriver(txd0->pin.port, txd0->pin.pinIndex, speedGrade);
        }

        if (miiPins->txd1 != NULL_PTR)
        {
            IfxLeth_P_Out *txd1 = miiPins->txd1;
            IfxPort_resetPinControllerSelection(txd1->pin.port, txd1->pin.pinIndex);
            IfxPort_setPinModeOutput(txd1->pin.port, txd1->pin.pinIndex, mode, txd1->select);
            IfxPort_setPinPadDriver(txd1->pin.port, txd1->pin.pinIndex, speedGrade);
        }

        if (miiPins->txd2 != NULL_PTR)
        {
            IfxLeth_P_Out *txd2 = miiPins->txd2;
            IfxPort_resetPinControllerSelection(txd2->pin.port, txd2->pin.pinIndex);
            IfxPort_setPinModeOutput(txd2->pin.port, txd2->pin.pinIndex, mode, txd2->select);
            IfxPort_setPinPadDriver(txd2->pin.port, txd2->pin.pinIndex, speedGrade);
        }

        if (miiPins->txd3 != NULL_PTR)
        {
            IfxLeth_P_Out *txd3 = miiPins->txd3;
            IfxPort_resetPinControllerSelection(txd3->pin.port, txd3->pin.pinIndex);
            IfxPort_setPinModeOutput(txd3->pin.port, txd3->pin.pinIndex, mode, txd3->select);
            IfxPort_setPinPadDriver(txd3->pin.port, txd3->pin.pinIndex, speedGrade);
        }
    }
}


void IfxLeth_setMiiPins(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, const IfxLeth_MiiPins *miiPins)
{
    IfxLeth_setupMiiInputPins(lethSFR, portIndex, miiPins);
    IfxLeth_setupMiiOutputPins(lethSFR, miiPins);
}


void IfxLeth_setTC14Pins(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, const IfxLeth_TC14Pins *tc14Pins)
{
    IfxPort_OutputMode outputMode = IfxPort_OutputMode_pushPull;
    IfxPort_InputMode  inputMode  = IfxPort_InputMode_noPullDevice;
    IfxPort_PadDriver  speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed1;

    if (tc14Pins != NULL_PTR)
    {
        IfxLeth_P_Out *tx = tc14Pins->tx;
        IfxLeth_P_In  *rx = tc14Pins->rx;
        IfxLeth_P_In  *ed = tc14Pins->ed;

        IfxPort_resetPinControllerSelection(tx->pin.port, tx->pin.pinIndex);
        IfxPort_setPinModeOutput(tx->pin.port, tx->pin.pinIndex, outputMode, tx->select);
        IfxPort_setPinPadDriver(tx->pin.port, tx->pin.pinIndex, speedGrade);

        lethSFR->P[portIndex].PORTCTRL0.B.RXDEN = 1;
        lethSFR->P[portIndex].PORTCTRL0.B.RXD   = rx->select;
        IfxPort_resetPinControllerSelection(rx->pin.port, rx->pin.pinIndex);
        IfxPort_setPinModeInput(rx->pin.port, rx->pin.pinIndex, inputMode);
        IfxPort_setPinPadDriver(rx->pin.port, rx->pin.pinIndex, speedGrade);

        lethSFR->P[portIndex].PORTCTRL1.B.MDIOEN = 1;
        lethSFR->P[portIndex].PORTCTRL1.B.MDIO   = ed->select;
        IfxPort_resetPinControllerSelection(ed->pin.port, ed->pin.pinIndex);
        IfxPort_setPinModeInput(ed->pin.port, ed->pin.pinIndex, inputMode);
        IfxPort_setPinPadDriver(ed->pin.port, ed->pin.pinIndex, speedGrade);
    }
}


void IfxLeth_setPhyInterface(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, IfxLeth_PhyInterface phyInterface, IfxLeth_PhyInterfacePhase initPhase)
{
    switch (phyInterface)
    {
    case IfxLeth_PhyInterface_mii_10:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR = 0;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 0;
        }

        break;
    }
    case IfxLeth_PhyInterface_mii_100:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR = 0;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 1;
        }

        break;
    }
    case IfxLeth_PhyInterface_rmii_10:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR = 2;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 0;
        }

        break;
    }
    case IfxLeth_PhyInterface_rmii_100:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR = 1;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 1;
        }

        break;
    }
    case IfxLeth_PhyInterface_tc14_10_NRZ:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR    = 3;
            lethSFR->P[portIndex].PORTCTRL0.B.TC14EN = 0;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 0;
        }

        break;
    }
    case IfxLeth_PhyInterface_tc14_10_RZ:
    {
        if (initPhase == IfxLeth_PhyInterfacePhase_1)
        {
            lethSFR->P[portIndex].PORTCTRL0.B.EPR    = 3;
            lethSFR->P[portIndex].PORTCTRL0.B.TC14EN = 1;
        }
        else
        {
            lethSFR->PORT[portIndex].CORE.MAC_CONFIGURATION.B.FES = 0;
        }

        break;
    }
    }
}


void IfxLeth_enablePortClock(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex)
{
    lethSFR->PEN.U &= (~0x0000000F | (~(1 << portIndex)));

    while (((lethSFR->PEN.U) & (1 << (0x10 + portIndex))) == 1) /*Check status*/
    {}
}


volatile Ifx_SRC_SRCR *IfxLeth_getSrcPointer(IfxLeth_ServiceRequest serviceRequest)
{
    Ifx_SRC_SRCR *src = (Ifx_SRC_SRCR *)(&MODULE_SRC.LETH[0]);
    return &src[serviceRequest];
}


void IfxLeth_Bridge_setPortMode(Ifx_LETH *lethSFR, IfxLeth_BridgePortMode mode)
{
    if (mode < IfxLeth_BridgePortMode_multiPort)
    {
        lethSFR->BRIDGE.ETHBR_FWD_CTRL_REG.B.Q_CH_MAPPING_EN = 0;    /*Single Port Mode*/
        lethSFR->BRIDGE.ETHBR_FWD_CTRL_REG.B.PORT_SEL        = mode; /*Selected port only to be used*/
    }
    else /*IfxLeth_BridgePortMode_multiPort*/
    {
        lethSFR->BRIDGE.ETHBR_FWD_CTRL_REG.B.Q_CH_MAPPING_EN = 1; /*Multi Port Mode*/
        lethSFR->BRIDGE.ETHBR_FWD_CTRL_REG.B.PORT_SEL        = 0; /*No specific instructions, keeping default reset value*/
    }
}


void IfxLeth_Bridge_mapTxQueue(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, IfxLeth_TxMtlQueue queueNumber, IfxLeth_BridgeTxQueueMap mapValue)
{
    switch (queueNumber)
    {
    case IfxLeth_TxMtlQueue_0:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].TXQ_MAP.B.TXQ0_MAP = mapValue;
        break;
    }
    case IfxLeth_TxMtlQueue_1:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].TXQ_MAP.B.TXQ1_MAP = mapValue;
        break;
    }
    case IfxLeth_TxMtlQueue_2:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].TXQ_MAP.B.TXQ2_MAP = mapValue;
        break;
    }
    case IfxLeth_TxMtlQueue_3:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].TXQ_MAP.B.TXQ3_MAP = mapValue;
        break;
    }
    case IfxLeth_TxMtlQueue_4:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].TXQ_MAP.B.TXQ4_MAP = mapValue;
        break;
    }
    }
}


void IfxLeth_Bridge_mapRxChannel(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, IfxLeth_BridgeRxChannel channelNumber, IfxLeth_BridgeRxCMap mapValue)
{
    switch (channelNumber)
    {
    case IfxLeth_BridgeRxChannel_0:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC0_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_1:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC1_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_2:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC2_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_3:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC3_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_4:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC4_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_5:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC5_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_6:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC6_MAP = mapValue;
        break;
    }
    case IfxLeth_BridgeRxChannel_7:
    {
        lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].RXC_MAP.B.RXC7_MAP = mapValue;
        break;
    }
    }
}


void IfxLeth_Bridge_enablePortTxQueuesAndRxChannels(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, IfxLeth_TxQRxCEnableConfig enable)
{
    lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].CTRL_REG.B.TXQ_EN = enable.txQueues;
    lethSFR->BRIDGE.PORT_CTRL_MAP[portIndex].CTRL_REG.B.RXC_EN = enable.rxChannels;
}


void IfxLeth_enableMmcCounterFreeze(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex, boolean enable)
{
    lethSFR->PORT[portIndex].CORE.MMC_CONTROL.B.CNTFREEZ = enable;
}


void IfxLeth_resetMmcCounter(Ifx_LETH *lethSFR, IfxLeth_PortIndex portIndex)
{
    lethSFR->PORT[portIndex].CORE.MMC_CONTROL.B.CNTRST = 1;
}


void IfxLeth_setMdioOnlyPins(Ifx_LETH *lethSFR, const IfxLeth_MdioPins *mdioPins)
{
    IfxPort_InputMode  inOutMode  = IfxPort_InputMode_noPullDevice;
    IfxPort_OutputMode outputMode = IfxPort_OutputMode_pushPull;
    IfxPort_PadDriver  speedGrade = IfxPort_PadDriver_cmosAutomotiveSpeed3;

    IfxLeth_P_Out     *mdc        = mdioPins->mdc;

    if (mdioPins->mdc != NULL_PTR)
    {
        {
            /* Disabled for non TC14 interfaces. For TC14 use IfxLeth_setTC14Pins API */
            lethSFR->P[mdioPins->portIndex].PORTCTRL0.B.RXDEN = 0;
            lethSFR->P[mdioPins->portIndex].PORTCTRL0.B.RXD   = 0;
        }
        IfxPort_setPinModeOutput(mdc->pin.port, mdc->pin.pinIndex, outputMode, mdc->select);
        IfxPort_setPinPadDriver(mdc->pin.port, mdc->pin.pinIndex, speedGrade);
    }

    IfxLeth_P_InOut *mdio = mdioPins->mdio;

    if (mdioPins->mdio != NULL_PTR)
    {
        lethSFR->P[mdioPins->portIndex].PORTCTRL1.B.MDIOEN = 1;
        lethSFR->P[mdioPins->portIndex].PORTCTRL1.B.MDIO   = mdio->inSelect;
        IfxPort_setPinModeInput(mdio->pin.port, mdio->pin.pinIndex, inOutMode);
        IfxPort_setPinPadDriver(mdio->pin.port, mdio->pin.pinIndex, speedGrade);
    }
}
