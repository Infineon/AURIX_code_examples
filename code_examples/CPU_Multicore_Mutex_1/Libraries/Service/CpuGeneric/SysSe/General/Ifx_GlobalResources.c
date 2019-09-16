/**
 * \file Ifx_GlobalResources.h
 * \brief Handling of global resources
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:36 GMT$
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
