#ifndef GUI_COMPONENTS_H
#define GUI_COMPONENTS_H

#include "lvgl.h"

lv_obj_t* body_create(lv_obj_t* parent);
lv_obj_t* title_bar_create(lv_obj_t* parent, const char *message);

#endif // GUI_COMPONENTS_H
