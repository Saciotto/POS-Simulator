#ifndef PLATF_LVGL_DRIVER_H
#define PLATF_LVGL_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void driver_flush_display(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p);

void driver_read_touchscreen(lv_indev_drv_t * drv, lv_indev_data_t*data);

void driver_read_keypad(lv_indev_drv_t * drv, lv_indev_data_t*data);

#ifdef __cplusplus
}
#endif

#endif // PLATF_LVGL_DRIVER_H
