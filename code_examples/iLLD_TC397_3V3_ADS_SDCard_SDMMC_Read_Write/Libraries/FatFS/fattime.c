
#include "fattime.h"

/*---------------------------------------------------------*/
/* User Provided Timer Function for FatFs module           */
/*---------------------------------------------------------*/
/* This is a real time clock service to be called from     */
/* FatFs module. Any valid time must be returned even if   */
/* the system does not support a real time clock.          */
/* This is not required in read-only configuration.        */

DWORD get_fattime (void)
{
    /*
     * 
     * DWORD res;
     * RTC   rtc;
     * 
     * rtc_gettime( &rtc );
     * 
     * res =  (((DWORD)rtc.year - 1980) << 25)
     * | ((DWORD)rtc.month << 21)
     * | ((DWORD)rtc.mday << 16)
     * | (WORD)(rtc.hour << 11)
     * | (WORD)(rtc.min << 5)
     * | (WORD)(rtc.sec >> 1);
     * 
     * return res;
     */
    return (0);
}
