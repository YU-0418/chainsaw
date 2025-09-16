target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_sources(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/print_err.cpp)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
    DESTINATION error_message
)
