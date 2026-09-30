/**
 * \file IfxEgtm_Tom.h
 * \brief EGTM  basic functionality
 * \ingroup IfxLld_Egtm
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
 *
 * \defgroup IfxLld_Egtm_Std_Tom Tom Basic Functionality
 * \ingroup IfxLld_Egtm_Std
 * \defgroup IfxLld_Egtm_Std_Tom_Enumerations TOM Enumerations
 * \ingroup IfxLld_Egtm_Std_Tom
 * \defgroup IfxLld_Egtm_Std_Tom_Channel_Functions TOM Channel Functions
 * \ingroup IfxLld_Egtm_Std_Tom
 * \defgroup IfxLld_Egtm_Std_Tom_TGC_Functions TOM TGC Functions
 * \ingroup IfxLld_Egtm_Std_Tom
 * \defgroup IfxLld_Egtm_Std_Tom_Module_Functions TOM Module Functions
 * \ingroup IfxLld_Egtm_Std_Tom
 */

#ifndef IFXEGTM_TOM_H
#define IFXEGTM_TOM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEgtm_cfg.h"
#include "IfxEgtm_bf.h"
#include "IfxEgtm.h"
#include "IfxEgtm_Tbu.h"
#include "Src/Std/IfxSrc.h"
#include "IfxEgtm_Cmu.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of channels per TOM TGC
 */
#define IFXEGTM_TOM_NUM_TGC_CHANNELS (8)

/** \brief Macro to calculate shift for each channel
 * Each channel occupies two bits hence multiply by 2 (left shift by 1) and then add offset
 */
#define IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, offset) ((((uint32)((uint32)channel & 0x7u)) << 1u) + offset)

/** \brief Macro to mask one channel bitfield in TGC registers
 */
#define IFXEGTM_TOM_TGC_CHANNEL_MASK (3u)

/** \brief Macro to calculate channel bitfield value in TGC registers depending on whether it is enabled or not
 */
#define IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled)         ((enabled == TRUE) ? IfxEgtm_FeatureControl_enable : IfxEgtm_FeatureControl_disable)

/** \brief Number of TGC
 */
#define IFXEGTM_TOM_NUM_TGC          (2)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Egtm_Std_Tom_Enumerations
 * \{ */
/** \brief Clock source for the TOM channels
 * Definition in Ifx_EGTM_CLS_TOM_CH_CTRL.B.CLK_SRC
 */
typedef enum
{
    IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk0 = 0,  /**< \brief div 1 */
    IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk1 = 1,  /**< \brief div 16 */
    IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk2 = 2,  /**< \brief div 256 */
    IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk3 = 3,  /**< \brief div 4096 */
    IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk4 = 4,  /**< \brief div 32768 */
    IfxEgtm_Tom_Ch_ClkSrc_noClock   = 5,  /**< \brief no clock */
    IfxEgtm_Tom_Ch_ClkSrc_prevTrig  = 13, /**< \brief TRIG[x-1] trigger from previous channel */
    IfxEgtm_Tom_Ch_ClkSrc_extTrig   = 14  /**< \brief TIM_EXT_CAPTURE */
} IfxEgtm_Tom_Ch_ClkSrc;

/** \brief Reset source for channel counter CN0
 * Definition in Ifx_EGTM_CLS_TOM_CH_CTRL.B.TRIGOUT
 */
typedef enum
{
    IfxEgtm_Tom_Ch_OutputTrigger_forward  = 0, /**< \brief Forward the trigger from the previous channel */
    IfxEgtm_Tom_Ch_OutputTrigger_generate = 1  /**< \brief Generate the trigger from the current channel */
} IfxEgtm_Tom_Ch_OutputTrigger;

/** \brief Reset event for channel counter CN0
 * Definition in Ifx_EGTM_CLS_TOM_CH_CTRL.B.RST_CCU0
 */
typedef enum
{
    IfxEgtm_Tom_Ch_ResetEvent_onCm0     = 0,
    IfxEgtm_Tom_Ch_ResetEvent_onTrigger = 1
} IfxEgtm_Tom_Ch_ResetEvent;

/** \} */

/** \addtogroup IfxLld_Egtm_Std_Tom_Channel_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the channel One notification
 *
 * \param[inout] tom    Pointer to the TOM object
 * \param[in]   channel Channel index
 *                      Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_clearOneNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Clears the channel Zero notification
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_clearZeroNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the base addredd of selected Tom channel
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Pointer to channel base address
 */
IFX_INLINE Ifx_EGTM_CLS_TOM_CH *IfxEgtm_Tom_Ch_getChannelPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the TOM channel input clock frequency in Hz
 *
 * \param[in] egtm    Pointer to EGTM module
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval TOM channel input clock frequency in Hz
 */
IFX_INLINE float32 IfxEgtm_Tom_Ch_getClockFrequency(Ifx_EGTM *egtm, Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the channel clock source
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval The clock source
 * Range: \ref: IfxEgtm_Tom_Ch_ClkSrc
 */
IFX_INLINE IfxEgtm_Tom_Ch_ClkSrc IfxEgtm_Tom_Ch_getClockSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare one value
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Compare one value
 * Range: 0 to 0xFFFF
 *
 */
IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare zero shadow value
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval compare zero shadow value
 * Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareOneShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare one pointer
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval compare one pointer
 */
IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getCompareOnePointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare zero value
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval compare zero value
 * Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare zero shadow value
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval compare zero shadow value
 * Range: 0 to 0xFFFF
 */
IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareZeroShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the compare zero pointer
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval compare zero pointer
 * Range: 0 to 0xFFFF
 */
IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getCompareZeroPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Gets the TOM output level
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval TRUE the output is high, FALSE the output is low
 */
IFX_INLINE boolean IfxEgtm_Tom_Ch_getOutputLevel(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns a pointer to the TOM channel SRC
 *
 * \param[in] egtm    Pointer to EGTM module
 * \param[in] cluster Specifies the Cls
 *                    Range: \ref: IfxEgtm_Cluster
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Pointer to the TOM channel SRC
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxEgtm_Tom_Ch_getSrcPointer(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tom_Ch channel);

/** \brief Returns the TGC pointer
 *
 * \param[in] tom      Pointer to the TOM object
 * \param[in] tgcIndex TGC index
 *                     Range: 0 to 0xFFFFFFFF
 *
 * \retval TOM TGC object pointer
 */
IFX_INLINE Ifx_EGTM_CLS_TOM_TGC *IfxEgtm_Tom_Ch_getTgcPointer(Ifx_EGTM_CLS_TOM *tom, uint32 tgcIndex);

/** \brief Returns the Timer pointer
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Timer pointer
 */
IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getTimerPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the status of channel One notification
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval TRUE If CCU1 Trigger condition interrupt is active for the specified channel.
 *         FALSE If CCU1 Trigger condition interrupt is not active for the specified channel.
 */
IFX_INLINE boolean IfxEgtm_Tom_Ch_isOneNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Returns the status of channel Zero notification
 *
 * \param[in] tom     Pointer to the TOM object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval TRUE If CCU0 Trigger condition interrupt is active for the specified channel.
 *         FALSE If CCU0 Trigger condition interrupt is not active for the specified channel.
 */
IFX_INLINE boolean IfxEgtm_Tom_Ch_isZeroNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Raises the interrupt for Compare 1
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]   channel  Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_raiseInterruptOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Raises the interrupt for Compare 0
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_raiseInterruptZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Sets the channel clock source
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    clk     Channel clock source
 *                       Range: \ref: IfxEgtm_Tom_Ch_ClkSrc
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setClockSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_ClkSrc clk);

/** \brief Sets the compare 0 and 1 values
 *
 * \param[inout] tom         Pointer to the TOM object
 * \param[in]    channel     Channel index
 *                           Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    compareZero Compare zero value
 *                           Range: 0 to 0xFFFF
 * \param[in]    compareOne  Compare one value
 *                           Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompare(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareZero, uint16 compareOne);

/** \brief Sets the compare 1 value
 *
 * \param[inout] tom        Pointer to the TOM object
 * \param[in]    channel    Channel index
 *                          Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    compareOne Compare one value
 *                          Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompareOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareOne);

/** \brief Sets the compare 1 shadow value
 *
 * \param[in] tom       Pointer to the TOM object
 * \param[in] channel   Channel index
 *                      Range: \ref: IfxEgtm_Tom_Ch
 * \param[in] shadowOne Compare one shadow value
 *                      Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompareOneShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowOne);

/** \brief Sets the compare 0 and 1 shadow values
 *
 * \param[inout] tom        Pointer to the TOM object
 * \param[in]    channel    Channel index
 *                          Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    shadowZero Compare zero shadow value
 *                          Range: 0 to 0xFFFF
 * \param[in]    shadowOne  Compare one shadow value
 *                          Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompareShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowZero, uint16 shadowOne);

/** \brief Sets the compare 0 value
 *
 * \param[inout] tom         Pointer to the TOM object
 * \param[in]    channel     Channel index
 *                           Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    compareZero Compare zero value
 *                           Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompareZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareZero);

/** \brief Sets the compare 0 shadow value
 *
 * \param[inout] tom        Pointer to the TOM object
 * \param[in]    channel    Channel index
 *                          Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    shadowZero Compare zero shadow value
 *                          Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCompareZeroShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowZero);

/** \brief Sets the counter value
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    value   Counter value
 *                       Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setCounterValue(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint32 value);

/** \brief Enable/disable the gated counter mode (channel 0 to 7 only)
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled If TRUE, Gated Counter Mode enabled, If FALSE Gated Counter Mode disabled.
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setGatedCounter(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled);

/** \brief Sets the channel notification
 *
 * \param[inout] tom                    Pointer to the TOM object
 * \param[in]    channel                Channel index
 *                                      Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    mode                   Interrupt mode
 *                                      Range: \ref: IfxEgtm_IrqMode
 * \param[in]    interruptOnCompareZero If TRUE, an interrupt is generated on compare 0, else no interrupt is generated
 * \param[in]    interruptOnCompareOne  If TRUE, an interrupt is generated on compare 1, else no interrupt is generated
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_IrqMode mode, boolean interruptOnCompareZero, boolean interruptOnCompareOne);

/** \brief Enable/disable the one shot mode
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 * \param[in]    enabled If TRUE, One-shot mode enabled, FALSE One-shot mode disabled
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setOneShotMode(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled);

/** \brief Enable/disable the PCM mode (channel 15 only)
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled If TRUE, the feature is enabled, else disabled
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setPcm(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled);

/** \brief Sets the channel clock source either from local or from previous channel
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    event   Channel reset event
 *                       Range: \ref: IfxEgtm_Tom_Ch_ResetEvent
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setResetSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_ResetEvent event);

/** \brief Sets the signal level
 *
 * \param[inout] tom         Pointer to the TOM object
 * \param[in]    channel     Channel index
 *                           Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    activeState Signal level active state. In case the channel is reset, the output is set to not active. The signal is active between 0 and the leading edge (CM1) and inactive between the leading edge and the trailing edge (CM0).
 *                           Range: \ref: Ifx_ActiveState
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setSignalLevel(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, Ifx_ActiveState activeState);

/** \brief Enable/disable the SPE mode (channel 0 to 7 only)
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled If TRUE, SPE output mode enabled: TOM_OUT [x:x] is defined by TOM[i]_SPE_OUT [x:x]
 *                          FALSE, SPE output mode disabled: TOM_OUT [x:x] is defined by TOM[i]_SPE_OUT [x:x]
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setSpe(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled);

/** \brief Sets the channel trigger output
 *
 * \param[inout] tom     Pointer to the TOM object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    trigger Channel trigger output mode
 *                       Range: \ref: IfxEgtm_Tom_Ch_OutputTrigger
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Ch_setTriggerOutput(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_OutputTrigger trigger);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Get configured frequency of PWM channel
 * Note: This API does not work if channel 0 counter is reset by external trigger. API will cause a trap in such a case.
 *
 * \param[in] tom     Pointer to TOM subcluster SFR
 * \param[in] channel TOM channel numer
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Channel frequency in Hz
 */
IFX_EXTERN float32 IfxEgtm_Tom_Ch_getFrequency(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \brief Get configured duty of PWM channel
 * Note: This API does not work if channel 0 counter is reset by external trigger. API will cause a trap in such a case.
 *
 * \param[in] tom     Pointer to TOM subcluster SFR
 * \param[in] channel TOM channel numer
 *                    Range: \ref: IfxEgtm_Tom_Ch
 *
 * \retval Channel duty in percentage [0-100%]
 */
IFX_EXTERN float32 IfxEgtm_Tom_Ch_getDuty(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel);

/** \} */

/** \addtogroup IfxLld_Egtm_Std_Tom_TGC_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Enable/disable one channel (ENDIS)
 *
 * \param[inout] tgc       Pointer to the TGC object
 * \param[in]    channel   Channel index
 *                         Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled   Enable/ Disable choice of the feature
 * \param[in]    immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannel(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean immediate);

/** \brief Enable/disable one channel output (OUTEN)
 *
 * \param[inout] tgc       Pointer to the TGC object
 * \param[in]    channel   Channel index
 *                         Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled   Enable/ Disable choice of the feature
 * \param[in]    immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelOutput(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean immediate);

/** \brief Enable/disable one channel for update (UPEN)
 *
 * \param[inout] tgc     Pointer to the TGC object
 * \param[in]    channel Channel index
 *                       Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled Enable/ Disable choice of the feature
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled);

/** \brief Enable/disable one or more channels (ENDIS)
 *
 * \param[inout] tgc         Pointer to the TGC object
 * \param[in]    enableMask  Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    disableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    immediate   If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannels(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate);

/** \brief Enable/disable one or more channels output (OUTEN)
 *
 * \param[inout] tgc         Pointer to the TGC object
 * \param[in]    enableMask  Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    immediate   If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsOutput(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate);

/** \brief Enable/disable the TGC channels trigger
 *
 * \param[inout] tgc         Pointer to the TGC object
 * \param[in]    enableMask  Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask);

/** \brief Enable/disable one or more channels for update (UPEN)
 *
 * \param[inout] tgc         Pointer to the TGC object
 * \param[in]    enableMask  Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in]    disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask);

/** \brief Enable/disable the time base trigger
 *
 * \param[inout] tgc     Pointer to the TGC object
 * \param[in]    enabled If TRUE, the trigger is enabled else disabled
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_enableTimeTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, boolean enabled);

/** \brief Reset one or more channels
 *
 * \param[inout] tgc      Pointer to the TGC object
 * \param[in]   resetMask Mask for the channel reset (bit 0: Channel 0, bit 1: channel 1, ...)
 *                        Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_resetChannels(Ifx_EGTM_CLS_TOM_TGC *tgc, uint32 resetMask);

/** \brief Enable/disable one channel for update (FUPD)
 *
 * \param[inout] tgc          Pointer to the TGC object
 * \param[in]    channel      Channel index
 *                            Range: \ref: IfxEgtm_Tom_Ch
 * \param[in]    enabled      Enable/ Disable choice of the feature
 * \param[in]    resetEnabled Enable/ Disable reset choice of the feature
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_setChannelForceUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean resetEnabled);

/** \brief Enable/disable one or more channels for the force update feature (FUPD)
 *
 * \param[inout] tgc              Pointer to the TGC object
 * \param[in]    enableMask       Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                                Range: 0 to 0xFFFF
 * \param[in]    disableMask      Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                                Range: 0 to 0xFFFF
 * \param[in]    resetEnableMask  Mask for the enabled channels counter reset on force update (bit 0: Channel 0, bit 1: channel 1, ...) Channel 0, bit 1: channel 1, ...)
 *                                Range: 0 to 0xFFFF
 * \param[in]    resetDisableMask Mask for the disabled channels with no counter reset on force update (bit 0: Channel 0, bit 1: channel 1, ...)
 *                                Range: 0 to 0xFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_setChannelsForceUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, uint16 resetEnableMask, uint16 resetDisableMask);

/** \brief Sets the trigger time base and time base value
 *
 * \param[inout] tgc   Pointer to the TGC object
 * \param[in]    base  Time base used for comparison
 *                     Range: \ref: IfxEgtm_Tbu_Ts
 * \param[in]    value Compare value that raise the trigger
 *                     Range: 0 to 0x00FFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_setTimeTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tbu_Ts base, uint32 value);

/** \brief Raise the trigger for the channel enable/disable settings,  output enable settings, and force update event (CTRL_TRIG)
 *
 * \param[inout] tgc Pointer to the TGC object
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_trigger(Ifx_EGTM_CLS_TOM_TGC *tgc);

/** \brief Sets the tgc global control value
 *
 * \param[inout] tgc    Pointer to the TGC object
 * \param[in]   control Global control value
 *                      Range: 0 to 0xFFFFFF01
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_writeGlobalControl(Ifx_EGTM_CLS_TOM_TGC *tgc, uint32 control);

/** \brief Enable/disable the TGC channel trigger
 *
 * \param[in] tgc     Pointer to the TGC object
 * \param[in] channel Channel index
 *                    Range: \ref: IfxEgtm_Tom_Ch
 * \param[in] enabled Enable/ Disable choice of the feature
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_Tgc_setInternalTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Builds the register value for the feature enable/disable
 *
 * \param[in] enableMask     Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in] disableMask    Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 *                           Range: 0 to 0xFFFF
 * \param[in] bitfieldOffset Offset of the channel 0 bitfield in the register
 *                           Range: 0 to 0xFF
 *
 * \retval The register value
 * Range: 0 to 0xFFFF
 */
IFX_EXTERN uint32 IfxEgtm_Tom_Tgc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset);

/** \brief Builds the register value for the feature enable/disable for a single channel
 *
 * \param[in] channel        Channel index
 *                           Range: \ref: IfxEgtm_Tom_Ch
 * \param[in] enabled        Enable/ Disable choice of the feature
 * \param[in] bitfieldOffset Offset of the channel 0 bitfield in the register
 *                           Range: 0 to 0xFF
 *
 * \retval The register value
 * Range: 0 to 0xFFFF
 */
IFX_EXTERN uint32 IfxEgtm_Tom_Tgc_buildFeatureForChannel(IfxEgtm_Tom_Ch channel, boolean enabled, uint8 bitfieldOffset);

/** \} */

/** \addtogroup IfxLld_Egtm_Std_Tom_Module_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Configures the tout selection
 *
 * \param[in] toutNum TOUT number
 *                    Range: 0 to 0xFFFFFFFF
 * \param[in] toutSel TOUTselection
 *                    Range: 0 to 0xFFFFFFFF
 *
 * \retval None
 */
IFX_INLINE void IfxEgtm_Tom_setTout(uint32 toutNum, uint32 toutSel);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxEgtm_Tom_Ch_clearOneNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    tom->CH[channel].IRQ_NOTIFY.B.CCU1TC = 1u;
}


IFX_INLINE void IfxEgtm_Tom_Ch_clearZeroNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    tom->CH[channel].IRQ_NOTIFY.B.CCU0TC = 1u;
}


IFX_INLINE Ifx_EGTM_CLS_TOM_CH *IfxEgtm_Tom_Ch_getChannelPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (Ifx_EGTM_CLS_TOM_CH *)((uint32)&tom->CH[channel].CTRL.U);
}


IFX_INLINE float32 IfxEgtm_Tom_Ch_getClockFrequency(Ifx_EGTM *egtm, Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    IfxEgtm_Tom_Ch_ClkSrc clk;
    IfxEgtm_Cmu_Fxclk     clkIndex[5] = {
        IfxEgtm_Cmu_Fxclk_0,      /*IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk0 */
        IfxEgtm_Cmu_Fxclk_1,      /*IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk1 */
        IfxEgtm_Cmu_Fxclk_2,      /*IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk2 */
        IfxEgtm_Cmu_Fxclk_3,      /*IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk3 */
        IfxEgtm_Cmu_Fxclk_4       /*IfxEgtm_Tom_Ch_ClkSrc_cmuFxclk4 */
    };

    clk = IfxEgtm_Tom_Ch_getClockSource(tom, channel);

    if (clk == IfxEgtm_Tom_Ch_ClkSrc_noClock)
    {
        return (float32)0.0f;
    }
    else
    {
        return IfxEgtm_Cmu_getFxClkFrequency(egtm, clkIndex[clk], TRUE);
    }
}


IFX_INLINE IfxEgtm_Tom_Ch_ClkSrc IfxEgtm_Tom_Ch_getClockSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    IfxEgtm_Tom_Ch_ClkSrc clk = IfxEgtm_Tom_Ch_ClkSrc_noClock;

    clk = (IfxEgtm_Tom_Ch_ClkSrc)(tom->CH[channel].CTRL.B.CLK_SRC);

    return clk;
}


IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (uint16)(tom->CH[channel].CM1.U);
}


IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareOneShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (uint16)tom->CH[channel].SR1.U;
}


IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getCompareOnePointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (volatile uint32 *)(volatile void *)&(tom->CH[channel].CM1.U);
}


IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (uint16)(tom->CH[channel].CM0.U);
}


IFX_INLINE uint16 IfxEgtm_Tom_Ch_getCompareZeroShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (uint16)tom->CH[channel].SR0.U;
}


IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getCompareZeroPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (volatile uint32 *)(volatile void *)&(tom->CH[channel].CM0.U);
}


IFX_INLINE boolean IfxEgtm_Tom_Ch_getOutputLevel(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    boolean level;
    level = (tom->CH[channel].STAT.B.OL == 1u) ? TRUE : FALSE;
    return level;
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxEgtm_Tom_Ch_getSrcPointer(Ifx_EGTM *egtm, IfxEgtm_Cluster cluster, IfxEgtm_Tom_Ch channel)
{
    IFX_UNUSED_PARAMETER(egtm)
    return &MODULE_SRC.EGTM.TOM[cluster].SR[channel >> 1u];
}


IFX_INLINE Ifx_EGTM_CLS_TOM_TGC *IfxEgtm_Tom_Ch_getTgcPointer(Ifx_EGTM_CLS_TOM *tom, uint32 tgcIndex)
{
    Ifx_EGTM_CLS_TOM_TGC *pointer = (Ifx_EGTM_CLS_TOM_TGC *)(volatile void *)&tom->TGC[tgcIndex].GLB_CTRL;
    return pointer;
}


IFX_INLINE volatile uint32 *IfxEgtm_Tom_Ch_getTimerPointer(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    return (volatile uint32 *)(volatile void *)&(tom->CH[channel].CN0.U);
}


IFX_INLINE boolean IfxEgtm_Tom_Ch_isOneNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    boolean notify;
    notify = (tom->CH[channel].IRQ_NOTIFY.B.CCU1TC != 0u) ? TRUE : FALSE;
    return notify;
}


IFX_INLINE boolean IfxEgtm_Tom_Ch_isZeroNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    boolean notify;
    notify = (tom->CH[channel].IRQ_NOTIFY.B.CCU0TC != 0u) ? TRUE : FALSE;
    return notify;
}


IFX_INLINE void IfxEgtm_Tom_Ch_raiseInterruptOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    tom->CH[channel].IRQ_FORCINT.B.TRG_CCU1TC = 1u;
}


IFX_INLINE void IfxEgtm_Tom_Ch_raiseInterruptZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel)
{
    tom->CH[channel].IRQ_FORCINT.B.TRG_CCU0TC = 1u;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setClockSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_ClkSrc clk)
{
    tom->CH[channel].CTRL.B.CLK_SRC       = (uint8)clk;
    tom->CH[channel].CTRL_SR.B.CLK_SRC_SR = (uint8)clk;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompare(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareZero, uint16 compareOne)
{
    tom->CH[channel].CM0.U = compareZero;
    tom->CH[channel].CM1.U = compareOne;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompareOne(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareOne)
{
    tom->CH[channel].CM1.U = compareOne;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompareOneShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowOne)
{
    tom->CH[channel].SR1.U = shadowOne;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompareShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowZero, uint16 shadowOne)
{
    tom->CH[channel].SR0.U = shadowZero;
    tom->CH[channel].SR1.U = shadowOne;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompareZero(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 compareZero)
{
    tom->CH[channel].CM0.U = compareZero;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCompareZeroShadow(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint16 shadowZero)
{
    tom->CH[channel].SR0.U = shadowZero;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setCounterValue(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, uint32 value)
{
    tom->CH[channel].CN0.U = value;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setGatedCounter(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    if (channel <= IfxEgtm_Tom_Ch_7)
    {
        tom->CH[channel].CTRL.B.GCM = (uint8)enabled;
    }
}


IFX_INLINE void IfxEgtm_Tom_Ch_setNotification(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_IrqMode mode, boolean interruptOnCompareZero, boolean interruptOnCompareOne)
{
    Ifx_EGTM_CLS_TOM_CH       *tomCh = &(tom->CH[channel]);

    /* Prepare new values */
    Ifx_EGTM_CLS_TOM_CH_IRQ_EN en;
    en.B.CCU0TC_IRQ_EN         = interruptOnCompareZero;
    en.B.CCU1TC_IRQ_EN         = interruptOnCompareOne;

    tomCh->IRQ_EN.U            = 0u;          /* Disable all interrupts of the interrupt set to change mode */
    tomCh->IRQ_MODE.B.IRQ_MODE = (uint8)mode; /* Change mode */
    tomCh->IRQ_EN.U            = en.U;        /* Set the new values */
}


IFX_INLINE void IfxEgtm_Tom_Ch_setOneShotMode(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    tom->CH[channel].CTRL.B.OSM = (uint8)enabled;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setPcm(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    if (channel == IfxEgtm_Tom_Ch_15)
    {
        tom->CH[15].CTRL.B.BITREV = (uint8)enabled;
    }
}


IFX_INLINE void IfxEgtm_Tom_Ch_setResetSource(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_ResetEvent event)
{
    tom->CH[channel].CTRL.B.RST_CCU0 = (uint8)event;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setSignalLevel(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, Ifx_ActiveState activeState)
{
    tom->CH[channel].CTRL.B.SL       = (uint8)activeState;
    tom->CH[channel].CTRL_SR.B.SL_SR = (uint8)activeState;
}


IFX_INLINE void IfxEgtm_Tom_Ch_setSpe(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    if (channel <= IfxEgtm_Tom_Ch_7)
    {
        tom->CH[channel].CTRL.B.SPEM = (uint8)enabled;
    }
}


IFX_INLINE void IfxEgtm_Tom_Ch_setTriggerOutput(Ifx_EGTM_CLS_TOM *tom, IfxEgtm_Tom_Ch channel, IfxEgtm_Tom_Ch_OutputTrigger trigger)
{
    tom->CH[channel].CTRL.B.TRIGOUT = (uint8)trigger;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannel(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 shift = IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF);
    uint32 value = (uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled) << shift;
    uint32 mask  = (uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift;

    Ifx__ldmst(&(tgc->ENDIS_CTRL.U), mask, value);

    if (immediate == TRUE)
    {
        Ifx__ldmst(&(tgc->ENDIS_STAT.U), mask, value);
    }
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelOutput(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean immediate)
{
    uint32 shift = IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF);
    uint32 value = (uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled) << shift;
    uint32 mask  = (uint32)((uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift);

    Ifx__ldmst(&(tgc->OUTEN_CTRL.U), mask, value);

    if (immediate == TRUE)
    {
        Ifx__ldmst(&(tgc->OUTEN_STAT.U), mask, value);
    }
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    uint32 shift = IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF);
    uint32 value = (uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled) << shift;
    uint32 mask  = (uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift;

    Ifx__ldmst(&(tgc->GLB_CTRL.U), mask, value);
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannels(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    value             = IfxEgtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_EGTM_CLS_TOM_TGC_ENDIS_CTRL_ENDIS_CTRL0_OFF);

    tgc->ENDIS_CTRL.U = value;

    if (immediate == TRUE)
    {
        tgc->ENDIS_STAT.U = value;
    }
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsOutput(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate)
{
    uint32 value;

    value             = IfxEgtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_EGTM_CLS_TOM_TGC_OUTEN_CTRL_OUTEN_CTRL0_OFF);

    tgc->OUTEN_CTRL.U = value;

    if (immediate == TRUE)
    {
        tgc->OUTEN_STAT.U = value;
    }
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask)
{
    tgc->INT_TRIG.U = IfxEgtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_EGTM_CLS_TOM_TGC_INT_TRIG_INT_TRIG0_OFF);
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableChannelsUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask)
{
    tgc->GLB_CTRL.U = IfxEgtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_EGTM_CLS_TOM_TGC_GLB_CTRL_UPEN_CTRL0_OFF);
}


IFX_INLINE void IfxEgtm_Tom_Tgc_enableTimeTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, boolean enabled)
{
    tgc->ACT_TB.B.TB_TRIG = (uint8)enabled;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_resetChannels(Ifx_EGTM_CLS_TOM_TGC *tgc, uint32 resetMask)
{
    uint8  i;
    uint32 reg = 0u;

    for (i = 0u; i < IFXEGTM_TOM_NUM_TGC_CHANNELS; i++)
    {
        if ((resetMask & 0x1u) == 0x1u)
        {
            reg |= (uint32)((uint32)1u << i);
        }

        resetMask = resetMask >> 1u;
    }

    tgc->GLB_CTRL.U = reg << IFX_EGTM_CLS_TOM_TGC_GLB_CTRL_RST_CH0_OFF;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_setChannelForceUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled, boolean resetEnabled)
{
    uint32 shift = IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF);
    uint32 value = (uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled) << shift;
    uint32 mask  = (uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift;

    shift = (uint32)IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF);
    value = value | (uint32)((uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(resetEnabled) << shift);
    mask  = mask | (uint32)((uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift);

    Ifx__ldmst(&(tgc->FUPD_CTRL.U), mask, value);
}


IFX_INLINE void IfxEgtm_Tom_Tgc_setChannelsForceUpdate(Ifx_EGTM_CLS_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, uint16 resetEnableMask, uint16 resetDisableMask)
{
    uint32 regEnable, regReset;

    regEnable        = IfxEgtm_Tom_Tgc_buildFeature(enableMask, disableMask, IFX_EGTM_CLS_TOM_TGC_FUPD_CTRL_FUPD_CTRL0_OFF);
    regReset         = IfxEgtm_Tom_Tgc_buildFeature(resetEnableMask, resetDisableMask, IFX_EGTM_CLS_TOM_TGC_FUPD_CTRL_RSTCN0_CH0_OFF);

    tgc->FUPD_CTRL.U = regEnable | regReset;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_setTimeTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tbu_Ts base, uint32 value)
{
    Ifx_EGTM_CLS_TOM_TGC_ACT_TB act_tb;

    act_tb.U         = tgc->ACT_TB.U;
    act_tb.B.TBU_SEL = (uint8)base;
    act_tb.B.ACT_TB  = value;
    tgc->ACT_TB.U    = act_tb.U;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_trigger(Ifx_EGTM_CLS_TOM_TGC *tgc)
{
    tgc->GLB_CTRL.B.HOST_TRIG = 1u;
}


IFX_INLINE void IfxEgtm_Tom_Tgc_writeGlobalControl(Ifx_EGTM_CLS_TOM_TGC *tgc, uint32 control)
{
    tgc->GLB_CTRL.U = control;
}


IFX_INLINE void IfxEgtm_Tom_setTout(uint32 toutNum, uint32 toutSel)
{
    uint32 outselReg = (toutNum / 6u);
    uint32 shift     = (toutNum % 6u) * 5u;

    if (shift >= 15)
    {
        ++shift;
    }

    uint32 outsel = toutSel << shift;
    uint32 mask   = (uint32)((uint32)0x1FU << shift);

    Ifx__ldmst(&(MODULE_EGTM.TOUTSEL[outselReg].U), mask, outsel);
}


IFX_INLINE void IfxEgtm_Tom_Tgc_setInternalTrigger(Ifx_EGTM_CLS_TOM_TGC *tgc, IfxEgtm_Tom_Ch channel, boolean enabled)
{
    uint32 shift = IFXEGTM_TOM_TGC_CHANNEL_SHIFT(channel, IFX_EGTM_CLS_TOM_TGC_INT_TRIG_INT_TRIG0_OFF);
    uint32 value = (uint32)IFXEGTM_TOM_TGC_CHANNEL_VALUE(enabled) << shift;
    uint32 mask  = (uint32)IFXEGTM_TOM_TGC_CHANNEL_MASK << shift;

    Ifx__ldmst(&(tgc->INT_TRIG.U), mask, value);
}


#endif /* IFXEGTM_TOM_H */
