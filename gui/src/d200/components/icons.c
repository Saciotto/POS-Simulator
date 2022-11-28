#include "components.h"

#include "assets.h"
#include "gui.h"

const lv_img_dsc_t* get_icon(int icon_id)
{
    switch (icon_id) {
    case ICON_WIFI:
        return &img_wifi_3;
    case ICON_BRIGHTNESS:
        return &img_brightness;
    case ICON_DOLLAR:
        return &img_dollar;
    case ICON_GEAR:
        return &img_gear;
    case ICON_HOTEL:
        return &img_hotel;
    case ICON_NO_CARD:
        return &img_no_card;
    case ICON_PHONE:
        return &img_phone;
    case ICON_RECEIPT:
        return &img_receipt;
    case ICON_UNDO:
        return &img_undo;
    case ICON_NONE:
    default:
        return NULL;
    }
}