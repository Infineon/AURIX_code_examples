/**
 * \file Ifx_GlobalResources.h
 * \brief Handling of global resources
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:39 GMT$
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
 * \defgroup library_srvsw_sysse_general_globalresources Global resources
 * This module implements the global resources handling
 * \ingroup library_srvsw_sysse_general
 */

#ifndef IFX_GLOBALRESOURCES_H
#define IFX_GLOBALRESOURCES_H            1

#include "Ifx_Cfg.h"
#include "Cpu/Std/Ifx_Types.h"

#ifndef IFX_CFG_GLOBAL_RESOURCES_ENABLED
#define IFX_CFG_GLOBAL_RESOURCES_ENABLED (0)
#endif

typedef struct
{
    void *resource;
    pchar name;
} Ifx_GlobalResources_Item;

/** \addtogroup library_srvsw_sysse_general_globalresources
 * \{ */
/** Return a pointer to the global resource
 *
 * \param id index of the Ifx_GlobalResources_Item in the table, the index starts with 0
 *
 * \return return Ifx_GlobalResources_Item.resource
 */
IFX_EXTERN void *Ifx_GlobalResources_get(sint32 id);

/** \brief Returns the global resource index.
 *
 * \return Returns the global resource index, -1 if not found
 */
IFX_EXTERN sint32 Ifx_GlobalResources_getIndex(void *resource);

/** Return a pointer to the global resource item
 *
 * \param id index of the Ifx_GlobalResources_Item in the table, the index starts with 0
 *
 * \return return the Ifx_GlobalResources_Item
 */
IFX_EXTERN const Ifx_GlobalResources_Item *Ifx_GlobalResources_getItem(sint32 id);

/** Return a the resource name as an NULL terminated string
 *
 * \param id index of the Ifx_GlobalResources_Item in the table, the index starts with 0
 *
 * \return return Ifx_GlobalResources_Item.name
 */
IFX_EXTERN pchar Ifx_GlobalResources_getName(sint32 id);

/** Initialize the global resource handler
 *
 * \param table pointer to an array of Ifx_GlobalResources_Item
 * \param size number of item in the table corresponds to sizeof(table)
 *
 * return returns TRUE in case of success else FALSE
 *
 */
IFX_EXTERN boolean Ifx_GlobalResources_init(const Ifx_GlobalResources_Item *table, uint32 size);
/** \} */

#endif /* IFX_GLOBALRESOURCES_H */
