#include "gui.h"

#include "lvgl.h"

void idle_screen_update()
{
    gui_update_status_bar();
}

void idle_screen()
{
    gui_add_status_bar(lv_scr_act());
}
