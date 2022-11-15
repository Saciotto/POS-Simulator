set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

function(pos_add_executable)
    qt_add_executable(${ARGV})
endfunction()

function(pos_add_library)
    qt_add_library(${ARGV})
endfunction()
