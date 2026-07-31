/**
 * \file IfxAudio_Ldma.h
 * \brief AUDIO LDMA details
 * \ingroup IfxLld_Audio
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
 * \defgroup IfxLld_Audio_Ldma LDMA
 * \ingroup IfxLld_Audio
 * \defgroup IfxLld_Audio_Ldma_Enumerations Enumerations
 * \ingroup IfxLld_Audio_Ldma
 * \defgroup IfxLld_Audio_Ldma_Structures Data Structures
 * \ingroup IfxLld_Audio_Ldma
 * \defgroup IfxLld_Audio_Ldma_Functions Module Interface Functions for Audio
 * \ingroup IfxLld_Audio_Ldma
 */

#ifndef IFXAUDIO_LDMA_H
#define IFXAUDIO_LDMA_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Audio/Audio/IfxAudio_Audio.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Audio_Ldma_Enumerations
 * \{ */
typedef enum
{
    IfxAudio_Ldma_DestFifo_tdm0 = 0,  /**< \brief TDM0 Sideband FIFO space available */
    IfxAudio_Ldma_DestFifo_tdm1 = 1,  /**< \brief TDM1 Sideband FIFO space available */
#if (IFXAUDIO_NUM_INTERFACES > 2)
    IfxAudio_Ldma_DestFifo_tdm2 = 2   /**< \brief TDM2 Sideband FIFO space available */
#endif /* #if (IFXAUDIO_NUM_INTERFACES > 2) */
} IfxAudio_Ldma_DestFifo;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Audio_Ldma_Structures
 * \{ */
/** \brief Configuration Structure of the Ldma block
 */
typedef struct
{
    uint32                 interruptMask;               /**< \brief LDMA interrupt mask */
    IfxAudio_Ldma_DestFifo destinationFifoSelect;       /**< \brief Destination FIFO space select */
} IfxAudio_Ldma_Config;

/** \} */

/** \addtogroup IfxLld_Audio_Ldma_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the AUDIO Ldma block
 * \param audio Specifies the module handle
 * \param config Configuration structure for LDMA
 * \return None
 */
IFX_EXTERN void IfxAudio_Ldma_initLdma(IfxAudio_Audio *audio, IfxAudio_Ldma_Config *config);

/** \brief Returns the value of LDMA.STATUS.B.DEST_SPACE_AVAIL
 * \param audio Specifies the module handle
 * \return level signal status
 */
IFX_EXTERN uint32 IfxAudio_Ldma_isDestinationSpaceAvailable(IfxAudio_Audio *audio);

/** \brief Returns the value of LDMA.STATUS.B.SRC_DATA_AVAIL
 * \param audio Specifies the module handle
 * \return level signal status
 */
IFX_EXTERN boolean IfxAudio_Ldma_isSourceDataAvailable(IfxAudio_Audio *audio);

/** \brief Returns the status of interrupt after masking
 * \param audio Specifies the module handle
 * \return level signal status
 */
IFX_EXTERN uint32 IfxAudio_Ldma_getMaskedInterruptStatus(IfxAudio_Audio *audio);

/** \} */

#endif /* IFXAUDIO_LDMA_H */
