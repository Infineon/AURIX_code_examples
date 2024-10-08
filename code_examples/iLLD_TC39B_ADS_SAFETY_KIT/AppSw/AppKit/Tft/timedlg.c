/**********************************************************************************************************************
 * \file timedlg.c
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

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <Cpu/Std/Ifx_Types.h>
#include <Cpu/Std/IfxCpu_Intrinsics.h>
#include "Configuration.h"
#if USE_RTC
#include "conio_tft.h"
#include "touch.h"
#include <string.h>
#include <stdio.h>
#include "RTC.h"
/******************************************************************************/
/*------------------------Inline Function Prototypes--------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
//specific entries timedlg.c, contains the amount of entries for timedlg selection up, down, OK and Cancel
#define TIMEDLG_BUTTONS      14
#define CALIBRATION_BUTTONS   1

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
void timedlg_display (sint32 ind, TDISPLAYENTRY * pdisplayentry);
sint32 timedlg_input (sint32 ind, TDISPLAYENTRY * pdisplayentry);
void timedlg_select_ok (sint32 ind, TDISPLAYENTRY * pdisplayentry);            //special call back for OK
void timedlg_select_cancel (sint32 ind, TDISPLAYENTRY * pdisplayentry);        //special call back for CANCEL
void timedlg_select_up_down (sint32 ind, TDISPLAYENTRY * pdisplayentry);       //special call back for up and down

void calibration_display (sint32 ind, TDISPLAYENTRY * pdisplayentry);
sint32 calibration_input (sint32 ind, TDISPLAYENTRY * pdisplayentry);
void calibration_select_cancel (sint32 ind, TDISPLAYENTRY * pdisplayentry);

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/
// *INDENT-OFF*
const uint8 timedlg_outline[13][34] = {
{0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 'E', 'N', 'T', 'E', 'R', ' ', 'A', ' ', 'T', 'I', 'T', 'L', 'E', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, '0', '1', 0x00, '/', 0x00, '0', '1', 0x00, '/', 0x00, '0', '0', 0x00, 0x00, 0x00, 0x00, '0', '0', 0x00, ':', 0x00, '0', '0', 0x00, ':', 0x00, '0', '0', 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0xB3, 0x00, 0x00, 0x00, 'O', 'K', 0x00, 0x00, 0x00, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3, 0x00, 'C', 'A', 'N', 'C', 'E', 'L', 0x00, 0xB3, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9, 0x00, 0x00, 0x00, 0xB3},
{0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9}
};

const TDISPLAYENTRY timedlglist[TIMEDLG_BUTTONS] = {
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 6, 7, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 11, 12, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 16, 17, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 22, 23, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 27, 28, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 32, 33, 6, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 6, 7, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 11, 12, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 16, 17, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 22, 23, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 27, 28, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 32, 33, 10, &timedlg_select_up_down, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 8, 15, 13, &timedlg_select_ok, &timedlg_display, &timedlg_input, "", 0x0},
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 24, 31, 13, &timedlg_select_cancel, &timedlg_display, &timedlg_input, "", 0x0}
};

const uint8 calibration_outline[6][30] = {
{0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF},
{0xB3, 0x00, 'C', 'A', 'L', 'I', 'B', 'R', 'A', 'T', 'I', 'N', 'G', ' ', 'R', 'T', 'C', ' ', 'P', 'L', 'E', 'A', 'S', 'E', ' ', 'W', 'A', 'I', 'T', 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDA, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xBF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3, 0x00, 'C', 'A', 'N', 'C', 'E', 'L', 0x00, 0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xB3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB3},
{0xC0, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xD9}
};

const TDISPLAYENTRY calibrationlist[CALIBRATION_BUTTONS] = {
{(COLOR_CYAN << 4) | COLOR_BLACK, (COLOR_BLACK << 4) | COLOR_YELLOW, 16, 23, 9, &calibration_select_cancel, &calibration_display, &calibration_input, "", 0x0}
};

// *INDENT-ON*
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
TIME Time2Set;
extern boolean rtc_calibration_finished;
/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/
void calibration_display (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    sint32 j;
    for (j = calibrationlist[ind].xmin; j <= calibrationlist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, calibrationlist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, calibrationlist[ind].color_display);
    }
}

sint32 calibration_input (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    __debug ();
    return (0);
}

void calibration_select_cancel (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    uint32 j;
    for (j = calibrationlist[ind].xmin; j <= calibrationlist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, calibrationlist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, calibrationlist[ind].color_select);
    }
    if ((touch_driver.touchmode & MASK_TOUCH_UP) != 0)
    {
        touch_driver.touchmode &= ~MASK_TOUCH_UP;   //clear
        rtc_calibration_finished = TRUE;
    }
}

void timedlg_display (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    sint32 j;
    for (j = timedlglist[ind].xmin; j <= timedlglist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, timedlglist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, timedlglist[ind].color_display);
    }
}

sint32 timedlg_input (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    __debug ();
    return (0);
}

void timedlg_select_ok (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    uint32 j;
    for (j = timedlglist[ind].xmin; j <= timedlglist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, timedlglist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, timedlglist[ind].color_select);
    }
    if ((touch_driver.touchmode & MASK_TOUCH_UP) != 0)
    {
        touch_driver.touchmode &= ~MASK_TOUCH_UP;   //clear
        // we set the time
        if (conio_driver.dialogmode == SETTIMEON) rtc_settime(&Time2Set);
        if (conio_driver.dialogmode == SETALARMTIME)
        {
            rtc_setalarm(&Time2Set, 0, 0x07);
            rtc_alarm_onoff(0, 1);
        }
        rtc_calibration_finished = FALSE;
        conio_driver.dialogmode = DIALOGOFF;
        display_ascii_clrscr(conio_driver.displaymode);
    }
}

void timedlg_select_cancel (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    uint32 j;
    for (j = timedlglist[ind].xmin; j <= timedlglist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, timedlglist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, timedlglist[ind].color_select);
    }
    if ((touch_driver.touchmode & MASK_TOUCH_UP) != 0)
    {
        touch_driver.touchmode &= ~MASK_TOUCH_UP;   //clear
        rtc_calibration_finished = FALSE;
        conio_driver.dialogmode = DIALOGOFF;
        conio_ascii_clrscr(conio_driver.displaymode);
    }
}

void timedlg_select_up_down (sint32 ind, TDISPLAYENTRY * pdisplayentry)
{
    uint32 j;
    for (j = timedlglist[ind].xmin; j <= timedlglist[ind].xmax; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, j, timedlglist[ind].y);
        conio_ascii_textchangecolor (conio_driver.displaymode, timedlglist[ind].color_select);
    }
    if ((touch_driver.touchmode & MASK_TOUCH_UP) != 0)
    {
        switch(ind)
        {
        case 0: Time2Set.date++;
                if ((Time2Set.date % 16) == 10) Time2Set.date += 6;
                // check for february
                if (Time2Set.month == 2)
                {
                    if (Time2Set.year % 4)
                    {
                        if (Time2Set.date > 0x28) Time2Set.date = 0x01;
                    }
                    else
                    {
                        if (Time2Set.date > 0x29) Time2Set.date = 0x01;
                    }
                }
                // check for 30 day months
                if ((Time2Set.month == 4) || (Time2Set.month == 6) || (Time2Set.month == 9) || (Time2Set.month == 11))
                {
                    if (Time2Set.date > 0x30) Time2Set.date = 0x01;
                }
                if (Time2Set.date > 0x31) Time2Set.date = 0x01;
                break;
        case 1: Time2Set.month++;
                if ((Time2Set.month % 16) == 10) Time2Set.month += 6;
                if (Time2Set.month > 0x12) Time2Set.month = 0x01;
                break;
        case 2: Time2Set.year++;
                if ((Time2Set.year % 16) == 10) Time2Set.year += 6;
                if (Time2Set.year > 0x99) Time2Set.year = 0x00;
                break;
        case 3: Time2Set.hours++;
                if ((Time2Set.hours % 16) == 10) Time2Set.hours += 6;
                if (Time2Set.hours > 0x23) Time2Set.hours = 0x00;
                break;
        case 4: Time2Set.minutes++;
                if ((Time2Set.minutes % 16) == 10) Time2Set.minutes += 6;
                if (Time2Set.minutes > 0x59) Time2Set.minutes = 0x00;
                break;
        case 5: Time2Set.seconds++;
                if ((Time2Set.seconds % 16) == 10) Time2Set.seconds += 6;
                if (Time2Set.seconds > 0x59) Time2Set.seconds = 0x00;
                break;
        case 6: // check for february
                if (Time2Set.date == 0x01)
                {
                    if (Time2Set.month == 2)
                    {
                        if (Time2Set.year % 4)
                        {
                            Time2Set.date = 0x28;
                        }
                        else
                        {
                            Time2Set.date = 0x29;
                        }
                    }
                    else
                    {
                        // check for 30 day months
                        if ((Time2Set.month == 4) || (Time2Set.month == 6) || (Time2Set.month == 9) || (Time2Set.month == 11))
                        {
                            Time2Set.date = 0x30;
                        }
                        else Time2Set.date = 0x31;
                    }
                }
                else
                    Time2Set.date--;
                if ((Time2Set.date % 16) == 15) Time2Set.date -= 6;
                break;
        case 7: if (Time2Set.month == 0x01)
                    Time2Set.month = 0x12;
                else
                    Time2Set.month--;
                if ((Time2Set.month % 16) == 15) Time2Set.month -= 6;
                break;
        case 8: if (Time2Set.year == 0)
                    Time2Set.year = 0x99;
                else
                    Time2Set.year--;
                if ((Time2Set.year % 16) == 15) Time2Set.year -= 6;
                break;
        case 9: if (Time2Set.hours == 0)
                    Time2Set.hours = 0x23;
                else
                    Time2Set.hours--;
                if ((Time2Set.hours % 16) == 15) Time2Set.hours -= 6;
                break;
        case 10: if (Time2Set.minutes == 0)
                    Time2Set.minutes = 0x59;
                 else
                    Time2Set.minutes--;
                 if ((Time2Set.minutes % 16) == 15) Time2Set.minutes -= 6;
                 break;
        case 11: if (Time2Set.seconds == 0)
                    Time2Set.seconds = 0x59;
                 else
                    Time2Set.seconds--;
                 if ((Time2Set.seconds % 16) == 15) Time2Set.seconds -= 6;
                 break;
        default: __debug(); // we should never come to here
                 break;
        }
        touch_driver.touchmode &= ~MASK_TOUCH_UP;   //clear
    }
}

void set_time (sint16 x, sint16 y)
{
    sint32 i, j;

    conio_ascii_textcolor (DISPLAYMENU, COLOR_BLACK);
    conio_ascii_textbackground (DISPLAYMENU, COLOR_CYAN);
    // first we make the calibration if needed
    if (rtc_calibration_finished == FALSE)
    {
        for (j = 0; j < 6; j += 1)
        {
            conio_ascii_gotoxy (conio_driver.displaymode, 5, 6+j);
            for (i = 0; i < 30; i += 1)
            {
                conio_ascii_putch (conio_driver.displaymode, calibration_outline[j][i]);
            }
        }
        conio_ascii_gotoxy (conio_driver.displaymode, 5, 0);
        /* for all buttons */
        for (i = 0; i < CALIBRATION_BUTTONS; i += 1)
        {
            if ((x >= calibrationlist[i].xmin) && (x <= calibrationlist[i].xmax) && (y == calibrationlist[i].y))
            {
                calibrationlist[i].select (i, (struct DISPLAYENTRY *) &calibrationlist[i]);
            }
            else
            {
                calibrationlist[i].display (i, (struct DISPLAYENTRY *) &calibrationlist[i]);
            }
        }
        return;
    }

    for (j = 0; j < 13; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, 3, 3+j);
        for (i = 0; i < 34; i += 1)
        {
            conio_ascii_putch (conio_driver.displaymode, timedlg_outline[j][i]);
        }
    }
    // set the title in the middle
    conio_ascii_gotoxy(conio_driver.displaymode, 11, 3+1);
    conio_ascii_cputs(conio_driver.displaymode, (uint8 *)"SET DATE AND TIME");
    conio_ascii_printfxy(conio_driver.displaymode, 6, 3+5, (const uint8 *)"%02x / %02x / %02x    %02x : %02x : %02x", Time2Set.date, Time2Set.month, Time2Set.year, Time2Set.hours, Time2Set.minutes, Time2Set.seconds);
    conio_ascii_gotoxy (conio_driver.displaymode, 3, 0);
    /* for all buttons */
    for (i = 0; i < TIMEDLG_BUTTONS; i += 1)
    {
        if ((x >= timedlglist[i].xmin) && (x <= timedlglist[i].xmax) && (y == timedlglist[i].y))
        {
            timedlglist[i].select (i, (struct DISPLAYENTRY *) &timedlglist[i]);
        }
        else
        {
            timedlglist[i].display (i, (struct DISPLAYENTRY *) &timedlglist[i]);
        }
    }
}

void set_alarmtime (sint16 x, sint16 y)
{
    sint32 i, j;
    conio_ascii_textcolor (DISPLAYMENU, COLOR_BLACK);
    conio_ascii_textbackground (DISPLAYMENU, COLOR_CYAN);

    for (j = 0; j < 13; j += 1)
    {
        conio_ascii_gotoxy (conio_driver.displaymode, 3, 3+j);
        for (i = 0; i < 34; i += 1)
        {
            conio_ascii_putch (conio_driver.displaymode, timedlg_outline[j][i]);
        }
    }
    // set the title in the middle
    conio_ascii_gotoxy(conio_driver.displaymode, 13, 3+1);
    conio_ascii_cputs(conio_driver.displaymode, (uint8 *)"SET ALARM TIME");
    conio_ascii_printfxy(conio_driver.displaymode, 6, 3+5, (const uint8 *)"%02x / %02x / %02x    %02x : %02x : %02x", Time2Set.date, Time2Set.month, Time2Set.year, Time2Set.hours, Time2Set.minutes, Time2Set.seconds);
    conio_ascii_gotoxy (conio_driver.displaymode, 3, 0);
    /* for all buttons */
    for (i = 0; i < TIMEDLG_BUTTONS; i += 1)
    {
        if ((x >= timedlglist[i].xmin) && (x <= timedlglist[i].xmax) && (y == timedlglist[i].y))
        {
            timedlglist[i].select (i, (struct DISPLAYENTRY *) &timedlglist[i]);
        }
        else
        {
            timedlglist[i].display (i, (struct DISPLAYENTRY *) &timedlglist[i]);
        }
    }
}
#endif /* USE_RTC */
