#include "framework.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "gui.h"

#include "lvgl.h"

#define BUTTON_WIDTH 125

static void construct_idle_scren(lv_fragment_t* self, void* args);
static lv_obj_t* create_idle_screen(lv_fragment_t* self, lv_obj_t* parent);

typedef struct {
    lv_fragment_t base;
    idle_screen_data data;
} idle_instance;

const lv_fragment_class_t idle_screen = {
    .constructor_cb = construct_idle_scren,
    .create_obj_cb = create_idle_screen,
    .instance_size = sizeof(idle_instance)
};

static void menu_clicked(lv_event_t* e)
{
    idle_instance* self = (idle_instance*) e->user_data;
    if (self->data.on_menu_clicked != NULL)
        self->data.on_menu_clicked();
}

static void shortcut_clicked(lv_event_t* e)
{
    idle_instance* self = (idle_instance*) e->user_data;
    if (self->data.on_shortcut_clicked != NULL)
        self->data.on_shortcut_clicked();
}

static void construct_idle_scren(lv_fragment_t* fragment, void* args)
{
    ((idle_instance*) fragment)->data = *((idle_screen_data*) args);
}

static lv_obj_t *idle_button_create(lv_obj_t* parent, const char *message)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, BACKGROUND_COLOR);
    lv_style_set_border_color(&style, PRIMARY_COLOR);
    lv_style_set_text_color(&style, TEXT_COLOR);
    lv_style_set_border_width(&style, 2);
    lv_style_set_radius(&style, 20);

    lv_obj_t* btn = lv_btn_create(parent);
    lv_obj_set_width(btn, BUTTON_WIDTH);
    lv_obj_add_style(btn, &style, 0);

    lv_obj_t* label = lv_label_create(btn);
    lv_label_set_text(label, message);
    lv_obj_center(label);
    return btn;
}

static lv_obj_t* create_idle_screen(lv_fragment_t* self, lv_obj_t* parent)
{
    // Create body
    lv_obj_t* body = body_create(parent);

    // Create logo
    lv_obj_t* logo = lv_img_create(body);
    lv_img_set_src(logo, &img_logo);
    lv_color_t color = PRIMARY_COLOR;
    lv_obj_set_style_img_recolor(logo, color, 0);
    lv_obj_set_style_img_recolor_opa(logo, LV_OPA_COVER, 0);
    lv_obj_align(logo, LV_ALIGN_CENTER, 0, -30);

    // Create message
    static lv_style_t msg_style;
    lv_style_init(&msg_style);
    lv_style_set_text_font(&msg_style, &font_roboto_18);
    lv_obj_t* msg = lv_label_create(body);
    lv_obj_add_style(msg, &msg_style, 0);
    lv_label_set_text(msg, "Digite o valor, insira ou passe o cartão");
    lv_obj_set_style_text_align(msg, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(msg, SCREEN_WIDTH - 10);
    lv_obj_align_to(msg, logo, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    // F1
    lv_obj_t* btn_menu = idle_button_create(body, "F1 - Menu");
    lv_obj_add_event_cb(btn_menu, menu_clicked, LV_EVENT_CLICKED, self);
    lv_obj_align(btn_menu, LV_ALIGN_BOTTOM_LEFT, 6, -6);

    // F2
    lv_obj_t* btn_shortcut = idle_button_create(body, "F2 - Atalhos");
    lv_obj_add_event_cb(btn_shortcut, shortcut_clicked, LV_EVENT_CLICKED, self);
    lv_obj_align(btn_shortcut, LV_ALIGN_BOTTOM_RIGHT, -6, -6);
    
    return body;
}
