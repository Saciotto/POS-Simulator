#ifndef APP_CONTROLLERS_H
#define APP_CONTROLLERS_H

#include "lvgl.h"

#include <stdint.h>

lv_fragment_t *idle_create();

lv_fragment_t *main_menu_create();

lv_fragment_t *payment_type_menu_create();

lv_fragment_t *in_progress_create();

lv_fragment_t *trans_amount_create(uint64_t intial_value);

#endif // APP_CONTROLLERS_H
