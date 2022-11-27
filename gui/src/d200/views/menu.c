#include "framework.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "gui.h"
#include "theme.h"

#include "lvgl.h"

#define BUTTON_WIDTH (GUI_SCREEN_WIDTH - GUI_DEFAULT_PADDING * 2)

static void construct_menu_screen(lv_fragment_t* fragment, void* args);
static void destruct_menu_screen(lv_fragment_t* fragment);
static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent);

typedef struct {
    lv_fragment_t base;
    gui_menu data;
} menu_instance;

const lv_fragment_class_t menu_screen = {
    .constructor_cb = construct_menu_screen,
    .create_obj_cb = create_menu_screen,
    .destructor_cb = destruct_menu_screen,
    .instance_size = sizeof(menu_instance)
};

static void f1_clicked(lv_event_t* e)
{
    close_screen();
}

static void construct_menu_screen(lv_fragment_t* fragment, void* args)
{
    ((menu_instance*) fragment)->data = *((gui_menu*) args);
}

static void destruct_menu_screen(lv_fragment_t* fragment)
{
}

static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent)
{
    menu_instance* self = (menu_instance*) fragment;

    lv_obj_t* body = body_create(parent);
    lv_obj_t* title = title_bar_create(body, self->data.title);

    const gui_menu_option* option;
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
