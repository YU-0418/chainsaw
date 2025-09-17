include_directories(.)

# 汇总所有对象库成一个大库
add_library(chainsaw STATIC
    $<TARGET_OBJECTS:common_obj>
    $<TARGET_OBJECTS:argv_obj>
    $<TARGET_OBJECTS:error_message_obj>
    $<TARGET_OBJECTS:html_obj>
    $<TARGET_OBJECTS:markdown_obj>
    # 其他模块的对象库...
)

# 添加所有公共头文件路径
target_include_directories(chainsaw PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/common/include
    ${PROJECT_SOURCE_DIR}/src/argv/include
    ${PROJECT_SOURCE_DIR}/src/error_message/include
    ${PROJECT_SOURCE_DIR}/src/html/include
    ${PROJECT_SOURCE_DIR}/src/markdown/include
)


# 安装大库
install(TARGETS chainsaw
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

add_subdirectory(common)
add_subdirectory(error_message)
add_subdirectory(html)
add_subdirectory(markdown)
add_subdirectory(argv)

# 模块列表
set(MODULES common argv error_message html markdown)

# 循环安装各模块头文件
foreach(module ${MODULES})
    install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/${module}/include
            DESTINATION include/${module}
            FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
endforeach()
