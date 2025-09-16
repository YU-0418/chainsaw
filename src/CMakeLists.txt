include_directories(.)

add_library(chainsaw STATIC)

target_include_directories(chainsaw
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(common)
add_subdirectory(error_message)
add_subdirectory(html)
add_subdirectory(markdown)
add_subdirectory(argv)
