/**
 * \file IfxGtm_cfg.c
 * \brief GTM on-chip implementation data
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
#if defined(DEVICE_TC33X) ||defined(DEVICE_TC36X) || defined(DEVICE_TC37X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC39XB)

#include "IfxGtm_cfg.h" 

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxGtm_Cdtm        IfxGtm_dtmAtom_map[IFXGTM_NUM_ATOM_OBJECTS] = {
    IfxGtm_Cdtm_0,              /* ATOM0 */
#if	IFXGTM_NUM_ATOM_OBJECTS > 1					
    IfxGtm_Cdtm_1,              /* ATOM1 */
    IfxGtm_Cdtm_2,              /* ATOM2 */
    IfxGtm_Cdtm_3,              /* ATOM3 */
#endif 
#if	IFXGTM_NUM_ATOM_OBJECTS > 4  				
    IfxGtm_Cdtm_4,              /* ATOM4 */
    IfxGtm_Cdtm_5,              /* ATOM5 */
#endif 
#if	IFXGTM_NUM_ATOM_OBJECTS > 6                  
    IfxGtm_Cdtm_none,           /* ATOM6 */
    IfxGtm_Cdtm_none,           /* ATOM7 */
    IfxGtm_Cdtm_none,           /* ATOM8 */
#endif
};

IFX_CONST IfxGtm_Cdtm        IfxGtm_dtmTom_map[IFXGTM_NUM_TOM_OBJECTS] = {
    IfxGtm_Cdtm_0,              /* TOM0 */
    IfxGtm_Cdtm_1,              /* TOM1 */
#if IFXGTM_NUM_TOM_OBJECTS > 2        		
    IfxGtm_Cdtm_2,              /* TOM2 */ 
#endif                                      
#if IFXGTM_NUM_TOM_OBJECTS > 3
    IfxGtm_Cdtm_3,              /* TOM3 */
#endif
#if	IFXGTM_NUM_TOM_OBJECTS > 4
    IfxGtm_Cdtm_none,           /* TOM4 */
#endif
};

#if defined(DEVICE_TC39XB)
IFX_CONST IfxModule_IndexMap IfxGtm_spe_indexMap[IFXGTM_NUM_SPE_OBJECTS] = {
    {&(MODULE_GTM.SPE[0]), (uint32)IfxGtm_Spe_0},
    {&(MODULE_GTM.SPE[1]), (uint32)IfxGtm_Spe_1},
    {&(MODULE_GTM.SPE[2]), (uint32)IfxGtm_Spe_2},
    {&(MODULE_GTM.SPE[3]), (uint32)IfxGtm_Spe_3},
    {&(MODULE_GTM.SPE[4]), (uint32)IfxGtm_Spe_4},
    {&(MODULE_GTM.SPE[5]), (uint32)IfxGtm_Spe_5}
};
#elif defined(DEVICE_TC38X)
IFX_CONST IfxModule_IndexMap IfxGtm_spe_indexMap[IFXGTM_NUM_SPE_OBJECTS] = {
    {&(MODULE_GTM.SPE[0]), (uint32)IfxGtm_Spe_0},
    {&(MODULE_GTM.SPE[1]), (uint32)IfxGtm_Spe_1},
    {&(MODULE_GTM.SPE[2]), (uint32)IfxGtm_Spe_2},
    {&(MODULE_GTM.SPE[3]), (uint32)IfxGtm_Spe_3},
};
#elif defined(DEVICE_TC38EVOX)
IFX_CONST IfxModule_IndexMap IfxGtm_spe_indexMap[IFXGTM_NUM_SPE_OBJECTS] = {
    {&(MODULE_GTM.SPE[0]), (uint32)IfxGtm_Spe_0},
    {&(MODULE_GTM.SPE[1]), (uint32)IfxGtm_Spe_1},
    {&(MODULE_GTM.SPE[2]), (uint32)IfxGtm_Spe_2},
    {&(MODULE_GTM.SPE[3]), (uint32)IfxGtm_Spe_3},
};
#endif

#endif /* #if defined(DEVICE_TC33X) ||defined(DEVICE_TC36X) || defined(DEVICE_TC37X) || defined(DEVICE_TC37XED) || defined(DEVICE_TC38EVOX) || defined(DEVICE_TC38X) || defined(DEVICE_TC39XB) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
