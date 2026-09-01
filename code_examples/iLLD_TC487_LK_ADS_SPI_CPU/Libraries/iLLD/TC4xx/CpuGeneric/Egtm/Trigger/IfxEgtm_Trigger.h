/**
 * \file IfxEgtm_Trigger.h
 * \brief EGTM TRIGGER details
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
 * \defgroup IfxLld_Egtm_Trigger_Usage How to use the eGTM Trigger functionality
 * \ingroup IfxLld_Egtm_Trigger
 *
 * The EGTM resources can be used as a trigger resource.
 * These resources are used by the other peripheral devices like ADC, SENT,
 * CAN, QSPI, ASCLIN, PSI5 and PSI5S.
 *
 * Usage of Trigger APIs
 *
 * To provide a trigger from EGTM following parameters are required.
 *
 * 1 egtmCluster: Cluster of EGTM which contains the trigger source
 * 2 egtmSource: Trigger source selected (Atom or Tom)
 * 3 channel: Channel within the egtmSource  (Atom 0-7, Tom 0-15)
 * 4 <module name>TrigSignal(Trigger Signal): trigger Signal  for the required module.
 * 5 <module name>Module (Module Instance): For modules like SENT and PSI5S which have multiple instance.
 *
 *
 * 1. Call the API IfxEgtm_Trigger_trigTo<module name> with the required input parameters described above.
 * IfxEgtm_Trigger_trigToAdc(IfxEgtm_Cluster_0, IfxEgtm_TrigSource_atom, IfxEgtm_Atom_Ch_0, IfxEgtm_Cfg_AdcTriggerSignal_0); //for illustration purpose only -- to set your own values.
 *
 * 2. If the combination of egtmCluster, egtmSource and channel is valid for the trigger then the trigger will be set for the module else API will return fail.
 *
 * \defgroup IfxLld_Egtm_Trigger
 * \ingroup IfxLld_Egtm
 * \defgroup IfxLld_Egtm_Trigger_Trigger_Functions Trigger Functions
 * \ingroup IfxLld_Egtm_Trigger
 */

#ifndef IFXEGTM_TRIGGER_H 
#define IFXEGTM_TRIGGER_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxEgtm_cfg.h"
#if !defined(IFX_ILLD_PPU_USAGE)
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#endif
#if defined(IFX_ILLD_PPU_USAGE)
#include "Ppu/Std/IfxPpu_Intrinsics.h"
#endif

/** \addtogroup IfxLld_Egtm_Trigger_Trigger_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Connect eGTM to Adc
 *
 * \param[in] egtmCluster   Cluster of EGTM which contains the trigger source
 *                          Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource    Trigger source selected (Atom or Tom)
 * \param[in] Channel       Channel within the egtmSource
 * \param[in] adcTrigSignal Connection to ADC trigger Signal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToAdc(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_AdcTriggerSignal adcTrigSignal);

/** \brief Connect eGTM to Sent
 *
 * \param[in] egtmCluster    Cluster of EGTM which contains the trigger source
 *                           Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource     Trigger source selected (Atom or Tom)
 *                           Range: \ref: IfxEgtm_Cfg_Psi5sTriggerSignal
 * \param[in] Channel        Channel within the egtmSource
 *                           Range: \ref: IfxEgtm_Cfg_Psi5sTriggerSignal
 * \param[in] sentModule     The SENT module to configure
 *                           Range: \ref: IfxEgtm_Cfg_Psi5sTriggerSignal
 * \param[in] sentTrigSignal Connection to SENT trigger Signal
 *                           Range: \ref: IfxEgtm_Cfg_Psi5sTriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToSent(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_SentTriggerModules sentModule, IfxEgtm_Cfg_SentTriggerSignal sentTrigSignal);

/** \brief Connect eGTM to Psi5
 *
 * \param[in] egtmCluster    Cluster of EGTM which contains the trigger source
 *                           Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource     Trigger source selected (Atom or Tom)
 *                           Range: \ref: IfxEgtm_TrigSource
 * \param[in] Channel        Channel within the egtmSource
 *                           Range: \ref: IfxEgtm_TrigChannel
 * \param[in] psi5TrigSignal Connection to ADC trigger Signal
 *                           Range: \ref: IfxEgtm_Cfg_Psi5TriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToPsi5(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_Psi5TriggerSignal psi5TrigSignal);

/** \brief Connect eGTM to Psi5s
 *
 * \param[in] egtmCluster     Cluster of EGTM which contains the trigger source
 *                            Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource      Trigger source selected (Atom or Tom)
 *                            Range: \ref: IfxEgtm_TrigSource
 * \param[in] Channel         Channel within the egtmSource
 *                            Range: \ref: IfxEgtm_TrigChannel
 * \param[in] psi5sModule     Psi5s Module configured for trigger
 *                            Range: \ref: IfxEgtm_Cfg_Psi5sTriggerModules
 * \param[in] psi5sTrigSignal Connection to ADC trigger Signal
 *                            Range: \ref: IfxEgtm_Cfg_Psi5sTriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToPsi5s(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_Psi5sTriggerModules psi5sModule, IfxEgtm_Cfg_Psi5sTriggerSignal psi5sTrigSignal);

/** \brief Connect eGTM to Can
 *
 * \param[in] egtmCluster   Cluster of EGTM which contains the trigger source
 *                          Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource    Trigger source selected (Atom or Tom)
 *                          Range: \ref: IfxEgtm_TrigSource
 * \param[in] Channel       Channel within the egtmSource
 *                          Range: \ref: IfxEgtm_TrigSource
 * \param[in] canTrigSignal Connection to ADC trigger Signal
 *                          Range: \ref: IfxEgtm_Cfg_CanTriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToCan(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_CanTriggerSignal canTrigSignal);

/** \brief Connect eGTM to Qspi
 *
 * \param[in] egtmCluster    Cluster of EGTM which contains the trigger source
 *                           Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource     Trigger source selected (Atom or Tom)
 *                           Range: \ref: IfxEgtm_TrigSource
 * \param[in] Channel        Channel within the egtmSource
 *                           Range: \ref: IfxEgtm_TrigChannel
 * \param[in] qspiTrigSignal Connection to ADC trigger Signal
 *                           Range: \ref: IfxEgtm_Cfg_QspiTriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToQspi(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_QspiTriggerSignal qspiTrigSignal);

/** \brief Connect eGTM to Asclin
 *
 * \param[in] egtmCluster      Cluster of EGTM which contains the trigger source
 *                             Range: \ref: IfxEgtm_Cluster
 * \param[in] egtmSource       Trigger source selected (Atom or Tom)
 *                             Range: \ref: IfxEgtm_TrigSource
 * \param[in] Channel          Channel within the egtmSource
 *                             Range: \ref: IfxEgtm_TrigChannel
 * \param[in] asclinTrigSignal Connection to ADC trigger Signal
 *                             Range: \ref: IfxEgtm_Cfg_AsclinTriggerSignal
 *
 * \retval TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxEgtm_Trigger_trigToAsclin(IfxEgtm_Cluster egtmCluster, IfxEgtm_TrigSource egtmSource, IfxEgtm_TrigChannel Channel, IfxEgtm_Cfg_AsclinTriggerSignal asclinTrigSignal);

/** \} */

#endif /* IFXEGTM_TRIGGER_H */
