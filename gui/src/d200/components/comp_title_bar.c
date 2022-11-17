#include "gui_components.h"

#include "gui_assets.h"
#include "gui_dimensions.h"

static lv_style_t *title_bar_style()
{
    static bool created = false;
    static lv_style_t style;
    if (created)
        return &style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &font_roboto_18);
    return &style;
}

lv_obj_t* comp_title_bar_create(lv_obj_t* parent, const char *message)
{
    lv_obj_t* title = lv_obj_create(parent);
    lv_obj_remove_style_all(title);
    lv_obj_set_style_bg_opa(title, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(title, PRIMARY_COLOR, 0);
    lv_obj_set_size(title, GUI_SCREEN_WIDTH, GUI_TITLE_BAR_HEIGHT);
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_style_t *style = title_bar_style();
    lv_obj_t* label = lv_label_create(title);
    lv_label_set_text(label, message);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 22, 0);
    lv_obj_add_style(label, style, 0);
    return title;
}
