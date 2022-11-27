#include "framework.h"
#include "gui.h"

void app_main()
{
    fw_initialize_lvgl();
    initialize_theme();

    lv_fragment_t *idle = lv_fragment_create(&idle_screen, NULL);
    initialize_gui_engine(idle);

    execute_app();
}
