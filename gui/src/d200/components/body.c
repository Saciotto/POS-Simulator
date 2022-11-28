#include "components.h"

#include "assets.h"
#include "dimensions.h"

lv_obj_t* body_create(lv_obj_t* parent)
{
    lv_obj_t* body = lv_obj_create(parent);
    lv_obj_remove_style_all(body);
    lv_obj_set_style_bg_opa(body, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(body, BACKGROUND_COLOR, 0);
    lv_obj_set_size(body, SCREEN_WIDTH, SCREEN_HEIGHT - STATUS_BAR_HEIGHT);
    return body;
}
