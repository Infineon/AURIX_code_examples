/**
 * \file IfxHsphy_Dll.c
 * \brief HSPHY DLL details
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

#if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX)
#include "IfxHsphy_Dll.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxHsphy_Dll_xspiInit(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_Xspi_XspiCfg *config)
{
    uint32 timeoutCycleCount = IFXHSPHY_MAX_TIMEOUT;
    uint8  timeOutError      = 0U;
    hsphyRegPtr->CMNCFG.B.FSR     = 0;
    hsphyRegPtr->DLL.CFG.B.PEN3VX = config->dllCfg.dllOutputVolt;

    if (config->dllCfg.dllOutputVolt == IfxHsphy_DllOutputVoltage_1P8V)
    {
        hsphyRegPtr->DLL.CFG.B.PMODE = config->dllCfg.dllCfgPmodeClock;
    }
    else
    {
        hsphyRegPtr->DLL.CFG.B.PMODE = config->dllCfg.dllCfgPmodePads;
    }
    /* PLL clock frequency */
    hsphyRegPtr->DLL.CFG.B.REFCLKSE = 1; 

    /* Depending on the interface frequency update the FMODE */
    hsphyRegPtr->DLL.CFG.B.FMODE = config->dllCfg.dllFreqMode;

    hsphyRegPtr->DLL.CFG.B.TXCFG = config->dllCfg.txClkSkew;
    hsphyRegPtr->DLL.CFG.B.RXCFG = config->dllCfg.rxClkSkew;
    /* Switch on the DLL power    */
    hsphyRegPtr->DLL.CFG.B.POWER = 1;            

    /* Enables the TX clock */
    hsphyRegPtr->DLL.CFG.B.TXEN  = 1;  
     /* Enables the RX clock */          
    hsphyRegPtr->DLL.CFG.B.RXEN  = 1;      

    /* Poll until the LOCKSTAT is set */
    while (hsphyRegPtr->DLL.CFG.B.LOCKSTAT != 1) 
    {
        IFXHSPHY_LOOP_TIMEOUT_CHECK(timeoutCycleCount, timeOutError);
    }

    return (boolean)timeOutError;
}


boolean IfxHsphy_Dll_rgmiiInit(Ifx_HSPHY *hsphyRegPtr, IfxHsphy_Geth_RgmiiCfg *config)
{
    /* Module is enabled in the IfxHsphy_enableModule() */
    uint32 timeoutCycleCount = IFXHSPHY_MAX_TIMEOUT;
    uint8  timeOutError      = 0U;
    hsphyRegPtr->CMNCFG.B.FSR     = 1;

    /* Depending on the desired voltage of operation set 1 or 0 */
    hsphyRegPtr->DLL.CFG.B.PEN3VX = config->dllCfg.dllOutputVolt; 

    if (config->dllCfg.dllOutputVolt == IfxHsphy_DllOutputVoltage_1P8V)
    {
        hsphyRegPtr->DLL.CFG.B.PMODE = config->dllCfg.dllCfgPmodeClock;
    }
    else
    {
        hsphyRegPtr->DLL.CFG.B.PMODE = config->dllCfg.dllCfgPmodePads;
    }

    /* FMODE is set to 0 if output freqmax req is less than 166MHz freq allowed for RGMII is 125MHz */
    hsphyRegPtr->DLL.CFG.B.FMODE    = 0;
    hsphyRegPtr->DLL.CFG.B.REFCLKSE = config->dllCfg.dllRefClkSel;

    hsphyRegPtr->DLL.CFG.B.TXCFG    = config->dllCfg.txClkSkew;
    hsphyRegPtr->DLL.CFG.B.RXCFG    = config->dllCfg.rxClkSkew;

    /* Switch on the DLL power */
    hsphyRegPtr->DLL.CFG.B.POWER    = 1;         

    /* To enable/disable TX clk */
    hsphyRegPtr->DLL.CFG.B.TXEN     = 1;  

    /* To enable/disable RX clk  */
    hsphyRegPtr->DLL.CFG.B.RXEN     = 1;         

    /* Poll until the LOCKSTAT is set */
    while (hsphyRegPtr->DLL.CFG.B.LOCKSTAT != 1) 
    {
        IFXHSPHY_LOOP_TIMEOUT_CHECK(timeoutCycleCount, timeOutError);
    }

    return (boolean)timeOutError;
}


void IfxHsphy_Dll_xspiDeInit(Ifx_HSPHY *hsphyRegPtr)
{
    /* Disable the TX clock */
    hsphyRegPtr->DLL.CFG.B.TXEN  = 0;  
    /* Disable the RX clock */          
    hsphyRegPtr->DLL.CFG.B.RXEN  = 0;         
    /* Switch off the DLL power */   
    hsphyRegPtr->DLL.CFG.B.POWER = 0;            
}

#endif /* #if defined(DEVICE_TC4DX) || defined(DEVICE_TC48XAA) || defined(DEVICE_TC48X) || defined(DEVICE_TC44X) || defined(DEVICE_TC4ZX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
