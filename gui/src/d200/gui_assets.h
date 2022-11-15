#ifndef GUI_ASSETS_H
#define GUI_ASSETS_H

#include "lvgl.h"

// fonts

LV_FONT_DECLARE(font_montserrat_14)
LV_FONT_DECLARE(font_montserrat_26)
LV_FONT_DECLARE(font_roboto_14)
LV_FONT_DECLARE(font_roboto_18)

// images

LV_IMG_DECLARE(img_logo)

LV_IMG_DECLARE(img_wifi_0)
LV_IMG_DECLARE(img_wifi_1)
LV_IMG_DECLARE(img_wifi_2)
LV_IMG_DECLARE(img_wifi_3)

LV_IMG_DECLARE(img_signal_0)
LV_IMG_DECLARE(img_signal_1)
LV_IMG_DECLARE(img_signal_2)
LV_IMG_DECLARE(img_signal_3)
LV_IMG_DECLARE(img_signal_4)
LV_IMG_DECLARE(img_signal_5)

// colors

#define PRIMARY_COLOR       lv_color_make(0xb3, 0x9d, 0xdb)
#define PRIMARY_DARK_COLOR  lv_color_make(0x83, 0x6f, 0xa9)
#define PRIMARY_LIGHT_COLOR lv_color_make(0xe6, 0xce, 0xff)

#define SECONDARY_COLOR       lv_color_make(0x79, 0x86, 0xcb)
#define SECONDARY_DARK_COLOR  lv_color_make(0x49, 0x59, 0x9a)
#define SECONDARY_LIGHT_COLOR lv_color_make(0xaa, 0xb6, 0xfe)

#endif // GUI_ASSETS_H
