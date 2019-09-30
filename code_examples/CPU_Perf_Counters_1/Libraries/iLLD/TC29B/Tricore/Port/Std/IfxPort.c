/**
 * \file IfxPort.c
 * \brief PORT  basic functionality
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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

#include "IfxPort.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxPort_disableEmergencyStop(Ifx_P *port, uint8 pinIndex)
{
    sint32  portIndex;
    boolean result = FALSE;

    for (portIndex = 0; portIndex < IFXPORT_NUM_MODULES; portIndex++)
    {
        if (port == IfxPort_cfg_esrMasks[portIndex].port)
        {
            if ((1U << pinIndex) & IfxPort_cfg_esrMasks[portIndex].masks)
            {
                IfxPort_resetESR(port, pinIndex);
                result = TRUE;
            }

            break;
        }
    }

    return result;
}


boolean IfxPort_enableEmergencyStop(Ifx_P *port, uint8 pinIndex)
{
    sint32  portIndex;
    boolean result = FALSE;

    for (portIndex = 0; portIndex < IFXPORT_NUM_MODULES; portIndex++)
    {
        if (port == IfxPort_cfg_esrMasks[portIndex].port)
        {
            if ((1U << pinIndex) & IfxPort_cfg_esrMasks[portIndex].masks)
            {
                IfxPort_setESR(port, pinIndex);
                result = TRUE;
            }
        }
    }

    return result;
}


Ifx_P *IfxPort_getAddress(IfxPort_Index port)
{
    Ifx_P *module = NULL_PTR;
    uint8  i      = 0;

    while ((i < IFXPORT_NUM_MODULES) && (module == NULL_PTR))
    {
        if (IfxPort_cfg_indexMap[i].index == port)
        {
            module = IfxPort_cfg_indexMap[i].module;
        }

        i++;
    }

    return module;
}


IfxPort_Index IfxPort_getIndex(Ifx_P *port)
{
    uint32        index;
    IfxPort_Index result;

    result = IfxPort_Index_none;

    for (index = 0; index < IFXPORT_NUM_MODULES; index++)
    {
        if (IfxPort_cfg_indexMap[index].module == port)
        {
            result = (IfxPort_Index)IfxPort_cfg_indexMap[index].index;
            break;
        }
    }

    return result;
}


void IfxPort_resetESR(Ifx_P *port, uint8 pinIndex)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    __ldmst(&port->ESR.U, 1U << pinIndex, 0);
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setESR(Ifx_P *port, uint8 pinIndex)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    __ldmst(&port->ESR.U, 1U << pinIndex, 1U << pinIndex);
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setGroupModeInput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_InputMode mode)
{
    uint32 i;
    uint32 iocrVal[4];
    uint32 iocrMask[4];

    /* initialise */
    for (i = 0; i < 4; i++)
    {
        iocrVal[i]  = 0;
        iocrMask[i] = 0;
    }

    /* calculate IOCRx values and masks */
    uint32 imask = (uint32)mask << pinIndex;

    for (i = pinIndex; i < 16; i++)
    {
        if ((imask & (1U << i)) != 0)
        {
            uint32 index = i / 4;
            uint32 shift = (i & 0x3U) * 8;
            iocrMask[index] |= (0x1FU << 3) << shift;
            iocrVal[index]  |= (mode) << shift;
        }
    }

    /* write IOCRx */
    for (i = 0; i < 4; i++)
    {
        if (iocrMask[i] != 0)
        {
            __ldmst(&((&(port->IOCR0.U))[i]), iocrMask[i], iocrVal[i]);
        }
    }
}


void IfxPort_setGroupModeOutput(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_OutputMode mode, IfxPort_OutputIdx index)
{
    uint32 i;
    uint32 iocrVal[4];
    uint32 iocrMask[4];

    /* initialise */
    for (i = 0; i < 4; i++)
    {
        iocrVal[i]  = 0;
        iocrMask[i] = 0;
    }

    /* calculate IOCRx values and masks */
    uint32 imask = (uint32)mask << pinIndex;

    for (i = pinIndex; i < 16; i++)
    {
        if ((imask & (1U << i)) != 0)
        {
            uint32 index = i / 4;
            uint32 shift = (i & 0x3U) * 8;
            iocrMask[index] |= (0x1FU << 3) << shift;
            iocrVal[index]  |= (mode | index) << shift;
        }
    }

    /* write IOCRx */
    for (i = 0; i < 4; i++)
    {
        if (iocrMask[i] != 0)
        {
            __ldmst(&((&(port->IOCR0.U))[i]), iocrMask[i], iocrVal[i]);
        }
    }
}


void IfxPort_setGroupPadDriver(Ifx_P *port, uint8 pinIndex, uint16 mask, IfxPort_PadDriver padDriver)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    {
        uint32 i;
        uint32 pdrVal[2];
        uint32 pdrMask[2];

        /* initialise */
        for (i = 0; i < 2; i++)
        {
            pdrVal[i]  = 0;
            pdrMask[i] = 0;
        }

        /* calculate PDRx values and masks */
        uint32 imask = (uint32)mask << pinIndex;

        for (i = pinIndex; i < 16; i++)
        {
            if ((imask & (1U << i)) != 0)
            {
                uint32 index = i / 8;
                uint32 shift = (i & 0x7U) * 4;
                pdrMask[index] |= (0xFUL << shift);
                pdrVal[index]  |= (padDriver << shift);
            }
        }

        /* write PDRx */
        for (i = 0; i < 2; i++)
        {
            if (pdrMask[i] != 0)
            {
                __ldmst(&((&(port->PDR0.U))[i]), pdrMask[i], pdrVal[i]);
            }
        }
    }
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinMode(Ifx_P *port, uint8 pinIndex, IfxPort_Mode mode)
{
    volatile Ifx_P_IOCR0 *iocr      = &(port->IOCR0);
    uint8                 iocrIndex = (pinIndex / 4);
    uint8                 shift     = (pinIndex & 0x3U) * 8;

    if (port == &MODULE_P40)
    {
        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
        IfxScuWdt_clearCpuEndinit(passwd);
        port->PDISC.U &= ~(1 << pinIndex);
        IfxScuWdt_setCpuEndinit(passwd);
    }

    __ldmst(&iocr[iocrIndex].U, (0xFFUL << shift), (mode << shift));
}


void IfxPort_setPinModeLvdsHigh(Ifx_P *port, uint8 pinIndex, IfxPort_Mode mode, IfxPort_ControlledBy enablePortControlled)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);

    if (mode < IfxPort_Mode_outputPushPullGeneral)
    {
        if (pinIndex < 2)
        {
            port->LPCR0.B_P21.RDIS_CTRL = enablePortControlled;
            port->LPCR0.B_P21.RX_DIS    = 0;
        }
        else
        {
            port->LPCR1.B_P21.RDIS_CTRL = enablePortControlled;
            port->LPCR1.B_P21.RX_DIS    = 0;
        }
    }
    else
    {
        port->LPCR2.B_P21.TDIS_CTRL = enablePortControlled;
        port->LPCR2.B_P21.TX_DIS    = 0;
        port->LPCR2.B_P21.TX_PD     = 0;
    }

    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinModeLvdsMedium(Ifx_P *port, uint8 pinIndex, IfxPort_PadDriver lvdsPadDriver, IfxPort_PadSupply padSupply)
{
    uint32                pdrOffset  = (pinIndex / 8);
    uint32                shift      = ((pinIndex / 2) * 8);
    uint32                lpcrOffset = (pinIndex / 2);
    volatile Ifx_P_PDR0  *pdr        = &(port->PDR0);
    volatile Ifx_P_LPCR0 *lpcr       = &(port->LPCR0);
    uint16                passwd     = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    {
        pdr[pdrOffset].U       = (lvdsPadDriver << shift); /* configuring LVDS mode */
        lpcr[lpcrOffset].B.PS1 = padSupply;
    }
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinPadDriver(Ifx_P *port, uint8 pinIndex, IfxPort_PadDriver padDriver)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    {
        volatile uint32 *pdr      = (volatile uint32 *)&(port->PDR0.U);
        uint8            pdrIndex = (pinIndex / 8);
        uint8            shift    = (pinIndex & 0x7U) * 4;
        __ldmst(&(pdr[pdrIndex]), (0xFUL << shift), (padDriver << shift));
    }
    IfxScuWdt_setCpuEndinit(passwd);
}
