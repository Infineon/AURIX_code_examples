/**
 * \file TFT_LCD_TC4.c
 * \brief TFT LCD driver for TC4D - Pure C implementation
 * 
 * Graphics library for TFT LCD displays. Adapted from TFT_LCD for TC4D platform.
 * 
 * Based on Adafruit TFTLCD library. MIT license.
 * TC4D adaptation.
 */

#include <Tft_lib_iLLD/TFT_LCD/TFT_LCD_TC4.h>
#include <Tft_lib_iLLD/TFT_LCD/registers.h>
#include <Tft_lib_iLLD/TC4_HAL.h>

/*----------------------------------Local Macros------------------------------*/
#define TFTLCD_DELAY 0xFF

/* Binary literal definitions for C compatibility */
#ifndef B00000001
#define B00000001 0x01
#define B00000010 0x02
#define B00000011 0x03
#define B00001000 0x08
#define B00010000 0x10
#define B00011000 0x18
#define B00100000 0x20
#define B00111000 0x38
#define B01000000 0x40
#define B01111000 0x78
#define B10000000 0x80
#define B10110000 0xB0
#define B11000000 0xC0
#define B11010000 0xD0
#define B11111000 0xF8
#define B11111100 0xFC
#endif

/*----------------------------------Local Prototypes--------------------------*/
static void flood(TFT_LCD *lcd, uint16_t color, uint32_t len);
static void setLR(TFT_LCD *lcd);
static void writeRegister8(uint8_t a, uint8_t d);
static void writeRegister16(uint16_t a, uint16_t d);
static void writeRegister24(uint8_t a, uint32_t d);
static void writeRegister32(uint8_t a, uint32_t d);
static void writeRegisterPair(uint8_t aH, uint8_t aL, uint16_t d);

/*----------------------------------Init Tables-------------------------------*/
static const uint8_t HX8347G_regValues[] = {
    0x2E, 0x89,
    0x29, 0x8F,
    0x2B, 0x02,
    0xE2, 0x00,
    0xE4, 0x01,
    0xE5, 0x10,
    0xE6, 0x01,
    0xE7, 0x10,
    0xE8, 0x70,
    0xF2, 0x00,
    0xEA, 0x00,
    0xEB, 0x20,
    0xEC, 0x3C,
    0xED, 0xC8,
    0xE9, 0x38,
    0xF1, 0x01,
    0x1B, 0x1A,
    0x1A, 0x02,
    0x24, 0x61,
    0x25, 0x5C,
    0x18, 0x36,
    0x19, 0x01,
    0x1F, 0x88,
    TFTLCD_DELAY, 5,
    0x1F, 0x80,
    TFTLCD_DELAY, 5,
    0x1F, 0x90,
    TFTLCD_DELAY, 5,
    0x1F, 0xD4,
    TFTLCD_DELAY, 5,
    0x17, 0x05,
    0x36, 0x09,
    0x28, 0x38,
    TFTLCD_DELAY, 40,
    0x28, 0x3C,
    0x02, 0x00,
    0x03, 0x00,
    0x04, 0x00,
    0x05, 0xEF,
    0x06, 0x00,
    0x07, 0x00,
    0x08, 0x01,
    0x09, 0x3F
};

static const uint8_t HX8357D_regValues[] = {
    HX8357_SWRESET, 0,
    HX8357D_SETC, 3, 0xFF, 0x83, 0x57,
    TFTLCD_DELAY, 250,
    HX8357_SETRGB, 4, 0x00, 0x00, 0x06, 0x06,
    HX8357D_SETCOM, 1, 0x25,
    HX8357_SETOSC, 1, 0x68,
    HX8357_SETPANEL, 1, 0x05,
    HX8357_SETPWR1, 6, 0x00, 0x15, 0x1C, 0x1C, 0x83, 0xAA,
    HX8357D_SETSTBA, 6, 0x50, 0x50, 0x01, 0x3C, 0x1E, 0x08,
    HX8357D_SETCYC, 7, 0x02, 0x40, 0x00, 0x2A, 0x2A, 0x0D, 0x78,
    HX8357_COLMOD, 1, 0x55,
    HX8357_MADCTL, 1, 0xC0,
    HX8357_TEON, 1, 0x00,
    HX8357_TEARLINE, 2, 0x00, 0x02,
    HX8357_SLPOUT, 0,
    TFTLCD_DELAY, 150,
    HX8357_DISPON, 0,
    TFTLCD_DELAY, 50,
};

static const uint16_t ILI932x_regValues[] = {
    ILI932X_START_OSC, 0x0001,
    TFTLCD_DELAY, 50,
    ILI932X_DRIV_OUT_CTRL, 0x0100,
    ILI932X_DRIV_WAV_CTRL, 0x0700,
    ILI932X_ENTRY_MOD, 0x1030,
    ILI932X_RESIZE_CTRL, 0x0000,
    ILI932X_DISP_CTRL2, 0x0202,
    ILI932X_DISP_CTRL3, 0x0000,
    ILI932X_DISP_CTRL4, 0x0000,
    ILI932X_RGB_DISP_IF_CTRL1, 0x0,
    ILI932X_FRM_MARKER_POS, 0x0,
    ILI932X_RGB_DISP_IF_CTRL2, 0x0,
    ILI932X_POW_CTRL1, 0x0000,
    ILI932X_POW_CTRL2, 0x0007,
    ILI932X_POW_CTRL3, 0x0000,
    ILI932X_POW_CTRL4, 0x0000,
    TFTLCD_DELAY, 200,
    ILI932X_POW_CTRL1, 0x1690,
    ILI932X_POW_CTRL2, 0x0227,
    TFTLCD_DELAY, 50,
    ILI932X_POW_CTRL3, 0x001A,
    TFTLCD_DELAY, 50,
    ILI932X_POW_CTRL4, 0x1800,
    ILI932X_POW_CTRL7, 0x002A,
    TFTLCD_DELAY, 50,
    ILI932X_GAMMA_CTRL1, 0x0000,
    ILI932X_GAMMA_CTRL2, 0x0000,
    ILI932X_GAMMA_CTRL3, 0x0000,
    ILI932X_GAMMA_CTRL4, 0x0206,
    ILI932X_GAMMA_CTRL5, 0x0808,
    ILI932X_GAMMA_CTRL6, 0x0007,
    ILI932X_GAMMA_CTRL7, 0x0201,
    ILI932X_GAMMA_CTRL8, 0x0000,
    ILI932X_GAMMA_CTRL9, 0x0000,
    ILI932X_GAMMA_CTRL10, 0x0000,
    ILI932X_GRAM_HOR_AD, 0x0000,
    ILI932X_GRAM_VER_AD, 0x0000,
    ILI932X_HOR_START_AD, 0x0000,
    ILI932X_HOR_END_AD, 0x00EF,
    ILI932X_VER_START_AD, 0X0000,
    ILI932X_VER_END_AD, 0x013F,
    ILI932X_GATE_SCAN_CTRL1, 0xA700,
    ILI932X_GATE_SCAN_CTRL2, 0x0003,
    ILI932X_GATE_SCAN_CTRL3, 0x0000,
    ILI932X_PANEL_IF_CTRL1, 0X0010,
    ILI932X_PANEL_IF_CTRL2, 0X0000,
    ILI932X_PANEL_IF_CTRL3, 0X0003,
    ILI932X_PANEL_IF_CTRL4, 0X1100,
    ILI932X_PANEL_IF_CTRL5, 0X0000,
    ILI932X_PANEL_IF_CTRL6, 0X0000,
    ILI932X_DISP_CTRL1, 0x0133,
};

static const uint16_t LGDP4535_regValues[] = {
    0x15, 0x0030,
    0x9A, 0x0010,
    0x11, 0x0020,
    0x10, 0x3428,
    0x12, 0x0002,
    0x13, 0x1046,
    TFTLCD_DELAY, 40,
    0x12, 0x0012,
    TFTLCD_DELAY, 40,
    0x10, 0x3420,
    0x13, 0x3046,
    TFTLCD_DELAY, 70,
    0x30, 0x0000,
    0x31, 0x0402,
    0x32, 0x0307,
    0x33, 0x0304,
    0x34, 0x0004,
    0x35, 0x0401,
    0x36, 0x0707,
    0x37, 0x0305,
    0x38, 0x0610,
    0x39, 0x0610,
    0x01, 0x0100,
    0x02, 0x0300,
    0x03, 0x1030,
    0x08, 0x0808,
    0x0A, 0x0008,
    0x60, 0x2700,
    0x61, 0x0001,
    0x90, 0x013E,
    0x92, 0x0100,
    0x93, 0x0100,
    0xA0, 0x3000,
    0xA3, 0x0010,
    0x07, 0x0001,
    0x07, 0x0021,
    0x07, 0x0023,
    0x07, 0x0033,
    0x07, 0x0133,
};

/*----------------------------------Implementation----------------------------*/

void TFTLCD_init(TFT_LCD *lcd)
{
    /* Initialize base GFX */
    GFX_init(&lcd->gfx, TFTLCD_WIDTH, TFTLCD_HEIGHT);
    
    /* Set function pointers for optimized drawing */
    lcd->gfx.drawPixel = TFTLCD_drawPixel;
    lcd->gfx.drawFastVLine_opt = TFTLCD_drawFastVLine;
    lcd->gfx.drawFastHLine_opt = TFTLCD_drawFastHLine;
    lcd->gfx.fillRect_opt = TFTLCD_fillRect;
    lcd->gfx.fillScreen_opt = TFTLCD_fillScreen;
    
    lcd->driver = TFTLCD_ID_UNKNOWN;
    
    /* Initialize TC4D hardware */
    TC4D_initTFTControlPins();
    TC4D_setWriteDir();
}

void TFTLCD_reset(TFT_LCD *lcd)
{
    CS_IDLE;
    WR_IDLE;
    RD_IDLE;
    
    /* Toggle reset pin - needs longer pulse for reliable reset */
    TC4D_TFT_RESET_HIGH();
    delay(50);   /* Ensure high before going low */
    TC4D_TFT_RESET_LOW();
    delay(15);   /* Reset pulse width - increased from 2ms */
    TC4D_TFT_RESET_HIGH();
    delay(150);  /* Wait for display to initialize after reset */
    
    /* Data transfer sync */
    CS_ACTIVE;
    CD_COMMAND;
    TC4D_write8(0x00);
    WR_STROBE; WR_STROBE; WR_STROBE;
    CS_IDLE;
}

void TFTLCD_begin(TFT_LCD *lcd, uint16_t id)
{
    uint16_t i = 0;
    uint16_t a, d;
    uint8_t r, len;
    
    TFTLCD_reset(lcd);
    delay(200);
    
    if ((id == 0x9325) || (id == 0x9328)) {
        lcd->driver = TFTLCD_ID_932X;
        CS_ACTIVE;
        while (i < sizeof(ILI932x_regValues) / sizeof(uint16_t)) {
            a = ILI932x_regValues[i++];
            d = ILI932x_regValues[i++];
            if (a == TFTLCD_DELAY) {
                delay(d);
            } else {
                writeRegister16(a, d);
            }
        }
        TFTLCD_setRotation(lcd, lcd->gfx.rotation);
        TFTLCD_setAddrWindow(lcd, 0, 0, TFTLCD_WIDTH - 1, TFTLCD_HEIGHT - 1);
    }
    else if (id == 0x4535) {
        lcd->driver = TFTLCD_ID_932X;
        CS_ACTIVE;
        while (i < sizeof(LGDP4535_regValues) / sizeof(uint16_t)) {
            a = LGDP4535_regValues[i++];
            d = LGDP4535_regValues[i++];
            if (a == TFTLCD_DELAY) {
                delay(d);
            } else {
                writeRegister16(a, d);
            }
        }
        TFTLCD_setRotation(lcd, lcd->gfx.rotation);
        TFTLCD_setAddrWindow(lcd, 0, 0, TFTLCD_WIDTH - 1, TFTLCD_HEIGHT - 1);
    }
    else if (id == 0x9341) {
        lcd->driver = TFTLCD_ID_9341;
        CS_ACTIVE;
        writeRegister8(ILI9341_SOFTRESET, 0);
        delay(50);
        writeRegister8(ILI9341_DISPLAYOFF, 0);
        writeRegister8(ILI9341_POWERCONTROL1, 0x23);
        writeRegister8(ILI9341_POWERCONTROL2, 0x10);
        writeRegister16(ILI9341_VCOMCONTROL1, 0x2B2B);
        writeRegister8(ILI9341_VCOMCONTROL2, 0xC0);
        writeRegister8(ILI9341_MEMCONTROL, ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
        writeRegister8(ILI9341_PIXELFORMAT, 0x55);
        writeRegister16(ILI9341_FRAMECONTROL, 0x001B);
        writeRegister8(ILI9341_ENTRYMODE, 0x07);
        writeRegister8(ILI9341_SLEEPOUT, 0);
        delay(150);
        writeRegister8(ILI9341_DISPLAYON, 0);
        delay(500);
        TFTLCD_setAddrWindow(lcd, 0, 0, TFTLCD_WIDTH - 1, TFTLCD_HEIGHT - 1);
        return;
    }
    else if (id == 0x8357) {
        lcd->driver = TFTLCD_ID_HX8357D;
        CS_ACTIVE;
        i = 0;
        while (i < sizeof(HX8357D_regValues)) {
            r = HX8357D_regValues[i++];
            len = HX8357D_regValues[i++];
            if (r == TFTLCD_DELAY) {
                delay(len);
            } else {
                CS_ACTIVE;
                CD_COMMAND;
                TC4D_write8(r);
                CD_DATA;
                while (len--) {
                    TC4D_write8(HX8357D_regValues[i++]);
                }
                CS_IDLE;
            }
        }
        return;
    }
    else if (id == 0x7575) {
        lcd->driver = TFTLCD_ID_7575;
        CS_ACTIVE;
        i = 0;
        while (i < sizeof(HX8347G_regValues)) {
            a = HX8347G_regValues[i++];
            d = HX8347G_regValues[i++];
            if (a == TFTLCD_DELAY) {
                delay(d);
            } else {
                writeRegister8((uint8_t)a, (uint8_t)d);
            }
        }
        TFTLCD_setRotation(lcd, lcd->gfx.rotation);
        setLR(lcd);
    }
    else {
        lcd->driver = TFTLCD_ID_UNKNOWN;
    }
}

void TFTLCD_setAddrWindow(TFT_LCD *lcd, int x1, int y1, int x2, int y2)
{
    int x, y, t;
    uint32_t addr;
    
    CS_ACTIVE;
    
    if (lcd->driver == TFTLCD_ID_932X) {
        switch (lcd->gfx.rotation) {
            default:
                x = x1;
                y = y1;
                break;
            case 1:
                t = y1;
                y1 = x1;
                x1 = TFTLCD_WIDTH - 1 - y2;
                y2 = x2;
                x2 = TFTLCD_WIDTH - 1 - t;
                x = x2;
                y = y1;
                break;
            case 2:
                t = x1;
                x1 = TFTLCD_WIDTH - 1 - x2;
                x2 = TFTLCD_WIDTH - 1 - t;
                t = y1;
                y1 = TFTLCD_HEIGHT - 1 - y2;
                y2 = TFTLCD_HEIGHT - 1 - t;
                x = x2;
                y = y2;
                break;
            case 3:
                t = x1;
                x1 = y1;
                y1 = TFTLCD_HEIGHT - 1 - x2;
                x2 = y2;
                y2 = TFTLCD_HEIGHT - 1 - t;
                x = x1;
                y = y2;
                break;
        }
        writeRegister16(0x0050, x1);
        writeRegister16(0x0051, x2);
        writeRegister16(0x0052, y1);
        writeRegister16(0x0053, y2);
        writeRegister16(0x0020, x);
        writeRegister16(0x0021, y);
    }
    else if (lcd->driver == TFTLCD_ID_7575) {
        writeRegisterPair(HX8347G_COLADDRSTART_HI, HX8347G_COLADDRSTART_LO, x1);
        writeRegisterPair(HX8347G_ROWADDRSTART_HI, HX8347G_ROWADDRSTART_LO, y1);
        writeRegisterPair(HX8347G_COLADDREND_HI, HX8347G_COLADDREND_LO, x2);
        writeRegisterPair(HX8347G_ROWADDREND_HI, HX8347G_ROWADDREND_LO, y2);
    }
    else if ((lcd->driver == TFTLCD_ID_9341) || (lcd->driver == TFTLCD_ID_HX8357D)) {
        addr = x1;
        addr <<= 16;
        addr |= x2;
        writeRegister32(ILI9341_COLADDRSET, addr);
        addr = y1;
        addr <<= 16;
        addr |= y2;
        writeRegister32(ILI9341_PAGEADDRSET, addr);
    }
    
    CS_IDLE;
}

static void setLR(TFT_LCD *lcd)
{
    CS_ACTIVE;
    writeRegisterPair(HX8347G_COLADDREND_HI, HX8347G_COLADDREND_LO, lcd->gfx._width - 1);
    writeRegisterPair(HX8347G_ROWADDREND_HI, HX8347G_ROWADDREND_LO, lcd->gfx._height - 1);
    CS_IDLE;
}

static void flood(TFT_LCD *lcd, uint16_t color, uint32_t len)
{
    uint16_t blocks;
    uint8_t i, hi = color >> 8, lo = color;
    
    CS_ACTIVE;
    CD_COMMAND;
    
    if (lcd->driver == TFTLCD_ID_9341) {
        TC4D_write8(0x2C);
    } else if (lcd->driver == TFTLCD_ID_932X) {
        TC4D_write8(0x00);
        TC4D_write8(0x22);
    } else if (lcd->driver == TFTLCD_ID_HX8357D) {
        TC4D_write8(HX8357_RAMWR);
    } else {
        TC4D_write8(0x22);
    }
    
    CD_DATA;
    TC4D_write8(hi);
    TC4D_write8(lo);
    len--;
    
    blocks = (uint16_t)(len / 64);
    if (hi == lo) {
        while (blocks--) {
            i = 16;
            do {
                WR_STROBE; WR_STROBE; WR_STROBE; WR_STROBE;
                WR_STROBE; WR_STROBE; WR_STROBE; WR_STROBE;
            } while (--i);
        }
        for (i = (uint8_t)len & 63; i--; ) {
            WR_STROBE;
            WR_STROBE;
        }
    } else {
        while (blocks--) {
            i = 16;
            do {
                TC4D_write8(hi); TC4D_write8(lo);
                TC4D_write8(hi); TC4D_write8(lo);
                TC4D_write8(hi); TC4D_write8(lo);
                TC4D_write8(hi); TC4D_write8(lo);
            } while (--i);
        }
        for (i = (uint8_t)len & 63; i--; ) {
            TC4D_write8(hi);
            TC4D_write8(lo);
        }
    }
    CS_IDLE;
}

void TFTLCD_drawPixel(TFT_GFX *gfx, int16_t x, int16_t y, uint16_t color)
{
    TFT_LCD *lcd = (TFT_LCD *)gfx;
    int16_t t;
    uint8_t hi, lo;
    
    if ((x < 0) || (y < 0) || (x >= gfx->_width) || (y >= gfx->_height)) return;
    
    CS_ACTIVE;
    
    if (lcd->driver == TFTLCD_ID_932X) {
        switch (gfx->rotation) {
            case 1:
                t = x;
                x = TFTLCD_WIDTH - 1 - y;
                y = t;
                break;
            case 2:
                x = TFTLCD_WIDTH - 1 - x;
                y = TFTLCD_HEIGHT - 1 - y;
                break;
            case 3:
                t = x;
                x = y;
                y = TFTLCD_HEIGHT - 1 - t;
                break;
        }
        writeRegister16(0x0020, x);
        writeRegister16(0x0021, y);
        writeRegister16(0x0022, color);
    }
    else if (lcd->driver == TFTLCD_ID_7575) {
        switch (gfx->rotation) {
            default: lo = 0; break;
            case 1: lo = 0x60; break;
            case 2: lo = 0xc0; break;
            case 3: lo = 0xa0; break;
        }
        writeRegister8(HX8347G_MEMACCESS, lo);
        writeRegisterPair(HX8347G_COLADDRSTART_HI, HX8347G_COLADDRSTART_LO, x);
        writeRegisterPair(HX8347G_ROWADDRSTART_HI, HX8347G_ROWADDRSTART_LO, y);
        hi = color >> 8;
        lo = color;
        CD_COMMAND;
        TC4D_write8(0x22);
        CD_DATA;
        TC4D_write8(hi);
        TC4D_write8(lo);
    }
    else if ((lcd->driver == TFTLCD_ID_9341) || (lcd->driver == TFTLCD_ID_HX8357D)) {
        TFTLCD_setAddrWindow(lcd, x, y, gfx->_width - 1, gfx->_height - 1);
        CS_ACTIVE;
        CD_COMMAND;
        TC4D_write8(0x2C);
        CD_DATA;
        TC4D_write8(color >> 8);
        TC4D_write8(color);
    }
    
    CS_IDLE;
}

void TFTLCD_drawFastHLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t length, uint16_t color)
{
    TFT_LCD *lcd = (TFT_LCD *)gfx;
    int16_t x2;
    
    if ((length <= 0) || (y < 0) || (y >= gfx->_height) ||
        (x >= gfx->_width) || ((x2 = (x + length - 1)) < 0)) return;
    
    if (x < 0) {
        length += x;
        x = 0;
    }
    if (x2 >= gfx->_width) {
        x2 = gfx->_width - 1;
        length = x2 - x + 1;
    }
    
    TFTLCD_setAddrWindow(lcd, x, y, x2, y);
    flood(lcd, color, length);
    
    if (lcd->driver == TFTLCD_ID_932X) {
        TFTLCD_setAddrWindow(lcd, 0, 0, gfx->_width - 1, gfx->_height - 1);
    } else {
        setLR(lcd);
    }
}

void TFTLCD_drawFastVLine(TFT_GFX *gfx, int16_t x, int16_t y, int16_t length, uint16_t color)
{
    TFT_LCD *lcd = (TFT_LCD *)gfx;
    int16_t y2;
    
    if ((length <= 0) || (x < 0) || (x >= gfx->_width) ||
        (y >= gfx->_height) || ((y2 = (y + length - 1)) < 0)) return;
    
    if (y < 0) {
        length += y;
        y = 0;
    }
    if (y2 >= gfx->_height) {
        y2 = gfx->_height - 1;
        length = y2 - y + 1;
    }
    
    TFTLCD_setAddrWindow(lcd, x, y, x, y2);
    flood(lcd, color, length);
    
    if (lcd->driver == TFTLCD_ID_932X) {
        TFTLCD_setAddrWindow(lcd, 0, 0, gfx->_width - 1, gfx->_height - 1);
    } else {
        setLR(lcd);
    }
}

void TFTLCD_fillRect(TFT_GFX *gfx, int16_t x1, int16_t y1, int16_t w, int16_t h, uint16_t fillcolor)
{
    TFT_LCD *lcd = (TFT_LCD *)gfx;
    int16_t x2, y2;
    
    if ((w <= 0) || (h <= 0) || (x1 >= gfx->_width) || (y1 >= gfx->_height) ||
        ((x2 = x1 + w - 1) < 0) || ((y2 = y1 + h - 1) < 0)) return;
    
    if (x1 < 0) { w += x1; x1 = 0; }
    if (y1 < 0) { h += y1; y1 = 0; }
    if (x2 >= gfx->_width) { x2 = gfx->_width - 1; w = x2 - x1 + 1; }
    if (y2 >= gfx->_height) { y2 = gfx->_height - 1; h = y2 - y1 + 1; }
    
    TFTLCD_setAddrWindow(lcd, x1, y1, x2, y2);
    flood(lcd, fillcolor, (uint32_t)w * (uint32_t)h);
    
    if (lcd->driver == TFTLCD_ID_932X) {
        TFTLCD_setAddrWindow(lcd, 0, 0, gfx->_width - 1, gfx->_height - 1);
    } else {
        setLR(lcd);
    }
}

void TFTLCD_fillScreen(TFT_GFX *gfx, uint16_t color)
{
    TFT_LCD *lcd = (TFT_LCD *)gfx;
    uint16_t x = 0, y = 0;
    
    if (lcd->driver == TFTLCD_ID_932X) {
        switch (gfx->rotation) {
            default: x = 0; y = 0; break;
            case 1: x = TFTLCD_WIDTH - 1; y = 0; break;
            case 2: x = TFTLCD_WIDTH - 1; y = TFTLCD_HEIGHT - 1; break;
            case 3: x = 0; y = TFTLCD_HEIGHT - 1; break;
        }
        CS_ACTIVE;
        writeRegister16(0x0020, x);
        writeRegister16(0x0021, y);
    }
    else if ((lcd->driver == TFTLCD_ID_9341) || (lcd->driver == TFTLCD_ID_7575) ||
             (lcd->driver == TFTLCD_ID_HX8357D)) {
        TFTLCD_setAddrWindow(lcd, 0, 0, gfx->_width - 1, gfx->_height - 1);
    }
    
    flood(lcd, color, (long)TFTLCD_WIDTH * (long)TFTLCD_HEIGHT);
}

void TFTLCD_pushColors(TFT_LCD *lcd, uint16_t *data, uint8_t len, boolean first)
{
    uint16_t color;
    uint8_t hi, lo;
    
    CS_ACTIVE;
    if (first == TRUE) {
        CD_COMMAND;
        if (lcd->driver == TFTLCD_ID_932X) TC4D_write8(0x00);
        if ((lcd->driver == TFTLCD_ID_9341) || (lcd->driver == TFTLCD_ID_HX8357D)) {
            TC4D_write8(0x2C);
        } else {
            TC4D_write8(0x22);
        }
    }
    CD_DATA;
    while (len--) {
        color = *data++;
        hi = color >> 8;
        lo = color;
        TC4D_write8(hi);
        TC4D_write8(lo);
    }
    CS_IDLE;
}

void TFTLCD_setRotation(TFT_LCD *lcd, uint8_t x)
{
    uint16_t t;
    
    GFX_setRotation(&lcd->gfx, x);
    
    CS_ACTIVE;
    
    if (lcd->driver == TFTLCD_ID_932X) {
        switch (lcd->gfx.rotation) {
            default: t = 0x1030; break;
            case 1: t = 0x1028; break;
            case 2: t = 0x1000; break;
            case 3: t = 0x1018; break;
        }
        writeRegister16(0x0003, t);
        TFTLCD_setAddrWindow(lcd, 0, 0, lcd->gfx._width - 1, lcd->gfx._height - 1);
    }
    
    if (lcd->driver == TFTLCD_ID_7575) {
        uint8_t rot;
        switch (lcd->gfx.rotation) {
            default: rot = 0; break;
            case 1: rot = 0x60; break;
            case 2: rot = 0xc0; break;
            case 3: rot = 0xa0; break;
        }
        writeRegister8(HX8347G_MEMACCESS, rot);
        setLR(lcd);
    }
    
    if (lcd->driver == TFTLCD_ID_9341) {
        switch (lcd->gfx.rotation) {
            case 2: t = ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR; break;
            case 3: t = ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR; break;
            case 0: t = ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR; break;
            case 1: t = ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR; break;
            default: t = 2; //setting as default the first scenario
        }
        writeRegister8(ILI9341_MADCTL, (uint8_t)t);
        TFTLCD_setAddrWindow(lcd, 0, 0, lcd->gfx._width - 1, lcd->gfx._height - 1);
    }
    
    if (lcd->driver == TFTLCD_ID_HX8357D) {
        switch (lcd->gfx.rotation) {
            case 2: t = HX8357B_MADCTL_RGB; break;
            case 3: t = HX8357B_MADCTL_MX | HX8357B_MADCTL_MV | HX8357B_MADCTL_RGB; break;
            case 0: t = HX8357B_MADCTL_MX | HX8357B_MADCTL_MY | HX8357B_MADCTL_RGB; break;
            case 1: t = HX8357B_MADCTL_MY | HX8357B_MADCTL_MV | HX8357B_MADCTL_RGB; break;
            default: t = 2; //setting as default the first scenario
        }
        writeRegister8(ILI9341_MADCTL, (uint8_t)t);
        TFTLCD_setAddrWindow(lcd, 0, 0, lcd->gfx._width - 1, lcd->gfx._height - 1);
    }
}

uint16_t TFTLCD_readID(TFT_LCD *lcd)
{
    uint8_t hi, lo;
    uint16_t id;
    
    if (TFTLCD_readReg(lcd, 0x04) == 0x8000) {
        writeRegister24(HX8357D_SETC, 0xFF8357);
        delay(300);
        if (TFTLCD_readReg(lcd, 0xD0) == 0x990000) {
            return 0x8357;
        }
    }
    
    id = (uint16_t)TFTLCD_readReg(lcd, 0xD3);
    if (id == 0x9341) {
        return id;
    }
    
    CS_ACTIVE;
    CD_COMMAND;
    TC4D_write8(0x00);
    WR_STROBE;
    TC4D_setReadDir();
    CD_DATA;
    hi = TC4D_read8();
    lo = TC4D_read8();
    TC4D_setWriteDir();
    CS_IDLE;
    
    id = hi;
    id <<= 8;
    id |= lo;
    return id;
}

uint32_t TFTLCD_readReg(TFT_LCD *lcd, uint8_t r)
{
    uint32_t id;
    uint8_t x;
    
    CS_ACTIVE;
    CD_COMMAND;
    TC4D_write8(r);
    TC4D_setReadDir();
    CD_DATA;
    delayMicroseconds(50);
    x = TC4D_read8();
    id = x;
    id <<= 8;
    x = TC4D_read8();
    id |= x;
    id <<= 8;
    x = TC4D_read8();
    id |= x;
    id <<= 8;
    x = TC4D_read8();
    id |= x;
    CS_IDLE;
    TC4D_setWriteDir();
    
    return id;
}

uint16_t TFTLCD_readPixel(TFT_LCD *lcd, int16_t x, int16_t y)
{
    uint8_t hi, lo, r, g, b;
    int16_t t;
    
    if ((x < 0) || (y < 0) || (x >= lcd->gfx._width) || (y >= lcd->gfx._height)) return 0;
    
    CS_ACTIVE;
    
    if (lcd->driver == TFTLCD_ID_932X) {
        switch (lcd->gfx.rotation) {
            case 1:
                t = x;
                x = TFTLCD_WIDTH - 1 - y;
                y = t;
                break;
            case 2:
                x = TFTLCD_WIDTH - 1 - x;
                y = TFTLCD_HEIGHT - 1 - y;
                break;
            case 3:
                t = x;
                x = y;
                y = TFTLCD_HEIGHT - 1 - t;
                break;
        }
        writeRegister16(0x0020, x);
        writeRegister16(0x0021, y);
        
        /* Read twice to get correct value */
        for (uint8_t pass = 0; pass < 2; pass++) {
            CD_COMMAND;
            TC4D_write8(0x00);
            TC4D_write8(0x22);
            CD_DATA;
            TC4D_setReadDir();
            hi = TC4D_read8();
            hi = TC4D_read8();
            hi = TC4D_read8();
            lo = TC4D_read8();
            TC4D_setWriteDir();
        }
        CS_IDLE;
        return ((uint16_t)hi << 8) | lo;
    }
    else if (lcd->driver == TFTLCD_ID_7575) {
        writeRegisterPair(HX8347G_COLADDRSTART_HI, HX8347G_COLADDRSTART_LO, x);
        writeRegisterPair(HX8347G_ROWADDRSTART_HI, HX8347G_ROWADDRSTART_LO, y);
        CD_COMMAND;
        TC4D_write8(0x22);
        TC4D_setReadDir();
        CD_DATA;
        r = TC4D_read8();
        r = TC4D_read8();
        g = TC4D_read8();
        b = TC4D_read8();
        TC4D_setWriteDir();
        CS_IDLE;
        return (((uint16_t)r & B11111000) << 8) |
               (((uint16_t)g & B11111100) << 3) |
               (b >> 3);
    }
    
    return 0;
}

uint16_t TFTLCD_color565(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

/*----------------------------------Register Write Helpers--------------------*/

static void writeRegister8(uint8_t a, uint8_t d)
{
    CD_COMMAND;
    TC4D_write8(a);
    CD_DATA;
    TC4D_write8(d);
}

static void writeRegister16(uint16_t a, uint16_t d)
{
    CD_COMMAND;
    TC4D_write8(a >> 8);
    TC4D_write8(a);
    CD_DATA;
    TC4D_write8(d >> 8);
    TC4D_write8(d);
}

static void writeRegister24(uint8_t a, uint32_t d)
{
    CD_COMMAND;
    TC4D_write8(a);
    CD_DATA;
    TC4D_write8(d >> 16);
    TC4D_write8(d >> 8);
    TC4D_write8(d);
}

static void writeRegister32(uint8_t a, uint32_t d)
{
    CD_COMMAND;
    TC4D_write8(a);
    CD_DATA;
    TC4D_write8(d >> 24);
    TC4D_write8(d >> 16);
    TC4D_write8(d >> 8);
    TC4D_write8(d);
}

static void writeRegisterPair(uint8_t aH, uint8_t aL, uint16_t d)
{
    writeRegister8(aH, d >> 8);
    writeRegister8(aL, d);
}
