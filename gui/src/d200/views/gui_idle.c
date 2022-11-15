#include "framework.h"

#include "gui.h"
#include "gui_assets.h"
#include "gui_dimensions.h"

#include "lvgl.h"

extern void on_menu_clicked();
extern void on_shortcut_clicked();

#define BUTTON_WIDTH 100

static void construct_idle_scren(lv_fragment_t* self, void* args);
static lv_obj_t* create_idle_screen(lv_fragment_t* self, lv_obj_t* parent);

typedef struct {
    lv_fragment_t base;
} idle_screen;

const lv_fragment_class_t gui_idle_screen = {
    .constructor_cb = construct_idle_scren,
    .create_obj_cb = create_idle_screen,
    .instance_size = sizeof(idle_screen)
};

static void menu_clicked(lv_event_t* e)
{
    on_menu_clicked();
}

static void shortcut_clicked(lv_event_t* e)
{
    on_shortcut_clicked();
}

static void construct_idle_scren(lv_fragment_t* self, void* args)
{
    (void) self;
    (void) args;
}

static lv_obj_t* create_idle_screen(lv_fragment_t* self, lv_obj_t* parent)
{
    (void) self;

    // Create body
    lv_obj_t* body = lv_obj_create(parent);
    lv_obj_remove_style_all(body);
    lv_obj_set_style_bg_opa(body, LV_OPA_100, 0);
    lv_obj_set_size(body, GUI_SCREEN_WIDTH, GUI_SCREEN_HEIGHT - GUI_STATUS_BAR_HEIGHT);

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
    lv_obj_set_width(msg, GUI_SCREEN_WIDTH - 10);
    lv_obj_align_to(msg, logo, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);

    // F1
    lv_obj_t* btn_menu = lv_btn_create(body);
    lv_obj_align(btn_menu, LV_ALIGN_BOTTOM_LEFT, 6, -6);
    lv_obj_set_width(btn_menu, BUTTON_WIDTH);
    lv_obj_add_event_cb(btn_menu, menu_clicked, LV_EVENT_CLICKED, NULL);
    lv_obj_t* f1_label = lv_label_create(btn_menu);
    lv_label_set_text(f1_label, "F1 - Menu");
    lv_obj_center(f1_label);

    // F2
    lv_obj_t* btn_f2 = lv_btn_create(body);
    lv_obj_align(btn_f2, LV_ALIGN_BOTTOM_RIGHT, -6, -6);
    lv_obj_set_width(btn_f2, BUTTON_WIDTH);
    lv_obj_add_event_cb(btn_f2, shortcut_clicked, LV_EVENT_CLICKED, NULL);
    lv_obj_t* f2_label = lv_label_create(btn_f2);
    lv_label_set_text(f2_label, "F2 - Atalhos");
    lv_obj_center(f2_label);

    return body;
}
