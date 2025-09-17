#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    find_package(Chainsaw REQUIRED)
#    include_directories(${CHAINSAW_INCLUDE_DIRS})
#    target_link_libraries(${PROJECT_NAME} ${CHAINSAW_LIBRARY_DIRS})
#
#    This file will define the following variables:
#      - CHAINSAW_LIBRARY_DIRS             : The list of all imported targets for OpenCV modules.
#      - CHAINSAW_INCLUDE_DIRS             : The OpenCV include directories.

unset(INCLUDE_DIR CACHE)

find_path(INCLUDE_DIR
NAMES chainsaw.h
HINTS ${Chainsaw_DIR}/../include/chainsaw
)

unset(CHAINSAW_INCLUDE_DIRS CACHE)

list(APPEND CHAINSAW_INCLUDE_DIRS ${INCLUDE_DIR}/..)

message(STATUS "!!CHAINSAW_INCLUDE_DIRS is ${CHAINSAW_INCLUDE_DIRS}")

find_library(CHAINSAW_LIBRARY_DIRS
    NAMES chainsaw
    HINTS ${Chainsaw_DIR}/../lib
)
message(STATUS "!!CHAINSAW_LIBRARY_DIRS is ${CHAINSAW_LIBRARY_DIRS}")

message(STATUS "copy me!\
\nfind_package(Chainsaw REQUIRED)\
\ninclude_directories(\${CHAINSAW_INCLUDE_DIRS})\
\ntarget_link_libraries(\${PROJECT_NAME} \${CHAINSAW_LIBRARY_DIRS})")

