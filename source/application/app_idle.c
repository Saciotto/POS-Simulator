#include "app_idle.h"

#include "lvgl.h"
#include "framework.h"

#define CANVAS_WIDTH  320
#define CANVAS_HEIGHT 20

#define STATUS_BAR_WIDTH  320
#define STATUS_BAR_HEIGHT 20

static lv_obj_t *clock_label = NULL;

static void update_clock()
{
    char time[6];
    fw_clock clock;
    fw_get_clock(&clock);
    fw_format_time(&clock, "h:mm", time, sizeof(time));
    lv_label_set_text(clock_label, time);
}

static void add_clock(lv_obj_t *parent)
{
    clock_label = lv_label_create(parent);
    lv_obj_set_style_text_align(clock_label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(clock_label, LV_ALIGN_CENTER, 0, 0);
    update_clock();
}

static void add_status_bar(lv_obj_t *parent)
{
    static uint8_t buf[LV_CANVAS_BUF_SIZE_INDEXED_1BIT(STATUS_BAR_WIDTH, STATUS_BAR_HEIGHT)];

    lv_obj_t *canvas = lv_canvas_create(parent);
    lv_canvas_set_buffer(canvas, buf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_INDEXED_1BIT);
    lv_canvas_set_palette(canvas, 0, lv_palette_main(LV_PALETTE_BLUE));

    lv_color_t c0;
    c0.full = 0;
    lv_canvas_fill_bg(canvas, c0, LV_OPA_COVER);

    add_clock(canvas);
}

void idle_screen_update()
{
    update_clock();
}

void idle_screen()
{
    add_status_bar(lv_scr_act());
}
