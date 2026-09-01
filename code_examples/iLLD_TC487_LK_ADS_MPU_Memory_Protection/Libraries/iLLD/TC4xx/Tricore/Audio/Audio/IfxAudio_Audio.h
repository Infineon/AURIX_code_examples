/**
 * \file IfxAudio_Audio.h
 * \brief AUDIO AUDIO details
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
 * \defgroup IfxLld_Audio_Audio AUDIO
 * \ingroup IfxLld_Audio
 * \defgroup IfxLld_Audio_Audio_Structures Data Structures
 * \ingroup IfxLld_Audio_Audio
 * \defgroup IfxLld_Audio_Audio_Enum Enumerations
 * \ingroup IfxLld_Audio_Audio
 * \defgroup IfxLld_Audio_Audio_Functions Module Interface Functions for Audio
 * \ingroup IfxLld_Audio_Audio
 */

#ifndef IFXAUDIO_AUDIO_H
#define IFXAUDIO_AUDIO_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Audio/Std/IfxAudio.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Audio_Audio_Structures
 * \{ */
/** \brief Module handle
 */
typedef struct
{
    Ifx_AUDIO *audioSFR;       /**< \brief Specifies the pointer to the AUDIO registers */
} IfxAudio_Audio;

/** \brief Configuration Structure of the Module
 */
typedef struct
{
    Ifx_AUDIO *audioSFR;       /**< \brief Specifies the pointer to the AUDIO registers */
} IfxAudio_Audio_Config;

/** \brief Structure for Interrupt node Configuration
 */
typedef struct
{
    Ifx_Priority priority;            /**< \brief Priority of the interrupt */
    IfxSrc_Tos   typeOfService;       /**< \brief Type of Service */
    IfxSrc_VmId  vmId;                /**< \brief Virtual Machine Number */
} IfxAudio_Audio_InterruptNodeConfig;

/** \} */

/** \addtogroup IfxLld_Audio_Audio_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initialises the AUDIO Module
 * \param audio Specifies the module handle
 * \param config Configuration structure of the module
 * \return None
 */
IFX_EXTERN void IfxAudio_Audio_initModule(IfxAudio_Audio *audio, IfxAudio_Audio_Config *config);

/** \brief Fills the configuration stucture of the AUDIO Module with default values
 * \param config Configuration structure to be filled with default values
 * \param audioSFR Specifies the pointer to the AUDIO registers
 * \return None
 */
IFX_EXTERN void IfxAudio_Audio_initModuleConfig(IfxAudio_Audio_Config *config, Ifx_AUDIO *audioSFR);

/** \brief Initialises the SRC interrupt node pointed by the index
 * \param config Configuration structure to be filled by application
 * \param index Specifies the AUDIO SRC node
 * \return None
 */
IFX_EXTERN void IfxAudio_Audio_initInterruptNode(IfxAudio_Audio_InterruptNodeConfig *config, IfxAudio_ServiceRequest index);

/** \} */

#endif /* IFXAUDIO_AUDIO_H */
