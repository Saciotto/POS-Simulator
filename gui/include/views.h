#ifndef GUI_VIEWS_H
#define GUI_VIEWS_H

#include "engine.h"

// Idle view

typedef struct {
    void (*on_menu_clicked)();
    void (*on_shortcut_clicked)();
} idle_screen_data;

extern const lv_fragment_class_t idle_screen;

// Menu view

typedef struct {
    const char *label;
    void (*on_clicked)();
} menu_option;

typedef struct {
    const char *title;
    const menu_option *options;
} menu_data;

extern const lv_fragment_class_t menu_screen;

#endif // GUI_VIEWS_H
