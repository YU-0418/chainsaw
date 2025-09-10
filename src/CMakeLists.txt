include_directories(.)

add_library(chainsaw STATIC)
add_subdirectory(common)
add_subdirectory(error_message)
add_subdirectory(html)
add_subdirectory(markdown)
add_subdirectory(argv)
