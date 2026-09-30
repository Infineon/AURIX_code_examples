/**
 * \file IfxScrUart.c
 * \brief SCR UART basic functionality
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Ifx_Cfg.h"
#if defined (__TASKING__)
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC45X)

#include "IfxScrUart.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

const IfxScrUart_UartBaudrateConfig presetBaudrateConfig[6] = {
    {IfxScrUart_BaudratePrescaler_none, 0xA,  IfxScrUart_BaudrateFractionalDivider_27},
    {IfxScrUart_BaudratePrescaler_none, 0x3E, IfxScrUart_BaudrateFractionalDivider_16},
    {IfxScrUart_BaudratePrescaler_none, 0x41, IfxScrUart_BaudrateFractionalDivider_3 },
    {IfxScrUart_BaudratePrescaler_2,    0x41, IfxScrUart_BaudrateFractionalDivider_3 },
    {IfxScrUart_BaudratePrescaler_4,    0x41, IfxScrUart_BaudrateFractionalDivider_3 },
    {IfxScrUart_BaudratePrescaler_8,    0x41, IfxScrUart_BaudrateFractionalDivider_3 },
};

void IfxScrUart_UartInitModuleConfig(IfxScrUart_UartConfig *uartConfig)
{
    uartConfig->mode                       = IfxScrUart_Mode_0;
    uartConfig->presetBaudrate             = IfxScrUart_UartPresetBaudrateConfig_4800;
    uartConfig->baudrateConfig             = presetBaudrateConfig[IfxScrUart_UartPresetBaudrateConfig_4800];
    uartConfig->enableDoubleMode2Frequency = FALSE;
    uartConfig->rxd                        = IfxScrUart_ReceiverInput_a;
}


void IfxScrUart_UartInitModule(IfxScrUart_UartConfig *uartConfig)
{
    IfxScrUart_setUartMode(uartConfig->mode);
    /*Disabling UART_BCON.R after writing to baudrate config registers/bitfields*/
    IfxScrUart_enableDisableBaudrateGenerator(Ifx_Functionality_disable);

    if ((uartConfig->mode == IfxScrUart_Mode_1) || (uartConfig->mode == IfxScrUart_Mode_3))
    {
        IfxScrUart_setBaudratePrescaler(uartConfig->baudrateConfig.prescaler);
        IfxScrUart_setBaudrateFractionalDivider(uartConfig->baudrateConfig.fracDiv);
        IfxScrUart_setReloadValue(uartConfig->baudrateConfig.reloadValue);
    }
    else if (uartConfig->mode == IfxScrUart_Mode_2)
    {
        IfxScrUart_doubleMode2Baudrate(uartConfig->enableDoubleMode2Frequency);
    }

    IfxScrUart_selectReceiverInput(uartConfig->rxd);
    //TODO:pin config(IOCR setting according to rxd selected) to be added.To be done after creating pinmaps

    /*Enabling UART_BCON.R after writing to baudrate config registers/bitfields*/
    IfxScrUart_enableDisableBaudrateGenerator(Ifx_Functionality_enable);
}


void IfxScrUart_UartWrite(uint16 *const memptr, const uint16 size)
{
    uint16 data, i;

    if (memptr != NULL_PTR)
    {
        for (i = 0; i < size; i++)
        {
            data = memptr[i];
            IfxScrUart_sendData(data);
        }
    }
}


void IfxScrUart_UartRead(uint16 *const memptr, const uint16 size)
{
    uint16 i;

    if (memptr != NULL_PTR)
    {
        for (i = 0; i < size; i++)
        {
            memptr[i] = IfxScrUart_receiveData();
        }
    }
}


void IfxScrUart_sendLinFrame(IfxScrUart_LinMasterMessage *linMessage)
{
    uint8  i       = 0;
    uint8 *dataPtr = linMessage->linDataPtr;
    /* LIN sync field */
    IfxScrUart_sendLinSyncField();

    /* LIN ID field */
    IfxScrUart_sendData(linMessage->linId);

    /* LIN data field */
    for (i = 0; i < linMessage->dataSizeinBytes; i++)
    {
        IfxScrUart_sendData(*dataPtr);
        dataPtr++;
    }

    /*LIN frame checksum*/
    IfxScrUart_sendData(linMessage->checksum);
}

#endif /* #if !defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
