#include "controllers.h"

#include "gui.h"

#define SIZE_OF_LIST(x) (sizeof(x) / sizeof(x[0]))

static void go_in_progress_screen();

static const menu_option financial_options[] = {
    { "Crédito", ICON_NONE, go_in_progress_screen },
    { "Débito", ICON_NONE, go_in_progress_screen },
    { "Voucher", ICON_NONE, go_in_progress_screen },
    { "PIX", ICON_NONE, go_in_progress_screen },
};

static const menu_group payment_groups[] = {
    { financial_options, SIZE_OF_LIST(financial_options) }
};

static const menu_config payment_menu = {
    .title = "Forma de pagamento",
    .groups = payment_groups,
    .no_groups = SIZE_OF_LIST(payment_groups),
    .on_back_clicked = close_screen,
    .on_cancel_clicked = close_to_idle
};

static void go_in_progress_screen()
{
    lv_fragment_t *fragment = in_progress_create();
    inflate_screen(fragment);
}

lv_fragment_t *payment_type_menu_create()
{
    return lv_fragment_create(&menu_screen, (void *) &payment_menu);
}
