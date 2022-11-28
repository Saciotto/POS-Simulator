#include "framework.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "gui.h"
#include "theme.h"

#include "lvgl.h"

#define GROUP_HORIZONTAL_PADDING 20
#define GROUP_VERTICAL_PADDING 10
#define GROUP_BORDER_WIDTH 1
#define CONTENT_WIDTH (GUI_SCREEN_WIDTH - 2 * GROUP_BORDER_WIDTH) 
#define BUTTON_WIDTH (CONTENT_WIDTH)
#define SEPARATOR_WIDTH (CONTENT_WIDTH - 2 * GROUP_HORIZONTAL_PADDING)

static void construct_menu_screen(lv_fragment_t* fragment, void* args);
static void destruct_menu_screen(lv_fragment_t* fragment);
static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent);

typedef struct {
    lv_fragment_t base;
    menu_data data;
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
    ((menu_instance*) fragment)->data = *((menu_data*) args);
}

static void destruct_menu_screen(lv_fragment_t* fragment)
{
}

static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent)
{
    menu_instance* self = (menu_instance*) fragment;

    lv_obj_t* body = body_create(parent);
    lv_obj_t* title = title_bar_create(body, self->data.title);

    lv_obj_t* menu_area = lv_obj_create(body);
    lv_obj_remove_style_all(menu_area);
    lv_obj_set_style_bg_opa(menu_area, LV_OPA_100, 0);
    lv_obj_set_style_bg_color(menu_area, ALTERNATIVE_BACKGROUND_COLOR, 0);
    lv_obj_set_style_radius(menu_area, 20, 0);
    lv_obj_set_style_border_width(menu_area, 1, 0);
    lv_obj_set_style_border_color(menu_area, TEXT_COLOR, 0);
    lv_obj_set_style_border_opa(menu_area, LV_OPA_20, 0);

    lv_obj_align_to(menu_area, title, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_width(menu_area, GUI_SCREEN_WIDTH);
    lv_obj_set_height(menu_area, LV_SIZE_CONTENT);
    lv_obj_set_style_clip_corner(menu_area, true, 0);
    lv_obj_set_style_pad_top(menu_area, 0, 0);
    lv_obj_set_style_pad_bottom(menu_area, 0, 0);
    lv_obj_set_style_pad_left(menu_area, 0, 0);
    lv_obj_set_style_pad_right(menu_area, 0, 0);
    
    const menu_option* option;
    lv_obj_t* previous_obj = NULL;

    static lv_style_t pressed;
    lv_style_init(&pressed);
    lv_style_set_bg_color(&pressed, PRIMARY_COLOR);
    lv_style_set_bg_opa(&pressed, LV_OPA_30);

    for (option = self->data.options; option != NULL && option->label != NULL; option++) {
        lv_obj_t* button = lv_btn_create(menu_area);
        lv_obj_remove_style_all(button);
        lv_obj_set_style_pad_top(button, GROUP_VERTICAL_PADDING, 0);
        lv_obj_set_style_pad_bottom(button, GROUP_VERTICAL_PADDING, 0);
        lv_obj_set_style_pad_left(button, GROUP_HORIZONTAL_PADDING, 0);
        lv_obj_set_style_pad_right(button, GROUP_HORIZONTAL_PADDING, 0);

        lv_obj_add_style(button, &pressed, LV_STATE_PRESSED);

        if (previous_obj == NULL) {
            lv_obj_align(button, LV_ALIGN_TOP_LEFT, 0, 0);
        } else { 
            lv_obj_t* separator = lv_obj_create(menu_area);
            lv_obj_set_width(separator, SEPARATOR_WIDTH);
            lv_obj_set_height(separator, 1);
            lv_obj_set_style_bg_opa(separator, LV_OPA_100, 0);
            lv_obj_set_style_bg_color(separator, TEXT_COLOR, 0);
            lv_obj_align_to(separator, previous_obj, LV_ALIGN_OUT_BOTTOM_LEFT, GROUP_HORIZONTAL_PADDING, 0);
            lv_obj_align_to(button, separator, LV_ALIGN_OUT_BOTTOM_LEFT, -GROUP_HORIZONTAL_PADDING, 0);
        }
        lv_obj_set_width(button, BUTTON_WIDTH);
        lv_obj_add_event_cb(button, f1_clicked, LV_EVENT_CLICKED, NULL);
        lv_obj_set_style_bg_color(button, lv_color_black(), LV_PART_INDICATOR | LV_STATE_FOCUSED);

        lv_obj_t* label = lv_label_create(button);
        lv_label_set_text(label, option->label);
        lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);
        lv_obj_add_style(label, gui_menu_label_style(), 0);

        previous_obj = button;
    }

    return body;
}
