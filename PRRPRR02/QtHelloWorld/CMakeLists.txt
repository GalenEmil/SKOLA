cmake_minimum_required(VERSION 3.5)
project(QtHelloWorld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(QtHelloWorld
    main.cpp
)

target_link_libraries(QtHelloWorld PRIVATE Qt5::Widgets)
