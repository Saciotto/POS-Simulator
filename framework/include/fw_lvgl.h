#ifndef FW_LVGL_H
#define FW_LVGL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void fw_initialize_lvgl();

lv_disp_t *fw_display_indev();
lv_indev_t *fw_touchscreen_indev();
lv_indev_t *fw_keypad_indev();

#ifdef __cplusplus
}
#endif

#endif // FW_LVGL_H
