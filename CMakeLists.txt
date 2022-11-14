cmake_minimum_required(VERSION 3.24)

project(POS-Simulator VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

set(LV_CONF_PATH ${CMAKE_SOURCE_DIR}/framework/src/simulator/api/lv_conf.h CACHE STRING "" FORCE)
include(FetchContent)
FetchContent_Declare(lvgl 
    GIT_REPOSITORY https://github.com/lvgl/lvgl.git
    GIT_TAG 5545ffc9257808ee26eac833ec5326706cdf2007 # v8.3.3
)
FetchContent_MakeAvailable(lvgl)

add_subdirectory(framework)
add_subdirectory(gui)
add_subdirectory(application)
