/**
 * \file IfxI2c.c
 * \brief I2C  basic functionality
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

#include "IfxI2c.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxI2c_configureAsMaster(Ifx_I2C *i2c)
{
    // enter config Mode
    IfxI2c_stop(i2c);

    i2c->ADDRCFG.U      = 0;
    i2c->ADDRCFG.B.MnS  = 1; // master mode
    i2c->ADDRCFG.B.SONA = 0; // don't release the bus on NACK
    i2c->ADDRCFG.B.SOPE = 0; // after transfer go into master restart state
    i2c->ADDRCFG.B.TBAM = 0; // 7 bit address mode
    i2c->FIFOCFG.U      = 0;
    i2c->FIFOCFG.B.TXFC = 1; // FIFO as flow controller
    i2c->FIFOCFG.B.RXFC = 1; // FIFO as flow controller
    i2c->FIFOCFG.B.TXBS = 0; // Burst size 1 word
    i2c->FIFOCFG.B.RXBS = 0; // Burst size 1 word
    i2c->FIFOCFG.B.TXFA = 0; // fifo is byte aligned
    i2c->FIFOCFG.B.RXFA = 0; // fifo is byte aligned
}


void IfxI2c_disableModule(Ifx_I2C *i2c)
{
    uint16 pwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(pwd);

    i2c->CLC.B.DISR = 1;

    while (i2c->CLC.B.DISS == 0)
    {}

    IfxScuWdt_setCpuEndinit(pwd);
}


void IfxI2c_enableBurstDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getBurstDataTransferSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


void IfxI2c_enableErrorInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getErrorSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


void IfxI2c_enableLastBurstDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getLastBurstDataTransferSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


void IfxI2c_enableLastSingleDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getLastSingleDataTransferSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


void IfxI2c_enableModule(Ifx_I2C *i2c)
{
    uint16 pwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(pwd);
    i2c->CLC.B.DISR = 0U;

    while (i2c->CLC.B.DISS == 1U)
    {}

    i2c->CLC1.B.RMC = 1U;

    while (i2c->CLC1.B.RMC != 1U)
    {}

    i2c->CLC1.B.DISR = 0U;

    while (i2c->CLC1.B.DISS == 1U)
    {}

    // disable all interrupts
    i2c->ERRIRQSM.U = 0x00;
    i2c->PIRQSM.U   = 0x00;
    i2c->IMSC.U     = 0x00;

    IfxScuWdt_setCpuEndinit(pwd);
}


void IfxI2c_enableProtocolInterrupt(void *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getProtocolSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


void IfxI2c_enableSingleDataTransferInterrupt(Ifx_I2C *i2c, IfxSrc_Tos typeOfService, uint16 priority)
{
    volatile Ifx_SRC_SRCR *src;
    src = IfxI2c_getSingleDataTransferSrcPointer(i2c);
    IfxSrc_init(src, typeOfService, priority);
    IfxSrc_enable(src);
}


Ifx_I2C *IfxI2c_getAddress(IfxI2c_Index i2c)
{
    Ifx_I2C *module;

    if (i2c < IFXI2C_NUM_MODULES)
    {
        module = (Ifx_I2C *)IfxI2c_cfg_indexMap[i2c].module;
    }
    else
    {
        module = NULL_PTR;
    }

    return module;
}


float32 IfxI2c_getBaudrate(Ifx_I2C *i2c)
{
    uint8   inc     = i2c->FDIVCFG.B.INC;
    uint16  dec     = i2c->FDIVCFG.B.DEC;
    uint8   rmc     = i2c->CLC1.B.RMC;
    float32 fKernel = IfxScuCcu_getBaud1Frequency();

    return (fKernel / rmc) / ((2 * dec / inc) + 3);
}


IfxI2c_Index IfxI2c_getIndex(Ifx_I2C *i2c)
{
    uint32       index;
    IfxI2c_Index result;

    result = IfxI2c_Index_none;

    for (index = 0; index < IFXI2C_NUM_MODULES; index++)
    {
        if (IfxI2c_cfg_indexMap[index].module == i2c)
        {
            result = (IfxI2c_Index)IfxI2c_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxI2c_initSclSdaPin(const IfxI2c_Scl_InOut *scl, const IfxI2c_Sda_InOut *sda, IfxPort_PadDriver padDriver)
{
    IfxPort_OutputMode mode = (IfxPort_OutputMode)IfxPort_Mode_outputOpenDrainGeneral;
    IfxPort_setPinModeOutput(scl->pin.port, scl->pin.pinIndex, mode, scl->outSelect);
    IfxPort_setPinModeOutput(sda->pin.port, sda->pin.pinIndex, mode, sda->outSelect);
    IfxPort_setPinPadDriver(scl->pin.port, scl->pin.pinIndex, padDriver);
    IfxPort_setPinPadDriver(sda->pin.port, sda->pin.pinIndex, padDriver);
    IfxI2c_setPinSelection(scl->module, (IfxI2c_PinSelect)scl->inSelect); // note: uses the same PISEL register like SDA
}


void IfxI2c_releaseBus(Ifx_I2C *i2c)
{
    // only set the set end of transmisson bit if bus is not free
    if (i2c->BUSSTAT.B.BS != IfxI2c_BusStatus_idle)
    {
        i2c->ENDDCTRL.B.SETEND = 1;

        // wait until bus is free
        while (IfxI2c_getProtocolInterruptSourceStatus(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd) == FALSE)
        {}

        IfxI2c_clearProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_transmissionEnd);
    }
}


void IfxI2c_resetFifo(Ifx_I2C *i2c)
{
    /* reset FIFO */
    i2c->FIFOCFG.U      = 0x0;
    i2c->FIFOCFG.B.TXFC = 0U;
    i2c->FIFOCFG.B.RXFC = 0U;
    i2c->FIFOCFG.B.TXBS = 0U;
    i2c->FIFOCFG.B.RXBS = 0U;
    i2c->FIFOCFG.B.TXFA = 0U;
    i2c->FIFOCFG.B.RXFA = 0U;
}


void IfxI2c_resetModule(Ifx_I2C *i2c)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    i2c->KRST0.B.RST = 1;           /* Only if both Kernel reset bits are set a reset is executed */
    i2c->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    while (0 == i2c->KRST0.B.RSTSTAT)   /* Wait until reset is executed */

    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    i2c->KRSTCLR.B.CLR = 1;         /* Clear Kernel reset status bit */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxI2c_setBaudrate(Ifx_I2C *i2c, float32 baudrate)
{
    float32 fKernel = IfxScuCcu_getBaud1Frequency();
    uint8   rmc     = i2c->CLC1.B.RMC;
    float32 dec;
    dec = (((fKernel / rmc) / baudrate) - 3) / 2;     // always: Inc = 1

    // dec:inc must be at least 6
    if (dec < 6)
    {
        dec = 6;
    }
    else if (dec > (1 << IFX_I2C_FDIVCFG_DEC_LEN) - 1)
    {
        dec = (1 << IFX_I2C_FDIVCFG_DEC_LEN) - 1;
    }

    uint16 pwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(pwd);
    /* Baudrate configuration */
    i2c->FDIVCFG.B.INC           = 1;
    i2c->FDIVCFG.B.DEC           = (uint16)(dec + 0.5);
    i2c->TIMCFG.B.SDA_DEL_HD_DAT = 0x3F;
    i2c->TIMCFG.B.FS_SCL_LOW     = 1;
    i2c->TIMCFG.B.EN_SCL_LOW_LEN = 1;
    i2c->TIMCFG.B.SCL_LOW_LEN    = 0x20;

    IfxScuWdt_setCpuEndinit(pwd);
}
