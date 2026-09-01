/**
 * \file IfxI2c_I2c.c
 * \brief I2C I2C details
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

#include "IfxI2c_I2c.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

float32 IfxI2c_I2c_getBaudrate(IfxI2c_I2c *i2c)
{
    return IfxI2c_getBaudrate(i2c->i2c);
}


void IfxI2c_I2c_initConfig(IfxI2c_I2c_Config *config, Ifx_I2C *i2c)
{
    config->i2c                                            = i2c;
    config->baudrate                                       = 400000;
    config->pins                                           = NULL_PTR;
    config->mode                                           = IfxI2c_Mode_StandardAndFast;
    config->peripheralMode                                 = IfxI2c_MasterNotSlave_master;

    config->addrFifoCfg.addressConfig.slaveAddress         = 0;
    config->addrFifoCfg.addressConfig.addressMode          = IfxI2c_AddressMode_7Bit;
    config->addrFifoCfg.addressConfig.generalCallEnable    = 0;
    config->addrFifoCfg.addressConfig.masterCodeEnable     = 0;
    config->addrFifoCfg.addressConfig.stopOnNotAcknowledge = 0;
    config->addrFifoCfg.addressConfig.stopOnPacketEnd      = 0;

    config->addrFifoCfg.fifoConfig.rxBurstSize             = IfxI2c_RxBurstSize_1Word;
    config->addrFifoCfg.fifoConfig.txBurstSize             = IfxI2c_TxBurstSize_1Word;
    config->addrFifoCfg.fifoConfig.rxFifoAlignment         = IfxI2c_RxFifoAlignment_byte;
    config->addrFifoCfg.fifoConfig.txFifoAlignment         = IfxI2c_TxFifoAlignment_byte;
    config->addrFifoCfg.fifoConfig.rxFifoFlowControl       = IfxI2c_RxFifoFlowControl_enable;
    config->addrFifoCfg.fifoConfig.txFifoFlowControl       = IfxI2c_TxFifoFlowControl_enable;
    config->addrFifoCfg.fifoConfig.clearRequestBehavior    = 0;
}


void IfxI2c_I2c_initDevice(IfxI2c_I2c_Device *i2cDevice, const IfxI2c_I2c_deviceConfig *i2cDeviceConfig)
{
    i2cDevice->i2c                 = i2cDeviceConfig->i2c;
    i2cDevice->deviceAddress       = i2cDeviceConfig->deviceAddress;
    i2cDevice->addressMode         = i2cDeviceConfig->addressMode;
    i2cDevice->speedMode           = i2cDeviceConfig->speedMode;
    i2cDevice->enableRepeatedStart = i2cDeviceConfig->enableRepeatedStart;
}


void IfxI2c_I2c_initDeviceConfig(IfxI2c_I2c_deviceConfig *i2cDeviceConfig, IfxI2c_I2c *i2c)
{
    i2cDeviceConfig->i2c                 = i2c;
    i2cDeviceConfig->deviceAddress       = 0xff;
    i2cDeviceConfig->addressMode         = IfxI2c_AddressMode_7Bit;
    i2cDeviceConfig->speedMode           = IfxI2c_Mode_StandardAndFast;
    i2cDeviceConfig->enableRepeatedStart = FALSE;
}


void IfxI2c_I2c_initModule(IfxI2c_I2c *i2c, const IfxI2c_I2c_Config *config)
{
    IfxI2c_Config addressConfiglocal = config->addrFifoCfg;
    Ifx_I2C      *i2cSFR             = config->i2c;
    i2c->i2c = i2cSFR;

    /* Enable the I2C module */
    IfxI2c_enableModule(i2cSFR);

    /* Stop the I2C module */
    IfxI2c_stop(i2cSFR);        
    
    /* Enter config mode */
    IfxI2c_configureAsMaster(i2cSFR);

    if (config->peripheralMode == IfxI2c_MasterNotSlave_slave)
    {
    	/* Configure peripheral as slave */
        IfxI2c_configureAsSlave(i2cSFR);
    }

    if (config->mode == IfxI2c_Mode_HighSpeed)
    {
        addressConfiglocal.addressConfig.masterCodeEnable = TRUE;
    }

    /* Configure address fifo */
    IfxI2c_configureAddrFifo(i2cSFR, &addressConfiglocal);

    /* In high speed mode the baud rate must be higher then 400kHz */
    IfxI2c_setBaudrate(i2cSFR, config->baudrate); 

    if (config->pins != NULL_PTR)
    {
    	/* Initialise the I2C SCL and SDA pins with the specified SCL, SDA and Pad Driver configuration */
        IfxI2c_initSclSdaPin(config->pins->scl, config->pins->sda, config->pins->padDriver);
    }

    /* To see protocol interrupt in register RIS enable the corresponding sources */
    IfxI2c_enableProtocolInterruptSource(i2cSFR, IfxI2c_ProtocolInterruptSource_arbitrationLost);
    IfxI2c_enableProtocolInterruptSource(i2cSFR, IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived);
    IfxI2c_enableProtocolInterruptSource(i2cSFR, IfxI2c_ProtocolInterruptSource_transmissionEnd);
    IfxI2c_enableProtocolInterruptSource(i2cSFR, IfxI2c_ProtocolInterruptSource_receiveMode);
    /* To see error interrupt in register RIS enable the corresponding sources */
    IfxI2c_enableErrorInterruptSource(i2cSFR, IfxI2c_ErrorInterruptSource_rxFifoUnderflow);
    IfxI2c_enableErrorInterruptSource(i2cSFR, IfxI2c_ErrorInterruptSource_rxFifoOverflow);
    IfxI2c_enableErrorInterruptSource(i2cSFR, IfxI2c_ErrorInterruptSource_txFifoUnderflow);
    IfxI2c_enableErrorInterruptSource(i2cSFR, IfxI2c_ErrorInterruptSource_txFifoOverflow);

    /* Start the I2C module */
    IfxI2c_run(i2cSFR);

    /* Initialise the I2C with the current Baud rate, Bus status, and set status to OK */
    i2c->baudrate  = IfxI2c_getBaudrate(i2cSFR);
    i2c->busStatus = IfxI2c_getBusStatus(i2cSFR);
    i2c->status    = IfxI2c_I2c_Status_ok;
}


IfxI2c_I2c_Status IfxI2c_I2c_read(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size)
{
    return (IfxI2c_I2c_Status)IfxI2c_read((IfxI2c_I2cStdDevice *)i2cDevice, data, size);
}


IfxI2c_I2c_Status IfxI2c_I2c_write(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size)
{
    return (IfxI2c_I2c_Status)IfxI2c_write((IfxI2c_I2cStdDevice *)i2cDevice, data, size);
}
