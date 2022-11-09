#include "framework.h"

#include "lvgl.h"
#include "demos/widgets/lv_demo_widgets.h"

#include "gui.h"

void app_main()
{
    fw_initialize_lvgl();
    idle_screen();

    fw_timestamp now;
    fw_timestamp last;
    fw_get_timestamp(&last);
    for (;;) {
        idle_screen_update();
        lv_task_handler();
        fw_sleep_ms(27);
        fw_get_timestamp(&now);
        uint32_t diff = (uint32_t) fw_timestamp_diff(&now, &last);
        last = now;
        lv_tick_inc(diff);
    }
}
