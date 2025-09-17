cmake_minimum_required(VERSION 3.10.0)

project(chainsaw VERSION 1.0.0 LANGUAGES C CXX)

# 默认安装路径
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "Install path" FORCE)
endif()

# 统一 include/lib/bin 目录
set(INSTALL_INCLUDE_DIR include)
set(INSTALL_LIB_DIR lib)
set(INSTALL_BIN_DIR bin)

# 根目录统一安装函数（可选）
function(install_target_and_headers target module)
    # 安装目标库/可执行
    install(TARGETS ${target}
            ARCHIVE DESTINATION ${INSTALL_LIB_DIR}   # 静态库
            LIBRARY DESTINATION ${INSTALL_LIB_DIR}   # 动态库
            RUNTIME DESTINATION ${INSTALL_BIN_DIR})  # 可执行文件

    # 安装头文件
    install(DIRECTORY ${PROJECT_SOURCE_DIR}/src/${module}/include
            DESTINATION ${INSTALL_INCLUDE_DIR}/${module}
            FILES_MATCHING 
            PATTERN "*.h"
            PATTERN "*.hpp")
endfunction()

add_subdirectory(src)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test")
    enable_testing()
    add_subdirectory(test)
ENDIF()
