/**
 * \file IfxMultican_cfg.h
 * \brief MULTICAN on-chip implementation data 
 * \ingroup IfxLld_Multican 
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Multican MULTICAN
 * \ingroup IfxLld
 * \defgroup IfxLld_Multican_Impl Implementation
 * \ingroup IfxLld_Multican
 * \defgroup IfxLld_Multican_Std Standard Driver
 * \ingroup IfxLld_Multican
 */

#ifndef IFXMULTICAN_CFG_H
#define IFXMULTICAN_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "IfxCan_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of CAN message objects 
 */
#define IFXMULTICAN_NUM_MESSAGE_OBJECTS (256)
                
/** \brief Number of CAN nodes 
 */
#define IFXMULTICAN_NUM_NODES (4)
                
/** \brief Number of service requests 
 */
#define IFXMULTICAN_NUM_SRC (16)
                
/** \brief Number of CANR message objects 
 */
#define IFXMULTICAN_R_NUM_MESSAGE_OBJECTS (128)
                
/** \brief Number of CANR nodes 
 */
#define IFXMULTICAN_R_NUM_NODES (2)
                
/** \brief Number of CANR service requests 
 */
#define IFXMULTICAN_R_NUM_SRC (8)
                
#define IFXMULTICAN_NUM_MODULES (2)
                
/** \brief Number of CANR service requests 
 */
#define IFXMULTICAN_R_NUM_SRC (8)
                


/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available multican resource.  
 */
typedef enum
{
    IfxMultican_Index_none = -1,                   /**< \brief Not Selected */
    IfxMultican_Index_0 = 0,      /**< \brief MULTICAN index 0  */
    IfxMultican_Index_1           /**< \brief MULTICAN index 1  */
} IfxMultican_Index;

/** \brief CAN Nodes definition  
 */
typedef enum
{
    IfxMultican_NodeId_none = -1,                    /**< \brief None of the Ifx_CAN Nodes */
    IfxMultican_NodeId_0 = 0,      /**< \brief Ifx_CAN Node 0  */
    IfxMultican_NodeId_1,          /**< \brief Ifx_CAN Node 1  */
    IfxMultican_NodeId_2,          /**< \brief Ifx_CAN Node 2  */
    IfxMultican_NodeId_3           /**< \brief Ifx_CAN Node 3  */
} IfxMultican_NodeId;

/** \brief Service request ID  
 */
typedef enum
{
    IfxMultican_SrcId_0 = 0,      /**< \brief Service request ID 0  */
    IfxMultican_SrcId_1,          /**< \brief Service request ID 1  */
    IfxMultican_SrcId_2,          /**< \brief Service request ID 2  */
    IfxMultican_SrcId_3,          /**< \brief Service request ID 3  */
    IfxMultican_SrcId_4,          /**< \brief Service request ID 4  */
    IfxMultican_SrcId_5,          /**< \brief Service request ID 5  */
    IfxMultican_SrcId_6,          /**< \brief Service request ID 6  */
    IfxMultican_SrcId_7,          /**< \brief Service request ID 7  */
    IfxMultican_SrcId_8,          /**< \brief Service request ID 8  */
    IfxMultican_SrcId_9,          /**< \brief Service request ID 9  */
    IfxMultican_SrcId_10,         /**< \brief Service request ID 10  */
    IfxMultican_SrcId_11,         /**< \brief Service request ID 11  */
    IfxMultican_SrcId_12,         /**< \brief Service request ID 12  */
    IfxMultican_SrcId_13,         /**< \brief Service request ID 13  */
    IfxMultican_SrcId_14,         /**< \brief Service request ID 14  */
    IfxMultican_SrcId_15          /**< \brief Service request ID 15  */
} IfxMultican_SrcId;


/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxMultican_cfg_indexMap[IFXMULTICAN_NUM_MODULES];


#endif /* IFXMULTICAN_CFG_H */
