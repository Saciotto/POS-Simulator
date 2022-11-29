#include <stdio.h>

#include "assets.h"
#include "dimensions.h"
#include "framework.h"

typedef struct {
    lv_obj_t *clock_label;
    lv_obj_t *battery_label;
    lv_obj_t *wifi_icon;
    lv_obj_t *battery_icon;
    lv_obj_t *cellular_icon;
} status_bar_instance;

static void update_clock(status_bar_instance *self)
{
    char text[6];
    fw_time time;
    fw_get_time(&time);
    fw_format_time(&time, "h:mm", text, sizeof(text));
    lv_label_set_text(self->clock_label, text);
}

static void update_battery(status_bar_instance *self)
{
    int level = fw_get_battery_level();
    if (level <= 5)
        lv_img_set_src(self->battery_icon, &img_battery_1);
    else if (level <= 20)
        lv_img_set_src(self->battery_icon, &img_battery_2);
    else if (level <= 40)
        lv_img_set_src(self->battery_icon, &img_battery_3);
    else if (level <= 60)
        lv_img_set_src(self->battery_icon, &img_battery_4);
    else if (level <= 80)
        lv_img_set_src(self->battery_icon, &img_battery_5);
    else
        lv_img_set_src(self->battery_icon, &img_battery_full);
    lv_color_t color = lv_color_white();
    lv_obj_set_style_img_recolor(self->battery_icon, color, LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(self->battery_icon, LV_OPA_COVER, LV_STATE_DEFAULT);

    char text[20];
    snprintf(text, sizeof(text), "%d%%", level);
    lv_label_set_text(self->battery_label, text);
}

static void update_cellular(status_bar_instance *self)
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
    lv_color_t color = lv_color_white();
    lv_obj_set_style_img_recolor(self->cellular_icon, color, LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(self->cellular_icon, LV_OPA_COVER, LV_STATE_DEFAULT);
}

static void update_wifi(status_bar_instance *self)
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
    lv_color_t color = lv_color_white();
    lv_obj_set_style_img_recolor(self->wifi_icon, color, LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(self->wifi_icon, LV_OPA_COVER, LV_STATE_DEFAULT);
}

static void update_relative_positions(status_bar_instance *self)
{
    lv_obj_align_to(self->battery_label, self->battery_icon, LV_ALIGN_OUT_LEFT_MID, -DEFAULT_PADDING, 0);
    lv_obj_align_to(self->cellular_icon, self->battery_label, LV_ALIGN_OUT_LEFT_MID, -DEFAULT_PADDING, 0);
    lv_obj_align_to(self->wifi_icon, self->cellular_icon, LV_ALIGN_OUT_LEFT_MID, -DEFAULT_PADDING, 0);
}

static void update_status_bar(status_bar_instance *self)
{
    update_clock(self);
    update_battery(self);
    update_cellular(self);
    update_wifi(self);
    update_relative_positions(self);
}

static void status_bar_refresh(lv_event_t *e)
{
    status_bar_instance *self = (status_bar_instance *) lv_event_get_user_data(e);
    update_status_bar(self);
}

static void status_bar_delete(lv_event_t *e)
{
    void *self = lv_event_get_user_data(e);
    free(self);
}

lv_obj_t *status_bar_create(lv_obj_t *screen)
{
    lv_obj_t *sb = lv_obj_create(screen);

    status_bar_instance *self = calloc(1, sizeof(*self));
    self->battery_label = lv_label_create(sb);
    self->clock_label = lv_label_create(sb);
    self->battery_icon = lv_img_create(sb);
    self->cellular_icon = lv_img_create(sb);
    self->wifi_icon = lv_img_create(sb);

    lv_obj_remove_style_all(sb);
    lv_obj_set_style_bg_opa(sb, LV_OPA_100, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(sb, PRIMARY_DARK_COLOR, LV_STATE_DEFAULT);
    lv_obj_set_size(sb, SCREEN_WIDTH, STATUS_BAR_HEIGHT);

    lv_obj_set_style_text_color(self->battery_label, lv_color_white(), LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(self->clock_label, lv_color_white(), LV_STATE_DEFAULT);

    lv_obj_set_style_text_align(self->battery_label, LV_TEXT_ALIGN_RIGHT, LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(self->clock_label, LV_ALIGN_LEFT_MID, LV_STATE_DEFAULT);
    lv_obj_align(self->battery_icon, LV_ALIGN_RIGHT_MID, -DEFAULT_PADDING, 0);
    lv_obj_align(self->clock_label, LV_ALIGN_LEFT_MID, DEFAULT_PADDING, 0);

    lv_obj_set_user_data(sb, (void *) self);
    lv_obj_add_event_cb(sb, status_bar_delete, LV_EVENT_DELETE, self);
    lv_obj_add_event_cb(sb, status_bar_refresh, LV_EVENT_REFRESH, self);

    update_status_bar(self);
    return sb;
}
