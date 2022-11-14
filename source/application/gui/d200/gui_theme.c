#include "gui.h"
#include "gui_assets.h"

#include "lvgl.h"

void gui_configure_theme()
{
    lv_disp_t* display = lv_disp_get_default();
    lv_theme_t* th = lv_theme_default_init(display, SECONDARY_COLOR, SECONDARY_LIGHT_COLOR, 0, LV_FONT_DEFAULT);
    lv_disp_set_theme(display, th);
}
