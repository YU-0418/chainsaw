# 可执行测试
add_executable(common-test chartool.cpp)
target_link_libraries(common-test PRIVATE chainsaw)

install(TARGETS common-test
        RUNTIME DESTINATION ${INSTALL_BIN_DIR})