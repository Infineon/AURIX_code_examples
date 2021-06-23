/**
 * \file IfxFlash_cfg.c
 * \brief FLASH on-chip implementation data
 *
 * \version iLLD_1_0_1_12_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxFlash_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableCfsLog[IFXFLASH_DFLASH_NUM_CFS_LOG_SECTORS] = {
    {0xaf800000, 0xaf800fff}, //CFS0
    {0xaf801000, 0xaf801fff}, //CFS1
    {0xaf802000, 0xaf802fff}, //CFS2
    {0xaf803000, 0xaf803fff}, //CFS3
    {0xaf804000, 0xaf804fff}, //CFS4
    {0xaf805000, 0xaf805fff}, //CFS5
    {0xaf806000, 0xaf806fff}, //CFS6
    {0xaf807000, 0xaf807fff}, //CFS7
    {0xaf808000, 0xaf808fff}, //CFS8
    {0xaf809000, 0xaf809fff}, //CFS9
    {0xaf80a000, 0xaf80afff}, //CFS10
    {0xaf80b000, 0xaf80bfff}, //CFS11
    {0xaf80c000, 0xaf80cfff}, //CFS12
    {0xaf80d000, 0xaf80dfff}, //CFS13
    {0xaf80e000, 0xaf80efff}, //CFS14
    {0xaf80f000, 0xaf80ffff}, //CFS15
}


;

IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableEepLog[IFXFLASH_DFLASH_NUM_LOG_SECTORS] = {
    {0xAF000000, 0xAF000FFF},
    {0xAF001000, 0xAF001FFF},
    {0xAF002000, 0xAF002FFF},
    {0xAF003000, 0xAF003FFF},
    {0xAF004000, 0xAF004FFF},
    {0xAF005000, 0xAF005FFF},
    {0xAF006000, 0xAF006FFF},
    {0xAF007000, 0xAF007FFF},
    {0xAF008000, 0xAF008FFF},
    {0xAF009000, 0xAF009FFF},
    {0xAF00A000, 0xAF00AFFF},
    {0xAF00B000, 0xAF00BFFF},
    {0xAF00C000, 0xAF00CFFF},
    {0xAF00D000, 0xAF00DFFF},
    {0xAF00E000, 0xAF00EFFF},
    {0xAF00F000, 0xAF00FFFF},
    {0xAF010000, 0xAF010FFF},
    {0xAF011000, 0xAF011FFF},
    {0xAF012000, 0xAF012FFF},
    {0xAF013000, 0xAF013FFF},
    {0xAF014000, 0xAF014FFF},
    {0xAF015000, 0xAF015FFF},
    {0xAF016000, 0xAF016FFF},
    {0xAF017000, 0xAF017FFF},
    {0xAF018000, 0xAF018FFF},
    {0xAF019000, 0xAF019FFF},
    {0xAF01A000, 0xAF01AFFF},
    {0xAF01B000, 0xAF01BFFF},
    {0xAF01C000, 0xAF01CFFF},
    {0xAF01D000, 0xAF01DFFF},
    {0xAF01E000, 0xAF01EFFF},
    {0xAF01F000, 0xAF01FFFF},
};

IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableHsmLog[IFXFLASH_DFLASH_NUM_HSM_LOG_SECTORS] = {
    {0xAFC00000, 0xAFC00FFF},   //HSM0
    {0xAFC01000, 0xAFC01FFF},   //HSM1
    {0xAFC02000, 0xAFC02FFF},   //HSM2
    {0xAFC03000, 0xAFC03FFF},   //HSM3
    {0xAFC04000, 0xAFC04FFF},   //HSM4
    {0xAFC05000, 0xAFC05FFF},   //HSM5
    {0xAFC06000, 0xAFC06FFF},   //HSM6
    {0xAFC07000, 0xAFC07FFF},   //HSM7
    {0xAFC08000, 0xAFC08FFF},   //HSM8
    {0xAFC09000, 0xAFC09FFF},   //HSM9
    {0xAFC0A000, 0xAFC0AFFF},   //HSM10
    {0xAFC0B000, 0xAFC0BFFF},   //HSM11
    {0xAFC0C000, 0xAFC0CFFF},   //HSM12
    {0xAFC0D000, 0xAFC0DFFF},   //HSM13
    {0xAFC0E000, 0xAFC0EFFF},   //HSM14
    {0xAFC0F000, 0xAFC0FFFF},   //HSM15
    {0xAFC10000, 0xAFC10FFF},   //HSM16
    {0xAFC11000, 0xAFC11FFF},   //HSM17
    {0xAFC12000, 0xAFC12FFF},   //HSM18
    {0xAFC13000, 0xAFC13FFF},   //HSM19
    {0xAFC14000, 0xAFC14FFF},   //HSM20
    {0xAFC15000, 0xAFC15FFF},   //HSM21
    {0xAFC16000, 0xAFC16FFF},   //HSM22
    {0xAFC17000, 0xAFC17FFF},   //HSM23
    {0xAFC18000, 0xAFC18FFF},   //HSM24
    {0xAFC19000, 0xAFC19FFF},   //HSM25
    {0xAFC1A000, 0xAFC1AFFF},   //HSM26
    {0xAFC1B000, 0xAFC1BFFF},   //HSM27
    {0xAFC1C000, 0xAFC1CFFF},   //HSM28
    {0xAFC1D000, 0xAFC1DFFF},   //HSM29
    {0xAFC1E000, 0xAFC1EFFF},   //HSM30
    {0xAFC1F000, 0xAFC1FFFF},   //HSM31
};

IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTablePhys[IFXFLASH_DFLASH_NUM_PHYSICAL_SECTORS] = {
    {IFXFLASH_DFLASH_START, IFXFLASH_DFLASH_END},
};

IFX_CONST IfxFlash_flashSector IfxFlash_dFlashTableUcbLog[IFXFLASH_DFLASH_NUM_UCB_LOG_SECTORS] = {
    {0xAF400000, 0xAF4001FF},   //UCB0
    {0xAF400200, 0xAF4003FF},   //UCB1
    {0xAF400400, 0xAF4005FF},   //UCB2
    {0xAF400600, 0xAF4007FF},   //UCB3
    {0xAF400800, 0xAF4009FF},   //UCB4
    {0xAF400A00, 0xAF400BFF},   //UCB5
    {0xAF400C00, 0xAF400DFF},   //UCB6
    {0xAF400E00, 0xAF400FFF},   //UCB7
    {0xAF401000, 0xAF4011FF},   //UCB8
    {0xAF401200, 0xAF4013FF},   //UCB9
    {0xAF401400, 0xAF4015FF},   //UCB10
    {0xAF401600, 0xAF4017FF},   //UCB11
    {0xAF401800, 0xAF4019FF},   //UCB12
    {0xAF401A00, 0xAF401BFF},   //UCB13
    {0xAF401C00, 0xAF401DFF},   //UCB14
    {0xAF401E00, 0xAF401FFF},   //UCB15
    {0xAF402000, 0xAF4021FF},   //UCB16
    {0xAF402200, 0xAF4023FF},   //UCB17
    {0xAF402400, 0xAF4025FF},   //UCB18
    {0xAF402600, 0xAF4027FF},   //UCB19
    {0xAF402800, 0xAF4029FF},   //UCB20
    {0xAF402A00, 0xAF402BFF},   //UCB21
    {0xAF402C00, 0xAF402DFF},   //UCB22
    {0xAF402E00, 0xAF402FFF},   //UCB23
    {0xAF403000, 0xAF4031FF},   //UCB24
    {0xAF403200, 0xAF4033FF},   //UCB25
    {0xAF403400, 0xAF4035FF},   //UCB26
    {0xAF403600, 0xAF4037FF},   //UCB27
    {0xAF403800, 0xAF4039FF},   //UCB28
    {0xAF403A00, 0xAF403BFF},   //UCB29
    {0xAF403C00, 0xAF403DFF},   //UCB30
    {0xAF403E00, 0xAF403FFF},   //UCB31
    {0xAF404000, 0xAF4041FF},   //UCB32
    {0xAF404200, 0xAF4043FF},   //UCB33
    {0xAF404400, 0xAF4045FF},   //UCB34
    {0xAF404600, 0xAF4047FF},   //UCB35
    {0xAF404800, 0xAF4049FF},   //UCB36
    {0xAF404A00, 0xAF404BFF},   //UCB37
    {0xAF404C00, 0xAF404DFF},   //UCB38
    {0xAF404E00, 0xAF404FFF},   //UCB39
    {0xAF405000, 0xAF4051FF},   //UCB40
    {0xAF405200, 0xAF4053FF},   //UCB41
    {0xAF405400, 0xAF4055FF},   //UCB42
    {0xAF405600, 0xAF4057FF},   //UCB43
    {0xAF405800, 0xAF4059FF},   //UCB44
    {0xAF405A00, 0xAF405BFF},   //UCB45
    {0xAF405C00, 0xAF405DFF},   //UCB46
    {0xAF405E00, 0xAF405FFF},   //UCB47
};

IFX_CONST IfxFlash_flashSector IfxFlash_pFlashTableLog[IFXFLASH_PFLASH_NUM_LOG_SECTORS] = {
    {0xA0000000, 0xA0003FFF},      //   PF0 S0
    {0xA0004000, 0xA0007FFF},      //	PF0 S1
    {0xA0008000, 0xA000BFFF},      //	PF0 S2
    {0xA000C000, 0xA000FFFF},      //	PF0 S3
    {0xA0010000, 0xA0013FFF},      //	PF0 S4
    {0xA0014000, 0xA0017FFF},      //	PF0 S5
    {0xA0018000, 0xA001BFFF},      //	PF0 S6
    {0xA001C000, 0xA001FFFF},      //	PF0 S7
    {0xA0020000, 0xA0023FFF},      //	PF0 S8
    {0xA0024000, 0xA0027FFF},      //	PF0 S9
    {0xA0028000, 0xA002BFFF},      //	PF0 S10
    {0xA002C000, 0xA002FFFF},      //	PF0 S11
    {0xA0030000, 0xA0033FFF},      //	PF0 S12
    {0xA0034000, 0xA0037FFF},      //	PF0 S13
    {0xA0038000, 0xA003BFFF},      //	PF0 S14
    {0xA003C000, 0xA003FFFF},      //	PF0 S15
    {0xA0040000, 0xA0043FFF},      //	PF0 S16
    {0xA0044000, 0xA0047FFF},      //	PF0 S17
    {0xA0048000, 0xA004BFFF},      //	PF0 S18
    {0xA004C000, 0xA004FFFF},      //	PF0 S19
    {0xA0050000, 0xA0053FFF},      //	PF0 S20
    {0xA0054000, 0xA0057FFF},      //	PF0 S21
    {0xA0058000, 0xA005BFFF},      //	PF0 S22
    {0xA005C000, 0xA005FFFF},      //	PF0 S23
    {0xA0060000, 0xA0063FFF},      //	PF0 S24
    {0xA0064000, 0xA0067FFF},      //	PF0 S25
    {0xA0068000, 0xA006BFFF},      //	PF0 S26
    {0xA006C000, 0xA006FFFF},      //	PF0 S27
    {0xA0070000, 0xA0073FFF},      //	PF0 S28
    {0xA0074000, 0xA0077FFF},      //	PF0 S29
    {0xA0078000, 0xA007BFFF},      //	PF0 S30
    {0xA007C000, 0xA007FFFF},      //	PF0 S31
    {0xA0080000, 0xA0083FFF},      //	PF0 S32
    {0xA0084000, 0xA0087FFF},      //	PF0 S33
    {0xA0088000, 0xA008BFFF},      //	PF0 S34
    {0xA008C000, 0xA008FFFF},      //	PF0 S35
    {0xA0090000, 0xA0093FFF},      //	PF0 S36
    {0xA0094000, 0xA0097FFF},      //	PF0 S37
    {0xA0098000, 0xA009BFFF},      //	PF0 S38
    {0xA009C000, 0xA009FFFF},      //	PF0 S39
    {0xA00A0000, 0xA00A3FFF},      //	PF0 S40
    {0xA00A4000, 0xA00A7FFF},      //	PF0 S41
    {0xA00A8000, 0xA00ABFFF},      //	PF0 S42
    {0xA00AC000, 0xA00AFFFF},      //	PF0 S43
    {0xA00B0000, 0xA00B3FFF},      //	PF0 S44
    {0xA00B4000, 0xA00B7FFF},      //	PF0 S45
    {0xA00B8000, 0xA00BBFFF},      //	PF0 S46
    {0xA00BC000, 0xA00BFFFF},      //	PF0 S47
    {0xA00C0000, 0xA00C3FFF},      //	PF0 S48
    {0xA00C4000, 0xA00C7FFF},      //	PF0 S49
    {0xA00C8000, 0xA00CBFFF},      //	PF0 S50
    {0xA00CC000, 0xA00CFFFF},      //	PF0 S51
    {0xA00D0000, 0xA00D3FFF},      //	PF0 S52
    {0xA00D4000, 0xA00D7FFF},      //	PF0 S53
    {0xA00D8000, 0xA00DBFFF},      //	PF0 S54
    {0xA00DC000, 0xA00DFFFF},      //	PF0 S55
    {0xA00E0000, 0xA00E3FFF},      //	PF0 S56
    {0xA00E4000, 0xA00E7FFF},      //	PF0 S57
    {0xA00E8000, 0xA00EBFFF},      //	PF0 S58
    {0xA00EC000, 0xA00EFFFF},      //	PF0 S59
    {0xA00F0000, 0xA00F3FFF},      //	PF0 S60
    {0xA00F4000, 0xA00F7FFF},      //	PF0 S61
    {0xA00F8000, 0xA00FBFFF},      //	PF0 S62
    {0xA00FC000, 0xA00FFFFF},      //	PF0 S63
    {0xA0100000, 0xA0103FFF},      //	PF0 S64
    {0xA0104000, 0xA0107FFF},      //	PF0 S65
    {0xA0108000, 0xA010BFFF},      //	PF0 S66
    {0xA010C000, 0xA010FFFF},      //	PF0 S67
    {0xA0110000, 0xA0113FFF},      //	PF0 S68
    {0xA0114000, 0xA0117FFF},      //	PF0 S69
    {0xA0118000, 0xA011BFFF},      //	PF0 S70
    {0xA011C000, 0xA011FFFF},      //	PF0 S71
    {0xA0120000, 0xA0123FFF},      //	PF0 S72
    {0xA0124000, 0xA0127FFF},      //	PF0 S73
    {0xA0128000, 0xA012BFFF},      //	PF0 S74
    {0xA012C000, 0xA012FFFF},      //	PF0 S75
    {0xA0130000, 0xA0133FFF},      //	PF0 S76
    {0xA0134000, 0xA0137FFF},      //	PF0 S77
    {0xA0138000, 0xA013BFFF},      //	PF0 S78
    {0xA013C000, 0xA013FFFF},      //	PF0 S79
    {0xA0140000, 0xA0143FFF},      //	PF0 S80
    {0xA0144000, 0xA0147FFF},      //	PF0 S81
    {0xA0148000, 0xA014BFFF},      //	PF0 S82
    {0xA014C000, 0xA014FFFF},      //	PF0 S83
    {0xA0150000, 0xA0153FFF},      //	PF0 S84
    {0xA0154000, 0xA0157FFF},      //	PF0 S85
    {0xA0158000, 0xA015BFFF},      //	PF0 S86
    {0xA015C000, 0xA015FFFF},      //	PF0 S87
    {0xA0160000, 0xA0163FFF},      //	PF0 S88
    {0xA0164000, 0xA0167FFF},      //	PF0 S89
    {0xA0168000, 0xA016BFFF},      //	PF0 S90
    {0xA016C000, 0xA016FFFF},      //	PF0 S91
    {0xA0170000, 0xA0173FFF},      //	PF0 S92
    {0xA0174000, 0xA0177FFF},      //	PF0 S93
    {0xA0178000, 0xA017BFFF},      //	PF0 S94
    {0xA017C000, 0xA017FFFF},      //	PF0 S95
    {0xA0180000, 0xA0183FFF},      //	PF0 S96
    {0xA0184000, 0xA0187FFF},      //	PF0 S97
    {0xA0188000, 0xA018BFFF},      //	PF0 S98
    {0xA018C000, 0xA018FFFF},      //	PF0 S99
    {0xA0190000, 0xA0193FFF},      //	PF0 S100
    {0xA0194000, 0xA0197FFF},      //	PF0 S101
    {0xA0198000, 0xA019BFFF},      //	PF0 S102
    {0xA019C000, 0xA019FFFF},      //	PF0 S103
    {0xA01A0000, 0xA01A3FFF},      //	PF0 S104
    {0xA01A4000, 0xA01A7FFF},      //	PF0 S105
    {0xA01A8000, 0xA01ABFFF},      //	PF0 S106
    {0xA01AC000, 0xA01AFFFF},      //	PF0 S107
    {0xA01B0000, 0xA01B3FFF},      //	PF0 S108
    {0xA01B4000, 0xA01B7FFF},      //	PF0 S109
    {0xA01B8000, 0xA01BBFFF},      //	PF0 S110
    {0xA01BC000, 0xA01BFFFF},      //	PF0 S111
    {0xA01C0000, 0xA01C3FFF},      //	PF0 S112
    {0xA01C4000, 0xA01C7FFF},      //	PF0 S113
    {0xA01C8000, 0xA01CBFFF},      //	PF0 S114
    {0xA01CC000, 0xA01CFFFF},      //	PF0 S115
    {0xA01D0000, 0xA01D3FFF},      //	PF0 S116
    {0xA01D4000, 0xA01D7FFF},      //	PF0 S117
    {0xA01D8000, 0xA01DBFFF},      //	PF0 S118
    {0xA01DC000, 0xA01DFFFF},      //	PF0 S119
    {0xA01E0000, 0xA01E3FFF},      //	PF0 S120
    {0xA01E4000, 0xA01E7FFF},      //	PF0 S121
    {0xA01E8000, 0xA01EBFFF},      //	PF0 S122
    {0xA01EC000, 0xA01EFFFF},      //	PF0 S123
    {0xA01F0000, 0xA01F3FFF},      //	PF0 S124
    {0xA01F4000, 0xA01F7FFF},      //	PF0 S125
    {0xA01F8000, 0xA01FBFFF},      //	PF0 S126
    {0xA01FC000, 0xA01FFFFF},      //	PF0 S127
};

IFX_CONST IfxFlash_flashSector IfxFlash_pFlashTablePhys[IFXFLASH_PFLASH_NUM_PHYSICAL_SECTORS] = {
    {0xA0000000, 0xA00FFFFF}, /* PF0 PS0*/
    {0xA0100000, 0xA01FFFFF}, /* PF0 PS1*/
};