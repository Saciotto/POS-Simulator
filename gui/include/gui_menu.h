#ifndef GUI_MENU_H
#define GUI_MENU_H

#include <stdlib.h>

typedef struct {
    const char *label;
    void (*on_clicked)();
} gui_menu_option;

typedef struct {
    const char *title;
    const gui_menu_option *options;
} gui_menu;

#endif // GUI_MENU_H
