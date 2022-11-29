#include "controllers.h"

#include "gui.h"

#define SIZE_OF_LIST(x) (sizeof(x) / sizeof(x[0]))

static void go_in_progress_screen();

static const menu_option financial_options[] = {
    { "Estorno", ICON_UNDO, go_in_progress_screen },
    { "Pré-autorização", ICON_HOTEL, go_in_progress_screen },
    { "Recarga de celular", ICON_PHONE, go_in_progress_screen },
    { "Venda sem cartão", ICON_NO_CARD, go_in_progress_screen },
};

static const menu_option printer_options[] = {
    { "Reimpressão", ICON_RECEIPT, go_in_progress_screen },
    { "Relatório de vendas", ICON_DOLLAR, go_in_progress_screen }
};

static const menu_option configuration_options[] = {
    { "Wi-Fi", ICON_WIFI, go_in_progress_screen },
    { "Brilho", ICON_BRIGHTNESS, go_in_progress_screen },
    { "Configurações", ICON_GEAR, go_in_progress_screen }
};

static const menu_group main_menu_group[] = {
    { financial_options, SIZE_OF_LIST(financial_options) },
    { printer_options, SIZE_OF_LIST(printer_options) },
    { configuration_options, SIZE_OF_LIST(configuration_options) },
};

static const menu_config main_menu = {
    .title = NULL,
    .groups = main_menu_group,
    .no_groups = SIZE_OF_LIST(main_menu_group),
    .on_back_clicked = close_screen,
    .on_cancel_clicked = close_to_idle
};

static void go_in_progress_screen()
{
    lv_fragment_t *fragment = in_progress_create();
    inflate_screen(fragment);
}

lv_fragment_t *main_menu_create()
{
    return lv_fragment_create(&menu_screen, (void *) &main_menu);
}
