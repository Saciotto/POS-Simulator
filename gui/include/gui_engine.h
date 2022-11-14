#ifndef GUI_ENGINE_H
#define GUI_ENGINE_H

#include "lvgl.h"

void gui_init_engine(lv_fragment_t* initial_screen);

void gui_inflate_screen(lv_fragment_t* screen);

void gui_close_screen();

void gui_execute_app();

#endif // GUI_ENGINE_H
