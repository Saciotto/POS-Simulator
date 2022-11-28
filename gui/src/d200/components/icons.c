#include "components.h"

#include "assets.h"
#include "gui.h"

const lv_img_dsc_t* get_icon(int icon_id)
{
    switch (icon_id) {
    case ICON_WIFI:
        return &img_wifi_3;
    case ICON_NONE:
    default:
        return NULL;
    }
}