cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)  # Enable automatic moc processing
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Set the project name
project(SimpleCalculator LANGUAGES CXX)

# Find Qt5 libraries
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(SimpleCalculator main.cpp Calculator.cpp TextEditor.cpp)

# Link Qt5 libraries
target_link_libraries(SimpleCalculator Qt5::Widgets)

# If on Windows, and Release mode, copy dependencies and the
# Qt platform plugin to the build directory.
if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
    include(cmake/CopyWinPlatformPlugin.cmake)
    
    # Ensure the copy happens after the main build
    add_dependencies(${PROJECT_NAME} copy_qt_plugin)
    
    # Post-build step: Copy all mingw64 dependencies to the build folder
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -DEXEC_PATH=$<TARGET_FILE:SimpleCalculator>
                                    -DDEST_DIR=$<TARGET_FILE_DIR:SimpleCalculator>
                                    -P ${CMAKE_SOURCE_DIR}/cmake/CopyQtDependencies.cmake
        COMMENT "Running ldd and copying necessary dlls..."
    )
endif()
