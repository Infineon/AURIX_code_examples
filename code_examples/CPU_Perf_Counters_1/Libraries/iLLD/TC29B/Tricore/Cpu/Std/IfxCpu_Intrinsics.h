/**
 * \file IfxCpu_Intrinsics.h
 * \ingroup IfxLld_Cpu_Intrinsics Intrinsics
 *
 * \version iLLD_1_0_1_9_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Cpu_Intrinsics Intrinsics
 * \ingroup IfxLld_Cpu_Std
 *
 */
#ifndef IFXCPU_INTRINSICS_H
#define IFXCPU_INTRINSICS_H
/******************************************************************************/
#include "Ifx_Types.h"

#if defined(__DCC__)
#include "IfxCpu_IntrinsicsDcc.h"

#elif defined(__HIGHTEC__)
#include "IfxCpu_IntrinsicsGnuc.h"

#elif defined(__TASKING__)
#include "IfxCpu_IntrinsicsTasking.h"

#elif defined(__ghs__)
#include "IfxCpu_IntrinsicsGhs.h"

#else
#error Compiler unsupported
#endif

#define IFX_ALIGN_8   (1)            // Align on 8 bit Boundary
#define IFX_ALIGN_16  (2)            // Align on 16 bit Boundary
#define IFX_ALIGN_32  (4)            // Align on 32 bit Boundary
#define IFX_ALIGN_64  (8)            // Align on 64 bit Boundary
#define IFX_ALIGN_128 (16)           // Align on 128 bit Boundary
#define IFX_ALIGN_256 (32)           // Align on 256 bit Boundary

#define Ifx_AlignOn256(Size) ((((Size) + (IFX_ALIGN_256 - 1)) & (~(IFX_ALIGN_256 - 1))))
#define Ifx_AlignOn128(Size) ((((Size) + (IFX_ALIGN_128 - 1)) & (~(IFX_ALIGN_128 - 1))))
#define Ifx_AlignOn64(Size)  ((((Size) + (IFX_ALIGN_64 - 1)) & (~(IFX_ALIGN_64 - 1))))
#define Ifx_AlignOn32(Size)  ((((Size) + (IFX_ALIGN_32 - 1)) & (~(IFX_ALIGN_32 - 1))))
#define Ifx_AlignOn16(Size)  ((((Size) + (IFX_ALIGN_16 - 1)) & (~(IFX_ALIGN_16 - 1))))
#define Ifx_AlignOn8(Size)   ((((Size) + (IFX_ALIGN_8 - 1)) & (~(IFX_ALIGN_8 - 1))))

#define Ifx_COUNTOF(x)       (sizeof(x) / sizeof(x[0]))

//______________________________________________________________________________

/** Convert context pointer to address pointer
 * \param[in] cx context pointer
 * \return address pointer
 */
IFX_INLINE void *__cx_to_addr(uint32 cx)
{
    uint32 seg_nr = __extru(cx, 16, 4);
    return (void *)__insert(seg_nr << 28, cx, 6, 16);
}


/** Convert address pointer to context pointer
 * \param[in] addr address pointer
 * \return context pointer
 */
IFX_INLINE uint32 __addr_to_cx(void *addr)
{
    uint32 seg_nr, seg_idx;
    seg_nr  = __extru((int)addr, 28, 4) << 16;
    seg_idx = __extru((int)addr, 6, 16);
    return seg_nr | seg_idx;
}


/******************************************************************************/
IFX_INLINE void __ldmst_c(volatile void *address, unsigned mask, unsigned value)
{
    *(volatile uint32 *)address = (*(volatile uint32 *)address & ~(mask)) | (mask & value);
}


/** 32bit load operation
 */
IFX_INLINE uint32 __ld32(void *addr)
{
    return *(volatile uint32 *)addr;
}


/** 32bit store operation
 */
IFX_INLINE void __st32(void *addr, uint32 value)
{
    *(volatile uint32 *)addr = value;
}


/** 64bit load operation
 */
IFX_INLINE uint64 __ld64(void *addr)
{
    return *(volatile uint64 *)addr;
}


/** 64bit store operation
 */
IFX_INLINE void __st64(void *addr, uint64 value)
{
    *(volatile uint64 *)addr = value;
}


/** 64bit load operation which returns the lower and upper 32bit word
 */
IFX_INLINE void __ld64_lu(void *addr, uint32 *valueLower, uint32 *valueUpper)
{
    register uint64 value;
    value       = __ld64(addr);
    *valueLower = (uint32)value;
    *valueUpper = (uint32)(value >> 32);
}


/** 64bit store operation which stores a lower and upper 32bit word
 */
IFX_INLINE void __st64_lu(void *addr, uint32 valueLower, uint32 valueUpper)
{
    register uint64 value = ((uint64)valueUpper << 32) | valueLower;
    __st64(addr, value);
}


/******************************************************************************/
#endif /* IFXCPU_INTRINSICS_H */
