/**
 * \file IfxGtm_Tim.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
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
 *
 *
 * \defgroup IfxLld_Gtm_Std_Tim Tim Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Tim_Enumerations TIM Enumerations
 * \ingroup IfxLld_Gtm_Std_Tim
 * \defgroup IfxLld_Gtm_Std_Tim_Channel_Functions TIM Channel Functions
 * \ingroup IfxLld_Gtm_Std_Tim
 */

#ifndef IFXGTM_TIM_H
#define IFXGTM_TIM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "Src/Std/IfxSrc.h"
#include "IfxGtm.h"
#include "IfxGtm_Cmu.h"
#include "IfxGtm_bf.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Tim_Enumerations
 * \{ */
typedef enum
{
    IfxGtm_Tim_CntsSel_cntReg = 0,
    IfxGtm_Tim_CntsSel_tbuTs0
} IfxGtm_Tim_CntsSel;

/** \brief Enum for Filter counter
 */
typedef enum
{
    IfxGtm_Tim_FilterCounter_upDown = 0,
    IfxGtm_Tim_FilterCounter_hold
} IfxGtm_Tim_FilterCounter;

/** \brief Enum for Filter mode
 */
typedef enum
{
    IfxGtm_Tim_FilterMode_immediateEdgePropagation = 0,  /**< \brief Immediate edge Propagation mode */
    IfxGtm_Tim_FilterMode_individualDeglitchTime         /**< \brief Individual deglitch mode */
} IfxGtm_Tim_FilterMode;

typedef enum
{
    IfxGtm_Tim_GprSel_tbuTs0 = 0,
    IfxGtm_Tim_GprSel_tbuTs1,
    IfxGtm_Tim_GprSel_tbuTs2,
    IfxGtm_Tim_GprSel_cnts
} IfxGtm_Tim_GprSel;

typedef enum
{
    IfxGtm_Tim_Input_currentChannel = 0,
    IfxGtm_Tim_Input_adjacentChannel
} IfxGtm_Tim_Input;

typedef enum
{
    IfxGtm_Tim_Mode_pwmMeasurement = 0,  /**< \brief TPWM */
    IfxGtm_Tim_Mode_pulseIntegration,    /**< \brief TPIM */
    IfxGtm_Tim_Mode_inputEvent,          /**< \brief TIEM */
    IfxGtm_Tim_Mode_inputPrescaler,      /**< \brief TIPM */
    IfxGtm_Tim_Mode_bitCompression       /**< \brief TBCM */
} IfxGtm_Tim_Mode;

/** \brief Enum for Timeout control
 */
typedef enum
{
    IfxGtm_Tim_Timeout_disabled,     /**< \brief Timeout feature disabled */
    IfxGtm_Tim_Timeout_risingEdge,   /**< \brief Timeout feature enabled for rising edge only */
    IfxGtm_Tim_Timeout_fallingEdge,  /**< \brief Timeout feature enabled for falling edge only */
    IfxGtm_Tim_Timeout_bothEdge      /**< \brief Timeout feature enabled for both edges */
} IfxGtm_Tim_Timeout;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tim_Channel_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the counter overflow flag
 * \param channel TIM channel pointer
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_clearCntOverflowEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Clears the data lost flag
 * \param channel TIM channel pointer
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_clearDataLostEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Clears the event counter overflow flag
 * \param channel TIM channel pointer
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_clearEcntOverflowEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Clears the glitch flag
 * \param channel TIM channel pointer
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_clearGlitchEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Clears the new value flag
 * \param channel TIM channel pointer
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_clearNewValueEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Returns a pointer to the TIM channel SRC
 * \param gtm Pointer to GTM module
 * \param tim Specifies the tim module no
 * \param channel Channel index
 * \return Pointer to the TIM channel SRC
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxGtm_Tim_Ch_getSrcPointer(Ifx_GTM *gtm, IfxGtm_Tim tim, IfxGtm_Tim_Ch channel);

/** \brief Test the counter overflow flag
 * \param channel TIM channel pointer
 * \return TRUE if the flag is set, else FALSE
 */
IFX_INLINE boolean IfxGtm_Tim_Ch_isCntOverflowEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Test the data lost flag
 * \param channel TIM channel pointer
 * \return TRUE if the flag is set, else FALSE
 */
IFX_INLINE boolean IfxGtm_Tim_Ch_isDataLostEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Test the event counter overflow flag
 * \param channel TIM channel pointer
 * \return TRUE if the flag is set, else FALSE
 */
IFX_INLINE boolean IfxGtm_Tim_Ch_isEcntOverflowEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Test the glitch flag
 * \param channel TIM channel pointer
 * \return TRUE if the flag is set, else FALSE
 */
IFX_INLINE boolean IfxGtm_Tim_Ch_isGlitchEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Test the new value flag
 * \param channel TIM channel pointer
 * \return TRUE if the flag is set, else FALSE
 */
IFX_INLINE boolean IfxGtm_Tim_Ch_isNewValueEvent(Ifx_GTM_TIM_CH *channel);

/** \brief Returns the pointer to the TIM channel
 * \param tim Pointer to Tim base
 * \param channel TIM channel
 * \return Pointer to TIM channel base
 */
IFX_INLINE Ifx_GTM_TIM_CH *IfxGtm_Tim_getChannel(Ifx_GTM_TIM *tim, IfxGtm_Tim_Ch channel);

/** \brief Reset the specified TIM channel
 * \param tim Pointer to GTM TIM instance
 * \param channel Channel index
 * \return None
 */
IFX_INLINE void IfxGtm_Tim_Ch_resetChannel(Ifx_GTM_TIM *tim, IfxGtm_Tim_Ch channel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the Capture Clock Frequency
 * \param gtm Pointer to GTM module
 * \param channel Pointer to TIM channel base
 * \return Capture clock frequency
 */
IFX_EXTERN float32 IfxGtm_Tim_Ch_getCaptureClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel);

/** \brief Returns the capture clock source selected
 * \param channel TIM channel pointer
 * \return capture clock source
 */
IFX_EXTERN IfxGtm_Cmu_Clk IfxGtm_Tim_Ch_getCaptureClockSource(Ifx_GTM_TIM_CH *channel);

/** \brief Returns the Filter Clock Frequency
 * \param gtm Pointer to GTM module
 * \param channel Pointer to TIM channel base
 * \return Filter clock frequency
 */
IFX_EXTERN float32 IfxGtm_Tim_Ch_getFilterClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel);

/** \brief Returns the Filter clock source selected
 * \param channel TIM channel pointer
 * \return Filter clock source
 */
IFX_EXTERN IfxGtm_Cmu_Tim_Filter_Clk IfxGtm_Tim_Ch_getFilterClockSource(Ifx_GTM_TIM_CH *channel);

/** \brief Returns the Timeout Clock Frequency
 * \param gtm Pointer to GTM module
 * \param channel Pointer to TIM channel base
 * \return Timeout clock frequency
 */
IFX_EXTERN float32 IfxGtm_Tim_Ch_getTimeoutClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TIM_CH *channel);

/** \brief Returns the Timeout clock source selected
 * \param channel TIM channel pointer
 * \return Timeout clock source
 */
IFX_EXTERN IfxGtm_Cmu_Clk IfxGtm_Tim_Ch_getTimeoutClockSource(Ifx_GTM_TIM_CH *channel);

/** \brief Set the channel notification
 * \param channel TIM channel pointer
 * \param irqOnNewVal If TRUE, the interrupt on new value is enabled
 * \param irqOnCntOverflow If TRUE, the interrupt on CNT overflow is enabled
 * \param irqOnEcntOverflow If TRUE, the interrupt on ECNT overflow is enabled
 * \param irqOnDatalost If TRUE, the interrupt on data lost (GPR0, GPR1) is enabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_Ch_setChannelNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnNewVal, boolean irqOnCntOverflow, boolean irqOnEcntOverflow, boolean irqOnDatalost);

/** \brief Set the channel clock source
 * \param channel TIM channel pointer
 * \param clock Selected clock
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_Ch_setClockSource(Ifx_GTM_TIM_CH *channel, IfxGtm_Cmu_Clk clock);

/** \brief Set the filter notification
 * \param channel TIM channel pointer
 * \param irqOnGlitch If TRUE, the interrupt on glitch is enabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_Ch_setFilterNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnGlitch);

/** \brief This function configures the TIM channel IRQ mode
 * \param channel TIM channel pointer
 * \param mode Notification Mode
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_Ch_setNotificationMode(Ifx_GTM_TIM_CH *channel, IfxGtm_IrqMode mode);

/** \brief Set the timeout notification
 * \param channel TIM channel pointer
 * \param irqOnTimeout If TRUE, the interrupt on timeout is enabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tim_Ch_setTimeoutNotification(Ifx_GTM_TIM_CH *channel, boolean irqOnTimeout);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxGtm_Tim_Ch_clearCntOverflowEvent(Ifx_GTM_TIM_CH *channel)
{
    channel->IRQ_NOTIFY.U = 0x1 << IFX_GTM_TIM_CH_IRQ_NOTIFY_CNTOFL_OFF;
}


IFX_INLINE void IfxGtm_Tim_Ch_clearDataLostEvent(Ifx_GTM_TIM_CH *channel)
{
    channel->IRQ_NOTIFY.U = 0x1 << IFX_GTM_TIM_CH_IRQ_NOTIFY_GPROFL_OFF;
}


IFX_INLINE void IfxGtm_Tim_Ch_clearEcntOverflowEvent(Ifx_GTM_TIM_CH *channel)
{
    channel->IRQ_NOTIFY.U = 0x1 << IFX_GTM_TIM_CH_IRQ_NOTIFY_ECNTOFL_OFF;
}


IFX_INLINE void IfxGtm_Tim_Ch_clearGlitchEvent(Ifx_GTM_TIM_CH *channel)
{
    channel->IRQ_NOTIFY.U = 0x1 << IFX_GTM_TIM_CH_IRQ_NOTIFY_GLITCHDET_OFF;
}


IFX_INLINE void IfxGtm_Tim_Ch_clearNewValueEvent(Ifx_GTM_TIM_CH *channel)
{
    channel->IRQ_NOTIFY.U = 0x1 << IFX_GTM_TIM_CH_IRQ_NOTIFY_NEWVAL_OFF;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxGtm_Tim_Ch_getSrcPointer(Ifx_GTM *gtm, IfxGtm_Tim tim, IfxGtm_Tim_Ch channel)
{
    return &MODULE_SRC.GTM.GTM[0].TIM[tim][channel];
}


IFX_INLINE boolean IfxGtm_Tim_Ch_isCntOverflowEvent(Ifx_GTM_TIM_CH *channel)
{
    return channel->IRQ_NOTIFY.B.CNTOFL == 1;
}


IFX_INLINE boolean IfxGtm_Tim_Ch_isDataLostEvent(Ifx_GTM_TIM_CH *channel)
{
    return channel->IRQ_NOTIFY.B.GPROFL == 1;
}


IFX_INLINE boolean IfxGtm_Tim_Ch_isEcntOverflowEvent(Ifx_GTM_TIM_CH *channel)
{
    return channel->IRQ_NOTIFY.B.ECNTOFL == 1;
}


IFX_INLINE boolean IfxGtm_Tim_Ch_isGlitchEvent(Ifx_GTM_TIM_CH *channel)
{
    return channel->IRQ_NOTIFY.B.GLITCHDET == 1;
}


IFX_INLINE boolean IfxGtm_Tim_Ch_isNewValueEvent(Ifx_GTM_TIM_CH *channel)
{
    return channel->IRQ_NOTIFY.B.NEWVAL == 1;
}


IFX_INLINE Ifx_GTM_TIM_CH *IfxGtm_Tim_getChannel(Ifx_GTM_TIM *tim, IfxGtm_Tim_Ch channel)
{
    return (Ifx_GTM_TIM_CH *)((uint32)&tim->CH0.GPR0.U + ((uint32)&tim->CH1 - (uint32)&tim->CH0) * channel);
}


IFX_INLINE void IfxGtm_Tim_Ch_resetChannel(Ifx_GTM_TIM *tim, IfxGtm_Tim_Ch channel)
{
    tim->RST.U |= (uint32)1 << (uint32)channel;
}


#endif /* IFXGTM_TIM_H */
