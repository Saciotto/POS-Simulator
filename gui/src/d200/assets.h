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
LV_IMG_DECLARE(img_working)

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

LV_IMG_DECLARE(img_battery_1)
LV_IMG_DECLARE(img_battery_2)
LV_IMG_DECLARE(img_battery_3)
LV_IMG_DECLARE(img_battery_4)
LV_IMG_DECLARE(img_battery_5)
LV_IMG_DECLARE(img_battery_full)

LV_IMG_DECLARE(img_brightness)
LV_IMG_DECLARE(img_dollar)
LV_IMG_DECLARE(img_gear)
LV_IMG_DECLARE(img_hotel)
LV_IMG_DECLARE(img_no_card)
LV_IMG_DECLARE(img_phone)
LV_IMG_DECLARE(img_receipt)
LV_IMG_DECLARE(img_undo)


// colors

#define BACKGROUND_COLOR             lv_color_make(0xf2, 0xf2, 0xf2)
#define ALTERNATIVE_BACKGROUND_COLOR lv_color_make(0xff, 0xff, 0xff)

#define TEXT_COLOR lv_color_make(0x00, 0x00, 0x00)

#define PRIMARY_COLOR       lv_color_make(0x79, 0x86, 0xcb)
#define PRIMARY_DARK_COLOR  lv_color_make(0x49, 0x59, 0x9a)
#define PRIMARY_LIGHT_COLOR lv_color_make(0xaa, 0xb6, 0xfe)

#define SECONDARY_COLOR       lv_color_make(0xb3, 0x9d, 0xdb)
#define SECONDARY_DARK_COLOR  lv_color_make(0x83, 0x6f, 0xa9)
#define SECONDARY_LIGHT_COLOR lv_color_make(0xe6, 0xce, 0xff)

// keys

#define KEY_ENTER     100
#define KEY_BACK      101
#define KEY_CANCEL    102
#define KEY_MAIN_MENU 201
#define KEY_SHORTCUT  202
#define KEY_NEXT      202
#define KEY_PREVIOUS  201

#endif // GUI_ASSETS_H
