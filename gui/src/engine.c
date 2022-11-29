#include "gui.h"

#include "framework.h"
#include "lvgl.h"

#include "dimensions.h"

static lv_fragment_manager_t *manager = NULL;
static lv_obj_t *status_bar = NULL;
static lv_obj_t *working_area = NULL;
static lv_group_t *keypad_group = NULL;

static void delete_fragment_manager(lv_event_t *e)
{
    lv_fragment_manager_t *manager = (lv_fragment_manager_t *) lv_event_get_user_data(e);
    lv_fragment_manager_del(manager);
}

static void on_key_pressed(lv_event_t *e)
{
    lv_fragment_t *top = lv_fragment_manager_get_top(manager);
    if (top != NULL && top->obj != NULL)
        lv_event_send(top->obj, LV_EVENT_KEY, e);
}

void initialize_gui_engine(lv_fragment_t *initial_screen)
{
    lv_obj_t *scr = lv_obj_create(NULL);
    lv_scr_load(scr);

    status_bar = status_bar_create(scr);

    lv_obj_t *container = lv_obj_create(scr);
    lv_obj_remove_style_all(container);
    lv_obj_align_to(container, status_bar, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_size(container, SCREEN_WIDTH, SCREEN_HEIGHT - STATUS_BAR_HEIGHT);

    working_area = lv_obj_create(container);
    lv_obj_remove_style_all(working_area);
    lv_obj_set_size(working_area, SCREEN_WIDTH, SCREEN_HEIGHT - STATUS_BAR_HEIGHT);

    manager = lv_fragment_manager_create(NULL);
    lv_obj_add_event_cb(scr, delete_fragment_manager, LV_EVENT_DELETE, manager);
    inflate_screen(initial_screen);

    keypad_group = lv_group_create();
    lv_group_add_obj(keypad_group, scr);
    lv_indev_set_group(fw_keypad_indev(), keypad_group);
    lv_obj_add_event_cb(scr, on_key_pressed, LV_EVENT_KEY, NULL);
}

void inflate_screen(lv_fragment_t *screen)
{
    lv_fragment_manager_push(manager, screen, &working_area);
}

void close_screen()
{
    lv_fragment_manager_pop(manager);
}

void execute_app()
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
