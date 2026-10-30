/**
 * \file TC4D_HAL.c
 * \brief Hardware Abstraction Layer implementation for TC4D
 */

#include <TC4_HAL.h>

/**
 * \brief Initialize the TFT Shield hardware
 * 
 * Call this function once at startup to initialize all necessary
 * peripherals for the TFT shield (GPIO, timing).
 */
void TC4D_TFTShield_Init(void)
{
    /* Initialize timing system (required for delay functions) */
    initTime();
    
    /* Initialize TFT control pins */
    TC4D_initTFTControlPins();
    
    /* Set data bus to output mode */
    TC4D_setWriteDir();
}
