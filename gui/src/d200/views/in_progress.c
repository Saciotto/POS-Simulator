#include "views.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "framework.h"
#include "gui.h"
#include "theme.h"

#define MESSAGE_WIDTH        (SCREEN_WIDTH - 10)
#define MESSAGE_TOP_MARGIN   10
#define ICON_VERTICAL_OFFSET -30

static void construct_in_progress_screen(lv_fragment_t *fragment, void *args);
static lv_obj_t *create_in_progress_screen(lv_fragment_t *self, lv_obj_t *parent);

typedef struct {
    lv_fragment_t base;
    in_progress_config config;
} in_progress_instance;

const lv_fragment_class_t in_pregress_screen = {
    .constructor_cb = construct_in_progress_screen,
    .create_obj_cb = create_in_progress_screen,
    .instance_size = sizeof(in_progress_instance)
};

static void construct_in_progress_screen(lv_fragment_t *fragment, void *args)
{
    ((in_progress_instance *) fragment)->config = *((in_progress_config *) args);
}

static void on_key_pressed(lv_event_t *e)
{
    in_progress_instance *self = (in_progress_instance *) e->user_data;
    uint32_t key = lv_indev_get_key(lv_indev_get_act());
    if (key == KEY_CANCEL) {
        self->config.on_cancel_clicked();
    } else if (key == KEY_BACK) {
        self->config.on_back_clicked();
    }
}

static lv_obj_t *create_in_progress_screen(lv_fragment_t *self, lv_obj_t *parent)
{
    // Create body
    lv_obj_t *body = body_create(parent);

    // Create icon
    lv_obj_t *logo = lv_img_create(body);
    lv_img_set_src(logo, &img_working);
    lv_color_t color = PRIMARY_DARK_COLOR;
    lv_obj_set_style_img_recolor(logo, color, LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(logo, LV_OPA_COVER, LV_STATE_DEFAULT);
    lv_obj_align(logo, LV_ALIGN_CENTER, 0, ICON_VERTICAL_OFFSET);

    // Create message
    lv_obj_t *msg = lv_label_create(body);
    lv_label_set_text(msg, "Esta tela não está presente nesta demonstração.");
    lv_obj_add_style(msg, regular_text_style(), LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(msg, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
    lv_obj_set_width(msg, MESSAGE_WIDTH);
    lv_obj_align_to(msg, logo, LV_ALIGN_OUT_BOTTOM_MID, 0, MESSAGE_TOP_MARGIN);

    lv_obj_add_event_cb(body, on_key_pressed, LV_EVENT_KEY, self);
    return body;
}
