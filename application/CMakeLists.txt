include(SetQtResources)

pos_add_executable(application
    # Sources
    src/controllers/idle.c
    src/controllers/in_progress.c
    src/controllers/main_menu.c
    src/main.c

    # Headers
    src/controllers.h

    # Resources
    ${SIMULATOR_RESOURCES}
)

target_link_libraries(application PUBLIC
    Framework::Framework 
    Gui::Gui
)

target_include_directories(application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(SetQtAppProperties)
