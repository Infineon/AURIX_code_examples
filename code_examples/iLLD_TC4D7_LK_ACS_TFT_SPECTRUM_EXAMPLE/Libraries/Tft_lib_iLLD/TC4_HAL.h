/**
 * \file TC4D_HAL.h
 * \brief Hardware Abstraction Layer for TC4D - Arduino compatibility layer
 * 
 * This file provides Arduino-compatible functions and macros for the TC4D platform
 * to allow easy porting of Arduino libraries.
 */

#ifndef TC4D_HAL_H
#define TC4D_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------Includes----------------------------------*/
#include "Ifx_Types.h"
#include "Port/Std/IfxPort.h"
#include "SysSe/Bsp/Bsp.h"

/*----------------------------------Type Definitions--------------------------*/
/* Arduino-compatible type definitions */
typedef uint8    uint8_t;
typedef uint16   uint16_t;
typedef uint32   uint32_t;
typedef sint8    int8_t;
typedef sint16   int16_t;
typedef sint32   int32_t;

typedef boolean  bool;
#ifndef true
#define true     TRUE
#endif
#ifndef false
#define false    FALSE
#endif

/*----------------------------------Pin Mode Definitions----------------------*/
#define INPUT           0
#define OUTPUT          1
#define INPUT_PULLUP    2
#define INPUT_PULLDOWN  3

/*----------------------------------Pin State Definitions---------------------*/
#define LOW             0
#define HIGH            1

/*----------------------------------Pin Mapping Structure---------------------*/
/**
 * \brief Structure to map Arduino-style pin numbers to TC4D port/pin
 */
typedef struct {
    Ifx_P  *port;       /**< Pointer to port module */
    uint8   pinIndex;   /**< Pin index within the port (0-15) */
} TC4D_PinMapping;

/*----------------------------------Pin Mapping Configuration-----------------*/
/**
 * \brief Configure your pin mapping here according to your hardware setup
 * 
 * Example mapping for TFT shield interface:
 * - Data pins D0-D7 for 8-bit parallel interface
 * - Control pins: CS, CD/RS, WR, RD, RST
 * - Touch screen pins: XP, YP, XM, YM
 * 
 * Adjust these mappings according to your actual hardware connections!
 */

/* TFT LCD Data Bus Pins (D0-D7) */
#define TFT_D0_PORT     (&MODULE_P02)
#define TFT_D0_PIN      6
#define TFT_D1_PORT     (&MODULE_P02)
#define TFT_D1_PIN      7
#define TFT_D2_PORT     (&MODULE_P02)
#define TFT_D2_PIN      0
#define TFT_D3_PORT     (&MODULE_P02)
#define TFT_D3_PIN      1
#define TFT_D4_PORT     (&MODULE_P03)
#define TFT_D4_PIN      3
#define TFT_D5_PORT     (&MODULE_P02)
#define TFT_D5_PIN      3
#define TFT_D6_PORT     (&MODULE_P02)
#define TFT_D6_PIN      5
#define TFT_D7_PORT     (&MODULE_P02)
#define TFT_D7_PIN      4

/* TFT LCD Control Pins */
#define TFT_CS_PORT     (&MODULE_P00)
#define TFT_CS_PIN      3
#define TFT_CD_PORT     (&MODULE_P00)   /* Also called RS (Register Select) */
#define TFT_CD_PIN      4
#define TFT_WR_PORT     (&MODULE_P00)
#define TFT_WR_PIN      5
#define TFT_RD_PORT     (&MODULE_P00)
#define TFT_RD_PIN      6
#define TFT_RST_PORT    (&MODULE_P00)
#define TFT_RST_PIN     2

/* Touch Screen Pins - SHARED with LCD pins on TFT Shield!
 * 
 * On the TFT Shield, touch pins share physical connections:
 *   YP = LCD_WR (A1 on Arduino) - needs analog input capability
 *   XM = LCD_CD (A2 on Arduino) - needs analog input capability  
 *   YM = LCD_D7 (D7 on Arduino) - digital only
 *   XP = LCD_D6 (D6 on Arduino) - digital only
 * 
 * Map these to the SAME pins as your LCD control/data pins!
 */
#define TS_XP_PORT      TFT_D6_PORT     /* X+ = LCD D6 */
#define TS_XP_PIN       TFT_D6_PIN
#define TS_YP_PORT      TFT_WR_PORT     /* Y+ = LCD WR (needs ADC!) */
#define TS_YP_PIN       TFT_WR_PIN
#define TS_XM_PORT      TFT_CD_PORT     /* X- = LCD CD/RS (needs ADC!) */
#define TS_XM_PIN       TFT_CD_PIN
#define TS_YM_PORT      TFT_D7_PORT     /* Y- = LCD D7 */
#define TS_YM_PIN       TFT_D7_PIN

/*----------------------------------Control Pin Macros------------------------*/
/* Fast pin control macros for TFT LCD */
#define CS_ACTIVE           IfxPort_setPinLow(TFT_CS_PORT, TFT_CS_PIN)
#define CS_IDLE             IfxPort_setPinHigh(TFT_CS_PORT, TFT_CS_PIN)
#define CD_COMMAND          IfxPort_setPinLow(TFT_CD_PORT, TFT_CD_PIN)
#define CD_DATA             IfxPort_setPinHigh(TFT_CD_PORT, TFT_CD_PIN)
#define WR_ACTIVE           IfxPort_setPinLow(TFT_WR_PORT, TFT_WR_PIN)
#define WR_IDLE             IfxPort_setPinHigh(TFT_WR_PORT, TFT_WR_PIN)
#define RD_ACTIVE           IfxPort_setPinLow(TFT_RD_PORT, TFT_RD_PIN)
#define RD_IDLE             IfxPort_setPinHigh(TFT_RD_PORT, TFT_RD_PIN)

/* WR_STROBE with adequate timing for high-speed TC4D 
 * The display typically needs ~50ns setup time and ~100ns WR pulse width.
 * At TC4D speeds, we need explicit delays to ensure proper timing.
 */
#define WR_STROBE           { __nop(); __nop(); WR_ACTIVE; __nop(); __nop(); __nop(); __nop(); WR_IDLE; __nop(); __nop(); }

#define TC4D_TFT_RESET_LOW()  IfxPort_setPinLow(TFT_RST_PORT, TFT_RST_PIN)
#define TC4D_TFT_RESET_HIGH() IfxPort_setPinHigh(TFT_RST_PORT, TFT_RST_PIN)

/*----------------------------------Delay Functions---------------------------*/
/**
 * \brief Delay for a specified number of milliseconds
 * \param ms Number of milliseconds to delay
 */
IFX_INLINE void delay(uint32 ms)
{
    waitTime(IfxStm_getTicksFromMilliseconds(ms));
}

/**
 * \brief Delay for a specified number of microseconds
 * \param us Number of microseconds to delay
 */
IFX_INLINE void delayMicroseconds(uint32 us)
{
    waitTime(IfxStm_getTicksFromMicroseconds(us));
}

/**
 * \brief Get current time in milliseconds since system start
 * \return Current time in milliseconds
 */
IFX_INLINE uint32 millis(void)
{
    return (uint32)(now() / TimeConst_1ms);
}

/**
 * \brief Get current time in microseconds since system start
 * \return Current time in microseconds
 */
IFX_INLINE uint32 micros(void)
{
    return (uint32)(now() / TimeConst_1us);
}

/*----------------------------------GPIO Functions----------------------------*/
/**
 * \brief Configure a TC4D port pin as input or output
 * \param port Pointer to the port module
 * \param pinIndex Pin index (0-15)
 * \param mode INPUT, OUTPUT, INPUT_PULLUP, or INPUT_PULLDOWN
 */
IFX_INLINE void TC4D_pinMode(Ifx_P *port, uint8 pinIndex, uint8 mode)
{
    if (mode == OUTPUT)
    {
        IfxPort_setPinModeOutput(port, pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    }
    else if (mode == INPUT_PULLUP)
    {
        IfxPort_setPinModeInput(port, pinIndex, IfxPort_InputMode_pullUp);
    }
    else if (mode == INPUT_PULLDOWN)
    {
        IfxPort_setPinModeInput(port, pinIndex, IfxPort_InputMode_pullDown);
    }
    else /* INPUT */
    {
        IfxPort_setPinModeInput(port, pinIndex, IfxPort_InputMode_noPullDevice);
    }
}

/**
 * \brief Write a digital value to a TC4D port pin
 * \param port Pointer to the port module
 * \param pinIndex Pin index (0-15)
 * \param value LOW (0) or HIGH (1)
 */
IFX_INLINE void TC4D_digitalWrite(Ifx_P *port, uint8 pinIndex, uint8 value)
{
    if (value)
    {
        IfxPort_setPinHigh(port, pinIndex);
    }
    else
    {
        IfxPort_setPinLow(port, pinIndex);
    }
}

/**
 * \brief Read a digital value from a TC4D port pin
 * \param port Pointer to the port module
 * \param pinIndex Pin index (0-15)
 * \return LOW (0) or HIGH (1)
 */
IFX_INLINE uint8 TC4D_digitalRead(Ifx_P *port, uint8 pinIndex)
{
    return IfxPort_getPinState(port, pinIndex) ? HIGH : LOW;
}

/*----------------------------------8-bit Data Bus Functions------------------*/
/**
 * \brief Write 8-bit data to the TFT data bus
 * \param data 8-bit data value to write
 * 
 * IMPORTANT: Data pins are mapped as follows (adjust for your hardware):
 *   D0=P02.6, D1=P02.7, D2=P02.0, D3=P02.1, D4=P03.3, D5=P02.3, D6=P02.5, D7=P02.4
 * This function writes each bit individually to handle non-contiguous pin mapping.
 */
IFX_INLINE void TC4D_write8(uint8 data)
{
    /* Write each data bit to its corresponding pin */
    /* D0 (bit 0) -> P02.6 */
    if (data & 0x01) { IfxPort_setPinHigh(TFT_D0_PORT, TFT_D0_PIN); }
    else             { IfxPort_setPinLow(TFT_D0_PORT, TFT_D0_PIN); }
    
    /* D1 (bit 1) -> P02.7 */
    if (data & 0x02) { IfxPort_setPinHigh(TFT_D1_PORT, TFT_D1_PIN); }
    else             { IfxPort_setPinLow(TFT_D1_PORT, TFT_D1_PIN); }
    
    /* D2 (bit 2) -> P02.0 */
    if (data & 0x04) { IfxPort_setPinHigh(TFT_D2_PORT, TFT_D2_PIN); }
    else             { IfxPort_setPinLow(TFT_D2_PORT, TFT_D2_PIN); }
    
    /* D3 (bit 3) -> P02.1 */
    if (data & 0x08) { IfxPort_setPinHigh(TFT_D3_PORT, TFT_D3_PIN); }
    else             { IfxPort_setPinLow(TFT_D3_PORT, TFT_D3_PIN); }
    
    /* D4 (bit 4) -> P03.3 (different port!) */
    if (data & 0x10) { IfxPort_setPinHigh(TFT_D4_PORT, TFT_D4_PIN); }
    else             { IfxPort_setPinLow(TFT_D4_PORT, TFT_D4_PIN); }
    
    /* D5 (bit 5) -> P02.3 */
    if (data & 0x20) { IfxPort_setPinHigh(TFT_D5_PORT, TFT_D5_PIN); }
    else             { IfxPort_setPinLow(TFT_D5_PORT, TFT_D5_PIN); }
    
    /* D6 (bit 6) -> P02.5 */
    if (data & 0x40) { IfxPort_setPinHigh(TFT_D6_PORT, TFT_D6_PIN); }
    else             { IfxPort_setPinLow(TFT_D6_PORT, TFT_D6_PIN); }
    
    /* D7 (bit 7) -> P02.4 */
    if (data & 0x80) { IfxPort_setPinHigh(TFT_D7_PORT, TFT_D7_PIN); }
    else             { IfxPort_setPinLow(TFT_D7_PORT, TFT_D7_PIN); }
    
    WR_STROBE;
}

/**
 * \brief Read 8-bit data from the TFT data bus
 * \return 8-bit data value read
 * 
 * IMPORTANT: Data pins are mapped as follows (adjust for your hardware):
 *   D0=P02.6, D1=P02.7, D2=P02.0, D3=P02.1, D4=P03.3, D5=P02.3, D6=P02.5, D7=P02.4
 * This function reads each bit individually to handle non-contiguous pin mapping.
 */
IFX_INLINE uint8 TC4D_read8(void)
{
    uint8 result = 0;
    
    RD_ACTIVE;
    
    /* Small delay for data to stabilize */
    __nop(); __nop(); __nop(); __nop();
    __nop(); __nop(); __nop(); __nop();
    
    /* Read each pin and assemble the byte */
    /* D0 (bit 0) <- P02.6 */
    if (IfxPort_getPinState(TFT_D0_PORT, TFT_D0_PIN)) { result |= 0x01; }
    
    /* D1 (bit 1) <- P02.7 */
    if (IfxPort_getPinState(TFT_D1_PORT, TFT_D1_PIN)) { result |= 0x02; }
    
    /* D2 (bit 2) <- P02.0 */
    if (IfxPort_getPinState(TFT_D2_PORT, TFT_D2_PIN)) { result |= 0x04; }
    
    /* D3 (bit 3) <- P02.1 */
    if (IfxPort_getPinState(TFT_D3_PORT, TFT_D3_PIN)) { result |= 0x08; }
    
    /* D4 (bit 4) <- P03.3 (different port!) */
    if (IfxPort_getPinState(TFT_D4_PORT, TFT_D4_PIN)) { result |= 0x10; }
    
    /* D5 (bit 5) <- P02.3 */
    if (IfxPort_getPinState(TFT_D5_PORT, TFT_D5_PIN)) { result |= 0x20; }
    
    /* D6 (bit 6) <- P02.5 */
    if (IfxPort_getPinState(TFT_D6_PORT, TFT_D6_PIN)) { result |= 0x40; }
    
    /* D7 (bit 7) <- P02.4 */
    if (IfxPort_getPinState(TFT_D7_PORT, TFT_D7_PIN)) { result |= 0x80; }
    
    RD_IDLE;
    
    return result;
}

/**
 * \brief Set TFT data bus pins as outputs
 */
IFX_INLINE void TC4D_setWriteDir(void)
{
    TC4D_pinMode(TFT_D0_PORT, TFT_D0_PIN, OUTPUT);
    TC4D_pinMode(TFT_D1_PORT, TFT_D1_PIN, OUTPUT);
    TC4D_pinMode(TFT_D2_PORT, TFT_D2_PIN, OUTPUT);
    TC4D_pinMode(TFT_D3_PORT, TFT_D3_PIN, OUTPUT);
    TC4D_pinMode(TFT_D4_PORT, TFT_D4_PIN, OUTPUT);
    TC4D_pinMode(TFT_D5_PORT, TFT_D5_PIN, OUTPUT);
    TC4D_pinMode(TFT_D6_PORT, TFT_D6_PIN, OUTPUT);
    TC4D_pinMode(TFT_D7_PORT, TFT_D7_PIN, OUTPUT);
}

/**
 * \brief Set TFT data bus pins as inputs
 */
IFX_INLINE void TC4D_setReadDir(void)
{
    TC4D_pinMode(TFT_D0_PORT, TFT_D0_PIN, INPUT);
    TC4D_pinMode(TFT_D1_PORT, TFT_D1_PIN, INPUT);
    TC4D_pinMode(TFT_D2_PORT, TFT_D2_PIN, INPUT);
    TC4D_pinMode(TFT_D3_PORT, TFT_D3_PIN, INPUT);
    TC4D_pinMode(TFT_D4_PORT, TFT_D4_PIN, INPUT);
    TC4D_pinMode(TFT_D5_PORT, TFT_D5_PIN, INPUT);
    TC4D_pinMode(TFT_D6_PORT, TFT_D6_PIN, INPUT);
    TC4D_pinMode(TFT_D7_PORT, TFT_D7_PIN, INPUT);
}

/*----------------------------------TFT Control Pin Init----------------------*/
/**
 * \brief Initialize TFT LCD control pins
 */
IFX_INLINE void TC4D_initTFTControlPins(void)
{
    /* Configure control pins as outputs */
    TC4D_pinMode(TFT_CS_PORT, TFT_CS_PIN, OUTPUT);
    TC4D_pinMode(TFT_CD_PORT, TFT_CD_PIN, OUTPUT);
    TC4D_pinMode(TFT_WR_PORT, TFT_WR_PIN, OUTPUT);
    TC4D_pinMode(TFT_RD_PORT, TFT_RD_PIN, OUTPUT);
    TC4D_pinMode(TFT_RST_PORT, TFT_RST_PIN, OUTPUT);
    
    /* Set initial states (all idle/high) */
    CS_IDLE;
    CD_DATA;
    WR_IDLE;
    RD_IDLE;
    TC4D_digitalWrite(TFT_RST_PORT, TFT_RST_PIN, HIGH);
}


/*----------------------------------Utility Macros----------------------------*/

/* Min/Max macros */
#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif

/* Constrain macro */
#ifndef constrain
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))
#endif

/* Map function */
IFX_INLINE sint32 map(sint32 x, sint32 in_min, sint32 in_max, sint32 out_min, sint32 out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* Program memory access (no separate flash on TC4D, just return pointer) */
#define pgm_read_byte(addr)  (*(const uint8_t *)(addr))
#define pgm_read_word(addr)  (*(const uint16_t *)(addr))
#define pgm_read_dword(addr) (*(const uint32_t *)(addr))
#define PROGMEM              /* No special attribute needed */

#ifdef __cplusplus
}
#endif

#endif /* TC4D_HAL_H */
