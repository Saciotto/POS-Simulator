#ifndef GUI_ENGINE_H
#define GUI_ENGINE_H

#include "lvgl.h"

void initialize_theme();

void initialize_gui_engine(lv_fragment_t *initial_screen);

void inflate_screen(lv_fragment_t *screen);

void close_screen();

void close_to_idle();

void execute_app();

void close_app();

#endif // GUI_ENGINE_H
