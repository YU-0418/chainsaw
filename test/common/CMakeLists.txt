add_executable(common-test chartool.cpp)
target_link_libraries(common-test
    PRIVATE
        chainsaw
)