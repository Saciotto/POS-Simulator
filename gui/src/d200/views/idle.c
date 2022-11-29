#include "views.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "framework.h"
#include "gui.h"
#include "theme.h"

#define BUTTON_WIDTH            125
#define BUTTON_MARGIN           6
#define IDLE_MESSAGE_WIDTH      (SCREEN_WIDTH - 10)
#define IDLE_MESSAGE_TOP_MARGIN 10
#define LOGO_VERTICAL_OFFSET    -30

static void construct_idle_screen(lv_fragment_t *self, void *args);
static lv_obj_t *create_idle_screen(lv_fragment_t *self, lv_obj_t *parent);

typedef struct {
    lv_fragment_t base;
    idle_screen_config config;
} idle_instance;

const lv_fragment_class_t idle_screen = {
    .constructor_cb = construct_idle_screen,
    .create_obj_cb = create_idle_screen,
    .instance_size = sizeof(idle_instance)
};

static void menu_clicked(lv_event_t *e)
{
    idle_instance *self = (idle_instance *) e->user_data;
    if (self->config.on_menu_clicked != NULL)
        self->config.on_menu_clicked();
}

static void shortcut_clicked(lv_event_t *e)
{
    idle_instance *self = (idle_instance *) e->user_data;
    if (self->config.on_shortcut_clicked != NULL)
        self->config.on_shortcut_clicked();
}

static void on_key_pressed(lv_event_t *e)
{
    idle_instance *self = (idle_instance *) e->user_data;
    uint32_t key = lv_indev_get_key(lv_indev_get_act());
    if (key > '0' && key < '9') {
        int value = key - '0';
        self->config.on_numpad_clicked(value);
    }
    if (key == KEY_MAIN_MENU) {
        menu_clicked(e);
    } else if (key == KEY_SHORTCUT) {
        shortcut_clicked(e);
    }
}

static void construct_idle_screen(lv_fragment_t *fragment, void *args)
{
    ((idle_instance *) fragment)->config = *((idle_screen_config *) args);
}

static lv_obj_t *idle_button_create(lv_obj_t *parent, const char *message)
{
    lv_obj_t *btn = lv_btn_create(parent);
    lv_obj_add_style(btn, button_style(), LV_STATE_DEFAULT);
    lv_obj_add_style(btn, pressed_style(), LV_STATE_PRESSED);
    lv_obj_set_width(btn, BUTTON_WIDTH);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, message);
    lv_obj_center(label);
    return btn;
}

static lv_obj_t *create_idle_screen(lv_fragment_t *self, lv_obj_t *parent)
{
    // Create body
    lv_obj_t *body = body_create(parent);

    // Create logo
    lv_obj_t *logo = lv_img_create(body);
    lv_img_set_src(logo, &img_logo);
    lv_color_t color = PRIMARY_COLOR;
    lv_obj_set_style_img_recolor(logo, color, LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(logo, LV_OPA_COVER, LV_STATE_DEFAULT);
    lv_obj_align(logo, LV_ALIGN_CENTER, 0, LOGO_VERTICAL_OFFSET);

    // Create message
    lv_obj_t *msg = lv_label_create(body);
    lv_label_set_text(msg, "Digite o valor, insira ou passe o cartão");
    lv_obj_add_style(msg, large_text_style(), LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(msg, LV_TEXT_ALIGN_CENTER, LV_STATE_DEFAULT);
    lv_obj_set_width(msg, IDLE_MESSAGE_WIDTH);
    lv_obj_align_to(msg, logo, LV_ALIGN_OUT_BOTTOM_MID, 0, IDLE_MESSAGE_TOP_MARGIN);

    // F1
    lv_obj_t *btn_menu = idle_button_create(body, "F1 - Menu");
    lv_obj_add_event_cb(btn_menu, menu_clicked, LV_EVENT_CLICKED, self);
    lv_obj_align(btn_menu, LV_ALIGN_BOTTOM_LEFT, BUTTON_MARGIN, -BUTTON_MARGIN);

    // F2
    lv_obj_t *btn_shortcut = idle_button_create(body, "F2 - Atalhos");
    lv_obj_add_event_cb(btn_shortcut, shortcut_clicked, LV_EVENT_CLICKED, self);
    lv_obj_align(btn_shortcut, LV_ALIGN_BOTTOM_RIGHT, -BUTTON_MARGIN, -BUTTON_MARGIN);

    lv_obj_add_event_cb(body, on_key_pressed, LV_EVENT_KEY, self);
    return body;
}
