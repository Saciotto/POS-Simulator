set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

#qt_add_resources(RESOURCES
#    assets.qrc 
#    components.qrc 
#    skins.qrc 
#    views.qrc
#)

#target_sources(framework PRIVATE 
    ## Sources
    #api/binding.cpp
    #api/platf_battery.cpp 
    #api/platf_cellular.cpp 
    #api/platf_log.cpp   
    #api/platf_lvgl_driver.cpp 
    #api/platf_lvgl.cpp 
    #api/platf_thread.cpp 
    #api/platf_time.cpp 
    #api/platf_timestamp.cpp 
    #api/platf_wifi.cpp
    #components/display.cpp 
    #controllers/application_controller.cpp 
    #controllers/display_controller.cpp 
    #controllers/keypad_controller.cpp 
    #controllers/pos_controller.cpp 
    #controllers/touchscreen_controller.cpp 
    #
    ## Headers
    #api/binding.hpp 
    #api/lv_conf.h 
    #api/platf_lvgl_driver.h
    #components/display.hpp  
    #controllers/application_controller.hpp 
    #controllers/display_controller.hpp 
    #controllers/keypad_controller.hpp 
    #controllers/pos_controller.hpp 
    #controllers/touchscreen_controller.hpp 

    # Resources
    #${RESOURCES}
#)

target_include_directories(framework PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(framework PRIVATE Qt6::Quick)

set(QML_IMPORT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "/" FORCE)
