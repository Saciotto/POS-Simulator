
pos_add_library(framework STATIC
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
)

target_include_directories(framework
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(framework PUBLIC lvgl::lvgl)

add_subdirectory(src/simulator)

add_library(Framework::Framework ALIAS framework)
