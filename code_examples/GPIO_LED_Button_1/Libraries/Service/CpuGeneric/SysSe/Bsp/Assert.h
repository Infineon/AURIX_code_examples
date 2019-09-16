/**
 * \file Assert.h
 * \brief Assert functions.
 * \ingroup library_srvsw_sysse_bsp_assert
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-28 14:15:34 GMT$
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
 * \defgroup library_srvsw_sysse_bsp_assert Assertion
 * This module implements assertion functions.
 * \ingroup library_srvsw_sysse_bsp
 */

#ifndef ASSERT_H
#define ASSERT_H 1

#include "_Utilities/Ifx_Assert.h"

/** \addtogroup library_srvsw_sysse_bsp_assert
 * Global configuration settings (Ifx_Cfg.h) :
 *     - IFX_CFG_ASSERT_STDIO: if IFX_CFG_ASSERT_STDIO=1, the assertion is output to the io
 *       defined by \ref Ifx_Assert_setStandardIo (). if IFX_CFG_ASSERT_STDIO=0, no text
 *       output is done.
 *       Default is IFX_CFG_ASSERT_STDIO=0
 *     - IFX_CFG_ASSERT_USE_BREAKPOINT: if IFX_CFG_ASSERT_USE_BREAKPOINT=1, a debug instruction is
 *       inserted in case an assertion occurs with a level of
 *       \ref IFX_VERBOSE_LEVEL_FAILURE or \ref IFX_VERBOSE_LEVEL_ERROR. If IFX_CFG_ASSERT_USE_BREAKPOINT=0 then
 *       no debug instruction is inserted.
 *       Default is IFX_CFG_ASSERT_USE_BREAKPOINT=0.
 *     - IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT: Set the assertion limit,
 *       assertion with a level below or equal to the limit are taken in
 *       account, other are ignored. range=[\ref IFX_VERBOSE_LEVEL_OFF, \ref IFX_VERBOSE_LEVEL_FAILURE,
 *       \ref IFX_VERBOSE_LEVEL_ERROR, \ref IFX_VERBOSE_LEVEL_WARNING, \ref IFX_VERBOSE_LEVEL_INFO,
 *       \ref IFX_VERBOSE_LEVEL_DEBUG]
 *       Default is IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT=\ref IFX_VERBOSE_LEVEL_INFO.
 *
 * Do not include this file but use # include "_Utilities/Ifx_Assert.h" instead
 * \{ */

#ifndef IFX_CFG_ASSERT_STDIO
#    define IFX_CFG_ASSERT_STDIO (0) /**<  \brief If set to 1, the assert message is send to the Assert_io interface */
#endif

#if IFX_CFG_ASSERT_STDIO == 1
#    include "StdIf/IfxStdIf_DPipe.h"
#endif

#ifndef IFX_CFG_ASSERT_USE_BREAKPOINT
#    define IFX_CFG_ASSERT_USE_BREAKPOINT    (0) /**<  \brief  If set to 1, the assert function will break the execution (breakpoint)  */
#endif

#ifndef IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT
/** \brief defines the assertion default level
 *
 * If not defined, the default assert level is set to IFX_VERBOSE_LEVEL_INFO
 * */
#define IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT (IFX_VERBOSE_LEVEL_INFO)
#endif

/** \brief Set the standard output used for \ref IFX_ASSERT and \ref IFX_VALIDATE
 *
 * For example the standard IO could redirect the output to a serial interface, CAN interface, ...
 *
 * \param standardIo Specifies the standard output used
 *
 * Enable only if (IFX_CFG_ASSERT_STDIO!=0)
 *
 * \return None.
 */
#if IFX_CFG_ASSERT_STDIO == 1
IFX_EXTERN void Ifx_Assert_setStandardIo(IfxStdIf_DPipe *standardIo);
#else
#define Ifx_Assert_setStandardIo(standardIo) ((void)0)
#endif

/** \internal
 * \brief Execute the assertion and display the assertion message
 *
 * Do not call this function directly, use IFX_ASSERT() instead
 *
 * \param level assertion level
 * \param __assertion test as string, is displayed with the assertion message
 * \param __file file in which the assertion occurred
 * \param __line line number where the assertion occurred
 * \param __function name of the function in which the assertion occurred
 * \return void
 */
IFX_EXTERN void Ifx_Assert_doLevel(uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function);

/** \internal
 * \brief Execute the assertion and display the assertion message.
 *
 * Do not call this function directly, use IFX_VALIDATE() instead
 *
 * \param expr expression value, assertion occurs if FALSE
 * \param level assertion level
 * \param __assertion test as string, is displayed with the assertion message
 * \param __file file in which the assertion occurred
 * \param __line line number where the assertion occurred
 * \param __function name of the function in which the assertion occurred
 * \return expr
 */
IFX_EXTERN boolean Ifx_Assert_doValidate(boolean expr, uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function);

#if IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT > IFX_VERBOSE_LEVEL_OFF
IFX_EXTERN uint32 Assert_verboseLevel; /**< \bri-ef Current verbose level, this value is initialised to IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT */

#else

#    undef IFX_CFG_ASSERT_STDIO
#    define IFX_CFG_ASSERT_STDIO (0)

#endif

#undef IFX_ASSERT
#undef IFX_VALIDATE

/** \brief Assertion function (assert)
 *
 * If  expr is FALSE, then an assertion message is displayed. The message
 * indicates the assertion level, the file, line and function where the
 * assertion occurred, and also display expr as text. In case the debug break
 * point is enabled then a debug instruction will also be inserted so that the debugger stops
 *
 * If expr is true, nothing is additional done.
 *
 * The expr expression is ignored (code disabled)  in case the assertion level set by IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT is \ref IFX_VERBOSE_LEVEL_OFF.
 *
 * The output needs to the be set with the function Ifx_Assert_setStandardIo() in order for the message to be displayed.
 *
 * \param level level of the assertion, range=[\ref IFX_VERBOSE_LEVEL_OFF, \ref IFX_VERBOSE_LEVEL_FAILURE,
 *              \ref IFX_VERBOSE_LEVEL_ERROR, \ref IFX_VERBOSE_LEVEL_WARNING, \ref IFX_VERBOSE_LEVEL_INFO,
 *              \ref IFX_VERBOSE_LEVEL_DEBUG]
 * \param expr expression to be tested. If FALSE the assertion is executed else nothing is done
 *
 * \return void
 */
#if IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT > IFX_VERBOSE_LEVEL_OFF
#    define IFX_ASSERT(level, expr)   (((expr) || (level > Assert_verboseLevel)) ? ((void)0) : Ifx_Assert_doLevel(level,#expr, __FILE__, __LINE__, __func__))
#else
#    define IFX_ASSERT(level, expr)   ((void)0)
#endif

/** \brief Assertion function (validate)
 *
 * If  expr is FALSE, then an assertion message is displayed. The message
 * indicates the assertion level, the file, line and function where the
 * assertion occurred, and also display expr as text. In case the debug
 * break point is enabled then a debug instruction will also be inserted so
 * that the debugger stops.
 *
 * \ref IFX_VALIDATE differs from \ref IFX_ASSERT in the way that the expr expression is
 * evaluated whatever the assertion level set by IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT.
 *
 * The output needs to the be set with the function Ifx_Assert_setStandardIo() in order for the message to be displayed.
 *
 * \param level level of the assertion, range=[\ref IFX_VERBOSE_LEVEL_OFF, \ref IFX_VERBOSE_LEVEL_FAILURE,
 *              \ref IFX_VERBOSE_LEVEL_ERROR, \ref IFX_VERBOSE_LEVEL_WARNING, \ref IFX_VERBOSE_LEVEL_INFO,
 *              \ref IFX_VERBOSE_LEVEL_DEBUG]
 * \param expr expression to be tested. If FALSE the assertion is executed else nothing is done
 *
 * \return void
 */
#if IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT > IFX_VERBOSE_LEVEL_OFF
#    define IFX_VALIDATE(level, expr) (Ifx_Assert_doValidate(expr, level,#expr, __FILE__, __LINE__, __func__))
#else
#    define IFX_VALIDATE(level, expr) (expr)
#endif

/** \} */

//#include "_Utilities/Ifx_Assert.h" /* Needs to be at the end of the file */

#endif
