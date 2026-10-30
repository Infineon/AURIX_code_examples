/**
 * \file IfxPort.c
 * \brief PORT  basic functionality
 *
 * \version iLLD_1_22_0
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
    	/* Check if the current port matches the specified port */
        if (port == IfxPort_cfg_esrMasks[portIndex].port)
        {
        	 /* Check if the specified pin index is part of the emergency stop mask */
            if ((1U << pinIndex) & IfxPort_cfg_esrMasks[portIndex].masks)
            {
            	/* Reset the emergency stop request for the specified pin */
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
    	/* Check if the current port matches the specified port */
        if (port == IfxPort_cfg_esrMasks[portIndex].port)
        {
        	 /* Check if the specified pin index is part of the emergency stop mask */
            if ((1U << pinIndex) & IfxPort_cfg_esrMasks[portIndex].masks)
            {
            	/* Reset the emergency stop request for the specified pin */
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

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Reset the emergency stop request for the specified pin */
    __ldmst(&port->ESR.U, 1U << pinIndex, 0);
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setESR(Ifx_P *port, uint8 pinIndex)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    /* Set the emergency stop request for the specified pin */
    __ldmst(&port->ESR.U, 1U << pinIndex, 1U << pinIndex);
    /* Setting the endinit protection back on */
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

    IFX_UNUSED_PARAMETER(index == IfxPort_OutputIdx_general);

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
    /* Clearing the endinit protection */
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
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinMode(Ifx_P *port, uint8 pinIndex, IfxPort_Mode mode)
{
    volatile Ifx_P_IOCR0 *iocr      = &(port->IOCR0);
    uint8                 iocrIndex = (pinIndex / 4);
    uint8                 shift     = (pinIndex & 0x3U) * 8;

#if !defined(DEVICE_TC33XED) && !defined (DEVICE_TC35X)
#if defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC39XB)
    if ((port == &MODULE_P40) || (port == &MODULE_P41))
#else
    if (port == &MODULE_P40)
#endif
    {
        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
        /* Clearing the endinit protection */
        IfxScuWdt_clearCpuEndinit(passwd);
        /* Disable the analog functionality for the specified pin by clearing the corresponding bit in the PDISC register */
        port->PDISC.U &= ~(1 << pinIndex);
        /* Setting the endinit protection back on */
        IfxScuWdt_setCpuEndinit(passwd);
    }
#endif
    /* Update the IOCR register to set the mode for the specified pin */
    __ldmst(&iocr[iocrIndex].U, (0xFFUL << shift), (mode << shift));
}


void IfxPort_setPinModeLVDS(Ifx_P *port, uint8 pinIndex, IfxPort_Mode pinMode, IfxPort_LvdsConfig *lvds)
{
    uint32               lpcrOffset;

    volatile Ifx_P_LPCR *lpcr       = &(port->LPCR[0]);
    uint16               passwd     = IfxScuWdt_getCpuWatchdogPassword();

    if((port == &MODULE_P14) && (pinIndex == 9 || pinIndex == 10))
	{
		/* Pad pair P14.9 and P14.10 is controlled by P14_LPCR5 */
		lpcrOffset = 5;
	}
	else
	{
		lpcrOffset = (pinIndex / 2);
	}

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    lpcr[lpcrOffset].B.LVDSM = lvds->lvdsMode;
    lpcr[lpcrOffset].B.PS    = lvds->padSupply;

    if (pinMode < IfxPort_Mode_outputPushPullGeneral)
    {
        lpcr[lpcrOffset].B.REN_CTRL = lvds->enablePortControlled;
        lpcr[lpcrOffset].B.RX_EN    = 1;
    }
    else
    {
        lpcr[lpcrOffset].B.TEN_CTRL = lvds->enablePortControlled;
        lpcr[lpcrOffset].B.TX_EN    = 1;
        lpcr[lpcrOffset].B.TX_PD    = 0;
    }

    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinPadDriver(Ifx_P *port, uint8 pinIndex, IfxPort_PadDriver padDriver)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    /* Clearing the endinit protection */
    IfxScuWdt_clearCpuEndinit(passwd);
    {
        volatile uint32 *pdr      = (volatile uint32 *)&(port->PDR0.U);
        uint8            pdrIndex = (pinIndex / 8);
        uint8            shift    = (pinIndex & 0x7U) * 4;
        /* Update the pad driver configuration for the specified pin */
        __ldmst(&(pdr[pdrIndex]), (0xFUL << shift), (padDriver << shift));
    }
    /* Setting the endinit protection back on */
    IfxScuWdt_setCpuEndinit(passwd);
}


void IfxPort_setPinControllerSelection(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_modifyPinControllerSelection(port, pinIndex, TRUE);
}


void IfxPort_resetPinControllerSelection(Ifx_P *port, uint8 pinIndex)
{
    IfxPort_modifyPinControllerSelection(port, pinIndex, FALSE);
}


void IfxPort_modifyPinControllerSelection(Ifx_P *port, uint8 pinIndex, boolean mode)
{
    uint16 passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Clearing the safety endinit protection */
    IfxScuWdt_clearSafetyEndinit(passwd);
    /* Modify the Pin Controller Selection Register (PCSR) for the specified pin */
    __ldmst(&port->PCSR.U, 1U << pinIndex, mode << pinIndex);
    /* Setting the safety endinit protection back on */
    IfxScuWdt_setSafetyEndinit(passwd);
}
