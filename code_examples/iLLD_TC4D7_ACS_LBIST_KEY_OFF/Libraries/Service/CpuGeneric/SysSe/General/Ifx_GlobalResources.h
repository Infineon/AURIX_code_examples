/**
 * \file Ifx_GlobalResources.h
 * \brief Handling of global resources
 *
 * \version iLLD-TC4-v2.6.0
 * \copyright Copyright (c) 2026 Infineon Technologies AG. All rights reserved.
 *
 *
  *                                 IMPORTANT NOTICE
 *
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
 * \defgroup library_srvsw_sysse_general_globalresources Global resources
 * This module implements the global resources handling
 * \ingroup library_srvsw_sysse_general
 */

#ifndef IFX_GLOBALRESOURCES_H
#define IFX_GLOBALRESOURCES_H 1

#include "Ifx_Cfg.h"
#include "Ifx_Types.h"

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
