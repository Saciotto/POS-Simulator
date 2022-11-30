#include "views.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "framework.h"
#include "gui.h"
#include "theme.h"

#include <stdint.h>
#include <stdio.h>

#define MESSAGE_WIDTH      (SCREEN_WIDTH - 10)
#define MESSAGE_TOP_MARGIN 10

static void construct_amount_screen(lv_fragment_t *fragment, void *args);
static lv_obj_t *create_amount_screen(lv_fragment_t *fragment, lv_obj_t *parent);

typedef struct {
    lv_fragment_t base;
    amount_config config;
    lv_obj_t *value_label;
    uint64_t value;
} amount_instance;

const lv_fragment_class_t amount_screen = {
    .constructor_cb = construct_amount_screen,
    .create_obj_cb = create_amount_screen,
    .instance_size = sizeof(amount_instance)
};

static void construct_amount_screen(lv_fragment_t *fragment, void *args)
{
    amount_instance *self = (amount_instance *) fragment;
    self->config = *((amount_config *) args);
    self->value = self->config.initial_value;
}

void format_value(uint64_t value, char *msg, size_t sz)
{
    char buffer[30];
    buffer[sizeof(buffer) - 1] = '\0';
    int idx = sizeof(buffer) - 2;
    int count;
    for (count = 2; count > 0; count--, idx--) {
        buffer[idx] = (char) (value % 10 + '0');
        value /= 10L;
    }
    buffer[idx--] = ',';
    buffer[idx--] = (char) (value % 10 + '0');
    value /= 10L;
    int digits = 1;
    while (value) {
        if (!(digits % 3))
            buffer[idx--] = '.';
        buffer[idx--] = (char) (value % 10 + '0');
        value /= 10L;
        digits++;
    }
    fw_strcpy_s(msg, sz, buffer + idx + 1);
}

static void update(amount_instance *self)
{
    char text[40] = "R$ ";
    format_value(self->value, text + strlen(text), sizeof(text) - strlen(text));
    lv_label_set_text(self->value_label, text);
}

static void on_key_pressed(lv_event_t *e)
{
    amount_instance *self = (amount_instance *) e->user_data;
    uint32_t key = lv_indev_get_key(lv_indev_get_act());
    if (key >= '0' && key <= '9') {
        unsigned long value = self->value * 10 + (key - '0');
        if (value < 1e12)
            self->value = value;
        update(self);
    } else if (key == KEY_BACK) {
        self->value /= 10;
        update(self);
    } else if (key == KEY_CANCEL) {
        self->config.on_cancel_clicked();
    } else if (key == KEY_ENTER) {
        self->config.on_result(self->value);
    }
}

static lv_obj_t *create_amount_screen(lv_fragment_t *fragment, lv_obj_t *parent)
{
    amount_instance *self = (amount_instance *) fragment;

    lv_obj_t *body = body_create(parent);

    lv_obj_t *title = lv_label_create(body);
    lv_label_set_text(title, self->config.title);
    lv_obj_add_style(title, xlarge_text_style(), LV_STATE_DEFAULT);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 21);

    lv_obj_t *message = lv_label_create(body);
    lv_label_set_text(message, "Digite o valor:");
    lv_obj_add_style(message, large_text_style(), LV_STATE_DEFAULT);
    lv_obj_align(message, LV_ALIGN_TOP_MID, 0, 70);

    self->value_label = lv_label_create(body);
    lv_obj_add_style(self->value_label, xxlarge_text_style(), LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(self->value_label, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
    lv_obj_set_width(self->value_label, MESSAGE_WIDTH);
    lv_obj_set_style_text_color(self->value_label, PRIMARY_DARK_COLOR, LV_STATE_DEFAULT);
    lv_obj_align(self->value_label, LV_ALIGN_TOP_MID, 0, 100);

    lv_obj_t *merchant = lv_label_create(body);
    lv_label_set_text(merchant, self->config.merchant_name);
    lv_obj_add_style(merchant, small_text_style(), LV_STATE_DEFAULT);
    lv_obj_align(merchant, LV_ALIGN_BOTTOM_MID, 0, -30);

    lv_obj_t *document = lv_label_create(body);
    lv_label_set_text(document, self->config.document);
    lv_obj_add_style(document, small_text_style(), LV_STATE_DEFAULT);
    lv_obj_align(document, LV_ALIGN_BOTTOM_MID, 0, -14);

    lv_obj_add_event_cb(body, on_key_pressed, LV_EVENT_KEY, self);
    update(self);
    return body;
}
