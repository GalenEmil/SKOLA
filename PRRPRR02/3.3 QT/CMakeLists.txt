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
