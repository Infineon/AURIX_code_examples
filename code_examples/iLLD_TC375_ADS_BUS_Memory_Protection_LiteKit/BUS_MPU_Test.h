/**********************************************************************************************************************
 * \file BUS_MPU_Test.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#ifndef BUS_MPU_TEST_H
#define BUS_MPU_TEST_H

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxPort.h"
#include "Bsp.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/* LEDs */
#define LED_ERROR         &MODULE_P00, 5
#define LED_SUCCESS       &MODULE_P00, 6

/* Cores */
#define TEST_CORE_0                 0
#define TEST_CORE_1                 1

/* Tests on different sections (memories) */
/* Define Test1(DLMU,SPR,PFlash), Test2(DLMU,SPR,PFlash) and Test3(DLMU,SPR,PFlash)-Overlap/NonOverlap */
#define TEST_1_DLMU                 1
#define TEST_1_SPR                  2
#define TEST_1_PFLASH               3

#define TEST_2_DLMU                 4
#define TEST_2_SPR                  5
#define TEST_2_PFLASH               6

#define TEST_3_DLMU_NON_OVERLAP     7
#define TEST_3_SPR_NON_OVERLAP      8
#define TEST_3_PFLASH               9

#define TEST_3_DLMU_OVERLAP         10
#define TEST_3_SPR_OVERLAP          11

/* Choosing each cores as the test configuration core and the test execution core */
/* Default: core0 is using as the test configuration and core1 is using as the test execution  */
#define TEST_CORE_CONFIG            TEST_CORE_0
#define TEST_CORE_EXECUTE           TEST_CORE_1

/**
 * @brief Test Examples
 *
 * Test 1 : Full Access
 * Test 2 : Non-Overlap Region => CPU0 -> R0, CPU0 !-> R1, CPU1 !-> R0, CPU1 !-> R1
 * Test 3 : Overlap Region => CPU0 -> R0, CPU0 !-> R1, CPU1 !-> R0, CPU1 -> R1
 * (Note: in Test3 "configuration" has been done for overlapping R0 and R1, but "execution"
   done for both overlap, and Non-overlap regions.)
 */

/* Region size must be aligned to 2^5 (bits 4:0 of the protection regions registers are reserved)               */
#define REGION_SIZE                 32                                    /* Byte - range size                  */
#define REGION_NUM                  8                                     /* Numbers of ranges                  */

#define ALL_REGION_SIZE             (REGION_NUM * REGION_SIZE)

/*********************************************************************************************************************/
/*---------------------------------Function Implementations for Test1, Test2, and Test3 -----------------------------*/
/*********************************************************************************************************************/
/* LED control function */
void Test_LED_init(void);

/* Function for Test1 configuration/execution */
void Test1_DLMU_configuration(void);
void Test1_DLMU_execute(void);
void Test1_SPR_configuration(void);
void Test1_SPR_execute(void);
void Test1_PFlash_configuration(void);
void Test1_PFlash_execute(void);

/* Function for Test2 configuration/execution */
void Test2_DLMU_configuration(void);
void Test2_DLMU_execute(void);
void Test2_SPR_configuration(void);
void Test2_SPR_execute(void);
void Test2_PFlash_configuration(void);
void Test2_PFlash_execute(void);

/* Function for Test3 configuration/execution */
void Test3_DLMU_configuration(void);
void Test3_DLMU_NonOverlap_execute(void);
void Test3_DLMU_Overlap_execute(void);
void Test3_SPR_configuration(void);
void Test3_SPR_NonOverlap_execute(void);
void Test3_SPR_Overlap_execute(void);
void Test3_PFlash_configuration(void);
void Test3_PFlash_execute(void);


#endif // _BUS_MPU_TEST_H_
