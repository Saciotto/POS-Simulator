#include "gui_status_bar.h"

#include "lvgl.h"
#include "framework.h"

#include "gui.h"

static lv_obj_t *clock_label = NULL;
static lv_obj_t *battery_label = NULL;
static lv_obj_t *carrier_label = NULL;
static lv_obj_t *wifi_icon = NULL;
static lv_obj_t *battery_icon = NULL;
static lv_obj_t *cellular_icon = NULL;

LV_IMG_DECLARE(img_wifi_2);
LV_IMG_DECLARE(img_signal_3);

static void update_clock()
{
    char text[6];
    fw_time time;
    fw_get_time(&time);
    fw_format_time(&time, "h:mm", text, sizeof(text));
    lv_label_set_text(clock_label, text);
}

static void add_cellular_icon(lv_obj_t *status_bar)
{
    cellular_icon = lv_img_create(status_bar);
    lv_img_set_src(cellular_icon, &img_signal_3);
    lv_obj_align(cellular_icon, LV_ALIGN_LEFT_MID, 4, 0);
}

static void add_carrier(lv_obj_t *status_bar)
{
    carrier_label = lv_label_create(status_bar);
    lv_obj_set_style_text_align(carrier_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(carrier_label, cellular_icon, LV_ALIGN_OUT_RIGHT_MID, 4, 0);
    lv_label_set_text(carrier_label, "Claro");
}

static void add_wifi_icon(lv_obj_t *status_bar)
{
    wifi_icon = lv_img_create(status_bar);
    lv_img_set_src(wifi_icon, &img_wifi_2);
    lv_obj_align_to(wifi_icon, carrier_label, LV_ALIGN_OUT_RIGHT_MID, 4, 0);
}

static void add_clock(lv_obj_t *status_bar)
{
    clock_label = lv_label_create(status_bar);
    lv_obj_set_style_text_align(clock_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(clock_label, LV_ALIGN_CENTER, 0, 0);
    update_clock();
}

static void add_battery_icon(lv_obj_t *status_bar)
{
    wifi_icon = lv_img_create(status_bar);
    lv_img_set_src(wifi_icon, LV_SYMBOL_BATTERY_3);
    lv_obj_align(wifi_icon, LV_ALIGN_RIGHT_MID, -4, 0);
}

static void add_battery_percentage(lv_obj_t *status_bar)
{
    battery_label = lv_label_create(status_bar);
    lv_obj_set_style_text_align(battery_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(battery_label, wifi_icon, LV_ALIGN_OUT_LEFT_MID, -4, 0);
    lv_label_set_text(battery_label, "67%");
}

void gui_update_status_bar()
{
    update_clock();
}

void gui_add_status_bar(lv_obj_t *screen)
{
    static uint8_t buf[LV_CANVAS_BUF_SIZE_INDEXED_1BIT(GUI_SCREEN_WIDTH, GUI_STATUS_BAR_HEIGHT)];

    lv_obj_t *canvas = lv_canvas_create(screen);
    lv_canvas_set_buffer(canvas, buf, GUI_SCREEN_WIDTH, GUI_STATUS_BAR_HEIGHT, LV_IMG_CF_INDEXED_1BIT);
    lv_canvas_set_palette(canvas, 0, lv_palette_main(LV_PALETTE_BLUE));

    lv_color_t c0;
    c0.full = 0;
    lv_canvas_fill_bg(canvas, c0, LV_OPA_COVER);

    add_cellular_icon(canvas);
    add_carrier(canvas);
    add_wifi_icon(canvas);
    add_clock(canvas);
    add_battery_icon(canvas);
    add_battery_percentage(canvas);
}
