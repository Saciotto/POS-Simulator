#include "views.h"

#include "assets.h"
#include "components.h"
#include "dimensions.h"
#include "framework.h"
#include "gui.h"
#include "theme.h"

#include <stdio.h>

#define GROUPS_SEPARATION 10
#define SEPARATOR_PADDING 20
#define ICON_WIDTH        30

static void construct_menu_screen(lv_fragment_t *fragment, void *args);
static void destruct_menu_screen(lv_fragment_t *fragment);
static lv_obj_t *create_menu_screen(lv_fragment_t *fragment, lv_obj_t *parent);

typedef void (*on_clicked_cb)();

typedef struct {
    char *label;
    const lv_img_dsc_t *icon;
    on_clicked_cb on_clicked;
    int shortcut;
} menu_option_priv;

typedef struct {
    menu_option_priv *options;
    size_t no_options;
} menu_group_priv;

typedef struct {
    char *title;
    menu_group_priv *groups;
    size_t no_groups;
    bool icons_enabled;
    on_clicked_cb on_shortcut_clicked[9];
    lv_group_t *navigation_group;
    void (*on_back_clicked)();
    void (*on_cancel_clicked)();
} menu_config_priv;

typedef struct {
    lv_fragment_t base;
    menu_config_priv config;
} menu_instance;

const lv_fragment_class_t menu_screen = {
    .constructor_cb = construct_menu_screen,
    .create_obj_cb = create_menu_screen,
    .destructor_cb = destruct_menu_screen,
    .instance_size = sizeof(menu_instance)
};

static void on_menu_clicked(lv_event_t *e)
{
    on_clicked_cb option_clicked_cb = (on_clicked_cb) e->user_data;
    if (option_clicked_cb != NULL)
        option_clicked_cb();
}

static void on_key_pressed(lv_event_t *e)
{
    menu_config_priv *config = (menu_config_priv *) e->user_data;
    uint32_t key = lv_indev_get_key(lv_indev_get_act());
    if (key >= '1' && key <= '9') {
        key -= '1';
        if (config->on_shortcut_clicked[key] != NULL)
            config->on_shortcut_clicked[key]();
        return;
    } else if (key == KEY_PREVIOUS) {
        lv_group_focus_prev(config->navigation_group);
    } else if (key == KEY_NEXT) {
        lv_group_focus_next(config->navigation_group);
    } else if (key == KEY_ENTER) {
        lv_obj_t *obj = lv_group_get_focused(config->navigation_group);
        lv_event_send(obj, LV_EVENT_CLICKED, NULL);
    } else if (key == KEY_BACK) {
        if (config->on_back_clicked)
            config->on_back_clicked();
    } else if (key == KEY_CANCEL) {
        if (config->on_cancel_clicked)
            config->on_cancel_clicked();
    }
}

static void construct_menu_screen(lv_fragment_t *fragment, void *args)
{
    const menu_config *orig = (menu_config *) args;
    menu_config_priv *config = &((menu_instance *) fragment)->config;
    memset(config, 0, sizeof(*config));
    int count = 0;

    config->on_back_clicked = orig->on_back_clicked;
    config->on_cancel_clicked = orig->on_cancel_clicked;
    config->icons_enabled = false;
    config->title = fw_strdup(orig->title);
    config->no_groups = orig->no_groups;
    config->groups = calloc(config->no_groups, sizeof(*config->groups));
    int g_id, o_id;
    for (g_id = 0; g_id < config->no_groups; g_id++) {
        const menu_group *orig_group = &orig->groups[g_id];
        menu_group_priv *group = &config->groups[g_id];
        group->no_options = orig_group->no_options;
        group->options = calloc(group->no_options, sizeof(*group->options));
        for (o_id = 0; o_id < group->no_options; o_id++) {
            const menu_option *orig_option = &orig_group->options[o_id];
            menu_option_priv *option = &group->options[o_id];
            option->label = fw_strdup(orig_option->label);
            option->icon = get_icon(orig_option->icon);
            if (option->icon != NULL)
                config->icons_enabled = true;
            option->on_clicked = orig_option->on_clicked;
            if (count < 9) {
                option->shortcut = count + 1;
                config->on_shortcut_clicked[count++] = option->on_clicked;
            }
        }
    }
    config->navigation_group = lv_group_create();
}

static void destruct_menu_screen(lv_fragment_t *fragment)
{
    menu_config_priv *config = &((menu_instance *) fragment)->config;
    int g_id, o_id;
    for (g_id = 0; g_id < config->no_groups; g_id++) {
        menu_group_priv *group = &config->groups[g_id];
        for (o_id = 0; o_id < group->no_options; o_id++) {
            menu_option_priv *option = &group->options[o_id];
            free(option->label);
        }
        free(group->options);
    }
    free(config->title);
    free(config->groups);
    lv_group_del(config->navigation_group);
}

static lv_obj_t *create_menu_screen(lv_fragment_t *fragment, lv_obj_t *parent)
{
    menu_instance *self = (menu_instance *) fragment;
    menu_config_priv *config = &self->config;

    lv_obj_t *body = body_create(parent);
    lv_obj_t *title = NULL;
    lv_obj_t *previous_container = NULL;

    if (config->title != NULL) {
        title = title_bar_create(body, config->title);
        previous_container = title;
    }

    int vertical_margin = 0;
    int group_idx, option_idx;
    for (group_idx = 0; group_idx < config->no_groups; group_idx++) {
        const menu_group_priv *group = &config->groups[group_idx];

        lv_obj_t *menu_area = lv_obj_create(body);
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

        lv_obj_t *previous_obj = NULL;
        for (option_idx = 0; option_idx < group->no_options; option_idx++) {
            const menu_option_priv *option = &group->options[option_idx];

            lv_obj_t *button = lv_btn_create(menu_area);
            lv_obj_remove_style_all(button);
            lv_obj_add_style(button, menu_item_style(), LV_STATE_DEFAULT);
            lv_obj_add_style(button, pressed_style(), LV_STATE_PRESSED);
            lv_obj_add_style(button, focused_style(), LV_STATE_FOCUSED);
            lv_group_add_obj(config->navigation_group, button);

            if (previous_obj == NULL) {
                lv_obj_align(button, LV_ALIGN_TOP_LEFT, 0, 0);
            } else {
                lv_obj_t *separator = lv_obj_create(menu_area);
                lv_obj_remove_style_all(separator);
                lv_obj_add_style(separator, menu_separator_style(), LV_STATE_DEFAULT);
                lv_obj_set_width(separator, separator_width);
                lv_obj_set_height(separator, 1);
                lv_obj_align_to(separator, previous_obj, LV_ALIGN_OUT_BOTTOM_LEFT, SEPARATOR_PADDING, 0);
                lv_obj_align_to(button, separator, LV_ALIGN_OUT_BOTTOM_LEFT, -SEPARATOR_PADDING, 0);
            }
            lv_obj_set_width(button, button_width);
            lv_obj_add_event_cb(button, on_menu_clicked, LV_EVENT_CLICKED, option->on_clicked);

            if (config->icons_enabled && option->icon != NULL) {
                lv_obj_t *icon_area = lv_obj_create(button);
                lv_obj_remove_style_all(icon_area);
                lv_obj_align(icon_area, LV_ALIGN_LEFT_MID, 0, 0);
                lv_obj_set_width(icon_area, ICON_WIDTH);
                lv_obj_set_height(icon_area, LV_SIZE_CONTENT);

                lv_obj_t *icon = lv_img_create(icon_area);
                lv_img_set_src(icon, option->icon);
                lv_color_t color = TEXT_COLOR;
                lv_obj_set_style_img_recolor(icon, color, LV_STATE_DEFAULT);
                lv_obj_set_style_img_recolor_opa(icon, LV_OPA_COVER, LV_STATE_DEFAULT);
                lv_obj_align(icon, LV_ALIGN_CENTER, 0, 0);
            }

            lv_obj_t *label = lv_label_create(button);
            lv_label_set_text(label, option->label);
            lv_coord_t label_offset = config->icons_enabled ? ICON_WIDTH : 0;
            lv_obj_align(label, LV_ALIGN_LEFT_MID, label_offset, 0);
            lv_obj_add_style(label, regular_text_style(), 0);

            if (option->shortcut != 0) {
                lv_obj_t *shortcut_label = lv_label_create(button);
                char shortcut[20];
                snprintf(shortcut, sizeof(shortcut), "(%d)", option->shortcut);
                lv_label_set_text(shortcut_label, shortcut);
                lv_obj_align(shortcut_label, LV_ALIGN_RIGHT_MID, 0, 0);
                lv_obj_add_style(shortcut_label, regular_text_style(), 0);
            }
            previous_obj = button;
        }
        vertical_margin = GROUPS_SEPARATION;
        previous_container = menu_area;
    }

    lv_obj_add_event_cb(body, on_key_pressed, LV_EVENT_KEY, config);
    lv_obj_set_scrollbar_mode(body, LV_SCROLLBAR_MODE_AUTO);
    lv_obj_set_scroll_snap_y(body, LV_SCROLL_SNAP_NONE);
    return body;
}
