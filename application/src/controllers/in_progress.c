#include "controllers.h"

#include "gui.h"

static const in_progress_config screen_config = {
    .on_back_clicked = close_screen,
    .on_cancel_clicked = close_to_idle
};

lv_fragment_t *in_progress_create()
{
    return lv_fragment_create(&in_pregress_screen, (void *) &screen_config);
}
