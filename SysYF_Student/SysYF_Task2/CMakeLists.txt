project(SysYF_Task2)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -g -pedantic")

set(SYSYF_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# include generated files in project environment
include_directories(${SYSYF_SOURCE_DIR}include/SysYIR)
add_subdirectory(${SYSYF_SOURCE_DIR}src/SysYIR src/SysYIR)

add_subdirectory(ta_demo)
add_subdirectory(student_cpp)
