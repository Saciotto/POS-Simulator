#include "components.h"

#include "assets.h"
#include "dimensions.h"

lv_obj_t* title_bar_create(lv_obj_t* parent, const char *message)
{
    lv_obj_t* title = lv_obj_create(parent);
    lv_obj_remove_style_all(title);
    lv_obj_set_style_bg_opa(title, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(title, BACKGROUND_COLOR, 0);
    lv_obj_set_size(title, SCREEN_WIDTH, TITLE_BAR_HEIGHT);
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_t* label = lv_label_create(title);
    lv_label_set_text(label, message);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(label, &font_roboto_18, 0);
    return title;
}
