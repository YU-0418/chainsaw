set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 可执行测试
add_executable(common-test common.cpp)
target_link_libraries(common-test PRIVATE chainsaw)

install(TARGETS common-test
        RUNTIME DESTINATION ${INSTALL_BIN_DIR})