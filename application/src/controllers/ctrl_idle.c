#include "ctrl_idle.h"

#include "gui.h"

static const gui_menu_option main_menu_options[] = {
    {"Reimprimir", NULL},
    {"Estorno", NULL},
    {"Pré-autorização", NULL},
    {"Confirmar pré-autorização", NULL},
    {"Cancelar pré-autorização", NULL},
    {"Configurações", NULL},
    {NULL, NULL}
};

static const gui_menu main_menu = {
    .title = "Título do menu",
    .options = main_menu_options
};

void on_menu_clicked()
{
    lv_fragment_t* fragment = lv_fragment_create(&gui_menu_screen, (void*) &main_menu);
    gui_inflate_screen(fragment);
}

void on_shortcut_clicked()
{
}
