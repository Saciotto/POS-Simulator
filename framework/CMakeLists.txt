find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

set(CMAKE_AUTOMOC ON)

qt_add_library(framework STATIC
    # Sources
    src/fw_string.c
    src/fw_time.c 
    src/fw_timestamp.c 

    # Headers
    include/framework.h 
    include/fw_battery.h 
    include/fw_cellular.h 
    include/fw_log.h 
    include/fw_lvgl.h 
    include/fw_string.h 
    include/fw_thread.h 
    include/fw_time.h 
    include/fw_timestamp.h 
    include/fw_wifi.h

    # Sources
    src/simulator/api/binding.cpp
    src/simulator/api/platf_battery.cpp 
    src/simulator/api/platf_cellular.cpp 
    src/simulator/api/platf_log.cpp   
    src/simulator/api/platf_lvgl_driver.cpp 
    src/simulator/api/platf_lvgl.cpp 
    src/simulator/api/platf_thread.cpp 
    src/simulator/api/platf_time.cpp 
    src/simulator/api/platf_timestamp.cpp 
    src/simulator/api/platf_wifi.cpp
    src/simulator/components/display.cpp 
    src/simulator/controllers/application_controller.cpp 
    src/simulator/controllers/display_controller.cpp 
    src/simulator/controllers/keypad_controller.cpp 
    src/simulator/controllers/pos_controller.cpp 
    src/simulator/controllers/touchscreen_controller.cpp
    src/simulator/main.cpp
    
    # Headers
    src/simulator/api/binding.hpp 
    src/simulator/api/lv_conf.h 
    src/simulator/api/platf_lvgl_driver.h
    src/simulator/components/display.hpp  
    src/simulator/controllers/application_controller.hpp 
    src/simulator/controllers/display_controller.hpp 
    src/simulator/controllers/keypad_controller.hpp 
    src/simulator/controllers/pos_controller.hpp 
    src/simulator/controllers/touchscreen_controller.hpp 
)

target_include_directories(framework
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(framework PUBLIC lvgl::lvgl)

add_subdirectory(src/simulator)

add_library(Framework::Framework ALIAS framework)
