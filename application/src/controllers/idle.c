#include "controllers.h"

#include "gui.h"

static void on_menu_clicked();
static void on_shortcut_clicked();
static void on_numpad_clicked(int number);

static const idle_screen_config idle_config = {
    .on_menu_clicked = on_menu_clicked,
    .on_shortcut_clicked = on_shortcut_clicked,
    .on_numpad_clicked = on_numpad_clicked
};

static void on_menu_clicked()
{
    lv_fragment_t *fragment = main_menu_create();
    inflate_screen(fragment);
}

static void on_numpad_clicked(int number)
{
    lv_fragment_t *fragment = in_progress_create();
    inflate_screen(fragment);
}

static void on_shortcut_clicked()
{
    lv_fragment_t *fragment = in_progress_create();
    inflate_screen(fragment);
}

lv_fragment_t *idle_create()
{
    return lv_fragment_create(&idle_screen, (void *) &idle_config);
}
