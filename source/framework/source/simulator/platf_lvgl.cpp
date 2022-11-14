

#include "fw_lvgl.h"

#include "platf_lvgl_driver.h"
#include "lvgl.h"

#define DISPLAY_HOR_RES 320
#define DISPLAY_VER_RES 240

static lv_disp_t *display;
static lv_indev_t *touchscreen;
static lv_indev_t *keypad;

void fw_initialize_lvgl()
{
    // Library initialization
    lv_init();

    // Display buffer
    static lv_disp_draw_buf_t display_buffer;
    static lv_color_t buf1[DISPLAY_HOR_RES * 100];
    static lv_color_t buf2[DISPLAY_HOR_RES * 100];
    lv_disp_draw_buf_init(&display_buffer, buf1, buf2, DISPLAY_HOR_RES * 100);

    // Display driver
    static lv_disp_drv_t display_driver;
    lv_disp_drv_init(&display_driver);
    display_driver.draw_buf = &display_buffer;
    display_driver.flush_cb = driver_flush_display;
    display_driver.hor_res = DISPLAY_HOR_RES;
    display_driver.ver_res = DISPLAY_VER_RES;
    display = lv_disp_drv_register(&display_driver);

    // Touchscreen driver
    static lv_indev_drv_t touch_driver;
    lv_indev_drv_init(&touch_driver);
    touch_driver.type = LV_INDEV_TYPE_POINTER;
    touch_driver.read_cb = driver_read_touchscreen;
    touchscreen = lv_indev_drv_register(&touch_driver);

    // Keypad driver
    static lv_indev_drv_t keypad_driver;
    lv_indev_drv_init(&keypad_driver);
    keypad_driver.type = LV_INDEV_TYPE_KEYPAD;
    keypad_driver.read_cb = driver_read_keypad;
    keypad = lv_indev_drv_register(&keypad_driver);
}
