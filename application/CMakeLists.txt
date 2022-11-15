include(SetQtResources)

pos_add_executable(application
    # Sources
    src/controllers/ctrl_idle.c
    src/app_main.c

    # Headers
    src/controllers/ctrl_idle.h

    # Resources
    ${SIMULATOR_RESOURCES}
)

target_link_libraries(application PUBLIC
    Framework::Framework 
    Gui::Gui
)

include(SetQtAppProperties)
