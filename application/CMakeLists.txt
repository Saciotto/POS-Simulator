find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

set(CMAKE_AUTOMOC ON)

qt_add_resources(RESOURCES
    ${CMAKE_SOURCE_DIR}/framework/src/simulator/assets.qrc 
    ${CMAKE_SOURCE_DIR}/framework/src/simulator/components.qrc 
    ${CMAKE_SOURCE_DIR}/framework/src/simulator/skins.qrc 
    ${CMAKE_SOURCE_DIR}/framework/src/simulator/views.qrc
)

qt_add_executable(application
    # Sources
    src/controllers/ctrl_idle.c
    src/app_main.c

    # Headers
    src/controllers/ctrl_idle.h

    # Resources
    ${RESOURCES}
)

target_link_libraries(application PUBLIC
    Framework::Framework 
    Gui::Gui
)

set_target_properties(application PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER saciotto.com.br
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS application BUNDLE DESTINATION . LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
