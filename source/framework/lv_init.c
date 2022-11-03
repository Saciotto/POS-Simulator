#include "lv_init.h"

#include "lvgl.h"
#include "framework.h"

#define DISPLAY_HOR_RES 320
#define DISPLAY_VER_RES 240

static void display_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one
     *`put_px` is just an example, it needs to be implemented by you.*/
    int32_t x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            fw_setDisplayPixel(x, y, color_p->ch.red, color_p->ch.green, color_p->ch.blue);
            color_p++;
        }
    }
    /* Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}

void fw_initializeLVGL()
{
    // Library initialization
    lv_init();

    // Display buffer
    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf1[DISPLAY_HOR_RES * 100];
    static lv_color_t buf2[DISPLAY_HOR_RES * 100];
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISPLAY_HOR_RES * 100);

    // Display driver
    static lv_disp_drv_t disp_drv;          /*A variable to hold the drivers. Must be static or global.*/
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
    disp_drv.flush_cb = display_flush;      /*Set a flush callback to draw to the display*/
    disp_drv.hor_res = DISPLAY_HOR_RES;     /*Set the horizontal resolution in pixels*/
    disp_drv.ver_res = DISPLAY_VER_RES;     /*Set the vertical resolution in pixels*/

    lv_disp_t* disp;
    disp = lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/

    lv_theme_t* th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                           LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, th);
}
