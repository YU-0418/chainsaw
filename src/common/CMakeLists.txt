add_library(common_obj OBJECT
    chartool.cpp
    command.cpp
    option.cpp
    print.cpp
    read_config_message.cpp
    readwritefile.cpp
    stringtool.cpp
)

target_include_directories(common_obj PUBLIC
    ${PROJECT_SOURCE_DIR}/src/common/include
)
