cmake_minimum_required(VERSION 3.16)

project(POS-Simulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(simulator
    source/main.cpp
)

qt_add_qml_module(simulator
    URI POS-Simulator
    VERSION 1.0
    QML_FILES
        "views/SimulatorView.qml"
        "views/components/D200.qml"
        "views/components/InvisibleButton.qml"
    RESOURCES
        "assets/images/D200.png"
)

set_target_properties(simulator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER saciotto.com.br
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(simulator
    PRIVATE Qt6::Quick)

install(TARGETS simulator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
