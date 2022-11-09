#include "gui_status_bar.h"

#include "lvgl.h"
#include "framework.h"

#include "gui.h"

static lv_obj_t *status_bar_canvas = NULL;
static lv_obj_t *clock_label = NULL;
static lv_obj_t *battery_label = NULL;
static lv_obj_t *wifi_icon = NULL;
static lv_obj_t *battery_icon = NULL;
static lv_obj_t *cellular_icon = NULL;

LV_IMG_DECLARE(img_wifi_0)
LV_IMG_DECLARE(img_wifi_1)
LV_IMG_DECLARE(img_wifi_2)
LV_IMG_DECLARE(img_wifi_3)

LV_IMG_DECLARE(img_signal_0)
LV_IMG_DECLARE(img_signal_1)
LV_IMG_DECLARE(img_signal_2)
LV_IMG_DECLARE(img_signal_3)
LV_IMG_DECLARE(img_signal_4)
LV_IMG_DECLARE(img_signal_5)

static void update_clock()
{
    char text[6];
    fw_time time;
    fw_get_time(&time);
    fw_format_time(&time, "h:mm", text, sizeof(text));
    lv_label_set_text(clock_label, text);
}

static void add_clock()
{
    clock_label = lv_label_create(status_bar_canvas);
    lv_obj_set_style_text_align(clock_label, LV_ALIGN_LEFT_MID, 0);
    lv_obj_align(clock_label, LV_ALIGN_LEFT_MID, GUI_DEFAULT_PADDING, 0);
    update_clock();
}

static void add_battery_icon()
{
    battery_icon = lv_img_create(status_bar_canvas);
    lv_img_set_src(battery_icon, LV_SYMBOL_BATTERY_3);
    lv_obj_align(battery_icon, LV_ALIGN_RIGHT_MID, -GUI_DEFAULT_PADDING, 0);
}

static void add_battery_percentage()
{
    battery_label = lv_label_create(status_bar_canvas);
    lv_obj_set_style_text_align(battery_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(battery_label, battery_icon, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
    lv_label_set_text(battery_label, "67%");
}

static void add_cellular_icon()
{
    cellular_icon = lv_img_create(status_bar_canvas);
    lv_img_set_src(cellular_icon, &img_signal_3);
    lv_obj_align_to(cellular_icon, battery_label, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
}

static void add_wifi_icon()
{
    wifi_icon = lv_img_create(status_bar_canvas);
    lv_img_set_src(wifi_icon, &img_wifi_2);
    lv_obj_align_to(wifi_icon, cellular_icon, LV_ALIGN_OUT_LEFT_MID, -GUI_DEFAULT_PADDING, 0);
}

static lv_obj_t *add_status_bar_area(lv_obj_t *screen)
{
    static uint8_t buf[LV_CANVAS_BUF_SIZE_INDEXED_1BIT(GUI_SCREEN_WIDTH, GUI_STATUS_BAR_HEIGHT)];

    status_bar_canvas = lv_canvas_create(screen);
    lv_canvas_set_buffer(status_bar_canvas, buf, GUI_SCREEN_WIDTH, GUI_STATUS_BAR_HEIGHT, LV_IMG_CF_INDEXED_1BIT);
    lv_canvas_set_palette(status_bar_canvas, 0, lv_palette_main(LV_PALETTE_BLUE));

    lv_color_t c0;
    c0.full = 0;
    lv_canvas_fill_bg(status_bar_canvas, c0, LV_OPA_COVER);
}

void gui_update_status_bar()
{
    update_clock();
}

void gui_add_status_bar(lv_obj_t *screen)
{
    add_status_bar_area(screen);
    add_clock();
    add_battery_icon();
    add_battery_percentage();
    add_cellular_icon();
    add_wifi_icon();
}
