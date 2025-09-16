cmake_minimum_required(VERSION 3.10.0)

project(chainsaw VERSION 1.0.2 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../install/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../install/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../install/lib)

add_subdirectory(src)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test")
    enable_testing()
    add_subdirectory(test)
ENDIF()
