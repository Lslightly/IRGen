project(SysYCompiler)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -g -pedantic")

# include generated files in project environment
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ASTBuilder)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ASTPrinter)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ErrorReporter)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/Grammar)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/SysYFIR)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/SysYFBuilder)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/ASTBuilder)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/ASTPrinter)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/ErrorReporter)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/Grammar)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/SysYFIR)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/SysYFBuilder)

add_executable(
  SysYFCompiler
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(
  SysYFCompiler
  SysYFBuilder
  IRLib
  Driver
  ASTPrinter
  ErrReporter
)
