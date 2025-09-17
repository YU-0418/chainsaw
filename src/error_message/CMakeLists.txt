add_library(error_message_obj OBJECT
    print_err.cpp
)

target_include_directories(error_message_obj PUBLIC
    ${PROJECT_SOURCE_DIR}/src/error_message/include
)
