cmake_minimum_required(VERSION 3.16)

project(POS-Simulator VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_resources(RESOURCES
    assets.qrc components.qrc skins.qrc views.qrc
)

qt_add_executable(simulator
    # Sources
    source/application/app_idle.c
    source/application/app_main.c
    source/components/display.cpp
    source/controllers/application_controller.cpp
    source/controllers/display_controller.cpp
    source/controllers/keypad_controller.cpp
    source/controllers/pos_controller.cpp
    source/controllers/touchscreen_controller.cpp
    source/framework/source/simulator/binding.cpp
    source/framework/source/simulator/platf_clock.cpp
    source/framework/source/simulator/platf_log.cpp
    source/framework/source/simulator/platf_lvgl_driver.cpp
    source/framework/source/simulator/platf_lvgl.cpp
    source/framework/source/simulator/platf_thread.cpp
    source/framework/source/simulator/platf_time.cpp
    source/framework/source/fw_time.c
    source/framework/source/fw_clock.c
    source/main.cpp

    # Headers
    source/application/app_idle.h
    source/components/display.hpp
    source/controllers/application_controller.hpp
    source/controllers/display_controller.hpp
    source/controllers/keypad_controller.hpp
    source/controllers/pos_controller.hpp
    source/controllers/touchscreen_controller.hpp
    source/framework/include/framework.h
    source/framework/include/fw_clock.h
    source/framework/include/fw_log.h
    source/framework/include/fw_lvgl.h
    source/framework/include/fw_thread.h
    source/framework/include/fw_time.h
    source/framework/source/simulator/binding.hpp
    source/framework/source/simulator/lv_conf.h
    source/framework/source/simulator/platf_lvgl_driver.h

    # Resources
    ${RESOURCES}
)

set_target_properties(simulator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER saciotto.com.br
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(FetchContent)
set(LV_CONF_PATH ${CMAKE_SOURCE_DIR}/source/framework/source/simulator/lv_conf.h CACHE STRING "" FORCE)
FetchContent_Declare(lvgl GIT_REPOSITORY https://github.com/lvgl/lvgl.git)
FetchContent_MakeAvailable(lvgl)

target_include_directories(simulator PRIVATE 
    "source" 
    "source/framework/include")

target_link_libraries(simulator PRIVATE
    Qt6::Quick
    lvgl::lvgl)

install(TARGETS simulator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "/" FORCE)
