/**
 * \file IfxWtu.c
 * \brief WTU  basic functionality
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
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxWtu.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxWtu_initConfig(IfxWtu_Config *config)
{
    config->password                      = IFXWTU_RESET_PASSWORD;
    config->reload                        = 0xFFFC;
    config->inputFrequency                = IfxWtu_IFSR_divBy16384;
    config->disableWatchdog               = FALSE;
    config->enableSmuRestriction          = FALSE;
    config->enableAutomaticPasswordChange = FALSE;
    config->enableTimerCheck              = FALSE;
    config->enableTimerCheckTolerance     = FALSE;
    config->TimerCheckToleranceValue      = 25;
    config->clrInternalResetFlag          = FALSE;
    config->TCVI                          = 0x3F;
}


void IfxWtu_initConfig0Register(Ifx_WTU_CTRLA *wtu_ctrla, IfxWtu_Config *config)
{
    Ifx_WTU_CTRLA ctrla;
    ctrla.U = wtu_ctrla->U;
    /* Initialize CTRLA register, with modify access, with user defined parameters
     * see Table 3 (Modify Access Bit Pattern Requirements) */

    ctrla.B.LCK  = 0;
    ctrla.B.PW   = config->password;  //user defined password
    ctrla.B.TCVI = config->TCVI;      //user defined reload value

    wtu_ctrla->U = ctrla.U;
}


void IfxWtu_initConfig1Register(Ifx_WTU_CTRLB *wtu_ctrlb, IfxWtu_Config *config)
{
    Ifx_WTU_CTRLB ctrlb;
    ctrlb.U = wtu_ctrlb->U;

    /* Initialize CTRLB register */
    switch (config->inputFrequency)
    {
    case IfxWtu_IFSR_divBy16384:
        ctrlb.B.IFSR = 0;
        break;
    case IfxWtu_IFSR_divBy256:
        ctrlb.B.IFSR = 1;
        break;
    case IfxWtu_IFSR_divBy64:
        ctrlb.B.IFSR = 2;
        break;
    default:
        ctrlb.B.IFSR = 3;
        break;
    }

    ctrlb.B.DR   = config->disableWatchdog ? 1 : 0;
    ctrlb.B.URR  = config->enableSmuRestriction ? 1 : 0;
    ctrlb.B.PAR  = config->enableAutomaticPasswordChange ? 1 : 0;
    ctrlb.B.TCR  = config->enableTimerCheck ? 1 : 0;
    ctrlb.B.TCTR = config->TimerCheckToleranceValue;
    ctrlb.B.TIMR = config->reload;

    wtu_ctrlb->U = ctrlb.U;
}


void IfxWtu_initCpuWatchdog(Ifx_WTU_WDTCPU *wtu, IfxWtu_Config *config)
{
    Ifx_WTU_CTRLA wtu_ctrla;
    Ifx_WTU_CTRLB wtu_ctrlb;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = wtu->CTRLA.U;
    wtu_ctrlb.U = 0;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW ^= 0x007F;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wtu->CTRLA.U = wtu_ctrla.U;
    }

    IfxWtu_initConfig0Register(&wtu_ctrla, config);

    /* Modify access ready - write WDT_CTRLA register */
    wtu->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be cleared in CTRLA before writting the bitfileds in CTRLB register */

    IfxWtu_initConfig1Register(&wtu_ctrlb, config);

    /* Finally write CTRLB with user defined configuration */
    wtu->CTRLB.U = wtu_ctrlb.U;

    /* LCK bit to be set once after the registers CTRLA & CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wtu->CTRLA.U    = wtu_ctrla.U;
}


void IfxWtu_initSecurityWatchdog(Ifx_WTU_WDTSEC *wtu, IfxWtu_Config *config)
{
    Ifx_WTU_CTRLA wtu_ctrla;
    Ifx_WTU_CTRLB wtu_ctrlb;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = wtu->CTRLA.U;
    wtu_ctrlb.U = 0;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW ^= 0x007F;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wtu->CTRLA.U = wtu_ctrla.U;
    }

    IfxWtu_initConfig0Register(&wtu_ctrla, config);

    /* Modify access ready - write WDT_CTRLA register */
    wtu->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be cleared in CTRLA before writting the bitfileds in CTRLB register */

    IfxWtu_initConfig1Register(&wtu_ctrlb, config);

    /* Finally write CTRLB with user defined configuration */
    wtu->CTRLB.U = wtu_ctrlb.U;

    /* LCK bit to be set once after the registers CTRLA & CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wtu->CTRLA.U    = wtu_ctrla.U;
}


void IfxWtu_initSystemWatchdog(Ifx_WTU_WDTSYS *wtu, IfxWtu_Config *config)
{
    Ifx_WTU_CTRLA wtu_ctrla;
    Ifx_WTU_CTRLB wtu_ctrlb;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = wtu->CTRLA.U;
    wtu_ctrlb.U = 0;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW ^= 0x007F;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wtu->CTRLA.U = wtu_ctrla.U;
    }

    IfxWtu_initConfig0Register(&wtu_ctrla, config);

    /* Modify access ready - write WDT_CTRLA register */
    wtu->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be cleared in CTRLA before writting the bitfileds in CTRLB register */

    IfxWtu_initConfig1Register(&wtu_ctrlb, config);

    /* Finally write CTRLB with user defined configuration */
    wtu->CTRLB.U = wtu_ctrlb.U;

    /* LCK bit to be set once after the registers CTRLA & CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wtu->CTRLA.U    = wtu_ctrla.U;
}


uint8 IfxWtu_getCpuWatchdogStatus(void)
{
    Ifx_WTU *wtu = &MODULE_WTU;
    return wtu->WDTCPU[IfxCpu_getCoreIndex()].STAT.B.D;
}


uint8 IfxWtu_getSecurityWatchdogStatus(void)
{
    Ifx_WTU *wtu = &MODULE_WTU;
    return wtu->WDTSEC.STAT.B.D;
}


uint8 IfxWtu_getSystemWatchdogStatus(void)
{
    Ifx_WTU *wtu = &MODULE_WTU;
    return wtu->WDTSYS.STAT.B.D;
}


uint16 IfxWtu_getCpuWatchdogPassword(void)
{
    return IfxWtu_getCpuWatchdogPasswordInline(&MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()]);
}


uint16 IfxWtu_getSecurityWatchdogPassword(void)
{
    return IfxWtu_getSecurityWatchdogPasswordInline();
}


uint16 IfxWtu_getSystemWatchdogPassword(void)
{
    return IfxWtu_getSystemWatchdogPasswordInline();
}


void IfxWtu_changeCpuWatchdogPassword(uint16 password, uint16 newPassword)
{
    Ifx_WTU_WDTCPU *watchdog = &MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()];

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    wtu_ctrla.U = watchdog->CTRLA.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        watchdog->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Password and LCK bit in Config_0 register */
    wtu_ctrla.B.PW    = newPassword;
    watchdog->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK   = 1;
    watchdog->CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_changeCpuWatchdogReload(uint16 password, uint16 reload)
{
    /* Select CPU Watchdog based on Core Id */
    uint32          coreId = IfxCpu_getCoreIndex();
    Ifx_WTU_WDTCPU *wdt    = &MODULE_WTU.WDTCPU[coreId];

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wdt->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Reload value and LCK bit in Config_0 register */
    wtu_ctrlb.B.TIMR = reload;
    wdt->CTRLA.U     = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wdt->CTRLB.U    = wtu_ctrlb.U;
    wdt->CTRLA.U    = wtu_ctrla.U;
}


void IfxWtu_changeSecurityWatchdogPassword(uint16 password, uint16 newPassword)
{
    Ifx_WTU_WDTSEC *watchdog = &MODULE_WTU.WDTSEC;

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    wtu_ctrla.U = watchdog->CTRLA.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        watchdog->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Password and LCK bit in Config_0 register */
    wtu_ctrla.B.PW    = newPassword;
    watchdog->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK   = 1;
    watchdog->CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_changeSecurityWatchdogReload(uint16 password, uint16 reload)
{
    /* Initialize pointer to Safety Watchdog */
    Ifx_WTU_WDTSEC *wdt = &MODULE_WTU.WDTSEC;

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wdt->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Reload value and LCK bit in Config_0 register */
    wtu_ctrlb.B.TIMR = reload;
    wdt->CTRLA.U     = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wdt->CTRLB.U    = wtu_ctrlb.U;
    wdt->CTRLA.U    = wtu_ctrla.U;
}


void IfxWtu_changeSystemWatchdogPassword(uint16 password, uint16 newPassword)
{
    Ifx_WTU_WDTSYS *watchdog = &MODULE_WTU.WDTSYS;

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    wtu_ctrla.U = watchdog->CTRLA.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        watchdog->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Password and LCK bit in Config_0 register */
    wtu_ctrla.B.PW    = newPassword;
    watchdog->CTRLA.U = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK   = 1;
    watchdog->CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_changeSystemWatchdogReload(uint16 password, uint16 reload)
{
    /* Initialize pointer to Safety Watchdog */
    Ifx_WTU_WDTSYS *wdt = &MODULE_WTU.WDTSYS;

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        wdt->CTRLA.U = wtu_ctrla.U;
    }

    /* Set new Reload value and LCK bit in Config_0 register */
    wtu_ctrlb.B.TIMR = reload;
    wdt->CTRLA.U     = wtu_ctrla.U;

    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK = 1;
    wdt->CTRLB.U    = wtu_ctrlb.U;
    wdt->CTRLA.U    = wtu_ctrla.U;
}


void IfxWtu_disableCpuWatchdog(uint16 password)
{
    /* Select CPU Watchdog based on Core Id */
    uint32          coreId = (uint32)IfxCpu_getCoreIndex();
    Ifx_WTU_WDTCPU *wdt    = &MODULE_WTU.WDTCPU[coreId];

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR                                   = 1; //Set DR bit in Config_1 register

    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLB.U = wtu_ctrlb.U;

    wtu_ctrla.B.LCK                                  = 1;

    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_disableSecurityWatchdog(uint16 password)
{
    Ifx_WTU_WDTSEC *wdt = &MODULE_WTU.WDTSEC;
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR            = 1; //Set DR bit in Config_1 register

    MODULE_WTU.WDTSEC.CTRLB.U = wtu_ctrlb.U;
    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK           = 1;

    MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_disableSystemWatchdog(uint16 password)
{
    Ifx_WTU_WDTSYS *wdt = &MODULE_WTU.WDTSYS;
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR            = 1; //Set DR bit in Config_1 register

    MODULE_WTU.WDTSYS.CTRLB.U = wtu_ctrlb.U;
    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK           = 1;

    MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_enableCpuWatchdog(uint16 password)
{
    /* Select CPU Watchdog based on Core Id */
    uint32          coreId = (uint32)IfxCpu_getCoreIndex();
    Ifx_WTU_WDTCPU *wdt    = &MODULE_WTU.WDTCPU[coreId];

    /* Read Config_0 register */
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR                                   = 0; //Set DR bit in Config_1 register

    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLB.U = wtu_ctrlb.U;

    wtu_ctrla.B.LCK                                  = 1;

    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_enableSecurityWatchdog(uint16 password)
{
    Ifx_WTU_WDTSEC *wdt = &MODULE_WTU.WDTSEC;
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR            = 0; //Set DR bit in Config_1 register

    MODULE_WTU.WDTSEC.CTRLB.U = wtu_ctrlb.U;
    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK           = 1;

    MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_enableSystemWatchdog(uint16 password)
{
    Ifx_WTU_WDTSYS *wdt = &MODULE_WTU.WDTSYS;
    Ifx_WTU_CTRLA   wtu_ctrla;
    Ifx_WTU_CTRLB   wtu_ctrlb;
    wtu_ctrla.U = wdt->CTRLA.U;
    wtu_ctrlb.U = wdt->CTRLB.U;

    if (wdt->CTRLA.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;
    }

    /* Password ready. Store it to WDT_CTRLA to unprotect the register */
    MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;

    wtu_ctrlb.B.DR            = 0; //Set DR bit in Config_1 register

    MODULE_WTU.WDTSYS.CTRLB.U = wtu_ctrlb.U;
    /* LCK bit to be set once after the register CTRLA/CTRLB are written */
    wtu_ctrla.B.LCK           = 1;

    MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_serviceCpuWatchdog(uint16 password)
{
    /* TODO Update as per spec */
    Ifx_WTU_CTRLA wtu_ctrla;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U; /*wtu->CTRLA.U;*/

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        if (MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].STAT.B.TC == 1U)
        {
            wtu_ctrla.B.TCVI = ~(MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].STAT.B.TIM);
        }

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;
    }

    wtu_ctrla.B.LCK                                  = 1;
    MODULE_WTU.WDTCPU[IfxCpu_getCoreIndex()].CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_serviceSecurityWatchdog(uint16 password)
{
    /* TODO Update as per spec */
    Ifx_WTU_CTRLA wtu_ctrla;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = MODULE_WTU.WDTSEC.CTRLA.U; /*wtu->CTRLA.U;*/

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        if (MODULE_WTU.WDTSEC.STAT.B.TC == 1U)
        {
            wtu_ctrla.B.TCVI = ~(MODULE_WTU.WDTSEC.STAT.B.TIM);
        }

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;
    }

    wtu_ctrla.B.LCK           = 1;
    MODULE_WTU.WDTSEC.CTRLA.U = wtu_ctrla.U;
}


void IfxWtu_serviceSystemWatchdog(uint16 password)
{
    /* TODO Update as per spec */
    Ifx_WTU_CTRLA wtu_ctrla;

    /* Read Config_0 register and clear wtu_ctrlb variable */
    wtu_ctrla.U = MODULE_WTU.WDTSYS.CTRLA.U; /*wtu->CTRLA.U;*/

    if (wtu_ctrla.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wtu_ctrla.B.LCK = 0;
        wtu_ctrla.B.PW  = password;

        if (MODULE_WTU.WDTSYS.STAT.B.TC == 1U)
        {
            wtu_ctrla.B.TCVI = ~(MODULE_WTU.WDTSYS.STAT.B.TIM);
        }

        /* Password ready. Store it to WDT_CTRLA to unprotect the register */
        MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;
    }

    wtu_ctrla.B.LCK           = 1;
    MODULE_WTU.WDTSYS.CTRLA.U = wtu_ctrla.U;
}
