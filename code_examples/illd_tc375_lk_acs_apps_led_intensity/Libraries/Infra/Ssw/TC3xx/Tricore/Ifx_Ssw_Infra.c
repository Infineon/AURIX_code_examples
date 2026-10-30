/**
 * \file Ifx_Ssw_Infra.c
 * \brief Startup Software support functions.
 *
 * \version iLLD_1_22_0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
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
 */

#include "Ifx_Cfg.h"
#include "Ifx_Ssw_Infra.h"

/******************************************************************************/
/*-------------------------Infrastructure Functions---------------------------*/
/******************************************************************************/

unsigned short Ifx_Ssw_getCpuWatchdogPassword(Ifx_SCU_WDTCPU *watchdog)
{
    return Ifx_Ssw_getCpuWatchdogPasswordInline(watchdog);
}


unsigned short Ifx_Ssw_getSafetyWatchdogPassword(void)
{
    return Ifx_Ssw_getSafetyWatchdogPasswordInline();
}


void Ifx_Ssw_clearCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_clearCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_setCpuEndinit(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_setCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_clearSafetyEndinit(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinitInline(password);
}


void Ifx_Ssw_setSafetyEndinit(unsigned short password)
{
    Ifx_Ssw_setSafetyEndinitInline(password);
}


void Ifx_Ssw_serviceCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    Ifx_Ssw_setCpuEndinitInline(watchdog, password);
}


void Ifx_Ssw_serviceSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_setSafetyEndinitInline(password);
}


void Ifx_Ssw_disableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    /* Select CPU Watchdog based on Core Id */
    unsigned int    cpuIndex;
    cpuIndex = Ifx_Ssw_MFCR(CPU_CORE_ID);
    cpuIndex = (unsigned int)((unsigned int)cpuIndex >> IFX_CPU_CORE_ID_CORE_ID_OFF) & IFX_CPU_CORE_ID_CORE_ID_MSK;
    cpuIndex = Ifx_Ssw_MINU(cpuIndex, 5);
    Ifx_SCU_WDTCPU *wdt = &MODULE_SCU.WDTCPU[cpuIndex];

    Ifx_Ssw_clearCpuEndinit(wdt, password);
    wdt->CON1.B.DR = 1U;         /* Set DR bit in Config_1 register */
    Ifx_Ssw_setCpuEndinit(wdt, password);
}


void Ifx_Ssw_enableCpuWatchdog(Ifx_SCU_WDTCPU *watchdog, unsigned short password)
{
    /* Select CPU Watchdog based on Core Id */
    unsigned int    cpuIndex;
    cpuIndex = Ifx_Ssw_MFCR(CPU_CORE_ID);
    cpuIndex = (unsigned int)((unsigned int)cpuIndex >> IFX_CPU_CORE_ID_CORE_ID_OFF) & IFX_CPU_CORE_ID_CORE_ID_MSK;
    cpuIndex = Ifx_Ssw_MINU(cpuIndex, 5);
    Ifx_SCU_WDTCPU *wdt = &MODULE_SCU.WDTCPU[cpuIndex];

    Ifx_Ssw_clearCpuEndinit(wdt, password);
    wdt->CON1.B.DR = 0U;         /* Clear DR bit in Config_1 register */
    Ifx_Ssw_setCpuEndinit(wdt, password);
}


void Ifx_Ssw_disableSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinit(password);
    SCU_WDTS_CON1.B.DR = 1U;     /* Set DR bit in Config_1 register */
    Ifx_Ssw_setSafetyEndinit(password);
}


void Ifx_Ssw_enableSafetyWatchdog(unsigned short password)
{
    Ifx_Ssw_clearSafetyEndinit(password);
    SCU_WDTS_CON1.B.DR = 0U;     /* Clear DR bit in Config_1 register */
    Ifx_Ssw_setSafetyEndinit(password);
}


void Ifx_Ssw_startCore(Ifx_CPU *cpu, unsigned int programCounter)
{
	volatile Ifx_CPU_PC     *pc;
	volatile Ifx_CPU_SYSCON *syscon;

	pc = &cpu->PC;
	/* Set the PC */
	pc->B.PC = (unsigned int)programCounter >> 1U;

	/* Release boot halt mode if required */
	syscon = &cpu->SYSCON;

	if (syscon->B.BHALT)
	{
		syscon->B.BHALT = 0U;
	}
}


void Ifx_Ssw_setCpu0Idle(void)
{
    Ifx_SCU_WDTCPU *wdt      = &MODULE_SCU.WDTCPU[0];
    unsigned short  cpuWdtPw = Ifx_Ssw_getCpuWatchdogPassword(wdt);
    Ifx_Ssw_clearCpuEndinit(wdt, cpuWdtPw);
    SCU_PMCSR0.B.REQSLP = 1U;
    Ifx_Ssw_setCpuEndinit(wdt, cpuWdtPw);
}


float Ifx_Ssw_getStmFrequency(void)
{
    float        oscFreq    = IFX_CFG_SSW_XTAL_FREQUENCY;
    float        sourcefreq = IFX_CFG_SSW_EVR_OSC_FREQUENCY;
    unsigned int insel      = SCU_SYSPLLCON0.B.INSEL;

    if (insel == 2U)
    {
        oscFreq = IFX_CFG_SSW_SYSCLK_PIN_FREQUENCY;
    }
    else if (insel == 1U)
    {
        oscFreq = IFX_CFG_SSW_XTAL_FREQUENCY;
    }
    else
    {
        oscFreq = IFX_CFG_SSW_EVR_OSC_FREQUENCY;
    }

    if (SCU_CCUCON0.B.CLKSEL != 0U)
    {
        sourcefreq = (oscFreq * (SCU_SYSPLLCON0.B.NDIV + 1U)) /
                     ((SCU_SYSPLLCON0.B.PDIV + 1U) * (SCU_SYSPLLCON1.B.K2DIV + 1U));
    }

    return sourcefreq / SCU_CCUCON0.B.STMDIV;
}

void Ifx_Ssw_doCppInit(void)
{
    Ifx_Ssw_C_InitInline();

	#ifdef __TASKING__
		extern void _main(void); /* cpp initialization */
		_main();
	#elif defined(__HIGHTEC__) && !defined(__clang__)
		extern void _init(void); /* cpp initialization */
		_init();
	#elif defined(__GNUC__) && !defined(__HIGHTEC__)
		extern void _init(void); /* cpp initialization */
		_init();
	#elif defined(__HIGHTEC__) && defined(__clang__) /* cpp initialization */
		extern void __libc_init_array(void);
		extern void __libc_fini_array(void);
		extern int atexit(void (*func)(void));
		atexit(__libc_fini_array);
		__libc_init_array();
	#elif defined(__ghs__)
		extern void _main(void); /* cpp initialization */
		_main();
	#endif
}

void Ifx_Ssw_doCppExit(int status)
{
	#ifdef __TASKING__
		extern void _doexit(void); /* cpp deinitialization */
		_doexit();
	#elif defined(__HIGHTEC__) && !defined(__clang__)
		extern void exit(int); /* cpp deinitialization */
		exit(status);
	#elif defined(__GNUC__) && !defined(__HIGHTEC__)
		extern void exit(int); /* cpp deinitialization */
		exit(status);
	#elif defined(__HIGHTEC__) && defined(__clang__)
		extern void exit(int); /* cpp deinitialization */
		exit(status);
	#elif __ghs__
		extern void exit(int); /* cpp deinitialization */
		exit(0);
	#endif

}


#if defined(__TASKING__)
#pragma optimize RL
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC optimize "O2"
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC optimize "O2"
#endif

#if (IFX_CFG_SSW_ENABLE_MONBIST == 1U)

static void Ifx_Ssw_MonbistCheck(void);

void Ifx_Ssw_Monbist(void)
{
     uint32 timeout;

     /* Disable the write-protection for registers */
    IFX_CFG_SSW_CLEAR_SAFETY_ENDINIT();
    /* Enable SMU Standby */
    PMS_CMD_STDBY.U    = 0x40000001U;
    /* clears the TSTEN, TSTRUN, TSTDONE, TSTOK, SMUERR and PMSERR flags */
    PMS_MONBISTCTRL.U  = 0x40000002U;
    /* Clear the filter */
    PMS_MONFILT.U = 0x20000000U;
    /* Wait until register is updated */
    timeout = 0x1000U;
    while ((PMS_MONFILT.U != 0x20000000U) && (timeout--))
    {};
    /* Activate under voltage and over voltage alarms */
    PMS_MONCTRL.U = 0xa5a5a5U;
    /* Wait until register is updated */
    timeout = 0x1000U;
    while ((PMS_MONCTRL.U != 0xa5a5a5U) && (timeout--))
    {};
    /* corresponding Over-voltage and Under-voltage interrupts are disabled */
    PMS_PMSIEN.U &= ~0x00000FFFU;
    /* Fault Signal reaction on alarms are disabled */
    PMS_AGFSP_STDBY0.U = 0x40000000U;
    PMS_AGFSP_STDBY1.U = 0x40000000U;
    /* FSP0EN and FSP1EN configuration bits are cleared to avoid spurious Error pin activation */
	/* ASCE bit is set and respective alarms are cleared */
    PMS_CMD_STDBY.U |= 0x40000008U;
	PMS_AG_STDBY0.U = 0xFFF0U;
	PMS_CMD_STDBY.U |= 0x40000008U;
	PMS_AG_STDBY1.U = 0x1FFFFU;
    /* Reset the MONFILT register */
    PMS_MONFILT.U = 0x00000000U;
    /* Start MONBIST test */
    PMS_MONBISTCTRL.U = 0x40000001U;

    /* Wait until MONBIST execution is done */
    timeout = 0x1000U;
    while (((PMS_MONBISTSTAT.B.TSTRUN == 1) || (PMS_MONBISTSTAT.B.TSTDONE == 0)) && (timeout--))
    {};

    /* Disable SMU Standby */
    PMS_CMD_STDBY.U    = 0x40000000U;
    IFX_CFG_SSW_SET_SAFETY_ENDINIT();

    Ifx_Ssw_jumpToFunction(&Ifx_Ssw_MonbistCheck);
}

void Ifx_Ssw_MonbistCheck(void)
{
    /* Check for MONBIST error state */
    if ((PMS_MONBISTSTAT.B.TSTOK == 0U) || (PMS_MONBISTSTAT.B.SMUERR == 1U) || (PMS_MONBISTSTAT.B.PMSERR == 1U))
    {
        __debug();
    }

    Ifx_Ssw_jumpBackToLink();
}
#endif

#if defined(DEVICE_TC33XED) || defined(DEVICE_TC37XED) || defined(DEVICE_TC39XB) || defined(DEVICE_TC35X)
#if (IFX_CFG_SSW_ENABLE_EMEM_INIT == 1U)

void Ifx_Ssw_UnlockEmem(void)
{
    if(SCU_CHIPID.B.EEA == 1U)
    {
      /* Enable EMEM clock */
      EMEM_CLC.U = 0x00000000U;
      /* sync access */
      EMEM_CLC.U;
      /* Disable Lock */
      EMEM_SBRCTR.U = 0x00000002U;
      EMEM_SBRCTR.U = 0x00000006U;
      EMEM_SBRCTR.U = 0x0000000EU;
    }
}
#endif /*(IFX_CFG_SSW_ENABLE_EMEM_INIT == 1U)*/
#endif/*#if defined(DEVICE_TC33XED) || defined(DEVICE_TC37XED) || defined(DEVICE_TC39XB) || defined(DEVICE_TC35X)*/

#if defined(__TASKING__)
#pragma endoptimize
#elif defined(__HIGHTEC__) && !defined(__clang__)
#pragma GCC reset_options
#elif defined(__GNUC__) && !defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
