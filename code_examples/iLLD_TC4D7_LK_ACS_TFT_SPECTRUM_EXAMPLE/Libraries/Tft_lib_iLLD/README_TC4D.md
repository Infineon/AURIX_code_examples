# TFT Shield Library for TC4D

This is an adapted version of the Adafruit GFX and TFTLCD libraries for use with the Infineon TC4D microcontroller. It provides a pure C implementation optimized for embedded systems.

## Overview

The libraries provide graphics primitives and TFT LCD driver support for TC4D using iLLD (Infineon Low-Level Drivers).

## Library Structure

```
Tft_lib_iLLD/
├── TFT_GFX/           # Core graphics library
│   ├── TFT_GFX_TC4.h  # Graphics functions and types
│   ├── TFT_GFX_TC4.c  # Graphics implementation
│   └── glcdfont.c     # Font data
├── TFT_LCD/           # TFT LCD driver
│   ├── TFT_LCD_TC4.h  # LCD driver interface
│   ├── TFT_LCD_TC4.c  # LCD driver implementation
│   └── registers.h    # LCD controller registers
├── TC4_HAL.h          # Hardware Abstraction Layer
├── TC4_HAL.c          # HAL implementation
└── README_TC4D.md     # This file
```

## Configuration

### 1. Include Headers

```c
#include <Tft_lib_iLLD/TFT_GFX/TFT_GFX_TC4.h>
#include <Tft_lib_iLLD/TFT_LCD/TFT_LCD_TC4.h>
#include <Tft_lib_iLLD/TC4_HAL.h>
```

### 2. Configure Pin Mappings

Edit `TC4D_HAL.h` to match your hardware connections:

```c
/* TFT LCD Data Bus Pins (D0-D7) */
#define TFT_D0_PORT     (&MODULE_P00)
#define TFT_D0_PIN      0
/* ... configure all data pins ... */

/* TFT LCD Control Pins */
#define TFT_CS_PORT     (&MODULE_P02)
#define TFT_CS_PIN      0
/* ... configure all control pins ... */
```

### 3. Include Paths

Add these paths to your project:
- Path to `TFT_Shield` folder
- Path to `iLLD` library (`iLLD/TC4xx/...`)
- Path to `Service` library
- Path to `Infra` library

### 4. Link Source Files

Link these source files to your project:
- `TFT_Shield/TC4D_HAL.c`
- `TFT_Shield/Elegoo_GFX/Elegoo_GFX.cpp`
- `TFT_Shield/Elegoo_TFTLCD/Elegoo_TFTLCD.cpp`

## Usage Example

```c
#define TC4D_PLATFORM

#include "TC4D_HAL.h"
#include "Elegoo_TFTLCD/Elegoo_TFTLCD.h"

Elegoo_TFTLCD tft;

int main(void)
{
    /* Initialize timing system */
    initTime();
    
    /* Initialize TFT shield */
    TC4D_TFTShield_Init();
    
    /* Initialize LCD */
    tft.begin(tft.readID());
    tft.setRotation(0);
    
    /* Draw something */
    tft.fillScreen(0x0000);  /* Black */
    tft.setCursor(10, 10);
    tft.setTextColor(0xFFFF);  /* White */
    tft.setTextSize(2);
    tft.println("Hello TC4D!");
    
    /* Main loop */
    while (1)
    {
        /* Application code */
    }
    
    return 0;
}
```

## API Compatibility

The adapted libraries maintain API compatibility with the original Arduino versions where possible:

### TFT_GFX
All drawing functions work identically. The `print()` and `println()` functions are implemented directly instead of inheriting from Arduino's Print class.

### TFT_LCD
All functions work identically. The default constructor creates an LCD object using the pins configured in `TC4D_HAL.h`.

## Hardware Abstraction Layer (HAL)

The HAL provides Arduino-compatible functions:

<table>
<tr>
<th>Arduino Function</th>
<th>TC4D HAL Function</th>
</tr>
<tr>
<td><code>pinMode(pin, mode)</code></td>
<td><code>TC4D_pinMode(port, pin, mode)</code></td>
</tr>
<tr>
<td><code>digitalWrite(pin, val)</code></td>
<td><code>TC4D_digitalWrite(port, pin, val)</code></td>
</tr>
<tr>
<td><code>digitalRead(pin)</code></td>
<td><code>TC4D_digitalRead(port, pin)</code></td>
</tr>
<tr>
<td><code>delay(ms)</code></td>
<td><code>delay(ms)</code></td>
</tr>
<tr>
<td><code>delayMicroseconds(us)</code></td>
<td><code>delayMicroseconds(us)</code></td>
</tr>
<tr>
<td><code>millis()</code></td>
<td><code>millis()</code></td>
</tr>
<tr>
<td><code>micros()</code></td>
<td><code>micros()</code></td>
</tr>
</table>

## Notes

1. **Performance**: The TC4D implementation uses inline functions where possible for optimal performance.

2. **Data Bus**: The default implementation assumes D0-D7 are on consecutive pins of PORT P00. If your hardware uses different pin arrangements, modify `TC4D_write8()` and `TC4D_read8()` in `TC4D_HAL.h`.

3. **Timing**: The timing functions rely on the iLLD BSP timer system. Call `initTime()` before using any timing or delay functions.

## License

Original libraries are MIT licensed by Adafruit/Elegoo.
TC4D adaptations follow the same license.
