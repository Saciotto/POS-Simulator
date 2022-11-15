#include "gui.h"

#include "framework.h"
#include "lvgl.h"

#include "gui_dimensions.h"

static lv_fragment_manager_t* manager = NULL;
static lv_obj_t* status_bar = NULL;
static lv_obj_t* working_area = NULL;

static void delete_fragment_manager(lv_event_t* e)
{
    lv_fragment_manager_t* manager = (lv_fragment_manager_t*) lv_event_get_user_data(e);
    lv_fragment_manager_del(manager);
}

void gui_init_engine(lv_fragment_t *initial_screen)
{
    lv_obj_t* scr = lv_obj_create(NULL);
    lv_scr_load(scr);

    status_bar = gui_create_status_bar(scr);

    lv_obj_t* container = lv_obj_create(scr);
    lv_obj_remove_style_all(container);
    lv_obj_align_to(container, status_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_size(container, GUI_SCREEN_WIDTH, GUI_SCREEN_HEIGHT - GUI_STATUS_BAR_HEIGHT);

    working_area = lv_obj_create(container);
    lv_obj_remove_style_all(working_area);
    lv_obj_set_size(working_area, GUI_SCREEN_WIDTH, GUI_SCREEN_HEIGHT - GUI_STATUS_BAR_HEIGHT);

    manager = lv_fragment_manager_create(NULL);
    lv_obj_add_event_cb(scr, delete_fragment_manager, LV_EVENT_DELETE, manager);
    lv_fragment_manager_replace(manager, initial_screen, &working_area);
}

void gui_inflate_screen(lv_fragment_t *screen)
{
    lv_fragment_manager_push(manager, screen, &working_area);
}

void gui_close_screen()
{
    lv_fragment_manager_pop(manager);
}

void gui_execute_app()
{
    fw_timestamp now;
    fw_timestamp last;
    fw_get_timestamp(&last);
    for (;;) {
        lv_event_send(status_bar, LV_EVENT_REFRESH, NULL);
        lv_task_handler();
        fw_sleep_ms(27);
        fw_get_timestamp(&now);
        uint32_t diff = (uint32_t) fw_timestamp_diff(&now, &last);
        last = now;
        lv_tick_inc(diff);
    }
}
