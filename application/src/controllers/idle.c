#include "idle.h"

#include "gui.h"

#define SIZE_OF_LIST(x) (sizeof(x) / sizeof(x[0]))

static void on_menu_clicked();
static void on_shortcut_clicked();

static const idle_screen_data idle_data = {
    .on_menu_clicked = on_menu_clicked,
    .on_shortcut_clicked = on_shortcut_clicked
};

static const menu_option financial_options[] = {
    { "Estorno", ICON_UNDO, NULL },
    { "Pré-autorização", ICON_HOTEL, NULL },
    { "Recarga de celular", ICON_PHONE, NULL },
    { "Venda sem cartão", ICON_NO_CARD, NULL },
};

static const menu_option printer_options[] = {
    { "Reimpressão", ICON_RECEIPT, NULL },
    { "Relatório de vendas", ICON_DOLLAR, NULL }
};

static const menu_option configuration_options[] = {
    { "Wi-Fi", ICON_WIFI, NULL },
    { "Brilho", ICON_BRIGHTNESS, NULL },
    { "Configurações", ICON_GEAR, NULL }
};

static const menu_group main_menu_group[] = {
    { financial_options, SIZE_OF_LIST(financial_options) },
    { printer_options, SIZE_OF_LIST(printer_options) },
    { configuration_options, SIZE_OF_LIST(configuration_options) },
};

static const menu_data main_menu = {
    .title = NULL,
    .groups = main_menu_group,
    .no_groups = SIZE_OF_LIST(main_menu_group)
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
