/**
 * \file IfxXspi.c
 * \brief XSPI  basic functionality
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Infineon Technologies AG (Infineon) licenses this file to you under the
 * Infineon Automotive SW Lab License v2025-01 (IFASLL). You may not use
 * this file except in compliance with IFASLL.
 *
 * The full license text is contained in IFASLL202501.pdf delivered with this SW.
 * Unless required by applicable law or agreed to in writing, software distributed
 * under this license is distributed "AS IS" without any warranty or liability of any
 * kind and Infineon hereby expressly disclaims any warranties or representations,
 * whether express, implied, statutory or otherwise, including but not limited to
 * warranties of workmanship, merchantability, fitness for a particular purpose,
 * defects in the licensed items, or non-infringement of third parties'
 * intellectual property rights. See the full license text for the specific
 * language governing permissions and limitations under IFASLL.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508 /* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96 /* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)
#include "IfxXspi.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

volatile Ifx_SRC_SRCR *IfxXspi_getSrcPointerFifo(Ifx_XSPI *xspi)
{
    return (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.XSPI.FIFO);
}


void IfxXspi_initApConfig(IfxXspi_ApConfig *config)
{
    IfxApProt_initConfig(&config->proteConfig);
    IfxApProt_initConfig(&config->protseConfig);
    IfxApApu_initConfig(&config->apuConfig);
}


void IfxXspi_initAp(Ifx_XSPI *xspi, IfxXspi_ApConfig *config)
{
    /* Initialize the PROTs */
    IfxApProt_init((Ifx_PROT_PROT *)&xspi->PROTE, &config->proteConfig);
    IfxApProt_init((Ifx_PROT_PROT *)&xspi->PROTSE, &config->protseConfig);

    /* Change the state to CONFIG, Configure APU and set PROT state back to RUN */
    /* Initialize the APU */
    IfxApProt_setState((Ifx_PROT_PROT *)&xspi->PROTSE, IfxApProt_State_config);
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&xspi->ACCEN, &config->apuConfig);
    IfxApProt_setState((Ifx_PROT_PROT *)&xspi->PROTSE, IfxApProt_State_run);
}


volatile Ifx_SRC_SRCR *IfxXspi_getSrcPointerError(Ifx_XSPI *xspi)
{
    return (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.XSPI.ERROR);
}


void IfxXspi_configureAccessToXspi(IfxApApu_ApuConfig *apConfig)
{
    IfxApApu_init((Ifx_ACCEN_ACCEN *)&MODULE_XSPI0.ACCEN, apConfig);
}


void IfxXspi_write8(Ifx_XSPI *xspi, uint8 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *txData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        txData->U = *data++;
        count--;
    }
}


void IfxXspi_write16(Ifx_XSPI *xspi, uint16 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *txData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        txData->U = *data++;
        count--;
    }
}


void IfxXspi_write32(Ifx_XSPI *xspi, uint32 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *txData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        txData->U = *data++;
        count--;
    }
}


void IfxXspi_read8(Ifx_XSPI *xspi, uint8 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *rxData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        *data++ = (uint8)rxData->U;
        count--;
    }
}


void IfxXspi_read16(Ifx_XSPI *xspi, uint16 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *rxData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        *data++ = (uint16)rxData->U;
        count--;
    }
}


void IfxXspi_read32(Ifx_XSPI *xspi, uint32 *data, uint32 count)
{
    volatile Ifx_XSPI_DR *rxData = (volatile Ifx_XSPI_DR *)&xspi->DR[0].U;

    while (count > 0)
    {
        *data++ = (uint32)rxData->U;
        count--;
    }
}


void IfxXspi_resetModule(Ifx_XSPI *xspi)
{
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(xspi->PROTE), IfxApProt_State_config);
#endif

    xspi->RST.CTRLA.B.KRST = 1;          /* Only if both Kernel reset bits are set a reset is executed */
    xspi->RST.CTRLB.B.KRST = 1;

    while (xspi->RST.STAT.B.KRST == 0)   /* Wait until reset is executed */
    {}

    xspi->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (xspi->RST.STAT.B.KRST == 1)
    {}

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(xspi->PROTE), IfxApProt_State_run);
#endif
}


void IfxXspi_getBaudrate(Ifx_XSPI *xspi, IfxXspi_BaudrateAndFrequencies *configStatus)
{
    uint32 fxspi = IfxClock_getXspiFrequency();

    if (xspi->CTRLR2.B.PORTSEL == 1)      /* HSFAST PADS (high speed) supports 200MHz SDR/DDR (with data strobe) & 133Mhz SDR (without data strobe) */
    {
        configStatus->ssiClk = fxspi * 2; /* frequency for fxspiX2 */
    }
    else                                  /* GPIO PADS (low speed) supports upto 25MHz SDR (no data strobe) */
    {
        configStatus->ssiClk = fxspi;     /* frequency for fxspisl */
    }

    configStatus->baudrate        = xspi->BAUDR.U;
    configStatus->sourceFrequency = fxspi;
    configStatus->sClkout         = (configStatus->ssiClk) / (configStatus->baudrate);
}

#endif /* !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
