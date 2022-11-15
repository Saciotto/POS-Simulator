
pos_add_library(gui STATIC
    # Sources
    src/gui_engine.c

    # Headers
    include/gui.h 
    include/gui_engine.h 
    include/gui_menu.h 
    include/gui_status_bar.h 
    include/gui_theme.h 
    include/gui_views.h 
)

target_include_directories(gui
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(gui PUBLIC 
    Framework::Framework
    lvgl::lvgl
)

add_subdirectory(src/d200)

add_library(Gui::Gui ALIAS gui)
