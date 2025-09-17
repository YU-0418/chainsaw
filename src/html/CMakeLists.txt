add_library(html_obj OBJECT
    table.cpp
)

target_include_directories(html_obj PUBLIC
    ${PROJECT_SOURCE_DIR}/src/html/include
)
