#include <stdio.h>

#include "assets.h"
#include "dimensions.h"
#include "framework.h"

typedef struct {
    lv_obj_t* clock_label;
    lv_obj_t* battery_label;
    lv_obj_t* wifi_icon;
    lv_obj_t* battery_icon;
    lv_obj_t* cellular_icon;
} status_bar_instance;

static void update_clock(status_bar_instance* self)
{
    char text[6];
    fw_time time;
    fw_get_time(&time);
    fw_format_time(&time, "h:mm", text, sizeof(text));
    lv_label_set_text(self->clock_label, text);
}

static void update_battery(status_bar_instance* self)
{
    int level = fw_get_battery_level();
    if (level <= 5)
        lv_img_set_src(self->battery_icon, LV_SYMBOL_BATTERY_EMPTY);
    else if (level <= 25)
        lv_img_set_src(self->battery_icon, LV_SYMBOL_BATTERY_1);
    else if (level <= 50)
        lv_img_set_src(self->battery_icon, LV_SYMBOL_BATTERY_2);
    else if (level <= 75)
        lv_img_set_src(self->battery_icon, LV_SYMBOL_BATTERY_3);
    else
        lv_img_set_src(self->battery_icon, LV_SYMBOL_BATTERY_FULL);

    char text[20];
    snprintf(text, sizeof(text), "%d%%", level);
    lv_label_set_text(self->battery_label, text);
}

static void update_cellular(status_bar_instance* self)
{
    int level = fw_get_cellular_signal();
    if (level == 0)
        lv_img_set_src(self->cellular_icon, &img_signal_0);
    else if (level <= 8)
        lv_img_set_src(self->cellular_icon, &img_signal_1);
    else if (level <= 14)
        lv_img_set_src(self->cellular_icon, &img_signal_2);
    else if (level <= 20)
        lv_img_set_src(self->cellular_icon, &img_signal_3);
    else if (level <= 26)
        lv_img_set_src(self->cellular_icon, &img_signal_4);
    else
        lv_img_set_src(self->cellular_icon, &img_signal_5);
}

static void update_wifi(status_bar_instance* self)
{
    int level = fw_get_wifi_signal();
    if (level <= 10)
        lv_img_set_src(self->wifi_icon, &img_wifi_0);
    else if (level <= 20)
        lv_img_set_src(self->wifi_icon, &img_wifi_1);
    else if (level <= 40)
        lv_img_set_src(self->wifi_icon, &img_wifi_2);
    else
        lv_img_set_src(self->wifi_icon, &img_wifi_3);
}

static void update_relative_positions(status_bar_instance* self)
{
    lv_obj_align_to(self->battery_label, self->battery_icon, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
    lv_obj_align_to(self->cellular_icon, self->battery_label, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
    lv_obj_align_to(self->wifi_icon, self->cellular_icon, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
}

static void update_status_bar(status_bar_instance* self)
{
    update_clock(self);
    update_battery(self);
    update_cellular(self);
    update_wifi(self);
    update_relative_positions(self);
}

static void status_bar_refresh(lv_event_t* e)
{
    status_bar_instance* self = (status_bar_instance*) lv_event_get_user_data(e);
    update_status_bar(self);
}

static void status_bar_delete(lv_event_t* e)
{
    void* self = lv_event_get_user_data(e);
    free(self);
}

lv_obj_t* status_bar_create(lv_obj_t* screen)
{
    lv_obj_t* sb = lv_obj_create(screen);

    status_bar_instance* self = calloc(1, sizeof(*self));
    self->battery_label = lv_label_create(sb);
    self->clock_label = lv_label_create(sb);
    self->battery_icon = lv_img_create(sb);
    self->cellular_icon = lv_img_create(sb);
    self->wifi_icon = lv_img_create(sb);

    lv_obj_remove_style_all(sb);
    lv_obj_set_style_bg_opa(sb, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(sb, PRIMARY_DARK_COLOR, 0);
    lv_obj_set_size(sb, GUI_SCREEN_WIDTH, GUI_STATUS_BAR_HEIGHT);

    lv_obj_set_style_text_align(self->battery_label, LV_TEXT_ALIGN_RIGHT, 0);
    lv_obj_set_style_text_align(self->clock_label, LV_ALIGN_LEFT_MID, 0);
    lv_obj_align(self->battery_icon, LV_ALIGN_RIGHT_MID, -GUI_DEFAULT_PADDING, 0);
    lv_obj_align(self->clock_label, LV_ALIGN_LEFT_MID, GUI_DEFAULT_PADDING, 0);

    lv_obj_set_user_data(sb, (void*) self);
    lv_obj_add_event_cb(sb, status_bar_delete, LV_EVENT_DELETE, self);
    lv_obj_add_event_cb(sb, status_bar_refresh, LV_EVENT_REFRESH, self);

    update_status_bar(self);
    return sb;
}
