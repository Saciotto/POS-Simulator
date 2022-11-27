#include "gui.h"
#include "assets.h"

#include "lvgl.h"

void initialize_theme()
{
    lv_disp_t* display = lv_disp_get_default();
    lv_theme_t* th = lv_theme_default_init(display, SECONDARY_COLOR, SECONDARY_LIGHT_COLOR, 0, &font_roboto_18);
    lv_disp_set_theme(display, th);
}

lv_style_t *gui_menu_label_style()
{
    static bool created = false;
    static lv_style_t style;
    if (created)
        return &style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &font_roboto_14);
    created = true;
    return &style;
}

lv_style_t *gui_menu_title_style()
{
    static bool created = false;
    static lv_style_t style;
    if (created)
        return &style;
    lv_style_init(&style);
    lv_style_set_text_font(&style, &font_roboto_18);
    created = true;
    return &style;
}
