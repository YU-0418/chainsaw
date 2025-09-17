add_library(markdown_obj OBJECT
    table.cpp
)

target_include_directories(markdown_obj PUBLIC
    ${PROJECT_SOURCE_DIR}/src/markdown/include
)
