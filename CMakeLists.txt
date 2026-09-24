cmake_minimum_required(VERSION 3.16)

project(AckermannLab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ackermann_lab
    src/main.cpp
    src/vehicle_command.cpp
)

target_include_directories(ackermann_lab PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
