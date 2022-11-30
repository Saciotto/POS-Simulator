#include "controllers.h"

#include "gui.h"

static void on_transction_amount_inserted(uint64_t value);

static const amount_config screen_config_base = {
    .on_back_clicked = close_screen,
    .on_cancel_clicked = close_to_idle,
    .on_result = on_transction_amount_inserted,
    .initial_value = 0,
    .title = "Venda",
    .document = "CNPJ: 12.345.678/0009-10",
    .merchant_name = "Pizzaria Forno à Lenha"
};

static void on_transction_amount_inserted(unsigned long value)
{
    lv_fragment_t *fragment = payment_type_menu_create();
    inflate_screen(fragment);
}

lv_fragment_t *trans_amount_create(uint64_t intial_value)
{
    amount_config config = screen_config_base;
    config.initial_value = intial_value;
    return lv_fragment_create(&amount_screen, (void *) &config);
}
