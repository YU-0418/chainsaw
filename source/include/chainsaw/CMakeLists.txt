cmake_minimum_required(VERSION 3.10)

project(chainsaw)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../../../build)
message(STATUS "!!CMAKE_INSTALL_PREFIX is ${CMAKE_INSTALL_PREFIX}")

set(CHAINSAW_ROOT ${PROJECT_SOURCE_DIR})
message(STATUS "!!!chainsaw_root is ${CHAINSAW_ROOT}")

# module_path
set(COMMON_PATH ${CHAINSAW_ROOT}/common)
set(ERROR_MESSAGE_PATH ${CHAINSAW_ROOT}/error_message)
set(ARGV_PATH ${CHAINSAW_ROOT}/argv)
set(HTML_PATH ${CHAINSAW_ROOT}/html)
set(MARKDOWN_PATH ${CHAINSAW_ROOT}/markdown)

set(COMMON_STRINGTOOL_PATH ${COMMON_PATH}/stringtool)

# module source file
aux_source_directory(${COMMON_PATH}/impl COMMON_MODULE)
aux_source_directory(${ERROR_MESSAGE_PATH}/impl ERROR_MESSAGE_MODULE)
aux_source_directory(${ARGV_PATH}/impl ARGV_MODULE)
aux_source_directory(${HTML_PATH}/impl HTML_MODULE)
aux_source_directory(${MARKDOWN_PATH}/impl MARKDOWN_MODULE)

aux_source_directory(${COMMON_STRINGTOOL_PATH}/impl COMMON_STRINGTOOL_MODULE)

# include directory
include_directories(${COMMON_PATH})
include_directories(${ERROR_MESSAGE_PATH})
include_directories(${ARGV_PATH})
include_directories(${HTML_PATH})
include_directories(${MARKDOWN_PATH})

include_directories(${COMMON_STRINGTOOL_PATH})

add_library(${PROJECT_NAME} 
    STATIC
    ${COMMON_MODULE}
    ${ERROR_MESSAGE_MODULE}
    ${ARGV_MODULE}
    ${HTML_MODULE}
    ${MARKDOWN_MODULE}
    ${COMMON_STRINGTOOL_MODULE}
)

install(
DIRECTORY ${CHAINSAW_ROOT}/
DESTINATION include/chainsaw
FILES_MATCHING 
#PATTERN "*.h*"
PATTERN "*"
PATTERN "impl" EXCLUDE
#PATTERN "*.cpp" EXCLUDE
PATTERN "*.bat" EXCLUDE
PATTERN "*.txt" EXCLUDE
PATTERN "cmake" EXCLUDE
)

install(FILES ${CHAINSAW_ROOT}/cmake/ChainsawConfig.cmake DESTINATION cmake/)

install(TARGETS ${PROJECT_NAME}
#PUBLIC_HEADER DESTINATION include
LIBRARY DESTINATION lib
)

