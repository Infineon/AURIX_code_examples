/**
 * \file IfxHsphy_EthIO.c
 * \brief HSPHY ETHIO details
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
#pragma warning 508			/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96	/* To suppress empty file warning */
#endif

#if !defined(DEVICE_TC4EX)  && !defined(DEVICE_TC4PX)
#include "IfxHsphy_EthIO.h"
 
/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX)
void IfxHsphy_EthIO_interfaceSelect(Ifx_HSPHY *hsphySFR, IfxHsphy_EthIndex ethIndex, IfxHsphy_EthCtrlExtPhySel ethCtrlExtPhySel, boolean ethPort16)
{
    hsphySFR->ETH[ethIndex].B.EPR = ethCtrlExtPhySel;

    if (((ethCtrlExtPhySel == IfxHsphy_EthCtrlExtPhySel_rmii) && (ethPort16 == TRUE)) || (ethCtrlExtPhySel == IfxHsphy_EthCtrlExtPhySel_rgmii))
    {
        hsphySFR->CMNCFG.B.FSR = 1;
    }
    else
    {
        hsphySFR->CMNCFG.B.FSR = 0;
    }
}

#else

boolean IfxHsphy_EthIO_interfaceSelect(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_PhyIndex phyIndex, IfxHsphy_TrgtDevice device)
{
    boolean ret = TRUE;

    if (phyIndex == IfxHsphy_PhyIndex_1)
    {
        if (device == IfxHsphy_TrgtDevice_eth)
        {
            /* ETH */
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 0;
        }
        else if (device == IfxHsphy_TrgtDevice_trace)
        {
            /* TPCS */
            hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 1;
        }
        else
        {
            ret = FALSE;
        }
    }

#if IFXHSPHY_IS_PHY2_AVAILABLE
    if (phyIndex == IfxHsphy_PhyIndex_2)
	{
		if (device == IfxHsphy_TrgtDevice_pcie)
		{
			/* PCIE */
			hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 0;
		}
		else if (device == IfxHsphy_TrgtDevice_trace)
		{
			/* TPCS */
			hsphyRegPtr->PHY[phyIndex].CTRL1.B.FSP = 1;
		}
		else
		{
			ret = FALSE;
		}
	}
#endif /* #if IFXHSPHY_IS_PHY2_AVAILABLE */

    return ret;
}
#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#endif /* #if !defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
