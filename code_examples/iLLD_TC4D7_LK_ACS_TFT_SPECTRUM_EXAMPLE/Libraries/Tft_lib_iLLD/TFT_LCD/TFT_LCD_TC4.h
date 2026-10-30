/**
 * \file TFT_LCD_TC4.h
 * \brief TFT LCD driver for TC4D - Pure C version
 * 
 * Graphics library for TFT LCD displays. Adapted from TFT_LCD for TC4D platform.
 * Supports: ILI9325, ILI9328, ILI9341, HX8347G, HX8357D, LGDP4535
 * 
 * Based on Adafruit TFTLCD library. MIT license.
 * TC4D adaptation.
 */

#ifndef _TFT_LCD_TC4_H_
#define _TFT_LCD_TC4_H_

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------Includes----------------------------------*/
#include <Tft_lib_iLLD/TC4_HAL.h>
#include <Tft_lib_iLLD/TFT_GFX/TFT_GFX_TC4.h>

/*----------------------------------Macros------------------------------------*/
#define TFTLCD_WIDTH   240
#define TFTLCD_HEIGHT  320

/* LCD controller chip identifiers */
#define TFTLCD_ID_932X    0
#define TFTLCD_ID_7575    1
#define TFTLCD_ID_9341    2
#define TFTLCD_ID_HX8357D 3
#define TFTLCD_ID_4535    4
#define TFTLCD_ID_UNKNOWN 0xFF

/* Color conversion macro */
#define TFTLCD_Color565(r, g, b) (((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | ((b) >> 3)

/*----------------------------------Structures--------------------------------*/

/**
 * \brief TFT LCD context structure (replaces TFT_LCD class)
 */
typedef struct {
    TFT_GFX gfx;         /**< Embedded GFX context (base graphics) */
    uint8_t driver;         /**< LCD controller type */
} TFT_LCD;

/*----------------------------------Function Prototypes-----------------------*/

/* Initialization */
void TFTLCD_init(TFT_LCD *lcd);
void TFTLCD_begin(TFT_LCD *lcd, uint16_t id);
void TFTLCD_reset(TFT_LCD *lcd);

/* Drawing - these override/extend base GFX functions */
void TFTLCD_drawPixel(TFT_GFX *gfx, int16_t x, int16_t y, uint16_t color);
void TFTLCD_drawFastHLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, uint16_t color);
void TFTLCD_drawFastVLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t h, uint16_t color);
void TFTLCD_fillRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void TFTLCD_fillScreen(TFT_GFX *gfx, uint16_t color);

/* LCD-specific functions */
void TFTLCD_setAddrWindow(TFT_LCD *lcd, int x1, int y1, int x2, int y2);
void TFTLCD_pushColors(TFT_LCD *lcd, uint16_t *data, uint8_t len, boolean first);
void TFTLCD_setRotation(TFT_LCD *lcd, uint8_t x);
void TFTLCD_setRegisters8(TFT_LCD *lcd, uint8_t *ptr, uint8_t n);
void TFTLCD_setRegisters16(TFT_LCD *lcd, uint16_t *ptr, uint8_t n);

/* Read functions */
uint16_t TFTLCD_readPixel(TFT_LCD *lcd, int16_t x, int16_t y);
uint16_t TFTLCD_readID(TFT_LCD *lcd);
uint32_t TFTLCD_readReg(TFT_LCD *lcd, uint8_t r);

/* Color conversion */
uint16_t TFTLCD_color565(uint8_t r, uint8_t g, uint8_t b);

/* Wrapper functions for convenience - use lcd->gfx as base */
#define TFTLCD_width(lcd)       GFX_width(&(lcd)->gfx)
#define TFTLCD_height(lcd)      GFX_height(&(lcd)->gfx)
#define TFTLCD_setCursor(lcd, x, y)         GFX_setCursor(&(lcd)->gfx, x, y)
#define TFTLCD_setTextColor(lcd, c)         GFX_setTextColor(&(lcd)->gfx, c)
#define TFTLCD_setTextColorBg(lcd, c, bg)   GFX_setTextColorBg(&(lcd)->gfx, c, bg)
#define TFTLCD_setTextSize(lcd, s)          GFX_setTextSize(&(lcd)->gfx, s)
#define TFTLCD_print(lcd, str)              GFX_print(&(lcd)->gfx, str)
#define TFTLCD_println(lcd)                 GFX_println(&(lcd)->gfx)
#define TFTLCD_printlnStr(lcd, str)         GFX_printlnStr(&(lcd)->gfx, str)
#define TFTLCD_drawLine(lcd, x0, y0, x1, y1, c) GFX_drawLine(&(lcd)->gfx, x0, y0, x1, y1, c)
#define TFTLCD_drawRect(lcd, x, y, w, h, c)     GFX_drawRect(&(lcd)->gfx, x, y, w, h, c)
#define TFTLCD_drawCircle(lcd, x, y, r, c)      GFX_drawCircle(&(lcd)->gfx, x, y, r, c)
#define TFTLCD_fillCircle(lcd, x, y, r, c)      GFX_fillCircle(&(lcd)->gfx, x, y, r, c)
#define TFTLCD_drawTriangle(lcd, x0, y0, x1, y1, x2, y2, c) GFX_drawTriangle(&(lcd)->gfx, x0, y0, x1, y1, x2, y2, c)
#define TFTLCD_fillTriangle(lcd, x0, y0, x1, y1, x2, y2, c) GFX_fillTriangle(&(lcd)->gfx, x0, y0, x1, y1, x2, y2, c)
#define TFTLCD_drawRoundRect(lcd, x, y, w, h, r, c)  GFX_drawRoundRect(&(lcd)->gfx, x, y, w, h, r, c)
#define TFTLCD_fillRoundRect(lcd, x, y, w, h, r, c)  GFX_fillRoundRect(&(lcd)->gfx, x, y, w, h, r, c)

#ifdef __cplusplus
}
#endif

#endif /* _TFT_LCD_TC4_H_ */
