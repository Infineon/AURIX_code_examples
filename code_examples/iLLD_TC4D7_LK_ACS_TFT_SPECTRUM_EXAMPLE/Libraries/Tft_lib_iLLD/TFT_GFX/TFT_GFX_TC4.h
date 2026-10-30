/**
 * \file TFT_GFX_TC4.h
 * \brief Graphics library for TC4D - Pure C version
 * 
 * This is the core graphics library providing common graphics primitives
 * (points, lines, circles, etc.). Adapted for TC4D platform.
 * 
 * Based on Adafruit GFX library. MIT license.
 * TC4D adaptation.
 */

#ifndef _TFT_GFX_TC4_H_
#define _TFT_GFX_TC4_H_

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------Includes----------------------------------*/
#include <Tft_lib_iLLD/TC4_HAL.h>
#include <stddef.h>
#include <string.h>

/*----------------------------------Macros------------------------------------*/
#define GFX_SWAP(a, b) { int16_t t = (a); (a) = (b); (b) = t; }

/*----------------------------------Structures--------------------------------*/

/**
 * \brief Graphics context structure
 */
typedef struct TFT_GFX {
    /* Display dimensions */
    int16_t WIDTH;          /**< Raw display width - never changes */
    int16_t HEIGHT;         /**< Raw display height - never changes */
    int16_t _width;         /**< Display width as modified by rotation */
    int16_t _height;        /**< Display height as modified by rotation */
    
    /* Cursor position */
    int16_t cursor_x;
    int16_t cursor_y;
    
    /* Text settings */
    uint16_t textcolor;
    uint16_t textbgcolor;
    uint8_t textsize;
    uint8_t rotation;
    boolean wrap;           /**< If set, wrap text at right edge */
    boolean _cp437;         /**< If set, use correct CP437 charset */
    
    /* Function pointer for drawPixel - must be set by derived display driver */
    void (*drawPixel)(struct TFT_GFX *gfx, int16_t x, int16_t y, uint16_t color);
    
    /* Optional function pointers for optimized drawing */
    void (*drawFastVLine_opt)(struct TFT_GFX *gfx, int16_t x, int16_t y, int16_t h, uint16_t color);
    void (*drawFastHLine_opt)(struct TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, uint16_t color);
    void (*fillRect_opt)(struct TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void (*fillScreen_opt)(struct TFT_GFX *gfx, uint16_t color);
    
} TFT_GFX;

/**
 * \brief Button structure
 */
typedef struct {
    TFT_GFX *_gfx;
    int16_t _x, _y;
    uint16_t _w, _h;
    uint8_t _textsize;
    uint16_t _outlinecolor, _fillcolor, _textcolor;
    char _label[10];
    boolean currstate, laststate;
} TFT_GFX_Button;

/*----------------------------------Function Prototypes-----------------------*/

/* Initialization */
void GFX_init(TFT_GFX *gfx, int16_t w, int16_t h);

/* Basic drawing - these use the drawPixel function pointer */
void GFX_drawLine(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void GFX_drawFastVLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t h, uint16_t color);
void GFX_drawFastHLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, uint16_t color);
void GFX_drawRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void GFX_fillRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void GFX_fillScreen(TFT_GFX *gfx, uint16_t color);

/* Circle drawing */
void GFX_drawCircle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint16_t color);
void GFX_drawCircleHelper(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void GFX_fillCircle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint16_t color);
void GFX_fillCircleHelper(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);

/* Triangle drawing */
void GFX_drawTriangle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void GFX_fillTriangle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);

/* Rounded rectangle drawing */
void GFX_drawRoundRect(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
void GFX_fillRoundRect(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);

/* Bitmap drawing */
void GFX_drawBitmap(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
void GFX_drawBitmapBg(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);
void GFX_drawXBitmap(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);

/* Text/character drawing */
void GFX_drawChar(TFT_GFX *gfx, int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
void GFX_setCursor(TFT_GFX *gfx, int16_t x, int16_t y);
void GFX_setTextColor(TFT_GFX *gfx, uint16_t c);
void GFX_setTextColorBg(TFT_GFX *gfx, uint16_t c, uint16_t bg);
void GFX_setTextSize(TFT_GFX *gfx, uint8_t s);
void GFX_setTextWrap(TFT_GFX *gfx, boolean w);
void GFX_cp437(TFT_GFX *gfx, boolean x);

/* Print functions */
size_t GFX_write(TFT_GFX *gfx, uint8_t c);
size_t GFX_writeBuffer(TFT_GFX *gfx, const uint8_t *buffer, size_t size);
size_t GFX_print(TFT_GFX *gfx, const char *str);
size_t GFX_printChar(TFT_GFX *gfx, char c);
size_t GFX_printInt(TFT_GFX *gfx, int n);
size_t GFX_printUInt(TFT_GFX *gfx, unsigned int n);
size_t GFX_printLong(TFT_GFX *gfx, long n);
size_t GFX_printULong(TFT_GFX *gfx, unsigned long n);
size_t GFX_println(TFT_GFX *gfx);
size_t GFX_printlnStr(TFT_GFX *gfx, const char *str);
size_t GFX_printlnChar(TFT_GFX *gfx, char c);
size_t GFX_printlnInt(TFT_GFX *gfx, int n);
size_t GFX_printlnUInt(TFT_GFX *gfx, unsigned int n);
size_t GFX_printlnLong(TFT_GFX *gfx, long n);
size_t GFX_printlnULong(TFT_GFX *gfx, unsigned long n);

/* Display properties */
void GFX_setRotation(TFT_GFX *gfx, uint8_t r);
uint8_t GFX_getRotation(TFT_GFX *gfx);
int16_t GFX_width(TFT_GFX *gfx);
int16_t GFX_height(TFT_GFX *gfx);
int16_t GFX_getCursorX(TFT_GFX *gfx);
int16_t GFX_getCursorY(TFT_GFX *gfx);
void GFX_invertDisplay(TFT_GFX *gfx, boolean i);

/* Button functions */
void GFX_Button_init(TFT_GFX_Button *btn);
void GFX_Button_initButton(TFT_GFX_Button *btn, TFT_GFX *gfx, int16_t x, int16_t y,
                           uint8_t w, uint8_t h, uint16_t outline, uint16_t fill,
                           uint16_t textcolor, char *label, uint8_t textsize);
void GFX_Button_drawButton(TFT_GFX_Button *btn, boolean inverted);
boolean GFX_Button_contains(TFT_GFX_Button *btn, int16_t x, int16_t y);
void GFX_Button_press(TFT_GFX_Button *btn, boolean p);
boolean GFX_Button_isPressed(TFT_GFX_Button *btn);
boolean GFX_Button_justPressed(TFT_GFX_Button *btn);
boolean GFX_Button_justReleased(TFT_GFX_Button *btn);

#ifdef __cplusplus
}
#endif

#endif /* _TFT_GFX_TC4D_H_ */
