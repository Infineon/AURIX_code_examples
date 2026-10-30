/**
 * \file IfxHspdm.h
 * \brief HSPDM  basic functionality
 * \ingroup IfxLld_Hspdm
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
 *
 * \defgroup IfxLld_Hspdm_Std_Usage How to use the Hspdm Interface driver?
 * \ingroup IfxLld_Hspdm_Std
 *
 * The HSPDM is intended to generate up to two 1-bit bit-streams. Each bit-stream represents the 16-bit data stored
 * inside the dedicated 8 KB SRAM. This bit-stream is a pulse-density modulated (PDM) bit-stream which can be
 * averaged outside the microcontroller using a low pass filter (LPF) to generate the analog voltage.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_Hspdm_Std_Preparation Preparation
 * \subsection IfxLld_Hspdm_Std_Include Include Files
 *
 * Include following header file into your C code:
 *
 * \code
 * #include <Hspdm/Std/IfxHspdm.h>
 * #include <Port/Std/IfxPort.h>
 * \endcode
 *
 * \subsection IfxLld_Hspdm_Std_Variables Variables
 *
 * The following buffer are declared globally
 * \code
 * const unsigned hspdmPatternA[19] = {
 *    0x00018000,
 *    0x0003c000,
 *    0x0007e000,
 *    0x000ff000,
 *    0x001ff800,
 *    0x003ffc00,
 *    0x007ffe00,
 *    0x00ffff00,
 *    0x01ffff80,
 *    0x03ffffc0,
 *    0x01ffff80,
 *    0x00ffff00,
 *    0x007ffe00,
 *    0x003ffc00,
 *    0x001ff800,
 *    0x000ff000,
 *    0x0007e000,
 *    0x0003c000,
 *    0x00018000
 *  };
 * \endcode
 *
 * The following Macros into your C code:
 * \code
 *    #define WAIT_TIME   100
 * \endcode
 *
 * \subsection IfxLld_Hspdm_Std_Init Module Initialisation
 *
 * The High Speed Pulse Density Modulation (HSPDM) is configured in Single buffer mode.
 *
 * Initialize the Hspdm with following code:
 * \code
 *  // Enable HSPDM pins
 *  IfxHspdm_initBsPin(&IfxHspdm0_BS0_OUT_P22_4_OUT, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 *  IfxHspdm_initBsPin(&IfxHspdm0_BS1_OUT_P22_5_OUT, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 *  IfxHspdm_initMutePin(&IfxHspdm0_MUTE_P22_3_OUT, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
 *
 *  // Init HSPDM
 *  Ifx_HSPDM *hspdm = &MODULE_HSPDM;
 *  IfxHspdm_enableModule(hspdm);
 *
 *  // Update frequency must be Fupd/10 in Shift Register Generated Bit Stream mode
 *  IfxHspdm_setUpdateFreq(hspdm, IfxHspdm_UpdateFreq_10MHz);
 *
 *  // Enable both Bit Streams
 *  IfxHspdm_enableBSB(hspdm, IfxHspdm_BSB_0, TRUE);
 *  IfxHspdm_enableBSB(hspdm, IfxHspdm_BSB_1, TRUE);
 *
 *  // Select the Shift Register Bit Streaming mode
 *  IfxHspdm_setStreamingMode(hspdm, IfxHspdm_StreamingMode_shiftRegister);
 *
 *  // Select the Single Buffer mode
 *  IfxHspdm_setBufferMode(hspdm, IfxHspdm_BufferMode_singleBuffer);
 *
 *  // Enable the ADC Trigger Generation to signal the start of the stream output
 *  IfxHspdm_enableAdcTrigger(hspdm);
 *
 *  // Configure the ADC Trigger generator to create just one trigger
 *  IfxHspdm_setAdcTriggerOffset(hspdm, 0); // No Trigger offset
 *  IfxHspdm_setAdcTriggerCounts(hspdm, 0); // Only 1 Trigger per Ramp
 * \endcode
 *
 * The Hspdm is ready for use now!
 *
 * \subsection IfxLld_Hspdm_Std_Bit_Streaming  Send different bitstream patterns.
 *
 * This example is used to send different bitstream patterns.
 * \code
 *  Ifx_HSPDM *hspdm = &MODULE_HSPDM;
 *  unsigned volatile *hspdmRam = (unsigned volatile *)HSPDM_SRAM;
 *
 *  // Preload buffer and set start/end address
 *  unsigned *pattern = (unsigned *)hspdmPatternA;
 *  unsigned patternSize = sizeof(hspdmPatternA) / 4;
 *
 *  for(unsigned i=0; i<patternSize; ++i) {
 *  	*(hspdmRam++) = *(pattern++); }
 *  IfxHspdm_setStartAddress(hspdm, IfxHspdm_Buffer_a, 0*4);
 *  IfxHspdm_setEndAddress(hspdm, IfxHspdm_Buffer_a, (patternSize-1) * 4);
 *
 *  // Start stream, run for 100 uS
 *  IfxHspdm_startBitStream(hspdm);
 *  waitTime(IfxStm_getTicksFromMicroseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    // Wait 100 microseconds
 *  IfxHspdm_stopBitStream(hspdm);
 * \endcode
 *
 * \defgroup IfxLld_Hspdm_Std_Enumerations Enumerations
 * \ingroup IfxLld_Hspdm_Std
 * \defgroup IfxLld_Hspdm_Std_Configuration Configuration Functions
 * \ingroup IfxLld_Hspdm_Std
 * \defgroup IfxLld_Hspdm_Std_Operative Operative Functions
 * \ingroup IfxLld_Hspdm_Std
 * \defgroup IfxLld_Hspdm_Std_Utility Utility Functions
 * \ingroup IfxLld_Hspdm_Std
 */

#ifndef IFXHSPDM_H
#define IFXHSPDM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxHspdm_cfg.h"
#include "IfxHspdm_reg.h"
#include "_Utilities/Ifx_Assert.h"
#include "_PinMap/IfxHspdm_PinMap.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Hspdm_Std_Enumerations
 * \{ */
/** \brief Bit streaming blocks.
 */
typedef enum
{
    IfxHspdm_BSB_0 = 0,  /**< \brief Bit Streaming Block 0 */
    IfxHspdm_BSB_1 = 1   /**< \brief Bit Streaming Block 1 */
} IfxHspdm_BSB;

/** \brief specifies the buffer.
 */
typedef enum
{
    IfxHspdm_Buffer_a           = 0, /**< \brief Buffer A */
    IfxHspdm_Buffer_b           = 1, /**< \brief Buffer B */
    IfxHspdm_Buffer_bufferCount = 2  /**< \brief number of buffers */
} IfxHspdm_Buffer;

/** \brief buffer modes.\n
 * Definition in Ifx_Hspdm.CON.MM
 */
typedef enum
{
    IfxHspdm_BufferMode_singleBuffer = 0,  /**< \brief single buffer mode */
    IfxHspdm_BufferMode_dualBuffer   = 1   /**< \brief dual buffer mode */
} IfxHspdm_BufferMode;

/** \brief Dither level values.\n
 * Definition in Ifx_Hspdm.CON.DITH
 */
typedef enum
{
    IfxHspdm_DitherLevel_disabled   = 0,  /**< \brief disable dither (default) */
    IfxHspdm_DitherLevel_minimum    = 1,  /**< \brief Minimum Dither level */
    IfxHspdm_DitherLevel_low        = 2,  /**< \brief Low Dither Level */
    IfxHspdm_DitherLevel_lowMedium  = 3,  /**< \brief Low-Medium Dither */
    IfxHspdm_DitherLevel_medium     = 4,  /**< \brief Medium Dither Level */
    IfxHspdm_DitherLevel_mediumHigh = 5,  /**< \brief Medium High Dither */
    IfxHspdm_DitherLevel_high       = 6,  /**< \brief High Dither Level */
    IfxHspdm_DitherLevel_highest    = 7   /**< \brief Highest Dither level */
} IfxHspdm_DitherLevel;

/** \brief enumeration holding event flags of HSPDM.\n
 * Definition in IfxHspdm.FLAGSSET, IfxHspdm.FLAGSCLEAR, IfxHspdm.FLAGSEN
 */
typedef enum
{
    IfxHspdm_Flag_buffAStart  = 0, /**< \brief buffer A start flag */
    IfxHspdm_Flag_buffAEnd    = 1, /**< \brief Buffer A End flag */
    IfxHspdm_Flag_buffBStart  = 2, /**< \brief Buffer B Start flag */
    IfxHspdm_Flag_buffBEnd    = 3, /**< \brief Buffer B flag */
    IfxHspdm_Flag_mute0Start  = 4, /**< \brief Mute 0 start flag */
    IfxHspdm_Flag_mute0End    = 5, /**< \brief Mute 0 End flag */
    IfxHspdm_Flag_mute1Start  = 6, /**< \brief Mute 1 start flag */
    IfxHspdm_Flag_mute1End    = 7, /**< \brief Mute 1 end flag */
    IfxHspdm_Flag_ramOverflow = 8  /**< \brief Ram overflow error flag */
} IfxHspdm_Flag;

/** \brief active edge which triggers the HSPDM.\n
 * Definition in IfxHspdm.CON.HRAE.
 */
typedef enum
{
    IfxHspdm_HwRunActiveEdge_rising  = 0, /**< \brief Rising edge is active edge */
    IfxHspdm_HwRunActiveEdge_falling = 1  /**< \brief Falling edge is active edge */
} IfxHspdm_HwRunActiveEdge;

/** \brief mute signal polarity.\n
 * Definition in IfxHspdm.CON.MPOL
 */
typedef enum
{
    IfxHspdm_MutePolarity_activeHigh = 0,  /**< \brief active high */
    IfxHspdm_MutePolarity_activeLow  = 1   /**< \brief active low */
} IfxHspdm_MutePolarity;

/** \brief HSPDM running status.\n
 * Definition in IfxHspdm.CON.RUN
 */
typedef enum
{
    IfxHspdm_RunState_stopped = 0,  /**< \brief hspdm is stopped */
    IfxHspdm_RunState_running = 1   /**< \brief Hspdm is running */
} IfxHspdm_RunState;

/** \brief Sleep Modes.\n
 * Definition in IfxHspdm.CLC.B.EDIS
 */
typedef enum
{
    IfxHspdm_SleepMode_enabled  = 0, /**< \brief sleep mode enabled. */
    IfxHspdm_SleepMode_disabled = 1  /**< \brief sleep mode disabled. */
} IfxHspdm_SleepMode;

/** \brief Streaming modes available at HSPDM.\n
 * Definition in IfxHspdm.CON.SM
 */
typedef enum
{
    IfxHspdm_StreamingMode_deltaSigmaCICEnabled  = 0,  /**< \brief Delta Sigma with CIC and compactor enabled (default) */
    IfxHspdm_StreamingMode_deltaSigmaCICDisabled = 1,  /**< \brief Delta-Sigma with CIC and compactor disabled */
    IfxHspdm_StreamingMode_shiftRegister         = 2   /**< \brief Shift Register generated */
} IfxHspdm_StreamingMode;

/** \brief OCDS suspend Modes.\n
 * used to set IfxHspdm.OCS.B.SUS
 */
typedef enum
{
    IfxHspdm_SuspendMode_none = 0,  /**< \brief wil not suspend */
    IfxHspdm_SuspendMode_hard = 1,  /**< \brief hard suspend. Clock Switched Off. */
    IfxHspdm_SuspendMode_soft = 2   /**< \brief Soft Suspend. */
} IfxHspdm_SuspendMode;

/** \brief update frequency.\n
 * Definition in IfxHSPDM.CON.ITMDIV
 */
typedef enum
{
    IfxHspdm_UpdateFreq_1MHz   = 0,  /**< \brief divide by 1 */
    IfxHspdm_UpdateFreq_0p5MHz = 1,  /**< \brief divide by 0.5 */
    IfxHspdm_UpdateFreq_2MHz   = 2,  /**< \brief divide by 2 */
    IfxHspdm_UpdateFreq_10MHz  = 3   /**< \brief divide by 10 */
} IfxHspdm_UpdateFreq;

/** \} */

/** \brief Enumeration listing the mute ranges available for Mute Signal set and clear.
 * Definition as MUTE0 and MUTE1 registers in HSPDM.
 */
typedef enum
{
    IfxHspdm_MuteRange_0 = 0,  /**< \brief Mute Range 0 */
    IfxHspdm_MuteRange_1 = 1   /**< \brief Mute Range 1 */
} IfxHspdm_MuteRange;

/** \addtogroup IfxLld_Hspdm_Std_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Disables the ADC trigger functionality of the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_disableAdcTrigger(Ifx_HSPDM *hspdm);

/**
 * \brief Sets the ADC Trigger offset value specified in counts of Fshift.
 *
 * \param[inout] hspdm       Pointer to the HSPDM device instance.
 * \param[in]    offsetCount Offset value specified in Fshift counts. Range: 0 to 65535.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_setAdcTriggerOffset(Ifx_HSPDM *hspdm, uint32 offsetCount);

/**
 * \brief Sets the trigger period in counts of Fshift for the HSPDM ADC.
 * If the period is set to less than 9 counts, the trigger will always be high,
 * which asserts an error.
 *
 * \param[inout] hspdm       Pointer to the HSPDM device instance.
 * \param[in]    periodCount Period in Fshift counts. Range: 0 to 65535.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setAdcTriggerPeriod(Ifx_HSPDM *hspdm, uint32 periodCount);

/**
 * \brief Sets the desired count as the ADC Trigger count value.
 *  The value (triggerCounts - 1) is stored in the TGCNT field of the HSPDM device.
 *
 * \param[inout] hspdm         Pointer to the HSPDM device instance.
 * \param[in]    triggerCounts The desired trigger count value to be set. Range: 0 to 65535.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_setAdcTriggerCounts(Ifx_HSPDM *hspdm, uint32 triggerCounts);

/**
 * \brief Enables the Pad Asymmetry Compensation (PAC) for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_enablePac(Ifx_HSPDM *hspdm);

/**
 * \brief Sets the buffer mode for the HSPDM device.
 *
 * \param[inout]  hspdm      Pointer to the HSPDM device instance.
 * \param[in]     bufferMode The buffer mode to be set. Definition in Ifx_Hspdm.CON.MM. Range: \ref IfxHspdm_BufferMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setBufferMode(Ifx_HSPDM *hspdm, IfxHspdm_BufferMode bufferMode);

/**
 * \brief Sets the mute signal polarity for the HSPDM device.
 *
 * \param[inout] hspdm    Pointer to the HSPDM device instance.
 * \param[in]    polarity Mute signal polarity to be set. Range: \ref IfxHspdm_MutePolarity.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setMutePolarity(Ifx_HSPDM *hspdm, IfxHspdm_MutePolarity polarity);

/**
 * \brief Enables the ADC trigger for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_enableAdcTrigger(Ifx_HSPDM *hspdm);

/**
 * \brief Set the active edge of the trigger signal which will activate HSPDM.
 *
 * \param[inout] hspdm      Pointer to the HSPDM device instance.
 * \param[in]    activeEdge Active edge of the trigger signal to be set. Range: \ref IfxHspdm_HwRunActiveEdge.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setHwRunActiveEdge(Ifx_HSPDM *hspdm, IfxHspdm_HwRunActiveEdge activeEdge);

/**
 * \brief Sets the Hardware Run Trigger Source to the selected source.
 *
 * \param[inout] hspdm         Pointer to the Ifx_HSPDM device instance.
 * \param[in]    triggerSource The hardware trigger source to be configured. Range: \ref IfxHspdm_HwTriggerSource.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_setHwRunTriggerSource(Ifx_HSPDM *hspdm, IfxHspdm_HwTriggerSource triggerSource);

/**
 * \brief Enables the Hardware Run Signal for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_enableHwRun(Ifx_HSPDM *hspdm);

/**
 * \brief Disables the Hardware Run feature for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_disableHwRun(Ifx_HSPDM *hspdm);

/**
 * \brief Sets the OCDS suspend mode for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 * \param[in]    mode  The suspend mode to be set. Range: \ref IfxHspdm_SuspendMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setSuspendMode(Ifx_HSPDM *hspdm, IfxHspdm_SuspendMode mode);

/**
 * \brief Sets the sleep mode for the specified HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 * \param[in]    mode  Sleep mode to be set. Range: \ref IfxHspdm_SleepMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setSleepMode(Ifx_HSPDM *hspdm, IfxHspdm_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Enables or disables the specified bit streaming block (BSB) for the HSPDM device.
 *
 * \param[inout] hspdm  Pointer to the HSPDM device instance.
 * \param[in]    bsb    BSB number to enable or disable. Range: TRUE for enabling or FALSE for disabling.
 * \param[in]    enable Boolean flag to enable (TRUE) or disable (FALSE) the BSB.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxHspdm_enableBSB(Ifx_HSPDM *hspdm, IfxHspdm_BSB bsb, boolean enable);

/**
 * \brief Initializes the BSB pin with the specified output mode and pad driver configuration.
 *
 * \param[inout] bsPin      Pointer to the BSB pin structure to be initialized.
 * \param[in]    outputMode Output mode configuration for the pin. Range: \ref IfxPort_OutputMode.
 * \param[in]    padDriver  Pad driver configuration. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxHspdm_initBsPin(IfxHspdm_Bs_Out *bsPin, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/**
 * \brief Initializes the Mute pin with the specified output mode and pad driver settings.
 *
 * \param[inout] mutePin    Pointer to the mute pin configuration structure to be initialized.
 * \param[in]    outputMode The output mode to be configured for the mute pin. Range: \ref IfxPort_OutputMode.
 * \param[in]    padDriver  The pad driver configuration to be applied to the mute pin. Range: \ref IfxPort_PadDriver.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxHspdm_initMutePin(IfxHspdm_Mute_Out *mutePin, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/** \} */

/** \addtogroup IfxLld_Hspdm_Std_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the streaming mode for the HSPDM module.
 *
 * \param[inout] hspdm         Pointer to the HSPDM module instance.
 * \param[in]    streamingMode The desired streaming mode for the HSPDM module. Definition in IfxHspdm.CON.SM. Range: \ref IfxHspdm_StreamingMode.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setStreamingMode(Ifx_HSPDM *hspdm, IfxHspdm_StreamingMode streamingMode);

/**
 * \brief Configures the dither level for the bit stream output.
 *
 * \param[inout] hspdm       Pointer to the HSPDM device instance.
 * \param[in]    ditherLevel Dither level to be set. Definition in Ifx_Hspdm.CON.DITH. Range: \ref IfxHspdm_DitherLevel.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setDitherLevel(Ifx_HSPDM *hspdm, IfxHspdm_DitherLevel ditherLevel);

/**
 * \brief Sets the divider value required in the ITMDIV field to realize the specified update frequency.
 *
 * \param[inout] hspdm           Pointer to the HSPDM device instance.
 * \param[in]    updateFrequency The desired update frequency. Range: \ref IfxHspdm_UpdateFreq.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setUpdateFreq(Ifx_HSPDM *hspdm, IfxHspdm_UpdateFreq updateFrequency);

/**
 * \brief Starts the bit stream operation for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_startBitStream(Ifx_HSPDM *hspdm);

/**
 * \brief Stops the bit stream transmission or reception from the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_stopBitStream(Ifx_HSPDM *hspdm);

/** \brief Sets the specified flag for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 * \param[in]    flag  Specified flag for the HSPDM device to be set. Range: \ref IfxHspdm_Flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_setFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag);

/** \brief Clears the specified flag for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 * \param[in]    flag  Specified flag for the HSPDM device to be clear. Range: \ref IfxHspdm_Flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_clearFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag);

/** \brief Enable the interrupt on event for the HSPDM device.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 * \param[in]    flag  Specified flag for the HSPDM device to be enable. Range: \ref IfxHspdm_Flag.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_enableFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag);

/**
 * \brief Disables the Pad Asymmetry Compensation (PAC) feature.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_disablePac(Ifx_HSPDM *hspdm);

/**
 * \brief Enables the HSPDM module.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_enableModule(Ifx_HSPDM *hspdm);

/**
 * \brief Disables the HSPDM module.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 * 
 */
IFX_INLINE void IfxHspdm_disableModule(Ifx_HSPDM *hspdm);

/**
 * \brief Resets the HSPDM module to its initial state.
 *
 * \param[inout] hspdm Pointer to the HSPDM device instance.
 *
 * \retval None
 *
 */
IFX_INLINE void IfxHspdm_resetModule(Ifx_HSPDM *hspdm);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Sets the start address for the specified buffer within the HSPDM device.
 *
 * \param[inout] hspdm   Pointer to the HSPDM device instance.
 * \param[in]    buffer  Specifies the buffer to configure. Range: \ref IfxHspdm_Buffer.
 * \param[in]    address Start address to set for the buffer. Range: 0 to 0x1FFC.
 *
 * \retval None
 * 
 */
IFX_EXTERN void IfxHspdm_setStartAddress(Ifx_HSPDM *hspdm, IfxHspdm_Buffer buffer, uint32 address);

/**
 * \brief Sets the end address of the chosen buffer for the HSPDM device.
 *
 * \param[inout] hspdm   Pointer to the HSPDM device instance.
 * \param[in]    buffer  Specifies the buffer to configure. Range: \ref IfxHspdm_Buffer.
 * \param[in]    address End address of the buffer. Range: 0 to 0x1FFC.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxHspdm_setEndAddress(Ifx_HSPDM *hspdm, IfxHspdm_Buffer buffer, uint32 address);

/**
 * \brief Sets the start and end addresses for the mute signals in the specified mute range.
 *
 * \param[inout] hspdm        Pointer to the HSPDM device instance.
 * \param[in]    muteRange    Enumeration specifying the mute range to configure. Range: \ref IfxHspdm_MuteRange.
 * \param[in]    startAddress Starting address of the mute range. Must be less than or equal to endAddress. Range: 0 to 0x1FFC.
 * \param[in]    endAddress   Ending address of the mute range. Must be greater than or equal to startAddress. Range: 0 to 0x1FFC.
 *
 * \retval None
 *
 */
IFX_EXTERN void IfxHspdm_setMuteAddresses(Ifx_HSPDM *hspdm, IfxHspdm_MuteRange muteRange, uint32 startAddress, uint32 endAddress);

/** \} */

/** \addtogroup IfxLld_Hspdm_Std_Utility
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \brief Returns the current address being accessed in the HSPDM SRAM.
 *
 * \param[in] hspdm Pointer to the HSPDM device instance.
 *
 * \retval uint32 The current address in the HSPDM SRAM. Range: 0 to 0x1FFC.
 *
 */
IFX_INLINE uint32 IfxHspdm_getCurrentSramAddr(Ifx_HSPDM *hspdm);

/**
 * \brief Retrieves the current run status of the HSPDM module.
 *
 * \param[in] hspdm Pointer to the HSPDM device instance.
 *  Definition in IfxHspdm.CON.RUN
 *
 * \retval IfxHspdm_RunState The current run state of the HSPDM module. Range: \ref IfxHspdm_RunState.
 *
 */
IFX_INLINE IfxHspdm_RunState IfxHspdm_getRunStatus(Ifx_HSPDM *hspdm);

/**
 * \brief Returns the physical level of the mute signal.
 *
 * \param[in] hspdm Pointer to the HSPDM device instance.
 *
 * \retval TRUE If  mute is active (signal is muted).
 *         FALSE If mute is inactive (signal is not muted).
 *
 */
IFX_INLINE boolean IfxHspdm_getMuteLevel(Ifx_HSPDM *hspdm);

/**
 * \brief Returns the status of the specified HSPDM flag.
 *
 * \param[in] hspdm Pointer to the HSPDM device instance.
 * \param[in] flag  Enumeration specifying the HSPDM flag to check. Range: \ref IfxHspdm_Flag.
 *
 * \retval TRUE The specified flag is set.
 *         FALSE The specified flag is not set.
 *
 */
IFX_INLINE boolean IfxHspdm_getFlagStatus(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag);

/**
 * \brief Returns the SRC pointer for HSPDM buffer Interrupt.
 * 
 * \retval Ifx_SRC_SRCR* Pointer to the BFR interrupt node of HSPDM.
 * 
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerBFR(void);

/**
 * \brief Returns the SRC pointer for HSPDM MUTE Interrupt.
 * This is mentioned as RAMP in the SRC regdef file.
 *
 * \retval Ifx_SRC_SRCR* Pointer to MUTE interrupt node of HSPDM.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerMUTE(void);

/**
 * \brief Returns the SRC pointer for HSPDM error Interrupt.
 *
 * \retval Ifx_SRC_SRCR* Pointer to the ERR interrupt node of HSPDM.
 *
 */
IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerERR(void);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxHspdm_setStreamingMode(Ifx_HSPDM *hspdm, IfxHspdm_StreamingMode streamingMode)
{
    hspdm->CON.B.SM = (uint32)streamingMode;
}


IFX_INLINE void IfxHspdm_setDitherLevel(Ifx_HSPDM *hspdm, IfxHspdm_DitherLevel ditherLevel)
{
    hspdm->CON.B.DITH = (uint32)ditherLevel;
}


IFX_INLINE void IfxHspdm_setUpdateFreq(Ifx_HSPDM *hspdm, IfxHspdm_UpdateFreq updateFrequency)
{
    hspdm->CON.B.ITMDIV = (uint32)updateFrequency;
}


IFX_INLINE void IfxHspdm_disableAdcTrigger(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.ADCTGEN = (uint32)0;
}


IFX_INLINE void IfxHspdm_setAdcTriggerOffset(Ifx_HSPDM *hspdm, uint32 offsetCount)
{
    hspdm->ADCTG.B.OFFSET = offsetCount;
}


IFX_INLINE void IfxHspdm_setAdcTriggerPeriod(Ifx_HSPDM *hspdm, uint32 periodCount)
{
    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, periodCount >= 9);  /* For period < 9; we have to assert an error */
    hspdm->ADCTG.B.PERIOD = periodCount;
}


IFX_INLINE void IfxHspdm_setAdcTriggerCounts(Ifx_HSPDM *hspdm, uint32 triggerCounts)
{
    if (triggerCounts >= (uint32)1)
    {
        hspdm->ADCTGCNT.B.TGCNT = (triggerCounts - 1);
    }
    else
    {
        hspdm->ADCTGCNT.B.TGCNT = 0;
    }
}


IFX_INLINE void IfxHspdm_enablePac(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.PAC = (uint32)1;
}


IFX_INLINE uint32 IfxHspdm_getCurrentSramAddr(Ifx_HSPDM *hspdm)
{
    return (uint32)(hspdm->CURRAD.B.CURRAD);
}


IFX_INLINE void IfxHspdm_setBufferMode(Ifx_HSPDM *hspdm, IfxHspdm_BufferMode bufferMode)
{
    hspdm->CON.B.MM = (uint32)bufferMode;
}


IFX_INLINE void IfxHspdm_startBitStream(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.RUNS = (uint32)1;
}


IFX_INLINE void IfxHspdm_stopBitStream(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.RUNC = (uint32)1;
}


IFX_INLINE IfxHspdm_RunState IfxHspdm_getRunStatus(Ifx_HSPDM *hspdm)
{
    return (IfxHspdm_RunState)(hspdm->CON.B.RUN);
}


IFX_INLINE void IfxHspdm_setMutePolarity(Ifx_HSPDM *hspdm, IfxHspdm_MutePolarity polarity)
{
    hspdm->CON.B.MPOL = (uint32)polarity;
}


IFX_INLINE boolean IfxHspdm_getMuteLevel(Ifx_HSPDM *hspdm)
{
    return (boolean)(hspdm->FLAGS.B.MUTE);
}


IFX_INLINE boolean IfxHspdm_getFlagStatus(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag)
{
    return (boolean)((hspdm->FLAGS.U >> (uint32)flag) & (uint32)1);
}


IFX_INLINE void IfxHspdm_setFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag)
{
    hspdm->FLAGSSET.U |= ((uint32)1 << (uint32)flag);
}


IFX_INLINE void IfxHspdm_clearFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag)
{
    hspdm->FLAGSCLEAR.U |= ((uint32)1 << (uint32)flag);
}


IFX_INLINE void IfxHspdm_enableFlag(Ifx_HSPDM *hspdm, IfxHspdm_Flag flag)
{
    hspdm->FLAGSEN.U |= ((uint32)1 << (uint32)flag);
}


IFX_INLINE void IfxHspdm_disablePac(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.PAC = (uint32)0;
}


IFX_INLINE void IfxHspdm_enableAdcTrigger(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.ADCTGEN = (uint32)1;
}


IFX_INLINE void IfxHspdm_setHwRunActiveEdge(Ifx_HSPDM *hspdm, IfxHspdm_HwRunActiveEdge activeEdge)
{
    hspdm->CON.B.HRAE = (uint32)activeEdge;
}


IFX_INLINE void IfxHspdm_setHwRunTriggerSource(Ifx_HSPDM *hspdm, IfxHspdm_HwTriggerSource triggerSource)
{
    hspdm->CON.B.HRSEL = (uint32)triggerSource;
}


IFX_INLINE void IfxHspdm_enableHwRun(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.HREN = (uint32)1;
}


IFX_INLINE void IfxHspdm_disableHwRun(Ifx_HSPDM *hspdm)
{
    hspdm->CON.B.HREN = (uint32)0;
}


IFX_INLINE void IfxHspdm_enableModule(Ifx_HSPDM *hspdm)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection*/
    IfxScuWdt_clearCpuEndinit(psw);
    /* Enables the module*/
    hspdm->CLC.B.DISR = (uint32)0;
    /* Sets the endinit protection back on*/
    IfxScuWdt_setCpuEndinit(psw);
}


IFX_INLINE void IfxHspdm_disableModule(Ifx_HSPDM *hspdm)
{
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    /* Clears the endinit protection*/
    IfxScuWdt_clearCpuEndinit(psw);
    /* Disables the module*/
    hspdm->CLC.B.DISR = (uint32)1;
    /* Sets the endinit protection back on*/
    IfxScuWdt_setCpuEndinit(psw);
}


IFX_INLINE void IfxHspdm_resetModule(Ifx_HSPDM *hspdm)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);

    /* Only if both Kernel reset bits are set a reset is executed */
    hspdm->KRST0.B.RST = 1;
    hspdm->KRST1.B.RST = 1;
    IfxScuWdt_setCpuEndinit(passwd);

    /* Wait until reset is executed */
    while (0 == hspdm->KRST0.B.RSTSTAT)
    {}

    IfxScuWdt_clearCpuEndinit(passwd);
    /* Clear Kernel reset status bit */
    hspdm->KRSTCLR.B.CLR = 1;

    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxHspdm_setSuspendMode(Ifx_HSPDM *hspdm, IfxHspdm_SuspendMode mode)
{
    Ifx_HSPDM_OCS ocs;

    /* Remove protection and configure the suspend mode. */
    ocs.B.SUS_P  = 1;
    ocs.B.SUS    = mode;
    hspdm->OCS.U = ocs.U;
}


IFX_INLINE void IfxHspdm_setSleepMode(Ifx_HSPDM *hspdm, IfxHspdm_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    hspdm->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerBFR(void)
{
    return (Ifx_SRC_SRCR *)(&MODULE_SRC.HSPDM.HSPDM0.BFR);
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerMUTE(void)
{
    return (Ifx_SRC_SRCR *)(&MODULE_SRC.HSPDM.HSPDM0.RAMP);
}


IFX_INLINE volatile Ifx_SRC_SRCR *IfxHspdm_getSrcPointerERR(void)
{
    return (Ifx_SRC_SRCR *)(&MODULE_SRC.HSPDM.HSPDM0.ERR);
}


#endif /* IFXHSPDM_H */
