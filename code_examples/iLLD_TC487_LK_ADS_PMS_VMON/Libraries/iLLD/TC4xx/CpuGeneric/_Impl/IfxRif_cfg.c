/**
 * \file IfxRif_cfg.c
 * \brief RIF on-chip implementation data 
 *
 * \version iLLD-TC4-v2.6.0
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

#if defined(DEVICE_TC45X)

#include "IfxRif_cfg.h"

            
/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/


IFX_CONST IfxModule_IndexMap IfxRif_cfg_indexMap[IFXRIF_NUM_MODULES] = 
    {{&MODULE_RIF0,  (uint32)IfxRif_Index_0 },
	{&MODULE_RIF1,  (uint32)IfxRif_Index_1 },
	{&MODULE_RIF2,  (uint32)IfxRif_Index_2 }
};

IFX_CONST IfxRif_HighFrequencyRange IfxRif_highFrequencyRangeTable[IFXRIF_NUM_HS_FREQ_RANGE] = 
    {
	{80u, 0x0u, 0x152u, 0x177u},
	{90u, 0x10u, 0x152u, 0x177u},
	{100u, 0x20u, 0x152u, 0x177u},
	{110u, 0x30u, 0x152u, 0x177u},
	{120u, 0x1u, 0x152u, 0x177u},
	{130u, 0x11u, 0x152u, 0x177u},
	{140u, 0x21u, 0x152u, 0x177u},
	{150u, 0x31u, 0x152u, 0x177u},
	{160u, 0x2u, 0x152u, 0x177u},
	{170u, 0x12u, 0x152u, 0x177u},
	{180u, 0x22u, 0x152u, 0x177u},
	{190u, 0x32u, 0x152u, 0x177u},
	{205u, 0x3u, 0x152u, 0x177u},
	{220u, 0x13u, 0x152u, 0x177u},
	{235u, 0x23u, 0x152u, 0x177u},
	{250u, 0x33u, 0x152u, 0x177u},
	{275u, 0x4u, 0x152u, 0x177u},
	{300u, 0x14u, 0x152u, 0x177u},
	{325u, 0x25u, 0x152u, 0x177u},
	{350u, 0x35u, 0x152u, 0x177u},
	{400u, 0x5u, 0x152u, 0x177u},
	{450u, 0x16u, 0x152u, 0x177u},
	{500u, 0x26u, 0x152u, 0x177u},
	{550u, 0x37u, 0x152u, 0x177u},
	{600u, 0x7u, 0x152u, 0x177u},
	{650u, 0x18u, 0x152u, 0x177u},
	{700u, 0x28u, 0x152u, 0x177u},
	{750u, 0x39u, 0x152u, 0x177u},
	{800u, 0x9u, 0x152u, 0x177u},
	{850u, 0x19u, 0x152u, 0x177u},
	{900u, 0x29u, 0x152u, 0x177u},
	{950u, 0x3Au, 0x152u, 0x177u},
	{1000u, 0xAu, 0x152u, 0x177u},
	{1050u, 0x1Au, 0x152u, 0x177u},
	{1100u, 0x2Au, 0x152u, 0x177u},
	{1150u, 0x3Bu, 0x152u, 0x177u},
	{1200u, 0xBu, 0x152u, 0x177u},
	{1250u, 0x1Bu, 0x152u, 0x177u},
	{1300u, 0x2Bu, 0x152u, 0x177u},
	{1350u, 0x3Cu, 0x152u, 0x177u},
	{1400u, 0xCu, 0x152u, 0x177u},
	{1450u, 0x1Cu, 0x152u, 0x177u},
	{1500u, 0x2Cu, 0x152u, 0x177u},
	{1550u, 0x3Du, 0xD1u,  0xE8u},
	{1600u, 0xDu, 0xD8u,  0xF0u},
	{1650u, 0x1Du, 0xDEu,  0xF7u},
	{1700u, 0x2Eu, 0xE6u,  0xFFu},
	{1750u, 0x3Eu, 0xECu,  0x106u},
	{1800u, 0xEu, 0xF3u,  0x10Eu},
	{1850u, 0x1Eu, 0xF9u,  0x115u},
	{1900u, 0x2Fu, 0x101u, 0x11Du},
	{1950u, 0x3Fu, 0x107u, 0x124u},
	{2000u, 0xFu, 0x10Eu, 0x12Cu},
	{2050u, 0x40u, 0x114u, 0x133u},
	{2100u, 0x41u, 0x11Cu, 0x13Bu},
	{2150u, 0x42u, 0x122u, 0x142u},
	{2200u, 0x43u, 0x129u, 0x14Au},
	{2250u, 0x44u, 0x12Fu, 0x151u},
	{2300u, 0x45u, 0x137u, 0x159u},
	{2350u, 0x46u, 0x13Du, 0x160u},
	{2400u, 0x47u, 0x144u, 0x168u},
	{2450u, 0x48u, 0x14Au, 0x16Fu},
	{2500u, 0x49u, 0x152u, 0x177u}
};

#endif /* #if defined(DEVICE_TC45X) */

#if defined (_TASKING_) || defined (_ghs_)
#pragma restore
#endif
