/**
 * \file Ifx_Cfg.h
 * \brief Project configuration file.
 *
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
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
 */

#ifndef IFX_CFG_H
#define IFX_CFG_H 1
/******************************************************************************/

/*______________________________________________________________________________
** Configuration for IfxScu_cfg.h
**____________________________________________________________________________*/
#define IFX_CFG_SCU_XTAL_FREQUENCY		(20000000)	/**<allowed values 16000000, 20000000 or 40000000*/
//#define IFX_CFG_SCU_PLL_FREQUENCY		(200000000) /**<allowed values 80000000, 133000000, 160000000, 200000000, 240000000 or 300000000 */

/*______________________________________________________________________________
** Configuration for Software managed interrupt
**____________________________________________________________________________*/

//#define IFX_USE_SW_MANAGED_INT

/*______________________________________________________________________________
** Configuration for Trap Hook Functions' Extensions
**____________________________________________________________________________*/

//#define IFX_CFG_EXTEND_TRAP_HOOKS

/******************************************************************************/

#endif /* IFX_CFG_H */
