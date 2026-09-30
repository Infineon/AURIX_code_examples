/**
 * \file IfxGst.h
 * \brief GST  basic functionality
 * \ingroup IfxLld_Gst
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

#ifndef IFXGST_H
#define IFXGST_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGst_cfg.h"
#include "_PinMap/IfxGst_PinMap.h"
#include "IfxGst_reg.h"
#include "Src/Std/IfxSrc.h"
#include "Ap/Std/IfxApProt.h"
#include "Ap/Std/IfxApApu.h"

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief Prescaler value for module clock
 * Definition in Ifx_GST.CFG.B.PRE
 */
typedef enum
{
    IfxGst_ClockPrescalar_div1 = 0,  /**< \brief Input clock is system clock */
    IfxGst_ClockPrescalar_div2 = 1,  /**< \brief Input clock is divided by 2 */
    IfxGst_ClockPrescalar_div4 = 2,  /**< \brief Input clock is divided by 4 */
    IfxGst_ClockPrescalar_div8 = 3   /**< \brief Input clock is divided by 8 */
} IfxGst_ClockPrescalar;

/** \brief Interrupt selection
 */
typedef enum
{
    IfxGst_Interrupt_bufferOverflow  = 0,  /**< \brief Select the buffer overflow interrupt */
    IfxGst_Interrupt_counterOverflow = 1,  /**< \brief Select the counter overflow interrupt */
    IfxGst_Interrupt_dma             = 2   /**< \brief Select the dma interrupt */
} IfxGst_Interrupt;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_GST.CLC.B.EDIS
 */
typedef enum
{
    IfxGst_SleepMode_enable  = 0,
    IfxGst_SleepMode_disable = 1
} IfxGst_SleepMode;

/** \brief Hardware trigger pulse length
 * Definition in Ifx_GST.CFG.B.PLE
 */
typedef enum
{
    IfxGst_TriggerPulseLength_1_clock    = 0, /**< \brief Pulse length is one GST clock cycle */
    IfxGst_TriggerPulseLength_2_clock    = 1, /**< \brief Pulse length is two GST clock cycle */
    IfxGst_TriggerPulseLength_4_clock    = 2, /**< \brief Pulse length is four GST clock cycle */
    IfxGst_TriggerPulseLength_8_clock    = 3, /**< \brief Pulse length is eight GST clock cycle */
    IfxGst_TriggerPulseLength_ToggleMode = 7  /**< \brief Pulse is set to toggle mode */
} IfxGst_TriggerPulseLength;

/** \brief trigger type selection
 * Definition in Ifx_GST.CFG.B.TRGTYP
 */
typedef enum
{
    IfxGst_TriggerType_none     = 0,  /**< \brief No trigger will be generated */
    IfxGst_TriggerType_delayed  = 1,  /**< \brief Delayed trigger generation is enabled */
    IfxGst_TriggerType_matching = 2,  /**< \brief Matching trigger generation is enabled */
    IfxGst_TriggerType_both     = 3   /**< \brief Both trigger types are enabled */
} IfxGst_TriggerType;

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Function that requests to enable the module clock
 * \param gst Pointer to the GST SFR
 * \return None
 */
IFX_INLINE void IfxGst_enableModule(Ifx_GST *gst);

/** \brief Disables the specified module of the Global State Controller (GST).
 * \param gst Pointer to the Ifx_GST module instance to be disabled.
 * \return None
 */
IFX_INLINE void IfxGst_disableModule(Ifx_GST *gst);

/** \brief Checks if the GST module is enabled.
 * \param gst Pointer to the GST SFR
 * \return Returns TRUE: Module clock is enabled
 * returns FALSE: Off, module is not clocked
 */
IFX_INLINE boolean IfxGst_isModuleEnabled(Ifx_GST *gst);

/** \brief Clears the system counter value.
 * \param gst Pointer to the GST SFR
 * \return None
 */
IFX_INLINE void IfxGst_clearSystemCounterValue(Ifx_GST *gst);

/** \brief Function to clear the trigger reload counter
 * \param gst Pointer to the GST SFR
 * \return None
 */
IFX_INLINE void IfxGst_clearTriggerCounterValue(Ifx_GST *gst);

/** \brief Flushes and resets the cyclic buffer of the GST module.
 * \param gst Pointer to the GST SFR
 * \return None
 */
IFX_INLINE void IfxGst_flushCyclicBuffer(Ifx_GST *gst);

/** \brief Clears the status register of the GST module.
 * \param gst Pointer to the GST SFR
 * \return None
 */
IFX_INLINE void IfxGst_clearStatusRegister(Ifx_GST *gst);

/** \brief Retrieves a pointer to the source control register (SRCR) for the specified interrupt.
 * \param gst pointer to GST SFR
 * \param interrupt The interrupt for which to retrieve the source control register pointer.
 * This is an input parameter of type IfxGst_Interrupt.
 * \return Pointer to the source control register (SRCR) for the specified interrupt.
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxGst_getSrcPointer(Ifx_GST *gst, IfxGst_Interrupt interrupt);

/** \brief Configures the sleep mode for the GST (General System Timer) module.
 * \param gst pointer to the GST SFR
 * \param mode mode The sleep mode to be set for the GST module. The mode can be one of
 *                the following:
 *                - #IfxGst_SleepMode_active: Active mode - Full functionality.
 *                - #IfxGst_SleepMode_standby: Standby mode - Reduced power consumption
 *                                            with quick wake-up capability.
 *                - #IfxGst_SleepMode_lowPower: Low-power mode - Minimal power
 *                                               consumption, slower wake-up.
 * \return None
 */
IFX_INLINE void IfxGst_setSleepMode(Ifx_GST *gst, IfxGst_SleepMode mode);

/** \brief Resets the GST module
 * \param gst pointer to GST registers
 * \return None
 */
IFX_INLINE void IfxGst_resetModule(Ifx_GST *gst);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes the trigger output pin for the Global State Trigger (GST) module.
 * \param trigPin Pointer to the trigger pin configuration structure. This structure contains hardware-specific
 *                 settings for the trigger pin and must not be modified by the caller after initialization.
 * \param pinMode The output mode to be configured for the trigger pin. This parameter determines how the pin
 *                    drives the output signal (e.g., push-pull, open-drain, etc.).
 * \param padDriver The pad driver configuration for the trigger pin. This parameter specifies the strength and
 *                      type of the output driver (e.g., high-drive, low-drive, etc.).
 * \return None
 */
IFX_EXTERN void IfxGst_initTriggerOutPin(const IfxGst_Hwtrg_Out *trigPin, IfxPort_OutputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Initializes the capture input pin for the GST module.
 * \param capturePin Pointer to the capture input pin configuration structure.
 *                    This structure contains hardware-specific settings for the pin.
 * \param pinMode Input mode configuration for the pin. Specifies how the pin should behave during input operations.
 * \param padDriver Pad driver configuration for the pin. Defines the strength and driving capabilities of the pin.
 * \return None
 */
IFX_EXTERN void IfxGst_initCaptureInPin(const IfxGst_Hwcap_In *capturePin, IfxPort_InputMode pinMode, IfxPort_PadDriver padDriver);

/** \brief Configures access to the General System Timer(s) (GSTs) based on the provided configuration.
 * \param apConfig Pointer to the AP configuration structure containing the access settings for GSTs.
 *                     Must be initialized with valid configuration parameters.
 * \return None
 */
IFX_EXTERN void IfxGst_configureAccessToGsts(IfxApApu_ApuConfig *apConfig);

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGst_enableModule(Ifx_GST *gst)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_config);
#endif
#endif
    gst->CLC.B.DISR = (uint8)0;
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_run);
#endif
#endif

    while (gst->CLC.B.DISS == (uint32)1)
    {
        /* wait until module is enabled */
    }
}


IFX_INLINE void IfxGst_disableModule(Ifx_GST *gst)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_config);
#endif
#endif

    gst->CLC.B.DISR = (uint8)1;
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_run);
#endif
#endif

    while (gst->CLC.B.DISS == (uint32)0)
    {
        /* wait until module is disabled */
    }
}


IFX_INLINE boolean IfxGst_isModuleEnabled(Ifx_GST *gst)
{
    boolean return_status = FALSE;
    return_status = (gst->CLC.B.DISS == (uint32)0) ? TRUE : FALSE;
    return return_status;
}


IFX_INLINE void IfxGst_clearSystemCounterValue(Ifx_GST *gst)
{
    gst->CTRL.B.CNTCLR = 1U;
}


IFX_INLINE void IfxGst_clearTriggerCounterValue(Ifx_GST *gst)
{
    gst->CTRL.B.RELCLR = 1U;
}


IFX_INLINE void IfxGst_flushCyclicBuffer(Ifx_GST *gst)
{
    gst->CTRL.B.FLUSH = 1U;
}


IFX_INLINE void IfxGst_clearStatusRegister(Ifx_GST *gst)
{
    gst->CTRL.B.STATCLR = 1U;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxGst_getSrcPointer(Ifx_GST *gst, IfxGst_Interrupt interrupt)
{
    volatile Ifx_SRC_SRCR *srcPtr = NULL_PTR;

    if (gst == &MODULE_GST0)
    {
        if (interrupt == IfxGst_Interrupt_bufferOverflow)
        {
            srcPtr = &MODULE_SRC.GST[0].BUFFFULL;
        }
        else if (interrupt == IfxGst_Interrupt_counterOverflow)
        {
            srcPtr = &MODULE_SRC.GST[0].CNTOVFL;
        }
        else
        {
            srcPtr = &MODULE_SRC.GST[0].DMA;
        }
    }

    return srcPtr;
}


IFX_INLINE void IfxGst_setSleepMode(Ifx_GST *gst, IfxGst_SleepMode mode)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(gst->PROTE), IfxApProt_State_config);
#endif
#endif
    gst->CLC.B.EDIS = (uint8)mode;
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&(gst->PROTE), IfxApProt_State_run);
#endif
#endif
}


IFX_INLINE void IfxGst_resetModule(Ifx_GST *gst)
{
#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_config);
#endif
#endif
    gst->RST.CTRLB.B.KRST = 1;        /* Only if both Kernel reset bits are set a reset is executed */
    gst->RST.CTRLA.B.KRST = 1;

    while (0 == gst->RST.STAT.B.KRST) /* Wait until reset is executed */
    {}

    gst->RST.CTRLB.B.STATCLR = 1;     /* Clear Kernel reset status bit */

    while (gst->RST.STAT.B.KRST == 1) /* Wait until KRST is cleared, only after this reset sequence is completed */
    {}

#if defined(IFX_PROT_ENABLED)
#if (IFX_PROT_ENABLED == 1U)
    IfxApProt_setState((Ifx_PROT_PROT *)&gst->PROTE, IfxApProt_State_run);
#endif
#endif
}


#endif /* IFXGST_H */
