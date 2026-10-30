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
 */

#include "Ifx_GlobalResources.h"
/** \brief Global resource object */
typedef struct
{
    const Ifx_GlobalResources_Item *table;  /**< \brief Pointer to the global resource table */
    sint32                          size;   /**< \brief Size of the global resource table */
} Ifx_GlobalResources;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED

Ifx_GlobalResources ifx_GlobalResource;
#endif

void *Ifx_GlobalResources_get(sint32 id)
{
    void *result;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED

    if (id < ifx_GlobalResource.size)
    {
        result = ifx_GlobalResource.table[id].resource;
    }
    else
    {
        result = NULL_PTR;
    }

#else
    result = NULL_PTR;

#endif

    return result;
}


sint32 Ifx_GlobalResources_getIndex(void *resource)
{
    sint32 id = -1;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED
    int    i;

    for (i = 0; i < ifx_GlobalResource.size; i++)
    {
        if (resource == ifx_GlobalResource.table[i].resource)
        {
            id = i;
        }
        else
        {}
    }

#else
#endif

    return id;
}


const Ifx_GlobalResources_Item *Ifx_GlobalResources_getItem(sint32 id)
{
    const Ifx_GlobalResources_Item *result;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED

    if (id < ifx_GlobalResource.size)
    {
        result = &ifx_GlobalResource.table[id];
    }
    else
    {
        result = NULL_PTR;
    }

#else
    result = NULL_PTR;

#endif

    return result;
}


pchar Ifx_GlobalResources_getName(sint32 id)
{
    pchar name;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED

    if (id < ifx_GlobalResource.size)
    {
        name = ifx_GlobalResource.table[id].name;
    }
    else
    {
        name = "unknown";
    }

#else
    name = "unknown";

#endif

    return name;
}


boolean Ifx_GlobalResources_init(const Ifx_GlobalResources_Item *table, uint32 size)
{
    boolean result;

#if IFX_CFG_GLOBAL_RESOURCES_ENABLED
    ifx_GlobalResource.table = table;
    ifx_GlobalResource.size  = size;
    result                   = TRUE;
#else
    result                   = FALSE;

#endif

    return result;
}
