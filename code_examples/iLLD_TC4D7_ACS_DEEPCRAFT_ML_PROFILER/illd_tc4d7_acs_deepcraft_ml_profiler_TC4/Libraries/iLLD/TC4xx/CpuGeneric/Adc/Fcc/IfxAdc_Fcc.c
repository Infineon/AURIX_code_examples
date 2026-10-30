/**
 * \file IfxAdc_Fcc.c
 * \brief ADC FCC details
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
#pragma warning 508		/* To suppress empty file warning */
#endif
#if defined (__ghs__)
#pragma diag_suppress 96		/* To suppress empty file warning */
#endif

#if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) || defined(DEVICE_TC4PX)
#include "IfxAdc_Fcc.h"

/** \addtogroup IfxLld_Adc_Fcc_Fcc
 * \{ */

/******************************************************************************/
/*-----------------------Private Function Prototypes--------------------------*/
/******************************************************************************/

/** \brief Setup Triggers for FCC module
 *
 * \param[in] fcc        Pointer to Fcc module sfr
 * \param[in] triggerCfg Pointer to the trigger Configuration
 *
 * \retval None
 */
IFX_STATIC void IfxAdc_Fcc_setupTriggers(Ifx_ADC_FCC *fcc, const IfxAdc_Fcc_TriggerConfig *triggerCfg);

/** \brief Function to update boundary configuration.
 *
 * \param[in]    fcc         Pointer to module sfr
 * \param[in]    boundConfig Pointer to boundary configuration
 *
 * \retval None
 */
IFX_STATIC void IfxAdc_Fcc_configureBoundary(Ifx_ADC_FCC *fcc, IfxAdc_Fcc_BoundaryConfig *boundConfig);

/** \} */

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxAdc_Fcc_initModule(IfxAdc_Fcc *fcc, const IfxAdc_Fcc_Config *config)
{
    /* Declare, initialize variables/pointers */
    IfxAdc_FccModule                   moduleId = config->id;
    Ifx_ADC_FCC                       *modptr   = &(config->adcSfr->FCC[moduleId]);
    IfxAdc_Fcc_BoundaryConfig         *bndCfg   = config->boundaryCfg;
    IfxAdc_Fcc_RampModeConfig         *rmpCfg   = config->rampCfg;
    const IfxAdc_Fcc_ServiceReqConfig *srvCfg   = &(config->srvReqCfg);
    const IfxAdc_Fcc_PinsConfig       *pinsCfg  = config->pins;
    volatile Ifx_SRC_SRCR             *src      = NULL_PTR;
    boolean                            status   = FALSE;

    Ifx_ADC_FCC_MODCFG                 modCfg;

    // Update Handle
    fcc->modSfr = modptr;
    fcc->id     = moduleId;

    /* Setting module state to uninitialized */
    fcc->state = IfxAdc_Fcc_ModuleState_uninitialized;

    /*Enable Fcc module clock*/
    IfxAdc_enableFccModule(moduleId);

    // Read relevant registers
    modCfg.U = modptr->MODCFG.U;

    if (config->initialTv > IFXADC_FCC_MAX_THRESHOLD_VALUE)
    {
        /* Assert Error */
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (config->initialTv < IFXADC_FCC_MAX_THRESHOLD_VALUE));
        status = TRUE;
    }

    /* Setting the mode, threshold value, Hysteresis mode and filter depth of the FCC module */
    {
        modCfg.B.MODE = config->mode;
        modCfg.B.TV   = config->initialTv;
        modCfg.B.GFD  = config->filterDepth;
    }

    /* Ramp Configuration */
    if (rmpCfg != NULL_PTR)
    {
        if (rmpCfg->stepSize > IFXADC_FCC_MAX_THRESHOLD_VALUE)
        {
            /*Assert Error*/
            IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, (config->rampCfg->stepSize < IFXADC_FCC_MAX_THRESHOLD_VALUE));
            status = TRUE;
        }

        IfxAdc_Fcc_configureRamp(modptr, rmpCfg);
    }

    /*Trigger configuration */
    if (config->trigger != NULL_PTR)
    {
        IfxAdc_Fcc_setupTriggers(modptr, config->trigger);
    }

    /* Boundary Configuration */
    if (bndCfg != NULL_PTR)
    {
        IfxAdc_Fcc_configureBoundary(modptr, bndCfg);
    }

    /* Interrupt Configuration */
    if (srvCfg->intCfg[0].priority > 0u)
    {
        src = IfxAdc_getFccSr0SrcPointer(modptr, fcc->id);
        IfxSrc_init(src, srvCfg->intCfg[0].typeOfService, srvCfg->intCfg[0].priority, srvCfg->intCfg[0].vmId);
        IfxAdc_setFccSr0EventSel(modptr, srvCfg->event0Sel);
        IfxSrc_enable(src);
    }

    if (srvCfg->intCfg[1].priority > 0u)
    {
        src = IfxAdc_getFccSr1SrcPointer(modptr, fcc->id);
        IfxSrc_init(src, srvCfg->intCfg[1].typeOfService, srvCfg->intCfg[1].priority, srvCfg->intCfg[1].vmId);
        IfxAdc_setFccSr1EventSel(modptr, srvCfg->event1Sel);
        IfxSrc_enable(src);
    }

    /* Pins configuration */
    if (pinsCfg != NULL_PTR)
    {
        /* Analog input configuration*/
        if (pinsCfg->fccPin != NULL_PTR)
        {
            IfxAdc_initFccPin(pinsCfg->fccPin, pinsCfg->fccinMode, pinsCfg->padDriver);
        }

        /* BFL out configuration */
        if (pinsCfg->bflPin != NULL_PTR)
        {
            IfxAdc_initBflPin(pinsCfg->bflPin, pinsCfg->bflMode, pinsCfg->padDriver);
        }
    }

    /* Writing register back */
    modptr->MODCFG.U = modCfg.U;

    /* Run Module */
    IfxAdc_runFccModule(modptr);

    /* If no error set module state to initialized */
    if (status == FALSE)
    {
        fcc->state = IfxAdc_Fcc_ModuleState_initialized;
    }
}


void IfxAdc_Fcc_initModuleConfig(IfxAdc_Fcc_Config *config, Ifx_ADC *adc)
{
    //1. Initialize all to default values
    const IfxAdc_Fcc_Config defaultConfig = {
        .id          = IfxAdc_FccModule_0,
        .adcSfr      = NULL_PTR,
        .mode        = IfxAdc_FccMode_normal,
        .filterDepth = 0u,
        .initialTv   = 0u,
        .trigger     = NULL_PTR,
        .boundaryCfg = NULL_PTR,
        .rampCfg     = NULL_PTR,
        .srvReqCfg   = {
            .intCfg[0].priority      = 0,
            .intCfg[0].typeOfService = IfxSrc_Tos_cpu0,
            .intCfg[0].vmId          = IfxSrc_VmId_0,

            .intCfg[1].priority      = 0,
            .intCfg[1].typeOfService = IfxSrc_Tos_cpu0,
            .intCfg[1].vmId          = IfxSrc_VmId_0,

            .event0Sel               = IfxAdc_FccSr0EventSel_disable,
            .event1Sel               = IfxAdc_FccSr1EventSel_disable
        }
    };

    *config        = defaultConfig;
    config->adcSfr = adc;
}


void IfxAdc_Fcc_configureRamp(Ifx_ADC_FCC *fcc, IfxAdc_Fcc_RampModeConfig *rampConfig)
{
    Ifx_ADC_FCC       *sfrPtr = fcc;
    Ifx_ADC_FCC_RMPCFG rampCfg;
    Ifx_ADC_FCC_RMPT   rampThreshold;

    /*Register read*/
    rampCfg.U           = sfrPtr->RMPCFG.U;
    rampThreshold.U     = sfrPtr->RMPT.U;

    rampCfg.B.DIR       = rampConfig->rampDir;
    rampCfg.B.STEPSZ    = rampConfig->stepSize;
    rampCfg.B.STEPWD    = rampConfig->stepWidth;

    rampThreshold.B.STV = rampConfig->startTV;
    rampThreshold.B.ETV = rampConfig->endTV;

    /*Register update*/
    sfrPtr->RMPCFG.U = rampCfg.U;
    sfrPtr->RMPT.U   = rampThreshold.U;
}


IFX_STATIC void IfxAdc_Fcc_setupTriggers(Ifx_ADC_FCC *fcc, const IfxAdc_Fcc_TriggerConfig *triggerCfg)
{
    Ifx_ADC_FCC        *sfrPtr = fcc;
    IfxAdc_Fcc_Trigger *config;

    /* Threshold trigger configuration */
    if (triggerCfg->thresholdTrigger != NULL_PTR)
    {
        config = triggerCfg->thresholdTrigger;
        IFXADC_FCC_WRITETRIGCFG(sfrPtr->THTRCFG, config->delayCount, config->edgeSel, config->trigSel);
    }

    /* Gate trigger configuration */
    if (triggerCfg->gatedTrigger != NULL_PTR)
    {
        config = triggerCfg->gatedTrigger;
        IFXADC_FCC_WRITETRIGCFG(sfrPtr->GATRCFG, config->delayCount, config->edgeSel, config->trigSel);
    }

    /* Ramp trigger configuration */
    if (triggerCfg->rampTrigger != NULL_PTR)
    {
        config = triggerCfg->rampTrigger;
        IFXADC_FCC_WRITETRIGCFG(sfrPtr->RMPTRCFG, config->delayCount, config->edgeSel, config->trigSel);
    }
}


IFX_STATIC void IfxAdc_Fcc_configureBoundary(Ifx_ADC_FCC *fcc, IfxAdc_Fcc_BoundaryConfig *boundConfig)
{
    Ifx_ADC_FCC                 *sfrPtr = fcc;
    Ifx_ADC_FCC_BFLCFG           boundaryFLagCfg;
    Ifx_ADC_FCC_HYSTCFG          hysteresisCfg;
    IfxAdc_Fcc_HysteresisConfig *hystConfigPtr;

    /* Configure Boundary Flag mode and activation condition*/
    {
        boundaryFLagCfg.U      = sfrPtr->BFLCFG.U;

        boundaryFLagCfg.B.BFM  = boundConfig->enableboundary;
        boundaryFLagCfg.B.BFA  = boundConfig->activateBoundaryFlag;
        boundaryFLagCfg.B.BFS  = boundConfig->selectBoundaryFlag;
        boundaryFLagCfg.B.SBFV = boundConfig->swBoundaryFlagValue;

        sfrPtr->BFLCFG.U       = boundaryFLagCfg.U;
    }

    /* Gated Boundary flag*/
    sfrPtr->GATRCFG.B.BFLPOL = boundConfig->polarity;

    /* Configure hysteresis boundary if hysteresis mode enabled */
    hystConfigPtr = boundConfig->hystconfig;

    if (hystConfigPtr != NULL_PTR)
    {
        IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, ((hystConfigPtr->deltaMinus < IFXADC_FCC_MAX_THRESHOLD_VALUE) || (hystConfigPtr->deltaPlus < IFXADC_FCC_MAX_THRESHOLD_VALUE)));

        hysteresisCfg.U      = sfrPtr->HYSTCFG.U;
        hysteresisCfg.B.DELM = hystConfigPtr->deltaMinus;
        hysteresisCfg.B.DELP = hystConfigPtr->deltaPlus;
        sfrPtr->HYSTCFG.U    = hysteresisCfg.U;
    }
}

#endif /* #if defined(DEVICE_TC49XN) || defined(DEVICE_TC46X) || defined(DEVICE_TC4EX) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
