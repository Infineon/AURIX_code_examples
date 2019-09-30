/**
 * \file IfxI2c_I2c.c
 * \brief I2C I2C details
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxI2c_I2c.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxI2c_I2c_initConfig(IfxI2c_I2c_Config *config, Ifx_I2C *i2c)
{
    config->i2c      = i2c;
    config->baudrate = 400000;
    config->pins     = NULL_PTR;
}


void IfxI2c_I2c_initDevice(IfxI2c_I2c_Device *i2cDevice, const IfxI2c_I2c_deviceConfig *i2cDeviceConfig)
{
    i2cDevice->i2c           = i2cDeviceConfig->i2c;
    i2cDevice->deviceAddress = i2cDeviceConfig->deviceAddress;
}


void IfxI2c_I2c_initDeviceConfig(IfxI2c_I2c_deviceConfig *i2cDeviceConfig, IfxI2c_I2c *i2c)
{
    i2cDeviceConfig->i2c           = i2c;
    i2cDeviceConfig->deviceAddress = 0xff;
}


void IfxI2c_I2c_initModule(IfxI2c_I2c *i2c, const IfxI2c_I2c_Config *config)
{
    Ifx_I2C *i2cSFR = config->i2c;
    i2c->i2c = i2cSFR;

    IfxI2c_enableModule(i2cSFR);
    IfxI2c_stop(i2cSFR);                                                                   // enter config Mode
    IfxI2c_configureAsMaster(i2cSFR);
    IfxI2c_setBaudrate(i2cSFR, config->baudrate);
    IfxI2c_initSclSdaPin(config->pins->scl, config->pins->sda, config->pins->padDriver);
    IfxI2c_run(i2cSFR);
    i2c->baudrate  = IfxI2c_getBaudrate(i2cSFR);
    i2c->busStatus = IfxI2c_getBusStatus(i2cSFR);
    i2c->status    = IfxI2c_I2c_Status_ok;
}


IfxI2c_I2c_Status IfxI2c_I2c_read(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size)
{
    IfxI2c_I2c_Status status         = IfxI2c_I2c_Status_ok;
    Ifx_I2C          *i2c            = i2cDevice->i2c->i2c;
    uint32            packet;
    uint8             slAddr         = i2cDevice->deviceAddress;

    uint32            rxData         = 0;
    sint32            bytesToReceive = size;
    uint8            *bytePtrRxData  = (uint8 *)&rxData;
    uint32            bytes;

    // bus free?
    if (IfxI2c_busIsFree(i2c) == FALSE)
    {
        status                    = IfxI2c_I2c_Status_busNotFree;
        i2cDevice->i2c->busStatus = IfxI2c_getBusStatus(i2c);
        i2cDevice->i2c->status    = status;
        return status;
    }

    IfxI2c_clearAllProtocolInterruptSources(i2c);
    IfxI2c_clearAllErrorInterruptSources(i2c);

    // send device address with RnW bit set
    packet = slAddr | 1;                    // set read bit
    IfxI2c_setTransmitPacketSize(i2c, 1);   // send slave address packet with RnW = 1
    IfxI2c_setReceivePacketSize(i2c, size); // set number of bytes to reveive
    IfxI2c_writeFifo(i2c, packet);
    IfxI2c_clearLastSingleRequestInterruptSource(i2c);
    IfxI2c_clearSingleRequestInterruptSource(i2c);
    IfxI2c_clearLastBurstRequestInterruptSource(i2c);
    IfxI2c_clearBurstRequestInterruptSource(i2c);

    // Poll until aribtration lost, nack, or rx mode flag is reset, or error is gone
    while ((i2c->PIRQSS.U & ((1 << IFX_I2C_PIRQSS_AL_OFF) | (1 << IFX_I2C_PIRQSS_NACK_OFF) | (1 << IFX_I2C_PIRQSS_RX_OFF) || i2c->ERRIRQSS.U)))
    {}

    // check status
    if (i2c->ERRIRQSS.U)
    {
        IfxI2c_clearAllErrorInterruptSources(i2c);
        status = IfxI2c_I2c_Status_error;
    }
    else if (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_arbitrationLost) == TRUE)
    {
        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_arbitrationLost);
        status = IfxI2c_I2c_Status_al;
    }
    else if (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived) == TRUE)
    {
        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived);
        status = IfxI2c_I2c_Status_nak;
    }
    else if (size > 0)                                       // required to poll for nak

    {
        if (size > 32)                                       // if fifo is too small => disable global interrupts!
        {           // assumes TC is faster than i2c and therefor a fifo overflow is not possible
            boolean intEnabled = IfxCpu_disableInterrupts(); // disable global interrupts to prevent fifo overflow
            uint32  i;

            for (i = 0; i < size; i += 4)
            {
                if (bytesToReceive >= 4)
                {
                    bytes           = 4;
                    bytesToReceive -= 4;
                }
                else
                {
                    bytes          = bytesToReceive;
                    bytesToReceive = 0;
                }

                uint32 ris;

                while (!(ris = i2c->RIS.U)) // wait for fifo request or error

                {}

                // check request flags
                if (ris & ((1 << IFX_I2C_RIS_LSREQ_INT_OFF) | (1 << IFX_I2C_RIS_SREQ_INT_OFF) | (1 << IFX_I2C_RIS_LBREQ_INT_OFF) | (1 << IFX_I2C_RIS_BREQ_INT_OFF)))
                {
                    rxData = i2c->RXD.U;
                    uint32 k;

                    for (k = 0; k < bytes; k++)
                    {
                        data[i + k] = bytePtrRxData[k];
                    }

                    IfxI2c_clearLastSingleRequestInterruptSource(i2c);
                    IfxI2c_clearSingleRequestInterruptSource(i2c);
                    IfxI2c_clearLastBurstRequestInterruptSource(i2c);
                    IfxI2c_clearBurstRequestInterruptSource(i2c);
                }

                // check errors
                if (ris & (1 << IFX_I2C_RIS_I2C_P_INT_OFF)) // check protocol flags
                {
                    IfxI2c_clearAllProtocolInterruptSources(i2c);
                    status = IfxI2c_I2c_Status_error;
                    break;
                }

                if (ris & (1 << IFX_I2C_RIS_I2C_ERR_INT_OFF)) // error flags
                {
                    IfxI2c_clearAllErrorInterruptSources(i2c);
                    status = IfxI2c_I2c_Status_error;
                    break;
                }
            }

            IfxCpu_restoreInterrupts(intEnabled); // (re-) enable global interrupts

            // TX_END: transmission finished
            while (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd) == FALSE)
            {}

            IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd);
        }
        else
        {
            // wait until all bytes are received
            while (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd) == FALSE)
            {}

            IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd);

            // check errors
            uint32 ris;
            ris = i2c->RIS.U;

            if (ris & (1 << IFX_I2C_RIS_I2C_P_INT_OFF)) // check protocol flags
            {
                IfxI2c_clearAllProtocolInterruptSources(i2c);
                status = IfxI2c_I2c_Status_error;
            }

            if (ris & (1 << IFX_I2C_RIS_I2C_ERR_INT_OFF)) // error flags
            {
                IfxI2c_clearAllErrorInterruptSources(i2c);
                status = IfxI2c_I2c_Status_error;
            }

            if (status != IfxI2c_I2c_Status_error)
            {
                // read fifo
                uint32 i;

                for (i = 0; i < size; i += 4)
                {
                    if (bytesToReceive >= 4)
                    {
                        bytes           = 4;
                        bytesToReceive -= 4;
                    }
                    else
                    {
                        bytes          = bytesToReceive;
                        bytesToReceive = 0;
                    }

                    uint32 k;
                    rxData = i2c->RXD.U;
                    IfxI2c_clearLastSingleRequestInterruptSource(i2c);
                    IfxI2c_clearSingleRequestInterruptSource(i2c);
                    IfxI2c_clearLastBurstRequestInterruptSource(i2c);
                    IfxI2c_clearBurstRequestInterruptSource(i2c);

                    for (k = 0; k < bytes; k++)
                    {
                        data[i + k] = bytePtrRxData[k];
                    }
                }
            }
        }

        // finally check errors
        uint32 ris;
        ris = i2c->RIS.U;

        if (ris & (1 << IFX_I2C_RIS_I2C_P_INT_OFF)) // check protocol flags
        {
            IfxI2c_clearAllProtocolInterruptSources(i2c);
            status = IfxI2c_I2c_Status_error;
        }

        if (ris & (1 << IFX_I2C_RIS_I2C_ERR_INT_OFF)) // error flags
        {
            IfxI2c_clearAllErrorInterruptSources(i2c);
            status = IfxI2c_I2c_Status_error;
        }
    }

    IfxI2c_releaseBus(i2c);
    i2cDevice->i2c->busStatus = IfxI2c_getBusStatus(i2c);
    i2cDevice->i2c->status    = status;
    return status;
}


IfxI2c_I2c_Status IfxI2c_I2c_write(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size)
{
    IfxI2c_I2c_Status status        = IfxI2c_I2c_Status_ok;
    Ifx_I2C          *i2c           = i2cDevice->i2c->i2c;
    uint8             slAddr        = i2cDevice->deviceAddress;
    uint32            packet;
    sint32            bytesToSend   = size + 1; // +1 slave device address
    uint32            bytes;
    uint8            *bytePtrPacket = (uint8 *)&packet;

    if (IfxI2c_busIsFree(i2c) == FALSE)
    {
        status                    = IfxI2c_I2c_Status_busNotFree;
        i2cDevice->i2c->busStatus = IfxI2c_getBusStatus(i2c);
        i2cDevice->i2c->status    = status;
        return status;
    }

    // build one packet containing the slave address

    IfxI2c_clearAllProtocolInterruptSources(i2c);
    IfxI2c_clearAllErrorInterruptSources(i2c);

    // try to seize control, if not return
    packet = slAddr;
    // try to seize control, if not return
    IfxI2c_setTransmitPacketSize(i2c, 1);
    IfxI2c_writeFifo(i2c, packet);
    IfxI2c_clearLastSingleRequestInterruptSource(i2c);
    IfxI2c_clearSingleRequestInterruptSource(i2c);
    IfxI2c_clearLastBurstRequestInterruptSource(i2c);
    IfxI2c_clearBurstRequestInterruptSource(i2c);

    // wait until packet is sent
    while (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd) == FALSE)
    {}

    IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd);

    // check status
    if (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_arbitrationLost) == TRUE)
    {
        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_arbitrationLost);
        status = IfxI2c_I2c_Status_al;
    }
    else if (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived) == TRUE)
    {
        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_notAcknowledgeReceived);
        status = IfxI2c_I2c_Status_nak;
    }
    else if (size > 0) // write i2c device

    {
        uint32  i, j = 0;

        // assumes TC is faster then i2c and therefor a fifo underflow is not possible
        boolean intEnabled = IfxCpu_disableInterrupts(); // disable global interrupts to prevent FIFO underflow
        IfxI2c_setTransmitPacketSize(i2c, size + 1);

        for (i = 0; i < size + 1; i += 4)
        {
            if (bytesToSend >= 4)
            {
                bytes        = 4;
                bytesToSend -= 4;
            }
            else
            {
                bytes       = bytesToSend;
                bytesToSend = 0;
            }

            packet = 0;

            for (j = 0; j < bytes; j++)
            {
                if ((i == 0) && (j == 0))
                {
                    bytePtrPacket[j] = (uint8)slAddr;
                }

                else
                {
                    bytePtrPacket[j] = (uint8)data[i + j - 1];
                }
            }

            do
            {
                // check errors
                uint32 ris;
                ris = i2c->RIS.U;

                if (ris & (1 << IFX_I2C_RIS_I2C_P_INT_OFF)) // check protocol flags
                {
                    IfxI2c_clearAllProtocolInterruptSources(i2c);
                    status = IfxI2c_I2c_Status_error;
                }

                if (ris & (1 << IFX_I2C_RIS_I2C_ERR_INT_OFF)) // error flags
                {
                    IfxI2c_clearAllErrorInterruptSources(i2c);
                    status = IfxI2c_I2c_Status_error;
                }
            } while (i2c->FFSSTAT.B.FFS == 8 && status != IfxI2c_I2c_Status_error); // wait to prevent FIFO overflow

            if (status == IfxI2c_I2c_Status_error)
            {
                break;
            }

            IfxI2c_writeFifo(i2c, packet);
            IfxI2c_clearLastSingleRequestInterruptSource(i2c);
            IfxI2c_clearSingleRequestInterruptSource(i2c);
            IfxI2c_clearLastBurstRequestInterruptSource(i2c);
            IfxI2c_clearBurstRequestInterruptSource(i2c);
        }

        IfxCpu_restoreInterrupts(intEnabled); // (re-) enable global interrupts

        // wait until all bytes are sent
        while (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd) == FALSE)
        {}

        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd);

        // finally check errors
        uint32 ris;
        ris = i2c->RIS.U;

        if (ris & (1 << IFX_I2C_RIS_I2C_P_INT_OFF)) // check protocol flags
        {
            IfxI2c_clearAllProtocolInterruptSources(i2c);
            status = IfxI2c_I2c_Status_error;
        }

        if (ris & (1 << IFX_I2C_RIS_I2C_ERR_INT_OFF)) // error flags
        {
            IfxI2c_clearAllErrorInterruptSources(i2c);
            status = IfxI2c_I2c_Status_error;
        }
    }

    IfxI2c_releaseBus(i2c);
    i2cDevice->i2c->busStatus = IfxI2c_getBusStatus(i2c);
    i2cDevice->i2c->status    = status;
    return status;
}
