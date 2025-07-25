/**
 * \file IfxHsphy_Mp8g.c
 * \brief HSPHY MP8G details
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxHsphy_Mp8g.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxHsphy_Mp8g_resetModule(Ifx_HSPHY *hsphyRegPtr)
{
    uint32 timeoutCycleCount = IFXHSPHY_MAX_TIMEOUT;
    uint8  timeOutError      = 0U;
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(hsphyRegPtr->PROTE), IfxApProt_State_config);
#endif

    hsphyRegPtr->RST.CTRLA.B.KRST = 1;
    hsphyRegPtr->RST.CTRLB.B.KRST = 1;

    while (0 == hsphyRegPtr->RST.STAT.B.KRST)    /* Wait until reset is executed */
    {
        IFXHSPHY_LOOP_TIMEOUT_CHECK(timeoutCycleCount, timeOutError);
    }

    if (timeOutError == TRUE)
    {
        return TRUE;
    }

    hsphyRegPtr->RST.CTRLB.B.STATCLR = 1;       /* Clear Kernel reset status bit */

    while (hsphyRegPtr->RST.STAT.B.KRST == 1)   /* Wait until reset is released */
    {
        IFXHSPHY_LOOP_TIMEOUT_CHECK(timeoutCycleCount, timeOutError);
    }

    if (timeOutError == TRUE)
    {
        return TRUE;
    }

#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(hsphyRegPtr->PROTE), IfxApProt_State_run);
#endif
    return (boolean)timeOutError;
}


boolean IfxHsphy_Mp8g_setPhyRefClockSel(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device)
{
    boolean ret = TRUE;

    if (phyIndex == IfxHsphy_PhyIndex_0)
    {
        if (device == IfxHsphy_TrgtDevice_pcie)
        {
            //PCIE
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.PRS = 1; /* 0b1, IFXHSPHY_PHY0_REFCLKSEL_PAD */
        }
        else if (device == IfxHsphy_TrgtDevice_xgmac)
        {
            //XGMAC
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.PRS = 0; /* 0b0, IFXHSPHY_PHY0_REFCLKSEL_ALT */
        }
        else
        {
            ret = FALSE;
        }
    }

    if (phyIndex == IfxHsphy_PhyIndex_1)
    {
        if ((device == IfxHsphy_TrgtDevice_xgmac) || (device == IfxHsphy_TrgtDevice_trace))
        {
            //XGMAC or TRACE
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.PRS = 0; /* 0b0, IFXHSPHY_PHY1_REFCLKSEL_ALT */
        }
        else
        {
            ret = FALSE;
        }
    }

    if (phyIndex == IfxHsphy_PhyIndex_2)
    {
        if (device == IfxHsphy_TrgtDevice_pcie)
        {
            //PCIE
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.PRS = 1; /* 0b1, IFXHSPHY_PHY2_REFCLKSEL_PAD */
        }
        else if (device == IfxHsphy_TrgtDevice_trace)
        {
            //TPCS
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.PRS = 0; /* 0b0, IFXHSPHY_PHY2_REFCLKSEL_ALT */
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;
}


boolean IfxHsphy_Mp8g_selFunction(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device)
{
    boolean ret = TRUE;

    if (phyIndex == IfxHsphy_PhyIndex_0)
    {
        if (device == IfxHsphy_TrgtDevice_pcie)
        {
            //PCIE
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 1;
        }
        else if (device == IfxHsphy_TrgtDevice_xgmac)
        {
            //XGMAC
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 0;
        }
        else
        {
            ret = FALSE;
        }
    }

    if (phyIndex == IfxHsphy_PhyIndex_1)
    {
        if (device == IfxHsphy_TrgtDevice_xgmac)
        {
            //XGMAC
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 0;
        }
        else if (device == IfxHsphy_TrgtDevice_trace)
        {
            //TPCS
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 1;
        }
        else
        {
            ret = FALSE;
        }
    }

    if (phyIndex == IfxHsphy_PhyIndex_2)
    {
        if (device == IfxHsphy_TrgtDevice_pcie)
        {
            //PCIE
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 0;
        }
        else if (device == IfxHsphy_TrgtDevice_trace)
        {
            //TPCS
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 1;
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;
}


boolean IfxHsphy_Mp8g_isPhyReady(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex)
{
    boolean ret = TRUE;

    if ((phyIndex == IfxHsphy_PhyIndex_0) || (phyIndex == IfxHsphy_PhyIndex_1) || (phyIndex == IfxHsphy_PhyIndex_2))
    {
        //Check if the PHY is ready by checking if SRAM loading start.
        ret = (hsphyRegPtr->PHY[phyIndex].CTRL1.B.INITDONE == 1);
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}


boolean IfxHsphy_Mp8g_setExtLdDone(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex)
{
    boolean ret = TRUE;

    if ((phyIndex == IfxHsphy_PhyIndex_0) || (phyIndex == IfxHsphy_PhyIndex_1) || (phyIndex == IfxHsphy_PhyIndex_2))
    {
        //Check if the PHY is ready by checking if SRAM loading start.
        if (hsphyRegPtr->PHY[phyIndex].CTRL1.B.EXTLDDONE != 1)
        {
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.EXTLDDONE = 1;
        }

        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }

    return ret;
}


void IfxHsphy_Mp8g_PowerDownReset(Ifx_HSPHY *hsphySFR, IfxHsphy_PhyIndex phyIndex, IfxHsphy_PhyPowerMode phyPowerMode)
{
    hsphySFR->PHY[phyIndex].CTRL1.B.PWRDWN = phyPowerMode;
    hsphySFR->PHY[phyIndex].CTRL1.B.RST    = 0;
}
