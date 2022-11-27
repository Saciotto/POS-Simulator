
pos_add_library(gui STATIC
    # Sources
    src/engine.c

    # Headers
    include/gui.h 
    include/engine.h 
    include/menu.h 
    include/status_bar.h 
    include/theme.h 
    include/views.h 
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
