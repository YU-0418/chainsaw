add_library(argv_obj OBJECT
    argv_tool.cpp
)

target_include_directories(argv_obj PUBLIC
    ${PROJECT_SOURCE_DIR}/src/argv/include
)
