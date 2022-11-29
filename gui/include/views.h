#ifndef GUI_VIEWS_H
#define GUI_VIEWS_H

#include "engine.h"

// Idle view

typedef struct {
    void (*on_menu_clicked)();
    void (*on_shortcut_clicked)();
    void (*on_numpad_clicked)(int number);
} idle_screen_config;

extern const lv_fragment_class_t idle_screen;

// Menu view

typedef struct {
    const char *label;
    int icon;
    void (*on_clicked)();
} menu_option;

typedef struct {
    const menu_option *options;
    size_t no_options;
} menu_group;

typedef struct {
    const char *title;
    const menu_group *groups;
    size_t no_groups;
    void (*on_back_clicked)();
    void (*on_cancel_clicked)();
} menu_config;

extern const lv_fragment_class_t menu_screen;

// In progress view

typedef struct {
    void (*on_back_clicked)();
    void (*on_cancel_clicked)();
} in_progress_config;

extern const lv_fragment_class_t in_pregress_screen;

// Amount view

typedef struct {
    unsigned long initial_value;
    void (*on_back_clicked)();
    void (*on_cancel_clicked)();
    void (*on_result)(unsigned long value);
} amount_config;

extern const lv_fragment_class_t amount_screen;

#endif // GUI_VIEWS_H
