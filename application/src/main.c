#include "framework.h"
#include "gui.h"

#include "controllers.h"

void app_main()
{
    fw_initialize_lvgl();
    initialize_theme();

    lv_fragment_t *idle = idle_create();
    initialize_gui_engine(idle);

    execute_app();
}
