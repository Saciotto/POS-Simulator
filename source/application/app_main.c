#include "framework.h"
#include "gui.h"

void app_main()
{
    fw_initialize_lvgl();
    gui_configure_theme();

    lv_fragment_t *idle = lv_fragment_create(&gui_idle_screen, NULL);
    gui_init_engine(idle);

    gui_execute_app();
}
