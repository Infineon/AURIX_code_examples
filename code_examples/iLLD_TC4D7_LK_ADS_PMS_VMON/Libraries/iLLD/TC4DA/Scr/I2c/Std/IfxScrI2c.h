/**
 * \file IfxScrI2c.h
 * \brief SCR I2c basic functionality
 * \ingroup IfxLld_Scr
 *
 * \version iLLD-TC4-v2.2.0
 * \copyright Copyright (c) 2022 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such
 * terms of use are agreed, use of this file is subject to following:
 *
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or
 * organization obtaining a copy of the software and accompanying
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
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
 * \defgroup IfxLld_Scr_I2c I2C
 * \ingroup IfxLld_Scr
 * \defgroup IfxLld_Scr_I2c_Enumerations Enumerations
 * \ingroup IfxLld_Scr_I2c
 * \defgroup IfxLld_Scr_I2c_DataStructures Data structures
 * \ingroup IfxLld_Scr_I2c
 * \defgroup IfxLld_Scr_I2c_config I2c Configuration Functionality
 * \ingroup IfxLld_Scr_I2c
 * \defgroup IfxLld_Scr_I2c_init I2c Initialization Functionality
 * \ingroup IfxLld_Scr_I2c
 *
 */

#ifndef IFXSCRI2C_H
#define IFXSCRI2C_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScrI2c_cfg.h"
#include "Scu/Std/IfxScrScu.h"
#include "Port/Std/IfxScrPort.h"
#include "_Reg/IfxScr_bf.h"
#include "_Reg/IfxScr_reg.h"
#include "_Utilities/Ifx_Assert.h"
/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scr_I2c_Enumerations
 * \{ */

/** \brief Enumeration for I2C SCL inputs
 */
typedef enum
{
    IfxScrI2c_Scl_A = 0,        /**< \brief I2CSCLA is selected */
    IfxScrI2c_Scl_B = 1,        /**< \brief I2CSCLB is selected */
	IfxScrI2c_Scl_C = 2,        /**< \brief I2CSCLC is selected */
	IfxScrI2c_Scl_D = 3         /**< \brief I2CSCLD is selected */
}IfxScrI2c_Scl;

/** \brief Enumeration for I2C SDA inputs
 */
typedef enum
{
    IfxScrI2c_Sda_A = 0,        /**< \brief I2CSDAA is selected */
    IfxScrI2c_Sda_B = 1,        /**< \brief I2CSDAB is selected */
	IfxScrI2c_Sda_C = 2,        /**< \brief I2CSDAC is selected */
	IfxScrI2c_Sda_D = 3         /**< \brief I2CSDAD is selected */
}IfxScrI2c_Sda;

/** \brief Enumeration for I2C Baudrate Prescalar (I2C_BRCR.BRP: 4bit)
 */
typedef enum
{
    IfxScrI2c_Prescaler_0  = 0,                  /**< \brief Prescalar 0 */
    IfxScrI2c_Prescaler_1  = 1,                  /**< \brief Prescalar 1 */
    IfxScrI2c_Prescaler_2  = 2,                  /**< \brief Prescalar 2 */
    IfxScrI2c_Prescaler_3  = 3,                  /**< \brief Prescalar 3 */
    IfxScrI2c_Prescaler_4  = 4,                  /**< \brief Prescalar 4 */
    IfxScrI2c_Prescaler_5  = 5,                  /**< \brief Prescalar 5 */
    IfxScrI2c_Prescaler_6  = 6,                  /**< \brief Prescalar 6 */
    IfxScrI2c_Prescaler_7  = 7,                  /**< \brief Prescalar 7 */
    IfxScrI2c_Prescaler_8  = 8,                  /**< \brief Prescalar 8 */
    IfxScrI2c_Prescaler_9  = 9,                  /**< \brief Prescalar 9 */
    IfxScrI2c_Prescaler_10 = 10,                 /**< \brief Prescalar 10 */
    IfxScrI2c_Prescaler_11 = 11,                 /**< \brief Prescalar 11 */
    IfxScrI2c_Prescaler_12 = 12,                 /**< \brief Prescalar 12 */
    IfxScrI2c_Prescaler_13 = 13,                 /**< \brief Prescalar 13 */
    IfxScrI2c_Prescaler_14 = 14,                 /**< \brief Prescalar 14 */
    IfxScrI2c_Prescaler_15 = 15,                 /**< \brief Prescalar 15 */
}IfxScrI2c_Prescaler;

/** \brief Enumeration for I2C Baudrate Predivider (I2C_BRCR.PREDIV)
 */
typedef enum
{
    IfxScrI2c_PreDiv_1   = 0,                  /**< \brief Predivider factor of 1 is used */
    IfxScrI2c_PreDiv_2   = 1,                  /**< \brief Predivider factor of 2 is used */
    IfxScrI2c_PreDiv_4   = 2,                  /**< \brief Predivider factor of 4 is used */
    IfxScrI2c_PreDiv_8   = 3,                  /**< \brief Predivider factor of 8 is used */
    IfxScrI2c_PreDiv_16  = 4,                  /**< \brief Predivider factor of 16 is used */
    IfxScrI2c_PreDiv_32  = 5,                  /**< \brief Predivider factor of 32 is used */
    IfxScrI2c_PreDiv_64  = 6,                  /**< \brief Predivider factor of 64 is used */
    IfxScrI2c_PreDiv_128 = 7                   /**< \brief Predivider factor of 128 is used */
}IfxScrI2c_PreDiv;

/** \brief Enumeration for I2C Baudrate
 */
typedef enum
{
    IfxScrI2c_Baudrate_100khz    = 0,                   /**< \brief Baud rate 100Khz */
    IfxScrI2c_Baudrate_92_5khz   = 1,                   /**< \brief Baud rate 92.5Khz */
    IfxScrI2c_Baudrate_96_15hz   = 2,                   /**< \brief Baud rate 96.15Khz */
    IfxScrI2c_Baudrate_89_12khz  = 3,                   /**< \brief Baud rate 89.12Khz */
    IfxScrI2c_Baudrate_333_3khz  = 4,                   /**< \brief Baud rate 333.3Khz */
    IfxScrI2c_Baudrate_333khz    = 5,                   /**< \brief Baud rate 333Khz */
    IfxScrI2c_Baudrate_357_14khz = 6,                   /**< \brief Baud rate 357.14Khz */
    IfxScrI2c_Baudrate_384_16khz = 7                    /**< \brief Baud rate 384.16Khz */
}IfxScrI2c_Baudrate;

/** \brief Enumeration for I2C status code
 */
typedef enum
{
    IfxScrI2c_Status_BusError                        = 0,            /**< \brief Bus Error */
    IfxScrI2c_Status_startCondtx                     = 0x08,         /**< \brief Start condition transmitted */
    IfxScrI2c_Status_repeatedStartCondtx             = 0x10,         /**< \brief Repeated start condition transmitted */
    IfxScrI2c_Status_addrAndWriteBitTxAckRx          = 0x18,         /**< \brief Address and write bit transmitted, ACK received */
    IfxScrI2c_Status_addrAndWriteBitTxAckNotRx       = 0x20,         /**< \brief Address and write bit transmitted, ACK not received */
    IfxScrI2c_Status_dataTxMasterModeAckRx           = 0x28,         /**< \brief Data byte transmitted in master mode, ACK received */
    IfxScrI2c_Status_dataTxMasterModeAckNotRx        = 0x30,         /**< \brief Data byte transmitted in master mode, ACK not received */
    IfxScrI2c_Status_arbitLostAddrOrData             = 0x38,         /**< \brief Arbitration lost in address or data byte */
    IfxScrI2c_Status_addrAndReadBitTxAckRx           = 0x40,         /**< \brief Address and read bit transmitted, ACK received */
    IfxScrI2c_Status_addrAndReadBitTxAckNotRx        = 0x48,         /**< \brief Address and read bit transmitted, ACK not received */
    IfxScrI2c_Status_dataRxMasterModeAckTx           = 0x50,         /**< \brief Data byte received in master mode, ACK transmitted */
    IfxScrI2c_Status_dataRxMasterModeAckNotTx        = 0x58,         /**< \brief Data byte received in master mode, ACK not transmitted */
    IfxScrI2c_Status_slaveAddrAndWriteBitRxAckTx     = 0x60,         /**< \brief Slave address and write bit received, ACK transmitted */
    IfxScrI2c_Status_arbitLostInAddrAsMaster         = 0x68,         /**< \brief Arbitration lost in address as master, slave address and write bit received, ACK transmitted */
    IfxScrI2c_Status_genCallAddressRxAckTx           = 0x70,         /**< \brief General call address received, ACK transmitted */
    IfxScrI2c_Status_arbitLostGenCallAddressRxAckTx  = 0x78,         /**< \brief Arbitration lost in address as master, general call address received, ACK transmitted */
    IfxScrI2c_Status_dataRxAfterSlaveAddrRxAckTx     = 0x80,         /**< \brief Data byte received after slave address received, ACK transmitted */
    IfxScrI2c_Status_dataRxAfterSlaveAddrRxAckNotTx  = 0x88,         /**< \brief Data byte received after slave address received, ACK not transmitted */
    IfxScrI2c_Status_dataRxAfterGenCallAddRxAckTx    = 0x90,         /**< \brief Data byte received after general call address received, ACK transmitted */
    IfxScrI2c_Status_dataRxAfterGenCallAddRxAckNotTx = 0x98,         /**< \brief Data byte received after general call address received, ACK not transmitted */
    IfxScrI2c_Status_stopOrRepeatedStartRx           = 0xA0,         /**< \brief STOP or repeated START mode received in slave mode */
    IfxScrI2c_Status_slaveAndReadBitRxAckTx          = 0xA8,         /**< \brief Slave address and read bit received, ACK transmitted */
    IfxScrI2c_Status_arbitLostslaveAndReadBitRxAckTx = 0xB0,         /**< \brief Arbitration lost in address as master, slave address and read bit received, ACK transmitted */
    IfxScrI2c_Status_dataByteTxSlaveModeAckRx        = 0xB8,         /**< \brief Data byte transmitted in slave mode, ACK received */
    IfxScrI2c_Status_dataByteTxSlaveModeAckNotRx     = 0xC0,         /**< \brief Data byte transmitted in slave mode, ACK not received */
    IfxScrI2c_Status_lastByteTxSlaveModeAckRx        = 0xC8,         /**< \brief Last byte transmitted in slave mode, ACK received */
    IfxScrI2c_Status_SecAddrAndWriteTxAckRx          = 0xD0,         /**< \brief Second address byte and write bit transmitted, ACK received */
    IfxScrI2c_Status_SecAddrAndWriteTxAckNotRx       = 0xD8,         /**< \brief Second address byte and write bit transmitted, ACK not received */
    IfxScrI2c_Status_idleState                       = 0xF8          /**< \brief No relevant status information, IFLG = 0 */
}IfxScrI2c_Status;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scr_I2c_DataStructures
 * \{ */

/** \brief I2c baudrate configuration structure
 * NOTE:Baudrates are set from the entries of table baudrateLookup[4]
 * fscl = fpclk/((2^PREDIV) * (BRP + 1) * 10)
 */
typedef struct
{
    IfxScrI2c_PreDiv    predivider;    /**< \brief Predivider for baudrate generation */
    IfxScrI2c_Prescaler preScaler;     /**< \brief Prescalar for baudrate generation */
}IfxScrI2c_BaudrateConfig;

/** \brief I2c configuration structure
 */
typedef struct
{
    IfxScrI2c_BaudrateConfig baudRate;      /**< \brief Baudrate configuration. Refer baudrateLookup for pre-configured baudrates */
    IfxScrPort_PinConfig    *sclPinCfg;     /**< \brief Scl Pin configuration */
    IfxScrPort_PinConfig    *sdaPinCfg;     /**< \brief Sda Pin configuration */
    uint16                   deviceAddr;    /**< \brief Device Address 7bit/10bit. Required if I2c operates in slave mode */
    uint8                    sclSel;        /**< \brief Scl input selection. Options IfxScrI2c_Scl_A, IfxScrI2c_Scl_B */
    uint8                    sdaSel;        /**< \brief Sda input selection. Options IfxScrI2c_Sda_A, IfxScrI2c_Sda_B */
}IfxScrI2c_Config;

/** \} */

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

/*
 * \brief I2c baud rate table for standard baud rates
 * */

IFX_EXTERN IFX_CONST IfxScrI2c_BaudrateConfig i2cbaudrateLookup[];

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scr_I2c_config
 * \{ */

/** \brief API to enable/disable I2c
 * \param enable Set TRUE to enable FALSE to disable
 * \return None
 */
IFX_INLINE void IfxScrI2c_enable(boolean enable);

/** \brief API to enable/disable I2c interrupt
 * \param enable Set TRUE to enable FALSE to disable
 * \return None
 */
IFX_INLINE void IfxScrI2c_enableInterrupt(boolean enable);

/** \brief API to configure slave address
 * \param slaveAddr 7bit/10bit slave address
 * \return None
 */
IFX_INLINE void IfxScrI2c_configureSlaveAddress(uint16 slaveAddr);

/** \brief API to enable/disable general call address
 * \param enable Set TRUE to enable FALSE to disable
 * \return None
 */
IFX_INLINE void IfxScrI2c_enableGeneralCallAddress(boolean enable);

/** \brief API to trigger soft reset on the I2C
 * \return None
 */
IFX_INLINE void IfxScrI2c_reset(void);

/** \brief API to select I2c Clock line
 * \param sclLine scl input selection
 * \return None
 */
IFX_INLINE void IfxScrI2c_selectScl(IfxScrI2c_Scl sclLine);

/** \brief API to select I2c Data line
 * \param sdaLine sda input selection
 * \return None
 */
IFX_INLINE void IfxScrI2c_selectSda(IfxScrI2c_Sda sdaLine);

/** \brief API to get status code
 * \return Returns Status code of I2C
 */
IFX_INLINE IfxScrI2c_Status IfxScrI2c_getStatusCode(void);

/** \brief API to assert acknowledge if
 *  - Matching 7bit/10bit slave address received
 *  - General Call address
 *  - Data byte in master or slave mode
 * \return None
 */
IFX_INLINE void IfxScrI2c_assertAck(void);

/** \brief API to sent Nack when a data byte is received in master or slave mode
 * \return None
 */
IFX_INLINE void IfxScrI2c_assertNack(void);

/** \brief API to clear I2c interrupt
 * \return None
 */
IFX_INLINE void IfxScrI2c_clearInterrupt(void);

/** \brief API to check if interrupt occurred
 * \return None
 */
IFX_INLINE boolean IfxScrI2c_isInterruptOccurred(void);

/** \brief API to transmit stop condition.
 *  If the API is called when I2c is in slave mode, no STOP condition will be transmitted
 *  on the I2C bus but the I2C behaves as if a STOP condition has been received.
 * \return None
 */
IFX_INLINE void IfxScrI2c_transmitStop(void);

/** \brief API to transmit start condition.
 *  I2C will enter master mode and transmit a START condition once I2C bus is free.
 *  If the I2C already in master mode and one or more bytes have been transmitted,
 *  a repeated START condition will be transmitted.
 *  If the I2C is in slave mode, the I2C will complete the data transfer and enter
 *  master mode once the I2C bus has been released.
 * \return None
 */
IFX_INLINE void IfxScrI2c_transmitStart(void);

/** \brief API to execute address phase
 * \param readWrite set FALSE to to write to the slave and TRUE to read from the slave
 * \return None
 */
IFX_INLINE void IfxScrI2c_sendAddress(uint16 slaveAddress, boolean readWrite);

/** \} */

/** \addtogroup IfxLld_Scr_Wcan_init
 * \{ */
/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to configure the I2c with default values
 * \param i2cConfig I2C configuration structure
 * \return None
 */
IFX_EXTERN void IfxScrI2c_initConfig(IfxScrI2c_Config *i2cConfig);

/** \brief API to initialize I2c.
 * \param i2cConfig I2C configuration structure
 * \return None
 */
IFX_EXTERN void IfxScrI2c_init(IfxScrI2c_Config *i2cConfig);

/** \brief API to send data to slave.
 * \param txbuffer Pointer to transmit buffer
 * \param len length of buffer
 * \param slaveAddress slave address to which the data should be sent.
 * \return Returns I2c status
 */
IFX_EXTERN IfxScrI2c_Status IfxScrI2c_masterSendData(uint8 *txbuffer, uint16 len, uint16 slaveAddress);

/** \brief API to receive data from slave.
 * \param rxbuffer Buffer to store received data
 * \param len length of buffer
 * \return Returns status
 */
IFX_EXTERN IfxScrI2c_Status IfxScrI2c_masterReceiveData(uint8 *rxbuffer, uint16 len, uint16 slaveAddress);

/** \brief API to send data to master.
 * \param data Data to be sent to the master
 * \return Returns status
 */
IFX_EXTERN IfxScrI2c_Status IfxScrI2c_slaveSendData(uint8 *txBuffer, uint16 len);

/** \brief API to receive data from master.
 * \return Returns received data
 */
IFX_EXTERN IfxScrI2c_Status IfxScrI2c_slaveReceiveData(uint8 *rxBuffer, uint16 len);
/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxScrI2c_enable(boolean enable)
{
    SCR_I2C_CNTR.B.ENAB = (enable == TRUE) ? 1u : 0u;
}


IFX_INLINE void IfxScrI2c_enableInterrupt(boolean enable)
{
    SCR_I2C_CNTR.B.IEN = (enable == TRUE) ? 1 : 0;
}


IFX_INLINE void IfxScrI2c_configureSlaveAddress(uint16 slaveAddr)
{
    /* 7bit slave address */
    if (slaveAddr < IFXSCRI2C_MAX_7BITADDR)
    {
        SCR_I2C_ADDR.B.SLA = (uint8)slaveAddr;
    }
    else
    {
        SCR_I2C_ADDRX.B.SLAX = (uint8)slaveAddr;
        SCR_I2C_ADDR.B.SLA   = ((IFXSCRI2C_10BITADDR_FIXEDBITS << 2u) | ((slaveAddr >> 8u) & 0x3u));
    }
}


IFX_INLINE void IfxScrI2c_enableGeneralCallAddress(boolean enable)
{
    SCR_I2C_ADDR.B.GCE = (enable == TRUE) ? 1u : 0u;
}


IFX_INLINE void IfxScrI2c_reset(void)
{
    SCR_I2C_SRST.B.SRST = 1u;
}


IFX_INLINE void IfxScrI2c_selectScl(IfxScrI2c_Scl sclLine)
{
    Ifx_SCR_I2C_SRST srst;
    srst.U          = SCR_I2C_SRST.U;
    srst.B.SCLSEL_P = 1u;
    srst.B.SCLSEL   = sclLine;
    SCR_I2C_SRST.U  = srst.U;
}


IFX_INLINE void IfxScrI2c_selectSda(IfxScrI2c_Sda sdaLine)
{
    Ifx_SCR_I2C_SRST srst;
    srst.U          = SCR_I2C_SRST.U;
    srst.B.SDASEL_P = 1u;
    srst.B.SDASEL   = sdaLine;
    SCR_I2C_SRST.U  = srst.U;
}


IFX_INLINE IfxScrI2c_Status IfxScrI2c_getStatusCode(void)
{
    return (IfxScrI2c_Status)(SCR_I2C_STAT.U);
}


IFX_INLINE void IfxScrI2c_assertAck(void)
{
    SCR_I2C_CNTR.B.AAK = 1u;
}


IFX_INLINE void IfxScrI2c_assertNack(void)
{
    SCR_I2C_CNTR.B.AAK = 0u;
}


IFX_INLINE void IfxScrI2c_clearInterrupt(void)
{
    SCR_I2C_CNTR.B.IFLG = 0u;
}


IFX_INLINE boolean IfxScrI2c_isInterruptOccurred(void)
{
    return (boolean)(SCR_I2C_CNTR.B.IFLG);
}


IFX_INLINE void IfxScrI2c_transmitStop(void)
{
    SCR_I2C_CNTR.B.STP = 1u;
}


IFX_INLINE void IfxScrI2c_transmitStart(void)
{
    SCR_I2C_CNTR.B.STA = 1u;
}


IFX_INLINE void IfxScrI2c_sendAddress(uint16 slaveAddress, boolean readWrite)
{
    uint8 data = 0u;

    if (slaveAddress < IFXSCRI2C_MAX_7BITADDR)
    {
        data = (uint8)(slaveAddress << 1U);

        if (readWrite == FALSE)
        {
            data &= ~(1);          /* Slave address + r/nw bit */
        }
        else
        {
            data |= (1u << 0u);
        }

        SCR_I2C_DATA.U = data;
        /* Clear IFLG bit to continue transfer */
        IfxScrI2c_clearInterrupt();
    }
    else
    {
        /* For 10 bit slave : Tx fixed 5 bit 2 upper slave bits and R/W bit */
        data = ((IFXSCRI2C_10BITADDR_FIXEDBITS << 3u) | (((slaveAddress >> 8u) & 0x3u) << 1u));

        if (readWrite == FALSE)
        {
            data &= ~(1);          /* Slave address + r/nw bit */
        }
        else
        {
            data |= (1u << 0u);
        }

        SCR_I2C_DATA.U = data;
        /* Clear IFLG bit to continue transfer */
        IfxScrI2c_clearInterrupt();

        /* For 10 bit slave : Tx lower 8 bits */
        data           = (uint8)(slaveAddress);
        SCR_I2C_DATA.U = data;
        /* Clear IFLG bit to continue transfer */
        IfxScrI2c_clearInterrupt();
    }
}


#endif /* IFXSCRI2C_H */
