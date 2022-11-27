#include "idle.h"

#include "gui.h"

static void on_menu_clicked();
static void on_shortcut_clicked();

static const idle_screen_data idle_data = {
    .on_menu_clicked = on_menu_clicked,
    .on_shortcut_clicked = on_shortcut_clicked
};

static const menu_option main_menu_options[] = {
    { "Reimprimir", NULL },
    { "Estorno", NULL },
    { "Pré-autorização", NULL },
    { "Confirmar pré-autorização", NULL },
    { "Cancelar pré-autorização", NULL },
    { "Configurações", NULL },
    { NULL, NULL }
};

static const menu_data main_menu = {
    .title = "Título do menu",
    .options = main_menu_options
};

static void on_menu_clicked()
{
    lv_fragment_t* fragment = lv_fragment_create(&menu_screen, (void*) &main_menu);
    inflate_screen(fragment);
}

static void on_shortcut_clicked()
{
}

lv_fragment_t* idle_create()
{
    return lv_fragment_create(&idle_screen, (void*) &idle_data);
}
