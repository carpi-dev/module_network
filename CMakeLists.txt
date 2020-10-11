cmake_minimum_required(VERSION 3.1.0)
project(network)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 11)
add_compile_definitions(NETWORK_LOADABLE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

add_library(network SHARED
        Network_global.h
        Network.cpp
        Network.h
        )

target_link_libraries(network PUBLIC Qt5::Widgets Qt5::Network)
target_compile_definitions(network PUBLIC NETWORK_LIBRARY)

install(TARGETS network
        LIBRARY DESTINATION lib/carpi)
