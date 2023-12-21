#include "Ifx_Types.h"
#include "tfthw.h"
#include "lvgl.h"
#include "touch.h"




void my_flush_cb(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);


void lv_configure(void)
{
    tft_init();
    lv_init();

    /*Create a display buffer for LVGL. LVGL will render
     *  the graphics here first, and seed the rendered image
     *  to the display. The buffer size can be set freely but 1/10
     *   screen size is a good starting point.*/
    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf_1[TFT_XSIZE * 32];
    lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, TFT_XSIZE*32);

    /*Implement and register a function which can copy the
     * rendered image to an area of your display*/
    static lv_disp_drv_t disp_drv; /*A variable to hold the drivers. Can belocal variable*/
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.flush_cb = my_flush_cb; /*Set your driver function. Set a flush callback to draw to the display*/
    disp_drv.draw_buf = &disp_buf; /*Assigns the buffer to the display. Set an initialized buffer*/
    disp_drv.full_refresh = 1;

    /*Set the resolution of the display*/
    disp_drv.hor_res = TFT_XSIZE;
    disp_drv.ver_res = TFT_YSIZE;

    lv_disp_t * disp;
    disp = lv_disp_drv_register(&disp_drv); /*Finally register the driver*/


    // Touc init
    touch_init();
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;

    /*Register the driver in LVGL and save the created input device object*/
    lv_indev_t * indev_touchpad;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
}




void my_flush_cb(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen oneby-one*/
    uint32 numberOfPixel;
    if((area->x2 >= area->x1) && area->y2 >= area->y1)
    {
      numberOfPixel = ((area->x2+1) - area->x1) * ((area->y2+1) - area->y1);
      tft_display_setxy(area->x1, area->y1, area->x2, area->y2);
      tft_flush_row_buff(numberOfPixel,color_p);
    }

/* IMPORTANT!!!
* Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}


/* Will be called by the library to read the touchpad */
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    /*Save the pressed coordinates and the state*/
    if ((touch_driver.touchmode & MASK_TOUCH_DOWN) != 0 || (touch_driver.touchmode & MASK_TOUCH_MOVE) != 0)
    {
        touch_driver.touchmode &= ~MASK_TOUCH_DOWN;   //clear
        touch_driver.touchmode &= ~MASK_TOUCH_MOVE;   //clear
        data->point.x = touch_driver.xdisp;
        data->point.y = touch_driver.ydisp;
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
       data->state = LV_INDEV_STATE_RELEASED;

    }
}
