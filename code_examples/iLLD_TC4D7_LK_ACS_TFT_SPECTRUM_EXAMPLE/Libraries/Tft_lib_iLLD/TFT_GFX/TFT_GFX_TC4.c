/**
 * \file TFT_GFX_TC4.c
 * \brief Graphics library for TC4D - Pure C implementation
 * 
 * This is the core graphics library providing common graphics primitives
 * (points, lines, circles, etc.). Adapted from TFT_GFX for TC4D platform.
 * 
 * Based on Adafruit GFX library. MIT license.
 * TC4D adaptation - MIT license
 */

#include <stdio.h>
#include <stdlib.h>
#include <Tft_lib_iLLD/TFT_GFX/TFT_GFX_TC4.h>
#include <Tft_lib_iLLD/TFT_GFX/glcdfont.c>

void GFX_init(TFT_GFX *gfx, int16_t w, int16_t h)
{
    gfx->WIDTH = w;
    gfx->HEIGHT = h;
    gfx->_width = w;
    gfx->_height = h;
    gfx->rotation = 0;
    gfx->cursor_x = 0;
    gfx->cursor_y = 0;
    gfx->textsize = 1;
    gfx->textcolor = 0xFFFF;
    gfx->textbgcolor = 0xFFFF;
    gfx->wrap = TRUE;
    gfx->_cp437 = FALSE;
    
    /* Function pointers - must be set by display driver */
    gfx->drawPixel = NULL;
    gfx->drawFastVLine_opt = NULL;
    gfx->drawFastHLine_opt = NULL;
    gfx->fillRect_opt = NULL;
    gfx->fillScreen_opt = NULL;
}

/*----------------------------------Line Drawing------------------------------*/

void GFX_drawLine(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    int16_t dx, dy, err, ystep;
    
    if (steep) {
        GFX_SWAP(x0, y0);
        GFX_SWAP(x1, y1);
    }
    
    if (x0 > x1) {
        GFX_SWAP(x0, x1);
        GFX_SWAP(y0, y1);
    }
    
    dx = x1 - x0;
    dy = abs(y1 - y0);
    err = dx / 2;
    
    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }
    
    for (; x0 <= x1; x0++) {
        if (steep) {
            gfx->drawPixel(gfx, y0, x0, color);
        } else {
            gfx->drawPixel(gfx, x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

void GFX_drawFastVLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t h, uint16_t color)
{
    if (gfx->drawFastVLine_opt) {
        gfx->drawFastVLine_opt(gfx, x, y, h, color);
    } else {
        GFX_drawLine(gfx, x, y, x, y + h - 1, color);
    }
}

void GFX_drawFastHLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, uint16_t color)
{
    if (gfx->drawFastHLine_opt) {
        gfx->drawFastHLine_opt(gfx, x, y, w, color);
    } else {
        GFX_drawLine(gfx, x, y, x + w - 1, y, color);
    }
}

/*----------------------------------Rectangle Drawing-------------------------*/

void GFX_drawRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    GFX_drawFastHLine(gfx, x, y, w, color);
    GFX_drawFastHLine(gfx, x, y + h - 1, w, color);
    GFX_drawFastVLine(gfx, x, y, h, color);
    GFX_drawFastVLine(gfx, x + w - 1, y, h, color);
}

void GFX_fillRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    int16_t i;
    
    if (gfx->fillRect_opt) {
        gfx->fillRect_opt(gfx, x, y, w, h, color);
    } else {
        for (i = x; i < x + w; i++) {
            GFX_drawFastVLine(gfx, i, y, h, color);
        }
    }
}

void GFX_fillScreen(TFT_GFX *gfx, uint16_t color)
{
    if (gfx->fillScreen_opt) {
        gfx->fillScreen_opt(gfx, color);
    } else {
        GFX_fillRect(gfx, 0, 0, gfx->_width, gfx->_height, color);
    }
}

/*----------------------------------Circle Drawing----------------------------*/

void GFX_drawCircle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    
    gfx->drawPixel(gfx, x0, y0 + r, color);
    gfx->drawPixel(gfx, x0, y0 - r, color);
    gfx->drawPixel(gfx, x0 + r, y0, color);
    gfx->drawPixel(gfx, x0 - r, y0, color);
    
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        
        gfx->drawPixel(gfx, x0 + x, y0 + y, color);
        gfx->drawPixel(gfx, x0 - x, y0 + y, color);
        gfx->drawPixel(gfx, x0 + x, y0 - y, color);
        gfx->drawPixel(gfx, x0 - x, y0 - y, color);
        gfx->drawPixel(gfx, x0 + y, y0 + x, color);
        gfx->drawPixel(gfx, x0 - y, y0 + x, color);
        gfx->drawPixel(gfx, x0 + y, y0 - x, color);
        gfx->drawPixel(gfx, x0 - y, y0 - x, color);
    }
}

void GFX_drawCircleHelper(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        
        if (cornername & 0x4) {
            gfx->drawPixel(gfx, x0 + x, y0 + y, color);
            gfx->drawPixel(gfx, x0 + y, y0 + x, color);
        }
        if (cornername & 0x2) {
            gfx->drawPixel(gfx, x0 + x, y0 - y, color);
            gfx->drawPixel(gfx, x0 + y, y0 - x, color);
        }
        if (cornername & 0x8) {
            gfx->drawPixel(gfx, x0 - y, y0 + x, color);
            gfx->drawPixel(gfx, x0 - x, y0 + y, color);
        }
        if (cornername & 0x1) {
            gfx->drawPixel(gfx, x0 - y, y0 - x, color);
            gfx->drawPixel(gfx, x0 - x, y0 - y, color);
        }
    }
}

void GFX_fillCircle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
    GFX_drawFastVLine(gfx, x0, y0 - r, 2 * r + 1, color);
    GFX_fillCircleHelper(gfx, x0, y0, r, 3, 0, color);
}

void GFX_fillCircleHelper(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    
    while (x < y) {
        if (f >= 0) {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        
        if (cornername & 0x1) {
            GFX_drawFastVLine(gfx, x0 + x, y0 - y, 2 * y + 1 + delta, color);
            GFX_drawFastVLine(gfx, x0 + y, y0 - x, 2 * x + 1 + delta, color);
        }
        if (cornername & 0x2) {
            GFX_drawFastVLine(gfx, x0 - x, y0 - y, 2 * y + 1 + delta, color);
            GFX_drawFastVLine(gfx, x0 - y, y0 - x, 2 * x + 1 + delta, color);
        }
    }
}

/*----------------------------------Triangle Drawing--------------------------*/

void GFX_drawTriangle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    GFX_drawLine(gfx, x0, y0, x1, y1, color);
    GFX_drawLine(gfx, x1, y1, x2, y2, color);
    GFX_drawLine(gfx, x2, y2, x0, y0, color);
}

void GFX_fillTriangle(TFT_GFX *gfx, int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    int16_t a, b, y, last;
    int16_t dx01, dy01, dx02, dy02, dx12, dy12;
    int32_t sa, sb;
    
    /* Sort coordinates by Y order (y2 >= y1 >= y0) */
    if (y0 > y1) {
        GFX_SWAP(y0, y1); GFX_SWAP(x0, x1);
    }
    if (y1 > y2) {
        GFX_SWAP(y2, y1); GFX_SWAP(x2, x1);
    }
    if (y0 > y1) {
        GFX_SWAP(y0, y1); GFX_SWAP(x0, x1);
    }
    
    if (y0 == y2) {
        a = b = x0;
        if (x1 < a) a = x1;
        else if (x1 > b) b = x1;
        if (x2 < a) a = x2;
        else if (x2 > b) b = x2;
        GFX_drawFastHLine(gfx, a, y0, b - a + 1, color);
        return;
    }
    
    dx01 = x1 - x0;
    dy01 = y1 - y0;
    dx02 = x2 - x0;
    dy02 = y2 - y0;
    dx12 = x2 - x1;
    dy12 = y2 - y1;
    sa = 0;
    sb = 0;
    
    if (y1 == y2) last = y1;
    else last = y1 - 1;
    
    for (y = y0; y <= last; y++) {
        a = x0 + sa / dy01;
        b = x0 + sb / dy02;
        sa += dx01;
        sb += dx02;
        if (a > b) GFX_SWAP(a, b);
        GFX_drawFastHLine(gfx, a, y, b - a + 1, color);
    }
    
    sa = dx12 * (y - y1);
    sb = dx02 * (y - y0);
    for (; y <= y2; y++) {
        a = x1 + sa / dy12;
        b = x0 + sb / dy02;
        sa += dx12;
        sb += dx02;
        if (a > b) GFX_SWAP(a, b);
        GFX_drawFastHLine(gfx, a, y, b - a + 1, color);
    }
}

/*----------------------------------Rounded Rectangle Drawing-----------------*/

void GFX_drawRoundRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
    GFX_drawFastHLine(gfx, x + r, y, w - 2 * r, color);
    GFX_drawFastHLine(gfx, x + r, y + h - 1, w - 2 * r, color);
    GFX_drawFastVLine(gfx, x, y + r, h - 2 * r, color);
    GFX_drawFastVLine(gfx, x + w - 1, y + r, h - 2 * r, color);
    
    GFX_drawCircleHelper(gfx, x + r, y + r, r, 1, color);
    GFX_drawCircleHelper(gfx, x + w - r - 1, y + r, r, 2, color);
    GFX_drawCircleHelper(gfx, x + w - r - 1, y + h - r - 1, r, 4, color);
    GFX_drawCircleHelper(gfx, x + r, y + h - r - 1, r, 8, color);
}

void GFX_fillRoundRect(TFT_GFX *gfx, int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color)
{
    GFX_fillRect(gfx, x + r, y, w - 2 * r, h, color);
    GFX_fillCircleHelper(gfx, x + w - r - 1, y + r, r, 1, h - 2 * r - 1, color);
    GFX_fillCircleHelper(gfx, x + r, y + r, r, 2, h - 2 * r - 1, color);
}

/*----------------------------------Bitmap Drawing----------------------------*/

void GFX_drawBitmap(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
{
    int16_t i, j, byteWidth = (w + 7) / 8;
    
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
                gfx->drawPixel(gfx, x + i, y + j, color);
            }
        }
    }
}

void GFX_drawBitmapBg(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg)
{
    int16_t i, j, byteWidth = (w + 7) / 8;
    
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (128 >> (i & 7))) {
                gfx->drawPixel(gfx, x + i, y + j, color);
            } else {
                gfx->drawPixel(gfx, x + i, y + j, bg);
            }
        }
    }
}

void GFX_drawXBitmap(TFT_GFX *gfx, int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
{
    int16_t i, j, byteWidth = (w + 7) / 8;
    
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            if (pgm_read_byte(bitmap + j * byteWidth + i / 8) & (1 << (i % 8))) {
                gfx->drawPixel(gfx, x + i, y + j, color);
            }
        }
    }
}

/*----------------------------------Text/Character Drawing--------------------*/

void GFX_drawChar(TFT_GFX *gfx, int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
    int8_t i, j;
    uint8_t line;
    
    if ((x >= gfx->_width) || (y >= gfx->_height) ||
        ((x + 6 * size - 1) < 0) || ((y + 8 * size - 1) < 0))
        return;
    
    if (!gfx->_cp437 && (c >= 176)) c++;
    
    for (i = 0; i < 6; i++) {
        if (i == 5)
            line = 0x0;
        else
            line = pgm_read_byte(font + (c * 5) + i);
        
        for (j = 0; j < 8; j++) {
            if (line & 0x1) {
                if (size == 1)
                    gfx->drawPixel(gfx, x + i, y + j, color);
                else
                    GFX_fillRect(gfx, x + (i * size), y + (j * size), size, size, color);
            } else if (bg != color) {
                if (size == 1)
                    gfx->drawPixel(gfx, x + i, y + j, bg);
                else
                    GFX_fillRect(gfx, x + i * size, y + j * size, size, size, bg);
            }
            line >>= 1;
        }
    }
}

void GFX_setCursor(TFT_GFX *gfx, int16_t x, int16_t y)
{
    gfx->cursor_x = x;
    gfx->cursor_y = y;
}

void GFX_setTextColor(TFT_GFX *gfx, uint16_t c)
{
    gfx->textcolor = c;
    gfx->textbgcolor = c;
}

void GFX_setTextColorBg(TFT_GFX *gfx, uint16_t c, uint16_t bg)
{
    gfx->textcolor = c;
    gfx->textbgcolor = bg;
}

void GFX_setTextSize(TFT_GFX *gfx, uint8_t s)
{
    gfx->textsize = (s > 0) ? s : 1;
}

void GFX_setTextWrap(TFT_GFX *gfx, boolean w)
{
    gfx->wrap = w;
}

void GFX_cp437(TFT_GFX *gfx, boolean x)
{
    gfx->_cp437 = x;
}

/*----------------------------------Print Functions---------------------------*/

size_t GFX_write(TFT_GFX *gfx, uint8_t c)
{
    if (c == '\n') {
        gfx->cursor_y += gfx->textsize * 8;
        gfx->cursor_x = 0;
    } else if (c == '\r') {
        /* skip */
    } else {
        GFX_drawChar(gfx, gfx->cursor_x, gfx->cursor_y, c, gfx->textcolor, gfx->textbgcolor, gfx->textsize);
        gfx->cursor_x += gfx->textsize * 6;
        if (gfx->wrap && (gfx->cursor_x > (gfx->_width - gfx->textsize * 6))) {
            gfx->cursor_y += gfx->textsize * 8;
            gfx->cursor_x = 0;
        }
    }
    return 1;
}

size_t GFX_writeBuffer(TFT_GFX *gfx, const uint8_t *buffer, size_t size)
{
    size_t n = 0;
    while (size--) {
        n += GFX_write(gfx, *buffer++);
    }
    return n;
}

size_t GFX_print(TFT_GFX *gfx, const char *str)
{
    size_t n = 0;
    while (*str) {
        n += GFX_write(gfx, (uint8_t)*str++);
    }
    return n;
}

size_t GFX_printChar(TFT_GFX *gfx, char c)
{
    return GFX_write(gfx, (uint8_t)c);
}

size_t GFX_printInt(TFT_GFX *gfx, int n)
{
    char buf[12];
    sprintf(buf, "%d", n);
    return GFX_print(gfx, buf);
}

size_t GFX_printUInt(TFT_GFX *gfx, unsigned int n)
{
    char buf[12];
    sprintf(buf, "%u", n);
    return GFX_print(gfx, buf);
}

size_t GFX_printLong(TFT_GFX *gfx, long n)
{
    char buf[12];
    sprintf(buf, "%ld", n);
    return GFX_print(gfx, buf);
}

size_t GFX_printULong(TFT_GFX *gfx, unsigned long n)
{
    char buf[12];
    sprintf(buf, "%lu", n);
    return GFX_print(gfx, buf);
}

size_t GFX_println(TFT_GFX *gfx)
{
    return GFX_write(gfx, '\n');
}

size_t GFX_printlnStr(TFT_GFX *gfx, const char *str)
{
    size_t n = GFX_print(gfx, str);
    n += GFX_println(gfx);
    return n;
}

size_t GFX_printlnChar(TFT_GFX *gfx, char c)
{
    size_t n = GFX_printChar(gfx, c);
    n += GFX_println(gfx);
    return n;
}

size_t GFX_printlnInt(TFT_GFX *gfx, int num)
{
    size_t n = GFX_printInt(gfx, num);
    n += GFX_println(gfx);
    return n;
}

size_t GFX_printlnUInt(TFT_GFX *gfx, unsigned int num)
{
    size_t n = GFX_printUInt(gfx, num);
    n += GFX_println(gfx);
    return n;
}

size_t GFX_printlnLong(TFT_GFX *gfx, long num)
{
    size_t n = GFX_printLong(gfx, num);
    n += GFX_println(gfx);
    return n;
}

size_t GFX_printlnULong(TFT_GFX *gfx, unsigned long num)
{
    size_t n = GFX_printULong(gfx, num);
    n += GFX_println(gfx);
    return n;
}

/*----------------------------------Display Properties------------------------*/

void GFX_setRotation(TFT_GFX *gfx, uint8_t r)
{
    gfx->rotation = (r & 3);
    switch (gfx->rotation) {
        case 0:
        case 2:
            gfx->_width = gfx->WIDTH;
            gfx->_height = gfx->HEIGHT;
            break;
        case 1:
        case 3:
            gfx->_width = gfx->HEIGHT;
            gfx->_height = gfx->WIDTH;
            break;
    }
}

uint8_t GFX_getRotation(TFT_GFX *gfx)
{
    return gfx->rotation;
}

int16_t GFX_width(TFT_GFX *gfx)
{
    return gfx->_width;
}

int16_t GFX_height(TFT_GFX *gfx)
{
    return gfx->_height;
}

int16_t GFX_getCursorX(TFT_GFX *gfx)
{
    return gfx->cursor_x;
}

int16_t GFX_getCursorY(TFT_GFX *gfx)
{
    return gfx->cursor_y;
}

void GFX_invertDisplay(TFT_GFX *gfx, boolean i)
{
    /* Do nothing - must be handled by display driver */
    (void)gfx;
    (void)i;
}

/*----------------------------------Button Functions--------------------------*/

void GFX_Button_init(TFT_GFX_Button *btn)
{
    btn->_gfx = NULL;
}

void GFX_Button_initButton(TFT_GFX_Button *btn, TFT_GFX *gfx, int16_t x, int16_t y,
                           uint8_t w, uint8_t h, uint16_t outline, uint16_t fill,
                           uint16_t textcolor, char *label, uint8_t textsize)
{
    btn->_x = x;
    btn->_y = y;
    btn->_w = w;
    btn->_h = h;
    btn->_outlinecolor = outline;
    btn->_fillcolor = fill;
    btn->_textcolor = textcolor;
    btn->_textsize = textsize;
    btn->_gfx = gfx;
    strncpy(btn->_label, label, 9);
    btn->_label[9] = 0;
}

void GFX_Button_drawButton(TFT_GFX_Button *btn, boolean inverted)
{
    uint16_t fill, outline, text;
    int16_t minDim;
    
    if (!inverted) {
        fill = btn->_fillcolor;
        outline = btn->_outlinecolor;
        text = btn->_textcolor;
    } else {
        fill = btn->_textcolor;
        outline = btn->_outlinecolor;
        text = btn->_fillcolor;
    }
    
    minDim = min(btn->_w, btn->_h);
    
    GFX_fillRoundRect(btn->_gfx, btn->_x - (btn->_w / 2), btn->_y - (btn->_h / 2),
                      btn->_w, btn->_h, minDim / 4, fill);
    GFX_drawRoundRect(btn->_gfx, btn->_x - (btn->_w / 2), btn->_y - (btn->_h / 2),
                      btn->_w, btn->_h, minDim / 4, outline);
    
    GFX_setCursor(btn->_gfx, btn->_x - strlen(btn->_label) * 3 * btn->_textsize,
                  btn->_y - 4 * btn->_textsize);
    GFX_setTextColor(btn->_gfx, text);
    GFX_setTextSize(btn->_gfx, btn->_textsize);
    GFX_print(btn->_gfx, btn->_label);
}

boolean GFX_Button_contains(TFT_GFX_Button *btn, int16_t x, int16_t y)
{
    if ((x < (btn->_x - btn->_w / 2)) || (x > (btn->_x + btn->_w / 2)))
        return FALSE;
    if ((y < (btn->_y - btn->_h / 2)) || (y > (btn->_y + btn->_h / 2)))
        return FALSE;
    return TRUE;
}

void GFX_Button_press(TFT_GFX_Button *btn, boolean p)
{
    btn->laststate = btn->currstate;
    btn->currstate = p;
}

boolean GFX_Button_isPressed(TFT_GFX_Button *btn)
{
    return btn->currstate;
}

boolean GFX_Button_justPressed(TFT_GFX_Button *btn)
{
    return (btn->currstate && !btn->laststate);
}

boolean GFX_Button_justReleased(TFT_GFX_Button *btn)
{
    return (!btn->currstate && btn->laststate);
}
