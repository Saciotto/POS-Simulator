#include "framework.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "gui.h"
#include "theme.h"

#define GROUPS_SEPARATION 10
#define SEPARATOR_PADDING 20
#define ICON_WIDTH        30

static void construct_menu_screen(lv_fragment_t* fragment, void* args);
static void destruct_menu_screen(lv_fragment_t* fragment);
static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent);

typedef struct {
    char* label;
    const lv_img_dsc_t* icon;
    void (*on_clicked)();
} menu_option_priv;

typedef struct {
    menu_option_priv* options;
    size_t no_options;
} menu_group_priv;

typedef struct {
    char* title;
    menu_group_priv* groups;
    size_t no_groups;
    bool icons_enabled;
} menu_data_priv;

typedef struct {
    lv_fragment_t base;
    menu_data_priv data;
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
    const menu_data* orig = (menu_data*) args;
    menu_data_priv* self = &((menu_instance*) fragment)->data;

    self->icons_enabled = false;
    self->title = fw_strdup(orig->title);
    self->no_groups = orig->no_groups;
    self->groups = calloc(self->no_groups, sizeof(*self->groups));
    int g_id, o_id;
    for (g_id = 0; g_id < self->no_groups; g_id++) {
        const menu_group* orig_group = &orig->groups[g_id];
        menu_group_priv* group = &self->groups[g_id];
        group->no_options = orig_group->no_options;
        group->options = calloc(group->no_options, sizeof(*group->options));
        for (o_id = 0; o_id < group->no_options; o_id++) {
            const menu_option* orig_option = &orig_group->options[o_id];
            menu_option_priv* option = &group->options[o_id];
            option->label = fw_strdup(orig_option->label);
            option->icon = get_icon(orig_option->icon);
            if (option->icon != NULL)
                self->icons_enabled = true;
            option->on_clicked = orig_option->on_clicked;
        }
    }
}

static void destruct_menu_screen(lv_fragment_t* fragment)
{
    menu_data_priv* self = &((menu_instance*) fragment)->data;
    int g_id, o_id;
    for (g_id = 0; g_id < self->no_groups; g_id++) {
        menu_group_priv* group = &self->groups[g_id];
        for (o_id = 0; o_id < group->no_options; o_id++) {
            menu_option_priv* option = &group->options[o_id];
            free(option->label);
        }
        free(group->options);
    }
    free(self->title);
    free(self->groups);
}

static lv_obj_t* create_menu_screen(lv_fragment_t* fragment, lv_obj_t* parent)
{
    menu_instance* self = (menu_instance*) fragment;

    lv_obj_t* body = body_create(parent);
    lv_obj_t* title = NULL;
    lv_obj_t* previous_container = NULL;

    if (self->data.title != NULL) {
        title = title_bar_create(body, self->data.title);
        previous_container = title;
    }

    int vertical_margin = 0;
    int group_idx, option_idx;
    for (group_idx = 0; group_idx < self->data.no_groups; group_idx++) {
        const menu_group_priv* group = &self->data.groups[group_idx];

        lv_obj_t* menu_area = lv_obj_create(body);
        lv_obj_remove_style_all(menu_area);
        lv_obj_add_style(menu_area, menu_container_style(), LV_STATE_DEFAULT);
        if (previous_container != NULL)
            lv_obj_align_to(menu_area, previous_container, LV_ALIGN_OUT_BOTTOM_LEFT, 0, vertical_margin);
        else
            lv_obj_align(menu_area, LV_ALIGN_TOP_LEFT, 0, GROUPS_SEPARATION);
        lv_obj_set_width(menu_area, SCREEN_WIDTH);
        lv_obj_set_height(menu_area, LV_SIZE_CONTENT);

        lv_coord_t button_width = SCREEN_WIDTH - 2 * lv_obj_get_style_border_width(menu_area, LV_PART_MAIN);
        lv_coord_t separator_width = button_width - 2 * SEPARATOR_PADDING;

        lv_obj_t* previous_obj = NULL;
        for (option_idx = 0; option_idx < group->no_options; option_idx++) {
            const menu_option_priv* option = &group->options[option_idx];

            lv_obj_t* button = lv_btn_create(menu_area);

            lv_obj_remove_style_all(button);
            lv_obj_add_style(button, menu_item_style(), LV_STATE_DEFAULT);
            lv_obj_add_style(button, pressed_style(), LV_STATE_PRESSED);

            if (previous_obj == NULL) {
                lv_obj_align(button, LV_ALIGN_TOP_LEFT, 0, 0);
            } else {
                lv_obj_t* separator = lv_obj_create(menu_area);
                lv_obj_remove_style_all(separator);
                lv_obj_add_style(separator, menu_separator_style(), LV_STATE_DEFAULT);
                lv_obj_set_width(separator, separator_width);
                lv_obj_set_height(separator, 1);
                lv_obj_align_to(separator, previous_obj, LV_ALIGN_OUT_BOTTOM_LEFT, SEPARATOR_PADDING, 0);
                lv_obj_align_to(button, separator, LV_ALIGN_OUT_BOTTOM_LEFT, -SEPARATOR_PADDING, 0);
            }
            lv_obj_set_width(button, button_width);
            lv_obj_add_event_cb(button, f1_clicked, LV_EVENT_CLICKED, NULL);

            if (self->data.icons_enabled && option->icon != NULL) {
                lv_obj_t* icon_area = lv_obj_create(button);
                lv_obj_remove_style_all(icon_area);
                lv_obj_align(icon_area, LV_ALIGN_LEFT_MID, 0, 0);
                lv_obj_set_width(icon_area, ICON_WIDTH);
                lv_obj_set_height(icon_area, LV_SIZE_CONTENT);

                lv_obj_t* icon = lv_img_create(icon_area);
                lv_img_set_src(icon, option->icon);
                lv_color_t color = TEXT_COLOR;
                lv_obj_set_style_img_recolor(icon, color, 0);
                lv_obj_set_style_img_recolor_opa(icon, LV_OPA_COVER, 0);
                lv_obj_align(icon, LV_ALIGN_CENTER, 0, 0);
            }

            lv_obj_t* label = lv_label_create(button);
            lv_label_set_text(label, option->label);
            lv_coord_t label_offset = self->data.icons_enabled ? ICON_WIDTH : 0;
            lv_obj_align(label, LV_ALIGN_LEFT_MID, label_offset, 0);
            lv_obj_add_style(label, regular_text_style(), 0);
            previous_obj = button;
        }
        vertical_margin = GROUPS_SEPARATION;
        previous_container = menu_area;
    }
    return body;
}
