#include "theme.h"

#include "assets.h"

#define MENU_BORDER_SIZE             1
#define MENU_BORDER_RADIUS           20
#define MENU_ITEM_VERTICAL_PADDING   10
#define MENU_ITEM_HORIZONTAL_PADDING 20

static lv_style_t regular_text;
static lv_style_t menu_container;
static lv_style_t menu_item;
static lv_style_t menu_separator;
static lv_style_t pressed;
static lv_style_t focused;

static void set_default_theme()
{
    lv_disp_t* display = lv_disp_get_default();
    lv_theme_t* th = lv_theme_default_init(display, SECONDARY_COLOR, SECONDARY_LIGHT_COLOR, 0, &font_roboto_18);
    lv_disp_set_theme(display, th);
}

static void initialize_text()
{
    lv_style_init(&regular_text);
    lv_style_set_text_font(&regular_text, &font_roboto_14);
}

static void initialize_events_effects()
{
    lv_style_init(&pressed);
    lv_style_set_bg_color(&pressed, PRIMARY_COLOR);
    lv_style_set_bg_opa(&pressed, LV_OPA_30);

    lv_style_init(&focused);
    lv_style_set_bg_color(&focused, PRIMARY_COLOR);
    lv_style_set_bg_opa(&focused, LV_OPA_30);
}

static void initialize_menu_style()
{
    lv_style_init(&menu_container);
    lv_style_set_bg_opa(&menu_container, LV_OPA_100);
    lv_style_set_bg_color(&menu_container, ALTERNATIVE_BACKGROUND_COLOR);
    lv_style_set_radius(&menu_container, MENU_BORDER_RADIUS);
    lv_style_set_border_width(&menu_container, MENU_BORDER_SIZE);
    lv_style_set_border_color(&menu_container, lv_color_black());
    lv_style_set_border_opa(&menu_container, LV_OPA_20);
    lv_style_set_clip_corner(&menu_container, true);

    lv_style_init(&menu_item);
    lv_style_set_pad_top(&menu_item, MENU_ITEM_VERTICAL_PADDING);
    lv_style_set_pad_bottom(&menu_item, MENU_ITEM_VERTICAL_PADDING);
    lv_style_set_pad_left(&menu_item, MENU_ITEM_HORIZONTAL_PADDING);
    lv_style_set_pad_right(&menu_item, MENU_ITEM_HORIZONTAL_PADDING);

    lv_style_init(&menu_separator);
    lv_style_set_bg_opa(&menu_separator, LV_OPA_20);
    lv_style_set_bg_color(&menu_separator, lv_color_black());
}

void initialize_theme()
{
    set_default_theme();
    initialize_text();
    initialize_events_effects();
    initialize_menu_style();
}

lv_style_t* regular_text_style()
{
    return &regular_text;
}

lv_style_t* pressed_style()
{
    return &pressed;
}

lv_style_t* focused_style()
{
    return &focused;
}

lv_style_t* menu_container_style()
{
    return &menu_container;
}

lv_style_t* menu_item_style()
{
    return &menu_item;
}

lv_style_t* menu_separator_style()
{
    return &menu_separator;
}
