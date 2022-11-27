include(SetQtResources)

pos_add_executable(application
    # Sources
    src/controllers/idle.c
    src/main.c

    # Headers
    src/controllers/idle.h

    # Resources
    ${SIMULATOR_RESOURCES}
)

target_link_libraries(application PUBLIC
    Framework::Framework 
    Gui::Gui
)

include(SetQtAppProperties)
