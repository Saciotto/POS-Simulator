#include "framework.h"

#include "gui.h"
#include "gui_assets.h"
#include "gui_dimensions.h"
#include "gui_theme.h"

#include "lvgl.h"

#define BUTTON_WIDTH (GUI_SCREEN_WIDTH - 20)
#define TITLE_HEIGHT 50

static void construct_menu_screen(lv_fragment_t* fragment, void* args);
static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent);

typedef struct {
    lv_fragment_t base;
    gui_menu data;
} menu_screen;

const lv_fragment_class_t gui_menu_screen = {
    .constructor_cb = construct_menu_screen,
    .create_obj_cb = create_menu_screen,
    .instance_size = sizeof(menu_screen)
};

static void f1_clicked(lv_event_t* e)
{
    gui_close_screen();
}

static void construct_menu_screen(lv_fragment_t* fragment, void* args)
{
    ((menu_screen*) fragment)->data = *((gui_menu*) args);
}

static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent)
{
    menu_screen* self = (menu_screen*) fragment;

    // Create body
    lv_obj_t* body = lv_obj_create(parent);
    lv_obj_remove_style_all(body);
    lv_obj_set_style_bg_opa(body, LV_OPA_100, 0);
    lv_obj_set_size(body, GUI_SCREEN_WIDTH, GUI_SCREEN_HEIGHT - GUI_STATUS_BAR_HEIGHT);

    // Create title
    lv_obj_t* title = lv_obj_create(body);
    lv_obj_remove_style_all(title);
    lv_obj_set_style_bg_opa(title, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(title, PRIMARY_COLOR, 0);
    lv_obj_set_size(title, GUI_SCREEN_WIDTH, TITLE_HEIGHT);
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_t* label = lv_label_create(title);
    lv_label_set_text(label, self->data.title);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 22, 0);
    lv_obj_add_style(label, gui_menu_title_style(), 0);

    // Create buttons
    const gui_menu_option *option;
    lv_obj_t* previous_obj = title;
    lv_coord_t padding = (GUI_SCREEN_WIDTH - BUTTON_WIDTH) / 2;

    for (option = self->data.options; option != NULL && option->label != NULL; option++) {
        lv_obj_t* button = lv_btn_create(body);
        lv_obj_align_to(button, previous_obj, LV_ALIGN_OUT_BOTTOM_LEFT, padding, 6);
        lv_obj_set_width(button, BUTTON_WIDTH);
        lv_obj_add_event_cb(button, f1_clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_t* label = lv_label_create(button);
        lv_label_set_text(label, option->label);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
        lv_obj_add_style(label, gui_menu_label_style(), 0);
        previous_obj = button;
        padding = 0;
    }
    

    return body;
}

